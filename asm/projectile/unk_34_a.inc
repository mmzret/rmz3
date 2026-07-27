	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile34_Init
Projectile34_Init: @ 0x080ACA18
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r2, #0
	movs r6, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r5, #0xa]
	ldrb r7, [r5, #0x10]
	cmp r7, #2
	bne _080ACA74
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACA6C @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACA70 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r7, [r5, #0xd]
	b _080ACAE6
	.align 2, 0
_080ACA6C: .4byte 0x0836C728
_080ACA70: .4byte gProjectileFnTable
_080ACA74:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080ACAB4
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACAAC @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACAB0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r6, [r5, #0xd]
	b _080ACAE6
	.align 2, 0
_080ACAAC: .4byte 0x0836C728
_080ACAB0: .4byte gProjectileFnTable
_080ACAB4:
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080ACAF8 @ =0x0836C728
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080ACAFC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	movs r0, #3
	strb r0, [r5, #0xd]
_080ACAE6:
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	bl Projectile34_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAF8: .4byte 0x0836C728
_080ACAFC: .4byte gProjectileFnTable
