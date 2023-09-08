	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013898
FUN_08013898: @ 0x08013898
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _080138D4 @ =gOverworld
	ldr r1, _080138D8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, [r5, #0x38]
	subs r0, r0, r1
	adds r4, r0, #5
	cmp r4, #0xff
	ble _080138B8
	movs r4, #0xff
_080138B8:
	movs r0, #0xff
	rsbs r0, r0, #0
	cmp r4, r0
	bge _080138C2
	adds r4, r0, #0
_080138C2:
	cmp r4, #0
	bge _080138E0
	ldr r0, _080138DC @ =gWindowRegBuffer
	rsbs r1, r4, #0
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0, #0xa]
	b _080138E6
	.align 2, 0
_080138D4: .4byte gOverworld
_080138D8: .4byte 0x0002C00C
_080138DC: .4byte gWindowRegBuffer
_080138E0:
	ldr r1, _08013900 @ =gWindowRegBuffer
	movs r0, #0
	strh r0, [r1, #0xa]
_080138E6:
	lsrs r2, r3, #4
	lsls r2, r2, #2
	ldr r0, _08013904 @ =gVideoRegBuffer+12
	adds r3, r2, r0
	ldr r1, [r5, #0x34]
	strh r1, [r3]
	adds r0, #2
	adds r2, r2, r0
	strh r4, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013900: .4byte gWindowRegBuffer
_08013904: .4byte gVideoRegBuffer+12

	thumb_func_start FUN_08013908
FUN_08013908: @ 0x08013908
	ldr r1, _08013924 @ =gBlendRegBuffer
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08013928 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _0801392C @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
_08013924: .4byte gBlendRegBuffer
_08013928: .4byte gWindowRegBuffer
_0801392C: .4byte 0x0000BFFF

	thumb_func_start sunkenlib_08013930
sunkenlib_08013930: @ 0x08013930
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	bne _080139A0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _08013A20 @ =gVideoRegBuffer+4
	adds r5, r5, r3
	ldr r1, [r7, #0x64]
	ldr r4, _08013A24 @ =0x00008045
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r6, [r0]
	ldr r0, _08013A28 @ =0x085223B4
	ldr r0, [r0]
	ldr r2, _08013A2C @ =0x085223BC
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	bl CpuFastSet
	ldr r0, _08013A30 @ =0x085223B8
	ldr r0, [r0]
	ldr r1, _08013A34 @ =0x085223C0
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08013A38 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	mov r2, r8
	bl CpuFastSet
	str r6, [r7, #0x68]
	strh r6, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080139A0:
	ldr r2, _08013A3C @ =gWindowRegBuffer
	ldrb r1, [r2, #0xd]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2, #0xd]
	ldr r0, [r7, #0x68]
	cmp r0, #0
	bne _080139B6
	bl FUN_080d8f2c
	str r0, [r7, #0x68]
_080139B6:
	ldr r5, _08013A40 @ =gOverworld
	ldr r4, _08013A44 @ =0x0002C00C
	adds r0, r5, r4
	ldr r1, [r0]
	ldr r0, _08013A48 @ =0x000227FF
	cmp r1, r0
	bgt _08013A60
	ldrh r0, [r7, #0x10]
	adds r0, #1
	strh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080139D6
	movs r0, #4
	strh r0, [r7, #0x10]
_080139D6:
	ldr r0, [r7, #0x68]
	bl FUN_080d8fd4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _080139F0
	adds r0, r4, #0
	bl PlaySound
_080139F0:
	ldrh r1, [r7, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08013A7E
	ldr r0, _08013A4C @ =0x0002D02C
	adds r2, r5, r0
	ldr r1, [r2]
	ldr r0, _08013A50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013A54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08013A7E
	ldr r1, _08013A58 @ =gBlendRegBuffer
	ldr r0, _08013A5C @ =0x00000C0A
	b _08013A82
	.align 2, 0
_08013A20: .4byte gVideoRegBuffer+4
_08013A24: .4byte 0x00008045
_08013A28: .4byte 0x085223B4
_08013A2C: .4byte 0x085223BC
_08013A30: .4byte 0x085223B8
_08013A34: .4byte 0x085223C0
_08013A38: .4byte 0x06000800
_08013A3C: .4byte gWindowRegBuffer
_08013A40: .4byte gOverworld
_08013A44: .4byte 0x0002C00C
_08013A48: .4byte 0x000227FF
_08013A4C: .4byte 0x0002D02C
_08013A50: .4byte 0x000343FD
_08013A54: .4byte 0x00269EC3
_08013A58: .4byte gBlendRegBuffer
_08013A5C: .4byte 0x00000C0A
_08013A60:
	movs r0, #3
	strh r0, [r7, #0x10]
	ldr r0, [r7, #0x68]
	bl FUN_080d8fe4
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013A7E
	adds r0, r4, #0
	bl stopSound
_08013A7E:
	ldr r1, _08013A90 @ =gBlendRegBuffer
	ldr r0, _08013A94 @ =0x00000C04
_08013A82:
	strh r0, [r1, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013A90: .4byte gBlendRegBuffer
_08013A94: .4byte 0x00000C04

	thumb_func_start FUN_08013a98
FUN_08013a98: @ 0x08013A98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r2, [r5, #0x5c]
	lsls r2, r2, #0x10
	ldr r0, _08013AFC @ =gOverworld
	ldr r1, _08013B00 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	ldr r3, [r5, #0x38]
	subs r3, r3, r0
	adds r3, #5
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r0, _08013B04 @ =gVideoRegBuffer+12
	adds r4, r2, r0
	ldr r1, [r5, #0x34]
	strh r1, [r4]
	adds r0, #2
	adds r2, r2, r0
	strh r3, [r2]
	ldr r6, _08013B08 @ =gStageTilesetOffsets+(18*4)
	ldrh r0, [r5, #0x10]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08013B0C @ =0x08704B10
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r5, #0x10]
	lsrs r0, r0, #2
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013AFC: .4byte gOverworld
_08013B00: .4byte 0x0002C00C
_08013B04: .4byte gVideoRegBuffer+12
_08013B08: .4byte gStageTilesetOffsets+(18*4)
_08013B0C: .4byte 0x08704B10

	thumb_func_start FUN_08013b10
FUN_08013b10: @ 0x08013B10
	push {r4, lr}
	ldr r3, [r0, #0x68]
	cmp r3, #0
	beq _08013B4E
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08013B68 @ =gSolidFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08013B4E:
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013B62
	adds r0, r4, #0
	bl stopSound
_08013B62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013B68: .4byte gSolidFnTable

	thumb_func_start sunkenlib_08013b6c
sunkenlib_08013b6c: @ 0x08013B6C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08013BBA
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _08013BCC @ =gVideoRegBuffer+4
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _08013BD0 @ =0x085223BC
	ldr r0, [r0]
	ldr r2, _08013BD4 @ =0x085223C4
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08013BBA:
	ldr r2, _08013BD8 @ =gWindowRegBuffer
	ldrb r1, [r2, #0xd]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #0xd]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013BCC: .4byte gVideoRegBuffer+4
_08013BD0: .4byte 0x085223BC
_08013BD4: .4byte 0x085223C4
_08013BD8: .4byte gWindowRegBuffer

	thumb_func_start FUN_08013bdc
FUN_08013bdc: @ 0x08013BDC
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r4, _08013C08 @ =gVideoRegBuffer+12
	adds r5, r2, r4
	ldr r3, [r0, #0x34]
	lsls r1, r3, #1
	adds r1, r1, r3
	asrs r1, r1, #2
	strh r1, [r5]
	adds r4, #2
	adds r2, r2, r4
	ldr r1, [r0, #0x38]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013C08: .4byte gVideoRegBuffer+12

	thumb_func_start sunkenLib_08013c0c
sunkenLib_08013c0c: @ 0x08013C0C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	ldr r2, _08013CA4 @ =gOverworld
	cmp r0, #0
	bne _08013C30
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xc
_08013C1E:
	str r1, [r0, #0x68]
	subs r0, #4
	cmp r0, r5
	bge _08013C1E
	movs r0, #0
	strh r0, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08013C30:
	ldr r1, _08013CA8 @ =0x0002D024
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08013CC0
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x68
_08013C46:
	ldr r0, [r4]
	cmp r0, #0
	bne _08013C56
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl FUN_080d8f7c
	str r0, [r4]
_08013C56:
	adds r4, #4
	adds r6, #1
	cmp r6, #3
	ble _08013C46
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _08013C72
	adds r0, r4, #0
	bl PlaySound
_08013C72:
	ldrh r1, [r5, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08013D20
	ldr r2, _08013CA4 @ =gOverworld
	ldr r0, _08013CAC @ =0x0002D02C
	adds r2, r2, r0
	ldr r1, [r2]
	ldr r0, _08013CB0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08013CB4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08013D20
	ldr r1, _08013CB8 @ =gBlendRegBuffer
	ldr r0, _08013CBC @ =0x00000C0A
	b _08013D24
	.align 2, 0
_08013CA4: .4byte gOverworld
_08013CA8: .4byte 0x0002D024
_08013CAC: .4byte 0x0002D02C
_08013CB0: .4byte 0x000343FD
_08013CB4: .4byte 0x00269EC3
_08013CB8: .4byte gBlendRegBuffer
_08013CBC: .4byte 0x00000C0A
_08013CC0:
	movs r4, #0
	ldr r7, _08013D2C @ =gSolidFnTable
	adds r3, r5, #0
	adds r3, #0x68
	movs r6, #3
_08013CCA:
	ldr r2, [r3]
	cmp r2, #0
	beq _08013D04
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r4, [r3]
_08013D04:
	adds r3, #4
	subs r6, #1
	cmp r6, #0
	bge _08013CCA
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013D20
	adds r0, r4, #0
	bl stopSound
_08013D20:
	ldr r1, _08013D30 @ =gBlendRegBuffer
	ldr r0, _08013D34 @ =0x00000C04
_08013D24:
	strh r0, [r1, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013D2C: .4byte gSolidFnTable
_08013D30: .4byte gBlendRegBuffer
_08013D34: .4byte 0x00000C04

	thumb_func_start FUN_08013d38
FUN_08013d38: @ 0x08013D38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08013D6C @ =gOverworld
	ldr r1, _08013D70 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08013D80
	ldr r4, _08013D74 @ =gStageTilesetOffsets+(18*4)
	ldr r0, [r4]
	ldr r1, _08013D78 @ =0x08704B74
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldr r0, [r4]
	ldr r1, _08013D7C @ =0x08704B80
	adds r0, r0, r1
	movs r1, #0
	bl LoadPalette
	b _08013DBA
	.align 2, 0
_08013D6C: .4byte gOverworld
_08013D70: .4byte 0x0002D024
_08013D74: .4byte gStageTilesetOffsets+(18*4)
_08013D78: .4byte 0x08704B74
_08013D7C: .4byte 0x08704B80
_08013D80:
	ldr r6, _08013DCC @ =gStageTilesetOffsets+(18*4)
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	movs r5, #3
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08013DD0 @ =0x08704B88
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08013DBA:
	adds r0, r7, #0
	mov r1, r8
	bl DrawGeneralStageLayer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013DCC: .4byte gStageTilesetOffsets+(18*4)
_08013DD0: .4byte 0x08704B88

	thumb_func_start FUN_08013dd4
FUN_08013dd4: @ 0x08013DD4
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _08013E38 @ =gSolidFnTable
	adds r3, r0, #0
	movs r4, #3
_08013DDE:
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _08013E16
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08013E16:
	adds r3, #4
	subs r4, #1
	cmp r4, #0
	bge _08013DDE
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08013E32
	adds r0, r4, #0
	bl stopSound
_08013E32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013E38: .4byte gSolidFnTable
