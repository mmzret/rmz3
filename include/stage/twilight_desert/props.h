#ifndef GUARD_RMZ3_STAGE_TWILIGHT_DESERT_PROPS_H
#define GUARD_RMZ3_STAGE_TWILIGHT_DESERT_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct TwilightDesertState {
  u8 unk_000;
  u8 unk_001;
  u8 unk_002;
  u8 unk_003;
  u8 unk_004;
  u8 unk_005;
  u8 unk_006[258];
};
static_assert(sizeof(struct TwilightDesertState) == 264);

#endif  // GUARD_RMZ3_STAGE_TWILIGHT_DESERT_PROPS_H
