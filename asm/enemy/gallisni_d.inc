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
