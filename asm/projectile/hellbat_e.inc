	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a202c
FUN_080a202c: @ 0x080A202C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A2052
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
_080A2052:
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _080A205A
	b _080A22DE
_080A205A:
	lsls r0, r0, #2
	ldr r1, _080A2064 @ =_080A2068
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A2064: .4byte _080A2068
_080A2068: @ jump table
	.4byte _080A2084 @ case 0
	.4byte _080A20EC @ case 1
	.4byte _080A2136 @ case 2
	.4byte _080A2162 @ case 3
	.4byte _080A21CE @ case 4
	.4byte _080A2254 @ case 5
	.4byte _080A22A8 @ case 6
_080A2084:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A209E
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	strb r2, [r5, #0x13]
	movs r0, #3
	strb r0, [r5, #0xe]
	b _080A22DE
_080A209E:
	ldr r1, _080A20E4 @ =0x0000A903
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, _080A20E8 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	str r4, [r5, #0x5c]
	b _080A2298
	.align 2, 0
_080A20E4: .4byte 0x0000A903
_080A20E8: .4byte 0xFFFFFF00
_080A20EC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _080A2110
	b _080A22DE
_080A2110:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x54]
	str r1, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	movs r3, #1
	bl createHellbatElectricBeam
	movs r0, #0
	strb r0, [r5, #0x13]
	movs r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	b _080A2294
_080A2136:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A2148
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A2148
	b _080A22DE
_080A2148:
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	add r1, sp, #8
	str r0, [r1, #4]
	ldr r0, [r5, #0x28]
	movs r2, #1
	bl FUN_080a1538
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A2296
_080A2162:
	ldr r1, _080A21A0 @ =0x0000A905
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080A21A4 @ =0x0836B2C4
	bl SetDDP
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _080A21A8
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080A21AA
	.align 2, 0
_080A21A0: .4byte 0x0000A905
_080A21A4: .4byte 0x0836B2C4
_080A21A8:
	ldr r0, _080A2224 @ =0xFFFFFD00
_080A21AA:
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080A2228 @ =0xFFFFFC00
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	str r4, [r5, #0x64]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A21CE:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	adds r1, r0, #0
	cmp r1, #0
	bge _080A21E4
	rsbs r1, r1, #0
_080A21E4:
	movs r0, #0xa0
	lsls r0, r0, #5
	cmp r1, r0
	ble _080A2206
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080A2206
	movs r0, #1
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080a1594
	ldr r1, [r5, #0x5c]
	str r1, [r0, #0x5c]
_080A2206:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x13]
	cmp r0, #1
	bne _080A222C
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	b _080A2238
	.align 2, 0
_080A2224: .4byte 0xFFFFFD00
_080A2228: .4byte 0xFFFFFC00
_080A222C:
	ldr r0, [r5, #0x54]
	ldr r2, _080A224C @ =0xFFFFFC00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
_080A2238:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A22DE
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _080A2250 @ =0xFFFFFD00
	str r0, [r5, #0x60]
	b _080A2298
	.align 2, 0
_080A224C: .4byte 0xFFFFFC00
_080A2250: .4byte 0xFFFFFD00
_080A2254:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r2, #0
	ldr r0, _080A22A0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080A22A4 @ =0xFFFFB000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	bge _080A2274
	movs r2, #1
_080A2274:
	cmp r2, #0
	beq _080A22DE
	adds r0, r1, r2
	str r0, [r5, #0x58]
	movs r0, #0xff
	str r0, [r5, #0x64]
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
_080A2294:
	ands r0, r1
_080A2296:
	strb r0, [r5, #0xa]
_080A2298:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A22DE
	.align 2, 0
_080A22A0: .4byte gStageRun+232
_080A22A4: .4byte 0xFFFFB000
_080A22A8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	ldr r0, [r5, #0x64]
	adds r1, #2
	strh r0, [r1]
	ldr r0, [r5, #0x64]
	cmp r0, #0
	ble _080A22C6
	subs r0, #0x20
	str r0, [r5, #0x64]
_080A22C6:
	ldr r0, [r5, #0x64]
	cmp r0, #0x20
	bgt _080A22DE
	ldr r1, _080A22E8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080A22DE:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A22E8: .4byte gProjectileFnTable

