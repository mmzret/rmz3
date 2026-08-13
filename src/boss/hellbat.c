#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

struct Projectile* FUN_080a1538(struct Entity* e, struct Coord* c, u8 a2);
struct VFX* createHellbatElectricBeam(struct Entity* e, struct Coord* c, u8 a2, u8 a3);

struct Hellbat {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[32];         // 0xB4
  s32 unk_d4;            // 0xD4
  u8 unk_d8[12];         // 0xD8
};
static_assert(sizeof(struct Hellbat) == sizeof(struct Boss));

static const struct Collision sCollisions[];
static const Coords32 sExplosionCoords[2];

void hellbat_0804cbe4(struct Boss* p);

static void Hellbat_Init(struct Boss* p);
static void Hellbat_Update(struct Boss* p);
static void Hellbat_Die(struct Boss* p);

// clang-format off
const BossRoutine gHellbatRoutine = {
    [ENTITY_INIT] =      (BossFunc)Hellbat_Init,
    [ENTITY_UPDATE] =    (BossFunc)Hellbat_Update,
    [ENTITY_DIE] =       (BossFunc)Hellbat_Die,
    [ENTITY_DISAPPEAR] = (BossFunc)DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Entity* CreateHellbat(Coords32* c, u8 n) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_HELLBAT);
    p->coord = *c;
    p->work[0] = n;
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
static bool32 nop_0804b6b4(void* _ UNUSED);
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
static void hellbatMode2(struct Hellbat* p);
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
      (void*)hellbatMode0,
      (void*)hellbatMode1,
      (void*)hellbatMode2,
      (void*)hellbatNeutral,
      (void*)hellbatMode4,
      (void*)hellbatDisappear,
      (void*)hellbatBatShower,
      (void*)hellbatEchoWave,
      (void*)hellbatThunderRevorb,
      (void*)hellbatEX,
      (void*)hellbatDamage,
      (void*)hellbatKnockBackDamage,
  };
  // clang-format on

  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    if (!(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
      SET_BOSS_ROUTINE(p, ENTITY_DIE);
      PlaySound(SE_HELLBAT_DEATH);
      if ((p->body).status & BODY_STATUS_SLASHED) {
        p->mode[3] = 1;
      } else {
        p->mode[3] = 0;
      }
      Hellbat_Die(p);
      return;
    }
  }

  (sUpdates1[p->mode[1]])((void*)p);
  hellbat_0804cbe4(p);
  (sUpdates2[p->mode[1]])((void*)p);
}

// --------------------------------------------

static void hellbatDeath0(struct Boss* p);
static void hellbatDeath1(struct Boss* p);

static void Hellbat_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      hellbatDeath0,
      hellbatDeath1,
  };
  (sDeads[p->mode[1]])((void*)p);
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
	bl UpdateEntityAnim\n\
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
	bl UpdateEntityAnim\n\
	movs r0, #0x44\n\
	strb r0, [r4, #0x12]\n\
	b _0804B4DC\n\
	.align 2, 0\n\
_0804B460: .4byte 0x0000A80D\n\
_0804B464: .4byte 0x0000A80C\n\
_0804B468:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
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

static bool32 nop_0804b520(struct Boss* p) { return TRUE; }

static void hellbatMode0(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->scriptEntity)->flags & (1 << 0)) {
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b56c(struct Boss* p) { return TRUE; }

static void hellbatMode1(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      p->work[2] = 60;
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 8));
      PlaySound(SE_HELLBAT_PREBATTLE);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) p->mode[2]++;
      break;
    }

    case 2: {
      if ((p->work[2] == 0) || (--p->work[2]) == 0) {
        p->mode[2]++;
      }
      break;
    }

    case 3: {
      UpdateSpriteAnimation(p);
      p->mode[1] = 2, p->mode[2] = 0;
      break;
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b5e8(struct Boss* p) { return TRUE; }

static void hellbatMode2(struct Hellbat* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 1));
      p->work[2] = 60;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) p->mode[2]++;
      break;
    }

    case 2: {
      s32 unk_d4 = p->unk_d4 - PIXEL(72);
      p->coord.y += (((unk_d4 - p->coord.y)) << 5) >> 8;
      UpdateSpriteAnimation(p);
      if ((p->work[2] == 0) || (--p->work[2]) == 0) {
        p->mode[2]++;
      }
      break;
    }

    case 3: {
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 2));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p) && !(gStageRun.vm.active & VM_ACTIVE)) {
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
    }

    default: {
    }
  }
}

