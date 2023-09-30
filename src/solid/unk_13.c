#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Rect sSize;

static const struct Collision Collision_ARRAY_0837025c[2];
static const struct Collision Collision_ARRAY_0837028c[2];

static void Solid13_Init(struct Solid* p);
void Solid13_Update(struct Solid* p);
void Solid13_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid13Routine = {
    [ENTITY_INIT] =      Solid13_Init,
    [ENTITY_MAIN] =      Solid13_Update,
    [ENTITY_DIE] =       Solid13_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

struct Solid* CreateSolid13(struct Entity* e, struct Coord* c, struct Coord* d, u8 n) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_013);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).d.x = d->x;
    (p->s).d.y = d->y;
    (p->s).unk_28 = e;
  }
  return p;
}

static void Solid13_Init(struct Solid* p) {
  (p->s).flags2 |= ENTITY_HAZARD;
  (p->s).size = &sSize;
  (p->s).hazardAttr = METATILE_GROUND;
  (p->s).flags |= FLIPABLE;
  (p->s).flags &= ~DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &Collision_ARRAY_0837025c[0], 1, NULL);
  INIT_BODY(p, &Collision_ARRAY_0837028c[0], 1, NULL);
  (p->props).raw[12] = 0;
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  Solid13_Update(p);
}

INCASM("asm/solid/unk_13.inc");

// --------------------------------------------

void FUN_080ce438(struct Solid* p);

const SolidFunc sSolid13Updates[1] = {
    FUN_080ce438,
};

// --------------------------------------------

static const struct Collision Collision_ARRAY_0837025c[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x1400, 0x1400},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x05,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x1400, 0x1400},
    },
};

static const struct Collision Collision_ARRAY_0837028c[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 5,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x4C00, 0x4C00},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x01,
      hardness : METAL,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1C00, 0x4C00, 0x4C00},
    },
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(30), PIXEL(56), PIXEL(56)};
