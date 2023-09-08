#include "global.h"
#include "overworld.h"

/*

ステージの地形(terrain):
  8x8タイルが集まって16x16のタイルブロックを構成し、
  タイルブロックが15x10ブロック集まって 240x160、
  つまり画面の大きさと等しいグラフィックデータ(Screenと呼称) を配置していくことで地形データを構成している

タイルブロックとスクリーンのデータはステージIDをidとすると
    arr = (u8 *)&gStageTerrains[3*id];
    TileBlocks tiles[] =   arr + gStageTerrains[3*id + 0];
    metatile_attr_t  attrs[]  =   arr + gStageTerrains[3*id + 1];
    Screen     s[]      =   arr + gStageTerrains[3*id + 2];


スクリーンでどのようにマッピングして地形を構成していくかは
    ScreenMap構造体(例: 08343fc8) が持っている
*/

const struct TerrainHeader gStageTerrains[STAGE_COUNT] = {
    /* 00: Unknown         */ {0x000000DC, 0x000000FC, 0x00000104},  // 0x863c654, 0x863c674, 0x863c67c
    /* 01: Spacecraft      */ {0x00000224, 0x00002824, 0x000031A4},  // 0x863c7a8, 0x863eda8, 0x863f728
    /* 02: Volcano         */ {0x00008724, 0x0000C064, 0x0000CEB4},  // 0x8644cb4, 0x86485f4, 0x8649444
    /* 03: Ocean           */ {0x00017894, 0x000196B4, 0x00019E3C},  // 0x8653e30, 0x8655c50, 0x86563d8
    /* 04: Repair Factory  */ {0x00025F8C, 0x0002978C, 0x0002A58C},  // 0x8662534, 0x8665d34, 0x8666b34
    /* 05: Old Life Space  */ {0x00032B18, 0x00035918, 0x00036498},  // 0x866f0cc, 0x8671ecc, 0x8672a4c
    /* 06: Missile Factory */ {0x00044208, 0x00048048, 0x00048FD8},  // 0x86807c8, 0x8684608, 0x8685598
    /* 07: Twilight Desert */ {0x000548F4, 0x00056274, 0x000568D4},  // 0x8690ec0, 0x8692840, 0x8692ea0
    /* 08: Anatre Forest   */ {0x0005C7B4, 0x0005E094, 0x0005E6CC},  // 0x8698d8c, 0x869a66c, 0x869aca4
    /* 09: Frost Base Line */ {0x00066C58, 0x00068FF8, 0x000698E0},  // 0x86a323c, 0x86a55dc, 0x86a5ec4
    /* 10: Area X2         */ {0x0007231C, 0x0007413C, 0x000748C4},  // 0x86ae90c, 0x86b072c, 0x86b0eb4
    /* 11: Energy Factory  */ {0x0007A9FC, 0x0007DE9C, 0x0007EBC4},  // 0x86b6ff8, 0x86ba498, 0x86bb1c0
    /* 12: Snowy Plain     */ {0x00087858, 0x000894B8, 0x00089BD0},  // 0x86c3e60, 0x86c5ac0, 0x86c61d8
    /* 13: Sunken Library  */ {0x000962FC, 0x000976DC, 0x00097BD4},  // 0x86d2910, 0x86d3cf0, 0x86d41e8
    /* 14: Giant Elevator  */ {0x0009E9F0, 0x000A0190, 0x000A0778},  // 0x86db010, 0x86dc7b0, 0x86dcd98
    /* 15: Sub Arcadia     */ {0x000A6400, 0x000A8780, 0x000A9060},  // 0x86e2a2c, 0x86e4dac, 0x86e568c
    /* 16: Weil Labo       */ {0x000B2078, 0x000B4338, 0x000B4BE8},  // 0x86ee6b0, 0x86f0970, 0x86f1220
    /* 17: Resistance Base */ {0x000BD9A8, 0x000C09A8, 0x000C15A8},  // 0x86f9fec, 0x86fcfec, 0x86fdbec
};
const s32 StageTerrainsPadding = 0x000C7DE8;

INCASM("asm/terrain.inc");

// data/terrain/terrain.s
