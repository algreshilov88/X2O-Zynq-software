b=1
i2cset -y $b 0x71 0 # disconnect all
i2cset -y $b 0x71 1 # enable expander reg branch
i2cset -y $b 0x45 0x09 0x55 # ports  7: 4 FF selection outputs
i2cset -y $b 0x45 0x0a 0x55 # ports 11: 8 FF selection outputs
i2cset -y $b 0x45 0x0b 0x55 # ports 15:12 FF selection outputs
i2cset -y $b 0x45 0x0c 0x55 # ports 19:16 FF selection outputs
i2cset -y $b 0x45 0x0d 0x55 # ports 23:20 FF selection outputs
i2cset -y $b 0x45 0x0e 0xaa # ports 27:24 POK inputs without pullups
i2cset -y $b 0x45 0x0f 0x6a # ports 30:28 POK inputs, P31 is output for interrupt
i2cset -y $b 0x45 0x40 0xff # deselect FFs
i2cset -y $b 0x45 0x48 0xff # deselect FFs
i2cset -y $b 0x45 0x50 0xff # deselect FFs
i2cset -y $b 0x45 0x24 0x00 # disable power sequencer
i2cset -y $b 0x45 0x5f 0x00 # default state for P31 when interrupt is disabled
i2cset -y $b 0x45 0x06 0x3f # interrupt mask covers all POK inputs
i2cset -y $b 0x45 0x04 0x81 # enable register and interrupt output P31
# set POK change signal polarity
./devreg.sh pok_change_polarity_top 1

