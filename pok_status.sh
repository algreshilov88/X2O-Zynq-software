if [ $DEVREG ]
then
	echo 'POK status TOP'
	i2cset -y $I2C_FPGA_TOP 0x71 1
	i2cget -y $I2C_FPGA_TOP 0x45 0x58
	echo 'POK status BOT'
	i2cset -y $I2C_FPGA_BOT 0x71 1
	i2cget -y $I2C_FPGA_BOT 0x45 0x58
else
        echo 'source revision setup script'
fi

