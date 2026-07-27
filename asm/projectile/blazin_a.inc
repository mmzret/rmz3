	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809e7c0
FUN_0809e7c0: @ 0x0809E7C0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809E824
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809E818
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809E810 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0809E814 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809E82A
	.align 2, 0
_0809E810: .4byte 0xFFFFF800
_0809E814: .4byte 0xFFFFFC00
_0809E818:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E848
_0809E824:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809E82A:
	bl CreateSmoke
	ldr r1, _0809E844 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809E9AE
	.align 2, 0
_0809E844: .4byte gProjectileFnTable
_0809E848:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809E854
	cmp r0, #1
	beq _0809E8C8
	b _0809E9AE
_0809E854:
	ldr r1, _0809E890 @ =0x0000A304
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809E894
	movs r0, #0xc0
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	b _0809E8B8
	.align 2, 0
_0809E890: .4byte 0x0000A304
_0809E894:
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
_0809E8B8:
	strb r0, [r2]
	ldr r0, _0809E948 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809E8C8:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809E8E2
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E8E2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809E94C @ =0x0836AD78
	bl SetDDP
_0809E8E2:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809E8F2
	str r1, [r4, #0x60]
_0809E8F2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809E916
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809E950 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809E916:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809E954
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E948: .4byte 0xFFFFFC00
_0809E94C: .4byte 0x0836AD78
_0809E950: .4byte 0xFFFFFD00
_0809E954:
	ldr r0, [r4, #0x54]
	ldr r1, _0809E980 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E980: .4byte 0xFFFFF800
_0809E984:
	movs r0, #0xef
	ands r0, r2
_0809E988:
	strb r0, [r4, #0xa]
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
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809E9A8:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0809E9AE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
