#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

// SubArcadia's platform

static const struct Collision sCollisions[];
static const struct Rect sSize;
static const u8 sInitMode[];

static void Solid17_Init(Object* p);
static void Solid17_Update(struct Entity* p);
static void Solid17_Die(struct Entity* p);

// clang-format off
const SolidRoutine gSubArcadiaPlatformRoutine = {
    [ENTITY_INIT] =      (SolidFunc)Solid17_Init,
    [ENTITY_UPDATE] =    (SolidFunc)Solid17_Update,
    [ENTITY_DIE] =       (SolidFunc)Solid17_Die,
    [ENTITY_DISAPPEAR] = (SolidFunc)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x080cf098
NAKED static void onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, [r3, #0xc]\n\
	ldr r4, [r0, #0x2c]\n\
	ldr r2, [r3, #0x2c]\n\
	ldr r0, [r3, #0x14]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CF0CE\n\
	movs r0, #8\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, #0\n\
	bne _080CF0CE\n\
	ldr r0, _080CF0F4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x58]\n\
	ldr r0, [r2, #0x58]\n\
	cmp r1, r0\n\
	bgt _080CF0CE\n\
	movs r1, #1\n\
	strb r1, [r2, #0x12]\n\
	ldrb r0, [r2, #0xd]\n\
	cmp r0, #0\n\
	bne _080CF0CE\n\
	strb r1, [r2, #0xd]\n\
	strb r0, [r2, #0xe]\n\
_080CF0CE:\n\
	ldr r0, [r3, #0x14]\n\
	movs r1, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080CF0EE\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _080CF0F8 @ =0x00001106\n\
	cmp r1, r0\n\
	bne _080CF0EE\n\
	ldrb r0, [r2, #0xd]\n\
	cmp r0, #1\n\
	bne _080CF0EE\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
_080CF0EE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CF0F4: .4byte pZero2\n\
_080CF0F8: .4byte 0x00001106\n\
 .syntax divided\n");
}

// --------------------------------------------

static void Solid17_Init(Object* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitMode[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  _INIT_BODY(p, sCollisions, 1);
  p->flags2 &= ~WHITE_PAINTABLE;
  p->invincibleID = p->uniqueID;
  SET_BODY_INTERSECT_HANDLER(p, onCollision);
  p->flags2 |= ENTI_PHYSICS;
  p->size = &sSize;
  p->physicsAttr = MTATTR_CONVEYOR1 | SHAPE_BLOCK;
  p->coord.x -= PIXEL(8);
  p->coord.y -= PIXEL(8);
  p->unk_coord.x = p->coord.x;
  p->unk_coord.y = p->coord.y;
  p->work[3] = 0;
  Solid17_Update((struct Entity*)p);
}

static void nop_080cf208(void* _ UNUSED);
void FUN_080cf20c(struct Solid* p);
void FUN_080cf250(struct Solid* p);
void FUN_080cf378(struct Solid* p);

static void Solid17_Update(struct Entity* p) {
  static const SolidFunc sUpdates1[] = {
      (SolidFunc)nop_080cf208,
      (SolidFunc)nop_080cf208,
      (SolidFunc)nop_080cf208,
  };
  static const SolidFunc sUpdates2[] = {
      (SolidFunc)FUN_080cf20c,
      (SolidFunc)FUN_080cf250,
      (SolidFunc)FUN_080cf378,
  };
  (sUpdates1[(p->mode)[1]])((void*)p);
  (sUpdates2[(p->mode)[1]])((void*)p);
  p->work[3] = p->work[2];
  p->work[2] = 0;
}

static void Solid17_Die(struct Entity* p) {
  p->flags2 &= ~ENTI_PHYSICS;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080cf208(void* _ UNUSED) {}

extern const motion_t sSolid17Motions[3][4];

void FUN_080cf20c(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      SetSpriteAnimation(p, sSolid17Motions[0][(p->s).work[0]]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

INCASM("asm/solid/platform_sub_arcadia_a.inc");

// --------------------------------------------

// 0x083705BC
static const struct Collision sCollisions[3] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 255,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(12), PIXEL(30), PIXEL(32)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(14), PIXEL(30), PIXEL(28)},
    },
};

// --------------------------------------------

// clang-format off
const motion_t sSolid17Motions[3][4] = {
    {
        MOTION(SM108_SUBARCADIA_PLATFORM, 6),
        MOTION(SM108_SUBARCADIA_PLATFORM, 4),
        MOTION(SM108_SUBARCADIA_PLATFORM, 2),
        MOTION(SM108_SUBARCADIA_PLATFORM, 8),
    },
    {
        MOTION(SM108_SUBARCADIA_PLATFORM, 7),
        MOTION(SM108_SUBARCADIA_PLATFORM, 5),
        MOTION(SM108_SUBARCADIA_PLATFORM, 3),
        MOTION(SM108_SUBARCADIA_PLATFORM, 9),
    },
    {
        MOTION(SM108_SUBARCADIA_PLATFORM, 12),
        MOTION(SM108_SUBARCADIA_PLATFORM, 11),
        MOTION(SM108_SUBARCADIA_PLATFORM, 10),
        MOTION(SM108_SUBARCADIA_PLATFORM, 13),
    },
};
// clang-format on

// --------------------------------------------

// 0x0837061c
static const struct Rect sSize = {PIXEL(0), PIXEL(14), PIXEL(30), PIXEL(28)};

// 0x08370624
static const u8 sInitMode[4] = {0, 0, 0, 0};

// clang-format off
const struct Rect Rect_ARRAY_08370628[6] = {
    { PIXEL(0), PIXEL(1), -PIXEL(1), PIXEL(0) },
    { PIXEL(0), -PIXEL(1), PIXEL(1), PIXEL(0) },
    { -PIXEL(15), PIXEL(28), PIXEL(15), PIXEL(28) },
    { -PIXEL(15), PIXEL(0), -PIXEL(15), PIXEL(28) },
    { -PIXEL(15), PIXEL(0), PIXEL(15), PIXEL(0) },
    { PIXEL(15), PIXEL(0), PIXEL(15), PIXEL(28) },
}; // 0x08370628
// clang-format on
