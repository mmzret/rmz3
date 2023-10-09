	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803d6a4
FUN_0803d6a4: @ 0x0803D6A4
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	beq _0803D6CC
	cmp r0, #1
	bgt _0803D6B8
	cmp r0, #0
	beq _0803D6BE
	b _0803D6F2
_0803D6B8:
	cmp r0, #2
	beq _0803D6E0
	b _0803D6F2
_0803D6BE:
	ldrb r0, [r2, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_0803D6CC:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D6F2
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	b _0803D6F2
_0803D6E0:
	ldr r0, _0803D6F8 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _0803D6F2
	strb r3, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803D6F2:
	pop {r0}
	bx r0
	.align 2, 0
_0803D6F8: .4byte gStageRun

	thumb_func_start FUN_0803d6fc
FUN_0803d6fc: @ 0x0803D6FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0803D70C
	cmp r0, #1
	beq _0803D728
	b _0803D798
_0803D70C:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803D76C @ =gMegamilpaCoreHitbox
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803D728:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803D798
	ldr r5, _0803D770 @ =u8_ARRAY_08361ac4
	ldr r3, _0803D774 @ =RNG_0202f388
	movs r0, #0xbd
	adds r0, r0, r4
	mov ip, r0
	adds r2, r4, #0
	adds r2, #0xbc
_0803D742:
	ldr r1, [r3]
	ldr r0, _0803D778 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803D77C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r1, r0
	bne _0803D780
	ldrb r0, [r2]
	adds r0, #1
	b _0803D782
	.align 2, 0
_0803D76C: .4byte gMegamilpaCoreHitbox
_0803D770: .4byte u8_ARRAY_08361ac4
_0803D774: .4byte RNG_0202f388
_0803D778: .4byte 0x000343FD
_0803D77C: .4byte 0x00269EC3
_0803D780:
	movs r0, #0
_0803D782:
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0803D742
	movs r0, #0
	mov r2, ip
	strb r1, [r2]
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0803D798:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803d7a0
FUN_0803d7a0: @ 0x0803D7A0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0803D7B0
	cmp r0, #1
	beq _0803D7F0
	b _0803D83E
_0803D7B0:
	ldr r0, _0803D814 @ =0x0000010D
	bl PlaySound
	movs r0, #0x20
	strb r0, [r6, #0x12]
	ldr r5, _0803D818 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _0803D81C @ =0x000343FD
	muls r0, r4, r0
	ldr r2, _0803D820 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r3, #1
	ands r0, r3
	movs r7, #0xbe
	strb r0, [r7, r6]
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r3
	adds r1, r6, #0
	adds r1, #0xbf
	strb r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0803D7F0:
	ldrb r1, [r6, #0x12]
	movs r4, #3
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0803D806
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0803d454
_0803D806:
	ldrb r0, [r6, #0x12]
	adds r3, r0, #0
	cmp r3, #0
	beq _0803D824
	subs r0, #1
	strb r0, [r6, #0x12]
	b _0803D834
	.align 2, 0
_0803D814: .4byte 0x0000010D
_0803D818: .4byte RNG_0202f388
_0803D81C: .4byte 0x000343FD
_0803D820: .4byte 0x00269EC3
_0803D824:
	adds r0, r6, #0
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r4, [r6, #0xd]
	strb r3, [r6, #0xe]
_0803D834:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
_0803D83E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

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
	bl UpdateMotionGraphic
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
	bl stopSound
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

	thumb_func_start FUN_0803dba0
FUN_0803dba0: @ 0x0803DBA0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0803DBB0
	cmp r0, #1
	beq _0803DBDE
	b _0803DC2E
_0803DBB0:
	ldr r0, _0803DC0C @ =0x0000010D
	bl PlaySound
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldr r2, _0803DC10 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803DC14 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803DC18 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0xbe
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803DBDE:
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DBF2
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0803d454
_0803DBF2:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	ldrb r0, [r4, #0x12]
	adds r3, r0, #0
	cmp r3, #0
	beq _0803DC1C
	subs r0, #1
	strb r0, [r4, #0x12]
	b _0803DC2E
	.align 2, 0
_0803DC0C: .4byte 0x0000010D
_0803DC10: .4byte RNG_0202f388
_0803DC14: .4byte 0x000343FD
_0803DC18: .4byte 0x00269EC3
_0803DC1C:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_0803DC2E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803dc34
FUN_0803dc34: @ 0x0803DC34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0803DC40
	b _0803DE4A
_0803DC40:
	lsls r0, r0, #2
	ldr r1, _0803DC4C @ =_0803DC50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803DC4C: .4byte _0803DC50
_0803DC50: @ jump table
	.4byte _0803DC70 @ case 0
	.4byte _0803DC9E @ case 1
	.4byte _0803DCDE @ case 2
	.4byte _0803DD7C @ case 3
	.4byte _0803DDB4 @ case 4
	.4byte _0803DDDA @ case 5
	.4byte _0803DDF8 @ case 6
	.4byte _0803DE0E @ case 7
_0803DC70:
	ldr r1, _0803DCC0 @ =0x0000A00C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x78
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xc8
	strb r1, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DC9E:
	ldrb r1, [r5, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DCB2
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0803d454
_0803DCB2:
	ldrb r0, [r5, #0x12]
	adds r1, r0, #0
	cmp r1, #0
	beq _0803DCC4
	subs r0, #1
	strb r0, [r5, #0x12]
	b _0803DCD2
	.align 2, 0
_0803DCC0: .4byte 0x0000A00C
_0803DCC4:
	adds r0, r5, #0
	adds r0, #0xc4
	str r1, [r0]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DCD2:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	b _0803DE4A
_0803DCDE:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803DD30 @ =0x083619C8
	bl SetDDP
	ldrb r0, [r5, #0xa]
	movs r2, #1
	movs r6, #0
	orrs r0, r2
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0xbe
	ldrb r0, [r4]
	ldrb r1, [r5, #0x13]
	eors r0, r1
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4]
	ldrb r0, [r5, #0x13]
	eors r1, r0
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	ands r1, r2
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0803DD34
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0803DD3A
	.align 2, 0
_0803DD30: .4byte 0x083619C8
_0803DD34:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803DD3A:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldrb r0, [r4]
	ldrb r1, [r5, #0x13]
	eors r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	ldrb r1, [r5, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r1, #0
	lsls r0, r0, #9
	ldr r1, _0803DD98 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DD7C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r1, r0, r1
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0803DD9C
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r1, r0
	ble _0803DDF0
	b _0803DDAA
	.align 2, 0
_0803DD98: .4byte 0xFFFFFF00
_0803DD9C:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _0803DDB0 @ =0xFFFF6000
	adds r0, r0, r2
	cmp r1, r0
	bge _0803DDF0
_0803DDAA:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0803DDEE
	.align 2, 0
_0803DDB0: .4byte 0xFFFF6000
_0803DDB4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803DDCC @ =gMegamilpaCoreHitbox
	bl SetDDP
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0803DDD0
	ldrb r0, [r5, #0xe]
	adds r0, #2
	strb r0, [r5, #0xe]
	b _0803DE4A
	.align 2, 0
_0803DDCC: .4byte gMegamilpaCoreHitbox
_0803DDD0:
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DDDA:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803DDE6
	subs r0, #1
	strb r0, [r5, #0x12]
	b _0803DDF0
_0803DDE6:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	movs r0, #2
_0803DDEE:
	strb r0, [r5, #0xe]
_0803DDF0:
	adds r0, r5, #0
	bl FUN_0803d600
	b _0803DE4A
_0803DDF8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0xc4
	movs r0, #0x78
	str r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DE0E:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r4, [r0]
	adds r6, r0, #0
	cmp r4, #0
	beq _0803DE20
	subs r0, r4, #1
	str r0, [r6]
	b _0803DE2C
_0803DE20:
	ldr r0, _0803DE50 @ =0x0000010D
	bl stopSound
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0803DE2C:
	ldr r0, [r6]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DE40
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0803d454
_0803DE40:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
_0803DE4A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DE50: .4byte 0x0000010D
