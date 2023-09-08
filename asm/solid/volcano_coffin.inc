	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start VolcanoCoffin_Init
VolcanoCoffin_Init: @ 0x080DDA74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #2
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DDAD4 @ =gCurStory
	ldr r2, _080DDAD8 @ =0x083716B8
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	adds r1, #0xc
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #8
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080DDADC @ =0xFFFFE001
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r4, #0x5c]
	ldr r1, _080DDAE0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VolcanoCoffin_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DDAD4: .4byte gCurStory
_080DDAD8: .4byte 0x083716B8
_080DDADC: .4byte 0xFFFFE001
_080DDAE0: .4byte gSolidFnTable

	thumb_func_start VolcanoCoffin_Update
VolcanoCoffin_Update: @ 0x080DDAE4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080DDB6A
	cmp r6, #1
	bgt _080DDAFA
	cmp r6, #0
	beq _080DDB02
	b _080DDCE2
_080DDAFA:
	cmp r6, #2
	bne _080DDB00
	b _080DDC1C
_080DDB00:
	b _080DDCE2
_080DDB02:
	ldr r0, _080DDBA4 @ =gStageRun+232
	adds r7, r5, #0
	adds r7, #0x54
	adds r1, r7, #0
	bl CalcFromCamera
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080DDB18
	b _080DDCE2
_080DDB18:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0x99
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DDBA8 @ =0x08371698
	adds r0, r4, #0
	adds r2, r7, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xb]
	movs r0, #0xef
	ands r0, r1
	ldrb r1, [r5, #0x1c]
	strb r1, [r5, #0x1d]
	movs r1, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080DDBAC @ =0x083716B0
	str r0, [r5, #0x30]
	ldr r0, _080DDBB0 @ =0x00002001
	strh r0, [r5, #0x26]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DDB6A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _080DDBDC
	ldr r0, _080DDBB4 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r5, #0x54]
	movs r3, #0xa8
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x54]
	cmp r1, r0
	ble _080DDBC0
	ldr r0, _080DDBB8 @ =0xFFFFFBC0
	str r0, [r5, #0x5c]
	ldr r0, _080DDBBC @ =0xFFFFD600
	str r0, [r5, #0x64]
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #2
	b _080DDCE0
	.align 2, 0
_080DDBA4: .4byte gStageRun+232
_080DDBA8: .4byte 0x08371698
_080DDBAC: .4byte 0x083716B0
_080DDBB0: .4byte 0x00002001
_080DDBB4: .4byte pZero2
_080DDBB8: .4byte 0xFFFFFBC0
_080DDBBC: .4byte 0xFFFFD600
_080DDBC0:
	ldr r6, _080DDBD8 @ =0xFFFFD600
	adds r0, r2, r6
	cmp r1, r0
	bge _080DDBDC
	movs r0, #0x88
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r3, [r5, #0x64]
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #2
	b _080DDCE0
	.align 2, 0
_080DDBD8: .4byte 0xFFFFD600
_080DDBDC:
	ldr r0, _080DDC18 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080DDCE2
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r5, #0xa]
	str r2, [r4]
	adds r0, r5, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
	strb r2, [r5, #0xd]
	b _080DDCE2
	.align 2, 0
_080DDC18: .4byte gStageRun+232
_080DDC1C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r2, r0, r1
	str r2, [r5, #0x54]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	bge _080DDC2E
	adds r0, #0xf
_080DDC2E:
	asrs r0, r0, #4
	str r0, [r5, #0x5c]
	movs r6, #1
	ldr r0, [r5, #0x64]
	adds r0, r2, r0
	ldr r1, [r5, #0x58]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r1, r4
	bl PushoutToUp1
	cmp r0, #0
	beq _080DDC70
	movs r6, #0
	ldr r1, [r5, #0x64]
	cmp r1, #0
	bge _080DDC5E
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	bl PushoutToRight1
	b _080DDC6A
_080DDC5E:
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	bl PushoutToLeft1
_080DDC6A:
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	str r1, [r5, #0x54]
_080DDC70:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DDCB8
	cmp r6, #0
	beq _080DDCB8
	ldr r2, _080DDCEC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080DDCF0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080DDCF4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x46
	bl __umodsi3
	subs r0, #0x23
	lsls r0, r0, #8
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	str r1, [sp]
	ldr r0, [r5, #0x58]
	movs r6, #0x90
	lsls r6, r6, #6
	adds r0, r0, r6
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080DDCB8:
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	cmp r0, #0x80
	bhi _080DDCE2
	ldr r2, _080DDCF8 @ =gCurStory
	ldr r1, _080DDCFC @ =0x083716B8
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r2, #0xc
	ldrh r0, [r0]
	adds r2, r2, r0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x68]
	subs r0, r0, r1
	asrs r0, r0, #8
	movs r1, #0
	strb r0, [r2]
	str r1, [r5, #0x5c]
	movs r0, #1
_080DDCE0:
	strb r0, [r5, #0xd]
_080DDCE2:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDCEC: .4byte RNG_0202f388
_080DDCF0: .4byte 0x000343FD
_080DDCF4: .4byte 0x00269EC3
_080DDCF8: .4byte gCurStory
_080DDCFC: .4byte 0x083716B8

	thumb_func_start VolcanoCoffin_Die
VolcanoCoffin_Die: @ 0x080DDD00
	bx lr
	.align 2, 0
