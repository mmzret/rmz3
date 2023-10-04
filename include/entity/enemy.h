#ifndef GUARD_RMZ3_ENTITY_ENEMY_H
#define GUARD_RMZ3_ENTITY_ENEMY_H

#include "entity/entity.h"

struct VFX;

struct PantheonProps {
  s32 x;
  u8 unk_b8[4];
  u8 unk_bc;
  u8 unk_bd;
  u8 unk_be;
  u8 unk_bf;
  struct Entity* unk_c0;
};

struct GyroCannonProps {
  struct VFX* elementEffect;
  u8 unk_004;
  u8 unk_005;
  u16 unk_006;
  u8 unk_008[8];
};

struct ShrimporinProps {
  struct VFX* elementEffect;
  u8 unk_004[12];
};

struct FlopperProps {
  struct Coord c;
  u32 unk_08;
  u8 unk_0c[4];
};

struct Enemy {
  struct Entity s;
  struct Body body;
  union {
    u8 raw[16];
    struct PantheonProps pantheon;
    struct GyroCannonProps gyroCannon;
    struct ShrimporinProps shrimpolin;
    struct FlopperProps flopper;
  } props;
};  // 196 bytes

typedef void (*EnemyFunc)(struct Enemy*);
typedef EnemyFunc EnemyRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_ENEMY_H
