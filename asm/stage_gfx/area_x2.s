	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initAreaX2
initAreaX2: @ 0x08011540
	push {r4, lr}
	ldr r1, _080115A4 @ =0x02002200
	ldr r2, _080115A8 @ =0x0002D030
	adds r0, r1, r2
	movs r3, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _080115AC @ =0x0002D028
	adds r0, r1, r4
	strh r2, [r0]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldr r2, _080115B0 @ =0x0002D024
	adds r0, r1, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r1, r4
	strb r3, [r0]
	ldr r0, _080115B4 @ =0x0002D02D
	adds r1, r1, r0
	strb r3, [r1]
	movs r0, #0x22
	movs r1, #0
	bl loadBlink
	movs r0, #0x23
	movs r1, #0
	bl loadBlink
	movs r0, #0x24
	movs r1, #0
	bl loadBlink
	movs r0, #0x25
	movs r1, #0
	bl loadBlink
	movs r0, #0x8f
	movs r1, #0
	bl loadBlink
	movs r0, #0x90
	movs r1, #0
	bl loadBlink
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080115A4: .4byte 0x02002200
_080115A8: .4byte 0x0002D030
_080115AC: .4byte 0x0002D028
_080115B0: .4byte 0x0002D024
_080115B4: .4byte 0x0002D02D

	thumb_func_start FUN_080115b8
FUN_080115b8: @ 0x080115B8
	push {lr}
	ldr r2, _0801164C @ =0x02002200
	ldr r0, _08011650 @ =0x0002D030
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _08011654 @ =0x0002D02A
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08011658 @ =0x000007D6
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xa
	bne _0801165C
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _0801165C
	subs r3, #2
	adds r1, r2, r3
	ldrh r2, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08011626
	movs r0, #1
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x20
	movs r1, #0
	bl loadBlink
	movs r0, #0x21
	movs r1, #0
	bl loadBlink
	movs r0, #0x26
	movs r1, #0
	bl loadBlink
	movs r0, #0x27
	movs r1, #0
	bl loadBlink
	movs r0, #0x28
	movs r1, #0
	bl loadBlink
	movs r0, #0x8e
	movs r1, #0
	bl loadBlink
_08011626:
	movs r0, #0x20
	bl FUN_08004068
	movs r0, #0x21
	bl FUN_08004068
	movs r0, #0x26
	bl FUN_08004068
	movs r0, #0x27
	bl FUN_08004068
	movs r0, #0x28
	bl FUN_08004068
	movs r0, #0x8e
	bl FUN_08004068
	b _08011696
	.align 2, 0
_0801164C: .4byte 0x02002200
_08011650: .4byte 0x0002D030
_08011654: .4byte 0x0002D02A
_08011658: .4byte 0x000007D6
_0801165C:
	ldr r0, _080116D0 @ =0x02002200
	ldr r1, _080116D4 @ =0x0002D028
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08011696
	movs r0, #1
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x20
	bl clearBlink
	movs r0, #0x21
	bl clearBlink
	movs r0, #0x26
	bl clearBlink
	movs r0, #0x27
	bl clearBlink
	movs r0, #0x28
	bl clearBlink
	movs r0, #0x8e
	bl clearBlink
_08011696:
	ldr r2, _080116D0 @ =0x02002200
	ldr r3, _080116D8 @ =0x000007D6
	adds r0, r2, r3
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xa
	bne _080116DC
	movs r0, #0xff
	ands r0, r1
	cmp r0, #2
	bne _080116DC
	ldr r1, _080116D4 @ =0x0002D028
	adds r2, r2, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080116C6
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x93
	movs r1, #0
	bl loadBlink
_080116C6:
	movs r0, #0x93
	bl FUN_08004068
	b _080116F8
	.align 2, 0
_080116D0: .4byte 0x02002200
_080116D4: .4byte 0x0002D028
_080116D8: .4byte 0x000007D6
_080116DC:
	ldr r0, _08011744 @ =0x02002200
	ldr r3, _08011748 @ =0x0002D028
	adds r2, r0, r3
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080116F8
	movs r0, #2
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x93
	bl clearBlink
