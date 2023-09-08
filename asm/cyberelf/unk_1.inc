	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e20a4
FUN_080e20a4: @ 0x080E20A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080E20F0 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E20E8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E20F4 @ =gElfFnTable
	movs r0, #1
	strb r0, [r3, #9]
	ldr r0, [r1, #4]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r6, [r0]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080E20E8:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080E20F0: .4byte gElfHeaderPtr
_080E20F4: .4byte gElfFnTable

	thumb_func_start Elf1_Init
Elf1_Init: @ 0x080E20F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	ldr r1, _080E21B8 @ =gZeroRanges
	ldr r0, _080E21BC @ =0x00000147
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	ldr r0, _080E21C0 @ =gPause
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r0, [r7, #0xa]
	movs r1, #0
	mov r8, r1
	orrs r4, r0
	movs r0, #2
	orrs r4, r0
	strb r4, [r7, #0xa]
	movs r0, #0
	bl createElfAction
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x4c
	mov r2, r8
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	mov r2, sb
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	asrs r5, r5, #0x10
	ldr r0, [r2, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0xbc
	mov r1, r8
	str r1, [r0]
	str r1, [r0, #4]
	subs r0, #4
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #0x20
	strb r0, [r1]
	ldr r1, _080E21C4 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Elf1_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E21B8: .4byte gZeroRanges
_080E21BC: .4byte 0x00000147
_080E21C0: .4byte gPause
_080E21C4: .4byte gElfFnTable

	thumb_func_start Elf1_Update
Elf1_Update: @ 0x080E21C8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E228C @ =gZeroRanges
	ldr r2, _080E2290 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	asrs r4, r4, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x68]
	ldr r1, _080E2294 @ =0x08371CA0
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r3, [r1]
	ldrb r0, [r7, #0xd]
	cmp r0, #3
	bhi _080E2220
	adds r3, #1
	adds r0, r3, #0
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r3, r3, r0
	strb r3, [r1]
_080E2220:
	lsls r3, r3, #4
	ldr r1, _080E2298 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r2, #4]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	movs r1, #0x10
	cmp r0, #0x7f
	ble _080E225A
	movs r1, #0x11
_080E225A:
	adds r0, r7, #0
	adds r0, #0x25
	strb r1, [r0]
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bhi _080E2286
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E2286
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E2286:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E228C: .4byte gZeroRanges
_080E2290: .4byte 0x00000147
_080E2294: .4byte 0x08371CA0
_080E2298: .4byte gSineTable

	thumb_func_start Elf1_Die
Elf1_Die: @ 0x080E229C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldr r1, _080E22FC @ =gPause
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E2300 @ =gUnlockedElfPtr
	adds r3, r2, #0
	adds r3, #0xb4
	ldr r5, _080E2304 @ =0x00000121
	adds r0, r2, r5
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r0, _080E2308 @ =gMission
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E22DA
	adds r0, #1
	strb r0, [r1]
_080E22DA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E230C @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E22FC: .4byte gPause
_080E2300: .4byte gUnlockedElfPtr
_080E2304: .4byte 0x00000121
_080E2308: .4byte gMission
_080E230C: .4byte gElfFnTable

	thumb_func_start FUN_080e2310
FUN_080e2310: @ 0x080E2310
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [sp, #4]
	ldr r0, [r1, #0x58]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xa0
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E2344
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080E2344:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e234c
FUN_080e234c: @ 0x080E234C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _080E239C @ =gZeroRanges
	ldr r2, _080E23A0 @ =0x00000147
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r3, #0x54]
	str r0, [sp, #4]
	asrs r1, r1, #0x10
	ldr r0, [r3, #0x58]
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xa0
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E2394
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080E2394:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E239C: .4byte gZeroRanges
_080E23A0: .4byte 0x00000147

	thumb_func_start FUN_080e23a4
FUN_080e23a4: @ 0x080E23A4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _080E23F4 @ =gZeroRanges
	ldr r2, _080E23F8 @ =0x00000147
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r3, #0x54]
	str r0, [sp, #4]
	asrs r1, r2, #0x10
	ldr r0, [r3, #0x58]
	subs r0, r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xa0
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E23EC
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080E23EC:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E23F4: .4byte gZeroRanges
_080E23F8: .4byte 0x00000147

	thumb_func_start FUN_080e23fc
FUN_080e23fc: @ 0x080E23FC
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E240E
	ldrb r0, [r1, #0xd]
	adds r0, #1
	strb r0, [r1, #0xd]
_080E240E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080e2414
FUN_080e2414: @ 0x080E2414
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080E2438
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	str r0, [r4, #0x2c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080E2438:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080E2446
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080E2446:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e244c
FUN_080e244c: @ 0x080E244C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldrb r1, [r3, #0x10]
	ldrb r0, [r3, #0x11]
	adds r1, r1, r0
	cmp r1, #1
	beq _080E248C
	cmp r1, #1
	bgt _080E2470
	cmp r1, #0
	beq _080E2480
	ldr r6, _080E246C @ =gElfFnTable
	b _080E24EA
	.align 2, 0
_080E246C: .4byte gElfFnTable
_080E2470:
	cmp r1, #2
	beq _080E2498
	cmp r1, #3
	beq _080E24C4
	ldr r6, _080E247C @ =gElfFnTable
	b _080E24EA
	.align 2, 0
_080E247C: .4byte gElfFnTable
_080E2480:
	ldr r1, _080E2488 @ =gLifeRecoverAmount
	ldr r0, [r1]
	adds r0, #0x20
	b _080E24A2
	.align 2, 0
_080E2488: .4byte gLifeRecoverAmount
_080E248C:
	ldr r1, _080E2494 @ =gLifeRecoverAmount
	ldr r0, [r1]
	adds r0, #0x40
	b _080E24A2
	.align 2, 0
_080E2494: .4byte gLifeRecoverAmount
_080E2498:
	ldr r1, _080E24A8 @ =gLifeRecoverAmount
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
_080E24A2:
	str r0, [r1]
	ldr r6, _080E24AC @ =gElfFnTable
	b _080E24EA
	.align 2, 0
_080E24A8: .4byte gLifeRecoverAmount
_080E24AC: .4byte gElfFnTable
_080E24B0:
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _080E24C0 @ =0x00000233
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	b _080E24EA
	.align 2, 0
_080E24C0: .4byte 0x00000233
_080E24C4:
	ldr r1, _080E2508 @ =gLifeRecoverAmount
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	movs r2, #0
	ldr r6, _080E250C @ =gElfFnTable
	adds r4, r5, #0
	adds r4, #0xbc
_080E24D8:
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0x1f
	bls _080E24B0
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _080E24D8
_080E24EA:
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r6
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	adds r0, r3, #0
	bl Elf1_Die
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E2508: .4byte gLifeRecoverAmount
_080E250C: .4byte gElfFnTable

	thumb_func_start FUN_080e2510
FUN_080e2510: @ 0x080E2510
	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldrb r2, [r3, #0x12]
	cmp r2, #0
	bne _080E2532
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E2574
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E2546
_080E2532:
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _080E2574
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_080E2546:
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
	ldr r1, _080E2578 @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080E2574:
	pop {r0}
	bx r0
	.align 2, 0
_080E2578: .4byte gElfFnTable
