b=2
echo 'instant LOL status, bit 1'
i2cget -y $b 0x68 0xe
echo 'sticky LOL status, bit 1'
i2cget -y $b 0x68 0x13
echo 'reset sticky LOL'
i2cset -y $b 0x68 0x13 0x2d
