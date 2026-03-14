	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ExlifeIndicator_Update
ExlifeIndicator_Update: @ 0x080BE540
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0x12]
	adds r2, r4, #1
	strb r2, [r3, #0x12]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bhi _080BE568
	ldr r1, _080BE564 @ =gSineTable
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xdc
	muls r0, r1, r0
	b _080BE588
	.align 2, 0
_080BE564: .4byte gSineTable
_080BE568:
	cmp r0, #0x7e
	bls _080BE58A
	ldr r1, _080BE5A8 @ =gSineTable
	lsls r0, r4, #0x19
	movs r2, #0x84
	lsls r2, r2, #0x17
	adds r0, r0, r2
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xdc
	muls r1, r0, r1
	movs r0, #0xdc
	lsls r0, r0, #9
	subs r0, r0, r1
_080BE588:
	str r0, [r3, #0x54]
_080BE58A:
	ldrb r0, [r3, #0x12]
	cmp r0, #0xa0
	bne _080BE5A2
	ldr r1, _080BE5AC @ =gVFXFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
_080BE5A2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE5A8: .4byte gSineTable
_080BE5AC: .4byte gVFXFnTable

