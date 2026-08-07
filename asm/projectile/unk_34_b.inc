	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080accf0
FUN_080accf0: @ 0x080ACCF0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080ACD1E
	movs r1, #0
	str r1, [r2]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080ACE06
_080ACD1E:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080ACD44
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080ACD44
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080ACD44
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080ACE06
_080ACD44:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080ACD50
	cmp r0, #1
	beq _080ACDB8
	b _080ACE78
_080ACD50:
	ldr r2, _080ACE80 @ =0x0836C820
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _080ACE84 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080ACE88 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080ACE8C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldr r2, [r2]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, _080ACE90 @ =0x00000C01
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080ACE94 @ =0x0836C770
	bl SetDDP
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080ACDB8:
	ldrb r0, [r7, #0x12]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ACDD0
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
_080ACDD0:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080ACDE0
	str r1, [r7, #0x60]
_080ACDE0:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080ACE06
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ACE78
_080ACE06:
	ldr r0, [r7, #0x54]
	ldr r1, _080ACE98 @ =0xFFFFF700
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	movs r4, #0x90
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	ldr r0, [r7, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r4, [r7, #0x54]
	subs r4, #6
	ldr r2, _080ACE84 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080ACE88 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080ACE8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080ACE98 @ =0xFFFFF700
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r1, _080ACE9C @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080ACE78:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACE80: .4byte 0x0836C820
_080ACE84: .4byte RNG_0202f388
_080ACE88: .4byte 0x000343FD
_080ACE8C: .4byte 0x00269EC3
_080ACE90: .4byte 0x00000C01
_080ACE94: .4byte 0x0836C770
_080ACE98: .4byte 0xFFFFF700
_080ACE9C: .4byte gProjectileFnTable

	thumb_func_start FUN_080acea0
FUN_080acea0: @ 0x080ACEA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080ACEAC
	b _080ACFFA
_080ACEAC:
	lsls r0, r0, #2
	ldr r1, _080ACEB8 @ =_080ACEBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACEB8: .4byte _080ACEBC
_080ACEBC: @ jump table
	.4byte _080ACED0 @ case 0
	.4byte _080ACF08 @ case 1
	.4byte _080ACF28 @ case 2
	.4byte _080ACF94 @ case 3
	.4byte _080ACFCC @ case 4
_080ACED0:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080ACEFA
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	b _080ACF02
_080ACEFA:
	ldr r1, _080ACF24 @ =0x00000A03
	adds r0, r4, #0
	bl SetMotion
_080ACF02:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACF08:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _080ACF20
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _080ACFFA
_080ACF20:
	movs r0, #0x7f
	b _080ACFAE
	.align 2, 0
_080ACF24: .4byte 0x00000A03
_080ACF28:
	ldrb r5, [r4, #0x10]
	cmp r5, #0
	bne _080ACF54
	ldr r1, _080ACF4C @ =0x00000A01
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACF50 @ =0x0836C740
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x60]
	str r5, [r4, #0x5c]
	b _080ACF74
	.align 2, 0
_080ACF4C: .4byte 0x00000A01
_080ACF50: .4byte 0x0836C740
_080ACF54:
	ldr r1, _080ACFB8 @ =0x00000A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080ACFBC @ =0x0836C758
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
_080ACF74:
	ldr r2, _080ACFC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080ACFC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080ACFC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080ACF94:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080ACFFA
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xff
_080ACFAE:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080ACFFA
	.align 2, 0
_080ACFB8: .4byte 0x00000A04
_080ACFBC: .4byte 0x0836C758
_080ACFC0: .4byte RNG_0202f388
_080ACFC4: .4byte 0x000343FD
_080ACFC8: .4byte 0x00269EC3
_080ACFCC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080ACFFA
	ldr r1, _080AD000 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080ACFFA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD000: .4byte gProjectileFnTable

