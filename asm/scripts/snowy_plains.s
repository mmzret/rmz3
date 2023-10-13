.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08355c70 0x08356674 ./data/scripts_snowy_plains.bin
SnowyPlainsScripts:
  .incbin "data/scripts_snowy_plains.bin"
