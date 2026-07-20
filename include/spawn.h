#ifndef GUARD_RMZ3_SPAWN_H
#define GUARD_RMZ3_SPAWN_H

#include "common.h"
#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

struct Entity;

// SF は SpawnFlag の略 (名前変えるかも)
// SpawnTemplate.flag, SpawnedEntity.flag
#define SF_RESPAWN (1 << 0)  // 削除時にスポーン可能フラグを再び立てるフラグ
#define SF_FLAG_1 (1 << 1)   // ???
// カリング(画面外に出たEntityの削除)をしないフラグ, セーメラン, レミングルスの巣, 改造カードで出現するカモメ　に使用されている
// レミングルスの巣 の場合、 巣だけがカリングされて、出てきたレミングルスがカリングされないようにプレイヤーが動くと無限にレミングルスが生成されるので、それを防ぐ (あと単純に画面切り替えだけでレミングルスが湧くと流石にうざいと思った？)
// セーメラン の場合は、 Seimeran_Update で自前のカリング処理を行っている (カリング範囲の問題?)
// カモメ はなぜフラグ立ててるのか不明
#define SF_NO_CULLING (1 << 2)
#define SF_FLAG_3 (1 << 3)  // ??? (このフラグが立っている SpawnTemplate.flag はない)
#define SF_ZOMBIE (1 << 4)  // 不要なEntity (つまり カリング対象になった か mode[0]>=ENTITY_DIE) の場合に立てるフラグ(SpawnedEntity.flag で動的に立てるもの)

// SpawnTemplate.attr (SA_ = Spawn Attr)
#define SA_KNIGHT (1 << 0)      // キーナイト系(雑魚敵消去エルフ)の対象か
#define SA_STORY_ONLY (1 << 1)  // フリーラン時には生成しない(=ストーリー専用)

// SpawnTemplate.virusID
enum VirusID {
  VIRUS_NONE = 0,
  VIRUS_BEETANK = (ENEMY_BEETANK - 29),  // = 1, カブタンク
  VIRUS_SWORDY = (ENEMY_SWORDY - 29),    // = 2, スウォーディン
  VIRUS_PUFFY = (ENEMY_PUFFY - 29),      // = 3, プクール
};

typedef u8 (*AreaChecker)(Coords32*);

// SpawnTemplate.kind, SpawnTemplate.id, SpawnTemplate.work0, SpawnTemplate.work1 を .kind[4] にまとめるべきだと思うが、 まだ UpdateSpawnManager のdecompができていないため、レイアウトが確定していない
// ただ、スポーンテーブルで 1行で記述したいので一旦このマクロでお茶をを濁す
#define SpawnEntity(ekind, eid, ework0, ework1) ekind, .id = eid, .work0 = ework0, .work1 = ework1

#define SpawnPixelCoords(pixel_x, pixel_y) ((pixel_x) / 16), ((pixel_y) / 16)

/*
  マップ上のEntityの設計図
  ただし、どこに生成するかという座標の情報は別(同じEntityをいろんな座標に生成したいというモチベがあるため)
*/
struct SpawnTemplate {
  u8 flag;  // 0x00, SpawnedEntity.flag にコピーされる制御フラグ
  // u8 kind[4]; にしたい
  u8 kind;  // 0x01, Entity.kind
  u8 id;
  u8 work0;      // 0x03, Entity.work[0]
  u8 work1;      // 0x04, Entity.work[1]
  u8 attr;       // 0x05, bit0: キーナイト系(雑魚敵消去エルフ)の対象か, bit1: フリーラン時には生成しない(=ストーリー専用), bit2..7: 不使用
  u8 mettaurID;  // 0x06, メットールに置き換える際に、どのタイプのメットールにするかを表すID (0 なら置き換え対象ではない)
  u8 virusID;    // 0x07, MMBN4のウィルスに置き換える対象かを示す (0 なら置き換え対象ではない)
};  // 8 bytes
static_assert(sizeof(struct SpawnTemplate) == 8);

/*
  SpawnTemplate をどこに生成するかを表す
  SpawnPoint を 配列にする際は、X座標で昇順(小->大)に並ぶ
*/
struct SpawnPoint {
  s32 x;    // .x * PIXEL(16) が実際の座標になる
  s16 y;    // .y * PIXEL(16) が実際の座標になる
  u16 idx;  // SpawnManager.template のインデックス, この SpawnPoint からスポーンする Entity を指定する
};  // 8 bytes
static_assert(sizeof(struct SpawnPoint) == 8);

