#ifndef GUARD_RMZ3_STAGE_RUN_H
#define GUARD_RMZ3_STAGE_RUN_H

#include "camera.h"
#include "common.h"
#include "entity.h"
#include "game.h"
#include "gba/types.h"
#include "script.h"

struct Renderer;

#define IS_DISK_UNLOCKED(flagbits, disk_id) ((flagbits[disk_id >> 2] & 0x0F) >> (disk_id & 3))

#define UNLOCK_DISK(flagbits, disk_id)                    \
  {                                                       \
    (flagbits)[(disk_id) >> 2] |= (1 << ((disk_id) & 3)); \
  }

// StageRun.missionStatus
#define MISSION_STAY (1 << 0)         // ランが有効な間にセットされるフラグ (このbitをクリアすると GameLoop_EndRun が実行され、ランが終了する)
#define MISSION_B1 (1 << 1)           // ???
#define STOP_TIME_COUNT (1 << 2)      // クリアタイムとプレイ時間のカウントが止まる 参照: 080ee868
#define MISSION_PLAYER_DEAD (1 << 3)  // プレイヤー(ゼロ)が死ぬと MISSION_STAY のクリアと共に　セットされるフラグ
#define MISSION_SUCCESS (1 << 4)      // ミッションをクリア(というかボスが死ぬ) と MISSION_STAY のクリアと共に　セットされるフラグ
#define MISSION_ESCAPE (1 << 5)       // メニュー画面でエスケープを決定すると MISSION_STAY のクリアと共に セットされるフラグ
#define DISABLE_MENU (1 << 6)         // メニュー禁止(オメガにとどめ刺すとき？)
#define SKIPPABLE_CUTSCENE (1 << 7)   // すでに見たことのある(STARTボタンでスキップ可能な)イベントシーンの間にセットされる

// ステージの地形情報とは関係ない、ミッションで立つフラグやチェックポイントなど、プレイヤーロジック的なデータを管理する構造体　なんだけど　良い名前が思いつかない
struct StageRun {
  u16 id;                     // 0x00, Stage ID, initResistanceBase (0x080160BC) のように　レジスタンスベースにいるけど、 .id は STAGE_WEILS_LABO ということもある
  u8 checkpoint;              // 0x02, リトライ時の再開地点
  u8 checkpointResultScreen;  // 0x03
  KEY_INPUT input;            // 0x04, 現在の入力 gJoypad->inputをコピー
  KEY_INPUT unk_06;           // 0x06
  u16 missionStatus;          // 0x08, 上のマクロ参照
  u16 unk_0a;                 // 0x0A
  u32 frame;                  // 0x0C, チェックポイントに降り立ってからステージ内で経過したフレーム、リトライするとリセット
  struct VM vm;               // 0x10
  struct Renderer* renderer;  // 0x178, 常に &gGameState.rendererMain
  u8 stageEventPhase;         // 0x17C
  u8 unk_17d;                 // 0x17D
  // ここからはステージによる？
  u16 searchDataFlags;     // 0x17E, 水没した図書館でゲットしたデータを表すフラグ, bit0: Weil, bit1: Omega, bit2: Dark elf, bit3: Elf war
  u32 searchDataIdx;       // 0x180, 水没した図書館: 直近にゲットしたデータのidx(0,1,2,3), 巨大エレベーター: エレベーターで倒した雑魚敵の数?
  u32 remainingTimeFrame;  // 0x184, 30秒間耐え切るイベントとかの残り時間
  u32 unk_188;             // 0x188
  u32 unk_18c;             // 0x18C
  u32 volteelRNG;          // 0x190, 0x0801f7ea で gStageRun からのオフセットでアクセスしているので StageRun 構造体のメンバっぽい
};
static_assert(sizeof(struct StageRun) == 404);

// 0x0203dc50
struct StageDiskManager {
  u8* disk;             // = GameSavedata.disk (addr: 0x02036e78)
  u8 stageDiskIDs[10];  // ステージ中で取得したシークレットディスクのIDの配列, フリーランしたときに今まで取ったディスクのIDがなかったのでステージランごとの記録
  u8 stageDiskCount;    // ステージ中で取得したシークレットディスクの枚数
  u8 _;
};  // 16 bytes
static_assert(sizeof(struct StageDiskManager) == 16);

extern struct StageRun gStageRun;
extern struct StageDiskManager gStageDiskManager;
extern const GameCommand** gStageScriptList[STAGE_COUNT];

typedef s16 (*StageRunFunc)(struct StageRun*);  // s16 を返す根拠は 0x0801bac8

void InitStageRun(u8 stageID);
void LoadStageRun(u8 stageID, u8 checkPoint);
void ClearStageRun(struct Renderer* r);
bool32 StageRun_Update(bool8 paused);
void StageRun_Render(bool8 paused);
void UpdateStoryFlag(void);
void setStageCheckpoint(u8 cp);
void setStageCheckpoint2(u8 cp);
void ApplyGiantElf(struct StageRun* p);

// --------------------------------------------

s16 Stage0_MissionUpdate(struct StageRun* p);
s16 SpaceCraft_MissionUpdate(struct StageRun* p);
s16 Volcano_MissionUpdate(struct StageRun* p);
s16 Ocean_MissionUpdate(struct StageRun* p);
s16 RepairFactory_MissionUpdate(struct StageRun* p);
s16 OldResidential_MissionUpdate(struct StageRun* p);
s16 MissileFactory_MissionUpdate(struct StageRun* p);
s16 TwilightDesert_MissionUpdate(struct StageRun* p);
s16 AnatreForest_MissionUpdate(struct StageRun* p);
s16 IceBase_MissionUpdate(struct StageRun* p);
s16 AreaX2_MissionUpdate(struct StageRun* p);
s16 EnergyFacility_MissionUpdate(struct StageRun* p);
s16 SnowyPlains_MissionUpdate(struct StageRun* p);
s16 SunkenLib_MissionUpdate(struct StageRun* p);
s16 GiantElevator_MissionUpdate(struct StageRun* p);
s16 SubArcadia_MissionUpdate(struct StageRun* p);
s16 WeilLabo_MissionUpdate(struct StageRun* p);
s16 ResistanceBase_Update(struct StageRun* p);

// --------------------------------------------

s16 SpaceCraft_FreeUpdate(struct StageRun* p);
s16 Volcano_FreeUpdate(struct StageRun* p);
s16 Ocean_FreeUpdate(struct StageRun* p);
s16 RepairFactory_FreeUpdate(struct StageRun* p);
s16 OldResidential_FreeUpdate(struct StageRun* p);
s16 MissileFactory_FreeUpdate(struct StageRun* p);
s16 TwilightDesert_FreeUpdate(struct StageRun* p);
s16 AnatreForest_FreeUpdate(struct StageRun* p);
s16 IceBase_FreeUpdate(struct StageRun* p);
s16 AreaX2_FreeUpdate(struct StageRun* p);
s16 EnergyFacility_FreeUpdate(struct StageRun* p);
s16 SnowyPlains_FreeUpdate(struct StageRun* p);
s16 SunkenLib_FreeUpdate(struct StageRun* p);
s16 GiantElevator_FreeUpdate(struct StageRun* p);
s16 SubArcadia_FreeUpdate(struct StageRun* p);

#endif  // GUARD_RMZ3_STAGE_RUN_H
