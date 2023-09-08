#include "minigame.h"

#include "blink.h"
#include "global.h"
#include "hud.h"
#include "sprite.h"
#include "zero.h"

static void MinigameLoop_InitMinigame(struct GameState *g);

void MainLoop_Minigame(struct GameState *g) {
  static const MinigameLoopFunc MinigameLoops[3] = {
      MinigameLoop_InitMinigame,
      MinigameLoop_Main,
      MinigameLoop_ExitMinigame,
  };
  (MinigameLoops[g->mode[2]])(g);
}

// clang-format off
static const MinigameLoopFunc sMinigameInitializers[MINIGAME_COUNT] = {
    [MINIGAME_ZERO] = initZeroMinigame,
    [MINIGAME_CIEL] = initCielMinigame,
    [MINIGAME_COPY_X] = initCopyXMinigame,
    [MINIGAME_HARPUIA] = initHarpuiaMinigame,
    [MINIGAME_FEFNIR] = initFefnirMinigame,
    [MINIGAME_LEVIATHAN] = initLeviathanMinigame,
    [MINIGAME_PHANTOM] = initPhantomMinigame,
};
// clang-format on

static void MinigameLoop_InitMinigame(struct GameState *g) {
  struct Pivot *pivot = &g->unk_0db8;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0x0;
  PALETTE16(0) = RGB_BLACK;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x00;
  gVideoRegBuffer.dispcnt &= 0xFFF8;
  gVideoRegBuffer.dispcnt &= 0xF0FF;
  gVideoRegBuffer.dispcnt |= 0x0100;
  g->unk_1ed8 = 0xFFFFFFFF;
  g->inMenu = FALSE;
  ResetPivot(pivot, &g->unk_0dc4, 0, 0);
  ResetTaskManager(&g->taskManager);
  SetTaskPivot(&g->taskManager, pivot);
  ResetCollisionManager();
  resetData_08016db4();
  RNG_0202f388 = (g->save).stageID;
  s32_0202f334 = -1;
  PTR_0202f384 = &g->unk_1ed8;
  pZero2 = g->z2;

  InitPlayerHeader(&g->entityHeaders[ENTITY_PLAYER], &gZero, 1);
  InitWeaponHeader(&g->entityHeaders[ENTITY_WEAPON], gWeapons, 24);
  InitEnemyHeader(&g->entityHeaders[ENTITY_ENEMY], gEnemies, 18);
  InitProjectileHeader(&g->entityHeaders[ENTITY_PROJECTILE], gProjectiles, 24);
  InitVFXHeader(&g->entityHeaders[ENTITY_VFX], gVFXs, 64);
  InitSolidHeader(&g->entityHeaders[ENTITY_SOLID], gSolids, 22);
  InitMapItemHeader(&g->entityHeaders[ENTITY_ITEM], gMapItems, 10);
  ResetHUD(gGameState.bg0);

  // Fill by white for damaged entity palette (OBJ13)
  *(u32 *)&gPaletteManager.buf[464] = *(u32 *)&gPaletteManager.buf[466] = *(u32 *)&gPaletteManager.buf[468] = *(u32 *)&gPaletteManager.buf[470] = *(u32 *)&gPaletteManager.buf[472] = *(u32 *)&gPaletteManager.buf[474] = *(u32 *)&gPaletteManager.buf[476] = *(u32 *)&gPaletteManager.buf[478] = 0xFFFFFFFF;

  (sMinigameInitializers[g->mode[1]])(g);
  g->frames = 0;
  g->mode[2]++;
}

// clang-format off
const MinigameLoopFunc EachMinigameLoops[MINIGAME_COUNT] = {
    [MINIGAME_ZERO] = zeroMinigame,
    [MINIGAME_CIEL] = cielMinigame,
    [MINIGAME_COPY_X] = copyXMinigame,
    [MINIGAME_HARPUIA] = harpuiaMinigame,
    [MINIGAME_FEFNIR] = fefnirMinigame,
    [MINIGAME_LEVIATHAN] = leviathanMinigame,
    [MINIGAME_PHANTOM] = phantomMinigame,
};
// clang-format on

// clang-format off
const MinigameLoopFunc MinigameDeinitializers[MINIGAME_COUNT] = {
    [MINIGAME_ZERO] = exitZeroMinigame,
    [MINIGAME_CIEL] = exitCielMinigame,
    [MINIGAME_COPY_X] = exitCopyXMinigame,
    [MINIGAME_HARPUIA] = exitHarpuiaMinigame,
    [MINIGAME_FEFNIR] = exitFefnirMinigame,
    [MINIGAME_LEVIATHAN] = exitLeviathanMinigame,
    [MINIGAME_PHANTOM] = exitPhantomMinigame,
};
// clang-format on

const MinigameLoopFunc ZeroMinigameLoops[3] = {
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

const u8 u8_ARRAY_08386b58[40] = {
    0, 2, 0, 4, 2, 3, 1, 5, 0, 1, 0, 6, 1, 3, 1, 7, 4, 2, 0, 8, 2, 3, 1, 9, 4, 5, 2, 8, 5, 7, 3, 9, 8, 6, 4, 8, 6, 7, 5, 9,
};

const MinigameLoopFunc CopyXMinigameLoops[3] = {
    copyx_minigame_080fa560,
    copyx_minigame_080fa62c,
    copyx_minigame_080fa764,
};

const MinigameLoopFunc HarpuiaMinigameLoops[3] = {
    harpuia_minigame_080fab10,
    harpuia_minigame_080fabe8,
    harpuia_minigame_080faebc,
};

const MinigameLoopFunc FefnirMinigameLoops[3] = {
    fefnir_minigame_080fb2d8,
    fefnir_minigame_080fb354,
    fefnir_minigame_080fb48c,
};

const MinigameLoopFunc LeviathanMinigameLoops[3] = {
    leviathan_minigame_080fbba0,
    leviathan_minigame_080fbc30,
    leviathan_minigame_080fbcdc,
};

const u8 u8_ARRAY_08386bb0[16] = {
    2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5,
};

const u8 u8_ARRAY_08386bc0[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 3, 5,
};

const MinigameLoopFunc PhantomMinigameLoops[3] = {
    phantomMinigame_080fc13c,
    phantomMinigame_080fc1b8,
    phantomMinigame_080fc390,
};
