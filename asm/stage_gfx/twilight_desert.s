	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initTwilightDesert
initTwilightDesert: @ 0x0800F8A8
	push {lr}
	ldr r0, _0800F8D0 @ =0x02002200
	ldr r2, _0800F8D4 @ =0x0002D02C
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r1, _0800F8D8 @ =0x0002D029
	adds r0, r0, r1
	strb r2, [r0]
	movs r0, #0x83
	movs r1, #0
	bl loadBlink
	movs r0, #0x84
	movs r1, #0
	bl loadBlink
	pop {r0}
	bx r0
	.align 2, 0
_0800F8D0: .4byte 0x02002200
_0800F8D4: .4byte 0x0002D02C
_0800F8D8: .4byte 0x0002D029

	thumb_func_start FUN_0800f8dc
FUN_0800f8dc: @ 0x0800F8DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800F980 @ =0x02002200
	ldr r1, _0800F984 @ =0x0002D02C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F924
	ldr r0, _0800F988 @ =0x0202FDC0
	ldrb r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800F90C
	movs r4, #0x81
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _0800F90C
	adds r0, r4, #0
	bl playSound
_0800F90C:
	ldr r0, _0800F980 @ =0x02002200
	ldr r1, _0800F984 @ =0x0002D02C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F924
	ldr r0, _0800F988 @ =0x0202FDC0
	ldrb r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800F938
_0800F924:
	movs r4, #0x81
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _0800F938
	adds r0, r4, #0
	bl stopSound
_0800F938:
	ldr r2, [r5]
	movs r0, #0xff
	lsls r0, r0, #0xd
	cmp r2, r0
	bgt _0800F9A8
	ldr r0, _0800F98C @ =0xFFF86000
	adds r1, r2, r0
	movs r0, #0xf6
	lsls r0, r0, #0xb
	cmp r1, r0
	bls _0800F966
	ldr r0, _0800F990 @ =0xFFF01000
	adds r1, r2, r0
	movs r0, #0xbc
	lsls r0, r0, #0xa
	cmp r1, r0
	bls _0800F966
	ldr r0, _0800F994 @ =0xFFE7B000
	adds r1, r2, r0
	movs r0, #0xb8
	lsls r0, r0, #0xa
	cmp r1, r0
	bhi _0800F998
_0800F966:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800F976
	movs r0, #0xc6
	bl playSound
_0800F976:
	movs r0, #0xc6
	bl sound_0800465c
	b _0800F9A8
	.align 2, 0
_0800F980: .4byte 0x02002200
_0800F984: .4byte 0x0002D02C
_0800F988: .4byte 0x0202FDC0
_0800F98C: .4byte 0xFFF86000
_0800F990: .4byte 0xFFF01000
_0800F994: .4byte 0xFFE7B000
_0800F998:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	beq _0800F9A8
	movs r0, #0xc6
	bl stopSound
_0800F9A8:
	movs r0, #0x83
	bl FUN_08004068
	movs r0, #0x84
	bl FUN_08004068
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0800f9bc
nop_0800f9bc: @ 0x0800F9BC
	bx lr
	.align 2, 0

	thumb_func_start exitTwilightDesert
exitTwilightDesert: @ 0x0800F9C0
	push {lr}
	movs r0, #0x83
	bl clearBlink
	movs r0, #0x84
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start desert_0800f9d4
desert_0800f9d4: @ 0x0800F9D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _0800FA22
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r3, r0, #1
	ldr r4, _0800FA28 @ =0x02002144
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
	ldr r0, _0800FA2C @ =0x08522394
	ldr r0, [r0]
	ldr r2, _0800FA30 @ =0x0852239C
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
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0800FA22:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800FA28: .4byte 0x02002144
_0800FA2C: .4byte 0x08522394
_0800FA30: .4byte 0x0852239C

	thumb_func_start FUN_0800fa34
FUN_0800fa34: @ 0x0800FA34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _0800FA4C
	b _0800FB68
_0800FA4C:
	ldr r2, _0800FB74 @ =0x03001590
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
_0800FB74: .4byte 0x03001590
_0800FB78: .4byte 0x0400001C
_0800FB7C: .4byte 0xA6600001
_0800FB80: .4byte 0xFFFF0000
_0800FB84: .4byte 0xFFFFFEC0

	thumb_func_start desert_0800fb88
desert_0800fb88: @ 0x0800FB88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x24
	bls _0800FB94
	b _0800FF84
