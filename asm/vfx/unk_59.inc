	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c26e8
FUN_080c26e8: @ 0x080C26E8
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080C2734 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C272C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C2738 @ =gVFXFnTable
	movs r1, #0x3b
	strb r1, [r3, #9]
	adds r0, #0xec
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
_080C272C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080C2734: .4byte gVFXHeaderPtr
_080C2738: .4byte gVFXFnTable

	thumb_func_start FUN_080c273c
FUN_080c273c: @ 0x080C273C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080C27A0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2792
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080C27A4 @ =gVFXFnTable
	movs r1, #0x3b
	strb r1, [r4, #9]
	adds r0, #0xec
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
_080C2792:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C27A0: .4byte gVFXHeaderPtr
_080C27A4: .4byte gVFXFnTable

	thumb_func_start VFX59_Init
VFX59_Init: @ 0x080C27A8
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
	bne _080C27E4
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
	b _080C2804
_080C27E4:
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
_080C2804:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C2810
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080C2812
_080C2810:
	movs r0, #0xc0
_080C2812:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C283C
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C2838 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C286E
	.align 2, 0
_080C2838: .4byte gVFXFnTable
_080C283C:
	ldr r2, _080C2880 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C2884 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C2888 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080C288C @ =gVFXFnTable
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
_080C286E:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl VFX59_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C2880: .4byte RNG_0202f388
_080C2884: .4byte 0x000343FD
_080C2888: .4byte 0x00269EC3
_080C288C: .4byte gVFXFnTable

	thumb_func_start VFX59_Update
VFX59_Update: @ 0x080C2890
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C28BC @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080C28C4
	ldr r1, _080C28C0 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl VFX59_Die
	b _080C28D4
	.align 2, 0
_080C28BC: .4byte gCurStory
_080C28C0: .4byte gVFXFnTable
_080C28C4:
	ldr r0, _080C28D8 @ =0x0836F310
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080C28D4:
	pop {r0}
	bx r0
	.align 2, 0
_080C28D8: .4byte 0x0836F310

	thumb_func_start VFX59_Die
VFX59_Die: @ 0x080C28DC
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C28F8 @ =gVFXFnTable
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
_080C28F8: .4byte gVFXFnTable

	thumb_func_start nop_080c28fc
nop_080c28fc: @ 0x080C28FC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c2900
FUN_080c2900: @ 0x080C2900
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C297C
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C2964 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C2968 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C296C @ =0x00269EC3
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
	ldr r2, _080C2970 @ =0x00006908
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r6, #0x10]
	ldr r2, _080C2974 @ =0x00006909
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r6, #0x10]
	ldr r2, _080C2978 @ =0x0000690A
	mov r0, sp
	b _080C29E8
	.align 2, 0
_080C2964: .4byte RNG_0202f388
_080C2968: .4byte 0x000343FD
_080C296C: .4byte 0x00269EC3
_080C2970: .4byte 0x00006908
_080C2974: .4byte 0x00006909
_080C2978: .4byte 0x0000690A
_080C297C:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C2A20
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C2A20
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C2A04 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C2A08 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C2A0C @ =0x00269EC3
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
	ldr r2, _080C2A10 @ =0x00006908
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r6, #0x10]
	ldr r2, _080C2A14 @ =0x00006909
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c273c
	ldrb r1, [r6, #0x10]
	ldr r2, _080C2A18 @ =0x0000690A
	adds r0, r5, #0
_080C29E8:
	adds r3, r4, #0
	bl FUN_080c273c
	ldr r1, _080C2A1C @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C2A68
	.align 2, 0
_080C2A04: .4byte RNG_0202f388
_080C2A08: .4byte 0x000343FD
_080C2A0C: .4byte 0x00269EC3
_080C2A10: .4byte 0x00006908
_080C2A14: .4byte 0x00006909
_080C2A18: .4byte 0x0000690A
_080C2A1C: .4byte gVFXFnTable
_080C2A20:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080C2A2C
	cmp r0, #1
	beq _080C2A42
	b _080C2A68
_080C2A2C:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldr r0, _080C2A70 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080C2A74 @ =0x00006907
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C2A42:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C2A52
	str r1, [r6, #0x60]
_080C2A52:
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
_080C2A68:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C2A70: .4byte 0xFFFFFF00
_080C2A74: .4byte 0x00006907

	thumb_func_start FUN_080c2a78
FUN_080c2a78: @ 0x080C2A78
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
	beq _080C2AAE
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C2AD0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C2AD0
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C2AD0
_080C2AAE:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080C2ACC @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C2B9E
	.align 2, 0
_080C2ACC: .4byte gVFXFnTable
_080C2AD0:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C2ADE
	cmp r0, #1
	beq _080C2B48
	b _080C2B9E
_080C2ADE:
	ldr r4, _080C2B60 @ =0x0836F37C
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
	ldr r3, _080C2B64 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C2B68 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C2B6C @ =0x00269EC3
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
_080C2B48:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C2B70
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C2B76
	.align 2, 0
_080C2B60: .4byte 0x0836F37C
_080C2B64: .4byte RNG_0202f388
_080C2B68: .4byte 0x000343FD
_080C2B6C: .4byte 0x00269EC3
_080C2B70:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2B76:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C2B88
	str r1, [r7, #0x60]
_080C2B88:
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
_080C2B9E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
