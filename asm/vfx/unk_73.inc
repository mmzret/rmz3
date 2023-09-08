	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c6e70
FUN_080c6e70: @ 0x080C6E70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r5, r1, #0
	movs r4, #0
	movs r7, #0
	movs r6, #1
	ldr r0, _080C6ED0 @ =0x0836DA24
	mov sb, r0
_080C6E86:
	ldr r0, _080C6ED4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080C6EBC
	adds r0, #0x25
	strb r6, [r0]
	movs r0, #0x49
	strb r0, [r1, #9]
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r7, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r7, [r0]
	strb r6, [r1, #0x10]
	strb r4, [r1, #0x11]
	mov r0, r8
	str r0, [r1, #0x28]
	ldr r0, [r5]
	str r0, [r1, #0x54]
	ldr r0, [r5, #4]
	str r0, [r1, #0x58]
_080C6EBC:
	adds r4, #1
	cmp r4, #2
	ble _080C6E86
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6ED0: .4byte 0x0836DA24
_080C6ED4: .4byte gVFXHeaderPtr

	thumb_func_start Ghost73_Init
Ghost73_Init: @ 0x080C6ED8
	push {lr}
	ldr r2, _080C6EEC @ =0x0836F874
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C6EEC: .4byte 0x0836F874

	thumb_func_start Ghost73_Update
Ghost73_Update: @ 0x080C6EF0
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C6F20 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080C6F28
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080C6F24 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080C6F38
	.align 2, 0
_080C6F20: .4byte gCurStory
_080C6F24: .4byte gVFXFnTable
_080C6F28:
	ldr r0, _080C6F3C @ =0x0836F87C
	ldrb r1, [r2, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080C6F38:
	pop {r0}
	bx r0
	.align 2, 0
_080C6F3C: .4byte 0x0836F87C

	thumb_func_start Ghost73_Die
Ghost73_Die: @ 0x080C6F40
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C6F5C @ =gVFXFnTable
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
_080C6F5C: .4byte gVFXFnTable

	thumb_func_start FUN_080c6f60
FUN_080c6f60: @ 0x080C6F60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	mov r8, r0
	movs r1, #0x54
	add r1, r8
	mov sb, r1
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x1c
	movs r1, #1
	ands r4, r1
	lsrs r6, r0, #0x1d
	ands r6, r1
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, _080C6FA8 @ =0x0000DC06
	adds r0, r5, #0
	bl SetMotion
	cmp r4, #0
	beq _080C6FAC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C6FB2
	.align 2, 0
_080C6FA8: .4byte 0x0000DC06
_080C6FAC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C6FB2:
	strb r0, [r5, #0xa]
	adds r1, r4, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	adds r3, r6, #0
	adds r4, r2, #0
	cmp r3, #0
	beq _080C6FDE
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080C6FE4
_080C6FDE:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080C6FE4:
	strb r0, [r5, #0xa]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r3
	adds r0, r5, #0
	adds r0, #0x4d
	strb r1, [r0]
	lsls r1, r1, #5
	ldrb r2, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r2, sb
	ldr r0, [r2]
	str r0, [r5, #0x54]
	ldr r0, [r2, #4]
	str r0, [r5, #0x58]
	mov r1, r8
	ldr r0, [r1, #0x5c]
	str r0, [r5, #0x5c]
	movs r1, #0
	mov r2, r8
	ldrb r0, [r2, #0xf]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080C7022
	movs r1, #1
_080C7022:
	strb r1, [r5, #0x13]
	movs r0, #0
	cmp r1, #0
	beq _080C702E
	mov r1, r8
	ldr r0, [r1, #0x60]
_080C702E:
	str r0, [r5, #0x60]
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldr r1, _080C7058 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Ghost73_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7058: .4byte gVFXFnTable

	thumb_func_start FUN_080c705c
FUN_080c705c: @ 0x080C705C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #0xf5
	muls r0, r1, r0
	cmp r0, #0
	bge _080C7072
	adds r0, #0xff
_080C7072:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080C7094
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C7094
	str r1, [r5, #0x60]
_080C7094:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080C70D8
	ldr r4, [r5, #0x54]
	ldr r2, [r5, #0x58]
	ldr r0, _080C70D4 @ =0xFFFFFE00
	adds r3, r2, r0
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080C70BE
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r2, r0
_080C70BE:
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C70EA
	movs r0, #0
	strb r0, [r5, #0x12]
	b _080C70EA
	.align 2, 0
_080C70D4: .4byte 0xFFFFFE00
_080C70D8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r0, r1
	ble _080C70EA
	str r1, [r5, #0x58]
_080C70EA:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080C7116
	ldr r0, [r5, #0x28]
	adds r4, r5, #0
	adds r4, #0x54
	adds r1, r4, #0
	bl FUN_080c6e70
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	ldr r1, _080C711C @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080C7116:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C711C: .4byte gVFXFnTable

	thumb_func_start FUN_080c7120
FUN_080c7120: @ 0x080C7120
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	mov r8, r0
	ldrb r0, [r0, #0xa]
	lsrs r6, r0, #4
	movs r0, #1
	ands r6, r0
	ldrb r5, [r7, #0x11]
	ldrb r1, [r7, #0xa]
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	cmp r5, #1
	bne _080C714C
	adds r1, r6, #0
	eors r1, r5
	b _080C714E
_080C714C:
	adds r1, r6, #0
_080C714E:
	adds r2, r1, #0
	cmp r2, #0
	beq _080C715C
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080C7162
_080C715C:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C7162:
	strb r0, [r7, #0xa]
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r1, r8
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #5
	ands r2, r4
	cmp r2, #0
	beq _080C7196
	ldrb r0, [r7, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080C719C
_080C7196:
	ldrb r1, [r7, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080C719C:
	strb r0, [r7, #0xa]
	movs r0, #1
	mov r8, r0
	mov r1, r8
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4d
	strb r1, [r0]
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080C7230 @ =0x0836F884
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	cmp r6, #0
	beq _080C71D0
	movs r0, #2
	subs r5, r0, r5
_080C71D0:
	subs r1, r5, #1
	lsls r1, r1, #8
	ldr r6, _080C7234 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080C7238 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080C723C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080C7240 @ =0x000001FF
	ands r0, r4
	adds r1, r1, r0
	ldr r0, _080C7244 @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, _080C7248 @ =0xFFFFFE00
	subs r1, r1, r0
	str r1, [r7, #0x60]
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _080C724C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Ghost73_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7230: .4byte 0x0836F884
_080C7234: .4byte RNG_0202f388
_080C7238: .4byte 0x000343FD
_080C723C: .4byte 0x00269EC3
_080C7240: .4byte 0x000001FF
_080C7244: .4byte 0xFFFFFF00
_080C7248: .4byte 0xFFFFFE00
_080C724C: .4byte gVFXFnTable

	thumb_func_start FUN_080c7250
FUN_080c7250: @ 0x080C7250
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C7282
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080C7288
_080C7282:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C7288:
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080C72B4
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080C72BC @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C72B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C72BC: .4byte gVFXFnTable