_0800FB94:
	lsls r0, r0, #2
	ldr r1, _0800FBA0 @ =_0800FBA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800FBA0: .4byte _0800FBA4
_0800FBA4: @ jump table
	.4byte _0800FC38 @ case 0
	.4byte _0800FC70 @ case 1
	.4byte _0800FC88 @ case 2
	.4byte _0800FCE0 @ case 3
	.4byte _0800FD0C @ case 4
	.4byte _0800FCE0 @ case 5
	.4byte _0800FD0C @ case 6
	.4byte _0800FD34 @ case 7
	.4byte _0800FD84 @ case 8
	.4byte _0800FCE0 @ case 9
	.4byte _0800FD0C @ case 10
	.4byte _0800FCE0 @ case 11
	.4byte _0800FD0C @ case 12
	.4byte _0800FDAC @ case 13
	.4byte _0800FCE0 @ case 14
	.4byte _0800FD0C @ case 15
	.4byte _0800FCE0 @ case 16
	.4byte _0800FD0C @ case 17
	.4byte _0800FDE0 @ case 18
	.4byte _0800FE30 @ case 19
	.4byte _0800FCE0 @ case 20
	.4byte _0800FD0C @ case 21
	.4byte _0800FCE0 @ case 22
	.4byte _0800FD0C @ case 23
	.4byte _0800FE58 @ case 24
	.4byte _0800FCE0 @ case 25
	.4byte _0800FD0C @ case 26
	.4byte _0800FCE0 @ case 27
	.4byte _0800FD0C @ case 28
	.4byte _0800FE8C @ case 29
	.4byte _0800FED8 @ case 30
	.4byte _0800FCE0 @ case 31
	.4byte _0800FD0C @ case 32
	.4byte _0800FCE0 @ case 33
	.4byte _0800FD0C @ case 34
	.4byte _0800FF18 @ case 35
	.4byte _0800FF3E @ case 36
