#include "collision.h"
#include "global.h"
#include "projectile.h"

static const u8 sInitModes[4];
static const struct Collision sCollisions[4];

static void EarShot_Init(struct Projectile* p);
static void EarShot_Update(struct Projectile* p);
static void EarShot_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gEarShotRoutine = {
    [ENTITY_INIT] =      EarShot_Init,
    [ENTITY_UPDATE] =    EarShot_Update,
    [ENTITY_DIE] =       EarShot_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

void createEarShot(s32 x, s32 y, u8 n, bool8 is_big) {
  struct Projectile* p = (struct Projectile*)AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 11);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = !!is_big;
    (p->s).work[2] = n;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

// 0x0809f2f0
static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

// --------------------------------------------

static void EarShot_Init(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &sCollisions[(p->s).work[0] == 1], 1, onCollision);
  EarShot_Update(p);
}

// --------------------------------------------

static void nop_0809f3d0(struct Projectile* p);
static void FUN_0809f3d4(struct Projectile* p);

static void EarShot_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates1[1] = {
      nop_0809f3d0,
  };
  static const ProjectileFunc sUpdates2[1] = {
      FUN_0809f3d4,
  };
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void EarShot_Die(struct Projectile* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_0809f3d0(struct Projectile* p) { return; }

NAKED static void FUN_0809f3d4(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _0809F3E4\n\
	cmp r0, #1\n\
	beq _0809F44A\n\
	b _0809F47C\n\
_0809F3E4:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _0809F3F6\n\
	movs r1, #0x94\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _0809F3FE\n\
_0809F3F6:\n\
	ldr r1, _0809F418 @ =0x00002501\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_0809F3FE:\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #0xb\n\
	ldr r1, _0809F41C @ =0xFFFFFC00\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r2, #0\n\
	beq _0809F420\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _0809F426\n\
	.align 2, 0\n\
_0809F418: .4byte 0x00002501\n\
_0809F41C: .4byte 0xFFFFFC00\n\
_0809F420:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0809F426:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0809F44A:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _0809F484 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #7\n\
	cmp r0, r1\n\
	bls _0809F47C\n\
	ldr r1, _0809F488 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_0809F47C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809F484: .4byte gStageRun+232\n\
_0809F488: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision sCollisions[4] = {
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
      range : {0x1200, 0x0000, 0x2600, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x2400, 0x0000, 0x4200, 0x0C00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x3E00, -0x0B00, 0x2400, 0x0A00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x3E00, 0x0B00, 0x2400, 0x0A00},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
