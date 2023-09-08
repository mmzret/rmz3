.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08353a80 0x0835416c ./data/anatre_forest.bin
AnatreForesetScripts:
  .incbin "data/anatre_forest.bin"
