#include "game.h"

#include "global.h"
#include "menu.h"
#include "system.h"

void Process_Game(struct Process* p) {
  static const GameLoopFunc loop[4] = {
      MainLoop_Game,
      MainLoop_Menu,
      MainLoop_Disk,
      MainLoop_Minigame,
  };

  FUN_08002428(p);
  do {
    loop[gGameState.mode[0]](&gGameState);
    SwitchProcess(TRUE);
  } while (TRUE);
}

void SetGameMode(struct GameState* p, u32 mode) {
  *((u32*)p->mode) = mode;
  *((u32*)&p->frames) = 0;
  *(u32*)p->unk_008 = 0;
};
