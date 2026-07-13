#include "collision.h"
#include "global.h"
#include "solid.h"

struct Solid8Object {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  s32 y;
  u8 unk_04[12];
};
static_assert(sizeof(struct Solid8Object) == sizeof(struct Solid));

static const struct Rect sSize;
static const u8 sInitMode[4];

static void LavaRiverPlatform_Init(struct Solid8Object* p);
static void LavaRiverPlatform_Update(struct Solid* p);
static void LavaRiverPlatform_Die(struct Solid* p);

// clang-format off
const SolidRoutine gLavaRiverPlatformRoutine = {
    [ENTITY_INIT] =      (SolidFunc)LavaRiverPlatform_Init,
    [ENTITY_UPDATE] =    (SolidFunc)LavaRiverPlatform_Update,
    [ENTITY_DIE] =       (SolidFunc)LavaRiverPlatform_Die,
    [ENTITY_DISAPPEAR] = (SolidFunc)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateLavaRiverPlatform(u32 x, u32 y) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_RIVER_PLATFORM);
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

// --------------------------------------------

static void LavaRiverPlatform_Init(struct Solid8Object* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitMode[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = (struct Rect*)&sSize;
  (p->s).physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  p->y = PIXEL(40);
  LavaRiverPlatform_Update((void*)p);
}

// --------------------------------------------

static void nop_080ccef8(struct Solid* p);
void FUN_080ccefc(struct Solid* p);
void FUN_080cd03c(struct Solid* p);

static void LavaRiverPlatform_Update(struct Solid* p) {
  static const SolidFunc sUpdates1[2] = {
      nop_080ccef8,
      nop_080ccef8,
  };
  static const SolidFunc sUpdates2[2] = {
      FUN_080ccefc,
      FUN_080cd03c,
  };
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void LavaRiverPlatform_Die(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ccef8(struct Solid* p) { return; }

INCASM("asm/solid/lava_river_platform.inc");

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(24), PIXEL(48), PIXEL(48)};

static const u8 sInitMode[4] = {1, 0, 0, 0};
