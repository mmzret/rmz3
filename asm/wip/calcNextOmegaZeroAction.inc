	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	ldr r0, _0805D5F8 @ =pZero2
	ldr r0, [r0]
	mov r2, ip
	ldr r1, [r2, #0x54]
	ldr r0, [r0, #0x54]
	subs r1, r1, r0
	cmp r1, #0
	bge _0805D5EC
	rsbs r1, r1, #0
_0805D5EC:
	ldr r0, _0805D5FC @ =0x00004FFF
	cmp r1, r0
	bgt _0805D600
	movs r1, #0
	b _0805D612
	.align 2, 0
_0805D5F8: .4byte pZero2
_0805D5FC: .4byte 0x00004FFF
_0805D600:
	ldr r0, _0805D60C @ =0x000077FF
	cmp r1, r0
	bgt _0805D610
	movs r1, #1
	b _0805D612
	.align 2, 0
_0805D60C: .4byte 0x000077FF
_0805D610:
	movs r1, #2
_0805D612:
	ldr r0, _0805D62C @ =RNG_0202f388
	mov r8, r0
	mov r5, ip
	adds r5, #0xc5
	ldr r2, _0805D630 @ =sModes
	mov sb, r2
	lsls r7, r1, #4
	mov r4, ip
	adds r4, #0xc6
	mov r6, ip
	adds r6, #0xa4
	b _0805D638
	.align 2, 0
_0805D62C: .4byte RNG_0202f388
_0805D630: .4byte sModes
_0805D634:
	cmp r2, #0x14
	bne _0805D66C
_0805D638:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, _0805D680 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805D684 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r3, r0, #0x11
	movs r0, #0xf
	ands r3, r0
	adds r0, r3, r7
	add r0, sb
	ldrb r1, [r5]
	ldrb r2, [r0]
	cmp r1, r2
	bne _0805D664
	ldrb r0, [r4]
	cmp r0, #0
	bne _0805D638
_0805D664:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0x20
	bgt _0805D634
_0805D66C:
	adds r0, r3, r7
	add r0, sb
	ldrb r1, [r0]
	ldrb r0, [r5]
	cmp r0, r1
	bne _0805D688
	ldrb r0, [r4]
	adds r0, #1
	b _0805D68C
	.align 2, 0
_0805D680: .4byte 0x000343FD
_0805D684: .4byte 0x00269EC3
_0805D688:
	movs r0, #0
	strb r1, [r5]
_0805D68C:
	strb r0, [r4]
	adds r0, r3, r7
	add r0, sb
	ldrb r0, [r0]
	movs r1, #0
	mov r2, ip
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
