	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyx_08056908
copyx_08056908: @ 0x08056908
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056920
	ldr r1, _08056940 @ =0x0000B30B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0x12]
_08056920:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0x79
	beq _0805696C
	cmp r0, #0x79
	bgt _0805694E
	cmp r0, #0x35
	beq _0805696C
	cmp r0, #0x35
	bgt _08056944
	cmp r0, #0x2c
	beq _08056966
	b _08056980
	.align 2, 0
_08056940: .4byte 0x0000B30B
_08056944:
	cmp r0, #0x3e
	beq _0805696C
	cmp r0, #0x70
	beq _08056966
	b _08056980
_0805694E:
	cmp r0, #0xb4
	beq _08056966
	cmp r0, #0xb4
	bgt _0805695C
	cmp r0, #0x82
	beq _0805696C
	b _08056980
_0805695C:
	cmp r0, #0xbd
	beq _0805696C
	cmp r0, #0xc6
	beq _0805696C
	b _08056980
_08056966:
	movs r0, #0x3c
	bl PlaySound
_0805696C:
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080a9048
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_080a9048
_08056980:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd9
	bne _0805699E
	movs r0, #0x1b
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xc6
	movs r0, #0
	strb r0, [r1]
_0805699E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080569a4
FUN_080569a4: @ 0x080569A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080569BA
	ldr r1, _080569E0 @ =0x0000B30C
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_080569BA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080569D8
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #4
	strb r0, [r4, #0x12]
_080569D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080569E0: .4byte 0x0000B30C

	thumb_func_start copyx_080569e4
copyx_080569e4: @ 0x080569E4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080569FA
	ldr r1, _08056A7C @ =0x0000B30D
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0xe]
_080569FA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056A76
	movs r4, #0
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	movs r0, #0x1d
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #2
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #3
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #4
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #5
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #6
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #7
	bl FUN_080a88a4
	adds r0, r5, #0
	adds r0, #0xc6
	strb r4, [r0]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	movs r0, #0x46
	bl PlaySound
_08056A76:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08056A7C: .4byte 0x0000B30D

	thumb_func_start FUN_08056a80
