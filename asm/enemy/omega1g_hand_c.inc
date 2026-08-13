	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08083a04
FUN_08083a04: @ 0x08083A04
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08083A12
	b _08083E06
_08083A12:
	lsls r0, r0, #2
	ldr r1, _08083A1C @ =_08083A20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083A1C: .4byte _08083A20
_08083A20: @ jump table
	.4byte _08083A84 @ case 0
	.4byte _08083AF4 @ case 1
	.4byte _08083B48 @ case 2
	.4byte _08083B5E @ case 3
	.4byte _08083B6C @ case 4
	.4byte _08083BB2 @ case 5
	.4byte _08083C1C @ case 6
	.4byte _08083C42 @ case 7
	.4byte _08083E06 @ case 8
	.4byte _08083E06 @ case 9
	.4byte _08083CC8 @ case 10
	.4byte _08083CF2 @ case 11
	.4byte _08083D10 @ case 12
	.4byte _08083E06 @ case 13
	.4byte _08083E06 @ case 14
	.4byte _08083E06 @ case 15
	.4byte _08083E06 @ case 16
	.4byte _08083E06 @ case 17
	.4byte _08083E06 @ case 18
	.4byte _08083E06 @ case 19
	.4byte _08083D2A @ case 20
	.4byte _08083D94 @ case 21
	.4byte _08083DA6 @ case 22
	.4byte _08083DE0 @ case 23
	.4byte _08083DE6 @ case 24
_08083A84:
	ldr r1, _08083B3C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r3, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r3, [r0]
	movs r2, #0x20
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083B40 @ =0x08368298
	bl SetDDP
	strb r4, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	str r4, [r5, #0x60]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x68]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083AF4:
	ldrb r0, [r5, #0x13]
	cmp r0, #0x3f
	bhi _08083AFE
	adds r0, #4
	strb r0, [r5, #0x13]
_08083AFE:
	ldrb r0, [r5, #0x13]
	mvns r0, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08083B1E
	str r1, [r5, #0x60]
_08083B1E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	ldr r2, _08083B44 @ =0xFFFFFE00
	adds r1, r1, r2
	cmp r0, r1
	bgt _08083B32
	b _08083E06
_08083B32:
	str r1, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083B3C: .4byte 0x00000902
_08083B40: .4byte 0x08368298
_08083B44: .4byte 0xFFFFFE00
_08083B48:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083B50
	b _08083E06
_08083B50:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083B5C
	b _08083E06
_08083B5C:
	b _08083DD2
_08083B5E:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083B6C:
	ldr r1, _08083C04 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
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
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C08 @ =0x08368298
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _08083C0C @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083BB2:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083C10 @ =0xFFFFD180
	adds r4, r0, #0
	cmp r2, r1
	bge _08083BD0
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08083BD0
	str r1, [r5, #0x60]
_08083BD0:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r1, _08083C14 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r4]
	ldr r0, _08083C18 @ =0xFFFFD000
	cmp r1, r0
	bge _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #6
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C04: .4byte 0x00000902
_08083C08: .4byte 0x08368298
_08083C0C: .4byte 0xFFFFFF00
_08083C10: .4byte 0xFFFFD180
_08083C14: .4byte 0xFFFFFE00
_08083C18: .4byte 0xFFFFD000
_08083C1C:
	ldr r1, _08083C94 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C98 @ =0x08368298
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _08083C9C @ =0xFFFFD000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083C42:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083CA0 @ =0xFFFFFE80
	adds r4, r0, #0
	cmp r2, r1
	ble _08083C5E
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0x3f
	bgt _08083C5E
	movs r0, #0x40
	str r0, [r5, #0x60]
_08083C5E:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r4, _08083CA4 @ =0xFFFFFE00
	adds r0, r0, r4
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x68]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #4
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C94: .4byte 0x00000902
_08083C98: .4byte 0x08368298
_08083C9C: .4byte 0xFFFFD000
_08083CA0: .4byte 0xFFFFFE80
_08083CA4: .4byte 0xFFFFFE00
_08083CA8:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _08083E06
_08083CAE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CB6
	b _08083E06
_08083CB6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CC2
	b _08083E06
_08083CC2:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _08083E06
_08083CC8:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	ldr r2, _08083D08 @ =0xFFFFEE00
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldr r0, _08083D0C @ =0x0000012D
	bl PlaySound
	movs r1, #0xc8
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac880
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083CF2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CFA
	b _08083E06
_08083CFA:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083D06
	b _08083E06
_08083D06:
	b _08083DD2
	.align 2, 0
_08083D08: .4byte 0xFFFFEE00
_08083D0C: .4byte 0x0000012D
_08083D10:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08083D24
	movs r0, #7
	strb r0, [r5, #0xe]
	b _08083E06
_08083D24:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _08083E06
_08083D2A:
	ldr r1, _08083D8C @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _08083D90 @ =0x08368268
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x32
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083D8C: .4byte 0x00000901
_08083D90: .4byte 0x08368268
_08083D94:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08083E06
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08083E06
	b _08083DD2
_08083DA6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	subs r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08083DBC
	str r1, [r5, #0x60]
_08083DBC:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _08083DDC @ =0xFFFFC800
	adds r0, r0, r2
	cmp r1, r0
	bge _08083E06
	str r0, [r5, #0x58]
_08083DD2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083DDC: .4byte 0xFFFFC800
_08083DE0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083DE6:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _08083E10 @ =0xFFFFC800
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _08083E06
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08083E06:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083E10: .4byte 0xFFFFC800

	thumb_func_start FUN_08083e14
FUN_08083e14:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083e18
FUN_08083e18: @ 0x08083E18
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _08083E28
	cmp r3, #1
	beq _08083E48
	b _08083E64
_08083E28:
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	str r3, [r2, #0x5c]
	str r3, [r2, #0x60]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083E48:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	cmp r0, #0x40
	ble _08083E56
	movs r0, #0x40
	str r0, [r2, #0x60]
_08083E56:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0
	bl UpdateEntityAnim
_08083E64:
	pop {r0}
	bx r0

	thumb_func_start FUN_08083e68
FUN_08083e68: @ 0x08083E68
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _08083E78
	cmp r3, #1
	beq _08083EA2
	b _08083EA8
_08083E78:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083EA2:
	adds r0, r2, #0
	bl UpdateEntityAnim
_08083EA8:
	pop {r0}
	bx r0

	thumb_func_start nop_08083eac
nop_08083eac: @ 0x08083EAC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083eb0
FUN_08083eb0: @ 0x08083EB0
	adds r3, r0, #0
	adds r3, #0xc1
	movs r2, #0
	movs r1, #1
	strb r1, [r3]
	movs r1, #4
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	movs r0, #1
	bx lr

	thumb_func_start FUN_08083ec4
FUN_08083ec4: @ 0x08083EC4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08083ED4
	cmp r5, #1
	beq _08083F0C
	b _08083F40
_08083ED4:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc1
	strb r5, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08083F0C:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _08083F48 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08083F40:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083F48: .4byte gSineTable

	thumb_func_start FUN_08083f4c
FUN_08083f4c: @ 0x08083F4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08083F5C
	cmp r5, #1
	beq _08083FAA
	b _08083FE0
_08083F5C:
	ldr r1, _08083FE8 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc1
	strb r5, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08083FAA:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _08083FEC @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r3, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r3, #0x58]
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08083FE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083FE8: .4byte 0x00000901
_08083FEC: .4byte gSineTable

	thumb_func_start FUN_08083ff0
FUN_08083ff0:
	movs r0, #1
	bx lr
	.align 2, 0
