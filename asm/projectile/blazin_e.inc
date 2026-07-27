	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809ee08
FUN_0809ee08: @ 0x0809EE08
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809EE22
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _0809EFEE
_0809EE22:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EE6E
	cmp r0, #1
	bgt _0809EE32
	cmp r0, #0
	beq _0809EE40
	b _0809F000
_0809EE32:
	cmp r0, #2
	bne _0809EE38
	b _0809EF4E
_0809EE38:
	cmp r0, #3
	bne _0809EE3E
	b _0809EFC4
_0809EE3E:
	b _0809F000
_0809EE40:
	ldr r1, _0809EEE0 @ =0x0000A305
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xa0
	lsls r1, r1, #3
	str r1, [r2]
	ldr r0, [r5, #0x5c]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EE6E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r6, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r1, r4
	bl PushoutToUp1
	str r0, [sp]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0809EEE4 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToDown1
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	ldr r3, _0809EEE4 @ =0xFFFFF800
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r2, r0, #0
	str r2, [sp, #0xc]
	ldr r1, [sp]
	cmp r1, #0
	beq _0809EEEE
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EEE8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
	.align 2, 0
_0809EEE0: .4byte 0x0000A305
_0809EEE4: .4byte 0xFFFFF800
_0809EEE8:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EEEE:
	ldr r1, [sp, #4]
	cmp r1, #0
	beq _0809EF12
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF0C
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF0C:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EF12:
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF1E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF1E:
	cmp r2, #0
	beq _0809EF30
_0809EF22:
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
_0809EF26:
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	rsbs r0, r0, #0
	str r0, [r5, #0x64]
_0809EF2E:
	movs r6, #1
_0809EF30:
	cmp r6, #1
	bne _0809F000
	movs r0, #0
	bl PlaySound
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809F000
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809F000
_0809EF4E:
	adds r6, r5, #0
	adds r6, #0xb8
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6]
	ldr r1, [r5, #0x28]
	ldr r2, [r1, #0x54]
	ldr r0, [r5, #0x54]
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809EFA4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x60]
_0809EFA4:
	ldr r1, [r5, #0x5c]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EFC4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r2, r5, #0
	adds r2, #0xbc
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	cmp r0, #0
	bgt _0809F000
_0809EFEE:
	ldr r1, _0809F008 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809F000:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F008: .4byte gProjectileFnTable
