#include "collision.h"
#include "cyberelf.h"
#include "disk.h"
#include "element.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "hud.h"
#include "menu.h"
#include "overworld.h"
#include "palette_animation.h"
#include "pickup.h"
#include "renderer.h"
#include "score.h"
#include "sound.h"
#include "story.h"
#include "system.h"
#include "text.h"
#include "weapon.h"
#include "zero.h"

static const u16 u16_ARRAY_08386130[32];
static const GameLoopFunc sGameLoops[16];

extern const struct Graphic gGraphic_GameOverString;
extern const struct Palette gPalette_GameOverString;

static void PostProcess_CyberSpaceColorFilter(void);
static void FUN_080ee328(u32* pal, u32 length, u32 r2, u16* lut);

void InitElFxManager(void);
void UpdateElFxManager(void);

const u16 u16_ARRAY_083860b0[64] = {
    0x0000, 0x0000, 0x8000, 0x0020, 0x0020, 0x8020, 0x0040, 0x0040, 0x8040, 0x0060, 0x0060, 0x8060, 0x0080, 0x0080, 0x8080, 0x00A0, 0x00A0, 0x80A0, 0x00C0, 0x00C0, 0x80C0, 0x00E0, 0x00E0, 0x80E0, 0x0100, 0x0100, 0x8100, 0x0120, 0x0120, 0x8120, 0x0140, 0x0140, 0x8140, 0x0160, 0x0160, 0x8160, 0x0180, 0x0180, 0x8180, 0x01A0, 0x01A0, 0x81A0, 0x01C0, 0x01C0, 0x81C0, 0x01E0, 0x01E0, 0x81E0, 0x0200, 0x0200, 0x8200, 0x0220, 0x0220, 0x8220, 0x0240, 0x0240, 0x8240, 0x0260, 0x0260, 0x8260, 0x0280, 0x0280, 0x8280, 0x02A0,
};

static const u16 u16_ARRAY_08386130[32] = {
    0x02A0, 0x82A0, 0x02C0, 0x02C0, 0x82C0, 0x02E0, 0x02E0, 0x82E0, 0x0300, 0x0300, 0x8300, 0x0320, 0x8320, 0x8320, 0x0340, 0x8340, 0x8340, 0x1364, 0x2789, 0xB78D, 0xCBB2, 0x5BD6, 0x6FFB, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
};

// ------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief セーブデータの1行分のテキストを描画する
 * @param idx Save sector index (0..)
 * @param rank 0: F, 1: E, 2: D, 3: C, 4: B, 5: A, 6: S
 * @param playTime プレイ時間 (フレーム単位)
 * @param lap 何周目か (0: 1周目, 1: 2周目, ...)
 * @param mode 0: Normal, 1: Hardmode, 2: Ultimate
 * @param y8 描画先のy座標 (タイル単位)
 * @details ▷${idx+1} レベル${rank} ${playTime} ${lap} ${mode}, e.g.  ▷1 レベルS 01:21'20 2 H
 * @note 0x080ee00c
 * @note ゲーム内で強制セーブする時のみ使う? (普段は PrintSaveDataRow ?)
 * @note なぜか ゲームモードの部分の x8 の (7+18) のコンパイル結果だけが不自然に一致しない
 */
NON_MATCH void PrintSaveDataRowText(u8 idx, u8 rank, u32 playTime, u8 lap, u8 mode, u8 y8) {
#if MODERN
  PrintString(gStrNumber(1 + idx), 7, y8);      // ${idx+1}
  PrintString(STRING(40 + rank), (7 + 2), y8);  // レベル${rank}

  PrintString(gStrNumber(playTime / (60 * 60 * 60 * 10)), (7 + 7), y8);    // Hour (digit 10)
  PrintString(gStrNumber((playTime / (60 * 60 * 60)) % 10), (7 + 8), y8);  // Hour (digit 1)
  PrintString(STRING(STR_COLON), (7 + 9), y8);                             // :
  PrintString(gStrNumber((playTime / (60 * 60 * 10)) % 6), (7 + 10), y8);  // Minute (digit 10)
  PrintString(gStrNumber((playTime / (60 * 60)) % 10), (7 + 11), y8);      // Minute (digit 1)
  PrintString(STRING(8), (7 + 12), y8);                                    // '
  PrintString(gStrNumber((playTime / (60 * 10)) % 6), (7 + 13), y8);       // Second (digit 10)
  PrintString(gStrNumber((playTime / 60) % 10), (7 + 14), y8);             // Second (digit 1)
  if (lap > 0) {
    if (lap > 9) PrintString(gStrNumber(lap / 10), (7 + 16), y8);
    PrintString(gStrNumber(lap % 10), (7 + 17), y8);
  }
  if (mode == 1) {                         // H (Hardmode)
    PrintString(STRING(3), (7 + 18), y8);  // ここの (7+18) のコンパイル結果だけが一致しない (しかも意味不明)
  } else if (mode == 2) {                  // U (Ultimate mode)
    PrintString(STRING(4), (7 + 18), y8);  // ここの (7+18) のコンパイル結果だけが一致しない (しかも意味不明)
  }
#else
  INCCODE("asm/wip/PrintSaveDataRowText.inc");
#endif
}

