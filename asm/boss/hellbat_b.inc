	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbat_0804cc38
hellbat_0804cc38: @ 0x0804CC38
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0804CC4E
	cmp r0, #0xe
	beq _0804CC4E
	cmp r0, #0xf
	bne _0804CC90
_0804CC4E:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804CC70
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804CC90
_0804CC70:
	ldr r0, _0804CC88 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0804CC90
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804CC8C
	movs r0, #0xff
	b _0804CC8E
	.align 2, 0
_0804CC88: .4byte gStageRun
_0804CC8C:
	movs r0, #0xfe
_0804CC8E:
	strb r0, [r2, #0x11]
_0804CC90:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0804CCC2
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804CCC2
	ldr r0, [r2, #4]
	ldr r1, _0804CCC8 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0804CCC2
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0804CCC2
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0804CCC2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CCC8: .4byte 0x000200FF
