	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08011140
FUN_08011140: @ 0x08011140
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801116E
	ldr r1, [r3, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #1
	ldr r0, _08011184 @ =gVideoRegBuffer+4
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08011188 @ =0x0000FFFC
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0801118C @ =gBlendRegBuffer
	ldr r0, _08011190 @ =0x00003B44
	strh r0, [r1]
	ldr r0, _08011194 @ =0x00000C04
	strh r0, [r1, #2]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801116E:
	ldr r1, [r3, #0x34]
	ldr r0, _08011198 @ =0x0000151F
	cmp r1, r0
	bgt _080111A4
	ldr r0, _0801119C @ =gOverworld
	ldr r1, _080111A0 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xa
	b _080111AE
	.align 2, 0
_08011184: .4byte gVideoRegBuffer+4
_08011188: .4byte 0x0000FFFC
_0801118C: .4byte gBlendRegBuffer
_08011190: .4byte 0x00003B44
_08011194: .4byte 0x00000C04
_08011198: .4byte 0x0000151F
_0801119C: .4byte gOverworld
_080111A0: .4byte 0x0002C00C
_080111A4:
	ldr r0, _080111B4 @ =gOverworld
	ldr r1, _080111B8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
_080111AE:
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080111B4: .4byte gOverworld
_080111B8: .4byte 0x0002C00C

	thumb_func_start FUN_080111bc
FUN_080111bc: @ 0x080111BC
	ldr r1, _080111D0 @ =gBlendRegBuffer
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080111D4 @ =gOverworld
	ldr r1, _080111D8 @ =0x0002C00C
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	str r1, [r0]
	bx lr
	.align 2, 0
_080111D0: .4byte gBlendRegBuffer
_080111D4: .4byte gOverworld
_080111D8: .4byte 0x0002C00C
