	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Ghost75_Init
Ghost75_Init: @ 0x080C75DC
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080C7618
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080C7638
_080C7618:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080C7638:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C7644
	movs r0, #0x80
	rsbs r0, r0, #0
	b _080C7646
_080C7644:
	movs r0, #0x80
_080C7646:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C7670
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C766C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C76A2
	.align 2, 0
_080C766C: .4byte gVFXFnTable
_080C7670:
	ldr r2, _080C76B4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C76B8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C76BC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x60
	strb r0, [r4, #0x12]
	ldr r1, _080C76C0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
_080C76A2:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl Ghost75_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C76B4: .4byte RNG_0202f388
_080C76B8: .4byte 0x000343FD
_080C76BC: .4byte 0x00269EC3
_080C76C0: .4byte gVFXFnTable

	thumb_func_start Ghost75_Update
Ghost75_Update: @ 0x080C76C4
	push {lr}
	ldr r2, _080C76D8 @ =0x0836F8B4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C76D8: .4byte 0x0836F8B4

	thumb_func_start Ghost75_Die
Ghost75_Die: @ 0x080C76DC
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C76F8 @ =gVFXFnTable
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
_080C76F8: .4byte gVFXFnTable

	thumb_func_start nop_080c76fc
nop_080c76fc: @ 0x080C76FC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c7700
FUN_080c7700: @ 0x080C7700
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C7798
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080C7780 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C7784 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C7788 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0x10]
	ldr r5, _080C778C @ =0x0000D50E
	mov r0, sp
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0x10]
	ldr r2, _080C7790 @ =0x0000D50D
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0x10]
	mov r0, sp
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080C7794 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C77E0
	.align 2, 0
_080C7780: .4byte RNG_0202f388
_080C7784: .4byte 0x000343FD
_080C7788: .4byte 0x00269EC3
_080C778C: .4byte 0x0000D50E
_080C7790: .4byte 0x0000D50D
_080C7794: .4byte gVFXFnTable
_080C7798:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080C77A4
	cmp r0, #1
	beq _080C77BA
	b _080C77E0
_080C77A4:
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r0, _080C77E8 @ =0xFFFFFE80
	str r0, [r6, #0x60]
	ldr r1, _080C77EC @ =0x0000D506
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C77BA:
	ldr r0, [r6, #0x60]
	adds r0, #0x10
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C77CA
	str r1, [r6, #0x60]
_080C77CA:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080C77E0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C77E8: .4byte 0xFFFFFE80
_080C77EC: .4byte 0x0000D506

	thumb_func_start FUN_080c77f0
FUN_080c77f0: @ 0x080C77F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C7826
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C7864
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C7864
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C7864
_080C7826:
	ldr r0, _080C785C @ =gStageRun+232
	adds r4, r7, #0
	adds r4, #0x54
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bhi _080C7848
	movs r0, #2
	adds r1, r4, #0
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_080C7848:
	ldr r1, _080C7860 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C7910
	.align 2, 0
_080C785C: .4byte gStageRun+232
_080C7860: .4byte gVFXFnTable
_080C7864:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C7872
	cmp r0, #1
	beq _080C78E4
	b _080C7910
_080C7872:
	ldr r4, _080C791C @ =0x0836F920
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080C7920 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C7924 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C7928 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C78E4:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C78FA
	str r1, [r7, #0x60]
_080C78FA:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080C7910:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C791C: .4byte 0x0836F920
_080C7920: .4byte RNG_0202f388
_080C7924: .4byte 0x000343FD
_080C7928: .4byte 0x00269EC3

