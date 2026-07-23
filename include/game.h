#ifndef GUARD_RMZ3_GAME_H
#define GUARD_RMZ3_GAME_H

#include "entity.h"
#include "gba/gba.h"
#include "gfx.h"
#include "menu.h"
#include "minigame.h"
#include "overworld.h"
#include "result.h"
#include "score.h"
#include "story.h"
#include "types.h"

/*
  02036dbc
  これがそのままストーリーのセーブデータになる
*/
typedef struct {
  u16 lap;        // 0x00, 何周目か
  u16 gamemode;   // 0x02, 0:Normal, 1:Hard, 2:Ultimate
  u16 stageID;    // 0x04
  u16 savedRank;  // 0x06, LoadStageRun 時におけるプレイヤーのランク (コンティニュー時に使う)
  u8 unk_08[8];   // 0x08, 16バイトパディング?
  u32 rng;        // 0x10

  struct Story story;       // 0x14, フラグデータ　や 会話の進行度などの ストーリーデータ (gGameState.save.story は addr:0x02036DD0)
  struct Story savedStory;  // 0x68, ラン開始時の .story をここに保存しておく (GameOver　のときに .story にこれを戻す)

  /*
    1byte で シークレットディスク4つ分

    each entry has following bitfields
      bit0: unlocked n+0, bit4: analysised n+0
      bit1: unlocked n+1, bit5: analysised n+1
      bit2: unlocked n+2, bit6: analysised n+2
      bit3: unlocked n+3, bit7: analysised n+3
  */
  u8 ALIGNED(4) disk[45];       // 0xBC
  u8 ALIGNED(4) savedDisk[45];  // 0xEC, LoadStageRun 時における SecretDisk (= 02036e78), コンティニュー時に使う

  u8 ALIGNED(4) elf[CYBERELF_LENGTH];       // 0x11C, bit0: Unlocked, bit1: Used as Fusion, bit2: Equippable as Satelite, bit3: Upgreaded once, bit4: Upgreaded twice
  u8 ALIGNED(4) savedElf[CYBERELF_LENGTH];  // 0x168, LoadStageRun 時における UnlockedCyberElf (= 0x02036ed8), コンティニュー時に使う

  struct TotalScore playinfo;  // 0x1B4, 今までのミッションスコアなど、　プレイヤーの行動によって変化するデータ
  struct ZeroStatus status;    // 0x204, LoadStageRun 時におけるZeroStatus コンティニュー時に使う
  struct ZeroAsset zeroAsset;  // 0x234, LoadStageRun 時におけるZeroAsset コンティニュー時に使う

  u8 unused_240[16];
} GameSavedata;  // 592 bytes
static_assert(sizeof(GameSavedata) == 592);

union SceneGameState {
  u8 raw[256];
  struct MenuState menu;
  struct ResultState result;
  struct MinigameState mg;
};

