	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08074208
FUN_08074208: @ 0x08074208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080742E2
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _080742E2
	ldrb r5, [r4, #0xf]
	cmp r5, #0
	beq _08074228
	cmp r5, #1
	beq _080742B8
	b _080742E2
_08074228:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080742E2
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bne _0807427C
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	cmp r0, #0
	bge _08074250
	movs r0, #0xb
	b _08074252
_08074250:
	movs r0, #4
_08074252:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldr r2, [r4, #0x2c]
	cmp r2, #0
	beq _0807427C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080742AC @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_0807427C:
	ldr r1, _080742B0 @ =0x08366E30
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080742B4 @ =0x08366E60
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080742A8:
	movs r0, #1
	b _080742E4
	.align 2, 0
_080742AC: .4byte gVFXFnTable
_080742B0: .4byte PTR_ARRAY_08366e30
_080742B4: .4byte PTR_ARRAY_08366e60
_080742B8:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080742E0
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bls _080742A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	ands r5, r1
	cmp r5, #0
	beq _080742A8
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	bne _080742E2
	b _080742A8
_080742E0:
	strb r0, [r4, #0xf]
_080742E2:
	movs r0, #0
_080742E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
