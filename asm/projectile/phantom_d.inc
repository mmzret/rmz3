	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080af8e8
FUN_080af8e8: @ 0x080AF8E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AF912
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
	b _080AF97E
_080AF912:
	ldr r1, [r5, #0x54]
	str r1, [r4, #0x54]
	ldr r3, _080AF9A0 @ =gSineTable
	ldrb r2, [r4, #0x12]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r1, [r5, #0x58]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r2, #0x20
	adds r0, r4, #0
	adds r0, #0x24
	movs r5, #0
	strb r2, [r0]
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	ldr r0, _080AF9A4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF998
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_080AF97E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF9A8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF998:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF9A0: .4byte gSineTable
_080AF9A4: .4byte gStageRun+232
_080AF9A8: .4byte gProjectileFnTable

