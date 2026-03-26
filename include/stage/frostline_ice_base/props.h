#ifndef GUARD_RMZ3_STAGE_FROSTLINE_ICE_BASE_PROPS_H
#define GUARD_RMZ3_STAGE_FROSTLINE_ICE_BASE_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Solid;

// 0x0202f228
struct FrostlineIceBaseState {
  u16 unk_000;
  u8 unk_002[262];
};
static_assert(sizeof(struct FrostlineIceBaseState) == 264);

#endif  // GUARD_RMZ3_STAGE_FROSTLINE_ICE_BASE_PROPS_H
