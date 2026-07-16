	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitMode7
cubitMode7: @ 0x08053728
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x15
	bls _08053734
	b _08053A00
_08053734:
	lsls r0, r0, #2
	ldr r1, _08053740 @ =_08053744
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053740: .4byte _08053744
_08053744: @ jump table
	.4byte _0805379C @ case 0
	.4byte _080537C8 @ case 1
	.4byte _080537D6 @ case 2
	.4byte _08053832 @ case 3
	.4byte _08053878 @ case 4
	.4byte _08053886 @ case 5
	.4byte _080538A0 @ case 6
	.4byte _080538C6 @ case 7
	.4byte _08053940 @ case 8
	.4byte _0805394E @ case 9
	.4byte _08053968 @ case 10
	.4byte _08053886 @ case 11
	.4byte _0805398C @ case 12
	.4byte _0805399E @ case 13
	.4byte _080539C0 @ case 14
	.4byte _08053886 @ case 15
	.4byte _080539C8 @ case 16
	.4byte _08053886 @ case 17
	.4byte _080539DC @ case 18
	.4byte _08053886 @ case 19
	.4byte _080539E4 @ case 20
	.4byte _080539F8 @ case 21
_0805379C:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	ble _080537B6
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080537B4
	b _080539F0
_080537B4:
	b _080537C2
_080537B6:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080537C2
	b _080539F0
_080537C2:
	movs r0, #3
	strb r0, [r4, #0xe]
	b _08053A00
_080537C8:
	ldr r1, _08053824 @ =0x0000B003
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080537D6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080537E8
	b _08053A00
_080537E8:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08053828
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805382E
	.align 2, 0
_08053824: .4byte 0x0000B003
_08053828:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805382E:
	strb r0, [r4, #0xa]
	b _080539F0
_08053832:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053854
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053850 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053864
	.align 2, 0
_08053850: .4byte 0xFFFFF800
_08053854:
	ldr r0, [r4, #0x54]
	ldr r1, _08053870 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053874 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053864:
	cmp r0, #0
	bne _0805386A
	b _080539F0
_0805386A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08053A00
	.align 2, 0
_08053870: .4byte 0xFFFFE400
_08053874: .4byte 0xFFFFF800
_08053878:
	ldr r1, _0805389C @ =0x0000B004
_0805387A:
	adds r0, r4, #0
	bl SetMotion
_08053880:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053886:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053898
	b _08053A00
_08053898:
	b _080539F0
	.align 2, 0
_0805389C: .4byte 0x0000B004
_080538A0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080538B0
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080538B2
_080538B0:
	ldr r0, _080538F4 @ =0xFFFFFD00
_080538B2:
	str r0, [r4, #0x5c]
	ldr r0, _080538F8 @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldr r1, _080538FC @ =0x0000B005
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080538C6:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r3, r0, r1
	str r3, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053904
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r2, _08053900 @ =0xFFFFF800
	adds r1, r3, r2
	bl PushoutToLeft1
	b _08053910
	.align 2, 0
_080538F4: .4byte 0xFFFFFD00
_080538F8: .4byte 0xFFFFFE00
_080538FC: .4byte 0x0000B005
_08053900: .4byte 0xFFFFF800
_08053904:
	ldr r1, _08053938 @ =0xFFFFE800
	adds r0, r2, r1
	ldr r2, _0805393C @ =0xFFFFF800
	adds r1, r3, r2
	bl PushoutToRight1
_08053910:
	adds r1, r0, #0
	cmp r1, #0
	beq _0805391C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0805391C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08053A00
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080539F0
	.align 2, 0
_08053938: .4byte 0xFFFFE800
_0805393C: .4byte 0xFFFFF800
_08053940:
	ldr r1, _08053964 @ =0x0000B006
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805394E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08053A00
	strb r0, [r4, #0xe]
	b _08053A00
	.align 2, 0
_08053964: .4byte 0x0000B006
_08053968:
	ldr r1, _08053988 @ =0x0000B00D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #9
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	movs r0, #0xcd
	bl PlaySound
	adds r0, r4, #0
	bl FUN_080a5fc4
	b _08053880
	.align 2, 0
_08053988: .4byte 0x0000B00D
_0805398C:
	ldr r1, _080539BC @ =0x0000B00E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #7
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805399E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080539B4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053A00
_080539B4:
	movs r0, #9
	strb r0, [r4, #0x12]
	b _080539F0
	.align 2, 0
_080539BC: .4byte 0x0000B00E
_080539C0:
	ldr r1, _080539C4 @ =0x0000B007
	b _0805387A
	.align 2, 0
_080539C4: .4byte 0x0000B007
_080539C8:
	ldr r1, _080539D8 @ =0x0000B008
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08053880
	.align 2, 0
_080539D8: .4byte 0x0000B008
_080539DC:
	ldr r1, _080539E0 @ =0x0000B009
	b _0805387A
	.align 2, 0
_080539E0: .4byte 0x0000B009
_080539E4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080539F0
	movs r0, #0xe
	strb r0, [r4, #0xe]
	b _08053A00
_080539F0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08053A00
_080539F8:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08053A00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

