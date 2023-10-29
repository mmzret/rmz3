.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08355364: @ 0x08355364
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Entity_08355390:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083553a0:
  .byte PLAYER, ZERO, 0, 0
  .4byte 5392*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083553b0:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6112*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083553c0:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11152*PX, 288*PX
  .4byte DIR_RIGHT

Entity_083553d0:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11328*PX, 288*PX
  .4byte DIR_RIGHT

Entity_083553e0:
  .byte BOSS, 23, 0, 0
  .4byte 3720*PX, 720*PX
  .4byte DIR_LEFT

Entity_083553f0:
  .byte BOSS, 14, 0, 0
  .4byte 5640*PX, 400*PX
  .4byte DIR_LEFT

Entity_08355400:
  .byte BOSS, 23, 1, 0
  .4byte 8520*PX, 560*PX
  .4byte DIR_LEFT

Entity_08355410:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 21
  .4byte 11472*PX, 288*PX
  .4byte DIR_LEFT

Entity_08355420:
  .byte BOSS, 13, 0, 0
  .4byte 11472*PX, 288*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08355430:
  eventflag 0, 31, 0
  spawn 0, Entity_08355390
  reset_camera Camera_08355364
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0D00
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm BGM_ENERGY_FACTORY
  wait_indicator_end
  release
  resume 0
  end

Script_083554f0:
  spawn 0, Entity_08355390
  reset_camera Camera_08355364
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm BGM_ENERGY_FACTORY
  wait_indicator_end
  release
  resume 0
  end

Script_08355550:
  spawn 0, Entity_08355390
  reset_camera Camera_08355364
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_ENERGY_FACTORY
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083555a8:
  spawn 1, Entity_083553e0
  forcekeyinput DPAD_RIGHT
  pause
  wait 8
  lock
  force 0, 0, 0
  entityflag 1, 0, TRUE
  force 1, 0, 0
  release
  resume 1
  end

Script_08355600:
  cmd08 1, 0, 2
  play_se SE_UNK_91
  quake 2, 0, 2
  resume 1
  end

Script_08355628:
  spawn 0, Entity_083553a0
  reset_camera Camera_08355364
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_ENERGY_FACTORY
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08355680:
  spawn 1, Entity_083553f0
  forcekeyinput DPAD_RIGHT
  stop_bgm
  pause
  wait 8
  lock
  force 0, 0, 0
  entityflag 1, 0, TRUE
  wait 60
  force 1, 0, 0
  release
  play_bgm BGM_MIDDLE_BOSS
  resume 1
  end

Script_083556f0:
  stop_bgm
  wait 60
  cmd08 1, 0, 2
  play_bgm BGM_ENERGY_FACTORY
  resume 1
  end

Script_08355720:
  spawn 0, Entity_083553b0
  reset_camera Camera_08355364
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_ENERGY_FACTORY
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08355778:
  spawn 1, Entity_08355400
  forcekeyinput DPAD_RIGHT
  pause
  wait 8
  lock
  force 0, 0, 0
  entityflag 1, 0, TRUE
  force 1, 0, 0
  release
  resume 1
  end

Script_083557d0:
  cmd08 1, 0, 2
  play_se 145
  quake 2, 0, 2
  resume 1
  end

Script_083557f8:
  spawn 0, Entity_083553c0
  reset_camera Camera_08355364
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08355850:
  forcekeyinput 0x0010
  pause
  eventflag 0, 32, 0
  walkto 11328*PX
  lock
  wait 15
  message 1, 0, 0x0D01
  wait_msgbox_end
  wait 15
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  spawn 3, Entity_08355410
  wait 60
  message 1, 0, 0x0D02
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08355420
  wait 60
  destroy 3
  triumphant_message 0, 0x0D04
  message 1, 0, 0x0D03
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08355960:
  spawn 1, Entity_08355420
  pause
  eventflag 0, 43, 0
  walkto 11328*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0D04
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083559e0:
  spawn 0, Entity_083553d0
  spawn 1, Entity_08355420
  reset_camera Camera_08355364
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0D04
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_08355a60:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0D05
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

Script_08355b20:
  spawn 0, Entity_08355390
  reset_camera Camera_08355364
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 180
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08355b98:
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

.global gEnergyFacilityScriptList
gEnergyFacilityScriptList: @ 0x08355c28, len is 18
  .4byte Script_08355430
  .4byte Script_083554f0
  .4byte Script_08355550
  .4byte Script_083555a8
  .4byte Script_08355600
  .4byte Script_08355628
  .4byte Script_08355680
  .4byte Script_083556f0
  .4byte Script_08355720
  .4byte Script_08355778
  .4byte Script_083557d0
  .4byte Script_083557f8
  .4byte Script_08355850
  .4byte Script_08355960
  .4byte Script_083559e0
  .4byte Script_08355a60
  .4byte Script_08355b20
  .4byte Script_08355b98
