	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start perroquiet_080da57c
perroquiet_080da57c: @ 0x080DA57C
	push {lr}
	ldr r2, _080DA59C @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA5AC
	ldrb r0, [r2, #0x15]
	cmp r0, #2
	bhi _080DA5A4
	movs r0, #3
	strb r0, [r2, #0x15]
	ldr r0, _080DA5A0 @ =0x0000027D
	b _080DA5E0
	.align 2, 0
_080DA59C: .4byte gCurStory
_080DA5A0: .4byte 0x0000027D
_080DA5A4:
	ldr r0, _080DA5A8 @ =0x0000027E
	b _080DA5E0
	.align 2, 0
_080DA5A8: .4byte 0x0000027E
_080DA5AC:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA5CE
	ldrb r0, [r2, #0x15]
	cmp r0, #1
	bhi _080DA5C8
	movs r0, #2
	strb r0, [r2, #0x15]
	ldr r0, _080DA5C4 @ =0x0000027B
	b _080DA5E0
	.align 2, 0
_080DA5C4: .4byte 0x0000027B
_080DA5C8:
	movs r0, #0x9f
	lsls r0, r0, #2
	b _080DA5E0
_080DA5CE:
	ldrb r0, [r2, #0x15]
	cmp r0, #0
	beq _080DA5DC
	ldr r0, _080DA5D8 @ =0x0000027A
	b _080DA5E0
	.align 2, 0
_080DA5D8: .4byte 0x0000027A
_080DA5DC:
	strb r3, [r2, #0x15]
	ldr r0, _080DA5E4 @ =0x00000279
_080DA5E0:
	pop {r1}
	bx r1
	.align 2, 0
_080DA5E4: .4byte 0x00000279
