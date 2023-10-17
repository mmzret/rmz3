#ifndef GUARD_RMZ3_ENTITY_VFX_H
#define GUARD_RMZ3_ENTITY_VFX_H

#include "entity/entity.h"

struct TempProps {
  struct Coord c;
  u8* unk_7c;
  u8 work[4];
};

struct ElementalEffectProps {
  struct Coord c;
  u8 unk_8[8];
};

struct Unk7Props {
  u16 unk_0;
  u16 unk_2;
  u8 unk_4[12];
};

struct Unk8Props {
  u8 unk_0;
  u8 unk_1[3];
  u16 unk_4;
  u16 unk_6;
  u8 unk_8[8];
};

struct Unk25Props {
  struct Coord c;
  u8 unk_7c[4];
  u16 unk_80;
  u16 unk_82;
};

struct Unk28Props {
  u16 unk_0;
  u16 unk_2;
  s32 unk_4;
  u8 unk_8[8];
};

struct Unk32Props {
  s16 unk_0;
  u8 unk_2[2];
  u32 unk_4;
  u32 unk_8;
  u16 unk_c;
  u16 unk_e;
};

struct Unk69Props {
  struct Coord c;
  u8 unk_8[8];
};

struct AfterImageProps {
  struct Coord c;
  u8 unk_8[8];
};

struct SnowProps {
  u32 unk_0;
  u8 unk_4[12];
};

struct NecroProps {
  motion_t* motions;
  u8 unk_04;
  u8 unk_05;
  u8 unk_06[10];
};

struct BubbleProps {
  u8 unk_0[4];
  s32 unk_4;
  u8 unk_8[8];
};

struct VFX {
  struct Entity s;
  union {
    u8 raw[16];
    struct BubbleProps bubble;
    struct AfterImageProps afterImage;
    struct NecroProps necro;
    struct SnowProps snow;
    struct ElementalEffectProps ee;
    struct Unk7Props unk7;
    struct Unk8Props unk8;
    struct Unk28Props vfx21;
    struct Unk25Props unk25;
    struct Unk28Props unk28;
    struct Unk32Props unk32;
    struct Unk69Props unk69;
    struct TempProps tmp;
  } props;
};  // 132 bytes

// For VFX 16
// e.g. u8_ARRAY_08365c14
struct SlashedEnemy {
  motion_t m;
  u8 unk_02[2];
  struct Coord16 c;
  struct Coord16 d;
  struct Coord16 unk_coord_0c;
  struct Coord16 unk_10;
  u16 unk_14[2];
  u8 _[4];
};  // 28 bytes

typedef void (*VFXFunc)(struct VFX*);
typedef VFXFunc VFXRoutine[5];

#endif  // GUARD_RMZ3_ENTITY_VFX_H
