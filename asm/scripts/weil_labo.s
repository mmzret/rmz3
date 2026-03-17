.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08358e4c: @ 0x08358e4c
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358e78: @ 0x08358e78
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 416*PX, 672*PX

Camera_08358ea4: @ 0x08358ea4
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, 0*PX

Camera_08358ed0: @ 0x08358ed0
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 256*PX, 512*PX

Camera_08358efc: @ 0x08358efc
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 2880*PX, 1200*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f28: @ 0x08358f28
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 2808*PX, 1200*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f54: @ 0x08358f54
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 1768*PX, 560*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_08358f80: @ 0x08358f80
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 7440*PX, 7680*PX, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Zero_08358fac: @ 0x08358fac
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 352*PX, 448*PX
  .4byte DIR_RIGHT

Zero_08358fbc: @ 0x08358fbc
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3000*PX, 560*PX
  .4byte DIR_RIGHT

Coord_08358fcc: @ 0x08358fcc
  .4byte 3000*PX, 640*PX

Entity_08358fd4: @ 0x08358fd4
  .byte 7, 0, 0, 2
  .4byte 3056*PX, 560*PX
  .4byte DIR_LEFT

Entity_08358fe4: @ 0x08358fe4
  .byte 7, 0, 1, 2
  .4byte 2944*PX, 560*PX
  .4byte DIR_LEFT

Entity_08358ff4: @ 0x08358ff4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 3
  .4byte 432*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08359004: @ 0x08359004
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 0
  .4byte 968*PX, 1408*PX
  .4byte DIR_LEFT

Entity_08359014: @ 0x08359014
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 1
  .4byte 912*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08359024: @ 0x08359024
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 2
  .4byte 432*PX, 1408*PX
  .4byte DIR_LEFT

Entity_08359034: @ 0x08359034
  .byte BOSS, 7, 0, 0
  .4byte 432*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08359044: @ 0x08359044
  .byte BOSS, 8, 0, 0
  .4byte 968*PX, 1408*PX
  .4byte DIR_LEFT

Entity_08359054: @ 0x08359054
  .byte BOSS, 3, 0, 0
  .4byte 912*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08359064: @ 0x08359064
  .byte BOSS, 2, 0, 0
  .4byte 432*PX, 1408*PX
  .4byte DIR_LEFT

Entity_08359074: @ 0x08359074
  .byte PLAYER, ZERO, 0, 0
  .4byte 288*PX, 1072*PX
  .4byte DIR_RIGHT

Entity_08359084: @ 0x08359084
  .byte PLAYER, ZERO, 0, 0
  .4byte 824*PX, 1392*PX
  .4byte DIR_RIGHT

Entity_08359094: @ 0x08359094
  .byte PLAYER, ZERO, 0, 0
  .4byte 768*PX, 1072*PX
  .4byte DIR_RIGHT

Entity_083590a4: @ 0x083590a4
  .byte PLAYER, ZERO, 0, 0
  .4byte 288*PX, 1392*PX
  .4byte DIR_RIGHT

Entity_083590b4: @ 0x083590b4
  .byte PLAYER, ZERO, 0, 0
  .4byte 3472*PX, 560*PX
  .4byte DIR_RIGHT

Entity_083590c4: @ 0x083590c4
  .byte PLAYER, ZERO, 0, 0
  .4byte 5880*PX, 560*PX
  .4byte DIR_RIGHT

Coord_083590d4: @ 0x083590d4
  .4byte 5880*PX, 480*PX

Entity_083590dc: @ 0x083590dc
  .byte 7, 0, 0, 2
  .4byte 5936*PX, 400*PX
  .4byte DIR_LEFT

Entity_083590ec: @ 0x083590ec
  .byte 7, 0, 1, 2
  .4byte 5824*PX, 400*PX
  .4byte DIR_LEFT

Entity_083590fc: @ 0x083590fc
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 6
  .4byte 1752*PX, 1088*PX
  .4byte DIR_LEFT

Entity_0835910c: @ 0x0835910c
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 7
  .4byte 2352*PX, 1408*PX
  .4byte DIR_LEFT

Entity_0835911c: @ 0x0835911c
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 4
  .4byte 1688*PX, 1408*PX
  .4byte DIR_LEFT

Entity_0835912c: @ 0x0835912c
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 5
  .4byte 2352*PX, 928*PX
  .4byte DIR_LEFT

Entity_0835913c: @ 0x0835913c
  .byte BOSS, 10, 1, 0
  .4byte 1752*PX, 1088*PX
  .4byte DIR_LEFT

