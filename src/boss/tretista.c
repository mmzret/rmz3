#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  s8 unk_b5[2];          // 0xB5
  u8 unk_b7;             // 0xB7
  u8 unk_b8[8];          // 0xB8
  void* unk_c0;          // 0xC0
  u8 unk_c4[20];         // 0xC4
  u8 unk_d8;             // 0xD8
  u8 unk_d9[11];         // 0xD9
} Tretista;
static_assert(sizeof(Tretista) == sizeof(Boss));

static const struct Collision sCollisions[13];

static void Tretista_Init(Tretista* p);
static void Tretista_Update(Tretista* p);
static void Tretista_Die(Tretista* p);

// clang-format off
const BossRoutine gTretistaRoutine = {
    [ENTITY_INIT] =      (void*)Tretista_Init,
    [ENTITY_UPDATE] =    (void*)Tretista_Update,
    [ENTITY_DIE] =       (void*)Tretista_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Tretista* Unused_CreateTretista(Coords32* c, u8 n) {
  Tretista* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_TRETISTA);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

static void Tretista_Init(Tretista* p) {
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

static bool8 FUN_0804dc8c(Tretista* p);
bool8 FUN_0804df70(Tretista* p);
bool8 FUN_0804e01c(Tretista* p);
bool8 FUN_0804e08c(Tretista* p);
bool8 FUN_0804e3f0(Tretista* p);
bool8 FUN_0804e544(Tretista* p);
bool8 FUN_0804eb38(Tretista* p);
bool8 FUN_0804f2b4(Tretista* p);
bool8 FUN_0804f5c0(Tretista* p);
bool8 FUN_0804f7d8(Tretista* p);
bool8 FUN_0804fc6c(Tretista* p);
bool8 FUN_0804e8f4(Tretista* p);

void tretista_0804dc90(Tretista* p);
void tretista_0804df74(Tretista* p);
void tretista_0804e020(Tretista* p);
void tretistaNeutral(Tretista* p);
void tretista_0804e3f4(Tretista* p);
void tretista_0804e548(Tretista* p);
void tretistaPipeThrow(Tretista* p);
void tretistaHellBouncers(Tretista* p);
void tretistaBreathGas(Tretista* p);
void tretistaLaserCraw(Tretista* p);
void tretista_0804fc70(Tretista* p);
void FUN_0804e8f8(Tretista* p);

static void Tretista_Update(Tretista* p) {
  // clang-format off
  static bool8 (*const sUpdates1[12])(Tretista*) = {
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
  static void (*const sUpdates2[12])(Tretista*) = {
      (void*)tretista_0804dc90,
      (void*)tretista_0804df74,
      (void*)tretista_0804e020,
      (void*)tretistaNeutral,
      (void*)tretista_0804e3f4,
      (void*)tretista_0804e548,
      (void*)tretistaPipeThrow,
      (void*)tretistaHellBouncers,
      (void*)tretistaBreathGas,
      (void*)tretistaLaserCraw,
      (void*)tretista_0804fc70,
      (void*)FUN_0804e8f8,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_TRETISTA_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[3] = 1;
    } else {
      p->mode[3] = 0;
    }
    Tretista_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

static void FUN_0804d804(Tretista* p);
static void tretista_0804d8e8(Tretista* p);

static void Tretista_Die(Tretista* p) {
  static void (*const sDeads[2])(Tretista*) = {
      FUN_0804d804,
      tretista_0804d8e8,
  };
  (sDeads[p->mode[1]])((void*)p);
}

static void FUN_0804d804(Tretista* p) {
  StepPaletteAnimation(73);
  StepPaletteAnimation(74);
  StepPaletteAnimation(75);
  StepPaletteAnimation(76);

  switch (p->mode[2]) {
    case 0: {
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & VM_ACTIVE)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      SetSpriteAnimation(p, MOTION(DM171_TRETISTA, 37));
      p->flags |= DISPLAY;
      (p->spr).yflip = FALSE, (p->spr).oam.yflip = FALSE;
      p->flags &= ~Y_FLIP;
      EXIT_BODY(p);
      (&p->d)->x = (&p->d)->y = 0;
      p->work[2] = 1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (p->work[2] > 0 && --(p->work[2]) == 0) p->mode[2]++;
      break;
    }
    case 2: {
      p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

static void tretista_0804d8e8(Tretista* p) { INCCODE("asm/wip/tretista_0804d8e8.inc"); }

static bool8 FUN_0804dc8c(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_a.inc");

bool8 FUN_0804df70(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_b.inc");

bool8 FUN_0804e01c(Tretista* p) { return TRUE; }

void tretista_0804e020(Tretista* p) {
  switch (p->mode[2]) {
    case 0:
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, 0xAB09);
      p->work[2] = 0;
      p->mode[2]++;
      // fallthrough
    case 1:
      if ((p->scriptEntity->flags & 1) && p->work[2] == 0) {
        p->work[2] = 1;
        PlaySound(0xD4);
      }
      if (!(gStageRun.vm.active & 1)) {
        p->work[2] = 0;
        p->mode[1] = 3;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

bool8 FUN_0804e08c(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_c.inc");

bool8 FUN_0804e3f0(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_d.inc");

bool8 FUN_0804e544(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_e.inc");

bool8 FUN_0804e8f4(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_f.inc");

bool8 FUN_0804eb38(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_g.inc");

bool8 FUN_0804f2b4(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_h.inc");

bool8 FUN_0804f5c0(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_i.inc");

bool8 FUN_0804f7d8(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_j.inc");

bool8 FUN_0804fc6c(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_k.inc");

bool8 isTretistaFarAway(Tretista* p) {
  s32 zx = (pZero2->s).coord.x;
  s32 sx = p->coord.x;
  s32 dx = zx - sx;
  if (dx > 0) {
    if (dx <= 0x86FF) {
      return FALSE;
    }
    return TRUE;
  }
  if (sx - zx > 0x86FF) {
    return TRUE;
  }
  return FALSE;
}

INCASM("asm/boss/tretista_l.inc");

// 0x083633b0
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

static const Coords32 sTretista_ExplosionOffsets[2] = {
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(0), -PIXEL(48)},
};  // 0x083634E8
