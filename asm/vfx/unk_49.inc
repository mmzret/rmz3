	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c025c
FUN_080c025c: @ 0x080C025C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080C02A0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0298
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C02A4 @ =gVFXFnTable
	movs r1, #0x31
	strb r1, [r3, #9]
	adds r0, #0xc4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080C0298:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C02A0: .4byte gVFXHeaderPtr
_080C02A4: .4byte gVFXFnTable

	thumb_func_start createLaserSign
createLaserSign: @ 0x080C02A8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _080C02EC @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080C02E6
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080C02F0 @ =gVFXFnTable
	movs r1, #0x31
	strb r1, [r4, #9]
	adds r0, #0xc4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
	str r7, [r4, #0x28]
_080C02E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C02EC: .4byte gVFXHeaderPtr
_080C02F0: .4byte gVFXFnTable

	thumb_func_start FUN_080c02f4
FUN_080c02f4: @ 0x080C02F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080C0338 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C0332
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C033C @ =gVFXFnTable
	movs r1, #0x31
	strb r1, [r3, #9]
	adds r0, #0xc4
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
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080C0332:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0338: .4byte gVFXHeaderPtr
_080C033C: .4byte gVFXFnTable

	thumb_func_start FUN_080c0340
FUN_080c0340: @ 0x080C0340
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C0380 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C037A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C0384 @ =gVFXFnTable
	movs r1, #0x31
	strb r1, [r3, #9]
	adds r0, #0xc4
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
	str r4, [r3, #0x28]
_080C037A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0380: .4byte gVFXHeaderPtr
_080C0384: .4byte gVFXFnTable

	thumb_func_start VFX49_Init
VFX49_Init: @ 0x080C0388
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C03C8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080C03CC @ =0x0836F160
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
	adds r0, r4, #0
	bl VFX49_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C03C8: .4byte gVFXFnTable
_080C03CC: .4byte 0x0836F160

	thumb_func_start VFX49_Update
VFX49_Update: @ 0x080C03D0
	push {lr}
	ldr r2, _080C03E4 @ =0x0836F150
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C03E4: .4byte 0x0836F150

	thumb_func_start VFX49_Die
VFX49_Die: @ 0x080C03E8
	ldr r2, _080C03FC @ =gVFXFnTable
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
_080C03FC: .4byte gVFXFnTable

	thumb_func_start FUN_080c0400
FUN_080c0400: @ 0x080C0400
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C0410
	cmp r5, #1
	beq _080C0446
	b _080C04CA
_080C0410:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r2, _080C0474 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C0478 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080C047C @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #3
	ands r1, r0
	ldr r0, _080C0480 @ =0x00005102
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x60]
	movs r0, #0x46
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0446:
	ldr r1, [r4, #0x60]
	adds r1, #4
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r1, r0, #1
	movs r2, #0
	strb r1, [r4, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bhi _080C0484
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080C0498
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C049E
	.align 2, 0
_080C0474: .4byte RNG_0202f388
_080C0478: .4byte 0x000343FD
_080C047C: .4byte 0x00269EC3
_080C0480: .4byte 0x00005102
_080C0484:
	cmp r0, #0x13
	bhi _080C04A0
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _080C0498
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C049E
_080C0498:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C049E:
	strb r0, [r4, #0xa]
_080C04A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080C04CA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C04D0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C04CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C04D0: .4byte gVFXFnTable

	thumb_func_start FUN_080c04d4
FUN_080c04d4: @ 0x080C04D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080C0528
	cmp r0, #1
	bgt _080C04EA
	cmp r0, #0
	beq _080C04F4
	b _080C059A
_080C04EA:
	cmp r0, #2
	beq _080C0542
	cmp r0, #3
	beq _080C0562
	b _080C059A
_080C04F4:
	movs r1, #0x9c
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x57
	bl LoadBlink
	movs r0, #0x57
	bl GetBlinkMotionState
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0528:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C053A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C053A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080C059A
_080C0542:
	movs r0, #0x57
	bl ClearBlink
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080C05A0 @ =0x00004E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0562:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r3, [r0]
	cmp r3, #3
	bne _080C059A
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C05A4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C059A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C05A0: .4byte 0x00004E01
_080C05A4: .4byte gVFXFnTable

	thumb_func_start FUN_080c05a8
FUN_080c05a8: @ 0x080C05A8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C05B8
	cmp r0, #1
	beq _080C05E4
	b _080C0650
_080C05B8:
	ldr r2, _080C0604 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C0608 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080C060C @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	ldr r0, _080C0610 @ =0x00004F03
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C05E4:
	ldr r0, [r4, #0x58]
	ldr r1, _080C0614 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x12]
	cmp r1, #0xd
	bhi _080C0620
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C0618
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C061E
	.align 2, 0
_080C0604: .4byte RNG_0202f388
_080C0608: .4byte 0x000343FD
_080C060C: .4byte 0x00269EC3
_080C0610: .4byte 0x00004F03
_080C0614: .4byte 0xFFFFFF00
_080C0618:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C061E:
	strb r0, [r4, #0xa]
_080C0620:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C0650
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C0658 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C0650:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C0658: .4byte gVFXFnTable

	thumb_func_start FUN_080c065c
FUN_080c065c: @ 0x080C065C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _080C068C
	movs r0, #0x57
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C0688 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	b _080C0778
	.align 2, 0
_080C0688: .4byte gVFXFnTable
_080C068C:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080C06E0
	cmp r0, #1
	bgt _080C069C
	cmp r0, #0
	beq _080C06A6
	b _080C077E
_080C069C:
	cmp r0, #2
	beq _080C0744
	cmp r0, #3
	beq _080C0752
	b _080C077E
_080C06A6:
	ldr r1, _080C0724 @ =0x00004E02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x57
	bl LoadBlink
	movs r0, #0x57
	bl GetBlinkMotionState
	movs r0, #2
	strb r0, [r4, #0x12]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C06E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C06F6
	cmp r0, #1
	bne _080C06F0
	movs r0, #0x57
	bl ClearBlink
_080C06F0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
_080C06F6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080C072C
	movs r0, #0x57
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C0728 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	b _080C0778
	.align 2, 0
_080C0724: .4byte 0x00004E02
_080C0728: .4byte gVFXFnTable
_080C072C:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080C077E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080C077E
_080C0744:
	ldr r1, _080C0784 @ =0x00004E03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C0752:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C077E
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C0788 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
_080C0778:
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C077E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C0784: .4byte 0x00004E03
_080C0788: .4byte gVFXFnTable
