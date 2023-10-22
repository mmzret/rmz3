.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"

    .balign 4
    .section .rodata

Camera_0834ecfc: @ 0x0834ecfc
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Entity_0834ed28:
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 608*PX
  .4byte DIR_RIGHT

Entity_0834ed38:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7744*PX, 448*PX
  .4byte DIR_RIGHT

Entity_0834ed48:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8512*PX, 928*PX
  .4byte DIR_RIGHT

Entity_0834ed58:
  .byte PLAYER, ZERO, 0, 0
  .4byte 8992*PX, 928*PX
  .4byte DIR_RIGHT

Entity_0834ed68:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11392*PX, 448*PX
  .4byte DIR_RIGHT

Entity_0834ed78:
  .byte PLAYER, ZERO, 0, 0
  .4byte 11568*PX, 448*PX
  .4byte DIR_RIGHT

Entity_0834ed88:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4640*PX, 560*PX
  .4byte DIR_RIGHT

Entity_0834ed98:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 2
  .4byte 11712*PX, 448*PX
  .4byte DIR_LEFT

Entity_0834eda8:
  .byte BOSS, BOSS_BLAZIN, 0, 0
  .4byte 11712*PX, 448*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834edb8:
  eventflag 0, 5, 0
  spawn 0, 0, Entity_0834ed28
  reset_camera Camera_0834ecfc
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0400
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 171
  wait_indicator_end
  release
  resume 0
  end

Script_0834ee78:
  spawn 0, 0, Entity_0834ed28
  reset_camera Camera_0834ecfc
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 171
  wait_indicator_end
  release
  resume 0
  end

Script_0834eed8:
  spawn 0, 0, Entity_0834ed28
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 171
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834ef30:
  spawn 0, 0, Entity_0834ed38
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 171
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834ef88:
  spawn 0, 0, Entity_0834ed48
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 171
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834efe0:
  forcekeyinput 0x00000010
  pause
  wait 8
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  release
  play_bgm 189
  resume 1
  end

Script_0834f038:
  lock
  wait 30
  play_bgm 171
  release
  resume 1
  end

Script_0834f068:
  spawn 0, 0, Entity_0834ed58
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 171
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834f0c0:
  spawn 0, 0, Entity_0834ed68
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834f118:
  play_se 224
  spawn 3, 0, Entity_0834ed98
  forcekeyinput 0x00000010
  pause
  eventflag 0, 6, 0
  force 9, 0, 2961408
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  message 1, 0, 0x0402
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, 0, Entity_0834eda8
  wait 60
  destroy 3
  message 3, 0, 1028
  message 1, 0, 0x0403
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

Script_0834f208:
  play_se 224
  spawn 1, 0, Entity_0834eda8
  forcekeyinput 0x00000010
  pause
  eventflag 0, 6, 0
  force 9, 0, 2961408
  lock
  eventflag 1, 0, 0
  message 3, 0, 1028
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_0834f298:
  play_se 224
  spawn 0, 0, Entity_0834ed78
  spawn 1, 0, Entity_0834eda8
  reset_camera Camera_0834ecfc
  lock
  normal_screen
  wait_screeneffect
  message 3, 0, 1028
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_0834f320:
  forcekeyinput 0x0000FFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0405
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 0, 2
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 32
  fadeout_se 90, 224
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

Script_0834f3e8:
  spawn 0, 0, Entity_0834ed88
  reset_camera Camera_0834ecfc
  lock
  screeneffect 9
  play_bgm 171
  release
  resume 0
  end

Script_0834f428:
  spawn 0, 0, Entity_0834ed28
  reset_camera Camera_0834ecfc
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 171
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_0834f4a0:
  play_se 224
  forcekeyinput 0x0000FFFF
  stop_bgm
  pause
  force 9, 0, 2979840
  lock
  wait 16
  force 4, 0, 0
  wait 30
  force 5, 0, 0
  fadeout_se 120, 224
  wait 60
  blackout_screen
  wait_screeneffect
  wait 30
  destroy 0
  force 1, 0, 0
  release
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gVolcanoScriptList
gVolcanoScriptList: @ 0x0834f538
  .4byte Script_0834edb8
  .4byte Script_0834ee78
  .4byte Script_0834eed8
  .4byte Script_0834ef30
  .4byte Script_0834ef88
  .4byte Script_0834efe0
  .4byte Script_0834f038
  .4byte Script_0834f068
  .4byte Script_0834f0c0
  .4byte Script_0834f118
  .4byte Script_0834f208
  .4byte Script_0834f298
  .4byte Script_0834f320
  .4byte Script_0834f3e8
  .4byte Script_0834f428
  .4byte Script_0834f4a0

