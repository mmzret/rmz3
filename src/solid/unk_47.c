#include "collision.h"
#include "global.h"
#include "solid.h"

INCASM("asm/solid/unk_47.inc");

void Solid47_Init(struct Solid* p);
void Solid47_Update(struct Solid* p);
void Solid47_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid47Routine = {
    [ENTITY_INIT] =      Solid47_Init,
    [ENTITY_MAIN] =      Solid47_Update,
    [ENTITY_DIE] =       Solid47_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void FUN_080dec04(struct Solid* p);
void FUN_080def4c(struct Solid* p);

static const SolidFunc sInitializers[2] = {
    FUN_080dec04,
    FUN_080def4c,
};

// --------------------------------------------

void FUN_080dec48(struct Solid* p);
void FUN_080defa8(struct Solid* p);

static const SolidFunc sUpdates[2] = {
    FUN_080dec48,
    FUN_080defa8,
};

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      layer : 2,
      special : 0,
      damage : 0,
      unk_04 : 0x00,
      element : 0x78,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0xFF,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(4)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)};
