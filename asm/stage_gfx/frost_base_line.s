	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initIceBase
initIceBase: @ 0x08010EA4
	ldr r0, _08010EB0 @ =0x02002200
	ldr r1, _08010EB4 @ =0x0002D028
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_08010EB0: .4byte 0x02002200
_08010EB4: .4byte 0x0002D028

	thumb_func_start FUN_08010eb8
FUN_08010eb8: @ 0x08010EB8
	push {lr}
	ldr r2, _08010EF4 @ =0x02002200
	ldr r1, _08010EF8 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #9
	bne _08010F00
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	bne _08010F00
	ldr r0, _08010EFC @ =0x0002D028
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08010EEC
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x85
	movs r1, #0
	bl loadBlink
_08010EEC:
	movs r0, #0x85
	bl FUN_08004068
	b _08010F1C
	.align 2, 0
_08010EF4: .4byte 0x02002200
_08010EF8: .4byte 0x000007D4
_08010EFC: .4byte 0x0002D028
_08010F00:
	ldr r0, _08010F74 @ =0x02002200
	ldr r1, _08010F78 @ =0x0002D028
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08010F1C
	movs r0, #1
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x85
	bl clearBlink
_08010F1C:
	ldr r2, _08010F74 @ =0x02002200
	ldr r1, _08010F7C @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #9
	bne _08010F80
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _08010F80
	ldr r0, _08010F78 @ =0x0002D028
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08010F5E
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x8b
	movs r1, #0
	bl loadBlink
	movs r0, #0x8c
	movs r1, #0
	bl loadBlink
	movs r0, #0x8d
	movs r1, #0
	bl loadBlink
_08010F5E:
	movs r0, #0x8b
	bl FUN_08004068
	movs r0, #0x8c
	bl FUN_08004068
	movs r0, #0x8d
	bl FUN_08004068
	b _08010FA8
	.align 2, 0
_08010F74: .4byte 0x02002200
_08010F78: .4byte 0x0002D028
_08010F7C: .4byte 0x000007D4
_08010F80:
	ldr r0, _08010FE4 @ =0x02002200
	ldr r1, _08010FE8 @ =0x0002D028
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08010FA8
	movs r0, #2
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x8b
	bl clearBlink
	movs r0, #0x8c
	bl clearBlink
	movs r0, #0x8d
	bl clearBlink
_08010FA8:
	ldr r2, _08010FE4 @ =0x02002200
	ldr r1, _08010FEC @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #9
	bne _08010FF0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _08010FF0
	ldr r0, _08010FE8 @ =0x0002D028
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08010FDA
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x88
	movs r1, #0
	bl loadBlink
_08010FDA:
	movs r0, #0x88
	bl FUN_08004068
	b _0801100C
	.align 2, 0
_08010FE4: .4byte 0x02002200
_08010FE8: .4byte 0x0002D028
_08010FEC: .4byte 0x000007D6
_08010FF0:
	ldr r0, _08011054 @ =0x02002200
	ldr r1, _08011058 @ =0x0002D028
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801100C
	movs r0, #4
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x88
	bl clearBlink
_0801100C:
	ldr r2, _08011054 @ =0x02002200
	ldr r1, _0801105C @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #9
	bne _08011060
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _08011060
	ldr r0, _08011058 @ =0x0002D028
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08011046
	movs r0, #8
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x86
	movs r1, #0
	bl loadBlink
	movs r0, #0x87
	movs r1, #0
	bl loadBlink
_08011046:
	movs r0, #0x86
	bl FUN_08004068
	movs r0, #0x87
	bl FUN_08004068
	b _08011082
	.align 2, 0
_08011054: .4byte 0x02002200
_08011058: .4byte 0x0002D028
_0801105C: .4byte 0x000007D6
_08011060:
	ldr r0, _080110CC @ =0x02002200
	ldr r1, _080110D0 @ =0x0002D028
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08011082
	movs r0, #8
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x86
	bl clearBlink
	movs r0, #0x87
	bl clearBlink
_08011082:
	ldr r0, _080110CC @ =0x02002200
	ldr r2, _080110D4 @ =0x000007D6
	adds r1, r0, r2
	ldrh r2, [r1]
	lsrs r1, r2, #8
	adds r3, r0, #0
	cmp r1, #9
	bne _080110D8
	movs r0, #0xff
	ands r0, r2
	cmp r0, #3
	bne _080110D8
	ldr r0, _080110D0 @ =0x0002D028
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080110BE
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x89
	movs r1, #0
	bl loadBlink
	movs r0, #0x8a
	movs r1, #0
	bl loadBlink
_080110BE:
	movs r0, #0x89
	bl FUN_08004068
	movs r0, #0x8a
	bl FUN_08004068
	b _080110F8
	.align 2, 0
_080110CC: .4byte 0x02002200
_080110D0: .4byte 0x0002D028
_080110D4: .4byte 0x000007D6
_080110D8:
	ldr r1, _080110FC @ =0x0002D028
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080110F8
	movs r0, #0x10
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x89
	bl clearBlink
	movs r0, #0x8a
	bl clearBlink
