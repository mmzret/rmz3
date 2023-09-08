#ifndef GUARD_RMZ3_CONST_MOTION_H
#define GUARD_RMZ3_CONST_MOTION_H

// Dynamic Motion (DM, Motion has multiple scene(= multiple metasprites))
#define DM000_ZERO_NEUTRAL 0
#define DM001_ZERO_DYING 1
#define DM002_ZERO_RUN 2
#define DM003_ZERO_DASH 3
#define DM004_ZERO_AIR 4  // All Air motion (not attacking)
#define DM005_ZERO_WALL 5
#define DM006_ZERO_WALL_AIR 6
#define DM007_ZERO_LADDER 7
#define DM008_ZERO_BUSTER 8
#define DM009_ZERO_BUSTER_WALK 9
#define DM010_ZERO_BUSTER_DASH 10
#define DM011_ZERO_BUSTER_AIR 11
#define DM012_ZERO_BUSTER_WALL 12
#define DM013_ZERO_BUSTER_LADDER 13
#define DM014_ZERO_SABER_TRIPLE1 14
#define DM015_ZERO_SABER_TRIPLE2 15
#define DM016_ZERO_SABER_TRIPLE3 16
#define DM017_ZERO_SABER_SLASH_UP 17
#define DM018_ZERO_SABER_TENRETSUJIN 18  // Split Heavens
#define DM019_ZERO_SABER_ZANEIDAN 19     // Throw Blade
#define DM020_ZERO_SABER_CHARGE 20
#define DM021_ZERO_SABER_RUN_1 21
#define DM022_ZERO_SABER_RUN_2 22
#define DM023_ZERO_SABER_DASH 23
#define DM024_ZERO_GALE 24  // Gale Attack
#define DM025_ZERO_SABER_AIR 25
#define DM026_ZERO_SABER_AIR_ROLLING 26
#define DM027_ZERO_SABER_SMASH 27  // ラクサイガ
#define DM028_ZERO_SABER_WALL 28
#define DM029_ZERO_SABER_LADDER 29
#define DM030_ZERO_ROD 30
#define DM031_ZERO_ROD_UP 31
#define DM032_ZERO_ROD_DOWN 32
#define DM033_ZERO_ROD_AIR 33
#define DM034_ZERO_ROD_UP_AIR 34
#define DM035_ZERO_ROD_DOWN_AIR 35
#define DM036_ZERO_ROD_WALL 36
#define DM037_ZERO_ROD_LADDER 37
#define DM040_ZERO_SHIELD_GUARD 40
#define DM041_ZERO_SHIELD_THROW 41
#define DM042_ZERO_SHIELD_WALK 42  // シールド構えながらの歩き
#define DM043_ZERO_SHIELD_AIR 43   // シールド構え時の空中
#define DM044_ZERO_SHIELD_THROW_AIR 44
#define DM045_ZERO_SHIELD_WALL 45  // シールド構えながらの壁ずり
#define DM046_ZERO_SHIELD_THROW_WALL 46
#define DM047_ZERO_SHIELD_LADDER 47  // シールド構えながらのハシゴ
#define DM048_ZERO_SHIELD_THROW_LADDER 48
#define DM049_ZERO_STUN 49
#define DM050_ZERO_STUN 50
#define DM051_ZERO_UNK 51
#define DM052_ZERO_TELEPORT_START 52   // 転送時の仁王立ち
#define DM053_ZERO_TELEPORT_END 53     // 転送時の伏せ
#define DM054_ZERO_DOOR_3D 54          // 3Dドア(ベース、サイバー空間)
#define DM055_ZERO_ROD_CHARGE 55       // 横方向へのチャージリコイル
#define DM056_ZERO_ROD_CHARGE_UP 56    // 上方向へのチャージリコイル
#define DM057_ZERO_ROD_CHARGE_DOWN 57  // 下方向へのチャージリコイル
#define DM058_ZERO_ROD_CHARGE_AIR 58
#define DM059_ZERO_ROD_CHARGE_UP_AIR 59
#define DM060_ZERO_ROD_CHARGE_DOWN_AIR 60
#define DM061_ZERO_ROD_CHARGE_WALL 61
#define DM062_ZERO_ROD_CHARGE_LADDER 62
#define DM063_OMEGA_ZERO 63  // オメガゼロ専用のいろんなモーション
// Weapon
#define DM064_SABER_CHARGE 64
#define DM080_SEMI_BUSTER 80
#define DM081_BURST_SHOT 81
#define DM082_BLIZZ_ARROW 82
#define DM083_BURST_SHOT_FIREWORK 83
#define DM088_TRIPLE_SLASH_1 88
#define DM089_TRIPLE_SLASH_2 89
#define DM090_TRIPLE_SLASH_3 90
#define DM091_SLUSH_UP 91
#define DM092_TENRETSUJIN 92
#define DM093_ZANEIDAN 93
#define DM094_SABER_CHARGE 94
#define DM095_SABER 95
#define DM096_SABER 96
#define DM097_GALE_ATTACK 97
#define DM098_SABER_CHARGE 98
#define DM099_SABER 99
#define DM100_RAKUSAIGA 100
#define DM101_SABER_CHARGE_AIR 101
#define DM102_SABER 102
#define DM103_SOUL_LAUNCHAR_FLAME 103
#define DM104_UNK 104
#define DM105_UNK 105
#define DM106_UNK 106
#define DM107_UNK 107
#define DM108_UNK 108
#define DM109_UNK 109
#define DM110_UNK 110
#define DM111_UNK 111
#define DM112_UNK 112
#define DM113_UNK 113
#define DM114_UNK 114
#define DM115_UNK 115
#define DM116_UNK 116
#define DM117_UNK 117
#define DM118_UNK 118
#define DM119_UNK 119
#define DM120_UNK 120
#define DM121_UNK 121
#define DM122_UNK 122
#define DM123_UNK 123
#define DM124_UNK 124
#define DM125_UNK 125
#define DM126_UNK 126
#define DM127_UNK 127
#define DM128_UNK 128
#define DM129_UNK 129
#define DM130_UNK 130
#define DM131_UNK 131
#define DM132_UNK 132
#define DM133_LEMON 133
#define DM134_UNK 134
#define DM135_UNK 135
#define DM136_UNK 136
#define DM137_UNK 137
#define DM138_UNK 138
#define DM139_UNK 139
#define DM140_UNK 140
#define DM141_UNK 141
#define DM142_UNK 142
#define DM144_CYBERELF_NURSE 144
#define DM145_CYBERELF_ANIMAL 145
#define DM146_CYBERELF_HACKER 146
#define DM147_CYBERELF_PARTICLE 147
#define DM160_MEGAMILPA 160
#define DM161_FEFNIR 161
#define DM162_BLAZIN 162
#define DM163_BLAZIN_PROJECTILE 163
#define DM164_CHILDRE 164
#define DM165_VOLTEEL 165
#define DM166_VOLTEEL_TAIL 166
#define DM167_DEATHTANZ 167
#define DM168_HELLBAT 168
#define DM169_HELLBAT_LASER 169
#define DM170_HELLBAT_BAT 170
#define DM171_TRETISTA 171
#define DM172_TRETISTA_HELLBOUNCER 172
#define DM173_TRETISTA_PROJECTILE 173
#define DM174_TRETISTA_LASERCLAW 174
#define DM175_ANUBIS 175
#define DM176_CUBIT 176
#define DM177_CUBIT_FLAME 177
#define DM178_GLACIERLE 178
#define DM179_COPY_X 179
#define DM180_BLIZZACK 180
#define DM181_HANUMACHINE 181
#define DM182_OMEGA_ZX 182
#define DM183_OMEGA_ZX_EYE_GLOW 183
#define DM184_OMEGA_ZX_EXCEED_BUSTER 184
#define DM185_OMEGA_ZX_BINDING_BALL 185
#define DM186_OMEGA_ZX_SPARK_CHASER 186
#define DM187_OMEGA_ZX_TRIPLE_LASER 187
#define DM188_PHANTOM 188
#define DM189_LEVIATHAN 189
#define DM190_HARPUIA 190
#define DM191_AZTEC_FALCON 191
#define DM192_OLA_DOOR 192   // Old Life Area door
#define DM193_BASE_DOOR 193  // Resistance Base door
#define DM194_CIEL 194
#define DM195_UNK 195
#define DM196_ZERO_WALK 196
#define DM197_WEIL 197
#define DM198_CYBERSPACE_DOOR 198
#define DM199_BOSS_EXPLOSION 199

