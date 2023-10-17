#include "collision.h"
#include "global.h"
#include "solid.h"
#include "vfx.h"

static const u8 sInitModes[2];
static const struct Collision sCollisions[5];
static const motion_t sMotions[4];

static void IcebonIce_Init(struct Solid* p);
static void IcebonIce_Update(struct Solid* p);
static void IcebonIce_Die(struct Solid* p);

// clang-format off
const SolidRoutine gIcebonIceRoutine = {
    [ENTITY_INIT] =      IcebonIce_Init,
    [ENTITY_UPDATE] =    IcebonIce_Update,
    [ENTITY_DIE] =       IcebonIce_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  // nop
  return;
}

static void IcebonIce_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &sCollisions[0], 8, onCollision);
  (p->props.icebonIce).y = (p->s).coord.y;
  IcebonIce_Update(p);
}

// --------------------------------------------

void FUN_080ca700(struct Solid* p);
static void nop_080ca6fc(struct Solid* p);
void FUN_080ca76c(struct Solid* p);

void FUN_080ca7d8(struct Solid* p);
void FUN_080ca880(struct Solid* p);
void FUN_080ca988(struct Solid* p);
void FUN_080caafc(struct Solid* p);
void FUN_080cab58(struct Solid* p);
void FUN_080cabe8(struct Solid* p);

static void IcebonIce_Update(struct Solid* p) {
  // clang-format off
  static const SolidFunc sUpdates1[6] = {
      FUN_080ca700,
      nop_080ca6fc,
      nop_080ca6fc,
      FUN_080ca76c,
      nop_080ca6fc,
      nop_080ca6fc,
  };
  // clang-format on

  // clang-format off
  static const SolidFunc sUpdates2[6] = {
      FUN_080ca7d8,
      FUN_080ca880,
      FUN_080ca988,
      FUN_080caafc,
      FUN_080cab58,
      FUN_080cabe8,
  };
  // clang-format on

  if ((p->body).status & BODY_STATUS_DEAD) {
    (p->s).flags2 &= ~ENTITY_HAZARD;
    SET_SOLID_ROUTINE(p, ENTITY_DIE);
    IcebonIce_Die(p);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void IcebonIce_Die(struct Solid* p) {
  struct Coord c;

  PlaySound(SE_ICE_BREAK);
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;

  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y + PIXEL(16);
  FUN_080b81a0((struct CollidableEntity*)p, &c, (motion_t*)sMotions, 4);
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080ca6fc(struct Solid* p) {
  // nop
  return;
}

// --------------------------------------------

INCASM("asm/solid/icebon_ice.inc");

static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0700, 0x1C00, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0400, 0x1C00, 0x1800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 4,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0200, 0x1400, 0x1400},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0200, 0x1400, 0x1400},
    },
};

const struct Rect Rect_0836fd58 = {PIXEL(0), -PIXEL(3), PIXEL(24), PIXEL(16)};

static const u8 sInitModes[2] = {0, 3};

static const motion_t sMotions[4] = {
    MOTION(SM017_ICEBON_ICE, 6),
    MOTION(SM017_ICEBON_ICE, 7),
    MOTION(SM017_ICEBON_ICE, 8),
    MOTION(SM017_ICEBON_ICE, 6),
};
