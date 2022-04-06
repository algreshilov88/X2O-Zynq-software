
i2cset -y 2 0x18 3 0x19 # program outputs in max7310
i2cset -y 2 0x18 1 0    # all zeros to outputs
i2cset -y 2 0x18 1 0x10 # QD = 1
i2cset -y 2 0x18 1 0x18 # QD = 1 QCK = 1
i2cset -y 2 0x18 1 0x10 # QD = 1
i2cset -y 2 0x18 1 0    # all zeros. This clocked QSFP0 = 1
