	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800ea78
FUN_0800ea78: @ 0x0800EA78
	push {r4, r5, r6, r7, lr}
	ldr r1, [r0, #0x34]
	ldrh r2, [r0, #0x10]
	adds r1, r1, r2
	lsls r7, r1, #0x10
	lsrs r6, r7, #0x10
	ldr r0, [r0, #0x38]
	ldr r1, _0800EB28 @ =0xFFFFFA60
	adds r0, r0, r1
	movs r1, #0xc
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _0800EB22
	ldr r2, _0800EB2C @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800EB30 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800EB34 @ =0xA6600001
	str r0, [r1]
	movs r2, #0
	cmp r4, #0x4f
	bgt _0800EAD8
	lsls r1, r4, #0x10
	lsrs r0, r7, #0x16
	orrs r1, r0
	adds r3, r5, #0
_0800EACE:
	stm r3!, {r1}
	adds r2, #1
	adds r0, r4, r2
	cmp r0, #0x4f
	ble _0800EACE
_0800EAD8:
	adds r0, r4, r2
	cmp r0, #0x57
	bgt _0800EAF2
	lsls r1, r4, #0x10
	lsrs r0, r6, #5
	orrs r1, r0
	lsls r0, r2, #2
	adds r3, r0, r5
_0800EAE8:
	stm r3!, {r1}
	adds r2, #1
	adds r0, r4, r2
	cmp r0, #0x57
	ble _0800EAE8
_0800EAF2:
	adds r0, r4, r2
	cmp r0, #0x6f
	bgt _0800EB0C
	lsls r1, r4, #0x10
	lsrs r0, r6, #3
	orrs r1, r0
	lsls r0, r2, #2
	adds r3, r0, r5
_0800EB02:
	stm r3!, {r1}
	adds r2, #1
	adds r0, r4, r2
	cmp r0, #0x6f
	ble _0800EB02
_0800EB0C:
	cmp r2, #0x9f
	bgt _0800EB22
	lsls r1, r4, #0x10
	lsrs r0, r6, #2
	orrs r1, r0
	lsls r0, r2, #2
	adds r0, r0, r5
_0800EB1A:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _0800EB1A
_0800EB22:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800EB28: .4byte 0xFFFFFA60
_0800EB2C: .4byte gIntrManager
_0800EB30: .4byte 0x0400001C
_0800EB34: .4byte 0xA6600001

	thumb_func_start missileFactory_0800eb38
missileFactory_0800eb38: @ 0x0800EB38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	mov sb, r1
	ldr r0, [r7, #0x5c]
	lsls r5, r0, #0x10
	lsrs r0, r5, #0x10
	mov sl, r0
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	bne _0800EBA8
	lsrs r3, r5, #0x14
	lsls r2, r3, #1
	ldr r4, _0800EBC4 @ =gVideoRegBuffer+4
	adds r2, r2, r4
	mov r8, r2
	ldr r1, [r7, #0x64]
	ldr r2, _0800EBC8 @ =0x00004044
	adds r0, r2, #0
	orrs r1, r0
	mov r0, r8
	strh r1, [r0]
	lsls r3, r3, #2
	adds r4, #8
	adds r3, r3, r4
	str r6, [r3]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r6, [sp, #8]
	ldr r2, _0800EBCC @ =0x01000400
	add r0, sp, #8
	bl CpuFastSet
	ldr r1, _0800EBD0 @ =gBlendRegBuffer
	ldr r0, _0800EBD4 @ =0x00003B44
	strh r0, [r1]
	ldr r0, _0800EBD8 @ =0x00000C08
	strh r0, [r1, #2]
	ldr r0, _0800EBDC @ =gOverworld
	ldr r1, _0800EBE0 @ =0x0002D034
	adds r0, r0, r1
	str r6, [r0]
	movs r0, #2
	strh r0, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800EBA8:
	ldrb r4, [r7, #0xe]
	cmp r4, #1
	beq _0800EBB0
	b _0800EF48
_0800EBB0:
	ldrb r6, [r7, #0xf]
	cmp r6, #1
	bne _0800EBB8
	b _0800ECF8
_0800EBB8:
	cmp r6, #1
	bgt _0800EBE4
	cmp r6, #0
	beq _0800EBF4
	lsrs r5, r5, #0x14
	b _0800EEF4
	.align 2, 0
_0800EBC4: .4byte gVideoRegBuffer+4
_0800EBC8: .4byte 0x00004044
_0800EBCC: .4byte 0x01000400
_0800EBD0: .4byte gBlendRegBuffer
_0800EBD4: .4byte 0x00003B44
_0800EBD8: .4byte 0x00000C08
_0800EBDC: .4byte gOverworld
_0800EBE0: .4byte 0x0002D034
_0800EBE4:
	cmp r6, #2
	bne _0800EBEA
	b _0800ED68
_0800EBEA:
	cmp r6, #3
	bne _0800EBF0
	b _0800EE90
_0800EBF0:
	lsrs r5, r5, #0x14
	b _0800EEF4
_0800EBF4:
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	beq _0800EBFC
	b _0800EE96
_0800EBFC:
	lsrs r0, r5, #0x14
	adds r3, r0, #0
	lsls r0, r3, #2
	ldr r2, _0800EC84 @ =gVideoRegBuffer+12
	mov ip, r2
	add r0, ip
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #1
	ands r0, r1
	adds r5, r3, #0
	cmp r0, #0
	bne _0800ECA8
	ldr r6, _0800EC88 @ =gOverworld
	ldr r0, _0800EC8C @ =0x0002D034
	adds r2, r6, r0
	ldr r1, [r2]
	ldr r0, _0800EC90 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0800EC94 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	cmp r0, #0
	bne _0800ECA8
	ldr r2, _0800EC98 @ =0x0002D024
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0800ECA8
	ldr r0, _0800EC9C @ =0x085223EC
	ldr r0, [r0]
	ldr r6, _0800ECA0 @ =0x085223F4
	adds r4, r0, r6
	lsls r0, r3, #1
	mov r1, ip
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r2, r0, #3
	movs r3, #0xc0
	lsls r3, r3, #0x13
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	orrs r3, r2
	cmp r0, #0
	bne _0800EC72
	ldr r1, _0800ECA4 @ =0x06000800
	adds r3, r2, r1
_0800EC72:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r3, #0
	bl CpuFastSet
	movs r0, #2
	strh r0, [r7, #0x10]
	b _0800EDF6
	.align 2, 0
_0800EC84: .4byte gVideoRegBuffer+12
_0800EC88: .4byte gOverworld
_0800EC8C: .4byte 0x0002D034
_0800EC90: .4byte 0x000343FD
_0800EC94: .4byte 0x00269EC3
_0800EC98: .4byte 0x0002D024
_0800EC9C: .4byte 0x085223EC
_0800ECA0: .4byte 0x085223F4
_0800ECA4: .4byte 0x06000800
_0800ECA8:
	adds r2, r5, #0
	lsls r0, r2, #2
	ldr r1, _0800ECEC @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r3, #0xe0
	ands r3, r4
	cmp r3, #0
	beq _0800ECBC
	b _0800EEF4
_0800ECBC:
	lsls r0, r2, #1
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r2, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	orrs r1, r2
	cmp r0, #0
	bne _0800ECE0
	ldr r6, _0800ECF0 @ =0x06000800
	adds r1, r2, r6
_0800ECE0:
	str r3, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0800ECF4 @ =0x01000200
	bl CpuFastSet
	b _0800EEF4
	.align 2, 0
_0800ECEC: .4byte gVideoRegBuffer+12
_0800ECF0: .4byte 0x06000800
_0800ECF4: .4byte 0x01000200
_0800ECF8:
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	beq _0800ED00
	b _0800EE96
_0800ED00:
	lsrs r0, r5, #0x14
	adds r1, r0, #0
	lsls r0, r1, #2
	ldr r2, _0800ED58 @ =gVideoRegBuffer+12
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #0xe0
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	beq _0800ED18
	b _0800EEF4
_0800ED18:
	ldr r0, _0800ED5C @ =0x085223F0
	ldr r0, [r0]
	ldr r6, _0800ED60 @ =0x085223F8
	adds r4, r0, r6
	lsls r0, r1, #1
	adds r1, r2, #0
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r2, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	orrs r1, r2
	cmp r0, #0
	bne _0800ED46
	ldr r0, _0800ED64 @ =0x06000800
	adds r1, r2, r0
_0800ED46:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	bl CpuFastSet
	movs r0, #2
	strh r0, [r7, #0x10]
	b _0800EDF6
	.align 2, 0
_0800ED58: .4byte gVideoRegBuffer+12
_0800ED5C: .4byte 0x085223F0
_0800ED60: .4byte 0x085223F8
_0800ED64: .4byte 0x06000800
_0800ED68:
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	beq _0800ED70
	b _0800EE96
_0800ED70:
	lsrs r0, r5, #0x14
	adds r3, r0, #0
	lsls r0, r3, #2
	ldr r1, _0800EE00 @ =gVideoRegBuffer+12
	mov ip, r1
	add r0, ip
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #1
	ands r0, r1
	adds r5, r3, #0
	cmp r0, #0
	bne _0800EE24
	ldr r4, _0800EE04 @ =gOverworld
	ldr r0, _0800EE08 @ =0x0002D034
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r0, _0800EE0C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0800EE10 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0800EDB6
	ldr r2, _0800EE14 @ =0x0002D024
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _0800EE24
_0800EDB6:
	ldr r0, _0800EE18 @ =0x085223FC
	ldr r0, [r0]
	ldr r1, _0800EE1C @ =0x08522404
	adds r4, r0, r1
	lsls r0, r3, #1
	mov r1, ip
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r2, r0, #3
	movs r3, #0xc0
	lsls r3, r3, #0x13
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	orrs r3, r2
	cmp r0, #0
	bne _0800EDE8
	ldr r1, _0800EE20 @ =0x06000800
	adds r3, r2, r1
_0800EDE8:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r3, #0
	bl CpuFastSet
	strh r6, [r7, #0x10]
_0800EDF6:
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
	b _0800EEF4
	.align 2, 0
_0800EE00: .4byte gVideoRegBuffer+12
_0800EE04: .4byte gOverworld
_0800EE08: .4byte 0x0002D034
_0800EE0C: .4byte 0x000343FD
_0800EE10: .4byte 0x00269EC3
_0800EE14: .4byte 0x0002D024
_0800EE18: .4byte 0x085223FC
_0800EE1C: .4byte 0x08522404
_0800EE20: .4byte 0x06000800
_0800EE24:
	adds r4, r5, #0
	lsls r0, r4, #2
	ldr r1, _0800EE80 @ =gVideoRegBuffer+12
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0xe0
	ands r0, r2
	cmp r0, #0
	bne _0800EEF4
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _0800EE84 @ =0x085223F8
	cmp r2, #0
	bne _0800EE48
	subs r0, #4
_0800EE48:
	ldr r0, [r0]
	ldr r6, _0800EE88 @ =0x08522400
	adds r3, r0, r6
	cmp r2, #0
	bne _0800EE56
	subs r6, #4
	adds r3, r0, r6
_0800EE56:
	lsls r0, r4, #1
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	orrs r1, r0
	cmp r2, #0
	bne _0800EE74
	ldr r2, _0800EE8C @ =0x06000800
	adds r1, r0, r2
_0800EE74:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r3, #0
	bl CpuFastSet
	b _0800EEF4
	.align 2, 0
_0800EE80: .4byte gVideoRegBuffer+12
_0800EE84: .4byte 0x085223F8
_0800EE88: .4byte 0x08522400
_0800EE8C: .4byte 0x06000800
_0800EE90:
	ldrh r0, [r7, #0x10]
	cmp r0, #0
	beq _0800EE9E
_0800EE96:
	subs r0, #1
	strh r0, [r7, #0x10]
	lsrs r5, r5, #0x14
	b _0800EEF4
_0800EE9E:
	lsrs r0, r5, #0x14
	adds r1, r0, #0
	lsls r0, r1, #2
	ldr r2, _0800EF2C @ =gVideoRegBuffer+12
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #0xe0
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	bne _0800EEF4
	ldr r0, _0800EF30 @ =0x08522400
	ldr r0, [r0]
	ldr r6, _0800EF34 @ =0x08522408
	adds r4, r0, r6
	lsls r0, r1, #1
	adds r1, r2, #0
	subs r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r2, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	orrs r1, r2
	cmp r0, #0
	bne _0800EEE2
	ldr r0, _0800EF38 @ =0x06000800
	adds r1, r2, r0
_0800EEE2:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	bl CpuFastSet
	movs r1, #0
	movs r0, #2
	strh r0, [r7, #0x10]
	strb r1, [r7, #0xf]
_0800EEF4:
	lsls r1, r5, #2
	ldr r2, _0800EF2C @ =gVideoRegBuffer+12
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #0x13
	strh r0, [r1]
	ldr r0, _0800EF3C @ =gOverworld
	ldr r1, _0800EF40 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0800EF0E
	b _0800F296
_0800EF0E:
	subs r2, #0xc
	mov r3, sl
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r0, _0800EF44 @ =gBlendRegBuffer
	strh r1, [r0]
	strb r3, [r7, #0xf]
	movs r0, #2
	strb r0, [r7, #0xe]
	b _0800F296
	.align 2, 0
_0800EF2C: .4byte gVideoRegBuffer+12
_0800EF30: .4byte 0x08522400
_0800EF34: .4byte 0x08522408
_0800EF38: .4byte 0x06000800
_0800EF3C: .4byte gOverworld
_0800EF40: .4byte 0x0002D024
_0800EF44: .4byte gBlendRegBuffer
_0800EF48:
	cmp r4, #2
	beq _0800EF4E
	b _0800F064
_0800EF4E:
	ldrb r6, [r7, #0xf]
	mov r8, r6
	cmp r6, #0
	bne _0800EFE2
	mov r0, sb
	ldr r4, [r0, #8]
	movs r0, #0xf
	movs r1, #9
	movs r2, #0
	bl LoadChunk
	movs r0, #0x10
	movs r1, #9
	movs r2, #0
	bl LoadChunk
	movs r0, #0xf
	movs r1, #0xa
	movs r2, #0
	bl LoadChunk
	movs r0, #0x10
	movs r1, #0xa
	movs r2, #0x36
	bl LoadChunk
	ldr r3, [r4]
	adds r3, r3, r4
	ldr r5, [r4, #8]
	adds r5, r5, r4
	adds r0, r7, #0
	adds r0, #0x14
	adds r1, r7, #0
	adds r1, #0x34
	ldr r2, [r7, #0x5c]
	lsrs r2, r2, #4
	lsls r2, r2, #1
	ldr r6, _0800F04C @ =gVideoRegBuffer+4
	adds r2, r2, r6
	ldrh r4, [r2]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r4
	lsls r2, r2, #3
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r2, r2, r4
	str r5, [sp]
	ldrh r5, [r7, #0xc]
	lsls r5, r5, #2
	mov r4, sb
	adds r4, #0xc
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp, #4]
	bl ResetLayerGraphic
	ldr r0, _0800F050 @ =0x80000001
	str r0, [r7, #0x40]
	str r0, [r7, #0x3c]
	mov r1, r8
	str r1, [r7, #0x68]
	str r1, [r7, #0x6c]
	str r1, [r7, #0x70]
	str r1, [r7, #0x74]
	subs r6, #4
	mov r2, sl
	lsls r0, r2, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0800EFE2:
	ldr r1, [r7, #0x70]
	ldr r0, _0800F054 @ =0x0001DFFF
	cmp r1, r0
	bgt _0800F026
	ldr r0, [r7, #0x68]
	adds r0, #4
	str r0, [r7, #0x68]
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	ble _0800EFFA
	str r2, [r7, #0x68]
_0800EFFA:
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x70]
	cmp r1, #0xff
	ble _0800F01A
	ldr r0, [r7, #0x6c]
	adds r0, #1
	str r0, [r7, #0x6c]
	cmp r0, r2
	ble _0800F012
	str r2, [r7, #0x6c]
_0800F012:
	ldr r0, [r7, #0x74]
	ldr r1, [r7, #0x6c]
	subs r0, r0, r1
	str r0, [r7, #0x74]
_0800F01A:
	ldr r0, [r7, #0x70]
	asrs r0, r0, #8
	str r0, [r7, #0x4c]
	ldr r0, [r7, #0x74]
	asrs r0, r0, #8
	str r0, [r7, #0x50]
_0800F026:
	ldr r0, _0800F058 @ =gOverworld
	ldr r3, _0800F05C @ =0x0002D024
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0800F034
	b _0800F296
_0800F034:
	ldr r2, _0800F060 @ =gVideoRegBuffer
	mov r6, sl
	lsls r1, r6, #8
	ldrh r0, [r2]
	bics r0, r1
	movs r1, #0
	strh r0, [r2]
	strb r1, [r7, #0xf]
	movs r0, #3
	strb r0, [r7, #0xe]
	b _0800F296
	.align 2, 0
_0800F04C: .4byte gVideoRegBuffer+4
_0800F050: .4byte 0x80000001
_0800F054: .4byte 0x0001DFFF
_0800F058: .4byte gOverworld
_0800F05C: .4byte 0x0002D024
_0800F060: .4byte gVideoRegBuffer
_0800F064:
	cmp r4, #3
	beq _0800F06A
	b _0800F296
_0800F06A:
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	bne _0800F094
	ldr r2, _0800F0C4 @ =0x0833EDDC
	movs r0, #0xff
	movs r1, #0x5a
	bl ShiftMetatile
	lsrs r2, r5, #0x14
	lsls r2, r2, #1
	ldr r0, _0800F0C8 @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _0800F0CC @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0800F094:
	ldr r1, _0800F0D0 @ =gOverworld
	ldr r2, _0800F0D4 @ =0x0002D024
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _0800F0E0
	ldr r3, _0800F0D8 @ =0x0002D025
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #8
	beq _0800F0E0
	ldr r2, _0800F0DC @ =gVideoRegBuffer
	mov r6, sl
	lsls r0, r6, #8
	ldrh r1, [r2]
	orrs r0, r1
	movs r1, #0
	strh r0, [r2]
	str r1, [r7, #0x68]
	str r1, [r7, #0x6c]
	str r1, [r7, #0x70]
	str r1, [r7, #0x74]
	b _0800F13C
	.align 2, 0
_0800F0C4: .4byte 0x0833EDDC
_0800F0C8: .4byte gVideoRegBuffer+4
_0800F0CC: .4byte 0x0000FFFC
_0800F0D0: .4byte gOverworld
_0800F0D4: .4byte 0x0002D024
_0800F0D8: .4byte 0x0002D025
_0800F0DC: .4byte gVideoRegBuffer
_0800F0E0:
	ldr r1, [r7, #0x70]
	ldr r0, _0800F128 @ =0x00010FFF
	cmp r1, r0
	bgt _0800F130
	ldr r2, _0800F12C @ =gVideoRegBuffer
	mov r1, sl
	lsls r0, r1, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [r7, #0x68]
	adds r0, #4
	str r0, [r7, #0x68]
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	ble _0800F104
	str r2, [r7, #0x68]
_0800F104:
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x70]
	cmp r1, #0xff
	ble _0800F13C
	ldr r0, [r7, #0x6c]
	adds r0, #1
	str r0, [r7, #0x6c]
	cmp r0, r2
	ble _0800F11C
	str r2, [r7, #0x6c]
_0800F11C:
	ldr r0, [r7, #0x74]
	ldr r1, [r7, #0x6c]
	subs r0, r0, r1
	str r0, [r7, #0x74]
	b _0800F13C
	.align 2, 0
_0800F128: .4byte 0x00010FFF
_0800F12C: .4byte gVideoRegBuffer
_0800F130:
	ldr r2, _0800F158 @ =gVideoRegBuffer
	mov r3, sl
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_0800F13C:
	ldr r2, [r7, #0x70]
	asrs r0, r2, #8
	str r0, [r7, #0x4c]
	ldr r1, [r7, #0x74]
	asrs r0, r1, #8
	str r0, [r7, #0x50]
	ldr r3, [r7, #0x34]
	ldr r0, _0800F15C @ =0x000012BF
	cmp r3, r0
	bgt _0800F1C0
	movs r0, #0
	add r6, sp, #0x10
	mov r8, r6
	b _0800F16A
	.align 2, 0
_0800F158: .4byte gVideoRegBuffer
_0800F15C: .4byte 0x000012BF
_0800F160:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r7, #0x70]
	ldr r1, [r7, #0x74]
_0800F16A:
	ldr r5, _0800F1B0 @ =0x0833ED1C
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r4, r6, #4
	adds r0, r4, r5
	ldr r0, [r0]
	subs r0, r0, r2
	str r0, [sp, #0x10]
	adds r0, r5, #4
	adds r0, r4, r0
	ldr r0, [r0]
	subs r0, r0, r1
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _0800F1B4 @ =0xFFFF8000
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0800F1B8 @ =0x00002001
	adds r2, r5, #0
	adds r2, #8
	adds r2, r4, r2
	ldr r3, [r2]
	lsls r3, r3, #3
	ldr r2, _0800F1BC @ =0x0833ECEC
	adds r3, r3, r2
	mov r2, r8
	bl AppendHazard
	adds r5, #0xc
	adds r4, r4, r5
	ldr r0, [r4]
	cmp r0, #0
	bne _0800F160
	b _0800F296
	.align 2, 0
_0800F1B0: .4byte 0x0833ED1C
_0800F1B4: .4byte 0xFFFF8000
_0800F1B8: .4byte 0x00002001
_0800F1BC: .4byte 0x0833ECEC
_0800F1C0:
	ldr r0, _0800F1D0 @ =0x0000158F
	cmp r3, r0
	bgt _0800F234
	movs r0, #0
	add r3, sp, #0x18
	mov r8, r3
	b _0800F1DE
	.align 2, 0
_0800F1D0: .4byte 0x0000158F
_0800F1D4:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r7, #0x70]
	ldr r1, [r7, #0x74]
_0800F1DE:
	ldr r5, _0800F224 @ =0x0833ED4C
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r4, r6, #4
	adds r0, r4, r5
	ldr r0, [r0]
	subs r0, r0, r2
	str r0, [sp, #0x18]
	adds r0, r5, #4
	adds r0, r4, r0
	ldr r0, [r0]
	subs r0, r0, r1
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _0800F228 @ =0xFFFF8000
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0800F22C @ =0x00002001
	adds r2, r5, #0
	adds r2, #8
	adds r2, r4, r2
	ldr r3, [r2]
	lsls r3, r3, #3
	ldr r2, _0800F230 @ =0x0833ECEC
	adds r3, r3, r2
	mov r2, r8
	bl AppendHazard
	adds r5, #0xc
	adds r4, r4, r5
	ldr r0, [r4]
	cmp r0, #0
	bne _0800F1D4
	b _0800F296
	.align 2, 0
_0800F224: .4byte 0x0833ED4C
_0800F228: .4byte 0xFFFF8000
_0800F22C: .4byte 0x00002001
_0800F230: .4byte 0x0833ECEC
_0800F234:
	ldr r0, _0800F244 @ =0x0000185F
	cmp r3, r0
	bgt _0800F296
	movs r0, #0
	add r3, sp, #0x20
	mov r8, r3
	b _0800F252
	.align 2, 0
_0800F244: .4byte 0x0000185F
_0800F248:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r7, #0x70]
	ldr r1, [r7, #0x74]
_0800F252:
	ldr r5, _0800F2B0 @ =0x0833ED8C
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r4, r6, #4
	adds r0, r4, r5
	ldr r0, [r0]
	subs r0, r0, r2
	str r0, [sp, #0x20]
	adds r0, r5, #4
	adds r0, r4, r0
	ldr r0, [r0]
	subs r0, r0, r1
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _0800F2B4 @ =0xFFFF8000
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0800F2B8 @ =0x00002001
	adds r2, r5, #0
	adds r2, #8
	adds r2, r4, r2
	ldr r3, [r2]
	lsls r3, r3, #3
	ldr r2, _0800F2BC @ =0x0833ECEC
	adds r3, r3, r2
	mov r2, r8
	bl AppendHazard
	adds r5, #0xc
	adds r4, r4, r5
	ldr r0, [r4]
	cmp r0, #0
	bne _0800F248
_0800F296:
	ldr r1, _0800F2C0 @ =gStageRun+288
	movs r0, #1
	bl AppendQuake
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2B0: .4byte 0x0833ED8C
_0800F2B4: .4byte 0xFFFF8000
_0800F2B8: .4byte 0x00002001
_0800F2BC: .4byte 0x0833ECEC
_0800F2C0: .4byte gStageRun+288

