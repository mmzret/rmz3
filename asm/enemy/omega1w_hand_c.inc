	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806b124
FUN_0806b124: @ 0x0806B124
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _0806B132
	b _0806B4C4
_0806B132:
	lsls r0, r0, #2
	ldr r1, _0806B13C @ =_0806B140
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B13C: .4byte _0806B140
_0806B140: @ jump table
	.4byte _0806B1A4 @ case 0
	.4byte _0806B1AE @ case 1
	.4byte _0806B1E8 @ case 2
	.4byte _0806B1FE @ case 3
	.4byte _0806B216 @ case 4
	.4byte _0806B260 @ case 5
	.4byte _0806B2D0 @ case 6
	.4byte _0806B2F6 @ case 7
	.4byte _0806B4C4 @ case 8
	.4byte _0806B4C4 @ case 9
	.4byte _0806B380 @ case 10
	.4byte _0806B3C4 @ case 11
	.4byte _0806B3E0 @ case 12
	.4byte _0806B4C4 @ case 13
	.4byte _0806B4C4 @ case 14
	.4byte _0806B4C4 @ case 15
	.4byte _0806B4C4 @ case 16
	.4byte _0806B4C4 @ case 17
	.4byte _0806B4C4 @ case 18
	.4byte _0806B4C4 @ case 19
	.4byte _0806B3FA @ case 20
	.4byte _0806B430 @ case 21
	.4byte _0806B470 @ case 22
	.4byte _0806B4A8 @ case 23
	.4byte _0806B4AE @ case 24
