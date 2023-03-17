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
	uint64_t exp[2] = {0,0};
	uint64_t qsfp_mod = 0;

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
			if (toml_rtoi(raw, &exp[0])) {printf ("exp0 convertion failure\n");};
		}


		if (0 != (arr = toml_array_in(i2c_chip_addr, "exp_b"))) 
		{
			printf ("exp1 found: %d\n", toml_array_nelem(arr));
			fflush (stdout);
			if (0 == (raw = toml_raw_at(arr, 0))) {printf ("exp1 raw failure\n");};
			if (toml_rtoi(raw, &exp[1])) {printf ("exp1 convertion failure\n");};
		}

		if (0 != (arr = toml_array_in(i2c_chip_addr, "qsfp_mod"))) 
		{
			printf ("qsfp_mod found: %d\n", toml_array_nelem(arr));
			fflush (stdout);
			if (0 == (raw = toml_raw_at(arr, 0))) {printf ("qsfp_mod raw failure\n");};
			if (toml_rtoi(raw, &qsfp_mod)) {printf ("qsfp_mod convertion failure\n");};
		}

		printf ("exp0: 0x%x exp1: 0x%x qsfp_mod: 0x%x\n", exp[0], exp[1], qsfp_mod);


		// TOML decoder is not working at this time, hardcode addresses for now
		exp[0] = 0x44; // expansion register on top layer
		exp[1] = 0x41; // expansion register on bottom layer
		qsfp_mod = 0x50; // QSFP module address
		// i2c_fd_bus seems to be correct

		toml_free(config);

		// this structure defines position of the qsfp select bit within I2C expansion registers
		typedef struct qsfp_select_s
		{
			uint8_t chip_ind; // 0 or 1
			uint8_t reg_addr; // 
		} qsfp_select_t;

		// map of the qsfp selection bits. 
		// refdes numbers in comments match schematics
		qsfp_select_t qsfp_select [30] = 
		{
			{1, 0x24}, // cage 0 refdes 0
			{1, 0x3E}, // cage 1 refdes 1
			{1, 0x3D}, // cage 2 refdes 2
			{1, 0x3B}, // cage 3 refdes 3
			{1, 0x39}, // cage 4 refdes 4
			{1, 0x36}, // cage 5 refdes 5
			{0, 0x29}, // cage 6 refdes 6
			{0, 0x2B}, // cage 7 refdes 7
			{0, 0x30}, // cage 8 refdes 8
			{0, 0x32}, // cage 9 refdes 9
			{0, 0x38}, // cage 10 refdes 10
			{0, 0x3A}, // cage 11 refdes 11
			{0, 0x3C}, // cage 12 refdes 12
			{0, 0x3D}, // cage 13 refdes 13
			{0, 0x3F}, // cage 14 refdes 28
			{1, 0x3F}, // cage 15 refdes 14
			{1, 0x26}, // cage 16 refdes 15
			{1, 0x27}, // cage 17 refdes 16
			{1, 0x3A}, // cage 18 refdes 17
			{1, 0x38}, // cage 19 refdes 18
			{1, 0x35}, // cage 20 refdes 19
			{0, 0x2E}, // cage 21 refdes 20
			{0, 0x2F}, // cage 22 refdes 21
			{0, 0x31}, // cage 23 refdes 22
			{0, 0x33}, // cage 24 refdes 23
			{0, 0x39}, // cage 25 refdes 24
			{0, 0x3B}, // cage 26 refdes 25
			{0, 0x27}, // cage 27 refdes 26
			{0, 0x25}, // cage 28 refdes 27
			{0, 0x24}  // cage 29 refdes 29
		};

		for (int i = 0; i < 30; i++)
		{
			qsfp_select_t qs = qsfp_select[i];

			// reset all outputs to 1
			for (int j = 0; j < 2; j++)
			{
				i2c_write (i2c_fd_bus, exp[j], 0x44, 0xff);
				i2c_write (i2c_fd_bus, exp[j], 0x4c, 0xff);
				i2c_write (i2c_fd_bus, exp[j], 0x54, 0xff);
				i2c_write (i2c_fd_bus, exp[j], 0x5c, 0xff);
			}

			// write selection bit
			i2c_write (i2c_fd_bus, exp[qs.chip_ind], qs.reg_addr, 0);

			// read temperature
			union temperature
			{
				int16_t t16;
				uint8_t  t8[2];
			} t;
			t.t16 = 0;
			int res;
			res = i2c_read (i2c_fd_bus, qsfp_mod, 0x16, &t.t8[1]);
			// if the first read fails, the device is not there, skip the rest
			if (res != -1) 			
			{
				i2c_read (i2c_fd_bus, qsfp_mod, 0x17, &t.t8[0]);

				// convert to C according to QSFP-MSA.pdf page 53 line 14
				float tc = ((float)t.t16)/256.;

				// read voltage
				union voltage
				{
					uint16_t v16;
					uint8_t  v8[2];
				} v;
				v.v16 = 0;
				i2c_read (i2c_fd_bus, qsfp_mod, 0x1a, &v.v8[1]);
				i2c_read (i2c_fd_bus, qsfp_mod, 0x1b, &v.v8[0]);

				// convert to V according to QSFP-MSA.pdf page 53 line 19
				float vv = ((float)v.v16)/10000.;

				if (vv < 3.2)
				{
					printf ("device %d voltage = %1.2f\n", i, vv);

//					i2c_chip_deinitialize();
//					exit (0);
				}

//				if (0)
				{
				// read interrupt flags
				uint8_t los, laser_fault, cdr_lol;
				i2c_read (i2c_fd_bus, qsfp_mod, 0x03, &los);
				i2c_read (i2c_fd_bus, qsfp_mod, 0x04, &laser_fault);
				i2c_read (i2c_fd_bus, qsfp_mod, 0x05, &cdr_lol);

				uint8_t alarm[15];
				i2c_read (i2c_fd_bus, qsfp_mod,  6, &alarm[ 6]);
				i2c_read (i2c_fd_bus, qsfp_mod,  7, &alarm[ 7]);
				i2c_read (i2c_fd_bus, qsfp_mod,  9, &alarm[ 9]);
				i2c_read (i2c_fd_bus, qsfp_mod, 10, &alarm[10]);
				i2c_read (i2c_fd_bus, qsfp_mod, 11, &alarm[11]);
				i2c_read (i2c_fd_bus, qsfp_mod, 12, &alarm[12]);
				i2c_read (i2c_fd_bus, qsfp_mod, 13, &alarm[13]);
				i2c_read (i2c_fd_bus, qsfp_mod, 14, &alarm[14]);

				uint8_t reg_193, options;
				i2c_read (i2c_fd_bus, qsfp_mod, 221, &options);
				i2c_read (i2c_fd_bus, qsfp_mod, 193, &reg_193);

				// select page 3
				uint8_t reg_238=0, reg_239=0, reg_225=0, ampl=0;
/*
				i2c_write (i2c_fd_bus, qsfp_mod, 127, 3);
				// read RX amplitudes
				i2c_read (i2c_fd_bus, qsfp_mod, 225, &reg_225);
				switch (reg_225 & 0xf)
				{
					case (1)  : ampl = 0x00; break;
					case (3)  : ampl = 0x11; break;
					case (7)  : ampl = 0x22; break;
					case (0xf): ampl = 0x33; break;
				}
				// reset amplitude to minimum
				ampl = 0x00;
				i2c_write (i2c_fd_bus, qsfp_mod, 238, ampl); // program max amplitudes
				i2c_write (i2c_fd_bus, qsfp_mod, 239, ampl);
				i2c_read (i2c_fd_bus, qsfp_mod, 238, &reg_238);
				i2c_read (i2c_fd_bus, qsfp_mod, 239, &reg_239);

				// back to page 0
				i2c_write (i2c_fd_bus, qsfp_mod, 127, 0);
*/
				printf ("i: %2d T16: %04x TC: %2.1f V16: %04x VV: %1.2f LOS: %02x Laser: %02x LOL: %02x AL: %02x %02x %02x %02x %02x %02x %02x %02x OPT: %02x OPT: %02x AMPSUP: %02x AMP: %02x%02x\n", 
						i, t.t16, tc, v.v16, vv, los, laser_fault, cdr_lol, alarm[6], alarm[7], alarm[9], alarm[10], alarm[11], alarm[12], alarm[13], alarm[14], reg_193, options, 
						reg_225, reg_238, reg_239);
				fflush (stdout);
				}
			}
//			else
//			{
//				printf ("cannot read device %d\n", i);
//				i2c_chip_deinitialize();
//				exit (0);
//			}
		}

		i2c_chip_deinitialize();
	}
	else
		i2c_chip_deinitialize(); // just unlock semaphore if run without parameters


	return EXIT_SUCCESS;
}
#ifdef NODEF

/////////////////////////////////////////////////////////////////////////////	

	// register arrays for each synth
	si5332_gm1_revd_register_t* regs[] = {si5332_gm1_revd_registers};
	int i, j;
	int dwords = sizeof(si5332_gm1_revd_registers)/sizeof(si5332_gm1_revd_register_t); // size of register dump
	int page_now = -1, page_old = -2;
	u8 regval;


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
	

#endif


