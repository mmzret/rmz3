	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatBatShower
hellbatBatShower: @ 0x0804BCF8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #6
	bls _0804BD06
	b _0804BECE
_0804BD06:
	lsls r0, r0, #2
	ldr r1, _0804BD10 @ =_0804BD14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BD10: .4byte _0804BD14
_0804BD14: @ jump table
	.4byte _0804BD30 @ case 0
	.4byte _0804BD52 @ case 1
	.4byte _0804BD7C @ case 2
	.4byte _0804BD94 @ case 3
	.4byte _0804BDFC @ case 4
	.4byte _0804BEA0 @ case 5
	.4byte _0804BEB8 @ case 6
_0804BD30:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BD78 @ =sCollisions+(1*24)
	bl SetDDP
	movs r1, #0
	movs r0, #0x28
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldr r0, [r6, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BD52:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BD72
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BD72
	b _0804BECE
_0804BD72:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BD78: .4byte sCollisions+(1*24)
_0804BD7C:
	movs r0, #0x85
	bl PlaySound
	ldr r1, _0804BDF4 @ =0x0000A811
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BD94:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0804BDCA
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804BDCA
	movs r0, #1
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BDF8 @ =0x08362FE0
	bl SetDDP
_0804BDCA:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BDD6
	b _0804BECE
_0804BDD6:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BDE6
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
_0804BDE6:
	movs r0, #6
	strb r0, [r6, #0x12]
	movs r0, #0x10
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BDF4: .4byte 0x0000A811
_0804BDF8: .4byte sCollisions+(6*24)
_0804BDFC:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BE20
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
_0804BE20:
	ldr r2, [r6, #0x54]
	str r2, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804BE3C
	ldr r1, _0804BE38 @ =0xFFFFE800
	b _0804BE40
	.align 2, 0
_0804BE38: .4byte 0xFFFFE800
_0804BE3C:
	movs r1, #0xc0
	lsls r1, r1, #5
_0804BE40:
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0804BE90 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r5, _0804BE94 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _0804BE98 @ =0x000343FD
	adds r2, r0, #0
	muls r2, r3, r2
	ldr r1, _0804BE9C @ =0x00269EC3
	adds r2, r2, r1
	lsls r2, r2, #1
	lsrs r0, r2, #1
	lsrs r2, r2, #0x11
	movs r4, #3
	ands r2, r4
	muls r3, r0, r3
	adds r3, r3, r1
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r5]
	lsrs r3, r3, #0x11
	ands r3, r4
	adds r0, r6, #0
	mov r1, sp
	bl createBat
	movs r0, #6
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BE90: .4byte 0xFFFFE000
_0804BE94: .4byte RNG_0202f388
_0804BE98: .4byte 0x000343FD
_0804BE9C: .4byte 0x00269EC3
_0804BEA0:
	ldr r1, _0804BED8 @ =0x0000A812
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BEDC @ =sCollisions+(1*24)
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BEB8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804BECE
	movs r0, #0
	strb r1, [r6, #0xd]
_0804BECC:
	strb r0, [r6, #0xe]
_0804BECE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BED8: .4byte 0x0000A812
_0804BEDC: .4byte sCollisions+(1*24)
