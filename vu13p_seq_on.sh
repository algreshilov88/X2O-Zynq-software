# all other voltages
i2cset -y 1 0x69 7 0xff
# VCCINT
i2cset -y 1 0x69 8 0x1
sleep 0.01
# += AVCC + AUX
i2cset -y 1 0x69 8 0x17
sleep 0.01
# += AVTT
i2cset -y 1 0x69 8 0x3f

