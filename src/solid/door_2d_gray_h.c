#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"

// Gray horizontal door

static const struct Collision sCollisions[2];

static void Solid22_Init(struct Solid* p);
static void Solid22_Update(struct Solid* p);
static void Solid22_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DGrayHRoutine = {
    [ENTITY_INIT] =      Solid22_Init,
    [ENTITY_UPDATE] =    Solid22_Update,
    [ENTITY_DIE] =       Solid22_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void Solid22_Init(struct Solid* p) {
  LOAD_STATIC_GRAPHIC(SM120_DOOR_2D_GRAY_H);
  (p->s).coord.x -= PIXEL(7);
  (p->s).coord.y += PIXEL(9);
  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  Solid22_Update(p);
}

// --------------------------------------------

void FUN_080d7eb8(struct Solid* p);
void openStageDoor_080d7f0c(struct Solid* p);
void FUN_080d8088(struct Solid* p);
void FUN_080d820c(struct Solid* p);

static void Solid22_Update(struct Solid* p) {
  static SolidFunc const sUpdates[] = {
      FUN_080d7eb8,
      openStageDoor_080d7f0c,
      FUN_080d8088,
      FUN_080d820c,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid22_Die(struct Solid* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

INCASM("asm/solid/unk_22.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(32), PIXEL(1), PIXEL(36), PIXEL(36)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
