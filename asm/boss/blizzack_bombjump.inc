	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0805A5DE
	b _0805A6FC
_0805A5DE:
	ldr r1, _0805A628 @ =0x0000B403
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x2c]
	movs r7, #1
	strb r7, [r0, #0xe]
	ldr r0, [r5, #0x2c]
	adds r0, #0xbc
	movs r1, #0
	mov r8, r1
	ldr r1, _0805A62C @ =0x00006403
	strh r1, [r0]
	mov r0, r8
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r6, [r5, #0x54]
	subs r2, r0, r6
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r2, r0
	ble _0805A634
	ldr r4, _0805A630 @ =pZero2
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	subs r0, r0, r6
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #2
	strb r0, [r5, #0x13]
	mov sb, r4
	b _0805A6A8
	.align 2, 0
_0805A628: .4byte 0x0000B403
_0805A62C: .4byte 0x00006403
_0805A630: .4byte pZero2
_0805A634:
	ldr r0, _0805A658 @ =pZero2
	ldr r1, [r0]
	ldr r4, [r1, #0x54]
	subs r3, r4, r6
	movs r1, #0xa0
	lsls r1, r1, #7
	mov sb, r0
	cmp r3, r1
	ble _0805A65C
	adds r0, r3, #0
	movs r1, #0x34
	bl __divsi3
	str r0, [r5, #0x5c]
	mov r1, r8
	strb r1, [r5, #0x13]
	b _0805A6A8
	.align 2, 0
_0805A658: .4byte pZero2
_0805A65C:
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0805A69C
	ldr r2, _0805A690 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805A694 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805A698 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r7
	cmp r0, #0
	beq _0805A69C
	adds r0, r3, #0
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #2
	strb r0, [r5, #0x13]
	b _0805A6A8
	.align 2, 0
_0805A690: .4byte RNG_0202f388
_0805A694: .4byte 0x000343FD
_0805A698: .4byte 0x00269EC3
_0805A69C:
	subs r0, r6, r4
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x5c]
	strb r7, [r5, #0x13]
_0805A6A8:
	ldr r0, _0805A6F0 @ =0xFFFFF640
	str r0, [r5, #0x60]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	movs r2, #0
	mov r0, sb
	ldr r4, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0805A6C0
	movs r2, #1
_0805A6C0:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0805A6D2
	movs r3, #1
_0805A6D2:
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
	beq _0805A6F4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805A6FA
	.align 2, 0
_0805A6F0: .4byte 0xFFFFF640
_0805A6F4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805A6FA:
	strb r0, [r5, #0xa]
_0805A6FC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x60
	str r1, [r5, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0805A720
	str r0, [r5, #0x60]
_0805A720:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805A736
	movs r0, #0xe
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
_0805A736:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
