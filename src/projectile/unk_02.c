#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

// Pantheon Aqua

static const ProjectileFunc sUpdates[1];
static const struct Collision sCollision;

static void Projectile2_Init(Projectile* p);
static void Projectile2_Update(Projectile* p);
static void Projectile2_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile2Routine = {
    [ENTITY_INIT] =      (void*)Projectile2_Init,
    [ENTITY_UPDATE] =    (void*)Projectile2_Update,
    [ENTITY_DIE] =       (void*)Projectile2_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* CreateProjectile2(Coords32* c1, Coords32* c2, u8 n) {
  Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 2);
    p->work[0] = n;
    (p->coord).x = c1->x, (p->coord).y = c1->y;
    (p->unk_coord).x = c2->x, (p->unk_coord).y = c2->y;
  }
  return p;
}

// --------------------------------------------

static void Projectile2_Init(Projectile* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  _INIT_BODY(p, &sCollision, 1);
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  Projectile2_Update(p);
}

static void _Projectile2_Update(Projectile* p);

static void Projectile2_Update(Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      _Projectile2_Update,
  };

  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    EXIT_BODY(p);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile2_Die(p);
    return;
  }
  (sUpdates[p->mode[1]])(p);
}

static void Projectile2_Die(Projectile* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// 0x0809d14c
NAKED static void _Projectile2_Update(Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0809D174\n\
	ldr r1, _0809D170 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _0809D222\n\
	.align 2, 0\n\
_0809D170: .4byte gProjectileFnTable\n\
_0809D174:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _0809D180\n\
	cmp r0, #1\n\
	beq _0809D1B2\n\
	b _0809D222\n\
_0809D180:\n\
	ldr r1, _0809D194 @ =0x0000270B\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _0809D19C\n\
	ldr r0, _0809D198 @ =0xFFFFFDC0\n\
	b _0809D1A0\n\
	.align 2, 0\n\
_0809D194: .4byte 0x0000270B\n\
_0809D198: .4byte 0xFFFFFDC0\n\
_0809D19C:\n\
	movs r0, #0x90\n\
	lsls r0, r0, #2\n\
_0809D1A0:\n\
	str r0, [r4, #0x5c]\n\
	movs r1, #0\n\
	str r1, [r4, #0x60]\n\
	movs r0, #0x78\n\
	strb r0, [r4, #0x12]\n\
	strb r1, [r4, #0x13]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0809D1B2:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x60]\n\
	adds r5, r1, r0\n\
	str r5, [r4, #0x58]\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	movs r1, #0x14\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0809D1F0\n\
	ldr r0, _0809D208 @ =gOverworld\n\
	ldr r1, _0809D20C @ =0x0002C00C\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	ldr r2, _0809D210 @ =0xFFFFF800\n\
	adds r0, r5, r2\n\
	cmp r1, r0\n\
	bge _0809D1F0\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	bl FUN_080ba9a0\n\
_0809D1F0:\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r1, #0x1d\n\
	bhi _0809D21C\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D214\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	b _0809D21A\n\
	.align 2, 0\n\
_0809D208: .4byte gOverworld\n\
_0809D20C: .4byte 0x0002C00C\n\
_0809D210: .4byte 0xFFFFF800\n\
_0809D214:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_0809D21A:\n\
	strb r0, [r4, #0xa]\n\
_0809D21C:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_0809D222:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 4,
  nature : BODY_NATURE_B7,
  remaining : 0,
  layer : 0x00000001,
  range : {0x0000, 0x0000, 0x1400, 0x0800},
};
