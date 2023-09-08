#ifndef GUARD_RMZ3_ENTITY_WEAPON_H
#define GUARD_RMZ3_ENTITY_WEAPON_H

#include "entity/entity.h"

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

struct Buster_b4 {
  struct Zero *z;
  struct Coord c;
  u8 props[8];
  u8 unk_c8[36];
};

struct Weapon {
  struct Entity s;
  struct Body body;
  struct Weapon_b4 unk_b4;
};  // 236 bytes

typedef void (*WeaponFunc)(struct Weapon *);
typedef WeaponFunc WeaponRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_WEAPON_H
