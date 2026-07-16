#ifndef __INCLUDE_BOSS_OMEGA1_H__
#define __INCLUDE_BOSS_OMEGA1_H__

#include "entity/entity.h"
#include "gba/gba.h"

struct Omega1 {
  COLLISION_OBJECT_HDR;   // 0x00
  u8 unk_b4[4];           // 0xB4
  s32 unk_y;              // 0xB8
  struct Entity* unk_bc;  // 0xBC, omegaWhite_080b91d4
  u16 unk_c0;             // 0xC0
  u8 unk_c2[18];          // 0xC2
  u32 unk_d4;             // 0xD4
  u8 unk_d8[12];          // 0xD8
};
static_assert(sizeof(struct Omega1) == sizeof(struct Boss));

#endif  // __INCLUDE_BOSS_OMEGA1_H__
