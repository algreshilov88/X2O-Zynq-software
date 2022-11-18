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
	uint64_t exp0 = 0, exp1 = 0, qsfp_mod = 0;

	if (argc == 2) 
	{
		printf ("attempting to get semaphore\n");
		i2c_chip_initialize(argc, argv[1]);
		printf ("semaphore acquired\n");

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

//		long long int i2c_chip[toml_array_nelem(arr)];

		/* Locate the [I2C_CHIPS] table. */
		if (0 != (i2c_chip_addr = toml_table_in(config, "I2C_CHIPS"))) 
		{
			printf ("I2C chip found: %d\n", i2c_chip_addr);	
		}



		/* Extract 'i2c_chip' config array. */
		if (0 == (arr = toml_array_in(i2c_chip_addr, "i2c_chip"))) 
		{
			//return handle_error();
		}

		if (0 != (arr = toml_array_in(i2c_chip_addr, "exp_a"))) 
		{
			printf ("exp0 found: %d\n", toml_array_nelem(arr));
			fflush (stdout);
			if (0 == (raw = toml_raw_at(arr, 0))) {printf ("exp0 raw failure\n");};
			if (toml_rtoi(raw, &exp0)) {printf ("exp0 convertion failure\n");};
		}


		if (0 != (arr = toml_array_in(i2c_chip_addr, "exp_b"))) 
		{
			printf ("exp1 found: %d\n", toml_array_nelem(arr));
			fflush (stdout);
			if (0 == (raw = toml_raw_at(arr, 0))) {printf ("exp1 raw failure\n");};
			if (toml_rtoi(raw, &exp1)) {printf ("exp1 convertion failure\n");};
		}

		if (0 != (arr = toml_array_in(i2c_chip_addr, "qsfp_mod"))) 
		{
			printf ("qsfp_mod found: %d\n", toml_array_nelem(arr));
			fflush (stdout);
			if (0 == (raw = toml_raw_at(arr, 0))) {printf ("qsfp_mod raw failure\n");};
			if (toml_rtoi(raw, &qsfp_mod)) {printf ("qsfp_mod convertion failure\n");};
		}

		printf ("exp0: %d exp1: %d qsfp_mod: %d\n", exp0, exp1, qsfp_mod);


		// TOML decoder is not working at this time, hardcode addresses for now
		exp0 = 0x41; // expansion register on top layer
		exp1 = 0x44; // expansion register on bottom layer
		qsfp_mod = 0x50; // QSFP module address
		// i2c_fd_bus seems to be correct

		toml_free(config);

		// positions of POK bits in the 0x41 register
		int pok_bit[9] = 
		{
			0x25, // POK 0
			0x3c, // POK 1
			0x37, // POK 2
			0x34, // POK 3
			0x33, // POK 4
			0x32, // POK 5
			0x31, // POK 6
			0x30, // POK 7
			0x28 // Overvoltage = 0
		};

		printf ("entering eternity\n");
		fflush (stdout);
		char stick[] = "-\\|/";
		int stick_ind = 0;
		uint8_t pok;
		while (1) // run continuosly
		{
			for (int i = 0; i < 9; i++)
			{
				i2c_read (i2c_fd_bus, exp0, pok_bit[i], &pok);
				if (pok == 0) 
				{
					if (i < 8) {printf ("POK[%d] = %x\n", i, pok);}
					else {printf ("OVERVOLTAGE!\n");}
					fflush (stdout);
				}
			}
			usleep (2000);
			printf ("\r%c     ", stick[(++stick_ind) & 3]);
			fflush (stdout);
		}
		i2c_chip_deinitialize();
	}
	else
		i2c_chip_deinitialize(); // just unlock semaphore if run without parameters


	return EXIT_SUCCESS;
}

