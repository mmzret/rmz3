	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hirondelle_080da398
hirondelle_080da398: @ 0x080DA398
	push {lr}
	ldr r2, _080DA3BC @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA3D0
	ldr r0, _080DA3C0 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2b
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA3C8
	ldr r0, _080DA3C4 @ =0x00000272
	b _080DA416
	.align 2, 0
_080DA3BC: .4byte gCurStory
_080DA3C0: .4byte gStageDiskManager
_080DA3C4: .4byte 0x00000272
_080DA3C8:
	ldr r0, _080DA3CC @ =0x00000271
	b _080DA416
	.align 2, 0
_080DA3CC: .4byte 0x00000271
_080DA3D0:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA402
	ldrb r0, [r2, #0x13]
	cmp r0, #1
	bhi _080DA3EC
	movs r0, #2
	strb r0, [r2, #0x13]
	ldr r0, _080DA3E8 @ =0x0000026E
	b _080DA416
	.align 2, 0
_080DA3E8: .4byte 0x0000026E
_080DA3EC:
	cmp r0, #2
	bhi _080DA3FC
	movs r0, #3
	strb r0, [r2, #0x13]
	ldr r0, _080DA3F8 @ =0x0000026F
	b _080DA416
	.align 2, 0
_080DA3F8: .4byte 0x0000026F
_080DA3FC:
	movs r0, #0x9c
	lsls r0, r0, #2
	b _080DA416
_080DA402:
	ldrb r0, [r2, #0x13]
	cmp r0, #0
	beq _080DA410
	ldr r0, _080DA40C @ =0x0000026D
	b _080DA416
	.align 2, 0
_080DA40C: .4byte 0x0000026D
_080DA410:
	strb r3, [r2, #0x13]
	movs r0, #0x9b
	lsls r0, r0, #2
_080DA416:
	pop {r1}
	bx r1
	.align 2, 0
