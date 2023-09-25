	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ZeroMini_Init
ZeroMini_Init: @ 0x08036398
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r6, r4, #0
	adds r6, #0x74
	ldr r1, _08036460 @ =0x0835ECA0
	adds r2, #0xa
	adds r0, r6, #0
	movs r3, #0x20
	bl InitBody
	str r4, [r6, #0x2c]
	str r5, [r6, #0x24]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	str r0, [r4, #0x58]
	ldr r1, _08036464 @ =gZeroFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	ldr r1, _08036468 @ =0x00000286
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl LoadZeroPalette
	movs r0, #0
	movs r1, #0
	bl SetWeaponElement
	movs r0, #1
	movs r1, #0
	bl SetWeaponElement
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	strb r5, [r4, #0x13]
	adds r1, #7
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r4, #0x5c]
	adds r0, #8
	str r5, [r0, #4]
	str r5, [r4, #0x64]
	adds r0, r4, #0
	bl ZeroMini_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036460: .4byte 0x0835ECA0
_08036464: .4byte gZeroFnTable
_08036468: .4byte 0x00000286

	thumb_func_start ZeroMini_Update
ZeroMini_Update: @ 0x0803646C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _080364A4
	ldr r1, _0803649C @ =0x0835EC78
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080364A0 @ =0x0835EC8C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _080364CA
	.align 2, 0
_0803649C: .4byte 0x0835EC78
_080364A0: .4byte 0x0835EC8C
_080364A4:
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	bne _080364CA
	ldr r1, _08036540 @ =0x0835EC78
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08036544 @ =0x0835EC8C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080364CA:
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r0, [r6]
	movs r1, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x94
	cmp r0, #0
	beq _08036518
	movs r0, #0xa
	bl PlaySound
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	beq _08036518
	movs r0, #4
	bl PlaySound
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xc]
	subs r1, #1
	strb r1, [r0, #0xc]
	ldr r0, [r4, #0x28]
	ldrb r2, [r0, #0xc]
	cmp r2, #0
	bne _08036518
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	strb r2, [r5]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08036518:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803653A
	ldr r0, _08036548 @ =0x00000286
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036532
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803653A
_08036532:
	ldrb r1, [r5]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r5]
_0803653A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036540: .4byte 0x0835EC78
_08036544: .4byte 0x0835EC8C
_08036548: .4byte 0x00000286

	thumb_func_start ZeroMini_Die
ZeroMini_Die: @ 0x0803654C
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08036588 @ =gZeroFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	bx lr
	.align 2, 0
_08036588: .4byte gZeroFnTable

	thumb_func_start nop_0803658c
nop_0803658c: @ 0x0803658C
	movs r0, #1
	bx lr

	thumb_func_start zeroMini_08036590
zeroMini_08036590: @ 0x08036590
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080365A0
	cmp r0, #1
	beq _080365B2
	b _080365D0
_080365A0:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080365B2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080365C8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080365D0
_080365C8:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080365D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080365d8
FUN_080365d8: @ 0x080365D8
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _080365E8
	b _080366EE
_080365E8:
	ldr r2, _08036608 @ =gJoypad
	ldrh r1, [r2, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803663A
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08036610
	ldr r4, _0803660C @ =0x00000287
	adds r1, r3, r4
	movs r0, #2
	strb r0, [r1]
	b _08036632
	.align 2, 0
_08036608: .4byte gJoypad
_0803660C: .4byte 0x00000287
_08036610:
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803662C
	ldr r5, _08036628 @ =0x00000287
	adds r1, r3, r5
	movs r0, #4
	strb r0, [r1]
	b _08036632
	.align 2, 0
_08036628: .4byte 0x00000287
_0803662C:
	ldr r4, _0803666C @ =0x00000287
	adds r0, r3, r4
	strb r1, [r0]
_08036632:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
_0803663A:
	ldr r5, _08036670 @ =0x0000027D
	adds r4, r3, r5
	ldrb r0, [r4]
	cmp r0, #1
	bne _08036694
	ldrh r2, [r2]
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080366EE
	subs r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	strb r1, [r4]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _08036674
	ldr r0, _0803666C @ =0x00000287
	adds r1, r3, r0
	movs r0, #7
	b _080366C0
	.align 2, 0
_0803666C: .4byte 0x00000287
_08036670: .4byte 0x0000027D
_08036674:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08036688
	ldr r2, _08036684 @ =0x00000287
	adds r1, r3, r2
	movs r0, #8
	b _080366C0
	.align 2, 0
_08036684: .4byte 0x00000287
_08036688:
	ldr r4, _08036690 @ =0x00000287
	adds r1, r3, r4
	movs r0, #6
	b _080366C0
	.align 2, 0
_08036690: .4byte 0x00000287
_08036694:
	movs r5, #0x9f
	lsls r5, r5, #2
	adds r1, r3, r5
	ldrb r0, [r1]
	cmp r0, #0xa
	bls _080366EE
	ldrh r2, [r2]
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080366EE
	strb r0, [r1]
	strb r0, [r4]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080366C8
	ldr r0, _080366C4 @ =0x00000287
	adds r1, r3, r0
	movs r0, #2
_080366C0:
	strb r0, [r1]
	b _080366E6
	.align 2, 0
_080366C4: .4byte 0x00000287
_080366C8:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080366E0
	ldr r2, _080366DC @ =0x00000287
	adds r1, r3, r2
	movs r0, #4
	b _080366C0
	.align 2, 0
_080366DC: .4byte 0x00000287
_080366E0:
	ldr r4, _080366F8 @ =0x00000287
	adds r0, r3, r4
	strb r1, [r0]
_080366E6:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
_080366EE:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080366F8: .4byte 0x00000287

	thumb_func_start FUN_080366fc
FUN_080366fc: @ 0x080366FC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _0803670C
	cmp r4, #1
	beq _0803673A
	b _0803683C
_0803670C:
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080367C8 @ =0x0835ECA0
	bl SetDDP
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803673A:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	ldr r0, [r5, #0x28]
	movs r1, #4
	ldrsh r6, [r0, r1]
	cmp r6, #1
	bne _08036822
	ldr r4, _080367CC @ =gJoypad
	ldrh r1, [r4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803677A
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_0803677A:
	ldrh r4, [r4]
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _0803679C
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_0803679C:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _08036814
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x27
	bhi _080367D0
	ldrh r0, [r3]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080367E4
	movs r0, #0x17
	bl PlaySound
	b _080367E4
	.align 2, 0
_080367C8: .4byte 0x0835ECA0
_080367CC: .4byte gJoypad
_080367D0:
	ldrh r0, [r3]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080367E4
	movs r0, #0x18
	bl PlaySound
_080367E4:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0xa
	bne _08036808
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c825c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c825c
_08036808:
	ldrb r0, [r6]
	cmp r0, #0xc7
	bhi _08036822
	adds r0, #1
	strb r0, [r6]
	b _08036822
_08036814:
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r7, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r7, [r0]
_08036822:
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x28
	bls _08036836
	ldr r0, _08036844 @ =0x0000027D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08036836:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0803683C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036844: .4byte 0x0000027D

	thumb_func_start FUN_08036848
FUN_08036848: @ 0x08036848
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _08036866
	ldr r0, _0803686C @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036866
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08036866:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_0803686C: .4byte gJoypad

	thumb_func_start FUN_08036870
FUN_08036870: @ 0x08036870
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080368A0
	cmp r0, #1
	bgt _08036884
	cmp r0, #0
	beq _0803688E
	b _080368FC
_08036884:
	cmp r0, #2
	beq _080368C2
	cmp r0, #3
	beq _080368DE
	b _080368FC
_0803688E:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080368A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080368D2
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080368D6
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080368FC
	b _080368D6
_080368C2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080368FC
_080368D2:
	movs r0, #0xa
	strb r0, [r4, #0x12]
_080368D6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080368FC
_080368DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080368F4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080368FC
_080368F4:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080368FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08036904
FUN_08036904: @ 0x08036904
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #1
	bne _0803692E
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0803692E
	ldr r0, _08036934 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803692E
	ldrb r0, [r2, #0xf]
	cmp r0, #0
	bne _0803692E
	strb r3, [r2, #0xf]
_0803692E:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08036934: .4byte gJoypad

	thumb_func_start recoil_minigame_08036938
recoil_minigame_08036938: @ 0x08036938
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _08036944
	b _08036B86
_08036944:
	lsls r0, r0, #2
	ldr r1, _08036950 @ =_08036954
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036950: .4byte _08036954
_08036954: @ jump table
	.4byte _08036984 @ case 0
	.4byte _080369F6 @ case 1
	.4byte _08036A32 @ case 2
	.4byte _08036AB6 @ case 3
	.4byte _08036B86 @ case 4
	.4byte _08036B86 @ case 5
	.4byte _08036B86 @ case 6
	.4byte _08036B86 @ case 7
	.4byte _08036B86 @ case 8
	.4byte _08036B86 @ case 9
	.4byte _08036AD4 @ case 10
	.4byte _08036B86 @ case 11
_08036984:
	ldr r0, _080369B8 @ =0x00000287
	adds r4, r5, r0
	ldrb r1, [r4]
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateWeaponMinigameRod
	ldr r1, _080369BC @ =0x0835ED48
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r4]
	cmp r0, #5
	bhi _080369C0
	movs r0, #0x36
	bl PlaySound
	movs r0, #0
	b _080369C8
	.align 2, 0
_080369B8: .4byte 0x00000287
_080369BC: .4byte 0x0835ED48
_080369C0:
	movs r0, #0x37
	bl PlaySound
	movs r0, #2
_080369C8:
	strb r0, [r5, #0xf]
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r1, _080369E8 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080369F0
	ldr r0, _080369EC @ =0xFFFFFA80
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _08036B86
	.align 2, 0
_080369E8: .4byte 0x00000287
_080369EC: .4byte 0xFFFFFA80
_080369F0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080369F6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	bne _08036A16
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _08036A16
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08036A16:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08036A22
	b _08036B86
_08036A22:
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	beq _08036A2A
	b _08036B7C
_08036A2A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08036B86
_08036A32:
	ldr r3, _08036AC8 @ =gJoypad
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08036A5A
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_08036A5A:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08036A7E
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_08036A7E:
	ldr r0, _08036ACC @ =0x00000287
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateWeaponMinigameRod
	ldr r1, _08036AD0 @ =0x0835ED48
	ldrb r0, [r4]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x36
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08036AB6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08036B86
	b _08036B7C
	.align 2, 0
_08036AC8: .4byte gJoypad
_08036ACC: .4byte 0x00000287
_08036AD0: .4byte 0x0835ED48
_08036AD4:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08036AE4
	str r1, [r5, #0x60]
_08036AE4:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08036B10
	cmp r1, #0
	bge _08036B08
	ldr r1, _08036B04 @ =0x00000403
	adds r0, r5, #0
	bl SetMotion
	b _08036B10
	.align 2, 0
_08036B04: .4byte 0x00000403
_08036B08:
	ldr r1, _08036B8C @ =0x00000404
	adds r0, r5, #0
	bl SetMotion
_08036B10:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08036B62
	ldr r3, _08036B90 @ =gJoypad
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08036B3E
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_08036B3E:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08036B62
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_08036B62:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	beq _08036B86
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08036B7C:
	movs r1, #0
	str r1, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08036B86:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036B8C: .4byte 0x00000404
_08036B90: .4byte gJoypad

	thumb_func_start FUN_08036b94
FUN_08036b94: @ 0x08036B94
	movs r0, #1
	bx lr

	thumb_func_start zeroMini_08036b98
zeroMini_08036b98: @ 0x08036B98
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08036BA8
	cmp r0, #1
	beq _08036BB8
	b _08036BEC
_08036BA8:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08036BB8:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08036BC8
	str r1, [r4, #0x60]
_08036BC8:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	beq _08036BE6
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08036BE6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08036BEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
