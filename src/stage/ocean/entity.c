#include "entity.h"

#include "global.h"
#include "overworld.h"

const struct EntityTemplate gOceanEntity[31] = {
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
            0,
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
            0,
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
            0,
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
            0,
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
            0,
            0,
            0,
            1,
            0,
            0,
        },
    [8] =
        {
            1,
            ENTITY_ENEMY,
            15,
            0,
            0,
            1,
            3,
            3,
        },
    [9] =
        {
            1,
            ENTITY_ENEMY,
            18,
            0,
            0,
            1,
            3,
            3,
        },
    [10] =
        {
            1,
            ENTITY_SOLID,
            4,
            1,
            0,
            1,
            0,
            0,
        },
    [11] =
        {
            1,
            ENTITY_SOLID,
            4,
            0,
            0,
            0,
            0,
            0,
        },
    [12] =
        {
            1,
            ENTITY_ENEMY,
            26,
            0,
            0,
            1,
            3,
            0,
        },
    [13] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_GRAY,
            2,
            0,
            0,
            0,
            0,
        },
    [14] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_GRAY,
            0,
            0,
            0,
            0,
            0,
        },
    [15] =
        {
            1,
            ENTITY_SOLID,
            SOLID_DOOR_2D_GRAY,
            1,
            0,
            0,
            0,
            0,
        },
    [16] =
        {
            2,
            ENTITY_ITEM,
            1,
            5,
            2,
            0,
            0,
            0,
        },
    [17] =
        {
            2,
            ENTITY_ITEM,
            1,
            9,
            2,
            0,
            0,
            0,
        },
    [18] =
        {
            2,
            ENTITY_ITEM,
            1,
            49,
            2,
            0,
            0,
            0,
        },
    [19] =
        {
            2,
            ENTITY_ITEM,
            1,
            75,
            2,
            0,
            0,
            0,
        },
    [20] =
        {
            2,
            ENTITY_ITEM,
            0,
            0,
            0,
            0,
            0,
            0,
        },
    [21] =
        {
            2,
            ENTITY_SOLID,
            35,
            1,
            59,
            0,
            0,
            0,
        },
    [22] =
        {
            2,
            ENTITY_SOLID,
            35,
            1,
            113,
            0,
            0,
            0,
        },
    [23] =
        {
            2,
            ENTITY_SOLID,
            35,
            1,
            254,
            0,
            0,
            0,
        },
    [24] =
        {
            2,
            ENTITY_SOLID,
            35,
            1,
            255,
            0,
            0,
            0,
        },
    [25] =
        {
            1,
            ENTITY_SOLID,
            31,
            0,
            0,
            0,
            0,
            0,
        },
    [26] =
        {
            1,
            ENTITY_SOLID,
            31,
            1,
            0,
            0,
            0,
            0,
        },
    [27] =
        {
            1,
            ENTITY_SOLID,
            53,
            0,
            0,
            0,
            0,
            0,
        },
    [28] =
        {
            1,
            ENTITY_SOLID,
            4,
            3,
            0,
            0,
            0,
            0,
        },
    [29] =
        {
            1,
            ENTITY_SOLID,
            4,
            5,
            0,
            0,
            0,
            0,
        },
    [30] =
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

