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

// Collision.kind
enum HitboxKind {
  DDP,   // 攻撃判定
  DRP,   // 喰らい判定
  DRP2,  // 喰らい判定その2
};

// Collision is occuring between different factions
enum CollisionFaction {
  FACTION_ALLY,   // 味方側の攻撃
  FACTION_ENEMY,  // 敵側の攻撃(=ゼロにダメージがあるもの)
  FACTION_UNK2,
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

  /*
    bit2: ランプロードの盾を攻撃する時のZバスターの豆、リコイル、シールドブーメラン
  */
  u8 unk_04;
  u8 element;
  u8 nature;
  u8 comboLv;

  u8 hitzone;   // 肉質
  u8 hardness;  // 特殊なダメージカットなどを実装したい時
  u8 unk_0a;
  u8 remaining;  // is 0, Collision chain is end
  u32 unk_0c;
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
    bit 2: ???(FACTION_UNK2)
    bit 7: 全部スキップ
  */
  u8 disabled;

  /*
    bit 0:    kill Zero(FACTION_ALLY)
    bit 1:    kill All Enemies (Used for area change?)(FACTION_ENEMY)
    bit 2:    ???(FACTION_UNK2)
    bit 3..7: Unused
  */
  u8 sweep;
  u8 pauseFrame;              // この値がxxの場合、xxフレーム後まで画面が止まる 回復アイテム取った時とかに使う？
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
