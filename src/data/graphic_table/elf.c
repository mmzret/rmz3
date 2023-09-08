#include "gfx.h"
#include "global.h"

// I'll replace this file by graphics/elf/header.json in the future

#define INCELFGFX(base, name)         \
  __asm__(                            \
      ".section .rodata\n"            \
      ".incbin \"" base name "/" name \
      ".4bpp\"\n"                     \
      ".incbin \"" base name "/" name \
      ".gbapal\"\n"                   \
      ".incbin \"" base name "/grayscale.pal\"\n");

#define INCLZELFGFX(base, name)       \
  __asm__(                            \
      ".section .rodata\n"            \
      ".incbin \"" base name "/" name \
      ".lz\"\n"                       \
      ".incbin \"" base name "/" name \
      ".lz.gbapal\"\n"                \
      ".incbin \"" base name "/grayscale.pal\"\n");

// 0x08635f24
const struct ColorGraphic gElfMugshotGraphics[48] = {
    [0] = {
      // 0x08635F24
      g : {
        src : 0x000003C0,  // 0x086362E4
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000005B4,  // 0x086364E4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [1] = {
      // 0x08635F38
      g : {
        src : 0x000005EC,  // 0x08636524
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000007E0,  // 0x08636724
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [2] = {
      // 0x08635F4C
      g : {
        src : 0x00000818,  // 0x08636764
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00000A0C,  // 0x08636964
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [3] = {
      // 0x08635F60
      g : {
        src : 0x00000A44,  // 0x086369A4
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00000C38,  // 0x08636BA4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [4] = {
      // 0x08635F74
      g : {
        src : 0x00000C70,  // 0x08636BE4
        size : 496,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00000E54,  // 0x08636DD4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [5] = {
      // 0x08635F88
      g : {
        src : 0x00000E8C,  // 0x08636E14
        size : 496,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00001070,  // 0x08637004
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [6] = {
      // 0x08635F9C
      g : {
        src : 0x000010A8,  // 0x08637044
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x0000129C,  // 0x08637244
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [7] = {
      // 0x08635FB0
      g : {
        src : 0x000012D4,  // 0x08637284
        size : 496,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000014B8,  // 0x08637474
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [8] = {
      // 0x08635FC4
      g : {
        src : 0x000014F0,  // 0x086374B4
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000016E4,  // 0x086376B4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [9] = {
      // 0x08635FD8
      g : {
        src : 0x0000171C,  // 0x086376F4
        size : 0,
        ofs : 863,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00001710,  // 0x086376F4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [10] = {
      // 0x08635FEC
      g : {
        src : 0x00001708,  // 0x086376F4
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000018FC,  // 0x086378F4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [11] = {
      // 0x08636000
      g : {
        src : 0x00001934,  // 0x08637934
        size : 0,
        ofs : 863,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00001928,  // 0x08637934
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [12] = {
      // 0x08636014
      g : {
        src : 0x00001920,  // 0x08637934
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00001B14,  // 0x08637B34
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [13] = {
      // 0x08636028
      g : {
        src : 0x00001B4C,  // 0x08637B74
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00001D40,  // 0x08637D74
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [14] = {
      // 0x0863603C
      g : {
        src : 0x00001D78,  // 0x08637DB4
        size : 508,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00001F68,  // 0x08637FB0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [15] = {
      // 0x08636050
      g : {
        src : 0x00001FA0,  // 0x08637FF0
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00002194,  // 0x086381F0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [16] = {
      // 0x08636064
      g : {
        src : 0x000021CC,  // 0x08638230
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000023C0,  // 0x08638430
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [17] = {
      // 0x08636078
      g : {
        src : 0x000023F8,  // 0x08638470
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000025EC,  // 0x08638670
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [18] = {
      // 0x0863608C
      g : {
        src : 0x00002624,  // 0x086386B0
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00002818,  // 0x086388B0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [19] = {
      // 0x086360A0
      g : {
        src : 0x00002850,  // 0x086388F0
        size : 452,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00002A08,  // 0x08638AB4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [20] = {
      // 0x086360B4
      g : {
        src : 0x00002A40,  // 0x08638AF4
        size : 488,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00002C1C,  // 0x08638CDC
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [21] = {
      // 0x086360C8
      g : {
        src : 0x00002C54,  // 0x08638D1C
        size : 452,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00002E0C,  // 0x08638EE0
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [22] = {
      // 0x086360DC
      g : {
        src : 0x00002E44,  // 0x08638F20
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00003038,  // 0x08639120
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [23] = {
      // 0x086360F0
      g : {
        src : 0x00003070,  // 0x08639160
        size : 396,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000031F0,  // 0x086392EC
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [24] = {
      // 0x08636104
      g : {
        src : 0x00003228,  // 0x0863932C
        size : 464,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000033EC,  // 0x086394FC
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [25] = {
      // 0x08636118
      g : {
        src : 0x00003424,  // 0x0863953C
        size : 476,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000035F4,  // 0x08639718
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [26] = {
      // 0x0863612C
      g : {
        src : 0x0000362C,  // 0x08639758
        size : 500,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00003814,  // 0x0863994C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [27] = {
      // 0x08636140
      g : {
        src : 0x0000384C,  // 0x0863998C
        size : 464,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00003A10,  // 0x08639B5C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [28] = {
      // 0x08636154
      g : {
        src : 0x00003A48,  // 0x08639B9C
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00003C3C,  // 0x08639D9C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [29] = {
      // 0x08636168
      g : {
        src : 0x00003C74,  // 0x08639DDC
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00003E68,  // 0x08639FDC
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [30] = {
      // 0x0863617C
      g : {
        src : 0x00003EA0,  // 0x0863A01C
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00004094,  // 0x0863A21C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [31] = {
      // 0x08636190
      g : {
        src : 0x000040CC,  // 0x0863A25C
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000042C0,  // 0x0863A45C
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [32] = {
      // 0x086361A4
      g : {
        src : 0x000042F8,  // 0x0863A49C
        size : 504,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000044E4,  // 0x0863A694
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [33] = {
      // 0x086361B8
      g : {
        src : 0x0000451C,  // 0x0863A6D4
        size : 448,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000046D0,  // 0x0863A894
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [34] = {
      // 0x086361CC
      g : {
        src : 0x00004708,  // 0x0863A8D4
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000048FC,  // 0x0863AAD4
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [35] = {
      // 0x086361E0
      g : {
        src : 0x00004934,  // 0x0863AB14
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00004B28,  // 0x0863AD14
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [36] = {
      // 0x086361F4
      g : {
        src : 0x00004B60,  // 0x0863AD54
        size : 484,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00004D38,  // 0x0863AF38
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [37] = {
      // 0x08636208
      g : {
        src : 0x00004D70,  // 0x0863AF78
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00004F64,  // 0x0863B178
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [38] = {
      // 0x0863621C
      g : {
        src : 0x00004F9C,  // 0x0863B1B8
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00005190,  // 0x0863B3B8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [39] = {
      // 0x08636230
      g : {
        src : 0x000051C8,  // 0x0863B3F8
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000053BC,  // 0x0863B5F8
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [40] = {
      // 0x08636244
      g : {
        src : 0x000053F4,  // 0x0863B638
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x000055E8,  // 0x0863B838
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [41] = {
      // 0x08636258
      g : {
        src : 0x00005620,  // 0x0863B878
        size : 512,
        ofs : 863,
        chunkSize : 32,
        props : BPP4
      },
      pal : {
        src : 0x00005814,  // 0x0863BA78
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [42] = {
      // 0x0863626C
      g : {
        src : 0x0000584C,  // 0x0863BAB8
        size : 460,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00005A0C,  // 0x0863BC84
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [43] = {
      // 0x08636280
      g : {
        src : 0x00005A44,  // 0x0863BCC4
        size : 412,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00005BD4,  // 0x0863BE60
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [44] = {
      // 0x08636294
      g : {
        src : 0x00005BEC,  // 0x0863BE80
        size : 368,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00005D50,  // 0x0863BFF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [45] = {
      // 0x086362A8
      g : {
        src : 0x00005D68,  // 0x0863C010
        size : 236,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00005E48,  // 0x0863C0FC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [46] = {
      // 0x086362BC
      g : {
        src : 0x00005E60,  // 0x0863C11C
        size : 492,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00006040,  // 0x0863C308
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
    [47] = {
      // 0x086362D0
      g : {
        src : 0x00006078,  // 0x0863C348
        size : 496,
        ofs : 863,
        chunkSize : 32,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0000625C,  // 0x0863C538
        size : 32 * COLOR,
        lz77 : FALSE,
        dst : 11,
      },
    },
};

INCELFGFX("graphics/elf/mugshot/martina/", "0x08635f24");
INCELFGFX("graphics/elf/mugshot/martina/", "0x08635f38");
INCELFGFX("graphics/elf/mugshot/martina/", "0x08635f4c");

INCELFGFX("graphics/elf/mugshot/nurse_a/", "0x08635f60");
INCLZELFGFX("graphics/elf/mugshot/nurse_a/", "0x08635f74");
INCLZELFGFX("graphics/elf/mugshot/nurse_b/", "0x08635f88");
INCELFGFX("graphics/elf/mugshot/nurse_b/", "0x08635f9c");
INCLZELFGFX("graphics/elf/mugshot/nurse_b/", "0x08635fb0");
INCELFGFX("graphics/elf/mugshot/nurse_b/", "0x08635f9c");
INCELFGFX("graphics/elf/mugshot/", "nurse_c");
INCELFGFX("graphics/elf/mugshot/", "nurse_e");

INCELFGFX("graphics/elf/mugshot/slime/", "0x08636028");
INCLZELFGFX("graphics/elf/mugshot/slime/", "0x0863603c");
INCELFGFX("graphics/elf/mugshot/slime/", "0x08636050");
INCELFGFX("graphics/elf/mugshot/cheetah/", "0x08636064");
INCELFGFX("graphics/elf/mugshot/cheetah/", "0x08636078");
INCELFGFX("graphics/elf/mugshot/monkey/", "0x0863608c");
INCLZELFGFX("graphics/elf/mugshot/monkey/", "0x086360a0");
INCLZELFGFX("graphics/elf/mugshot/frog/", "0x086360b4");
INCLZELFGFX("graphics/elf/mugshot/frog/", "0x086360c8");
INCELFGFX("graphics/elf/mugshot/cow/", "0x086360dc");
INCLZELFGFX("graphics/elf/mugshot/cow/", "0x086360f0");
INCLZELFGFX("graphics/elf/mugshot/", "bird");
INCLZELFGFX("graphics/elf/mugshot/", "sea_otter");
INCLZELFGFX("graphics/elf/mugshot/", "bee");
INCLZELFGFX("graphics/elf/mugshot/", "archix");

INCELFGFX("graphics/elf/mugshot/byse/", "0x08636154");
INCELFGFX("graphics/elf/mugshot/byse/", "0x08636168");
INCELFGFX("graphics/elf/mugshot/byse/", "0x0863617c");
INCELFGFX("graphics/elf/mugshot/", "dylphina");
INCLZELFGFX("graphics/elf/mugshot/ninja/", "0x086361a4");
INCLZELFGFX("graphics/elf/mugshot/ninja/", "0x086361b8");
INCELFGFX("graphics/elf/mugshot/", "miko");
INCELFGFX("graphics/elf/mugshot/", "clock");
INCLZELFGFX("graphics/elf/mugshot/", "metall");
INCELFGFX("graphics/elf/mugshot/armor/", "0x08636208");
INCELFGFX("graphics/elf/mugshot/armor/", "0x0863621c");
INCELFGFX("graphics/elf/mugshot/", "time");
INCELFGFX("graphics/elf/mugshot/giant/", "0x08636244");
INCELFGFX("graphics/elf/mugshot/giant/", "0x08636258");
INCLZELFGFX("graphics/elf/mugshot/", "whistle");

INCLZ("graphics/elf/type/nurse");
INCLZ("graphics/elf/type/animal");
INCLZ("graphics/elf/type/hacker");

INCLZELFGFX("graphics/elf/mugshot/nurse_d/", "0x086362bc");
INCLZELFGFX("graphics/elf/mugshot/nurse_d/", "0x086362d0");
