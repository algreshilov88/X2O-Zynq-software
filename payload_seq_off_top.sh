b=1
i2cset -y $b 0x71 0 # disconnect all
i2cset -y $b 0x71 1 # enable expander reg branch
#payload sequence off 
i2cset -y $b 0x45 0x24 0x00

