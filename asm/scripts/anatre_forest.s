.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08353a80: @ 0x08353a80
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08353aac: @ 0x08353aac
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 7480*PX, MAX_X, 0*PX, MAX_Y

Entity_08353ad8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 608*PX
  .4byte DIR_RIGHT

Entity_08353ae8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 2752*PX, 608*PX
  .4byte DIR_RIGHT

Entity_08353af8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7312*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08353b08:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7528*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08353b18:
  .byte BOSS, BOSS_HANUMACHINE, 0, 0
  .4byte 7672*PX, 288*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08353b28:
  spawn 0, Entity_08353ad8
  reset_camera Camera_08353a80
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
  play_bgm 177
  wait_indicator_end
  release
  resume 0
  end

Script_08353bb0:
  spawn 0, Entity_08353ad8
  reset_camera Camera_08353a80
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 177
  wait_indicator_end
  release
  resume 0
  end

Script_08353c10:
  spawn 0, Entity_08353ad8
  reset_camera Camera_08353a80
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 177
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08353c68:
  spawn 0, Entity_08353ae8
  reset_camera Camera_08353a80
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 177
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08353cc0:
  spawn 0, Entity_08353af8
  reset_camera Camera_08353a80
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08353d18:
  spawn 1, Entity_08353b18
  lock
  pause
  eventflag 0, 26, 0
  walkto 7528*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7480*PX
  adjust_camera 12, 0 7760*PX
  wait 75
  triumphant_message 0, 0x0A01
  message 1, 0, 0x0A00
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7440*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_08353e00:
  spawn 1, Entity_08353b18
  lock
  pause
  eventflag 0, 26, 0
  walkto 7528*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7480*PX
  adjust_camera 12, 0 7760*PX
  wait 75
  triumphant_message 0, 0x0A01
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7440*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_08353ed8:
  spawn 0, Entity_08353b08
  spawn 1, Entity_08353b18
  entityflag 1, 0, TRUE
  reset_camera Camera_08353aac
  adjust_camera 12, 0 7760*PX
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0A01
  entityflag 1, 0, TRUE
  wait 60
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7440*PX
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08353f80:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0A02
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
  wait 60
  prepare_missionresult
  missionresult
  end

Script_08354040:
  spawn 0, Entity_08353ad8
  reset_camera Camera_08353a80
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 177
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083540b8:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 7600*PX
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

.global gAnatreForestScriptList
gAnatreForestScriptList: @ 0x08354140, len is 11
  .4byte Script_08353b28
  .4byte Script_08353bb0
  .4byte Script_08353c10
  .4byte Script_08353c68
  .4byte Script_08353cc0
  .4byte Script_08353d18
  .4byte Script_08353e00
  .4byte Script_08353ed8
  .4byte Script_08353f80
  .4byte Script_08354040
  .4byte Script_083540b8

