	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MgNinjaStar_Update
MgNinjaStar_Update: @ 0x080D925C
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldr r0, [r2, #8]
	ldr r0, [r0, #0x54]
	ldr r3, [r4, #0x54]
	subs r0, r0, r3
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _080D92B0
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D92AC @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080D92DE
	.align 2, 0
_080D92AC: .4byte gSolidFnTable
_080D92B0:
	ldr r0, [r2, #0x14]
	adds r0, r3, r0
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	ldr r1, [r2, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, _080D92E4 @ =0x08371180
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080D92E8 @ =0x08371188
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080D92DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D92E4: .4byte 0x08371180
_080D92E8: .4byte 0x08371188

	thumb_func_start MgNinjaStar_Die
MgNinjaStar_Die: @ 0x080D92EC
	ldr r2, _080D9300 @ =gSolidFnTable
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
_080D9300: .4byte gSolidFnTable
