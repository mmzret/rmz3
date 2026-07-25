	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a3094
FUN_080a3094: @ 0x080A3094
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A30A4
	cmp r0, #1
	beq _080A30FE
	b _080A3166
_080A30A4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A30BC @ =0x0836B474
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080A30C0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080A30C6
	.align 2, 0
_080A30BC: .4byte 0x0836B474
_080A30C0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A30C6:
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
	ldr r1, _080A3134 @ =0xFFFFFE00
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0xa
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	str r1, [r4, #0x60]
	ldr r1, _080A3138 @ =0x00004604
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A30FE:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080A3116
	str r1, [r4, #0x60]
_080A3116:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	cmp r2, #0
	bge _080A3140
	ldr r0, [r4, #0x54]
	ldr r2, _080A313C @ =0xFFFFF800
	adds r0, r0, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _080A3160
	b _080A3152
	.align 2, 0
_080A3134: .4byte 0xFFFFFE00
_080A3138: .4byte 0x00004604
_080A313C: .4byte 0xFFFFF800
_080A3140:
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _080A3160
_080A3152:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A3160:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080A3166:
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A31B4
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A31BC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A31B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A31BC: .4byte gProjectileFnTable

	thumb_func_start FUN_080a31c0
FUN_080a31c0: @ 0x080A31C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080A31D0
	cmp r0, #1
	beq _080A320E
	b _080A3234
_080A31D0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A3288 @ =0x0836B48C
	bl SetDDP
	ldr r3, [r4, #0x54]
	ldr r1, _080A328C @ =0xFFFFF800
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A31F4
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r3, r0
_080A31F4:
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080A3290 @ =0x00004605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A320E:
	ldr r1, [r4, #0x58]
	adds r1, #0x80
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080A322E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080A322E:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080A3234:
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A3282
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3294 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A3282:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3288: .4byte 0x0836B48C
_080A328C: .4byte 0xFFFFF800
_080A3290: .4byte 0x00004605
_080A3294: .4byte gProjectileFnTable

	thumb_func_start FUN_080a3298
FUN_080a3298: @ 0x080A3298
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080A32D2
	cmp r0, #1
	bgt _080A32AC
	cmp r0, #0
	beq _080A32BA
	b _080A32B4
_080A32AC:
	cmp r0, #2
	beq _080A32F8
	cmp r0, #3
	beq _080A3336
_080A32B4:
	adds r5, r4, #0
	adds r5, #0x8c
	b _080A33C2
_080A32BA:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A32F0 @ =0x0836B4A4
	bl SetDDP
	ldr r1, _080A32F4 @ =0x00004606
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A32D2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #3
	bne _080A33C2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A33C2
	.align 2, 0
_080A32F0: .4byte 0x0836B4A4
_080A32F4: .4byte 0x00004606
_080A32F8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A334C @ =0x0836B45C
	bl SetDDP
	movs r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl InitScalerotMotion1
	ldr r1, _080A3350 @ =0x00004606
	adds r0, r4, #0
	movs r2, #3
	movs r3, #1
	bl GotoMotion
	movs r0, #0x20
	str r0, [r4, #0x5c]
	movs r2, #0x20
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A332E
	subs r2, #0x40
_080A332E:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A3336:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080A3354
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080A335A
	.align 2, 0
_080A334C: .4byte 0x0836B45C
_080A3350: .4byte 0x00004606
_080A3354:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A335A:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #4
	movs r2, #0
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #7
	bhi _080A33BC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3414 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A33BC:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080A33C2:
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A340C
	bl FUN_080a2ea0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080a2ee8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A3414 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080A340C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A3414: .4byte gProjectileFnTable
