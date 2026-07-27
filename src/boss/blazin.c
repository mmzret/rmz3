#include "boss.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "sound.h"
#include "zero.h"
//
#include "projectile/blazin.h"
#include "projectile/blazin_tail.h"
#include "element.h"

const Coords32 gBlazinCoords[5];

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[16];         // 0xB4
  BlazinTail* tail;      // 0xC4
  u16 anim_c8;           // 0xC8
  u8 unk_ca[26];         // 0xC8
} Blazin;
static_assert(sizeof(Blazin) == sizeof(Boss));

static void Blazin_Init(Blazin* p);
static void Blazin_Update(Blazin* p);
static void Blazin_Die(Blazin* p);

// clang-format off
const BossRoutine gBlazinRoutine = {
    [ENTITY_INIT] =      (void*)Blazin_Init,
    [ENTITY_UPDATE] =    (void*)Blazin_Update,
    [ENTITY_DIE] =       (void*)Blazin_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Blazin* Unused_CreateBlazin(Coords32* c, u8 n) {
  Blazin* p = (Blazin*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_BLAZIN);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

NAKED static void Blazin_Init(Blazin* p) {
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
	ldr r1, _0803E9A4 @ =gBlazinCollisions\n\
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
_0803E9A4: .4byte gBlazinCollisions\n\
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

static bool8 nop_0803ee2c(Blazin* _);
static bool8 FUN_0803ee8c(Blazin* _);
static bool8 FUN_0803ef64(Blazin* _);
bool8 true_0803efc4(Blazin* _);
bool8 nop_0803f280(Blazin* _);
bool8 FUN_0803f3fc(Blazin* _);
bool8 nop_0803f538(Blazin* _);
bool8 nop_0803f710(Blazin* _);
bool8 FUN_0803f9a8(Blazin* _);
bool8 FUN_0803f9c0(Blazin* _);
bool8 FUN_0803fc70(Blazin* _);
bool8 FUN_0803fd58(Blazin* _);

static void blazinMode0(Blazin* p);
static void blazinMode1(Blazin* p);
void blazinMode2(Blazin* p);
void blazinNeutral(Blazin* p);
void blazinMode4(Blazin* p);
void blazinMode5(Blazin* p);
void blazinMode6(Blazin* p);
void blazinMode7(Blazin* p);
void blazinMode8(Blazin* p);
void blazinEX(Blazin* p);
void blazinMode10(Blazin* p);
void blazinKnockBackDamage(Blazin* p);

u32 blazin_0803fed8(struct Boss* p);
static bool8 FUN_0803ffc0(Blazin* p);

static void Blazin_Update(Blazin* p) {
  // clang-format off
  static bool8 (*const sUpdates1[12])(Blazin*) = {
      nop_0803ee2c,
      FUN_0803ee8c,
      FUN_0803ef64,
      true_0803efc4,
      nop_0803f280,
      FUN_0803f3fc,
      nop_0803f538,
      nop_0803f710,
      FUN_0803f9a8,
      FUN_0803f9c0,
      FUN_0803fc70,
      FUN_0803fd58,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[12])(Blazin*) = {
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

  if (((p->body).status & BODY_STATUS_DEAD || (p->body).hp == 0) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_BLAZIN_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[3] = 1;
    } else {
      p->mode[3] = 0;
    }
    Blazin_Die((Blazin*)p);
  } else {
    BlazinTail* tail = p->tail;
    if (tail != NULL && tail->mode[0] > ENTITY_UPDATE) {
      p->tail = NULL;
      FUN_0803ffc0((Blazin*)p);
      p->anim_c8 = 21;
    }
    sUpdates1[p->mode[1]](p);
    blazin_0803fed8((void*)p);
    sUpdates2[p->mode[1]](p);
  }
}

static void blazinDeath0(Blazin* p);
static void blazinDeath1(Blazin* p);

static void Blazin_Die(Blazin* p) {
  static void (*const sDeads[2])(Blazin*) = {
      blazinDeath0,
      blazinDeath1,
  };
  (sDeads[p->mode[1]])((void*)p);
}

static void blazinDeath0(Blazin* p) {
  switch (p->mode[2]) {
    case 0: {
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & VM_ACTIVE)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      if (isSoundPlaying(SE_COPYX_FIRESHOT)) StopSound(SE_COPYX_FIRESHOT);
      if (isSoundPlaying(SE_BLAZIN_EX)) StopSound(SE_BLAZIN_EX);
      EXIT_BODY(p);
      (&p->d)->x = (&p->d)->y = 0;
      p->work[2] = 1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (p->work[2] != 0) {
        p->work[2]--;
        if (p->work[2] == 0) p->mode[2]++;
      }
      break;
    }

    case 2: {
      p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

NAKED static void blazinDeath1(Blazin* p) {
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
	bl UpdateEntityAnim\n\
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
	bl UpdateEntityAnim\n\
	movs r0, #0x44\n\
	strb r0, [r4, #0x12]\n\
	b _0803EDE8\n\
	.align 2, 0\n\
_0803ED4C: .4byte 0x0000A21A\n\
_0803ED50: .4byte 0xFFFFA200\n\
_0803ED54:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
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
	ldr r1, _0803EDA8 @ =gBlazinCoords+(8*3)\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDA8: .4byte gBlazinCoords+(3*8)\n\
_0803EDAC:\n\
	ldr r1, _0803EDB0 @ =gBlazinCoords+(4*8)\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDB0: .4byte gBlazinCoords+(4*8)\n\
_0803EDB4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803EDC8\n\
	ldr r1, _0803EDC4 @ =gBlazinCoords+(1*8)\n\
	b _0803EDCA\n\
	.align 2, 0\n\
_0803EDC4: .4byte gBlazinCoords+(1*8)\n\
_0803EDC8:\n\
	ldr r1, _0803EDF0 @ =gBlazinCoords+(2*8)\n\
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
_0803EDF0: .4byte gBlazinCoords+(2*8)\n\
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

static bool8 nop_0803ee2c(Blazin* _) { return TRUE; }

static void blazinMode0(Blazin* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags |= DISPLAY;
      SetSpriteAnimation(p, MOTION(DM162_BLAZIN, p->anim_c8 + 21));
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

static bool8 FUN_0803ee8c(Blazin* _) { return TRUE; }

static void blazinMode1(Blazin* p) {
  switch (p->mode[2]) {
    case 0: {
      p->work[2] = 26;
      SetSpriteAnimation(p, MOTION(DM162_BLAZIN, p->anim_c8 + 39));
      PlaySound(SE_BLAZIN_PREBATTLE);
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
      p->work[2] = 30;
      SetSpriteAnimation(p, MOTION(DM162_BLAZIN, p->anim_c8 + 40));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 4: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        if ((p->work[2] == 0) || (--p->work[2]) == 0) {
          p->mode[2]++;
        }
      }
      break;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      p->mode[1] = 2, p->mode[2] = 0;
      break;
    }
    default: {
      break;
    }
  }
}

static bool8 FUN_0803ef64(Blazin* _) { return TRUE; }

void blazinMode2(Blazin* p) {
  switch (p->mode[2]) {
    case 0: {
      p->tail = NULL;
      p->tail = createBlazinTail((void*)p, 2);
      SetSpriteAnimation(p, MOTION(DM162_BLAZIN, p->anim_c8));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) p->mode[1] = 3, p->mode[2] = 0;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 true_0803efc4(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_b.inc");

bool8 nop_0803f280(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_c.inc");

bool8 FUN_0803f3fc(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_d.inc");

bool8 nop_0803f538(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_e.inc");

bool8 nop_0803f710(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_f.inc");

bool8 FUN_0803f9a8(Blazin* _) { return TRUE; }

void blazinMode8(Blazin* p) {
  if (p->mode[2] == 0) p->mode[2] = 1;
}

bool8 FUN_0803f9c0(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_g.inc");

bool8 FUN_0803fc70(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_h.inc");

bool8 FUN_0803fd58(Blazin* _) { return TRUE; }

INCASM("asm/boss/blazin_i_a.inc");

u32 blazin_0803fed8(struct Boss* p) {
  struct Entity** slot = (struct Entity**)&p->buffer[12];

  if (*slot == NULL && ((p->body).status & 1)) {
    *slot = ApplyElementEffect(9, (Object*)p, gBlazinCoords);
    if (*slot != NULL) {
      if ((*(u8*)((u8*)p + 0x97) & 0xf0) == 0x10) {
        p->mode[1] = 10;
        p->mode[2] = 0;
      } else {
        *slot = NULL;
      }
    }
  }
  return TRUE;
}

INCASM("asm/boss/blazin_i_b.inc");

struct Enemy* FUN_0809c430(struct Entity* e, Coords32* c);

static bool8 FUN_0803ffc0(Blazin* p) {
  Coords32 c;
  c.x = (p->coord).x;
  c.y = (p->coord).y;
  FUN_0809c430((void*)p, &c);
  return TRUE;
}

INCASM("asm/boss/blazin_j.inc");

s32 howFarBlazin(Blazin* p) {
  s32 zx = ((pZero2->s).coord).x;
  s32 sx = (p->coord).x;
  s32 d = zx - sx;
  if (d <= 0) d = sx - zx;
  if (d < PIXEL(79)) return 0;
  if (d < PIXEL(143)) return 1;
  return 2;
}

INCASM("asm/boss/blazin_k.inc");

// 0x080403c4
static void setBlazinDirection(struct Entity* p) {
  struct Entity* z = (struct Entity*)pZero2;
  if ((z->coord).x > (p->coord).x) {
    if (!(p->flags & X_FLIP)) {
      (p->spr).xflip = TRUE, (p->spr).oam.xflip = TRUE;
      p->flags |= X_FLIP;
    }
  } else {
    if (p->flags & X_FLIP) {
      (p->spr).xflip = FALSE, (p->spr).oam.xflip = FALSE;
      p->flags &= ~X_FLIP;
    }
  }
}

// --------------------------------------------

// 0x08361c68
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

// 0x08361dd0
const Coords32 gBlazinCoords[5] = {
    {PIXEL(0), -PIXEL(32)}, {PIXEL(12), -PIXEL(32)}, {PIXEL(12), -PIXEL(32)}, {PIXEL(18), -PIXEL(32)}, {PIXEL(18), -PIXEL(32)},
};
