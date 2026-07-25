	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyxNovaStrike3
copyxNovaStrike3: @ 0x080560D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056166
	ldr r1, _08056108 @ =0x0000B30A
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08056110
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r0, _0805610C @ =0x0000FFF8
	b _0805611A
	.align 2, 0
_08056108: .4byte 0x0000B30A
_0805610C: .4byte 0x0000FFF8
_08056110:
	ldr r0, _08056140 @ =0xFFFFFC80
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc8
	movs r0, #8
_0805611A:
	strh r0, [r1]
	movs r0, #0
	str r0, [r4, #0x60]
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xde
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _08056148
	subs r0, #0x6a
	ldr r1, _08056144 @ =0x08363CA8
	bl SetDDP
	movs r0, #0x46
	bl PlaySound
	b _08056158
	.align 2, 0
_08056140: .4byte 0xFFFFFC80
_08056144: .4byte 0x08363CA8
_08056148:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080561F0 @ =0x08363C48
	bl SetDDP
	movs r0, #0x46
	bl PlaySound
_08056158:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateCopyXSonicBoom
	movs r0, #0
	strb r0, [r5]
_08056166:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r3, [r4, #0x5c]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r0, r0, r2
	ldr r2, [r4, #0x58]
	cmp r2, r0
	bge _08056224
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	ldr r1, _080561F4 @ =pZero2
	ldr r0, [r1]
	ldr r0, [r0, #0x58]
	adds r3, r1, #0
	cmp r2, r0
	ble _080561A2
	ldr r5, _080561F8 @ =0xFFFFFE00
	adds r0, r2, r5
	str r0, [r4, #0x58]
_080561A2:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _080561BE
	movs r5, #0xa0
	lsls r5, r5, #9
	adds r0, r2, r5
	cmp r1, r0
	ble _080561C6
_080561BE:
	movs r0, #0xb
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080561C6:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	bics r2, r0
	movs r5, #0
	ldr r0, [r3]
	ldr r0, [r0, #0x54]
	adds r3, r1, #0
	cmp r0, r3
	bge _080561DC
	movs r5, #1
_080561DC:
	cmp r2, r5
	beq _08056266
	subs r2, r0, r3
	cmp r2, #0
	blt _080561FC
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	bgt _08056206
	b _08056266
	.align 2, 0
_080561F0: .4byte 0x08363C48
_080561F4: .4byte pZero2
_080561F8: .4byte 0xFFFFFE00
_080561FC:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _08056266
_08056206:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x28
	bls _08056266
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r1, [r0]
	cmp r1, #0
	bne _0805625E
	movs r0, #0xa
	strb r0, [r4, #0xd]
	movs r0, #0x15
	strb r0, [r4, #0xf]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	b _08056262
_08056224:
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, r3, r0
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	cmp r1, #0
	bge _08056238
	rsbs r1, r1, #0
_08056238:
	ldr r0, _08056250 @ =0x000003FF
	cmp r1, r0
	bgt _08056258
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08056254
	movs r0, #0x80
	lsls r0, r0, #3
	b _08056256
	.align 2, 0
_08056250: .4byte 0x000003FF
_08056254:
	ldr r0, _0805626C @ =0xFFFFFC00
_08056256:
	str r0, [r4, #0x5c]
_08056258:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x28
	bls _08056266
_0805625E:
	movs r0, #0xb
	strb r0, [r4, #0xd]
_08056262:
	movs r0, #1
	strb r0, [r4, #0xe]
_08056266:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805626C: .4byte 0xFFFFFC00

	thumb_func_start copyxMode16
copyxMode16: @ 0x08056270
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080562FA
	ldr r1, _080562C8 @ =0x0000B310
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _080562CC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08056292
	movs r3, #1
_08056292:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080562A4
	movs r3, #1
_080562A4:
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
	beq _080562D0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080562D6
	.align 2, 0
_080562C8: .4byte 0x0000B310
_080562CC: .4byte pZero2
_080562D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080562D6:
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080562F0
	ldr r0, _080562EC @ =0xFFFFFD00
	b _080562F4
	.align 2, 0
_080562EC: .4byte 0xFFFFFD00
_080562F0:
	movs r0, #0xc0
	lsls r0, r0, #2
_080562F4:
	str r0, [r4, #0x5c]
	ldr r0, _08056334 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_080562FA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _0805632E
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xc
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805632E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056334: .4byte 0xFFFFFD00

	thumb_func_start copyxMode17
copyxMode17: @ 0x08056338
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08056378 @ =u8_ARRAY_080fefb0
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805638C
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08056380
	ldr r0, _0805637C @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08056380
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08056380
	movs r0, #0x25
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl copyx_08057094
	b _080563C4
	.align 2, 0
_08056378: .4byte u8_ARRAY_080fefb0
_0805637C: .4byte gScore
_08056380:
	ldr r1, _080563B4 @ =0x0000B301
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_0805638C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080563C4
	movs r0, #0x12
	strb r0, [r4, #0xd]
	movs r1, #1
	strb r1, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080563B8
	strb r1, [r4, #0x13]
	b _080563C4
	.align 2, 0
_080563B4: .4byte 0x0000B301
_080563B8:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
_080563C4:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start copyxMode18
copyxMode18: @ 0x080563CC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _080563FC @ =u8_ARRAY_080fefb4
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056410
	ldr r1, _08056400 @ =0x0000B302
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08056404
	movs r0, #4
	b _0805640E
	.align 2, 0
_080563FC: .4byte u8_ARRAY_080fefb4
_08056400: .4byte 0x0000B302
_08056404:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
_0805640E:
	strb r0, [r4, #0x12]
_08056410:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805642C
	movs r0, #0x13
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805642C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start copyxMode19
copyxMode19: @ 0x08056434
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080564DA
	ldr r1, _08056470 @ =0x0000B303
	adds r0, r4, #0
	bl SetMotion
	movs r6, #0
	strb r6, [r4, #0xe]
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r0, [r5]
	cmp r0, #0
	beq _08056474
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_080a83e4
	strb r6, [r5]
	movs r0, #0x46
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xc7
	movs r0, #1
	b _080564D8
	.align 2, 0
_08056470: .4byte 0x0000B303
_08056474:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	beq _080564A4
	cmp r0, #1
	bgt _08056488
	cmp r0, #0
	beq _08056492
	b _080564D2
_08056488:
	cmp r0, #2
	beq _080564B0
	cmp r0, #3
	beq _080564C2
	b _080564D2
_08056492:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080a83e4
	movs r0, #0x46
	bl PlaySound
	b _080564D2
_080564A4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #6
	bl FUN_080a88a4
	b _080564D2
_080564B0:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080a9048
	movs r0, #0x49
	bl PlaySound
	b _080564D2
_080564C2:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080a9048
	movs r0, #0x46
	bl PlaySound
_080564D2:
	adds r1, r4, #0
	adds r1, #0xc7
	movs r0, #0
_080564D8:
	strb r0, [r1]
_080564DA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056502
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080564FA
	movs r0, #0x14
	b _080564FC
_080564FA:
	movs r0, #0x12
_080564FC:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08056502:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start copyx_08056508
copyx_08056508: @ 0x08056508
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805651E
	ldr r1, _0805653C @ =0x0000B304
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_0805651E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080565AC
	adds r5, r4, #0
	adds r5, #0xcd
	ldrb r0, [r5]
	cmp r0, #0
	beq _08056540
	subs r0, #1
	b _0805659A
	.align 2, 0
_0805653C: .4byte 0x0000B304
_08056540:
	adds r0, r4, #0
	adds r0, #0xc7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805659C
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	bne _0805657C
	ldr r2, _08056570 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08056574 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08056578 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	b _0805659A
	.align 2, 0
_08056570: .4byte RNG_0202f388
_08056574: .4byte 0x000343FD
_08056578: .4byte 0x00269EC3
_0805657C:
	cmp r0, #2
	bne _0805659C
	ldr r2, _080565B4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080565B8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080565BC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
_0805659A:
	strb r0, [r5]
_0805659C:
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #4
	strb r0, [r4, #0x12]
_080565AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080565B4: .4byte RNG_0202f388
_080565B8: .4byte 0x000343FD
_080565BC: .4byte 0x00269EC3

	thumb_func_start copyx_080565c0
copyx_080565c0: @ 0x080565C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805664C
	ldr r1, _0805661C @ =0x0000B307
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r3, #0
	ldr r0, _08056620 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080565E6
	movs r3, #1
_080565E6:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080565F8
	movs r3, #1
_080565F8:
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
	beq _08056624
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805662A
	.align 2, 0
_0805661C: .4byte 0x0000B307
_08056620: .4byte pZero2
_08056624:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805662A:
	strb r0, [r4, #0xa]
	ldr r0, _0805668C @ =0xFFFFFF00
	str r0, [r4, #0x60]
	ldr r2, _08056690 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08056694 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08056698 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	adds r0, #6
	strb r0, [r4, #0x12]
_0805664C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080566A8
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080566A0
	ldr r0, _0805669C @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _080566A0
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080566A0
	movs r0, #0x26
	b _080566A2
	.align 2, 0
_0805668C: .4byte 0xFFFFFF00
_08056690: .4byte RNG_0202f388
_08056694: .4byte 0x000343FD
_08056698: .4byte 0x00269EC3
_0805669C: .4byte gScore
_080566A0:
	movs r0, #0x16
_080566A2:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080566A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start copyx_080566b0
copyx_080566b0: @ 0x080566B0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08056708 @ =u8_ARRAY_080fefb0
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080566D6
	ldr r1, _0805670C @ =0x0000B315
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
_080566D6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x10
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805671C
	movs r0, #0x17
	strb r0, [r4, #0xd]
	movs r1, #1
	strb r1, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08056710
	strb r1, [r4, #0x13]
	b _0805671C
	.align 2, 0
_08056708: .4byte u8_ARRAY_080fefb0
_0805670C: .4byte 0x0000B315
_08056710:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
_0805671C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start copyx_08056724
copyx_08056724: @ 0x08056724
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08056754 @ =u8_ARRAY_080fefb4
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056768
	ldr r1, _08056758 @ =0x0000B316
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805675C
	movs r0, #4
	b _08056766
	.align 2, 0
_08056754: .4byte u8_ARRAY_080fefb4
_08056758: .4byte 0x0000B316
_0805675C:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
_08056766:
	strb r0, [r4, #0x12]
_08056768:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805678C
	movs r0, #0x18
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805678C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start copyx_08056794
copyx_08056794: @ 0x08056794
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08056862
	ldr r1, _080567B8 @ =0x0000B317
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080567C0
	ldr r0, _080567BC @ =0xFFFFFE00
	b _080567C4
	.align 2, 0
_080567B8: .4byte 0x0000B317
_080567BC: .4byte 0xFFFFFE00
_080567C0:
	movs r0, #0x80
	lsls r0, r0, #2
_080567C4:
	str r0, [r4, #0x5c]
	ldr r0, _080567F4 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	adds r5, r4, #0
	adds r5, #0xc6
	ldrb r6, [r5]
	cmp r6, #0
	beq _080567F8
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080a83e4
	movs r1, #0
	strb r1, [r5]
	movs r0, #0xc
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc7
	strb r1, [r0]
	movs r0, #0x46
	bl PlaySound
	b _08056862
	.align 2, 0
_080567F4: .4byte 0xFFFFFE00
_080567F8:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08056822
	cmp r0, #1
	bgt _0805680C
	cmp r0, #0
	beq _08056816
	b _08056862
_0805680C:
	cmp r0, #2
	beq _0805683A
	cmp r0, #3
	beq _08056848
	b _08056862
_08056816:
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080a83e4
	b _08056852
_08056822:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	bl FUN_080a88a4
	movs r0, #0xc
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0xc7
	movs r0, #6
	strb r0, [r1]
	b _08056862
_0805683A:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_080a9048
	movs r0, #0x49
	b _08056854
_08056848:
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	bl FUN_080a9048
_08056852:
	movs r0, #0x46
_08056854:
	bl PlaySound
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc7
	strb r6, [r0]
_08056862:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r1, r4, #0
	adds r1, #0xc7
	ldrb r0, [r1]
	cmp r0, #0
	beq _08056878
	subs r0, #1
	strb r0, [r1]
	b _080568B4
_08056878:
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
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080568B4
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	ands r0, r1
	cmp r0, #0
	bne _080568AC
	movs r0, #0x19
	b _080568AE
_080568AC:
	movs r0, #0x17
_080568AE:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080568B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
