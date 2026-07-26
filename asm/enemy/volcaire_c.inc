	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807762c
FUN_0807762c: @ 0x0807762C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08077642
	bl isKilled
	cmp r0, #0
	beq _0807768A
_08077642:
	movs r0, #0
	str r0, [r5]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0807765C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077658 @ =0x083672D0
	bl SetDDP
	b _08077666
	.align 2, 0
_08077658: .4byte sCollisions+(1*24)
_0807765C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077680 @ =0x08367360
	bl SetDDP
_08077666:
	adds r0, r4, #0
	bl IsFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0807768A
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08077684
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0807768A
	.align 2, 0
_08077680: .4byte sCollisions+(7*24)
_08077684:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807768A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080776A8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080776A0
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080776A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080776A8: .4byte 0x00020001

	thumb_func_start FUN_080776ac
FUN_080776ac: @ 0x080776AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080776BC
	cmp r0, #1
	beq _080776FC
	b _080777BE
_080776BC:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _080776DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080776D8 @ =0x083672E8
	bl SetDDP
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080776F2
	.align 2, 0
_080776D8: .4byte sCollisions+(2*24)
_080776DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077750 @ =0x08367378
	bl SetDDP
	ldr r1, _08077754 @ =0x00002E05
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl GotoMotion
_080776F2:
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080776FC:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _080777B8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077716
	str r1, [r4, #0x60]
_08077716:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _080777B8
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	adds r6, r4, #0
	adds r6, #0xb9
	cmp r0, #0
	bne _08077758
	ldrb r0, [r6]
	cmp r0, #0
	bne _08077758
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	b _080777B8
	.align 2, 0
_08077750: .4byte sCollisions+(8*24)
_08077754: .4byte 0x00002E05
_08077758:
	ldr r0, _080777C4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _080777B4
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	bne _0807777E
	ldr r1, [r4, #0x28]
	cmp r1, #0
	beq _0807777E
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0807777E:
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
	ldr r1, _080777C8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080777B4:
	movs r0, #1
	strb r0, [r6]
_080777B8:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080777BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080777C4: .4byte gStageRun+232
_080777C8: .4byte gEnemyFnTable

	thumb_func_start FUN_080777cc
FUN_080777cc: @ 0x080777CC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080777EE
	cmp r0, #1
	bgt _080777E0
	cmp r0, #0
	beq _080777E6
	b _0807782C
_080777E0:
	cmp r0, #2
	beq _08077806
	b _0807782C
_080777E6:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080777EE:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080777F8
	movs r0, #0xc0
	b _080777FE
_080777F8:
	movs r0, #1
	strb r0, [r4, #0x13]
	movs r0, #0x28
_080777FE:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077806:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077826
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #3
	bhi _08077822
	adds r0, r4, #0
	bl FUN_08077174
_08077822:
	movs r0, #1
	strb r0, [r4, #0xe]
_08077826:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0807782C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08077834
FUN_08077834: @ 0x08077834
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08077870
	cmp r0, #1
	bgt _08077848
	cmp r0, #0
	beq _08077852
	b _08077902
_08077848:
	cmp r0, #2
	beq _08077898
	cmp r0, #3
	beq _080778A6
	b _08077902
_08077852:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077890 @ =0x083672D0
	bl SetDDP
	ldr r0, _08077894 @ =0xFFFFF800
	str r0, [r4, #0x60]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077870:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	cmp r1, #0
	ble _08077886
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077886:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08077902
	.align 2, 0
_08077890: .4byte sCollisions+(1*24)
_08077894: .4byte 0xFFFFF800
_08077898:
	ldr r1, _08077908 @ =0x00002E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080778A6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r5, [r0]
	cmp r5, #3
	bne _08077902
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r3, #0
	bl FUN_080771cc
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r3, #1
	bl FUN_080771cc
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
	ldr r1, _0807790C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077902:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077908: .4byte 0x00002E01
_0807790C: .4byte gEnemyFnTable

	thumb_func_start FUN_08077910
FUN_08077910: @ 0x08077910
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0807791E
	b _08077A2C
_0807791E:
	lsls r0, r0, #2
	ldr r1, _08077928 @ =_0807792C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077928: .4byte _0807792C
_0807792C: @ jump table
	.4byte _08077944 @ case 0
	.4byte _080779FE @ case 1
	.4byte _080779A8 @ case 2
	.4byte _080779FE @ case 3
	.4byte _08077A18 @ case 4
	.4byte _08077A2C @ case 5
_08077944:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08077968
	ldr r1, _08077960 @ =0x00002E02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08077964 @ =0x08367300
	bl SetDDP
	b _0807797A
	.align 2, 0
_08077960: .4byte 0x00002E02
_08077964: .4byte sCollisions+(3*24)
_08077968:
	ldr r1, _0807799C @ =0x00002E03
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080779A0 @ =0x08367330
	bl SetDDP
_0807797A:
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	lsls r1, r0, #0xf
	ldr r2, _080779A4 @ =0xFFFFC000
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _08077990
	adds r2, #0x1f
	adds r0, r1, r2
_08077990:
	asrs r0, r0, #5
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	b _080779F8
	.align 2, 0
_0807799C: .4byte 0x00002E03
_080779A0: .4byte sCollisions+(5*24)
_080779A4: .4byte 0xFFFFC000
_080779A8:
	movs r0, #8
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080779CC @ =0x08367360
	bl SetDDP
	ldr r1, _080779D0 @ =0x00002E04
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080779D4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080779DA
	.align 2, 0
_080779CC: .4byte sCollisions+(7*24)
_080779D0: .4byte 0x00002E04
_080779D4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080779DA:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
_080779F8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080779FE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08077A10
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077A10:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08077A2C
_08077A18:
	ldr r1, _08077A7C @ =0x00002E05
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08077A2C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08077A3C
	str r1, [r4, #0x60]
_08077A3C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0xb9
	cmp r6, #0
	bge _08077A84
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08077A80
	ldrb r1, [r5]
	cmp r1, #0
	bne _08077A80
	ldr r0, [r4, #0x58]
	adds r0, r0, r6
	str r0, [r4, #0x58]
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08077A84
	.align 2, 0
_08077A7C: .4byte 0x00002E05
_08077A80:
	movs r0, #1
	strb r0, [r5]
_08077A84:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08077A92
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08077110
_08077A92:
	ldr r0, _08077AF0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08077AE8
	cmp r7, #0
	beq _08077AB2
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08077AB2:
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
	ldr r1, _08077AF4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08077AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077AF0: .4byte gStageRun+232
_08077AF4: .4byte gEnemyFnTable

