	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start GlacierleAtkArm_Init
GlacierleAtkArm_Init: @ 0x080828E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08082940 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08082944 @ =0x08368170
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r1, r0
	movs r0, #1
	movs r2, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08082932
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08082948 @ =0x08368140
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0808294C @ =nop_080828dc
	str r0, [r4, #0x24]
_08082932:
	adds r0, r5, #0
	bl GlacierleAtkArm_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082940: .4byte gEnemyFnTable
_08082944: .4byte 0x08368170
_08082948: .4byte 0x08368140
_0808294C: .4byte nop_080828dc

	thumb_func_start GlacierleAtkArm_Update
GlacierleAtkArm_Update: @ 0x08082950
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808297C @ =0x08368128
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08082980 @ =0x08368134
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808297C: .4byte 0x08368128
_08082980: .4byte 0x08368134

	thumb_func_start GlacierleAtkArm_Die
GlacierleAtkArm_Die: @ 0x08082984
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	blt _08082A12
	cmp r0, #1
	ble _08082998
	cmp r0, #2
	beq _08082A00
	b _08082A12
_08082998:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080829A4
	cmp r0, #1
	beq _080829AC
	b _08082A12
_080829A4:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080829AC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080829BC
	str r1, [r4, #0x60]
_080829BC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08082A12
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080829E8
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08082A00
_080829E8:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08082A00
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_08082A00:
	ldr r1, _08082A18 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08082A12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08082A18: .4byte gEnemyFnTable
