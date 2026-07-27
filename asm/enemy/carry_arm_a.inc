	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08071470
FUN_08071470: @ 0x08071470
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080714E0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _080714FA
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0
	mov ip, r0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080714E4 @ =gEnemyFnTable
	movs r0, #0x11
	strb r0, [r2, #9]
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r3, #0
	mov r1, ip
	strh r1, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r3, [r0]
	ldrb r1, [r2, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	strb r3, [r2, #0x10]
	strb r5, [r2, #0x11]
	str r6, [r2, #0x54]
	str r7, [r2, #0x58]
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080714E8
	mov r0, ip
	str r0, [r2, #0x2c]
	adds r1, r2, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	b _080714F2
	.align 2, 0
_080714E0: .4byte gEnemyHeaderPtr
_080714E4: .4byte gEnemyFnTable
_080714E8:
	str r4, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0xb8
	strb r3, [r0]
	str r2, [r4, #0x2c]
_080714F2:
	adds r0, r2, #0
	adds r0, #0xb4
	mov r1, r8
	str r1, [r0]
_080714FA:
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08071508
FUN_08071508: @ 0x08071508
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _08071560 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08071558
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08071564 @ =gEnemyFnTable
	movs r0, #0x11
	strb r0, [r3, #9]
	ldr r0, [r1, #0x44]
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
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb4
	str r6, [r0]
_08071558:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08071560: .4byte gEnemyHeaderPtr
_08071564: .4byte gEnemyFnTable
