#!/usr/bin/fish
set chosen (echo -e "󰍃 Logout\n󰜉 Reboot\n󰐥 Poweroff" | rofi -dmenu -i -p "󰐥 System" -theme ~/.config/rofi/vxwm.rasi)
function poweroff_cmd
    if command -v loginctl >/dev/null 2>&1
        loginctl poweroff
    else
        poweroff
    end
end
function reboot_cmd
    if command -v loginctl >/dev/null 2>&1
        loginctl reboot
    else
        reboot
    end
end
switch $chosen
    case '*Logout'
        pkill vxwm
    case '*Reboot'
        reboot
    case '*Poweroff'
        poweroff
end
