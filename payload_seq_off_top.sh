if [ $DEVREG ]
then
b=$TOP_JTAG
i2cset -y $b 0x71 0 # disconnect all
i2cset -y $b 0x71 1 # enable expander reg branch

# disable POK change reaction
./$DEVREG pok_change_enable_top 0

#payload sequence off
i2cset -y $b 0x45 0x24 0x00

# reset interrupt, by reading interrupt status. The status is in MSB
i2cget -y $b 0x45 0x06
else
        echo 'source revision setup script'
fi

