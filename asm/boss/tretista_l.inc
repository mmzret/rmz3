	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804fc70
tretista_0804fc70: @ 0x0804FC70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804FC80
	cmp r5, #1
	beq _0804FD1C
	b _0804FDF0
_0804FC80:
	movs r0, #0xdc
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xe1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0804FC98
	ldr r1, _0804FCC4 @ =0x0000AB24
	adds r0, r4, #0
	bl SetMotion
_0804FC98:
	ldr r0, _0804FCC8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0804FCD0
	ldr r0, _0804FCCC @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804FCF2
	.align 2, 0
_0804FCC4: .4byte 0x0000AB24
_0804FCC8: .4byte pZero2
_0804FCCC: .4byte 0xFFFFFE00
_0804FCD0:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804FCF2:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x49
	bl RemovePaletteAnimation
	movs r0, #0x4a
	bl RemovePaletteAnimation
	movs r0, #0x4b
	bl RemovePaletteAnimation
	movs r0, #0x4c
	bl RemovePaletteAnimation
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804FD1C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804FD3E
	str r1, [r4, #0x60]
_0804FD3E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0804FD6C
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r3, _0804FDD0 @ =0xFFFFF800
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FD6C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804FD6C:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804FD8E
	ldr r0, [r4, #0x54]
	ldr r1, _0804FDD4 @ =0xFFFFD200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _0804FDD0 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FD8E
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804FD8E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804FDA2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804FDA2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804FDB2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804FDF0
_0804FDB2:
	adds r0, r4, #0
	adds r0, #0xe1
	ldrb r1, [r0]
	cmp r1, #7
	bne _0804FDE4
	adds r0, #1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804FDE4
	cmp r0, #7
	bhi _0804FDD8
	strb r1, [r4, #0xd]
	movs r0, #6
	strb r0, [r4, #0xe]
	b _0804FDF0
	.align 2, 0
_0804FDD0: .4byte 0xFFFFF800
_0804FDD4: .4byte 0xFFFFD200
_0804FDD8:
	cmp r0, #9
	bhi _0804FDE4
	strb r1, [r4, #0xd]
	movs r0, #8
	strb r0, [r4, #0xe]
	b _0804FDF0
_0804FDE4:
	movs r0, #0
	movs r1, #3
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_0804FDF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804fdf8
FUN_0804fdf8:
	.byte 0x10, 0xB5, 0x03, 0x1C, 0xD8, 0x68, 0x42, 0x68
	.byte 0x10, 0x79, 0x03, 0x28, 0x03, 0xD0, 0x0E, 0x28, 0x01, 0xD0, 0x0F, 0x28, 0x20, 0xD1, 0xDA, 0x6A
	.byte 0xD8, 0x68, 0xC4, 0x6A, 0x10, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0x80, 0x21, 0x89, 0x00, 0x08, 0x40
	.byte 0x00, 0x28, 0x05, 0xD1, 0x10, 0x1C, 0xA4, 0x30, 0x00, 0x21, 0x40, 0x5E, 0x00, 0x28, 0x0F, 0xD1
	.byte 0x05, 0x48, 0x01, 0x89, 0x08, 0x20, 0x08, 0x40, 0x00, 0x28, 0x09, 0xD1, 0xE0, 0x6D, 0x00, 0x28
	.byte 0x04, 0xDA, 0xFF, 0x20, 0x03, 0xE0, 0x00, 0x00, 0x60, 0xFE, 0x02, 0x02, 0xFE, 0x20, 0x50, 0x74
	.byte 0xDA, 0x6A, 0xD8, 0x68, 0x40, 0x68, 0x40, 0x78, 0x02, 0x28, 0x0C, 0xD1, 0x59, 0x68, 0x08, 0x78
	.byte 0x02, 0x28, 0x08, 0xD0, 0xC9, 0x68, 0x01, 0x20, 0x40, 0x42, 0x81, 0x42, 0x03, 0xD0, 0x11, 0x1C
	.byte 0xB7, 0x31, 0x01, 0x20, 0x08, 0x70, 0xD8, 0x68, 0x42, 0x68, 0x59, 0x68, 0x08, 0x78, 0x02, 0x28
	.byte 0x1F, 0xD0, 0xC9, 0x68, 0x01, 0x20, 0x40, 0x42, 0x81, 0x42, 0x1A, 0xD0, 0x50, 0x68, 0x0E, 0x49
	.byte 0x08, 0x40, 0xFD, 0x39, 0x88, 0x42, 0x14, 0xD1, 0xDA, 0x6A, 0x53, 0x7B, 0x18, 0x1C, 0x0A, 0x28
	.byte 0x0F, 0xD0, 0x06, 0x28, 0x0D, 0xD0, 0x09, 0x28, 0x0B, 0xD0, 0x07, 0x28, 0x02, 0xD1, 0x90, 0x7B
	.byte 0x09, 0x28, 0x06, 0xD8, 0x10, 0x1C, 0xE1, 0x30, 0x00, 0x21, 0x03, 0x70, 0x0A, 0x20, 0x50, 0x73
	.byte 0x91, 0x73, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xFF, 0x00, 0x02, 0x00

	thumb_func_start tretista_0804fecc
tretista_0804fecc: @ 0x0804FECC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804FF06
	movs r2, #0
	ldr r5, _0804FEEC @ =u16_ARRAY_080fef2c
	adds r3, r5, #0
_0804FEDA:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804FEF0
	adds r3, #2
	adds r2, #1
	cmp r2, #5
	ble _0804FEDA
	b _0804FF1A
	.align 2, 0
_0804FEEC: .4byte u16_ARRAY_080fef2c
_0804FEF0:
	adds r0, r2, #1
	movs r1, #6
	b _0804FEFA
_0804FEF6:
	adds r0, r2, #1
	movs r1, #5
_0804FEFA:
	bl __modsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804FF1A
_0804FF06:
	movs r2, #0
	ldr r5, _0804FF20 @ =u16_ARRAY_080fef2c
	adds r3, r5, #0
_0804FF0C:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804FEF6
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804FF0C
_0804FF1A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804FF20: .4byte u16_ARRAY_080fef2c

	thumb_func_start isTretistaFarAway
isTretistaFarAway: @ 0x0804FF24
	push {lr}
	ldr r1, _0804FF3C @ =pZero2
	ldr r1, [r1]
	ldr r3, [r1, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0804FF44
	ldr r0, _0804FF40 @ =0x000086FF
	cmp r2, r0
	ble _0804FF4C
	b _0804FF54
	.align 2, 0
_0804FF3C: .4byte pZero2
_0804FF40: .4byte 0x000086FF
_0804FF44:
	subs r1, r1, r3
	ldr r0, _0804FF50 @ =0x000086FF
	cmp r1, r0
	bgt _0804FF54
_0804FF4C:
	movs r0, #0
	b _0804FF56
	.align 2, 0
_0804FF50: .4byte 0x000086FF
_0804FF54:
	movs r0, #1
_0804FF56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ff5c
FUN_0804ff5c: @ 0x0804FF5C
	push {r4, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r4, _0804FFA0 @ =0x0000AB0B
	cmp r1, r4
	bne _0804FFAC
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFA4 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804FFA8 @ =0x00010300
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFA0: .4byte 0x0000AB0B
_0804FFA4: .4byte 0x00FFFF00
_0804FFA8: .4byte 0x00010300
_0804FFAC:
	ldr r3, _0804FFE4 @ =0x0000AB05
	cmp r1, r3
	bne _08050034
	ldr r0, [r2, #0x70]
	ldr r1, _0804FFE8 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _08050008
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804FFEC
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _08050006
	.align 2, 0
_0804FFE4: .4byte 0x0000AB05
_0804FFE8: .4byte 0x00FFFF00
_0804FFEC:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_08050006:
	strb r0, [r2, #0xa]
_08050008:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050024
	ldr r1, _08050020 @ =0x0000AB09
	b _08050026
	.align 2, 0
_08050020: .4byte 0x0000AB09
_08050024:
	ldr r1, _08050030 @ =0x0000AB03
_08050026:
	adds r0, r2, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050030: .4byte 0x0000AB03
_08050034:
	ldr r0, _08050060 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _08050064
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08050078
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _0805008A
	.align 2, 0
_08050060: .4byte pZero2
_08050064:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805008A
	adds r0, r2, #0
	adds r0, #0xd8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050082
_08050078:
	adds r0, r2, #0
	adds r1, r4, #0
	bl SetMotion
	b _0805008A
_08050082:
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_0805008A:
	pop {r4}
	pop {r0}
	bx r0
