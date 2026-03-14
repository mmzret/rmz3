	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809e7c0
FUN_0809e7c0: @ 0x0809E7C0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809E824
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809E818
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809E810 @ =0xFFFFF800
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
	ldr r1, _0809E814 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809E82A
	.align 2, 0
_0809E810: .4byte 0xFFFFF800
_0809E814: .4byte 0xFFFFFC00
_0809E818:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E848
_0809E824:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809E82A:
	bl CreateSmoke
	ldr r1, _0809E844 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809E9AE
	.align 2, 0
_0809E844: .4byte gProjectileFnTable
_0809E848:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809E854
	cmp r0, #1
	beq _0809E8C8
	b _0809E9AE
_0809E854:
	ldr r1, _0809E890 @ =0x0000A304
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
	bne _0809E894
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
	b _0809E8B8
	.align 2, 0
_0809E890: .4byte 0x0000A304
_0809E894:
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
_0809E8B8:
	strb r0, [r2]
	ldr r0, _0809E948 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809E8C8:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809E8E2
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809E8E2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809E94C @ =0x0836AD78
	bl SetDDP
_0809E8E2:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809E8F2
	str r1, [r4, #0x60]
_0809E8F2:
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
	beq _0809E916
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809E950 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809E916:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809E954
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E948: .4byte 0xFFFFFC00
_0809E94C: .4byte 0x0836AD78
_0809E950: .4byte 0xFFFFFD00
_0809E954:
	ldr r0, [r4, #0x54]
	ldr r1, _0809E980 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809E9A8
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809E984
	movs r0, #0x10
	orrs r0, r2
	b _0809E988
	.align 2, 0
_0809E980: .4byte 0xFFFFF800
_0809E984:
	movs r0, #0xef
	ands r0, r2
_0809E988:
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
_0809E9A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809E9AE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e9b8
FUN_0809e9b8:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73
	.byte 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809e9c4
FUN_0809e9c4: @ 0x0809E9C4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809E9D4
	cmp r0, #1
	beq _0809EA2A
	b _0809EACA
_0809E9D4:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r2, r5, #0
	adds r2, #0xbc
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r2]
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r2]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, _0809EAD0 @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0xa
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EA2A:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r0, r2, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r3, #4
	ldr r2, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	adds r0, r5, #0
	adds r0, #0x50
	strh r2, [r0]
	ldr r0, [r3]
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r3]
	movs r0, #0xd0
	lsls r0, r0, #1
	cmp r1, r0
	ble _0809EA92
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0809EA92
	adds r0, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809EAD4 @ =0x0836AE38
	bl SetDDP
_0809EA92:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EAB8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EACA
_0809EAB8:
	ldr r1, _0809EAD8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EACA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EAD0: .4byte 0x0000A301
_0809EAD4: .4byte 0x0836AE38
_0809EAD8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809eadc
FUN_0809eadc:
	.byte 0x00, 0x22, 0x01, 0x21
	.byte 0x41, 0x73, 0x82, 0x73, 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809eae8
FUN_0809eae8: @ 0x0809EAE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809EB3E
	cmp r0, #1
	bgt _0809EAFC
	cmp r0, #0
	beq _0809EB06
	b _0809EC04
_0809EAFC:
	cmp r0, #2
	beq _0809EBC6
	cmp r0, #3
	beq _0809EBE2
	b _0809EC04
