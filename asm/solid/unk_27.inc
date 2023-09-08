	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d8f2c
FUN_080d8f2c: @ 0x080D8F2C
	push {r4, lr}
	ldr r0, _080D8F74 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8F6A
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080D8F78 @ =gSolidFnTable
	movs r0, #0x1b
	strb r0, [r4, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
_080D8F6A:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D8F74: .4byte gSolidHeaderPtr
_080D8F78: .4byte gSolidFnTable

	thumb_func_start FUN_080d8f7c
FUN_080d8f7c: @ 0x080D8F7C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080D8FCC @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080D8FC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080D8FD0 @ =gSolidFnTable
	movs r0, #0x1b
	strb r0, [r3, #9]
	ldr r0, [r1, #0x6c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
_080D8FC2:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D8FCC: .4byte gSolidHeaderPtr
_080D8FD0: .4byte gSolidFnTable

	thumb_func_start FUN_080d8fd4
FUN_080d8fd4: @ 0x080D8FD4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	beq _080D8FE0
	movs r0, #1
	strb r0, [r1, #0x13]
_080D8FE0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8fe4
FUN_080d8fe4: @ 0x080D8FE4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	beq _080D8FF0
	movs r0, #0
	strb r0, [r1, #0x13]
_080D8FF0:
	pop {r0}
	bx r0

	thumb_func_start Solid27_Init
Solid27_Init: @ 0x080D8FF4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r2, #0
	movs r6, #0
	strb r6, [r5, #0x13]
	strb r6, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080D9024
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D9020 @ =0x083710F4
	b _080D903A
	.align 2, 0
_080D9020: .4byte 0x083710F4
_080D9024:
	movs r0, #4
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldrb r0, [r5, #0x11]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D9068 @ =0x0837110C
	adds r1, r1, r0
_080D903A:
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080D906C @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Solid27_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D9068: .4byte 0x0837110C
_080D906C: .4byte gSolidFnTable

	thumb_func_start Solid27_Update
Solid27_Update: @ 0x080D9070
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0x10]
	cmp r6, #0
	bne _080D90E4
	ldrb r0, [r5, #0x13]
	adds r1, r0, #0
	ldrb r2, [r5, #0x12]
	cmp r1, r2
	beq _080D90C6
	strb r0, [r5, #0x12]
	cmp r1, #0
	beq _080D90B0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D90AC @ =0x083710F4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _080D90C6
	.align 2, 0
_080D90AC: .4byte 0x083710F4
_080D90B0:
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
_080D90C6:
	ldr r0, _080D90D8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	ldr r0, _080D90DC @ =gOverworld
	ldr r1, _080D90E0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	b _080D9150
	.align 2, 0
_080D90D8: .4byte pZero2
_080D90DC: .4byte gOverworld
_080D90E0: .4byte 0x0002C00C
_080D90E4:
	ldr r0, _080D9124 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	str r2, [r5, #0x54]
	ldr r1, [r0, #0x58]
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080D9130
	adds r0, r2, #0
	bl FUN_0800a31c
	str r0, [r5, #0x54]
	ldr r0, _080D9128 @ =gOverworld
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080D9152
	ldr r1, [r5, #0x58]
	movs r0, #0x97
	lsls r0, r0, #0xb
	cmp r1, r0
	bgt _080D9150
	ldr r0, _080D912C @ =0x000427FF
	cmp r1, r0
	bgt _080D9152
	adds r0, #1
	b _080D9150
	.align 2, 0
_080D9124: .4byte pZero2
_080D9128: .4byte gOverworld
_080D912C: .4byte 0x000427FF
_080D9130:
	cmp r0, #1
	bne _080D913E
	adds r0, r2, #0
	bl FUN_0800a22c
	str r0, [r5, #0x54]
	b _080D9152
_080D913E:
	cmp r0, #2
	bne _080D914A
	adds r0, r2, #0
	bl FUN_0800a134
	b _080D9150
_080D914A:
	adds r0, r2, #0
	bl FUN_08009f6c
_080D9150:
	str r0, [r5, #0x58]
_080D9152:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Solid27_Die
Solid27_Die: @ 0x080D9158
	bx lr
	.align 2, 0
