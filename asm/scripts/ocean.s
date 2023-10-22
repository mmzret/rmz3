.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"

.balign 4
.section .rodata

Camera_0834f578: @ 0x0834f578
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0834f5a4: @ 0x0834f5a4
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, 480*PX

Camera_0834f5d0: @ 0x0834f5d0
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 848*PX, MAX_X, 0*PX, MAX_Y

Entity_0834f5fc:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 448*PX
  .4byte DIR_RIGHT

Entity_0834f60c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 960*PX, 448*PX
  .4byte DIR_RIGHT

Entity_0834f61c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6592*PX, 928*PX
  .4byte DIR_RIGHT

Entity_0834f62c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 6768*PX, 928*PX
  .4byte DIR_RIGHT

Entity_0834f63c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7312*PX, 928*PX
  .4byte DIR_RIGHT

Entity_0834f64c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11152*PX, 768*PX
  .4byte DIR_RIGHT

Entity_0834f65c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11328*PX, 768*PX
  .4byte DIR_RIGHT

Entity_0834f66c:
  .byte PLAYER, ZERO, 0, 0
  .4byte 2480*PX, 576*PX
  .4byte DIR_RIGHT

Entity_0834f67c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 26, 0
  .4byte 320*PX, 352*PX
  .4byte DIR_LEFT

Entity_0834f68c:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 27, 0
  .4byte 1104*PX, 480*PX
  .4byte DIR_RIGHT

Entity_0834f69c:
  .byte SOLID, 55, 0, 0
  .4byte 1184*PX, 480*PX
  .4byte DIR_LEFT

Entity_0834f6ac:
  .byte BOSS, BOSS_PANTHEON_AQUA_MOD, 0, 0
  .4byte 6840*PX, 928*PX
  .4byte DIR_LEFT

Entity_0834f6bc:
  .byte BOSS, BOSS_PANTHEON_AQUA_MOD, 1, 0
  .4byte 6840*PX, 928*PX
  .4byte DIR_LEFT

Entity_0834f6cc:
  .byte SOLID, 55, 1, 0
  .4byte 7360*PX, 480*PX
  .4byte DIR_LEFT

Entity_0834f6dc:
  .byte BOSS, BOSS_CHILDRE, 0, 0
  .4byte 11472*PX, 768*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834f6ec:
  eventflag 0, 7, 0
  spawn 0, 0, Entity_0834f5fc
  reset_camera Camera_0834f5a4
  lock
  normal_screen
  wait 1
  spawn 3, 0, Entity_0834f67c
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  destroy 3
  message 1, 0, 0x0500
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 14, 0, 2621440
  indicator 1, 2, 0
  wait 45
  play_bgm 172
  wait_indicator_end
  release
  resume 1
  end

Script_0834f7e4:
  spawn 0, 0, Entity_0834f5fc
  reset_camera Camera_0834f578
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 172
  wait_indicator_end
  release
  resume 0
  end

Script_0834f844:
  spawn 0, 0, Entity_0834f5fc
  reset_camera Camera_0834f578
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 172
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834f89c:
  eventflag 0, 8, 0
  lock
  force 0, 0, 0
  force 8, 0, 0
  force 1, 0, 0
  turn_right 0
  spawn 3, 0, Entity_0834f69c
  spawn 4, 0, Entity_0834f68c
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 233472
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  emotion 4, 0x1000, 0x00FFE400, 0
  wait 75
  entityflag 4, 0, TRUE
  wait 45
  message 1, 0, 0x0503
  wait_msgbox_end
  wait 15
  change_camera_mode 1
  adjust_camera 1, 0, 4
  adjust_camera 3, 0, 286720
  adjust_camera 4, 0, 122880
  wait 60
  entityflag 4, 0, FALSE
  entityflag 3, 0, TRUE
  wait 90
  entityflag 3, 0, FALSE
  wait 45
  destroy 4
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 217088
  wait 60
  message 1, 0, 0x0504
  wait_msgbox_end
  wait 15
  entityflag 3, 1, TRUE
  eventflag 1, 0, 0
  release
  resume 1
  end

Script_0834f9f4:
  spawn 0, 0, Entity_0834f60c
  reset_camera Camera_0834f5d0
  lock
  normal_screen
  wait_screeneffect
  spawn 3, 0, Entity_0834f69c
  play_bgm 172
  entityflag 3, 1, TRUE
  release
  resume 1
  end

Script_0834fa4c:
  spawn 0, 0, Entity_0834f60c
  reset_camera Camera_0834f5d0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 172
  indicator 1, 0, 0
  wait_indicator_end
  spawn 3, 0, Entity_0834f69c
  entityflag 3, 1, TRUE
  release
  resume 0
  end

