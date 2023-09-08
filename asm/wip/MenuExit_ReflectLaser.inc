	push {r4, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x28]
	adds r0, r1, #0
	adds r0, #0xb4
	ldrb r2, [r0, #0xe]
	cmp r2, #0
	beq _0803ACA2
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0803ACB8
_0803ACA2:
	movs r4, #0x9b
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803ACE6
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0803ACB8:
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
	ldr r1, _0803ACEC @ =gWeaponFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_0803ACE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ACEC: .4byte gWeaponFnTable