// --------------------------------------------

static bool32 nop_0804b6b4(void* _) { return TRUE; }

INCASM("asm/boss/hellbat_a.inc");

void hellbatEX(struct Boss* p0) {
  register struct Boss* p asm("r5");
  s32 arr[3];
  struct Coord c;
  p = p0;
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0xA8, 0x0F));
      SetDDP(&p->body, (const struct Collision*)0x8363148);
      p->d.x = p->coord.x;
      p->work[2] = 0x14;
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      u32 w;
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      {
        u32 wt = p->work[2];
        u32 m = wt & 1;
        w = wt;
        asm("" : "+r"(w));
        if (m != 0) {
          p->flags |= 1;
        } else {
          p->flags &= 0xFE;
        }
      }
      if ((w << 24) != 0) {
        u32 t = w - 1;
        p->work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      SetDDP(&p->body, sCollisions);
      PlaySound(0x84);
      p->work[2] = 0xA;
      p->mode[2]++;
      break;
    }
    case 2:
      UpdateEntityAnim((struct Entity*)p);
      if (p->work[2] & 1) {
        p->flags |= 1;
      } else {
        p->flags &= 0xFE;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->work[2] = 0;
      p->mode[2]++;
      break;
    case 3: {
      u32 w = p->work[2];
      asm("" : "+r"(w));
      if (w & 1) {
        p->coord.x = p->d.x + ((w >> 2) << 8);
      } else {
        p->coord.x = p->d.x - (((u8)w >> 2) << 8);
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 t = p->work[2];
        if (t <= 0x27) {
          t++;
          p->work[2] = t;
          if ((u8)t <= 0x27) {
            break;
          }
        }
      }
      p->work[2] = 0x30;
      p->mode[2]++;
      break;
    }
    case 4:
      SetMotion((struct Entity*)p, MOTION(0xA8, 0x03));
      PlaySound(0x88);
      p->coord.y = *(s32*)((u8*)p + 0xd4) + -0x8E00;
      p->work[3] = 0;
      p->work[2] = 0x14;
      {
        register u8* c4d asm("r1");
        c4d = (u8*)p + 0x4d;
        *c4d = 1;
      }
      {
        register u8* oa asm("r2");
        register u32 k asm("r1");
        oa = (u8*)p + 0x4a;
        {
          u32 ov = *oa;
          asm("" : "+r"(ov));
          k = 0x20;
          ov |= k;
          *oa = ov;
        }
        k |= p->flags;
        k &= 0xFE;
        p->flags = k;
      }
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      u32 w;
      UpdateEntityAnim((struct Entity*)p);
      w = p->work[2];
      if (w != 0) {
        w--;
        p->work[2] = w;
        if ((w << 24) != 0) {
          break;
        }
      }
      p->work[2] = 0x30;
      p->mode[2]++;
      break;
    }
    case 6: {
      p->flags |= 1;
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 bx = *(s32*)((u8*)p + 0xd0);
        arr[0] = bx + (0xE0 << 7);
        arr[1] = bx + (0xB0 << 8);
        arr[2] = bx + (0xF0 << 8);
      }
      p->work[3]++;
      p->coord.x = arr[(u8)(p->work[3] % 3)];
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->work[3] = 3;
      p->mode[2]++;
      break;
    }
    case 7: {
      s32* t0;
      s32* dp;
      register s32 zx4 asm("r4");
      s32 d0;
      s32 d1;
      s32 d2;
      s32 i;
      s32 x;
      t0 = (s32*)((u8*)p + 0xd0);
      {
        s32 t = (pZero2->s).coord.x + -0x7000;
        zx4 = *t0;
        d0 = zx4 - t;
        dp = t0;
        if (d0 <= 0) {
          d0 = t - zx4;
        }
      }
      arr[0] = d0;
      {
        s32 t = (pZero2->s).coord.x + -0xB000;
        d1 = zx4 - t;
        if (d1 <= 0) {
          d1 = t - zx4;
        }
      }
      arr[1] = d1;
      {
        s32 t = (pZero2->s).coord.x + -0xF000;
        d2 = zx4 - t;
        if (d2 <= 0) {
          d2 = t - zx4;
        }
      }
      arr[2] = d2;
      if (d0 > d1) {
        if (d0 > d2) {
          goto pick0;
        }
        i = 2;
        if (d1 > d2) {
          i = 1;
          goto have;
        }
      } else {
        i = 2;
        if (d1 > d2) {
          i = 1;
        }
      }
      if (i == 0) {
      pick0:
        x = *dp + (0xE0 << 7);
      } else {
      have:
        if (i == 1) {
          x = *dp + (0xB0 << 8);
        } else {
          x = *dp + (0xF0 << 8);
        }
      }
      p->unk_coord.x = x;
      p->coord.x = *(volatile s32*)&p->unk_coord.x;
      p->work[2] = 0x1E;
      createHellbatElectricBeam((struct Entity*)p, &p->coord, 0, 0);
      SetDDP(&p->body, (const struct Collision*)0x83631A8);
      p->mode[2]++;
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 9: {
      c.x = p->coord.x;
      c.y = p->coord.y + (0xB8 << 6);
      FUN_080a1538((struct Entity*)p, &c, 0);
      PlaySound(0x89);
      {
        u32 w = p->work[3];
        if (w != 0) {
          w--;
          p->work[3] = w;
          if ((w << 24) != 0) {
            p->mode[2]++;
            break;
          }
        }
      }
      p->mode[2] = 0x14;
      break;
    }
    case 10:
      SetDDP(&p->body, sCollisions);
      p->work[2] = 0x18;
      p->mode[2]++;
      FALLTHROUGH;
    case 11: {
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 bx = *(s32*)((u8*)p + 0xd0);
        arr[0] = bx + (0xE0 << 7);
        arr[1] = bx + (0xB0 << 8);
        arr[2] = bx + (0xF0 << 8);
      }
      p->coord.x = arr[(u8)(p->work[2] % 3)];
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2] = 7;
      break;
    }
    case 20:
      p->flags |= 1;
      p->work[2] = 0x14;
      p->mode[2]++;
      FALLTHROUGH;
    case 21:
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 22: {
      u32 z;
      p->flags |= 1;
      z = 0;
      SetMotion((struct Entity*)p, MOTION(0xA8, 0x01));
      SetDDP(&p->body, sCollisions);
      p->unk_coord.x = p->coord.x;
      p->unk_coord.y = p->coord.y + (0x80 << 6);
      p->work[2] = z;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 23: {
      u32 w;
      {
        s32 d = p->unk_coord.y;
        s32 cy = p->coord.y;
        d -= cy;
        p->coord.y = cy + ((d << 5) >> 8);
      }
      UpdateEntityAnim((struct Entity*)p);
      w = p->work[2];
      asm("" : "+r"(w));
      if (w & 1) {
        p->coord.x = p->unk_coord.x + ((w >> 2) << 8);
      } else {
        p->coord.x = p->unk_coord.x - (((u8)w >> 2) << 8);
      }
      {
        u32 t = p->work[2];
        if (t <= 0x1D) {
          t++;
          p->work[2] = t;
          if ((u8)t <= 0x1D) {
            break;
          }
        }
      }
      p->flags &= 0xFE;
      p->work[2] = 8;
      p->mode[2]++;
      break;
    }
    case 8:
    case 24: {
      u32 w = p->work[2];
      if (w != 0) {
        w--;
        p->work[2] = w;
        if ((w << 24) != 0) {
          break;
        }
      }
      p->mode[2]++;
      break;
    }
    case 25: {
      register u32 z asm("r2");
      {
        u8* c4d = (u8*)p + 0x4d;
        z = 0;
        *c4d = z;
      }
      {
        register u8* oa asm("r3");
        s32 ov;
        s32 m21;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        m21 = -0x21;
        m21 &= ov;
        *oa = m21;
      }
      p->flags &= 0xDF;
      {
        u32 five = 5;
        p->mode[1] = five;
        p->mode[2] = five;
      }
      p->mode[3] = z;
      break;
    }
  }
}

