#include "projectile/blazin_tail.h"

#include "collision.h"
#include "global.h"
#include "projectile.h"

static const struct Collision sCollisions[2];

static void BlazinTail_Init(BlazinTail* p);
static void BlazinTail_Update(BlazinTail* p);
static void BlazinTail_Die(BlazinTail* p);

static void BlazinTail_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

// clang-format off
const ProjectileRoutine gBlazinTailRoutine = {
    [ENTITY_INIT] =      (void*)BlazinTail_Init,
    [ENTITY_UPDATE] =    (void*)BlazinTail_Update,
    [ENTITY_DIE] =       (void*)BlazinTail_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

BlazinTail* createBlazinTail(struct Entity* e, s32 hp) {
  BlazinTail* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 10);
    p->work[0] = 0;
    p->unk_28 = e;
    p->hp = hp;
  }
  return p;
}

// --------------------------------------------

static void BlazinTail_Init(BlazinTail* p) {
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollisions[0], *((s16*)&p->hp), BlazinTail_OnCollision);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  BlazinTail_Update(p);
}

static void FUN_0809f140(BlazinTail* p);

static void BlazinTail_Update(BlazinTail* p) {
  static void (*const sUpdates[1])(BlazinTail*) = {
      FUN_0809f140,
  };

  if ((p->body).hp < 1) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    BlazinTail_Die(p);
    return;
  }
  p->xflip = ((p->unk_28)->flags & X_FLIP) ? 1 : 0;
  (sUpdates[p->mode[1]])(p);
}

static void BlazinTail_Die(BlazinTail* p) {
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809f140(BlazinTail* p) {
  if ((p->unk_28)->mode[0] > 1) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }

  switch (p->mode[2]) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      SET_XFLIP(p, ((p->unk_28)->flags & X_FLIP) != 0);
      (p->coord).x = ((p->unk_28)->coord).x;
      (p->coord).y = ((p->unk_28)->coord).y;
      if ((p->unk_28)->mode[1] == 9) {
        SetDDP(&p->body, &sCollisions[0]);
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      SET_XFLIP(p, ((p->unk_28)->flags & X_FLIP) != 0);
      (p->coord).x = ((p->unk_28)->coord).x;
      (p->coord).y = ((p->unk_28)->coord).y;
      if ((p->unk_28)->mode[1] != 9) {
        p->mode[2] = 0;
      }
      break;
    }
  }
}

NAKED static void BlazinTail_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
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