_0809EB06:
	ldr r1, _0809EB74 @ =0x0000A302
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x64]
	movs r1, #0x36
	strb r1, [r4, #0x12]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0809EB78 @ =0x00016C80
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x36
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x35
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EB3E:
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0809EB6A
	subs r0, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809EB7C
_0809EB6A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809EC04
	.align 2, 0
_0809EB74: .4byte 0x0000A302
_0809EB78: .4byte 0x00016C80
_0809EB7C:
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EBA0
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809EBF2
_0809EBA0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EC04
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EC04
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	b _0809EBF2
_0809EBC6:
	ldr r1, _0809EC0C @ =0x0000A303
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809EC10 @ =0x0836ADD8
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809EBE2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809EC04
_0809EBF2:
	ldr r1, _0809EC14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809EC04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809EC0C: .4byte 0x0000A303
_0809EC10: .4byte 0x0836ADD8
_0809EC14: .4byte gProjectileFnTable

	thumb_func_start FUN_0809ec18
FUN_0809ec18:
	.byte 0x00, 0x22, 0x01, 0x21, 0x41, 0x73, 0x82, 0x73
	.byte 0x70, 0x47
	.align 2, 0

	thumb_func_start FUN_0809ec24
FUN_0809ec24: @ 0x0809EC24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EC8A
	cmp r0, #1
	bgt _0809EC38
	cmp r0, #0
	beq _0809EC3E
	b _0809EDF0
_0809EC38:
	cmp r0, #2
	beq _0809ED36
	b _0809EDF0
_0809EC3E:
	adds r0, r5, #0
	bl InitRotatableMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	adds r0, r5, #0
	adds r0, #0x50
	movs r4, #0x80
	lsls r4, r4, #1
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #0x62
	ldrb r1, [r0]
	subs r0, #0x90
	strb r1, [r0]
	ldr r1, _0809ECEC @ =0x0000A301
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	str r4, [r2]
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EC8A:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809EC9C
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ECCE
_0809EC9C:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	rsbs r1, r2, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ECCE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809ECE0
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809ECF0
_0809ECE0:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809ED2E
	.align 2, 0
_0809ECEC: .4byte 0x0000A301
_0809ECF0:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809ED14
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809ED14:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809ED2E
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809EDD4
_0809ED2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0809EDF0
_0809ED36:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	ble _0809ED48
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bgt _0809ED7E
_0809ED48:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r2, [r3]
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r5, #0x5c]
	muls r2, r0, r2
	asrs r2, r2, #8
	str r2, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r3]
	muls r1, r0, r1
	asrs r1, r1, #8
	str r1, [r5, #0x68]
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0809ED7E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809EDDE
	subs r0, #1
	movs r3, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809EDDE
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809EDBA
	str r3, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0809EDDE
_0809EDBA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809EDF0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809EDF0
_0809EDD4:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
_0809EDDE:
	ldr r1, _0809EDF8 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809EDF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809EDF8: .4byte gProjectileFnTable

	thumb_func_start FUN_0809edfc
FUN_0809edfc: @ 0x0809EDFC
	movs r2, #0
	movs r1, #1
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ee08
FUN_0809ee08: @ 0x0809EE08
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809EE22
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	b _0809EFEE
_0809EE22:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0809EE6E
	cmp r0, #1
	bgt _0809EE32
	cmp r0, #0
	beq _0809EE40
	b _0809F000
_0809EE32:
	cmp r0, #2
	bne _0809EE38
	b _0809EF4E
_0809EE38:
	cmp r0, #3
	bne _0809EE3E
	b _0809EFC4
_0809EE3E:
	b _0809F000
_0809EE40:
	ldr r1, _0809EEE0 @ =0x0000A305
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xa0
	lsls r1, r1, #3
	str r1, [r2]
	ldr r0, [r5, #0x5c]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r2]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	movs r0, #4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EE6E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r6, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r1, r4
	bl PushoutToUp1
	str r0, [sp]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0809EEE4 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToDown1
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	str r0, [sp, #8]
	ldr r0, [r5, #0x54]
	ldr r3, _0809EEE4 @ =0xFFFFF800
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r2, r0, #0
	str r2, [sp, #0xc]
	ldr r1, [sp]
	cmp r1, #0
	beq _0809EEEE
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EEE8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
	.align 2, 0
_0809EEE0: .4byte 0x0000A305
_0809EEE4: .4byte 0xFFFFF800
_0809EEE8:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EEEE:
	ldr r1, [sp, #4]
	cmp r1, #0
	beq _0809EF12
	ldr r0, [r5, #0x68]
	rsbs r0, r0, #0
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF0C
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF0C:
	cmp r2, #0
	beq _0809EF2E
	b _0809EF22
_0809EF12:
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0809EF1E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0809EF26
_0809EF1E:
	cmp r2, #0
	beq _0809EF30
_0809EF22:
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
_0809EF26:
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x64]
	rsbs r0, r0, #0
	str r0, [r5, #0x64]
_0809EF2E:
	movs r6, #1
_0809EF30:
	cmp r6, #1
	bne _0809F000
	movs r0, #0
	bl PlaySound
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809F000
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809F000
_0809EF4E:
	adds r6, r5, #0
	adds r6, #0xb8
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6]
	ldr r1, [r5, #0x28]
	ldr r2, [r1, #0x54]
	ldr r0, [r5, #0x54]
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x60]
	asrs r2, r2, #2
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809EFA4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x60]
_0809EFA4:
	ldr r1, [r5, #0x5c]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x60]
	ldr r0, [r6]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [r5, #0x68]
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809EFC4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r2, r5, #0
	adds r2, #0xbc
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	cmp r0, #0
	bgt _0809F000
_0809EFEE:
	ldr r1, _0809F008 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809F000:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F008: .4byte gProjectileFnTable

