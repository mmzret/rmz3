	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08099f54
FUN_08099f54: @ 0x08099F54
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08099FB0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08099FA8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08099FB4 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
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
	movs r0, #6
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x68]
	str r7, [r3, #0x5c]
_08099FA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099FB0: .4byte gEnemyHeaderPtr
_08099FB4: .4byte gEnemyFnTable

	thumb_func_start FUN_08099fb8
FUN_08099fb8: @ 0x08099FB8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809A024 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0809A01E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A028 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
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
	strb r5, [r3, #0x10]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #0xc
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_0809A01E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A024: .4byte gEnemyHeaderPtr
_0809A028: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a02c
FUN_0809a02c: @ 0x0809A02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809A0A8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0809A0A0
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A0AC @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r4, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #4
	strb r0, [r4, #0x10]
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r4, #0x54]
	movs r1, #0x82
	lsls r1, r1, #0xb
	str r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	ldr r0, _0809A0B0 @ =0xFFFF6800
	adds r1, r1, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	lsls r0, r0, #0xc
	adds r1, r1, r0
	str r1, [r4, #0x54]
	strb r5, [r4, #0x12]
	str r6, [r4, #0x28]
_0809A0A0:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809A0A8: .4byte gEnemyHeaderPtr
_0809A0AC: .4byte gEnemyFnTable
_0809A0B0: .4byte 0xFFFF6800