// 0x080ee1dc
void EnableCyberSpaceColorFilter(void) {
  u8 val;
  CpuFastCopy(u16_ARRAY_08386130, &gCyberSpaceColorHashtable[64], 64);
  val = 0;
  gUnkSineTableIdx = val;
  gPaletteManager.post_process = PostProcess_CyberSpaceColorFilter;
}

void DisableCyberSpaceColorFilter(void) {
  gPaletteManager.post_process = NULL;
  return;
}

NAKED static void PostProcess_CyberSpaceColorFilter(void) {
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
	ldr r7, _080EE308 @ =gCyberSpaceColorHashtable\n\
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
	ldr r6, _080EE308 @ =gCyberSpaceColorHashtable\n\
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
	ldr r5, _080EE310 @ =gSpawnManager+0x22A\n\
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
	ldr r3, _080EE308 @ =gCyberSpaceColorHashtable\n\
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
	ldr r5, _080EE308 @ =gCyberSpaceColorHashtable\n\
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
_080EE308: .4byte gCyberSpaceColorHashtable\n\
_080EE30C: .4byte u16_ARRAY_083860b0\n\
_080EE310: .4byte gSpawnManager+0x22A\n\
_080EE314: .4byte 0x05000200\n\
_080EE318: .4byte 0x001F001F\n\
_080EE31C: .4byte 0x05000240\n\
_080EE320: .4byte 0x05000340\n\
_080EE324: .4byte 0x05000040\n\
 .syntax divided\n");
}

/**
 * @brief サイバー空間用のテーブルを使った色の変換処理
 * @param length 2byte 単位の長さ = 色数
 * @param lut gCyberSpaceColorHashtable
 * @note 0x080ee328
 * @warning asm直書きかもしれない　(push の前に length >>= 1 のアセンブリが入ってたり, ループの終了判定で subs して(cmpせず) すぐに bne はあまりみない気がする)
 */
