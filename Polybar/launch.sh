#!/bin/sh

# 1. Kill any existing bars
killall -9 polybar 2>/dev/null

# 2. Wait for them to actually die
while pgrep -u $(id -u) -x polybar >/dev/null; do sleep 1; done

# 3. Detect monitors and launch
# This works in any shell because it uses /bin/sh
if command -v xrandr >/dev/null; then
  for m in $(xrandr --query | grep " connected" | cut -d" " -f1); do
    MONITOR=$m polybar --reload mybar &
  done
else
  polybar --reload mybar &
fi