Entity_0835914c: @ 0x0835914c
  .byte BOSS, 5, 0, 0
  .4byte 2352*PX, 1408*PX
  .4byte DIR_LEFT

Entity_0835915c: @ 0x0835915c
  .byte BOSS, 16, 0, 0
  .4byte 1688*PX, 1408*PX
  .4byte DIR_LEFT

Entity_0835916c: @ 0x0835916c
  .byte BOSS, 13, 0, 0
  .4byte 2352*PX, 928*PX
  .4byte DIR_LEFT

Entity_0835917c: @ 0x0835917c
  .byte PLAYER, ZERO, 0, 0
  .4byte 1608*PX, 1072*PX
  .4byte DIR_RIGHT

Entity_0835918c: @ 0x0835918c
  .byte PLAYER, ZERO, 0, 0
  .4byte 2208*PX, 1392*PX
  .4byte DIR_RIGHT

Entity_0835919c: @ 0x0835919c
  .byte PLAYER, ZERO, 0, 0
  .4byte 1544*PX, 1392*PX
  .4byte DIR_RIGHT

Entity_083591ac: @ 0x083591ac
  .byte PLAYER, ZERO, 0, 0
  .4byte 2208*PX, 912*PX
  .4byte DIR_RIGHT

Entity_083591bc: @ 0x083591bc
  .byte PLAYER, ZERO, 0, 0
  .4byte 6112*PX, 400*PX
  .4byte DIR_RIGHT

Entity_083591cc: @ 0x083591cc
  .byte PLAYER, ZERO, 0, 0
  .4byte 7072*PX, 1408*PX
  .4byte DIR_RIGHT

Entity_083591dc: @ 0x083591dc
  .byte SOLID, SOLID_SCRIPT_ACTOR, 28, 0
  .4byte 7632*PX, 1376*PX
  .4byte DIR_LEFT

Entity_083591ec: @ 0x083591ec
  .byte SOLID, SOLID_SCRIPT_ACTOR, 29, 0
  .4byte 7644*PX, 1376*PX
  .4byte DIR_LEFT

Entity_083591fc: @ 0x083591fc
  .byte BOSS, 18, 0, 0
  .4byte 7632*PX, 1376*PX
  .4byte DIR_LEFT

Entity_0835920c: @ 0x0835920c
  .byte SOLID, SOLID_SCRIPT_ACTOR, 31, 0
  .4byte 7632*PX, 1536*PX
  .4byte DIR_LEFT

Entity_0835921c: @ 0x0835921c
  .byte PLAYER, ZERO, 0, 0
  .4byte 7488*PX, 1408*PX
  .4byte DIR_RIGHT

Entity_0835922c: @ 0x0835922c
  .byte SOLID, SOLID_SCRIPT_ACTOR, 30, 0
  .4byte 7503*PX, 1376*PX
  .4byte DIR_LEFT

Entity_0835923c: @ 0x0835923c
  .byte BOSS, 22, 0, 0
  .4byte 7632*PX, 1376*PX
  .4byte DIR_LEFT

Coord_0835924c: @ 0x0835924c
  .byte 0x0, 0xF8, 0xA, 0x0, 0x0, 0xC0, 0x3, 0x0

Entity_08359254: @ 0x08359254
  .byte SOLID, SOLID_SCRIPT_ACTOR, 32, 0
  .4byte 2952*PX, 1248*PX
  .4byte DIR_LEFT

Entity_08359264: @ 0x08359264
  .byte BOSS, 20, 0, 0
  .4byte 2952*PX, 1248*PX
  .4byte DIR_LEFT

Entity_08359274: @ 0x08359274
  .byte PLAYER, ZERO, 0, 0
  .4byte 2808*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08359284: @ 0x08359284
  .byte SOLID, SOLID_SCRIPT_ACTOR, 39, 0
  .4byte 2736*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08359294: @ 0x08359294
  .byte SOLID, SOLID_SCRIPT_ACTOR, 40, 0
  .4byte 2880*PX, 1248*PX
  .4byte DIR_LEFT

Entity_083592a4: @ 0x083592a4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 41, 0
  .4byte 2880*PX, 1264*PX
  .4byte DIR_LEFT

Entity_083592b4: @ 0x083592b4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 42, 0
  .4byte 2736*PX, 1264*PX
  .4byte DIR_RIGHT

