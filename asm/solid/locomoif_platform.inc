	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ce538
FUN_080ce538: @ 0x080CE538
	push {r4, r5, r6, r7, lr}
	ldr r5, [r0, #0x28]
	ldr r3, [r5, #0x54]
	str r3, [r0, #0x54]
	ldr r6, _080CE584 @ =gSineTable
	adds r4, r0, #0
	adds r4, #0xb4
	ldrh r1, [r4]
	lsrs r1, r1, #8
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r6
	movs r7, #0
	ldrsh r2, [r1, r7]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r3, r3, r1
	str r3, [r0, #0x54]
	ldr r3, [r5, #0x58]
	ldr r1, _080CE588 @ =0xFFFFF000
	adds r3, r3, r1
	str r3, [r0, #0x58]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r4, #0
	ldrsh r2, [r1, r4]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r3, r3, r1
	str r3, [r0, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE584: .4byte gSineTable
_080CE588: .4byte 0xFFFFF000

	thumb_func_start nop_080ce58c
nop_080ce58c: @ 0x080CE58C
	bx lr
	.align 2, 0

	thumb_func_start LocomoIFPlatform_Init
LocomoIFPlatform_Init: @ 0x080CE590
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080CE5F0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080CE5F4 @ =0x08370310
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
	ldr r1, _080CE5F8 @ =0x083702F8
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080CE5FC @ =nop_080ce58c
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl LocomoIFPlatform_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE5F0: .4byte gSolidFnTable
_080CE5F4: .4byte 0x08370310
_080CE5F8: .4byte 0x083702F8
_080CE5FC: .4byte nop_080ce58c

	thumb_func_start LocomoIFPlatform_Update
LocomoIFPlatform_Update: @ 0x080CE600
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r1, _080CE6A0 @ =0x083702D8
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _080CE6A4 @ =0x083702E8
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _080CE6B0
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r4, #0
	strb r0, [r5, #0xb]
	movs r0, #0x8c
	adds r0, r0, r5
	mov r8, r0
	str r4, [r0]
	adds r7, r5, #0
	adds r7, #0x90
	str r4, [r7]
	adds r6, r5, #0
	adds r6, #0x94
	strb r4, [r6]
	ldrb r1, [r5, #0xa]
	movs r2, #0xfb
	mov sb, r2
	mov r0, sb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, _080CE6A8 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _080CE6E8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	mov r0, r8
	str r4, [r0]
	str r4, [r7]
	strb r4, [r6]
	ldrb r1, [r5, #0xa]
	mov r0, sb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080CE6AC @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080CE6E8
	.align 2, 0
_080CE6A0: .4byte 0x083702D8
_080CE6A4: .4byte 0x083702E8
_080CE6A8: .4byte gStageRun+232
_080CE6AC: .4byte gSolidFnTable
_080CE6B0:
	ldr r0, _080CE6D4 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r1, [r1, #0x58]
	cmp r1, r0
	bge _080CE6E0
	ldrb r1, [r5, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080CE6D8 @ =0x08370314
	str r0, [r5, #0x30]
	ldr r0, _080CE6DC @ =0x0000A001
	strh r0, [r5, #0x26]
	b _080CE6E8
	.align 2, 0
_080CE6D4: .4byte pZero2
_080CE6D8: .4byte 0x08370314
_080CE6DC: .4byte 0x0000A001
_080CE6E0:
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
_080CE6E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start LocomoIFPlatform_Die
LocomoIFPlatform_Die: @ 0x080CE6F4
	ldr r2, _080CE708 @ =gSolidFnTable
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
_080CE708: .4byte gSolidFnTable

	thumb_func_start nop_080ce70c
nop_080ce70c: @ 0x080CE70C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ce710
FUN_080ce710: @ 0x080CE710
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CE722
	cmp r0, #1
	beq _080CE73A
	b _080CE758
_080CE722:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE73A:
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CE758
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CE758:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce760
FUN_080ce760: @ 0x080CE760
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CE772
	cmp r0, #1
	beq _080CE776
	b _080CE78E
_080CE772:
	movs r0, #1
	strb r0, [r4, #0xe]
_080CE776:
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r4, #0x5c]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CE78E:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080CE79C
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CE79C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce7a4
FUN_080ce7a4: @ 0x080CE7A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CE7B4
	cmp r5, #1
	beq _080CE7CE
	b _080CE7FE
_080CE7B4:
	ldr r0, _080CE804 @ =0x0000010B
	bl PlaySound
	ldr r1, _080CE808 @ =0x00005501
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE7CE:
	ldr r1, [r4, #0x5c]
	adds r1, #4
	str r1, [r4, #0x5c]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE7FE
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080CE7FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE804: .4byte 0x0000010B
_080CE808: .4byte 0x00005501

	thumb_func_start FUN_080ce80c
FUN_080ce80c: @ 0x080CE80C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CE81E
	cmp r0, #1
	beq _080CE828
	b _080CE862
_080CE81E:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CE828:
	ldr r1, [r4, #0x5c]
	subs r1, #4
	str r1, [r4, #0x5c]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r5, #0
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080ce538
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CE862
	ldr r0, _080CE868 @ =0x0000010B
	bl stopSound
	adds r0, r6, #0
	adds r0, #0xbd
	strb r5, [r0]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080CE862:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CE868: .4byte 0x0000010B
