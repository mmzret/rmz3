#include "collision.h"
#include "global.h"
#include "solid.h"

static const struct Rect sSize;

static const struct Collision Collision_ARRAY_0837025c[2];
static const struct Collision Collision_ARRAY_0837028c[2];

static void Solid13_Init(struct Solid* p);
static void Solid13_Update(struct Solid* p);
static void Solid13_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid13Routine = {
    [ENTITY_INIT] =      Solid13_Init,
    [ENTITY_UPDATE] =    Solid13_Update,
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
    (p->s).flags2 |= WHITE_PAINTABLE;
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
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  Solid13_Update(p);
}

// --------------------------------------------

static void FUN_080ce438(struct Solid* p);

static void Solid13_Update(struct Solid* p) {
  static const SolidFunc sUpdates[1] = {
      FUN_080ce438,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid13_Die(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
  return;
}

// --------------------------------------------

NAKED static void FUN_080ce438(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _080CE448\n\
	cmp r0, #1\n\
	beq _080CE44C\n\
	b _080CE4C6\n\
_080CE448:\n\
	movs r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080CE44C:\n\
	ldr r0, [r4, #0x28]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r2, [r0, #0x58]\n\
	str r1, [r4, #0x54]\n\
	str r2, [r4, #0x58]\n\
	ldrb r0, [r0, #0xc]\n\
	adds r5, r4, #0\n\
	adds r5, #0x8c\n\
	cmp r0, #1\n\
	bls _080CE48E\n\
	ldr r1, _080CE4CC @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	movs r1, #0\n\
	str r1, [r5]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl Solid13_Die\n\
_080CE48E:\n\
	ldr r0, [r5]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CE4C6\n\
	ldr r1, _080CE4CC @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	movs r1, #0\n\
	str r1, [r5]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl Solid13_Die\n\
_080CE4C6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CE4CC: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision Collision_ARRAY_0837025c[2] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1400, 0x1400},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1400, 0x1400},
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
      range : {0x0000, -0x1C00, 0x4C00, 0x4C00},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      range : {0x0000, -0x1C00, 0x4C00, 0x4C00},
    },
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(30), PIXEL(56), PIXEL(56)};
