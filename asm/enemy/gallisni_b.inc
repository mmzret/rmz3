	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08087518
FUN_08087518: @ 0x08087518
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08087528
	cmp r0, #1
	beq _08087598
	b _080875BA
_08087528:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808754C @ =0x08368708
	bl SetDDP
	ldrb r0, [r4, #0x12]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	beq _08087550
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08087556
	.align 2, 0
_0808754C: .4byte 0x08368708
_08087550:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08087556:
	strb r0, [r4, #0xa]
	movs r1, #1
	adds r2, r1, #0
	ands r2, r3
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r2, #4
	ldrb r3, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	mov r2, ip
	strb r0, [r2]
	ldrb r0, [r4, #0x12]
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, _080875C0 @ =0xFFFFFC00
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r1, _080875C4 @ =0x00006703
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087598:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080875BA
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080875BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080875C0: .4byte 0xFFFFFC00
_080875C4: .4byte 0x00006703

	thumb_func_start FUN_080875c8
FUN_080875c8: @ 0x080875C8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080875D8
	cmp r5, #1
	beq _08087608
	b _08087720
_080875D8:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r2, r2, r0
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #1
	movs r3, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	subs r2, r2, r0
	str r2, [r4, #0x68]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	eors r0, r3
	ands r0, r3
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08087608:
	ldr r5, [r4, #0x64]
	str r5, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _08087638
	ldr r2, _08087634 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _08087650
	.align 2, 0
_08087634: .4byte gSineTable
_08087638:
	ldr r2, _0808767C @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_08087650:
	str r0, [r4, #0x54]
	ldr r5, [r4, #0x68]
	str r5, [r4, #0x58]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08087680
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _08087696
	.align 2, 0
_0808767C: .4byte gSineTable
_08087680:
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_08087696:
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _080876BC @ =0x00007FFF
	cmp r0, r1
	ble _080876B0
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080876B0:
	ldr r1, [r4, #0x5c]
	ldr r0, _080876C0 @ =0x000029FF
	cmp r1, r0
	bgt _080876C8
	ldr r1, _080876C4 @ =0x00006704
	b _080876D0
	.align 2, 0
_080876BC: .4byte 0x00007FFF
_080876C0: .4byte 0x000029FF
_080876C4: .4byte 0x00006704
_080876C8:
	ldr r0, _080876D8 @ =0x000053FF
	cmp r1, r0
	bgt _080876E0
	ldr r1, _080876DC @ =0x00006705
_080876D0:
	adds r0, r4, #0
	bl SetMotion
	b _0808771A
	.align 2, 0
_080876D8: .4byte 0x000053FF
_080876DC: .4byte 0x00006705
_080876E0:
	ldrb r2, [r4, #0x13]
	cmp r2, #0
	beq _080876EE
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080876F4
_080876EE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080876F4:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08087728 @ =0x00006704
	adds r0, r4, #0
	bl SetMotion
_0808771A:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08087720:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08087728: .4byte 0x00006704

	thumb_func_start FUN_0808772c
FUN_0808772c: @ 0x0808772C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808773C
	cmp r0, #1
	beq _0808775E
	b _08087780
_0808773C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldrb r2, [r4, #0x12]
	movs r0, #1
	ands r0, r2
	lsls r0, r0, #0xb
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #4
	strb r0, [r4, #0x13]
	ldr r1, _08087788 @ =0x00006703
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808775E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08087780
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08087780:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087788: .4byte 0x00006703

	thumb_func_start FUN_0808778c
FUN_0808778c: @ 0x0808778C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808779C
	cmp r5, #1
	beq _080877CC
	b _080878E4
_0808779C:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r2, r2, r0
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #1
	movs r3, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	subs r2, r2, r0
	str r2, [r4, #0x68]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	eors r0, r3
	ands r0, r3
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080877CC:
	ldr r5, [r4, #0x64]
	str r5, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r6, r1, #0
	cmp r0, #0
	bne _080877FC
	ldr r2, _080877F8 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	b _08087814
	.align 2, 0
_080877F8: .4byte gSineTable
_080877FC:
	ldr r2, _08087840 @ =gSineTable
	ldr r3, [r4, #0x5c]
	asrs r0, r3, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
_08087814:
	str r0, [r4, #0x54]
	ldr r5, [r4, #0x68]
	str r5, [r4, #0x58]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08087844
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r5, r0
	b _0808785A
	.align 2, 0
_08087840: .4byte gSineTable
_08087844:
	asrs r0, r3, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
_0808785A:
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _08087880 @ =0x00007FFF
	cmp r0, r1
	ble _08087874
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08087874:
	ldr r1, [r4, #0x5c]
	ldr r0, _08087884 @ =0x000029FF
	cmp r1, r0
	bgt _0808788C
	ldr r1, _08087888 @ =0x00006704
	b _08087894
	.align 2, 0
_08087880: .4byte 0x00007FFF
_08087884: .4byte 0x000029FF
_08087888: .4byte 0x00006704
_0808788C:
	ldr r0, _0808789C @ =0x000053FF
	cmp r1, r0
	bgt _080878A4
	ldr r1, _080878A0 @ =0x00006705
_08087894:
	adds r0, r4, #0
	bl SetMotion
	b _080878DE
	.align 2, 0
_0808789C: .4byte 0x000053FF
_080878A0: .4byte 0x00006705
_080878A4:
	ldrb r2, [r4, #0x13]
	cmp r2, #0
	beq _080878B2
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080878B8
_080878B2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080878B8:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080878EC @ =0x00006704
	adds r0, r4, #0
	bl SetMotion
_080878DE:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080878E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080878EC: .4byte 0x00006704

	thumb_func_start FUN_080878f0
FUN_080878f0: @ 0x080878F0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08087974 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08087978 @ =0x0836875A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808797C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08087980 @ =0x0000270E
	cmp r1, r0
	bhi _08087950
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08087950:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08087984 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08087974: .4byte 0xFFFFF000
_08087978: .4byte 0x0836875A
_0808797C: .4byte gScore
_08087980: .4byte 0x0000270E
_08087984: .4byte gEnemyFnTable

	thumb_func_start FUN_08087988
FUN_08087988: @ 0x08087988
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0808799A
	cmp r0, #1
	beq _08087A58
	b _08087A9E
_0808799A:
	movs r3, #0
	ldr r0, _080879BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080879AC
	movs r3, #1
_080879AC:
	adds r4, r3, #0
	adds r2, r4, #0
	cmp r4, #0
	beq _080879C0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080879C6
	.align 2, 0
_080879BC: .4byte pZero2
_080879C0:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080879C6:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r4, #8
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _08087AA8 @ =0x00006707
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r6, #0
	adds r1, #0x54
	ldr r0, _08087AAC @ =0x08368760
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r6, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b857c
	ldr r0, [sp, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
	strb r4, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08087A58:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08087A70
	str r1, [r6, #0x60]
_08087A70:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08087A98
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08087A9E
_08087A98:
	adds r0, r6, #0
	bl FUN_080878f0
_08087A9E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087AA8: .4byte 0x00006707
_08087AAC: .4byte 0x08368760

	thumb_func_start FUN_08087ab0
FUN_08087ab0: @ 0x08087AB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08087AC0
	cmp r0, #1
	beq _08087B56
	b _08087B96
_08087AC0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08087B38 @ =0x08368738
	bl SetDDP
	ldr r1, _08087B3C @ =0x00006703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _08087B40 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08087B44 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08087B48
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08087B50
	.align 2, 0
_08087B38: .4byte 0x08368738
_08087B3C: .4byte 0x00006703
_08087B40: .4byte pZero2
_08087B44: .4byte 0xFFFFE800
_08087B48:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08087B50:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08087B56:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08087B6E
	str r1, [r5, #0x60]
_08087B6E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08087B90
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08087B96
_08087B90:
	adds r0, r5, #0
	bl FUN_080878f0
_08087B96:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

