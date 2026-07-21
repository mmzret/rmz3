#ifndef __INCLUDE_BOSS_OMEGA1_H__
#define __INCLUDE_BOSS_OMEGA1_H__

#include "entity/entity.h"
#include "gba/gba.h"

typedef struct {
  COLLISION_OBJECT_HDR;   // 0x00
  u8 unk_b4;              // 0xB4
  s8 prevModes[2];        // 0xB5
  u8 unk_b7;              // 0xB7
  s32 unk_y;              // 0xB8
  struct Entity* unk_bc;  // 0xBC, omegaWhite_080b91d4
  u16 unk_c0;             // 0xC0
  u8 unk_c2[6];           // 0xC2
  void* sword;            // 0xC8, CreateOmega1gSword
  u8 unk_cc[8];           // 0xCC
  u32 unk_d4;             // 0xD4
  u8 unk_d8[12];          // 0xD8
} Omega1;
static_assert(sizeof(Omega1) == sizeof(struct Boss));

struct Entity* FUN_08082b58(Coords32* c, bool8 isLeftHand, Omega1* omega);
struct Entity* CreateOmega1gSword(Coords32* c, u8 r1, void* omega1);

#endif  // __INCLUDE_BOSS_OMEGA1_H__
