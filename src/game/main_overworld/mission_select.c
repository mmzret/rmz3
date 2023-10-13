#include "game.h"
#include "global.h"
#include "text.h"

void OverworldLoop_MissionSelect(struct GameState *g) {
  s16 ans;

  switch (g->mode[3]) {
    default: {
      OverworldLoop_CmdRoomTalk(g);
      break;
    }

    case 0: {
      PrintOptionMessage2(0x130D);
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
          g->mode[3] = 18;
        } else {
          g->mode[3] = 11;
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
        (&gTextWindow.text)->flag |= TEXT_FLAG_TERMINATE;
      } else {
        SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
      }
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
