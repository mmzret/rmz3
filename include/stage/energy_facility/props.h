#ifndef GUARD_RMZ3_STAGE_ENERGY_FACILITY_PROPS_H
#define GUARD_RMZ3_STAGE_ENERGY_FACILITY_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct EnergyFacilityState {
  u8 unk_000[4];
  s32 unk_004;
  s32 unk_008;
  u8 unk_00c[2];
  u16 unk_00e;
  u8 unk_010[2];
  u8 unk_012[2];
  u16 unk_014;
  u16 unk_016;
  u8 unk_018[240];
};
static_assert(sizeof(struct EnergyFacilityState) == 264);

#endif  // GUARD_RMZ3_STAGE_ENERGY_FACILITY_PROPS_H
