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

	thumb_func_start ExlifeIndicator_Die
ExlifeIndicator_Die: @ 0x080BE5B0
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BE5CC @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BE5CC: .4byte gVFXFnTable

	thumb_func_start FUN_080be5d0
FUN_080be5d0: @ 0x080BE5D0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, [r5, #8]
	ldr r1, [r4, #0x54]
	ldr r0, _080BE648 @ =0xFFFF8800
	adds r1, r1, r0
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r4, #0x58]
	ldr r0, _080BE64C @ =0xFFFFB000
	adds r1, r1, r0
	ldr r0, [r6, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _080BE650 @ =sMotions
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	mov r0, sp
	str r0, [r4, #0x40]
	ldr r2, [r5, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _080BE654 @ =FUN_080be5d0
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BE648: .4byte 0xFFFF8800
_080BE64C: .4byte 0xFFFFB000
_080BE650: .4byte sMotions
_080BE654: .4byte FUN_080be5d0
