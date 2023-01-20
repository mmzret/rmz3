#ifndef GUARD_RMZ3_OBJECT_H
#define GUARD_RMZ3_OBJECT_H

#include "gba/gba.h"
#include "global.h"

typedef enum HitboxSpecial {
  HBOX_NONE = 0,
  HBOX_HALFABLE = 1,  // プチットやダメージ半減などの特殊処理の対象を示すフラグ
  HBOX_UNK_02 = 2
} HitboxSpecial;

/*
  DDPとDRPのどちらか
    DDP + 0x03 = damage dealt (for enemies only?)
    DRP + 0x02 = something if 0x01, see instructions 0800761C - 08007620 (+ some more after)
    DRP + 0x08 = invincibility if 0xFF (and 0x00?), see instructions 080075DC - 080075E0
*/
struct Hitbox {
  /*
    DDP:
      0: (DDPに対応する攻撃が)当たる
      1: すり抜ける(パンテオンにダメージなし)
      2: パンテオンはすり抜けたがパンテオンの豆をバスターの豆で全部消せた
    DRP:
      0: すり抜ける(ダメージなし)
      1: 柔らかい(普通)
      2: 硬い
  */
  u8 attr;
  bool8 unk_1;  // ZeroHitBox要素のこれをtrueにしたらゼットセイバーを振るうとゼロがなぜかダメージ
  enum HitboxSpecial special;
  u8 damage;  // damage dealt (for enemies only?)

  /*
    bit2: ランプロードの盾を攻撃する時のZバスターの豆、リコイル、シールドブーメラン
  */
  u8 unk_4;

  /*
    DDP:
      0x00: 何もなし
      0x01: 当たると麻痺?
      0x03: 当たると凍結?
    DRP:
      0xFF で固定?
  */
  u8 unk_5;
  u8 unk_6;
  u8 unk_7;

  u8 invincibility;

  /*
    bit 0: 1にすると、攻撃が当たった時に金属音がなり、バスターが貫通しなくなる(ダメージは通る)
  */
  u8 unk_9;

  u8 unk_10[10];
  u16 width;
  u16 height;
};

// 0x030038e4
struct UnkHitbox {
  struct UnkHitbox* next;
  struct Hitbox* hitbox;
  void* obj;
  struct Coord c;
  u16 w;
  u16 h;
};  // 24 bytes

// clang-format off
typedef enum ObjStatus {
  OBJ_WHITE   = 0x00000001,  // 真っ白にする 被ダメの無敵エフェクト用
  OBJ_FAILED  = 0x00000200,  // 0x02037cecでこのbit立てるとミッション失敗になる
  OBJ_BLOCKED = 0x00001000,  // 硬いものにあたって無効化されたか
  OBJ_SLASHED = 0x00010000,  // 死亡時の切断演出の有無？
  OBJ_CHAT    = 0x20000000,  // 上ボタンで会話ができるときに立つ
  OBJ_DOOR    = 0x40000000,  // 上ボタンでドアに入れるときに立つ
} ObjStatus;
// clang-format on

struct Object {
  struct Hitbox* ddp;  // DAMAGE DEALING POINTER
  struct Hitbox* drp;  // DAMAGE RECEIVING POINTER
  struct Coord* coord;
  struct Object* enemy;  // 接触ダメージを受ける時は接触相手
  void* unk_16;

  enum ObjStatus hitboxFlags;
  enum ObjStatus status;

  u32 unk_28;
  u16 invincibleTime;
  u16 comboLevel;
  void* fn;  // objがダメージ食らった時？
  u32 unk_40;
  struct Entity* parent;  // Objectの親ステート
  u16 hp;
  u8 unk_50[4];
  u8 unk_54;
  u8 atk;  // 攻撃力(何の？)
  u8 unk_56;
  u8 unk_57;
  u8 unk_58;
  u8 unk_59;
  u8 unk_60[4];
};  // 64 bytes

extern u8 FieldFlag_030032e0;
extern u8 u8_030032e3;
extern struct UnkHitbox * PTR_03003904;

void clearUnkHitboxes(void);

#endif  // GUARD_RMZ3_OBJECT_H
