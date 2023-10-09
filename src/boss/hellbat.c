#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[29];

void hellbat_0804cbe4(struct Boss* p);

static void Hellbat_Init(struct Boss* p);
static void Hellbat_Update(struct Boss* p);
static void Hellbat_Die(struct Boss* p);

// clang-format off
const BossRoutine gHellbatRoutine = {
    [ENTITY_INIT] =      Hellbat_Init,
    [ENTITY_UPDATE] =    Hellbat_Update,
    [ENTITY_DIE] =       Hellbat_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateHellbat(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;

    INIT_BOSS_ROUTINE(p, BOSS_HELLBAT);

    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

NAKED static void Hellbat_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	movs r4, #0\n\
	strb r4, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0x50\n\
	movs r6, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	strh r0, [r1]\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
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
	ldr r1, _0804B110 @ =sCollisions\n\
	adds r0, r5, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	ldr r1, _0804B114 @ =hellbat_0804cc38\n\
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
	str r4, [r0]\n\
	subs r0, #9\n\
	strb r6, [r0]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r5, #0\n\
	adds r1, #0xd4\n\
	str r0, [r1]\n\
	str r0, [r5, #0x58]\n\
	ldr r0, _0804B118 @ =gStageRun+232\n\
	ldr r1, [r0, #0x3c]\n\
	ldr r0, _0804B11C @ =0xFFFFB000\n\
	adds r1, r1, r0\n\
	ldr r0, [r5, #0x54]\n\
	bl FUN_0800a31c\n\
	adds r1, r5, #0\n\
	adds r1, #0xd0\n\
	str r0, [r1]\n\
	subs r1, #0x18\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r1]\n\
	ldr r0, [r5, #0x58]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0804B124\n\
	ldr r1, _0804B120 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r6, [r5, #0xd]\n\
	b _0804B13A\n\
	.align 2, 0\n\
_0804B110: .4byte sCollisions\n\
_0804B114: .4byte hellbat_0804cc38\n\
_0804B118: .4byte gStageRun+232\n\
_0804B11C: .4byte 0xFFFFB000\n\
_0804B120: .4byte gBossFnTable\n\
_0804B124:\n\
	ldr r1, _0804B150 @ =gBossFnTable\n\
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
_0804B13A:\n\
	strb r6, [r5, #0xe]\n\
	strb r6, [r5, #0xf]\n\
	movs r0, #0\n\
	strb r0, [r5, #0x11]\n\
	adds r0, r5, #0\n\
	bl Hellbat_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0804B150: .4byte gBossFnTable\n\
 .syntax divided\n");
}

void FUN_0804b520(struct Boss* p);
void FUN_0804b56c(struct Boss* p);
void FUN_0804b5e8(struct Boss* p);
void FUN_0804b6b4(struct Boss* p);
void FUN_0804b900(struct Boss* p);
void FUN_0804ba40(struct Boss* p);
void FUN_0804bcf4(struct Boss* p);
void FUN_0804bee0(struct Boss* p);
void FUN_0804c220(struct Boss* p);
void FUN_0804c554(struct Boss* p);
void nop_0804c9ec(struct Boss* p);
void FUN_0804caa0(struct Boss* p);

// clang-format off
static const BossFunc sUpdates1[12] = {
    FUN_0804b520,
    FUN_0804b56c,
    FUN_0804b5e8,
    FUN_0804b6b4,
    FUN_0804b900,
    FUN_0804ba40,
    FUN_0804bcf4,
    FUN_0804bee0,
    FUN_0804c220,
    FUN_0804c554,
    nop_0804c9ec,
    FUN_0804caa0,
};
// clang-format on

void hellbatMode0(struct Boss* p);
void hellbatMode1(struct Boss* p);
void hellbatMode2(struct Boss* p);
void hellbatNeutral(struct Boss* p);
void hellbatMode4(struct Boss* p);
void hellbatDisappear(struct Boss* p);
void hellbatBatShower(struct Boss* p);
void hellbatEchoWave(struct Boss* p);
void hellbatThunderRevorb(struct Boss* p);
void hellbatEX(struct Boss* p);
void hellbatDamage(struct Boss* p);
void hellbatKnockBackDamage(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[12] = {
    hellbatMode0,
    hellbatMode1,
    hellbatMode2,
    hellbatNeutral,
    hellbatMode4,
    hellbatDisappear,
    hellbatBatShower,
    hellbatEchoWave,
    hellbatThunderRevorb,
    hellbatEX,
    hellbatDamage,
    hellbatKnockBackDamage,
};
// clang-format on

static void Hellbat_Update(struct Boss* p) {
  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    if (!(gStageRun.missionStatus & MISSION_FAIL)) {
      SET_BOSS_ROUTINE(p, ENTITY_DIE);
      PlaySound(SE_HELLBAT_DEATH);
      if ((p->body).status & BODY_STATUS_SLASHED) {
        (p->s).mode[3] = 1;
      } else {
        (p->s).mode[3] = 0;
      }
      Hellbat_Die(p);
      return;
    }
  }

  (sUpdates1[(p->s).mode[1]])(p);
  hellbat_0804cbe4(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

void hellbatDeath0(struct Boss* p);
void hellbatDeath1(struct Boss* p);

static void Hellbat_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      hellbatDeath0,
      hellbatDeath1,
  };
  (sDeads[(p->s).mode[1]])(p);
}

INCASM("asm/boss/hellbat.inc");

static const struct Collision sCollisions[29] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x00,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
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
      remaining : 4,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [2] = {
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
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [3] = {
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
      remaining : 2,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
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
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [5] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : METAL,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 6,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 5,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
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
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
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
      hitzone : 0,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
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
      hitzone : 6,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 6,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [12] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : METAL,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

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
      remaining : 7,
      unk_0c : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
    },
    [14] = {
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
      remaining : 6,
      unk_0c : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
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
      remaining : 5,
      unk_0c : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
    },
    [16] = {
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
      remaining : 4,
      unk_0c : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
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
      remaining : 3,
      unk_0c : 0x00000001,
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [18] = {
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
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [19] = {
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
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
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
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
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
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [22] = {
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
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
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
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [24] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0x06,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [25] = {
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
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [26] = {
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
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [27] = {
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
      remaining : 1,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [28] = {
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
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
};

static const struct Coord sCoords[3] = {
    {0x00000000, -0x00002000},
    {0x00000000, -0x00002000},
    {0x00000000, -0x00002000},
};
