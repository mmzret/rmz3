#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Collision sCollision;
static const u8 sInitModes[4];
static const struct Rect sSize;

static void Solid50_Init(struct Solid* p);
static void Solid50_Update(struct Solid* p);
static void Solid50_Die(struct Solid* p);
static void Solid50_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gStructuralSteelRoutine = {
    [ENTITY_INIT] =      Solid50_Init,
    [ENTITY_UPDATE] =    Solid50_Update,
    [ENTITY_DIE] =       Solid50_Die,
    [ENTITY_DISAPPEAR] = Solid50_Disappear,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateStructuralSteel(s32 x, s32 y, u8 r2, u8 r3, u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_STRUCTURAL_STEEL);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).work[2] = r2;
    (p->s).work[3] = r3;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_coord.x = x;
    (p->s).unk_coord.y = y;
  }
  return p;
}

static void FUN_080df5ac(struct Entity* e) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_STRUCTURAL_STEEL);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 2;
    (p->s).unk_28 = e;
  }
}

// --------------------------------------------

static void Solid50_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);

  if ((p->s).work[0] != 2) {
    FUN_080df5ac(&p->s);
  } else {
    INIT_BODY(p, &sCollision, 1, NULL);
    (p->s).flags2 |= ENTITY_HAZARD;
    (p->s).size = &sSize;
    (p->s).hazardAttr = 0x2001;
  }

  Solid50_Update(p);
}

// --------------------------------------------

void FUN_080df6d8(struct Solid* p);
void FUN_080df768(struct Solid* p);

static void Solid50_Update(struct Solid* p) {
  static const SolidFunc sUpdates[2] = {
      FUN_080df6d8,
      FUN_080df768,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid50_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static void Solid50_Disappear(struct Solid* p) {
  (p->s).flags2 &= ~ENTITY_HAZARD;
  DeleteSolid(p);
}

// --------------------------------------------

INCASM("asm/solid/structural_steel.inc");

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 255,
  remaining : 0,
  layer : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(52), PIXEL(10)},
};

static const u8 sInitModes[4] = {0, 0, 1, 0};
static const struct Rect sSize = {PIXEL(0), PIXEL(8), PIXEL(52), PIXEL(16)};
