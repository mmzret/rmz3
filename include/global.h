#ifndef GUARD_RMZ3_GLOBAL_H
#define GUARD_RMZ3_GLOBAL_H

#include "gba/gba.h"
#include "ioreg.h"

struct Coord {
  s32 x;
  s32 y;
};

struct BgMapHeader {
  u32 field_0x0;
  u16 w;
  u16 h;
};

struct Rect {
  s16 x0;
  s16 y0;
  s16 x1;
  s16 y1;
};

#endif  // GUARD_RMZ3_GLOBAL_H
