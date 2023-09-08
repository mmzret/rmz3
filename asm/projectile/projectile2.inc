	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080aed8c
FUN_080aed8c: @ 0x080AED8C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080AEDE8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AEDDE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AEDEC @ =gProjectileFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
	str r7, [r3, #0x28]
_080AEDDE:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AEDE8: .4byte gProjectileHeaderPtr
_080AEDEC: .4byte gProjectileFnTable

	thumb_func_start FUN_080aedf0
FUN_080aedf0: @ 0x080AEDF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0x11]
	cmp r6, #0
	bne _080AEE3C
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080AEE4C @ =0x0836D2E4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080AEE50 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r6, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
_080AEE3C:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl FUN_080aee54
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AEE4C: .4byte 0x0836D2E4
_080AEE50: .4byte gProjectileFnTable

	thumb_func_start FUN_080aee54
FUN_080aee54: @ 0x080AEE54
	push {lr}
	adds r2, r0, #0
	ldr r0, _080AEEA0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AEEA8
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080AEEA4 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl FUN_080aeec0
	b _080AEEB8
	.align 2, 0
_080AEEA0: .4byte gCurStory
_080AEEA4: .4byte gProjectileFnTable
_080AEEA8:
	ldr r0, _080AEEBC @ =0x0836D2E0
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080AEEB8:
	pop {r0}
	bx r0
	.align 2, 0
_080AEEBC: .4byte 0x0836D2E0

	thumb_func_start FUN_080aeec0
FUN_080aeec0: @ 0x080AEEC0
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080AEEF8 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080AEEF8: .4byte gProjectileFnTable

	thumb_func_start FUN_080aeefc