_080116F8:
	ldr r0, _08011744 @ =0x02002200
	ldr r2, _0801174C @ =0x000007D6
	adds r1, r0, r2
	ldrh r2, [r1]
	lsrs r1, r2, #8
	adds r3, r0, #0
	cmp r1, #0xa
	bne _08011750
	movs r0, #0xff
	ands r0, r2
	cmp r0, #3
	bne _08011750
	ldr r0, _08011748 @ =0x0002D028
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08011734
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x91
	movs r1, #0
	bl loadBlink
	movs r0, #0x92
	movs r1, #0
	bl loadBlink
_08011734:
	movs r0, #0x91
	bl FUN_08004068
	movs r0, #0x92
	bl FUN_08004068
	b _08011770
	.align 2, 0
_08011744: .4byte 0x02002200
_08011748: .4byte 0x0002D028
_0801174C: .4byte 0x000007D6
_08011750:
	ldr r1, _08011798 @ =0x0002D028
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08011770
	movs r0, #4
	eors r0, r1
	strh r0, [r2]
	movs r0, #0x91
	bl clearBlink
	movs r0, #0x92
	bl clearBlink
_08011770:
	movs r0, #0x22
	bl FUN_08004068
	movs r0, #0x23
	bl FUN_08004068
	movs r0, #0x24
	bl FUN_08004068
	movs r0, #0x25
	bl FUN_08004068
	movs r0, #0x8f
	bl FUN_08004068
	movs r0, #0x90
	bl FUN_08004068
	pop {r0}
	bx r0
	.align 2, 0
_08011798: .4byte 0x0002D028

	thumb_func_start nop_0801179c
nop_0801179c: @ 0x0801179C
	bx lr
	.align 2, 0

	thumb_func_start exitAreaX2
exitAreaX2: @ 0x080117A0
	push {lr}
	movs r0, #0x20
	bl clearBlink
	movs r0, #0x21
	bl clearBlink
	movs r0, #0x22
	bl clearBlink
	movs r0, #0x23
	bl clearBlink
	movs r0, #0x24
	bl clearBlink
	movs r0, #0x25
	bl clearBlink
	movs r0, #0x26
	bl clearBlink
	movs r0, #0x27
	bl clearBlink
	movs r0, #0x28
	bl clearBlink
	movs r0, #0x8e
	bl clearBlink
	movs r0, #0x8f
	bl clearBlink
	movs r0, #0x90
	bl clearBlink
	movs r0, #0x91
	bl clearBlink
	movs r0, #0x92
	bl clearBlink
	movs r0, #0x93
	bl clearBlink
	pop {r0}
	bx r0

	thumb_func_start FUN_08011800
