	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start goldOmega1Laser
goldOmega1Laser: @ 0x0805B5E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0805B5EC
	b _0805B738
_0805B5EC:
	lsls r0, r0, #2
	ldr r1, _0805B5F8 @ =_0805B5FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805B5F8: .4byte _0805B5FC
_0805B5FC: @ jump table
	.4byte _0805B610 @ case 0
	.4byte _0805B670 @ case 1
	.4byte _0805B6C0 @ case 2
	.4byte _0805B6E4 @ case 3
	.4byte _0805B714 @ case 4
_0805B610:
	adds r0, r4, #0
	adds r0, #0x4c
	movs r2, #0
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r2, [r0, #4]
	str r2, [r4, #0x5c]
	movs r0, #3
	strb r0, [r4, #0x12]
	ldr r2, _0805B65C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805B660 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805B664 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805B668
	strb r0, [r4, #0xf]
	b _0805B66A
	.align 2, 0
_0805B65C: .4byte RNG_0202f388
_0805B660: .4byte 0x000343FD
_0805B664: .4byte 0x00269EC3
_0805B668:
	strb r1, [r4, #0xf]
_0805B66A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B670:
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0805B698
	movs r0, #0x9a
	lsls r0, r0, #3
	ldr r2, _0805B694 @ =unk_080fefb8
	ldrb r1, [r4, #0x12]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x30
	adds r3, r4, #0
	bl createGoldOmega1Laser
	b _0805B6AE
	.align 2, 0
_0805B694: .4byte unk_080fefb8
_0805B698:
	movs r0, #0x9a
	lsls r0, r0, #3
	ldr r2, _0805B6BC @ =0x080FEFBB
	ldrb r1, [r4, #0x12]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x30
	adds r3, r4, #0
	bl createGoldOmega1Laser
_0805B6AE:
	movs r0, #0xb
	bl StepPaletteAnimation
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805B738
	.align 2, 0
_0805B6BC: .4byte 0x080FEFBB
_0805B6C0:
	adds r0, r4, #0
	bl floatGoldOmega1
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0805B6DC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805B6DC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805B6DC:
	adds r0, r4, #0
	bl floatGoldOmega1
	b _0805B70C
_0805B6E4:
	adds r0, r4, #0
	bl floatGoldOmega1
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805B708
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0805B70A
_0805B708:
	movs r0, #1
_0805B70A:
	strb r0, [r4, #0xe]
_0805B70C:
	movs r0, #0xb
	bl StepPaletteAnimation
	b _0805B738
_0805B714:
	adds r0, r4, #0
	bl floatGoldOmega1
	movs r0, #0xb
	bl StepPaletteAnimation
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805B738
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805B738
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805B738:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

