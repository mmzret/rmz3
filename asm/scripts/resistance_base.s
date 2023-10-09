.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/song.h"
#include "constants/solid.h"

  .balign 4
  .section .rodata

Camera_0835bdec: @ 0x0835bdec
  .byte 3
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0835be18: @ 0x0835be18
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 0x16800, 0x19000
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0835be44: @ 0x0835be44
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 0x10A800, 0x19000
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

EntityTemplate_Zero_0835be70: @ 0x0835be70
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x19000, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_Zero_0835be80: @ 0x0835be80
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0xDB000, 0x13000
  .4byte DIR_LEFT

EntityTemplate_Ciel_0835be90: @ 0x0835be90
  .byte SOLID
  .byte 21
  .byte ACTOR_SAVE_SELECT_CIEL
  .byte 0
  .4byte 0xD8000, 0x13000
  .4byte DIR_RIGHT

EntityTemplate_Zero_0835bea0: @ 0x0835bea0
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x16800, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_0835beb0: @ 0x0835beb0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 22
  .byte 0
  .4byte 0x11000, 0x1C000
  .4byte DIR_RIGHT

EntityTemplate_0835bec0: @ 0x0835bec0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 22
  .byte 1
  .4byte 0x11C00, 0x1C000
  .4byte DIR_RIGHT

EntityTemplate_Zero_0835bed0: @ 0x0835bed0
  .byte 0
  .byte 0
  .byte 0
  .byte 1
  .4byte 0x16800, 0x13000
  .4byte DIR_LEFT

EntityTemplate_0835bee0: @ 0x0835bee0
  .byte SOLID
  .byte 21
  .byte 48
  .byte 0
  .4byte 0x10B100, 0x1C000
  .4byte DIR_RIGHT

EntityTemplate_0835bef0: @ 0x0835bef0
  .byte SOLID
  .byte 21
  .byte 49
  .byte 0
  .4byte 0x106000, 0x1C000
  .4byte DIR_RIGHT

EntityTemplate_0835bf00: @ 0x0835bf00
  .byte SOLID
  .byte 21
  .byte 50
  .byte 0
  .4byte 0x10CC00, 0x1C000
  .4byte DIR_LEFT

EntityTemplate_Zero_0835bf10: @ 0x0835bf10
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x19000, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_Zero_0835bf20: @ 0x0835bf20
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x17800, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_0835bf30: @ 0x0835bf30
  .byte SOLID
  .byte 21
  .byte 61
  .byte 0
  .4byte 0xBD000, 0x26000
  .4byte DIR_LEFT

EntityTemplate_0835bf40: @ 0x0835bf40
  .byte SOLID
  .byte 21
  .byte 62
  .byte 0
  .4byte 0xB6000, 0x26000
  .4byte DIR_RIGHT

EntityTemplate_0835bf50: @ 0x0835bf50
  .byte SOLID
  .byte 21
  .byte 63
  .byte 0
  .4byte 0xB3000, 0x26000
  .4byte DIR_RIGHT

EntityTemplate_Zero_0835bf60: @ 0x0835bf60
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x77000, 0x39000
  .4byte DIR_RIGHT

EntityTemplate_0835bf70: @ 0x0835bf70
  .byte SOLID
  .byte 21
  .byte 64
  .byte 0
  .4byte 0x1C800, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_0835bf80: @ 0x0835bf80
  .byte SOLID
  .byte 21
  .byte 64
  .byte 1
  .4byte 0x10800, 0x1D000
  .4byte DIR_RIGHT

EntityTemplate_0835bf90: @ 0x0835bf90
  .byte SOLID
  .byte 21
  .byte 64
  .byte 2
  .4byte 0x1B400, 0x1D000
  .4byte DIR_LEFT

EntityTemplate_0835bfa0: @ 0x0835bfa0
  .byte SOLID
  .byte 21
  .byte 64
  .byte 3
  .4byte 0x11C00, 0x1D000
  .4byte DIR_RIGHT

