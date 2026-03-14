#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "story.h"

static const struct Collision sCollisions[2];

static void ClavekerYellowBalls_Init(struct Projectile* p);
static void ClavekerYellowBalls_Update(struct Projectile* p);
static void ClavekerYellowBalls_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gClavekerYellowBallsRoutine = {
    [ENTITY_INIT] =      ClavekerYellowBalls_Init,
    [ENTITY_UPDATE] =    ClavekerYellowBalls_Update,
    [ENTITY_DIE] =       ClavekerYellowBalls_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* FUN_080aed8c(struct Entity* boss, struct Coord* c1, struct Coord* c2, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 39);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = n;
    (p->s).work[1] = 0;
    (p->s).coord.x = c1->x;
    (p->s).coord.y = c1->y;
    (p->s).unk_coord.x = c2->x;
    (p->s).unk_coord.y = c2->y;
    (p->s).unk_28 = boss;
  }
  return p;
}

static void ClavekerYellowBalls_Init(struct Projectile* p) {
  if ((p->s).work[1] == 0) {
    InitNonAffineMotion(&p->s);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    INIT_BODY(p, &sCollisions[0], 2, NULL);
    SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
    (p->s).mode[3] = 0;
  }
  (p->s).work[2] = 0xFF;
  ClavekerYellowBalls_Update(p);
}

static void FUN_080aeefc(struct Projectile* p);

static void ClavekerYellowBalls_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[1] = {
      FUN_080aeefc,
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->body).status = 0;
    (p->body).prevStatus = 0;
    (p->body).invincibleTime = 0;
    (p->s).flags &= ~COLLIDABLE;
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    ClavekerYellowBalls_Die(p);
    return;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void ClavekerYellowBalls_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void FUN_080aeefc(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r2, r4, #0\n\
	adds r2, #0x8c\n\
	ldr r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	ands r3, r1\n\
	cmp r3, #0\n\
	beq _080AEF74\n\
	movs r1, #0\n\
	str r1, [r2]\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r5, r4, #0\n\
	adds r5, #0x54\n\
	movs r0, #2\n\
	adds r1, r5, #0\n\
	bl CreateSmoke\n\
	ldr r1, _080AEF70 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	ldr r1, [r4, #0x28]\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bhi _080AEF52\n\
	adds r1, #0xb9\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_080AEF52:\n\
	ldr r0, [r4, #0x28]\n\
	adds r0, #0xb9\n\
	ldrb r0, [r0]\n\
	cmp r0, #7\n\
	bhi _080AEF5E\n\
	b _080AF0F4\n\
_080AEF5E:\n\
	movs r0, #1\n\
	adds r1, r5, #0\n\
	bl CreateSmoke\n\
	movs r0, #6\n\
	adds r1, r5, #0\n\
	bl TryDropItem\n\
	b _080AF0F4\n\
	.align 2, 0\n\
_080AEF70: .4byte gProjectileFnTable\n\
_080AEF74:\n\
	movs r0, #4\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080AEF98\n\
	str r3, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r3, [r0]\n\
	adds r0, #4\n\
	strb r3, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #2\n\
	b _080AEFAA\n\
_080AEF98:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080AEFC8\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
_080AEFAA:\n\
	bl CreateSmoke\n\
	ldr r1, _080AEFC4 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _080AF0F4\n\
	.align 2, 0\n\
_080AEFC4: .4byte gProjectileFnTable\n\
_080AEFC8:\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _080AF012\n\
	cmp r5, #1\n\
	bgt _080AEFD8\n\
	cmp r5, #0\n\
	beq _080AEFDE\n\
	b _080AF0F4\n\
_080AEFD8:\n\
	cmp r5, #2\n\
	beq _080AF0CE\n\
	b _080AF0F4\n\
_080AEFDE:\n\
	ldr r1, _080AF054 @ =0x0000750A\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	str r5, [r4, #0x60]\n\
	ldr r2, _080AF058 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080AF05C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080AF060 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	bl __umodsi3\n\
	subs r0, #0xf0\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0x78\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AF012:\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080AF022\n\
	str r1, [r4, #0x60]\n\
_080AF022:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, [r4, #0x60]\n\
	adds r1, r1, r2\n\
	str r1, [r4, #0x58]\n\
	bl PushoutToUp1\n\
	adds r5, r0, #0\n\
	cmp r5, #0\n\
	beq _080AF0C6\n\
	ldr r0, _080AF064 @ =0xFFFFF900\n\
	cmp r5, r0\n\
	blt _080AF0C6\n\
	ldr r0, [r4, #0x5c]\n\
	cmp r0, #0\n\
	ble _080AF068\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToLeft1\n\
	b _080AF070\n\
	.align 2, 0\n\
_080AF054: .4byte 0x0000750A\n\
_080AF058: .4byte RNG_0202f388\n\
_080AF05C: .4byte 0x000343FD\n\
_080AF060: .4byte 0x00269EC3\n\
_080AF064: .4byte 0xFFFFF900\n\
_080AF068:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToRight1\n\
_080AF070:\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _080AF0B8\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	beq _080AF0B8\n\
	adds r2, r1, #0\n\
	cmp r1, #0\n\
	bge _080AF086\n\
	rsbs r2, r1, #0\n\
_080AF086:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r2, r0\n\
	ble _080AF0B8\n\
	adds r2, r1, #0\n\
	cmp r1, #0\n\
	bge _080AF096\n\
	rsbs r2, r1, #0\n\
_080AF096:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	cmp r2, r0\n\
	bgt _080AF0B8\n\
	cmp r1, #0\n\
	bge _080AF0A4\n\
	rsbs r1, r1, #0\n\
_080AF0A4:\n\
	adds r0, r5, #0\n\
	cmp r0, #0\n\
	bge _080AF0AC\n\
	rsbs r0, r0, #0\n\
_080AF0AC:\n\
	cmp r1, r0\n\
	bgt _080AF0B8\n\
	ldr r0, [r4, #0x5c]\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x5c]\n\
	b _080AF0C0\n\
_080AF0B8:\n\
	ldr r0, [r4, #0x60]\n\
	asrs r0, r0, #1\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x60]\n\
_080AF0C0:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080AF0C6:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _080AF0F4\n\
_080AF0CE:\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080AF0DE\n\
	str r1, [r4, #0x60]\n\
_080AF0DE:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080AF0F4:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
  .align 2, 0\n\
 .syntax divided\n");
}

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};
