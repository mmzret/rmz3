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
	ldr r1, _080975AC @ =sInitModes
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
_080975AC: .4byte sInitModes
_080975B0: .4byte sCollisions
_080975B4: .4byte FUN_080978c8
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
	bl UpdateEntityAnim
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
	bl IsFrozen
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
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r4, #0xf]
_08097740:
	adds r0, r4, #0
	bl IsFrozen
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
_08097794: .4byte sElementCoord
_08097798: .4byte sCollisions+(10*24)
_0809779C: .4byte 0x00020001
_080977A0: .4byte sUpdates1
_080977A4: .4byte sUpdates2
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
	bl IsFrozen
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
_08097850: .4byte sCollisions
_08097854: .4byte 0xFFFFF900
_08097858: .4byte 0xFFFFFF00
_0809785C: .4byte 0x00020001

