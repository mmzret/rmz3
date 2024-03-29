#include "entity.h"

#include "global.h"
#include "overworld.h"

const struct EntityTemplate gRepairFactoryEntity[38] = {
    [0] =
        {
            0,
            ENTITY_PLAYER,
            PLAYER_ZERO,
        },
    [1] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_LIFE_M,
            2,
        },
    [2] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_LIFE_L,
            2,
        },
    [3] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_EC_L,
            2,
        },
    [4] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            ITEM_EXLIFE,
            2,
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
            1,
            0,
            0,
            0,
            0,
        },
    [7] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_P_GUARDIAN,
            0,
            0,
            1,
            1,
            1,
        },
    [8] =
        {
            2,
            ENTITY_ENEMY,
            ENEMY_EYE_CANNON,
            0,
            0,
            1,
            2,
            0,
        },
    [9] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_SNAKECORD,
            0,
            0,
            1,
            2,
            0,
        },
    [10] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_HAMMER,
            0,
            0,
            0,
            0,
            0,
        },
    [11] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_DEATHLOCK,
            0,
            0,
            1,
            0,
            0,
        },
    [12] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_DEATHLOCK,
            1,
            0,
            1,
            0,
            0,
        },
    [13] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_DEATHLOCK,
            2,
            0,
            1,
            0,
            0,
        },
    [14] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_DEATHLOCK,
            3,
            0,
            1,
            0,
            0,
        },
    [15] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_DEATHLOCK,
            8,
            0,
            0,
            0,
            0,
        },
    [16] =
        {
            4,
            ENTITY_ENEMY,
            ENEMY_LEMMINGLES_NEST,
            0,
            0,
            1,
            1,
            0,
        },
    [17] =
        {
            4,
            ENTITY_ENEMY,
            ENEMY_LEMMINGLES_NEST,
            1,
            0,
            1,
            1,
            0,
        },
    [18] =
        {
            4,
            ENTITY_ENEMY,
            ENEMY_LEMMINGLES_NEST,
            4,
            0,
            1,
            0,
            0,
        },
    [19] =
        {
            4,
            ENTITY_ENEMY,
            ENEMY_LEMMINGLES_NEST,
            5,
            0,
            1,
            0,
            0,
        },
    [20] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_GRAY_V,
            2,
            0,
            0,
            0,
            0,
        },
    [21] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_GRAY_V,
            0,
            0,
            0,
            0,
            0,
        },
    [22] =
        {
            1,
            ENTITY_SOLID,
            SOLID_UNK_034,
            0,
            0,
            0,
            0,
            0,
        },
    [23] =
        {
            2,
            ENTITY_ITEM,
            1,
            84,
            2,
            0,
            0,
            0,
        },
    [24] =
        {
            2,
            ENTITY_ITEM,
            1,
            100,
            2,
            0,
            0,
            0,
        },
    [25] =
        {
            2,
            ENTITY_ITEM,
            1,
            104,
            2,
            0,
            0,
            0,
        },
    [26] =
        {
            2,
            ENTITY_ITEM,
            1,
            115,
            2,
            0,
            0,
            0,
        },
    [27] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            0,
            12,
            0,
            0,
            0,
        },
    [28] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            0,
            53,
            0,
            0,
            0,
        },
    [29] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            0,
            254,
            0,
            0,
            0,
        },
    [30] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            0,
            255,
            0,
            0,
            0,
        },
    [31] =
        {
            1,
            ENTITY_SOLID,
            SOLID_CYBERSPACE_DOOR,
            0,
        },
    [32] =
        {
            1,
            ENTITY_SOLID,
            SOLID_CYBERSPACE_DOOR,
            1,
        },
    [33] =
        {
            2,
            ENTITY_ENEMY,
            ENEMY_EYE_CANNON,
            1,
        },
    [34] =
        {
            2,
            ENTITY_ENEMY,
            ENEMY_EYE_CANNON,
            2,
        },
    [35] =
        {
            2,
            ENTITY_ENEMY,
            ENEMY_EYE_CANNON,
            3,
        },
    [36] =
        {
            2,
            ENTITY_ENEMY,
            ENEMY_EYE_CANNON,
            4,
        },
    [37] =
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

