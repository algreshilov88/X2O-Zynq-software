# all TX signals inverted on power board
./devreg.sh tx_polarity 0xf
./devreg.sh channel_up_bot 0
./devreg.sh c2c_slave_reset_bot 1
./devreg.sh c2c_slave_reset_bot 0
./devreg.sh channel_up_bot 1
./devreg.sh link_stat_bot

