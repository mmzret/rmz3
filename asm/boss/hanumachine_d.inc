	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805c404
FUN_0805c404: @ 0x0805C404
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C476
	ldr r1, _0805C45C @ =0x0000B508
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C460 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C426
	movs r3, #1
_0805C426:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C438
	movs r3, #1
_0805C438:
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
	beq _0805C464
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C46A
	.align 2, 0
_0805C45C: .4byte 0x0000B508
_0805C460: .4byte pZero2
_0805C464:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C46A:
	strb r0, [r4, #0xa]
	ldr r0, _0805C4A0 @ =0xFFFFFB80
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C476:
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
	bne _0805C49A
	movs r1, #0
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C49A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C4A0: .4byte 0xFFFFFB80

	thumb_func_start hanu_0805c4a4
hanu_0805c4a4: @ 0x0805C4A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C4DE
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C4FC @ =0x0000B509
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x58]
	ldr r1, _0805C500 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x30
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C504 @ =0x08364F28
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C4DE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C520
	ldrb r0, [r4, #0x12]
	cmp r0, #0x20
	bne _0805C508
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x50
	b _0805C538
	.align 2, 0
_0805C4FC: .4byte 0x0000B509
_0805C500: .4byte 0xFFFFF000
_0805C504: .4byte 0x08364F28
_0805C508:
	cmp r0, #0x10
	bne _0805C514
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x40
	b _0805C538
_0805C514:
	cmp r0, #0
	bne _0805C558
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x30
	b _0805C538
_0805C520:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x20
	bne _0805C52E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xb0
	b _0805C538
_0805C52E:
	cmp r0, #0x10
	bne _0805C544
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xc0
_0805C538:
	bl hanu_080ad598
	movs r0, #0x51
	bl PlaySound
	b _0805C558
_0805C544:
	cmp r0, #0
	bne _0805C558
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xd0
	bl hanu_080ad598
	movs r0, #0x51
	bl PlaySound
_0805C558:
	ldrb r0, [r4, #0x13]
	adds r0, #0x10
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805C57A
	movs r0, #0xc
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C57A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c580
FUN_0805c580: @ 0x0805C580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C62A
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r6, #1
	ands r2, r6
	movs r1, #2
	bl hanu_080ad598
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805C5FC @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C600 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C5C2
	movs r3, #1
_0805C5C2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C5D4
	movs r3, #1
_0805C5D4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	adds r1, r6, #0
	ands r1, r3
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805C604
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C60A
	.align 2, 0
_0805C5FC: .4byte 0x0000B506
_0805C600: .4byte pZero2
_0805C604:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C60A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C66C @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C62A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805C646
	str r0, [r4, #0x60]
_0805C646:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C666
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805C66C: .4byte 0x08364EC8

	thumb_func_start hanu_0805c670
hanu_0805c670: @ 0x0805C670
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C714
	ldr r1, _0805C6C8 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805C6CC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C692
	movs r3, #1
_0805C692:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805C6A4
	movs r3, #1
_0805C6A4:
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
	beq _0805C6D0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C6D6
	.align 2, 0
_0805C6C8: .4byte 0x0000B506
_0805C6CC: .4byte pZero2
_0805C6D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C6D6:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C6F4
	ldr r0, _0805C6EC @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805C6F0 @ =0xFFFFF000
	b _0805C6FE
	.align 2, 0
_0805C6EC: .4byte 0xFFFFFE80
_0805C6F0: .4byte 0xFFFFF000
_0805C6F4:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805C6FE:
	str r0, [r4, #0x64]
	ldr r0, _0805C75C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	movs r0, #0xe
	strb r0, [r4, #0x12]
	movs r0, #0x50
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C714:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C732
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805C732:
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
	bne _0805C754
	movs r0, #0xe
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C754:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C75C: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805c760
FUN_0805c760: @ 0x0805C760
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C77C
	ldr r1, _0805C7C0 @ =0x0000B50C
	adds r0, r4, #0
	movs r2, #2
	movs r3, #5
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C77C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805C79A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805C79A:
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
	bne _0805C7B8
	movs r1, #0
	movs r0, #0xf
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805C7B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C7C0: .4byte 0x0000B50C

	thumb_func_start hanu_0805c7c4
hanu_0805c7c4: @ 0x0805C7C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805C80E
	ldr r1, _0805C7F8 @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805C7FC @ =0x08364F58
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805C800
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805C806
	.align 2, 0
_0805C7F8: .4byte 0x0000B50D
_0805C7FC: .4byte 0x08364F58
_0805C800:
	ldr r0, _0805C864 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	ldr r0, _0805C868 @ =0xFFFFF000
_0805C806:
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C80E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C874
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C84A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805C84A:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	movs r0, #0x52
	bl PlaySound
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805C86C
	movs r0, #0x10
	b _0805C86E
	.align 2, 0
_0805C864: .4byte 0xFFFFFC00
_0805C868: .4byte 0xFFFFF000
_0805C86C:
	movs r0, #0x11
_0805C86E:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0805C874:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805c87c
FUN_0805c87c: @ 0x0805C87C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805C926
	ldr r1, _0805C8D0 @ =0x0000B50E
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805C8D4 @ =0x08364EC8
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0805C8D8
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805C8DE
	.align 2, 0
_0805C8D0: .4byte 0x0000B50E
_0805C8D4: .4byte 0x08364EC8
_0805C8D8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805C8DE:
	strb r0, [r5, #0xa]
	ldr r0, _0805C918 @ =0xFFFFFB80
	str r0, [r5, #0x60]
	movs r0, #0
	str r0, [r5, #0x5c]
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a31c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805C91C
	adds r4, #4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a22c
	ldr r1, [r4]
	cmp r1, r0
	bne _0805C91C
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r5, #0x58]
	str r1, [r0]
	movs r0, #0xff
	b _0805C91E
	.align 2, 0
_0805C918: .4byte 0xFFFFFB80
_0805C91C:
	movs r0, #0x1b
_0805C91E:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805C926:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	adds r1, #0x40
	str r1, [r5, #0x60]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #0
	cmp r0, #0xff
	bne _0805C972
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, r2
	bgt _0805C986
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C986
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xbe
	strb r1, [r0]
	b _0805C986
_0805C972:
	subs r0, r1, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805C986
	movs r0, #0xe
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
_0805C986:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start hanu_0805c98c
hanu_0805c98c: @ 0x0805C98C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805C9C2
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805CA3C @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x60
	strb r0, [r1]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, _0805CA40 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	strb r5, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805C9C2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CA58
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805C9F2
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805C9F2:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805CA44
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CA4A
	.align 2, 0
_0805CA3C: .4byte 0x0000B50D
_0805CA40: .4byte 0xFFFFFC00
_0805CA44:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CA4A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	rsbs r1, r1, #0
	str r1, [r4, #0x5c]
_0805CA58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CAEA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CA82
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805CA82:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #5
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #5
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #5
	ldrb r2, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805CACC
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _0805CAD2
_0805CACC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0805CAD2:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r1, r1, #0
	str r1, [r4, #0x60]
	cmp r1, #0
	bge _0805CAEA
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0805CAEA:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bls _0805CAF8
	movs r1, #0
	movs r0, #0x12
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CAF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cb00
FUN_0805cb00: @ 0x0805CB00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805CBA6
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805CB24
	movs r1, #1
_0805CB24:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r3, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805CB34
	movs r3, #1
_0805CB34:
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
	beq _0805CB56
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CB5C
_0805CB56:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CB5C:
	strb r0, [r4, #0xa]
	ldr r1, _0805CB8C @ =0x0000B50E
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CB90 @ =0x08364EC8
	bl SetDDP
	ldr r0, _0805CB94 @ =0xFFFFFB80
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CB98
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805CB9E
	.align 2, 0
_0805CB8C: .4byte 0x0000B50E
_0805CB90: .4byte 0x08364EC8
_0805CB94: .4byte 0xFFFFFB80
_0805CB98:
	ldr r0, _0805CBF4 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	ldr r0, _0805CBF8 @ =0xFFFFF000
_0805CB9E:
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CBA6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CBC4
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CBC4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CBEE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CBEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CBF4: .4byte 0xFFFFFE00
_0805CBF8: .4byte 0xFFFFF000

	thumb_func_start hanu_0805cbfc
hanu_0805cbfc: @ 0x0805CBFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CC78
	ldr r1, _0805CC54 @ =0x0000B510
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805CC58 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CC1E
	movs r3, #1
_0805CC1E:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CC30
	movs r3, #1
_0805CC30:
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
	beq _0805CC5C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CC62
	.align 2, 0
_0805CC54: .4byte 0x0000B510
_0805CC58: .4byte pZero2
_0805CC5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CC62:
	strb r0, [r4, #0xa]
	movs r0, #0x50
	bl PlaySound
	movs r1, #0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r1, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CC78:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805CCA0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805CCB2
	ldr r1, _0805CC9C @ =0x0000B511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _0805CCB2
	.align 2, 0
_0805CC9C: .4byte 0x0000B511
_0805CCA0:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805CCB2
	movs r1, #0
	movs r0, #0x14
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CCB2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start hanu_0805ccc0
hanu_0805ccc0: @ 0x0805CCC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CD28
	ldr r1, _0805CCFC @ =0x0000B512
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CD00 @ =0x08364F88
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CD08
	ldr r0, [r4, #0x54]
	ldr r1, _0805CD04 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #6
	b _0805CD18
	.align 2, 0
_0805CCFC: .4byte 0x0000B512
_0805CD00: .4byte 0x08364F88
_0805CD04: .4byte 0xFFFFF000
_0805CD08:
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, _0805CDB0 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	ldr r0, _0805CDB4 @ =0xFFFFD000
_0805CD18:
	str r0, [r4, #0x64]
	ldr r0, _0805CDB0 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CD28:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r6, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0805CDA4
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CD56
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CD56:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	adds r0, r0, r2
	ldr r5, _0805CDB8 @ =0xFFFFE000
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CDAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CD94
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_08010dd8
_0805CD94:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
_0805CDA4:
	movs r0, #0x15
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0805CDAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805CDB0: .4byte 0xFFFFFC00
_0805CDB4: .4byte 0xFFFFD000
_0805CDB8: .4byte 0xFFFFE000

	thumb_func_start FUN_0805cdbc
FUN_0805cdbc: @ 0x0805CDBC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805CDFE
	ldr r1, _0805CDE8 @ =0x0000B513
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805CDEC @ =0x08364EC8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805CDF0
	movs r0, #0x80
	lsls r0, r0, #2
	b _0805CDF2
	.align 2, 0
_0805CDE8: .4byte 0x0000B513
_0805CDEC: .4byte 0x08364EC8
_0805CDF0:
	ldr r0, _0805CE4C @ =0xFFFFFE00
_0805CDF2:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CDFE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CE1C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805CE1C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CE46
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805CE46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CE4C: .4byte 0xFFFFFE00

	thumb_func_start FUN_0805ce50
FUN_0805ce50: @ 0x0805CE50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805CF06
	ldr r1, _0805CEA4 @ =0x0000B506
	adds r0, r5, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805CEA8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CE72
	movs r3, #1
_0805CE72:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805CE84
	movs r3, #1
_0805CE84:
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r2, r3, #4
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	cmp r3, #0
	beq _0805CEAC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805CEB2
	.align 2, 0
_0805CEA4: .4byte 0x0000B506
_0805CEA8: .4byte pZero2
_0805CEAC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805CEB2:
	strb r0, [r5, #0xa]
	ldr r0, _0805CEF4 @ =pZero2
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r0, #0x54]
	ldr r4, [r1]
	subs r0, r0, r4
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r1, r2
	adds r4, r4, r0
	ldr r0, [r5, #0x54]
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x18
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r1, _0805CEF8 @ =0xFFFFFA00
	str r1, [r5, #0x60]
	cmp r0, #0
	ble _0805CEFC
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805CEFE
	.align 2, 0
_0805CEF4: .4byte pZero2
_0805CEF8: .4byte 0xFFFFFA00
_0805CEFC:
	ldr r0, _0805CF54 @ =0xFFFFF000
_0805CEFE:
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805CF06:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x64]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CF24
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805CF24:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805CF3C
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0805CF3C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0
	blt _0805CF4E
	movs r1, #0
	movs r0, #0x17
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805CF4E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805CF54: .4byte 0xFFFFF000

	thumb_func_start hanu_0805cf58
hanu_0805cf58: @ 0x0805CF58
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805CF7C
	ldr r1, _0805CF9C @ =0x0000B514
	bl SetMotion
	movs r0, #0x4e
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	strb r5, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805CF7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	bne _0805CFA0
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0805CFE0
	adds r0, r1, #1
	strb r0, [r4, #0xf]
	b _0805CFE0
	.align 2, 0
_0805CF9C: .4byte 0x0000B514
_0805CFA0:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0805CFC4
	movs r1, #0
	movs r0, #0x18
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805CFE0
_0805CFC4:
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805CFE0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0805CFE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cfe8
FUN_0805cfe8: @ 0x0805CFE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D02C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D00C
	ldr r0, _0805D004 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805D008 @ =0xFFFFF000
	b _0805D016
	.align 2, 0
_0805D004: .4byte 0xFFFFFE80
_0805D008: .4byte 0xFFFFF000
_0805D00C:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D016:
	str r0, [r4, #0x64]
	ldr r0, _0805D07C @ =0xFFFFFC40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl hanu_080ad598
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D02C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D04A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D04A:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D074
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D074:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D07C: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805d080
FUN_0805d080: @ 0x0805D080
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D16C
	ldr r1, _0805D0D4 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _0805D0D8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805D0A2
	movs r3, #1
_0805D0A2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _0805D0B4
	movs r3, #1
_0805D0B4:
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r2, r3, #4
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	cmp r3, #0
	beq _0805D0DC
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805D0E2
	.align 2, 0
_0805D0D4: .4byte 0x0000B506
_0805D0D8: .4byte pZero2
_0805D0DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805D0E2:
	strb r0, [r4, #0xa]
	ldr r0, _0805D128 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r0, #0x54]
	ldr r5, [r1]
	subs r2, r0, r5
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r2, #0
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r2, r1, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D134
	adds r0, r5, r2
	ldr r1, _0805D12C @ =0xFFFFB800
	adds r2, r0, r1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r3, _0805D130 @ =0xFFFFE800
	adds r0, r1, r3
	cmp r2, r0
	ble _0805D148
	b _0805D146
	.align 2, 0
_0805D128: .4byte pZero2
_0805D12C: .4byte 0xFFFFB800
_0805D130: .4byte 0xFFFFE800
_0805D134:
	adds r0, r5, r2
	movs r1, #0x90
	lsls r1, r1, #7
	adds r2, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r5, r3
	cmp r2, r0
	bge _0805D148
_0805D146:
	adds r2, r0, #0
_0805D148:
	ldr r0, [r4, #0x54]
	subs r0, r2, r0
	movs r1, #0x1c
	bl __divsi3
	str r0, [r4, #0x5c]
	cmp r0, #0
	ble _0805D15E
	movs r0, #0x80
	lsls r0, r0, #5
	b _0805D160
_0805D15E:
	ldr r0, _0805D1BC @ =0xFFFFF000
_0805D160:
	str r0, [r4, #0x64]
	ldr r0, _0805D1C0 @ =0xFFFFF900
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D16C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D18A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D18A:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D1A2
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0805D1A2:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	cmp r0, #0
	blt _0805D1B4
	movs r1, #0
	movs r0, #0x1a
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D1B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D1BC: .4byte 0xFFFFF000
_0805D1C0: .4byte 0xFFFFF900

	thumb_func_start FUN_0805d1c4
FUN_0805d1c4: @ 0x0805D1C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0805D1E0
	ldr r1, _0805D20C @ =0x0000B50C
	movs r2, #2
	movs r3, #5
	bl GotoMotion
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D1E0:
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
	bne _0805D204
	movs r1, #0
	movs r0, #0x1b
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D204:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D20C: .4byte 0x0000B50C

	thumb_func_start FUN_0805d210
FUN_0805d210: @ 0x0805D210
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805D268
	adds r0, r4, #0
	bl InitRotatableMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805D250 @ =0x0000B50D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0xe0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805D254 @ =0x08364F58
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D258
	movs r0, #0x80
	lsls r0, r0, #3
	b _0805D25A
	.align 2, 0
_0805D250: .4byte 0x0000B50D
_0805D254: .4byte 0x08364F58
_0805D258:
	ldr r0, _0805D2BC @ =0xFFFFFC00
_0805D25A:
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D268:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0805D2C0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D29A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805D29A:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	movs r1, #0
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0805D308
	.align 2, 0
_0805D2BC: .4byte 0xFFFFFC00
_0805D2C0:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D308
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D2EA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08010dd8
_0805D2EA:
	movs r0, #0x52
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x1c
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0805D308:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d310
FUN_0805d310: @ 0x0805D310
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _0805D376
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _0805D350 @ =0x0000B506
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805D354 @ =sCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D360
	ldr r0, _0805D358 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	ldr r0, _0805D35C @ =0xFFFFF000
	b _0805D36A
	.align 2, 0
_0805D350: .4byte 0x0000B506
_0805D354: .4byte sCollisions
_0805D358: .4byte 0xFFFFFE80
_0805D35C: .4byte 0xFFFFF000
_0805D360:
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D36A:
	str r0, [r4, #0x64]
	ldr r0, _0805D3C4 @ =0xFFFFFC40
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805D376:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0805d594
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D394
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805D394:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D3BE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805D3BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D3C4: .4byte 0xFFFFFC40

	thumb_func_start FUN_0805d3c8
FUN_0805d3c8: @ 0x0805D3C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0805D3D4
	b _0805D4E2
_0805D3D4:
	adds r0, #0x24
	strb r1, [r0]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldr r1, _0805D438 @ =0x0000B502
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805D43C @ =sCollisions
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldrb r1, [r4]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r0, [r4]
	movs r1, #0x4a
	adds r1, r1, r5
	mov ip, r1
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	mov r0, ip
	ldrb r3, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4]
	ands r2, r0
	cmp r2, #0
	beq _0805D440
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805D446
	.align 2, 0
_0805D438: .4byte 0x0000B502
_0805D43C: .4byte sCollisions
_0805D440:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805D446:
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D498
	ldr r0, [r5, #0x54]
	ldr r2, _0805D488 @ =0xFFFFEE00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r2, _0805D48C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D480
	ldr r0, [r5, #0x54]
	ldr r1, _0805D488 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0805D48C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a31c
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D480:
	ldr r0, _0805D490 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldr r0, _0805D494 @ =0xFFFFF000
	b _0805D4D2
	.align 2, 0
_0805D488: .4byte 0xFFFFEE00
_0805D48C: .4byte 0xFFFFF800
_0805D490: .4byte 0xFFFFFE00
_0805D494: .4byte 0xFFFFF000
_0805D498:
	ldr r0, [r5, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r2, _0805D518 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D4C8
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0805D518 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a22c
	ldr r1, _0805D51C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D4C8:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #5
_0805D4D2:
	str r0, [r5, #0x64]
	ldr r0, _0805D520 @ =0xFFFFFC00
	str r0, [r5, #0x60]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805D4E2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	adds r4, r0, r1
	ldr r1, [r5, #0x58]
	adds r0, r4, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805D536
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805D524
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r4, r0
	ble _0805D536
	b _0805D52E
	.align 2, 0
_0805D518: .4byte 0xFFFFF800
_0805D51C: .4byte 0xFFFFEE00
_0805D520: .4byte 0xFFFFFC00
_0805D524:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r4, r0
	bge _0805D536
_0805D52E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0805D536:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, #0x40
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0805D560
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805D560:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

