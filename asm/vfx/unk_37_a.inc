	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bc758
FUN_080bc758: @ 0x080BC758
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080BC79C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC796
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC7A0 @ =gVFXFnTable
	movs r1, #0x25
	strb r1, [r3, #9]
	adds r0, #0x94
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080BC796:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC79C: .4byte gVFXHeaderPtr
_080BC7A0: .4byte gVFXFnTable
