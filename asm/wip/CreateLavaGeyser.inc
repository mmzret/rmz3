	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov r8, r1
	adds r4, r2, #0
	adds r7, r3, #0
	movs r5, #0
	movs r6, #0
_080CC73E:
	ldr r0, _080CC7B4 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _080CC7A0
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CC7B8 @ =gSolidFnTable
	movs r0, #7
	strb r0, [r2, #9]
	ldr r0, [r1, #0x1c]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #0xc
	strb r0, [r2, #0x10]
	strb r5, [r2, #0x11]
	subs r0, r7, r4
	cmp r0, #0
	bge _080CC782
	rsbs r0, r0, #0
_080CC782:
	adds r1, r0, #0
	cmp r0, #0
	bge _080CC78C
	ldr r3, _080CC7BC @ =0x000007FF
	adds r1, r0, r3
_080CC78C:
	asrs r0, r1, #0xb
	strb r0, [r2, #0x13]
	mov r0, r8
	str r0, [r2, #0x54]
	str r4, [r2, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r4, r4, r3
	mov r0, sb
	str r0, [r2, #0x28]
_080CC7A0:
	adds r5, #1
	cmp r5, #5
	ble _080CC73E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC7B4: .4byte gSolidHeaderPtr
_080CC7B8: .4byte gSolidFnTable
_080CC7BC: .4byte 0x000007FF
