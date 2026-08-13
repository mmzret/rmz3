	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08063da0
FUN_08063da0: @ 0x08063DA0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, _08063E0C @ =0x00002FFF
	cmp r1, r0
	bhi _08063DB6
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063DB6:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063DCC
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063DCC:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _08063DDE
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063DDE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08063DF6
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063DF6:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063E06
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063E06:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063E0C: .4byte 0x00002FFF

	thumb_func_start doNothing_08063e10
doNothing_08063e10: @ 0x08063E10
	push {r4, lr}
	adds r4, r0, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063E22
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063E22:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08063e28
FUN_08063e28: @ 0x08063E28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063E40
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063E40:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _08063E52
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063E52:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08063E6A
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063E6A:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063E7A
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063E7A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08063e80
FUN_08063e80: @ 0x08063E80
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063E98
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063E98:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08063EB0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063EB0:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063EC0
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063EC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08063ec8
FUN_08063ec8: @ 0x08063EC8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _08063EDC
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063EDC:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063EEC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063EEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08063ef4
FUN_08063ef4: @ 0x08063EF4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08063F10
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063F10:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063F20
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08063F20:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08063f28
FUN_08063f28: @ 0x08063F28
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xd]
	cmp r0, #8
	beq _08063F48
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08063F4C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08063F48
	movs r1, #0
	movs r0, #8
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08063F48:
	pop {r0}
	bx r0
	.align 2, 0
_08063F4C: .4byte 0x00020001

	thumb_func_start FUN_08063f50
FUN_08063f50: @ 0x08063F50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08063F60
	cmp r5, #1
	beq _08063F82
	b _08063FD2
_08063F60:
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08063FB8 @ =sCollisions
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063F82:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08063FD2
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r3, #1
	ands r2, r3
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, _08063FBC @ =0x00005FFF
	cmp r1, r0
	bhi _08063FC0
	cmp r2, r3
	bne _08063FC4
	b _08063FCA
	.align 2, 0
_08063FB8: .4byte sCollisions
_08063FBC: .4byte 0x00005FFF
_08063FC0:
	cmp r2, #0
	beq _08063FCA
_08063FC4:
	movs r1, #0
	movs r0, #1
	b _08063FCE
_08063FCA:
	movs r1, #0
	movs r0, #2
_08063FCE:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08063FD2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08063fd8
FUN_08063fd8: @ 0x08063FD8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r5, _08064040 @ =0xFFFFF580
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _08064044 @ =0xFFFFFA00
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806401C
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806401C
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	beq _08064048
_0806401C:
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080640CA
	.align 2, 0
_08064040: .4byte 0xFFFFF580
_08064044: .4byte 0xFFFFFA00
_08064048:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08064054
	cmp r5, #1
	beq _08064090
	b _080640CA
_08064054:
	ldr r1, _080640D0 @ =0x00001401
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080640D4 @ =sCollisions
	bl SetDDP
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064090:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, _080640D8 @ =0x00005FFF
	cmp r1, r0
	bls _080640BA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	subs r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	ble _080640BA
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080640BA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080640CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080640D0: .4byte 0x00001401
_080640D4: .4byte sCollisions
_080640D8: .4byte 0x00005FFF

	thumb_func_start FUN_080640dc
FUN_080640dc: @ 0x080640DC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	movs r5, #0xa8
	lsls r5, r5, #4
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _08064150 @ =0xFFFFFA00
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064122
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08064122
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	beq _08064154
_08064122:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	strb r3, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _080641DA
	.align 2, 0
_08064150: .4byte 0xFFFFFA00
_08064154:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08064160
	cmp r5, #1
	beq _080641A0
	b _080641DA
