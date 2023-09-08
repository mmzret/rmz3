#include "gfx.h"
#include "global.h"

// I'll replace this file by graphics/bg/header.json in the future

// 0x08547280
const struct Graphic gGraphic_Capcom = {
  src : 0x00000A78,  // 0x08547CF8
  size : 2400,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4),
};
const struct Palette gPalette_Capcom = {
  src : 0x000013CC,  // 0x08548658
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

// 0x08547294
const struct Graphic gGraphic_Inti = {
  src : 0x000013E4,  // 0x08548678
  size : 1260,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_Inti = {
  src : 0x000018C4,  // 0x08548B64
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

// 0x085472A8
const struct Graphic gGraphic_085472a8 = {
  src : 0x000018DC,  // 0x08548B84
  size : 9456,
  ofs : 256,
  chunkSize : 256,
  props : 66,
};
const struct Palette gPalette_085472a8 = {
  src : 0x00003DC0,  // 0x0854B074
  size : 128 * COLOR,
  lz77 : FALSE,
  dst : 6,
};

// 0x085472BC
const struct Graphic gGraphic_TitleZero = {
  src : 0x00003EB8,  // 0x0854B174
  size : 11468,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};

const struct Palette gPalette_TitleZero = {
  src : 0x00006B78,  // 0x0854DE40
  size : 32 * COLOR,
  lz77 : FALSE,
  dst : 14,
};

const struct Graphic gGraphic_TitleCiel = {
  // 0x085472D0
  src : 0x00006BB0,  // 0x0854DE80
  size : 8260,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4),
};

const struct Palette gPalette_TitleCiel = {
  src : 0x00008BE8,  // 0x0854FEC4
  size : 32 * COLOR,
  lz77 : FALSE,
  dst : 14,
};

const struct ColorGraphic gGraphics_085472E4[5] = {
    {
      // 0x085472E4
      g : {
        src : 0x00008C20,  // 0x0854FF04
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00008C14,  // 0x0854FF04
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 14,
      },
    },
    {
      // 0x085472F8
      g : {
        src : 0x00008C0C,  // 0x0854FF04
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00008C00,  // 0x0854FF04
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x0854730C
      g : {
        src : 0x00008BF8,  // 0x0854FF04
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00008BEC,  // 0x0854FF04
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547320
      g : {
        src : 0x00008BE4,  // 0x0854FF04
        size : 0,
        ofs : 256,
        chunkSize : 0,
        props : LZ77
      },
      pal : {
        src : 0x00008BD8,  // 0x0854FF04
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 6,
      },
    },
    {
      // 0x08547334
      g : {
        src : 0x00008BD0,  // 0x0854FF04
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00008BC4,  // 0x0854FF04
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
};

// 0x08547348
const struct Graphic gGraphic_HPGauge = {
  src : 0x00008BBC,  // 0x0854FF04
  size : 6080,
  ofs : 512,
  chunkSize : 256,
  props : BPP4
};
const struct Palette gPalette_HPGauge = {
  src : 0x0000A370,  // 0x085516C4
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 1,
};

// 0x0854735C
const struct Graphic gGraphic_MissionStart = {
  src : 0x0000A388,  // 0x085516E4
  size : 1856,
  ofs : 512,
  chunkSize : 256,
  props : BPP4
};
const struct Palette gPalette_MissionStart = {
  src : 0x0000AABC,  // 0x08551E24
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 1,
};

const struct ColorGraphic gGraphics_MissionAlerts[] = {
    {
      // MISSION FAILED
      // 0x08547370
      g : {
        src : 0x0000AAD4,  // 0x08551E44
        size : 804,
        ofs : 512,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0000ADEC,  // 0x08552168
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 1,
      },
    },
    {
      // 0x08547384
      g : {
        src : 0x0000AE04,  // 0x08552188
        size : 2368,
        ofs : 512,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x0000B738,  // 0x08552AC8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 1,
      },
    },
    {
      // 0x08547398
      g : {
        src : 0x0000B750,  // 0x08552AE8
        size : 832,
        ofs : 512,
        chunkSize : 256,
        props : BPP4
      },
      pal : {
        src : 0x0000BA84,  // 0x08552E28
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 1,
      },
    },
    {
      // 0x085473AC
      g : {
        src : 0x0000BA9C,  // 0x08552E48
        size : 1408,
        ofs : 512,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0000C010,  // 0x085533C8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 1,
      },
    },
};

// 0x085473C0
const struct Graphic gGraphic_GAMEOVER = {
  src : 0x0000C028,  // 0x085533E8
  size : 1564,
  ofs : 512,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_GAMEOVER = {
  src : 0x0000C638,  // 0x08553A04
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 1,
};

// 0x085473D4
const struct Graphic gGraphic_085473D4 = {
  src : 0x0000C650,  // 0x08553A24
  size : 1344,
  ofs : 896,
  chunkSize : 168,
  props : BPP4
};
const struct Palette gPalette_085473D4 = {
  src : 0x0000CB84,  // 0x08553F64
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 1,
};

// 0x085473E8
const struct Graphic gGraphic_TitleLogo = {
  src : 0x0000CB9C,  // 0x08553F84
  size : 1152,
  ofs : 512,
  chunkSize : 256,
  props : BPP4
};
const struct Palette gPalette_TitleLogo = {
  src : 0x0000D010,  // 0x08554404
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 1,
};

const struct ColorGraphic gGraphic_085473FC = {
  // 0x085473FC
  g : {
    src : 0x0000D028,  // 0x08554424
    size : 0,
    ofs : 0,
    chunkSize : 0,
    props : 0
  },
  pal : {
    src : 0x0000D01C,  // 0x08554424
    size : 0 * COLOR,
    lz77 : FALSE,
    dst : 0,
  },
};

const struct ColorGraphic gGraphic_MainMenu = {
  // 0x08547410
  g : {
    src : 0x0000D014,  // 0x08554424
    size : 7072,
    ofs : 0,
    chunkSize : 256,
    props : (LZ77 | BPP4)
  },
  pal : {
    src : 0x0000EBA8,  // 0x08555FC4
    size : 112 * COLOR,
    lz77 : FALSE,
    dst : 2,
  },
};

const struct ColorGraphic gGraphic_ExSkillMenu = {
  // 0x08547424
  g : {
    src : 0x0000EC80,  // 0x085560A4
    size : 2616,
    ofs : 512,
    chunkSize : 256,
    props : (LZ77 | BPP4)
  },
  pal : {
    src : 0x0000F6AC,  // 0x08556ADC
    size : 48 * COLOR,
    lz77 : FALSE,
    dst : 9,
  },
};

// 0x08547438
const struct Graphic gGraphic_MenuMisc = {
  src : 0x0000F704,  // 0x08556B3C
  size : 6740,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4),
};
const struct Palette gPalette_MenuMisc = {
  src : 0x0001114C,  // 0x08558590
  size : 112 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

const struct Graphic gGraphic_ElfMenu = {
  src : 0x00011224,  // 0x08558670
  size : 3140,
  ofs : 512,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_ElfMenu = {
  src : 0x00011E5C,  // 0x085592B4
  size : 80 * COLOR,
  lz77 : FALSE,
  dst : 9,
};

const struct ColorGraphic gGraphics_Zero3DModel[9] = {
    {
      // 0x08547460
      g : {
        src : 0x00011EF4,  // 0x08559354
        size : 720,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000121B8,  // 0x08559624
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x08547474
      g : {
        src : 0x000121D0,  // 0x08559644
        size : 688,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00012474,  // 0x085598F4
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x08547488
      g : {
        src : 0x0001248C,  // 0x08559914
        size : 660,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00012714,  // 0x08559BA8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x0854749C
      g : {
        src : 0x0001272C,  // 0x08559BC8
        size : 588,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001296C,  // 0x08559E14
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x085474B0
      g : {
        src : 0x00012984,  // 0x08559E34
        size : 536,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00012B90,  // 0x0855A04C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x085474C4
      g : {
        src : 0x00012BA8,  // 0x0855A06C
        size : 592,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00012DEC,  // 0x0855A2BC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x085474D8
      g : {
        src : 0x00012E04,  // 0x0855A2DC
        size : 608,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00013058,  // 0x0855A53C
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x085474EC
      g : {
        src : 0x00013070,  // 0x0855A55C
        size : 624,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000132D4,  // 0x0855A7CC
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
    {
      // 0x08547500
      g : {
        src : 0x000132EC,  // 0x0855A7EC
        size : 636,
        ofs : 384,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001355C,  // 0x0855AA68
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 7,
      },
    },
};

// 0x08547514
const struct ColorGraphic gGraphics_ElfCategory[3] = {
    {
      // 0x08547514
      g : {
        src : 0x00013574,  // 0x0855AA88
        size : 576,
        ofs : 576,
        chunkSize : 288,
        props : (BPP4 | CHUNKED)
      },
      pal : {
        src : 0x000137A8,  // 0x0855ACC8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 13,
      },
    },
    {
      // 0x08547528
      g : {
        src : 0x000137C0,  // 0x0855ACE8
        size : 576,
        ofs : 576,
        chunkSize : 288,
        props : (BPP4 | CHUNKED)
      },
      pal : {
        src : 0x000139F4,  // 0x0855AF28
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 13,
      },
    },
    {
      // 0x0854753C
      g : {
        src : 0x00013A0C,  // 0x0855AF48
        size : 576,
        ofs : 576,
        chunkSize : 288,
        props : (BPP4 | CHUNKED)
      },
      pal : {
        src : 0x00013C40,  // 0x0855B188
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 13,
      },
    },
};

const struct ColorGraphic gGraphics_ModSecretDisk[2] = {
    {
      // 0x08547550
      g : {
        src : 0x00013C58,  // 0x0855B1A8
        size : 256,
        ofs : 235,
        chunkSize : 128,
        props : (BPP4 | CHUNKED)
      },
      pal : {
        src : 0x00013D4C,  // 0x0855B2A8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
    {
      // 0x08547564
      g : {
        src : 0x00013D64,  // 0x0855B2C8
        size : 256,
        ofs : 235,
        chunkSize : 128,
        props : (BPP4 | CHUNKED)
      },
      pal : {
        src : 0x00013E58,  // 0x0855B3C8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 8,
      },
    },
};

const struct ColorGraphic gGraphic_08547578 = {
  // 0x08547578
  g : {
    src : 0x00013E70,  // 0x0855B3E8
    size : 0,
    ofs : 0,
    chunkSize : 0,
    props : 0
  },
  pal : {
    src : 0x00013E64,  // 0x0855B3E8
    size : 0 * COLOR,
    lz77 : FALSE,
    dst : 0,
  },
};

// 0x0854758C
const struct Graphic gGraphic_0854758C = {
  src : 0x00013E5C,  // 0x0855B3E8
  size : 576,
  ofs : 576,
  chunkSize : 288,
  props : (BPP4 | CHUNKED)
};
const struct Palette gPalette_0854758C = {
  src : 0x00014090,  // 0x0855B628
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 13,
};

// 0x085475a0
const struct Graphic gGraphic_NurseElfTab = {
  src : 0x000140A8,  // 0x0855B648
  size : 512,
  ofs : 672,
  chunkSize : 256,
  props : (BPP4 | CHUNKED)
};
const struct Palette gPalette_NurseElfTab = {
  src : 0x0001429C,  // 0x0855B848
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 11,
};

// 0x085475B4
const struct Graphic gGraphic_AnimalElfTab = {
  src : 0x000142B4,  // 0x0855B868
  size : 512,
  ofs : 672,
  chunkSize : 256,
  props : (BPP4 | CHUNKED)
};
const struct Palette gPalette_AnimalElfTab = {
  src : 0x000144A8,  // 0x0855BA68
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 11,
};

// 0x085475C8
const struct Graphic gGraphic_HackerElfTab = {
  src : 0x000144C0,  // 0x0855BA88
  size : 512,
  ofs : 672,
  chunkSize : 256,
  props : (BPP4 | CHUNKED)
};
const struct Palette gPalette_HackerElfTab = {
  src : 0x000146B4,  // 0x0855BC88
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 11,
};

const struct ColorGraphic gGraphics_CodeName[] = {
    {
      // 0x085475DC
      g : {
        src : 0x000146CC,  // 0x0855BCA8
        size : 2540,
        ofs : 768,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000150AC,  // 0x0855C694
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 15,
      },
    },
    {
      // 0x085475F0
      g : {
        src : 0x000150C4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000150B8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547604
      g : {
        src : 0x000150B0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000150A4,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547618
      g : {
        src : 0x0001509C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015090,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854762C
      g : {
        src : 0x00015088,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x0001507C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547640
      g : {
        src : 0x00015074,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015068,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547654
      g : {
        src : 0x00015060,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015054,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547668
      g : {
        src : 0x0001504C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015040,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854767C
      g : {
        src : 0x00015038,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x0001502C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547690
      g : {
        src : 0x00015024,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015018,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085476A4
      g : {
        src : 0x00015010,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015004,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085476B8
      g : {
        src : 0x00014FFC,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014FF0,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085476CC
      g : {
        src : 0x00014FE8,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014FDC,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085476E0
      g : {
        src : 0x00014FD4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014FC8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085476F4
      g : {
        src : 0x00014FC0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014FB4,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547708
      g : {
        src : 0x00014FAC,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014FA0,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854771C
      g : {
        src : 0x00014F98,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F8C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547730
      g : {
        src : 0x00014F84,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F78,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547744
      g : {
        src : 0x00014F70,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F64,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547758
      g : {
        src : 0x00014F5C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F50,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854776C
      g : {
        src : 0x00014F48,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F3C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547780
      g : {
        src : 0x00014F34,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F28,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547794
      g : {
        src : 0x00014F20,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F14,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085477A8
      g : {
        src : 0x00014F0C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014F00,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085477BC
      g : {
        src : 0x00014EF8,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014EEC,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085477D0
      g : {
        src : 0x00014EE4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014ED8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085477E4
      g : {
        src : 0x00014ED0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014EC4,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085477F8
      g : {
        src : 0x00014EBC,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014EB0,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854780C
      g : {
        src : 0x00014EA8,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E9C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547820
      g : {
        src : 0x00014E94,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E88,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547834
      g : {
        src : 0x00014E80,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E74,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547848
      g : {
        src : 0x00014E6C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E60,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854785C
      g : {
        src : 0x00014E58,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E4C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547870
      g : {
        src : 0x00014E44,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E38,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547884
      g : {
        src : 0x00014E30,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E24,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547898
      g : {
        src : 0x00014E1C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014E10,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085478AC
      g : {
        src : 0x00014E08,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014DFC,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085478C0
      g : {
        src : 0x00014DF4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014DE8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085478D4
      g : {
        src : 0x00014DE0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014DD4,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085478E8
      g : {
        src : 0x00014DCC,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014DC0,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085478FC
      g : {
        src : 0x00014DB8,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014DAC,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547910
      g : {
        src : 0x00014DA4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D98,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547924
      g : {
        src : 0x00014D90,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D84,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547938
      g : {
        src : 0x00014D7C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D70,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854794C
      g : {
        src : 0x00014D68,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D5C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547960
      g : {
        src : 0x00014D54,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D48,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547974
      g : {
        src : 0x00014D40,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D34,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547988
      g : {
        src : 0x00014D2C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D20,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x0854799C
      g : {
        src : 0x00014D18,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014D0C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085479B0
      g : {
        src : 0x00014D04,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014CF8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085479C4
      g : {
        src : 0x00014CF0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014CE4,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085479D8
      g : {
        src : 0x00014CDC,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014CD0,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x085479EC
      g : {
        src : 0x00014CC8,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014CBC,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A00
      g : {
        src : 0x00014CB4,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014CA8,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A14
      g : {
        src : 0x00014CA0,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014C94,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A28
      g : {
        src : 0x00014C8C,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014C80,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A3C
      g : {
        src : 0x00014C78,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014C6C,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A50
      g : {
        src : 0x00014C64,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014C58,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547A64
      g : {
        src : 0x00014C50,  // 0x0855C6B4
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00014C44,  // 0x0855C6B4
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
};

// ゲームオーバー画面のカタカナでかかれたゲームオーバー
const struct Graphic gGraphic_GameOver = {// 0x08547A78
  src : 0x00014C3C,  // 0x0855C6B4
  size : 1404,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_GameOver = {
  src : 0x000151AC,  // 0x0855CC30
  size : 32 * COLOR,
  lz77 : FALSE,
  dst : 9,
};

// 最初のあらすじ説明のエルピスとゼロのいるカットシーン
const struct ColorGraphic gGraphics_Prologue[10] = {
    {
      // 0x08547A8C
      g : {
        src : 0x000151E4,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000151D8,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 9,
      },
    },
    {
      // 0x08547AA0
      g : {
        src : 0x000151D0,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000151C4,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547AB4
      g : {
        src : 0x000151BC,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x000151B0,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547AC8
      g : {
        src : 0x000151A8,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x0001519C,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547ADC
      g : {
        src : 0x00015194,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015188,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547AF0
      g : {
        src : 0x00015180,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015174,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547B04
      g : {
        src : 0x0001516C,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015160,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547B18
      g : {
        src : 0x00015158,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x0001514C,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547B2C
      g : {
        src : 0x00015144,  // 0x0855CC70
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 0
      },
      pal : {
        src : 0x00015138,  // 0x0855CC70
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 0,
      },
    },
    {
      // 0x08547B40
      g : {
        src : 0x00015130,  // 0x0855CC70
        size : 16216,
        ofs : 0,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0001907C,  // 0x08560BC8
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
};

const struct ColorGraphic gGraphics_08547b54[8] = {
    {
      // 0x08547B54
      g : {
        src : 0x00019094,  // 0x08560BE8
        size : 24700,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x0001F104,  // 0x08566C64
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547B68
      g : {
        src : 0x0001F1DC,  // 0x08566D44
        size : 7596,
        ofs : 0,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x00020F7C,  // 0x08568AF0
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547B7C
      g : {
        src : 0x00020F94,  // 0x08568B10
        size : 18844,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x00025924,  // 0x0856D4AC
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547B90
      g : {
        src : 0x000259FC,  // 0x0856D58C
        size : 27280,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x0002C480,  // 0x0857401C
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547BA4
      g : {
        src : 0x0002C558,  // 0x085740FC
        size : 16324,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x00030510,  // 0x085780C0
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547BB8
      g : {
        src : 0x000305E8,  // 0x085781A0
        size : 16140,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x000344E8,  // 0x0857C0AC
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547BCC
      g : {
        src : 0x000345C0,  // 0x0857C18C
        size : 17416,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x000389BC,  // 0x08580594
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547BE0
      g : {
        src : 0x00038A94,  // 0x08580674
        size : 10884,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x0003B50C,  // 0x085830F8
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
};

const struct ColorGraphic gGraphics_008547bf4[4] = {
    {
      // 0x08547BF4
      g : {
        src : 0x0003B5E4,  // 0x085831D8
        size : 31544,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x00043110,  // 0x0858AD10
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547C08
      g : {
        src : 0x000431E8,  // 0x0858ADF0
        size : 18080,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x0004787C,  // 0x0858F490
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547C1C
      g : {
        src : 0x00047954,  // 0x0858F570
        size : 22744,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x0004D220,  // 0x08594E48
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547C30
      g : {
        src : 0x0004D2F8,  // 0x08594F28
        size : 9276,
        ofs : 0,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x0004F728,  // 0x08597364
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
};

const struct Graphic gGraphic_08547C44 = {
  src : 0x0004F740,  // 0x08597384
  size : 15380,
  ofs : 0,
  chunkSize : 256,
  props : 66
};
const struct Palette gPalette_08547C44 = {
  src : 0x00053348,  // 0x0859AF98
  size : 112 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

const struct ColorGraphic gGraphics_008547c58[2] = {
    {
      // 0x08547C58
      g : {
        src : 0x00053420,  // 0x0859B078
        size : 9664,
        ofs : 64,
        chunkSize : 256,
        props : (LZ77 | BPP4)
      },
      pal : {
        src : 0x000559D4,  // 0x0859D638
        size : 16 * COLOR,
        lz77 : FALSE,
        dst : 10,
      },
    },
    {
      // 0x08547C6C
      g : {
        src : 0x000559EC,  // 0x0859D658
        size : 15720,
        ofs : 0,
        chunkSize : 256,
        props : 66
      },
      pal : {
        src : 0x00059748,  // 0x085A13C0
        size : 112 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
};

const struct Graphic gGraphic_CielMinigame = {
  src : 0x00059820,  // 0x085A14A0
  size : 2500,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_CielMinigame = {
  src : 0x0005A1D8,  // 0x085A1E64
  size : 48 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

// 0x08547c94
const struct Graphic gGraphic_OpeningAnim0 = {
  src : 0x0005A230,  // 0x085A1EC4
  size : 0,
  ofs : 0,
  chunkSize : 0,
  props : 2
};
const struct Palette gPalette_OpeningAnim0 = {
  src : 0x0005A224,  // 0x085A1EC4
  size : 0 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

const struct Graphic gGraphic_OpeningAnim1 = {
  src : 0x0005A21C,  // 0x085A1EC4
  size : 12252,
  ofs : 0,
  chunkSize : 256,
  props : (LZ77 | BPP4)
};
const struct Palette gPalette_OpeningAnim1 = {
  src : 0x0005D1EC,  // 0x085A4EA0
  size : 16 * COLOR,
  lz77 : FALSE,
  dst : 2,
};

const struct Graphic gGraphic_OpeningAnim2 = {
  src : 0x0005D204,  // 0x085A4EC0
  size : 12184,
  ofs : 512,
  chunkSize : 256,
  props : (LZ77 | BPP4 | NO_PAL)
};
const struct Palette gPalette_OpeningAnim2 = {
  src : 0x00060190,  // 0x085A7E58
  size : 0 * COLOR,
  lz77 : FALSE,
  dst : 9,
};

const struct ColorGraphic gGraphics_08547294[] = {
    {
      // 0x08547CD0
      g : {
        src : 0x00060188,  // 0x085A7E58
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 2
      },
      pal : {
        src : 0x0006017C,  // 0x085A7E58
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
    {
      // 0x08547CE4
      g : {
        src : 0x00060174,  // 0x085A7E58
        size : 0,
        ofs : 0,
        chunkSize : 0,
        props : 2
      },
      pal : {
        src : 0x00060168,  // 0x085A7E58
        size : 0 * COLOR,
        lz77 : FALSE,
        dst : 2,
      },
    },
};

INCLZ("graphics/bg/capcom");
INCLZ("graphics/bg/inti");

INCBIN("graphics/bg/cutscene_085472a8.bin");

INCBIN("graphics/bg/title_zero.lz");
INCBIN("graphics/bg/title_zero.pal");
INCBIN("graphics/bg/title_ciel.lz");
INCBIN("graphics/bg/title_ciel.pal");
INC4BPP("graphics/bg/hp_gauge");
INC4BPP("graphics/bg/mission_start");  // 0854735c
INCLZ("graphics/bg/mission_failed");
INC4BPP("graphics/bg/gfx_08547384");
INC4BPP("graphics/bg/gfx_08547398");
INCLZ("graphics/bg/stage_clear");
INCLZ("graphics/bg/game_over");
INC4BPP("graphics/bg/gfx_085473d4");
INC4BPP("graphics/bg/title_logo");

// 20~23
INCBIN("graphics/bg/menu_main.lz");
INCBIN("graphics/bg/menu_main.pal");
INCBIN("graphics/bg/menu_exskill.lz");
INCBIN("graphics/bg/menu_exskill.pal");
INCBIN("graphics/bg/menu_others.lz");
INCBIN("graphics/bg/menu_others.pal");
INCBIN("graphics/bg/menu_elf.lz");
INCBIN("graphics/bg/menu_elf.pal");

// 24~32
INCLZ("graphics/bg/zero_3d/0");
INCLZ("graphics/bg/zero_3d/1");
INCLZ("graphics/bg/zero_3d/2");
INCLZ("graphics/bg/zero_3d/3");
INCLZ("graphics/bg/zero_3d/4");
INCLZ("graphics/bg/zero_3d/5");
INCLZ("graphics/bg/zero_3d/6");
INCLZ("graphics/bg/zero_3d/7");
INCLZ("graphics/bg/zero_3d/8");

INC4BPP("graphics/bg/str_nurse_elf");
INC4BPP("graphics/bg/str_animal_elf");
INC4BPP("graphics/bg/str_hacker_elf");

INC4BPP("graphics/bg/secret_dick_blue");
INC4BPP("graphics/bg/secret_dick_red");

INC4BPP("graphics/bg/gfx_0854758c");

INC4BPP("graphics/bg/elftab/nurse");
INC4BPP("graphics/bg/elftab/animal");
INC4BPP("graphics/bg/elftab/hacker");

INCLZ("graphics/bg/codename");
INCBIN("graphics/bg/game_over_screen.lz");
INCBIN("graphics/bg/game_over_screen.pal");

// 103~
INCLZ("graphics/bg/cutscene_prologue");
INCBIN("graphics/bg/cutscene_omegaship.lz");
INCBIN("graphics/bg/cutscene_omegaship.pal");
INCLZ("graphics/bg/cutscene_darkelf");
INCBIN("graphics/bg/cutscene_comeon_zero.lz");
INCBIN("graphics/bg/cutscene_comeon_zero.pal");
INCBIN("graphics/bg/cutscene_omega_white.lz");
INCBIN("graphics/bg/cutscene_omega_white.pal");

// ./tools/dumper/bin.ts baserom.gba 0x085740fc 0x85a7ec4 ./graphics/bg/bg.bin
INCBIN("graphics/bg/bg.bin");
