	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mothjiro_080884a4
mothjiro_080884a4: @ 0x080884A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _080884B4
	cmp r6, #1
	beq _08088566
	b _080885E8
_080884B4:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r1, [r1]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _0808850C
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_0808850C:
	ldr r1, [r4, #0x5c]
	lsls r1, r1, #9
	asrs r1, r1, #8
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	cmp r1, #0
	ble _08088544
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _08088560
_08088544:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08088560:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08088566:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080885A2
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_080885A2:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, [r4, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080885B2
	subs r1, r2, r0
_080885B2:
	ldr r0, _080885F0 @ =0x00004FFF
	cmp r1, r0
	bgt _080885D6
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080885C8
	subs r1, r2, r0
_080885C8:
	ldr r0, _080885F4 @ =0x000017FF
	cmp r1, r0
	bgt _080885D6
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080885D6:
	adds r0, r4, #0
	bl FUN_08088ae0
	adds r1, r0, #0
	cmp r1, #0
	bne _080885E8
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080885E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080885F0: .4byte 0x00004FFF
_080885F4: .4byte 0x000017FF

