#include "minigame.h"

#include "global.h"
#include "hud.h"
#include "palette_animation.h"
#include "pickup.h"
#include "sprite.h"
#include "system.h"
#include "zero.h"

void ExitStageLandscape(void);

static void MinigameLoop_InitMinigame(struct GameState* g);
static void MinigameLoop_Main(struct GameState* g);
static void MinigameLoop_ExitMinigame(struct GameState* g);

void MainLoop_Minigame(struct GameState* g) {
  static const GameLoopFunc MinigameLoops[3] = {
      MinigameLoop_InitMinigame,
      MinigameLoop_Main,
      MinigameLoop_ExitMinigame,
  };
  (MinigameLoops[g->mode[2]])(g);
}

// ------------------------------------------------------------------------------------------------------------------------------------

void initZeroMinigame(struct GameState* g);
void initCielMinigame(struct GameState* g);
void initCopyXMinigame(struct GameState* g);
void initHarpuiaMinigame(struct GameState* g);
void initFefnirMinigame(struct GameState* g);
void initLeviathanMinigame(struct GameState* g);
void initPhantomMinigame(struct GameState* g);

static void MinigameLoop_InitMinigame(struct GameState* g) {
  // clang-format off
  static const GameLoopFunc sMinigameInitializers[MINIGAME_COUNT] = {
      [MINIGAME_ZERO] = initZeroMinigame,
      [MINIGAME_CIEL] = initCielMinigame,
      [MINIGAME_COPY_X] = initCopyXMinigame,
      [MINIGAME_HARPUIA] = initHarpuiaMinigame,
      [MINIGAME_FEFNIR] = initFefnirMinigame,
      [MINIGAME_LEVIATHAN] = initLeviathanMinigame,
      [MINIGAME_PHANTOM] = initPhantomMinigame,
  };
  // clang-format on

  struct Pivot* pivot = &g->unk_0db8;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
  gPaletteManager.post_process = NULL;
  RemoveAllPaletteAnimations();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  wMOSAIC = 0x0;
  gPaletteManager.buf[0] = RGB_BLACK;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_BLACK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  g->unk_1ed8 = 0xFFFFFFFF;
  g->inMenu = FALSE;
  ResetPivot(pivot, &g->unk_0dc4, 0, 0);
  Renderer_Init(&g->rendererMain);
  Renderer_SetPivot(&g->rendererMain, pivot);
  ResetCollisionManager();
  ResetEntityEnvironment();
  RNG_0202f388 = (g->save).stageID;
  s32_0202f334 = -1;
  PTR_0202f384 = &g->unk_1ed8;
  pZero2 = g->z2;

  InitPlayerHeader(&g->entityHeaders[ENTITY_PLAYER], gPlayers, 1);
  InitWeaponHeader(&g->entityHeaders[ENTITY_WEAPON], gWeapons, 24);
  InitEnemyHeader(&g->entityHeaders[ENTITY_ENEMY], gEnemies, 18);
  InitProjectileHeader(&g->entityHeaders[ENTITY_PROJECTILE], gProjectiles, 24);
  InitVFXHeader(&g->entityHeaders[ENTITY_VFX], gVFXs, 64);
  InitSolidHeader(&g->entityHeaders[ENTITY_SOLID], gSolids, 22);
  InitPickupHeader(&g->entityHeaders[ENTITY_ITEM], gPickups, 10);
  ResetHUD((u16*)gGameState.bg0);

  // Fill by white for damaged entity palette (OBJ13)
  *(u32*)&gPaletteManager.buf[464] = *(u32*)&gPaletteManager.buf[466] = *(u32*)&gPaletteManager.buf[468] = *(u32*)&gPaletteManager.buf[470] = *(u32*)&gPaletteManager.buf[472] = *(u32*)&gPaletteManager.buf[474] = *(u32*)&gPaletteManager.buf[476] = *(u32*)&gPaletteManager.buf[478] = 0xFFFFFFFF;

  (sMinigameInitializers[g->mode[1]])(g);
  g->frames = 0;
  g->mode[2]++;
}

// ------------------------------------------------------------------------------------------------------------------------------------

bool32 zeroMinigame(struct GameState* g);
bool32 cielMinigame(struct GameState* g);
bool32 copyXMinigame(struct GameState* g);
bool32 harpuiaMinigame(struct GameState* g);
bool32 fefnirMinigame(struct GameState* g);
bool32 leviathanMinigame(struct GameState* g);
bool32 phantomMinigame(struct GameState* g);

// clang-format off
static const MinigameFunc sEachMinigameLoops[MINIGAME_COUNT] = {
    [MINIGAME_ZERO] = zeroMinigame,
    [MINIGAME_CIEL] = cielMinigame,
    [MINIGAME_COPY_X] = copyXMinigame,
    [MINIGAME_HARPUIA] = harpuiaMinigame,
    [MINIGAME_FEFNIR] = fefnirMinigame,
    [MINIGAME_LEVIATHAN] = leviathanMinigame,
    [MINIGAME_PHANTOM] = phantomMinigame,
}; // 0x08386AB4
// clang-format on

