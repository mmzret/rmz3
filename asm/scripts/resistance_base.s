.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/song.h"
#include "constants/entity.h"

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

Entity_Zero_0835bed0: @ 0x0835bed0
  .byte 0
  .byte 0
  .byte 0
  .byte 1
  .4byte 0x16800, 0x13000
  .4byte DIR_LEFT

Entity_0835bee0: @ 0x0835bee0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 48
  .byte 0
  .4byte 0x10B100, 0x1C000
  .4byte DIR_RIGHT

Entity_0835bef0: @ 0x0835bef0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 49
  .byte 0
  .4byte 0x106000, 0x1C000
  .4byte DIR_RIGHT

Entity_0835bf00: @ 0x0835bf00
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 50
  .byte 0
  .4byte 0x10CC00, 0x1C000
  .4byte DIR_LEFT

Entity_0835bf10: @ 0x0835bf10
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x19000, 0x1D000
  .4byte DIR_LEFT

Entity_0835bf20: @ 0x0835bf20
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x17800, 0x1D000
  .4byte DIR_LEFT

Entity_0835bf30: @ 0x0835bf30
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 61
  .byte 0
  .4byte 0xBD000, 0x26000
  .4byte DIR_LEFT

Entity_0835bf40: @ 0x0835bf40
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 62
  .byte 0
  .4byte 0xB6000, 0x26000
  .4byte DIR_RIGHT

Entity_0835bf50: @ 0x0835bf50
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 63
  .byte 0
  .4byte 0xB3000, 0x26000
  .4byte DIR_RIGHT

Entity_0835bf60: @ 0x0835bf60
  .byte 0
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x77000, 0x39000
  .4byte DIR_RIGHT

Entity_0835bf70: @ 0x0835bf70
  .byte SOLID
  .byte 21
  .byte 64
  .byte 0
  .4byte 0x1C800, 0x1D000
  .4byte DIR_LEFT

Entity_0835bf80: @ 0x0835bf80
  .byte SOLID
  .byte 21
  .byte 64
  .byte 1
  .4byte 0x10800, 0x1D000
  .4byte DIR_RIGHT

Entity_0835bf90: @ 0x0835bf90
  .byte SOLID
  .byte 21
  .byte 64
  .byte 2
  .4byte 0x1B400, 0x1D000
  .4byte DIR_LEFT

Entity_0835bfa0: @ 0x0835bfa0
  .byte SOLID
  .byte 21
  .byte 64
  .byte 3
  .4byte 0x11C00, 0x1D000
  .4byte DIR_RIGHT

Entity_0835bfb0: @ 0x0835bfb0
  .byte SOLID
  .byte 21
  .byte 65
  .byte 0
  .4byte 0x16800, 0x1C000
  .4byte DIR_RIGHT

Script_0835bfc0:
  spawn 0, 0, EntityTemplate_Zero_0835be70
  reset_camera Camera_0835bdec
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
  reset_camera Camera_0835bdec
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
  reset_camera Camera_0835bdec
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
  reset_camera Camera_0835be18
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
  spawn 0, 1, Entity_Zero_0835bed0
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, 0x0051 @ おつかれさまでした
  wait_msgbox_end
  reset_camera Camera_0835bdec
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
  entityflag 3, 0, TRUE
  wait SECOND/4
  entityflag 4, 0, TRUE
  wait 3*SECOND
  destroy 3
  destroy 4
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
  destroy 0
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
  stop_camera
  normal_screen
  wait_screeneffect
  message 1, 0, 0x130C @ シエルにはまだ...ささえてやってくれ ゼロ....
  wait_msgbox_end
  sweep 3, 0, 0
  wait 32*FRAME
  resume_camera
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
  turn_left 0
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
  reset_camera Camera_0835be18
  normal_screen
  wait FRAME
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_screeneffect
  print_message 0x14, 0x50
  wait_msgbox_end
  play_se SE_TENSOU_VOICE
  wait SECOND
  spawn 0, 1, Entity_Zero_0835bed0
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, 0x51
  wait_msgbox_end
  reset_camera Camera_0835bdec
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
  turn_left 0
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
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  reset_camera Camera_0835be18
  normal_screen
  wait FRAME
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_screeneffect
  spawn 0, 1, Entity_Zero_0835bed0
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, 0x51
  wait_msgbox_end
  reset_camera Camera_0835bdec
  play_bgm BGM_RBASE
  wait 75*FRAME
  release
  resume 0
  end

