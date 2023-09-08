.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x0835416c 0x08354840 ./data/frostline_ice_base.bin
FrostlineIceBaseScripts:
  .incbin "data/frostline_ice_base.bin"
