	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatEchoWave
hellbatEchoWave: @ 0x0804BEE4
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0804BEF2
	b _0804C218
_0804BEF2:
	lsls r0, r0, #2
	ldr r1, _0804BEFC @ =_0804BF00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BEFC: .4byte _0804BF00
_0804BF00: @ jump table
	.4byte _0804BF38 @ case 0
	.4byte _0804BF5C @ case 1
	.4byte _0804BFC0 @ case 2
	.4byte _0804BFF8 @ case 3
	.4byte _0804C1F4 @ case 4
	.4byte _0804C03C @ case 5
	.4byte _0804C150 @ case 6
	.4byte _0804C162 @ case 7
	.4byte _0804C17E @ case 8
	.4byte _0804C1B0 @ case 9
	.4byte _0804C1EE @ case 10
	.4byte _0804C1DC @ case 11
	.4byte _0804C1EE @ case 12
	.4byte _0804C210 @ case 13
_0804BF38:
	ldr r1, _0804BF84 @ =0x0000A80F
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BF88 @ =0x08363148
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x5c]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804BF5C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BF6E
	b _0804C218
_0804BF6E:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0804BF8C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BF92
	.align 2, 0
_0804BF84: .4byte 0x0000A80F
_0804BF88: .4byte sCollisions+(21*24)
_0804BF8C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BF92:
	strb r0, [r4, #0xa]
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _0804BFA6
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BFA6
	b _0804C218
_0804BFA6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BFBC @ =sCollisions
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	b _0804C204
	.align 2, 0
_0804BFBC: .4byte sCollisions
_0804BFC0:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BFD2
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BFD8
_0804BFD2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BFD8:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BFF2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BFF2
	b _0804C218
_0804BFF2:
	movs r0, #0
	strb r0, [r4, #0x12]
	b _0804C204
_0804BFF8:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804C00C
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	adds r0, r0, r1
	b _0804C016
_0804C00C:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	subs r0, r0, r1
_0804C016:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0x27
	bhi _0804C032
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _0804C032
	b _0804C218
_0804C032:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	b _0804C14A
_0804C03C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804C09C @ =0x0000A810
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C0A0 @ =sCollisions+(1*24)
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r0, _0804C0A4 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r3, _0804C0A8 @ =0xFFFF9000
	adds r0, r0, r3
	ldr r5, [r1]
	subs r6, r5, r0
	cmp r6, #0
	bgt _0804C06E
	subs r6, r0, r5
_0804C06E:
	str r6, [sp]
	ldr r0, [r2, #0x54]
	ldr r3, _0804C0AC @ =0xFFFF5000
	adds r0, r0, r3
	subs r3, r5, r0
	cmp r3, #0
	bgt _0804C07E
	subs r3, r0, r5
_0804C07E:
	str r3, [sp, #4]
	ldr r0, [r2, #0x54]
	ldr r2, _0804C0B0 @ =0xFFFF1000
	adds r0, r0, r2
	subs r2, r5, r0
	cmp r2, #0
	bgt _0804C08E
	subs r2, r0, r5
_0804C08E:
	str r2, [sp, #8]
	cmp r6, r3
	bge _0804C0B4
	movs r0, #2
	cmp r6, r2
	bge _0804C0BC
	b _0804C0C0
	.align 2, 0
_0804C09C: .4byte 0x0000A810
_0804C0A0: .4byte sCollisions+(1*24)
_0804C0A4: .4byte pZero2
_0804C0A8: .4byte 0xFFFF9000
_0804C0AC: .4byte 0xFFFF5000
_0804C0B0: .4byte 0xFFFF1000
_0804C0B4:
	movs r0, #2
	cmp r3, r2
	bge _0804C0BC
	movs r0, #1
_0804C0BC:
	cmp r0, #0
	bne _0804C0CA
_0804C0C0:
	ldr r0, [r1]
	movs r3, #0xe0
	lsls r3, r3, #7
	adds r0, r0, r3
	b _0804C0E0
_0804C0CA:
	cmp r0, #1
	bne _0804C0D8
	ldr r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r0, r1
	b _0804C0E0
_0804C0D8:
	ldr r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r0, r0, r2
_0804C0E0:
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x64]
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r3, _0804C120 @ =0xFFFFCE00
	adds r0, r0, r3
	str r0, [r4, #0x58]
	ldr r0, _0804C124 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0804C128
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804C10A
	b _0804C204
_0804C10A:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	b _0804C14C
	.align 2, 0
_0804C120: .4byte 0xFFFFCE00
_0804C124: .4byte pZero2
_0804C128:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804C204
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
_0804C14A:
	ands r0, r1
_0804C14C:
	strb r0, [r4, #0xa]
	b _0804C204
_0804C150:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C218
	b _0804C204
_0804C162:
	ldr r1, _0804C1A8 @ =0x0000A809
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x86
	bl PlaySound
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C17E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0804C1F4
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804C1F4
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C1AC @ =sCollisions+(13*24)
	bl SetDDP
	b _0804C1F4
	.align 2, 0
_0804C1A8: .4byte 0x0000A809
_0804C1AC: .4byte sCollisions+(13*24)
_0804C1B0:
	movs r5, #0
	add r6, sp, #0xc
_0804C1B4:
	ldr r0, [r4, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x58]
	ldr r1, _0804C1D8 @ =0xFFFFD600
	adds r0, r0, r1
	str r0, [r6, #4]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r6, #0
	bl createEchoWave
	adds r5, #1
	cmp r5, #5
	ble _0804C1B4
	movs r0, #0x20
	b _0804C1E6
	.align 2, 0
_0804C1D8: .4byte 0xFFFFD600
_0804C1DC:
	ldr r1, _0804C20C @ =0x0000A80A
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
_0804C1E6:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C1EE:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804C1F4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C204
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C218
_0804C204:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804C218
	.align 2, 0
_0804C20C: .4byte 0x0000A80A
_0804C210:
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804C218:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
