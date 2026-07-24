#ifndef __INCLUDE_ENEMY_CLAVEKER_H__
#define __INCLUDE_ENEMY_CLAVEKER_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 initX;             // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  u8 unk_ba;             // 0xBA
  u8 unk_bb;             // 0xBB
  Entity* elfx;          // 0xBC
  u8 unk_c0[4];          // 0xC0
} Claveker;
static_assert(sizeof(Claveker) == sizeof(struct Enemy));

#endif  // __INCLUDE_ENEMY_CLAVEKER_H__
