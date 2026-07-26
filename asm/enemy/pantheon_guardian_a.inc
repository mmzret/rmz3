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

	thumb_func_start PantheonGuardian_Die
PantheonGuardian_Die: @ 0x08063A24
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _08063A6C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08063A74
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _08063A70 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08063D80
	.align 2, 0
_08063A6C: .4byte gCurStory
_08063A70: .4byte gEnemyFnTable
_08063A74:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xb
	bls _08063A7C
	b _08063D82
_08063A7C:
	lsls r0, r0, #2
	ldr r1, _08063A88 @ =_08063A8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08063A88: .4byte _08063A8C
_08063A8C: @ jump table
	.4byte _08063ABC @ case 0
	.4byte _08063BA0 @ case 1
	.4byte _08063BB4 @ case 2
	.4byte _08063C26 @ case 3
	.4byte _08063D46 @ case 4
	.4byte _08063D82 @ case 5
	.4byte _08063D82 @ case 6
	.4byte _08063D82 @ case 7
	.4byte _08063D82 @ case 8
	.4byte _08063D82 @ case 9
	.4byte _08063BA0 @ case 10
	.4byte _08063D14 @ case 11
_08063ABC:
	ldr r1, _08063AF0 @ =0x00001404
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _08063AF4
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
	b _08063B16
	.align 2, 0
_08063AF0: .4byte 0x00001404
_08063AF4:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08063B16:
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r2, #0
	ands r0, r5
	adds r6, r1, #0
	cmp r0, #0
	beq _08063B86
	adds r0, r4, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	bne _08063B86
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08063B86
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, #0x40
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08063B86
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08063B70 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r0, [r7]
	cmp r0, #0
	beq _08063B74
	movs r0, #0
	mov r1, sp
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080b2b40
	b _08063B80
	.align 2, 0
_08063B70: .4byte 0xFFFFEC00
_08063B74:
	movs r0, #0
	mov r1, sp
	adds r2, r5, #0
	movs r3, #1
	bl FUN_080b2b40
_08063B80:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _08063B88
_08063B86:
	movs r0, #0xa
_08063B88:
	strb r0, [r4, #0xd]
	movs r1, #0
	str r1, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_08063BA0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08063BB2
	b _08063D82
_08063BB2:
	b _08063D06
_08063BB4:
	adds r0, r4, #0
	bl InitRotatableMotion
	ldr r1, _08063BEC @ =0x00001406
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063BF0
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
	b _08063C12
	.align 2, 0
_08063BEC: .4byte 0x00001406
_08063BF0:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08063C12:
	adds r0, r4, #0
	bl CreateGhost17_1
	movs r0, #0
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_08063C26:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r3, [r4, #0x12]
	lsrs r0, r3, #5
	ldrb r5, [r4, #0x13]
	adds r0, r0, r5
	strb r0, [r4, #0x13]
	ldr r5, _08063CAC @ =gSineTable
	adds r0, r3, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063CB0
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	ldrb r1, [r4, #0x12]
	ldrb r2, [r4, #0x13]
	adds r2, r1, r2
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r6, #0
	ldrsh r3, [r0, r6]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r3, r3, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r1, [r4, #0x54]
	subs r0, r1, r0
	str r0, [r4, #0x54]
	strb r2, [r4, #0x12]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #0x3f
	bls _08063D82
	movs r6, #0xa0
	lsls r6, r6, #4
	b _08063CF0
	.align 2, 0
_08063CAC: .4byte gSineTable
_08063CB0:
	adds r0, r4, #0
	adds r0, #0x24
	strb r3, [r0]
	ldrb r1, [r4, #0x12]
	ldrb r2, [r4, #0x13]
	adds r2, r1, r2
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r6, #0
	ldrsh r3, [r0, r6]
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r3, r3, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r1, [r4, #0x54]
	adds r0, r1, r0
	str r0, [r4, #0x54]
	strb r2, [r4, #0x12]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #0x3f
	bls _08063D82
	ldr r6, _08063D10 @ =0xFFFFF600
_08063CF0:
	adds r0, r0, r6
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_08063D06:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _08063D82
	.align 2, 0
_08063D10: .4byte 0xFFFFF600
_08063D14:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08063D8C @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp, #4]
	ldr r5, _08063D90 @ =0xFFFFF400
	adds r0, r0, r5
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r0, r4, #0
	mov r1, sp
	bl CreateGhost17_2
_08063D46:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08063D94 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08063D98 @ =0x0000270E
	cmp r1, r0
	bhi _08063D60
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08063D60:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08063D9C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08063D80:
	str r0, [r4, #0x14]
_08063D82:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063D8C: .4byte 0xFFFFF600
_08063D90: .4byte 0xFFFFF400
_08063D94: .4byte gScore
_08063D98: .4byte 0x0000270E
_08063D9C: .4byte gEnemyFnTable
