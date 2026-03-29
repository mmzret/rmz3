#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/zero.inc");

void zeroMinigamePhase0(struct GameState* g);
void zeroMinigamePhase1(struct GameState* g);
void zeroMinigamePhase2(struct GameState* g);

const GameLoopFunc ZeroMinigameLoops[3] = {
    zeroMinigamePhase0,
    zeroMinigamePhase1,
    zeroMinigamePhase2,
};

// clang-format off
const struct Coord Coord_ARRAY_08386af8[6] = {
    {-0x2000, 0x1000}, {+0x2000, 0x1000},
    {-0x2000, 0x4800}, {+0x2000, 0x4800},
    {-0x2000, 0x8000}, {+0x2000, 0x8000},
};
// clang-format on

// clang-format off
const struct Coord Coord_ARRAY_08386b28[6] = {
    {+0x2800, 0x1000}, {-0x2800, 0x1000},
    {+0x1800, 0x4800}, {-0x1800, 0x4800},
    {+0x2800, 0x8000}, {-0x2800, 0x8000},
};
// clang-format on

// 0x080f9848
bool32 exitZeroMinigame(struct GameState* g) {
  struct MinigameState* s = &(g->sceneState).mg;
  if (s->unk_06 == 0) {
    *((s16*)s->unk_00) = 2;
    s->unk_06++;
    return TRUE;
  }
  if (s->unk_06 == 1) {
    if ((*((s16*)s->unk_00) <= 0 || (--(*((s16*)s->unk_00)) <= 0))) {
      if (s->unk_3c > gSystemSavedataManager.minigameHiscores[MINIGAME_ZERO]) {
        gSystemSavedataManager.minigameHiscores[MINIGAME_ZERO] = s->unk_3c;
        SaveSystemData();
      }
      return FALSE;
    }
  }
  return TRUE;
}
