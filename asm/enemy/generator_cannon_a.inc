	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808c3ec
FUN_0808c3ec: @ 0x0808C3EC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808C448
	ldr r1, _0808C428 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	beq _0808C43C
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0808C42C
	strb r4, [r2, #0xd]
	b _0808C43E
	.align 2, 0
_0808C428: .4byte gEnemyFnTable
_0808C42C:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0808C43A
	movs r0, #3
	b _0808C43C
_0808C43A:
	movs r0, #1
_0808C43C:
	strb r0, [r2, #0xd]
_0808C43E:
	adds r0, r2, #0
	bl GeneratorCannon_Die
	movs r0, #1
	b _0808C44A
_0808C448:
	movs r0, #0
_0808C44A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808c450
FUN_0808c450: @ 0x0808C450
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0808C4DE
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0808C4DE
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808C470
	cmp r0, #1
	beq _0808C4B4
	b _0808C4DE
_0808C470:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808C4DE
	ldr r1, _0808C4AC @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808C4B0 @ =sUpdates2
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
_0808C4A6:
	movs r0, #1
	b _0808C4E0
	.align 2, 0
_0808C4AC: .4byte sUpdates1
_0808C4B0: .4byte sUpdates2
_0808C4B4:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808C4DC
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808C4A6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C4D8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C4A6
	strb r5, [r4, #0xf]
	b _0808C4DE
	.align 2, 0
_0808C4D8: .4byte 0x00020001
_0808C4DC:
	strb r0, [r4, #0xf]
_0808C4DE:
	movs r0, #0
_0808C4E0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c4e8
FUN_0808c4e8: @ 0x0808C4E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0x10]
	cmp r1, #1
	bne _0808C52C
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0808C52C
	adds r0, #0x8c
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0808C52C
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r0
	cmp r5, #0
	beq _0808C518
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0808C52C
_0808C518:
	ldr r2, _0808C534 @ =0x08369108
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808C52C
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808C52C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808C534: .4byte 0x08369108

	thumb_func_start GeneratorCannon_Init
GeneratorCannon_Init: @ 0x0808C538
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808C5C8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _0808C5CC @ =0x08369110
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808C604
	ldrb r0, [r6, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, _0808C5D0 @ =0x08369114
	str r0, [r6, #0x30]
	ldr r0, _0808C5D4 @ =0x00000801
	strh r0, [r6, #0x26]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r0, _0808C5D8 @ =gSystemSavedata
	ldrb r1, [r0, #0x13]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808C5E4
	ldr r0, _0808C5DC @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0808C5E4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C5E0 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	b _0808C620
	.align 2, 0
_0808C5C8: .4byte gEnemyFnTable
_0808C5CC: .4byte 0x08369110
_0808C5D0: .4byte 0x08369114
_0808C5D4: .4byte 0x00000801
_0808C5D8: .4byte gSystemSavedata
_0808C5DC: .4byte gCurStory
_0808C5E0: .4byte sCollisions
_0808C5E4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C600 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x14
	b _0808C620
	.align 2, 0
_0808C600: .4byte sCollisions
_0808C604:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r5, [r0]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C638 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #5
_0808C620:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808C63C @ =onCollision
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl GeneratorCannon_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808C638: .4byte sCollisions
_0808C63C: .4byte onCollision

	thumb_func_start GeneratorCannon_Update
GeneratorCannon_Update: @ 0x0808C640
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808C660 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0808C664
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0808C678
	.align 2, 0
_0808C660: .4byte gCurStory
_0808C664:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808C6AC
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808C6AC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808C678:
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
	ldr r1, _0808C6A8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808C6EA
	.align 2, 0
_0808C6A8: .4byte gEnemyFnTable
_0808C6AC:
	adds r0, r4, #0
	bl FUN_0808c3ec
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C6EA
	adds r0, r4, #0
	bl FUN_0808c4e8
	adds r0, r4, #0
	bl FUN_0808c450
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C6EA
	ldr r1, _0808C6F0 @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808C6F4 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808C6EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C6F0: .4byte sUpdates1
_0808C6F4: .4byte sUpdates2

	thumb_func_start GeneratorCannon_Die
GeneratorCannon_Die: @ 0x0808C6F8
	push {lr}
	adds r3, r0, #0
	ldr r0, _0808C740 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808C748
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0808C744 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _0808C758
	.align 2, 0
_0808C740: .4byte gCurStory
_0808C744: .4byte gEnemyFnTable
_0808C748:
	ldr r0, _0808C75C @ =0x08368F48
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_0808C758:
	pop {r0}
	bx r0
	.align 2, 0
_0808C75C: .4byte 0x08368F48
