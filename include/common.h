#ifndef GUARD_RMZ3_COMMON_H
#define GUARD_RMZ3_COMMON_H

#include "gba/types.h"

struct Coord16 {
  s16 x;
  s16 y;
};

struct Coord {
  s32 x;
  s32 y;
};

struct Border {
  s32 left;
  s32 right;
  s32 top;
  s32 bottom;
};

struct DrawPivot {
  struct Coord coord;
  struct Coord lefttop;
  struct Coord offset;
};

struct Pivot {
  struct Coord *coord;   // Pivotの座標
  struct Coord *offset;  // Pivotのオフセット(フィールド上では基本的に(0, 0)だが振動時とかに変化)
  void *_;               // Unused
};

struct BgMapHeader {
  u32 unk_00;
  u16 w;
  u16 h;
};

/*
  (x, y )------------(x+w, y  )
  |                           |
  |                           |
  (x,y+h)------------(x+w, y+h)
*/
struct Rect {
  s16 x;
  s16 y;
  s16 w;
  s16 h;
};

#endif  // GUARD_RMZ3_COMMON_H