Script_0834fab4:
  spawn 0, 0, Entity_0834f61c
  reset_camera Camera_0834f578
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 172
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834fb0c:
  destroy 3
  spawn 1, 0, Entity_0834f6ac
  stop_bgm
  pause
  eventflag 0, 9, 0
  force 9, 0, 1732608
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  play_bgm 223
  message 1, 0, 0x0508
  wait_msgbox_end
  wait 15
  entityflag 1, 1, TRUE
  wait 30
  message 1, 0, 0x0509
  wait_msgbox_end
  wait 15
  entityflag 1, 2, TRUE
  wait 300
  message 1, 0, 0x050A
  wait_msgbox_end
  wait 15
  entityflag 1, 3, TRUE
  stop_bgm
  wait 120
  play_bgm 167
  wait 190
  forcekeyinput 0x00002000
  wait 40
  lock
  wait 10
  message 1, 0, 0x050B
  wait_msgbox_end
  stop_bgm
  wait 60
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  wait 60
  release
  play_bgm 189
  resume 1
  end

Script_0834fc64:
  spawn 1, 0, Entity_0834f6bc
  stop_bgm
  pause
  eventflag 0, 9, 0
  force 9, 0, 1732608
  lock
  wait 60
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  release
  play_bgm 189
  resume 1
  end

Script_0834fccc:
  spawn 0, 0, Entity_0834f62c
  spawn 1, 0, Entity_0834f6bc
  reset_camera Camera_0834f578
  lock
  normal_screen
  wait_screeneffect
  entityflag 1, 0, TRUE
  release
  play_bgm 189
  resume 1
  end

Script_0834fd24:
  lock
  stop_bgm
  wait 120
  cmd08 1, 0, 2
  destroy 1
  spawn 3, 0, Entity_0834f6cc
  entityflag 3, 1, TRUE
  play_bgm 172
  release
  resume 1
  end

Script_0834fd7c:
  spawn 0, 0, Entity_0834f63c
  reset_camera Camera_0834f578
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 172
  indicator 1, 0, 0
  wait_indicator_end
  spawn 3, 0, Entity_0834f6cc
  entityflag 3, 1, TRUE
  release
  resume 0
  end

Script_0834fde4:
  spawn 0, 0, Entity_0834f64c
  reset_camera Camera_0834f578
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834fe3c:
  spawn 1, 0, Entity_0834f6dc
  forcekeyinput 0x00000010
  pause
  eventflag 0, 10, 0
  walkto 11328*PX
  lock
  wait 30
  message 3, 0, 0x050D
  message 1, 0, 0x050C
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_0834fee4:
  spawn 1, 0, Entity_0834f6dc
  forcekeyinput 0x00000010
  pause
  eventflag 0, 10, 0
  walkto 11328*PX
  lock
  eventflag 1, 0, 0
  message 3, 0, 0x050D
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0834ff6c:
  spawn 0, 0, Entity_0834f65c
  spawn 1, 0, Entity_0834f6dc
  reset_camera Camera_0834f578
  lock
  normal_screen
  wait_screeneffect
  message 3, 0, 0x050D
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0834ffec:
  forcekeyinput 0x0000FFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x050E
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

Script_083500ac:
  spawn 0, 0, Entity_0834f66c
  reset_camera Camera_0834f578
  lock
  screeneffect 9
  play_bgm 172
  release
  resume 0
  end

Script_083500ec:
  spawn 0, 0, Entity_0834f5fc
  reset_camera Camera_0834f578
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 172
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08350164:
  forcekeyinput 0x0000FFFF
  stop_bgm
  pause
  walkto 11400*PX
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

.global gOceanScriptList
gOceanScriptList: @ 0x083501ec
  .4byte Script_0834f6ec
  .4byte Script_0834f7e4
  .4byte Script_0834f844
  .4byte Script_0834f89c
  .4byte Script_0834f9f4
  .4byte Script_0834fa4c
  .4byte Script_0834fab4
  .4byte Script_0834fb0c
  .4byte Script_0834fc64
  .4byte Script_0834fccc
  .4byte Script_0834fd24
  .4byte Script_0834fd7c
  .4byte Script_0834fde4
  .4byte Script_0834fe3c
  .4byte Script_0834fee4
  .4byte Script_0834ff6c
  .4byte Script_0834ffec
  .4byte Script_083500ac
  .4byte Script_083500ec
  .4byte Script_08350164