// 0x02030B60
struct GameState {
  u8 mode[4];                                     // 0x0000 (addr:0x02030B60)
  s16 frames;                                     // 0x0004 (addr:0x02030B64)
  s16 unk_006;                                    // 0x0006 (addr:0x02030B66), GameOver時のカーソル位置 (それ以外の用途は不明)
  s16 unk_008[2];                                 // 0x0008 (addr:0x02030B68)
  bool32 unk_00c;                                 // 0x000C (addr:0x02030B6C)
  u32 bg0[512];                                   // 0x0010 (addr:0x02030B70), BG0(HUD や　テキストウィンドウ) のBGマップバッファ
  struct EntityHeader entityHeaders[10];          // 0x0810 (addr:0x02031370), index は include/constants/entity.h の ENTITY_XXX と対応
  Renderer rendererMain;                          // 0x09A0 (addr:0x02031500), ゲームプレイ中の描画に使う Renderer (ステージ と Entity の両方を描画する)
  Renderer rendererUI;                            // 0x0BAC (addr:0x0203170C), UI画面(スタートメニュー、リザルト画面など)で Widget を描画する用の Renderer
  struct Pivot unk_0db8;                          // 0x0DB8 (addr:0x02031918), rendererUI 用の Pivot
  Coords32 unk_0dc4;                              // 0x0DC4 (addr:0x02031924), UI画面でのWidgetの描画中心, 基本的に PIXEL(120), PIXEL(80) だが、スタートメニューのスライド時などにはWidgetも一緒にスクロールするために変化させたりする
  union SceneGameState sceneState;                // 0x0DCC (addr:0x0203192C), 256 bytes
  struct Solid* sunkinLibCursor;                  // 0x0ECC (addr:0x02031A2C)
  u8 unk_0ed0[8];                                 // 0x0ED0 (addr:0x02031A30)
  u16 menuBgMap1[1024];                           // 0x0ED8 (addr:0x02031A38)
  u16 menuBgMap2[1024];                           // 0x16D8 (addr:0x02032238), menuBgMap1 とくっつけて u16[2048] にした方がいいかも (ExMenuLoop_Init などでまとめて転送されるので)
  u32 unk_1ed8;                                   // 0x1ED8 (addr:0x02032A38)
  bool16 inMenu;                                  // 0x1EDC (addr:0x02032A3C)
  u16 unk_1ede;                                   // 0x1EDE (addr:0x02032A3E)
  struct WramBlendRegister savedBlendRegister;    // 0x1EE0 (addr:0x02032A40)
  struct WramWindowRegister savedWindowRegister;  // 0x1EE8 (addr:0x02032A48)
  u8 unk_1ef8[352];                               // 0x1EF8 (addr:0x02032A58)
  u8 savedObjVRAM[16 * 1024];                     // 0x2058 (addr:0x02032BB8)
  rgb555 savedObjPal[256];                        // 0x6058 (addr:0x02036BB8)
  u32 savedColor0;                                // 0x6258 (addr:0x02036DB8), SaveGraphicState でここに 色番号0(透明色)が退避される
  GameSavedata save;                              // 0x625C (addr:0x02036DBC)
  struct Zero* z2;                                // 0x64AC (addr:0x0203700C)
  struct Zero* z3;                                // 0x64B0 (addr:0x02037010)
};
static_assert(sizeof(struct GameState) == 25780);

extern struct GameState gGameState;
extern u8 gUnkSineTableIdx;
extern u16 gCyberSpaceColorHashtable[96];
extern u32* PTR_0202f384;
extern GameSavedata SaveState_020003a8;

void SetGameMode(struct GameState* p, u32 mode);

struct Pickup;
struct CyberElf;

void InitBossHeader(struct EntityHeader* h, struct Boss* p, s16 len);
void InitWeaponHeader(struct EntityHeader* h, Weapon* w, s16 len);
void InitEnemyHeader(struct EntityHeader* h, struct Enemy* p, s16 len);
void InitProjectileHeader(struct EntityHeader* h, Projectile* p, s16 len);
void InitVFXHeader(struct EntityHeader* h, struct VFX* p, s16 len);
void InitSolidHeader(struct EntityHeader* h, struct Solid* p, s16 len);
void InitPickupHeader(struct EntityHeader* h, struct Pickup* p, s16 len);
void InitElfHeader(struct EntityHeader* h, struct CyberElf* p, s16 len);
void InitWidgetHeader(struct EntityHeader* h, struct Widget* p, s16 len);

void UpdateVFXs(void);
void UpdateProjectiles(void);

void RunOverworldLoop(struct GameState* g);
void OverworldLoop_ManageSaveData(struct GameState* g);
void OverworldLoop_CmdRoomTalk(struct GameState* g);
u16 handleWrapTwoChoice(struct GameState* g);

void DrawHUD(struct GameState* _);
void CheckItemGain(struct GameState* p);

typedef void (*GameLoopFunc)(struct GameState*);

#endif  // GUARD_RMZ3_GAME_H
