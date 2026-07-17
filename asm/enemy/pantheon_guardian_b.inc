	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

