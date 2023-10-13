#include "entity.h"

#include "global.h"
#include "overworld.h"

const struct EntityTemplate gVolcanoEntity[51] = {
    [0] =
        {
            0,
            ENTITY_PLAYER,
            0,
            0,
            0,
            0,
            0,
            0,
        },
    [1] =
        {
            2,
            ENTITY_ITEM,
            ITEM_GENERAL,
            1,
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
            2,
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
            4,
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
            5,
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
            1,
            0,
            0,
            0,
            0,
        },
    [7] =
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
    [8] =
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
    [9] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_GYRO_CANNON,
            0,
            0,
            1,
            2,
            2,
        },
    [10] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            0,
            0,
            0,
            0,
            0,
        },
    [11] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            1,
            0,
            0,
            0,
            0,
        },
    [12] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            2,
            0,
            0,
            0,
            0,
        },
    [13] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            3,
            0,
            0,
            0,
            0,
        },
    [14] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            4,
            0,
            0,
            0,
            0,
        },
    [15] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            5,
            0,
            0,
            0,
            0,
        },
    [16] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            6,
            0,
            0,
            0,
            0,
        },
    [17] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            7,
            0,
            0,
            0,
            0,
        },
    [18] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            8,
            0,
            0,
            0,
            0,
        },
    [19] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            9,
            0,
            0,
            0,
            0,
        },
    [20] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            10,
            0,
            0,
            0,
            0,
        },
    [21] =
        {
            1,
            ENTITY_SOLID,
            SOLID_LAVA_GEYSER,
            11,
            0,
            0,
            0,
            0,
        },
    [22] =
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
    [23] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_P_GUARDIAN,
            0,
            0,
            1,
            1,
            2,
        },
    [24] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_VOLCAIRE,
            0,
            0,
            1,
            0,
            0,
        },
    [25] =
        {
            1,
            ENTITY_SOLID,
            SOLID_HEAVY_CANNON,
            0,
            0,
            1,
            1,
            1,
        },
    [26] =
        {
            1,
            ENTITY_SOLID,
            SOLID_HEAVY_CANNON,
            1,
            0,
            1,
            1,
            1,
        },
    [27] =
        {
            1,
            ENTITY_SOLID,
            SOLID_HEAVY_CANNON,
            2,
            0,
            1,
            1,
            1,
        },
    [28] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_LAMPLORT,
            0,
            0,
            1,
            1,
            1,
        },
    [29] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_LAMPLORT,
            1,
            0,
            1,
            1,
            1,
        },
    [30] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            0,
            0,
            1,
            1,
            0,
        },
    [31] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            1,
            0,
            1,
            2,
            0,
        },
    [32] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            2,
            0,
            1,
            2,
            0,
        },
    [33] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            3,
            0,
            1,
            2,
            0,
        },
    [34] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            0,
            1,
            1,
            1,
            0,
        },
    [35] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            1,
            1,
            1,
            2,
            0,
        },
    [36] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            2,
            1,
            1,
            2,
            0,
        },
    [37] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_TOP_GABYOALL,
            3,
            1,
            1,
            2,
            0,
        },
    [38] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            26,
            2,
            0,
            0,
            0,
        },
    [39] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            47,
            2,
            0,
            0,
            0,
        },
    [40] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            73,
            2,
            0,
            0,
            0,
        },
    [41] =
        {
            2,
            ENTITY_ITEM,
            ITEM_DISK,
            114,
            2,
            0,
            0,
            0,
        },
    [42] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            1,
            8,
            0,
            0,
            0,
        },
    [43] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            1,
            72,
            0,
            0,
            0,
        },
    [44] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            1,
            102,
            0,
            0,
            0,
        },
    [45] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            1,
            254,
            0,
            0,
            0,
        },
    [46] =
        {
            2,
            ENTITY_SOLID,
            SOLID_CONTAINER,
            1,
            255,
            0,
            0,
            0,
        },
    [47] =
        {
            1,
            ENTITY_SOLID,
            SOLID_CYBERSPACE_DOOR,
            0,
            0,
            0,
            0,
            0,
        },
    [48] =
        {
            1,
            ENTITY_SOLID,
            SOLID_CYBERSPACE_DOOR,
            1,
            0,
            0,
            0,
            0,
        },
    [49] =
        {
            1,
            ENTITY_ENEMY,
            ENEMY_P_HUNTER,
            1,
            0,
            1,
            1,
            1,
        },
    [50] =
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

