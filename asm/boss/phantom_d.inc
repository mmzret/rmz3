	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805f4a4
FUN_0805f4a4: @ 0x0805F4A4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0805F508
	ldr r3, [r5, #0x54]
	str r3, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	ldr r0, _0805F4EC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	subs r0, r0, r3
	subs r1, r1, r2
	ldr r2, _0805F4F0 @ =0xFFFFE800
	adds r1, r1, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x18
	cmp r4, #0x80
	bls _0805F4F6
	cmp r4, #0xc0
	bls _0805F4F4
	movs r4, #0
	b _0805F4F6
	.align 2, 0
_0805F4EC: .4byte pZero2
_0805F4F0: .4byte 0xFFFFE800
_0805F4F4:
	movs r4, #0x80
_0805F4F6:
	movs r0, #0xfc
	bl PlaySound
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r4, #0
	bl FUN_080afcec
_0805F508:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F522
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	movs r3, #1
	bl FUN_080607bc
	movs r0, #5
	strh r0, [r5, #0xe]
_0805F522:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

