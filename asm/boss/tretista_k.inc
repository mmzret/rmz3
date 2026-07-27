	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretistaLaserCraw
tretistaLaserCraw: @ 0x0804F7DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x25
	bls _0804F7E8
	b _0804FC5E
_0804F7E8:
	lsls r0, r0, #2
	ldr r1, _0804F7F4 @ =_0804F7F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F7F4: .4byte _0804F7F8
_0804F7F8: @ jump table
	.4byte _0804F890 @ case 0
	.4byte _0804F8C0 @ case 1
	.4byte _0804F8E4 @ case 2
	.4byte _0804F900 @ case 3
	.4byte _0804F96C @ case 4
	.4byte _0804F9AC @ case 5
	.4byte _0804FC5E @ case 6
	.4byte _0804FC5E @ case 7
	.4byte _0804FC5E @ case 8
	.4byte _0804FC5E @ case 9
	.4byte _0804F9E8 @ case 10
	.4byte _0804FA1A @ case 11
	.4byte _0804FA40 @ case 12
	.4byte _0804FC5E @ case 13
	.4byte _0804FC5E @ case 14
	.4byte _0804FC5E @ case 15
	.4byte _0804FC5E @ case 16
	.4byte _0804FC5E @ case 17
	.4byte _0804FC5E @ case 18
	.4byte _0804FC5E @ case 19
	.4byte _0804FC5E @ case 20
	.4byte _0804FC5E @ case 21
	.4byte _0804FC5E @ case 22
	.4byte _0804FC5E @ case 23
	.4byte _0804FC5E @ case 24
	.4byte _0804FC5E @ case 25
	.4byte _0804FC5E @ case 26
	.4byte _0804FC5E @ case 27
	.4byte _0804FC5E @ case 28
	.4byte _0804FC5E @ case 29
	.4byte _0804FA44 @ case 30
	.4byte _0804FA60 @ case 31
	.4byte _0804FA94 @ case 32
	.4byte _0804FAC8 @ case 33
	.4byte _0804FB16 @ case 34
	.4byte _0804FB6A @ case 35
	.4byte _0804FBF4 @ case 36
	.4byte _0804FC2C @ case 37
