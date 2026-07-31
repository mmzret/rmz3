	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807c96c
FUN_0807c96c: @ 0x0807C96C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807C97E
	cmp r5, #1
	beq _0807C994
	b _0807CA8A
_0807C97E:
	movs r1, #0x82
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xc4
	strb r0, [r4, #0x12]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C994:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x68]
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	ldr r1, _0807C9F0 @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl dragInSea
	ldr r0, _0807C9F4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C9F8
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807CA30
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807CA12
	movs r0, #0x10
	orrs r0, r2
	b _0807CA16
	.align 2, 0
_0807C9F0: .4byte gSineTable
_0807C9F4: .4byte pZero2
_0807C9F8:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807CA30
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807CA12
	movs r0, #0x10
	orrs r0, r2
	b _0807CA16
_0807CA12:
	movs r0, #0xef
	ands r0, r2
_0807CA16:
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
_0807CA30:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807CA46
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807CA8A
_0807CA46:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807CA5C
	ldr r0, [r4, #0x54]
	ldr r2, _0807CA58 @ =0xFFFFEA00
	adds r0, r0, r2
	b _0807CA64
	.align 2, 0
_0807CA58: .4byte 0xFFFFEA00
_0807CA5C:
	ldr r0, [r4, #0x54]
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r0, r3
_0807CA64:
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r2, _0807CA94 @ =0xFFFFFC00
	adds r0, r0, r2
	str r0, [sp, #4]
	lsls r3, r1, #0x18
	lsrs r3, r3, #0x1c
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	mov r1, sp
	mov r2, sp
	bl FUN_080a2838
	movs r0, #0
	bl PlaySound
	movs r0, #0xc4
	strb r0, [r4, #0x12]
_0807CA8A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CA94: .4byte 0xFFFFFC00
