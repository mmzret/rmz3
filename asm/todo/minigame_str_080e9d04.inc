	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	mov r6, r8
	cmp r6, #0
	bge _080E9D26
	rsbs r6, r6, #0
_080E9D26:
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #0x10]
	movs r7, #0xf
	b _080E9D40
_080E9D30:
	adds r0, r6, #0
	movs r1, #0xa
	bl __divsi3
	adds r6, r0, #0
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
_080E9D40:
	lsls r0, r7, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	ble _080E9D5C
	mov r0, sp
	adds r4, r0, r5
	adds r0, r6, #0
	movs r1, #0xa
	bl __modsi3
	adds r0, #0x30
	strb r0, [r4]
	cmp r6, #9
	bgt _080E9D30
_080E9D5C:
	mov r2, r8
	cmp r2, #0
	bge _080E9D72
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, sp
	adds r1, r2, r0
	movs r0, #0x2d
	strb r0, [r1]
_080E9D72:
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r2, sp
	adds r0, r2, r1
	subs r1, #0xf
	add r1, sb
	mov r2, sl
	bl PrintUnicodeString
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
