b=2

# disable POK change reaction
./devreg.sh pok_change_enable_qsfp 0

#payload sequence off 
i2cset -y $b 0x10 0xfe 0xff 0xff i

# reset interrupt, by reading interrupt status. The status is in MSB
#i2cget -y $b 0x45 0x06

