#include "collision.h"
#include "global.h"
#include "solid.h"

// 溶岩の間欠泉の上にある岩の足場

static const u8 sInitModes[4];
static const struct Rect sSize;

bool8 FUN_080cc814(struct Entity* p);

// ------------------------------------------------------------------------------------------------------------------------------------

static void Solid6_Init(struct Solid* p);
static void Solid6_Update(struct Solid* p);
static void Solid6_Die(struct Solid* p);

// clang-format off
const SolidRoutine gLavaGeyserPlatformRoutine = {
    [ENTITY_INIT] =      Solid6_Init,
    [ENTITY_UPDATE] =    Solid6_Update,
    [ENTITY_DIE] =       Solid6_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateLavaGeyserPlatform(struct Solid* s) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_LAVA_GEYSER_PLATFORM);
    (p->s).work[0] = 0;
    (p->s).unk_28 = &s->s;
  }
}

static void Solid6_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = &sSize;
  (p->s).physicsAttr = SHAPE_BLOCK;
  Solid6_Update(p);
}

// --------------------------------------------

static void nop_080cc69c(struct Solid* p);
static void FUN_080cc6a0(struct Solid* p);

static void Solid6_Update(struct Solid* p) {
  static const SolidFunc sUpdates1[1] = {
      nop_080cc69c,
  };
  static const SolidFunc sUpdates2[1] = {
      FUN_080cc6a0,
  };

  if (((p->s).unk_28)->mode[0] == 4) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

static void Solid6_Die(struct Solid* p) {
  (p->s).flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

static void nop_080cc69c(struct Solid* p) { return; }

static void FUN_080cc6a0(struct Solid* p) {
  struct Entity* anchor = (p->s).unk_28;
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(&p->s, MOTION(SM058_VOLCANO_RISING_PLATFORM, 1));
      (p->s).mode[2]++;
    case 1:
      if (FUN_080cc814(anchor)) {
        (p->s).mode[2]++;
      }
      UpdateSpriteAnimation(&p->s);
      break;
    case 2:
      SetSpriteAnimation(&p->s, MOTION(SM058_VOLCANO_RISING_PLATFORM, 0));
      (p->s).mode[2]++;
    case 3:
      if (!FUN_080cc814(anchor)) {
        (p->s).mode[2] = 0;
      }
      UpdateSpriteAnimation(&p->s);
      break;
  }
  (p->s).coord.x = anchor->coord.x;
  (p->s).coord.y = anchor->coord.y - 0xF00;
}

// --------------------------------------------

static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(40), PIXEL(16)};

static const u8 sInitModes[4] = {0, 0, 0, 0};
