	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mothjiro_080888a0
mothjiro_080888a0: @ 0x080888A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	mov r8, r0
	cmp r0, #0
	beq _080888B6
	cmp r0, #1
	beq _0808896A
	b _08088A08
_080888B6:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
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
	beq _08088906
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
_08088906:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08088946
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
	b _08088964
_08088946:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08088964:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808896A:
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
	movs r2, #0
	mov r8, r2
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080889AA
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_080889AA:
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	ldr r1, _08088A14 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5]
	cmp r0, #0
	bgt _080889C0
	mov r2, r8
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_080889C0:
	adds r0, r4, #0
	bl FUN_08088ae0
	cmp r0, #0
	beq _08088A08
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	subs r6, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	subs r7, r1, r0
	asrs r0, r6, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r7, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #0xe
	ldr r0, _08088A18 @ =0x000077FF
	cmp r1, r0
	bgt _08088A08
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	mov r0, r8
	strb r0, [r4, #0xe]
_08088A08:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08088A14: .4byte 0xFFFFFE00
_08088A18: .4byte 0x000077FF

