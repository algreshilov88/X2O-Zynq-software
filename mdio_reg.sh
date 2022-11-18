#!/bin/bash

devmem="/root/busybox-arm64 devmem"
mdio_reg=0xFF0B0034

if [ $# -eq 3 ] # write
then
    # echo "$1 $2 $3"
	#construct write value
	wr_value=$3 # data
	wr_value=$(( $wr_value | ( 1 << 28) )) # write
	wr_value=$(( $wr_value | ($1 << 23) )) # phy adddr
	wr_value=$(( $wr_value | ($2 << 18) )) # reg adddr
	wr_value=$(( $wr_value | ( 2 << 16) )) # fixed
	wr_value=$(( $wr_value | ( 1 << 30) )) # fixed

	# printf "0x%x\n" "$wr_value"
	command=$(printf "%s %s 32 0x%x" "$devmem" "$mdio_reg" "$wr_value")
	`$command`

else
if [ $# -eq 2 ] # read
then
    # echo "$1 $2"
	#construct write value
	wr_value=$(( (2 << 28) )) # read
	wr_value=$(( $wr_value | ($1 << 23) )) # phy adddr
	wr_value=$(( $wr_value | ($2 << 18) )) # reg adddr
	wr_value=$(( $wr_value | ( 2 << 16) )) # fixed
	wr_value=$(( $wr_value | ( 1 << 30) )) # fixed

	# printf "0x%x\n" "$wr_value"
	command=$(printf "%s %s 32 0x%x" "$devmem" "$mdio_reg" "$wr_value")
	`$command`
	sleep 0.01
	rd_value=`$devmem $mdio_reg 32`
	rd_value=$(( $rd_value & 0xffff ))
	printf "0x%04x\n" $rd_value

else
	echo 'usage: mdio_reg.sh phy=2|3 reg [write_data]'
fi
fi

