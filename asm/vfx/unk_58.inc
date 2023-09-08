	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c1b98
FUN_080c1b98: @ 0x080C1B98
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C1BE4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1BDA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1BE8 @ =gVFXFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080C1BDA:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080C1BE4: .4byte gVFXHeaderPtr
_080C1BE8: .4byte gVFXFnTable

	thumb_func_start FUN_080c1bec
FUN_080c1bec: @ 0x080C1BEC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C1C3C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1C32
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1C40 @ =gVFXFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080C1C32:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1C3C: .4byte gVFXHeaderPtr
_080C1C40: .4byte gVFXFnTable

	thumb_func_start FUN_080c1c44
FUN_080c1c44: @ 0x080C1C44
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C1C8C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1C84
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1C90 @ =gVFXFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080C1C84:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1C8C: .4byte gVFXHeaderPtr
_080C1C90: .4byte gVFXFnTable

	thumb_func_start FUN_080c1c94
FUN_080c1c94: @ 0x080C1C94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, _080C1CEC @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1CE4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1CF0 @ =gVFXFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #6
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0x80
	strh r6, [r0]
_080C1CE4:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1CEC: .4byte gVFXHeaderPtr
_080C1CF0: .4byte gVFXFnTable

	thumb_func_start FUN_080c1cf4
FUN_080c1cf4: @ 0x080C1CF4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r0, _080C1D54 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1D4C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C1D58 @ =gVFXFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #7
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0x82
	strh r6, [r0]
	subs r0, #2
	strh r7, [r0]
_080C1D4C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C1D54: .4byte gVFXHeaderPtr
_080C1D58: .4byte gVFXFnTable

	thumb_func_start VFX58_Init
