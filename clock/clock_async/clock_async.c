/*
 * Copyright (c) 2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include "i2c-chip.h"
#include "toml.h"

#ifdef F250
#include "Si5332-GM1-RevD-Registers.h" // 250M all channels, for GTH 16G IBERT
#endif

#ifdef F322
#include "si5332-322.x-all-Registers.h" // 322.265625M all channels, for 25G GTY IBERT
#endif

// Make the SDK console work in the debugger
#define printf(...) \
 fprintf(stdout, __VA_ARGS__); \
 fflush(stdout);

typedef long long int u64;
typedef unsigned int u32;

int main(int argc, char * argv[])
{
	toml_table_t* config;
	toml_table_t* i2c_chip_addr;
	toml_array_t* arr;
	toml_raw_t raw;

	int n;

	FILE* fp;
	char errbuf[1000];

	if (argc == 2) {
	/* Open the file. */
	if (0 == (fp = fopen(argv[1], "r"))) {
		//return handle_error();
		perror("fopen() failed for CONFIG.toml");
	}

	/* Run the files through the parser. */
	config = toml_parse_file(fp, errbuf, sizeof(errbuf));
	if (0 == config) {
		//return handle_error();
	}

	fclose(fp);

	/* Locate the [I2C_CHIPS] table. */
	if (0 == (i2c_chip_addr = toml_table_in(config, "I2C_CHIPS"))) {
		//return handle_error();
	}

	/* Extract 'i2c_chip' config array. */
	if (0 == (arr = toml_array_in(i2c_chip_addr, "i2c_chip"))) {
		//return handle_error();
	}

	long long int i2c_chip[toml_array_nelem(arr)];

	for (n=0; n<toml_array_nelem(arr); n++) {
		/* Extract 'i2c_chip[n]' config value. */
		if (0 == (raw = toml_raw_at(arr, n))) {
			//return handle_error();
		};
									
		/* Convert the raw value into an int. */
		if (toml_rtoi(raw, &i2c_chip[n])) {
			//return handle_error();
		};
	}		

	toml_free(config);

/////////////////////////////////////////////////////////////////////////////	

	// register arrays for each synth
	si5332_gm1_revd_register_t* regs[] = {si5332_gm1_revd_registers};
	int i, j;
	int dwords = sizeof(si5332_gm1_revd_registers)/sizeof(si5332_gm1_revd_register_t); // size of register dump
	int page_now = -1, page_old = -2;
	u8 regval;

	i2c_chip_initialize(argc, argv[1]);

	// set multiplexor on WIB
	// TBD, write I2C chain selector into 0xa00c0004, bits 3:0

	i2c_write(i2c_fd_bus, 0x71, 0, 0);
	i2c_write(i2c_fd_bus, 0x71, 0, 4);

	for (j = 0; j < sizeof(i2c_chip)/sizeof(int)-1; j++) // chip loop
	{
		// reset page, so it's selected for each chip at the start
		page_now = -1;
		page_old = -2;
		// dump registers
		for (i = 0; i < dwords; i ++)
		{
			si5332_gm1_revd_register_t rd = regs[j][i];

			// detect page switches
			page_old = page_now;
			page_now = (rd.address >> 8) & 0xff;
			if (page_now != page_old)
			{
				// page changed, switch
				i2c_write(i2c_fd_bus, i2c_chip[j], 1, page_now);
			}

			i2c_write(i2c_fd_bus, i2c_chip[j], rd.address & 0xff, rd.value);
			i2c_read(i2c_fd_bus, i2c_chip[j], rd.address & 0xff, &regval);

			if (i == 2) usleep (300000);
		}
		i2c_write(i2c_fd_bus, i2c_chip[j], 1, 0);
		printf ("si5332 configuration finished, a = 0x%x\n", i2c_chip[j]);
	}
	
	i2c_chip_deinitialize();
	} else {
		printf ("Invalid command!\n");
	}

	return EXIT_SUCCESS;
}
