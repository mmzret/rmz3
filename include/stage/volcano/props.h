#ifndef GUARD_RMZ3_STAGE_VOLCANO_PROPS_H
#define GUARD_RMZ3_STAGE_VOLCANO_PROPS_H

#include "common.h"
#include "gba/types.h"

struct Solid;

// 0x0202f228
struct VolcanoState {
  u8 unk_000;
  u8 unk_001;
  u8 unk_002;
  u8 unk_003;
  u16 unk_004;
  u16 unk_006;
  struct Solid* coffins[2];
  u8 unk_010[248];
};
static_assert(sizeof(struct VolcanoState) == 264);

#endif  // GUARD_RMZ3_STAGE_VOLCANO_PROPS_H
