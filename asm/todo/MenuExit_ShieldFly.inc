	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0xb4
	ldr r1, [r4]
	adds r5, r1, #0
	adds r5, #0xb4
	ldr r2, _08039A68 @ =0x00000232
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #0
	beq _08039A6C
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _08039A8A
	.align 2, 0
_08039A68: .4byte 0x00000232
_08039A6C:
	ldrb r0, [r5, #0xe]
	ldrb r4, [r4, #0xd]
	cmp r0, r4
	bne _08039A84
	movs r4, #0x9b
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08039AB8
_08039A84:
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08039A8A:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08039AC0 @ =gWeaponFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08039AB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08039AC0: .4byte gWeaponFnTable
