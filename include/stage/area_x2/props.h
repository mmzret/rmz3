#ifndef GUARD_RMZ3_STAGE_AREA_X2_PROPS_H
#define GUARD_RMZ3_STAGE_AREA_X2_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct AreaX2State {
  u16 unk_000;
  u16 unk_002;
  u8 unk_004[2];
  u8 unk_006[2];
  u16 unk_008;
  u8 unk_00a[254];
};
static_assert(sizeof(struct AreaX2State) == 264);

#endif  // GUARD_RMZ3_STAGE_AREA_X2_PROPS_H
