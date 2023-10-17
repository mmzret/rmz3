#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const u8 sDeathtanzModes[32];
static const struct Collision sCollisions[71];
static const u8 sInitModes[2];

static void Deathtanz_Init(struct Boss* p);
static void Deathtanz_Update(struct Boss* p);
static void Deathtanz_Die(struct Boss* p);

// clang-format off
const BossRoutine gDeathtanzRoutine = {
    [ENTITY_INIT] =      Deathtanz_Init,
    [ENTITY_UPDATE] =    Deathtanz_Update,
    [ENTITY_DIE] =       Deathtanz_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

NAKED static void calcNextAction(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	mov ip, r0\n\
	movs r3, #0\n\
	adds r0, #0xb4\n\
	mov r2, ip\n\
	ldr r1, [r2, #0x54]\n\
	ldr r2, [r0]\n\
	cmp r1, r2\n\
	bge _08048D84\n\
	movs r3, #1\n\
_08048D84:\n\
	ldr r0, _08048DA4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r0, r2\n\
	bge _08048D92\n\
	movs r0, #1\n\
	eors r3, r0\n\
_08048D92:\n\
	ldr r7, _08048DA8 @ =RNG_0202f388\n\
	mov r5, ip\n\
	adds r5, #0xc3\n\
	ldr r0, _08048DAC @ =sDeathtanzModes\n\
	mov r8, r0\n\
	lsls r6, r3, #4\n\
	mov r4, ip\n\
	adds r4, #0xc4\n\
	b _08048DBA\n\
	.align 2, 0\n\
_08048DA4: .4byte pZero2\n\
_08048DA8: .4byte RNG_0202f388\n\
_08048DAC: .4byte sDeathtanzModes\n\
_08048DB0:\n\
	ldr r0, _08048DF8 @ =gMission\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #4\n\
	bhi _08048DE6\n\
_08048DBA:\n\
	ldr r1, [r7]\n\
	ldr r0, _08048DFC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08048E00 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r7]\n\
	lsrs r3, r0, #0x11\n\
	movs r0, #0xf\n\
	ands r3, r0\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r5]\n\
	ldrb r2, [r0]\n\
	cmp r1, r2\n\
	bne _08048DE2\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _08048DBA\n\
_08048DE2:\n\
	cmp r2, #0x11\n\
	beq _08048DB0\n\
_08048DE6:\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	bne _08048E04\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	b _08048E08\n\
	.align 2, 0\n\
_08048DF8: .4byte gMission\n\
_08048DFC: .4byte 0x000343FD\n\
_08048E00: .4byte 0x00269EC3\n\
_08048E04:\n\
	movs r0, #0\n\
	strb r1, [r5]\n\
_08048E08:\n\
	strb r0, [r4]\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r1, #0\n\
	mov r2, ip\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void onCollision(struct Body* body, struct Coord* c1, struct Coord* c2) {
  struct Zero* z = (struct Zero*)body->enemy->parent;
  struct Boss* boss = (struct Boss*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (boss->props.deathtanz).unk_c8.x = (z->s).coord.x;
    (boss->props.deathtanz).unk_c8.y = (z->s).coord.y;
    (boss->props.deathtanz).shouldTurnRight = (boss->s).coord.x < (z->s).coord.x;
  }
}

static bool8 tryKillDeathtanz(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    PlaySound(SE_DEATHTANZ_DEATH);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else {
      (p->s).mode[1] = 0;
    }
    Deathtanz_Die(p);
    return TRUE;
  }

  return FALSE;
}

static void Deathtanz_Init(struct Boss* p) {
  struct Body* body;
  s32 y;
  void* fn;

  // TODO: Kill them all
#if MODERN == 0
  register u32 r0 asm("r0");
  register u8 r1 asm("r1");
  register u8* r2 asm("r2");
#endif

  SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);

  ResetBossBody(p, &sCollisions[0], 64);
  SET_BOSS_COLLISION_HANDLER(p, onCollision);

  if ((p->s).work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM054_DEATHTANZ_ROCK);
    LOAD_STATIC_GRAPHIC(SM055_DEATHTANZ_PROJECTILE);

    (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
    ((p->props).deathtanz).unk_b4.x = (p->s).coord.x >> 8;
    ((p->props).deathtanz).unk_b4.x = ((((p->props).deathtanz).unk_b4.x / 240) * PIXEL(240)) + PIXEL(120);
    ((p->props).deathtanz).unk_b4.y = (p->s).coord.y;
    ((p->props).deathtanz).unk_bd = 0;
    ((p->props).deathtanz).unk_c1 = 3;
#if MODERN
    ((p->props).deathtanz).unk_c3 = 0xFF;
#else
    r2 = &((p->props).deathtanz).unk_c3;
    r0 = *r2;
    r1 = 0xFF;
    r0 |= r1;
    *r2 = r0;
#endif
    ((p->props).deathtanz).unk_c4 = 0;
  }
  Deathtanz_Update(p);
}

// --------------------------------------------

static void nop_0804908c(struct Boss* p);
static void tryMakeFlinch(struct Boss* p);

