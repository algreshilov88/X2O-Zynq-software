b=0
i2cset -y $b 0x71 0 # disconnect all
i2cset -y $b 0x71 1 # enable expander reg branch
#payload sequence off 
i2cset -y $b 0x45 0x24 0x00

# reset interrupt, by reading interrupt status. The status is in MSB
i2cget -y $b 0x45 0x06

# disable POK change reaction
./devreg.sh pok_change_enable_bot 0

