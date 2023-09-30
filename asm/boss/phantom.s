	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805ecc8
FUN_0805ecc8: @ 0x0805ECC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r7, _0805ED30 @ =RNG_0202f388
	ldr r0, _0805ED34 @ =0x000343FD
	mov sb, r0
	ldr r1, _0805ED38 @ =0x00269EC3
	mov r8, r1
	movs r6, #3
_0805ECDE:
	ldr r0, [r7]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0x18
	bl __umodsi3
	subs r0, #0xc
	lsls r0, r0, #8
	ldr r2, [r5, #0x54]
	adds r2, r2, r0
	mov r0, sb
	muls r0, r4, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	rsbs r0, r0, #0
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, [r5, #0x58]
	subs r1, r1, r0
	adds r0, r2, #0
	bl FUN_080c4be0
	subs r6, #1
	cmp r6, #0
	bge _0805ECDE
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805ED30: .4byte RNG_0202f388
_0805ED34: .4byte 0x000343FD
_0805ED38: .4byte 0x00269EC3

	thumb_func_start Phantom_Init
Phantom_Init: @ 0x0805ED3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _0805EEAC @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #5
	strb r0, [r7, #0xd]
	movs r0, #0
	strh r0, [r7, #0xe]
	movs r1, #0
	strb r1, [r7, #0x10]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r4, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r0, r4, #0
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r7, #0x58]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	ldr r0, _0805EEB0 @ =0xFFFF9000
	adds r2, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #7
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #0xd4
	str r2, [r0]
	adds r0, #4
	str r1, [r0]
	subs r1, r1, r2
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	asrs r1, r1, #1
	adds r2, r2, r1
	str r2, [r0]
	subs r0, #0x1c
	movs r1, #0
	str r1, [r0]
	ldr r5, _0805EEB4 @ =0x00000A78
	ldr r2, _0805EEB8 @ =gStaticMotionGraphics
	mov r8, r2
	adds r0, r5, r2
	ldr r1, _0805EEBC @ =wStaticGraphicTilenums
	mov sb, r1
	movs r4, #0x86
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805EEC0 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	ldr r6, _0805EEC4 @ =wStaticMotionPalIDs
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r5, _0805EEC8 @ =0x00000A8C
	mov r1, r8
	adds r0, r5, r1
	movs r4, #0x87
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805EEC0 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	movs r4, #0xaa
	lsls r4, r4, #4
	add r8, r4
	movs r5, #0x88
	lsls r5, r5, #1
	add sb, r5
	mov r2, sb
	ldrh r1, [r2]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldr r1, _0805EEC0 @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	adds r6, r6, r5
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _0805EECC @ =0x083652C0
	adds r0, r7, #0
	movs r2, #0x60
	bl ResetBossBody
	ldr r1, _0805EED0 @ =phantom_0805eed4
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x5c
	movs r2, #0
	str r2, [r0]
	movs r0, #0
	strb r0, [r7, #0x10]
	adds r0, r7, #0
	bl Phantom_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805EEAC: .4byte gBossFnTable
_0805EEB0: .4byte 0xFFFF9000
_0805EEB4: .4byte 0x00000A78
_0805EEB8: .4byte gStaticMotionGraphics
_0805EEBC: .4byte wStaticGraphicTilenums
_0805EEC0: .4byte gStaticMotionGraphics+12
_0805EEC4: .4byte wStaticMotionPalIDs
_0805EEC8: .4byte 0x00000A8C
_0805EECC: .4byte 0x083652C0
_0805EED0: .4byte phantom_0805eed4

	thumb_func_start phantom_0805eed4
phantom_0805eed4: @ 0x0805EED4
	push {r4, lr}
	ldr r4, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805EEE8
	movs r0, #0xff
	bl PlaySound
_0805EEE8:
	movs r2, #0
	ldr r0, _0805EF08 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0805EEFA
	movs r2, #1
_0805EEFA:
	adds r0, r4, #0
	adds r0, #0xcb
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805EF08: .4byte pZero2

	thumb_func_start Phantom_Update
Phantom_Update: @ 0x0805EF0C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805EF2A
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0805EF6C
_0805EF2A:
	ldr r0, _0805EF64 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0805EF6C
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r0, [r1]
	cmp r0, #0
	beq _0805EF46
	str r2, [r1]
_0805EF46:
	ldr r1, _0805EF68 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	adds r0, r4, #0
	bl Phantom_Die
	b _0805EF82
	.align 2, 0
_0805EF64: .4byte gStageRun
_0805EF68: .4byte gBossFnTable
_0805EF6C:
	ldr r0, _0805EF88 @ =0x08365414
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl phantom_080607e4
_0805EF82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805EF88: .4byte 0x08365414

	thumb_func_start callPhantomBossModeTable
callPhantomBossModeTable: @ 0x0805EF8C
	push {lr}
	ldr r2, _0805EFA0 @ =0x08365418
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805EFA0: .4byte 0x08365418

	thumb_func_start phantom_0805efa4
phantom_0805efa4: @ 0x0805EFA4
	push {lr}
	ldr r2, _0805EFB8 @ =0x08365434
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805EFB8: .4byte 0x08365434

	thumb_func_start FUN_0805efbc
FUN_0805efbc: @ 0x0805EFBC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805EFF4 @ =0x083652C0
	bl SetDDP
	movs r5, #1
	strh r5, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080607a0
	ldr r2, _0805EFF8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805EFFC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805F000 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_0805f004
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805EFF4: .4byte 0x083652C0
_0805EFF8: .4byte RNG_0202f388
_0805EFFC: .4byte 0x000343FD
_0805F000: .4byte 0x00269EC3

	thumb_func_start FUN_0805f004
FUN_0805f004: @ 0x0805F004
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080607f0
	ldrb r0, [r4, #0x12]
	subs r3, r0, #1
	strb r3, [r4, #0x12]
	cmp r3, #0
	bne _0805F09A
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2f
	bgt _0805F060
	ldr r2, _0805F044 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805F048 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805F04C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #9
	bhi _0805F050
	movs r0, #1
	b _0805F096
	.align 2, 0
_0805F044: .4byte RNG_0202f388
_0805F048: .4byte 0x000343FD
_0805F04C: .4byte 0x00269EC3
_0805F050:
	cmp r1, #0x10
	bhi _0805F058
	movs r0, #3
	b _0805F096
_0805F058:
	cmp r1, #0x17
	bls _0805F094
	movs r0, #6
	b _0805F096
_0805F060:
	ldr r2, _0805F080 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805F084 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805F088 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xd
	bhi _0805F08C
	movs r0, #1
	b _0805F096
	.align 2, 0
_0805F080: .4byte RNG_0202f388
_0805F084: .4byte 0x000343FD
_0805F088: .4byte 0x00269EC3
_0805F08C:
	cmp r1, #0x16
	bhi _0805F094
	movs r0, #3
	b _0805F096
_0805F094:
	movs r0, #4
_0805F096:
	strb r0, [r4, #0xd]
	strh r3, [r4, #0xe]
_0805F09A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start phantom_0805f0a0
phantom_0805f0a0: @ 0x0805F0A0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #3
	beq _0805F0BC
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805F0BC
	movs r0, #3
	strh r0, [r4, #0xe]
_0805F0BC:
	ldr r1, _0805F0F0 @ =0x0836543C
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	cmp r0, #0
	bne _0805F0EA
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	bl CreateParticle
	movs r0, #3
	strb r0, [r4, #0x13]
_0805F0EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F0F0: .4byte 0x0836543C

	thumb_func_start FUN_0805f0f4
FUN_0805f0f4: @ 0x0805F0F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F144 @ =0x083652C0
	bl SetDDP
	movs r0, #1
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080607a0
	adds r0, r4, #0
	bl FUN_08060838
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0805F148
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805F14E
	.align 2, 0
_0805F144: .4byte 0x083652C0
_0805F148:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805F14E:
	strb r0, [r4, #0xa]
	lsls r1, r5, #1
	subs r1, #1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #6
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #3
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl FUN_0805f180
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f180
FUN_0805f180: @ 0x0805F180
	push {lr}
	ldr r2, _0805F194 @ =0x0836544C
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F194: .4byte 0x0836544C

	thumb_func_start phantom_0805f198
phantom_0805f198: @ 0x0805F198
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, [r5, #0x5c]
	bl FUN_08060864
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805F208
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r6, #1
	ands r4, r6
	adds r0, r5, #0
	bl FUN_08060838
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _0805F208
	ldr r4, _0805F1F8 @ =pZero2
	ldr r0, [r4]
	ldr r0, [r0, #0x54]
	ldr r2, [r5, #0x54]
	subs r1, r0, r2
	ldr r0, _0805F1FC @ =0x000040C0
	adds r1, r1, r0
	ldr r0, _0805F200 @ =0x00008180
	cmp r1, r0
	bhi _0805F20C
	ldr r1, [r5, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	ldr r1, [r4]
	ldr r1, [r1, #0x58]
	subs r1, r0, r1
	ldr r0, _0805F204 @ =0x000013FF
	cmp r1, r0
	bgt _0805F20C
	movs r0, #0xfb
	bl PlaySound
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #7
	bl FUN_080607a0
	b _0805F20C
	.align 2, 0
_0805F1F8: .4byte pZero2
_0805F1FC: .4byte 0x000040C0
_0805F200: .4byte 0x00008180
_0805F204: .4byte 0x000013FF
_0805F208:
	movs r0, #2
	strh r0, [r5, #0xe]
_0805F20C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f214
FUN_0805f214: @ 0x0805F214
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x71
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _0805F22E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805F264 @ =0x08365320
	bl SetDDP
_0805F22E:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #3
	bne _0805F240
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805F268 @ =0x083652C0
	bl SetDDP
_0805F240:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08060864
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F25E
	movs r0, #2
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080607a0
_0805F25E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F264: .4byte 0x08365320
_0805F268: .4byte 0x083652C0

	thumb_func_start FUN_0805f26c
FUN_0805f26c: @ 0x0805F26C
	push {lr}
	ldr r2, _0805F280 @ =0x08365454
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F280: .4byte 0x08365454

	thumb_func_start FUN_0805f284
FUN_0805f284: @ 0x0805F284
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F2C8 @ =0x083652C0
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0xf]
	ldr r0, [r4, #0x5c]
	movs r1, #0xf0
	lsls r1, r1, #2
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r1, _0805F2CC @ =0x00006CC0
	muls r0, r1, r0
	movs r1, #0x1e
	bl __divsi3
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08060864
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F2D0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl FUN_080607bc
	b _0805F2D8
	.align 2, 0
_0805F2C8: .4byte 0x083652C0
_0805F2CC: .4byte 0x00006CC0
_0805F2D0:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080607a0
_0805F2D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f2e0
FUN_0805f2e0: @ 0x0805F2E0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0805F320
	adds r0, r4, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #2
	cmp r0, #0
	ble _0805F330
	lsls r1, r0, #5
	ldr r0, [r4, #0x5c]
	muls r1, r0, r1
	adds r0, r4, #0
	bl FUN_08060864
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F330
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #1
	bl FUN_080607bc
	b _0805F330
_0805F320:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #2
	bne _0805F330
	movs r0, #0
	strb r0, [r4, #0xd]
	strh r0, [r4, #0xe]
_0805F330:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f338
FUN_0805f338: @ 0x0805F338
	push {lr}
	ldr r2, _0805F34C @ =0x0836545C
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F34C: .4byte 0x0836545C

	thumb_func_start FUN_0805f350
FUN_0805f350: @ 0x0805F350
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F390 @ =0x083652C0
	bl SetDDP
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xcb
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080607a0
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xf]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F390: .4byte 0x083652C0

	thumb_func_start FUN_0805f394
FUN_0805f394: @ 0x0805F394
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x5c]
	bl FUN_08060864
	ldr r1, [r4, #0x5c]
	movs r0, #0xe6
	muls r0, r1, r0
	cmp r0, #0
	bge _0805F3AA
	adds r0, #0xff
_0805F3AA:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0805F3C8
	adds r0, r4, #0
	movs r1, #0x12
	bl FUN_080607a0
	strb r5, [r4, #0xd]
	strh r5, [r4, #0xe]
_0805F3C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f3d0
FUN_0805f3d0: @ 0x0805F3D0
	push {lr}
	ldr r2, _0805F3E4 @ =0x08365464
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F3E4: .4byte 0x08365464

	thumb_func_start FUN_0805f3e8
FUN_0805f3e8: @ 0x0805F3E8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805F420 @ =0x083652C0
	bl SetDDP
	adds r0, r4, #0
	bl FUN_080608c8
	ldr r2, _0805F424 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805F428 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805F42C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #6
	ands r0, r1
	cmp r0, #0
	beq _0805F434
	ldr r0, _0805F430 @ =0xFFFFFA40
	b _0805F436
	.align 2, 0
_0805F420: .4byte 0x083652C0
_0805F424: .4byte RNG_0202f388
_0805F428: .4byte 0x000343FD
_0805F42C: .4byte 0x00269EC3
_0805F430: .4byte 0xFFFFFA40
_0805F434:
	ldr r0, _0805F440 @ =0xFFFFF940
_0805F436:
	str r0, [r4, #0x60]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F440: .4byte 0xFFFFF940

	thumb_func_start FUN_0805f444
FUN_0805f444: @ 0x0805F444
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080608e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F45C
	movs r0, #2
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	bl FUN_0805f464
_0805F45C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f464
FUN_0805f464: @ 0x0805F464
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060924
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0805F482
	movs r0, #4
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080607a0
	movs r0, #0
	strb r0, [r4, #0x12]
_0805F482:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f488
FUN_0805f488: @ 0x0805F488
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060974
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0805F49C
	movs r0, #0
	strb r0, [r4, #0xd]
	strh r0, [r4, #0xe]
_0805F49C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f4a4
FUN_0805f4a4: @ 0x0805F4A4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0805F508
	ldr r3, [r5, #0x54]
	str r3, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	ldr r0, _0805F4EC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	subs r0, r0, r3
	subs r1, r1, r2
	ldr r2, _0805F4F0 @ =0xFFFFE800
	adds r1, r1, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x18
	cmp r4, #0x80
	bls _0805F4F6
	cmp r4, #0xc0
	bls _0805F4F4
	movs r4, #0
	b _0805F4F6
	.align 2, 0
_0805F4EC: .4byte pZero2
_0805F4F0: .4byte 0xFFFFE800
_0805F4F4:
	movs r4, #0x80
_0805F4F6:
	movs r0, #0xfc
	bl PlaySound
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r4, #0
	bl FUN_080afcec
_0805F508:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F522
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	movs r3, #1
	bl FUN_080607bc
	movs r0, #5
	strh r0, [r5, #0xe]
_0805F522:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F52C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x01, 0xF0, 0xF8, 0xF9, 0x00, 0x06, 0x00, 0x28, 0x05, 0xD0, 0x03, 0x20, 0xE0, 0x81, 0x20, 0x1C
	.byte 0x04, 0x21, 0x01, 0xF0, 0x2D, 0xF9, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_0805f54c
FUN_0805f54c: @ 0x0805F54C
	push {lr}
	ldr r2, _0805F560 @ =0x0836547C
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F560: .4byte 0x0836547C

	thumb_func_start FUN_0805f564
FUN_0805f564: @ 0x0805F564
	push {lr}
	ldr r2, _0805F578 @ =0x08365494
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F578: .4byte 0x08365494

	thumb_func_start FUN_0805f57c
FUN_0805f57c: @ 0x0805F57C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F5A4 @ =0x083652C0
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl FUN_080608c8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080afbb0
	str r0, [r4, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F5A4: .4byte 0x083652C0

	thumb_func_start FUN_0805f5a8
FUN_0805f5a8: @ 0x0805F5A8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080608e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F626
	movs r0, #2
	strb r0, [r4, #0xf]
	ldr r0, _0805F5DC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r0, [r0]
	cmp r1, r0
	bne _0805F5F2
	ldr r2, [r4, #0x54]
	cmp r2, r1
	ble _0805F5E4
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	ldr r1, _0805F5E0 @ =0xFFFFE800
	adds r0, r0, r1
	b _0805F612
	.align 2, 0
_0805F5DC: .4byte pZero2
_0805F5E0: .4byte 0xFFFFE800
_0805F5E4:
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	b _0805F612
_0805F5F2:
	cmp r1, r0
	bge _0805F604
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	ldr r1, _0805F600 @ =0xFFFFE800
	b _0805F60E
	.align 2, 0
_0805F600: .4byte 0xFFFFE800
_0805F604:
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #5
_0805F60E:
	adds r0, r0, r1
	ldr r2, [r4, #0x54]
_0805F612:
	subs r0, r0, r2
	movs r1, #0x2e
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0805F62C @ =0xFFFFFA40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0805f630
_0805F626:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F62C: .4byte 0xFFFFFA40

	thumb_func_start FUN_0805f630
FUN_0805f630: @ 0x0805F630
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F65C @ =0x083653E0
	bl SetDDP
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08060864
	adds r0, r4, #0
	bl FUN_08060924
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F654
	movs r0, #3
	strb r0, [r4, #0xf]
_0805F654:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F65C: .4byte 0x083653E0

	thumb_func_start FUN_0805f660
FUN_0805f660: @ 0x0805F660
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x74
	ldr r1, _0805F68C @ =0x083652C0
	bl SetDDP
	adds r0, r5, #0
	bl FUN_08060974
	lsls r0, r0, #0x18
	cmp r0, #0
	ble _0805F686
	movs r4, #4
	strb r4, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	strb r4, [r5, #0x12]
_0805F686:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F68C: .4byte 0x083652C0

	thumb_func_start FUN_0805f690
FUN_0805f690: @ 0x0805F690
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x12]
	subs r0, #1
	strb r0, [r1, #0x12]
	cmp r0, #0
	bne _0805F6AA
	movs r0, #1
	strh r0, [r1, #0xe]
	adds r0, r1, #0
	movs r1, #5
	bl FUN_080607a0
_0805F6AA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f6b0
FUN_0805f6b0: @ 0x0805F6B0
	push {lr}
	ldr r2, _0805F6C4 @ =0x083654A8
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F6C4: .4byte 0x083654A8

	thumb_func_start FUN_0805f6c8
FUN_0805f6c8: @ 0x0805F6C8
	push {lr}
	adds r1, r0, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0805F6DC
	movs r0, #1
	strb r0, [r1, #0xf]
_0805F6DC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f6e0
FUN_0805f6e0: @ 0x0805F6E0
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x2c]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0805F6F8
	movs r0, #2
	strb r0, [r1, #0xf]
	adds r0, r1, #0
	movs r1, #6
	bl FUN_080607a0
_0805F6F8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f6fc
FUN_0805f6fc: @ 0x0805F6FC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0805F716
	movs r0, #0xfc
	bl PlaySound
	movs r0, #3
	strb r0, [r4, #0xf]
_0805F716:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f71c
FUN_0805f71c: @ 0x0805F71C
	push {lr}
	adds r1, r0, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F734
	movs r0, #2
	strh r0, [r1, #0xe]
	adds r0, r1, #0
	movs r1, #0
	bl FUN_080607a0
_0805F734:
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f738
FUN_0805f738: @ 0x0805F738
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080609a4
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	ble _0805F764
	movs r0, #3
	strh r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0xb7
	strb r1, [r0]
	adds r1, #0x12
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl FUN_08060a48
	adds r0, r4, #0
	bl FUN_0805f76c
_0805F764:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f76c
FUN_0805f76c: @ 0x0805F76C
	push {lr}
	ldr r2, _0805F780 @ =0x083654B8
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F780: .4byte 0x083654B8

	thumb_func_start FUN_0805f784
FUN_0805f784: @ 0x0805F784
	push {lr}
	movs r1, #1
	strb r1, [r0, #0xf]
	bl FUN_080608c8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f794
FUN_0805f794: @ 0x0805F794
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080608e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F7CA
	movs r2, #0
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r3, r4, #0
	adds r3, #0xb7
	ldrb r1, [r3]
	adds r0, r1, #1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	adds r1, #8
	strb r1, [r3]
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x54]
	str r0, [r1]
	strb r2, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_0805f7d0
_0805F7CA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f7d0
FUN_0805f7d0: @ 0x0805F7D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0x12]
	adds r1, #1
	strb r1, [r5, #0x12]
	adds r0, #0xbc
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r0, [r0]
	ldr r4, [r2]
	subs r0, r0, r4
	muls r0, r1, r0
	adds r1, r5, #0
	adds r1, #0xb7
	ldrb r1, [r1]
	bl __divsi3
	adds r4, r4, r0
	str r4, [r5, #0x54]
	adds r0, r5, #0
	bl FUN_08060924
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0805F818
	ldr r0, [r5, #0x2c]
	ldr r0, [r0, #0x58]
	subs r0, #0x80
	ldr r1, [r5, #0x58]
	cmp r1, r0
	blt _0805F818
	movs r0, #4
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	bl FUN_0805f820
_0805F818:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805f820
FUN_0805f820: @ 0x0805F820
	push {lr}
	ldr r2, _0805F834 @ =0x083654C4
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F834: .4byte 0x083654C4

	thumb_func_start FUN_0805f838
FUN_0805f838: @ 0x0805F838
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F858 @ =0x083653E0
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080607a0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F858: .4byte 0x083653E0

	thumb_func_start FUN_0805f85c
FUN_0805f85c: @ 0x0805F85C
	push {lr}
	adds r1, r0, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F86C
	movs r0, #2
	strb r0, [r1, #0xf]
_0805F86C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f870
FUN_0805f870: @ 0x0805F870
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805F89C @ =gStageRun+232
	ldr r0, [r5, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r1, [r1, #0x3c]
	subs r1, r1, r0
	ldr r0, _0805F8A0 @ =0xFFFFD000
	cmp r1, r0
	bge _0805F8A4
	movs r4, #0
	movs r0, #3
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080607a0
	strb r4, [r5, #0x12]
	b _0805F8B8
	.align 2, 0
_0805F89C: .4byte gStageRun+232
_0805F8A0: .4byte 0xFFFFD000
_0805F8A4:
	ldr r0, _0805F8C0 @ =0xFFFFE000
	cmp r1, r0
	ble _0805F8B8
	movs r0, #5
	strh r0, [r5, #0xe]
	movs r0, #0
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	bl FUN_0805f934
_0805F8B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805F8C0: .4byte 0xFFFFE000

	thumb_func_start FUN_0805f8c4
FUN_0805f8c4: @ 0x0805F8C4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bne _0805F91A
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r0, #0xfc
	bl PlaySound
	movs r4, #0xf0
	lsls r4, r4, #2
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x10
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x50
	movs r3, #1
	bl FUN_080afbfc
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x70
	movs r3, #1
	bl FUN_080afbfc
_0805F91A:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F928
	movs r0, #2
	strb r0, [r5, #0xf]
_0805F928:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0805f930
nop_0805f930: @ 0x0805F930
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805f934
FUN_0805f934: @ 0x0805F934
	push {lr}
	ldr r2, _0805F948 @ =0x083654D8
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805F948: .4byte 0x083654D8

	thumb_func_start FUN_0805f94c
FUN_0805f94c: @ 0x0805F94C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805F974 @ =0x083652F0
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080607a0
	ldr r0, _0805F978 @ =0xFFFFFB00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0805f97c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F974: .4byte 0x083652F0
_0805F978: .4byte 0xFFFFFB00

	thumb_func_start FUN_0805f97c
FUN_0805f97c: @ 0x0805F97C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060924
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805F99A
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080607a0
_0805F99A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f9a0
FUN_0805f9a0: @ 0x0805F9A0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r5, #4
	ands r0, r5
	cmp r0, #0
	beq _0805F9C8
	ldr r0, _0805F9C4 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_080607a0
	movs r0, #3
	strb r0, [r4, #0xf]
	b _0805F9D6
	.align 2, 0
_0805F9C4: .4byte 0xFFFFFD00
_0805F9C8:
	adds r0, r4, #0
	bl FUN_08060924
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F9D6
	strb r5, [r4, #0xf]
_0805F9D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f9dc
FUN_0805f9dc: @ 0x0805F9DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060924
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805F9EE
	movs r0, #4
	strb r0, [r4, #0xf]
_0805F9EE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805f9f4
FUN_0805f9f4: @ 0x0805F9F4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060974
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0805FA08
	movs r0, #0
	strb r0, [r4, #0xd]
	strh r0, [r4, #0xe]
_0805FA08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805fa10
FUN_0805fa10: @ 0x0805FA10
	push {lr}
	ldr r2, _0805FA24 @ =0x083654EC
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805FA24: .4byte 0x083654EC

	thumb_func_start FUN_0805fa28
FUN_0805fa28: @ 0x0805FA28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805FA40 @ =0x083652C0
	bl SetDDP
	movs r0, #1
	strh r0, [r4, #0xe]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805FA40: .4byte 0x083652C0

	thumb_func_start FUN_0805fa44
FUN_0805fa44: @ 0x0805FA44
	push {lr}
	ldr r2, _0805FA58 @ =0x08365504
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805FA58: .4byte 0x08365504

	thumb_func_start FUN_0805fa5c
FUN_0805fa5c: @ 0x0805FA5C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	movs r6, #1
	movs r4, #1
	strb r4, [r7, #0xf]
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	movs r1, #0x2e
	bl __divsi3
	str r0, [r7, #0x5c]
	ldr r0, _0805FAB4 @ =0xFFFFFA40
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl FUN_080608c8
	adds r0, r7, #0
	adds r0, #0xc4
	str r5, [r0]
	adds r0, #4
	strb r4, [r0]
	ldr r2, _0805FAB8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FABC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FAC0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r6
	adds r1, r7, #0
	adds r1, #0xc9
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0805fac4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FAB4: .4byte 0xFFFFFA40
_0805FAB8: .4byte RNG_0202f388
_0805FABC: .4byte 0x000343FD
_0805FAC0: .4byte 0x00269EC3

	thumb_func_start FUN_0805fac4
FUN_0805fac4: @ 0x0805FAC4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080608e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805FAD6
	movs r0, #2
	strb r0, [r4, #0xf]
_0805FAD6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805fadc
FUN_0805fadc: @ 0x0805FADC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x5c]
	bl FUN_08060864
	adds r0, r4, #0
	bl FUN_08060924
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805FAF6
	movs r0, #3
	strb r0, [r4, #0xf]
_0805FAF6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805fafc
FUN_0805fafc: @ 0x0805FAFC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060974
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805FB1C
	movs r0, #0xfd
	bl PlaySound
	movs r0, #4
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080607a0
_0805FB1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805fb24
FUN_0805fb24: @ 0x0805FB24
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805FB4C @ =0x08365350
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805FB50
	movs r0, #5
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080607a0
	movs r0, #4
	strb r0, [r4, #0x12]
	b _0805FB84
	.align 2, 0
_0805FB4C: .4byte 0x08365350
_0805FB50:
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0805FB84
	adds r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0805FB84
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0805FB84:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805fb8c
FUN_0805fb8c: @ 0x0805FB8C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r3, r0, #1
	strb r3, [r5, #0x12]
	cmp r3, #0
	bne _0805FC04
	movs r0, #6
	strb r0, [r5, #0xf]
	ldr r2, _0805FC0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FC10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FC14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r6, r0, #0x11
	movs r0, #3
	ands r6, r0
	subs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r0, r1, r0
	str r0, [r5, #0x64]
	movs r2, #0
	subs r0, r0, r1
	cmp r0, #0
	ble _0805FBD4
	movs r2, #1
_0805FBD4:
	lsls r0, r2, #9
	ldr r1, _0805FC18 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	strb r3, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xc4
	str r3, [r0]
	movs r4, #0
_0805FBE6:
	cmp r4, r6
	beq _0805FBF2
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0809130c
_0805FBF2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0805FBE6
	adds r0, r5, #0
	movs r1, #4
	bl FUN_0809130c
_0805FC04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805FC0C: .4byte RNG_0202f388
_0805FC10: .4byte 0x000343FD
_0805FC14: .4byte 0x00269EC3
_0805FC18: .4byte 0xFFFFFF00

	thumb_func_start FUN_0805fc1c
FUN_0805fc1c: @ 0x0805FC1C
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r2, #0x12]
	adds r0, #1
	strb r0, [r2, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0805FC3E
	ldrb r0, [r2, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FC44
_0805FC3E:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FC44:
	strb r0, [r2, #0xa]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x5c]
	adds r1, r0, r1
	str r1, [r2, #0x54]
	ldr r0, [r2, #0x64]
	subs r3, r0, r1
	adds r4, r0, #0
	cmp r3, #0
	blt _0805FC5E
	cmp r3, #0xff
	ble _0805FC64
	b _0805FC76
_0805FC5E:
	subs r0, r1, r4
	cmp r0, #0xff
	bgt _0805FC76
_0805FC64:
	str r4, [r2, #0x54]
	movs r0, #2
	strh r0, [r2, #0xe]
	ldrb r1, [r2, #0x12]
	movs r0, #0x8d
	subs r0, r0, r1
	movs r1, #0
	strb r0, [r2, #0x13]
	strb r1, [r2, #0x12]
_0805FC76:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805fc7c
FUN_0805fc7c: @ 0x0805FC7C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0805FC96
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FC9C
_0805FC96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FC9C:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	movs r2, #0x10
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0805FCB6
	movs r0, #1
	str r0, [r5]
	movs r0, #5
	b _0805FD52
_0805FCB6:
	ldrb r1, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	subs r0, #0x3c
	cmp r1, r0
	ble _0805FCF4
	movs r0, #8
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805FCF0 @ =0x08365380
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805FCF4
	adds r1, r4, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805FD50
	movs r0, #4
	b _0805FD52
	.align 2, 0
_0805FCF0: .4byte 0x08365380
_0805FCF4:
	ldrb r0, [r4, #0x12]
	ldrb r1, [r4, #0x13]
	cmp r0, r1
	bls _0805FD54
	ldr r0, _0805FD14 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _0805FD1C
	ldr r0, _0805FD18 @ =0x00003FFF
	cmp r2, r0
	ble _0805FD24
	b _0805FD3C
	.align 2, 0
_0805FD14: .4byte pZero2
_0805FD18: .4byte 0x00003FFF
_0805FD1C:
	subs r1, r1, r0
	ldr r0, _0805FD38 @ =0x00003FFF
	cmp r1, r0
	bgt _0805FD3C
_0805FD24:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #1
	str r0, [r5]
	strb r0, [r4, #0xd]
	strh r2, [r4, #0xe]
	b _0805FD54
	.align 2, 0
_0805FD38: .4byte 0x00003FFF
_0805FD3C:
	adds r1, r4, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805FD50
	movs r0, #4
	b _0805FD52
_0805FD50:
	movs r0, #3
_0805FD52:
	strh r0, [r4, #0xe]
_0805FD54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805fd5c
FUN_0805fd5c: @ 0x0805FD5C
	push {lr}
	ldr r2, _0805FD70 @ =0x08365520
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805FD70: .4byte 0x08365520

	thumb_func_start FUN_0805fd74
FUN_0805fd74: @ 0x0805FD74
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805FDA8 @ =0x08365350
	bl SetDDP
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080607a0
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xf]
	strb r1, [r4, #0x12]
	adds r4, #0xc4
	movs r0, #4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805FDA8: .4byte 0x08365350

	thumb_func_start FUN_0805fdac
FUN_0805fdac: @ 0x0805FDAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r1, r0, #1
	movs r2, #0
	strb r1, [r5, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bhi _0805FDD4
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDD4:
	cmp r0, #0x2f
	bhi _0805FDE8
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDE8:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0805FDF8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0805FDFE
_0805FDF8:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
_0805FDFE:
	strb r0, [r5, #0xa]
	ldr r1, _0805FE9C @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r5, #0x12]
	cmp r0, #0x40
	bne _0805FE92
	ldr r2, _0805FEA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FEA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FEA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r6, r0, #0x11
	movs r0, #3
	ands r6, r0
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r7, [r0]
	adds r3, r5, #0
	adds r3, #0xc9
	ldrb r1, [r3]
	lsls r2, r1, #5
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #8
	adds r7, r7, r0
	movs r0, #1
	eors r1, r0
	strb r1, [r3]
	str r7, [r5, #0x54]
	movs r4, #0
	movs r0, #0xc4
	adds r0, r0, r5
	mov r8, r0
_0805FE5C:
	cmp r4, r6
	beq _0805FE6C
	adds r1, r4, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_0809130c
_0805FE6C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0805FE5C
	subs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r7, r0
	str r0, [r5, #0x54]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #1
	mov r1, r8
	str r0, [r1]
_0805FE92:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FE9C: .4byte gSineTable
_0805FEA0: .4byte RNG_0202f388
_0805FEA4: .4byte 0x000343FD
_0805FEA8: .4byte 0x00269EC3

	thumb_func_start FUN_0805feac
FUN_0805feac: @ 0x0805FEAC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	movs r2, #0
	strb r1, [r4, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0805FED8
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FED8:
	cmp r0, #0x6f
	bhi _0805FEEC
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FEEC:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0805FEFC
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FF02
_0805FEFC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FF02:
	strb r0, [r4, #0xa]
	ldr r1, _0805FF5C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x80
	bne _0805FF54
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805FF60 @ =0x08365380
	bl SetDDP
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080607a0
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #8
	str r0, [r1]
	movs r0, #2
	strh r0, [r4, #0xe]
	movs r0, #0
	strb r0, [r4, #0x12]
	movs r0, #0x10
	strb r0, [r4, #0x13]
_0805FF54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805FF5C: .4byte gSineTable
_0805FF60: .4byte 0x08365380

	thumb_func_start FUN_0805ff64
FUN_0805ff64: @ 0x0805FF64
	push {lr}
	ldr r2, _0805FF78 @ =0x0836552C
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805FF78: .4byte 0x0836552C

	thumb_func_start FUN_0805ff7c
FUN_0805ff7c: @ 0x0805FF7C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805FFAC @ =0x083652C0
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0xf]
	ldr r0, _0805FFB0 @ =0xFFFFFA40
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_080608c8
	adds r1, r4, #0
	adds r1, #0xc4
	movs r0, #2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0805ffb4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805FFAC: .4byte 0x083652C0
_0805FFB0: .4byte 0xFFFFFA40

	thumb_func_start FUN_0805ffb4
FUN_0805ffb4: @ 0x0805FFB4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0805FFCE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FFD4
_0805FFCE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FFD4:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_080608e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805FFE6
	movs r0, #2
	strb r0, [r4, #0xf]
_0805FFE6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ffec
FUN_0805ffec: @ 0x0805FFEC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08060006
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0806000C
_08060006:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0806000C:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl FUN_08060924
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08060038
	adds r1, r5, #0
	adds r1, #0xc4
	movs r0, #1
	str r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080607a0
	strb r4, [r5, #0x12]
	movs r0, #3
	strb r0, [r5, #0xf]
_08060038:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060040
FUN_08060040: @ 0x08060040
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _080600A4
	ldr r3, [r5, #0x54]
	str r3, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	ldr r0, _08060088 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	subs r0, r0, r3
	subs r1, r1, r2
	ldr r2, _0806008C @ =0xFFFFE800
	adds r1, r1, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x18
	cmp r4, #0x80
	bls _08060092
	cmp r4, #0xc0
	bls _08060090
	movs r4, #0
	b _08060092
	.align 2, 0
_08060088: .4byte pZero2
_0806008C: .4byte 0xFFFFE800
_08060090:
	movs r4, #0x80
_08060092:
	movs r0, #0xfc
	bl PlaySound
	movs r1, #0xe0
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r4, #0
	bl FUN_080afcec
_080600A4:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080600BE
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	movs r3, #1
	bl FUN_080607bc
	movs r0, #4
	strb r0, [r5, #0xf]
_080600BE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080600c8
FUN_080600c8: @ 0x080600C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060924
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080600DA
	movs r0, #5
	strb r0, [r4, #0xf]
_080600DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080600e0
FUN_080600e0: @ 0x080600E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08060974
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080600F4
	movs r0, #0
	strb r0, [r4, #0xd]
	strh r0, [r4, #0xe]
_080600F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080600fc
FUN_080600fc: @ 0x080600FC
	push {lr}
	ldr r2, _08060110 @ =0x08365544
	ldrb r1, [r0, #0xf]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08060110: .4byte 0x08365544

	thumb_func_start FUN_08060114
FUN_08060114: @ 0x08060114
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08060160 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	ldr r0, _08060164 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08060168 @ =0xFFFFD000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08060864
	movs r0, #0
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080607a0
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0xfe
	bl PlaySound
	adds r0, r4, #0
	bl FUN_0805ecc8
	movs r0, #0xc
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_0806016c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060160: .4byte pZero2
_08060164: .4byte gStageRun+232
_08060168: .4byte 0xFFFFD000

	thumb_func_start FUN_0806016c
FUN_0806016c: @ 0x0806016C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060192
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08060198 @ =0x083652F0
	bl SetDDP
	movs r0, #2
	strb r0, [r4, #0xf]
_08060192:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060198: .4byte 0x083652F0

	thumb_func_start FUN_0806019c
FUN_0806019c: @ 0x0806019C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080601B0
	str r1, [r4, #0x60]
_080601B0:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r5, #4
	ands r0, r5
	cmp r0, #0
	beq _080601CC
	ldr r0, _080601EC @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_080607a0
	strb r5, [r4, #0xf]
_080601CC:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0806089c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080601E6
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080607a0
	movs r0, #3
	strb r0, [r4, #0xf]
_080601E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080601EC: .4byte 0xFFFFFD00

	thumb_func_start FUN_080601f0
FUN_080601f0: @ 0x080601F0
	push {lr}
	adds r1, r0, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060202
	movs r0, #0
	strb r0, [r1, #0xd]
	strh r0, [r1, #0xe]
_08060202:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060208
FUN_08060208: @ 0x08060208
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806021C
	str r1, [r4, #0x60]
_0806021C:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0806089c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806023A
	ldr r0, _08060240 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080607a0
	movs r0, #3
	strb r0, [r4, #0xf]
_0806023A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060240: .4byte 0xFFFFFD00

	thumb_func_start phantom_08060244
phantom_08060244: @ 0x08060244
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x1b
	bls _08060250
	b _080603AC
_08060250:
	lsls r0, r0, #2
	ldr r1, _0806025C @ =_08060260
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806025C: .4byte _08060260
_08060260: @ jump table
	.4byte _080602D0 @ case 0
	.4byte _080603AC @ case 1
	.4byte _080603AC @ case 2
	.4byte _080603AC @ case 3
	.4byte _080603AC @ case 4
	.4byte _080603AC @ case 5
	.4byte _080603AC @ case 6
	.4byte _080603AC @ case 7
	.4byte _080603AC @ case 8
	.4byte _080603AC @ case 9
	.4byte _080603AC @ case 10
	.4byte _080603AC @ case 11
	.4byte _080603AC @ case 12
	.4byte _080603AC @ case 13
	.4byte _080603AC @ case 14
	.4byte _080603AC @ case 15
	.4byte _080603AC @ case 16
	.4byte _080603AC @ case 17
	.4byte _080603AC @ case 18
	.4byte _080603AC @ case 19
	.4byte _080602E4 @ case 20
	.4byte _080602F2 @ case 21
	.4byte _08060300 @ case 22
	.4byte _0806034C @ case 23
	.4byte _08060368 @ case 24
	.4byte _0806037A @ case 25
	.4byte _0806038E @ case 26
	.4byte _0806039C @ case 27
_080602D0:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _080603AC
_080602E4:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080602F2:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080603AC
	b _08060386
_08060300:
	movs r0, #0xfa
	bl PlaySound
	movs r4, #0xbe
	lsls r4, r4, #1
	ldr r1, _08060358 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _0806035C @ =wStaticGraphicTilenums
	ldrh r1, [r1, #0x26]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08060360 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _08060364 @ =wStaticMotionPalIDs
	ldrh r1, [r0, #0x26]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806034C:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080603AC
	b _08060386
	.align 2, 0
_08060358: .4byte gStaticMotionGraphics
_0806035C: .4byte wStaticGraphicTilenums
_08060360: .4byte gStaticMotionGraphics+12
_08060364: .4byte wStaticMotionPalIDs
_08060368:
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080607a0
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806037A:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080603AC
_08060386:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080603AC
_0806038E:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806039C:
	ldr r0, _080603B4 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080603AC
	strb r1, [r5, #0xd]
	strh r1, [r5, #0xe]
_080603AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080603B4: .4byte gStageRun

	thumb_func_start FUN_080603b8
FUN_080603b8: @ 0x080603B8
	push {lr}
	ldr r2, _080603CC @ =0x08365558
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080603CC: .4byte 0x08365558

	thumb_func_start FUN_080603d0
FUN_080603d0: @ 0x080603D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080603E0
	cmp r0, #1
	beq _080603F4
	b _08060408
_080603E0:
	ldr r1, _080603F0 @ =0x0000BC16
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08060408
	.align 2, 0
_080603F0: .4byte 0x0000BC16
_080603F4:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060408
	movs r0, #0
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08060408:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08060410
FUN_08060410: @ 0x08060410
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _0806044A
	cmp r0, #1
	bgt _08060424
	cmp r0, #0
	beq _0806042E
	b _080604D2
_08060424:
	cmp r0, #2
	beq _0806045C
	cmp r0, #3
	beq _08060494
	b _080604D2
_0806042E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08060458 @ =0x08365350
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0806044A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080604D2
	b _0806047E
	.align 2, 0
_08060458: .4byte 0x08365350
_0806045C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08060488 @ =0x083652C0
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	ldr r1, _0806048C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _08060490 @ =0x0000BC17
	adds r0, r4, #0
	bl SetMotion
_0806047E:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _080604D2
	.align 2, 0
_08060488: .4byte 0x083652C0
_0806048C: .4byte 0xFFFFB000
_08060490: .4byte 0x0000BC17
_08060494:
	ldr r0, [r4, #0x70]
	ldr r1, _080604D8 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _080604DC @ =0x00010500
	cmp r0, r1
	bne _080604BE
	movs r0, #0xfc
	bl PlaySound
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809142c
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0809142c
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809142c
_080604BE:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080604D2
	movs r0, #0
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080604D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080604D8: .4byte 0x00FFFF00
_080604DC: .4byte 0x00010500

	thumb_func_start FUN_080604e0
FUN_080604e0: @ 0x080604E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _08060514
	cmp r0, #1
	bgt _080604F4
	cmp r0, #0
	beq _080604FE
	b _08060556
_080604F4:
	cmp r0, #2
	beq _08060524
	cmp r0, #3
	beq _08060540
	b _08060556
_080604FE:
	ldr r1, _08060510 @ =0x0000BC18
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08060556
	.align 2, 0
_08060510: .4byte 0x0000BC18
_08060514:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060556
	movs r0, #2
	strb r0, [r4, #0xf]
	b _08060556
_08060524:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806055C @ =0x08365350
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_08060540:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08060556
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08060556:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806055C: .4byte 0x08365350

	thumb_func_start FUN_08060560
FUN_08060560: @ 0x08060560
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	beq _08060570
	cmp r1, #1
	beq _08060638
	b _08060648
_08060570:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080605AC @ =0x083652C0
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	bge _080605B4
	ldr r0, _080605B0 @ =0xFFFFC000
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	cmp r2, r0
	bge _080605D0
	movs r2, #0x80
	lsls r2, r2, #7
	b _080605C6
	.align 2, 0
_080605AC: .4byte 0x083652C0
_080605B0: .4byte 0xFFFFC000
_080605B4:
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	cmp r2, r0
	ble _080605D0
	ldr r2, _080605CC @ =0xFFFFC000
_080605C6:
	adds r0, r1, r2
	str r0, [r4, #0x54]
	b _080605D2
	.align 2, 0
_080605CC: .4byte 0xFFFFC000
_080605D0:
	str r2, [r4, #0x54]
_080605D2:
	movs r3, #0
	ldr r0, _08060618 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _080605E2
	movs r3, #1
_080605E2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _080605F4
	movs r3, #1
_080605F4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0806061C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08060622
	.align 2, 0
_08060618: .4byte pZero2
_0806061C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08060622:
	strb r0, [r4, #0xa]
	ldr r1, _08060634 @ =0x0000BC19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08060648
	.align 2, 0
_08060634: .4byte 0x0000BC19
_08060638:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060648
	movs r0, #0
	strb r1, [r4, #0xd]
	strh r0, [r4, #0xe]
_08060648:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Phantom_Die
Phantom_Die: @ 0x08060650
	push {lr}
	ldr r2, _08060664 @ =0x08365410
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08060664: .4byte 0x08365410

	thumb_func_start phantom_08060668
phantom_08060668: @ 0x08060668
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _08060674
	b _08060794
_08060674:
	lsls r0, r0, #2
	ldr r1, _08060680 @ =_08060684
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08060680: .4byte _08060684
_08060684: @ jump table
	.4byte _080606A0 @ case 0
	.4byte _080606F2 @ case 1
	.4byte _0806072C @ case 2
	.4byte _0806073A @ case 3
	.4byte _08060758 @ case 4
	.4byte _08060762 @ case 5
	.4byte _08060794 @ case 6
_080606A0:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r3, _08060720 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _080606CA
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080606CA
	ldr r0, _08060724 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080606CA:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08060728 @ =0x0000BC0E
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080606F2:
	ldr r1, [r5, #0x60]
	adds r1, #0x40
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08060708
	str r0, [r5, #0x60]
_08060708:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0806074C
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08060746
	.align 2, 0
_08060720: .4byte gStageRun
_08060724: .4byte 0x0000FFFE
_08060728: .4byte 0x0000BC0E
_0806072C:
	ldr r1, _08060754 @ =0x0000BC13
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806073A:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0806074C
_08060746:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806074C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08060794
	.align 2, 0
_08060754: .4byte 0x0000BC13
_08060758:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08060762:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08060794
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r2, _0806079C @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r5, #0
	bl FUN_0805ecc8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08060794:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806079C: .4byte gStageRun

	thumb_func_start FUN_080607a0
FUN_080607a0: @ 0x080607A0
	push {lr}
	adds r2, r0, #0
	adds r2, #0xb4
	strb r1, [r2]
	ldr r2, _080607B8 @ =0x08365214
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	bl SetMotion
	pop {r0}
	bx r0
	.align 2, 0
_080607B8: .4byte 0x08365214

	thumb_func_start FUN_080607bc
FUN_080607bc: @ 0x080607BC
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0xb4
	strb r1, [r4]
	ldr r4, _080607E0 @ =0x08365214
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl GotoMotion
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080607E0: .4byte 0x08365214

	thumb_func_start phantom_080607e4
phantom_080607e4: @ 0x080607E4
	push {lr}
	bl UpdateMotionGraphic
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080607f0
FUN_080607f0: @ 0x080607F0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08060838
	movs r4, #1
	adds r1, r4, #0
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_08060838
	adds r3, r5, #0
	adds r3, #0x4a
	ands r4, r0
	lsls r2, r4, #4
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	cmp r4, #0
	beq _0806082A
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08060830
_0806082A:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08060830:
	strb r0, [r5, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08060838
FUN_08060838: @ 0x08060838
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x54]
	ldr r0, _08060854 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	cmp r3, r1
	beq _08060858
	movs r0, #0
	cmp r3, r1
	bge _08060860
	movs r0, #1
	b _08060860
	.align 2, 0
_08060854: .4byte pZero2
_08060858:
	ldrb r0, [r2, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
_08060860:
	pop {r1}
	bx r1

	thumb_func_start FUN_08060864
FUN_08060864: @ 0x08060864
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	adds r4, r0, r1
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r3, [r0]
	subs r1, r4, r3
	adds r0, #8
	ldr r0, [r0]
	cmp r1, r0
	bhi _08060882
	str r4, [r2, #0x54]
	movs r0, #0
	b _08060894
_08060882:
	cmp r4, r3
	bge _0806088A
	str r3, [r2, #0x54]
	b _08060892
_0806088A:
	adds r0, r2, #0
	adds r0, #0xd8
	ldr r0, [r0]
	str r0, [r2, #0x54]
_08060892:
	movs r0, #1
_08060894:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0806089c
FUN_0806089c: @ 0x0806089C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x58]
	adds r5, r2, r1
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_08009f6c
	cmp r5, r0
	blt _080608BE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #1
	b _080608C2
_080608BE:
	str r5, [r4, #0x58]
	movs r0, #0
_080608C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080608c8
FUN_080608c8: @ 0x080608C8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #3
	bl FUN_080607a0
	adds r0, r4, #0
	bl FUN_080607f0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080608e0
FUN_080608e0: @ 0x080608E0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0806091E
	adds r0, r2, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0806091E
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #1
	b _08060920
_0806091E:
	movs r0, #0
_08060920:
	pop {r1}
	bx r1

	thumb_func_start FUN_08060924
FUN_08060924: @ 0x08060924
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _08060954 @ =0x083653E0
	bl SetDDP
	ldr r5, [r4, #0x60]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0806089c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08060958
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080607a0
	adds r0, r4, #0
	bl FUN_080607f0
	movs r0, #1
	b _0806096C
	.align 2, 0
_08060954: .4byte 0x083653E0
_08060958:
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bne _08060964
	adds r0, r5, #0
	adds r0, #0xa8
	b _08060968
_08060964:
	adds r0, r5, #0
	adds r0, #0x40
_08060968:
	str r0, [r4, #0x60]
	movs r0, #0
_0806096C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08060974
FUN_08060974: @ 0x08060974
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _08060990 @ =0x083652C0
	bl SetDDP
	adds r4, #0x73
	ldrb r0, [r4]
	cmp r0, #2
	bne _08060994
	movs r0, #1
	rsbs r0, r0, #0
	b _0806099E
	.align 2, 0
_08060990: .4byte 0x083652C0
_08060994:
	cmp r0, #3
	beq _0806099C
	movs r0, #0
	b _0806099E
_0806099C:
	movs r0, #1
_0806099E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080609a4
FUN_080609a4: @ 0x080609A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x2c]
	ldr r1, [r5, #0x60]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08060A3C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r3, [r4, #0x54]
	ldr r2, [r5, #0x54]
	ldr r1, [r5, #0x58]
	subs r1, r1, r0
	ldr r0, _080609F8 @ =0xFFFFFB00
	adds r1, r1, r0
	subs r2, r2, r3
	movs r0, #0x80
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r2, r0
	bhi _08060A04
	movs r3, #0
	ldr r4, _080609FC @ =0xFFFFF700
	ldr r2, _08060A00 @ =0x08365240
_080609DE:
	adds r2, #4
	adds r3, #1
	subs r1, #0x80
	ldr r0, [r2]
	adds r0, r0, r4
	rsbs r0, r0, #0
	cmp r0, r1
	bge _080609DE
	subs r0, r3, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _08060A40
	.align 2, 0
_080609F8: .4byte 0xFFFFFB00
_080609FC: .4byte 0xFFFFF700
_08060A00: .4byte 0x08365240
_08060A04:
	movs r3, #0
	ldr r5, _08060A30 @ =0xFFFFF700
	adds r4, r0, #0
	ldr r2, _08060A34 @ =0x08365240
_08060A0C:
	adds r2, #4
	adds r3, #1
	ldr r0, [r2]
	adds r0, r0, r5
	cmp r0, r4
	ble _08060A0C
	subs r3, #1
	adds r0, r3, #0
	adds r0, #8
	lsls r0, r0, #7
	subs r1, r1, r0
	ldr r0, _08060A38 @ =0xFFFFE000
	cmp r1, r0
	bgt _08060A3C
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	b _08060A40
	.align 2, 0
_08060A30: .4byte 0xFFFFF700
_08060A34: .4byte 0x08365240
_08060A38: .4byte 0xFFFFE000
_08060A3C:
	movs r0, #1
	rsbs r0, r0, #0
_08060A40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08060a48
FUN_08060a48: @ 0x08060A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r2, [r6, #0x2c]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r2, #0x5c]
	ldr r1, [r2, #0x60]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r5, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _08060A7E
	movs r5, #1
_08060A7E:
	add r0, sp, #8
	mov sb, r0
	add r1, sp, #0x10
	mov r8, r1
	movs r0, #0xbc
	adds r0, r0, r6
	mov sl, r0
	adds r1, r6, #0
	adds r1, #0xc0
	str r1, [sp, #0x18]
_08060A92:
	ldr r1, _08060AE0 @ =0x08365568
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	mov r1, sp
	mov r2, sb
	mov r3, r8
	bl _call_via_r4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08060AB6
	movs r0, #0
	cmp r5, #0
	bne _08060AB4
	movs r0, #1
_08060AB4:
	adds r5, r0, #0
_08060AB6:
	lsls r0, r7, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r7, r0, #0x18
	cmp r0, #0
	bne _08060A92
	ldr r0, [sp]
	mov r1, sl
	str r0, [r1]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060AE0: .4byte 0x08365568
