	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806e604
FUN_0806e604: @ 0x0806E604
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806E66A
	ldr r2, [r3, #0x28]
	cmp r2, #0
	beq _0806E62C
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r3, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806E62C:
	ldr r1, _0806E658 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #2
	str r2, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _0806E65C
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0806E65E
	strb r2, [r3, #0xd]
	b _0806E660
	.align 2, 0
_0806E658: .4byte gEnemyFnTable
_0806E65C:
	movs r0, #1
_0806E65E:
	strb r0, [r3, #0xd]
_0806E660:
	adds r0, r3, #0
	bl Lemmingles_Die
	movs r0, #1
	b _0806E66C
_0806E66A:
	movs r0, #0
_0806E66C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806e674
FUN_0806e674: @ 0x0806E674
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _0806E6FA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0806E6FA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0806E694
	cmp r0, #1
	beq _0806E6D8
	b _0806E6FA
_0806E694:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0806E6FA
	ldr r1, _0806E6D0 @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E6D4 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806E6CA:
	movs r0, #1
	b _0806E6FC
	.align 2, 0
_0806E6D0: .4byte sUpdates1
_0806E6D4: .4byte sUpdates2
_0806E6D8:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0806E6F8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0806E6F4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0806E6CA
	strb r5, [r4, #0xf]
	b _0806E6FA
	.align 2, 0
_0806E6F4: .4byte 0x00020001
_0806E6F8:
	strb r0, [r4, #0xf]
_0806E6FA:
	movs r0, #0
_0806E6FC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806e704
FUN_0806e704: @ 0x0806E704
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0806E744
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806E744
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0806E730
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0806E744
_0806E730:
	ldr r2, _0806E74C @ =0x08366914
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0806E744
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0806E744:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E74C: .4byte sElementCoord

	thumb_func_start Lemmingles_Init
Lemmingles_Init: @ 0x0806E750
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0806E7C8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0806E7CC @ =0x0836691C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r0, _0806E7D0 @ =gSystemSavedata
	ldrb r1, [r0, #0x14]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0806E7DC
	ldr r0, _0806E7D4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _0806E7DC
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0806E7D8 @ =0x0836686C
	adds r2, r5, #0
	adds r2, #0x54
	ldrb r0, [r5, #0x10]
	movs r3, #0xc
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #1
	bhi _0806E7BC
	movs r3, #8
_0806E7BC:
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _0806E804
	.align 2, 0
_0806E7C8: .4byte gEnemyFnTable
_0806E7CC: .4byte sInitModes
_0806E7D0: .4byte gSystemSavedata
_0806E7D4: .4byte gCurStory
_0806E7D8: .4byte sCollisions
_0806E7DC:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r1, _0806E824 @ =0x0836686C
	adds r2, r5, #0
	adds r2, #0x54
	ldrb r0, [r5, #0x10]
	movs r3, #8
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #1
	bhi _0806E7F8
	movs r3, #4
_0806E7F8:
	adds r0, r4, #0
	bl InitBody
	str r5, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
_0806E804:
	ldr r0, _0806E828 @ =onCollision
	str r0, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #8
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl Lemmingles_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E824: .4byte sCollisions
_0806E828: .4byte onCollision

	thumb_func_start Lemmingles_Update
Lemmingles_Update: @ 0x0806E82C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _0806E840
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0806E840
	movs r0, #0
	str r0, [r4, #0x28]
_0806E840:
	ldr r0, _0806E8AC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bhi _0806E85E
	ldr r0, _0806E8B0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x42
	ands r0, r1
	cmp r0, #0
	beq _0806E8B8
_0806E85E:
	cmp r5, #0
	beq _0806E872
	adds r2, r5, #0
	adds r2, #0xb4
	movs r1, #1
	ldrb r0, [r4, #0x11]
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0806E872:
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
	ldr r1, _0806E8B4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0806E8F6
	.align 2, 0
_0806E8AC: .4byte gStageRun+232
_0806E8B0: .4byte gCurStory
_0806E8B4: .4byte gEnemyFnTable
_0806E8B8:
	adds r0, r4, #0
	bl FUN_0806e604
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E8F6
	adds r0, r4, #0
	bl FUN_0806e704
	adds r0, r4, #0
	bl FUN_0806e674
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806E8F6
	ldr r1, _0806E8FC @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E900 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0806E8F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E8FC: .4byte sUpdates1
_0806E900: .4byte sUpdates2
