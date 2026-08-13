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

	thumb_func_start FUN_0804df70
FUN_0804df70: @ 0x0804DF70
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804df74
tretista_0804df74: @ 0x0804DF74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bhi _0804E014
	lsls r0, r0, #2
	ldr r1, _0804DF88 @ =_0804DF8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DF88: .4byte _0804DF8C
_0804DF8C: @ jump table
	.4byte _0804DFAC @ case 0
	.4byte _0804DFE0 @ case 1
	.4byte _0804DFB8 @ case 2
	.4byte _0804DFE0 @ case 3
	.4byte _0804DFC0 @ case 4
	.4byte _0804DFD2 @ case 5
	.4byte _0804DFE0 @ case 6
	.4byte _0804DFFC @ case 7
_0804DFAC:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r1, _0804DFB4 @ =0x0000AB21
	b _0804DFD4
	.align 2, 0
_0804DFB4: .4byte 0x0000AB21
_0804DFB8:
	ldr r1, _0804DFBC @ =0x0000AB22
	b _0804DFD4
	.align 2, 0
_0804DFBC: .4byte 0x0000AB22
_0804DFC0:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804DFF0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E014
	b _0804DFF0
_0804DFD2:
	ldr r1, _0804DFF8 @ =0x0000AB23
_0804DFD4:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804DFE0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E014
_0804DFF0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804E014
	.align 2, 0
_0804DFF8: .4byte 0x0000AB23
_0804DFFC:
	adds r0, r5, #0
	adds r0, #0xc8
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0804E014:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e01c
FUN_0804e01c: @ 0x0804E01C
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804e020
tretista_0804e020: @ 0x0804E020
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804E030
	cmp r5, #1
	beq _0804E048
	b _0804E07E
