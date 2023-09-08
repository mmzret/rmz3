.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x0835320c 0x08353a80 ./data/twilight_desert.bin
TwilightDesertScripts:
  .incbin "data/twilight_desert.bin"
