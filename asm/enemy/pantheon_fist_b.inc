	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08095014
FUN_08095014: @ 0x08095014
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _0809506A
	cmp r5, #0
	bge _08095044
	ldr r0, [r4, #0x54]
	ldr r1, _0809503C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095040 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #1
	b _0809506C
	.align 2, 0
_0809503C: .4byte 0xFFFFF200
_08095040: .4byte 0xFFFFF600
_08095044:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095060 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #2
	b _0809506C
	.align 2, 0
_08095060: .4byte 0xFFFFF600
_08095064:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809506A:
	movs r0, #0
_0809506C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

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

