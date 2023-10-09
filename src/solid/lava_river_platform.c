#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Rect sSize;
static const u8 sInitMode[4];

static void LavaRiverPlatform_Init(struct Solid* p);
static void LavaRiverPlatform_Update(struct Solid* p);
static void LavaRiverPlatform_Die(struct Solid* p);

// clang-format off
const SolidRoutine gLavaRiverPlatformRoutine = {
    [ENTITY_INIT] =      LavaRiverPlatform_Init,
    [ENTITY_UPDATE] =    LavaRiverPlatform_Update,
    [ENTITY_DIE] =       LavaRiverPlatform_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateLavaRiverPlatform(u32 x, u32 y) {
  struct Solid* s = (struct Solid*)AllocEntityLast(gSolidHeaderPtr);
  if (s != NULL) {
    (s->s).taskCol = 30;
    INIT_SOLID_ROUTINE(s, SOLID_LAVA_RIVER_PLATFORM);
    (s->s).tileNum = 0;
    (s->s).palID = 0;
    (s->s).flags2 |= WHITE_PAINTABLE;
    (s->s).invincibleID = (s->s).uniqueID;
    (s->s).work[0] = 0;
    (s->s).coord.x = x;
    (s->s).coord.y = y;
  }
  return;
}

// --------------------------------------------

static void LavaRiverPlatform_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitMode[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = (struct Rect*)&sSize;
  (p->s).hazardAttr = 0x2001;
  (p->props).solid8.y = PIXEL(40);
  LavaRiverPlatform_Update(p);
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
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ccef8(struct Solid* p) { return; }

INCASM("asm/solid/lava_river_platform.inc");

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(24), PIXEL(48), PIXEL(48)};

static const u8 sInitMode[4] = {1, 0, 0, 0};