const struct PreloadEntity gRepairFactoryStatic[13] = {
    {
        20,
        3,
        512,
        4,
        1,
        1,
        0,
    },
    {
        40,
        3,
        666,
        5,
        1,
        3,
        0,
    },
    {
        29,
        3,
        754,
        6,
        1,
        3,
        0,
    },
    {
        30,
        3,
        834,
        7,
        1,
        3,
        0,
    },
    {
        61,
        3,
        512,
        13,
        1,
        2,
        0,
    },
    {
        62,
        3,
        541,
        4,
        1,
        2,
        0,
    },
    {
        41,
        1,
        855,
        8,
        1,
        3,
        0,
    },
    {
        102,
        1,
        872,
        9,
        3,
        3,
        0,
    },
    {
        224,
        1,
        920,
        10,
        1,
        3,
        1,
    },
    {
        116,
        2,
        855,
        7,
        3,
        3,
        0,
    },
    {
        118,
        2,
        950,
        8,
        3,
        3,
        1,
    },
    {
        221,
        127,
        512,
        4,
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
const struct EntityTemplateCoord gRepairFactoryEntityCoord[73] = {
    [0] = { -0x80000000, -0x8000, 0 },
    [1] = { 0x00000020, 0x0044, 7 },
    [2] = { 0x00000023, 0x0033, 33 },
    [3] = { 0x00000024, 0x004D, 7 },
    [4] = { 0x00000027, 0x004D, 7 },
    [5] = { 0x0000002D, 0x0034, 10 },
    [6] = { 0x0000002D, 0x003F, 10 },
    [7] = { 0x0000002F, 0x0049, 34 },
    [8] = { 0x00000032, 0x0044, 7 },
    [9] = { 0x0000003B, 0x004D, 18 },
    [10] = { 0x0000003E, 0x0035, 31 },
    [11] = { 0x0000003F, 0x0035, 1 },
    [12] = { 0x00000042, 0x0033, 35 },
    [13] = { 0x00000046, 0x003A, 18 },
    [14] = { 0x00000054, 0x0037, 7 },
    [15] = { 0x0000005B, 0x0030, 7 },
    [16] = { 0x00000060, 0x002C, 7 },
    [17] = { 0x00000068, 0x003A, 18 },
    [18] = { 0x0000006B, 0x0029, 9 },
    [19] = { 0x00000075, 0x002B, 3 },
    [20] = { 0x00000076, 0x002B, 3 },
    [21] = { 0x0000007A, 0x002E, 10 },
    [22] = { 0x0000007C, 0x002B, 26 },
    [23] = { 0x00000080, 0x0035, 27 },
    [24] = { 0x00000088, 0x0029, 36 },
    [25] = { 0x00000090, 0x0031, 18 },
    [26] = { 0x000000A0, 0x0029, 9 },
    [27] = { 0x000000A8, 0x002D, 7 },
    [28] = { 0x000000B0, 0x002E, 1 },
    [29] = { 0x000000B4, 0x002D, 7 },
    [30] = { 0x000000B8, 0x0029, 9 },
    [31] = { 0x000000C2, 0x002D, 7 },
    [32] = { 0x000000C5, 0x002D, 32 },
    [33] = { 0x000000CF, 0x002D, 7 },
    [34] = { 0x000000D3, 0x0030, 29 },
    [35] = { 0x000000D6, 0x0037, 3 },
    [36] = { 0x000000D7, 0x0037, 3 },
    [37] = { 0x000000D9, 0x002B, 10 },
    [38] = { 0x000000DF, 0x002D, 25 },
    [39] = { 0x000000E0, 0x003A, 21 },
    [40] = { 0x000000EF, 0x003A, 21 },
    [41] = { 0x000000FE, 0x003A, 20 },
    [42] = { 0x0000010D, 0x003A, 21 },
    [43] = { 0x00000110, 0x0016, 15 },
    [44] = { 0x00000112, 0x000B, 9 },
    [45] = { 0x00000116, 0x0035, 31 },
    [46] = { 0x00000117, 0x0035, 1 },
    [47] = { 0x00000131, 0x000D, 15 },
    [48] = { 0x00000138, 0x000B, 22 },
    [49] = { 0x00000142, 0x000B, 9 },
    [50] = { 0x0000014C, 0x000D, 16 },
    [51] = { 0x0000014D, 0x000D, 24 },
    [52] = { 0x0000015A, 0x0030, 23 },
    [53] = { 0x0000015B, 0x000C, 15 },
    [54] = { 0x0000015B, 0x0032, 22 },
    [55] = { 0x0000015E, 0x002E, 9 },
    [56] = { 0x00000160, 0x000B, 9 },
    [57] = { 0x00000161, 0x0018, 15 },
    [58] = { 0x00000165, 0x000D, 3 },
    [59] = { 0x00000166, 0x000D, 3 },
    [60] = { 0x0000016C, 0x0038, 16 },
    [61] = { 0x00000178, 0x0033, 9 },
    [62] = { 0x00000183, 0x0038, 11 },
    [63] = { 0x00000185, 0x0038, 32 },
    [64] = { 0x00000187, 0x004D, 28 },
    [65] = { 0x0000018A, 0x0041, 17 },
    [66] = { 0x0000018C, 0x0046, 3 },
    [67] = { 0x00000190, 0x0033, 9 },
    [68] = { 0x0000019A, 0x0045, 12 },
    [69] = { 0x0000019A, 0x0048, 9 },
    [70] = { 0x000001A3, 0x003A, 5 },
    [71] = { 0x000001B2, 0x003A, 5 },
    [72] = { 0x7FFFFFFF, 0x7FFF, 0 },
};
// clang-format on
