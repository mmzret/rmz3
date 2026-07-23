#ifndef __INCLUDE_PROJECTILE_BLAZIN_H__
#define __INCLUDE_PROJECTILE_BLAZIN_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 angle_b4;           // 0xB4
  u8 unk_b5[15];         // 0xB5
} BlazinProjectile;
static_assert(sizeof(BlazinProjectile) == sizeof(Projectile));

BlazinProjectile* FUN_0809e500(Entity* e, Coords32* c, Coords32* d);
BlazinProjectile* FUN_0809e55c(Entity* e, Coords32* c, Coords32* c2);
BlazinProjectile* _createBlazinEXFireBall(Entity* e, Coords32* c, Coords32* d, u8 angle);
BlazinProjectile* blazin_0809e620(Entity* e, Coords32* c, Coords32* d);

#endif  // __INCLUDE_PROJECTILE_BLAZIN_H__
