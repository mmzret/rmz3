#ifndef GUARD_RMZ3_MINIGAME_H
#define GUARD_RMZ3_MINIGAME_H

#include "gba/gba.h"

struct MinigameState {
  u8 unk_00[4];
  s16 unk_04;
  u16 unk_06;
  u32 unk_08;  // Ciel score
  u8 unk_0c;
  u8 unk_0d[3];
  u8 unk_10[24];
  u32 unk_28;  // Fefnir Hiscore
  u32 unk_2c;  // Leviathan Hiscore
  u8 unk_30[12];
  u32 unk_3c;  // Phantom Hiscore
  u8 unk_40[192];
};
static_assert(sizeof(struct MinigameState) == 256);

#endif  // GUARD_RMZ3_MINIGAME_H
