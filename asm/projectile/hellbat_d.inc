	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a1f1c
FUN_080a1f1c: @ 0x080A1F1C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080A1F4C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A1F4C
	ldr r1, _080A1F48 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2018
	.align 2, 0
_080A1F48: .4byte gProjectileFnTable
_080A1F4C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A1F58
	cmp r0, #1
	beq _080A1F84
	b _080A2018
_080A1F58:
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A1F6C
	movs r0, #0x12
	rsbs r0, r0, #0
	b _080A1F6E
_080A1F6C:
	movs r0, #0x12
_080A1F6E:
	str r0, [r4, #0x5c]
	movs r0, #0xc8
	strb r0, [r4, #0x12]
	movs r1, #0xa9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A1F84:
	ldr r0, [r4, #0x64]
	ldr r3, [r4, #0x5c]
	adds r1, r0, r3
	str r1, [r4, #0x64]
	adds r2, r1, #0
	cmp r1, #0
	bge _080A1F94
	rsbs r2, r1, #0
_080A1F94:
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble _080A1FA0
	subs r0, r1, r3
	str r0, [r4, #0x64]
_080A1FA0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A1FE4
	cmp r1, #0
	ble _080A1FBE
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToLeft1
	b _080A1FC6
_080A1FBE:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToRight1
_080A1FC6:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2012
	ldr r1, _080A1FE0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2012
	.align 2, 0
_080A1FE0: .4byte gProjectileFnTable
_080A1FE4:
	cmp r1, #0
	ble _080A1FF2
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToLeft1
	b _080A1FFA
_080A1FF2:
	ldr r1, [r4, #0x58]
	adds r0, r2, #0
	bl PushoutToRight1
_080A1FFA:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2012
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
_080A2012:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080A2018:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

