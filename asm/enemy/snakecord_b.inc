	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08074d90
FUN_08074d90: @ 0x08074D90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08074DE2
	cmp r0, #1
	bgt _08074DA4
	cmp r0, #0
	beq _08074DAE
	b _08074E82
_08074DA4:
	cmp r0, #2
	beq _08074E24
	cmp r0, #3
	beq _08074E36
	b _08074E82
_08074DAE:
	ldr r0, _08074E1C @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08074DC2
	movs r2, #0x80
	lsls r2, r2, #2
_08074DC2:
	str r2, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xa
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _08074E20 @ =0x00002807
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074DE2:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074DFA
	str r1, [r4, #0x60]
_08074DFA:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _08074E82
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08074E82
	.align 2, 0
_08074E1C: .4byte 0xFFFFFE00
_08074E20: .4byte 0x00002807
_08074E24:
	movs r0, #0
	strb r0, [r4, #0x13]
	ldr r1, _08074E88 @ =0x00002808
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074E36:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08074E4E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074E8C @ =0x08366F2C
	bl SetDDP
_08074E4E:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074E66
	str r1, [r4, #0x60]
_08074E66:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08074E7C
	movs r0, #8
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08074E7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08074E82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074E88: .4byte 0x00002808
_08074E8C: .4byte sCollisions+(6*24)

	thumb_func_start FUN_08074e90
FUN_08074e90: @ 0x08074E90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08074EC6
	cmp r0, #1
	bgt _08074EA4
	cmp r0, #0
	beq _08074EAE
	b _08074F2A
_08074EA4:
	cmp r0, #2
	beq _08074F04
	cmp r0, #3
	beq _08074F12
	b _08074F2A
_08074EAE:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074EFC @ =0x08366F2C
	bl SetDDP
	ldr r1, _08074F00 @ =0x00002809
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074EC6:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08073ea8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08074EDE
	str r1, [r4, #0x60]
_08074EDE:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08073ef0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08074EF4
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074EF4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08074F2A
	.align 2, 0
_08074EFC: .4byte sCollisions+(6*24)
_08074F00: .4byte 0x00002809
_08074F04:
	ldr r1, _08074F30 @ =0x0000280A
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074F12:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08074F2A
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08074F2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074F30: .4byte 0x0000280A

	thumb_func_start FUN_08074f34
FUN_08074f34: @ 0x08074F34
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08074F44
	cmp r5, #1
	beq _08074F6E
	b _08074FB6
_08074F44:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08074FBC @ =0x08366F5C
	bl SetDDP
	ldr r1, _08074FC0 @ =0x0000280B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl FUN_080bb830
	str r0, [r4, #0x2c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074F6E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08074F7E
	movs r0, #0x18
	strb r0, [r4, #0x12]
	movs r0, #0x3b
	bl PlaySound
_08074F7E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, _08074FC4 @ =pZero2
	ldr r3, [r0]
	ldr r2, [r3, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r2, r1
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r5, #0xfe
	lsls r5, r5, #3
	adds r1, r2, r5
	cmp r0, #0
	beq _08074FA6
	ldr r0, _08074FC8 @ =0xFFFFF800
	adds r1, r2, r0
_08074FA6:
	str r1, [r4, #0x54]
	ldr r0, [r3, #0x58]
	ldr r1, _08074FC8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08074FB6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08074FBC: .4byte sCollisions+(8*24)
_08074FC0: .4byte 0x0000280B
_08074FC4: .4byte pZero2
_08074FC8: .4byte 0xFFFFF800

	thumb_func_start FUN_08074fcc
FUN_08074fcc: @ 0x08074FCC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08074FDC
	cmp r0, #1
	beq _08074FEC
	b _08075058
_08074FDC:
	strb r0, [r4, #0x12]
	ldr r1, _08075020 @ =0x0000280C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08074FEC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08075028
	ldr r2, _08075024 @ =0xFFFFFC00
	cmp r1, r2
	bge _0807500C
	ldrb r0, [r4, #0x12]
	muls r0, r2, r0
	cmp r0, #0
	bge _0807500A
	adds r0, #0xff
_0807500A:
	asrs r1, r0, #8
_0807500C:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #4
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4, #0x12]
	b _08075030
	.align 2, 0
_08075020: .4byte 0x0000280C
_08075024: .4byte 0xFFFFFC00
_08075028:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08075030:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08075060 @ =0x08366FEC
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08075064 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
_08075058:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08075060: .4byte u8_ARRAY_08366fec
_08075064: .4byte sCollisions

	thumb_func_start MaybeKillSnakecord
MaybeKillSnakecord: @ 0x08075068
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
	ldr r1, _080750E8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080bb908
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080750EC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080750F0 @ =0x0000270E
	cmp r1, r0
	bhi _080750C4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080750C4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _080750F4 @ =gEnemyFnTable
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
_080750E8: .4byte 0xFFFFF000
_080750EC: .4byte gScore
_080750F0: .4byte 0x0000270E
_080750F4: .4byte gEnemyFnTable

	thumb_func_start FUN_080750f8
FUN_080750f8: @ 0x080750F8
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
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08075150 @ =gEnemyFnTable
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
_08075150: .4byte gEnemyFnTable

	thumb_func_start FUN_08075154
FUN_08075154: @ 0x08075154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _0807516A
	cmp r7, #1
	bne _08075168
	b _08075282
_08075168:
	b _080752C2
_0807516A:
	ldr r0, [r6, #0x28]
	mov ip, r0
	cmp r0, #0
	beq _080751E2
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0xfd
	ands r0, r4
	mov r2, ip
	strb r0, [r2, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r2, [r2, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	mov r5, ip
	strb r0, [r5, #0xa]
	ldr r0, _08075260 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	ldr r5, [r5, #0x28]
	mov ip, r5
	ldrb r0, [r5, #0xa]
	ands r1, r0
	ands r1, r4
	strb r1, [r5, #0xa]
	mov r0, ip
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	mov r1, ip
	ldrb r0, [r1, #0xa]
	ands r3, r0
	strb r3, [r1, #0xa]
	ldrb r0, [r1, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r1, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r1, #0x14]
	str r7, [r6, #0x28]
_080751E2:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08075264 @ =0x08366FD4
	bl SetDDP
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _08075268 @ =0x0000280C
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, _0807526C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r3, _08075270 @ =0xFFFFE800
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
	beq _08075274
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
	b _0807527C
	.align 2, 0
_08075260: .4byte gEnemyFnTable
_08075264: .4byte sCollisions+(13*24)
_08075268: .4byte 0x0000280C
_0807526C: .4byte pZero2
_08075270: .4byte 0xFFFFE800
_08075274:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
_0807527C:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08075282:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807529A
	str r1, [r6, #0x60]
_0807529A:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080752BC
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080752C2
_080752BC:
	adds r0, r6, #0
	bl MaybeKillSnakecord
_080752C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
