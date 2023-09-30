#ifndef GUARD_RMZ3_STAGE_SCRIPT_H
#define GUARD_RMZ3_STAGE_SCRIPT_H

#include "camera.h"
#include "common.h"
#include "entity.h"
#include "gba/types.h"

#define SCRIPT_ENTITY_COUNT 12

// vm.screenEffect
enum ScreenEffect {
  NO_SCREEN_EFFECT,
  SCREEN_EFFECT_01,
  BLACKOUT,
};

/**
 * @brief Script Command
 * @see gScriptCommands
 */
struct Command {
  u8 cmd;  // コマンドID
  u8 status;
  s16 val2;
  u32 work;  // コマンドハンドラ用の汎用データ コマンドによって用途が異なる
};           // 8 bytes

struct Command0D {
  u8 cmd;  // コマンドID
  u8 entityIdx;
  union {
    s16 idx;
    u8 mask;
    u8 pad;
  } PACKED val;
  u32 flags;
};

// For emotion layout
struct Command12 {
  u8 cmd;  // コマンドID
  u8 idx;
  s16 x;
  u16 kind;
  s16 y;
};

struct ScriptEntity {
  struct Entity* entity;
  struct Entity* unk_04;
  u8 unk_08;
  u8 unk_09;
  u16 unk_0A[3];
};

union ScriptString {
  u32 raw;
  s16 n;
  u8 x;
  u8 y;
};

// フィールドスクリプト実行VM
struct VM {
  u8 unk_000;
  u8 unk_001;
  bool8 active;
  u8 unk_003;
  u16 unk_004;
  u16 unk_006;
  struct Command* start;  // コマンド列の開始地点
  struct Command* pc;     // コマンド列の現在地点
  struct ScriptEntity entities[SCRIPT_ENTITY_COUNT];
  u32 time;  // Frame count from ClearVM
  u32 wait;  // waitコマンドで設定する待機時間
  struct Camera camera;
  u32 screenEffect;
  KEY_INPUT forcedKey;
  u16 unk_14a;

  /*
    緊急事態に画面が赤くなるエフェクトを設定するフラグ
    画面エフェクトのみでアラートのような音はならない 08022bb4 によってセットされる
    0202ffbd が
      0x40: 0202ffbcがFFになったら画面が赤くなるの解除
      0x80: ずっと赤いまま
  */
  u16 emergency;
  u16 magnitude;  // 0xFFにするほど揺れが強い
  union ScriptString rune;
  struct VFX* indicator;  // ステージへオペレータに転送されたとき(もしくはミッション開始時に)右下に出てくる "Z x 9" や `MISSION START`などのオーバーレイ
  SoundID32 bgm;
  TextID zeroDeathTextIDs[2];  // ゼロがボス戦で死んだ時にボスが喋るメッセージのテキストID配列
  struct Coord forceCoord;     // 0xFFFFFFFF以外に設定するとそこにゼロが瞬間移動 & 座標固定される(侵入可能エリアなら死)
};                             // 360 bytes

struct ScriptEntityTemplate {
  u8 kind;
  u8 variant;
  u8 unk_02;
  u8 unk_03;
  struct Coord coord;
  s8 xflip;
  s8 yflip;
};

// ------------------------------------------------------------------------------------------------------------------------------------

typedef bool32 (*CommandHandler)(struct VM*);

extern const CommandHandler gScriptCommands[38];
extern const struct Command Script_MissionFail[];
extern const struct Command Script_MissionFail2[];

extern const TextID CielGoodluckTextIDs[];

void FUN_08021ca0(struct VM* vm);
void SetScript(struct VM* vm, const struct Command* script);
void CreateScriptEntity(u8 t, struct ScriptEntityTemplate* arg);
bool32 RunVM(struct VM* vm);
void ClearVM(struct VM* vm, u32 stageID);
void FUN_08021b88(struct VM* _);
void FUN_08021cb4(struct VM* vm, const struct Command* script, struct Entity* e);
void DeleteScriptEntity(u8 n);

#endif  // GUARD_RMZ3_STAGE_SCRIPT_H
