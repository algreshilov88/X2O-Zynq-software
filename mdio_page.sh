#!/bin/bash

mdio_reg="./mdio_reg.sh"

if [ $# -eq 4 ] # write
then
	# write page number into reg 31
	command=$(printf "%s %s 31 %s" "$mdio_reg" "$1" "$2")
	`$command`
	# write data into selected register
	command=$(printf "%s %s %s %s" "$mdio_reg" "$1" "$3" "$4")
	`$command`
	# restore page 0
	command=$(printf "%s %s 31 0" "$mdio_reg" "$1")
	`$command`


else
if [ $# -eq 3 ] # read
then
	# write page number into reg 31
	command=$(printf "%s %s 31 %s" "$mdio_reg" "$1" "$2")
	`$command`
	# read data from selected register
	rd_value=`$mdio_reg $1 $3`
	printf "0x%04x\n" $rd_value
	# restore page 0
	command=$(printf "%s %s 31 0" "$mdio_reg" "$1")
	`$command`

else
	echo 'usage: mdio_page.sh phy=2|3 page reg [write_data]'
fi
fi

