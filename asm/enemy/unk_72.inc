	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809c3b4
FUN_0809c3b4: @ 0x0809C3B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809C428 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C41A
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C42C @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r5, [r4, #0x10]
	strb r2, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0xb4
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x28]
_0809C41A:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809C428: .4byte gZakoHeaderPtr
_0809C42C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c430
FUN_0809c430: @ 0x0809C430
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _0809C48C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C484
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C490 @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0x11]
	str r6, [r4, #0x28]
_0809C484:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C48C: .4byte gZakoHeaderPtr
_0809C490: .4byte gEnemyFnTable

	thumb_func_start Enemy72_Init
Enemy72_Init: @ 0x0809C494
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0809C534
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0809C4DE
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _0809C504
_0809C4DE:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	rsbs r0, r0, #0
_0809C504:
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xb]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r5, #0x1d]
	ldr r1, _0809C530 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r2, [r5, #0xd]
	strb r2, [r5, #0xe]
	strb r2, [r5, #0xf]
	b _0809C56E
	.align 2, 0
_0809C530: .4byte gEnemyFnTable
_0809C534:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809C57C @ =0x0836A8DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _0809C580 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r1, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
_0809C56E:
	adds r0, r5, #0
	bl Enemy72_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C57C: .4byte 0x0836A8DC
_0809C580: .4byte gEnemyFnTable

	thumb_func_start Enemy72_Update
Enemy72_Update: @ 0x0809C584
	push {lr}
	ldr r2, _0809C598 @ =0x0836A8BC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809C598: .4byte 0x0836A8BC

	thumb_func_start Enemy72_Die
Enemy72_Die: @ 0x0809C59C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0809C5B8 @ =gEnemyFnTable
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
_0809C5B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c5bc
FUN_0809c5bc: @ 0x0809C5BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #1
	beq _0809C614
	cmp r2, #1
	bgt _0809C5D0
	cmp r2, #0
	beq _0809C5D6
	b _0809C65A
_0809C5D0:
	cmp r2, #2
	beq _0809C63C
	b _0809C65A
_0809C5D6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C5F6
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0809C5FC
_0809C5F6:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0809C638 @ =0xFFFFF400
_0809C5FC:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C614:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809C65A
	.align 2, 0
_0809C638: .4byte 0xFFFFF400
_0809C63C:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809C65A
	ldr r1, _0809C660 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c664
FUN_0809c664: @ 0x0809C664
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809C6C8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C6BC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809C6B4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0809C6B8 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809C6CE
	.align 2, 0
_0809C6B4: .4byte 0xFFFFF800
_0809C6B8: .4byte 0xFFFFFC00
_0809C6BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C6EC
_0809C6C8:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809C6CE:
	bl CreateSmoke
	ldr r1, _0809C6E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809C852
	.align 2, 0
_0809C6E8: .4byte gEnemyFnTable
_0809C6EC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809C6F8
	cmp r0, #1
	beq _0809C76C
	b _0809C852
_0809C6F8:
	ldr r1, _0809C734 @ =0x0000A304
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809C738
	movs r0, #0xc0
	str r0, [r4, #0x5c]
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
	b _0809C75C
	.align 2, 0
_0809C734: .4byte 0x0000A304
_0809C738:
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
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
	orrs r0, r3
_0809C75C:
	strb r0, [r2]
	ldr r0, _0809C7EC @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C76C:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809C786
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C786
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809C7F0 @ =0x0836A8DC
	bl SetDDP
_0809C786:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809C796
	str r1, [r4, #0x60]
_0809C796:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809C7BA
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809C7F4 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809C7BA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C7F8
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C7EC: .4byte 0xFFFFFC00
_0809C7F0: .4byte 0x0836A8DC
_0809C7F4: .4byte 0xFFFFFD00
_0809C7F8:
	ldr r0, [r4, #0x54]
	ldr r1, _0809C824 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C824: .4byte 0xFFFFF800
_0809C828:
	movs r0, #0xef
	ands r0, r2
_0809C82C:
	strb r0, [r4, #0xa]
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
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809C84C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809C852:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
