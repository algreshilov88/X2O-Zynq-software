#!/bin/bash

devmem="/root/busybox-armv7l devmem"
# status
name=(ha         rdy_ipmb_zynq los_10g    pim_alarm  link_stat_top rxchan_up_top link_stat_bot rxchan_up_bot hs           prbs_err   prbs_err_sticky)
addr=(0x41220008 0x41220008    0x41220008 0x41220008 0x41220008    0x41220008    0x41220008    0x41220008    0x41220008   0x41220008 0x41220008)
bnum=(0          8             10         11         12            13            14            15            16           17         21)
mask=(0xff       3              1          1          1             1             1             1             1           0xf        0xf)

#more status
name+=(payload_off_alarm_bot payload_off_alarm_top payload_off_alarm_qsfp pok_payload pok_change_bot pok_change_top pok_change_qsfp )
addr+=(0x41220008            0x41220008            0x41220008             0x41220008  0x41220008     0x41220008     0x41220008 )
bnum+=(25                    26                    27                     28          29             30             31         )
mask+=(1                     1                     1                      1           1              1              1          )

# control
name+=(en_ipmb_zynq id         qvb_on_off prbs_sel    aurora_pma_init tx_polarity gtp_reset  channel_up_top c2c_slave_reset_top channel_up_bot c2c_slave_reset_bot prbs_sticky_reset)
addr+=(0x41220000   0x41220000 0x41220000 0x41220000  0x41220000      0x41220000  0x41220000 0x41220000     0x41220000          0x41220000     0x41220000          0x41220000)
bnum+=(0            2          5          6           9               10          14         15             16                  17             18                  19) 
mask+=(3            7          1          7           1               0xf         1          1              1                   1              1                   1)

#more control
name+=(pok_change_polarity_bot pok_change_polarity_top pok_change_polarity_qsfp pok_change_enable_bot pok_change_enable_top pok_change_enable_qsfp)
addr+=(0x41220000              0x41220000              0x41220000               0x41220000            0x41220000            0x41220000            )
bnum+=(20                      21                      22                       23                    24                    25                    )
mask+=(1                       1                       1                        1                     1                     1                     )

#syntax: devreg reg_name [wr_value]

if [ $1 ]
then
	reg_name=$1 # register name
	if [ $2 ] 
	then
		# writing
		wr_value=$2 # write value
		i=0
		found=0
		for n in "${name[@]}"
		do
			if [[ "$n" == "$1" ]]
			then
				#prepare write and mask values
				wr_value=$(( $wr_value & ${mask[$i]} ))
				wr_value=$(( $wr_value << ${bnum[$i]} ))
				msk_value=$(( ${mask[$i]} << ${bnum[$i]} ))
				msk_value=$(( 0xffffffff ^ $msk_value ))
				# read the register
				reg_read_value=`$devmem ${addr[$i]} 32`
				reg_wr_value=$(( $reg_read_value & $msk_value )) # cut the bits
				reg_wr_value=$(( $reg_wr_value | $wr_value )) # insert bits
				# split field
				# printf "%s value: %x mask: %x wr_reg: %x\n" "$n" "$wr_value" "$msk_value" "$reg_wr_value"
				command=$(printf "%s %s 32 0x%x" "$devmem" "${addr[$i]}" "$reg_wr_value")
				#`$devmem ${addr[$i]} 32 0x$reg_wr_value`
				`$command`
				found=1
				
			fi
			i=$(( $i + 1 ))
		done
		if [[ $found == 0 ]]
		then
			printf "undefined register: %s\n" "$reg_name"
		fi
	else	
		# reading
		i=0
		found=0
		for n in "${name[@]}"
		do
			if [[ "$n" == "$1" ]]
			then
				# read the register
				reg_read_value=`$devmem ${addr[$i]} 32`
				# split field
				reg_read_value=$(( $reg_read_value >> ${bnum[$i]} ))
				reg_read_value=$(( $reg_read_value &  ${mask[$i]} ))
				printf "%s = 0x%x\n" "$n" "$reg_read_value"
				found=1		
			fi
			i=$(( $i + 1 ))
		done
		if [[ $found == 0 ]]
		then
			printf "undefined register: %s\n" "$reg_name"
		fi
	fi
else	
	# no arguments, print usage
	printf "usage: devreg reg_name [wr_value]\n"
	printf "available registers:\n"
	printf "ADDR\t\tLBIT\tMASK\tNAME\n"
	i=0
	for n in "${name[@]}"
	do
		printf "%s\t%d\t%x\t%s\n" "${addr[$i]}" "${bnum[$i]}" "${mask[$i]}" "$n"
		i=$(( $i + 1 ))
	done

fi
