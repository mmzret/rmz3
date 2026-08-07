	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyxMode5
copyxMode5: @ 0x08055B2C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08055BB0
	movs r1, #0xb3
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r3, #0
	ldr r0, _08055B88 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055B54
	movs r3, #1
_08055B54:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055B66
	movs r3, #1
_08055B66:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08055B8C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08055B92
	.align 2, 0
_08055B88: .4byte pZero2
_08055B8C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08055B92:
	strb r0, [r4, #0xa]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl CreateVFX52
	str r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08055BF4 @ =0x08363C78
	bl SetDDP
	movs r0, #0x45
	bl PlaySound
_08055BB0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08055C0E
	ldr r0, [r4, #0x2c]
	movs r1, #1
	strb r1, [r0, #0x11]
	movs r0, #0
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xf]
	adds r2, r4, #0
	adds r2, #0xc5
	strb r0, [r2]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	movs r1, #2
	strb r1, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x1f
	bgt _08055BF8
	movs r0, #8
	strb r0, [r4, #0x12]
	b _08055C04
	.align 2, 0
_08055BF4: .4byte 0x08363C78
_08055BF8:
	cmp r0, #0x2f
	bgt _08055C02
	movs r0, #4
	strb r0, [r4, #0x12]
	b _08055C04
_08055C02:
	strb r1, [r4, #0x12]
_08055C04:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08055C14 @ =sCollisions
	bl SetDDP
_08055C0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055C14: .4byte sCollisions

	thumb_func_start copyxMode6
copyxMode6: @ 0x08055C18
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08055C9C
	ldr r1, _08055C70 @ =0x0000B306
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _08055C74 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055C3A
	movs r3, #1
_08055C3A:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055C4C
	movs r3, #1
_08055C4C:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08055C78
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08055C7E
	.align 2, 0
_08055C70: .4byte 0x0000B306
_08055C74: .4byte pZero2
_08055C78:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08055C7E:
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08055C94
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _08055C96
_08055C94:
	movs r0, #0xc0
_08055C96:
	str r0, [r4, #0x5c]
	ldr r0, _08055CD8 @ =0xFFFFFC00
	str r0, [r4, #0x60]
_08055C9C:
	adds r0, r4, #0
	bl UpdateEntityAnim
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
	bl FUN_08009f6c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _08055CD0
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #7
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08055CD0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055CD8: .4byte 0xFFFFFC00

	thumb_func_start copyxMode7
copyxMode7: @ 0x08055CDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08055D90
	ldr r1, _08055D34 @ =0x0000B30F
	adds r0, r4, #0
	bl SetMotion
	movs r3, #0
	ldr r0, _08055D38 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055CFE
	movs r3, #1
_08055CFE:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08055D10
	movs r3, #1
_08055D10:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _08055D3C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08055D42
	.align 2, 0
_08055D34: .4byte 0x0000B30F
_08055D38: .4byte pZero2
_08055D3C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08055D42:
	strb r0, [r4, #0xa]
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08055D68
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r0, _08055D64 @ =0x0000FFF0
	strh r0, [r1]
	b _08055D72
	.align 2, 0
_08055D64: .4byte 0x0000FFF0
_08055D68:
	ldr r0, _08055DC8 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xc8
	strh r2, [r0]
_08055D72:
	movs r0, #0x28
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl CreateCopyXSonicBoom
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08055DCC @ =0x08363CD8
	bl SetDDP
	movs r0, #0x4c
	bl PlaySound
_08055D90:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc8
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	cmp r1, #0
	bge _08055DB0
	rsbs r1, r1, #0
_08055DB0:
	ldr r0, _08055DD0 @ =0x000002BF
	cmp r1, r0
	bgt _08055DD8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08055DD4
	movs r0, #0xb0
	lsls r0, r0, #2
	b _08055DD6
	.align 2, 0
_08055DC8: .4byte 0xFFFFFC00
_08055DCC: .4byte 0x08363CD8
_08055DD0: .4byte 0x000002BF
_08055DD4:
	ldr r0, _08055DF4 @ =0xFFFFFD40
_08055DD6:
	str r0, [r4, #0x5c]
_08055DD8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08055DEE
	movs r0, #8
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08055DEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055DF4: .4byte 0xFFFFFD40

	thumb_func_start copyxMode8
copyxMode8: @ 0x08055DF8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08055E18
	ldr r1, _08055E64 @ =0x0000B310
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #3
	adds r1, r4, #0
	adds r1, #0xc8
	strh r0, [r1]
_08055E18:
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08055E58
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r1, #0xb3
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08055E68 @ =sCollisions
	bl SetDDP
_08055E58:
	adds r0, r4, #0
	bl UpdateEntityAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055E64: .4byte 0x0000B310
_08055E68: .4byte sCollisions

