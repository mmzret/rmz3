.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

gTerminateCharCode::
    .byte 0xFF
    .balign 4, 0

# strN = 0x08372aa0 + StringOfsTable[N]
StringOfsTable:: @ StringOfsTable
    .hword 0x0000, 0x0002, 0x000c, 0x0010, 0x0013, 0x0016, 0x0018, 0x001a, 0x001c, 0x001e, 0x0020, 0x02b5, 0x02c0, 0x02c0, 0x02c0, 0x02c0
    .hword 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c0, 0x02c2
    .hword 0x02c4, 0x02c6, 0x02c8, 0x02ca, 0x02cc, 0x02ce, 0x02d0, 0x02d2, 0x02d4, 0x02d9, 0x02de, 0x02e3, 0x02e8, 0x02ed, 0x02f2, 0x02f7
    .hword 0x0302, 0x030f, 0x031e, 0x0329, 0x0332, 0x033a, 0x0344, 0x034d, 0x035a, 0x0361, 0x036a, 0x036f, 0x037b, 0x0386, 0x0392, 0x0392
    .hword 0x03cd, 0x040a, 0x0439, 0x046d, 0x04ad, 0x04e1, 0x051e, 0x0551, 0x0583, 0x05b2, 0x05ec, 0x061f, 0x0637, 0x0637, 0x0637, 0x0637
    .hword 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x0637
    .hword 0x0637, 0x0637, 0x0637, 0x0637, 0x0637, 0x063d, 0x0642, 0x0647, 0x064c, 0x0651, 0x0656, 0x065b, 0x065f, 0x0663, 0x0668, 0x066c
    .hword 0x0670, 0x0675, 0x0679, 0x067d, 0x0682, 0x0686, 0x068b, 0x0691, 0x0696, 0x069b, 0x06a0, 0x06a5, 0x06aa, 0x06af, 0x06b4, 0x06b9
    .hword 0x06be, 0x06c3, 0x06c7, 0x06cc, 0x06d1, 0x06d7, 0x06dd, 0x06e2, 0x06e7, 0x06ed, 0x06f3, 0x06f8, 0x06fd, 0x0702, 0x0708, 0x070d
    .hword 0x0712, 0x0718, 0x071d, 0x0722, 0x0727, 0x072d, 0x0733, 0x0739, 0x073f, 0x0744, 0x074a, 0x0750, 0x0756, 0x075c, 0x0762, 0x0768
    .hword 0x076e, 0x0774, 0x077a, 0x0780, 0x0786, 0x078c, 0x0792, 0x0798, 0x079e, 0x07a4, 0x07a9, 0x07ae, 0x07b4, 0x07b9, 0x07be, 0x07c1
    .hword 0x07d0, 0x07df, 0x0802, 0x081c, 0x083b, 0x0852, 0x086b, 0x0898, 0x08c6, 0x08d7, 0x08ef, 0x0907, 0x0914, 0x0931, 0x0950, 0x0970
    .hword 0x098f, 0x09a7, 0x09bf, 0x09c2, 0x09de, 0x09fa, 0x0a07, 0x0a19, 0x0a29, 0x0a4a, 0x0a6b, 0x0a8c, 0x0ab0, 0x0ace, 0x0aea, 0x0b08
    .hword 0x0b26, 0x0b48, 0x0b6a, 0x0b8d, 0x0ba9, 0x0bc9, 0x0be9, 0x0c0b, 0x0c2e, 0x0c4d, 0x0c6c, 0x0c8c, 0x0cae, 0x0ccc, 0x0ceb, 0x0d10
    .hword 0x0d37, 0x0d5f, 0x0d80, 0x0da2, 0x0dc1, 0x0de1, 0x0dfe, 0x0e1b, 0x0e3c, 0x0e57, 0x0e78, 0x0e9c, 0x0ebf, 0x0ed9, 0x0ef4, 0x0f14
    .hword 0x0f32, 0x0f57, 0x0f74, 0x0f97, 0x0fbd, 0x0fdc, 0x1000, 0x1020, 0x1045, 0x1057, 0x1069, 0x107a, 0x108c, 0x10ab, 0x10d0, 0x10f2
    .hword 0x1116, 0x1138, 0x115c, 0x1175, 0x118f, 0x11ad, 0x11ce, 0x11f0, 0x1216, 0x1238, 0x125b, 0x127c, 0x129c, 0x12be, 0x12db, 0x12fc
    .hword 0x1317, 0x1340, 0x1366, 0x1384, 0x13a6, 0x13c9, 0x13ed, 0x1408, 0x1428, 0x1449, 0x146c, 0x1490, 0x14b0, 0x14d8, 0x1500, 0x152b
    .hword 0x1552, 0x157a, 0x15a8, 0x15cf, 0x15f7, 0x1619, 0x163a, 0x1657, 0x1675, 0x169f, 0x16a2, 0x16a2, 0x16a2, 0x16b0, 0x16bd, 0x16d7
    .hword 0x16e5, 0x16f3, 0x1701, 0x171b, 0x172b, 0x1739, 0x1742, 0x174a, 0x1752, 0x175c, 0x1768, 0x1779, 0x1799, 0x17ad, 0x17bf, 0x17d0
    .hword 0x17ea, 0x17ff, 0x1814, 0x1828, 0x183c, 0x184d, 0x185a, 0x1866, 0x187c, 0x1889, 0x18a0, 0x18b5, 0x18cd, 0x18cd, 0x18cd, 0x18cd
    .hword 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd
    .hword 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18cd, 0x18d8, 0x18e9, 0x18f3, 0x18ff, 0x1915, 0x192c, 0x1937
    .hword 0x193f, 0x1956, 0x1969, 0x197c, 0x198e, 0x19a9, 0x19bf, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc
    .hword 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19cc, 0x19e4, 0x19f4, 0x1a00, 0x1a1e
    .hword 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a2e, 0x1a3d, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a
    .hword 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a
    .hword 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a, 0x1a4a
    .hword 0x1a4a, 0x1a4a, 0x1a4a, 0x1a54, 0x1a5a, 0x1a63, 0x1a6c, 0x1a73, 0x1a79, 0x1a80, 0x1a87, 0x1a92, 0x1a9b, 0x1aa4, 0x1aae, 0x1ab6
    .hword 0x1ad3, 0x1b0a, 0x1b3e, 0x1b6b, 0x1b94, 0x1be0, 0x1c12, 0x1c48, 0x1c71, 0x1cac, 0x1cd2, 0x1d11, 0x1d1a, 0x1d33, 0x1d42, 0x1d46
    .hword 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a
    .hword 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d5a, 0x1d62
    .hword 0x1d6a, 0x1d72, 0x1d7a, 0x1d82, 0x1d8a, 0x1d99, 0x1da6, 0x1dc2, 0x1dd6, 0x1de4, 0x1df2, 0x1e04, 0x1e16, 0x1e24, 0x1e32, 0x1e3a
    .hword 0x1e42, 0x1e4a, 0x1e52, 0x1e5c, 0x1e66, 0x1e70, 0x1e7a, 0x1e84, 0x1e8e, 0x1e98, 0x1ea2, 0x1eab, 0x1eb4, 0x1eb4, 0x1eb4, 0x1eb4
    .hword 0x1eb4, 0x1eb4, 0x1eb4, 0x1eb4, 0x1eb4, 0x1eb4, 0x1eb4, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0
    .hword 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24a0, 0x24d4, 0x250b, 0x2533
    .hword 0x2558, 0x257d, 0x25b1, 0x25f5, 0x2639, 0x2681, 0x26bc, 0x26f6, 0x2735, 0x2775, 0x27b0, 0x27f6, 0x2838, 0x287e, 0x28cb, 0x2912
    .hword 0x2951, 0x295c, 0x295e, 0x2965, 0x296f, 0x2973, 0x297a, 0x29a8, 0x29de, 0x2a0d, 0x2a3e, 0x2a7b, 0x2a9c, 0x2abd, 0x2af1, 0x2b14
    .hword 0x2b3e, 0x2b6a, 0x2ba3, 0x2bd8, 0x2c0e, 0x2c46, 0x2c69, 0x2c94, 0x2cc1, 0x2ce2, 0x2d06, 0x2d2e, 0x2d57, 0x2d87, 0x2dae, 0x2dd5
    .hword 0x2df7, 0x2e23, 0x2e50, 0x2e79, 0x2eaa, 0x2ed6, 0x2efd, 0x2f22, 0x2f47, 0x2f74, 0x2f93, 0x2fbe, 0x2fdb, 0x3001, 0x3030, 0x3053
    .hword 0x3076, 0x3092, 0x30b9, 0x30d2, 0x30f6, 0x311d, 0x314a, 0x3175, 0x319d, 0x31b7, 0x31df, 0x3204, 0x3229, 0x324d, 0x3270, 0x329d
    .hword 0x32c5, 0x32ea, 0x3314, 0x3333, 0x3364, 0x338e, 0x33b2, 0x33d9, 0x3403, 0x3432, 0x3461, 0x3490, 0x34be, 0x34be, 0x34be, 0x34be
    .hword 0x34be, 0x34c4, 0x34ca, 0x34d0, 0x34d6, 0x34dc, 0x34e2, 0x34e8, 0x34ee, 0x34f4, 0x34fa, 0x3500, 0x3506, 0x350c, 0x3512, 0x3518
    .hword 0x351e, 0x3524, 0x352a, 0x3530, 0x3536, 0x353c, 0x3542, 0x3548, 0x354e, 0x3554, 0x355a, 0x3560, 0x3566, 0x356c, 0x3572, 0x3578
    .hword 0x357e, 0x3584, 0x358a, 0x3590, 0x3596, 0x359c, 0x35a2, 0x35a8, 0x35ae, 0x35b4, 0x35ba, 0x35c0, 0x35c6, 0x35cc, 0x35d2, 0x35d8
    .hword 0x35de, 0x35e4, 0x35ea, 0x35f0, 0x35f6, 0x35fc, 0x3602, 0x3608, 0x360e, 0x3614, 0x361a, 0x3620, 0x3626, 0x362c, 0x3632, 0x3638
    .hword 0x363e, 0x3644, 0x364a, 0x3650, 0x3656, 0x365c, 0x3662, 0x3668, 0x366e, 0x3674, 0x367a, 0x3680, 0x3686, 0x368c, 0x3692, 0x3698
    .hword 0x369e, 0x36a4, 0x36aa, 0x36b0, 0x36b6, 0x36bc, 0x36c2, 0x36c8, 0x36ce, 0x36d4, 0x36da, 0x36e0, 0x36e6, 0x36ec, 0x36f2, 0x36f8
    .hword 0x36fe, 0x3704, 0x370a, 0x3710, 0x3716, 0x371c, 0x3722, 0x3728, 0x372e, 0x3734, 0x373a, 0x3740, 0x3746, 0x374c, 0x3752, 0x3758
    .hword 0x375e, 0x3764, 0x376a, 0x3770, 0x3776, 0x377c, 0x3782, 0x3788, 0x378e, 0x3794, 0x379a, 0x37a0, 0x37a6, 0x37ac, 0x37b2, 0x37b8
    .hword 0x37be, 0x37c4, 0x37ca, 0x37d0, 0x37d6, 0x37dc, 0x37e2, 0x37e8, 0x37ee, 0x37f4, 0x37fa, 0x3800, 0x3806, 0x380c, 0x3812, 0x3818
    .hword 0x381e, 0x3824, 0x382a, 0x3830, 0x3836, 0x383c, 0x3842, 0x3848, 0x384e, 0x3854, 0x385a, 0x3860, 0x3866, 0x386c, 0x3872, 0x3878
    .hword 0x387e, 0x3884, 0x388a, 0x3890, 0x3896, 0x389c, 0x38a2, 0x38a8, 0x38ae, 0x38b4, 0x38ba, 0x38c0, 0x38c6, 0x38cc, 0x38d2, 0x38d8
    .hword 0x38de, 0x38e4, 0x38ea, 0x38f0, 0x38f6, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x38fc, 0x3904
    .hword 0x390c, 0x3917, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924, 0x3924
    .hword 0x3924, 0x392a, 0x39b3, 0x3a51, 0x3aee, 0x3b68, 0x3c0a, 0x3c97

