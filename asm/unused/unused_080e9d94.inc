	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	lsls r2, r0, #0x10
	adds r0, r2, #0
	asrs r0, r0, #0x10
	mov r3, sp
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E9DFC @ =0xFFFF0000
	adds r0, r2, r1
	cmp r0, #0
	blt _080E9DE8
	movs r6, #0xf
	movs r5, #0xff
_080E9DC2:
	asrs r2, r0, #0x10
	mov r0, sp
	adds r3, r0, r2
	adds r1, r4, #0
	ands r1, r6
	adds r0, r1, #0
	adds r0, #0x30
	strb r0, [r3]
	ands r0, r5
	cmp r0, #0x39
	bls _080E9DDE
	adds r0, r1, #0
	adds r0, #0x37
	strb r0, [r3]
_080E9DDE:
	lsrs r4, r4, #4
	subs r0, r2, #1
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080E9DC2
_080E9DE8:
	mov r0, sp
	mov r1, ip
	adds r2, r7, #0
	bl PrintUnicodeString
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E9DFC: .4byte 0xFFFF0000
