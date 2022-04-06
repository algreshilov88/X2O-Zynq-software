b=1
i2cget -y $b 0x45 0x06
# re-enable register and interrupt output P31
i2cset -y $b 0x45 0x04 0x81
