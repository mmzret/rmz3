#include "gfx.h"
#include "global.h"

// I'll replace this file by sprites/prop/header.json in the future

const struct ColorGraphic gStaticMotionGraphics[STATIC_MOTION_COUNT] = {
    [0] = {
      // gStaticMotionGraphics
      g : {
        src : 0x000013D8,  // 0x085D8CD0
        size : 2816,
        ofs : 160,
        chunkSize : 1592,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00001ECC,  // 0x085D97D0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [1] = {
      // 0x085D790C
      g : {
        src : 0x00001F04,  // 0x085D9810
        size : 1328,
        ofs : 512,
        chunkSize : 400,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00002428,  // 0x085D9D40
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [2] = {
      // 0x085D7920
      g : {
        src : 0x00002440,  // 0x085D9D60
        size : 96,
        ofs : 359,
        chunkSize : 24,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x00002494,  // 0x085D9DC0
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [3] = {
      // 0x085D7934
      g : {
        src : 0x0000248C,  // 0x085D9DC0
        size : 192,
        ofs : 362,
        chunkSize : 48,
        props : (BPP4 | NO_PAL)
      },
      pal : {
        src : 0x00002540,  // 0x085D9E80
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [4] = {
      // 0x085D7948
      g : {
        src : 0x00002538,  // 0x085D9E80
        size : 1792,
        ofs : 512,
        chunkSize : 448,
        props : BPP4
      },
      pal : {
        src : 0x00002C2C,  // 0x085DA580
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [5] = {
      // 0x085D795C
      g : {
        src : 0x00002C44,  // 0x085DA5A0
        size : 128,
        ofs : 896,
        chunkSize : 56,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00002CB8,  // 0x085DA620
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [6] = {
      // 0x085D7970
      g : {
        src : 0x00002CD0,  // 0x085DA640
        size : 3104,
        ofs : 512,
        chunkSize : 776,
        props : BPP4
      },
      pal : {
        src : 0x000038E4,  // 0x085DB260
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [7] = {
      // 0x085D7984
      g : {
        src : 0x000038FC,  // 0x085DB280
        size : 1312,
        ofs : 512,
        chunkSize : 328,
        props : BPP4
      },
      pal : {
        src : 0x00003E10,  // 0x085DB7A0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [8] = {
      // 0x085D7998
      g : {
        src : 0x00003E28,  // 0x085DB7C0
        size : 2240,
        ofs : 512,
        chunkSize : 560,
        props : BPP4
      },
      pal : {
        src : 0x000046DC,  // 0x085DC080
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [9] = {
      // 0x085D79AC
      g : {
        src : 0x000046F4,  // 0x085DC0A0
        size : 2228,
        ofs : 512,
        chunkSize : 1056,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00004F9C,  // 0x085DC954
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [10] = {
      // 0x085D79C0
      g : {
        src : 0x00004FB4,  // 0x085DC974
        size : 1940,
        ofs : 644,
        chunkSize : 992,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0000573C,  // 0x085DD108
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [11] = {
      // 0x085D79D4
      g : {
        src : 0x00005754,  // 0x085DD128
        size : 880,
        ofs : 768,
        chunkSize : 304,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00005AB8,  // 0x085DD498
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [12] = {
      // 0x085D79E8
      g : {
        src : 0x00005AD0,  // 0x085DD4B8
        size : 640,
        ofs : 806,
        chunkSize : 160,
        props : BPP4
      },
      pal : {
        src : 0x00005D44,  // 0x085DD738
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [13] = {
      // 0x085D79FC
      g : {
        src : 0x00005D5C,  // 0x085DD758
        size : 4096,
        ofs : 512,
        chunkSize : 1024,
        props : BPP4
      },
      pal : {
        src : 0x00006D50,  // 0x085DE758
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [14] = {
      // 0x085D7A10
      g : {
        src : 0x00006D88,  // 0x085DE798
        size : 2608,
        ofs : 512,
        chunkSize : 976,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000077AC,  // 0x085DF1C8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [15] = {
      // 0x085D7A24
      g : {
        src : 0x000077E4,  // 0x085DF208
        size : 1444,
        ofs : 634,
        chunkSize : 824,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00007D7C,  // 0x085DF7AC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [16] = {
      // 0x085D7A38
      g : {
        src : 0x00007D94,  // 0x085DF7CC
        size : 1248,
        ofs : 512,
        chunkSize : 312,
        props : BPP4
      },
      pal : {
        src : 0x00008268,  // 0x085DFCAC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [17] = {
      // 0x085D7A4C
      g : {
        src : 0x00008280,  // 0x085DFCCC
        size : 2080,
        ofs : 548,
        chunkSize : 520,
        props : BPP4
      },
      pal : {
        src : 0x00008A94,  // 0x085E04EC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [18] = {
      // 0x085D7A60
      g : {
        src : 0x00008AAC,  // 0x085E050C
        size : 1024,
        ofs : 480,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x00008EA0,  // 0x085E090C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [19] = {
      // 0x085D7A74
      g : {
        src : 0x00008EB8,  // 0x085E092C
        size : 3840,
        ofs : 512,
        chunkSize : 960,
        props : BPP4
      },
      pal : {
        src : 0x00009DAC,  // 0x085E182C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [20] = {
      // 0x085D7A88
      g : {
        src : 0x00009DC4,  // 0x085E184C
        size : 4928,
        ofs : 512,
        chunkSize : 1232,
        props : BPP4
      },
      pal : {
        src : 0x0000B0F8,  // 0x085E2B8C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [21] = {
      // 0x085D7A9C
      g : {
        src : 0x0000B110,  // 0x085E2BAC
        size : 1024,
        ofs : 512,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x0000B504,  // 0x085E2FAC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [22] = {
      // 0x085D7AB0
      g : {
        src : 0x0000B51C,  // 0x085E2FCC
        size : 512,
        ofs : 512,
        chunkSize : 128,
        props : BPP4
      },
      pal : {
        src : 0x0000B710,  // 0x085E31CC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [23] = {
      // 0x085D7AC4
      g : {
        src : 0x0000B728,  // 0x085E31EC
        size : 3040,
        ofs : 512,
        chunkSize : 760,
        props : BPP4
      },
      pal : {
        src : 0x0000C2FC,  // 0x085E3DCC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [24] = {
      // 0x085D7AD8
      g : {
        src : 0x0000C314,  // 0x085E3DEC
        size : 2880,
        ofs : 908,
        chunkSize : 720,
        props : BPP4
      },
      pal : {
        src : 0x0000CE48,  // 0x085E492C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [25] = {
      // 0x085D7AEC
      g : {
        src : 0x0000CE80,  // 0x085E496C
        size : 4992,
        ofs : 512,
        chunkSize : 1248,
        props : BPP4
      },
      pal : {
        src : 0x0000E1F4,  // 0x085E5CEC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [26] = {
      // 0x085D7B00
      g : {
        src : 0x0000E20C,  // 0x085E5D0C
        size : 448,
        ofs : 420,
        chunkSize : 176,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0000E3C0,  // 0x085E5ECC
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 15,
      },
    },
    [27] = {
      // 0x085D7B14
      g : {
        src : 0x0000E3B8,  // 0x085E5ECC
        size : 608,
        ofs : 420,
        chunkSize : 176,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0000E60C,  // 0x085E612C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [28] = {
      // 0x085D7B28
      g : {
        src : 0x0000E604,  // 0x085E612C
        size : 240,
        ofs : 412,
        chunkSize : 64,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0000E6E8,  // 0x085E621C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 15,
      },
    },
    [29] = {
      // 0x085D7B3C
      g : {
        src : 0x0000E6E0,  // 0x085E621C
        size : 2560,
        ofs : 533,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x0000F0D4,  // 0x085E6C1C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [30] = {
      // 0x085D7B50
      g : {
        src : 0x0000F0EC,  // 0x085E6C3C
        size : 672,
        ofs : 512,
        chunkSize : 168,
        props : BPP4
      },
      pal : {
        src : 0x0000F380,  // 0x085E6EDC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [31] = {
      // 0x085D7B64
      g : {
        src : 0x0000F398,  // 0x085E6EFC
        size : 512,
        ofs : 512,
        chunkSize : 128,
        props : BPP4
      },
      pal : {
        src : 0x0000F58C,  // 0x085E70FC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [32] = {
      // 0x085D7B78
      g : {
        src : 0x0000F5A4,  // 0x085E711C
        size : 1984,
        ofs : 512,
        chunkSize : 496,
        props : BPP4
      },
      pal : {
        src : 0x0000FD58,  // 0x085E78DC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [33] = {
      // 0x085D7B8C
      g : {
        src : 0x0000FD70,  // 0x085E78FC
        size : 472,
        ofs : 512,
        chunkSize : 200,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0000FF3C,  // 0x085E7AD4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [34] = {
      // 0x085D7BA0
      g : {
        src : 0x0000FF54,  // 0x085E7AF4
        size : 920,
        ofs : 537,
        chunkSize : 320,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000102E0,  // 0x085E7E8C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [35] = {
      // 0x085D7BB4
      g : {
        src : 0x000102F8,  // 0x085E7EAC
        size : 440,
        ofs : 577,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000104A4,  // 0x085E8064
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [36] = {
      // 0x085D7BC8
      g : {
        src : 0x000104BC,  // 0x085E8084
        size : 672,
        ofs : 640,
        chunkSize : 272,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00010750,  // 0x085E8324
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [37] = {
      // 0x085D7BDC
      g : {
        src : 0x00010768,  // 0x085E8344
        size : 1508,
        ofs : 674,
        chunkSize : 936,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00010D40,  // 0x085E8928
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [38] = {
      // 0x085D7BF0
      g : {
        src : 0x00010D58,  // 0x085E8948
        size : 820,
        ofs : 800,
        chunkSize : 440,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00011080,  // 0x085E8C7C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [39] = {
      // 0x085D7C04
      g : {
        src : 0x00011098,  // 0x085E8C9C
        size : 3072,
        ofs : 512,
        chunkSize : 768,
        props : BPP4
      },
      pal : {
        src : 0x00011C8C,  // 0x085E989C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [40] = {
      // 0x085D7C18
      g : {
        src : 0x00011CA4,  // 0x085E98BC
        size : 2816,
        ofs : 512,
        chunkSize : 704,
        props : BPP4
      },
      pal : {
        src : 0x00012798,  // 0x085EA3BC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [41] = {
      // 0x085D7C2C
      g : {
        src : 0x000127B0,  // 0x085EA3DC
        size : 544,
        ofs : 512,
        chunkSize : 136,
        props : BPP4
      },
      pal : {
        src : 0x000129C4,  // 0x085EA5FC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [42] = {
      // 0x085D7C40
      g : {
        src : 0x000129DC,  // 0x085EA61C
        size : 1024,
        ofs : 832,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x00012DD0,  // 0x085EAA1C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [43] = {
      // 0x085D7C54
      g : {
        src : 0x00012DE8,  // 0x085EAA3C
        size : 3948,
        ofs : 512,
        chunkSize : 1792,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00013D48,  // 0x085EB9A8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [44] = {
      // 0x085D7C68
      g : {
        src : 0x00013D80,  // 0x085EB9E8
        size : 816,
        ofs : 768,
        chunkSize : 304,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000140A4,  // 0x085EBD18
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [45] = {
      // 0x085D7C7C
      g : {
        src : 0x000140DC,  // 0x085EBD58
        size : 448,
        ofs : 644,
        chunkSize : 112,
        props : BPP4
      },
      pal : {
        src : 0x00014290,  // 0x085EBF18
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [46] = {
      // 0x085D7C90
      g : {
        src : 0x000142A8,  // 0x085EBF38
        size : 3360,
        ofs : 512,
        chunkSize : 840,
        props : BPP4
      },
      pal : {
        src : 0x00014FBC,  // 0x085ECC58
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [47] = {
      // 0x085D7CA4
      g : {
        src : 0x00014FD4,  // 0x085ECC78
        size : 2560,
        ofs : 512,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x000159C8,  // 0x085ED678
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [48] = {
      // 0x085D7CB8
      g : {
        src : 0x000159E0,  // 0x085ED698
        size : 388,
        ofs : 512,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00015B58,  // 0x085ED81C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [49] = {
      // 0x085D7CCC
      g : {
        src : 0x00015B70,  // 0x085ED83C
        size : 1612,
        ofs : 544,
        chunkSize : 616,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000161B0,  // 0x085EDE88
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [50] = {
      // 0x085D7CE0
      g : {
        src : 0x000161C8,  // 0x085EDEA8
        size : 896,
        ofs : 640,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001653C,  // 0x085EE228
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [51] = {
      // 0x085D7CF4
      g : {
        src : 0x00016574,  // 0x085EE268
        size : 2016,
        ofs : 704,
        chunkSize : 1224,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00016D48,  // 0x085EEA48
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [52] = {
      // 0x085D7D08
      g : {
        src : 0x00016D60,  // 0x085EEA68
        size : 1680,
        ofs : 864,
        chunkSize : 1024,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000173E4,  // 0x085EF0F8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [53] = {
      // 0x085D7D1C
      g : {
        src : 0x000173FC,  // 0x085EF118
        size : 1472,
        ofs : 908,
        chunkSize : 368,
        props : BPP4
      },
      pal : {
        src : 0x000179B0,  // 0x085EF6D8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [54] = {
      // 0x085D7D30
      g : {
        src : 0x000179E8,  // 0x085EF718
        size : 1276,
        ofs : 768,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00017ED8,  // 0x085EFC14
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [55] = {
      // 0x085D7D44
      g : {
        src : 0x00017EF0,  // 0x085EFC34
        size : 1208,
        ofs : 832,
        chunkSize : 1040,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001839C,  // 0x085F00EC
        size : 64 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [56] = {
      // 0x085D7D58
      g : {
        src : 0x00018414,  // 0x085F016C
        size : 1984,
        ofs : 512,
        chunkSize : 496,
        props : BPP4
      },
      pal : {
        src : 0x00018BC8,  // 0x085F092C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [57] = {
      // 0x085D7D6C
      g : {
        src : 0x00018BE0,  // 0x085F094C
        size : 4640,
        ofs : 512,
        chunkSize : 1160,
        props : BPP4
      },
      pal : {
        src : 0x00019DF4,  // 0x085F1B6C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [58] = {
      // 0x085D7D80
      g : {
        src : 0x00019E0C,  // 0x085F1B8C
        size : 960,
        ofs : 704,
        chunkSize : 240,
        props : BPP4
      },
      pal : {
        src : 0x0001A1C0,  // 0x085F1F4C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [59] = {
      // 0x085D7D94
      g : {
        src : 0x0001A1D8,  // 0x085F1F6C
        size : 768,
        ofs : 512,
        chunkSize : 192,
        props : BPP4
      },
      pal : {
        src : 0x0001A4CC,  // 0x085F226C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [60] = {
      // 0x085D7DA8
      g : {
        src : 0x0001A4E4,  // 0x085F228C
        size : 480,
        ofs : 48,
        chunkSize : 384,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0001A6B8,  // 0x085F246C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [61] = {
      // 0x085D7DBC
      g : {
        src : 0x0001A6B0,  // 0x085F246C
        size : 928,
        ofs : 512,
        chunkSize : 232,
        props : (BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0001AA44,  // 0x085F280C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 13,
      },
    },
    [62] = {
      // 0x085D7DD0
      g : {
        src : 0x0001AA3C,  // 0x085F280C
        size : 3200,
        ofs : 640,
        chunkSize : 800,
        props : BPP4
      },
      pal : {
        src : 0x0001B6B0,  // 0x085F348C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [63] = {
      // 0x085D7DE4
      g : {
        src : 0x0001B6C8,  // 0x085F34AC
        size : 2432,
        ofs : 640,
        chunkSize : 608,
        props : BPP4
      },
      pal : {
        src : 0x0001C03C,  // 0x085F3E2C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [64] = {
      // 0x085D7DF8
      g : {
        src : 0x0001C054,  // 0x085F3E4C
        size : 732,
        ofs : 808,
        chunkSize : 248,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001C324,  // 0x085F4128
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [65] = {
      // 0x085D7E0C
      g : {
        src : 0x0001C33C,  // 0x085F4148
        size : 960,
        ofs : 640,
        chunkSize : 240,
        props : BPP4
      },
      pal : {
        src : 0x0001C6F0,  // 0x085F4508
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [66] = {
      // 0x085D7E20
      g : {
        src : 0x0001C708,  // 0x085F4528
        size : 3136,
        ofs : 768,
        chunkSize : 784,
        props : BPP4
      },
      pal : {
        src : 0x0001D33C,  // 0x085F5168
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [67] = {
      // 0x085D7E34
      g : {
        src : 0x0001D354,  // 0x085F5188
        size : 2784,
        ofs : 512,
        chunkSize : 696,
        props : BPP4
      },
      pal : {
        src : 0x0001DE28,  // 0x085F5C68
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [68] = {
      // 0x085D7E48
      g : {
        src : 0x0001DE40,  // 0x085F5C88
        size : 1024,
        ofs : 512,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x0001E234,  // 0x085F6088
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [69] = {
      // 0x085D7E5C
      g : {
        src : 0x0001E24C,  // 0x085F60A8
        size : 4608,
        ofs : 864,
        chunkSize : 1152,
        props : BPP4
      },
      pal : {
        src : 0x0001F440,  // 0x085F72A8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [70] = {
      // 0x085D7E70
      g : {
        src : 0x0001F478,  // 0x085F72E8
        size : 3584,
        ofs : 512,
        chunkSize : 1568,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002026C,  // 0x085F80E8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [71] = {
      // 0x085D7E84
      g : {
        src : 0x00020284,  // 0x085F8108
        size : 1024,
        ofs : 708,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x00020678,  // 0x085F8508
        size : 48 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [72] = {
      // 0x085D7E98
      g : {
        src : 0x000206D0,  // 0x085F8568
        size : 256,
        ofs : 512,
        chunkSize : 64,
        props : BPP4
      },
      pal : {
        src : 0x000207C4,  // 0x085F8668
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [73] = {
      // 0x085D7EAC
      g : {
        src : 0x000207DC,  // 0x085F8688
        size : 436,
        ofs : 640,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00020984,  // 0x085F883C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [74] = {
      // 0x085D7EC0
      g : {
        src : 0x0002099C,  // 0x085F885C
        size : 1692,
        ofs : 660,
        chunkSize : 736,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002102C,  // 0x085F8EF8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [75] = {
      // 0x085D7ED4
      g : {
        src : 0x00021044,  // 0x085F8F18
        size : 2560,
        ofs : 752,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x00021A38,  // 0x085F9918
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [76] = {
      // 0x085D7EE8
      g : {
        src : 0x00021A50,  // 0x085F9938
        size : 6656,
        ofs : 752,
        chunkSize : 1664,
        props : BPP4
      },
      pal : {
        src : 0x00023444,  // 0x085FB338
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [77] = {
      // 0x085D7EFC
      g : {
        src : 0x0002345C,  // 0x085FB358
        size : 1932,
        ofs : 608,
        chunkSize : 880,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00023BDC,  // 0x085FBAE4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [78] = {
      // 0x085D7F10
      g : {
        src : 0x00023BF4,  // 0x085FBB04
        size : 1328,
        ofs : 718,
        chunkSize : 608,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00024118,  // 0x085FC034
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [79] = {
      // 0x085D7F24
      g : {
        src : 0x00024130,  // 0x085FC054
        size : 736,
        ofs : 794,
        chunkSize : 240,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00024404,  // 0x085FC334
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [80] = {
      // 0x085D7F38
      g : {
        src : 0x0002441C,  // 0x085FC354
        size : 464,
        ofs : 824,
        chunkSize : 128,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000245E0,  // 0x085FC524
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [81] = {
      // 0x085D7F4C
      g : {
        src : 0x000245F8,  // 0x085FC544
        size : 4064,
        ofs : 840,
        chunkSize : 1016,
        props : BPP4
      },
      pal : {
        src : 0x000255CC,  // 0x085FD524
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [82] = {
      // 0x085D7F60
      g : {
        src : 0x00025604,  // 0x085FD564
        size : 1004,
        ofs : 879,
        chunkSize : 656,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000259E4,  // 0x085FD950
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [83] = {
      // 0x085D7F74
      g : {
        src : 0x00025A1C,  // 0x085FD990
        size : 1264,
        ofs : 961,
        chunkSize : 504,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00025F00,  // 0x085FDE80
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [84] = {
      // 0x085D7F88
      g : {
        src : 0x00025F18,  // 0x085FDEA0
        size : 2580,
        ofs : 592,
        chunkSize : 1200,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00026920,  // 0x085FE8B4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [85] = {
      // 0x085D7F9C
      g : {
        src : 0x00026938,  // 0x085FE8D4
        size : 472,
        ofs : 742,
        chunkSize : 200,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00026B04,  // 0x085FEAAC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [86] = {
      // 0x085D7FB0
      g : {
        src : 0x00026B1C,  // 0x085FEACC
        size : 1176,
        ofs : 767,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00026FA8,  // 0x085FEF64
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [87] = {
      // 0x085D7FC4
      g : {
        src : 0x00026FC0,  // 0x085FEF84
        size : 772,
        ofs : 831,
        chunkSize : 408,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000272B8,  // 0x085FF288
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [88] = {
      // 0x085D7FD8
      g : {
        src : 0x000272D0,  // 0x085FF2A8
        size : 1664,
        ofs : 895,
        chunkSize : 416,
        props : BPP4
      },
      pal : {
        src : 0x00027944,  // 0x085FF928
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [89] = {
      // 0x085D7FEC
      g : {
        src : 0x0002795C,  // 0x085FF948
        size : 2288,
        ofs : 768,
        chunkSize : 816,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00028240,  // 0x08600238
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [90] = {
      // 0x085D8000
      g : {
        src : 0x00028258,  // 0x08600258
        size : 1152,
        ofs : 896,
        chunkSize : 288,
        props : BPP4
      },
      pal : {
        src : 0x000286CC,  // 0x086006D8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [91] = {
      // 0x085D8014
      g : {
        src : 0x000286E4,  // 0x086006F8
        size : 3280,
        ofs : 576,
        chunkSize : 1272,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000293A8,  // 0x086013C8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [92] = {
      // 0x085D8028
      g : {
        src : 0x000293C0,  // 0x086013E8
        size : 1544,
        ofs : 735,
        chunkSize : 584,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000299BC,  // 0x086019F0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [93] = {
      // 0x085D803C
      g : {
        src : 0x000299D4,  // 0x08601A10
        size : 1432,
        ofs : 808,
        chunkSize : 640,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00029F60,  // 0x08601FA8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [94] = {
      // 0x085D8050
      g : {
        src : 0x00029F78,  // 0x08601FC8
        size : 380,
        ofs : 888,
        chunkSize : 280,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002A0E8,  // 0x08602144
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [95] = {
      // 0x085D8064
      g : {
        src : 0x0002A100,  // 0x08602164
        size : 300,
        ofs : 923,
        chunkSize : 152,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002A220,  // 0x08602290
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [96] = {
      // 0x085D8078
      g : {
        src : 0x0002A238,  // 0x086022B0
        size : 1028,
        ofs : 942,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002A630,  // 0x086026B4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [97] = {
      // 0x085D808C
      g : {
        src : 0x0002A648,  // 0x086026D4
        size : 304,
        ofs : 1006,
        chunkSize : 128,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002A76C,  // 0x08602804
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [98] = {
      // 0x085D80A0
      g : {
        src : 0x0002A784,  // 0x08602824
        size : 3032,
        ofs : 576,
        chunkSize : 1008,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002B350,  // 0x086033FC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [99] = {
      // 0x085D80B4
      g : {
        src : 0x0002B368,  // 0x0860341C
        size : 1468,
        ofs : 702,
        chunkSize : 864,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002B918,  // 0x086039D8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [100] = {
      // 0x085D80C8
      g : {
        src : 0x0002B930,  // 0x086039F8
        size : 960,
        ofs : 810,
        chunkSize : 480,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002BCE4,  // 0x08603DB8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [101] = {
      // 0x085D80DC
      g : {
        src : 0x0002BCFC,  // 0x08603DD8
        size : 4492,
        ofs : 826,
        chunkSize : 1864,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0002CE7C,  // 0x08604F64
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [102] = {
      // 0x085D80F0
      g : {
        src : 0x0002CE94,  // 0x08604F84
        size : 1536,
        ofs : 512,
        chunkSize : 384,
        props : BPP4
      },
      pal : {
        src : 0x0002D488,  // 0x08605584
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [103] = {
      // 0x085D8104
      g : {
        src : 0x0002D4A0,  // 0x086055A4
        size : 4256,
        ofs : 512,
        chunkSize : 1064,
        props : BPP4
      },
      pal : {
        src : 0x0002E534,  // 0x08606644
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [104] = {
      // 0x085D8118
      g : {
        src : 0x0002E54C,  // 0x08606664
        size : 1344,
        ofs : 512,
        chunkSize : 336,
        props : BPP4
      },
      pal : {
        src : 0x0002EA80,  // 0x08606BA4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [105] = {
      // 0x085D812C
      g : {
        src : 0x0002EAB8,  // 0x08606BE4
        size : 3040,
        ofs : 512,
        chunkSize : 760,
        props : BPP4
      },
      pal : {
        src : 0x0002F68C,  // 0x086077C4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [106] = {
      // 0x085D8140
      g : {
        src : 0x0002F6A4,  // 0x086077E4
        size : 2412,
        ofs : 640,
        chunkSize : 1136,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00030004,  // 0x08608150
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [107] = {
      // 0x085D8154
      g : {
        src : 0x0003001C,  // 0x08608170
        size : 1536,
        ofs : 512,
        chunkSize : 384,
        props : BPP4
      },
      pal : {
        src : 0x00030610,  // 0x08608770
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [108] = {
      // 0x085D8168
      g : {
        src : 0x00030628,  // 0x08608790
        size : 1280,
        ofs : 512,
        chunkSize : 320,
        props : BPP4
      },
      pal : {
        src : 0x00030B1C,  // 0x08608C90
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [109] = {
      // 0x085D817C
      g : {
        src : 0x00030B34,  // 0x08608CB0
        size : 3040,
        ofs : 512,
        chunkSize : 760,
        props : BPP4
      },
      pal : {
        src : 0x00031708,  // 0x08609890
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [110] = {
      // 0x085D8190
      g : {
        src : 0x00031720,  // 0x086098B0
        size : 6400,
        ofs : 512,
        chunkSize : 1600,
        props : BPP4
      },
      pal : {
        src : 0x00033014,  // 0x0860B1B0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [111] = {
      // 0x085D81A4
      g : {
        src : 0x0003302C,  // 0x0860B1D0
        size : 512,
        ofs : 800,
        chunkSize : 128,
        props : BPP4
      },
      pal : {
        src : 0x00033220,  // 0x0860B3D0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [112] = {
      // 0x085D81B8
      g : {
        src : 0x00033238,  // 0x0860B3F0
        size : 1632,
        ofs : 800,
        chunkSize : 408,
        props : BPP4
      },
      pal : {
        src : 0x0003388C,  // 0x0860BA50
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [113] = {
      // 0x085D81CC
      g : {
        src : 0x000338A4,  // 0x0860BA70
        size : 1504,
        ofs : 512,
        chunkSize : 376,
        props : BPP4
      },
      pal : {
        src : 0x00033E78,  // 0x0860C050
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [114] = {
      // 0x085D81E0
      g : {
        src : 0x00033E90,  // 0x0860C070
        size : 1632,
        ofs : 560,
        chunkSize : 408,
        props : BPP4
      },
      pal : {
        src : 0x000344E4,  // 0x0860C6D0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [115] = {
      // 0x085D81F4
      g : {
        src : 0x000344FC,  // 0x0860C6F0
        size : 2560,
        ofs : 560,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x00034EF0,  // 0x0860D0F0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [116] = {
      // 0x085D8208
      g : {
        src : 0x00034F08,  // 0x0860D110
        size : 3040,
        ofs : 512,
        chunkSize : 760,
        props : BPP4
      },
      pal : {
        src : 0x00035ADC,  // 0x0860DCF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [117] = {
      // 0x085D821C
      g : {
        src : 0x00035AF4,  // 0x0860DD10
        size : 1568,
        ofs : 512,
        chunkSize : 392,
        props : BPP4
      },
      pal : {
        src : 0x00036108,  // 0x0860E330
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [118] = {
      // 0x085D8230
      g : {
        src : 0x00036120,  // 0x0860E350
        size : 1120,
        ofs : 624,
        chunkSize : 280,
        props : BPP4
      },
      pal : {
        src : 0x00036574,  // 0x0860E7B0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [119] = {
      // 0x085D8244
      g : {
        src : 0x0003658C,  // 0x0860E7D0
        size : 2048,
        ofs : 512,
        chunkSize : 512,
        props : BPP4
      },
      pal : {
        src : 0x00036D80,  // 0x0860EFD0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [120] = {
      // 0x085D8258
      g : {
        src : 0x00036D98,  // 0x0860EFF0
        size : 992,
        ofs : 480,
        chunkSize : 248,
        props : BPP4
      },
      pal : {
        src : 0x0003716C,  // 0x0860F3D0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [121] = {
      // 0x085D826C
      g : {
        src : 0x00037184,  // 0x0860F3F0
        size : 5408,
        ofs : 512,
        chunkSize : 1352,
        props : BPP4
      },
      pal : {
        src : 0x00038698,  // 0x08610910
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [122] = {
      // 0x085D8280
      g : {
        src : 0x000386B0,  // 0x08610930
        size : 960,
        ofs : 480,
        chunkSize : 240,
        props : BPP4
      },
      pal : {
        src : 0x00038A64,  // 0x08610CF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [123] = {
      // 0x085D8294
      g : {
        src : 0x00038A7C,  // 0x08610D10
        size : 2656,
        ofs : 512,
        chunkSize : 664,
        props : BPP4
      },
      pal : {
        src : 0x000394D0,  // 0x08611770
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [124] = {
      // 0x085D82A8
      g : {
        src : 0x000394E8,  // 0x08611790
        size : 1120,
        ofs : 512,
        chunkSize : 280,
        props : BPP4
      },
      pal : {
        src : 0x0003993C,  // 0x08611BF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [125] = {
      // 0x085D82BC
      g : {
        src : 0x00039954,  // 0x08611C10
        size : 1920,
        ofs : 512,
        chunkSize : 480,
        props : BPP4
      },
      pal : {
        src : 0x0003A0C8,  // 0x08612390
        size : 48 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [126] = {
      // 0x085D82D0
      g : {
        src : 0x0003A120,  // 0x086123F0
        size : 2560,
        ofs : 512,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x0003AB14,  // 0x08612DF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [127] = {
      // 0x085D82E4
      g : {
        src : 0x0003AB2C,  // 0x08612E10
        size : 244,
        ofs : 512,
        chunkSize : 96,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003AC14,  // 0x08612F04
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [128] = {
      // 0x085D82F8
      g : {
        src : 0x0003AC2C,  // 0x08612F24
        size : 2928,
        ofs : 656,
        chunkSize : 1832,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003B790,  // 0x08613A94
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [129] = {
      // 0x085D830C
      g : {
        src : 0x0003B7A8,  // 0x08613AB4
        size : 900,
        ofs : 737,
        chunkSize : 480,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003BB20,  // 0x08613E38
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [130] = {
      // 0x085D8320
      g : {
        src : 0x0003BB38,  // 0x08613E58
        size : 1452,
        ofs : 737,
        chunkSize : 432,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003C0D8,  // 0x08614404
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [131] = {
      // 0x085D8334
      g : {
        src : 0x0003C0F0,  // 0x08614424
        size : 3128,
        ofs : 576,
        chunkSize : 1280,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003CD1C,  // 0x0861505C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [132] = {
      // 0x085D8348
      g : {
        src : 0x0003CD34,  // 0x0861507C
        size : 2108,
        ofs : 736,
        chunkSize : 824,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003D564,  // 0x086158B8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [133] = {
      // 0x085D835C
      g : {
        src : 0x0003D57C,  // 0x086158D8
        size : 2676,
        ofs : 859,
        chunkSize : 944,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003DFE4,  // 0x0861634C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [134] = {
      // 0x085D8370
      g : {
        src : 0x0003DFFC,  // 0x0861636C
        size : 1260,
        ofs : 576,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003E4DC,  // 0x08616858
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [135] = {
      // 0x085D8384
      g : {
        src : 0x0003E4F4,  // 0x08616878
        size : 1940,
        ofs : 640,
        chunkSize : 992,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003EC7C,  // 0x0861700C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [136] = {
      // 0x085D8398
      g : {
        src : 0x0003EC94,  // 0x0861702C
        size : 560,
        ofs : 764,
        chunkSize : 304,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0003EEB8,  // 0x0861725C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [137] = {
      // 0x085D83AC
      g : {
        src : 0x0003EED0,  // 0x0861727C
        size : 2560,
        ofs : 560,
        chunkSize : 640,
        props : BPP4
      },
      pal : {
        src : 0x0003F8C4,  // 0x08617C7C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [138] = {
      // 0x085D83C0
      g : {
        src : 0x0003F8DC,  // 0x08617C9C
        size : 1312,
        ofs : 560,
        chunkSize : 328,
        props : BPP4
      },
      pal : {
        src : 0x0003FDF0,  // 0x086181BC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [139] = {
      // 0x085D83D4
      g : {
        src : 0x0003FE08,  // 0x086181DC
        size : 1732,
        ofs : 512,
        chunkSize : 1832,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000404C0,  // 0x086188A0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [140] = {
      // 0x085D83E8
      g : {
        src : 0x000404D8,  // 0x086188C0
        size : 2780,
        ofs : 656,
        chunkSize : 976,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00040FA8,  // 0x0861939C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [141] = {
      // 0x085D83FC
      g : {
        src : 0x00040FC0,  // 0x086193BC
        size : 0,
        ofs : 512,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00040FB4,  // 0x086193BC
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [142] = {
      // 0x085D8410
      g : {
        src : 0x00040FAC,  // 0x086193BC
        size : 1344,
        ofs : 512,
        chunkSize : 336,
        props : BPP4
      },
      pal : {
        src : 0x000414E0,  // 0x086198FC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [143] = {
      // 0x085D8424
      g : {
        src : 0x000414F8,  // 0x0861991C
        size : 0,
        ofs : 512,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000414EC,  // 0x0861991C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [144] = {
      // 0x085D8438
      g : {
        src : 0x000414E4,  // 0x0861991C
        size : 616,
        ofs : 512,
        chunkSize : 304,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00041740,  // 0x08619B84
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [145] = {
      // 0x085D844C
      g : {
        src : 0x00041758,  // 0x08619BA4
        size : 724,
        ofs : 512,
        chunkSize : 320,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00041A20,  // 0x08619E78
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [146] = {
      // 0x085D8460
      g : {
        src : 0x00041A38,  // 0x08619E98
        size : 924,
        ofs : 512,
        chunkSize : 424,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00041DC8,  // 0x0861A234
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [147] = {
      // 0x085D8474
      g : {
        src : 0x00041DE0,  // 0x0861A254
        size : 696,
        ofs : 512,
        chunkSize : 424,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004208C,  // 0x0861A50C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [148] = {
      // 0x085D8488
      g : {
        src : 0x000420A4,  // 0x0861A52C
        size : 792,
        ofs : 512,
        chunkSize : 320,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000423B0,  // 0x0861A844
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [149] = {
      // 0x085D849C
      g : {
        src : 0x000423C8,  // 0x0861A864
        size : 2232,
        ofs : 0,
        chunkSize : 896,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00042C74,  // 0x0861B11C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    [150] = {
      // 0x085D84B0
      g : {
        src : 0x00042C8C,  // 0x0861B13C
        size : 2628,
        ofs : 512,
        chunkSize : 1064,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000436C4,  // 0x0861BB80
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 3,
      },
    },
    [151] = {
      // 0x085D84C4
      g : {
        src : 0x000436DC,  // 0x0861BBA0
        size : 544,
        ofs : 512,
        chunkSize : 136,
        props : BPP4
      },
      pal : {
        src : 0x000438F0,  // 0x0861BDC0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [152] = {
      // 0x085D84D8
      g : {
        src : 0x00043908,  // 0x0861BDE0
        size : 4064,
        ofs : 512,
        chunkSize : 1016,
        props : BPP4
      },
      pal : {
        src : 0x000448DC,  // 0x0861CDC0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [153] = {
      // 0x085D84EC
      g : {
        src : 0x00044914,  // 0x0861CE00
        size : 1632,
        ofs : 512,
        chunkSize : 408,
        props : BPP4
      },
      pal : {
        src : 0x00044F68,  // 0x0861D460
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [154] = {
      // 0x085D8500
      g : {
        src : 0x00044F80,  // 0x0861D480
        size : 768,
        ofs : 512,
        chunkSize : 192,
        props : BPP4
      },
      pal : {
        src : 0x00045274,  // 0x0861D780
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [155] = {
      // 0x085D8514
      g : {
        src : 0x0004528C,  // 0x0861D7A0
        size : 1024,
        ofs : 640,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x00045680,  // 0x0861DBA0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [156] = {
      // 0x085D8528
      g : {
        src : 0x00045698,  // 0x0861DBC0
        size : 384,
        ofs : 768,
        chunkSize : 96,
        props : BPP4
      },
      pal : {
        src : 0x0004580C,  // 0x0861DD40
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [157] = {
      // 0x085D853C
      g : {
        src : 0x00045824,  // 0x0861DD60
        size : 1024,
        ofs : 512,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x00045C18,  // 0x0861E160
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [158] = {
      // 0x085D8550
      g : {
        src : 0x00045C30,  // 0x0861E180
        size : 136,
        ofs : 512,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00045CAC,  // 0x0861E208
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [159] = {
      // 0x085D8564
      g : {
        src : 0x00045CC4,  // 0x0861E228
        size : 140,
        ofs : 512,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00045D44,  // 0x0861E2B4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [160] = {
      // 0x085D8578
      g : {
        src : 0x00045D5C,  // 0x0861E2D4
        size : 132,
        ofs : 640,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00045DD4,  // 0x0861E358
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [161] = {
      // 0x085D858C
      g : {
        src : 0x00045DEC,  // 0x0861E378
        size : 144,
        ofs : 512,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00045E70,  // 0x0861E408
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [162] = {
      // 0x085D85A0
      g : {
        src : 0x00045E88,  // 0x0861E428
        size : 384,
        ofs : 512,
        chunkSize : 96,
        props : BPP4
      },
      pal : {
        src : 0x00045FFC,  // 0x0861E5A8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [163] = {
      // 0x085D85B4
      g : {
        src : 0x00046014,  // 0x0861E5C8
        size : 960,
        ofs : 512,
        chunkSize : 240,
        props : BPP4
      },
      pal : {
        src : 0x000463C8,  // 0x0861E988
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [164] = {
      // 0x085D85C8
      g : {
        src : 0x000463E0,  // 0x0861E9A8
        size : 608,
        ofs : 512,
        chunkSize : 152,
        props : BPP4
      },
      pal : {
        src : 0x00046634,  // 0x0861EC08
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [165] = {
      // 0x085D85DC
      g : {
        src : 0x0004664C,  // 0x0861EC28
        size : 576,
        ofs : 512,
        chunkSize : 144,
        props : BPP4
      },
      pal : {
        src : 0x00046880,  // 0x0861EE68
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [166] = {
      // 0x085D85F0
      g : {
        src : 0x00046898,  // 0x0861EE88
        size : 576,
        ofs : 512,
        chunkSize : 144,
        props : BPP4
      },
      pal : {
        src : 0x00046ACC,  // 0x0861F0C8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [167] = {
      // 0x085D8604
      g : {
        src : 0x00046AE4,  // 0x0861F0E8
        size : 404,
        ofs : 442,
        chunkSize : 128,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00046C6C,  // 0x0861F27C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [168] = {
      // 0x085D8618
      g : {
        src : 0x00046C84,  // 0x0861F29C
        size : 396,
        ofs : 442,
        chunkSize : 128,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00046E04,  // 0x0861F428
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [169] = {
      // 0x085D862C
      g : {
        src : 0x00046E1C,  // 0x0861F448
        size : 424,
        ofs : 442,
        chunkSize : 128,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00046FB8,  // 0x0861F5F0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [170] = {
      // 0x085D8640
      g : {
        src : 0x00046FD0,  // 0x0861F610
        size : 228,
        ofs : 458,
        chunkSize : 88,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000470A8,  // 0x0861F6F4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [171] = {
      // 0x085D8654
      g : {
        src : 0x000470C0,  // 0x0861F714
        size : 164,
        ofs : 458,
        chunkSize : 88,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00047158,  // 0x0861F7B8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [172] = {
      // 0x085D8668
      g : {
        src : 0x00047170,  // 0x0861F7D8
        size : 216,
        ofs : 458,
        chunkSize : 88,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004723C,  // 0x0861F8B0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [173] = {
      // 0x085D867C
      g : {
        src : 0x00047254,  // 0x0861F8D0
        size : 108,
        ofs : 469,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000472B4,  // 0x0861F93C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [174] = {
      // 0x085D8690
      g : {
        src : 0x000472CC,  // 0x0861F95C
        size : 100,
        ofs : 469,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00047324,  // 0x0861F9C0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [175] = {
      // 0x085D86A4
      g : {
        src : 0x0004733C,  // 0x0861F9E0
        size : 116,
        ofs : 469,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000473A4,  // 0x0861FA54
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [176] = {
      // 0x085D86B8
      g : {
        src : 0x000473BC,  // 0x0861FA74
        size : 136,
        ofs : 473,
        chunkSize : 40,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00047438,  // 0x0861FAFC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [177] = {
      // 0x085D86CC
      g : {
        src : 0x00047450,  // 0x0861FB1C
        size : 148,
        ofs : 473,
        chunkSize : 40,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000474D8,  // 0x0861FBB0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [178] = {
      // 0x085D86E0
      g : {
        src : 0x000474F0,  // 0x0861FBD0
        size : 124,
        ofs : 473,
        chunkSize : 40,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00047560,  // 0x0861FC4C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [179] = {
      // 0x085D86F4
      g : {
        src : 0x00047578,  // 0x0861FC6C
        size : 24,
        ofs : 796,
        chunkSize : 8,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x00047584,  // 0x0861FC84
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [180] = {
      // 0x085D8708
      g : {
        src : 0x0004757C,  // 0x0861FC84
        size : 3616,
        ofs : 512,
        chunkSize : 904,
        props : BPP4
      },
      pal : {
        src : 0x00048390,  // 0x08620AA4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [181] = {
      // 0x085D871C
      g : {
        src : 0x000483A8,  // 0x08620AC4
        size : 384,
        ofs : 512,
        chunkSize : 96,
        props : BPP4
      },
      pal : {
        src : 0x0004851C,  // 0x08620C44
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [182] = {
      // 0x085D8730
      g : {
        src : 0x00048534,  // 0x08620C64
        size : 928,
        ofs : 512,
        chunkSize : 232,
        props : BPP4
      },
      pal : {
        src : 0x000488C8,  // 0x08621004
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [183] = {
      // 0x085D8744
      g : {
        src : 0x000488E0,  // 0x08621024
        size : 256,
        ofs : 512,
        chunkSize : 64,
        props : (BPP4 | NO_PAL)
      },
      pal : {
        src : 0x000489D4,  // 0x08621124
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [184] = {
      // 0x085D8758
      g : {
        src : 0x000489CC,  // 0x08621124
        size : 3936,
        ofs : 512,
        chunkSize : 984,
        props : BPP4
      },
      pal : {
        src : 0x00049920,  // 0x08622084
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [185] = {
      // 0x085D876C
      g : {
        src : 0x00049938,  // 0x086220A4
        size : 612,
        ofs : 512,
        chunkSize : 248,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00049B90,  // 0x08622308
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    [186] = {
      // 0x085D8780
      g : {
        src : 0x00049BA8,  // 0x08622328
        size : 1412,
        ofs : 512,
        chunkSize : 408,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004A120,  // 0x086228AC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [187] = {
      // 0x085D8794
      g : {
        src : 0x0004A138,  // 0x086228CC
        size : 1824,
        ofs : 512,
        chunkSize : 456,
        props : BPP4
      },
      pal : {
        src : 0x0004A84C,  // 0x08622FEC
        size : 48 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [188] = {
      // 0x085D87A8
      g : {
        src : 0x0004A8A4,  // 0x0862304C
        size : 388,
        ofs : 512,
        chunkSize : 104,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004AA1C,  // 0x086231D0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [189] = {
      // 0x085D87BC
      g : {
        src : 0x0004AA34,  // 0x086231F0
        size : 560,
        ofs : 512,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004AC58,  // 0x08623420
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [190] = {
      // 0x085D87D0
      g : {
        src : 0x0004AC70,  // 0x08623440
        size : 368,
        ofs : 512,
        chunkSize : 96,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004ADD4,  // 0x086235B0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [191] = {
      // 0x085D87E4
      g : {
        src : 0x0004ADEC,  // 0x086235D0
        size : 468,
        ofs : 512,
        chunkSize : 120,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004AFB4,  // 0x086237A4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [192] = {
      // 0x085D87F8
      g : {
        src : 0x0004AFCC,  // 0x086237C4
        size : 360,
        ofs : 512,
        chunkSize : 88,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004B128,  // 0x0862392C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [193] = {
      // 0x085D880C
      g : {
        src : 0x0004B140,  // 0x0862394C
        size : 448,
        ofs : 512,
        chunkSize : 120,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004B2F4,  // 0x08623B0C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [194] = {
      // 0x085D8820
      g : {
        src : 0x0004B30C,  // 0x08623B2C
        size : 1524,
        ofs : 512,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004B8F4,  // 0x08624120
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [195] = {
      // 0x085D8834
      g : {
        src : 0x0004B90C,  // 0x08624140
        size : 1044,
        ofs : 512,
        chunkSize : 328,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004BD14,  // 0x08624554
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [196] = {
      // 0x085D8848
      g : {
        src : 0x0004BD2C,  // 0x08624574
        size : 980,
        ofs : 512,
        chunkSize : 320,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004C0F4,  // 0x08624948
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [197] = {
      // 0x085D885C
      g : {
        src : 0x0004C10C,  // 0x08624968
        size : 348,
        ofs : 512,
        chunkSize : 96,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004C25C,  // 0x08624AC4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [198] = {
      // 0x085D8870
      g : {
        src : 0x0004C274,  // 0x08624AE4
        size : 540,
        ofs : 512,
        chunkSize : 192,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004C484,  // 0x08624D00
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [199] = {
      // 0x085D8884
      g : {
        src : 0x0004C49C,  // 0x08624D20
        size : 400,
        ofs : 512,
        chunkSize : 104,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004C620,  // 0x08624EB0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [200] = {
      // 0x085D8898
      g : {
        src : 0x0004C638,  // 0x08624ED0
        size : 1280,
        ofs : 512,
        chunkSize : 320,
        props : BPP4
      },
      pal : {
        src : 0x0004CB2C,  // 0x086253D0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [201] = {
      // 0x085D88AC
      g : {
        src : 0x0004CB44,  // 0x086253F0
        size : 412,
        ofs : 544,
        chunkSize : 168,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004CCD4,  // 0x0862558C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [202] = {
      // 0x085D88C0
      g : {
        src : 0x0004CCEC,  // 0x086255AC
        size : 408,
        ofs : 565,
        chunkSize : 192,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004CE78,  // 0x08625744
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [203] = {
      // 0x085D88D4
      g : {
        src : 0x0004CE90,  // 0x08625764
        size : 2048,
        ofs : 512,
        chunkSize : 512,
        props : BPP4
      },
      pal : {
        src : 0x0004D684,  // 0x08625F64
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [204] = {
      // 0x085D88E8
      g : {
        src : 0x0004D69C,  // 0x08625F84
        size : 156,
        ofs : 996,
        chunkSize : 144,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004D72C,  // 0x08626020
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [205] = {
      // 0x085D88FC
      g : {
        src : 0x0004D744,  // 0x08626040
        size : 3664,
        ofs : 740,
        chunkSize : 2048,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004E588,  // 0x08626E90
        size : 64 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [206] = {
      // 0x085D8910
      g : {
        src : 0x0004E600,  // 0x08626F10
        size : 3840,
        ofs : 740,
        chunkSize : 2048,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004F4F4,  // 0x08627E10
        size : 64 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [207] = {
      // 0x085D8924
      g : {
        src : 0x0004F56C,  // 0x08627E90
        size : 396,
        ofs : 676,
        chunkSize : 512,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004F6EC,  // 0x0862801C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [208] = {
      // 0x085D8938
      g : {
        src : 0x0004F704,  // 0x0862803C
        size : 3632,
        ofs : 740,
        chunkSize : 2048,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00050528,  // 0x08628E6C
        size : 64 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [209] = {
      // 0x085D894C
      g : {
        src : 0x000505A0,  // 0x08628EEC
        size : 320,
        ofs : 368,
        chunkSize : 80,
        props : (BPP4 | NO_PAL)
      },
      pal : {
        src : 0x000506D4,  // 0x0862902C
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 15,
      },
    },
    [210] = {
      // 0x085D8960
      g : {
        src : 0x000506CC,  // 0x0862902C
        size : 864,
        ofs : 512,
        chunkSize : 216,
        props : BPP4
      },
      pal : {
        src : 0x00050A20,  // 0x0862938C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [211] = {
      // 0x085D8974
      g : {
        src : 0x00050A38,  // 0x086293AC
        size : 32,
        ofs : 512,
        chunkSize : 8,
        props : BPP4
      },
      pal : {
        src : 0x00050A4C,  // 0x086293CC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [212] = {
      // 0x085D8988
      g : {
        src : 0x00050A64,  // 0x086293EC
        size : 4224,
        ofs : 512,
        chunkSize : 1056,
        props : BPP4
      },
      pal : {
        src : 0x00051AD8,  // 0x0862A46C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [213] = {
      // 0x085D899C
      g : {
        src : 0x00051AF0,  // 0x0862A48C
        size : 2400,
        ofs : 512,
        chunkSize : 600,
        props : BPP4
      },
      pal : {
        src : 0x00052444,  // 0x0862ADEC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [214] = {
      // 0x085D89B0
      g : {
        src : 0x0005245C,  // 0x0862AE0C
        size : 5280,
        ofs : 512,
        chunkSize : 1320,
        props : BPP4
      },
      pal : {
        src : 0x000538F0,  // 0x0862C2AC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [215] = {
      // 0x085D89C4
      g : {
        src : 0x00053908,  // 0x0862C2CC
        size : 864,
        ofs : 768,
        chunkSize : 216,
        props : BPP4
      },
      pal : {
        src : 0x00053C5C,  // 0x0862C62C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [216] = {
      // 0x085D89D8
      g : {
        src : 0x00053C74,  // 0x0862C64C
        size : 896,
        ofs : 512,
        chunkSize : 224,
        props : BPP4
      },
      pal : {
        src : 0x00053FE8,  // 0x0862C9CC
        size : 48 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [217] = {
      // 0x085D89EC
      g : {
        src : 0x00054040,  // 0x0862CA2C
        size : 544,
        ofs : 512,
        chunkSize : 136,
        props : BPP4
      },
      pal : {
        src : 0x00054254,  // 0x0862CC4C
        size : 48 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [218] = {
      // 0x085D8A00
      g : {
        src : 0x000542AC,  // 0x0862CCAC
        size : 1504,
        ofs : 512,
        chunkSize : 376,
        props : BPP4
      },
      pal : {
        src : 0x00054880,  // 0x0862D28C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [219] = {
      // 0x085D8A14
      g : {
        src : 0x00054898,  // 0x0862D2AC
        size : 4064,
        ofs : 512,
        chunkSize : 1016,
        props : BPP4
      },
      pal : {
        src : 0x0005586C,  // 0x0862E28C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [220] = {
      // 0x085D8A28
      g : {
        src : 0x00055884,  // 0x0862E2AC
        size : 1792,
        ofs : 512,
        chunkSize : 448,
        props : BPP4
      },
      pal : {
        src : 0x00055F78,  // 0x0862E9AC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [221] = {
      // 0x085D8A3C
      g : {
        src : 0x00055F90,  // 0x0862E9CC
        size : 3008,
        ofs : 512,
        chunkSize : 752,
        props : BPP4
      },
      pal : {
        src : 0x00056B44,  // 0x0862F58C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [222] = {
      // 0x085D8A50
      g : {
        src : 0x00056B5C,  // 0x0862F5AC
        size : 1792,
        ofs : 512,
        chunkSize : 448,
        props : BPP4
      },
      pal : {
        src : 0x00057250,  // 0x0862FCAC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [223] = {
      // 0x085D8A64
      g : {
        src : 0x00057268,  // 0x0862FCCC
        size : 672,
        ofs : 512,
        chunkSize : 168,
        props : BPP4
      },
      pal : {
        src : 0x000574FC,  // 0x0862FF6C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [224] = {
      // 0x085D8A78
      g : {
        src : 0x00057514,  // 0x0862FF8C
        size : 704,
        ofs : 512,
        chunkSize : 176,
        props : BPP4
      },
      pal : {
        src : 0x000577C8,  // 0x0863024C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [225] = {
      // 0x085D8A8C
      g : {
        src : 0x000577E0,  // 0x0863026C
        size : 5096,
        ofs : 512,
        chunkSize : 1952,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00058BBC,  // 0x08631654
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [226] = {
      // 0x085D8AA0
      g : {
        src : 0x00058BD4,  // 0x08631674
        size : 832,
        ofs : 380,
        chunkSize : 208,
        props : BPP4
      },
      pal : {
        src : 0x00058F08,  // 0x086319B4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    [227] = {
      // 0x085D8AB4
      g : {
        src : 0x00058F20,  // 0x086319D4
        size : 832,
        ofs : 380,
        chunkSize : 208,
        props : BPP4
      },
      pal : {
        src : 0x00059254,  // 0x08631D14
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    [228] = {
      // 0x085D8AC8
      g : {
        src : 0x0005926C,  // 0x08631D34
        size : 832,
        ofs : 380,
        chunkSize : 208,
        props : BPP4
      },
      pal : {
        src : 0x000595A0,  // 0x08632074
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    [229] = {
      // 0x085D8ADC
      g : {
        src : 0x000595B8,  // 0x08632094
        size : 192,
        ofs : 380,
        chunkSize : 48,
        props : BPP4
      },
      pal : {
        src : 0x0005966C,  // 0x08632154
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    [230] = {
      // 0x085D8AF0
      g : {
        src : 0x00059684,  // 0x08632174
        size : 608,
        ofs : 512,
        chunkSize : 152,
        props : BPP4
      },
      pal : {
        src : 0x000598D8,  // 0x086323D4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [231] = {
      // 0x085D8B04
      g : {
        src : 0x000598F0,  // 0x086323F4
        size : 448,
        ofs : 512,
        chunkSize : 112,
        props : BPP4
      },
      pal : {
        src : 0x00059AA4,  // 0x086325B4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [232] = {
      // 0x085D8B18
      g : {
        src : 0x00059ABC,  // 0x086325D4
        size : 512,
        ofs : 512,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00059CB0,  // 0x086327D4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [233] = {
      // 0x085D8B2C
      g : {
        src : 0x00059CC8,  // 0x086327F4
        size : 960,
        ofs : 556,
        chunkSize : 568,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005A07C,  // 0x08632BB4
        size : 80 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [234] = {
      // 0x085D8B40
      g : {
        src : 0x0005A114,  // 0x08632C54
        size : 912,
        ofs : 628,
        chunkSize : 448,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005A498,  // 0x08632FE4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    [235] = {
      // 0x085D8B54
      g : {
        src : 0x0005A4B0,  // 0x08633004
        size : 1024,
        ofs : 0,
        chunkSize : 256,
        props : (BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0005A8A4,  // 0x08633404
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    [236] = {
      // 0x085D8B68
      g : {
        src : 0x0005A89C,  // 0x08633404
        size : 688,
        ofs : 968,
        chunkSize : 448,
        props : (LZ77 | BPP4 | NO_PAL)
      },
      pal : {
        src : 0x0005AB40,  // 0x086336B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 13,
      },
    },
    [237] = {
      // 0x085D8B7C
      g : {
        src : 0x0005AB38,  // 0x086336B4
        size : 592,
        ofs : 912,
        chunkSize : 184,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005AD7C,  // 0x08633904
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [238] = {
      // 0x085D8B90
      g : {
        src : 0x0005AD94,  // 0x08633924
        size : 448,
        ofs : 362,
        chunkSize : 112,
        props : BPP4
      },
      pal : {
        src : 0x0005AF48,  // 0x08633AE4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 15,
      },
    },
    [239] = {
      // 0x085D8BA4
      g : {
        src : 0x0005AF60,  // 0x08633B04
        size : 848,
        ofs : 768,
        chunkSize : 312,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005B2A4,  // 0x08633E54
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 5,
      },
    },
    [240] = {
      // 0x085D8BB8
      g : {
        src : 0x0005B2BC,  // 0x08633E74
        size : 1176,
        ofs : 807,
        chunkSize : 392,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005B748,  // 0x0863430C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [241] = {
      // 0x085D8BCC
      g : {
        src : 0x0005B760,  // 0x0863432C
        size : 384,
        ofs : 856,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005B8D4,  // 0x086344AC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [242] = {
      // 0x085D8BE0
      g : {
        src : 0x0005B8EC,  // 0x086344CC
        size : 412,
        ofs : 876,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005BA7C,  // 0x08634668
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    [243] = {
      // 0x085D8BF4
      g : {
        src : 0x0005BA94,  // 0x08634688
        size : 248,
        ofs : 512,
        chunkSize : 96,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005BB80,  // 0x08634780
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    [244] = {
      // 0x085D8C08
      g : {
        src : 0x0005BB98,  // 0x086347A0
        size : 536,
        ofs : 942,
        chunkSize : 376,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005BDA4,  // 0x086349B8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    [245] = {
      // 0x085D8C1C
      g : {
        src : 0x0005BDBC,  // 0x086349D8
        size : 628,
        ofs : 512,
        chunkSize : 216,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005C024,  // 0x08634C4C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [246] = {
      // 0x085D8C30
      g : {
        src : 0x0005C03C,  // 0x08634C6C
        size : 352,
        ofs : 512,
        chunkSize : 88,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005C190,  // 0x08634DCC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [247] = {
      // 0x085D8C44
      g : {
        src : 0x0005C1A8,  // 0x08634DEC
        size : 516,
        ofs : 512,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005C3A0,  // 0x08634FF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [248] = {
      // 0x085D8C58
      g : {
        src : 0x0005C3B8,  // 0x08635010
        size : 740,
        ofs : 512,
        chunkSize : 208,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005C690,  // 0x086352F4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [249] = {
      // 0x085D8C6C
      g : {
        src : 0x0005C6A8,  // 0x08635314
        size : 540,
        ofs : 512,
        chunkSize : 144,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005C8B8,  // 0x08635530
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [250] = {
      // 0x085D8C80
      g : {
        src : 0x0005C8D0,  // 0x08635550
        size : 512,
        ofs : 512,
        chunkSize : 160,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005CAC4,  // 0x08635750
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [251] = {
      // 0x085D8C94
      g : {
        src : 0x0005CADC,  // 0x08635770
        size : 1012,
        ofs : 512,
        chunkSize : 328,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005CEC4,  // 0x08635B64
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [252] = {
      // 0x085D8CA8
      g : {
        src : 0x0005CEDC,  // 0x08635B84
        size : 536,
        ofs : 512,
        chunkSize : 168,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0005D0E8,  // 0x08635D9C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
    [253] = {
      // 0x085D8CBC
      g : {
        src : 0x0005D100,  // 0x08635DBC
        size : 288,
        ofs : 512,
        chunkSize : 72,
        props : BPP4
      },
      pal : {
        src : 0x0005D214,  // 0x08635EDC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 4,
      },
    },
};

INCLZ("graphics/sprite_prop/effects");
INCBIN("graphics/sprite_prop/effects_2.pal");
INCLZ("graphics/sprite_prop/01")
INCBIN("graphics/sprite_prop/lemon.lz")
INCBIN("graphics/sprite_prop/emotion_bubble.4bpp")
INC4BPP("graphics/sprite_prop/shotcounter")
INCLZ("graphics/sprite_prop/gravel")
INC4BPP("graphics/sprite_prop/batring")
INC4BPP("graphics/sprite_prop/grand_cannon")
INC4BPP("graphics/sprite_prop/pillar_cannon")
INCLZ("graphics/sprite_prop/omega_arm")
INCLZ("graphics/sprite_prop/omega_ring")
INCLZ("graphics/sprite_prop/omega_recover")
INC4BPP("graphics/sprite_prop/gfx_085d79e8")
INC4BPP("graphics/sprite_prop/shrimpolin")
INCBIN("graphics/sprite_prop/shrimpolin_red.pal")
INCLZ("graphics/sprite_prop/chipicon")
INCBIN("graphics/sprite_prop/chipicon_2.pal")
INCLZ("graphics/sprite_prop/menu_item")
INC4BPP("graphics/sprite_prop/icebon")
INC4BPP("graphics/sprite_prop/icebon_ice")
INC4BPP("graphics/sprite_prop/12");
INC4BPP("graphics/sprite_prop/pantheon_hunter")
INC4BPP("graphics/sprite_prop/pantheon_guardian")
INC4BPP("graphics/sprite_prop/top_gabyoall")
INC4BPP("graphics/sprite_prop/flopper")
INC4BPP("graphics/sprite_prop/gyro_cannon")
INC4BPP("graphics/sprite_prop/sharkseal_x")
INCBIN("graphics/sprite_prop/sharkseal_x_2.pal")
INC4BPP("graphics/sprite_prop/lamplort")

INCBIN("graphics/sprite_prop/1a.lz")
INCBIN("graphics/sprite_prop/1b.lz")
INCBIN("graphics/sprite_prop/1c.lz")

INC4BPP("graphics/sprite_prop/lemmingles");
INC4BPP("graphics/sprite_prop/lemmingles_nest");
INC4BPP("graphics/sprite_prop/1f");
INC4BPP("graphics/sprite_prop/20");
INCLZ("graphics/sprite_prop/21");
INCLZ("graphics/sprite_prop/carryarm");
INCLZ("graphics/sprite_prop/container");
INCLZ("graphics/sprite_prop/24");
INCLZ("graphics/sprite_prop/ear_shot");
INCLZ("graphics/sprite_prop/26");
INC4BPP("graphics/sprite_prop/pantheon_aqua");
INC4BPP("graphics/sprite_prop/snakecord");
INC4BPP("graphics/sprite_prop/hammer");
INC4BPP("graphics/sprite_prop/purple_nerple");
INCLZ("graphics/sprite_prop/wormer");
INCBIN("graphics/sprite_prop/wormer_ice.pal");
INCLZ("graphics/sprite_prop/wormer_rock_drone");
INCBIN("graphics/sprite_prop/wormer_rock_drone_2.pal");
INC4BPP("graphics/sprite_prop/2d");
INC4BPP("graphics/sprite_prop/volcaire");
INC4BPP("graphics/sprite_prop/tile_cannon");
INCLZ("graphics/sprite_prop/baby_elf");
INCLZ("graphics/sprite_prop/crea_prea_31");
INCLZ("graphics/sprite_prop/crea_prea_32");
INCBIN("graphics/sprite_prop/crea_prea_32_2.pal");
INCLZ("graphics/sprite_prop/crea_prea_33");
INCLZ("graphics/sprite_prop/crea_prea_34");
INC4BPP("graphics/sprite_prop/shelluno");
INCBIN("graphics/sprite_prop/shelluno_2.pal");
INCLZ("graphics/sprite_prop/deathtanz_rock");
INCLZ("graphics/sprite_prop/deathtanz_projectile");
INCBIN("graphics/sprite_prop/deathtanz_projectile_2.pal");
INCBIN("graphics/sprite_prop/deathtanz_projectile_3.pal");
INCBIN("graphics/sprite_prop/deathtanz_projectile_4.pal");
INC4BPP("graphics/sprite_prop/heavy_cannon");
INC4BPP("graphics/sprite_prop/geyser");
INC4BPP("graphics/sprite_prop/3a_plate");
INC4BPP("graphics/sprite_prop/3b_lava_platform");
INCBIN("graphics/sprite_prop/3c_exlife_indicator.lz");
INCBIN("graphics/sprite_prop/3d.4bpp");
INC4BPP("graphics/sprite_prop/3e_beetank");
INC4BPP("graphics/sprite_prop/3f_swordy");
INCLZ("graphics/sprite_prop/40_iceball");
INC4BPP("graphics/sprite_prop/41_puffy");
INC4BPP("graphics/sprite_prop/42_puffy_bubble");
INC4BPP("graphics/sprite_prop/43_crossbyne");
INC4BPP("graphics/sprite_prop/44_old_residential_fall_rock");
INC4BPP("graphics/sprite_prop/45_exskill_icon.notrim");
INCBIN("graphics/sprite_prop/45_exskill_icon_2.pal");
INCLZ("graphics/sprite_prop/46_beeserver");
INC4BPP("graphics/sprite_prop/47_mellnet");
INCBIN("graphics/sprite_prop/47_mellnet_2.pal");
INC4BPP("graphics/sprite_prop/48");
INCLZ("graphics/sprite_prop/49_anubis_rod");
INCLZ("graphics/sprite_prop/4a_anubis_sand");
INC4BPP("graphics/sprite_prop/4b_anubis_coffin");
INC4BPP("graphics/sprite_prop/4c_pantheon_zombie");
INCLZ("graphics/sprite_prop/4d_pantheon_aqua_mod");
INCLZ("graphics/sprite_prop/4e_pantheon_aqua_mod_projectile");
INCLZ("graphics/sprite_prop/4f_pantheon_aqua_mod_rock");
INCLZ("graphics/sprite_prop/50");
INC4BPP("graphics/sprite_prop/51_dark_elf");
INCBIN("graphics/sprite_prop/51_mother_elf.pal");
INCLZ("graphics/sprite_prop/52_elf_menu");
INCBIN("graphics/sprite_prop/52_2.pal");
INCLZ("graphics/sprite_prop/53_elf_menu_icon");
INCLZ("graphics/sprite_prop/54_locomo_if");
INCLZ("graphics/sprite_prop/55_locomo_if_platform");
INCLZ("graphics/sprite_prop/56_locomo_if_flame");
INCLZ("graphics/sprite_prop/57_locomo_if_frost");
INC4BPP("graphics/sprite_prop/58");
INCLZ("graphics/sprite_prop/59_glacierle_arm");
INC4BPP("graphics/sprite_prop/5a_icicle");
INCLZ("graphics/sprite_prop/5b");

// TODO: Dump remaining png images from sprite_prop.bin using tools/dumper/gfx.ts
// ./tools/dumper/bin.ts baserom.gba 0x086013E8 0x0861B13C graphics/sprite_prop/sprite_prop.bin
INCBIN("graphics/sprite_prop/sprite_prop.bin");

INCLZ("sprites/prop/z_logo/sheet");
INC4BPP("sprites/prop/missile_platform/sheet");
INCBIN("sprites/prop/mother_elf/sheet.4bpp");
INCBIN("sprites/prop/mother_elf/04.pal");
INCBIN("sprites/prop/mother_elf/05.pal");
INC4BPP("sprites/prop/volcano_coffin/sheet");
INC4BPP("sprites/prop/giant_elevator_pier/sheet");
INC4BPP("sprites/prop/giant_elevator_platform/sheet");
INC4BPP("sprites/prop/156/sheet");
INC4BPP("sprites/prop/smoke_157/sheet");
INCLZ("sprites/prop/minigame/zero/sheet");
INCLZ("sprites/prop/minigame/copy_x/sheet");
INCLZ("sprites/prop/minigame/phantom/sheet");
INCLZ("sprites/prop/minigame/harpuia/sheet");
INC4BPP("sprites/prop/resistance_base/painting/mmbn/sheet");
INC4BPP("sprites/prop/resistance_base/graffiti/zero1/sheet");
INC4BPP("sprites/prop/resistance_base/graffiti/ciel/sheet");
INC4BPP("sprites/prop/resistance_base/graffiti/zero2/sheet");
INC4BPP("sprites/prop/resistance_base/painting/ciel/sheet");
INCLZ("sprites/prop/life_energy/default/sheet");
INCLZ("sprites/prop/life_energy/x/sheet");
INCLZ("sprites/prop/life_energy/tank/sheet");
INCLZ("sprites/prop/ecrystal/default/sheet");
INCLZ("sprites/prop/ecrystal/ball/sheet");
INCLZ("sprites/prop/ecrystal/green/sheet");
INCLZ("sprites/prop/exlife/default/sheet");
INCLZ("sprites/prop/exlife/blue/sheet");
INCLZ("sprites/prop/exlife/green/sheet");
INCLZ("sprites/prop/result_disk/default/sheet");
INCLZ("sprites/prop/result_disk/blue/sheet");
INCLZ("sprites/prop/result_disk/red/sheet");
INCBIN("sprites/prop/179/sheet.lz");
INC4BPP("sprites/prop/childre_ship/sheet");
INC4BPP("sprites/prop/sea_level_button/sheet");
INC4BPP("sprites/prop/182/sheet");
INCBIN("sprites/prop/childre_ship_sonic_wave/sheet.4bpp");
INC4BPP("sprites/prop/x/sheet");
INCLZ("sprites/prop/omega_zx_floating_rock/sheet");
INCLZ("sprites/prop/186/sheet");
INC4BPP("sprites/prop/resistance/alouette/sheet");
INCBIN("sprites/prop/resistance/alouette/05-06.pal");
INCLZ("sprites/prop/resistance/kiss/sheet");
INCLZ("sprites/prop/resistance/faucon/sheet");
INCLZ("sprites/prop/resistance/hirondelle/sheet");
INCLZ("sprites/prop/resistance/autruche/sheet");
INCLZ("sprites/prop/resistance/rocinolle/sheet");
INCLZ("sprites/prop/resistance/doigt/sheet");
INCLZ("sprites/prop/resistance/cerveau/sheet");
INCLZ("sprites/prop/resistance/hibou/sheet");
INCLZ("sprites/prop/resistance/andrew/sheet");
INCLZ("sprites/prop/resistance/menart/sheet");
INCLZ("sprites/prop/resistance/perroquiet/sheet");
INCLZ("sprites/prop/resistance/pic/sheet");
INC4BPP("sprites/prop/smoke/sheet");
INCLZ("sprites/prop/resistance/operator/sheet");
INCLZ("sprites/prop/resistance_base/202/sheet");
INC4BPP("sprites/prop/iceblock/sheet");
INCLZ("sprites/prop/resistance_base/204/sheet");
INCLZ("sprites/prop/mission_mugshot/first4/sheet");
INCBIN("sprites/prop/mission_mugshot/first4/08-10.pal");
INCLZ("sprites/prop/mission_mugshot/middle4/sheet");
INCBIN("sprites/prop/mission_mugshot/middle4/08-10.pal");
INCLZ("sprites/prop/mission_mugshot/done/sheet.notrim");
INCLZ("sprites/prop/mission_mugshot/later4/sheet");
INCBIN("sprites/prop/mission_mugshot/later4/08-10.pal");
INCBIN("sprites/prop/number/sheet.4bpp");
INC4BPP("sprites/prop/lever_switch/sheet");
INC4BPP("sprites/prop/menu_border/sheet/0");
INC4BPP("sprites/prop/enemy/pantheon_fist/sheet/0");
INC4BPP("sprites/prop/enemy/cattatank/sheet/0");
INC4BPP("sprites/prop/enemy/spearook/sheet/0");
INC4BPP("sprites/prop/215/sheet");
INC4BPP("sprites/prop/resistance_base/cat/216/sheet/0");
INCBIN("sprites/prop/resistance_base/cat/216/sheet/5-6.pal");
INC4BPP("sprites/prop/resistance_base/cat/217/sheet/0");
INCBIN("sprites/prop/resistance_base/cat/217/sheet/5-6.pal");
INC4BPP("sprites/prop/resistance_base/seagull/sheet/0");
INC4BPP("sprites/prop/enemy/shellcrawler/sheet/0");
INC4BPP("sprites/prop/enemy/cannon_hopper/sheet/0");
INC4BPP("sprites/prop/enemy/mettaur/sheet/0");
INC4BPP("sprites/prop/structural_steel/sheet");
INC4BPP("sprites/prop/light_switch/sheet");
INC4BPP("sprites/prop/rubble/sheet/0");
INCLZ("sprites/prop/omega_white/sheet/0");
INC4BPP("sprites/prop/container/0");
INC4BPP("sprites/prop/container/1");
INC4BPP("sprites/prop/container/2");
INC4BPP("sprites/prop/subtank/sheet");
INC4BPP("sprites/prop/resistance_base/flying_fish/sheet/0");
INC4BPP("sprites/prop/resistance_base/plant/sheet/0");
INCLZ("sprites/prop/ciel_minigame/232/sheet");
INCLZ("sprites/prop/ciel_minigame/233/sheet");
INCBIN("sprites/prop/ciel_minigame/233/06-09.pal");
INCLZ("sprites/prop/ciel_minigame/234/sheet");
INCBIN("sprites/prop/235/sheet.4bpp");
INCBIN("sprites/prop/spark/sheet/0.lz");
INCLZ("sprites/prop/rock_237/sheet");
INC4BPP("sprites/prop/238/sheet");
INCLZ("sprites/prop/fish/angel_fish/sheet");
INCLZ("sprites/prop/fish/sea_bream/sheet");
INCLZ("sprites/prop/fish/crab/sheet");
INCLZ("sprites/prop/fish/school/sheet");
INCLZ("sprites/prop/243/sheet");
INCLZ("sprites/prop/copy_x_minigame_slot/sheet");
INCLZ("sprites/prop/boss_human/hellbat/sheet/0");
INCLZ("sprites/prop/boss_human/childre/sheet/0");
INCLZ("sprites/prop/boss_human/blazin/sheet/0");
INCLZ("sprites/prop/boss_human/deathtanz/sheet/0");
INCLZ("sprites/prop/boss_human/glacierle/sheet/0");
INCLZ("sprites/prop/boss_human/cubit/sheet/0");
INCLZ("sprites/prop/boss_human/tretista/sheet/0");
INCLZ("sprites/prop/boss_human/volteel/sheet/0");
INC4BPP("sprites/prop/253/sheet");
