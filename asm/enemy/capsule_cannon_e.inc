	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08085c4c
FUN_08085c4c: @ 0x08085C4C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _08085CB6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08085CB6
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	ldr r2, _08085CA0 @ =0x083684E8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _08085CB6
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08085CA8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085CA4 @ =0x083684D0
	bl SetDDP
	b _08085CB6
	.align 2, 0
_08085CA0: .4byte 0x083684E8
_08085CA4: .4byte 0x083684D0
_08085CA8:
	cmp r1, #0x30
	bne _08085CB6
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085CC0 @ =0x083684D0
	bl SetDDP
_08085CB6:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08085CC0: .4byte 0x083684D0

	thumb_func_start FUN_08085cc4
FUN_08085cc4: @ 0x08085CC4
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _08085CDC
	cmp r0, #0xe
	beq _08085CDC
	cmp r0, #0xf
	bne _08085D06
_08085CDC:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08085D06
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _08085CFE
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08085D04
_08085CFE:
	adds r1, r2, #0
	adds r1, #0xba
	movs r0, #0xfe
_08085D04:
	strb r0, [r1]
_08085D06:
	pop {r0}
	bx r0
	.align 2, 0

