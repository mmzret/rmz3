	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretistaHellBouncers
tretistaHellBouncers: @ 0x0804F2B8
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xe
	bls _0804F2C6
	b _0804F5A6
_0804F2C6:
	lsls r0, r0, #2
	ldr r1, _0804F2D0 @ =_0804F2D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F2D0: .4byte _0804F2D4
_0804F2D4: @ jump table
	.4byte _0804F310 @ case 0
	.4byte _0804F38C @ case 1
	.4byte _0804F3B8 @ case 2
	.4byte _0804F3D4 @ case 3
	.4byte _0804F3F8 @ case 4
	.4byte _0804F45E @ case 5
	.4byte _0804F480 @ case 6
	.4byte _0804F4A0 @ case 7
	.4byte _0804F4CC @ case 8
	.4byte _0804F4E4 @ case 9
	.4byte _0804F514 @ case 10
	.4byte _0804F54C @ case 11
	.4byte _0804F558 @ case 12
	.4byte _0804F570 @ case 13
	.4byte _0804F588 @ case 14
_0804F310:
	ldr r1, _0804F350 @ =0x0000AB1C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F354 @ =sCollisions+(24*1)
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r0, [r0]
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	cmp r1, r0
	bge _0804F358
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	b _0804F382
	.align 2, 0
_0804F350: .4byte 0x0000AB1C
_0804F354: .4byte sCollisions+(24*1)
_0804F358:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r2, _0804F3B4 @ =0xFFFFCE00
	adds r0, r0, r2
	cmp r1, r0
	ble _0804F382
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
_0804F382:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F38C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F39E
	b _0804F5A6
_0804F39E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F3A6
	b _0804F568
_0804F3A6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F3B2
	b _0804F5A6
_0804F3B2:
	b _0804F568
	.align 2, 0
_0804F3B4: .4byte 0xFFFFCE00
_0804F3B8:
	ldr r1, _0804F3F0 @ =0x0000AB1D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F3F4 @ =0x08363458
	bl SetDDP
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F3D4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F3E2
	b _0804F568
_0804F3E2:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F3EE
	b _0804F5A6
_0804F3EE:
	b _0804F568
	.align 2, 0
_0804F3F0: .4byte 0x0000AB1D
_0804F3F4: .4byte 0x08363458
_0804F3F8:
	ldr r0, [r5, #0x58]
	ldr r1, _0804F474 @ =0xFFFFD500
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	ldr r2, _0804F478 @ =0xFFFFEF00
	adds r0, r0, r2
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	movs r3, #1
	bl createHellBouncer
	adds r4, r5, #0
	adds r4, #0xc8
	str r0, [r4]
	ldr r0, [r5, #0x54]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #1
	movs r3, #0
	bl createHellBouncer
	adds r2, r5, #0
	adds r2, #0xcc
	str r0, [r2]
	ldr r1, [r4]
	str r1, [r0, #0x2c]
	ldr r1, [r4]
	ldr r0, [r2]
	str r0, [r1, #0x2c]
	movs r0, #0xd6
	bl PlaySound
	ldr r1, _0804F47C @ =0x0000AB1A
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F45E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0804F466
	b _0804F558
_0804F466:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F472
	b _0804F5A6
_0804F472:
	b _0804F558
	.align 2, 0
_0804F474: .4byte 0xFFFFD500
_0804F478: .4byte 0xFFFFEF00
_0804F47C: .4byte 0x0000AB1A
_0804F480:
	ldr r1, _0804F4C4 @ =0x0000AB03
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F4C8 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0xff
	strb r0, [r5, #0x12]
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F4A0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F5A6
	b _0804F568
	.align 2, 0
_0804F4C4: .4byte 0x0000AB03
_0804F4C8: .4byte sCollisions+(24*1)
_0804F4CC:
	ldr r1, _0804F50C @ =0x0000AB04
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F510 @ =0x08363458
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F4E4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	movs r1, #2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	strb r1, [r0]
	b _0804F568
	.align 2, 0
_0804F50C: .4byte 0x0000AB04
_0804F510: .4byte 0x08363458
_0804F514:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
	ldr r1, _0804F548 @ =0x0000AB08
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0804F568
	.align 2, 0
_0804F548: .4byte 0x0000AB08
_0804F54C:
	movs r0, #0xd7
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F558:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804F5A6
_0804F568:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804F5A6
_0804F570:
	ldr r1, _0804F5B8 @ =0x0000AB1F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F5BC @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F588:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _0804F5A6
	adds r0, #0x55
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	strb r2, [r5, #0xd]
	strb r1, [r5, #0xe]
_0804F5A6:
	ldrb r1, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xe2
	strb r1, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F5B8: .4byte 0x0000AB1F
_0804F5BC: .4byte sCollisions+(24*1)
