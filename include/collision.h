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
#define FORCE_LAYER (6)  // ???

// Collision.hardness
#define METAL (1 << 0)  // 攻撃が当たった時に金属音がなり、バスターが貫通しなくなる(ダメージは通る)
#define NO_DAMAGE (1 << 1)
#define LITTLE_HARD (1 << 2)  // Take 2/3 damage
#define HARDNESS_B3 (1 << 3)
#define HARDNESS_WEAK (1 << 4)  // Take 2x damage

#define priorityLayer layer

// DRP
#define LAYER_MASK(drp) (*(u32*)(drp->atkType))
#define LAYER(val) \
  atkType:         \
  ((val) >> 0) & 0xFF, element : ((val) >> 8) & 0xFF, nature : ((val) >> 16) & 0xFF, comboLv : ((val) >> 24) & 0xFF

// LAYER(RECOIL_PUSHABLE)
#define RECOIL_PUSHABLE 0x7800

// CollisionManager.disabled
#define COLLMAN_DISABLED (1 << 7)

// Collision.atkType
enum CollisionAtkType {
  ATK_NORMAL = 0,  // 通常攻撃
  ATK_SABER = 1,   // 特殊攻撃, 4フレームのヒットストップが発生する
  ATK_ROD = 2,     // リコイルロッド, 4フレームのヒットストップが発生する
  ATK_UNK3 = 3,
  ATK_UNK4 = 4,
  ATK_UNK5 = 5,
  ATK_UNK6 = 6,
  ATK_UNK7 = 7,
  ATK_UNK8 = 8,
  ATK_UNK9 = 9,
  ATK_UNK10 = 10,
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

// HitboxTemplate とかにした方がいいかも
struct Collision {
  u8 kind;     // 0x00, HitboxKind
  u8 faction;  // 0x01, 同じレイヤーに属するもの同士のコリジョンは発生し"無い"
  u8 special;  // 0x02, bit0: プチットやダメージ半減などの特殊処理の対象を示すフラグ, bit1: ???
  u8 damage;   // 0x03, damage dealt (for enemies only?)

  // --------------------------------------------
  // If DRP, this is u32 layer value for DDPBody.collisionLayer
  u8 atkType;  // 0x04
  u8 element;  // 0x05
  u8 nature;   // 0x06
  u8 comboLv;  // 0x07
  // --------------------------------------------

  u8 hitzone;    // 0x08, 肉質
  u8 hardness;   // 0x09, 特殊なダメージカットなどを実装したい時
  u8 unk_0a;     // 0x0a
  u8 remaining;  // 0x0b, 通常キャラクターの当たり判定は複数のAABBで構成されている, (struct Collisionの配列において、)後続の Collision のうち、

  u32 layer;          // 0x0c, DDPの場合: 単純なCollisionのレイヤ、 self.unk_0c & LAYER(DRP) されて0じゃないならCollisionが処理される, DRPの場合: 連鎖値を無視して処理する優先レイヤ、 ランプロートの盾など、優先的に攻撃を吸ってもらいたい部位に設定される
  struct Rect range;  // 0x10, Hitbox range
};
static_assert(sizeof(struct Collision) == 24);

// 1 Hitbox が 1 Collision　に対応
struct Hitbox {
  struct Hitbox* next;     // 0x00, Hitboxのリンクリスト (あくまで同じレイヤーのHitbox同士のリンクで、別のBodyのHitboxも指す)
  struct Collision* data;  // 0x04, この Hitbox の AABBのデータ (ROM)
  struct Body* body;       // 0x08, この Hitbox の持ち主
  Coords32 c;              // 0x0C, この Hitbox のワールド座標 (= body->coord + data.range)
  u16 w;                   // 0x14, この Hitbox の幅 (= data.range.w)
  u16 h;                   // 0x16, この Hitbox の高さ (= data.range.h)
};  // 24 bytes
static_assert(sizeof(struct Hitbox) == 24);

// 0x030032e0
struct CollisionManager {
  u8 disabled;                // 0x000, bitに対応するFACTIONの重なり検知をしない, bit0: FACTION_ALLY, bit1: FACTION_ENEMY, bit2: FACTION_NEUTRAL, bit3..6: Unused, bit7: 全部
  u8 sweep;                   // 0x001, bitに対応するFACTIONのEntityを全てkillする, bit0: FACTION_ALLY, bit1: FACTION_ENEMY(Used for area change?), bit2: FACTION_NEUTRAL, bit3..7: Unused
  u8 hitstop;                 // 0x002, この値がxxの場合、xxフレーム後まで画面が止まる, セイバーとかの攻撃が当たった時にセット
  u8 length;                  // 0x003, 次に追加するコリジョンデータのidxでもある(毎フレーム0にセットされてその後、各エンティティのコリジョンデータが設定されるごとに増えていく)
  struct Hitbox buf[64];      // 0x004, Hitbox のバッファ
  struct Hitbox* list[3][3];  // 0x604, Hitbox linklist (.bufのデータのリンクリスト)
  struct Body* talkTo;        // 0x628, 会話可能なキャラが会話範囲にいるときにそのキャラのBodyがセットされる
  struct Body* door;          // 0x62C, ドアの当たり判定に入ったときにそのドアのBodyがセットされる
  struct Body* teleportal;    // 0x630, テレポータルの当たり判定に入ったときにそのテレポータルのBodyがセットされる
};
static_assert(sizeof(struct CollisionManager) == 1588);

extern struct CollisionManager gCollisionManager;

void ResetCollisionManager(void);
void ClearAllHitboxes(void);
void SetDDP(struct Body*, const struct Collision*);
u16 CalcDamage(struct Body* a, struct Body* d);
void CheckCollision(void);

void ResisterNonAffineHitbox(struct Body* body);
void RegisterFlipableHitbox(struct Body* body, u8 flip);
void RegisterScalerotHitbox(struct Body* body, u8 flip, u8 angle);

void InitWeaponBody(struct Body* o, const struct Collision* hitbox, s16 atk, s16 elementID, s16 r4, s16 r5);
void InitBody(struct Body* p, const struct Collision* hitbox, Coords32* coord, s16 hp);

u16 CalcPutitedSpikeDamage(struct Body* body, u8 damage);

#endif  // GUARD_RMZ3_COLLISION_H