VFX58_Init: @ 0x080C1D5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0x10]
	cmp r6, #0
	bne _080C1DA0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #8
	strb r0, [r7, #0x12]
	ldr r1, _080C1D9C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r6, [r7, #0xe]
	strb r6, [r7, #0xf]
	b _080C20D2
	.align 2, 0
_080C1D9C: .4byte gVFXFnTable
_080C1DA0:
	cmp r6, #1
	bne _080C1DD8
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #8
	strb r0, [r7, #0x12]
	ldr r1, _080C1DD4 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r2, [r7, #0xe]
	strb r2, [r7, #0xf]
	b _080C20D2
	.align 2, 0
_080C1DD4: .4byte gVFXFnTable
_080C1DD8:
	cmp r6, #2
	bne _080C1E1C
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	str r2, [r7, #0x74]
	str r2, [r7, #0x78]
	ldr r1, _080C1E18 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r2, [r7, #0xe]
	strb r2, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	b _080C20D2
	.align 2, 0
_080C1E18: .4byte gVFXFnTable
_080C1E1C:
	cmp r6, #3
	bne _080C1E64
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	str r2, [r7, #0x74]
	str r2, [r7, #0x78]
	ldr r1, _080C1E60 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r2, [r7, #0xe]
	strb r2, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0xa0
	strb r0, [r7, #0x12]
	b _080C20D2
	.align 2, 0
_080C1E60: .4byte gVFXFnTable
_080C1E64:
	cmp r6, #4
	beq _080C1E6A
	b _080C1FDC
_080C1E6A:
	movs r4, #0x3c
	ldr r0, _080C1F34 @ =0x085D79E8
	ldr r1, _080C1F38 @ =wStaticGraphicTilenums
	ldrh r1, [r1, #0x18]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080C1F3C @ =0x085D79F4
	ldr r1, _080C1F40 @ =wStaticMotionPalIDs
	ldrh r1, [r1, #0x18]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r1, #0
	strb r4, [r7, #0x12]
	ldr r0, _080C1F44 @ =gVFXFnTable
	mov ip, r0
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, ip
	movs r5, #1
	str r5, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r1, [r7, #0xe]
	strb r1, [r7, #0xf]
	ldr r3, _080C1F48 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r4, _080C1F4C @ =0x000343FD
	muls r0, r4, r0
	ldr r2, _080C1F50 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	mov sb, r0
	ands r0, r5
	mov sb, r0
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	mov r8, r0
	mov r1, r8
	ands r1, r5
	mov r8, r1
	movs r4, #0
	mov sl, r4
	adds r5, r3, #0
	mov r6, ip
	adds r6, #0xe8
_080C1EF0:
	ldr r0, _080C1F54 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C1FC6
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x3a
	strb r0, [r3, #9]
	ldr r0, [r6]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	mov r2, sl
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	mov r1, sl
	strb r1, [r0]
	movs r0, #5
	strb r0, [r3, #0x10]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	mov r2, sb
	cmp r2, #0
	bne _080C1F5C
	ldr r0, _080C1F58 @ =0x080FF13C
	b _080C1F5E
	.align 2, 0
_080C1F34: .4byte 0x085D79E8
_080C1F38: .4byte wStaticGraphicTilenums
_080C1F3C: .4byte 0x085D79F4
_080C1F40: .4byte wStaticMotionPalIDs
_080C1F44: .4byte gVFXFnTable
_080C1F48: .4byte RNG_0202f388
_080C1F4C: .4byte 0x000343FD
_080C1F50: .4byte 0x00269EC3
_080C1F54: .4byte gVFXHeaderPtr
_080C1F58: .4byte 0x080FF13C
_080C1F5C:
	ldr r0, _080C1F90 @ =0x080FF124
_080C1F5E:
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r0, [r1]
	asrs r0, r0, #1
	str r0, [r3, #0x5c]
	ldr r2, [r3, #0x5c]
	subs r2, #0x20
	ldr r1, [r5]
	ldr r0, _080C1F94 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C1F98 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r3, #0x5c]
	mov r2, r8
	cmp r2, #0
	bne _080C1FA0
	ldr r1, _080C1F9C @ =0x080FF10C
	b _080C1FA2
	.align 2, 0
_080C1F90: .4byte 0x080FF124
_080C1F94: .4byte 0x000343FD
_080C1F98: .4byte 0x00269EC3
_080C1F9C: .4byte 0x080FF10C
_080C1FA0:
	ldr r1, _080C1FD0 @ =0x080FF118
_080C1FA2:
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	ldr r1, [r5]
	ldr r0, _080C1FD4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C1FD8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r0, #0x80
	str r0, [r3, #0x60]
_080C1FC6:
	adds r4, #1
	cmp r4, #5
	ble _080C1EF0
	b _080C20D2
	.align 2, 0
_080C1FD0: .4byte 0x080FF118
_080C1FD4: .4byte 0x000343FD
_080C1FD8: .4byte 0x00269EC3
_080C1FDC:
	cmp r6, #5
	bne _080C203C
	adds r0, r7, #0
	bl InitScalerotMotion1
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r2, _080C202C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C2030 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C2034 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x3c
	strb r0, [r7, #0x12]
	ldr r1, _080C2038 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r6, [r7, #0xd]
	strb r3, [r7, #0xe]
	strb r3, [r7, #0xf]
	b _080C20D2
	.align 2, 0
_080C202C: .4byte RNG_0202f388
_080C2030: .4byte 0x000343FD
_080C2034: .4byte 0x00269EC3
_080C2038: .4byte gVFXFnTable
_080C203C:
	cmp r6, #6
	bne _080C2084
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080C2080 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #7
	strb r0, [r7, #0xd]
	strb r2, [r7, #0xe]
	strb r2, [r7, #0xf]
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r1, [r2]
	subs r0, #0x14
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	b _080C20D2
	.align 2, 0
_080C2080: .4byte gVFXFnTable
_080C2084:
	cmp r6, #7
	bne _080C20D2
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080C20E8 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #8
	strb r0, [r7, #0xd]
	strb r2, [r7, #0xe]
	strb r2, [r7, #0xf]
	adds r0, r7, #0
	adds r0, #0x82
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bne _080C20D2
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	subs r1, #0xe
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r2]
_080C20D2:
	adds r0, r7, #0
	bl VFX58_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C20E8: .4byte gVFXFnTable

	thumb_func_start VFX58_Update
VFX58_Update: @ 0x080C20EC
	push {lr}
	ldr r2, _080C2100 @ =0x0836F26C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C2100: .4byte 0x0836F26C

	thumb_func_start VFX58_Die
VFX58_Die: @ 0x080C2104
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C2120 @ =gVFXFnTable
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
_080C2120: .4byte gVFXFnTable

	thumb_func_start FUN_080c2124
FUN_080c2124: @ 0x080C2124
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080C2142
	movs r0, #8
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080C2162
_080C2142:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C214E
	cmp r0, #1
	beq _080C215C
	b _080C2162
_080C214E:
	ldr r1, _080C2168 @ =0x00000A08
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C215C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C2162:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C2168: .4byte 0x00000A08

	thumb_func_start FUN_080c216c
FUN_080c216c: @ 0x080C216C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C2194
	ldr r1, _080C2190 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C21B4
	.align 2, 0
_080C2190: .4byte gVFXFnTable
_080C2194:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C21A0
	cmp r0, #1
	beq _080C21AE
	b _080C21B4
_080C21A0:
	ldr r1, _080C21BC @ =0x00000A09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C21AE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C21B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C21BC: .4byte 0x00000A09

	thumb_func_start FUN_080c21c0
FUN_080c21c0: @ 0x080C21C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080C21E4
	ldr r1, _080C21E0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C2288
	.align 2, 0
_080C21E0: .4byte gVFXFnTable
_080C21E4:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C21F0
	cmp r5, #1
	beq _080C2202
	b _080C2288
_080C21F0:
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C2202:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080C222C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C2232
_080C222C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2232:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C2266
	ldr r0, _080C2290 @ =0x0202F360
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080C2266
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080C226E
_080C2266:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C226E:
	ldr r0, [r3, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080C2282
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C2282:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C2288:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C2290: .4byte 0x0202F360

	thumb_func_start FUN_080c2294
FUN_080c2294: @ 0x080C2294
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080C22AC
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C22C4
_080C22AC:
	ldr r1, _080C22C0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C2358
	.align 2, 0
_080C22C0: .4byte gVFXFnTable
_080C22C4:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C22D0
	cmp r5, #1
	beq _080C22E0
	b _080C2358
_080C22D0:
	ldr r1, _080C230C @ =0x00000B01
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C22E0:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080C2310
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C2316
	.align 2, 0
_080C230C: .4byte 0x00000B01
_080C2310:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2316:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C234A
	ldr r0, _080C2360 @ =0x0202F360
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080C234A
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080C2352
_080C234A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C2352:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C2358:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C2360: .4byte 0x0202F360

	thumb_func_start FUN_080c2364
FUN_080c2364: @ 0x080C2364
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C2386
	ldr r1, _080C238C @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080C2386:
	pop {r0}
	bx r0
	.align 2, 0
_080C238C: .4byte gVFXFnTable

	thumb_func_start FUN_080c2390
FUN_080c2390: @ 0x080C2390
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r7, #0xff
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080C23B0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080C2480
_080C23B0:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C23BC
	cmp r0, #1
	beq _080C244A
	b _080C2480
_080C23BC:
	ldr r6, _080C241C @ =RNG_0202f388
	ldr r0, [r6]
	ldr r1, _080C2420 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _080C2424 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	strb r0, [r4, #0x13]
	ands r0, r7
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x80
	ldrh r1, [r2]
	ldr r0, _080C2428 @ =0x00000C02
	cmp r1, r0
	bne _080C243C
	mov r0, r8
	muls r0, r5, r0
	ldr r1, _080C2424 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C242C
	movs r1, #0xc0
	lsls r1, r1, #4
	b _080C242E
	.align 2, 0
_080C241C: .4byte RNG_0202f388
_080C2420: .4byte 0x000343FD
_080C2424: .4byte 0x00269EC3
_080C2428: .4byte 0x00000C02
_080C242C:
	ldr r1, _080C2438 @ =0x00000C01
_080C242E:
	adds r0, r4, #0
	bl SetMotion
	b _080C2444
	.align 2, 0
_080C2438: .4byte 0x00000C01
_080C243C:
	ldrh r1, [r2]
	adds r0, r4, #0
	bl SetMotion
_080C2444:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C244A:
	ldr r2, [r4, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C246A
	str r1, [r4, #0x60]
_080C246A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C2480:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c248c
FUN_080c248c: @ 0x080C248C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C249C
	cmp r0, #1
	beq _080C24B2
	b _080C24F4
_080C249C:
	adds r0, r4, #0
	adds r0, #0x80
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C24B2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C24CA
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C24D0
_080C24CA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C24D0:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C24F4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C24F4
	ldr r1, _080C24FC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C24F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C24FC: .4byte gVFXFnTable

	thumb_func_start FUN_080c2500
FUN_080c2500: @ 0x080C2500
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080C2516
	cmp r0, #1
	beq _080C258A
	b _080C25D2
_080C2516:
	ldr r4, _080C25E0 @ =0x0836F2F0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	mov r8, r0
	ldrb r2, [r7, #0x11]
	lsls r2, r2, #3
	add r2, r8
	ldr r3, _080C25E4 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C25E8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C25EC @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #3
	add r0, r8
	ldr r2, [r0]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	mov r0, sb
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C258A:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C25A0
	str r1, [r7, #0x60]
_080C25A0:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080C25C0
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C25D2
_080C25C0:
	ldr r1, _080C25F0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080C25D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C25E0: .4byte 0x0836F2F0
_080C25E4: .4byte RNG_0202f388
_080C25E8: .4byte 0x000343FD
_080C25EC: .4byte 0x00269EC3
_080C25F0: .4byte gVFXFnTable

	thumb_func_start FUN_080c25f4
FUN_080c25f4: @ 0x080C25F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080C260A
	cmp r0, #1
	beq _080C267E
	b _080C26C6
_080C260A:
	ldr r4, _080C26D4 @ =0x0836F2F0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	mov r8, r0
	ldrb r2, [r7, #0x11]
	lsls r2, r2, #3
	add r2, r8
	ldr r3, _080C26D8 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C26DC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C26E0 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #3
	add r0, r8
	ldr r2, [r0]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	mov r0, sb
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C267E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C2694
	str r1, [r7, #0x60]
_080C2694:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080C26B4
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C26C6
_080C26B4:
	ldr r1, _080C26E4 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080C26C6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C26D4: .4byte 0x0836F2F0
_080C26D8: .4byte RNG_0202f388
_080C26DC: .4byte 0x000343FD
_080C26E0: .4byte 0x00269EC3
_080C26E4: .4byte gVFXFnTable
