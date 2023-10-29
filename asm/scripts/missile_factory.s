.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08351d88: @ 0x08351d88
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08351db4: @ 0x08351db4
  .byte 6, 4, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 3760*PX, 5760*PX, 0*PX, MAX_Y

Camera_08351de0: @ 0x08351de0
  .byte 1, 8, 0, 0
  .4byte 5168*PX, 1680*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08351e0c: @ 0x08351e0c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 6832*PX, 7072*PX, 0*PX, MAX_Y

Camera_08351e38: @ 0x08351e38
  .byte 1, 8, 0, 0
  .4byte 7080*PX, 240*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Entity_08351e64:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 2048*PX
  .4byte DIR_RIGHT

Entity_08351e74:
  .byte PLAYER, ZERO, 0, 0
  .4byte 5640*PX, 1568*PX
  .4byte DIR_LEFT

Entity_08351e84:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6592*PX, 1728*PX
  .4byte DIR_RIGHT

Entity_08351e94:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6880*PX, 1728*PX
  .4byte DIR_RIGHT

Entity_08351ea4:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 23, 0
  .4byte 2064*PX, 256*PX
  .4byte DIR_LEFT

Coord_08351eb4:
  .4byte 5640*PX, 1568*PX

Entity_08351ebc:
  .byte BOSS, 6, 0, 0
  .4byte 7024*PX, 1728*PX
  .4byte DIR_LEFT

Entity_08351ecc:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 51, 0
  .4byte 7072*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351edc:
  .byte BOSS, 6, 0, 0
  .4byte 7280*PX, 224*PX
  .4byte DIR_LEFT

Entity_08351eec:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 52, 0
  .4byte 7360*PX, 224*PX
  .4byte DIR_LEFT

Entity_08351efc:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 55, 0
  .4byte 7280*PX, 240*PX
  .4byte DIR_LEFT

Entity_08351f0c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 56, 0
  .4byte 7152*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f1c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 16
  .4byte 7248*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f2c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 17
  .4byte 7288*PX, 288*PX
  .4byte DIR_LEFT

Entity_08351f3c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 18
  .4byte 7270*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f4c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 19
  .4byte 7253*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f5c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 20
  .4byte 7280*PX, 288*PX
  .4byte DIR_LEFT

Entity_08351f6c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 21
  .4byte 7266*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f7c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 22
  .4byte 7272*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f8c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 23
  .4byte 7256*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08351f9c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 24
  .4byte 7264*PX, 288*PX
  .4byte DIR_RIGHT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08351fac:
  eventflag 0, 19, 0
  spawn 0, Entity_08351e64
  reset_camera Camera_08351d88
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0800
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 175
  wait_indicator_end
  release
  resume 0
  end

Script_0835206c:
  spawn 0, Entity_08351e64
  reset_camera Camera_08351d88
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 175
  wait_indicator_end
  release
  resume 0
  end

Script_083520cc:
  spawn 0, Entity_08351e64
  reset_camera Camera_08351d88
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 175
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08352124:
  eventflag 0, 20, 0
  lock
  force 0, 0, 0
  force 8, 0, 0
  turn_right 0
  spawn 3, Entity_08351ea4
  play_se 269
  quake 0, 0, 2
  stop_bgm
  emotion 0, 16*PX, 0x00FFD800, 0
  wait 60
  message 1, 0, 0x0801
  wait_msgbox_end
  wait 15
  change_camera_mode 1
  force 1, 0, 0
  forcekeyinput DPAD_RIGHT
  wait 4
  forcekeyinput 0x00002010
  wait 28
  lock
  wait 90
  stop_se 269
  quake 2, 0, 16
  play_se 268
  quake 0, 0, 4
  gimmick 1, 0, 1
  entityflag 3, 0, TRUE
  wait 180
  stop_bgm
  blackout_screen
  wait_screeneffect
  stop_quake
  wait 60
  destroy 3
  play_bgm 168
  cmd1c 3, 0, 1600*PX
  force 13, 0, 0
  entity 0, 0, Coord_08351eb4
  turn_left 0
  reset_camera Camera_08351de0
  lock
  normal_screen
  wait 1
  change_camera_mode 1
  adjust_camera 3, 0 5640*PX
  adjust_camera 4, 0 1560*PX
  adjust_camera 1, 0, 2
  wait_screeneffect
  message 1, 0, 0x0802
  wait_msgbox_end
  message 1, 0, 0x0803
  wait_msgbox_end
  message 1, 0, 0x0804
  wait_msgbox_end
  eventflag 1, 0, 0
  wait 15
  reset_camera Camera_08351db4
  release
  resume 1
  end

