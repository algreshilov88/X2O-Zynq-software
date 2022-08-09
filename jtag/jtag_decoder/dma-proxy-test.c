/**
 * Copyright (C) 2021 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

/* DMA Proxy Test Application
 *
 * This application is intended to be used with the DMA Proxy device driver. It provides
 * an example application showing how to use the device driver to do user space DMA
 * operations.
 *
 * The driver allocates coherent memory which is non-cached in a s/w coherent system
 * or cached in a h/w coherent system.
 *
 * Transmit and receive buffers in that memory are mapped to user space such that the
 * application can send and receive data using DMA channels (transmit and receive).
 *
 * It has been tested with AXI DMA and AXI MCDMA systems with transmit looped back to
 * receive. Note that the receive channel of the AXI DMA throttles the transmit with
 * a loopback while this is not the case with AXI MCDMA.
 *
 * Build information: The pthread library is required for linking. Compiler optimization
 * makes a very big difference in performance with -O3 being good performance and
 * -O0 being very low performance.
 *
 * The user should tune the number of channels and channel names to match the device
 * tree.
 *
 * More complete documentation is contained in the device driver (dma-proxy.c).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <signal.h>
#include <sched.h>
#include <time.h>
#include <errno.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#include "dma-proxy.h"

/* The user must tune the application number of channels to match the proxy driver device tree
 * and the names of each channel must match the dma-names in the device tree for the proxy
 * driver node. The number of channels can be less than the number of names as the other
 * channels will just not be used in testing.
 */
#define TX_CHANNEL_COUNT 1
#define RX_CHANNEL_COUNT 1

const char *tx_channel_names[] = { "dma_proxy_tx", /* add unique channel names here */ };
const char *rx_channel_names[] = { "dma_proxy_rx", /* add unique channel names here */ };

/* Internal data which should work without tuning */

struct channel {
	struct channel_buffer *buf_ptr;
	int fd;
	pthread_t tid;
};

static int test_size;
int num_transfers;
long rest_size;
char* binfile;
struct stat st;
off_t binfile_size;

struct channel tx_channels[TX_CHANNEL_COUNT], rx_channels[RX_CHANNEL_COUNT];

/*******************************************************************************************************************/
/* Get the clock time in usecs to allow performance testing
 */
