	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c2e7c
FUN_080c2e7c: @ 0x080C2E7C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C2EC8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C2EC0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C2ECC @ =gVFXFnTable
	movs r1, #0x3d
	strb r1, [r3, #9]
	adds r0, #0xf4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080C2EC0:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080C2EC8: .4byte gVFXHeaderPtr
_080C2ECC: .4byte gVFXFnTable

	thumb_func_start FUN_080c2ed0
FUN_080c2ed0: @ 0x080C2ED0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080C2F34 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2F26
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080C2F38 @ =gVFXFnTable
	movs r1, #0x3d
	strb r1, [r4, #9]
	adds r0, #0xf4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080C2F26:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C2F34: .4byte gVFXHeaderPtr
_080C2F38: .4byte gVFXFnTable

	thumb_func_start FUN_080c2f3c
FUN_080c2f3c: @ 0x080C2F3C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C2F8C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C2F82
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C2F90 @ =gVFXFnTable
	movs r1, #0x3d
	strb r1, [r3, #9]
	adds r0, #0xf4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	movs r0, #2
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080C2F82:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080C2F8C: .4byte gVFXHeaderPtr
_080C2F90: .4byte gVFXFnTable

	thumb_func_start VFX61_Init
VFX61_Init: @ 0x080C2F94
	push {r4, r5, lr}
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
	bne _080C2FD0
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
	b _080C2FF0
_080C2FD0:
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
_080C2FF0:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C2FFC
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080C2FFE
_080C2FFC:
	movs r0, #0xc0
_080C2FFE:
	str r0, [r4, #0x5c]
	movs r5, #0
	str r5, [r4, #0x60]
	ldrb r3, [r4, #0x11]
	cmp r3, #0
	bne _080C3028
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C3024 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C3088
	.align 2, 0
_080C3024: .4byte gVFXFnTable
_080C3028:
	cmp r3, #1
	bne _080C3070
	ldr r2, _080C3060 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C3064 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C3068 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080C306C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
	b _080C3088
	.align 2, 0
_080C3060: .4byte RNG_0202f388
_080C3064: .4byte 0x000343FD
_080C3068: .4byte 0x00269EC3
_080C306C: .4byte gVFXFnTable
_080C3070:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C3098 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
_080C3088:
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	adds r0, r4, #0
	bl VFX61_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3098: .4byte gVFXFnTable

	thumb_func_start VFX61_Update
VFX61_Update: @ 0x080C309C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C30C8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080C30D0
	ldr r1, _080C30CC @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl VFX61_Die
	b _080C30E0
	.align 2, 0
_080C30C8: .4byte gCurStory
_080C30CC: .4byte gVFXFnTable
_080C30D0:
	ldr r0, _080C30E4 @ =0x0836F424
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080C30E0:
	pop {r0}
	bx r0
	.align 2, 0
_080C30E4: .4byte 0x0836F424

	thumb_func_start VFX61_Die
VFX61_Die: @ 0x080C30E8
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C3104 @ =gVFXFnTable
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
_080C3104: .4byte gVFXFnTable

	thumb_func_start FUN_080c3108
FUN_080c3108: @ 0x080C3108
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3130
	ldr r1, _080C312C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C320C
	.align 2, 0
_080C312C: .4byte gVFXFnTable
_080C3130:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C313C
	cmp r5, #1
	beq _080C3178
	b _080C320C
_080C313C:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r1, _080C3198 @ =0x00006B03
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x5c]
	str r5, [r4, #0x60]
	ldr r2, _080C319C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C31A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C31A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x40
	str r0, [r4, #0x64]
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3178:
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	movs r5, #0
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x14
	bls _080C31A8
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080C31BE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C31C4
	.align 2, 0
_080C3198: .4byte 0x00006B03
_080C319C: .4byte RNG_0202f388
_080C31A0: .4byte 0x000343FD
_080C31A4: .4byte 0x00269EC3
_080C31A8:
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C31BE
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C31C4
_080C31BE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C31C4:
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x64]
	cmp r1, #0
	ble _080C31D8
	ldr r0, [r4, #0x5c]
	adds r0, #8
	str r0, [r4, #0x5c]
	cmp r0, r1
	ble _080C31E6
	b _080C31E4
_080C31D8:
	ldr r0, [r4, #0x5c]
	subs r0, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	cmp r0, r1
	bge _080C31E6
_080C31E4:
	str r1, [r4, #0x5c]
_080C31E6:
	ldr r0, [r4, #0x60]
	adds r0, #8
	str r0, [r4, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C31F6
	str r1, [r4, #0x60]
_080C31F6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C320C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c3214
FUN_080c3214: @ 0x080C3214
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3290
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C3278 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C327C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C3280 @ =0x00269EC3
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
	ldr r2, _080C3284 @ =0x00006B04
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3288 @ =0x00006B05
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C328C @ =0x00006B06
	mov r0, sp
	b _080C32FC
	.align 2, 0
_080C3278: .4byte RNG_0202f388
_080C327C: .4byte 0x000343FD
_080C3280: .4byte 0x00269EC3
_080C3284: .4byte 0x00006B04
_080C3288: .4byte 0x00006B05
_080C328C: .4byte 0x00006B06
_080C3290:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C3334
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C3334
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C3318 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C331C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C3320 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3324 @ =0x00006B04
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C3328 @ =0x00006B05
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r6, #0x10]
	ldr r2, _080C332C @ =0x00006B06
	adds r0, r5, #0
_080C32FC:
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldr r1, _080C3330 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C337C
	.align 2, 0
_080C3318: .4byte RNG_0202f388
_080C331C: .4byte 0x000343FD
_080C3320: .4byte 0x00269EC3
_080C3324: .4byte 0x00006B04
_080C3328: .4byte 0x00006B05
_080C332C: .4byte 0x00006B06
_080C3330: .4byte gVFXFnTable
_080C3334:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080C3340
	cmp r0, #1
	beq _080C3356
	b _080C337C
_080C3340:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldr r0, _080C3384 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080C3388 @ =0x00006B02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C3356:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C3366
	str r1, [r6, #0x60]
_080C3366:
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
_080C337C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C3384: .4byte 0xFFFFFF00
_080C3388: .4byte 0x00006B02

	thumb_func_start FUN_080c338c
FUN_080c338c: @ 0x080C338C
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
	beq _080C33C2
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C33E4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C33E4
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C33E4
_080C33C2:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080C33E0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C34B2
	.align 2, 0
_080C33E0: .4byte gVFXFnTable
_080C33E4:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C33F2
	cmp r0, #1
	beq _080C345C
	b _080C34B2
_080C33F2:
	ldr r4, _080C3474 @ =0x0836F490
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
	ldr r3, _080C3478 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C347C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C3480 @ =0x00269EC3
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
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C345C:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C3484
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C348A
	.align 2, 0
_080C3474: .4byte 0x0836F490
_080C3478: .4byte RNG_0202f388
_080C347C: .4byte 0x000343FD
_080C3480: .4byte 0x00269EC3
_080C3484:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C348A:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C349C
	str r1, [r7, #0x60]
_080C349C:
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
_080C34B2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
