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
#include <exception>

void termination_handler (int signum)
{
	exit(0);
}

using namespace std;
  
#define mwrite(b,d) {*((uint64_t*)(sys_vptr + d)) = *b;}
#define mread(b,d)  {*b = *((uint64_t*)(sys_vptr + d));}
  
int main (int argc, char* argv[])
{ 
    struct sigaction new_action, old_action;

    /* Set up the structure to specify the new action. */
    new_action.sa_handler = termination_handler;
    sigemptyset (&new_action.sa_mask);
    new_action.sa_flags = 0;

//    new_action.sa_sigaction = termination_handler;
//    new_action.sa_flags = SA_SIGINFO;


//    sigaction (SIGBUS, NULL, &old_action);
//    if (old_action.sa_handler != SIG_IGN)
    int sigres = sigaction (SIGBUS, &new_action, NULL);
    if (sigres != 0)
    {
        printf ("sigaction failed\n");
	fflush (stdout);
	exit (0);
    }

    uint64_t DRP_BASE, DRP_SIZE;

	if (argc < 2)
	{
		printf ("arguments: top_bram0, 2, bot_bram0, 2, lb_gmt\n");
		printf ("size_t: %d off_t: %d\n", sizeof(size_t), sizeof(off_t));
		exit (0);
	}

    string target = argv[1];
    if (target.compare("top_bram_gem") == 0) // test BRAM @0 in KU15P, GEM design
    {
        DRP_BASE = 0x454020000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("top_bram0") == 0) // test BRAM @0 in KU15P
    {
        DRP_BASE = 0x450000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("top_bram2") == 0) // test BRAM @0x2000000 in KU15P
    {
        DRP_BASE = 0x452000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("bot_bram0") == 0) // test BRAM @0 in KU15P
    {
        DRP_BASE = 0x458000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("bot_bram2") == 0) // test BRAM @0x2000000 in KU15P
    {
        DRP_BASE = 0x45a000000;
        DRP_SIZE = 0x10000; // 64KB
    }
    if (target.compare("lb") == 0) // loopback BRAM in ZYNQ
    {
//        DRP_BASE = 0x443c20000;
        DRP_BASE = 0x470000000;
        DRP_SIZE = 0x2000; // 8KB
    }
    if (target.compare("lb_gmt") == 0) // loopback BRAM in ZYNQ with GMT design
    {
        DRP_BASE = 0x444000000;
        DRP_SIZE = 0x2000; // 8KB
    }

    uint8_t *sys_vptr;
    int sys_fd;
    sys_fd = ::open("/dev/mem", O_RDWR | O_SYNC);
    if (sys_fd != -1)
        sys_vptr = (uint8_t *)mmap(NULL, DRP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, sys_fd, DRP_BASE);
    else sys_vptr = NULL;

    if (sys_vptr == MAP_FAILED)
    {
	printf ("mmap failed\n");
	exit (1);
    }

//    exit(1);

    uint64_t* pw = (uint64_t*) malloc (DRP_SIZE);
    uint64_t* pr = (uint64_t*) malloc (DRP_SIZE);
    if (pr == NULL || pw == NULL)
    {
        printf ("cannot allocate memory\n");
        exit (1);
    }

	std::default_random_engine generator;
    	//std::random_device rd;
	//std::mt19937_64 generator(rd());
	std::uniform_int_distribution<uint64_t> distribution(0, 0xffffffffffffffffULL);

    uint64_t j = 0xff00000000000000ULL;
    while (true)
    {
        //  printf ("writing\n"); fflush (stdout);
        for (uint64_t i = 0; i < DRP_SIZE/8; i++)
        {
            //      printf ("i: %04llx\n", i); fflush (stdout);
//            pw[i] = (j << 10) + i;
            printf("checkSTART\n");
            pw[i] = distribution(generator);
	    printf("checkEND\n");
        }

        memset (pr, 0, DRP_SIZE);
        memcpy (sys_vptr, pw, DRP_SIZE);
        memcpy (pr, sys_vptr, DRP_SIZE);

	printf("check6\n");
        //  printf ("reading\n"); fflush (stdout);
        uint64_t rb;
        for (uint64_t i = 0; i < DRP_SIZE/8; i++)
        {
		printf("check7\n");
            if (pw[i] != pr[i])
            {
		    printf("check8\n");
                printf ("w: %04llx r: %04llx\n", pw[i], pr[i]);
                fflush (stdout);
            }
        }
        j++;
    }
    printf("check9\n");
	return 0;
}

