.include "asm/macros.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/boss.h"
#include "constants/solid.h"

.balign 4
.section .rodata

Camera_08354840: @ 0x08354840
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0835486c: @ 0x0835486c
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x103000, 0x116000, 0x0, 0x280000

Entity_Zero_08354898: @ 0x08354898
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 352*PX, 2528*PX
  .4byte DIR_RIGHT

Entity_Zero_083548a8: @ 0x083548a8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 2032*PX
  .4byte DIR_RIGHT

Entity_Zero_083548b8: @ 0x083548b8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 448*PX
  .4byte DIR_RIGHT

Entity_Zero_083548c8: @ 0x083548c8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 4192*PX, 448*PX
  .4byte DIR_RIGHT

Entity_CopyX: @ 0x083548d8
  .byte ENTITY_BOSS
  .byte BOSS_COPY_X
  .byte 0
  .byte 0
  .4byte 4336*PX, 448*PX
  .4byte DIR_LEFT

Entity_Unk_083548e8: @ 0x083548e8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 0
  .4byte 4264*PX, 448*PX
  .4byte DIR_RIGHT

Entity_Unk_083548f8: @ 0x083548f8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 1
  .4byte 4264*PX, 448*PX
  .4byte DIR_LEFT

# ./tools/dumper/bin.ts ./baserom.gba 0x08354908 0x08355330 ./data/area_x2.bin
AreaX2Scripts:
  .incbin "data/area_x2.bin"

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gAreaX2ScriptList
gAreaX2ScriptList: @ 0x08355330
  .word 0x08354908
  .word 0x08354990
  .word 0x083549F0
  .word 0x08354A48
  .word 0x08354AA0
  .word 0x08354B00
  .word 0x08354C00
  .word 0x08354CF0
  .word 0x08354DB0
  .word 0x08354F98
  .word 0x08354FC0
  .word 0x08355230
  .word 0x083552A8