gStringData:: @ 0x08372aa0

@ EN: ▷
sCursor:: @ 0x08372aa0
  .string "▷$"
  .string "データがありません$"
  .string "やめる$"
  .string "{RED}H$"
  .string "{RED}U$"
  .string "X$"
  .string "/$"
  .string ":$"
  .byte 0xD0, 0xFF
  .byte 0xE9, 0xFF

@ EN: The legendary Reploid Zero / awoke from a long slumber... / / / With Ciel's Resi
sRecap:: @ 0x08372ac0
  .include "src/data/strings/recap.inc"
  .string "あれから2ヶ月後$"

@ EN: 0
sNumber:: @ 0x08372d60
  .string "0$"
  .string "1$"
  .string "2$"
  .string "3$"
  .string "4$"
  .string "5$"
  .string "6$"
  .string "7$"
  .string "8$"
  .string "9$"

@ EN: Lv.F
sRanks:: @ 0x08372d74
  .string "レベルF$"
  .string "レベルE$"
  .string "レベルD$"
  .string "レベルC$"
  .string "レベルB$"
  .string "レベルA$"
  .string "レベルS$"

@ EN: DERELICT SPACECRAFT
sStageNames:: @ 0x08372d97
  .string "こわれたウチュウセン$"
  .string "アグニスかざんの基地$"
  .string "カイジョウのハイウェイあとち$"
  .string "ヘイキ再生工場$"
  .string "旧きょじゅうく$"
  .string "ミサイル工場$"
  .string "ゆうやみの砂ばく$"
  .string "アナトレーのモリ$"
  .string "コオリのゼンセン基地$"
  .string "エリアX-2$"
  .string "エネルギーしせつ$"
  .string "セツゲン$"
  .string "すいぼつしたトショカン$"
  .string "巨大エレベーター$"
  .string "アンダー・アルカディア$"

