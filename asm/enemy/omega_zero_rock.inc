	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateOzChargeSaberRock
CreateOzChargeSaberRock: @ 0x0808B538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	adds r7, r5, #0
	ldr r0, _0808B5C4 @ =0xFFFFD000
	adds r5, r5, r0
	ldr r2, _0808B5C8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808B5CC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808B5D0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #7
	bl __umodsi3
	adds r5, r5, r0
	ldr r0, _0808B5D4 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0808B5D8 @ =0xFFFF9000
	adds r6, r0, r1
	ldr r0, _0808B5DC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0808B5BA
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808B5E0 @ =gEnemyFnTable
	movs r1, #0x34
	strb r1, [r4, #9]
	adds r0, #0xd0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
	str r7, [r4, #0x64]
	mov r0, r8
	strb r0, [r4, #0x13]
_0808B5BA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B5C4: .4byte 0xFFFFD000
_0808B5C8: .4byte RNG_0202f388
_0808B5CC: .4byte 0x000343FD
_0808B5D0: .4byte 0x00269EC3
_0808B5D4: .4byte gStageRun+232
_0808B5D8: .4byte 0xFFFF9000
_0808B5DC: .4byte gZakoHeaderPtr
_0808B5E0: .4byte gEnemyFnTable

	thumb_func_start nop_0808b5e4
nop_0808b5e4: @ 0x0808B5E4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808b5e8
FUN_0808b5e8: @ 0x0808B5E8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808B5FE
	movs r0, #0
	b _0808B618
_0808B5FE:
	ldr r1, _0808B61C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl OmegaZeroRock_Die
	movs r0, #1
_0808B618:
	pop {r1}
	bx r1
	.align 2, 0
_0808B61C: .4byte gEnemyFnTable

	thumb_func_start OmegaZeroRock_Init
OmegaZeroRock_Init: @ 0x0808B620
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808B680 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0808B684 @ =0x08368D78
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
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0808B688 @ =0x08368D48
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #5
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0808B68C @ =nop_0808b5e4
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl OmegaZeroRock_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B680: .4byte gEnemyFnTable
_0808B684: .4byte 0x08368D78
_0808B688: .4byte 0x08368D48
_0808B68C: .4byte nop_0808b5e4

	thumb_func_start OmegaZeroRock_Update
OmegaZeroRock_Update: @ 0x0808B690
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b5e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B6BE
	ldr r1, _0808B6C4 @ =0x08368D40
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808B6C8 @ =0x08368D44
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808B6BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6C4: .4byte 0x08368D40
_0808B6C8: .4byte 0x08368D44

	thumb_func_start OmegaZeroRock_Die
OmegaZeroRock_Die: @ 0x0808B6CC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x41
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	ldr r2, _0808B6FC @ =0x08368D7A
	adds r0, r4, #0
	movs r3, #3
	bl FUN_080b7ffc
	ldr r1, _0808B700 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6FC: .4byte 0x08368D7A
_0808B700: .4byte gEnemyFnTable

	thumb_func_start nop_0808b704
nop_0808b704: @ 0x0808B704
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808b708
FUN_0808b708: @ 0x0808B708
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808B718
	cmp r0, #1
	beq _0808B72E
	b _0808B78E
_0808B718:
	str r0, [r4, #0x60]
	movs r0, #0x10
	strb r0, [r4, #0x12]
	movs r1, #0xed
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B72E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808B73E
	str r1, [r4, #0x60]
_0808B73E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0808B76A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B788
	ldrb r1, [r4, #0x13]
	cmp r1, #1
	bhi _0808B788
	ldr r0, [r4, #0x64]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateOzChargeSaberRock
	b _0808B788
_0808B76A:
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808B788
	ldr r1, _0808B794 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0808B788:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808B78E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B794: .4byte gEnemyFnTable
