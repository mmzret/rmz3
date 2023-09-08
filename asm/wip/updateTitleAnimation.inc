	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #6]
	cmp r6, #0
	beq _080EBFDC
	cmp r6, #1
	beq _080EC028
	b _080EC0F8
_080EBFDC:
	movs r0, #0xbf
	bl playBGM
	ldr r0, _080EC04C @ =gIntro
	str r6, [r0, #0xc]
	ldr r2, _080EC050 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EC054 @ =0x0000F0FF
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	ldr r1, _080EC058 @ =gBlendRegBuffer
	movs r0, #0x92
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r1, #2]
	adds r0, r5, #0
	bl FUN_080ed07c
	adds r0, r5, #0
	bl intro_080ed1d4
	adds r0, r5, #0
	bl FUN_080ed6c4
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080EC05C @ =0x00000235
	adds r0, r5, r2
	strb r4, [r0]
	strh r6, [r5, #8]
	ldrb r0, [r5, #6]
	adds r0, #1
	strb r0, [r5, #6]
_080EC028:
	adds r0, r5, #0
	bl intro_080ed108
	movs r3, #8
	ldrsh r0, [r5, r3]
	movs r1, #0x8e
	lsls r1, r1, #1
	cmp r0, r1
	bgt _080EC07E
	cmp r0, r1
	bne _080EC064
	ldr r2, _080EC050 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _080EC060 @ =0x0000C7FF
	ands r0, r1
	strh r0, [r2]
	b _080EC07E
	.align 2, 0
_080EC04C: .4byte gIntro
_080EC050: .4byte gVideoRegBuffer
_080EC054: .4byte 0x0000F0FF
_080EC058: .4byte gBlendRegBuffer
_080EC05C: .4byte 0x00000235
_080EC060: .4byte 0x0000C7FF
_080EC064:
	cmp r0, #0xb7
	ble _080EC072
	adds r0, r5, #0
	movs r1, #0
	bl intro_080ed770
	b _080EC07E
_080EC072:
	cmp r0, #0x53
	ble _080EC07E
	adds r0, r5, #0
	movs r1, #1
	bl intro_080ed770
_080EC07E:
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, _080EC098 @ =0x0000012B
	cmp r1, r0
	bgt _080EC0C4
	cmp r1, #0xef
	ble _080EC09C
	adds r0, r5, #0
	movs r1, #3
	bl intro_080ed480
	b _080EC0C4
	.align 2, 0
_080EC098: .4byte 0x0000012B
_080EC09C:
	cmp r1, #0xc7
	ble _080EC0AA
	adds r0, r5, #0
	movs r1, #2
	bl intro_080ed480
	b _080EC0C4
_080EC0AA:
	cmp r1, #0x8b
	ble _080EC0B8
	adds r0, r5, #0
	movs r1, #1
	bl intro_080ed480
	b _080EC0C4
_080EC0B8:
	cmp r1, #0x63
	ble _080EC0C4
	adds r0, r5, #0
	movs r1, #0
	bl intro_080ed480
_080EC0C4:
	movs r2, #8
	ldrsh r1, [r5, r2]
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	ble _080EC0D6
	adds r0, r5, #0
	bl intro_080ed2a0
_080EC0D6:
	movs r3, #8
	ldrsh r1, [r5, r3]
	movs r0, #0xcf
	lsls r0, r0, #1
	cmp r1, r0
	ble _080EC0F8
	ldr r2, _080EC118 @ =gVideoRegBuffer
	ldrh r1, [r2]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #2
	bl intro_080ed770
_080EC0F8:
	ldr r1, _080EC11C @ =0x00000235
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _080EC128
	subs r1, #1
	strb r1, [r0]
	ldr r2, _080EC120 @ =gPaletteManager
	movs r0, #0x40
	subs r0, r0, r1
	ldr r3, _080EC124 @ =0x00000402
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	b _080EC144
	.align 2, 0
_080EC118: .4byte gVideoRegBuffer
_080EC11C: .4byte 0x00000235
_080EC120: .4byte gPaletteManager
_080EC124: .4byte 0x00000402
_080EC128:
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _080EC152
	adds r0, #1
	strb r0, [r1]
	ldr r2, _080EC16C @ =gPaletteManager
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	ldr r3, _080EC170 @ =0x00000402
	adds r1, r2, r3
	strb r0, [r1]
_080EC144:
	subs r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r2, r1
	strb r0, [r2]
_080EC152:
	ldrh r0, [r5, #8]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	ldr r1, _080EC174 @ =0x01AD0000
	cmp r0, r1
	ble _080EC17C
	ldr r0, _080EC178 @ =0x0000014D
	bl PlaySound
	b _080EC19E
	.align 2, 0
_080EC16C: .4byte gPaletteManager
_080EC170: .4byte 0x00000402
_080EC174: .4byte 0x01AD0000
_080EC178: .4byte 0x0000014D
_080EC17C:
	ldr r1, _080EC1C4 @ =0x00000236
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EC192
	ldr r0, _080EC1C8 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _080EC1BC
_080EC192:
	ldr r0, _080EC1CC @ =0x0000014D
	bl PlaySound
	movs r0, #0xbf
	bl fadeoutBGM
_080EC19E:
	ldr r1, _080EC1D0 @ =gPaletteManager
	ldr r2, _080EC1D4 @ =0x00000402
	adds r0, r1, r2
	movs r2, #0x40
	strb r2, [r0]
	ldr r3, _080EC1D8 @ =0x00000401
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	strb r2, [r1]
	strb r4, [r5, #6]
	movs r0, #2
	strb r0, [r5, #5]
_080EC1BC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EC1C4: .4byte 0x00000236
_080EC1C8: .4byte gJoypad
_080EC1CC: .4byte 0x0000014D
_080EC1D0: .4byte gPaletteManager
_080EC1D4: .4byte 0x00000402
_080EC1D8: .4byte 0x00000401
