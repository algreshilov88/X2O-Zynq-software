if [ $DEVREG ]
then
#echo 'POK status BOT'
#i2cset -y $BOT_JTAG 0x71 1
#i2cget -y $BOT_JTAG 0x45 0x58
echo 'POK status TOP'
i2cset -y $TOP_JTAG 0x71 1
i2cget -y $TOP_JTAG 0x45 0x58
else
        echo 'source revision setup script'
fi