Script_0835230c:
  cmd1c 3, 0, 1600*PX
  spawn 0, Entity_08351e74
  play_bgm 168
  reset_camera Camera_08351db4
  adjust_camera 1, 0, 8
  lock
  normal_screen
  wait_screeneffect
  release
  resume 0
  end

Script_08352364:
  cmd1c 3, 0, 1600*PX
  spawn 0, Entity_08351e74
  play_bgm 168
  reset_camera Camera_08351de0
  lock
  screeneffect 9
  wait 1
  change_camera_mode 1
  adjust_camera 3, 0 5640*PX
  adjust_camera 4, 0 1560*PX
  adjust_camera 1, 0, 2
  wait_screeneffect
  indicator 1, 0, 0
  wait_indicator_end
  reset_camera Camera_08351db4
  release
  resume 1
  end

Script_083523f4:
  lock
  force 0, 0, 0
  force 8, 0, 0
  turn_left 0
  gimmick 1, 0, 2
  emotion 0, 0x0800, 0x00FFD800, 0
  wait 60
  change_camera_mode 1
  adjust_camera 1, 0, 1
  scroll_speed_x 4294967040
  scroll_speed_y 128
  wait 60
  quake 2, 0, 16
  gimmick 1, 0, 3
  wait 180
  cmd1c 2, 0, 1600*PX
  cmd1c 3, 0, 10240*PX
  change_camera_mode 6
  adjust_camera 1, 0, 2
  adjust_camera 12, 0 4208*PX
  adjust_camera 14, 0 1840*PX
  wait 20
  gimmick 1, 0, 4
  wait 60
  force 1, 0, 0
  release
  resume 1
  end

Script_083524d4:
  spawn 0, Entity_08351e84
  reset_camera Camera_08351d88
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835252c:
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 21, 0
  wait 10
  spawn 1, Entity_08351ebc
  walkto 6880*PX
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 6832*PX
  adjust_camera 12, 0 7072*PX
  wait 75
  message 1, 0, 0x0805
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 1, 6, TRUE
  wait 30
  entityflag 1, 6, FALSE
  wait 15
  message 1, 0, 0x0806
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 1, 7, TRUE
  wait 30
  entityflag 1, 7, FALSE
  wait 15
  message 1, 0, 0x0807
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 1, 6, TRUE
  wait 30
  entityflag 1, 6, FALSE
  wait 15
  message 1, 0, 0x0808
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 1, 7, TRUE
  wait 30
  entityflag 1, 7, FALSE
  wait 15
  message 1, 0, 0x0809
  wait_msgbox_end
  triumphant_message 0, 0x080A
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  walkto 6952*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08352704:
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 21, 0
  wait 10
  spawn 1, Entity_08351ebc
  walkto 6880*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 6832*PX
  adjust_camera 12, 0 7072*PX
  wait 75
  triumphant_message 0, 0x080A
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  walkto 6952*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083527c4:
  spawn 0, Entity_08351e94
  spawn 1, Entity_08351ebc
  reset_camera Camera_08351e0c
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x080A
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  walkto 6952*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08352844:
  lockmenu
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  eventflag 0, 22, 0
  message 1, 0, 0x080B
  walkto 6920*PX
  turn_right 0
  wait_msgbox_end
  message 1, 0, 0x080C
  wait_msgbox_end
  wait 60
  play_se 269
  quake 0, 0, 3
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  play_se 276
  entityflag 1, 6, TRUE
  wait 30
  entityflag 1, 6, FALSE
  wait 15
  message 1, 0, 0x080D
  wait_msgbox_end
  wait 15
  quake 0, 0, 5
  play_se 277
  entityflag 1, 7, TRUE
  wait 30
  entityflag 1, 7, FALSE
  wait 15
  message 1, 0, 0x080E
  wait_msgbox_end
  change_camera_mode 1
  scroll_speed_x 0
  scroll_speed_y 0
  forcekeyinput 0x00004020
  wait 42
  lock
  wait 20
  stop_bgm
  stop_se 269
  play_se 284
  screeneffect 6
  quake 0, 0, 32
  wait_screeneffect
  quake 0, 0, 0
  wait 32
  destroy 1
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 240
  fadeout_se 120, 284
  wait 120
  eventflag 1, 0, 0
  prepare_missionresult
  missionresult
  cmd20 0, 0, 0
  destroy 0
  wait 60
  end

Script_08352a3c:
  cmd06 0, 5, 65535
  prepare_missionresult
  missionresult
  wait 60
  lockmenu
  end

