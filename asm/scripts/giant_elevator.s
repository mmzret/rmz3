.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_083577f0: @ 0x083577f0
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0835781c: @ 0x0835781c
  .byte 1, 8, 0, 0
  .4byte 5280*PX, 3120*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Entity_08357848: @ 0x08357848
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 608*PX
  .4byte DIR_RIGHT

Entity_08357858: @ 0x08357858
  .byte PLAYER, ZERO, 0, 0
  .4byte 3552*PX, 1856*PX
  .4byte DIR_RIGHT

Entity_08357868: @ 0x08357868
  .byte PLAYER, ZERO, 0, 0
  .4byte 4432*PX, 1856*PX
  .4byte DIR_RIGHT

Entity_08357878: @ 0x08357878
  .byte PLAYER, ZERO, 0, 0
  .4byte 4912*PX, 3168*PX
  .4byte DIR_RIGHT

Entity_08357888: @ 0x08357888
  .byte PLAYER, ZERO, 0, 0
  .4byte 5208*PX, 3168*PX
  .4byte DIR_RIGHT

Entity_08357898: @ 0x08357898
  .byte BOSS, 24, 0, 0
  .4byte 3912*PX, 1712*PX
  .4byte DIR_LEFT

Entity_083578a8: @ 0x083578a8
  .byte BOSS, 10, 0, 0
  .4byte 5352*PX, 3168*PX
  .4byte DIR_LEFT

Entity_083578b8: @ 0x083578b8
  .byte BOSS, 10, 1, 0
  .4byte 5352*PX, 3168*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0_083578c8: @ 0x083578c8
  spawn 0, Entity_08357848
  reset_camera Camera_083577f0
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  wait 15
  force 6, 0, 0
  wait 15
  indicator 1, 2, 0
  wait 45
  play_bgm 183
  wait_indicator_end
  release
  resume 0
  end

Script_1_08357950: @ 0x08357950
  spawn 0, Entity_08357848
  reset_camera Camera_083577f0
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 183
  wait_indicator_end
  release
  resume 0
  end

Script_2_083579b0: @ 0x083579b0
  spawn 0, Entity_08357848
  reset_camera Camera_083577f0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 183
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_3_08357a08: @ 0x08357a08
  spawn 0, Entity_08357858
  reset_camera Camera_083577f0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 183
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_4_08357a60: @ 0x08357a60
  spawn 1, Entity_08357898
  force 8, 0, 0
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  change_camera_mode 1
  adjust_camera 1, 0, 4
  adjust_camera 3, 0 3840*PX
  wait 60
  walkto 3768*PX
  turn_right 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  release
  play_bgm 189
  resume 1
  end

Script_5_08357af8: @ 0x08357af8
  stop_bgm
  wait 120
  cmd08 1, 2
  destroy 1
  play_bgm 183
  resume 1
  end

Script_6_08357b30: @ 0x08357b30
  force 8, 0, 0
  lock
  walkto 3920*PX
  turn_right 0
  gimmick 1, 0, 9
  wait 600
  adjust_camera 12, 0 15360*PX
  release
  resume 1
  end

Script_7_08357b80: @ 0x08357b80
  spawn 0, Entity_08357868
  reset_camera Camera_083577f0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 183
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 1
  end

Script_8_08357bd8: @ 0x08357bd8
  spawn 0, Entity_08357878
  reset_camera Camera_083577f0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 1
  end

Script_9_08357c30: @ 0x08357c30
  spawn 1, Entity_083578a8
  lock
  pause
  eventflag 0, 43, 0
  walkto 5208*PX
  emotion 0, 0x1000, 0x00FFD800, 0
  change_camera_mode 1
  adjust_camera 1, 0, 4
  adjust_camera 3, 0 5312*PX
  wait 60
  entityflag 1, 0, TRUE
  wait 300
  change_camera_mode 1
  adjust_camera 1, 0, 4
  adjust_camera 3, 0 5280*PX
  wait 60
  triumphant_message 0, 0x1002
  message 1, 0, 0x1001
  wait_msgbox_end
  eventflag 1, 0, 0
  gimmick 1, 1, 1
  warning_indicator
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 2
  adjust_camera 11, 0 5064*PX
  adjust_camera 12, 0 5496*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_10_08357d40: @ 0x08357d40
  spawn 1, Entity_083578b8
  entityflag 1, 0, TRUE
  lock
  pause
  eventflag 0, 43, 0
  walkto 5208*PX
  change_camera_mode 1
  adjust_camera 1, 0, 4
  adjust_camera 3, 0 5280*PX
  wait 60
  eventflag 1, 0, 0
  triumphant_message 0, 0x1002
  gimmick 1, 1, 1
  warning_indicator
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 2
  adjust_camera 11, 0 5064*PX
  adjust_camera 12, 0 5496*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_11_08357e10: @ 0x08357e10
  spawn 0, Entity_08357888
  spawn 1, Entity_083578b8
  entityflag 1, 0, TRUE
  reset_camera Camera_0835781c
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x1002
  gimmick 1, 1, 1
  warning_indicator
  wait 120
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 2
  adjust_camera 11, 0 5064*PX
  adjust_camera 12, 0 5496*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_12_08357ec0: @ 0x08357ec0
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x1003
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 2
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
  wait 90
  prepare_missionresult
  missionresult
  end

Script_13_08357f80: @ 0x08357f80
  spawn 0, Entity_08357848
  reset_camera Camera_083577f0
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 183
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_14_08357ff8: @ 0x08357ff8
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

.global gGiantElevatorScriptList
gGiantElevatorScriptList: @ 0x08358088
  .4byte Script_0_083578c8 @ 0x083578c8
  .4byte Script_1_08357950 @ 0x08357950
  .4byte Script_2_083579b0 @ 0x083579b0
  .4byte Script_3_08357a08 @ 0x08357a08
  .4byte Script_4_08357a60 @ 0x08357a60
  .4byte Script_5_08357af8 @ 0x08357af8
  .4byte Script_6_08357b30 @ 0x08357b30
  .4byte Script_7_08357b80 @ 0x08357b80
  .4byte Script_8_08357bd8 @ 0x08357bd8
  .4byte Script_9_08357c30 @ 0x08357c30
  .4byte Script_10_08357d40 @ 0x08357d40
  .4byte Script_11_08357e10 @ 0x08357e10
  .4byte Script_12_08357ec0 @ 0x08357ec0
  .4byte Script_13_08357f80 @ 0x08357f80
  .4byte Script_14_08357ff8 @ 0x08357ff8

