#ifndef __INCLUDE_PROJECTILE_BLAZIN_TAIL_H__
#define __INCLUDE_PROJECTILE_BLAZIN_TAIL_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 hp;        // 0xB4
  s32 xflip;     // 0xB8
  u8 unk_bc[8];  // 0xBC
} BlazinTail;
static_assert(sizeof(BlazinTail) == sizeof(Projectile));

BlazinTail* createBlazinTail(Entity* e, s32 hp);

#endif  // __INCLUDE_PROJECTILE_BLAZIN_TAIL_H__
