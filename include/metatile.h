#ifndef GUARD_RMZ3_OW_METATILE_H
#define GUARD_RMZ3_OW_METATILE_H

#include "types.h"

// 8x8タイルが2x2枚集まった論理タイル(16x16px)
typedef u16 Metatile[4];

struct MetatileShift {
  s16 x;      // メタタイル単位
  s16 y;      // メタタイル単位
  s16 block;  // 動かすメタタイルの数
  s16 row;
};

// --------------------------------------------

// e.g. 0833ccf0
struct MetatilePatch {
  u16 w;  // パッチの横のメタタイル数
  u16 h;  // パッチの縦のメタタイル数

  /*
    この後に
    metatile_id_t patchs[w*h];
    が続いている
  */
};

struct MetatilePatch2x1 {
  struct MetatilePatch size;
  metatile_id_t data[2 * 1];
};

struct MetatilePatch2x2 {
  struct MetatilePatch size;
  metatile_id_t data[2 * 2];
};

// ------------------------------------------------------------------------------------------------------------------------------------

metatile_attr_t GetMetatileAttr(s32 x, s32 y);
void ShiftMetatile(s32 x, s32 y, const struct MetatileShift *s);
void PatchMetatileMap(u32 x, u32 y, struct MetatilePatch *p);

#endif  // GUARD_RMZ3_OW_METATILE_H
