#!/usr/bin/fish
set chosen (echo -e "󰍃 Logout\n󰜉 Reboot\n󰐥 Poweroff" | rofi -dmenu -i -p "󰐥 System" -theme ~/.config/rofi/vxwm.rasi)
switch $chosen
    case '*Logout'
        pkill vxwm
    case '*Reboot'
        reboot
    case '*Poweroff'
        poweroff
end
