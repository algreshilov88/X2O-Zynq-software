# Power enable = 0
# POK inputs = 1 to make them inputs
# the rest of the bits are QSFP selects = 0
i2cset -y 2 0x10 0xfe 0x09 0x21 i

#all bits here are QSFP selects = 0
i2cset -y 2 0x12 0    0    0    i

