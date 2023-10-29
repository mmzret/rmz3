#include "blink.h"
#include "collision.h"
#include "cyberelf.h"
#include "disk.h"
#include "element.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "hud.h"
#include "menu.h"
#include "mission.h"
#include "overworld.h"
#include "sound.h"
#include "story.h"
#include "system.h"
#include "task.h"
#include "text.h"
#include "weapon.h"
#include "zero.h"

static const u16 u16_ARRAY_08386130[32];
static const GameLoopFunc sGameLoops[16];

static void FUN_080ee228(void);

void FUN_08019678(struct Story *p);

const u16 u16_ARRAY_083860b0[64] = {
    0x0000, 0x0000, 0x8000, 0x0020, 0x0020, 0x8020, 0x0040, 0x0040, 0x8040, 0x0060, 0x0060, 0x8060, 0x0080, 0x0080, 0x8080, 0x00A0, 0x00A0, 0x80A0, 0x00C0, 0x00C0, 0x80C0, 0x00E0, 0x00E0, 0x80E0, 0x0100, 0x0100, 0x8100, 0x0120, 0x0120, 0x8120, 0x0140, 0x0140, 0x8140, 0x0160, 0x0160, 0x8160, 0x0180, 0x0180, 0x8180, 0x01A0, 0x01A0, 0x81A0, 0x01C0, 0x01C0, 0x81C0, 0x01E0, 0x01E0, 0x81E0, 0x0200, 0x0200, 0x8200, 0x0220, 0x0220, 0x8220, 0x0240, 0x0240, 0x8240, 0x0260, 0x0260, 0x8260, 0x0280, 0x0280, 0x8280, 0x02A0,
};

static const u16 u16_ARRAY_08386130[32] = {
    0x02A0, 0x82A0, 0x02C0, 0x02C0, 0x82C0, 0x02E0, 0x02E0, 0x82E0, 0x0300, 0x0300, 0x8300, 0x0320, 0x8320, 0x8320, 0x0340, 0x8340, 0x8340, 0x1364, 0x2789, 0xB78D, 0xCBB2, 0x5BD6, 0x6FFB, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
};

// ------------------------------------------------------------------------------------------------------------------------------------

/*
  ゲーム内で強制セーブする時用
  ▷${idx} レベル${rank} ${playTime} ${playLaps} ${mode}

  e.g.  ▷1 レベルS 01:21'20 2 H
*/
NAKED void printSaveDataRowText(s32 idx, u8 rank, u32 playTime, u8 playLaps, u32 mode, u8 y) { INCCODE("asm/todo/printSaveDataRowText.inc"); }

void ApplyCyberSpaceColorFilter(void) {
  u8 val;
  CpuFastCopy(u16_ARRAY_08386130, CopyFrom_08386130, 64);
  val = 0;
  gUnkSineTableIdx = val;
  gPaletteManager.unk_408 = FUN_080ee228;
}

void CancelCyberSpaceColorFilter(void) {
  gPaletteManager.unk_408 = NULL;
  return;
}

