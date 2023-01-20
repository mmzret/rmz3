#ifndef GUARD_RMZ3_ENTITY_WEAPON_H
#define GUARD_RMZ3_ENTITY_WEAPON_H

#include "entity/entity.h"

struct Weapon {
  struct BaseGeneralEntity base;
  struct Object *obj;
  struct Zero *z;
  struct Coord prevCoord;

  /*
    08007224 の 引数4つ目
    属性?
  */
  u8 unk_c0;
  u8 atk;

  /*
    08007224 の 引数5つ目
      bit 1: ??
      bit 6: イレタスの効果が乗っているか
  */
  u8 unk_c2;

  u8 unk_195;
  u8 unk_196[40];
};  // 236 bytes

#endif  // GUARD_RMZ3_ENTITY_WEAPON_H
