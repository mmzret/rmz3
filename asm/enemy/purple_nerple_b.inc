	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PurpleNerple_Die
PurpleNerple_Die: @ 0x080760D0
	push {lr}
	adds r2, r0, #0
	adds r0, #0xb9
	ldrb r3, [r0]
	cmp r3, #0
	bne _08076128
	ldr r0, _08076120 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08076128
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08076124 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _08076138
	.align 2, 0
_08076120: .4byte gCurStory
_08076124: .4byte gEnemyFnTable
_08076128:
	ldr r0, _0807613C @ =PTR_ARRAY_08367120
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_08076138:
	pop {r0}
	bx r0
	.align 2, 0
_0807613C: .4byte PTR_ARRAY_08367120

