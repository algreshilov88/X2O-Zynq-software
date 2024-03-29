i2cset -y $I2C_XGBUFFER 0x50 0x00 1 #reset
i2cset -y $I2C_XGBUFFER 0x50 0x00 0

i2cget -y $I2C_XGBUFFER 0x50 0x1
i2cget -y $I2C_XGBUFFER 0x50 0x2
i2cget -y $I2C_XGBUFFER 0x50 0x8

# set DE values according to datasheet page 16 (top)
i2cset -y $I2C_XGBUFFER 0x50 0x11	0x1
i2cset -y $I2C_XGBUFFER 0x50 0x18	0x1
i2cset -y $I2C_XGBUFFER 0x50 0x1f	0x1
i2cset -y $I2C_XGBUFFER 0x50 0x26	0x1
i2cset -y $I2C_XGBUFFER 0x50 0x2e	0x38
i2cset -y $I2C_XGBUFFER 0x50 0x35	0x38
i2cset -y $I2C_XGBUFFER 0x50 0x3c	0x38
i2cset -y $I2C_XGBUFFER 0x50 0x43	0x38

