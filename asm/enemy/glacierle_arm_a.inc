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

	thumb_func_start createGlacierleJoint
createGlacierleJoint: @ 0x08082218
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _080822A4 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080822D8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080822A8 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r7, #0x2c]
	str r0, [r3, #0x2c]
	str r7, [r3, #0x28]
	ldr r2, [r7, #0x2c]
	cmp r2, #0
	beq _080822AC
	str r3, [r2, #0x28]
	ldr r0, [r2, #0x5c]
	str r0, [r3, #0x5c]
	ldr r0, [r2, #0x60]
	str r0, [r3, #0x60]
	ldr r5, [r2, #0x54]
	str r5, [r3, #0x54]
	ldr r6, [r2, #0x58]
	str r6, [r3, #0x58]
	ldr r4, [r2, #0x2c]
	cmp r4, #0
	beq _0808229A
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	adds r0, r5, r0
	str r0, [r3, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	adds r0, r6, r0
	str r0, [r3, #0x58]
_0808229A:
	ldr r0, [r3, #0x54]
	str r0, [r3, #0x64]
	ldr r0, [r3, #0x58]
	str r0, [r3, #0x68]
	b _080822B0
	.align 2, 0
_080822A4: .4byte gEnemyHeaderPtr
_080822A8: .4byte gEnemyFnTable
_080822AC:
	str r2, [r3, #0x5c]
	str r2, [r3, #0x60]
_080822B0:
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r3, #0x1d]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	str r3, [r7, #0x2c]
	adds r1, r7, #0
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r2, r3, #0
	adds r2, #0xb6
	strb r0, [r2]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080822D8:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start createGlacierleSucker
createGlacierleSucker: @ 0x080822E4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08082340 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08082336
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08082344 @ =gEnemyFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r2, [r3, #0xb]
	movs r1, #0x10
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x2c]
	orrs r1, r2
	strb r1, [r3, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r3, #0x1d]
	adds r0, r3, #0
	adds r0, #0xbc
	str r4, [r0]
_08082336:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08082340: .4byte gEnemyHeaderPtr
_08082344: .4byte gEnemyFnTable

	thumb_func_start FUN_08082348
FUN_08082348: @ 0x08082348
	push {lr}
	adds r1, r0, #0
	ldr r3, [r1, #0x2c]
	cmp r3, #0
	beq _0808239C
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _0808235A
	str r1, [r0, #0x28]
_0808235A:
	ldr r0, [r3, #0x2c]
	str r0, [r1, #0x2c]
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080823A0 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_0808239C:
	pop {r0}
	bx r0
	.align 2, 0
_080823A0: .4byte gEnemyFnTable
