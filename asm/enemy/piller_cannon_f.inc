	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068adc
FUN_08068adc: @ 0x08068ADC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xa
	bls _08068AEA
	b _08068C70
_08068AEA:
	lsls r0, r0, #2
	ldr r1, _08068AF4 @ =_08068AF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068AF4: .4byte _08068AF8
_08068AF8: @ jump table
	.4byte _08068B24 @ case 0
	.4byte _08068C1E @ case 1
	.4byte _08068B30 @ case 2
	.4byte _08068B50 @ case 3
	.4byte _08068C18 @ case 4
	.4byte _08068B84 @ case 5
	.4byte _08068B9A @ case 6
	.4byte _08068C0E @ case 7
	.4byte _08068C18 @ case 8
	.4byte _08068C36 @ case 9
	.4byte _08068C4A @ case 10
_08068B24:
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068C1E
_08068B30:
	ldr r0, _08068B78 @ =0x00000103
	bl PlaySound
	ldr r1, _08068B7C @ =0x00000805
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068B50:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08068B62
	b _08068C70
_08068B62:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08068B80 @ =0x083661A4
	bl SetDDP
	b _08068C2E
	.align 2, 0
_08068B78: .4byte 0x00000103
_08068B7C: .4byte 0x00000805
_08068B80: .4byte sCollisions+(11*24)
_08068B84:
	ldr r1, _08068BCC @ =0x00000806
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	movs r0, #3
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068B9A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08068C04
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068C04
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r7, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08068BD4
	ldr r0, [r5, #0x54]
	ldr r1, _08068BD0 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp]
	movs r6, #0xa0
	lsls r6, r6, #2
	movs r2, #0
	b _08068BE4
	.align 2, 0
_08068BCC: .4byte 0x00000806
_08068BD0: .4byte 0xFFFFE800
_08068BD4:
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	movs r6, #0xa0
	lsls r6, r6, #2
	movs r2, #0x80
_08068BE4:
	mov r0, sp
	adds r1, r6, #0
	bl CreateLemon
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2c
	bl PlaySound
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
_08068C04:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x13]
	b _08068C2A
_08068C0E:
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068C18:
	adds r0, r5, #0
	bl UpdateEntityAnim
_08068C1E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08068C70
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
_08068C2A:
	cmp r0, #0
	bne _08068C70
_08068C2E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068C70
_08068C36:
	ldr r0, _08068C78 @ =0x00000103
	bl PlaySound
	ldr r1, _08068C7C @ =0x00000807
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068C4A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08068C70
	adds r0, r5, #0
	adds r0, #0xb9
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08068C80 @ =0x08366144
	bl SetDDP
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_08068C70:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068C78: .4byte 0x00000103
_08068C7C: .4byte 0x00000807
_08068C80: .4byte sCollisions+(7*24)

