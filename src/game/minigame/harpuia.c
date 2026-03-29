#include "game.h"
#include "global.h"
#include "minigame.h"

INCASM("asm/minigame/harpuia.inc");

bool32 harpuia_minigame_080fab10(struct GameState* g);
bool32 harpuia_minigame_080fabe8(struct GameState* g);
bool32 harpuia_minigame_080faebc(struct GameState* g);

const MinigameFunc HarpuiaMinigameLoops[3] = {
    harpuia_minigame_080fab10,
    harpuia_minigame_080fabe8,
    harpuia_minigame_080faebc,
};

// 0x080FAFC0
bool32 exitHarpuiaMinigame(struct GameState* g) {
  struct MinigameState* s = &(g->sceneState).mg;
  if (s->unk_06 == 0) {
    *((s16*)s->unk_00) = 2;
    s->unk_06++;
    return TRUE;
  }
  if (s->unk_06 == 1) {
    if ((*((s16*)s->unk_00) <= 0 || (--(*((s16*)s->unk_00)) <= 0))) {
      if (s->unk_3c > gSystemSavedataManager.minigameHiscores[MINIGAME_HARPUIA]) {
        gSystemSavedataManager.minigameHiscores[MINIGAME_HARPUIA] = s->unk_3c;
        SaveSystemData();
      }
      return FALSE;
    }
  }
  return TRUE;
}
