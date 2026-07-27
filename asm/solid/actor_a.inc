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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl Camera_GetDistance
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl Camera_GetDistance
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	ldr r4, _080D1F04 @ =sProloguePantheons
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
_080D1F04: .4byte sProloguePantheons
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
	ldr r0, _080D200C @ =gStaticMotionGraphics+((20*9)+12)
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
	bl UpdateEntityAnim
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
_080D2004: .4byte gStaticMotionGraphics+(20*9)
_080D2008: .4byte wStaticGraphicTilenums
_080D200C: .4byte gStaticMotionGraphics+(20*9)+12
_080D2010: .4byte wStaticMotionPalIDs
_080D2014: .4byte 0x00000902
_080D2018: .4byte gStageRun+232
_080D201C: .4byte 0x00009BFF
_080D2020: .4byte 0xFFFFF800
_080D2024:
	adds r0, r6, #0
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	ldr r0, _080D215C @ =gStaticMotionGraphics+((20*9)+12)
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
	ldr r1, _080D2168 @ =sCollisions_08370B58
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
	bl UpdateEntityAnim
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
_080D2154: .4byte gStaticMotionGraphics+(20*9)
_080D2158: .4byte wStaticGraphicTilenums
_080D215C: .4byte gStaticMotionGraphics+((20*9)+12)
_080D2160: .4byte wStaticMotionPalIDs
_080D2164: .4byte 0x00000902
_080D2168: .4byte sCollisions_08370B58
_080D216C: .4byte gStageRun+232
_080D2170: .4byte 0x000097FF
_080D2174: .4byte 0x00001FFF
_080D2178: .4byte 0xFFFFD000
_080D217C: .4byte 0xFFFFFA00
_080D2180:
	adds r0, r6, #0
	bl UpdateEntityAnim
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
	ldr r1, _080D22E8 @ =sCollisions_08370B58+(24*1)
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
	bl UpdateEntityAnim
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
_080D22E8: .4byte sCollisions_08370B58+(24*1)
_080D22EC: .4byte gStageRun+232
_080D22F0: .4byte 0x000087FF
_080D22F4: .4byte 0xFFFFF800
_080D22F8:
	adds r0, r6, #0
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	ldr r1, _080D24DC @ =sCollisions_08370B58+(24*1)
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
	bl UpdateEntityAnim
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
_080D24DC: .4byte sCollisions_08370B58+(24*1)
_080D24E0: .4byte gStageRun+232
_080D24E4: .4byte 0x000087FF
_080D24E8: .4byte 0xFFFFFD00
_080D24EC:
	adds r0, r7, #0
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xe
	b _080D27FA
_080D26B0:
	adds r0, r7, #0
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
