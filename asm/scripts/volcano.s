    .include "asm/macros.inc"
    
    .balign 4
    .section .rodata

Camera_0834ecfc: @ 0x0834ecfc
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

# ./tools/dumper/bin.ts ./baserom.gba 0x0834ed28 0x0834f578 ./data/scripts_volcano.bin
VolcanoScripts: @ 0x834cfd4
    .incbin "data/scripts_volcano.bin"
