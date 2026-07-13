#include "collision.h"
#include "global.h"
#include "projectile.h"
#include "vfx.h"

// Omega (1st white) hoop shot?
typedef struct {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  u8 unk_b4[4];  // 0xB4
  s32 unk_b8;    // 0xB8
  s32 lifetime;  // 0xBC
  u32 unk_c0;    // 0xC0
} Projectile5;
static_assert(sizeof(Projectile5) == sizeof(struct Projectile));

static const ProjectileFunc sUpdates[2];
static const struct Collision sCollisions[];

static void Projectile5_Init(Object* p);
static void Projectile5_Update(struct Entity* p);
static void Projectile5_Die(Object* p);

// clang-format off
const ProjectileRoutine gProjectile5Routine = {
    [ENTITY_INIT] =      (void*)Projectile5_Init,
    [ENTITY_UPDATE] =    (void*)Projectile5_Update,
    [ENTITY_DIE] =       (void*)Projectile5_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_0809d8a0(Coords32* c, s32 unk_b8, s32 lifetime, struct Entity* q) {
  Projectile5* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 5);
    (p->s).coord = *c;
    (p->s).work[0] = 0;
    p->unk_b8 = unk_b8, p->lifetime = lifetime;
    (p->s).unk_28 = q;
  }
  return (void*)p;
}

struct Entity* FUN_0809d904(Coords32* c, s32 unk_b8, s32 lifetime, struct Entity* q) {
  Projectile5* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 5);
    (p->s).coord = *c;
    (p->s).work[0] = 1;
    p->unk_b8 = unk_b8, p->lifetime = lifetime;
    (p->s).unk_28 = q;
  }
  return (void*)p;
}

// --------------------------------------------

static void Projectile5_Init(Object* p) {
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, NULL);
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  Projectile5_Update((void*)p);
}

static void FUN_0809da14(Projectile5* p);
static void FUN_0809daa0(Projectile5* p);

static void Projectile5_Update(struct Entity* p) {
  static const EntityFunc sUpdates[2] = {
      (void*)FUN_0809da14,
      (void*)FUN_0809daa0,
  };  // 0x0836ab84
  (sUpdates[(p->mode[1])])(p);
}

static void Projectile5_Die(Object* p) {
  (p->s).flags &= ~DISPLAY;
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void FUN_0809da14(Projectile5* p) {
  if (((p->s).unk_28)->mode[0] >= ENTITY_DIE) {
    CreateSmoke(3, &(p->s).coord);
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
    return;
  }
  switch ((p->s).mode[2]) {
    case 0: {
      if ((p->s).work[0] == 0) {
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 0));
      } else {
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 3));
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      FALLTHROUGH;
    }
    default: {
      if (p->lifetime == 0 || (--p->lifetime) == 0) {
        (p->s).work[2] = 127;
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

NAKED static void FUN_0809daa0(Projectile5* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0809DAB8\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl CreateSmoke\n\
	b _0809DAC4\n\
_0809DAB8:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0809DADC\n\
_0809DAC4:\n\
	ldr r1, _0809DAD8 @ =gProjectileFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	b _0809DBAA\n\
	.align 2, 0\n\
_0809DAD8: .4byte gProjectileFnTable\n\
_0809DADC:\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _0809DB5E\n\
	cmp r5, #1\n\
	bgt _0809DAEC\n\
	cmp r5, #0\n\
	beq _0809DAF2\n\
	b _0809DBAA\n\
_0809DAEC:\n\
	cmp r5, #2\n\
	beq _0809DB94\n\
	b _0809DBAA\n\
_0809DAF2:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _0809DB20\n\
	ldr r1, _0809DB18 @ =0x00000A01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809DB1C @ =sCollisions+24\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x60]\n\
	str r5, [r4, #0x5c]\n\
	b _0809DB3E\n\
	.align 2, 0\n\
_0809DB18: .4byte 0x00000A01\n\
_0809DB1C: .4byte sCollisions+24\n\
_0809DB20:\n\
	ldr r1, _0809DB80 @ =0x00000A04\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0809DB84 @ =sCollisions+48\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x5c]\n\
	str r5, [r4, #0x60]\n\
_0809DB3E:\n\
	ldr r2, _0809DB88 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0809DB8C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0809DB90 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #1\n\
	ands r0, r1\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0809DB5E:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0809DBAA\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	strb r1, [r4, #0xa]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0809DBAA\n\
	.align 2, 0\n\
_0809DB80: .4byte 0x00000A04\n\
_0809DB84: .4byte sCollisions+48\n\
_0809DB88: .4byte RNG_0202f388\n\
_0809DB8C: .4byte 0x000343FD\n\
_0809DB90: .4byte 0x00269EC3\n\
_0809DB94:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_0809DBAA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 0x0836ab8c
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0000, 0x1000, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x3000, 0x1000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1000, 0x3000},
    },
};
