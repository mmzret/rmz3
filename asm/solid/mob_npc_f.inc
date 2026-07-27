	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start pic_080da494
pic_080da494: @ 0x080DA494
	push {lr}
	ldr r2, _080DA4B4 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA4C2
	ldrb r0, [r2, #0x14]
	cmp r0, #2
	bhi _080DA4BC
	movs r0, #3
	strb r0, [r2, #0x14]
	ldr r0, _080DA4B8 @ =0x00000277
	b _080DA4F8
	.align 2, 0
_080DA4B4: .4byte gCurStory
_080DA4B8: .4byte 0x00000277
_080DA4BC:
	movs r0, #0x9e
	lsls r0, r0, #2
	b _080DA4F8
_080DA4C2:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA4E8
	ldrb r0, [r2, #0x14]
	cmp r0, #1
	bhi _080DA4E0
	movs r0, #2
	strb r0, [r2, #0x14]
	ldr r0, _080DA4DC @ =0x00000275
	b _080DA4F8
	.align 2, 0
_080DA4DC: .4byte 0x00000275
_080DA4E0:
	ldr r0, _080DA4E4 @ =0x00000276
	b _080DA4F8
	.align 2, 0
_080DA4E4: .4byte 0x00000276
_080DA4E8:
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	beq _080DA4F4
	movs r0, #0x9d
	lsls r0, r0, #2
	b _080DA4F8
_080DA4F4:
	strb r3, [r2, #0x14]
	ldr r0, _080DA4FC @ =0x00000273
_080DA4F8:
	pop {r1}
	bx r1
	.align 2, 0
_080DA4FC: .4byte 0x00000273