INCASM("asm/boss/hellbat_b.inc");

extern const u16 u16_ARRAY_080feedc[6];

u16 FUN_0804cccc(void* _, u32 a, bool32 rankAS) {
  s32 i;
  if (rankAS == 1) {
    for (i = 0; i < (s32)ARRAY_COUNT(u16_ARRAY_080feedc); i++) {
      if (u16_ARRAY_080feedc[i] == a) {
        return u16_ARRAY_080feedc[(i + 1) % 6];
      }
    }
  } else {
    for (i = 0; i < (s32)ARRAY_COUNT(u16_ARRAY_080feedc) - 1; i++) {
      if (u16_ARRAY_080feedc[i] == a) {
        return u16_ARRAY_080feedc[(i + 1) % 5];
      }
    }
  }
}

// プレイヤー�ヘル�ット� 80px 以上離れ��る�ら TRUE を返�
bool32 isHellbatFarAway(struct Boss* p) {
  s32 zx = (pZero2->s).coord.x;
  s32 hellbat_x = p->coord.x;
  if ((zx - hellbat_x) > 0) {
    if ((zx - hellbat_x) < PIXEL(80)) {
      return FALSE;
    }
    return TRUE;
  } else {
    if ((hellbat_x - zx) >= PIXEL(80)) {
      return TRUE;
    }
    return FALSE;
  }
}

