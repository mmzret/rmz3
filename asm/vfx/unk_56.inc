	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX56
CreateVFX56: @ 0x080C14F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080C1540 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C153A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1544 @ =gVFXFnTable
	movs r1, #0x38
	strb r1, [r3, #9]
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080C153A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C1540: .4byte gVFXHeaderPtr
_080C1544: .4byte gVFXFnTable

	thumb_func_start VFX56_Init
VFX56_Init: @ 0x080C1548
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C1590 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C1594 @ =0x00006001
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _080C1598 @ =0x0836F22C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C1590: .4byte gVFXFnTable
_080C1594: .4byte 0x00006001
_080C1598: .4byte 0x0836F22C

	thumb_func_start VFX56_Update
VFX56_Update: @ 0x080C159C
	push {lr}
	ldr r2, _080C15B0 @ =0x0836F238
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C15B0: .4byte 0x0836F238

	thumb_func_start VFX56_Die
VFX56_Die: @ 0x080C15B4
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C15D0 @ =gVFXFnTable
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
_080C15D0: .4byte gVFXFnTable

	thumb_func_start FUN_080c15d4
FUN_080c15d4: @ 0x080C15D4
	push {r4, lr}
	mov ip, r0
	ldr r3, [r0, #0x28]
	movs r2, #0
	ldrb r1, [r0, #0xa]
	movs r0, #0xef
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	mov r0, ip
	adds r0, #0x4c
	strb r2, [r0]
	mov r4, ip
	adds r4, #0x4a
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
	mov r1, ip
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r3, #0x54]
	ldr r1, [r3, #0x58]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r2, [r3, #0x12]
	mov r0, ip
	bl VFX56_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c161c
FUN_080c161c: @ 0x080C161C
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	movs r0, #0
	mov sl, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	mov r1, sl
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r5, _080C16EC @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _080C16F0 @ =0x000343FD
	mov sb, r3
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r3, _080C16F4 @ =0x00269EC3
	mov r8, r3
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r0, #3
	strb r0, [r4, #0x13]
	mov r0, sl
	strb r0, [r4, #0x12]
	mov r2, sb
	muls r2, r6, r2
	add r2, r8
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r5]
	lsrs r2, r2, #0x11
	movs r0, #0xff
	ands r2, r0
	adds r0, #1
	adds r2, r2, r0
	ldr r3, _080C16F8 @ =gSineTable
	ldrb r0, [r4, #0x11]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r5, r2, #0
	muls r5, r1, r5
	asrs r5, r5, #8
	str r5, [r4, #0x60]
	ldrb r2, [r4, #0x13]
	lsls r1, r2, #3
	subs r1, r1, r2
	bl __divsi3
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0x13]
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r0, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	adds r0, r4, #0
	bl VFX56_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C16EC: .4byte RNG_0202f388
_080C16F0: .4byte 0x000343FD
_080C16F4: .4byte 0x00269EC3
_080C16F8: .4byte gSineTable

	thumb_func_start FUN_080c16fc
FUN_080c16fc: @ 0x080C16FC
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	movs r0, #0
	mov sl, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	mov r1, sl
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x58]
	ldr r3, _080C17D4 @ =0xFFFFEC00
	adds r0, r0, r3
	str r0, [r4, #0x58]
	ldr r5, _080C17D8 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r1, _080C17DC @ =0x000343FD
	mov sb, r1
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	ldr r1, _080C17E0 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r5]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r0, #3
	strb r0, [r4, #0x13]
	mov r3, sl
	strb r3, [r4, #0x12]
	mov r2, sb
	muls r2, r6, r2
	add r2, r8
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r5]
	lsls r2, r2, #6
	lsrs r2, r2, #0x17
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r3, _080C17E4 @ =gSineTable
	ldrb r0, [r4, #0x11]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r5, r2, #0
	muls r5, r1, r5
	asrs r5, r5, #8
	str r5, [r4, #0x60]
	ldrb r2, [r4, #0x13]
	lsls r1, r2, #3
	subs r1, r1, r2
	bl __divsi3
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0x13]
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r0, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	adds r0, r4, #0
	bl VFX56_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C17D4: .4byte 0xFFFFEC00
_080C17D8: .4byte RNG_0202f388
_080C17DC: .4byte 0x000343FD
_080C17E0: .4byte 0x00269EC3
_080C17E4: .4byte gSineTable

	thumb_func_start FUN_080c17e8
FUN_080c17e8: @ 0x080C17E8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C17FC
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #3
	b _080C17FE
_080C17FC:
	subs r0, #1
_080C17FE:
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080C1822
	ldr r1, _080C1828 @ =gVFXFnTable
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
_080C1822:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C1828: .4byte gVFXFnTable

	thumb_func_start FUN_080c182c
FUN_080c182c: @ 0x080C182C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C1840
	adds r0, r4, #0
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
