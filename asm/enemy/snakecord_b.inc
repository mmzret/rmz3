	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Snakecord_Die
Snakecord_Die: @ 0x080745B0
	push {lr}
	adds r3, r0, #0
	ldr r0, _080745F8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08074600
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080745FC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _08074610
	.align 2, 0
_080745F8: .4byte gCurStory
_080745FC: .4byte gEnemyFnTable
_08074600:
	ldr r0, _08074614 @ =0x08366E90
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_08074610:
	pop {r0}
	bx r0
	.align 2, 0
_08074614: .4byte PTR_ARRAY_08366e90

