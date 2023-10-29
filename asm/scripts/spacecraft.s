.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"
#include "constants/flag.h"

  .balign 4
  .section .rodata

Camera_0834d268: @ 0x0834d268
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 1200*PX, MAX_X, 0*PX, MAX_Y

Camera_0834d294: @ 0x0834d294
  .byte 1, 9, 0, 0
  .4byte 0x7800,  0x5F000
  .4byte 0x0,     0xC0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0834d2c0: @ 0x0834d2c0
  .byte 1, 8, 0, 0
  .4byte 1096*PX, 1680*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0834d2ec: @ 0x0834d2ec
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 3152*PX, MAX_X, 0*PX, 1440*PX

Camera_0834d318: @ 0x0834d318
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 3360*PX, MAX_X, 0*PX, MAX_Y

Camera_0834d344: @ 0x0834d344
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 3944*PX, 4184*PX, 0*PX, MAX_Y

Entity_SpaceCraftIntroZero: @ 0x0834d370
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_ZERO_WALK, 0
  .4byte 0xFFFFE000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_SpaceCraftIntroCiel: @ 0x0834d380
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_CIEL_WALK, 0
  .4byte 0xFFFFB000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d390: @ 0x0834d390
  .byte SOLID, SOLID_SCRIPT_ACTOR, 3, 0
  .4byte 0xFFFFD000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3a0: @ 0x0834d3a0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 3, 1
  .4byte 0xFFFF8000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3b0: @ 0x0834d3b0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 4, 0
  .4byte 0x47000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3c0: @ 0x0834d3c0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 5, 0
  .4byte 0x42000, 0x6C000
  .4byte DIR_LEFT

EntityTemplate_0834d3d0: @ 0x0834d3d0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 5, 1
  .4byte 0x45000, 0x6C000
  .4byte DIR_RIGHT

Entity_0834d3e0: @ 0x0834d3e0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 7, 1
  .4byte 0x3B000, 0x6C000
  .4byte DIR_RIGHT

Entity_0834d3f0: @ 0x0834d3f0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 6, 0
  .4byte 0xCF000, 0x57000
  .4byte DIR_LEFT

@ オメガと四天王の戦闘に巻き込まれて死ぬパンテオン3匹(0)
Entity_PantheonOmegaCrash0: @ 0x0834d400
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_CRASHED_PANTHEON, 0
  .4byte 3936*PX, 288*PX
  .4byte DIR_RIGHT

Entity_PantheonOmegaCrash1:
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_CRASHED_PANTHEON, 1
  .4byte 0xF7000, 288*PX
  .4byte DIR_RIGHT

Entity_PantheonOmegaCrash2:
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_CRASHED_PANTHEON, 1
  .4byte 0xF9000, 288*PX
  .4byte DIR_RIGHT

Entity_0834d430: @ 0x0834d430
  .byte SOLID, SOLID_SCRIPT_ACTOR, 10, 0
  .4byte 0xFB000, 0xF000
  .4byte DIR_LEFT

Entity_0834d440: @ 0x0834d440
  .byte SOLID, SOLID_SCRIPT_ACTOR, 11, 0
  .4byte 0xFB000, 0xF000
  .4byte DIR_LEFT

Entity_0834d450: @ 0x0834d450
  .byte SOLID, SOLID_SCRIPT_ACTOR, 12, 0
  .4byte 0xFB000, 0x13000
  .4byte DIR_RIGHT

Entity_0834d460: @ 0x0834d460
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 0
  .4byte 0x101000, 288*PX
  .4byte DIR_RIGHT

Entity_0834d470: @ 0x0834d470
  .byte SOLID, SOLID_SCRIPT_ACTOR, 17, 1
  .4byte 0x103800, 288*PX
  .4byte DIR_LEFT

Entity_0834d480: @ 0x0834d480
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 2
  .4byte 0x102600, 288*PX
  .4byte DIR_RIGHT

Entity_0834d490: @ 0x0834d490
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 3
  .4byte 0x101500, 288*PX
  .4byte DIR_RIGHT

Entity_0834d4a0: @ 0x0834d4a0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 4
  .4byte 0x103000, 288*PX
  .4byte DIR_LEFT

