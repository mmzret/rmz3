	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c3f1c
FUN_080c3f1c: @ 0x080C3F1C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3F2C
	cmp r0, #1
	beq _080C3F3A
	b _080C3F66
_080C3F2C:
	ldr r1, _080C3F6C @ =0x00008004
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3F3A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C3F66
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F70 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3F66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F6C: .4byte 0x00008004
_080C3F70: .4byte gVFXFnTable