_08064160:
	ldr r1, _080641E0 @ =0x00001401
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080641E4 @ =sCollisions
	bl SetDDP
	movs r0, #0x80
	str r0, [r4, #0x5c]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080641A0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, _080641E8 @ =0x00005FFF
	cmp r1, r0
	bls _080641CA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	subs r0, r2, r0
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	ble _080641CA
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080641CA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080641DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080641E0: .4byte 0x00001401
_080641E4: .4byte sCollisions
_080641E8: .4byte 0x00005FFF

	thumb_func_start FUN_080641ec
FUN_080641ec: @ 0x080641EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080641FC
	cmp r0, #1
	beq _08064216
	b _08064290
_080641FC:
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08064270 @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064216:
	ldr r1, [r4, #0x60]
	ldr r0, _08064274 @ =0x000006FF
	cmp r1, r0
	bgt _08064224
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r4, #0x60]
_08064224:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0806427C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _08064278 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PantheonGuardian_Die
	b _08064290
	.align 2, 0
_08064270: .4byte sCollisions
_08064274: .4byte 0x000006FF
_08064278: .4byte gEnemyFnTable
_0806427C:
	cmp r1, #0
	beq _08064290
	ldr r0, _08064298 @ =0x0000800F
	cmp r1, r0
	beq _08064290
	subs r0, #1
	cmp r1, r0
	beq _08064290
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_08064290:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064298: .4byte 0x0000800F

	thumb_func_start FUN_0806429c
FUN_0806429c: @ 0x0806429C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080642C4
	cmp r0, #1
	bgt _080642B0
	cmp r0, #0
	beq _080642B6
	b _08064330
_080642B0:
	cmp r0, #2
	beq _08064304
	b _08064330
_080642B6:
	ldr r1, _080642F8 @ =0x00001402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080642C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08064330
	ldr r1, _080642FC @ =0x00001403
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08064300 @ =sCollisions+(24*2)
	bl SetDDP
	movs r0, #0x3a
	bl PlaySound
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08064330
	.align 2, 0
_080642F8: .4byte 0x00001402
_080642FC: .4byte 0x00001403
_08064300: .4byte sCollisions+(24*2)
_08064304:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08064330
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08064350 @ =sCollisions
	bl SetDDP
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08064330:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806434A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_0806434A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08064350: .4byte sCollisions

	thumb_func_start FUN_08064354
FUN_08064354: @ 0x08064354
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08064364
	cmp r5, #1
	beq _080643E2
	b _08064422
_08064364:
	ldr r1, _080643A4 @ =0x00001404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080643A8 @ =sCollisions+(24*4)
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080643AC
	movs r0, #0x80
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080643D4
	.align 2, 0
_080643A4: .4byte 0x00001404
_080643A8: .4byte sCollisions+(24*4)
_080643AC:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080643D4:
	movs r1, #0
	movs r0, #0xc
	strb r0, [r4, #0x12]
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080643E2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08064408
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08064422
_08064408:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0806441A
	movs r0, #1
	b _0806441E
_0806441A:
	movs r1, #0
	movs r0, #2
_0806441E:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08064422:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806443C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_0806443C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08064444
FUN_08064444: @ 0x08064444
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08064466
	ldr r1, _08064474 @ =0x00001404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08064478 @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08064466:
	adds r0, r4, #0
	bl UpdateEntityAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064474: .4byte 0x00001404
_08064478: .4byte sCollisions

	thumb_func_start FUN_0806447c
FUN_0806447c: @ 0x0806447C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080644A6
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08064498
	adds r0, #0x1f
_08064498:
	asrs r0, r0, #5
	str r0, [r4, #0x64]
	movs r0, #0x1f
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080644A6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080644E0
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r2, #0
	bl FUN_080098a4
	movs r1, #0x80
	lsls r1, r1, #5
	ands r1, r0
	cmp r1, #0
	bne _080644EA
_080644E0:
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080644F4
_080644EA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080644F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080644fc
FUN_080644fc: @ 0x080644FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _080645F6
	ldr r1, _0806456C @ =0x00001404
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _08064570 @ =pZero2
	ldr r2, [r4]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	ldr r2, _08064574 @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _08064578
	ldr r0, [r5, #0x5c]
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08064592
	.align 2, 0
_0806456C: .4byte 0x00001404
_08064570: .4byte pZero2
_08064574: .4byte 0xFFFFE800
_08064578:
	ldr r0, [r4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806458A
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0806458C
_0806458A:
	ldr r0, _080645B8 @ =0xFFFFFA00
_0806458C:
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
_08064592:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080645BC
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080645DE
	.align 2, 0
_080645B8: .4byte 0xFFFFFA00
_080645BC:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080645DE:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08064650 @ =sCollisions+(24*6)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080645F6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	adds r2, #0x40
	str r2, [r5, #0x60]
	adds r0, r0, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064632
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08064654 @ =0xFFFFE800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806464A
_08064632:
	ldr r1, _08064658 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl PantheonGuardian_Die
_0806464A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064650: .4byte sCollisions+(24*6)
_08064654: .4byte 0xFFFFE800
_08064658: .4byte gEnemyFnTable

	thumb_func_start PantheonGuardian_OnCollision
PantheonGuardian_OnCollision: @ 0x0806465C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08064682
	ldr r2, [r2, #0x2c]
	movs r3, #0
	ldr r0, _08064688 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0806467C
	movs r3, #1
_0806467C:
	adds r0, r2, #0
	adds r0, #0xb8
	strb r3, [r0]
_08064682:
	pop {r0}
	bx r0
	.align 2, 0
_08064688: .4byte pZero2
