.include "asm/macros.inc"
.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/entity.h"
#include "constants/song.h"

.balign 4
.section .rodata

Camera_08356674: @ 0x08356674
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Entity_083566a0: @ 0x083566a0
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 448*PX
  .4byte DIR_RIGHT

@ 検索部屋に入ってきたときの座標
Entity_083566b0: @ 0x083566b0
  .byte PLAYER, ZERO, 0, 0
  .4byte 5328*PX, 448*PX
  .4byte DIR_RIGHT

@ 検索画面から戻ってきた時の座標
Entity_083566c0: @ 0x083566c0
  .byte PLAYER, ZERO, 0, 0
  .4byte 5392*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083566d0: @ 0x083566d0
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_083566e0: @ 0x083566e0
  .byte PLAYER, ZERO, 0, 0
  .4byte 1792*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_083566f0: @ 0x083566f0
  .byte PLAYER, ZERO, 0, 0
  .4byte 1072*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08356700: @ 0x08356700
  .byte PLAYER, ZERO, 0, 0
  .4byte 2512*PX, 1024*PX
  .4byte DIR_RIGHT

Entity_08356710: @ 0x08356710
  .byte PLAYER, ZERO, 0, 0
  .4byte 528*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08356720: @ 0x08356720
  .byte PLAYER, ZERO, 0, 0
  .4byte 1968*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08356730: @ 0x08356730
  .byte PLAYER, ZERO, 0, 0
  .4byte 1248*PX, 1248*PX
  .4byte DIR_RIGHT

Entity_08356740: @ 0x08356740
  .byte PLAYER, ZERO, 0, 0
  .4byte 2688*PX, 1024*PX
  .4byte DIR_RIGHT

Entity_08356750: @ 0x08356750
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 23
  .4byte 672*PX, 1248*PX
  .4byte DIR_LEFT

Entity_08356760: @ 0x08356760
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 23
  .4byte 2112*PX, 1248*PX
  .4byte DIR_LEFT

Entity_08356770: @ 0x08356770
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 23
  .4byte 1392*PX, 1248*PX
  .4byte DIR_LEFT

Entity_08356780: @ 0x08356780
  .byte SOLID, SOLID_SCRIPT_ACTOR, 25, 23
  .4byte 2832*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08356790: @ 0x08356790
  .byte BOSS, 5, 0, 0
  .4byte 672*PX, 1248*PX
  .4byte DIR_LEFT

Entity_083567a0: @ 0x083567a0
  .byte BOSS, 5, 0, 0
  .4byte 2112*PX, 1248*PX
  .4byte DIR_LEFT

Entity_083567b0: @ 0x083567b0
  .byte BOSS, 5, 0, 0
  .4byte 1392*PX, 1248*PX
  .4byte DIR_LEFT

Entity_083567c0: @ 0x083567c0
  .byte BOSS, 5, 0, 0
  .4byte 2832*PX, 1088*PX
  .4byte DIR_LEFT


@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0_083567d0: @ 0x083567d0
  eventflag 0, 36, 0
  spawn 0, Entity_083566a0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_screeneffect
  play_bgm 331
  wait 15
  force 6, 0, 0
  wait 60
  message 1, 0, 0x0F00
  wait_msgbox_end
  stop_bgm
  wait 15
  eventflag 1, 0, 0
  indicator 1, 2, 0
  wait 45
  play_bgm 182
  wait_indicator_end
  release
  resume 0
  end

Script_1_08356890: @ 0x08356890
  spawn 0, Entity_083566a0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  indicator 1, 2, 0
  wait 45
  play_bgm 182
  wait_indicator_end
  release
  resume 0
  end

Script_2_083568f0: @ 0x083568f0
  spawn 0, Entity_083566a0
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 182
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_3_08356948: @ 0x08356948
  eventflag 0, 37, 0
  forcekeyinput 0x0010
  pause
  walkto 5328*PX
  lock
  message 1, 0, 0x0F01
  wait_msgbox_end
  wait 15
  eventflag 1, 0, 0
  release
  resume 1
  end

Script_4_083569a8: @ 0x083569a8
  spawn 0, Entity_083566b0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  play_bgm 182
  release
  resume 0
  end

Script_5_083569f0: @ 0x083569f0
  spawn 0, Entity_083566c0
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 182
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_6_08356a48: @ 0x08356a48
  force 0, 0, 0
  lock
  wait_msgbox_end
  wait 15
  force 8, 0, 0
  message 5, 0, 0
  wait_msgbox_end
  wait 15
  message 5, 1, 0
  wait_msgbox_end
  wait 15
  release
  force 1, 0, 0
  resume 1
  end

