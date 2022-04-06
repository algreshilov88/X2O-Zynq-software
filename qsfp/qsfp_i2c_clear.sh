for i in `seq 1 100`;
do
	i2cset -y 2 0x18 1 0xf7 # QD = 1
	i2cset -y 2 0x18 1 0xff # QD = 1 QCK = 1
done