Entity_083592c4: @ 0x083592c4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 43, 0
  .4byte 2720*PX, 1264*PX
  .4byte DIR_RIGHT

Entity_083592d4: @ 0x083592d4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 45, 0
  .4byte 2840*PX, 1264*PX
  .4byte DIR_RIGHT

Entity_083592e4: @ 0x083592e4
  .byte SOLID, SOLID_SCRIPT_ACTOR, 46, 0
  .4byte 2784*PX, 1200*PX
  .4byte DIR_LEFT

Entity_083592f4: @ 0x083592f4
  .byte PLAYER, ZERO, 0, 0
  .4byte 2790*PX+0x42, 1248*PX
  .4byte DIR_RIGHT

Entity_08359304: @ 0x08359304
  .byte SOLID, SOLID_SCRIPT_ACTOR, 33, 0
  .4byte 1800*PX, 592*PX
  .4byte DIR_LEFT

Entity_08359314: @ 0x08359314
  .byte SOLID, SOLID_SCRIPT_ACTOR, 34, 0
  .4byte 1728*PX, 592*PX
  .4byte DIR_RIGHT

Entity_08359324: @ 0x08359324
  .byte SOLID, SOLID_SCRIPT_ACTOR, 35, 0
  .4byte 1760*PX, 592*PX
  .4byte DIR_RIGHT

Entity_08359334: @ 0x08359334
  .byte SOLID, SOLID_SCRIPT_ACTOR, 36, 0
  .4byte 1832*PX, 592*PX
  .4byte DIR_LEFT

Entity_08359344: @ 0x08359344
  .byte SOLID, SOLID_SCRIPT_ACTOR, 37, 0
  .4byte 1848*PX, 592*PX
  .4byte DIR_LEFT

Entity_08359354: @ 0x08359354
  .byte SOLID, SOLID_SCRIPT_ACTOR, 37, 1
  .4byte 1704*PX, 592*PX
  .4byte DIR_RIGHT

Entity_08359364: @ 0x08359364
  .byte SOLID, SOLID_SCRIPT_ACTOR, 38, 0
  .4byte 1768*PX, 496*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0_08359374: @ 0x08359374
  spawn 0, Zero_08358fac
  reset_camera Camera_08358e4c
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
  play_bgm 185
  wait_indicator_end
  release
  resume 0
  end

Script_1_083593fc: @ 0x083593fc
  spawn 0, Zero_08358fac
  reset_camera Camera_08358e4c
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 0, 0
  wait 45
  play_bgm 185
  wait_indicator_end
  release
  resume 0
  end

Script_2_0835945c: @ 0x0835945c
  spawn 0, Zero_08358fac
  reset_camera Camera_08358e4c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 185
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_3_083594b4: @ 0x083594b4
  spawn 0, Zero_08358fbc
  reset_camera Camera_08358e78
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 185
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_4_0835950c: @ 0x0835950c
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  message 6, 0, 0
  message 5, 1, 0
  wait_msgbox_end
  message 6, 1, 0
  entityflag 1, 7, TRUE
  cmd08 1, 2
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 1
  stop_camera
  cmd06 0, 5, 65535
  blackout_screen
  wait_screeneffect
  cmd06 0, 5, 0
  entity 0, 0, Coord_08358fcc
  turn_right 0
  resume_camera
  change_camera_mode 6
  adjust_camera 11, 0 0*PX
  adjust_camera 12, 0 15360*PX
  adjust_camera 13, 0 416*PX
  adjust_camera 14, 0 672*PX
  adjust_camera 15, 0, 0
  normal_screen
  wait 1
  force 6, 0, 0
  wait 1
  spawn 6, Entity_08358fd4
  entity 6, 7, 0
  spawn 6, Entity_08358fe4
  entity 6, 7, 0
  wait_screeneffect
  cmd20 0, 0, 0
  play_bgm 185
  release
  end