NAKED static void FUN_080ee228(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r5, #0\n\
	ldr r1, _080EE300 @ =0x02000108\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080EE304 @ =gSineTable\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #4\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	asrs r4, r0, #1\n\
	movs r1, #0\n\
	ldr r7, _080EE308 @ =0x02000048\n\
	ldr r6, _080EE30C @ =u16_ARRAY_083860b0\n\
_080EE250:\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r2, r1, #1\n\
	adds r2, r2, r7\n\
	lsrs r0, r5, #0xc\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r6\n\
	ldrh r0, [r0]\n\
	strh r0, [r2]\n\
	adds r5, r5, r4\n\
	adds r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	lsls r2, r1, #0x10\n\
	asrs r3, r2, #0x10\n\
	cmp r3, #0x1f\n\
	ble _080EE250\n\
	lsls r1, r4, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xb\n\
	subs r0, r0, r1\n\
	lsrs r4, r0, #5\n\
	cmp r3, #0x3f\n\
	bgt _080EE2A0\n\
	ldr r6, _080EE308 @ =0x02000048\n\
	ldr r3, _080EE30C @ =u16_ARRAY_083860b0\n\
_080EE284:\n\
	asrs r2, r2, #0x10\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r6\n\
	lsrs r0, r5, #0xc\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r5, r5, r4\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	asrs r0, r2, #0x10\n\
	cmp r0, #0x3f\n\
	ble _080EE284\n\
_080EE2A0:\n\
	movs r1, #4\n\
	ldr r5, _080EE310 @ =0x0202FDBA\n\
_080EE2A4:\n\
	ldrh r0, [r5]\n\
	lsls r1, r1, #0x10\n\
	asrs r4, r1, #0x10\n\
	asrs r0, r4\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EE2C4\n\
	lsls r0, r4, #5\n\
	ldr r1, _080EE314 @ =0x05000200\n\
	adds r0, r0, r1\n\
	movs r1, #0x10\n\
	ldr r2, _080EE318 @ =0x001F001F\n\
	ldr r3, _080EE308 @ =0x02000048\n\
	bl FUN_080ee328\n\
_080EE2C4:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	ble _080EE2A4\n\
	ldr r0, _080EE31C @ =0x05000240\n\
	ldr r4, _080EE318 @ =0x001F001F\n\
	ldr r5, _080EE308 @ =0x02000048\n\
	movs r1, #0x10\n\
	adds r2, r4, #0\n\
	adds r3, r5, #0\n\
	bl FUN_080ee328\n\
	ldr r0, _080EE320 @ =0x05000340\n\
	movs r1, #0x10\n\
	adds r2, r4, #0\n\
	adds r3, r5, #0\n\
	bl FUN_080ee328\n\
	ldr r0, _080EE324 @ =0x05000040\n\
	movs r1, #0xe0\n\
	adds r2, r4, #0\n\
	adds r3, r5, #0\n\
	bl FUN_080ee328\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EE300: .4byte 0x02000108\n\
_080EE304: .4byte gSineTable\n\
_080EE308: .4byte 0x02000048\n\
_080EE30C: .4byte u16_ARRAY_083860b0\n\
_080EE310: .4byte 0x0202FDBA\n\
_080EE314: .4byte 0x05000200\n\
_080EE318: .4byte 0x001F001F\n\
_080EE31C: .4byte 0x05000240\n\
_080EE320: .4byte 0x05000340\n\
_080EE324: .4byte 0x05000040\n\
 .syntax divided\n");
}

NAKED void FUN_080ee328(u32 *pal, u32 r1, u32 r2, u16 *src) {
  asm(".syntax unified\n\
	lsrs r1, r1, #1\n\
	push {r4, r5, r6, r7}\n\
	movs r7, #0x7f\n\
_080EE32E:\n\
	ldr r4, [r0]\n\
	lsrs r5, r4, #0xa\n\
	ands r5, r2\n\
	lsrs r6, r4, #5\n\
	ands r6, r2\n\
	ands r4, r2\n\
	adds r4, r4, r5\n\
	adds r4, r4, r6\n\
	adds r5, r4, #0\n\
	ands r5, r7\n\
	lsls r5, r5, #1\n\
	ldrh r5, [r3, r5]\n\
	lsrs r4, r4, #0x10\n\
	ands r4, r7\n\
	lsls r4, r4, #1\n\
	ldrh r4, [r3, r4]\n\
	lsls r4, r4, #0x10\n\
	orrs r4, r5\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	subs r1, #1\n\
	bne _080EE32E\n\
	pop {r4, r5, r6, r7}\n\
	bx lr\n\
 .syntax divided\n");
}

// --------------------------------------------

void MainLoop_Game(struct GameState *s) {
  (sGameLoops[s->mode[1]])(s);
  return;
}

