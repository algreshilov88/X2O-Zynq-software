# switch to QSFP I2C
devmem 0x41200000 32 2

#configure expander
i2cset -y 2 0x18 3 0xe6 # program inputs in max7310
i2cset -y 2 0x18 2 0x00 # program inversions in max7310
i2cset -y 2 0x18 4 0x00 # disable timeout in max7310

# write initial 0 into pipeline
i2cset -y 2 0x18 1 0xe7 # QD = 0 QCK = 0
i2cset -y 2 0x18 1 0xef # QD = 0 QCK = 1
i2cset -y 2 0x18 1 0xe7 # QD = 0 QCK = 0
i2cset -y 2 0x18 1 0xf7 # QD = 1 QCK = 0

for i in `seq 1 28`;
do
	# read CDR enable flags
	i2cget -y 2 0x50 98 w
	# enable all CDRs
	i2cset -y 2 0x50 98 0xff
	# read flags again
	i2cget -y 2 0x50 98 w

	# move selector one position
	i2cset -y 2 0x18 1 0xff # QCK = 1
	i2cset -y 2 0x18 1 0xf7 # QCK = 0

#	sleep 0.5
done
