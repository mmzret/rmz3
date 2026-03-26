#ifndef GUARD_RMZ3_STAGE_ANATRE_FOREST_PROPS_H
#define GUARD_RMZ3_STAGE_ANATRE_FOREST_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Solid;

// 0x0202f228
struct AnatreForestState {
  struct Solid* leaf;
  u8 unk_004;
  struct Solid* unk_008;
  u8 unk_00c;
  u8 unk_00d;
  u16 unk_00e;
  u8 unk_010[248];
};
static_assert(sizeof(struct AnatreForestState) == 264);

#endif  // GUARD_RMZ3_STAGE_ANATRE_FOREST_PROPS_H
