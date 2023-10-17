#ifndef GUARD_RMZ3_ENTITY_WEAPON_H
#define GUARD_RMZ3_ENTITY_WEAPON_H

#include "entity/entity.h"

struct Weapon;

struct Weapon_b4 {
  struct Zero *z;
  /*
    props[n][0]: 属性？
    props[n][1]: 攻撃力？
    props[n][2]: bit6: イレタスの効果が乗っているか
  */
  u8 props[2][8];

  u8 unk_c8[36];
};

struct Rod_b4 {
  struct Zero *z;
  u8 element;
  u8 atk;
  u8 unk_06;
  u8 comboLv;
  u8 unk_08;
  u8 unk_09;
  u8 unk_0a;
  u8 unk_0b;
  u8 unk_0c[8];
  u8 unk_c8[36];
};

struct Buster_b4 {
  struct Zero *z;
  struct Coord c;
  u8 unk_c0;
  u8 element;
  u8 unk_c2;
  u8 unk_c3;
  u8 unk_c4[40];
};

struct Saber_b4 {
  struct Zero *z;
  u8 props[8];
  u8 element;
  u8 atk;
  u8 nature;
  bool8 unk;
  u8 unk_c4[40];
};

// エルフで出せるやつ
struct SaberWave_b4 {
  struct Weapon *saber;  // projectile -> saber (if saber, this is null)
  struct Zero *z;
  u8 props[4];
  u8 element;
  u8 atk;
  u8 flags;
  bool8 unk;
  u8 unk_c4[40];
};

struct SoulLauncherProps {
  struct Zero *z;
  u8 unk_b8[8];
  u8 unk_c0;
  u8 element;
  u8 unk_c2[42];
};

// EXSkill (Ja: ザンエイダン)
struct ThrowBladeProps {
  struct Weapon *saber;
  u8 unk_b8[8];
  u8 element;
  u8 unk_c1[43];
};

struct Weapon {
  struct Entity s;
  struct Body body;
  union {
    u8 raw[56];
    struct Weapon_b4 common;
    struct Buster_b4 buster;
    struct Saber_b4 saber;
    struct SaberWave_b4 wave;  // Not EXSkill
    struct ThrowBladeProps throw_blade;
    struct SoulLauncherProps soul_launcher;
    struct Rod_b4 rod;
  } props;
};  // 236 bytes

typedef void (*WeaponFunc)(struct Weapon *);
typedef WeaponFunc WeaponRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_WEAPON_H
