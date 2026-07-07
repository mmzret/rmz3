#include "collision.h"
#include "global.h"
#include "solid.h"

// Tretista

typedef struct {
  ENTITY_HDR;
  ENTITY_SPRITE;
  struct Body body;  // 0x74
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[12];
  u8 unk_c0;
} Solid13Object;
static_assert(sizeof(Solid13Object) == sizeof(struct Solid));

static const struct Rect sSize;

static const struct Collision Collision_ARRAY_0837025c[2];
static const struct Collision Collision_ARRAY_0837028c[2];

static void Solid13_Init(Solid13Object* p);
static void Solid13_Update(struct Entity* p);
static void Solid13_Die(struct Entity* p);

// clang-format off
const SolidRoutine gSolid13Routine = {
    [ENTITY_INIT] =      (void*)Solid13_Init,
    [ENTITY_UPDATE] =    (void*)Solid13_Update,
    [ENTITY_DIE] =       (void*)Solid13_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Solid* CreateSolid13(struct Entity* e, Coords32* c, Coords32* d, u8 n) {
  struct Entity* p = AllocEntityLast(gSolidHeaderPtr);
  if (p != NULL) {
    INIT_SOLID_ROUTINE(p, SOLID_UNK_013);
    p->work[0] = n;
    p->coord.x = c->x, p->coord.y = c->y;
    p->d.x = d->x, p->d.y = d->y;
    p->unk_28 = e;
  }
  return (void*)p;
}

static void Solid13_Init(Solid13Object* p) {
  p->flags2 |= ENTI_PHYSICS;
  p->size = &sSize;
  p->physicsAttr = SHAPE_BLOCK;
  p->flags |= FLIPABLE;
  p->flags &= ~DISPLAY;
  InitNonAffineMotion((void*)p);
  INIT_BODY(p, &Collision_ARRAY_0837025c[0], 1, NULL);
  INIT_BODY(p, &Collision_ARRAY_0837028c[0], 1, NULL);
  p->unk_c0 = 0;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Solid13_Update((void*)p);
}

static void _Solid13_Update(Object* p);

static void Solid13_Update(struct Entity* p) {
  static const SolidFunc sUpdates[1] = {
      (SolidFunc)_Solid13_Update,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void Solid13_Die(struct Entity* p) { SET_SOLID_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

// 0x080ce438
static void _Solid13_Update(Object* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      struct Entity* e = (struct Entity*)(p->s).unk_28;
      (p->s).coord = e->coord;
      if (e->mode[0] >= ENTITY_DIE) {
        SET_SOLID_ROUTINE(p, ENTITY_DIE);
        EXIT_BODY(p);
        Solid13_Die((void*)p);
      }
      if ((p->body).status & BODY_STATUS_B2) {
        SET_SOLID_ROUTINE(p, ENTITY_DIE);
        EXIT_BODY(p);
        Solid13_Die((void*)p);
      }
      break;
    }
    default: {
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision Collision_ARRAY_0837025c[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
};

static const struct Collision Collision_ARRAY_0837028c[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(28), PIXEL(76), PIXEL(76)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(28), PIXEL(76), PIXEL(76)},
    },
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(30), PIXEL(56), PIXEL(56)};