_0804E030:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804E084 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E048:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0804E064
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804E064
	strb r2, [r4, #0x12]
	movs r0, #0xd4
	bl PlaySound
_0804E064:
	ldr r0, _0804E088 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804E078
	strb r1, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E078:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804E07E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E084: .4byte 0x0000AB09
_0804E088: .4byte gStageRun

	thumb_func_start FUN_0804e08c
FUN_0804e08c: @ 0x0804E08C
	movs r0, #1
	bx lr

	thumb_func_start tretistaNeutral
tretistaNeutral: @ 0x0804E090
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0804E116
	cmp r0, #1
	bgt _0804E0AA
	cmp r0, #0
	beq _0804E0B0
	b _0804E3E4
_0804E0AA:
	cmp r0, #2
	beq _0804E158
	b _0804E3E4
_0804E0B0:
	ldrb r0, [r6, #0xd]
	adds r1, r6, #0
	adds r1, #0xe1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0804E0D4
	ldr r1, _0804E0D0 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	b _0804E0DC
	.align 2, 0
_0804E0D0: .4byte 0x0000AB09
_0804E0D4:
	ldr r1, _0804E104 @ =0x0000AB0D
	adds r0, r6, #0
	bl SetMotion
_0804E0DC:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804E108 @ =sCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	str r1, [r6, #0x60]
	str r1, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0x64
	str r1, [r0, #4]
	str r1, [r6, #0x64]
	ldrb r0, [r6, #0xf]
	cmp r0, #0xff
	bne _0804E10C
	movs r0, #1
	strb r0, [r6, #0x13]
	strb r1, [r6, #0xf]
	b _0804E110
	.align 2, 0
_0804E104: .4byte 0x0000AB0D
_0804E108: .4byte sCollisions+(24*1)
_0804E10C:
	movs r0, #0x14
	strb r0, [r6, #0x13]
_0804E110:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E116:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E130
	str r1, [r6, #0x68]
_0804E130:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r2
	ble _0804E14A
	ldr r1, _0804E154 @ =0x0000AB09
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804E14A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _0804E3E4
	.align 2, 0
_0804E154: .4byte 0x0000AB09
_0804E158:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	bl FUN_0804ff5c
	ldr r0, [r6, #0x70]
	ldr r1, _0804E234 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _0804E238 @ =0x00080200
	cmp r0, r1
	bne _0804E180
	movs r0, #0xd4
	bl PlaySound
_0804E180:
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804E190
	str r1, [r6, #0x68]
_0804E190:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	cmp r0, r4
	ble _0804E19E
	str r4, [r6, #0x58]
_0804E19E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	beq _0804E1AE
	b _0804E3E4
_0804E1AE:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804E1B6
	b _0804E3E4
_0804E1B6:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0804E1C4
	b _0804E3E4
_0804E1C4:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _0804E2AC
	ldr r0, _0804E23C @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E250
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E240 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E244 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E248 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E24C @ =TretistaEXModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	beq _0804E224
	b _0804E31E
_0804E224:
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E234: .4byte 0x00FFFF00
_0804E238: .4byte 0x00080200
_0804E23C: .4byte gScore
_0804E240: .4byte RNG_0202f388
_0804E244: .4byte 0x000343FD
_0804E248: .4byte 0x00269EC3
_0804E24C: .4byte TretistaEXModes
_0804E250:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E29C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2A8 @ =TretistaModes
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r4, r0
	bne _0804E31E
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl tretista_0804fecc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0804E31E
	.align 2, 0
_0804E29C: .4byte RNG_0202f388
_0804E2A0: .4byte 0x000343FD
_0804E2A4: .4byte 0x00269EC3
_0804E2A8: .4byte TretistaModes
_0804E2AC:
	ldr r0, _0804E2D8 @ =gScore
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804E2EC
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E2DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E2E0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E2E4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E2E8 @ =TretistaEXModes
	b _0804E30A
	.align 2, 0
_0804E2D8: .4byte gScore
_0804E2DC: .4byte RNG_0202f388
_0804E2E0: .4byte 0x000343FD
_0804E2E4: .4byte 0x00269EC3
_0804E2E8: .4byte TretistaEXModes
_0804E2EC:
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	ldr r2, _0804E344 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804E348 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804E34C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804E350 @ =TretistaModes
_0804E30A:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r4, [r4]
_0804E31E:
	strb r4, [r6, #0xd]
	strb r7, [r6, #0xe]
	subs r0, r4, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804E3B0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E358
	ldr r0, _0804E354 @ =0x000077FF
	cmp r2, r0
	ble _0804E360
	b _0804E378
	.align 2, 0
_0804E344: .4byte RNG_0202f388
_0804E348: .4byte 0x000343FD
_0804E34C: .4byte 0x00269EC3
_0804E350: .4byte TretistaModes
_0804E354: .4byte 0x000077FF
_0804E358:
	subs r1, r1, r0
	ldr r0, _0804E370 @ =0x000077FF
	cmp r1, r0
	bgt _0804E378
_0804E360:
	ldr r0, _0804E374 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0804E3B0
	b _0804E3A8
	.align 2, 0
_0804E370: .4byte 0x000077FF
_0804E374: .4byte pZero2
_0804E378:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, [r6, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0804E394
	ldr r0, _0804E390 @ =0x000077FF
	cmp r2, r0
	ble _0804E39C
	b _0804E3B0
	.align 2, 0
_0804E390: .4byte 0x000077FF
_0804E394:
	subs r1, r1, r0
	ldr r0, _0804E3C4 @ =0x000077FF
	cmp r1, r0
	bgt _0804E3B0
_0804E39C:
	ldr r0, _0804E3C8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _0804E3B0
_0804E3A8:
	movs r4, #5
	movs r0, #0
	strb r4, [r6, #0xd]
	strb r0, [r6, #0xe]
_0804E3B0:
	cmp r4, #5
	bne _0804E3D0
	adds r0, r6, #0
	bl isTretistaFarAway
	adds r3, r0, #0
	cmp r3, #0
	bne _0804E3CC
	strb r3, [r6, #0xf]
	b _0804E3D0
	.align 2, 0
_0804E3C4: .4byte 0x000077FF
_0804E3C8: .4byte pZero2
_0804E3CC:
	movs r0, #1
	strb r0, [r6, #0xf]
_0804E3D0:
	adds r0, r6, #0
	adds r0, #0xe2
	movs r1, #0
	strb r1, [r0]
	mov r1, r8
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, r8
	strb r4, [r0]
_0804E3E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804e3f0
FUN_0804e3f0: @ 0x0804E3F0
	movs r0, #1
	bx lr

	thumb_func_start tretista_0804e3f4
tretista_0804e3f4: @ 0x0804E3F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0804E4B4
	cmp r5, #1
	bgt _0804E408
	cmp r5, #0
	beq _0804E416
	b _0804E53C
_0804E408:
	cmp r5, #2
	bne _0804E40E
	b _0804E530
_0804E40E:
	cmp r5, #3
	bne _0804E414
	b _0804E534
_0804E414:
	b _0804E53C
_0804E416:
	ldr r1, _0804E458 @ =0x0000AB0A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E45C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E464
	ldr r1, _0804E460 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	ble _0804E48E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r3
	b _0804E48C
	.align 2, 0
_0804E458: .4byte 0x0000AB0A
_0804E45C: .4byte sCollisions+(24*1)
_0804E460: .4byte pZero2
_0804E464:
	ldr r1, _0804E49C @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	bge _0804E4A4
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804E48C:
	strb r0, [r4, #0xa]
_0804E48E:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0804E4A4
	ldr r0, _0804E4A0 @ =0xFFFFFEA0
	b _0804E4A8
	.align 2, 0
_0804E49C: .4byte pZero2
_0804E4A0: .4byte 0xFFFFFEA0
_0804E4A4:
	movs r0, #0xb0
	lsls r0, r0, #1
_0804E4A8:
	str r0, [r4, #0x5c]
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E4B4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x70]
	ldr r0, _0804E4F0 @ =0x00FFFF00
	ands r1, r0
	movs r0, #0x81
	lsls r0, r0, #9
	cmp r1, r0
	beq _0804E4CE
	ldr r0, _0804E4F4 @ =0x00010900
	cmp r1, r0
	bne _0804E4D4
_0804E4CE:
	movs r0, #0xde
	bl PlaySound
_0804E4D4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0804E4F8
	movs r1, #0xd8
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804E502
	.align 2, 0
_0804E4F0: .4byte 0x00FFFF00
_0804E4F4: .4byte 0x00010900
_0804E4F8:
	ldr r1, _0804E52C @ =0xFFFF9400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804E502:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E512
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #1
	strb r0, [r4, #0x12]
_0804E512:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804E522
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E53C
_0804E522:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804E53C
	.align 2, 0
_0804E52C: .4byte 0xFFFF9400
_0804E530:
	movs r0, #3
	strb r0, [r4, #0xe]
_0804E534:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E53C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e544
FUN_0804e544: @ 0x0804E544
	movs r0, #1
	bx lr
