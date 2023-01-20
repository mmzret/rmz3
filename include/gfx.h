#ifndef GUARD_RMZ3_GFX_H
#define GUARD_RMZ3_GFX_H

#include "gba/gba.h"

// 0x080036cc の関数で src -> dst に転送が行われる
// Graphic構造体、Bgmapなどさまざまなグラフィックデータを転送する
struct GraphicTask {
  // 下位2bitが
  //   0: Graphic構造体
  //   1: BGマップ
  //   2: ??? (0x08003a08)
  //   3: ???
  u8 type;

  u8 unk[3];
  void* dst;
  void* src;
};

// 0x02001fc4
// 0x080036ccで 毎フレームごとに、 DMA3 で VRAM に転送される
struct Bg0Mask {
  // 転送されるバイトサイズ
  u32 size;

  /*
    ここにアドレスがセットされている場合、
    080036cc で .mask のデータが アドレス(0x6000000 + .map)に転送される
    (このアドレス自体は使わない？)
  */
  void* bg0;

  // 転送先のBgMap offset
  u32 map;

  // マスクデータ(u16 x 2)
  u32 mask;
};

// 0x02001f00
struct GraphicTasks {
  u8 len;  // .tasks のうち、有効なタスク数
  struct GraphicTask tasks[16];
  struct Bg0Mask bg0mask;
};

// グラフィックデータ(タイルデータ)の情報を持った構造体(ヘッダみたいなもの)
struct Graphic {
  s32 src;        // tile data starts from `(u8 *)&src + src`
  u32 size : 22;  // unit is byte.
  u32 ofs : 10;
  u16 chunkSize;  // If graphic is not chunked, this value is unused.

  // uint16
  // bit0:     is chunked? (chunk mode)
  // bit1:     is LZ77 compressed?
  // bit5:     is 4BPP?
  // bit6:     is 8BPP?
  // bit12:    is RLU compressed?
  // props & 0x7F8 is ofsUnit (4BPP: 32, 8BPP: 64)
  u16 props;
};

// パレットの情報を持った構造体(ヘッダみたいなもの)
struct Palette {
  u32 src;    // palette data starts from `(void *)&src + src`
  u16 size;   // unit is byte
  bool8 lz77; // lz77 compressed?
  u8 dst;
};

/*
  0x02001f00
  グラフィックデータを転送するタスクデータが入っている
  毎フレーム、ここに入っているタスクが 関数 0x080036cc で実行されグラフィックデータが転送される
*/
extern struct GraphicTasks GraphicTasks;

#endif  // GUARD_RMZ3_GFX_H
