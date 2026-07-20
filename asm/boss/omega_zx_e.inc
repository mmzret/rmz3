	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08061648
FUN_08061648: @ 0x08061648
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r2, #0xa4
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #0x20
	bgt _0806167E
	movs r2, #0
	ldr r5, _08061670 @ =u16_ARRAY_080feffa
	adds r3, r5, #0
_0806165E:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08061674
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0806165E
	b _080616B0
	.align 2, 0
_08061670: .4byte u16_ARRAY_080feffa
_08061674:
	adds r0, r2, #1
	movs r1, #5
	bl __modsi3
	b _0806169A
_0806167E:
	movs r2, #0
	ldr r5, _080616A4 @ =u16_ARRAY_080feffa
	adds r3, r5, #0
_08061684:
	ldrh r1, [r3]
	cmp r1, r4
	bne _080616A8
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _08061694
	adds r0, r2, #4
_08061694:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
_0806169A:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _080616B0
	.align 2, 0
_080616A4: .4byte u16_ARRAY_080feffa
_080616A8:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _08061684
_080616B0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

