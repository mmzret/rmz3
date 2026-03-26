#ifndef GUARD_RMZ3_STAGE_WEIL_LABO_PROPS_H
#define GUARD_RMZ3_STAGE_WEIL_LABO_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct WeilLaboState {
  u8 unk_000;
  u8 unk_001[3];
  u32 unk_004;
  u16 unk_008;
  u16 unk_00a;
  u32 unk_00c;
  struct Coord unk_010;
  u32 unk_018;
  u32 unk_01c;
  u32 unk_020;
  struct Coord unk_024;
  struct Coord unk_02c;
  u8 unk_34[212];
};
static_assert(sizeof(struct WeilLaboState) == 264);

#endif  // GUARD_RMZ3_STAGE_WEIL_LABO_PROPS_H
