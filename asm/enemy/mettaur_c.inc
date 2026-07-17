	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080892c4
FUN_080892c4: @ 0x080892C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080892D4
	cmp r0, #1
	beq _080892F2
	b _08089358
_080892D4:
	str r0, [r4, #0x5c]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089300 @ =0x08368814
	bl SetDDP
	ldr r1, _08089304 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080892F2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08089308
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r3, [r4, #0x54]
	b _08089338
	.align 2, 0
_08089300: .4byte sCollisions
_08089304: .4byte 0x0000DD02
_08089308:
	ldr r0, _08089320 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r1, r2, r0
	adds r3, r0, #0
	cmp r1, #0
	blt _08089328
	ldr r0, _08089324 @ =0x00005FFF
	cmp r1, r0
	ble _08089330
	b _08089338
	.align 2, 0
_08089320: .4byte pZero2
_08089324: .4byte 0x00005FFF
_08089328:
	subs r1, r3, r2
	ldr r0, _08089360 @ =0x00005FFF
	cmp r1, r0
	bgt _08089338
_08089330:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089338:
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r0, r3, #0
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
	adds r0, r4, #0
	bl UpdateEntityAnim
_08089358:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089360: .4byte 0x00005FFF

	thumb_func_start FUN_08089364
FUN_08089364: @ 0x08089364
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089374
	cmp r0, #1
	beq _080893FE
	b _0808949E
_08089374:
	movs r2, #0
	ldr r0, _08089394 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08089386
	movs r2, #1
_08089386:
	adds r5, r2, #0
	cmp r5, #0
	beq _08089398
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808939E
	.align 2, 0
_08089394: .4byte pZero2
_08089398:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808939E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r6, #0
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
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #0xa
	ldr r0, _080893E8 @ =0xFFFFF600
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080893EC @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080893F0
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
	adds r0, r4, #0
	bl FUN_080892c4
	b _0808949E
	.align 2, 0
_080893E8: .4byte 0xFFFFF600
_080893EC: .4byte 0xFFFFF800
_080893F0:
	ldr r1, _0808942C @ =0x0000DD03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080893FE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089484
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r3, r1, r0
	lsrs r2, r3, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08089430
	cmp r2, #0
	beq _08089434
	b _0808944E
	.align 2, 0
_0808942C: .4byte 0x0000DD03
_08089430:
	cmp r2, #0
	beq _0808944E
_08089434:
	adds r1, r3, #0
	cmp r1, #0
	bge _0808943C
	rsbs r1, r1, #0
_0808943C:
	movs r0, #0xe0
	lsls r0, r0, #7
	cmp r1, r0
	ble _0808944E
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0808949E
_0808944E:
	ldr r2, _08089470 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08089474 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08089478 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _0808947C
	movs r1, #0
	movs r0, #3
	b _08089480
	.align 2, 0
_08089470: .4byte RNG_0202f388
_08089474: .4byte 0x000343FD
_08089478: .4byte 0x00269EC3
_0808947C:
	movs r1, #0
	movs r0, #4
_08089480:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089484:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
_0808949E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080894a4
FUN_080894a4: @ 0x080894A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bhi _08089578
	lsls r0, r0, #2
	ldr r1, _080894B8 @ =_080894BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080894B8: .4byte _080894BC
_080894BC: @ jump table
	.4byte _080894DC @ case 0
	.4byte _080894EA @ case 1
	.4byte _08089504 @ case 2
	.4byte _08089512 @ case 3
	.4byte _0808952C @ case 4
	.4byte _0808953A @ case 5
	.4byte _08089554 @ case 6
	.4byte _08089562 @ case 7
_080894DC:
	ldr r1, _08089500 @ =0x0000DD01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080894EA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089500: .4byte 0x0000DD01
_08089504:
	ldr r1, _08089528 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089512:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089528: .4byte 0x0000DD02
_0808952C:
	ldr r1, _08089550 @ =0x0000DD0D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808953A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089550: .4byte 0x0000DD0D
_08089554:
	ldr r1, _08089598 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089562:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	movs r0, #0
	strb r0, [r4, #0xd]
_08089576:
	strb r0, [r4, #0xe]
_08089578:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089598: .4byte 0x0000DD02

	thumb_func_start FUN_0808959c
FUN_0808959c: @ 0x0808959C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080895AC
	cmp r0, #1
	beq _080895F0
	b _08089688
_080895AC:
	ldr r0, _08089614 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080895C4
	movs r2, #0xc0
	lsls r2, r2, #1
_080895C4:
	str r2, [r4, #0x5c]
	ldr r0, _08089618 @ =0xFFFFF600
	str r0, [r4, #0x64]
	cmp r1, #0
	beq _080895D2
	movs r0, #0xa0
	lsls r0, r0, #4
_080895D2:
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808961C @ =0x08368844
	bl SetDDP
	ldr r1, _08089620 @ =0x0000DD05
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080895F0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r3, r1, r0
	lsrs r2, r3, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08089624
	cmp r2, #0
	beq _08089628
	b _08089642
	.align 2, 0
_08089614: .4byte 0xFFFFFE80
_08089618: .4byte 0xFFFFF600
_0808961C: .4byte sCollisions+(2*24)
_08089620: .4byte 0x0000DD05
_08089624:
	cmp r2, #0
	beq _08089642
_08089628:
	adds r1, r3, #0
	cmp r1, #0
	bge _08089630
	rsbs r1, r1, #0
_08089630:
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _08089642
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08089688
_08089642:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089664
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08089690 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808966C
_08089664:
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0808966C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
_08089688:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089690: .4byte 0xFFFFF800

	thumb_func_start FUN_08089694
FUN_08089694: @ 0x08089694
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080896A6
	cmp r0, #1
	beq _08089710
	b _0808977E
_080896A6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080896D8 @ =0x08368844
	bl SetDDP
	ldr r1, _080896DC @ =0x0000DD04
	adds r0, r5, #0
	bl SetMotion
	movs r2, #0
	ldr r0, _080896E0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080896CA
	movs r2, #1
_080896CA:
	cmp r2, #0
	beq _080896E4
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080896EA
	.align 2, 0
_080896D8: .4byte sCollisions+(2*24)
_080896DC: .4byte 0x0000DD04
_080896E0: .4byte pZero2
_080896E4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080896EA:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
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
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089710:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne _08089752
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldr r1, [r5, #0x54]
	ldr r0, _08089788 @ =0xFFFFFA00
	adds r1, r1, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #0xa
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808978C @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #2
	lsls r4, r4, #7
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_08089752:
	ldrb r1, [r5, #0x12]
	cmp r1, #0
	bne _0808975E
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808975E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r5, #0
	bl FUN_08088bc8
	adds r0, r5, #0
	bl UpdateEntityAnim
_0808977E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089788: .4byte 0xFFFFFA00
_0808978C: .4byte 0xFFFFFE00

	thumb_func_start FUN_08089790
FUN_08089790: @ 0x08089790
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0808979C
	b _080898B2
_0808979C:
	lsls r0, r0, #2
	ldr r1, _080897A8 @ =_080897AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080897A8: .4byte _080897AC
_080897AC: @ jump table
	.4byte _080897C4 @ case 0
	.4byte _080897E0 @ case 1
	.4byte _08089830 @ case 2
	.4byte _0808983E @ case 3
	.4byte _08089874 @ case 4
	.4byte _08089882 @ case 5
_080897C4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089828 @ =0x08368814
	bl SetDDP
	ldr r1, _0808982C @ =0x0000DD01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080897E0:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08088bc8
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _080897F8
	adds r0, #0xff
_080897F8:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808980C
	str r1, [r4, #0x60]
_0808980C:
	adds r0, r4, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808981E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808981E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080898B2
	.align 2, 0
_08089828: .4byte sCollisions
_0808982C: .4byte 0x0000DD01
_08089830:
	ldr r1, _08089870 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808983E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089854
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089854:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl FUN_08088bc8
	b _080898B2
	.align 2, 0
_08089870: .4byte 0x0000DD02
_08089874:
	ldr r1, _080898B8 @ =0x0000DD0D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089882:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089898
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08089898:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl FUN_08088bc8
_080898B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080898B8: .4byte 0x0000DD0D

	thumb_func_start FUN_080898bc
FUN_080898bc: @ 0x080898BC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _080898CE
	cmp r4, #1
	beq _080898F2
	b _080899EA
_080898CE:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808994C @ =0x08368844
	bl SetDDP
	ldr r1, _08089950 @ =0x0000DD06
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0x78
	strh r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080898F2:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r2, [r6, #0x12]
	adds r3, r2, #0
	cmp r2, #0
	bne _08089908
	ldrb r0, [r6, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r6, #0x13]
_08089908:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _08089958
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r4, r0, r1
	ldr r3, _08089954 @ =gSineTable
	movs r1, #0x80
	subs r1, r1, r2
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	b _0808998A
	.align 2, 0
_0808994C: .4byte sCollisions+(2*24)
_08089950: .4byte 0x0000DD06
_08089954: .4byte gSineTable
_08089958:
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r5, _080899F4 @ =0xFFFFE800
	adds r4, r0, r5
	ldr r2, _080899F8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
_0808998A:
	lsls r0, r0, #5
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080899E4
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0x2c
	bl PlaySound
	ldr r0, [r6, #0x54]
	ldr r2, _080899FC @ =0xFFFFF800
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r6, #0x58]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r5, #0x80
	lsls r5, r5, #2
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xe0
	bl CreateLemon
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xa0
	bl CreateLemon
_080899E4:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080899EA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080899F4: .4byte 0xFFFFE800
_080899F8: .4byte gSineTable
_080899FC: .4byte 0xFFFFF800

