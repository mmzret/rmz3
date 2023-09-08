.include "asm/macros.inc"

.balign 4
.section .rodata

# ./tools/dumper/bin.ts ./baserom.gba 0x0835023c 0x08350b40 ./data/scripts_repair_factory.bin
RepairFactoryScripts:
  .incbin "data/scripts_repair_factory.bin"
