	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Volteel_OnCollision
Volteel_OnCollision: @ 0x0804586C
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _08045882
	cmp r0, #0xe
	beq _08045882
	cmp r0, #0xf
	bne _080458C4
_08045882:
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
	bne _080458A4
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080458C4
_080458A4:
	ldr r0, _080458BC @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080458C4
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _080458C0
	movs r0, #0xff
	b _080458C2
	.align 2, 0
_080458BC: .4byte gStageRun
_080458C0:
	movs r0, #0xfe
_080458C2:
	strb r0, [r2, #0x11]
_080458C4:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _08045904
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08045904
	ldr r0, [r2, #4]
	ldr r1, _0804590C @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08045904
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xc
	beq _08045904
	cmp r0, #9
	beq _08045904
	cmp r0, #5
	bne _080458FC
	ldrb r0, [r2, #0xe]
	cmp r0, #4
	bhi _08045904
_080458FC:
	movs r1, #0
	movs r0, #0xc
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08045904:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804590C: .4byte 0x000200FF
