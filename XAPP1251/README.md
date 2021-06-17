## License
"xvcServer_uio.c", is a derivative of "xvcd.c" (https://github.com/tmbinc/xvcd) 
by tmbinc, used under CC0 1.0 Universal (http://creativecommons.org/publicdomain/zero/1.0/). 
"xvcServer.c" is licensed under CC0 1.0 Universal (http://creativecommons.org/publicdomain/zero/1.0/) 
by Avnet and is used by Xilinx for XAPP1251.

## Overview
This tool uses the mmap() system call to map IP memory into Linux user space through the built-in Linux generic_uio driver.

# Before compilation
Make sure generic_uio driver set in Kernel during Petalinux compilation flow
Make sure debug_bridge node is compatible to generic-uio. This can be done from `project-spec/meta-user/recipes-bsp/device-tree/files/system-user.dtsi` in Petalinux flow. 

## How to Compile
Running from XAPP1251 folder
`cmake .` then `make`
