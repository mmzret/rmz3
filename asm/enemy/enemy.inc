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

	thumb_func_start FUN_08098838
FUN_08098838: @ 0x08098838
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08098894 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809888C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08098898 @ =gEnemyFnTable
	movs r1, #0x43
	strb r1, [r3, #9]
	adds r1, #0xc9
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
_0809888C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098894: .4byte gZakoHeaderPtr
_08098898: .4byte gEnemyFnTable

	thumb_func_start Cattatank_Init
Cattatank_Init: @ 0x0809889C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #0
	mov r8, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08098910 @ =0x0836A4D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08098914 @ =FUN_08099eb4
	str r0, [r4, #0x24]
	adds r7, r6, #0
	adds r7, #0xb8
	strb r5, [r7]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08098918
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	subs r4, #0x28
	strb r5, [r4]
	adds r2, r6, #0
	adds r2, #0x4a
	movs r3, #0x10
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	strb r5, [r7]
	adds r3, r2, #0
	b _0809893A
	.align 2, 0
_08098910: .4byte 0x0836A4D8
_08098914: .4byte FUN_08099eb4
_08098918:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r3, r6, #0
	adds r3, #0x4c
	strb r5, [r3]
	adds r1, r6, #0
	adds r1, #0x4a
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	strb r5, [r7]
	adds r4, r3, #0
	adds r3, r1, #0
_0809893A:
	ldrb r5, [r6, #0x11]
	cmp r5, #1
	bne _080989A4
	ldr r0, _08098968 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0809896C
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	strb r2, [r4]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	strb r2, [r7]
	b _08098986
	.align 2, 0
_08098968: .4byte pZero2
_0809896C:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	strb r5, [r4]
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	strb r5, [r7]
_08098986:
	ldr r1, _080989A0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r0, [r6, #0xd]
	b _080989BA
	.align 2, 0
_080989A0: .4byte gEnemyFnTable
_080989A4:
	ldr r1, _08098A00 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
_080989BA:
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	movs r4, #0
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080989E4
	ldr r1, _08098A04 @ =0x0000D503
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080989E4:
	adds r0, r6, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #6
	strb r4, [r0]
	adds r0, r6, #0
	bl Cattatank_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098A00: .4byte gEnemyFnTable
_08098A04: .4byte 0x0000D503

	thumb_func_start Cattatank_Update
Cattatank_Update: @ 0x08098A08
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08098A4C
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _08098A2A
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08098AD0
_08098A2A:
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08098A48 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Cattatank_Die
	b _08098B10
	.align 2, 0
_08098A48: .4byte gEnemyFnTable
_08098A4C:
	ldr r6, _08098ABC @ =gStageRun+232
	adds r5, r4, #0
	adds r5, #0x54
	adds r0, r6, #0
	adds r1, r5, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _08098AD0
	ldr r1, [r6, #0x3c]
	ldr r0, _08098AC0 @ =0x00004FFF
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	cmp r1, r0
	bge _08098AD0
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08098AD0
	strb r0, [r4, #0xf]
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08098AC4 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098AC8 @ =0x0000270E
	cmp r1, r0
	bhi _08098A98
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098A98:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08098ACC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	b _08098B10
	.align 2, 0
_08098ABC: .4byte gStageRun+232
_08098AC0: .4byte 0x00004FFF
_08098AC4: .4byte gMission
_08098AC8: .4byte 0x0000270E
_08098ACC: .4byte gEnemyFnTable
_08098AD0:
	ldr r1, _08098B18 @ =0x0836A470
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl cattatank_08099e20
	ldrb r1, [r4, #0xd]
	subs r0, r1, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08098B00
	cmp r1, #9
	beq _08098B00
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08098B10
_08098B00:
	ldr r0, _08098B1C @ =0x0836A498
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08098B10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098B18: .4byte 0x0836A470
_08098B1C: .4byte 0x0836A498

	thumb_func_start Cattatank_Die
Cattatank_Die: @ 0x08098B20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08098B78 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08098B80
	ldrb r0, [r6, #0x11]
	cmp r0, #1
	beq _08098B80
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08098B7C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0809906E
	.align 2, 0
_08098B78: .4byte gCurStory
_08098B7C: .4byte gEnemyFnTable
_08098B80:
	ldr r5, _08098C44 @ =gStageRun+232
	adds r4, r6, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	mov sb, r4
	cmp r0, r1
	bls _08098C78
	ldr r1, [r5, #0x3c]
	ldr r0, _08098C48 @ =0x00004FFF
	adds r1, r1, r0
	ldr r2, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #6
	mov sl, r3
	adds r0, r2, r3
	cmp r1, r0
	bge _08098C78
	ldr r0, [r6, #0x54]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	beq _08098BD0
	b _08099040
_08098BD0:
	ldr r2, _08098C4C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098C50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08098C54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08098C58 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08098C5C @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08098C60 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08098C68
	ldr r0, [r6, #0x54]
	ldr r1, _08098C64 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #8]
	b _08098FF0
	.align 2, 0
_08098C44: .4byte gStageRun+232
_08098C48: .4byte 0x00004FFF
_08098C4C: .4byte RNG_0202f388
_08098C50: .4byte 0x000343FD
_08098C54: .4byte 0x00269EC3
_08098C58: .4byte 0x0000D50F
_08098C5C: .4byte 0x0000D50E
_08098C60: .4byte 0x0000D510
_08098C64: .4byte 0xFFFFE000
_08098C68:
	ldr r0, [r6, #0x54]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r0, r8
	ldrb r1, [r0]
	b _08099036
_08098C78:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xb
	bls _08098C80
	b _08099070
_08098C80:
	lsls r0, r0, #2
	ldr r1, _08098C8C @ =_08098C90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098C8C: .4byte _08098C90
_08098C90: @ jump table
	.4byte _08098CC0 @ case 0
	.4byte _08098E24 @ case 1
	.4byte _08098D08 @ case 2
	.4byte _08098D1C @ case 3
	.4byte _08098E44 @ case 4
	.4byte _08099070 @ case 5
	.4byte _08099070 @ case 6
	.4byte _08099070 @ case 7
	.4byte _08099070 @ case 8
	.4byte _08099070 @ case 9
	.4byte _08098E24 @ case 10
	.4byte _08098F20 @ case 11
_08098CC0:
	ldr r1, _08098CE8 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08098CEC
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08098CEC
	movs r0, #1
	b _08098CEE
	.align 2, 0
_08098CE8: .4byte 0x0000D505
_08098CEC:
	movs r0, #0xa
_08098CEE:
	strb r0, [r6, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08098E24
_08098D08:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08098D1A
	b _08099070
_08098D1A:
	b _08098E24
_08098D1C:
	ldr r1, _08098D68 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r6, #0x13]
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r6, #0xf]
	adds r7, r6, #0
	adds r7, #0xb8
	cmp r0, #0
	bne _08098D4A
	ldrb r1, [r7]
	mov r0, sp
	bl FUN_080c7518
_08098D4A:
	ldrb r0, [r7]
	cmp r0, #0
	bne _08098D70
	ldr r0, [sp]
	ldr r1, _08098D6C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r0, #0x80
	b _08098D84
	.align 2, 0
_08098D68: .4byte 0x0000D505
_08098D6C: .4byte 0xFFFFF800
_08098D70:
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
_08098D84:
	str r0, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08098DB0
	cmp r0, #0xfe
	bne _08098DA4
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08098DD2
_08098DA4:
	ldr r0, _08098DC0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _08098DC4
_08098DB0:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08098DD2
	.align 2, 0
_08098DC0: .4byte pZero2
_08098DC4:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08098DD2:
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08098E1C
	ldr r2, _08098E2C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098E30 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08098E34 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x10
	str r0, [r5, #4]
	ldrb r1, [r7]
	ldr r2, _08098E38 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
	ldrb r1, [r7]
	ldr r2, _08098E3C @ =0x0000D510
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
_08098E1C:
	ldr r0, _08098E40 @ =0xFFFFFE00
	str r0, [r6, #0x60]
	movs r0, #0x1e
	strb r0, [r6, #0x12]
_08098E24:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08099070
	.align 2, 0
_08098E2C: .4byte RNG_0202f388
_08098E30: .4byte 0x000343FD
_08098E34: .4byte 0x00269EC3
_08098E38: .4byte 0x0000D50F
_08098E3C: .4byte 0x0000D510
_08098E40: .4byte 0xFFFFFE00
_08098E44:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098E5A
	str r1, [r6, #0x60]
_08098E5A:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r2, [r6, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x60]
	cmp r0, #0
	ble _08098ED8
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08098F14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098F18 @ =0x0000270E
	cmp r1, r0
	bhi _08098EB6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098EB6:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08098F1C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
_08098ED8:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08098EEA
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098EEA
	b _08099070
_08098EEA:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098EFA
	b _08099070
_08098EFA:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08099040
	.align 2, 0
_08098F14: .4byte gMission
_08098F18: .4byte 0x0000270E
_08098F1C: .4byte gEnemyFnTable
_08098F20:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098F30
	str r1, [r6, #0x60]
_08098F30:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, [r6, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098F5A
	b _08099070
_08098F5A:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08099040
	ldr r2, _08099004 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08099008 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809900C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x18
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08099010 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08099014 @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099018 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099024
	ldr r0, [r6, #0x54]
	ldr r1, _0809901C @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #0x18]
_08098FF0:
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099020 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	b _08099040
	.align 2, 0
_08099004: .4byte RNG_0202f388
_08099008: .4byte 0x000343FD
_0809900C: .4byte 0x00269EC3
_08099010: .4byte 0x0000D50F
_08099014: .4byte 0x0000D50E
_08099018: .4byte 0x0000D510
_0809901C: .4byte 0xFFFFE000
_08099020: .4byte 0x0000D50D
_08099024:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
_08099036:
	ldr r2, _08099080 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
_08099040:
	ldr r2, _08099084 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08099088 @ =0x0000270E
	cmp r1, r0
	bhi _0809904E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0809904E:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809908C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0809906E:
	str r0, [r6, #0x14]
_08099070:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099080: .4byte 0x0000D50D
_08099084: .4byte gMission
_08099088: .4byte 0x0000270E
_0809908C: .4byte gEnemyFnTable

	thumb_func_start nop_08099090
nop_08099090: @ 0x08099090
	movs r0, #1
	bx lr

	thumb_func_start cattatank_08099094
cattatank_08099094: @ 0x08099094
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080990A4
	cmp r0, #1
	beq _080990B6
	b _080990CE
_080990A4:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #0x32
	strb r0, [r2, #0x12]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080990B6:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _080990C6
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080990CE
_080990C6:
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080990CE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_080990d4
nop_080990d4: @ 0x080990D4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080990d8
FUN_080990d8: @ 0x080990D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080990E4
	b _08099256
_080990E4:
	lsls r0, r0, #2
	ldr r1, _080990F0 @ =_080990F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080990F0: .4byte _080990F4
_080990F4: @ jump table
	.4byte _0809910C @ case 0
	.4byte _080991A0 @ case 1
	.4byte _080991F2 @ case 2
	.4byte _0809920A @ case 3
	.4byte _08099228 @ case 4
	.4byte _0809923C @ case 5
_0809910C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809915C @ =0x0000D503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099160 @ =0x0836A4D8
	bl SetDDP
	ldr r0, _08099164 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099168
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
	b _08099194
	.align 2, 0
_0809915C: .4byte 0x0000D503
_08099160: .4byte 0x0836A4D8
_08099164: .4byte pZero2
_08099168:
	movs r3, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r3, [r0]
_08099194:
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080991A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080991B6
	str r1, [r4, #0x60]
_080991B6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _080991D4
	ldr r1, _080991D0 @ =0xFFFFF800
	b _080991D8
	.align 2, 0
_080991D0: .4byte 0xFFFFF800
_080991D4:
	movs r1, #0x80
	lsls r1, r1, #4
_080991D8:
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099256
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _0809921A
_080991F2:
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08099224 @ =0x0000D504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809920A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099256
_0809921A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099256
	.align 2, 0
_08099224: .4byte 0x0000D504
_08099228:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809923C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099256
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099256:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0809925c
nop_0809925c: @ 0x0809925C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099260
FUN_08099260: @ 0x08099260
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0809926C
	b _080994E2
_0809926C:
	lsls r0, r0, #2
	ldr r1, _08099278 @ =_0809927C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099278: .4byte _0809927C
_0809927C: @ jump table
	.4byte _080992B4 @ case 0
	.4byte _080992EE @ case 1
	.4byte _080994E2 @ case 2
	.4byte _080994E2 @ case 3
	.4byte _080994E2 @ case 4
	.4byte _080994E2 @ case 5
	.4byte _080994E2 @ case 6
	.4byte _080994E2 @ case 7
	.4byte _080994E2 @ case 8
	.4byte _080994E2 @ case 9
	.4byte _0809944C @ case 10
	.4byte _0809945A @ case 11
	.4byte _08099474 @ case 12
	.4byte _080994CE @ case 13
_080992B4:
	ldr r1, _080992DC @ =0x0000D501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080992E0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080992E4
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080992E6
	.align 2, 0
_080992DC: .4byte 0x0000D501
_080992E0: .4byte 0x0836A4D8
_080992E4:
	movs r0, #0xc0
_080992E6:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080992EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0809930E
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _08099318
_0809930E:
	ldr r2, _08099354 @ =0xFFFFF600
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_08099318:
	adds r2, r0, #0
	cmp r2, #0
	beq _08099324
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_08099324:
	ldrb r0, [r4, #0x11]
	adds r6, r0, #0
	cmp r6, #1
	bne _08099360
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	ldr r2, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	ldr r3, [r4, #0x58]
	cmp r0, #1
	bls _0809938E
	ldr r0, _08099358 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _0809938E
	cmp r5, #0
	ble _0809935C
	ldr r0, [r1, #0x54]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099354: .4byte 0xFFFFF600
_08099358: .4byte pZero2
_0809935C:
	ldr r0, [r1, #0x54]
	b _08099386
_08099360:
	ldr r5, [r4, #0x5c]
	cmp r5, #0
	ble _0809937C
	ldr r0, _08099378 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099378: .4byte pZero2
_0809937C:
	ldr r0, _080993BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
_08099386:
	cmp r0, r2
	ble _0809938E
_0809938A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809938E:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	beq _080993EC
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080993C0
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _080993EC
	ldr r0, _080993BC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _080993EC
	ldr r0, [r1, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080993CC
	b _080993DC
	.align 2, 0
_080993BC: .4byte pZero2
_080993C0:
	ldr r0, _080993D4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	ble _080993DC
_080993CC:
	ldr r0, _080993D8 @ =0x00003BFF
	cmp r1, r0
	ble _080993E4
	b _080993EC
	.align 2, 0
_080993D4: .4byte pZero2
_080993D8: .4byte 0x00003BFF
_080993DC:
	subs r1, r2, r0
	ldr r0, _0809940C @ =0x00003BFF
	cmp r1, r0
	bgt _080993EC
_080993E4:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080993EC:
	cmp r5, #0
	ble _08099414
	ldr r1, _08099410 @ =0xFFFFF600
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	b _0809942C
	.align 2, 0
_0809940C: .4byte 0x00003BFF
_08099410: .4byte 0xFFFFF600
_08099414:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	ldr r2, _08099448 @ =0xFFFFF600
_0809942C:
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	cmp r2, r0
	beq _080994E2
	movs r1, #0
	str r1, [r4, #0x60]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080994E2
	.align 2, 0
_08099448: .4byte 0xFFFFF600
_0809944C:
	ldr r1, _08099470 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809945A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080994E0
	.align 2, 0
_08099470: .4byte 0x0000D511
_08099474:
	ldr r1, _080994A8 @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _080994AC
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _080994C6
	.align 2, 0
_080994A8: .4byte 0x0000D512
_080994AC:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_080994C6:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080994CE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	movs r0, #0
_080994E0:
	strb r0, [r4, #0xe]
_080994E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start nop_080994e8
nop_080994e8: @ 0x080994E8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080994ec
FUN_080994ec: @ 0x080994EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080994F8
	b _08099736
_080994F8:
	lsls r0, r0, #2
	ldr r1, _08099504 @ =_08099508
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099504: .4byte _08099508
_08099508: @ jump table
	.4byte _08099540 @ case 0
	.4byte _0809954A @ case 1
	.4byte _08099584 @ case 2
	.4byte _08099670 @ case 3
	.4byte _08099684 @ case 4
	.4byte _08099736 @ case 5
	.4byte _08099736 @ case 6
	.4byte _08099736 @ case 7
	.4byte _08099736 @ case 8
	.4byte _08099736 @ case 9
	.4byte _080996A0 @ case 10
	.4byte _080996AE @ case 11
	.4byte _080996C8 @ case 12
	.4byte _08099722 @ case 13
_08099540:
	movs r0, #0
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809954A:
	ldr r1, _0809956C @ =0x0000D502
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099570 @ =0x0836A4D8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099574
	movs r0, #0x80
	lsls r0, r0, #1
	b _08099576
	.align 2, 0
_0809956C: .4byte 0x0000D502
_08099570: .4byte 0x0836A4D8
_08099574:
	ldr r0, _080995B0 @ =0xFFFFFF00
_08099576:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099584:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x64]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r4, #0x64]
	cmp r1, #0
	ble _080995B4
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080995BE
	.align 2, 0
_080995B0: .4byte 0xFFFFFF00
_080995B4:
	ldr r3, _080995DC @ =0xFFFFF600
	adds r0, r2, r3
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080995BE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080995CA
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080995CA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080995E0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080995E6
	.align 2, 0
_080995DC: .4byte 0xFFFFF600
_080995E0:
	ldr r0, [r4, #0x54]
	ldr r3, _08099628 @ =0xFFFFF600
	adds r0, r0, r3
_080995E6:
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _080995FC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
_080995FC:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08099634
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _0809965C
	ldr r0, _0809962C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x58]
	ldr r0, [r2, #0x58]
	cmp r1, r0
	blt _0809965C
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099630
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099628: .4byte 0xFFFFF600
_0809962C: .4byte pZero2
_08099630:
	ldr r1, [r2, #0x54]
	b _08099652
_08099634:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809964C
	ldr r0, _08099648 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099648: .4byte pZero2
_0809964C:
	ldr r0, _0809966C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
_08099652:
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0809965C
_08099658:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809965C:
	ldr r1, [r4, #0x64]
	movs r0, #0xc0
	lsls r0, r0, #5
	cmp r1, r0
	ble _08099736
	movs r0, #3
	b _08099734
	.align 2, 0
_0809966C: .4byte pZero2
_08099670:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099684:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099736
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08099736
_080996A0:
	ldr r1, _080996C4 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080996AE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08099734
	.align 2, 0
_080996C4: .4byte 0x0000D511
_080996C8:
	ldr r1, _080996FC @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _08099700
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _0809971A
	.align 2, 0
_080996FC: .4byte 0x0000D512
_08099700:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_0809971A:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099722:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	movs r0, #1
_08099734:
	strb r0, [r4, #0xe]
_08099736:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_0809973c
nop_0809973c: @ 0x0809973C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099740
FUN_08099740: @ 0x08099740
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0809974C
	b _08099948
_0809974C:
	lsls r0, r0, #2
	ldr r1, _08099758 @ =_0809975C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099758: .4byte _0809975C
_0809975C: @ jump table
	.4byte _08099778 @ case 0
	.4byte _08099794 @ case 1
	.4byte _080997A4 @ case 2
	.4byte _080997C4 @ case 3
	.4byte _08099858 @ case 4
	.4byte _08099878 @ case 5
	.4byte _0809990C @ case 6
_08099778:
	ldr r1, _0809979C @ =0x0000D507
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080997A0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099794:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080998E6
	.align 2, 0
_0809979C: .4byte 0x0000D507
_080997A0: .4byte 0x0836A4D8
_080997A4:
	ldr r1, _08099844 @ =0x0000D508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099848 @ =0x0836A520
	bl SetDDP
	movs r1, #0
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080997C4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080997E4
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080997E4
	movs r0, #0x52
	bl PlaySound
_080997E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #4
	bne _0809980C
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0809980C
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809984C @ =0x0836A568
	bl SetDDP
_0809980C:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bne _08099828
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _08099828
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099850 @ =0x0836A5B0
	bl SetDDP
_08099828:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099854 @ =0x0836A5F8
	b _080998D8
	.align 2, 0
_08099844: .4byte 0x0000D508
_08099848: .4byte 0x0836A520
_0809984C: .4byte 0x0836A568
_08099850: .4byte 0x0836A5B0
_08099854: .4byte 0x0836A5F8
_08099858:
	ldr r1, _080998FC @ =0x0000D509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099900 @ =0x0836A5B0
	bl SetDDP
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099878:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08099898
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08099898
	movs r0, #0x52
	bl PlaySound
_08099898:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #1
	bne _080998C0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080998C0
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099904 @ =0x0836A568
	bl SetDDP
_080998C0:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099908 @ =0x0836A520
_080998D8:
	bl SetDDP
_080998DC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099948
_080998E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099948
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099948
	.align 2, 0
_080998FC: .4byte 0x0000D509
_08099900: .4byte 0x0836A5B0
_08099904: .4byte 0x0836A568
_08099908: .4byte 0x0836A520
_0809990C:
	ldr r0, _08099924 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0809992C
	ldr r0, _08099928 @ =0x000039FF
	cmp r2, r0
	ble _08099934
	b _08099940
	.align 2, 0
_08099924: .4byte pZero2
_08099928: .4byte 0x000039FF
_0809992C:
	subs r1, r1, r0
	ldr r0, _0809993C @ =0x000039FF
	cmp r1, r0
	bgt _08099940
_08099934:
	movs r1, #0
	movs r0, #3
	b _08099944
	.align 2, 0
_0809993C: .4byte 0x000039FF
_08099940:
	movs r1, #0
	movs r0, #2
_08099944:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099948:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_08099950
nop_08099950: @ 0x08099950
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099954
FUN_08099954: @ 0x08099954
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08099964
	cmp r0, #1
	beq _080999A4
	b _08099A88
_08099964:
	ldr r1, _0809998C @ =0x0000D50C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099990 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r0, _08099994 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099998
	movs r0, #0x60
	b _0809999C
	.align 2, 0
_0809998C: .4byte 0x0000D50C
_08099990: .4byte 0x0836A4D8
_08099994: .4byte pZero2
_08099998:
	movs r0, #0x60
	rsbs r0, r0, #0
_0809999C:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080999A4:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080999C6
	str r1, [r4, #0x60]
_080999C6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080999E0
	ldr r0, [r4, #0x54]
	ldr r2, _080999DC @ =0xFFFFF600
	b _080999E6
	.align 2, 0
_080999DC: .4byte 0xFFFFF600
_080999E0:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_080999E6:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099A06
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099A06:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	bne _08099A40
	ldr r0, _08099A3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099A6E
	movs r2, #1
	movs r0, #0x10
	orrs r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r5
	b _08099A66
	.align 2, 0
_08099A3C: .4byte pZero2
_08099A40:
	ldr r0, _08099A90 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099A6E
	movs r2, #0
	movs r0, #0xef
	ands r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_08099A66:
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
_08099A6E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099A88
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099A88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A90: .4byte pZero2

	thumb_func_start nop_08099a94
nop_08099a94: @ 0x08099A94
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099a98
FUN_08099a98: @ 0x08099A98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08099B08
	cmp r0, #1
	bgt _08099AAC
	cmp r0, #0
	beq _08099AB8
	b _08099CDA
_08099AAC:
	cmp r0, #2
	beq _08099BA6
	cmp r0, #3
	bne _08099AB6
	b _08099BB4
_08099AB6:
	b _08099CDA
_08099AB8:
	ldr r1, _08099AE0 @ =0x0000D50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099AE4 @ =0x0836A640
	bl SetDDP
	ldr r0, _08099AE8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099AF0
	ldr r0, _08099AEC @ =0xFFFFFA00
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _08099AF8
	.align 2, 0
_08099AE0: .4byte 0x0000D50A
_08099AE4: .4byte 0x0836A640
_08099AE8: .4byte pZero2
_08099AEC: .4byte 0xFFFFFA00
_08099AF0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
_08099AF8:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B08:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099B30
	str r1, [r4, #0x60]
_08099B30:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099B52
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B52:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099B64
	ldr r0, [r4, #0x54]
	ldr r1, _08099B60 @ =0xFFFFF600
	adds r0, r0, r1
	b _08099B6C
	.align 2, 0
_08099B60: .4byte 0xFFFFF600
_08099B64:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
_08099B6C:
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099B8A
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08099B8A:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	bne _08099B9A
	b _08099CDA
_08099B9A:
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
	b _08099CDA
_08099BA6:
	ldr r1, _08099BF0 @ =0x0000D50B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099BB4:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099BDC
	str r1, [r4, #0x60]
_08099BDC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099BF8
	ldr r0, [r4, #0x54]
	ldr r2, _08099BF4 @ =0xFFFFF600
	b _08099BFE
	.align 2, 0
_08099BF0: .4byte 0x0000D50B
_08099BF4: .4byte 0xFFFFF600
_08099BF8:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_08099BFE:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099C1E
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099C1E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099C36
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08099C36:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099CDA
	ldr r1, [r5]
	cmp r1, #0
	beq _08099CAC
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _08099C6C
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C66
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099C66:
	movs r1, #0
	movs r0, #7
	b _08099CD6
_08099C6C:
	cmp r2, #2
	bne _08099C96
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C90
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08099C8C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08099CC6
	.align 2, 0
_08099C8C: .4byte gEnemyFnTable
_08099C90:
	movs r1, #0
	movs r0, #9
	b _08099CD6
_08099C96:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CA8
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099CA8:
	movs r1, #0
	b _08099CD4
_08099CAC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CD4
	strb r1, [r4, #0xf]
_08099CBA:
	ldr r1, _08099CD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08099CC6:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08099CDA
	.align 2, 0
_08099CD0: .4byte gEnemyFnTable
_08099CD4:
	movs r0, #1
_08099CD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099CDA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_08099ce0
nop_08099ce0: @ 0x08099CE0
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099ce4
FUN_08099ce4: @ 0x08099CE4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099CF4
	cmp r5, #1
	beq _08099D08
	b _08099D4E
_08099CF4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099D74 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099D08:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099D18
	str r1, [r4, #0x60]
_08099D18:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099D78 @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099D44
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099D4E
_08099D44:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099D4E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099D6C
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099D6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099D74: .4byte 0x0836A550
_08099D78: .4byte 0xFFFFF600

	thumb_func_start nop_08099d7c
nop_08099d7c: @ 0x08099D7C
	movs r0, #1
	bx lr

	thumb_func_start nop_08099d80
nop_08099d80: @ 0x08099D80
	bx lr
	.align 2, 0

	thumb_func_start nop_08099d84
nop_08099d84: @ 0x08099D84
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099d88
FUN_08099d88: @ 0x08099D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099D98
	cmp r5, #1
	beq _08099DAC
	b _08099DF2
_08099D98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099E18 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099DAC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099DBC
	str r1, [r4, #0x60]
_08099DBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099E1C @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099DE8
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099DF2
_08099DE8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099DF2:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099E10
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099E10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099E18: .4byte 0x0836A550
_08099E1C: .4byte 0xFFFFF600

	thumb_func_start cattatank_08099e20
cattatank_08099e20: @ 0x08099E20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _08099EAA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08099EAA
	ldr r2, _08099E6C @ =0x0836A670
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099E84
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E70
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #7
	b _08099E7E
	.align 2, 0
_08099E6C: .4byte 0x0836A670
_08099E70:
	cmp r1, #0x30
	bne _08099EAA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #9
_08099E7E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08099EAA
_08099E84:
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E9E
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _08099EAA
_08099E9E:
	cmp r1, #0x30
	bne _08099EAA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_08099EAA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08099eb4
FUN_08099eb4: @ 0x08099EB4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08099ECC
	cmp r0, #0xe
	beq _08099ECC
	cmp r0, #0xf
	bne _08099EF6
_08099ECC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF6
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08099EEE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08099EF4
_08099EEE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08099EF4:
	strb r0, [r1]
_08099EF6:
	ldr r0, [r3, #4]
	ldr r1, _08099F28 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08099F2C
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099F4E
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099F20
	adds r0, r4, #0
	bl isFrozen
_08099F20:
	movs r1, #0
	movs r0, #6
	b _08099F4A
	.align 2, 0
_08099F28: .4byte 0x000200FF
_08099F2C:
	ldr r4, [r2, #0x2c]
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _08099F4E
	ldrb r0, [r3, #6]
	cmp r0, #0x40
	beq _08099F4E
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08099F4E
	movs r0, #5
_08099F4A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08099f54
FUN_08099f54: @ 0x08099F54
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08099FB0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08099FA8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08099FB4 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #6
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x68]
	str r7, [r3, #0x5c]
_08099FA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099FB0: .4byte gZakoHeaderPtr
_08099FB4: .4byte gEnemyFnTable

	thumb_func_start FUN_08099fb8
FUN_08099fb8: @ 0x08099FB8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809A024 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809A01E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A028 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	strb r5, [r3, #0x10]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #0xc
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_0809A01E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A024: .4byte gZakoHeaderPtr
_0809A028: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a02c
FUN_0809a02c: @ 0x0809A02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809A0A8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809A0A0
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A0AC @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r4, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #4
	strb r0, [r4, #0x10]
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r4, #0x54]
	movs r1, #0x82
	lsls r1, r1, #0xb
	str r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	ldr r0, _0809A0B0 @ =0xFFFF6800
	adds r1, r1, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	lsls r0, r0, #0xc
	adds r1, r1, r0
	str r1, [r4, #0x54]
	strb r5, [r4, #0x12]
	str r6, [r4, #0x28]
_0809A0A0:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809A0A8: .4byte gZakoHeaderPtr
_0809A0AC: .4byte gEnemyFnTable
_0809A0B0: .4byte 0xFFFF6800

	thumb_func_start nop_0809a0b4
nop_0809a0b4: @ 0x0809A0B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a0b8
FUN_0809a0b8: @ 0x0809A0B8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0809A0CE
	movs r0, #0
	b _0809A0FA
_0809A0CE:
	ldr r0, [r2, #0x28]
	adds r0, #0x31
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, _0809A100 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, _0809A104 @ =0x0836A764
	ldrb r0, [r2, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl LeviathanMinigameEnemy_Die
	movs r0, #1
_0809A0FA:
	pop {r1}
	bx r1
	.align 2, 0
_0809A100: .4byte gEnemyFnTable
_0809A104: .4byte 0x0836A764

	thumb_func_start LeviathanMinigameEnemy_Init
LeviathanMinigameEnemy_Init: @ 0x0809A108
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809A184 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0809A188 @ =0x0836A76A
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #6
	beq _0809A152
	ldr r0, _0809A18C @ =0x0836A772
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_0809A152:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809A190 @ =0x0836A6D4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0809A194 @ =nop_0809a0b4
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl LeviathanMinigameEnemy_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A184: .4byte gEnemyFnTable
_0809A188: .4byte 0x0836A76A
_0809A18C: .4byte 0x0836A772
_0809A190: .4byte 0x0836A6D4
_0809A194: .4byte nop_0809a0b4

	thumb_func_start LeviathanMinigameEnemy_Update
LeviathanMinigameEnemy_Update: @ 0x0809A198
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809a0b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A1C6
	ldr r1, _0809A1CC @ =0x0836A68C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809A1D0 @ =0x0836A6A8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809A1C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A1CC: .4byte 0x0836A68C
_0809A1D0: .4byte 0x0836A6A8

	thumb_func_start LeviathanMinigameEnemy_Die
LeviathanMinigameEnemy_Die: @ 0x0809A1D4
	push {lr}
	ldr r2, _0809A1E8 @ =0x0836A6C4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809A1E8: .4byte 0x0836A6C4

	thumb_func_start nop_0809a1ec
nop_0809a1ec: @ 0x0809A1EC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a1f0
FUN_0809a1f0: @ 0x0809A1F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A210
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A20C @ =0x0836A6D4
	bl SetDDP
	b _0809A30A
	.align 2, 0
_0809A20C: .4byte 0x0836A6D4
_0809A210:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A228 @ =0x0836A6EC
	bl SetDDP
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809A22C
	cmp r0, #1
	beq _0809A292
	b _0809A30A
	.align 2, 0
_0809A228: .4byte 0x0836A6EC
_0809A22C:
	adds r1, r5, #0
	adds r1, #0x22
	movs r4, #1
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x12]
	eors r4, r0
	cmp r4, #0
	beq _0809A250
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A256
_0809A250:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A256:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r4
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
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r5, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809A292:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0809A310 @ =gSineTable
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r0, #4
	movs r4, #0
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _0809A314 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A30A
	str r4, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0809A318 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0809A30A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A310: .4byte gSineTable
_0809A314: .4byte 0xFFFF3000
_0809A318: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a31c
FUN_0809a31c: @ 0x0809A31C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A33C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A338 @ =0x0836A6D4
	bl SetDDP
	b _0809A49A
	.align 2, 0
_0809A338: .4byte 0x0836A6D4
_0809A33C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A354 @ =0x0836A704
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A358
	cmp r0, #1
	beq _0809A3BE
	b _0809A49A
	.align 2, 0
_0809A354: .4byte 0x0836A704
_0809A358:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0809A378 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0809A37C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A382
	.align 2, 0
_0809A378: .4byte 0x00003501
_0809A37C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A382:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A3BE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A3F2
	ldr r2, _0809A4A4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A4A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A4AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r4, #0x13]
	ldr r1, _0809A4B0 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
_0809A3F2:
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	bge _0809A400
	adds r0, #0xff
_0809A400:
	asrs r1, r0, #8
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809A422
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809A422:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0809A450
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
_0809A450:
	ldr r0, [r4, #0x54]
	ldr r1, _0809A4B4 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A49A
	str r5, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A4B8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A49A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A4A0: .4byte 0xFFFFFEC0
_0809A4A4: .4byte RNG_0202f388
_0809A4A8: .4byte 0x000343FD
_0809A4AC: .4byte 0x00269EC3
_0809A4B0: .4byte 0x00003501
_0809A4B4: .4byte 0xFFFF3000
_0809A4B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a4bc
FUN_0809a4bc: @ 0x0809A4BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A4DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4D8 @ =0x0836A6D4
	bl SetDDP
	b _0809A5CC
	.align 2, 0
_0809A4D8: .4byte 0x0836A6D4
_0809A4DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4F4 @ =0x0836A71C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A4F8
	cmp r0, #1
	beq _0809A55C
	b _0809A5CC
	.align 2, 0
_0809A4F4: .4byte 0x0836A71C
_0809A4F8:
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A516
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A51C
_0809A516:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A51C:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A55C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A5D4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A5D8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A5CC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A5DC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A5CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5D4: .4byte gSineTable
_0809A5D8: .4byte 0xFFFF3000
_0809A5DC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a5e0
FUN_0809a5e0: @ 0x0809A5E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A600
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A5FC @ =0x0836A6D4
	bl SetDDP
	b _0809A6EC
	.align 2, 0
_0809A5FC: .4byte 0x0836A6D4
_0809A600:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A618 @ =0x0836A734
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A61C
	cmp r0, #1
	beq _0809A67A
	b _0809A6EC
	.align 2, 0
_0809A618: .4byte 0x0836A734
_0809A61C:
	movs r1, #0xef
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A63A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A640
_0809A63A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A640:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xe0
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A67A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A6F4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0809A694
	adds r1, #3
_0809A694:
	asrs r1, r1, #2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A6F8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A6EC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A6FC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A6EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A6F4: .4byte gSineTable
_0809A6F8: .4byte 0xFFFF3000
_0809A6FC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a700
FUN_0809a700: @ 0x0809A700
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A724
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A720 @ =0x0836A6D4
	bl SetDDP
	b _0809A8F4
	.align 2, 0
_0809A720: .4byte 0x0836A6D4
_0809A724:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A740 @ =0x0836A74C
	bl SetDDP
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0809A782
	cmp r0, #1
	bgt _0809A744
	cmp r0, #0
	beq _0809A750
	b _0809A8F4
	.align 2, 0
_0809A740: .4byte 0x0836A74C
_0809A744:
	cmp r0, #2
	beq _0809A7A8
	cmp r0, #3
	bne _0809A74E
	b _0809A894
_0809A74E:
	b _0809A8F4
_0809A750:
	movs r1, #0xf1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A79C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A7A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A7A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A782:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A794
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A794:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0809A8F4
	.align 2, 0
_0809A79C: .4byte RNG_0202f388
_0809A7A0: .4byte 0x000343FD
_0809A7A4: .4byte 0x00269EC3
_0809A7A8:
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A800 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r7, _0809A804 @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _0809A808 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r1, r8
	str r3, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0809A810
	adds r0, r3, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #0xa
	ldr r3, _0809A80C @ =0xFFFFFE00
	adds r0, r0, r3
	b _0809A846
	.align 2, 0
_0809A800: .4byte RNG_0202f388
_0809A804: .4byte 0x000343FD
_0809A808: .4byte 0x00269EC3
_0809A80C: .4byte 0xFFFFFE00
_0809A810:
	movs r2, #0x80
	rsbs r2, r2, #0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r1, _0809A860 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r2, r2, r0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r3, _0809A860 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r1, r0
_0809A846:
	str r0, [r6, #0x5c]
	movs r1, #0
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _0809A852
	movs r1, #1
_0809A852:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A864
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A86A
	.align 2, 0
_0809A860: .4byte 0x00269EC3
_0809A864:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A86A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
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
	ldr r1, _0809A900 @ =0x0000F101
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A894:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	movs r2, #0
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A8AC
	strb r2, [r6, #0xe]
_0809A8AC:
	ldr r0, [r6, #0x54]
	ldr r1, _0809A904 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A8EE
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809A908 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_0809A8EE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0809A8F4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A900: .4byte 0x0000F101
_0809A904: .4byte 0xFFFF3000
_0809A908: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a90c
FUN_0809a90c: @ 0x0809A90C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AA02
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A926
	cmp r0, #1
	beq _0809A9B2
	b _0809AA02
_0809A926:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r3, #0x80
	rsbs r3, r3, #0
	ldr r2, _0809A974 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A978 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A97C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r3, r3, r0
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #1
	movs r0, #1
	subs r0, r0, r1
	muls r0, r3, r0
	str r0, [r4, #0x5c]
	movs r1, #0
	cmp r0, #0
	ble _0809A964
	movs r1, #1
_0809A964:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A980
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A986
	.align 2, 0
_0809A974: .4byte RNG_0202f388
_0809A978: .4byte 0x000343FD
_0809A97C: .4byte 0x00269EC3
_0809A980:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A986:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	movs r1, #0xf2
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A9B2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809AA08 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A9FC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809AA0C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A9FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809AA02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA08: .4byte 0xFFFF3000
_0809AA0C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aa10
FUN_0809aa10: @ 0x0809AA10
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AA2E
	adds r0, r5, #7
_0809AA2E:
	asrs r5, r0, #3
	cmp r5, #0
	bge _0809AA38
	movs r5, #0
	b _0809AA40
_0809AA38:
	adds r0, r5, #4
	cmp r0, #0x1e
	ble _0809AA40
	movs r5, #0x1a
_0809AA40:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AA4A
	adds r0, r4, #7
_0809AA4A:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AA54
	movs r4, #1
	b _0809AA5A
_0809AA54:
	cmp r4, #0x11
	ble _0809AA5A
	movs r4, #0x11
_0809AA5A:
	ldr r0, _0809AA88 @ =0x080FF064
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, _0809AA8C @ =0x080FF06C
	adds r1, r5, #2
	adds r4, #1
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl minigame_str_080e9d04
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA88: .4byte 0x080FF064
_0809AA8C: .4byte 0x080FF06C

	thumb_func_start FUN_0809aa90
FUN_0809aa90: @ 0x0809AA90
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AAAE
	adds r0, r5, #7
_0809AAAE:
	asrs r5, r0, #3
	ldrb r1, [r6, #0x13]
	subs r0, r5, r1
	adds r0, #1
	cmp r0, #0
	bge _0809AABE
	subs r5, r1, #1
	b _0809AAC6
_0809AABE:
	adds r0, r5, #7
	cmp r0, #0x1e
	ble _0809AAC6
	movs r5, #0x17
_0809AAC6:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AAD0
	adds r0, r4, #7
_0809AAD0:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AADA
	movs r4, #1
	b _0809AAE0
_0809AADA:
	cmp r4, #0x11
	ble _0809AAE0
	movs r4, #0x11
_0809AAE0:
	ldr r0, [r6, #0x68]
	cmp r0, #1
	ble _0809AAFC
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	bl minigame_str_080e9d04
	ldr r0, _0809AB20 @ =0x080FF070
	adds r1, r5, #2
	adds r2, r4, #0
	bl PrintUnicodeString
_0809AAFC:
	ldr r0, _0809AB24 @ =0x080FF078
	adds r4, #1
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	adds r1, r5, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl minigame_str_080e9d04
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AB20: .4byte 0x080FF070
_0809AB24: .4byte 0x080FF078

	thumb_func_start FUN_0809ab28
FUN_0809ab28: @ 0x0809AB28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809ABA6
	cmp r5, #1
	bgt _0809AB3C
	cmp r5, #0
	beq _0809AB46
	b _0809AC1E
_0809AB3C:
	cmp r5, #2
	beq _0809ABBC
	cmp r5, #3
	beq _0809ABC6
	b _0809AC1E
_0809AB46:
	ldr r1, [r4, #0x68]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0809AB6C
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809AB68 @ =FUN_0809aa10
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809AB9C
	.align 2, 0
_0809AB68: .4byte FUN_0809aa10
_0809AB6C:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809ABB8 @ =FUN_0809aa90
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x13]
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _0809AB9C
_0809AB88:
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	adds r1, r0, #0
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	cmp r1, #0
	bne _0809AB88
_0809AB9C:
	movs r0, #0x1e
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABA6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _0809AC1E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809AC1E
	.align 2, 0
_0809ABB8: .4byte FUN_0809aa90
_0809ABBC:
	movs r0, #0x18
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABC6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809ABDC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809ABE2
_0809ABDC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809ABE2:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x64]
	cmp r2, #0
	bne _0809AC1E
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809AC24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809AC1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AC24: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ac28
FUN_0809ac28: @ 0x0809AC28
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AC7A
	ldr r0, [r4, #0x20]
	adds r0, #0x3c
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #1
	bl FUN_08099f54
	ldr r1, [r4, #0x1c]
	adds r1, #1
	cmp r1, #4
	ble _0809AC70
	movs r1, #4
_0809AC70:
	ldrb r0, [r6]
	muls r1, r0, r1
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AC7A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809ACD4 @ =0x0836A77E
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809ACD8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809ACD4: .4byte 0x0836A77E
_0809ACD8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809acdc
FUN_0809acdc: @ 0x0809ACDC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AD2A
	ldr r0, [r4, #0x20]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #5
	bl FUN_08099f54
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AD2A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809AD84 @ =0x0836A784
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809AD88 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AD84: .4byte 0x0836A784
_0809AD88: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ad8c
FUN_0809ad8c: @ 0x0809AD8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AD9E
	cmp r5, #1
	beq _0809ADF0
	b _0809AE5C
_0809AD9E:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809ADCC
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AE04 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809ADCC:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ADF0:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AE08
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AE0E
	.align 2, 0
_0809AE04: .4byte 0xFFFFFED4
_0809AE08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AE0E:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AE5C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AE38
	ldr r1, _0809AE64 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AE38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0809AE4C
	adds r0, #0xff
_0809AE4C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x10
	str r1, [r4, #0x60]
_0809AE5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE64: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ae68
FUN_0809ae68: @ 0x0809AE68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AE7A
	cmp r5, #1
	beq _0809AECA
	b _0809AF14
_0809AE7A:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AEA8
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AEE0 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809AEA8:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809AECA:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AEE4
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AEEA
	.align 2, 0
_0809AEE0: .4byte 0xFFFFFED4
_0809AEE4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AEEA:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AF14
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AF14
	ldr r1, _0809AF1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AF14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AF1C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809af20
FUN_0809af20: @ 0x0809AF20
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _0809AF80 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809AF76
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AF84 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r4, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	strb r6, [r4, #0x11]
	str r7, [r4, #0x28]
_0809AF76:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809AF80: .4byte gZakoHeaderPtr
_0809AF84: .4byte gEnemyFnTable

	thumb_func_start FUN_0809af88
FUN_0809af88: @ 0x0809AF88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _0809AFE8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809AFE0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AFEC @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r6, [r3, #0x28]
_0809AFE0:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AFE8: .4byte gZakoHeaderPtr
_0809AFEC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aff0
FUN_0809aff0: @ 0x0809AFF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B05C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B052
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B060 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B052:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B05C: .4byte gZakoHeaderPtr
_0809B060: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b064
FUN_0809b064: @ 0x0809B064
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B0D0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B0C6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B0D4 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B0C6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B0D0: .4byte gZakoHeaderPtr
_0809B0D4: .4byte gEnemyFnTable

	thumb_func_start HarpuiaMinigameEnemy_Init
HarpuiaMinigameEnemy_Init: @ 0x0809B0D8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0x10]
	cmp r7, #0
	bne _0809B160
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	movs r2, #0
	bl FUN_0809af88
	str r0, [r6, #0x2c]
	ldrb r0, [r6, #0xb]
	orrs r4, r0
	strb r4, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B15C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B15C: .4byte gEnemyFnTable
_0809B160:
	cmp r7, #1
	bne _0809B1D4
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r7, [r0]
	adds r5, r6, #0
	adds r5, #0x4a
	movs r3, #0x10
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	ldrb r0, [r6, #0xb]
	orrs r2, r0
	strb r2, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B1D0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B1D0: .4byte gEnemyFnTable
_0809B1D4:
	cmp r7, #2
	bne _0809B278
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B224
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B220 @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r7, [r0]
	b _0809B248
	.align 2, 0
_0809B220: .4byte 0x0836A7D0
_0809B224:
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B26C @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
_0809B248:
	ldr r0, _0809B270 @ =FUN_0809bd2c
	str r0, [r4, #0x24]
	ldr r1, _0809B274 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B26C: .4byte 0x0836A7D0
_0809B270: .4byte FUN_0809bd2c
_0809B274: .4byte gEnemyFnTable
_0809B278:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B2D4 @ =0x0836A818
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _0809B2D8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_0809B2C6:
	adds r0, r6, #0
	bl HarpuiaMinigameEnemy_Update
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2D4: .4byte 0x0836A818
_0809B2D8: .4byte gEnemyFnTable

	thumb_func_start HarpuiaMinigameEnemy_Update
HarpuiaMinigameEnemy_Update: @ 0x0809B2DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809B308 @ =0x0836A7A0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809B30C @ =0x0836A7B8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B308: .4byte 0x0836A7A0
_0809B30C: .4byte 0x0836A7B8

	thumb_func_start HarpuiaMinigameEnemy_Die
HarpuiaMinigameEnemy_Die: @ 0x0809B310
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _0809B34C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r3, #0x14]
	strb r2, [r3, #0xd]
	strb r2, [r3, #0xe]
	strb r2, [r3, #0xf]
	bx lr
	.align 2, 0
_0809B34C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b350
FUN_0809b350:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b354
FUN_0809b354: @ 0x0809B354
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B380
	ldr r1, _0809B37C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B400
	.align 2, 0
_0809B37C: .4byte gEnemyFnTable
_0809B380:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B3A8
	cmp r0, #1
	bgt _0809B390
	cmp r0, #0
	beq _0809B39A
	b _0809B400
_0809B390:
	cmp r0, #2
	beq _0809B3D0
	cmp r0, #3
	beq _0809B3E0
	b _0809B400
_0809B39A:
	ldr r1, _0809B3CC @ =0x0000BF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3A8:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B400
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B3FE
	.align 2, 0
_0809B3CC: .4byte 0x0000BF01
_0809B3D0:
	movs r1, #0xbf
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3E0:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B400
_0809B3FE:
	strb r0, [r4, #0xe]
_0809B400:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809b408
FUN_0809b408:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b40c
FUN_0809b40c:
	bx lr

	thumb_func_start FUN_0809b410
FUN_0809b410:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b414
FUN_0809b414:
	bx lr

	thumb_func_start FUN_0809b418
FUN_0809b418:
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b41c
FUN_0809b41c: @ 0x0809B41C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B448
	ldr r1, _0809B444 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B4CC
	.align 2, 0
_0809B444: .4byte gEnemyFnTable
_0809B448:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B470
	cmp r0, #1
	bgt _0809B458
	cmp r0, #0
	beq _0809B462
	b _0809B4CC
_0809B458:
	cmp r0, #2
	beq _0809B49C
	cmp r0, #3
	beq _0809B4AA
	b _0809B4CC
_0809B462:
	ldr r1, _0809B498 @ =0x0000BF02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B470:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B4CC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B4CA
	.align 2, 0
_0809B498: .4byte 0x0000BF02
_0809B49C:
	ldr r1, _0809B4D4 @ =0x0000BF03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B4AA:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B4CC
_0809B4CA:
	strb r0, [r4, #0xe]
_0809B4CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B4D4: .4byte 0x0000BF03

	thumb_func_start FUN_0809b4d8
FUN_0809b4d8: @ 0x0809B4D8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b4dc
FUN_0809b4dc: @ 0x0809B4DC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809B5D8
	adds r2, r5, #0
	adds r2, #0xb6
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809B512
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r6, r5, #0
	adds r6, #0xb4
	cmp r0, #2
	beq _0809B552
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldrh r2, [r1, #0x38]
	adds r0, r0, r2
	b _0809B52C
_0809B512:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne _0809B53C
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #5
_0809B52C:
	strh r0, [r1, #0x38]
	ldr r0, _0809B538 @ =0x00000137
	bl PlaySound
	b _0809B552
	.align 2, 0
_0809B538: .4byte 0x00000137
_0809B53C:
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _0809B5BC @ =0x00000137
	bl PlaySound
_0809B552:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0809B5C0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B5C4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _0809B5C8 @ =0x00269EC3
	adds r4, r4, r3
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5CC @ =0x00004707
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D0 @ =0x00004708
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D4 @ =0x00004709
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	b _0809B924
	.align 2, 0
_0809B5BC: .4byte 0x00000137
_0809B5C0: .4byte RNG_0202f388
_0809B5C4: .4byte 0x000343FD
_0809B5C8: .4byte 0x00269EC3
_0809B5CC: .4byte 0x00004707
_0809B5D0: .4byte 0x00004708
_0809B5D4: .4byte 0x00004709
_0809B5D8:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0809B5F8
	movs r1, #1
	ands r2, r1
	cmp r2, #0
	beq _0809B5F8
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809B5F8
	strb r1, [r3]
	movs r0, #0xa
	strb r0, [r5, #0xe]
_0809B5F8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _0809B600
	b _0809B936
_0809B600:
	lsls r0, r0, #2
	ldr r1, _0809B60C @ =_0809B610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B60C: .4byte _0809B610
_0809B610: @ jump table
	.4byte _0809B640 @ case 0
	.4byte _0809B6B6 @ case 1
	.4byte _0809B6F6 @ case 2
	.4byte _0809B700 @ case 3
	.4byte _0809B936 @ case 4
	.4byte _0809B73E @ case 5
	.4byte _0809B7F2 @ case 6
	.4byte _0809B936 @ case 7
	.4byte _0809B936 @ case 8
	.4byte _0809B936 @ case 9
	.4byte _0809B818 @ case 10
	.4byte _0809B8C0 @ case 11
_0809B640:
	movs r4, #0
	str r4, [r5, #0x2c]
	strb r4, [r3]
	adds r0, r5, #0
	adds r0, #0xb6
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r1, _0809B688 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0809B68C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0809B690
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
	b _0809B6AC
	.align 2, 0
_0809B688: .4byte 0x00004703
_0809B68C: .4byte pZero2
_0809B690:
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
_0809B6AC:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B6B6:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B6EE
	b _0809B936
_0809B6EE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809B936
_0809B6F6:
	movs r0, #0x30
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B700:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B738
	b _0809B936
_0809B738:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0809B936
_0809B73E:
	movs r0, #0
	str r0, [r5, #0x2c]
	strb r0, [r3]
	ldr r1, _0809B7A0 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r6, _0809B7A4 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B7A8
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B7C4
	.align 2, 0
_0809B7A0: .4byte 0x00004703
_0809B7A4: .4byte pZero2
_0809B7A8:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B7BC
	ldr r0, _0809B7B8 @ =0xFFFFFF00
	b _0809B7C0
	.align 2, 0
_0809B7B8: .4byte 0xFFFFFF00
_0809B7BC:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B7C0:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B7C4:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B7F2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B816
	b _0809B936
_0809B816:
	b _0809B924
_0809B818:
	ldr r6, _0809B86C @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B870
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B88C
	.align 2, 0
_0809B86C: .4byte pZero2
_0809B870:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B884
	ldr r0, _0809B880 @ =0xFFFFFF00
	b _0809B888
	.align 2, 0
_0809B880: .4byte 0xFFFFFF00
_0809B884:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B888:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B88C:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldr r1, _0809B940 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809B944 @ =0x0836A800
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B8C0:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, [r5, #0x60]
	adds r0, r0, r3
	str r0, [r5, #0x58]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x5c]
	rsbs r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809B936
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B914
	ldrh r0, [r1, #0x38]
	adds r0, #5
	strh r0, [r1, #0x38]
	ldr r0, _0809B948 @ =0x00000137
	bl PlaySound
_0809B914:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_0809B924:
	ldr r1, _0809B94C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809B936:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B940: .4byte 0x00004703
_0809B944: .4byte 0x0836A800
_0809B948: .4byte 0x00000137
_0809B94C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b950
FUN_0809b950: @ 0x0809B950
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b954
FUN_0809b954: @ 0x0809B954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BA0C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldr r2, _0809B9F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B9F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0809B9F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r2, _0809B9FC @ =0x00004707
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA00 @ =0x00004708
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA04 @ =0x00004709
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _0809BA08 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl HarpuiaMinigameEnemy_Die
	b _0809BD16
	.align 2, 0
_0809B9F0: .4byte RNG_0202f388
_0809B9F4: .4byte 0x000343FD
_0809B9F8: .4byte 0x00269EC3
_0809B9FC: .4byte 0x00004707
_0809BA00: .4byte 0x00004708
_0809BA04: .4byte 0x00004709
_0809BA08: .4byte gEnemyFnTable
_0809BA0C:
	ldrb r0, [r7, #0xe]
	cmp r0, #6
	bls _0809BA14
	b _0809BD16
_0809BA14:
	lsls r0, r0, #2
	ldr r1, _0809BA20 @ =_0809BA24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BA20: .4byte _0809BA24
_0809BA24: @ jump table
	.4byte _0809BA40 @ case 0
	.4byte _0809BAFC @ case 1
	.4byte _0809BBD0 @ case 2
	.4byte _0809BBDA @ case 3
	.4byte _0809BD16 @ case 4
	.4byte _0809BC08 @ case 5
	.4byte _0809BCD2 @ case 6
_0809BA40:
	ldr r1, _0809BA80 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _0809BA84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0809BA88
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
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
	b _0809BAA6
	.align 2, 0
_0809BA80: .4byte 0x00004703
_0809BA84: .4byte pZero2
_0809BA88:
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809BAA6:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	movs r0, #4
	strb r0, [r7, #0x13]
	ldr r4, _0809BB44 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _0809BB48 @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r6, _0809BB4C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BAFC:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BB18
	ldr r0, [r7, #0x54]
	ldr r1, _0809BB50 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x5c]
_0809BB18:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0809BB28
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BBAC
_0809BB28:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _0809BB3C
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BB54
_0809BB3C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BBC8
	.align 2, 0
_0809BB44: .4byte RNG_0202f388
_0809BB48: .4byte 0x000343FD
_0809BB4C: .4byte 0x00269EC3
_0809BB50: .4byte 0xFFFC4000
_0809BB54:
	ldr r4, _0809BBA0 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _0809BBA4 @ =0x000343FD
	mov r8, r3
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _0809BBA8 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	b _0809BBC8
	.align 2, 0
_0809BBA0: .4byte RNG_0202f388
_0809BBA4: .4byte 0x000343FD
_0809BBA8: .4byte 0x00269EC3
_0809BBAC:
	ldr r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
_0809BBC8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0809BD16
_0809BBD0:
	movs r0, #7
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BBDA:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BBEA
	ldr r0, [r7, #0x54]
	ldr r2, _0809BC04 @ =0xFFFC4000
	adds r0, r0, r2
	str r0, [r7, #0x54]
_0809BBEA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809BBFE
	b _0809BD16
_0809BBFE:
	movs r0, #5
	strb r0, [r7, #0xe]
	b _0809BD16
	.align 2, 0
_0809BC04: .4byte 0xFFFC4000
_0809BC08:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BC18
	ldr r0, [r7, #0x54]
	ldr r3, _0809BC74 @ =0xFFFC4000
	adds r0, r0, r3
	str r0, [r7, #0x54]
_0809BC18:
	ldr r1, _0809BC78 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r5, _0809BC7C @ =pZero2
	ldr r2, [r5]
	ldr r0, [r7, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [r7, #0x58]
	movs r3, #0xd8
	lsls r3, r3, #6
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r7, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809BC80
	ldr r0, [r7, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x68]
	b _0809BC9C
	.align 2, 0
_0809BC74: .4byte 0xFFFC4000
_0809BC78: .4byte 0x00004703
_0809BC7C: .4byte pZero2
_0809BC80:
	ldr r0, [r5]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809BC94
	ldr r0, _0809BC90 @ =0xFFFFFF00
	b _0809BC98
	.align 2, 0
_0809BC90: .4byte 0xFFFFFF00
_0809BC94:
	movs r0, #0x80
	lsls r0, r0, #1
_0809BC98:
	str r0, [r7, #0x64]
	str r4, [r7, #0x68]
_0809BC9C:
	ldr r1, [r7, #0x64]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x68]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BD16
_0809BCD2:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BCE2
	ldr r0, [r7, #0x54]
	ldr r1, _0809BD24 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0809BCE2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BD16
	ldr r1, _0809BD28 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_0809BD16:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BD24: .4byte 0xFFFC4000
_0809BD28: .4byte gEnemyFnTable

	thumb_func_start FUN_0809bd2c
FUN_0809bd2c: @ 0x0809BD2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0xc]
	ldr r3, [r2, #4]
	ldr r0, [r4, #0x2c]
	mov ip, r0
	ldr r0, [r3, #4]
	ldr r1, _0809BD58 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _0809BD5C @ =0x00020002
	cmp r0, r1
	bne _0809BD60
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD94
	ldr r0, [r2, #0x2c]
	mov r1, ip
	str r0, [r1, #0x2c]
	b _0809BD94
	.align 2, 0
_0809BD58: .4byte 0x00FF00FF
_0809BD5C: .4byte 0x00020002
_0809BD60:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BD94
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD8C
	mov r1, ip
	adds r1, #0xa4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x10
	bgt _0809BD94
	adds r0, r2, #0
	adds r0, #8
	strh r0, [r1]
	b _0809BD94
_0809BD8C:
	mov r1, ip
	adds r1, #0xb6
	movs r0, #1
	strb r0, [r1]
_0809BD94:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BDCC
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #0x2c]
	adds r0, r3, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809BDCC
	ldr r0, [r4, #4]
	ldrb r2, [r0, #1]
	cmp r2, #2
	bne _0809BDCC
	mov r1, ip
	adds r1, #0xb7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809BDC8
	adds r0, r3, #0
	adds r0, #0xb6
	strb r2, [r0]
	b _0809BDCC
_0809BDC8:
	adds r0, #1
	strb r0, [r1]
_0809BDCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809bdd4
FUN_0809bdd4: @ 0x0809BDD4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809BE2C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BE24
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809BE30 @ =gEnemyFnTable
	movs r1, #0x46
	strb r1, [r3, #9]
	adds r1, #0xd2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_0809BE24:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809BE2C: .4byte gZakoHeaderPtr
_0809BE30: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Init
CielMinigameEnemy_Init: @ 0x0809BE34
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _0809BEC4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xe9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	str r2, [r4, #0x58]
	movs r0, #0xe1
	lsls r0, r0, #4
	adds r5, r5, r0
	ldrh r0, [r5]
	str r0, [r4, #0x60]
	ldrh r0, [r5]
	str r0, [r4, #0x5c]
	strb r2, [r4, #0x13]
	adds r0, r4, #0
	bl CielMinigameEnemy_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809BEC4: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Update
CielMinigameEnemy_Update: @ 0x0809BEC8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bls _0809BEE4
	b _0809C06A
_0809BEE4:
	lsls r0, r0, #2
	ldr r1, _0809BEF0 @ =_0809BEF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BEF0: .4byte _0809BEF4
_0809BEF4: @ jump table
	.4byte _0809BF08 @ case 0
	.4byte _0809BF2C @ case 1
	.4byte _0809BF46 @ case 2
	.4byte _0809BF62 @ case 3
	.4byte _0809BFE4 @ case 4
_0809BF08:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
	str r0, [r4, #0x58]
	ldr r1, _0809BF28 @ =0x000006FF
	cmp r0, r1
	bgt _0809BF16
	b _0809C06A
_0809BF16:
	movs r0, #0xe0
	lsls r0, r0, #3
	str r0, [r4, #0x58]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BF28: .4byte 0x000006FF
_0809BF2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF3C
	b _0809C06A
_0809BF3C:
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF46:
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF5C
	b _0809C06A
_0809BF5C:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF62:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r5, r0, r2
	str r5, [r4, #0x58]
	ldr r1, _0809BFC0 @ =0x00000DCC
	adds r0, r7, r1
	ldrb r0, [r0, #4]
	adds r3, r2, #0
	cmp r0, #3
	bhi _0809BF9A
	ldr r6, _0809BFC4 @ =gJoypad
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809BF88
	adds r0, r5, r3
	str r0, [r4, #0x58]
_0809BF88:
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BF9A
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0809BF9A:
	adds r0, r4, #0
	bl FUN_0809c110
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0809C06A
	cmp r0, #1
	bne _0809BFC8
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, [r4, #0x60]
	b _0809BFD8
	.align 2, 0
_0809BFC0: .4byte 0x00000DCC
_0809BFC4: .4byte gJoypad
_0809BFC8:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	ldr r3, _0809BFE0 @ =0xFFFFE000
	adds r1, r1, r3
	str r1, [r0]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
_0809BFD8:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BFE0: .4byte 0xFFFFE000
_0809BFE4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r3, r0, r1
	str r3, [r4, #0x54]
	ldr r5, _0809C038 @ =0x00000DCC
	adds r0, r7, r5
	ldrb r0, [r0, #4]
	adds r2, r1, #0
	cmp r0, #3
	bhi _0809C01C
	ldr r5, _0809C03C @ =gJoypad
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C00A
	adds r0, r3, r2
	str r0, [r4, #0x54]
_0809C00A:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C01C
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_0809C01C:
	cmp r2, #0
	ble _0809C044
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r3, _0809C040 @ =0x00000E04
	adds r1, r7, r3
	b _0809C058
	.align 2, 0
_0809C038: .4byte 0x00000DCC
_0809C03C: .4byte gJoypad
_0809C040: .4byte 0x00000E04
_0809C044:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	bge _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r5, _0809C0BC @ =0x00000E04
	adds r1, r7, r5
_0809C058:
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	str r0, [r4, #0x54]
	movs r0, #3
_0809C068:
	strb r0, [r4, #0xd]
_0809C06A:
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _0809C0E8
	ldr r0, _0809C0C0 @ =0x00000DCC
	adds r3, r7, r0
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r4, #0x54]
	asrs r1, r0, #8
	adds r2, r1, #0
	subs r2, #0x18
	adds r0, r2, #0
	cmp r2, #0
	bge _0809C08E
	adds r0, r1, #7
_0809C08E:
	asrs r1, r0, #5
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldrb r5, [r4, #0x11]
	cmp r0, r5
	bne _0809C0CC
	ldr r2, _0809C0C4 @ =0x00000DE9
	adds r0, r7, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r3, #8]
	adds r0, #0xa
	str r0, [r3, #8]
	ldr r1, _0809C0C8 @ =0x0001869F
	cmp r0, r1
	bls _0809C0D6
	str r1, [r3, #8]
	b _0809C0D6
	.align 2, 0
_0809C0BC: .4byte 0x00000E04
_0809C0C0: .4byte 0x00000DCC
_0809C0C4: .4byte 0x00000DE9
_0809C0C8: .4byte 0x0001869F
_0809C0CC:
	ldr r3, _0809C0F0 @ =0x00000E13
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809C0D6:
	ldr r1, _0809C0F4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C0E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809C0F0: .4byte 0x00000E13
_0809C0F4: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy_Die
CielMinigameEnemy_Die: @ 0x0809C0F8
	ldr r2, _0809C10C @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0809C10C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c110
FUN_0809c110: @ 0x0809C110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r5, [r0, #0x28]
	ldr r0, [r0, #0x54]
	asrs r1, r0, #8
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0
	bge _0809C12C
	adds r0, r1, #7
_0809C12C:
	asrs r0, r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0
	ldr r1, _0809C1A4 @ =0x0836A85C
	mov r8, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r6, r1, #1
	ldr r2, _0809C1A8 @ =0x0836A87A
	mov sb, r2
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sl, r1
_0809C148:
	adds r0, r4, r6
	mov r7, r8
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0809C1BA
	ldrb r2, [r1]
	lsrs r0, r2, #1
	lsls r0, r0, #0xc
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r3, r0, r1
	lsls r1, r2, #1
	movs r7, #0xdf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0xff
	beq _0809C1B0
	mov r0, ip
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, r3
	bge _0809C1B0
	mov r1, ip
	ldr r0, [r1, #0x58]
	cmp r0, r3
	blt _0809C1B0
	mov r0, ip
	adds r0, #0xbc
	strb r2, [r0]
	ldr r2, _0809C1AC @ =0x00000E04
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r7, ip
	str r3, [r7, #0x58]
	mov r1, sl
	adds r0, r4, r1
	add r0, sb
	ldrb r0, [r0]
	b _0809C1BC
	.align 2, 0
_0809C1A4: .4byte 0x0836A85C
_0809C1A8: .4byte 0x0836A87A
_0809C1AC: .4byte 0x00000E04
_0809C1B0:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _0809C148
_0809C1BA:
	movs r0, #0
_0809C1BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809c1cc
FUN_0809c1cc: @ 0x0809C1CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809C224 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809C21C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C228 @ =gEnemyFnTable
	movs r1, #0x47
	strb r1, [r3, #9]
	adds r1, #0xd5
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_0809C21C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C224: .4byte gZakoHeaderPtr
_0809C228: .4byte gEnemyFnTable

	thumb_func_start CielMinigameEnemy2_Init
CielMinigameEnemy2_Init: @ 0x0809C22C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r1, _0809C2D4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xe9
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	subs r2, #1
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xde
	lsls r0, r0, #4
	adds r4, r4, r0
	ldrb r0, [r5, #0x10]
	adds r4, r4, r0
	ldrb r1, [r4]
	strb r1, [r5, #0x12]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl ForceEntityPalette
	movs r0, #0xd8
	lsls r0, r0, #8
	str r0, [r5, #0x54]
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #4
	movs r0, #0x30
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x10]
	cmp r0, #3
	bne _0809C2C6
	movs r0, #0xe8
	lsls r0, r0, #8
	str r0, [r5, #0x54]
_0809C2C6:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0809C2D0
	cmp r0, #3
	bne _0809C2DC
_0809C2D0:
	ldr r0, _0809C2D8 @ =0xFFFFFF00
	b _0809C2DE
	.align 2, 0
_0809C2D4: .4byte gEnemyFnTable
_0809C2D8: .4byte 0xFFFFFF00
_0809C2DC:
	movs r0, #0
_0809C2DE:
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl CielMinigameEnemy2_Update
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start CielMinigameEnemy2_Update
CielMinigameEnemy2_Update: @ 0x0809C300
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0809C312
	cmp r0, #1
	beq _0809C350
	b _0809C38E
_0809C312:
	ldr r1, _0809C344 @ =0x00000E0F
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r0, _0809C348 @ =gZakoHeaderPtr
	ldr r0, [r0]
	movs r3, #0xa
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _0809C38E
	ldr r1, _0809C34C @ =0x00000E12
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C38E
	movs r3, #0xde
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C38C
	.align 2, 0
_0809C344: .4byte 0x00000E0F
_0809C348: .4byte gZakoHeaderPtr
_0809C34C: .4byte 0x00000E12
_0809C350:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	cmp r1, r0
	blt _0809C38E
	ldrb r1, [r4, #0x12]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r0, [r5]
	str r0, [r4, #0x58]
	movs r0, #0
_0809C38C:
	strb r0, [r4, #0xd]
_0809C38E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CielMinigameEnemy2_Die
CielMinigameEnemy2_Die:
	.byte 0x04, 0x4A, 0x41, 0x7A
	.byte 0x89, 0x00, 0x89, 0x18, 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69, 0x41, 0x61, 0x70, 0x47
	.byte 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0809c3b4
FUN_0809c3b4: @ 0x0809C3B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809C428 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C41A
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C42C @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r5, [r4, #0x10]
	strb r2, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0xb4
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x28]
_0809C41A:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809C428: .4byte gZakoHeaderPtr
_0809C42C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c430
FUN_0809c430: @ 0x0809C430
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _0809C48C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C484
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C490 @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0x11]
	str r6, [r4, #0x28]
_0809C484:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C48C: .4byte gZakoHeaderPtr
_0809C490: .4byte gEnemyFnTable

	thumb_func_start Enemy72_Init
Enemy72_Init: @ 0x0809C494
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0809C534
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0809C4DE
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _0809C504
_0809C4DE:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
	movs r0, #0x80
	rsbs r0, r0, #0
_0809C504:
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xb]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r5, #0x1d]
	ldr r1, _0809C530 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r2, [r5, #0xd]
	strb r2, [r5, #0xe]
	strb r2, [r5, #0xf]
	b _0809C56E
	.align 2, 0
_0809C530: .4byte gEnemyFnTable
_0809C534:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809C57C @ =0x0836A8DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _0809C580 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r1, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
_0809C56E:
	adds r0, r5, #0
	bl Enemy72_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C57C: .4byte 0x0836A8DC
_0809C580: .4byte gEnemyFnTable

	thumb_func_start Enemy72_Update
Enemy72_Update: @ 0x0809C584
	push {lr}
	ldr r2, _0809C598 @ =0x0836A8BC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809C598: .4byte 0x0836A8BC

	thumb_func_start Enemy72_Die
Enemy72_Die: @ 0x0809C59C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0809C5B8 @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0809C5B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c5bc
FUN_0809c5bc: @ 0x0809C5BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #1
	beq _0809C614
	cmp r2, #1
	bgt _0809C5D0
	cmp r2, #0
	beq _0809C5D6
	b _0809C65A
_0809C5D0:
	cmp r2, #2
	beq _0809C63C
	b _0809C65A
_0809C5D6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C5F6
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0809C5FC
_0809C5F6:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0809C638 @ =0xFFFFF400
_0809C5FC:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C614:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809C65A
	.align 2, 0
_0809C638: .4byte 0xFFFFF400
_0809C63C:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809C65A
	ldr r1, _0809C660 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c664
FUN_0809c664: @ 0x0809C664
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809C6C8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C6BC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809C6B4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0809C6B8 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809C6CE
	.align 2, 0
_0809C6B4: .4byte 0xFFFFF800
_0809C6B8: .4byte 0xFFFFFC00
_0809C6BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C6EC
_0809C6C8:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809C6CE:
	bl CreateSmoke
	ldr r1, _0809C6E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809C852
	.align 2, 0
_0809C6E8: .4byte gEnemyFnTable
_0809C6EC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809C6F8
	cmp r0, #1
	beq _0809C76C
	b _0809C852
_0809C6F8:
	ldr r1, _0809C734 @ =0x0000A304
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809C738
	movs r0, #0xc0
	str r0, [r4, #0x5c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	b _0809C75C
	.align 2, 0
_0809C734: .4byte 0x0000A304
_0809C738:
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
_0809C75C:
	strb r0, [r2]
	ldr r0, _0809C7EC @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C76C:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809C786
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C786
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809C7F0 @ =0x0836A8DC
	bl SetDDP
_0809C786:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809C796
	str r1, [r4, #0x60]
_0809C796:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809C7BA
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809C7F4 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809C7BA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C7F8
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C7EC: .4byte 0xFFFFFC00
_0809C7F0: .4byte 0x0836A8DC
_0809C7F4: .4byte 0xFFFFFD00
_0809C7F8:
	ldr r0, [r4, #0x54]
	ldr r1, _0809C824 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C824: .4byte 0xFFFFF800
_0809C828:
	movs r0, #0xef
	ands r0, r2
_0809C82C:
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
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809C84C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809C852:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
