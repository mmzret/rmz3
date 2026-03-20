#include "collision.h"
#include "global.h"
#include "projectile.h"

static const struct Collision sCollisions[2];

static void BlazinTail_Init(struct Projectile* p);
static void BlazinTail_Update(struct Projectile* p);
static void BlazinTail_Die(struct Projectile* p);

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED);

// clang-format off
const ProjectileRoutine gBlazinTailRoutine = {
    [ENTITY_INIT] =      BlazinTail_Init,
    [ENTITY_UPDATE] =    BlazinTail_Update,
    [ENTITY_DIE] =       BlazinTail_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Projectile* createBlazinTail(struct Entity* e, s32 hp) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 10);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    (p->s).unk_28 = e;
    *(s32*)(p->work) = hp;
  }
  return p;
}

// --------------------------------------------

static void BlazinTail_Init(struct Projectile* p) {
  (p->s).flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], *(s16*)(p->work), onCollision);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  BlazinTail_Update(p);
}

// --------------------------------------------

static void FUN_0809f140(struct Projectile* p);

static void BlazinTail_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      FUN_0809f140,
  };

  if ((p->body).hp < 1) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    BlazinTail_Die(p);
    return;
  }
  (p->prevCoord).x = (((p->s).unk_28)->flags & X_FLIP) ? 1 : 0;
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void BlazinTail_Die(struct Projectile* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED static void FUN_0809f140(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, [r4, #0x28]\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _0809F164\n\
	ldr r1, _0809F160 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _0809F236\n\
	.align 2, 0\n\
_0809F160: .4byte gProjectileFnTable\n\
_0809F164:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0809F18A\n\
	cmp r0, #1\n\
	bgt _0809F174\n\
	cmp r0, #0\n\
	beq _0809F17A\n\
	b _0809F236\n\
_0809F174:\n\
	cmp r0, #2\n\
	beq _0809F1EC\n\
	b _0809F236\n\
_0809F17A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809F1A0 @ =0x0836AEE0\n\
	bl SetDDP\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0809F18A:\n\
	ldr r0, [r4, #0x28]\n\
	ldrb r0, [r0, #0xa]\n\
	lsrs r2, r0, #4\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _0809F1A4\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _0809F1AA\n\
	.align 2, 0\n\
_0809F1A0: .4byte sCollisions+(1*24)\n\
_0809F1A4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0809F1AA:\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r2, #0\n\
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
	ldr r1, [r4, #0x28]\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #9\n\
	bne _0809F236\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809F1E8 @ =sCollisions\n\
	bl SetDDP\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	b _0809F234\n\
	.align 2, 0\n\
_0809F1E8: .4byte sCollisions\n\
_0809F1EC:\n\
	ldrb r0, [r1, #0xa]\n\
	lsrs r2, r0, #4\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _0809F200\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _0809F206\n\
_0809F200:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0809F206:\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r2, #0\n\
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
	ldr r1, [r4, #0x28]\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #9\n\
	beq _0809F236\n\
	movs r0, #0\n\
_0809F234:\n\
	strb r0, [r4, #0xe]\n\
_0809F236:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  asm(".syntax unified\n\
	push {lr}\n\
	movs r3, #0\n\
	ldr r2, [r0, #0x2c]\n\
	adds r0, #0x23\n\
	ldrb r0, [r0]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	cmp r1, #1\n\
	beq _0809F252\n\
	cmp r1, #3\n\
	bne _0809F282\n\
_0809F252:\n\
	adds r0, r2, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809F270\n\
	ldr r0, _0809F26C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r2, #0x54]\n\
	cmp r1, r0\n\
	ble _0809F282\n\
	b _0809F28E\n\
	.align 2, 0\n\
_0809F26C: .4byte pZero2\n\
_0809F270:\n\
	cmp r0, #1\n\
	bne _0809F282\n\
	ldr r0, _0809F294 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r2, #0x54]\n\
	cmp r1, r0\n\
	bge _0809F282\n\
	movs r3, #1\n\
_0809F282:\n\
	cmp r3, #0\n\
	bne _0809F28E\n\
	adds r1, r2, #0\n\
	adds r1, #0xa4\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
_0809F28E:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809F294: .4byte pZero2\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(22), -PIXEL(18), PIXEL(22), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 7,
      remaining : 0,
      range : {PIXEL(22), -PIXEL(18), PIXEL(22), PIXEL(16)},
    },
};