Script_0835c868:
  eventflag 0, 17, 0
  gimmick 0, 10, 0
  reset_camera Camera_0835be44
  normal_screen
  wait 1
  cmd1c 0, 0, 0
  gimmick 0, 10, 0
  spawn 3, 0, Entity_0835bee0
  spawn 4, 0, Entity_0835bef0
  screeneffect 9
  wait_screeneffect
  play_bgm 164
  wait 120
  message 1, 0, 0x1315
  wait_msgbox_end
  entityflag 4, 0, TRUE
  wait 30
  message 1, 0, 0x1316
  wait_msgbox_end
  wait 15
  spawn 5, 0, Entity_0835bf00
  wait 60
  message 1, 0, 0x1317
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 118, 0, 0
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x1318
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0835be44
  normal_screen
  wait_screeneffect
  wait 15
  entityflag 5, 0, TRUE
  wait 90
  message 1, 0, 0x1319
  wait_msgbox_end
  emotion 4, 0x0C00, 0x00FFD000, 0
  wait 75
  message 1, 0, 0x131A
  wait_msgbox_end
  entityflag 5, 0, FALSE
  wait 75
  message 1, 0, 0x131B
  wait_msgbox_end
  stop_bgm
  wait 60
  screeneffect 10
  wait_screeneffect
  wait 120
  destroy 3
  destroy 4
  destroy 5
  eventflag 1, 0, 0
  end

Script_0835ca60:
  eventflag 0, 18, 0
  cmd1c 1, 0, 0
  wait 1
  gimmick 0, 17, 0
  spawn 0, 0, Entity_0835bf10
  reset_camera Camera_0835bdec
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 186
  wait 60
  stop_bgm
  play_se 293
  emergency_on
  emotion 0, 0x0800, 0x00FFD800, 0
  wait 75
  play_bgm 167
  message 1, 0, 0x131C
  wait_msgbox_end
  wait 15
  force 9, 0, 92160
  lock
  wait 15
  message 1, 0, 0x131D
  wait_msgbox_end
  sweep 2, 0, 0
  wait 15
  gimmick 1, 1, 1
  wait 30
  message 1, 0, 0x131E
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 45
  message 1, 0, 0x131F
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 30
  message 1, 0, 0x1320
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 2
  wait 15
  message 1, 0, 0x1321
  wait_msgbox_end
  wait 90
  gimmick 1, 1, 0
  wait 15
  message 1, 0, 0x1322
  wait_msgbox_end
  wait 15
  gimmick 1, 0, 1
  wait 75
  print_message 20, 0x0048
  wait 15
  play_se 153
  wait 45
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait 30
  fadeout_se 60, 293
  gimmick 1, 1, 1
  wait 30
  message 1, 0, 0x1323
  wait 15
  emergency_off
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_screeneffect
  wait 60
  sweep 3, 0, 0
  eventflag 1, 0, 0
  end

Script_0835ccc8:
  spawn 0, 0, Entity_0835bf20
  lock
  sweep 2, 0, 0
  wait 1
  force 2, 0, 0
  wait 15
  reset_camera Camera_0835bdec
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 167
  wait 30
  gimmick 1, 1, 1
  wait 30
  message 1, 0, 0x1324
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  gimmick 1, 1, 2
  message 1, 0, 0x1325
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  sweep 3, 0, 0
  wait 16
  wait_msgbox_end
  wait 30
  end

Script_0835cdb8:
  spawn 0, 0, Entity_0835bf20
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_screeneffect
  play_bgm 167
  end

