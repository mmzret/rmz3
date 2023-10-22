.include "asm/scripts/commands.inc"
.include "asm/macros.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"

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

Entity_08354898: @ 0x08354898
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 352*PX, 2528*PX
  .4byte DIR_RIGHT

Entity_083548a8: @ 0x083548a8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 2032*PX
  .4byte DIR_RIGHT

Entity_083548b8: @ 0x083548b8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548c8: @ 0x083548c8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 4192*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548d8: @ 0x083548d8
  .byte ENTITY_BOSS
  .byte BOSS_COPY_X
  .byte 0
  .byte 0
  .4byte 4336*PX, 448*PX
  .4byte DIR_LEFT

Entity_083548e8: @ 0x083548e8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 0
  .4byte 4264*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548f8: @ 0x083548f8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 1
  .4byte 4264*PX, 448*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08354908:
  spawn 0, 0, Entity_08354898
  reset_camera Camera_08354840
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
  play_bgm 179
  wait_indicator_end
  release
  resume 0
  end

Script_08354990:
  spawn 0, 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 179
  wait_indicator_end
  release
  resume 0
  end

Script_083549f0:
  spawn 0, 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 179
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354a48:
  spawn 0, 0, Entity_083548a8
  reset_camera Camera_08354840
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 179
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354aa0:
  spawn 0, 0, Entity_083548b8
  cmd1c 3, 0, 122880
  reset_camera Camera_08354840
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354b00:
  stop_bgm
  spawn 1, 0, Entity_083548d8
  forcekeyinput 0x00000010
  pause
  eventflag 0, 28, 0
  force 9, 0, 1073152
  lock
  play_bgm 164
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1060864
  adjust_camera 12, 0, 1138688
  gimmick 1, 0, 1
  wait 75
  message 3, 0, 3074
  message 1, 0, 3073
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08354c00:
  stop_bgm
  spawn 1, 0, Entity_083548d8
  forcekeyinput 0x00000010
  pause
  eventflag 0, 28, 0
  force 9, 0, 1073152
  lock
  play_bgm 164
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1060864
  adjust_camera 12, 0, 1138688
  gimmick 1, 0, 1
  wait 75
  message 3, 0, 3074
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08354cf0:
  cmd1c 3, 0, 122880
  spawn 0, 0, Entity_083548c8
  spawn 1, 0, Entity_083548d8
  reset_camera Camera_0835486c
  lock
  normal_screen
  wait 1
  gimmick 1, 0, 1
  wait_screeneffect
  message 3, 0, 3074
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08354db0:
  lockmenu
  forcekeyinput 0x0000FFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  eventflag 0, 29, 0
  time 0
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1091584
  adjust_camera 4, 0, 102400
  force 9, 0, 1073152
  wait 4
  turn_right 0
  lock
  wait 15
  waitabs 90
  play_bgm 167
  message 1, 0, 0x0C03
  wait_msgbox_end
  wait 60
  message 1, 0, 0x0C04
  wait_msgbox_end
  emotion 1, 0x0C00, 0x00FFD800, 0
  wait 60
  spawn 3, 0, Entity_083548e8
  wait 180
  message 1, 0, 0x0C05
  wait_msgbox_end
  entityflag 1, 7, TRUE
  wait 30
  message 1, 0, 0x0C06
  wait_msgbox_end
  entityflag 1, 1, TRUE
  wait 30
  message 1, 0, 0x0C07
  wait_msgbox_end
  stop_bgm
  wait 60
  entityflag 1, 2, TRUE
  play_se 48
  cmd08 1, 0, 2
  wait 120
  screeneffect 6
  wait_screeneffect
  fadeout_se 120, 317
  wait 90
  destroy 1
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 60
  eventflag 1, 0, 0
  prepare_missionresult
  missionresult
  cmd20 0, 0, 0
  destroy 0
  destroy 3
  wait 2
  end

Script_08354f98:
  cmd06 0, 5, 65535
  prepare_missionresult
  missionresult
  lockmenu
  end

Script_08354fc0:
  unlockmenu
  eventflag 0, 30, 0
  spawn 0, 0, Entity_083548c8
  spawn 3, 0, Entity_083548f8
  reset_camera Camera_0835486c
  lock
  normal_screen
  wait 1
  normal_screen
  gimmick 1, 0, 3
  wait 1
  normal_screen
  wait_screeneffect
  play_se 317
  play_bgm 167
  message 1, 0, 0x0C08
  wait_msgbox_end
  wait 60
  message 1, 0, 0x0C09
  wait_msgbox_end
  wait 15
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 75
  message 1, 0, 0x0C0A
  wait_msgbox_end
  fadeout_se 60, 317
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 120, 0, 0
  normal_screen
  wait_screeneffect
  play_bgm 166
  wait 15
  message 1, 0, 0x0C0B
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0835486c
  normal_screen
  wait_screeneffect
  play_se 317
  wait 60
  message 1, 0, 0x0C0C
  wait_msgbox_end
  stop_bgm
  wait 120
  play_bgm 167
  message 1, 0, 0x0C0D
  wait_msgbox_end
  emotion 0, 0x1000, 0x00FFD800, 1
  wait 75
  message 1, 0, 0x0C0E
  wait_msgbox_end
  wait 15
  stop_se 317
  entityflag 3, 0, TRUE
  wait 30
  entityflag 3, 1, TRUE
  wait 210
  force 2, 0, 0
  wait 60
  message 1, 0, 0x0C0F
  wait_msgbox_end
  wait 30
  force 5, 0, 0
  stop_bgm
  wait 60
  blackout_screen
  wait_screeneffect
  wait 30
  destroy 0
  destroy 3
  eventflag 1, 0, 0
  end

Script_08355230:
  spawn 0, 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 179
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083552a8:
  forcekeyinput 0x0000FFFF
  stop_bgm
  pause
  force 9, 0, 1091584
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

.global gAreaX2ScriptList
gAreaX2ScriptList: @ 0x08355330
  .word Script_08354908
  .word Script_08354990
  .word Script_083549f0
  .word Script_08354a48
  .word Script_08354aa0
  .word Script_08354b00
  .word Script_08354c00
  .word Script_08354cf0
  .word Script_08354db0
  .word Script_08354f98
  .word Script_08354fc0
  .word Script_08355230
  .word Script_083552a8
