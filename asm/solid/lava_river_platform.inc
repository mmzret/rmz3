	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ccefc
FUN_080ccefc: @ 0x080CCEFC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _080CCF0E
	cmp r4, #1
	beq _080CCF30
	b _080CD010
_080CCF0E:
	movs r0, #0x77
	bl PlaySound
	str r4, [r5, #0x60]
	strb r4, [r5, #0x12]
	str r4, [r5, #0x64]
	movs r1, #0xec
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080CCF30:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CCF40
	str r1, [r5, #0x60]
_080CCF40:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r2, [r4]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r1, r0, #0
	adds r7, r4, #0
	cmp r1, #0
	bge _080CCF64
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_080CCF64:
	ldr r6, [r5, #0x58]
	ldr r0, [r7]
	adds r6, r6, r0
	ldr r0, [r5, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	cmp r6, r0
	bge _080CCF78
	adds r6, r0, #0
_080CCF78:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r6, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _080CCF90
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080CCF90:
	ldr r0, [r5, #0x64]
	adds r0, #1
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080CCFF2
	ldr r0, _080CD018 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080CD01C @ =0x000007FF
	cmp r0, r1
	bhi _080CCFF2
	ldr r0, [r5, #0x64]
	cmp r0, #0x77
	bgt _080CCFF2
	ldr r4, [r5, #0x54]
	ldr r0, _080CD020 @ =0xFFFFD800
	adds r4, r4, r0
	str r4, [sp]
	ldr r2, _080CD024 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080CD028 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CD02C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #6
	bl __umodsi3
	adds r0, r0, r4
	str r0, [sp]
	ldr r2, _080CD030 @ =0xFFFFFC00
	adds r0, r6, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl CreateParticle
_080CCFF2:
	ldr r0, [r7]
	subs r0, #0x60
	str r0, [r7]
	ldr r1, _080CD034 @ =0xFFFFF000
	cmp r0, r1
	bge _080CD010
	ldr r1, _080CD038 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080CD010:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD018: .4byte gStageRun+232
_080CD01C: .4byte 0x000007FF
_080CD020: .4byte 0xFFFFD800
_080CD024: .4byte RNG_0202f388
_080CD028: .4byte 0x000343FD
_080CD02C: .4byte 0x00269EC3
_080CD030: .4byte 0xFFFFFC00
_080CD034: .4byte 0xFFFFF000
_080CD038: .4byte gSolidFnTable

	thumb_func_start FUN_080cd03c
FUN_080cd03c: @ 0x080CD03C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CD04C
	cmp r0, #1
	beq _080CD060
	b _080CD0B2
_080CD04C:
	strb r0, [r4, #0x12]
	str r0, [r4, #0x60]
	movs r1, #0xec
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CD060:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CD070
	str r1, [r4, #0x60]
_080CD070:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r2, [r2]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r1, r0, #0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CD09C
	movs r0, #0x80
	str r0, [r4, #0x60]
	cmp r1, #0
	bne _080CD0AC
	movs r0, #1
	strb r0, [r4, #0x12]
	b _080CD0AC
_080CD09C:
	cmp r1, #0
	bge _080CD0AC
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CD0AC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CD0B2:
	pop {r4}
	pop {r0}
	bx r0
