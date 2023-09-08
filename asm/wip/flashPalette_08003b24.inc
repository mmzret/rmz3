	push {r4, lr}
	sub sp, #0x28
	ldr r4, _08003B60 @ =gPaletteManager
	ldr r0, _08003B64 @ =0x001F001F
	str r0, [sp]
	ldr r0, _08003B68 @ =0x03E003E0
	str r0, [sp, #4]
	ldr r0, _08003B6C @ =0x7C007C00
	str r0, [sp, #8]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r3, r4, r0
	ldr r1, _08003B70 @ =0x00000401
	adds r0, r4, r1
	ldrb r1, [r3]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08003BB2
	cmp r1, #0x20
	bne _08003B7C
	ldr r1, _08003B74 @ =0x040000D4
	str r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08003B78 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08003C32
	.align 2, 0
_08003B60: .4byte gPaletteManager
_08003B64: .4byte 0x001F001F
_08003B68: .4byte 0x03E003E0
_08003B6C: .4byte 0x7C007C00
_08003B70: .4byte 0x00000401
_08003B74: .4byte 0x040000D4
_08003B78: .4byte 0x84000100
_08003B7C:
	cmp r1, #0x1f
	bhi _08003B90
	movs r1, #0xa0
	lsls r1, r1, #0x13
	ldrb r2, [r3]
	adds r0, r4, #0
	mov r3, sp
	bl gfx_08003cf0
	b _08003C32
_08003B90:
	add r2, sp, #0xc
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [sp, #0xc]
	ldrb r0, [r3]
	subs r0, #0x21
	lsls r1, r0, #0x10
	orrs r0, r1
	str r0, [r2, #4]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	mov r3, sp
	bl gfx_08003d34
	b _08003C32
_08003BB2:
	cmp r1, #0x20
	bhi _08003BC4
	add r0, sp, #0xc
	ldrb r1, [r3]
	str r1, [sp, #0xc]
	movs r1, #0
	str r1, [r0, #0xc]
	adds r2, r0, #0
	b _08003BD8
_08003BC4:
	add r2, sp, #0xc
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [sp, #0xc]
	ldrb r0, [r3]
	subs r0, #0x21
	lsls r1, r0, #0x10
	orrs r0, r1
	str r0, [r2, #0xc]
_08003BD8:
	ldr r0, _08003BE8 @ =0x00000401
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0x20
	bhi _08003BEC
	str r0, [r2, #4]
	movs r0, #0
	b _08003BFC
	.align 2, 0
_08003BE8: .4byte 0x00000401
_08003BEC:
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r2, #4]
	ldrb r0, [r3]
	subs r0, #0x21
	lsls r1, r0, #0x10
	orrs r0, r1
_08003BFC:
	str r0, [r2, #0x10]
	ldr r1, _08003C10 @ =0x00000402
	adds r3, r4, r1
	ldrb r0, [r3]
	cmp r0, #0x20
	bhi _08003C14
	str r0, [r2, #8]
	movs r0, #0
	b _08003C24
	.align 2, 0
_08003C10: .4byte 0x00000402
_08003C14:
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r2, #8]
	ldrb r0, [r3]
	subs r0, #0x21
	lsls r1, r0, #0x10
	orrs r0, r1
_08003C24:
	str r0, [r2, #0x14]
	ldr r0, _08003C84 @ =gPaletteManager
	movs r1, #0xa0
	lsls r1, r1, #0x13
	mov r3, sp
	bl flashPalette_08003d84
_08003C32:
	ldr r4, _08003C84 @ =gPaletteManager
	ldr r2, _08003C88 @ =0x00000406
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _08003C6A
	add r1, sp, #0x24
	ldr r2, _08003C8C @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, _08003C90 @ =0x040000D4
	str r1, [r2]
	ldr r1, _08003C94 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [r2, #4]
	ldrh r0, [r3]
	lsrs r0, r0, #1
	movs r1, #0x81
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	strh r0, [r3]
_08003C6A:
	movs r2, #0x81
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08003C7A
	bl _call_via_r0
_08003C7A:
	add sp, #0x28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003C84: .4byte gPaletteManager
_08003C88: .4byte 0x00000406
_08003C8C: .4byte 0x0000FFFF
_08003C90: .4byte 0x040000D4
_08003C94: .4byte 0x00000404