Script_0835cdf0:
  eventflag 0, 24, 0
  wait 30
  play_se 298
  wait 90
  message 1, 0, 0x1329
  wait_msgbox_end
  wait 15
  emotion 0, 0x0800, 0x00FFD800, 0
  wait 75
  sweep 2, 0, 0
  force 2, 0, 0
  wait 60
  message 1, 0, 0x132A
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 119, 0, 0
  normal_screen
  wait_screeneffect
  play_bgm 166
  wait 15
  message 1, 0, 0x132B
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x132C
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 2
  wait 90
  message 1, 0, 0x132D
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 15
  message 1, 0, 0x132E
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 119, 0, 0
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x132F
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_screeneffect
  wait 15
  stop_bgm
  message 1, 0, 0x1330
  wait_msgbox_end
  wait 15
  play_se 293
  emergency_on
  wait 90
  message 1, 0, 0x1331
  wait_msgbox_end
  fadeout_se 60, 293
  emergency_off
  wait 15
  eventflag 1, 0, 0
  sweep 3, 0, 0
  wait 16
  play_bgm 186
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d098:
  spawn 0, 0, Entity_0835bf20
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_screeneffect
  play_bgm 186
  force 2, 0, 0
  wait 16
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d108:
  lock
  sweep 2, 0, 0
  wait 8
  gimmick 1, 1, 2
  wait 15
  force 2, 0, 0
  wait 30
  message 1, 0, 0x1335
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  sweep 3, 0, 0
  wait 16
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d1a8:
  lock
  message 1, 0, 0x1338
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 16
  wait_msgbox_end
  wait 30
  release
  unlockmenu
  resume 0
  end

Script_0835d208:
  cmd1c 3, 0, 40960
  gameflag 20, 1
  destroy 0
  eventflag 0, 44, 0
  spawn 3, 0, Entity_0835bf30
  spawn 4, 0, Entity_0835bf40
  wait_screeneffect
  stop_bgm
  wait 15
  emotion 4, 0x1000, 0x00FFD800, 0
  wait 75
  play_bgm 167
  message 1, 0, 0x133C
  wait_msgbox_end
  wait 15
  entityflag 4, 0, TRUE
  wait 120
  message 1, 0, 0x133D
  wait_msgbox_end
  wait 15
  spawn 5, 0, Entity_0835bf50
  wait 105
  message 1, 0, 0x133E
  wait_msgbox_end
  message 1, 0, 0x133F
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 120
  message 1, 0, 0x1340
  wait_msgbox_end
  wait 60
  message 1, 0, 0x1341
  wait_msgbox_end
  wait 15
  message 1, 0, 0x1342
  wait_msgbox_end
  wait 15
  entityflag 4, 1, TRUE
  wait 120
  message 1, 0, 0x1343
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_screeneffect
  cmd1c 3, 0, 2621440
  destroy 3
  destroy 4
  destroy 5
  wait 30
  eventflag 1, 0, 0
  spawn 0, 0, Entity_0835bf60
  reset_camera Camera_0835bdec
  forcekeyinput 0x0000FFFF
  normal_screen
  wait 1
  release
  wait_screeneffect
  play_bgm 186
  end

