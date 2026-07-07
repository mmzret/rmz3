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
	bl Malloc
	mov sb, r0
	cmp r0, #0
	bne _08012C1C
	b _08012FDA
_08012C1C:
	ldr r2, _08012F54 @ =gIntrManager
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
_08012F54: .4byte gIntrManager
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
