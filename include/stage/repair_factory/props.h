#ifndef GUARD_RMZ3_STAGE_REPAIR_FACTORY_PROPS_H
#define GUARD_RMZ3_STAGE_REPAIR_FACTORY_PROPS_H

#include "common.h"
#include "gba/types.h"

// 0x0202f228
struct RepairFactoryState {
  u8 unk_000;
  s8 unk_001;
  u8 unk_002;
  u8 unk_003;
  u8 unk_004[260];
};
static_assert(sizeof(struct RepairFactoryState) == 264);

#endif  // GUARD_RMZ3_STAGE_REPAIR_FACTORY_PROPS_H
