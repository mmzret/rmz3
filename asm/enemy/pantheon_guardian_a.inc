	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonGuardian_Update
PantheonGuardian_Update: @ 0x08063840
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl FUN_08063f28
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	bne _0806385A
	adds r0, r4, #0
	bl FUN_080644fc
	b _08063A10
_0806385A:
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0806387C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _08063898 @ =0xFFFFE200
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080638A0
_0806387C:
	ldr r1, _0806389C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PantheonGuardian_Die
	b _08063A10
	.align 2, 0
_08063898: .4byte 0xFFFFE200
_0806389C: .4byte gEnemyFnTable
_080638A0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r7, #0x80
	lsls r7, r7, #4
	adds r1, r1, r7
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _080638C2
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080638C2:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	mov r8, r5
	cmp r0, #0
	bne _080638EA
	ldr r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080638E4
	ldr r2, _0806392C @ =Coord_08365b70
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_080638E4:
	ldr r6, [r5]
	cmp r6, #0
	beq _08063938
_080638EA:
	ldr r1, _08063930 @ =0x00001404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r5, r4, #0
	adds r5, #0x74
	ldr r6, _08063934 @ =sCollisions+(24*1)
	adds r0, r5, #0
	adds r1, r6, #0
	bl SetDDP
	mov r1, r8
	ldr r0, [r1]
	bl isKilled
	cmp r0, #0
	bne _08063914
	b _08063A10
_08063914:
	adds r1, r6, #0
	subs r1, #0x18
	adds r0, r5, #0
	bl SetDDP
	movs r0, #0
	mov r2, r8
	str r0, [r2]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _08063A10
	.align 2, 0
_0806392C: .4byte Coord_08365b70
_08063930: .4byte 0x00001404
_08063934: .4byte sCollisions+(24*1)
_08063938:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08063968
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08063964 @ =sCollisions
	bl SetDDP
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _08063A10
	.align 2, 0
_08063964: .4byte sCollisions
_08063968:
	ldr r0, [r5]
	cmp r0, #0
	beq _080639A6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r7
	bl FUN_0800a40c
	cmp r0, #0
	beq _080639A6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r7
	bl FUN_0800a40c
	adds r1, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r7
	bl PushoutToUp1
	cmp r0, #0
	beq _080639A6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r7
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080639A6:
	ldr r0, _080639C8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r4, #0x58]
	ldr r1, [r2, #0x58]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _080639CC @ =0x00005FFF
	cmp r0, r1
	bls _080639D0
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	b _080639F0
	.align 2, 0
_080639C8: .4byte pZero2
_080639CC: .4byte 0x00005FFF
_080639D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080639E4
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r2, #0x54]
	ldr r2, [r4, #0x54]
	b _080639EC
_080639E4:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r4, #0x54]
	ldr r2, [r2, #0x54]
_080639EC:
	subs r1, r1, r2
	str r1, [r0]
_080639F0:
	ldr r1, _08063A1C @ =0x08365A80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08063A20 @ =0x08365AA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08063A10:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063A1C: .4byte sPantheonGuardianUpdates1
_08063A20: .4byte sPantheonGuardianUpdates2