void deathtanzMode0(struct Boss* p);
void deathtanzNeutral(struct Boss* p);
void deathtanzMode2(struct Boss* p);
void deathtanzMode3(struct Boss* p);
void deathtanzMode4(struct Boss* p);
void deathtanzPreAI(struct Boss* p);
void deathtanzMode6(struct Boss* p);
void deathtanzMode7(struct Boss* p);
void deathtanzMode8(struct Boss* p);
void deathtanzMode9(struct Boss* p);
void deathtanzMode10(struct Boss* p);
void deathtanzMode11(struct Boss* p);
void deathtanzMode12(struct Boss* p);
void deathtanzMode13(struct Boss* p);
void deathtanzMode14(struct Boss* p);
void deathtanzMode15(struct Boss* p);
void deathtanzMode16(struct Boss* p);
void deathtanzEX1(struct Boss* p);
void deathtanzEX2(struct Boss* p);
void deathtanzMode19(struct Boss* p);
void deathtanzKnockBackDamage(struct Boss* p);

static void Deathtanz_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[21] = {
      nop_0804908c,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      nop_0804908c,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      tryMakeFlinch,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
      nop_0804908c,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[21] = {
      deathtanzMode0,
      deathtanzNeutral,
      deathtanzMode2,
      deathtanzMode3,
      deathtanzMode4,
      deathtanzPreAI,
      deathtanzMode6,
      deathtanzMode7,
      deathtanzMode8,
      deathtanzMode9,
      deathtanzMode10,
      deathtanzMode11,
      deathtanzMode12,
      deathtanzMode13,
      deathtanzMode14,
      deathtanzMode15,
      deathtanzMode16,
      deathtanzEX1,
      deathtanzEX2,
      deathtanzMode19,
      deathtanzKnockBackDamage,
  };
  // clang-format on

  bool8 killed = tryKillDeathtanz(p);
  if (!killed) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

// --------------------------------------------

void FUN_0804ac44(struct Boss* p);
void deathtanz_0804adb0(struct Boss* p);

static void Deathtanz_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      FUN_0804ac44,
      deathtanz_0804adb0,
  };
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void nop_0804908c(struct Boss* p) {
  // nop
  return;
}

static void tryMakeFlinch(struct Boss* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 20;
      (p->s).mode[2] = 0;
    }
  }
}

INCASM("asm/boss/deathtanz.inc");

// --------------------------------------------

static const struct Collision sCollisions[71] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0100, -0x2B00, 0x2400, 0x1F00},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0600, -0x1500, 0x3400, 0x2400},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1300, 0x3B00},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2000, 0x1700, 0x3E00},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2A00, 0x4900, 0x1900},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x2000, 0x1700, 0x3E00},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0900, -0x1A00, 0x2F00, 0x3700},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0800, -0x1500, 0x2800, 0x2400},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0500, -0x3400, 0x2C00, 0x1A00},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x1300, 0x2F00, 0x2700},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1C00, 0x1C00, 0x3A00},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x3300, 0x1A00, 0x1400},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0200, -0x2A00, 0x1300, 0x5100},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0200, -0x2B00, 0x1300, 0x5100},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2A00, 0x1B00, 0x5100},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1200, -0x2E00, 0x1A00, 0x1400},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2A00, 0x1B00, 0x5100},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0300, -0x1C00, 0x2400, 0x3300},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x1F00, -0x1B00, 0x3400, 0x0F00},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1B00, 0x1500, 0x3500},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0600, -0x2B00, 0x1B00, 0x4400},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0A00, -0x4000, 0x2400, 0x1B00},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x2A00, 0x1400, 0x4C00},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x1C00, 0x2400, 0x1000},
    },
    [26] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [29] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x2C00, 0x2400, 0x1000},
    },
    [30] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [31] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [32] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [33] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [34] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [35] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0A00, -0x2600, 0x1000, 0x4800},
    },
    [36] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0500, -0x1B00, 0x2C00, 0x1000},
    },
    [37] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {-0x0200, -0x3600, 0x1500, 0x1F00},
    },
    [38] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0A00, -0x1900, 0x1100, 0x2E00},
    },
    [39] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x3600, 0x2C00, 0x1000},
    },
    [41] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [42] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [43] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0700, -0x3000, 0x2C00, 0x1000},
    },
    [44] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [45] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x2100, -0x5300, 0x0B00, 0x3300},
    },
    [47] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [48] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [49] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0300, -0x5A00, 0x3600, 0x3400},
    },
    [50] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [51] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [52] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x3300, -0x5A00, 0x3600, 0x3400},
    },
    [53] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [55] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x3300, -0x2600, 0x3600, 0x3400},
    },
    [56] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [57] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1C00, -0x1700, 0x0800, 0x3400},
    },
    [59] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [60] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x1F00, 0x2400, 0x4000},
    },
    [61] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0C00, -0x1C00, 0x1300, 0x3B00},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0500, -0x3100, 0x1E00, 0x1B00},
    },
    [63] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0300, -0x1200, 0x3A00, 0x2600},
    },
    [64] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0C00, -0x1C00, 0x1300, 0x3B00},
    },
    [65] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x0A00, 0x2E00, 0x1800},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2100, 0x0F00, 0x4500},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1300, 0x3B00},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x3200, 0x2300},
    },
    [69] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2300, 0x1100, 0x4800},
    },
    [70] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1A00, 0x1900, 0x3700},
    },
};

static const u8 sDeathtanzModes[32] = {
    2, 2, 2, 2, 2, 2, 2, 2, 12, 12, 12, 12, 17, 17, 17, 17, 2, 2, 2, 2, 2, 2, 12, 12, 15, 15, 15, 15, 17, 17, 17, 17,
};

static const u8 sInitModes[2] = {0, 19};

static const u8 u8_ARRAY_08362ea6[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3,
};

static const u8 sPostures[14] = {
    39, 39, 42, 42, 45, 45, 48, 51, 54, 57, 57, 57, 57, 0,
};

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(35)},
    {PIXEL(0), -PIXEL(35)},
};
