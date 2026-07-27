	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start doigt_080da660
doigt_080da660: @ 0x080DA660
	push {lr}
	ldr r2, _080DA680 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA6B2
	ldrb r0, [r2, #0x16]
	cmp r0, #2
	bhi _080DA688
	movs r0, #3
	strb r0, [r2, #0x16]
	ldr r0, _080DA684 @ =0x00000283
	b _080DA6E8
	.align 2, 0
_080DA680: .4byte gCurStory
_080DA684: .4byte 0x00000283
_080DA688:
	ldr r0, _080DA6A4 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA6AC
	ldr r0, _080DA6A8 @ =0x00000285
	b _080DA6E8
	.align 2, 0
_080DA6A4: .4byte gStageDiskManager
_080DA6A8: .4byte 0x00000285
_080DA6AC:
	movs r0, #0xa1
	lsls r0, r0, #2
	b _080DA6E8
_080DA6B2:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA6D8
	ldrb r0, [r2, #0x16]
	cmp r0, #1
	bhi _080DA6D0
	movs r0, #2
	strb r0, [r2, #0x16]
	ldr r0, _080DA6CC @ =0x00000281
	b _080DA6E8
	.align 2, 0
_080DA6CC: .4byte 0x00000281
_080DA6D0:
	ldr r0, _080DA6D4 @ =0x00000282
	b _080DA6E8
	.align 2, 0
_080DA6D4: .4byte 0x00000282
_080DA6D8:
	ldrb r0, [r2, #0x16]
	cmp r0, #0
	beq _080DA6E4
	movs r0, #0xa0
	lsls r0, r0, #2
	b _080DA6E8
_080DA6E4:
	strb r3, [r2, #0x16]
	ldr r0, _080DA6EC @ =0x0000027F
_080DA6E8:
	pop {r1}
	bx r1
	.align 2, 0
_080DA6EC: .4byte 0x0000027F
