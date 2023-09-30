	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807d6c0
FUN_0807d6c0: @ 0x0807D6C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0807D718 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0807D710
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0807D71C @ =gEnemyFnTable
	movs r1, #0x23
	strb r1, [r3, #9]
	adds r0, #0x8c
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
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_0807D710:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D718: .4byte gZakoHeaderPtr
_0807D71C: .4byte gEnemyFnTable

	thumb_func_start FUN_0807d720
FUN_0807d720: @ 0x0807D720
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807d724
FUN_0807d724: @ 0x0807D724
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807D776
	ldr r1, _0807D764 @ =gEnemyFnTable
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
	bne _0807D768
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0807D76A
	strb r4, [r2, #0xd]
	b _0807D76C
	.align 2, 0
_0807D764: .4byte gEnemyFnTable
_0807D768:
	movs r0, #1
_0807D76A:
	strb r0, [r2, #0xd]
_0807D76C:
	adds r0, r2, #0
	bl Mellnet_Die
	movs r0, #1
	b _0807D778
_0807D776:
	movs r0, #0
_0807D778:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807d780
FUN_0807d780: @ 0x0807D780
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _0807D806
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0807D806
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0807D7A0
	cmp r0, #1
	beq _0807D7E4
	b _0807D806
_0807D7A0:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807D806
	ldr r1, _0807D7DC @ =0x08367C98
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807D7E0 @ =0x08367CB4
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
_0807D7D6:
	movs r0, #1
	b _0807D808
	.align 2, 0
_0807D7DC: .4byte 0x08367C98
_0807D7E0: .4byte 0x08367CB4
_0807D7E4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807D804
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0807D800 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807D7D6
	strb r5, [r4, #0xf]
	b _0807D806
	.align 2, 0
_0807D800: .4byte 0x00020001
_0807D804:
	strb r0, [r4, #0xf]
_0807D806:
	movs r0, #0
_0807D808:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807d810
FUN_0807d810: @ 0x0807D810
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0807D850
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807D850
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0807D83C
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0807D850
_0807D83C:
	ldr r2, _0807D858 @ =0x08367D3C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807D850
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807D850:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D858: .4byte 0x08367D3C

	thumb_func_start Mellnet_Init
Mellnet_Init: @ 0x0807D85C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0807D8C4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807D8C8 @ =0x08367D44
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
	ldr r1, _0807D8CC @ =0x08367CDC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #4
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807D8D0 @ =FUN_0807d720
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, r4, #0
	bl Mellnet_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8C4: .4byte gEnemyFnTable
_0807D8C8: .4byte 0x08367D44
_0807D8CC: .4byte 0x08367CDC
_0807D8D0: .4byte FUN_0807d720

	thumb_func_start Mellnet_Update
Mellnet_Update: @ 0x0807D8D4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807d724
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807D914
	adds r0, r4, #0
	bl FUN_0807d810
	adds r0, r4, #0
	bl FUN_0807d780
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807D914
	ldr r1, _0807D91C @ =0x08367C98
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807D920 @ =0x08367CB4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807D914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D91C: .4byte 0x08367C98
_0807D920: .4byte 0x08367CB4

	thumb_func_start Mellnet_Die
Mellnet_Die: @ 0x0807D924
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x10]
	cmp r3, #0
	bne _0807D978
	ldr r0, _0807D970 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807D978
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
	ldr r1, _0807D974 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _0807D988
	.align 2, 0
_0807D970: .4byte gCurStory
_0807D974: .4byte gEnemyFnTable
_0807D978:
	ldr r0, _0807D98C @ =0x08367CD0
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_0807D988:
	pop {r0}
	bx r0
	.align 2, 0
_0807D98C: .4byte 0x08367CD0

	thumb_func_start FUN_0807d990
FUN_0807d990:
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807d994
FUN_0807d994: @ 0x0807D994
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0807D9B0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807D9AC
	movs r1, #0
	movs r0, #6
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807D9AC:
	pop {r0}
	bx r0
	.align 2, 0
_0807D9B0: .4byte 0x00020001

	thumb_func_start FUN_0807d9b4
FUN_0807d9b4: @ 0x0807D9B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0807D9CA
	bl isKilled
	cmp r0, #0
	beq _0807D9EA
_0807D9CA:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807DA08 @ =0x08367CF4
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0807D9EA
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807D9EA:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0807DA0C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807DA00
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807DA00:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA08: .4byte 0x08367CF4
_0807DA0C: .4byte 0x00020001

	thumb_func_start FUN_0807da10
FUN_0807da10: @ 0x0807DA10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807DA2A
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807DA30 @ =0x08367D0C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DA2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA30: .4byte 0x08367D0C

	thumb_func_start FUN_0807da34
FUN_0807da34: @ 0x0807DA34
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807DA44
	cmp r0, #1
	beq _0807DA76
	b _0807DA90
_0807DA44:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807DA98 @ =0x08367CF4
	bl SetDDP
	ldr r2, _0807DA9C @ =0x08367D46
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DA76:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0807DA8A
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807DA8A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807DA90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA98: .4byte 0x08367CF4
_0807DA9C: .4byte 0x08367D46

	thumb_func_start FUN_0807daa0
FUN_0807daa0: @ 0x0807DAA0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0807DB38
	cmp r0, #1
	bgt _0807DAB4
	cmp r0, #0
	beq _0807DABE
	b _0807DB94
_0807DAB4:
	cmp r0, #2
	beq _0807DB68
	cmp r0, #3
	beq _0807DB7A
	b _0807DB94
_0807DABE:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0807DAD4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0807DADA
_0807DAD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807DADA:
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
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	ldr r1, _0807DB5C @ =0xFFFFFD00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0x15
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807DB60 @ =0x08367CF4
	bl SetDDP
	ldr r2, _0807DB64 @ =0x08367D4A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DB38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807DB52
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DB52:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0807DB94
	.align 2, 0
_0807DB5C: .4byte 0xFFFFFD00
_0807DB60: .4byte 0x08367CF4
_0807DB64: .4byte 0x08367D4A
_0807DB68:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DB7A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0807DB8E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807DB8E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807DB94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807db9c
FUN_0807db9c:
	.byte 0xF0, 0xB5, 0x47, 0x46
	.byte 0x80, 0xB4, 0x06, 0x1C, 0xB0, 0x7B, 0x04, 0x28, 0x00, 0xD9, 0xB6, 0xE0, 0x80, 0x00, 0x02, 0x49
	.byte 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0x00, 0x00, 0xBC, 0xDB, 0x07, 0x08, 0xD0, 0xDB, 0x07, 0x08
	.byte 0xEA, 0xDB, 0x07, 0x08, 0xAA, 0xDC, 0x07, 0x08, 0xE4, 0xDC, 0x07, 0x08, 0xEE, 0xDC, 0x07, 0x08
	.byte 0x06, 0x20, 0xB0, 0x74, 0x31, 0x1C, 0xB8, 0x31, 0x04, 0x20, 0x08, 0x70, 0x70, 0x6D, 0x70, 0x66
	.byte 0xB0, 0x6D, 0xB0, 0x66, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x34, 0x1C, 0xB8, 0x34, 0x22, 0x78
	.byte 0x01, 0x32, 0x38, 0x4B, 0x19, 0x68, 0x38, 0x48, 0x48, 0x43, 0x38, 0x49, 0x40, 0x18, 0x40, 0x00
	.byte 0x41, 0x08, 0x19, 0x60, 0x40, 0x0C, 0x07, 0x21, 0x08, 0x40, 0x12, 0x18, 0x22, 0x70, 0x20, 0x78
	.byte 0x09, 0x21, 0x80, 0xF0, 0x75, 0xFE, 0x20, 0x70, 0x75, 0x6E, 0x31, 0x48, 0x80, 0x46, 0x45, 0x44
	.byte 0x24, 0x78, 0x20, 0x1C, 0x03, 0x21, 0x80, 0xF0, 0x6B, 0xFE, 0x00, 0x06, 0x00, 0x0B, 0x2D, 0x18
	.byte 0x70, 0x6D, 0x2D, 0x1A, 0xB7, 0x6E, 0x47, 0x44, 0x20, 0x1C, 0x03, 0x21, 0x80, 0xF0, 0x24, 0xFE
	.byte 0x00, 0x06, 0x00, 0x0B, 0x3F, 0x18, 0xB0, 0x6D, 0x3F, 0x1A, 0x28, 0x12, 0x04, 0x1C, 0x44, 0x43
	.byte 0x38, 0x12, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x24, 0x18, 0x20, 0x1C, 0x80, 0xF0, 0x76, 0xFC
	.byte 0x00, 0x04, 0x04, 0x0A, 0x28, 0x02, 0x21, 0x1C, 0x80, 0xF0, 0x5A, 0xFD, 0x05, 0x1C, 0x38, 0x02
	.byte 0x21, 0x1C, 0x80, 0xF0, 0x55, 0xFD, 0x07, 0x1C, 0xE8, 0x00, 0x40, 0x1B, 0xC0, 0x01, 0x00, 0x28
	.byte 0x00, 0xDA, 0xFF, 0x30, 0x05, 0x12, 0xF8, 0x00, 0xC0, 0x1B, 0xC0, 0x01, 0x00, 0x28, 0x00, 0xDA
	.byte 0xFF, 0x30, 0x07, 0x12, 0xF5, 0x65, 0x37, 0x66, 0xE0, 0x21, 0x89, 0x00, 0x20, 0x1C, 0x80, 0xF0
	.byte 0x3F, 0xFD, 0xF0, 0x74, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x70, 0x6D, 0xF1, 0x6D, 0x40, 0x18
	.byte 0x70, 0x65, 0xB0, 0x6D, 0x31, 0x6E, 0x40, 0x18, 0xB0, 0x65, 0xF0, 0x7C, 0x01, 0x38, 0xF0, 0x74
	.byte 0x00, 0x06, 0x00, 0x28, 0x02, 0xD1, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0x30, 0x1C, 0x99, 0xF7
	.byte 0xC5, 0xFC, 0x22, 0xE0, 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00
	.byte 0x00, 0xF0, 0xFF, 0xFF, 0x08, 0x20, 0xF0, 0x74, 0xB0, 0x7B, 0x01, 0x30, 0xB0, 0x73, 0xF0, 0x7C
	.byte 0x01, 0x38, 0xF0, 0x74, 0x00, 0x06, 0x00, 0x28, 0x0C, 0xD1, 0xB0, 0x7C, 0x01, 0x38, 0xB0, 0x74
	.byte 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29, 0x03, 0xD1, 0x04, 0x20, 0x70, 0x73, 0xB1, 0x73, 0x01, 0xE0
	.byte 0x01, 0x20, 0xB0, 0x73, 0x30, 0x1C, 0x99, 0xF7, 0xA1, 0xFC, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_0807dd24
FUN_0807dd24: @ 0x0807DD24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #5
	bls _0807DD30
	b _0807DEDE
_0807DD30:
	lsls r0, r0, #2
	ldr r1, _0807DD3C @ =_0807DD40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807DD3C: .4byte _0807DD40
_0807DD40: @ jump table
	.4byte _0807DD58 @ case 0
	.4byte _0807DE6C @ case 1
	.4byte _0807DE34 @ case 2
	.4byte _0807DE6C @ case 3
	.4byte _0807DE8C @ case 4
	.4byte _0807DEC4 @ case 5
_0807DD58:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807DD80 @ =0x08367CF4
	bl SetDDP
	movs r2, #0
	ldr r0, _0807DD84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0807DD72
	movs r2, #1
_0807DD72:
	cmp r2, #0
	beq _0807DD88
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0807DD8E
	.align 2, 0
_0807DD80: .4byte 0x08367CF4
_0807DD84: .4byte pZero2
_0807DD88:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807DD8E:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _0807DE28 @ =pZero2
	ldr r1, [r0]
	ldr r5, [r1, #0x54]
	ldr r0, [r6, #0x54]
	subs r5, r5, r0
	ldr r4, [r1, #0x58]
	ldr r0, _0807DE2C @ =0xFFFFE800
	adds r4, r4, r0
	ldr r0, [r6, #0x58]
	subs r4, r4, r0
	asrs r0, r5, #8
	adds r7, r0, #0
	muls r7, r0, r7
	asrs r0, r4, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r7, r7, r0
	adds r0, r7, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r7, r0, #8
	lsls r5, r5, #8
	adds r0, r5, #0
	adds r1, r7, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r4, r4, #8
	adds r0, r4, #0
	adds r1, r7, #0
	bl __divsi3
	lsls r5, r5, #2
	lsls r0, r0, #2
	str r5, [r6, #0x5c]
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x71
	movs r7, #0
	ldrsb r7, [r0, r7]
	ldr r2, _0807DE30 @ =0x08367D4E
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	movs r3, #3
	bl GotoMotion
	movs r0, #3
	b _0807DE64
	.align 2, 0
_0807DE28: .4byte pZero2
_0807DE2C: .4byte 0xFFFFE800
_0807DE30: .4byte 0x08367D4E
_0807DE34:
	adds r0, r6, #0
	adds r0, #0x71
	movs r7, #0
	ldrsb r7, [r0, r7]
	ldr r2, _0807DE88 @ =0x08367D4E
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r2, #4
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	movs r3, #3
	bl GotoMotion
	movs r0, #0xf
_0807DE64:
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807DE6C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807DEDE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0807DEDE
	.align 2, 0
_0807DE88: .4byte 0x08367D4E
_0807DE8C:
	adds r0, r6, #0
	adds r0, #0x71
	movs r7, #0
	ldrsb r7, [r0, r7]
	ldr r2, _0807DEE4 @ =0x08367D4E
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r2, #8
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	movs r3, #3
	bl GotoMotion
	movs r0, #3
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807DEC4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0807DEDE
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_0807DEDE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DEE4: .4byte 0x08367D4E

	thumb_func_start FUN_0807dee8
FUN_0807dee8: @ 0x0807DEE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807DEF8
	cmp r0, #1
	beq _0807DF2C
	b _0807DF90
_0807DEF8:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r2, [r0]
	ldr r3, _0807DF98 @ =0x08367D5A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r3, #3
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807DF2C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0807DF8A
	ldr r0, _0807DF9C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0807DF8A
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
	ldr r1, _0807DFA0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0807DF8A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807DF90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807DF98: .4byte 0x08367D5A
_0807DF9C: .4byte gStageRun+232
_0807DFA0: .4byte gEnemyFnTable

	thumb_func_start FUN_0807dfa4
FUN_0807dfa4: @ 0x0807DFA4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807DFF4
	ldr r2, _0807DFF0 @ =0x08367D5E
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	b _0807E000
	.align 2, 0
_0807DFF0: .4byte 0x08367D5E
_0807DFF4:
	ldr r2, _0807E014 @ =0x08367D5E
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
_0807E000:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0807E018
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	b _0807E024
	.align 2, 0
_0807E014: .4byte 0x08367D5E
_0807E018:
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
_0807E024:
	adds r1, r4, #0
	ldr r3, _0807E054 @ =gMission
	ldrh r2, [r3, #0xc]
	ldr r0, _0807E058 @ =0x0000270E
	cmp r2, r0
	bhi _0807E034
	adds r0, r2, #1
	strh r0, [r3, #0xc]
_0807E034:
	adds r0, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0807E05C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E054: .4byte gMission
_0807E058: .4byte 0x0000270E
_0807E05C: .4byte gEnemyFnTable

	thumb_func_start FUN_0807e060
FUN_0807e060: @ 0x0807E060
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807E072
	cmp r5, #1
	beq _0807E126
	b _0807E16C
_0807E072:
	movs r6, #0
	ldr r0, _0807E0EC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0807E084
	movs r6, #1
_0807E084:
	lsls r0, r6, #8
	subs r0, r1, r0
	str r0, [r4, #0x54]
	ldr r1, _0807E0F0 @ =0x00004705
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
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0807E0F8
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _0807E0F4 @ =0x08367D64
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b84f4
	b _0807E10E
	.align 2, 0
_0807E0EC: .4byte pZero2
_0807E0F0: .4byte 0x00004705
_0807E0F4: .4byte 0x08367D64
_0807E0F8:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _0807E174 @ =0x08367D64
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b857c
_0807E10E:
	ldr r0, [sp, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807E126:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807E13E
	str r1, [r4, #0x60]
_0807E13E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E166
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807E16C
_0807E166:
	adds r0, r4, #0
	bl FUN_0807dfa4
_0807E16C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E174: .4byte 0x08367D64

	thumb_func_start FUN_0807e178
FUN_0807e178: @ 0x0807E178
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0807E188
	cmp r0, #1
	beq _0807E236
	b _0807E276
_0807E188:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E218 @ =0x08367D24
	bl SetDDP
	ldr r2, _0807E21C @ =0x08367D66
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r0, r0, #0x1f
	movs r1, #2
	ands r0, r1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0807E220 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0807E224 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0807E228
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0807E230
	.align 2, 0
_0807E218: .4byte 0x08367D24
_0807E21C: .4byte 0x08367D66
_0807E220: .4byte pZero2
_0807E224: .4byte 0xFFFFE800
_0807E228:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0807E230:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E236:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807E24E
	str r1, [r5, #0x60]
_0807E24E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807E270
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807E276
_0807E270:
	adds r0, r5, #0
	bl FUN_0807dfa4
_0807E276:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
