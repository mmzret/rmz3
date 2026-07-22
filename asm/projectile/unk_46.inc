	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl _ForceEntityPalette
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
	bl UpdateEntityAnim
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl _ForceEntityPalette
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
