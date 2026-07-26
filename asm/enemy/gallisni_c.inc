	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start Gallisni_Update
Gallisni_Update: @ 0x0808728C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08087318
	ldr r0, _080872C4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080872C8
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
	b _080872F4
	.align 2, 0
_080872C4: .4byte gCurStory
_080872C8:
	ldr r0, _08087310 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bls _08087318
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_080872F4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08087314 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08087356
	.align 2, 0
_08087310: .4byte gStageRun+232
_08087314: .4byte gEnemyFnTable
_08087318:
	adds r0, r4, #0
	bl gallisni_080870bc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08087356
	adds r0, r4, #0
	bl gallisni_080871b4
	adds r0, r4, #0
	bl gallisni_08087118
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08087356
	ldr r1, _0808735C @ =0x0836868C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08087360 @ =0x083686AC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08087356:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808735C: .4byte 0x0836868C
_08087360: .4byte 0x083686AC
