	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Beetank_Init
Beetank_Init: @ 0x0807B8BC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B924 @ =0xFFFFF400
	adds r1, r1, r4
	bl PushoutToLeft1
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	ldr r2, _0807B928 @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl PushoutToRight1
	str r0, [sp, #4]
	cmp r5, #0
	beq _0807B92C
	cmp r0, #0
	bne _0807B938
	ldr r0, [r6, #0x54]
	ldr r1, [sp]
	adds r0, r0, r1
	b _0807B936
	.align 2, 0
_0807B924: .4byte 0xFFFFF400
_0807B928: .4byte 0xFFFFF000
_0807B92C:
	cmp r0, #0
	beq _0807B938
	ldr r0, [r6, #0x54]
	ldr r2, [sp, #4]
	adds r0, r0, r2
_0807B936:
	str r0, [r6, #0x54]
_0807B938:
	ldr r0, [r6, #0x54]
	ldr r1, _0807B968 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r4, _0807B96C @ =0xFFFFFA00
	adds r1, r1, r4
	bl FUN_08009f6c
	adds r5, r0, #0
	str r5, [sp]
	ldr r0, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	str r0, [sp, #4]
	ldr r1, [sp]
	cmp r1, r0
	bge _0807B970
	str r5, [r6, #0x58]
	b _0807B972
	.align 2, 0
_0807B968: .4byte 0xFFFFF000
_0807B96C: .4byte 0xFFFFFA00
_0807B970:
	str r0, [r6, #0x58]
_0807B972:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807B9E4 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _0807B9E8 @ =nop_0807bea4
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r6, #0x5c]
	adds r0, #0x60
	str r5, [r0]
	subs r0, #4
	strb r5, [r0]
	ldr r1, _0807B9EC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807B9D6
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_0807B9D6:
	adds r0, r6, #0
	bl Beetank_Update
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807B9E4: .4byte sCollisions
_0807B9E8: .4byte nop_0807bea4
_0807B9EC: .4byte gEnemyFnTable

