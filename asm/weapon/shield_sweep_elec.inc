	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ElecShieldSweep_Init
ElecShieldSweep_Init: @ 0x0803CC98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	mov r8, r0
	ldr r1, _0803CD40 @ =gWeaponFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xb]
	movs r0, #0xfb
	ands r0, r1
	movs r6, #0
	strb r0, [r7, #0xb]
	movs r0, #0
	strh r6, [r7, #0x20]
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r7, #0xa]
	movs r1, #1
	movs r2, #0
	mov sb, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0803CD44 @ =0x00001A06
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r5, _0803CD48 @ =0x08361724
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	mov r0, r8
	bl CalcShieldBonus
	adds r2, r0, #0
	adds r2, #4
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	bl InitWeaponBody
	ldrb r2, [r7, #0x10]
	cmp r2, #0
	beq _0803CD4C
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0803CD52
	.align 2, 0
_0803CD40: .4byte gWeaponFnTable
_0803CD44: .4byte 0x00001A06
_0803CD48: .4byte 0x08361724
_0803CD4C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803CD52:
	strb r0, [r7, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	ldr r1, _0803CD90 @ =incrementShieldHitCount
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, r7, #0
	bl ElecShieldSweep_Update
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CD90: .4byte incrementShieldHitCount

	thumb_func_start ElecShieldSweep_Update
ElecShieldSweep_Update: @ 0x0803CD94
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	cmp r1, #0xf
	bhi _0803CDBA
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803CDB2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0803CDB8
_0803CDB2:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
_0803CDB8:
	strb r0, [r4, #0xa]
_0803CDBA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0803CDCE
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0803CDE6
_0803CDCE:
	ldr r1, _0803CDEC @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl ElecShieldSweep_Die
_0803CDE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDEC: .4byte gWeaponFnTable

	thumb_func_start ElecShieldSweep_Die
ElecShieldSweep_Die: @ 0x0803CDF0
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803CE0C @ =gWeaponFnTable
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
_0803CE0C: .4byte gWeaponFnTable

	thumb_func_start incrementShieldHitCount
incrementShieldHitCount: @ 0x0803CE10
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803CE32
	ldr r2, [r2, #0x2c]
	ldr r3, _0803CE38 @ =gMission
	ldrh r1, [r3, #0x22]
	ldr r0, _0803CE3C @ =0x0000FFFE
	cmp r1, r0
	bhi _0803CE2E
	adds r0, r1, #1
	strh r0, [r3, #0x22]
_0803CE2E:
	movs r0, #1
	strb r0, [r2, #0x11]
_0803CE32:
	pop {r0}
	bx r0
	.align 2, 0
_0803CE38: .4byte gMission
_0803CE3C: .4byte 0x0000FFFE
