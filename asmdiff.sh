#!/usr/bin/env bash

# asmdiff.sh start bytesize
# start が 0x8000000 以上の場合は GBAのアドレス空間として、それ以外は GBAのROMのオフセットとして自動的に扱う

if [[ -d "$DEVKITARM/bin/" ]]; then
    OBJDUMP_BIN="$DEVKITARM/bin/arm-none-eabi-objdump"
else
    OBJDUMP_BIN="arm-none-eabi-objdump"
fi

OBJDUMP="$OBJDUMP_BIN -D -bbinary -marmv4t -Mforce-thumb"

if [ $(($1)) -ge $((0x8000000)) ]; then
    OPTIONS="--adjust-vma=0x8000000 --start-address=$(($1)) --stop-address=$(($1 + $2))"
else
    OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
fi

$OBJDUMP $OPTIONS baserom.gba > build/rmz3/baserom.dump
$OBJDUMP $OPTIONS rmz3.gba > build/rmz3/rmz3.dump
diff -u build/rmz3/baserom.dump build/rmz3/rmz3.dump