@ EN: AREA: AEGIS VOLCANO BASE / BOSS: BLAZIN' FLIZARD / MISSION: N.A. ARMY RECON
Text_MissionDesc_00:: @ 0x08372E32
	.string "エリア  :アグニスかざんの基地\n"
	.string "ボス   :ブレイジン・フリザード\n"
	.string "ミッション:ネオ・アルカディア軍テイサツ$"

@ EN: AREA: OCEANIC HWY RUINS / BOSS: CHILDRE INARABITTA / MISSION: TRACK D.E. SIGNAL
Text_MissionDesc_01:: @ 0x08372E6D
	.string "エリア  :カイジョウのハイウェイあとち\n"
	.string "ボス   :チルドレ・イナラビッタ\n"
	.string "ミッション:ダークエルフハンノウのカクニン$"

@ EN: AREA: W.R. FACTORY / BOSS: DEVILBAT SCHILT / MISSION: DESTROY FACTORY
Text_MissionDesc_02:: @ 0x08372EAA
	.string "エリア  :ヘイキ再生工場\n"
	.string "ボス   :ヘルバット・シルト\n"
	.string "ミッション:工場のハカイ$"

@ EN: AREA: OLD RESIDENTIAL / BOSS: DEATHTANZ MANTISK / MISSION: FIND DARK ELF
Text_MissionDesc_03:: @ 0x08372ED9
	.string "エリア  :旧きょじゅうく\n"
	.string "ボス   :デスタンツ・マンティスク\n"
	.string "ミッション:ダークエルフのチョウサ$"

