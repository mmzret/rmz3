#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[13];

static void Tretista_Init(struct Boss* p);
static void Tretista_Update(struct Boss* p);
static void Tretista_Die(struct Boss* p);

// clang-format off
const BossRoutine gTretistaRoutine = {
    [ENTITY_INIT] =      Tretista_Init,
    [ENTITY_UPDATE] =    Tretista_Update,
    [ENTITY_DIE] =       Tretista_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateTretista(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;

    INIT_BOSS_ROUTINE(p, BOSS_TRETISTA);

    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

NAKED static void Tretista_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r6, #0\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r6, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _0804D710 @ =sCollisions\n\
	adds r0, r5, #0\n\
	movs r2, #0x60\n\
	bl ResetBossBody\n\
	ldr r1, _0804D714 @ =FUN_0804fdf8\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x40\n\
	strb r6, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0xc0\n\
	str r6, [r0]\n\
	subs r0, #9\n\
	strb r6, [r0]\n\
	adds r0, #0x21\n\
	movs r7, #1\n\
	strb r7, [r0]\n\
	subs r0, #0x14\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	adds r0, #0xd\n\
	strb r6, [r0]\n\
	adds r0, #9\n\
	strb r6, [r0]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0xd4\n\
	str r1, [r0]\n\
	str r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	bl FUN_0800a134\n\
	adds r4, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r4, #0\n\
	bl FUN_0800a31c\n\
	adds r1, r5, #0\n\
	adds r1, #0xd0\n\
	str r0, [r1]\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r4, #0\n\
	bl FUN_0800a22c\n\
	adds r1, r5, #0\n\
	adds r1, #0xdc\n\
	str r0, [r1]\n\
	subs r1, #0x24\n\
	ldr r0, [r5, #0x54]\n\
	ldr r2, _0804D718 @ =0xFFFF9000\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0804D720\n\
	ldr r1, _0804D71C @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r6, [r5, #0xd]\n\
	b _0804D734\n\
	.align 2, 0\n\
_0804D710: .4byte sCollisions\n\
_0804D714: .4byte FUN_0804fdf8\n\
_0804D718: .4byte 0xFFFF9000\n\
_0804D71C: .4byte gBossFnTable\n\
_0804D720:\n\
	ldr r1, _0804D750 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r5, #0xd]\n\
_0804D734:\n\
	strb r6, [r5, #0xe]\n\
	strb r6, [r5, #0xf]\n\
	movs r0, #0\n\
	strb r0, [r5, #0x11]\n\
	adds r1, r5, #0\n\
	adds r1, #0xe1\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	bl Tretista_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0804D750: .4byte gBossFnTable\n\
   .syntax divided\n");
}

void FUN_0804dc8c(struct Boss* p);
void FUN_0804df70(struct Boss* p);
void FUN_0804e01c(struct Boss* p);
void FUN_0804e08c(struct Boss* p);
void FUN_0804e3f0(struct Boss* p);
void FUN_0804e544(struct Boss* p);
void FUN_0804eb38(struct Boss* p);
void FUN_0804f2b4(struct Boss* p);
void FUN_0804f5c0(struct Boss* p);
void FUN_0804f7d8(struct Boss* p);
void FUN_0804fc6c(struct Boss* p);
void FUN_0804e8f4(struct Boss* p);

void tretista_0804dc90(struct Boss* p);
void tretista_0804df74(struct Boss* p);
void tretista_0804e020(struct Boss* p);
void tretistaNeutral(struct Boss* p);
void tretista_0804e3f4(struct Boss* p);
void tretista_0804e548(struct Boss* p);
void tretistaPipeThrow(struct Boss* p);
void tretistaHellBouncers(struct Boss* p);
void tretistaBreathGas(struct Boss* p);
void tretistaLaserCraw(struct Boss* p);
void tretista_0804fc70(struct Boss* p);
void FUN_0804e8f8(struct Boss* p);

static void Tretista_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[12] = {
      FUN_0804dc8c,
      FUN_0804df70,
      FUN_0804e01c,
      FUN_0804e08c,
      FUN_0804e3f0,
      FUN_0804e544,
      FUN_0804eb38,
      FUN_0804f2b4,
      FUN_0804f5c0,
      FUN_0804f7d8,
      FUN_0804fc6c,
      FUN_0804e8f4,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[12] = {
      tretista_0804dc90,
      tretista_0804df74,
      tretista_0804e020,
      tretistaNeutral,
      tretista_0804e3f4,
      tretista_0804e548,
      tretistaPipeThrow,
      tretistaHellBouncers,
      tretistaBreathGas,
      tretistaLaserCraw,
      tretista_0804fc70,
      FUN_0804e8f8,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_TRETISTA_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[3] = 1;
    } else {
      (p->s).mode[3] = 0;
    }
    Tretista_Die(p);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

void FUN_0804d804(struct Boss* p);
void tretista_0804d8e8(struct Boss* p);

static void Tretista_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      FUN_0804d804,
      tretista_0804d8e8,
  };
  (sDeads[(p->s).mode[1]])(p);
}

INCASM("asm/boss/tretista.inc");

static const struct Collision sCollisions[13] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(4), -PIXEL(34), PIXEL(84), PIXEL(68)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(26), -PIXEL(49), PIXEL(20), PIXEL(24)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(4), -PIXEL(18), PIXEL(84), PIXEL(37)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(56), PIXEL(72), PIXEL(103)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(15), -PIXEL(96), PIXEL(22), PIXEL(23)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(41), PIXEL(72), PIXEL(83)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(37), PIXEL(80), PIXEL(77)},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(50), PIXEL(20), PIXEL(26)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(12), PIXEL(80), PIXEL(25)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(12), -PIXEL(37), PIXEL(97), PIXEL(78)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(26), -PIXEL(49), PIXEL(20), PIXEL(24)},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(12), -PIXEL(12), PIXEL(97), PIXEL(24)},
    },
};

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(0), -PIXEL(48)},
};
