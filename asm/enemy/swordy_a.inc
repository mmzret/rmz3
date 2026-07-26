	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Swordy_Init
Swordy_Init: @ 0x0807BF04
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r5, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0807BFA0 @ =sCollisions
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	adds r0, #0x60
	str r5, [r0]
	subs r0, #4
	strb r5, [r0]
	adds r0, #8
	strb r6, [r0]
	ldr r1, _0807BFA4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r0, r7, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807BF94
	movs r1, #0xfc
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
_0807BF94:
	adds r0, r7, #0
	bl Swordy_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807BFA0: .4byte sCollisions
_0807BFA4: .4byte gEnemyFnTable