@ EN: AREA: TWILIGHT DESERT / BOSS: ANUBIS NECROMANCESS V / MISSION: ENGAGE N.A. ARMY
Text_MissionDesc_04:: @ 0x08372F0D
	.string "エリア  :ゆうやみの砂ばく\n"
	.string "ボス   :アヌビステップ・ネクロマンセス5世\n"
	.string "ミッション:ネオ・アルカディア軍のゲイゲキ$"

@ EN: AREA: FOREST OF ANATRE / BOSS: HANUMACHINE R / MISSION: ENGAGE N.A. ARMY
Text_MissionDesc_05:: @ 0x08372F4D
	.string "エリア  :アナトレーのモリ\n"
	.string "ボス   :ハヌマシーンR\n"
	.string "ミッション:ネオ・アルカディア軍のゲイゲキ$"

@ EN: AREA: FRONTLINE ICE BASE / BOSS: BLIZZACK STAGGROFF R / MISSION: ENGAGE N.A. ARM
Text_MissionDesc_06:: @ 0x08372F81
	.string "エリア  :コオリのゼンセン基地\n"
	.string "ボス   :ブリザック・スタグロフR\n"
	.string "ミッション:ネオ・アルカディア軍のゲイゲキ$"

@ EN: AREA: AREA X-2 / BOSS: COPY X MARK II / MISSION: INFILTRATE N.A.
Text_MissionDesc_07:: @ 0x08372FBE
	.string "エリア  :エリアX-2\n"
	.string "ボス   :コピーエックスMK2\n"
	.string "ミッション:ネオ・アルカディアせんにゅう$"

@ EN: AREA: ENERGY FACILITY / BOSS: CUBIT FOXTAR / MISSION: SEARCH FACILITY
Text_MissionDesc_08:: @ 0x08372FF1
	.string "エリア  :エネルギーしせつ\n"
	.string "ボス   :キュービット・フォクスター\n"
	.string "ミッション:しせつのチョウサ$"

@ EN: AREA: SNOWY PLAINS / BOSS: GLACIER LE CACTANK / MISSION: RETRIEVE DATA
Text_MissionDesc_09:: @ 0x08373023
	.string "エリア  :セツゲン\n"
	.string "ボス   :グラチャー・レ・カクタンク\n"
	.string "ミッション:データのカイシュウ$"

@ EN: AREA: SUNKEN LIBRARY / BOSS: VOLTEEL BIBLIO / MISSION: RETRIEVE DATA FILE
Text_MissionDesc_10:: @ 0x08373052
	.string "エリア  :すいぼつしたトショカン\n"
	.string "ボス   :ヴォルティール・ビブリーオ\n"
	.string "ミッション:データファイルのカイシュウ$"

@ EN: AREA: GIANT ELEVATOR / BOSS: TRETISTA KELVERIAN / MISSION: SEARCH FACILITY
Text_MissionDesc_11:: @ 0x0837308C
	.string "エリア  :巨大エレベーター\n"
	.string "ボス   :トレテスタ・ケルベリアン\n"
	.string "ミッション:しせつのチョウサ$"

  .string "このミッションは、すでにしゅうりょうしています$"

@ EN: Martina
sCyberElfNames:: @ 0x083730d7
  .string "マルティナ$"
  .string "ミルピィ$"
  .string "エルピィ$"
  .string "シルピィ$"
  .string "レルピィ$"
  .string "アータン$"
  .string "ジクタン$"
  .string "モット$"
  .string "ドット$"
  .string "キュリフ$"
  .string "ルルフ$"
  .string "スルフ$"
  .string "ティリフ$"
  .string "ユリフ$"
  .string "ベリフ$"
  .string "ウィリフ$"
  .string "クリフ$"
  .string "スノック$"
  .string "マティック$"
  .string "ミヤック$"
  .string "アジック$"
  .string "トブック$"
  .string "ムラック$"
  .string "マイーラ$"
  .string "ミウーラ$"
  .string "コロップ$"
  .string "ソロップ$"
  .string "プチット$"
  .string "バレット$"
  .string "マーヤ$"
  .string "クワッパ$"
  .string "ガンブル$"
  .string "バーエイド$"
  .string "バーリーフ$"
  .string "ピタッパ$"
  .string "ピタップ$"
  .string "ビータック$"
  .string "ビーナイプ$"
  .string "アーチム$"
  .string "アーチル$"
  .string "バイッス$"
  .string "デルピーナ$"
  .string "リゼタス$"
  .string "コータス$"
  .string "シュータス$"
  .string "マルタス$"
  .string "イレタス$"
  .string "エネタス$"
  .string "バースラス$"
  .string "セーバラス$"
  .string "ロードラス$"
  .string "ブーメラス$"
  .string "クロクル$"
  .string "メットラス$"
  .string "メットリカ$"
  .string "メットルフ$"
  .string "メットレラ$"
  .string "メットロム$"
  .string "キーナイト$"
  .string "サーナイト$"
  .string "テーナイト$"
  .string "ストパーラ$"
  .string "ストピーナ$"
  .string "ストプール$"
  .string "ストペータ$"
  .string "ストポーサ$"
  .string "ハンマーガ$"
  .string "ハンマージ$"
  .string "ハンマーボ$"
  .string "エイーナ$"
  .string "エコーイ$"
  .string "エチューン$"
  .string "エナータ$"
  .string "エワーネ$"

