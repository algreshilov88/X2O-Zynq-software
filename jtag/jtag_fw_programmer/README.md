‘jtag_fw_programmer.cc’ - Zynq compatible jtag firmware programmer tool to load connected bitstream using JTAG device driver on Zynq board

To compile jtag_fw_programmer on Zynq ‘cmake .’ then 'make'
Copy compiled binary to Zynq board along with bitstream file for uploading to FPGA
Make sure that xilinx_xvc_driver.ko is loaded
Make sure xvcServer is not running
To run ‘jtag_fw_programmer /dev/device bitfile’
    (for example ‘client_zynq_ioctl /dev/xilinx_xvc_driver_0 emtf_control_bm.bit’)

