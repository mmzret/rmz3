	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createIcebonIce
createIcebonIce: @ 0x080B9864
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080B98A4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080B989E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080B98A8 @ =gVFXFnTable
	movs r0, #0x1a
	strb r0, [r3, #9]
	ldr r0, [r1, #0x68]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	strb r0, [r3, #0x10]
_080B989E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B98A4: .4byte gVFXHeaderPtr
_080B98A8: .4byte gVFXFnTable

	thumb_func_start FUN_080b98ac
FUN_080b98ac: @ 0x080B98AC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080B98EC @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080B98E4
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080B98F0 @ =gVFXFnTable
	movs r0, #0x1a
	strb r0, [r4, #9]
	ldr r0, [r1, #0x68]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
	strb r2, [r4, #0x10]
_080B98E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B98EC: .4byte gVFXHeaderPtr
_080B98F0: .4byte gVFXFnTable

	thumb_func_start IcebonIcedust_Init
IcebonIcedust_Init: @ 0x080B98F4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B9934 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B9938 @ =0x0836EAFC
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl IcebonIcedust_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9934: .4byte gVFXFnTable
_080B9938: .4byte 0x0836EAFC

	thumb_func_start IcebonIcedust_Update
IcebonIcedust_Update: @ 0x080B993C
	push {lr}
	ldr r2, _080B9950 @ =0x0836EAF4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B9950: .4byte 0x0836EAF4

	thumb_func_start IcebonIcedust_Die
IcebonIcedust_Die: @ 0x080B9954
	ldr r2, _080B9968 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080B9968: .4byte gVFXFnTable

	thumb_func_start ice_080b996c
ice_080b996c: @ 0x080B996C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080B997C
	cmp r0, #1
	beq _080B99BA
	b _080B99EC
_080B997C:
	ldr r1, _080B99F4 @ =0x00001109
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _080B99F8 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _080B99FC @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080B9A00 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	ldr r6, _080B9A04 @ =0xFFFFFF00
	adds r0, r0, r6
	str r0, [r5, #0x5c]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x80
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B99BA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B99EC
	ldr r1, _080B9A08 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B99EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B99F4: .4byte 0x00001109
_080B99F8: .4byte RNG_0202f388
_080B99FC: .4byte 0x000343FD
_080B9A00: .4byte 0x00269EC3
_080B9A04: .4byte 0xFFFFFF00
_080B9A08: .4byte gVFXFnTable

	thumb_func_start ice_080b9a0c
ice_080b9a0c: @ 0x080B9A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9A1C
	cmp r0, #1
	beq _080B9A2A
	b _080B9A4C
_080B9A1C:
	ldr r1, _080B9A54 @ =0x00001109
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B9A2A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B9A4C
	ldr r1, _080B9A58 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B9A4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9A54: .4byte 0x00001109
_080B9A58: .4byte gVFXFnTable
