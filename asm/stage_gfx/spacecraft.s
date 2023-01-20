	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initSpaceCraft
initSpaceCraft: @ 0x0800B20C
	push {lr}
	ldr r1, _0800B260 @ =0x02002200
	ldr r2, _0800B264 @ =0x0002D024
	adds r0, r1, r2
	movs r3, #0
	strb r3, [r0]
	adds r2, #2
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #2
	adds r0, r1, r2
	str r3, [r0]
	ldr r0, _0800B268 @ =0x0002D02C
	adds r2, r1, r0
	movs r0, #0xff
	lsls r0, r0, #0xc
	str r0, [r2]
	ldr r0, _0800B26C @ =0x0002D030
	adds r2, r1, r0
	movs r0, #0x90
	lsls r0, r0, #9
	str r0, [r2]
	ldr r2, _0800B270 @ =0x0002D025
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _0800B274 @ =0x0002D036
	adds r1, r1, r0
	strh r3, [r1]
	ldr r0, _0800B278 @ =0x0202FDC0
	ldrb r1, [r0, #4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800B25A
	movs r0, #0x10
	movs r1, #1
	movs r2, #0x30
	bl loadScreenIntoBlockMap
_0800B25A:
	pop {r0}
	bx r0
	.align 2, 0
_0800B260: .4byte 0x02002200
_0800B264: .4byte 0x0002D024
_0800B268: .4byte 0x0002D02C
_0800B26C: .4byte 0x0002D030
_0800B270: .4byte 0x0002D025
_0800B274: .4byte 0x0002D036
_0800B278: .4byte 0x0202FDC0

	thumb_func_start FUN_0800b27c
FUN_0800b27c: @ 0x0800B27C
	push {lr}
	ldr r3, _0800B2B8 @ =0x02002200
	ldr r1, _0800B2BC @ =0x000007D4
	adds r0, r3, r1
	ldrh r2, [r0]
	lsrs r1, r2, #8
	cmp r1, #1
	bne _0800B2C4
	movs r0, #0xff
	ands r0, r2
	cmp r0, #0
	bne _0800B2C4
	ldr r2, _0800B2C0 @ =0x0002D036
	adds r3, r3, r2
	ldrh r2, [r3]
	ands r1, r2
	cmp r1, #0
	bne _0800B2AE
	movs r0, #1
	orrs r0, r2
	strh r0, [r3]
	movs r0, #5
	movs r1, #0
	bl loadBlink
_0800B2AE:
	movs r0, #5
	bl FUN_08004068
	b _0800B2E0
	.align 2, 0
_0800B2B8: .4byte 0x02002200
_0800B2BC: .4byte 0x000007D4
_0800B2C0: .4byte 0x0002D036
_0800B2C4:
	ldr r0, _0800B318 @ =0x02002200
	ldr r1, _0800B31C @ =0x0002D036
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B2E0
	movs r0, #1
	eors r0, r1
	strh r0, [r2]
	movs r0, #5
	bl clearBlink
_0800B2E0:
	ldr r2, _0800B318 @ =0x02002200
	ldr r1, _0800B320 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #1
	bne _0800B324
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _0800B324
	ldr r1, _0800B31C @ =0x0002D036
	adds r2, r2, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0800B310
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #9
	movs r1, #0
	bl loadBlink
_0800B310:
	movs r0, #9
	bl FUN_08004068
	b _0800B340
	.align 2, 0
_0800B318: .4byte 0x02002200
_0800B31C: .4byte 0x0002D036
_0800B320: .4byte 0x000007D6
_0800B324:
	ldr r0, _0800B388 @ =0x02002200
	ldr r1, _0800B38C @ =0x0002D036
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800B340
	movs r0, #2
	eors r0, r1
	strh r0, [r2]
	movs r0, #9
	bl clearBlink
_0800B340:
	ldr r2, _0800B388 @ =0x02002200
	ldr r1, _0800B390 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #1
	bne _0800B394
	movs r0, #0xff
	ands r0, r1
	cmp r0, #3
	bne _0800B394
	ldr r0, _0800B38C @ =0x0002D036
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0800B37A
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #6
	movs r1, #0
	bl loadBlink
	movs r0, #8
	movs r1, #0
	bl loadBlink
_0800B37A:
	movs r0, #6
	bl FUN_08004068
	movs r0, #8
	bl FUN_08004068
	b _0800B3B6
	.align 2, 0
_0800B388: .4byte 0x02002200
_0800B38C: .4byte 0x0002D036
_0800B390: .4byte 0x000007D4
_0800B394:
	ldr r0, _0800B400 @ =0x02002200
	ldr r1, _0800B404 @ =0x0002D036
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800B3B6
	movs r0, #4
	eors r0, r1
	strh r0, [r2]
	movs r0, #6
	bl clearBlink
	movs r0, #8
	bl clearBlink
_0800B3B6:
	ldr r0, _0800B400 @ =0x02002200
	ldr r2, _0800B408 @ =0x000007D6
	adds r1, r0, r2
	ldrh r2, [r1]
	lsrs r1, r2, #8
	adds r3, r0, #0
	cmp r1, #1
	bne _0800B40C
	movs r0, #0xff
	ands r0, r2
	cmp r0, #4
	bne _0800B40C
	ldr r0, _0800B404 @ =0x0002D036
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800B3F2
	movs r0, #8
	orrs r0, r1
	strh r0, [r2]
	movs r0, #7
	movs r1, #0
	bl loadBlink
	movs r0, #0xa
	movs r1, #0
	bl loadBlink
_0800B3F2:
	movs r0, #7
	bl FUN_08004068
	movs r0, #0xa
	bl FUN_08004068
	b _0800B42C
	.align 2, 0
_0800B400: .4byte 0x02002200
_0800B404: .4byte 0x0002D036
_0800B408: .4byte 0x000007D6
_0800B40C:
	ldr r1, _0800B430 @ =0x0002D036
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800B42C
	movs r0, #8
	eors r0, r1
	strh r0, [r2]
	movs r0, #7
	bl clearBlink
	movs r0, #0xa
	bl clearBlink
_0800B42C:
	pop {r0}
	bx r0
	.align 2, 0
_0800B430: .4byte 0x0002D036

	thumb_func_start nop_0800b434
nop_0800b434: @ 0x0800B434
	bx lr
	.align 2, 0

	thumb_func_start exitSpaceCraft
exitSpaceCraft: @ 0x0800B438
	push {lr}
	movs r0, #5
	bl clearBlink
	movs r0, #6
	bl clearBlink
	movs r0, #7
	bl clearBlink
	movs r0, #8
	bl clearBlink
	movs r0, #9
	bl clearBlink
	movs r0, #0xa
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start spacecraft0Script
spacecraft0Script: @ 0x0800B464
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _0800B4B6
	ldr r1, [r5, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r4, r1, #1
	ldr r3, _0800B4C4 @ =0x02002144
	adds r4, r4, r3
	ldr r0, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r0, r2
	movs r2, #0x44
	orrs r0, r2
	strh r0, [r4]
	lsls r1, r1, #2
	adds r3, #8
	adds r1, r1, r3
	str r6, [r1]
	str r6, [r5, #0x68]
	ldr r0, _0800B4C8 @ =0x08522340
	ldr r0, [r0]
	ldr r1, _0800B4CC @ =0x08522348
	adds r0, r0, r1
	ldrh r2, [r4]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0800B4B6:
	ldr r0, [r5, #0x68]
	adds r0, #1
	str r0, [r5, #0x68]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B4C4: .4byte 0x02002144
_0800B4C8: .4byte 0x08522340
_0800B4CC: .4byte 0x08522348

	thumb_func_start spacecraft0ScrollBG
spacecraft0ScrollBG: @ 0x0800B4D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r4, #0x9f
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	mov sl, r0
	cmp r0, #0
	bne _0800B4F0
	b _0800B8FA
_0800B4F0:
	ldr r2, _0800B828 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	mov r3, sl
	str r3, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800B82C @ =0x0400001C
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _0800B830 @ =0xA6600001
	str r0, [r1]
	ldr r0, [r7, #0x34]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B834 @ =0xFFFFFA60
	adds r0, r0, r1
	asrs r0, r0, #3
	adds r0, #0x13
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	adds r0, #0x9f
	cmp r0, #0x80
	ble _0800B548
	movs r1, #0x9f
	lsls r1, r1, #2
	add r1, sl
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_0800B538:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _0800B548
	adds r0, r3, r4
	cmp r0, #0x80
	bgt _0800B538
_0800B548:
	ldr r0, [r7, #0x34]
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r2, _0800B834 @ =0xFFFFFA60
	adds r0, r0, r2
	asrs r0, r0, #4
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #0
	blt _0800B5BC
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r4
	adds r6, r0, #0
	cmp r1, #0x80
	ble _0800B594
	adds r1, r2, #0
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0x10
	adds r3, r0, r2
	lsls r2, r4, #2
	add r2, sl
	movs r0, #0x80
	lsls r0, r0, #9
	mov r8, r0
_0800B582:
	str r3, [r2]
	add r3, r8
	subs r2, #4
	subs r4, #1
	cmp r4, #0
	blt _0800B5BC
	adds r0, r1, r4
	cmp r0, #0x80
	bgt _0800B582
_0800B594:
	cmp r4, #0
	blt _0800B5BC
	asrs r2, r6, #0x10
	adds r0, r2, r4
	cmp r0, #0x77
	ble _0800B5BC
	lsls r0, r4, #2
	mov r3, sl
	adds r1, r0, r3
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_0800B5AC:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _0800B5BC
	adds r0, r3, r4
	cmp r0, #0x77
	bgt _0800B5AC
_0800B5BC:
	ldr r0, [r7, #0x34]
	lsls r0, r0, #0xd
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B834 @ =0xFFFFFA60
	adds r0, r0, r1
	asrs r0, r0, #5
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #0
	blt _0800B62E
	lsls r0, r1, #0x10
	asrs r2, r0, #0x10
	adds r1, r2, r4
	adds r6, r0, #0
	cmp r1, #0x77
	ble _0800B606
	adds r3, r2, #0
	lsls r0, r4, #0x10
	movs r1, #0xee
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r2, r4, #2
	add r2, sl
	movs r0, #0x80
	lsls r0, r0, #9
	mov r8, r0
_0800B5F4:
	str r1, [r2]
	add r1, r8
	subs r2, #4
	subs r4, #1
	cmp r4, #0
	blt _0800B62E
	adds r0, r3, r4
	cmp r0, #0x77
	bgt _0800B5F4
_0800B606:
	cmp r4, #0
	blt _0800B62E
	asrs r2, r6, #0x10
	adds r0, r2, r4
	cmp r0, #0x70
	ble _0800B62E
	lsls r0, r4, #2
	mov r3, sl
	adds r1, r0, r3
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r5
_0800B61E:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _0800B62E
	adds r0, r3, r4
	cmp r0, #0x70
	bgt _0800B61E
_0800B62E:
	lsls r2, r4, #0x10
	ldr r0, [r7, #0x68]
	lsrs r0, r0, #1
	ldr r1, [r7, #0x34]
	asrs r1, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B838 @ =0xFFFFFB00
	adds r0, r0, r1
	asrs r0, r0, #4
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r4, #0
	lsrs r3, r2, #0x10
	mov r8, r3
	asrs r2, r2, #0x10
	cmp r4, r2
	bgt _0800B676
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x26
	bgt _0800B676
	mov r6, sl
	adds r3, r0, #0
	lsls r1, r3, #0x10
	orrs r1, r5
_0800B668:
	stm r6!, {r1}
	adds r4, #1
	cmp r4, r2
	bgt _0800B676
	adds r0, r3, r4
	cmp r0, #0x26
	ble _0800B668
_0800B676:
	ldr r0, [r7, #0x68]
	lsrs r0, r0, #2
	ldr r1, [r7, #0x34]
	asrs r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B838 @ =0xFFFFFB00
	adds r0, r0, r1
	asrs r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	str r0, [sp]
	cmp r4, r2
	bgt _0800B70A
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r4
	adds r6, r0, #0
	cmp r1, #0x26
	bgt _0800B6E0
	mov r8, r5
	lsls r0, r4, #0x10
	movs r1, #0x9c
	lsls r1, r1, #0xe
	subs r1, r1, r0
	lsls r0, r4, #2
	add r0, sl
	mov ip, r0
	ldr r0, _0800B83C @ =0xFFFF0000
	mov sb, r0
	str r3, [sp, #4]
_0800B6C0:
	adds r0, r1, #0
	mov r3, r8
	orrs r0, r3
	mov r3, ip
	adds r3, #4
	mov ip, r3
	subs r3, #4
	stm r3!, {r0}
	add r1, sb
	adds r4, #1
	cmp r4, r2
	bgt _0800B70A
	ldr r3, [sp, #4]
	adds r0, r3, r4
	cmp r0, #0x26
	ble _0800B6C0
_0800B6E0:
	ldr r0, [sp]
	asrs r2, r0, #0x10
	cmp r4, r2
	bgt _0800B70A
	asrs r1, r6, #0x10
	adds r0, r1, r4
	cmp r0, #0x34
	bgt _0800B70A
	lsls r0, r4, #2
	mov r3, sl
	adds r6, r0, r3
	adds r3, r1, #0
	lsls r1, r3, #0x10
	orrs r1, r5
_0800B6FC:
	stm r6!, {r1}
	adds r4, #1
	cmp r4, r2
	bgt _0800B70A
	adds r0, r3, r4
	cmp r0, #0x34
	ble _0800B6FC
_0800B70A:
	ldr r0, [r7, #0x68]
	lsrs r0, r0, #3
	ldr r1, [r7, #0x34]
	asrs r1, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B838 @ =0xFFFFFB00
	adds r0, r0, r1
	asrs r0, r0, #6
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, [sp]
	asrs r2, r3, #0x10
	cmp r4, r2
	bgt _0800B79A
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r4
	adds r6, r0, #0
	cmp r1, #0x34
	bgt _0800B770
	mov r8, r5
	lsls r0, r4, #0x10
	movs r1, #0xd4
	lsls r1, r1, #0xe
	subs r1, r1, r0
	lsls r0, r4, #2
	add r0, sl
	mov ip, r0
	ldr r0, _0800B83C @ =0xFFFF0000
	mov sb, r0
	str r3, [sp, #4]
_0800B750:
	adds r0, r1, #0
	mov r3, r8
	orrs r0, r3
	mov r3, ip
	adds r3, #4
	mov ip, r3
	subs r3, #4
	stm r3!, {r0}
	add r1, sb
	adds r4, #1
	cmp r4, r2
	bgt _0800B79A
	ldr r3, [sp, #4]
	adds r0, r3, r4
	cmp r0, #0x34
	ble _0800B750
_0800B770:
	ldr r0, [sp]
	asrs r2, r0, #0x10
	cmp r4, r2
	bgt _0800B79A
	asrs r1, r6, #0x10
	adds r0, r1, r4
	cmp r0, #0x3f
	bgt _0800B79A
	lsls r0, r4, #2
	mov r3, sl
	adds r6, r0, r3
	adds r3, r1, #0
	lsls r1, r3, #0x10
	orrs r1, r5
_0800B78C:
	stm r6!, {r1}
	adds r4, #1
	cmp r4, r2
	bgt _0800B79A
	adds r0, r3, r4
	cmp r0, #0x3f
	ble _0800B78C
_0800B79A:
	ldr r0, [r7, #0x68]
	lsrs r0, r0, #4
	ldr r1, [r7, #0x34]
	asrs r1, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r1, _0800B838 @ =0xFFFFFB00
	adds r0, r0, r1
	asrs r0, r0, #7
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, [sp]
	asrs r2, r3, #0x10
	cmp r4, r2
	bgt _0800B84A
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	mov r8, r1
	adds r1, r1, r4
	adds r6, r0, #0
	cmp r1, #0x3f
	bgt _0800B804
	mov sb, r5
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0xf
	adds r3, r0, r1
	lsls r0, r4, #2
	add r0, sl
	mov ip, r0
	str r2, [sp, #8]
	mov r1, r8
_0800B7E2:
	adds r0, r3, #0
	mov r2, sb
	orrs r0, r2
	mov r2, ip
	adds r2, #4
	mov ip, r2
	subs r2, #4
	stm r2!, {r0}
	ldr r0, _0800B83C @ =0xFFFF0000
	adds r3, r3, r0
	adds r4, #1
	ldr r2, [sp, #8]
	cmp r4, r2
	bgt _0800B84A
	adds r0, r1, r4
	cmp r0, #0x3f
	ble _0800B7E2
_0800B804:
	ldr r3, [sp]
	asrs r2, r3, #0x10
	cmp r4, r2
	bgt _0800B84A
	asrs r1, r6, #0x10
	adds r0, r1, r4
	cmp r0, #0x47
	bgt _0800B84A
	lsls r0, r4, #2
	mov r3, sl
	adds r6, r0, r3
	adds r3, r1, #0
	lsls r1, r3, #0x10
	orrs r1, r5
_0800B820:
	stm r6!, {r1}
	adds r4, #1
	b _0800B840
	.align 2, 0
_0800B828: .4byte 0x03001590
_0800B82C: .4byte 0x0400001C
_0800B830: .4byte 0xA6600001
_0800B834: .4byte 0xFFFFFA60
_0800B838: .4byte 0xFFFFFB00
_0800B83C: .4byte 0xFFFF0000
_0800B840:
	cmp r4, r2
	bgt _0800B84A
	adds r0, r3, r4
	cmp r0, #0x47
	ble _0800B820
_0800B84A:
	ldr r0, [r7, #0x68]
	lsrs r0, r0, #5
	ldr r1, [r7, #0x34]
	asrs r1, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r7, #0x38]
	ldr r7, _0800B90C @ =0xFFFFFB00
	adds r0, r0, r7
	asrs r0, r0, #8
	adds r0, #0x18
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, [sp]
	asrs r2, r0, #0x10
	cmp r4, r2
	bgt _0800B8FA
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r4
	adds r6, r0, #0
	cmp r1, #0x47
	bgt _0800B8AC
	mov r8, r5
	lsls r0, r4, #0x10
	movs r1, #0x90
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r4, #2
	add r0, sl
	mov ip, r0
	ldr r7, _0800B910 @ =0xFFFF0000
	mov sb, r7
_0800B88E:
	adds r0, r1, #0
	mov r7, r8
	orrs r0, r7
	mov r7, ip
	adds r7, #4
	mov ip, r7
	subs r7, #4
	stm r7!, {r0}
	add r1, sb
	adds r4, #1
	cmp r4, r2
	bgt _0800B8FA
	adds r0, r3, r4
	cmp r0, #0x47
	ble _0800B88E
_0800B8AC:
	ldr r0, [sp]
	asrs r7, r0, #0x10
	cmp r4, r7
	bgt _0800B8FA
	asrs r1, r6, #0x10
	adds r0, r1, r4
	cmp r0, #0x53
	bgt _0800B8D8
	lsls r0, r4, #2
	mov r2, sl
	adds r6, r0, r2
	adds r3, r1, #0
	lsls r1, r3, #0x10
	orrs r1, r5
	adds r2, r7, #0
_0800B8CA:
	stm r6!, {r1}
	adds r4, #1
	cmp r4, r2
	bgt _0800B8FA
	adds r0, r3, r4
	cmp r0, #0x53
	ble _0800B8CA
_0800B8D8:
	ldr r3, [sp]
	asrs r0, r3, #0x10
	cmp r4, r0
	bgt _0800B8FA
	adds r2, r0, #0
	lsls r0, r4, #0x10
	movs r1, #0xe4
	lsls r1, r1, #0xf
	subs r1, r1, r0
	lsls r0, r4, #2
	add r0, sl
	ldr r3, _0800B910 @ =0xFFFF0000
_0800B8F0:
	stm r0!, {r1}
	adds r1, r1, r3
	adds r4, #1
	cmp r4, r2
	ble _0800B8F0
_0800B8FA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B90C: .4byte 0xFFFFFB00
_0800B910: .4byte 0xFFFF0000

	thumb_func_start spacecraft_0800b914
spacecraft_0800b914: @ 0x0800B914
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	ldrb r1, [r7, #0xe]
	mov r8, r1
	cmp r1, #0
	bne _0800B97E
	lsrs r5, r0, #0x14
	lsls r5, r5, #1
	ldr r0, _0800B98C @ =0x02002144
	adds r5, r5, r0
	ldr r1, [r7, #0x64]
	ldr r2, _0800B990 @ =0x00004046
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r5]
	ldr r0, _0800B994 @ =0x08522348
	ldr r0, [r0]
	ldr r2, _0800B998 @ =0x08522350
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldrh r0, [r5]
	ands r4, r0
	lsls r4, r4, #3
	ldr r0, _0800B99C @ =0x06000800
	adds r4, r4, r0
	mov r1, r8
	str r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r2, r6
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800B97E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B98C: .4byte 0x02002144
_0800B990: .4byte 0x00004046
_0800B994: .4byte 0x08522348
_0800B998: .4byte 0x08522350
_0800B99C: .4byte 0x06000800

	thumb_func_start fixWhiteOmegaCoord
fixWhiteOmegaCoord: @ 0x0800B9A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _0800B9CC @ =0x02002200
	ldr r1, _0800B9D0 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800B9D8
	ldr r0, _0800B9D4 @ =0x02002140
	lsls r1, r3, #8
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0800B9E2
	.align 2, 0
_0800B9CC: .4byte 0x02002200
_0800B9D0: .4byte 0x0002D025
_0800B9D4: .4byte 0x02002140
_0800B9D8:
	ldr r2, _0800BACC @ =0x02002140
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_0800B9E2:
	ldr r2, _0800BAD0 @ =0x02002200
	mov r8, r2
	ldr r0, _0800BAD4 @ =0x0002C002
	add r0, r8
	ldrh r0, [r0]
	lsrs r3, r3, #4
	mov sb, r3
	cmp r0, #0
	beq _0800BA3A
	ldr r0, _0800BAD8 @ =0x08522348
	ldr r0, [r0]
	ldr r6, _0800BADC @ =0x08522350
	adds r0, r0, r6
	lsls r5, r3, #1
	ldr r1, _0800BAE0 @ =0x02002144
	adds r5, r5, r1
	ldrh r2, [r5]
	movs r4, #0xf8
	lsls r4, r4, #5
	adds r1, r4, #0
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	movs r1, #0
	ldrh r0, [r5]
	ands r4, r0
	lsls r4, r4, #3
	ldr r0, _0800BAE4 @ =0x06000800
	adds r4, r4, r0
	str r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r2, r6
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
_0800BA3A:
	ldr r0, _0800BAE8 @ =0x0002D028
	add r0, r8
	ldr r2, [r0]
	mov r5, r8
	cmp r2, #0
	beq _0800BA84
	ldr r6, _0800BAEC @ =0x0002D02C
	adds r1, r5, r6
	ldr r0, [r2, #0x54]
	str r0, [r1]
	ldr r0, _0800BAF0 @ =0x0002D030
	adds r1, r5, r0
	ldr r0, [r2, #0x58]
	str r0, [r1]
	ldr r0, _0800BAF4 @ =0x0202F360
	ldrb r1, [r2, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0800BA84
	ldr r1, _0800BAF8 @ =0x03002AC0
	ldr r6, _0800BAFC @ =0x00000404
	adds r2, r1, r6
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r0, _0800BB00 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0x20
	strh r0, [r1]
_0800BA84:
	mov r1, sb
	lsls r3, r1, #2
	ldr r2, _0800BB04 @ =0x0200214C
	adds r4, r3, r2
	ldr r1, [r7, #0x34]
	ldr r6, _0800BAEC @ =0x0002D02C
	adds r0, r5, r6
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x30
	ldr r0, [r7, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r4]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [r7, #0x38]
	ldr r2, _0800BAF0 @ =0x0002D030
	adds r0, r5, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x90
	ldr r0, [r7, #0x30]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BACC: .4byte 0x02002140
_0800BAD0: .4byte 0x02002200
_0800BAD4: .4byte 0x0002C002
_0800BAD8: .4byte 0x08522348
_0800BADC: .4byte 0x08522350
_0800BAE0: .4byte 0x02002144
_0800BAE4: .4byte 0x06000800
_0800BAE8: .4byte 0x0002D028
_0800BAEC: .4byte 0x0002D02C
_0800BAF0: .4byte 0x0002D030
_0800BAF4: .4byte 0x0202F360
_0800BAF8: .4byte 0x03002AC0
_0800BAFC: .4byte 0x00000404
_0800BB00: .4byte 0x00000406
_0800BB04: .4byte 0x0200214C

	thumb_func_start fallSnowOnSpacecraft
fallSnowOnSpacecraft: @ 0x0800BB08
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _0800BB8E
	lsrs r3, r0, #0x14
	lsls r2, r3, #1
	ldr r4, _0800BB5C @ =0x02002144
	adds r2, r2, r4
	ldr r1, [r5, #0x64]
	movs r0, #0x45
	orrs r1, r0
	strh r1, [r2]
	lsls r3, r3, #2
	adds r4, #8
	adds r3, r3, r4
	str r6, [r3]
	ldr r0, _0800BB60 @ =0x08522344
	ldr r0, [r0]
	ldr r2, _0800BB64 @ =0x0852234C
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #4
	bl appendBgMapTask
	ldr r1, _0800BB68 @ =0x02002180
	ldr r0, _0800BB6C @ =0x00003B44
	strh r0, [r1]
	ldr r0, _0800BB70 @ =0x02002200
	ldr r4, _0800BB74 @ =0x0002D024
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800BB7C
	ldr r0, _0800BB78 @ =0x00001010
	b _0800BB80
	.align 2, 0
_0800BB5C: .4byte 0x02002144
_0800BB60: .4byte 0x08522344
_0800BB64: .4byte 0x0852234C
_0800BB68: .4byte 0x02002180
_0800BB6C: .4byte 0x00003B44
_0800BB70: .4byte 0x02002200
_0800BB74: .4byte 0x0002D024
_0800BB78: .4byte 0x00001010
_0800BB7C:
	movs r0, #0x80
	lsls r0, r0, #5
_0800BB80:
	strh r0, [r1, #2]
	movs r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0800BB8E:
	ldr r0, _0800BBDC @ =0x02002200
	ldr r1, _0800BBE0 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrh r2, [r5, #0x10]
	cmp r0, #0
	beq _0800BBC0
	movs r1, #0x1f
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _0800BBC0
	ldr r3, _0800BBE4 @ =0x02002180
	ldrh r0, [r3, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800BBC0
	subs r0, r1, #1
	movs r1, #0x1f
	ands r0, r1
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3, #2]
_0800BBC0:
	subs r0, r2, #1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x12]
	adds r0, #1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0800BBD6
	movs r0, #0
	strh r0, [r5, #0x12]
_0800BBD6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BBDC: .4byte 0x02002200
_0800BBE0: .4byte 0x0002D024
_0800BBE4: .4byte 0x02002180

	thumb_func_start FUN_0800bbe8
FUN_0800bbe8: @ 0x0800BBE8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r1, [r4, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #2
	ldr r0, _0800BC6C @ =0x0200214C
	adds r3, r1, r0
	ldr r2, [r4, #0x34]
	strh r2, [r3]
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	strh r0, [r1]
	ldr r0, _0800BC70 @ =0x087044F8
	mov r8, r0
	ldr r6, _0800BC74 @ =0x0833B200
	ldrh r0, [r4, #0x12]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _0800BC78 @ =0x08704BD8
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4, #0x12]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BC6C: .4byte 0x0200214C
_0800BC70: .4byte 0x087044F8
_0800BC74: .4byte 0x0833B200
_0800BC78: .4byte 0x08704BD8

	thumb_func_start clearBLDCLT_0800bc7c
clearBLDCLT_0800bc7c: @ 0x0800BC7C
	ldr r1, _0800BC84 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_0800BC84: .4byte 0x02002180

	thumb_func_start FUN_0800bc88
FUN_0800bc88: @ 0x0800BC88
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0800BCC2
	cmp r0, #1
	bgt _0800BC9C
	cmp r0, #0
	beq _0800BCA6
	b _0800BD16
_0800BC9C:
	cmp r0, #2
	beq _0800BCDE
	cmp r0, #3
	beq _0800BCFA
	b _0800BD16
_0800BCA6:
	ldr r0, _0800BD1C @ =0x02002200
	ldr r1, _0800BD20 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800BD16
	movs r0, #0x10
	movs r1, #1
	movs r2, #0x34
	bl loadScreenIntoBlockMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800BCC2:
	ldr r0, _0800BD1C @ =0x02002200
	ldr r1, _0800BD20 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800BD16
	movs r0, #0x10
	movs r1, #1
	movs r2, #0x35
	bl loadScreenIntoBlockMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800BCDE:
	ldr r0, _0800BD1C @ =0x02002200
	ldr r1, _0800BD20 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0800BD16
	movs r0, #0x10
	movs r1, #1
	movs r2, #0x36
	bl loadScreenIntoBlockMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800BCFA:
	ldr r0, _0800BD1C @ =0x02002200
	ldr r1, _0800BD20 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _0800BD16
	movs r0, #0x10
	movs r1, #1
	movs r2, #0x30
	bl loadScreenIntoBlockMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800BD16:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800BD1C: .4byte 0x02002200
_0800BD20: .4byte 0x0002D026

	thumb_func_start whiteOmega1_0800bd24
whiteOmega1_0800bd24: @ 0x0800BD24
	ldr r1, _0800BD30 @ =0x02002200
	ldr r2, _0800BD34 @ =0x0002D028
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0800BD30: .4byte 0x02002200
_0800BD34: .4byte 0x0002D028

	thumb_func_start FUN_0800bd38
FUN_0800bd38: @ 0x0800BD38
	asrs r0, r0, #0xc
	subs r0, #1
	asrs r1, r1, #0xc
	subs r1, #1
	ldr r3, _0800BD74 @ =0x02002200
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r3, r3, r2
	ldrh r2, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r2, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, r0
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r3
	adds r2, r2, r0
	adds r2, #0x7a
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrh r1, [r1]
	ldrh r0, [r2]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
_0800BD74: .4byte 0x02002200

	thumb_func_start FUN_0800bd78
FUN_0800bd78: @ 0x0800BD78
	push {r4, r5, r6, lr}
	sub sp, #8
	asrs r2, r0, #0xc
	subs r2, #1
	asrs r3, r1, #0xc
	subs r3, #1
	lsls r2, r2, #0x10
	asrs r6, r2, #0x10
	movs r4, #0xf0
	lsls r4, r4, #0xf
	adds r2, r2, r4
	lsls r4, r3, #0x10
	ldr r5, _0800BDCC @ =0x0000FFFF
	lsrs r2, r2, #0x10
	orrs r2, r4
	str r2, [sp]
	ldr r2, _0800BDD0 @ =0x00020002
	str r2, [sp, #4]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BDB8
	ldr r0, [sp, #4]
	ands r0, r5
	movs r1, #0xc0
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [sp, #4]
_0800BDB8:
	asrs r1, r4, #0x10
	adds r0, r6, #0
	mov r2, sp
	bl shiftTerrain
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BDCC: .4byte 0x0000FFFF
_0800BDD0: .4byte 0x00020002

	thumb_func_start FUN_0800bdd4
FUN_0800bdd4: @ 0x0800BDD4
	push {lr}
	sub sp, #8
	asrs r0, r0, #0xc
	subs r0, #1
	asrs r1, r1, #0xc
	subs r1, #1
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	movs r3, #0xf0
	lsls r3, r3, #0xe
	adds r0, r0, r3
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldr r0, _0800BE08 @ =0x00020002
	str r0, [sp, #4]
	asrs r1, r1, #0x10
	adds r0, r2, #0
	mov r2, sp
	bl shiftTerrain
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800BE08: .4byte 0x00020002
