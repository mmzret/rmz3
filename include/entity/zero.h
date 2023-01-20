#ifndef GUARD_RMZ3_ENTITY_ZERO_H
#define GUARD_RMZ3_ENTITY_ZERO_H

#include "entity/entity.h"

struct Zero {
  struct Entity s;
  u16 unk_32;
  u8 unk_34[18];
  u8 unk_52[32];
  struct Coord coord;
  struct Coord dydx;
  u8 unk_100[552];
};  // 652 bytes

#endif  // GUARD_RMZ3_ENTITY_ZERO_H
