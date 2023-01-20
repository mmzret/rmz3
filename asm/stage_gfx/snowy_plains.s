	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initSnowyPlains
initSnowyPlains: @ 0x08012ADC
	push {lr}
	sub sp, #0x10
	ldr r0, _08012B10 @ =0x080FECCC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08012B14 @ =0x080FECD4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0
	movs r1, #0x51
	mov r2, sp
	bl shiftTerrain
	add r2, sp, #8
	movs r0, #0xf0
	movs r1, #0x6f
	bl shiftTerrain
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_08012B10: .4byte 0x080FECCC
_08012B14: .4byte 0x080FECD4

	thumb_func_start nop_08012b18
nop_08012b18: @ 0x08012B18
	bx lr
	.align 2, 0

	thumb_func_start nop_08012b1c
nop_08012b1c: @ 0x08012B1C
	bx lr
	.align 2, 0

	thumb_func_start nop_08012b20
nop_08012b20: @ 0x08012B20
	bx lr
	.align 2, 0

	thumb_func_start snowyplains_08012b24
snowyplains_08012b24: @ 0x08012B24
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _08012B4C
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _08012B50 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _08012B54 @ =0x0000FFFC
	ands r1, r2
	movs r2, #3
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08012B4C:
	pop {r0}
	bx r0
	.align 2, 0
_08012B50: .4byte 0x02002144
_08012B54: .4byte 0x0000FFFC

	thumb_func_start snowyplains_08012b58
