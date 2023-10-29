.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"
#include "constants/flag.h"

.balign 4
.section .rodata

Camera_08350b40: @ 0x08350b40
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08350b6c: @ 0x08350b6c
  .byte 1, 8, 0, 0
  .4byte 7560*PX, 240*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Entity_08350b98: @ 0x08350b98
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 768*PX
  .4byte DIR_RIGHT

Entity_08350ba8: @ 0x08350ba8
  .byte PLAYER, ZERO, 0, 0
  .4byte 3168*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08350bb8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 3472*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08350bc8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4912*PX, 1088*PX
  .4byte DIR_RIGHT

Entity_08350bd8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7312*PX, 1088*PX
  .4byte DIR_RIGHT

Entity_08350be8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7488*PX, 1088*PX
  .4byte DIR_RIGHT

Entity_08350bf8:
  .byte PLAYER, ZERO, 0, 0
  .4byte 7408*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08350c08:
  .byte PLAYER, ZERO, 0, 0
  .4byte 4912*PX, 1088*PX
  .4byte DIR_RIGHT

Entity_08350c18:
  .byte BOSS, BOSS_BABY_ELF, 3, 0
  .4byte 3280*PX, 224*PX
  .4byte DIR_LEFT

Entity_08350c28:
  .byte BOSS, BOSS_MEGAMILPA, 0, 0
  .4byte 4680*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08350c38:
  .byte BOSS, BOSS_BABY_ELF, 4, 0
  .4byte 7568*PX, 1024*PX
  .4byte DIR_LEFT

Entity_08350c48:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 3
  .4byte 7632*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08350c58:
  .byte BOSS, BOSS_DEATHTANZ, 0, 0
  .4byte 7632*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08350c68:
  .byte BOSS, BOSS_BABY_ELF, 3, 0
  .4byte 7552*PX, 224*PX
  .4byte DIR_LEFT

Entity_08350c78:
  .byte SOLID, SOLID_SCRIPT_ACTOR, 47, 0
  .4byte 7632*PX, 288*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08350c88:
  eventflag 0, 13, 0
  spawn 0, Entity_08350b98
  reset_camera Camera_08350b40
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0700
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 174
  wait_indicator_end
  release
  resume 0
  end

Script_08350d48:
  spawn 0, Entity_08350b98
  reset_camera Camera_08350b40
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 174
  wait_indicator_end
  release
  resume 0
  end

Script_08350da8:
  spawn 0, Entity_08350b98
  reset_camera Camera_08350b40
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 174
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08350e00:
  spawn 3, Entity_08350c18
  forcekeyinput DPAD_RIGHT
  pause
  eventflag 0, 14, 0
  walkto 3168*PX
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  play_bgm 169
  message 1, 0, 0x0704
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 3, 6, TRUE
  wait 30
  entityflag 3, 6, FALSE
  wait 15
  message 1, 0, 0x0705
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 3, 7, TRUE
  wait 30
  entityflag 3, 7, FALSE
  wait 15
  message 1, 0, 0x0706
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 3, 6, TRUE
  wait 30
  entityflag 3, 6, FALSE
  wait 15
  message 1, 0, 0x0707
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 3, 7, TRUE
  wait 30
  entityflag 3, 7, FALSE
  wait 15
  message 1, 0, 0x0708
  wait_msgbox_end
  entityflag 3, 1, TRUE
  wait 60
  stop_bgm
  wait 120
  play_bgm 174
  wait 30
  message 1, 0, 0x0709
  wait_msgbox_end
  message 1, 0, 0x070A
  wait_msgbox_end
  message 1, 0, 0x070B
  wait_msgbox_end
  message 1, 0, 0x070C
  wait_msgbox_end
  message 1, 0, 0x070D
  wait_msgbox_end
  message 1, 0, 0x070E
  wait_msgbox_end
  wait 15
  destroy 3
  eventflag 1, 0, 0
  release
  resume 0
  end

Script_08351020:
  spawn 0, Entity_08350ba8
  reset_camera Camera_08350b40
  lock
  normal_screen
  wait_screeneffect
  play_bgm 174
  release
  resume 0
  end

Script_08351068:
  spawn 0, Entity_08350bb8
  reset_camera Camera_08350b40
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 174
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083510c0:
  spawn 1, Entity_08350c28
  lock
  force 0, 0, 0
  force 8, 0, 0
  turn_right 0
  force 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 1167360
  adjust_camera 12, 0, 1228800
  emotion 0, 0x1000, 0x00FFD800, 0
  stop_bgm
  wait 120
  entityflag 1, 0, TRUE
  release
  play_bgm BGM_MIDDLE_BOSS
  resume 1
  end

Script_08351150:
  lock
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 0
  adjust_camera 12, 0, 3932160
  cmd08 1, 0, 2
  destroy 1
  play_bgm 174
  release
  resume 1
  end

Script_083511b8:
  spawn 0, Entity_08350bc8
  reset_camera Camera_08350b40
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 174
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08351210:
  spawn 0, Entity_08350bd8
  reset_camera Camera_08350b40
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  gameflag FLAG_2, FALSE
  resume 0
  end

