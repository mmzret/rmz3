#include "game.h"
#include "global.h"

NAKED void OverworldLoop_Computer(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #3]\n\
	cmp r0, #0x15\n\
	bls _080F2200\n\
	b _080F2616\n\
_080F2200:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F220C @ =_080F2210\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F220C: .4byte _080F2210\n\
_080F2210: @ jump table\n\
	.4byte _080F2268 @ case 0\n\
	.4byte _080F2274 @ case 1\n\
	.4byte _080F22AE @ case 2\n\
	.4byte _080F2332 @ case 3\n\
	.4byte _080F2346 @ case 4\n\
	.4byte _080F2374 @ case 5\n\
	.4byte _080F238E @ case 6\n\
	.4byte _080F23AC @ case 7\n\
	.4byte _080F23F8 @ case 8\n\
	.4byte _080F2424 @ case 9\n\
	.4byte _080F2474 @ case 10\n\
	.4byte _080F248A @ case 11\n\
	.4byte _080F24A0 @ case 12\n\
	.4byte _080F24AC @ case 13\n\
	.4byte _080F24D8 @ case 14\n\
	.4byte _080F24F0 @ case 15\n\
	.4byte _080F252C @ case 16\n\
	.4byte _080F254C @ case 17\n\
	.4byte _080F2564 @ case 18\n\
	.4byte _080F25AC @ case 19\n\
	.4byte _080F25C4 @ case 20\n\
	.4byte _080F2602 @ case 21\n\
_080F2268:\n\
	movs r0, #0x67\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F2274:\n\
	ldr r0, _080F22EC @ =gTextWindow+8\n\
	ldrh r1, [r0, #2]\n\
	adds r2, r0, #0\n\
	cmp r1, #3\n\
	bne _080F2292\n\
	ldr r0, _080F22F0 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F2292\n\
	ldrh r1, [r2]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
_080F2292:\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F229E\n\
	cmp r0, #4\n\
	beq _080F229E\n\
	b _080F2616\n\
_080F229E:\n\
	movs r0, #0x68\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F22AE:\n\
	ldr r0, _080F22EC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F22BC\n\
	cmp r0, #4\n\
	beq _080F22BC\n\
	b _080F2616\n\
_080F22BC:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F22CC\n\
	b _080F2616\n\
_080F22CC:\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F231C\n\
	ldr r2, _080F22F4 @ =gCurStory\n\
	ldrb r1, [r2, #5]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F22F8\n\
	movs r0, #0xa3\n\
	lsls r0, r0, #2\n\
	bl PrintOptionMessage2\n\
	b _080F2612\n\
	.align 2, 0\n\
_080F22EC: .4byte gTextWindow+8\n\
_080F22F0: .4byte gJoypad\n\
_080F22F4: .4byte gCurStory\n\
_080F22F8:\n\
	ldrb r1, [r2, #6]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F2310\n\
	ldr r0, _080F230C @ =0x0000028D\n\
	bl PrintOptionMessage2\n\
	b _080F2612\n\
	.align 2, 0\n\
_080F230C: .4byte 0x0000028D\n\
_080F2310:\n\
	ldr r0, _080F2318 @ =0x0000028E\n\
	bl PrintOptionMessage2\n\
	b _080F2612\n\
	.align 2, 0\n\
_080F2318: .4byte 0x0000028E\n\
_080F231C:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F2328\n\
	movs r0, #5\n\
	b _080F2614\n\
_080F2328:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	movs r0, #3\n\
	b _080F2614\n\
_080F2332:\n\
	ldr r0, _080F2358 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2340\n\
	cmp r0, #4\n\
	beq _080F2340\n\
	b _080F2616\n\
_080F2340:\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F2346:\n\
	ldr r2, _080F2358 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F235C\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F2616\n\
	.align 2, 0\n\
_080F2358: .4byte gTextWindow+8\n\
_080F235C:\n\
	ldr r0, _080F2370 @ =gGameState\n\
	movs r1, #1\n\
	str r1, [r0, #0xc]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r5, #0\n\
	bl SetGameMode\n\
	b _080F2616\n\
	.align 2, 0\n\
_080F2370: .4byte gGameState\n\
_080F2374:\n\
	ldr r0, _080F23D8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2382\n\
	cmp r0, #4\n\
	beq _080F2382\n\
	b _080F2616\n\
_080F2382:\n\
	movs r0, #0x69\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F238E:\n\
	ldr r0, _080F23D8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F239C\n\
	cmp r0, #4\n\
	beq _080F239C\n\
	b _080F2616\n\
_080F239C:\n\
	movs r0, #0x6a\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F23AC:\n\
	ldr r0, _080F23D8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F23BA\n\
	cmp r0, #4\n\
	beq _080F23BA\n\
	b _080F2616\n\
_080F23BA:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F23CA\n\
	b _080F2616\n\
_080F23CA:\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F23DC\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F23D8: .4byte gTextWindow+8\n\
_080F23DC:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F23E6\n\
	b _080F2612\n\
_080F23E6:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldr r1, _080F23F4 @ =gGameState\n\
	movs r0, #1\n\
	str r0, [r1, #0xc]\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F23F4: .4byte gGameState\n\
_080F23F8:\n\
	ldr r0, _080F241C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2406\n\
	cmp r0, #4\n\
	beq _080F2406\n\
	b _080F2616\n\
_080F2406:\n\
	movs r0, #0x6b\n\
	bl PrintOptionMessage1\n\
	ldr r1, _080F2420 @ =gGameState\n\
	movs r0, #0\n\
	str r0, [r1, #0xc]\n\
	bl FUN_0800104c\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F241C: .4byte gTextWindow+8\n\
_080F2420: .4byte gGameState\n\
_080F2424:\n\
	ldr r0, _080F2444 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F244C\n\
	movs r0, #3\n\
	bl PlaySound\n\
	bl DisableSerial\n\
	ldr r1, _080F2448 @ =gGameState\n\
	movs r0, #1\n\
	str r0, [r1, #0xc]\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F2444: .4byte gJoypad\n\
_080F2448: .4byte gGameState\n\
_080F244C:\n\
	bl FUN_08001134\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	bne _080F245A\n\
	b _080F2616\n\
_080F245A:\n\
	cmp r4, #2\n\
	bne _080F2462\n\
	movs r0, #0xc\n\
	b _080F2614\n\
_080F2462:\n\
	cmp r4, #4\n\
	bne _080F246A\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F246A:\n\
	cmp r4, #0x10\n\
	beq _080F2470\n\
	b _080F2616\n\
_080F2470:\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F2474:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	movs r0, #0x6d\n\
	bl PrintOptionMessage2\n\
	bl DisableSerial\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F248A:\n\
	ldr r0, _080F249C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _080F2494\n\
	b _080F2612\n\
_080F2494:\n\
	cmp r0, #4\n\
	beq _080F249A\n\
	b _080F2616\n\
_080F249A:\n\
	b _080F2612\n\
	.align 2, 0\n\
_080F249C: .4byte gTextWindow+8\n\
_080F24A0:\n\
	movs r0, #0x6c\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F24AC:\n\
	bl FUN_08001134\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	bl FUN_08000fb8\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080F24C6\n\
	bl DisableSerial\n\
	movs r0, #0xe\n\
	b _080F2614\n\
_080F24C6:\n\
	cmp r4, #4\n\
	bne _080F24CE\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F24CE:\n\
	cmp r4, #0x10\n\
	beq _080F24D4\n\
	b _080F2616\n\
_080F24D4:\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F24D8:\n\
	bl FUN_08001098\n\
	ldr r1, _080F24E8 @ =0x02030B54\n\
	ldr r0, _080F24EC @ =gSystemSavedataManager\n\
	ldr r0, [r0, #0x40]\n\
	str r0, [r1]\n\
	movs r0, #0xf\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F24E8: .4byte 0x02030B54\n\
_080F24EC: .4byte gSystemSavedataManager\n\
_080F24F0:\n\
	bl FUN_08001154\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	bne _080F24FE\n\
	b _080F2616\n\
_080F24FE:\n\
	cmp r4, #1\n\
	bne _080F2520\n\
	ldr r0, _080F2518 @ =gSystemSavedataManager\n\
	ldr r0, [r0, #0x40]\n\
	cmp r0, #0\n\
	bne _080F2514\n\
	ldr r0, _080F251C @ =0x020014C0\n\
	ldr r0, [r0, #0x14]\n\
	cmp r0, #0\n\
	bne _080F2514\n\
	b _080F2616\n\
_080F2514:\n\
	movs r0, #0x10\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F2518: .4byte gSystemSavedataManager\n\
_080F251C: .4byte 0x020014C0\n\
_080F2520:\n\
	cmp r4, #2\n\
	bne _080F2528\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F2528:\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F252C:\n\
	bl FUN_080011bc\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080F2616\n\
	cmp r4, #1\n\
	bne _080F2540\n\
	movs r0, #0x11\n\
	b _080F2614\n\
_080F2540:\n\
	cmp r4, #2\n\
	bne _080F2548\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F2548:\n\
	movs r0, #0xf\n\
	b _080F2614\n\
_080F254C:\n\
	bl FUN_08001210\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080F2616\n\
	cmp r4, #1\n\
	bne _080F2560\n\
	movs r0, #0x12\n\
	b _080F2614\n\
_080F2560:\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F2564:\n\
	bl FUN_08001264\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080F2616\n\
	cmp r4, #1\n\
	bne _080F25A8\n\
	movs r2, #0\n\
	ldr r3, _080F259C @ =gSystemSavedataManager\n\
	ldr r1, [r3, #0x40]\n\
	ldr r0, _080F25A0 @ =0x000032DA\n\
	cmp r1, r0\n\
	beq _080F2586\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r2, r0, #0x1f\n\
_080F2586:\n\
	strh r2, [r5, #4]\n\
	ldr r0, _080F25A4 @ =0x020014C0\n\
	ldrh r1, [r0, #0x14]\n\
	ldrh r0, [r0, #0x16]\n\
	lsls r0, r0, #9\n\
	orrs r1, r0\n\
	str r1, [r3, #0x40]\n\
	bl SaveSystemData\n\
	movs r0, #0x13\n\
	b _080F2614\n\
	.align 2, 0\n\
_080F259C: .4byte gSystemSavedataManager\n\
_080F25A0: .4byte 0x000032DA\n\
_080F25A4: .4byte 0x020014C0\n\
_080F25A8:\n\
	movs r0, #0xa\n\
	b _080F2614\n\
_080F25AC:\n\
	bl FUN_08001298\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080F2616\n\
	cmp r4, #1\n\
	bne _080F25C0\n\
	movs r0, #0x14\n\
	b _080F2614\n\
_080F25C0:\n\
	movs r0, #0x14\n\
	b _080F2614\n\
_080F25C4:\n\
	movs r0, #4\n\
	ldrsh r3, [r5, r0]\n\
	movs r2, #0\n\
	ldr r0, _080F25E8 @ =gSystemSavedataManager\n\
	ldr r1, [r0, #0x40]\n\
	ldr r0, _080F25EC @ =0x000032DA\n\
	cmp r1, r0\n\
	beq _080F25DA\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r2, r0, #0x1f\n\
_080F25DA:\n\
	cmp r3, r2\n\
	beq _080F25F0\n\
	movs r0, #0x6e\n\
	bl PrintOptionMessage2\n\
	b _080F25F6\n\
	.align 2, 0\n\
_080F25E8: .4byte gSystemSavedataManager\n\
_080F25EC: .4byte 0x000032DA\n\
_080F25F0:\n\
	movs r0, #0x6f\n\
	bl PrintOptionMessage2\n\
_080F25F6:\n\
	movs r0, #6\n\
	bl PlaySound\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F2602:\n\
	ldr r0, _080F261C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F260E\n\
	cmp r0, #4\n\
	bne _080F2616\n\
_080F260E:\n\
	bl DisableSerial\n\
_080F2612:\n\
	movs r0, #1\n\
_080F2614:\n\
	strb r0, [r5, #3]\n\
_080F2616:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F261C: .4byte gTextWindow+8\n\
 .syntax divided\n");
}
