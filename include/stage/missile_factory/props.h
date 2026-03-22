#ifndef GUARD_RMZ3_STAGE_MISSILE_FACTORY_PROPS_H
#define GUARD_RMZ3_STAGE_MISSILE_FACTORY_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct MissileFactoryState {
  u8 unk_000;
  u8 unk_001;
  s8 unk_002;
  u8 unk_003;
  u16 unk_004;
  u16 unk_006;
  u8 unk_008;
  u8 unk_009;
  u8 unk_00a;
  u8 unk_00b;
  u32 unk_00c;
  u32 unk_010;
  struct Coord unk_014;
  u8 unk_01c[236];
};
static_assert(sizeof(struct MissileFactoryState) == 264);

#endif  // GUARD_RMZ3_STAGE_MISSILE_FACTORY_PROPS_H
