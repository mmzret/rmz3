	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX63
CreateVFX63: @ 0x080C36CC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r3, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, _080C3728 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C371E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C372C @ =gVFXFnTable
	movs r1, #0x3f
	strb r1, [r3, #9]
	adds r0, #0xfc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x74
	strh r6, [r0]
	str r7, [r3, #0x78]
_080C371E:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C3728: .4byte gVFXHeaderPtr
_080C372C: .4byte gVFXFnTable

	thumb_func_start VFX63_Init
VFX63_Init: @ 0x080C3730
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080C376C
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080C378C
_080C376C:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080C378C:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C3798
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080C379A
_080C3798:
	movs r0, #0xc0
_080C379A:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r3, [r4, #0x11]
	cmp r3, #0
	bne _080C37DA
	ldr r2, _080C37E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C37EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C37F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080C37F4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r3, [r4, #0xd]
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
_080C37DA:
	adds r0, r4, #0
	bl VFX63_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C37E8: .4byte RNG_0202f388
_080C37EC: .4byte 0x000343FD
_080C37F0: .4byte 0x00269EC3
_080C37F4: .4byte gVFXFnTable

	thumb_func_start VFX63_Update
VFX63_Update: @ 0x080C37F8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C3824 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080C382C
	ldr r1, _080C3828 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl VFX63_Die
	b _080C383C
	.align 2, 0
_080C3824: .4byte gCurStory
_080C3828: .4byte gVFXFnTable
_080C382C:
	ldr r0, _080C3840 @ =0x0836F4D4
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080C383C:
	pop {r0}
	bx r0
	.align 2, 0
_080C3840: .4byte 0x0836F4D4

	thumb_func_start VFX63_Die
VFX63_Die: @ 0x080C3844
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C3860 @ =gVFXFnTable
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
_080C3860: .4byte gVFXFnTable

	thumb_func_start FUN_080c3864
FUN_080c3864: @ 0x080C3864
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3882
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	b _080C38A8
_080C3882:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C38C4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C38C4
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C38C4
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #3
_080C38A8:
	bl CreateSmoke
	ldr r1, _080C38C0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C3992
	.align 2, 0
_080C38C0: .4byte gVFXFnTable
_080C38C4:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C38D2
	cmp r0, #1
	beq _080C393C
	b _080C3992
_080C38D2:
	ldr r4, _080C3954 @ =0x0836F538
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080C3958 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C395C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C3960 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C393C:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C3964
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C396A
	.align 2, 0
_080C3954: .4byte 0x0836F538
_080C3958: .4byte RNG_0202f388
_080C395C: .4byte 0x000343FD
_080C3960: .4byte 0x00269EC3
_080C3964:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C396A:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C397C
	str r1, [r7, #0x60]
_080C397C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080C3992:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

