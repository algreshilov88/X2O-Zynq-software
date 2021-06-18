
#i2cset -y 1 0x18 1 0xe7 # QD = 0 QCK = 0
#i2cset -y 1 0x18 1 0xef # QD = 0 QCK = 1
#i2cset -y 1 0x18 1 0xe7 # QD = 0 QCK = 0        
#i2cset -y 1 0x18 1 0xf7 # QD = 1 QCK = 0


for i in `seq 1 $1`;
do
	i2cset -y 1 0x18 1 0xe7 # QCK = 1
	i2cset -y 1 0x18 1 0xef # QCK = 0
done

