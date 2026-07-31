	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c09c8
FUN_080c09c8: @ 0x080C09C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080C0A22
	cmp r5, #1
	bgt _080C09DC
	cmp r5, #0
	beq _080C09E2
	b _080C0A98
_080C09DC:
	cmp r5, #2
	beq _080C0A6A
	b _080C0A98
_080C09E2:
	ldr r1, _080C0A00 @ =0x0000B01C
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080C0A04
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080C0A0A
	.align 2, 0
_080C0A00: .4byte 0x0000B01C
_080C0A04:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080C0A5C @ =0xFFFFF400
_080C0A0A:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0A22:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C0A60
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080C0A98
	.align 2, 0
_080C0A5C: .4byte 0xFFFFF400
_080C0A60:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080C0A98
_080C0A6A:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080C0A98
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080C0AA0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C0A98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0AA0: .4byte gVFXFnTable
