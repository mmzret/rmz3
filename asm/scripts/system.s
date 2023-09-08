.include "asm/scripts/commands.inc"
.include "asm/scripts/constants.inc"
#include "constants/song.h"

    .balign 4
    .section .rodata

.global Script_MissionFail
Script_MissionFail: @ 0x0834d0b4
    disablekeyinput 2 0 0xFFFF
    message 7 0 0
    stop_bgm
    wait SECOND
    message 5 0 0
    wait SECOND
    message 2 0 0
    indicator 0 0 0
    indicator 2 0 0
    indicator 0 0 0
    fadeout_se SECOND SE_IN_SEA
    screeneffect 10
    screeneffect 0
    wait SECOND
    end

.global Script_MissionFail2
Script_MissionFail2: @ 0x0834d12c
    disablekeyinput 2 0 0xFFFF
    message 7 0 0
    stop_bgm
    screeneffect 0
    screeneffect 1
    wait SECOND
    message 5 0 0
    wait SECOND
    message 2 0 0
    indicator 0 0 0
    indicator 2 0 0
    indicator 0 0 0
    fadeout_se SECOND SE_IN_SEA
    screeneffect 10
    screeneffect 0
    wait SECOND
    end

.global CielGoodluckTextIDs
CielGoodluckTextIDs: @ 0x0834d1b4
    .2byte 0x0000
    .2byte 0x0059
    .2byte 0x005A
    .2byte 0x005B
    .2byte 0x005C
    .2byte 0x005D
    .2byte 0x0000
    .2byte 0x005E
    .2byte 0x005F
    .2byte 0x0060
    .2byte 0x1334
    .2byte 0x0061
    .2byte 0x0062
    .2byte 0x0063
    .2byte 0x0064
    .2byte 0x0065
    .2byte 0x0000
    .2byte 0x0000