const struct PreloadEntity gOceanStatic[17] = {
    {
        122,
        0,
        480,
        2,
        1,
        3,
        0,
    },
    {
        53,
        7,
        512,
        4,
        1,
        3,
        0,
    },
    {
        24,
        7,
        558,
        5,
        1,
        1,
        0,
    },
    {
        39,
        7,
        648,
        6,
        1,
        1,
        0,
    },
    {
        182,
        1,
        744,
        7,
        3,
        3,
        1,
    },
    {
        61,
        7,
        558,
        13,
        1,
        2,
        0,
    },
    {
        65,
        7,
        587,
        5,
        1,
        2,
        0,
    },
    {
        66,
        7,
        617,
        6,
        1,
        2,
        0,
    },
    {
        183,
        7,
        891,
        14,
        3,
        3,
        0,
    },
    {
        181,
        7,
        899,
        10,
        3,
        3,
        1,
    },
    {
        180,
        0,
        911,
        10,
        3,
        3,
        0,
    },
    {
        16,
        6,
        744,
        7,
        3,
        3,
        0,
    },
    {
        17,
        6,
        783,
        8,
        3,
        3,
        0,
    },
    {
        45,
        6,
        848,
        9,
        3,
        3,
        1,
    },
    {
        39,
        64,
        512,
        4,
        3,
        3,
        0,
    },
    {
        221,
        63,
        648,
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
const struct EntityTemplateCoord gOceanEntityCoord[86] = {
    [0] = { -0x80000000, -0x8000, 0 },
    [1] = { 0x00000016, 0x0026, 16 },
    [2] = { 0x00000017, 0x0026, 12 },
    [3] = { 0x0000001A, 0x0026, 3 },
    [4] = { 0x0000001B, 0x0026, 3 },
    [5] = { 0x0000001F, 0x0025, 27 },
    [6] = { 0x00000044, 0x0024, 8 },
    [7] = { 0x0000005B, 0x0026, 7 },
    [8] = { 0x00000064, 0x0026, 7 },
    [9] = { 0x0000006E, 0x0023, 8 },
    [10] = { 0x00000078, 0x0027, 8 },
    [11] = { 0x00000087, 0x0038, 8 },
    [12] = { 0x00000090, 0x0039, 3 },
    [13] = { 0x00000091, 0x0039, 3 },
    [14] = { 0x00000093, 0x0039, 19 },
    [15] = { 0x00000094, 0x002B, 25 },
    [16] = { 0x0000009F, 0x002D, 7 },
    [17] = { 0x000000A4, 0x001E, 3 },
    [18] = { 0x000000AB, 0x001E, 3 },
    [19] = { 0x000000AC, 0x001E, 17 },
    [20] = { 0x000000C1, 0x002D, 12 },
    [21] = { 0x000000D7, 0x0031, 7 },
    [22] = { 0x000000DE, 0x0024, 8 },
    [23] = { 0x000000E2, 0x0029, 21 },
    [24] = { 0x000000E9, 0x0024, 11 },
    [25] = { 0x000000F5, 0x001E, 2 },
    [26] = { 0x000000F9, 0x0038, 12 },
    [27] = { 0x000000FB, 0x0024, 11 },
    [28] = { 0x000000FF, 0x0024, 10 },
    [29] = { 0x00000103, 0x0024, 11 },
    [30] = { 0x00000105, 0x0024, 11 },
    [31] = { 0x00000107, 0x0038, 7 },
    [32] = { 0x0000010C, 0x0030, 8 },
    [33] = { 0x00000110, 0x001E, 4 },
    [34] = { 0x00000117, 0x0030, 12 },
    [35] = { 0x0000011D, 0x0030, 23 },
    [36] = { 0x0000011F, 0x0029, 2 },
    [37] = { 0x0000011F, 0x0030, 23 },
    [38] = { 0x00000125, 0x002E, 12 },
    [39] = { 0x00000132, 0x002A, 8 },
    [40] = { 0x00000135, 0x003A, 23 },
    [41] = { 0x00000152, 0x0030, 23 },
    [42] = { 0x00000159, 0x001E, 1 },
    [43] = { 0x0000015A, 0x0026, 9 },
    [44] = { 0x00000161, 0x002E, 8 },
    [45] = { 0x00000164, 0x0033, 23 },
    [46] = { 0x00000166, 0x0033, 23 },
    [47] = { 0x00000172, 0x0026, 9 },
    [48] = { 0x0000017B, 0x0030, 9 },
    [49] = { 0x00000180, 0x0030, 26 },
    [50] = { 0x00000182, 0x0023, 8 },
    [51] = { 0x0000018A, 0x0030, 9 },
    [52] = { 0x00000194, 0x003A, 14 },
    [53] = { 0x000001A3, 0x003A, 14 },
    [54] = { 0x000001B2, 0x003A, 13 },
    [55] = { 0x000001C1, 0x003A, 14 },
    [56] = { 0x000001E1, 0x0037, 7 },
    [57] = { 0x000001E8, 0x0034, 25 },
    [58] = { 0x000001EE, 0x0024, 28 },
    [59] = { 0x000001EE, 0x002C, 29 },
    [60] = { 0x000001F0, 0x0031, 9 },
    [61] = { 0x000001F3, 0x0024, 28 },
    [62] = { 0x000001F3, 0x002C, 29 },
    [63] = { 0x000001FB, 0x0025, 9 },
    [64] = { 0x000001FF, 0x001E, 18 },
    [65] = { 0x000001FF, 0x0025, 3 },
    [66] = { 0x0000020C, 0x0032, 9 },
    [67] = { 0x00000228, 0x0033, 8 },
    [68] = { 0x00000232, 0x002D, 8 },
    [69] = { 0x00000235, 0x0033, 8 },
    [70] = { 0x0000023B, 0x0035, 23 },
    [71] = { 0x00000243, 0x0029, 8 },
    [72] = { 0x00000243, 0x0038, 22 },
    [73] = { 0x00000252, 0x0025, 8 },
    [74] = { 0x00000258, 0x002D, 8 },
    [75] = { 0x0000025E, 0x0038, 23 },
    [76] = { 0x00000265, 0x002F, 8 },
    [77] = { 0x0000027E, 0x0030, 9 },
    [78] = { 0x00000283, 0x0033, 7 },
    [79] = { 0x00000286, 0x0025, 8 },
    [80] = { 0x0000028E, 0x0030, 9 },
    [81] = { 0x00000296, 0x0039, 9 },
    [82] = { 0x000002A2, 0x003A, 26 },
    [83] = { 0x000002B1, 0x0030, 5 },
    [84] = { 0x000002C0, 0x0030, 5 },
    [85] = { 0x7FFFFFFF, 0x7FFF, 0 },
};
// clang-format on