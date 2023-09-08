	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor8_Update
Actor8_Update: @ 0x080D1748
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bls _080D175C
	b _080D1CD8
_080D175C:
	lsls r0, r0, #2
	ldr r1, _080D1768 @ =_080D176C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D1768: .4byte _080D176C
_080D176C: @ jump table
	.4byte _080D1780 @ case 0
	.4byte _080D1A60 @ case 1
	.4byte _080D1ADA @ case 2
	.4byte _080D1B8C @ case 3
	.4byte _080D1C1E @ case 4
_080D1780:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _080D17CC
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080D17CC
	ldr r2, _080D1908 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D190C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D1910 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x1e
	strb r0, [r7, #0x12]
	ldr r2, [r7, #0x54]
	ldr r3, _080D1914 @ =0xFFFFF000
	adds r2, r2, r3
	ldr r3, [r7, #0x68]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r3, r3, r4
	movs r0, #1
	movs r1, #0
	bl FUN_080c5628
_080D17CC:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D17DC
	b _080D1CD8
_080D17DC:
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r7, #0xa]
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	beq _080D17EC
	b _080D1920
_080D17EC:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	ldr r4, _080D1918 @ =0x0000011D
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _080D1808
	adds r0, r4, #0
	bl PlaySound
_080D1808:
	ldr r0, [r7, #0x54]
	ldr r1, _080D1914 @ =0xFFFFF000
	mov sb, r1
	add r0, sb
	str r0, [sp, #8]
	ldr r0, [r7, #0x68]
	ldr r2, _080D191C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldr r0, [r7, #0x68]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldr r2, [r7, #0x54]
	add r2, sb
	ldr r3, [r7, #0x68]
	adds r3, r3, r4
	mov ip, r3
	ldr r3, _080D1908 @ =RNG_0202f388
	mov r8, r3
	ldr r0, [r3]
	ldr r6, _080D190C @ =0x000343FD
	muls r0, r6, r0
	ldr r4, _080D1910 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r5, #7
	ands r0, r5
	subs r0, #4
	lsls r0, r0, #7
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #3
	mov r3, ip
	bl FUN_080c5684
	ldr r2, [r7, #0x54]
	add r2, sb
	ldr r3, [r7, #0x68]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r0, r0, r3
	mov ip, r0
	mov r1, r8
	ldr r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #4
	lsls r0, r0, #7
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #5
	mov r3, ip
	bl FUN_080c5684
	ldr r2, [r7, #0x54]
	add r2, sb
	ldr r3, [r7, #0x68]
	mov r1, r8
	ldr r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #4
	lsls r0, r0, #7
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r4, r8
	str r1, [r4]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #4
	bl FUN_080c5684
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D1CD8
	.align 2, 0
_080D1908: .4byte RNG_0202f388
_080D190C: .4byte 0x000343FD
_080D1910: .4byte 0x00269EC3
_080D1914: .4byte 0xFFFFF000
_080D1918: .4byte 0x0000011D
_080D191C: .4byte 0xFFFFFE00
_080D1920:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0x10
	bl AppendQuake
	movs r0, #0x41
	bl PlaySound
	ldr r0, [r7, #0x54]
	ldr r1, _080D1A4C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	ldr r2, _080D1A50 @ =0xFFFFF800
	mov sb, r2
	add r0, sb
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldrb r0, [r7, #0x11]
	cmp r0, #2
	bne _080D1976
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x68]
	str r0, [sp, #0xc]
	movs r0, #1
	add r1, sp, #8
	bl CreateSmoke
_080D1976:
	ldr r2, [r7, #0x54]
	ldr r4, _080D1A4C @ =0xFFFFF000
	adds r2, r2, r4
	ldr r3, [r7, #0x68]
	add r3, sb
	mov ip, r3
	ldr r0, _080D1A54 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _080D1A58 @ =0x000343FD
	muls r0, r6, r0
	ldr r4, _080D1A5C @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r5, #7
	ands r0, r5
	subs r0, #6
	lsls r0, r0, #8
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #3
	mov r3, ip
	bl FUN_080c5684
	ldr r2, [r7, #0x54]
	add r2, sb
	ldr r3, [r7, #0x68]
	add r3, sb
	mov ip, r3
	mov r1, r8
	ldr r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #6
	lsls r0, r0, #8
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #5
	mov r3, ip
	bl FUN_080c5684
	ldr r2, [r7, #0x54]
	add r2, sb
	ldr r3, [r7, #0x68]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r3, r0
	mov r1, r8
	ldr r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r5
	subs r0, #6
	lsls r0, r0, #8
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r4, r8
	str r1, [r4]
	lsrs r0, r0, #0x11
	ands r0, r5
	rsbs r0, r0, #0
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #4
	bl FUN_080c5684
	movs r0, #3
	strb r0, [r7, #0xd]
	b _080D1CD8
	.align 2, 0
_080D1A4C: .4byte 0xFFFFF000
_080D1A50: .4byte 0xFFFFF800
_080D1A54: .4byte RNG_0202f388
_080D1A58: .4byte 0x000343FD
_080D1A5C: .4byte 0x00269EC3
_080D1A60:
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [sp, #0xc]
	bl PushoutToUp2
	cmp r0, #0
	beq _080D1ADA
	ldr r0, [r7, #0x54]
	ldr r3, _080D1AF8 @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldr r0, [sp, #8]
	adds r0, r0, r4
	str r0, [sp, #8]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	movs r0, #0x41
	bl isSoundPlaying
	cmp r0, #0
	bne _080D1AAE
	movs r0, #0x41
	bl PlaySound
_080D1AAE:
	adds r0, r7, #0
	adds r0, #0x8c
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	str r4, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D1ADA:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bne _080D1B0C
	ldrb r1, [r7, #0x13]
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1AFC
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080D1B02
	.align 2, 0
_080D1AF8: .4byte 0xFFFFF800
_080D1AFC:
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
_080D1B02:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
_080D1B0C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r1, [r7, #0x60]
	ldr r0, _080D1B80 @ =0x000006FF
	cmp r1, r0
	bgt _080D1B20
	adds r0, r1, #0
	adds r0, #0x2a
	str r0, [r7, #0x60]
_080D1B20:
	ldr r1, [r7, #0x60]
	cmp r1, #0
	ble _080D1B2C
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_080D1B2C:
	ldr r0, _080D1B84 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D1B78
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
	ldr r1, _080D1B88 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_080D1B78:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080D1CD8
	.align 2, 0
_080D1B80: .4byte 0x000006FF
_080D1B84: .4byte gStageRun+232
_080D1B88: .4byte gSolidFnTable
_080D1B8C:
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [sp, #0xc]
	bl PushoutToUp2
	cmp r0, #0
	beq _080D1C1E
	ldr r0, [r7, #0x54]
	ldr r3, _080D1C3C @ =0xFFFFF800
	adds r0, r0, r3
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	ldr r0, [sp, #8]
	adds r0, r0, r4
	str r0, [sp, #8]
	movs r0, #3
	add r1, sp, #8
	bl CreateSmoke
	adds r0, r7, #0
	adds r0, #0x8c
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	rsbs r0, r0, #0
	asrs r0, r0, #1
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x5c]
	asrs r0, r0, #1
	str r0, [r7, #0x5c]
	ldr r2, _080D1C40 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D1C44 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D1C48 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	strb r0, [r7, #0x12]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D1C1E:
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bne _080D1C54
	ldrb r1, [r7, #0x13]
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1C4C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080D1C52
	.align 2, 0
_080D1C3C: .4byte 0xFFFFF800
_080D1C40: .4byte RNG_0202f388
_080D1C44: .4byte 0x000343FD
_080D1C48: .4byte 0x00269EC3
_080D1C4C:
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
_080D1C52:
	strb r0, [r7, #0xa]
_080D1C54:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r1, [r7, #0x60]
	ldr r0, _080D1CE8 @ =0x000006FF
	cmp r1, r0
	bgt _080D1C68
	adds r0, r1, #0
	adds r0, #0x2a
	str r0, [r7, #0x60]
_080D1C68:
	ldr r1, [r7, #0x60]
	cmp r1, #0
	ble _080D1C74
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
_080D1C74:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r1, r7, #0
	adds r1, #0x24
	ldrb r0, [r7, #0x12]
	ldrb r2, [r1]
	adds r0, r0, r2
	movs r4, #0
	strb r0, [r1]
	ldr r0, _080D1CEC @ =gStageRun+232
	adds r1, #0x30
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D1CD2
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
	ldr r1, _080D1CF0 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_080D1CD2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080D1CD8:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1CE8: .4byte 0x000006FF
_080D1CEC: .4byte gStageRun+232
_080D1CF0: .4byte gSolidFnTable

	thumb_func_start ActorCrashedPantheon_Update
ActorCrashedPantheon_Update: @ 0x080D1CF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r5, [r7, #0xd]
	cmp r5, #1
	beq _080D1D90
	cmp r5, #1
	bgt _080D1D0E
	cmp r5, #0
	beq _080D1D14
	b _080D1EF2
_080D1D0E:
	cmp r5, #2
	beq _080D1DD0
	b _080D1EF2
_080D1D14:
	ldr r0, _080D1DB4 @ =wStaticGraphicTilenums
	movs r2, #0xa1
	lsls r2, r2, #2
	strh r2, [r0, #0x26]
	ldr r6, _080D1DB8 @ =wStaticMotionPalIDs
	movs r0, #5
	strh r0, [r6, #0x26]
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _080D1D5A
	movs r4, #0xbe
	lsls r4, r4, #1
	ldr r1, _080D1DBC @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r2, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r3, _080D1DC0 @ =gStaticMotionGraphics+12
	adds r4, r4, r3
	ldrh r1, [r6, #0x26]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
_080D1D5A:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	ldr r1, _080D1DC4 @ =0x00001301
	adds r0, r7, #0
	bl SetMotion
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080D1DC8 @ =Collision_08370ad0
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D1D90:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080D1DA8
	b _080D1EF2
_080D1DA8:
	ldr r1, _080D1DCC @ =0x00001303
	adds r0, r7, #0
	bl SetMotion
	b _080D1EEC
	.align 2, 0
_080D1DB4: .4byte wStaticGraphicTilenums
_080D1DB8: .4byte wStaticMotionPalIDs
_080D1DBC: .4byte gStaticMotionGraphics
_080D1DC0: .4byte gStaticMotionGraphics+12
_080D1DC4: .4byte 0x00001301
_080D1DC8: .4byte Collision_08370ad0
_080D1DCC: .4byte 0x00001303
_080D1DD0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D1DE2
	b _080D1EF2
_080D1DE2:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080D1F00 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r4, _080D1F04 @ =SlashedEnemy_08370ae8
	ldrb r0, [r7, #0xa]
	movs r5, #0x10
	adds r3, r5, #0
	ands r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl CreateSlashedEnemy
	adds r1, r4, #0
	adds r1, #0x1c
	ldrb r0, [r7, #0xa]
	adds r3, r5, #0
	ands r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r0, sp
	movs r2, #0
	bl CreateSlashedEnemy
	adds r4, #0x38
	ldrb r0, [r7, #0xa]
	adds r3, r5, #0
	ands r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r0, [r7, #0x58]
	ldr r2, _080D1F08 @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r3, _080D1F0C @ =RNG_0202f388
	mov r8, r3
	ldr r0, [r3]
	ldr r2, _080D1F10 @ =0x000343FD
	muls r0, r2, r0
	ldr r4, _080D1F14 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsrs r0, r0, #0x11
	movs r6, #0x1f
	ands r0, r6
	subs r0, r5, r0
	lsls r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	str r1, [sp]
	adds r0, r3, #0
	muls r0, r2, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	str r2, [sp, #8]
	bl CreateSmoke
	mov r1, r8
	ldr r0, [r1]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	subs r5, r5, r0
	lsls r5, r5, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r5
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
_080D1EEC:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D1EF2:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1F00: .4byte 0xFFFFE800
_080D1F04: .4byte SlashedEnemy_08370ae8
_080D1F08: .4byte 0xFFFFF000
_080D1F0C: .4byte RNG_0202f388
_080D1F10: .4byte 0x000343FD
_080D1F14: .4byte 0x00269EC3

	thumb_func_start Actor10_Update
Actor10_Update: @ 0x080D1F18
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #8
	bls _080D1F24
	b _080D21E8
_080D1F24:
	lsls r0, r0, #2
	ldr r1, _080D1F30 @ =_080D1F34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D1F30: .4byte _080D1F34
_080D1F34: @ jump table
	.4byte _080D1F58 @ case 0
	.4byte _080D1FDE @ case 1
	.4byte _080D2024 @ case 2
	.4byte _080D203E @ case 3
	.4byte _080D2054 @ case 4
	.4byte _080D2064 @ case 5
	.4byte _080D2114 @ case 6
	.4byte _080D2180 @ case 7
	.4byte _080D21E8 @ case 8
_080D1F58:
	ldr r0, _080D2004 @ =0x085D79AC
	ldr r1, _080D2008 @ =wStaticGraphicTilenums
	ldrh r1, [r1, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D200C @ =0x085D79B8
	ldr r1, _080D2010 @ =wStaticMotionPalIDs
	ldrh r1, [r1, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _080D2014 @ =0x00000902
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, _080D2018 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D201C @ =0x00009BFF
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D1FDE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, _080D2020 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x64]
	cmp r0, r1
	blt _080D1FF4
	b _080D21E8
_080D1FF4:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #0x10
	bl AppendQuake
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	b _080D21E2
	.align 2, 0
_080D2004: .4byte 0x085D79AC
_080D2008: .4byte wStaticGraphicTilenums
_080D200C: .4byte 0x085D79B8
_080D2010: .4byte wStaticMotionPalIDs
_080D2014: .4byte 0x00000902
_080D2018: .4byte gStageRun+232
_080D201C: .4byte 0x00009BFF
_080D2020: .4byte 0xFFFFF800
_080D2024:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2038
	b _080D21E8
_080D2038:
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	b _080D21E2
_080D203E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2052
	b _080D21E8
_080D2052:
	b _080D21E2
_080D2054:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x54]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	b _080D21CC
_080D2064:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D2072
	b _080D21E8
_080D2072:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _080D2154 @ =0x085D79AC
	ldr r1, _080D2158 @ =wStaticGraphicTilenums
	ldrh r1, [r1, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D215C @ =0x085D79B8
	ldr r1, _080D2160 @ =wStaticMotionPalIDs
	ldrh r1, [r1, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	ldr r1, _080D2164 @ =0x00000902
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	movs r5, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D2168 @ =Collision_ARRAY_08370b58
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080D216C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D2170 @ =0x000097FF
	adds r1, r0, r2
	str r1, [r6, #0x54]
	ldr r1, _080D2174 @ =0x00001FFF
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x68]
	ldr r2, _080D2178 @ =0xFFFFD000
	adds r0, r0, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2114:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, _080D217C @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r0, r1, #6
	subs r0, r0, r1
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #6
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080D21E8
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0
	str r0, [r6, #0x5c]
	movs r0, #0xf
	strb r0, [r6, #0x12]
	b _080D21E2
	.align 2, 0
_080D2154: .4byte 0x085D79AC
_080D2158: .4byte wStaticGraphicTilenums
_080D215C: .4byte 0x085D79B8
_080D2160: .4byte wStaticMotionPalIDs
_080D2164: .4byte 0x00000902
_080D2168: .4byte Collision_ARRAY_08370b58
_080D216C: .4byte gStageRun+232
_080D2170: .4byte 0x000097FF
_080D2174: .4byte 0x00001FFF
_080D2178: .4byte 0xFFFFD000
_080D217C: .4byte 0xFFFFFA00
_080D2180:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x58]
	lsls r0, r1, #6
	subs r0, r0, r1
	ldr r2, _080D21B4 @ =0xFFFFD000
	adds r0, r0, r2
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #6
	str r0, [r6, #0x58]
	adds r2, r6, #0
	adds r2, #0x24
	ldrb r1, [r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, #0x4f
	asrs r0, r0, #4
	strb r0, [r2]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080D21B8
	subs r0, #1
	strb r0, [r6, #0x12]
	b _080D21E8
	.align 2, 0
_080D21B4: .4byte 0xFFFFD000
_080D21B8:
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #5
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	asrs r0, r0, #5
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
_080D21CC:
	str r1, [r6, #0x54]
	ldr r0, _080D21F0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D21F4 @ =0x000097FF
	adds r0, r0, r2
	cmp r1, r0
	blt _080D21E8
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D21E2:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D21E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21F0: .4byte gStageRun+232
_080D21F4: .4byte 0x000097FF

	thumb_func_start ActorLeviathan11_Update
ActorLeviathan11_Update: @ 0x080D21F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #7
	bls _080D2204
	b _080D23A6
_080D2204:
	lsls r0, r0, #2
	ldr r1, _080D2210 @ =_080D2214
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2210: .4byte _080D2214
_080D2214: @ jump table
	.4byte _080D2234 @ case 0
	.4byte _080D22B4 @ case 1
	.4byte _080D22F8 @ case 2
	.4byte _080D2318 @ case 3
	.4byte _080D232E @ case 4
	.4byte _080D2380 @ case 5
	.4byte _080D2390 @ case 6
	.4byte _080D23A6 @ case 7
_080D2234:
	ldr r2, _080D22DC @ =wDynamicGraphicTilenums
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080D22E0 @ =wDynamicMotionPalIDs
	adds r1, r1, r0
	movs r3, #8
	movs r0, #0xf3
	lsls r0, r0, #2
	strh r0, [r2]
	strh r3, [r1]
	ldr r1, _080D22E4 @ =0x0000BD10
	adds r0, r6, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D22E8 @ =0x08370B70
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r0, _080D22EC @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D22F0 @ =0x000087FF
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D22B4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, _080D22F4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x64]
	cmp r0, r1
	bge _080D23A6
	movs r0, #0x56
	bl PlaySound
	ldr r0, [r6, #0x64]
	str r0, [r6, #0x54]
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #0x5a
	strb r0, [r1]
	b _080D23A0
	.align 2, 0
_080D22DC: .4byte wDynamicGraphicTilenums
_080D22E0: .4byte wDynamicMotionPalIDs
_080D22E4: .4byte 0x0000BD10
_080D22E8: .4byte 0x08370B70
_080D22EC: .4byte gStageRun+232
_080D22F0: .4byte 0x000087FF
_080D22F4: .4byte 0xFFFFF800
_080D22F8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D23A6
	ldr r1, _080D2314 @ =0x0000BD12
	adds r0, r6, #0
	bl SetMotion
	b _080D23A0
	.align 2, 0
_080D2314: .4byte 0x0000BD12
_080D2318:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D23A6
	movs r0, #0
	str r0, [r6, #0x60]
	b _080D23A0
_080D232E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x60]
	ldr r0, _080D2374 @ =0x000006FF
	cmp r1, r0
	bgt _080D2342
	adds r0, r1, #0
	adds r0, #0x2a
	str r0, [r6, #0x60]
_080D2342:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r1, r1, r2
	bl PushoutToUp2
	cmp r0, #0
	beq _080D23A6
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2378 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080D237C @ =0x0000BD1B
	adds r0, r6, #0
	bl SetMotion
	b _080D23A0
	.align 2, 0
_080D2374: .4byte 0x000006FF
_080D2378: .4byte 0xFFFFFA00
_080D237C: .4byte 0x0000BD1B
_080D2380:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	b _080D239C
_080D2390:
	ldr r1, _080D23AC @ =0x0000BD1B
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D239C:
	cmp r0, #0
	beq _080D23A6
_080D23A0:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D23A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D23AC: .4byte 0x0000BD1B

	thumb_func_start ActorFefnir12_Update
ActorFefnir12_Update: @ 0x080D23B0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0x14
	bls _080D23BE
	b _080D27FC
_080D23BE:
	lsls r0, r0, #2
	ldr r1, _080D23C8 @ =_080D23CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D23C8: .4byte _080D23CC
_080D23CC: @ jump table
	.4byte _080D2420 @ case 0
	.4byte _080D24A0 @ case 1
	.4byte _080D24EC @ case 2
	.4byte _080D2558 @ case 3
	.4byte _080D25B0 @ case 4
	.4byte _080D25D8 @ case 5
	.4byte _080D264C @ case 6
	.4byte _080D2688 @ case 7
	.4byte _080D264C @ case 8
	.4byte _080D2688 @ case 9
	.4byte _080D264C @ case 10
	.4byte _080D2688 @ case 11
	.4byte _080D269C @ case 12
	.4byte _080D27FC @ case 13
	.4byte _080D26B0 @ case 14
	.4byte _080D26E4 @ case 15
	.4byte _080D2750 @ case 16
	.4byte _080D27A8 @ case 17
	.4byte _080D27C8 @ case 18
	.4byte _080D27E4 @ case 19
	.4byte _080D27FC @ case 20
_080D2420:
	ldr r0, _080D24CC @ =wDynamicGraphicTilenums
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, _080D24D0 @ =0x0000034D
	strh r1, [r0]
	ldr r0, _080D24D4 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldr r1, _080D24D8 @ =0x0000A114
	adds r0, r7, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	movs r5, #0
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080D24DC @ =0x08370B70
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0x94
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0xf4
	bl PlaySound
	ldr r0, _080D24E0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D24E4 @ =0x000087FF
	adds r0, r0, r1
	str r0, [r7, #0x54]
	movs r0, #0x14
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D24A0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x54]
	ldr r2, _080D24E8 @ =0xFFFFFD00
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D24BC
	b _080D27FC
_080D24BC:
	movs r0, #8
	strb r0, [r7, #0x12]
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	b _080D27F6
	.align 2, 0
_080D24CC: .4byte wDynamicGraphicTilenums
_080D24D0: .4byte 0x0000034D
_080D24D4: .4byte wDynamicMotionPalIDs
_080D24D8: .4byte 0x0000A114
_080D24DC: .4byte 0x08370B70
_080D24E0: .4byte gStageRun+232
_080D24E4: .4byte 0x000087FF
_080D24E8: .4byte 0xFFFFFD00
_080D24EC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r2, [r7, #0x54]
	ldr r1, _080D254C @ =0xFFFFFE00
	adds r0, r2, r1
	str r0, [r7, #0x54]
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080D2528
	ldr r1, _080D2550 @ =0xFFFFF200
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D2528:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2536
	b _080D27FC
_080D2536:
	ldr r1, _080D2554 @ =0x0000A11B
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	b _080D27F6
	.align 2, 0
_080D254C: .4byte 0xFFFFFE00
_080D2550: .4byte 0xFFFFF200
_080D2554: .4byte 0x0000A11B
_080D2558:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	asrs r0, r0, #4
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r2, r1, r0
	str r2, [r7, #0x54]
	ldrb r1, [r7, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080D259C
	ldr r1, _080D25AC @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D259C:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D25AA
	b _080D27FC
_080D25AA:
	b _080D27F6
	.align 2, 0
_080D25AC: .4byte 0xFFFFF400
_080D25B0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D25C4
	b _080D27FC
_080D25C4:
	ldr r1, _080D25D4 @ =0x0000A11C
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	b _080D27F6
	.align 2, 0
_080D25D4: .4byte 0x0000A11C
_080D25D8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D25EC
	b _080D27FC
_080D25EC:
	ldr r1, _080D2638 @ =0x0000A109
	adds r0, r7, #0
	bl SetMotion
	ldr r0, _080D263C @ =wStaticGraphicTilenums
	adds r0, #0x42
	movs r6, #0x80
	lsls r6, r6, #2
	strh r6, [r0]
	ldr r5, _080D2640 @ =wStaticMotionPalIDs
	adds r5, #0x42
	movs r0, #4
	strh r0, [r5]
	movs r4, #0xa5
	lsls r4, r4, #2
	ldr r1, _080D2644 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r6, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D2648 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	b _080D27F6
	.align 2, 0
_080D2638: .4byte 0x0000A109
_080D263C: .4byte wStaticGraphicTilenums
_080D2640: .4byte wStaticMotionPalIDs
_080D2644: .4byte gStaticMotionGraphics
_080D2648: .4byte gStaticMotionGraphics+12
_080D264C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D2660
	b _080D27FC
_080D2660:
	ldr r1, _080D2684 @ =0x0000A10B
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	movs r1, #0xd
	bl CreateScriptActor
	movs r0, #0xf5
	bl PlaySound
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	b _080D27F6
	.align 2, 0
_080D2684: .4byte 0x0000A10B
_080D2688:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D269A
	b _080D27FC
_080D269A:
	b _080D27F6
_080D269C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xe
	b _080D27FA
_080D26B0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D26C6
	b _080D27FC
_080D26C6:
	ldr r1, _080D2740 @ =0x0000A114
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xf4
	bl PlaySound
	movs r0, #0x52
	bl PlaySound
	movs r0, #8
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D26E4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r2, [r7, #0x54]
	ldr r1, _080D2744 @ =0xFFFFFE00
	adds r0, r2, r1
	str r0, [r7, #0x54]
	ldrb r1, [r7, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080D2720
	ldr r1, _080D2748 @ =0xFFFFF200
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D2720:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D27FC
	ldr r1, _080D274C @ =0x0000A11B
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r7, #0x5c]
	movs r0, #0x18
	strb r0, [r7, #0x12]
	b _080D27F6
	.align 2, 0
_080D2740: .4byte 0x0000A114
_080D2744: .4byte 0xFFFFFE00
_080D2748: .4byte 0xFFFFF200
_080D274C: .4byte 0x0000A11B
_080D2750:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r1, [r7, #0x5c]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r2, r1, r0
	str r2, [r7, #0x54]
	ldrb r1, [r7, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080D2794
	ldr r1, _080D27A4 @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D2794:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D27FC
	b _080D27F6
	.align 2, 0
_080D27A4: .4byte 0xFFFFF400
_080D27A8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D27FC
	ldr r1, _080D27C4 @ =0x0000A11C
	adds r0, r7, #0
	bl SetMotion
	b _080D27F6
	.align 2, 0
_080D27C4: .4byte 0x0000A11C
_080D27C8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D27FC
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	b _080D27F6
_080D27E4:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r7, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D27FC
_080D27F6:
	ldrb r0, [r7, #0xd]
	adds r0, #1
_080D27FA:
	strb r0, [r7, #0xd]
_080D27FC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor13_Update
Actor13_Update: @ 0x080D2804
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D2816
	cmp r0, #1
	beq _080D286E
	b _080D289C
_080D2816:
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r2, _080D28A4 @ =0xFFFFE200
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D286E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, _080D28A8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D28AC @ =0x0000B7FF
	adds r0, r0, r2
	cmp r1, r0
	ble _080D289C
	ldr r1, _080D28B0 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080D289C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D28A4: .4byte 0xFFFFE200
_080D28A8: .4byte gStageRun+232
_080D28AC: .4byte 0x0000B7FF
_080D28B0: .4byte gSolidFnTable

	thumb_func_start ActorSaveSelectCiel_Update
ActorSaveSelectCiel_Update: @ 0x080D28B4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D28C4
	cmp r0, #1
	beq _080D28DE
	b _080D28E4
_080D28C4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D28DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D28E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor15_Update
Actor15_Update: @ 0x080D28EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D28FC
	cmp r0, #1
	beq _080D2922
	b _080D2928
_080D28FC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2930 @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0xca
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2922:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D2928:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2930: .4byte 0xFFFFE400

	thumb_func_start ActorOperator_Update
ActorOperator_Update: @ 0x080D2934
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D2944
	cmp r0, #1
	beq _080D29C4
	b _080D29CA
_080D2944:
	ldr r1, [r4, #0x54]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080D2952
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080D2954
_080D2952:
	ldr r2, _080D2994 @ =0xFFFFF400
_080D2954:
	adds r0, r1, r2
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2998 @ =0xFFFFE500
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x11]
	movs r2, #0xc9
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	movs r1, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080D2986
	movs r1, #1
_080D2986:
	adds r2, r1, #0
	cmp r2, #0
	beq _080D299C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080D29A2
	.align 2, 0
_080D2994: .4byte 0xFFFFF400
_080D2998: .4byte 0xFFFFE500
_080D299C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D29A2:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D29C4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D29CA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Actor17_Update
Actor17_Update: @ 0x080D29D0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D2AC0
	cmp r7, #1
	ble _080D29E0
	b _080D2B34
_080D29E0:
	cmp r7, #0
	beq _080D29E6
	b _080D2B34
_080D29E6:
	ldrb r1, [r6, #0x11]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D2A0C
	movs r0, #0x2b
	bl PlaySound
	ldr r0, _080D2AD8 @ =wStaticGraphicTilenums
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2ADC @ =wStaticMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
_080D2A0C:
	ldr r4, _080D2AE0 @ =0x00001270
	ldr r1, _080D2AE4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D2AD8 @ =wStaticGraphicTilenums
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r3, _080D2AE8 @ =gStaticMotionGraphics+12
	adds r4, r4, r3
	ldr r0, _080D2ADC @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D2AEC @ =0x0000EC01
	adds r0, r6, #0
	bl SetMotion
	adds r3, r6, #0
	adds r3, #0x45
	ldrb r2, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r3]
	adds r3, #4
	ldrb r0, [r3]
	ands r1, r0
	orrs r1, r2
	strb r1, [r3]
	ldrb r0, [r6, #0xa]
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldrb r1, [r6, #0x11]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D2AF0 @ =0x08370B88
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #9
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D2AF4 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080D2AF8 @ =gBlendRegBuffer
	movs r0, #0xfd
	lsls r0, r0, #6
	strh r0, [r1]
	movs r0, #8
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2AC0:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #6
	bls _080D2B00
	ldr r1, _080D2AF8 @ =gBlendRegBuffer
	ldr r0, _080D2AFC @ =0x00001010
	strh r0, [r1, #2]
	adds r2, r1, #0
	b _080D2B16
	.align 2, 0
_080D2AD8: .4byte wStaticGraphicTilenums
_080D2ADC: .4byte wStaticMotionPalIDs
_080D2AE0: .4byte 0x00001270
_080D2AE4: .4byte gStaticMotionGraphics
_080D2AE8: .4byte gStaticMotionGraphics+12
_080D2AEC: .4byte 0x0000EC01
_080D2AF0: .4byte 0x08370B88
_080D2AF4: .4byte 0xFFFFB000
_080D2AF8: .4byte gBlendRegBuffer
_080D2AFC: .4byte 0x00001010
_080D2B00:
	ldr r2, _080D2B3C @ =gBlendRegBuffer
	ldrb r1, [r6, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #0x1f
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #2]
_080D2B16:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080D2B34
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	strh r3, [r2]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2B34:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2B3C: .4byte gBlendRegBuffer

	thumb_func_start Actor18_Update
Actor18_Update: @ 0x080D2B40
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bls _080D2B4C
	b _080D2D44
_080D2B4C:
	lsls r0, r0, #2
	ldr r1, _080D2B58 @ =_080D2B5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2B58: .4byte _080D2B5C
_080D2B5C: @ jump table
	.4byte _080D2B88 @ case 0
	.4byte _080D2BA4 @ case 1
	.4byte _080D2BBC @ case 2
	.4byte _080D2BE4 @ case 3
	.4byte _080D2C1C @ case 4
	.4byte _080D2C44 @ case 5
	.4byte _080D2C80 @ case 6
	.4byte _080D2CC4 @ case 7
	.4byte _080D2D14 @ case 8
	.4byte _080D2D2E @ case 9
	.4byte _080D2D44 @ case 10
_080D2B88:
	ldr r0, _080D2BB4 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2BB8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2BA4:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D2D38
	.align 2, 0
_080D2BB4: .4byte wDynamicGraphicTilenums
_080D2BB8: .4byte wDynamicMotionPalIDs
_080D2BBC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2BD0
	b _080D2D44
_080D2BD0:
	ldr r1, _080D2BE0 @ =0x0000BE01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	b _080D2D3E
	.align 2, 0
_080D2BE0: .4byte 0x0000BE01
_080D2BE4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D2BFC
	ldr r0, _080D2C14 @ =0x00000101
	bl PlaySound
_080D2BFC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D2C08
	b _080D2D44
_080D2C08:
	ldr r1, _080D2C18 @ =0x0000BE02
	adds r0, r4, #0
	bl SetMotion
	b _080D2D3E
	.align 2, 0
_080D2C14: .4byte 0x00000101
_080D2C18: .4byte 0x0000BE02
_080D2C1C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D2C2E
	b _080D2D44
_080D2C2E:
	ldr r1, _080D2C40 @ =0x0000BE03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	b _080D2D3E
	.align 2, 0
_080D2C40: .4byte 0x0000BE03
_080D2C44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, _080D2C7C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r4, #0x68]
	subs r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r1, r0, #3
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080D2D44
	strb r0, [r4, #0x12]
	str r1, [r4, #0x60]
	b _080D2D3E
	.align 2, 0
_080D2C7C: .4byte gSineTable
_080D2C80:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r1, _080D2CC0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r2, r0, #3
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2D44
	movs r0, #0x40
	strb r0, [r4, #0x12]
	str r2, [r4, #0x68]
	b _080D2D3E
	.align 2, 0
_080D2CC0: .4byte gSineTable
_080D2CC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r2, [r4, #0x68]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _080D2D0C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	str r2, [r4, #0x68]
	ldr r0, [r4, #0x58]
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, r1, r2
	asrs r1, r1, #3
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp2
	cmp r0, #0
	beq _080D2D44
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080D2D10 @ =0x0000BE0E
	adds r0, r4, #0
	bl SetMotion
	b _080D2D3E
	.align 2, 0
_080D2D0C: .4byte gSineTable
_080D2D10: .4byte 0x0000BE0E
_080D2D14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D2D44
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	b _080D2D3A
_080D2D2E:
	ldr r1, _080D2D4C @ =0x0000BE0E
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
_080D2D38:
	lsls r0, r0, #0x10
_080D2D3A:
	cmp r0, #0
	beq _080D2D44
_080D2D3E:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2D44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2D4C: .4byte 0x0000BE0E

	thumb_func_start Actor19_Update
Actor19_Update: @ 0x080D2D50
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D2DA8
	cmp r0, #1
	bgt _080D2D64
	cmp r0, #0
	beq _080D2D6A
	b _080D2DFE
_080D2D64:
	cmp r0, #2
	beq _080D2DE8
	b _080D2DFE
_080D2D6A:
	ldr r0, _080D2DD4 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2DD8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
	ldr r1, _080D2DDC @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	ldr r0, _080D2DE0 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080D2DE4 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2DA8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x54]
	lsls r0, r1, #7
	subs r0, r0, r1
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	asrs r0, r0, #7
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	lsls r0, r1, #7
	subs r0, r0, r1
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #7
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D2DF4
	.align 2, 0
_080D2DD4: .4byte wDynamicGraphicTilenums
_080D2DD8: .4byte wDynamicMotionPalIDs
_080D2DDC: .4byte 0x0000C501
_080D2DE0: .4byte gStageRun+232
_080D2DE4: .4byte 0xFFFFB000
_080D2DE8:
	ldr r1, _080D2E04 @ =0x0000C501
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D2DF4:
	cmp r0, #0
	beq _080D2DFE
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2DFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2E04: .4byte 0x0000C501

	thumb_func_start Actor20_Update
Actor20_Update: @ 0x080D2E08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _080D2E8E
	lsls r0, r0, #2
	ldr r1, _080D2E1C @ =_080D2E20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2E1C: .4byte _080D2E20
_080D2E20: @ jump table
	.4byte _080D2E34 @ case 0
	.4byte _080D2E50 @ case 1
	.4byte _080D2E68 @ case 2
	.4byte _080D2E78 @ case 3
	.4byte _080D2E8E @ case 4
_080D2E34:
	ldr r0, _080D2E5C @ =wDynamicGraphicTilenums
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xd0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D2E60 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #7
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2E50:
	ldr r1, _080D2E64 @ =0x0000B319
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D2E82
	.align 2, 0
_080D2E5C: .4byte wDynamicGraphicTilenums
_080D2E60: .4byte wDynamicMotionPalIDs
_080D2E64: .4byte 0x0000B319
_080D2E68:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D2E84
_080D2E78:
	ldr r1, _080D2E94 @ =0x0000B319
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
_080D2E82:
	lsls r0, r0, #0x10
_080D2E84:
	cmp r0, #0
	beq _080D2E8E
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D2E8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2E94: .4byte 0x0000B319

	thumb_func_start initActor21
initActor21: @ 0x080D2E98
	push {r4, lr}
	ldr r2, _080D2ED4 @ =gWindowRegBuffer
	ldrh r3, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	ldrb r3, [r2, #0xe]
	movs r1, #0xfe
	orrs r1, r3
	strb r1, [r2, #0xe]
	movs r3, #1
	strb r4, [r2, #0xd]
	strb r4, [r0, #0x12]
	ldr r2, _080D2ED8 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	str r3, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2ED4: .4byte gWindowRegBuffer
_080D2ED8: .4byte gSolidFnTable

	thumb_func_start Actor21_Update
Actor21_Update: @ 0x080D2EDC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #6
	bls _080D2EE8
	b _080D2FEC
_080D2EE8:
	lsls r0, r0, #2
	ldr r1, _080D2EF4 @ =_080D2EF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D2EF4: .4byte _080D2EF8
_080D2EF8: @ jump table
	.4byte _080D2F14 @ case 0
	.4byte _080D2F26 @ case 1
	.4byte _080D2F58 @ case 2
	.4byte _080D2F6A @ case 3
	.4byte _080D2F86 @ case 4
	.4byte _080D2FC0 @ case 5
	.4byte _080D2FEC @ case 6
_080D2F14:
	movs r1, #0
	str r1, [r6, #0x54]
	movs r0, #0x93
	lsls r0, r0, #8
	str r0, [r6, #0x58]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2F26:
	ldr r2, _080D2F54 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	adds r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1f
	bls _080D2FEC
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x10
	strb r0, [r6, #0x13]
	b _080D2FEC
	.align 2, 0
_080D2F54: .4byte gSineTable
_080D2F58:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2FEC
	movs r0, #4
	strb r0, [r6, #0x13]
	b _080D2FE6
_080D2F6A:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D2FEC
	movs r0, #8
	strb r0, [r6, #0x13]
	b _080D2FE6
_080D2F86:
	ldrb r1, [r6, #0x13]
	subs r1, #1
	strb r1, [r6, #0x13]
	ldr r2, _080D2FBC @ =gSineTable
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [r6, #0x54]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080D2FEC
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x97
	lsls r0, r0, #1
	bl PlaySound
	b _080D2FEC
	.align 2, 0
_080D2FBC: .4byte gSineTable
_080D2FC0:
	ldr r1, [r6, #0x54]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	str r0, [r6, #0x58]
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bgt _080D2FEC
	ldr r2, _080D302C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080D3030 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_080D2FE6:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D2FEC:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r5, _080D302C @ =gWindowRegBuffer
	ldr r2, [r6, #0x54]
	asrs r2, r2, #8
	movs r3, #1
	ands r3, r0
	lsls r0, r3, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xbc
	movs r4, #0xff
	ands r1, r4
	movs r0, #0xbc
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	lsls r3, r3, #2
	adds r0, r0, r3
	ands r0, r4
	strh r0, [r5, #0xa]
	ldr r1, _080D3034 @ =gPaletteManager
	ldr r3, _080D3038 @ =0x00007FFF
	adds r0, r3, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D302C: .4byte gWindowRegBuffer
_080D3030: .4byte 0x0000BFFF
_080D3034: .4byte gPaletteManager
_080D3038: .4byte 0x00007FFF

	thumb_func_start Actor22_Update
Actor22_Update: @ 0x080D303C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #4
	bls _080D3048
	b _080D3166
_080D3048:
	lsls r0, r0, #2
	ldr r1, _080D3054 @ =_080D3058
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3054: .4byte _080D3058
_080D3058: @ jump table
	.4byte _080D306C @ case 0
	.4byte _080D30D6 @ case 1
	.4byte _080D3120 @ case 2
	.4byte _080D3140 @ case 3
	.4byte _080D3166 @ case 4
_080D306C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	movs r4, #0x82
	ldr r0, _080D310C @ =wStaticGraphicTilenums
	lsls r1, r4, #1
	adds r2, r0, r1
	ldr r0, _080D3110 @ =0x0000024D
	strh r0, [r2]
	ldr r0, _080D3114 @ =wStaticMotionPalIDs
	adds r6, r0, r1
	movs r0, #8
	strh r0, [r6]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D30C6
	lsls r4, r4, #2
	adds r4, #0x82
	lsls r4, r4, #2
	ldr r1, _080D3118 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r2]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D311C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_080D30C6:
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D30D6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D3166
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #8
	strb r0, [r5, #0x12]
	b _080D3160
	.align 2, 0
_080D310C: .4byte wStaticGraphicTilenums
_080D3110: .4byte 0x0000024D
_080D3114: .4byte wStaticMotionPalIDs
_080D3118: .4byte gStaticMotionGraphics
_080D311C: .4byte gStaticMotionGraphics+12
_080D3120:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D3166
	ldr r1, _080D313C @ =0x00008202
	adds r0, r5, #0
	bl SetMotion
	b _080D3160
	.align 2, 0
_080D313C: .4byte 0x00008202
_080D3140:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x54]
	subs r1, #0x80
	str r1, [r5, #0x54]
	ldr r0, _080D316C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D3170 @ =0xFFFF7800
	adds r0, r0, r2
	cmp r1, r0
	bge _080D3166
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
_080D3160:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D3166:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D316C: .4byte gStageRun+232
_080D3170: .4byte 0xFFFF7800

	thumb_func_start initActor23
initActor23: @ 0x080D3174
	push {lr}
	ldrb r2, [r0, #0xb]
	movs r1, #8
	movs r3, #0
	orrs r1, r2
	strb r1, [r0, #0xb]
	ldr r1, _080D31A4 @ =0x08370C60
	str r1, [r0, #0x30]
	ldr r1, _080D31A8 @ =0x00002001
	strh r1, [r0, #0x26]
	str r3, [r0, #0x5c]
	ldr r2, _080D31AC @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r0}
	bx r0
	.align 2, 0
_080D31A4: .4byte 0x08370C60
_080D31A8: .4byte 0x00002001
_080D31AC: .4byte gSolidFnTable

	thumb_func_start Actor23_Update
Actor23_Update: @ 0x080D31B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D31EE
	ldr r0, _080D31F4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080D31F8 @ =0x00000FFF
	cmp r0, r1
	bhi _080D31EE
	ldr r0, [r4, #0x5c]
	adds r0, #4
	str r0, [r4, #0x5c]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080D31E0
	str r1, [r4, #0x5c]
_080D31E0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x58]
_080D31EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D31F4: .4byte gStageRun+232
_080D31F8: .4byte 0x00000FFF

	thumb_func_start Actor24_Update
Actor24_Update: @ 0x080D31FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0
	bne _080D325C
	ldr r6, [r7, #0x28]
	ldr r4, _080D3268 @ =0x0000107C
	ldr r1, _080D326C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D3270 @ =wStaticGraphicTilenums
	movs r5, #0xd3
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3274 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D3278 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D327C @ =0x0000D301
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r6]
	str r0, [r7, #0x54]
	ldr r0, [r6, #4]
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D325C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3268: .4byte 0x0000107C
_080D326C: .4byte gStaticMotionGraphics
_080D3270: .4byte wStaticGraphicTilenums
_080D3274: .4byte gStaticMotionGraphics+12
_080D3278: .4byte wStaticMotionPalIDs
_080D327C: .4byte 0x0000D301

	thumb_func_start Actor25_Update
Actor25_Update: @ 0x080D3280
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bls _080D328E
	b _080D358C
_080D328E:
	lsls r0, r0, #2
	ldr r1, _080D3298 @ =_080D329C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3298: .4byte _080D329C
_080D329C: @ jump table
	.4byte _080D32C4 @ case 0
	.4byte _080D3352 @ case 1
	.4byte _080D336C @ case 2
	.4byte _080D339C @ case 3
	.4byte _080D33BA @ case 4
	.4byte _080D33DA @ case 5
	.4byte _080D3412 @ case 6
	.4byte _080D3478 @ case 7
	.4byte _080D356C @ case 8
	.4byte _080D3584 @ case 9
_080D32C4:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	ldrb r6, [r7, #0x11]
	movs r0, #0xf
	ands r0, r6
	strb r0, [r7, #0x11]
	ldrb r4, [r7, #0x11]
	adds r4, #0xf5
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r1, _080D333C @ =gStaticMotionGraphics
	adds r0, r5, r1
	ldr r1, _080D3340 @ =wStaticGraphicTilenums
	lsls r4, r4, #1
	adds r1, r4, r1
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r3, _080D3344 @ =gStaticMotionGraphics+12
	adds r5, r5, r3
	ldr r0, _080D3348 @ =wStaticMotionPalIDs
	adds r4, r4, r0
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadPalette
	ldrb r1, [r7, #0x11]
	adds r1, #0xf5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	cmp r6, #0xf
	bhi _080D334C
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0xd]
	adds r0, #2
	strb r0, [r7, #0xd]
	b _080D358C
	.align 2, 0
_080D333C: .4byte gStaticMotionGraphics
_080D3340: .4byte wStaticGraphicTilenums
_080D3344: .4byte gStaticMotionGraphics+12
_080D3348: .4byte wStaticMotionPalIDs
_080D334C:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3352:
	ldrb r1, [r7, #0x11]
	adds r1, #0xf5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	movs r2, #0
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D336A
	b _080D358C
_080D336A:
	b _080D357C
_080D336C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3380
	b _080D358C
_080D3380:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xf8
	bl LoadBlink
	b _080D357C
_080D339C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0xf8
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D33B2
	b _080D358C
_080D33B2:
	movs r0, #0xf8
	bl ClearBlink
	b _080D357C
_080D33BA:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r1, r0
	movs r0, #0xf9
	bl LoadBlink
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D33DA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0xf9
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _080D33F0
	b _080D358C
_080D33F0:
	movs r0, #0xf9
	bl ClearBlink
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xfa
	bl LoadBlink
	b _080D357C
_080D3412:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0xfa
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D3428
	b _080D358C
_080D3428:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x64]
	ldr r5, _080D34A0 @ =0x08370DE8
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	lsls r1, r1, #7
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x68]
	adds r0, r7, #0
	adds r0, #0x64
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r7, #0x28]
	adds r0, #0x74
	movs r4, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	movs r0, #0x58
	bl PlaySound
	strb r4, [r7, #0x12]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3478:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r3, r0, #1
	strb r3, [r7, #0x12]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _080D34A8
	ldr r2, [r7, #0x28]
	ldr r1, _080D34A4 @ =gSineTable
	lsls r0, r3, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7, #0x5c]
	b _080D34EA
	.align 2, 0
_080D34A0: .4byte 0x08370DE8
_080D34A4: .4byte gSineTable
_080D34A8:
	cmp r0, #0x20
	bne _080D34C0
	ldr r1, [r7, #0x28]
	ldr r0, [r7, #0x5c]
	subs r0, #2
	lsls r0, r0, #8
	str r0, [r1, #0x78]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	b _080D3556
_080D34C0:
	cmp r0, #0x35
	bhi _080D34D0
	ldr r1, [r7, #0x28]
	ldr r0, [r7, #0x5c]
	subs r0, #4
	lsls r0, r0, #8
	str r0, [r1, #0x78]
	b _080D3556
_080D34D0:
	cmp r0, #0x3f
	bhi _080D34F4
	ldr r2, [r7, #0x28]
	ldr r1, _080D34F0 @ =gSineTable
	movs r0, #0x40
	subs r0, r0, r3
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7, #0x5c]
	subs r0, #4
_080D34EA:
	muls r0, r1, r0
	str r0, [r2, #0x78]
	b _080D3556
	.align 2, 0
_080D34F0: .4byte gSineTable
_080D34F4:
	movs r4, #0
	ldr r5, _080D3568 @ =0x08370DE8
_080D34F8:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #2
	bl FUN_080c5684
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _080D34F8
	ldr r0, [r7, #0x28]
	adds r0, #0x77
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xfa
	bl ClearBlink
	ldrb r4, [r7, #0x11]
	adds r4, #0xfb
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r4, #0
	bl LoadBlink
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3556:
	ldr r2, [r7, #0x28]
	ldrb r0, [r7, #0x12]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	b _080D358C
	.align 2, 0
_080D3568: .4byte 0x08370DE8
_080D356C:
	ldrb r0, [r7, #0x11]
	adds r0, #0xfb
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080D358C
_080D357C:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D358C
_080D3584:
	ldrb r0, [r7, #0x11]
	adds r0, #0xfb
	bl ClearBlink
_080D358C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor26_Update
Actor26_Update: @ 0x080D3594
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D360C
	cmp r0, #1
	bgt _080D368C
	cmp r0, #0
	bne _080D368C
	ldr r1, _080D3694 @ =wStaticGraphicTilenums
	adds r1, #0xa2
	ldrh r0, [r1]
	str r0, [r7, #0x64]
	ldr r5, _080D3698 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	ldrh r0, [r5]
	str r0, [r7, #0x68]
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	movs r6, #0
	ldr r0, _080D369C @ =0x00000305
	strh r0, [r1]
	movs r0, #8
	strh r0, [r5]
	ldr r4, _080D36A0 @ =0x00000654
	ldr r2, _080D36A4 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D36A8 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D360C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r1, [r7, #0x12]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D3628
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #3
	movs r1, #0
	bl FUN_080c5628
_080D3628:
	ldrb r1, [r7, #0x12]
	adds r1, #1
	strb r1, [r7, #0x12]
	ldr r2, [r7, #0x5c]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r2, r4
	str r2, [r7, #0x5c]
	ldr r3, _080D36AC @ =gSineTable
	lsls r0, r1, #0x19
	movs r4, #0x80
	lsls r4, r4, #0x17
	adds r0, r0, r4
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	adds r2, r2, r0
	str r2, [r7, #0x54]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, _080D36B0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D36B4 @ =0x000097FF
	adds r0, r0, r1
	cmp r2, r0
	blt _080D368C
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _080D3694 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	ldr r1, [r7, #0x64]
	strh r1, [r0]
	ldr r0, _080D3698 @ =wStaticMotionPalIDs
	adds r0, #0xa2
	ldr r1, [r7, #0x68]
	strh r1, [r0]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D368C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3694: .4byte wStaticGraphicTilenums
_080D3698: .4byte wStaticMotionPalIDs
_080D369C: .4byte 0x00000305
_080D36A0: .4byte 0x00000654
_080D36A4: .4byte gStaticMotionGraphics
_080D36A8: .4byte gStaticMotionGraphics+12
_080D36AC: .4byte gSineTable
_080D36B0: .4byte gStageRun+232
_080D36B4: .4byte 0x000097FF

	thumb_func_start Actor27_Update
Actor27_Update: @ 0x080D36B8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D36C4
	b _080D3890
_080D36C4:
	lsls r0, r0, #2
	ldr r1, _080D36D0 @ =_080D36D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D36D0: .4byte _080D36D4
_080D36D4: @ jump table
	.4byte _080D36FC @ case 0
	.4byte _080D3732 @ case 1
	.4byte _080D374C @ case 2
	.4byte _080D3760 @ case 3
	.4byte _080D378E @ case 4
	.4byte _080D37B4 @ case 5
	.4byte _080D37C6 @ case 6
	.4byte _080D37FA @ case 7
	.4byte _080D3828 @ case 8
	.4byte _080D3890 @ case 9
_080D36FC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r2, _080D3740 @ =wDynamicGraphicTilenums
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r2, r2, r3
	ldrh r0, [r2]
	str r0, [r4, #0x64]
	ldr r1, _080D3744 @ =wDynamicMotionPalIDs
	adds r1, r1, r3
	ldrh r0, [r1]
	str r0, [r4, #0x68]
	ldr r0, _080D3748 @ =0x00000305
	strh r0, [r2]
	movs r0, #9
	strh r0, [r1]
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3732:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D37A8
	b _080D379A
	.align 2, 0
_080D3740: .4byte wDynamicGraphicTilenums
_080D3744: .4byte wDynamicMotionPalIDs
_080D3748: .4byte 0x00000305
_080D374C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D375E
	b _080D3890
_080D375E:
	b _080D388A
_080D3760:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
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
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D378E:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D37A8
_080D379A:
	ldr r1, _080D37B0 @ =0x0000A408
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D37A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080D3890
	.align 2, 0
_080D37B0: .4byte 0x0000A408
_080D37B4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D3890
	b _080D388A
_080D37C6:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	strb r2, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D37FA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D3890
	ldr r1, _080D3820 @ =0x0000A405
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080D3824 @ =0xFFFFFB00
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	b _080D388A
	.align 2, 0
_080D3820: .4byte 0x0000A405
_080D3824: .4byte 0xFFFFFB00
_080D3828:
	ldr r0, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	cmp r1, #0
	ble _080D385A
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _080D3898 @ =0x0000A406
	cmp r0, r1
	beq _080D385A
	adds r0, r4, #0
	bl SetMotion
_080D385A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	movs r1, #0xd0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r0, r1
	bge _080D3890
	ldr r0, _080D389C @ =wDynamicGraphicTilenums
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r4, #0x64]
	strh r1, [r0]
	ldr r0, _080D38A0 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	ldr r1, [r4, #0x68]
	strh r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080D388A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3890:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D3898: .4byte 0x0000A406
_080D389C: .4byte wDynamicGraphicTilenums
_080D38A0: .4byte wDynamicMotionPalIDs

	thumb_func_start initActor28
initActor28: @ 0x080D38A4
	push {r4, lr}
	ldr r2, _080D38E0 @ =gWindowRegBuffer
	ldrh r3, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	strb r4, [r2, #0xd]
	ldrb r3, [r2, #0xe]
	movs r1, #0xfe
	orrs r1, r3
	strb r1, [r2, #0xe]
	strb r4, [r0, #0x12]
	ldr r2, _080D38E4 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D38E0: .4byte gWindowRegBuffer
_080D38E4: .4byte gSolidFnTable

	thumb_func_start Actor28_Update
Actor28_Update: @ 0x080D38E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bhi _080D39A6
	lsls r0, r0, #2
	ldr r1, _080D38FC @ =_080D3900
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D38FC: .4byte _080D3900
_080D3900: @ jump table
	.4byte _080D3914 @ case 0
	.4byte _080D392E @ case 1
	.4byte _080D3960 @ case 2
	.4byte _080D3976 @ case 3
	.4byte _080D39A6 @ case 4
_080D3914:
	movs r4, #0
	str r4, [r6, #0x54]
	movs r0, #0x93
	lsls r0, r0, #8
	str r0, [r6, #0x58]
	movs r0, #0x97
	lsls r0, r0, #1
	bl PlaySound
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D392E:
	ldr r2, _080D395C @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	adds r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0xf
	bls _080D39A6
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	movs r0, #0x20
	strb r0, [r6, #0x13]
	b _080D39A6
	.align 2, 0
_080D395C: .4byte gSineTable
_080D3960:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D39A6
	movs r0, #0x20
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3976:
	ldr r2, _080D39E8 @ =gSineTable
	ldrb r1, [r6, #0x13]
	lsls r0, r1, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	str r0, [r6, #0x54]
	subs r1, #1
	strb r1, [r6, #0x13]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080D39A6
	ldr r2, _080D39EC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080D39F0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D39A6:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r5, _080D39EC @ =gWindowRegBuffer
	ldr r2, [r6, #0x54]
	asrs r2, r2, #8
	movs r3, #1
	ands r3, r0
	lsls r0, r3, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xbc
	movs r4, #0xff
	ands r1, r4
	movs r0, #0xbc
	subs r0, r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5, #6]
	ldr r0, [r6, #0x58]
	asrs r0, r0, #8
	lsls r3, r3, #2
	adds r0, r0, r3
	ands r0, r4
	strh r0, [r5, #0xa]
	ldr r1, _080D39F4 @ =gPaletteManager
	ldr r2, _080D39F8 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D39E8: .4byte gSineTable
_080D39EC: .4byte gWindowRegBuffer
_080D39F0: .4byte 0x0000BFFF
_080D39F4: .4byte gPaletteManager
_080D39F8: .4byte 0x00007FFF

	thumb_func_start Actor29_Update
Actor29_Update: @ 0x080D39FC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D3A7E
	cmp r7, #1
	bgt _080D3A12
	cmp r7, #0
	beq _080D3A1A
	b _080D3B2E
_080D3A12:
	cmp r7, #2
	bne _080D3A18
	b _080D3B24
_080D3A18:
	b _080D3B2E
_080D3A1A:
	ldr r0, [r6, #0x54]
	ldr r1, _080D3AF8 @ =0xFFFF1000
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [r6, #0x58]
	ldr r0, _080D3AFC @ =wStaticGraphicTilenums
	movs r5, #0
	ldr r1, _080D3B00 @ =0x000003CE
	strh r1, [r0, #2]
	ldr r4, _080D3B04 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r4, #2]
	ldr r0, _080D3B08 @ =0x085D790C
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3B0C @ =0x085D7918
	ldrh r1, [r4, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #8
	bl AppendQuake
	strb r5, [r6, #0x12]
	str r7, [r6, #0x60]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D3A7E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x60]
	adds r1, #0x10
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r4, r6, #0
	adds r4, #0x54
	movs r0, #2
	adds r1, r4, #0
	bl AppendQuake
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080D3AD6
	ldr r0, [r6, #0x54]
	ldr r1, _080D3B10 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, _080D3B14 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D3B18 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D3B1C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080D3AD6:
	ldr r0, _080D3B20 @ =gStageRun+232
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bls _080D3B2E
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D3B2E
	.align 2, 0
_080D3AF8: .4byte 0xFFFF1000
_080D3AFC: .4byte wStaticGraphicTilenums
_080D3B00: .4byte 0x000003CE
_080D3B04: .4byte wStaticMotionPalIDs
_080D3B08: .4byte 0x085D790C
_080D3B0C: .4byte 0x085D7918
_080D3B10: .4byte 0xFFFFC000
_080D3B14: .4byte RNG_0202f388
_080D3B18: .4byte 0x000343FD
_080D3B1C: .4byte 0x00269EC3
_080D3B20: .4byte gStageRun+232
_080D3B24:
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3B2E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor30_Update
Actor30_Update: @ 0x080D3B38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D3C16
	cmp r0, #1
	bgt _080D3B56
	cmp r0, #0
	beq _080D3B64
	b _080D3D10
_080D3B56:
	cmp r0, #2
	bne _080D3B5C
	b _080D3C8C
_080D3B5C:
	cmp r0, #3
	bne _080D3B62
	b _080D3D08
_080D3B62:
	b _080D3D10
_080D3B64:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CD4 @ =0xFFFF6000
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r2, _080D3CD8 @ =0x00000101
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r1, _080D3CDC @ =wStaticGraphicTilenums
	ldr r0, _080D3CE0 @ =0x000003CE
	strh r0, [r1, #2]
	ldr r6, _080D3CE4 @ =wStaticMotionPalIDs
	movs r0, #9
	strh r0, [r6, #2]
	movs r4, #0xb9
	lsls r0, r4, #1
	mov r8, r0
	adds r2, r1, #0
	add r2, r8
	mov sl, r2
	ldr r0, _080D3CE8 @ =0x000003AF
	strh r0, [r2]
	add r8, r6
	movs r0, #0xa
	mov r2, r8
	strh r0, [r2]
	ldr r5, _080D3CEC @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0x14
	ldrh r1, [r1, #2]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D3CF0 @ =gStaticMotionGraphics+12
	mov sb, r0
	adds r0, #0x14
	ldrh r1, [r6, #2]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	bl LoadPalette
	lsls r4, r4, #4
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r5, r4, r5
	mov r2, sl
	ldrh r1, [r2]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, sb
	mov r2, r8
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C16:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0x10
	bl AppendQuake
	ldr r5, _080D3CF4 @ =RNG_0202f388
	mov r6, sp
	movs r4, #3
_080D3C38:
	ldr r0, [r7, #0x54]
	ldr r1, _080D3CF8 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5]
	ldr r0, _080D3CFC @ =0x000343FD
	muls r1, r0, r1
	ldr r2, _080D3D00 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsls r1, r1, #3
	lsrs r1, r1, #0x14
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r6, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	subs r4, #1
	cmp r4, #0
	bge _080D3C38
	ldr r0, _080D3D04 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	str r0, [r7, #0x64]
	adds r0, r7, #0
	bl InitRotatableMotion
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x68]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D3C8C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r1, [r7, #0x60]
	adds r1, #1
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x68]
	asrs r0, r0, #0xb
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r1, [r7, #0x60]
	asrs r2, r1, #2
	ldr r0, [r7, #0x58]
	subs r0, r0, r2
	str r0, [r7, #0x58]
	asrs r1, r1, #1
	ldr r0, [r7, #0x64]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, _080D3D04 @ =pZero2
	ldr r1, [r1]
	str r0, [r1, #0x58]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D10
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D3D10
	.align 2, 0
_080D3CD4: .4byte 0xFFFF6000
_080D3CD8: .4byte 0x00000101
_080D3CDC: .4byte wStaticGraphicTilenums
_080D3CE0: .4byte 0x000003CE
_080D3CE4: .4byte wStaticMotionPalIDs
_080D3CE8: .4byte 0x000003AF
_080D3CEC: .4byte gStaticMotionGraphics
_080D3CF0: .4byte gStaticMotionGraphics+12
_080D3CF4: .4byte RNG_0202f388
_080D3CF8: .4byte 0xFFFFC000
_080D3CFC: .4byte 0x000343FD
_080D3D00: .4byte 0x00269EC3
_080D3D04: .4byte pZero2
_080D3D08:
	ldr r0, _080D3D4C @ =pZero2
	ldr r1, [r0]
	ldr r0, [r7, #0x64]
	str r0, [r1, #0x58]
_080D3D10:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bhi _080D3D3A
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3D30
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080c5628
_080D3D30:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
_080D3D3A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D3D4C: .4byte pZero2

	thumb_func_start Actor31_Update
Actor31_Update: @ 0x080D3D50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xd]
	cmp r5, #1
	beq _080D3D98
	cmp r5, #1
	bgt _080D3DD8
	cmp r5, #0
	bne _080D3DD8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r4, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x74
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r4, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3D98:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldr r3, [r4, #0x28]
	ldr r2, _080D3DE0 @ =gSineTable
	movs r1, #0xfe
	ands r0, r1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	str r0, [r3, #0x78]
	ldr r2, [r4, #0x28]
	ldrb r0, [r4, #0x12]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0xc
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x81
	bne _080D3DD8
	ldr r0, [r4, #0x28]
	adds r0, #0x77
	strb r3, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3DD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3DE0: .4byte gSineTable

	thumb_func_start initActor32
initActor32: @ 0x080D3DE4
	push {r4, lr}
	ldr r2, _080D3E20 @ =gWindowRegBuffer
	ldrh r3, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	movs r4, #0
	orrs r1, r3
	strh r1, [r2]
	movs r1, #4
	strb r1, [r2, #0xd]
	ldrb r3, [r2, #0xe]
	movs r1, #0xfe
	orrs r1, r3
	strb r1, [r2, #0xe]
	strb r4, [r0, #0x12]
	ldr r2, _080D3E24 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	bl Actor_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D3E20: .4byte gWindowRegBuffer
_080D3E24: .4byte gSolidFnTable

	thumb_func_start Actor32_Update
Actor32_Update: @ 0x080D3E28
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xd]
	ldr r5, _080D3E40 @ =gWindowRegBuffer
	cmp r0, #4
	bhi _080D3EDC
	lsls r0, r0, #2
	ldr r1, _080D3E44 @ =_080D3E48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3E40: .4byte gWindowRegBuffer
_080D3E44: .4byte _080D3E48
_080D3E48: @ jump table
	.4byte _080D3E5C @ case 0
	.4byte _080D3E72 @ case 1
	.4byte _080D3E94 @ case 2
	.4byte _080D3EC0 @ case 3
	.4byte _080D3EDC @ case 4
_080D3E5C:
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r3, #0x54]
	movs r0, #0x92
	lsls r0, r0, #8
	str r0, [r3, #0x58]
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E72:
	ldr r0, [r3, #0x58]
	ldr r1, _080D3F08 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3E94:
	ldr r1, _080D3F10 @ =gSineTable
	ldrb r0, [r3, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb8
	muls r0, r1, r0
	str r0, [r3, #0x54]
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0x3f
	bls _080D3EDC
	movs r0, #0x10
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EC0:
	ldrb r0, [r3, #0x13]
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	ldr r5, _080D3F0C @ =gWindowRegBuffer
	cmp r0, #0
	bne _080D3EDC
	ldrh r0, [r5]
	ldr r1, _080D3F14 @ =0x0000BFFF
	ands r1, r0
	strh r1, [r5]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_080D3EDC:
	ldrb r0, [r3, #0x12]
	adds r0, #1
	strb r0, [r3, #0x12]
	ldr r2, [r3, #0x54]
	asrs r2, r2, #8
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r1, r2, #0
	adds r1, #0xc0
	adds r4, r5, #0
	movs r0, #0xc0
	subs r0, r0, r2
	lsls r2, r0, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xf0
	bgt _080D3F18
	movs r0, #0xff
	ands r0, r1
	b _080D3F1A
	.align 2, 0
_080D3F08: .4byte 0xFFFFF800
_080D3F0C: .4byte gWindowRegBuffer
_080D3F10: .4byte gSineTable
_080D3F14: .4byte 0x0000BFFF
_080D3F18:
	movs r0, #0xf0
_080D3F1A:
	orrs r0, r2
	strh r0, [r4, #6]
	ldr r1, [r3, #0x58]
	asrs r1, r1, #8
	ldrb r2, [r3, #0x12]
	movs r0, #1
	ands r0, r2
	lsls r0, r0, #3
	subs r1, r1, r0
	adds r2, r0, #0
	adds r2, #0x93
	movs r0, #0xff
	ands r2, r0
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _080D3F40
	lsls r0, r0, #8
	orrs r2, r0
_080D3F40:
	strh r2, [r5, #0xa]
	ldr r1, _080D3F50 @ =gPaletteManager
	ldr r2, _080D3F54 @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F50: .4byte gPaletteManager
_080D3F54: .4byte 0x00007FFF

	thumb_func_start Actor33_Update
Actor33_Update: @ 0x080D3F58
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0xe
	bls _080D3F64
	b _080D4108
_080D3F64:
	lsls r0, r0, #2
	ldr r1, _080D3F70 @ =_080D3F74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F70: .4byte _080D3F74
_080D3F74: @ jump table
	.4byte _080D3FB0 @ case 0
	.4byte _080D3FC8 @ case 1
	.4byte _080D4006 @ case 2
	.4byte _080D402C @ case 3
	.4byte _080D403E @ case 4
	.4byte _080D405C @ case 5
	.4byte _080D406A @ case 6
	.4byte _080D4080 @ case 7
	.4byte _080D4092 @ case 8
	.4byte _080D40A6 @ case 9
	.4byte _080D40B6 @ case 10
	.4byte _080D40C4 @ case 11
	.4byte _080D40D4 @ case 12
	.4byte _080D40F4 @ case 13
	.4byte _080D4102 @ case 14
_080D3FB0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D3FC8:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D3FEA
	b _080D4108
_080D3FEA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D4058 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4006:
	ldr r1, _080D404C @ =gPaletteManager
	ldr r0, _080D4050 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080D4054 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D402C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D4108
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D403E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	b _080D40E6
	.align 2, 0
_080D404C: .4byte gPaletteManager
_080D4050: .4byte 0x00000404
_080D4054: .4byte 0x00000406
_080D4058: .4byte 0x00003503
_080D405C:
	ldr r1, _080D407C @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D406A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4108
	b _080D40EC
	.align 2, 0
_080D407C: .4byte 0x00003501
_080D4080:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4092:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4108
	b _080D40EC
_080D40A6:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40B6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	b _080D40E6
_080D40C4:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D40D4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	subs r0, #0x50
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x20
_080D40E6:
	ands r0, r1
	cmp r0, #0
	beq _080D4108
_080D40EC:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D4108
_080D40F4:
	ldr r1, _080D4110 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4102:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D4108:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D4110: .4byte 0x00003303

	thumb_func_start Actor34_Update
Actor34_Update: @ 0x080D4114
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D4124
	cmp r0, #1
	beq _080D418C
	b _080D4220
_080D4124:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D41EC @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r4, #0xb8
	ldr r1, _080D41F0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D41F4 @ =0x00000385
	strh r0, [r1]
	ldr r5, _080D41F8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080D41FC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D4200 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D418C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D41A4
	ldr r1, _080D4204 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D41A4:
	ldr r4, _080D4208 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r7, _080D420C @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _080D4210 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D41C8
	ldr r1, _080D4214 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D41C8:
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D4220
	ldr r0, [r4]
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4218
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080D421E
	.align 2, 0
_080D41EC: .4byte 0xFFFFE800
_080D41F0: .4byte wStaticGraphicTilenums
_080D41F4: .4byte 0x00000385
_080D41F8: .4byte wStaticMotionPalIDs
_080D41FC: .4byte gStaticMotionGraphics
_080D4200: .4byte gStaticMotionGraphics+12
_080D4204: .4byte 0x0000B802
_080D4208: .4byte RNG_0202f388
_080D420C: .4byte 0x000343FD
_080D4210: .4byte 0x00269EC3
_080D4214: .4byte 0x0000B803
_080D4218:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D421E:
	strb r0, [r6, #0xa]
_080D4220:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor35_Update
Actor35_Update: @ 0x080D4228
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D4234
	b _080D43B6
_080D4234:
	lsls r0, r0, #2
	ldr r1, _080D4240 @ =_080D4244
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4240: .4byte _080D4244
_080D4244: @ jump table
	.4byte _080D426C @ case 0
	.4byte _080D4284 @ case 1
	.4byte _080D42A4 @ case 2
	.4byte _080D42C0 @ case 3
	.4byte _080D42D4 @ case 4
	.4byte _080D42F4 @ case 5
	.4byte _080D4302 @ case 6
	.4byte _080D4324 @ case 7
	.4byte _080D434C @ case 8
	.4byte _080D436C @ case 9
_080D426C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, _080D429C @ =0x0000C20D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D4284:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D4298
	b _080D43B6
_080D4298:
	ldr r1, _080D42A0 @ =0x0000C20C
	b _080D433A
	.align 2, 0
_080D429C: .4byte 0x0000C20D
_080D42A0: .4byte 0x0000C20C
_080D42A4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D42B8
	b _080D43B6
_080D42B8:
	ldr r1, _080D42BC @ =0x0000C201
	b _080D433A
	.align 2, 0
_080D42BC: .4byte 0x0000C201
_080D42C0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	b _080D4336
_080D42D4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D42F0 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D42F0: .4byte 0x0000C206
_080D42F4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	b _080D4330
_080D4302:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4320 @ =0x0000C201
	adds r0, r4, #0
	bl SetMotion
	b _080D4344
	.align 2, 0
_080D4320: .4byte 0x0000C201
_080D4324:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
_080D4330:
	ands r0, r1
	cmp r0, #0
	beq _080D43B6
_080D4336:
	movs r1, #0xc2
	lsls r1, r1, #8
_080D433A:
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
_080D4344:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D43B6
_080D434C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D43B6
	ldr r1, _080D4390 @ =0x0000C206
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D436C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, [r4, #0x18]
	ldr r0, [r0, #4]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080D4382
	movs r2, #1
_080D4382:
	cmp r2, #0
	beq _080D4394
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080D439A
	.align 2, 0
_080D4390: .4byte 0x0000C206
_080D4394:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080D439A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
_080D43B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Actor36_Update
Actor36_Update: @ 0x080D43BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _080D43CC
	cmp r0, #1
	beq _080D4430
	b _080D4436
_080D43CC:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xc2
	ldr r0, _080D443C @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x88
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4440 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #5
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0xc2
	lsls r4, r4, #2
	ldr r2, _080D4444 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D4448 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4430:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080D4436:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D443C: .4byte wStaticGraphicTilenums
_080D4440: .4byte wStaticMotionPalIDs
_080D4444: .4byte gStaticMotionGraphics
_080D4448: .4byte gStaticMotionGraphics+12

	thumb_func_start Actor37_Update
Actor37_Update: @ 0x080D444C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D4458
	b _080D45E4
_080D4458:
	lsls r0, r0, #2
	ldr r1, _080D4464 @ =_080D4468
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4464: .4byte _080D4468
_080D4468: @ jump table
	.4byte _080D447C @ case 0
	.4byte _080D454C @ case 1
	.4byte _080D459C @ case 2
	.4byte _080D45BC @ case 3
	.4byte _080D45E4 @ case 4
_080D447C:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	bne _080D44F4
	movs r4, #0x82
	ldr r0, _080D44E4 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x98
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D44E8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x82
	lsls r4, r4, #2
	ldr r2, _080D44EC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D44F0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	b _080D4546
	.align 2, 0
_080D44E4: .4byte wStaticGraphicTilenums
_080D44E8: .4byte wStaticMotionPalIDs
_080D44EC: .4byte gStaticMotionGraphics
_080D44F0: .4byte gStaticMotionGraphics+12
_080D44F4:
	movs r4, #0x8c
	ldr r1, _080D4584 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D4588 @ =0x00000296
	strh r0, [r1]
	ldr r5, _080D458C @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r2, _080D4590 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D4594 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D4598 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
_080D4546:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D454C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D45E4
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D45DE
	.align 2, 0
_080D4584: .4byte wStaticGraphicTilenums
_080D4588: .4byte 0x00000296
_080D458C: .4byte wStaticMotionPalIDs
_080D4590: .4byte gStaticMotionGraphics
_080D4594: .4byte gStaticMotionGraphics+12
_080D4598: .4byte 0x00008C05
_080D459C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D45E4
	ldr r1, _080D45B8 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	b _080D45DE
	.align 2, 0
_080D45B8: .4byte 0x00008C07
_080D45BC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x54]
	ldr r0, _080D45EC @ =0xFFFFFF00
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldr r0, _080D45F0 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D45F4 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	bge _080D45E4
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D45DE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D45E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D45EC: .4byte 0xFFFFFF00
_080D45F0: .4byte gStageRun+232
_080D45F4: .4byte 0xFFFF7000

	thumb_func_start Actor38_Update
Actor38_Update: @ 0x080D45F8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D467C
	cmp r0, #1
	ble _080D4608
	b _080D4752
_080D4608:
	cmp r0, #0
	beq _080D460E
	b _080D4752
_080D460E:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4720 @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4724 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4728 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #7
	strh r0, [r5]
	ldr r4, _080D472C @ =0x00000654
	ldr r2, _080D4730 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	bl LoadGraphic
	ldr r0, _080D4734 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D467C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r5, _080D4738 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, [r7, #0x5c]
	adds r4, r1, r0
	str r4, [r7, #0x54]
	lsls r0, r2, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r7, #0x68]
	adds r3, r1, r0
	str r3, [r7, #0x58]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _080D46C2
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl FUN_080c5628
_080D46C2:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4744
	ldrb r1, [r7, #0x13]
	adds r1, #1
	strb r1, [r7, #0x13]
	ldr r2, [r7, #0x5c]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r2, r2, r1
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x68]
	ldr r2, _080D473C @ =0xFFFFFF00
	adds r0, r0, r2
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4740 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080D4752
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D4752
	.align 2, 0
_080D4720: .4byte 0xFFFFB000
_080D4724: .4byte wStaticGraphicTilenums
_080D4728: .4byte wStaticMotionPalIDs
_080D472C: .4byte 0x00000654
_080D4730: .4byte gStaticMotionGraphics
_080D4734: .4byte gStaticMotionGraphics+12
_080D4738: .4byte gSineTable
_080D473C: .4byte 0xFFFFFF00
_080D4740: .4byte gStageRun+232
_080D4744:
	ldr r0, [r7, #0x68]
	lsls r1, r0, #7
	subs r1, r1, r0
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	asrs r1, r1, #7
	str r1, [r7, #0x68]
_080D4752:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Actor39_Update
Actor39_Update: @ 0x080D4758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bls _080D4768
	b _080D4976
_080D4768:
	lsls r0, r0, #2
	ldr r1, _080D4774 @ =_080D4778
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4774: .4byte _080D4778
_080D4778: @ jump table
	.4byte _080D47A0 @ case 0
	.4byte _080D47B8 @ case 1
	.4byte _080D481C @ case 2
	.4byte _080D4870 @ case 3
	.4byte _080D48A2 @ case 4
	.4byte _080D48D0 @ case 5
	.4byte _080D48FE @ case 6
	.4byte _080D4930 @ case 7
	.4byte _080D4954 @ case 8
	.4byte _080D4976 @ case 9
_080D47A0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D47B8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _080D47CE
	b _080D4976
_080D47CE:
	ldrb r1, [r7, #0xa]
	movs r0, #4
	movs r6, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080D4818 @ =0x08370C68
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, #0
	bl SetMotion
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	mov r1, r8
	ands r2, r1
	adds r0, r5, #0
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	str r6, [r7, #0x2c]
	movs r0, #0x20
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4818: .4byte 0x08370C68
_080D481C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	bne _080D4830
	adds r0, r7, #0
	bl CreateAfterImages
	str r0, [r7, #0x2c]
_080D4830:
	ldr r0, [r7, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D484A
	b _080D4976
_080D484A:
	ldr r0, [r7, #0x2c]
	cmp r0, #0
	beq _080D4852
	strb r1, [r0, #0x11]
_080D4852:
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xa
	bl PlaySound
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [r7, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D4870:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, [r7, #0x60]
	adds r1, r1, r2
	str r1, [r7, #0x58]
	adds r2, #0x40
	str r2, [r7, #0x60]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D4976
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	str r0, [r7, #0x58]
	movs r0, #0
	str r0, [r7, #0x60]
	b _080D4970
_080D48A2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #4
	subs r1, r1, r0
	asrs r1, r1, #4
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4976
	adds r0, r7, #0
	movs r1, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r7, #0x12]
	b _080D4970
_080D48D0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D4976
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	b _080D4970
_080D48FE:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	asrs r1, r1, #2
	str r1, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x54]
	cmp r1, #3
	bgt _080D4976
	ldr r1, _080D492C @ =0x00003F05
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	b _080D4970
	.align 2, 0
_080D492C: .4byte 0x00003F05
_080D4930:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D4976
	ldr r1, _080D4950 @ =0x00003501
	adds r0, r7, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r7, #0x12]
	b _080D4970
	.align 2, 0
_080D4950: .4byte 0x00003501
_080D4954:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D4968
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _080D4976
_080D4968:
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D4970:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4976:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d4980
FUN_080d4980: @ 0x080D4980
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xf
	bls _080D498C
	b _080D4EFA
_080D498C:
	lsls r0, r0, #2
	ldr r1, _080D4998 @ =_080D499C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4998: .4byte _080D499C
_080D499C: @ jump table
	.4byte _080D49DC @ case 0
	.4byte _080D4A0A @ case 1
	.4byte _080D4A6C @ case 2
	.4byte _080D4AD8 @ case 3
	.4byte _080D4B58 @ case 4
	.4byte _080D4BEC @ case 5
	.4byte _080D4C02 @ case 6
	.4byte _080D4C10 @ case 7
	.4byte _080D4C28 @ case 8
	.4byte _080D4C3A @ case 9
	.4byte _080D4C50 @ case 10
	.4byte _080D4C82 @ case 11
	.4byte _080D4D60 @ case 12
	.4byte _080D4E64 @ case 13
	.4byte _080D4E84 @ case 14
	.4byte _080D4EDC @ case 15
_080D49DC:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r0, #0
	movs r1, #8
	bl LoadZeroPalette
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r6, #0x20]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	ldr r1, _080D4A64 @ =0x00003F05
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4A0A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D4A1E
	b _080D4EFA
_080D4A1E:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4A68 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r1, [r0]
	ldr r0, [r6, #0x28]
	str r1, [r0, #0x78]
	strb r1, [r6, #0x12]
	strb r1, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4A64: .4byte 0x00003F05
_080D4A68: .4byte 0xFFFFF400
_080D4A6C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldr r2, [r6, #0x28]
	ldr r1, _080D4AC0 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r2, #0x78]
	ldr r2, [r6, #0x28]
	ldrb r0, [r6, #0x13]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4AC4
	ldrb r1, [r6, #0x12]
	movs r0, #0x12
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bge _080D4ABA
	b _080D4EFA
_080D4ABA:
	adds r0, r1, #3
	strb r0, [r6, #0x12]
	b _080D4EFA
	.align 2, 0
_080D4AC0: .4byte gSineTable
_080D4AC4:
	ldrb r0, [r6, #0x12]
	cmp r0, #3
	bls _080D4AD0
	subs r0, #3
	strb r0, [r6, #0x12]
	b _080D4EFA
_080D4AD0:
	ldr r0, [r6, #0x28]
	adds r0, #0x77
	strb r3, [r0]
	b _080D4EF4
_080D4AD8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D4AEC
	b _080D4EFA
_080D4AEC:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4B50 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4B54 @ =0x08370C80
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r6, #0x12]
	strb r5, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4B50: .4byte 0xFFFFF400
_080D4B54: .4byte 0x08370C80
_080D4B58:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0x12]
	cmp r0, #0x3f
	bhi _080D4B6E
	adds r0, #0x10
	strb r0, [r6, #0x12]
_080D4B6E:
	ldrb r1, [r6, #0x13]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4BBC
	cmp r1, #3
	bls _080D4B98
	ldr r2, _080D4BAC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D4BB0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D4BB4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	bne _080D4BBC
_080D4B98:
	ldr r2, [r6, #0x28]
	ldr r1, _080D4BB8 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	str r0, [r2, #0x78]
	b _080D4BC2
	.align 2, 0
_080D4BAC: .4byte RNG_0202f388
_080D4BB0: .4byte 0x000343FD
_080D4BB4: .4byte 0x00269EC3
_080D4BB8: .4byte gSineTable
_080D4BBC:
	ldr r1, [r6, #0x28]
	movs r0, #0
	str r0, [r1, #0x78]
_080D4BC2:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x40
	bhi _080D4BCA
	b _080D4EFA
_080D4BCA:
	ldr r0, [r6, #0x28]
	adds r0, #0x77
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	b _080D4EF4
_080D4BEC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080D4C00
	b _080D4EFA
_080D4C00:
	b _080D4EF4
_080D4C02:
	ldr r1, _080D4C24 @ =0x00003501
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C10:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D4C22
	b _080D4EFA
_080D4C22:
	b _080D4EF4
	.align 2, 0
_080D4C24: .4byte 0x00003501
_080D4C28:
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C3A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D4C4E
	b _080D4EFA
_080D4C4E:
	b _080D4EF4
_080D4C50:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4CD0 @ =0x08370C98
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D4C82:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	cmp r0, #0
	beq _080D4CAA
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4CAA
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
_080D4CAA:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D4CE4
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ands r0, r1
	cmp r0, #0
	beq _080D4CD4
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	b _080D4CDE
	.align 2, 0
_080D4CD0: .4byte 0x08370C98
_080D4CD4:
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
_080D4CDE:
	ldr r0, _080D4D54 @ =0x0000013B
	bl PlaySound
_080D4CE4:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080D4CF2
	b _080D4EFA
_080D4CF2:
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	ldr r1, _080D4D58 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4D5C @ =0x08370C80
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #3
	movs r2, #0
	bl CreateVFX39
	str r0, [r6, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r6, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r6, #0x12]
	strb r5, [r6, #0x13]
	b _080D4EF4
	.align 2, 0
_080D4D54: .4byte 0x0000013B
_080D4D58: .4byte 0xFFFFF400
_080D4D5C: .4byte 0x08370C80
_080D4D60:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	cmp r0, #0
	beq _080D4D88
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4D88
	adds r0, r6, #0
	movs r1, #0
	bl SetMotion
_080D4D88:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0x12]
	cmp r0, #0x3f
	bhi _080D4D98
	adds r0, #0x10
	strb r0, [r6, #0x12]
_080D4D98:
	ldrb r1, [r6, #0x13]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4DE8
	cmp r1, #3
	bls _080D4DC2
	ldr r2, _080D4DD8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D4DDC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D4DE0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	bne _080D4DE8
_080D4DC2:
	ldr r2, [r6, #0x28]
	ldr r1, _080D4DE4 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	str r0, [r2, #0x78]
	b _080D4DEE
	.align 2, 0
_080D4DD8: .4byte RNG_0202f388
_080D4DDC: .4byte 0x000343FD
_080D4DE0: .4byte 0x00269EC3
_080D4DE4: .4byte gSineTable
_080D4DE8:
	ldr r1, [r6, #0x28]
	movs r0, #0
	str r0, [r1, #0x78]
_080D4DEE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x40
	bhi _080D4DF6
	b _080D4EFA
_080D4DF6:
	ldr r1, [r6, #0x28]
	adds r1, #0x77
	movs r2, #0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080D4E34
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4E30 @ =0x08370C98
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xb
	b _080D4EF8
	.align 2, 0
_080D4E30: .4byte 0x08370C98
_080D4E34:
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D4E60 @ =0x08370CB0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xd4
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	b _080D4EF4
	.align 2, 0
_080D4E60: .4byte 0x08370CB0
_080D4E64:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D4EFA
	ldr r1, _080D4E80 @ =0x00003F05
	adds r0, r6, #0
	bl SetMotion
	b _080D4EF4
	.align 2, 0
_080D4E80: .4byte 0x00003F05
_080D4E84:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _080D4EFA
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldr r3, _080D4ED0 @ =gStageRun
	ldrh r2, [r3, #8]
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _080D4EC2
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080D4EC2
	ldr r0, _080D4ED4 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080D4EC2:
	ldr r1, _080D4ED8 @ =0x08370E08
	adds r0, r6, #0
	bl CreateBossExplosion
	str r0, [r6, #0x2c]
	b _080D4EF4
	.align 2, 0
_080D4ED0: .4byte gStageRun
_080D4ED4: .4byte 0x0000FFFE
_080D4ED8: .4byte 0x08370E08
_080D4EDC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080D4EFA
	ldr r2, _080D4F00 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_080D4EF4:
	ldrb r0, [r6, #0xd]
	adds r0, #1
_080D4EF8:
	strb r0, [r6, #0xd]
_080D4EFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D4F00: .4byte gStageRun

	thumb_func_start FUN_080d4f04
FUN_080d4f04: @ 0x080D4F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bls _080D4F14
	b _080D50D2
_080D4F14:
	lsls r0, r0, #2
	ldr r1, _080D4F20 @ =_080D4F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4F20: .4byte _080D4F24
_080D4F24: @ jump table
	.4byte _080D4F38 @ case 0
	.4byte _080D4FAC @ case 1
	.4byte _080D5008 @ case 2
	.4byte _080D5036 @ case 3
	.4byte _080D505C @ case 4
_080D4F38:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4FF0 @ =0xFFFFB800
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4FF4 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0x8c
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4FF8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #5
	strh r0, [r5]
	ldr r4, _080D4FFC @ =0x00000654
	ldr r2, _080D5000 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5004 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4FAC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r1, [r7, #0x13]
	movs r0, #0x13
	ldrsb r0, [r7, r0]
	cmp r0, #0
	blt _080D4FD2
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, #2
	strh r0, [r1]
_080D4FD2:
	ldr r1, [r7, #0x60]
	lsls r0, r1, #6
	subs r0, r0, r1
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #6
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5050
	.align 2, 0
_080D4FF0: .4byte 0xFFFFB800
_080D4FF4: .4byte wStaticGraphicTilenums
_080D4FF8: .4byte wStaticMotionPalIDs
_080D4FFC: .4byte 0x00000654
_080D5000: .4byte gStaticMotionGraphics
_080D5004: .4byte gStaticMotionGraphics+12
_080D5008:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080D5028
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #5
	movs r1, #0
	bl FUN_080c5628
_080D5028:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5054
_080D5036:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	ldr r0, [r7, #0x5c]
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x60]
	str r0, [r7, #0x68]
_080D5050:
	movs r0, #0
	strb r0, [r7, #0x13]
_080D5054:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D50D2
_080D505C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r6, _080D510C @ =RNG_0202f388
	ldr r0, [r6]
	ldr r4, _080D5110 @ =0x000343FD
	mov r8, r4
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _080D5114 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	mov r1, r8
	muls r1, r4, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r6]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #5
	adds r0, r7, #0
	bl ForceEntityPalette
_080D50D2:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D5118 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D510C: .4byte RNG_0202f388
_080D5110: .4byte 0x000343FD
_080D5114: .4byte 0x00269EC3
_080D5118: .4byte gSineTable

	thumb_func_start FUN_080d511c
FUN_080d511c: @ 0x080D511C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bls _080D5128
	b _080D5438
_080D5128:
	lsls r0, r0, #2
	ldr r1, _080D5134 @ =_080D5138
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5134: .4byte _080D5138
_080D5138: @ jump table
	.4byte _080D5164 @ case 0
	.4byte _080D5180 @ case 1
	.4byte _080D51B0 @ case 2
	.4byte _080D51EC @ case 3
	.4byte _080D521C @ case 4
	.4byte _080D5260 @ case 5
	.4byte _080D52BC @ case 6
	.4byte _080D5318 @ case 7
	.4byte _080D5380 @ case 8
	.4byte _080D53B8 @ case 9
	.4byte _080D5408 @ case 10
_080D5164:
	ldr r0, _080D51A0 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D51A4 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D5180:
	ldr r1, _080D51A8 @ =0x0000BE03
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D5192
	b _080D5438
_080D5192:
	ldr r1, _080D51AC @ =0x0000BE14
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	str r0, [r5, #0x5c]
	b _080D53F8
	.align 2, 0
_080D51A0: .4byte wDynamicGraphicTilenums
_080D51A4: .4byte wDynamicMotionPalIDs
_080D51A8: .4byte 0x0000BE03
_080D51AC: .4byte 0x0000BE14
_080D51B0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	ldr r0, _080D51E4 @ =0x000003FF
	cmp r1, r0
	bgt _080D51C4
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D51C4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D51D8
	b _080D5438
_080D51D8:
	ldr r1, _080D51E8 @ =0x0000BE15
	adds r0, r5, #0
	bl SetMotion
	b _080D53F8
	.align 2, 0
_080D51E4: .4byte 0x000003FF
_080D51E8: .4byte 0x0000BE15
_080D51EC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	ldr r0, _080D5218 @ =0x000003FF
	cmp r1, r0
	bgt _080D5200
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D5200:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D5214
	b _080D5438
_080D5214:
	b _080D53F8
	.align 2, 0
_080D5218: .4byte 0x000003FF
_080D521C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	ldr r0, _080D5254 @ =0x000003FF
	cmp r1, r0
	bgt _080D5230
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x5c]
_080D5230:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080D5258 @ =0x000B1800
	cmp r0, r1
	bgt _080D5240
	b _080D5438
_080D5240:
	ldr r1, _080D525C @ =0x0000BE16
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D5254: .4byte 0x000003FF
_080D5258: .4byte 0x000B1800
_080D525C: .4byte 0x0000BE16
_080D5260:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080D5294
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D52B4 @ =0x08370CC8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D5294:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D52A0
	b _080D5438
_080D52A0:
	ldr r1, _080D52B8 @ =0x0000BE17
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	strb r6, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D52B4: .4byte 0x08370CC8
_080D52B8: .4byte 0x0000BE17
_080D52BC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _080D52F0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D5310 @ =0x08370CE0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D52F0:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D52FC
	b _080D5438
_080D52FC:
	ldr r1, _080D5314 @ =0x0000BE18
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf9
	bl PlaySound
	strb r6, [r5, #0x12]
	b _080D53F8
	.align 2, 0
_080D5310: .4byte 0x08370CE0
_080D5314: .4byte 0x0000BE18
_080D5318:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _080D534C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D5378 @ =0x08370CF8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D534C:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5438
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D537C @ =0x08370D10
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _080D53F8
	.align 2, 0
_080D5378: .4byte 0x08370CF8
_080D537C: .4byte 0x08370D10
_080D5380:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D5438
	ldr r1, _080D53B0 @ =0x0000BE0C
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf8
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r0, _080D53B4 @ =0xFFFFFC00
	str r0, [r5, #0x60]
	b _080D53F8
	.align 2, 0
_080D53B0: .4byte 0x0000BE0C
_080D53B4: .4byte 0xFFFFFC00
_080D53B8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	subs r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x20
	str r1, [r5, #0x60]
	ldr r0, _080D5400 @ =0xFFFFFF00
	cmp r1, r0
	blt _080D53E0
	lsls r0, r2, #4
	subs r0, r0, r2
	asrs r0, r0, #4
	str r0, [r5, #0x5c]
_080D53E0:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	blt _080D5438
	ldr r1, _080D5404 @ =0x0000BE0D
	adds r0, r5, #0
	bl SetMotion
	movs r1, #0
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	strb r1, [r5, #0x12]
_080D53F8:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080D5438
	.align 2, 0
_080D5400: .4byte 0xFFFFFF00
_080D5404: .4byte 0x0000BE0D
_080D5408:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldr r1, _080D5440 @ =gSineTable
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_080D5438:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D5440: .4byte gSineTable

	thumb_func_start FUN_080d5444
FUN_080d5444: @ 0x080D5444
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xa
	bls _080D5450
	b _080D55A2
_080D5450:
	lsls r0, r0, #2
	ldr r1, _080D545C @ =_080D5460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D545C: .4byte _080D5460
_080D5460: @ jump table
	.4byte _080D548C @ case 0
	.4byte _080D54A8 @ case 1
	.4byte _080D5528 @ case 2
	.4byte _080D553A @ case 3
	.4byte _080D5574 @ case 4
	.4byte _080D553A @ case 5
	.4byte _080D5574 @ case 6
	.4byte _080D553A @ case 7
	.4byte _080D5574 @ case 8
	.4byte _080D558C @ case 9
	.4byte _080D559C @ case 10
_080D548C:
	ldr r0, _080D5508 @ =wDynamicGraphicTilenums
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xd0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D550C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D54A8:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D55A2
	ldr r1, _080D5510 @ =0x0000A109
	adds r0, r6, #0
	bl SetMotion
	ldr r1, _080D5514 @ =wStaticGraphicTilenums
	adds r1, #0x42
	ldr r0, _080D5518 @ =0x00000327
	strh r0, [r1]
	ldr r5, _080D551C @ =wStaticMotionPalIDs
	adds r5, #0x42
	movs r0, #7
	strh r0, [r5]
	movs r4, #0xa5
	lsls r4, r4, #2
	ldr r2, _080D5520 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	b _080D5584
	.align 2, 0
_080D5508: .4byte wDynamicGraphicTilenums
_080D550C: .4byte wDynamicMotionPalIDs
_080D5510: .4byte 0x0000A109
_080D5514: .4byte wStaticGraphicTilenums
_080D5518: .4byte 0x00000327
_080D551C: .4byte wStaticMotionPalIDs
_080D5520: .4byte gStaticMotionGraphics
_080D5524: .4byte gStaticMotionGraphics+12
_080D5528:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D55A2
	b _080D5584
_080D553A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, _080D5570 @ =0x0000A10B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	movs r1, #0x2c
	bl CreateScriptActor
	ldrb r1, [r6, #0xd]
	subs r1, #3
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	strb r1, [r0, #0x11]
	movs r0, #0xf5
	bl PlaySound
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	b _080D5584
	.align 2, 0
_080D5570: .4byte 0x0000A10B
_080D5574:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D55A2
_080D5584:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D55A2
_080D558C:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D559C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080D55A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d55a8
FUN_080d55a8: @ 0x080D55A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r4, [r5, #0xd]
	cmp r4, #0
	beq _080D55BA
	cmp r4, #1
	beq _080D5614
	b _080D569C
_080D55BA:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080D56A4 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D5614:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _080D565C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldrb r0, [r5, #0x11]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D56A8 @ =0x08370D28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D565C:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080D569C
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r6, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080D56AC @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080D569C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D56A4: .4byte 0xFFFFE200
_080D56A8: .4byte 0x08370D28
_080D56AC: .4byte gSolidFnTable

	thumb_func_start FUN_080d56b0
FUN_080d56b0: @ 0x080D56B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xd
	bls _080D56BE
	b _080D59CC
_080D56BE:
	lsls r0, r0, #2
	ldr r1, _080D56C8 @ =_080D56CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D56C8: .4byte _080D56CC
_080D56CC: @ jump table
	.4byte _080D5704 @ case 0
	.4byte _080D5720 @ case 1
	.4byte _080D5770 @ case 2
	.4byte _080D57C0 @ case 3
	.4byte _080D5810 @ case 4
	.4byte _080D5838 @ case 5
	.4byte _080D5860 @ case 6
	.4byte _080D58A4 @ case 7
	.4byte _080D58CA @ case 8
	.4byte _080D5904 @ case 9
	.4byte _080D5944 @ case 10
	.4byte _080D5974 @ case 11
	.4byte _080D59A4 @ case 12
	.4byte _080D59C6 @ case 13
_080D5704:
	ldr r0, _080D5760 @ =wDynamicGraphicTilenums
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5764 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #7
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5720:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #8
	ldr r3, _080D5768 @ =0x08370E10
	movs r1, #1
	mov r2, sp
	bl AppendHazard
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D5750
	b _080D59CC
_080D5750:
	ldr r1, _080D576C @ =0x0000BD05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5760: .4byte wDynamicGraphicTilenums
_080D5764: .4byte wDynamicMotionPalIDs
_080D5768: .4byte 0x08370E10
_080D576C: .4byte 0x0000BD05
_080D5770:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D5786
	b _080D59CC
_080D5786:
	ldr r1, _080D57B8 @ =0x0000BD09
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D57BC @ =0x08370D70
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D57B8: .4byte 0x0000BD09
_080D57BC: .4byte 0x08370D70
_080D57C0:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D57D6
	b _080D59CC
_080D57D6:
	ldr r1, _080D5808 @ =0x0000BD0B
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D580C @ =0x08370D88
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5808: .4byte 0x0000BD0B
_080D580C: .4byte 0x08370D88
_080D5810:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D5824
	b _080D59CC
_080D5824:
	ldr r1, _080D5834 @ =0x0000BD0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5834: .4byte 0x0000BD0C
_080D5838:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D584E
	b _080D59CC
_080D584E:
	ldr r1, _080D585C @ =0x0000BD14
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D585C: .4byte 0x0000BD14
_080D5860:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	beq _080D5876
	b _080D59CC
_080D5876:
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58A0 @ =0x08370DA0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _080D59BE
	.align 2, 0
_080D58A0: .4byte 0x08370DA0
_080D58A4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58F8 @ =0x08370DB8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D58CA:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D59CC
	ldr r1, _080D58FC @ =0x0000BD10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf6
	bl PlaySound
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	ldr r0, _080D5900 @ =0xFFFFFEC0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D58F8: .4byte 0x08370DB8
_080D58FC: .4byte 0x0000BD10
_080D5900: .4byte 0xFFFFFEC0
_080D5904:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, [r6, #0x60]
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r2, #0x40
	str r2, [r6, #0x60]
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	beq _080D59CC
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D5940 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D5940: .4byte 0xFFFFEC00
_080D5944:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D59CC
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r6, #0x12]
	b _080D59BE
_080D5974:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D59CC
	ldr r1, _080D59A0 @ =0x0000BD0F
	adds r0, r6, #0
	bl SetMotion
	b _080D59BE
	.align 2, 0
_080D59A0: .4byte 0x0000BD0F
_080D59A4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #3
	bgt _080D59CC
_080D59BE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D59CC
_080D59C6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080D59CC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d59d4
FUN_080d59d4: @ 0x080D59D4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D5A78
	cmp r7, #1
	bgt _080D59E8
	cmp r7, #0
	beq _080D59EE
	b _080D5AE8
_080D59E8:
	cmp r7, #2
	beq _080D5AB4
	b _080D5AE8
_080D59EE:
	movs r4, #0xfd
	ldr r1, _080D5AA0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D5AA4 @ =0x000002B7
	strh r0, [r1]
	ldr r5, _080D5AA8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #0xa
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xfd
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D5AAC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5AB0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	movs r1, #0xfd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	str r7, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	movs r2, #0
	movs r3, #0x10
_080D5A56:
	ldr r0, [r6, #0x60]
	adds r0, r0, r3
	str r0, [r6, #0x60]
	ldr r1, [r6, #0x58]
	subs r1, r1, r0
	str r1, [r6, #0x58]
	lsls r0, r2, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x5f
	ble _080D5A56
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5A78:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r2, r0, r1
	str r2, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x60]
	cmp r1, #0
	bne _080D5AE8
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	str r2, [r6, #0x68]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D5AE8
	.align 2, 0
_080D5AA0: .4byte wStaticGraphicTilenums
_080D5AA4: .4byte 0x000002B7
_080D5AA8: .4byte wStaticMotionPalIDs
_080D5AAC: .4byte gStaticMotionGraphics
_080D5AB0: .4byte gStaticMotionGraphics+12
_080D5AB4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D5AF0 @ =gSineTable
	adds r0, #0x81
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_080D5AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5AF0: .4byte gSineTable

	thumb_func_start FUN_080d5af4
FUN_080d5af4: @ 0x080D5AF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5B32
	cmp r0, #1
	bgt _080D5B08
	cmp r0, #0
	beq _080D5B0E
	b _080D5C08
_080D5B08:
	cmp r0, #2
	beq _080D5BE8
	b _080D5C08
_080D5B0E:
	ldr r0, _080D5B60 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb6
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r0, _080D5B64 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldr r1, _080D5B68 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5B32:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5B78
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5B6C @ =0x0000C502
	cmp r0, r1
	bne _080D5B70
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5B78
	.align 2, 0
_080D5B60: .4byte wDynamicGraphicTilenums
_080D5B64: .4byte wDynamicMotionPalIDs
_080D5B68: .4byte 0x0000C501
_080D5B6C: .4byte 0x0000C502
_080D5B70:
	ldr r1, _080D5BE0 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5B78:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5BA8
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE0 @ =0x0000C501
	cmp r0, r1
	bne _080D5B9C
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5B9C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5BBE
_080D5BA8:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE4 @ =0x0000C503
	cmp r0, r1
	bne _080D5BBE
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5BBE:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D5C08
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D5BE0 @ =0x0000C501
	cmp r1, r0
	beq _080D5C02
	adds r0, #2
	cmp r1, r0
	bne _080D5C08
	b _080D5C02
	.align 2, 0
_080D5BE0: .4byte 0x0000C501
_080D5BE4: .4byte 0x0000C503
_080D5BE8:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D5C08
_080D5C02:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5C08:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d5c10
FUN_080d5c10: @ 0x080D5C10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D5C20
	cmp r0, #1
	beq _080D5C44
	b _080D5C4A
_080D5C20:
	ldr r0, _080D5C50 @ =wDynamicGraphicTilenums
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5C54 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
	ldr r1, _080D5C58 @ =0x0000B31D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5C44:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D5C4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D5C50: .4byte wDynamicGraphicTilenums
_080D5C54: .4byte wDynamicMotionPalIDs
_080D5C58: .4byte 0x0000B31D

	thumb_func_start FUN_080d5c5c
FUN_080d5c5c: @ 0x080D5C5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _080D5D18
	lsls r0, r0, #2
	ldr r1, _080D5C70 @ =_080D5C74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5C70: .4byte _080D5C74
_080D5C74: @ jump table
	.4byte _080D5C88 @ case 0
	.4byte _080D5CB8 @ case 1
	.4byte _080D5CE0 @ case 2
	.4byte _080D5CF8 @ case 3
	.4byte _080D5D12 @ case 4
_080D5C88:
	ldr r0, _080D5CD4 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5CD8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #5
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5CB8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D5D18
	ldr r1, _080D5CDC @ =0x0000BE20
	adds r0, r4, #0
	bl SetMotion
	b _080D5CF0
	.align 2, 0
_080D5CD4: .4byte wDynamicGraphicTilenums
_080D5CD8: .4byte wDynamicMotionPalIDs
_080D5CDC: .4byte 0x0000BE20
_080D5CE0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5D18
_080D5CF0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5D18
_080D5CF8:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D12:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080D5D18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d5d20
FUN_080d5d20: @ 0x080D5D20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5D56
	cmp r0, #1
	bgt _080D5D34
	cmp r0, #0
	beq _080D5D3A
	b _080D5DFA
_080D5D34:
	cmp r0, #2
	beq _080D5D7C
	b _080D5DFA
_080D5D3A:
	ldr r0, _080D5D70 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5D74 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D56:
	ldr r1, _080D5D78 @ =0x0000C501
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D5DFA
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5DFA
	.align 2, 0
_080D5D70: .4byte wDynamicGraphicTilenums
_080D5D74: .4byte wDynamicMotionPalIDs
_080D5D78: .4byte 0x0000C501
_080D5D7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5DB4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5DA8 @ =0x0000C502
	cmp r0, r1
	bne _080D5DAC
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5DB4
	.align 2, 0
_080D5DA8: .4byte 0x0000C502
_080D5DAC:
	ldr r1, _080D5E00 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5DB4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5DE4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E00 @ =0x0000C501
	cmp r0, r1
	bne _080D5DD8
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DD8:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5DFA
_080D5DE4:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E04 @ =0x0000C503
	cmp r0, r1
	bne _080D5DFA
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E00: .4byte 0x0000C501
_080D5E04: .4byte 0x0000C503

	thumb_func_start FUN_080d5e08
FUN_080d5e08: @ 0x080D5E08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D5E14
	b _080D5FC0
_080D5E14:
	lsls r0, r0, #2
	ldr r1, _080D5E20 @ =_080D5E24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5E20: .4byte _080D5E24
_080D5E24: @ jump table
	.4byte _080D5E4C @ case 0
	.4byte _080D5E7A @ case 1
	.4byte _080D5E8E @ case 2
	.4byte _080D5ED4 @ case 3
	.4byte _080D5F18 @ case 4
	.4byte _080D5F34 @ case 5
	.4byte _080D5F56 @ case 6
	.4byte _080D5F78 @ case 7
	.4byte _080D5FA0 @ case 8
	.4byte _080D5FB8 @ case 9
_080D5E4C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D5ED0 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E7A:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D5E88
	b _080D5FC0
_080D5E88:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E8E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D5EA2
	b _080D5FC0
_080D5EA2:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _080D5FB0
	.align 2, 0
_080D5ED0: .4byte 0x00003503
_080D5ED4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D5EE8
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D5EE8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D5F08
	movs r0, #1
	strb r0, [r1, #0x11]
_080D5F08:
	ldr r1, _080D5F14 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F14: .4byte 0x00000301
_080D5F18:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D5FC0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F34:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D5FC0
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x2a
	strb r0, [r4, #0x12]
	b _080D5FB0
_080D5F56:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D5FC0
	movs r1, #0xd0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F78:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	movs r0, #0x9a
	bl PlaySound
	ldr r1, _080D5F9C @ =0x00003401
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F9C: .4byte 0x00003401
_080D5FA0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5FC0
_080D5FB0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5FC0
_080D5FB8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080D5FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start omega1_080d5fc8
omega1_080d5fc8: @ 0x080D5FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0xa
	bls _080D5FDC
	b _080D6446
_080D5FDC:
	lsls r0, r0, #2
	ldr r1, _080D5FE8 @ =_080D5FEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5FE8: .4byte _080D5FEC
_080D5FEC: @ jump table
	.4byte _080D6018 @ case 0
	.4byte _080D60DC @ case 1
	.4byte _080D6114 @ case 2
	.4byte _080D6130 @ case 3
	.4byte _080D6186 @ case 4
	.4byte _080D62A4 @ case 5
	.4byte _080D62E8 @ case 6
	.4byte _080D6302 @ case 7
	.4byte _080D6338 @ case 8
	.4byte _080D6370 @ case 9
	.4byte _080D63A8 @ case 10
_080D6018:
	movs r1, #0x85
	lsls r1, r1, #2
	ldr r0, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r0, #0x16]
	ldr r2, _080D60FC @ =wStaticMotionPalIDs
	mov sl, r2
	movs r0, #5
	strh r0, [r2, #0x16]
	ldr r5, _080D6100 @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	mov sb, r2
	add r1, sb
	bl LoadGraphic
	ldr r4, _080D6104 @ =gStaticMotionGraphics+12
	adds r0, r4, #0
	adds r0, #0xdc
	mov r2, sl
	ldrh r1, [r2, #0x16]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	bl LoadPalette
	movs r0, #0xa
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r2, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r2, #0x14]
	mov r2, sl
	strh r0, [r2, #0x14]
	adds r5, #0xc8
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r5, #0
	bl LoadGraphic
	adds r4, #0xc8
	mov r0, sl
	ldrh r1, [r0, #0x14]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D6108 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, [r7, #0x54]
	str r1, [r7, #0x64]
	str r0, [r7, #0x68]
	adds r0, r7, #0
	movs r1, #0x35
	bl CreateScriptActor
	adds r0, r7, #0
	movs r1, #0x36
	bl CreateScriptActor
	adds r0, r7, #0
	bl FUN_0800f894
	ldr r0, _080D610C @ =gOverworld
	ldr r2, _080D6110 @ =0x0002D026
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	strb r0, [r7, #0x12]
	strb r0, [r7, #0x11]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D60DC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D60F2
	b _080D6446
_080D60F2:
	strb r2, [r7, #0xe]
	b _080D6398
	.align 2, 0
_080D60F8: .4byte wStaticGraphicTilenums
_080D60FC: .4byte wStaticMotionPalIDs
_080D6100: .4byte gStaticMotionGraphics
_080D6104: .4byte gStaticMotionGraphics+12
_080D6108: .4byte 0xFFFFFE80
_080D610C: .4byte gOverworld
_080D6110: .4byte 0x0002D026
_080D6114:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D612A
	b _080D6446
_080D612A:
	strb r2, [r7, #0xe]
	movs r0, #6
	b _080D6396
_080D6130:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D6146
	b _080D6446
_080D6146:
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #8
	adds r1, r4, #0
	bl AppendQuake
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r7, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r7, #0x12]
	strb r5, [r7, #0x13]
	b _080D6398
_080D6186:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _080D619E
	movs r0, #0x7e
	strb r0, [r7, #0x13]
_080D619E:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D61F8
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bls _080D61CC
	ldr r0, _080D61D8 @ =0x00000135
	bl PlaySound
	movs r0, #0x8a
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl LoadBlink
	movs r0, #0x8b
	lsls r0, r0, #1
	movs r1, #0xe0
	bl LoadBlink
_080D61CC:
	ldrb r0, [r7, #0x12]
	cmp r0, #8
	bls _080D61DC
	subs r0, #8
	b _080D6200
	.align 2, 0
_080D61D8: .4byte 0x00000135
_080D61DC:
	ldr r1, [r7, #0x28]
	cmp r1, #0
	beq _080D61E8
	adds r1, #0x77
	movs r0, #1
	strb r0, [r1]
_080D61E8:
	movs r0, #0
	str r0, [r7, #0x28]
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6202
_080D61F8:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bhi _080D6202
	adds r0, #0x10
_080D6200:
	strb r0, [r7, #0x12]
_080D6202:
	ldr r3, [r7, #0x28]
	cmp r3, #0
	beq _080D627A
	ldrb r1, [r7, #0x13]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6254
	cmp r1, #3
	bls _080D6232
	ldr r2, _080D6244 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D6248 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D624C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	cmp r0, #0
	bne _080D6254
_080D6232:
	ldr r0, _080D6250 @ =gSineTable
	ldrb r1, [r7, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	str r0, [r3, #0x78]
	b _080D627A
	.align 2, 0
_080D6244: .4byte RNG_0202f388
_080D6248: .4byte 0x000343FD
_080D624C: .4byte 0x00269EC3
_080D6250: .4byte gSineTable
_080D6254:
	ldr r1, _080D62A0 @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r3, #0x78]
	ldr r2, [r7, #0x28]
	ldrb r0, [r7, #0x13]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
_080D627A:
	movs r0, #0x8a
	lsls r0, r0, #1
	bl GetBlinkMotionState
	movs r0, #0x8b
	lsls r0, r0, #1
	bl GetBlinkMotionState
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080D6298
	b _080D6446
_080D6298:
	ldr r0, [r7, #0x64]
	subs r0, #8
	b _080D6444
	.align 2, 0
_080D62A0: .4byte gSineTable
_080D62A4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62B4
	subs r0, #1
	strb r0, [r7, #0x13]
_080D62B4:
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r0, r5, #0
	bl GetBlinkMotionState
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r0, r4, #0
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _080D62D2
	b _080D6446
_080D62D2:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62DA
	b _080D6446
_080D62DA:
	adds r0, r5, #0
	bl ClearBlink
	adds r0, r4, #0
	bl ClearBlink
	b _080D6398
_080D62E8:
	movs r0, #0x88
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl LoadBlink
	ldr r0, _080D6334 @ =0x00000117
	movs r1, #0xe0
	bl LoadBlink
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6302:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r5, #0
	bl GetBlinkMotionState
	ldr r4, _080D6334 @ =0x00000117
	adds r0, r4, #0
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D6324
	b _080D6446
_080D6324:
	adds r0, r5, #0
	bl ClearBlink
	adds r0, r4, #0
	bl ClearBlink
	b _080D6398
	.align 2, 0
_080D6334: .4byte 0x00000117
_080D6338:
	ldr r5, _080D63A0 @ =0x0000010F
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl LoadBlink
	ldr r4, _080D63A4 @ =0x00000115
	adds r0, r4, #0
	movs r1, #0xe0
	bl LoadBlink
	adds r0, r5, #0
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl GetBlinkMotionState
	adds r0, r5, #0
	bl ClearBlink
	adds r0, r4, #0
	bl ClearBlink
	movs r0, #0x3c
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6370:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _080D63B4
	movs r0, #3
	strb r0, [r7, #0xe]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6446
	movs r0, #4
	strb r0, [r7, #0xe]
	str r2, [r7, #0x5c]
	movs r0, #0x1e
_080D6396:
	strb r0, [r7, #0x13]
_080D6398:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6446
	.align 2, 0
_080D63A0: .4byte 0x0000010F
_080D63A4: .4byte 0x00000115
_080D63A8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D63BA
_080D63B4:
	subs r0, #1
	strb r0, [r7, #0x13]
	b _080D6446
_080D63BA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080D63DA
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x1e
	bl CreateOmegaWhiteHoop
_080D63DA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D63FA
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x28
	bl CreateOmegaWhiteHoop
_080D63FA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080D641A
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x32
	bl CreateOmegaWhiteHoop
_080D641A:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6434
	ldr r0, [r7, #0x5c]
	cmp r0, #0x5f
	bgt _080D643E
	adds r0, #8
	b _080D643C
	.align 2, 0
_080D6430: .4byte 0xFFFF9C00
_080D6434:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	beq _080D643E
	subs r0, #4
_080D643C:
	str r0, [r7, #0x5c]
_080D643E:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
_080D6444:
	str r0, [r7, #0x64]
_080D6446:
	ldrb r0, [r7, #0x11]
	adds r0, #1
	strb r0, [r7, #0x11]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D645A
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080D6460
_080D645A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D6460:
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080D6490
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x64]
	str r0, [r7, #0x54]
	ldr r1, _080D648C @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _080D64E0
	.align 2, 0
_080D648C: .4byte gSineTable
_080D6490:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	ldr r0, _080D64F0 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r5, _080D64F4 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080D64F8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080D64FC @ =0x000001FF
	ands r0, r4
	ldr r1, [r7, #0x64]
	adds r6, r1, r0
	str r6, [r7, #0x54]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x28]
	cmp r2, #0
	beq _080D64E0
	str r6, [r2, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080D6500 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [r2, #0x58]
_080D64E0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D64F0: .4byte RNG_0202f388
_080D64F4: .4byte 0x000343FD
_080D64F8: .4byte 0x00269EC3
_080D64FC: .4byte 0x000001FF
_080D6500: .4byte 0xFFFFC000

	thumb_func_start FUN_080d6504
FUN_080d6504: @ 0x080D6504
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x28]
	ldrb r0, [r6, #0xd]
	cmp r0, #0xa
	bls _080D6512
	b _080D6808
_080D6512:
	lsls r0, r0, #2
	ldr r1, _080D651C @ =_080D6520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D651C: .4byte _080D6520
_080D6520: @ jump table
	.4byte _080D654C @ case 0
	.4byte _080D65A2 @ case 1
	.4byte _080D6600 @ case 2
	.4byte _080D664A @ case 3
	.4byte _080D66B4 @ case 4
	.4byte _080D66DA @ case 5
	.4byte _080D6600 @ case 6
	.4byte _080D664A @ case 7
	.4byte _080D6730 @ case 8
	.4byte _080D677A @ case 9
	.4byte _080D67CC @ case 10
_080D654C:
	ldr r1, _080D65E0 @ =wStaticGraphicTilenums
	movs r5, #0
	ldr r0, _080D65E4 @ =0x0000023A
	strh r0, [r1, #0x12]
	ldr r4, _080D65E8 @ =wStaticMotionPalIDs
	movs r0, #5
	strh r0, [r4, #0x12]
	ldr r0, _080D65EC @ =0x085D79AC
	ldrh r1, [r1, #0x12]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D65F0 @ =0x085D79B8
	ldrh r1, [r4, #0x12]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D65F4 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x1c
	strb r0, [r1]
	strb r5, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D65A2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r0, [r7, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080D65F8 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080D65FC @ =0xFFFFC800
	adds r1, r1, r0
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	bne _080D65D6
	b _080D67BC
_080D65D6:
	cmp r0, #4
	beq _080D65DC
	b _080D6808
_080D65DC:
	b _080D67BC
	.align 2, 0
_080D65E0: .4byte wStaticGraphicTilenums
_080D65E4: .4byte 0x0000023A
_080D65E8: .4byte wStaticMotionPalIDs
_080D65EC: .4byte 0x085D79AC
_080D65F0: .4byte 0x085D79B8
_080D65F4: .4byte 0x00000901
_080D65F8: .4byte gSineTable
_080D65FC: .4byte 0xFFFFC800
_080D6600:
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bne _080D660C
	movs r0, #0x52
	bl PlaySound
_080D660C:
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _080D6698 @ =0x00000902
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x28
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #6
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D664A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r5, [r7, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D669C @ =0xFFFFB800
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r7, #0xe]
	cmp r0, #4
	bne _080D66A4
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	bne _080D6670
	b _080D6808
_080D6670:
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6686
	b _080D6808
_080D6686:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D66A0 @ =0xFFFFB600
	adds r0, r4, r2
	str r0, [r6, #0x58]
	b _080D6808
	.align 2, 0
_080D6698: .4byte 0x00000902
_080D669C: .4byte 0xFFFFB800
_080D66A0: .4byte 0xFFFFB600
_080D66A4:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D66B2
	b _080D6808
_080D66B2:
	b _080D67BC
_080D66B4:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitRotatableMotion
	ldr r1, _080D6720 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x58
	strb r0, [r1]
	movs r0, #0xc
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D66DA:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r5, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D6724 @ =0xFFFFA800
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _080D6718
	subs r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6718
	ldr r1, _080D6728 @ =0xFFFFFF00
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D672C @ =0xFFFFA600
	adds r0, r4, r2
	str r0, [r6, #0x58]
_080D6718:
	ldrb r0, [r7, #0xe]
	cmp r0, #2
	bne _080D6808
	b _080D67BC
	.align 2, 0
_080D6720: .4byte 0x00000901
_080D6724: .4byte 0xFFFFA800
_080D6728: .4byte 0xFFFFFF00
_080D672C: .4byte 0xFFFFA600
_080D6730:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	movs r2, #0x10
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	strb r3, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D677A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r5, [r7, #0x54]
	movs r1, #0xa4
	lsls r1, r1, #6
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r4, [r7, #0x58]
	ldr r2, _080D67C4 @ =0xFFFFC400
	adds r0, r4, r2
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D67B6
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r5, r1
	str r0, [r6, #0x54]
	ldr r2, _080D67C8 @ =0xFFFFC300
	adds r0, r4, r2
	str r0, [r6, #0x58]
_080D67B6:
	ldrb r0, [r7, #0xe]
	cmp r0, #3
	bne _080D6808
_080D67BC:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D6808
	.align 2, 0
_080D67C4: .4byte 0xFFFFC400
_080D67C8: .4byte 0xFFFFC300
_080D67CC:
	movs r0, #0x52
	bl PlaySound
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r1, _080D6810 @ =0x00000901
	adds r0, r6, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	movs r4, #1
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	strb r4, [r6, #0xd]
_080D6808:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D6810: .4byte 0x00000901

	thumb_func_start FUN_080d6814
FUN_080d6814: @ 0x080D6814
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r0, [r5, #0xd]
	cmp r0, #0xa
	bls _080D6822
	b _080D6AF6
_080D6822:
	lsls r0, r0, #2
	ldr r1, _080D682C @ =_080D6830
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D682C: .4byte _080D6830
_080D6830: @ jump table
	.4byte _080D685C @ case 0
	.4byte _080D688E @ case 1
	.4byte _080D68DC @ case 2
	.4byte _080D691C @ case 3
	.4byte _080D6988 @ case 4
	.4byte _080D69E4 @ case 5
	.4byte _080D68DC @ case 6
	.4byte _080D691C @ case 7
	.4byte _080D6A40 @ case 8
	.4byte _080D6A88 @ case 9
	.4byte _080D6ADC @ case 10
_080D685C:
	ldr r1, _080D68C4 @ =wStaticGraphicTilenums
	movs r4, #0
	ldr r0, _080D68C8 @ =0x0000023A
	strh r0, [r1, #0x12]
	ldr r1, _080D68CC @ =wStaticMotionPalIDs
	movs r0, #5
	strh r0, [r1, #0x12]
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D688E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, _080D68D0 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080D68D4 @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080D68D8 @ =0xFFFFC600
	adds r1, r1, r0
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _080D68BE
	cmp r0, #4
	beq _080D68BE
	b _080D6AF6
_080D68BE:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D68C4: .4byte wStaticGraphicTilenums
_080D68C8: .4byte 0x0000023A
_080D68CC: .4byte wStaticMotionPalIDs
_080D68D0: .4byte 0xFFFFED00
_080D68D4: .4byte gSineTable
_080D68D8: .4byte 0xFFFFC600
_080D68DC:
	adds r0, r5, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x30
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D691C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r7, [r6, #0x54]
	ldr r1, _080D6964 @ =0xFFFFDD00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6968 @ =0xFFFFB600
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r6, #0xe]
	cmp r0, #4
	bne _080D6974
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080D6940
	b _080D6AF6
_080D6940:
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6956
	b _080D6AF6
_080D6956:
	ldr r1, _080D696C @ =0xFFFFDF00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6970 @ =0xFFFFFE00
	adds r0, r4, r2
	str r0, [r5, #0x58]
	b _080D6AF6
	.align 2, 0
_080D6964: .4byte 0xFFFFDD00
_080D6968: .4byte 0xFFFFB600
_080D696C: .4byte 0xFFFFDF00
_080D6970: .4byte 0xFFFFFE00
_080D6974:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D6982
	b _080D6AF6
_080D6982:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
_080D6988:
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _080D6A2C @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x58
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x1d
	strb r0, [r1]
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D69E4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r7, [r6, #0x54]
	ldr r1, _080D6A30 @ =0xFFFFF900
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6A34 @ =0xFFFFA600
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080D6A20
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6A20
	ldr r1, _080D6A38 @ =0xFFFFFB00
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6A3C @ =0xFFFFFE00
	adds r0, r4, r2
	str r0, [r5, #0x58]
_080D6A20:
	ldrb r0, [r6, #0xe]
	cmp r0, #2
	bne _080D6AF6
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D6A2C: .4byte 0x00000901
_080D6A30: .4byte 0xFFFFF900
_080D6A34: .4byte 0xFFFFA600
_080D6A38: .4byte 0xFFFFFB00
_080D6A3C: .4byte 0xFFFFFE00
_080D6A40:
	adds r0, r5, #0
	bl InitRotatableMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	subs r3, #1
	ldrb r0, [r3]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r3]
	strb r2, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D6A88:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r7, [r6, #0x54]
	ldr r1, _080D6ACC @ =0xFFFFE500
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r2, _080D6AD0 @ =0xFFFFBC00
	adds r4, r0, r2
	str r4, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __udivsi3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6AC0
	ldr r1, _080D6AD4 @ =0xFFFFE600
	adds r0, r7, r1
	str r0, [r5, #0x54]
	ldr r2, _080D6AD8 @ =0xFFFFFF00
	adds r0, r4, r2
	str r0, [r5, #0x58]
_080D6AC0:
	ldrb r0, [r6, #0xe]
	cmp r0, #3
	bne _080D6AF6
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080D6AF4
	.align 2, 0
_080D6ACC: .4byte 0xFFFFE500
_080D6AD0: .4byte 0xFFFFBC00
_080D6AD4: .4byte 0xFFFFE600
_080D6AD8: .4byte 0xFFFFFF00
_080D6ADC:
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	movs r0, #0
_080D6AF4:
	strb r0, [r5, #0xd]
_080D6AF6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6afc
FUN_080d6afc: @ 0x080D6AFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #1
	beq _080D6B7E
	cmp r0, #1
	bgt _080D6B10
	cmp r0, #0
	beq _080D6B16
	b _080D6C48
_080D6B10:
	cmp r0, #2
	beq _080D6BD8
	b _080D6C48
_080D6B16:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D6BC0 @ =wStaticGraphicTilenums
	adds r1, #0xa2
	movs r6, #0
	ldr r0, _080D6BC4 @ =0x000002BE
	strh r0, [r1]
	ldr r5, _080D6BC8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #6
	strh r0, [r5]
	ldr r4, _080D6BCC @ =0x00000654
	ldr r2, _080D6BD0 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D6BD4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	movs r0, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6B7E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D6B9E
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #3
	movs r1, #0
	bl FUN_080c5628
_080D6B9E:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6BB0
	ldr r0, [r7, #0x5c]
	adds r0, #0x60
	str r0, [r7, #0x5c]
_080D6BB0:
	ldrb r1, [r2, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6C48
	movs r0, #0
	strb r0, [r7, #0x13]
	b _080D6C42
	.align 2, 0
_080D6BC0: .4byte wStaticGraphicTilenums
_080D6BC4: .4byte 0x000002BE
_080D6BC8: .4byte wStaticMotionPalIDs
_080D6BCC: .4byte 0x00000654
_080D6BD0: .4byte gStaticMotionGraphics
_080D6BD4: .4byte gStaticMotionGraphics+12
_080D6BD8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x5c]
	adds r0, #0x80
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	movs r1, #0x90
	lsls r1, r1, #1
	cmp r0, r1
	bls _080D6C12
	adds r2, r1, #0
_080D6C12:
	adds r0, r7, #0
	adds r0, #0x50
	strh r2, [r0]
	ldrb r0, [r7, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	cmp r0, #0x50
	bls _080D6C48
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D6C42:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6C48:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D6C7C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D6C7C: .4byte gSineTable

	thumb_func_start FUN_080d6c80
FUN_080d6c80: @ 0x080D6C80
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xc
	bls _080D6C8C
	b _080D6F5E
_080D6C8C:
	lsls r0, r0, #2
	ldr r1, _080D6C98 @ =_080D6C9C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6C98: .4byte _080D6C9C
_080D6C9C: @ jump table
	.4byte _080D6CD0 @ case 0
	.4byte _080D6CEC @ case 1
	.4byte _080D6D04 @ case 2
	.4byte _080D6D2C @ case 3
	.4byte _080D6D64 @ case 4
	.4byte _080D6D8C @ case 5
	.4byte _080D6DD8 @ case 6
	.4byte _080D6E00 @ case 7
	.4byte _080D6E2C @ case 8
	.4byte _080D6E74 @ case 9
	.4byte _080D6F38 @ case 10
	.4byte _080D6F48 @ case 11
	.4byte _080D6F5E @ case 12
_080D6CD0:
	ldr r0, _080D6CFC @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xf0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D6D00 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6CEC:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	b _080D6F52
	.align 2, 0
_080D6CFC: .4byte wDynamicGraphicTilenums
_080D6D00: .4byte wDynamicMotionPalIDs
_080D6D04:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D6D18
	b _080D6F5E
_080D6D18:
	ldr r1, _080D6D28 @ =0x0000BE01
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D6F58
	.align 2, 0
_080D6D28: .4byte 0x0000BE01
_080D6D2C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D6D44
	ldr r0, _080D6D5C @ =0x00000101
	bl PlaySound
_080D6D44:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D50
	b _080D6F5E
_080D6D50:
	ldr r1, _080D6D60 @ =0x0000BE02
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6D5C: .4byte 0x00000101
_080D6D60: .4byte 0x0000BE02
_080D6D64:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6D76
	b _080D6F5E
_080D6D76:
	ldr r1, _080D6D88 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	b _080D6F58
	.align 2, 0
_080D6D88: .4byte 0x0000BE03
_080D6D8C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, _080D6DD0 @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D6DC0
	b _080D6F5E
_080D6DC0:
	ldr r1, _080D6DD4 @ =0x0000BE11
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x60]
	b _080D6F58
	.align 2, 0
_080D6DD0: .4byte gSineTable
_080D6DD4: .4byte 0x0000BE11
_080D6DD8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6DEA
	b _080D6F5E
_080D6DEA:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound
	ldr r1, _080D6DFC @ =0x0000BE12
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6DFC: .4byte 0x0000BE12
_080D6E00:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D6E14
	b _080D6F5E
_080D6E14:
	movs r0, #0x92
	lsls r0, r0, #1
	bl stopSound
	ldr r1, _080D6E28 @ =0x0000BE13
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6E28: .4byte 0x0000BE13
_080D6E2C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D6E3E
	b _080D6F5E
_080D6E3E:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D6E6C @ =0x08370DD0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080D6E70 @ =0x0000BE03
	adds r0, r6, #0
	bl SetMotion
	str r5, [r6, #0x5c]
	strb r5, [r6, #0x13]
	b _080D6F58
	.align 2, 0
_080D6E6C: .4byte 0x08370DD0
_080D6E70: .4byte 0x0000BE03
_080D6E74:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	beq _080D6EAA
	adds r0, #0x20
	str r0, [r6, #0x5c]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080D6E8E
	str r1, [r6, #0x5c]
_080D6E8E:
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x5c]
	adds r1, r1, r0
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x54]
	bl PushoutToUp1
	cmp r0, #0
	beq _080D6EAA
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x60]
_080D6EAA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _080D6ED8
	subs r0, #1
	strb r0, [r6, #0x13]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6EC4
	adds r0, r6, #0
	bl PaintEntityWhite
	b _080D6ECA
_080D6EC4:
	adds r0, r6, #0
	bl UpdateEntityPaletteID
_080D6ECA:
	ldrb r0, [r6, #0x13]
	cmp r0, #0x16
	bne _080D6ED8
	ldr r1, _080D6EF8 @ =0x0000BE0D
	adds r0, r6, #0
	bl SetMotion
_080D6ED8:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D6F00
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x60]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r1, _080D6EFC @ =0x0000BE0E
	adds r0, r6, #0
	bl SetMotion
	b _080D6F58
	.align 2, 0
_080D6EF8: .4byte 0x0000BE0D
_080D6EFC: .4byte 0x0000BE0E
_080D6F00:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D6F5E
	ldr r1, _080D6F34 @ =0x0000BE0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x13]
	ldr r0, [r6, #0x5c]
	adds r0, #1
	str r0, [r6, #0x5c]
	movs r0, #0xf8
	bl isSoundPlaying
	cmp r0, #0
	bne _080D6F5E
	movs r0, #0xf8
	bl PlaySound
	b _080D6F5E
	.align 2, 0
_080D6F34: .4byte 0x0000BE0C
_080D6F38:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	b _080D6F54
_080D6F48:
	ldr r1, _080D6F98 @ =0x0000BE0B
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0934
_080D6F52:
	lsls r0, r0, #0x10
_080D6F54:
	cmp r0, #0
	beq _080D6F5E
_080D6F58:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D6F5E:
	ldrb r0, [r6, #0xd]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080D6F90
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldr r1, _080D6F9C @ =gSineTable
	ldrb r0, [r6, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x68]
	ldr r2, [r6, #0x58]
	lsls r0, r2, #3
	subs r0, r0, r2
	adds r0, r0, r1
	asrs r0, r0, #3
	str r0, [r6, #0x58]
_080D6F90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D6F98: .4byte 0x0000BE0B
_080D6F9C: .4byte gSineTable

	thumb_func_start FUN_080d6fa0
FUN_080d6fa0: @ 0x080D6FA0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D6FAC
	b _080D71F0
_080D6FAC:
	lsls r0, r0, #2
	ldr r1, _080D6FB8 @ =_080D6FBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D6FB8: .4byte _080D6FBC
_080D6FBC: @ jump table
	.4byte _080D6FD4 @ case 0
	.4byte _080D708E @ case 1
	.4byte _080D70E0 @ case 2
	.4byte _080D710C @ case 3
	.4byte _080D71B8 @ case 4
	.4byte _080D71F0 @ case 5
_080D6FD4:
	movs r4, #0xb8
	ldr r0, _080D7050 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7054 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #6
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7058 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D705C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7060 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D7068
	ldr r1, _080D7064 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0
	str r0, [r6, #0x60]
	movs r0, #3
	b _080D71EE
	.align 2, 0
_080D7050: .4byte wStaticGraphicTilenums
_080D7054: .4byte wStaticMotionPalIDs
_080D7058: .4byte gStaticMotionGraphics
_080D705C: .4byte gStaticMotionGraphics+12
_080D7060: .4byte 0xFFFFE800
_080D7064: .4byte 0x0000B802
_080D7068:
	str r0, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	ldrb r4, [r6, #0xd]
	movs r3, #0x10
	movs r2, #0x5f
_080D7074:
	ldr r1, [r6, #0x60]
	adds r1, r1, r3
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7074
	movs r0, #0
	strb r0, [r6, #0x13]
	adds r0, r4, #1
	strb r0, [r6, #0xd]
_080D708E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r4, r1, r0
	str r4, [r6, #0x60]
	cmp r4, #0
	beq _080D70A8
	b _080D71F0
_080D70A8:
	ldr r1, _080D70D0 @ =gPaletteManager
	ldr r0, _080D70D4 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D70D8 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D70DC @ =0x0000B801
	adds r0, r6, #0
	bl SetMotion
	str r4, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	b _080D71EA
	.align 2, 0
_080D70D0: .4byte gPaletteManager
_080D70D4: .4byte 0x00000404
_080D70D8: .4byte 0x00000406
_080D70DC: .4byte 0x0000B801
_080D70E0:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D70F2
	b _080D71F0
_080D70F2:
	ldr r1, _080D7104 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _080D7108 @ =0x0000013D
	bl PlaySound
	b _080D71EA
	.align 2, 0
_080D7104: .4byte 0x0000B802
_080D7108: .4byte 0x0000013D
_080D710C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7124
	ldr r1, _080D7190 @ =0x0000B802
	adds r0, r6, #0
	bl SetMotion
_080D7124:
	ldr r2, _080D7194 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7198 @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D719C @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7148
	ldr r1, _080D71A0 @ =0x0000B803
	adds r0, r6, #0
	bl SetMotion
_080D7148:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, _080D71A4 @ =0x0000013D
	bl stopSound
	ldr r1, _080D71A8 @ =gPaletteManager
	ldr r0, _080D71AC @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D71B0 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x64
	str r0, [r6, #0x40]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _080D71B4 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	strb r4, [r6, #0x13]
	b _080D71EA
	.align 2, 0
_080D7190: .4byte 0x0000B802
_080D7194: .4byte RNG_0202f388
_080D7198: .4byte 0x000343FD
_080D719C: .4byte 0x00269EC3
_080D71A0: .4byte 0x0000B803
_080D71A4: .4byte 0x0000013D
_080D71A8: .4byte gPaletteManager
_080D71AC: .4byte 0x00000404
_080D71B0: .4byte 0x00000406
_080D71B4: .4byte 0xFFFFFF00
_080D71B8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D71F0
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, _080D7240 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080D7244 @ =0x00000FFF
	cmp r0, r1
	bls _080D71F0
	ldrb r0, [r6, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r6, #0xa]
_080D71EA:
	ldrb r0, [r6, #0xd]
	adds r0, #1
_080D71EE:
	strb r0, [r6, #0xd]
_080D71F0:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7238
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bge _080D7238
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D7248 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [r6, #0x68]
_080D7238:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7240: .4byte gStageRun+232
_080D7244: .4byte 0x00000FFF
_080D7248: .4byte gSineTable

	thumb_func_start FUN_080d724c
FUN_080d724c: @ 0x080D724C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #5
	bls _080D7258
	b _080D73FA
_080D7258:
	lsls r0, r0, #2
	ldr r1, _080D7264 @ =_080D7268
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7264: .4byte _080D7268
_080D7268: @ jump table
	.4byte _080D7280 @ case 0
	.4byte _080D72FE @ case 1
	.4byte _080D731C @ case 2
	.4byte _080D734E @ case 3
	.4byte _080D7388 @ case 4
	.4byte _080D73B4 @ case 5
_080D7280:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D72E4 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D72E8 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D72EC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D72F0 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D72F4 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080D72F8
	movs r0, #5
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D72E4: .4byte gStaticMotionGraphics
_080D72E8: .4byte wStaticGraphicTilenums
_080D72EC: .4byte gStaticMotionGraphics+12
_080D72F0: .4byte wStaticMotionPalIDs
_080D72F4: .4byte 0x00008C06
_080D72F8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D72FE:
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	ldr r1, _080D7318 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
	.align 2, 0
_080D7318: .4byte 0x00008C05
_080D731C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080D73A8
_080D734E:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D73FA
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080D73A8
_080D7388:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D73FA
	ldr r1, _080D73B0 @ =0x00008C06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080D73A8:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D73FA
	.align 2, 0
_080D73B0: .4byte 0x00008C06
_080D73B4:
	ldr r0, _080D7400 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080D7404 @ =0x00000FFF
	cmp r0, r1
	bls _080D73FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080D7408 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080D73FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7400: .4byte gStageRun+232
_080D7404: .4byte 0x00000FFF
_080D7408: .4byte gSolidFnTable

	thumb_func_start FUN_080d740c
FUN_080d740c: @ 0x080D740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	bls _080D7418
	b _080D7512
_080D7418:
	lsls r0, r0, #2
	ldr r1, _080D7424 @ =_080D7428
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7424: .4byte _080D7428
_080D7428: @ jump table
	.4byte _080D743C @ case 0
	.4byte _080D74A0 @ case 1
	.4byte _080D74E4 @ case 2
	.4byte _080D74FC @ case 3
	.4byte _080D7512 @ case 4
_080D743C:
	movs r4, #0xaf
	lsls r4, r4, #4
	ldr r1, _080D74C0 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D74C4 @ =wStaticGraphicTilenums
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D74C8 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D74CC @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D74D0 @ =0x00008C07
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, _080D74D4 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D74D8 @ =0x000087FF
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74A0:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r2, _080D74DC @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x64]
	cmp r0, r1
	bge _080D7512
	str r1, [r6, #0x54]
	ldr r1, _080D74E0 @ =0x00008C05
	adds r0, r6, #0
	bl SetMotion
	b _080D750C
	.align 2, 0
_080D74C0: .4byte gStaticMotionGraphics
_080D74C4: .4byte wStaticGraphicTilenums
_080D74C8: .4byte gStaticMotionGraphics+12
_080D74CC: .4byte wStaticMotionPalIDs
_080D74D0: .4byte 0x00008C07
_080D74D4: .4byte gStageRun+232
_080D74D8: .4byte 0x000087FF
_080D74DC: .4byte 0xFFFFFF00
_080D74E0: .4byte 0x00008C05
_080D74E4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7512
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D74FC:
	ldr r1, _080D7518 @ =0x00008C05
	adds r0, r6, #0
	movs r2, #0
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7512
_080D750C:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D7512:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7518: .4byte 0x00008C05

	thumb_func_start FUN_080d751c
FUN_080d751c: @ 0x080D751C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D755A
	cmp r0, #1
	bgt _080D7530
	cmp r0, #0
	beq _080D7536
	b _080D7630
_080D7530:
	cmp r0, #2
	beq _080D7610
	b _080D7630
_080D7536:
	ldr r0, _080D7588 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D758C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #9
	strh r1, [r0]
	ldr r1, _080D7590 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D755A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D75A0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7594 @ =0x0000C502
	cmp r0, r1
	bne _080D7598
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D75A0
	.align 2, 0
_080D7588: .4byte wDynamicGraphicTilenums
_080D758C: .4byte wDynamicMotionPalIDs
_080D7590: .4byte 0x0000C501
_080D7594: .4byte 0x0000C502
_080D7598:
	ldr r1, _080D7608 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D75A0:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D75D0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D7608 @ =0x0000C501
	cmp r0, r1
	bne _080D75C4
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75C4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D75E6
_080D75D0:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D760C @ =0x0000C503
	cmp r0, r1
	bne _080D75E6
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D75E6:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D7608 @ =0x0000C501
	cmp r1, r0
	beq _080D762A
	adds r0, #2
	cmp r1, r0
	bne _080D7630
	b _080D762A
	.align 2, 0
_080D7608: .4byte 0x0000C501
_080D760C: .4byte 0x0000C503
_080D7610:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D7630
_080D762A:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7630:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7638
FUN_080d7638: @ 0x080D7638
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D7682
	cmp r0, #1
	bgt _080D764C
	cmp r0, #0
	beq _080D7652
	b _080D76B4
_080D764C:
	cmp r0, #2
	beq _080D769C
	b _080D76B4
_080D7652:
	ldr r0, _080D7694 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D7698 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7682:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	b _080D76AA
	.align 2, 0
_080D7694: .4byte wDynamicGraphicTilenums
_080D7698: .4byte wDynamicMotionPalIDs
_080D769C:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
_080D76AA:
	cmp r0, #0
	beq _080D76B4
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D76B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor62_Update
Actor62_Update: @ 0x080D76BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D76C8
	b _080D7868
_080D76C8:
	lsls r0, r0, #2
	ldr r1, _080D76D4 @ =_080D76D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D76D4: .4byte _080D76D8
_080D76D8: @ jump table
	.4byte _080D7700 @ case 0
	.4byte _080D7718 @ case 1
	.4byte _080D7738 @ case 2
	.4byte _080D775A @ case 3
	.4byte _080D778C @ case 4
	.4byte _080D77AC @ case 5
	.4byte _080D77BE @ case 6
	.4byte _080D77EA @ case 7
	.4byte _080D7828 @ case 8
	.4byte _080D7868 @ case 9
_080D7700:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7718:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D772C
	b _080D7868
_080D772C:
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
_080D7738:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	beq _080D774A
	b _080D7868
_080D774A:
	movs r1, #0xc4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	b _080D7862
_080D775A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	adds r0, #0x60
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D7776
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_080D7776:
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _080D7868
	ldr r1, _080D7788 @ =0x00003303
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D7788: .4byte 0x00003303
_080D778C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7868
	ldr r1, _080D77A8 @ =0x00003301
	adds r0, r4, #0
	bl SetMotion
	b _080D7862
	.align 2, 0
_080D77A8: .4byte 0x00003301
_080D77AC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	b _080D7862
_080D77BE:
	ldr r1, _080D7824 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
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
	strb r0, [r2]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D77EA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7868
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	b _080D7862
	.align 2, 0
_080D7824: .4byte 0x00000301
_080D7828:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D783C
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D783C:
	ldr r1, [r4, #0x54]
	ldr r0, _080D7870 @ =0xFFFFFC80
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, _080D7874 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7878 @ =0xFFFF6800
	adds r0, r0, r2
	cmp r1, r0
	bge _080D7868
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D785A
	movs r0, #1
	strb r0, [r1, #0x11]
_080D785A:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_080D7862:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D7868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7870: .4byte 0xFFFFFC80
_080D7874: .4byte gStageRun+232
_080D7878: .4byte 0xFFFF6800

	thumb_func_start Actor63_Update
Actor63_Update: @ 0x080D787C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #1
	beq _080D78F6
	cmp r0, #1
	bgt _080D7890
	cmp r0, #0
	beq _080D7896
	b _080D793E
_080D7890:
	cmp r0, #2
	beq _080D7938
	b _080D793E
_080D7896:
	ldr r4, _080D7920 @ =0x00000F28
	ldr r1, _080D7924 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080D7928 @ =wStaticGraphicTilenums
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D792C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080D7930 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r1, _080D7934 @ =0x0000C203
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r0, #0x5a
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D78F6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	adds r0, #0x80
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D793E
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D793E
	.align 2, 0
_080D7920: .4byte 0x00000F28
_080D7924: .4byte gStaticMotionGraphics
_080D7928: .4byte wStaticGraphicTilenums
_080D792C: .4byte gStaticMotionGraphics+12
_080D7930: .4byte wStaticMotionPalIDs
_080D7934: .4byte 0x0000C203
_080D7938:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080D793E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Actor64_Update
Actor64_Update: @ 0x080D7944
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #4
	bls _080D7950
	b _080D7AC0
_080D7950:
	lsls r0, r0, #2
	ldr r1, _080D795C @ =_080D7960
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D795C: .4byte _080D7960
_080D7960: @ jump table
	.4byte _080D7974 @ case 0
	.4byte _080D7A34 @ case 1
	.4byte _080D7A74 @ case 2
	.4byte _080D7AA0 @ case 3
	.4byte _080D7ABA @ case 4
_080D7974:
	movs r4, #0x8c
	ldr r0, _080D7A04 @ =wStaticGraphicTilenums
	lsls r1, r4, #1
	adds r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #2
	strh r2, [r0]
	ldr r0, _080D7A08 @ =wStaticMotionPalIDs
	adds r6, r0, r1
	movs r0, #7
	strh r0, [r6]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D79C4
	lsls r4, r4, #2
	adds r4, #0x8c
	lsls r4, r4, #2
	ldr r1, _080D7A0C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r2, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7A10 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_080D79C4:
	ldr r1, _080D7A14 @ =0x00008C02
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0x11]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D79DE
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
_080D79DE:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r1, [r5, #0x11]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7A20
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x5c]
	ldr r0, _080D7A18 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080D7A1C @ =0xFFFF7800
	adds r0, r0, r1
	b _080D7A2C
	.align 2, 0
_080D7A04: .4byte wStaticGraphicTilenums
_080D7A08: .4byte wStaticMotionPalIDs
_080D7A0C: .4byte gStaticMotionGraphics
_080D7A10: .4byte gStaticMotionGraphics+12
_080D7A14: .4byte 0x00008C02
_080D7A18: .4byte gStageRun+232
_080D7A1C: .4byte 0xFFFF7800
_080D7A20:
	ldr r0, _080D7A68 @ =0xFFFFFF00
	str r0, [r5, #0x5c]
	ldr r0, _080D7A6C @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r2, _080D7A70 @ =0x000087FF
	adds r0, r0, r2
_080D7A2C:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7A34:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	cmp r2, #0
	bge _080D7A4C
	ldr r1, [r5, #0x64]
	cmp r0, r1
	ble _080D7A56
_080D7A4C:
	cmp r2, #0
	ble _080D7AC0
	ldr r1, [r5, #0x64]
	cmp r0, r1
	blt _080D7AC0
_080D7A56:
	str r1, [r5, #0x54]
	movs r1, #0x8c
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	b _080D7A94
	.align 2, 0
_080D7A68: .4byte 0xFFFFFF00
_080D7A6C: .4byte gStageRun+232
_080D7A70: .4byte 0x000087FF
_080D7A74:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D7AC0
	ldr r1, _080D7A9C @ =0x00008C01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080D7A94:
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080D7AC0
	.align 2, 0
_080D7A9C: .4byte 0x00008C01
_080D7AA0:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7AC0
	ldr r1, _080D7AC8 @ =0x00008C03
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D7ABA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080D7AC0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7AC8: .4byte 0x00008C03

	thumb_func_start Actor65_Update
Actor65_Update: @ 0x080D7ACC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #5
	bls _080D7AD8
	b _080D7D04
_080D7AD8:
	lsls r0, r0, #2
	ldr r1, _080D7AE4 @ =_080D7AE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7AE4: .4byte _080D7AE8
_080D7AE8: @ jump table
	.4byte _080D7B00 @ case 0
	.4byte _080D7B8C @ case 1
	.4byte _080D7BF4 @ case 2
	.4byte _080D7C20 @ case 3
	.4byte _080D7CCC @ case 4
	.4byte _080D7D04 @ case 5
_080D7B00:
	movs r4, #0xb8
	ldr r0, _080D7BD0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r0, r0, r2
	movs r6, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D7BD4 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D7BD8 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D7BDC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r4, _080D7BE0 @ =0xFFFFE800
	adds r0, r0, r4
	str r0, [r7, #0x58]
	str r6, [r7, #0x60]
	movs r0, #0x10
	str r0, [r7, #0x68]
	movs r3, #0x10
	movs r2, #0x5f
_080D7B70:
	ldr r1, [r7, #0x60]
	adds r1, r1, r3
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x58]
	subs r2, #1
	cmp r2, #0
	bge _080D7B70
	movs r0, #0
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7B8C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x68]
	subs r4, r1, r0
	str r4, [r7, #0x60]
	cmp r4, #0
	beq _080D7BA6
	b _080D7D04
_080D7BA6:
	ldr r1, _080D7BE4 @ =gPaletteManager
	ldr r0, _080D7BE8 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7BEC @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D7BF0 @ =0x0000B801
	adds r0, r7, #0
	bl SetMotion
	str r4, [r7, #0x60]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	b _080D7CFE
	.align 2, 0
_080D7BD0: .4byte wStaticGraphicTilenums
_080D7BD4: .4byte wStaticMotionPalIDs
_080D7BD8: .4byte gStaticMotionGraphics
_080D7BDC: .4byte gStaticMotionGraphics+12
_080D7BE0: .4byte 0xFFFFE800
_080D7BE4: .4byte gPaletteManager
_080D7BE8: .4byte 0x00000404
_080D7BEC: .4byte 0x00000406
_080D7BF0: .4byte 0x0000B801
_080D7BF4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D7C06
	b _080D7D04
_080D7C06:
	ldr r1, _080D7C18 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
	ldr r0, _080D7C1C @ =0x0000013D
	bl PlaySound
	b _080D7CFE
	.align 2, 0
_080D7C18: .4byte 0x0000B802
_080D7C1C: .4byte 0x0000013D
_080D7C20:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D7C38
	ldr r1, _080D7CA4 @ =0x0000B802
	adds r0, r7, #0
	bl SetMotion
_080D7C38:
	ldr r2, _080D7CA8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D7CAC @ =0x000343FD
	muls r0, r1, r0
	ldr r4, _080D7CB0 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080D7C5C
	ldr r1, _080D7CB4 @ =0x0000B803
	adds r0, r7, #0
	bl SetMotion
_080D7C5C:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, _080D7CB8 @ =0x0000013D
	bl stopSound
	ldr r1, _080D7CBC @ =gPaletteManager
	ldr r0, _080D7CC0 @ =0x00000404
	adds r2, r1, r0
	movs r4, #0x40
	movs r0, #0x40
	strh r0, [r2]
	ldr r2, _080D7CC4 @ =0x00000406
	adds r1, r1, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [r7, #0x40]
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r0, _080D7CC8 @ =0xFFFFFF00
	str r0, [r7, #0x60]
	strb r4, [r7, #0x13]
	b _080D7CFE
	.align 2, 0
_080D7CA4: .4byte 0x0000B802
_080D7CA8: .4byte RNG_0202f388
_080D7CAC: .4byte 0x000343FD
_080D7CB0: .4byte 0x00269EC3
_080D7CB4: .4byte 0x0000B803
_080D7CB8: .4byte 0x0000013D
_080D7CBC: .4byte gPaletteManager
_080D7CC0: .4byte 0x00000404
_080D7CC4: .4byte 0x00000406
_080D7CC8: .4byte 0xFFFFFF00
_080D7CCC:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7D04
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, _080D7D54 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _080D7D58 @ =0x00000FFF
	cmp r0, r1
	bls _080D7D04
	ldrb r0, [r7, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r7, #0xa]
_080D7CFE:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D7D04:
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, #0xb8
	lsls r1, r1, #8
	cmp r0, r1
	bne _080D7D4C
	ldr r0, [r7, #0x60]
	cmp r0, #0
	bge _080D7D4C
	ldrb r0, [r7, #0x13]
	adds r2, r0, #1
	strb r2, [r7, #0x13]
	ldr r3, _080D7D5C @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #2
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #3
	ldr r0, [r7, #0x58]
	subs r0, r0, r1
	str r0, [r7, #0x68]
_080D7D4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D7D54: .4byte gStageRun+232
_080D7D58: .4byte 0x00000FFF
_080D7D5C: .4byte gSineTable