NAKED static void FUN_080ee328(u32* pal, u32 length, u32 r2, u16* lut) {
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

static void GameLoop_NewGame(struct GameState* g);
static void GameLoop_ContinueGame(struct GameState* g);
static void GameLoop_Nop2(struct GameState* g);
static void GameLoop_PreOverworld(struct GameState* g);
static void GameLoop_Overworld(struct GameState* g);
static void GameLoop_OpenMenu(struct GameState* g);
static void GameLoop_CloseMenu(struct GameState* g);
static void GameLoop_SwitchCyberSpace(struct GameState* g);
static void GameLoop_EndRun(struct GameState* g);
static void GameLoop_GameOver(struct GameState* g);
static void GameLoop_Nop10(struct GameState* g);
static void GameLoop_UnlockMinigame(struct GameState* g);
static void GameLoop_SystemSaveScreen(struct GameState* g);
static void GameLoop_StartSpecialMode(struct GameState* g);
static void GameLoop_StartDemoPlay(struct GameState* g);
static void GameLoop_SkieEventScene(struct GameState* g);

void MainLoop_Game(struct GameState* g) {
  // clang-format off
  static const GameLoopFunc sGameLoops[16] = {
    [NEW_GAME]  = GameLoop_NewGame,
    [CONTINUE_GAME]  = GameLoop_ContinueGame,
    [GAME_SCENE_NOP_2]  = GameLoop_Nop2,
    [PRE_OVERWORLD]  = GameLoop_PreOverworld,
    [OVERWORLD]  = GameLoop_Overworld,
    [OPEN_MENU]  = GameLoop_OpenMenu,
    [GAME_SCENE_6]  = GameLoop_CloseMenu,
    [GAME_SCENE_7]  = GameLoop_SwitchCyberSpace,
    [GAME_SCENE_END_RUN]  = GameLoop_EndRun,
    [GAMEOVER]  = GameLoop_GameOver,
    [GAME_SCENE_NOP_10] = GameLoop_Nop10,
    [UNLOCK_MINIGAME] = GameLoop_UnlockMinigame,
    [GAME_SCENE_12] = GameLoop_SystemSaveScreen,
    [START_SPECIAL_MODE] = GameLoop_StartSpecialMode,
    [DEMOPLAY] = GameLoop_StartDemoPlay,
    [SKIP_EVENT] = GameLoop_SkieEventScene,
  };
  // clang-format on
  (sGameLoops[g->mode[1]])(g);
}

// 0x080ee378
void SaveGraphicState(struct GameState* g) {
  g->savedColor0 = gPaletteManager.buf[0];
  SaveDispRegister();

  {
    void* src = &gBlendRegBuffer;
    void* dst = &g->savedBlendRegister;
    u32 bytesize = sizeof(struct WramBlendRegister);
    MemCopy32(src, dst, bytesize);
    gBlendRegBuffer.bldclt = 0;
  }

  {
    void* src = &gWindowRegBuffer;
    void* dst = &g->savedWindowRegister;
    u32 bytesize = sizeof(struct WramWindowRegister);
    MemCopy32(src, dst, bytesize);
    gWindowRegBuffer.dispcnt = 0;
    gWindowRegBuffer.winin[2] = 0xFF;
  }

  {
    void* src = OBJ_VRAM1;
    void* dst = g->savedObjVRAM;
    u32 bytesize = OBJ_VRAM1_SIZE;
    CpuFastCopy(src, dst, bytesize);
  }
  {
    void* src = &gPaletteManager.buf[256];
    void* dst = g->savedObjPal;
    u32 bytesize = OBJ_PLTT_SIZE;
    CpuFastCopy(src, dst, bytesize);
  }
}

// 0x080ee42c
void RestoreGraphicState(struct GameState* g) {
  RestoreBackground();
  {
    void* src = &g->savedBlendRegister;
    void* dst = &gBlendRegBuffer;
    u32 bytesize = sizeof(struct WramBlendRegister);
    MemCopy32(src, dst, bytesize);
  }
  {
    void* src = &g->savedWindowRegister;
    void* dst = &gWindowRegBuffer;
    u32 bytesize = sizeof(struct WramWindowRegister);
    MemCopy32(src, dst, bytesize);
  }
  {
    void* src = g->savedObjVRAM;
    void* dst = OBJ_VRAM1;
    u32 bytesize = OBJ_VRAM1_SIZE;
    CpuFastCopy(src, dst, bytesize);
  }
  {
    void* src = g->savedObjPal;
    void* dst = &gPaletteManager.buf[256];
    u32 bytesize = OBJ_PLTT_SIZE;
    CpuFastCopy(src, dst, bytesize);
  }
  gPaletteManager.buf[0] = g->savedColor0;
}

// 00 00 nn nn
static void GameLoop_NewGame(struct GameState* g) {
  (&(g->save))->gamemode = 0;
  gGameState.z2 = gGameState.z3 = gPlayers;
  (g->save).stageID = STAGE_SPACE_CRAFT;
  (&(g->save))->lap = 0;
  FUN_08019678(&(g->save).story);
  ClearPlayInfo(&(g->save).playinfo);
  clearSecretDiskData((g->save).disk);
  clearUnlockedCyberElfData((g->save).elf);
  ClearZeroStatus(&(g->save).status);
  if ((gSystemSavedata.hardmodeLock == (gSineTable[8] & 0xFF)) && (gJoypad[0].input & L_BUTTON)) {
    (&(g->save))->gamemode = 1;
    SET_FLAG((g->save).story.gameflags, FLAG_HARD);
    clearSecretDiskDataHard((g->save).disk);
    clearUnlockedCyberElfDataHard((g->save).elf);
    ClearZeroStatusHard(&(g->save).status);
  }
  if ((gSystemSavedata.ultimateModeLock == (gSineTable[9] & 0xFF)) && (gJoypad[0].input & R_BUTTON)) {
    (&(g->save))->gamemode = 2;
    SET_FLAG((g->save).story.gameflags, FLAG_ULTIMATE);
    unlockAllSecretDisk((g->save).disk);
    unlockAllElvesForUltimate((g->save).elf);
    ClearZeroStatusUltimate(&(g->save).status);
  }
  InitStageRun((g->save).stageID);
  if ((&(g->save))->gamemode == 0) {
    SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
  } else {
    SetGameMode(g, GAMEMODE(MAINGAME, START_SPECIAL_MODE, 0, 0));
  }
}

// 00 01 nn nn
// 0x080EE614
static void GameLoop_ContinueGame(struct GameState* g) {
  (g->save).stageID = STAGE_BASE;
  gGameState.z2 = gGameState.z3 = gPlayers;
  FUN_08019678(&(g->save).story);
  ClearPlayInfo(&(g->save).playinfo);
  clearSecretDiskData((g->save).disk);
  clearUnlockedCyberElfData((g->save).elf);
  ClearZeroStatus(&(g->save).status);
  LoadStageRun((g->save).stageID, 1);
  SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 1, 0x60));
}

