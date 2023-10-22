	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080935b4
FUN_080935b4: @ 0x080935B4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _08093620 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08093618
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093624 @ =gEnemyFnTable
	movs r1, #0x3d
	strb r1, [r4, #9]
	adds r0, #0xf4
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
	strb r2, [r4, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	lsls r1, r6, #0xc
	subs r0, r0, r1
	ldr r1, _08093628 @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [r4, #0x58]
	strb r7, [r4, #0x12]
	str r5, [r4, #0x28]
_08093618:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093620: .4byte gZakoHeaderPtr
_08093624: .4byte gEnemyFnTable
_08093628: .4byte 0xFFFFE400

	thumb_func_start nop_0809362c
nop_0809362c: @ 0x0809362C
	bx lr
	.align 2, 0

	thumb_func_start Enemy61_Init
Enemy61_Init: @ 0x08093630
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080936A0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080936A4 @ =0x08369E00
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080936A8 @ =0x08369D40
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080936AC @ =nop_0809362c
	str r0, [r5, #0x24]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	str r0, [r2]
	adds r0, r4, #0
	bl Enemy61_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080936A0: .4byte gEnemyFnTable
_080936A4: .4byte 0x08369E00
_080936A8: .4byte 0x08369D40
_080936AC: .4byte nop_0809362c

	thumb_func_start Enemy61_Update
Enemy61_Update: @ 0x080936B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080936D4
	ldr r1, _080936D0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080936F4
	.align 2, 0
_080936D0: .4byte gEnemyFnTable
_080936D4:
	ldr r1, _080936FC @ =0x08369D38
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093700 @ =0x08369D3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080936F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080936FC: .4byte 0x08369D38
_08093700: .4byte 0x08369D3C

	thumb_func_start Enemy61_Die
Enemy61_Die: @ 0x08093704
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	beq _08093716
	cmp r1, #1
	beq _08093732
	b _0809374A
_08093716:
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08093732:
	ldrb r0, [r3, #0xc]
	cmp r0, #2
	bls _0809374A
	ldr r1, _08093750 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
_0809374A:
	pop {r0}
	bx r0
	.align 2, 0
_08093750: .4byte gEnemyFnTable

	thumb_func_start FUN_08093754
FUN_08093754: @ 0x08093754
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093758
FUN_08093758: @ 0x08093758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08093770
	cmp r0, #1
	beq _0809377C
	b _08093926
_08093770:
	str r0, [r6, #0x5c]
	str r0, [r6, #0x64]
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809377C:
	ldr r3, [r6, #0x68]
	cmp r3, #0
	bne _080937AC
	adds r2, r6, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080937A8 @ =0x000021BF
	adds r4, r2, #0
	cmp r0, r1
	ble _080937B4
	str r3, [r6, #0x64]
	movs r0, #0x3c
	str r0, [r6, #0x68]
	b _080937B4
	.align 2, 0
_080937A8: .4byte 0x000021BF
_080937AC:
	subs r0, r3, #1
	str r0, [r6, #0x68]
	adds r4, r6, #0
	adds r4, #0xb4
_080937B4:
	ldr r0, [r4]
	ldr r5, _08093808 @ =0x0000CA80
	adds r1, r5, #0
	bl __umodsi3
	str r0, [r4]
	movs r4, #0x87
	lsls r4, r4, #4
	adds r7, r0, r4
	adds r0, r7, #0
	adds r1, r5, #0
	bl __umodsi3
	adds r7, r0, #0
	adds r1, r4, #0
	bl __udivsi3
	adds r7, r0, #0
	movs r0, #0x17
	subs r7, r0, r7
	ldrb r0, [r6, #0x12]
	mov r1, r8
	adds r1, #0xb4
	adds r2, r1, r0
	ldrb r4, [r2]
	adds r3, r1, #0
	cmp r4, #0
	beq _0809381A
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093810
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0809380C
	movs r0, #0
	b _0809380E
	.align 2, 0
_08093808: .4byte 0x0000CA80
_0809380C:
	subs r0, r4, #1
_0809380E:
	strb r0, [r2]
_08093810:
	ldrb r0, [r6, #0x12]
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809381E
_0809381A:
	movs r4, #2
	b _08093826
_0809381E:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	movs r1, #1
	subs r4, r1, r0
_08093826:
	subs r0, r7, #4
	cmp r0, #3
	bhi _08093858
	ldrb r0, [r6, #0x12]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08093848
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093844 @ =0x08369DB8
	bl SetDDP
	b _08093896
	.align 2, 0
_08093844: .4byte 0x08369DB8
_08093848:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093854 @ =0x08369D58
	bl SetDDP
	b _08093896
	.align 2, 0
_08093854: .4byte 0x08369D58
_08093858:
	adds r0, r7, #0
	subs r0, #0x11
	cmp r0, #3
	bhi _0809388C
	ldrb r0, [r6, #0x12]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809387C
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093878 @ =0x08369DD0
	bl SetDDP
	b _08093896
	.align 2, 0
_08093878: .4byte 0x08369DD0
_0809387C:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093888 @ =0x08369D88
	bl SetDDP
	b _08093896
	.align 2, 0
_08093888: .4byte 0x08369D88
_0809388C:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080938B8 @ =0x08369D40
	bl SetDDP
_08093896:
	adds r0, r7, #0
	subs r0, #0xb
	cmp r0, #2
	bhi _080938A2
	cmp r4, #2
	bne _080938AE
_080938A2:
	adds r0, r7, #0
	subs r0, #0xa
	cmp r0, #4
	bhi _080938BC
	cmp r4, #2
	bne _080938BC
_080938AE:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08093904
	.align 2, 0
_080938B8: .4byte 0x08369D40
_080938BC:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	cmp r4, #2
	bne _080938D0
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	b _080938D6
_080938D0:
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #0
_080938D6:
	strb r0, [r1]
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	movs r2, #0x8b
	lsls r2, r2, #8
	adds r0, r7, r2
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _08093918 @ =0x08369DE8
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r0, #0x18
	adds r1, r6, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08093904:
	ldr r0, [r6, #0x5c]
	cmp r0, r4
	beq _08093926
	str r4, [r6, #0x5c]
	cmp r4, #1
	bne _0809391C
	movs r0, #0x91
	bl PlaySound
	b _08093926
	.align 2, 0
_08093918: .4byte 0x08369DE8
_0809391C:
	cmp r4, #2
	bne _08093926
	movs r0, #0x93
	bl PlaySound
_08093926:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
