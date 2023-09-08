	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c4fc8
FUN_080c4fc8: @ 0x080C4FC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C5010 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C5006
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C5014 @ =gVFXFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080C5006:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C5010: .4byte gVFXHeaderPtr
_080C5014: .4byte gVFXFnTable

	thumb_func_start FUN_080c5018
FUN_080c5018: @ 0x080C5018
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, _080C5070 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C5066
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C5074 @ =gVFXFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0x80
	strh r6, [r0]
_080C5066:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C5070: .4byte gVFXHeaderPtr
_080C5074: .4byte gVFXFnTable

	thumb_func_start FUN_080c5078
FUN_080c5078: @ 0x080C5078
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r0, _080C50D8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C50CE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C50DC @ =gVFXFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0x82
	strh r6, [r0]
	subs r0, #2
	strh r7, [r0]
_080C50CE:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C50D8: .4byte gVFXHeaderPtr
_080C50DC: .4byte gVFXFnTable

	thumb_func_start Ghost69_Init
Ghost69_Init: @ 0x080C50E0
	push {lr}
	ldr r2, _080C5108 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldrb r1, [r0, #0x10]
	movs r2, #0
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	strb r2, [r0, #0xf]
	bl Ghost69_Update
	pop {r0}
	bx r0
	.align 2, 0
_080C5108: .4byte gVFXFnTable

	thumb_func_start Ghost69_Update
Ghost69_Update: @ 0x080C510C
	push {lr}
	ldr r2, _080C5120 @ =0x0836F6F4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C5120: .4byte sGhost69Updates

	thumb_func_start Ghost69_Die
Ghost69_Die: @ 0x080C5124
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C5140 @ =gVFXFnTable
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
_080C5140: .4byte gVFXFnTable

	thumb_func_start FUN_080c5144
FUN_080c5144: @ 0x080C5144
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080C5168
	ldr r1, _080C5164 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080C5216
	.align 2, 0
_080C5164: .4byte gVFXFnTable
_080C5168:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C5174
	cmp r5, #1
	beq _080C51AE
	b _080C5216
_080C5174:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x74]
	str r5, [r4, #0x78]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x13]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C51AE:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C5208
	ldrb r0, [r2, #0xd]
	cmp r0, #5
	beq _080C5208
	cmp r0, #6
	bne _080C51DC
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _080C5208
_080C51DC:
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C51F0
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	b _080C5208
_080C51F0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C5200
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C5208
_080C5200:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080C520E
_080C5208:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C520E:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C5216:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c521c
FUN_080c521c: @ 0x080C521C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080C5240
	ldr r1, _080C523C @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080C5318
	.align 2, 0
_080C523C: .4byte gVFXFnTable
_080C5240:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080C524C
	cmp r0, #1
	beq _080C52AA
	b _080C5318
_080C524C:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	subs r0, #0x2e
	strb r1, [r0]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080C5320 @ =0x0000B801
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r5, #0x12]
	str r4, [r5, #0x5c]
	ldr r2, [r5, #0x28]
	ldr r1, [r5, #0x64]
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x68]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C52AA:
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r6, r0, r2
	ldr r0, [r1, #0x58]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r7, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r6, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r1, [r5, #0x58]
	subs r0, r7, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r1, [r5, #0x5c]
	movs r0, #0x20
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080C5300
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C5312
_080C5300:
	ldr r1, _080C5324 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080C5312:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080C5318:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5320: .4byte 0x0000B801
_080C5324: .4byte gVFXFnTable

	thumb_func_start FUN_080c5328
FUN_080c5328: @ 0x080C5328
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _080C5396
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080C5340
	cmp r5, #1
	beq _080C536E
	b _080C53A8
_080C5340:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x74]
	str r5, [r4, #0x78]
	ldr r1, _080C53B0 @ =0x0000B903
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C536E:
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x78]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C5396
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C53A8
_080C5396:
	ldr r1, _080C53B4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C53A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C53B0: .4byte 0x0000B903
_080C53B4: .4byte gVFXFnTable

	thumb_func_start FUN_080c53b8
FUN_080c53b8: @ 0x080C53B8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080C53DC
	ldr r1, _080C53D8 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080C5516
	.align 2, 0
_080C53D8: .4byte gVFXFnTable
_080C53DC:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080C53E8
	cmp r0, #1
	beq _080C5454
	b _080C5516
_080C53E8:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	subs r0, #0x2e
	strb r1, [r0]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080C551C @ =0x0000B801
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r5, #0x12]
	str r4, [r5, #0x5c]
	ldr r1, _080C5520 @ =0xFFFFCA00
	str r1, [r5, #0x68]
	ldr r2, [r5, #0x28]
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x74]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x78]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r1, [r5, #0x11]
	movs r0, #0x2a
	muls r0, r1, r0
	movs r1, #0xff
	ands r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C5454:
	ldr r1, [r5, #0x68]
	movs r0, #0xe0
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x68]
	ldr r2, [r5, #0x28]
	mov ip, r2
	ldr r0, [r2, #0x54]
	adds r1, r1, r0
	str r1, [r5, #0x64]
	ldr r2, [r5, #0x78]
	rsbs r1, r2, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x78]
	ldr r1, [r5, #0x60]
	adds r0, r1, #0
	adds r0, #0xa
	str r0, [r5, #0x60]
	cmp r0, #0xff
	ble _080C548E
	subs r0, #0xff
	str r0, [r5, #0x60]
_080C548E:
	ldr r2, [r5, #0x78]
	adds r7, r2, #0
	ldr r3, _080C5524 @ =gSineTable
	ldr r1, [r5, #0x60]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r6, r0, #0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r2, r1
	asrs r7, r1, #8
	lsls r0, r0, #3
	subs r0, r0, r6
	lsls r0, r0, #4
	asrs r6, r0, #8
	ldr r0, [r5, #0x64]
	adds r0, r0, r6
	str r0, [r5, #0x54]
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r1, r7, r4
	mov r2, ip
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x5c]
	movs r0, #0x20
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldr r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080C54FE
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C5510
_080C54FE:
	ldr r1, _080C5528 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080C5510:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080C5516:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C551C: .4byte 0x0000B801
_080C5520: .4byte 0xFFFFCA00
_080C5524: .4byte gSineTable
_080C5528: .4byte gVFXFnTable

	thumb_func_start nop_080c552c
nop_080c552c: @ 0x080C552C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c5530
FUN_080c5530: @ 0x080C5530
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C5540
	cmp r0, #1
	beq _080C5574
	b _080C55AA
_080C5540:
	ldr r2, _080C55B0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C55B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C55B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C5574:
	ldr r2, [r4, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C5594
	str r1, [r4, #0x60]
_080C5594:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080C55AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C55B0: .4byte RNG_0202f388
_080C55B4: .4byte 0x000343FD
_080C55B8: .4byte 0x00269EC3

	thumb_func_start FUN_080c55bc
FUN_080c55bc: @ 0x080C55BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C55CC
	cmp r0, #1
	beq _080C55D6
	b _080C561E
_080C55CC:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C55D6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C55EC
	str r1, [r4, #0x60]
_080C55EC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C560C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C561E
_080C560C:
	ldr r1, _080C5624 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C561E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C5624: .4byte gVFXFnTable
