	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080aab38
FUN_080aab38: @ 0x080AAB38
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080AAB90 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AABCE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAB94 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r5, [r3, #0x28]
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080AAB80
	movs r1, #1
_080AAB80:
	adds r2, r1, #0
	cmp r2, #0
	beq _080AAB98
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAB9E
	.align 2, 0
_080AAB90: .4byte gProjectileHeaderPtr
_080AAB94: .4byte gProjectileFnTable
_080AAB98:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAB9E:
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
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	str r0, [r3, #0x58]
_080AABCE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aabd4
FUN_080aabd4: @ 0x080AABD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AAC20 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAC18
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAC24 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AAC18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AAC20: .4byte gProjectileHeaderPtr
_080AAC24: .4byte gProjectileFnTable

	thumb_func_start FUN_080aac28
FUN_080aac28: @ 0x080AAC28
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AAC74 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAC6C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAC78 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #4
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
_080AAC6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AAC74: .4byte gProjectileHeaderPtr
_080AAC78: .4byte gProjectileFnTable

	thumb_func_start FUN_080aac7c
FUN_080aac7c: @ 0x080AAC7C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AACD4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAD06
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AACD8 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #5
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r2, r4, #0
	cmp r2, #0
	beq _080AACDC
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AACE2
	.align 2, 0
_080AACD4: .4byte gProjectileHeaderPtr
_080AACD8: .4byte gProjectileFnTable
_080AACDC:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AACE2:
	strb r0, [r3, #0xa]
	movs r1, #1
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
	str r6, [r3, #0x28]
_080AAD06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aad0c
FUN_080aad0c: @ 0x080AAD0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AAD64 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAD9A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAD68 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	movs r0, #6
	strb r0, [r3, #0x10]
	strb r1, [r3, #0x11]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r2, r4, #0
	cmp r2, #0
	beq _080AAD6C
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAD72
	.align 2, 0
_080AAD64: .4byte gProjectileHeaderPtr
_080AAD68: .4byte gProjectileFnTable
_080AAD6C:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAD72:
	strb r0, [r3, #0xa]
	movs r1, #1
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
	str r6, [r3, #0x28]
	ldr r0, [r6, #0x28]
	str r0, [r3, #0x2c]
_080AAD9A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aada0
FUN_080aada0: @ 0x080AADA0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080AADFC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAE2C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AAE00 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
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
	strb r5, [r3, #0x11]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080AAE04
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AAE0A
	.align 2, 0
_080AADFC: .4byte gProjectileHeaderPtr
_080AAE00: .4byte gProjectileFnTable
_080AAE04:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AAE0A:
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
	str r4, [r3, #0x28]
_080AAE2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080aae34
FUN_080aae34: @ 0x080AAE34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AAE4C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	bne _080AAE50
	movs r0, #0
	b _080AAE7A
	.align 2, 0
_080AAE4C: .4byte gProjectileHeaderPtr
_080AAE50:
	adds r0, r4, #0
	adds r0, #0x25
	movs r3, #0
	movs r2, #8
	strb r2, [r0]
	ldr r0, _080AAE80 @ =gProjectileFnTable
	movs r1, #0x20
	strb r1, [r4, #9]
	adds r0, #0x80
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	strb r0, [r4, #0x11]
	str r5, [r4, #0x28]
	adds r0, r4, #0
_080AAE7A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AAE80: .4byte gProjectileFnTable

