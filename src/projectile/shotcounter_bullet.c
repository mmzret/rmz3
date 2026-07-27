#include "collision.h"
#include "entity.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static const struct Collision sCollisions[2];

static void ShotcounterBullet_Init(Projectile* p);
static void ShotcounterBullet_Update(Projectile* p);
void ShotcounterBullet_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gShotcounterBulletRoutine = {
    [ENTITY_INIT] =      (void*)ShotcounterBullet_Init,
    [ENTITY_UPDATE] =    (void*)ShotcounterBullet_Update,
    [ENTITY_DIE] =       (void*)ShotcounterBullet_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* CreateShotcounterBullet(Coords32* c, Coords32* d, u8 r2, u8 r3) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, PROJECTILE_SHOTCOUNTER_BULLET);
    p->work[0] = r2;
    p->work[1] = r3;
    p->coord.x = c->x;
    p->coord.y = c->y;
    p->d.x = d->x;
    p->d.y = d->y;
  }
  return p;
}

NAKED static void ShotcounterBullet_Init(Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r7, #0\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809CDA8 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldrb r3, [r6, #0x10]\n\
	cmp r3, #0\n\
	bne _0809CDAC\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r3, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _0809CDCE\n\
	.align 2, 0\n\
_0809CDA8: .4byte sCollisions\n\
_0809CDAC:\n\
	movs r3, #1\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r3, [r0]\n\
	adds r4, r6, #0\n\
	adds r4, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r4]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r4]\n\
_0809CDCE:\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r3, [r0]\n\
	movs r0, #0xff\n\
	strb r0, [r6, #0x12]\n\
	ldr r1, _0809CE00 @ =gProjectileFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #0\n\
	strb r1, [r6, #0xd]\n\
	strb r0, [r6, #0xe]\n\
	strb r0, [r6, #0xf]\n\
	adds r0, r6, #0\n\
	bl ShotcounterBullet_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CE00: .4byte gProjectileFnTable\n\
   .syntax divided\n");
}

// --------------------------------------------

void nop_0809ceac(Projectile* p);
void FUN_0809ceb0(Projectile* p);
void FUN_0809cf98(Projectile* p);

static void ShotcounterBullet_Update(Projectile* p) {
  static const ProjectileFunc sUpdates[] = {
      nop_0809ceac,
      FUN_0809ceb0,
      FUN_0809cf98,
  };
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    ShotcounterBullet_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

INCASM("asm/projectile/shotcounter_bullet_a.inc");

void nop_0809ceac(Projectile* p) {
}

INCASM("asm/projectile/shotcounter_bullet_b.inc");

void FUN_0809cf98(Projectile* p) {
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};
