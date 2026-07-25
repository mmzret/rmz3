	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08077388
FUN_08077388: @ 0x08077388
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080773D0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080773D0
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080773D0
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080773BC
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080773D0
_080773BC:
	ldr r2, _080773D8 @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080773D0
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080773D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080773D8: .4byte sElementCoord

	thumb_func_start Volcaire_Init
Volcaire_Init: @ 0x080773DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0807742C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08077430 @ =sInitModes
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r2, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08077434
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _080774BC
	.align 2, 0
_0807742C: .4byte gEnemyFnTable
_08077430: .4byte sInitModes
_08077434:
	cmp r0, #0
	blt _080774BC
	cmp r0, #2
	bgt _080774BC
	adds r0, r6, #0
	adds r0, #0xb9
	strb r2, [r0]
	ldrb r0, [r6, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, _08077484 @ =gSystemSavedata
	ldrb r1, [r0, #0x14]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08077490
	ldr r0, _08077488 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08077490
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807748C @ =0x083672B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _080774A8
	.align 2, 0
_08077484: .4byte gSystemSavedata
_08077488: .4byte gCurStory
_0807748C: .4byte sCollisions
_08077490:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080774C8 @ =0x083672B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_080774A8:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080774CC @ =onCollision
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
_080774BC:
	adds r0, r6, #0
	bl Volcaire_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080774C8: .4byte sCollisions
_080774CC: .4byte onCollision

	thumb_func_start Volcaire_Update
Volcaire_Update: @ 0x080774D0
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0807754C @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08077512
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08077554
	ldr r3, [r4, #0x28]
	cmp r3, #0
	beq _080774FA
	ldrb r0, [r3, #0xc]
	cmp r0, #1
	bls _080774FA
	str r1, [r4, #0x28]
	movs r3, #0
_080774FA:
	ldrb r1, [r2, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08077554
	cmp r3, #0
	beq _08077512
	adds r1, r3, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077512:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08077550 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08077592
	.align 2, 0
_0807754C: .4byte gCurStory
_08077550: .4byte gEnemyFnTable
_08077554:
	adds r0, r4, #0
	bl FUN_08077260
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077592
	adds r0, r4, #0
	bl FUN_08077388
	adds r0, r4, #0
	bl FUN_080772f8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077592
	ldr r1, _08077598 @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807759C @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08077592:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077598: .4byte sUpdates1
_0807759C: .4byte sUpdates2
