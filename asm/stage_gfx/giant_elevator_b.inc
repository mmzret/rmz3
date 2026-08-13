	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start gelevator_08014678
gelevator_08014678: @ 0x08014678
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r1, _08014708 @ =gOverworld
	ldr r2, _0801470C @ =0x0002D034
	adds r0, r1, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r6, _08014710 @ =0x0002D038
	adds r0, r1, r6
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r4, r0, #0x10
	ldr r7, _08014714 @ =0x0002D044
	adds r0, r1, r7
	ldr r0, [r0]
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _08014718 @ =0x0002D048
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #0xf
	lsrs r5, r0, #0x17
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	beq _0801477C
	ldr r2, _0801471C @ =gIntrManager
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	str r6, [r0]
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r2, r7
	ldr r0, _08014720 @ =0x04000018
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08014724 @ =0xA6600001
	str r0, [r1]
	movs r2, #0
	lsls r4, r4, #0x10
	str r4, [sp]
	movs r1, #0x80
	lsls r1, r1, #1
	mov ip, r1
	lsls r4, r5, #0x10
	mov r7, r8
	orrs r4, r7
	adds r0, r5, r1
	lsls r3, r0, #0x10
	orrs r3, r7
	adds r1, r6, #0
_080146FA:
	adds r0, r2, r5
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _08014728
	str r4, [r1]
	b _0801472A
	.align 2, 0
_08014708: .4byte gOverworld
_0801470C: .4byte 0x0002D034
_08014710: .4byte 0x0002D038
_08014714: .4byte 0x0002D044
_08014718: .4byte 0x0002D048
_0801471C: .4byte gIntrManager
_08014720: .4byte 0x04000018
_08014724: .4byte 0xA6600001
_08014728:
	str r3, [r1]
