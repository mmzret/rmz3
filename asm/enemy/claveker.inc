	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Claveker_Init
Claveker_Init: @ 0x0808E52C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _0808E578 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x13]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808E584
	ldr r0, _0808E57C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808E584
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E580 @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	b _0808E59C
	.align 2, 0
_0808E578: .4byte gSystemSavedataManager
_0808E57C: .4byte gCurStory
_0808E580: .4byte 0x08369388
_0808E584:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E60C @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
_0808E59C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808E610 @ =FUN_0808f234
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r4, #0
	strb r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r1, _0808E614 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E5F8
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0808E5F8:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r6, #0
	bl Claveker_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E60C: .4byte 0x08369388
_0808E610: .4byte FUN_0808f234
_0808E614: .4byte gEnemyFnTable

	thumb_func_start Claveker_Update
Claveker_Update: @ 0x0808E618
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _0808E648
	ldr r1, _0808E644 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Claveker_Die
	b _0808E6FC
	.align 2, 0
_0808E644: .4byte gEnemyFnTable
_0808E648:
	ldr r1, _0808E6A0 @ =0x08369340
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0808f1e0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E67E
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0808E67E
	cmp r0, #3
	beq _0808E67E
	cmp r0, #5
	beq _0808E67E
	cmp r0, #4
	beq _0808E67E
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808E67E:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0808E6A4
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E6A4
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0808E6FC
	.align 2, 0
_0808E6A0: .4byte 0x08369340
_0808E6A4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E6B4
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808E6B4:
	ldr r0, [r5]
	cmp r0, #0
	beq _0808E6EC
	bl isKilled
	cmp r0, #0
	beq _0808E6DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E6D8 @ =0x08369388
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0808E6FC
	.align 2, 0
_0808E6D8: .4byte 0x08369388
_0808E6DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E6E8 @ =0x083693A0
	bl SetDDP
	b _0808E6FC
	.align 2, 0
_0808E6E8: .4byte 0x083693A0
_0808E6EC:
	ldr r0, _0808E704 @ =0x08369358
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0808E6FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E704: .4byte 0x08369358

	thumb_func_start Claveker_Die
Claveker_Die: @ 0x0808E708
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _0808E754 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808E75C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808E758 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808EAEE
	.align 2, 0
_0808E754: .4byte gCurStory
_0808E758: .4byte gEnemyFnTable
_0808E75C:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _0808E764
	b _0808EAF0
_0808E764:
	lsls r0, r0, #2
	ldr r1, _0808E770 @ =_0808E774
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808E770: .4byte _0808E774
_0808E774: @ jump table
	.4byte _0808E7A4 @ case 0
	.4byte _0808E8C8 @ case 1
	.4byte _0808E7F4 @ case 2
	.4byte _0808E808 @ case 3
	.4byte _0808E8D0 @ case 4
	.4byte _0808EAF0 @ case 5
	.4byte _0808EAF0 @ case 6
	.4byte _0808EAF0 @ case 7
	.4byte _0808EAF0 @ case 8
	.4byte _0808EAF0 @ case 9
	.4byte _0808E8C8 @ case 10
	.4byte _0808EA50 @ case 11
_0808E7A4:
	ldr r1, _0808E7CC @ =0x00007505
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0808E7D0
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _0808E7D0
	movs r0, #1
	b _0808E7D2
	.align 2, 0
_0808E7CC: .4byte 0x00007505
_0808E7D0:
	movs r0, #0xa
