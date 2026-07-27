	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor28_Update
Actor28_Update: @ 0x080D38E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bhi _080D39A6
	lsls r0, r0, #2
	ldr r1, _080D38FC @ =_080D3900
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D38FC: .4byte _080D3900
_080D3900: @ jump table
	.4byte _080D3914 @ case 0
	.4byte _080D392E @ case 1
	.4byte _080D3960 @ case 2
	.4byte _080D3976 @ case 3
	.4byte _080D39A6 @ case 4
_080D3914:
	movs r4, #0
	str r4, [r6, #0x54]
	movs r0, #0x93
	lsls r0, r0, #8
	str r0, [r6, #0x58]
	movs r0, #0x97
	lsls r0, r0, #1
	bl PlaySound
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D392E:
	ldr r2, _080D395C @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	adds r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xf
	bls _080D39A6
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x20
	strb r0, [r6, #0x13]
	b _080D39A6
	.align 2, 0
_080D395C: .4byte gSineTable
_080D3960:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D39A6
	movs r0, #0x20
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3976:
	ldr r2, _080D39E8 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	subs r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080D39A6
	ldr r2, _080D39EC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080D39F0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D39A6:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r5, _080D39EC @ =gWindowRegBuffer
	ldr r2, [r6, #0x54]
	asrs r2, r2, #8
	movs r3, #1
	ands r3, r0
	lsls r0, r3, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xbc
	movs r4, #0xff
	ands r1, r4
	movs r0, #0xbc
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	lsls r3, r3, #2
	adds r0, r0, r3
	ands r0, r4
	strh r0, [r5, #0xa]
	ldr r1, _080D39F4 @ =gPaletteManager
	ldr r2, _080D39F8 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D39E8: .4byte gSineTable
_080D39EC: .4byte gWindowRegBuffer
_080D39F0: .4byte 0x0000BFFF
_080D39F4: .4byte gPaletteManager
_080D39F8: .4byte 0x00007FFF

	thumb_func_start Actor29_Update
Actor29_Update: @ 0x080D39FC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D3A7E
	cmp r7, #1
	bgt _080D3A12
	cmp r7, #0
	beq _080D3A1A
	b _080D3B2E
_080D3A12:
	cmp r7, #2
	bne _080D3A18
	b _080D3B24
_080D3A18:
	b _080D3B2E
_080D3A1A:
	ldr r0, [r6, #0x54]
	ldr r1, _080D3AF8 @ =0xFFFF1000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [r6, #0x58]
	ldr r0, _080D3AFC @ =wStaticGraphicTilenums
	movs r5, #0
	ldr r1, _080D3B00 @ =0x000003CE
	strh r1, [r0, #2]
	ldr r4, _080D3B04 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r4, #2]
	ldr r0, _080D3B08 @ =0x085D790C
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3B0C @ =0x085D7918
	ldrh r1, [r4, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #8
	bl AppendQuake
	strb r5, [r6, #0x12]
	str r7, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3A7E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, [r6, #0x60]
	adds r1, #0x10
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r4, r6, #0
	adds r4, #0x54
	movs r0, #2
	adds r1, r4, #0
	bl AppendQuake
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080D3AD6
	ldr r0, [r6, #0x54]
	ldr r1, _080D3B10 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, _080D3B14 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D3B18 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D3B1C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D3AD6:
	ldr r0, _080D3B20 @ =gStageRun+232
	adds r1, r4, #0
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bls _080D3B2E
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D3B2E
	.align 2, 0
_080D3AF8: .4byte 0xFFFF1000
_080D3AFC: .4byte wStaticGraphicTilenums
_080D3B00: .4byte 0x000003CE
_080D3B04: .4byte wStaticMotionPalIDs
_080D3B08: .4byte gStaticMotionGraphics+(20*1)
_080D3B0C: .4byte gStaticMotionGraphics+(20*1)+12
_080D3B10: .4byte 0xFFFFC000
_080D3B14: .4byte RNG_0202f388
_080D3B18: .4byte 0x000343FD
_080D3B1C: .4byte 0x00269EC3
_080D3B20: .4byte gStageRun+232
_080D3B24:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3B2E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor30_Update
Actor30_Update: @ 0x080D3B38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D3C16
	cmp r0, #1
	bgt _080D3B56
	cmp r0, #0
	beq _080D3B64
	b _080D3D10
_080D3B56:
	cmp r0, #2
	bne _080D3B5C
	b _080D3C8C
_080D3B5C:
	cmp r0, #3
	bne _080D3B62
	b _080D3D08
_080D3B62:
	b _080D3D10
_080D3B64:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CD4 @ =0xFFFF6000
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r2, _080D3CD8 @ =0x00000101
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r1, _080D3CDC @ =wStaticGraphicTilenums
	ldr r0, _080D3CE0 @ =0x000003CE
	strh r0, [r1, #2]
	ldr r6, _080D3CE4 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r6, #2]
	movs r4, #0xb9
	lsls r0, r4, #1
	mov r8, r0
	adds r2, r1, #0
	add r2, r8
	mov sl, r2
	ldr r0, _080D3CE8 @ =0x000003AF
	strh r0, [r2]
	add r8, r6
	movs r0, #0xa
	mov r2, r8
	strh r0, [r2]
	ldr r5, _080D3CEC @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0x14
	ldrh r1, [r1, #2]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3CF0 @ =gStaticMotionGraphics+12
	mov sb, r0
	adds r0, #0x14
	ldrh r1, [r6, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	bl LoadPalette
	lsls r4, r4, #4
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r5, r4, r5
	mov r2, sl
	ldrh r1, [r2]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, sb
	mov r2, r8
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C16:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0x10
	bl AppendQuake
	ldr r5, _080D3CF4 @ =RNG_0202f388
	mov r6, sp
	movs r4, #3
_080D3C38:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CF8 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5]
	ldr r0, _080D3CFC @ =0x000343FD
	muls r1, r0, r1
	ldr r2, _080D3D00 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsls r1, r1, #3
	lsrs r1, r1, #0x14
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r6, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	subs r4, #1
	cmp r4, #0
	bge _080D3C38
	ldr r0, _080D3D04 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x64]
	adds r0, r7, #0
	bl InitRotatableMotion
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x68]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C8C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r1, [r7, #0x60]
	adds r1, #1
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	asrs r0, r0, #0xb
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, [r7, #0x60]
	asrs r2, r1, #2
	ldr r0, [r7, #0x58]
	subs r0, r0, r2
	str r0, [r7, #0x58]
	asrs r1, r1, #1
	ldr r0, [r7, #0x64]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, _080D3D04 @ =pZero2
	ldr r1, [r1]
	str r0, [r1, #0x58]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D3D10
	.align 2, 0
_080D3CD4: .4byte 0xFFFF6000
_080D3CD8: .4byte 0x00000101
_080D3CDC: .4byte wStaticGraphicTilenums
_080D3CE0: .4byte 0x000003CE
_080D3CE4: .4byte wStaticMotionPalIDs
_080D3CE8: .4byte 0x000003AF
_080D3CEC: .4byte gStaticMotionGraphics
_080D3CF0: .4byte gStaticMotionGraphics+12
_080D3CF4: .4byte RNG_0202f388
_080D3CF8: .4byte 0xFFFFC000
_080D3CFC: .4byte 0x000343FD
_080D3D00: .4byte 0x00269EC3
_080D3D04: .4byte pZero2
_080D3D08:
	ldr r0, _080D3D4C @ =pZero2
	ldr r1, [r0]
	ldr r0, [r7, #0x64]
	str r0, [r1, #0x58]
_080D3D10:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bhi _080D3D3A
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3D30
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080c5628
_080D3D30:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3D3A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3D4C: .4byte pZero2

	thumb_func_start Actor31_Update
Actor31_Update: @ 0x080D3D50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #1
	beq _080D3D98
	cmp r5, #1
	bgt _080D3DD8
	cmp r5, #0
	bne _080D3DD8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r4, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x74
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3D98:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r3, [r4, #0x28]
	ldr r2, _080D3DE0 @ =gSineTable
	movs r1, #0xfe
	ands r0, r1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	str r0, [r3, #0x78]
	ldr r2, [r4, #0x28]
	ldrb r0, [r4, #0x12]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0xc
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x81
	bne _080D3DD8
	ldr r0, [r4, #0x28]
	adds r0, #0x77
	strb r3, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3DD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3DE0: .4byte gSineTable