_0801472A:
	adds r1, #4
	adds r2, #1
	cmp r2, #0x9f
	ble _080146FA
	ldr r0, [sp]
	asrs r1, r0, #0x10
	cmp r1, #0xff
	ble _08014742
	mov r2, sb
	ldrb r0, [r2, #0xe]
	cmp r0, #7
	bls _0801477C
_08014742:
	movs r2, #0
	adds r3, r1, #0
	movs r7, #0x80
	lsls r7, r7, #1
	lsls r5, r3, #0x10
	mov r0, sl
	orrs r5, r0
	adds r0, r3, r7
	lsls r4, r0, #0x10
	mov r1, sl
	orrs r4, r1
	adds r1, r6, #0
_0801475A:
	adds r0, r2, r3
	ands r0, r7
	cmp r0, #0
	bne _08014766
	str r5, [r1]
	b _08014774
_08014766:
	mov r6, sb
	ldrb r0, [r6, #0xe]
	cmp r0, #7
	bls _08014774
	cmp r3, #0
	ble _08014774
	str r4, [r1]
_08014774:
	adds r1, #4
	adds r2, #1
	cmp r2, #0x9f
	ble _0801475A
_0801477C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801478c
FUN_0801478c: @ 0x0801478C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r4, [r7, #0xe]
	cmp r4, #1
	beq _080147E0
	cmp r4, #1
	bgt _080147AE
	cmp r4, #0
	beq _080147B4
	b _08014856
_080147AE:
	cmp r4, #2
	beq _0801484A
	b _08014856
_080147B4:
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _08014864 @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	orrs r0, r1
	movs r1, #0x44
	orrs r0, r1
	strh r0, [r2]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014868 @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x5e
	movs r3, #0
	bl LoadBgMap
	strh r4, [r7, #0x10]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080147E0:
	ldr r0, _0801486C @ =gOverworld
	ldr r1, _08014870 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #9
	bls _08014856
	mov r3, r8
	ldr r4, [r3, #8]
	lsrs r2, r5, #4
	lsls r2, r2, #1
	ldr r6, _08014864 @ =gVideoRegBuffer+4
	adds r2, r2, r6
	ldr r0, [r7, #0x64]
	ldr r3, _08014874 @ =0x00004046
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, [r4]
	adds r3, r3, r4
	ldr r5, [r4, #8]
	adds r5, r5, r4
	adds r0, r7, #0
	adds r0, #0x14
	adds r1, r7, #0
	adds r1, #0x34
	ldr r2, [r7, #0x5c]
	lsrs r2, r2, #4
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r4, [r2]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r4
	lsls r2, r2, #3
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r2, r2, r4
	str r5, [sp]
	ldrh r5, [r7, #0xc]
	lsls r5, r5, #2
	mov r4, r8
	adds r4, #0xc
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp, #4]
	bl ResetLayerGraphic
	ldr r0, _08014878 @ =0x80000001
	str r0, [r7, #0x40]
	str r0, [r7, #0x3c]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0801484A:
	ldr r0, _0801486C @ =gOverworld
	ldr r1, _0801487C @ =0x0002D03C
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	str r0, [r7, #0x4c]
_08014856:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014864: .4byte gVideoRegBuffer+4
_08014868: .4byte gBgMapOffsets
_0801486C: .4byte gOverworld
_08014870: .4byte 0x0002D024
_08014874: .4byte 0x00004046
_08014878: .4byte 0x80000001
_0801487C: .4byte 0x0002D03C

	thumb_func_start giantElevator_08014880
giantElevator_08014880: @ 0x08014880
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, _080148B8 @ =gOverworld
	ldr r3, _080148BC @ =0x0002D024
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #9
	bhi _080148CC
	ldr r1, [r2, #0x5c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x14
	lsls r1, r1, #2
	ldr r2, _080148C0 @ =gVideoRegBuffer+12
	adds r3, r1, r2
	ldr r5, _080148C4 @ =0x0002D050
	adds r0, r4, r5
	ldr r0, [r0]
	asrs r0, r0, #8
	strh r0, [r3]
	adds r2, #2
	adds r1, r1, r2
	ldr r2, _080148C8 @ =0x0002D054
	adds r0, r4, r2
	ldr r0, [r0]
	asrs r0, r0, #8
	strh r0, [r1]
	b _080148D2
	.align 2, 0
_080148B8: .4byte gOverworld
_080148BC: .4byte 0x0002D024
_080148C0: .4byte gVideoRegBuffer+12
_080148C4: .4byte 0x0002D050
_080148C8: .4byte 0x0002D054
_080148CC:
	adds r0, r2, #0
	bl DrawGeneralStageLayer
_080148D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start giantElevator_080148d8
giantElevator_080148d8: @ 0x080148D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r8, r1
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	bne _08014946
	lsrs r2, r0, #0x14
	lsls r4, r2, #1
	ldr r3, _0801498C @ =gVideoRegBuffer+4
	adds r4, r4, r3
	ldr r0, [r6, #0x60]
	ldr r1, [r6, #0x64]
	orrs r0, r1
	ldr r5, _08014990 @ =0x00008044
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r4]
	lsls r2, r2, #2
	adds r3, #8
	adds r2, r2, r3
	str r7, [r2]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _08014994 @ =gBgMapOffsets
	str r7, [sp]
	adds r1, r5, #0
	movs r2, #0x5a
	movs r3, #0
	bl LoadBgMap
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _08014998 @ =0x06000800
	adds r0, r0, r2
	str r7, [sp]
	adds r1, r5, #0
	movs r2, #0x5a
	movs r3, #0
	bl loadBgMap_08004248
	strh r7, [r6, #0x10]
	strh r7, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014946:
	ldr r0, _0801499C @ =gOverworld
	ldr r5, _080149A0 @ =0x0002D025
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014960
	ldrh r1, [r6, #0x12]
	ldr r0, _080149A4 @ =0x000007FF
	cmp r1, r0
	bhi _08014960
	adds r0, r1, #0
	adds r0, #8
	strh r0, [r6, #0x12]
_08014960:
	ldrh r0, [r6, #0x12]
	lsrs r0, r0, #8
	ldrh r2, [r6, #0x10]
	adds r1, r0, r2
	strh r1, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r2, r0, #0
	cmp r2, #1
	bne _080149AC
	lsls r1, r1, #0x10
	ldr r0, _080149A8 @ =0x14FF0000
	cmp r1, r0
	bls _080149AC
	mov r5, r8
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014994 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5b
	b _08014A12
	.align 2, 0
_0801498C: .4byte gVideoRegBuffer+4
_08014990: .4byte 0x00008044
_08014994: .4byte gBgMapOffsets
_08014998: .4byte 0x06000800
_0801499C: .4byte gOverworld
_080149A0: .4byte 0x0002D025
_080149A4: .4byte 0x000007FF
_080149A8: .4byte 0x14FF0000
_080149AC:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _080149F4
	ldrh r1, [r6, #0x10]
	ldr r0, _080149E4 @ =0x000015FF
	cmp r1, r0
	bls _080149F4
	mov r1, r8
	lsrs r0, r1, #4
	lsls r0, r0, #1
	ldr r1, _080149E8 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, _080149EC @ =0x06000800
	adds r0, r0, r2
	ldr r1, _080149F0 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5d
	movs r3, #0
	bl loadBgMap_08004248
	b _08014A18
	.align 2, 0
_080149E4: .4byte 0x000015FF
_080149E8: .4byte gVideoRegBuffer+4
_080149EC: .4byte 0x06000800
_080149F0: .4byte gBgMapOffsets
_080149F4:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08014A1E
	ldrh r1, [r6, #0x10]
	ldr r0, _08014A2C @ =0x000016FF
	cmp r1, r0
	bls _08014A1E
	mov r5, r8
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014A30 @ =gBgMapOffsets
	movs r2, #0
	str r2, [sp]
	movs r2, #0x5d
_08014A12:
	movs r3, #0
	bl LoadBgMap
_08014A18:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08014A1E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014A2C: .4byte 0x000016FF
_08014A30: .4byte gBgMapOffsets

	thumb_func_start giantElevator_08014a34
giantElevator_08014a34: @ 0x08014A34
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r3, _08014A5C @ =gVideoRegBuffer+12
	adds r4, r2, r3
	ldr r1, [r0, #0x34]
	ldr r5, _08014A60 @ =0xFFFFEBD8
	adds r1, r1, r5
	asrs r1, r1, #2
	strh r1, [r4]
	adds r3, #2
	adds r2, r2, r3
	ldrh r0, [r0, #0x10]
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014A5C: .4byte gVideoRegBuffer+12
_08014A60: .4byte 0xFFFFEBD8

	thumb_func_start giantElevator_08014a64
giantElevator_08014a64: @ 0x08014A64
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	bne _08014AAA
	lsrs r2, r0, #0x14
	lsls r3, r2, #1
	ldr r4, _08014AC4 @ =gVideoRegBuffer+4
	adds r3, r3, r4
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	orrs r0, r1
	movs r1, #0x44
	orrs r0, r1
	strh r0, [r3]
	lsls r2, r2, #2
	adds r4, #8
	adds r2, r2, r4
	str r6, [r2]
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08014AC8 @ =gBgMapOffsets
	str r6, [sp]
	movs r2, #0x5c
	movs r3, #0
	bl LoadBgMap
	strh r6, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08014AAA:
	ldr r0, _08014ACC @ =gOverworld
	ldr r1, _08014AD0 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08014ABC
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
_08014ABC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014AC4: .4byte gVideoRegBuffer+4
_08014AC8: .4byte gBgMapOffsets
_08014ACC: .4byte gOverworld
_08014AD0: .4byte 0x0002D025

	thumb_func_start giantElevator_08014ad4
giantElevator_08014ad4: @ 0x08014AD4
	push {r4, r5, lr}
	ldr r2, [r0, #0x5c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x14
	lsls r2, r2, #2
	ldr r3, _08014AFC @ =gVideoRegBuffer+12
	adds r4, r2, r3
	ldr r1, [r0, #0x34]
	ldr r5, _08014B00 @ =0xFFFFEBD8
	adds r1, r1, r5
	asrs r1, r1, #7
	strh r1, [r4]
	adds r3, #2
	adds r2, r2, r3
	ldrh r0, [r0, #0x10]
	lsrs r0, r0, #2
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014AFC: .4byte gVideoRegBuffer+12
_08014B00: .4byte 0xFFFFEBD8