snowyplains_08012b58: @ 0x08012B58
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _08012B8E
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _08012B94 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _08012B98 @ =0x0000FFFC
	ands r1, r2
	movs r2, #3
	orrs r1, r2
	strh r1, [r0]
	movs r0, #0x60
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	movs r0, #0x96
	str r0, [r3, #0x4c]
	movs r0, #0x64
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08012B8E:
	pop {r0}
	bx r0
	.align 2, 0
_08012B94: .4byte 0x02002144
_08012B98: .4byte 0x0000FFFC

	thumb_func_start snowyPlains_08012b9c
snowyPlains_08012b9c: @ 0x08012B9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08012BEA
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _08012BF0 @ =0x02002144
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _08012BF4 @ =0x085223D8
	ldr r0, [r0]
	ldr r2, _08012BF8 @ =0x085223E0
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08012BEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08012BF0: .4byte 0x02002144
_08012BF4: .4byte 0x085223D8
_08012BF8: .4byte 0x085223E0

	thumb_func_start FUN_08012bfc
FUN_08012bfc: @ 0x08012BFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	movs r5, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	mov sb, r0
	cmp r0, #0
	bne _08012C1C
	b _08012FDA
_08012C1C:
	ldr r2, _08012F54 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	mov r3, sb
	str r3, [r0]
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r2, r6
	ldr r0, _08012F58 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08012F5C @ =0xA6600001
	str r0, [r1]
	ldr r2, [sp]
	ldr r1, [r2, #0x34]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r7, r0, #0x10
	ldr r1, [r2, #0x38]
	subs r1, #0xa0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	ldr r3, _08012F60 @ =0xFFFFFEA8
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r8, r6
	asrs r1, r0, #0x10
	adds r0, r1, #0
	adds r0, #0x9f
	cmp r0, #0xff
	ble _08012C8A
	adds r3, r1, #0
	movs r2, #0xc0
	lsls r2, r2, #0xf
	movs r1, #0x9f
	lsls r1, r1, #2
	add r1, sb
	movs r4, #0x80
	lsls r4, r4, #9
_08012C78:
	str r2, [r1]
	adds r2, r2, r4
	subs r1, #4
	subs r5, #1
	cmp r5, #0
	blt _08012CB4
	adds r0, r3, r5
	cmp r0, #0xff
	bgt _08012C78
_08012C8A:
	cmp r5, #0
	blt _08012CB4
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, r5
	cmp r0, #0xb0
	ble _08012CB4
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012CA4:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012CB4
	adds r0, r1, r5
	cmp r0, #0xb0
	bgt _08012CA4
_08012CB4:
	ldr r6, [sp]
	ldr r1, [r6, #0x34]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xd
	lsrs r7, r0, #0x10
	ldr r0, [r6, #0x38]
	subs r0, #0xa0
	movs r1, #0xb0
	muls r0, r1, r0
	asrs r0, r0, #8
	ldr r1, _08012F64 @ =0xFFFFFED0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, #0
	blt _08012D2E
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r5
	adds r4, r0, #0
	cmp r1, #0xb0
	ble _08012D08
	adds r3, r2, #0
	lsls r0, r5, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r5, #2
	mov r6, sb
	adds r2, r0, r6
	movs r6, #0x80
	lsls r6, r6, #9
_08012CF6:
	str r1, [r2]
	adds r1, r1, r6
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012D2E
	adds r0, r3, r5
	cmp r0, #0xb0
	bgt _08012CF6
_08012D08:
	cmp r5, #0
	blt _08012D2E
	asrs r1, r4, #0x10
	adds r0, r1, r5
	cmp r0, #0x78
	ble _08012D2E
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012D1E:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012D2E
	adds r0, r1, r5
	cmp r0, #0x78
	bgt _08012D1E
_08012D2E:
	ldr r6, [sp]
	ldr r1, [r6, #0x34]
	ldr r0, _08012F68 @ =0xFFFFF4C0
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r7, r0, #0x10
	str r7, [sp, #4]
	ldr r1, [r6, #0x38]
	subs r1, #0xa0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	asrs r0, r0, #8
	ldr r1, _08012F6C @ =0xFFFFFEB8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov sl, r8
	cmp r5, #0
	blt _08012DB4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r5
	adds r4, r0, #0
	cmp r1, #0x78
	ble _08012D8E
	adds r3, r2, #0
	lsls r0, r5, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r5, #2
	mov r6, sb
	adds r2, r0, r6
	movs r6, #0x80
	lsls r6, r6, #9
_08012D7C:
	str r1, [r2]
	adds r1, r1, r6
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012DB4
	adds r0, r3, r5
	cmp r0, #0x78
	bgt _08012D7C
_08012D8E:
	cmp r5, #0
	blt _08012DB4
	asrs r1, r4, #0x10
	adds r0, r1, r5
	cmp r0, #0x67
	ble _08012DB4
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012DA4:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012DB4
	adds r0, r1, r5
	cmp r0, #0x67
	bgt _08012DA4
_08012DB4:
	ldr r6, [sp]
	ldr r0, [r6, #0x34]
	ldr r1, _08012F68 @ =0xFFFFF4C0
	adds r0, r0, r1
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r6, #0x38]
	subs r0, #0xa0
	movs r1, #3
	bl __divsi3
	adds r1, r0, #0
	subs r1, #0x93
	lsls r1, r1, #0x10
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0xc]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #0xc]
	subs r0, r3, r0
	lsls r0, r0, #0xc
	lsrs r6, r1, #0x10
	mov r8, r6
	asrs r6, r1, #0x10
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	mov sl, r1
	subs r4, r6, r1
	adds r4, #0x32
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp, #8]
	movs r0, #0xc8
	lsls r0, r0, #0xa
	adds r1, r4, #0
	bl __divsi3
	ldr r3, _08012F70 @ =0xFFFFF000
	adds r3, r3, r0
	mov ip, r3
	cmp r5, #0
	blt _08012E8A
	adds r0, r6, r5
	cmp r0, #0x35
	ble _08012E60
	mov r4, sl
	ldr r0, [sp, #0xc]
	mov sl, r0
	str r6, [sp, #0x10]
	lsls r0, r5, #2
	mov r1, sb
	adds r3, r0, r1
	rsbs r0, r5, #0
	adds r0, #0x67
	subs r2, r0, r4
_08012E30:
	mov r1, ip
	muls r1, r2, r1
	asrs r1, r1, #0xc
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ldr r6, [sp, #8]
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #0xc
	mov r6, sl
	subs r0, r6, r0
	ldr r6, _08012F74 @ =0x0000FFFF
	ands r0, r6
	orrs r1, r0
	str r1, [r3]
	subs r3, #4
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	blt _08012E8A
	ldr r1, [sp, #0x10]
	adds r0, r1, r5
	cmp r0, #0x35
	bgt _08012E30
_08012E60:
	cmp r5, #0
	blt _08012E8A
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, r5
	cmp r0, #0x2f
	ble _08012E8A
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012E7A:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012E8A
	adds r0, r1, r5
	cmp r0, #0x2f
	bgt _08012E7A
_08012E8A:
	ldr r6, [sp]
	ldr r0, [r6, #0x34]
	lsls r0, r0, #0xe
	lsrs r7, r0, #0x10
	ldr r0, [r6, #0x38]
	subs r0, #0xa0
	asrs r0, r0, #2
	subs r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r5, #0
	blt _08012EFC
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r5
	adds r4, r0, #0
	cmp r1, #0x2f
	ble _08012ED6
	adds r3, r2, #0
	lsls r0, r5, #0x10
	movs r1, #0xbc
	lsls r1, r1, #0xe
	subs r1, r1, r0
	lsls r0, r5, #2
	mov r6, sb
	adds r2, r0, r6
	movs r6, #0x80
	lsls r6, r6, #9
_08012EC4:
	str r1, [r2]
	adds r1, r1, r6
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012EFC
	adds r0, r3, r5
	cmp r0, #0x2f
	bgt _08012EC4
_08012ED6:
	cmp r5, #0
	blt _08012EFC
	asrs r1, r4, #0x10
	adds r0, r1, r5
	cmp r0, #0x10
	ble _08012EFC
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012EEC:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012EFC
	adds r0, r1, r5
	cmp r0, #0x10
	bgt _08012EEC
_08012EFC:
	ldr r6, [sp]
	ldr r0, [r6, #0x34]
	lsls r0, r0, #0xd
	lsrs r7, r0, #0x10
	cmp r5, #0
	blt _08012F8C
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r5
	adds r4, r0, #0
	cmp r1, #0x10
	ble _08012F3E
	adds r1, r2, #0
	lsls r0, r5, #0x10
	rsbs r0, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r3, r0, r2
	lsls r0, r5, #2
	mov r6, sb
	adds r2, r0, r6
	movs r6, #0x80
	lsls r6, r6, #9
_08012F2C:
	str r3, [r2]
	adds r3, r3, r6
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012F8C
	adds r0, r1, r5
	cmp r0, #0x10
	bgt _08012F2C
_08012F3E:
	cmp r5, #0
	blt _08012F8C
	asrs r1, r4, #0x10
	adds r0, r1, r5
	cmp r0, #7
	ble _08012F8C
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	b _08012F78
	.align 2, 0
_08012F54: .4byte 0x03001590
_08012F58: .4byte 0x0400001C
_08012F5C: .4byte 0xA6600001
_08012F60: .4byte 0xFFFFFEA8
_08012F64: .4byte 0xFFFFFED0
_08012F68: .4byte 0xFFFFF4C0
_08012F6C: .4byte 0xFFFFFEB8
_08012F70: .4byte 0xFFFFF000
_08012F74: .4byte 0x0000FFFF
_08012F78:
	lsls r3, r1, #0x10
	orrs r3, r7
_08012F7C:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012F8C
	adds r0, r1, r5
	cmp r0, #7
	bgt _08012F7C
_08012F8C:
	ldr r6, [sp]
	ldr r0, [r6, #0x34]
	lsls r0, r0, #0xc
	lsrs r7, r0, #0x10
	cmp r5, #0
	blt _08012FDA
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, r5
	cmp r0, #0
	ble _08012FBE
	lsls r0, r5, #2
	mov r3, sb
	adds r2, r0, r3
	lsls r3, r1, #0x10
	orrs r3, r7
_08012FAE:
	str r3, [r2]
	subs r2, #4
	subs r5, #1
	cmp r5, #0
	blt _08012FDA
	adds r0, r1, r5
	cmp r0, #0
	bgt _08012FAE
_08012FBE:
	cmp r5, #0
	blt _08012FDA
	lsls r0, r5, #0x10
	rsbs r1, r0, #0
	lsls r0, r5, #2
	add r0, sb
	movs r2, #0x80
	lsls r2, r2, #9
_08012FCE:
	str r1, [r0]
	adds r1, r1, r2
	subs r0, #4
	subs r5, #1
	cmp r5, #0
	bge _08012FCE
_08012FDA:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start snowyPlains_08012fec
snowyPlains_08012fec: @ 0x08012FEC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _0801303A
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _08013040 @ =0x02002144
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _08013044 @ =0x085223D4
	ldr r0, [r0]
	ldr r2, _08013048 @ =0x085223DC
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0801303A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013040: .4byte 0x02002144
_08013044: .4byte 0x085223D4
_08013048: .4byte 0x085223DC

	thumb_func_start FUN_0801304c
FUN_0801304c: @ 0x0801304C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r4, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _08013068
	b _080131EC
_08013068:
	ldr r2, _080131F8 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080131FC @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08013200 @ =0xA6600001
	str r0, [r1]
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x10
	ldr r0, [r1, #0x38]
	ldr r2, _08013204 @ =0xFFFFFCE0
	adds r0, r0, r2
	asrs r0, r0, #4
	subs r0, #0x60
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	asrs r1, r0, #0x10
	adds r0, r1, #0
	adds r0, #0x9f
	cmp r0, #0x8f
	ble _080130C8
	adds r3, r1, #0
	ldr r2, _08013208 @ =0xFFF00000
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r7, #0x80
	lsls r7, r7, #9
_080130B6:
	str r2, [r1]
	adds r2, r2, r7
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080130F2
	adds r0, r3, r4
	cmp r0, #0x8f
	bgt _080130B6
_080130C8:
	cmp r4, #0
	blt _080130F2
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x4f
	ble _080130F2
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_080130E2:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080130F2
	adds r0, r3, r4
	cmp r0, #0x4f
	bgt _080130E2
_080130F2:
	mov r2, sb
	ldr r0, [r2, #0x34]
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	ldr r0, [r2, #0x38]
	ldr r1, _08013204 @ =0xFFFFFCE0
	adds r0, r0, r1
	asrs r0, r0, #5
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp r4, #0
	blt _08013166
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r4
	mov r8, r0
	cmp r1, #0x4f
	ble _0801313E
	adds r3, r2, #0
	lsls r0, r4, #0x10
	movs r1, #0x9e
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r4, #2
	adds r2, r0, r6
	movs r7, #0x80
	lsls r7, r7, #9
_0801312C:
	str r1, [r2]
	adds r1, r1, r7
	subs r2, #4
	subs r4, #1
	cmp r4, #0
	blt _08013166
	adds r0, r3, r4
	cmp r0, #0x4f
	bgt _0801312C
_0801313E:
	cmp r4, #0
	blt _08013166
	mov r0, r8
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x2f
	ble _08013166
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013156:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013166
	adds r0, r3, r4
	cmp r0, #0x2f
	bgt _08013156
_08013166:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xd
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _08013198
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x27
	ble _08013198
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013188:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013198
	adds r0, r3, r4
	cmp r0, #0x27
	bgt _08013188
_08013198:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xc
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _080131EC
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x1f
	ble _080131CA
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_080131BA:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080131EC
	adds r0, r3, r4
	cmp r0, #0x1f
	bgt _080131BA
_080131CA:
	cmp r4, #0
	blt _080131EC
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r0, r2
	lsls r0, r4, #2
	adds r0, r0, r6
	movs r2, #0x80
	lsls r2, r2, #9
_080131E0:
	str r1, [r0]
	adds r1, r1, r2
	subs r0, #4
	subs r4, #1
	cmp r4, #0
	bge _080131E0
_080131EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080131F8: .4byte 0x03001590
_080131FC: .4byte 0x0400001C
_08013200: .4byte 0xA6600001
_08013204: .4byte 0xFFFFFCE0
_08013208: .4byte 0xFFF00000

	thumb_func_start snowyplains_0801320c
snowyplains_0801320c: @ 0x0801320C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _0801325A
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _08013260 @ =0x02002144
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _08013264 @ =0x085223D4
	ldr r0, [r0]
	ldr r2, _08013268 @ =0x085223DC
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0801325A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013260: .4byte 0x02002144
_08013264: .4byte 0x085223D4
_08013268: .4byte 0x085223DC

	thumb_func_start snowyplains_0801326c
snowyplains_0801326c: @ 0x0801326C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r4, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _08013286
	b _08013396
_08013286:
	ldr r2, _080133A0 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080133A4 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080133A8 @ =0xA6600001
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	ldr r0, [r1, #0x38]
	ldr r2, _080133AC @ =0xFFFFFCE0
	adds r0, r0, r2
	asrs r0, r0, #5
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	asrs r1, r0, #0x10
	adds r0, r1, #0
	adds r0, #0x9f
	cmp r0, #0x4f
	ble _080132E6
	adds r3, r1, #0
	ldr r2, _080133B0 @ =0xFFB00000
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r7, #0x80
	lsls r7, r7, #9
_080132D4:
	str r2, [r1]
	adds r2, r2, r7
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013310
	adds r0, r3, r4
	cmp r0, #0x4f
	bgt _080132D4
_080132E6:
	cmp r4, #0
	blt _08013310
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x2f
	ble _08013310
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013300:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013310
	adds r0, r3, r4
	cmp r0, #0x2f
	bgt _08013300
_08013310:
	mov r2, r8
	ldr r0, [r2, #0x34]
	lsls r0, r0, #0xd
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _08013342
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x27
	ble _08013342
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013332:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013342
	adds r0, r3, r4
	cmp r0, #0x27
	bgt _08013332
_08013342:
	mov r2, r8
	ldr r0, [r2, #0x34]
	lsls r0, r0, #0xc
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _08013396
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x1f
	ble _08013374
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013364:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013396
	adds r0, r3, r4
	cmp r0, #0x1f
	bgt _08013364
_08013374:
	cmp r4, #0
	blt _08013396
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r0, r2
	lsls r0, r4, #2
	adds r0, r0, r6
	movs r2, #0x80
	lsls r2, r2, #9
_0801338A:
	str r1, [r0]
	adds r1, r1, r2
	subs r0, #4
	subs r4, #1
	cmp r4, #0
	bge _0801338A
_08013396:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080133A0: .4byte 0x03001590
_080133A4: .4byte 0x0400001C
_080133A8: .4byte 0xA6600001
_080133AC: .4byte 0xFFFFFCE0
_080133B0: .4byte 0xFFB00000

	thumb_func_start snowyplains_080133b4
snowyplains_080133b4: @ 0x080133B4
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080133DC
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _080133E0 @ =0x02002144
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080133E4 @ =0x0000FFFC
	ands r1, r2
	movs r2, #3
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080133DC:
	pop {r0}
	bx r0
	.align 2, 0
_080133E0: .4byte 0x02002144
_080133E4: .4byte 0x0000FFFC

	thumb_func_start FUN_080133e8
FUN_080133e8: @ 0x080133E8
	push {r4, r5, r6, lr}
	ldr r1, [r0]
	ldr r2, _08013408 @ =0xFFFFF800
	adds r1, r1, r2
	asrs r5, r1, #0xc
	ldr r0, [r0, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	asrs r6, r0, #0xc
	ldr r0, _0801340C @ =0x0000018B
	cmp r5, r0
	bne _08013414
	ldr r4, _08013410 @ =0x08343F58
	b _08013444
	.align 2, 0
_08013408: .4byte 0xFFFFF800
_0801340C: .4byte 0x0000018B
_08013410: .4byte 0x08343F58
_08013414:
	ldr r0, _08013420 @ =0x00000193
	cmp r5, r0
	bne _08013428
	ldr r4, _08013424 @ =0x08343F58
	b _08013444
	.align 2, 0
_08013420: .4byte 0x00000193
_08013424: .4byte 0x08343F58
_08013428:
	ldr r0, _08013434 @ =0x000001AB
	cmp r5, r0
	bne _0801343C
	ldr r4, _08013438 @ =0x08343F60
	b _08013444
	.align 2, 0
_08013434: .4byte 0x000001AB
_08013438: .4byte 0x08343F60
_0801343C:
	ldr r0, _0801345C @ =0x000001B9
	cmp r5, r0
	bne _08013464
	ldr r4, _08013460 @ =0x08343F68
_08013444:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl patchBlockMap
	adds r1, r6, #1
	adds r0, r5, #0
	adds r2, r4, #0
	bl patchBlockMap
	b _0801347A
	.align 2, 0
_0801345C: .4byte 0x000001B9
_08013460: .4byte 0x08343F68
_08013464:
	ldr r4, _08013480 @ =0x08343F50
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl patchBlockMap
	adds r1, r6, #1
	adds r0, r5, #0
	adds r2, r4, #0
	bl patchBlockMap
_0801347A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013480: .4byte 0x08343F50
