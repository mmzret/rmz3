	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08084dc8
FUN_08084dc8: @ 0x08084DC8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _08084DE8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	bne _08084DEC
	movs r0, #0
	b _08084E2A
	.align 2, 0
_08084DE8: .4byte gZakoHeaderPtr
_08084DEC:
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08084E30 @ =gEnemyFnTable
	movs r1, #0x2a
	strb r1, [r3, #9]
	adds r0, #0xa8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	strb r6, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r4, [r3, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r0, r3, #0
_08084E2A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08084E30: .4byte gEnemyFnTable

	thumb_func_start Enemy42_Init
Enemy42_Init: @ 0x08084E34
	push {lr}
	ldr r2, _08084E48 @ =0x08368390
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08084E48: .4byte 0x08368390

	thumb_func_start Enemy42_Update
Enemy42_Update: @ 0x08084E4C
	push {lr}
	ldr r2, _08084E60 @ =0x0836839C
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08084E60: .4byte 0x0836839C

	thumb_func_start Enemy42_Die
Enemy42_Die: @ 0x08084E64
	push {lr}
	ldr r2, _08084E78 @ =0x083683A8
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08084E78: .4byte 0x083683A8

	thumb_func_start FUN_08084e7c
FUN_08084e7c: @ 0x08084E7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldr r1, _08084ED0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldrb r0, [r6, #0x1c]
	strb r0, [r5, #0x1d]
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _08084ED4
	ldrb r0, [r5, #0xa]
	orrs r0, r1
	b _08084EDA
	.align 2, 0
_08084ED0: .4byte gEnemyFnTable
_08084ED4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08084EDA:
	strb r0, [r5, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	strb r3, [r5, #0xe]
	adds r0, r5, #0
	bl Enemy42_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084f18
FUN_08084f18: @ 0x08084F18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08084F54 @ =gEnemyFnTable
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
	ldrb r1, [r4, #0xa]
	movs r0, #2
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08084F58 @ =0x00006209
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x11]
	cmp r2, #0
	beq _08084F5C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08084F62
	.align 2, 0
_08084F54: .4byte gEnemyFnTable
_08084F58: .4byte 0x00006209
_08084F5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08084F62:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08084F94
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a22c
	b _08084F9C
_08084F94:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a31c
_08084F9C:
	str r0, [r4, #0x54]
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl Enemy42_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084fb4
FUN_08084fb4: @ 0x08084FB4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldr r1, _08084FFC @ =gEnemyFnTable
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
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08085000 @ =0x0000B40D
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x11]
	cmp r2, #0
	beq _08085004
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0808500A
	.align 2, 0
_08084FFC: .4byte gEnemyFnTable
_08085000: .4byte 0x0000B40D
_08085004:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808500A:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r6, #0x1c]
	strb r0, [r4, #0x1d]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08085048
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #2
	b _0808504E
_08085048:
	movs r0, #0x80
	str r0, [r4, #0x5c]
	subs r0, #0x82
_0808504E:
	str r0, [r4, #0x64]
	movs r0, #0
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl Enemy42_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
_080852E6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080852f4
FUN_080852f4: @ 0x080852F4
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r2, [r4, #0xf]
	adds r3, r2, #0
	cmp r3, #0
	bne _08085328
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _08085342
	adds r0, r2, #1
	strb r0, [r4, #0xf]
	strb r3, [r4, #0x12]
	b _08085342
_08085328:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xf]
	cmp r0, #3
	bls _08085342
	ldr r1, _08085348 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08085342:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085348: .4byte gEnemyFnTable

	thumb_func_start FUN_0808534c
FUN_0808534c:
	.byte 0x02, 0x1C, 0x8C, 0x30
	.byte 0x00, 0x21, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20
	.byte 0x08, 0x40, 0x90, 0x72, 0x04, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60
	.byte 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
	.align 2, 0
	.4byte gEnemyFnTable

	thumb_func_start FUN_0808537c
FUN_0808537c: @ 0x0808537C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r2, #1
	cmp r0, #0
	beq _08085398
	movs r2, #0xff
_08085398:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _08085560 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _08085564 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _08085568 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r3, #0x7f
	ands r0, r3
	adds r0, #0x80
	lsls r2, r2, #0x18
	mov r8, r2
	asrs r2, r2, #0x18
	mov r8, r2
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #0
	bl CreateVFX57
	ldr r0, [sp, #8]
	ldr r3, _08085570 @ =0xFFFFF000
	mov sl, r3
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xff
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	mov sb, r3
	add r0, sb
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xff
	ands r0, r2
	add r0, sb
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08085574 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085560: .4byte RNG_0202f388
_08085564: .4byte 0x000343FD
_08085568: .4byte 0x00269EC3
_0808556C: .4byte 0x000003FF
_08085570: .4byte 0xFFFFF000
_08085574: .4byte gEnemyFnTable

	thumb_func_start FUN_08085578
FUN_08085578:
	.byte 0x04, 0x4A, 0x41, 0x7A, 0x89, 0x00, 0x89, 0x18
	.byte 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69, 0x41, 0x61, 0x70, 0x47
	.align 2, 0
	.4byte gEnemyFnTable