WIP void SaveGraphicState(struct GameState *p) {
#if MODERN
  p->savedColor0 = *((u16 *)&gPaletteManager.buf[0]);
  SaveDispRegister();

  CpuFastCopy(&gBlendRegBuffer, &p->savedBlendRegister, sizeof(struct WramBlendRegister) / 32);
  CpuCopy32(&gBlendRegBuffer, &p->savedBlendRegister, sizeof(struct WramBlendRegister) % 32);
  gBlendRegBuffer.bldclt = 0;

  CpuFastCopy(&gWindowRegBuffer, &p->savedWindowRegister, sizeof(struct WramWindowRegister) / 32);
  CpuCopy32(&gWindowRegBuffer, &p->savedWindowRegister, sizeof(struct WramWindowRegister) % 32);
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;

  CpuFastCopy(OBJ_VRAM1, p->savedObjVRAM, 16384);
  CpuFastCopy(&gPaletteManager.buf[256], p->savedObjPal, 512);
#else
  INCCODE("asm/wip/SaveGraphicState.inc");
#endif
}

WIP void RestoreGraphicState(struct GameState *p) {
#if MODERN
  RestoreBackground();
  CpuFastCopy(&p->savedBlendRegister, &gBlendRegBuffer, sizeof(struct WramBlendRegister) / 32);
  CpuCopy32(&p->savedBlendRegister, &gBlendRegBuffer, sizeof(struct WramBlendRegister) % 32);
  CpuFastCopy(&p->savedWindowRegister, &gWindowRegBuffer, sizeof(struct WramWindowRegister) / 32);
  CpuCopy32(&p->savedWindowRegister, &gWindowRegBuffer, sizeof(struct WramWindowRegister) % 32);
  CpuFastCopy(p->savedObjVRAM, OBJ_VRAM1, 16384);
  CpuFastCopy(p->savedObjPal, &gPaletteManager.buf[256], 512);
  *((u16 *)&gPaletteManager.buf[0]) = p->savedColor0;
#else
  INCCODE("asm/wip/RestoreGraphicState.inc");
#endif
}

// 00 00 nn nn
NAKED static void GameLoop_NewGame(struct GameState *p) { INCCODE("asm/todo/GameLoop_NewGame.inc"); }

// 00 01 nn nn
static void GameLoop_ContinueGame(struct GameState *p) {
  (p->save).stageID = STAGE_BASE;
  gGameState.z2 = gGameState.z3 = &gZero;
  FUN_08019678(&(p->save).story);
  ClearPlayInfo(&(p->save).playinfo);
  clearSecretDiskData((p->save).disk);
  clearUnlockedCyberElfData((p->save).elf);
  ClearZeroStatus(&(p->save).status);
  LoadStageRun((p->save).stageID, 1);
  SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 1, 0x60));
}

static void GameLoop_Nop2(struct GameState *_) { return; }

static void GameLoop_PreOverworld(struct GameState *p) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0;
  PALETTE16(0) = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  *(u32 *)gVideoRegBuffer.bgofs[0] = 0;
  p->unk_1ed8 = 0xFFFFFFFF;
  p->inMenu = FALSE;
  ResetTaskManager(&p->taskManager);
  ResetCollisionManager();
  ResetEntityEnvironment();
  RNG_0202f388 = (u32)(p->save).stageID;
  s32_0202f334 = -1;
  PTR_0202f384 = (void *)&p->unk_1ed8;
  pZero2 = p->z2;
  InitPlayerHeader(&p->entityHeaders[ENTITY_PLAYER], &gZero, 1);
  InitWeaponHeader(&p->entityHeaders[ENTITY_WEAPON], gWeapons, 24);
  InitBossHeader(&p->entityHeaders[ENTITY_BOSS], gBosses, 5);
  InitEnemyHeader(&p->entityHeaders[ENTITY_ENEMY], gEnemies, 18);
  InitProjectileHeader(&p->entityHeaders[ENTITY_PROJECTILE], gProjectiles, 24);
  InitVFXHeader(&p->entityHeaders[ENTITY_VFX], gVFXs, 64);
  InitSolidHeader(&p->entityHeaders[ENTITY_SOLID], gSolids, 22);
  InitMapItemHeader(&p->entityHeaders[ENTITY_ITEM], gMapItems, 10);
  InitElfHeader(&p->entityHeaders[ENTITY_ELF], gElfEntities, 16);
  FUN_080250b8();
  ResetHUD((u16 *)gGameState.bg0);
  ClearTextWindow((u16 *)gGameState.bg0);
  SaveZeroStatus(p->z2, &(p->save).status);
  ClearStageRun(&p->taskManager);
  p->mode[1]++;  // -> OVERWORLD
}

