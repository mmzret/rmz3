	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Cubit_Init
Cubit_Init: @ 0x0805260C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r7, #0
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080526FC @ =sCollisions
	adds r0, r6, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _08052700 @ =FUN_08054530
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	strb r7, [r0]
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc0
	str r7, [r0]
	subs r0, #9
	strb r7, [r0]
	adds r0, #0x11
	strb r7, [r0]
	adds r0, #4
	str r7, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, _08052704 @ =0xFFFFC000
	adds r1, r1, r0
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r4, r0, #0
	str r4, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r2, _08052708 @ =0xFFFF8400
	adds r0, r4, r2
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, _0805270C @ =0xFFFF8C00
	adds r4, r4, r1
	adds r1, r4, #0
	bl FUN_0800a22c
	adds r5, r0, #0
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a31c
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0xbc
	str r4, [r0]
	subs r5, r5, r4
	adds r0, r5, #0
	movs r1, #3
	bl __divsi3
	adds r2, r6, #0
	adds r2, #0xd4
	asrs r1, r0, #1
	adds r4, r4, r1
	str r4, [r2]
	adds r2, #4
	adds r1, r4, r0
	str r1, [r2]
	adds r2, #4
	lsls r1, r0, #1
	adds r4, r4, r1
	str r4, [r2]
	adds r1, r6, #0
	adds r1, #0xe0
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xca
	strb r7, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08052714
	ldr r1, _08052710 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	b _0805272A
	.align 2, 0
_080526FC: .4byte sCollisions
_08052700: .4byte FUN_08054530
_08052704: .4byte 0xFFFFC000
_08052708: .4byte 0xFFFF8400
_0805270C: .4byte 0xFFFF8C00
_08052710: .4byte gBossFnTable
_08052714:
	ldr r1, _08052740 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
_0805272A:
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	movs r0, #0
	strb r0, [r6, #0x11]
	adds r0, r6, #0
	bl Cubit_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052740: .4byte gBossFnTable

