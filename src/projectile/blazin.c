#include "projectile/blazin.h"

#include "collision.h"
#include "global.h"
#include "projectile.h"

typedef void (*BlazinProjectileFunc)(BlazinProjectile*);

static const struct Collision sCollisions[14];

static void Projectile9_Init(BlazinProjectile* p);
static void Projectile9_Update(BlazinProjectile* p);
static void Projectile9_Die(BlazinProjectile* p);

// clang-format off
const ProjectileRoutine gBlazinProjectileRoutine = {
    [ENTITY_INIT] =      (void*)Projectile9_Init,
    [ENTITY_UPDATE] =    (void*)Projectile9_Update,
    [ENTITY_DIE] =       (void*)Projectile9_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

BlazinProjectile* Unused_FUN_0809e4b0(Entity* q, Coords32* c) {
  BlazinProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 9);
    p->work[0] = 0;
    p->coord = *c;
    p->unk_28 = q;
  }
  return p;
}

BlazinProjectile* FUN_0809e500(Entity* e, Coords32* c, Coords32* d) {
  BlazinProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 9);
    p->work[0] = 1;
    p->d = *d;
    p->coord = *c;
    p->unk_28 = e;
  }
  return p;
}

BlazinProjectile* FUN_0809e55c(Entity* e, Coords32* c, Coords32* c2) {
  BlazinProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 9);
    p->work[0] = 2;
    p->coord = *c;
    p->unk_coord = *c2;
    p->unk_28 = e;
  }
  return p;
}

BlazinProjectile* _createBlazinEXFireBall(Entity* e, Coords32* c, Coords32* d, u8 angle) {
  BlazinProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 9);
    p->work[0] = 3;
    p->angle_b4 = angle;
    p->coord = *c;
    p->d = *d;
    p->unk_28 = e;
  }
  return p;
}

BlazinProjectile* blazin_0809e620(Entity* e, Coords32* c, Coords32* d) {
  BlazinProjectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 9);
    p->work[0] = 4;
    p->d = *d;
    p->coord = *c;
    p->unk_28 = e;
  }
  return p;
}

// --------------------------------------------

NAKED static void Projectile9_Init(BlazinProjectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #1\n\
	movs r4, #0\n\
	movs r6, #0\n\
	orrs r1, r0\n\
	movs r0, #2\n\
	orrs r1, r0\n\
	strb r1, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0809E6BC\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809E6B8 @ =sCollisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0x10\n\
	b _0809E71E\n\
	.align 2, 0\n\
_0809E6B8: .4byte sCollisions\n\
_0809E6BC:\n\
	cmp r0, #1\n\
	bne _0809E6D4\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809E6D0 @ =0x0836ADF0\n\
	b _0809E716\n\
	.align 2, 0\n\
_0809E6D0: .4byte sCollisions+(6*24)\n\
_0809E6D4:\n\
	cmp r0, #2\n\
	bne _0809E6EC\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809E6E8 @ =0x0836ADC0\n\
	b _0809E716\n\
	.align 2, 0\n\
_0809E6E8: .4byte sCollisions+(4*24)\n\
_0809E6EC:\n\
	cmp r0, #3\n\
	bne _0809E704\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809E700 @ =0x0836ADA8\n\
	b _0809E716\n\
	.align 2, 0\n\
_0809E700: .4byte sCollisions+(3*24)\n\
_0809E704:\n\
	cmp r0, #4\n\
	bne _0809E726\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809E750 @ =0x0836AE80\n\
_0809E716:\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
_0809E71E:\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
_0809E726:\n\
	movs r0, #0xff\n\
	strb r0, [r5, #0x12]\n\
	ldr r1, _0809E754 @ =gProjectileFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #0\n\
	strb r1, [r5, #0xd]\n\
	strb r0, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	adds r0, r5, #0\n\
	bl Projectile9_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E750: .4byte sCollisions+(12*24)\n\
_0809E754: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

static void FUN_0809e7b4(BlazinProjectile* p);
void FUN_0809e7c0(BlazinProjectile* p);
void FUN_0809e9b8(BlazinProjectile* p);
void FUN_0809e9c4(BlazinProjectile* p);
void FUN_0809eadc(BlazinProjectile* p);
void FUN_0809eae8(BlazinProjectile* p);
void FUN_0809ec18(BlazinProjectile* p);
void FUN_0809ec24(BlazinProjectile* p);
void FUN_0809edfc(BlazinProjectile* p);
void FUN_0809ee08(BlazinProjectile* p);

// clang-format off
static const BlazinProjectileFunc PTR_ARRAY_ARRAY_0836ad24[5][2] = {
    {FUN_0809e7b4, FUN_0809e7c0},
    {FUN_0809e9b8, FUN_0809e9c4},
    {FUN_0809eadc, FUN_0809eae8},
    {FUN_0809ec18, FUN_0809ec24},
    {FUN_0809edfc, FUN_0809ee08},
};
// clang-format on

static void Projectile9_Update(BlazinProjectile* p) {
  // clang-format off
  static const BlazinProjectileFunc* const sUpdates[5] = {
    PTR_ARRAY_ARRAY_0836ad24[0],
    PTR_ARRAY_ARRAY_0836ad24[1],
    PTR_ARRAY_ARRAY_0836ad24[2],
    PTR_ARRAY_ARRAY_0836ad24[3],
    PTR_ARRAY_ARRAY_0836ad24[4],
  };
  // clang-format on
  ((sUpdates[p->work[0]])[p->mode[1]])(p);
}

static void Projectile9_Die(BlazinProjectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809e7b4(BlazinProjectile* p) {
  p->mode[1] = 1;
  p->mode[2] = 0;
}

INCASM("asm/projectile/blazin.inc");

// --------------------------------------------

// 0x0836ad60
static const struct Collision sCollisions[14] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 1,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0100, -0x0400, 0x1A00, 0x0E00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0A00, 0x0A00},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000004,
      range : {0x0000, -0x0700, 0x0A00, 0x1700},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [7] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x0C00, 0x0C00},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0C00, 0x0C00},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      element : ELEMENT_FLAME,
      comboLv : 0,
      remaining : 2,
      layer : 0x00000004,
      range : {0x0000, 0x0000, 0x1100, 0x1100},
    },
    [10] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1A00, 0x1400},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1A00, 0x1400},
    },
};