Script_7_08356ac0: @ 0x08356ac0
  spawn 0, Entity_083566d0
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_8_08356b18: @ 0x08356b18
  spawn 0, Entity_083566e0
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_9_08356b70: @ 0x08356b70
  spawn 0, Entity_083566f0
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_10_08356bc8: @ 0x08356bc8
  spawn 0, Entity_08356700
  reset_camera Camera_08356674
  lock
  screeneffect 9
  wait_screeneffect
  play_bgm 161
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_11_08356c20: @ 0x08356c20
  eventflag 0, 42, 0
  stop_bgm
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  walkto 528*PX
  turn_right 0
  lock
  force 0, 0, 0
  wait 16
  turn_right 0
  play_bgm 161
  spawn 3, Entity_08356750
  wait 60
  message 1, 0, 0x0F0C
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_08356790
  wait 60
  destroy 3
  triumphant_message 0, 0x0F0E
  message 1, 0, 0x0F0D
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_12_08356d58: @ 0x08356d58
  eventflag 0, 42, 0
  stop_bgm
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  walkto 1968*PX
  turn_right 0
  lock
  force 0, 0, 0
  wait 16
  turn_right 0
  play_bgm 161
  spawn 3, Entity_08356760
  wait 60
  message 1, 0, 0x0F0C
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_083567a0
  wait 60
  destroy 3
  triumphant_message 0, 0x0F0E
  message 1, 0, 0x0F0D
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_13_08356e90: @ 0x08356e90
  eventflag 0, 42, 0
  stop_bgm
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  walkto 1248*PX
  turn_right 0
  lock
  force 0, 0, 0
  wait 16
  turn_right 0
  play_bgm 161
  spawn 3, Entity_08356770
  wait 60
  message 1, 0, 0x0F0C
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_083567b0
  wait 60
  destroy 3
  triumphant_message 0, 0x0F0E
  message 1, 0, 0x0F0D
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_14_08356fc8: @ 0x08356fc8
  eventflag 0, 42, 0
  stop_bgm
  lock
  emotion 0, 0x1000, 0x00FFD800, 0
  wait 60
  walkto 2688*PX
  turn_right 0
  lock
  force 0, 0, 0
  wait 16
  turn_right 0
  play_bgm 161
  spawn 3, Entity_08356780
  wait 60
  message 1, 0, 0x0F0C
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 90
  spawn 1, Entity_083567c0
  wait 60
  destroy 3
  triumphant_message 0, 0x0F0E
  message 1, 0, 0x0F0D
  wait_msgbox_end
  eventflag 1, 0, 0
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 14, 0 1152*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_15_08357100: @ 0x08357100
  spawn 1, Entity_08356790
  pause
  eventflag 0, 42, 0
  walkto 528*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_16_08357198: @ 0x08357198
  spawn 1, Entity_083567a0
  pause
  eventflag 0, 42, 0
  walkto 1968*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_17_08357230: @ 0x08357230
  spawn 1, Entity_083567b0
  pause
  eventflag 0, 42, 0
  walkto 1248*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_18_083572c8: @ 0x083572c8
  spawn 1, Entity_083567c0
  pause
  eventflag 0, 42, 0
  walkto 2688*PX
  lock
  eventflag 1, 0, 0
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 14, 0 1152*PX
  warning_indicator
  wait_indicator_end
  release
  play_bgm 188
  resume 1
  end

Script_19_08357360: @ 0x08357360
  spawn 0, Entity_08356710
  spawn 1, Entity_08356790
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_20_083573f8: @ 0x083573f8
  spawn 0, Entity_08356720
  spawn 1, Entity_083567a0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_21_08357490: @ 0x08357490
  spawn 0, Entity_08356730
  spawn 1, Entity_083567b0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 13, 0 1088*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_22_08357528: @ 0x08357528
  spawn 0, Entity_08356740
  spawn 1, Entity_083567c0
  reset_camera Camera_08356674
  lock
  normal_screen
  wait_screeneffect
  triumphant_message 0, 0x0F0E
  entityflag 1, 0, TRUE
  wait 120
  change_camera_mode 6
  adjust_camera 1, 0, 4
  adjust_camera 14, 0 1152*PX
  warning_indicator
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm 188
  resume 1
  end

Script_23_083575c0: @ 0x083575c0
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  message 1, 0, 0x0F0F
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08 1, 2
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  screeneffect 6
  wait_screeneffect
  wait 32
  destroy 1
  destroy 0
  load_graphic_primitive
  stop_camera
  cmd06 0, 5, 65535
  screeneffect 5
  wait 90
  prepare_missionresult
  missionresult
  end

Script_24_08357680: @ 0x08357680
  spawn 0, Entity_083566a0
  reset_camera Camera_08356674
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_screeneffect
  play_bgm 182
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_25_083576f8: @ 0x083576f8
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

.global gSunkenLibraryScriptList
gSunkenLibraryScriptList: @ 0x08357788
  .4byte Script_0_083567d0 @ 0x083567d0
  .4byte Script_1_08356890 @ 0x08356890
  .4byte Script_2_083568f0 @ 0x083568f0
  .4byte Script_3_08356948 @ 0x08356948
  .4byte Script_4_083569a8 @ 0x083569a8
  .4byte Script_5_083569f0 @ 0x083569f0
  .4byte Script_6_08356a48 @ 0x08356a48
  .4byte Script_7_08356ac0 @ 0x08356ac0
  .4byte Script_8_08356b18 @ 0x08356b18
  .4byte Script_9_08356b70 @ 0x08356b70
  .4byte Script_10_08356bc8 @ 0x08356bc8
  .4byte Script_11_08356c20 @ 0x08356c20
  .4byte Script_12_08356d58 @ 0x08356d58
  .4byte Script_13_08356e90 @ 0x08356e90
  .4byte Script_14_08356fc8 @ 0x08356fc8
  .4byte Script_15_08357100 @ 0x08357100
  .4byte Script_16_08357198 @ 0x08357198
  .4byte Script_17_08357230 @ 0x08357230
  .4byte Script_18_083572c8 @ 0x083572c8
  .4byte Script_19_08357360 @ 0x08357360
  .4byte Script_20_083573f8 @ 0x083573f8
  .4byte Script_21_08357490 @ 0x08357490
  .4byte Script_22_08357528 @ 0x08357528
  .4byte Script_23_083575c0 @ 0x083575c0
  .4byte Script_24_08357680 @ 0x08357680
  .4byte Script_25_083576f8 @ 0x083576f8
