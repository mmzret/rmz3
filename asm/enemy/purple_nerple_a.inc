	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08075aa8
FUN_08075aa8: @ 0x08075AA8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r2, r0, #0
	cmp r2, #0
	beq _08075B12
	cmp r2, #0
	bge _08075AF0
	ldr r0, [r4, #0x54]
	adds r1, r0, #0
	subs r1, #0x80
	str r1, [r4, #0x54]
	ldr r1, _08075AEC @ =0xFFFFFD80
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	rsbs r1, r1, #0
	lsrs r6, r1, #0x1f
	b _08075B2C
	.align 2, 0
_08075AEC: .4byte 0xFFFFFD80
_08075AF0:
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x80
	str r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	b _08075B68
_08075B12:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08075B2C
	movs r6, #1
_08075B2C:
	cmp r6, #0
	bne _08075B68
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08075B6E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r3, [r4, #0x58]
	subs r2, r2, r3
	ldr r0, _08075B60 @ =0x000003FF
	adds r1, r2, r0
	ldr r0, _08075B64 @ =0x000007FE
	cmp r1, r0
	bhi _08075B6E
	adds r0, r3, r2
	b _08075B6C
	.align 2, 0
_08075B60: .4byte 0x000003FF
_08075B64: .4byte 0x000007FE
_08075B68:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
_08075B6C:
	str r0, [r4, #0x58]
_08075B6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08075b74
FUN_08075b74: @ 0x08075B74
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08075BC8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075BC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075BCC @ =gEnemyFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
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
	str r5, [r3, #0x28]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08075BC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08075BC8: .4byte gEnemyHeaderPtr
_08075BCC: .4byte gEnemyFnTable

	thumb_func_start FUN_08075bd0
FUN_08075bd0: @ 0x08075BD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r4, #0
	movs r6, #0
	ldr r7, _08075C38 @ =gEnemyFnTable
_08075BDE:
	ldr r0, _08075C3C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _08075C26
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x16
	strb r0, [r2, #9]
	ldr r0, [r7, #0x58]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #2
	strb r0, [r2, #0x10]
	strb r4, [r2, #0x11]
	ldr r0, [r5, #0x54]
	str r0, [r2, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r2, #0x58]
	adds r0, r2, #0
	adds r0, #0xb9
	strb r6, [r0]
_08075C26:
	adds r4, #1
	cmp r4, #1
	ble _08075BDE
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075C38: .4byte gEnemyFnTable
_08075C3C: .4byte gEnemyHeaderPtr

	thumb_func_start FUN_08075c40
FUN_08075c40: @ 0x08075C40
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08075CB8 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075CB0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075CBC @ =gEnemyFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
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
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r2, _08075CC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08075CC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08075CC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #0x11]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r1, [r0]
_08075CB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075CB8: .4byte gEnemyHeaderPtr
_08075CBC: .4byte gEnemyFnTable
_08075CC0: .4byte RNG_0202f388
_08075CC4: .4byte 0x000343FD
_08075CC8: .4byte 0x00269EC3

	thumb_func_start summonPurpleNerple
summonPurpleNerple: @ 0x08075CCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08075D2C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08075D26
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08075D30 @ =gEnemyFnTable
	movs r0, #0x16
	strb r0, [r3, #9]
	ldr r0, [r1, #0x58]
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
	movs r0, #3
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	ldr r0, _08075D34 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08075D38 @ =0xFFFF9000
	adds r0, r0, r1
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r4, #0x54]
	str r0, [r1]
_08075D26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08075D2C: .4byte gEnemyHeaderPtr
_08075D30: .4byte gEnemyFnTable
_08075D34: .4byte gStageRun+232
_08075D38: .4byte 0xFFFF9000

	thumb_func_start FUN_08075d3c
FUN_08075d3c: @ 0x08075D3C
	bx lr
  .align 2, 0

	thumb_func_start FUN_08075d40
FUN_08075d40: @ 0x08075D40
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08075DC0
	ldr r1, _08075D78 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r3, [r2, #0x10]
	cmp r3, #1
	beq _08075DA4
	cmp r3, #1
	bgt _08075D7C
	cmp r3, #0
	beq _08075D82
	b _08075DB6
	.align 2, 0
_08075D78: .4byte gEnemyFnTable
_08075D7C:
	cmp r3, #2
	beq _08075DB2
	b _08075DB6
_08075D82:
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _08075D92
	movs r0, #1
	b _08075DB4
_08075D92:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _08075DA0
	movs r0, #5
	b _08075DB4
_08075DA0:
	strb r3, [r2, #0xd]
	b _08075DB6
_08075DA4:
	ldr r0, [r2, #0x28]
	cmp r0, #0
	beq _08075DAE
	adds r0, #0xb8
	strb r3, [r0]
_08075DAE:
	strb r1, [r2, #0xd]
	b _08075DB6
_08075DB2:
	movs r0, #4
_08075DB4:
	strb r0, [r2, #0xd]
_08075DB6:
	adds r0, r2, #0
	bl PurpleNerple_Die
	movs r0, #1
	b _08075DC2
_08075DC0:
	movs r0, #0
_08075DC2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08075dc8
FUN_08075dc8: @ 0x08075DC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08075E82
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _08075E82
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08075DE8
	cmp r0, #1
	beq _08075E30
	b _08075E82
_08075DE8:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _08075E82
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08075E82
	ldr r1, _08075E28 @ =PTR_ARRAY_083670d0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08075E2C @ =PTR_ARRAY_083670f8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08075E24:
	movs r0, #1
	b _08075E84
	.align 2, 0
_08075E28: .4byte PTR_ARRAY_083670d0
_08075E2C: .4byte PTR_ARRAY_083670f8
_08075E30:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08075E3A
	cmp r0, #3
	bne _08075E58
_08075E3A:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08075E58
	adds r0, r4, #0
	bl FUN_08075aa8
	ldr r1, _08075E78 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
_08075E58:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08075E80
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08075E7C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08075E24
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08075E84
	.align 2, 0
_08075E78: .4byte 0x00002A04
_08075E7C: .4byte 0x00020001
_08075E80:
	strb r0, [r4, #0xf]
_08075E82:
	movs r0, #0
_08075E84:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08075e8c
FUN_08075e8c: @ 0x08075E8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08075ED4
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _08075ED4
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08075ED4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _08075EC0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08075ED4
_08075EC0:
	ldr r2, _08075EDC @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _08075ED4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08075ED4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075EDC: .4byte sElementCoord

	thumb_func_start PurpleNerple_Init
PurpleNerple_Init: @ 0x08075EE0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _08075EEE
	adds r0, #0xb9
	strb r1, [r0]
_08075EEE:
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bne _08075F00
	adds r2, r6, #0
	adds r2, #0xb9
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	strb r1, [r6, #0x10]
_08075F00:
	ldr r1, _08075F48 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08075F4C @ =sInitModes
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #1
	beq _08075FD4
	cmp r0, #1
	bgt _08075F50
	cmp r0, #0
	beq _08075F56
	b _08075FF4
	.align 2, 0
_08075F48: .4byte gEnemyFnTable
_08075F4C: .4byte sInitModes
_08075F50:
	cmp r0, #2
	beq _08075FD4
	b _08075FF4
_08075F56:
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_08075b74
	ldr r0, _08075F94 @ =gSystemSavedata
	ldrb r1, [r0, #0x13]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08075FA0
	ldr r0, _08075F98 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08075FA0
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08075F9C @ =0x08367138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	b _08075FB8
	.align 2, 0
_08075F94: .4byte gSystemSavedata
_08075F98: .4byte gCurStory
_08075F9C: .4byte sCollisions
_08075FA0:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08075FD0 @ =0x08367138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
_08075FB8:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0
	strb r0, [r1]
	adds r1, #8
	ldr r0, [r6, #0x54]
	str r0, [r1]
	b _08075FF4
	.align 2, 0
_08075FD0: .4byte sCollisions
_08075FD4:
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08076000 @ =0x08367138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08076004 @ =0x08075D3D
	str r0, [r4, #0x24]
_08075FF4:
	adds r0, r6, #0
	bl PurpleNerple_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08076000: .4byte sCollisions
_08076004: .4byte FUN_08075d3c

