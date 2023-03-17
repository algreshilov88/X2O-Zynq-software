#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

// #define DRP_SIZE 8192
// #define DRP_BASE 0x50000000

int main (int argc, char* argv[])
{
	uint32_t *sys_vptr;
	int sys_fd;

	uint32_t DRP_BASE = strtol (argv[1], NULL, 0);
	uint32_t DRP_SIZE = strtol (argv[2], NULL, 0); 

	printf ("c2c test. Base: 0x%08x Lng: 0x%x\n", DRP_BASE, DRP_SIZE);

	sys_fd = ::open("/dev/mem", O_RDWR | O_SYNC);

	if (sys_fd != -1)
		sys_vptr = (uint32_t *)mmap(NULL, DRP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, sys_fd, DRP_BASE);
	else
	{
		sys_vptr = NULL;
		printf ("cannot map memory\n");
		return (0);
	}

	printf ("writing\n");
	fflush (stdout);

	for (uint32_t i = 0; i < DRP_SIZE/4; i++)
	{
		try 
		{
			sys_vptr[i] = i;
		}
		catch (int e)
		{
			printf ("exception %d\n", e);
		}
	}

	printf ("reading\n");
	fflush (stdout);

	for (uint32_t i = 0; i < DRP_SIZE/4; i++)
	{
		uint32_t rb = sys_vptr[i];
		if (i != rb) printf ("i: %03x w: %08x r: %08x\n");

	}

}