static void GameLoop_Nop2(struct GameState* _) {}

static void GameLoop_PreOverworld(struct GameState* g) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
  gPaletteManager.post_process = NULL;
  RemoveAllPaletteAnimations();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  wMOSAIC = 0;
  gPaletteManager.buf[0] = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  RESET_BGOFS(0);
  g->unk_1ed8 = 0xFFFFFFFF;
  g->inMenu = FALSE;
  Renderer_Init(&g->rendererMain);
  ResetCollisionManager();
  ResetEntityEnvironment();
  RNG_0202f388 = (u32)(g->save).stageID;
  s32_0202f334 = -1;
  PTR_0202f384 = &g->unk_1ed8;
  pZero2 = g->z2;
  InitPlayerHeader(&g->entityHeaders[ENTITY_PLAYER], gPlayers, 1);
  InitWeaponHeader(&g->entityHeaders[ENTITY_WEAPON], gWeapons, 24);
  InitBossHeader(&g->entityHeaders[ENTITY_BOSS], gBosses, 5);
  InitEnemyHeader(&g->entityHeaders[ENTITY_ENEMY], gEnemies, 18);
  InitProjectileHeader(&g->entityHeaders[ENTITY_PROJECTILE], gProjectiles, 24);
  InitVFXHeader(&g->entityHeaders[ENTITY_VFX], gVFXs, 64);
  InitSolidHeader(&g->entityHeaders[ENTITY_SOLID], gSolids, 22);
  InitPickupHeader(&g->entityHeaders[ENTITY_ITEM], gPickups, 10);
  InitElfHeader(&g->entityHeaders[ENTITY_ELF], gElfEntities, 16);
  InitElFxManager();
  ResetHUD((u16*)gGameState.bg0);
  ClearTextWindow((u16*)gGameState.bg0);
  LoadZeroStatus(g->z2, &(g->save).status);
  ClearStageRun(&g->rendererMain);
  g->mode[1]++;  // -> OVERWORLD
}

