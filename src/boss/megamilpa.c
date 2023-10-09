#include "boss.h"
#include "collision.h"
#include "global.h"
#include "stagerun.h"

static const s32 s32_ARRAY_08361abc[2];
static const u8 u8_ARRAY_08361ac4[2];

static void Megamilpa_Init(struct Boss* p);
static void Megamilpa_Update(struct Boss* p);
static void Megamilpa_Die(struct Boss* p);

// clang-format off
const BossRoutine gMegamilpaRoutine = {
    [ENTITY_INIT] =      Megamilpa_Init,
    [ENTITY_UPDATE] =    Megamilpa_Update,
    [ENTITY_DIE] =       Megamilpa_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

NAKED static void Megamilpa_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _0803D254 @ =gBossFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldr r1, _0803D258 @ =u8_ARRAY_08361ab8\n\
	ldrb r0, [r6, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	movs r5, #0\n\
	strb r0, [r6, #0xd]\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	adds r4, r6, #0\n\
	adds r4, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	asrs r0, r0, #8\n\
	str r0, [r4]\n\
	movs r1, #0xf0\n\
	bl __divsi3\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0xc\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #7\n\
	adds r1, r1, r0\n\
	str r1, [r4]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r6, #0\n\
	adds r1, #0xb8\n\
	ldr r2, _0803D25C @ =0xFFFFFC00\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	ldr r0, [r4]\n\
	str r0, [r6, #0x54]\n\
	ldr r0, [r1]\n\
	str r0, [r6, #0x58]\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	str r5, [r0]\n\
	adds r1, #5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r5, [r0]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _0803D2A0\n\
	movs r4, #0\n\
_0803D224:\n\
	cmp r4, #5\n\
	beq _0803D234\n\
	lsls r0, r4, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl CreateMegamilpaNode\n\
	adds r0, #0xb4\n\
	str r6, [r0]\n\
_0803D234:\n\
	adds r4, #1\n\
	cmp r4, #0xa\n\
	ble _0803D224\n\
	ldr r0, _0803D260 @ =gSystemSavedataManager\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803D268\n\
	ldr r1, _0803D264 @ =gMegamilpaCoreHitbox\n\
	adds r0, r6, #0\n\
	movs r2, #0x50\n\
	bl ResetBossBody\n\
	b _0803D272\n\
	.align 2, 0\n\
_0803D254: .4byte gBossFnTable\n\
_0803D258: .4byte u8_ARRAY_08361ab8\n\
_0803D25C: .4byte 0xFFFFFC00\n\
_0803D260: .4byte gSystemSavedataManager\n\
_0803D264: .4byte gMegamilpaCoreHitbox\n\
_0803D268:\n\
	ldr r1, _0803D2AC @ =gMegamilpaCoreHitbox\n\
	adds r0, r6, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
_0803D272:\n\
	ldr r0, _0803D2B0 @ =0x085D795C\n\
	ldr r1, _0803D2B4 @ =wStaticGraphicTilenums\n\
	ldrh r1, [r1, #0xa]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _0803D2B8 @ =0x085D7968\n\
	ldr r1, _0803D2BC @ =wStaticMotionPalIDs\n\
	ldrh r1, [r1, #0xa]\n\
	ldrb r2, [r0, #7]\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	bl LoadPalette\n\
_0803D2A0:\n\
	adds r0, r6, #0\n\
	bl Megamilpa_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D2AC: .4byte gMegamilpaCoreHitbox\n\
_0803D2B0: .4byte 0x085D795C\n\
_0803D2B4: .4byte wStaticGraphicTilenums\n\
_0803D2B8: .4byte 0x085D7968\n\
_0803D2BC: .4byte wStaticMotionPalIDs\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_0803d6a0(struct Boss* p);

void FUN_0803d6a4(struct Boss* p);
void FUN_0803d6fc(struct Boss* p);
void FUN_0803d7a0(struct Boss* p);
void FUN_0803d844(struct Boss* p);
void FUN_0803dba0(struct Boss* p);
void FUN_0803dc34(struct Boss* p);

static void Megamilpa_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[6] = {
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0,
  };
  static const BossFunc sUpdates2[6] = {
      FUN_0803d6a4, 
      FUN_0803d6fc, 
      FUN_0803d7a0, 
      FUN_0803d844, 
      FUN_0803dba0, 
      FUN_0803dc34,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_FAIL)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    Megamilpa_Die(p);
    return;
  }

  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

NAKED static void Megamilpa_Die(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #4\n\
	bls _0803D348\n\
	b _0803D448\n\
_0803D348:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0803D354 @ =_0803D358\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0803D354: .4byte _0803D358\n\
_0803D358: @ jump table\n\
	.4byte _0803D36C @ case 0\n\
	.4byte _0803D3D0 @ case 1\n\
	.4byte _0803D410 @ case 2\n\
	.4byte _0803D422 @ case 3\n\
	.4byte _0803D448 @ case 4\n\
_0803D36C:\n\
	ldr r0, _0803D3BC @ =0x0000010D\n\
	bl stopSound\n\
	ldr r3, _0803D3C0 @ =gStageRun\n\
	ldrh r2, [r3, #8]\n\
	movs r4, #1\n\
	adds r0, r4, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0803D394\n\
	ldrb r1, [r3, #0x12]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803D394\n\
	ldr r0, _0803D3C4 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
_0803D394:\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	movs r2, #0\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0xfb\n\
	ands r1, r0\n\
	strb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803D3C8\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #2\n\
	b _0803D446\n\
	.align 2, 0\n\
_0803D3BC: .4byte 0x0000010D\n\
_0803D3C0: .4byte gStageRun\n\
_0803D3C4: .4byte 0x0000FFFE\n\
_0803D3C8:\n\
	str r2, [r5, #0x60]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_0803D3D0:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, #0x20\n\
	str r1, [r5, #0x60]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	cmp r1, r0\n\
	ble _0803D3E6\n\
	str r0, [r5, #0x60]\n\
_0803D3E6:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _0803D448\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	adds r4, r5, #0\n\
	adds r4, #0x54\n\
	movs r0, #1\n\
	adds r1, r4, #0\n\
	bl CreateSmoke\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl CreateGhost19_2\n\
	b _0803D442\n\
_0803D410:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r0, #0x78\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_0803D422:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803D448\n\
	ldr r2, _0803D450 @ =gStageRun\n\
	ldrb r0, [r2, #0x12]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x12]\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #9\n\
	bl TryDropItem\n\
_0803D442:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
_0803D446:\n\
	strb r0, [r5, #0xd]\n\
_0803D448:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D450: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

NAKED static void FUN_0803d454(struct Boss* p, u8 r1, u8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	adds r7, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	mov sl, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r2, [sp, #0x10]\n\
	cmp r1, #0\n\
	beq _0803D4C4\n\
	ldr r0, _0803D4B0 @ =0xFFFFFD80\n\
	mov sb, r0\n\
	str r0, [sp]\n\
	ldr r4, _0803D4B4 @ =RNG_0202f388\n\
	ldr r0, [r4]\n\
	ldr r1, _0803D4B8 @ =0x000343FD\n\
	mov r8, r1\n\
	mov r2, r8\n\
	muls r2, r0, r2\n\
	adds r0, r2, #0\n\
	ldr r6, _0803D4BC @ =0x00269EC3\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r5, r0, #1\n\
	str r5, [r4]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	bl __umodsi3\n\
	add r0, sb\n\
	str r0, [sp]\n\
	ldr r2, _0803D4C0 @ =0xFFFFFF00\n\
	mov r0, r8\n\
	muls r0, r5, r0\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r4]\n\
	b _0803D4EC\n\
	.align 2, 0\n\
_0803D4B0: .4byte 0xFFFFFD80\n\
_0803D4B4: .4byte RNG_0202f388\n\
_0803D4B8: .4byte 0x000343FD\n\
_0803D4BC: .4byte 0x00269EC3\n\
_0803D4C0: .4byte 0xFFFFFF00\n\
_0803D4C4:\n\
	ldr r5, _0803D518 @ =RNG_0202f388\n\
	ldr r0, [r5]\n\
	ldr r4, _0803D51C @ =0x000343FD\n\
	muls r0, r4, r0\n\
	ldr r3, _0803D520 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsls r0, r0, #5\n\
	lsrs r0, r0, #0x16\n\
	ldr r2, _0803D524 @ =0xFFFFFE00\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r2, _0803D528 @ =0xFFFFFF00\n\
	adds r0, r1, #0\n\
	muls r0, r4, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
_0803D4EC:\n\
	lsls r0, r0, #6\n\
	lsrs r0, r0, #0x17\n\
	subs r2, r2, r0\n\
	str r2, [sp, #4]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldr r2, [r1]\n\
	str r2, [sp, #8]\n\
	adds r0, r7, #0\n\
	adds r0, #0xbe\n\
	mov sb, r1\n\
	mov r8, r0\n\
	ldrb r3, [r0]\n\
	cmp sl, r3\n\
	beq _0803D530\n\
	ldr r0, _0803D52C @ =s32_ARRAY_08361abc\n\
	ldr r3, [sp, #0x10]\n\
	lsls r1, r3, #2\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	subs r0, r2, r0\n\
	b _0803D53C\n\
	.align 2, 0\n\
_0803D518: .4byte RNG_0202f388\n\
_0803D51C: .4byte 0x000343FD\n\
_0803D520: .4byte 0x00269EC3\n\
_0803D524: .4byte 0xFFFFFE00\n\
_0803D528: .4byte 0xFFFFFF00\n\
_0803D52C: .4byte s32_ARRAY_08361abc\n\
_0803D530:\n\
	ldr r0, _0803D58C @ =s32_ARRAY_08361abc\n\
	ldr r3, [sp, #0x10]\n\
	lsls r1, r3, #2\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	adds r0, r0, r2\n\
_0803D53C:\n\
	str r0, [sp, #8]\n\
	adds r6, r1, #0\n\
	ldr r2, [sp, #8]\n\
	ldr r0, _0803D590 @ =0xFFFFF000\n\
	adds r2, r2, r0\n\
	ldr r3, _0803D594 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _0803D598 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803D59C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsls r0, r0, #2\n\
	lsrs r0, r0, #0x13\n\
	adds r0, r0, r2\n\
	str r0, [sp, #8]\n\
	adds r5, r7, #0\n\
	adds r5, #0xb8\n\
	ldr r0, [r5]\n\
	add r4, sp, #8\n\
	str r0, [r4, #4]\n\
	adds r0, r4, #0\n\
	mov r1, sp\n\
	bl CreateGhost19_1\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	str r1, [sp, #8]\n\
	mov r3, r8\n\
	ldrb r3, [r3]\n\
	cmp sl, r3\n\
	beq _0803D5A0\n\
	ldr r0, _0803D58C @ =s32_ARRAY_08361abc\n\
	adds r0, r6, r0\n\
	ldr r0, [r0]\n\
	subs r0, r1, r0\n\
	b _0803D5A8\n\
	.align 2, 0\n\
_0803D58C: .4byte s32_ARRAY_08361abc\n\
_0803D590: .4byte 0xFFFFF000\n\
_0803D594: .4byte RNG_0202f388\n\
_0803D598: .4byte 0x000343FD\n\
_0803D59C: .4byte 0x00269EC3\n\
_0803D5A0:\n\
	ldr r0, _0803D5EC @ =s32_ARRAY_08361abc\n\
	adds r0, r6, r0\n\
	ldr r0, [r0]\n\
	adds r0, r1, r0\n\
_0803D5A8:\n\
	str r0, [sp, #8]\n\
	ldr r2, [sp, #8]\n\
	ldr r0, _0803D5F0 @ =0xFFFFF000\n\
	adds r2, r2, r0\n\
	ldr r3, _0803D5F4 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _0803D5F8 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803D5FC @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsls r0, r0, #2\n\
	lsrs r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	str r2, [sp, #8]\n\
	ldr r0, [r5]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	movs r0, #3\n\
	adds r1, r4, #0\n\
	bl CreateSmoke\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D5EC: .4byte s32_ARRAY_08361abc\n\
_0803D5F0: .4byte 0xFFFFF000\n\
_0803D5F4: .4byte RNG_0202f388\n\
_0803D5F8: .4byte 0x000343FD\n\
_0803D5FC: .4byte 0x00269EC3\n\
 .syntax divided\n");
}

NAKED static void FUN_0803d600(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r1, #0\n\
	adds r0, #0xc4\n\
	ldr r0, [r0]\n\
	cmp r0, #0x77\n\
	bgt _0803D610\n\
	movs r1, #1\n\
_0803D610:\n\
	adds r7, r1, #0\n\
	movs r1, #0\n\
	cmp r0, #0xc4\n\
	ble _0803D61A\n\
	movs r1, #1\n\
_0803D61A:\n\
	adds r6, r1, #0\n\
	cmp r7, #0\n\
	bne _0803D624\n\
	cmp r6, #0\n\
	beq _0803D640\n\
_0803D624:\n\
	adds r5, r4, #0\n\
	adds r5, #0xc8\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0803D652\n\
	ldr r0, _0803D63C @ =0x0000010D\n\
	bl PlaySound\n\
	movs r0, #1\n\
	strb r0, [r5]\n\
	b _0803D652\n\
	.align 2, 0\n\
_0803D63C: .4byte 0x0000010D\n\
_0803D640:\n\
	adds r5, r4, #0\n\
	adds r5, #0xc8\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	beq _0803D652\n\
	ldr r0, _0803D69C @ =0x0000010D\n\
	bl stopSound\n\
	strb r6, [r5]\n\
_0803D652:\n\
	adds r0, r4, #0\n\
	adds r0, #0xc4\n\
	ldr r1, [r0]\n\
	adds r1, #1\n\
	str r1, [r0]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _0803D694\n\
	cmp r7, #0\n\
	beq _0803D67C\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	movs r2, #1\n\
	bl FUN_0803d454\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl AppendQuake\n\
_0803D67C:\n\
	cmp r6, #0\n\
	beq _0803D694\n\
	adds r0, r4, #0\n\
	movs r1, #1\n\
	movs r2, #1\n\
	bl FUN_0803d454\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl AppendQuake\n\
_0803D694:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D69C: .4byte 0x0000010D\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_0803d6a0(struct Boss* p) {
  // nop
  return;
}

// --------------------------------------------

INCASM("asm/boss/megamilpa.inc");

// --------------------------------------------

const struct Collision Collision_ARRAY_ARRAY_083619c8[3][3] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0xF800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0x400, 0x0, 0xF00, 0x1400},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0x0, 0x800, 0x1400, 0xB00},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : METAL,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0x0, 0xFC00, 0x1400, 0xF00},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 4,
          unk_04 : 0,
          element : 0,
          nature : 0,
          comboLv : 0,
          hitzone : 0,
          hardness : 0,
          unk_0a : 0,
          remaining : 2,
          unk_0c : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : 0,
          unk_0a : 0,
          remaining : 1,
          unk_0c : 0,
          range : {0x800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : 2,
          damage : 0,
          unk_04 : 0xFF,
          element : 0xFF,
          nature : 0xFF,
          comboLv : 0xFF,
          hitzone : 5,
          hardness : METAL,
          unk_0a : 0,
          remaining : 0,
          unk_0c : 0xFFFFFFFF,
          range : {0xFC00, 0x0, 0xF00, 0x1400},
        },
    },
};

const struct Collision gMegamilpaCoreHitbox = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : 2,
  damage : 0,
  unk_04 : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 0,
  hardness : 0,
  unk_0a : 0,
  remaining : 0,
  unk_0c : 0,
  range : {0x400, 0x0, 0x800, 0x1000},
};

const u8 u8_ARRAY_08361ab8[4] = {0, 0, 0, 0};

static const s32 s32_ARRAY_08361abc[2] = {0x4800, 0x3000};

static const u8 u8_ARRAY_08361ac4[2] = {2, 4};

const motion_t gMegamilpaMotions[5] = {
    MOTION(DM160_MEGAMILPA, 0x0C), MOTION(DM160_MEGAMILPA, 0x0D), MOTION(DM160_MEGAMILPA, 0x0E), MOTION(DM160_MEGAMILPA, 0x0F), MOTION(DM160_MEGAMILPA, 0x10),
};

const u8 u8_ARRAY_08361ad0[5] = {0, 0, 3, 6, 6};  // 083619c8 のidx
