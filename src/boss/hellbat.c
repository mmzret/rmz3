#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"

static const struct Collision sCollisions[29];
static const struct Coord sExplosionCoords[2];

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

// --------------------------------------------

static bool32 nop_0804b520(struct Boss* p);
static bool32 nop_0804b56c(struct Boss* p);
static bool32 nop_0804b5e8(struct Boss* p);
static bool32 nop_0804b6b4(struct Boss* p);
void FUN_0804b900(struct Boss* p);
void FUN_0804ba40(struct Boss* p);
void FUN_0804bcf4(struct Boss* p);
void FUN_0804bee0(struct Boss* p);
void FUN_0804c220(struct Boss* p);
void FUN_0804c554(struct Boss* p);
void nop_0804c9ec(struct Boss* p);
void FUN_0804caa0(struct Boss* p);

static void hellbatMode0(struct Boss* p);
static void hellbatMode1(struct Boss* p);
static void hellbatMode2(struct Boss* p);
void hellbatNeutral(struct Boss* p);
void hellbatMode4(struct Boss* p);
void hellbatDisappear(struct Boss* p);
void hellbatBatShower(struct Boss* p);
void hellbatEchoWave(struct Boss* p);
void hellbatThunderRevorb(struct Boss* p);
void hellbatEX(struct Boss* p);
void hellbatDamage(struct Boss* p);
void hellbatKnockBackDamage(struct Boss* p);

static void Hellbat_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[12] = {
      (BossFunc)nop_0804b520,
      (BossFunc)nop_0804b56c,
      (BossFunc)nop_0804b5e8,
      (BossFunc)nop_0804b6b4,
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

// --------------------------------------------

static void hellbatDeath0(struct Boss* p);
static void hellbatDeath1(struct Boss* p);

static void Hellbat_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      hellbatDeath0,
      hellbatDeath1,
  };
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

NAKED static void hellbatDeath0(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0xe]\n\
	cmp r0, #1\n\
	beq _0804B2A8\n\
	cmp r0, #1\n\
	bgt _0804B220\n\
	cmp r0, #0\n\
	beq _0804B226\n\
	b _0804B2D0\n\
_0804B220:\n\
	cmp r0, #2\n\
	beq _0804B2C8\n\
	b _0804B2D0\n\
