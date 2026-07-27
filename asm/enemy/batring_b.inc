	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08067a64
FUN_08067a64: @ 0x08067A64
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _08067A70
	b _08067C3E
_08067A70:
	lsls r0, r0, #2
	ldr r1, _08067A7C @ =_08067A80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08067A7C: .4byte _08067A80
_08067A80: @ jump table
	.4byte _08067AA0 @ case 0
	.4byte _08067AB0 @ case 1
	.4byte _08067AD6 @ case 2
	.4byte _08067AEC @ case 3
	.4byte _08067B14 @ case 4
	.4byte _08067B36 @ case 5
	.4byte _08067B86 @ case 6
	.4byte _08067BBE @ case 7
_08067AA0:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067AB0:
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08067AC0
	adds r0, r5, #0
	bl UpdateEntityAnim
_08067AC0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08067AC8
	b _08067C3E
_08067AC8:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08067AD4
	b _08067C3E
_08067AD4:
	b _08067B6E
_08067AD6:
	ldr r1, _08067B10 @ =0x00000601
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067AEC:
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	strb r0, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08067B00
	adds r0, r5, #0
	bl UpdateEntityAnim
_08067B00:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08067B0C
	b _08067C3E
_08067B0C:
	b _08067B6E
	.align 2, 0
_08067B10: .4byte 0x00000601
_08067B14:
	adds r0, r5, #0
	adds r0, #0xb9
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08067B78 @ =sCollisions+(24*6)
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbb
	movs r0, #1
	strb r0, [r1]
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067B36:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067B46
	str r1, [r5, #0x60]
_08067B46:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08067B7C
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08067B6E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067C3E
	.align 2, 0
_08067B78: .4byte sCollisions+(24*6)
_08067B7C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08067C3E
_08067B86:
	movs r0, #0x82
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _08067BA4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08067BAC
	ldr r1, _08067BA8 @ =0x00000603
	adds r0, r5, #0
	bl SetMotion
	b _08067BB4
	.align 2, 0
_08067BA4: .4byte pZero2
_08067BA8: .4byte 0x00000603
_08067BAC:
	ldr r1, _08067BF0 @ =0x00000605
	adds r0, r5, #0
	bl SetMotion
_08067BB4:
	ldr r0, _08067BF4 @ =0xFFFFFE80
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067BBE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067BE2
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067BFC
_08067BE2:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067BF8 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067C06
	.align 2, 0
_08067BF0: .4byte 0x00000605
_08067BF4: .4byte 0xFFFFFE80
_08067BF8: .4byte sCollisions+(24*10)
_08067BFC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067C44 @ =sCollisions+(24*8)
	bl SetDDP
_08067C06:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067C16
	str r1, [r5, #0x60]
_08067C16:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08067C3E
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08067C3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067C44: .4byte sCollisions+(24*8)
