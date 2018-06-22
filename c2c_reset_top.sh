# all TX signals inverted on power board
./devreg.sh tx_polarity 0xf
./devreg.sh channel_up_top 0
./devreg.sh c2c_slave_reset_top 1
./devreg.sh c2c_slave_reset_top 0
./devreg.sh channel_up_top 1
./devreg.sh link_stat_top

