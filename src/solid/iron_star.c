#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

/*
  ファントムのミニゲームに出てくるトゲ付き鉄球
*/

void initIronStar(struct Solid* p);
void ironStarAI(struct Solid* p);
void killIronStar(struct Solid* p);

// clang-format off
const SolidRoutine gIronStarRoutine = {
    [ENTITY_INIT] =      initIronStar,
    [ENTITY_UPDATE] =    ironStarAI,
    [ENTITY_DIE] =       killIronStar,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

void CreateIronStar(struct Entity* e, s32 x, s32 y) {
  struct Solid* p = (struct Solid*)AllocEntityFirst(gSolidHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 30;
    INIT_SOLID_ROUTINE(p, SOLID_UNK_004);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).unk_28 = e;
  }
}

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  // NOP
  return;
}

INCASM("asm/solid/iron_star.inc");

// --------------------------------------------

void nop_080cbcc0(struct Solid* p);

const SolidFunc PTR_ARRAY_0836fe00[2] = {
    nop_080cbcc0,
    nop_080cbcc0,
};

// --------------------------------------------

void FUN_080cbcc4(struct Solid* p);
void FUN_080cbd6c(struct Solid* p);

const SolidFunc PTR_ARRAY_0836fe08[2] = {
    FUN_080cbcc4,
    FUN_080cbd6c,
};

// --------------------------------------------

const struct Collision Collision_ARRAY_0836fe10[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0600, 0x1A00, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0A00, 0x2000, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x1800},
    },
};

const struct Coord Coord_0836fe58 = {-0x04000000, 0x10002000};
