#include "collision.h"
#include "global.h"
#include "solid.h"

static void Solid47_Init(struct Solid* p);
static void Solid47_Update(struct Solid* p);
static void Solid47_Die(struct Solid* p);

// clang-format off
const SolidRoutine gAnatreCubeRoutine = {
    [ENTITY_INIT] =      Solid47_Init,
    [ENTITY_UPDATE] =    Solid47_Update,
    [ENTITY_DIE] =       Solid47_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* FUN_080deb10(struct Coord* c) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_ANATRE_CUBE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 0;
    (p->s).unk_coord.y = (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct Solid* FUN_080deb6c(u8 r0, struct Coord* c) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_ANATRE_CUBE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 1;
    (p->s).work[1] = r0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

// --------------------------------------------

static void FUN_080dec04(struct Solid* p);
void FUN_080def4c(struct Solid* p);

static void Solid47_Init(struct Solid* p) {
  static const SolidFunc sInitializers[2] = {
      FUN_080dec04,
      FUN_080def4c,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080dec48(struct Solid* p);
void FUN_080defa8(struct Solid* p);

static void Solid47_Update(struct Solid* p) {
  static const SolidFunc sUpdates[2] = {
      FUN_080dec48,
      FUN_080defa8,
  };
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void Solid47_Die(struct Solid* p) {
  // nop
  return;
}

// --------------------------------------------

static void FUN_080dec04(struct Solid* p) {
  struct Coord* d;
  (p->s).flags |= FLIPABLE;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) - (PIXEL(32) - 1);
  d = &(p->s).d;
  d->x = d->y = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
}

INCASM("asm/solid/anatre_cube.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(RECOIL_PUSHABLE),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(4)},
    },
};

static const struct Rect sSize = {PIXEL(0), PIXEL(16), PIXEL(32), PIXEL(32)};