void hellbat_0804cd5c(struct Boss* p) {
  // const motion_t m = (p->motionID << 8) | p->motion.id;
  if (((p->motionID << 8) | p->motion.id) == MOTION(DM168_HELLBAT, 14)) {
    if (IsSpriteAnimEnd(p)) {
      if ((p->flags & X_FLIP) == 0) {
        p->spr.xflip = TRUE;
        p->spr.oam.xflip = TRUE;
        p->flags |= X_FLIP;
      } else {
        p->spr.xflip = FALSE;
        p->spr.oam.xflip = FALSE;
        p->flags &= ~X_FLIP;
      }
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 0));
    }
  } else if ((pZero2->s).coord.x > p->coord.x) {
    if (!(p->flags & X_FLIP)) {
      SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 14));
    }
  } else if (p->flags & X_FLIP) {
    SetSpriteAnimation(p, MOTION(DM168_HELLBAT, 14));
  }
}

// 0x08362f50
static const struct Collision sCollisions[29] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [5] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
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
      remaining : 6,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 5,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(33), PIXEL(27), PIXEL(18)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [10] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 2,
      range : {PIXEL(0), -PIXEL(22), PIXEL(31), PIXEL(39)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(54), PIXEL(13), PIXEL(25)},
    },
    [12] = {
      kind : DRP2,
      faction : FACTION_ENEMY,
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
      remaining : 7,
      layer : 0x00000001,
      range : {PIXEL(28), -PIXEL(46), PIXEL(23), PIXEL(42)},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 6,
      layer : 0x00000001,
      range : {PIXEL(28), -PIXEL(46), PIXEL(23), PIXEL(42)},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 5,
      layer : 0x00000001,
      range : {-PIXEL(20), -PIXEL(46), PIXEL(18), PIXEL(42)},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 4,
      layer : 0x00000001,
      range : {-PIXEL(20), -PIXEL(46), PIXEL(18), PIXEL(42)},
    },
    [17] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(3), -0x3D00, 0x1B00, 0x2600},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(3), -0x3D00, 0x1B00, 0x2600},
    },
    [19] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 1,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 0,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [24] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [26] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x06,
      remaining : 1,
      range : {PIXEL(0), -0x1600, 0x1F00, 0x2700},
    },
    [28] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 6,
      remaining : 0,
      range : {PIXEL(0), -0x3600, 0x0D00, 0x1900},
    },
};

// 0x08363208
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(32)};

// 0x08363210
static const Coords32 sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(32)},
    {PIXEL(0), -PIXEL(32)},
};
