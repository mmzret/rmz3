	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CapsuleCannon_Init
CapsuleCannon_Init: @ 0x080855F0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08085664 @ =FUN_08085cc4
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r5, r6, #0
	adds r5, #0xb8
	strb r2, [r5]
	adds r0, r6, #0
	adds r0, #0xbc
	str r2, [r0]
	subs r0, #3
	strb r2, [r0]
	ldrb r4, [r6, #0x10]
	cmp r4, #0
	bne _0808566C
	ldr r0, [r6, #0x54]
	ldr r1, _08085668 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	str r0, [r6, #0x54]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	strb r4, [r5]
	b _080856A0
	.align 2, 0
_08085664: .4byte FUN_08085cc4
_08085668: .4byte 0xFFFFF600
_0808566C:
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	str r0, [r6, #0x54]
	movs r3, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	movs r2, #0x10
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	strb r3, [r5]
_080856A0:
	ldr r1, _080856FC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r4, #0
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _08085744
	ldr r0, _08085700 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808570C
	ldr r0, _08085704 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808570C
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085708 @ =0x083684B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _08085724
	.align 2, 0
_080856FC: .4byte gEnemyFnTable
_08085700: .4byte gSystemSavedata
_08085704: .4byte gCurStory
_08085708: .4byte 0x083684B8
_0808570C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808573C @ =0x083684B8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_08085724:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _08085740 @ =0x00006801
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _080857A4
	.align 2, 0
_0808573C: .4byte 0x083684B8
_08085740: .4byte 0x00006801
_08085744:
	ldr r0, _08085778 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08085784
	ldr r0, _0808577C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08085784
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085780 @ =0x08368488
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _0808579C
	.align 2, 0
_08085778: .4byte gSystemSavedata
_0808577C: .4byte gCurStory
_08085780: .4byte 0x08368488
_08085784:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080857B8 @ =0x08368488
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_0808579C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_080857A4:
	adds r1, r6, #0
	adds r1, #0xba
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl CapsuleCannon_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080857B8: .4byte 0x08368488

