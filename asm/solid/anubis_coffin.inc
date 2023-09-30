	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cdd64
FUN_080cdd64: @ 0x080CDD64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x2c]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x24
	ands r0, r1
	cmp r0, #0
	bne _080CDD90
	mov r0, sb
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xbc
	cmp r0, #0
	beq _080CDD98
_080CDD90:
	adds r1, r7, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_080CDD98:
	ldr r2, [r7, #0x54]
	mov r0, sb
	ldr r3, [r0, #0x54]
	subs r2, r2, r3
	ldr r0, _080CDE0C @ =0xFFFFE800
	adds r2, r2, r0
	ldrb r0, [r1]
	ldr r4, [r7, #0x54]
	cmp r0, #0
	bne _080CDDD6
	ldr r0, _080CDE10 @ =0x00001DFF
	cmp r2, r0
	bgt _080CDE24
	ldr r0, _080CDE14 @ =pZero2
	ldr r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r2, #0x54]
	cmp r1, r0
	blt _080CDE24
	ldr r3, _080CDE18 @ =0xFFFFF400
	adds r0, r4, r3
	cmp r1, r0
	bgt _080CDE24
	ldr r0, [r7, #0x58]
	ldr r1, _080CDE1C @ =0xFFFFE200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	cmp r1, r0
	ble _080CDE24
_080CDDD6:
	ldr r0, _080CDE14 @ =pZero2
	ldr r1, [r0]
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r1, #0x54]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r5, _080CDE20 @ =0x08370220
	adds r1, r5, #0
	bl SetDDP
	ldrb r1, [r7, #0xb]
	movs r4, #0xf7
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r7, #0xb]
	mov r0, sb
	adds r0, #0x74
	adds r1, r5, #0
	bl SetDDP
	mov r3, sb
	ldrb r0, [r3, #0xb]
	ands r4, r0
	strb r4, [r3, #0xb]
	b _080CDE56
	.align 2, 0
_080CDE0C: .4byte 0xFFFFE800
_080CDE10: .4byte 0x00001DFF
_080CDE14: .4byte pZero2
_080CDE18: .4byte 0xFFFFF400
_080CDE1C: .4byte 0xFFFFE200
_080CDE20: .4byte 0x08370220
_080CDE24:
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080CDE64 @ =0x08370208
	mov r8, r1
	bl SetDDP
	ldrb r0, [r7, #0xb]
	movs r4, #8
	orrs r0, r4
	strb r0, [r7, #0xb]
	ldr r6, _080CDE68 @ =0x08370238
	str r6, [r7, #0x30]
	movs r5, #1
	strh r5, [r7, #0x26]
	mov r0, sb
	adds r0, #0x74
	mov r1, r8
	bl SetDDP
	mov r3, sb
	ldrb r0, [r3, #0xb]
	orrs r4, r0
	strb r4, [r3, #0xb]
	str r6, [r3, #0x30]
	strh r5, [r3, #0x26]
_080CDE56:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CDE64: .4byte 0x08370208
_080CDE68: .4byte 0x08370238

	thumb_func_start nop_080cde6c
nop_080cde6c: @ 0x080CDE6C
	bx lr
	.align 2, 0

	thumb_func_start AnubisCoffin_Init
AnubisCoffin_Init: @ 0x080CDE70
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CDED8 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080CDEDC @ =0x08370240
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080CDEE0 @ =0x08370208
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080CDEE4 @ =nop_080cde6c
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xbc
	strb r6, [r0]
	adds r0, r4, #0
	bl AnubisCoffin_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CDED8: .4byte gSolidFnTable
_080CDEDC: .4byte 0x08370240
_080CDEE0: .4byte 0x08370208
_080CDEE4: .4byte nop_080cde6c

	thumb_func_start AnubisCoffin_Update
AnubisCoffin_Update: @ 0x080CDEE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CDF14 @ =0x083701F0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CDF18 @ =0x083701FC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CDF14: .4byte 0x083701F0
_080CDF18: .4byte 0x083701FC

	thumb_func_start AnubisCoffin_Die
AnubisCoffin_Die: @ 0x080CDF1C
	ldr r2, _080CDF30 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080CDF30: .4byte gSolidFnTable

	thumb_func_start FUN_080cdf34
FUN_080cdf34: @ 0x080CDF34
	bx lr
	.align 2, 0

	thumb_func_start coffin_080cdf38
coffin_080cdf38: @ 0x080CDF38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080CE03A
	cmp r0, #1
	bgt _080CDF4E
	cmp r0, #0
	beq _080CDF5C
	b _080CE0C4
_080CDF4E:
	cmp r0, #2
	bne _080CDF54
	b _080CE054
_080CDF54:
	cmp r0, #3
	bne _080CDF5A
	b _080CE098
_080CDF5A:
	b _080CE0C4
_080CDF5C:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CDF8C @ =0x08370238
	str r0, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x26]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080CDFBC
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CDF94
	movs r1, #0x96
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r1]
	ldr r2, _080CDF90 @ =0xFFFF7800
	b _080CDFA6
	.align 2, 0
_080CDF8C: .4byte 0x08370238
_080CDF90: .4byte 0xFFFF7800
_080CDF94:
	ldr r1, _080CDFB8 @ =0x00004B01
	adds r0, r4, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r1]
	movs r2, #0x88
	lsls r2, r2, #8
_080CDFA6:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	adds r2, r1, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r2]
	str r0, [r1]
	b _080CE000
	.align 2, 0
_080CDFB8: .4byte 0x00004B01
_080CDFBC:
	ldr r0, _080CDFDC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CDFE4
	movs r1, #0x96
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x54]
	ldr r2, _080CDFE0 @ =0xFFFFD000
	b _080CDFF2
	.align 2, 0
_080CDFDC: .4byte pZero2
_080CDFE0: .4byte 0xFFFFD000
_080CDFE4:
	ldr r1, _080CE050 @ =0x00004B01
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
_080CDFF2:
	adds r0, r1, r2
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	str r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb8
_080CE000:
	movs r0, #0xc
	strb r0, [r4, #0x13]
	ldr r0, [r2]
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r1, [r1]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xb4
	str r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0
	bl FUN_080bf438
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE03A:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE0C4
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CE0C4
	.align 2, 0
_080CE050: .4byte 0x00004B01
_080CE054:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x46
	bl LoadBlink
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #2
	adds r0, #0x16
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080CE0CC @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE098:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080CE0D0 @ =0xFFFFE400
	adds r0, r0, r2
	cmp r1, r0
	bge _080CE0B8
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CE0B8:
	movs r0, #0x46
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CE0C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE0CC: .4byte 0xFFFFFD00
_080CE0D0: .4byte 0xFFFFE400

	thumb_func_start coffin_080ce0d4
coffin_080ce0d4: @ 0x080CE0D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080CE124
	cmp r0, #1
	bgt _080CE0EA
	cmp r0, #0
	beq _080CE0F4
	b _080CE1F2
_080CE0EA:
	cmp r0, #2
	beq _080CE158
	cmp r0, #3
	beq _080CE172
	b _080CE1F2
_080CE0F4:
	movs r0, #0x80
	bl PlaySound
	movs r0, #0x46
	bl ClearBlink
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x47
	bl LoadBlink
	movs r0, #0x10
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE124:
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bne _080CE13E
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE13E
	adds r0, r4, #0
	bl FUN_080bf390
_080CE13E:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE150
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE150:
	movs r0, #0x47
	bl UpdateBlinkMotionState
	b _080CE1F2
_080CE158:
	movs r0, #0
	strb r0, [r4, #0x13]
	movs r2, #0xf0
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #7
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE172:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bne _080CE1A0
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE1A0
	ldr r0, [r4, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	ble _080CE1A0
	adds r0, r4, #0
	bl FUN_080bf390
_080CE1A0:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	bne _080CE1CC
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r3, _080CE1C8 @ =0xFFFFFD00
	adds r0, r0, r3
	cmp r1, r0
	ble _080CE1E6
	str r0, [r4, #0x54]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080CE1E6
	.align 2, 0
_080CE1C8: .4byte 0xFFFFFD00
_080CE1CC:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	cmp r1, r0
	bge _080CE1E6
	str r0, [r4, #0x54]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CE1E6:
	movs r0, #0x47
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CE1F2:
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bne _080CE1FE
	adds r0, r4, #0
	bl FUN_080cdd64
_080CE1FE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start coffin_080ce204
coffin_080ce204: @ 0x080CE204
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CE214
	cmp r5, #1
	beq _080CE23E
	b _080CE2D4
_080CE214:
	movs r0, #0x47
	bl ClearBlink
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x46
	bl LoadBlink
	strb r5, [r4, #0x13]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE23E:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r6, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r4, #0
	adds r5, #0xb4
	cmp r0, #4
	bne _080CE25C
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	movs r2, #0
	bl FUN_080bf438
_080CE25C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CE26C
	str r1, [r4, #0x60]
_080CE26C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	cmp r1, r0
	ble _080CE2C8
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CE2C4 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	movs r0, #0x46
	bl ClearBlink
	b _080CE2E0
	.align 2, 0
_080CE2C4: .4byte gSolidFnTable
_080CE2C8:
	movs r0, #0x46
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CE2D4:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080CE2E0
	adds r0, r4, #0
	bl FUN_080cdd64
_080CE2E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
