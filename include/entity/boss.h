#ifndef GUARD_RMZ3_ENTITY_BOSS_H
#define GUARD_RMZ3_ENTITY_BOSS_H

#include "entity/entity.h"
#include "sound.h"

struct ChildreProps {
  struct Entity *unk_b4;
  u32 unk_b8;
  struct Coord unk_bc;
  u8 unk_c4;
  u8 unk_c5;
  bool8 shouldTurnRight;
  u8 unk_c7;
  struct Coord unk_c8;
  u8 unk_d0[20];
};

struct DeathtanzProps {
  struct Coord unk_b4;
  u8 unk_bc;
  u8 unk_bd;
  u8 unk_be;
  u8 unk_bf;
  u8 unk_c0;
  u8 unk_c1;
  bool8 shouldTurnRight;
  u8 unk_c3;
  u8 unk_c4;
  u8 unk_c5[3];
  struct Coord unk_c8;
  u8 unk_d0[20];
};

struct GlacierleProps {
  u32 unk_b4;
  struct VFX *unk_b8;
  s32 unk_bc;
  u8 unk_c0;
  u8 unk_c1;
  bool8 shouldRightDir;
  u8 unk_c3[5];
  struct Coord unk_c8;
  u8 unk_d0[20];
};

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

struct CopyXProps {
  u8 unk_b4[16];
  u8 unk_c4;
  u8 unk_c5;
  u8 unk_c6[22];
  u8 unk_dc;
  s8 unk_dd;
  u8 unk_de[6];
};

struct HellbatProps {
  u8 unk_b4[32];
  s32 unk_d4;
  u8 unk_d8[12];
};

struct PAquaModProps {
  u8 unk_b4[6];
  u16 x;
  s32 y;
  u8 unk_c0[36];
};

struct Boss {
  struct Entity s;
  struct Body body;

  union {
    u8 raw[48];
    struct OmegaWhiteProps omegaWhite;
    struct OmegaZeroProps oz;
    struct CopyXProps copyx;
    struct GlacierleProps glacierle;
    struct ChildreProps childre;
    struct DeathtanzProps deathtanz;
    struct HellbatProps hellbat;
    struct PAquaModProps paquam;
  } props;
};  // 228 bytes

typedef void (*BossFunc)(struct Boss *);
typedef BossFunc BossRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_BOSS_H
