	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08000784
FUN_08000784: @ 0x08000784
	push {r7, lr}
	ldr r7, _08000794 @ =0x02000D50
	ldr r0, [r7, #0x48]
	movs r1, #3
	ands r0, r1
	movs r0, r0
	tst r0, r0
	pop {r7, pc}
	.align 2, 0
_08000794: .4byte 0x02000D50

	thumb_func_start FUN_08000798
FUN_08000798: @ 0x08000798
	push {lr}
	ldr r0, _0800087C @ =0x02000D50
	movs r1, #0x58
	bl clearMemory16
	ldr r0, _08000880 @ =0x020010B0
	movs r1, #0x10
	bl clearMemory16
	ldr r0, _08000884 @ =0x02000CD0
	movs r1, #0x40
	bl clearMemory16
	pop {pc}

	thumb_func_start FUN_080007b4
FUN_080007b4: @ 0x080007B4
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r7, _0800087C @ =0x02000D50
	adds r0, r7, #6
	ldr r1, _08000880 @ =0x020010B0
	ldr r2, _08000884 @ =0x02000CD0
	bl LinkMain1
	str r0, [r7, #0x48]
	sub sp, #0x10
	str r0, [sp]
	bl GetLinkState
	cmp r0, #1
	bne _080007D8
	movs r1, #1
	strb r1, [r7, #6]
	b _080007F0
_080007D8:
	cmp r0, #2
	bne _080007F0
	ldrb r2, [r7, #7]
	cmp r2, #2
	bne _080007E8
	movs r0, #0xff
	strb r0, [r7, #7]
	b _080007F0
_080007E8:
	strb r0, [r7, #7]
	movs r1, #1
	strb r1, [r7, #6]
	b _080007F0
_080007F0:
	ldr r0, [sp]
	movs r1, #3
	ands r0, r1
	movs r0, r0
	str r0, [sp, #4]
	ldr r0, [sp]
	movs r1, #0x1c
	ands r0, r1
	lsrs r0, r0, #2
	str r0, [sp, #8]
	strb r0, [r7, #4]
	ldr r0, [sp]
	movs r1, #0x20
	ands r0, r1
	beq _08000858
	ldr r0, [sp, #8]
	cmp r0, #2
	blt _0800081C
	ldr r0, [sp]
	movs r1, #0x40
	ands r0, r1
	bne _0800082A
_0800081C:
	ldr r0, [sp]
	movs r1, #0x20
	lsls r1, r1, #0x10
	ands r0, r1
	beq _08000860
	movs r6, #4
	b _08000866
_0800082A:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_08000888
	adds r6, r0, #0
	cmp r6, #2
	bne _08000866
	ldr r7, [sp, #8]
	bl Call_Jt_0800980
	tst r0, r0
	beq _08000866
	cmp r0, #2
	bne _0800084C
	movs r6, #0x10
	b _08000866
_0800084C:
	cmp r0, #0x20
	bne _08000854
	movs r6, #4
	b _08000866
_08000854:
	movs r6, #8
	b _08000866
_08000858:
	ldr r0, [sp]
	movs r1, #0x40
	ands r0, r1
	bne _0800082A
_08000860:
	movs r0, #3
	bl FUN_08000f64
_08000866:
	add sp, #0x10
	cmp r6, #4
	bne _08000876
	ldr r0, _0800087C @ =0x02000D50
	ldrb r1, [r0, #5]
	tst r1, r1
	beq _08000876
	movs r6, #4
_08000876:
	adds r0, r6, #0
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0800087C: .4byte 0x02000D50
_08000880: .4byte 0x020010B0
_08000884: .4byte 0x02000CD0

	thumb_func_start FUN_08000888
FUN_08000888: @ 0x08000888
	push {r4, r5, r6, r7, lr}
	bl Call_Jt_080008f0
	bl FUN_08000e28
	movs r1, #0x7f
	ands r1, r0
	bne _080008A8
	movs r1, #0x80
	ands r1, r0
	beq _080008B2
	movs r6, #8
	movs r0, #0
	bl FUN_08000f64
	b _080008C8
_080008A8:
	movs r6, #4
	movs r0, #1
	bl FUN_08000f64
	b _080008C8
_080008B2:
	movs r0, #2
	bl FUN_08000f64
	movs r6, #2
	movs r0, #4
	bl FUN_08000ef4
	tst r1, r1
	bne _080008C8
	bl FUN_08000f28
_080008C8:
	adds r0, r6, #0
	pop {r4, r5, r6, r7, pc}

	thumb_func_start Call_Jt_080008f0
Call_Jt_080008f0: @ 0x080008CC
	push {r0, r4, r5, r6, r7, lr}
	mov r0, r8
	mov r3, sb
	push {r0, r3}
	ldr r5, _08000900 @ =0x020010B0
	ldr r7, _08000904 @ =0x02000D50
	ldr r1, _080008EC @ =0x080008F0
	ldrb r0, [r7]
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_080008E2:
	.byte 0x09, 0xBC, 0x80, 0x46, 0x99, 0x46, 0xF1, 0xBD, 0x00, 0x00
_080008EC: .4byte _080008F0
_080008F0:
	.4byte FUN_08000908
	.4byte FUN_08000920
	.4byte FUN_08000934
	.4byte FUN_08000944
_08000900: .4byte 0x020010B0
_08000904: .4byte 0x02000D50

	thumb_func_start FUN_08000908
FUN_08000908: @ 0x08000908
	push {lr}
	ldr r0, [r7, #0x1c]
	str r0, [r5, #4]
	ldrh r0, [r7, #0xa]
	strh r0, [r5, #2]
	ldr r0, [r7, #0x44]
	str r0, [r5, #0xc]
	ldr r0, [r7, #0x20]
	str r0, [r5, #8]
	movs r0, #0x60
	strh r0, [r5]
	pop {pc}

	thumb_func_start FUN_08000920
FUN_08000920: @ 0x08000920
	push {lr}
	ldr r0, [r7, #0x34]
	movs r4, #0x10
	movs r2, #0
_08000928:
	ldrh r3, [r0, r2]
	strh r3, [r5, r2]
	adds r2, #2
	cmp r2, r4
	blt _08000928
	pop {pc}

	thumb_func_start FUN_08000934
FUN_08000934: @ 0x08000934
	push {lr}
	ldrh r0, [r7, #0xa]
	strh r0, [r5, #2]
	ldrh r0, [r7, #0x1c]
	strh r0, [r5, #4]
	movs r0, #0x62
	strh r0, [r5]
	pop {pc}

	thumb_func_start FUN_08000944
FUN_08000944: @ 0x08000944
	push {lr}
	ldr r0, [r7, #0x54]
	subs r0, #1
	str r0, [r7, #0x54]
	bne _08000952
	movs r0, #4
	strb r0, [r7]
_08000952:
	ldr r0, [r7, #0x34]
	movs r4, #0x10
	movs r2, #0
_08000958:
	movs r3, #0
	strh r3, [r5, r2]
	adds r2, #2
	cmp r2, r4
	blt _08000958
	pop {pc}

	thumb_func_start Call_Jt_0800980
Call_Jt_0800980: @ 0x08000964
	push {r4, r5, r6, r7, lr}
	ldr r5, _0800098C @ =0x02000CD0
	ldr r6, _08000990 @ =0x02000D50
	movs r0, #1
	strb r0, [r6, #5]
	ldr r1, _0800097C @ =0x08000980
	ldrb r0, [r6, #1]
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_08000978:
	.byte 0xF0, 0xBD, 0x00, 0x00
_0800097C: .4byte _08000980
_08000980:
	.4byte FUN_08000994
	.4byte FUN_08000c64
	.4byte FUN_08000de0
_0800098C: .4byte 0x02000CD0
_08000990: .4byte 0x02000D50

	thumb_func_start FUN_08000994
FUN_08000994: @ 0x08000994
	push {lr}
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	ldr r1, _080009A4 @ =0x080009A8
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_080009A2:
	.byte 0x00, 0xBD
_080009A4: .4byte _080009A8
_080009A8:
	.4byte nop_080009b8
	.4byte Call_Jt_080009d4
	.4byte FUN_08000b2c
	.4byte nop_080009b8

	thumb_func_start nop_080009b8
nop_080009b8: @ 0x080009B8
	push {lr}
	pop {pc}

	thumb_func_start Call_Jt_080009d4
Call_Jt_080009d4: @ 0x080009BC
	push {r4, r5, r6, r7, lr}
	ldr r4, _080009CC @ =0x020014C0
	ldrb r0, [r4, #1]
	ldr r1, _080009D0 @ =0x080009D4
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_080009CA:
	.byte 0xF0, 0xBD
_080009CC: .4byte 0x020014C0
_080009D0: .4byte _080009D4
_080009D4:
	.4byte FUN_080009dc
	.4byte FUN_08000a78

	thumb_func_start FUN_080009dc
FUN_080009dc: @ 0x080009DC
	push {lr}
	movs r3, #2
	movs r0, #4
	muls r3, r0, r3
	sub sp, #0x10
	str r3, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	bl FUN_08000ffc
	bgt _08000A68
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #0
	muls r1, r3, r1
_080009FC:
	ldrh r0, [r4, r1]
	cmp r0, #0x62
	beq _08000A5E
	cmp r0, #0x60
	bne _08000A68
	adds r4, #2
	subs r2, #1
	bgt _080009FC
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #1
	muls r1, r3, r1
	ldr r5, _08000A70 @ =0x08000A74
	movs r6, #0
_08000A18:
	ldrh r0, [r4, r1]
	ldrh r3, [r5, r6]
	ands r3, r0
	beq _08000A68
	adds r4, #2
	adds r6, #2
	subs r2, #1
	bgt _08000A18
	ldr r1, [sp, #4]
	strh r0, [r1, #4]
	ldr r5, [sp, #8]
	ldr r6, [sp, #0xc]
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #2
	ldr r3, [sp]
	muls r1, r3, r1
_08000A3A:
	push {r1}
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, [r6, #0x1c]
	cmp r0, r1
	pop {r1}
	bne _08000A68
	adds r4, #2
	subs r2, #1
	bgt _08000A3A
	movs r0, #1
	strh r0, [r6, #0xe]
_08000A58:
	add sp, #0x10
	movs r0, #0
	pop {pc}
_08000A5E:
	movs r0, #8
	strb r0, [r6]
	bl sio_0800100c
	b _08000A58
_08000A68:
	add sp, #0x10
	movs r0, #1
	pop {pc}
	.align 2, 0
_08000A70: .4byte _08000A74
_08000A74:
	.byte 0x00, 0x20, 0x00, 0x10

	thumb_func_start FUN_08000a78
FUN_08000a78: @ 0x08000A78
	push {lr}
	movs r3, #2
	movs r0, #4
	muls r3, r0, r3
	sub sp, #0x10
	str r3, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #0
	muls r1, r3, r1
_08000A92:
	ldrh r0, [r4, r1]
	cmp r0, #0x62
	beq _08000B16
	cmp r0, #0x60
	bne _08000B20
	adds r4, #2
	subs r2, #1
	bgt _08000A92
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #1
	muls r1, r3, r1
_08000AAA:
	ldrh r0, [r4, r1]
	ldr r3, _08000B28 @ =0x00001000
	ands r0, r3
	beq _08000B20
	adds r4, #2
	subs r2, #1
	bgt _08000AAA
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #2
	ldr r3, [sp]
	muls r1, r3, r1
_08000AC2:
	push {r1}
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, [r6, #0x1c]
	cmp r0, r1
	pop {r1}
	bne _08000B20
	adds r4, #2
	subs r2, #1
	bgt _08000AC2
	adds r4, r5, #0
	movs r1, #4
	muls r1, r3, r1
	adds r4, #2
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r6, #0x20]
	adds r4, r5, #0
	movs r1, #6
	muls r1, r3, r1
	adds r4, #2
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r6, #0x40]
	ldrb r0, [r6, #1]
	adds r0, #4
	strb r0, [r6, #1]
	strb r0, [r6]
	movs r0, #2
	strh r0, [r6, #0xe]
_08000B10:
	add sp, #0x10
	movs r0, #0
	pop {pc}
_08000B16:
	movs r0, #8
	strb r0, [r6]
	bl sio_0800100c
	b _08000B10
_08000B20:
	add sp, #0x10
	movs r0, #1
	pop {pc}
	.align 2, 0
_08000B28: .4byte 0x00001000

	thumb_func_start FUN_08000b2c
FUN_08000b2c: @ 0x08000B2C
	push {r4, r5, r6, r7, lr}
	ldr r4, _08000B3C @ =0x020014C0
	ldrb r0, [r4, #1]
	ldr r1, _08000B40 @ =0x08000B44
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_08000B3A:
	.byte 0xF0, 0xBD
_08000B3C: .4byte 0x020014C0
_08000B40: .4byte _08000B44
_08000B44: .4byte FUN_08000b48

	thumb_func_start FUN_08000b48
FUN_08000b48: @ 0x08000B48
	push {r4, r5, r6, r7, lr}
	movs r3, #2
	movs r0, #4
	muls r3, r0, r3
	sub sp, #0x14
	str r7, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r4, #0
	movs r7, #0
_08000B60:
	adds r0, r4, #0
	bl FUN_0800309c
	cmp r0, #1
	bne _08000B6C
	adds r7, #1
_08000B6C:
	cmp r0, #0
	beq _08000C4E
	adds r4, #1
	ldr r0, [sp]
	cmp r4, r0
	blt _08000B60
	cmp r7, #2
	bne _08000C4E
	ldr r7, [sp]
	adds r4, r5, #0
	movs r1, #0
	ldr r3, [sp, #0x10]
	muls r1, r3, r1
	movs r2, #0
_08000B88:
	adds r0, r2, #0
	bl FUN_08000e94
	beq _08000B9A
	ldrh r0, [r4, r1]
	cmp r0, #0x62
	beq _08000C44
	cmp r0, #0x60
	bne _08000C4E
_08000B9A:
	adds r4, #2
	adds r2, #1
	cmp r2, r7
	blt _08000B88
	adds r4, r5, #0
	movs r1, #2
	ldr r3, [sp, #0x10]
	muls r1, r3, r1
	movs r2, #0
_08000BAC:
	adds r0, r2, #0
	bl FUN_08000e94
	beq _08000BC8
	push {r1}
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, [r6, #0x1c]
	cmp r0, r1
	pop {r1}
	bne _08000C4E
_08000BC8:
	adds r4, #2
	adds r2, #1
	cmp r2, r7
	blt _08000BAC
	adds r4, r5, #0
	adds r2, r7, #0
	movs r1, #1
	ldr r3, [sp, #0x10]
	muls r1, r3, r1
	movs r2, #0
_08000BDC:
	adds r0, r2, #0
	bl FUN_08000e94
	beq _08000BEC
	ldrh r0, [r4, r1]
	ldrh r3, [r6, #0xa]
	cmp r0, r3
	bne _08000C54
_08000BEC:
	adds r4, #2
	adds r2, #1
	cmp r2, r7
	blt _08000BDC
	adds r4, r5, #0
	movs r1, #4
	ldr r3, [sp, #0x10]
	muls r1, r3, r1
	adds r0, r4, #0
	bl FUN_08001024
	adds r4, r0, #0
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r6, #0x20]
	adds r4, r5, #0
	movs r1, #6
	ldr r3, [sp, #0x10]
	muls r1, r3, r1
	adds r0, r4, #0
	bl FUN_08001024
	adds r4, r0, #0
	ldrh r0, [r4, r1]
	adds r1, r1, r3
	ldrh r1, [r4, r1]
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r6, #0x40]
	ldrb r0, [r6, #1]
	adds r0, #4
	strb r0, [r6, #1]
	strb r0, [r6]
	movs r0, #2
	strh r0, [r6, #0xe]
	movs r0, #0
	strh r0, [r6, #0x1c]
	str r0, [r6, #0x30]
	add sp, #0x14
	movs r0, #0
	pop {r4, r5, r6, r7, pc}
_08000C44:
	movs r0, #8
	strb r0, [r6]
	bl sio_0800100c
	b _08000BDC
_08000C4E:
	add sp, #0x14
	movs r0, #1
	pop {r4, r5, r6, r7, pc}
_08000C54:
	add sp, #0x14
	movs r0, #2
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08000C5C: .4byte _08000C60
_08000C60: .byte 0x00, 0x20, 0x00, 0x10

	thumb_func_start FUN_08000c64
FUN_08000c64: @ 0x08000C64
	push {lr}
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	ldr r1, _08000C74 @ =0x08000C78
	ldr r0, [r1, r0]
	mov lr, pc
	bx r0
_08000C72:
	.byte 0x00, 0xBD
_08000C74: .4byte _08000C78
_08000C78:
	.4byte FUN_08000c88
	.4byte FUN_08000ce0
	.4byte FUN_08000d70
	.4byte FUN_08000c88

	thumb_func_start FUN_08000c88
FUN_08000c88: @ 0x08000C88
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r1, #0
	movs r2, #4
_08000C98:
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	bl FUN_08000e94
	beq _08000CB0
	cmp r2, #4
	bne _08000CAC
	str r1, [sp, #4]
	b _08000CAE
_08000CAC:
	str r1, [sp, #8]
_08000CAE:
	adds r2, #4
_08000CB0:
	adds r1, #2
	cmp r1, #8
	blt _08000C98
	ldr r3, [r6, #0x38]
	ldr r4, [r6, #0x3c]
	ldr r7, [r6, #0x20]
	movs r0, #2
	movs r1, #4
	muls r0, r1, r0
_08000CC2:
	ldr r1, [sp, #4]
	ldrh r2, [r5, r1]
	strh r2, [r3]
	ldr r1, [sp, #8]
	ldrh r2, [r5, r1]
	strh r2, [r4]
	adds r5, r5, r0
	adds r3, #2
	adds r4, #2
	subs r7, #2
	bgt _08000CC2
	add sp, #0x10
	movs r0, #0
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start FUN_08000ce0
FUN_08000ce0: @ 0x08000CE0
	push {r4, r5, r6, r7, lr}
	ldr r4, _08000D4C @ =0x020014C0
	ldrb r0, [r4]
	tst r0, r0
	bne _08000D46
	adds r5, #2
	ldrb r0, [r4, #2]
	tst r0, r0
	bne _08000D04
	ldrh r2, [r5]
	cmp r2, #0x61
	bne _08000D46
	movs r0, #1
	strb r0, [r4, #2]
	movs r0, #0
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r6, #0x28]
_08000D04:
	movs r1, #0x38
	adds r1, r1, r6
	ldr r2, [r1]
	movs r1, #0xe
	ldr r7, [r6, #0x28]
	movs r3, #2
	movs r0, #4
	muls r3, r0, r3
	adds r5, r5, r3
_08000D16:
	bl FUN_08000d50
	adds r5, r5, r3
	adds r7, #2
	subs r1, #2
	bgt _08000D16
	str r7, [r6, #0x28]
	ldr r0, [r6, #0x20]
	cmp r7, r0
	blt _08000D46
	ldr r0, [r6, #0x40]
	ldr r1, [r4, #8]
	cmp r0, r1
	beq _08000D3E
	movs r0, #8
	strb r0, [r6, #1]
	movs r0, #4
	strh r0, [r6, #0xe]
	movs r0, #1
	pop {r4, r5, r6, r7, pc}
_08000D3E:
	movs r0, #8
	strb r0, [r6, #1]
	movs r0, #4
	strh r0, [r6, #0xe]
_08000D46:
	movs r0, #0
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08000D4C: .4byte 0x020014C0

	thumb_func_start FUN_08000d50
FUN_08000d50: @ 0x08000D50
	push {r0, r1, r2, r3, r4, r5, r6, r7, lr}
	movs r3, #0
	ldr r0, [r6, #0x28]
	tst r0, r0
	bne _08000D5C
	ldrb r0, [r5, r3]
_08000D5C:
	ldrb r0, [r5, r3]
	strb r0, [r2, r7]
	ldr r1, [r4, #8]
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r7, #1
	adds r3, #1
	cmp r3, #2
	blt _08000D5C
	pop {r0, r1, r2, r3, r4, r5, r6, r7, pc}

	thumb_func_start FUN_08000d70
FUN_08000d70: @ 0x08000D70
	push {r4, r5, r6, r7, lr}
	adds r0, r5, #0
	bl FUN_08001024
	adds r5, r0, #0
	ldr r7, _08000DD8 @ =0x020014C0
	ldrb r0, [r7, #2]
	tst r0, r0
	bne _08000D96
	ldrh r2, [r5]
	cmp r2, #0x61
	beq _08000D8C
	movs r0, #0
	b _08000DD6
_08000D8C:
	movs r0, #1
	strb r0, [r7, #2]
	movs r0, #0
	str r0, [r7, #8]
	str r0, [r6, #0x28]
_08000D96:
	movs r4, #0x38
	bl FUN_08000784
	tst r0, r0
	beq _08000DA2
	movs r4, #0x3c
_08000DA2:
	adds r1, r4, r6
	ldr r2, [r1]
	movs r1, #0xe
	ldr r7, [r6, #0x28]
	movs r3, #2
	movs r0, #4
	muls r3, r0, r3
	adds r5, r5, r3
	ldr r4, _08000DD8 @ =0x020014C0
_08000DB4:
	bl FUN_08000d50
	adds r5, r5, r3
	adds r7, #2
	subs r1, #2
	bgt _08000DB4
	movs r2, #0
	ldr r0, [r6, #0x40]
	ldr r1, [r4, #8]
	cmp r0, r1
	beq _08000DCC
	movs r2, #0x20
_08000DCC:
	adds r0, r2, #0
	movs r0, #8
	strb r0, [r6, #1]
	movs r0, #4
	strh r0, [r6, #0xe]
_08000DD6:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08000DD8: .4byte 0x020014C0

	thumb_func_start FUN_08000ddc
FUN_08000ddc: @ 0x08000DDC
	push {lr}
	pop {pc}

	thumb_func_start FUN_08000de0
FUN_08000de0: @ 0x08000DE0
	push {lr}
	sub sp, #0x10
	movs r0, #0
	str r0, [sp]
	ldrb r0, [r6, #8]
	tst r0, r0
	bne _08000E16
	movs r3, #2
	movs r1, #4
	muls r3, r1, r3
_08000DF4:
	adds r2, r5, #0
	ldr r0, [sp]
	adds r0, #1
	bl FUN_08000e94
	beq _08000E06
	ldrh r0, [r2]
	cmp r0, #0x62
	bne _08000E20
_08000E06:
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	adds r5, #2
	subs r7, #1
	bgt _08000DF4
	movs r0, #1
	strb r0, [r6, #8]
_08000E16:
	ldrh r0, [r6, #0xc]
	tst r0, r0
	beq _08000E20
	subs r0, #1
	strh r0, [r6, #0xc]
_08000E20:
	add sp, #0x10
	movs r0, #0
	pop {pc}
	.align 2, 0

	thumb_func_start FUN_08000e28
FUN_08000e28: @ 0x08000E28
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	movs r1, #1
	lsls r1, r1, #8
	ands r1, r4
	beq _08000E3A
	movs r0, #0x80
	orrs r6, r0
_08000E3A:
	movs r1, #0x40
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E46
	movs r0, #0x40
	orrs r6, r0
_08000E46:
	movs r1, #2
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E52
	movs r0, #2
	orrs r6, r0
_08000E52:
	movs r1, #1
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E5E
	movs r0, #1
	orrs r6, r0
_08000E5E:
	movs r1, #4
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E6A
	movs r0, #4
	orrs r6, r0
_08000E6A:
	movs r1, #8
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E76
	movs r0, #8
	orrs r6, r0
_08000E76:
	movs r1, #0x10
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E82
	movs r0, #0x10
	orrs r6, r0
_08000E82:
	movs r1, #0x20
	lsls r1, r1, #0x10
	ands r1, r4
	beq _08000E8E
	movs r0, #0x20
	orrs r6, r0
_08000E8E:
	adds r0, r6, #0
	pop {r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start FUN_08000e94
FUN_08000e94: @ 0x08000E94
	push {r0, r1, r2, r3, lr}
	subs r0, #1
	bl FUN_0800309c
	cmp r0, #2
	beq _08000EA8
	cmp r0, #0xff
	beq _08000EA8
	movs r0, #1
	tst r0, r0
_08000EA8:
	pop {r0, r1, r2, r3, pc}
	.align 2, 0

	thumb_func_start FUN_08000eac
FUN_08000eac: @ 0x08000EAC
	push {r0, r1, r2, r3, r4, r5, r6, r7, lr}
	ldr r4, _08000ED0 @ =0x02000D10
	movs r3, #4
	lsls r3, r3, #1
	muls r2, r3, r2
	lsls r1, r1, #1
	adds r1, r1, r2
	strh r0, [r4, r1]
	pop {r0, r1, r2, r3, r4, r5, r6, r7, pc}
	.align 2, 0

	thumb_func_start LoadArray02000d10
LoadArray02000d10: @ 0x08000EC0
	push {r4, lr}
	ldr r4, _08000ED0 @ =0x02000D10
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	pop {r4, pc}
	.align 2, 0
_08000ED0: .4byte 0x02000D10

	thumb_func_start FUN_08000ed4
FUN_08000ed4: @ 0x08000ED4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08000784
	ldr r1, _08000F18 @ =0x08000F24
	ldrb r0, [r1, r0]
	cmp r0, #0xff
	beq _08000EEE
	ldr r4, _08000F20 @ =0x02000D50
	ldrh r2, [r4, #0x10]
	ldrh r0, [r4, #0x16]
	movs r1, #0
	b _08000EF2
_08000EEE:
	movs r1, #1
	movs r0, #0
_08000EF2:
	pop {r4, pc}

	thumb_func_start FUN_08000ef4
FUN_08000ef4: @ 0x08000EF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08000784
	ldr r1, _08000F18 @ =0x08000F24
	ldrb r0, [r1, r0]
	cmp r0, #0xff
	beq _08000F12
	movs r1, #8
	muls r1, r4, r1
	adds r1, r1, r0
	ldr r4, _08000F1C @ =0x02000D10
	ldrh r0, [r4, r1]
	movs r1, #0
	b _08000F16
_08000F12:
	movs r1, #1
	movs r0, #0
_08000F16:
	pop {r4, pc}
	.align 2, 0
_08000F18: .4byte _08000F24
_08000F1C: .4byte 0x02000D10
_08000F20: .4byte 0x02000D50
_08000F24: .byte 0x02, 0xFF, 0xFF, 0x04

	thumb_func_start FUN_08000f28
FUN_08000f28: @ 0x08000F28
	push {r4, lr}
	ldr r4, _08000F60 @ =0x02000D50
	ldrh r1, [r4, #0x14]
	cmp r0, r1
	beq _08000F38
	strh r0, [r4, #0x14]
	movs r1, #0
	strh r1, [r4, #0x18]
_08000F38:
	ldrh r1, [r4, #0x18]
	cmp r1, #8
	beq _08000F44
	adds r1, #1
	strh r1, [r4, #0x18]
	b _08000F5C
_08000F44:
	ldrh r1, [r4, #0x12]
	tst r1, r1
	bne _08000F52
	strh r0, [r4, #0x16]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	b _08000F5C
_08000F52:
	ldrh r1, [r4, #0x10]
	strh r1, [r4, #0x12]
	strh r0, [r4, #0x10]
	movs r0, #0
	strh r0, [r4, #0x16]
_08000F5C:
	pop {r4, pc}
	.align 2, 0
_08000F60: .4byte 0x02000D50

	thumb_func_start FUN_08000f64
FUN_08000f64: @ 0x08000F64
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08000F78 @ =0x08000F7C
	lsls r3, r3, #2
	ldr r4, [r4, r3]
	ldrb r1, [r4]
	ldrb r2, [r4, #1]
	adds r0, r4, #2
	pop {r4, pc}
	.align 2, 0
_08000F78: .4byte _08000F7C
_08000F7C:
	.4byte _08000f8c
	.4byte _08000f8c+11
	.4byte _08000fa4
	.4byte FUN_08000fac
_08000f8c:
	.byte 0x00, 0x03, 0x53, 0x49
	.byte 0x4F, 0x20, 0x57, 0x41, 0x49, 0x54, 0x00, 0x00, 0x03, 0x53, 0x49, 0x4F, 0x20, 0x45, 0x52, 0x52
	.byte 0x4F, 0x52, 0x32, 0x00
_08000fa4:
	.byte 0x00, 0x03, 0x53, 0x49, 0x4F, 0x20, 0x4F, 0x4E

	thumb_func_start FUN_08000fac
FUN_08000fac: @ 0x08000FAC
	movs r0, r0
	strh r3, [r0, r4]
	ldr r7, _080010D8 @ =0x020014C0
	ldr r7, _08001034 @ =0x1E71FBA7
	mov r6, r8
	movs r0, r0

	thumb_func_start FUN_08000fb8
FUN_08000fb8: @ 0x08000FB8
	push {r4, r7, lr}
	movs r4, #1
	ldr r7, _08000FEC @ =0x02000D50
	ldrb r0, [r7, #1]
	cmp r0, #8
	bne _08000FE6
	ldrb r0, [r7]
	cmp r0, #8
	bne _08000FE6
	ldr r0, [r7, #0x48]
	bl FUN_08000e28
	movs r1, #0x7f
	tst r1, r0
	beq _08000FDE
	ldrh r0, [r7, #0xc]
	cmp r0, #8
	blt _08000FE4
	b _08000FE6
_08000FDE:
	ldrh r0, [r7, #0xc]
	tst r0, r0
	bne _08000FE6
_08000FE4:
	movs r4, #0
_08000FE6:
	adds r0, r4, #0
	pop {r4, r7, pc}
	.align 2, 0
_08000FEC: .4byte 0x02000D50

	thumb_func_start FUN_08000ff0
FUN_08000ff0: @ 0x08000FF0
	push {lr}
	movs r1, #8
	strb r1, [r0]
	movs r1, #0x10
	strh r1, [r0, #0xc]
	pop {pc}

	thumb_func_start FUN_08000ffc
FUN_08000ffc: @ 0x08000FFC
	push {lr}
	ldr r2, _08001008 @ =0x02000D50
	ldrb r0, [r2, #4]
	ldrb r1, [r2, #3]
	cmp r0, r1
	pop {pc}
	.align 2, 0
_08001008: .4byte 0x02000D50

	thumb_func_start sio_0800100c
sio_0800100c: @ 0x0800100C
	push {lr}
	ldr r6, _08001020 @ =0x02000D50
	movs r0, #0
	strh r0, [r6, #0xe]
	movs r0, #8
	strb r0, [r6, #1]
	adds r0, r6, #0
	bl FUN_08000ff0
	pop {pc}
	.align 2, 0
_08001020: .4byte 0x02000D50

	thumb_func_start FUN_08001024
FUN_08001024: @ 0x08001024
	push {r1, r2, r3, r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #1
_0800102A:
	adds r0, r6, #0
	bl FUN_08000e94
	beq _08001044
_08001032:
	.byte 0xFF, 0xF7
_08001034: .4byte 0x1E71FBA7
_08001038:
	.byte 0x88, 0x42, 0x03, 0xD1, 0x01, 0x36, 0x04, 0x2E
	.byte 0xF3, 0xDD, 0x01, 0xE0
_08001044:
	lsls r1, r1, #1
	adds r7, r7, r1
_08001048:
	adds r0, r7, #0
	pop {r1, r2, r3, r4, r5, r6, r7, pc}

	thumb_func_start FUN_0800104c
FUN_0800104c: @ 0x0800104C
	push {lr}
	ldr r0, _08001088 @ =0x020014C0
	movs r1, #0x20
	bl clearMemory16
	bl FUN_08000798
	ldr r0, _08001080 @ =0x4234574A
	ldr r1, _08001084 @ =0x00000200
	movs r2, #0
	bl sio_08000774
	movs r0, #0x10
	movs r1, #3
	movs r2, #2
	movs r3, #2
	bl mmbn4_08000738
	ldr r0, _0800108C @ =0x10000000
	bl FUN_080010e8
	ldr r0, _08001090 @ =0x020014F4
	ldr r1, _08001094 @ =0x0000A3D0
	strh r1, [r0]
	pop {pc}
	.align 2, 0
_08001080: .4byte 0x4234574A
_08001084: .4byte 0x00000200
_08001088: .4byte 0x020014C0
_0800108C: .4byte 0x10000000
_08001090: .4byte 0x020014F4
_08001094: .4byte 0x0000A3D0

	thumb_func_start FUN_08001098
FUN_08001098: @ 0x08001098
	push {lr}
	ldr r0, _080010D8 @ =0x020014C0
	movs r1, #0x20
	bl clearMemory16
	bl FUN_08000798
	ldr r0, _080010D0 @ =0x4234574A
	ldr r1, _080010D4 @ =0x00000200
	movs r2, #0
	bl sio_08000774
	movs r0, #0x10
	movs r1, #0
	movs r2, #2
	movs r3, #3
	bl mmbn4_08000738
	movs r0, #0xff
	movs r1, #4
	ldr r2, _080010D4 @ =0x00000200
	bl FUN_08001670
	ldr r0, _080010E0 @ =0x020014F4
	ldr r1, _080010E4 @ =0x0000A3D0
	strh r1, [r0]
	pop {pc}
	.align 2, 0
_080010D0: .4byte 0x4234574A
_080010D4: .4byte 0x00000200
_080010D8: .4byte 0x020014C0
_080010DC:
	.byte 0x00, 0x00, 0x00, 0x10
_080010E0: .4byte 0x020014F4
_080010E4: .4byte 0x0000A3D0

	thumb_func_start FUN_080010e8
FUN_080010e8: @ 0x080010E8
	push {r4, r5, r6, r7, lr}
	ldr r7, _0800112C @ =0x02000FB0
	push {r0}
	adds r0, r7, #0
	movs r1, #0x10
	bl clearMemory16
	pop {r0}
	ldr r6, _08001130 @ =0x02000D50
	str r7, [r6, #0x4c]
	movs r5, #0
	movs r4, #0
	movs r1, #0x61
	strh r1, [r7, r5]
	adds r5, #2
	strh r0, [r7, r5]
	adds r5, #2
	lsrs r1, r0, #0x10
	strh r1, [r7, r5]
	adds r5, #2
	movs r3, #4
	movs r1, #0xff
_08001114:
	adds r2, r0, #0
	ands r2, r1
	adds r4, r4, r2
	lsrs r0, r0, #8
	subs r3, #1
	bgt _08001114
	str r4, [r6, #0x44]
	movs r0, #0xe
	str r0, [r6, #0x20]
	str r0, [r6, #0x24]
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0800112C: .4byte 0x02000FB0
_08001130: .4byte 0x02000D50

	thumb_func_start FUN_08001134
FUN_08001134: @ 0x08001134
	push {r5, r7, lr}
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #2
	bne _0800114C
	bl FUN_08000784
	ldr r5, _08001150 @ =0x020014C0
	strb r0, [r5]
	bl FUN_080012ec
_0800114C:
	adds r0, r7, #0
	pop {r5, r7, pc}
	.align 2, 0
_08001150: .4byte 0x020014C0

	thumb_func_start FUN_08001154
FUN_08001154: @ 0x08001154
	push {r4, r6, r7, lr}
	movs r6, #0
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #8
	beq _0800119E
	cmp r7, #4
	bne _0800116E
	movs r6, #2
_08001168:
	bl DisableSerial
	b _080011AA
_0800116E:
	movs r0, #1
	bl mmbn4_080016c8
	cmp r0, #0xff
	beq _0800119E
	ldrh r1, [r0, #6]
	cmp r1, #1
	bne _08001190
	ldr r4, _080011B8 @ =0x020014C0
	ldrh r1, [r0, #8]
	lsrs r2, r1, #9
	strh r2, [r4, #0x16]
	lsls r2, r2, #9
	bics r1, r2
	strh r1, [r4, #0x14]
	movs r6, #1
	b _0800119E
_08001190:
	cmp r1, #2
	bne _0800119E
	movs r6, #4
	ldrh r1, [r0, #8]
	cmp r1, #3
	beq _08001168
	movs r6, #0
_0800119E:
	ldr r0, _080011B4 @ =0x02030B54
	ldr r0, [r0]
	movs r1, #1
	ldr r2, _080011B0 @ =0x00000200
	bl FUN_08001670
_080011AA:
	adds r0, r6, #0
	pop {r4, r6, r7, pc}
	.align 2, 0
_080011B0: .4byte 0x00000200
_080011B4: .4byte 0x02030B54
_080011B8: .4byte 0x020014C0

	thumb_func_start FUN_080011bc
FUN_080011bc: @ 0x080011BC
	push {r4, r6, r7, lr}
	movs r6, #0
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #8
	beq _08001204
	cmp r7, #4
	bne _080011D6
	movs r6, #2
	bl DisableSerial
	b _08001204
_080011D6:
	movs r0, #1
	bl mmbn4_080016c8
	cmp r0, #0xff
	beq _080011F4
	ldrh r1, [r0, #6]
	cmp r1, #2
	bne _080011F4
	ldrh r1, [r0, #8]
	tst r1, r1
	beq _080011F4
	movs r6, #4
	cmp r1, #1
	bne _080011F4
	movs r6, #1
_080011F4:
	movs r0, #1
	movs r1, #2
	ldr r2, _08001208 @ =0x00000200
	bl FUN_08001670
	ldr r0, _0800120C @ =0x020014C0
	movs r1, #0x3c
	strh r1, [r0, #0x18]
_08001204:
	adds r0, r6, #0
	pop {r4, r6, r7, pc}
	.align 2, 0
_08001208: .4byte 0x00000200
_0800120C: .4byte 0x020014C0

	thumb_func_start FUN_08001210
FUN_08001210: @ 0x08001210
	push {r4, r6, r7, lr}
	movs r6, #0
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #8
	beq _08001258
	cmp r7, #4
	bne _0800122A
	movs r6, #2
	bl DisableSerial
	b _08001258
_0800122A:
	movs r0, #1
	bl mmbn4_080016c8
	cmp r0, #0xff
	beq _0800124E
	ldrh r1, [r0, #6]
	cmp r1, #3
	bne _08001258
	push {r0}
	bl FUN_08000784
	tst r0, r0
	pop {r0}
	beq _0800124C
	ldrh r1, [r0, #0xa]
	ldr r4, _08001260 @ =0x020014C0
	strh r1, [r4, #0x18]
_0800124C:
	movs r6, #1
_0800124E:
	movs r0, #0
	movs r1, #3
	ldr r2, _0800125C @ =0x00000200
	bl FUN_08001670
_08001258:
	adds r0, r6, #0
	pop {r4, r6, r7, pc}
	.align 2, 0
_0800125C: .4byte 0x00000200
_08001260: .4byte 0x020014C0

	thumb_func_start FUN_08001264
FUN_08001264: @ 0x08001264
	push {r4, r6, r7, lr}
	movs r6, #0
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #8
	beq _0800128E
	cmp r7, #4
	bne _0800127E
	movs r6, #2
	bl DisableSerial
	b _0800128E
_0800127E:
	ldr r4, _08001294 @ =0x020014C0
	ldrh r1, [r4, #0x18]
	subs r1, #1
	strh r1, [r4, #0x18]
	bne _0800128E
	movs r0, #0x40
	strh r0, [r4, #0x18]
	movs r6, #1
_0800128E:
	adds r0, r6, #0
	pop {r4, r6, r7, pc}
	.align 2, 0
_08001294: .4byte 0x020014C0

	thumb_func_start FUN_08001298
FUN_08001298: @ 0x08001298
	push {r4, r6, r7, lr}
	movs r6, #0
	bl FUN_080007b4
	adds r7, r0, #0
	cmp r7, #8
	beq _080012C2
	cmp r7, #4
	bne _080012B2
	movs r6, #2
	bl DisableSerial
	b _080012C2
_080012B2:
	ldr r4, _080012C8 @ =0x020014C0
	ldrh r1, [r4, #0x18]
	subs r1, #1
	strh r1, [r4, #0x18]
	bne _080012C2
	bl DisableSerial
	movs r6, #1
_080012C2:
	adds r0, r6, #0
	pop {r4, r6, r7, pc}
	.align 2, 0
_080012C8: .4byte 0x020014C0

	thumb_func_start FUN_080012cc
FUN_080012cc: @ 0x080012CC
	push {r4, r6, r7, lr}
	ldr r4, _080012E8 @ =0x020014C0
	ldrh r0, [r4, #0x14]
	ldrh r1, [r4, #0x16]
	ldr r4, _080012E8 @ =0x020014C0
	ldrh r0, [r4, #0x14]
	movs r1, #0
	movs r2, #9
	movs r3, #4
	ldrh r0, [r4, #0x16]
	movs r1, #0
	movs r2, #0xa
	movs r3, #4
	pop {r4, r6, r7, pc}
	.align 2, 0
_080012E8: .4byte 0x020014C0

	thumb_func_start FUN_080012ec
FUN_080012ec: @ 0x080012EC
	push {r5, r6, r7, lr}
	ldr r6, _08001324 @ =0x02000D50
	ldrb r0, [r6, #1]
	cmp r0, #4
	bne _08001322
	ldr r1, [r6, #0x2c]
	ldr r0, [r6, #0x24]
	cmp r1, r0
	blt _08001304
	bl FUN_08001328
	b _08001322
_08001304:
	movs r2, #0
	ldr r7, [r6, #0x34]
	ldr r5, [r6, #0x4c]
	ldr r1, [r6, #0x30]
_0800130C:
	ldrh r0, [r5, r1]
	strh r0, [r7, r2]
	adds r1, #2
	adds r2, #2
	cmp r2, #0x10
	blt _0800130C
	str r1, [r6, #0x30]
	movs r0, #0xe
	ldr r1, [r6, #0x2c]
	adds r1, r1, r0
	str r1, [r6, #0x2c]
_08001322:
	pop {r5, r6, r7, pc}
	.align 2, 0
_08001324: .4byte 0x02000D50

	thumb_func_start FUN_08001328
FUN_08001328: @ 0x08001328
	push {r7, lr}
	ldr r7, _08001338 @ =0x02000D50
	movs r0, #8
	strb r0, [r7]
	movs r0, #0x10
	strh r0, [r7, #0xc]
	pop {r7, pc}
	.align 2, 0
_08001338: .4byte 0x02000D50

	thumb_func_start sio_0800133c
sio_0800133c: @ 0x0800133C
	push {lr}
	ldr r0, _08001378 @ =0x020014C0
	movs r1, #0x20
	bl clearMemory16
	bl FUN_08000798
	ldr r0, _08001370 @ =0x425A334A
	ldr r1, _08001374 @ =0x00002000
	movs r2, #0
	bl sio_08000774
	movs r0, #0x80
	lsls r0, r0, #4
	movs r1, #1
	movs r2, #2
	movs r3, #1
	bl mmbn4_08000738
	bl FUN_08001384
	ldr r0, _0800137C @ =0x020014F4
	ldr r1, _08001380 @ =0x0000A380
	strh r1, [r0]
	pop {pc}
	.align 2, 0
_08001370: .4byte 0x425A334A
_08001374: .4byte 0x00002000
_08001378: .4byte 0x020014C0
_0800137C: .4byte 0x020014F4
_08001380: .4byte 0x0000A380

	thumb_func_start FUN_08001384
FUN_08001384: @ 0x08001384
	push {r4, r6, r7, lr}
	ldr r4, _080013A4 @ =0x020010C0
	movs r7, #0
	movs r1, #0
	movs r3, #0
	movs r0, #0x61
	strh r0, [r4, r1]
	movs r6, #0
_08001394:
	adds r1, #2
	adds r6, #2
	adds r3, #1
	strh r3, [r4, r1]
	cmp r6, #0xe
	blt _08001394
	pop {r4, r6, r7, pc}
	.align 2, 0
_080013A4: .4byte 0x020010C0

	thumb_func_start sio_080013a8
sio_080013a8: @ 0x080013A8
	push {r6, r7, lr}
	bl FUN_08001438
	bne _080013C0
	bl FUN_08000fb8
	beq _080013C0
	bl DisableSerial
	bl FUN_0800146c
	b _080013CA
_080013C0:
	bl FUN_08001498
	beq _080013CA
	movs r0, #1
	b _080013CC
_080013CA:
	movs r0, #0
_080013CC:
	pop {r6, r7, pc}
	.align 2, 0

	thumb_func_start sio_080013d0
sio_080013d0: @ 0x080013D0
	push {r6, r7, lr}
	movs r6, #0
	bl FUN_08001438
	bne _080013EA
	bl FUN_08000fb8
	beq _080013EA
	bl DisableSerial
	bl FUN_0800146c
	movs r6, #1
_080013EA:
	adds r0, r6, #0
	pop {r6, r7, pc}
	.align 2, 0

	thumb_func_start sio_080013f0
sio_080013f0: @ 0x080013F0
	push {r6, r7, lr}
	bl FUN_08001438
	beq _08001402
	bl FUN_08000fb8
	beq _08001402
	movs r0, #0
	b _0800140C
_08001402:
	bl DisableSerial
	bl FUN_0800146c
	movs r0, #1
_0800140C:
	pop {r6, r7, pc}
	.align 2, 0

	thumb_func_start sio_08001410
sio_08001410: @ 0x08001410
	push {r6, r7, lr}
	bl FUN_08001438
	bne _08001426
	bl FUN_08000fb8
	beq _0800142C
	bl DisableSerial
	movs r0, #0
	b _08001436
_08001426:
	bl FUN_08000fb8
	bne _08001434
_0800142C:
	bl DisableSerial
	movs r0, #1
	b _08001436
_08001434:
	movs r0, #2
_08001436:
	pop {r6, r7, pc}

	thumb_func_start FUN_08001438
FUN_08001438: @ 0x08001438
	push {r5, r7, lr}
	ldr r5, _08001468 @ =0x020014C0
	movs r7, #1
	bl FUN_080007b4
	push {r0}
	movs r1, #0
	movs r2, #6
	movs r3, #2
	pop {r0}
	cmp r0, #4
	bne _08001454
	movs r7, #0
	b _08001462
_08001454:
	cmp r0, #2
	bne _08001462
	bl FUN_08000784
	strb r0, [r5]
	bl FUN_080014a8
_08001462:
	adds r0, r7, #0
	tst r0, r0
	pop {r5, r7, pc}
	.align 2, 0
_08001468: .4byte 0x020014C0

	thumb_func_start FUN_0800146c
FUN_0800146c: @ 0x0800146C
	push {lr}
	bl FUN_08000798
	bl ResetSerial
	ldr r0, _08001490 @ =0x425A334A
	ldr r1, _08001494 @ =0x00002000
	movs r2, #0
	bl sio_08000774
	movs r0, #0x80
	lsls r0, r0, #4
	movs r1, #1
	movs r2, #2
	movs r3, #1
	bl mmbn4_08000738
	pop {pc}
	.align 2, 0
_08001490: .4byte 0x425A334A
_08001494: .4byte 0x00002000

	thumb_func_start FUN_08001498
FUN_08001498: @ 0x08001498
	push {lr}
	ldr r1, _080014A4 @ =0x02000D50
	ldrh r0, [r1, #0xe]
	tst r0, r0
	pop {pc}
	.align 2, 0
_080014A4: .4byte 0x02000D50

	thumb_func_start FUN_080014a8
FUN_080014a8: @ 0x080014A8
	push {r4, r5, r6, r7, lr}
	ldr r6, _080014E8 @ =0x02000D50
	ldrb r0, [r6, #1]
	cmp r0, #4
	bne _080014DE
	ldr r1, [r6, #0x2c]
	ldr r0, [r6, #0x20]
	cmp r1, r0
	blt _080014C2
	adds r0, r6, #0
	bl FUN_08000ff0
	b _080014DE
_080014C2:
	ldr r1, [r6, #0x30]
	movs r2, #0
	ldr r7, _080014E0 @ =0x02000FB0
	ldr r5, _080014E4 @ =0x020010C0
_080014CA:
	ldrh r0, [r5, r1]
	strh r0, [r7, r2]
	adds r1, #2
	adds r2, #2
	cmp r2, #0x10
	blt _080014CA
	movs r0, #0xe
	ldr r1, [r6, #0x2c]
	adds r1, r1, r0
	str r1, [r6, #0x2c]
_080014DE:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_080014E0: .4byte 0x02000FB0
_080014E4: .4byte 0x020010C0
_080014E8: .4byte 0x02000D50

	thumb_func_start sio_080014ec
sio_080014ec: @ 0x080014EC
	push {lr}
	ldr r0, _08001504 @ =0x425A334A
	ldr r1, _08001508 @ =0x08001510
	ldrh r1, [r1]
	movs r2, #0
	bl sio_08000774
	ldr r0, _0800150C @ =0x020014C0
	movs r1, #4
	strb r1, [r0, #1]
	pop {pc}
	.align 2, 0
_08001504: .4byte 0x425A334A
_08001508: .4byte _08001510
_0800150C: .4byte 0x020014C0
_08001510:
	.byte 0x10, 0x10, 0x00, 0x00

	thumb_func_start sio_08001514
sio_08001514: @ 0x08001514
	push {r4, r6, lr}
	ldr r4, _08001530 @ =0x020014C0
	movs r1, #0x38
	ldrb r0, [r4]
	tst r0, r0
	beq _08001522
	movs r1, #0x3c
_08001522:
	ldr r6, _08001534 @ =0x02000D50
	ldr r2, [r6, r1]
	ldrh r0, [r2]
	ldrh r0, [r2, r0]
	movs r1, #0xff
	ands r0, r1
	pop {r4, r6, pc}
	.align 2, 0
_08001530: .4byte 0x020014C0
_08001534: .4byte 0x02000D50

	thumb_func_start sio_08001538
sio_08001538: @ 0x08001538
	push {lr}
	ldr r0, _0800156C @ =0x020014C0
	movs r1, #0x20
	bl clearMemory16
	bl FUN_08000798
	movs r0, #0x10
	movs r1, #2
	movs r2, #4
	movs r3, #0
	bl mmbn4_08000738
	movs r0, #0
	movs r1, #0
	ldr r2, _08001564 @ =0x00004000
	bl FUN_0800165c
	ldr r0, _08001568 @ =0x02000D50
	movs r1, #0x3c
	strh r1, [r0, #0xc]
	pop {pc}
	.align 2, 0
_08001564: .4byte 0x00004000
_08001568: .4byte 0x02000D50
_0800156C: .4byte 0x020014C0

	thumb_func_start sio_08001570
sio_08001570: @ 0x08001570
	push {r5, r6, r7, lr}
	movs r6, #2
	bl sio_080015e8
	bne _0800159C
	bl FUN_080015a8
	beq _0800159C
	bl FUN_080015c4
	bne _080015A0
	ldr r5, _080015A4 @ =0x020014C0
	ldrh r0, [r5, #0x10]
	movs r1, #0
	movs r2, #0xa
	movs r3, #4
	ldrh r0, [r5, #0x12]
	movs r1, #0
	movs r2, #0xb
	movs r3, #4
	movs r6, #0
	b _080015A0
_0800159C:
	movs r6, #1
	mov r8, r8
_080015A0:
	adds r0, r6, #0
	pop {r5, r6, r7, pc}
	.align 2, 0
_080015A4: .4byte 0x020014C0

	thumb_func_start FUN_080015a8
FUN_080015a8: @ 0x080015A8
	push {r4, lr}
	bl LoadArray02000d10
	ldr r4, _080015C0 @ =0x0000A380
	cmp r0, r4
	beq _080015BE
	cmp r1, r4
	beq _080015BE
	cmp r2, r4
	beq _080015BE
	cmp r3, r4
_080015BE:
	pop {r4, pc}
	.align 2, 0
_080015C0: .4byte 0x0000A380

	thumb_func_start FUN_080015c4
FUN_080015c4: @ 0x080015C4
	push {r5, lr}
	ldr r5, _080015E4 @ =0x020014C0
	movs r0, #4
	bl FUN_08000ed4
	tst r1, r1
	bne _080015D8
	strh r2, [r5, #0x10]
	strh r0, [r5, #0x12]
	pop {r5, pc}
_080015D8:
	movs r0, #0
	mvns r0, r0
	strh r0, [r5, #0x12]
	strh r0, [r5, #0x10]
	pop {r5, pc}
	.align 2, 0
_080015E4: .4byte 0x020014C0

	thumb_func_start sio_080015e8
sio_080015e8: @ 0x080015E8
	push {r4, r5, r6, r7, lr}
	movs r6, #2
	bl FUN_080007b4
	cmp r0, #2
	beq _080015FA
	cmp r0, #4
	beq _0800164A
	b _0800164C
_080015FA:
	movs r0, #0
	bl FUN_08001690
	cmp r0, #0xff
	beq _0800164C
	ldr r4, _08001654 @ =0x020014C0
	movs r3, #0xc
	movs r7, #0
	movs r5, #0
_0800160C:
	adds r0, r7, #0
	bl FUN_0800309c
	strb r0, [r4, r3]
	cmp r0, #2
	bne _08001626
	cmp r7, #1
	beq _08001620
	cmp r7, #2
	bne _08001634
_08001620:
	adds r5, #1
	movs r6, #0
	b _08001634
_08001626:
	cmp r0, #1
	bne _08001634
	cmp r7, #0
	beq _08001632
	cmp r7, #3
	bne _08001634
_08001632:
	adds r5, #1
_08001634:
	adds r3, #1
	adds r7, #1
	cmp r7, #4
	blt _0800160C
	ldr r1, _08001658 @ =0x02000D50
	ldr r0, [r1, #0x48]
	movs r1, #0x1c
	ands r0, r1
	lsrs r0, r0, #2
	cmp r5, r0
	beq _0800164C
_0800164A:
	movs r6, #1
_0800164C:
	adds r0, r6, #0
	tst r6, r6
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08001654: .4byte 0x020014C0
_08001658: .4byte 0x02000D50

	thumb_func_start FUN_0800165c
FUN_0800165c: @ 0x0800165C
	push {r4, lr}
	ldr r4, _08001688 @ =0x02000FB0
	strh r0, [r4, #8]
	strh r1, [r4, #6]
	strh r2, [r4, #4]
	ldr r0, _0800168C @ =0x4234574A
	str r0, [r4]
	movs r0, #0x3c
	strh r0, [r4, #0xa]
	pop {r4, pc}

	thumb_func_start FUN_08001670
FUN_08001670: @ 0x08001670
	push {r4, lr}
	bl FUN_0800165c
	ldr r4, _08001688 @ =0x02000FB0
	bl GetLastSendQueueCount
	strh r0, [r4, #0xc]
	bl GetLastRecvQueueCount
	strh r0, [r4, #0xe]
	pop {r4, pc}
	.align 2, 0
_08001688: .4byte 0x02000FB0
_0800168C: .4byte 0x4234574A

	thumb_func_start FUN_08001690
FUN_08001690: @ 0x08001690
	push {r4, r6, r7, lr}
	lsls r0, r0, #2
	adds r7, r0, #0
	bl FUN_08000784
	beq _0800169E
	movs r0, #1
_0800169E:
	ldr r4, _08001728 @ =0x020014C0
	strb r0, [r4]
	ldr r1, _0800172C @ =0x08001730
	ldr r6, [r1, #4]
	tst r0, r0
	beq _080016AC
	ldr r6, [r1]
_080016AC:
	ldr r0, [r6]
	ldr r1, _08001738 @ =0x4234574A
	cmp r0, r1
	bne _080016C2
	ldrh r0, [r6, #4]
	ldr r1, _0800173C @ =0x08001740
	ldr r1, [r1, r7]
	cmp r0, r1
	bne _080016C2
	adds r0, r6, #0
	b _080016C4
_080016C2:
	movs r0, #0xff
_080016C4:
	pop {r4, r6, r7, pc}
	.align 2, 0
