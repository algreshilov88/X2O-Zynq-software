# set up for Power module rev 3
export I2C_FPGA_TOP=1
export I2C_FPGA_BOT=2
export DEVREG=devreg_us.sh
export I2C_XGBUFFER=4 # I2C interface connected to XAUI conditioner
export XVC_DRIVER=jtag/xvc/driver_us/xilinx_xvc_driver.ko
export XVC_DEV_TOP=/dev/xilinx_xvc_driver_0
export XVC_DEV_BOT=/dev/xilinx_xvc_driver_1

