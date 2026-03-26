#ifndef GUARD_RMZ3_OW_METATILE_H
#define GUARD_RMZ3_OW_METATILE_H

#include "types.h"

// Metatile is a 16x16px tile, which is made of 4 GBA tiles (8x8 x 4)

typedef u16 metatile_id_t;    // Metatile を識別するためのID
typedef u16 metatile_attr_t;  // Metatileの属性 (include/constants/metatile.h 参照)

typedef u16 Metatile[4];  // GBAのBGマップデータ x4枚分(16x16px)

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

// ------------------------------------------------------------------------------------------------------------------------------------

metatile_attr_t GetMetatileAttr(s32 x, s32 y);
metatile_attr_t GetHazardMetatileAttr(s32 x, s32 y);
metatile_attr_t FUN_080098a4(s32 x, s32 y);
metatile_attr_t GetGroundMetatileAttr(s32 x, s32 y);

void ShiftMetatile(s32 x, s32 y, const struct MetatileShift* s);
void PatchMetatileMap(u32 x, u32 y, struct MetatilePatch* p);

#endif  // GUARD_RMZ3_OW_METATILE_H
