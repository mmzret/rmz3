	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid13_Init
Solid13_Init: @ 0x080CE354
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldrb r1, [r4, #0xb]
	movs r0, #8
	movs r2, #0
	mov sl, r2
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CE3F8 @ =sSize
	str r0, [r4, #0x30]
	movs r0, #0
	mov sb, r0
	movs r7, #1
	strh r7, [r4, #0x26]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r6, #4
	orrs r0, r6
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080CE3FC @ =Collision_ARRAY_0837025c
	movs r2, #0x54
	adds r2, r2, r4
	mov r8, r2
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	mov r0, sl
	str r0, [r5, #0x24]
	ldrb r0, [r4, #0xa]
	orrs r6, r0
	strb r6, [r4, #0xa]
	ldr r1, _080CE400 @ =Collision_ARRAY_0837028c
	adds r0, r5, #0
	mov r2, r8
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	mov r1, sl
	str r1, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xc0
	mov r2, sb
	strb r2, [r0]
	ldr r1, _080CE404 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	adds r0, r4, #0
	bl Solid13_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE3F8: .4byte sSize
_080CE3FC: .4byte Collision_ARRAY_0837025c
_080CE400: .4byte Collision_ARRAY_0837028c
_080CE404: .4byte gSolidFnTable

	thumb_func_start Solid13_Update
Solid13_Update: @ 0x080CE408
	push {lr}
	ldr r2, _080CE41C @ =sSolid13Updates
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CE41C: .4byte sSolid13Updates

	thumb_func_start Solid13_Die
Solid13_Die: @ 0x080CE420
	ldr r2, _080CE434 @ =gSolidFnTable
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
_080CE434: .4byte gSolidFnTable

	thumb_func_start FUN_080ce438
FUN_080ce438: @ 0x080CE438
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CE448
	cmp r0, #1
	beq _080CE44C
	b _080CE4C6
_080CE448:
	movs r0, #1
	strb r0, [r4, #0xe]
_080CE44C:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x54]
	ldr r2, [r0, #0x58]
	str r1, [r4, #0x54]
	str r2, [r4, #0x58]
	ldrb r0, [r0, #0xc]
	adds r5, r4, #0
	adds r5, #0x8c
	cmp r0, #1
	bls _080CE48E
	ldr r1, _080CE4CC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl Solid13_Die
_080CE48E:
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080CE4C6
	ldr r1, _080CE4CC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl Solid13_Die
_080CE4C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE4CC: .4byte gSolidFnTable