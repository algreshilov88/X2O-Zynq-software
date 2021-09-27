# disable POK change reaction
./devreg.sh pok_change_enable_top 0
./devreg.sh pok_change_enable_bot 0

./devreg.sh qvb_on_off 1
sleep 0.2
./devreg.sh pok_payload

#enable POK change reaction
#./devreg.sh pok_change_enable_top 1
#./devreg.sh pok_change_enable_bot 1

