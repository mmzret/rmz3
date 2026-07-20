	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809106c
FUN_0809106c: @ 0x0809106C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _0809107C
	cmp r6, #1
	beq _08091124
	b _08091146
_0809107C:
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
	beq _080910C2
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
_080910C2:
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
	ble _08091102
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
	b _0809111E
_08091102:
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
_0809111E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091124:
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
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r2, _0809114C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r1]
_08091146:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809114C: .4byte 0xFFFFFE00

