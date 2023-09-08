	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080665ec
FUN_080665ec: @ 0x080665EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0806666C
	cmp r5, #1
	bgt _08066600
	cmp r5, #0
	beq _08066606
	b _080667A8
_08066600:
	cmp r5, #2
	beq _080666E6
	b _080667A8
_08066606:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	bne _08066638
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	str r2, [r4, #0x5c]
	ldr r0, _08066634 @ =0xFFFFFF00
	b _08066660
	.align 2, 0
_08066634: .4byte 0xFFFFFF00
_08066638:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	str r5, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
_08066660:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806666C:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bge _08066698
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xbc
	strb r2, [r0]
	b _080666C4
_08066698:
	movs r3, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strb r3, [r0]
_080666C4:
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xbd
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806671C @ =0x08365D64
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080666E6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r1, #0
	bge _080666F8
	rsbs r1, r1, #0
_080666F8:
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r5]
	movs r0, #0xa8
	lsls r0, r0, #7
	cmp r1, r0
	ble _08066720
	ldr r0, [r4, #0x64]
	asrs r0, r0, #2
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #5
	b _08066728
	.align 2, 0
_0806671C: .4byte 0x08365D64
_08066720:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #4
_08066728:
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08066764
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bne _08066792
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _08066760 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToLeft1
	b _0806678C
	.align 2, 0
_08066760: .4byte 0xFFFFF000
_08066764:
	ldr r0, [r4, #0x54]
	ldr r1, _080667B0 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	bne _08066792
	ldr r0, [r4, #0x54]
	ldr r1, _080667B0 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080667B0 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToRight1
_0806678C:
	adds r1, r0, #0
	cmp r1, #0
	beq _08066798
_08066792:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08066798:
	ldr r1, [r5]
	ldr r0, _080667B4 @ =0x00005FFF
	cmp r1, r0
	ble _080667A8
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080667A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080667B0: .4byte 0xFFFFF000
_080667B4: .4byte 0x00005FFF

	thumb_func_start FUN_080667b8
FUN_080667b8: @ 0x080667B8
	movs r0, #1
	bx lr

	thumb_func_start shotcounter_080667bc
shotcounter_080667bc: @ 0x080667BC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _080667CA
	b _08066964
_080667CA:
	lsls r0, r0, #2
	ldr r1, _080667D4 @ =_080667D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080667D4: .4byte _080667D8
_080667D8: @ jump table
	.4byte _080667FC @ case 0
	.4byte _08066826 @ case 1
	.4byte _08066900 @ case 2
	.4byte _0806686C @ case 3
	.4byte _0806687E @ case 4
	.4byte _080668F6 @ case 5
	.4byte _08066900 @ case 6
	.4byte _08066928 @ case 7
	.4byte _0806693C @ case 8
_080667FC:
	ldr r1, _08066860 @ =0x00000401
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08066864 @ =0x00000103
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xbd
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066868 @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066826:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08066846
	adds r1, r5, #0
	adds r1, #0xbd
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066868 @ =0x08365E0C
	bl SetDDP
_08066846:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08066858
	b _08066964
_08066858:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	b _08066920
	.align 2, 0
_08066860: .4byte 0x00000401
_08066864: .4byte 0x00000103
_08066868: .4byte 0x08365E0C
_0806686C:
	ldr r1, _080668B0 @ =0x00000402
	adds r0, r5, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806687E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080668E4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080668E4
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	add r1, sp, #8
	str r2, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	adds r3, r0, #0
	cmp r2, #0
	bne _080668BC
	ldr r0, [r5, #0x54]
	ldr r2, _080668B4 @ =0xFFFFF200
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, _080668B8 @ =0xFFFFFD80
	b _080668CA
	.align 2, 0
_080668B0: .4byte 0x00000402
_080668B4: .4byte 0xFFFFF200
_080668B8: .4byte 0xFFFFFD80
_080668BC:
	ldr r0, [r5, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
_080668CA:
	str r0, [sp, #8]
	ldrb r2, [r3]
	mov r0, sp
	movs r3, #0
	bl CreateShotcounterBullet
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2c
	bl PlaySound
_080668E4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066964
	b _08066920
_080668F6:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066900:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08066920
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08066964
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08066964
_08066920:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08066964
_08066928:
	ldr r1, _0806696C @ =0x00000403
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08066970 @ =0x00000103
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806693C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r6, [r0]
	cmp r6, #3
	bne _08066964
	adds r1, r5, #0
	adds r1, #0xbd
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066974 @ =0x08365D64
	bl SetDDP
	strb r6, [r5, #0xd]
	strb r4, [r5, #0xe]
_08066964:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806696C: .4byte 0x00000403
_08066970: .4byte 0x00000103
_08066974: .4byte 0x08365D64

	thumb_func_start nop_08066978
nop_08066978: @ 0x08066978
	movs r0, #1
	bx lr

	thumb_func_start shotcounter_0806697c
shotcounter_0806697c: @ 0x0806697C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08066A10
	cmp r5, #1
	bgt _08066990
	cmp r5, #0
	beq _0806699C
	b _08066AC8
_08066990:
	cmp r5, #2
	beq _08066A34
	cmp r5, #3
	bne _0806699A
	b _08066AA8
_0806699A:
	b _08066AC8
_0806699C:
	ldr r1, _080669D0 @ =0x00000404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	bne _080669D4
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	str r2, [r4, #0x5c]
	b _080669F8
	.align 2, 0
_080669D0: .4byte 0x00000404
_080669D4:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	str r5, [r4, #0x5c]
_080669F8:
	movs r1, #0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb8
	str r1, [r0]
	subs r0, #0x44
	ldr r1, _08066A30 @ =0x08365DDC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066A10:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066AC8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08066AC8
	.align 2, 0
_08066A30: .4byte 0x08365DDC
_08066A34:
	ldr r1, _08066A70 @ =0x00000405
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
	adds r2, r0, #0
	cmp r2, #0
	bne _08066A74
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	str r2, [r4, #0x5c]
	b _08066A9E
	.align 2, 0
_08066A70: .4byte 0x00000405
_08066A74:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	str r3, [r4, #0x5c]
_08066A9E:
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066AA8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066AC8
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08066AC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08066ad0
FUN_08066ad0: @ 0x08066AD0
	movs r0, #1
	bx lr

	thumb_func_start FUN_08066ad4
FUN_08066ad4: @ 0x08066AD4
	bx lr
	.align 2, 0

	thumb_func_start FUN_08066ad8
FUN_08066ad8: @ 0x08066AD8
	movs r0, #1
	bx lr

	thumb_func_start FUN_08066adc
FUN_08066adc: @ 0x08066ADC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _08066AF6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B28 @ =0x08365E24
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066AF6:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _08066B20
	adds r1, r5, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r4]
	movs r4, #1
	strb r4, [r5, #0xd]
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B2C @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0xe]
_08066B20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066B28: .4byte 0x08365E24
_08066B2C: .4byte 0x08365E0C

	thumb_func_start FUN_08066b30
FUN_08066b30: @ 0x08066B30
	movs r0, #1
	bx lr

	thumb_func_start FUN_08066b34
FUN_08066b34: @ 0x08066B34
	bx lr
	.align 2, 0

	thumb_func_start FUN_08066b38
FUN_08066b38: @ 0x08066B38
	movs r0, #1
	bx lr

	thumb_func_start FUN_08066b3c
FUN_08066b3c: @ 0x08066B3C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08066B4C
	cmp r4, #1
	beq _08066B5E
	b _08066BA8
_08066B4C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B98 @ =0x08365E24
	bl SetDDP
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066B5E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08066B6E
	str r1, [r5, #0x60]
_08066B6E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08066BA0
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	ldr r1, _08066B9C @ =0xFFFFF000
	b _08066BA4
	.align 2, 0
_08066B98: .4byte 0x08365E24
_08066B9C: .4byte 0xFFFFF000
_08066BA0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
_08066BA4:
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08066BA8:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _08066BD2
	adds r1, r5, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r4]
	movs r4, #1
	strb r4, [r5, #0xd]
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066BD8 @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0xe]
_08066BD2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066BD8: .4byte 0x08365E0C

	thumb_func_start FUN_08066bdc
FUN_08066bdc: @ 0x08066BDC
	movs r0, #1
	bx lr

	thumb_func_start shotcounter_08066be0
shotcounter_08066be0: @ 0x08066BE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08066BF0
	cmp r0, #1
	beq _08066C12
	b _08066D9A
_08066BF0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08066D2C @ =0x08365E54
	bl SetDDP
	ldr r0, _08066D30 @ =pZero2
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0xf]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08066C12:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	adds r1, r1, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C3E
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	bne _08066C3E
	b _08066D7C
_08066C3E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	ldr r1, _08066D34 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C6C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	bne _08066C6C
	b _08066D7C
_08066C6C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	ldr r2, _08066D34 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066C98
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08066D7C
_08066C98:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	ldr r3, _08066D34 @ =0xFFFFF000
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	adds r1, r1, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08066CC0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08066D7C
_08066CC0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r1, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	lsls r0, r2, #4
	subs r0, r2, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x60]
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08066CFC
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08066CFC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08066D9A
	adds r0, r4, #0
	adds r0, #0xb8
	str r1, [r0]
	ldr r2, [r5]
	cmp r2, #0
	beq _08066D70
	adds r0, #7
	ldrb r2, [r0]
	cmp r2, #1
	bne _08066D38
	subs r0, #0x1b
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	ble _08066D7C
	movs r0, #5
	b _08066D6A
	.align 2, 0
_08066D2C: .4byte 0x08365E54
_08066D30: .4byte pZero2
_08066D34: .4byte 0xFFFFF000
_08066D38:
	cmp r2, #2
	bne _08066D5C
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	bgt _08066D58
	ldr r1, _08066D54 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08066D88
	.align 2, 0
_08066D54: .4byte gEnemyFnTable
_08066D58:
	movs r0, #7
	b _08066D6A
_08066D5C:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	ble _08066D7C
	movs r0, #1
_08066D6A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08066D9A
_08066D70:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	bgt _08066D94
_08066D7C:
	ldr r1, _08066D90 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08066D88:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08066D9A
	.align 2, 0
_08066D90: .4byte gEnemyFnTable
_08066D94:
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08066D9A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start shotcounter_08066da0
shotcounter_08066da0: @ 0x08066DA0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r5, [r6]
	cmp r5, #0
	bne _08066E2A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08066E2A
	ldr r2, _08066DEC @ =0x08365E84
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08066E04
	cmp r1, #0
	beq _08066E2A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08066DF0
	adds r0, r4, #0
	adds r0, #0xbf
	strb r7, [r0]
	movs r0, #5
	b _08066DFE
	.align 2, 0
_08066DEC: .4byte 0x08365E84
_08066DF0:
	cmp r1, #0x30
	bne _08066E2A
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #2
	strb r0, [r1]
	movs r0, #7
_08066DFE:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08066E2A
_08066E04:
	cmp r1, #0
	beq _08066E2A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08066E1E
	adds r0, r4, #0
	adds r0, #0xbf
	strb r7, [r0]
	b _08066E2A
_08066E1E:
	cmp r1, #0x30
	bne _08066E2A
	adds r1, r4, #0
	adds r1, #0xbf
	movs r0, #2
	strb r0, [r1]
_08066E2A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08066e34
FUN_08066e34: @ 0x08066E34
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08066E4C
	cmp r0, #0xe
	beq _08066E4C
	cmp r0, #0xf
	bne _08066E76
_08066E4C:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08066E76
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08066E6E
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #0xff
	b _08066E74
_08066E6E:
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #0xfe
_08066E74:
	strb r0, [r1]
_08066E76:
	ldr r0, [r3, #4]
	ldr r1, _08066F00 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08066F44
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08066F44
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08066EAC
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08066EAC
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #1
	strh r0, [r1]
_08066EAC:
	ldr r6, _08066F04 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r4, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _08066F08
	ldr r0, [r4, #0x64]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	b _08066F24
	.align 2, 0
_08066F00: .4byte 0x000200FF
_08066F04: .4byte pZero2
_08066F08:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08066F1C
	ldr r0, _08066F18 @ =0xFFFFFF00
	b _08066F20
	.align 2, 0
_08066F18: .4byte 0xFFFFFF00
_08066F1C:
	movs r0, #0x80
	lsls r0, r0, #1
_08066F20:
	str r0, [r4, #0x64]
	str r5, [r4, #0x68]
_08066F24:
	ldr r1, [r4, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08066F44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