WIP static void GameLoop_Overworld(struct GameState *p) {
#if MODERN
  bool8 isPaused;
  bool32 escape;

  isPaused = FALSE;
  if ((p->inMenu || (gLifeRecoverAmount != 0)) || (wPauseFrame != 0)) {
    isPaused = TRUE;
  }

  p->unk_1ed8++;
  ClearTaskBuffer(&p->taskManager);
  gMatrixCount = 0;
  CpuFastFill(0, gWhitePaintFlags, 32);

  if (FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED) && (!isPaused) && (!gPause)) {
    if (gTimeElfTimer == 0) {
      TurnUpBGM();
      CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
      if (isSoundPlaying(SE_TIME_ELF_HURRY)) {
        stopSound(SE_TIME_ELF_HURRY);
      }
    } else {
      if ((gTimeElfTimer & 0x8000) == 0) {
        if (gTimeElfTimer < 3 * SECOND) {
          if (isSoundPlaying(SE_TIME_ELF)) {
            stopSound(SE_TIME_ELF);
          }
          if (!isSoundPlaying(SE_TIME_ELF_HURRY)) {
            PlaySound(SE_TIME_ELF_HURRY);
          }
        }
      } else {
        TurnDownBGM();
        PlaySound(SE_TIME_ELF);
        gTimeElfTimer &= 0x7FFF;
      }
      gTimeElfTimer--;
    }
  }

  escape = OverworldUpdate(isPaused || gPause);
  if (escape) {
    gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
    gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
    SetGameMode(p, GAMEMODE(MAINGAME, CHANGE_MAP, 0, 0));
    return;
  }

  if (isPaused) {
    ClearAllHitboxes();
  } else {
    if (((gStageRun.missionStatus & MISSION_STAY) && ((gStageRun.vm.active & 1) == 0)) && ((gStageRun.missionStatus & STOP_TIME_COUNT) == 0)) {
      if (gMission.clearTime < 359999) {
        gMission.clearTime++;
      }
      if ((gMission.unk_00)->playTime < 21599999) {
        (gMission.unk_00)->playTime++;
      }
    }
    FUN_0802511c();
    if (!gPause) {
      UpdateHazardEntities(gSolidHeaderPtr);
      UpdateHazardEntities(gBossHeaderPtr);
      UpdateHazardEntities(gZakoHeaderPtr);
      UpdateEntities(gZeroHeaderPtr);
      UpdateProjectiles();
      UpdateEntities(gWeaponHeaderPtr);
      UpdateEntities(gMapItemHeaderPtr);
    }
    UpdateHazardEntities(gElfHeaderPtr);
    UpdateVFXs();
    ClearAllHitboxes();
    if (!gPause) {
      RegisterHitboxes(gSolidHeaderPtr);
      RegisterHitboxes(gBossHeaderPtr);
      RegisterHitboxes(gZakoHeaderPtr);
      RegisterHitboxes(gZeroHeaderPtr);
      RegisterHitboxes(gProjectileHeaderPtr);
      RegisterHitboxes(gWeaponHeaderPtr);
      RegisterHitboxes(gMapItemHeaderPtr);
      RegisterHitboxes(gElfHeaderPtr);
    }
  }
  CheckItemGain(p);
  CheckCollision();
  RunDamageEffect(gSolidHeaderPtr);
  RunDamageEffect(gBossHeaderPtr);
  RunDamageEffect(gZakoHeaderPtr);
  RunDamageEffect(gZeroHeaderPtr);
  RunDamageEffect(gMapItemHeaderPtr);

  struct TaskManager *tm = &p->taskManager;
  DrawCollidableEntity(gSolidHeaderPtr, tm);
  DrawCollidableEntity(gBossHeaderPtr, tm);
  DrawCollidableEntity(gZakoHeaderPtr, tm);
  DrawCollidableEntity(gZeroHeaderPtr, tm);
  DrawEntity(gElfHeaderPtr, tm);
  DrawWeapon(tm);
  DrawEntity(gProjectileHeaderPtr, tm);
  DrawEntity(gVFXHeaderPtr, tm);
  DrawCollidableEntity(gMapItemHeaderPtr, tm);
  DrawHUD(p);
  UpdateTextWindow();
  RunOverworldLoop(p);

  if ((((gJoypad[0].pressed & START_BUTTON) && (*(s32 *)p->mode == 0x400)) && ((((p->z2->body).status & BODY_STATUS_DEAD) == 0 && ((p->z2->body).hp != 0)))) && ((((gTextWindow.text.mode == 0 || (gTextWindow.text.mugshot == 0)) && ((gStageRun.missionStatus & DISABLE_MENU) == 0)) && ((((((gStageRun.missionStatus & MISSION_STAY) && ((gStageRun.vm.active & 1) == 0)) && (gStageRun.vm.screenEffect == NO_SCREEN_EFFECT)) && ((gGameState.mode[2] == 0 && (!gPause)))) && ((wMOSAIC == 0 && (gLifeRecoverAmount == 0)))))))) {
    p->inMenu = TRUE;
    SetGameMode(p, GAMEMODE(MAINGAME, OPEN_MENU, 0, 0));
  }

  CameraUpdate(isPaused || gPause);
  if ((!isPaused) && (!gPause)) {
    if ((gIsPlayDamageSE) && ((gCollisionManager.sweep & SWEEP_ALL_ENEMY) == 0)) {
      PlaySound(SE_ZAKO_STUN);
    }
    gIsPlayDamageSE = FALSE;
  }
  wPauseFrame = gCollisionManager.hitstop;
