#include "game.h"
#include "global.h"
#include "text.h"

void OverworldLoop_080f2e44(struct GameState *g) {
  s16 ans;
  switch (g->mode[3]) {
    default: {
      OverworldLoop_CmdRoomTalk(g);
      break;
    }

    case 0: {
      PrintOptionMessage2(0x1332);
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 1: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage1(0x130E);
      g->mode[3]++;
      FALLTHROUGH;
    }
    case 2: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      if ((ans = handleWrapTwoChoice(g)) != 0) {
        if (ans > 0) {
          g->mode[3] = 0x12;
        } else {
          g->mode[3] = 0x0B;
        }
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
        (&gTextWindow.text)->flag |= (1 << 1);
        break;
      }
      SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
      break;
    }

    case 11: {
      if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        return;
      }
      PrintOptionMessage2(0x130F);
      g->mode[3] = 3;
      break;
    }
  }
}
