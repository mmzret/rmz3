#include "collision.h"
#include "global.h"
#include "solid.h"

static const motion_t sMotions[5];
static const struct Collision sCollisions[2];

static void CielComputer_Init(struct Solid* p);
static void CielComputer_Update(struct Solid* p);
static void CielComputer_Die(struct Solid* p);

// clang-format off
const SolidRoutine gCielComputerRoutine = {
    [ENTITY_INIT] =      CielComputer_Init,
    [ENTITY_MAIN] =      CielComputer_Update,
    [ENTITY_DIE] =       CielComputer_Die,
    [ENTITY_DISAPPEAR] = CielComputer_Die,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void CielComputer_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6}\n\
	adds r6, r0, #0\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	movs r1, #1\n\
	mov sb, r1\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	mov r2, r8\n\
	strb r2, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r5, _080DF25C @ =sMotions\n\
	ldr r4, _080DF260 @ =gSystemSavedataManager\n\
	adds r4, #0x48\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r4, [r0]\n\
	lsrs r4, r4, #8\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	ldr r1, _080DF264 @ =gStaticMotionGraphics\n\
	adds r0, r5, r1\n\
	ldr r1, _080DF268 @ =wStaticGraphicTilenums\n\
	lsls r4, r4, #1\n\
	adds r1, r4, r1\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080DF26C @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r0, _080DF270 @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080DF274 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	mov r0, r8\n\
	str r0, [r4, #0x24]\n\
	ldr r0, [r6, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r0, #1\n\
	str r0, [r6, #0x58]\n\
	ldr r1, _080DF278 @ =gSolidFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	mov r2, sb\n\
	str r2, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl CielComputer_Update\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DF25C: .4byte sMotions\n\
_080DF260: .4byte gSystemSavedataManager\n\
_080DF264: .4byte gStaticMotionGraphics\n\
_080DF268: .4byte wStaticGraphicTilenums\n\
_080DF26C: .4byte gStaticMotionGraphics+12\n\
_080DF270: .4byte wStaticMotionPalIDs\n\
_080DF274: .4byte sCollisions\n\
_080DF278: .4byte gSolidFnTable\n\
 .syntax divided\n");
}

NAKED static void CielComputer_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #0\n\
	beq _080DF294\n\
	cmp r0, #1\n\
	beq _080DF358\n\
	b _080DF3EA\n\
_080DF294:\n\
	adds r0, r6, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x16\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080DF2A6\n\
	b _080DF3EA\n\
_080DF2A6:\n\
	ldr r0, _080DF340 @ =gInChat\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080DF2B0\n\
	b _080DF3EA\n\
_080DF2B0:\n\
	ldr r0, _080DF344 @ =gCollisionManager\n\
	movs r1, #0xc5\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	adds r1, r6, #0\n\
	adds r1, #0x74\n\
	ldr r0, [r0]\n\
	cmp r0, r1\n\
	beq _080DF2C4\n\
	b _080DF3EA\n\
_080DF2C4:\n\
	ldr r0, _080DF348 @ =gSystemSavedataManager\n\
	adds r4, r0, #0\n\
	adds r4, #0x48\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bhi _080DF302\n\
	ldr r1, _080DF34C @ =sMotions\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4]\n\
	cmp r0, #3\n\
	bne _080DF302\n\
	adds r0, r6, #0\n\
	bl GetEntityPalID\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x13\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	movs r0, #0xf1\n\
	bl LoadBlink\n\
_080DF302:\n\
	ldr r0, _080DF348 @ =gSystemSavedataManager\n\
	adds r0, #0x48\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bne _080DF326\n\
	adds r0, r6, #0\n\
	bl GetEntityPalID\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x13\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	movs r0, #0xf2\n\
	bl LoadBlink\n\
_080DF326:\n\
	movs r0, #0x95\n\
	lsls r0, r0, #1\n\
	bl PlaySound\n\
	ldr r0, _080DF350 @ =gGameState\n\
	ldr r1, _080DF354 @ =0x00060400\n\
	bl SetGameMode\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r6, #0xd]\n\
	b _080DF3EA\n\
	.align 2, 0\n\
_080DF340: .4byte gInChat\n\
_080DF344: .4byte gCollisionManager\n\
_080DF348: .4byte gSystemSavedataManager\n\
_080DF34C: .4byte sMotions\n\
_080DF350: .4byte gGameState\n\
_080DF354: .4byte 0x00060400\n\
_080DF358:\n\
	movs r0, #0xf1\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0xf2\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080DF3F4 @ =gGameState\n\
	ldrb r7, [r0, #2]\n\
	cmp r7, #0\n\
	bne _080DF3EA\n\
	movs r0, #0xf1\n\
	bl ClearBlink\n\
	movs r0, #0xf2\n\
	bl ClearBlink\n\
	ldr r0, _080DF3F8 @ =gSystemSavedataManager\n\
	adds r0, #0x48\n\
	mov r8, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bls _080DF3D2\n\
	ldr r1, _080DF3FC @ =sMotions\n\
	mov r2, r8\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	lsrs r4, r4, #8\n\
	lsls r5, r4, #2\n\
	adds r5, r5, r4\n\
	lsls r5, r5, #2\n\
	ldr r1, _080DF400 @ =gStaticMotionGraphics\n\
	adds r0, r5, r1\n\
	ldr r1, _080DF404 @ =wStaticGraphicTilenums\n\
	lsls r4, r4, #1\n\
	adds r1, r4, r1\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl RequestGraphicTransfer\n\
	ldr r0, _080DF408 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r0, _080DF40C @ =wStaticMotionPalIDs\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
_080DF3D2:\n\
	ldr r1, _080DF3FC @ =sMotions\n\
	mov r2, r8\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldr r0, _080DF410 @ =gInChat\n\
	strb r7, [r0]\n\
	strb r7, [r6, #0xd]\n\
_080DF3EA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DF3F4: .4byte gGameState\n\
_080DF3F8: .4byte gSystemSavedataManager\n\
_080DF3FC: .4byte sMotions\n\
_080DF400: .4byte gStaticMotionGraphics\n\
_080DF404: .4byte wStaticGraphicTilenums\n\
_080DF408: .4byte gStaticMotionGraphics+12\n\
_080DF40C: .4byte wStaticMotionPalIDs\n\
_080DF410: .4byte gInChat\n\
 .syntax divided\n");
}

static void CielComputer_Die(struct Solid* p) {
  DeleteSolid(p);
  return;
}

// clang-format off
static const motion_t sMotions[5] = {
    MOTION(0x90, 0x00),
    MOTION(0x91, 0x00),
    MOTION(0x92, 0x00),
    MOTION(0x93, 0x00),
    MOTION(0x94, 0x00),
};
// clang-format on

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_UNK2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0100},
    },
    {
      kind : DRP,
      faction : FACTION_UNK2,
      special : CHATABLE,
      damage : 255,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};
