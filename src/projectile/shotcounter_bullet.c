#include "collision.h"
#include "entity.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static const struct Collision sCollisions[2];

static void ShotcounterBullet_Init(struct Projectile *p);
static void ShotcounterBullet_Update(struct Projectile *p);
void ShotcounterBullet_Die(struct Projectile *p);

// clang-format off
const ProjectileRoutine gShotcounterBulletRoutine = {
    [ENTITY_INIT] =      ShotcounterBullet_Init,
    [ENTITY_MAIN] =      ShotcounterBullet_Update,
    [ENTITY_DIE] =       ShotcounterBullet_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile *CreateShotcounterBullet(struct Coord *c, struct Coord *d, u8 r2, u8 r3) {
  struct Projectile *p = (struct Projectile *)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, PROJECTILE_SHOTCOUNTER_BULLET);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = r2;
    (p->s).work[1] = r3;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).d.x = d->x;
    (p->s).d.y = d->y;
  }
  return p;
}

NAKED static void ShotcounterBullet_Init(struct Projectile *p) {
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

void nop_0809ceac(struct Projectile *p);
void FUN_0809ceb0(struct Projectile *p);
void FUN_0809cf98(struct Projectile *p);

static void ShotcounterBullet_Update(struct Projectile *p) {
  static const ProjectileFunc sUpdates[] = {
      nop_0809ceac,
      FUN_0809ceb0,
      FUN_0809cf98,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    ShotcounterBullet_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

INCASM("asm/projectile/shotcounter_bullet.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x80,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
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
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};