Script_5_08359674: @ 0x08359674
  stop_bgm
  lock
  pause
  eventflag 0, 49, 0
  change_camera_mode 1
  adjust_camera 3, 0 360*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_08358ff4
  play_bgm 161
  wait 60
  triumphant_message 0, 0x120B
  triumphant_message 1, 0x120C
  message 1, 0, 0x120A
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08359034
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 210
  change_camera_mode 3
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_6_08359784: @ 0x08359784
  spawn 0, Entity_08359074
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 360*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_08359034
  play_bgm 161
  wait 60
  triumphant_message 0, 0x120B
  triumphant_message 1, 0x120C
  entityflag 1, 0, TRUE
  stop_bgm
  wait 210
  change_camera_mode 3
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_7_0835985c: @ 0x0835985c
  stop_bgm
  lock
  pause
  eventflag 0, 50, 0
  change_camera_mode 1
  adjust_camera 3, 0 896*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_08359004
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1208
  triumphant_message 1, 0x1209
  message 1, 0, 0x1207
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08359044
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 12, 0 1072*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_8_08359984: @ 0x08359984
  spawn 0, Entity_08359084
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 896*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_08359044
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1208
  triumphant_message 1, 0x1209
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 12, 0 1072*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_9_08359a74: @ 0x08359a74
  stop_bgm
  lock
  pause
  eventflag 0, 51, 0
  change_camera_mode 1
  adjust_camera 3, 0 840*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_08359014
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1205
  triumphant_message 1, 0x1206
  message 1, 0, 0x1204
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08359054
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_10_08359b84: @ 0x08359b84
  spawn 0, Entity_08359094
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 840*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_08359054
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1205
  triumphant_message 1, 0x1206
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_11_08359c5c: @ 0x08359c5c
  stop_bgm
  lock
  pause
  eventflag 0, 52, 0
  change_camera_mode 1
  adjust_camera 3, 0 360*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_08359024
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1202
  triumphant_message 1, 0x1203
  message 1, 0, 0x1201
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08359064
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_12_08359d6c: @ 0x08359d6c
  spawn 0, Entity_083590a4
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 360*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_08359064
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1202
  triumphant_message 1, 0x1203
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_13_08359e44: @ 0x08359e44
  spawn 0, Entity_083590b4
  reset_camera Camera_08358e4c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 185
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_14_08359e9c: @ 0x08359e9c
  spawn 0, Entity_083590c4
  reset_camera Camera_08358ed0
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 185
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_15_08359ef4: @ 0x08359ef4
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  message 6, 0, 0
  message 5, 1, 0
  wait_msgbox_end
  message 6, 1, 0
  entityflag 1, 7, TRUE
  cmd08 1, 2
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 32
  adjust_camera 13, 0 0*PX
  adjust_camera 12, 0 15360*PX
  destroy 1
  stop_camera
  cmd06 0, 5, 65535
  blackout_screen
  wait_screeneffect
  cmd06 0, 5, 0
  entity 0, 0, Coord_083590d4
  turn_right 0
  resume_camera
  change_camera_mode 6
  adjust_camera 11, 0 0*PX
  adjust_camera 12, 0 15360*PX
  adjust_camera 13, 0 256*PX
  adjust_camera 14, 0 512*PX
  adjust_camera 15, 0, 0
  normal_screen
  wait 1
  force 6, 0, 0
  wait 1
  spawn 6, Entity_083590dc
  entity 6, 7, 0
  spawn 6, Entity_083590ec
  entity 6, 7, 0
  wait_screeneffect
  cmd20 0, 0, 0
  play_bgm 185
  release
  end

