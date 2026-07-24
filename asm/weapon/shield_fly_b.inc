	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803a5c8
FUN_0803a5c8: @ 0x0803A5C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	subs r2, r6, r3
	adds r0, r2, r4
	movs r5, #0xff
	ands r0, r5
	lsls r1, r4, #1
	cmp r0, r1
	bhi _0803A5E2
	adds r3, r6, #0
	b _0803A5F4
_0803A5E2:
	ands r2, r5
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, #0x7f
	bgt _0803A5EE
	movs r0, #1
_0803A5EE:
	muls r0, r4, r0
	adds r3, r3, r0
	ands r3, r5
_0803A5F4:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start shield_0803a5fc
shield_0803a5fc: @ 0x0803A5FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov ip, r0
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803A630
	ldr r2, _0803A628 @ =gZeroRanges
	ldr r3, _0803A62C @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	subs r4, r0, r1
	b _0803A646
	.align 2, 0
_0803A628: .4byte gZeroRanges
_0803A62C: .4byte 0x00000147
_0803A630:
	ldr r2, _0803A690 @ =gZeroRanges
	ldr r3, _0803A694 @ =0x00000147
	add r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r4, ip
	ldr r0, [r4, #0x54]
	adds r4, r0, r1
_0803A646:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r2, #2
	ldrsh r1, [r0, r2]
	mov r3, ip
	ldr r0, [r3, #0x58]
	adds r1, r0, r1
	ldr r0, [r5, #0x54]
	subs r4, r4, r0
	ldr r0, [r5, #0x58]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, r2
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r0, r2
	bhi _0803A698
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r1, r3
	cmp r0, r2
	bhi _0803A698
	adds r0, r4, #0
	muls r0, r4, r0
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r4, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	cmp r0, r1
	bgt _0803A698
	movs r0, #1
	b _0803A69A
	.align 2, 0
_0803A690: .4byte gZeroRanges
_0803A694: .4byte 0x00000147
_0803A698:
	movs r0, #0
_0803A69A:
	pop {r4, r5}
	pop {r1}
	bx r1

