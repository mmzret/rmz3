#include "boss.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "sound.h"

static const BossFunc sUpdates1[12];
static const BossFunc sUpdates2[12];

static void Blazin_Init(struct Boss* p);
static void Blazin_Update(struct Boss* p);
static void Blazin_Die(struct Boss* p);

// clang-format off
const BossRoutine gBlazinRoutine = {
    [ENTITY_INIT] =      Blazin_Init,
    [ENTITY_UPDATE] =    Blazin_Update,
    [ENTITY_DIE] =       Blazin_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

struct Boss* CreateBlazin(struct Coord* c, u8 n) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_BOSS_ROUTINE(p, BOSS_BLAZIN);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).coord = *c;
    (p->s).work[0] = n;
  }
  return p;
}

NAKED static void Blazin_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r4, #0\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r4, [r0]\n\
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
	ldr r1, _0803E9A4 @ =0x08361C68\n\
	adds r0, r5, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	ldr r1, _0803E9A8 @ =FUN_0803ff28\n\
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
	adds r0, r5, #0\n\
	adds r0, #0xc0\n\
	str r4, [r0]\n\
	subs r0, #9\n\
	strb r4, [r0]\n\
	adds r0, #0x11\n\
	movs r7, #0\n\
	strh r4, [r0]\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0803E9AC @ =0xFFFFC000\n\
	adds r1, r1, r0\n\
	ldr r0, [r5, #0x54]\n\
	bl FUN_08009f6c\n\
	str r0, [r5, #0x58]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb8\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r1]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_0800a134\n\
	adds r6, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r6, #0\n\
	bl FUN_0800a22c\n\
	adds r4, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r6, #0\n\
	bl FUN_0800a31c\n\
	subs r4, r4, r0\n\
	asrs r6, r4, #2\n\
	adds r1, r5, #0\n\
	adds r1, #0xd4\n\
	asrs r4, r4, #3\n\
	adds r0, r0, r4\n\
	str r0, [r1]\n\
	adds r2, r5, #0\n\
	adds r2, #0xd8\n\
	adds r1, r0, r6\n\
	str r1, [r2]\n\
	adds r3, r5, #0\n\
	adds r3, #0xdc\n\
	lsls r1, r6, #1\n\
	adds r2, r0, r1\n\
	str r2, [r3]\n\
	adds r2, r5, #0\n\
	adds r2, #0xe0\n\
	adds r1, r1, r6\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	adds r0, r5, #0\n\
	adds r0, #0xca\n\
	strb r7, [r0]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0803E9B4\n\
	ldr r1, _0803E9B0 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r7, [r5, #0xd]\n\
	b _0803E9CA\n\
	.align 2, 0\n\
_0803E9A4: .4byte 0x08361C68\n\
_0803E9A8: .4byte FUN_0803ff28\n\
_0803E9AC: .4byte 0xFFFFC000\n\
_0803E9B0: .4byte gBossFnTable\n\
_0803E9B4:\n\
	ldr r1, _0803E9EC @ =gBossFnTable\n\
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
_0803E9CA:\n\
	strb r7, [r5, #0xe]\n\
	strb r7, [r5, #0xf]\n\
	movs r1, #0\n\
	strb r1, [r5, #0x11]\n\
	adds r0, r5, #0\n\
	adds r0, #0xd0\n\
	strb r1, [r0]\n\
	subs r0, #0xc\n\
	str r1, [r0]\n\
	adds r0, #8\n\
	str r1, [r0]\n\
	adds r0, r5, #0\n\
	bl Blazin_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803E9EC: .4byte gBossFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool8 nop_0803ee2c(struct Boss* _);
bool8 FUN_0803ee8c(struct Boss* _);
bool8 FUN_0803ef64(struct Boss* _);
bool8 true_0803efc4(struct Boss* _);
bool8 nop_0803f280(struct Boss* _);
bool8 FUN_0803f3fc(struct Boss* _);
bool8 nop_0803f538(struct Boss* _);
bool8 nop_0803f710(struct Boss* _);
bool8 FUN_0803f9a8(struct Boss* _);
bool8 FUN_0803f9c0(struct Boss* _);
bool8 FUN_0803fc70(struct Boss* _);
bool8 FUN_0803fd58(struct Boss* _);

// clang-format off
static const BossFunc sUpdates1[12] = {
    (BossFunc)nop_0803ee2c,
    (BossFunc)FUN_0803ee8c,
    (BossFunc)FUN_0803ef64,
    (BossFunc)true_0803efc4,
    (BossFunc)nop_0803f280,
    (BossFunc)FUN_0803f3fc,
    (BossFunc)nop_0803f538,
    (BossFunc)nop_0803f710,
    (BossFunc)FUN_0803f9a8,
    (BossFunc)FUN_0803f9c0,
    (BossFunc)FUN_0803fc70,
    (BossFunc)FUN_0803fd58,
};
// clang-format on

void blazinMode0(struct Boss* p);
void blazinMode1(struct Boss* p);
void blazinMode2(struct Boss* p);
void blazinNeutral(struct Boss* p);
void blazinMode4(struct Boss* p);
void blazinMode5(struct Boss* p);
void blazinMode6(struct Boss* p);
void blazinMode7(struct Boss* p);
void blazinMode8(struct Boss* p);
void blazinEX(struct Boss* p);
void blazinMode10(struct Boss* p);
void blazinKnockBackDamage(struct Boss* p);

// clang-format off
static const BossFunc sUpdates2[12] = {
    blazinMode0,
    blazinMode1,
    blazinMode2,
    blazinNeutral,
    blazinMode4,
    blazinMode5,
    blazinMode6,
    blazinMode7,
    blazinMode8,
    blazinEX,
    blazinMode10,
    blazinKnockBackDamage,
};
// clang-format on

NAKED static void Blazin_Update(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r4, #0\n\
	adds r5, #0x8c\n\
	ldr r0, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EA10\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bne _0803EA5A\n\
_0803EA10:\n\
	ldr r0, _0803EA48 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EA5A\n\
	ldr r1, _0803EA4C @ =gBossFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0x75\n\
	bl PlaySound\n\
	ldr r1, [r5]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0803EA50\n\
	movs r0, #1\n\
	strb r0, [r4, #0xf]\n\
	b _0803EA52\n\
	.align 2, 0\n\
_0803EA48: .4byte gStageRun\n\
_0803EA4C: .4byte gBossFnTable\n\
_0803EA50:\n\
	strb r1, [r4, #0xf]\n\
_0803EA52:\n\
	adds r0, r4, #0\n\
	bl Blazin_Die\n\
	b _0803EAA2\n\
_0803EA5A:\n\
	adds r1, r4, #0\n\
	adds r1, #0xc4\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0803EA7C\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0803EA7C\n\
	movs r0, #0\n\
	str r0, [r1]\n\
	adds r0, r4, #0\n\
	bl FUN_0803ffc0\n\
	adds r1, r4, #0\n\
	adds r1, #0xc8\n\
	movs r0, #0x15\n\
	strh r0, [r1]\n\
_0803EA7C:\n\
	ldr r1, _0803EAA8 @ =sUpdates1\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl blazin_0803fed8\n\
	ldr r1, _0803EAAC @ =sUpdates2\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
_0803EAA2:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803EAA8: .4byte sUpdates1\n\
_0803EAAC: .4byte sUpdates2\n\
 .syntax divided\n");
}

// --------------------------------------------

static void blazinDeath0(struct Boss* p);
static void blazinDeath1(struct Boss* p);

static void Blazin_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      blazinDeath0,
      blazinDeath1,
  };
  (sDeads[(p->s).mode[1]])(p);
}

static void blazinDeath0(struct Boss* p) {
  struct Coord* velocity;
  switch ((p->s).mode[2]) {
    case 0: {
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & 1)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      if (isSoundPlaying(SE_COPYX_FIRESHOT)) {
        stopSound(SE_COPYX_FIRESHOT);
      }
      if (isSoundPlaying(SE_BLAZIN_EX)) {
        stopSound(SE_BLAZIN_EX);
      }
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      velocity = &(p->s).d;
      velocity->x = velocity->y = 0;
      (p->s).work[2] = 1;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->s).work[2] != 0) {
        (p->s).work[2]--;
        if ((p->s).work[2] == 0) {
          (p->s).mode[2]++;
        }
      }
      break;
    }

    case 2: {
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 0;
      break;
    }
  }
}

NAKED static void blazinDeath1(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0x19\n\
	bls _0803EB8E\n\
	b _0803EE20\n\
_0803EB8E:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0803EB98 @ =_0803EB9C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0803EB98: .4byte _0803EB9C\n\
_0803EB9C: @ jump table\n\
	.4byte _0803EC04 @ case 0\n\
	.4byte _0803EC6C @ case 1\n\
	.4byte _0803EC7C @ case 2\n\
	.4byte _0803ECEE @ case 3\n\
	.4byte _0803ED54 @ case 4\n\
	.4byte _0803EE20 @ case 5\n\
	.4byte _0803EE20 @ case 6\n\
	.4byte _0803EE20 @ case 7\n\
	.4byte _0803EE20 @ case 8\n\
	.4byte _0803EE20 @ case 9\n\
	.4byte _0803EC6C @ case 10\n\
	.4byte _0803ED6A @ case 11\n\
	.4byte _0803EE20 @ case 12\n\
	.4byte _0803EE20 @ case 13\n\
	.4byte _0803EE20 @ case 14\n\
	.4byte _0803EE20 @ case 15\n\
	.4byte _0803EE20 @ case 16\n\
	.4byte _0803EE20 @ case 17\n\
	.4byte _0803EE20 @ case 18\n\
	.4byte _0803EE20 @ case 19\n\
	.4byte _0803ED7C @ case 20\n\
	.4byte _0803ED86 @ case 21\n\
	.4byte _0803ED94 @ case 22\n\
	.4byte _0803EDDC @ case 23\n\
	.4byte _0803EDF4 @ case 24\n\
	.4byte _0803EE08 @ case 25\n\
_0803EC04:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc8\n\
	ldrh r1, [r0]\n\
	adds r1, #3\n\
	ldr r2, _0803EC74 @ =0xFFFFA200\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r2, r4, #0\n\
	adds r2, #0x8c\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EC38\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bne _0803EC4A\n\
_0803EC38:\n\
	ldr r0, _0803EC78 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EC4A\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #1\n\
	beq _0803EC4C\n\
_0803EC4A:\n\
	movs r0, #0xa\n\
_0803EC4C:\n\
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
_0803EC6C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0803EDE8\n\
	.align 2, 0\n\
_0803EC74: .4byte 0xFFFFA200\n\
_0803EC78: .4byte gStageRun\n\
_0803EC7C:\n\
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
	beq _0803EC94\n\
	str r2, [sp]\n\
_0803EC94:\n\
	ldr r1, _0803ECB4 @ =0xFFFFE000\n\
	adds r0, r3, r1\n\
	str r0, [sp, #4]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0xff\n\
	beq _0803ECC2\n\
	cmp r0, #0xfe\n\
	bne _0803ECB8\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
	b _0803ECE6\n\
	.align 2, 0\n\
_0803ECB4: .4byte 0xFFFFE000\n\
_0803ECB8:\n\
	ldr r0, _0803ECD4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r0, r2\n\
	ble _0803ECD8\n\
_0803ECC2:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #1\n\
	bl FUN_080b2b40\n\
	b _0803ECE6\n\
	.align 2, 0\n\
_0803ECD4: .4byte pZero2\n\
_0803ECD8:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	movs r0, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl FUN_080b2b40\n\
_0803ECE6:\n\
	movs r0, #0x2f\n\
	bl PlaySound\n\
	b _0803EDE8\n\
_0803ECEE:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc4\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _0803ED14\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	ldr r2, _0803ED10 @ =0x0000A205\n\
	ldrb r3, [r4, #0xa]\n\
	lsrs r3, r3, #4\n\
	movs r0, #1\n\
	ands r3, r0\n\
	adds r0, r4, #0\n\
	bl FUN_0809c3b4\n\
	b _0803ED28\n\
	.align 2, 0\n\
_0803ED10: .4byte 0x0000A205\n\
_0803ED14:\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	ldr r2, _0803ED4C @ =0x0000A21A\n\
	ldrb r3, [r4, #0xa]\n\
	lsrs r3, r3, #4\n\
	movs r0, #1\n\
	ands r3, r0\n\
	adds r0, r4, #0\n\
	bl FUN_0809c3b4\n\
_0803ED28:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc8\n\
	ldrh r1, [r0]\n\
	adds r1, #4\n\
	ldr r2, _0803ED50 @ =0xFFFFA200\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	movs r0, #0x44\n\
	strb r0, [r4, #0x12]\n\
	b _0803EDE8\n\
	.align 2, 0\n\
_0803ED4C: .4byte 0x0000A21A\n\
_0803ED50: .4byte 0xFFFFA200\n\
_0803ED54:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803ED6A\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803EE20\n\
_0803ED6A:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803EE20\n\
	movs r0, #0x14\n\
	strb r0, [r4, #0xe]\n\
	b _0803EE20\n\
_0803ED7C:\n\
	movs r0, #0x50\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803ED86:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803EE20\n\
	b _0803EDE8\n\
_0803ED94:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #1\n\
	bne _0803EDB4\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EDAC\n\
	ldr r1, _0803EDA8 @ =0x08361DE8\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDA8: .4byte 0x08361DE8\n\
_0803EDAC:\n\
	ldr r1, _0803EDB0 @ =0x08361DF0\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDB0: .4byte 0x08361DF0\n\
_0803EDB4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EDC8\n\
	ldr r1, _0803EDC4 @ =0x08361DD8\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDC4: .4byte 0x08361DD8\n\
_0803EDC8:\n\
	ldr r1, _0803EDF0 @ =0x08361DE0\n\
_0803EDCA:\n\
	adds r0, r4, #0\n\
	bl CreateBossExplosion\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	str r0, [r1]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803EDDC:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc0\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0803EE20\n\
_0803EDE8:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0803EE20\n\
	.align 2, 0\n\
_0803EDF0: .4byte 0x08361DE0\n\
_0803EDF4:\n\
	movs r0, #0x30\n\
	strb r0, [r4, #0x12]\n\
	ldr r2, _0803EE28 @ =gStageRun\n\
	ldrb r1, [r2, #0x12]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0803EE08:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _0803EE18\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803EE20\n\
_0803EE18:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_0803EE20:\n\
	add sp, #8\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803EE28: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool8 nop_0803ee2c(struct Boss* _) { return TRUE; }

INCASM("asm/boss/blazin.inc");

const struct Collision gBlazinCollisions[15] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, -0x1200, 0x2400, 0x2600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1100, 0x2200, 0x2400},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {0x0000, -0x1200, 0x2400, 0x2600},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1700, 0x1A00, 0x2A00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {0x0000, -0x1800, 0x1C00, 0x2D00},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x800, -0xD00, 0x2F00, 0x1900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {-0x900, -0xE00, 0x3100, 0x1B00},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1500, 0x2200, 0x2D00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {0x0000, -0x1600, 0x2400, 0x2F00},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x300, -0xE00, 0x2500, 0x1C00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {-0x400, -0xF00, 0x2700, 0x1E00},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0100, -0x1500, 0x1E00, 0x2E00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 2,
      range : {0x0200, -0x1600, 0x2000, 0x3000},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1B00, -0x1B00, 0x1A00, 0x0D00},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x07,
      remaining : 0,
      range : {-0x1C00, -0x1C00, 0x1C00, 0x0F00},
    },
};

const struct Coord gBlazinCoords[5] = {
    {0x0000, -0x2000}, {0x0C00, -0x2000}, {0x0C00, -0x2000}, {0x1200, -0x2000}, {0x1200, -0x2000},
};