EntityTemplate_0835bfb0: @ 0x0835bfb0
  .byte SOLID
  .byte 21
  .byte 65
  .byte 0
  .4byte 0x16800, 0x1C000
  .4byte DIR_RIGHT

Script_0835bfc0:
  spawn 0, 0, EntityTemplate_Zero_0835be70
  cmd04 0, 0, Camera_0835bdec
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_ContinueGameSaveSelect:
  spawn 0, 0, EntityTemplate_Zero_0835be80
  spawn 3, 0, EntityTemplate_Ciel_0835be90
  cmd04 0, 0, Camera_0835bdec
  lock
  normal_screen
  play_bgm BGM_RBASE
  wait 1
  start_talk
  wait_screeneffect
  resume 0
  end

Script_0835c060:
  spawn 0, 0, EntityTemplate_Zero_0835bea0
  cmd04 0, 0, Camera_0835bdec
  lock
  normal_screen
  wait_screeneffect
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_ReturnFromStageRun:
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  cmd04 0, 0, Camera_0835be18
  normal_screen
  wait FRAME
  spawn 3, 0, EntityTemplate_0835beb0
  spawn 4, 0, EntityTemplate_0835bec0
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_screeneffect
  print_message 0x14, 0x0050
  wait_msgbox_end
  play_se SE_TENSOU_VOICE
  wait SECOND
  spawn 0, 1, EntityTemplate_Zero_0835bed0
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, 0x0051 @ おつかれさまでした
  wait_msgbox_end
  cmd04 0, 0, Camera_0835bdec
  play_bgm BGM_RBASE
  wait SECOND+15*FRAME
  gimmick 1, 1, 1
  wait SECOND/4
  goodluck 0
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  wait 8*FRAME
  gimmick 1, 1, 2
  wait 8*FRAME
  gimmick 1, 1, 0x82
  wait 8*FRAME
  gimmick 1, 1, 0x80
  wait 45*FRAME
  message 1, 0, 0x1300
  wait_msgbox_end
  wait SECOND/2
  cmd0d 3, 1, 1
  wait SECOND/4
  cmd0d 4, 1, 1
  wait 3*SECOND
  cmd0c 3, 6, 0
  cmd0c 4, 6, 0
  gimmick 1, 1, 0x82
  wait 8*FRAME
  gimmick 1, 1, 2
  wait 8*FRAME
  gimmick 1, 1, 0
  wait SECOND/4
  start_talk
  wait 16*FRAME
  wait_msgbox_end
  release
  resume 0
  end

Script_0835c288:
  lock
  message 1, 0, 0x1310
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 2
  wait SECOND/2
  message 1, 0, 0x1311
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  wait 8*FRAME
  start_talk
  wait 16*FRAME
  wait_msgbox_end
  stop_bgm
  wait SECOND
  screeneffect 10
  wait_screeneffect
  cmd0c 0, 6, 0
  wait SECOND*2
  end

Script_ReceiveRod:
  lock
  wait_msgbox_end
  wait 70*FRAME
  message 1, 0, 0x011F @ リコイルロッドを手に入れた！
  wait_msgbox_end
  message 1, 0, 0x0120
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, 0x1308
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, 0x1309
  wait_msgbox_end
  wait SECOND
  message 1, 0, 0x130A
  wait_msgbox_end
  wait SECOND/2
  end_talk
  wait SECOND/2
  walkto 0xD5000
  wait SECOND/2
  message 1, 0, 0x130B @ リコイルロッド使いやすそうだ...
  wait_msgbox_end
  wait SECOND/4
  sweep 2, 0, 0
  forcekeyinput DPAD_LEFT
  wait 10*FRAME
  blackout_screen
  wait_screeneffect
  lock
  cmd05 0x10, 0, 0
  normal_screen
  wait_screeneffect
  message 1, 0, 0x130C
  wait_msgbox_end
  sweep 3, 0, 0
  wait 32*FRAME
  cmd05 0x11, 0, 0
  wait_screeneffect
  release
  resume 0
  end

