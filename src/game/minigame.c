#include "minigame.h"

#include "blink.h"
#include "global.h"
#include "hud.h"
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
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.post_process = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
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
  ResetEntityEnvironment();
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
};
// clang-format on

NAKED static void MinigameLoop_Main(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	ldrh r0, [r6, #4]\n\
	movs r2, #4\n\
	ldrsh r1, [r6, r2]\n\
	cmp r1, #0x1f\n\
	bgt _080F8F90\n\
	adds r0, #1\n\
	adds r1, r0, #0\n\
	strh r0, [r6, #4]\n\
	ldr r2, _080F8F88 @ =gPaletteManager\n\
	ldr r3, _080F8F8C @ =0x00000402\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	b _080F8FA4\n\
	.align 2, 0\n\
_080F8F88: .4byte gPaletteManager\n\
_080F8F8C: .4byte 0x00000402\n\
_080F8F90:\n\
	cmp r1, #0x20\n\
	ble _080F8FB4\n\
	subs r0, #1\n\
	strh r0, [r6, #4]\n\
	ldr r2, _080F9170 @ =gPaletteManager\n\
	subs r0, #0x20\n\
	ldr r3, _080F9174 @ =0x00000402\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	movs r1, #0xff\n\
_080F8FA4:\n\
	ands r0, r1\n\
	subs r3, #1\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
_080F8FB4:\n\
	ldr r2, _080F9178 @ =0x00001ED8\n\
	adds r1, r6, r2\n\
	ldr r0, [r1]\n\
	adds r0, #1\n\
	str r0, [r1]\n\
	movs r3, #0x9a\n\
	lsls r3, r3, #4\n\
	adds r0, r6, r3\n\
	bl ClearTaskBuffer\n\
	ldr r1, _080F917C @ =0x0202F354\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r1, _080F9180 @ =0x0202F360\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _080F9184 @ =0x001FFFFF\n\
	mov sl, r2\n\
	ldr r2, _080F9188 @ =0x01000008\n\
	mov r0, sp\n\
	bl CpuFastSet\n\
	ldr r1, _080F918C @ =sEachMinigameLoops\n\
	ldrb r0, [r6, #1]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r6, #0\n\
	bl _call_via_r1\n\
	cmp r0, #0\n\
	bne _080F8FFA\n\
	ldrb r0, [r6, #2]\n\
	adds r0, #1\n\
	strb r0, [r6, #2]\n\
_080F8FFA:\n\
	ldrb r0, [r6, #1]\n\
	cmp r0, #1\n\
	beq _080F9058\n\
	ldr r7, _080F9190 @ =0x020023D4\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #2\n\
	adds r3, r3, r7\n\
	mov sb, r3\n\
	subs r0, r7, #2\n\
	mov r8, r0\n\
	ldrb r0, [r0]\n\
	lsls r4, r0, #1\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #3\n\
	adds r5, r4, #0\n\
	movs r0, #0x20\n\
	rsbs r0, r0, #0\n\
	ands r5, r0\n\
	lsrs r2, r5, #2\n\
	mov r1, sl\n\
	ands r2, r1\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	bl CpuFastSet\n\
	movs r0, #0x1f\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	beq _080F904A\n\
	adds r0, r5, r7\n\
	mov r2, sb\n\
	adds r1, r5, r2\n\
	lsrs r2, r4, #2\n\
	mov r3, sl\n\
	ands r2, r3\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x13\n\
	orrs r2, r3\n\
	bl CpuSet\n\
_080F904A:\n\
	mov r0, r8\n\
	ldrb r1, [r0]\n\
	subs r0, r7, #1\n\
	strb r1, [r0]\n\
	movs r2, #0\n\
	mov r1, r8\n\
	strb r2, [r1]\n\
_080F9058:\n\
	ldr r5, _080F9194 @ =gSolidHeaderPtr\n\
	ldr r0, [r5]\n\
	bl UpdateHazardEntities\n\
	ldr r7, _080F9198 @ =gZakoHeaderPtr\n\
	ldr r0, [r7]\n\
	bl UpdateHazardEntities\n\
	ldr r3, _080F919C @ =0x0203029C\n\
	mov r8, r3\n\
	ldr r0, [r3]\n\
	bl UpdateEntities\n\
	bl UpdateProjectiles\n\
	ldr r4, _080F91A0 @ =gWeaponHeaderPtr\n\
	ldr r0, [r4]\n\
	bl UpdateEntities\n\
	ldr r0, _080F91A4 @ =gPickupHeaderPtr\n\
	mov sb, r0\n\
	ldr r0, [r0]\n\
	bl UpdateEntities\n\
	bl UpdateVFXs\n\
	bl ClearAllHitboxes\n\
	ldr r0, [r5]\n\
	bl RegisterHitboxes\n\
	ldr r0, [r7]\n\
	bl RegisterHitboxes\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	bl RegisterHitboxes\n\
	ldr r2, _080F91A8 @ =gProjectileHeaderPtr\n\
	mov sl, r2\n\
	ldr r0, [r2]\n\
	bl RegisterHitboxes\n\
	ldr r0, [r4]\n\
	bl RegisterHitboxes\n\
	mov r3, sb\n\
	ldr r0, [r3]\n\
	bl RegisterHitboxes\n\
	ldrb r0, [r6, #1]\n\
	cmp r0, #1\n\
	beq _080F90CA\n\
	ldr r1, _080F91AC @ =0x00000DC4\n\
	adds r0, r6, r1\n\
	bl UpdateStageLandscape\n\
_080F90CA:\n\
	bl CheckCollision\n\
	ldr r0, [r5]\n\
	bl RunDamageEffect\n\
	ldr r0, [r7]\n\
	bl RunDamageEffect\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	bl RunDamageEffect\n\
	mov r3, sb\n\
	ldr r0, [r3]\n\
	bl RunDamageEffect\n\
	ldr r0, [r5]\n\
	movs r1, #0x9a\n\
	lsls r1, r1, #4\n\
	adds r4, r6, r1\n\
	adds r1, r4, #0\n\
	bl DrawCollidableEntity\n\
	ldr r0, [r7]\n\
	adds r1, r4, #0\n\
	bl DrawCollidableEntity\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r1, r4, #0\n\
	bl DrawCollidableEntity\n\
	adds r0, r4, #0\n\
	bl DrawWeapon\n\
	mov r3, sl\n\
	ldr r0, [r3]\n\
	adds r1, r4, #0\n\
	bl DrawEntity\n\
	ldr r0, _080F91B0 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	adds r1, r4, #0\n\
	bl DrawEntity\n\
	mov r1, sb\n\
	ldr r0, [r1]\n\
	adds r1, r4, #0\n\
	bl DrawCollidableEntity\n\
	ldrb r0, [r6, #1]\n\
	cmp r0, #1\n\
	beq _080F913A\n\
	adds r0, r4, #0\n\
	bl DrawOverworld\n\
_080F913A:\n\
	adds r0, r4, #0\n\
	bl RunAllTasks\n\
	ldr r0, _080F91B4 @ =0x0202F330\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F915A\n\
	ldr r0, _080F91B8 @ =gCollisionManager\n\
	ldrb r1, [r0, #1]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F915A\n\
	movs r0, #0x29\n\
	bl PlaySound\n\
_080F915A:\n\
	ldr r1, _080F91B4 @ =0x0202F330\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F9170: .4byte gPaletteManager\n\
_080F9174: .4byte 0x00000402\n\
_080F9178: .4byte 0x00001ED8\n\
_080F917C: .4byte 0x0202F354\n\
_080F9180: .4byte gWhitePaintFlags\n\
_080F9184: .4byte 0x001FFFFF\n\
_080F9188: .4byte 0x01000008\n\
_080F918C: .4byte sEachMinigameLoops\n\
_080F9190: .4byte 0x020023D4\n\
_080F9194: .4byte gSolidHeaderPtr\n\
_080F9198: .4byte gZakoHeaderPtr\n\
_080F919C: .4byte 0x0203029C\n\
_080F91A0: .4byte gWeaponHeaderPtr\n\
_080F91A4: .4byte gPickupHeaderPtr\n\
_080F91A8: .4byte gProjectileHeaderPtr\n\
_080F91AC: .4byte 0x00000DC4\n\
_080F91B0: .4byte gVFXHeaderPtr\n\
_080F91B4: .4byte 0x0202F330\n\
_080F91B8: .4byte gCollisionManager\n\
 .syntax divided\n");
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
    ClearBlinkings();
    ExitProcess();
  }
}
