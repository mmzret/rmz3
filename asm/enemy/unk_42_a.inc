	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08085060
FUN_08085060: @ 0x08085060
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808507C
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0xe]
_0808507C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r2, r5, #0
	adds r2, #0xe0
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08085098
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080850BA
_08085098:
	subs r1, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	bgt _080850B4
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _080850B4
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080850BA
_080850B4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080850BA:
	strb r0, [r4, #0xa]
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080850D0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080850D6
_080850D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080850D6:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08085118
	ldr r1, _08085120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Enemy42_Die
_08085118:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085120: .4byte gEnemyFnTable

	thumb_func_start FUN_08085124
FUN_08085124: @ 0x08085124
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08085144
	b _080852C2
_08085144:
	ldrb r0, [r6, #0xd]
	cmp r0, #3
	bhi _080851EA
	cmp r0, #2
	bhi _080851DA
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	movs r5, #7
	ands r0, r5
	cmp r0, #0
	bne _080851DA
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r4, _0808519C @ =RNG_0202f388
	ldr r0, [r4]
	ldr r7, _080851A0 @ =0x000343FD
	muls r0, r7, r0
	ldr r1, _080851A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r2, r0, #1
	str r2, [r4]
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #4
	lsls r0, r0, #8
	ldr r1, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, [r6, #0x60]
	movs r0, #1
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _080851A8
	lsls r1, r3, #0xb
	ldr r0, [sp, #8]
	subs r0, r0, r1
	str r0, [sp, #8]
	b _080851C2
	.align 2, 0
_0808519C: .4byte RNG_0202f388
_080851A0: .4byte 0x000343FD
_080851A4: .4byte 0x00269EC3
_080851A8:
	adds r0, r2, #0
	muls r0, r7, r0
	ldr r1, _080851FC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	ands r0, r5
	lsls r0, r0, #0xb
	ldr r1, [sp, #8]
	subs r1, r1, r0
	str r1, [sp, #8]
_080851C2:
	adds r0, r3, #1
	movs r1, #7
	ands r0, r1
	str r0, [r6, #0x60]
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl CreateVFX57
_080851DA:
	mov r1, r8
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	beq _080851EA
	movs r0, #4
	strb r0, [r6, #0xd]
	movs r0, #0xf0
	strb r0, [r6, #0x12]
_080851EA:
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080851F2
	b _080852E0
_080851F2:
	lsls r0, r0, #2
	ldr r1, _08085200 @ =_08085204
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080851FC: .4byte 0x00269EC3
_08085200: .4byte _08085204
_08085204: @ jump table
	.4byte _08085218 @ case 0
	.4byte _08085254 @ case 1
	.4byte _08085284 @ case 2
	.4byte _080852E0 @ case 3
	.4byte _080852B4 @ case 4
_08085218:
	ldrb r0, [r6, #0x12]
	adds r1, r0, #1
	strb r1, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x30
	bls _080852E0
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08085250 @ =0x083683B4
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
	b _080852A4
	.align 2, 0
_08085250: .4byte 0x083683B4
_08085254:
	ldrb r0, [r6, #0x12]
	adds r1, r0, #1
	strb r1, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _080852E0
	ldr r1, _0808527C @ =0x0000620A
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08085280 @ =0x083683E4
	bl SetDDP
	movs r0, #0
	strb r0, [r6, #0x12]
	b _080852A4
	.align 2, 0
_0808527C: .4byte 0x0000620A
_08085280: .4byte 0x083683E4
_08085284:
	ldrb r0, [r6, #0x12]
	adds r1, r0, #1
	strb r1, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _080852E0
	ldr r1, _080852AC @ =0x0000620B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080852B0 @ =0x08368414
	bl SetDDP
_080852A4:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080852E0
	.align 2, 0
_080852AC: .4byte 0x0000620B
_080852B0: .4byte 0x08368414
_080852B4:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080852E0
_080852C2:
	ldr r1, _080852DC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl FUN_0808537c
	b _080852E6
	.align 2, 0
_080852DC: .4byte gEnemyFnTable
_080852E0:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080852E6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
