#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static const ProjectileFunc sUpdates[1];
static const struct Collision sCollision;

static void Projectile2_Init(struct Projectile* p);
static void Projectile2_Update(struct Projectile* p);
static void Projectile2_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile2Routine = {
    [ENTITY_INIT] =      Projectile2_Init,
    [ENTITY_UPDATE] =    Projectile2_Update,
    [ENTITY_DIE] =       Projectile2_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* CreateProjectile2(struct Coord* c1, struct Coord* c2, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 2);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).coord.x = c1->x;
    (p->s).coord.y = c1->y;
    (p->s).unk_coord.x = c2->x;
    (p->s).unk_coord.y = c2->y;
  }
  return p;
}

// --------------------------------------------

NAKED static void Projectile2_Init(struct Projectile* p) {
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
	ldr r1, _0809D050 @ =sCollision\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldrb r2, [r6, #0x10]\n\
	cmp r2, #0\n\
	bne _0809D054\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _0809D076\n\
	.align 2, 0\n\
_0809D050: .4byte sCollision\n\
_0809D054:\n\
	movs r2, #1\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_0809D076:\n\
	movs r0, #0xff\n\
	strb r0, [r6, #0x12]\n\
	ldr r1, _0809D0A0 @ =gProjectileFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r6, #0xd]\n\
	strb r0, [r6, #0xe]\n\
	strb r0, [r6, #0xf]\n\
	adds r0, r6, #0\n\
	bl Projectile2_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D0A0: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

static void updateProjectile2(struct Projectile* p);

static void Projectile2_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      updateProjectile2,
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    Projectile2_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void Projectile2_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void updateProjectile2(struct Projectile* p) {
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
	bl UpdateMotionGraphic\n\
_0809D222:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  special : 0,
  damage : 4,
  unk_04 : 0x00,
  element : 0x00,
  nature : 0x80,
  comboLv : 0x00,
  hitzone : 0x00,
  hardness : 0x00,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000001,
  range : {0x0000, 0x0000, 0x1400, 0x0800},
};
