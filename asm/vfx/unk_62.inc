	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX62
CreateVFX62: @ 0x080C34C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r4, #0
	movs r6, #0
	ldr r0, _080C351C @ =0x0836D9F8
	mov r8, r0
_080C34D2:
	ldr r0, _080C3520 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080C350A
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x3e
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r6, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r6, [r0]
	strb r6, [r1, #0x10]
	strb r4, [r1, #0x11]
	str r7, [r1, #0x28]
	ldr r0, [r5]
	str r0, [r1, #0x54]
	ldr r0, [r5, #4]
	str r0, [r1, #0x58]
_080C350A:
	adds r4, #1
	cmp r4, #2
	ble _080C34D2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C351C: .4byte 0x0836D9F8
_080C3520: .4byte gVFXHeaderPtr

	thumb_func_start VFX62_Init
VFX62_Init: @ 0x080C3524
	push {lr}
	ldr r2, _080C3538 @ =0x0836F4B0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C3538: .4byte 0x0836F4B0

	thumb_func_start VFX62_Update
VFX62_Update: @ 0x080C353C
	push {lr}
	ldr r2, _080C3550 @ =0x0836F4B4
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C3550: .4byte 0x0836F4B4

	thumb_func_start VFX62_Die
VFX62_Die: @ 0x080C3554
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C3570 @ =gVFXFnTable
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
_080C3570: .4byte gVFXFnTable

	thumb_func_start FUN_080c3574
FUN_080c3574: @ 0x080C3574
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xa]
	lsrs r5, r0, #4
	movs r0, #1
	ands r5, r0
	ldrb r4, [r7, #0x11]
	ldrb r1, [r7, #0xa]
	movs r6, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r2, r5, #0
	cmp r5, #0
	beq _080C35A4
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C35AA
_080C35A4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C35AA:
	strb r0, [r7, #0xa]
	movs r0, #1
	mov r8, r0
	ands r0, r2
	adds r6, r7, #0
	adds r6, #0x4c
	strb r0, [r6]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r0, r0, #4
	ldrb r2, [r3]
	movs r1, #0x11
	rsbs r1, r1, #0
	mov ip, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	cmp r4, #1
	bne _080C35E6
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	strb r4, [r6]
	movs r2, #0x10
	ldrb r1, [r3]
	mov r0, ip
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080C35E6:
	ldr r0, _080C3658 @ =0x0836F4B8
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r7, #0
	bl SetMotion
	cmp r5, #0
	beq _080C35FC
	movs r0, #2
	subs r4, r0, r4
_080C35FC:
	subs r1, r4, #1
	lsls r1, r1, #7
	ldr r6, _080C365C @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080C3660 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080C3664 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080C3668 @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080C366C @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080C3670 @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	ldr r1, _080C3674 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl VFX62_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3658: .4byte 0x0836F4B8
_080C365C: .4byte RNG_0202f388
_080C3660: .4byte 0x000343FD
_080C3664: .4byte 0x00269EC3
_080C3668: .4byte 0x000001FF
_080C366C: .4byte 0xFFFFFF00
_080C3670: .4byte 0xFFFFFE00
_080C3674: .4byte gVFXFnTable

	thumb_func_start FUN_080c3678
FUN_080c3678: @ 0x080C3678
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C36C0
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080C36C8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C36C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C36C8: .4byte gVFXFnTable
