	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807aae8
FUN_0807aae8: @ 0x0807AAE8
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0xc]
	ldr r5, [r0, #0x2c]
	ldr r3, [r2, #0x2c]
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807AB10
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0807AB0A
	movs r4, #1
_0807AB0A:
	adds r0, r3, #0
	adds r0, #0xb4
	strb r4, [r0]
_0807AB10:
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807AB2A
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0807AB2A
	movs r0, #0xff
	strb r0, [r3, #0x12]
_0807AB2A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807ab30
FUN_0807ab30: @ 0x0807AB30
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807AB46
	movs r0, #0
	b _0807AB60
_0807AB46:
	ldr r1, _0807AB64 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl HeavyCannon_Die
	movs r0, #1
_0807AB60:
	pop {r1}
	bx r1
	.align 2, 0
_0807AB64: .4byte gEnemyFnTable

	thumb_func_start HeavyCannon_Init
HeavyCannon_Init: @ 0x0807AB68
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807ABD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807ABD4 @ =0x083677CC
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0807ABD8 @ =sCollisions
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0xa
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807ABDC @ =FUN_0807aae8
	str r0, [r5, #0x24]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r4, #0
	bl HeavyCannon_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807ABD0: .4byte gEnemyFnTable
_0807ABD4: .4byte sInitModes
_0807ABD8: .4byte sCollisions
_0807ABDC: .4byte FUN_0807aae8

	thumb_func_start HeavyCannon_Update
HeavyCannon_Update: @ 0x0807ABE0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0807AC28 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807AC30
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807AC2C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0807AC5C
	.align 2, 0
_0807AC28: .4byte gCurStory
_0807AC2C: .4byte gEnemyFnTable
_0807AC30:
	adds r0, r4, #0
	bl FUN_0807ab30
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807AC5C
	ldr r1, _0807AC64 @ =0x08367774
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807AC68 @ =0x0836777C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807AC5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AC64: .4byte PTR_ARRAY_08367774
_0807AC68: .4byte PTR_ARRAY_0836777c

	thumb_func_start HeavyCannon_Die
HeavyCannon_Die: @ 0x0807AC6C
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
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
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0807ACC8 @ =0x083677CE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _0807ACCC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807ACC8: .4byte sMotions
_0807ACCC: .4byte gEnemyFnTable
