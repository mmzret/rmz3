#include "collision.h"
#include "global.h"
#include "trig.h"
#include "physics.h"
#include "projectile.h"
#include "vfx.h"

struct Projectile33x {
  COLLISION_OBJECT_HDR;
  u8 buffer[4];          // 0xB4
  Coords32 prevCoord;  // 0xB8
  u32 unk_c0;          // 0xC0
};


// オメガ第一形態(白)の攻撃オブジェクト
typedef struct {
  COLLISION_OBJECT_HDR;
  u8 idx_b4;     // 0xB4
  s32 unk_b8;    // 0xB8
  s32 timer_bc;  // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile4;
static_assert(sizeof(Projectile4) == sizeof(Projectile));

static const struct Collision sCollisions[2];

static void OmegaWhiteProjectile_Init(Projectile4* p);
static void OmegaWhiteProjectile_Update(Projectile4* p);
static void OmegaWhiteProjectile_Die(Projectile4* p);

// clang-format off
const ProjectileRoutine gOmegaWhiteProjectileRoutine = {
    [ENTITY_INIT] =      (void*)OmegaWhiteProjectile_Init,
    [ENTITY_UPDATE] =    (void*)OmegaWhiteProjectile_Update,
    [ENTITY_DIE] =       (void*)OmegaWhiteProjectile_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* createOmega1Laser(s32 x, u8 n, s32 lifetime, Entity* omega) {
  Projectile4* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 4);
    p->work[0] = 0;
    p->idx_b4 = n;
    p->unk_b8 = x;
    p->timer_bc = lifetime;
    p->unk_28 = omega;
  }
  return (void*)p;
}

Entity* CreateOmegaWhiteHoop(s32 x, s32 y, u8 n) {
  Projectile4* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 4);
    p->work[0] = 1;
    (p->coord).x = x, (p->coord).y = y;
    p->idx_b4 = n;
    p->unk_b8 = 0x400;
    p->timer_bc = 1;
    p->unk_28 = NULL;
  }
  return (void*)p;
}

NAKED static void OmegaWhiteProjectile_Init(Projectile4* p) {
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

void doOmega1BallLaser1(Projectile4* p);
void doOmega1BallLaser2(Projectile4* p);
void doOmega1Hoopshot(Projectile4* p);

static void OmegaWhiteProjectile_Update(Projectile4* p) {
  static void (*const sUpdates[3])(Projectile4*) = {
      doOmega1BallLaser1,
      doOmega1BallLaser2,
      doOmega1Hoopshot,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

static void OmegaWhiteProjectile_Die(Projectile4* p) {
  p->flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

void doOmega1BallLaser1(Projectile4* p) {
  if (p->unk_28->mode[0] > 1) {
    CreateSmoke(3, &p->coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  } else {
    switch (p->mode[2]) {
      case 0:
        SetSpriteAnimation(p, 0xa06);
        p->mode[2]++;
        FALLTHROUGH;
      case 1:
        p->coord.x = p->unk_28->coord.x;
        p->coord.y = p->unk_28->coord.y - 0x6600;
        UpdateSpriteAnimation(p);
        break;
    }
    if (((struct Projectile33x*)p)->prevCoord.y == 0 || --((struct Projectile33x*)p)->prevCoord.y == 0) {
      p->mode[1] = 1;
      p->mode[2] = 0;
    }
  }
}

// NON_MATCH: doOmega1BallLaser2 (127/129) and doOmega1Hoopshot (113/115) carved
// to asm/projectile/omega_white_p2.inc. Both reach within 2 instructions; the gap
// is a redundant (u8) truncation (lsls#24;lsrs#24) agbcc applies to the OLD work[3]
// in the trail toggle that clean C optimizes away (the ldrb value is already 0..255),
// plus a r4/r6 alloc shuffle in Hoopshot's sine setup. Permuter TODO. C sketch:
//   doOmega1BallLaser2: if (unk_28->mode[0] > 1 || --work[2]==0) { smoke3; DIE; }
//     else switch(mode[2]){ case 0: prevCoord.x = (u32)(prevCoord.x*5<<6)>>8;
//       work[3]=0; SetMotion(0xa07); SetDDP(&sCollisions[1]);
//       d.x = -((u32)(gSineTable[work0]*prevCoord.x)>>8);
//       d.y =  (u32)(gSineTable[(u8)(work0+0x40)]*prevCoord.x)>>8;
//       work1=1; PlaySound(0x12c); mode[2]++;  FALLTHROUGH;
//     case 1: if(((u8)work[3]++ & 1)==0) FUN_080b9184(&coord,0); coord += d;
//       push=PushoutToUp1(coord.x,coord.y); if(push && work1){ work1=0; coord.y+=push;
//       d.y=-d.y; } UpdateSpriteAnimation(); }
//   doOmega1Hoopshot: same as BallLaser2 case 0/1 but the death check is just
//     `if (--work[2]==0) DIE;` (no unk_28, no smoke) and case 0 skips the prevCoord.x scale.
INCASM("asm/projectile/omega1w_laser_a.inc");

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