Script_0835c480:
  lock
  killtimeelf
  force 1, 0, 0
  end_talk
  wait SECOND/4
  walkto 0x16800
  wait SECOND/4
  cmd0c 0, 2, 0
  message 1, 0, 0x46
  wait_msgbox_end
  stop_bgm
  play_se SE_TENSOU_BEEP
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait SECOND
  print_message 0x1E, 0x47
  wait_msgbox_end
  wait SECOND/4
  print_message 0x14, 0x48
  wait SECOND/4
  play_se SE_TENSOU_VOICE
  wait SECOND*3/4
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait SECOND/2
  fadeout_se SECOND SE_TENSOU_BEEP
  wait SECOND/4
  goodluck 1
  wait SECOND/4
  emergency_off
  wait_msgbox_end
  wait SECOND/4
  blackout_screen
  wait_screeneffect
  wait SECOND
  end

Script_0835c5b0:
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  cmd04 0, 0, Camera_0835be18
  normal_screen
  wait FRAME
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_screeneffect
  print_message 0x14, 0x50
  wait_msgbox_end
  play_se SE_TENSOU_VOICE
  wait SECOND
  spawn 0, 1, EntityTemplate_Zero_0835bed0
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, 0x51
  wait_msgbox_end
  cmd04 0, 0, Camera_0835bdec
  play_bgm BGM_RBASE
  wait 75*FRAME
  gimmick 1, 1, 1
  wait SECOND/4
  goodluck 0
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  release
  resume 0
  end

Script_FreeRunTransport:
  lock
  killtimeelf
  force 1, 0, 0
  end_talk
  wait SECOND/4
  walkto 0x16800
  wait SECOND/4
  cmd0c 0, 2, 0
  stop_bgm
  play_se SE_TENSOU_BEEP
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait SECOND
  print_message 0x1E, 0x47
  wait_msgbox_end
  wait SECOND/4
  print_message 0x14, 0x48
  wait SECOND/4
  play_se SE_TENSOU_VOICE
  wait SECOND*3/4
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  fadeout_se SECOND SE_TENSOU_BEEP
  emergency_off
  wait SECOND
  blackout_screen
  wait_screeneffect
  wait SECOND
  end

Script_0835c7b0:
# ./tools/dumper/bin.ts ./baserom.gba 0x0835c7b0 0x0835d3f0 ./data/scripts2.bin
.incbin "data/scripts2.bin"

Script_0835d3f0:
  spawn 0, 0, EntityTemplate_Zero_0835bf60
  cmd04 0, 0, Camera_0835bdec
  lock
  normal_screen
  wait_screeneffect
  play_bgm BGM_RBASE
  release
  resume 0
  end

# ./tools/dumper/bin.ts ./baserom.gba 0x0835d438 0x0835dae0 ./data/Script_0835d438.bin
Script_0835d438:
  .incbin "data/Script_0835d438.bin"

Script_0835dae0:
  wait SECOND/4
  message 1, 0, 0x1360
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, 0x1361
  wait_msgbox_end
  wait 90*FRAME
  message 1, 0, 0x1362
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, 0x1363
  wait_msgbox_end
  wait SECOND/4
  end

.global ResistanceBaseScriptList
ResistanceBaseScriptList:
  .word Script_0835bfc0
  .word Script_ContinueGameSaveSelect
  .word Script_0835c060
  .word Script_ReturnFromStageRun
  .word Script_0835c288
  .word Script_ReceiveRod
  .word Script_0835c480
  .word Script_0835c5b0
  .word Script_FreeRunTransport
  .word Script_0835c7b0
  .word 0x0835C868
  .word 0x0835CA60
  .word 0x0835CCC8
  .word 0x0835CDB8
  .word 0x0835CDF0
  .word 0x0835D108
  .word 0x0835D1A8
  .word 0x0835D208
  .word Script_0835d3f0
  .word Script_0835d438
  .word Script_0835dae0
  .word 0x0835D098
