#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/leviathan.inc");

void leviathan_minigame_080fbba0(struct GameState* g);
void leviathan_minigame_080fbc30(struct GameState* g);
void leviathan_minigame_080fbcdc(struct GameState* g);

const GameLoopFunc LeviathanMinigameLoops[3] = {
    leviathan_minigame_080fbba0,
    leviathan_minigame_080fbc30,
    leviathan_minigame_080fbcdc,
};

const u8 u8_ARRAY_08386bb0[16] = {
    2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5,
};

const u8 u8_ARRAY_08386bc0[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 3, 5,
};

bool32 exitLeviathanMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedataManager.minigameHiscores[MINIGAME_LEVIATHAN] = s->unk_2c;
  SaveSystemData();
  return FALSE;
}
