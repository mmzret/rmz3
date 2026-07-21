	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080af65c
FUN_080af65c: @ 0x080AF65C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r5, r1, r0
	str r5, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r3, r1, r0
	str r3, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080AF6B2
	ldr r2, _080AF700 @ =gSineTable
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r0, r5, r0
	adds r1, r3, r1
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AF6B2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0x10]
	strb r1, [r4, #0xd]
_080AF6B2:
	ldr r0, _080AF704 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF6FA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF708 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF6FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF700: .4byte gSineTable
_080AF704: .4byte gStageRun+232
_080AF708: .4byte gProjectileFnTable