@ EN: None
sCyberElfMenu:: @ 0x0837325e
  .string "なし$"
  .string "{RED}サテライト1そうびちゅう{RED_END}$"
  .string "{RED}サテライト2そうびちゅう{RED_END}$"
  .string "フュージョン系エルフは\n1回 使用すると\n死んでしまいます$"
  .string "サイバーエルフを\nそだてたり\n改造したりします$"
  .string "げんざい もっている\nサイバーエルフの\nリストが見られます$"

@ EN: Select and press A BUTTON.
sCyberElfMenu2:: @ 0x083732db
  .string "上下でえらんで Aボタンをおしてください$"
  .string "ライフにかんする\nサポートをする\nエルフたちです$"
  .string "プレイヤーのイドウ系\nアビリティーを高めたり\nコウゲキのほじょをする\nエルフたちです$"
  .string "エリアやミッションの\nデータやプレイヤーの\nブキ系アビリティーを\n高めるエルフたちです$"
  .string "左右でタグをえらんでください$"
  .string "✚ボタンでえらんで Aボタンをおしてください$"
  .string "✚ボタンでえらんで Aボタンをおしてください$"
  .string "ひつよう/もっているEC$"

@ EN: Upgrade one / level? / Yes No
Text_CyberElfGrowUp00:: @ 0x083733B4
	.string "1だんかい\n"
	.string "せいちょうさせますか？\n"
	.string "  はい   いいえ$"

@ EN: Upgrade to / Satellite? / Yes No
Text_CyberElfGrowUp01:: @ 0x083733D1
	.string "サテライトタイプに\n"
	.string "改造しますか？\n"
	.string "  はい   いいえ$"

@ EN: Upgrade to / Fusion type? / Yes No
Text_CyberElfGrowUp02:: @ 0x083733F0
	.string "フュージョンタイプに\n"
	.string "改造しますか？\n"
	.string "  はい   いいえ$"

@ EN: Upgrade to / new version? / Yes No
Text_CyberElfGrowUp03:: @ 0x08373410
	.string "ヴァージョンアップ\n"
	.string "改造しますか？\n"
	.string "  はい   いいえ$"

@ EN: Select and press A BUTTON.
str_0837342f:: @ 0x0837342f
  .string "✚ボタンでえらんで Aボタンをおしてください$"
  .string "✚ボタンでえらんで Aボタンをおしてください$"

@ EN: EC
sEC:: @ 0x0837345f
  .string "EC$"

@ EN: Satellite 1 / not equipped / with an Elf.
sNoSatelite:: @ 0x08373462
  .string "げんざいサテライト1に\nエルフはそうびされて\nいません$"
  .string "げんざいサテライト2に\nエルフはそうびされて\nいません$"

@ EN: Insufficient E-Crystals.
s_0837349a:: @ 0x0837349a
  .string "Eクリスタルがたりません$"
  .string "そうびちゅうは 改造できません$"
  .string "エルフがサブタンクにかわった！$"

@ EN: I double / your / vitality.
Text_Cyberelfs:: @ 0x083734c9
  .include "src/data/strings/cyberelf.inc"

@ EN: None
sNothing:: @ 0x0837413f
  .string "なし$"

@ EN: Your main weapon.
s_08374142:: @ 0x08374142
  .string "メインでそうびしているブキ$"
  .string "サブでそうびしているブキ$"
  .string "よぶんにとったライフエネルギーをためておけるタンク$"
  .string "そうびしているヘッドチップ$"
  .string "そうびしているボディチップ$"
  .string "そうびしているフットチップ$"

@ EN: Abort completed missions.
sEscape:: @ 0x083741a1
  .string "ボスをたおしたエリアなら、いつでもだっしゅつできる$"
  .string "A:エスケープ B:キャンセル$"
  .string "今はエスケープできません$"

@ EN: BUSTER SHOT
sWeaponNames:: @ 0x083741d9
  .string "バスターショット$"
  .string "ゼットセイバー$"
  .string "リコイルロッド$"
  .string "シールドブーメラン$"

@ EN: Remaining energy:
sSubtankRemaining:: @ 0x083741fc
  .string "エネルギーざんりょう:$"

