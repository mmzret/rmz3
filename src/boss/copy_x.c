#include "boss.h"
#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "vfx.h"

struct VFX* CreateVFX55(struct Boss* p, u8 r1, u8 r2);

static const struct Collision sCollisions[10];

static void CopyX_Init(struct Boss* p);
static void CopyX_Update(struct Boss* p);
static void CopyX_Die(struct Boss* p);

// clang-format off
const BossRoutine gCopyXRoutine = {
    [ENTITY_INIT] =      CopyX_Init,
    [ENTITY_UPDATE] =    CopyX_Update,
    [ENTITY_DIE] =       CopyX_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

void CreateCopyX(struct Coord* c) {
  struct Boss* p = (struct Boss*)AllocEntityFirst(gBossHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;

    INIT_BOSS_ROUTINE(p, BOSS_COPY_X);

    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;

    ((p->s).coord).x = c->x;
    ((p->s).coord).y = c->y;

    (p->s).work[0] = 0;
    (p->s).work[1] = 0;
  }
}

// --------------------------------------------

NAKED static void CopyX_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	movs r4, #0xeb\n\
	lsls r4, r4, #3\n\
	ldr r5, _08055620 @ =gStaticMotionGraphics\n\
	adds r0, r4, r5\n\
	ldr r1, _08055624 @ =wStaticGraphicTilenums\n\
	mov sb, r1\n\
	adds r1, #0xbc\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	mov r8, r2\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	ldr r6, _08055628 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r6\n\
	ldr r0, _0805562C @ =wStaticMotionPalIDs\n\
	mov sl, r0\n\
	adds r0, #0xbc\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055630 @ =0x00000744\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xba\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xba\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055634 @ =0x0000071C\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xb6\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xb6\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xe6\n\
	lsls r4, r4, #3\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xb8\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xb8\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055638 @ =0x0000076C\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xbe\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xbe\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #3\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xc0\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xc0\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _0805563C @ =0x00000794\n\
	adds r5, r4, r5\n\
	mov r0, sb\n\
	adds r0, #0xc2\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r5, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	adds r0, r5, #0\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xc2\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08055640 @ =0x0000B319\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r0, r7, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	strb r5, [r0]\n\
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
	ldr r1, _08055644 @ =sCollisions\n\
	adds r0, r7, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	ldr r1, _08055648 @ =CopyX_OnDamage\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_0800a134\n\
	adds r1, r7, #0\n\
	adds r1, #0xb8\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_0800a31c\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r7, #0\n\
	adds r1, #0xd4\n\
	str r0, [r1]\n\
	str r0, [r7, #0x58]\n\
	subs r1, #0x18\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xc5\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r1, #0xa\n\
	movs r4, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xcc\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	adds r1, #0xe\n\
	movs r0, #0x3c\n\
	strh r0, [r1]\n\
	adds r1, #5\n\
	movs r0, #0x30\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xcf\n\
	strb r4, [r0]\n\
	subs r1, #1\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xde\n\
	strb r4, [r0]\n\
	subs r1, #0xc\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xd2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	strh r1, [r0]\n\
	str r5, [r7, #0x2c]\n\
	adds r1, r7, #0\n\
	adds r1, #0xce\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl FUN_080a9aa0\n\
	ldr r1, _0805564C @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	strb r4, [r7, #0xd]\n\
	strb r1, [r7, #0xe]\n\
	adds r0, r7, #0\n\
	bl CopyX_Update\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08055620: .4byte gStaticMotionGraphics\n\
_08055624: .4byte wStaticGraphicTilenums\n\
_08055628: .4byte gStaticMotionGraphics+12\n\
_0805562C: .4byte wStaticMotionPalIDs\n\
_08055630: .4byte 0x00000744\n\
_08055634: .4byte 0x0000071C\n\
_08055638: .4byte 0x0000076C\n\
_0805563C: .4byte 0x00000794\n\
_08055640: .4byte 0x0000B319\n\
_08055644: .4byte sCollisions\n\
_08055648: .4byte CopyX_OnDamage\n\
_0805564C: .4byte gBossFnTable\n\
 .syntax divided\n");
}

static void copyx_080557a4(struct Boss* p);
static void copyxMode1(struct Boss* p);
void copyxNeutral(struct Boss* p);
void copyxNextMode(struct Boss* p);
void copyxMode4(struct Boss* p);
void copyxMode5(struct Boss* p);
void copyxMode6(struct Boss* p);
void copyxMode7(struct Boss* p);
void copyxMode8(struct Boss* p);
void copyxMode9(struct Boss* p);
void copyxMode10(struct Boss* p);
void copyxMode11(struct Boss* p);
void copyxMode12(struct Boss* p);
void copyxJumpForNovaStrike(struct Boss* p);
void copyxNovaStrike2(struct Boss* p);
void copyxNovaStrike3(struct Boss* p);
void copyxMode16(struct Boss* p);
void copyxMode17(struct Boss* p);
void copyxMode18(struct Boss* p);
void copyxMode19(struct Boss* p);
void copyx_08056508(struct Boss* p);
void copyx_080565c0(struct Boss* p);
void copyx_080566b0(struct Boss* p);
void copyx_08056724(struct Boss* p);
void copyx_08056794(struct Boss* p);
void copyx_080568bc(struct Boss* p);
void copyx_08056908(struct Boss* p);
void FUN_080569a4(struct Boss* p);
void copyx_080569e4(struct Boss* p);
void FUN_08056a80(struct Boss* p);
void copyx_08056ac0(struct Boss* p);
void copyx_08056b6c(struct Boss* p);
void copyx_08056bd0(struct Boss* p);
void copyxKnockBackDamage(struct Boss* p);
void FUN_08056d58(struct Boss* p);
void copyxRaisingExcharge(struct Boss* p);
void copyxMode36(struct Boss* p);
void copyx_08057094(struct Boss* p);
void copyxMode38(struct Boss* p);

// clang-format off
static const BossFunc sUpdates[39] = {
    [0] =  copyx_080557a4,
    [1] =  copyxMode1,
    [2] =  copyxNeutral,
    [3] =  copyxNextMode,
    [4] =  copyxMode4,
    [5] =  copyxMode5,
    [6] =  copyxMode6,
    [7] =  copyxMode7,
    [8] =  copyxMode8,
    [9] =  copyxMode9,
    [10] = copyxMode10,
    [11] = copyxMode11,
    [12] = copyxMode12,
    [13] = copyxJumpForNovaStrike,
    [14] = copyxNovaStrike2,
    [15] = copyxNovaStrike3,
    [16] = copyxMode16,
    [17] = copyxMode17,
    [18] = copyxMode18,
    [19] = copyxMode19,
    [20] = copyx_08056508,
    [21] = copyx_080565c0,
    [22] = copyx_080566b0,
    [23] = copyx_08056724,
    [24] = copyx_08056794,
    [25] = copyx_080568bc,
    [26] = copyx_08056908,
    [27] = FUN_080569a4,
    [28] = copyx_080569e4,
    [29] = FUN_08056a80,
    [30] = copyx_08056ac0,
    [31] = copyx_08056b6c,
    [32] = copyx_08056bd0,
    [33] = copyxKnockBackDamage,
    [34] = FUN_08056d58,
    [35] = copyxRaisingExcharge,
    [36] = copyxMode36,
    [37] = copyx_08057094,
    [38] = copyxMode38,
};
// clang-format on

NAKED static void CopyX_Update(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	adds r6, r4, #0\n\
	adds r6, #0x8c\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08055670\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0\n\
	bne _080556D0\n\
_08055670:\n\
	ldr r0, _080556C8 @ =gStageRun\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	bne _080556D0\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5c\n\
	bl LoadBlink\n\
	movs r0, #0x5c\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x5c\n\
	bl ClearBlink\n\
	ldr r1, _080556CC @ =gBossFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #0xe]\n\
	str r5, [r6]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	strb r5, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl CopyX_Die\n\
	b _08055774\n\
	.align 2, 0\n\
_080556C8: .4byte gStageRun\n\
_080556CC: .4byte gBossFnTable\n\
_080556D0:\n\
	adds r0, r4, #0\n\
	bl copyx_08057744\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0x21\n\
	beq _080556F4\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	ldrb r0, [r0]\n\
	subs r0, #0x10\n\
	adds r1, r4, #0\n\
	adds r1, #0xdd\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bge _080556F4\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080556F4:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r2, [r0]\n\
	movs r3, #1\n\
	adds r0, r2, #0\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0805573E\n\
	adds r0, r4, #0\n\
	adds r0, #0x97\n\
	ldrb r1, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0805571C\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #8\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _0805573E\n\
_0805571C:\n\
	ldrb r1, [r4, #0xd]\n\
	subs r0, r1, #5\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bls _0805573E\n\
	adds r0, r1, #0\n\
	cmp r0, #9\n\
	beq _0805573E\n\
	cmp r0, #0xa\n\
	beq _0805573E\n\
	cmp r0, #0xb\n\
	beq _0805573E\n\
	movs r0, #0x21\n\
	strb r0, [r4, #0xd]\n\
	strb r3, [r4, #0xe]\n\
	strb r0, [r4, #0xf]\n\
_0805573E:\n\
	ldr r1, _0805577C @ =sUpdates\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r5, r4, #0\n\
	adds r5, #0xc5\n\
	ldrb r0, [r5]\n\
	adds r0, #0x5c\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	bl LoadBlink\n\
	ldrb r0, [r5]\n\
	adds r0, #0x5c\n\
	bl UpdateBlinkMotionState\n\
	ldrb r0, [r5]\n\
	adds r0, #0x5c\n\
	bl ClearBlink\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_08055774:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805577C: .4byte sUpdates\n\
 .syntax divided\n");
}

void copyx_08057744(struct Boss* p);
void copyx_08057204(struct Boss* p);
void copyx_08057418(struct Boss* p);
void copyx_08057520(struct Boss* p);
void copyx_08057590(struct Boss* p);
void copyx_0805763c(struct Boss* p);

static void CopyX_Die(struct Boss* p) {
  // clang-format off
  static const BossFunc sDeads[5] = {
      [0] = copyx_08057204,
      [1] = copyx_08057418,
      [2] = copyx_08057520,
      [3] = copyx_08057590,
      [4] = copyx_0805763c,
  };
  // clang-format on
  copyx_08057744(p);
  (sDeads[(p->s).mode[1]])(p);
}

static void copyx_080557a4(struct Boss* p) {
  if ((p->s).arr[9] & 1) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 1;
  }
}

static void copyxMode1(struct Boss* p) {
  if ((p->s).mode[2] != 0) {
    SetMotion(&p->s, MOTION(DM179_COPY_X, 0x1A));
    CreateVFX55(p, 0, 0);
    (p->s).mode[2] = 0;
    (p->s).mode[3] = 0;
    (p->s).work[2] = 0;
  }
  if (((p->s).work[2] == 0) && ((p->s).motion.cmdIdx == 6)) {
    PlaySound(SE_COPYX_MODE_CHANGE);
    (p->s).work[2]++;
  }
  if ((p->s).mode[3] == 0) {
    if ((p->s).motion.state == MOTION_END) {
      (p->s).mode[3]++;
    }
  } else if (!(gStageRun.vm.active & 1)) {
    SetMotion(&p->s, MOTION(DM179_COPY_X, 0x00));
    (p->s).mode[1] = 2;
    (p->s).mode[2] = 1;
  }
}

INCASM("asm/boss/copy_x.inc");

static const struct Collision sCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 5,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 5,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : 0x01,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0xFFFFFFFF,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(8), -PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 2,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 5,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(8), -PIXEL(8), PIXEL(8), PIXEL(16)},
    },
};
