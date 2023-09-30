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
	ldr r0, _08075BC8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_08075BC8: .4byte gZakoHeaderPtr
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
	ldr r0, _08075C3C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_08075C3C: .4byte gZakoHeaderPtr

	thumb_func_start FUN_08075c40
FUN_08075c40: @ 0x08075C40
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08075CB8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_08075CB8: .4byte gZakoHeaderPtr
_08075CBC: .4byte gEnemyFnTable
_08075CC0: .4byte RNG_0202f388
_08075CC4: .4byte 0x000343FD
_08075CC8: .4byte 0x00269EC3

	thumb_func_start summonPurpleNerple
summonPurpleNerple: @ 0x08075CCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08075D2C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
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
_08075D2C: .4byte gZakoHeaderPtr
_08075D30: .4byte gEnemyFnTable
_08075D34: .4byte gStageRun+232
_08075D38: .4byte 0xFFFF9000
_08075D3C:
	.byte 0x70, 0x47, 0x00, 0x00

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
	bl isFrozen
	cmp r0, #0
	beq _08075E82
	ldr r1, _08075E28 @ =0x083670D0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08075E2C @ =0x083670F8
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
	bl UpdateMotionGraphic
_08075E24:
	movs r0, #1
	b _08075E84
	.align 2, 0
_08075E28: .4byte 0x083670D0
_08075E2C: .4byte 0x083670F8
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
	bl UpdateMotionGraphic
_08075E58:
	adds r0, r4, #0
	bl isFrozen
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
	ldr r2, _08075EDC @ =0x083671E0
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
_08075EDC: .4byte 0x083671E0

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
	ldr r1, _08075F4C @ =0x083671E8
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
_08075F4C: .4byte 0x083671E8
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
	ldr r0, _08075F94 @ =gSystemSavedataManager
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
_08075F94: .4byte gSystemSavedataManager
_08075F98: .4byte gCurStory
_08075F9C: .4byte 0x08367138
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
_08075FD0: .4byte 0x08367138
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
_08076000: .4byte 0x08367138
_08076004: .4byte 0x08075D3D

	thumb_func_start PurpleNerple_Update
PurpleNerple_Update: @ 0x08076008
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0807606E
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r2, [r0]
	cmp r2, #0
	bne _08076068
	ldr r0, _08076060 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08076068
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _08076064 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080760C2
	.align 2, 0
