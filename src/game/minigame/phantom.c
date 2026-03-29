#include "game.h"
#include "global.h"
#include "minigame.h"
#include "text.h"

extern const u8 Unicode_SCORE_0810e2b8[];
extern const u8 Unicode_HI_SCORE_0810e2c0[];

void MinigamePhantom_DrawScoreHiscore(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintUnicodeString(Unicode_SCORE_0810e2b8, 1, 0);
  PrintMinigameNumber(s->unk_34, 12, 0);
  PrintUnicodeString(Unicode_HI_SCORE_0810e2c0, 15, 0);
  PrintMinigameNumber(s->unk_3c, 28, 0);
}

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