Entity_0834d4b0: @ 0x0834d4b0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 5
  .4byte 0x102200, 288*PX
  .4byte DIR_RIGHT

Entity_0834d4c0: @ 0x0834d4c0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 6
  .4byte 0x102800, 288*PX
  .4byte DIR_RIGHT

Entity_0834d4d0: @ 0x0834d4d0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 7
  .4byte 0x101800, 288*PX
  .4byte DIR_RIGHT

Entity_0834d4e0: @ 0x0834d4e0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 8
  .4byte 0x102000, 288*PX
  .4byte DIR_RIGHT

Entity_0834d4f0: @ 0x0834d4f0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 18
  .byte 0
  .4byte 0xFD000, 288*PX
  .4byte DIR_RIGHT

Entity_0834d500: @ 0x0834d500
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 19
  .byte 0
  .4byte 0x104000, 0xE000
  .4byte DIR_LEFT

Entity_0834d510: @ 0x0834d510
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 20
  .byte 0
  .4byte 0x100000, 288*PX
  .4byte DIR_LEFT

Entity_0834d520: @ 0x0834d520
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 21
  .byte 0
  .4byte 0x102000, 288*PX
  .4byte DIR_LEFT

Entity_0834d530: @ 0x0834d530
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x4C000, 0x6C000
  .4byte DIR_RIGHT

@ ゼロを壊れた宇宙船のスタート地点に生成する
Entity_ZeroSpaceCraftStartPoint: @ 0x0834d540
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x52000, 0x6C000
  .4byte DIR_RIGHT

@ ゼロを壊れた宇宙船のスタート地点に生成する
Entity_ZeroSpaceCraftBuilding: @ 0x0834d550
  .byte PLAYER, ZERO, 0, 0
  .4byte 0xD4000, 0x57000
  .4byte DIR_RIGHT

Entity_0834d560: @ 0x0834d560
  .byte PLAYER, ZERO, 0, 0
  .4byte 0xE8000, 288*PX
  .4byte DIR_RIGHT

Entity_0834d570: @ 0x0834d570
  .byte PLAYER, ZERO, 0, 0
  .4byte 0xF9800, 288*PX
  .4byte DIR_RIGHT

Entity_OmegaWhite: @ 0x0834d580
  .byte BOSS, BOSS_OMEGA_WHITE, 0, 0
  .4byte 4128*PX, 288*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834d590:
  eventflag 0, 0, 0
  cmd06 0x70, 6, 0
  normal_screen
  wait_screeneffect
  play_bgm BGM_PROLOGUE
  wait 90
  scroll 0, 0, 0
  scroll 1, 10, 1300 @ Prologue text
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  wait SECOND/2
  eventflag 1, 0, 0
  lockmenu
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ script entity slot idx
@ 3: Zero
.equ CIEL, 4