Script_08352a6c:
  unlockmenu
  eventflag 0, 23, 0
  normal_screen
  wait_screeneffect
  wait 28
  time 0
  play_se 231
  message 1, 0, 0x080F
  wait_msgbox_end
  waitabs 120
  play_bgm 223
  blackout_screen
  wait_screeneffect
  spawn 3, Entity_08351ecc
  reset_camera Camera_08351e38
  normal_screen
  wait 1
  gimmick 1, 0, 0
  wait_screeneffect
  wait 30
  entityflag 3, 0, TRUE
  wait 150
  emotion 3, 0x1200, 0x00FFE000, 0
  wait 60
  spawn 4, Entity_08351edc
  wait 1
  spawn 6, Entity_08351eec
  wait 1
  spawn 7, Entity_08351efc
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0 7320*PX
  wait 90
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0810
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0811
  wait_msgbox_end
  wait 15
  entityflag 6, 0, TRUE
  wait 45
  entityflag 6, 1, TRUE
  wait 6
  play_se 269
  wait 90
  message 1, 0, 0x0812
  play_se 231
  wait_msgbox_end
  wait 16
  entityflag 6, 2, TRUE
  entityflag 7, 0, TRUE
  wait 90
  entityflag 7, 1, TRUE
  wait 30
  entityflag 6, 2, FALSE
  wait 120
  entityflag 6, 3, TRUE
  destroy 7
  wait 120
  stop_bgm
  fadeout_se 120, 269
  wait 180
  play_bgm 165
  wait 120
  message 1, 0, 0x0813
  play_se 231
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0814
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0815
  wait_msgbox_end
  wait 15
  play_se 231
  wait 90
  entityflag 6, 4, TRUE
  wait 120
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0 7216*PX
  wait 120
  spawn 5, Entity_08351f0c
  wait 30
  entityflag 6, 4, FALSE
  wait 90
  message 1, 0, 0x0816
  wait_msgbox_end
  wait 15
  entityflag 5, 0, TRUE
  wait 150
  entityflag 4, 6, TRUE
  entityflag 4, 7, TRUE
  spawn 8, Entity_08351f1c
  wait 9
  spawn 9, Entity_08351f2c
  wait 9
  spawn 10, Entity_08351f3c
  wait 9
  spawn 11, Entity_08351f4c
  wait 12
  destroy 8
  spawn 8, Entity_08351f5c
  wait 9
  destroy 9
  spawn 9, Entity_08351f6c
  wait 12
  destroy 10
  spawn 10, Entity_08351f7c
  wait 18
  destroy 11
  spawn 11, Entity_08351f8c
  wait 30
  destroy 8
  spawn 8, Entity_08351f9c
  entityflag 5, 1, TRUE
  entityflag 6, 7, TRUE
  entityflag 4, 7, FALSE
  entityflag 4, 6, FALSE
  wait 30
  entityflag 6, 6, TRUE
  wait 20
  entityflag 6, 6, TRUE
  wait 10
  entityflag 6, 6, TRUE
  wait 8
  entityflag 6, 6, TRUE
  wait 60
  entityflag 5, 2, TRUE
  destroy 9
  destroy 10
  destroy 11
  destroy 8
  wait 60
  message 1, 0, 0x0817
  wait_msgbox_end
  wait 15
  entityflag 3, 1, TRUE
  wait 60
  message 1, 0, 0x0818
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0819
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x081A
  wait_msgbox_end
  wait 15
  message 1, 0, 0x081B
  wait_msgbox_end
  wait 15
  print_message 60, 0x081C
  entityflag 5, 3, TRUE
  entityflag 3, 2, TRUE
  wait 45
  entityflag 6, 5, TRUE
  wait 30
  entityflag 6, 5, TRUE
  wait 15
  entityflag 6, 5, TRUE
  wait 30
  stop_bgm
  wait 90
  screeneffect 10
  wait_screeneffect
  stop_camera
  wait 120
  destroy 3
  destroy 4
  destroy 5
  destroy 6
  wait 60
  eventflag 1, 0, 0
  end

Script_083530cc:
  spawn 0, Entity_08351e64
  reset_camera Camera_08351d88
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 175
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08353144:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 2040*PX
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

.global gMissileFactoryScriptList
gMissileFactoryScriptList: @ 0x083531cc, len is 16
  .4byte Script_08351fac
  .4byte Script_0835206c
  .4byte Script_083520cc
  .4byte Script_08352124
  .4byte Script_0835230c
  .4byte Script_08352364
  .4byte Script_083523f4
  .4byte Script_083524d4
  .4byte Script_0835252c
  .4byte Script_08352704
  .4byte Script_083527c4
  .4byte Script_08352844
  .4byte Script_08352a3c
  .4byte Script_08352a6c
  .4byte Script_083530cc
  .4byte Script_08353144
