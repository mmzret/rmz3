#include "entity.h"

#include "global.h"
#include "overworld.h"

const struct EntityTemplate gSpaceCraftEntity[26] = {
    [0] =
        {
            0,
            ENTITY_PLAYER,
        },
    [1] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_LIFE_M,
            2,
            0,
            0,
            0,
        },
    [2] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_LIFE_L,
            2,
            0,
            0,
            0,
        },
    [3] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_EC_L,
            2,
            0,
            0,
            0,
        },
    [4] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_EXLIFE,
            2,
            0,
            0,
            0,
        },
    [5] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_BLUE,
            0,
            0,
            0,
            0,
            0,
        },
    [6] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_BLUE,
            2,
            0,
            0,
            0,
            0,
        },
    [7] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_GRAND_CANNON,
            GRAND_CANNON_TURRET,
            0,
            1,
            1,
            1,
        },
    [8] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_SHRIMPORIN,
            0,
            0,
            1,
            1,
            0,
        },
    [9] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_SHRIMPORIN,
            1,
            0,
            1,
            1,
            0,
        },
    [10] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_P_HUNTER,
            0,
            0,
            1,
            1,
            1,
        },
    [11] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_BATRING,
            0,
            0,
            1,
            2,
            2,
        },
    [12] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_BATRING,
            1,
            0,
            1,
            2,
            2,
        },
    [13] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_SHOTCOUNTER,
            0,
            0,
            1,
            2,
            2,
        },
    [14] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_SHOTCOUNTER,
            1,
            0,
            1,
            2,
            2,
        },
    [15] =
        {
            1,
            ENTITY_SOLID,
            SOLID_SCRIPT_ACTOR,
            8,
            0,
            0,
            0,
            0,
        },
    [16] =
        {
            1,
            ENTITY_SOLID,
            SOLID_ICE_BLOCK,
            0,
            0,
            0,
            0,
            0,
        },
    [17] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            24,
            2,
            0,
            0,
            0,
        },
    [18] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            37,
            2,
            0,
            0,
            0,
        },
    [19] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            50,
            2,
            0,
            0,
            0,
        },
    [20] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            101,
            2,
            0,
            0,
            0,
        },
    [21] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            2,
            7,
            0,
            0,
            0,
        },
    [22] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            2,
            111,
            0,
            0,
            0,
        },
    [23] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            2,
            254,
            0,
            0,
            0,
        },
    [24] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            2,
            255,
            0,
            0,
            0,
        },
    [25] =
        {
            15,
            15,
            255,
            255,
            255,
            0,
            0,
            0,
        },
};

const struct PreloadEntity gSpaceCraftStatic[8] = {
    {
        SM007_GRAND_CANNON,
        B8(00000001),
        512,
        4,
        1,
        1,
        0,
    },
    {
        SM013_SHRIMPOLIN,
        B8(00000001),
        553,
        5,
        1,
        3,
        0,
    },
    {
        SM019_PANTHEON_HUNTER,
        B8(00000001),
        681,
        6,
        1,
        1,
        0,
    },
    {
        SM006_BATRING,
        B8(00000001),
        801,
        7,
        1,
        1,
        0,
    },
    {
        SM004_SHOTCOUNTER,
        B8(00000001),
        898,
        8,
        1,
        1,
        0,
    },
    {
        SM203_ICE_BLOCK,
        B8(00000001),
        954,
        9,
        3,
        3,
        1,
    },
    {
        SM221_METTAUR,
        B8(01111111),
        512,
        6,
        2,
        3,
        0,
    },
    {
        255,
        255,
        4095,
        15,
        1,
        3,
        1,
    },
};

