#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "projectile.h"
#include "story.h"

static void Projectile8_Init(struct Projectile* p);
static void Projectile8_Update(struct Projectile* p);
static void Projectile8_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile8Routine = {
    [ENTITY_INIT] =      Projectile8_Init,
    [ENTITY_UPDATE] =    Projectile8_Update,
    [ENTITY_DIE] =       Projectile8_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void CreateProjectile8(s32 x, s32 y) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 8);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

static const struct Collision sCollisions[2];

NAKED static void Projectile8_Init(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	adds r4, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0809E324 @ =0x00001709\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r6, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	movs r0, #1\n\
	mov r8, r0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r6, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r5, r4, #0\n\
	adds r5, #0x74\n\
	ldr r1, _0809E328 @ =0x0836ACE0\n\
	adds r2, #0xa\n\
	adds r0, r5, #0\n\
	movs r3, #8\n\
	bl InitBody\n\
	str r4, [r5, #0x2c]\n\
	str r6, [r5, #0x24]\n\
	str r6, [r4, #0x60]\n\
	ldr r1, _0809E32C @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Projectile8_Update\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E324: .4byte 0x00001709\n\
_0809E328: .4byte sCollisions\n\
_0809E32C: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

static void Projectile8_Update(struct Projectile* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  UpdateMotionGraphic(&p->s);
  if ((p->s).mode[2] == 0) {
    if ((p->s).d.y < PIXEL(7)) (p->s).d.y += (PIXEL(1) / 4);
    (p->s).coord.y += (p->s).d.y;
    if ((((p->body).status & BODY_STATUS_B2)) || (FUN_080098a4((p->s).coord.x, (p->s).coord.y) != 0)) {
      SetMotion(&p->s, MOTION(SM023_GYRO_CANNON, 10));
      UpdateMotionGraphic(&p->s);
      PlaySound(SE_UNK_35);
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[2]++;
    }
  } else {
    if ((p->s).motion.cmdIdx == 2) {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
    }
    if ((p->s).motion.state == MOTION_END) {
      SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
      Projectile8_Die(p);
    }
  }
}

static void Projectile8_Die(struct Projectile* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0C00, 0x1A00, 0x1C00},
    },
};