_0800FC38:
	ldr r1, _0800FC5C @ =0x02002200
	ldr r2, _0800FC60 @ =0x0002D028
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0800FC64 @ =0x0002D029
	adds r0, r1, r3
	strb r2, [r0]
	ldr r5, _0800FC68 @ =0x0002D02A
	adds r1, r1, r5
	strb r2, [r1]
	ldr r1, _0800FC6C @ =0x02002180
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r1, #2]
	strh r2, [r4, #0x10]
	movs r0, #2
	b _0800FF82
	.align 2, 0
_0800FC5C: .4byte 0x02002200
_0800FC60: .4byte 0x0002D028
_0800FC64: .4byte 0x0002D029
_0800FC68: .4byte 0x0002D02A
_0800FC6C: .4byte 0x02002180
_0800FC70:
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x26
	bl loadScreenIntoBlockMap
	ldr r0, _0800FCA0 @ =0x02002200
	ldr r1, _0800FCA4 @ =0x0002D02A
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	strh r1, [r4, #0x10]
	strh r1, [r4, #0x12]
_0800FC88:
	ldr r2, _0800FCA0 @ =0x02002200
	ldr r3, _0800FCA8 @ =0x0002D028
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800FCAC
	ldrb r0, [r4, #0xe]
	movs r1, #3
	cmp r0, #1
	bne _0800FCCA
	movs r1, #7
	b _0800FCCA
	.align 2, 0
_0800FCA0: .4byte 0x02002200
_0800FCA4: .4byte 0x0002D02A
_0800FCA8: .4byte 0x0002D028
_0800FCAC:
	cmp r0, #2
	bne _0800FCBC
	ldrb r0, [r4, #0xe]
	movs r1, #0xe
	cmp r0, #1
	bne _0800FCCA
	movs r1, #0x12
	b _0800FCCA
_0800FCBC:
	cmp r0, #3
	bne _0800FCCE
	ldrb r0, [r4, #0xe]
	movs r1, #0x19
	cmp r0, #1
	bne _0800FCCA
	movs r1, #0x1d
_0800FCCA:
	strb r1, [r4, #0xe]
	b _0800FF84
_0800FCCE:
	movs r0, #0
	movs r1, #2
	strb r1, [r4, #0xe]
	ldr r5, _0800FCDC @ =0x0002D029
	adds r1, r2, r5
	strb r0, [r1]
	b _0800FF84
	.align 2, 0
_0800FCDC: .4byte 0x0002D029
_0800FCE0:
	ldrh r1, [r4, #0x12]
	adds r1, #1
	strh r1, [r4, #0x12]
	ldr r3, _0800FD08 @ =0x02002180
	movs r0, #0x1f
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #5
	adds r2, r5, #0
	orrs r0, r2
	strh r0, [r3, #2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	beq _0800FD00
	b _0800FF84
_0800FD00:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD08: .4byte 0x02002180
_0800FD0C:
	ldrh r1, [r4, #0x12]
	subs r1, #1
	strh r1, [r4, #0x12]
	ldr r3, _0800FD30 @ =0x02002180
	movs r0, #0x1f
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #5
	adds r2, r5, #0
	orrs r0, r2
	strh r0, [r3, #2]
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _0800FD2A
	b _0800FF84
_0800FD2A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD30: .4byte 0x02002180
_0800FD34:
	ldrh r2, [r4, #0x10]
	lsrs r2, r2, #2
	adds r2, #0x43
	movs r0, #0x24
	movs r1, #3
	bl loadScreenIntoBlockMap
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	ldr r1, _0800FD74 @ =0x0202FE60
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r1, _0800FD78 @ =0x00008003
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	beq _0800FD5E
	b _0800FF84
_0800FD5E:
	ldr r0, _0800FD7C @ =0x02002200
	ldr r5, _0800FD80 @ =0x0002D02A
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD74: .4byte 0x0202FE60
_0800FD78: .4byte 0x00008003
_0800FD7C: .4byte 0x02002200
_0800FD80: .4byte 0x0002D02A
_0800FD84:
	ldr r1, _0800FD98 @ =0x02002200
	ldr r2, _0800FD9C @ =0x0002D028
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800FDA0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FD98: .4byte 0x02002200
_0800FD9C: .4byte 0x0002D028
_0800FDA0:
	ldr r3, _0800FDA8 @ =0x0002D029
	adds r1, r1, r3
	b _0800FF0C
	.align 2, 0
_0800FDA8: .4byte 0x0002D029
_0800FDAC:
	ldrh r2, [r4, #0x10]
	subs r2, #1
	strh r2, [r4, #0x10]
	ldr r0, _0800FDD8 @ =0x0202FE60
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r5, r0, r1
	ldr r0, _0800FDDC @ =0x00008003
	strh r0, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	adds r2, #0x43
	movs r0, #0x24
	movs r1, #3
	bl loadScreenIntoBlockMap
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq _0800FDD4
	b _0800FF84
_0800FDD4:
	strh r0, [r5]
	b _0800FF80
	.align 2, 0
_0800FDD8: .4byte 0x0202FE60
_0800FDDC: .4byte 0x00008003
_0800FDE0:
	ldrh r2, [r4, #0x10]
	lsrs r2, r2, #2
	adds r2, #0x48
	movs r0, #0x24
	movs r1, #3
	bl loadScreenIntoBlockMap
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	ldr r1, _0800FE20 @ =0x0202FE60
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r1, _0800FE24 @ =0x00008003
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	beq _0800FE0A
	b _0800FF84
_0800FE0A:
	ldr r0, _0800FE28 @ =0x02002200
	ldr r5, _0800FE2C @ =0x0002D02A
	adds r0, r0, r5
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FE20: .4byte 0x0202FE60
_0800FE24: .4byte 0x00008003
_0800FE28: .4byte 0x02002200
_0800FE2C: .4byte 0x0002D02A
_0800FE30:
	ldr r1, _0800FE44 @ =0x02002200
	ldr r2, _0800FE48 @ =0x0002D028
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0800FE4C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FE44: .4byte 0x02002200
_0800FE48: .4byte 0x0002D028
_0800FE4C:
	ldr r3, _0800FE54 @ =0x0002D029
	adds r1, r1, r3
	b _0800FF0C
	.align 2, 0
_0800FE54: .4byte 0x0002D029
_0800FE58:
	ldrh r2, [r4, #0x10]
	subs r2, #1
	strh r2, [r4, #0x10]
	ldr r0, _0800FE84 @ =0x0202FE60
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r5, r0, r1
	ldr r0, _0800FE88 @ =0x00008003
	strh r0, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	adds r2, #0x48
	movs r0, #0x24
	movs r1, #3
	bl loadScreenIntoBlockMap
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq _0800FE80
	b _0800FF84
_0800FE80:
	strh r0, [r5]
	b _0800FF80
	.align 2, 0
_0800FE84: .4byte 0x0202FE60
_0800FE88: .4byte 0x00008003
_0800FE8C:
	ldr r0, _0800FECC @ =0x02002200
	ldr r2, _0800FED0 @ =0x0002D02A
	adds r3, r0, r2
	movs r0, #3
	strb r0, [r3]
	ldrh r1, [r4, #0x10]
	adds r1, #1
	strh r1, [r4, #0x10]
	ldr r6, _0800FED4 @ =0x02002180
	movs r2, #0x1f
	ands r2, r1
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r6, #2]
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x10
	bne _0800FF84
	movs r0, #4
	strb r0, [r3]
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x4c
	bl loadScreenIntoBlockMap
	strh r5, [r6, #2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FECC: .4byte 0x02002200
_0800FED0: .4byte 0x0002D02A
_0800FED4: .4byte 0x02002180
_0800FED8:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FEE8
	movs r0, #0xc6
	bl playSound
_0800FEE8:
	movs r0, #0xc6
	bl sound_0800465c
	ldr r1, _0800FF00 @ =0x02002200
	ldr r3, _0800FF04 @ =0x0002D028
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #3
	beq _0800FF08
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0800FF82
	.align 2, 0
_0800FF00: .4byte 0x02002200
_0800FF04: .4byte 0x0002D028
_0800FF08:
	ldr r5, _0800FF14 @ =0x0002D029
	adds r1, r1, r5
_0800FF0C:
	movs r0, #0
	strb r0, [r1]
	b _0800FF84
	.align 2, 0
_0800FF14: .4byte 0x0002D029
_0800FF18:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FF28
	movs r0, #0xc6
	bl playSound
_0800FF28:
	movs r0, #0xc6
	bl sound_0800465c
	movs r0, #0x24
	movs r1, #3
	movs r2, #0x26
	bl loadScreenIntoBlockMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800FF3E:
	movs r0, #0xc6
	bl isSoundPlaying
	cmp r0, #0
	bne _0800FF4E
	movs r0, #0xc6
	bl playSound
_0800FF4E:
	movs r0, #0xc6
	bl sound_0800465c
	ldr r0, _0800FF8C @ =0x02002200
	ldr r1, _0800FF90 @ =0x0002D02A
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldrh r1, [r4, #0x10]
	subs r1, #1
	strh r1, [r4, #0x10]
	ldr r3, _0800FF94 @ =0x02002180
	movs r2, #0x1f
	ands r2, r1
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r2, r0
	strh r2, [r3, #2]
	lsls r1, r1, #0x10
	cmp r1, #0
	bne _0800FF84
	movs r0, #0xc6
	bl stopSound
_0800FF80:
	movs r0, #1
_0800FF82:
	strb r0, [r4, #0xe]
_0800FF84:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800FF8C: .4byte 0x02002200
_0800FF90: .4byte 0x0002D02A
_0800FF94: .4byte 0x02002180

	thumb_func_start desert_0800ff98
desert_0800ff98: @ 0x0800FF98
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r3, [r6, #0xe]
	cmp r3, #0
	bne _0801001E
	ldr r4, [r6, #0x5c]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x14
	lsls r2, r4, #1
	ldr r5, _08010024 @ =0x02002144
	adds r2, r2, r5
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x64]
	orrs r1, r0
	movs r0, #0x44
	orrs r1, r0
	strh r1, [r2]
	lsls r4, r4, #2
	adds r0, r5, #0
	adds r0, #8
	adds r0, r4, r0
	str r3, [r0]
	ldr r0, _08010028 @ =0x08522398
	ldr r0, [r0]
	ldr r2, _0801002C @ =0x085223A0
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
	ldr r1, _08010030 @ =0x02002180
	ldr r0, _08010034 @ =0x00003D42
	strh r0, [r1]
	ldr r2, _08010038 @ =0x02002190
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xff
	strb r0, [r2, #0xd]
	ldrb r1, [r2, #0xe]
	movs r0, #0xc
	orrs r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xe]
	movs r0, #0xff
	strh r0, [r2, #6]
	adds r5, #0xa
	adds r4, r4, r5
	ldr r1, _0801003C @ =0x0000FF80
	adds r0, r1, #0
	strh r0, [r4]
	ldr r0, _08010040 @ =0x000080A0
	strh r0, [r2, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0801001E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010024: .4byte 0x02002144
_08010028: .4byte 0x08522398
_0801002C: .4byte 0x085223A0
_08010030: .4byte 0x02002180
_08010034: .4byte 0x00003D42
_08010038: .4byte 0x02002190
_0801003C: .4byte 0x0000FF80
_08010040: .4byte 0x000080A0

	thumb_func_start FUN_08010044
FUN_08010044: @ 0x08010044
	push {r4, r5, r6, r7, lr}
	ldr r1, [r0, #0x5c]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r7, #0x20
	ldr r0, [r0, #0x38]
	ldr r2, _08010094 @ =0xFFFFFE20
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsrs r1, r1, #0x14
	lsls r4, r1, #2
	ldr r2, _08010098 @ =0x0200214C
	adds r3, r4, r2
	movs r0, #0
	strh r0, [r3]
	adds r0, r2, #2
	adds r4, r4, r0
	strh r5, [r4]
	lsls r1, r1, #1
	subs r2, #8
	adds r2, r1, r2
	ldrh r1, [r2]
	ldr r3, _0801009C @ =0x0000FFFC
	adds r0, r3, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080100A0 @ =0x02002200
	ldr r1, _080100A4 @ =0x0002D02A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080100A8
	ldrh r0, [r4]
	subs r0, #0x80
	strh r0, [r4]
	b _080100D8
	.align 2, 0
_08010094: .4byte 0xFFFFFE20
_08010098: .4byte 0x0200214C
_0801009C: .4byte 0x0000FFFC
_080100A0: .4byte 0x02002200
_080100A4: .4byte 0x0002D02A
_080100A8:
	cmp r0, #1
	bne _080100B6
	ldrh r0, [r4]
	subs r0, #0x40
	strh r0, [r4]
	movs r7, #0x40
	b _080100D8
_080100B6:
	cmp r0, #2
	bne _080100C2
	ldrh r0, [r4]
	subs r0, #0x20
	strh r0, [r4]
	b _080100D8
_080100C2:
	cmp r0, #4
	bne _080100D8
	ldrh r0, [r4]
	adds r0, #0x20
	strh r0, [r4]
	ldrh r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
_080100D8:
	movs r3, #0xa0
	subs r1, r3, r7
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x9f
	ble _080100FC
	ldr r2, _080100F8 @ =0x02002140
	lsls r1, r6, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	b _08010110
	.align 2, 0
_080100F8: .4byte 0x02002140
_080100FC:
	ldr r2, _08010118 @ =0x02002140
	lsls r0, r6, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0801011C @ =0x02002190
	lsls r0, r5, #0x10
	asrs r0, r0, #8
	orrs r0, r3
	strh r0, [r1, #0xa]
_08010110:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010118: .4byte 0x02002140
_0801011C: .4byte 0x02002190

	thumb_func_start FUN_08010120
FUN_08010120: @ 0x08010120
	ldr r1, _0801013C @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08010140 @ =0x02002190
	ldrh r2, [r1]
	ldr r0, _08010144 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
_0801013C: .4byte 0x02002180
_08010140: .4byte 0x02002190
_08010144: .4byte 0x0000BFFF

	thumb_func_start FUN_08010148
FUN_08010148: @ 0x08010148
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801017A
	ldr r1, [r3, #0x5c]
	lsls r1, r1, #0x10
	movs r0, #0xe0
	str r0, [r3, #0x44]
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [r3, #0x4c]
	lsrs r1, r1, #0x14
	lsls r1, r1, #1
	ldr r0, _08010180 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08010184 @ =0x0000FFFC
	ands r0, r2
	movs r2, #3
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801017A:
	pop {r0}
	bx r0
	.align 2, 0
_08010180: .4byte 0x02002144
_08010184: .4byte 0x0000FFFC

	thumb_func_start FUN_08010188
FUN_08010188: @ 0x08010188
	ldr r1, _0801019C @ =0x02002200
	ldr r3, _080101A0 @ =0x0002D028
	adds r2, r1, r3
	strb r0, [r2]
	ldr r0, _080101A4 @ =0x0002D029
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0801019C: .4byte 0x02002200
_080101A0: .4byte 0x0002D028
_080101A4: .4byte 0x0002D029

	thumb_func_start FUN_080101a8
FUN_080101a8: @ 0x080101A8
	ldr r0, _080101B4 @ =0x02002200
	ldr r1, _080101B8 @ =0x0002D029
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080101B4: .4byte 0x02002200
_080101B8: .4byte 0x0002D029
