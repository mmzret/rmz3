#include "blink.h"
#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

// I call Omega Second Form "Omega ZX" because his shoulder pads look like Zero and X.

struct OmegaZXProjectileTemplate {
  motion_t motions[2];
  u8 unk_4;
  u8 _;
} PACKED;

static void OmegaZX_Init(struct Boss* p);
static void OmegaZX_Update(struct Boss* p);
static void OmegaZX_Die(struct Boss* p);
static void OmegaZX_Disappear(struct Boss* p);

// clang-format off
const BossRoutine gOmegaZXRoutine = {
    [ENTITY_INIT] =      OmegaZX_Init,
    [ENTITY_UPDATE] =    OmegaZX_Update,
    [ENTITY_DIE] =       OmegaZX_Die,
    [ENTITY_DISAPPEAR] = OmegaZX_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateOmegaZX(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_BOSS_ROUTINE(p, BOSS_OMEGA_ZX);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

// --------------------------------------------

NAKED static void OmegaZX_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	adds r2, r5, #0\n\
	adds r2, #0x5c\n\
	bl FUN_08016094\n\
	ldr r0, _08060C04 @ =gOverworld\n\
	ldr r1, _08060C08 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r4, #0\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _08060C0C @ =sCollisions\n\
	adds r0, r5, #0\n\
	movs r2, #0x60\n\
	bl ResetBossBody\n\
	ldr r1, _08060C10 @ =FUN_080616b8\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x40\n\
	strb r4, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r3, r5, #0\n\
	adds r3, #0xbc\n\
	str r4, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb7\n\
	strb r4, [r0]\n\
	adds r0, #9\n\
	movs r1, #0\n\
	mov ip, r1\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, _08060C14 @ =0xFFFFB000\n\
	adds r7, r0, r1\n\
	ldr r0, _08060C18 @ =gStageRun+232\n\
	ldr r0, [r0, #0x3c]\n\
	ldr r1, _08060C1C @ =0x00003FFF\n\
	adds r7, r0, r1\n\
	ldr r1, _08060C20 @ =0xFFFFD800\n\
	adds r0, r7, r1\n\
	str r0, [r5, #0x58]\n\
	adds r2, r5, #0\n\
	adds r2, #0xb8\n\
	str r0, [r2]\n\
	ldr r0, [r5, #0x58]\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #8\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [r5, #0x5c]\n\
	str r1, [r5, #0x60]\n\
	ldr r0, [r2]\n\
	str r0, [r5, #0x68]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	str r4, [r5, #0x2c]\n\
	str r4, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0xc4\n\
	str r4, [r0]\n\
	adds r0, #8\n\
	str r4, [r0]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _08060C28\n\
	ldr r1, _08060C24 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	mov r0, ip\n\
	strb r0, [r5, #0xd]\n\
	strb r0, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	b _08060C44\n\
	.align 2, 0\n\
_08060C04: .4byte gOverworld\n\
_08060C08: .4byte 0x0002D025\n\
_08060C0C: .4byte sCollisions\n\
_08060C10: .4byte FUN_080616b8\n\
_08060C14: .4byte 0xFFFFB000\n\
_08060C18: .4byte gStageRun+232\n\
_08060C1C: .4byte 0x00003FFF\n\
_08060C20: .4byte 0xFFFFD800\n\
_08060C24: .4byte gBossFnTable\n\
_08060C28:\n\
	ldr r1, _08060CA0 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	mov r1, ip\n\
	strb r1, [r5, #0xe]\n\
	strb r1, [r5, #0xf]\n\
_08060C44:\n\
	mov r0, sp\n\
	movs r1, #0\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	mov r0, sp\n\
	movs r1, #1\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	mov r0, sp\n\
	movs r1, #2\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	adds r1, r5, #0\n\
	adds r1, #0xcc\n\
	str r0, [r1]\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #2\n\
	movs r0, #0xa7\n\
	adds r1, r4, #0\n\
	bl LoadBlink\n\
	movs r1, #0xb8\n\
	lsls r1, r1, #2\n\
	movs r0, #0xa8\n\
	bl LoadBlink\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	movs r0, #0xa9\n\
	bl LoadBlink\n\
	movs r0, #0xaa\n\
	adds r1, r4, #0\n\
	bl LoadBlink\n\
	adds r0, r5, #0\n\
	bl OmegaZX_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08060CA0: .4byte gBossFnTable\n\
 .syntax divided\n");
}

void FUN_08060f98(struct Boss* p);
void FUN_08060fd8(struct Boss* p);
void FUN_08061064(struct Boss* p);
void FUN_080610a8(struct Boss* p);
void FUN_08061230(struct Boss* p);
void FUN_080612d4(struct Boss* p);
void FUN_080613b8(struct Boss* p);
void FUN_080614a4(struct Boss* p);
void FUN_080615d8(struct Boss* p);

void FUN_08060f9c(struct Boss* p);
void FUN_08060fdc(struct Boss* p);
void FUN_08061068(struct Boss* p);
void Boss22Neutral(struct Boss* p);
void FUN_08061234(struct Boss* p);
void FUN_080612d8(struct Boss* p);
void FUN_080613bc(struct Boss* p);
void FUN_080614a8(struct Boss* p);
void FUN_080615dc(struct Boss* p);

static void OmegaZX_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[9] = {
      FUN_08060f98,
      FUN_08060fd8,
      FUN_08061064,
      FUN_080610a8,
      FUN_08061230,
      FUN_080612d4,
      FUN_080613b8,
      FUN_080614a4,
      FUN_080615d8,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[9] = {
      FUN_08060f9c,
      FUN_08060fdc,
      FUN_08061068,
      Boss22Neutral,
      FUN_08061234,
      FUN_080612d8,
      FUN_080613bc,
      FUN_080614a8,
      FUN_080615dc,
  };
  // clang-format on

  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    if (!(gStageRun.missionStatus & MISSION_FAIL)) {
      SET_BOSS_ROUTINE(p, ENTITY_DIE);
      OmegaZX_Die(p);
      return;
    }
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

void FUN_08060d60(struct Boss* p);
void FUN_08060e14(struct Boss* p);

static void OmegaZX_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      FUN_08060d60,
      FUN_08060e14,
  };
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void OmegaZX_Disappear(struct Boss* p) {
  ClearBlink(167);
  ClearBlink(168);
  ClearBlink(169);
  ClearBlink(170);
  DeleteBoss(p);
}

// --------------------------------------------

INCASM("asm/boss/omega_zx.inc");

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(3), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
};

static const struct OmegaZXProjectileTemplate sOmegaZXProjectileTemplates[18] = {
    [0] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [1] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [2] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [3] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [4] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [5] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [6] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [7] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [8] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [9] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [10] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [11] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [12] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [13] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [14] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [15] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [16] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [17] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
};
