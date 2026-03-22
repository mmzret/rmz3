#ifndef GUARD_RMZ3_STAGE_RBASE_PROPS_H
#define GUARD_RMZ3_STAGE_RBASE_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct ResistanceBaseState {
  u8 unk_000;
  u8 weather;
  u8 unk_002;
  u8 unk_003;
  u8 unk_004[260];
};
static_assert(sizeof(struct ResistanceBaseState) == 264);

#endif  // GUARD_RMZ3_STAGE_RBASE_PROPS_H
