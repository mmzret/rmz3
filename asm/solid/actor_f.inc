	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d5c5c
FUN_080d5c5c: @ 0x080D5C5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _080D5D18
	lsls r0, r0, #2
	ldr r1, _080D5C70 @ =_080D5C74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5C70: .4byte _080D5C74
_080D5C74: @ jump table
	.4byte _080D5C88 @ case 0
	.4byte _080D5CB8 @ case 1
	.4byte _080D5CE0 @ case 2
	.4byte _080D5CF8 @ case 3
	.4byte _080D5D12 @ case 4
_080D5C88:
	ldr r0, _080D5CD4 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5CD8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #5
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5CB8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D5D18
	ldr r1, _080D5CDC @ =0x0000BE20
	adds r0, r4, #0
	bl SetMotion
	b _080D5CF0
	.align 2, 0
_080D5CD4: .4byte wDynamicGraphicTilenums
_080D5CD8: .4byte wDynamicMotionPalIDs
_080D5CDC: .4byte 0x0000BE20
_080D5CE0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5D18
_080D5CF0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5D18
_080D5CF8:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D12:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D5D18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d5d20
FUN_080d5d20: @ 0x080D5D20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5D56
	cmp r0, #1
	bgt _080D5D34
	cmp r0, #0
	beq _080D5D3A
	b _080D5DFA
_080D5D34:
	cmp r0, #2
	beq _080D5D7C
	b _080D5DFA
_080D5D3A:
	ldr r0, _080D5D70 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5D74 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D56:
	ldr r1, _080D5D78 @ =0x0000C501
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D5DFA
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5DFA
	.align 2, 0
_080D5D70: .4byte wDynamicGraphicTilenums
_080D5D74: .4byte wDynamicMotionPalIDs
_080D5D78: .4byte 0x0000C501
_080D5D7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5DB4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5DA8 @ =0x0000C502
	cmp r0, r1
	bne _080D5DAC
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5DB4
	.align 2, 0
_080D5DA8: .4byte 0x0000C502
_080D5DAC:
	ldr r1, _080D5E00 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5DB4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5DE4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E00 @ =0x0000C501
	cmp r0, r1
	bne _080D5DD8
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DD8:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5DFA
_080D5DE4:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E04 @ =0x0000C503
	cmp r0, r1
	bne _080D5DFA
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E00: .4byte 0x0000C501
_080D5E04: .4byte 0x0000C503

	thumb_func_start FUN_080d5e08
FUN_080d5e08: @ 0x080D5E08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D5E14
	b _080D5FC0
_080D5E14:
	lsls r0, r0, #2
	ldr r1, _080D5E20 @ =_080D5E24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5E20: .4byte _080D5E24
_080D5E24: @ jump table
	.4byte _080D5E4C @ case 0
	.4byte _080D5E7A @ case 1
	.4byte _080D5E8E @ case 2
	.4byte _080D5ED4 @ case 3
	.4byte _080D5F18 @ case 4
	.4byte _080D5F34 @ case 5
	.4byte _080D5F56 @ case 6
	.4byte _080D5F78 @ case 7
	.4byte _080D5FA0 @ case 8
	.4byte _080D5FB8 @ case 9
_080D5E4C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D5ED0 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E7A:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D5E88
	b _080D5FC0
_080D5E88:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E8E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D5EA2
	b _080D5FC0
_080D5EA2:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _080D5FB0
	.align 2, 0
