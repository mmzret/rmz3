#include "collision.h"
#include "global.h"
#include "solid.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  s32 y;
  u8 unk_04[12];
} Solid8Object;
static_assert(sizeof(Solid8Object) == sizeof(struct Solid));

static const struct Rect sSize;
static const u8 sInitMode[4];

static void LavaRiverPlatform_Init(Solid8Object* p);
static void LavaRiverPlatform_Update(Solid8Object* p);
static void LavaRiverPlatform_Die(Solid8Object* p);

// clang-format off
const SolidRoutine gLavaRiverPlatformRoutine = {
    [ENTITY_INIT] =      (void*)LavaRiverPlatform_Init,
    [ENTITY_UPDATE] =    (void*)LavaRiverPlatform_Update,
    [ENTITY_DIE] =       (void*)LavaRiverPlatform_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateLavaRiverPlatform(u32 x, u32 y) {
  Solid8Object* p = AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_RIVER_PLATFORM);
    p->work[0] = 0;
    (p->coord).x = x, (p->coord).y = y;
  }
}

// --------------------------------------------

static void LavaRiverPlatform_Init(Solid8Object* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitMode[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  p->flags2 |= ENTI_PHYSICS;
  p->size = (struct Rect*)&sSize;
  p->physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  p->y = PIXEL(40);
  LavaRiverPlatform_Update(p);
}

static void nop_080ccef8(Solid8Object* p);
void FUN_080ccefc(Solid8Object* p);
void FUN_080cd03c(Solid8Object* p);

static void LavaRiverPlatform_Update(Solid8Object* p) {
  static void (*const sUpdates1[2])(Solid8Object*) = {
      nop_080ccef8,
      nop_080ccef8,
  };
  static void (*const sUpdates2[2])(Solid8Object*) = {
      FUN_080ccefc,
      FUN_080cd03c,
  };
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void LavaRiverPlatform_Die(Solid8Object* p) {
  p->flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ccef8(Solid8Object* _) {}

INCASM("asm/solid/lava_river_platform.inc");

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(24), PIXEL(48), PIXEL(48)};

static const u8 sInitMode[4] = {1, 0, 0, 0};
