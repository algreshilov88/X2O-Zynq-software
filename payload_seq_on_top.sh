if [ $DEVREG ]
then
b=$TOP_JTAG
i2cset -y $b 0x71 0 # disconnect all
i2cset -y $b 0x71 1 # enable expander reg branch

# reset interrupt, by reading interrupt status. The status is in MSB
i2cget -y $b 0x45 0x06

# disable POK change reaction
./$DEVREG pok_change_enable_bot 0

# payload sequence on
i2cset -y $b 0x45 0x24 0x01

# let power turn on
sleep 0.2

# check POK bits from payload
i2cget -y $b 0x45 0x58

# enable register and interrupt output P31
i2cset -y $b 0x45 0x04 0x81

#enable POK change reaction
./$DEVREG pok_change_enable_top 1
else
	echo 'source revision setup script'
fi