FUN_080aeefc: @ 0x080AEEFC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	ands r3, r1
	cmp r3, #0
	beq _080AEF74
	movs r1, #0
	str r1, [r2]
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl CreateSmoke
	ldr r1, _080AEF70 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080AEF52
	adds r1, #0xb9
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080AEF52:
	ldr r0, [r4, #0x28]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080AEF5E
	b _080AF0F4
_080AEF5E:
	movs r0, #1
	adds r1, r5, #0
	bl CreateSmoke
	movs r0, #6
	adds r1, r5, #0
	bl TryDropItem
	b _080AF0F4
	.align 2, 0
_080AEF70: .4byte gProjectileFnTable
_080AEF74:
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080AEF98
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	b _080AEFAA
_080AEF98:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AEFC8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
_080AEFAA:
	bl CreateSmoke
	ldr r1, _080AEFC4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AF0F4
	.align 2, 0
_080AEFC4: .4byte gProjectileFnTable
_080AEFC8:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080AF012
	cmp r5, #1
	bgt _080AEFD8
	cmp r5, #0
	beq _080AEFDE
	b _080AF0F4
_080AEFD8:
	cmp r5, #2
	beq _080AF0CE
	b _080AF0F4
_080AEFDE:
	ldr r1, _080AF054 @ =0x0000750A
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x60]
	ldr r2, _080AF058 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080AF05C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080AF060 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	lsls r1, r1, #1
	bl __umodsi3
	subs r0, #0xf0
	str r0, [r4, #0x5c]
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AF012:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AF022
	str r1, [r4, #0x60]
_080AF022:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	beq _080AF0C6
	ldr r0, _080AF064 @ =0xFFFFF900
	cmp r5, r0
	blt _080AF0C6
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080AF068
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080AF070
	.align 2, 0
_080AF054: .4byte 0x0000750A
_080AF058: .4byte RNG_0202f388
_080AF05C: .4byte 0x000343FD
_080AF060: .4byte 0x00269EC3
_080AF064: .4byte 0xFFFFF900
_080AF068:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080AF070:
	adds r1, r0, #0
	cmp r1, #0
	beq _080AF0B8
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080AF0B8
	adds r2, r1, #0
	cmp r1, #0
	bge _080AF086
	rsbs r2, r1, #0
_080AF086:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	ble _080AF0B8
	adds r2, r1, #0
	cmp r1, #0
	bge _080AF096
	rsbs r2, r1, #0
_080AF096:
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r2, r0
	bgt _080AF0B8
	cmp r1, #0
	bge _080AF0A4
	rsbs r1, r1, #0
_080AF0A4:
	adds r0, r5, #0
	cmp r0, #0
	bge _080AF0AC
	rsbs r0, r0, #0
_080AF0AC:
	cmp r1, r0
	bgt _080AF0B8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	b _080AF0C0
_080AF0B8:
	ldr r0, [r4, #0x60]
	asrs r0, r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
_080AF0C0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AF0C6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080AF0F4
_080AF0CE:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AF0DE
	str r1, [r4, #0x60]
_080AF0DE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080AF0F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af0fc
FUN_080af0fc: @ 0x080AF0FC
	push {lr}
	ldr r2, _080AF110 @ =0x0836D3E8
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF110: .4byte 0x0836D3E8

	thumb_func_start FUN_080af114
FUN_080af114: @ 0x080AF114
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080AF15C
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
	ldr r1, _080AF158 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080AF1A2
	.align 2, 0
_080AF158: .4byte gProjectileFnTable
_080AF15C:
	ldrh r1, [r1, #0xe]
	ldr r0, _080AF1A8 @ =0x00000101
	cmp r1, r0
	bne _080AF1A2
	ldr r1, _080AF1AC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF1B0 @ =0x00008603
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl FUN_080af308
_080AF1A2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF1A8: .4byte 0x00000101
_080AF1AC: .4byte gProjectileFnTable
_080AF1B0: .4byte 0x00008603

	thumb_func_start FUN_080af1b4
FUN_080af1b4: @ 0x080AF1B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080AF20C @ =0x0836D328
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldr r1, _080AF210 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r6, [r4, #0xd]
	adds r0, r4, #0
	bl InitRotatableMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_080af308
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF20C: .4byte 0x0836D328
_080AF210: .4byte gProjectileFnTable

	thumb_func_start FUN_080af214
FUN_080af214: @ 0x080AF214
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF24C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl InitRotatableMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_080af308
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF24C: .4byte gProjectileFnTable

	thumb_func_start FUN_080af250
FUN_080af250: @ 0x080AF250
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080AF2A8 @ =0x0836D388
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldr r1, _080AF2AC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r6, [r4, #0xd]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_080af308
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF2A8: .4byte 0x0836D388
_080AF2AC: .4byte gProjectileFnTable

	thumb_func_start FUN_080af2b0
FUN_080af2b0: @ 0x080AF2B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080AF300 @ =0x0836D3B8
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldr r1, _080AF304 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_080af308
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF300: .4byte 0x0836D3B8
_080AF304: .4byte gProjectileFnTable

	thumb_func_start FUN_080af308
FUN_080af308: @ 0x080AF308
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF328 @ =0x0836D400
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF328: .4byte 0x0836D400

	thumb_func_start FUN_080af32c
FUN_080af32c: @ 0x080AF32C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AF350
	ldr r1, _080AF34C @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	b _080AF360
	.align 2, 0
_080AF34C: .4byte gProjectileFnTable
_080AF350:
	ldr r0, _080AF364 @ =0x0836D418
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080AF360:
	pop {r0}
	bx r0
	.align 2, 0
_080AF364: .4byte 0x0836D418

	thumb_func_start FUN_080af368
FUN_080af368: @ 0x080AF368
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldr r6, [r0, #0x54]
	ldr r7, [r0, #0x58]
	ldrb r0, [r0, #0xa]
	lsrs r4, r0, #4
	movs r0, #1
	ands r4, r0
	adds r2, r4, #0
	cmp r2, #0
	beq _080AF388
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080AF38E
_080AF388:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF38E:
	strb r0, [r3, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, #0
	bne _080AF3BC
	movs r0, #1
_080AF3BC:
	lsls r0, r0, #0xc
	adds r0, r6, r0
	str r0, [r3, #0x54]
	ldr r1, _080AF3E4 @ =0xFFFFE400
	adds r0, r7, r1
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080AF3DC
	strb r5, [r3, #0xd]
	ldr r1, _080AF3E8 @ =0x00008601
	adds r0, r3, #0
	bl SetMotion
_080AF3DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF3E4: .4byte 0xFFFFE400
_080AF3E8: .4byte 0x00008601

	thumb_func_start FUN_080af3ec
FUN_080af3ec: @ 0x080AF3EC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x28]
	ldrb r0, [r1, #0xf]
	cmp r0, #2
	bls _080AF408
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	adds r0, r3, #0
	bl FUN_080af46c
	b _080AF462
_080AF408:
	ldr r5, [r1, #0x54]
	ldr r6, [r1, #0x58]
	ldrb r0, [r1, #0xa]
	lsrs r4, r0, #4
	movs r0, #1
	ands r4, r0
	adds r2, r4, #0
	cmp r2, #0
	beq _080AF422
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080AF428
_080AF422:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF428:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r4, #0
	bne _080AF452
	movs r1, #1
_080AF452:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #9
	adds r0, r5, r0
	str r0, [r3, #0x54]
	ldr r1, _080AF468 @ =0xFFFFE900
	adds r0, r6, r1
	str r0, [r3, #0x58]
_080AF462:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF468: .4byte 0xFFFFE900

	thumb_func_start FUN_080af46c
FUN_080af46c: @ 0x080AF46C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AF490
	ldr r1, _080AF48C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	b _080AF506
	.align 2, 0
_080AF48C: .4byte gProjectileFnTable
_080AF490:
	ldr r1, _080AF4BC @ =0x0836D424
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r5, #0x2c]
	cmp r0, r4
	bne _080AF4C0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bhi _080AF4C0
	cmp r0, #4
	bne _080AF508
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	b _080AF508
	.align 2, 0
_080AF4BC: .4byte 0x0836D424
_080AF4C0:
	ldr r0, _080AF510 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080AF508
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
	ldr r1, _080AF514 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_080AF506:
	str r0, [r4, #0x14]
_080AF508:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF510: .4byte gStageRun+232
_080AF514: .4byte gProjectileFnTable

	thumb_func_start FUN_080af518
FUN_080af518: @ 0x080AF518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r7, #0
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AF570 @ =0x0836D358
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r4, #1
	strb r4, [r6, #0xe]
	movs r1, #0x86
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x28]
	ldr r5, [r0, #0x54]
	ldr r1, [r0, #0x58]
	mov ip, r1
	ldrb r0, [r0, #0xa]
	lsrs r3, r0, #4
	ands r3, r4
	movs r1, #0
	cmp r3, #0
	bne _080AF562
	movs r1, #1
_080AF562:
	adds r2, r1, #0
	cmp r2, #0
	beq _080AF574
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AF57A
	.align 2, 0
_080AF570: .4byte 0x0836D358
_080AF574:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF57A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, #0
	beq _080AF5A0
	movs r0, #1
_080AF5A0:
	adds r3, r0, #0
	lsls r0, r3, #5
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r5, r0
	str r0, [r6, #0x54]
	ldr r0, _080AF5C8 @ =0xFFFFF200
	add r0, ip
	str r0, [r6, #0x58]
	lsls r0, r3, #0xa
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	lsls r0, r3, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF5C8: .4byte 0xFFFFF200

	thumb_func_start FUN_080af5cc
FUN_080af5cc: @ 0x080AF5CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r4, #0
	adds r2, #0x5c
	adds r3, r4, #0
	adds r3, #0x64
	bl FUN_080afdf0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080AF5EC
	movs r0, #2
	strb r0, [r4, #0xe]
_080AF5EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af5f4
FUN_080af5f4: @ 0x080AF5F4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r4, #0
	adds r2, #0x5c
	adds r3, r4, #0
	adds r3, #0x64
	bl FUN_080afe38
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080AF614
	movs r0, #1
	strb r0, [r4, #0xe]
_080AF614:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af61c
FUN_080af61c: @ 0x080AF61C
	push {lr}
	ldr r2, _080AF630 @ =0x0836D430
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF630: .4byte 0x0836D430

	thumb_func_start FUN_080af634
FUN_080af634: @ 0x080AF634
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF658 @ =0x00008605
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af65c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF658: .4byte 0x00008605

	thumb_func_start FUN_080af65c
FUN_080af65c: @ 0x080AF65C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r5, r1, r0
	str r5, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r3, r1, r0
	str r3, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080AF6B2
	ldr r2, _080AF700 @ =gSineTable
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r0, r5, r0
	adds r1, r3, r1
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AF6B2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0x10]
	strb r1, [r4, #0xd]
_080AF6B2:
	ldr r0, _080AF704 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF6FA
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
	ldr r1, _080AF708 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF6FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF700: .4byte gSineTable
_080AF704: .4byte gStageRun+232
_080AF708: .4byte gProjectileFnTable

	thumb_func_start FUN_080af70c
FUN_080af70c: @ 0x080AF70C
	push {lr}
	adds r3, r0, #0
	adds r0, #0x8c
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080AF744 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r3, #0x14]
	strb r2, [r3, #0xd]
	adds r0, r3, #0
	bl FUN_080af308
	pop {r0}
	bx r0
	.align 2, 0
_080AF744: .4byte gProjectileFnTable

	thumb_func_start FUN_080af748
FUN_080af748: @ 0x080AF748
	push {lr}
	ldr r2, _080AF75C @ =0x0836D438
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF75C: .4byte 0x0836D438

	thumb_func_start FUN_080af760
FUN_080af760: @ 0x080AF760
	push {r4, lr}
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
	ldr r1, _080AF7A8 @ =0x00008605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r4, #0x60]
	ldr r1, _080AF7AC @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r0, #0x1c
	strb r0, [r4, #0x13]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af7b0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF7A8: .4byte 0x00008605
_080AF7AC: .4byte 0xFFFFFA00

	thumb_func_start FUN_080af7b0
FUN_080af7b0: @ 0x080AF7B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AF7CE
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080AF7D2
_080AF7CE:
	ldrb r0, [r5, #0xa]
	orrs r0, r1
_080AF7D2:
	strb r0, [r5, #0xa]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _080AF814
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080AF810 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080AF8A8
	.align 2, 0
_080AF810: .4byte gProjectileFnTable
_080AF814:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AF824
	str r1, [r5, #0x60]
_080AF824:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r4, _080AF898 @ =gSineTable
	ldrb r2, [r5, #0x12]
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r2, r2, r4
	movs r6, #0
	ldrsh r3, [r2, r6]
	lsls r3, r3, #3
	ldrb r2, [r5, #0x12]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r4, #0
	ldrsh r2, [r2, r4]
	lsls r2, r2, #3
	adds r0, r0, r3
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _080AF88A
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #1
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080AF886
	adds r0, #0xff
_080AF886:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
_080AF88A:
	ldrb r1, [r5, #0x12]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080AF89C
	adds r1, #8
	b _080AF89E
	.align 2, 0
_080AF898: .4byte gSineTable
_080AF89C:
	subs r1, #8
_080AF89E:
	strb r1, [r5, #0x12]
	adds r1, #0x20
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
_080AF8A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af8b0
FUN_080af8b0: @ 0x080AF8B0
	push {lr}
	ldr r2, _080AF8C4 @ =0x0836D440
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF8C4: .4byte 0x0836D440

	thumb_func_start FUN_080af8c8
FUN_080af8c8: @ 0x080AF8C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF8E4 @ =0x00008605
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af8e8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF8E4: .4byte 0x00008605

	thumb_func_start FUN_080af8e8
FUN_080af8e8: @ 0x080AF8E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AF912
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
	b _080AF97E
_080AF912:
	ldr r1, [r5, #0x54]
	str r1, [r4, #0x54]
	ldr r3, _080AF9A0 @ =gSineTable
	ldrb r2, [r4, #0x12]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r1, [r5, #0x58]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r2, #0x20
	adds r0, r4, #0
	adds r0, #0x24
	movs r5, #0
	strb r2, [r0]
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	ldr r0, _080AF9A4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF998
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_080AF97E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF9A8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF998:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF9A0: .4byte gSineTable
_080AF9A4: .4byte gStageRun+232
_080AF9A8: .4byte gProjectileFnTable

	thumb_func_start nop_080af9ac
nop_080af9ac: @ 0x080AF9AC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080af9b0
FUN_080af9b0: @ 0x080AF9B0
	push {lr}
	ldr r2, _080AF9C4 @ =0x0836D44C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF9C4: .4byte 0x0836D44C

	thumb_func_start FUN_080af9c8
FUN_080af9c8: @ 0x080AF9C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF9F0 @ =0x00008602
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	movs r2, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r2, [r4, #0x13]
	adds r0, r4, #0
	bl FUN_080af9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF9F0: .4byte 0x00008602

	thumb_func_start FUN_080af9f4
FUN_080af9f4: @ 0x080AF9F4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AFA6A
	movs r5, #0
	ldr r7, _080AFB10 @ =gSineTable
	mov r6, sp
_080AFA1E:
	ldrb r3, [r4, #0x13]
	lsls r3, r3, #4
	lsls r0, r5, #6
	adds r3, r3, r0
	lsls r3, r3, #0x18
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	lsrs r2, r3, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x17
	adds r3, r3, r0
	lsrs r3, r3, #0x17
	adds r3, r3, r7
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #3
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	lsls r0, r2, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldr r1, [r6, #4]
	adds r0, r0, r1
	str r0, [r6, #4]
	mov r0, sp
	movs r1, #0xf0
	lsls r1, r1, #2
	movs r3, #0
	bl FUN_080afbfc
	adds r5, #1
	cmp r5, #3
	ble _080AFA1E
_080AFA6A:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AFAC2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFAC2:
	ldr r0, _080AFB18 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AFB08
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFB08:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFB10: .4byte gSineTable
_080AFB14: .4byte gProjectileFnTable
_080AFB18: .4byte gStageRun+232

	thumb_func_start FUN_080afb1c
FUN_080afb1c: @ 0x080AFB1C
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AFB5E
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
	ldr r1, _080AFB64 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080AFB5E:
	pop {r0}
	bx r0
	.align 2, 0
_080AFB64: .4byte gProjectileFnTable

	thumb_func_start FUN_080afb68
FUN_080afb68: @ 0x080AFB68
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AFBAC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbb0
FUN_080afbb0: @ 0x080AFBB0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFBF4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFBEC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFBF8 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r4, [r3, #0x10]
	str r5, [r3, #0x28]
_080AFBEC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFBF4: .4byte gProjectileHeaderPtr
_080AFBF8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbfc
FUN_080afbfc: @ 0x080AFBFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	mov r8, r4
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _080AFC90 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFC82
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFC94 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldr r2, _080AFC98 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC64
	adds r0, #0xff
_080AFC64:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC78
	adds r0, #0xff
_080AFC78:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
	mov r0, r8
	strb r0, [r3, #0x12]
	strb r7, [r3, #0x11]
_080AFC82:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFC90: .4byte gProjectileHeaderPtr
_080AFC94: .4byte gProjectileFnTable
_080AFC98: .4byte gSineTable

	thumb_func_start FUN_080afc9c
FUN_080afc9c: @ 0x080AFC9C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFCE4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFCDC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFCE8 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x28]
_080AFCDC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFCE4: .4byte gProjectileHeaderPtr
_080AFCE8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afcec
FUN_080afcec: @ 0x080AFCEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	mov r8, r5
	ldr r0, _080AFD98 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080AFD8C
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFD9C @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r4, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r2, _080AFDA0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD50
	adds r0, #0xff
_080AFD50:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD64
	adds r0, #0xff
_080AFD64:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	mov r0, r8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x80
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0xc0
	bl FUN_080afc9c
_080AFD8C:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFD98: .4byte gProjectileHeaderPtr
_080AFD9C: .4byte gProjectileFnTable
_080AFDA0: .4byte gSineTable

	thumb_func_start FUN_080afda4
FUN_080afda4: @ 0x080AFDA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AFDE8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFDDE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFDEC @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_080AFDDE:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AFDE8: .4byte gProjectileHeaderPtr
_080AFDEC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afdf0
FUN_080afdf0: @ 0x080AFDF0
	push {r4, r5, lr}
	ldr r5, [r2]
	ldr r3, [r1]
	adds r4, r3, r5
	str r4, [r1]
	ldr r3, [r1, #4]
	ldr r2, [r2, #4]
	adds r3, r3, r2
	str r3, [r1, #4]
	adds r1, r0, #0
	adds r1, #0xdc
	ldr r1, [r1]
	ldr r2, _080AFE28 @ =0xFFFFB400
	adds r1, r1, r2
	ldr r3, _080AFE2C @ =0xFFFFDA00
	adds r2, r4, r3
	adds r0, #0xd4
	ldr r0, [r0]
	subs r4, r2, r0
	cmp r4, r1
	bls _080AFE30
	adds r0, r4, #0
	muls r0, r5, r0
	cmp r0, #0
	ble _080AFE30
	movs r0, #1
	b _080AFE32
	.align 2, 0
_080AFE28: .4byte 0xFFFFB400
_080AFE2C: .4byte 0xFFFFDA00
_080AFE30:
	movs r0, #0
_080AFE32:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080afe38
FUN_080afe38: @ 0x080AFE38
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r6, r3, #0
	ldr r5, [r6]
	ldr r0, [r2]
	adds r3, r0, r5
	str r3, [r2]
	ldr r1, [r2, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	ble _080AFE54
	subs r1, #8
	str r1, [r2, #4]
_080AFE54:
	ldr r0, [r4]
	adds r0, r0, r3
	str r0, [r4]
	ldr r0, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _080AFE70 @ =0x000003FF
	adds r1, r3, r0
	ldr r0, _080AFE74 @ =0x000007FE
	cmp r1, r0
	bhi _080AFE78
	movs r0, #0
	b _080AFE7E
	.align 2, 0
_080AFE70: .4byte 0x000003FF
_080AFE74: .4byte 0x000007FE
_080AFE78:
	rsbs r0, r5, #0
	str r0, [r6]
	movs r0, #1
_080AFE7E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080afe84
FUN_080afe84: @ 0x080AFE84
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AFED4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFECC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFED8 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080AFECC:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AFED4: .4byte gProjectileHeaderPtr
_080AFED8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afedc
FUN_080afedc: @ 0x080AFEDC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AFF2C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFF22
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFF30 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080AFF22:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AFF2C: .4byte gProjectileHeaderPtr
_080AFF30: .4byte gProjectileFnTable

	thumb_func_start FUN_080aff34
FUN_080aff34: @ 0x080AFF34
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _080AFF80 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFF78
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFF84 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r5, [r3, #0x28]
_080AFF78:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFF80: .4byte gProjectileHeaderPtr
_080AFF84: .4byte gProjectileFnTable

	thumb_func_start FUN_080aff88
FUN_080aff88: @ 0x080AFF88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080AFFDC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFFD2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFFE0 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080AFFD2:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AFFDC: .4byte gProjectileHeaderPtr
_080AFFE0: .4byte gProjectileFnTable

	thumb_func_start FUN_080affe4
FUN_080affe4: @ 0x080AFFE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080B0040 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B0038
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B0044 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #6
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xbc
	strh r6, [r0]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080B0038:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B0040: .4byte gProjectileHeaderPtr
_080B0044: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0048
FUN_080b0048: @ 0x080B0048
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _080B0094 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B008C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B0098 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r3, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #7
	strb r0, [r3, #0x10]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r5, [r3, #0x28]
_080B008C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B0094: .4byte gProjectileHeaderPtr
_080B0098: .4byte gProjectileFnTable

	thumb_func_start FUN_080b009c
FUN_080b009c: @ 0x080B009C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B00DC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B00D2
	adds r0, #0x25
	movs r3, #0
	movs r2, #8
	strb r2, [r0]
	ldr r0, _080B00E0 @ =gProjectileFnTable
	movs r1, #0x29
	strb r1, [r4, #9]
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
_080B00D2:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B00DC: .4byte gProjectileHeaderPtr
_080B00E0: .4byte gProjectileFnTable

	thumb_func_start FUN_080b00e4
FUN_080b00e4: @ 0x080B00E4
	push {lr}
	ldr r2, _080B0110 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldrb r1, [r0, #0x10]
	movs r2, #0
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	strb r2, [r0, #0xf]
	movs r1, #0xff
	strb r1, [r0, #0x12]
	bl omega2_080b0114
	pop {r0}
	bx r0
	.align 2, 0
_080B0110: .4byte gProjectileFnTable

	thumb_func_start omega2_080b0114
omega2_080b0114: @ 0x080B0114
	push {lr}
	ldr r2, _080B0128 @ =0x0836D468
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B0128: .4byte 0x0836D468

	thumb_func_start FUN_080b012c
FUN_080b012c: @ 0x080B012C
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080B0164 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080B0164: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0168
FUN_080b0168: @ 0x080B0168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B019C
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B0198 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B0206
	.align 2, 0
_080B0198: .4byte gProjectileFnTable
_080B019C:
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B01A8
	cmp r6, #1
	beq _080B01F8
	b _080B0206
_080B01A8:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B020C @ =0x0836D624
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	str r6, [r5, #0x60]
	ldr r0, _080B0210 @ =0xFFFFFB00
	str r0, [r5, #0x5c]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B01F8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B0206:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B020C: .4byte 0x0836D624
_080B0210: .4byte 0xFFFFFB00

	thumb_func_start FUN_080b0214
FUN_080b0214: @ 0x080B0214
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080B02BE
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080B0268
	cmp r5, #1
	bgt _080B0230
	cmp r5, #0
	beq _080B0236
	b _080B02D0
_080B0230:
	cmp r5, #2
	beq _080B0282
	b _080B02D0
_080B0236:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	strb r5, [r4, #0x12]
	movs r1, #0xb9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B0268:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _080B02D0
	b _080B02B6
_080B0282:
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #0
	adds r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B02A8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B02AE
_080B02A8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B02AE:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080B02D0
_080B02B6:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080B02BE:
	ldr r1, _080B02D8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B02D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B02D8: .4byte gProjectileFnTable

	thumb_func_start FUN_080b02dc
FUN_080b02dc: @ 0x080B02DC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0300
	ldr r1, _080B02FC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B0368
	.align 2, 0
_080B02FC: .4byte gProjectileFnTable
_080B0300:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080B030C
	cmp r5, #1
	beq _080B0334
	b _080B0368
_080B030C:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x12]
	ldr r1, _080B034C @ =0x0000B902
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B0334:
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0350
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B0356
	.align 2, 0
_080B034C: .4byte 0x0000B902
_080B0350:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B0356:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r4, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080B0368:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start omega2_080b0370
omega2_080b0370: @ 0x080B0370
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #9
	bhi _080B0388
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0388
	movs r0, #0xa
	strb r0, [r7, #0xe]
_080B0388:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x10
	bls _080B0390
	b _080B07BA
_080B0390:
	lsls r0, r0, #2
	ldr r1, _080B039C @ =_080B03A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B039C: .4byte _080B03A0
_080B03A0: @ jump table
	.4byte _080B03E4 @ case 0
	.4byte _080B0460 @ case 1
	.4byte _080B055C @ case 2
	.4byte _080B05E4 @ case 3
	.4byte _080B06A4 @ case 4
	.4byte _080B07BA @ case 5
	.4byte _080B07BA @ case 6
	.4byte _080B07BA @ case 7
	.4byte _080B07BA @ case 8
	.4byte _080B07BA @ case 9
	.4byte _080B06FC @ case 10
	.4byte _080B0706 @ case 11
	.4byte _080B07BA @ case 12
	.4byte _080B07BA @ case 13
	.4byte _080B07BA @ case 14
	.4byte _080B0754 @ case 15
	.4byte _080B0776 @ case 16
_080B03E4:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #2
	movs r6, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080B04C4 @ =0x0836D63C
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _080B04C8 @ =0x0000B901
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #2
	bl FUN_080afedc
	movs r0, #0x99
	lsls r0, r0, #1
	bl PlaySound
	ldr r2, [r7, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	str r0, [r7, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	str r0, [r7, #0x58]
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0460:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080B0500
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0500
	ldr r0, _080B04CC @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	str r2, [sp]
	ldr r0, [r7, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	cmp r2, #0
	bne _080B0492
	cmp r1, #0
	beq _080B04D0
_080B0492:
	ldr r1, [sp]
	adds r0, r1, #0
	muls r0, r1, r0
	ldr r2, [sp, #4]
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r3, [sp]
	lsls r0, r3, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	ldr r1, [sp, #4]
	lsls r0, r1, #8
	adds r1, r4, #0
	bl __divsi3
	b _080B04D6
	.align 2, 0
_080B04C4: .4byte 0x0836D63C
_080B04C8: .4byte 0x0000B901
_080B04CC: .4byte pZero2
_080B04D0:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
_080B04D6:
	str r0, [sp, #4]
	ldr r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r3, [sp, #4]
	cmp r3, #0
	bge _080B04F0
	lsls r0, r3, #1
	adds r0, r0, r3
	b _080B04F6
_080B04F0:
	ldr r1, [sp, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
_080B04F6:
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	movs r0, #0x18
	strb r0, [r7, #0x13]
_080B0500:
	ldr r0, _080B0540 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0512
	movs r0, #0x18
	strb r0, [r7, #0x13]
_080B0512:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B0544
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080B07BA
	.align 2, 0
_080B0540: .4byte pZero2
_080B0544:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B0556
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B0556
	b _080B07BA
_080B0556:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	b _080B07BA
_080B055C:
	movs r6, #0
	ldr r1, [r7, #0x64]
	ldr r0, [r7, #0x54]
	subs r1, r1, r0
	adds r4, r1, #0
	ldr r2, [r7, #0x68]
	ldr r0, [r7, #0x58]
	subs r2, r2, r0
	adds r5, r2, #0
	cmp r1, #0
	bne _080B0576
	cmp r2, #0
	beq _080B059E
_080B0576:
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
	b _080B05A2
_080B059E:
	movs r4, #0x80
	lsls r4, r4, #1
_080B05A2:
	lsls r0, r4, #8
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	lsls r0, r5, #8
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	str r6, [r7, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x68]
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r0, _080B063C @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r3]
	adds r3, #4
	ldr r0, [r2, #0x58]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080B0640 @ =0x0836D654
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B05E4:
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r3, r1, r0
	str r3, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r0, _080B0644 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _080B0648 @ =0x000027FF
	adds r0, r0, r2
	cmp r1, r0
	bge _080B064C
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r1, [r3]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3]
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _080B063C @ =pZero2
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r3]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _080B0666
	.align 2, 0
_080B063C: .4byte pZero2
_080B0640: .4byte 0x0836D654
_080B0644: .4byte gStageRun+232
_080B0648: .4byte 0x000027FF
_080B064C:
	ldr r0, _080B069C @ =pZero2
	ldr r2, [r0]
	adds r0, r7, #0
	adds r0, #0xb4
	ldr r0, [r0]
	adds r0, r3, r0
	str r0, [r2, #0x54]
	adds r1, r7, #0
	adds r1, #0xb8
	ldr r0, [r7, #0x58]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r2, #0x58]
_080B0666:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	cmp r0, #0
	bgt _080B0688
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _080B06A0 @ =0x0836D66C
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0688:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B06E2
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B069A
	b _080B07BA
_080B069A:
	b _080B06E2
	.align 2, 0
_080B069C: .4byte pZero2
_080B06A0: .4byte 0x0836D66C
_080B06A4:
	adds r3, r7, #0
	adds r3, #0xb4
	ldr r1, [r3]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3]
	adds r2, r7, #0
	adds r2, #0xb8
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _080B06F8 @ =pZero2
	ldr r4, [r0]
	ldr r0, [r7, #0x54]
	ldr r1, [r3]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080B06E2:
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B07BA
	movs r0, #0xf
	strb r0, [r7, #0xe]
	b _080B07BA
	.align 2, 0
_080B06F8: .4byte pZero2
_080B06FC:
	movs r0, #0x1a
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0706:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B0732
	movs r0, #2
	strb r0, [r7, #0xe]
	b _080B07BA
_080B0732:
	ldr r0, _080B0750 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	cmp r0, #0
	beq _080B07BA
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B07A8
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	b _080B07A4
	.align 2, 0
_080B0750: .4byte gStageRun+232
_080B0754:
	adds r0, r7, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0776:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B0786
	subs r0, #1
	strb r0, [r7, #0x12]
_080B0786:
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080B079A
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B07A0
_080B079A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B07A0:
	strb r0, [r7, #0xa]
	lsls r0, r2, #0x18
_080B07A4:
	cmp r0, #0
	bne _080B07BA
_080B07A8:
	ldr r1, _080B07C4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B07BA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B07C4: .4byte gProjectileFnTable

	thumb_func_start omega2_080b07c8
omega2_080b07c8: @ 0x080B07C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0x15
	bls _080B07D4
	b _080B0BA4
_080B07D4:
	lsls r0, r0, #2
	ldr r1, _080B07E0 @ =_080B07E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B07E0: .4byte _080B07E4
_080B07E4: @ jump table
	.4byte _080B083C @ case 0
	.4byte _080B089C @ case 1
	.4byte _080B09B0 @ case 2
	.4byte _080B09E4 @ case 3
	.4byte _080B0B92 @ case 4
	.4byte _080B0BA4 @ case 5
	.4byte _080B0BA4 @ case 6
	.4byte _080B0BA4 @ case 7
	.4byte _080B0BA4 @ case 8
	.4byte _080B0BA4 @ case 9
	.4byte _080B0AB8 @ case 10
	.4byte _080B0AC8 @ case 11
	.4byte _080B0BA4 @ case 12
	.4byte _080B0BA4 @ case 13
	.4byte _080B0BA4 @ case 14
	.4byte _080B0BA4 @ case 15
	.4byte _080B0BA4 @ case 16
	.4byte _080B0BA4 @ case 17
	.4byte _080B0BA4 @ case 18
	.4byte _080B0BA4 @ case 19
	.4byte _080B0B34 @ case 20
	.4byte _080B0B5E @ case 21
_080B083C:
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #2
	movs r5, #0
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B08B8 @ =0x0836D69C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #7
	strb r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _080B08BC @ =0x00000133
	bl PlaySound
	str r5, [r6, #0x64]
	ldr r0, _080B08C0 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	strb r5, [r6, #0x13]
	strb r5, [r6, #0x11]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B089C:
	movs r4, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _080B08C4
	movs r0, #0xa
	strb r0, [r6, #0xe]
	b _080B0BA4
	.align 2, 0
_080B08B8: .4byte 0x0836D69C
_080B08BC: .4byte 0x00000133
_080B08C0: .4byte 0xFFFFFD00
_080B08C4:
	ldr r2, _080B08DC @ =pZero2
	ldr r3, [r2]
	ldrb r1, [r3, #0xa]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080B08E0
	strb r4, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080B099C
	.align 2, 0
_080B08DC: .4byte pZero2
_080B08E0:
	ldr r0, [r6, #0x54]
	ldr r1, [r3, #0x54]
	subs r3, r0, r1
	adds r4, r0, #0
	cmp r3, #0
	ble _080B08F6
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r3, r0
	bgt _080B0900
	b _080B0952
_080B08F6:
	subs r1, r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080B0952
_080B0900:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _080B0952
	ldr r0, [r2]
	ldr r0, [r0, #0x54]
	cmp r4, r0
	ble _080B0940
	ldr r1, _080B0938 @ =0xFFFFFD00
	adds r0, r4, r1
	str r0, [r6, #0x54]
	ldr r2, _080B093C @ =0xFFFFF500
	adds r0, r4, r2
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r2, r0, #0
	cmp r2, #0
	beq _080B0948
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r0, #1
	strb r0, [r6, #0xf]
	b _080B0948
	.align 2, 0
_080B0938: .4byte 0xFFFFFD00
_080B093C: .4byte 0xFFFFF500
_080B0940:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6, #0x54]
_080B0948:
	movs r4, #0xc0
	lsls r4, r4, #2
	movs r0, #0
	str r0, [r6, #0x68]
	b _080B099A
_080B0952:
	movs r0, #1
	strb r0, [r6, #0x13]
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, r2
	str r0, [r6, #0x58]
	movs r0, #0xa0
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r4, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _080B0984
	ldr r0, [r6, #0x58]
	adds r0, r0, r2
	str r0, [r6, #0x58]
	movs r0, #0
	strb r0, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080B0996
_080B0984:
	ldr r0, [r6, #0x68]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldr r1, _080B09A8 @ =0x00002FFF
	cmp r0, r1
	ble _080B0996
	strb r2, [r6, #0x13]
_080B0996:
	movs r4, #0x80
	lsls r4, r4, #2
_080B099A:
	str r4, [r6, #0x5c]
_080B099C:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080B09AC @ =0x00000EFF
	b _080B0B10
	.align 2, 0
_080B09A8: .4byte 0x00002FFF
_080B09AC: .4byte 0x00000EFF
_080B09B0:
	ldr r0, _080B09CC @ =pZero2
	ldr r2, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B09DA
	ldr r1, [r6, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _080B09D4
	ldr r0, _080B09D0 @ =0xFFFFFD00
	b _080B09D8
	.align 2, 0
_080B09CC: .4byte pZero2
_080B09D0: .4byte 0xFFFFFD00
_080B09D4:
	movs r0, #0xc0
	lsls r0, r0, #2
_080B09D8:
	str r0, [r6, #0x5c]
_080B09DA:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B09E4:
	movs r5, #0
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080B0A08 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0A0C
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
_080B0A02:
	movs r5, #0xc0
	lsls r5, r5, #2
	b _080B0A74
	.align 2, 0
_080B0A08: .4byte pZero2
_080B0A0C:
	ldr r1, [r6, #0x5c]
	cmp r1, #0
	bge _080B0A34
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, _080B0A30 @ =0xFFFFF800
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B0A02
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	b _080B0A68
	.align 2, 0
_080B0A30: .4byte 0xFFFFF800
_080B0A34:
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _080B0A64
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080B0A60 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	cmp r1, r0
	beq _080B0A02
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	b _080B0A02
	.align 2, 0
_080B0A60: .4byte 0xFFFFF800
_080B0A64:
	cmp r0, #1
	bne _080B0A74
_080B0A68:
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r5, r1, #0
_080B0A74:
	ldr r0, _080B0AB0 @ =gStageRun+232
	adds r4, r6, #0
	adds r4, #0x54
	adds r1, r4, #0
	bl CalcFromCamera
	cmp r0, #0
	beq _080B0A9A
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080B0A94
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0A9A
_080B0A94:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0A9A:
	ldr r0, [r6, #0x64]
	adds r0, r0, r5
	str r0, [r6, #0x64]
	ldr r1, _080B0AB4 @ =0x00000EFF
	cmp r0, r1
	bgt _080B0AA8
	b _080B0BA4
_080B0AA8:
	ldrb r2, [r6, #0x11]
	adds r0, r6, #0
	adds r1, r4, #0
	b _080B0B1C
	.align 2, 0
_080B0AB0: .4byte gStageRun+232
_080B0AB4: .4byte 0x00000EFF
_080B0AB8:
	ldr r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0AC8:
	ldr r2, [r6, #0x58]
	ldr r0, _080B0B2C @ =0xFFFFFC00
	adds r1, r2, r0
	ldr r3, [r6, #0x68]
	subs r1, r3, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x58]
	cmp r2, r3
	ble _080B0AE6
	movs r0, #1
	strb r0, [r6, #0xe]
_080B0AE6:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B0B04
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #2
	strb r0, [r6, #0xe]
_080B0B04:
	ldr r0, [r6, #0x64]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080B0B30 @ =0x00000FFF
_080B0B10:
	cmp r0, r1
	ble _080B0BA4
	adds r1, r6, #0
	adds r1, #0x54
	ldrb r2, [r6, #0x11]
	adds r0, r6, #0
_080B0B1C:
	bl FUN_080aff88
	movs r0, #0
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0x11]
	adds r0, #1
	strb r0, [r6, #0x11]
	b _080B0BA4
	.align 2, 0
_080B0B2C: .4byte 0xFFFFFC00
_080B0B30: .4byte 0x00000FFF
_080B0B34:
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r1, _080B0B70 @ =0x0000BA01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B0B5E:
	ldrb r1, [r6, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0B74
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080B0B7A
	.align 2, 0
_080B0B70: .4byte 0x0000BA01
_080B0B74:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B0B7A:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080B0B92
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B0BA4
_080B0B92:
	ldr r1, _080B0BAC @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080B0BA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0BAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080b0bb0
FUN_080b0bb0: @ 0x080B0BB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #9
	bhi _080B0BE0
	ldr r6, [r5, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bhi _080B0BDC
	ldrb r0, [r5, #0x11]
	movs r1, #6
	bl __umodsi3
	adds r4, r0, #0
	ldrb r0, [r6, #0x11]
	movs r1, #6
	bl __umodsi3
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _080B0BE0
_080B0BDC:
	movs r0, #0xa
	strb r0, [r5, #0xe]
_080B0BE0:
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B0C40
	cmp r6, #1
	bgt _080B0BF0
	cmp r6, #0
	beq _080B0BFA
	b _080B0C98
_080B0BF0:
	cmp r6, #0xa
	beq _080B0C50
	cmp r6, #0xb
	beq _080B0C76
	b _080B0C98
_080B0BFA:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B0C48 @ =0x0836D6CC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	strb r6, [r5, #0x12]
	ldr r1, _080B0C4C @ =0x0000BA02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C40:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080B0C98
	.align 2, 0
_080B0C48: .4byte 0x0836D6CC
_080B0C4C: .4byte 0x0000BA02
_080B0C50:
	adds r0, r5, #0
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
	strb r0, [r5, #0xa]
	ldr r1, _080B0CA0 @ =0x0000BA03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B0C76:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B0C98
	ldr r1, _080B0CA4 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B0C98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0CA0: .4byte 0x0000BA03
_080B0CA4: .4byte gProjectileFnTable

	thumb_func_start omega2_080b0ca8
omega2_080b0ca8: @ 0x080B0CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #9
	bhi _080B0CC8
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080B0CC8
	movs r0, #0xa
	strb r0, [r7, #0xe]
_080B0CC8:
	ldr r2, _080B0CF4 @ =pZero2
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B0CE0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x13
	bhi _080B0CE0
	movs r0, #0x14
	strb r0, [r7, #0xe]
_080B0CE0:
	ldrb r0, [r7, #0xe]
	cmp r0, #0x14
	bls _080B0CE8
	b _080B109C
_080B0CE8:
	lsls r0, r0, #2
	ldr r1, _080B0CF8 @ =_080B0CFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B0CF4: .4byte pZero2
_080B0CF8: .4byte _080B0CFC
_080B0CFC: @ jump table
	.4byte _080B0D50 @ case 0
	.4byte _080B0D7E @ case 1
	.4byte _080B0DA4 @ case 2
	.4byte _080B0FBC @ case 3
	.4byte _080B109C @ case 4
	.4byte _080B109C @ case 5
	.4byte _080B109C @ case 6
	.4byte _080B109C @ case 7
	.4byte _080B109C @ case 8
	.4byte _080B109C @ case 9
	.4byte _080B1080 @ case 10
	.4byte _080B109C @ case 11
	.4byte _080B109C @ case 12
	.4byte _080B109C @ case 13
	.4byte _080B109C @ case 14
	.4byte _080B109C @ case 15
	.4byte _080B109C @ case 16
	.4byte _080B109C @ case 17
	.4byte _080B109C @ case 18
	.4byte _080B109C @ case 19
	.4byte _080B1080 @ case 20
_080B0D50:
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x24
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080B0D7E:
	ldr r0, [r7, #0x28]
	ldr r1, [r0, #0x54]
	str r1, [r7, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080B0D96
	b _080B0F6A
_080B0D96:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B0DA2
	b _080B109C
_080B0DA2:
	b _080B0F6A
_080B0DA4:
	movs r6, #0
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x64]
	str r0, [sp]
	ldrb r1, [r7, #0x11]
	cmp r1, #0
	bne _080B0DD4
	ldr r1, _080B0DD0 @ =0xFFFFBC00
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0x13
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #4
	str r0, [r7, #0x60]
	movs r6, #2
	b _080B0E04
	.align 2, 0
_080B0DD0: .4byte 0xFFFFBC00
_080B0DD4:
	cmp r1, #1
	bne _080B0DF0
	ldr r2, _080B0DEC @ =0xFFFF8C00
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	subs r0, #0x1f
	str r0, [r7, #0x60]
	movs r6, #3
	b _080B0E04
	.align 2, 0
_080B0DEC: .4byte 0xFFFF8C00
_080B0DF0:
	cmp r1, #2
	bne _080B0E04
	ldr r4, _080B0F74 @ =0xFFFF5C00
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #0x23
	str r0, [r7, #0x5c]
	subs r0, #0x50
	str r0, [r7, #0x60]
	movs r6, #4
_080B0E04:
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x60]
	lsls r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	mov r1, sp
	bl FUN_080b0048
	adds r0, r7, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0E6A
	ldr r0, [r7, #0x28]
	bl CreateGhost84
	str r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0E4E
	str r7, [r0, #0x2c]
_080B0E4E:
	ldr r2, _080B0F7C @ =gWindowRegBuffer
	ldrb r1, [r2, #0xe]
	movs r0, #0xe1
	ands r0, r1
	movs r3, #0
	movs r1, #0x1f
	orrs r0, r1
	strb r0, [r2, #0xe]
	ldr r1, _080B0F80 @ =gPaletteManager
	ldr r4, _080B0F84 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	strh r3, [r2, #6]
	strh r3, [r2, #0xa]
_080B0E6A:
	ldr r5, _080B0F88 @ =gStageRun+232
	ldr r4, [r5, #0x3c]
	ldr r1, _080B0F8C @ =0x00003FFF
	adds r0, r4, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _080B0F78 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	ldr r2, [r7, #0x60]
	str r2, [sp, #8]
	ldr r1, [r7, #0x58]
	mov ip, r1
	cmp r0, #0
	beq _080B0EBC
	ldr r3, _080B0F7C @ =gWindowRegBuffer
	ldr r1, [r7, #0x68]
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	subs r1, r1, r4
	asrs r1, r1, #8
	movs r2, #0xff
	ands r1, r2
	add r0, ip
	subs r0, r0, r4
	ldr r2, [sp, #8]
	adds r0, r0, r2
	asrs r0, r0, #8
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r3, #0xa]
	ldrh r1, [r3]
	ldr r0, _080B0F90 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r3]
_080B0EBC:
	ldr r1, _080B0F94 @ =0x020302DC
	ldr r4, [r7, #0x54]
	ldr r3, _080B0F98 @ =0xFFFF8801
	adds r4, r4, r3
	ldr r2, [r5, #0x38]
	subs r4, r4, r2
	ldr r0, [r7, #0x5c]
	adds r4, r4, r0
	asrs r0, r4, #8
	subs r0, #0x10
	mov sl, r0
	str r0, [r1]
	ldr r0, _080B0F9C @ =0x020302C4
	mov r8, r0
	ldr r0, _080B0FA0 @ =0x020302D4
	mov r1, sl
	str r1, [r0]
	mov r0, r8
	str r1, [r0]
	ldr r1, _080B0FA4 @ =0x020302CC
	movs r0, #0
	str r0, [r1]
	ldr r0, [r7, #0x64]
	adds r0, r0, r3
	subs r0, r0, r2
	subs r4, r4, r0
	lsls r1, r6, #8
	adds r0, r4, r1
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	subs r4, r4, r1
	ldr r1, _080B0FAC @ =0x020302C8
	str r4, [r1]
	ldr r2, [r7, #0x68]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldr r3, [r5, #0x3c]
	subs r2, r2, r3
	asrs r2, r2, #8
	mov sb, r2
	add r1, ip
	subs r1, r1, r3
	ldr r2, [sp, #8]
	adds r1, r1, r2
	asrs r6, r1, #8
	mov r1, sb
	subs r5, r1, r6
	adds r1, r5, #0
	bl __divsi3
	mov r8, r0
	ldr r2, _080B0FA8 @ =0x020302E4
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r2, r0, #0
	ldr r4, _080B0FAC @ =0x020302C8
	str r2, [r4]
	ldr r0, _080B0FB0 @ =0x020302D0
	str r6, [r0]
	ldr r0, _080B0FB4 @ =0x020302D8
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080B0F66
	mov r4, sl
	str r4, [r0, #0x74]
	ldr r0, [r7, #0x2c]
	str r6, [r0, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B0FB8 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	mov r1, sb
	str r1, [r0]
	ldr r0, [r7, #0x2c]
	mov r4, r8
	str r4, [r0, #0x5c]
	str r2, [r0, #0x64]
_080B0F66:
	movs r0, #0x14
	strb r0, [r7, #0x12]
_080B0F6A:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B0F74: .4byte 0xFFFF5C00
_080B0F78: .4byte pZero2
_080B0F7C: .4byte gWindowRegBuffer
_080B0F80: .4byte gPaletteManager
_080B0F84: .4byte 0x0000FFFF
_080B0F88: .4byte gStageRun+232
_080B0F8C: .4byte 0x00003FFF
_080B0F90: .4byte 0x0000BFFF
_080B0F94: .4byte 0x020302DC
_080B0F98: .4byte 0xFFFF8801
_080B0F9C: .4byte 0x020302C4
_080B0FA0: .4byte 0x020302D4
_080B0FA4: .4byte 0x020302CC
_080B0FA8: .4byte 0x020302E4
_080B0FAC: .4byte 0x020302C8
_080B0FB0: .4byte 0x020302D0
_080B0FB4: .4byte 0x020302D8
_080B0FB8: .4byte 0x020302C0
_080B0FBC:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r7, #0x58]
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1014
	ldr r1, _080B0FF4 @ =gPaletteManager
	ldr r2, _080B0FF8 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldrb r1, [r7, #0x12]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080B1004
	ldr r2, _080B0FFC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B1000 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _080B1014
	.align 2, 0
_080B0FF4: .4byte gPaletteManager
_080B0FF8: .4byte 0x0000FFFF
_080B0FFC: .4byte gWindowRegBuffer
_080B1000: .4byte 0x0000BFFF
_080B1004:
	ldr r0, _080B1064 @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r1, r2
	strh r1, [r0]
	strb r3, [r0, #0xd]
_080B1014:
	ldr r1, [r7, #0x2c]
	cmp r1, #0
	beq _080B1048
	ldr r0, _080B1068 @ =0x020302DC
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B106C @ =0x020302D0
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1070 @ =0x020302C0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
	ldr r0, [r7, #0x2c]
	adds r0, #0x80
	ldr r1, _080B1074 @ =0x020302D8
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x2c]
	ldr r0, _080B1078 @ =0x020302E4
	ldr r0, [r0]
	str r0, [r1, #0x5c]
	ldr r0, _080B107C @ =0x020302C8
	ldr r0, [r0]
	str r0, [r1, #0x64]
_080B1048:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080B105E
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B109C
_080B105E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
	b _080B109C
	.align 2, 0
_080B1064: .4byte gWindowRegBuffer
_080B1068: .4byte 0x020302DC
_080B106C: .4byte 0x020302D0
_080B1070: .4byte 0x020302C0
_080B1074: .4byte 0x020302D8
_080B1078: .4byte 0x020302E4
_080B107C: .4byte 0x020302C8
_080B1080:
	ldr r2, _080B10AC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080B10B0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B10B4 @ =gProjectileFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080B109C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B10AC: .4byte gWindowRegBuffer
_080B10B0: .4byte 0x0000BFFF
_080B10B4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b10b8
FUN_080b10b8: @ 0x080B10B8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #1
	beq _080B1124
	cmp r6, #1
	bgt _080B10CC
	cmp r6, #0
	beq _080B10D2
	b _080B1162
_080B10CC:
	cmp r6, #0xa
	beq _080B1150
	b _080B1162
_080B10D2:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1140 @ =0x0836D6E4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1144 @ =0x0000BB06
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldr r0, _080B1148 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080B114C @ =0x00003FFF
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1124:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080B113A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1162
_080B113A:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _080B1162
	.align 2, 0
_080B1140: .4byte 0x0836D6E4
_080B1144: .4byte 0x0000BB06
_080B1148: .4byte gStageRun+232
_080B114C: .4byte 0x00003FFF
_080B1150:
	ldr r1, _080B1168 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1162:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1168: .4byte gProjectileFnTable

	thumb_func_start FUN_080b116c
FUN_080b116c: @ 0x080B116C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080B11EA
	cmp r0, #4
	beq _080B11EA
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1188
	cmp r6, #1
	beq _080B11B4
	b _080B1220
_080B1188:
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1228 @ =0x0836D48C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B11B4:
	ldr r2, [r5, #0x2c]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, _080B122C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	adds r2, #0xbc
	ldr r1, [r2]
	asrs r1, r1, #9
	adds r0, r5, #0
	adds r0, #0x74
	movs r2, #0x10
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080B1228 @ =0x0836D48C
	adds r1, r1, r2
	bl SetDDP
	ldr r0, [r5, #0x2c]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _080B1220
_080B11EA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1230 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080B1220:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1228: .4byte 0x0836D48C
_080B122C: .4byte pZero2
_080B1230: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1234
FUN_080b1234: @ 0x080B1234
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080B1290 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B1284
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B1294 @ =gProjectileFnTable
	movs r1, #0x2a
	strb r1, [r3, #9]
	adds r0, #0xa8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r4, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	str r7, [r3, #0x5c]
	mov r0, r8
	str r0, [r3, #0x60]
_080B1284:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1290: .4byte gProjectileHeaderPtr
_080B1294: .4byte gProjectileFnTable
_080B1298:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b129c
FUN_080b129c: @ 0x080B129C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080B12FC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B1300 @ =0x0836D730
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
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
	ldr r1, _080B1304 @ =0x0836D718
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080B1308 @ =0x080B1299
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080b130c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B12FC: .4byte gProjectileFnTable
_080B1300: .4byte 0x0836D730
_080B1304: .4byte 0x0836D718
_080B1308: .4byte 0x080B1299

	thumb_func_start FUN_080b130c
FUN_080b130c: @ 0x080B130C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080B1360
	ldr r0, _080B1358 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B1360
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080B135C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080B1380
	.align 2, 0
_080B1358: .4byte gCurStory
_080B135C: .4byte gProjectileFnTable
_080B1360:
	ldr r1, _080B1388 @ =0x0836D710
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080B138C @ =0x0836D714
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080B1380:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1388: .4byte 0x0836D710
_080B138C: .4byte 0x0836D714

	thumb_func_start FUN_080b1390
FUN_080b1390: @ 0x080B1390
	push {r4, lr}
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
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080B13D4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B13D4: .4byte gProjectileFnTable
_080B13D8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b13dc
FUN_080b13dc: @ 0x080B13DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B13EC
	cmp r0, #1
	beq _080B13FA
	b _080B144E
_080B13EC:
	ldr r1, _080B1454 @ =0x00008E0C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B13FA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1412
	str r1, [r4, #0x60]
_080B1412:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B143C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B144E
_080B143C:
	ldr r1, _080B1458 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B144E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1454: .4byte 0x00008E0C
_080B1458: .4byte gProjectileFnTable

	thumb_func_start FUN_080b145c
FUN_080b145c: @ 0x080B145C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080B14B0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B14A8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B14B4 @ =gProjectileFnTable
	movs r1, #0x2b
	strb r1, [r3, #9]
	adds r0, #0xac
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r5, [r3, #0x5c]
	movs r0, #0
	cmp r5, #0
	ble _080B14A4
	movs r0, #1
_080B14A4:
	strb r0, [r3, #0x12]
	strb r1, [r3, #0x10]
_080B14A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B14B0: .4byte gProjectileHeaderPtr
_080B14B4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b14b8
FUN_080b14b8: @ 0x080B14B8
	push {lr}
	ldr r2, _080B14EC @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldr r2, _080B14F0 @ =0x0836D77C
	ldrb r1, [r0, #0x10]
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0, #0xd]
	ldrb r1, [r0, #0xa]
	movs r2, #1
	orrs r1, r2
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #0xa]
	bl FUN_080b14f4
	pop {r0}
	bx r0
	.align 2, 0
_080B14EC: .4byte gProjectileFnTable
_080B14F0: .4byte 0x0836D77C

	thumb_func_start FUN_080b14f4
FUN_080b14f4: @ 0x080B14F4
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B153C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B1544
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
	ldr r1, _080B1540 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080B1554
	.align 2, 0
_080B153C: .4byte gCurStory
_080B1540: .4byte gProjectileFnTable
_080B1544:
	ldr r0, _080B1558 @ =0x0836D748
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080B1554:
	pop {r0}
	bx r0
	.align 2, 0
_080B1558: .4byte 0x0836D748

	thumb_func_start FUN_080b155c
FUN_080b155c: @ 0x080B155C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B156C
	cmp r6, #1
	beq _080B15E2
	b _080B1656
_080B156C:
	ldrb r1, [r5, #0xa]
	movs r0, #4
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B15A8 @ =0x0836D74C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, _080B15AC @ =0x0000DB0D
	adds r0, r5, #0
	bl SetMotion
	ldrb r2, [r5, #0x12]
	cmp r2, #0
	beq _080B15B0
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B15B6
	.align 2, 0
_080B15A8: .4byte 0x0836D74C
_080B15AC: .4byte 0x0000DB0D
_080B15B0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B15B6:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	movs r0, #0x55
	strb r0, [r5, #0x13]
	movs r0, #6
	strb r0, [r5, #0x12]
_080B15E2:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1610
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B160C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1656
	.align 2, 0
_080B160C: .4byte gProjectileFnTable
_080B1610:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080B164C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B1650
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080B1650
	ldr r1, _080B1648 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1650
	.align 2, 0
_080B1648: .4byte gProjectileFnTable
_080B164C:
	subs r0, #1
	strb r0, [r5, #0x12]
_080B1650:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B1656:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B165C:
	.byte 0x02, 0x1C, 0x91, 0x7A
	.byte 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49
	.byte 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61
	.byte 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080b1698
FUN_080b1698: @ 0x080B1698
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080B16E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B16E0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B16EC @ =gProjectileFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r5, [r3, #0x12]
	strb r4, [r3, #0x13]
_080B16E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B16E8: .4byte gProjectileHeaderPtr
_080B16EC: .4byte gProjectileFnTable
_080B16F0:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b16f4
FUN_080b16f4: @ 0x080B16F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080B1754 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B1758 @ =0x0836D7B4
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
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
	ldr r1, _080B175C @ =0x0836D79C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080B1760 @ =0x080B16F1
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080b1764
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1754: .4byte gProjectileFnTable
_080B1758: .4byte 0x0836D7B4
_080B175C: .4byte 0x0836D79C
_080B1760: .4byte 0x080B16F1

	thumb_func_start FUN_080b1764
FUN_080b1764: @ 0x080B1764
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B1790 @ =0x0836D794
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080B1794 @ =0x0836D798
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
_080B1790: .4byte 0x0836D794
_080B1794: .4byte 0x0836D798

	thumb_func_start FUN_080b1798
FUN_080b1798: @ 0x080B1798
	push {r4, lr}
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
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B17D4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17D4: .4byte gProjectileFnTable
_080B17D8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b17dc
FUN_080b17dc: @ 0x080B17DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B17EC
	cmp r0, #1
	beq _080B1834
	b _080B18C2
_080B17EC:
	movs r0, #0x40
	str r0, [r4, #0x64]
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Sqrt
	ldr r1, [r4, #0x64]
	rsbs r1, r1, #0
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r2, r1, #0
	muls r2, r3, r2
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080B1812
	str r1, [r4, #0x64]
	rsbs r0, r2, #0
	str r0, [r4, #0x5c]
_080B1812:
	lsls r0, r3, #1
	str r0, [r4, #0x68]
	movs r2, #0xa0
	ldrb r1, [r4, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x60]
	movs r1, #0xd7
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B1834:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _080B184C
	subs r0, #1
	str r0, [r4, #0x68]
	ldr r0, [r4, #0x64]
	adds r0, r1, r0
	str r0, [r4, #0x5c]
_080B184C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080B1880
	ldr r0, _080B1878 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B187C @ =0xFFFF2800
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bge _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080B1894
	.align 2, 0
_080B1878: .4byte gStageRun+232
_080B187C: .4byte 0xFFFF2800
_080B1880:
	ldr r0, _080B18C8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B18CC @ =0x0000D7FF
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	ble _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B1894:
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
	ldr r1, _080B18D0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080B18C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B18C8: .4byte gStageRun+232
_080B18CC: .4byte 0x0000D7FF
_080B18D0: .4byte gProjectileFnTable

	thumb_func_start FUN_080b18d4
FUN_080b18d4: @ 0x080B18D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080B192C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B1922
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B1930 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r6, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
_080B1922:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B192C: .4byte gProjectileHeaderPtr
_080B1930: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1934
FUN_080b1934: @ 0x080B1934
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B1988 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B197E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B198C @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B197E:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B1988: .4byte gProjectileHeaderPtr
_080B198C: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1990
FUN_080b1990: @ 0x080B1990
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B19E4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B19DA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B19E8 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B19DA:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B19E4: .4byte gProjectileHeaderPtr
_080B19E8: .4byte gProjectileFnTable

	thumb_func_start FUN_080b19ec
FUN_080b19ec: @ 0x080B19EC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B1A40 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B1A36
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B1A44 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B1A36:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B1A40: .4byte gProjectileHeaderPtr
_080B1A44: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1a48
FUN_080b1a48: @ 0x080B1A48
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r5, [r4, #0x10]
	cmp r5, #0
	bne _080B1A9C
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _080B1A98 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	b _080B1B0C
	.align 2, 0
_080B1A98: .4byte gProjectileFnTable
_080B1A9C:
	cmp r5, #1
	bne _080B1ACC
	movs r2, #0
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
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
	ldr r1, _080B1AC8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	b _080B1B00
	.align 2, 0
_080B1AC8: .4byte gProjectileFnTable
_080B1ACC:
	cmp r5, #2
	beq _080B1AD4
	cmp r5, #3
	bne _080B1B0C
_080B1AD4:
	movs r2, #0
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r3, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r1, _080B1B24 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
_080B1B00:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
_080B1B0C:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080b1b28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B24: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1b28
FUN_080b1b28: @ 0x080B1B28
	push {lr}
	ldr r2, _080B1B3C @ =0x0836D7CC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B1B3C: .4byte 0x0836D7CC
_080B1B40:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080b1b7c
FUN_080b1b7c: @ 0x080B1B7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1BA2
	adds r0, r5, #0
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
	strb r0, [r5, #0xa]
	b _080B1BBC
_080B1BA2:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B1BD4
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1BD4
_080B1BBC:
	ldr r1, _080B1BD0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1CAE
	.align 2, 0
_080B1BD0: .4byte gProjectileFnTable
_080B1BD4:
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1BE0
	cmp r6, #1
	beq _080B1CA0
	b _080B1CAE
_080B1BE0:
	movs r7, #0
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1C2C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C28 @ =0x0836D7DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb6
	lsls r1, r1, #7
	b _080B1C52
	.align 2, 0
_080B1C28: .4byte 0x0836D7DC
_080B1C2C:
	cmp r0, #1
	bne _080B1C60
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C5C @ =0x0836D7F4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb8
	lsls r1, r1, #7
_080B1C52:
	adds r0, r5, #0
	bl SetMotion
	b _080B1C8C
	.align 2, 0
_080B1C5C: .4byte 0x0836D7F4
_080B1C60:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1C8C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1CB4 @ =0x0836D80C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xbe
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
_080B1C8C:
	ldr r0, _080B1CB8 @ =FUN_080b2178
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1CA0:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B1CAE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1CB4: .4byte 0x0836D80C
_080B1CB8: .4byte FUN_080b2178

	thumb_func_start FUN_080b1cbc
FUN_080b1cbc: @ 0x080B1CBC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r6, [r0]
	cmp r6, #0
	beq _080B1D24
	subs r0, #0x30
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _080B1D0E
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	ldr r0, _080B1D20 @ =0x00000137
	bl PlaySound
_080B1D0E:
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	b _080B1EE2
	.align 2, 0
_080B1D20: .4byte 0x00000137
_080B1D24:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r7, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1D34
	b _080B1ED6
_080B1D34:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B1E0C
	cmp r0, #1
	bgt _080B1D44
	cmp r0, #0
	beq _080B1D52
	b _080B1EF4
_080B1D44:
	cmp r0, #2
	bne _080B1D4A
	b _080B1E5C
_080B1D4A:
	cmp r0, #3
	bne _080B1D50
	b _080B1EA0
_080B1D50:
	b _080B1EF4
_080B1D52:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1D9C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1D94 @ =0x0836D824
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1D98 @ =0x00000E08
	b _080B1DC0
	.align 2, 0
_080B1D94: .4byte 0x0836D824
_080B1D98: .4byte 0x00000E08
_080B1D9C:
	cmp r0, #1
	bne _080B1DD0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1DC8 @ =0x0836D83C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1DCC @ =0x00000E07
_080B1DC0:
	adds r0, r5, #0
	bl SetMotion
	b _080B1DFA
	.align 2, 0
_080B1DC8: .4byte 0x0836D83C
_080B1DCC: .4byte 0x00000E07
_080B1DD0:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1DFA
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1E4C @ =0x0836D854
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1E50 @ =0x00000E09
	adds r0, r5, #0
	bl SetMotion
_080B1DFA:
	ldr r0, _080B1E54 @ =FUN_080b21c0
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	subs r0, #0xa8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1E0C:
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1E1C
	str r1, [r5, #0x60]
_080B1E1C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _080B1E58 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1EF4
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _080B1E94
	.align 2, 0
_080B1E4C: .4byte 0x0836D854
_080B1E50: .4byte 0x00000E09
_080B1E54: .4byte FUN_080b21c0
_080B1E58: .4byte 0xFFFFF800
_080B1E5C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080B1E9C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	cmp r0, r1
	beq _080B1EF4
	str r6, [r5, #0x60]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0x28
	strb r0, [r5, #0x13]
_080B1E94:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080B1EF4
	.align 2, 0
_080B1E9C: .4byte 0xFFFFF000
_080B1EA0:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1EB0
	str r1, [r5, #0x60]
_080B1EB0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080B1ED6
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1EF4
_080B1ED6:
	ldr r1, [r5, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _080B1EE2
	subs r0, #1
	strb r0, [r1, #0xc]
_080B1EE2:
	ldr r1, _080B1EFC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1EF4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1EFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1f00
FUN_080b1f00: @ 0x080B1F00
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B1F12
	movs r0, #0xff
	strb r0, [r6, #0x12]
_080B1F12:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1F38
	ldr r1, _080B1F34 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B2030
	.align 2, 0
_080B1F34: .4byte gProjectileFnTable
_080B1F38:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B1F44
	cmp r0, #1
	beq _080B2010
	b _080B2030
_080B1F44:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, _080B1FC0 @ =0x000117FF
	cmp r1, r0
	ble _080B1FA2
	ldr r0, _080B1FC4 @ =0x00013BFF
	cmp r1, r0
	bgt _080B1FD4
	ldr r0, [r6, #0x54]
	ldr r4, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r4
	bl FUN_0800a31c
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_0800a22c
	ldr r0, [r6, #0x54]
	ldr r2, _080B1FCC @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	movs r4, #0x9e
	lsls r4, r4, #9
	cmp r0, r4
	bgt _080B1FA2
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r2, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	cmp r0, r4
	ble _080B1FD4
_080B1FA2:
	ldr r1, _080B1FD0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	b _080B2030
	.align 2, 0
_080B1FC0: .4byte 0x000117FF
_080B1FC4: .4byte 0x00013BFF
_080B1FC8: .4byte 0xFFFFF800
_080B1FCC: .4byte 0xFFFFE000
_080B1FD0: .4byte gProjectileFnTable
_080B1FD4:
	adds r1, r6, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x12
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B2038 @ =0x0836D86C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xf3
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B2010:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2020
	ldr r0, [r6, #0x54]
	ldr r1, _080B203C @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r6, #0x54]
_080B2020:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080B2040 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
_080B2030:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2038: .4byte 0x0836D86C
_080B203C: .4byte 0xFFFC4000
_080B2040: .4byte gStageRun+232

	thumb_func_start FUN_080b2044
FUN_080b2044: @ 0x080B2044
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B2056
	movs r0, #0xff
	strb r0, [r5, #0x12]
_080B2056:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B207C
	ldr r1, _080B2078 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B216C
	.align 2, 0
_080B2078: .4byte gProjectileFnTable
_080B207C:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bne _080B20C2
	ldrb r0, [r5, #0xe]
	cmp r0, #2
	beq _080B20C2
	ldr r1, [r5, #0x28]
	ldrh r0, [r1, #0xe]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0xe]
	ldr r0, _080B20D4 @ =0x00000137
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	movs r0, #2
	strb r0, [r5, #0xe]
_080B20C2:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B2116
	cmp r0, #1
	bgt _080B20D8
	cmp r0, #0
	beq _080B20DE
	b _080B216C
	.align 2, 0
_080B20D4: .4byte 0x00000137
_080B20D8:
	cmp r0, #2
	beq _080B214C
	b _080B216C
_080B20DE:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B2138 @ =0x0836D884
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080B213C @ =FUN_080b2204
	str r0, [r4, #0x24]
	ldr r1, _080B2140 @ =0x0000AA04
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B2116:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2126
	ldr r0, [r5, #0x54]
	ldr r1, _080B2144 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B2126:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080B2148 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	b _080B216C
	.align 2, 0
_080B2138: .4byte 0x0836D884
_080B213C: .4byte FUN_080b2204
_080B2140: .4byte 0x0000AA04
_080B2144: .4byte 0xFFFC4000
_080B2148: .4byte gStageRun+232
_080B214C:
	ldrb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080B215C
	movs r0, #0x22
	bl PlaySound
_080B215C:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B216C
	ldr r0, [r5, #0x54]
	ldr r1, _080B2174 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B216C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2174: .4byte 0xFFFC4000

	thumb_func_start FUN_080b2178
FUN_080b2178: @ 0x080B2178
	push {r4, lr}
	movs r4, #0
	ldr r3, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	ldrb r0, [r3, #0x11]
	cmp r0, #0
	bne _080B2190
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B2190
	movs r4, #1
_080B2190:
	ldrb r0, [r3, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21A0
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21A0
	movs r4, #1
_080B21A0:
	cmp r1, #2
	bne _080B21AC
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21AC
	movs r4, #1
_080B21AC:
	adds r1, r3, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	cmp r4, #1
	bne _080B21BA
	strb r4, [r1]
_080B21BA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b21c0
FUN_080b21c0: @ 0x080B21C0
	push {lr}
	movs r3, #0
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _080B21D8
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B21D8
	movs r3, #1
_080B21D8:
	ldrb r0, [r1, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21E8
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21E8
	movs r3, #1
_080B21E8:
	cmp r1, #2
	bne _080B21F4
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21F4
	movs r3, #1
_080B21F4:
	cmp r3, #1
	bne _080B21FE
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_080B21FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2204
FUN_080b2204: @ 0x080B2204
	push {lr}
	ldr r1, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _080B2218
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_080B2218:
	pop {r0}
	bx r0

	thumb_func_start FUN_080b221c
FUN_080b221c: @ 0x080B221C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080B2268 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B225E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B226C @ =gProjectileFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080B225E:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B2268: .4byte gProjectileHeaderPtr
_080B226C: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2270
FUN_080b2270: @ 0x080B2270
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080B22C0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B22B6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B22C4 @ =gProjectileFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	str r7, [r3, #0x2c]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080B22B6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B22C0: .4byte gProjectileHeaderPtr
_080B22C4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b22c8
FUN_080b22c8: @ 0x080B22C8
	push {lr}
	ldr r2, _080B22DC @ =0x0836D8B0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B22DC: .4byte 0x0836D8B0

	thumb_func_start FUN_080b22e0
FUN_080b22e0: @ 0x080B22E0
	push {lr}
	ldr r2, _080B22F4 @ =0x0836D8BC
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B22F4: .4byte 0x0836D8BC

	thumb_func_start FUN_080b22f8
FUN_080b22f8: @ 0x080B22F8
	push {lr}
	ldr r2, _080B230C @ =0x0836D8C8
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B230C: .4byte 0x0836D8C8

	thumb_func_start FUN_080b2310
FUN_080b2310: @ 0x080B2310
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xea
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r3, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	str r2, [r4, #0x58]
	ldr r1, _080B2380 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B2380: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2384
FUN_080b2384: @ 0x080B2384
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B241C @ =0x0000E902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r5, #1
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
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #8
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x58]
	ldr r1, _080B2420 @ =0x00000DE9
	adds r0, r6, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x12]
	ldrb r3, [r4, #0x11]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_080b2270
	str r0, [r4, #0x2c]
	ldr r1, _080B2424 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B241C: .4byte 0x0000E902
_080B2420: .4byte 0x00000DE9
_080B2424: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2428
FUN_080b2428: @ 0x080B2428
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B24BC @ =0x0000E905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r3, #1
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
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #8
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x58]
	ldr r0, _080B24C0 @ =0x00000DE9
	adds r5, r5, r0
	ldrb r0, [r4, #0x11]
	adds r5, r5, r0
	ldrb r0, [r5]
	strb r0, [r4, #0x12]
	ldr r1, _080B24C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B24BC: .4byte 0x0000E905
_080B24C0: .4byte 0x00000DE9
_080B24C4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b24c8
FUN_080b24c8: @ 0x080B24C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B251C
	cmp r0, #1
	bgt _080B24DE
	cmp r0, #0
	beq _080B24E8
	b _080B257A
_080B24DE:
	cmp r0, #2
	beq _080B2538
	cmp r0, #3
	beq _080B2560
	b _080B257A
_080B24E8:
	ldrb r1, [r4, #0x11]
	ldr r2, _080B2514 @ =0x00000DE4
	adds r0, r5, r2
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _080B257A
	adds r2, r0, #0
	adds r0, r5, #0
	bl FUN_0809bdd4
	str r0, [r4, #0x2c]
	cmp r0, #0
	beq _080B257A
	ldr r0, _080B2518 @ =0x00000E12
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B2578
	.align 2, 0
_080B2514: .4byte 0x00000DE4
_080B2518: .4byte 0x00000E12
_080B251C:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bls _080B2538
	ldr r1, _080B2554 @ =0x0000EA01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080B2558 @ =0x00000139
	bl PlaySound
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B2538:
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x58]
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080B257A
	ldr r1, _080B255C @ =0x0000EA02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B2578
	.align 2, 0
_080B2554: .4byte 0x0000EA01
_080B2558: .4byte 0x00000139
_080B255C: .4byte 0x0000EA02
_080B2560:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B257A
	ldr r1, _080B2588 @ =0x00000DE4
	adds r0, r5, r1
	ldrb r2, [r4, #0x11]
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #0
_080B2578:
	strb r0, [r4, #0xd]
_080B257A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2588: .4byte 0x00000DE4

	thumb_func_start FUN_080b258c
FUN_080b258c: @ 0x080B258C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldr r1, _080B25B0 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B2646
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B25D8
	cmp r0, #1
	bgt _080B25B4
	cmp r0, #0
	beq _080B25BA
	b _080B2646
	.align 2, 0
_080B25B0: .4byte 0x00000DCC
_080B25B4:
	cmp r0, #2
	beq _080B2614
	b _080B2646
_080B25BA:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2646
	ldr r1, _080B25D4 @ =0x0000E903
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080B2604
	.align 2, 0
_080B25D4: .4byte 0x0000E903
_080B25D8:
	ldr r1, _080B260C @ =0x00000DE9
	adds r0, r5, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r1, [r4, #0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080B2646
	ldr r1, _080B2610 @ =0x0000E904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x9d
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_080B2604:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080B2646
	.align 2, 0
_080B260C: .4byte 0x00000DE9
_080B2610: .4byte 0x0000E904
_080B2614:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2646
	ldr r1, _080B264C @ =0x0000E902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	strb r2, [r4, #0xd]
	ldrb r0, [r4, #0x12]
	cmp r0, #4
	bne _080B2646
	ldr r0, _080B2650 @ =0x00000DE9
	adds r1, r5, r0
	ldrb r0, [r4, #0x11]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	strb r2, [r4, #0x12]
_080B2646:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B264C: .4byte 0x0000E902
_080B2650: .4byte 0x00000DE9

	thumb_func_start FUN_080b2654
FUN_080b2654: @ 0x080B2654
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B26B8
	cmp r0, #1
	bgt _080B266E
	cmp r0, #0
	beq _080B2678
	b _080B2742
_080B266E:
	cmp r0, #2
	beq _080B2700
	cmp r0, #3
	beq _080B2724
	b _080B2742
_080B2678:
	ldr r1, _080B26B4 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B2742
	adds r1, #0x1d
	adds r0, r5, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r1, [r4, #0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080B2742
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	b _080B2716
	.align 2, 0
_080B26B4: .4byte 0x00000DCC
_080B26B8:
	ldrb r0, [r4, #0x12]
	cmp r0, #4
	bne _080B26EC
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2742
	ldr r1, _080B26E8 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B26E0
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r3, [r4, #0x11]
	adds r0, r5, #0
	movs r2, #0
	bl CreateGhost78_1
_080B26E0:
	movs r0, #0x1e
	strb r0, [r4, #0x13]
	b _080B2716
	.align 2, 0
_080B26E8: .4byte 0x00000DCC
_080B26EC:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _080B2742
	movs r0, #0
	strb r0, [r4, #0xd]
	b _080B2742
_080B2700:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080B2742
	ldr r1, _080B2720 @ =0x0000E90A
	adds r0, r4, #0
	bl SetMotion
_080B2716:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080B2742
	.align 2, 0
_080B2720: .4byte 0x0000E90A
_080B2724:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2742
	ldr r1, _080B2748 @ =0x0000E905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0x12]
_080B2742:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2748: .4byte 0x0000E905

	thumb_func_start FUN_080b274c
FUN_080b274c: @ 0x080B274C
	ldr r2, _080B2760 @ =gProjectileFnTable
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
_080B2760: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2764
FUN_080b2764: @ 0x080B2764
	ldr r2, _080B2778 @ =gProjectileFnTable
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
_080B2778: .4byte gProjectileFnTable

	thumb_func_start FUN_080b277c
FUN_080b277c: @ 0x080B277C
	ldr r2, _080B2790 @ =gProjectileFnTable
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
_080B2790: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2794
FUN_080b2794: @ 0x080B2794
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080B27E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B27EC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B27E4 @ =gProjectileFnTable
	movs r1, #0x2f
	strb r1, [r3, #9]
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r2, [r3, #0x5c]
	cmp r5, #0
	beq _080B27E8
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080B27EA
	.align 2, 0
_080B27E0: .4byte gProjectileHeaderPtr
_080B27E4: .4byte gProjectileFnTable
_080B27E8:
	ldr r0, _080B27F4 @ =0xFFFFFD00
_080B27EA:
	str r0, [r3, #0x60]
_080B27EC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B27F4: .4byte 0xFFFFFD00

	thumb_func_start FUN_080b27f8
FUN_080b27f8: @ 0x080B27F8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r7, #0
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B287C @ =0x0836D8E8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xb7
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bge _080B285C
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080B285C:
	ldr r1, _080B2880 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl FUN_080b2884
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B287C: .4byte 0x0836D8E8
_080B2880: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2884
FUN_080b2884: @ 0x080B2884
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, _080B28D0 @ =gOverworld
	ldr r1, _080B28D4 @ =0x0002C00C
	adds r0, r0, r1
	ldr r2, [r4, #0x58]
	ldr r0, [r0]
	cmp r2, r0
	blt _080B28A2
	movs r0, #0x82
	lsls r0, r0, #0xb
	cmp r2, r0
	ble _080B28DC
_080B28A2:
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
	ldr r1, _080B28D8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B28EA
	.align 2, 0
_080B28D0: .4byte gOverworld
_080B28D4: .4byte 0x0002C00C
_080B28D8: .4byte gProjectileFnTable
_080B28DC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, r2, r0
	str r0, [r4, #0x58]
_080B28EA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b28f0
FUN_080b28f0: @ 0x080B28F0
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080B2928 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080B2928: .4byte gProjectileFnTable
