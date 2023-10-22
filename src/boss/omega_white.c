#include "blink.h"
#include "boss.h"
#include "collision.h"
#include "enemy.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "sound.h"
#include "vfx.h"

struct VFX *omegaWhite_080b91d4(struct Coord *c, u8 r1, struct Boss *p);
void omegaWhite_0800bd24(struct Boss *p);
static void onCollision(struct Body *body, struct Coord *c1, struct Coord *c2);

static const struct Collision sCollisions[8];

static void OmegaWhite_Init(struct Boss *p);
static void OmegaWhite_Update(struct Boss *p);
static void OmegaWhite_Die(struct Boss *p);
static void OmegaWhite_Disappear(struct Boss *p);

// clang-format off
const BossRoutine gOmegaWhiteRoutine = {
    [ENTITY_INIT] =      OmegaWhite_Init,
    [ENTITY_UPDATE] =    OmegaWhite_Update,
    [ENTITY_DIE] =       OmegaWhite_Die,
    [ENTITY_DISAPPEAR] = OmegaWhite_Disappear,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

static void floatOmegaWhite(struct Boss *p);

struct Boss *CreateOmegaWhite(struct Coord *c, u8 n) {
  struct Boss *p = (struct Boss *)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_BOSS_ROUTINE(p, BOSS_OMEGA_WHITE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

WIP static void OmegaWhite_Init(struct Boss *p) {
#if MODERN
  s32 y;
  struct Coord c;
  struct Body *body;

  omegaWhite_0800bd24(p);
  gOverworld.unk_1c8.work[1] = 0;
  LOAD_STATIC_GRAPHIC(SM009_OMEGA_HAND);
  LOAD_STATIC_GRAPHIC(SM010_OMEGA_RING);
  LOAD_STATIC_GRAPHIC(SM011_OMEGA_RECOVER);
  LOAD_STATIC_GRAPHIC(SM012_OMEGA_RUBBLE);

  ResetBossBody(p, &sCollisions[0], 64);
  body = &p->body;
  body->fn = onCollision;

  (p->props).omegaWhite.unk_b4 = 0;
  (p->props).omegaWhite.unk_b5[0] = -1;
  (p->props).omegaWhite.unk_b5[1] = -1;
  (p->props).omegaWhite.unk_bc = 0;
  (p->props).omegaWhite.unk_b7 = 0;
  (p->props).omegaWhite.unk_c0 = 0;
  (p->props).omegaWhite.unk_d4 = 0;

  y = (p->s).coord.y - PIXEL(80);
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, y);
  (p->s).unk_coord.y = (p->props).omegaWhite.unk_y = (p->s).coord.y;

  if ((p->s).work[0] == 0) {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 0;
  } else {
    SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 3;
  }
  (p->s).mode[2] = 0;
  (p->s).mode[3] = 0;
  CreateOmegaWhiteHand(&c, FALSE, p);
  (p->s).unk_2c = (struct Entity *)omegaWhite_080b91d4(&c, 2, p);
  CreateOmegaWhiteHand(&c, TRUE, p);
  LoadBlink(11, 672);
  OmegaWhite_Update(p);
#else
  INCCODE("asm/wip/OmegaWhite_Init.inc");
#endif
}

// --------------------------------------------

static void omegaWhite_0803e244(struct Boss *p);
static void omegaWhiteIntoMode2(struct Boss *p);
static void omegaWhiteNeutral(struct Boss *p);
static void omegaWhiteLaser(struct Boss *p);
static void omegaWhite_0803e2a0(struct Boss *p);
static bool8 changeOmegaWhiteMode(struct Boss *p);
static bool8 nop_0803e240(struct Boss *_);
static bool8 nop_0803e278(struct Boss *_);
static bool8 nop_0803e29c(struct Boss *_);
static bool8 nop_0803e390(struct Boss *_);
static bool8 nop_0803e51c(struct Boss *_);
static bool8 nop_0803e5e8(struct Boss *_);
static void omegaWhite_0803e520(struct Boss *p);
static void omegaWhite_0803e5ec(struct Boss *p);

static void OmegaWhite_Update(struct Boss *p) {
  // clang-format off
  static const BossFunc sUpdates1[7] = {
      (BossFunc)nop_0803e240,
      (BossFunc)nop_0803e278,
      (BossFunc)nop_0803e29c,
      (BossFunc)changeOmegaWhiteMode,
      (BossFunc)nop_0803e390,
      (BossFunc)nop_0803e51c,
      (BossFunc)nop_0803e5e8,
  };
  // clang-format on
  // clang-format off
  static const BossFunc sUpdates2[7] = {
      omegaWhite_0803e244,
      omegaWhiteIntoMode2,
      omegaWhite_0803e2a0,
      omegaWhiteNeutral,
      omegaWhiteLaser,
      omegaWhite_0803e520,
      omegaWhite_0803e5ec,
  };
  // clang-format on

  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    u16 failed = gStageRun.missionStatus & MISSION_FAIL;
    if ((failed == 0) && ((p->s).mode[1] != 6)) {
      PlaySound(SE_OMEGA1_DEATH);
      (p->s).mode[1] = 6;
      (p->s).mode[2] = failed;
    }
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void omegaWhite_0803e148(struct Boss *p);
static void omegaWhite_0803e1f8(struct Boss *p);

static void OmegaWhite_Die(struct Boss *p) {
  static const BossFunc seq[2] = {
      omegaWhite_0803e148,
      omegaWhite_0803e1f8,
  };
  (seq[(p->s).mode[1]])(p);
}

static void OmegaWhite_Disappear(struct Boss *p) {
  ClearBlink(11);
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  (p->s).flags &= ~DISPLAY;
  gOverworld.unk_1c8.work[1] = 0;
  DeleteBoss(p);
}

NAKED static void omegaWhite_0803e148(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0803E1BA\n\
	cmp r0, #1\n\
	bgt _0803E162\n\
	cmp r0, #0\n\
	beq _0803E168\n\
	b _0803E1F0\n\
_0803E162:\n\
	cmp r0, #2\n\
	beq _0803E1DC\n\
	b _0803E1F0\n\
_0803E168:\n\
	ldr r3, _0803E1D4 @ =gStageRun\n\
	ldrh r2, [r3, #8]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0803E18A\n\
	ldrb r1, [r3, #0x12]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E18A\n\
	ldr r0, _0803E1D8 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
_0803E18A:\n\
	movs r0, #0xe8\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r2, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r2\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x5c\n\
	str r1, [r0, #4]\n\
	str r1, [r4, #0x5c]\n\
	movs r0, #0x5a\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E1BA:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803E1F0\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E1F0\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0803E1F0\n\
	.align 2, 0\n\
_0803E1D4: .4byte gStageRun\n\
_0803E1D8: .4byte 0x0000FFFE\n\
_0803E1DC:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803E1F0\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0803E1F0:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void omegaWhite_0803e1f8(struct Boss *p) {
  u8 phase = (p->s).mode[2];
  switch (phase) {
    case 0: {
      ClearBlink(11);
      (p->s).flags &= ~DISPLAY;
      gOverworld.unk_1c8.work[1] = phase;
      (p->s).mode[2]++;
    }
    case 1: {
      gStageRun.vm.active |= (1 << 1);
    }
  }
}

static bool8 nop_0803e240(struct Boss *_) { return TRUE; }

static void omegaWhite_0803e244(struct Boss *p) {
  if ((p->s).mode[2] == 0) {
    gOverworld.unk_1c8.work[1] = 1;
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
    p->props.omegaWhite.unk_d4 |= (1 << 0);
    (p->s).mode[2]++;
  }
}

static bool8 nop_0803e278(struct Boss *_) { return TRUE; }

static void omegaWhiteIntoMode2(struct Boss *p) {
  u8 phase = (p->s).mode[2];
  switch (phase) {
    case 0: {
      (p->s).mode[2] = 1;
    }
    case 1: {
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
    }
  }
}

static bool8 nop_0803e29c(struct Boss *_) { return TRUE; }

static void omegaWhite_0803e2a0(struct Boss *p) {
  u8 phase = (p->s).mode[2];
  switch (phase) {
    case 0: {
      (p->s).mode[2] = 1;
    }
    case 1: {
      u8 new_phase = gStageRun.vm.active & 1;
      if ((gStageRun.vm.active & 1) == 0) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = new_phase;
      }
    }
  }
}

// クールタイム終了後のオメガのモードをランダムに4か5にする
NAKED static bool8 changeOmegaWhiteMode(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3, #0xe]\n\
	cmp r0, #0\n\
	beq _0803E34E\n\
	ldrb r0, [r3, #0x13]\n\
	cmp r0, #0\n\
	beq _0803E34E\n\
	subs r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	bne _0803E34E\n\
	ldr r2, _0803E31C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0803E320 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803E324 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	cmp r0, #7\n\
	bhi _0803E32C\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	ldr r1, _0803E328 @ =0x00FFFF00\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803E348\n\
	movs r0, #4\n\
	b _0803E34A\n\
	.align 2, 0\n\
_0803E31C: .4byte RNG_0202f388\n\
_0803E320: .4byte 0x000343FD\n\
_0803E324: .4byte 0x00269EC3\n\
_0803E328: .4byte 0x00FFFF00\n\
_0803E32C:\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	ldr r1, _0803E340 @ =0x00FFFF00\n\
	ands r0, r1\n\
	ldr r1, _0803E344 @ =0x00010100\n\
	cmp r0, r1\n\
	bne _0803E348\n\
	movs r0, #4\n\
	b _0803E34A\n\
	.align 2, 0\n\
_0803E340: .4byte 0x00FFFF00\n\
_0803E344: .4byte 0x00010100\n\
_0803E348:\n\
	movs r0, #5\n\
_0803E34A:\n\
	strb r0, [r3, #0xd]\n\
	strb r4, [r3, #0xe]\n\
_0803E34E:\n\
	movs r0, #1\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// オメガが縦にふわふわして何もしていない状態(2秒間)
static void omegaWhiteNeutral(struct Boss *p) {
  u8 phase = (p->s).mode[2];
  switch (phase) {
    case 0: {
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).d.x = (p->s).d.y = 0;
      (p->s).work[3] = 2 * SECOND;
      (p->s).mode[2]++;
    }
    case 1: {
      floatOmegaWhite(p);
    }
  }
}

static bool8 nop_0803e390(struct Boss *_) { return TRUE; }

// オメガレーザー(3発の球体を打つやつ)
NAKED static void omegaWhiteLaser(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #4\n\
	bls _0803E3A2\n\
	b _0803E500\n\
_0803E3A2:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0803E3AC @ =_0803E3B0\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0803E3AC: .4byte _0803E3B0\n\
_0803E3B0: @ jump table\n\
	.4byte _0803E3C4 @ case 0\n\
	.4byte _0803E444 @ case 1\n\
	.4byte _0803E494 @ case 2\n\
	.4byte _0803E4B2 @ case 3\n\
	.4byte _0803E4DC @ case 4\n\
_0803E3C4:\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x5c\n\
	str r2, [r0, #4]\n\
	str r2, [r4, #0x5c]\n\
	movs r0, #3\n\
	strb r0, [r4, #0x12]\n\
	ldr r2, _0803E410 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0803E414 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803E418 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E41C\n\
	strb r0, [r4, #0xf]\n\
	b _0803E41E\n\
	.align 2, 0\n\
_0803E410: .4byte RNG_0202f388\n\
_0803E414: .4byte 0x000343FD\n\
_0803E418: .4byte 0x00269EC3\n\
_0803E41C:\n\
	strb r1, [r4, #0xf]\n\
_0803E41E:\n\
	mov r0, sp\n\
	movs r1, #3\n\
	adds r2, r4, #0\n\
	bl omegaWhite_080b91d4\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	str r0, [r1]\n\
	adds r3, r4, #0\n\
	adds r3, #0xb5\n\
	ldrb r1, [r3]\n\
	adds r2, r4, #0\n\
	adds r2, #0xb6\n\
	movs r0, #0\n\
	strb r1, [r2]\n\
	strb r0, [r3]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E444:\n\
	movs r0, #0x30\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _0803E46C\n\
	movs r0, #0x84\n\
	lsls r0, r0, #3\n\
	ldr r2, _0803E468 @ =u8_ARRAY_080fecec\n\
	ldrb r1, [r4, #0x12]\n\
	subs r1, #1\n\
	adds r1, r1, r2\n\
	ldrb r1, [r1]\n\
	movs r2, #0x30\n\
	adds r3, r4, #0\n\
	bl createOmega1Laser\n\
	b _0803E482\n\
	.align 2, 0\n\
_0803E468: .4byte u8_ARRAY_080fecec\n\
_0803E46C:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #3\n\
	ldr r2, _0803E490 @ =0x080FECEF\n\
	ldrb r1, [r4, #0x12]\n\
	subs r1, #1\n\
	adds r1, r1, r2\n\
	ldrb r1, [r1]\n\
	movs r2, #0x30\n\
	adds r3, r4, #0\n\
	bl createOmega1Laser\n\
_0803E482:\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0803E500\n\
	.align 2, 0\n\
_0803E490: .4byte 0x080FECEF\n\
_0803E494:\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	beq _0803E4AA\n\
	subs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E4AA\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E4AA:\n\
	adds r0, r4, #0\n\
	bl floatOmegaWhite\n\
	b _0803E4D4\n\
_0803E4B2:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	bne _0803E4D0\n\
	adds r0, r4, #0\n\
	adds r0, #0xbc\n\
	str r1, [r0]\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	b _0803E4D2\n\
_0803E4D0:\n\
	movs r0, #1\n\
_0803E4D2:\n\
	strb r0, [r4, #0xe]\n\
_0803E4D4:\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	b _0803E500\n\
_0803E4DC:\n\
	adds r0, r4, #0\n\
	bl floatOmegaWhite\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803E500\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	bne _0803E500\n\
	movs r0, #3\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0803E500:\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	add sp, #8\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static bool8 nop_0803e51c(struct Boss *_) { return TRUE; }

NAKED static void omegaWhite_0803e520(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #0xe]\n\
	cmp r2, #1\n\
	beq _0803E57A\n\
	cmp r2, #1\n\
	bgt _0803E534\n\
	cmp r2, #0\n\
	beq _0803E53A\n\
	b _0803E5E0\n\
_0803E534:\n\
	cmp r2, #2\n\
	beq _0803E5BA\n\
	b _0803E5E0\n\
_0803E53A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	str r2, [r4, #0x60]\n\
	str r2, [r4, #0x5c]\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	strb r0, [r4, #0x13]\n\
	adds r2, r4, #0\n\
	adds r2, #0xb5\n\
	ldrb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0xb6\n\
	strb r0, [r1]\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E57A:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803E586\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	b _0803E5A0\n\
_0803E586:\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	beq _0803E5A0\n\
	subs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E5A0\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E5A0:\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	b _0803E5E0\n\
_0803E5BA:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803E5CA\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E5DA\n\
_0803E5CA:\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	movs r2, #0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #3\n\
	strb r0, [r4, #0xd]\n\
	strb r2, [r4, #0xe]\n\
_0803E5DA:\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
_0803E5E0:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static bool8 nop_0803e5e8(struct Boss *_) { return TRUE; }

NAKED static void omegaWhite_0803e5ec(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	movs r0, #0xb\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #5\n\
	bls _0803E5FE\n\
	b _0803E7E6\n\
_0803E5FE:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0803E608 @ =_0803E60C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0803E608: .4byte _0803E60C\n\
_0803E60C: @ jump table\n\
	.4byte _0803E624 @ case 0\n\
	.4byte _0803E650 @ case 1\n\
	.4byte _0803E68C @ case 2\n\
	.4byte _0803E704 @ case 3\n\
	.4byte _0803E73E @ case 4\n\
	.4byte _0803E7B4 @ case 5\n\
_0803E624:\n\
	ldr r3, _0803E684 @ =gStageRun\n\
	ldrh r2, [r3, #8]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0803E646\n\
	ldrb r1, [r3, #0x12]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E646\n\
	ldr r0, _0803E688 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
_0803E646:\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E650:\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E670\n\
	b _0803E7E6\n\
_0803E670:\n\
	adds r2, r4, #0\n\
	adds r2, #0xd4\n\
	ldr r0, [r2]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	b _0803E7E0\n\
	.align 2, 0\n\
_0803E684: .4byte gStageRun\n\
_0803E688: .4byte 0x0000FFFE\n\
_0803E68C:\n\
	adds r0, r4, #0\n\
	adds r0, #0xd4\n\
	ldr r1, [r0]\n\
	movs r2, #3\n\
	rsbs r2, r2, #0\n\
	ands r1, r2\n\
	str r1, [r0]\n\
	ldrb r1, [r4, #0x12]\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	beq _0803E6AC\n\
	subs r0, r1, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E6CE\n\
_0803E6AC:\n\
	ldr r2, _0803E6F8 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0803E6FC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803E700 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	adds r0, #0x28\n\
	strb r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	bl PaintEntityWhite\n\
_0803E6CE:\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E6EE\n\
	b _0803E7E6\n\
_0803E6EE:\n\
	ldr r0, [r5]\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	str r0, [r5]\n\
	b _0803E7E0\n\
	.align 2, 0\n\
_0803E6F8: .4byte RNG_0202f388\n\
_0803E6FC: .4byte 0x000343FD\n\
_0803E700: .4byte 0x00269EC3\n\
_0803E704:\n\
	adds r2, r4, #0\n\
	adds r2, #0xd4\n\
	ldr r0, [r2]\n\
	movs r1, #9\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803E7E6\n\
	ldr r0, [r2]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	b _0803E7E0\n\
_0803E73E:\n\
	adds r2, r4, #0\n\
	adds r2, #0xd4\n\
	ldr r0, [r2]\n\
	movs r1, #3\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldrb r0, [r4, #0x12]\n\
	adds r5, r2, #0\n\
	cmp r0, #0\n\
	beq _0803E770\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803E792\n\
_0803E770:\n\
	ldr r2, _0803E7A8 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _0803E7AC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803E7B0 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	adds r0, #0x28\n\
	strb r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	bl PaintEntityWhite\n\
_0803E792:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803E7E6\n\
	ldr r0, [r5]\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	str r0, [r5]\n\
	b _0803E7E0\n\
	.align 2, 0\n\
_0803E7A8: .4byte RNG_0202f388\n\
_0803E7AC: .4byte 0x000343FD\n\
_0803E7B0: .4byte 0x00269EC3\n\
_0803E7B4:\n\
	adds r2, r4, #0\n\
	adds r2, #0xd4\n\
	ldr r0, [r2]\n\
	movs r1, #9\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #5\n\
	asrs r0, r0, #8\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803E7E6\n\
_0803E7E0:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803E7E6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 0x0803e7ec
NAKED static void onCollision(struct Body *body, struct Coord *c1, struct Coord *c2) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldr r1, [r3, #0x2c]\n\
	ldr r2, [r1, #0x2c]\n\
	cmp r2, #0\n\
	beq _0803E80C\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #1\n\
	bls _0803E804\n\
	movs r0, #0\n\
	str r0, [r1, #0x2c]\n\
	b _0803E80C\n\
_0803E804:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
_0803E80C:\n\
	ldr r0, [r3, #0x2c]\n\
	adds r1, r0, #0\n\
	adds r1, #0xbc\n\
	ldr r2, [r1]\n\
	cmp r2, #0\n\
	beq _0803E82C\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #1\n\
	bls _0803E824\n\
	movs r0, #0\n\
	str r0, [r1]\n\
	b _0803E82C\n\
_0803E824:\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
_0803E82C:\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// オメガが縦にふわふわする処理
static void floatOmegaWhite(struct Boss *p) {
  u16 val = ((p->props.omegaWhite).unk_c0 + 1) & 0xFF;
  (p->props.omegaWhite).unk_c0 = val;
  (p->s).coord.y = (p->s).unk_coord.y + (gSineTable[val] << 3);
}

static const struct Collision sCollisions[8] = {
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

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 2,
      layer : 1,
      range : {PIXEL(20), -PIXEL(64), PIXEL(54), PIXEL(128)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {PIXEL(2), -PIXEL(102), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(16), PIXEL(28)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      remaining : 1,
      layer : 1,
      range : {PIXEL(0), PIXEL(3), PIXEL(40), PIXEL(80)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(80), PIXEL(24), PIXEL(24)},
    },
};
