## Overview
"jtag_fw_programmer.cc" - Zynq compatible jtag firmware programmer tool to load connected bitstream using JTAG device driver on Zynq board

## Compilation
To compile jtag_fw_programmer on Zynq run ‘cmake .’ then 'make'

Make sure that "xilinx_xvc_driver.ko" is loaded

## Executing
Run ‘jtag_fw_programmer /dev/device bitfile’
    (for example ‘client_zynq_ioctl /dev/xilinx_xvc_driver_0 emtf_control_bm.bit’)

