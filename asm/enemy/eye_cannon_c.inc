	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080849b0
FUN_080849b0: @ 0x080849B0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080849C0
	cmp r0, #1
	beq _080849DC
	b _08084A6A
_080849C0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08084A14 @ =0x08368328
	bl SetDDP
	ldr r1, _08084A18 @ =0x00006601
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x80
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080849DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08084A28
	ldr r0, _08084A1C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, _08084A20 @ =0x000067FF
	cmp r0, r1
	bhi _08084A50
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _08084A24 @ =0x00006FFF
	cmp r0, r1
	bhi _08084A50
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _08084A50
	.align 2, 0
_08084A14: .4byte 0x08368328
_08084A18: .4byte 0x00006601
_08084A1C: .4byte pZero2
_08084A20: .4byte 0x000067FF
_08084A24: .4byte 0x00006FFF
_08084A28:
	ldr r0, _08084A70 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	ldr r1, _08084A74 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, _08084A78 @ =0x000067FF
	cmp r0, r1
	bhi _08084A50
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	ldr r1, _08084A7C @ =0x00006FFF
	cmp r0, r1
	bhi _08084A50
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08084A50:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08084A64
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08084A64:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08084A6A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08084A70: .4byte pZero2
_08084A74: .4byte 0xFFFFF000
_08084A78: .4byte 0x000067FF
_08084A7C: .4byte 0x00006FFF

	thumb_func_start FUN_08084a80
FUN_08084a80: @ 0x08084A80
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08084AAC
	cmp r0, #1
	bgt _08084A94
	cmp r0, #0
	beq _08084A9E
	b _08084B26
_08084A94:
	cmp r0, #2
	beq _08084AC8
	cmp r0, #3
	beq _08084B0C
	b _08084B26
_08084A9E:
	ldr r1, _08084AC4 @ =0x00006602
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08084AAC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08084B26
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08084B26
	.align 2, 0
_08084AC4: .4byte 0x00006602
_08084AC8:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08084ADA
	movs r0, #0x10
	orrs r0, r2
	b _08084ADE
_08084ADA:
	movs r0, #0xef
	ands r0, r2
_08084ADE:
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
	movs r1, #0xcc
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08084B0C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08084B26
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08084B26:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084b2c
FUN_08084b2c: @ 0x08084B2C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08084B56
	cmp r0, #1
	bgt _08084B42
	cmp r0, #0
	beq _08084B4C
	b _08084C18
_08084B42:
	cmp r0, #2
	beq _08084B70
	cmp r0, #3
	beq _08084C00
	b _08084C18
_08084B4C:
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08084B56:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08084B68
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08084B68:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08084C18
_08084B70:
	ldr r2, [r4, #0x54]
	ldr r1, _08084C20 @ =0xFFFFFC00
	adds r0, r2, r1
	str r0, [sp]
	adds r1, r0, #0
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _08084B8C
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r2, r0
_08084B8C:
	str r1, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r7, #0xc0
	lsls r7, r7, #2
	ldr r6, _08084C24 @ =0x08368370
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	ands r0, r1
	adds r0, r0, r6
	ldrb r2, [r0]
	mov r0, sp
	adds r1, r7, #0
	bl CreateLemon
	ldr r3, [r4, #0x54]
	ldr r2, _08084C28 @ =0xFFFFFF00
	adds r0, r3, r2
	str r0, [sp]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08084BCC
	adds r2, r3, #0
_08084BCC:
	str r2, [sp]
	ldr r0, [r4, #0x58]
	movs r2, #0xd8
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #2
	cmp r1, #0
	beq _08084BE0
	movs r0, #3
_08084BE0:
	adds r0, r0, r6
	ldrb r2, [r0]
	mov r0, sp
	adds r1, r7, #0
	bl CreateLemon
	movs r0, #0x2c
	bl PlaySound
	ldr r1, _08084C2C @ =0x00006604
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08084C00:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08084C18
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08084C18:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084C20: .4byte 0xFFFFFC00
_08084C24: .4byte 0x08368370
_08084C28: .4byte 0xFFFFFF00
_08084C2C: .4byte 0x00006604

	thumb_func_start FUN_08084c30
FUN_08084c30: @ 0x08084C30
	push {r4, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08084C40
	cmp r0, #1
	beq _08084C4A
	b _08084CAC
_08084C40:
	movs r0, #0x60
	strb r0, [r2, #0x12]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08084C4A:
	ldrb r0, [r2, #0x12]
	subs r0, #1
	movs r4, #0
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08084C5E
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r4, [r2, #0xe]
_08084C5E:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08084C7C
	ldr r0, _08084C78 @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	b _08084C88
	.align 2, 0
_08084C78: .4byte pZero2
_08084C7C:
	ldr r0, _08084CB4 @ =pZero2
	ldr r3, [r0]
	ldr r0, [r3, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	ldr r1, _08084CB8 @ =0xFFFFF000
_08084C88:
	adds r0, r0, r1
	movs r1, #0xd0
	lsls r1, r1, #7
	cmp r0, r1
	bhi _08084CA0
	ldr r0, [r3, #0x58]
	ldr r1, [r2, #0x58]
	subs r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08084CA6
_08084CA0:
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r4, [r2, #0xe]
_08084CA6:
	adds r0, r2, #0
	bl UpdateEntityAnim
_08084CAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08084CB4: .4byte pZero2
_08084CB8: .4byte 0xFFFFF000
