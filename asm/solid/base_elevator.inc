	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cff48
FUN_080cff48: @ 0x080CFF48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	movs r1, #0
	strb r1, [r4, #0x12]
	adds r5, r0, #0
	adds r5, #0xbd
	ldrb r0, [r5]
	cmp r0, #0
	beq _080CFFD2
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r5]
	cmp r0, #1
	bne _080CFF80
	movs r1, #0x89
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	b _080CFFAC
_080CFF80:
	movs r1, #0x8a
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xbb
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r4, #0
	adds r1, #0xc2
	strb r0, [r1]
	ldrb r0, [r4, #0x12]
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	orrs r1, r2
	bl LoadBlink
_080CFFAC:
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
_080CFFD2:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080D0000 @ =Rect_08370730
	str r0, [r4, #0x30]
	movs r2, #1
	strh r2, [r4, #0x26]
	ldr r1, _080D0004 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl BaseElevator_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0000: .4byte Rect_08370730
_080D0004: .4byte gSolidFnTable

	thumb_func_start FUN_080d0008
FUN_080d0008: @ 0x080D0008
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	beq _080D001A
	adds r0, r1, #0
	bl FUN_080d0224
	b _080D0020
_080D001A:
	adds r0, r1, #0
	bl rBaseElevatorScript
_080D0020:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d0024
FUN_080d0024: @ 0x080D0024
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r2, [r0]
	cmp r2, #0
	beq _080D00A8
	ldrb r0, [r4, #0xd]
	ldrb r1, [r5, #0xd]
	cmp r0, r1
	beq _080D009E
	cmp r1, #0
	beq _080D006E
	cmp r2, #1
	bne _080D004C
	ldr r1, _080D0048 @ =0x00008902
	b _080D0076
	.align 2, 0
_080D0048: .4byte 0x00008902
_080D004C:
	ldrb r0, [r4, #0x12]
	bl ClearBlink
	movs r0, #0xbc
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc2
	ldrb r1, [r0]
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xbc
	bl LoadBlink
	b _080D009E
_080D006E:
	cmp r2, #1
	bne _080D007E
	movs r1, #0x89
	lsls r1, r1, #8
_080D0076:
	adds r0, r4, #0
	bl SetMotion
	b _080D009E
_080D007E:
	ldrb r0, [r4, #0x12]
	bl ClearBlink
	movs r0, #0xbb
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc2
	ldrb r1, [r0]
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xbb
	bl LoadBlink
_080D009E:
	ldrb r0, [r5, #0xd]
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D00A8:
	ldrb r0, [r4, #0x12]
	bl UpdateBlinkMotionState
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080D00D8
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080D00C6
	bl ClearBlink
_080D00C6:
	ldr r1, _080D00E0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080D00D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D00E0: .4byte gSolidFnTable

	thumb_func_start rBaseElevatorScript
rBaseElevatorScript: @ 0x080D00E4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080D016A
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D011C
	ldrb r0, [r4, #0x11]
	cmp r0, #5
	bhi _080D0110
	ldr r0, _080D010C @ =sBaseElevatorMotions
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	b _080D0122
	.align 2, 0
_080D010C: .4byte sBaseElevatorMotions
_080D0110:
	ldr r0, _080D0118 @ =sBaseElevatorMotions
	ldrh r1, [r0]
	b _080D0122
	.align 2, 0
_080D0118: .4byte sBaseElevatorMotions
_080D011C:
	cmp r0, #1
	bne _080D0130
	ldr r1, _080D012C @ =0x00008901
_080D0122:
	adds r0, r4, #0
	bl SetMotion
	b _080D0138
	.align 2, 0
_080D012C: .4byte 0x00008901
_080D0130:
	ldr r1, _080D01AC @ =0x00008A01
	adds r0, r4, #0
	bl SetMotion
_080D0138:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	str r2, [r4, #0x60]
	ldr r1, _080D01B0 @ =gOverworld
	ldr r3, _080D01B4 @ =0x0002C014
	adds r0, r1, r3
	str r2, [r0]
	adds r3, #4
	adds r0, r1, r3
	str r2, [r0]
	ldr r0, _080D01B8 @ =0x0002C01C
	adds r2, r1, r0
	movs r0, #0xf0
	lsls r0, r0, #0xe
	str r0, [r2]
	adds r3, #8
	adds r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D016A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080D0200
	ldr r0, _080D01BC @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0xc]
	ldr r0, _080D01C0 @ =0x00FFFF00
	ands r2, r0
	cmp r2, #0
	bne _080D0200
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r4, #0x11]
	adds r3, r0, #0
	ldrb r1, [r1]
	cmp r3, r1
	bls _080D01CC
	ldr r0, _080D01C4 @ =gStageRun
	ldrh r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D01CC
	ldr r0, _080D01C8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080D01F4
	.align 2, 0
_080D01AC: .4byte 0x00008A01
_080D01B0: .4byte gOverworld
_080D01B4: .4byte 0x0002C014
_080D01B8: .4byte 0x0002C01C
_080D01BC: .4byte pZero2
_080D01C0: .4byte 0x00FFFF00
_080D01C4: .4byte gStageRun
_080D01C8: .4byte 0xFFFFFE00
_080D01CC:
	adds r1, r4, #0
	adds r1, #0xc1
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bhs _080D0200
	ldr r0, _080D01FC @ =gStageRun
	ldrh r1, [r0, #4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080D0200
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080D01F4:
	adds r0, r4, #0
	bl BaseElevator_Update
	b _080D0218
	.align 2, 0
_080D01FC: .4byte gStageRun
_080D0200:
	adds r4, #0xbe
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D0218
	adds r0, r1, #0
	bl stopSound
	ldr r0, _080D0220 @ =0x0000FFFF
	strh r0, [r4]
_080D0218:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0220: .4byte 0x0000FFFF

	thumb_func_start FUN_080d0224
FUN_080d0224: @ 0x080D0224
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080D024C
	adds r5, r4, #0
	adds r5, #0xbe
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _080D0246
	movs r0, #0xa0
	bl PlaySound
	strh r0, [r5]
_080D0246:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D024C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r5, r0, r1
	str r5, [r4, #0x58]
	cmp r1, #0
	ble _080D0276
	adds r2, r4, #0
	adds r2, #0xb8
	ldrb r0, [r4, #0x11]
	adds r3, r0, #1
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #0xd
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r5, r0
	blt _080D0294
	b _080D028C
_080D0276:
	adds r2, r4, #0
	adds r2, #0xb8
	ldrb r0, [r4, #0x11]
	subs r3, r0, #1
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #0xd
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r5, r0
	bgt _080D0294
_080D028C:
	movs r0, #0
	strb r3, [r4, #0x11]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080D0294:
	ldr r2, _080D02C8 @ =gOverworld
	ldr r0, _080D02CC @ =0x0002C014
	adds r1, r2, r0
	movs r0, #0xc7
	lsls r0, r0, #0xb
	str r0, [r1]
	ldr r0, _080D02D0 @ =0x0002C01C
	adds r1, r2, r0
	movs r0, #0xcd
	lsls r0, r0, #0xb
	str r0, [r1]
	ldr r1, _080D02D4 @ =0x0002C018
	adds r3, r2, r1
	ldr r0, [r4, #0x58]
	ldr r4, _080D02D8 @ =0xFFFFC000
	adds r1, r0, r4
	str r1, [r3]
	ldr r1, _080D02DC @ =0x0002C020
	adds r2, r2, r1
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D02C8: .4byte gOverworld
_080D02CC: .4byte 0x0002C014
_080D02D0: .4byte 0x0002C01C
_080D02D4: .4byte 0x0002C018
_080D02D8: .4byte 0xFFFFC000
_080D02DC: .4byte 0x0002C020