Script_16_0835a06c: @ 0x0835a06c
  stop_bgm
  lock
  pause
  eventflag 0, 53, 0
  change_camera_mode 1
  adjust_camera 3, 0 1680*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_083590fc
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1217
  triumphant_message 1, 0x1218
  message 1, 0, 0x1216
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_0835913c
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  change_camera_mode 6
  adjust_camera 11, 0 1464*PX
  adjust_camera 12, 0 1896*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_17_0835a19c: @ 0x0835a19c
  spawn 0, Entity_0835917c
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 1680*PX
  adjust_camera 4, 0 1040*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_0835913c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1217
  triumphant_message 1, 0x1218
  entityflag 1, 0, TRUE
  stop_bgm
  wait 60
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 11, 0 1464*PX
  adjust_camera 12, 0 1896*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_18_0835a294: @ 0x0835a294
  stop_bgm
  lock
  pause
  eventflag 0, 54, 0
  change_camera_mode 1
  adjust_camera 3, 0 2280*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_0835910c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1214
  triumphant_message 1, 0x1215
  message 1, 0, 0x1213
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_0835914c
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 13, 0 1248*PX
  adjust_camera 14, 0 10240*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_19_0835a3b4: @ 0x0835a3b4
  spawn 0, Entity_0835918c
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 2280*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_0835914c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1214
  triumphant_message 1, 0x1215
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 13, 0 1248*PX
  adjust_camera 14, 0 10240*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_20_0835a49c: @ 0x0835a49c
  stop_bgm
  lock
  pause
  eventflag 0, 55, 0
  change_camera_mode 1
  adjust_camera 3, 0 1616*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_0835911c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1211
  triumphant_message 1, 0x1212
  message 1, 0, 0x1210
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_0835915c
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 12, 0 1792*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_21_0835a5c4: @ 0x0835a5c4
  spawn 0, Entity_0835919c
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 1616*PX
  adjust_camera 4, 0 1360*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_0835915c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x1211
  triumphant_message 1, 0x1212
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 12, 0 1792*PX
  adjust_camera 13, 0 0*PX
  adjust_camera 14, 0 9600*PX
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_22_0835a6b4: @ 0x0835a6b4
  stop_bgm
  lock
  pause
  eventflag 0, 56, 0
  change_camera_mode 1
  adjust_camera 3, 0 2280*PX
  adjust_camera 4, 0 880*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 3, Entity_0835912c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x120E
  triumphant_message 1, 0x120F
  message 1, 0, 0x120D
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_0835916c
  wait 60
  destroy 3
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_23_0835a7c4: @ 0x0835a7c4
  spawn 0, Entity_083591ac
  stop_bgm
  lock
  pause
  reset_camera Camera_08358ea4
  change_camera_mode 1
  adjust_camera 3, 0 2280*PX
  adjust_camera 4, 0 880*PX
  adjust_camera 15, 0, 0
  wait 1
  spawn 1, Entity_0835916c
  play_bgm 161
  wait 60
  triumphant_message 0, 0x120E
  triumphant_message 1, 0x120F
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 3
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_24_0835a89c: @ 0x0835a89c
  spawn 0, Entity_083591bc
  reset_camera Camera_08358e4c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 185
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_25_0835a8f4: @ 0x0835a8f4
  spawn 0, Entity_083591cc
  reset_camera Camera_08358e4c
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_26_0835a94c: @ 0x0835a94c
  gimmick 1, 1, 0
  lock
  pause
  eventflag 0, 57, 0
  walkto 7488*PX
  lock
  stop_bgm
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7440*PX
  wait 60
  gimmick 1, 3, 1
  play_se 298
  wait 90
  play_bgm 166
  wait 60
  message 1, 0, 0x1219
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 123, 0, 0
  normal_screen
  wait_screeneffect
  message 1, 0, 0x121A
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  resume_camera
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x121B
  wait_msgbox_end
  stop_bgm
  wait 15
  spawn 3, Entity_083591dc
  wait 48
  spawn 1, Entity_083591fc
  wait 60
  play_bgm 165
  destroy 3
  wait 15
  message 1, 0, 0x121C
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 187
  resume 1
  end

Script_27_0835ab0c: @ 0x0835ab0c
  gimmick 1, 1, 0
  gimmick 1, 3, 1
  forcekeyinput 0x0010
  pause
  eventflag 0, 57, 0
  wait 30
  spawn 1, Entity_083591fc
  walkto 7488*PX
  lock
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0 7440*PX
  wait 60
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 187
  resume 1
  end

Script_28_0835abc4: @ 0x0835abc4
  spawn 0, Entity_0835921c
  reset_camera Camera_08358f80
  lock
  normal_screen
  wait 1
  gimmick 1, 3, 1
  spawn 1, Entity_083591fc
  wait_screeneffect
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 187
  resume 1
  end

Script_29_0835ac4c: @ 0x0835ac4c
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  time 0
  force 8, 0, 0
  eventflag 0, 58, 0
  walkto 7488*PX
  turn_right 0
  lock
  waitabs 120
  play_bgm 167
  message 1, 0, 0x121D
  wait_msgbox_end
  entityflag 1, 7, TRUE
  wait 15
  play_se 285
  play_se 269
  spawn 3, Entity_083591ec
  gimmick 1, 3, 2
  wait 15
  wait 60
  message 1, 0, 0x121E
  wait_msgbox_end
  wait 15
  cmd08 1, 2
  spawn 4, Entity_0835920c
  wait 64
  screeneffect 6
  wait_screeneffect
  destroy 3
  stop_bgm
  wait 30
  destroy 4
  destroy 1
  wait 2
  spawn 3, Entity_0835922c
  cmd20 0, 0, 0
  eventflag 1, 0, 0
  gimmick 1, 0, 1
  gimmick 1, 1, 0
  spawn 1, Entity_0835923c
  screeneffect 5
  wait_screeneffect
  play_bgm 192
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  resume 1
  end

