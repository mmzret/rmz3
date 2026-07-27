	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803ff28
FUN_0803ff28: @ 0x0803FF28
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0803FF40
	cmp r0, #0xe
	beq _0803FF40
	cmp r0, #0xf
	bne _0803FF80
_0803FF40:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0803FF5E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0803FF80
_0803FF5E:
	ldr r0, _0803FF78 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0803FF80
	ldr r1, [r2, #0x54]
	ldr r0, [r4]
	cmp r1, r0
	bge _0803FF7C
	movs r0, #0xff
	b _0803FF7E
	.align 2, 0
_0803FF78: .4byte gStageRun
_0803FF7C:
	movs r0, #0xfe
_0803FF7E:
	strb r0, [r2, #0x11]
_0803FF80:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0803FFB6
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0803FFB6
	ldr r0, [r2, #4]
	ldr r1, _0803FFBC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0803FFB6
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0803FFB6
	cmp r0, #5
	beq _0803FFB6
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803FFB6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FFBC: .4byte 0x000200FF
