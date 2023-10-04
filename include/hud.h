#ifndef GUARD_RMZ3_HEALTH_H
#define GUARD_RMZ3_HEALTH_H

#include "common.h"
#include "entity.h"
#include "gba/types.h"

// state about BG0(Health Layer)
struct HUD {
  u16* bg0;  // -> 0x02030b70
  u16 unk_02;
  struct Zero* z;
  struct Entity* unk_0c;
  s32* timeLeft;  // e.g. Left time in Volcano Mid-boss room(Kill 25 Crossbynes)
  u8 _[12];
};

extern struct HUD gHUD;

void ResetHUD(u16* bg0);
void DrawStatus(void);
void DrawLeftTime(void);

#endif  // GUARD_RMZ3_OW_BG0_H
