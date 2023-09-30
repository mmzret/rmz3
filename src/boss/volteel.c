#include "boss.h"
#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[24];

bool8 volteel_080457c4(struct Boss* p);

static void Volteel_Init(struct Boss* p);
static void Volteel_Update(struct Boss* p);
static void Volteel_Die(struct Boss* p);

// clang-format off
const BossRoutine gVolteelRoutine = {
    [ENTITY_INIT] =      Volteel_Init,
    [ENTITY_MAIN] =      Volteel_Update,
    [ENTITY_DIE] =       Volteel_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateVolteel(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_BOSS_ROUTINE(p, BOSS_VOLTEEL);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= ENTITY_FLAGS2_B4;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

NAKED static void Volteel_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r7, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	adds r0, #0x24\n\
	movs r4, #0\n\
	strb r4, [r0]\n\
	adds r1, r7, #0\n\
	adds r1, #0x50\n\
	movs r0, #0\n\
	mov r8, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	adds r2, r7, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08043444 @ =0x08362330\n\
	adds r0, r7, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	adds r1, r7, #0\n\
	adds r1, #0xc9\n\
	movs r0, #0x40\n\
	strb r0, [r1]\n\
	ldr r1, _08043448 @ =FUN_0804586c\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x40\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xc0\n\
	str r4, [r0]\n\
	subs r0, #9\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	ldr r1, [r7, #0x58]\n\
	ldr r0, _0804344C @ =0xFFFFC000\n\
	adds r1, r1, r0\n\
	ldr r0, [r7, #0x54]\n\
	bl FUN_0800a05c\n\
	str r0, [r7, #0x58]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb8\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_0800a134\n\
	adds r5, r0, #0\n\
	ldr r0, [r7, #0x54]\n\
	adds r1, r5, #0\n\
	bl FUN_0800a22c\n\
	adds r6, r0, #0\n\
	ldr r0, [r7, #0x54]\n\
	adds r1, r5, #0\n\
	bl FUN_0800a31c\n\
	adds r4, r0, #0\n\
	subs r0, r6, r4\n\
	asrs r5, r0, #1\n\
	adds r5, r4, r5\n\
	ldr r1, [r7, #0x58]\n\
	adds r0, r5, #0\n\
	bl FUN_0800a134\n\
	adds r1, r7, #0\n\
	adds r1, #0xd4\n\
	str r0, [r1]\n\
	ldr r1, [r7, #0x58]\n\
	adds r0, r5, #0\n\
	bl FUN_0800a05c\n\
	adds r1, r7, #0\n\
	adds r1, #0xd8\n\
	str r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xdc\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	subs r0, #0x16\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
	ldrb r0, [r7, #0x10]\n\
	cmp r0, #0\n\
	bne _08043454\n\
	ldr r1, _08043450 @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	mov r0, r8\n\
	strb r0, [r7, #0xd]\n\
	strb r0, [r7, #0xe]\n\
	strb r0, [r7, #0xf]\n\
	b _08043470\n\
	.align 2, 0\n\
_08043444: .4byte 0x08362330\n\
_08043448: .4byte FUN_0804586c\n\
_0804344C: .4byte 0xFFFFC000\n\
_08043450: .4byte gBossFnTable\n\
_08043454:\n\
	ldr r1, _08043484 @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	movs r0, #3\n\
	strb r0, [r7, #0xd]\n\
	mov r1, r8\n\
	strb r1, [r7, #0xe]\n\
	strb r1, [r7, #0xf]\n\
_08043470:\n\
	movs r0, #0\n\
	strb r0, [r7, #0x11]\n\
	adds r0, r7, #0\n\
	bl Volteel_Update\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08043484: .4byte gBossFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

bool8 nop_080438a4(struct Boss* p);
bool8 FUN_080438f0(struct Boss* p);
bool8 FUN_08043988(struct Boss* p);
bool8 nop_080439d0(struct Boss* p);
bool8 nop_08043db0(struct Boss* p);
bool8 FUN_080440c0(struct Boss* p);
bool8 FUN_080449f0(struct Boss* p);
bool8 FUN_08044cb4(struct Boss* p);
bool8 FUN_08044f00(struct Boss* p);
bool8 FUN_080450bc(struct Boss* p);
bool8 FUN_08045464(struct Boss* p);
bool8 FUN_08045570(struct Boss* p);
bool8 FUN_08045610(struct Boss* p);

void volteelMode0(struct Boss* p);
void volteelMode1(struct Boss* p);
void volteelMode2(struct Boss* p);
void volteelNeutral(struct Boss* p);
void volteelMode4(struct Boss* p);
void volteelMode5(struct Boss* p);
void volteelMode6(struct Boss* p);
void volteelElectricCage(struct Boss* p);
void volteelMode8(struct Boss* p);
void volteelMode9(struct Boss* p);
void volteelEX(struct Boss* p);
void volteelMode11(struct Boss* p);
void volteelKnockBackDamage(struct Boss* p);

static void Volteel_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[] = {
      (BossFunc)nop_080438a4,
      (BossFunc)FUN_080438f0,
      (BossFunc)FUN_08043988,
      (BossFunc)nop_080439d0,
      (BossFunc)nop_08043db0,
      (BossFunc)FUN_080440c0,
      (BossFunc)FUN_080449f0,
      (BossFunc)FUN_08044cb4,
      (BossFunc)FUN_08044f00,
      (BossFunc)FUN_080450bc,
      (BossFunc)FUN_08045464,
      (BossFunc)FUN_08045570,
      (BossFunc)FUN_08045610,
  };
  // clang-format on
  // clang-format off
  static const BossFunc sUpdates2[] = {
      volteelMode0,
      volteelMode1,
      volteelMode2,
      volteelNeutral,
      volteelMode4,
      volteelMode5,
      volteelMode6,
      volteelElectricCage,
      volteelMode8,
      volteelMode9,
      volteelEX,
      volteelMode11,
      volteelKnockBackDamage,
  };
  // clang-format on
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_VOLTEEL_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[3] = 1;
    } else {
      (p->s).mode[3] = 0;
    }
    Volteel_Die(p);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  volteel_080457c4(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

void volteelDeath0(struct Boss* p);
void volteelDeath1(struct Boss* p);

static void Volteel_Die(struct Boss* p) {
  static const BossFunc seq[] = {
      volteelDeath0,
      volteelDeath1,
  };
  (seq[(p->s).mode[1]])(p);
}

INCASM("asm/boss/volteel.inc");

// --------------------------------------------

static const struct Collision sCollisions[24] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {0x0000, -0x1200, 0x2400, 0x2600},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1800, 0x1C00, 0x2600},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1900, 0x1E00, 0x2800},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x1C00, 0x3C00},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1D00, 0x1E00, 0x3E00},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x0200, -0x1C00, 0x1A00, 0x3600},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x2800, -0x0F00, 0x1700, 0x2100},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0300, -0x1D00, 0x1C00, 0x3800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-0x0700, -0x1600, 0x1F00, 0x2600},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x0A00, -0x3F00, 0x2300, 0x1100},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0800, -0x1700, 0x2100, 0x2800},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0600, -0x1100, 0x7C00, 0x1000},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0700, -0x1200, 0x7E00, 0x1200},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1100, 0x1000, 0x7C00},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, -0x1200, 0x1200, 0x7E00},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [16] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
    [17] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-0x0E00, 0x0000, 0x1C00, 0x0E00},
    },
    [18] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-0x0F00, 0x0000, 0x1E00, 0x1000},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0E00, 0x0E00, 0x1C00},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0F00, 0x1000, 0x1E00},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {0x0000, -0x1C00, 0x1A00, 0x3600},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 5,
      unk_04 : 0x00,
      element : 0x01,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000002,
      range : {-0x4E00, -0x1900, 0x4500, 0x1000},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0100, -0x1D00, 0x1C00, 0x3800},
    },
};

const struct Coord Coord_ARRAY_08362570[7] = {
    {0x00000000, -0x00002000}, {0x00000600, -0x00002500}, {0x00000600, -0x00002500}, {0x00000000, 0x00000400}, {0x00000000, 0x00000400}, {-0x00001000, 0x00000000}, {-0x00001000, 0x00000000},
};
