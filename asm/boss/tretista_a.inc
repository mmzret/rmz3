	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804dc90
tretista_0804dc90: @ 0x0804DC90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0804DCC0
	cmp r0, #1
	bgt _0804DCA4
	cmp r0, #0
	beq _0804DCAA
	b _0804DCFA
_0804DCA4:
	cmp r0, #2
	beq _0804DCE0
	b _0804DCFA
_0804DCAA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804DCDC @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804DCC0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DCFA
	movs r0, #0
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804DCF8
	.align 2, 0
_0804DCDC: .4byte 0x0000AB09
_0804DCE0:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0804DCF2
	adds r0, r4, #0
	bl tretista_0804dd00
	cmp r0, #1
	bne _0804DCFA
	b _0804DCF4
_0804DCF2:
	movs r0, #1
_0804DCF4:
	strb r0, [r4, #0xd]
	movs r0, #7
_0804DCF8:
	strb r0, [r4, #0xe]
_0804DCFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start tretista_0804dd00
tretista_0804dd00: @ 0x0804DD00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0xf
	bls _0804DD12
	b _0804DF60
_0804DD12:
	lsls r0, r0, #2
	ldr r1, _0804DD1C @ =_0804DD20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DD1C: .4byte _0804DD20
_0804DD20: @ jump table
	.4byte _0804DD60 @ case 0
	.4byte _0804DDE2 @ case 1
	.4byte _0804DE10 @ case 2
	.4byte _0804DE38 @ case 3
	.4byte _0804DE74 @ case 4
	.4byte _0804DF1C @ case 5
	.4byte _0804DE84 @ case 6
	.4byte _0804DE92 @ case 7
	.4byte _0804DEA0 @ case 8
	.4byte _0804DF1C @ case 9
	.4byte _0804DEB4 @ case 10
	.4byte _0804DED0 @ case 11
	.4byte _0804DEEC @ case 12
	.4byte _0804DF1C @ case 13
	.4byte _0804DF34 @ case 14
	.4byte _0804DF42 @ case 15
_0804DD60:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	mov r8, r1
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r6, _0804DE04 @ =pZero2
	ldr r0, [r6]
	ldr r0, [r0, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	movs r3, #0
	bl createHellBouncer
	adds r4, r7, #0
	adds r4, #0xc8
	str r0, [r4]
	adds r0, #0xb9
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldr r0, [r5]
	str r0, [r1, #0x64]
	ldr r0, [r7, #0x58]
	ldr r1, _0804DE08 @ =0xFFFF6000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r6]
	ldr r0, [r0, #0x54]
	ldr r1, _0804DE0C @ =0xFFFF8800
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	movs r3, #1
	bl createHellBouncer
	adds r2, r7, #0
	adds r2, #0xcc
	str r0, [r2]
	adds r0, #0xb9
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, [r5]
	str r0, [r1, #0x64]
	ldr r1, [r2]
	ldr r0, [r4]
	str r0, [r1, #0x2c]
	ldr r1, [r4]
	ldr r0, [r2]
	str r0, [r1, #0x2c]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DDE2:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804DDF2
	b _0804DF60
_0804DDF2:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804DE02
	b _0804DF60
_0804DE02:
	b _0804DF2C
	.align 2, 0
_0804DE04: .4byte pZero2
_0804DE08: .4byte 0xFFFF6000
_0804DE0C: .4byte 0xFFFF8800
_0804DE10:
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0804DE68 @ =0x0000AB01
	adds r0, r7, #0
	bl SetMotion
	str r4, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x58]
	ldr r1, _0804DE6C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DE38:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804DE48
	str r1, [r7, #0x60]
_0804DE48:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, _0804DE70 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0804DE64
	b _0804DF60
_0804DE64:
	str r0, [r7, #0x58]
	b _0804DF2C
	.align 2, 0
_0804DE68: .4byte 0x0000AB01
_0804DE6C: .4byte 0xFFFFB000
_0804DE70: .4byte pZero2
_0804DE74:
	movs r0, #0xd4
	bl PlaySound
	ldr r1, _0804DE80 @ =0x0000AB02
	b _0804DEA2
	.align 2, 0
_0804DE80: .4byte 0x0000AB02
_0804DE84:
	ldr r1, _0804DE9C @ =0x0000AB03
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DE92:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _0804DF2C
	.align 2, 0
_0804DE9C: .4byte 0x0000AB03
_0804DEA0:
	ldr r1, _0804DEB0 @ =0x0000AB04
_0804DEA2:
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	b _0804DF1C
	.align 2, 0
_0804DEB0: .4byte 0x0000AB04
_0804DEB4:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	movs r1, #2
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	strb r1, [r0]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DED0:
	adds r0, r7, #0
	adds r0, #0xcc
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF0E
	movs r0, #0xd7
	bl PlaySound
	ldr r1, _0804DEE8 @ =0x0000AB06
	b _0804DF02
	.align 2, 0
_0804DEE8: .4byte 0x0000AB06
_0804DEEC:
	adds r0, r7, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF0E
	movs r0, #0xd7
	bl PlaySound
	ldr r1, _0804DF18 @ =0x0000AB08
_0804DF02:
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DF0E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _0804DF60
	.align 2, 0
_0804DF18: .4byte 0x0000AB08
_0804DF1C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF60
_0804DF2C:
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	b _0804DF60
_0804DF34:
	ldr r1, _0804DF5C @ =0x0000AB1F
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0804DF42:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF60
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	movs r0, #1
	b _0804DF62
	.align 2, 0
_0804DF5C: .4byte 0x0000AB1F
_0804DF60:
	movs r0, #0
_0804DF62:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
