#include "collision.h"
#include "entity.h"
#include "global.h"
#include "projectile.h"

// 敵が撃ってくる Lemon(豆)
typedef struct {
  COLLISION_OBJECT_HDR;
  s32 amplitude;  // 0xB4
  u8 unk_b8[12];  // 0xB8
} ProjectileLemon;
static_assert(sizeof(ProjectileLemon) == sizeof(struct Projectile));

static const struct Collision sCollisions[6];

static void Lemon_Init(ProjectileLemon* p);
static void Lemon_Update(ProjectileLemon* p);
static void Lemon_Die(ProjectileLemon* p);

// clang-format off
const ProjectileRoutine gLemonRoutine = {
    [ENTITY_INIT] =      (void*)Lemon_Init,
    [ENTITY_UPDATE] =    (void*)Lemon_Update,
    [ENTITY_DIE] =       (void*)Lemon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

// 0x0809c99c
struct Projectile* CreateLemon(Coords32* c, s32 amplitude, u8 r2) {
  ProjectileLemon* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 0);
    p->coord.x = c->x, p->coord.y = c->y;
    r2 += 0x80;
    p->amplitude = amplitude;
    p->d.x = Cos(r2, amplitude);
    p->d.y = Sin(r2, amplitude);
    p->work[0] = 1;
  }
  return (void*)p;
}

NAKED static struct Projectile* unused_0809ca34(Coords32* c, s32 r1, u8 r2) { INCCODE("asm/unused/unused_0809ca34.inc"); }

static void Lemon_Init(ProjectileLemon* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 0, NULL);
  SetSpriteAnimation(p, MOTION(SM002_LEMON, 0));
  p->work[2] = 0xFF;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  Lemon_Update(p);
}

NAKED static void Lemon_Update(ProjectileLemon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	bl UpdateEntityAnim\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809CBB4\n\
	ldrb r6, [r5, #0xd]\n\
	cmp r6, #0\n\
	bne _0809CB94\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809CB90 @ =0x0836AA10\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	ldr r1, [r5, #0x5c]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	rsbs r0, r0, #0\n\
	lsrs r1, r0, #0x1f\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	str r0, [r5, #0x5c]\n\
	ldr r1, [r5, #0x60]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	rsbs r0, r0, #0\n\
	lsrs r1, r0, #0x1f\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	str r0, [r5, #0x60]\n\
	movs r0, #1\n\
	strb r0, [r5, #0xd]\n\
	b _0809CBB4\n\
	.align 2, 0\n\
_0809CB90: .4byte sCollisions+(24*2)\n\
_0809CB94:\n\
	ldr r0, [r5, #0x60]\n\
	cmp r0, #0\n\
	bge _0809CBA8\n\
	movs r0, #0x2b\n\
	bl PlaySound\n\
	ldr r0, [r5, #0x5c]\n\
	rsbs r0, r0, #0\n\
	str r0, [r5, #0x5c]\n\
	b _0809CBB4\n\
_0809CBA8:\n\
	movs r0, #0x2b\n\
	bl PlaySound\n\
	ldr r0, [r5, #0x60]\n\
	rsbs r0, r0, #0\n\
	str r0, [r5, #0x60]\n\
_0809CBB4:\n\
	adds r2, r5, #0\n\
	adds r2, #0x8c\n\
	ldr r1, [r2]\n\
	ldr r3, _0809CBDC @ =0x00400100\n\
	ands r3, r1\n\
	cmp r3, #0\n\
	beq _0809CBE0\n\
	movs r1, #0\n\
	str r1, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	b _0809CC30\n\
	.align 2, 0\n\
_0809CBDC: .4byte 0x00400100\n\
_0809CBE0:\n\
	movs r0, #4\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0809CC04\n\
	str r3, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0x90\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #2\n\
	b _0809CC36\n\
_0809CC04:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0809CC30\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	beq _0809CC54\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	beq _0809CC54\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809CC54\n\
_0809CC30:\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
_0809CC36:\n\
	bl CreateSmoke\n\
	ldr r1, _0809CC50 @ =gProjectileFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	b _0809CCA4\n\
	.align 2, 0\n\
_0809CC50: .4byte gProjectileFnTable\n\
_0809CC54:\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #0\n\
	bne _0809CC94\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #0\n\
	bne _0809CC80\n\
	ldr r0, _0809CC78 @ =gIsLemonCollisionRemoved\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809CC94\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809CC7C @ =0x0836AA40\n\
	bl SetDDP\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
	b _0809CC94\n\
	.align 2, 0\n\
_0809CC78: .4byte gIsLemonCollisionRemoved\n\
_0809CC7C: .4byte sCollisions+(24*4)\n\
_0809CC80:\n\
	ldr r0, _0809CCAC @ =gIsLemonCollisionRemoved\n\
	ldrb r4, [r0]\n\
	cmp r4, #0\n\
	bne _0809CC94\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809CCB0 @ =sCollisions\n\
	bl SetDDP\n\
	strb r4, [r5, #0xe]\n\
_0809CC94:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
_0809CCA4:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CCAC: .4byte gIsLemonCollisionRemoved\n\
_0809CCB0: .4byte sCollisions\n\
 .syntax divided\n");
}

static void Lemon_Die(ProjectileLemon* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

static const struct Collision sCollisions[6] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0xFF,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0xFF,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0600, 0x0600},
    },
};