#else
  INCCODE("asm/wip/GameLoop_Overworld.inc");
#endif
}

static void GameLoop_OpenMenu(struct GameState *p) {
  if (p->mode[3] == 0) {
    TurnDownBGM();
    p->frames = 32;
    p->mode[3]++;
  }
  p->frames -= 2;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = p->frames;

  if (p->frames == 0) {
    SaveGraphicState(p);
    PALETTE16(0) = RGB_BLACK;
    gVideoRegBuffer.dispcnt &= 0xc1ff;
    wMOSAIC = 0;
    PauseAllBlinks();
    CancelCyberSpaceColorFilter();
    SetGameMode(p, GAMEMODE(MODE_MENU, 0, 0, 0));
  } else {
    void *dst;
    struct TaskManager *tm = &(p->taskManager);
    ClearTaskBuffer(tm);
    ClearAllHitboxes();
    gMatrixCount = 0;
    dst = gWhitePaintFlags;
    CpuFastFill(0, dst, 32);
    OverworldUpdate(TRUE);
    DrawCollidableEntity(gSolidHeaderPtr, tm);
    DrawCollidableEntity(gBossHeaderPtr, tm);
    DrawCollidableEntity(gZakoHeaderPtr, tm);
    DrawCollidableEntity(gZeroHeaderPtr, tm);
    DrawEntity(gElfHeaderPtr, tm);
    DrawWeapon(tm);
    DrawEntity(gProjectileHeaderPtr, tm);
    DrawEntity(gVFXHeaderPtr, tm);
    DrawCollidableEntity(gMapItemHeaderPtr, tm);
    CameraUpdate(TRUE);
    DrawHUD(p);
    UpdateTextWindow();
    { vu32 _; }
  }
}

