	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf1_Update
Elf1_Update: @ 0x080E21C8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E228C @ =gZeroRanges
	ldr r2, _080E2290 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r7, #0
	bl UpdateEntityAnim
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	asrs r4, r4, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x68]
	ldr r1, _080E2294 @ =0x08371CA0
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	adds r1, r7, #0
	adds r1, #0xb8
	ldrb r3, [r1]
	ldrb r0, [r7, #0xd]
	cmp r0, #3
	bhi _080E2220
	adds r3, #1
	adds r0, r3, #0
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r3, r3, r0
	strb r3, [r1]
_080E2220:
	lsls r3, r3, #4
	ldr r1, _080E2298 @ =gSineTable
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r2, #4]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	movs r1, #0x10
	cmp r0, #0x7f
	ble _080E225A
	movs r1, #0x11
_080E225A:
	adds r0, r7, #0
	adds r0, #0x25
	strb r1, [r0]
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bhi _080E2286
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E2286
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E2286:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E228C: .4byte gZeroRanges
_080E2290: .4byte 0x00000147
_080E2294: .4byte sElf1Updates
_080E2298: .4byte gSineTable

	thumb_func_start Elf1_Die
Elf1_Die: @ 0x080E229C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldr r1, _080E22FC @ =gPause
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E2300 @ =gElfAvailability
	adds r3, r2, #0
	adds r3, #0xb4
	ldr r5, _080E2304 @ =0x00000121
	adds r0, r2, r5
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r0, _080E2308 @ =gScore
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E22DA
	adds r0, #1
	strb r0, [r1]
_080E22DA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E230C @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E22FC: .4byte gPause
_080E2300: .4byte gElfAvailability
_080E2304: .4byte 0x00000121
_080E2308: .4byte gScore
_080E230C: .4byte gElfFnTable
