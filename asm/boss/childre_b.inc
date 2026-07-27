	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start childreMode16
childreMode16: @ 0x08041E44
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _08041E56
	cmp r1, #1
	beq _08041EC4
	b _08041F2C
_08041E56:
	ldrb r0, [r4, #0xb]
	movs r7, #0x10
	movs r6, #0
	orrs r0, r7
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08041EAE
	ldrb r0, [r4, #0xa]
	orrs r0, r7
	b _08041EB4
_08041EAE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08041EB4:
	strb r0, [r4, #0xa]
	ldr r1, _08041ED8 @ =0x0000A409
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041EC4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08041EDC
	movs r0, #0xf6
	b _08041EDE
	.align 2, 0
_08041ED8: .4byte 0x0000A409
_08041EDC:
	movs r0, #0xfa
_08041EDE:
	muls r0, r1, r0
	cmp r0, #0
	bge _08041EE6
	adds r0, #0xff
_08041EE6:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_0801779c
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _08041F2C
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
	ldr r1, _08041F34 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08041F2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041F34: .4byte gBossFnTable

	thumb_func_start childreStun
childreStun: @ 0x08041F38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08041F48
	cmp r5, #1
	beq _08041FA4
	b _08041FFC
_08041F48:
	movs r0, #0x6d
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r1, _08041F90 @ =0x0000A41F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r1, r0, r2
	ldr r2, [r4, #0x54]
	cmp r2, r1
	ble _08041F94
	str r1, [r4, #0x54]
	b _08041F9E
	.align 2, 0
_08041F90: .4byte 0x0000A41F
_08041F94:
	ldr r3, _08042004 @ =0xFFFFA000
	adds r0, r0, r3
	cmp r2, r0
	bge _08041F9E
	str r0, [r4, #0x54]
_08041F9E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08041FA4:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08041FB4
	str r1, [r4, #0x60]
_08041FB4:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	subs r5, r0, r1
	cmp r5, #0
	bge _08041FD6
	cmp r2, #0
	ble _08041FD6
	adds r0, r1, r5
	str r0, [r4, #0x58]
_08041FD6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08041FEC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08041FFC
_08041FEC:
	cmp r5, #0
	bge _08041FFC
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08041FFC
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08041FFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042004: .4byte 0xFFFFA000

	thumb_func_start childreMode18
childreMode18: @ 0x08042008
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08042018
	cmp r0, #1
	beq _080420C0
	b _08042136
_08042018:
	movs r0, #0x6d
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldr r1, _080420DC @ =0x0000A41F
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r1, r2
	str r0, [r5, #0x58]
	adds r2, r5, #0
	adds r2, #0xc8
	ldr r0, [r5, #0x54]
	ldr r2, [r2]
	subs r0, r0, r2
	str r0, [r5, #0x5c]
	ldr r3, _080420E0 @ =0xFFFFD800
	adds r1, r1, r3
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r2, [r2]
	subs r1, r1, r2
	str r1, [r5, #0x60]
	asrs r0, r0, #8
	adds r6, r0, #0
	muls r6, r0, r6
	asrs r1, r1, #8
	adds r0, r1, #0
	muls r0, r1, r0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r1, r0, #0
	str r1, [r5, #0x60]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #7
	cmp r0, #0
	bge _080420A2
	adds r0, #0xff
_080420A2:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _080420B6
	adds r0, #0xff
_080420B6:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080420C0:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r1, r0, r1
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #7
	adds r2, r0, r3
	cmp r1, r2
	ble _080420E4
	str r2, [r5, #0x54]
	b _080420EE
	.align 2, 0
_080420DC: .4byte 0x0000A41F
_080420E0: .4byte 0xFFFFD800
_080420E4:
	ldr r2, _0804213C @ =0xFFFFA000
	adds r0, r0, r2
	cmp r1, r0
	bge _080420EE
	str r0, [r5, #0x54]
_080420EE:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080420FE
	str r1, [r5, #0x60]
_080420FE:
	ldr r0, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r0, r2
	str r1, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	subs r6, r0, r1
	cmp r6, #0
	bge _08042120
	cmp r2, #0
	ble _08042120
	adds r0, r1, r6
	str r0, [r5, #0x58]
_08042120:
	adds r0, r5, #0
	bl UpdateEntityAnim
	cmp r6, #0
	bge _08042136
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08042136
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_08042136:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804213C: .4byte 0xFFFFA000

	thumb_func_start childre_08042140
childre_08042140: @ 0x08042140
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _08042214
	lsls r0, r0, #2
	ldr r1, _08042154 @ =_08042158
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042154: .4byte _08042158
_08042158: @ jump table
	.4byte _0804216C @ case 0
	.4byte _080421C4 @ case 1
	.4byte _080421EC @ case 2
	.4byte _080421FC @ case 3
	.4byte _08042214 @ case 4
_0804216C:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r3, _080421E0 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080421B2
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080421B2
	ldr r0, _080421E4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080421B2:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _080421E8 @ =0x0000A41F
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080421C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08042214
	b _0804220E
	.align 2, 0
_080421E0: .4byte gStageRun
_080421E4: .4byte 0x0000FFFE
_080421E8: .4byte 0x0000A41F
_080421EC:
	ldr r1, _0804221C @ =sChildre_ExplosionOffsets
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080421FC:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08042214
	ldr r2, _08042220 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_0804220E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042214:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804221C: .4byte sChildre_ExplosionOffsets
_08042220: .4byte gStageRun

	thumb_func_start childre_08042224
childre_08042224: @ 0x08042224
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08042232
	b _080423CE
_08042232:
	lsls r0, r0, #2
	ldr r1, _0804223C @ =_08042240
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804223C: .4byte _08042240
_08042240: @ jump table
	.4byte _08042254 @ case 0
	.4byte _08042338 @ case 1
	.4byte _080423A6 @ case 2
	.4byte _080423B6 @ case 3
	.4byte _080423CE @ case 4
_08042254:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r6, [r0]
	ldr r0, _08042358 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080422C8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0804235C @ =gBossFnTable
	movs r0, #3
	strb r0, [r3, #9]
	ldr r0, [r1, #0xc]
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r3, #0x5c]
	str r4, [r3, #0x28]
	movs r1, #1
	strb r1, [r3, #0x10]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r1
	eors r0, r6
	strb r0, [r3, #0x13]
_080422C8:
	ldr r1, _08042360 @ =0x0000A40A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _08042364 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804230A
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804230A
	ldr r0, _08042368 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804230A:
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0804236C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042338:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08042370
	cmp r3, #1
	bne _08042374
	b _08042378
	.align 2, 0
_08042358: .4byte gBossHeaderPtr
_0804235C: .4byte gBossFnTable
_08042360: .4byte 0x0000A40A
_08042364: .4byte gStageRun
_08042368: .4byte 0x0000FFFE
_0804236C: .4byte 0xFFFFF000
_08042370:
	cmp r3, #0
	beq _08042378
_08042374:
	movs r0, #0xfa
	b _0804237A
_08042378:
	movs r0, #0xf6
_0804237A:
	muls r0, r2, r0
	cmp r0, #0
	bge _08042382
	adds r0, #0xff
_08042382:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804239E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804239E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080423CE
_080423A6:
	ldr r1, _080423D8 @ =sChildre_ExplosionOffsets+(8*1)
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080423B6:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080423CE
	ldr r2, _080423DC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080423CE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080423D8: .4byte sChildre_ExplosionOffsets+(8*1)
_080423DC: .4byte gStageRun
