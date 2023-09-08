	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateGhost65
CreateGhost65: @ 0x080C4250
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080C42A0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C429A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C42A4 @ =gVFXFnTable
	movs r1, #0x41
	strb r1, [r3, #9]
	adds r1, #0xc3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	strb r4, [r3, #0x12]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
_080C429A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C42A0: .4byte gVFXHeaderPtr
_080C42A4: .4byte gVFXFnTable

	thumb_func_start Ghost65_Init
Ghost65_Init: @ 0x080C42A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C42E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080C42EC @ =0x0836F59C
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl Ghost65_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C42E8: .4byte gVFXFnTable
_080C42EC: .4byte 0x0836F59C

	thumb_func_start Ghost65_Update
Ghost65_Update: @ 0x080C42F0
	push {lr}
	ldr r2, _080C4304 @ =0x0836F598
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C4304: .4byte 0x0836F598

	thumb_func_start Ghost65_Die
Ghost65_Die: @ 0x080C4308
	ldr r2, _080C431C @ =gVFXFnTable
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
_080C431C: .4byte gVFXFnTable

	thumb_func_start FUN_080c4320
FUN_080c4320: @ 0x080C4320
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080C4334
	cmp r0, #1
	beq _080C43BA
	b _080C443C
_080C4334:
	ldr r0, _080C4354 @ =0x0836F59E
	ldrb r1, [r7, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0x12]
	cmp r2, #0
	beq _080C4358
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080C435E
	.align 2, 0
_080C4354: .4byte 0x0836F59E
_080C4358:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C435E:
	strb r0, [r7, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	movs r2, #0
	mov r8, r2
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r6, _080C43F4 @ =0xFFFFFE00
	ldr r5, _080C43F8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080C43FC @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080C4400 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r0, r6, r0
	str r0, [r7, #0x60]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r0, r0, r6
	str r0, [r7, #0x5c]
	mov r0, r8
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C43BA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C43D8
	str r1, [r7, #0x60]
_080C43D8:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C4404
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C440A
	.align 2, 0
_080C43F4: .4byte 0xFFFFFE00
_080C43F8: .4byte RNG_0202f388
_080C43FC: .4byte 0x000343FD
_080C4400: .4byte 0x00269EC3
_080C4404:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C440A:
	strb r0, [r7, #0xa]
	ldr r0, _080C4448 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _080C443C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080C444C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080C443C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4448: .4byte gStageRun+232
_080C444C: .4byte gVFXFnTable
