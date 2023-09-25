#include "game.h"
#include "global.h"
#include "text.h"

void OverworldLoop_080f2f44(struct GameState *g) {
  s16 ans;

  switch (g->mode[3]) {
    default: {
      OverworldLoop_ManageSaveData(g);
      break;
    }

    case 0: {
      PrintOptionMessage2(0x1336);
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 1: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage1(0x1302);
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 2: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      if ((ans = handleWrapTwoChoice(g)) != 0) {
        if (ans > 0) {
          SET_FLAG(gCurStory.s.gameflags, FLAG_17);
          g->mode[3] = 0x70;
          break;
        }
        if (ans == -1) {
          SET_FLAG(gCurStory.s.gameflags, FLAG_17);
          g->mode[3] = 0x7C;
          break;
        }
        PlaySound(SE_NOT_ALLOWED);
      }
      break;
    }
    case 3: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      SetGameMode(g, 0xC0400);
      break;
    }

    case 0x77:
    case 0x7C: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage2(0x1337);
      g->mode[3] = 3;
      break;
    }
  }
}
