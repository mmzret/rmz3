#include "collision.h"
#include "global.h"
#include "projectile.h"

/*
  オメガ第一形態(白)の攻撃オブジェクト
  various: 0 -> 球体のレーザー, 1 -> フープショット？
*/

static const struct Collision sCollisions[2];

static void OmegaWhiteProjectile_Init(struct Projectile* p);
static void OmegaWhiteProjectile_Update(struct Projectile* p);
static void OmegaWhiteProjectile_Die(struct Projectile* p);

// clang-format off
const ProjectileRoutine gOmegaWhiteProjectileRoutine = {
    [ENTITY_INIT] =      OmegaWhiteProjectile_Init,
    [ENTITY_UPDATE] =    OmegaWhiteProjectile_Update,
    [ENTITY_DIE] =       OmegaWhiteProjectile_Die,
    [ENTITY_DISAPPEAR] = DeleteProjectile,
    [ENTITY_EXIT] =      (ProjectileFunc)DeleteEntity,
};
// clang-format on

struct Projectile* createOmega1Laser(s32 x, u8 n, s32 y, struct Entity* omega) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 4);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 0;
    p->work[0] = n;
    (p->prevCoord).x = x;
    (p->prevCoord).y = y;
    (p->s).unk_28 = omega;
  }
  return p;
}

struct Projectile* CreateOmegaWhiteHoop(s32 x, s32 y, u8 n) {
  struct Projectile* p = (struct Projectile*)AllocEntityFirst(gProjectileHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 8;
    INIT_PROJECTILE_ROUTINE(p, 4);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).work[0] = 1;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    p->work[0] = n;
    (p->prevCoord).x = 0x400;
    (p->prevCoord).y = 1;
    (p->s).unk_28 = NULL;
  }
  return p;
}

NAKED static void OmegaWhiteProjectile_Init(struct Projectile* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r2, #0\n\
	movs r6, #0\n\
	orrs r1, r0\n\
	movs r0, #2\n\
	orrs r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r5, #0xa]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0809D558\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strb r1, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809D550 @ =sCollisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	adds r0, r5, #0\n\
	adds r0, #0x25\n\
	strb r6, [r0]\n\
	ldr r1, _0809D554 @ =gProjectileFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r6, [r5, #0xd]\n\
	b _0809D590\n\
	.align 2, 0\n\
_0809D550: .4byte sCollisions\n\
_0809D554: .4byte gProjectileFnTable\n\
_0809D558:\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strb r1, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0809D5A4 @ =sCollisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	adds r0, r5, #0\n\
	adds r0, #0x25\n\
	strb r6, [r0]\n\
	ldr r1, _0809D5A8 @ =gProjectileFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r5, #0xd]\n\
_0809D590:\n\
	strb r6, [r5, #0xe]\n\
	strb r6, [r5, #0xf]\n\
	movs r0, #0xff\n\
	strb r0, [r5, #0x12]\n\
	adds r0, r5, #0\n\
	bl OmegaWhiteProjectile_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D5A4: .4byte sCollisions\n\
_0809D5A8: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

void doOmega1BallLaser1(struct Projectile* p);
void doOmega1BallLaser2(struct Projectile* p);
void doOmega1Hoopshot(struct Projectile* p);

static void OmegaWhiteProjectile_Update(struct Projectile* p) {
  static const ProjectileFunc sUpdates[3] = {
      doOmega1BallLaser1,
      doOmega1BallLaser2,
      doOmega1Hoopshot,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

static void OmegaWhiteProjectile_Die(struct Projectile* p) {
  (p->s).flags &= ~DISPLAY;
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/projectile/omega_white.inc");

static const struct Collision sCollisions[2] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
};
