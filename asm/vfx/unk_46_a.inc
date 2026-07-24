	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bedc0
FUN_080bedc0: @ 0x080BEDC0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080BEE1C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BEE14
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BEE20 @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x7c
	strb r6, [r0]
	movs r0, #3
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080BEE14:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BEE1C: .4byte gVFXHeaderPtr
_080BEE20: .4byte gVFXFnTable
