.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_0835320c: @ 0x0835320c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08353238: @ 0x08353238
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 4176*PX, MAX_X, 0*PX, MAX_Y

Camera_08353264: @ 0x08353264
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 8400*PX, MAX_X, 0*PX, MAX_Y

Camera_08353290: @ 0x08353290
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 8640*PX, 8880*PX, 480*PX, MAX_Y

Entity_083532bc:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 608*PX
  .4byte DIR_RIGHT

Entity_083532cc:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4288*PX, 512*PX
  .4byte DIR_RIGHT

Entity_083532dc:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8512*PX, 608*PX
  .4byte DIR_RIGHT

Entity_083532ec:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8688*PX, 608*PX
  .4byte DIR_RIGHT

Entity_083532fc:
  .byte BOSS, 4, 0, 0
  .4byte 4536*PX, 608*PX
  .4byte DIR_LEFT

Entity_0835330c:
  .byte BOSS, 11, 0, 0
  .4byte 8832*PX, 608*PX
  .4byte DIR_LEFT

Entity_0835331c:
  .byte BOSS, 11, 2, 0
  .4byte 8832*PX, 608*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0835332c:
  spawn 0, Entity_083532bc
  reset_camera Camera_0835320c
  lock
  screeneffect 9
  wait 1
  visible 0, FALSE
  wait_screeneffect
  wait 15
  force 6, 0, 0
  wait 15
  indicator 1, 2, 0
  wait 45
  play_bgm 176
  wait_indicator_end
  release
  resume 0
  end

Script_083533b4:
  spawn 0, Entity_083532bc
  reset_camera Camera_0835320c
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 176
  wait_indicator_end
  release
  resume 0
  end

Script_08353414:
  spawn 0, Entity_083532bc
  reset_camera Camera_0835320c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 176
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835346c:
  spawn 1, Entity_083532fc
  lock
  force 0, 0, 0
  force 8, 0, 0
  force 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 4320*PX
  adjust_camera 12, 0 4560*PX
  adjust_camera 13, 0 480*PX
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  entityflag 1, 0, TRUE
  release
  play_bgm BGM_MIDDLE_BOSS
  resume 1
  end

Script_083534fc:
  stop_bgm
  wait 120
  cmd08 1, 0, 2
  destroy 1
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 4176*PX
  adjust_camera 12, 0 15360*PX
  adjust_camera 13, 0 0*PX
  play_bgm 176
  resume 1
  end

Script_0835355c:
  spawn 0, Entity_083532cc
  reset_camera Camera_08353238
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 176
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083535b4:
  spawn 0, Entity_083532dc
  reset_camera Camera_08353264
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 176
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835360c:
  lock
  force 0, 0, 0
  force 8, 0, 0
  eventflag 0, 25, 0
  turn_right 0
  force 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8640*PX
  adjust_camera 12, 0 8880*PX
  adjust_camera 13, 0 480*PX
  time 0
  walkto 8688*PX
  turn_right 0
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  spawn 1, Entity_0835330c
  waitabs 120
  play_bgm 161
  wait 240
  triumphant_message 0, 0x0901
  message 1, 0, 0x0900
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08353714:
  lock
  force 0, 0, 0
  force 8, 0, 0
  eventflag 0, 25, 0
  turn_right 0
  force 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8640*PX
  adjust_camera 12, 0 8880*PX
  adjust_camera 13, 0 480*PX
  time 0
  walkto 8688*PX
  turn_right 0
  lock
  spawn 1, Entity_0835330c
  waitabs 120
  play_bgm 161
  wait 240
  triumphant_message 0, 0x0901
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08353804:
  spawn 0, Entity_083532ec
  spawn 1, Entity_0835331c
  reset_camera Camera_08353290
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0901
  entityflag 1, 0, TRUE
  wait 60
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0835387c:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0902
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 0, 2
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 1
  destroy 0
  cmd20 0, 0, 0
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  stop_camera
  wait 90
  prepare_missionresult
  missionresult
  end

Script_08353944:
  spawn 0, Entity_083532bc
  reset_camera Camera_0835320c
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 176
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083539bc:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  forcekeyinput 0x0010
  wait 46
  lock
  wait 16
  force 4, 0, 0
  wait 30
  force 5, 0, 0
  wait 60
  blackout_screen
  wait_screeneffect
  wait 30
  destroy 0
  force 1, 0, 0
  release
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gTwilightDesertScriptList
gTwilightDesertScriptList: @ 0x08353a4c, len is 13
  .4byte Script_0835332c
  .4byte Script_083533b4
  .4byte Script_08353414
  .4byte Script_0835346c
  .4byte Script_083534fc
  .4byte Script_0835355c
  .4byte Script_083535b4
  .4byte Script_0835360c
  .4byte Script_08353714
  .4byte Script_08353804
  .4byte Script_0835387c
  .4byte Script_08353944
  .4byte Script_083539bc