@ EN: A normal Head Chip.
sChipEffects:: @ 0x08374208
  .string "ノーマルじょうたいのヘッドチップ$"
  .string "たち止まっていると自動的に体力をかいふくしてくれる$"
  .string "自動的にブキをチャージしてくれる$"
  .string "ブキのチャージ時間がはやくなる$"
  .string "ノーマルじょうたいのボディチップ$"
  .string "しずんだり くずれたりする地形を ムコウにする$"
  .string "コウゲキをうけても あとずさりしなくなる$"
  .string "カミナリぞくせいのコウゲキがカノウになる$"
  .string "ホノオぞくせいのコウゲキがカノウになる$"
  .string "コオリぞくせいのコウゲキがカノウになる$"
  .string "ノーマルじょうたいのフットチップ$"
  .string "すいめんをジャンプできる$"
  .string "2だんジャンプができる$"
  .string "とくていのテキをダッシュで すりぬけられる$"
  .string "はしるはやさがアップする$"
  .string "すべる地めんの上でも ふつうに はしれる$"
  .string "かべから ずりおちるそくどが おそくなる$"
  .string "すべてのフットチップの力が使えるようになる$"

sElfVoices: @ 0x0837436d
  .string "わ〜、いただきます！$"
  .string "わ〜い、わ〜い\nEクリスタルだ！$"
  .string "ありがとう〜ゼロ！$"
  .string "おんにきるよ！\nゼロ！$"
  .string "ゼロ、ここまで\nそだててくれて\nありがとう$"
  .string "なにもかも\nゼロのおかげだよ！\nありがとう！$"
  .string "ごちそうさまでした！$"
  .string "いただきます！$"
  .string "こんなんじゃ\nたりないよ\nもっとちょうだ〜い$"
  .string "おなかすいたよう\nもっとほしいよう！$"
  .string "もうすこしたべれば\n大きくなれるわ$"
  .string "もうちょっとで\nパワーアップするぜ$"
  .string "Eクリスタル\nう〜んとたべて\nゼロの力になりたいな$"
  .string "Eクリスタルの力で\nパワーアップしたいな$"
  .string "{RED}シメイを終えました{RED_END}$"

@ EN: OK to save the current data? / YES / NO
sSave:: @ 0x0837446c
  .string "データをセーブしますか？\n  はい\n  いいえ$"
  .string "どこにデータをセーブしますか？$"
  .string "データをセーブしました$"
  .string "このデータに上がきしていいですか？\n  はい\n  いいえ$"
  .string "データを上がきセーブしました$"

@ EN: ReflectLaser
sUnused_083744ce:: @ 0x083744ce
  .string "「NEWレジスタンスベース」$"
  .string "「メンテナンス・ルーム」$"

@ EN: ReflectLaser
sExSkillNames:: @ 0x083744ea
  .string "リフレクトレーザー$"
  .string "Vショット$"
  .string "バーストショット$"
  .string "ブリザードアロー$"
  .string "レップウゲキ$"
  .string "ラクサイガ$"
  .string "テンレツジン$"
  .string "ザンエイダン$"
  .string "サウザンドスラッシュ$"
  .string "ソウルランチャー$"
  .string "クロールシールド$"
  .string "サーキュラシールド$"

@ EN: None learned
Text_ExskillDesc_00:: @ 0x0837454E
	.string "おぼえていない$"

@ EN: BUSTER SHOT / Reflects off / of walls.
Text_ExskillDesc_01:: @ 0x08374556
	.string "{RED}バスターショット{RED_END}\n"
	.string "かべやゆかにあたると\n"
	.string "はんしゃする$"

@ EN: BUSTER SHOT / Splits shot / when used / with Thunder / Body Chip.
Text_ExskillDesc_02:: @ 0x08374573
	.string "{RED}バスターショット{RED_END}\n"
	.string "ボディチップを\n"
	.string "サンダーにして使うと\n"
	.string "上下にわかれたショットを\n"
	.string "うつことができる$"

@ EN: BUSTER SHOT / Explodes / when used / with Flame / Body Chip.
Text_ExskillDesc_03:: @ 0x083745AA
	.string "{RED}バスターショット{RED_END}\n"
	.string "ボディチップを\n"
	.string "フレイムにして使うと\n"
	.string "バクフウで テキを\n"
	.string "まきこむことができる$"

@ EN: BUSTER SHOT / Shoots ice / when used / with Ice / Body Chip.
Text_ExskillDesc_04:: @ 0x083745DE
	.string "{RED}バスターショット{RED_END}\n"
	.string "ボディチップを\n"
	.string "アイスにして使うと\n"
	.string "コオリのヤイバが\n"
	.string "とんでいく$"

@ EN: Z SABER / Skewer foes / by dashing / with saber.
Text_ExskillDesc_05:: @ 0x0837460B
	.string "{RED}ゼットセイバー{RED_END}\n"
	.string "ダッシュをしながら\n"
	.string "セイバーでコウゲキすると\n"
	.string "テキをつきさす$"

