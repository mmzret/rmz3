.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x08351d88 0x0835320c ./data/scripts_missile_factory.bin
MissleFactoryScripts:
  .incbin "data/scripts_missile_factory.bin"
