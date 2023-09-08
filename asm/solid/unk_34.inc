	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid34_Update
Solid34_Update: @ 0x080DC178
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _080DC1C6
	cmp r0, #1
	bgt _080DC18C
	cmp r0, #0
	beq _080DC192
	b _080DC242
_080DC18C:
	cmp r0, #2
	beq _080DC22C
	b _080DC242
_080DC192:
	ldr r0, _080DC1AC @ =gOverworld
	ldr r1, _080DC1B0 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x10]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DC1B8
	ldr r1, _080DC1B4 @ =0x00007601
	adds r0, r4, #0
	bl SetMotion
	b _080DC1C0
	.align 2, 0
_080DC1AC: .4byte gOverworld
_080DC1B0: .4byte 0x0002D024
_080DC1B4: .4byte 0x00007601
_080DC1B8:
	ldr r1, _080DC204 @ =0x00007602
	adds r0, r4, #0
	bl SetMotion
_080DC1C0:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080DC1C6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080DC1E8
	ldr r0, _080DC208 @ =gOverworld
	ldr r1, _080DC20C @ =0x0002D024
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_080DC1E8:
	ldr r0, _080DC208 @ =gOverworld
	ldr r1, _080DC20C @ =0x0002D024
	adds r0, r0, r1
	ldrb r1, [r4, #0x10]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080DC242
	cmp r1, #0
	bne _080DC214
	ldr r1, _080DC210 @ =0x00007603
	adds r0, r4, #0
	bl SetMotion
	b _080DC21C
	.align 2, 0
_080DC204: .4byte 0x00007602
_080DC208: .4byte gOverworld
_080DC20C: .4byte 0x0002D024
_080DC210: .4byte 0x00007603
_080DC214:
	ldr r1, _080DC228 @ =0x00007604
	adds r0, r4, #0
	bl SetMotion
_080DC21C:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	b _080DC240
	.align 2, 0
_080DC228: .4byte 0x00007604
_080DC22C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080DC242
_080DC240:
	strb r0, [r4, #0xf]
_080DC242:
	pop {r4}
	pop {r0}
	bx r0
