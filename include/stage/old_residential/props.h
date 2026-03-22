#ifndef GUARD_RMZ3_STAGE_OLD_RESIDENTIAL_PROPS_H
#define GUARD_RMZ3_STAGE_OLD_RESIDENTIAL_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Solid;

// 0x0202f228
struct OldResidentialState {
  struct Solid* leaf;
  u8 unk_004[4];
  u16 unk_008;
  u16 unk_00a;
  u16 unk_00c;
  u16 unk_00e;
  u16 unk_010;
  u16 unk_012;
  u8 unk_014[244];
};
static_assert(sizeof(struct OldResidentialState) == 264);

#endif  // GUARD_RMZ3_STAGE_OLD_RESIDENTIAL_PROPS_H
