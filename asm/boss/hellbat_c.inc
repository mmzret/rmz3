	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatDisappear
hellbatDisappear: @ 0x0804BA44
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804BA50
	b _0804BCEE
_0804BA50:
	lsls r0, r0, #2
	ldr r1, _0804BA5C @ =_0804BA60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BA5C: .4byte _0804BA60
_0804BA60: @ jump table
	.4byte _0804BA84 @ case 0
	.4byte _0804BAA8 @ case 1
	.4byte _0804BB10 @ case 2
	.4byte _0804BB4C @ case 3
	.4byte _0804BB98 @ case 4
	.4byte _0804BBB0 @ case 5
	.4byte _0804BC5C @ case 6
	.4byte _0804BC7C @ case 7
	.4byte _0804BCD8 @ case 8
_0804BA84:
	ldr r1, _0804BAD0 @ =0x0000A80F
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BAD4 @ =0x08363148
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
_0804BAA8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BABA
	b _0804BCEE
_0804BABA:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0804BAD8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BADE
	.align 2, 0
_0804BAD0: .4byte 0x0000A80F
_0804BAD4: .4byte sCollisions+(21*24)
_0804BAD8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BADE:
	strb r0, [r4, #0xa]
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _0804BAF2
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BAF2
	b _0804BCEE
_0804BAF2:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BB0C @ =sCollisions
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
	.align 2, 0
_0804BB0C: .4byte sCollisions
_0804BB10:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BB22
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BB28
_0804BB22:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BB28:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BB42
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BB42
	b _0804BCEE
_0804BB42:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BB4C:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BB60
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	adds r0, r0, r1
	b _0804BB6A
_0804BB60:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	subs r0, r0, r1
_0804BB6A:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0x27
	bhi _0804BB86
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _0804BB86
	b _0804BCEE
_0804BB86:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BB98:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BBAA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BBAA
	b _0804BCEE
_0804BBAA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BBB0:
	ldr r2, _0804BC1C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804BC20 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804BC24 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0xd0
	ldr r0, [r0]
	adds r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r4, #0x64]
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r2, _0804BC28 @ =0xFFFFB800
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, _0804BC2C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0804BC30
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804BC56
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
	b _0804BC54
	.align 2, 0
_0804BC1C: .4byte RNG_0202f388
_0804BC20: .4byte 0x000343FD
_0804BC24: .4byte 0x00269EC3
_0804BC28: .4byte 0xFFFFB800
_0804BC2C: .4byte pZero2
_0804BC30:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804BC56
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
	ands r0, r1
_0804BC54:
	strb r0, [r4, #0xa]
_0804BC56:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BC5C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804BC98 @ =0x0000A810
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804BC7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BC9C
	lsrs r1, r1, #1
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	b _0804BCA6
	.align 2, 0
_0804BC98: .4byte 0x0000A810
_0804BC9C:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x19
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	subs r0, r0, r1
_0804BCA6:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BCBE
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BCEE
_0804BCBE:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BCD4 @ =sCollisions+(1*24)
	bl SetDDP
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
	.align 2, 0
_0804BCD4: .4byte sCollisions+(1*24)
_0804BCD8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804BCEE
	movs r0, #0
	strb r1, [r4, #0xd]
_0804BCEC:
	strb r0, [r4, #0xe]
_0804BCEE:
	pop {r4}
	pop {r0}
	bx r0
