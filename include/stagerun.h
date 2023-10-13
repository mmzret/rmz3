#ifndef GUARD_RMZ3_STAGE_RUN_H
#define GUARD_RMZ3_STAGE_RUN_H

#include "camera.h"
#include "common.h"
#include "entity.h"
#include "game.h"
#include "gba/types.h"
#include "script.h"
#include "task.h"

// StageRun.missionStatus
#define MISSION_STAY (1 << 0)
#define STOP_TIME_COUNT (1 << 2)
#define MISSION_FAIL (1 << 3)
#define MISSION_SUCCESS (1 << 4)
#define MISSION_B5 (1 << 5)
#define DISABLE_MENU (1 << 6)
#define EVENT_SCENE (1 << 7)

struct StageRun {
  u16 id;         // Stage ID
  u8 checkpoint;  // リトライ時の再開地点
  u8 checkpointBuffer;
  KEY_INPUT input;  // 現在の入力 gJoypad->inputをコピー
  KEY_INPUT unk_06;

  /*
      bit0: これを0にするとベースに帰還する
      bit2: クリアタイムとプレイ時間のカウントが止まる 参照: 080ee868
      bit3: FAIL(?)
      bit4: SUCCESS(?)
      bit6: メニュー禁止(オメガにとどめ刺すとき？)
      bit7: イベントシーン中？
  */
  u16 missionStatus;
  u16 unk_0a;
  u32 frame;  // チェックポイントに降り立ってからステージ内で経過したフレーム、リトライするとリセット
  struct VM vm;
  struct TaskManager* taskManager;
  u8 stageEventPhase;
  u8 unk_17d;

  /*
    水没した図書館でゲットしたデータを表すフラグ
      bit0: Weil
      bit1: Omega
      bit2: Dark elf
      bit3: Elf war
  */
  u16 searchDataFlags;

  /*
    水没した図書館:  直近にゲットしたデータのidx(0,1,2,3)
    巨大エレベーター: エレベーターで倒した雑魚敵の数?
  */
  u32 searchDataIdx;
  u32 remainingTimeFrame;  // 30秒間耐え切るイベントとかの残り時間
  u32 unk_188;
  u32 unk_18c;
  u32 volteelRNG;
};

// 0x0203dc50
struct StageDiskManager {
  u8* disk;             // -> 0x02036e78
  u8 stageDiskIDs[10];  // ステージ中で取得したシークレットディスクのIDの配列, フリーランしたときに今まで取ったディスクのIDがなかったのでステージランごとの記録
  u8 stageDiskCount;    // ステージ中で取得したシークレットディスクの枚数
  u8 _;
};  // 16 bytes

extern struct StageRun gStageRun;
extern struct StageDiskManager gStageDiskManager;
extern const struct Command** gStageScriptList[STAGE_COUNT];

typedef s16 (*StageRunFunc)(struct StageRun*);  // s16 を返す根拠は 0x0801bac8

void InitStageRun(u8 stageID);
void LoadStageRun(u8 stageID, u8 checkPoint);
void ClearStageRun(struct TaskManager* tm);
bool32 OverworldUpdate(bool8 paused);
void CameraUpdate(bool8 paused);
void UpdateStoryFlag(void);
void setStageCheckpoint(u8 cp);
void setStageCheckpoint2(u8 cp);
void ApplyGiantElf(struct StageRun* p);
u32 CalcFromCamera(struct Camera* p, struct Coord* c);
void SetCameraMode(struct Camera* p, u32 mode);
void LoadCameraTemplate(struct Camera* p, const struct CameraTemplate* t);

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
