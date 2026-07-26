	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start GlacierleArm_Die
GlacierleArm_Die: @ 0x080CEA5C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x3f
	bl PlaySound
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
	movs r5, #0
	ldr r1, _080CEAF0 @ =0x0837053A
	ldrb r0, [r4, #0x12]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080CEAB6
	adds r6, r1, #0
_080CEA8E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r3, [r2]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #8
	rsbs r2, r2, #0
	bl CreateIcicleParticle
	adds r5, #1
	ldrb r0, [r4, #0x12]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	blt _080CEA8E
_080CEAB6:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CEAF8
	ldr r3, [r4, #0x28]
	ldrb r0, [r3, #0xc]
	cmp r0, #1
	bhi _080CEADC
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, #4
	ldr r2, [r0]
	adds r0, r3, #0
	bl CreateSolidGlacierleArm
_080CEADC:
	ldr r1, _080CEAF4 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	b _080CEB1E
	.align 2, 0
_080CEAF0: .4byte 0x0837053A
_080CEAF4: .4byte gSolidFnTable
_080CEAF8:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r4, #0x58]
	ldr r1, _080CEB24 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0x10]
_080CEB1E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CEB24: .4byte gSolidFnTable
