	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid18_Update
Solid18_Update: @ 0x080CF74C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080CF7BC @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	adds r4, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl IsVoidSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CF772
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r4, r0
	bgt _080CF77A
_080CF772:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r4, r0
	ble _080CF7C4
_080CF77A:
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r2, #0
	strb r0, [r5, #0xb]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080CF7C0 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080CF874
	.align 2, 0
_080CF7BC: .4byte gStageRun+232
_080CF7C0: .4byte gSolidFnTable
_080CF7C4:
	ldr r0, _080CF7E8 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r5, #0x58]
	ldr r2, _080CF7EC @ =0xFFFFFF00
	adds r0, r0, r2
	ldr r1, [r1, #0x58]
	cmp r1, r0
	bge _080CF7F8
	ldrb r1, [r5, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080CF7F0 @ =0x083706C8
	str r0, [r5, #0x30]
	ldr r0, _080CF7F4 @ =0x00008801
	strh r0, [r5, #0x26]
	b _080CF800
	.align 2, 0
_080CF7E8: .4byte pZero2
_080CF7EC: .4byte 0xFFFFFF00
_080CF7F0: .4byte 0x083706C8
_080CF7F4: .4byte 0x00008801
_080CF7F8:
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
_080CF800:
	adds r4, r5, #0
	adds r4, #0xb6
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xf
	bl __modsi3
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CF854
	ldr r0, _080CF840 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080CF844 @ =0x00003FFF
	cmp r0, r1
	bhi _080CF854
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _080CF836
	cmp r0, #4
	bne _080CF84C
_080CF836:
	ldr r0, _080CF848 @ =0x00000127
	bl PlaySound
	b _080CF854
	.align 2, 0
_080CF840: .4byte gStageRun+232
_080CF844: .4byte 0x00003FFF
_080CF848: .4byte 0x00000127
_080CF84C:
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound
_080CF854:
	ldr r1, _080CF87C @ =0x0837066C
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _080CF880 @ =0x08370680
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_080CF874:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF87C: .4byte 0x0837066C
_080CF880: .4byte 0x08370680

	thumb_func_start Solid18_Die
Solid18_Die: @ 0x080CF884
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xb]
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
	ldr r0, [r4, #0x54]
	ldr r1, _080CF904 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080CF908 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080CF90C @ =0x083706D0
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _080CF910 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF904: .4byte 0xFFFFF000
_080CF908: .4byte 0xFFFFF800
_080CF90C: .4byte 0x083706D0
_080CF910: .4byte gSolidFnTable

	thumb_func_start nop_080cf914
nop_080cf914:
  bx lr
	.align 2, 0

	thumb_func_start nop_080cf918
nop_080cf918:	
  bx lr
	.align 2, 0

	thumb_func_start FUN_080cf91c
FUN_080cf91c: @ 0x080CF91C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x2c]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CF92E
	cmp r5, #1
	beq _080CF968
	b _080CF9C6
_080CF92E:
	ldr r1, _080CF98C @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CF990 @ =0x08370694
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	str r5, [r4, #0x5c]
	str r5, [r4, #0x60]
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CF960
	movs r2, #0x40
_080CF960:
	str r2, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CF968:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080CF998
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	ble _080CF986
	str r0, [r4, #0x5c]
_080CF986:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CF994 @ =0xFFFFFD00
	b _080CF9A6
	.align 2, 0
_080CF98C: .4byte 0x00006D0D
_080CF990: .4byte 0x08370694
_080CF994: .4byte 0xFFFFFD00
_080CF998:
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _080CF9A2
	str r0, [r4, #0x5c]
_080CF9A2:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CF9DC @ =0xFFFFFC00
_080CF9A6:
	cmp r0, r1
	bge _080CF9AC
	str r1, [r4, #0x5c]
_080CF9AC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CF9C6
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF9C6:
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080CF9D6
	movs r1, #0
	str r1, [r4, #0x2c]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF9D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF9DC: .4byte 0xFFFFFC00

	thumb_func_start FUN_080cf9e0
FUN_080cf9e0: @ 0x080CF9E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x2c]
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080CF9F2
	cmp r0, #1
	beq _080CFA02
	b _080CFA6A
_080CF9F2:
	movs r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080CFA02:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl FUN_080cf428
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFA64
	ldrb r1, [r5, #0xa]
	lsrs r0, r1, #4
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080CFA36
	movs r0, #0x10
	orrs r0, r1
	b _080CFA3A
_080CFA36:
	movs r0, #0xef
	ands r0, r1
_080CFA3A:
	strb r0, [r5, #0xa]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	strb r3, [r5, #0xd]
	strb r4, [r5, #0xe]
_080CFA64:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080CFA6A:
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080CFA7A
	movs r1, #0
	str r1, [r5, #0x2c]
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080CFA7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cfa80
FUN_080cfa80: @ 0x080CFA80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CFA90
	cmp r5, #1
	beq _080CFABA
	b _080CFB26
_080CFA90:
	ldr r1, _080CFB2C @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CFB30 @ =0x083706AC
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	movs r1, #0x20
	bl __divsi3
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CFABA:
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080CFAD2
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	subs r0, r2, #1
	strb r0, [r4, #0x12]
_080CFAD2:
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CFAEA
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CFAEA:
	ldrb r0, [r4, #0x12]
	adds r3, r4, #0
	adds r3, #0x8c
	cmp r0, #0
	bne _080CFB16
	ldr r0, [r3]
	movs r5, #4
	ands r0, r5
	cmp r0, #0
	beq _080CFB16
	ldr r0, _080CFB34 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r4, #0x58]
	subs r0, #8
	ldr r1, [r2, #0x58]
	cmp r1, r0
	bge _080CFB16
	ldrb r0, [r2, #0xd]
	cmp r0, #0
	bne _080CFB16
	strb r5, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CFB16:
	ldr r0, [r3]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CFB26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFB2C: .4byte 0x00006D0D
_080CFB30: .4byte 0x083706AC
_080CFB34: .4byte pZero2

	thumb_func_start FUN_080cfb38
FUN_080cfb38: @ 0x080CFB38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CFB48
	cmp r5, #1
	beq _080CFB84
	b _080CFBC4
_080CFB48:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CFBCC @ =0x08370694
	bl SetDDP
	ldr r1, _080CFBD0 @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	str r5, [r4, #0x5c]
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r2, r0, #0
	ldr r0, _080CFBD4 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CFB7C
	movs r2, #0x20
_080CFB7C:
	str r2, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CFB84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #2
	cmp r1, r0
	ble _080CFB9C
	str r0, [r4, #0x5c]
_080CFB9C:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CFBD8 @ =0xFFFFFC80
	cmp r0, r1
	bge _080CFBA6
	str r1, [r4, #0x5c]
_080CFBA6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CFBC4
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CFBC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFBCC: .4byte 0x08370694
_080CFBD0: .4byte 0x00006D0D
_080CFBD4: .4byte pZero2
_080CFBD8: .4byte 0xFFFFFC80
