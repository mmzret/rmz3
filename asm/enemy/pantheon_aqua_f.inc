	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08072e44
FUN_08072e44: @ 0x08072E44
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _08072E54
	cmp r6, #1
	beq _08072F1A
	b _08072FA0
_08072E54:
	adds r7, r4, #0
	adds r7, #0xb4
	ldr r0, [r7]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc0
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
	beq _08072EA2
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
_08072EA2:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #7
	asrs r0, r0, #8
	str r0, [r4, #0x68]
	ldr r1, [r4, #0x54]
	ldr r0, [r7]
	cmp r1, r0
	ble _08072ED8
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
	b _08072EFA
_08072ED8:
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
_08072EFA:
	ldr r1, _08072F84 @ =0x00002701
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf0
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072F88 @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08072F1A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_08073610
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	strb r1, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072F4E
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080733b4
_08072F4E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08072F64
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072F6C
_08072F64:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08072F6C:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r2, r1, r0
	cmp r2, #0
	ble _08072F90
	ldr r0, _08072F8C @ =0x00004FFF
	cmp r2, r0
	ble _08072F98
	b _08072FA0
	.align 2, 0
_08072F84: .4byte 0x00002701
_08072F88: .4byte sCollisions
_08072F8C: .4byte 0x00004FFF
_08072F90:
	subs r1, r0, r1
	ldr r0, _08072FA8 @ =0x00004FFF
	cmp r1, r0
	bgt _08072FA0
_08072F98:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08072FA0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072FA8: .4byte 0x00004FFF