NON_MATCH static void GameLoop_Overworld(struct GameState* g) {
#if MODERN
  bool8 isPaused;
  bool32 escape;

  isPaused = FALSE;
  if ((g->inMenu || (gLifeRecoverAmount != 0)) || gInHitStopFrames) {
    isPaused = TRUE;
  }

  g->unk_1ed8++;
  Renderer_Clear(&g->rendererMain);
  gMatrixCount = 0;
  CpuFastFill(0, gWhitePaintFlags, 32);

  if (FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED) && (!isPaused) && (!gPause)) {
    if (gTimeElfTimer == 0) {
      TurnUpBGM();
      CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
      if (isSoundPlaying(SE_TIME_ELF_HURRY)) {
        StopSound(SE_TIME_ELF_HURRY);
      }
    } else {
      if ((gTimeElfTimer & 0x8000) == 0) {
        if (gTimeElfTimer < 3 * SECOND) {
          if (isSoundPlaying(SE_TIME_ELF)) {
            StopSound(SE_TIME_ELF);
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

  escape = StageRun_Update(isPaused || gPause);
  if (escape) {
    gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
    gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
    SetGameMode(g, GAMEMODE(MAINGAME, GAME_SCENE_END_RUN, 0, 0));
    return;
  }

  if (isPaused) {
    ClearAllHitboxes();
  } else {
    if (((gStageRun.missionStatus & MISSION_STAY) && (!(gStageRun.vm.active & VM_ACTIVE))) && ((gStageRun.missionStatus & STOP_TIME_COUNT) == 0)) {
      if (gScore.clearTime < 359999) gScore.clearTime++;
      if ((gScore.total)->playTime < 21599999) (gScore.total)->playTime++;
    }
    UpdateElFxManager();  // ゼロの属性(エレメント)　によるグラフィックデータ？
    if (!gPause) {
      UpdateHazardEntities(gSolidHeaderPtr);
      UpdateHazardEntities(gBossHeaderPtr);
      UpdateHazardEntities(gEnemyHeaderPtr);
      UpdateEntities(gZeroHeaderPtr);
      UpdateProjectiles();
      UpdateEntities(gWeaponHeaderPtr);
      UpdateEntities(gPickupHeaderPtr);
    }
    UpdateHazardEntities(gElfHeaderPtr);
    UpdateVFXs();
    ClearAllHitboxes();
    if (!gPause) {
      RegisterHitboxes(gSolidHeaderPtr);
      RegisterHitboxes(gBossHeaderPtr);
      RegisterHitboxes(gEnemyHeaderPtr);
      RegisterHitboxes(gZeroHeaderPtr);
      RegisterHitboxes(gProjectileHeaderPtr);
      RegisterHitboxes(gWeaponHeaderPtr);
      RegisterHitboxes(gPickupHeaderPtr);
      RegisterHitboxes(gElfHeaderPtr);
    }
  }
  CheckItemGain(g);
  CheckCollision();
  RunDamageEffect(gSolidHeaderPtr);
  RunDamageEffect(gBossHeaderPtr);
  RunDamageEffect(gEnemyHeaderPtr);
  RunDamageEffect(gZeroHeaderPtr);
  RunDamageEffect(gPickupHeaderPtr);

  {
    Renderer* r = &g->rendererMain;
    DrawCollidableEntity(gSolidHeaderPtr, r);
    DrawCollidableEntity(gBossHeaderPtr, r);
    DrawCollidableEntity(gEnemyHeaderPtr, r);
    DrawCollidableEntity(gZeroHeaderPtr, r);
    DrawEntity(gElfHeaderPtr, r);
    DrawWeapon(r);
    DrawEntity(gProjectileHeaderPtr, r);
    DrawEntity(gVFXHeaderPtr, r);
    DrawCollidableEntity(gPickupHeaderPtr, r);
    DrawHUD(g);
    UpdateTextWindow();
    RunOverworldLoop(g);
  }

  if ((((gJoypad[0].pressed & START_BUTTON) && (*(s32*)g->mode == 0x400)) && ((((g->z2->body).status & BODY_STATUS_DEAD) == 0 && ((g->z2->body).hp != 0)))) && ((((gTextWindow.text.mode == 0 || (gTextWindow.text.mugshot == 0)) && ((gStageRun.missionStatus & DISABLE_MENU) == 0)) && ((((((gStageRun.missionStatus & MISSION_STAY) && (!(gStageRun.vm.active & VM_ACTIVE))) && (gStageRun.vm.transition == TRANSITION_NONE)) && ((gGameState.mode[2] == 0 && (!gPause)))) && ((wMOSAIC == 0 && (gLifeRecoverAmount == 0)))))))) {
    g->inMenu = TRUE;
    SetGameMode(g, GAMEMODE(MAINGAME, OPEN_MENU, 0, 0));
  }

  StageRun_Render(isPaused || gPause);
  if ((!isPaused) && (!gPause)) {
    if ((gIsPlayDamageSE) && ((gCollisionManager.sweep & SWEEP_ALL_ENEMY) == 0)) {
      PlaySound(SE_ZAKO_STUN);
    }
    gIsPlayDamageSE = FALSE;
  }
  gInHitStopFrames = gCollisionManager.hitstop;  // 現在ヒットストップ中かどうかのTRUE/FALSE
#else
  INCCODE("asm/wip/GameLoop_Overworld.inc");
#endif
}

static void GameLoop_OpenMenu(struct GameState* g) {
  if (g->mode[3] == 0) {
    TurnDownBGM();
    g->frames = 32;
    g->mode[3]++;
  }
  g->frames -= 2;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;

  if (g->frames == 0) {
    SaveGraphicState(g);
    gPaletteManager.buf[0] = RGB_BLACK;
    gVideoRegBuffer.dispcnt &= 0xC1FF;
    wMOSAIC = 0;
    PauseAllPaletteAnimations();
    DisableCyberSpaceColorFilter();
    SetGameMode(g, GAMEMODE(MODE_MENU, 0, 0, 0));
  } else {
    void* dst;
    Renderer* r = &(g->rendererMain);
    Renderer_Clear(r);
    ClearAllHitboxes();
    gMatrixCount = 0;
    dst = gWhitePaintFlags;
    _CpuFastFill(0, dst, 32);
    StageRun_Update(TRUE);
    DrawCollidableEntity(gSolidHeaderPtr, r);
    DrawCollidableEntity(gBossHeaderPtr, r);
    DrawCollidableEntity(gEnemyHeaderPtr, r);
    DrawCollidableEntity(gZeroHeaderPtr, r);
    DrawEntity(gElfHeaderPtr, r);
    DrawWeapon(r);
    DrawEntity(gProjectileHeaderPtr, r);
    DrawEntity(gVFXHeaderPtr, r);
    DrawCollidableEntity(gPickupHeaderPtr, r);
    StageRun_Render(TRUE);
    DrawHUD(g);
    UpdateTextWindow();
  }
}

// 0x080EEDF0
static void GameLoop_CloseMenu(struct GameState* g) {
  if (g->mode[3] == 0) {
    u8 color = ((&(g->z2)->unk_b4)->status).body;

    if (FLAG(gCurStory.s.gameflags, IN_CYBERSPACE)) EnableCyberSpaceColorFilter();
    RestoreGraphicState(g);
    ResumeAllPaletteAnimations();
    g->frames = 0;

    if ((&g->save)->gamemode == 1) {
      color = BODY_CHIP_PROTO;
    } else if ((&g->save)->gamemode == 2) {
      color = BODY_CHIP_ULTIMA;
    }

    // z = g->z2;
    if ((g->z2)->posture == POSTURE_SHADOW) {
      LoadZeroPalette(&(g->z2)->s, color);
      LoadShadowDashPalette(g->z2, color);
    } else {
      LoadZeroPalette(&(g->z2)->s, color);
    }

    if (gStageRun.missionStatus & MISSION_ESCAPE) {
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      SetGameMode(g, GAMEMODE(MAINGAME, GAME_SCENE_END_RUN, 0, 0));
      return;
    }
    g->mode[3]++;
  }

  Renderer_Clear(&g->rendererMain);
  ClearAllHitboxes();
  gMatrixCount = 0;
  {
    u32 fillval = 0;
    void* dst = gWhitePaintFlags;
    u32 bytesize = 32;
    _CpuFastFill(fillval, dst, bytesize);
  }
  StageRun_Update(TRUE);
  DrawCollidableEntity(gSolidHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gBossHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gEnemyHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gZeroHeaderPtr, &g->rendererMain);
  DrawEntity(gElfHeaderPtr, &g->rendererMain);
  DrawWeapon(&g->rendererMain);
  DrawEntity(gProjectileHeaderPtr, &g->rendererMain);
  DrawEntity(gVFXHeaderPtr, &g->rendererMain);
  DrawCollidableEntity(gPickupHeaderPtr, &g->rendererMain);
  StageRun_Render(TRUE);
  DrawHUD(g);
  UpdateTextWindow();

  g->frames += 2;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  if (g->frames == 32) {
    g->inMenu = FALSE;
    if (!FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED)) {
      TurnUpBGM();
    } else {
      SetStageNoiseVolume(SE_TIME_ELF);
      SetStageNoiseVolume(SE_TIME_ELF_HURRY);
    }
    SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 0, 0));
  }
}

NAKED static void GameLoop_SwitchCyberSpace(struct GameState* g) { INCCODE("asm/todo/GameLoop_SwitchCyberSpace.inc"); }

/**
 * @brief ランの終了 (ミッションクリア、プレイヤー死亡、エスケープ、フリーランでボスがいた部屋に到着) 後の処理
 * @note 0x080ef400
 */
NON_MATCH static void GameLoop_EndRun(struct GameState* g) {
#if MODERN
  UpdateStoryFlag();
  if (FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    ExitProcess();
    return;
  }

  if (gStageRun.missionStatus & MISSION_PLAYER_DEAD) {
    u32 mode;
    if ((gScore.total)->extraLife == 0) {
      mode = GAMEMODE(MAINGAME, GAMEOVER, 0, 0);
    } else {
      if (gScore.retryCount < 99) gScore.retryCount++;
      (gScore.total)->extraLife--;
      mode = GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0);
    }
    SetGameMode(g, mode);
    return;
  }

  if ((g->save).stageID == STAGE_BASE) {
    if (gStageRun.checkpoint == 12) {
      (g->save).stageID = STAGE_MISSILE_FACTORY;
      InitStageRun(STAGE_MISSILE_FACTORY);
      SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }
    if (gStageRun.checkpoint == 19) {
      (g->save).stageID = STAGE_SUB_ARCADIA;
      InitStageRun(STAGE_SUB_ARCADIA);
      SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }
  }

  if (!IS_MISSION) {
    (g->save).stageID = STAGE_BASE;
    LoadStageRun(STAGE_BASE, 9);
    SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
    return;
  }

  if ((g->save).stageID == STAGE_SPACE_CRAFT) {
    (g->save).stageID = STAGE_BASE;
    LoadStageRun(STAGE_BASE, 3);
    SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
    return;
  }

  if (FLAG(gCurStory.s.gameflags, FLAG_FIRST4_DONE)) {
    if (!FLAG(gCurStory.s.gameflags, FLAG_MISSILE_DONE)) {
      if ((g->save).stageID == STAGE_BASE) {
        (g->save).stageID = STAGE_MISSILE_FACTORY;
        InitStageRun(STAGE_MISSILE_FACTORY);
      } else {
        (g->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 4);
      }
      SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }

    if ((g->save).stageID == STAGE_MISSILE_FACTORY) {
      (g->save).stageID = STAGE_BASE;
      LoadStageRun(STAGE_BASE, 13);
      SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      return;
    }

    if (FLAG(gCurStory.s.gameflags, FLAG_MID3_DONE) && FLAG(gCurStory.s.gameflags, FLAG_AREAX2_DONE)) {
      if ((g->save).stageID == STAGE_AREA_X2) {
        (g->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 15);
        SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
        return;
      }

      if (FLAG(gCurStory.s.gameflags, FLAG_LATER4_DONE)) {
        if (FLAG(gCurStory.s.gameflags, FLAG_SUBARCADIA_DONE)) {
          if ((g->save).stageID == STAGE_SUB_ARCADIA) {
            (g->save).stageID = STAGE_BASE;
            LoadStageRun(STAGE_BASE, 7);
          } else if ((g->save).stageID == STAGE_WEILS_LABO) {
            SetGameMode(g, GAMEMODE(MAINGAME, UNLOCK_MINIGAME, 0, 0));
            return;
          }
          SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
          return;
        }

        if ((g->save).stageID == STAGE_BASE) {
          (g->save).stageID = STAGE_SUB_ARCADIA;
          InitStageRun(STAGE_SUB_ARCADIA);
          return;
        }

        (g->save).stageID = STAGE_BASE;
        LoadStageRun(STAGE_BASE, 16);
        SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
        return;
      }
    }
  }

  (g->save).stageID = STAGE_BASE;
  LoadStageRun(STAGE_BASE, 7);
  SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
#else
  INCCODE("asm/wip/GameLoop_EndRun.inc");
#endif
}

