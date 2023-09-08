#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "intro.h"
#include "system.h"

void ClearMemory(void);
void InitIntrHandlers(void);
void clear0x020014e0(void);
void InitInput(void);
void clear0x02001ee0(void);
void ClearVRAM(void);
void InitPaletteManager(void);
void InitSound(void);
void InitTextPrinter(u32 *);
void InitScheduler(bool32 ok);
void GameLoop(void);
void usrHBlankCallback(void);
void usrVBlankCallback(void);

WIP void AgbMain(void) {
#if MODERN
  ClearMemory();
  InitIntrHandlers();
  clear0x020014e0();
  InitInput();
  clear0x02001ee0();
  REG_DISPCNT = DISPCNT_FORCED_BLANK;
  ClearVRAM();
  InitPaletteManager();
  ClearBlinkings();
  ResetVideoRegister();
  ResetOAM();
  ClearBLDCLT_1();
  ResetWindow();
  ClearMOSAIC();
  InitSound();
  MaskBg0(gGameState.bg0, SCREEN_BASE(0), 1408, 0x3C0);
  InitTextPrinter(gGameState.bg0);
  PALETTE16(0) = RGB_WHITE;
  gIntrManager.slowGameRatio = 1;
  gIntrManager.hblankCallback = usrHBlankCallback;
  gIntrManager.lyc = 0;
  gIntrManager.vblankCallback = usrVBlankCallback;
  gGameState.unk_00c = TRUE;
  SetIntroMode(&gIntro, 0);
  gIntro.unk_12 = 0;

  InitScheduler(TRUE);
  ResetProcess(0, Process_SoftReset);
  ResetProcess(2, Process_System);

  GameLoop();
#else
  INCCODE("asm/wip/AgbMain.inc");
#endif
}
