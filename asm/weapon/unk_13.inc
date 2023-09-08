	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Weapon13_Init
Weapon13_Init: @ 0x0803C558
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0803C5A0 @ =0x083616D8
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0803C5A4
	movs r0, #0x10
	orrs r1, r0
	b _0803C5A8
	.align 2, 0
_0803C5A0: .4byte 0x083616D8
_0803C5A4:
	movs r0, #0xef
	ands r1, r0
_0803C5A8:
	strb r1, [r5, #0xa]
	adds r1, r2, #0
	adds r4, r5, #0
	adds r4, #0x4c
	strb r1, [r4]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0x10]
	mov ip, r4
	adds r4, r3, #0
	cmp r0, #0
	beq _0803C5D2
	cmp r0, #3
	bne _0803C5FC
_0803C5D2:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0803C5F0
	ldr r0, _0803C5EC @ =0x083616D4
	ldrb r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r1, [r5, #0x10]
	b _0803C606
	.align 2, 0
_0803C5EC: .4byte 0x083616D4
_0803C5F0:
	ldr r0, _0803C5F8 @ =0x083616D4
	ldrb r3, [r0]
	ldrb r1, [r5, #0x10]
	b _0803C606
	.align 2, 0
_0803C5F8: .4byte 0x083616D4
_0803C5FC:
	ldr r0, _0803C620 @ =0x083616D4
	ldrb r1, [r5, #0x10]
	adds r0, r1, r0
	ldrb r3, [r0]
	ldrb r2, [r6, #0xa]
_0803C606:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0803C628
	ldr r0, _0803C624 @ =0x083616CC
	adds r0, r1, r0
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	b _0803C636
	.align 2, 0
_0803C620: .4byte 0x083616D4
_0803C624: .4byte 0x083616CC
_0803C628:
	ldr r0, _0803C680 @ =0x083616CC
	adds r0, r1, r0
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
_0803C636:
	str r0, [r5, #0x54]
	ldr r1, _0803C684 @ =0x083616D0
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, _0803C688 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r2, r0, #2
	str r2, [r5, #0x5c]
	ldrb r0, [r5, #0x10]
	adds r7, r1, #0
	cmp r0, #3
	bne _0803C6A8
	rsbs r0, r2, #0
	str r0, [r5, #0x5c]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _0803C68C
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803C692
	.align 2, 0
_0803C680: .4byte 0x083616CC
_0803C684: .4byte 0x083616D0
_0803C688: .4byte gSineTable
_0803C68C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803C692:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #4
	ldrb r2, [r4]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4]
_0803C6A8:
	lsls r0, r3, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r4, [r0, r2]
	lsls r4, r4, #2
	str r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x64]
	adds r0, r4, #0
	movs r1, #0x1a
	bl __divsi3
	str r0, [r5, #0x68]
	ldr r1, _0803C6E8 @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Weapon13_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C6E8: .4byte gWeaponFnTable

	thumb_func_start Weapon13_Update
Weapon13_Update: @ 0x0803C6EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _0803C738 @ =0x00000137
	adds r1, r0, r2
	ldrb r0, [r4, #0x11]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0803C740
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
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0803C73C @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0803C784
	.align 2, 0
_0803C738: .4byte 0x00000137
_0803C73C: .4byte gWeaponFnTable
_0803C740:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x64]
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x68]
	subs r1, r1, r0
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803C784
	ldr r1, _0803C78C @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Weapon13_Die
_0803C784:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C78C: .4byte gWeaponFnTable

	thumb_func_start Weapon13_Die
Weapon13_Die: @ 0x0803C790
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803C7AC @ =gWeaponFnTable
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
_0803C7AC: .4byte gWeaponFnTable
