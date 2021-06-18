# all TX signals inverted on power board
./devreg.sh tx_polarity 0xf
./devreg.sh channel_up 0
./devreg.sh c2c_slave_reset 1
./devreg.sh c2c_slave_reset 0
./devreg.sh channel_up 1
./devreg.sh link_stat_top
./devreg.sh link_stat_bot

