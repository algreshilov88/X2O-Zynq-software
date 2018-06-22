#include <iostream>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <random>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h> 

jmp_buf reset;

void sigbus_handler(int signum)
{
	longjmp(reset, 1);
}

using namespace std;
  
#define mwrite(b,d) {*((uint64_t*)(sys_vptr + d)) = *b;}
#define mread(b,d)  {*b = *((uint64_t*)(sys_vptr + d));}
  
int main (int argc, char* argv[])
{ 

    if (setjmp(reset) != 0)
    {
        printf("BUS ERROR, ejecting\n");
        exit (0);
    }
    signal (SIGBUS, sigbus_handler);


    uint32_t DRP_BASE, DRP_SIZE;

	if (argc < 2)
	{
		printf ("arguments: top_bram0, 2, bot_bram0, 2, lb_gmt\n");
		exit (0);
	}

    string target = argv[1];
    if (target.compare("top_bram0") == 0) // test BRAM @0 in KU15P
    {
        DRP_BASE = 0x50000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("top_bram2") == 0) // test BRAM @0x2000000 in KU15P
    {
        DRP_BASE = 0x52000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("bot_bram0") == 0) // test BRAM @0 in KU15P
    {
        DRP_BASE = 0x58000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("bot_bram2") == 0) // test BRAM @0x2000000 in KU15P
    {
        DRP_BASE = 0x5a000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("lb") == 0) // loopback BRAM in ZYNQ
    {
        DRP_BASE = 0x43c30000;
        DRP_SIZE = 0x2000; // 8KB
    }
    if (target.compare("lb_gmt") == 0) // loopback BRAM in ZYNQ with GMT design
    {
        DRP_BASE = 0x44000000;
        DRP_SIZE = 0x2000; // 8KB
    }

    uint8_t *sys_vptr;
    int sys_fd;
    sys_fd = ::open("/dev/mem", O_RDWR | O_SYNC);
    if (sys_fd != -1)
        sys_vptr = (uint8_t *)mmap(NULL, DRP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, sys_fd, DRP_BASE);
    else sys_vptr = NULL;

    uint64_t* pw = (uint64_t*) malloc (DRP_SIZE);
    uint64_t* pr = (uint64_t*) malloc (DRP_SIZE);
    if (pr == NULL || pw == NULL)
    {
        printf ("cannot allocate memory\n");
        exit (1);
    }

	std::default_random_engine generator;
	std::uniform_int_distribution<uint64_t> distribution(0, 0xffffffffffffffffULL);

    uint64_t j = 0xff00000000000000ULL;
    while (true)
    {
        //  printf ("writing\n"); fflush (stdout);
        for (uint64_t i = 0; i < DRP_SIZE/8; i++)
        {
            //      printf ("i: %04llx\n", i); fflush (stdout);
//            pw[i] = (j << 10) + i;
            pw[i] = distribution(generator);
        }

        memset (pr, 0, DRP_SIZE);
        memcpy (sys_vptr, pw, DRP_SIZE);
        memcpy (pr, sys_vptr, DRP_SIZE);

        //  printf ("reading\n"); fflush (stdout);
        uint64_t rb;
        for (uint64_t i = 0; i < DRP_SIZE/8; i++)
        {
            if (pw[i] != pr[i])
            {
                printf ("w: %04llx r: %04llx\n", pw[i], pr[i]);
                fflush (stdout);
            }
        }
        j++;
    }
	return 0;
}

