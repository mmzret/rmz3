	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateDeathtanzRock
CreateDeathtanzRock: @ 0x0807A4E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov sb, r1
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _0807A5B0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0807A544
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807A5B4 @ =gEnemyFnTable
	movs r0, #0x1b
	strb r0, [r4, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	mov r0, sb
	str r0, [r4, #0x54]
	mov r1, r8
	str r1, [r4, #0x58]
	str r5, [r4, #0x28]
	strb r7, [r4, #0x12]
_0807A544:
	movs r5, #0
	movs r6, #0
_0807A548:
	ldr r0, _0807A5B0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _0807A59A
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807A5B4 @ =gEnemyFnTable
	movs r0, #0x1b
	strb r0, [r2, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	strh r6, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	strb r6, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #1
	strb r0, [r2, #0x10]
	mov r1, sb
	str r1, [r2, #0x54]
	ldr r1, _0807A5B8 @ =0x0836773C
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r0, r8
	str r0, [r2, #0x58]
	str r4, [r2, #0x28]
	strb r7, [r2, #0x12]
	strb r5, [r2, #0x13]
_0807A59A:
	adds r5, #1
	cmp r5, #2
	ble _0807A548
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A5B0: .4byte gZakoHeaderPtr
_0807A5B4: .4byte gEnemyFnTable
_0807A5B8: .4byte 0x0836773C

	thumb_func_start nop_0807a5bc
nop_0807a5bc: @ 0x0807A5BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a5c0
FUN_0807a5c0: @ 0x0807A5C0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0807A5D6
	movs r0, #0
	b _0807A5F4
_0807A5D6:
	ldr r1, _0807A5F8 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	movs r0, #0
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl DeathtanzRock_Die
	movs r0, #1
_0807A5F4:
	pop {r1}
	bx r1
	.align 2, 0
_0807A5F8: .4byte gEnemyFnTable

	thumb_func_start DeathtanzRock_Init
DeathtanzRock_Init: @ 0x0807A5FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0807A660 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0807A664 @ =0x08367742
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807A66C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A668 @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x14
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #3
	strb r0, [r1]
	b _0807A68A
	.align 2, 0
_0807A660: .4byte gEnemyFnTable
_0807A664: .4byte 0x08367742
_0807A668: .4byte 0x08367664
_0807A66C:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A69C @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0807A68A:
	ldr r0, _0807A6A0 @ =nop_0807a5bc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl DeathtanzRock_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A69C: .4byte 0x08367664
_0807A6A0: .4byte nop_0807a5bc

	thumb_func_start DeathtanzRock_Update
DeathtanzRock_Update: @ 0x0807A6A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807a5c0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807A6D2
	ldr r1, _0807A6D8 @ =0x08367648
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807A6DC @ =0x08367654
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0

	non_word_aligned_thumb_func_start FUN_0807a6ce
FUN_0807a6ce: @ 0x0807A6CE
	bl _call_via_r1
_0807A6D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A6D8: .4byte 0x08367648
_0807A6DC: .4byte 0x08367654

	thumb_func_start DeathtanzRock_Die
DeathtanzRock_Die: @ 0x0807A6E0
	push {lr}
	ldr r2, _0807A6F4 @ =0x08367660
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0807A6F4: .4byte 0x08367660

	thumb_func_start nop_0807a6f8
nop_0807a6f8: @ 0x0807A6F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807a6fc
FUN_0807a6fc: @ 0x0807A6FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0807A780
	cmp r0, #1
	bgt _0807A712
	cmp r0, #0
	beq _0807A720
	b _0807A894
_0807A712:
	cmp r0, #2
	bne _0807A718
	b _0807A828
_0807A718:
	cmp r0, #3
	bne _0807A71E
	b _0807A84A
_0807A71E:
	b _0807A894
_0807A720:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A740 @ =0x0836767C
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0807A744
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0807A74A
	.align 2, 0
_0807A740: .4byte 0x0836767C
_0807A744:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807A74A:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r4, #0x60]
	strb r3, [r4, #0x13]
	ldr r1, _0807A810 @ =0x00003603
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A780:
	adds r0, r6, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807A798
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A798:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0807A814 @ =0x08367744
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0807A818 @ =0x08367664
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807A7C2
	str r1, [r4, #0x60]
_0807A7C2:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r5, r6, #0
	adds r5, #0xb8
	ldr r1, [r5]
	cmp r0, r1
	ble _0807A820
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0807A7EE
	movs r0, #0x41
	bl PlaySound
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
_0807A7EE:
	ldr r0, [r5]
	str r0, [r4, #0x58]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _0807A820
	ldr r1, _0807A81C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	b _0807A894
	.align 2, 0
_0807A810: .4byte 0x00003603
_0807A814: .4byte 0x08367744
_0807A818: .4byte 0x08367664
_0807A81C: .4byte gEnemyFnTable
_0807A820:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0807A894
_0807A828:
	adds r0, r4, #0
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
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A84A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0807A872
	ldr r1, _0807A888 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0807A872:
	ldrb r1, [r4, #0x12]
	cmp r1, #0x1d
	bhi _0807A894
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807A88C
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807A892
	.align 2, 0
_0807A888: .4byte gEnemyFnTable
_0807A88C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807A892:
	strb r0, [r4, #0xa]
_0807A894:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807a89c
FUN_0807a89c: @ 0x0807A89C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0807A8C4
	ldr r1, _0807A8C0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	b _0807A972
	.align 2, 0
_0807A8C0: .4byte gEnemyFnTable
_0807A8C4:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807A8D0
	cmp r0, #1
	beq _0807A924
	b _0807A972
_0807A8D0:
	ldrb r0, [r4, #0xb]
	movs r3, #0x10
	movs r1, #0
	orrs r0, r3
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0807A8EA
	ldrb r0, [r4, #0xa]
	orrs r0, r3
	b _0807A8F0
_0807A8EA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807A8F0:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldr r1, _0807A948 @ =0x08367748
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A924:
	adds r3, r5, #0
	adds r3, #0xb4
	ldrb r0, [r3]
	ldrb r2, [r4, #0x13]
	cmp r0, r2
	bne _0807A938
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807A938:
	ldrb r3, [r3]
	cmp r2, r3
	blo _0807A94C
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	b _0807A952
	.align 2, 0
_0807A948: .4byte 0x08367748
_0807A94C:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
_0807A952:
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r1, [r5, #0x58]
	str r1, [r4, #0x58]
	ldr r2, _0807A978 @ =0x0836774E
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807A972:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A978: .4byte 0x0836774E

	thumb_func_start FUN_0807a97c
FUN_0807a97c: @ 0x0807A97C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807A98C
	cmp r0, #1
	beq _0807A9E8
	b _0807AA1E
_0807A98C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807AA24 @ =0x0836770C
	bl SetDDP
	ldr r3, _0807AA28 @ =gSineTable
	ldr r2, _0807AA2C @ =0x08367754
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r1, r0, r1
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807A9BE
	rsbs r0, r1, #0
	str r0, [r4, #0x5c]
_0807A9BE:
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	rsbs r1, r1, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A9E8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807AA18
	ldr r1, _0807AA30 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
_0807AA18:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807AA1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA24: .4byte 0x0836770C
_0807AA28: .4byte gSineTable
_0807AA2C: .4byte 0x08367754
_0807AA30: .4byte gEnemyFnTable

	thumb_func_start FUN_0807aa34
FUN_0807aa34: @ 0x0807AA34
	push {r4, lr}
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
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0807AA6A
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	ldr r2, _0807AA84 @ =0x0836775A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
_0807AA6A:
	ldr r1, _0807AA88 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA84: .4byte 0x0836775A
_0807AA88: .4byte gEnemyFnTable
