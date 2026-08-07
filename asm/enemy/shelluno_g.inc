	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807a3ec
FUN_0807a3ec: @ 0x0807A3EC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #4]
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq _0807A404
	cmp r0, #0xe
	beq _0807A404
	cmp r0, #0xf
	bne _0807A42E
_0807A404:
	ldr r2, [r3, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807A42E
	ldr r1, [r2, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _0807A426
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xff
	b _0807A42C
_0807A426:
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xfe
_0807A42C:
	strb r0, [r1]
_0807A42E:
	ldr r0, [r4, #4]
	ldr r1, _0807A464 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0807A45E
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #5
	beq _0807A45E
	adds r0, r2, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807A45E
	ldr r1, _0807A468 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_0807A45E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A464: .4byte 0x000200FF
_0807A468: .4byte gEnemyFnTable

	thumb_func_start FUN_0807a46c
FUN_0807a46c: @ 0x0807A46C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0807A4D8 @ =gOverworld
	ldr r2, _0807A4DC @ =0x0002C00C
	adds r1, r1, r2
	ldr r5, [r1]
	ldr r2, [r4, #0x58]
	ldr r3, _0807A4E0 @ =0xFFFFF400
	adds r1, r2, r3
	cmp r5, r1
	ble _0807A4D0
	ldr r0, [r4, #0x54]
	adds r1, r2, #0
	bl FUN_0800a05c
	ldr r1, [r4, #0x58]
	cmp r0, r1
	beq _0807A4A0
	adds r1, r4, #0
	adds r1, #0xc1
	movs r0, #0x1e
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	str r0, [r4, #0x58]
_0807A4A0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	ldr r2, [r4, #0x58]
	cmp r1, r2
	beq _0807A4D0
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	beq _0807A4D0
	ldr r1, _0807A4E4 @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x58]
	cmp r1, r2
	bge _0807A4D0
	adds r2, r4, #0
	adds r2, #0xc1
	movs r1, #0x1e
	strb r1, [r2]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r5, r2
	str r1, [r4, #0x58]
_0807A4D0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807A4D8: .4byte gOverworld
_0807A4DC: .4byte 0x0002C00C
_0807A4E0: .4byte 0xFFFFF400
_0807A4E4: .4byte pZero2

