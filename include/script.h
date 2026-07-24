#ifndef GUARD_RMZ3_STAGE_SCRIPT_H
#define GUARD_RMZ3_STAGE_SCRIPT_H

#include "camera.h"
#include "common.h"
#include "gba/types.h"

#define SCRIPT_ENTITY_COUNT 12

// vm.transition
#define TRANSITION_NONE 0
#define TRANSITION_REVERSE (1 << 0)   // ReverseWipe = このフラグが立っている時は、画面が見えない状態から通常状態へのトランジションになる
#define TRANSITION_BLACKOUT (1 << 1)  // 画面が徐々に暗くなっていくトランジション (TRANSITION_REVERSE セット時は真っ黒から徐々に見える状態へのトランジションになる)
#define TRANSITION_WHITEOUT (1 << 2)  // 画面が徐々に白くなっていくトランジション (TRANSITION_REVERSE セット時は真っ白から徐々に見える状態へのトランジションになる)
#define TRANSITION_Z (1 << 3)         // wipe by Z (Zマークを作りながらの暗転, TRANSITION_REVERSEセット時は真っ黒な画面からZマークを作りながら通常の画面に戻るトランジションになる)

// vm.emergency
#define EMERGENCY_END (1 << 14)      // このフラグが立っている時は、次に赤の強さが0になるタイミングで緊急事態エフェクトを終了する
#define EMERGENCY_ENABLED (1 << 15)  // 緊急事態エフェクト が有効かどうか

// vm.active
#define VM_ACTIVE (1 << 0)  // 現在実行しているスクリプトがあることを示すフラグ, = SetScript で セットされ、 RunScript でコマンドが終端まで実行されるとクリアされるフラグ
#define VM_FLAG1 (1 << 1)

struct Entity;
struct VFX;

/**
 * @brief asm/scripts で使っているコマンド
 * @note 基本的に コマンド はこの GameCommand のことを指し、　スクリプト (または ゲームスクリプト) は GameCommand の配列(コマンド列) のことを指す
 * @sa gScriptCommands
 */
typedef union {
  struct GameCommandCommon {
    u8 op;      // 0x0, コマンドID (e.g. spawn => 11)
    u8 status;  // 0x1
    s16 val2;   // 0x2
    u32 work;   // 0x4, コマンドハンドラ用の汎用データ コマンドによって用途が異なる
  } c;

  struct {       // Cmd_spawn
    u8 op;       // 0x0, 11
    u8 slot;     // 0x1, gStageRun.vm.entities の idx
    s16 val2;    // 0x2, ???
    void* tmpl;  // 0x4, ScriptEntityTemplate*
  } spawn;
  struct {     // Cmd_flag
    u8 op;     // 0x0, 13
    u8 slot;   // 0x1, gStageRun.vm.entities の idx
    s16 val;   // 0x2
    u32 mode;  // 0x4
  } flag;
  struct {       // Cmd_emergency
    u8 op;       // 0x0, 16
    u8 op2;      // 0x1, 0: emergency_on, 1: emergency_off
    s16 _;       // 0x2, 不使用
    u32 offset;  // 0x4, emergency_on で 赤フェードの強さの初期値を指定するためのものだが、ゲーム中では0以外が渡されることはない
  } emergency;
  struct {     // Cmd_emotion
    u8 op;     // 0x0, 18
    u8 slot;   // どのScriptEntityに対して出すか
    s16 px;    // 吹き出しを出すX座標, = idxで指定した ScriptEntityの(左上?の)座標からのピクセル単位のオフセット
    u16 kind;  // 吹き出しの種類
    s16 py;    // 吹き出しを出すY座標 = idxで指定した ScriptEntityの(左上?の)座標からのピクセル単位のオフセット
  } emotion;
} GameCommand;  // 8 bytes
static_assert(sizeof(GameCommand) == 8);

// spawn　コマンド によって (ハンドラ Cmd_spawn) 生成された Entity を管理する構造体
struct ScriptEntity {
  struct Entity* entity;
  struct Entity* unk_04;
  u8 unk_08;
  u8 flags;  // Actorによって各bitの意味が異なる
  u16 unk_0A[3];
};
static_assert(sizeof(struct ScriptEntity) == 16);

// フィールドスクリプト実行VM
struct VM {
  u8 unk_000;
  u8 unk_001;
  u8 active;  // bit0: ?,, bit1: cmd08 で フラグでフラグのセット or クリア を待機できる, bit2..7: bit1と同じだが不使用
  u8 eventID;
  u16 unk_004;
  u16 unk_006;
  GameCommand* start;  // コマンド列の開始地点
  GameCommand* pc;     // コマンド列の現在地点
  struct ScriptEntity entities[SCRIPT_ENTITY_COUNT];
  u32 time;              // Frame count from ClearVM
  u32 wait;              // waitコマンドで設定する待機時間
  struct Camera camera;  // 0xD8
  u32 transition;        // bit0..15: transition flags, bit16..31: transition parameter
  KEY_INPUT forcedKey;
  u16 unk_14a;
  u16 emergency;  // 緊急事態に画面が赤くなるエフェクト (bit0..7: intensity, bit8..13: unused?, bit14: temporary, bit15: enabled)
  u16 magnitude;  // 0xFFにするほど揺れが強い
  union {
    u32 raw;
    s16 n;  // strings.s
    u8 x;
    u8 y;
  } string;                  // ((string_id << 16) | (y << 8) | x)
  struct Entity* indicator;  // ステージへオペレータに転送されたとき(もしくはミッション開始時に)右下に出てくる "Z x 9" や `MISSION START`などのオーバーレイ
  SoundID32 bgm;
  TextID zeroDeathTextIDs[2];  // ゼロがボス戦で死んだ時にボスが喋るメッセージのテキストID配列
  Coords32 forceCoord;         // 0xFFFFFFFF以外に設定するとそこにゼロが瞬間移動 & 座標固定される(侵入可能エリアなら死)
};  // 360 bytes
static_assert(sizeof(struct VM) == 360);

// ------------------------------------------------------------------------------------------------------------------------------------

typedef bool32 (*CommandHandler)(struct VM*);

extern const CommandHandler gScriptCommands[38];

void SetScript(struct VM* vm, const GameCommand* script);
bool32 RunVM(struct VM* vm);
void ClearVM(struct VM* vm, u32 stageID);
void FUN_08021cb4(struct VM* vm, const GameCommand* script, struct Entity* e);
void DeleteScriptEntity(u8 n);

#endif  // GUARD_RMZ3_STAGE_SCRIPT_H
