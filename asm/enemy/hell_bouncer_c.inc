	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807f648
FUN_0807f648: @ 0x0807F648
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _0807F654
	b _0807F984
_0807F654:
	ldrb r0, [r6, #0xe]
	cmp r0, #0x11
	bls _0807F65C
	b _0807FCFE
_0807F65C:
	lsls r0, r0, #2
	ldr r1, _0807F668 @ =_0807F66C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807F668: .4byte _0807F66C
_0807F66C: @ jump table
	.4byte _0807F6B4 @ case 0
	.4byte _0807F6DE @ case 1
	.4byte _0807F728 @ case 2
	.4byte _0807F748 @ case 3
	.4byte _0807F764 @ case 4
	.4byte _0807F778 @ case 5
	.4byte _0807F7B8 @ case 6
	.4byte _0807F7C6 @ case 7
	.4byte _0807F7E0 @ case 8
	.4byte _0807F7F6 @ case 9
	.4byte _0807F810 @ case 10
	.4byte _0807F826 @ case 11
	.4byte _0807F888 @ case 12
	.4byte _0807F896 @ case 13
	.4byte _0807F8B0 @ case 14
	.4byte _0807F8C8 @ case 15
	.4byte _0807F904 @ case 16
	.4byte _0807FCBE @ case 17
_0807F6B4:
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0807F720 @ =0x0000AC08
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, _0807F724 @ =0xFFFFFE00
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F6DE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807F6FC
	movs r0, #0xd3
	bl PlaySound
_0807F6FC:
	ldr r0, [r6, #0x64]
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r6, #0x54]
	cmp r1, r0
	bge _0807F712
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #1
	strb r0, [r1]
_0807F712:
	ldr r0, [r6, #0x64]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r1, [r6, #0x54]
	b _0807FC2A
	.align 2, 0
_0807F720: .4byte 0x0000AC08
_0807F724: .4byte 0xFFFFFE00
_0807F728:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F75C @ =0x0000AC0B
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _0807F760 @ =0xFFFFFD80
	str r0, [r6, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F748:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F75A
	b _0807FCFE
_0807F75A:
	b _0807FC2E
	.align 2, 0
_0807F75C: .4byte 0x0000AC0B
_0807F760: .4byte 0xFFFFFD80
_0807F764:
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807F7B0 @ =0x0000AC0C
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F778:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F788
	str r1, [r6, #0x60]
_0807F788:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, _0807F7B4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0807F7AC
	b _0807FCFE
_0807F7AC:
	str r0, [r6, #0x58]
	b _0807FC2E
	.align 2, 0
_0807F7B0: .4byte 0x0000AC0C
_0807F7B4: .4byte pZero2
_0807F7B8:
	ldr r1, _0807F7DC @ =0x0000AC0D
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F7C6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F7D8
	b _0807FCFE
_0807F7D8:
	b _0807FC2E
	.align 2, 0
_0807F7DC: .4byte 0x0000AC0D
_0807F7E0:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F80C @ =0x0000AC01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F7F6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807F808
	b _0807FCFE
_0807F808:
	b _0807FC2E
	.align 2, 0
_0807F80C: .4byte 0x0000AC01
_0807F810:
	ldr r1, _0807F858 @ =0x0000AC09
	adds r0, r6, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F826:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807F83C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F87A
_0807F83C:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0807F87A
	movs r1, #1
	strb r1, [r6, #0x13]
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807F85C
	movs r0, #0x10
	orrs r0, r2
	b _0807F860
	.align 2, 0
_0807F858: .4byte 0x0000AC09
_0807F85C:
	movs r0, #0xef
	ands r0, r2
_0807F860:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807F87A:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F886
	b _0807FCFE
_0807F886:
	b _0807FC2E
_0807F888:
	ldr r1, _0807F8AC @ =0x0000AC02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F896:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F8A8
	b _0807FCFE
_0807F8A8:
	b _0807FC2E
	.align 2, 0
_0807F8AC: .4byte 0x0000AC02
_0807F8B0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	ldr r0, _0807F8F8 @ =0xFFFFF900
	str r0, [r6, #0x60]
	ldr r1, _0807F8FC @ =0x0000AC03
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F8C8:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F8D8
	str r1, [r6, #0x60]
_0807F8D8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r3, _0807F900 @ =0xFFFF8800
	adds r0, r0, r3
	b _0807FC28
	.align 2, 0
_0807F8F8: .4byte 0xFFFFF900
_0807F8FC: .4byte 0x0000AC03
_0807F900: .4byte 0xFFFF8800
_0807F904:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807F974 @ =0x0000AB1B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807F978 @ =sCollisions+(7*24)
	bl SetDDP
	movs r0, #0x20
	strb r0, [r6, #0x12]
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
	ldr r4, [r6, #0x28]
	ldr r1, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r0, r1, r2
	str r0, [r6, #0x54]
	movs r3, #0x8f
	lsls r3, r3, #8
	adds r1, r1, r3
	ldr r0, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r1, [r4, #0x58]
	ldr r2, _0807F97C @ =0xFFFF6000
	adds r0, r1, r2
	str r0, [r6, #0x58]
	ldr r3, _0807F980 @ =0xFFFF8B00
	adds r1, r1, r3
	ldr r0, [r4, #0x58]
	b _0807FCAC
	.align 2, 0
_0807F974: .4byte 0x0000AB1B
_0807F978: .4byte sCollisions+(7*24)
_0807F97C: .4byte 0xFFFF6000
_0807F980: .4byte 0xFFFF8B00
_0807F984:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xf
	bls _0807F98C
	b _0807FCFE
_0807F98C:
	lsls r0, r0, #2
	ldr r1, _0807F998 @ =_0807F99C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807F998: .4byte _0807F99C
_0807F99C: @ jump table
	.4byte _0807F9DC @ case 0
	.4byte _0807F9F2 @ case 1
	.4byte _0807FA00 @ case 2
	.4byte _0807FA76 @ case 3
	.4byte _0807FAE8 @ case 4
	.4byte _0807FAFE @ case 5
	.4byte _0807FB18 @ case 6
	.4byte _0807FB34 @ case 7
	.4byte _0807FB94 @ case 8
	.4byte _0807FBA2 @ case 9
	.4byte _0807FBBC @ case 10
	.4byte _0807FBCA @ case 11
	.4byte _0807FBE4 @ case 12
	.4byte _0807FBFA @ case 13
	.4byte _0807FC48 @ case 14
	.4byte _0807FCBE @ case 15
_0807F9DC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xc0
	strb r1, [r0]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F9F2:
	ldr r0, [r6, #0x2c]
	adds r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807F9FE
	b _0807FCFE
_0807F9FE:
	b _0807FC2E
_0807FA00:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0807FAD8 @ =0x0000AC05
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
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
	ldr r0, [r6, #0x64]
	movs r1, #0x84
	lsls r1, r1, #8
	adds r0, r0, r1
	movs r1, #0x28
	strb r1, [r6, #0x12]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	movs r1, #0x28
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0xc8
	lsls r0, r0, #8
	ldr r1, _0807FADC @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x58]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FA76:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807FA86
	str r1, [r6, #0x60]
_0807FA86:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldrb r2, [r6, #0x13]
	cmp r2, #0
	bne _0807FAB6
	ldr r0, _0807FADC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r3, _0807FAE0 @ =0xFFFFA000
	adds r0, r0, r3
	cmp r1, r0
	ble _0807FAB6
	adds r0, r2, #1
	strb r0, [r6, #0x13]
	ldr r1, _0807FAE4 @ =0x0000AC06
	adds r0, r6, #0
	bl SetMotion
_0807FAB6:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FACE
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807FACE
	b _0807FCFE
_0807FACE:
	ldr r0, _0807FADC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	str r0, [r6, #0x58]
	b _0807FC2E
	.align 2, 0
_0807FAD8: .4byte 0x0000AC05
_0807FADC: .4byte pZero2
_0807FAE0: .4byte 0xFFFFA000
_0807FAE4: .4byte 0x0000AC06
_0807FAE8:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807FB14 @ =0x0000AC07
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FAFE:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FB10
	b _0807FCFE
_0807FB10:
	b _0807FC2E
	.align 2, 0
_0807FB14: .4byte 0x0000AC07
_0807FB18:
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807FB64 @ =0x0000AC09
	adds r0, r6, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FB34:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FB4A
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807FB86
_0807FB4A:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0807FB86
	movs r1, #1
	strb r1, [r6, #0x13]
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807FB68
	movs r0, #0x10
	orrs r0, r2
	b _0807FB6C
	.align 2, 0
_0807FB64: .4byte 0x0000AC09
_0807FB68:
	movs r0, #0xef
	ands r0, r2
_0807FB6C:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807FB86:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FB92
	b _0807FCFE
_0807FB92:
	b _0807FC2E
_0807FB94:
	ldr r1, _0807FBB8 @ =0x0000AC01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBA2:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807FBB4
	b _0807FCFE
_0807FBB4:
	b _0807FC2E
	.align 2, 0
_0807FBB8: .4byte 0x0000AC01
_0807FBBC:
	ldr r1, _0807FBE0 @ =0x0000AC02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBCA:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FBDC
	b _0807FCFE
_0807FBDC:
	b _0807FC2E
	.align 2, 0
_0807FBE0: .4byte 0x0000AC02
_0807FBE4:
	ldr r0, _0807FC38 @ =0xFFFFFA00
	str r0, [r6, #0x5c]
	ldr r0, _0807FC3C @ =0xFFFFF900
	str r0, [r6, #0x60]
	ldr r1, _0807FC40 @ =0x0000AC03
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBFA:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807FC0A
	str r1, [r6, #0x60]
_0807FC0A:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807FC44 @ =0xFFFF8800
	adds r0, r0, r1
_0807FC28:
	ldr r1, [r6, #0x58]
_0807FC2A:
	cmp r1, r0
	bge _0807FCFE
_0807FC2E:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0807FCFE
	.align 2, 0
_0807FC38: .4byte 0xFFFFFA00
_0807FC3C: .4byte 0xFFFFF900
_0807FC40: .4byte 0x0000AC03
_0807FC44: .4byte 0xFFFF8800
_0807FC48:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807FD04 @ =0x0000AB1B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807FD08 @ =sCollisions+(7*24)
	bl SetDDP
	movs r0, #0x20
	strb r0, [r6, #0x12]
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
	ldr r5, [r6, #0x28]
	ldr r1, [r5, #0x54]
	ldr r4, _0807FD0C @ =0xFFFF6000
	adds r0, r1, r4
	str r0, [r6, #0x54]
	ldr r2, _0807FD10 @ =0xFFFF7100
	adds r1, r1, r2
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r1, [r5, #0x58]
	adds r4, r1, r4
	str r4, [r6, #0x58]
	ldr r3, _0807FD14 @ =0xFFFF8B00
	adds r1, r1, r3
	ldr r0, [r5, #0x58]
_0807FCAC:
	subs r0, r0, r1
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FCBE:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FCE4
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807FCFE
_0807FCE4:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807FD18 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_0807FCFE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD04: .4byte 0x0000AB1B
_0807FD08: .4byte sCollisions+(7*24)
_0807FD0C: .4byte 0xFFFF6000
_0807FD10: .4byte 0xFFFF7100
_0807FD14: .4byte 0xFFFF8B00
_0807FD18: .4byte gEnemyFnTable
