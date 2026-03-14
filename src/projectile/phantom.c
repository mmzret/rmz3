#include "collision.h"
#include "global.h"
#include "projectile.h"

static void PhantomProjectile_Init(struct Projectile* p);
static void PhantomProjectile_Update(struct Projectile* p);
void PhantomProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gPhantomProjectileRoutine = {
    [ENTITY_INIT] =      PhantomProjectile_Init,
    [ENTITY_UPDATE] =    PhantomProjectile_Update,
    [ENTITY_DIE] =       PhantomProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

static const struct Collision sCollisions[8] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(5), PIXEL(10), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(24), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 5,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 5,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(20), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 5,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      atkType : 0x00,
      comboLv : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(8)},
    },
};

// --------------------------------------------

static void FUN_080af114(struct Projectile* p);
static void FUN_080af1b4(struct Projectile* p);
static void FUN_080af214(struct Projectile* p);
static void FUN_080af250(struct Projectile* p);
void FUN_080af70c(struct Projectile* p);
static void FUN_080af2b0(struct Projectile* p);

static void PhantomProjectile_Init(struct Projectile* p) {
  // clang-format off
  static const ProjectileFunc sInitializers[6] = {
    FUN_080af114,
    FUN_080af1b4,
    FUN_080af214,
    FUN_080af250,
    FUN_080af70c,
    FUN_080af2b0,
  };
  // clang-format on
  (sInitializers[(p->s).work[0]])(p);
}

NAKED static void FUN_080af114(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, [r4, #0x28]\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _080AF15C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AF158 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080AF1A2\n\
	.align 2, 0\n\
_080AF158: .4byte gProjectileFnTable\n\
_080AF15C:\n\
	ldrh r1, [r1, #0xe]\n\
	ldr r0, _080AF1A8 @ =0x00000101\n\
	cmp r1, r0\n\
	bne _080AF1A2\n\
	ldr r1, _080AF1AC @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x19\n\
	strb r0, [r1]\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080AF1B0 @ =0x00008603\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl PhantomProjectile_Update\n\
_080AF1A2:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080AF1A8: .4byte 0x00000101\n\
_080AF1AC: .4byte gProjectileFnTable\n\
_080AF1B0: .4byte 0x00008603\n\
 .syntax divided\n");
}

static void FUN_080af1b4(struct Projectile* p) {
  INIT_BODY(p, &sCollisions[0], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  InitRotatableMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af214(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  InitRotatableMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af250(struct Projectile* p) {
  INIT_BODY(p, &sCollisions[4], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  InitNonAffineMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

static void FUN_080af2b0(struct Projectile* p) {
  INIT_BODY(p, &sCollisions[6], 0, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).flags &= ~DISPLAY;
  (p->s).flags |= FLIPABLE;
  PhantomProjectile_Update(p);
}

// --------------------------------------------

static void FUN_080af32c(struct Projectile* p);
void FUN_080af61c(struct Projectile* p);
void FUN_080af8b0(struct Projectile* p);
void FUN_080af9b0(struct Projectile* p);
void FUN_080af748(struct Projectile* p);
void FUN_080afb1c(struct Projectile* p);

static void PhantomProjectile_Update(struct Projectile* p) {
  // clang-format off
  static const ProjectileFunc sUpdates[6] = {
    FUN_080af32c,
    FUN_080af61c,
    FUN_080af8b0,
    FUN_080af9b0,
    FUN_080af748,
    FUN_080afb1c,
  };
  // clang-format on
  (sUpdates[(p->s).work[0]])(p);
  UpdateMotionGraphic(&p->s);
}

void FUN_080af368(struct Projectile* p);
void FUN_080af3ec(struct Projectile* p);
void FUN_080af46c(struct Projectile* p);

static void FUN_080af32c(struct Projectile* p) {
  static const ProjectileFunc PTR_ARRAY_0836d418[3] = {
      FUN_080af368,
      FUN_080af3ec,
      FUN_080af46c,
  };

  if (((p->s).unk_28)->mode[0] >= 2) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }
  (PTR_ARRAY_0836d418[(p->s).mode[1]])(p);
}

INCASM("asm/projectile/phantom.inc");

void FUN_080af518(struct Projectile* p);
void FUN_080af5cc(struct Projectile* p);
void FUN_080af5f4(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836d424[3] = {
    FUN_080af518,
    FUN_080af5cc,
    FUN_080af5f4,
};

void FUN_080af634(struct Projectile* p);
void FUN_080af65c(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836d430[2] = {
    FUN_080af634,
    FUN_080af65c,
};

void FUN_080af760(struct Projectile* p);
void FUN_080af7b0(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836d438[2] = {
    FUN_080af760,
    FUN_080af7b0,
};

void FUN_080af8c8(struct Projectile* p);
void FUN_080af8e8(struct Projectile* p);
void nop_080af9ac(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836d440[3] = {
    FUN_080af8c8,
    FUN_080af8e8,
    nop_080af9ac,
};

void FUN_080af9c8(struct Projectile* p);
void FUN_080af9f4(struct Projectile* p);

static const ProjectileFunc PTR_ARRAY_0836d44c[2] = {
    FUN_080af9c8,
    FUN_080af9f4,
};
