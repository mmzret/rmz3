#include "game.h"
#include "global.h"

u16 save_080f32f8(struct GameState *);

#define STATE(m) (m + 63)
NAKED void OverworldLoop_ManageSaveData(struct GameState *p) { INCCODE("asm/wip/OverworldLoop_ManageSaveData.inc"); }
#undef STATE