// Entityのグラフィックデータ (現在のエリアに対応する .areas のビットが立っているときだけロードする)
struct PreloadEntity {
  motion_id_t id;    // gDynamicMotionCmdTable または gStaticMotionCmdTable の idx (Dynamic: 0..162, Static: 0..252)
  u8 areas;          // どのエリアで有効かを示すbitfield
  u16 tileBase;      // タイルデータの読み込み先
  u8 palID;          // パレットの読み込み先
  u8 unk_05;         // bit0: ??, bit1: メットール化適用中にもグラフィックデータのロードが必要か(つまりメットールになるやつは0?), bit2..7: 不使用
  u8 unk_06;         // bit0: ??, bit1: ??, bit2..7: 不使用
  bool8 cyberColor;  // サイバー空間にいるときに、緑色にするパレットエフェクト(PostProcess_CyberSpaceColorFilter)の対象かを表すフラグ
};  // 8 bytes
static_assert(sizeof(struct PreloadEntity) == 8);

// Entity + スポーン情報
struct SpawnedEntity {
  struct SpawnedEntity* next;  // 0x00, リンクリストの次の要素(先頭は SpawnManager.list)
  struct Entity* e;
  s16 sid;  // この SpawnedEntity が どの SpawnPoint からスポーンしたかを表す (SpawnManager.points の index)
  u16 flag;
};  // 12 bytes
static_assert(sizeof(struct SpawnedEntity) == 12);

/*
  0x0202fb90
  ステージ上のEntityのスポーンを管理する構造体
*/
struct SpawnManager {
  u32 spawnable[32 + 1];            // 1024個のbitfield (bitが1なら、対応するEntityをスポーンできる。 すでに生成している雑魚敵 や 一度きりのアイテム の再生成を防止するために存在)
  struct SpawnedEntity buffer[32];  // 32個の SpawnedEntity のバッファ (つまり SpawnManager によってスポーンできる Entity は最大32体)
  struct SpawnedEntity* list;       // リンクリストの先頭
  struct SpawnedEntity* free;
  bool16 isMissionDone;  // 0x20C, 今いるステージのミッションがすでに終わっている(= フリーラン)
  bool16 spawnDisabled;  // 0x20E, bit0 が 1なら、 新たに Entity をスポーンさせない (範囲外に出たEntityを消す処理は通常通り行う)
  u8 stageID;            // 0x210
  u8 area;               // 0x211, Stage area
  u16 remaining;
  const struct SpawnTemplate* template;  // 0x08347954 のテーブルのエントリのどれかが入る
  const struct SpawnPoint* points;       // sStageSpawnPointTable のテーブルのエントリのどれかが入る
  s32 borderY[2];                        // 0x21C, ここで指定されたY座標の範囲外にいる Entity は viewport の座標に関係なくスポーンしなくなる

  /*
    SpawnPoint のエントリで画面左端より左側(つまり左過ぎて画面外にあるもの)の個数
    UpdateSpawnManager ではインデックスがstart以降、つまり画面左端より右側に存在する SpawnPoint に対して Entity生成処理を行なっていく
  */
  u16 start;

  bool8 enemiesDeleted;       // 0x226, 雑魚敵を消去する系のサイバーエルフ発動中
  bool8 mettaursEnabled;      // 0x227: 敵がメットールに置き換えられているかを表すフラグ
  bool8 inCyberSpace;         // 0x228: サイバー空間からの出入りを検知するためのフラグ, 雑魚敵をMMBN4のウィルスにする or 元に戻す処理のトリガーとして使われる
  bool8 mmbn4EnemiesEnabled;  // 0x229: 敵がMMBN4の雑魚敵に置き換えられているかを表すフラグ
  u16 cyberOBPs;              // 0x22A, (スプライトの)パレットID のビットフィールドで、サイバー空間のパレットエフェクトの対象を示す?
};  // 556 bytes
static_assert(sizeof(struct SpawnManager) == 556);

// --------------------------------------------

extern struct SpawnManager gSpawnManager;

// --------------------------------------------

void InitSpawnManager(u8 stageID, bool8 missionDone);
struct Entity* CreateStageEntity(u8 kind, u8 id);
void DeleteStageEntity(struct Entity* e);
void ClipSpawnRange(s32 top, s32 bottom);

#endif  // GUARD_RMZ3_SPAWN_H