Script_30_0835adf4: @ 0x0835adf4
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  time 0
  force 8, 0, 0
  eventflag 0, 58, 0
  walkto 7488*PX
  turn_right 0
  lock
  waitabs 120
  play_bgm 167
  entityflag 1, 7, TRUE
  wait 15
  play_se 285
  play_se 269
  spawn 3, Entity_083591ec
  gimmick 1, 3, 2
  wait 15
  cmd08 1, 2
  spawn 4, Entity_0835920c
  wait 64
  screeneffect 6
  wait_screeneffect
  destroy 3
  stop_bgm
  wait 30
  destroy 4
  destroy 1
  wait 2
  spawn 3, Entity_0835922c
  cmd20 0, 0, 0
  eventflag 1, 0, 0
  gimmick 1, 0, 1
  gimmick 1, 1, 0
  spawn 1, Entity_0835923c
  screeneffect 5
  wait_screeneffect
  play_bgm 192
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  resume 1
  end

Script_31_0835af6c: @ 0x0835af6c
  screeneffect 5
  wait 1
  spawn 0, Entity_0835921c
  reset_camera Camera_08358f80
  lock
  screeneffect 5
  wait 1
  gimmick 1, 3, 2
  gimmick 1, 0, 1
  gimmick 1, 1, 0
  play_se 269
  spawn 1, Entity_0835923c
  spawn 3, Entity_0835922c
  wait_screeneffect
  play_bgm 192
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  resume 1
  end

Script_32_0835b024: @ 0x0835b024
  force 8, 0, 0
  eventflag 0, 59, 0
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  walkto 7488*PX
  turn_right 0
  entityflag 1, 7, TRUE
  wait 60
  stop_se 269
  play_se 284
  cmd08 1, 2
  entityflag 3, 0, TRUE
  wait 240
  screeneffect 6
  wait_screeneffect
  entityflag 3, 1, TRUE
  destroy 1
  cmd20 0, 0, 0
  wait 120
  reset_camera Camera_08358efc
  screeneffect 5
  wait_screeneffect
  play_bgm 193
  wait 30
  destroy 3
  entity 0, 0, Coord_0835924c
  turn_right 0
  force 13, 0, 0
  wait 120
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 75
  message 1, 0, 0x121F
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 124, 6, 0
  normal_screen
  wait_screeneffect
  wait 180
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_08358efc
  normal_screen
  wait_screeneffect
  wait 15
  force 2, 0, 0
  wait 45
  message 1, 0, 0x1220
  wait_msgbox_end
  wait 90
  message 1, 0, 0x1221
  wait_msgbox_end
  wait 15
  emotion 0, 0x0C00, 0x00FFD800, 0
  stop_bgm
  wait 120
  play_se 283
  spawn 3, Entity_08359254
  wait 64
  screeneffect 6
  wait_screeneffect
  wait 64
  destroy 3
  stop_camera
  cutscene 3
  play_bgm 194
  screeneffect 5
  cutscene 4
  cutscene 5
  gimmick 0, 16, 0
  reset_camera Camera_08358efc
  screeneffect 5
  wait 1
  spawn 1, Entity_08359264
  gimmick 1, 3, 100
  wait_screeneffect
  message 1, 0, 0x1223
  wait_msgbox_end
  wait 15
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  force 3, 0, 0
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 195
  resume 1
  end

Script_33_0835b33c: @ 0x0835b33c
  force 8, 0, 0
  eventflag 0, 59, 0
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  walkto 7488*PX
  turn_right 0
  entityflag 1, 7, TRUE
  wait 60
  stop_se 269
  play_se 284
  cmd08 1, 2
  entityflag 3, 0, TRUE
  wait 240
  screeneffect 6
  wait_screeneffect
  entityflag 3, 1, TRUE
  destroy 1
  cmd20 0, 0, 0
  wait 120
  reset_camera Camera_08358efc
  screeneffect 5
  wait 1
  gimmick 1, 3, 100
  spawn 1, Entity_08359264
  destroy 3
  entity 0, 0, Coord_0835924c
  turn_right 0
  force 13, 0, 0
  wait_screeneffect
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  force 3, 0, 0
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 195
  resume 1
  end

Script_34_0835b4b4: @ 0x0835b4b4
  spawn 0, Entity_08359274
  spawn 1, Entity_08359264
  reset_camera Camera_08358efc
  lock
  normal_screen
  wait 1
  gimmick 1, 3, 100
  wait_screeneffect
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  wait 90
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 1, 0, 4
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 195
  resume 1
  end

