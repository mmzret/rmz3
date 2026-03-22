#ifndef GUARD_RMZ3_STAGE_SPACECRAFT_PROPS_H
#define GUARD_RMZ3_STAGE_SPACECRAFT_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Boss;

// 0x0202f228
struct SpaceCraftState {
  struct Boss* omega;
  struct Coord omegaCoord;
  u8 unk_00c[2];
  u16 unk_00e;
  u8 unk_010[248];
};
static_assert(sizeof(struct SpaceCraftState) == 264);

#endif  // GUARD_RMZ3_STAGE_SPACECRAFT_PROPS_H
