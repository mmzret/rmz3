#ifndef GUARD_RMZ3_STAGE_OCEAN_PROPS_H
#define GUARD_RMZ3_STAGE_OCEAN_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Solid;

// 0x0202f228
struct OceanState {
  u8 unk_000;
  u8 unk_001;
  s8 unk_002;
  u8 unk_003;
  struct Solid* btns[4];
  u8 unk_014[244];
};
static_assert(sizeof(struct OceanState) == 264);

#endif  // GUARD_RMZ3_STAGE_OCEAN_PROPS_H
