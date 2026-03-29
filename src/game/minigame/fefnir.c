#include "game.h"
#include "global.h"
#include "minigame.h"
#include "text.h"

extern const u8 Unicode_SCORE_0810e284[];
extern const u8 Unicode_HI_SCORE_0810e28c[];

void MinigameFefnir_DrawScoreHiscore(struct GameState* g) {
  struct MinigameState* s = (struct MinigameState*)(g->sceneState).raw;

  PrintUnicodeString(Unicode_SCORE_0810e284, 1, 0);
  minigame_str_080e9d04(s->unk_20, 12, 0);
  PrintUnicodeString(Unicode_HI_SCORE_0810e28c, 15, 0);
  minigame_str_080e9d04(s->unk_28, 28, 0);
}

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