const struct PreloadEntity gVolcanoStatic[20] = {
    {
        SM023_GYRO_CANNON,
        B8(00001111),
        512,
        4,
        1,
        1,
        0,
    },
    {
        SM056_HEAVY_CANNON,
        B8(00001111),
        607,
        5,
        1,
        1,
        0,
    },
    {
        SM019_PANTHEON_HUNTER,
        B8(00001111),
        669,
        6,
        1,
        1,
        0,
    },
    {
        SM061_UNK,
        B8(00001111),
        512,
        13,
        1,
        2,
        0,
    },
    {
        SM062_BEETANK,
        B8(00001111),
        541,
        5,
        1,
        2,
        0,
    },
    {
        SM063_SWORDY,
        B8(00001111),
        641,
        6,
        1,
        2,
        0,
    },
    {
        SM031_VOLCANO_BOMB,
        B8(00000001),
        849,
        8,
        3,
        3,
        0,
    },
    {
        SM046_VOLCAIRE,
        B8(00000010),
        849,
        8,
        3,
        3,
        0,
    },
    {
        SM057_GEYSER,
        B8(00000100),
        849,
        8,
        3,
        3,
        1,
    },
    {
        SM058_VOLCANO_RISING_PLATFORM,
        B8(00000100),
        994,
        9,
        3,
        3,
        1,
    },
    {
        SM059_LAVA_PLATFORM,
        B8(00011000),
        849,
        8,
        3,
        3,
        1,
    },
    {
        SM025_LAMPLORT,
        B8(00010000),
        512,
        4,
        1,
        1,
        0,
    },
    {
        SM020_PANTHEON_GUARDIAN,
        B8(00010000),
        668,
        5,
        1,
        1,
        0,
    },
    {
        SM021_TOP_GABYOALL,
        B8(00010000),
        873,
        6,
        1,
        3,
        0,
    },
    {
        SM153_VOLCANO_COFFIN,
        B8(00010000),
        905,
        9,
        3,
        3,
        1,
    },
    {
        SM061_UNK,
        B8(00010000),
        512,
        13,
        1,
        2,
        0,
    },
    {
        SM062_BEETANK,
        B8(00010000),
        541,
        5,
        1,
        2,
        0,
    },
    {
        SM063_SWORDY,
        B8(00010000),
        641,
        7,
        1,
        2,
        0,
    },
    {
        SM221_METTAUR,
        B8(01111111),
        669,
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
const struct EntityTemplateCoord gVolcanoEntityCoord[69] = {
    [0] =  { -0x80000000, -0x8000, 0 },
    [1] =  { 0x0000002E, 0x0025, 25 },
    [2] =  { 0x00000048, 0x0025, 26 },
    [3] =  { 0x0000006B, 0x0025, 25 },
    [4] =  { 0x00000084, 0x0025, 27 },
    [5] =  { 0x00000092, 0x0023, 47 },
    [6] =  { 0x00000096, 0x0023, 22 },
    [7] =  { 0x000000A9, 0x0023, 22 },
    [8] =  { 0x000000AB, 0x0023, 22 },
    [9] =  { 0x000000B5, 0x0023, 22 },
    [10] = { 0x000000BF, 0x0023, 22 },
    [11] = { 0x000000C1, 0x0023, 22 },
    [12] = { 0x000000DF, 0x0027, 24 },
    [13] = { 0x000000F1, 0x0021, 22 },
    [14] = { 0x000000FD, 0x0027, 24 },
    [15] = { 0x00000103, 0x0021, 22 },
    [16] = { 0x0000010F, 0x0027, 24 },
    [17] = { 0x00000115, 0x0021, 22 },
    [18] = { 0x00000129, 0x0026, 18 },
    [19] = { 0x0000012F, 0x0024, 49 },
    [20] = { 0x0000012F, 0x0026, 19 },
    [21] = { 0x00000137, 0x0026, 12 },
    [22] = { 0x0000013E, 0x0026, 18 },
    [23] = { 0x0000013F, 0x0019, 3 },
    [24] = { 0x00000140, 0x0019, 22 },
    [25] = { 0x00000142, 0x0019, 39 },
    [26] = { 0x00000146, 0x0026, 12 },
    [27] = { 0x0000015E, 0x0025, 44 },
    [28] = { 0x00000160, 0x0025, 27 },
    [29] = { 0x00000169, 0x0021, 9 },
    [30] = { 0x00000173, 0x001B, 38 },
    [31] = { 0x00000174, 0x001B, 2 },
    [32] = { 0x00000179, 0x0021, 9 },
    [33] = { 0x00000180, 0x0025, 25 },
    [34] = { 0x000001C6, 0x001C, 48 },
    [35] = { 0x000001D0, 0x001C, 7 },
    [36] = { 0x000001DF, 0x001C, 7 },
    [37] = { 0x000001F7, 0x0025, 41 },
    [38] = { 0x000001F8, 0x0025, 3 },
    [39] = { 0x000001F9, 0x0025, 3 },
    [40] = { 0x00000204, 0x001B, 28 },
    [41] = { 0x00000204, 0x002B, 23 },
    [42] = { 0x00000205, 0x0030, 23 },
    [43] = { 0x0000020C, 0x003A, 7 },
    [44] = { 0x00000213, 0x0017, 40 },
    [45] = { 0x0000021B, 0x003A, 7 },
    [46] = { 0x0000021E, 0x0024, 28 },
    [47] = { 0x0000021F, 0x001C, 23 },
    [48] = { 0x00000220, 0x0026, 43 },
    [49] = { 0x00000228, 0x001A, 29 },
    [50] = { 0x0000022A, 0x0026, 23 },
    [51] = { 0x0000022A, 0x003A, 8 },
    [52] = { 0x00000233, 0x0026, 23 },
    [53] = { 0x00000235, 0x001C, 42 },
    [54] = { 0x0000023A, 0x001C, 30 },
    [55] = { 0x0000023C, 0x002D, 23 },
    [56] = { 0x0000023F, 0x0029, 31 },
    [57] = { 0x00000241, 0x0035, 47 },
    [58] = { 0x00000242, 0x0035, 3 },
    [59] = { 0x00000242, 0x003A, 23 },
    [60] = { 0x00000243, 0x0019, 29 },
    [61] = { 0x00000247, 0x0021, 3 },
    [62] = { 0x00000247, 0x0027, 33 },
    [63] = { 0x000002A8, 0x001A, 28 },
    [64] = { 0x000002AC, 0x001A, 3 },
    [65] = { 0x000002B2, 0x001A, 48 },
    [66] = { 0x000002C0, 0x001C, 5 },
    [67] = { 0x000002CF, 0x001C, 5 },
    [68] = { 0x7FFFFFFF, 0x7FFF, 0 },
};
// clang-format off


