# disable POK change reaction
./$DEVREG pok_change_enable_top 0
./$DEVREG pok_change_enable_bot 0

./$DEVREG qvb_on_off 1
sleep 0.2
./$DEVREG pok_payload

#enable POK change reaction
#./$DEVREG pok_change_enable_top 1
#./$DEVREG pok_change_enable_bot 1

