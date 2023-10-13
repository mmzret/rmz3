    .include "asm/macros.inc"
    
    .balign 4
    .section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08356674 0x08358e4c ./data/scripts.bin
TodoScripts: @ 0x834cfd4
    .incbin "data/scripts.bin"
