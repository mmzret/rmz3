	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitMode4
cubitMode4: @ 0x08052F0C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0xb
	bls _08052F18
	b _080533AE
_08052F18:
	lsls r0, r0, #2
	ldr r1, _08052F24 @ =_08052F28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052F24: .4byte _08052F28
_08052F28: @ jump table
	.4byte _08052F58 @ case 0
	.4byte _08052FCC @ case 1
	.4byte _08052FEC @ case 2
	.4byte _08053010 @ case 3
	.4byte _08053068 @ case 4
	.4byte _08053114 @ case 5
	.4byte _08053130 @ case 6
	.4byte _0805319A @ case 7
	.4byte _08053308 @ case 8
	.4byte _0805334E @ case 9
	.4byte _08053374 @ case 10
	.4byte _08053398 @ case 11
_08052F58:
	adds r3, r6, #0
	adds r3, #0xca
	movs r0, #1
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r2, [r6, #0x54]
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r2, r1
	ble _08052F7E
	adds r0, #8
	ldr r0, [r0]
	asrs r0, r0, #1
	adds r0, r1, r0
	cmp r2, r0
	ble _08052F90
	movs r0, #2
	b _08052F8E
_08052F7E:
	adds r0, r6, #0
	adds r0, #0xe0
	ldr r0, [r0]
	asrs r0, r0, #1
	subs r0, r1, r0
	cmp r2, r0
	bge _08052F90
	movs r0, #0
_08052F8E:
	strb r0, [r3]
_08052F90:
	ldr r0, [r4]
	ldr r5, [r6, #0x58]
	ldr r1, _08052FE4 @ =0xFFFFCE00
	adds r4, r5, r1
	movs r1, #0x18
	strb r1, [r6, #0x12]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	movs r1, #0x18
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0xa2
	lsls r0, r0, #7
	subs r4, r4, r5
	subs r0, r0, r4
	movs r1, #0x18
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	movs r0, #0x17
	strb r0, [r6, #0x12]
	ldr r1, _08052FE8 @ =0x0000B015
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08052FCC:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08052FDE
	b _080533AE
_08052FDE:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_08052FE4: .4byte 0xFFFFCE00
_08052FE8: .4byte 0x0000B015
_08052FEC:
	adds r1, r6, #0
	adds r1, #0xc8
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0805305C @ =0x0000B016
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08053060 @ =sCollisions+(24*1)
	bl SetDDP
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053010:
	ldr r0, [r6, #0x60]
	adds r2, r0, #0
	adds r2, #0x48
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0805303C
	cmp r2, #0
	ble _0805303C
	movs r0, #1
	strb r0, [r6, #0x13]
	ldr r1, _08053064 @ =0x0000B017
	adds r0, r6, #0
	bl SetMotion
_0805303C:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08053054
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08053054
	b _080533AE
_08053054:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_0805305C: .4byte 0x0000B016
_08053060: .4byte sCollisions+(24*1)
_08053064: .4byte 0x0000B017
_08053068:
	movs r7, #0
	adds r0, r6, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805307A
	adds r0, r6, #0
	adds r0, #0xdc
	b _080530A0
_0805307A:
	cmp r0, #1
	bne _08053098
	ldr r0, _08053094 @ =pZero2
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0xd8
	ldr r2, [r0, #0x54]
	ldr r0, [r1]
	cmp r2, r0
	ble _0805309C
	adds r0, r6, #0
	adds r0, #0xdc
	b _080530A0
	.align 2, 0
_08053094: .4byte pZero2
_08053098:
	cmp r0, #2
	bne _080530A2
_0805309C:
	adds r0, r6, #0
	adds r0, #0xd4
_080530A0:
	ldr r7, [r0]
_080530A2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	movs r5, #0
	movs r0, #0x28
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl InitScalerotMotion1
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _0805312C @ =0x0000B018
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x64]
	movs r0, #0x52
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r0, [r6, #0x54]
	subs r0, r7, r0
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	adds r2, r0, #0
	muls r2, r1, r2
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r6, #0x58]
	subs r4, r4, r2
	subs r0, r0, r4
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053114:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053126
	b _080533AE
_08053126:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_0805312C: .4byte 0x0000B018
_08053130:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _08053152
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0xa]
	orrs r1, r0
	strb r1, [r6, #0xa]
	b _0805316E
_08053152:
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
_0805316E:
	movs r0, #0xca
	bl PlaySound
	ldr r1, _08053200 @ =0x0000B019
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08053204 @ =0x08363A20
	bl SetDDP
	ldr r0, [r6, #0x58]
	ldr r2, _08053208 @ =0xFFFFD800
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldr r1, _0805320C @ =gElFxManager
	movs r0, #4
	strb r0, [r1, #2]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0805319A:
	ldr r2, [r6, #0x60]
	adds r2, #0x48
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r6, #0
	adds r5, #0x70
	cmp r0, #3
	bne _0805329E
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _08053200 @ =0x0000B019
	cmp r0, r1
	bne _08053240
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053210
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053216
	.align 2, 0
_08053200: .4byte 0x0000B019
_08053204: .4byte 0x08363A20
_08053208: .4byte 0xFFFFD800
_0805320C: .4byte gElFxManager
_08053210:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053216:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08053226
	movs r0, #0xfe
_08053226:
	subs r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	lsls r0, r0, #4
	str r0, [r6, #0x64]
	ldr r1, _0805323C @ =0x0000B01F
	adds r0, r6, #0
	bl SetMotion
	b _0805329E
	.align 2, 0
_0805323C: .4byte 0x0000B01F
_08053240:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _08053276
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805327C
_08053276:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805327C:
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x64]
	asrs r1, r0, #4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _0805328C
	movs r0, #0xfe
_0805328C:
	subs r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	lsls r0, r0, #4
	str r0, [r6, #0x64]
	ldr r1, _080532C0 @ =0x0000B019
	adds r0, r6, #0
	bl SetMotion
_0805329E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _080532C4
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080532C0 @ =0x0000B019
	cmp r0, r1
	bne _080532E0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	subs r0, r0, r1
	b _080532E6
	.align 2, 0
_080532C0: .4byte 0x0000B019
_080532C4:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080532DC @ =0x0000B019
	cmp r0, r1
	bne _080532E0
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	subs r0, r0, r1
	b _080532E6
	.align 2, 0
_080532DC: .4byte 0x0000B019
_080532E0:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
_080532E6:
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x64]
	asrs r0, r0, #4
	adds r1, r6, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08053302
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080533AE
_08053302:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
_08053308:
	adds r0, r6, #0
	adds r0, #0xc8
	movs r2, #0
	strb r2, [r0]
	ldr r1, _08053364 @ =gElFxManager
	movs r0, #4
	strb r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _08053368 @ =0x0000B01A
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0805336C @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, _08053370 @ =0xFFFFC400
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0805334E:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080533AE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _080533AC
	.align 2, 0
_08053364: .4byte gElFxManager
_08053368: .4byte 0x0000B01A
_0805336C: .4byte sCollisions+(24*1)
_08053370: .4byte 0xFFFFC400
_08053374:
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldr r1, _080533B4 @ =0x0000B01B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080533B8 @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08053398:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _080533AE
	movs r0, #0
	strb r1, [r6, #0xd]
_080533AC:
	strb r0, [r6, #0xe]
_080533AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080533B4: .4byte 0x0000B01B
_080533B8: .4byte sCollisions+(24*1)

