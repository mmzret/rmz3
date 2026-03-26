	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08096fb0
FUN_08096fb0: @ 0x08096FB0
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x54]
	str r1, [r3, #0x64]
	ldr r1, [r3, #0x58]
	str r1, [r3, #0x68]
	adds r2, r3, #0
	adds r2, #0xc0
	movs r1, #0
	str r1, [r2]
	ldr r1, _08096FF4 @ =0xFFFFFE00
	str r1, [r3, #0x5c]
	adds r4, r1, #0
	ldrb r2, [r3, #0xa]
	movs r1, #0x10
	ands r1, r2
	cmp r1, #0
	beq _08096FD8
	movs r4, #0x80
	lsls r4, r4, #2
_08096FD8:
	str r4, [r3, #0x5c]
	ldr r1, _08096FF8 @ =0xFFFFFC00
	str r1, [r3, #0x60]
	adds r4, r1, #0
	movs r1, #0x20
	ands r1, r2
	cmp r1, #0
	beq _08096FEC
	movs r4, #0x80
	lsls r4, r4, #3
_08096FEC:
	str r4, [r3, #0x60]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08096FF4: .4byte 0xFFFFFE00
_08096FF8: .4byte 0xFFFFFC00

	thumb_func_start FUN_08096ffc
FUN_08096ffc: @ 0x08096FFC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r6, #0
	cmp r2, #0
	bne _0809700A
	b _08097118
_0809700A:
	ldr r0, [r5, #0x68]
	adds r1, r0, r2
	str r1, [r5, #0x68]
	movs r2, #0
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0809701A
	movs r2, #1
_0809701A:
	adds r4, r2, #0
	ldr r0, [r5, #0x64]
	ldr r2, _08097044 @ =0xFFFFF900
	adds r3, r0, r2
	adds r2, r1, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08097048 @ =0xFFFFD100
	cmp r0, #0
	beq _0809704C
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _0809704C
	adds r0, r1, #0
	muls r0, r4, r0
	b _08097052
	.align 2, 0
_08097044: .4byte 0xFFFFF900
_08097048: .4byte 0xFFFFD100
_0809704C:
	movs r0, #1
	eors r0, r4
	muls r0, r1, r0
_08097052:
	adds r2, r2, r0
	cmp r4, #0
	beq _08097074
	ldr r0, _08097070 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097094
	ldr r0, [r5, #0x68]
	movs r1, #0x80
	lsls r1, r1, #1
	b _0809708A
	.align 2, 0
_08097070: .4byte 0xFFFFFF00
_08097074:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097094
	ldr r0, [r5, #0x68]
	ldr r1, _080970C8 @ =0xFFFFFF00
_0809708A:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r5, #0x68]
	movs r0, #1
	orrs r6, r0
_08097094:
	movs r1, #0
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0809709E
	movs r1, #1
_0809709E:
	adds r4, r1, #0
	ldr r0, [r5, #0x64]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r3, r0, r2
	ldr r2, [r5, #0x68]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080970CC @ =0xFFFFD100
	cmp r0, #0
	beq _080970D0
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _080970D0
	adds r0, r1, #0
	muls r0, r4, r0
	b _080970D6
	.align 2, 0
_080970C8: .4byte 0xFFFFFF00
_080970CC: .4byte 0xFFFFD100
_080970D0:
	movs r0, #1
	eors r0, r4
	muls r0, r1, r0
_080970D6:
	adds r2, r2, r0
	cmp r4, #0
	beq _080970F8
	ldr r0, _080970F4 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097118
	ldr r0, [r5, #0x68]
	movs r1, #0x80
	lsls r1, r1, #1
	b _0809710E
	.align 2, 0
_080970F4: .4byte 0xFFFFFF00
_080970F8:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097118
	ldr r0, [r5, #0x68]
	ldr r1, _08097154 @ =0xFFFFFF00
_0809710E:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r5, #0x68]
	movs r0, #1
	orrs r6, r0
_08097118:
	cmp r7, #0
	beq _080971E8
	ldr r0, [r5, #0x64]
	adds r1, r0, r7
	str r1, [r5, #0x64]
	movs r2, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _0809712C
	movs r2, #1
_0809712C:
	adds r4, r2, #0
	ldr r2, _08097158 @ =0xFFFFF900
	adds r3, r1, r2
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r0, [r5, #0x68]
	ldr r1, _0809715C @ =0xFFFFFE00
	adds r2, r0, r1
	cmp r4, #0
	beq _08097160
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _0809717C
	b _0809716E
	.align 2, 0
_08097154: .4byte 0xFFFFFF00
_08097158: .4byte 0xFFFFF900
_0809715C: .4byte 0xFFFFFE00
_08097160:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _0809717C
_0809716E:
	ldr r0, [r5, #0x64]
	adds r0, r0, r3
	str r0, [r5, #0x64]
	movs r0, #2
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_0809717C:
	movs r1, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _08097186
	movs r1, #1
_08097186:
	adds r4, r1, #0
	ldr r3, [r5, #0x64]
	ldr r2, _080971AC @ =0xFFFFF900
	adds r3, r3, r2
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r2, [r5, #0x68]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080971B0
	movs r0, #0xb4
	lsls r0, r0, #6
	adds r2, r2, r0
	b _080971B4
	.align 2, 0
_080971AC: .4byte 0xFFFFF900
_080971B0:
	ldr r1, _080971C8 @ =0xFFFFD300
	adds r2, r2, r1
_080971B4:
	cmp r4, #0
	beq _080971CC
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _080971E8
	b _080971DA
	.align 2, 0
_080971C8: .4byte 0xFFFFD300
_080971CC:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _080971E8
_080971DA:
	ldr r0, [r5, #0x64]
	adds r0, r0, r3
	str r0, [r5, #0x64]
	movs r0, #2
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_080971E8:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _08097208
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _08097208
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _08097208
	adds r1, r5, #0
	adds r1, #0xc0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0809720E
_08097208:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
_0809720E:
	movs r0, #2
	ands r6, r0
	cmp r6, #0
	beq _0809721C
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_0809721C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08097224
FUN_08097224: @ 0x08097224
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r7, #0
	cmp r2, #0
	bne _08097232
	b _08097340
_08097232:
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	movs r2, #0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08097242
	movs r2, #1
_08097242:
	adds r5, r2, #0
	ldr r0, [r4, #0x54]
	ldr r2, _0809726C @ =0xFFFFF900
	adds r3, r0, r2
	adds r2, r1, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08097270 @ =0xFFFFD100
	cmp r0, #0
	beq _08097274
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _08097274
	adds r0, r1, #0
	muls r0, r5, r0
	b _0809727A
	.align 2, 0
_0809726C: .4byte 0xFFFFF900
_08097270: .4byte 0xFFFFD100
_08097274:
	movs r0, #1
	eors r0, r5
	muls r0, r1, r0
_0809727A:
	adds r2, r2, r0
	cmp r5, #0
	beq _0809729C
	ldr r0, _08097298 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _080972BC
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	b _080972B2
	.align 2, 0
_08097298: .4byte 0xFFFFFF00
_0809729C:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _080972BC
	ldr r0, [r4, #0x58]
	ldr r1, _080972F0 @ =0xFFFFFF00
_080972B2:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #1
	orrs r7, r0
_080972BC:
	movs r1, #0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _080972C6
	movs r1, #1
_080972C6:
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r3, r0, r2
	ldr r2, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080972F4 @ =0xFFFFD100
	cmp r0, #0
	beq _080972F8
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _080972F8
	adds r0, r1, #0
	muls r0, r5, r0
	b _080972FE
	.align 2, 0
_080972F0: .4byte 0xFFFFFF00
_080972F4: .4byte 0xFFFFD100
_080972F8:
	movs r0, #1
	eors r0, r5
	muls r0, r1, r0
_080972FE:
	adds r2, r2, r0
	cmp r5, #0
	beq _08097320
	ldr r0, _0809731C @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097340
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	b _08097336
	.align 2, 0
_0809731C: .4byte 0xFFFFFF00
_08097320:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097340
	ldr r0, [r4, #0x58]
	ldr r1, _0809738C @ =0xFFFFFF00
_08097336:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #1
	orrs r7, r0
_08097340:
	cmp r6, #0
	beq _08097420
	ldr r0, [r4, #0x54]
	adds r1, r0, r6
	str r1, [r4, #0x54]
	movs r2, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08097354
	movs r2, #1
_08097354:
	adds r5, r2, #0
	ldr r2, _08097390 @ =0xFFFFF900
	adds r3, r1, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r6, [r4, #0x58]
	ldr r0, _08097394 @ =0xFFFFFE00
	adds r2, r6, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097378
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, r6, r1
_08097378:
	cmp r5, #0
	beq _08097398
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _080973B4
	b _080973A6
	.align 2, 0
_0809738C: .4byte 0xFFFFFF00
_08097390: .4byte 0xFFFFF900
_08097394: .4byte 0xFFFFFE00
_08097398:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _080973B4
_080973A6:
	ldr r0, [r4, #0x54]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	movs r0, #2
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_080973B4:
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080973BE
	movs r1, #1
_080973BE:
	adds r5, r1, #0
	ldr r3, [r4, #0x54]
	ldr r2, _080973E4 @ =0xFFFFF900
	adds r3, r3, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r2, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080973E8
	movs r0, #0xb4
	lsls r0, r0, #6
	adds r2, r2, r0
	b _080973EC
	.align 2, 0
_080973E4: .4byte 0xFFFFF900
_080973E8:
	ldr r1, _08097400 @ =0xFFFFD300
	adds r2, r2, r1
_080973EC:
	cmp r5, #0
	beq _08097404
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _08097420
	b _08097412
	.align 2, 0
_08097400: .4byte 0xFFFFD300
_08097404:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _08097420
_08097412:
	ldr r0, [r4, #0x54]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	movs r0, #2
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_08097420:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08097428
FUN_08097428: @ 0x08097428
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	mov r2, sp
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #1]
	strb r0, [r2]
	ldr r0, [r5, #0x54]
	ldr r1, _08097454 @ =0xFFFFF900
	adds r2, r0, r1
	ldr r4, [r5, #0x58]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097458
	movs r0, #0xb8
	lsls r0, r0, #6
	adds r4, r4, r0
	b _0809745C
	.align 2, 0
_08097454: .4byte 0xFFFFF900
_08097458:
	ldr r1, _080974B8 @ =0xFFFFD200
	adds r4, r4, r1
_0809745C:
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _0809746E
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0809746E:
	ldr r2, [r5, #0x54]
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _08097482
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08097482:
	ldr r0, [r5, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _0809749C
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0809749C:
	ldr r0, [r5, #0x54]
	ldr r1, _080974BC @ =0xFFFFF900
	adds r2, r0, r1
	ldr r4, [r5, #0x58]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080974C0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
	b _080974C4
	.align 2, 0
_080974B8: .4byte 0xFFFFD200
_080974BC: .4byte 0xFFFFF900
_080974C0:
	ldr r1, _08097518 @ =0xFFFFFF00
	adds r4, r4, r1
_080974C4:
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _080974D6
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_080974D6:
	ldr r2, [r5, #0x54]
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _080974EA
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_080974EA:
	ldr r0, [r5, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _08097504
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08097504:
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0]
	ldrb r1, [r1, #1]
	ands r0, r1
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08097518: .4byte 0xFFFFFF00

	thumb_func_start CannonHopper_Init
CannonHopper_Init: @ 0x0809751C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080975A8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _080975AC @ =0x0836A418
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0xa]
	movs r1, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080975B0 @ =0x0836A288
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080975B4 @ =0x080978C9
	str r0, [r4, #0x24]
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r2, #0
	ldr r0, _080975B8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809759C
	movs r2, #1
_0809759C:
	cmp r2, #0
	beq _080975BC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080975C2
	.align 2, 0
_080975A8: .4byte gEnemyFnTable
_080975AC: .4byte 0x0836A418
_080975B0: .4byte 0x0836A288
_080975B4: .4byte 0x080978C9
_080975B8: .4byte pZero2
_080975BC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080975C2:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	str r3, [r0]
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x28]
	adds r0, r5, #0
	adds r0, #0xbf
	strb r3, [r0]
	adds r0, r5, #0
	bl CannonHopper_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start CannonHopper_Update
CannonHopper_Update: @ 0x080975FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08097620
	adds r0, r4, #0
	bl FUN_08097428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08097682
_08097620:
	ldrb r2, [r4, #0xd]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809763E
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0809763C
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
_0809763C:
	movs r2, #1
_0809763E:
	ldr r1, _08097668 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0809766C
	movs r0, #1
	b _08097678
	.align 2, 0
_08097668: .4byte gEnemyFnTable
_0809766C:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08097678
	movs r0, #3
_08097678:
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl CannonHopper_Die
	b _08097844
_08097682:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r5, [r0]
	adds r7, r0, #0
	cmp r5, #0
	bne _08097702
	ldr r0, [r6]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _08097702
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0809775A
	ldr r2, _08097794 @ =0x0836A41C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r7]
	cmp r0, #0
	beq _08097702
	adds r0, r4, #0
	adds r0, #0xbf
	strb r6, [r0]
	subs r0, #0x4b
	ldr r1, _08097798 @ =0x0836A378
	bl SetDDP
	str r5, [r4, #0x60]
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080976E2
	ldr r0, [r4, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080976E2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08097702:
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0809775A
	ldr r0, [r7]
	cmp r0, #0
	bne _0809776A
	adds r0, r4, #0
	adds r0, #0xbf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809775A
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08097732
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0809772C
	movs r0, #1
	strb r0, [r4, #0xf]
_0809772C:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0809775A
_08097732:
	cmp r0, #1
	bne _08097740
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r4, #0xf]
_08097740:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _0809774C
	strb r0, [r4, #0xf]
_0809774C:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0809779C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08097844
_0809775A:
	ldr r0, [r7]
	cmp r0, #0
	bne _0809776A
	adds r0, r4, #0
	adds r0, #0xbf
	ldrb r0, [r0]
	cmp r0, #0
	beq _08097770
_0809776A:
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	bne _080977A8
_08097770:
	ldr r1, _080977A0 @ =0x0836A3D8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080977A4 @ =0x0836A3F0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08097844
	.align 2, 0
_08097794: .4byte 0x0836A41C
_08097798: .4byte 0x0836A378
_0809779C: .4byte 0x00020001
_080977A0: .4byte 0x0836A3D8
_080977A4: .4byte 0x0836A3F0
_080977A8:
	ldr r0, [r7]
	cmp r0, #0
	beq _080977C4
	bl isKilled
	cmp r0, #0
	beq _080977C4
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097850 @ =0x0836A288
	bl SetDDP
	movs r0, #0
	str r0, [r7]
_080977C4:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _0809782E
	adds r6, r4, #0
	adds r6, #0xbf
	ldrb r0, [r6]
	cmp r0, #0
	beq _0809782E
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r7, #0xe0
	lsls r7, r7, #3
	cmp r0, r7
	ble _080977EA
	str r7, [r4, #0x60]
_080977EA:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08097854 @ =0xFFFFF900
	adds r0, r0, r2
	ldr r2, _08097858 @ =0xFFFFFF00
	mov r8, r2
	add r1, r8
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08097812
	str r5, [r4, #0x60]
	strb r5, [r6]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08097812:
	ldr r0, [r4, #0x54]
	adds r0, r0, r7
	ldr r1, [r4, #0x58]
	add r1, r8
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809782E
	str r5, [r4, #0x60]
	strb r5, [r6]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809782E:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0809785C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08097844
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097844:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097850: .4byte 0x0836A288
_08097854: .4byte 0xFFFFF900
_08097858: .4byte 0xFFFFFF00
_0809785C: .4byte 0x00020001

	thumb_func_start CannonHopper_Die
CannonHopper_Die: @ 0x08097860
	push {lr}
	adds r3, r0, #0
	ldr r0, _080978A8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080978B0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080978AC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080978C0
	.align 2, 0
_080978A8: .4byte gCurStory
_080978AC: .4byte gEnemyFnTable
_080978B0:
	ldr r0, _080978C4 @ =0x0836A408
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080978C0:
	pop {r0}
	bx r0
	.align 2, 0
_080978C4: .4byte 0x0836A408

	thumb_func_start FUN_080978c8
FUN_080978c8:
	.byte 0xC1, 0x6A, 0x0A, 0x1C, 0xB4, 0x32, 0x03, 0x48
	.byte 0x00, 0x68, 0x40, 0x6D, 0x49, 0x6D, 0x40, 0x1A, 0x10, 0x60, 0x70, 0x47, 0x40, 0xF3, 0x02, 0x02

	thumb_func_start FUN_080978e0
FUN_080978e0:
  bx lr

	thumb_func_start FUN_080978e4
FUN_080978e4: @ 0x080978E4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08097900 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080978FC
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080978FC:
	pop {r0}
	bx r0
	.align 2, 0
_08097900: .4byte 0x00020001

	thumb_func_start FUN_08097904
FUN_08097904: @ 0x08097904
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08097920 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809791C
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0809791C:
	pop {r0}
	bx r0
	.align 2, 0
_08097920: .4byte 0x00020001

	thumb_func_start FUN_08097924
FUN_08097924: @ 0x08097924
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097934
	cmp r0, #1
	beq _080979E8
	b _08097A0C
_08097934:
	adds r1, r4, #0
	adds r1, #0xbe
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08096fb0
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097974 @ =0x0836A288
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08097994
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _08097978
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r2, r0
	bgt _08097982
	b _080979E2
	.align 2, 0
_08097974: .4byte 0x0836A288
_08097978:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	ble _080979E2
_08097982:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_08097994:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _080979A8
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	bgt _080979B2
	b _080979E2
_080979A8:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _080979E2
_080979B2:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_080979C4:
	movs r0, #0xef
	ands r0, r2
_080979C8:
	strb r0, [r4, #0xa]
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
_080979E2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080979E8:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08096ffc
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08097A06
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097A06:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097a14
cannonHopper_08097a14: @ 0x08097A14
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097A24
	cmp r0, #1
	beq _08097A60
	b _08097AF0
_08097A24:
	ldr r1, _08097A7C @ =0x0000DC01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x15
	strb r0, [r4, #0x12]
	ldr r0, _08097A80 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08097A44
	movs r2, #0x80
	lsls r2, r2, #2
_08097A44:
	str r2, [r4, #0x5c]
	ldr r0, _08097A84 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	adds r2, r0, #0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097A58
	movs r2, #0x80
	lsls r2, r2, #3
_08097A58:
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08097A60:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08097A8C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08097AEA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097A88 @ =0x0836A2B8
	bl SetDDP
	b _08097AEA
	.align 2, 0
_08097A7C: .4byte 0x0000DC01
_08097A80: .4byte 0xFFFFFE00
_08097A84: .4byte 0xFFFFFC00
_08097A88: .4byte 0x0836A2B8
_08097A8C:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08097224
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq _08097AD4
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097AB0
	movs r0, #0x10
	orrs r0, r2
	b _08097AB4
_08097AB0:
	movs r0, #0xef
	ands r0, r2
_08097AB4:
	strb r0, [r4, #0xa]
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
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
_08097AD4:
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #9
	bgt _08097AEA
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097AEA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097AF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097af8
cannonHopper_08097af8: @ 0x08097AF8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _08097B08
	cmp r4, #1
	beq _08097B20
	b _08097CBC
_08097B08:
	adds r0, r6, #0
	adds r0, #0xbe
	strb r4, [r0]
	ldr r1, _08097B40 @ =0x0000DC02
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08097B20:
	ldrb r0, [r6, #0x13]
	cmp r0, #8
	bls _08097B48
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08097B44 @ =0x0836A348
	adds r0, r4, #0
	bl SetDDP
	adds r1, r6, #0
	adds r1, #0xbe
	movs r0, #4
	strb r0, [r1]
	adds r7, r1, #0
	adds r5, r4, #0
	b _08097B72
	.align 2, 0
_08097B40: .4byte 0x0000DC02
_08097B44: .4byte 0x0836A348
_08097B48:
	adds r5, r6, #0
	adds r5, #0x74
	ldr r4, _08097BB0 @ =0x0836A424
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _08097BB4 @ =0x0836A288
	adds r1, r1, r0
	adds r0, r5, #0
	bl SetDDP
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0xbe
	strb r1, [r0]
	adds r7, r0, #0
_08097B72:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	movs r4, #0
	strb r0, [r6, #0x13]
	ldr r1, [r6, #0x5c]
	ldr r2, [r6, #0x60]
	adds r0, r6, #0
	bl FUN_08097224
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08097B98
	str r4, [r6, #0x5c]
	str r4, [r6, #0x60]
	strb r1, [r6, #0x12]
_08097B98:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08097BDC
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _08097BB8
	movs r0, #0x10
	orrs r0, r2
	b _08097BBC
	.align 2, 0
_08097BB0: .4byte 0x0836A424
_08097BB4: .4byte 0x0836A288
_08097BB8:
	movs r0, #0xef
	ands r0, r2
_08097BBC:
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
	ldr r0, [r6, #0x5c]
	rsbs r0, r0, #0
	str r0, [r6, #0x5c]
_08097BDC:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08097C64
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08097C64
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08097C06
	ldr r0, [r6, #0x58]
	movs r1, #0xbc
	lsls r1, r1, #6
	b _08097C0A
_08097C06:
	ldr r0, [r6, #0x58]
	ldr r1, _08097C20 @ =0xFFFFD100
_08097C0A:
	adds r0, r0, r1
	str r0, [r6, #0x58]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x1d
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097C24
	movs r0, #0x20
	orrs r0, r2
	b _08097C28
	.align 2, 0
_08097C20: .4byte 0xFFFFD100
_08097C24:
	movs r0, #0xdf
	ands r0, r2
_08097C28:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r4, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08097C60 @ =0x0836A288
	adds r0, r5, #0
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r7]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _08097CBC
	.align 2, 0
_08097C60: .4byte 0x0836A288
_08097C64:
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097C7E
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r1, r0
	b _08097C8C
_08097C7E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r0, r1
_08097C8C:
	ldr r0, _08097CC4 @ =0x00001FFF
	cmp r1, r0
	bgt _08097CB6
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CA0
	adds r0, #0xff
_08097CA0:
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CB2
	adds r0, #0xff
_08097CB2:
	asrs r0, r0, #8
	str r0, [r6, #0x60]
_08097CB6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08097CBC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097CC4: .4byte 0x00001FFF

	thumb_func_start FUN_08097cc8
FUN_08097cc8: @ 0x08097CC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097CD8
	cmp r0, #1
	beq _08097CEA
	b _08097D04
_08097CD8:
	ldr r1, _08097D0C @ =0x0000DC03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08097CEA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08097CFE
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097CFE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097D04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097D0C: .4byte 0x0000DC03

	thumb_func_start cannonHopper_08097d10
cannonHopper_08097d10: @ 0x08097D10
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _08097D1E
	b _08097F34
_08097D1E:
	lsls r0, r0, #2
	ldr r1, _08097D28 @ =_08097D2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08097D28: .4byte _08097D2C
_08097D2C: @ jump table
	.4byte _08097D40 @ case 0
	.4byte _08097D98 @ case 1
	.4byte _08097DB4 @ case 2
	.4byte _08097E88 @ case 3
	.4byte _08097E9C @ case 4
_08097D40:
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0xbd
	strb r0, [r1]
	ldr r0, _08097D68 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsrs r2, r0, #0x1f
	cmp r2, #0
	beq _08097D6C
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08097D72
	.align 2, 0
_08097D68: .4byte pZero2
_08097D6C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08097D72:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097D98:
	ldr r0, _08097E6C @ =0x0000DC14
	adds r1, r0, #0
	ldrb r0, [r5, #0x13]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097DB4:
	ldr r1, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_08096ffc
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bne _08097E52
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08097E52
	ldr r0, _08097E70 @ =0x0836A42D
	ldrb r1, [r5, #0x13]
	subs r2, r1, #1
	adds r0, r2, r0
	ldrb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08097DF2
	movs r0, #0x80
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08097DF2:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08097E06
	movs r0, #0xff
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08097E06:
	ldr r1, [r5, #0x54]
	str r1, [sp]
	ldr r0, _08097E74 @ =0x0836A434
	lsls r3, r2, #2
	adds r2, r3, r0
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [sp]
	adds r1, r0, #0
	cmp r6, #0
	beq _08097E22
	ldr r0, [r2]
	lsls r0, r0, #1
	subs r1, r1, r0
_08097E22:
	str r1, [sp]
	ldr r1, [r5, #0x58]
	str r1, [sp, #4]
	ldr r0, _08097E78 @ =0x0836A448
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r2, r0, #0
	cmp r7, #0
	beq _08097E3E
	ldr r0, [r3]
	lsls r0, r0, #1
	subs r2, r2, r0
_08097E3E:
	str r2, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_08097E52:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08097E80
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08097E7C
	movs r0, #3
	b _08097E7E
	.align 2, 0
_08097E6C: .4byte 0x0000DC14
_08097E70: .4byte 0x0836A42D
_08097E74: .4byte 0x0836A434
_08097E78: .4byte 0x0836A448
_08097E7C:
	movs r0, #1
_08097E7E:
	strb r0, [r5, #0xe]
_08097E80:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08097F34
_08097E88:
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097E9C:
	ldr r1, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_08096ffc
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08097F2E
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r2, [r0]
	cmp r2, #0
	beq _08097EC4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08097ECA
_08097EC4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08097ECA:
	strb r0, [r5, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	adds r4, r5, #0
	adds r4, #0x4c
	strb r1, [r4]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	adds r6, r3, #0
	cmp r0, #0x4f
	bgt _08097F00
	movs r0, #3
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
	b _08097F2E
_08097F00:
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	adds r1, r7, #0
	bics r1, r0
	cmp r1, #0
	beq _08097F12
	movs r0, #0x10
	orrs r0, r2
	b _08097F16
_08097F12:
	movs r0, #0xef
	ands r0, r2
_08097F16:
	strb r0, [r5, #0xa]
	movs r3, #0
	strb r1, [r4]
	lsls r1, r1, #4
	ldrb r2, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	strb r3, [r5, #0xd]
	strb r3, [r5, #0xe]
_08097F2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08097F34:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08097f3c
FUN_08097f3c: @ 0x08097F3C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097F50
	cmp r0, #1
	bne _08097F4E
	b _0809805E
_08097F4E:
	b _080980FA
_08097F50:
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08097F8C
	cmp r0, #2
	bgt _08097F64
	cmp r0, #1
	beq _08097F6E
	b _08098038
_08097F64:
	cmp r0, #3
	beq _08097FB0
	cmp r0, #4
	beq _08097FE4
	b _08098038
_08097F6E:
	ldr r3, [r4, #0x58]
	ldr r1, _08097F88 @ =0xFFFFEE00
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FA6
	movs r0, #0x90
	lsls r0, r0, #5
	b _08097FA4
	.align 2, 0
_08097F88: .4byte 0xFFFFEE00
_08097F8C:
	ldr r3, [r4, #0x58]
	ldr r1, _08097FAC @ =0xFFFFE800
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FA6
	movs r0, #0xc0
	lsls r0, r0, #5
_08097FA4:
	adds r2, r3, r0
_08097FA6:
	str r2, [r4, #0x58]
	b _08098038
	.align 2, 0
_08097FAC: .4byte 0xFFFFE800
_08097FB0:
	ldr r3, [r4, #0x58]
	ldr r1, _08097FE0 @ =0xFFFFDD00
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FCA
	movs r0, #0x8c
	lsls r0, r0, #6
	adds r2, r3, r0
_08097FCA:
	str r2, [r4, #0x58]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1d
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _08098018
	movs r0, #0x20
	orrs r0, r1
	b _0809801C
	.align 2, 0
_08097FE0: .4byte 0xFFFFDD00
_08097FE4:
	ldr r3, [r4, #0x58]
	ldr r1, _08098014 @ =0xFFFFD500
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FFE
	movs r0, #0xac
	lsls r0, r0, #6
	adds r2, r3, r0
_08097FFE:
	str r2, [r4, #0x58]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1d
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _08098018
	movs r0, #0x20
	orrs r0, r1
	b _0809801C
	.align 2, 0
_08098014: .4byte 0xFFFFD500
_08098018:
	movs r0, #0xdf
	ands r0, r1
_0809801C:
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_08098038:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809805E:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080980B0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c6e70
	movs r0, #0x2a
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080980C6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r5, #0
	bgt _080980C0
	cmp r1, #0
	bge _080980B4
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _080980C4
	.align 2, 0
_080980B0: .4byte 0xFFFFF800
_080980B4:
	rsbs r0, r5, #0
	cmp r0, r1
	bge _080980C0
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _080980C4
_080980C0:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
_080980C4:
	str r0, [r4, #0x58]
_080980C6:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08098104 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098108 @ =0x0000270E
	cmp r1, r0
	bhi _080980E0
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080980E0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0809810C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080980FA:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098104: .4byte gMission
_08098108: .4byte 0x0000270E
_0809810C: .4byte gEnemyFnTable

	thumb_func_start FUN_08098110
FUN_08098110: @ 0x08098110
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	bne _0809811E
	b _080982FA
_0809811E:
	cmp r0, #1
	bgt _08098128
	cmp r0, #0
	beq _08098130
	b _08098406
_08098128:
	cmp r0, #2
	bne _0809812E
	b _080983E0
_0809812E:
	b _08098406
_08098130:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098170
	cmp r0, #2
	bgt _08098146
	cmp r0, #1
	beq _08098154
	b _0809814E
_08098146:
	cmp r0, #3
	beq _0809818C
	cmp r0, #4
	beq _080981B0
_0809814E:
	adds r6, r5, #0
	adds r6, #0x4a
	b _080981F6
_08098154:
	ldr r4, _0809816C @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0x90
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_0809816C: .4byte 0xFFFFEE00
_08098170:
	ldr r4, _08098188 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0xc0
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_08098188: .4byte 0xFFFFE800
_0809818C:
	ldr r4, _080981AC @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809819C
	movs r4, #0x8c
	lsls r4, r4, #6
_0809819C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981AC: .4byte 0xFFFFDD00
_080981B0:
	ldr r4, _080981D0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080981C0
	movs r4, #0xac
	lsls r4, r4, #6
_080981C0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981D0: .4byte 0xFFFFD500
_080981D4:
	movs r0, #0xdf
	ands r0, r1
_080981D8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	adds r6, r3, #0
_080981F6:
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0809823C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r4, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r4, #0
	bgt _08098236
	cmp r1, #0
	bge _0809822A
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_0809822A:
	rsbs r0, r4, #0
	cmp r0, r1
	bge _08098236
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_08098236:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
_0809823A:
	str r0, [r5, #0x58]
_0809823C:
	ldr r1, _08098270 @ =0x0000DC07
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08098274 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809825E
	movs r4, #1
_0809825E:
	movs r0, #1
	adds r2, r4, #0
	eors r2, r0
	cmp r2, #0
	beq _08098278
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809827E
	.align 2, 0
_08098270: .4byte 0x0000DC07
_08098274: .4byte 0xFFFFF000
_08098278:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809827E:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r7, #0
	strb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r4, r4, #9
	subs r0, r0, r4
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #1
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_080c6e24
	ldr r0, [r5, #0x5c]
	movs r1, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	bge _080982C8
	adds r0, #0xff
_080982C8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	muls r0, r1, r0
	cmp r0, #0
	bge _080982D6
	adds r0, #0xff
_080982D6:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080982FA:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098314
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
_08098314:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _0809832E
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098340
	b _0809833A
_0809832E:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r4, r0, #0
	cmp r4, #0
	ble _08098340
_0809833A:
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08098340:
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	cmp r0, #0
	bge _08098350
	adds r0, #0xff
_08098350:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	cmp r2, #0
	bne _08098364
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098374
_08098364:
	adds r0, r2, #0
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098374
	str r1, [r5, #0x60]
_08098374:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080983CA
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _080983D4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080983D8 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080983DC @ =0x0000270E
	cmp r1, r0
	bhi _080983BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080983BC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080983CA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08098406
	.align 2, 0
_080983D4: .4byte 0xFFFFF000
_080983D8: .4byte gMission
_080983DC: .4byte 0x0000270E
_080983E0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080983F4
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08098406
_080983F4:
	ldr r1, _08098410 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08098406:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098410: .4byte gEnemyFnTable

	thumb_func_start FUN_08098414
FUN_08098414: @ 0x08098414
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _08098422
	b _08098538
_08098422:
	cmp r0, #1
	bgt _0809842C
	cmp r0, #0
	beq _08098434
	b _080985FE
_0809842C:
	cmp r0, #2
	bne _08098432
	b _080985D8
_08098432:
	b _080985FE
_08098434:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809846C
	cmp r0, #2
	bgt _0809844A
	cmp r0, #1
	beq _08098454
	b _080984EC
_0809844A:
	cmp r0, #3
	beq _08098484
	cmp r0, #4
	beq _080984A8
	b _080984EC
_08098454:
	ldr r5, _08098468 @ =0xFFFFEE00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0x90
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098468: .4byte 0xFFFFEE00
_0809846C:
	ldr r5, _08098480 @ =0xFFFFE800
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0xc0
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098480: .4byte 0xFFFFE800
_08098484:
	ldr r5, _080984A4 @ =0xFFFFDD00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098494
	movs r5, #0x8c
	lsls r5, r5, #6
_08098494:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984A4: .4byte 0xFFFFDD00
_080984A8:
	ldr r5, _080984C8 @ =0xFFFFD500
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984B8
	movs r5, #0xac
	lsls r5, r5, #6
_080984B8:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984C8: .4byte 0xFFFFD500
_080984CC:
	movs r0, #0xdf
	ands r0, r1
_080984D0:
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080984EC:
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08097224
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809851C
	movs r2, #1
_0809851C:
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #8
	movs r0, #0xa0
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _080985CC @ =0xFFFFFB80
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08098538:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08098556
	str r0, [r4, #0x60]
_08098556:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098576
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080985FE
_08098576:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c6e70
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080985D0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080985D4 @ =0x0000270E
	cmp r1, r0
	bhi _080985BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080985BC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080985FE
	.align 2, 0
_080985CC: .4byte 0xFFFFFB80
_080985D0: .4byte gMission
_080985D4: .4byte 0x0000270E
_080985D8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080985EC
	subs r0, #1
	strb r0, [r4, #0x12]
	b _080985FE
_080985EC:
	ldr r1, _08098608 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080985FE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098608: .4byte gEnemyFnTable

	thumb_func_start FUN_0809860c
FUN_0809860c: @ 0x0809860C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809861E
	cmp r0, #1
	bne _0809861C
	b _08098772
_0809861C:
	b _0809882C
_0809861E:
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098654
	cmp r0, #2
	bgt _08098634
	cmp r0, #1
	beq _0809863E
	b _080986D4
_08098634:
	cmp r0, #3
	beq _0809866C
	cmp r0, #4
	beq _08098690
	b _080986D4
_0809863E:
	ldr r6, _08098650 @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0x90
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098650: .4byte 0xFFFFEE00
_08098654:
	ldr r6, _08098668 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0xc0
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098668: .4byte 0xFFFFE800
_0809866C:
	ldr r6, _0809868C @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809867C
	movs r6, #0x8c
	lsls r6, r6, #6
_0809867C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_0809868C: .4byte 0xFFFFDD00
_08098690:
	ldr r6, _080986B0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986A0
	movs r6, #0xac
	lsls r6, r6, #6
_080986A0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_080986B0: .4byte 0xFFFFD500
_080986B4:
	movs r0, #0xdf
	ands r0, r1
_080986B8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080986D4:
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_08097224
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08098758 @ =0x0836A3A8
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0809875C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08098760 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08098764
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0809876C
	.align 2, 0
_08098758: .4byte 0x0836A3A8
_0809875C: .4byte pZero2
_08098760: .4byte 0xFFFFE800
_08098764:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0809876C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08098772:
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _08098798
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r6, r0, #0
	cmp r6, #0
	bge _080987B0
	ldr r0, _08098794 @ =0xFFFFF800
	cmp r6, r0
	ble _080987B0
	b _080987A8
	.align 2, 0
_08098794: .4byte 0xFFFFF800
_08098798:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _080987E4 @ =0x000007FE
	cmp r1, r0
	bhi _080987B0
_080987A8:
	movs r4, #1
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_080987B0:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080987C0
	str r1, [r5, #0x60]
_080987C0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _080987EC
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _08098806
	ldr r0, _080987E8 @ =0xFFFFF800
	cmp r6, r0
	ble _08098806
	b _080987FE
	.align 2, 0
_080987E4: .4byte 0x000007FE
_080987E8: .4byte 0xFFFFF800
_080987EC:
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToDown1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _08098834 @ =0x000007FE
	cmp r1, r0
	bhi _08098806
_080987FE:
	movs r4, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
_08098806:
	cmp r4, #0
	bne _08098826
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08098826
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809882C
_08098826:
	adds r0, r5, #0
	bl FUN_08097f3c
_0809882C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098834: .4byte 0x000007FE