static uint64_t get_posix_clock_time_usec ()
{
    struct timespec ts;

    if (clock_gettime (CLOCK_MONOTONIC, &ts) == 0)
        return (uint64_t) (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
    else
        return 0;
}

/*******************************************************************************************************************/
/*
 * The following function is the transmit thread to allow the transmit and the receive channels to be
 * operating simultaneously. Some of the ioctl calls are blocking so that multiple threads are required.
 */
void tx_thread(struct channel *channel_ptr)
{
	int i, buffer_id = 0;

	buffer_id = 0;

  int fd = open(binfile, O_RDONLY);
  if (fd < 0) {
    perror("ERROR opening binfile");
  }

  if (stat(binfile, &st) < 0)
  {
    perror("ERROR in stat()");
  }
  else
  {
    binfile_size = st.st_size;
    printf("binfile size: %ld bytes\n", (long) binfile_size);
  }

	if (!binfile_size%BUFFER_SIZE)
	{
		num_transfers = binfile_size%BUFFER_SIZE;
		unsigned int buf[num_transfers][BUFFER_SIZE / sizeof(unsigned int)];
		rest_size = 0;

		for (i = 0; i < num_transfers; i++) {
			/* Set up the length for the DMA transfer and initialize the transmit
			 * buffer to a known pattern.
			 */
			channel_ptr->buf_ptr[buffer_id].length = BUFFER_SIZE;

			/* Perform the DMA transfer and check the status after it completes
			 * as the call blocks til the transfer is done.
			 */
			ioctl(channel_ptr->fd, FINISH_XFER, &buffer_id);
			if (channel_ptr->buf_ptr[buffer_id].status != PROXY_NO_ERROR)
				printf("Proxy tx transfer error\n");

			unsigned int *buffer = (unsigned int *)&channel_ptr->buf_ptr[buffer_id].buffer;

			read(fd, buf[i], BUFFER_SIZE);
			buffer = buf[i];

			/* Restart the completed channel buffer to start another transfer and keep
			 * track of the number of transfers in progress
			 */
			ioctl(channel_ptr->fd, START_XFER, &buffer_id);
		}
	} else
	{
		num_transfers = binfile_size%BUFFER_SIZE + 1;
		unsigned int buf[num_transfers][BUFFER_SIZE];
		rest_size = binfile_size - num_transfers * BUFFER_SIZE;

		for (i = 0; i < num_transfers; i++) {
			/* Set up the length for the DMA transfer and initialize the transmit
			 * buffer to a known pattern.
			 */
			if (i < num_transfers-1)
				channel_ptr->buf_ptr[buffer_id].length = BUFFER_SIZE;

			if (i == num_transfers-1)
				channel_ptr->buf_ptr[buffer_id].length = rest_size;

			/* Perform the DMA transfer and check the status after it completes
			 * as the call blocks til the transfer is done.
			 */
			ioctl(channel_ptr->fd, FINISH_XFER, &buffer_id);
			if (channel_ptr->buf_ptr[buffer_id].status != PROXY_NO_ERROR)
				printf("Proxy tx transfer error\n");

			unsigned int *buffer = (unsigned int *)&channel_ptr->buf_ptr[buffer_id].buffer;

			read(fd, buf[i], BUFFER_SIZE);
			buffer = buf[i];

			/* Restart the completed channel buffer to start another transfer and keep
			 * track of the number of transfers in progress
			 */
			ioctl(channel_ptr->fd, START_XFER, &buffer_id);
		}
	}
}

/*******************************************************************************************************************/
/*
 * Setup the transmit and receive threads so that the transmit thread is low priority to help prevent it from
 * overrunning the receive since most testing is done without any backpressure to the transmit channel.
 */
void setup_threads(int *num_transfers)
{
	int i;

	for (i = 0; i < TX_CHANNEL_COUNT; i++)
		pthread_create(&tx_channels[i].tid, NULL, tx_thread, (void *)&tx_channels[i]);
}

/*******************************************************************************************************************/
/*
 * The main program starts the transmit thread and then does the receive processing to do a number of DMA transfers.
 */
int main(int argc, char *argv[])
{
	int i;
	uint64_t start_time, end_time, time_diff;
	int mb_sec;
	int max_channel_count = MAX(TX_CHANNEL_COUNT, RX_CHANNEL_COUNT);

	printf("DMA proxy test\n");

	binfile = argv[1];

	if ((argc != 3) && (argc != 4)) {
		printf("Usage: dma-proxy-test <# of DMA transfers to perform> <# of bytes in each transfer in KB (< 1MB)> <optional verify, 0 or 1>\n");
		exit(EXIT_FAILURE);
	}

	/* Open the file descriptors for each tx channel and map the kernel driver memory into user space */

	for (i = 0; i < TX_CHANNEL_COUNT; i++) {
		char channel_name[64] = "/dev/";
		strcat(channel_name, tx_channel_names[i]);
		tx_channels[i].fd = open(channel_name, O_RDWR);
		if (tx_channels[i].fd < 1) {
			printf("Unable to open DMA proxy device file: %s\r", channel_name);
			exit(EXIT_FAILURE);
		}
		tx_channels[i].buf_ptr = (struct channel_buffer *)mmap(NULL, sizeof(struct channel_buffer) * TX_BUFFER_COUNT,
										PROT_READ | PROT_WRITE, MAP_SHARED, tx_channels[i].fd, 0);
		if (tx_channels[i].buf_ptr == MAP_FAILED) {
			printf("Failed to mmap tx channel\n");
			exit(EXIT_FAILURE);
		}
	}

	/* Grab the start time to calculate performance then start the threads & transfers on all channels */

	start_time = get_posix_clock_time_usec();
	setup_threads(&num_transfers);

	/* Do the minimum to know the transfers are done before getting the time for performance */

  for (i = 0; i < TX_CHANNEL_COUNT; i++)
		pthread_join(tx_channels[i].tid, NULL);

	/* Grab the end time and calculate the performance */

	end_time = get_posix_clock_time_usec();
	time_diff = end_time - start_time;
	mb_sec = ((1000000 / (double)time_diff) * ((num_transfers * max_channel_count * (double) BUFFER_SIZE) + max_channel_count * (double) test_size)) / 1000000;

	printf("Time: %d microseconds\n", (int) time_diff);
	printf("Transfer size: %d KB\n", (int)((num_transfers - 1) * (BUFFER_SIZE / 1024) * max_channel_count) + ((int) rest_size / 1024) * max_channel_count);
	printf("Throughput: %d MB / sec \n", mb_sec);

	/* Clean up all the channels before leaving */

	for (i = 0; i < TX_CHANNEL_COUNT; i++) {
		munmap(tx_channels[i].buf_ptr, sizeof(struct channel_buffer));
		close(tx_channels[i].fd);
	}

	printf("DMA proxy test complete\n");

	return 0;
}
