	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid25_Update
Solid25_Update: @ 0x080D8AC8
	push {r4, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x10]
	lsls r1, r0, #6
	ldr r4, _080D8B10 @ =gOverworld
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r2, r0
	cmp r2, #0xa
	beq _080D8AE6
	cmp r2, #0x10
	bne _080D8AEE
_080D8AE6:
	ldr r2, _080D8B14 @ =0x0002D030
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r1, r1, r0
_080D8AEE:
	lsls r1, r1, #0x10
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r1, r0, #0x10
	cmp r1, #0x7f
	bhi _080D8B1C
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _080D8B18 @ =0xFFFFD000
	adds r0, r0, r1
	ldr r1, [r3, #0x68]
	adds r1, r1, r0
	str r1, [r3, #0x58]
	b _080D8B30
	.align 2, 0
_080D8B10: .4byte gOverworld
_080D8B14: .4byte 0x0002D030
_080D8B18: .4byte 0xFFFFD000
_080D8B1C:
	adds r0, r1, #0
	subs r0, #0x80
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	ldr r2, _080D8B3C @ =0xFFFFD000
	adds r1, r1, r2
	ldr r0, [r3, #0x68]
	subs r0, r0, r1
	str r0, [r3, #0x58]
_080D8B30:
	adds r0, r3, #0
	bl UpdateMotionGraphic
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D8B3C: .4byte 0xFFFFD000

	thumb_func_start Solid25_Die
Solid25_Die: @ 0x080D8B40
	bx lr
	.align 2, 0
