    .include "asm/macros.inc"
    
    .balign 4
    .section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08355364 0x0835bdec ./data/scripts.bin
TodoScripts: @ 0x834cfd4
    .incbin "data/scripts.bin"
