#ifndef GUARD_RMZ3_PHYSICS_BODY_H
#define GUARD_RMZ3_PHYSICS_BODY_H

#include "common.h"
#include "gba/gba.h"

// Body.status, Body.hitboxFlags
#define BODY_STATUS_WHITE (1 << 0)
#define BODY_STATUS_B1 (1 << 1)
#define BODY_STATUS_B2 (1 << 2)
#define BODY_STATUS_B3 (1 << 3)
#define BODY_STATUS_B4 (1 << 4)
#define BODY_STATUS_B5 (1 << 5)
#define BODY_STATUS_B6 (1 << 6)
#define BODY_STATUS_B7 (1 << 7)
#define BODY_STATUS_B8 (1 << 8)
#define BODY_STATUS_DEAD (1 << 9)
#define BODY_STATUS_BINDED (1 << 10)
#define BODY_STATUS_BINDING (1 << 11)
#define BODY_STATUS_BLOCKED (1 << 12)
#define BODY_STATUS_B13 (1 << 13)
#define BODY_STATUS_B14 (1 << 14)
#define BODY_STATUS_B15 (1 << 15)
#define BODY_STATUS_SLASHED (1 << 16)
#define BODY_STATUS_RECOILED (1 << 17)  // Pushed by recoil rod
#define BODY_STATUS_B22 (1 << 22)
#define BODY_STATUS_B23 (1 << 23)
#define BODY_STATUS_B28 (1 << 28)
#define BODY_STATUS_CHAT (1 << 29)
#define BODY_STATUS_DOOR (1 << 30)
#define BODY_STATUS_TELEPORTAL (1 << 31)

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

typedef void (*BodyFunc)(struct Body*, struct Coord*, struct Coord*);

/**
 * @brief Physics Body (Ja: 肉体)
 */
struct Body {
  const struct Collision* collisions;  // Collision chain start
  const struct Collision* processing;  // .collisions は Bodyが持ってる当たり判定のリスト、 .processing は オーバーラップした時に、解決処理の間、Collisionリストの先頭を指す
  struct Coord* coord;
  struct Body* enemy;     // 接触ダメージを受ける時は接触相手
  struct Body* bindPair;  // 拘束技(オメガZXのバインディングボールなど)を食らった時の相手(e.g. Zero ⇆ Binding ball)

  u32 hitboxFlags;  // .status と同じ内容？

  /*
    bit 0:  真っ白にする 被ダメの無敵エフェクト用
    bit 9:  ボディのHPが0になるとセット、ゼロのときにこのフラグを立てるとミッション失敗になるのでおそらく死亡判定
    bit 12: 硬いものにあたって無効化されたか
    bit 16: 死亡時の切断演出の有無？
    bit 29: 上ボタンで会話ができるときに立つ
    bit 30: 上ボタンでドアに入れるときに立つ
  */
  u32 status;
  u32 prevStatus;

  // bit0..6: invincible frame
  // bit7:    ???
  u8 invincibleTime;
  u8 unk_21;
  u8 invincibleLv;  // 無敵レベル(防御側の連鎖値)
  u8 unk_23 : 4;
  u8 elemented : 4;  // Element damaged?
  BodyFunc fn;       // ダメージを与えた時 or 食らった時 に呼び出される
  u32 unk_28;
  struct CollidableEntity* parent;  // Objectの親ステート
  s16 hp;
  s16 unk_32[2];

  u8 forceFlags;  // ダメージや属性、連鎖値などでCollisionの値ではなくプログラムで指定した値を強制する
  u8 atk;         // 攻撃力(何の？)
  u8 element;
  u8 nature;   // 豆をかき消せるなどの特性
  u8 comboLv;  // 連鎖値(無敵レベル)

  /*
    攻撃を喰らう際に  自分の processing->unk_09 と ORしたものをフラグとして使っている
    bit 0: 1にすると、攻撃が当たった時に金属音がなり、バスターが貫通しなくなる(ダメージは通る, 関数の0x08007e28参照)
    bit 1: ダメージを0に
    bit 2: ダメージを2/3に
    bit 3: ???
    bit 4: ダメージを2倍に
  */
  u8 hardness;
  u32 collisionLayer;
};  // 64 bytes

#endif  // GUARD_RMZ3_PHYSICS_BODY_H
