	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c2124
FUN_080c2124: @ 0x080C2124
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080C2142
	movs r0, #8
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080C2162
_080C2142:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C214E
	cmp r0, #1
	beq _080C215C
	b _080C2162
_080C214E:
	ldr r1, _080C2168 @ =0x00000A08
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C215C:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C2162:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C2168: .4byte 0x00000A08

	thumb_func_start FUN_080c216c
FUN_080c216c: @ 0x080C216C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C2194
	ldr r1, _080C2190 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C21B4
	.align 2, 0
_080C2190: .4byte gVFXFnTable
_080C2194:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C21A0
	cmp r0, #1
	beq _080C21AE
	b _080C21B4
_080C21A0:
	ldr r1, _080C21BC @ =0x00000A09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C21AE:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C21B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C21BC: .4byte 0x00000A09

	thumb_func_start FUN_080c21c0
FUN_080c21c0: @ 0x080C21C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080C21E4
	ldr r1, _080C21E0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C2288
	.align 2, 0
_080C21E0: .4byte gVFXFnTable
_080C21E4:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C21F0
	cmp r5, #1
	beq _080C2202
	b _080C2288
_080C21F0:
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C2202:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080C222C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C2232
_080C222C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2232:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C2266
	ldr r0, _080C2290 @ =gWhitePaintFlags
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080C2266
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080C226E
_080C2266:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C226E:
	ldr r0, [r3, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080C2282
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C2282:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C2288:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C2290: .4byte gWhitePaintFlags

	thumb_func_start FUN_080c2294
FUN_080c2294: @ 0x080C2294
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080C22AC
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C22C4
_080C22AC:
	ldr r1, _080C22C0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C2358
	.align 2, 0
_080C22C0: .4byte gVFXFnTable
_080C22C4:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C22D0
	cmp r5, #1
	beq _080C22E0
	b _080C2358
_080C22D0:
	ldr r1, _080C230C @ =0x00000B01
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C22E0:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x13]
	adds r0, r1, #1
	strb r0, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080C2310
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C2316
	.align 2, 0
_080C230C: .4byte 0x00000B01
_080C2310:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2316:
	strb r0, [r4, #0xa]
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C234A
	ldr r0, _080C2360 @ =gWhitePaintFlags
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080C234A
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080C2352
_080C234A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080C2352:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080C2358:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C2360: .4byte gWhitePaintFlags

