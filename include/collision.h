#ifndef GUARD_RMZ3_COLLISION_H
#define GUARD_RMZ3_COLLISION_H

#include "entity/body.h"
#include "gba/types.h"

#define SWEEP_ALL_ENEMY (1 << 1)

// Collision.special
#define HALFABLE 1
#define CS_BOSS 2
#define CHATABLE 3
#define DOOR_3D 4
#define CS_TELEPORTAL 5

// Collision.flags
#define FORCE_DAMAGE (1 << 0)
#define FORCE_ELEMENT (1 << 1)
#define FORCE_NATURE (1 << 2)
#define FORCE_COMBO_LEVEL (1 << 3)
#define FORCE_LAYER (6)

#define priorityLayer layer

// DRP
#define LAYER_MASK(drp) (*(u32*)(drp->atkType))
#define LAYER(val) \
  atkType:         \
  ((val) >> 0) & 0xFF, element : ((val) >> 8) & 0xFF, nature : ((val) >> 16) & 0xFF, comboLv : ((val) >> 24) & 0xFF

// Collision.atkType
enum CollisionAtkType {
  ATK_NORMAL = 0,  // 通常攻撃

  // --------------------------------------------

  // 4フレームのヒットストップが発生する
  ATK_SABER = 1,  // 特殊攻撃
  ATK_ROD = 2,    // リコイルロッド

  // --------------------------------------------

  ATK_UNK3 = 3,
  ATK_UNK4 = 4,
  // ...
  ATK_UNK8 = 8,
  // ...
  ATK_UNK11 = 11,
  ATK_UNK12 = 12,
  ATK_SOUL_LAUNCHER = 13,
  ATK_UNK14 = 14,
  ATK_NONE = 0xFF,  // DRP, DRP2のとき
};

// Collision.kind
enum HitboxKind {
  DDP,   // 攻撃判定
  DRP,   // 喰らい判定
  DRP2,  // 喰らい判定その2(豆の跳ね返しや, リコイルロッドと関連？)
};

// Collision is occuring between different factions
enum CollisionFaction {
  FACTION_ALLY,     // 味方側の攻撃
  FACTION_ENEMY,    // 敵側の攻撃(=ゼロにダメージがあるもの)
  FACTION_NEUTRAL,  // NPC(敵ではないけど会話のために接触判定はしたい) や 中立(兵器再生工場のハンマー振り子やリコイルロッドで吹き飛ばした敵)
};

struct Collision {
  u8 kind;     // HitboxKind
  u8 faction;  // 同じレイヤーに属するもの同士のコリジョンは発生し"無い"

  /*
    bit 0: プチットやダメージ半減などの特殊処理の対象を示すフラグ
    bit 1: ???
  */
  u8 special;
  u8 damage;  // damage dealt (for enemies only?)

  // --------------------------------------------
  // If DRP, this is u32 layer value for DDPBody.collisionLayer
  u8 atkType;
  u8 element;
  u8 nature;
  u8 comboLv;
  // --------------------------------------------

  u8 hitzone;   // 肉質
  u8 hardness;  // 特殊なダメージカットなどを実装したい時
  u8 unk_0a;
  u8 remaining;  // is 0, Collision chain is end

  /*
    DDPの場合: 単純なCollisionのレイヤ、 self.unk_0c & LAYER(DRP) されて0じゃないならCollisionが処理される
    DRPの場合: 連鎖値を無視して処理する優先レイヤ、 ランプロートの盾など、優先的に攻撃を吸ってもらいたい部位に設定される
  */
  u32 layer;
  struct Rect range;  // Collision range
};

// 0x030038e4
struct Hitbox {
  struct Hitbox* next;
  struct Collision* collisions;
  struct Body* body;
  struct Coord c;
  u16 w;
  u16 h;
};  // 24 bytes

// 0x030032e0
struct CollisionManager {
  /*
    bit 0: ゼロ側のコリジョン関連の処理をスキップ(FACTION_ALLY)
    bit 1: 敵側のコリジョン関連の処理をスキップ(FACTION_ENEMY)
    bit 2: 中立エンティティのコリジョン関連の処理をスキップ(FACTION_NEUTRAL)
    bit 7: 全部スキップ
  */
  u8 disabled;

  /*
    bit 0:    kill Zero(FACTION_ALLY)
    bit 1:    kill All Enemies (Used for area change?)(FACTION_ENEMY)
    bit 2:    kill Neutral Entities(FACTION_NEUTRAL)
    bit 3..7: Unused
  */
  u8 sweep;
  u8 hitstop;                 // この値がxxの場合、xxフレーム後まで画面が止まる 回復アイテム取った時とかに使う？
  u8 length;                  // 次に追加するコリジョンデータのidxでもある(毎フレーム0にセットされてその後、各エンティティのコリジョンデータが設定されるごとに増えていく)
  struct Hitbox buf[64];      // Collision data のバッファ
  struct Hitbox* list[3][3];  // Collision data linklist (.bufのデータのリンクリスト)
  struct Body* talkTo;        // ゼロが上ボタンを押すと会話ができるキャラクター
  struct Body* door;          // ゼロが上ボタンを押すと開ける範囲にあるドア
  struct Body* teleportal;
  u8 _[12];
};  // 1600 bytes

extern struct CollisionManager gCollisionManager;

void ResetCollisionManager(void);
void ClearAllHitboxes(void);
void SetDDP(struct Body*, const struct Collision*);
u16 CalcDamage(struct Body* a, struct Body* d);
void CheckCollision(void);

void ResisterNonAffineHitbox(struct Body* body);
void RegisterFlipableHitbox(struct Body* p, u8 flip);
void RegisterScalerotHitbox(struct Body* o, u32 r1, u32 r2);

void InitWeaponBody(struct Body* o, const struct Collision* hitbox, s16 atk, s16 elementID, s16 r4, s16 r5);
void InitBody(struct Body* p, const struct Collision* hitbox, struct Coord* coord, s16 hp);

u16 CalcPutitedSpikeDamage(struct Body* body, u8 damage);

#endif  // GUARD_RMZ3_COLLISION_H