_0806B1A4:
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B1AE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, _0806B1E0 @ =0xFFFFFD00
	cmp r0, r1
	bge _0806B1C2
	str r1, [r5, #0x60]
_0806B1C2:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B1E4 @ =0xFFFF8600
	adds r0, r0, r2
	cmp r1, r0
	blt _0806B1D8
	b _0806B4C4
_0806B1D8:
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _0806B49C
	.align 2, 0
_0806B1E0: .4byte 0xFFFFFD00
_0806B1E4: .4byte 0xFFFF8600
_0806B1E8:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B1F0
	b _0806B4C4
_0806B1F0:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B1FC
	b _0806B4C4
_0806B1FC:
	b _0806B49C
_0806B1FE:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B2B4 @ =0x08366448
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B216:
	ldr r1, _0806B2B8 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
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
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B2BC @ =0x083664A8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _0806B2C0 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B260:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B2C4 @ =0xFFFF8800
	adds r4, r0, #0
	cmp r2, r1
	bge _0806B27E
	ldr r0, [r5, #0x5c]
	subs r0, #0x40
	str r0, [r5, #0x5c]
	movs r1, #0x80
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0806B27E
	str r1, [r5, #0x5c]
_0806B27E:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r1, _0806B2C8 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r4]
	ldr r0, _0806B2CC @ =0xFFFF8000
	cmp r1, r0
	bge _0806B366
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B360
	movs r0, #6
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B2B4: .4byte sCollisions+(24*1)
_0806B2B8: .4byte 0x00000902
_0806B2BC: .4byte sCollisions+(24*5)
_0806B2C0: .4byte 0xFFFFFE00
_0806B2C4: .4byte 0xFFFF8800
_0806B2C8: .4byte 0xFFFFED00
_0806B2CC: .4byte 0xFFFF8000
_0806B2D0:
	ldr r1, _0806B34C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B350 @ =0x083664A8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _0806B354 @ =0xFFFF8000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B2F6:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B358 @ =0xFFFFF800
	adds r4, r0, #0
	cmp r2, r1
	ble _0806B312
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	str r0, [r5, #0x5c]
	cmp r0, #0x80
	ble _0806B312
	movs r0, #0x80
	str r0, [r5, #0x5c]
_0806B312:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r4, _0806B35C @ =0xFFFFED00
	adds r0, r0, r4
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0806B366
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B360
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B34C: .4byte 0x00000902
_0806B350: .4byte sCollisions+(24*5)
_0806B354: .4byte 0xFFFF8000
_0806B358: .4byte 0xFFFFF800
_0806B35C: .4byte 0xFFFFED00
_0806B360:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B366:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B36E
	b _0806B4C4
_0806B36E:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B37A
	b _0806B4C4
_0806B37A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B380:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B398
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r0, r2
	b _0806B39E
_0806B398:
	ldr r0, [r5, #0x54]
	ldr r1, _0806B3D8 @ =0xFFFFFA00
	adds r0, r0, r1
_0806B39E:
	str r0, [sp]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, _0806B3DC @ =0x0000012D
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #1
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_0809d8a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B3C4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B3CC
	b _0806B4C4
_0806B3CC:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B4C4
	b _0806B49C
	.align 2, 0
_0806B3D8: .4byte 0xFFFFFA00
_0806B3DC: .4byte 0x0000012D
_0806B3E0:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B3F4
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B3F4:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0806B4C4
_0806B3FA:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B428 @ =0x08366448
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _0806B42C @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	b _0806B49C
	.align 2, 0
_0806B428: .4byte sCollisions+(24*1)
_0806B42C: .4byte 0xFFFFED00
_0806B430:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806B4C4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0806B4C4
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B46C @ =sCollisions
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0806B49C
	.align 2, 0
_0806B46C: .4byte sCollisions
_0806B470:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x80
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B486
	str r1, [r5, #0x60]
_0806B486:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B4A4 @ =0xFFFFC600
	adds r0, r0, r2
	cmp r1, r0
	ble _0806B4C4
	str r0, [r5, #0x58]
_0806B49C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806B4C4
	.align 2, 0
_0806B4A4: .4byte 0xFFFFC600
_0806B4A8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B4AE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _0806B4C4
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806B4C4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b4cc
FUN_0806b4cc: @ 0x0806B4CC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _0806B4DA
	b _0806B8C4
_0806B4DA:
	lsls r0, r0, #2
	ldr r1, _0806B4E4 @ =_0806B4E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B4E4: .4byte _0806B4E8
_0806B4E8: @ jump table
	.4byte _0806B54C @ case 0
	.4byte _0806B5B6 @ case 1
	.4byte _0806B60C @ case 2
	.4byte _0806B622 @ case 3
	.4byte _0806B630 @ case 4
	.4byte _0806B676 @ case 5
	.4byte _0806B6E0 @ case 6
	.4byte _0806B706 @ case 7
	.4byte _0806B8C4 @ case 8
	.4byte _0806B8C4 @ case 9
	.4byte _0806B790 @ case 10
	.4byte _0806B7BA @ case 11
	.4byte _0806B7D8 @ case 12
	.4byte _0806B8C4 @ case 13
	.4byte _0806B8C4 @ case 14
	.4byte _0806B8C4 @ case 15
	.4byte _0806B8C4 @ case 16
	.4byte _0806B8C4 @ case 17
	.4byte _0806B8C4 @ case 18
	.4byte _0806B8C4 @ case 19
	.4byte _0806B7F2 @ case 20
	.4byte _0806B85C @ case 21
	.4byte _0806B86E @ case 22
	.4byte _0806B8A8 @ case 23
	.4byte _0806B8AE @ case 24
_0806B54C:
	ldr r1, _0806B600 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r3, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r3, [r0]
	movs r2, #0x20
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B604 @ =0x083664A8
	bl SetDDP
	strb r4, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B5B6:
	ldrb r0, [r5, #0x13]
	cmp r0, #0x3f
	bhi _0806B5C0
	adds r0, #4
	strb r0, [r5, #0x13]
_0806B5C0:
	ldrb r0, [r5, #0x13]
	mvns r0, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B5E0
	str r1, [r5, #0x60]
_0806B5E0:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B608 @ =0xFFFFFE00
	adds r0, r0, r2
	cmp r1, r0
	bgt _0806B5F6
	b _0806B8C4
_0806B5F6:
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _0806B89A
	.align 2, 0
_0806B600: .4byte 0x00000902
_0806B604: .4byte sCollisions+(24*5)
_0806B608: .4byte 0xFFFFFE00
_0806B60C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B614
	b _0806B8C4
_0806B614:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B620
	b _0806B8C4
_0806B620:
	b _0806B89A
_0806B622:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B630:
	ldr r1, _0806B6C8 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
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
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B6CC @ =0x083664A8
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _0806B6D0 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B676:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B6D4 @ =0xFFFFD180
	adds r4, r0, #0
	cmp r2, r1
	bge _0806B694
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	ble _0806B694
	str r1, [r5, #0x60]
_0806B694:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	adds r0, r0, r1
	ldr r1, _0806B6D8 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r4]
	ldr r0, _0806B6DC @ =0xFFFFD000
	cmp r1, r0
	bge _0806B776
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B770
	movs r0, #6
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B6C8: .4byte 0x00000902
_0806B6CC: .4byte sCollisions+(24*5)
_0806B6D0: .4byte 0xFFFFFF00
_0806B6D4: .4byte 0xFFFFD180
_0806B6D8: .4byte 0xFFFFFE00
_0806B6DC: .4byte 0xFFFFD000
_0806B6E0:
	ldr r1, _0806B75C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806B760 @ =0x083664A8
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _0806B764 @ =0xFFFFD000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B706:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0806B768 @ =0xFFFFFE80
	adds r4, r0, #0
	cmp r2, r1
	ble _0806B722
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0x3f
	bgt _0806B722
	movs r0, #0x40
	str r0, [r5, #0x60]
_0806B722:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	adds r0, r0, r1
	ldr r4, _0806B76C @ =0xFFFFFE00
	adds r0, r0, r4
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0806B776
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B770
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B75C: .4byte 0x00000902
_0806B760: .4byte sCollisions+(24*5)
_0806B764: .4byte 0xFFFFD000
_0806B768: .4byte 0xFFFFFE80
_0806B76C: .4byte 0xFFFFFE00
_0806B770:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B776:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B77E
	b _0806B8C4
_0806B77E:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B78A
	b _0806B8C4
_0806B78A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B790:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	ldr r2, _0806B7D0 @ =0xFFFFEE00
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldr r0, _0806B7D4 @ =0x0000012D
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_0809d904
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B7BA:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B7C2
	b _0806B8C4
_0806B7C2:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B8C4
	b _0806B89A
	.align 2, 0
_0806B7D0: .4byte 0xFFFFEE00
_0806B7D4: .4byte 0x0000012D
_0806B7D8:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B7EC
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B7EC:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0806B8C4
_0806B7F2:
	ldr r1, _0806B854 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _0806B858 @ =0x08366478
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x32
	strb r0, [r5, #0x12]
	b _0806B89A
	.align 2, 0
_0806B854: .4byte 0x00000901
_0806B858: .4byte sCollisions+(24*3)
_0806B85C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806B8C4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806B8C4
	b _0806B89A
_0806B86E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	subs r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0806B884
	str r1, [r5, #0x60]
_0806B884:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0806B8A4 @ =0xFFFFC800
	adds r0, r0, r2
	cmp r1, r0
	bge _0806B8C4
	str r0, [r5, #0x58]
_0806B89A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0806B8C4
	.align 2, 0
_0806B8A4: .4byte 0xFFFFC800
_0806B8A8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806B8AE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _0806B8C4
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806B8C4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

