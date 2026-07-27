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

	thumb_func_start CapsuleCannon_Update
CapsuleCannon_Update: @ 0x080857BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080857EC
	ldr r1, _080857E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl CapsuleCannon_Die
	b _08085868
	.align 2, 0
_080857E8: .4byte gEnemyFnTable
_080857EC:
	ldr r1, _0808583C @ =0x08368458
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08085c4c
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0808581E
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _08085868
	ldr r0, [r5]
	cmp r0, #0
	beq _08085858
_0808581E:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08085868
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _08085844
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085840 @ =0x083684B8
	bl SetDDP
	b _0808584E
	.align 2, 0
_0808583C: .4byte 0x08368458
_08085840: .4byte 0x083684B8
_08085844:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085854 @ =0x08368488
	bl SetDDP
_0808584E:
	movs r0, #0
	str r0, [r5]
	b _08085868
	.align 2, 0
_08085854: .4byte 0x08368488
_08085858:
	ldr r0, _08085870 @ =0x08368470
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08085868:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085870: .4byte 0x08368470

	thumb_func_start CapsuleCannon_Die
CapsuleCannon_Die: @ 0x08085874
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080858BC @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080858C4
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080858C0 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080859F0
	.align 2, 0
_080858BC: .4byte gCurStory
_080858C0: .4byte gEnemyFnTable
_080858C4:
	ldrb r1, [r7, #0xe]
	cmp r1, #1
	beq _080858F4
	cmp r1, #1
	bgt _080858D4
	cmp r1, #0
	beq _080858DA
	b _080859F2
_080858D4:
	cmp r1, #2
	beq _08085904
	b _080859F2
_080858DA:
	movs r0, #1
	strb r0, [r7, #0xe]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
_080858F4:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080859F2
_08085904:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08085918
	ldr r0, [r7, #0x5c]
	ldr r1, _08085914 @ =0xFFFFF800
	b _0808591E
	.align 2, 0
_08085914: .4byte 0xFFFFF800
_08085918:
	ldr r0, [r7, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #4
_0808591E:
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r7, #0x60]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08085990 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08085994 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08085998 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808599C @ =0x00006803
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	ldrb r1, [r5]
	ldr r2, _080859A0 @ =0x00006804
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	ldrb r1, [r5]
	ldr r2, _080859A4 @ =0x00006805
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080859AC
	ldr r0, [r7, #0x54]
	ldr r1, _080859A8 @ =0xFFFFF400
	b _080859B2
	.align 2, 0
_08085990: .4byte RNG_0202f388
_08085994: .4byte 0x000343FD
_08085998: .4byte 0x00269EC3
_0808599C: .4byte 0x00006803
_080859A0: .4byte 0x00006804
_080859A4: .4byte 0x00006805
_080859A8: .4byte 0xFFFFF400
_080859AC:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
_080859B2:
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080859FC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08085A00 @ =0x0000270E
	cmp r1, r0
	bhi _080859D0
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080859D0:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08085A04 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_080859F0:
	str r0, [r7, #0x14]
_080859F2:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080859FC: .4byte gScore
_08085A00: .4byte 0x0000270E
_08085A04: .4byte gEnemyFnTable
