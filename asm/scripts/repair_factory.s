.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_0835023c: @ 0x0835023c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08350268: @ 0x08350268
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 7016*PX, 7312*PX, 0*PX, MAX_Y

Entity_08350294:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_083502a4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 3712*PX, 928*PX
  .4byte DIR_RIGHT

Entity_083502b4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4432*PX, 928*PX
  .4byte DIR_RIGHT

Entity_083502c4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6832*PX, 928*PX
  .4byte DIR_RIGHT

Entity_083502d4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7064*PX, 928*PX
  .4byte DIR_RIGHT

Entity_083502e4:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4512*PX, 464*PX
  .4byte DIR_RIGHT

Entity_083502f4:
  .byte BOSS, BOSS_BEE_SERVER, 0, 0
  .4byte 3960*PX, 928*PX
  .4byte DIR_LEFT

Entity_08350304:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 0
  .4byte 7208*PX, 928*PX
  .4byte DIR_LEFT

Entity_08350314:
  .byte BOSS, BOSS_HELLBAT, 0, 0
  .4byte 7208*PX, 928*PX
  .4byte DIR_LEFT

Script_08350324:
  eventflag 0, 11, 0
  spawn 0, Entity_08350294
  reset_camera Camera_0835023c
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0600
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 173
  wait_indicator_end
  release
  resume 0
  end

Script_083503e4:
  spawn 0, Entity_08350294
  reset_camera Camera_0835023c
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 173
  wait_indicator_end
  release
  resume 0
  end

Script_08350444:
  spawn 0, Entity_08350294
  reset_camera Camera_0835023c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 173
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835049c:
  spawn 0, Entity_083502a4
  reset_camera Camera_0835023c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 173
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083504f4:
  spawn 1, Entity_083502f4
  forcekeyinput DPAD_RIGHT
  pause
  wait 8
  lock
  force 0, 0, 0
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  entityflag 1, 0, TRUE
  force 1, 0, 0
  release
  play_bgm BGM_MIDDLE_BOSS
  resume 1
  end

Script_0835056c:
  lock
  stop_bgm
  wait 120
  cmd08 1, 0, 2
  destroy 1
  play_bgm 173
  release
  resume 1
  end

Script_083505b4:
  spawn 0, Entity_083502b4
  reset_camera Camera_0835023c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 173
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0835060c:
  spawn 0, Entity_083502c4
  reset_camera Camera_0835023c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08350664:
  spawn 3, Entity_08350304
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 12, 0
  walkto 7064*PX
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1796096
  adjust_camera 12, 0, 1871872
  wait 75
  message 1, 0, 0x0602
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08350314
  wait 60
  destroy 3
  triumphant_message 0, 0x0604
  message 1, 0, 0x0603
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1781760
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0835078c:
  spawn 1, Entity_08350314
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 12, 0
  walkto 7064*PX
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1796096
  adjust_camera 12, 0, 1871872
  wait 60
  eventflag 1, 0, 0
  triumphant_message 0, 0x0604
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1781760
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08350864:
  spawn 0, Entity_083502d4
  spawn 1, Entity_08350314
  reset_camera Camera_08350268
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0604
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1781760
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08350904:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0605
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

Script_083509c4:
  spawn 0, Entity_083502e4
  reset_camera Camera_0835023c
  lock
  screeneffect 9
  play_bgm 173
  release
  resume 0
  end

Script_08350a04:
  spawn 0, Entity_08350294
  reset_camera Camera_0835023c
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 173
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08350a7c:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 7136*PX
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

.global gRepairFactoryScriptList
gRepairFactoryScriptList: @ 0x08350b04
  .4byte Script_08350324
  .4byte Script_083503e4
  .4byte Script_08350444
  .4byte Script_0835049c
  .4byte Script_083504f4
  .4byte Script_0835056c
  .4byte Script_083505b4
  .4byte Script_0835060c
  .4byte Script_08350664
  .4byte Script_0835078c
  .4byte Script_08350864
  .4byte Script_08350904
  .4byte Script_083509c4
  .4byte Script_08350a04
  .4byte Script_08350a7c
