# Power enable = 0
# POK inputs = 1 to make them inputs
# the rest of the bits are QSFP selects = 1 (inverted)
i2cset -y 2 0x10 0xfe 0xff 0xff i

#all bits here are QSFP selects = 1 (inverted)
i2cset -y 2 0x12 0xff 0xff 0xff i

