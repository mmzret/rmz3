	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a2f34
FUN_080a2f34: @ 0x080A2F34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	movs r5, #0
	movs r6, #0
	ldr r1, _080A2F98 @ =0xFFFFE400
	adds r4, r0, r1
	ldr r2, _080A2F9C @ =gProjectileFnTable
	mov r8, r2
_080A2F48:
	ldr r0, _080A2FA0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2F80
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x12
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2, #0x48]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r6, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r6, [r0]
	strb r6, [r1, #0x10]
	str r4, [r1, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r7, r2
	str r0, [r1, #0x58]
	strb r5, [r1, #0x12]
_080A2F80:
	movs r0, #0xe0
	lsls r0, r0, #6
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	ble _080A2F48
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2F98: .4byte 0xFFFFE400
_080A2F9C: .4byte gProjectileFnTable
_080A2FA0: .4byte gProjectileHeaderPtr

