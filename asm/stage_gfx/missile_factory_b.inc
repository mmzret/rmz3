	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800f54c
FUN_0800f54c: @ 0x0800F54C
	push {lr}
	movs r0, #0xcf
	bl RemovePaletteAnimation
	movs r0, #0xd0
	bl RemovePaletteAnimation
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start missileFactory_0800f560
missileFactory_0800f560: @ 0x0800F560
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	mov r8, r0
	cmp r0, #0
	bne _0800F5D8
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r5, r0, #1
	ldr r3, _0800F5E8 @ =gVideoRegBuffer+4
	adds r5, r5, r3
	ldr r1, [r7, #0x60]
	ldr r2, [r7, #0x64]
	orrs r1, r2
	ldr r4, _0800F5EC @ =0x00004044
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r5]
	lsls r0, r0, #2
	adds r3, #8
	adds r0, r0, r3
	mov r2, r8
	str r2, [r0]
	ldr r0, _0800F5F0 @ =0x085223E4
	ldr r0, [r0]
	ldr r4, _0800F5F4 @ =0x085223EC
	adds r0, r0, r4
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _0800F5F8 @ =0x085223E8
	ldr r0, [r0]
	ldr r1, _0800F5FC @ =0x085223F0
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _0800F600 @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	mov r4, r8
	strh r4, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800F5D8:
	ldrh r0, [r7, #0x10]
	adds r0, #4
	strh r0, [r7, #0x10]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F5E8: .4byte gVideoRegBuffer+4
_0800F5EC: .4byte 0x00004044
_0800F5F0: .4byte 0x085223E4
_0800F5F4: .4byte 0x085223EC
_0800F5F8: .4byte 0x085223E8
_0800F5FC: .4byte 0x085223F0
_0800F600: .4byte 0x06000800

	thumb_func_start FUN_0800f604
FUN_0800f604: @ 0x0800F604
	push {r4, r5, lr}
	ldrh r4, [r0, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r3, r0, #0
	cmp r3, #0
	beq _0800F67A
	ldr r2, _0800F680 @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r3, [r0]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r2, r5
	ldr r0, _0800F684 @ =0x0400001C
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0800F688 @ =0xA6600001
	str r0, [r1]
	lsrs r1, r4, #6
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r3, r2
_0800F63C:
	str r1, [r0]
	subs r0, #4
	cmp r0, r3
	bge _0800F63C
	lsrs r2, r4, #5
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r1, #7
_0800F64E:
	stm r0!, {r2}
	subs r1, #1
	cmp r1, #0
	bge _0800F64E
	lsrs r2, r4, #3
	movs r1, #0x58
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r0, r3, r5
_0800F660:
	stm r0!, {r2}
	adds r1, #1
	cmp r1, #0x6f
	ble _0800F660
	cmp r1, #0x9f
	bgt _0800F67A
	lsrs r2, r4, #2
	lsls r0, r1, #2
	adds r0, r0, r3
_0800F672:
	stm r0!, {r2}
	adds r1, #1
	cmp r1, #0x9f
	ble _0800F672
_0800F67A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F680: .4byte gIntrManager
_0800F684: .4byte 0x0400001C
_0800F688: .4byte 0xA6600001

	thumb_func_start FUN_0800f68c
FUN_0800f68c: @ 0x0800F68C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0800F6DE
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _0800F6E8 @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldr r1, [r4, #0x64]
	ldr r3, _0800F6EC @ =0x00004046
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r5, [sp, #4]
	ldr r2, _0800F6F0 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0800F6F4 @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x59
	movs r3, #0
	bl LoadBgMap
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0800F6DE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F6E8: .4byte gVideoRegBuffer+4
_0800F6EC: .4byte 0x00004046
_0800F6F0: .4byte 0x01000400
_0800F6F4: .4byte gBgMapOffsets

	thumb_func_start FUN_0800f6f8
FUN_0800f6f8: @ 0x0800F6F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0800F720 @ =gOverworld
	ldr r1, _0800F724 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F72C
	ldr r0, _0800F728 @ =gVideoRegBuffer
	lsls r1, r5, #8
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _0800F736
	.align 2, 0
_0800F720: .4byte gOverworld
_0800F724: .4byte 0x0002D026
_0800F728: .4byte gVideoRegBuffer
_0800F72C:
	ldr r2, _0800F808 @ =gVideoRegBuffer
	lsls r1, r5, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_0800F736:
	ldr r7, _0800F80C @ =gOverworld
	ldr r2, _0800F810 @ =0x0002C002
	adds r0, r7, r2
	ldrh r0, [r0]
	lsrs r1, r5, #4
	mov r8, r1
	cmp r0, #0
	beq _0800F778
	movs r4, #0
	lsls r0, r1, #1
	ldr r1, _0800F814 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r4, [sp, #4]
	ldr r2, _0800F818 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0800F81C @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x59
	movs r3, #0
	bl LoadBgMap
_0800F778:
	ldr r2, _0800F820 @ =0x0002D038
	adds r0, r7, r2
	ldr r2, [r0]
	adds r5, r7, #0
	cmp r2, #0
	beq _0800F7C2
	ldr r7, _0800F824 @ =0x0002D03C
	adds r1, r5, r7
	ldr r0, [r2, #0x54]
	str r0, [r1]
	ldr r0, _0800F828 @ =0x0002D040
	adds r1, r5, r0
	ldr r0, [r2, #0x58]
	str r0, [r1]
	ldr r0, _0800F82C @ =gWhitePaintFlags
	ldrb r1, [r2, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0800F7C2
	ldr r1, _0800F830 @ =gPaletteManager
	ldr r7, _0800F834 @ =0x00000404
	adds r2, r1, r7
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r0, _0800F838 @ =0x00000406
	adds r1, r1, r0
	movs r0, #0x20
	strh r0, [r1]
_0800F7C2:
	mov r1, r8
	lsls r3, r1, #2
	ldr r2, _0800F83C @ =gVideoRegBuffer+12
	adds r4, r3, r2
	ldr r1, [r6, #0x34]
	ldr r7, _0800F824 @ =0x0002D03C
	adds r0, r5, r7
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x30
	ldr r0, [r6, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r4]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [r6, #0x38]
	ldr r2, _0800F828 @ =0x0002D040
	adds r0, r5, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x90
	ldr r0, [r6, #0x30]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F808: .4byte gVideoRegBuffer
_0800F80C: .4byte gOverworld
_0800F810: .4byte 0x0002C002
_0800F814: .4byte gVideoRegBuffer+4
_0800F818: .4byte 0x01000400
_0800F81C: .4byte gBgMapOffsets
_0800F820: .4byte 0x0002D038
_0800F824: .4byte 0x0002D03C
_0800F828: .4byte 0x0002D040
_0800F82C: .4byte gWhitePaintFlags
_0800F830: .4byte gPaletteManager
_0800F834: .4byte 0x00000404
_0800F838: .4byte 0x00000406
_0800F83C: .4byte gVideoRegBuffer+12

	thumb_func_start FUN_0800f840
FUN_0800f840: @ 0x0800F840
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x5c]
	lsls r2, r0, #0x10
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0800F868
	lsrs r2, r2, #0x14
	lsls r2, r2, #1
	ldr r0, _0800F86C @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _0800F870 @ =0x0000FFFC
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0800F868:
	pop {r0}
	bx r0
	.align 2, 0
_0800F86C: .4byte gVideoRegBuffer+4
_0800F870: .4byte 0x0000FFFC

	thumb_func_start FUN_0800f874
FUN_0800f874: @ 0x0800F874
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _0800F88A
	movs r0, #0xc0
	str r0, [r1, #0x44]
	ldr r0, _0800F890 @ =0x000006CC
	str r0, [r1, #0x4c]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800F88A:
	pop {r0}
	bx r0
	.align 2, 0
_0800F890: .4byte 0x000006CC

	thumb_func_start FUN_0800f894
FUN_0800f894: @ 0x0800F894
	ldr r1, _0800F8A0 @ =gOverworld
	ldr r2, _0800F8A4 @ =0x0002D038
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0800F8A0: .4byte gOverworld
_0800F8A4: .4byte 0x0002D038
