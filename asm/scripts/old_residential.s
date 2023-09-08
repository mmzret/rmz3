.include "asm/macros.inc"
.include "asm/scripts/constants.inc"

.balign 4
.section .rodata

Camera_08350b40: @ 0x08350b40
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_08350b6c: @ 0x08350b6c
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 7560*PX, 240*PX
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Entity_08350b98: @ 0x08350b98
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 352*PX, 768*PX
  .4byte DIR_RIGHT

Entity_08350ba8: @ 0x08350ba8
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 3168*PX, 288*PX
  .4byte DIR_RIGHT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

# ./tools/dumper/bin.ts ./baserom.gba 0x08350bb8 0x08351d88 ./data/scripts_ols.bin
OldLifeSpaceScripts:
  .incbin "data/scripts_ols.bin"
