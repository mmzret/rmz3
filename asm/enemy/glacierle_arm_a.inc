	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createGlacierleAtkHand
createGlacierleAtkHand: @ 0x08082194
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _08082210 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r7, r0, #0
	cmp r7, #0
	beq _08082204
	adds r1, r7, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08082214 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r7, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r7, #0x14]
	movs r6, #0
	strh r5, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r7, #0xb]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r7, #0xb]
	ldrb r0, [r7, #0x1c]
	strb r0, [r7, #0x1d]
	strb r6, [r7, #0x10]
	adds r0, r7, #0
	bl InitRotatableMotion
	str r5, [r7, #0x2c]
	mov r0, r8
	str r0, [r7, #0x28]
	str r5, [r7, #0x5c]
	str r5, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb4
	strb r6, [r0]
	ldrb r0, [r7, #0xb]
	orrs r4, r0
	strb r4, [r7, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r7, #0x1d]
_08082204:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08082210: .4byte gEnemyHeaderPtr
_08082214: .4byte gEnemyFnTable
