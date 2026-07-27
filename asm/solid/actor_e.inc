	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor32_Update
Actor32_Update: @ 0x080D3E28
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xd]
	ldr r5, _080D3E40 @ =gWindowRegBuffer
	cmp r0, #4
	bhi _080D3EDC
	lsls r0, r0, #2
	ldr r1, _080D3E44 @ =_080D3E48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3E40: .4byte gWindowRegBuffer
_080D3E44: .4byte _080D3E48
_080D3E48: @ jump table
	.4byte _080D3E5C @ case 0
	.4byte _080D3E72 @ case 1
	.4byte _080D3E94 @ case 2
	.4byte _080D3EC0 @ case 3
	.4byte _080D3EDC @ case 4
_080D3E5C:
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r3, #0x54]
	movs r0, #0x92
	lsls r0, r0, #8
	str r0, [r3, #0x58]
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E72:
	ldr r0, [r3, #0x58]
	ldr r1, _080D3F08 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E94:
	ldr r1, _080D3F10 @ =gSineTable
	ldrb r0, [r3, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb8
	muls r0, r1, r0
	str r0, [r3, #0x54]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0x10
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EC0:
	ldrb r0, [r3, #0x13]
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0
	bne _080D3EDC
	ldrh r0, [r5]
	ldr r1, _080D3F14 @ =0x0000BFFF
	ands r1, r0
	strh r1, [r5]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EDC:
	ldrb r0, [r3, #0x12]
	adds r0, #1
	strb r0, [r3, #0x12]
	ldr r2, [r3, #0x54]
	asrs r2, r2, #8
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xc0
	adds r4, r5, #0
	movs r0, #0xc0
	subs r0, r0, r2
	lsls r2, r0, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xf0
	bgt _080D3F18
	movs r0, #0xff
	ands r0, r1
	b _080D3F1A
	.align 2, 0
_080D3F08: .4byte 0xFFFFF800
_080D3F0C: .4byte gWindowRegBuffer
_080D3F10: .4byte gSineTable
_080D3F14: .4byte 0x0000BFFF
_080D3F18:
	movs r0, #0xf0
_080D3F1A:
	orrs r0, r2
	strh r0, [r4, #6]
	ldr r1, [r3, #0x58]
	asrs r1, r1, #8
	ldrb r2, [r3, #0x12]
	movs r0, #1
	ands r0, r2
	lsls r0, r0, #3
	subs r1, r1, r0
	adds r2, r0, #0
	adds r2, #0x93
	movs r0, #0xff
	ands r2, r0
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _080D3F40
	lsls r0, r0, #8
	orrs r2, r0
_080D3F40:
	strh r2, [r5, #0xa]
	ldr r1, _080D3F50 @ =gPaletteManager
	ldr r2, _080D3F54 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F50: .4byte gPaletteManager
_080D3F54: .4byte 0x00007FFF

	thumb_func_start Actor33_Update
Actor33_Update: @ 0x080D3F58
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xe
	bls _080D3F64
	b _080D4108
_080D3F64:
	lsls r0, r0, #2
	ldr r1, _080D3F70 @ =_080D3F74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F70: .4byte _080D3F74
_080D3F74: @ jump table
	.4byte _080D3FB0 @ case 0
	.4byte _080D3FC8 @ case 1
	.4byte _080D4006 @ case 2
	.4byte _080D402C @ case 3
	.4byte _080D403E @ case 4
	.4byte _080D405C @ case 5
	.4byte _080D406A @ case 6
	.4byte _080D4080 @ case 7
	.4byte _080D4092 @ case 8
	.4byte _080D40A6 @ case 9
	.4byte _080D40B6 @ case 10
	.4byte _080D40C4 @ case 11
	.4byte _080D40D4 @ case 12
	.4byte _080D40F4 @ case 13
	.4byte _080D4102 @ case 14
_080D3FB0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3FC8:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3FEA
	b _080D4108
_080D3FEA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D4058 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4006:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D402C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D403E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	b _080D40E6
	.align 2, 0
_080D404C: .4byte gPaletteManager
_080D4050: .4byte 0x00000404
_080D4054: .4byte 0x00000406
_080D4058: .4byte 0x00003503
_080D405C:
	ldr r1, _080D407C @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D406A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4108
	b _080D40EC
	.align 2, 0
_080D407C: .4byte 0x00003501
_080D4080:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4092:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4108
	b _080D40EC
_080D40A6:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40B6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	b _080D40E6
_080D40C4:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40D4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	subs r0, #0x50
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x20
_080D40E6:
	ands r0, r1
	cmp r0, #0
	beq _080D4108
_080D40EC:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D4108
_080D40F4:
	ldr r1, _080D4110 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4102:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D4108:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D4110: .4byte 0x00003303

	thumb_func_start Actor34_Update
Actor34_Update: @ 0x080D4114
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D4124
	cmp r0, #1
	beq _080D418C
	b _080D4220
_080D4124:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D41EC @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r4, #0xb8
	ldr r1, _080D41F0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D41F4 @ =0x00000385
	strh r0, [r1]
	ldr r5, _080D41F8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080D41FC @ =gStaticMotionGraphics
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
	ldr r0, _080D4200 @ =gStaticMotionGraphics+12
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
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D418C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D41A4
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D41A4:
	ldr r4, _080D4208 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r7, _080D420C @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _080D4210 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D41C8
	ldr r1, _080D4214 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D41C8:
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D4220
	ldr r0, [r4]
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4218
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080D421E
	.align 2, 0
_080D41EC: .4byte 0xFFFFE800
_080D41F0: .4byte wStaticGraphicTilenums
_080D41F4: .4byte 0x00000385
_080D41F8: .4byte wStaticMotionPalIDs
_080D41FC: .4byte gStaticMotionGraphics
_080D4200: .4byte gStaticMotionGraphics+12
_080D4204: .4byte 0x0000B802
_080D4208: .4byte RNG_0202f388
_080D420C: .4byte 0x000343FD
_080D4210: .4byte 0x00269EC3
_080D4214: .4byte 0x0000B803
_080D4218:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D421E:
	strb r0, [r6, #0xa]
_080D4220:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor35_Update
Actor35_Update: @ 0x080D4228
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D4234
	b _080D43B6
_080D4234:
	lsls r0, r0, #2
	ldr r1, _080D4240 @ =_080D4244
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4240: .4byte _080D4244
_080D4244: @ jump table
	.4byte _080D426C @ case 0
	.4byte _080D4284 @ case 1
	.4byte _080D42A4 @ case 2
	.4byte _080D42C0 @ case 3
	.4byte _080D42D4 @ case 4
	.4byte _080D42F4 @ case 5
	.4byte _080D4302 @ case 6
	.4byte _080D4324 @ case 7
	.4byte _080D434C @ case 8
	.4byte _080D436C @ case 9
_080D426C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080D429C @ =0x0000C20D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4284:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D4298
	b _080D43B6
_080D4298:
	ldr r1, _080D42A0 @ =0x0000C20C
	b _080D433A
	.align 2, 0
_080D429C: .4byte 0x0000C20D
_080D42A0: .4byte 0x0000C20C
_080D42A4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D42B8
	b _080D43B6
_080D42B8:
	ldr r1, _080D42BC @ =0x0000C201
	b _080D433A
	.align 2, 0
_080D42BC: .4byte 0x0000C201
_080D42C0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	b _080D4336
_080D42D4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D42F0 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D42F0: .4byte 0x0000C206
_080D42F4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	b _080D4330
_080D4302:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4320 @ =0x0000C201
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D4320: .4byte 0x0000C201
_080D4324:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
_080D4330:
	ands r0, r1
	cmp r0, #0
	beq _080D43B6
_080D4336:
	movs r1, #0xc2
	lsls r1, r1, #8
_080D433A:
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
_080D4344:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D43B6
_080D434C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4390 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D436C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r2, #0
	ldr r0, [r4, #0x18]
	ldr r0, [r0, #4]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080D4382
	movs r2, #1
_080D4382:
	cmp r2, #0
	beq _080D4394
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080D439A
	.align 2, 0
_080D4390: .4byte 0x0000C206
_080D4394:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D439A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080D43B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Actor36_Update
Actor36_Update: @ 0x080D43BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D43CC
	cmp r0, #1
	beq _080D4430
	b _080D4436
_080D43CC:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xc2
	ldr r0, _080D443C @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x88
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4440 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0xc2
	lsls r4, r4, #2
	ldr r2, _080D4444 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D4448 @ =gStaticMotionGraphics+12
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
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4430:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D4436:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D443C: .4byte wStaticGraphicTilenums
_080D4440: .4byte wStaticMotionPalIDs
_080D4444: .4byte gStaticMotionGraphics
_080D4448: .4byte gStaticMotionGraphics+12

	thumb_func_start Actor37_Update
Actor37_Update: @ 0x080D444C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D4458
	b _080D45E4
_080D4458:
	lsls r0, r0, #2
	ldr r1, _080D4464 @ =_080D4468
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4464: .4byte _080D4468
_080D4468: @ jump table
	.4byte _080D447C @ case 0
	.4byte _080D454C @ case 1
	.4byte _080D459C @ case 2
	.4byte _080D45BC @ case 3
	.4byte _080D45E4 @ case 4
_080D447C:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	bne _080D44F4
	movs r4, #0x82
	ldr r0, _080D44E4 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x98
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D44E8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x82
	lsls r4, r4, #2
	ldr r2, _080D44EC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D44F0 @ =gStaticMotionGraphics+12
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
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	b _080D4546
	.align 2, 0
_080D44E4: .4byte wStaticGraphicTilenums
_080D44E8: .4byte wStaticMotionPalIDs
_080D44EC: .4byte gStaticMotionGraphics
_080D44F0: .4byte gStaticMotionGraphics+12
_080D44F4:
	movs r4, #0x8c
	ldr r1, _080D4584 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D4588 @ =0x00000296
	strh r0, [r1]
	ldr r5, _080D458C @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r2, _080D4590 @ =gStaticMotionGraphics
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
	ldr r0, _080D4594 @ =gStaticMotionGraphics+12
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
	ldr r1, _080D4598 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
_080D4546:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D454C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D45E4
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
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D45DE
	.align 2, 0
_080D4584: .4byte wStaticGraphicTilenums
_080D4588: .4byte 0x00000296
_080D458C: .4byte wStaticMotionPalIDs
_080D4590: .4byte gStaticMotionGraphics
_080D4594: .4byte gStaticMotionGraphics+12
_080D4598: .4byte 0x00008C05
_080D459C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D45E4
	ldr r1, _080D45B8 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	b _080D45DE
	.align 2, 0
_080D45B8: .4byte 0x00008C07
_080D45BC:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, [r6, #0x54]
	ldr r0, _080D45EC @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r0, _080D45F0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D45F4 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	bge _080D45E4
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D45DE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D45E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D45EC: .4byte 0xFFFFFF00
_080D45F0: .4byte gStageRun+232
_080D45F4: .4byte 0xFFFF7000

	thumb_func_start Actor38_Update
Actor38_Update: @ 0x080D45F8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D467C
	cmp r0, #1
	ble _080D4608
	b _080D4752
_080D4608:
	cmp r0, #0
	beq _080D460E
	b _080D4752
_080D460E:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4720 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4724 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4728 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #7
	strh r0, [r5]
	ldr r4, _080D472C @ =0x00000654
	ldr r2, _080D4730 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r0, _080D4734 @ =gStaticMotionGraphics+12
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
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D467C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r5, _080D4738 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, [r7, #0x5c]
	adds r4, r1, r0
	str r4, [r7, #0x54]
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r7, #0x68]
	adds r3, r1, r0
	str r3, [r7, #0x58]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _080D46C2
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl FUN_080c5628
_080D46C2:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4744
	ldrb r1, [r7, #0x13]
	adds r1, #1
	strb r1, [r7, #0x13]
	ldr r2, [r7, #0x5c]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r2, r2, r1
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x68]
	ldr r2, _080D473C @ =0xFFFFFF00
	adds r0, r0, r2
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4740 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D4752
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D4752
	.align 2, 0
_080D4720: .4byte 0xFFFFB000
_080D4724: .4byte wStaticGraphicTilenums
_080D4728: .4byte wStaticMotionPalIDs
_080D472C: .4byte 0x00000654
_080D4730: .4byte gStaticMotionGraphics
_080D4734: .4byte gStaticMotionGraphics+12
_080D4738: .4byte gSineTable
_080D473C: .4byte 0xFFFFFF00
_080D4740: .4byte gStageRun+232
_080D4744:
	ldr r0, [r7, #0x68]
	lsls r1, r0, #7
	subs r1, r1, r0
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	asrs r1, r1, #7
	str r1, [r7, #0x68]
_080D4752:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor39_Update
Actor39_Update: @ 0x080D4758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bls _080D4768
	b _080D4976
_080D4768:
	lsls r0, r0, #2
	ldr r1, _080D4774 @ =_080D4778
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4774: .4byte _080D4778
_080D4778: @ jump table
	.4byte _080D47A0 @ case 0
	.4byte _080D47B8 @ case 1
	.4byte _080D481C @ case 2
	.4byte _080D4870 @ case 3
	.4byte _080D48A2 @ case 4
	.4byte _080D48D0 @ case 5
	.4byte _080D48FE @ case 6
	.4byte _080D4930 @ case 7
	.4byte _080D4954 @ case 8
	.4byte _080D4976 @ case 9
_080D47A0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D47B8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _080D47CE
	b _080D4976
_080D47CE:
	ldrb r1, [r7, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080D4818 @ =sCollisions_08370C68
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	mov r1, r8
	ands r2, r1
	adds r0, r5, #0
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	str r6, [r7, #0x2c]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4818: .4byte sCollisions_08370C68
_080D481C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	bne _080D4830
	adds r0, r7, #0
	bl CreateAfterImages
	str r0, [r7, #0x2c]
_080D4830:
	ldr r0, [r7, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D484A
	b _080D4976
_080D484A:
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080D4852
	strb r1, [r0, #0x11]
_080D4852:
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xa
	bl PlaySound
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D4870:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	adds r2, #0x40
	str r2, [r7, #0x60]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D4976
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	movs r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D48A2:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #4
	subs r1, r1, r0
	asrs r1, r1, #4
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4976
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r7, #0x12]
	b _080D4970
_080D48D0:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4976
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	b _080D4970
_080D48FE:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	asrs r1, r1, #2
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	cmp r1, #3
	bgt _080D4976
	ldr r1, _080D492C @ =0x00003F05
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	b _080D4970
	.align 2, 0
_080D492C: .4byte 0x00003F05
_080D4930:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4976
	ldr r1, _080D4950 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4950: .4byte 0x00003501
_080D4954:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D4968
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _080D4976
_080D4968:
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D4970:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4976:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ActorOmegaZero40_Update
ActorOmegaZero40_Update: @ 0x080D4980
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xf
	bls _080D498C
	b _080D4EFA
_080D498C:
	lsls r0, r0, #2
	ldr r1, _080D4998 @ =_080D499C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4998: .4byte _080D499C
_080D499C: @ jump table
	.4byte _080D49DC @ case 0
	.4byte _080D4A0A @ case 1
	.4byte _080D4A6C @ case 2
	.4byte _080D4AD8 @ case 3
	.4byte _080D4B58 @ case 4
	.4byte _080D4BEC @ case 5
	.4byte _080D4C02 @ case 6
	.4byte _080D4C10 @ case 7
	.4byte _080D4C28 @ case 8
	.4byte _080D4C3A @ case 9
	.4byte _080D4C50 @ case 10
	.4byte _080D4C82 @ case 11
	.4byte _080D4D60 @ case 12
	.4byte _080D4E64 @ case 13
	.4byte _080D4E84 @ case 14
	.4byte _080D4EDC @ case 15
_080D49DC:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r0, #0
	movs r1, #8
	bl LoadZeroPalette
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r6, #0x20]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	ldr r1, _080D4A64 @ =0x00003F05
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4A0A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D4A1E
	b _080D4EFA
_080D4A1E:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4A68 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	str r1, [r0, #0x78]
	strb r1, [r6, #0x12]
	strb r1, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4A64: .4byte 0x00003F05
_080D4A68: .4byte 0xFFFFF400
_080D4A6C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldr r2, [r6, #0x28]
	ldr r1, _080D4AC0 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r2, #0x78]
	ldr r2, [r6, #0x28]
	ldrb r0, [r6, #0x13]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4AC4
	ldrb r1, [r6, #0x12]
	movs r0, #0x12
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bge _080D4ABA
	b _080D4EFA
_080D4ABA:
	adds r0, r1, #3
	strb r0, [r6, #0x12]
	b _080D4EFA
	.align 2, 0
_080D4AC0: .4byte gSineTable
_080D4AC4:
	ldrb r0, [r6, #0x12]
	cmp r0, #3
	bls _080D4AD0
	subs r0, #3
	strb r0, [r6, #0x12]
	b _080D4EFA
_080D4AD0:
	ldr r0, [r6, #0x28]
	adds r0, #0x77
	strb r3, [r0]
	b _080D4EF4
_080D4AD8:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D4AEC
	b _080D4EFA
_080D4AEC:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4B50 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4B54 @ =sCollisions_08370C68+(24*1)
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r6, #0x12]
	strb r5, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4B50: .4byte 0xFFFFF400
_080D4B54: .4byte sCollisions_08370C68+(24*1)
_080D4B58:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0x12]
	cmp r0, #0x3f
	bhi _080D4B6E
	adds r0, #0x10
	strb r0, [r6, #0x12]
_080D4B6E:
	ldrb r1, [r6, #0x13]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4BBC
	cmp r1, #3
	bls _080D4B98
	ldr r2, _080D4BAC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D4BB0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D4BB4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	bne _080D4BBC
_080D4B98:
	ldr r2, [r6, #0x28]
	ldr r1, _080D4BB8 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	str r0, [r2, #0x78]
	b _080D4BC2
	.align 2, 0
_080D4BAC: .4byte RNG_0202f388
_080D4BB0: .4byte 0x000343FD
_080D4BB4: .4byte 0x00269EC3
_080D4BB8: .4byte gSineTable
_080D4BBC:
	ldr r1, [r6, #0x28]
	movs r0, #0
	str r0, [r1, #0x78]
_080D4BC2:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x40
	bhi _080D4BCA
	b _080D4EFA
_080D4BCA:
	ldr r0, [r6, #0x28]
	adds r0, #0x77
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
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
	b _080D4EF4
_080D4BEC:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080D4C00
	b _080D4EFA
_080D4C00:
	b _080D4EF4
_080D4C02:
	ldr r1, _080D4C24 @ =0x00003501
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C10:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D4C22
	b _080D4EFA
_080D4C22:
	b _080D4EF4
	.align 2, 0
_080D4C24: .4byte 0x00003501
_080D4C28:
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C3A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D4C4E
	b _080D4EFA
_080D4C4E:
	b _080D4EF4
_080D4C50:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4CD0 @ =0x08370C98
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C82:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	cmp r0, #0
	beq _080D4CAA
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4CAA
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
_080D4CAA:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4CE4
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ands r0, r1
	cmp r0, #0
	beq _080D4CD4
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	b _080D4CDE
	.align 2, 0
_080D4CD0: .4byte sCollisions_08370C68+(24*2)
_080D4CD4:
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
_080D4CDE:
	ldr r0, _080D4D54 @ =0x0000013B
	bl PlaySound
_080D4CE4:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080D4CF2
	b _080D4EFA
_080D4CF2:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4D58 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4D5C @ =sCollisions_08370C68+(24*1)
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r6, #0x12]
	strb r5, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4D54: .4byte 0x0000013B
_080D4D58: .4byte 0xFFFFF400
_080D4D5C: .4byte sCollisions_08370C68+(24*1)
_080D4D60:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	cmp r0, #0
	beq _080D4D88
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4D88
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
_080D4D88:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0x12]
	cmp r0, #0x3f
	bhi _080D4D98
	adds r0, #0x10
	strb r0, [r6, #0x12]
_080D4D98:
	ldrb r1, [r6, #0x13]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4DE8
	cmp r1, #3
	bls _080D4DC2
	ldr r2, _080D4DD8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D4DDC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D4DE0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	bne _080D4DE8
_080D4DC2:
	ldr r2, [r6, #0x28]
	ldr r1, _080D4DE4 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	str r0, [r2, #0x78]
	b _080D4DEE
	.align 2, 0
_080D4DD8: .4byte RNG_0202f388
_080D4DDC: .4byte 0x000343FD
_080D4DE0: .4byte 0x00269EC3
_080D4DE4: .4byte gSineTable
_080D4DE8:
	ldr r1, [r6, #0x28]
	movs r0, #0
	str r0, [r1, #0x78]
_080D4DEE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x40
	bhi _080D4DF6
	b _080D4EFA
_080D4DF6:
	ldr r1, [r6, #0x28]
	adds r1, #0x77
	movs r2, #0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080D4E34
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4E30 @ =0x08370C98
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xb
	b _080D4EF8
	.align 2, 0
_080D4E30: .4byte sCollisions_08370C68+(24*2)
_080D4E34:
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4E60 @ =0x08370CB0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	b _080D4EF4
	.align 2, 0
_080D4E60: .4byte sCollisions_08370C68+(24*3)
_080D4E64:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D4EFA
	ldr r1, _080D4E80 @ =0x00003F05
	adds r0, r6, #0
	bl SetMotion
	b _080D4EF4
	.align 2, 0
_080D4E80: .4byte 0x00003F05
_080D4E84:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _080D4EFA
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldr r3, _080D4ED0 @ =gStageRun
	ldrh r2, [r3, #8]
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _080D4EC2
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080D4EC2
	ldr r0, _080D4ED4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080D4EC2:
	ldr r1, _080D4ED8 @ =0x08370E08
	adds r0, r6, #0
	bl CreateBossExplosion
	str r0, [r6, #0x2c]
	b _080D4EF4
	.align 2, 0
_080D4ED0: .4byte gStageRun
_080D4ED4: .4byte 0x0000FFFE
_080D4ED8: .4byte Coord_08370e08
_080D4EDC:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080D4EFA
	ldr r2, _080D4F00 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_080D4EF4:
	ldrb r0, [r6, #0xd]
	adds r0, #1
_080D4EF8:
	strb r0, [r6, #0xd]
_080D4EFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D4F00: .4byte gStageRun

	thumb_func_start Actor41_Update
Actor41_Update: @ 0x080D4F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bls _080D4F14
	b _080D50D2
_080D4F14:
	lsls r0, r0, #2
	ldr r1, _080D4F20 @ =_080D4F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4F20: .4byte _080D4F24
_080D4F24: @ jump table
	.4byte _080D4F38 @ case 0
	.4byte _080D4FAC @ case 1
	.4byte _080D5008 @ case 2
	.4byte _080D5036 @ case 3
	.4byte _080D505C @ case 4
_080D4F38:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4FF0 @ =0xFFFFB800
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4FF4 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0x8c
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4FF8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #5
	strh r0, [r5]
	ldr r4, _080D4FFC @ =0x00000654
	ldr r2, _080D5000 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5004 @ =gStaticMotionGraphics+12
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
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4FAC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r1, [r7, #0x13]
	movs r0, #0x13
	ldrsb r0, [r7, r0]
	cmp r0, #0
	blt _080D4FD2
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, #2
	strh r0, [r1]
_080D4FD2:
	ldr r1, [r7, #0x60]
	lsls r0, r1, #6
	subs r0, r0, r1
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #6
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5050
	.align 2, 0
_080D4FF0: .4byte 0xFFFFB800
_080D4FF4: .4byte wStaticGraphicTilenums
_080D4FF8: .4byte wStaticMotionPalIDs
_080D4FFC: .4byte 0x00000654
_080D5000: .4byte gStaticMotionGraphics
_080D5004: .4byte gStaticMotionGraphics+12
_080D5008:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080D5028
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #5
	movs r1, #0
	bl FUN_080c5628
_080D5028:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5054
_080D5036:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	ldr r0, [r7, #0x5c]
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x60]
	str r0, [r7, #0x68]
_080D5050:
	movs r0, #0
	strb r0, [r7, #0x13]
_080D5054:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D50D2
_080D505C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r6, _080D510C @ =RNG_0202f388
	ldr r0, [r6]
	ldr r4, _080D5110 @ =0x000343FD
	mov r8, r4
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _080D5114 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	mov r1, r8
	muls r1, r4, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r6]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #5
	adds r0, r7, #0
	bl _ForceEntityPalette
_080D50D2:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D5118 @ =gSineTable
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
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D510C: .4byte RNG_0202f388
_080D5110: .4byte 0x000343FD
_080D5114: .4byte 0x00269EC3
_080D5118: .4byte gSineTable

	thumb_func_start ActorLastHarpuia_Update
ActorLastHarpuia_Update: @ 0x080D511C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bls _080D5128
	b _080D5438
_080D5128:
	lsls r0, r0, #2
	ldr r1, _080D5134 @ =_080D5138
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5134: .4byte _080D5138
_080D5138: @ jump table
	.4byte _080D5164 @ case 0
	.4byte _080D5180 @ case 1
	.4byte _080D51B0 @ case 2
	.4byte _080D51EC @ case 3
	.4byte _080D521C @ case 4
	.4byte _080D5260 @ case 5
	.4byte _080D52BC @ case 6
	.4byte _080D5318 @ case 7
	.4byte _080D5380 @ case 8
	.4byte _080D53B8 @ case 9
	.4byte _080D5408 @ case 10
_080D5164:
	ldr r0, _080D51A0 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D51A4 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D5180:
	ldr r1, _080D51A8 @ =0x0000BE03
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D5192
	b _080D5438
_080D5192:
	ldr r1, _080D51AC @ =0x0000BE14
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	str r0, [r5, #0x5c]
	b _080D53F8
	.align 2, 0
_080D51A0: .4byte wDynamicGraphicTilenums
_080D51A4: .4byte wDynamicMotionPalIDs
_080D51A8: .4byte 0x0000BE03
_080D51AC: .4byte 0x0000BE14
_080D51B0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x5c]
	ldr r0, _080D51E4 @ =0x000003FF
	cmp r1, r0
	bgt _080D51C4
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D51C4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D51D8
	b _080D5438
_080D51D8:
	ldr r1, _080D51E8 @ =0x0000BE15
	adds r0, r5, #0
	bl SetMotion
	b _080D53F8
	.align 2, 0
_080D51E4: .4byte 0x000003FF
_080D51E8: .4byte 0x0000BE15
_080D51EC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x5c]
	ldr r0, _080D5218 @ =0x000003FF
	cmp r1, r0
	bgt _080D5200
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D5200:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D5214
	b _080D5438
_080D5214:
	b _080D53F8
	.align 2, 0
_080D5218: .4byte 0x000003FF
_080D521C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x5c]
	ldr r0, _080D5254 @ =0x000003FF
	cmp r1, r0
	bgt _080D5230
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D5230:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080D5258 @ =0x000B1800
	cmp r0, r1
	bgt _080D5240
	b _080D5438
_080D5240:
	ldr r1, _080D525C @ =0x0000BE16
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D5254: .4byte 0x000003FF
_080D5258: .4byte 0x000B1800
_080D525C: .4byte 0x0000BE16
_080D5260:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080D5294
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D52B4 @ =0x08370CC8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D5294:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D52A0
	b _080D5438
_080D52A0:
	ldr r1, _080D52B8 @ =0x0000BE17
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	strb r6, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D52B4: .4byte sCollisions_08370C68+(24*4)
_080D52B8: .4byte 0x0000BE17
_080D52BC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _080D52F0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D5310 @ =0x08370CE0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D52F0:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D52FC
	b _080D5438
_080D52FC:
	ldr r1, _080D5314 @ =0x0000BE18
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	strb r6, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D5310: .4byte sCollisions_08370C68+(24*5)
_080D5314: .4byte 0x0000BE18
_080D5318:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _080D534C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D5378 @ =0x08370CF8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D534C:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5438
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D537C @ =0x08370D10
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _080D53F8
	.align 2, 0
_080D5378: .4byte sCollisions_08370C68+(24*6)
_080D537C: .4byte sCollisions_08370C68+(24*7)
_080D5380:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D5438
	ldr r1, _080D53B0 @ =0x0000BE0C
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf8
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r0, _080D53B4 @ =0xFFFFFC00
	str r0, [r5, #0x60]
	b _080D53F8
	.align 2, 0
_080D53B0: .4byte 0x0000BE0C
_080D53B4: .4byte 0xFFFFFC00
_080D53B8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	subs r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x20
	str r1, [r5, #0x60]
	ldr r0, _080D5400 @ =0xFFFFFF00
	cmp r1, r0
	blt _080D53E0
	lsls r0, r2, #4
	subs r0, r0, r2
	asrs r0, r0, #4
	str r0, [r5, #0x5c]
_080D53E0:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	blt _080D5438
	ldr r1, _080D5404 @ =0x0000BE0D
	adds r0, r5, #0
	bl SetMotion
	movs r1, #0
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	strb r1, [r5, #0x12]
_080D53F8:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080D5438
	.align 2, 0
_080D5400: .4byte 0xFFFFFF00
_080D5404: .4byte 0x0000BE0D
_080D5408:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldr r1, _080D5440 @ =gSineTable
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_080D5438:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D5440: .4byte gSineTable

	thumb_func_start ActorLastFefnir_Update
ActorLastFefnir_Update: @ 0x080D5444
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xa
	bls _080D5450
	b _080D55A2
_080D5450:
	lsls r0, r0, #2
	ldr r1, _080D545C @ =_080D5460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D545C: .4byte _080D5460
_080D5460: @ jump table
	.4byte _080D548C @ case 0
	.4byte _080D54A8 @ case 1
	.4byte _080D5528 @ case 2
	.4byte _080D553A @ case 3
	.4byte _080D5574 @ case 4
	.4byte _080D553A @ case 5
	.4byte _080D5574 @ case 6
	.4byte _080D553A @ case 7
	.4byte _080D5574 @ case 8
	.4byte _080D558C @ case 9
	.4byte _080D559C @ case 10
_080D548C:
	ldr r0, _080D5508 @ =wDynamicGraphicTilenums
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xd0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D550C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D54A8:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D55A2
	ldr r1, _080D5510 @ =0x0000A109
	adds r0, r6, #0
	bl SetMotion
	ldr r1, _080D5514 @ =wStaticGraphicTilenums
	adds r1, #0x42
	ldr r0, _080D5518 @ =0x00000327
	strh r0, [r1]
	ldr r5, _080D551C @ =wStaticMotionPalIDs
	adds r5, #0x42
	movs r0, #7
	strh r0, [r5]
	movs r4, #0xa5
	lsls r4, r4, #2
	ldr r2, _080D5520 @ =gStaticMotionGraphics
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
	ldr r0, _080D5524 @ =gStaticMotionGraphics+12
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
	b _080D5584
	.align 2, 0
_080D5508: .4byte wDynamicGraphicTilenums
_080D550C: .4byte wDynamicMotionPalIDs
_080D5510: .4byte 0x0000A109
_080D5514: .4byte wStaticGraphicTilenums
_080D5518: .4byte 0x00000327
_080D551C: .4byte wStaticMotionPalIDs
_080D5520: .4byte gStaticMotionGraphics
_080D5524: .4byte gStaticMotionGraphics+12
_080D5528:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D55A2
	b _080D5584
_080D553A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, _080D5570 @ =0x0000A10B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	movs r1, #0x2c
	bl CreateScriptActor
	ldrb r1, [r6, #0xd]
	subs r1, #3
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	strb r1, [r0, #0x11]
	movs r0, #0xf5
	bl PlaySound
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	b _080D5584
	.align 2, 0
_080D5570: .4byte 0x0000A10B
_080D5574:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D55A2
_080D5584:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D55A2
_080D558C:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D559C:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D55A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ActorLastFefnirFireball_Update
ActorLastFefnirFireball_Update: @ 0x080D55A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r4, [r5, #0xd]
	cmp r4, #0
	beq _080D55BA
	cmp r4, #1
	beq _080D5614
	b _080D569C
_080D55BA:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
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
	ldr r0, [r6, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080D56A4 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D5614:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _080D565C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldrb r0, [r5, #0x11]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D56A8 @ =0x08370D28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D565C:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080D569C
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r6, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080D56AC @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080D569C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D56A4: .4byte 0xFFFFE200
_080D56A8: .4byte sCollisions_08370C68+(24*8)
_080D56AC: .4byte gSolidFnTable

	thumb_func_start ActorLastLeviathan_Update
ActorLastLeviathan_Update: @ 0x080D56B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xd
	bls _080D56BE
	b _080D59CC
_080D56BE:
	lsls r0, r0, #2
	ldr r1, _080D56C8 @ =_080D56CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D56C8: .4byte _080D56CC
_080D56CC: @ jump table
	.4byte _080D5704 @ case 0
	.4byte _080D5720 @ case 1
	.4byte _080D5770 @ case 2
	.4byte _080D57C0 @ case 3
	.4byte _080D5810 @ case 4
	.4byte _080D5838 @ case 5
	.4byte _080D5860 @ case 6
	.4byte _080D58A4 @ case 7
	.4byte _080D58CA @ case 8
	.4byte _080D5904 @ case 9
	.4byte _080D5944 @ case 10
	.4byte _080D5974 @ case 11
	.4byte _080D59A4 @ case 12
	.4byte _080D59C6 @ case 13
_080D5704:
	ldr r0, _080D5760 @ =wDynamicGraphicTilenums
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5764 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #7
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5720:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #8
	ldr r3, _080D5768 @ =0x08370E10
	movs r1, #1
	mov r2, sp
	bl AppendHazard
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D5750
	b _080D59CC
_080D5750:
	ldr r1, _080D576C @ =0x0000BD05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5760: .4byte wDynamicGraphicTilenums
_080D5764: .4byte wDynamicMotionPalIDs
_080D5768: .4byte Rect_08370e10
_080D576C: .4byte 0x0000BD05
_080D5770:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D5786
	b _080D59CC
_080D5786:
	ldr r1, _080D57B8 @ =0x0000BD09
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D57BC @ =0x08370D70
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D57B8: .4byte 0x0000BD09
_080D57BC: .4byte sCollisions_08370C68+(24*11)
_080D57C0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D57D6
	b _080D59CC
_080D57D6:
	ldr r1, _080D5808 @ =0x0000BD0B
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D580C @ =0x08370D88
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5808: .4byte 0x0000BD0B
_080D580C: .4byte sCollisions_08370C68+(24*12)
_080D5810:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D5824
	b _080D59CC
_080D5824:
	ldr r1, _080D5834 @ =0x0000BD0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5834: .4byte 0x0000BD0C
_080D5838:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D584E
	b _080D59CC
_080D584E:
	ldr r1, _080D585C @ =0x0000BD14
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D585C: .4byte 0x0000BD14
_080D5860:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	beq _080D5876
	b _080D59CC
_080D5876:
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58A0 @ =0x08370DA0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _080D59BE
	.align 2, 0
_080D58A0: .4byte sCollisions_08370C68+(24*13)
_080D58A4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58F8 @ =0x08370DB8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D58CA:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D59CC
	ldr r1, _080D58FC @ =0x0000BD10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf6
	bl PlaySound
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	ldr r0, _080D5900 @ =0xFFFFFEC0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D58F8: .4byte sCollisions_08370C68+(24*14)
_080D58FC: .4byte 0x0000BD10
_080D5900: .4byte 0xFFFFFEC0
_080D5904:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, [r6, #0x60]
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r2, #0x40
	str r2, [r6, #0x60]
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	beq _080D59CC
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D5940 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D5940: .4byte 0xFFFFEC00
_080D5944:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D59CC
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r6, #0x12]
	b _080D59BE
_080D5974:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D59CC
	ldr r1, _080D59A0 @ =0x0000BD0F
	adds r0, r6, #0
	bl SetMotion
	b _080D59BE
	.align 2, 0
_080D59A0: .4byte 0x0000BD0F
_080D59A4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #3
	bgt _080D59CC
_080D59BE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D59CC
_080D59C6:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D59CC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ActorLastX_Update
ActorLastX_Update: @ 0x080D59D4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D5A78
	cmp r7, #1
	bgt _080D59E8
	cmp r7, #0
	beq _080D59EE
	b _080D5AE8
_080D59E8:
	cmp r7, #2
	beq _080D5AB4
	b _080D5AE8
_080D59EE:
	movs r4, #0xfd
	ldr r1, _080D5AA0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D5AA4 @ =0x000002B7
	strh r0, [r1]
	ldr r5, _080D5AA8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #0xa
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xfd
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D5AAC @ =gStaticMotionGraphics
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
	ldr r0, _080D5AB0 @ =gStaticMotionGraphics+12
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
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	movs r1, #0xfd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	str r7, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	movs r2, #0
	movs r3, #0x10
_080D5A56:
	ldr r0, [r6, #0x60]
	adds r0, r0, r3
	str r0, [r6, #0x60]
	ldr r1, [r6, #0x58]
	subs r1, r1, r0
	str r1, [r6, #0x58]
	lsls r0, r2, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x5f
	ble _080D5A56
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5A78:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r2, r0, r1
	str r2, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x60]
	cmp r1, #0
	bne _080D5AE8
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	str r2, [r6, #0x68]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D5AE8
	.align 2, 0
_080D5AA0: .4byte wStaticGraphicTilenums
_080D5AA4: .4byte 0x000002B7
_080D5AA8: .4byte wStaticMotionPalIDs
_080D5AAC: .4byte gStaticMotionGraphics
_080D5AB0: .4byte gStaticMotionGraphics+12
_080D5AB4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D5AF0 @ =gSineTable
	adds r0, #0x81
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_080D5AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5AF0: .4byte gSineTable

	thumb_func_start Actor47_Update
Actor47_Update: @ 0x080D5AF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5B32
	cmp r0, #1
	bgt _080D5B08
	cmp r0, #0
	beq _080D5B0E
	b _080D5C08
_080D5B08:
	cmp r0, #2
	beq _080D5BE8
	b _080D5C08
_080D5B0E:
	ldr r0, _080D5B60 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb6
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r0, _080D5B64 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldr r1, _080D5B68 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5B32:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5B78
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5B6C @ =0x0000C502
	cmp r0, r1
	bne _080D5B70
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5B78
	.align 2, 0
_080D5B60: .4byte wDynamicGraphicTilenums
_080D5B64: .4byte wDynamicMotionPalIDs
_080D5B68: .4byte 0x0000C501
_080D5B6C: .4byte 0x0000C502
_080D5B70:
	ldr r1, _080D5BE0 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5B78:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5BA8
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE0 @ =0x0000C501
	cmp r0, r1
	bne _080D5B9C
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5B9C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5BBE
_080D5BA8:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE4 @ =0x0000C503
	cmp r0, r1
	bne _080D5BBE
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5BBE:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D5C08
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D5BE0 @ =0x0000C501
	cmp r1, r0
	beq _080D5C02
	adds r0, #2
	cmp r1, r0
	bne _080D5C08
	b _080D5C02
	.align 2, 0
_080D5BE0: .4byte 0x0000C501
_080D5BE4: .4byte 0x0000C503
_080D5BE8:
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
	beq _080D5C08
_080D5C02:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5C08:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
