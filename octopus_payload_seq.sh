# this should return 0x69
i2cget -y 2 0x69 5

i2cset -y 2 0x69 10 1
i2cset -y 2 0x69 7 0x1
i2cset -y 2 0x69 7 0x7
i2cset -y 2 0x69 7 0xf
i2cset -y 2 0x69 7 0x1f
i2cset -y 2 0x69 7 0x3f
i2cset -y 2 0x69 7 0x7f
i2cset -y 2 0x69 7 0xff
i2cset -y 2 0x69 9 0x1
i2cset -y 2 0x69 9 0x3
i2cset -y 2 0x69 9 0x7
i2cset -y 2 0x69 9 0xf
i2cset -y 2 0x69 9 0x1f
i2cset -y 2 0x69 8 0x1
i2cset -y 2 0x69 8 0x3
i2cset -y 2 0x69 8 0x7
i2cset -y 2 0x69 8 0xf
i2cset -y 2 0x69 8 0x1f
i2cset -y 2 0x69 8 0x3f
sleep 1
# read power status: {pgood_s_latch  pgood_n_latch  alert_s_latch  alert_n_latch  pgood_s  pgood_n  alert_s  alert_n}
i2cget -y 2 0x69 4