WIP static void GameLoop_CloseMenu(struct GameState *p) {
#if MODERN
  struct TaskManager *tm;
  void *dst;
  s16 frames;

  if (p->mode[3] == 0) {
    struct Zero *z;
    struct Zero_b4 *b4 = &p->z2->unk_b4;
    u8 color = (b4->status).body;

    if (FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) {
      ApplyCyberSpaceColorFilter();
    }
    RestoreGraphicState(p);
    ResumeAllBlinks();
    p->frames = 0;

    if ((p->save).gamemode == 1) {
      color = BODY_CHIP_PROTO;
    } else if ((p->save).gamemode == 2) {
      color = BODY_CHIP_ULTIMA;
    }

    z = p->z2;
    if (z->posture == POSTURE_SHADOW) {
      LoadZeroPalette(&z->s, color);
      LoadShadowDashPalette(p->z2, color);
    } else {
      LoadZeroPalette(&z->s, color);
    }

    if (gStageRun.missionStatus & MISSION_B5) {
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      SetGameMode(p, GAMEMODE(MAINGAME, CHANGE_MAP, 0, 0));
      return;
    }
    p->mode[3]++;
  }

  tm = &p->taskManager;
  ClearTaskBuffer(tm);
  ClearAllHitboxes();
  gMatrixCount = 0;
  dst = gWhitePaintFlags;
  CpuFastFill(0, dst, 32);
  OverworldUpdate(TRUE);
  DrawCollidableEntity(gSolidHeaderPtr, tm);
  DrawCollidableEntity(gBossHeaderPtr, tm);
  DrawCollidableEntity(gZakoHeaderPtr, tm);
  DrawCollidableEntity(gZeroHeaderPtr, tm);
  DrawEntity(gElfHeaderPtr, tm);
  DrawWeapon(tm);
  DrawEntity(gProjectileHeaderPtr, tm);
  DrawEntity(gVFXHeaderPtr, tm);
  DrawCollidableEntity(gMapItemHeaderPtr, tm);
  CameraUpdate(TRUE);
  DrawHUD(p);
  UpdateTextWindow();
  { vu32 _; }

  p->frames += 2;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = p->frames;
  if (p->frames == 32) {
    p->inMenu = FALSE;
    if (FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED) == 0) {
      TurnUpBGM();
    } else {
      SetStageNoiseVolume(SE_TIME_ELF);
      SetStageNoiseVolume(SE_TIME_ELF_HURRY);
    }
    SetGameMode(p, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
  }
#else
  INCCODE("asm/wip/GameLoop_CloseMenu.inc");
#endif
}

NAKED static void GameLoop_SwitchCyberSpace(struct GameState *p) { INCCODE("asm/todo/GameLoop_SwitchCyberSpace.inc"); }

