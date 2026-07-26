	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801304c
FUN_0801304c: @ 0x0801304C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r4, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _08013068
	b _080131EC
_08013068:
	ldr r2, _080131F8 @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080131FC @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08013200 @ =0xA6600001
	str r0, [r1]
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x10
	ldr r0, [r1, #0x38]
	ldr r2, _08013204 @ =0xFFFFFCE0
	adds r0, r0, r2
	asrs r0, r0, #4
	subs r0, #0x60
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	asrs r1, r0, #0x10
	adds r0, r1, #0
	adds r0, #0x9f
	cmp r0, #0x8f
	ble _080130C8
	adds r3, r1, #0
	ldr r2, _08013208 @ =0xFFF00000
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r7, #0x80
	lsls r7, r7, #9
_080130B6:
	str r2, [r1]
	adds r2, r2, r7
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080130F2
	adds r0, r3, r4
	cmp r0, #0x8f
	bgt _080130B6
_080130C8:
	cmp r4, #0
	blt _080130F2
	mov r1, ip
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x4f
	ble _080130F2
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_080130E2:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080130F2
	adds r0, r3, r4
	cmp r0, #0x4f
	bgt _080130E2
_080130F2:
	mov r2, sb
	ldr r0, [r2, #0x34]
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	ldr r0, [r2, #0x38]
	ldr r1, _08013204 @ =0xFFFFFCE0
	adds r0, r0, r1
	asrs r0, r0, #5
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp r4, #0
	blt _08013166
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r4
	mov r8, r0
	cmp r1, #0x4f
	ble _0801313E
	adds r3, r2, #0
	lsls r0, r4, #0x10
	movs r1, #0x9e
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r4, #2
	adds r2, r0, r6
	movs r7, #0x80
	lsls r7, r7, #9
_0801312C:
	str r1, [r2]
	adds r1, r1, r7
	subs r2, #4
	subs r4, #1
	cmp r4, #0
	blt _08013166
	adds r0, r3, r4
	cmp r0, #0x4f
	bgt _0801312C
_0801313E:
	cmp r4, #0
	blt _08013166
	mov r0, r8
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x2f
	ble _08013166
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013156:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013166
	adds r0, r3, r4
	cmp r0, #0x2f
	bgt _08013156
_08013166:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xd
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _08013198
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x27
	ble _08013198
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_08013188:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08013198
	adds r0, r3, r4
	cmp r0, #0x27
	bgt _08013188
_08013198:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xc
	lsrs r5, r0, #0x10
	cmp r4, #0
	blt _080131EC
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, r4
	cmp r0, #0x1f
	ble _080131CA
	lsls r0, r4, #2
	adds r1, r0, r6
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_080131BA:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _080131EC
	adds r0, r3, r4
	cmp r0, #0x1f
	bgt _080131BA
_080131CA:
	cmp r4, #0
	blt _080131EC
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r0, r2
	lsls r0, r4, #2
	adds r0, r0, r6
	movs r2, #0x80
	lsls r2, r2, #9
_080131E0:
	str r1, [r0]
	adds r1, r1, r2
	subs r0, #4
	subs r4, #1
	cmp r4, #0
	bge _080131E0
_080131EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080131F8: .4byte gIntrManager
_080131FC: .4byte 0x0400001C
_08013200: .4byte 0xA6600001
_08013204: .4byte 0xFFFFFCE0
_08013208: .4byte 0xFFF00000
