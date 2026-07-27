	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809eae8
FUN_0809eae8: @ 0x0809EAE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809EB3E
	cmp r0, #1
	bgt _0809EAFC
	cmp r0, #0
	beq _0809EB06
	b _0809EC04
_0809EAFC:
	cmp r0, #2
	beq _0809EBC6
	cmp r0, #3
	beq _0809EBE2
	b _0809EC04
_0809EB06:
	ldr r1, _0809EB74 @ =0x0000A302
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x64]
	movs r1, #0x36
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0809EB78 @ =0x00016C80
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x35
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EB3E:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0809EB6A
	subs r0, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EB7C
_0809EB6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809EC04
	.align 2, 0
_0809EB74: .4byte 0x0000A302
_0809EB78: .4byte 0x00016C80
_0809EB7C:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EBA0
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809EBF2
_0809EBA0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EC04
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EC04
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _0809EBF2
_0809EBC6:
	ldr r1, _0809EC0C @ =0x0000A303
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809EC10 @ =0x0836ADD8
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EBE2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809EC04
_0809EBF2:
	ldr r1, _0809EC14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809EC04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809EC0C: .4byte 0x0000A303
_0809EC10: .4byte 0x0836ADD8
_0809EC14: .4byte gProjectileFnTable