/*
  00 08 -- --

  - デモプレイが終わってタイトル画面に戻る時
  - ティウンティウン後の次の残機でリトライするとき
*/
WIP static void GameLoop_ChangeMap(struct GameState *p) {
#if MODERN
  UpdateStoryFlag();
  if (FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    ExitProcess();
    return;
  }

  if (gStageRun.missionStatus & MISSION_FAIL) {
    u32 mode;
    if ((gMission.unk_00)->extraLife == 0) {
      mode = GAMEMODE(MAINGAME, GAMEOVER, 0, 0);
    } else {
      if (gMission.retryCount < 99) {
        gMission.retryCount++;
      }
      (gMission.unk_00)->extraLife--;
      mode = GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0);
    }
    SetGameMode(p, mode);
    return;
  }

  if ((p->save).stageID == STAGE_BASE) {
    if (gStageRun.checkpoint == 12) {
      (p->save).stageID = STAGE_MISSILE_FACTORY;
      InitStageRun(STAGE_MISSILE_FACTORY);
      SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }
    if (gStageRun.checkpoint == 19) {
      (p->save).stageID = STAGE_SUB_ARCADIA;
      InitStageRun(STAGE_SUB_ARCADIA);
      SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }
  }

  if (!IS_MISSION) {
    (p->save).stageID = STAGE_BASE;
    LoadStageRun(STAGE_BASE, 9);
    SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
    return;
  }

  if ((p->save).stageID == STAGE_SPACE_CRAFT) {
    (p->save).stageID = STAGE_BASE;
    LoadStageRun(STAGE_BASE, 3);
    SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
    return;
  }

  if (FLAG(gCurStory.s.gameflags, FLAG_11)) {
    if (!FLAG(gCurStory.s.gameflags, FLAG_12)) {
      if ((p->save).stageID == STAGE_BASE) {
        (p->save).stageID = STAGE_MISSILE_FACTORY;
        InitStageRun(STAGE_MISSILE_FACTORY);
      } else {
        (p->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 4);
      }
      SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }

    if ((p->save).stageID == STAGE_MISSILE_FACTORY) {
      (p->save).stageID = STAGE_BASE;
      LoadStageRun(STAGE_BASE, 13);
      SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }

    if (FLAG(gCurStory.s.gameflags, FLAG_15) && FLAG(gCurStory.s.gameflags, NO_HARPUIA)) {
      if ((p->save).stageID == STAGE_AREA_X2) {
        (p->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 15);
        SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
        return;
      }

      if (FLAG(gCurStory.s.gameflags, SUNKEN_ANALYZE)) {
        if (FLAG(gCurStory.s.gameflags, FLAG_WEIL_LABO)) {
          if ((p->save).stageID == STAGE_SUB_ARCADIA) {
            (p->save).stageID = STAGE_BASE;
            LoadStageRun(STAGE_BASE, 7);
          } else if ((p->save).stageID == STAGE_WEILS_LABO) {
            SetGameMode(p, GAMEMODE(MAINGAME, GAMEMODE_11, 0, 0));
            return;
          }
          SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
          return;
        }

        if ((p->save).stageID == STAGE_BASE) {
          (p->save).stageID = STAGE_SUB_ARCADIA;
          InitStageRun(STAGE_SUB_ARCADIA);
          return;
        }

        (p->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 16);
        SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
        return;
      }
    }
  }

  (p->save).stageID = STAGE_BASE;
  LoadStageRun(STAGE_BASE, 7);
  SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
#else
  INCCODE("asm/wip/GameLoop_ChangeMap.inc");
#endif
}

/*
00 09 xx nn

xx (02030b62):
  0: 初期化
  1: 一定時間の後、BGMを流して次のフェイズ(2)へ
  2: ユーザー入力待ち
  3: 画面をフェードアウト？
  4: ユーザーが選んだ選択肢(02030b66)を処理
      0: コンティニュー
      1: セーブしたところからやり直す
      2: ゲームをやめる

02030b62 (処理フェイズ)に関わらず、選択肢の文字を描画する処理は行う(画面が真っ黒のときでも)
*/
NAKED static void GameLoop_GameOver(struct GameState *p) { INCCODE("asm/todo/GameLoop_GameOver.inc"); }

static void GameLoop_Nop10(struct GameState *p) { return; }  // 00 0a -- --

NAKED static void GameLoop_UnlockMinigame(struct GameState *p) { INCCODE("asm/todo/GameLoop_UnlockMinigame.inc"); }
NAKED static void GameLoop_SystemSaveScreen(struct GameState *p) { INCCODE("asm/todo/GameLoop_SystemSaveScreen.inc"); }

