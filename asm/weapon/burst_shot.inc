	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start BurstShot_Init
BurstShot_Init: @ 0x0803B620
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov sb, r0
	ldr r1, [r4, #0x2c]
	mov sl, r1
	ldr r1, _0803B6D8 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0803B6DC @ =0x083615D8
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r6, _0803B6E0 @ =0x083615AC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	mov r0, r8
	str r0, [r5, #0x24]
	mov r0, sb
	bl CalcBusterBonus
	adds r2, r0, #0
	adds r2, #2
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #2
	str r0, [sp]
	mov r1, sl
	ldrb r0, [r1, #0x13]
	lsrs r0, r0, #2
	adds r0, #2
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #2
	bl InitWeaponBody
	ldr r0, _0803B6E4 @ =FUN_0803b73c
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl BurstShot_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B6D8: .4byte gWeaponFnTable
_0803B6DC: .4byte 0x083615D8
_0803B6E0: .4byte 0x083615AC
_0803B6E4: .4byte FUN_0803b73c

	thumb_func_start BurstShot_Update
BurstShot_Update: @ 0x0803B6E8
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803B712
	ldr r1, _0803B718 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl BurstShot_Die
_0803B712:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B718: .4byte gWeaponFnTable

	thumb_func_start BurstShot_Die
BurstShot_Die: @ 0x0803B71C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803B738 @ =gWeaponFnTable
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
_0803B738: .4byte gWeaponFnTable

	thumb_func_start FUN_0803b73c
FUN_0803b73c: @ 0x0803B73C
	push {lr}
	ldr r0, [r0, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803B756
	ldr r2, _0803B75C @ =gMission
	ldrh r1, [r2, #0x1c]
	ldr r0, _0803B760 @ =0x0000FFFE
	cmp r1, r0
	bhi _0803B756
	adds r0, r1, #1
	strh r0, [r2, #0x1c]
_0803B756:
	pop {r0}
	bx r0
	.align 2, 0
_0803B75C: .4byte gMission
_0803B760: .4byte 0x0000FFFE
