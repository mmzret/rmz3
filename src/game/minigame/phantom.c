#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/phantom.inc");

void phantomMinigame_080fc13c(struct GameState* p);
void phantomMinigame_080fc1b8(struct GameState* p);
void phantomMinigame_080fc390(struct GameState* p);

const GameLoopFunc PhantomMinigameLoops[3] = {
    phantomMinigame_080fc13c,
    phantomMinigame_080fc1b8,
    phantomMinigame_080fc390,
};

bool32 exitPhantomMinigame(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;
  gSystemSavedataManager.minigameHiscores[MINIGAME_PHANTOM] = s->unk_3c;
  SaveSystemData();
  return FALSE;
}
