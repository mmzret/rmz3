.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/boss.h"
#include "constants/song.h"
#include "constants/solid.h"
#include "constants/flag.h"

  .balign 4
  .section .rodata

Camera_0834d268: @ 0x0834d268
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x4B000, 0x3C0000, 0x0, 0x280000

Camera_0834d294: @ 0x0834d294
  .byte 1
  .byte 9
  .byte 0, 0
  .4byte 0x7800,  0x5F000
  .4byte 0x0,     0xC0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0834d2c0: @ 0x0834d2c0
  .byte 1
  .byte 8
  .byte 0, 0
  .4byte 0x44800, 0x69000
  .4byte 0x0,     0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0834d2ec: @ 0x0834d2ec
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0xC5000, 0x3C0000, 0x0, 0x5A000

Camera_0834d318: @ 0x0834d318
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0xD2000, 0x3C0000, 0x0, 0x280000

Camera_0834d344: @ 0x0834d344
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0xF6800, 0x105800, 0x0, 0x280000

EntityTemplate_SpaceCraftIntroZero: @ 0x0834d370
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_ZERO_WALK
  .byte 0x0
  .4byte 0xFFFFE000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_SpaceCraftIntroCiel: @ 0x0834d380
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_CIEL_WALK
  .byte 0x0
  .4byte 0xFFFFB000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d390: @ 0x0834d390
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x3
  .byte 0x0
  .4byte 0xFFFFD000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3a0: @ 0x0834d3a0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x3
  .byte 0x1
  .4byte 0xFFFF8000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3b0: @ 0x0834d3b0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x4
  .byte 0x0
  .4byte 0x47000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3c0: @ 0x0834d3c0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x5
  .byte 0x0
  .4byte 0x42000, 0x6C000
  .4byte DIR_LEFT

EntityTemplate_0834d3d0: @ 0x0834d3d0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x5
  .byte 0x1
  .4byte 0x45000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3e0: @ 0x0834d3e0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x7
  .byte 0x1
  .4byte 0x3B000, 0x6C000
  .4byte DIR_RIGHT

EntityTemplate_0834d3f0: @ 0x0834d3f0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 0x6
  .byte 0x0
  .4byte 0xCF000, 0x57000
  .4byte DIR_LEFT

@ オメガと四天王の戦闘に巻き込まれて死ぬパンテオン3匹(0)
EntityTemplate_PantheonOmegaCrash0: @ 0x0834d400
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_CRASHED_PANTHEON
  .byte 0
  .4byte 0xF6000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_PantheonOmegaCrash1:
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_CRASHED_PANTHEON
  .byte 1
  .4byte 0xF7000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_PantheonOmegaCrash2:
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_CRASHED_PANTHEON
  .byte 1
  .4byte 0xF9000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d430: @ 0x0834d430
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 10
  .byte 0
  .4byte 0xFB000, 0xF000
  .4byte DIR_LEFT

EntityTemplate_0834d440: @ 0x0834d440
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 11
  .byte 0
  .4byte 0xFB000, 0xF000
  .4byte DIR_LEFT

EntityTemplate_0834d450: @ 0x0834d450
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 12
  .byte 0
  .4byte 0xFB000, 0x13000
  .4byte DIR_RIGHT

EntityTemplate_0834d460: @ 0x0834d460
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 0
  .4byte 0x101000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d470: @ 0x0834d470
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 1
  .4byte 0x103800, 0x12000
  .4byte DIR_LEFT

EntityTemplate_0834d480: @ 0x0834d480
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 2
  .4byte 0x102600, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d490: @ 0x0834d490
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 3
  .4byte 0x101500, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d4a0: @ 0x0834d4a0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 4
  .4byte 0x103000, 0x12000
  .4byte DIR_LEFT


EntityTemplate_0834d4b0: @ 0x0834d4b0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 5
  .4byte 0x102200, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d4c0: @ 0x0834d4c0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 6
  .4byte 0x102800, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d4d0: @ 0x0834d4d0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 7
  .4byte 0x101800, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d4e0: @ 0x0834d4e0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 17
  .byte 8
  .4byte 0x102000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d4f0: @ 0x0834d4f0
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 18
  .byte 0
  .4byte 0xFD000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_0834d500: @ 0x0834d500
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 19
  .byte 0
  .4byte 0x104000, 0xE000
  .4byte DIR_LEFT

