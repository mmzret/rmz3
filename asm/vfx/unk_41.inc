	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080be154
FUN_080be154: @ 0x080BE154
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080BE1AE
	cmp r5, #1
	bgt _080BE168
	cmp r5, #0
	beq _080BE16E
	b _080BE224
_080BE168:
	cmp r5, #2
	beq _080BE1F6
	b _080BE224
_080BE16E:
	ldr r1, _080BE18C @ =0x0000A80D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080BE190
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080BE196
	.align 2, 0
_080BE18C: .4byte 0x0000A80D
_080BE190:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BE1E8 @ =0xFFFFF400
_080BE196:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE1AE:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE1EC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080BE224
	.align 2, 0
_080BE1E8: .4byte 0xFFFFF400
_080BE1EC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080BE224
_080BE1F6:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080BE224
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080BE22C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE224:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE22C: .4byte gVFXFnTable

	thumb_func_start FUN_080be230
FUN_080be230: @ 0x080BE230
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BE2C0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080BE310
	ldrb r0, [r1, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080BE310
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE25C
	cmp r0, #1
	beq _080BE28C
	b _080BE2C0
_080BE25C:
	ldr r1, _080BE2D8 @ =0x0000A901
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE28C:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BE2DC @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _080BE2C0
	ldr r1, _080BE2E0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE2C0:
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r1, [r0]
	cmp r1, #1
	bne _080BE322
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE2E4
	cmp r0, #1
	beq _080BE2FE
	b _080BE322
	.align 2, 0
_080BE2D8: .4byte 0x0000A901
_080BE2DC: .4byte 0xFFFFFF00
_080BE2E0: .4byte gVFXFnTable
_080BE2E4:
	strb r1, [r4, #0x12]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080BE328 @ =0x0000A904
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE2FE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE322
_080BE310:
	ldr r1, _080BE32C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BE322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE328: .4byte 0x0000A904
_080BE32C: .4byte gVFXFnTable

	thumb_func_start FUN_080be330
FUN_080be330: @ 0x080BE330
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BE340
	cmp r0, #1
	beq _080BE3E0
	b _080BE454
_080BE340:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080BE350
	ldr r1, _080BE34C @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE34C: .4byte 0x0000A907
_080BE350:
	cmp r0, #1
	bne _080BE35C
	ldr r1, _080BE358 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE358: .4byte 0x0000A907
_080BE35C:
	cmp r0, #2
	bne _080BE368
	ldr r1, _080BE364 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE364: .4byte 0x0000A907
_080BE368:
	cmp r0, #3
	bne _080BE374
	ldr r1, _080BE370 @ =0x0000A907
	b _080BE37A
	.align 2, 0
_080BE370: .4byte 0x0000A907
_080BE374:
	cmp r0, #4
	bne _080BE388
	ldr r1, _080BE384 @ =0x0000A90B
_080BE37A:
	adds r0, r4, #0
	bl SetMotion
	b _080BE394
	.align 2, 0
_080BE384: .4byte 0x0000A90B
_080BE388:
	cmp r0, #5
	bne _080BE394
	ldr r1, _080BE3AC @ =0x0000A90B
	adds r0, r4, #0
	bl SetMotion
_080BE394:
	adds r0, r4, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	movs r2, #1
	ands r2, r0
	cmp r2, #0
	beq _080BE3B0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080BE3B6
	.align 2, 0
_080BE3AC: .4byte 0x0000A90B
_080BE3B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080BE3B6:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	movs r0, #3
	strb r0, [r4, #0x13]
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE3E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BE3F0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE44E
_080BE3F0:
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080BE404
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BE41C
_080BE404:
	ldr r1, _080BE418 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BE44E
	.align 2, 0
_080BE418: .4byte gVFXFnTable
_080BE41C:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bhi _080BE43C
	ldr r0, _080BE438 @ =motion_t_ARRAY_0836ef74
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
	b _080BE44E
	.align 2, 0
_080BE438: .4byte motion_t_ARRAY_0836ef74
_080BE43C:
	ldr r0, _080BE45C @ =motion_t_ARRAY_0836ef7a
	ldrb r1, [r4, #0x13]
	subs r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
_080BE44E:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080BE454:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE45C: .4byte motion_t_ARRAY_0836ef7a

