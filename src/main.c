#include "game.h"
#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "intro.h"
#include "palette_animation.h"
#include "system.h"

void ClearMemory(void);
void InitIntrHandlers(void);
void clear0x020014e0(void);
void InitInput(void);
void clear0x02001ee0(void);
void ClearVRAM(void);
void InitPaletteManager(void);
void InitSound(void);
void InitTextPrinter(void* tilemap);
void InitScheduler(bool32 ok);
void RunScheduler(void);
void usrHBlankCallback(void);
void usrVBlankCallback(void);

NON_MATCH void AgbMain(void) {
#if MODERN
  ClearMemory();
  InitIntrHandlers();
  clear0x020014e0();
  InitInput();
  clear0x02001ee0();
  REG_DISPCNT = DISPCNT_FORCED_BLANK;
  ClearVRAM();
  InitPaletteManager();
  RemoveAllPaletteAnimations();
  ResetVideoRegister();
  ResetOAM();
  ClearBLDCLT_1();
  ResetWindow();
  ClearMOSAIC();
  InitSound();
  EnableBG0(gGameState.bg0, SCREEN_BASE(0), 1408, RGB(0, 30, 0));
  InitTextPrinter(gGameState.bg0);
  gPaletteManager.buf[0] = RGB_WHITE;
  gIntrManager.slowGameRatio = 1;
  gIntrManager.hblankCallback = usrHBlankCallback;
  gIntrManager.lyc = 0;
  gIntrManager.vblankCallback = usrVBlankCallback;
  gGameState.unk_00c = TRUE;
  SetIntroMode(&gIntro, 0);
  gIntro.demo_id = 0;

  InitScheduler(TRUE);
  ResetProcess(0, Process_SoftReset);  // Process_SoftReset -> Process_Intro -> Process_Game
  ResetProcess(2, Process_System);

  RunScheduler();
#else
  INCCODE("asm/wip/AgbMain.inc");
#endif
}
