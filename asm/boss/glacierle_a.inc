	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start glacierleIceRain2
glacierleIceRain2: @ 0x08058BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08058C20
	cmp r0, #1
	bgt _08058BEC
	cmp r0, #0
	beq _08058BF2
	b _08058D32
_08058BEC:
	cmp r0, #2
	beq _08058C78
	b _08058D32
_08058BF2:
	ldr r2, [r4, #0x2c]
	cmp r2, #0
	beq _08058C10
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #2
	cmp r0, #0
	beq _08058C08
	ldr r1, _08058CC0 @ =0xFFFFFD80
_08058C08:
	adds r0, r2, #0
	movs r2, #0
	bl FUN_0808242c
_08058C10:
	movs r0, #0x20
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x68]
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08058C20:
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _08058C5E
	ldr r1, [r4, #0x54]
	str r1, [r5, #0x54]
	ldr r3, _08058CC4 @ =s16_ARRAY_08364af0
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r2, r1, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08058C54
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	subs r2, r2, r0
_08058C54:
	str r2, [r5, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _08058CC8 @ =0xFFFFD300
	adds r0, r0, r2
	str r0, [r5, #0x58]
_08058C5E:
	movs r0, #0
	strb r0, [r4, #0x13]
	ldr r1, _08058CCC @ =sMotions
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08058C78:
	ldr r5, [r4, #0x28]
	ldr r3, _08058CD0 @ =u8_ARRAY_08364b00
	ldrb r2, [r4, #0x12]
	adds r0, r2, r3
	ldrb r6, [r0]
	adds r1, r2, #1
	adds r0, r1, #0
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r1, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	subs r0, r0, r6
	ldrb r1, [r4, #0x13]
	muls r0, r1, r0
	ldr r1, _08058CD4 @ =u8_ARRAY_08364ae8
	adds r1, r2, r1
	ldrb r1, [r1]
	bl __divsi3
	adds r6, r6, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08058CD8
	movs r0, #0x80
	rsbs r0, r0, #0
	adds r1, r0, #0
	subs r1, r1, r6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_0808288c
	b _08058CE2
	.align 2, 0
_08058CC0: .4byte 0xFFFFFD80
_08058CC4: .4byte s16_ARRAY_08364af0
_08058CC8: .4byte 0xFFFFD300
_08058CCC: .4byte sMotions
_08058CD0: .4byte u8_ARRAY_08364b00
_08058CD4: .4byte u8_ARRAY_08364ae8
_08058CD8:
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_0808288c
_08058CE2:
	ldr r2, [r4, #0x2c]
	adds r0, r2, #0
	movs r1, #0
	bl glacierle_08082598
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _08058E10 @ =u8_ARRAY_08364ae8
	ldrb r2, [r4, #0x12]
	adds r1, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08058D12
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #7
	ands r0, r1
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xe]
_08058D12:
	ldr r0, [r4, #0x68]
	cmp r0, #3
	bne _08058D2C
	ldrb r0, [r4, #0x12]
	cmp r0, #4
	bne _08058D2C
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _08058D2C
	movs r0, #0xe
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08058D2C:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08058D32:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _08058E00
	ldr r0, [r4, #0x68]
	cmp r0, #2
	bgt _08058E00
	movs r0, #0x2d
	bl PlaySound
	movs r0, #0x20
	str r0, [r4, #0x64]
	ldr r2, _08058E14 @ =s16_ARRAY_08364b08
	ldr r0, [r4, #0x68]
	lsls r3, r0, #2
	adds r0, r3, r2
	movs r1, #0
	ldrsh r5, [r0, r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	mov sl, r0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08058D6A
	rsbs r5, r5, #0
_08058D6A:
	adds r0, r2, #2
	adds r0, r3, r0
	movs r1, #0
	ldrsh r6, [r0, r1]
	ldr r2, _08058E18 @ =s16_ARRAY_08364b14
	mov r8, r2
	adds r0, r3, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x54]
	adds r2, r0, r1
	cmp r7, #0
	beq _08058D88
	lsls r0, r1, #1
	subs r2, r2, r0
_08058D88:
	movs r0, #2
	add r0, r8
	mov sb, r0
	adds r0, r3, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	adds r0, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_080aa5e8
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r5
	lsls r0, r0, #5
	cmp r0, #0
	bge _08058DB2
	adds r0, #0xff
_08058DB2:
	asrs r5, r0, #8
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	subs r0, r0, r6
	lsls r0, r0, #5
	cmp r0, #0
	bge _08058DC4
	adds r0, #0xff
_08058DC4:
	asrs r6, r0, #8
	ldr r0, [r4, #0x68]
	lsls r7, r0, #2
	mov r2, r8
	adds r0, r7, r2
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r0, [r4, #0x54]
	adds r2, r0, r3
	ldrb r1, [r4, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08058DE4
	lsls r0, r3, #1
	subs r2, r2, r0
_08058DE4:
	mov r1, sb
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	adds r0, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_080aa5e8
	ldr r0, [r4, #0x68]
	adds r0, #1
	str r0, [r4, #0x68]
_08058E00:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08058E10: .4byte u8_ARRAY_08364ae8
_08058E14: .4byte s16_ARRAY_08364b08
_08058E18: .4byte s16_ARRAY_08364b14

	thumb_func_start glacierleIceRain3
glacierleIceRain3: @ 0x08058E1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _08058E2E
	b _08058FDC
_08058E2E:
	lsls r0, r0, #2
	ldr r1, _08058E38 @ =_08058E3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058E38: .4byte _08058E3C
_08058E3C: @ jump table
	.4byte _08058E54 @ case 0
	.4byte _08058E62 @ case 1
	.4byte _08058E94 @ case 2
	.4byte _08058F3C @ case 3
	.4byte _08058FA8 @ case 4
	.4byte _08058FC6 @ case 5
_08058E54:
	ldr r1, _08058E90 @ =0x0000B21E
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08058E62:
	ldr r7, [r6, #0x28]
	adds r0, r7, #0
	movs r1, #0x40
	bl FUN_0808288c
	ldr r5, [r6, #0x2c]
	adds r0, r5, #0
	movs r1, #0
	bl glacierle_08082598
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08058E88
	b _08058FDC
_08058E88:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08058FDA
	.align 2, 0
_08058E90: .4byte 0x0000B21E
_08058E94:
	ldr r5, [r6, #0x2c]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r0, [r1]
	movs r2, #0xb4
	adds r2, r2, r6
	mov sb, r2
	cmp r0, #0
	beq _08058EB4
	adds r4, r1, #0
_08058EA8:
	adds r0, r5, #0
	bl FUN_08082348
	ldrb r0, [r4]
	cmp r0, #0
	bne _08058EA8
_08058EB4:
	ldr r7, [r6, #0x28]
	ldrb r2, [r7, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	movs r4, #0
	movs r2, #0xfd
	mov ip, r2
	ands r0, r2
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r2, [r7, #0xa]
	movs r3, #0xfb
	adds r0, r3, #0
	ands r0, r2
	strb r0, [r7, #0xa]
	ldr r0, _08058F98 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r2, #3
	str r2, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
	ldrb r0, [r5, #0xa]
	ands r1, r0
	mov r0, ip
	ands r1, r0
	strb r1, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r0, [r5, #0xa]
	ands r3, r0
	strb r3, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	mov r1, sb
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	str r4, [r6, #0x60]
	ldr r1, _08058F9C @ =0x0000B211
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08058F3C:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08058F4C
	str r1, [r6, #0x60]
_08058F4C:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x74
	ldr r2, _08058FA0 @ =u8_ARRAY_08364b20
	adds r1, r6, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08058FA4 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08058FDC
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _08058FDA
	.align 2, 0
_08058F98: .4byte gEnemyFnTable
_08058F9C: .4byte 0x0000B211
_08058FA0: .4byte u8_ARRAY_08364b20
_08058FA4: .4byte sCollisions
_08058FA8:
	movs r0, #0x91
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08058FE8 @ =0x08363DE4
	bl SetDDP
	ldr r1, _08058FEC @ =0x0000B209
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08058FC6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08058FDC
	movs r0, #0
	strb r0, [r6, #0xd]
_08058FDA:
	strb r0, [r6, #0xe]
_08058FDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08058FE8: .4byte sCollisions+(1*24)
_08058FEC: .4byte 0x0000B209
