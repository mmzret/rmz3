	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Leviathan_Update
Leviathan_Update: @ 0x08035F74
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _08035FA2
	ldr r1, _08035FD4 @ =0x0835EC00
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08035FD8 @ =0x0835EC0C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08035FA2:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2]
	ldr r3, _08035FDC @ =0xFFFF9400
	adds r1, r0, r3
	ldr r0, [r4, #0x54]
	cmp r0, r1
	bgt _08035FBA
	str r1, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_08035FBA:
	ldr r0, [r2]
	movs r2, #0xd8
	lsls r2, r2, #7
	adds r1, r0, r2
	ldr r0, [r4, #0x54]
	cmp r0, r1
	blt _08035FCE
	str r1, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_08035FCE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035FD4: .4byte 0x0835EC00
_08035FD8: .4byte 0x0835EC0C
_08035FDC: .4byte 0xFFFF9400

	thumb_func_start Leviathan_Die
Leviathan_Die: @ 0x08035FE0
	ldr r2, _08035FF4 @ =gZeroFnTable
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
_08035FF4: .4byte gZeroFnTable

	thumb_func_start leviathanMode0Pre
leviathanMode0Pre: @ 0x08035FF8
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrh r1, [r3, #0x10]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _08036010
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08036010:
	ldrh r1, [r3, #0x12]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036022
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08036022:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start leviathanMode1Pre
leviathanMode1Pre: @ 0x08036028
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrh r1, [r0, #0x12]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036040
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08036040:
	pop {r0}
	bx r0

	thumb_func_start nop_08036044
nop_08036044: @ 0x08036044
	bx lr
	.align 2, 0

	thumb_func_start leviathanMode0
leviathanMode0: @ 0x08036048
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08036058
	cmp r5, #1
	beq _08036076
	b _080360C2
_08036058:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080360C8 @ =0x0835EC18
	bl SetDDP
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x64]
	strb r5, [r4, #0x12]
	ldr r1, _080360CC @ =0x0000BD04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08036076:
	adds r0, r4, #0
	bl FUN_08035e6c
	ldr r2, [r4, #0x64]
	str r2, [r4, #0x58]
	ldr r1, _080360D0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _08036098
	adds r0, #0xff
_08036098:
	asrs r0, r0, #8
	adds r0, r2, r0
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl FUN_08035e48
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080360B4
	movs r0, #0
	str r0, [r4, #0x5c]
_080360B4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080360C2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080360C8: .4byte 0x0835EC18
_080360CC: .4byte 0x0000BD04
_080360D0: .4byte gSineTable

	thumb_func_start leviathanMode1
leviathanMode1: @ 0x080360D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0803610C
	cmp r0, #1
	bgt _080360EA
	cmp r0, #0
	beq _080360F4
	b _080361F6
_080360EA:
	cmp r0, #2
	beq _080361B6
	cmp r0, #3
	beq _080361C4
	b _080361F6
_080360F4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08036150 @ =0x0835EC18
	bl SetDDP
	ldr r1, _08036154 @ =0x0000BD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803610C:
	adds r0, r4, #0
	bl FUN_08035e6c
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x58]
	movs r5, #0
	ldrh r1, [r6, #0x10]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803615C
	ldr r0, [r4, #0x5c]
	subs r0, #0x10
	str r0, [r4, #0x5c]
	ldr r1, _08036158 @ =0xFFFFFD00
	cmp r0, r1
	bge _08036130
	str r1, [r4, #0x5c]
_08036130:
	movs r5, #1
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0803618E
	.align 2, 0
_08036150: .4byte 0x0835EC18
_08036154: .4byte 0x0000BD02
_08036158: .4byte 0xFFFFFD00
_0803615C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803618E
	ldr r0, [r4, #0x5c]
	adds r0, #0x10
	str r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08036174
	str r1, [r4, #0x5c]
_08036174:
	movs r5, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
_0803618E:
	adds r0, r4, #0
	bl FUN_08035e48
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080361A6
	cmp r5, #0
	bne _080361A6
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080361A6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080361F6
_080361B6:
	ldr r1, _080361E4 @ =0x0000BD01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080361C4:
	adds r0, r4, #0
	bl FUN_08035e6c
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrh r0, [r6, #0x10]
	movs r1, #0x30
	ands r1, r0
	cmp r1, #0
	beq _080361E8
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080361F6
	.align 2, 0
_080361E4: .4byte 0x0000BD01
_080361E8:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080361F6
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
_080361F6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start leviathanMode2
leviathanMode2: @ 0x080361FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08036230
	cmp r0, #1
	bgt _08036212
	cmp r0, #0
	beq _0803621C
	b _080362FE
_08036212:
	cmp r0, #2
	beq _08036250
	cmp r0, #3
	beq _08036274
	b _080362FE
_0803621C:
	adds r1, r6, #0
	adds r1, #0x35
	strb r0, [r1]
	ldr r1, _0803624C @ =0x0000BD17
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08036230:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _080362FE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080362FE
	.align 2, 0
_0803624C: .4byte 0x0000BD17
_08036250:
	movs r0, #0xf7
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080362CC @ =0x0835EC30
	bl SetDDP
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	ldr r1, _080362D0 @ =0x0000BD19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08036274:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803628C
	ldr r0, [r4, #0x5c]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
_0803628C:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0803629C
	str r1, [r4, #0x60]
_0803629C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0x8c
	lsls r2, r2, #6
	adds r1, r1, r2
	bl PushoutToUp2
	adds r2, r0, #0
	ldrh r1, [r6, #0x10]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080362D4
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x64]
	strb r1, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08036350
	.align 2, 0
_080362CC: .4byte 0x0835EC30
_080362D0: .4byte 0x0000BD19
_080362D4:
	cmp r2, #0
	bge _080362F8
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	bge _080362E6
	adds r0, #0xff
_080362E6:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r0, [r4, #0x64]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080362F8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080362FE:
	movs r5, #0
	ldrh r1, [r6, #0x10]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803631C
	ldr r0, [r4, #0x5c]
	subs r0, #0x10
	str r0, [r4, #0x5c]
	ldr r1, _08036318 @ =0xFFFFFD00
	cmp r0, r1
	bge _08036334
	b _08036332
	.align 2, 0
_08036318: .4byte 0xFFFFFD00
_0803631C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08036336
	ldr r0, [r4, #0x5c]
	adds r0, #0x10
	str r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08036334
_08036332:
	str r1, [r4, #0x5c]
_08036334:
	movs r5, #1
_08036336:
	adds r0, r4, #0
	bl FUN_08035e48
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08036348
	cmp r5, #0
	bne _08036348
	str r5, [r4, #0x5c]
_08036348:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08036350:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
