	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	ldr r1, _080760C8 @ =PTR_ARRAY_083670d0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080760CC @ =PTR_ARRAY_083670f8
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
_080760C8: .4byte PTR_ARRAY_083670d0
_080760CC: .4byte PTR_ARRAY_083670f8

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
	ldr r0, _0807613C @ =PTR_ARRAY_08367120
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
_0807613C: .4byte PTR_ARRAY_08367120