FUN_08011800: @ 0x08011800
	push {lr}
	adds r3, r0, #0
	ldrb r2, [r3, #0xe]
	cmp r2, #0
	bne _08011814
	ldr r0, _08011818 @ =0x02002180
	ldr r1, _0801181C @ =0x00002844
	strh r1, [r0]
	adds r0, r2, #1
	strb r0, [r3, #0xe]
_08011814:
	pop {r0}
	bx r0
	.align 2, 0
_08011818: .4byte 0x02002180
_0801181C: .4byte 0x00002844

	thumb_func_start FUN_08011820
FUN_08011820: @ 0x08011820
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08011838 @ =0x02002200
	ldr r1, _0801183C @ =0x0002D02A
	adds r0, r0, r1
	ldrb r3, [r0]
	cmp r3, #0x3f
	bhi _08011840
	movs r3, #0
	b _08011862
	.align 2, 0
_08011838: .4byte 0x02002200
_0801183C: .4byte 0x0002D02A
_08011840:
	cmp r3, #0x7f
	bhi _0801184C
	adds r0, r3, #0
	subs r0, #0x40
	lsls r0, r0, #0xe
	b _08011860
_0801184C:
	cmp r3, #0xbf
	bhi _08011854
	movs r3, #0x10
	b _08011862
_08011854:
	adds r1, r3, #0
	subs r1, #0xc0
	asrs r1, r1, #2
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
_08011860:
	lsrs r3, r0, #0x10
_08011862:
	ldr r2, _08011880 @ =0x02002180
	movs r1, #0x1f
	ands r1, r3
	movs r0, #0x10
	subs r0, r0, r3
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #2]
	adds r0, r4, #0
	adds r1, r5, #0
	bl variousStageFunc_080093b8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011880: .4byte 0x02002180

	thumb_func_start FUN_08011884
FUN_08011884: @ 0x08011884
	ldr r1, _0801188C @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_0801188C: .4byte 0x02002180

	thumb_func_start areaX2_08011890
areaX2_08011890: @ 0x08011890
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _080118E0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _080118EC @ =0x02002144
	adds r3, r3, r4
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	orrs r1, r2
	movs r2, #0x44
	orrs r1, r2
	strh r1, [r3]
	lsls r0, r0, #2
	adds r4, #8
	adds r0, r0, r4
	str r6, [r0]
	ldr r0, _080118F0 @ =0x085223A8
	ldr r0, [r0]
	ldr r2, _080118F4 @ =0x085223B0
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	strh r6, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080118E0:
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080118EC: .4byte 0x02002144
_080118F0: .4byte 0x085223A8
_080118F4: .4byte 0x085223B0

	thumb_func_start FUN_080118f8
FUN_080118f8: @ 0x080118F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	mov sl, r0
	cmp r0, #0
	bne _08011914
	b _08011A62
_08011914:
	ldr r2, _08011A70 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	mov r3, sl
	str r3, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08011A74 @ =0x0400001C
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _08011A78 @ =0xA6600001
	str r0, [r1]
	mov r0, r8
	ldrh r1, [r0, #0x10]
	ldr r0, [r0, #0x34]
	adds r0, r0, r1
	lsls r0, r0, #0xd
	lsrs r7, r0, #0x10
	mov r1, r8
	ldr r0, [r1, #0x38]
	ldr r2, _08011A7C @ =0xFFFFFAB0
	adds r1, r0, r2
	lsls r1, r1, #0xe
	lsrs r6, r1, #0x10
	ldr r3, _08011A80 @ =0xFFFFFBF0
	adds r0, r0, r3
	movs r1, #7
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov sb, r1
	asrs r5, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	subs r0, r5, r0
	adds r0, #0x94
	lsls r0, r0, #8
	movs r1, #0x94
	bl __divsi3
	ldr r2, _08011A84 @ =0xFFFFFF00
	adds r6, r0, r2
	movs r4, #0x9f
	adds r0, r5, #0
	adds r0, #0x9f
	cmp r0, #0x87
	ble _080119A4
	adds r3, r0, #0
	subs r0, #0x88
	movs r2, #0x9f
	lsls r2, r2, #2
	add r2, sl
	adds r1, r0, #0
	muls r1, r6, r1
_0801198A:
	asrs r0, r1, #8
	subs r0, r5, r0
	lsls r0, r0, #0x10
	orrs r0, r7
	str r0, [r2]
	subs r3, #1
	subs r1, r1, r6
	subs r2, #4
	subs r4, #1
	cmp r4, #0
	blt _080119A4
	cmp r3, #0x87
	bgt _0801198A
_080119A4:
	mov r3, r8
	ldrh r1, [r3, #0x10]
	ldr r0, [r3, #0x34]
	adds r0, r0, r1
	lsls r0, r0, #0xc
	lsrs r7, r0, #0x10
	mov r6, sb
	ldr r0, [r3, #0x38]
	ldr r1, _08011A88 @ =0xFFFFFC40
	adds r0, r0, r1
	lsls r0, r0, #0xd
	lsrs r2, r0, #0x10
	mov sb, r2
	asrs r5, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	subs r0, r5, r0
	adds r0, #0x18
	lsls r0, r0, #8
	movs r1, #0x18
	bl __divsi3
	ldr r3, _08011A84 @ =0xFFFFFF00
	adds r6, r0, r3
	cmp r4, #0
	blt _08011A08
	adds r0, r4, r5
	cmp r0, #0x75
	ble _08011A08
	adds r3, r0, #0
	adds r0, r4, #0
	subs r0, #0x76
	adds r0, r0, r5
	lsls r1, r4, #2
	add r1, sl
	adds r2, r0, #0
	muls r2, r6, r2
_080119EE:
	asrs r0, r2, #8
	subs r0, r5, r0
	lsls r0, r0, #0x10
	orrs r0, r7
	str r0, [r1]
	subs r3, #1
	subs r2, r2, r6
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08011A08
	cmp r3, #0x75
	bgt _080119EE
_08011A08:
	mov r0, r8
	ldrh r1, [r0, #0x10]
	ldr r0, [r0, #0x34]
	adds r0, r0, r1
	lsls r0, r0, #0xb
	lsrs r7, r0, #0x10
	mov r6, sb
	cmp r4, #0
	blt _08011A40
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	adds r0, r4, r2
	cmp r0, #0x6f
	ble _08011A40
	lsls r0, r4, #2
	mov r3, sl
	adds r1, r0, r3
	adds r3, r2, #0
	lsls r2, r3, #0x10
	orrs r2, r7
_08011A30:
	str r2, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	blt _08011A40
	adds r0, r4, r3
	cmp r0, #0x6f
	bgt _08011A30
_08011A40:
	mov r1, r8
	ldr r0, [r1, #0x34]
	ldr r2, _08011A8C @ =0xFFFFF100
	adds r0, r0, r2
	lsls r0, r0, #0xd
	lsrs r7, r0, #0x10
	cmp r4, #0
	blt _08011A62
	lsls r1, r6, #0x10
	orrs r1, r7
	lsls r0, r4, #2
	add r0, sl
_08011A58:
	str r1, [r0]
	subs r0, #4
	subs r4, #1
	cmp r4, #0
	bge _08011A58
_08011A62:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011A70: .4byte 0x03001590
_08011A74: .4byte 0x0400001C
_08011A78: .4byte 0xA6600001
_08011A7C: .4byte 0xFFFFFAB0
_08011A80: .4byte 0xFFFFFBF0
_08011A84: .4byte 0xFFFFFF00
_08011A88: .4byte 0xFFFFFC40
_08011A8C: .4byte 0xFFFFF100

	thumb_func_start FUN_08011a90
FUN_08011a90: @ 0x08011A90
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _08011ACC
	cmp r1, #1
	bgt _08011AA8
	cmp r1, #0
	beq _08011AB2
	b _08011B82
_08011AA8:
	cmp r1, #2
	beq _08011B26
	cmp r1, #3
	beq _08011B68
	b _08011B82
_08011AB2:
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _08011B04 @ =0x02002144
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _08011B08 @ =0x0000FFFC
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08011ACC:
	ldr r1, _08011B0C @ =0x02002200
	ldr r2, _08011B10 @ =0x0002D024
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _08011B14
	movs r0, #0x11
	movs r1, #1
	movs r2, #0x3c
	bl loadScreenIntoBlockMap
	movs r0, #0x12
	movs r1, #1
	movs r2, #0x3d
	bl loadScreenIntoBlockMap
	movs r0, #0x11
	movs r1, #2
	movs r2, #0x4c
	bl loadScreenIntoBlockMap
	movs r0, #0x12
	movs r1, #2
	movs r2, #0x4d
	bl loadScreenIntoBlockMap
	movs r0, #4
	b _08011B80
	.align 2, 0
_08011B04: .4byte 0x02002144
_08011B08: .4byte 0x0000FFFC
_08011B0C: .4byte 0x02002200
_08011B10: .4byte 0x0002D024
_08011B14:
	cmp r0, #0
	beq _08011B82
	ldr r0, _08011B60 @ =0x0002D02C
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08011B26:
	ldr r0, _08011B64 @ =0x02002200
	ldr r1, _08011B60 @ =0x0002D02C
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08011B82
	movs r0, #0x11
	movs r1, #1
	movs r2, #0x3c
	bl loadScreenIntoBlockMap
	movs r0, #0x12
	movs r1, #1
	movs r2, #0x3d
	bl loadScreenIntoBlockMap
	movs r0, #0x11
	movs r1, #2
	movs r2, #0x4c
	bl loadScreenIntoBlockMap
	movs r0, #0x12
	movs r1, #2
	movs r2, #0x4d
	bl loadScreenIntoBlockMap
	movs r0, #1
	strb r0, [r5]
	b _08011B7C
	.align 2, 0
_08011B60: .4byte 0x0002D02C
_08011B64: .4byte 0x02002200
_08011B68:
	ldr r1, _08011B88 @ =0x02002200
	ldr r2, _08011B8C @ =0x0002D024
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08011B82
	ldr r0, _08011B90 @ =0x0002D02D
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_08011B7C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
_08011B80:
	strb r0, [r4, #0xe]
_08011B82:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011B88: .4byte 0x02002200
_08011B8C: .4byte 0x0002D024
_08011B90: .4byte 0x0002D02D

	thumb_func_start FUN_08011b94
FUN_08011b94: @ 0x08011B94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08011BA4
	cmp r5, #1
	beq _08011BDC
	b _08011BFC
_08011BA4:
	ldr r1, _08011BBC @ =0x02002200
	ldr r2, _08011BC0 @ =0x0002D024
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _08011BC4
	movs r0, #0xb4
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	movs r0, #2
	b _08011BFA
	.align 2, 0
_08011BBC: .4byte 0x02002200
_08011BC0: .4byte 0x0002D024
_08011BC4:
	ldr r2, _08011C04 @ =0x0002D02D
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011BFC
	movs r0, #0xe0
	bl playSound
	strh r5, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08011BDC:
	ldrh r1, [r4, #0x10]
	adds r1, #1
	strh r1, [r4, #0x10]
	ldrh r0, [r4, #0x10]
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0xb3
	bls _08011BFC
	movs r0, #0xe0
	bl stopSound
	ldrb r0, [r4, #0xe]
	adds r0, #1
_08011BFA:
	strb r0, [r4, #0xe]
_08011BFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011C04: .4byte 0x0002D02D

	thumb_func_start FUN_08011c08
FUN_08011c08: @ 0x08011C08
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _08011C1A
	b _08011D48
_08011C1A:
	lsls r0, r0, #2
	ldr r1, _08011C24 @ =_08011C28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08011C24: .4byte _08011C28
_08011C28: @ jump table
	.4byte _08011C3C @ case 0
	.4byte _08011C62 @ case 1
	.4byte _08011CC0 @ case 2
	.4byte _08011CFC @ case 3
	.4byte _08011D38 @ case 4
_08011C3C:
	lsrs r2, r3, #4
	lsls r2, r2, #1
	ldr r0, _08011C94 @ =0x02002144
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _08011C98 @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08011C9C @ =0x02002180
	ldr r0, _08011CA0 @ =0x00003748
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r1, #2]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08011C62:
	ldr r1, _08011CA4 @ =0x02002200
	ldr r2, _08011CA8 @ =0x0002D024
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _08011CAC
	movs r1, #0
	str r1, [r5, #0x44]
	str r1, [r5, #0x48]
	movs r0, #0xf0
	str r0, [r5, #0x4c]
	ldr r0, _08011C9C @ =0x02002180
	strh r1, [r0]
	lsrs r2, r3, #4
	lsls r2, r2, #1
	ldr r0, _08011C94 @ =0x02002144
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _08011C98 @ =0x0000FFFC
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	b _08011D46
	.align 2, 0
_08011C94: .4byte 0x02002144
_08011C98: .4byte 0x0000FFFC
_08011C9C: .4byte 0x02002180
_08011CA0: .4byte 0x00003748
_08011CA4: .4byte 0x02002200
_08011CA8: .4byte 0x0002D024
_08011CAC:
	ldr r2, _08011CF0 @ =0x0002D02C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011D48
	movs r0, #0
	strh r0, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08011CC0:
	ldrh r1, [r5, #0x10]
	adds r1, #1
	strh r1, [r5, #0x10]
	ldr r4, _08011CF4 @ =0x02002180
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #0x1f
	adds r2, r1, #0
	ands r2, r0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r4, #2]
	cmp r3, #0x3f
	bls _08011D48
	ldr r0, _08011CF8 @ =0x02002200
	ldr r1, _08011CF0 @ =0x0002D02C
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	b _08011D42
	.align 2, 0
_08011CF0: .4byte 0x0002D02C
_08011CF4: .4byte 0x02002180
_08011CF8: .4byte 0x02002200
_08011CFC:
	ldr r0, _08011D24 @ =0x02002200
	ldr r2, _08011D28 @ =0x0002D02C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011D48
	ldr r1, _08011D2C @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	lsrs r2, r3, #4
	lsls r2, r2, #1
	ldr r0, _08011D30 @ =0x02002144
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _08011D34 @ =0x0000FFFC
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	b _08011D42
	.align 2, 0
_08011D24: .4byte 0x02002200
_08011D28: .4byte 0x0002D02C
_08011D2C: .4byte 0x02002180
_08011D30: .4byte 0x02002144
_08011D34: .4byte 0x0000FFFC
_08011D38:
	movs r0, #0
	str r0, [r5, #0x44]
	str r0, [r5, #0x48]
	movs r0, #0xf0
	str r0, [r5, #0x4c]
_08011D42:
	ldrb r0, [r5, #0xe]
	adds r0, #1
_08011D46:
	strb r0, [r5, #0xe]
_08011D48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08011d50
FUN_08011d50: @ 0x08011D50
	ldr r1, _08011D58 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_08011D58: .4byte 0x02002180
