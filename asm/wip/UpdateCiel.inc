	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #0xe
	bls _080DAF58
	b _080DB3FC
_080DAF58:
	lsls r0, r0, #2
	ldr r1, _080DAF64 @ =_080DAF68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAF64: .4byte _080DAF68
_080DAF68: @ jump table
	.4byte _080DAFA4 @ case 0
	.4byte _080DB030 @ case 1
	.4byte _080DB2A0 @ case 2
	.4byte _080DB2F0 @ case 3
	.4byte _080DB316 @ case 4
	.4byte _080DB34E @ case 5
	.4byte _080DB368 @ case 6
	.4byte _080DB390 @ case 7
	.4byte _080DB3C6 @ case 8
	.4byte _080DB316 @ case 9
	.4byte _080DB34E @ case 10
	.4byte _080DB368 @ case 11
	.4byte _080DB390 @ case 12
	.4byte _080DB3C6 @ case 13
	.4byte _080DB3F6 @ case 14
_080DAFA4:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r1, [r5, #0x54]
	str r1, [r5, #0x64]
	ldr r0, _080DB084 @ =gOverworld
	ldr r2, _080DB088 @ =0x0002D024
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DB000
	ldr r2, _080DB08C @ =0xFFFFE800
	adds r0, r1, r2
	str r0, [r5, #0x54]
_080DB000:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DB090 @ =Collision_ARRAY_08371380
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DB030:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x70
	ldrb r1, [r2]
	orrs r0, r1
	movs r3, #0xc2
	lsls r3, r3, #8
	adds r4, r2, #0
	cmp r0, r3
	beq _080DB05C
	ldr r0, _080DB084 @ =gOverworld
	ldr r1, _080DB094 @ =0x0002D025
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _080DB07A
_080DB05C:
	ldrb r2, [r5, #0x1e]
	lsls r1, r2, #8
	ldrb r0, [r4]
	orrs r1, r0
	ldr r3, _080DB098 @ =0x0000C206
	cmp r1, r3
	beq _080DB09C
	ldr r0, _080DB084 @ =gOverworld
	ldr r1, _080DB094 @ =0x0002D025
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _080DB09C
_080DB07A:
	adds r0, r5, #0
	adds r1, r3, #0
	bl SetMotion
	b _080DB0C0
	.align 2, 0
_080DB084: .4byte gOverworld
_080DB088: .4byte 0x0002D024
_080DB08C: .4byte 0xFFFFE800
_080DB090: .4byte Collision_ARRAY_08371380
_080DB094: .4byte 0x0002D025
_080DB098: .4byte 0x0000C206
_080DB09C:
	lsls r0, r2, #8
	ldrb r1, [r4]
	orrs r0, r1
	ldr r2, _080DB0DC @ =0x0000C201
	cmp r0, r2
	beq _080DB0C0
	ldr r0, _080DB0E0 @ =gOverworld
	ldr r1, _080DB0E4 @ =0x0002D025
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #2
	bne _080DB0C0
	adds r0, r5, #0
	adds r1, r2, #0
	bl SetMotion
_080DB0C0:
	ldr r1, _080DB0E0 @ =gOverworld
	ldr r2, _080DB0E4 @ =0x0002D025
	adds r0, r1, r2
	ldrb r0, [r0]
	lsrs r2, r0, #7
	movs r0, #1
	eors r2, r0
	adds r4, r1, #0
	cmp r2, #0
	beq _080DB0E8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080DB0EE
	.align 2, 0
_080DB0DC: .4byte 0x0000C201
_080DB0E0: .4byte gOverworld
_080DB0E4: .4byte 0x0002D025
_080DB0E8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080DB0EE:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _080DB12C @ =0x0002D024
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DB134
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	beq _080DB160
	ldr r1, _080DB130 @ =0x0000C20E
	adds r0, r5, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r5, #0xd]
	b _080DB3FC
	.align 2, 0
_080DB12C: .4byte 0x0002D024
_080DB130: .4byte 0x0000C20E
_080DB134:
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bne _080DB160
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080DB15C @ =Collision_ARRAY_083713e0
	bl SetDDP
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	movs r0, #9
	strb r0, [r5, #0xd]
	b _080DB3FC
	.align 2, 0
_080DB15C: .4byte Collision_ARRAY_083713e0
_080DB160:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	bne _080DB172
	b _080DB3FC
_080DB172:
	ldr r0, _080DB1AC @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DB17C
	b _080DB3FC
_080DB17C:
	ldr r0, _080DB1B0 @ =gCollisionManager
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	beq _080DB190
	b _080DB3FC
_080DB190:
	ldr r1, _080DB1B4 @ =gCurStory
	ldrb r2, [r1, #6]
	movs r0, #0xc
	ands r0, r2
	cmp r0, #4
	bne _080DB1C0
	movs r0, #8
	orrs r0, r2
	strb r0, [r1, #6]
	ldr r0, _080DB1B8 @ =gGameState
	ldr r1, _080DB1BC @ =0x000D0400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB1AC: .4byte gInChat
_080DB1B0: .4byte gCollisionManager
_080DB1B4: .4byte gCurStory
_080DB1B8: .4byte gGameState
_080DB1BC: .4byte 0x000D0400
_080DB1C0:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080DB1E4
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _080DB1E4
	ldr r0, _080DB1DC @ =gGameState
	ldr r1, _080DB1E0 @ =0x000B0400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB1DC: .4byte gGameState
_080DB1E0: .4byte 0x000B0400
_080DB1E4:
	adds r3, r1, #0
	ldrb r2, [r3, #5]
	movs r0, #0x60
	ands r0, r2
	cmp r0, #0x20
	bne _080DB208
	movs r0, #0x40
	orrs r0, r2
	strb r0, [r3, #5]
	ldr r0, _080DB200 @ =gGameState
	ldr r1, _080DB204 @ =0x000A0400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB200: .4byte gGameState
_080DB204: .4byte 0x000A0400
_080DB208:
	movs r0, #0x30
	ands r0, r2
	cmp r0, #0x10
	bne _080DB224
	ldr r0, _080DB21C @ =gGameState
	ldr r1, _080DB220 @ =0x00090400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB21C: .4byte gGameState
_080DB220: .4byte 0x00090400
_080DB224:
	movs r0, #0x18
	ands r0, r2
	cmp r0, #8
	bne _080DB240
	ldr r0, _080DB238 @ =gGameState
	ldr r1, _080DB23C @ =0x00080400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB238: .4byte gGameState
_080DB23C: .4byte 0x00080400
_080DB240:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	bne _080DB260
	movs r0, #1
	orrs r0, r2
	strb r0, [r3, #5]
	ldr r0, _080DB258 @ =gGameState
	ldr r1, _080DB25C @ =0x00040400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB258: .4byte gGameState
_080DB25C: .4byte 0x00040400
_080DB260:
	movs r0, #6
	ands r0, r2
	cmp r0, #2
	bne _080DB280
	movs r0, #4
	orrs r0, r2
	strb r0, [r1, #5]
	ldr r0, _080DB278 @ =gGameState
	ldr r1, _080DB27C @ =0x00050400
	bl SetGameMode
	b _080DB28A
	.align 2, 0
_080DB278: .4byte gGameState
_080DB27C: .4byte 0x00050400
_080DB280:
	ldr r0, _080DB298 @ =gGameState
	movs r1, #0x81
	lsls r1, r1, #0xa
	bl SetGameMode
_080DB28A:
	ldr r1, _080DB29C @ =0x0000C206
_080DB28C:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	b _080DB3F0
	.align 2, 0
_080DB298: .4byte gGameState
_080DB29C: .4byte 0x0000C206
_080DB2A0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080DB2D0 @ =gOverworld
	ldr r1, _080DB2D4 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DB2D8
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bne _080DB2D8
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	movs r0, #4
	strb r0, [r5, #0xd]
	b _080DB3FC
	.align 2, 0
_080DB2D0: .4byte gOverworld
_080DB2D4: .4byte 0x0002D024
_080DB2D8:
	ldr r0, _080DB2E8 @ =gGameState
	ldrb r1, [r0, #2]
	cmp r1, #0
	beq _080DB2E2
	b _080DB3FC
_080DB2E2:
	ldr r0, _080DB2EC @ =gInChat
	strb r1, [r0]
	b _080DB306
	.align 2, 0
_080DB2E8: .4byte gGameState
_080DB2EC: .4byte gInChat
_080DB2F0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	adds r0, #0x8b
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	cmp r1, r0
	ble _080DB304
	b _080DB3FC
_080DB304:
	str r1, [r5, #0x54]
_080DB306:
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r5, #0xd]
	b _080DB3FC
_080DB316:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080DB3FC
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_080DB346:
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	b _080DB3F0
_080DB34E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB3FC
	ldr r1, _080DB364 @ =0x0000C20E
	b _080DB28C
	.align 2, 0
_080DB364: .4byte 0x0000C20E
_080DB368:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	subs r0, #0x8b
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	ldr r2, _080DB38C @ =0xFFFFE800
	adds r1, r1, r2
	cmp r1, r0
	blt _080DB3FC
	str r1, [r5, #0x54]
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	b _080DB346
	.align 2, 0
_080DB38C: .4byte 0xFFFFE800
_080DB390:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB3FC
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _080DB346
_080DB3C6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB3FC
	ldr r1, _080DB3EC @ =0x0000C206
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xd]
	cmp r0, #8
	bne _080DB3F0
	movs r0, #2
	strb r0, [r5, #0xd]
	b _080DB3FC
	.align 2, 0
_080DB3EC: .4byte 0x0000C206
_080DB3F0:
	adds r0, #1
	strb r0, [r5, #0xd]
	b _080DB3FC
_080DB3F6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080DB3FC:
	pop {r4, r5}
	pop {r0}
	bx r0
