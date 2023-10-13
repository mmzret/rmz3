#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"
#include "vfx.h"

static const struct Collision sCollision;

static void GrandCannonBomb_Init(struct Projectile* p);
static void GrandCannonBomb_Update(struct Projectile* p);
static void GrandCannonBomb_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gGrandCannonBombRoutine = {
    [ENTITY_INIT] =      GrandCannonBomb_Init,
    [ENTITY_UPDATE] =    GrandCannonBomb_Update,
    [ENTITY_DIE] =       GrandCannonBomb_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

void CreateGrandCannonBomb(struct Coord* c, s32 amplitude, u8 angle) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 3);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).d.x = Cos(angle, amplitude);
    (p->s).d.y = Sin(angle, amplitude);
  }
}

// --------------------------------------------

static void GrandCannonBomb_Init(struct Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &sCollision, 1, NULL);
  GrandCannonBomb_Update(p);
}

// --------------------------------------------

static void _parabolaGrandcannonBomb(struct Projectile* p);  // グランドキャノンの砲弾が放物線を描いて飛ぶ処理

static void GrandCannonBomb_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      _parabolaGrandcannonBomb,
  };

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
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void GrandCannonBomb_Die(struct Projectile* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  CreateSmoke(3, &(p->s).coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED static void _parabolaGrandcannonBomb(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _0809D3C4\n\
	cmp r0, #1\n\
	beq _0809D3D4\n\
	b _0809D426\n\
_0809D3C4:\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0809D3D4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r1, #0x40\n\
	str r1, [r4, #0x60]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	cmp r1, r0\n\
	ble _0809D3F8\n\
	str r0, [r4, #0x60]\n\
_0809D3F8:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0809D414\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D426\n\
_0809D414:\n\
	ldr r1, _0809D42C @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_0809D426:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D42C: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_NEUTRAL,
  special : 0,
  damage : 3,
  unk_04 : 0x00,
  element : 0x00,
  nature : 0x00,
  comboLv : 0,
  unk_0a : 0x00,
  remaining : 0,
  unk_0c : 0x00000001,
  range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
};
