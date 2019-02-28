#!/bin/sh
setxkbmap hu
feh --bg-scale $HOME/.config/background/customwall.png $HOME/.config/background/customwall2.png
$HOME/.config/SUCKLESS/xssstate/xsidle.sh slock &
/usr/local/bin/slstatus &
exec dwm