_0808E7D2:
	strb r0, [r7, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
	b _0808E8C8
_0808E7F4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808E806
	b _0808EAF0
_0808E806:
	b _0808E8C8
_0808E808:
	ldr r1, _0808E84C @ =0x00007505
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r7, #0x13]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #0xb8
	ldrb r1, [r4]
	mov r0, sp
	bl FUN_080c4450
	ldrb r0, [r4]
	cmp r0, #0
	bne _0808E854
	ldr r0, [sp]
	ldr r1, _0808E850 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	b _0808E868
	.align 2, 0
_0808E84C: .4byte 0x00007505
_0808E850: .4byte 0xFFFFF800
_0808E854:
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
_0808E868:
	str r0, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0808E894
	cmp r0, #0xfe
	bne _0808E888
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0808E8B6
_0808E888:
	ldr r0, _0808E8A4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0808E8A8
_0808E894:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0808E8B6
	.align 2, 0
_0808E8A4: .4byte pZero2
_0808E8A8:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0808E8B6:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl TryDropItem
	movs r0, #0x80
	str r0, [r7, #0x60]
	movs r0, #0x32
	strb r0, [r7, #0x12]
_0808E8C8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808EAF0
_0808E8D0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E8E6
	str r1, [r7, #0x60]
_0808E8E6:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808E9A4
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0808E984 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808E988 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0808E98C @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808E990 @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808E994 @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808E998 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808E99C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808E9A0 @ =0x0000270E
	cmp r1, r0
	bhi _0808E97A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808E97A:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0808EAD2
	.align 2, 0
_0808E984: .4byte RNG_0202f388
_0808E988: .4byte 0x000343FD
_0808E98C: .4byte 0x00269EC3
_0808E990: .4byte 0x00007507
_0808E994: .4byte 0x00007508
_0808E998: .4byte 0x00007509
_0808E99C: .4byte gMission
_0808E9A0: .4byte 0x0000270E
_0808E9A4:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _0808E9AC
	b _0808EAF0
_0808E9AC:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E9B8
	b _0808EAF0
_0808E9B8:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0808EA30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808EA34 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808EA38 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x10
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808EA3C @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EA40 @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EA44 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808EA48 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808EA4C @ =0x0000270E
	cmp r1, r0
	bhi _0808EA28
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808EA28:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0808EAD2
	.align 2, 0
_0808EA30: .4byte RNG_0202f388
_0808EA34: .4byte 0x000343FD
_0808EA38: .4byte 0x00269EC3
_0808EA3C: .4byte 0x00007507
_0808EA40: .4byte 0x00007508
_0808EA44: .4byte 0x00007509
_0808EA48: .4byte gMission
_0808EA4C: .4byte 0x0000270E
_0808EA50:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #1
	mov r1, r8
	bl TryDropItem
	ldr r2, _0808EAFC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808EB00 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808EB04 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x18
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808EB08 @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EB0C @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EB10 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldr r2, _0808EB14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808EB18 @ =0x0000270E
	cmp r1, r0
	bhi _0808EACE
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808EACE:
	adds r0, r7, #0
	mov r1, r8
_0808EAD2:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808EB1C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0808EAEE:
	str r0, [r7, #0x14]
_0808EAF0:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EAFC: .4byte RNG_0202f388
_0808EB00: .4byte 0x000343FD
_0808EB04: .4byte 0x00269EC3
_0808EB08: .4byte 0x00007507
_0808EB0C: .4byte 0x00007508
_0808EB10: .4byte 0x00007509
_0808EB14: .4byte gMission
_0808EB18: .4byte 0x0000270E
_0808EB1C: .4byte gEnemyFnTable

	thumb_func_start FUN_0808eb20
FUN_0808eb20: @ 0x0808EB20
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808eb24
FUN_0808eb24: @ 0x0808EB24
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808EB5C
	cmp r0, #1
	bgt _0808EB38
	cmp r0, #0
	beq _0808EB3E
	b _0808EBAA
_0808EB38:
	cmp r0, #2
	beq _0808EB90
	b _0808EBAA
_0808EB3E:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EB84 @ =0x08369388
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EB5C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0808EB88 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _0808EB8C @ =0x00003FFF
	cmp r0, r1
	bhi _0808EBAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a134
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EBAA
	.align 2, 0
_0808EB84: .4byte 0x08369388
_0808EB88: .4byte gStageRun+232
_0808EB8C: .4byte 0x00003FFF
_0808EB90:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808EBAA
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EBAA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ebb0
FUN_0808ebb0: @ 0x0808EBB0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808ebb4
FUN_0808ebb4: @ 0x0808EBB4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0808EBC0
	b _0808EFEE
_0808EBC0:
	lsls r0, r0, #2
	ldr r1, _0808EBCC @ =_0808EBD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808EBCC: .4byte _0808EBD0
_0808EBD0: @ jump table
	.4byte _0808EBE8 @ case 0
	.4byte _0808EC98 @ case 1
	.4byte _0808EF6E @ case 2
	.4byte _0808EF8A @ case 3
	.4byte _0808EFA4 @ case 4
	.4byte _0808EFAA @ case 5
_0808EBE8:
	ldr r1, _0808EC1C @ =0x00007501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EC20 @ =0x08369388
	bl SetDDP
	ldr r0, _0808EC24 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EC40
	ldr r3, _0808EC28 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EC30
	ldr r0, _0808EC2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC38
	b _0808EC6C
	.align 2, 0
_0808EC1C: .4byte 0x00007501
_0808EC20: .4byte 0x08369388
_0808EC24: .4byte pZero2
_0808EC28: .4byte 0xFFFFD000
_0808EC2C: .4byte 0x00002FFF
_0808EC30:
	subs r1, r1, r0
	ldr r0, _0808EC3C @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC38:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC3C: .4byte 0x00002FFF
_0808EC40:
	movs r3, #0xc0
	lsls r3, r3, #6
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EC5C
	ldr r0, _0808EC58 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC64
	b _0808EC6C
	.align 2, 0
_0808EC58: .4byte 0x00002FFF
_0808EC5C:
	subs r1, r0, r1
	ldr r0, _0808EC68 @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC64:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC68: .4byte 0x00002FFF
_0808EC6C:
	movs r0, #1
_0808EC6E:
	strb r0, [r4, #0xf]
	ldr r2, _0808ECC8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808ECCC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808ECD0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0x3c
	movs r1, #0
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EC98:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808ECA0
	b _0808EDB8
_0808ECA0:
	ldr r5, _0808ECD4 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808ED3C
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #4
	adds r1, r1, r3
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ECD8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ECC8: .4byte RNG_0202f388
_0808ECCC: .4byte 0x000343FD
_0808ECD0: .4byte 0x00269EC3
_0808ECD4: .4byte pZero2
_0808ECD8:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED02
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808ED02:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808ED1C
	ldr r0, _0808ED18 @ =0x00002FFF
	cmp r2, r0
	ble _0808ED26
	b _0808EECC
	.align 2, 0
_0808ED18: .4byte 0x00002FFF
_0808ED1C:
	subs r1, r1, r0
	ldr r0, _0808ED30 @ =0x00002FFF
	cmp r1, r0
	ble _0808ED26
	b _0808EECC
_0808ED26:
	ldr r0, _0808ED34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808ED38 @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808ED30: .4byte 0x00002FFF
_0808ED34: .4byte pZero2
_0808ED38: .4byte 0xFFFFD000
_0808ED3C:
	ldr r3, _0808ED58 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ED5C
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED58: .4byte 0xFFFFEC00
_0808ED5C:
	ldr r0, [r4, #0x54]
	ldr r3, _0808ED84 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808ED88 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED8C
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED84: .4byte 0xFFFFFD00
_0808ED88: .4byte 0xFFFFE900
_0808ED8C:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EDA8
	ldr r0, _0808EDA4 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EDA0
	b _0808EEB8
_0808EDA0:
	b _0808EECC
	.align 2, 0
_0808EDA4: .4byte 0x00002FFF
_0808EDA8:
	subs r1, r0, r1
	ldr r0, _0808EDB4 @ =0x00002FFF
	cmp r1, r0
	ble _0808EDB2
	b _0808EECC
_0808EDB2:
	b _0808EEB8
	.align 2, 0
_0808EDB4: .4byte 0x00002FFF
_0808EDB8:
	ldr r5, _0808EDE0 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EE50
	ldr r3, _0808EDE4 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EDE8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EDE0: .4byte pZero2
_0808EDE4: .4byte 0xFFFFEC00
_0808EDE8:
	ldr r0, [r4, #0x54]
	ldr r3, _0808EE10 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808EE14 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE18
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EE10: .4byte 0xFFFFFD00
_0808EE14: .4byte 0xFFFFE900
_0808EE18:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EE30
	ldr r0, _0808EE2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EE38
	b _0808EECC
	.align 2, 0
_0808EE2C: .4byte 0x00002FFF
_0808EE30:
	subs r1, r0, r1
	ldr r0, _0808EE44 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EE38:
	ldr r0, _0808EE48 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808EE4C @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808EE44: .4byte 0x00002FFF
_0808EE48: .4byte pZero2
_0808EE4C: .4byte 0xFFFFD000
_0808EE50:
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EE6C
	movs r0, #3
	b _0808EECA
_0808EE6C:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE96
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808EE96:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EEB0
	ldr r0, _0808EEAC @ =0x00002FFF
	cmp r2, r0
	bgt _0808EEB8
	b _0808EECC
	.align 2, 0
_0808EEAC: .4byte 0x00002FFF
_0808EEB0:
	subs r1, r1, r0
	ldr r0, _0808EEE8 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EEB8:
	ldr r0, _0808EEEC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
_0808EEC2:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
_0808EECA:
	strb r0, [r4, #0xe]
_0808EECC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r4, #0x54]
	ldr r1, [r0]
	subs r2, r3, r1
	adds r5, r0, #0
	cmp r2, #0
	ble _0808EEF0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0808EEFA
	b _0808EF48
	.align 2, 0
_0808EEE8: .4byte 0x00002FFF
_0808EEEC: .4byte pZero2
_0808EEF0:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _0808EF48
_0808EEFA:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	cmp r0, r1
	ble _0808EF0A
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r1, r3
	b _0808EF0E
_0808EF0A:
	ldr r2, _0808EF28 @ =0xFFFF6000
	adds r0, r1, r2
_0808EF0E:
	str r0, [r4, #0x54]
	ldr r0, _0808EF2C @ =pZero2
	ldr r0, [r0]
	ldr r3, [r4, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0808EF34
	ldr r0, _0808EF30 @ =0x00002FFF
	cmp r2, r0
	ble _0808EF3C
	b _0808EF44
	.align 2, 0
_0808EF28: .4byte 0xFFFF6000
_0808EF2C: .4byte pZero2
_0808EF30: .4byte 0x00002FFF
_0808EF34:
	subs r1, r1, r3
	ldr r0, _0808EF40 @ =0x00002FFF
	cmp r1, r0
	bgt _0808EF44
_0808EF3C:
	movs r0, #2
	b _0808EF46
	.align 2, 0
_0808EF40: .4byte 0x00002FFF
_0808EF44:
	movs r0, #3
_0808EF46:
	strb r0, [r4, #0xe]
_0808EF48:
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _0808EF66
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0808EF66
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_0808EF66:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808EFEE
_0808EF6E:
	adds r5, r4, #0
	adds r5, #0x71
	movs r1, #0
	ldrsb r1, [r5, r1]
	cmp r1, #0
	beq _0808EFE8
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #7
	bne _0808EFEE
	b _0808EFE6
_0808EF8A:
	ldr r1, _0808EFA0 @ =0x0000750B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EFEE
	.align 2, 0
_0808EFA0: .4byte 0x0000750B
_0808EFA4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EFAA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r2, r3
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bne _0808EFD8
	ldr r0, _0808EFD4 @ =pZero2
	ldr r0, [r0]
	movs r3, #0xd0
	lsls r3, r3, #8
	adds r1, r2, r3
	ldr r0, [r0, #0x54]
	cmp r0, r1
	bge _0808EFEE
	b _0808EFE6
	.align 2, 0
_0808EFD4: .4byte pZero2
_0808EFD8:
	ldr r0, _0808EFF4 @ =pZero2
	ldr r0, [r0]
	ldr r2, _0808EFF8 @ =0xFFFFD000
	adds r1, r1, r2
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0808EFEE
_0808EFE6:
	movs r1, #0
_0808EFE8:
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EFEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EFF4: .4byte pZero2
_0808EFF8: .4byte 0xFFFFD000

	thumb_func_start FUN_0808effc
FUN_0808effc: @ 0x0808EFFC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f000
FUN_0808f000: @ 0x0808F000
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _0808F00E
	b _0808F14E
_0808F00E:
	lsls r0, r0, #2
	ldr r1, _0808F018 @ =_0808F01C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808F018: .4byte _0808F01C
_0808F01C: @ jump table
	.4byte _0808F04C @ case 0
	.4byte _0808F12C @ case 1
	.4byte _0808F05A @ case 2
	.4byte _0808F068 @ case 3
	.4byte _0808F080 @ case 4
	.4byte _0808F092 @ case 5
	.4byte _0808F0C4 @ case 6
	.4byte _0808F0F4 @ case 7
	.4byte _0808F102 @ case 8
	.4byte _0808F118 @ case 9
	.4byte _0808F12C @ case 10
	.4byte _0808F146 @ case 11
_0808F04C:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	b _0808F124
_0808F05A:
	ldr r1, _0808F07C @ =0x00007502
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F068:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F07C: .4byte 0x00007502
_0808F080:
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb9
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F092:
	ldr r1, _0808F0EC @ =0x00007503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	mov r2, sp
	movs r3, #0
	bl FUN_080aed8c
	ldr r0, _0808F0F0 @ =0x00000145
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F0C4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ands r0, r1
	cmp r0, #0
	beq _0808F13E
	movs r0, #5
	strb r0, [r4, #0xe]
	b _0808F14E
	.align 2, 0
_0808F0EC: .4byte 0x00007503
_0808F0F0: .4byte 0x00000145
_0808F0F4:
	ldr r1, _0808F114 @ =0x00007504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F102:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F114: .4byte 0x00007504
_0808F118:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_0808F124:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F12C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
_0808F13E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808F14E
_0808F146:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808F14E:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f158
FUN_0808f158: @ 0x0808F158
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f15c
FUN_0808f15c: @ 0x0808F15C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F176
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F194 @ =0x083693A0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F176:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0808F18C
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F18C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F194: .4byte 0x083693A0

	thumb_func_start FUN_0808f198
FUN_0808f198: @ 0x0808F198
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f19c
FUN_0808f19c: @ 0x0808F19C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808f1a0
FUN_0808f1a0: @ 0x0808F1A0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f1a4
FUN_0808f1a4: @ 0x0808F1A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F1BE
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F1DC @ =0x083693A0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F1BE:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0808F1D4
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F1D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F1DC: .4byte 0x083693A0

	thumb_func_start FUN_0808f1e0
FUN_0808f1e0: @ 0x0808F1E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0808F22A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F22A
	ldr r2, _0808F21C @ =0x083693B8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808F22A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0808F220
	movs r0, #3
	b _0808F226
	.align 2, 0
_0808F21C: .4byte 0x083693B8
_0808F220:
	cmp r1, #0x30
	bne _0808F22A
	movs r0, #5
_0808F226:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808F22A:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808f234
FUN_0808f234: @ 0x0808F234
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _0808F24C
	cmp r0, #0xe
	beq _0808F24C
	cmp r0, #0xf
	bne _0808F276
_0808F24C:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F276
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _0808F26E
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xff
	b _0808F274
_0808F26E:
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xfe
_0808F274:
	strb r0, [r1]
_0808F276:
	pop {r0}
	bx r0
	.align 2, 0