_080110F8:
	pop {r0}
	bx r0
	.align 2, 0
_080110FC: .4byte 0x0002D028

	thumb_func_start FUN_08011100
FUN_08011100: @ 0x08011100
	bx lr
	.align 2, 0

	thumb_func_start FUN_08011104
FUN_08011104: @ 0x08011104
	push {lr}
	movs r0, #0x85
	bl clearBlink
	movs r0, #0x86
	bl clearBlink
	movs r0, #0x87
	bl clearBlink
	movs r0, #0x88
	bl clearBlink
	movs r0, #0x89
	bl clearBlink
	movs r0, #0x8a
	bl clearBlink
	movs r0, #0x8b
	bl clearBlink
	movs r0, #0x8c
	bl clearBlink
	movs r0, #0x8d
	bl clearBlink
	pop {r0}
	bx r0

	thumb_func_start FUN_08011140
FUN_08011140: @ 0x08011140
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801116E
	ldr r1, [r3, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #1
	ldr r0, _08011184 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08011188 @ =0x0000FFFC
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0801118C @ =0x02002180
	ldr r0, _08011190 @ =0x00003B44
	strh r0, [r1]
	ldr r0, _08011194 @ =0x00000C04
	strh r0, [r1, #2]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801116E:
	ldr r1, [r3, #0x34]
	ldr r0, _08011198 @ =0x0000151F
	cmp r1, r0
	bgt _080111A4
	ldr r0, _0801119C @ =0x02002200
	ldr r1, _080111A0 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xa
	b _080111AE
	.align 2, 0
_08011184: .4byte 0x02002144
_08011188: .4byte 0x0000FFFC
_0801118C: .4byte 0x02002180
_08011190: .4byte 0x00003B44
_08011194: .4byte 0x00000C04
_08011198: .4byte 0x0000151F
_0801119C: .4byte 0x02002200
_080111A0: .4byte 0x0002C00C
_080111A4:
	ldr r0, _080111B4 @ =0x02002200
	ldr r1, _080111B8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
_080111AE:
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080111B4: .4byte 0x02002200
_080111B8: .4byte 0x0002C00C

	thumb_func_start FUN_080111bc
FUN_080111bc: @ 0x080111BC
	ldr r1, _080111D0 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080111D4 @ =0x02002200
	ldr r1, _080111D8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	str r1, [r0]
	bx lr
	.align 2, 0
_080111D0: .4byte 0x02002180
_080111D4: .4byte 0x02002200
_080111D8: .4byte 0x0002C00C

	thumb_func_start icebase_080111dc
icebase_080111dc: @ 0x080111DC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	bne _08011248
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _08011250 @ =0x02002144
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r6, _08011254 @ =0x00008044
	adds r2, r6, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	str r4, [r0]
	ldr r0, _08011258 @ =0x0852239C
	ldr r0, [r0]
	ldr r2, _0801125C @ =0x085223A4
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
	ldr r0, _08011260 @ =0x085223A0
	ldr r0, [r0]
	ldr r1, _08011264 @ =0x085223A8
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _08011268 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08011248:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011250: .4byte 0x02002144
_08011254: .4byte 0x00008044
_08011258: .4byte 0x0852239C
_0801125C: .4byte 0x085223A4
_08011260: .4byte 0x085223A0
_08011264: .4byte 0x085223A8
_08011268: .4byte 0x06000800

	thumb_func_start FUN_0801126c
FUN_0801126c: @ 0x0801126C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r7, r0, #0
	cmp r7, #0
	bne _08011286
	b _080113B8
_08011286:
	ldr r2, _080113C4 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080113C8 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _080113CC @ =0xA6600001
	str r0, [r1]
	mov r1, sb
	ldr r0, [r1, #0x34]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sb
	ldr r0, [r1, #0x38]
	subs r0, #0xe0
	movs r1, #3
	bl __divsi3
	adds r0, #1
	movs r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x8b
	bgt _080112E4
	adds r4, r7, #0
	adds r3, r0, #0
	lsls r1, r3, #0x10
	mov r0, r8
	orrs r1, r0
_080112D6:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _080112E4
	adds r0, r3, r2
	cmp r0, #0x8b
	ble _080112D6
_080112E4:
	mov r1, sb
	ldr r0, [r1, #0x34]
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r1, #0x38]
	ldr r1, _080113D0 @ =0xFFFFFEA0
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r2, #0x9f
	bgt _08011352
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0x8f
	bgt _0801132C
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0x90
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r7
	ldr r6, _080113D4 @ =0xFFFF0000
_0801131C:
	stm r3!, {r1}
	adds r1, r1, r6
	adds r2, #1
	cmp r2, #0x9f
	bgt _08011352
	adds r0, r4, r2
	cmp r0, #0x8f
	ble _0801131C
_0801132C:
	cmp r2, #0x9f
	bgt _08011352
	asrs r1, r5, #0x10
	adds r0, r1, r2
	cmp r0, #0xe0
	bgt _08011352
	lsls r0, r2, #2
	adds r4, r0, r7
	adds r3, r1, #0
	lsls r1, r3, #0x10
	mov r0, r8
	orrs r1, r0
_08011344:
	stm r4!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	bgt _08011352
	adds r0, r3, r2
	cmp r0, #0xe0
	ble _08011344
_08011352:
	mov r0, sb
	ldr r1, [r0, #0x34]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r0, sb
	ldr r1, [r0, #0x38]
	ldr r0, _080113D8 @ =0xFFFFFE20
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r2, #0x9f
	bgt _080113B8
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r1, r3, r2
	adds r5, r0, #0
	cmp r1, #0xdf
	bgt _080113A4
	adds r4, r3, #0
	lsls r0, r2, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	adds r3, r0, r7
	ldr r6, _080113D4 @ =0xFFFF0000
_08011394:
	stm r3!, {r1}
	adds r1, r1, r6
	adds r2, #1
	cmp r2, #0x9f
	bgt _080113B8
	adds r0, r4, r2
	cmp r0, #0xdf
	ble _08011394
_080113A4:
	cmp r2, #0x9f
	bgt _080113B8
	mov r1, r8
	orrs r1, r5
	lsls r0, r2, #2
	adds r0, r0, r7
_080113B0:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _080113B0
_080113B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080113C4: .4byte 0x03001590
_080113C8: .4byte 0x0400001C
_080113CC: .4byte 0xA6600001
_080113D0: .4byte 0xFFFFFEA0
_080113D4: .4byte 0xFFFF0000
_080113D8: .4byte 0xFFFFFE20

	thumb_func_start FUN_080113dc
FUN_080113dc: @ 0x080113DC
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	bne _080113F2
	movs r0, #0x80
	str r0, [r2, #0x44]
	adds r0, #0x80
	str r0, [r2, #0x48]
	adds r0, r1, #1
	strb r0, [r2, #0xe]
_080113F2:
	ldr r1, [r2, #0x34]
	ldr r0, _08011400 @ =0x00001C1F
	cmp r1, r0
	bgt _08011408
	ldr r0, _08011404 @ =0x00000CA8
	b _0801140A
	.align 2, 0
_08011400: .4byte 0x00001C1F
_08011404: .4byte 0x00000CA8
_08011408:
	ldr r0, _08011410 @ =0x00000E88
_0801140A:
	str r0, [r2, #0x4c]
	pop {r0}
	bx r0
	.align 2, 0
_08011410: .4byte 0x00000E88

	thumb_func_start FUN_08011414
FUN_08011414: @ 0x08011414
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	adds r1, r3, #0
	cmp r1, #0
	bne _0801142E
	movs r0, #0x40
	str r0, [r2, #0x44]
	adds r0, #0xc0
	str r0, [r2, #0x48]
	strh r1, [r2, #0x10]
	adds r0, r3, #1
	strb r0, [r2, #0xe]
_0801142E:
	ldr r1, [r2, #0x34]
	ldr r0, _0801143C @ =0x00001C1F
	cmp r1, r0
	bgt _08011444
	ldr r0, _08011440 @ =0x000012FC
	b _08011446
	.align 2, 0
_0801143C: .4byte 0x00001C1F
_08011440: .4byte 0x000012FC
_08011444:
	ldr r0, _08011460 @ =0x000015CC
_08011446:
	str r0, [r2, #0x4c]
	ldrh r0, [r2, #0x10]
	adds r0, #1
	strh r0, [r2, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0801145A
	movs r0, #0
	strh r0, [r2, #0x10]
_0801145A:
	pop {r0}
	bx r0
	.align 2, 0
_08011460: .4byte 0x000015CC

	thumb_func_start FUN_08011464
FUN_08011464: @ 0x08011464
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	mov r8, r1
	ldr r6, _080114C8 @ =0x087044F8
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _080114CC @ =0x08704A20
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	adds r0, r4, #0
	mov r1, r8
	bl variousStageFunc_080093b8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080114C8: .4byte 0x087044F8
_080114CC: .4byte 0x08704A20

	thumb_func_start icebase_080114d0
icebase_080114d0: @ 0x080114D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08011528
	ldr r1, [r5, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r4, r1, #1
	ldr r3, _08011530 @ =0x02002144
	adds r4, r4, r3
	ldr r0, [r5, #0x64]
	movs r2, #0x45
	orrs r0, r2
	strh r0, [r4]
	lsls r1, r1, #2
	adds r0, r3, #0
	adds r0, #8
	adds r1, r1, r0
	str r6, [r1]
	subs r3, #4
	ldrh r1, [r3]
	ldr r0, _08011534 @ =0x0000DBFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _08011538 @ =0x085223A4
	ldr r0, [r0]
	ldr r1, _0801153C @ =0x085223AC
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
_08011528:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011530: .4byte 0x02002144
_08011534: .4byte 0x0000DBFF
_08011538: .4byte 0x085223A4
_0801153C: .4byte 0x085223AC
