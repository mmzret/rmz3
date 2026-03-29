#include "blink.h"
#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/ciel.inc");

const u8 u8_ARRAY_08386b58[40] = {
    0, 2, 0, 4, 2, 3, 1, 5, 0, 1, 0, 6, 1, 3, 1, 7, 4, 2, 0, 8, 2, 3, 1, 9, 4, 5, 2, 8, 5, 7, 3, 9, 8, 6, 4, 8, 6, 7, 5, 9,
};

#define STATE (&(g->sceneState).mg)

bool32 exitCielMinigame(struct GameState* g) {
  if (gSystemSavedataManager.minigameHiscores[MINIGAME_CIEL] < STATE->unk_08) {
    gSystemSavedataManager.minigameHiscores[MINIGAME_CIEL] = STATE->unk_08;
    SaveSystemData();
  }

  gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON;
  ClearBlink(0xD6);
  return FALSE;
}

#undef STATE