/**
 * @note 0x080ef580
 */
static void GameLoop_GameOver(struct GameState* g) {
  switch (g->mode[2]) {
    case 0: {
      s16 i;
      g->mode[3] = FALSE;
      for (i = 0; i < GAME_SECTOR_NUM; i++) {
        if (ValidateSector(i, sizeof(GameSavedata))) g->mode[3] = TRUE;
      }
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG3_ON | DISPCNT_BG2_ON | DISPCNT_BG0_ON;
      BGCNT16(2) = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(4);
      RESET_BGOFS(2);
      BGCNT16(3) = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(6);
      RESET_BGOFS(3);
      LoadGraphic(&gGraphic_GameOverString, (void*)BG_CHAR_OFFSET(1));
      LoadPalette(&gPalette_GameOverString, 0);
      LoadBgMap(USE_BG2, gBgMapOffsets, BG_GAMEOVER_103, 0, 0);
      LoadBgMap(USE_BG3, gBgMapOffsets, BG_GAMEOVER_KATAKANA, 0, 0);
      LoadAsciiBold();
      FUN_080e981c();
      g->frames = 0;
      g->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      g->frames++;
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
      if (g->frames < FILTER_NONE) {
        break;
      }
      PlayBGM(BGM_GUARDER_ROOM);
      g->unk_006 = 0;
      g->mode[2]++;
      FALLTHROUGH;
    }
    case 2: {
      if (gJoypad[0].field3_0x6 & DPAD_UP) {
        PlaySound(SE_CURSOR);
        g->unk_006 = (g->unk_006 + 2) % 3;
        if ((g->unk_006 == 1) && (g->mode[3] == 0)) g->unk_006--;
      }
      if (gJoypad[0].field3_0x6 & DPAD_DOWN) {
        PlaySound(SE_CURSOR);
        g->unk_006 = (g->unk_006 + 1) % 3;
        if ((g->unk_006 == 1) && (g->mode[3] == 0)) g->unk_006++;
      }
      if (gJoypad[0].field3_0x6 & (A_BUTTON | START_BUTTON)) {
        PlaySound(SE_YES);
        FadeOutBGM(BGM_GUARDER_ROOM);
        g->frames = FILTER_NONE;
        g->mode[2]++;
      }
      break;
    }

    case 3: {
      g->frames--;
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
      if (g->frames != 0) {
        break;
      }
      gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
      g->frames = 96;
      g->mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      g->frames--;
      if (g->frames == -1 || !_isSoundPlaying(BGM_GUARDER_ROOM)) {
        if (g->unk_006 == 0) {
          (gScore.total)->extraLife = 2;
          (gScore.total)->rank = (g->save).savedRank;
          {
            void* src = &(g->save).zeroAsset;
            void* dst = &(g->save).status;
            u32 bytesize = sizeof(struct ZeroAsset);
            MemCopy32(src, dst, bytesize);
          }
          LoadStoryData((g->save).stageID, &(g->save).savedStory);
          StoreStoryData(&(g->save).story);
          {
            void* src = (g->save).savedDisk;
            void* dst = (g->save).disk;
            u32 bytesize = 48;
            MemCopy32(src, dst, bytesize);
          }
          {
            void* src = (g->save).savedElf;
            void* dst = (g->save).elf;
            u32 bytesize = 76;
            MemCopy32(src, dst, bytesize);
          }
          InitStageRun((g->save).stageID);
          SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
        } else if (g->unk_006 == 1) {
          SetGameMode(g, GAMEMODE(MAINGAME, CONTINUE_GAME, 0, 0));
        } else {
          ExitProcess();
        }
      }
      break;
    }
  }
  // sGameOver
  PrintString(STRING((g->unk_006 != 0) ? 521 : 520), 0, 8);   // コンティニュー
  PrintString(STRING((g->unk_006 != 1) ? 523 : 522), 0, 10);  // セーブした場所からやりなおす
  PrintString(STRING((g->unk_006 != 2) ? 525 : 524), 0, 12);  // ゲームをやめる
  if (gProcessManager.masterFrame & 1) {
    BgOfs* bg3ofs = (BgOfs*)gVideoRegBuffer.bgofs[3];
    bg3ofs->x++;
    bg3ofs->y--;
  }
}

