	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800fa34
FUN_0800fa34: @ 0x0800FA34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _0800FA4C
	b _0800FB68
_0800FA4C:
	ldr r2, _0800FB74 @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800FB78 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800FB7C @ =0xA6600001
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r0, [r1, #0x38]
	adds r0, #0xa0
	asrs r0, r0, #4
	adds r0, #0x10
	movs r2, #0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x88
	bgt _0800FA9E
	adds r4, r6, #0
	adds r3, r0, #0
	lsls r1, r3, #0x10
	mov r0, ip
	orrs r1, r0
_0800FA90:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _0800FA9E
	adds r0, r3, r2
	cmp r0, #0x88
	ble _0800FA90
_0800FA9E:
	mov r1, r8
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xd
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r0, [r1, #0x38]
	subs r0, #0xa0
	asrs r0, r0, #3
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r2, #0x9f
	bgt _0800FB0A
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0x88
	bgt _0800FAE4
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0x89
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r6
	ldr r7, _0800FB80 @ =0xFFFF0000
_0800FAD4:
	stm r3!, {r1}
	adds r1, r1, r7
	adds r2, #1
	cmp r2, #0x9f
	bgt _0800FB0A
	adds r0, r4, r2
	cmp r0, #0x88
	ble _0800FAD4
_0800FAE4:
	cmp r2, #0x9f
	bgt _0800FB0A
	asrs r1, r5, #0x18
	adds r0, r1, r2
	cmp r0, #0x99
	bgt _0800FB0A
	lsls r0, r2, #2
	adds r4, r0, r6
	adds r3, r1, #0
	lsls r1, r3, #0x10
	mov r0, ip
	orrs r1, r0
_0800FAFC:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _0800FB0A
	adds r0, r3, r2
	cmp r0, #0x99
	ble _0800FAFC
_0800FB0A:
	mov r1, r8
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r0, [r1, #0x38]
	ldr r1, _0800FB84 @ =0xFFFFFEC0
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r2, #0x9f
	bgt _0800FB68
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0x98
	bgt _0800FB52
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0x99
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r6
	ldr r7, _0800FB80 @ =0xFFFF0000
_0800FB42:
	stm r3!, {r1}
	adds r1, r1, r7
	adds r2, #1
	cmp r2, #0x9f
	bgt _0800FB68
	adds r0, r4, r2
	cmp r0, #0x98
	ble _0800FB42
_0800FB52:
	cmp r2, #0x9f
	bgt _0800FB68
	asrs r1, r5, #8
	mov r0, ip
	orrs r1, r0
	lsls r0, r2, #2
	adds r0, r0, r6
_0800FB60:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _0800FB60
_0800FB68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FB74: .4byte gIntrManager
_0800FB78: .4byte 0x0400001C
_0800FB7C: .4byte 0xA6600001
_0800FB80: .4byte 0xFFFF0000
_0800FB84: .4byte 0xFFFFFEC0
