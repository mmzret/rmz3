	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile37_Init
Projectile37_Init: @ 0x080ADB24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0x11]
	cmp r7, #0
	bne _080ADB7C
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080ADB74 @ =0x0836C944
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080ADB78 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _080ADBC4
	.align 2, 0
_080ADB74: .4byte 0x0836C944
_080ADB78: .4byte gProjectileFnTable
_080ADB7C:
	cmp r7, #1
	bne _080ADBC4
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
	ldr r1, _080ADBD4 @ =0x0836C92C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080ADBD8 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_080ADBC4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl Projectile37_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBD4: .4byte 0x0836C92C
_080ADBD8: .4byte gProjectileFnTable
