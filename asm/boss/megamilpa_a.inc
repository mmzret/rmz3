	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803d844
FUN_0803d844: @ 0x0803D844
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _0803D858
	b _0803DB88
_0803D858:
	lsls r0, r0, #2
	ldr r1, _0803D864 @ =_0803D868
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D864: .4byte _0803D868
_0803D868: @ jump table
	.4byte _0803D880 @ case 0
	.4byte _0803D898 @ case 1
	.4byte _0803D8CA @ case 2
	.4byte _0803D97E @ case 3
	.4byte _0803DB2C @ case 4
	.4byte _0803DB4C @ case 5
_0803D880:
	adds r2, r6, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0x55
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803D898:
	ldrb r1, [r6, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803D8AC
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0803d454
_0803D8AC:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0803D8C2
	subs r0, #1
	strb r0, [r6, #0x12]
	b _0803DB88
_0803D8C2:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0803DB88
_0803D8CA:
	ldrb r2, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	movs r1, #0
	orrs r0, r2
	strb r0, [r6, #0xa]
	strb r1, [r6, #0x12]
	strb r1, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xc4
	adds r0, r6, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	lsls r0, r0, #0xf
	str r0, [r1]
	adds r5, r6, #0
	adds r5, #0xbf
	ldrb r1, [r5]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r0, [r5]
	adds r4, r6, #0
	adds r4, #0x4a
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5]
	ands r2, r0
	cmp r2, #0
	beq _0803D922
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0803D928
_0803D922:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803D928:
	strb r0, [r6, #0xa]
	ldrb r1, [r5]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	adds r1, r6, #0
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r0, [r5]
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #5
	ldrb r3, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5]
	ands r2, r0
	cmp r2, #0
	beq _0803D95C
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _0803D962
_0803D95C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0803D962:
	strb r0, [r6, #0xa]
	movs r2, #0xc0
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbe
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803D97E:
	ldr r3, _0803D9E8 @ =gSineTable
	adds r2, r6, #0
	adds r2, #0xc4
	ldr r0, [r2]
	asrs r0, r0, #8
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r2]
	asrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	rsbs r1, r1, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	adds r7, r2, #0
	movs r1, #0xbe
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	bne _0803DA7E
	ldrb r2, [r1]
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _0803D9EC
	cmp r2, #1
	bne _0803D9FA
	b _0803D9F0
	.align 2, 0
_0803D9E8: .4byte gSineTable
_0803D9EC:
	cmp r2, #0
	bne _0803D9FA
_0803D9F0:
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	bne _0803DA7E
_0803D9FA:
	movs r0, #1
	strb r0, [r6, #0x12]
	ldr r0, [r7]
	asrs r4, r0, #8
	movs r1, #0x80
	subs r4, r1, r4
	lsls r0, r4, #2
	adds r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _0803DA12
	adds r0, #0x7f
_0803DA12:
	asrs r4, r0, #7
	lsls r4, r4, #5
	subs r5, r1, r4
	movs r0, #0xbf
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803DA26
	adds r5, #0x80
_0803DA26:
	ldr r2, [r6, #0x54]
	str r2, [sp]
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r1, r0, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp]
	ldr r2, [r6, #0x58]
	str r2, [sp, #4]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	rsbs r1, r1, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	mov r1, r8
	ldrb r0, [r1]
	ldr r1, _0803DAA0 @ =0xFFFFFE00
	cmp r0, #0
	beq _0803DA70
	movs r1, #0x80
	lsls r1, r1, #2
_0803DA70:
	adds r2, r4, #0
	subs r2, #0x80
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	bl CreateLemon
_0803DA7E:
	ldr r2, [r7]
	ldr r0, [r6, #0x5c]
	adds r2, r2, r0
	str r2, [r7]
	mov r4, sb
	ldrb r3, [r4]
	lsls r0, r3, #6
	subs r0, r0, r3
	lsls r0, r0, #1
	movs r1, #0x7f
	subs r4, r1, r0
	lsls r4, r4, #8
	cmp r2, r4
	ble _0803DAA4
	cmp r3, #1
	bne _0803DAAE
	b _0803DAA8
	.align 2, 0
_0803DAA0: .4byte 0xFFFFFE00
_0803DAA4:
	cmp r3, #0
	bne _0803DAAE
_0803DAA8:
	ldr r0, [r7]
	cmp r0, r4
	bne _0803DAB6
_0803DAAE:
	str r4, [r7]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803DAB6:
	ldr r0, [r7]
	asrs r4, r0, #8
	lsls r0, r4, #2
	adds r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _0803DAC6
	adds r0, #0x7f
_0803DAC6:
	asrs r4, r0, #7
	cmp r4, #4
	ble _0803DACE
	movs r4, #4
_0803DACE:
	ldr r1, _0803DB20 @ =0x08361AC6
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803DB24 @ =0x08361AD0
	adds r1, r4, r1
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0803DB28 @ =0x083619C8
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DB12
	ldrb r1, [r6, #0x12]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0803d454
_0803DB12:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	b _0803DB88
	.align 2, 0
_0803DB20: .4byte 0x08361AC6
_0803DB24: .4byte 0x08361AD0
_0803DB28: .4byte 0x083619C8
_0803DB2C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0803DB98 @ =gMegamilpaCoreHitbox
	bl SetDDP
	adds r1, r6, #0
	adds r1, #0xc4
	movs r0, #0x55
	str r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803DB4C:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DB64
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0803d454
_0803DB64:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	adds r1, r6, #0
	adds r1, #0xc4
	ldr r0, [r1]
	subs r4, r0, #1
	str r4, [r1]
	cmp r4, #0
	bne _0803DB88
	ldr r0, _0803DB9C @ =0x0000010D
	bl StopSound
	movs r0, #1
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
_0803DB88:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB98: .4byte gMegamilpaCoreHitbox
_0803DB9C: .4byte 0x0000010D
