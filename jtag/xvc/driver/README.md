# Overview
This is the `xilinx_xvc_driver` Linux kernel driver source code.  This driver remaps the memory of one or more jtag IPs specified in the device tree into the kernel driver's memory.  Access to these jtag nodes memory is exposed through the driver's ioctl system call implementation.

The driver handles two jtag IPs in a single design, so in this case the information about these jtag configurations supplied in `xvc_user_config.h`.

The kernel driver implements the ioctl() system call to expose debug_bridge memory access to user space.  The implemented ioctl commands are:
  * XDMA_IOCXVC - sends parameters of the shift command to the driver
  * XDMA_RDXVC_PROPS - retrieves properties of the debug_bridge targeted by the character file

See `src/user` for an XVC server implementation with examples of how to interact with this driver.

## Steps Before Compiling
  * Make sure all debug entries in the PL design's device tree have their "compatible" field matching the default value of "xlnx,xvc", or the value from `xvc_user_config.h` if the user is overriding this "compatible" field value.
  * In the Xilinx PetaLinux flow, the device tree user source file is typically located in `project-spec/meta-user/recipes-bsp/device-tree/files/system-user.dtsi` in case to provide changes in device tree nodes.

## How to Compile
Follow info on p.118 in petalinux compilation flow:
https://www.xilinx.com/support/documentation/sw_manuals/xilinx2020_2/ug1144-petalinux-tools-reference-guide.pdf
