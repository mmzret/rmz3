	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start LemminglesNest_Die
LemminglesNest_Die: @ 0x0806E1DC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _0806E1F0
	cmp r0, #4
	beq _0806E1F0
	cmp r0, #5
	bne _0806E25A
_0806E1F0:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0806E274 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0806E278 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806E27C @ =0x0000270E
	cmp r1, r0
	bhi _0806E240
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806E240:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806E25A:
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E274: .4byte 0xFFFFF000
_0806E278: .4byte gScore
_0806E27C: .4byte 0x0000270E
_0806E280: .4byte gEnemyFnTable