Script_35_0835b55c: @ 0x0835b55c
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  entityflag 1, 7, TRUE
  cmd08 1, 2
  wait 8
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 0
  destroy 1
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 90
  prepare_missionresult
  missionresult
  cmd20 0, 0, 0
  lockmenu
  end

Script_36_0835b60c: @ 0x0835b60c
  wait 15
  eventflag 0, 60, 0
  spawn 3, Entity_08359284
  spawn 4, Entity_08359294
  reset_camera Camera_08358f28
  lock
  normal_screen
  wait 1
  gimmick 1, 3, 100
  wait_screeneffect
  play_bgm 223
  wait 60
  emotion 3, 0x1000, 0x00FFD800, 0
  wait 75
  entityflag 4, 0, TRUE
  wait 60
  spawn 5, Entity_083592a4
  wait 60
  entityflag 4, 0, FALSE
  wait 120
  entityflag 5, 0, TRUE
  wait 90
  message 1, 0, 0x1224
  wait_msgbox_end
  wait 24
  entityflag 3, 0, TRUE
  wait 32
  entityflag 4, 1, TRUE
  wait 120
  message 1, 0, 0x1225
  wait_msgbox_end
  wait 90
  entityflag 4, 2, TRUE
  wait 90
  spawn 6, Entity_083592b4
  wait 180
  entityflag 4, 3, TRUE
  wait 30
  entityflag 4, 3, FALSE
  wait 90
  message 1, 0, 0x1226
  wait_msgbox_end
  wait 15
  spawn 7, Entity_083592c4
  wait 135
  message 1, 0, 0x1227
  wait_msgbox_end
  wait 15
  spawn 8, Entity_083592d4
  wait 160
  entityflag 4, 3, TRUE
  entityflag 4, 4, TRUE
  wait 120
  message 1, 0, 0x1228
  wait_msgbox_end
  entityflag 5, 1, TRUE
  wait 15
  message 1, 0, 0x1229
  wait_msgbox_end
  wait 15
  entityflag 5, 2, TRUE
  wait 75
  message 1, 0, 0x122A
  wait_msgbox_end
  wait 15
  spawn 9, Entity_083592e4
  wait 120
  message 1, 0, 0x122B
  wait_msgbox_end
  wait 30
  entityflag 3, 1, TRUE
  wait 3
  force 12, 0, 0
  spawn 0, Entity_083592f4
  wait 1
  destroy 3
  wait 30
  message 1, 0, 0x122C
  wait_msgbox_end
  stop_bgm
  wait 15
  change_camera_mode 6
  adjust_camera 2, 0, 0
  adjust_camera 11, 0 2688*PX
  adjust_camera 12, 0 2928*PX
  eventflag 1, 0, 0
  release
  lockmenu
  resume 1
  end

Script_37_0835b8dc: @ 0x0835b8dc
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  cmd08 1, 2
  wait 8
  screeneffect 6
  wait_screeneffect
  wait 32
  cmd20 0, 0, 0
  destroy 0
  destroy 4
  destroy 5
  destroy 6
  destroy 7
  destroy 8
  destroy 9
  wait 300
  lockmenu
  end

