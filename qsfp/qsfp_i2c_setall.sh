for i in `seq 1 100`;
do
	i2cset -y 1 0x18 1 0xe7 # QD = 1
	i2cset -y 1 0x18 1 0xef # QD = 1 QCK = 1
done

