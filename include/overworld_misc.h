#ifndef GUARD_RMZ3_OW_MISC_H
#define GUARD_RMZ3_OW_MISC_H

#include "common.h"
#include "entity.h"
#include "gba/types.h"

// --------------------------------------------

s32 FUN_0800a134(s32 x, s32 y);
s32 FUN_0800a05c(s32 x, s32 y);
void FUN_080186c8(u32 top, u32 bottom);
void InitStageEntityManager(u8 stageID, bool8 missionDone);

#endif  // GUARD_RMZ3_OW_MISC_H