EntityTemplate_0834d510: @ 0x0834d510
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 20
  .byte 0
  .4byte 0x100000, 0x12000
  .4byte DIR_LEFT

EntityTemplate_0834d520: @ 0x0834d520
  .byte SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte 21
  .byte 0
  .4byte 0x102000, 0x12000
  .4byte DIR_LEFT

EntityTemplate_0834d530: @ 0x0834d530
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x4C000, 0x6C000
  .4byte DIR_RIGHT

@ ゼロを壊れた宇宙船のスタート地点に生成する
EntityTemplate_ZeroSpaceCraftStartPoint: @ 0x0834d540
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 0x52000, 0x6C000
  .4byte DIR_RIGHT

@ ゼロを壊れた宇宙船のスタート地点に生成する
EntityTemplate_ZeroSpaceCraftBuilding: @ 0x0834d550
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 0xD4000, 0x57000
  .4byte DIR_RIGHT

EntityTemplate_Zero_0834d560: @ 0x0834d560
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 0xE8000, 0x12000
  .4byte DIR_RIGHT

EntityTemplate_Zero_0834d570: @ 0x0834d570
  .byte PLAYER
  .byte 0
  .byte 0
  .byte 0
  .4byte 0xF9800, 0x12000
  .4byte DIR_RIGHT

Entity_OmegaWhite: @ 0x0834d580
  .byte BOSS
  .byte BOSS_OMEGA_WHITE
  .byte 0
  .byte 0
  .4byte 0x102000, 0x12000
  .4byte DIR_LEFT

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
.equ ZERO, 3
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
  spawn ZERO, 0, EntityTemplate_SpaceCraftIntroZero
  wait SECOND
  spawn CIEL, 0, EntityTemplate_SpaceCraftIntroCiel
  spawn 6, 0, EntityTemplate_0834d3a0
  wait SECOND/4
  spawn 5, 0, EntityTemplate_0834d390
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
  emotion ZERO, 0xC00, 0xFFD800, 1
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
  spawn 0, 0, EntityTemplate_0834d530
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
  spawn 0, 0, EntityTemplate_ZeroSpaceCraftStartPoint
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
  spawn 4, 0, EntityTemplate_0834d3c0
  spawn 5, 0, EntityTemplate_0834d3d0
  spawn 3, 0, EntityTemplate_0834d3b0
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
  .incbin "data/Script_0834da48.bin" @ ./tools/dumper/bin.ts ./baserom.gba 0x0834dc28 0x0834df70 ./data/Script_0834da48.bin
  @ WIP 0x0834dc28..0x0834df70

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_SpaceCraftBuilding:
  spawn 0, 0, EntityTemplate_ZeroSpaceCraftBuilding
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
  spawn 0, 0, EntityTemplate_ZeroSpaceCraftBuilding
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
  spawn 0, 0, EntityTemplate_Zero_0834d560
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
# ./tools/dumper/bin.ts ./baserom.gba 0x0834e068 0x0834e4d8 ./data/Script_PreOmegaWhiteBattle.bin
  .incbin "data/Script_PreOmegaWhiteBattle.bin"

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_IntoOmegaWhiteBattle:
  cmd1c 0, 0, 0
  wait FRAME
  gimmick 1, 2, 4
  forcekeyinput DPAD_RIGHT
  pause
  spawn 1, 0, Entity_OmegaWhite
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
# ./tools/dumper/bin.ts ./baserom.gba 0x0834e5a0 0x0834eba0 ./data/spacecraft_scripts.bin
  .incbin "data/spacecraft_scripts.bin"

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_MissionResult:
  backdrop_color 0xFFFF
  prepare_missionresult
  missionresult
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_InitSpaceCraftFreeRun:
  spawn 0, 0, EntityTemplate_ZeroSpaceCraftStartPoint
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

.global SpaceCraftScriptList
SpaceCraftScriptList:
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
  .word 0x0834E628
  .word Script_MissionResult
  .word Script_InitSpaceCraftFreeRun
  .word Script_0834ec38
