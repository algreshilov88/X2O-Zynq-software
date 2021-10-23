b=2

# disable POK change reaction
./devreg.sh pok_change_enable_qsfp 0

# payload sequence on 
i2cset -y $b 0x10 0xff 0xff 0xff i

# let power turn on
#sleep 0.2

# check POK bits from payload
#i2cget -y $b 0x45 0x58

# enable register and interrupt output P31
#i2cset -y $b 0x45 0x04 0x81

#enable POK change reaction
#./devreg.sh pok_change_enable_bot 1


