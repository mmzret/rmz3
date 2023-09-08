#ifndef GUARD_RMZ3_ENTITY_PROJECTILE_H
#define GUARD_RMZ3_ENTITY_PROJECTILE_H

#include "entity/entity.h"

struct Projectile {
  struct Entity s;
  struct Body body;
  u8 work[4];  // general purpose buffer
  struct Coord prevCoord;
  u32 unk_c0;
};  // 196 bytes

typedef void (*ProjectileFunc)(struct Projectile *);
typedef ProjectileFunc ProjectileRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_PROJECTILE_H
