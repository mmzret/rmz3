.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_0835416c: @ 0x0835416c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08354198: @ 0x08354198
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 8520*PX, MAX_X, 0*PX, MAX_Y

Entity_083541c4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 768*PX
  .4byte DIR_RIGHT

Entity_083541d4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6112*PX, 928*PX
  .4byte DIR_RIGHT

Entity_083541e4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8272*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083541f4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8568*PX, 448*PX
  .4byte DIR_RIGHT

Entity_08354204:
  .byte BOSS, 17, 0, 0
  .4byte 8712*PX, 432*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08354214:
  spawn 0, Entity_083541c4
  reset_camera Camera_0835416c
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
  play_bgm 178
  wait_indicator_end
  release
  resume 0
  end

Script_0835429c:
  spawn 0, Entity_083541c4
  reset_camera Camera_0835416c
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 178
  wait_indicator_end
  release
  resume 0
  end

Script_083542fc:
  spawn 0, Entity_083541c4
  reset_camera Camera_0835416c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 178
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354354:
  spawn 0, Entity_083541d4
  reset_camera Camera_0835416c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 178
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083543ac:
  cmd1c 3, 0, 480*PX
  spawn 0, Entity_083541e4
  reset_camera Camera_0835416c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835440c:
  spawn 1, Entity_08354204
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 27, 0
  walkto 8568*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8520*PX
  wait 75
  triumphant_message 0, 0x0B01
  message 1, 0, 0x0B00
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8400*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083544e4:
  spawn 1, Entity_08354204
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 27, 0
  walkto 8568*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8520*PX
  wait 75
  triumphant_message 0, 0x0B01
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8400*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083545ac:
  cmd1c 3, 0, 480*PX
  spawn 0, Entity_083541f4
  spawn 1, Entity_08354204
  reset_camera Camera_08354198
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0B01
  entityflag 1, 0, TRUE
  stop_bgm
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 8400*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08354654:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0B02
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
  wait 90
  prepare_missionresult
  missionresult
  end

Script_08354714:
  spawn 0, Entity_083541c4
  reset_camera Camera_0835416c
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 178
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835478c:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 8640*PX
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

.global gFrostlineIceBaseScriptList
gFrostlineIceBaseScriptList: @ 0x08354814, len is 11
  .4byte Script_08354214
  .4byte Script_0835429c
  .4byte Script_083542fc
  .4byte Script_08354354
  .4byte Script_083543ac
  .4byte Script_0835440c
  .4byte Script_083544e4
  .4byte Script_083545ac
  .4byte Script_08354654
  .4byte Script_08354714
  .4byte Script_0835478c
