	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateSwordy
CreateSwordy: @ 0x0807BEA8
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0807BEFC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0807BEF4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0807BF00 @ =gEnemyFnTable
	movs r0, #0x1f
	strb r0, [r3, #9]
	ldr r0, [r1, #0x7c]
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_0807BEF4:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807BEFC: .4byte gZakoHeaderPtr
_0807BF00: .4byte gEnemyFnTable

	thumb_func_start Swordy_Init
Swordy_Init: @ 0x0807BF04
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r5, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0807BFA0 @ =0x08367A58
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	adds r0, #0x60
	str r5, [r0]
	subs r0, #4
	strb r5, [r0]
	adds r0, #8
	strb r6, [r0]
	ldr r1, _0807BFA4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r0, r7, #0
	bl isFrozen
	cmp r0, #0
	beq _0807BF94
	movs r1, #0xfc
	lsls r1, r1, #6
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
_0807BF94:
	adds r0, r7, #0
	bl Swordy_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807BFA0: .4byte 0x08367A58
_0807BFA4: .4byte gEnemyFnTable

	thumb_func_start Swordy_Update
Swordy_Update: @ 0x0807BFA8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807BFD8
	ldr r1, _0807BFD4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Swordy_Die
	b _0807C030
	.align 2, 0
_0807BFD4: .4byte gEnemyFnTable
_0807BFD8:
	ldr r1, _0807C01C @ =0x08367A38
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0807c530
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807C020
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807C030
	ldrb r0, [r4, #0xd]
	adds r1, r4, #0
	adds r1, #0xba
	strb r0, [r1]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
	ldr r0, [r6]
	bl isKilled
	cmp r0, #0
	beq _0807C030
	str r5, [r6]
	b _0807C030
	.align 2, 0
_0807C01C: .4byte 0x08367A38
_0807C020:
	ldr r0, _0807C038 @ =0x08367A48
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0807C030:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C038: .4byte 0x08367A48

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
	ldr r2, _0807C074 @ =gMission
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
_0807C074: .4byte gMission
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
	ldr r2, _0807C150 @ =gMission
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
_0807C150: .4byte gMission
_0807C154: .4byte 0x0000270E
_0807C158:
	adds r0, r4, #0
	bl UpdateMotionGraphic
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
	ldr r2, _0807C224 @ =gMission
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
_0807C224: .4byte gMission
_0807C228: .4byte 0x0000270E
_0807C22C: .4byte gEnemyFnTable

	thumb_func_start FUN_0807c230
FUN_0807c230: @ 0x0807C230
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807c234
FUN_0807c234: @ 0x0807C234
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0807C240
	b _0807C46E
_0807C240:
	lsls r0, r0, #2
	ldr r1, _0807C24C @ =_0807C250
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807C24C: .4byte _0807C250
_0807C250: @ jump table
	.4byte _0807C268 @ case 0
	.4byte _0807C2A6 @ case 1
	.4byte _0807C360 @ case 2
	.4byte _0807C3FC @ case 3
	.4byte _0807C420 @ case 4
	.4byte _0807C43E @ case 5
_0807C268:
	movs r1, #0xfc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807C290 @ =0x08367A58
	bl SetDDP
	ldr r0, _0807C294 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _0807C298 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r0, r1
	ble _0807C29C
	movs r0, #0
	b _0807C29E
	.align 2, 0
_0807C290: .4byte 0x08367A58
_0807C294: .4byte pZero2
_0807C298: .4byte 0xFFFFF800
_0807C29C:
	movs r0, #1
_0807C29E:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C2A6:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0807C2D0
	ldr r1, [r4, #0x58]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r1, r3
	str r1, [r4, #0x58]
	ldr r2, _0807C2C8 @ =pZero2
	ldr r0, [r2]
	ldr r0, [r0, #0x58]
	ldr r3, _0807C2CC @ =0xFFFFF800
	adds r0, r0, r3
	cmp r0, r1
	bge _0807C2EE
	b _0807C2E6
	.align 2, 0
_0807C2C8: .4byte pZero2
_0807C2CC: .4byte 0xFFFFF800
_0807C2D0:
	ldr r1, [r4, #0x58]
	ldr r0, _0807C314 @ =0xFFFFFE80
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r2, _0807C318 @ =pZero2
	ldr r0, [r2]
	ldr r0, [r0, #0x58]
	ldr r3, _0807C31C @ =0xFFFFF800
	adds r0, r0, r3
	cmp r0, r1
	ble _0807C2EE
_0807C2E6:
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C2EE:
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C320
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807C358
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C33A
	movs r0, #0x10
	orrs r0, r2
	b _0807C33E
	.align 2, 0
_0807C314: .4byte 0xFFFFFE80
_0807C318: .4byte pZero2
_0807C31C: .4byte 0xFFFFF800
_0807C320:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807C358
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C33A
	movs r0, #0x10
	orrs r0, r2
	b _0807C33E
_0807C33A:
	movs r0, #0xef
	ands r0, r2
_0807C33E:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C358:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0807C46E
_0807C360:
	ldr r0, _0807C388 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C3B0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807C3AA
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C38C
	movs r0, #0x10
	orrs r0, r2
	b _0807C390
	.align 2, 0
_0807C388: .4byte pZero2
_0807C38C:
	movs r0, #0xef
	ands r0, r2
_0807C390:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C3AA:
	movs r0, #0xc0
	lsls r0, r0, #1
	b _0807C3EA
_0807C3B0:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807C3E8
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C3CA
	movs r0, #0x10
	orrs r0, r2
	b _0807C3CE
_0807C3CA:
	movs r0, #0xef
	ands r0, r2
_0807C3CE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C3E8:
	ldr r0, _0807C41C @ =0xFFFFFE80
_0807C3EA:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x64]
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C3FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807C412
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C46E
_0807C412:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C46E
	.align 2, 0
_0807C41C: .4byte 0xFFFFFE80
_0807C420:
	ldr r1, _0807C474 @ =0x00003F01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807C478 @ =0x08367A88
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C43E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	adds r1, r0, #0
	cmp r1, #0
	bge _0807C454
	rsbs r1, r1, #0
_0807C454:
	movs r0, #0xf0
	lsls r0, r0, #9
	cmp r1, r0
	ble _0807C468
	ldr r1, [r4, #0x60]
	adds r1, #0x80
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x58]
_0807C468:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0807C46E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C474: .4byte 0x00003F01
_0807C478: .4byte 0x08367A88

	thumb_func_start FUN_0807c47c
FUN_0807c47c: @ 0x0807C47C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807c480
FUN_0807c480: @ 0x0807C480
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807C48E
	movs r0, #1
	strb r0, [r4, #0xe]
_0807C48E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807C4A4
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807C4A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807c4ac
FUN_0807c4ac: @ 0x0807C4AC
	movs r0, #1
	bx lr

	thumb_func_start nop_0807c4b0
nop_0807c4b0: @ 0x0807C4B0
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807c4b4
FUN_0807c4b4: @ 0x0807C4B4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807c4b8
FUN_0807c4b8: @ 0x0807C4B8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807C4C8
	cmp r0, #1
	beq _0807C4D0
	b _0807C514
_0807C4C8:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C4D0:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807C4E0
	str r1, [r4, #0x60]
_0807C4E0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807C50C
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0807C508 @ =0xFFFFF000
	b _0807C510
	.align 2, 0
_0807C508: .4byte 0xFFFFF000
_0807C50C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0807C510:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0807C514:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807C52A
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807C52A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807c530
FUN_0807c530: @ 0x0807C530
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807C57A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _0807C57A
	ldr r2, _0807C56C @ =0x08367AD0
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807C57A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807C570
	strb r7, [r4, #0xd]
	b _0807C578
	.align 2, 0
_0807C56C: .4byte 0x08367AD0
_0807C570:
	cmp r1, #0x30
	bne _0807C57A
	movs r0, #3
	strb r0, [r4, #0xd]
_0807C578:
	strb r5, [r4, #0xe]
_0807C57A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
