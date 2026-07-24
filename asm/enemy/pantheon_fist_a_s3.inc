	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08095074
FUN_08095074: @ 0x08095074
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	beq _080950C4
	cmp r1, #0
	bge _080950A4
	ldr r0, [r2, #0x54]
	ldr r1, _0809509C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950A0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #1
	b _080950C6
	.align 2, 0
_0809509C: .4byte 0xFFFFF200
_080950A0: .4byte 0xFFFFF600
_080950A4:
	ldr r0, [r2, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950C0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #2
	b _080950C6
	.align 2, 0
_080950C0: .4byte 0xFFFFF600
_080950C4:
	movs r0, #0
_080950C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080950cc
nop_080950cc: @ 0x080950CC
	bx lr
	.align 2, 0

