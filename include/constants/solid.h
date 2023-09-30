#ifndef GUARD_RMZ3_CONST_SOLID_H
#define GUARD_RMZ3_CONST_SOLID_H

#define SOLID_ICEBON 0
#define SOLID_ICEBON_ICE 1
#define SOLID_DOOR_2D_BLUE 2
#define SOLID_UNK_003 3
#define SOLID_UNK_004 4
#define SOLID_HEAVY_CANNON 5
#define SOLID_LAVA_GEYSER_PLATFORM 6
#define SOLID_LAVA_GEYSER 7
#define SOLID_LAVA_RIVER_PLATFORM 8
#define SOLID_DOOR_3D 9
#define SOLID_UNK_010 10
#define SOLID_UNK_011 11
#define SOLID_ANUBIS_COFFIN 12
#define SOLID_UNK_013 13
#define SOLID_LOCOMOIF_PLATFORM 14
#define SOLID_GLACIERLE_ARM 15
#define SOLID_UNK_016 16
#define SOLID_UNK_017 17
#define SOLID_UNK_018 18
#define SOLID_BASE_ELEVATOR 19
#define SOLID_DOOR_2D_GRAY 20
#define SOLID_SCRIPT_ACTOR 21
#define SOLID_UNK_022 22
#define SOLID_UNK_023 23
#define SOLID_PHANTOM_TELEPORTER 24
#define SOLID_UNK_025 25
#define SOLID_ICE_BLOCK 26
#define SOLID_UNK_027 27
#define SOLID_MG_NINJASTAR 28
#define SOLID_MOB_NPC 29
#define SOLID_MAIN_NPC 30
#define SOLID_CYBERSPACE_DOOR 31
#define SOLID_LIGHT_SWITCH 32  // In energy facility
#define SOLID_UNK_033 33
#define SOLID_UNK_034 34
#define SOLID_CONTAINER 35
#define SOLID_UNK_036 36
#define SOLID_UNK_037 37
#define SOLID_SEAGULLS 38  // カモメ
#define SOLID_CAT 39
#define SOLID_MOD_PLANT 40
#define SOLID_VOLCANO_COFFIN 41
#define SOLID_UNK_042 42
#define SOLID_UNK_043 43
#define SOLID_UNK_044 44
#define SOLID_GE_PIER 45  // 巨大エレベータのエレベータにのるための桟橋
#define SOLID_GE_PLATFORM 46
#define SOLID_ANATRE_CUBE 47  // アナトレーの森でリコイルロッドで押せるキューブ
#define SOLID_CIEL_COMPUTER 48
#define SOLID_GRAFFITI 49
#define SOLID_STRUCTURAL_STEEL 50
#define SOLID_MOD_ELF 51
#define SOLID_UNK_052 52
#define SOLID_UNK_053 53
#define SOLID_SEA_LV_BTN 54
#define SOLID_CHILDRE_SHIP 55

#define SOLID_ENTITY_COUNT 56

// --------------------------------------------

// Solid.id is 9(SOLID_DOOR_3D)
#define DOOR3D_ANDREW_1UP 3

// --------------------------------------------

// Solid.id が　 21 のエンティティ == スクリプトの登場人物(Actor)

// Solid.work[0]
#define ACTOR_DUMMY 0
#define ACTOR_ZERO_WALK 1              // プロローグで歩行するゼロ
#define ACTOR_CIEL_WALK 2              // プロローグで歩行するシエル
#define ACTOR_CRASHED_PANTHEON 9       // オメガと四天王の戦闘に巻き込まれて死ぬパンテオン3匹
#define ACTOR_LEVIATHAN_11 11          // ミニゲームのレヴィアタン？
#define ACTOR_FEFNIR_12 12             // ミニゲームのファーブニル？
#define ACTOR_SAVE_SELECT_CIEL 14      // 続きからでセーブデータを選ぶときのシエル
#define ACTOR_CMD_FLOATING_UNK 15      // CMD室真ん中のふわふわしてるやつ
#define ACTOR_OPERATOR 16              // オペレータ(work[1]でルージュかジョーヌか)
#define ACTOR_SEARCH_CURSOR 24         // 水没した図書館で検索した時に部屋のドアを囲むカーソル
#define ACTOR_ZERO_AFTER_OZ 39         // オメガをリンチしてる時のゼロ(プレイヤー)
#define ACTOR_INJURED_OMEGA 40         // 四天王にリンチされるイベントでのオメガ
#define ACTOR_DARKELF_HEAL 41          // ダークエルフがオメガを回復させるために落とすキラキラ
#define ACTOR_LAST_HARPUIA 42          // オメガをリンチしてる時のハルピュイア
#define ACTOR_LAST_FEFNIR 43           // オメガをリンチしてる時のファーブニル
#define ACTOR_LAST_FEFNIR_FIREBALL 44  // オメガをリンチしてる時のファーブニルの火球
#define ACTOR_LAST_LEVIATHAN 45        // オメガをリンチしてる時のレヴィアタン
#define ACTOR_LAST_X 46                // オメガをリンチしてる時のXのエルフ
// ...
#define ACTOR_UNK_57 57
// ...
#define ACTOR_UNK_65 65

#define ACTOR_COUNT 66

// --------------------------------------------

// Solid.id is 29(SOLID_MOB_NPC)
#define MOB_ANDREW 0
#define MOB_ALOUETTE 1
#define MOB_HIBOU 2
#define MOB_MENART 3
#define MOB_ROCINOLLE 4
#define MOB_HIRONDELLE 5
#define MOB_PIC 6
#define MOB_07 7
#define MOB_08 8
#define MOB_09 9
#define MOB_10 10
#define MOB_11 11
#define MOB_12 12
#define MOB_13 13
#define MOB_14 14
#define MOB_15 15
#define MOB_16 16
#define MOB_17 17
#define MOB_18 18
#define MOB_19 19
#define MOB_20 20
#define MOB_21 21
#define MOB_22 22
#define MOB_23 23
#define MOB_24 24
#define MOB_25 25
#define MOB_26 26

// --------------------------------------------

// Solid.id が 30
#define MAIN_NPC_CIEL 1
#define MAIN_NPC_CERVEAU 2
#define MAIN_NPC_COLBOR 3

// --------------------------------------------

#define MOD_ELF_ELPIZO 0
#define MOD_ELF_PHANTOM 1

// --------------------------------------------

#endif  // GUARD_RMZ3_CONST_SOLID_H