/*
  00 0D xx --

  ハードモードかアルティメットモードでゲームを始めた時に通知を鳴らしてゲームを開始させる
*/
static void GameLoop_StartSpecialMode(struct GameState *p) {
  switch (p->mode[2]) {
    case 0: {
      PlaySound(SE_NOTIFICATION);
      p->frames = 7200;
      p->mode[2]++;
      break;
    }
    case 1: {
      p->frames--;
      if ((p->frames == 0) || (!isSoundPlaying(SE_NOTIFICATION))) {
        SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      }
      break;
    }
  }
}

/*
  00 0e 00 00
  タイトル画面で放置した時のデモプレイと関係あり
*/
static void GameLoop_demoplay_080f033c(struct GameState *p) {
  struct ZeroStatus *status, *status2;
  u16 stageID;
  struct SaveSlot *s = &p->save;

  s->gamemode = 0;
  gGameState.z2 = gGameState.z3 = &gZero;
  FUN_08019678(&(p->save).story);
  ClearPlayInfo(&(p->save).playinfo);
  clearSecretDiskData((p->save).disk);
  clearUnlockedCyberElfData((p->save).elf);
  status = &(p->save).status;
  ClearZeroStatus(status);
  SET_FLAG(gCurStory.s.gameflags, DEMO_PLAY);
  *(u8 *)&(p->save).story.id = *(u8 *)&(p->save).story.id | 0x40;

  (status->keyMap).keys.jump = A_BUTTON;
  (status->keyMap).keys.dash = L_BUTTON;
  (status->keyMap).keys.main = B_BUTTON;
  (status->keyMap).keys.sub = R_BUTTON;

  (p->save).status.keyMap.btnMode = 0;     // Type A
  (p->save).status.keyMap.attackMode = 1;  // Type B
  (p->save).status.keyMap.unk_a = 0;

  status2 = &gGameState.save.status;
  status2->unlockedWeapon |= (1 << 2);
  status2->unlockedWeapon |= (1 << 3);

  if ((p->save).stageID == STAGE_VOLCANO) {
    status2->mainWeapon = WEAPON_ROD;
    status2->subWeapon = WEAPON_SABER;

  } else if ((p->save).stageID == STAGE_OCEAN) {
    status2->mainWeapon = WEAPON_BUSTER;
    status2->subWeapon = WEAPON_SABER;

  } else if ((p->save).stageID == STAGE_REPAIR_FACTORY) {
    status2->mainWeapon = WEAPON_SABER;
    status2->subWeapon = WEAPON_ROD;

  } else {
    status2->mainWeapon = WEAPON_SHIELD;
    status2->subWeapon = WEAPON_SABER;
    status2->body = BODY_CHIP_FLAME;
    status2->element = ELEMENT_FLAME;
  }

  InitStageRun((p->save).stageID);
  SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
}

/*
  00 0f 00 00
*/
static void GameLoop_SkieEventScene(struct GameState *p) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0;
  PALETTE16(0) = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  text_080e9730();
  SetGameMode(p, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
}

// clang-format off
// 00 xx nn nn
static const GameLoopFunc sGameLoops[16] = {
    GameLoop_NewGame,
		GameLoop_ContinueGame,
		GameLoop_Nop2,
		GameLoop_PreOverworld,
		GameLoop_Overworld,
		GameLoop_OpenMenu,
		GameLoop_CloseMenu,
		GameLoop_SwitchCyberSpace,
		GameLoop_ChangeMap,
		GameLoop_GameOver,
		GameLoop_Nop10,
		GameLoop_UnlockMinigame,
		GameLoop_SystemSaveScreen,
		GameLoop_StartSpecialMode,
		GameLoop_demoplay_080f033c,
		GameLoop_SkieEventScene,
};
// clang-format on
