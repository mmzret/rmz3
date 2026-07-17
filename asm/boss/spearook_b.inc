	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806228c
FUN_0806228c: @ 0x0806228C
	push {lr}
	adds r3, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080622FE
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _080622C0
	adds r2, r3, #0
	adds r2, #0xba
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	lsls r0, r0, #0xf
	b _080622D8
_080622C0:
	adds r2, r3, #0
	adds r2, #0xba
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	lsls r0, r0, #0xc
_080622D8:
	subs r1, r1, r0
	strh r1, [r2]
	adds r3, r2, #0
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080622F0 @ =0xFFFFC000
	cmp r1, r0
	bge _080622F4
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r3]
	b _080622FE
	.align 2, 0
_080622F0: .4byte 0xFFFFC000
_080622F4:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _080622FE
	strh r0, [r2]
_080622FE:
	pop {r0}
	bx r0
	.align 2, 0

