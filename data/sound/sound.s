    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

ToneDatas: @ 0x0810e5a4
    # ./tools/dumper/bin.ts ./baserom.gba 0x0810e5a4 0x08338c74 ./data/sound/sound.bin
    .incbin "data/sound/sound.bin"
