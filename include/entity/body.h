#ifndef GUARD_RMZ3_PHYSICS_BODY_H
#define GUARD_RMZ3_PHYSICS_BODY_H

#include "common.h"
#include "gba/gba.h"

// Body.status, Body.hitboxFlags
#define BODY_STATUS_WHITE (1 << 0)  // 真っ白にする 被ダメの無敵エフェクト用
#define BODY_STATUS_B1 (1 << 1)
#define BODY_STATUS_B2 (1 << 2)
#define BODY_STATUS_B3 (1 << 3)
#define BODY_STATUS_B4 (1 << 4)
#define BODY_STATUS_B5 (1 << 5)
#define BODY_STATUS_B6 (1 << 6)
#define BODY_STATUS_B7 (1 << 7)
#define BODY_STATUS_B8 (1 << 8)
#define BODY_STATUS_DEAD (1 << 9)  // 0x200, ボディのHPが0になるとセット、ゼロのときにこのフラグを立てるとミッション失敗になるのでおそらく死亡判定
#define BODY_STATUS_BINDED (1 << 10)
#define BODY_STATUS_BINDING (1 << 11)  // 0x800
#define BODY_STATUS_BLOCKED (1 << 12)  // 硬いものにあたって無効化されたか
#define BODY_STATUS_B13 (1 << 13)
#define BODY_STATUS_B14 (1 << 14)
#define BODY_STATUS_B15 (1 << 15)
#define BODY_STATUS_SLASHED (1 << 16)   // 死亡時の切断演出の有無？
#define BODY_STATUS_RECOILED (1 << 17)  // 0x20000, Pushed by recoil rod
#define BODY_STATUS_B22 (1 << 22)
#define BODY_STATUS_B23 (1 << 23)
#define BODY_STATUS_B28 (1 << 28)
#define BODY_STATUS_CHAT (1 << 29)  // 上ボタンで会話ができるときに立つ
#define BODY_STATUS_DOOR (1 << 30)  // 上ボタンでドアに入れるときに立つ
#define BODY_STATUS_TELEPORTAL (1 << 31)

// Body.nature
#define BODY_NATURE_B0 (1 << 0)
#define ELEMENT_ENCHANTABLE (1 << 1)  // (ゼロ専用)エレメントチップで属性を付与できる
#define BODY_NATURE_B2 (1 << 2)
#define BODY_NATURE_B3 (1 << 3)
#define BODY_NATURE_CUT (1 << 4)      // 斬撃属性(死体を両断するか)
#define BODY_NATURE_RECOIL (1 << 5)   // Recoil rod(Charge)
#define BODY_NATURE_ILETHAS (1 << 6)  // Vanish enemy's lemon
#define BODY_NATURE_B7 (1 << 7)

struct Collision;
struct Body;

// 基本的に最初の Body しか使わない (SharksealX_OnCollision が 2個目の引数を使っている)
typedef void (*BodyFunc)(struct Body*, Coords32*, Coords32*);

struct Body {
  const struct Collision* collisions;  // 0x00, 自分の当たり判定を表す Hitboxのリスト
  const struct Collision* processing;  // 0x04, .collisions のどれかが別のBodyと交差したときに、該当の Collisionをセットする
  Coords32* coord;                     // 0x08, = &Entity.coord
  struct Body* enemy;                  // 0x0C, 交差した相手のBody
  struct Body* bindPair;               // 0x10, 拘束技(オメガZXのバインディングボールなど)を食らった時の相手(e.g. Zero ⇆ Binding ball)

  u32 hitboxFlags;  // 0x14, .status と同じ内容？
  u32 status;       // 0x18
  u32 prevStatus;   // 0x1C

  u8 invincibleTime;      // 0x20, bit0..6: 無敵時間(フレーム数), bit7: このbitがセットされている場合は、bit0..6の値に関係なく無敵
  u8 unk_21;              // 0x21
  u8 invincibleLv;        // 0x22, 無敵レベル(防御側の連鎖値)
  u8 unk_23 : 4;          // 0x23.0-3
  u8 elemented : 4;       // 0x23.4-7, Element damaged?
  BodyFunc fn;            // 0x24, ダメージを与えた時 or 食らった時 に呼び出される
  u32 unk_28;             // 0x28
  struct Entity* parent;  // 0x2C, Objectの親ステート
  s16 hp;                 // 0x30
  s16 unk_32[2];          // 0x32

  u8 forceFlags;  // 0x36, ダメージや属性、連鎖値などでCollisionの値ではなくプログラムで指定した値を強制する
  u8 atk;         // 0x37, 攻撃力(何の？)
  u8 element;     // 0x38
  u8 nature;      // 0x39, 豆をかき消せるなどの特性
  u8 comboLv;     // 0x3a, 連鎖値(無敵レベル)

  u8 hardness;         // 0x3b, Collision.hardness と内容は同じ、 (Body.hardness | Collision.hardness) で処理を行う
  u32 collisionLayer;  // 0x3c
};  // 64 bytes
static_assert(sizeof(struct Body) == 64);

#endif  // GUARD_RMZ3_PHYSICS_BODY_H