_0804F890:
	ldr r1, _0804F8D8 @ =0x0000AB11
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F8DC @ =sCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	movs r0, #0x34
	strb r0, [r5, #0x12]
	str r1, [r5, #0x5c]
	ldr r0, _0804F8E0 @ =0x0001A680
	movs r1, #0x34
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x33
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F8C0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F8D2
	b _0804FC5E
_0804F8D2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804F8D8: .4byte 0x0000AB11
_0804F8DC: .4byte sCollisions+(24*1)
_0804F8E0: .4byte 0x0001A680
_0804F8E4:
	ldr r1, _0804F960 @ =0x0000AB0D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F964 @ =0x08363410
	bl SetDDP
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F900:
	ldr r2, [r5, #0x60]
	adds r2, #0x50
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r5, #0x58]
	cmp r2, #0
	ble _0804F942
	ldrb r6, [r5, #0x13]
	cmp r6, #0
	bne _0804F942
	movs r4, #1
	strb r4, [r5, #0x13]
	ldr r1, _0804F968 @ =0x0000AB12
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	ands r2, r4
	adds r0, r5, #0
	bl tretista_080a36f4
	adds r1, r5, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r6, [r5, #0xf]
_0804F942:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F95A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F95A
	b _0804FC5E
_0804F95A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804F960: .4byte 0x0000AB0D
_0804F964: .4byte 0x08363410
_0804F968: .4byte 0x0000AB12
_0804F96C:
	ldr r1, _0804F9DC @ =0x0000AB12
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0804F9E0 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804F9E4 @ =sCollisions+(24*1)
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	bl PlaySound
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804F9AC:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F9BE
	b _0804FC5E
_0804F9BE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804F9D0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F9D0
	b _0804FC5E
_0804F9D0:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	beq _0804F9D8
	b _0804FC5E
_0804F9D8:
	movs r0, #0xa
	b _0804FC5C
	.align 2, 0
_0804F9DC: .4byte 0x0000AB12
_0804F9E0: .4byte 0xFFFFF000
_0804F9E4: .4byte sCollisions+(24*1)
_0804F9E8:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #8
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
	ldr r1, _0804FA38 @ =0x0000AB13
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FA3C @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x5a
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FA1A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FA32
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804FA32
	b _0804FC5E
_0804FA32:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FA38: .4byte 0x0000AB13
_0804FA3C: .4byte sCollisions+(24*1)
_0804FA40:
	movs r0, #0x1e
	b _0804FC5C
_0804FA44:
	ldr r1, _0804FA8C @ =0x0000AB20
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FA90 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FA60:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804FA72
	b _0804FC5E
_0804FA72:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FA84
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804FA84
	b _0804FC5E
_0804FA84:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FA8C: .4byte 0x0000AB20
_0804FA90: .4byte sCollisions+(24*1)
_0804FA94:
	adds r1, r5, #0
	adds r1, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl FUN_080a374c
	adds r1, r5, #0
	adds r1, #0xc0
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x49
	bl StartPaletteAnimation
	movs r0, #0xdb
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0x12]
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FAC8:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0804FAE8
	ldrb r0, [r5, #0x12]
	cmp r0, #0x14
	bls _0804FAE8
	movs r0, #1
	strb r0, [r5, #0x13]
	movs r0, #0x49
	bl RemovePaletteAnimation
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4a
	bl StartPaletteAnimation
_0804FAE8:
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _0804FAF6
	movs r0, #0x4a
	bl StepPaletteAnimation
	b _0804FAFC
_0804FAF6:
	movs r0, #0x49
	bl StepPaletteAnimation
_0804FAFC:
	ldrb r0, [r5, #0x12]
	cmp r0, #0x1e
	bhi _0804FB10
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _0804FB10
	b _0804FC5E
_0804FB10:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
_0804FB16:
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0804FB48 @ =0x0000AB22
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FB4C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FB54
	ldr r0, _0804FB50 @ =0xFFFFFD00
	b _0804FB58
	.align 2, 0
_0804FB48: .4byte 0x0000AB22
_0804FB4C: .4byte sCollisions+(24*1)
_0804FB50: .4byte 0xFFFFFD00
_0804FB54:
	movs r0, #0xc0
	lsls r0, r0, #2
_0804FB58:
	str r0, [r5, #0x5c]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r5, #0x60]
	movs r0, #0
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FB6A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	bge _0804FB78
	rsbs r1, r1, #0
_0804FB78:
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	movs r0, #0x4a
	bl StepPaletteAnimation
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _0804FB9A
	ldr r0, [r5, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	b _0804FBA6
_0804FB9A:
	ldr r0, [r5, #0x54]
	ldr r2, _0804FBF0 @ =0xFFFFD200
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
_0804FBA6:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FBB2
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_0804FBB2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	asrs r0, r0, #1
	ldr r1, [r5, #0x64]
	cmp r1, r0
	ble _0804FBDA
	adds r3, r5, #0
	adds r3, #0xc4
	ldr r2, [r3]
	cmp r2, #0
	beq _0804FBDA
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	str r0, [r3]
_0804FBDA:
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x60]
	cmp r1, r0
	ble _0804FC5E
	movs r0, #0x4a
	bl RemovePaletteAnimation
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0804FC5C
	.align 2, 0
_0804FBF0: .4byte 0xFFFFD200
_0804FBF4:
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r0, #0x4b
	bl StartPaletteAnimation
	ldr r1, _0804FC64 @ =0x0000AB23
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804FC68 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804FC2C:
	movs r0, #0x4b
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r4, [r0]
	cmp r4, #3
	bne _0804FC5E
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804FC52
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804FC5E
_0804FC52:
	movs r0, #0x4b
	bl RemovePaletteAnimation
	movs r0, #0
	strb r4, [r5, #0xd]
_0804FC5C:
	strb r0, [r5, #0xe]
_0804FC5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC64: .4byte 0x0000AB23
_0804FC68: .4byte sCollisions+(24*1)
