	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080795f0
FUN_080795f0: @ 0x080795F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bls _08079606
	bl _0807A004
_08079606:
	lsls r0, r0, #2
	ldr r1, _08079610 @ =_08079614
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08079610: .4byte _08079614
_08079614: @ jump table
	.4byte _08079628 @ case 0
	.4byte _0807965E @ case 1
	.4byte _080796D8 @ case 2
	.4byte _08079D58 @ case 3
	.4byte _08079D7C @ case 4
_08079628:
	adds r1, r7, #0
	adds r1, #0xb9
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080796C8 @ =0x083675CC
	bl SetDDP
	str r4, [r7, #0x5c]
	str r4, [r7, #0x60]
	ldr r0, [r7, #0x58]
	ldr r1, _080796CC @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r7, #0x68]
	movs r0, #8
	strb r0, [r7, #0x12]
	movs r0, #0x14
	strb r0, [r7, #0x13]
	ldr r1, _080796D0 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0807965E:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r2, _080796D4 @ =0xFFFFE800
	adds r1, r1, r2
	bl PushoutToDown2
	adds r1, r0, #0
	cmp r1, #0
	beq _08079682
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_08079682:
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080796A2
	cmp r0, #1
	bne _080796A8
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _080796A8
_080796A2:
	adds r0, r7, #0
	bl UpdateEntityAnim
_080796A8:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080796B2
	bl _0807A004
_080796B2:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080796C0
	bl _0807A004
_080796C0:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	bl _0807A002
	.align 2, 0
_080796C8: .4byte 0x083675CC
_080796CC: .4byte 0xFFFFF000
_080796D0: .4byte 0x00003501
_080796D4: .4byte 0xFFFFE800
_080796D8:
	ldr r0, _08079724 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	adds r5, r2, #0
	ldr r0, [r7, #0x58]
	ldr r3, _08079728 @ =0xFFFFF000
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	adds r6, r1, #0
	cmp r2, #0
	bne _080796F8
	cmp r1, #0
	beq _0807972C
_080796F8:
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r5, #8
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r6, #8
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	b _08079730
	.align 2, 0
_08079724: .4byte pZero2
_08079728: .4byte 0xFFFFF000
_0807972C:
	movs r5, #0x80
	lsls r5, r5, #1
_08079730:
	lsls r0, r5, #9
	asrs r3, r0, #8
	str r3, [r7, #0x64]
	lsls r0, r6, #9
	asrs r2, r0, #8
	str r2, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0xb9
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #1
	bne _080797B6
	ldr r1, [r7, #0x5c]
	subs r0, r3, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	subs r0, r2, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r5, r1, r0
	str r5, [r7, #0x60]
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldrb r4, [r7, #0x12]
	adds r0, r4, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08079784
	adds r0, r4, #0
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079790
_08079784:
	ldr r1, _0807978C @ =0xFFFFFEE0
	adds r0, r5, r1
	str r0, [r7, #0x60]
	b _080797D2
	.align 2, 0
_0807978C: .4byte 0xFFFFFEE0
_08079790:
	adds r0, r4, #0
	movs r1, #0x46
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080797AC
	adds r0, r4, #0
	movs r1, #0x5a
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080797D2
_080797AC:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	str r0, [r7, #0x60]
	b _080797D2
_080797B6:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080797D2
	str r1, [r7, #0x60]
_080797D2:
	ldr r0, [r7, #0x58]
	ldr r3, _080797E8 @ =0xFFFFF400
	adds r4, r0, r3
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	cmp r1, #0
	bge _080797EC
	adds r1, r0, r3
	b _080797F2
	.align 2, 0
_080797E8: .4byte 0xFFFFF400
_080797EC:
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r0, r2
_080797F2:
	adds r0, r1, #0
	adds r1, r4, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08079890
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079820
	ldr r0, [r7, #0x54]
	ldr r3, _0807981C @ =0xFFFFF400
	adds r0, r0, r3
	adds r1, r4, #0
	bl PushoutToRight2
	b _0807982E
	.align 2, 0
_0807981C: .4byte 0xFFFFF400
_08079820:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r4, #0
	bl PushoutToLeft2
_0807982E:
	adds r1, r0, #0
	cmp r1, #0
	beq _0807983A
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0807983A:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079870
	ldr r2, _08079864 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079868 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _0807986C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0xc0
	lsls r1, r1, #1
	subs r1, r1, r0
	str r1, [r7, #0x5c]
	b _08079890
	.align 2, 0
_08079864: .4byte RNG_0202f388
_08079868: .4byte 0x000343FD
_0807986C: .4byte 0x00269EC3
_08079870:
	ldr r2, _080798E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080798EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080798F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x60
	bl __umodsi3
	ldr r2, _080798F4 @ =0xFFFFFE80
	adds r0, r0, r2
	str r0, [r7, #0x5c]
_08079890:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r4, _080798F8 @ =0xFFFFF800
	adds r1, r1, r4
	bl FUN_0800a05c
	str r0, [sp]
	ldr r0, [r7, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r0, r3
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl FUN_0800a05c
	str r0, [sp, #4]
	ldr r0, [r7, #0x54]
	ldr r1, _080798FC @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl FUN_0800a05c
	adds r1, r0, #0
	str r1, [sp, #8]
	movs r2, #0
	ldr r0, [sp]
	cmp r0, #0
	bne _080798D4
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _080798D4
	cmp r1, #0
	beq _08079908
_080798D4:
	ldr r1, [sp]
	ldr r0, [sp, #4]
	cmp r1, r0
	bge _08079900
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _08079908
	adds r2, r1, #0
	b _08079908
	.align 2, 0
_080798E8: .4byte RNG_0202f388
_080798EC: .4byte 0x000343FD
_080798F0: .4byte 0x00269EC3
_080798F4: .4byte 0xFFFFFE80
_080798F8: .4byte 0xFFFFF800
_080798FC: .4byte 0xFFFFF400
_08079900:
	ldr r2, [sp, #8]
	cmp r0, r2
	bge _08079908
	adds r2, r0, #0
_08079908:
	ldr r0, [r7, #0x58]
	subs r0, r2, r0
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08079934
	ldr r0, [r7, #0x60]
	cmp r0, r1
	ble _0807991C
	str r1, [r7, #0x60]
_0807991C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r3, _08079930 @ =0xFFFFF400
	adds r1, r2, r3
	cmp r0, r1
	ble _0807993A
	str r1, [r7, #0x58]
	b _0807993A
	.align 2, 0
_08079930: .4byte 0xFFFFF400
_08079934:
	ldr r1, _0807998C @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r7, #0x58]
_0807993A:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r6, _08079990 @ =0xFFFFE800
	adds r1, r1, r6
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _0807995C
	cmp r5, #0
	beq _080799B4
_0807995C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08079994 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r6
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079980
	subs r1, r4, r0
_08079980:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079998
	cmp r1, r2
	blt _0807999E
	b _080799A8
	.align 2, 0
_0807998C: .4byte 0xFFFFF400
_08079990: .4byte 0xFFFFE800
_08079994: .4byte 0xFFFFF800
_08079998:
	subs r0, r5, r0
	cmp r1, r0
	bge _080799A8
_0807999E:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _080799B4
_080799A8:
	ldr r0, _08079A14 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _080799B4
	str r1, [r7, #0x58]
_080799B4:
	ldr r0, [r7, #0x54]
	movs r6, #0xc0
	lsls r6, r6, #4
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079A18 @ =0xFFFFE800
	mov r8, r2
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _080799E0
	cmp r5, #0
	beq _08079A3C
_080799E0:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079A1C @ =0xFFFFF800
	adds r1, r1, r3
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079A08
	subs r1, r4, r0
_08079A08:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079A20
	cmp r1, r2
	blt _08079A26
	b _08079A30
	.align 2, 0
_08079A14: .4byte 0xFFFFF400
_08079A18: .4byte 0xFFFFE800
_08079A1C: .4byte 0xFFFFF800
_08079A20:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079A30
_08079A26:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, r1
	str r0, [r7, #0x58]
	b _08079A3C
_08079A30:
	ldr r2, _08079A9C @ =0xFFFFF400
	adds r1, r5, r2
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079A3C
	str r1, [r7, #0x58]
_08079A3C:
	ldr r0, [r7, #0x54]
	ldr r6, _08079A9C @ =0xFFFFF400
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079AA0 @ =0xFFFFE800
	mov r8, r3
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079A66
	cmp r5, #0
	beq _08079AC4
_08079A66:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079AA4 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079A8E
	subs r1, r4, r0
_08079A8E:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079AA8
	cmp r1, r2
	blt _08079AAE
	b _08079AB8
	.align 2, 0
_08079A9C: .4byte 0xFFFFF400
_08079AA0: .4byte 0xFFFFE800
_08079AA4: .4byte 0xFFFFF800
_08079AA8:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079AB8
_08079AAE:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079AC4
_08079AB8:
	ldr r0, _08079AD4 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079AC4
	str r1, [r7, #0x58]
_08079AC4:
	ldr r4, [r7, #0x58]
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079AD8
	ldr r0, [r7, #0x54]
	ldr r2, _08079AD4 @ =0xFFFFF400
	adds r1, r0, r2
	b _08079AE0
	.align 2, 0
_08079AD4: .4byte 0xFFFFF400
_08079AD8:
	ldr r0, [r7, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r0, r3
_08079AE0:
	adds r0, r1, #0
	adds r1, r4, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08079B2A
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	bge _08079B10
	ldr r0, [r7, #0x54]
	ldr r1, _08079B0C @ =0xFFFFF400
	adds r0, r0, r1
	adds r1, r4, #0
	bl PushoutToRight2
	b _08079B1E
	.align 2, 0
_08079B0C: .4byte 0xFFFFF400
_08079B10:
	ldr r0, [r7, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r1, r4, #0
	bl PushoutToLeft2
_08079B1E:
	adds r1, r0, #0
	cmp r1, #0
	beq _08079B2A
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_08079B2A:
	ldr r1, _08079B58 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r7, #0x54]
	ldr r0, [r0, #0x54]
	adds r4, r1, #0
	cmp r2, r0
	ble _08079B5C
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08079B7E
	.align 2, 0
_08079B58: .4byte pZero2
_08079B5C:
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08079B7E:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	bne _08079BF0
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079C54
	movs r0, #1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08079BB8 @ =0x083675CC
	bl SetDDP
	ldr r0, _08079BBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r7, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _08079BC4
	ldr r0, _08079BC0 @ =0x00003BFF
	cmp r2, r0
	ble _08079BCC
	b _08079BE0
	.align 2, 0
_08079BB8: .4byte 0x083675CC
_08079BBC: .4byte pZero2
_08079BC0: .4byte 0x00003BFF
_08079BC4:
	subs r1, r1, r0
	ldr r0, _08079BD8 @ =0x00003BFF
	cmp r1, r0
	bgt _08079BE0
_08079BCC:
	ldr r1, _08079BDC @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	b _08079C54
	.align 2, 0
_08079BD8: .4byte 0x00003BFF
_08079BDC: .4byte 0x00003501
_08079BE0:
	ldr r1, _08079BEC @ =0x0000350A
	adds r0, r7, #0
	bl SetMotion
	b _08079C54
	.align 2, 0
_08079BEC: .4byte 0x0000350A
_08079BF0:
	cmp r0, #1
	beq _08079BF6
	b _08079CF0
_08079BF6:
	ldrb r3, [r7, #0x1e]
	lsls r1, r3, #8
	adds r2, r7, #0
	adds r2, #0x70
	ldrb r0, [r2]
	orrs r1, r0
	ldr r0, _08079C5C @ =0x00003501
	cmp r1, r0
	bne _08079C28
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08079C54
	cmp r0, #1
	bne _08079C28
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _08079C54
_08079C28:
	lsls r0, r3, #8
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _08079C60 @ =0x0000350A
	cmp r0, r1
	bne _08079C64
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08079C54
	cmp r0, #1
	bne _08079C64
	adds r0, r7, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08079C64
_08079C54:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08079CF6
	.align 2, 0
_08079C5C: .4byte 0x00003501
_08079C60: .4byte 0x0000350A
_08079C64:
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	ldr r1, [r7, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _08079C7C
	ldr r0, _08079C78 @ =0x00003BFF
	cmp r2, r0
	ble _08079C84
	b _08079CBC
	.align 2, 0
_08079C78: .4byte 0x00003BFF
_08079C7C:
	subs r1, r1, r0
	ldr r0, _08079CAC @ =0x00003BFF
	cmp r1, r0
	bgt _08079CBC
_08079C84:
	ldr r2, _08079CB0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079CB4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08079CB8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x12
	bl __umodsi3
	cmp r0, #0
	bne _08079CF6
	mov r2, sb
	strb r0, [r2]
	movs r0, #0xe
	strb r0, [r7, #0x13]
	b _08079CF6
	.align 2, 0
_08079CAC: .4byte 0x00003BFF
_08079CB0: .4byte RNG_0202f388
_08079CB4: .4byte 0x000343FD
_08079CB8: .4byte 0x00269EC3
_08079CBC:
	ldr r2, _08079CE4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08079CE8 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _08079CEC @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _08079CF6
	mov r0, sb
	strb r1, [r0]
	movs r0, #0xb
	strb r0, [r7, #0x13]
	b _08079CF6
	.align 2, 0
_08079CE4: .4byte RNG_0202f388
_08079CE8: .4byte 0x000343FD
_08079CEC: .4byte 0x00269EC3
_08079CF0:
	adds r0, r7, #0
	bl UpdateEntityAnim
_08079CF6:
	adds r0, r7, #0
	bl FUN_0807a46c
	adds r1, r7, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08079D12
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08079D12
	b _0807A004
_08079D12:
	ldr r0, _08079D38 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r7, #0x54]
	ldr r1, [r0, #0x54]
	cmp r2, r1
	bge _08079D3C
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08079D2E
	b _0807A004
_08079D2E:
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	b _0807A002
	.align 2, 0
_08079D38: .4byte pZero2
_08079D3C:
	cmp r2, r1
	bgt _08079D42
	b _0807A004
_08079D42:
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08079D4E
	b _0807A004
_08079D4E:
	movs r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	b _0807A002
_08079D58:
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08079DC0 @ =0x083675CC
	bl SetDDP
	movs r0, #0x10
	strb r0, [r7, #0x12]
	ldr r1, _08079DC4 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08079D7C:
	ldr r0, [r7, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #4
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08079D98
	str r1, [r7, #0x60]
_08079D98:
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x5c]
	adds r2, r2, r3
	str r2, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r4, r2, #0
	ldr r1, _08079DC8 @ =0xFFFFF400
	adds r5, r0, r1
	cmp r3, #0
	bge _08079DCC
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToRight2
	b _08079DDA
	.align 2, 0
_08079DC0: .4byte 0x083675CC
_08079DC4: .4byte 0x00003501
_08079DC8: .4byte 0xFFFFF400
_08079DCC:
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r4, r4, r2
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToLeft2
_08079DDA:
	adds r1, r0, #0
	cmp r1, #0
	beq _08079DE6
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_08079DE6:
	ldr r5, [r7, #0x58]
	ldr r4, [r7, #0x54]
	adds r0, r4, #0
	adds r1, r5, #0
	bl PushoutToUp2
	str r0, [sp]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r4, r3
	adds r1, r5, #0
	bl PushoutToUp2
	str r0, [sp, #4]
	ldr r1, _08079E34 @ =0xFFFFF400
	adds r0, r4, r1
	adds r1, r5, #0
	bl PushoutToUp2
	adds r1, r0, #0
	str r1, [sp, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08079E20
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _08079E20
	cmp r1, #0
	beq _08079E4C
_08079E20:
	ldr r2, [sp]
	ldr r0, [sp, #4]
	cmp r2, r0
	bge _08079E38
	ldr r1, [sp, #8]
	cmp r2, r1
	bge _08079E40
	adds r1, r2, #0
	b _08079E40
	.align 2, 0
_08079E34: .4byte 0xFFFFF400
_08079E38:
	ldr r1, [sp, #8]
	cmp r0, r1
	bge _08079E40
	adds r1, r0, #0
_08079E40:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_08079E4C:
	adds r0, r7, #0
	bl FUN_0807a46c
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r6, _08079EA4 @ =0xFFFFE800
	adds r1, r1, r6
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079E74
	cmp r5, #0
	beq _08079EC8
_08079E74:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _08079EA8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r6
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079E98
	subs r1, r4, r0
_08079E98:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079EAC
	cmp r1, r2
	blt _08079EB2
	b _08079EBC
	.align 2, 0
_08079EA4: .4byte 0xFFFFE800
_08079EA8: .4byte 0xFFFFF800
_08079EAC:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079EBC
_08079EB2:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079EC8
_08079EBC:
	ldr r0, _08079F28 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079EC8
	str r1, [r7, #0x58]
_08079EC8:
	ldr r0, [r7, #0x54]
	movs r6, #0xc0
	lsls r6, r6, #4
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079F2C @ =0xFFFFE800
	mov r8, r2
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079EF4
	cmp r5, #0
	beq _08079F50
_08079EF4:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079F30 @ =0xFFFFF800
	adds r1, r1, r3
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079F1C
	subs r1, r4, r0
_08079F1C:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079F34
	cmp r1, r2
	blt _08079F3A
	b _08079F44
	.align 2, 0
_08079F28: .4byte 0xFFFFF400
_08079F2C: .4byte 0xFFFFE800
_08079F30: .4byte 0xFFFFF800
_08079F34:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079F44
_08079F3A:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, r1
	str r0, [r7, #0x58]
	b _08079F50
_08079F44:
	ldr r2, _08079FB0 @ =0xFFFFF400
	adds r1, r5, r2
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079F50
	str r1, [r7, #0x58]
_08079F50:
	ldr r0, [r7, #0x54]
	ldr r6, _08079FB0 @ =0xFFFFF400
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r3, _08079FB4 @ =0xFFFFE800
	mov r8, r3
	add r1, r8
	bl PushoutToDown2
	adds r4, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	subs r1, #0x10
	bl PushoutToUp2
	adds r5, r0, #0
	cmp r4, #0
	bne _08079F7A
	cmp r5, #0
	beq _08079FD8
_08079F7A:
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	ldr r2, _08079FB8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r6
	ldr r1, [r7, #0x58]
	add r1, r8
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r7, #0x58]
	subs r1, r0, r4
	cmp r1, #0
	bgt _08079FA2
	subs r1, r4, r0
_08079FA2:
	subs r2, r0, r5
	cmp r2, #0
	ble _08079FBC
	cmp r1, r2
	blt _08079FC2
	b _08079FCC
	.align 2, 0
_08079FB0: .4byte 0xFFFFF400
_08079FB4: .4byte 0xFFFFE800
_08079FB8: .4byte 0xFFFFF800
_08079FBC:
	subs r0, r5, r0
	cmp r1, r0
	bge _08079FCC
_08079FC2:
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r4, r3
	str r0, [r7, #0x58]
	b _08079FD8
_08079FCC:
	ldr r0, _0807A014 @ =0xFFFFF400
	adds r1, r5, r0
	ldr r0, [r7, #0x58]
	cmp r0, r1
	ble _08079FD8
	str r1, [r7, #0x58]
_08079FD8:
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08079FEC
	adds r0, r7, #0
	bl UpdateEntityAnim
_08079FEC:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0807A004
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0807A004
	str r0, [r7, #0x60]
	strb r0, [r7, #0xd]
_0807A002:
	strb r0, [r7, #0xe]
_0807A004:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A014: .4byte 0xFFFFF400