_08076060: .4byte gCurStory
_08076064: .4byte gEnemyFnTable
_08076068:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08076084
_0807606E:
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076084
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08076084
	movs r0, #0
	str r0, [r4, #0x28]
_08076084:
	adds r0, r4, #0
	bl FUN_08075d40
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080760C2
	adds r0, r4, #0
	bl FUN_08075e8c
	adds r0, r4, #0
	bl FUN_08075dc8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080760C2
	ldr r1, _080760C8 @ =0x083670D0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080760CC @ =0x083670F8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080760C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080760C8: .4byte 0x083670D0
_080760CC: .4byte 0x083670F8

	thumb_func_start PurpleNerple_Die
PurpleNerple_Die: @ 0x080760D0
	push {lr}
	adds r2, r0, #0
	adds r0, #0xb9
	ldrb r3, [r0]
	cmp r3, #0
	bne _08076128
	ldr r0, _08076120 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08076128
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08076124 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _08076138
	.align 2, 0
_08076120: .4byte gCurStory
_08076124: .4byte gEnemyFnTable
_08076128:
	ldr r0, _0807613C @ =0x08367120
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_08076138:
	pop {r0}
	bx r0
	.align 2, 0
_0807613C: .4byte 0x08367120

	thumb_func_start FUN_08076140
FUN_08076140: @ 0x08076140
	bx lr
	.align 2, 0

	thumb_func_start FUN_08076144
FUN_08076144: @ 0x08076144
	push {lr}
	adds r2, r0, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076158
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08076158:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08076174 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807616E
	movs r1, #0
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807616E:
	pop {r0}
	bx r0
	.align 2, 0
_08076174: .4byte 0x00020001

	thumb_func_start FUN_08076178
FUN_08076178: @ 0x08076178
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08076194 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08076190
	movs r1, #0
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08076190:
	pop {r0}
	bx r0
	.align 2, 0
_08076194: .4byte 0x00020001

	thumb_func_start FUN_08076198
FUN_08076198: @ 0x08076198
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080761B4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080761B0
	movs r1, #0
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080761B0:
	pop {r0}
	bx r0
	.align 2, 0
_080761B4: .4byte 0x00020001

	thumb_func_start FUN_080761b8
FUN_080761b8: @ 0x080761B8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _080761CE
	bl isKilled
	cmp r0, #0
	beq _08076200
_080761CE:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080761F4 @ =0x08367150
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08076200
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080761F8
	movs r0, #4
	b _080761FA
	.align 2, 0
_080761F4: .4byte 0x08367150
_080761F8:
	movs r0, #2
_080761FA:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08076200:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0807621C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08076216
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08076216:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807621C: .4byte 0x00020001

	thumb_func_start FUN_08076220
FUN_08076220: @ 0x08076220
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08076230
	cmp r5, #1
	beq _0807626E
	b _080762D4
_08076230:
	str r5, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807624C
	ldr r1, _08076248 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	b _08076258
	.align 2, 0
_08076248: .4byte 0x00002A04
_0807624C:
	ldr r1, _080762DC @ =0x00002A02
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x12]
_08076258:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080762E0 @ =0x08367168
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807626E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076296
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08076290
	movs r0, #0
	strb r0, [r4, #0x12]
	ldr r1, _080762E4 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08076290:
	adds r0, r4, #0
	bl FUN_08075aa8
_08076296:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _080762D4
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080762B2
	str r1, [r4, #0x60]
_080762B2:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080762D4
	ldr r0, _080762E8 @ =0xFFFFF800
	cmp r1, r0
	ble _080762D4
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080762D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080762DC: .4byte 0x00002A02
_080762E0: .4byte 0x08367168
_080762E4: .4byte 0x00002A04
_080762E8: .4byte 0xFFFFF800

	thumb_func_start FUN_080762ec
FUN_080762ec: @ 0x080762EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08076368
	cmp r0, #1
	bgt _08076300
	cmp r0, #0
	beq _0807630A
	b _080763EC
_08076300:
	cmp r0, #2
	beq _080763C0
	cmp r0, #3
	beq _080763CC
	b _080763EC
_0807630A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08076330 @ =0x08367150
	bl SetDDP
	movs r2, #0
	ldr r0, _08076334 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08076324
	movs r2, #1
_08076324:
	cmp r2, #0
	beq _08076338
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807633E
	.align 2, 0
_08076330: .4byte 0x08367150
_08076334: .4byte pZero2
_08076338:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807633E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080763AC @ =0x00002A02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076368:
	ldr r1, _080763B0 @ =gStageRun+232
	ldr r0, [r1, #0x3c]
	ldr r2, _080763B4 @ =0xFFFF9000
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r3, [r4, #0x54]
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r0, r3, r2
	ldr r2, [r1, #0x38]
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	ble _08076392
	ldr r1, _080763B8 @ =0xFFFF8801
	adds r0, r3, r1
	subs r0, r0, r2
	ldr r1, _080763BC @ =0xFFFFE000
	cmp r0, r1
	blt _0807639C
_08076392:
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _080763A2
_0807639C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080763A2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080763EC
	.align 2, 0
_080763AC: .4byte 0x00002A02
_080763B0: .4byte gStageRun+232
_080763B4: .4byte 0xFFFF9000
_080763B8: .4byte 0xFFFF8801
_080763BC: .4byte 0xFFFFE000
_080763C0:
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080763CC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _080763F4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _080763EC
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080763EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080763F4: .4byte pZero2

	thumb_func_start FUN_080763f8
FUN_080763f8: @ 0x080763F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _08076408
	cmp r4, #1
	beq _0807643E
	b _080764F6
_08076408:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08076464 @ =0x08367150
	bl SetDDP
	ldr r1, _08076468 @ =0x00002A02
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _0807646C @ =0xFFFFFEC0
	str r0, [r6, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807642E
	movs r2, #0xa0
	lsls r2, r2, #1
_0807642E:
	str r2, [r6, #0x5c]
	str r4, [r6, #0x60]
	str r4, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807643E:
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r2, [r6, #0x54]
	ldr r0, [r0]
	subs r0, r2, r0
	movs r1, #0xb4
	lsls r1, r1, #9
	adds r0, r0, r1
	movs r1, #0xb4
	lsls r1, r1, #0xa
	cmp r0, r1
	bls _08076470
	ldr r1, [r6, #0x60]
	subs r1, #0x40
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _0807649E
	.align 2, 0
_08076464: .4byte 0x08367150
_08076468: .4byte 0x00002A02
_0807646C: .4byte 0xFFFFFEC0
_08076470:
	ldr r0, [r6, #0x64]
	adds r0, #1
	str r0, [r6, #0x64]
	ldr r1, [r6, #0x5c]
	adds r1, r2, r1
	str r1, [r6, #0x54]
	ldr r4, [r6, #0x68]
	str r4, [r6, #0x58]
	ldr r5, _080764FC @ =gSineTable
	lsls r0, r0, #8
	movs r1, #0x4c
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x58]
_0807649E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _080764F6
	ldr r0, _08076500 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _080764F6
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08076504 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080764F6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080764FC: .4byte gSineTable
_08076500: .4byte gStageRun+232
_08076504: .4byte gEnemyFnTable

	thumb_func_start FUN_08076508
FUN_08076508: @ 0x08076508
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807651A
	cmp r0, #1
	beq _08076532
	b _0807653A
_0807651A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807654C @ =0x08367180
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076532:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_0807653A:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08076550
	movs r5, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0807658A
	.align 2, 0
_0807654C: .4byte 0x08367180
_08076550:
	cmp r0, #4
	bne _0807658A
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
	ldr r1, _08076590 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0807658A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08076590: .4byte gEnemyFnTable

	thumb_func_start FUN_08076594
FUN_08076594: @ 0x08076594
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080765A4
	cmp r0, #1
	beq _080765BE
	b _0807662E
_080765A4:
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080765FC @ =0x08367150
	bl SetDDP
	ldr r1, _08076600 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080765BE:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080765CE
	str r1, [r4, #0x60]
_080765CE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08076628
	ldr r0, _08076604 @ =0xFFFFF800
	cmp r1, r0
	ble _08076612
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076608
	movs r0, #9
	b _0807660A
	.align 2, 0
_080765FC: .4byte 0x08367150
_08076600: .4byte 0x00002A04
_08076604: .4byte 0xFFFFF800
_08076608:
	movs r0, #6
_0807660A:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _08076628
_08076612:
	ldr r1, _08076634 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
_08076628:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807662E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08076634: .4byte gEnemyFnTable

	thumb_func_start FUN_08076638
FUN_08076638: @ 0x08076638
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08076676
	cmp r5, #1
	bgt _0807664C
	cmp r5, #0
	beq _08076656
	b _080766D8
_0807664C:
	cmp r5, #2
	beq _08076698
	cmp r5, #3
	beq _080766AA
	b _080766D8
_08076656:
	str r5, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08076690 @ =0x08367150
	bl SetDDP
	ldr r1, _08076694 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x64
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076676:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076688
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076688:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080766D8
	.align 2, 0
_08076690: .4byte 0x08367150
_08076694: .4byte 0x00002A04
_08076698:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldr r1, _08076704 @ =0x00002A05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080766AA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080766D2
	ldr r1, _08076708 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #3
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_08075bd0
_080766D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080766D8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _08076724
	cmp r1, #0
	bge _08076710
	ldr r0, [r4, #0x54]
	adds r1, r0, #0
	subs r1, #0x80
	str r1, [r4, #0x54]
	ldr r1, _0807670C @ =0xFFFFFD80
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	b _0807672E
	.align 2, 0
_08076704: .4byte 0x00002A05
_08076708: .4byte gEnemyFnTable
_0807670C: .4byte 0xFFFFFD80
_08076710:
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x80
	str r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	b _0807672E
_08076724:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
_0807672E:
	bl GetMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq _08076740
	movs r0, #1
	strb r0, [r4, #0x13]
_08076740:
	ldrb r5, [r4, #0x13]
	cmp r5, #0
	bne _08076774
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08076756
	str r1, [r4, #0x60]
_08076756:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0807677A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
	b _0807677A
_08076774:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
	str r0, [r4, #0x58]
_0807677A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08076780
FUN_08076780: @ 0x08076780
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _08076790
	cmp r2, #1
	beq _080767B2
	b _08076816
_08076790:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	str r2, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807681C @ =0x08367180
	bl SetDDP
	ldr r1, _08076820 @ =0x00002A03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080767B2:
	ldr r0, [r4, #0x60]
	subs r0, #0x20
	str r0, [r4, #0x60]
	ldr r1, _08076824 @ =0xFFFFF900
	cmp r0, r1
	bge _080767C0
	str r1, [r4, #0x60]
_080767C0:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _08076828 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _08076816
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
	ldr r1, _0807682C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08076816:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807681C: .4byte 0x08367180
_08076820: .4byte 0x00002A03
_08076824: .4byte 0xFFFFF900
_08076828: .4byte gStageRun+232
_0807682C: .4byte gEnemyFnTable

	thumb_func_start FUN_08076830
FUN_08076830: @ 0x08076830
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08076840
	cmp r0, #1
	beq _0807687A
	b _080768C2
_08076840:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080768C8 @ =0x08367198
	bl SetDDP
	ldrb r0, [r4, #0x11]
	ldr r1, _080768CC @ =0x00002A07
	cmp r0, #0
	bne _08076854
	subs r1, #1
_08076854:
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	bne _08076874
	ldrb r1, [r4, #0x11]
	ldr r0, _080768D0 @ =0x00000266
	muls r0, r1, r0
	ldr r1, _080768D4 @ =0xFFFFFECD
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _080768D8 @ =0xFFFFFB20
	str r0, [r4, #0x60]
_08076874:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807687A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08076892
	str r1, [r4, #0x60]
_08076892:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080768BC
	ldr r1, _080768DC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #4
	strb r0, [r4, #0xd]
_080768BC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080768C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080768C8: .4byte 0x08367198
_080768CC: .4byte 0x00002A07
_080768D0: .4byte 0x00000266
_080768D4: .4byte 0xFFFFFECD
_080768D8: .4byte 0xFFFFFB20
_080768DC: .4byte gEnemyFnTable

	thumb_func_start FUN_080768e0
FUN_080768e0: @ 0x080768E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080768F0
	cmp r0, #1
	beq _0807699A
	b _08076A48
_080768F0:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08076910 @ =0x083671C8
	bl SetDDP
	adds r0, r6, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076918
	ldr r1, _08076914 @ =0x00002A04
	adds r0, r6, #0
	bl SetMotion
	b _08076920
	.align 2, 0
_08076910: .4byte 0x083671C8
_08076914: .4byte 0x00002A04
_08076918:
	ldr r1, _08076980 @ =0x00002A02
	adds r0, r6, #0
	bl SetMotion
_08076920:
	ldr r0, _08076984 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r3, _08076988 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r6, #0x60]
	asrs r1, r1, #8
	adds r5, r1, #0
	muls r5, r1, r5
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r5, r5, r0
	adds r0, r5, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #8
	cmp r5, #0
	beq _0807698C
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r6, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r6, #0x60]
	b _08076994
	.align 2, 0
_08076980: .4byte 0x00002A02
_08076984: .4byte pZero2
_08076988: .4byte 0xFFFFE800
_0807698C:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
_08076994:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807699A:
	adds r0, r6, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080769B4
	ldr r1, _080769B0 @ =0x00002A04
	adds r0, r6, #0
	bl SetMotion
	b _080769BC
	.align 2, 0
_080769B0: .4byte 0x00002A04
_080769B4:
	ldr r1, _080769E4 @ =0x00002A02
	adds r0, r6, #0
	bl SetMotion
_080769BC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #0
	bge _080769E8
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	ble _080769FC
	ldr r0, [r6, #0x54]
	adds r0, r0, r5
	str r0, [r6, #0x54]
	b _08076A0A
	.align 2, 0
_080769E4: .4byte 0x00002A02
_080769E8:
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	bge _080769FC
	ldr r0, [r6, #0x54]
	adds r0, r0, r5
	str r0, [r6, #0x54]
	b _08076A0A
_080769FC:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08076A12
_08076A0A:
	adds r0, r6, #0
	bl FUN_08076b30
	b _08076A48
_08076A12:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08076A22
	str r1, [r6, #0x60]
_08076A22:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r2, r0, r1
	str r2, [r6, #0x58]
	cmp r1, #0
	ble _08076A48
	ldr r0, [r6, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08076A48
	ldr r0, [r6, #0x58]
	adds r0, r0, r5
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl FUN_08076b30
_08076A48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08076a50
FUN_08076a50: @ 0x08076A50
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08076A88
	cmp r0, #1
	bgt _08076A66
	cmp r0, #0
	beq _08076A70
	b _08076B24
_08076A66:
	cmp r0, #2
	beq _08076ABC
	cmp r0, #3
	beq _08076AC6
	b _08076B24
_08076A70:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08076AB0 @ =0x08367150
	bl SetDDP
	ldr r1, _08076AB4 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076A88:
	ldr r0, [r4, #0x54]
	adds r0, #0x80
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _08076AB8 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	ble _08076B24
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08076B24
	.align 2, 0
_08076AB0: .4byte 0x08367150
_08076AB4: .4byte 0x00002A04
_08076AB8: .4byte 0xFFFFF000
_08076ABC:
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08076AC6:
	ldr r0, [r4, #0x54]
	adds r0, #0x80
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, #0x80
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08076B1E
	cmp r1, #0
	beq _08076AEA
	adds r1, #0xba
	movs r0, #1
	strb r0, [r1]
_08076AEA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _08076B2C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08076B1E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08076B24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08076B2C: .4byte gEnemyFnTable

	thumb_func_start FUN_08076b30
FUN_08076b30: @ 0x08076B30
	push {r4, r5, lr}
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
	ldr r1, _08076B84 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076B8C
	ldr r2, _08076B88 @ =0x083671EC
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
	b _08076B98
	.align 2, 0
_08076B84: .4byte 0xFFFFF000
_08076B88: .4byte 0x083671EC
_08076B8C:
	ldr r2, _08076BD4 @ =0x083671EC
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
_08076B98:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08076BD8 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08076BDC @ =0x0000270E
	cmp r1, r0
	bhi _08076BB2
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08076BB2:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08076BE0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08076BD4: .4byte 0x083671EC
_08076BD8: .4byte gMission
_08076BDC: .4byte 0x0000270E
_08076BE0: .4byte gEnemyFnTable

	thumb_func_start FUN_08076be4
FUN_08076be4: @ 0x08076BE4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08076BF6
	cmp r0, #1
	beq _08076CDC
	b _08076D22
_08076BF6:
	movs r3, #0
	ldr r0, _08076C18 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08076C08
	movs r3, #1
_08076C08:
	adds r6, r3, #0
	adds r2, r6, #0
	cmp r6, #0
	beq _08076C1C
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08076C22
	.align 2, 0
_08076C18: .4byte pZero2
_08076C1C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08076C22:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r6, #8
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _08076CB0 @ =0x00002A0C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	asrs r0, r0, #1
	str r0, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076CB8
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _08076CB4 @ =0x083671F2
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b857c
	b _08076CCE
	.align 2, 0
_08076CB0: .4byte 0x00002A0C
_08076CB4: .4byte 0x083671F2
_08076CB8:
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _08076D2C @ =0x083671F2
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b84f4
_08076CCE:
	movs r1, #0
	movs r0, #0x18
	strb r0, [r5, #0x12]
	str r1, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08076CDC:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08076CEC
	str r1, [r5, #0x60]
_08076CEC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08076D1C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08076D22
_08076D1C:
	adds r0, r5, #0
	bl FUN_08076b30
_08076D22:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08076D2C: .4byte 0x083671F2

	thumb_func_start FUN_08076d30
FUN_08076d30: @ 0x08076D30
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
	ldr r1, _08076D90 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08076D94 @ =0x083671F4
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _08076D98 @ =gEnemyFnTable
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
_08076D90: .4byte 0xFFFFF000
_08076D94: .4byte 0x083671F4
_08076D98: .4byte gEnemyFnTable

	thumb_func_start FUN_08076d9c
FUN_08076d9c: @ 0x08076D9C
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
	ldr r1, _08076DF0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08076DF4 @ =gEnemyFnTable
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
_08076DF0: .4byte 0xFFFFF800
_08076DF4: .4byte gEnemyFnTable

	thumb_func_start FUN_08076df8
FUN_08076df8: @ 0x08076DF8
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
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08076E50 @ =0x083671FA
	adds r0, r4, #0
	mov r1, sp
	movs r3, #2
	bl FUN_080b7f70
	ldr r1, _08076E54 @ =gEnemyFnTable
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
_08076E50: .4byte 0x083671FA
_08076E54: .4byte gEnemyFnTable