Script_08351270:
  eventflag 0, 15, 0
  spawn 3, Entity_08350c48
  spawn 4, Entity_08350c38
  stop_bgm
  lock
  force 0, 0, 0
  turn_right 0
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1935360
  wait 120
  play_bgm 169
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x070F
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0710
  wait_msgbox_end
  wait 15
  message 1, 0, 0x0711
  wait_msgbox_end
  wait 15
  force 1, 0, 0
  gameflag FLAG_2, FALSE
  walkto 7488*PX
  gameflag FLAG_2, TRUE
  lock
  message 1, 0, 0x0712
  wait_msgbox_end
  wait 15
  entityflag 4, 6, TRUE
  entityflag 4, 7, TRUE
  play_se 276
  wait 25
  play_se 277
  wait 25
  play_se 276
  wait 25
  play_se 277
  wait 25
  entityflag 4, 6, FALSE
  entityflag 4, 7, FALSE
  wait 90
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0713
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0714
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0715
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0716
  wait_msgbox_end
  wait 15
  message 1, 0, 0x0717
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0718
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0719
  wait_msgbox_end
  wait 15
  entityflag 4, 1, TRUE
  wait 60
  stop_bgm
  wait 90
  play_bgm BGM_GUARDER_ROOM
  message 1, 0, 0x071A
  wait_msgbox_end
  wait 15
  destroy 4
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08350c58
  wait 60
  destroy 3
  triumphant_message 0, 0x0701
  message 1, 0, 0x071B
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 210
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 2
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083516a8:
  spawn 1, Entity_08350c58
  forcekeyinput DPAD_RIGHT
  pause
  gameflag FLAG_2, TRUE
  eventflag 0, 15, 0
  walkto 7488*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0701
  entityflag 1, 0, TRUE
  stop_bgm
  wait 210
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_08351738:
  gameflag FLAG_2, TRUE
  spawn 0, Entity_08350be8
  spawn 1, Entity_08350c58
  reset_camera Camera_08350b40
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0701
  entityflag 1, 0, TRUE
  stop_bgm
  wait 210
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_083517c0:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0702
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 0, 2
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 1
  cmd20 0, 0, 0
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 90
  prepare_missionresult
  missionresult
  destroy 0
  lockmenu
  end

Script_08351870:
  unlockmenu
  eventflag 0, 16, 0
  reset_camera Camera_08350b6c
  normal_screen
  wait 1
  spawn 3, Entity_08350c78
  spawn 4, Entity_08350c68
  wait_screeneffect
  play_bgm 166
  wait 30
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x071C
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x071D
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  message 1, 0, 0x071E
  wait_msgbox_end
  wait 30
  entityflag 4, 6, TRUE
  entityflag 4, 7, TRUE
  play_se 276
  wait 25
  play_se 277
  wait 25
  play_se 276
  wait 25
  play_se 277
  wait 25
  entityflag 4, 6, FALSE
  entityflag 4, 7, FALSE
  wait 25
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x071F
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0720
  wait_msgbox_end
  wait 15
  entityflag 3, 0, FALSE
  wait 90
  message 1, 0, 0x0721
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 4, 6, TRUE
  wait 30
  entityflag 4, 6, FALSE
  wait 15
  message 1, 0, 0x0722
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 4, 7, TRUE
  wait 30
  entityflag 4, 7, FALSE
  wait 15
  message 1, 0, 0x0723
  wait_msgbox_end
  spawn 0, Entity_08350bf8
  forcekeyinput DPAD_RIGHT
  wait 32
  pause
  wait 8
  lock
  message 1, 0, 0x0724
  wait_msgbox_end
  wait 15
  entityflag 3, 1, TRUE
  entityflag 4, 2, TRUE
  stop_bgm
  wait 150
  play_bgm 167
  message 1, 0, 0x0725
  wait_msgbox_end
  message 1, 0, 0x0726
  wait_msgbox_end
  message 1, 0, 0x0727
  wait_msgbox_end
  message 1, 0, 0x0728
  wait_msgbox_end
  stop_bgm
  force 4, 0, 0
  wait 30
  force 5, 0, 0
  wait 60
  blackout_screen
  wait_screeneffect
  eventflag 1, 0, 0
  destroy 3
  destroy 4
  destroy 0
  end

Script_08351c00:
  spawn 0, Entity_08350c08
  reset_camera Camera_08350b40
  lock
  screeneffect 9
  play_bgm 174
  release
  resume 0
  end

Script_08351c40:
  spawn 0, Entity_08350b98
  reset_camera Camera_08350b40
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 174
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08351cb8:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 7560*PX
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

.global gOldResidentialScriptList
gOldResidentialScriptList: @ 0x08351d40
  .4byte Script_08350c88
  .4byte Script_08350d48
  .4byte Script_08350da8
  .4byte Script_08350e00
  .4byte Script_08351020
  .4byte Script_08351068
  .4byte Script_083510c0
  .4byte Script_08351150
  .4byte Script_083511b8
  .4byte Script_08351210
  .4byte Script_08351270
  .4byte Script_083516a8
  .4byte Script_08351738
  .4byte Script_083517c0
  .4byte Script_08351870
  .4byte Script_08351c00
  .4byte Script_08351c40
  .4byte Script_08351cb8
