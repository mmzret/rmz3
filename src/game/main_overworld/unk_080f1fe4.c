#include "game.h"
#include "global.h"
#include "text.h"

void OverworldLoop_080f1fe4(struct GameState *g) {
  switch (g->mode[3]) {
    default: {
      OverworldLoop_ManageSaveData(g);
      break;
    }

    case 0: {
      PrintOptionMessage2(0x1301);
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
      s16 ans;
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      if ((ans = handleWrapTwoChoice(g)) != 0) {
        if (ans > 0) {
          g->mode[3] = 0x70;
          break;
        }
        if (ans == -1) {
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
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 4: {
      if ((&gTextWindow.text)->mode != 0) {
        (&gTextWindow.text)->flag |= TEXT_FLAG_TERMINATE;
      } else {
        SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
      }
      break;
    }

    case 0x77: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage2(0x1303);
      g->mode[3] = 3;
      break;
    }

    case 0x7C: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage2(0x1304);
      g->mode[3] = 3;
      break;
    }
  }
}
