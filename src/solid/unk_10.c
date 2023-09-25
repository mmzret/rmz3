#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

static const struct Collision Collision_ARRAY_08370108[2];
static const struct Collision Collision_ARRAY_08370138[2];

static void Solid10_Init(struct Solid* p);
static void Solid10_Update(struct Solid* p);
void Solid10_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid10Routine = {
    [ENTITY_INIT] =      Solid10_Init,
    [ENTITY_MAIN] =      Solid10_Update,
    [ENTITY_DIE] =       Solid10_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

static void Solid10_Init(struct Solid* p) {
  struct Body* body;
  struct Coord* velocity;

  if (GetMetatileAttr((p->s).coord.x, (p->s).coord.y) == 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (p->s).flags |= COLLIDABLE;

  body = &p->body;
  InitBody(body, Collision_ARRAY_08370108, &(p->s).coord, 0);
  body->parent = (struct CollidableEntity*)p;
  body->fn = NULL;

  velocity = &(p->s).d;
  velocity->x = velocity->y = 0;
  (p->s).coord.x += PIXEL(8);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y) + 1;
  SET_SOLID_ROUTINE(p, ENTITY_MAIN);
  Solid10_Update(p);
}

// --------------------------------------------

static void Solid10_Update(struct Solid* p) {
  if ((p->body).status & BODY_STATUS_B2) {
    struct Zero_b4* b4 = &pZero2->unk_b4;
    if ((b4->status).body != BODY_CHIP_LIGHT) {
      struct Body* body;

      (p->s).flags |= COLLIDABLE;

      body = &p->body;
      InitBody(body, Collision_ARRAY_08370138, &(p->s).coord, 0);
      body->parent = (struct CollidableEntity*)p;
      body->fn = NULL;

      (p->s).flags |= DISPLAY;
      (p->s).flags |= FLIPABLE;
      InitNonAffineMotion(&p->s);
      SetMotion(&p->s, MOTION(SM068_OLD_RESIDENTIAL_FALL_ROCK, 0) | (p->s).work[0]);
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Solid10_Die(p);
    }
  }
}

INCASM("asm/solid/unk_10.inc");

// --------------------------------------------

static const struct Collision Collision_ARRAY_08370108[2] = {
    [0] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0500, 0x2200, 0x0C00},
    },
    [1] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

static const struct Collision Collision_ARRAY_08370138[2] = {
    [0] = {
      kind : DDP,
      layer : 1,
      special : 0,
      damage : 1,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x1000, 0x0800, 0x1200},
    },
    [1] = {
      kind : DRP,
      layer : 1,
      special : 0,
      damage : 1,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};

// --------------------------------------------

const struct Rect Rect_08370168 = {
    0x0,
    0x800,
    0x2000,
    0x1000,
};

// --------------------------------------------

const s32 s32_ARRAY_08370170[8] = {
    -1, 0, 1, 0, -1, 0, 1, 0,
};

const s32 s32_ARRAY_08370190[8] = {
    -1, 1, 0, -1, 1, -1, 0, 1,
};
