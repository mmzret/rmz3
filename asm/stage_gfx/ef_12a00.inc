	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	ldr r7, _08012A60 @ =gSolidFnTable
_08012A0A:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r3, r0, r6
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08012A4C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r5, [r3, #0x68]
_08012A4C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08012A0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012A60: .4byte gSolidFnTable