Script_38_0835b97c: @ 0x0835b97c
  eventflag 0, 61, 0
  cmd06 0, 5, 65535
  gimmick 0, 17, 0
  spawn 3, Entity_08359304
  reset_camera Camera_08358f54
  screeneffect 5
  wait_screeneffect
  play_se 316
  wait 210
  wait 60
  play_bgm 196
  wait 60
  play_se 317
  spawn 4, Entity_08359314
  entityflag 3, 0, TRUE
  screeneffect 5
  wait_screeneffect
  wait 30
  message 1, 0, 0x122E
  wait_msgbox_end
  wait 30
  fadeout_se 120, 317
  screeneffect 6
  wait_screeneffect
  wait 120
  entityflag 3, 1, TRUE
  destroy 4
  spawn 4, Entity_08359324
  cmd0f 4, 3, 0
  spawn 5, Entity_08359334
  spawn 6, Entity_08359344
  spawn 7, Entity_08359354
  play_se 316
  wait 120
  screeneffect 5
  wait_screeneffect
  wait 60
  message 1, 0, 0x122F
  wait_msgbox_end
  wait 120
  entityflag 3, 2, TRUE
  wait 120
  message 1, 0, 0x1230
  wait_msgbox_end
  wait 15
  entityflag 7, 0, TRUE
  wait 30
  message 1, 0, 0x1231
  wait_msgbox_end
  wait 15
  entityflag 3, 3, TRUE
  wait 60
  message 1, 0, 0x1232
  wait_msgbox_end
  wait 60
  message 1, 0, 0x1233
  wait_msgbox_end
  wait 15
  emotion 3, 0x0C00, 0x00FFD800, 0
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 4, 0 536*PX
  wait 75
  entityflag 4, 0, TRUE
  wait 60
  spawn 8, Entity_08359364
  wait 300
  message 1, 0, 0x1234
  wait_msgbox_end
  wait 15
  entityflag 8, 0, TRUE
  wait 300
  message 1, 0, 0x1235
  wait_msgbox_end
  wait 15
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 4, 0 560*PX
  wait 120
  destroy 8
  entityflag 4, 1, TRUE
  wait 180
  message 1, 0, 0x1236
  wait_msgbox_end
  wait 15
  entityflag 4, 2, TRUE
  wait 120
  entityflag 3, 4, TRUE
  wait 210
  entityflag 3, 5, TRUE
  wait 90
  message 1, 0, 0x1237
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 127, 0, 0
  normal_screen
  wait_screeneffect
  wait 60
  print_message 90, 0x1238
  wait_msgbox_end
  stop_bgm
  wait 60
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  eventflag 1, 0, 0
  end

Script_39_0835bce4: @ 0x0835bce4
  eventflag 0, 62, 0
  cmd06 0, 5, 0
  normal_screen
  wait_screeneffect
  play_bgm 197
  wait 120
  scroll 0, 0, 0
  scroll 2, 550, 2528
  stop_bgm
  blackout_screen
  wait 90
  eventflag 1, 0, 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gWeilLaboScriptList
gWeilLaboScriptList: @ 0x0835bd4c
  .4byte Script_0_08359374 @ 0x08359374
  .4byte Script_1_083593fc @ 0x083593fc
  .4byte Script_2_0835945c @ 0x0835945c
  .4byte Script_3_083594b4 @ 0x083594b4
  .4byte Script_4_0835950c @ 0x0835950c
  .4byte Script_5_08359674 @ 0x08359674
  .4byte Script_6_08359784 @ 0x08359784
  .4byte Script_7_0835985c @ 0x0835985c
  .4byte Script_8_08359984 @ 0x08359984
  .4byte Script_9_08359a74 @ 0x08359a74
  .4byte Script_10_08359b84 @ 0x08359b84
  .4byte Script_11_08359c5c @ 0x08359c5c
  .4byte Script_12_08359d6c @ 0x08359d6c
  .4byte Script_13_08359e44 @ 0x08359e44
  .4byte Script_14_08359e9c @ 0x08359e9c
  .4byte Script_15_08359ef4 @ 0x08359ef4
  .4byte Script_16_0835a06c @ 0x0835a06c
  .4byte Script_17_0835a19c @ 0x0835a19c
  .4byte Script_18_0835a294 @ 0x0835a294
  .4byte Script_19_0835a3b4 @ 0x0835a3b4
  .4byte Script_20_0835a49c @ 0x0835a49c
  .4byte Script_21_0835a5c4 @ 0x0835a5c4
  .4byte Script_22_0835a6b4 @ 0x0835a6b4
  .4byte Script_23_0835a7c4 @ 0x0835a7c4
  .4byte Script_24_0835a89c @ 0x0835a89c
  .4byte Script_25_0835a8f4 @ 0x0835a8f4
  .4byte Script_26_0835a94c @ 0x0835a94c
  .4byte Script_27_0835ab0c @ 0x0835ab0c
  .4byte Script_28_0835abc4 @ 0x0835abc4
  .4byte Script_29_0835ac4c @ 0x0835ac4c
  .4byte Script_30_0835adf4 @ 0x0835adf4
  .4byte Script_31_0835af6c @ 0x0835af6c
  .4byte Script_32_0835b024 @ 0x0835b024
  .4byte Script_33_0835b33c @ 0x0835b33c
  .4byte Script_34_0835b4b4 @ 0x0835b4b4
  .4byte Script_35_0835b55c @ 0x0835b55c
  .4byte Script_36_0835b60c @ 0x0835b60c
  .4byte Script_37_0835b8dc @ 0x0835b8dc
  .4byte Script_38_0835b97c @ 0x0835b97c
  .4byte Script_39_0835bce4 @ 0x0835bce4

