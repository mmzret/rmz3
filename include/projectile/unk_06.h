#ifndef __INCLUDE_PROJECTILE_UNK_06_H__
#define __INCLUDE_PROJECTILE_UNK_06_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u32 unk_b4;            // 0xB4
  u8 unk_b8[12];         // 0xB8
} LamplortFlame;         // 132 bytes
static_assert(sizeof(LamplortFlame) == sizeof(Object) + 16);

#endif  // __INCLUDE_PROJECTILE_UNK_06_H__
