	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Swordy_Die
Swordy_Die: @ 0x0807C03C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0807C070 @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _0807C07C
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C074 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C078 @ =0x0000270E
	cmp r1, r0
	bhi _0807C06A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C06A:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C1FE
	.align 2, 0
_0807C070: .4byte gStageRun
_0807C074: .4byte gScore
_0807C078: .4byte 0x0000270E
_0807C07C:
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0807C084
	b _0807C21C
_0807C084:
	lsls r0, r0, #2
	ldr r1, _0807C090 @ =_0807C094
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807C090: .4byte _0807C094
_0807C094: @ jump table
	.4byte _0807C0A8 @ case 0
	.4byte _0807C158 @ case 1
	.4byte _0807C188 @ case 2
	.4byte _0807C198 @ case 3
	.4byte _0807C1D4 @ case 4
_0807C0A8:
	ldr r1, _0807C108 @ =0x00003F02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C110
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C10C @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl createGhost44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl TryDropItem
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C158
	.align 2, 0
_0807C108: .4byte 0x00003F02
_0807C10C: .4byte 0xFFFFF400
_0807C110:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C14C @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0807C150 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C154 @ =0x0000270E
	cmp r1, r0
	bhi _0807C144
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C144:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C1FE
	.align 2, 0
_0807C14C: .4byte 0xFFFFFA00
_0807C150: .4byte gScore
_0807C154: .4byte 0x0000270E
_0807C158:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C178
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C17E
_0807C178:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C17E:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C21C
	b _0807C1CC
_0807C188:
	adds r0, r4, #0
	bl PaintEntityWhite
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C198:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C1B2
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C1B8
_0807C1B2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C1B8:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C21C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
_0807C1CC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C21C
_0807C1D4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807C1E4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C21C
_0807C1E4:
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C224 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C228 @ =0x0000270E
	cmp r1, r0
	bhi _0807C1F8
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C1F8:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
_0807C1FE:
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807C22C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0807C21C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C224: .4byte gScore
_0807C228: .4byte 0x0000270E
_0807C22C: .4byte gEnemyFnTable

