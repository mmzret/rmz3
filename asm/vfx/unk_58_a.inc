	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	ldr r0, _080C1F34 @ =gStaticMotionGraphics+(12*20)
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
	bl AllocEntityLast
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
	ldr r0, _080C1F58 @ =s32_ARRAY_080ff13c
	b _080C1F5E
	.align 2, 0
_080C1F34: .4byte gStaticMotionGraphics+(12*20)
_080C1F38: .4byte wStaticGraphicTilenums
_080C1F3C: .4byte gStaticMotionGraphics+(12*20)+12
_080C1F40: .4byte wStaticMotionPalIDs
_080C1F44: .4byte gVFXFnTable
_080C1F48: .4byte RNG_0202f388
_080C1F4C: .4byte 0x000343FD
_080C1F50: .4byte 0x00269EC3
_080C1F54: .4byte gVFXHeaderPtr
_080C1F58: .4byte s32_ARRAY_080ff13c
_080C1F5C:
	ldr r0, _080C1F90 @ =s32_ARRAY_080ff124
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
	ldr r1, _080C1F9C @ =u16_ARRAY_080ff10c
	b _080C1FA2
	.align 2, 0
_080C1F90: .4byte s32_ARRAY_080ff124
_080C1F94: .4byte 0x000343FD
_080C1F98: .4byte 0x00269EC3
_080C1F9C: .4byte u16_ARRAY_080ff10c
_080C1FA0:
	ldr r1, _080C1FD0 @ =u16_ARRAY_080ff118
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
_080C1FD0: .4byte u16_ARRAY_080ff118
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

