	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start NurseB_Init
NurseB_Init: @ 0x080E25EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldr r1, _080E2684 @ =gZeroRanges
	ldr r2, _080E2688 @ =0x00000147
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r0, #0
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	asrs r4, r4, #0x10
	ldr r0, [r7, #0x58]
	adds r0, r0, r4
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xbc
	mov r2, r8
	str r2, [r0]
	str r2, [r0, #4]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080E268C
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	b _080E2694
	.align 2, 0
_080E2684: .4byte gZeroRanges
_080E2688: .4byte 0x00000147
_080E268C:
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #8
	strb r0, [r1]
_080E2694:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r6, #0
	adds r1, r7, #0
	bl CreateElf3
	ldr r1, _080E26C8 @ =gElfFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl NurseB_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E26C8: .4byte gElfFnTable

	thumb_func_start NurseB_Update
NurseB_Update: @ 0x080E26CC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r1, _080E2734 @ =gZeroRanges
	ldr r2, _080E2738 @ =0x00000147
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r7, [r0, #4]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _080E273C @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	beq _080E26F4
	b _080E280E
_080E26F4:
	ldr r1, _080E2740 @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E2748
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E2744 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E280E
	.align 2, 0
_080E2734: .4byte gZeroRanges
_080E2738: .4byte 0x00000147
_080E273C: .4byte gPause
_080E2740: .4byte 0x00000232
_080E2744: .4byte gElfFnTable
_080E2748:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E2764
	adds r0, r5, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E277C
_080E2764:
	ldr r1, _080E2778 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080E280E
	.align 2, 0
_080E2778: .4byte gElfFnTable
_080E277C:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	asrs r1, r6, #0x10
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldr r1, _080E2814 @ =sNurseBUpdates
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r3, [r1]
	adds r3, #1
	adds r0, r3, #0
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r3, r3, r0
	adds r0, r3, #0
	strb r3, [r1]
	lsls r3, r3, #4
	ldr r1, _080E2818 @ =gSineTable
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #4
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #4]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	movs r1, #0x10
	cmp r0, #0x7f
	ble _080E27E8
	movs r1, #0x11
_080E27E8:
	adds r0, r4, #0
	adds r0, #0x25
	strb r1, [r0]
	adds r5, r4, #0
	adds r5, #0xb9
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E280E
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r5]
_080E280E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E2814: .4byte sNurseBUpdates
_080E2818: .4byte gSineTable

