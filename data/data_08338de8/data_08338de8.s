    .include "asm/macros.inc"

    .section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x0833a340 0x08372210 ./data/data_08338de8/data_08338de8.bin
Data_08338de8: @ 0x08338de8
    .incbin "data/data_08338de8/data_08338de8.bin"
