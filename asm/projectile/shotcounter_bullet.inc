	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ShotcounterBullet_Die
ShotcounterBullet_Die: @ 0x0809CE70
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0809CEA8 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_0809CEA8: .4byte gProjectileFnTable

	thumb_func_start nop_0809ceac
nop_0809ceac: @ 0x0809CEAC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ceb0
FUN_0809ceb0: @ 0x0809CEB0
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	ands r3, r1
	cmp r3, #0
	beq _0809CEE6
	movs r1, #0
	str r1, [r2]
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	b _0809CF42
_0809CEE6:
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _0809CF10
	str r3, [r2]
	adds r0, r4, #0
	adds r0, #0x90
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x35
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
	b _0809CF42
_0809CF10:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809CF3C
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _0809CF60
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0809CF60
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809CF60
_0809CF3C:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
_0809CF42:
	bl CreateSmoke
	ldr r1, _0809CF5C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809CF92
	.align 2, 0
_0809CF5C: .4byte gProjectileFnTable
_0809CF60:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809CF6C
	cmp r0, #1
	beq _0809CF7C
	b _0809CF92
_0809CF6C:
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809CF7C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809CF92:
	pop {r4}
	pop {r0}
	bx r0


	thumb_func_start FUN_0809cf98
FUN_0809cf98:
	bx lr
	.align 2, 0