#define DYNAMIC_MOTION_COUNT 200

// Static Motion (SM, Motion has a single scene(= a single metasprite))

#define SM000_BATTLE_EFFECT 0
#define SM001_UNK 1
#define SM002_LEMON 2
#define SM003_EMOTION_BUBBLE 3
#define SM004_SHOTCOUNTER 4
#define SM005_GRAVEL 5
#define SM006_BATRING 6
#define SM007_GRAND_CANNON 7
#define SM008_PILLAR_CANNON 8
#define SM009_OMEGA_ARM 9
#define SM010_OMEGA_RING 10
#define SM011_OMEGA_RECOVER 11
#define SM012_UNK 12
#define SM013_SHRIMPOLIN 13
#define SM014_CHIPICON 14
#define SM015_MENUITEM 15
#define SM016_ICEBON 16
#define SM017_ICEBON_ICE 17
#define SM018_UNK 18
#define SM019_PANTHEON_HUNTER 19
#define SM020_PANTHEON_GUARDIAN 20
#define SM021_TOP_GABYOALL 21
#define SM022_FLOPPER 22
#define SM023_GYRO_CANNON 23
#define SM024_SHARKSEAL_X 24
#define SM025_LAMPLORT 25
#define SM026_UNK 26
#define SM027_UNK 27
#define SM028_UNK 28
#define SM029_LEMMINGLES 29
#define SM030_LEMMINGLES_NEST 30
#define SM031_UNK 31
#define SM032_UNK 32
#define SM033_UNK 33
#define SM034_CARRYARM 34
#define SM035_CONTAINER 35
#define SM036_UNK 36
#define SM037_EAR_SHOT 37
#define SM038_UNK 38
#define SM039_PANTHEON_AQUA 39
#define SM040_SNAKECORD 40
#define SM041_HAMMER 41
#define SM042_PURPLE_NERPLE 42
#define SM043_WORMER 43
#define SM044_WORMER_ROCK_DRONE 44
#define SM045_UNK 45
#define SM046_VOLCAIRE 46
#define SM047_TILE_CANNON 47
#define SM048_BABY_ELF 48
#define SM049_CREA_PREA 49
#define SM050_CREA_PREA 50
#define SM051_CREA_PREA 51
#define SM052_CREA_PREA 52
#define SM053_SHELLUNO 53
#define SM054_DEATHTANZ_ROCK 54
#define SM055_DEATHTANZ_PROJECTILE 55
#define SM056_HEAVY_CANNON 56
#define SM057_GEYSER 57  // 間欠泉
#define SM058_VOLCANO_RISING_PLATFORM 58
#define SM059_LAVA_PLATFORM 59
#define SM060_EXLIFE_INDICATOR 60  // Z x 9 みたいなやつ
#define SM061_UNK 61
#define SM062_BEETANK 62
#define SM063_SWORDY 63
#define SM064_ICE_BALL 64
#define SM065_PUFFY 65
#define SM066_PUFFY_BUBBLE 66
#define SM067_CROSSBYNE 67
#define SM068_OLD_RESIDENTIAL_FALL_ROCK 68
#define SM069_EXSKILL_ICON 69
#define SM070_BEESERVER 70
#define SM071_MELLNET 71
#define SM072_UNK 72
#define SM073_ANUBIS_ROD 73
#define SM074_ANUBIS_SAND 74
#define SM075_ANUBIS_COFFIN 75
#define SM076_PANTHEON_ZOMBIE 76
#define SM077_PANTHEON_AQUA_MOD 77
#define SM078_PANTHEON_AQUA_MOD_PROJECTILE 78
#define SM079_PANTHEON_AQUA_MOD_ROCK 79
#define SM080_UNK 80
#define SM081_DARK_ELF 81
#define SM082_ELF_MENU 82
#define SM083_ELF_MENU_ICON 83
#define SM084_LOCOMO_IF 84
#define SM085_LOCOMO_IF_PLATFORM 85
#define SM086_LOCOMO_IF_FLAME 86
#define SM087_LOCOMO_IF_FROST 87
#define SM088_UNK_ICE 88
#define SM089_GLACIERLE_ARM 89
#define SM090_ICICLE 90
#define SM091_UNK 91
// ...
#define SM170_ECRYSTAL 170
#define SM171_ECRYSTAL_BALL 171
#define SM172_ECRYSTAL_GREEN 172
#define SM173_EXLIFE 173
#define SM174_EXLIFE_BLUE 174
#define SM175_EXLIFE_GREEN 175
#define SM176_RESULT_DISK 176
#define SM177_RESULT_DISK_BLUE 177
#define SM178_RESULT_DISK_RED 178
#define SM179_UNK 179
#define SM180_CHILDRE_SHIP 180
#define SM181_SEA_LEVEL_BUTTON 181
#define SM182_UNK 182
#define SM183_CHILDRE_SHIP_SONIC_WAVE 183
#define SM184_X 184
#define SM185_OMEGA_ZX_FLOATING_ROCK 185
#define SM186_UNK 186
#define SM187_ALOUETTE 187
#define SM188_KISS 188
#define SM189_FAUCON 189
#define SM190_HIRONDELLE 190
#define SM191_AUTRUCHE 191
#define SM192_ROCINOLLE 192
#define SM193_DOIGT 193
#define SM194_CERVEAU 194
#define SM195_HIBOU 195
#define SM196_ANDREW 196
#define SM197_MENART 197
#define SM198_PERROQUIET 198
#define SM199_PIC 199
#define SM200_SMOKE 200
#define SM201_OPERATOR 201
#define SM202_CMD_ROOM_UNK 202
#define SM203_ICE_BLOCK 203
#define SM204_UNK 204
#define SM205_MISSION_MUGSHOT 205
#define SM206_MISSION_MUGSHOT 206
#define SM207_MISSION_DONE_MUGSHOT 207
#define SM208_MISSION_MUGSHOT 208
#define SM209_NUMBER 209
#define SM210_LEVER_SWITCH 210
#define SM211_MENU_CURSOR_BORDER 211
#define SM212_PANTHEON_FIST 212
#define SM213_CATTATANK 213
#define SM214_SPEAROOK 214
#define SM215_UNK 215
#define SM216_CAT_1 216
#define SM217_CAT_2 217
#define SM218_SEAGULL 218
#define SM219_SHELLCRAWLER 219
#define SM220_CANNON_HOPPER 220
#define SM221_METTAUR 221
#define SM222_STRUCTURAL_STEEL 222  // 鉄骨, 形鋼
#define SM223_LIGHT_SWITCH 223
#define SM224_RUBBLE 224
#define SM225_OMEGA_WHITE 225
#define SM226_CRASH_CONTAINER 226
#define SM227_CRASH_CONTAINER 227
#define SM228_CRASH_CONTAINER 228
#define SM229_SUBTANK 229
#define SM230_FLYING_FISH 230
#define SM231_PLANT 231
#define SM232_UNK 232
#define SM233_UNK 233
#define SM234_UNK 234
#define SM235_UNK 235
#define SM236_SPARK 236
#define SM237_ROCK 237
#define SM238_UNK 238
#define SM239_ANGEL_FISH 239
#define SM240_SEA_BREAM 240
#define SM241_CRAB 241
#define SM242_FISH_SCHOOL 242
#define SM243_UNK 243
#define SM244_COPYX_MINIGAME_SLOT 244
#define SM245_HELLBAT_HUMAN 245
#define SM246_CHILDRE_HUMAN 246
#define SM247_BLAZIN_HUMAN 247
#define SM248_DEATHTANZ_HUMAN 248
#define SM249_GLACIERLE_HUMAN 249
#define SM250_CUBIT_HUMAN 250
#define SM251_TRETISTA_HUMAN 251
#define SM252_VOLTEEL_HUMAN 252
#define SM253_UNK 253

#define STATIC_MOTION_COUNT 254

#endif  // GUARD_RMZ3_CONST_MOTION_H