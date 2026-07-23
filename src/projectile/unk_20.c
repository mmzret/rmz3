#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

void FUN_080bf438(s32 x, s32 y, u8 kind);

static void Projectile20_Init(Projectile* p);
static void Projectile20_Update(Projectile* p);
static void Projectile20_Die(Projectile* p);

// clang-format off
const ProjectileRoutine gProjectile20Routine = {
    [ENTITY_INIT] =      (void*)Projectile20_Init,
    [ENTITY_UPDATE] =    (void*)Projectile20_Update,
    [ENTITY_DIE] =       (void*)Projectile20_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080a4ef8(Entity* e) {
  Projectile* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 20);
    p->work[0] = 0;
    p->unk_28 = (void*)e;
  }
}

void FUN_080a4f3c(Projectile* p) {
  s32 i;
  for (i = 0; i < 4; i++) {
    register s32 x asm("r4");
    s32 y;
    x = (p->coord).x - PIXEL(16);
    x += (RANDOM(RNG_0202f388) & 0x1FFF);
    y = FUN_08009f6c(x, (p->coord).y);
    if (((y - (p->coord).y) >= -PIXEL(24)) && ((y - (p->coord).y) < PIXEL(24))) {
      FUN_080bf438(x, y, 1);
    }
  }
}

NAKED void FUN_080a4fa4(Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r3, r0, #0\n\
	ldr r5, [r3, #0x28]\n\
	adds r0, #0xb4\n\
	ldrh r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A4FBE\n\
	rsbs r0, r4, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
_080A4FBE:\n\
	ldr r6, [r5, #0x54]\n\
	str r6, [r3, #0x54]\n\
	ldr r2, _080A4FF8 @ =gSineTable\n\
	lsrs r0, r4, #8\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	movs r7, #0\n\
	ldrsh r1, [r0, r7]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xb\n\
	rsbs r0, r0, #0\n\
	adds r7, r2, #0\n\
	lsrs r2, r4, #8\n\
	cmp r0, #0\n\
	bge _080A4FE0\n\
	adds r0, #0xff\n\
_080A4FE0:\n\
	asrs r0, r0, #8\n\
	adds r0, r6, r0\n\
	str r0, [r3, #0x54]\n\
	ldr r1, _080A4FFC @ =0xFFFFC000\n\
	adds r0, r4, r1\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	blt _080A5000\n\
	adds r1, r3, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x17\n\
	b _080A5006\n\
	.align 2, 0\n\
_080A4FF8: .4byte gSineTable\n\
_080A4FFC: .4byte 0xFFFFC000\n\
_080A5000:\n\
	adds r1, r3, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x19\n\
_080A5006:\n\
	strb r0, [r1]\n\
	ldr r1, [r5, #0x58]\n\
	str r1, [r3, #0x58]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	asrs r0, r0, #8\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r7\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	str r1, [r3, #0x58]\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r7\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	lsls r0, r0, #0xa\n\
	rsbs r0, r0, #0\n\
	cmp r0, #0\n\
	bge _080A503C\n\
	adds r0, #0xff\n\
_080A503C:\n\
	asrs r0, r0, #8\n\
	adds r0, r1, r0\n\
	str r0, [r3, #0x58]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 0x080a5048
static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// --------------------------------------------

static const struct Collision sCollisions[];
static const u8 sInitModes[];

static void Projectile20_Init(Projectile* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  INIT_BODY(p, &sCollisions[0], 1, onCollision);
  Projectile20_Update(p);
}

static void FUN_080a5144(Projectile* _ UNUSED);
void FUN_080a5148(Projectile* p);
void FUN_080a51b4(Projectile* p);
void FUN_080a5290(Projectile* p);
void FUN_080a53e8(Projectile* p);
void FUN_080a54f8(Projectile* p);
void FUN_080a569c(Projectile* p);
void FUN_080a57ac(Projectile* p);
void FUN_080a598c(Projectile* p);
void FUN_080a5ac0(Projectile* p);
void FUN_080a5b28(Projectile* p);

static void Projectile20_Update(Projectile* p) {
  // clang-format off
  static const ProjectileFunc sUpdates1[10] = {
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
    FUN_080a5144,
  }; // 0x0836ba50
  // clang-format on
  // clang-format off
  static const ProjectileFunc sUpdates2[10] = {
      FUN_080a5148,
      FUN_080a51b4,
      FUN_080a5290,
      FUN_080a53e8,
      FUN_080a54f8,
      FUN_080a569c,
      FUN_080a57ac,
      FUN_080a598c,
      FUN_080a5ac0,
      FUN_080a5b28,
  }; // 0x0836ba78
  // clang-format on

  Entity* q = (Entity*)p->unk_28;
  if ((q->mode[0] >= ENTITY_DIE) && (p->mode[1] != 7)) {
    p->mode[1] = 7, p->mode[2] = 0;
  }
  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void Projectile20_Die(Projectile* p) {
  EXIT_BODY(p);
  CreateSmoke(3, &p->coord);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_080a5144(Projectile* _) {}

INCASM("asm/projectile/unk_20.inc");

// --------------------------------------------

// 0x0836BAA0
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(32), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      nature : BODY_NATURE_B2,
      remaining : 0,
      layer : 1,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(46)},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
