	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MettaurSwim_Update
MettaurSwim_Update: @ 0x08088F8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08088FA0
	cmp r0, #3
	bne _08088FDC
_08088FA0:
	ldr r0, _08088FD4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bhi _08088FF4
	adds r0, r4, #0
	bl FUN_08088cfc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08088FDC
	ldr r1, _08088FD8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _08089128
	.align 2, 0
_08088FD4: .4byte gStageRun+232
_08088FD8: .4byte gEnemyFnTable
_08088FDC:
	ldrb r3, [r4, #0x10]
	cmp r3, #4
	beq _08088FE4
	b _080890E8
_08088FE4:
	ldrb r0, [r7, #0xc]
	cmp r0, #2
	bhi _08088FF4
	cmp r0, #1
	bls _08089030
	adds r0, r7, #0
	bl FUN_08088d54
_08088FF4:
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
	ldr r1, _0808902C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080891E8
	.align 2, 0
_0808902C: .4byte gEnemyFnTable
_08089030:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	adds r0, r7, #0
	bl FUN_08088d54
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080890C8 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldr r5, [r7, #0x54]
	ldr r6, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08088bc8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08088bc8
	orrs r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r5, [r7, #0x54]
	str r6, [r7, #0x58]
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _080890CC
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl MettaurSwim_Die
	b _080891E8
	.align 2, 0
_080890C8: .4byte gEnemyFnTable
_080890CC:
	ldr r1, _080890E4 @ =0x0000DD07
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #8
	strb r0, [r7, #0xd]
	strb r4, [r7, #0xe]
	b _080891E8
	.align 2, 0
_080890E4: .4byte 0x0000DD07
_080890E8:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	ldr r1, _08089120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08089124
	cmp r3, #2
	beq _08089124
	movs r0, #1
	b _08089126
	.align 2, 0
_08089120: .4byte gEnemyFnTable
_08089124:
	movs r0, #0
_08089126:
	strb r0, [r4, #0xd]
_08089128:
	adds r0, r4, #0
	bl MettaurSwim_Die
	b _080891E8
_08089130:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xc
	beq _080891C8
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08089150
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808914A
	movs r0, #1
	strb r0, [r4, #0xf]
_0808914A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080891C8
_08089150:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0808915A
	cmp r0, #3
	bne _08089192
_0808915A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _08089176
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08088bc8
_08089176:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808919C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _0808919C
_08089192:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08088c4c
_0808919C:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _080891AC
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r4, #0xf]
_080891AC:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	bne _080891B8
	strb r0, [r4, #0xf]
_080891B8:
	ldr r0, [r6]
	ldr r1, _080891F4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080891E8
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _080891E8
_080891C8:
	ldr r1, _080891F8 @ =sInitializers
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080891FC @ =sUpdates
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080891E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080891F4: .4byte 0x00020001
_080891F8: .4byte sInitializers
_080891FC: .4byte sUpdates
