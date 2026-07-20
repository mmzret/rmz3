#ifndef __INCLUDE_BOSS_COPY_X_H__
#define __INCLUDE_BOSS_COPY_X_H__

#include "entity/entity.h"
#include "gba/gba.h"

struct BossCopyX {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[16];         // 0xB4
  u8 unk_c4;             // 0xC4
  u8 unk_c5;             // 0xC5
  u8 unk_c6;             // 0xC6, FUN_080a9dcc で使用
  u8 unk_c7;             // 0xC7
  u8 unk_c8[20];         // 0xC8
  u8 unk_dc;             // 0xDC
  s8 unk_dd;             // 0xDD
  u8 unk_de[6];          // 0xDE
};
static_assert(sizeof(struct BossCopyX) == sizeof(struct Boss));

#endif  // __INCLUDE_BOSS_COPY_X_H__