static void GameLoop_Nop10(struct GameState* _) {}  // 00 0a -- --

NAKED static void GameLoop_UnlockMinigame(struct GameState* g) { INCCODE("asm/todo/GameLoop_UnlockMinigame.inc"); }
NAKED static void GameLoop_SystemSaveScreen(struct GameState* g) { INCCODE("asm/todo/GameLoop_SystemSaveScreen.inc"); }

/*
  00 0D xx --

  ハードモードかアルティメットモードでゲームを始めた時に通知を鳴らしてゲームを開始させる
*/
static void GameLoop_StartSpecialMode(struct GameState* g) {
  switch (g->mode[2]) {
    case 0: {
      PlaySound(SE_NOTIFICATION);
      g->frames = 7200;
      g->mode[2]++;
      break;
    }
    case 1: {
      g->frames--;
      if ((g->frames == 0) || (!isSoundPlaying(SE_NOTIFICATION))) {
        SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
      }
      break;
    }
  }
}

/**
 * @brief ゲームをデモプレイ用の状態で初期化
 * @note 0x080f033c
 */
static void GameLoop_StartDemoPlay(struct GameState* g) {
  struct ZeroStatus *status, *status2;
  u16 stageID;
  GameSavedata* s = &g->save;

  s->gamemode = 0;
  gGameState.z2 = gGameState.z3 = gPlayers;
  FUN_08019678(&(g->save).story);
  ClearPlayInfo(&(g->save).playinfo);
  clearSecretDiskData((g->save).disk);
  clearUnlockedCyberElfData((g->save).elf);
  status = &(g->save).status;
  ClearZeroStatus(status);
  SET_FLAG(gCurStory.s.gameflags, DEMO_PLAY);
  SET_FLAG((g->save).story.gameflags, DEMO_PLAY);

  (status->keyMap).keys.jump = A_BUTTON;
  (status->keyMap).keys.dash = L_BUTTON;
  (status->keyMap).keys.main = B_BUTTON;
  (status->keyMap).keys.sub = R_BUTTON;

  (g->save).status.keyMap.btnMode = 0;     // Type A
  (g->save).status.keyMap.attackMode = 1;  // Type B
  (g->save).status.keyMap.unk_a = 0;

  status2 = &gGameState.save.status;
  status2->unlockedWeapon |= (1 << WEAPON_ROD);
  status2->unlockedWeapon |= (1 << WEAPON_SHIELD);

  if ((g->save).stageID == STAGE_VOLCANO) {
    status2->weapons[0] = WEAPON_ROD, status2->weapons[1] = WEAPON_SABER;

  } else if ((g->save).stageID == STAGE_OCEAN) {
    status2->weapons[0] = WEAPON_BUSTER, status2->weapons[1] = WEAPON_SABER;

  } else if ((g->save).stageID == STAGE_REPAIR_FACTORY) {
    status2->weapons[0] = WEAPON_SABER, status2->weapons[1] = WEAPON_ROD;

  } else {
    status2->weapons[0] = WEAPON_SHIELD, status2->weapons[1] = WEAPON_SABER;
    status2->body = BODY_CHIP_FLAME;
    status2->element = ELEMENT_FLAME;
  }

  InitStageRun((g->save).stageID);
  SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
}

/**
 * @note 0x080f0464
 */
static void GameLoop_SkieEventScene(struct GameState* g) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
  gPaletteManager.post_process = NULL;
  RemoveAllPaletteAnimations();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  wMOSAIC = 0;
  gPaletteManager.buf[0] = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BGMODE_MASK;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  LoadAsciiBold();
  SetGameMode(g, GAMEMODE(MAINGAME, PRE_OVERWORLD, 0, 0));
}
