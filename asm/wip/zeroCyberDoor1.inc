	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _0802CD80
	cmp r0, #1
	bgt _0802CDB2
	cmp r0, #0
	bne _0802CDB2
	ldr r1, _0802CD7C @ =0x00003601
	adds r0, r4, #0
	bl SetMotion
	b _0802CDAC
	.align 2, 0
_0802CD7C: .4byte 0x00003601
_0802CD80:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802CDB2
	adds r5, r4, #0
	adds r5, #0xfa
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0802CDA4
	adds r0, r1, #0
	bl stopSound
	ldr r0, _0802CDB8 @ =0x0000FFFF
	strh r0, [r5]
_0802CDA4:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_0802CDAC:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0802CDB2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CDB8: .4byte 0x0000FFFF
