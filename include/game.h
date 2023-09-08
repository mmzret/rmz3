#ifndef GUARD_RMZ3_GAME_H
#define GUARD_RMZ3_GAME_H

#include "entity.h"
#include "gba/gba.h"
#include "gfx.h"
#include "menu.h"
#include "minigame.h"
#include "overworld.h"
#include "result.h"
#include "story.h"
#include "types.h"

/*
  02036dbc
  これがそのままストーリーのセーブデータになる
*/
struct SaveSlot {
  u16 lap;       // 何周目か
  u16 gamemode;  // 0:Normal, 1:Hard, 2:Ultimate
  u16 stageID;

  /*
    loadMap時におけるプレイヤーのランク
    コンティニュー時に使う
  */
  u16 savedRank;
  u8 unk_010[8];
  u32 rng;

  struct Story story;
  struct Story savedStory;  // 080196b8でここにコピーされる

  /*
    1byte で シークレットディスク4つ分

    each entry has following bitfields
      bit0: unlocked n+0, bit4: analysised n+0
      bit1: unlocked n+1, bit5: analysised n+1
      bit2: unlocked n+2, bit6: analysised n+2
      bit3: unlocked n+3, bit7: analysised n+3
  */
  u8 ALIGNED(4) disk[45];
  u8 ALIGNED(4) savedDisk[45];  // loadMap時における SecretDisk (= 02036e78), コンティニュー時に使う

  /*
    bit0: Unlocked
    bit1: Used as Fusion
    bit2: Equippable as Satelite
    bit3: Upgreaded once
    bit4: Upgreaded twice
  */
  u8 ALIGNED(4) elf[CYBERELF_LENGTH];
  u8 ALIGNED(4) savedElf[CYBERELF_LENGTH];  // loadMap時における UnlockedCyberElf (= 0x02036ed8), コンティニュー時に使う

  struct PlayInfo playinfo;
  struct ZeroStatus status;    // loadMap時におけるZeroStatus コンティニュー時に使う
  struct ZeroAsset zeroAsset;  // loadMap時におけるZeroAsset コンティニュー時に使う

  u8 unused_240[16];
};  // 592 bytes

// 02030b60
struct GameState {
  u8 mode[4];
  s16 frames;
  s16 unk_006;
  s16 unk_008[2];
  bool32 unk_00c;

  /*
    0x02001fd0 以降の内容がコピーされる場合もある
    ここを変えると画面の対応するタイルが変わる
  */
  u32 bg0[512];

  struct EntityHeader entityHeaders[10];
  struct TaskManager taskManager;   // 02031500
  struct TaskManager taskManager2;  // 0203170c
  struct Pivot unk_0db8;            // 02031918, メニュー画面、リザルト画面のスプライトの位置を管理する

  /*
    02031924
    これをいじると
    - リザルト画面のスプライト(シークレットディスク)の座標が変わる
    - メニュー画面のスプライトの位置がずれる

    例: Coord.y を 0x2000 -> 0x1000 にすると スプライト全部が16pxだけ上にずれた
  */
  struct Coord unk_0dc4;

  union {
    struct MenuState menu;
    struct ResultState result;
    struct MinigameState minigame;
  } sceneState;  // 0203192c, 256 bytes

  // 02031a2c
  struct Solid* sunkinLibCursor;
  u8 unk_0ed0[8];
  u16 unk_0ed8[1024];
  u16 unk_16d8[1024];
  u32 unk_1ed8;
  bool16 inMenu;
  u16 unk_1ede;

  // Copy from 02002180..02002187 by 080ee378
  struct WramBlendRegister savedBlendRegister;
  struct WramWindowRegister savedWindowRegister;  // 02032a48
  u8 unk_1ef8[352];
  u8 savedObjVRAM[16 * 1024];
  struct PlttData savedObjPal[256];  // 02036bb8, 03002cc0 から 512バイトコピー
  u32 savedColor0;                   // SaveGraphicState でここに 色番号0(透明色)が退避される

  struct SaveSlot save;
  struct Zero* z2;  // 0x02037c60 を指す CopyZeroStatus 関数(08032274)で ZeroDetailState (02036fc0) にコピーされる
  struct Zero* z3;
  u8 _[12];
};

extern struct GameState gGameState;
extern u8 gUnkSineTableIdx;
extern u16 CopyFrom_08386130[32];
extern void* PTR_0202f384;
extern struct SaveSlot SaveState_020003a8;

void SetGameMode(struct GameState* p, u32 mode);

void InitBossHeader(struct EntityHeader* h, struct Boss* p, s16 len);
void InitWeaponHeader(struct EntityHeader* h, struct Weapon* w, s16 len);
void InitEnemyHeader(struct EntityHeader* h, struct Enemy* p, s16 len);
void InitProjectileHeader(struct EntityHeader* h, struct Projectile* p, s16 len);
void InitVFXHeader(struct EntityHeader* h, struct VFX* p, s16 len);
void InitSolidHeader(struct EntityHeader* h, struct Solid* p, s16 len);
void InitMapItemHeader(struct EntityHeader* h, struct MapItem* p, s16 len);
void InitElfHeader(struct EntityHeader* h, struct Elf* p, s16 len);

void UpdateVFXs(void);
void UpdateProjectiles(void);

void MainLoop_Game(struct GameState* p);
void MainLoop_Disk(struct GameState* p);
void MainLoop_Minigame(struct GameState* p);

void RunOverworldLoop(struct GameState* g);
void OverworldLoop_ManageSaveData(struct GameState* g);
void OverworldLoop_CmdRoomTalk(struct GameState* g);
u16 handleWrapTwoChoice(struct GameState* g);

void DrawHUD(struct GameState* _);
void CheckItemGain(struct GameState* p);

typedef void (*GameLoopFunc)(struct GameState*);

#endif  // GUARD_RMZ3_GAME_H
