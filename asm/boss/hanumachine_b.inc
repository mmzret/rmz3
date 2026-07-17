	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Hanumachine_Die
Hanumachine_Die: @ 0x0805BB4C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0805BC20
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0805BBCA
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0805BBA4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r3, [r0]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	ldr r1, _0805BBA8 @ =0x0000B503
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805BBAC
	movs r0, #0x40
	str r0, [r4, #0x5c]
	subs r0, #0x41
	b _0805BBB4
	.align 2, 0
_0805BBA4: .4byte 0xFFFFF000
_0805BBA8: .4byte 0x0000B503
_0805BBAC:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #1
_0805BBB4:
	str r0, [r4, #0x64]
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	bl CreateEnemy50
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	b _0805BBDC
_0805BBCA:
	ldr r1, _0805BC38 @ =0x0000B50F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xf]
	movs r0, #0x40
	strb r0, [r4, #0x12]
_0805BBDC:
	movs r0, #0x4e
	bl PlaySound
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r3, _0805BC3C @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805BC1A
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805BC1A
	ldr r0, _0805BC40 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805BC1A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805BC20:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _0805BC62
	cmp r0, #1
	bgt _0805BC44
	cmp r0, #0
	beq _0805BC4E
	b _0805BCD4
	.align 2, 0
_0805BC38: .4byte 0x0000B50F
_0805BC3C: .4byte gStageRun
_0805BC40: .4byte 0x0000FFFE
_0805BC44:
	cmp r0, #2
	beq _0805BC9C
	cmp r0, #3
	beq _0805BCB8
	b _0805BCD4
_0805BC4E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	cmp r1, #0
	bne _0805BCD4
	b _0805BC90
_0805BC62:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805BCD4
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0805BC7A
	movs r0, #0xc0
	lsls r0, r0, #4
	b _0805BC7E
_0805BC7A:
	movs r0, #0xa8
	lsls r0, r0, #5
_0805BC7E:
	str r0, [sp, #8]
	ldr r1, _0805BC98 @ =0xFFFFEE00
	add r0, sp, #8
	str r1, [r0, #4]
	adds r1, r0, #0
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
_0805BC90:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _0805BCD4
	.align 2, 0
_0805BC98: .4byte 0xFFFFEE00
_0805BC9C:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0805BCD4
	ldr r2, _0805BCB4 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _0805BCCE
	.align 2, 0
_0805BCB4: .4byte gStageRun
_0805BCB8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805BCD4
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
_0805BCCE:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0805BCD4:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

