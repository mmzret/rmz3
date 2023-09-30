	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080866a4
FUN_080866a4: @ 0x080866A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08086700 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _08086738
	mov r1, ip
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08086704 @ =gEnemyFnTable
	movs r1, #0x2d
	mov r3, ip
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	mov r1, ip
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r3, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	str r5, [r3, #0x28]
	adds r2, r4, #0
	cmp r2, #0
	beq _08086708
	ldrb r0, [r3, #0xa]
	orrs r0, r1
	strb r0, [r3, #0xa]
	b _08086714
	.align 2, 0
_08086700: .4byte gZakoHeaderPtr
_08086704: .4byte gEnemyFnTable
_08086708:
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r0, #0xef
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
_08086714:
	movs r1, #1
	ands r1, r2
	mov r0, ip
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	mov r4, ip
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r2, ip
	strb r6, [r2, #0x10]
	strb r3, [r2, #0x11]
_08086738:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start HanumachineObj_Init
HanumachineObj_Init:
	.byte 0xF0, 0xB5, 0x06, 0x1C, 0xB7, 0x6A, 0x19, 0x49, 0x70, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x01, 0x21
	.byte 0xF1, 0x60, 0x00, 0x68, 0x40, 0x68, 0x70, 0x61, 0x30, 0x1C, 0x90, 0xF7, 0xAF, 0xFE, 0xB1, 0x7A
	.byte 0x01, 0x20, 0x00, 0x25, 0x08, 0x43, 0x02, 0x21, 0x08, 0x43, 0xB0, 0x72, 0x10, 0x49, 0x30, 0x1C
	.byte 0x90, 0xF7, 0xFA, 0xFE, 0xB1, 0x7A, 0x04, 0x20, 0x08, 0x43, 0xB0, 0x72, 0x34, 0x1C, 0x74, 0x34
	.byte 0x0C, 0x49, 0x32, 0x1C, 0x54, 0x32, 0x20, 0x1C, 0x08, 0x23, 0x80, 0xF7, 0x31, 0xFD, 0xE6, 0x62
	.byte 0x65, 0x62, 0xB1, 0x7A, 0x10, 0x20, 0x08, 0x40, 0x00, 0x28, 0x0D, 0xD0, 0x78, 0x6D, 0xB0, 0x21
	.byte 0x49, 0x01, 0x40, 0x18, 0x70, 0x65, 0x80, 0x20, 0xC0, 0x00, 0x0A, 0xE0, 0x48, 0x59, 0x36, 0x08
	.byte 0x03, 0x6A, 0x00, 0x00, 0xE8, 0x85, 0x36, 0x08, 0x78, 0x6D, 0x0F, 0x49, 0x40, 0x18, 0x70, 0x65
	.byte 0x0E, 0x48, 0xF0, 0x65, 0xB8, 0x6D, 0x0E, 0x49, 0x40, 0x18, 0xB0, 0x65, 0x31, 0x1C, 0xC0, 0x31
	.byte 0x00, 0x22, 0x00, 0x23, 0x96, 0x20, 0x80, 0x00, 0x08, 0x80, 0x30, 0x1C, 0xBD, 0x30, 0x02, 0x70
	.byte 0x33, 0x66, 0x6D, 0x38, 0x40, 0x21, 0x01, 0x80, 0x02, 0x30, 0x01, 0x80, 0x30, 0x1C, 0x00, 0xF0
	.byte 0x09, 0xF8, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0xEA, 0xFF, 0xFF, 0x00, 0xFC, 0xFF, 0xFF
	.byte 0x00, 0xF1, 0xFF, 0xFF

	thumb_func_start HanumachineObj_Update
HanumachineObj_Update: @ 0x08086804
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xc0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0808685C
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08086844 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808684C
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08086848 @ =0x08368660
	bl SetDDP
	b _080868B4
	.align 2, 0
_08086844: .4byte 0xFFFFF800
_08086848: .4byte 0x08368660
_0808684C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08086858 @ =0x08368630
	bl SetDDP
	b _080868B4
	.align 2, 0
_08086858: .4byte 0x08368630
_0808685C:
	ldrb r0, [r5, #0xd]
	cmp r0, #7
	beq _0808687E
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	ldr r1, _08086888 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08086878
	movs r1, #0
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08086878:
	ldrb r0, [r5, #0xd]
	cmp r0, #7
	bne _0808688C
_0808687E:
	adds r0, r5, #0
	bl FUN_08086e34
	b _08086912
	.align 2, 0
_08086888: .4byte 0x00020001
_0808688C:
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080868D8
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, _080868D0 @ =0xFFFFF800
	adds r0, r0, r1
	add r4, sp, #8
	str r0, [r4, #4]
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
_080868B4:
	ldr r1, _080868D4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl HanumachineObj_Die
	b _08086912
	.align 2, 0
_080868D0: .4byte 0xFFFFF800
_080868D4: .4byte gEnemyFnTable
_080868D8:
	ldr r1, _08086908 @ =0x083685C8
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldrh r0, [r4]
	subs r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _08086912
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _0808690C
	adds r0, r5, #0
	bl PaintEntityWhite
	b _08086912
	.align 2, 0
_08086908: .4byte 0x083685C8
_0808690C:
	adds r0, r5, #0
	bl UpdateEntityPaletteID
_08086912:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start HanumachineObj_Die
HanumachineObj_Die: @ 0x0808691C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _08086938 @ =gEnemyFnTable
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
_08086938: .4byte gEnemyFnTable

	thumb_func_start FUN_0808693c
FUN_0808693c: @ 0x0808693C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _08086952
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #3
	adds r0, #2
	strb r0, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0xe]
_08086952:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	ldr r1, _0808699C @ =0xFFFFF600
	cmp r0, #0
	beq _08086970
	movs r1, #0xa0
	lsls r1, r1, #4
_08086970:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0808698C
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086994
_0808698C:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08086994:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808699C: .4byte 0xFFFFF600

	thumb_func_start FUN_080869a0
FUN_080869a0: @ 0x080869A0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _080869B2
	ldr r0, _080869F0 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r0, r1, #1
	strb r0, [r4, #0xe]
_080869B2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r1, r4, #0
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #0xff
	bhi _080869DA
	adds r0, #0x10
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_080869DA:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _080869E8
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080869E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080869F0: .4byte 0xFFFFFD00

	thumb_func_start FUN_080869f4
FUN_080869f4: @ 0x080869F4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08086A10
	ldr r1, _08086A30 @ =0x00006A02
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086A10:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #1
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08086A34
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08086A4A
	.align 2, 0
_08086A30: .4byte 0x00006A02
_08086A34:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08086A4A
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08086A4A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086a50
FUN_08086a50: @ 0x08086A50
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08086AC8
	ldr r1, _08086A80 @ =0x00006A03
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldr r0, _08086A84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08086A72
	movs r2, #1
_08086A72:
	cmp r2, #0
	beq _08086A88
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08086A8E
	.align 2, 0
_08086A80: .4byte 0x00006A03
_08086A84: .4byte pZero2
_08086A88:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08086A8E:
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
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08086ABA
	movs r0, #0xc0
	lsls r0, r0, #1
	b _08086ABC
_08086ABA:
	ldr r0, _08086AE4 @ =0xFFFFFE80
_08086ABC:
	str r0, [r4, #0x5c]
	ldr r0, _08086AE8 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086AC8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08086AEC
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _08086B64
	.align 2, 0
_08086AE4: .4byte 0xFFFFFE80
_08086AE8: .4byte 0xFFFFFD00
_08086AEC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086B34
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08086B16
	movs r0, #0x10
	orrs r0, r2
	b _08086B1A
_08086B16:
	movs r0, #0xef
	ands r0, r2
_08086B1A:
	strb r0, [r4, #0xa]
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
_08086B34:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086B64
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08086b6c
FUN_08086b6c:
	.byte 0x70, 0xB5, 0x05, 0x1C
	.byte 0xAC, 0x7B, 0x00, 0x2C, 0x30, 0xD1, 0x22, 0x49, 0x90, 0xF7, 0xF6, 0xFC, 0x2A, 0x1C, 0x49, 0x32
	.byte 0x11, 0x78, 0x0D, 0x20, 0x40, 0x42, 0x08, 0x40, 0x04, 0x21, 0x08, 0x43, 0x10, 0x70, 0xAC, 0x74
	.byte 0x6B, 0x32, 0x1C, 0x48, 0x03, 0x68, 0x68, 0x6D, 0x59, 0x6D, 0x40, 0x1A, 0x10, 0x60, 0x2C, 0x1C
	.byte 0xB8, 0x34, 0x19, 0x4A, 0x11, 0x68, 0x19, 0x48, 0x48, 0x43, 0x19, 0x49, 0x40, 0x18, 0x40, 0x00
	.byte 0x41, 0x08, 0x11, 0x60, 0x00, 0x01, 0x40, 0x0D, 0x16, 0x49, 0x09, 0x1A, 0x21, 0x60, 0x98, 0x7A
	.byte 0x00, 0x09, 0x01, 0x21, 0x08, 0x40, 0x29, 0x1C, 0xBC, 0x31, 0x08, 0x70, 0x04, 0x31, 0x3C, 0x20
	.byte 0x08, 0x80, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C, 0x90, 0xF7, 0x3F, 0xFD, 0x28, 0x1C
	.byte 0xBC, 0x30, 0x02, 0x78, 0x07, 0x48, 0x03, 0x68, 0x98, 0x7A, 0x00, 0x09, 0x01, 0x21, 0x08, 0x40
	.byte 0x82, 0x42, 0x11, 0xD1, 0x28, 0x1C, 0xB4, 0x30, 0x59, 0x6D, 0x00, 0x68, 0x09, 0x18, 0x10, 0xE0
	.byte 0x04, 0x6A, 0x00, 0x00, 0x40, 0xF3, 0x02, 0x02, 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00
	.byte 0xC3, 0x9E, 0x26, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0x28, 0x1C, 0xB4, 0x30, 0x59, 0x6D, 0x00, 0x68
	.byte 0x09, 0x1A, 0x69, 0x65, 0x0A, 0x4B, 0x1A, 0x68, 0x29, 0x1C, 0xB8, 0x31, 0x90, 0x6D, 0x09, 0x68
	.byte 0x40, 0x18, 0xA8, 0x65, 0x00, 0x24, 0x69, 0x6D, 0x50, 0x6D, 0x1E, 0x1C, 0x81, 0x42, 0x00, 0xDA
	.byte 0x01, 0x24, 0x22, 0x1C, 0x00, 0x2A, 0x05, 0xD0, 0xA9, 0x7A, 0x10, 0x20, 0x08, 0x43, 0x04, 0xE0
	.byte 0x40, 0xF3, 0x02, 0x02, 0xA9, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA8, 0x72, 0x11, 0x1C, 0x28, 0x1C
	.byte 0x4C, 0x30, 0x01, 0x70, 0x2B, 0x1C, 0x4A, 0x33, 0x09, 0x01, 0x1A, 0x78, 0x11, 0x20, 0x40, 0x42
	.byte 0x10, 0x40, 0x08, 0x43, 0x18, 0x70, 0x31, 0x68, 0x00, 0x29, 0x19, 0xD0, 0x08, 0x1C, 0x9E, 0xF7
	.byte 0xAD, 0xFE, 0xA9, 0x7C, 0x40, 0x18, 0xA8, 0x74, 0x00, 0x06, 0x00, 0x0E, 0x18, 0x28, 0x0E, 0xD8
	.byte 0x33, 0x68, 0x18, 0x1C, 0x8C, 0x30, 0x00, 0x68, 0x80, 0x21, 0x89, 0x00, 0x08, 0x40, 0x00, 0x28
	.byte 0x05, 0xD1, 0x18, 0x1C, 0xA4, 0x30, 0x00, 0x21, 0x40, 0x5E, 0x00, 0x28, 0x03, 0xD1, 0x00, 0x21
	.byte 0x05, 0x20, 0x68, 0x73, 0xA9, 0x73, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_08086cbc
FUN_08086cbc: @ 0x08086CBC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08086D40
	ldr r1, _08086CFC @ =0x00006A03
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08086D00 @ =0x08368618
	bl SetDDP
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08086D04
	movs r0, #0x10
	orrs r0, r2
	b _08086D08
	.align 2, 0
_08086CFC: .4byte 0x00006A03
_08086D00: .4byte 0x08368618
_08086D04:
	movs r0, #0xef
	ands r0, r2
_08086D08:
	strb r0, [r4, #0xa]
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
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08086D32
	movs r0, #0xc0
	lsls r0, r0, #1
	b _08086D34
_08086D32:
	ldr r0, _08086D70 @ =0xFFFFFE80
_08086D34:
	str r0, [r4, #0x5c]
	ldr r0, _08086D74 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086D40:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086D96
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08086D78
	movs r0, #0x10
	orrs r0, r2
	b _08086D7C
	.align 2, 0
_08086D70: .4byte 0xFFFFFE80
_08086D74: .4byte 0xFFFFFD00
_08086D78:
	movs r0, #0xef
	ands r0, r2
_08086D7C:
	strb r0, [r4, #0xa]
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
_08086D96:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	adds r2, #0x40
	str r2, [r4, #0x60]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086DC6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086DC6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086dcc
FUN_08086dcc: @ 0x08086DCC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08086DF4
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _08086E2C @ =0x00006A03
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08086E30 @ =0x08368600
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08086DF4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, #0x40
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086E24
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08086E24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086E2C: .4byte 0x00006A03
_08086E30: .4byte 0x08368600

	thumb_func_start FUN_08086e34
FUN_08086e34: @ 0x08086E34
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _08086F2E
	ldr r1, _08086EA4 @ =0x00006A03
	adds r0, r6, #0
	bl SetMotion
	ldr r4, _08086EA8 @ =pZero2
	ldr r2, [r4]
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x58]
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	ldr r2, _08086EAC @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r6, #0x60]
	asrs r1, r1, #8
	adds r5, r1, #0
	muls r5, r1, r5
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r5, r5, r0
	adds r0, r5, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08086EB0
	ldr r0, [r6, #0x5c]
	adds r1, r5, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r6, #0x5c]
	ldr r0, [r6, #0x60]
	adds r1, r5, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r6, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r6, #0x60]
	b _08086ECA
	.align 2, 0
_08086EA4: .4byte 0x00006A03
_08086EA8: .4byte pZero2
_08086EAC: .4byte 0xFFFFE800
_08086EB0:
	ldr r0, [r4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08086EC2
	movs r0, #0xc0
	lsls r0, r0, #3
	b _08086EC4
_08086EC2:
	ldr r0, _08086EF0 @ =0xFFFFFA00
_08086EC4:
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
_08086ECA:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _08086EF4
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
	b _08086F16
	.align 2, 0
_08086EF0: .4byte 0xFFFFFA00
_08086EF4:
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
_08086F16:
	adds r1, r6, #0
	adds r1, #0xbd
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08086F88 @ =0x08368648
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08086F2E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r4, [r6, #0x5c]
	adds r3, r0, r4
	str r3, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r2, r1, r0
	str r2, [r6, #0x58]
	adds r0, #0x40
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08086F7A
	adds r0, r3, r4
	adds r1, r2, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08086F7A
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r2, _08086F8C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08086F82
_08086F7A:
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0
	strh r0, [r1]
_08086F82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086F88: .4byte 0x08368648
_08086F8C: .4byte 0xFFFFF000
