echo 'POK status BOT'
i2cset -y 0 0x71 1
i2cget -y 0 0x45 0x58
echo 'POK status TOP'
i2cset -y 1 0x71 1
i2cget -y 1 0x45 0x58

