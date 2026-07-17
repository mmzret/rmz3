	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08042da4
FUN_08042da4: @ 0x08042DA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _08042DE0
	cmp r4, #1
	bgt _08042DB8
	cmp r4, #0
	beq _08042DBE
	b _08042E4E
_08042DB8:
	cmp r4, #2
	beq _08042E0A
	b _08042E4E
_08042DBE:
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r2, [r5, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042E30 @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _08042E34 @ =0x00002B06
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042DE0:
	ldr r0, [r5, #0x54]
	ldr r1, _08042E38 @ =0xFFFFDA00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08042E3C @ =0xFFFFC000
	adds r1, r1, r2
	ldr r4, _08042E40 @ =0x08362278
	ldrb r3, [r5, #0x12]
	lsls r3, r3, #3
	adds r2, r3, r4
	ldr r2, [r2]
	adds r4, #4
	adds r3, r3, r4
	ldr r3, [r3]
	bl FUN_08075c40
	movs r0, #0x10
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042E0A:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042E48
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08042E44
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08042E48
	.align 2, 0
_08042E30: .4byte sCollisions+(5*24)
_08042E34: .4byte 0x00002B06
_08042E38: .4byte 0xFFFFDA00
_08042E3C: .4byte 0xFFFFC000
_08042E40: .4byte 0x08362278
_08042E44:
	movs r0, #1
	strb r0, [r5, #0xe]
_08042E48:
	adds r0, r5, #0
	bl UpdateEntityAnim
_08042E4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042e54
FUN_08042e54: @ 0x08042E54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08042E80
	cmp r0, #1
	bgt _08042E68
	cmp r0, #0
	beq _08042E72
	b _08042F82
_08042E68:
	cmp r0, #2
	beq _08042ED0
	cmp r0, #3
	beq _08042F10
	b _08042F82
_08042E72:
	ldr r1, _08042EC4 @ =0x00002B02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042E80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08042EC8 @ =0x08362290
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r3, [r4, #0x10]
	lsls r2, r3, #3
	subs r2, r2, r3
	ldrb r1, [r1]
	adds r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08042ECC @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08042F82
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08042F82
	.align 2, 0
_08042EC4: .4byte 0x00002B02
_08042EC8: .4byte 0x08362290
_08042ECC: .4byte sCollisions
_08042ED0:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08042EDE
	movs r0, #0x55
	bl PlaySound
	b _08042EE4
_08042EDE:
	movs r0, #0x55
	bl PlaySound
_08042EE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042F88 @ =0x08362110
	adds r1, r1, r2
	bl SetDDP
	movs r0, #0xa8
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042F10:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0xb4
	cmp r0, #0
	bne _08042F58
	ldr r2, _08042F8C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042F90 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042F94 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r2, _08042F98 @ =0xFFFFF400
	adds r0, r0, r2
	ldr r3, [r4, #0x54]
	adds r3, r3, r0
	ldr r1, [r5]
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r2, [r0]
	adds r0, r3, #0
	bl CreateGhost35
_08042F58:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r5]
	movs r2, #0xa8
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	ble _08042F7C
	adds r0, r4, #0
	adds r0, #0xba
	strb r6, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
_08042F7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08042F82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042F88: .4byte sCollisions+(1*24)
_08042F8C: .4byte RNG_0202f388
_08042F90: .4byte 0x000343FD
_08042F94: .4byte 0x00269EC3
_08042F98: .4byte 0xFFFFF400

