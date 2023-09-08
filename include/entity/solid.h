#ifndef GUARD_RMZ3_ENTITY_SOLID_H
#define GUARD_RMZ3_ENTITY_SOLID_H

#include "entity/entity.h"

struct ResistanceBaseElevatorProps {
  struct Coord c;
  u8 unk_bc;
  u8 skin;  // 1: Wood, 2: MMX
  SoundIDS16 se;
  u8 unk_c0;
  u8 unk_c1;
  u16 unk_c2;
};

struct Solid8Props {
  s32 y;
  u8 unk_04[12];
};

struct LocomoIFPlatformProps {
  u16 unk_00;
  u8 unk_02[14];
};

struct MobProps {
  u8 unk_00[8];
  s16 unk_08;
  motion_t motion;
  u8 unk_0c[4];
};

struct Solid {
  struct Entity s;
  struct Body body;
  union {
    u8 raw[16];
    struct Solid8Props solid8;
    struct ResistanceBaseElevatorProps rbe;
    struct LocomoIFPlatformProps lifp;
    struct MobProps mob;
  } props;
};  // 196 bytes

typedef void (*SolidFunc)(struct Solid*);
typedef SolidFunc SolidRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_SOLID_H
