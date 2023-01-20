#ifndef GUARD_RMZ3_STAGE_H
#define GUARD_RMZ3_STAGE_H

#include "gba/gba.h"
#include "global.h"

// 8x8タイルが2x2枚集まったもの(16x16px)
typedef u16 TileBlock[4];

// タイルブロックを識別するためのID
typedef u16 MapBlockID;

// TileBlock に対するプロパティ
struct __attribute__((packed, aligned(2))) BlockAttr {
  u8 unk_0;

  // bit2: 蟻地獄(どんどん沈んでいく)
  u8 special;
};

typedef union {
  struct BlockAttr;
  u16 val;
} BlockAttr_t;

// TileBlock(のID)を 15x10ブロック集めて画面全体のグラフィックを表すようにしたもの
typedef u16 Screen[150];

/*
  BlockMap(0x020029e4)に Screen をどう配置するかのデータ
*/
struct ScreenMap {
  u8 realWidth;
  u8 skip;    // そのステージでのSKIP値を格納する
  u8 width;   // ステージの横幅が画面何枚分か
  u8 height;  // ステージの縦幅が画面何枚分か
};

// ステージの静的な情報
struct Stage {
  u32 id;  // ステージID
  void *fn[4];
  s32 *terrain;
  struct ScreenMap *maps[3];
  u8 unk_24[84];
  void *unk_108;
  void *unk_112;
  void *unk_116;
  u8 unk_120[8];
};

struct TerrainShift {
  s16 x;      // ブロック単位
  s16 y;      // ブロック単位
  s16 block;  // 動かすブロックの数
  s16 row;
};

// e.g. 0833ccf0
struct TerrainPatch {
  u16 w;  // パッチの横のブロック数
  u16 h;  // パッチの縦のブロック数

  /*
    この後に
    MapBlockID patchs[w*h];
    が続いている
  */
};

// 命名未定
struct astruct_9 {
  struct Coord c;
  u16 bgofs[2];
  void *terrain;
  Screen *screens;
  struct ScreenMap *map;
};  // 24 bytes

// ステージ中のBG(BG1 or BG2 or BG3)
struct StageBg {
  void *fn_00;
  void *fn_04;
  void *exit;
  u16 unk_12;
  u8 initalized;
  u8 unk_15;
  u32 unk_16;
  struct astruct_9 unk_20;
  struct Coord unk_44;
  struct Coord screen;       // 現在の画面中央 >> 8
  struct Coord prevScreen;   // 1フレーム?前の.screen
  struct Coord scrollPower;  // .scroll の1単位ごとのスクロール度合い
  struct Coord scroll;
  struct Coord scrollCopy;
  u32 unk_bg;  // bit4-8がbgcntのn(BGnか)
  u32 bgcnt1;  // 参照: 0800d12a
  u32 bgcnt2;
  u32 frameCounter;  // 例: 壊れた宇宙船で背景の雲の流れと連動
  u8 unk_108[28];
};  // 136 bytes

struct Terrain {
  union BlockAttr_t *attrs;
  TileBlock *blocks;
  Screen *screens;
  struct ScreenMap *map;
};  // 16 bytes

// 0x20029e0
struct BlockMap {
  u16 w;
  u16 pad;
  u16 map[89102];
};  // 178208 bytes

// 0x02002200
struct CurStage {
  u8 Unk02002200[24];
  u8 unk_24[8];
  struct StageBg bgs[3];
  struct Terrain terrain;
  struct Coord screen;
  u16 id;              // ステージID
  u8 blockings[1538];  // ステージで通り抜け不能なオブジェクト
  u16 tilesets[2];
  u16 enableBg;  // DISPCNTの bit8..11 つまり BGn有効フラグ
  u16 savedBgCnt[3];
  struct BlockMap bm;
};  // 180224 bytes

#endif  // GUARD_RMZ3_STAGE_H
