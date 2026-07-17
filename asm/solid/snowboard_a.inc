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
	bl Camera_GetDistance
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
	bl Camera_GetDistance
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

