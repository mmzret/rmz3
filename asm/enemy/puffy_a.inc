	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Puffy_Init
Puffy_Init: @ 0x0807C5E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r6, #0
	movs r1, #0xef
	ands r0, r1
	movs r7, #0
	strb r0, [r5, #0xa]
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807C680 @ =sCollisions
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0807C684 @ =FUN_0807cba4
	str r0, [r4, #0x24]
	ldr r0, _0807C688 @ =gOverworld
	ldr r1, _0807C68C @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r5, #0x58]
	cmp r0, r1
	ble _0807C694
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807C690 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _0807C6E8
	.align 2, 0
_0807C680: .4byte sCollisions
_0807C684: .4byte FUN_0807cba4
_0807C688: .4byte gOverworld
_0807C68C: .4byte 0x0002C00C
_0807C690: .4byte gEnemyFnTable
_0807C694:
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r5, #0x68]
	str r1, [r0]
	subs r0, #0x58
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	adds r0, #0x60
	str r6, [r0]
	subs r0, #4
	strb r6, [r0]
	adds r0, #8
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0807C6F4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r6, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807C6E2
	movs r1, #0x82
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
_0807C6E2:
	adds r0, r5, #0
	bl Puffy_Update
_0807C6E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C6F4: .4byte gEnemyFnTable
