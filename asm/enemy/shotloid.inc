	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093930
FUN_08093930: @ 0x08093930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809398C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08093984
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093990 @ =gEnemyFnTable
	movs r1, #0x3e
	strb r1, [r3, #9]
	adds r0, #0xf8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xbd
	strb r4, [r0]
_08093984:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809398C: .4byte gZakoHeaderPtr
_08093990: .4byte gEnemyFnTable

	thumb_func_start FUN_08093994
FUN_08093994: @ 0x08093994
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080939E0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080939DA
	adds r2, r4, #0
	adds r2, #0x25
	movs r3, #0
	movs r1, #0x18
	strb r1, [r2]
	ldr r1, _080939E4 @ =gEnemyFnTable
	movs r2, #0x3e
	strb r2, [r4, #9]
	adds r1, #0xf8
	ldr r1, [r1]
	ldr r1, [r1]
	str r1, [r4, #0x14]
	movs r1, #0
	strh r3, [r4, #0x20]
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	ldrb r2, [r4, #0xb]
	movs r1, #0x10
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r1, [r4, #0x1c]
	strb r1, [r4, #0x1d]
	movs r1, #1
	strb r1, [r4, #0x10]
	str r5, [r4, #0x28]
_080939DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080939E0: .4byte gZakoHeaderPtr
_080939E4: .4byte gEnemyFnTable

	thumb_func_start FUN_080939e8
FUN_080939e8: @ 0x080939E8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08093A14 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _080939FC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_080939FC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093A18
	movs r0, #0
	b _08093A1A
	.align 2, 0
_08093A14: .4byte 0xFFFFF200
_08093A18:
	movs r0, #1
_08093A1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a20
FUN_08093a20: @ 0x08093A20
	push {lr}
	movs r3, #0
	ldr r1, _08093A50 @ =pZero2
	ldr r1, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _08093A32
	movs r3, #1
_08093A32:
	ldr r1, _08093A54 @ =0xFFFFA000
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #0xe
	adds r0, r0, r1
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08093A58 @ =0x00000FFF
	cmp r0, r1
	bls _08093A5C
	adds r0, r3, #0
	b _08093A5E
	.align 2, 0
_08093A50: .4byte pZero2
_08093A54: .4byte 0xFFFFA000
_08093A58: .4byte 0x00000FFF
_08093A5C:
	movs r0, #2
_08093A5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a64
FUN_08093a64: @ 0x08093A64
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _08093A90
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08093A8C @ =0x000007FF
	cmp r1, r0
	bgt _08093A90
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _08093A92
	.align 2, 0
_08093A8C: .4byte 0x000007FF
_08093A90:
	movs r0, #0
_08093A92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093a98
FUN_08093a98: @ 0x08093A98
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _08093AEE
	cmp r5, #0
	bge _08093AC8
	ldr r0, [r4, #0x54]
	ldr r1, _08093AC0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AC4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #1
	b _08093AF0
	.align 2, 0
_08093AC0: .4byte 0xFFFFF200
_08093AC4: .4byte 0xFFFFF600
_08093AC8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AE4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #2
	b _08093AF0
	.align 2, 0
_08093AE4: .4byte 0xFFFFF600
_08093AE8:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08093AEE:
	movs r0, #0
_08093AF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_08093af8
nop_08093af8: @ 0x08093AF8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093afc
FUN_08093afc: @ 0x08093AFC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08093B48
	ldr r1, _08093B3C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08093B40
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08093B42
	strb r4, [r2, #0xd]
	b _08093B44
	.align 2, 0
_08093B3C: .4byte gEnemyFnTable
_08093B40:
	movs r0, #1
_08093B42:
	strb r0, [r2, #0xd]
_08093B44:
	movs r0, #1
	b _08093B4A
_08093B48:
	movs r0, #0
_08093B4A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093b50
FUN_08093b50: @ 0x08093B50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _08093BD6
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _08093BD6
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08093B70
	cmp r0, #1
	beq _08093BB4
	b _08093BD6
_08093B70:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08093BD6
	ldr r1, _08093BAC @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093BB0 @ =0x08369E3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08093BA6:
	movs r0, #1
	b _08093BD8
	.align 2, 0
_08093BAC: .4byte 0x08369E18
_08093BB0: .4byte 0x08369E3C
_08093BB4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08093BD4
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093BD0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093BA6
	strb r5, [r4, #0xf]
	b _08093BD6
	.align 2, 0
_08093BD0: .4byte 0x00020001
_08093BD4:
	strb r0, [r4, #0xf]
_08093BD6:
	movs r0, #0
_08093BD8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093be0
FUN_08093be0: @ 0x08093BE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _08093C20
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093C20
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _08093C0C
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08093C20
_08093C0C:
	ldr r2, _08093C28 @ =0x08369EB4
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _08093C20
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08093C20:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093C28: .4byte 0x08369EB4

	thumb_func_start Shotloid_Init
Shotloid_Init: @ 0x08093C2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08093C3E
	movs r0, #0
	strb r0, [r5, #0x10]
	movs r0, #1
	b _08093C40
_08093C3E:
	movs r0, #0
_08093C40:
	strb r0, [r5, #0x11]
	ldr r1, _08093CC0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08093CC4 @ =0x08369EBC
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r6, [r5, #0x10]
	cmp r6, #0
	bne _08093D12
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08093CC8 @ =0x08369E6C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08093CCC @ =nop_08093af8
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	movs r2, #0
	ldr r0, _08093CD0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08093CB2
	movs r2, #1
_08093CB2:
	cmp r2, #0
	beq _08093CD4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08093CDA
	.align 2, 0
_08093CC0: .4byte gEnemyFnTable
_08093CC4: .4byte 0x08369EBC
_08093CC8: .4byte 0x08369E6C
_08093CCC: .4byte nop_08093af8
_08093CD0: .4byte pZero2
_08093CD4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08093CDA:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	bl FUN_08093994
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08093D0A
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #0
	b _08093D10
_08093D0A:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #3
_08093D10:
	strb r0, [r1]
_08093D12:
	adds r0, r5, #0
	bl Shotloid_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Shotloid_Update
Shotloid_Update: @ 0x08093D20
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08093afc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08093D66
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08093D46
	adds r0, r4, #0
	bl FUN_08093be0
	adds r0, r4, #0
	bl FUN_08093b50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08093D66
_08093D46:
	ldr r1, _08093D6C @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093D70 @ =0x08369E3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08093D66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093D6C: .4byte 0x08369E18
_08093D70: .4byte 0x08369E3C

	thumb_func_start Shotloid_Die
Shotloid_Die: @ 0x08093D74
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08093DC8
	ldr r0, _08093DC0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08093DC8
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08093DC4 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _08093DD8
	.align 2, 0
_08093DC0: .4byte gCurStory
_08093DC4: .4byte gEnemyFnTable
_08093DC8:
	ldr r0, _08093DDC @ =0x08369E60
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_08093DD8:
	pop {r0}
	bx r0
	.align 2, 0
_08093DDC: .4byte 0x08369E60

	thumb_func_start FUN_08093de0
FUN_08093de0:
	bx lr

	thumb_func_start FUN_08093de4
FUN_08093de4: @ 0x08093DE4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093E00 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093DFC
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08093DFC:
	pop {r0}
	bx r0
	.align 2, 0
_08093E00: .4byte 0x00020001

	thumb_func_start FUN_08093e04
FUN_08093e04: @ 0x08093E04
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08093E1A
	bl isKilled
	cmp r0, #0
	beq _08093E3A
_08093E1A:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08093E58 @ =0x08369E6C
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08093E3A
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093E3A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093E5C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093E50
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093E50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093E58: .4byte 0x08369E6C
_08093E5C: .4byte 0x00020001

	thumb_func_start FUN_08093e60
FUN_08093e60: @ 0x08093E60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08093E70
	cmp r5, #1
	beq _08093E98
	b _08093ED6
_08093E70:
	ldr r1, _08093EDC @ =0x00008E04
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08093EE0 @ =0x08369E84
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08093E98:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _08093ED0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08093EB4
	str r1, [r4, #0x60]
_08093EB4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08093ED0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08093ED0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08093ED6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093EDC: .4byte 0x00008E04
_08093EE0: .4byte 0x08369E84

	thumb_func_start FUN_08093ee4
FUN_08093ee4: @ 0x08093EE4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08093EF4
	cmp r0, #1
	beq _08093F14
	b _08093FDA
_08093EF4:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	movs r1, #0x8e
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08093F14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _08093F3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08093F2A
	movs r2, #1
_08093F2A:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08093F40
	cmp r2, #0
	beq _08093F44
	b _08093F4A
	.align 2, 0
_08093F3C: .4byte pZero2
_08093F40:
	cmp r2, #0
	beq _08093F4A
_08093F44:
	movs r1, #0
	movs r0, #4
	b _08093FD6
_08093F4A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08093FC4
	adds r0, r4, #0
	bl FUN_08093a20
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bne _08093F6E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08093FC4
_08093F6E:
	ldr r0, _08093FB4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, _08093FB8 @ =0xFFFFA000
	adds r1, r1, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xe
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r1
	bge _08093F8C
	movs r5, #1
_08093F8C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08093FBC
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080939e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08093FBC
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _08093FC4
	.align 2, 0
_08093FB4: .4byte pZero2
_08093FB8: .4byte 0xFFFFA000
_08093FBC:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093FC4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08093FDA
	movs r0, #5
_08093FD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093FDA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08093fe0
FUN_08093fe0: @ 0x08093FE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08093FF0
	cmp r5, #1
	beq _08094016
	b _0809410A
_08093FF0:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094058 @ =0x00008E06
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094016:
	adds r0, r4, #0
	bl FUN_08093a20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	ldr r0, _0809405C @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldr r0, _08094060 @ =0xFFFFA000
	adds r5, r5, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xe
	adds r5, r5, r0
	ldr r0, [r4, #0x54]
	subs r1, r5, r0
	cmp r1, #0
	bge _0809403E
	adds r1, #0x1f
_0809403E:
	asrs r5, r1, #5
	cmp r2, #2
	beq _08094052
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080939e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094064
_08094052:
	movs r1, #0
	movs r0, #1
	b _08094106
	.align 2, 0
_08094058: .4byte 0x00008E06
_0809405C: .4byte pZero2
_08094060: .4byte 0xFFFFA000
_08094064:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080940EC
	ldr r0, [r4, #0x5c]
	adds r1, r0, r5
	str r1, [r4, #0x5c]
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, r2
	ble _08094090
	ldr r2, _0809408C @ =0xFFFFFF00
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	b _080940A0
	.align 2, 0
_0809408C: .4byte 0xFFFFFF00
_08094090:
	ldr r0, _080940C0 @ =0xFFFFFF00
	cmp r1, r0
	bge _0809409C
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	movs r3, #1
_0809409C:
	cmp r3, #0
	beq _080940F4
_080940A0:
	ldrb r0, [r4, #0x12]
	movs r1, #7
	ands r0, r1
	strb r0, [r4, #0x12]
	movs r2, #0
	cmp r5, #0
	ble _080940B0
	movs r2, #1
_080940B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080940C4
	cmp r2, #0
	beq _080940C8
	b _080940CE
	.align 2, 0
_080940C0: .4byte 0xFFFFFF00
_080940C4:
	cmp r2, #0
	beq _080940CE
_080940C8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	b _080940D2
_080940CE:
	ldrb r0, [r4, #0x12]
	adds r0, #1
_080940D2:
	strb r0, [r4, #0x12]
	ldr r1, _080940E8 @ =0x00008E06
	ldrb r2, [r4, #0x12]
	adds r0, r4, #0
	movs r3, #1
	bl GotoMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080940F4
	.align 2, 0
_080940E8: .4byte 0x00008E06
_080940EC:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080940F4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809410A
	movs r0, #5
_08094106:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809410A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094110
FUN_08094110: @ 0x08094110
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08094120
	cmp r0, #1
	beq _0809413E
	b _0809416C
_08094120:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08094174 @ =0x00008E02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809413E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08094156
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08094156:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809416C
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809416C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094174: .4byte 0x00008E02

	thumb_func_start FUN_08094178
FUN_08094178: @ 0x08094178
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #0xe]
	cmp r3, #0
	beq _08094188
	cmp r3, #1
	beq _080941A6
	b _0809421E
_08094188:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	strb r3, [r4, #0x12]
	ldr r1, _080941D4 @ =0x00008E08
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080941A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080941F6
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _080941F6
	movs r1, #1
	strb r1, [r4, #0x12]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _080941D8
	movs r0, #0x10
	orrs r0, r2
	b _080941DC
	.align 2, 0
_080941D4: .4byte 0x00008E08
_080941D8:
	movs r0, #0xef
	ands r0, r2
_080941DC:
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
_080941F6:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08094208
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08094208:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809421E
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809421E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094224
FUN_08094224: @ 0x08094224
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08094268
	cmp r5, #1
	bgt _08094238
	cmp r5, #0
	beq _08094242
	b _0809431A
_08094238:
	cmp r5, #2
	beq _080942D0
	cmp r5, #3
	beq _080942DE
	b _0809431A
_08094242:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080942C8 @ =0x00008E04
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094268:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809428E
	ldr r3, [r4, #0x54]
	ldr r1, _080942CC @ =0xFFFFFF00
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809428C
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r3, r0
_0809428C:
	str r2, [r4, #0x54]
_0809428E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809429E
	str r1, [r4, #0x60]
_0809429E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809431A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809431A
	.align 2, 0
_080942C8: .4byte 0x00008E04
_080942CC: .4byte 0xFFFFFF00
_080942D0:
	ldr r1, _08094300 @ =0x00008E05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080942DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _08094312
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r0, [r1]
	cmp r0, #0
	bne _08094304
	movs r0, #1
	strb r0, [r1]
	movs r0, #8
	b _0809430C
	.align 2, 0
_08094300: .4byte 0x00008E05
_08094304:
	cmp r0, #2
	bne _0809430A
	strb r2, [r1]
_0809430A:
	movs r0, #1
_0809430C:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08094312:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
_0809431A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094320
FUN_08094320: @ 0x08094320
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _08094374
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08094370 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08094522
	.align 2, 0
_08094370: .4byte gEnemyFnTable
_08094374:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094380
	cmp r5, #1
	beq _080943BC
	b _08094522
_08094380:
	adds r0, r4, #0
	bl InitRotatableMotion
	ldr r1, _080944B4 @ =0x00008E01
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1a
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	eors r0, r1
	ands r0, r1
	strb r0, [r4, #0x12]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #9
	subs r1, r1, r0
	str r1, [r4, #0x64]
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #7
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080943BC:
	ldr r0, [r6, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080944B8 @ =0xFFFFF300
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080943D4
	b _080944F4
_080943D4:
	adds r7, r6, #0
	adds r7, #0xb8
	ldr r2, [r7]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080944CC
	ldrb r1, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x54]
	mov r8, r2
	ldr r3, [r4, #0x58]
	mov sb, r3
	ldr r0, _080944BC @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	subs r5, r5, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #5
	cmp r0, #0
	bge _08094404
	adds r0, #0xff
_08094404:
	asrs r5, r0, #8
	adds r0, r5, #0
	movs r1, #0x1e
	bl __divsi3
	adds r5, r0, #0
	ldr r0, _080944C0 @ =0xFFFFFD00
	cmp r5, r0
	bge _08094418
	adds r5, r0, #0
_08094418:
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r5, r0
	ble _08094422
	adds r5, r0, #0
_08094422:
	ldr r0, _080944C4 @ =0xFFFFFC40
	mov sl, r0
	ldr r1, [r4, #0x64]
	subs r0, r5, r1
	cmp r0, #0
	bge _08094430
	adds r0, #0xf
_08094430:
	asrs r0, r0, #4
	adds r0, r1, r0
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x68]
	mov r3, sl
	subs r1, r3, r2
	cmp r1, #0
	bge _08094442
	adds r1, #0xf
_08094442:
	asrs r1, r1, #4
	adds r1, r2, r1
	str r1, [r4, #0x68]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsrs r0, r0, #8
	strb r0, [r4, #0x13]
	ldr r0, [r7]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08094512
	movs r0, #0x2d
	bl PlaySound
	ldr r0, [r7]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r2, _080944C8 @ =gSineTable
	ldrb r0, [r4, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	add r8, r0
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	add sb, r0
	ldrb r0, [r6, #0x11]
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	adds r2, r5, #0
	mov r3, sl
	bl FUN_080b1234
	b _08094512
	.align 2, 0
_080944B4: .4byte 0x00008E01
_080944B8: .4byte 0xFFFFF300
_080944BC: .4byte pZero2
_080944C0: .4byte 0xFFFFFD00
_080944C4: .4byte 0xFFFFFC40
_080944C8: .4byte gSineTable
_080944CC:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x64]
	adds r3, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080944E0
	ldr r3, _080944F0 @ =0xFFFFFF00
_080944E0:
	str r3, [r4, #0x64]
	str r2, [r4, #0x68]
	adds r0, r3, #0
	movs r1, #0
	bl ArcTan2
	strb r0, [r4, #0x13]
	b _0809450A
	.align 2, 0
_080944F0: .4byte 0xFFFFFF00
_080944F4:
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809450A
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08094510
_0809450A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08094510:
	strb r0, [r4, #0xa]
_08094512:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
_08094522:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094534
FUN_08094534:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0xA8, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28
	.byte 0x4B, 0xD0, 0x9C, 0xE0, 0x28, 0x1C, 0x74, 0x30, 0x1C, 0x49, 0x72, 0xF7, 0x63, 0xFE, 0x1C, 0x49
	.byte 0x28, 0x1C, 0x83, 0xF7, 0x09, 0xF8, 0x28, 0x1C, 0x83, 0xF7, 0x80, 0xF8, 0x19, 0x48, 0x02, 0x68
	.byte 0x69, 0x6D, 0x50, 0x6D, 0x09, 0x1A, 0xE9, 0x65, 0xA8, 0x6D, 0x17, 0x4B, 0xC0, 0x18, 0x92, 0x6D
	.byte 0x80, 0x1A, 0x28, 0x66, 0x09, 0x12, 0x0E, 0x1C, 0x4E, 0x43, 0x00, 0x12, 0x01, 0x1C, 0x41, 0x43
	.byte 0x08, 0x1C, 0x36, 0x18, 0x30, 0x1C, 0x69, 0xF0, 0xE1, 0xFF, 0x00, 0x04, 0x06, 0x0A, 0x00, 0x2E
	.byte 0x1C, 0xD0, 0xE8, 0x6D, 0x00, 0x02, 0x31, 0x1C, 0x6A, 0xF0, 0xC2, 0xF8, 0x04, 0x1C, 0xEC, 0x65
	.byte 0x28, 0x6E, 0x00, 0x02, 0x31, 0x1C, 0x6A, 0xF0, 0xBB, 0xF8, 0x61, 0x00, 0x09, 0x19, 0x49, 0x00
	.byte 0xE9, 0x65, 0x41, 0x00, 0x09, 0x18, 0x49, 0x00, 0x29, 0x66, 0x0B, 0xE0, 0x9C, 0x9E, 0x36, 0x08
	.byte 0x09, 0x8E, 0x00, 0x00, 0x40, 0xF3, 0x02, 0x02, 0x00, 0xE8, 0xFF, 0xFF, 0xC0, 0x20, 0xC0, 0x00
	.byte 0xE8, 0x65, 0x2E, 0x66, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C, 0x83, 0xF7, 0x3E, 0xF8
	.byte 0xE9, 0x6D, 0x28, 0x1C, 0xFF, 0xF7, 0x58, 0xFA, 0x00, 0x06, 0x00, 0x28, 0x06, 0xD1, 0x2E, 0x1C
	.byte 0x8C, 0x36, 0x34, 0x68, 0x04, 0x20, 0x04, 0x40, 0x00, 0x2C, 0x03, 0xD0, 0x28, 0x1C, 0x00, 0xF0
	.byte 0xE1, 0xF8, 0x3C, 0xE0, 0x28, 0x6E, 0x40, 0x30, 0x28, 0x66, 0xE0, 0x21, 0xC9, 0x00, 0x88, 0x42
	.byte 0x00, 0xDD, 0x29, 0x66, 0xA9, 0x6D, 0x28, 0x6E, 0x09, 0x18, 0xA9, 0x65, 0x68, 0x6D, 0x75, 0xF7
	.byte 0xB7, 0xF9, 0x01, 0x1C, 0x00, 0x29, 0x05, 0xDA, 0xA8, 0x6D, 0x40, 0x18, 0xA8, 0x65, 0x28, 0x1C
	.byte 0x00, 0xF0, 0xC8, 0xF8, 0x68, 0x7C, 0x00, 0x28, 0x21, 0xD0, 0x12, 0x48, 0x29, 0x1C, 0x54, 0x31
	.byte 0x86, 0xF7, 0xE6, 0xF8, 0xC0, 0x21, 0xC9, 0x01, 0x88, 0x42, 0x18, 0xD9, 0xA9, 0x7A, 0xFE, 0x20
	.byte 0x08, 0x40, 0xFD, 0x21, 0x08, 0x40, 0xA8, 0x72, 0x34, 0x60, 0x28, 0x1C, 0x90, 0x30, 0x04, 0x60
	.byte 0x04, 0x30, 0x04, 0x70, 0xA9, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0xA8, 0x72, 0x06, 0x49, 0x68, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x03, 0x21, 0xE9, 0x60, 0x00, 0x68, 0xC0, 0x68, 0x68, 0x61, 0x70, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x48, 0xFF, 0x02, 0x02, 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0809468c
FUN_0809468c: @ 0x0809468C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809469C
	cmp r0, #1
	beq _08094714
	b _080947B8
_0809469C:
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080946CC @ =0x00008E06
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xbd
	ldrb r1, [r2]
	movs r0, #1
	adds r3, r0, #0
	eors r3, r1
	adds r6, r2, #0
	cmp r3, #0
	beq _080946D0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080946D6
	.align 2, 0
_080946CC: .4byte 0x00008E06
_080946D0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080946D6:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r3
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	ldrb r0, [r6]
	lsls r0, r0, #9
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	str r4, [r5, #0x60]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08094714:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809479A
	movs r4, #0
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	adds r2, r0, r1
	str r2, [r5, #0x60]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r6, r1, #0
	cmp r2, r3
	ble _08094744
	ldr r1, _08094740 @ =0xFFFFFF00
	adds r0, r2, r1
	str r0, [r5, #0x60]
	b _08094754
	.align 2, 0
_08094740: .4byte 0xFFFFFF00
_08094744:
	ldr r0, _08094774 @ =0xFFFFFF00
	cmp r2, r0
	bge _08094750
	adds r0, r2, r3
	str r0, [r5, #0x60]
	movs r4, #1
_08094750:
	cmp r4, #0
	beq _0809479A
_08094754:
	ldrb r0, [r5, #0x12]
	movs r1, #7
	ands r0, r1
	strb r0, [r5, #0x12]
	movs r2, #0
	cmp r6, #0
	ble _08094764
	movs r2, #1
_08094764:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08094778
	cmp r2, #0
	beq _0809477C
	b _08094782
	.align 2, 0
_08094774: .4byte 0xFFFFFF00
_08094778:
	cmp r2, #0
	beq _08094782
_0809477C:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	b _08094786
_08094782:
	ldrb r0, [r5, #0x12]
	adds r0, #1
_08094786:
	strb r0, [r5, #0x12]
	ldr r1, _080947C0 @ =0x00008E06
	ldrb r2, [r5, #0x12]
	adds r0, r5, #0
	movs r3, #1
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0809479A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080947B8
	adds r0, r5, #0
	adds r0, #0xbc
	movs r1, #2
	strb r1, [r0]
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
_080947B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080947C0: .4byte 0x00008E06

	thumb_func_start FUN_080947c4
FUN_080947c4: @ 0x080947C4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08094814 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _0809481C
	ldr r2, _08094818 @ =0x08369EBE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7f70
	b _08094828
	.align 2, 0
_08094814: .4byte 0xFFFFF000
_08094818: .4byte 0x08369EBE
_0809481C:
	ldr r2, _08094864 @ =0x08369EBE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7ffc
_08094828:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08094868 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0809486C @ =0x0000270E
	cmp r1, r0
	bhi _08094842
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08094842:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08094870 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094864: .4byte 0x08369EBE
_08094868: .4byte gMission
_0809486C: .4byte 0x0000270E
_08094870: .4byte gEnemyFnTable

	thumb_func_start FUN_08094874
FUN_08094874: @ 0x08094874
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094888
	cmp r5, #1
	bne _08094886
	b _08094988
_08094886:
	b _080949C6
_08094888:
	movs r6, #0
	ldr r0, _0809490C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809489A
	movs r6, #1
_0809489A:
	ldr r1, _08094910 @ =0x00008E0A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r1, r1, r0
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094934
	movs r0, #0x20
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08094918
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094914 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b84f4
	b _0809496E
	.align 2, 0
_0809490C: .4byte pZero2
_08094910: .4byte 0x00008E0A
_08094914: .4byte 0x08369EC6
_08094918:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094930 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b857c
	b _0809496E
	.align 2, 0
_08094930: .4byte 0x08369EC6
_08094934:
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08094958
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094954 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	b _0809496E
	.align 2, 0
_08094954: .4byte 0x08369EC6
_08094958:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _080949D0 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_0809496E:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _08094976
	adds r0, #3
_08094976:
	asrs r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094988:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _080949AC
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080949A4
	str r1, [r4, #0x60]
_080949A4:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08093a64
_080949AC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080949C6
	adds r0, r4, #0
	bl FUN_080947c4
_080949C6:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080949D0: .4byte 0x08369EC6