// clang-format off
const struct EntityTemplateCoord gSpaceCraftEntityCoord[68] = {
  [0] = { -0x80000000, -0x8000, 0 },
  [1] = { 0x00000068, 0x0069, 7 },
  [2] = { 0x00000072, 0x0067, 7 },
  [3] = { 0x0000007B, 0x006A, 8 },
  [4] = { 0x0000008D, 0x0065, 7 },
  [5] = { 0x00000091, 0x0065, 23 },
  [6] = { 0x00000095, 0x0061, 7 },
  [7] = { 0x0000009B, 0x0060, 7 },
  [8] = { 0x0000009F, 0x005B, 9 },
  [9] = { 0x000000AD, 0x0062, 17 },
  [10] = { 0x000000AF, 0x005A, 8 },
  [11] = { 0x000000BB, 0x0056, 7 },
  [12] = { 0x000000D5, 0x0040, 16 },
  [13] = { 0x000000D5, 0x0044, 16 },
  [14] = { 0x000000D6, 0x0018, 10 },
  [15] = { 0x000000D6, 0x0023, 10 },
  [16] = { 0x000000D6, 0x0028, 21 },
  [17] = { 0x000000D7, 0x003F, 3 },
  [18] = { 0x000000D7, 0x0044, 16 },
  [19] = { 0x000000D9, 0x0030, 12 },
  [20] = { 0x000000D9, 0x0042, 16 },
  [21] = { 0x000000D9, 0x0044, 16 },
  [22] = { 0x000000DB, 0x001C, 12 },
  [23] = { 0x000000DB, 0x0044, 16 },
  [24] = { 0x000000DC, 0x003F, 19 },
  [25] = { 0x000000DD, 0x0040, 16 },
  [26] = { 0x000000DD, 0x0044, 16 },
  [27] = { 0x000000DE, 0x0032, 22 },
  [28] = { 0x000000E0, 0x0012, 5 },
  [29] = { 0x000000E0, 0x0058, 16 },
  [30] = { 0x000000E1, 0x0047, 14 },
  [31] = { 0x000000E2, 0x0053, 18 },
  [32] = { 0x000000E2, 0x0058, 16 },
  [33] = { 0x000000E8, 0x0049, 14 },
  [34] = { 0x000000E8, 0x0056, 12 },
  [35] = { 0x000000EA, 0x003A, 23 },
  [36] = { 0x000000EC, 0x0053, 16 },
  [37] = { 0x000000ED, 0x0039, 14 },
  [38] = { 0x000000EE, 0x0049, 16 },
  [39] = { 0x000000EE, 0x0053, 16 },
  [40] = { 0x000000EE, 0x0055, 16 },
  [41] = { 0x000000EF, 0x0012, 6 },
  [42] = { 0x000000F0, 0x0049, 16 },
  [43] = { 0x000000F0, 0x0053, 16 },
  [44] = { 0x000000F0, 0x0055, 16 },
  [45] = { 0x000000F1, 0x0044, 23 },
  [46] = { 0x000000F2, 0x0049, 16 },
  [47] = { 0x000000F3, 0x0037, 13 },
  [48] = { 0x000000F6, 0x000A, 15 },
  [49] = { 0x000000F6, 0x004E, 10 },
  [50] = { 0x000000F6, 0x0056, 10 },
  [51] = { 0x000000F7, 0x0040, 11 },
  [52] = { 0x000000F8, 0x000A, 15 },
  [53] = { 0x000000FA, 0x000A, 15 },
  [54] = { 0x000000FA, 0x0035, 20 },
  [55] = { 0x000000FA, 0x004E, 16 },
  [56] = { 0x000000FB, 0x0049, 2 },
  [57] = { 0x000000FC, 0x000A, 15 },
  [58] = { 0x000000FE, 0x000A, 15 },
  [59] = { 0x000000FE, 0x000B, 15 },
  [60] = { 0x000000FE, 0x000C, 15 },
  [61] = { 0x000000FE, 0x000D, 15 },
  [62] = { 0x000000FE, 0x000E, 15 },
  [63] = { 0x000000FE, 0x000F, 15 },
  [64] = { 0x000000FE, 0x0010, 15 },
  [65] = { 0x000000FE, 0x0011, 15 },
  [66] = { 0x000000FE, 0x0012, 15 },
  [67] = { 0x7FFFFFFF, 0x7FFF, 0 },
};
// clang-format on
