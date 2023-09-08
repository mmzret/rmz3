.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"

  .balign 4
  .section .rodata

Camera_0834d1d8:
  .byte 0x06, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00

EntityTemplate_0834d204:
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x92000, 0x12000
  .4byte DIR_LEFT

Script_Stage0: @ 0x0834d214
  spawn 0 0 EntityTemplate_0834d204
  cmd04 0 0 Camera_0834d1d8
  lock
  screeneffect 9
  screeneffect 0
  indicator 1 0 0
  indicator 0 0 0
  release
  resume 0
  end

.global Stage0ScriptList
Stage0ScriptList: @ 0x0834d264
  .word Script_Stage0