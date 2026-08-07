	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803dc34
FUN_0803dc34: @ 0x0803DC34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _0803DC40
	b _0803DE4A
_0803DC40:
	lsls r0, r0, #2
	ldr r1, _0803DC4C @ =_0803DC50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803DC4C: .4byte _0803DC50
_0803DC50: @ jump table
	.4byte _0803DC70 @ case 0
	.4byte _0803DC9E @ case 1
	.4byte _0803DCDE @ case 2
	.4byte _0803DD7C @ case 3
	.4byte _0803DDB4 @ case 4
	.4byte _0803DDDA @ case 5
	.4byte _0803DDF8 @ case 6
	.4byte _0803DE0E @ case 7
_0803DC70:
	ldr r1, _0803DCC0 @ =0x0000A00C
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x78
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xc8
	strb r1, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DC9E:
	ldrb r1, [r5, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DCB2
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0803d454
_0803DCB2:
	ldrb r0, [r5, #0x12]
	adds r1, r0, #0
	cmp r1, #0
	beq _0803DCC4
	subs r0, #1
	strb r0, [r5, #0x12]
	b _0803DCD2
	.align 2, 0
_0803DCC0: .4byte 0x0000A00C
_0803DCC4:
	adds r0, r5, #0
	adds r0, #0xc4
	str r1, [r0]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DCD2:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	b _0803DE4A
_0803DCDE:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803DD30 @ =0x083619C8
	bl SetDDP
	ldrb r0, [r5, #0xa]
	movs r2, #1
	movs r6, #0
	orrs r0, r2
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0xbe
	ldrb r0, [r4]
	ldrb r1, [r5, #0x13]
	eors r0, r1
	ands r0, r2
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4]
	ldrb r0, [r5, #0x13]
	eors r1, r0
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	ands r1, r2
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0803DD34
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0803DD3A
	.align 2, 0
_0803DD30: .4byte 0x083619C8
_0803DD34:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803DD3A:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldrb r0, [r4]
	ldrb r1, [r5, #0x13]
	eors r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	ldrb r1, [r5, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xd
	subs r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r1, #0
	lsls r0, r0, #9
	ldr r1, _0803DD98 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DD7C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r1, r0, r1
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0803DD9C
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r1, r0
	ble _0803DDF0
	b _0803DDAA
	.align 2, 0
_0803DD98: .4byte 0xFFFFFF00
_0803DD9C:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _0803DDB0 @ =0xFFFF6000
	adds r0, r0, r2
	cmp r1, r0
	bge _0803DDF0
_0803DDAA:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0803DDEE
	.align 2, 0
_0803DDB0: .4byte 0xFFFF6000
_0803DDB4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0803DDCC @ =gMegamilpaCoreHitbox
	bl SetDDP
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0803DDD0
	ldrb r0, [r5, #0xe]
	adds r0, #2
	strb r0, [r5, #0xe]
	b _0803DE4A
	.align 2, 0
_0803DDCC: .4byte gMegamilpaCoreHitbox
_0803DDD0:
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DDDA:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0803DDE6
	subs r0, #1
	strb r0, [r5, #0x12]
	b _0803DDF0
_0803DDE6:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	movs r0, #2
_0803DDEE:
	strb r0, [r5, #0xe]
_0803DDF0:
	adds r0, r5, #0
	bl FUN_0803d600
	b _0803DE4A
_0803DDF8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0xc4
	movs r0, #0x78
	str r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803DE0E:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r4, [r0]
	adds r6, r0, #0
	cmp r4, #0
	beq _0803DE20
	subs r0, r4, #1
	str r0, [r6]
	b _0803DE2C
_0803DE20:
	ldr r0, _0803DE50 @ =0x0000010D
	bl StopSound
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_0803DE2C:
	ldr r0, [r6]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803DE40
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0803d454
_0803DE40:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
_0803DE4A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DE50: .4byte 0x0000010D
