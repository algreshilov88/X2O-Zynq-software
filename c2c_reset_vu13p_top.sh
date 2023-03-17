# all TX signals inverted on power board
./devreg_us.sh tx_polarity 0xf
./devreg_us.sh channel_up_top 0
./devreg_us.sh c2c_slave_reset_top 1
./devreg_us.sh c2c_slave_reset_top 0
./devreg_us.sh channel_up_top 1
./devreg_us.sh link_stat_top