_080D5ED0: .4byte 0x00003503
_080D5ED4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D5EE8
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D5EE8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D5F08
	movs r0, #1
	strb r0, [r1, #0x11]
_080D5F08:
	ldr r1, _080D5F14 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F14: .4byte 0x00000301
_080D5F18:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D5FC0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F34:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D5FC0
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x2a
	strb r0, [r4, #0x12]
	b _080D5FB0
_080D5F56:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D5FC0
	movs r1, #0xd0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F78:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	movs r0, #0x9a
	bl PlaySound
	ldr r1, _080D5F9C @ =0x00003401
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F9C: .4byte 0x00003401
_080D5FA0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5FC0
_080D5FB0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5FC0
_080D5FB8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080D5FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start omega1_080d5fc8
omega1_080d5fc8: @ 0x080D5FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0xa
	bls _080D5FDC
	b _080D6446
_080D5FDC:
	lsls r0, r0, #2
	ldr r1, _080D5FE8 @ =_080D5FEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5FE8: .4byte _080D5FEC
_080D5FEC: @ jump table
	.4byte _080D6018 @ case 0
	.4byte _080D60DC @ case 1
	.4byte _080D6114 @ case 2
	.4byte _080D6130 @ case 3
	.4byte _080D6186 @ case 4
	.4byte _080D62A4 @ case 5
	.4byte _080D62E8 @ case 6
	.4byte _080D6302 @ case 7
	.4byte _080D6338 @ case 8
	.4byte _080D6370 @ case 9
	.4byte _080D63A8 @ case 10
_080D6018:
	movs r1, #0x85
	lsls r1, r1, #2
	ldr r0, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r0, #0x16]
	ldr r2, _080D60FC @ =wStaticMotionPalIDs
	mov sl, r2
	movs r0, #5
	strh r0, [r2, #0x16]
	ldr r5, _080D6100 @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	mov sb, r2
	add r1, sb
	bl LoadGraphic
	ldr r4, _080D6104 @ =gStaticMotionGraphics+12
	adds r0, r4, #0
	adds r0, #0xdc
	mov r2, sl
	ldrh r1, [r2, #0x16]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	bl LoadPalette
	movs r0, #0xa
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r2, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r2, #0x14]
	mov r2, sl
	strh r0, [r2, #0x14]
	adds r5, #0xc8
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r5, #0
	bl LoadGraphic
	adds r4, #0xc8
	mov r0, sl
	ldrh r1, [r0, #0x14]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D6108 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, [r7, #0x54]
	str r1, [r7, #0x64]
	str r0, [r7, #0x68]
	adds r0, r7, #0
	movs r1, #0x35
	bl CreateScriptActor
	adds r0, r7, #0
	movs r1, #0x36
	bl CreateScriptActor
	adds r0, r7, #0
	bl FUN_0800f894
	ldr r0, _080D610C @ =gOverworld
	ldr r2, _080D6110 @ =0x0002D026
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	strb r0, [r7, #0x12]
	strb r0, [r7, #0x11]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D60DC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D60F2
	b _080D6446
_080D60F2:
	strb r2, [r7, #0xe]
	b _080D6398
	.align 2, 0
_080D60F8: .4byte wStaticGraphicTilenums
_080D60FC: .4byte wStaticMotionPalIDs
_080D6100: .4byte gStaticMotionGraphics
_080D6104: .4byte gStaticMotionGraphics+12
_080D6108: .4byte 0xFFFFFE80
_080D610C: .4byte gOverworld
_080D6110: .4byte 0x0002D026
_080D6114:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D612A
	b _080D6446
_080D612A:
	strb r2, [r7, #0xe]
	movs r0, #6
	b _080D6396
_080D6130:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D6146
	b _080D6446
_080D6146:
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #8
	adds r1, r4, #0
	bl AppendQuake
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r7, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r7, #0x12]
	strb r5, [r7, #0x13]
	b _080D6398
_080D6186:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _080D619E
	movs r0, #0x7e
	strb r0, [r7, #0x13]
_080D619E:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D61F8
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bls _080D61CC
	ldr r0, _080D61D8 @ =0x00000135
	bl PlaySound
	movs r0, #0x8a
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl StartPaletteAnimation
	movs r0, #0x8b
	lsls r0, r0, #1
	movs r1, #0xe0
	bl StartPaletteAnimation
_080D61CC:
	ldrb r0, [r7, #0x12]
	cmp r0, #8
	bls _080D61DC
	subs r0, #8
	b _080D6200
	.align 2, 0
_080D61D8: .4byte 0x00000135
_080D61DC:
	ldr r1, [r7, #0x28]
	cmp r1, #0
	beq _080D61E8
	adds r1, #0x77
	movs r0, #1
	strb r0, [r1]
_080D61E8:
	movs r0, #0
	str r0, [r7, #0x28]
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6202
_080D61F8:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bhi _080D6202
	adds r0, #0x10
_080D6200:
	strb r0, [r7, #0x12]
_080D6202:
	ldr r3, [r7, #0x28]
	cmp r3, #0
	beq _080D627A
	ldrb r1, [r7, #0x13]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6254
	cmp r1, #3
	bls _080D6232
	ldr r2, _080D6244 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D6248 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D624C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	cmp r0, #0
	bne _080D6254
_080D6232:
	ldr r0, _080D6250 @ =gSineTable
	ldrb r1, [r7, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	str r0, [r3, #0x78]
	b _080D627A
	.align 2, 0
_080D6244: .4byte RNG_0202f388
_080D6248: .4byte 0x000343FD
_080D624C: .4byte 0x00269EC3
_080D6250: .4byte gSineTable
_080D6254:
	ldr r1, _080D62A0 @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r3, #0x78]
	ldr r2, [r7, #0x28]
	ldrb r0, [r7, #0x13]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
_080D627A:
	movs r0, #0x8a
	lsls r0, r0, #1
	bl StepPaletteAnimation
	movs r0, #0x8b
	lsls r0, r0, #1
	bl StepPaletteAnimation
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080D6298
	b _080D6446
_080D6298:
	ldr r0, [r7, #0x64]
	subs r0, #8
	b _080D6444
	.align 2, 0
_080D62A0: .4byte gSineTable
_080D62A4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62B4
	subs r0, #1
	strb r0, [r7, #0x13]
_080D62B4:
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r0, r5, #0
	bl StepPaletteAnimation
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r0, r4, #0
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _080D62D2
	b _080D6446
_080D62D2:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62DA
	b _080D6446
_080D62DA:
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	b _080D6398
_080D62E8:
	movs r0, #0x88
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl StartPaletteAnimation
	ldr r0, _080D6334 @ =0x00000117
	movs r1, #0xe0
	bl StartPaletteAnimation
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6302:
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r5, #0
	bl StepPaletteAnimation
	ldr r4, _080D6334 @ =0x00000117
	adds r0, r4, #0
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D6324
	b _080D6446
_080D6324:
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	b _080D6398
	.align 2, 0
_080D6334: .4byte 0x00000117
_080D6338:
	ldr r5, _080D63A0 @ =0x0000010F
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl StartPaletteAnimation
	ldr r4, _080D63A4 @ =0x00000115
	adds r0, r4, #0
	movs r1, #0xe0
	bl StartPaletteAnimation
	adds r0, r5, #0
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	movs r0, #0x3c
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6370:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _080D63B4
	movs r0, #3
	strb r0, [r7, #0xe]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6446
	movs r0, #4
	strb r0, [r7, #0xe]
	str r2, [r7, #0x5c]
	movs r0, #0x1e
_080D6396:
	strb r0, [r7, #0x13]
_080D6398:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6446
	.align 2, 0
_080D63A0: .4byte 0x0000010F
_080D63A4: .4byte 0x00000115
_080D63A8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D63BA
_080D63B4:
	subs r0, #1
	strb r0, [r7, #0x13]
	b _080D6446
_080D63BA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080D63DA
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x1e
	bl CreateOmegaWhiteHoop
_080D63DA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D63FA
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x28
	bl CreateOmegaWhiteHoop
_080D63FA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080D641A
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x32
	bl CreateOmegaWhiteHoop
_080D641A:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6434
	ldr r0, [r7, #0x5c]
	cmp r0, #0x5f
	bgt _080D643E
	adds r0, #8
	b _080D643C
	.align 2, 0
_080D6430: .4byte 0xFFFF9C00
_080D6434:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	beq _080D643E
	subs r0, #4
_080D643C:
	str r0, [r7, #0x5c]
_080D643E:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
_080D6444:
	str r0, [r7, #0x64]
_080D6446:
	ldrb r0, [r7, #0x11]
	adds r0, #1
	strb r0, [r7, #0x11]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D645A
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080D6460
_080D645A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D6460:
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080D6490
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x64]
	str r0, [r7, #0x54]
	ldr r1, _080D648C @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _080D64E0
	.align 2, 0
_080D648C: .4byte gSineTable
_080D6490:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	ldr r0, _080D64F0 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r5, _080D64F4 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080D64F8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080D64FC @ =0x000001FF
	ands r0, r4
	ldr r1, [r7, #0x64]
	adds r6, r1, r0
	str r6, [r7, #0x54]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x28]
	cmp r2, #0
	beq _080D64E0
	str r6, [r2, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080D6500 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [r2, #0x58]
_080D64E0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D64F0: .4byte RNG_0202f388
_080D64F4: .4byte 0x000343FD
_080D64F8: .4byte 0x00269EC3
_080D64FC: .4byte 0x000001FF
_080D6500: .4byte 0xFFFFC000

	thumb_func_start FUN_080d6504
FUN_080d6504: @ 0x080D6504
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	ldrb r0, [r6, #0xd]
	cmp r0, #0xa
	bls _080D6512
	b _080D6808
_080D6512:
	lsls r0, r0, #2
	ldr r1, _080D651C @ =_080D6520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D651C: .4byte _080D6520
_080D6520: @ jump table
	.4byte _080D654C @ case 0
	.4byte _080D65A2 @ case 1
	.4byte _080D6600 @ case 2
	.4byte _080D664A @ case 3
	.4byte _080D66B4 @ case 4
	.4byte _080D66DA @ case 5
	.4byte _080D6600 @ case 6
	.4byte _080D664A @ case 7
	.4byte _080D6730 @ case 8
	.4byte _080D677A @ case 9
	.4byte _080D67CC @ case 10
_080D654C:
	ldr r1, _080D65E0 @ =wStaticGraphicTilenums
	movs r5, #0
	ldr r0, _080D65E4 @ =0x0000023A
	strh r0, [r1, #0x12]
	ldr r4, _080D65E8 @ =wStaticMotionPalIDs
	movs r0, #5
	strh r0, [r4, #0x12]
	ldr r0, _080D65EC @ =gStaticMotionGraphics+(20*9)
	ldrh r1, [r1, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D65F0 @ =gStaticMotionGraphics+((20*9)+12)
	ldrh r1, [r4, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D65F4 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x1c
	strb r0, [r1]
	strb r5, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D65A2:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080D65F8 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080D65FC @ =0xFFFFC800
	adds r1, r1, r0
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	bne _080D65D6
	b _080D67BC
_080D65D6:
	cmp r0, #4
	beq _080D65DC
	b _080D6808
_080D65DC:
	b _080D67BC
	.align 2, 0
_080D65E0: .4byte wStaticGraphicTilenums
_080D65E4: .4byte 0x0000023A
_080D65E8: .4byte wStaticMotionPalIDs
_080D65EC: .4byte gStaticMotionGraphics+(20*9)
_080D65F0: .4byte gStaticMotionGraphics+((20*9)+12)
_080D65F4: .4byte 0x00000901
_080D65F8: .4byte gSineTable
_080D65FC: .4byte 0xFFFFC800
_080D6600:
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bne _080D660C
	movs r0, #0x52
	bl PlaySound
_080D660C:
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _080D6698 @ =0x00000902
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x28
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #6
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D664A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r5, [r7, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D669C @ =0xFFFFB800
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bne _080D66A4
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _080D6670
	b _080D6808
_080D6670:
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6686
	b _080D6808
_080D6686:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D66A0 @ =0xFFFFB600
	adds r0, r4, r2
	str r0, [r6, #0x58]
	b _080D6808
	.align 2, 0
_080D6698: .4byte 0x00000902
_080D669C: .4byte 0xFFFFB800
_080D66A0: .4byte 0xFFFFB600
_080D66A4:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D66B2
	b _080D6808
_080D66B2:
	b _080D67BC
_080D66B4:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _080D6720 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x58
	strb r0, [r1]
	movs r0, #0xc
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D66DA:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r5, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D6724 @ =0xFFFFA800
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080D6718
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6718
	ldr r1, _080D6728 @ =0xFFFFFF00
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D672C @ =0xFFFFA600
	adds r0, r4, r2
	str r0, [r6, #0x58]
_080D6718:
	ldrb r0, [r7, #0xe]
	cmp r0, #2
	bne _080D6808
	b _080D67BC
	.align 2, 0
_080D6720: .4byte 0x00000901
_080D6724: .4byte 0xFFFFA800
_080D6728: .4byte 0xFFFFFF00
_080D672C: .4byte 0xFFFFA600
_080D6730:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	movs r2, #0x10
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	strb r3, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D677A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r5, [r7, #0x54]
	movs r1, #0xa4
	lsls r1, r1, #6
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D67C4 @ =0xFFFFC400
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D67B6
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D67C8 @ =0xFFFFC300
	adds r0, r4, r2
	str r0, [r6, #0x58]
_080D67B6:
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	bne _080D6808
_080D67BC:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D6808
	.align 2, 0
_080D67C4: .4byte 0xFFFFC400
_080D67C8: .4byte 0xFFFFC300
_080D67CC:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D6810 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r4, #1
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl UpdateEntityAnim
	strb r4, [r6, #0xd]
_080D6808:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D6810: .4byte 0x00000901

	thumb_func_start FUN_080d6814
FUN_080d6814: @ 0x080D6814
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bls _080D6822
	b _080D6AF6
_080D6822:
	lsls r0, r0, #2
	ldr r1, _080D682C @ =_080D6830
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D682C: .4byte _080D6830
_080D6830: @ jump table
	.4byte _080D685C @ case 0
	.4byte _080D688E @ case 1
	.4byte _080D68DC @ case 2
	.4byte _080D691C @ case 3
	.4byte _080D6988 @ case 4
	.4byte _080D69E4 @ case 5
	.4byte _080D68DC @ case 6
	.4byte _080D691C @ case 7
	.4byte _080D6A40 @ case 8
	.4byte _080D6A88 @ case 9
	.4byte _080D6ADC @ case 10
_080D685C:
	ldr r1, _080D68C4 @ =wStaticGraphicTilenums
	movs r4, #0
	ldr r0, _080D68C8 @ =0x0000023A
	strh r0, [r1, #0x12]
	ldr r1, _080D68CC @ =wStaticMotionPalIDs
	movs r0, #5
	strh r0, [r1, #0x12]
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D688E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r1, _080D68D0 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080D68D4 @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080D68D8 @ =0xFFFFC600
	adds r1, r1, r0
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _080D68BE
	cmp r0, #4
	beq _080D68BE
	b _080D6AF6
_080D68BE:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D68C4: .4byte wStaticGraphicTilenums
_080D68C8: .4byte 0x0000023A
_080D68CC: .4byte wStaticMotionPalIDs
_080D68D0: .4byte 0xFFFFED00
_080D68D4: .4byte gSineTable
_080D68D8: .4byte 0xFFFFC600
_080D68DC:
	adds r0, r5, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x30
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D691C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r7, [r6, #0x54]
	ldr r1, _080D6964 @ =0xFFFFDD00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6968 @ =0xFFFFB600
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	bne _080D6974
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080D6940
	b _080D6AF6
_080D6940:
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6956
	b _080D6AF6
_080D6956:
	ldr r1, _080D696C @ =0xFFFFDF00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6970 @ =0xFFFFFE00
	adds r0, r4, r2
	str r0, [r5, #0x58]
	b _080D6AF6
	.align 2, 0
_080D6964: .4byte 0xFFFFDD00
_080D6968: .4byte 0xFFFFB600
_080D696C: .4byte 0xFFFFDF00
_080D6970: .4byte 0xFFFFFE00
_080D6974:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D6982
	b _080D6AF6
_080D6982:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
_080D6988:
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _080D6A2C @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x58
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x1d
	strb r0, [r1]
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D69E4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r7, [r6, #0x54]
	ldr r1, _080D6A30 @ =0xFFFFF900
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6A34 @ =0xFFFFA600
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080D6A20
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6A20
	ldr r1, _080D6A38 @ =0xFFFFFB00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6A3C @ =0xFFFFFE00
	adds r0, r4, r2
	str r0, [r5, #0x58]
_080D6A20:
	ldrb r0, [r6, #0xe]
	cmp r0, #2
	bne _080D6AF6
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D6A2C: .4byte 0x00000901
_080D6A30: .4byte 0xFFFFF900
_080D6A34: .4byte 0xFFFFA600
_080D6A38: .4byte 0xFFFFFB00
_080D6A3C: .4byte 0xFFFFFE00
_080D6A40:
	adds r0, r5, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	subs r3, #1
	ldrb r0, [r3]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r3]
	strb r2, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D6A88:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r7, [r6, #0x54]
	ldr r1, _080D6ACC @ =0xFFFFE500
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6AD0 @ =0xFFFFBC00
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6AC0
	ldr r1, _080D6AD4 @ =0xFFFFE600
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6AD8 @ =0xFFFFFF00
	adds r0, r4, r2
	str r0, [r5, #0x58]
_080D6AC0:
	ldrb r0, [r6, #0xe]
	cmp r0, #3
	bne _080D6AF6
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D6ACC: .4byte 0xFFFFE500
_080D6AD0: .4byte 0xFFFFBC00
_080D6AD4: .4byte 0xFFFFE600
_080D6AD8: .4byte 0xFFFFFF00
_080D6ADC:
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0
_080D6AF4:
	strb r0, [r5, #0xd]
_080D6AF6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6afc
FUN_080d6afc: @ 0x080D6AFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D6B7E
	cmp r0, #1
	bgt _080D6B10
	cmp r0, #0
	beq _080D6B16
	b _080D6C48
_080D6B10:
	cmp r0, #2
	beq _080D6BD8
	b _080D6C48
_080D6B16:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D6BC0 @ =wStaticGraphicTilenums
	adds r1, #0xa2
	movs r6, #0
	ldr r0, _080D6BC4 @ =0x000002BE
	strh r0, [r1]
	ldr r5, _080D6BC8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #6
	strh r0, [r5]
	ldr r4, _080D6BCC @ =0x00000654
	ldr r2, _080D6BD0 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D6BD4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	movs r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6B7E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D6B9E
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #3
	movs r1, #0
	bl FUN_080c5628
_080D6B9E:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6BB0
	ldr r0, [r7, #0x5c]
	adds r0, #0x60
	str r0, [r7, #0x5c]
_080D6BB0:
	ldrb r1, [r2, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6C48
	movs r0, #0
	strb r0, [r7, #0x13]
	b _080D6C42
	.align 2, 0
_080D6BC0: .4byte wStaticGraphicTilenums
_080D6BC4: .4byte 0x000002BE
_080D6BC8: .4byte wStaticMotionPalIDs
_080D6BCC: .4byte 0x00000654
_080D6BD0: .4byte gStaticMotionGraphics
_080D6BD4: .4byte gStaticMotionGraphics+12
_080D6BD8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	adds r0, #0x80
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	movs r1, #0x90
	lsls r1, r1, #1
	cmp r0, r1
	bls _080D6C12
	adds r2, r1, #0
_080D6C12:
	adds r0, r7, #0
	adds r0, #0x50
	strh r2, [r0]
	ldrb r0, [r7, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	cmp r0, #0x50
	bls _080D6C48
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D6C42:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6C48:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D6C7C: .4byte gSineTable

	thumb_func_start FUN_080d6c80
FUN_080d6c80: @ 0x080D6C80
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xc
	bls _080D6C8C
	b _080D6F5E
_080D6C8C:
	lsls r0, r0, #2
	ldr r1, _080D6C98 @ =_080D6C9C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6C98: .4byte _080D6C9C
_080D6C9C: @ jump table
	.4byte _080D6CD0 @ case 0
	.4byte _080D6CEC @ case 1
	.4byte _080D6D04 @ case 2
	.4byte _080D6D2C @ case 3
	.4byte _080D6D64 @ case 4
	.4byte _080D6D8C @ case 5
	.4byte _080D6DD8 @ case 6
	.4byte _080D6E00 @ case 7
	.4byte _080D6E2C @ case 8
	.4byte _080D6E74 @ case 9
	.4byte _080D6F38 @ case 10
	.4byte _080D6F48 @ case 11
	.4byte _080D6F5E @ case 12
_080D6CD0:
	ldr r0, _080D6CFC @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D6D00 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6CEC:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D6F52
	.align 2, 0
_080D6CFC: .4byte wDynamicGraphicTilenums
_080D6D00: .4byte wDynamicMotionPalIDs
_080D6D04:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6D18
	b _080D6F5E
_080D6D18:
	ldr r1, _080D6D28 @ =0x0000BE01
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D6F58
	.align 2, 0
_080D6D28: .4byte 0x0000BE01
_080D6D2C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D6D44
	ldr r0, _080D6D5C @ =0x00000101
	bl PlaySound
_080D6D44:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D50
	b _080D6F5E
_080D6D50:
	ldr r1, _080D6D60 @ =0x0000BE02
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6D5C: .4byte 0x00000101
_080D6D60: .4byte 0x0000BE02
_080D6D64:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D76
	b _080D6F5E
_080D6D76:
	ldr r1, _080D6D88 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	b _080D6F58
	.align 2, 0
_080D6D88: .4byte 0x0000BE03
_080D6D8C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, _080D6DD0 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D6DC0
	b _080D6F5E
_080D6DC0:
	ldr r1, _080D6DD4 @ =0x0000BE11
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x60]
	b _080D6F58
	.align 2, 0
_080D6DD0: .4byte gSineTable
_080D6DD4: .4byte 0x0000BE11
_080D6DD8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6DEA
	b _080D6F5E
_080D6DEA:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _080D6DFC @ =0x0000BE12
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6DFC: .4byte 0x0000BE12
_080D6E00:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D6E14
	b _080D6F5E
_080D6E14:
	movs r0, #0x92
	lsls r0, r0, #1
	bl StopSound
	ldr r1, _080D6E28 @ =0x0000BE13
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6E28: .4byte 0x0000BE13
_080D6E2C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6E3E
	b _080D6F5E
_080D6E3E:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D6E6C @ =0x08370DD0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080D6E70 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x5c]
	strb r5, [r6, #0x13]
	b _080D6F58
	.align 2, 0
_080D6E6C: .4byte sCollisions_08370C68+(24*15)
_080D6E70: .4byte 0x0000BE03
_080D6E74:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	beq _080D6EAA
	adds r0, #0x20
	str r0, [r6, #0x5c]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080D6E8E
	str r1, [r6, #0x5c]
_080D6E8E:
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x5c]
	adds r1, r1, r0
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x54]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D6EAA
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x60]
_080D6EAA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080D6ED8
	subs r0, #1
	strb r0, [r6, #0x13]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6EC4
	adds r0, r6, #0
	bl PaintEntityWhite
	b _080D6ECA
_080D6EC4:
	adds r0, r6, #0
	bl UpdateEntityPaletteID
_080D6ECA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x16
	bne _080D6ED8
	ldr r1, _080D6EF8 @ =0x0000BE0D
	adds r0, r6, #0
	bl SetMotion
_080D6ED8:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D6F00
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r1, _080D6EFC @ =0x0000BE0E
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6EF8: .4byte 0x0000BE0D
_080D6EFC: .4byte 0x0000BE0E
_080D6F00:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6F5E
	ldr r1, _080D6F34 @ =0x0000BE0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x5c]
	adds r0, #1
	str r0, [r6, #0x5c]
	movs r0, #0xf8
	bl isSoundPlaying
	cmp r0, #0
	bne _080D6F5E
	movs r0, #0xf8
	bl PlaySound
	b _080D6F5E
	.align 2, 0
_080D6F34: .4byte 0x0000BE0C
_080D6F38:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	b _080D6F54
_080D6F48:
	ldr r1, _080D6F98 @ =0x0000BE0B
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0934
_080D6F52:
	lsls r0, r0, #0x10
_080D6F54:
	cmp r0, #0
	beq _080D6F5E
_080D6F58:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6F5E:
	ldrb r0, [r6, #0xd]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080D6F90
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r1, _080D6F9C @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
_080D6F90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D6F98: .4byte 0x0000BE0B
_080D6F9C: .4byte gSineTable

	thumb_func_start FUN_080d6fa0
FUN_080d6fa0: @ 0x080D6FA0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D6FAC
	b _080D71F0
_080D6FAC:
	lsls r0, r0, #2
	ldr r1, _080D6FB8 @ =_080D6FBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6FB8: .4byte _080D6FBC
_080D6FBC: @ jump table
	.4byte _080D6FD4 @ case 0
	.4byte _080D708E @ case 1
	.4byte _080D70E0 @ case 2
	.4byte _080D710C @ case 3
	.4byte _080D71B8 @ case 4
	.4byte _080D71F0 @ case 5
_080D6FD4:
	movs r4, #0xb8
	ldr r0, _080D7050 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7054 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7058 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D705C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7060 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D7068
	ldr r1, _080D7064 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	str r0, [r6, #0x60]
	movs r0, #3
	b _080D71EE
	.align 2, 0
_080D7050: .4byte wStaticGraphicTilenums
_080D7054: .4byte wStaticMotionPalIDs
_080D7058: .4byte gStaticMotionGraphics
_080D705C: .4byte gStaticMotionGraphics+12
_080D7060: .4byte 0xFFFFE800
_080D7064: .4byte 0x0000B802
_080D7068:
	str r0, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	ldrb r4, [r6, #0xd]
	movs r3, #0x10
	movs r2, #0x5f
_080D7074:
	ldr r1, [r6, #0x60]
	adds r1, r1, r3
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7074
	movs r0, #0
	strb r0, [r6, #0x13]
	adds r0, r4, #1
	strb r0, [r6, #0xd]
_080D708E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r4, r1, r0
	str r4, [r6, #0x60]
	cmp r4, #0
	beq _080D70A8
	b _080D71F0
_080D70A8:
	ldr r1, _080D70D0 @ =gPaletteManager
	ldr r0, _080D70D4 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D70D8 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D70DC @ =0x0000B801
	adds r0, r6, #0
	bl SetMotion
	str r4, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	b _080D71EA
	.align 2, 0
_080D70D0: .4byte gPaletteManager
_080D70D4: .4byte 0x00000404
_080D70D8: .4byte 0x00000406
_080D70DC: .4byte 0x0000B801
_080D70E0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D70F2
	b _080D71F0
_080D70F2:
	ldr r1, _080D7104 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _080D7108 @ =0x0000013D
	bl PlaySound
	b _080D71EA
	.align 2, 0
_080D7104: .4byte 0x0000B802
_080D7108: .4byte 0x0000013D
_080D710C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7124
	ldr r1, _080D7190 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D7124:
	ldr r2, _080D7194 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7198 @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D719C @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7148
	ldr r1, _080D71A0 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D7148:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, _080D71A4 @ =0x0000013D
	bl StopSound
	ldr r1, _080D71A8 @ =gPaletteManager
	ldr r0, _080D71AC @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D71B0 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x64
	str r0, [r6, #0x40]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _080D71B4 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	strb r4, [r6, #0x13]
	b _080D71EA
	.align 2, 0
_080D7190: .4byte 0x0000B802
_080D7194: .4byte RNG_0202f388
_080D7198: .4byte 0x000343FD
_080D719C: .4byte 0x00269EC3
_080D71A0: .4byte 0x0000B803
_080D71A4: .4byte 0x0000013D
_080D71A8: .4byte gPaletteManager
_080D71AC: .4byte 0x00000404
_080D71B0: .4byte 0x00000406
_080D71B4: .4byte 0xFFFFFF00
_080D71B8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, _080D7240 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7244 @ =0x00000FFF
	cmp r0, r1
	bls _080D71F0
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D71EA:
	ldrb r0, [r6, #0xd]
	adds r0, #1
_080D71EE:
	strb r0, [r6, #0xd]
_080D71F0:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7238
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bge _080D7238
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D7248 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x68]
_080D7238:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7240: .4byte gStageRun+232
_080D7244: .4byte 0x00000FFF
_080D7248: .4byte gSineTable

	thumb_func_start FUN_080d724c
FUN_080d724c: @ 0x080D724C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D7258
	b _080D73FA
_080D7258:
	lsls r0, r0, #2
	ldr r1, _080D7264 @ =_080D7268
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7264: .4byte _080D7268
_080D7268: @ jump table
	.4byte _080D7280 @ case 0
	.4byte _080D72FE @ case 1
	.4byte _080D731C @ case 2
	.4byte _080D734E @ case 3
	.4byte _080D7388 @ case 4
	.4byte _080D73B4 @ case 5
_080D7280:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D72E4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D72E8 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D72EC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D72F0 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D72F4 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D72F8
	movs r0, #5
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D72E4: .4byte gStaticMotionGraphics
_080D72E8: .4byte wStaticGraphicTilenums
_080D72EC: .4byte gStaticMotionGraphics+12
_080D72F0: .4byte wStaticMotionPalIDs
_080D72F4: .4byte 0x00008C06
_080D72F8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D72FE:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	ldr r1, _080D7318 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
	.align 2, 0
_080D7318: .4byte 0x00008C05
_080D731C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080D73A8
_080D734E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
_080D7388:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D73FA
	ldr r1, _080D73B0 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D73A8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D73B0: .4byte 0x00008C06
_080D73B4:
	ldr r0, _080D7400 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7404 @ =0x00000FFF
	cmp r0, r1
	bls _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080D7408 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080D73FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7400: .4byte gStageRun+232
_080D7404: .4byte 0x00000FFF
_080D7408: .4byte gSolidFnTable

	thumb_func_start FUN_080d740c
FUN_080d740c: @ 0x080D740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D7418
	b _080D7512
_080D7418:
	lsls r0, r0, #2
	ldr r1, _080D7424 @ =_080D7428
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7424: .4byte _080D7428
_080D7428: @ jump table
	.4byte _080D743C @ case 0
	.4byte _080D74A0 @ case 1
	.4byte _080D74E4 @ case 2
	.4byte _080D74FC @ case 3
	.4byte _080D7512 @ case 4
_080D743C:
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D74C0 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D74C4 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D74C8 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D74CC @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D74D0 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, _080D74D4 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D74D8 @ =0x000087FF
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74A0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r2, _080D74DC @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x64]
	cmp r0, r1
	bge _080D7512
	str r1, [r6, #0x54]
	ldr r1, _080D74E0 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	b _080D750C
	.align 2, 0
_080D74C0: .4byte gStaticMotionGraphics
_080D74C4: .4byte wStaticGraphicTilenums
_080D74C8: .4byte gStaticMotionGraphics+12
_080D74CC: .4byte wStaticMotionPalIDs
_080D74D0: .4byte 0x00008C07
_080D74D4: .4byte gStageRun+232
_080D74D8: .4byte 0x000087FF
_080D74DC: .4byte 0xFFFFFF00
_080D74E0: .4byte 0x00008C05
_080D74E4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7512
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74FC:
	ldr r1, _080D7518 @ =0x00008C05
	adds r0, r6, #0
	movs r2, #0
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7512
_080D750C:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D7512:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7518: .4byte 0x00008C05

	thumb_func_start FUN_080d751c
FUN_080d751c: @ 0x080D751C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D755A
	cmp r0, #1
	bgt _080D7530
	cmp r0, #0
	beq _080D7536
	b _080D7630
_080D7530:
	cmp r0, #2
	beq _080D7610
	b _080D7630
_080D7536:
	ldr r0, _080D7588 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D758C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldr r1, _080D7590 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D755A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D75A0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7594 @ =0x0000C502
	cmp r0, r1
	bne _080D7598
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D75A0
	.align 2, 0
_080D7588: .4byte wDynamicGraphicTilenums
_080D758C: .4byte wDynamicMotionPalIDs
_080D7590: .4byte 0x0000C501
_080D7594: .4byte 0x0000C502
_080D7598:
	ldr r1, _080D7608 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D75A0:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D75D0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7608 @ =0x0000C501
	cmp r0, r1
	bne _080D75C4
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75C4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D75E6
_080D75D0:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D760C @ =0x0000C503
	cmp r0, r1
	bne _080D75E6
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75E6:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D7608 @ =0x0000C501
	cmp r1, r0
	beq _080D762A
	adds r0, #2
	cmp r1, r0
	bne _080D7630
	b _080D762A
	.align 2, 0
_080D7608: .4byte 0x0000C501
_080D760C: .4byte 0x0000C503
_080D7610:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7630
_080D762A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7630:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7638
FUN_080d7638: @ 0x080D7638
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D7682
	cmp r0, #1
	bgt _080D764C
	cmp r0, #0
	beq _080D7652
	b _080D76B4
_080D764C:
	cmp r0, #2
	beq _080D769C
	b _080D76B4
_080D7652:
	ldr r0, _080D7694 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D7698 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7682:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D76AA
	.align 2, 0
_080D7694: .4byte wDynamicGraphicTilenums
_080D7698: .4byte wDynamicMotionPalIDs
_080D769C:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D76AA:
	cmp r0, #0
	beq _080D76B4
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D76B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor62_Update
Actor62_Update: @ 0x080D76BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D76C8
	b _080D7868
_080D76C8:
	lsls r0, r0, #2
	ldr r1, _080D76D4 @ =_080D76D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D76D4: .4byte _080D76D8
_080D76D8: @ jump table
	.4byte _080D7700 @ case 0
	.4byte _080D7718 @ case 1
	.4byte _080D7738 @ case 2
	.4byte _080D775A @ case 3
	.4byte _080D778C @ case 4
	.4byte _080D77AC @ case 5
	.4byte _080D77BE @ case 6
	.4byte _080D77EA @ case 7
	.4byte _080D7828 @ case 8
	.4byte _080D7868 @ case 9
_080D7700:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7718:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D772C
	b _080D7868
_080D772C:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
_080D7738:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	beq _080D774A
	b _080D7868
_080D774A:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	b _080D7862
_080D775A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	adds r0, #0x60
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D7776
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_080D7776:
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _080D7868
	ldr r1, _080D7788 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D7788: .4byte 0x00003303
_080D778C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7868
	ldr r1, _080D77A8 @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D77A8: .4byte 0x00003301
_080D77AC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	b _080D7862
_080D77BE:
	ldr r1, _080D7824 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D77EA:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	b _080D7862
	.align 2, 0
_080D7824: .4byte 0x00000301
_080D7828:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D783C
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D783C:
	ldr r1, [r4, #0x54]
	ldr r0, _080D7870 @ =0xFFFFFC80
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, _080D7874 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7878 @ =0xFFFF6800
	adds r0, r0, r2
	cmp r1, r0
	bge _080D7868
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D785A
	movs r0, #1
	strb r0, [r1, #0x11]
_080D785A:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_080D7862:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7870: .4byte 0xFFFFFC80
_080D7874: .4byte gStageRun+232
_080D7878: .4byte 0xFFFF6800

	thumb_func_start Actor63_Update
Actor63_Update: @ 0x080D787C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #1
	beq _080D78F6
	cmp r0, #1
	bgt _080D7890
	cmp r0, #0
	beq _080D7896
	b _080D793E
_080D7890:
	cmp r0, #2
	beq _080D7938
	b _080D793E
_080D7896:
	ldr r4, _080D7920 @ =0x00000F28
	ldr r1, _080D7924 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D7928 @ =wStaticGraphicTilenums
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D792C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D7930 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D7934 @ =0x0000C203
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r0, #0x5a
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D78F6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	adds r0, #0x80
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D793E
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D793E
	.align 2, 0
_080D7920: .4byte 0x00000F28
_080D7924: .4byte gStaticMotionGraphics
_080D7928: .4byte wStaticGraphicTilenums
_080D792C: .4byte gStaticMotionGraphics+12
_080D7930: .4byte wStaticMotionPalIDs
_080D7934: .4byte 0x0000C203
_080D7938:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D793E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Actor64_Update
Actor64_Update: @ 0x080D7944
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #4
	bls _080D7950
	b _080D7AC0
_080D7950:
	lsls r0, r0, #2
	ldr r1, _080D795C @ =_080D7960
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D795C: .4byte _080D7960
_080D7960: @ jump table
	.4byte _080D7974 @ case 0
	.4byte _080D7A34 @ case 1
	.4byte _080D7A74 @ case 2
	.4byte _080D7AA0 @ case 3
	.4byte _080D7ABA @ case 4
_080D7974:
	movs r4, #0x8c
	ldr r0, _080D7A04 @ =wStaticGraphicTilenums
	lsls r1, r4, #1
	adds r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #2
	strh r2, [r0]
	ldr r0, _080D7A08 @ =wStaticMotionPalIDs
	adds r6, r0, r1
	movs r0, #7
	strh r0, [r6]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D79C4
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r1, _080D7A0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r2, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7A10 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_080D79C4:
	ldr r1, _080D7A14 @ =0x00008C02
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0x11]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D79DE
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
_080D79DE:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r1, [r5, #0x11]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7A20
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x5c]
	ldr r0, _080D7A18 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D7A1C @ =0xFFFF7800
	adds r0, r0, r1
	b _080D7A2C
	.align 2, 0
_080D7A04: .4byte wStaticGraphicTilenums
_080D7A08: .4byte wStaticMotionPalIDs
_080D7A0C: .4byte gStaticMotionGraphics
_080D7A10: .4byte gStaticMotionGraphics+12
_080D7A14: .4byte 0x00008C02
_080D7A18: .4byte gStageRun+232
_080D7A1C: .4byte 0xFFFF7800
_080D7A20:
	ldr r0, _080D7A68 @ =0xFFFFFF00
	str r0, [r5, #0x5c]
	ldr r0, _080D7A6C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7A70 @ =0x000087FF
	adds r0, r0, r2
_080D7A2C:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7A34:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	cmp r2, #0
	bge _080D7A4C
	ldr r1, [r5, #0x64]
	cmp r0, r1
	ble _080D7A56
_080D7A4C:
	cmp r2, #0
	ble _080D7AC0
	ldr r1, [r5, #0x64]
	cmp r0, r1
	blt _080D7AC0
_080D7A56:
	str r1, [r5, #0x54]
	movs r1, #0x8c
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	b _080D7A94
	.align 2, 0
_080D7A68: .4byte 0xFFFFFF00
_080D7A6C: .4byte gStageRun+232
_080D7A70: .4byte 0x000087FF
_080D7A74:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D7AC0
	ldr r1, _080D7A9C @ =0x00008C01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
_080D7A94:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080D7AC0
	.align 2, 0
_080D7A9C: .4byte 0x00008C01
_080D7AA0:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7AC0
	ldr r1, _080D7AC8 @ =0x00008C03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7ABA:
	adds r0, r5, #0
	bl UpdateEntityAnim
_080D7AC0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7AC8: .4byte 0x00008C03

	thumb_func_start Actor65_Update
Actor65_Update: @ 0x080D7ACC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #5
	bls _080D7AD8
	b _080D7D04
_080D7AD8:
	lsls r0, r0, #2
	ldr r1, _080D7AE4 @ =_080D7AE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7AE4: .4byte _080D7AE8
_080D7AE8: @ jump table
	.4byte _080D7B00 @ case 0
	.4byte _080D7B8C @ case 1
	.4byte _080D7BF4 @ case 2
	.4byte _080D7C20 @ case 3
	.4byte _080D7CCC @ case 4
	.4byte _080D7D04 @ case 5
_080D7B00:
	movs r4, #0xb8
	ldr r0, _080D7BD0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7BD4 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7BD8 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7BDC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7BE0 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r7, #0x58]
	str r6, [r7, #0x60]
	movs r0, #0x10
	str r0, [r7, #0x68]
	movs r3, #0x10
	movs r2, #0x5f
_080D7B70:
	ldr r1, [r7, #0x60]
	adds r1, r1, r3
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7B70
	movs r0, #0
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7B8C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x68]
	subs r4, r1, r0
	str r4, [r7, #0x60]
	cmp r4, #0
	beq _080D7BA6
	b _080D7D04
_080D7BA6:
	ldr r1, _080D7BE4 @ =gPaletteManager
	ldr r0, _080D7BE8 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7BEC @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D7BF0 @ =0x0000B801
	adds r0, r7, #0
	bl SetMotion
	str r4, [r7, #0x60]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	b _080D7CFE
	.align 2, 0
_080D7BD0: .4byte wStaticGraphicTilenums
_080D7BD4: .4byte wStaticMotionPalIDs
_080D7BD8: .4byte gStaticMotionGraphics
_080D7BDC: .4byte gStaticMotionGraphics+12
_080D7BE0: .4byte 0xFFFFE800
_080D7BE4: .4byte gPaletteManager
_080D7BE8: .4byte 0x00000404
_080D7BEC: .4byte 0x00000406
_080D7BF0: .4byte 0x0000B801
_080D7BF4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D7C06
	b _080D7D04
_080D7C06:
	ldr r1, _080D7C18 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
	ldr r0, _080D7C1C @ =0x0000013D
	bl PlaySound
	b _080D7CFE
	.align 2, 0
_080D7C18: .4byte 0x0000B802
_080D7C1C: .4byte 0x0000013D
_080D7C20:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7C38
	ldr r1, _080D7CA4 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
_080D7C38:
	ldr r2, _080D7CA8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7CAC @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D7CB0 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7C5C
	ldr r1, _080D7CB4 @ =0x0000B803
	adds r0, r7, #0
	bl SetMotion
_080D7C5C:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, _080D7CB8 @ =0x0000013D
	bl StopSound
	ldr r1, _080D7CBC @ =gPaletteManager
	ldr r0, _080D7CC0 @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7CC4 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [r7, #0x40]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _080D7CC8 @ =0xFFFFFF00
	str r0, [r7, #0x60]
	strb r4, [r7, #0x13]
	b _080D7CFE
	.align 2, 0
_080D7CA4: .4byte 0x0000B802
_080D7CA8: .4byte RNG_0202f388
_080D7CAC: .4byte 0x000343FD
_080D7CB0: .4byte 0x00269EC3
_080D7CB4: .4byte 0x0000B803
_080D7CB8: .4byte 0x0000013D
_080D7CBC: .4byte gPaletteManager
_080D7CC0: .4byte 0x00000404
_080D7CC4: .4byte 0x00000406
_080D7CC8: .4byte 0xFFFFFF00
_080D7CCC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, _080D7D54 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _080D7D58 @ =0x00000FFF
	cmp r0, r1
	bls _080D7D04
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D7CFE:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7D04:
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7D4C
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bge _080D7D4C
	ldrb r0, [r7, #0x13]
	adds r2, r0, #1
	strb r2, [r7, #0x13]
	ldr r3, _080D7D5C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x68]
_080D7D4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D7D54: .4byte gStageRun+232
_080D7D58: .4byte 0x00000FFF
_080D7D5C: .4byte gSineTable
