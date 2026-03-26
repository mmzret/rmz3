.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08355c70: @ 0x08355c70
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08355c9c: @ 0x08355c9c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 8160*PX, MAX_X, 0*PX, MAX_Y

Camera_08355cc8: @ 0x08355cc8
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 13504*PX, 13808*PX, 0*PX, MAX_Y

Entity_08355cf4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08355d04:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8400*PX, 1504*PX
  .4byte DIR_RIGHT

Entity_08355d14:
  .byte PLAYER, ZERO, 0, 0
  .4byte 13312*PX, 2368*PX
  .4byte DIR_RIGHT

Entity_08355d24:
  .byte PLAYER, ZERO, 0, 0
  .4byte 13552*PX, 2368*PX
  .4byte DIR_RIGHT

Entity_08355d34:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 58, 0
  .4byte 432*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08355d44:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 58, 1
  .4byte 432*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08355d54:
  .byte BOSS, 4, 1, 0
  .4byte 8280*PX, 1552*PX
  .4byte DIR_LEFT

Entity_08355d64:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 20
  .4byte 13696*PX, 2368*PX
  .4byte DIR_LEFT

Entity_08355d74:
  .byte BOSS, 16, 0, 0
  .4byte 13696*PX, 2368*PX
  .4byte DIR_LEFT

Entity_08355d84:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 59, 0
  .4byte 13632*PX, 2368*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08355d94:
  eventflag 0, 33, 0
  spawn 0, Entity_08355cf4
  spawn 3, Entity_08355d34
  reset_camera Camera_08355c70
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  emotion 3, 0x1000, 0x00FFD800, 0
  wait 75
  entityflag 3, 0, TRUE
  wait 45
  message 1, 0, 0x0E00
  wait_msgbox_end
  stop_bgm
  wait 15
  entityflag 3, 1, TRUE
  wait 30
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 181
  wait_indicator_end
  entity 3, 7, 0
  release
  resume 0
  end

Script_08355e94:
  spawn 0, Entity_08355cf4
  spawn 3, Entity_08355d44
  entity 3, 7, 0
  reset_camera Camera_08355c70
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 181
  wait_indicator_end
  release
  resume 0
  end

Script_08355f04:
  spawn 0, Entity_08355cf4
  reset_camera Camera_08355c70
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 181
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08355f5c:
  spawn 1, Entity_08355d54
  lock
  force 0, 0, 0
  force 8, 0, 0
  turn_right 0
  force 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8160*PX
  adjust_camera 12, 0 8400*PX
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  entityflag 1, 0, TRUE
  release
  play_bgm 189
  resume 1
  end

Script_08355fec:
  stop_bgm
  wait 120
  cmd08 1, 2
  destroy 1
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 12, 0 15360*PX
  play_bgm 181
  resume 1
  end

Script_0835603c:
  spawn 0, Entity_08355d04
  reset_camera Camera_08355c9c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 181
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08356094:
  spawn 0, Entity_08355d14
  reset_camera Camera_08355c70
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083560ec:
  forcekeyinput 0x0010
  pause
  eventflag 0, 34, 0
  walkto 13552*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 13504*PX
  adjust_camera 12, 0 13808*PX
  wait 75
  message 1, 0, 0x0E01
  wait_msgbox_end
  wait 15
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  spawn 3, Entity_08355d64
  wait 60
  message 1, 0, 0x0E02
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08355d74
  wait 60
  destroy 3
  triumphant_message 0, 0x0E04
  message 1, 0, 0x0E03
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 13440*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0835623c:
  spawn 1, Entity_08355d74
  forcekeyinput 0x0010
  pause
  eventflag 0, 34, 0
  walkto 13552*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 13504*PX
  adjust_camera 12, 0 13808*PX
  wait 60
  eventflag 1, 0, 0
  triumphant_message 0, 0x0E04
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 13440*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0835630c:
  spawn 1, Entity_08355d74
  spawn 0, Entity_08355d24
  reset_camera Camera_08355cc8
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0E04
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 13440*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083563ac:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0E05
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 2
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 1
  load_graphic_primitive
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 90
  prepare_missionresult
  missionresult
  destroy 0
  wait 2
  lockmenu
  end

Script_08356464:
  unlockmenu
  eventflag 0, 35, 0
  spawn 0, Entity_08355d24
  reset_camera Camera_08355cc8
  lock
  normal_screen
  wait_screeneffect
  play_bgm 167
  spawn 3, Entity_08355d84
  wait 150
  message 1, 0, 0x0E06
  wait_msgbox_end
  wait 30
  message 1, 0, 0x0E07
  wait_msgbox_end
  wait 15
  stop_bgm
  force 4, 0, 0
  wait 30
  force 5, 0, 0
  wait 60
  blackout_screen
  wait_screeneffect
  eventflag 1, 0, 0
  destroy 3
  destroy 0
  end

Script_0835653c:
  spawn 0, Entity_08355cf4
  reset_camera Camera_08355c70
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 181
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083565b4:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 13624*PX
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

.global gSnowyPlainsScriptList
gSnowyPlainsScriptList: @ 0x0835663c
  .4byte Script_08355d94
  .4byte Script_08355e94
  .4byte Script_08355f04
  .4byte Script_08355f5c
  .4byte Script_08355fec
  .4byte Script_0835603c
  .4byte Script_08356094
  .4byte Script_083560ec
  .4byte Script_0835623c
  .4byte Script_0835630c
  .4byte Script_083563ac
  .4byte Script_08356464
  .4byte Script_0835653c
  .4byte Script_083565b4