Script_0834d608: @ 0x0834d608
  eventflag 0, 1, 0
  play_bgm BGM_INTRO_STARSHIP
  rune 11, 8, 11
  normal_screen
  wait_screeneffect
  wait SECOND*3
  blackout_screen
  wait_screeneffect
  rune 0, 0, 0
  wait SECOND*2
  reset_camera Camera_0834d294
  time 0
  lock
  normal_screen
  wait_screeneffect
  waitabs 213
  scroll_speed_y 0
  spawn 3, Entity_SpaceCraftIntroZero
  wait SECOND
  spawn CIEL, EntityTemplate_SpaceCraftIntroCiel
  spawn 6, EntityTemplate_0834d3a0
  wait SECOND/4
  spawn 5, EntityTemplate_0834d390
  wait SECOND*8+20
  scroll_speed_x 80
  wait SECOND*2
  print_message 0x50, 0x0300
  wait_msgbox_end
  wait SECOND*6
  entityflag 4, 0, TRUE
  scroll_speed_x 0x60
  wait FRAME
  scroll_speed_x 0x50
  wait FRAME
  scroll_speed_x 0x40
  wait FRAME
  scroll_speed_x 0x30
  wait FRAME
  scroll_speed_x 0x20
  wait FRAME
  scroll_speed_x 0x10
  entityflag 5, 0, TRUE
  wait FRAME*40
  scroll_speed_x 0x00
  emotion CIEL, 0xC00, 0xFFD800, 0
  wait SECOND/4
  entityflag 3, 0, TRUE
  entityflag 6, 0, TRUE
  wait SECOND
  emotion 3, 0xC00, 0xFFD800, 1
  wait SECOND*2
  print_message 0x50, 0x0301
  wait_msgbox_end
  gimmick 1, 0, 1
  wait SECOND*3
  print_message 0x50, 0x0302 @ 0x0837f1de
  wait_msgbox_end
  wait SECOND*2
  emotion 6, 0x800, 0xFFD800, 0
  wait SECOND
  print_message 0x50, 0x0303 @ 0x0837f1eb
  wait_msgbox_end
  wait SECOND/4
  entityflag 4, 1, TRUE
  wait SECOND/2
  blackout_screen
  wait_screeneffect
  visible 3, FALSE
  visible 4, FALSE
  visible 5, FALSE
  visible 6, FALSE
  stop_camera
  cutscene 0
  normal_screen
  cutscene 1
  wait SECOND/2
  message 1, 0, 0x0304
  wait_msgbox_end
  wait SECOND/2
  message 1, 0, 0x0305
  wait_msgbox_end
  wait SECOND/4
  blackout_screen
  wait_screeneffect
  cutscene 2
  visible 6, TRUE
  visible 5, TRUE
  visible 4, TRUE
  visible 3, TRUE
  entityflag 5, 1, TRUE
  reset_camera Camera_0834d2c0
  entityflag 4, 2, TRUE
  normal_screen
  wait_screeneffect
  wait SECOND/4
  message 1, 0, 0x0306
  wait_msgbox_end
  wait SECOND/4
  entityflag 3, 1, TRUE
  stop_bgm
  wait SECOND
  blackout_screen
  wait_screeneffect
  destroy 3
  destroy 4
  destroy 6
  destroy 5
  eventflag 1, 0, 0
  lockmenu
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834d978:  @ 0x0834d978
  unlockmenu
  spawn 0, Entity_0834d530
  reset_camera Camera_0834d268
  lock
  normal_screen
  forcekeyinput DPAD_RIGHT
  wait 16
  play_bgm BGM_BREAKOUT
  wait 16
  indicator 1, 0, 0
  walkto 0x52000
  wait_indicator_end
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_InitSpaceCraftStageRun: @ 0x0834d9f0
  spawn 0, Entity_ZeroSpaceCraftStartPoint
  reset_camera Camera_0834d268
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_BREAKOUT
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834da48: @ 0x0834da48
  eventflag 0, 2, 0
  force 0, 0, 0
  lock
  force 8, 0, 0
  turn_right 0
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 0xC5000
  wait 90*FRAME
  start_talk
  wait 45*FRAME
  message 1, 0, 0x307
  wait_msgbox_end
  wait SECOND/4
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 0x72, 6, 0
  normal_screen
  wait_screeneffect
  wait SECOND/4
  message 1, 0, 0x308 @ アイツは俺のことを知っていた.. 世界を滅ぼしかけたエルフがなぜオレのことを..
  wait_msgbox_end
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  resume_camera
  change_camera_mode 1
  normal_screen
  wait_screeneffect
  wait SECOND/2
  message 1, 0, 0x309
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, 0x30A
  wait_msgbox_end
  wait SECOND/4
  blackout_screen
  wait_screeneffect
  gimmick 1, 0, 1
  spawn 4, EntityTemplate_0834d3c0
  spawn 5, EntityTemplate_0834d3d0
  spawn 3, EntityTemplate_0834d3b0
  reset_camera Camera_0834d2c0
  normal_screen
  wait_screeneffect
  wait SECOND/4
  message 1, 0, 0x30B
  wait_msgbox_end
  wait SECOND/2
  emotion 4, 0x800, 0xFFD800, 0 
  stop_bgm
  wait SECOND
  message 1, 0, 0x30C
  wait SECOND
  play_bgm BGM_ANTAN
  wait_msgbox_end
  wait SECOND/4
  entityflag 3, 0, TRUE
  wait SECOND/4
  entityflag 4, 0, TRUE
  wait 15
  message 1, 0, 0x030E
  wait_msgbox_end
  wait 15
  entityflag 5, 1, TRUE
  wait 30
  spawn 6, Entity_0834d3e0
  wait 8
  entityflag 3, 1, TRUE
  wait 15
  spawn 7, Entity_0834d3e0
  wait 15
  stop_bgm
  blackout_screen
  wait_screeneffect
  stop_camera
  wait 90
  play_se 90
  wait 60
  destroy 3
  destroy 4
  destroy 5
  destroy 6
  destroy 7
  wait 120
  reset_camera Camera_0834d2ec
  normal_screen
  wait_screeneffect
  play_bgm 166
  message 1, 0, 0x030F
  wait_msgbox_end
  wait 30
  emotion 0, 0x0C00, 0x00FFD800, 0
  wait 60
  force 3, 0, 0
  wait 60
  spawn 3, Entity_0834d3f0
  wait 90
  message 1, 0, 0x0310
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 30
  message 1, 0, 0x0311
  wait_msgbox_end
  entityflag 3, 1, TRUE
  wait 15
  entityflag 3, 2, TRUE
  wait 180
  message 1, 0, 0x0312
  wait_msgbox_end
  wait 90
  message 1, 0, 0x0313
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 60
  message 1, 0, 0x0314
  wait_msgbox_end
  wait 15
  message 1, 0, 0x0315
  wait_msgbox_end
  wait 60
  destroy 3
  play_se 231
  wait 180
  emotion 0, 0x0C00, 0x00FFD800, 0
  wait 60
  message 1, 0, 0x0316
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 115, 0, 0
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x0317
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  reset_camera Camera_0834d2ec
  normal_screen
  wait_screeneffect
  wait 15
  force 3, 0, 0
  wait 15
  force 1, 0, 0
  forcekeyinput 0x00004010
  wait 1
  force 9, 0, 868352
  adjust_camera 1, 0, 4
  adjust_camera 11, 0, 860160
  adjust_camera 14, 0, 2621440
  stop_bgm
  wait 60
  eventflag 1, 0, 0
  play_bgm 170
  release
  resume 1
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_SpaceCraftBuilding:
  spawn 0, Entity_ZeroSpaceCraftBuilding
  reset_camera Camera_0834d318
  lock
  normal_screen
  wait_screeneffect
  play_bgm BGM_BREAKOUT
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834dfb8:
  spawn 0, Entity_ZeroSpaceCraftBuilding
  reset_camera Camera_0834d318
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_BREAKOUT
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_GuarderRoom:
  spawn 0, Entity_0834d560
  reset_camera Camera_0834d318
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_PreOmegaWhiteBattle:
  eventflag 0, 3, 0
  spawn 3, Entity_PantheonOmegaCrash0
  spawn 4, Entity_PantheonOmegaCrash1
  spawn 5, Entity_PantheonOmegaCrash2
  stop_bgm
  lock
  force 0, 0, 0
  turn_right 0
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  play_se 285
  quake 2, 0, 4
  wait 60
  play_bgm 167
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1013760
  wait 60
  play_se 285
  quake 2, 0, 8
  wait 30
  play_se 285
  quake 2, 0, 12
  wait 30
  gimmick 1, 2, 1
  quake 0, 0, 2
  wait 60
  play_se 246
  wait 30
  spawn 6, Entity_0834d440
  spawn 7, Entity_0834d430
  gimmick 1, 2, 2
  wait 30
  quake 0, 0, 4
  wait 30
  gimmick 1, 2, 3
  stop_quake
  wait 90
  spawn 8, Entity_0834d450
  gimmick 1, 2, 4
  wait 60
  entityflag 6, 0, TRUE
  entityflag 7, 0, TRUE
  destroy 3
  destroy 4
  destroy 5
  wait 90
  message 1, 0, 0x0319
  wait_msgbox_end
  wait 15
  entityflag 8, 0, TRUE
  wait 90
  message 1, 0, 0x031A
  wait_msgbox_end
  wait 15
  entityflag 8, 1, TRUE
  wait 60
  entityflag 7, 1, TRUE
  wait 60
  message 1, 0, 0x031B
  wait_msgbox_end
  wait 15
  spawn 1, Entity_OmegaWhite
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1028096
  wait 60
  play_se 231
  wait 90
  stop_bgm
  wait 90
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 116, 3, 0
  normal_screen
  wait_screeneffect
  play_bgm 165
  wait 15
  cmd06 116, 4, 0
  wait 15
  message 1, 0, 0x031C
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  resume_camera
  change_camera_mode 1
  adjust_camera 1, 0, 8
  adjust_camera 3, 0, 1028096
  normal_screen
  wait_screeneffect
  force 1, 0, 0
  gameflag FLAG_2, FALSE
  walkto 3992*PX
  gameflag FLAG_2, TRUE
  emotion 8, 0x1000, 0x00FFD800, 0
  wait 60
  message 1, 0, 0x031D
  wait_msgbox_end
  wait 15
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1013760
  wait 60
  message 1, 0, 0x031E
  wait_msgbox_end
  wait 15
  entityflag 6, 1, TRUE
  wait 60
  change_camera_mode 1
  adjust_camera 1, 0, 2
  adjust_camera 3, 0, 1028096
  wait 60
  message 1, 0, 0x031F
  wait_msgbox_end
  wait 15
  entityflag 8, 2, TRUE
  eventflag 1, 0, 0
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 2
  adjust_camera 11, 0, 1009664
  adjust_camera 12, 0, 1071104
  stop_bgm
  wait 120
  play_se 231
  wait 180
  message 1, 0, 0x0320
  wait_msgbox_end
  wait 15
  destroy 6
  destroy 7
  destroy 8
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 187
  resume 1
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_IntoOmegaWhiteBattle:
  cmd1c 0, 0, 0
  wait FRAME
  gimmick 1, 2, 4
  forcekeyinput DPAD_RIGHT
  pause
  spawn 1, Entity_OmegaWhite
  eventflag 0, 3, 0
  gameflag FLAG_2, TRUE
  walkto 3992 * PX
  eventflag 1, 0, 0
  change_camera_mode 6
  adjust_camera 1, 0, 2
  adjust_camera 11, 0, 3944 * PX
  adjust_camera 12, 0, 4184 * PX
  stop_bgm
  wait SECOND
  play_se SE_OMEGA1_GROWL
  wait 2*SECOND
  warning_indicator
  wait_indicator_end
  clear_force_coord
  release
  play_bgm BGM_OMEGA_BATTLE
  resume 1
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834e5a0:
  cmd1c 0, 0, 0
  spawn 0, Entity_0834d570
  spawn 1, Entity_OmegaWhite
  reset_camera Camera_0834d344
  lock
  screeneffect 9
  wait 1
  gimmick 1, 2, 4
  wait_screeneffect
  play_se 231
  wait 120
  warning_indicator
  wait_indicator_end
  release
  play_bgm 187
  resume 1
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834e628:
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  eventflag 0, 4, 0
  entityflag 1, 7, TRUE
  wait 90
  message 1, 0, 0x0321
  wait_msgbox_end
  wait 15
  force 8, 0, 0
  force 9, 0, 1019904
  wait 8
  turn_right 0
  wait 120
  entityflag 1, 0, TRUE
  wait 30
  play_bgm 167
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 90
  play_se 231
  wait 240
  message 1, 0, 0x0322
  wait_msgbox_end
  wait 15
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  sweep 1, 0, 0
  sweep 3, 0, 0
  spawn 3, Entity_0834d460
  wait 9
  spawn 4, Entity_0834d470
  wait 9
  spawn 5, Entity_0834d480
  wait 9
  spawn 6, Entity_0834d490
  wait 12
  spawn 7, Entity_0834d4a0
  wait 9
  spawn 8, Entity_0834d4b0
  wait 12
  spawn 9, Entity_0834d4c0
  wait 18
  spawn 10, Entity_0834d4d0
  wait 30
  spawn 11, Entity_0834d4e0
  wait 15
  destroy 3
  destroy 4
  destroy 5
  destroy 6
  destroy 7
  destroy 8
  destroy 9
  destroy 10
  destroy 11
  spawn 3, Entity_0834d4f0
  wait 60
  entityflag 1, 0, FALSE
  wait 90
  message 1, 0, 0x0324
  wait_msgbox_end
  wait 15
  message 1, 0, 0x0323
  wait_msgbox_end
  entityflag 1, 0, TRUE
  wait 30
  entityflag 3, 0, TRUE
  wait 90
  play_se 231
  wait 210
  message 1, 0, 0x0325
  wait_msgbox_end
  stop_bgm
  wait 15
  emotion 0, 0x1000, 0x00FFD800, 0
  emotion 3, 0x0C00, 0x00FFD000, 0
  wait 90
  play_bgm 166
  message 1, 0, 0x0326
  wait_msgbox_end
  wait 60
  play_se 231
  message 1, 0, 0x0327
  wait_msgbox_end
  spawn 4, Entity_0834d500
  wait 210
  blackout_screen
  wait_screeneffect
  stop_camera
  cmd06 117, 0, 0
  normal_screen
  wait_screeneffect
  wait 15
  message 1, 0, 0x0328
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_screeneffect
  cmd06 0, 1, 0
  resume_camera
  change_camera_mode 1
  adjust_camera 1, 0, 8
  normal_screen
  wait_screeneffect
  play_bgm 164
  wait 15
  spawn 5, Entity_0834d510
  wait 60
  message 1, 0, 0x0329
  wait_msgbox_end
  wait 15
  entityflag 3, 1, TRUE
  wait 150
  message 1, 0, 0x032A
  wait_msgbox_end
  wait 60
  message 1, 0, 0x032B
  wait_msgbox_end
  emotion 3, 0x0C00, 0x00FFD800, 0
  wait 60
  message 1, 0, 0x032C
  wait_msgbox_end
  wait 30
  message 1, 0, 0x032D
  wait_msgbox_end
  wait 15
  entityflag 5, 0, TRUE
  wait 120
  message 1, 0, 0x032E
  wait_msgbox_end
  wait 15
  entityflag 3, 2, TRUE
  wait 30
  entityflag 4, 0, TRUE
  wait 30
  spawn 6, Entity_0834d520
  wait 30
  destroy 1
  wait 60
  stop_bgm
  wait 120
  destroy 6
  force 2, 0, 0
  wait 75
  play_bgm 167
  message 1, 0, 0x032F
  wait_msgbox_end
  wait 15
  message 1, 0, 0x0330
  wait_msgbox_end
  message 1, 0, 0x0331
  wait_msgbox_end
  message 1, 0, 0x0332
  wait_msgbox_end
  stop_bgm
  wait 15
  force 4, 0, 0
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 60
  eventflag 1, 0, 0
  destroy 0
  destroy 3
  destroy 4
  destroy 5
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  prepare_missionresult
  missionresult
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_MissionResult:
  backdrop_color 0xFFFF
  prepare_missionresult
  missionresult
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_InitSpaceCraftFreeRun:
  spawn 0, Entity_ZeroSpaceCraftStartPoint
  reset_camera Camera_0834d268
  lock
  wait FRAME
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm BGM_BREAKOUT
  indicator 1, 0, 0
  wait 15*FRAME
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0834ec38:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 0xF7800
  lock
  wait 16*FRAME
  force 4, 0, 0
  wait SECOND/2
  force 5, 0, 0
  wait SECOND
  blackout_screen
  wait_screeneffect
  wait SECOND/2
  destroy 0
  force 1, 0, 0
  release
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gSpaceCraftScriptList
gSpaceCraftScriptList:
  .word Script_0834d590
  .word Script_0834d608
  .word Script_0834d978
  .word Script_InitSpaceCraftStageRun
  .word Script_0834da48
  .word Script_SpaceCraftBuilding
  .word Script_0834dfb8
  .word Script_GuarderRoom
  .word Script_PreOmegaWhiteBattle
  .word Script_IntoOmegaWhiteBattle
  .word Script_0834e5a0
  .word Script_0834e628
  .word Script_MissionResult
  .word Script_InitSpaceCraftFreeRun
  .word Script_0834ec38
