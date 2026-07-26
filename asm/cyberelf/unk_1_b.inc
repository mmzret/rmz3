	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

