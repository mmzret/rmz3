	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonFist_Die
PantheonFist_Die: @ 0x08095340
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08095394
	ldr r0, _0809538C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08095394
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
	ldr r1, _08095390 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080953A4
	.align 2, 0
_0809538C: .4byte gCurStory
_08095390: .4byte gEnemyFnTable
_08095394:
	ldr r0, _080953A8 @ =0x08369FC8
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080953A4:
	pop {r0}
	bx r0
	.align 2, 0
_080953A8: .4byte 0x08369FC8