@ EN: Z SABER / Press Down / and slash / during fall / or slide to / skewer foes / bel
Text_ExskillDesc_06:: @ 0x08374634
	.string "{RED}ゼットセイバー{RED_END}\n"
	.string "ジャンプ中や らっか中に\n"
	.string "✚ボタンの下を\n"
	.string "おしながら\n"
	.string "セイバーでコウゲキすると\n"
	.string "真下にいるテキを\n"
	.string "つきさすことができる$"

@ EN: Z SABER / Press Up and / use Saber / to slice / upward.
Text_ExskillDesc_07:: @ 0x08374680
	.string "{RED}ゼットセイバー{RED_END}\n"
	.string "✚ボタンの上を\n"
	.string "おしながら\n"
	.string "セイバーでコウゲキすると\n"
	.string "ジャンプできりあげる$"

@ EN: Z SABER / Press Down / and slash / to shoot a / blade ahead.
Text_ExskillDesc_08:: @ 0x083746B2
	.string "{RED}ゼットセイバー{RED_END}\n"
	.string "✚ボタンの下を\n"
	.string "おしながら\n"
	.string "セイバーでコウゲキすると\n"
	.string "前方にヤイバがとんでいく$"

@ EN: RECOIL ROD / Rapidly use / Rod for / multi atk.
Text_ExskillDesc_09:: @ 0x083746E8
	.string "{RED}リコイルロッド{RED_END}\n"
	.string "ロッドをレンダすると\n"
	.string "前方にレンゾクで\n"
	.string "コウゲキができる$"

@ EN: RECOIL ROD / Press Up and / charge Rod / to shoot / above.
Text_ExskillDesc_10:: @ 0x08374711
	.string "{RED}リコイルロッド{RED_END}\n"
	.string "✚ボタンの上を\n"
	.string "おしながら ロッドを\n"
	.string "チャージでコウゲキすると\n"
	.string "上に向けて タマをうてる$"

@ EN: S.BOOMERANG / S.Boomerang / skims the / ground.
Text_ExskillDesc_11:: @ 0x0837474C
	.string "{RED}シールドブーメラン{RED_END}\n"
	.string "地形にそって\n"
	.string "シールドブーメランが\n"
	.string "とんでいく$"

@ EN: S.BOOMERANG / Press Down / and use S. / Boomerang / to form a / shield.
Text_ExskillDesc_12:: @ 0x08374772
	.string "{RED}シールドブーメラン{RED_END}\n"
	.string "✚ボタンの下を\n"
	.string "おしながら\n"
	.string "シールドブーメランを\n"
	.string "なげると 自分のまわりを\n"
	.string "シールドがまわる$"

@ EN: None learned
Text_ExskillDesc_13:: @ 0x083747B1
	.string "おぼえていない\n"
	.string "$"

@ EN: Press A BUTTON to analyze.
sDiskAnalysisGuide:: @ 0x083747ba
  .string "✚ボタンでえらんで Aボタンでカイセキできます$"
  .string "Bボタンでしゅうりょうします$"
  .string "NO.$"
  .string "このディスクは\nカイセキされていません$"

@ EN: \xF7 NEW GAME
sTitleMenu:: @ 0x083747fa
  .string "{F7 0x00}はじめから${F7 0x01}はじめから$"
  .string "{F7 0x00}つづきから${F7 0x01}つづきから$"
  .string "{F7 0x00}ミニゲーム${F7 0x01}ミニゲーム$"

@ EN: \xF74PLEASE WAIT...
sConnections_0:: @ 0x0837482a
  .string "{F7 0x05}つうしん まちうけちゅう$"
@ EN: \xF7 B BUTTON: CANCEL
sConnections_1:: @ 0x08374839
  .string "{F7 0x00}Bボタンでキャンセル$"
@ EN: \xF74 Exe 4 is / \xF74selecting chip.
sConnections_2:: @ 0x08374846
  .string "{F7 0x05}    エグゼ4が\n{F7 0x05}チップをせんたくちゅうです$"
@ EN: \xF73LINK / TERMINATED.
sConnections_3:: @ 0x08374862
  .string "{F7 0x04}つうしんエラーが\nはっせいしました$"

@ EN: \xF7 CONTINUE
sGameOver:: @ 0x08374876
  .string "{F7 0x00}    コンティニュー${F7 0x01}    コンティニュー$"
  .string " {F7 0x00}セーブした場所からやりなおす$ {F7 0x01}セーブした場所からやりなおす$"
  .string "{F7 0x00}    ゲームをやめる${F7 0x01}    ゲームをやめる$"

@ EN: \xF7 ZERO
sMiniGameNames:: @ 0x083748d2
  .string " {F7 0x00}  ゼロ$ {F7 0x01}  ゼロ$"
  .string "{F7 0x00}  シエル${F7 0x01}  シエル$"
  .string "{F7 0x00}コピーエックス${F7 0x01}コピーエックス$"
  .string " {F7 0x00}ハルピュイア$ {F7 0x01}ハルピュイア$"
  .string " {F7 0x00}ファーブニル$ {F7 0x01}ファーブニル$"
  .string " {F7 0x00}レヴィアタン$ {F7 0x01}レヴィアタン$"
  .string "{F7 0x00} ファントム${F7 0x01} ファントム$"