_0804B226:\n\
	ldr r4, _0804B2C0 @ =gStageRun\n\
	ldrh r3, [r4, #8]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0804B248\n\
	ldrb r1, [r4, #0x12]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0804B248\n\
	ldr r0, _0804B2C4 @ =0x0000FFFE\n\
	ands r0, r3\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
_0804B248:\n\
	ldrb r0, [r2, #0xa]\n\
	movs r1, #1\n\
	movs r4, #0\n\
	orrs r1, r0\n\
	strb r1, [r2, #0xa]\n\
	movs r0, #0x20\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0804B280\n\
	adds r0, r2, #0\n\
	adds r0, #0x4d\n\
	strb r4, [r0]\n\
	adds r3, r2, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldr r0, [r2, #0x58]\n\
	movs r1, #0xe4\n\
	lsls r1, r1, #6\n\
	adds r0, r0, r1\n\
	str r0, [r2, #0x58]\n\
_0804B280:\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	strb r4, [r0]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x5c\n\
	str r4, [r0, #4]\n\
	str r4, [r2, #0x5c]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x12]\n\
	ldrb r0, [r2, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xe]\n\
_0804B2A8:\n\
	ldrb r0, [r2, #0x12]\n\
	cmp r0, #0\n\
	beq _0804B2D0\n\
	subs r0, #1\n\
	strb r0, [r2, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0804B2D0\n\
	ldrb r0, [r2, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xe]\n\
	b _0804B2D0\n\
	.align 2, 0\n\
_0804B2C0: .4byte gStageRun\n\
_0804B2C4: .4byte 0x0000FFFE\n\
_0804B2C8:\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
_0804B2D0:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void hellbatDeath1(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0x19\n\
	bls _0804B2E6\n\
	b _0804B514\n\
_0804B2E6:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0804B2F0 @ =_0804B2F4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0804B2F0: .4byte _0804B2F4\n\
_0804B2F4: @ jump table\n\
	.4byte _0804B35C @ case 0\n\
	.4byte _0804B3B4 @ case 1\n\
	.4byte _0804B3C4 @ case 2\n\
	.4byte _0804B436 @ case 3\n\
	.4byte _0804B468 @ case 4\n\
	.4byte _0804B514 @ case 5\n\
	.4byte _0804B514 @ case 6\n\
	.4byte _0804B514 @ case 7\n\
	.4byte _0804B514 @ case 8\n\
	.4byte _0804B514 @ case 9\n\
	.4byte _0804B3B4 @ case 10\n\
	.4byte _0804B47E @ case 11\n\
	.4byte _0804B514 @ case 12\n\
	.4byte _0804B514 @ case 13\n\
	.4byte _0804B514 @ case 14\n\
	.4byte _0804B514 @ case 15\n\
	.4byte _0804B514 @ case 16\n\
	.4byte _0804B514 @ case 17\n\
	.4byte _0804B514 @ case 18\n\
	.4byte _0804B514 @ case 19\n\
	.4byte _0804B490 @ case 20\n\
	.4byte _0804B49A @ case 21\n\
	.4byte _0804B4A8 @ case 22\n\
	.4byte _0804B4D0 @ case 23\n\
	.4byte _0804B4E8 @ case 24\n\
	.4byte _0804B4FC @ case 25\n\
_0804B35C:\n\
	ldr r1, _0804B3BC @ =0x0000A80B\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r2, r4, #0\n\
	adds r2, #0x8c\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0804B380\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bne _0804B392\n\
_0804B380:\n\
	ldr r0, _0804B3C0 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0804B392\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #1\n\
	beq _0804B394\n\
_0804B392:\n\
	movs r0, #0xa\n\
_0804B394:\n\
	strb r0, [r4, #0xe]\n\
	movs r1, #0\n\
	str r1, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
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
_0804B3B4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0804B4DC\n\
	.align 2, 0\n\
_0804B3BC: .4byte 0x0000A80B\n\
_0804B3C0: .4byte gStageRun\n\
_0804B3C4:\n\
	movs r0, #0\n\
	str r0, [r4, #0x60]\n\
	ldr r2, [r4, #0x54]\n\
	str r2, [sp]\n\
	ldr r3, [r4, #0x58]\n\
	str r3, [sp, #4]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0804B3DC\n\
	str r2, [sp]\n\
_0804B3DC:\n\
	ldr r1, _0804B3FC @ =0xFFFFE000\n\
	adds r0, r3, r1\n\
	str r0, [sp, #4]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0xff\n\
	beq _0804B40A\n\
	cmp r0, #0xfe\n\
	bne _0804B400\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
	b _0804B42E\n\
	.align 2, 0\n\
_0804B3FC: .4byte 0xFFFFE000\n\
_0804B400:\n\
	ldr r0, _0804B41C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r0, r2\n\
	ble _0804B420\n\
_0804B40A:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #1\n\
	bl FUN_080b2b40\n\
	b _0804B42E\n\
	.align 2, 0\n\
_0804B41C: .4byte pZero2\n\
_0804B420:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
_0804B42E:\n\
	movs r0, #0x2f\n\
	bl PlaySound\n\
	b _0804B4DC\n\
_0804B436:\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	ldr r2, _0804B460 @ =0x0000A80D\n\
	ldrb r3, [r4, #0xa]\n\
	lsrs r3, r3, #4\n\
	movs r0, #1\n\
	ands r3, r0\n\
	adds r0, r4, #0\n\
	bl FUN_0809c3b4\n\
	ldr r1, _0804B464 @ =0x0000A80C\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	movs r0, #0x44\n\
	strb r0, [r4, #0x12]\n\
	b _0804B4DC\n\
	.align 2, 0\n\
_0804B460: .4byte 0x0000A80D\n\
_0804B464: .4byte 0x0000A80C\n\
_0804B468:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0804B47E\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0804B514\n\
_0804B47E:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0804B514\n\
	movs r0, #0x14\n\
	strb r0, [r4, #0xe]\n\
	b _0804B514\n\
_0804B490:\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0804B49A:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0804B514\n\
	b _0804B4DC\n\
_0804B4A8:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0804B4BC\n\
	ldr r1, _0804B4B8 @ =sExplosionCoords\n\
	b _0804B4BE\n\
	.align 2, 0\n\
_0804B4B8: .4byte sExplosionCoords\n\
_0804B4BC:\n\
	ldr r1, _0804B4E4 @ =sExplosionCoords+8\n\
_0804B4BE:\n\
	adds r0, r4, #0\n\
	bl CreateBossExplosion\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	str r0, [r1]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0804B4D0:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc0\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0804B514\n\
_0804B4DC:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0804B514\n\
	.align 2, 0\n\
_0804B4E4: .4byte sExplosionCoords+8\n\
_0804B4E8:\n\
	movs r0, #0x3c\n\
	strb r0, [r4, #0x12]\n\
	ldr r2, _0804B51C @ =gStageRun\n\
	ldrb r1, [r2, #0x12]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0804B4FC:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0804B50C\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0804B514\n\
_0804B50C:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_0804B514:\n\
	add sp, #8\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0804B51C: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool32 nop_0804b520(struct Boss* p) {
  // nop
  return TRUE;
}

static void hellbatMode0(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).flags |= DISPLAY;
      SetMotion(&p->s, MOTION(DM168_HELLBAT, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if (((p->s).scriptEntity)->flags & (1 << 0)) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b56c(struct Boss* p) {
  // nop
  return TRUE;
}

static void hellbatMode1(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).work[2] = 60;
      SetMotion(&p->s, MOTION(DM168_HELLBAT, 8));
      PlaySound(SE_HELLBAT_PREBATTLE);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[2]++;
      }
      break;
    }

    case 2: {
      if (((p->s).work[2] == 0) || (--(p->s).work[2]) == 0) {
        (p->s).mode[2]++;
      }
      break;
    }

    case 3: {
      UpdateMotionGraphic(&p->s);
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b5e8(struct Boss* p) {
  // nop
  return TRUE;
}

static void hellbatMode2(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, MOTION(DM168_HELLBAT, 1));
      (p->s).work[2] = 60;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[2]++;
      }
      break;
    }

    case 2: {
      s32 unk_d4 = (p->props.hellbat).unk_d4 - PIXEL(72);
      (p->s).coord.y += (((unk_d4 - (p->s).coord.y)) << 5) >> 8;
      UpdateMotionGraphic(&p->s);
      if (((p->s).work[2] == 0) || (--(p->s).work[2]) == 0) {
        (p->s).mode[2]++;
      }
      break;
    }

    case 3: {
      SetMotion(&p->s, MOTION(DM168_HELLBAT, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      UpdateMotionGraphic(&p->s);
      if (((p->s).motion.state == MOTION_END) && ((gStageRun.vm.active & 1) == 0)) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = 0;
      }
      break;
    }

    default: {
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b6b4(struct Boss* p) {
  // nop
  return TRUE;
}

INCASM("asm/boss/hellbat.inc");

static const struct Collision sCollisions[29] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
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
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
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
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [5] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

    [6] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      remaining : 6,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
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
      hitzone : 0,
      remaining : 5,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
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
      hitzone : 0,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [12] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(20), -PIXEL(21), PIXEL(11), PIXEL(42)},
    },

    // --------------------------------------------

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
      remaining : 7,
      layer : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 6,
      layer : 0x00000001,
      range : {0x1C00, -0x2E00, 0x1700, 0x2A00},
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
      remaining : 5,
      layer : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
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
      remaining : 4,
      layer : 0x00000001,
      range : {-0x1400, -0x2E00, 0x1200, 0x2A00},
    },
    [17] = {
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
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [18] = {
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
      range : {0x0300, -0x3D00, 0x1B00, 0x2600},
    },
    [19] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 1,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
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
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
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
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      hardness : 0x01,
      remaining : 1,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [24] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      hardness : 0x01,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
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
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [26] = {
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
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 1,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [28] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 0,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(32)};

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(32)},
    {PIXEL(0), -PIXEL(32)},
};
