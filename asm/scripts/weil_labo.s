.include "asm/macros.inc"
.include "asm/scripts/constants.inc"

.balign 4
.section .rodata

Camera_08358e4c: @ 0x08358e4c
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358e78: @ 0x08358e78
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 416*PX, 672*PX

Camera_08358ea4: @ 0x08358ea4
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, 0*PX

Camera_08358ed0: @ 0x08358ed0
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 256*PX, 512*PX

Camera_08358efc: @ 0x08358efc
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 2880*PX, 1200*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f28: @ 0x08358f28
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 2808*PX, 1200*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f54: @ 0x08358f54
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 1768*PX, 560*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f80: @ 0x08358f80
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 7440*PX, 7680*PX, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Zero_08358fac: @ 0x08358fac
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 352*PX, 448*PX
  .4byte DIR_RIGHT

Zero_08358fbc: @ 0x08358fbc
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3000*PX, 560*PX
  .4byte DIR_RIGHT

# ./tools/dumper/bin.ts ./baserom.gba 0x08358fcc 0x0835bdec ./data/scripts_weil_labo.bin
WeilLaboScripts:
  .incbin "data/scripts_weil_labo.bin"