# size is 1516 bytes
@ EN: STAFF / / / / / DIRECTOR / RYOTA ITO / YOSHINORI KAWANO / / / GAME DESIGNER / YO
sStaffRoll:: @ 0x08374954
  .include "src/data/strings/staff_roll.inc"

@ EN: AUTO-CHARGE / (Head Chip) / / Automatic / charge to / your weapon.
sDiskContents:: @ 0x08374f40
  .include "src/data/strings/disk.inc"

@ EN: 000
sDiskNumbers:: @ 0x08375f5e
  .include "src/data/strings/disk_number.inc"

@ EN: Dr. Weil
sSubmergedLibFileNames:: @ 0x0837639c
  .string "バイルのデータ$"
  .string "オメガのデータ$"
  .string "ダークエルフのデータ$"
  .string "ヨウセイ戦争のデータ$"

@ size is 996 bytes
@ EN: RULES
Text_MiniGameRules:: @ 0x083763c4
  .string "{RED}ルール{RED_END}$"

@ EN: Aim with +Control Pad and / use B BUTTON to hit / Mellnets with Recoil Rod. / Di
Text_MinigameDesc_Zero::
	.string "6方向から とんでくる メルネットを\n"
	.string "✚ボタンで ねらいをさだめ、\n"
	.string "Bボタンのリコイルロッドで コウゲキします。\n"
	.string "いろのちがう メルネットは、かたいので\n"
	.string "2ヒットさせるか、チャージこうげきで、\n"
	.string "ふきとばさなくてはいけません。\n"
	.string "3回ミスをすると ゲームオーバーです。$"

@ EN: Guide 5 colored jewels to / the right colored beaker. / The jewels will take all
Text_MinigameDesc_Ciel::
	.string "上から おちてくる 5しょくのジュエルを\n"
	.string "ただしい いろのビーカーへと みちびきます。\n"
	.string "ジュエルの とおりみちに、よこの あなが\n"
	.string "あいている ばあいは、そちらに行きます。\n"
	.string "AボタンかBボタンで とおりみちに フタをしたり\n"
	.string "外したりして、うまく ゆうどうしてください。\n"
	.string "3回ミスをすると ゲームオーバーです。$"

@ EN: Using 3 elements, destroy / panels on a belt conveyor. / The L BUTTON and R BUTT
Text_MinigameDesc_X::
	.string "サンダー・フレイム・アイスのエレメントを\n"
	.string "きりかえて、ベルトコンベアをながれてくるパネルを\n"
	.string "ハカイしてください。Lボタン・Rボタンで\n"
	.string "エレメントをきりかえて、Bボタンでコウゲキします。\n"
	.string "サンダーはアイス、アイスはフレイム、フレイムは\n"
	.string "サンダーのコウゲキでハカイできます。\n"
	.string "3回ミスをすると ゲームオーバーです。$"

@ EN: Riding Aztec Falcon jump / over obstacles and slash / foes. A BUTTON to jump\xED
Text_MinigameDesc_Harpuia::
	.string "アステファルコンにのり、しょうがいぶつを\n"
	.string "ジャンプでとびこえ、\n"
	.string "テキをブレードで コウゲキします。\n"
	.string "Aボタンでジャンプ、Bボタンでコウゲキです。\n"
	.string "しょうがいぶつやテキに3回当たるか、はさまれたり\n"
	.string "あなにおちたりすると ゲームオーバーです。$"

@ EN: Stop Carryarms from taking / the items. +Control Pad / to move Fefnir\xED B BUTT
Text_MinigameDesc_Fefnir::
	.string "キャリアームに ブッシをうばわれないように\n"
	.string "✚ボタンで左右にファーブニルを動かし、\n"
	.string "Bボタンでメテオレインを上にハッシャします。\n"
	.string "ブッシをもったキャリアームを高いイチで たおすと\n"
	.string "ブッシがおちるまでの間、とくてんが入ります。\n"
	.string "ブッシが 1つでも エリアの外に\n"
	.string "もっていかれてしまうと、ゲームオーバーです。$"

@ EN: Move Leviathan w/ +Control / Pad\xED B BUTTON for spear. / Earn score and time b
Text_MinigameDesc_Leviathan::
	.string "✚ボタンでレヴィアタンを左右に動かし、\n"
	.string "Bボタンでスピアを下につきます。\n"
	.string "うみの生きものをころさないように\n"
	.string "うまく メカニロイドだけをたおして、\n"
	.string "スコアとタイムをかせいでください。\n"
	.string "のがさずレンゾクでつくと 高とくてんです。\n"
	.string "タイムが0になると ゲームオーバーです。$"

@ EN: Jump from one shuriken to / another. +Control Pad to / move\xED A BUTTON to jump
Text_MinigameDesc_Phantom::
	.string "シュリケンからシュリケンへと おちないように\n"
	.string "✚ボタンでファントムを左右に動かしながら\n"
	.string "Aボタンでジャンプして とびうつります。\n"
	.string "しょうがいぶつに3回当たるか、シュリケンから\n"
	.string "おちてしまうと ゲームオーバーです。$"
