#ifndef GUARD_RMZ3_ENTITY_MAPITEM_H
#define GUARD_RMZ3_ENTITY_MAPITEM_H

#include "entity/entity.h"
#include "entity/zero.h"
#include "global.h"

struct Pickup {
  struct Entity s;
  struct Body body;
  s32 y;
  struct Zero* z;  // ゼロがアイテム拾うとセットされる
  u8 work[8];
};  // 196 bytes

typedef void (*PickupFunc)(struct Pickup*);
typedef PickupFunc PickupRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_MAPITEM_H
