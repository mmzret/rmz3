#ifndef GUARD_RMZ3_ENTITY_BOSS_H
#define GUARD_RMZ3_ENTITY_BOSS_H

#include "entity/entity.h"
#include "sound.h"

struct OmegaWhiteProps {
  u8 unk_b4;
  s8 unk_b5[2];
  u8 unk_b7;
  s32 unk_y;
  u32 unk_bc;
  u16 unk_c0;
  u8 unk_c2[18];
  u32 unk_d4;
  u8 unk_d8[12];
};

struct OmegaZeroProps {
  s32 x;
  s32 y;
  void *vfx;
  u8 oldMode_c0;
  u8 unk_c1;
  u16 unk_c2;
  bool8 isRight;
  u8 prevMode;
  u8 unk_c6;
  u8 unk_c7;
  void *unk_c8;
  void *unk_cc;
  SoundID se;
  u8 unk_d2;
  u8 unk_d3;
  u32 unk_d4;
  u8 unk_d8[12];
};

struct Boss {
  struct Entity s;
  struct Body body;

  union {
    u8 raw[48];
    struct OmegaWhiteProps omegaWhite;
    struct OmegaZeroProps oz;
  } props;
};  // 228 bytes

typedef void (*BossFunc)(struct Boss *);
typedef BossFunc BossRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_BOSS_H
