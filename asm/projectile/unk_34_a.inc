	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ac880
FUN_080ac880: @ 0x080AC880
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC8E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _080AC8D8
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC8E4 @ =gProjectileFnTable
	movs r1, #0x22
	mov r2, ip
	strb r1, [r2, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r2, [r3, #0x11]
	mov r0, ip
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC8D8:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC8E0: .4byte gProjectileHeaderPtr
_080AC8E4: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac8e8
FUN_080ac8e8: @ 0x080AC8E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC948 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _080AC940
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC94C @ =gProjectileFnTable
	movs r1, #0x22
	mov r2, ip
	strb r1, [r2, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x20]
	adds r0, #0x22
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r3, ip
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r2, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	mov r0, ip
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC940:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC948: .4byte gProjectileHeaderPtr
_080AC94C: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac950
FUN_080ac950: @ 0x080AC950
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080AC9AC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AC9A4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AC9B0 @ =gProjectileFnTable
	movs r1, #0x22
	strb r1, [r3, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r0, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080AC9A4:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC9AC: .4byte gProjectileHeaderPtr
_080AC9B0: .4byte gProjectileFnTable

	thumb_func_start FUN_080ac9b4
FUN_080ac9b4: @ 0x080AC9B4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080ACA10 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080ACA06
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080ACA14 @ =gProjectileFnTable
	movs r1, #0x22
	strb r1, [r3, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0xb8
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	str r7, [r3, #0x28]
_080ACA06:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ACA10: .4byte gProjectileHeaderPtr
_080ACA14: .4byte gProjectileFnTable

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

	thumb_func_start Projectile34_Update
Projectile34_Update: @ 0x080ACB00
	push {lr}
	ldr r2, _080ACB14 @ =0x0836C718
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080ACB14: .4byte 0x0836C718

	thumb_func_start Projectile34_Die
Projectile34_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40
	.byte 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00
	.byte 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x70, 0x47
  .align 2, 0
	.4byte gProjectileFnTable
