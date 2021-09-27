## License
"xvcServer.c", is a derivative of "xvcd.c" (https://github.com/tmbinc/xvcd) 
by tmbinc, used under CC0 1.0 Universal (http://creativecommons.org/publicdomain/zero/1.0/). 
"xvcServer.c" is licensed under CC0 1.0 Universal (http://creativecommons.org/publicdomain/zero/1.0/) 
by Avnet and is used by Xilinx for XAPP1251.

## Overview
There are two modes to compile xvcServer.c: ioctl and mmap.  The difference between the two modes is in the method used to communicate between the xvcServer program and the IP in the FPGA fabric.

The default mode is ioctl which uses the ioctl() system call to utilize the xilinx_xvc_driver Linux kernel driver to access IP memory.  See `src/driver` for this driver's source code and steps to compile.

The mmap mode uses the mmap() system call to map IP memory into Linux user space through the built-in Linux generic_uio driver.

Other than this difference in IP memory access, the two modes share a common XVC server implementation.

## How to Compile
Running the default
`make`
or
`make ioctl`
will compile xvcServer.c in ioctl mode.  This uses the USE_IOCTL compilation flag to compile the relevant ioctl xvcServer.c source code.  The program will be named xvcServer_ioctl.

Running
`make mmap`
will compile xvcServer.c in mmap mode.  The program will be named xvcServer_mmap.

Running
`make test`
will compile a simple verify_xilinx_xvc_driver.c test program to ensure the Linux driver is working properly in the ioctl use case.

Running
`make clean`
will remove any of these programs compiled by the Makefile.

## Note
Make sure that the xvc server process termination is configured without using the 
`SIGKILL` 
signal so as not to leave the semaphore blocked. You can use other termination signals such as 
`SIGTERM` 
, 
`SIGQUIT` 
etc. 

