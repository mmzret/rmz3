	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitEX
cubitEX: @ 0x08053D0C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1b
	bls _08053D1A
	b _080542BC
_08053D1A:
	lsls r0, r0, #2
	ldr r1, _08053D24 @ =_08053D28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053D24: .4byte _08053D28
_08053D28: @ jump table
	.4byte _08053D98 @ case 0
	.4byte _0805426C @ case 1
	.4byte _08053E08 @ case 2
	.4byte _08053E32 @ case 3
	.4byte _08053E88 @ case 4
	.4byte _0805426C @ case 5
	.4byte _08053EF8 @ case 6
	.4byte _08053F60 @ case 7
	.4byte _080540CC @ case 8
	.4byte _0805426C @ case 9
	.4byte _08054114 @ case 10
	.4byte _0805426C @ case 11
	.4byte _08054128 @ case 12
	.4byte _08054132 @ case 13
	.4byte _0805414E @ case 14
	.4byte _08054170 @ case 15
	.4byte _080541A0 @ case 16
	.4byte _0805426C @ case 17
	.4byte _08054254 @ case 18
	.4byte _0805426C @ case 19
	.4byte _080541E0 @ case 20
	.4byte _080541F2 @ case 21
	.4byte _08054210 @ case 22
	.4byte _0805426C @ case 23
	.4byte _08054254 @ case 24
	.4byte _0805426C @ case 25
	.4byte _0805428C @ case 26
	.4byte _0805429E @ case 27
