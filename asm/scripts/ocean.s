.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x0834f578 0x0835023c ./data/scripts_ocean.bin
OceanScripts:
  .incbin "data/scripts_ocean.bin"