// 0x080f8f5c
// レジスタ割り当てがうまくいかない以外は問題なさそう
NON_MATCH static void MinigameLoop_Main(struct GameState* g) {
#if MODERN
  if (g->frames < 32) {
    g->frames++;
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  } else if (g->frames > 32) {
    g->frames--;
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames - FILTER_NONE;
  }
  g->unk_1ed8++;

  Renderer_Clear(&g->rendererMain);
  gMatrixCount = 0;
  {
    void* dst = gWhitePaintFlags;
    u32 bytesize = sizeof(gWhitePaintFlags);
    _CpuFastFill(0, dst, bytesize);
  }

  if ((sEachMinigameLoops[g->mode[1]])(g) == 0) g->mode[2]++;

  // ここのレジスタ割り当てがうまくいかない以外は問題なさそう
  if (g->mode[1] != MINIGAME_CIEL) {
    void* src = gOverworld.terrain.objects;
    void* dst = gOverworld.terrain.objectsPrev;
    u32 bytesize = gOverworld.terrain.objectLen * sizeof(struct Hazard);
    u32 fastsize = bytesize & ~31;
    CpuFastCopy(src, dst, fastsize);
    if (bytesize & 31) CpuCopy32(src + fastsize, dst + fastsize, bytesize & 31);
    gOverworld.terrain.objectLenPrev = gOverworld.terrain.objectLen;
    gOverworld.terrain.objectLen = 0;
  }

  UpdateHazardEntities(gSolidHeaderPtr);
  UpdateHazardEntities(gEnemyHeaderPtr);
  UpdateEntities(gZeroHeaderPtr);
  UpdateProjectiles();
  UpdateEntities(gWeaponHeaderPtr);
  UpdateEntities(gPickupHeaderPtr);
  UpdateVFXs();
  ClearAllHitboxes();
  RegisterHitboxes(gSolidHeaderPtr);
  RegisterHitboxes(gEnemyHeaderPtr);
  RegisterHitboxes(gZeroHeaderPtr);
  RegisterHitboxes(gProjectileHeaderPtr);
  RegisterHitboxes(gWeaponHeaderPtr);
  RegisterHitboxes(gPickupHeaderPtr);
  if (g->mode[1] != MINIGAME_CIEL) UpdateStageLandscape(&g->unk_0dc4);
  CheckCollision();
  RunDamageEffect(gSolidHeaderPtr);
  RunDamageEffect(gEnemyHeaderPtr);
  RunDamageEffect(gZeroHeaderPtr);
  RunDamageEffect(gPickupHeaderPtr);

  DrawCollidableEntity(gSolidHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gEnemyHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gZeroHeaderPtr, &g->rendererMain);
  DrawWeapon(&g->rendererMain);
  DrawEntity(gProjectileHeaderPtr, &g->rendererMain);
  DrawEntity(gVFXHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gPickupHeaderPtr, &g->rendererMain);
  if (g->mode[1] != MINIGAME_CIEL) DrawOverworld(&g->rendererMain);
  Renderer_Flush(&g->rendererMain);

  if (gIsPlayDamageSE && (!(gCollisionManager.sweep & SWEEP_ALL_ENEMY))) PlaySound(SE_ZAKO_STUN);
  gIsPlayDamageSE = FALSE;
#else
  INCCODE("asm/wip/MinigameLoop_Main.inc");
#endif
}

// ------------------------------------------------------------------------------------------------------------------------------------

bool32 exitZeroMinigame(struct GameState* g);
bool32 exitCielMinigame(struct GameState* g);
bool32 exitCopyXMinigame(struct GameState* g);
bool32 exitHarpuiaMinigame(struct GameState* g);
bool32 exitFefnirMinigame(struct GameState* g);
bool32 exitLeviathanMinigame(struct GameState* g);
bool32 exitPhantomMinigame(struct GameState* g);

static void MinigameLoop_ExitMinigame(struct GameState* g) {
  bool32 result;
  // clang-format off
  static const MinigameFunc sMinigameDeinitializers[MINIGAME_COUNT] = {
      [MINIGAME_ZERO] = exitZeroMinigame,
      [MINIGAME_CIEL] = exitCielMinigame,
      [MINIGAME_COPY_X] = exitCopyXMinigame,
      [MINIGAME_HARPUIA] = exitHarpuiaMinigame,
      [MINIGAME_FEFNIR] = exitFefnirMinigame,
      [MINIGAME_LEVIATHAN] = exitLeviathanMinigame,
      [MINIGAME_PHANTOM] = exitPhantomMinigame,
  };
  // clang-format on

  result = (sMinigameDeinitializers[g->mode[1]])(g);
  if (result == FALSE) {
    ExitStageLandscape();
    RemoveAllPaletteAnimations();
    ExitProcess();
  }
}
