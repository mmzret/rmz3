	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08086ff0
FUN_08086ff0: @ 0x08086FF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x2c]
	ldr r1, [r2, #0x2c]
	mov r8, r1
	ldrh r1, [r0, #8]
	ldr r0, _080870A0 @ =0x00002E03
	cmp r1, r0
	beq _08087094
	mov r1, r8
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _08087094
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08087094
	mov r4, r8
	adds r4, #0xb8
	ldrb r0, [r4]
	mov sb, r0
	cmp r0, #0
	bne _08087094
	ldr r7, _080870A4 @ =gStageRun+232
	mov r1, r8
	adds r1, #0x54
	adds r0, r7, #0
	bl Camera_GetDistance
	ldr r1, _080870A8 @ =0x000007FF
	cmp r0, r1
	bhi _08087094
	movs r0, #0xff
	strb r0, [r4]
	ldr r0, [r7, #0x38]
	ldr r6, _080870AC @ =0x00008BFF
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B0 @ =0xFFFF9C00
	adds r1, r1, r4
	movs r2, #0
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	ldr r5, _080870B4 @ =0xFFFF7400
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #1
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r6
	ldr r1, [r7, #0x3c]
	ldr r4, _080870B8 @ =0x000063FF
	adds r1, r1, r4
	movs r2, #2
	bl CreateGallisni
	ldr r0, [r7, #0x38]
	adds r0, r0, r5
	ldr r1, [r7, #0x3c]
	adds r1, r1, r4
	movs r2, #3
	bl CreateGallisni
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #0xd]
	mov r0, sb
	strb r0, [r1, #0xe]
	movs r0, #0x40
	strb r0, [r1, #0x12]
_08087094:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870A0: .4byte 0x00002E03
_080870A4: .4byte gStageRun+232
_080870A8: .4byte 0x000007FF
_080870AC: .4byte 0x00008BFF
_080870B0: .4byte 0xFFFF9C00
_080870B4: .4byte 0xFFFF7400
_080870B8: .4byte 0x000063FF

	thumb_func_start gallisni_080870bc
gallisni_080870bc: @ 0x080870BC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808710E
	ldr r1, _080870FC @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08087100
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08087102
	strb r4, [r2, #0xd]
	b _08087104
	.align 2, 0
_080870FC: .4byte gEnemyFnTable
_08087100:
	movs r0, #1
_08087102:
	strb r0, [r2, #0xd]
_08087104:
	adds r0, r2, #0
	bl Gallisni_Die
	movs r0, #1
	b _08087110
_0808710E:
	movs r0, #0
_08087110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start gallisni_08087118
gallisni_08087118: @ 0x08087118
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080871AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080871AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08087138
	cmp r0, #1
	beq _08087188
	b _080871AA
_08087138:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080871AA
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0808714E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808714E:
	ldr r1, _08087180 @ =0x0836868C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08087184 @ =0x083686AC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808717A:
	movs r0, #1
	b _080871AC
	.align 2, 0
_08087180: .4byte 0x0836868C
_08087184: .4byte 0x083686AC
_08087188:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080871A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080871A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808717A
	strb r5, [r4, #0xf]
	b _080871AA
	.align 2, 0
_080871A4: .4byte 0x00020001
_080871A8:
	strb r0, [r4, #0xf]
_080871AA:
	movs r0, #0
_080871AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start gallisni_080871b4
gallisni_080871b4: @ 0x080871B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080871F4
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080871F4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080871E0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080871F4
_080871E0:
	ldr r2, _080871FC @ =0x08368750
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080871F4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080871F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080871FC: .4byte 0x08368750

	thumb_func_start Gallisni_Init
Gallisni_Init: @ 0x08087200
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808727C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08087280 @ =0x08368758
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087284 @ =0x083686D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08087288 @ =FUN_08086ff0
	str r0, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r4, [r6, #0x10]
	cmp r4, #0
	bne _08087270
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	strb r4, [r0]
_08087270:
	adds r0, r6, #0
	bl Gallisni_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808727C: .4byte gEnemyFnTable
_08087280: .4byte 0x08368758
_08087284: .4byte 0x083686D8
_08087288: .4byte FUN_08086ff0