Script_0835d3f0:
  spawn 0, 0, Entity_0835bf60
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_screeneffect
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_0835d438:
  eventflag 0, 45, 0
  lock
  message 1, 1, 0x1346
  message 2, 1, 0
  message 7, 0, 0
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_screeneffect
  stop_camera
  normal_screen
  wait_screeneffect
  play_bgm 223
  wait 60
  message 1, 0, 0x1347
  wait_msgbox_end
  wait 15
  normal_screen
  wait 1
  cmd06 122, 0, 0
  wait_screeneffect
  wait 15
  message 1, 0, 0x1348
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x1349
  wait_msgbox_end
  stop_bgm
  wait 60
  message 1, 0, 0x134A
  wait_msgbox_end
  play_bgm 166
  wait 15
  emotion 0, 0x0C00, 0x00FFD800, 0
  wait 75
  message 1, 0, 0x134B
  wait_msgbox_end
  wait 30
  message 1, 0, 0x134C
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  stop_camera
  cutscene 6
  normal_screen
  wait_screeneffect
  wait 15
  cutscene 7
  wait 15
  message 1, 1, 0x134D
  message 2, 1, 0
  message 1, 1, 0x134E
  message 2, 1, 0
  wait 15
  play_se 333
  screeneffect 5
  wait 15
  message 1, 1, 0x134F
  message 2, 1, 0
  wait 15
  play_se 333
  screeneffect 5
  wait 15
  message 1, 1, 0x1350
  message 2, 1, 0
  wait 15
  play_se 333
  screeneffect 5
  wait 30
  play_se 333
  screeneffect 5
  wait 30
  play_se 333
  screeneffect 5
  wait 12
  play_se 333
  screeneffect 5
  wait 12
  play_se 333
  screeneffect 5
  wait 12
  play_se 333
  screeneffect 5
  wait 15
  message 1, 1, 0x1351
  message 2, 1, 0
  message 7, 0, 0
  wait_msgbox_end
  wait 15
  screeneffect 6
  wait_screeneffect
  wait 120
  cutscene 8
  reset_camera Camera_0835bdec
  gimmick 0, 17, 0
  screeneffect 5
  wait_screeneffect
  wait 15
  message 1, 0, 0x1352
  wait_msgbox_end
  message 1, 0, 0x1353
  wait_msgbox_end
  wait 15
  spawn 3, 0, Entity_0835bf70
  wait 60
  emotion 0, 0x0C00, 0x00FFD800, 0
  wait 75
  force 3, 0, 0
  wait 15
  turn_right 0
  wait 15
  message 1, 0, 0x1354
  wait_msgbox_end
  wait 30
  message 1, 0, 0x1355
  wait_msgbox_end
  wait 15
  spawn 4, 0, Entity_0835bf80
  wait 60
  message 1, 0, 0x1356
  wait_msgbox_end
  wait 15
  force 9, 0, 100352
  wait 15
  message 1, 0, 0x1357
  wait_msgbox_end
  wait 15
  spawn 5, 0, Entity_0835bf90
  spawn 6, 0, Entity_0835bfa0
  wait 75
  message 1, 0, 0x1358
  wait_msgbox_end
  wait 30
  message 1, 0, 0x1359
  wait_msgbox_end
  wait 30
  spawn 7, 0, Entity_0835bfb0
  wait 150
  play_se 333
  entityflag 3, 0, TRUE
  entityflag 4, 0, TRUE
  entityflag 5, 0, TRUE
  entityflag 6, 0, TRUE
  screeneffect 5
  stop_bgm
  wait 90
  message 1, 0, 0x135A
  wait 30
  play_bgm 167
  wait_msgbox_end
  wait 15
  turn_left 0
  force 2, 0, 0
  wait 45
  message 1, 0, 0x135B
  wait_msgbox_end
  wait 15
  entityflag 7, 0, TRUE
  entityflag 7, 1, TRUE
  wait 210
  message 1, 0, 0x135C
  wait_msgbox_end
  wait 15
  force 3, 0, 0
  wait 15
  force 9, 0, 92160
  wait 15
  turn_left 0
  message 1, 0, 0x135D
  wait_msgbox_end
  stop_bgm
  play_se 293
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait 60
  print_message 30, 0x135E
  wait_msgbox_end
  wait 15
  print_message 20, 0x135F
  wait 15
  play_se 153
  wait 45
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait 30
  fadeout_se 60, 293
  wait 15
  goodluck 1
  wait 15
  emergency_off
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  destroy 3
  destroy 4
  destroy 5
  destroy 6
  destroy 7
  wait 60
  eventflag 1, 0, 0
  end

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

.global gResistanceBaseScriptList
gResistanceBaseScriptList:
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
  .word Script_0835c868
  .word Script_0835ca60
  .word Script_0835ccc8
  .word Script_0835cdb8
  .word Script_0835cdf0
  .word Script_0835d108
  .word Script_0835d1a8
  .word Script_0835d208
  .word Script_0835d3f0
  .word Script_0835d438
  .word Script_0835dae0
  .word Script_0835d098
