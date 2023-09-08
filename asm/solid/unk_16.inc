	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cee14
FUN_080cee14: @ 0x080CEE14
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r7, r2, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080CEE94 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080CEE8E
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CEE98 @ =gSolidFnTable
	movs r3, #0x10
	movs r0, #0x10
	strb r0, [r4, #9]
	ldr r0, [r1, #0x40]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r4, #0xb]
	orrs r0, r3
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r6, r1
	str r0, [r4, #0x54]
	str r7, [r4, #0x58]
	strb r5, [r4, #0x10]
	movs r1, #1
	movs r0, #1
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _080CEE9C @ =0x0000700F
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl AppendQuake
_080CEE8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CEE94: .4byte gSolidHeaderPtr
_080CEE98: .4byte gSolidFnTable
_080CEE9C: .4byte 0x0000700F

	thumb_func_start Solid16_Init
Solid16_Init: @ 0x080CEEA0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	movs r2, #0
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080CEF04
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080CEEF8 @ =0x08370578
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080CEEFC @ =FUN_080cefb4
	str r0, [r4, #0x24]
	ldrb r1, [r5, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r5, #0x1d]
	ldr r1, _080CEF00 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Solid16_Update
	b _080CEF1C
	.align 2, 0
_080CEEF8: .4byte 0x08370578
_080CEEFC: .4byte FUN_080cefb4
_080CEF00: .4byte gSolidFnTable
_080CEF04:
	ldr r1, _080CEF24 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Solid16_Die
_080CEF1C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CEF24: .4byte gSolidFnTable

	thumb_func_start Solid16_Update
Solid16_Update: @ 0x080CEF28
	ldr r1, _080CEF38 @ =pZero2
	ldr r2, [r1]
	ldr r1, [r2, #0x54]
	str r1, [r0, #0x54]
	ldr r1, [r2, #0x58]
	str r1, [r0, #0x58]
	bx lr
	.align 2, 0
_080CEF38: .4byte pZero2

	thumb_func_start Solid16_Die
Solid16_Die: @ 0x080CEF3C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080CEF4C
	cmp r0, #1
	beq _080CEF58
	b _080CEFA2
_080CEF4C:
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080CEFA2
_080CEF58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x60]
	ldr r0, _080CEFA8 @ =0x000006FF
	cmp r1, r0
	bgt _080CEF6C
	adds r0, r1, #0
	adds r0, #0x20
	str r0, [r4, #0x60]
_080CEF6C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldr r0, _080CEFAC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080CEFA2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080CEFB0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080CEFA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CEFA8: .4byte 0x000006FF
_080CEFAC: .4byte gStageRun+232
_080CEFB0: .4byte gSolidFnTable

	thumb_func_start FUN_080cefb4
FUN_080cefb4: @ 0x080CEFB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r2, [r0, #0xc]
	ldr r4, [r2, #4]
	ldr r5, [r2, #8]
	adds r6, r4, #0
	adds r6, #0x10
	ldr r3, [r5]
	ldr r0, _080CEFEC @ =0xFFE3E000
	adds r1, r3, r0
	ldr r0, _080CEFF0 @ =0x0000EFFF
	cmp r1, r0
	bls _080CF08A
	ldr r0, [r2, #0x2c]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080CEFF4
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	adds r7, r3, r0
	b _080CEFFA
	.align 2, 0
_080CEFEC: .4byte 0xFFE3E000
_080CEFF0: .4byte 0x0000EFFF
_080CEFF4:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	subs r7, r3, r0
_080CEFFA:
	movs r0, #2
	ldrsh r1, [r6, r0]
	ldr r0, [r5, #4]
	adds r5, r0, r1
	ldrh r0, [r6, #4]
	lsrs r0, r0, #1
	mov sl, r0
	ldrh r0, [r6, #6]
	lsrs r0, r0, #1
	mov r8, r0
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CF020
	adds r0, r7, #0
	b _080CF074
_080CF020:
	mov r1, sl
	adds r4, r7, r1
	mov r0, r8
	adds r6, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CF05A
	mov r1, r8
	subs r5, r5, r1
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CF072
	mov r0, sl
	subs r4, r7, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CF064
_080CF05A:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08010dd8
	b _080CF08A
_080CF064:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08010d70
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CF07C
_080CF072:
	adds r0, r4, #0
_080CF074:
	adds r1, r5, #0
	bl FUN_08010dd8
	b _080CF08A
_080CF07C:
	mov r1, sb
	ldr r0, [r1, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r1, sb
	str r0, [r1, #0x18]
_080CF08A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cf098
FUN_080cf098: @ 0x080CF098
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080CF0CE
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080CF0CE
	ldr r0, _080CF0F4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x58]
	ldr r0, [r2, #0x58]
	cmp r1, r0
	bgt _080CF0CE
	movs r1, #1
	strb r1, [r2, #0x12]
	ldrb r0, [r2, #0xd]
	cmp r0, #0
	bne _080CF0CE
	strb r1, [r2, #0xd]
	strb r0, [r2, #0xe]
_080CF0CE:
	ldr r0, [r3, #0x14]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CF0EE
	ldrh r1, [r4, #8]
	ldr r0, _080CF0F8 @ =0x00001106
	cmp r1, r0
	bne _080CF0EE
	ldrb r0, [r2, #0xd]
	cmp r0, #1
	bne _080CF0EE
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080CF0EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF0F4: .4byte pZero2
_080CF0F8: .4byte 0x00001106
