#ifndef __INCLUDE_BOSS_ANUBIS_H__
#define __INCLUDE_BOSS_ANUBIS_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[12];         // 0xB4
  u32 unk_c0;            // 0xC0
  u8 unk_c4[7];          // 0xC4
  u8 pzombieCount;       // 0xCB
  u8 unk_cc[24];         // 0xCC
} Anubis;
static_assert(sizeof(Anubis) == sizeof(struct Boss));

#endif  // __INCLUDE_BOSS_ANUBIS_H__