FUN_08056a80: @ 0x08056A80
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056A96
	ldr r1, _08056ABC @ =0x0000B30E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_08056A96:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056AB4
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #4
	strb r0, [r4, #0x12]
_08056AB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056ABC: .4byte 0x0000B30E

	thumb_func_start copyx_08056ac0
copyx_08056ac0: @ 0x08056AC0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056B2E
	ldr r1, _08056B18 @ =0x0000B301
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _08056B1C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056AE2
	movs r3, #1
_08056AE2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056AF4
	movs r3, #1
_08056AF4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08056B20
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08056B26
	.align 2, 0
_08056B18: .4byte 0x0000B301
_08056B1C: .4byte pZero2
_08056B20:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08056B26:
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
_08056B2E:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08056B4C
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056B5E
	ldr r1, _08056B48 @ =0x0000B302
	adds r0, r4, #0
	bl SetMotion
	b _08056B5E
	.align 2, 0
_08056B48: .4byte 0x0000B302
_08056B4C:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056B5E
	movs r0, #0x1f
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08056B5E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyx_08056b6c
copyx_08056b6c: @ 0x08056B6C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056B8C
	ldr r1, _08056BCC @ =0x0000B303
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #0x40
	strb r0, [r4, #0x12]
	movs r0, #0x46
	bl PlaySound
_08056B8C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08056BA6
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl CreateProjectile28
_08056BA6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08056BC4
	movs r0, #0x20
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xc6
	movs r0, #0
	strb r0, [r1]
_08056BC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056BCC: .4byte 0x0000B303

	thumb_func_start copyx_08056bd0
copyx_08056bd0: @ 0x08056BD0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056BEA
	ldr r1, _08056C10 @ =0x0000B303
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #0x40
	strb r0, [r4, #0x12]
_08056BEA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056C08
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #4
	strb r0, [r4, #0x12]
_08056C08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056C10: .4byte 0x0000B303

	thumb_func_start copyxKnockBackDamage
copyxKnockBackDamage: @ 0x08056C14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056CC6
	ldr r1, _08056C70 @ =0x0000B311
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	movs r3, #0
	ldr r0, _08056C74 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056C3C
	movs r3, #1
_08056C3C:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056C4E
	movs r3, #1
_08056C4E:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08056C78
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08056C7E
	.align 2, 0
_08056C70: .4byte 0x0000B311
_08056C74: .4byte pZero2
_08056C78:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08056C7E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08056C94
	ldr r0, _08056C90 @ =0xFFFFFE00
	b _08056C98
	.align 2, 0
_08056C90: .4byte 0xFFFFFE00
_08056C94:
	movs r0, #0x80
	lsls r0, r0, #2
_08056C98:
	str r0, [r4, #0x5c]
	ldr r0, _08056CE8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xc6
	movs r5, #0
	strb r5, [r0]
	movs r0, #8
	strb r0, [r4, #0x12]
	movs r0, #0x47
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08056CEC @ =sCollisions
	bl SetDDP
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _08056CC6
	movs r0, #1
	strb r0, [r1, #0x11]
	str r5, [r4, #0x2c]
_08056CC6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r1, r4, #0
	adds r1, #0xdd
	adds r0, r4, #0
	adds r0, #0xa4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _08056CF0
	movs r0, #0x24
	b _08056D4A
	.align 2, 0
_08056CE8: .4byte 0xFFFFFE00
_08056CEC: .4byte sCollisions
_08056CF0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08056D34
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08056D50
	ldr r1, _08056D30 @ =0x0000B308
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08056D50
	.align 2, 0
_08056D30: .4byte 0x0000B308
_08056D34:
	adds r0, r2, #0
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _08056D50
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0x22
_08056D4A:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08056D50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08056d58
FUN_08056d58: @ 0x08056D58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r0, [r4, #0x54]
	ldr r7, _08056DC0 @ =0xFFFF5800
	adds r0, r0, r7
	ldr r1, [r6]
	subs r1, r1, r0
	mov r8, r1
	ldr r2, _08056DC4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08056DC8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08056DCC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r5, r0, #0x11
	movs r0, #0xf
	ands r5, r0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056D9A
	ldr r1, _08056DD0 @ =0x0000B305
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_08056D9A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r4, #0
	adds r2, #0xce
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa4
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble _08056DD4
	movs r0, #0
	movs r1, #0x23
	strb r1, [r4, #0xd]
	movs r1, #1
	strb r1, [r4, #0xe]
	strb r0, [r2]
	b _08056E88
	.align 2, 0
_08056DC0: .4byte 0xFFFF5800
_08056DC4: .4byte RNG_0202f388
_08056DC8: .4byte 0x000343FD
_08056DCC: .4byte 0x00269EC3
_08056DD0: .4byte 0x0000B305
_08056DD4:
	ldr r0, [r4, #0x54]
	adds r3, r0, r7
	ldr r1, [r6]
	subs r2, r1, r3
	adds r6, r0, #0
	cmp r2, #0
	blt _08056DEC
	movs r0, #0xc8
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08056DF6
	b _08056E24
_08056DEC:
	subs r1, r3, r1
	movs r0, #0xc8
	lsls r0, r0, #8
	cmp r1, r0
	ble _08056E24
_08056DF6:
	ldr r2, _08056E18 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08056E1C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08056E20 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08056E62
	movs r0, #6
	b _08056E82
	.align 2, 0
_08056E18: .4byte RNG_0202f388
_08056E1C: .4byte 0x000343FD
_08056E20: .4byte 0x00269EC3
_08056E24:
	cmp r5, #4
	bhi _08056E2C
	movs r0, #6
	b _08056E82
_08056E2C:
	cmp r5, #9
	bhi _08056E38
	adds r0, r4, #0
	bl copyx_080577c8
	b _08056E84
_08056E38:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, _08056E54 @ =0xFFFF5800
	adds r1, r6, r2
	ldr r0, [r0]
	subs r2, r0, r1
	cmp r2, #0
	blt _08056E58
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08056E62
	b _08056E80
	.align 2, 0
_08056E54: .4byte 0xFFFF5800
_08056E58:
	subs r1, r1, r0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _08056E80
_08056E62:
	movs r0, #9
	strb r0, [r4, #0xd]
	movs r0, #0xb
	strb r0, [r4, #0xf]
	mov r0, r8
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _08056E7C @ =0xFFFFFB00
	str r0, [r4, #0x60]
	b _08056E84
	.align 2, 0
_08056E7C: .4byte 0xFFFFFB00
_08056E80:
	movs r0, #0x10
_08056E82:
	strb r0, [r4, #0xd]
_08056E84:
	movs r0, #1
	strb r0, [r4, #0xe]
_08056E88:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyxRaisingExcharge
copyxRaisingExcharge: @ 0x08056E94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056F0E
	ldr r1, _08056EF4 @ =0x0000B31A
	adds r0, r4, #0
	movs r2, #0xa
	movs r3, #0
	bl GotoMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	movs r3, #0
	ldr r0, _08056EF8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056EC0
	movs r3, #1
_08056EC0:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056ED2
	movs r3, #1
_08056ED2:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08056EFC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08056F02
	.align 2, 0
_08056EF4: .4byte 0x0000B31A
_08056EF8: .4byte pZero2
_08056EFC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08056F02:
	strb r0, [r4, #0xa]
	movs r0, #0xc
	strb r0, [r4, #0x12]
	movs r0, #0x4a
	bl PlaySound
_08056F0E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _08056F44
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08056FCC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08056F40 @ =0x08363C78
	bl SetDDP
	adds r0, r4, #0
	bl CreateVFX52
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _08056F68
	.align 2, 0
_08056F40: .4byte 0x08363C78
_08056F44:
	cmp r1, #1
	bne _08056F70
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r2, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08056FCC
	ldr r0, [r4, #0x2c]
	strb r1, [r0, #0x11]
	str r2, [r4, #0x2c]
	strb r2, [r4, #0x12]
	adds r0, r4, #0
	movs r1, #2
	bl CreateProjectile28
_08056F68:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08056FCC
_08056F70:
	ldrb r1, [r4, #0x12]
	movs r5, #3
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08056F94
	adds r1, r4, #0
	adds r1, #0xa4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, #0x34
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0x4b
	bl PlaySound
_08056F94:
	ldrb r2, [r4, #0x12]
	cmp r2, #0x7f
	beq _08056FA6
	ldr r0, _08056FC0 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08056FC8
_08056FA6:
	strb r5, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08056FC4 @ =sCollisions
	bl SetDDP
	movs r0, #4
	b _08056FCA
	.align 2, 0
_08056FC0: .4byte gStageRun
_08056FC4: .4byte sCollisions
_08056FC8:
	adds r0, r2, #1
_08056FCA:
	strb r0, [r4, #0x12]
_08056FCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyxMode36
copyxMode36: @ 0x08056FD4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08057064
	ldr r1, _08057038 @ =0x0000B314
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	movs r3, #0
	ldr r0, _0805703C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08057002
	movs r3, #1
_08057002:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08057014
	movs r3, #1
_08057014:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08057040
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08057046
	.align 2, 0
_08057038: .4byte 0x0000B314
_0805703C: .4byte pZero2
_08057040:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08057046:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08057090 @ =0x08363C78
	bl SetDDP
	adds r0, r4, #0
	bl CreateVFX52
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	movs r0, #0x45
	bl PlaySound
_08057064:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08057088
	ldr r0, [r4, #0x2c]
	movs r1, #1
	strb r1, [r0, #0x11]
	movs r0, #0
	str r0, [r4, #0x2c]
	movs r0, #0xf
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xde
	strb r1, [r0]
_08057088:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08057090: .4byte 0x08363C78

	thumb_func_start copyx_08057094
copyx_08057094: @ 0x08057094
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805711C
	ldr r1, _080570F0 @ =0x0000B31B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r3, #0
	ldr r0, _080570F4 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080570BA
	movs r3, #1
_080570BA:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080570CC
	movs r3, #1
_080570CC:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _080570F8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080570FE
	.align 2, 0
_080570F0: .4byte 0x0000B31B
_080570F4: .4byte pZero2
_080570F8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080570FE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateVFX55
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl copyx_080aa24c
	adds r1, r4, #0
	adds r1, #0xc6
	movs r0, #0
	strb r0, [r1]
_0805711C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08057134
	movs r0, #0x14
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08057134:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyxMode38
copyxMode38: @ 0x0805713C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080571C4
	ldr r1, _08057198 @ =0x0000B31C
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r3, #0
	ldr r0, _0805719C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08057162
	movs r3, #1
_08057162:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08057174
	movs r3, #1
_08057174:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _080571A0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080571A6
	.align 2, 0
_08057198: .4byte 0x0000B31C
_0805719C: .4byte pZero2
_080571A0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080571A6:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl CreateVFX55
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl copyx_080aa24c
	adds r1, r4, #0
	adds r1, #0xc6
	movs r0, #0
	strb r0, [r1]
_080571C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080571FA
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080571E8
	ldr r0, _080571E4 @ =0xFFFFFE00
	b _080571EC
	.align 2, 0
_080571E4: .4byte 0xFFFFFE00
_080571E8:
	movs r0, #0x80
	lsls r0, r0, #2
_080571EC:
	str r0, [r4, #0x5c]
	ldr r0, _08057200 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	movs r0, #0x19
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080571FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08057200: .4byte 0xFFFFFE00

	thumb_func_start copyx_08057204
copyx_08057204: @ 0x08057204
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080572B4
	ldr r1, _08057260 @ =0x0000B311
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	movs r3, #0
	ldr r0, _08057264 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805722C
	movs r3, #1
_0805722C:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0805723E
	movs r3, #1
_0805723E:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08057268
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805726E
	.align 2, 0
_08057260: .4byte 0x0000B311
_08057264: .4byte pZero2
_08057268:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805726E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08057284
	ldr r0, _08057280 @ =0xFFFFFE00
	b _08057288
	.align 2, 0
_08057280: .4byte 0xFFFFFE00
_08057284:
	movs r0, #0x80
	lsls r0, r0, #2
_08057288:
	str r0, [r4, #0x5c]
	ldr r0, _080572C8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	movs r0, #8
	strb r0, [r4, #0x12]
	ldr r3, _080572CC @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080572B4
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080572B4
	ldr r0, _080572D0 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080572B4:
	ldrb r0, [r4, #0xf]
	cmp r0, #5
	bls _080572BC
	b _0805740C
_080572BC:
	lsls r0, r0, #2
	ldr r1, _080572D4 @ =_080572D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080572C8: .4byte 0xFFFFFE00
_080572CC: .4byte gStageRun
_080572D0: .4byte 0x0000FFFE
_080572D4: .4byte _080572D8
_080572D8: @ jump table
	.4byte _080572F0 @ case 0
	.4byte _08057324 @ case 1
	.4byte _08057354 @ case 2
	.4byte _08057390 @ case 3
	.4byte _080573E8 @ case 4
	.4byte _08057406 @ case 5
_080572F0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08057314
	b _0805740C
_08057314:
	ldr r1, _08057320 @ =0x0000B308
	adds r0, r4, #0
	bl SetMotion
	b _080573FE
	.align 2, 0
_08057320: .4byte 0x0000B308
_08057324:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	cmp r0, r1
	bge _0805740C
	str r0, [r4, #0x58]
	ldr r1, _08057350 @ =0x0000B305
	adds r0, r4, #0
	bl SetMotion
	b _080573FE
	.align 2, 0
_08057350: .4byte 0x0000B305
_08057354:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805740C
	ldr r1, _08057384 @ =0x0000B306
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r2, _08057388 @ =0xFFFF1000
	adds r1, r1, r2
	ldr r0, [r0]
	subs r0, r0, r1
	movs r1, #0x28
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0805738C @ =0xFFFFFB00
	str r0, [r4, #0x60]
	b _080573FE
	.align 2, 0
_08057384: .4byte 0x0000B306
_08057388: .4byte 0xFFFF1000
_0805738C: .4byte 0xFFFFFB00
_08057390:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _080573B2
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_080573B2:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	cmp r0, r1
	bge _0805740C
	adds r0, r2, #0
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080573E4 @ =0x0000B313
	adds r0, r4, #0
	bl SetMotion
	b _080573FE
	.align 2, 0
_080573E4: .4byte 0x0000B313
_080573E8:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805740C
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805740C
_080573FE:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _0805740C
_08057406:
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0805740C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start copyx_08057418
copyx_08057418: @ 0x08057418
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0805744E
	ldr r1, _0805747C @ =0x0000B306
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r5, #0x54]
	ldr r2, _08057480 @ =0xFFFF5800
	adds r1, r1, r2
	ldr r0, [r0]
	subs r0, r0, r1
	movs r4, #0x14
	movs r1, #0x14
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, _08057484 @ =0xFFFFFB00
	str r0, [r5, #0x60]
	strb r4, [r5, #0x12]
_0805744E:
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	beq _080574CC
	cmp r0, #1
	bgt _08057488
	cmp r0, #0
	beq _08057492
	b _0805751A
	.align 2, 0
_0805747C: .4byte 0x0000B306
_08057480: .4byte 0xFFFF5800
_08057484: .4byte 0xFFFFFB00
_08057488:
	cmp r0, #2
	beq _080574EC
	cmp r0, #3
	beq _08057502
	b _0805751A
_08057492:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x40
	str r1, [r5, #0x60]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080574BE
	ldr r1, _080574C8 @ =0x0000B314
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	movs r0, #0x14
	strb r0, [r5, #0x12]
_080574BE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0805751A
	.align 2, 0
_080574C8: .4byte 0x0000B314
_080574CC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805751A
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	movs r0, #0x30
	strb r0, [r5, #0x12]
	b _0805751A
_080574EC:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805751A
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	b _0805751A
_08057502:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805751A
	movs r0, #2
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
_0805751A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start copyx_08057520
copyx_08057520: @ 0x08057520
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08057544
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x62
	bl StartPaletteAnimation
	movs r0, #0x24
	strb r0, [r4, #0x12]
_08057544:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #0x62
	bl StepPaletteAnimation
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08057588
	movs r0, #0x62
	bl RemovePaletteAnimation
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08057588:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyx_08057590
copyx_08057590: @ 0x08057590
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08057628
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080575C0
	movs r4, #0
	strb r4, [r5, #0xe]
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x63
	bl StartPaletteAnimation
	movs r0, #0x39
	bl PlaySound
	movs r0, #0xff
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
_080575C0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0x63
	bl StepPaletteAnimation
	ldrb r0, [r5, #0x12]
	movs r1, #7
	ands r1, r0
	cmp r1, #3
	bne _080575E8
	ldrb r2, [r5, #0x13]
	adds r0, r5, #0
	movs r1, #2
	bl CreateVFX56
	ldrb r0, [r5, #0x13]
	adds r0, #0xc
	strb r0, [r5, #0x13]
	b _0805760E
_080575E8:
	cmp r1, #7
	bne _0805760E
	ldr r3, _08057630 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _08057634 @ =0x000343FD
	adds r2, r1, #0
	muls r2, r0, r2
	ldr r0, _08057638 @ =0x00269EC3
	adds r2, r2, r0
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r3]
	lsrs r2, r2, #0x11
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	movs r1, #2
	bl CreateVFX56
_0805760E:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r4, #4
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08057628
	movs r0, #0x63
	bl RemovePaletteAnimation
	movs r0, #0
	strb r4, [r5, #0xd]
	strb r0, [r5, #0xe]
_08057628:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08057630: .4byte RNG_0202f388
_08057634: .4byte 0x000343FD
_08057638: .4byte 0x00269EC3

	thumb_func_start copyx_0805763c
copyx_0805763c: @ 0x0805763C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _080576B4
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080576EC @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	adds r2, r4, #0
	adds r2, #0xe0
	str r0, [r2]
	cmp r0, #0
	beq _0805773C
	adds r0, #0x74
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x76
	strb r1, [r0]
	ldr r0, [r2]
	str r5, [r0, #0x78]
	ldr r0, [r2]
	adds r0, #0x7c
	movs r1, #0x21
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x7d
	movs r1, #0x1e
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r0, #0x64
	bl StartPaletteAnimation
	ldr r2, _080576F0 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	movs r0, #0x39
	bl StopSound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080576B4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bhi _0805773C
	movs r0, #0x64
	bl StepPaletteAnimation
	ldrb r1, [r4, #0x13]
	adds r0, r1, #4
	cmp r0, #0xff
	ble _080576D0
	movs r0, #0xff
_080576D0:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	beq _080576F4
	adds r2, r4, #0
	adds r2, #0xe0
	ldr r1, [r2]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #8
	str r0, [r1, #0x78]
	adds r5, r2, #0
	b _0805771A
	.align 2, 0
_080576EC: .4byte 0xFFFFF000
_080576F0: .4byte gStageRun
_080576F4:
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #8
	ldr r1, _0805770C @ =0xFFFFF100
	adds r2, r0, r1
	cmp r2, #0
	ble _08057710
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	str r2, [r0, #0x78]
	b _08057718
	.align 2, 0
_0805770C: .4byte 0xFFFFF100
_08057710:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	str r3, [r0, #0x78]
_08057718:
	adds r5, r1, #0
_0805771A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805773C
	movs r0, #0x64
	bl RemovePaletteAnimation
	ldr r0, [r5]
	adds r0, #0x77
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805773C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start copyx_08057744
copyx_08057744: @ 0x08057744
	push {r4, lr}
	adds r2, r0, #0
	adds r0, #0xb4
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r1, r3
	ldr r3, [r2, #0x54]
	cmp r3, r0
	blt _08057766
	movs r4, #0xa0
	lsls r4, r4, #9
	adds r0, r1, r4
	adds r1, r2, #0
	adds r1, #0xbc
	cmp r3, r0
	ble _0805776E
_08057766:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	str r0, [r2, #0x54]
_0805776E:
	ldr r0, [r2, #0x54]
	str r0, [r1]
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	adds r3, r2, #0
	adds r3, #0xc0
	cmp r1, r0
	bge _0805778C
	ldr r0, [r3]
	str r0, [r2, #0x58]
_0805778C:
	ldr r0, [r2, #0x58]
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CopyX_OnDamage
CopyX_OnDamage: @ 0x08057798
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080577BE
	ldr r2, [r2, #0x2c]
	movs r3, #0
	ldr r0, _080577C4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080577B8
	movs r3, #1
_080577B8:
	adds r0, r2, #0
	adds r0, #0xc4
	strb r3, [r0]
_080577BE:
	pop {r0}
	bx r0
	.align 2, 0
_080577C4: .4byte pZero2

	thumb_func_start copyx_080577c8
copyx_080577c8: @ 0x080577C8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08057836
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08057824
	cmp r0, #1
	bgt _080577E8
	cmp r0, #0
	beq _080577F2
	b _080578D6
_080577E8:
	cmp r0, #2
	beq _0805782A
	cmp r0, #3
	beq _08057830
	b _080578D6
_080577F2:
	ldr r0, _0805781C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	asrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080578B0
	movs r0, #9
	strb r0, [r4, #0xd]
	movs r0, #0x15
	strb r0, [r4, #0xf]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x58
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _08057820 @ =0xFFFFFA80
	b _080578D4
	.align 2, 0
_0805781C: .4byte pZero2
_08057820: .4byte 0xFFFFFA80
_08057824:
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	b _080578D6
_0805782A:
	movs r0, #0x1a
	strb r0, [r4, #0xd]
	b _080578D6
_08057830:
	movs r0, #0x1e
	strb r0, [r4, #0xd]
	b _080578D6
_08057836:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805786C
	ldr r2, _08057860 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08057864 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08057868 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _080578A0
	b _08057888
	.align 2, 0
_08057860: .4byte RNG_0202f388
_08057864: .4byte 0x000343FD
_08057868: .4byte 0x00269EC3
_0805786C:
	ldr r2, _08057894 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08057898 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805789C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #5
	bhi _080578A0
_08057888:
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	b _080578D6
	.align 2, 0
_08057894: .4byte RNG_0202f388
_08057898: .4byte 0x000343FD
_0805789C: .4byte 0x00269EC3
_080578A0:
	ldr r0, _080578B8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	asrs r0, r0, #9
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080578BC
_080578B0:
	movs r0, #0x11
	strb r0, [r4, #0xd]
	b _080578D6
	.align 2, 0
_080578B8: .4byte pZero2
_080578BC:
	movs r0, #9
	strb r0, [r4, #0xd]
	movs r0, #0x15
	strb r0, [r4, #0xf]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x50
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _080578DC @ =0xFFFFFB00
_080578D4:
	str r0, [r4, #0x60]
_080578D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080578DC: .4byte 0xFFFFFB00

	thumb_func_start copyx_080578e0
copyx_080578e0: @ 0x080578E0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r3, #0
	movs r2, #0
	ldr r0, _08057960 @ =RNG_0202f388
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0xdc
	ldrb r1, [r0]
	movs r6, #1
	adds r5, r0, #0
_080578F8:
	adds r0, r1, #0
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	beq _0805790A
	mov r7, sp
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #1
_0805790A:
	adds r2, #1
	cmp r2, #3
	ble _080578F8
	mov r0, ip
	ldr r1, [r0]
	ldr r0, _08057964 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08057968 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r0, r0, #0x11
	adds r1, r3, #0
	bl __umodsi3
	movs r1, #5
	strb r1, [r4, #0xd]
	mov r7, sp
	adds r2, r7, r0
	ldrb r0, [r2]
	strb r0, [r4, #0xf]
	movs r4, #1
	adds r0, r4, #0
	ldrb r1, [r2]
	lsls r0, r1
	movs r3, #0xf
	eors r0, r3
	ldrb r1, [r5]
	ands r0, r1
	strb r0, [r5]
	cmp r0, #0
	bne _08057958
	adds r0, r4, #0
	ldrb r2, [r2]
	lsls r0, r2
	eors r0, r3
	strb r0, [r5]
_08057958:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057960: .4byte RNG_0202f388
_08057964: .4byte 0x000343FD
_08057968: .4byte 0x00269EC3