_08053D98:
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, [r0]
	ldr r2, [r7, #0x54]
	cmp r2, r1
	ble _08053DB6
	adds r0, #8
	ldr r0, [r0]
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r2, r0
	ble _08053DCA
	adds r0, r7, #0
	adds r0, #0xdc
	b _08053DC8
_08053DB6:
	adds r0, r7, #0
	adds r0, #0xe0
	ldr r0, [r0]
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r2, r0
	bge _08053DCA
	adds r0, r7, #0
	adds r0, #0xd4
_08053DC8:
	ldr r1, [r0]
_08053DCA:
	ldr r5, [r7, #0x58]
	ldr r0, _08053E00 @ =0xFFFFCE00
	adds r4, r5, r0
	movs r0, #0x18
	strb r0, [r7, #0x12]
	subs r0, r1, r2
	movs r1, #0x18
	bl __divsi3
	str r0, [r7, #0x5c]
	movs r0, #0xa2
	lsls r0, r0, #7
	subs r4, r4, r5
	subs r0, r0, r4
	movs r1, #0x18
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	movs r0, #0x17
	strb r0, [r7, #0x12]
	ldr r1, _08053E04 @ =0x0000B015
	adds r0, r7, #0
	bl SetMotion
	b _08054266
	.align 2, 0
_08053E00: .4byte 0xFFFFCE00
_08053E04: .4byte 0x0000B015
_08053E08:
	adds r1, r7, #0
	adds r1, #0xc8
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053E7C @ =0x0000B016
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08053E80 @ =sCollisions+(24*1)
	bl SetDDP
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08053E32:
	ldr r0, [r7, #0x60]
	adds r2, r0, #0
	adds r2, #0x48
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _08053E5E
	cmp r2, #0
	ble _08053E5E
	movs r0, #1
	strb r0, [r7, #0x13]
	ldr r1, _08053E84 @ =0x0000B017
	adds r0, r7, #0
	bl SetMotion
_08053E5E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08053E6C
	b _0805427C
_08053E6C:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08053E78
	b _080542BC
_08053E78:
	b _0805427C
	.align 2, 0
_08053E7C: .4byte 0x0000B016
_08053E80: .4byte sCollisions+(24*1)
_08053E84: .4byte 0x0000B017
_08053E88:
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r5, r0, #0
	movs r6, #0
	movs r0, #0x28
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x54]
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x28
	bl __divsi3
	str r0, [r7, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r5, r5, r1
	subs r0, r0, r5
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	movs r0, #0x27
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _08053EF4 @ =0x0000B018
	adds r0, r7, #0
	bl SetMotion
	str r6, [r7, #0x64]
	movs r0, #0xa4
	str r0, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	b _08054266
	.align 2, 0
_08053EF4: .4byte 0x0000B018
_08053EF8:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	ble _08053F1A
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0xa]
	orrs r1, r0
	strb r1, [r7, #0xa]
	b _08053F3A
_08053F1A:
	cmp r0, #0
	bge _08053F3A
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
_08053F3A:
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053FC8 @ =0x0000B019
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08053FCC @ =0x08363A20
	bl SetDDP
	ldr r0, [r7, #0x58]
	ldr r1, _08053FD0 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08053F60:
	ldr r2, [r7, #0x60]
	adds r2, #0x48
	str r2, [r7, #0x60]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r7, #0
	adds r5, #0x70
	cmp r0, #3
	bne _08054062
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08053FC8 @ =0x0000B019
	cmp r0, r1
	bne _08054004
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r7, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r7, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053FD4
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053FDA
	.align 2, 0
_08053FC8: .4byte 0x0000B019
_08053FCC: .4byte 0x08363A20
_08053FD0: .4byte 0xFFFFD800
_08053FD4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053FDA:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08053FEA
	movs r0, #0xfe
_08053FEA:
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	lsls r0, r0, #4
	str r0, [r7, #0x64]
	ldr r1, _08054000 @ =0x0000B01F
	adds r0, r7, #0
	bl SetMotion
	b _08054062
	.align 2, 0
_08054000: .4byte 0x0000B01F
_08054004:
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r7, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r7, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _0805403A
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08054040
_0805403A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08054040:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08054050
	movs r0, #0xfe
_08054050:
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	lsls r0, r0, #4
	str r0, [r7, #0x64]
	ldr r1, _08054084 @ =0x0000B019
	adds r0, r7, #0
	bl SetMotion
_08054062:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	ble _08054088
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08054084 @ =0x0000B019
	cmp r0, r1
	bne _080540A4
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	b _080540AA
	.align 2, 0
_08054084: .4byte 0x0000B019
_08054088:
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080540A0 @ =0x0000B019
	cmp r0, r1
	bne _080540A4
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	b _080540AA
	.align 2, 0
_080540A0: .4byte 0x0000B019
_080540A4:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
_080540AA:
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	asrs r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080540BE
	b _0805427C
_080540BE:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080540CA
	b _080542BC
_080540CA:
	b _0805427C
_080540CC:
	adds r0, r7, #0
	adds r0, #0xc8
	movs r1, #0
	strb r1, [r0]
	subs r0, #0xa4
	strb r1, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _08054108 @ =0x0000B01A
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805410C @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08054110 @ =0xFFFFC400
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	b _08054266
	.align 2, 0
_08054108: .4byte 0x0000B01A
_0805410C: .4byte sCollisions+(24*1)
_08054110: .4byte 0xFFFFC400
_08054114:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _08054124 @ =0x0000B01B
	b _08054256
	.align 2, 0
_08054124: .4byte 0x0000B01B
_08054128:
	movs r0, #2
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08054132:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08054140
	b _0805427C
_08054140:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805414C
	b _080542BC
_0805414C:
	b _0805427C
_0805414E:
	ldr r1, _08054198 @ =0x0000B00A
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805419C @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #8
	strb r0, [r7, #0x12]
	movs r0, #0xd0
	bl PlaySound
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08054170:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08054182
	b _080542BC
_08054182:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0805427C
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054194
	b _080542BC
_08054194:
	b _0805427C
	.align 2, 0
_08054198: .4byte 0x0000B00A
_0805419C: .4byte sCollisions+(24*1)
_080541A0:
	ldr r1, _080541D4 @ =0x0000B00B
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080541D8 @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080541DC @ =0xFFFFBE00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r4, #0
_080541C0:
	adds r0, r7, #0
	mov r1, sp
	adds r2, r4, #0
	bl createFlameRain1
	adds r4, #1
	cmp r4, #3
	ble _080541C0
	b _08054266
	.align 2, 0
_080541D4: .4byte 0x0000B00B
_080541D8: .4byte sCollisions+(24*1)
_080541DC: .4byte 0xFFFFBE00
_080541E0:
	ldr r1, _0805420C @ =0x0000B002
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080541F2:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0805427C
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080542BC
	b _0805427C
	.align 2, 0
_0805420C: .4byte 0x0000B002
_08054210:
	ldr r1, _08054248 @ =0x0000B00B
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0805424C @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r2, _08054250 @ =0xFFFFBE00
	adds r0, r0, r2
	add r1, sp, #8
	str r0, [r1, #4]
	movs r4, #0
	adds r5, r1, #0
_08054234:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl createFlameRain2
	adds r4, #1
	cmp r4, #1
	ble _08054234
	b _08054266
	.align 2, 0
_08054248: .4byte 0x0000B00B
_0805424C: .4byte sCollisions+(24*1)
_08054250: .4byte 0xFFFFBE00
_08054254:
	ldr r1, _08054284 @ =0x0000B00C
_08054256:
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08054288 @ =sCollisions+(24*1)
	bl SetDDP
_08054266:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805426C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080542BC
_0805427C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080542BC
	.align 2, 0
_08054284: .4byte 0x0000B00C
_08054288: .4byte sCollisions+(24*1)
_0805428C:
	ldr r1, _080542C4 @ =0x0000B002
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805429E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080542B4
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080542BC
_080542B4:
	movs r1, #0
	movs r0, #3
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_080542BC:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080542C4: .4byte 0x0000B002

