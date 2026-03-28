#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/fefnir.inc");

void fefnir_minigame_080fb2d8(struct GameState* g);
void fefnir_minigame_080fb354(struct GameState* g);
void fefnir_minigame_080fb48c(struct GameState* g);

const GameLoopFunc FefnirMinigameLoops[3] = {
    fefnir_minigame_080fb2d8,
    fefnir_minigame_080fb354,
    fefnir_minigame_080fb48c,
};

bool32 exitFefnirMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedataManager.minigameHiscores[MINIGAME_FEFNIR] = s->unk_28;
  SaveSystemData();
  return FALSE;
}
