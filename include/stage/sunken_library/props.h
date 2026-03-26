#ifndef GUARD_RMZ3_STAGE_SUNKEN_LIBRARY_PROPS_H
#define GUARD_RMZ3_STAGE_SUNKEN_LIBRARY_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct SunkenLibraryState {
  u8 unk_000;
  u8 unk_001;
  u8 unk_002;
  u8 unk_003;
  u32 rng;
  u16 unk_008;
  u16 theta;
  u16 unk_00c;
  u8 unk_00e[250];
};
static_assert(sizeof(struct SunkenLibraryState) == 264);

#endif  // GUARD_RMZ3_STAGE_SUNKEN_LIBRARY_PROPS_H
