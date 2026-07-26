	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c182c
FUN_080c182c: @ 0x080C182C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C1840
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	b _080C1842
_080C1840:
	subs r0, #1
_080C1842:
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x64]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x68]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080C1882
	ldr r1, _080C1888 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX56_Die
_080C1882:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C1888: .4byte gVFXFnTable

	thumb_func_start FUN_080c188c
FUN_080c188c: @ 0x080C188C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C18A0
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x13]
	b _080C18A2
_080C18A0:
	subs r0, #1
_080C18A2:
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x64]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x68]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080C18E2
	ldr r1, _080C18E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX56_Die
_080C18E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C18E8: .4byte gVFXFnTable
