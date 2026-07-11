#include "game.h"
#include "global.h"
#include "text.h"

s16 save_080f32f8(struct GameState*);
void PrintSaveDataRow(s32 idx, u8 rank, u32 playTime, u8 lap, u8 mode, u8 y8);

// DEKASUGI!!!
// 0x080f0658
NAKED void OverworldLoop_ManageSaveData(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #3]\n\
	subs r0, #0x3f\n\
	cmp r0, #0x37\n\
	bls _080F0672\n\
	bl _RETURN\n\
_080F0672:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F067C @ =_080F0680\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F067C: .4byte _080F0680\n\
_080F0680: @ jump table\n\
	.4byte _080F0760 @ case 0\n\
	.4byte _080F0780 @ case 1\n\
	.4byte _080F07A0 @ case 2\n\
	.4byte _080F07F4 @ case 3\n\
	.4byte _080F080C @ case 4\n\
	.4byte _080F08B0 @ case 5\n\
	.4byte _080F08C2 @ case 6\n\
	.4byte _080F0C74 @ case 7\n\
	.4byte _080F0C84 @ case 8\n\
	.4byte _080F0D20 @ case 9\n\
	.4byte _080F07FC @ case 10\n\
	.4byte _080F080C @ case 11\n\
	.4byte _080F08B0 @ case 12\n\
	.4byte _080F08C2 @ case 13\n\
	.4byte _080F0D4C @ case 14\n\
	.4byte _080F0D5C @ case 15\n\
	.4byte _080F0DE0 @ case 16\n\
	.4byte _080F0E36 @ case 17\n\
	.4byte _080F0E7C @ case 18\n\
	.4byte _080F0804 @ case 19\n\
	.4byte _080F080C @ case 20\n\
	.4byte _080F08B0 @ case 21\n\
	.4byte _080F08C2 @ case 22\n\
	.4byte _080F0FE0 @ case 23\n\
	.4byte _080F0FF0 @ case 24\n\
	.4byte _RETURN @ case 25\n\
	.4byte _RETURN @ case 26\n\
	.4byte _RETURN @ case 27\n\
	.4byte _RETURN @ case 28\n\
	.4byte _RETURN @ case 29\n\
	.4byte _RETURN @ case 30\n\
	.4byte _RETURN @ case 31\n\
	.4byte _RETURN @ case 32\n\
	.4byte _080F07FC @ case 33\n\
	.4byte _080F080C @ case 34\n\
	.4byte _080F08B0 @ case 35\n\
	.4byte _080F08C2 @ case 36\n\
	.4byte _080F0D4C @ case 37\n\
	.4byte _080F0D5C @ case 38\n\
	.4byte _080F0DE0 @ case 39\n\
	.4byte _080F0E36 @ case 40\n\
	.4byte _080F0E7C @ case 41\n\
	.4byte _080F106A @ case 42\n\
	.4byte _RETURN @ case 43\n\
	.4byte _RETURN @ case 44\n\
	.4byte _RETURN @ case 45\n\
	.4byte _RETURN @ case 46\n\
	.4byte _RETURN @ case 47\n\
	.4byte _RETURN @ case 48\n\
	.4byte _080F07F4 @ case 49\n\
	.4byte _080F080C @ case 50\n\
	.4byte _080F08B0 @ case 51\n\
	.4byte _080F08C2 @ case 52\n\
	.4byte _080F0C74 @ case 53\n\
	.4byte _080F0C84 @ case 54\n\
	.4byte _080F0D20 @ case 55\n\
_080F0760:\n\
	ldr r2, _080F0774 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F0778\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	bl _RETURN\n\
	.align 2, 0\n\
_080F0774: .4byte gTextWindow+8\n\
_080F0778:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	bl _080f0fd4\n\
_080F0780:\n\
	ldr r0, _080F07D4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F0790\n\
	cmp r0, #4\n\
	beq _080F0790\n\
	bl _RETURN\n\
_080F0790:\n\
	movs r0, #2\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F07A0:\n\
	ldr r0, _080F07D4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F07B0\n\
	cmp r0, #4\n\
	beq _080F07B0\n\
	bl _RETURN\n\
_080F07B0:\n\
	adds r0, r6, #0\n\
	bl save_080f32f8\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F07C2\n\
	bl _RETURN\n\
_080F07C2:\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _080F07D8\n\
	movs r0, #0x42\n\
	strb r0, [r6, #3]\n\
	bl _RETURN\n\
	.align 2, 0\n\
_080F07D4: .4byte gTextWindow+8\n\
_080F07D8:\n\
	cmp r0, #2\n\
	bne _080F07E4\n\
	movs r0, #0x49\n\
	strb r0, [r6, #3]\n\
	bl _RETURN\n\
_080F07E4:\n\
	cmp r0, #3\n\
	bne _080F07EC\n\
	bl _080F1064\n\
_080F07EC:\n\
	movs r0, #0x3f\n\
	strb r0, [r6, #3]\n\
	bl _RETURN\n\
_080F07F4:\n\
	movs r0, #3\n\
	bl PrintOptionMessage1\n\
	b _080F0DC0\n\
_080F07FC:\n\
	movs r0, #5\n\
	bl PrintOptionMessage1\n\
	b _080F0DC0\n\
_080F0804:\n\
	movs r0, #7\n\
	bl PrintOptionMessage1\n\
	b _080F0DC0\n\
_080F080C:\n\
	movs r4, #0\n\
	ldr r0, _080F083C @ =gSaveSlotMetadata\n\
	mov sl, r0\n\
	ldr r7, _080F0840 @ =0x0200055C\n\
	ldr r1, _080F0844 @ =0xFFFFFE4C\n\
	adds r1, r1, r7\n\
	mov sb, r1\n\
_080F081A:\n\
	lsls r0, r4, #0x18\n\
	lsrs r5, r0, #0x18\n\
	adds r0, r5, #0\n\
	movs r1, #0x94\n\
	lsls r1, r1, #2\n\
	bl ValidateSector\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _080F0848\n\
	lsls r1, r4, #0x10\n\
	asrs r0, r1, #0x10\n\
	add r0, sl\n\
	strb r2, [r0]\n\
	mov r8, r1\n\
	b _080F089C\n\
	.align 2, 0\n\
_080F083C: .4byte gSaveSlotMetadata\n\
_080F0840: .4byte 0x0200055C\n\
_080F0844: .4byte 0xFFFFFE4C\n\
_080F0848:\n\
	lsls r4, r4, #0x10\n\
	asrs r0, r4, #0x10\n\
	add r0, sl\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	adds r0, r5, #0\n\
	ldr r1, _080F09CC @ =SaveState_020003a8\n\
	movs r2, #0x94\n\
	lsls r2, r2, #2\n\
	bl sram_08003378\n\
	mov r8, r4\n\
	ldr r4, _080F09D0 @ =gSramState\n\
_080F0862:\n\
	bl UpdateSram\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	beq _080F0862\n\
	movs r2, #0x1e\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #0\n\
	beq _080F0862\n\
	ldr r1, _080F09D4 @ =0x02000600\n\
	mov r5, r8\n\
	asrs r3, r5, #0x10\n\
	lsls r2, r3, #2\n\
	adds r1, r2, r1\n\
	ldr r0, [r7, #0xc]\n\
	str r0, [r1]\n\
	ldr r0, _080F09D8 @ =0x02000618\n\
	adds r2, r2, r0\n\
	ldrb r0, [r7, #1]\n\
	str r0, [r2]\n\
	ldr r0, _080F09DC @ =0x0200062C\n\
	adds r0, r3, r0\n\
	mov r2, sb\n\
	ldrh r1, [r2]\n\
	strb r1, [r0]\n\
	ldr r0, _080F09E0 @ =0x02000634\n\
	adds r3, r3, r0\n\
	ldrh r0, [r2, #2]\n\
	strb r0, [r3]\n\
_080F089C:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	add r0, r8\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #4\n\
	ble _080F081A\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F08B0:\n\
	movs r0, #0\n\
	strh r0, [r6, #4]\n\
	strh r0, [r6, #6]\n\
	strh r0, [r6, #8]\n\
	movs r0, #0xf\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F08C2:\n\
	ldr r0, _080F09E4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F08D2\n\
	cmp r0, #4\n\
	beq _080F08D2\n\
	bl _RETURN\n\
_080F08D2:\n\
	movs r5, #4\n\
	ldrsh r0, [r6, r5]\n\
	cmp r0, #3\n\
	bgt _080F08F2\n\
	ldr r0, _080F09E8 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F08F2\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r6, #4]\n\
	adds r0, #1\n\
	strh r0, [r6, #4]\n\
_080F08F2:\n\
	movs r1, #4\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0\n\
	ble _080F0912\n\
	ldr r0, _080F09E8 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F0912\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r6, #4]\n\
	subs r0, #1\n\
	strh r0, [r6, #4]\n\
_080F0912:\n\
	ldrh r3, [r6, #4]\n\
	movs r2, #4\n\
	ldrsh r1, [r6, r2]\n\
	movs r5, #6\n\
	ldrsh r0, [r6, r5]\n\
	adds r2, r3, #0\n\
	cmp r1, r0\n\
	bge _080F0924\n\
	strh r2, [r6, #6]\n\
_080F0924:\n\
	movs r0, #4\n\
	ldrsh r1, [r6, r0]\n\
	movs r2, #6\n\
	ldrsh r0, [r6, r2]\n\
	adds r0, #1\n\
	cmp r1, r0\n\
	ble _080F0936\n\
	subs r0, r3, #1\n\
	strh r0, [r6, #6]\n\
_080F0936:\n\
	movs r4, #0\n\
_080F0938:\n\
	lsls r0, r4, #0x10\n\
	asrs r5, r0, #0x10\n\
	movs r2, #6\n\
	ldrsh r1, [r6, r2]\n\
	subs r1, r5, r1\n\
	lsls r1, r1, #0x19\n\
	lsrs r1, r1, #0x18\n\
	mov ip, r1\n\
	lsls r7, r1, #0x18\n\
	lsrs r1, r7, #0x18\n\
	mov r8, r0\n\
	cmp r1, #2\n\
	bhi _080F0A26\n\
	ldr r0, _080F09EC @ =gSaveSlotMetadata\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F09F8\n\
	ldr r1, _080F09F0 @ =StringOfsTable\n\
	adds r0, r5, #0\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F09F4 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r1, _080F09E4 @ =gTextWindow+8\n\
	ldrb r0, [r1, #6]\n\
	cmp r0, #0\n\
	bne _080F097C\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #1\n\
	bne _080F097E\n\
_080F097C:\n\
	movs r2, #1\n\
_080F097E:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #9\n\
	subs r1, r1, r0\n\
	ldr r5, _080F09E4 @ =gTextWindow+8\n\
	mov r0, ip\n\
	lsls r4, r0, #0x18\n\
	asrs r2, r4, #0x18\n\
	adds r2, #2\n\
	ldrb r0, [r5, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldr r0, _080F09F0 @ =StringOfsTable\n\
	ldrh r1, [r0, #2]\n\
	ldr r0, _080F09F4 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r1, #0\n\
	ldrb r0, [r5, #6]\n\
	cmp r0, #0\n\
	bne _080F09B0\n\
	ldrb r0, [r5, #4]\n\
	cmp r0, #1\n\
	bne _080F09B2\n\
_080F09B0:\n\
	movs r1, #1\n\
_080F09B2:\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	movs r1, #0xb\n\
	subs r1, r1, r0\n\
	ldr r0, _080F09E4 @ =gTextWindow+8\n\
	asrs r2, r4, #0x18\n\
	adds r2, #2\n\
	ldrb r0, [r0, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	b _080F0A26\n\
	.align 2, 0\n\
_080F09CC: .4byte SaveState_020003a8\n\
_080F09D0: .4byte gSramState\n\
_080F09D4: .4byte 0x02000600\n\
_080F09D8: .4byte 0x02000618\n\
_080F09DC: .4byte 0x0200062C\n\
_080F09E0: .4byte 0x02000634\n\
_080F09E4: .4byte gTextWindow+8\n\
_080F09E8: .4byte gJoypad\n\
_080F09EC: .4byte gSaveSlotMetadata\n\
_080F09F0: .4byte StringOfsTable\n\
_080F09F4: .4byte gStringData\n\
_080F09F8:\n\
	lsls r0, r4, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r1, _080F0B00 @ =0x02000618\n\
	lsls r3, r5, #2\n\
	adds r1, r3, r1\n\
	ldrb r1, [r1]\n\
	ldr r2, _080F0B04 @ =0x02000600\n\
	adds r3, r3, r2\n\
	ldr r2, [r3]\n\
	ldr r3, _080F0B08 @ =0x0200062C\n\
	adds r3, r5, r3\n\
	ldrb r3, [r3]\n\
	ldr r4, _080F0B0C @ =0x02000634\n\
	adds r4, r5, r4\n\
	ldrb r4, [r4]\n\
	str r4, [sp]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r4, r7, r5\n\
	lsrs r4, r4, #0x18\n\
	str r4, [sp, #4]\n\
	bl PrintSaveDataRow\n\
_080F0A26:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	add r0, r8\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #4\n\
	bgt _080F0A36\n\
	b _080F0938\n\
_080F0A36:\n\
	ldr r0, _080F0B10 @ =StringOfsTable\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F0B14 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F0B18 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0A50\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0A52\n\
_080F0A50:\n\
	movs r2, #1\n\
_080F0A52:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	movs r0, #4\n\
	ldrsh r2, [r6, r0]\n\
	movs r5, #6\n\
	ldrsh r0, [r6, r5]\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, #2\n\
	ldrb r0, [r4, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r6, #8]\n\
	adds r0, #1\n\
	strh r0, [r6, #8]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F0A82\n\
	b _080F0B84\n\
_080F0A82:\n\
	movs r2, #0\n\
	ldrb r0, [r4, #6]\n\
	cmp r0, #0\n\
	bne _080F0A90\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0A92\n\
_080F0A90:\n\
	movs r2, #1\n\
_080F0A92:\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	movs r0, #8\n\
	subs r0, r0, r1\n\
	cmp r0, #3\n\
	ble _080F0B24\n\
	movs r1, #6\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0\n\
	beq _080F0ACE\n\
	ldr r3, _080F0B1C @ =Unicode_CursorUp\n\
	movs r2, #0\n\
	ldr r0, _080F0B18 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0ABA\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0ABC\n\
_080F0ABA:\n\
	movs r2, #1\n\
_080F0ABC:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #2\n\
	adds r0, r3, #0\n\
	bl PrintJISString\n\
_080F0ACE:\n\
	movs r2, #6\n\
	ldrsh r0, [r6, r2]\n\
	cmp r0, #3\n\
	beq _080F0B84\n\
	ldr r3, _080F0B20 @ =Unicode_CursorDown\n\
	movs r2, #0\n\
	ldr r0, _080F0B18 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0AEA\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0AEC\n\
_080F0AEA:\n\
	movs r2, #1\n\
_080F0AEC:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #5\n\
	adds r0, r3, #0\n\
	bl PrintJISString\n\
	b _080F0B84\n\
	.align 2, 0\n\
_080F0B00: .4byte 0x02000618\n\
_080F0B04: .4byte 0x02000600\n\
_080F0B08: .4byte 0x0200062C\n\
_080F0B0C: .4byte 0x02000634\n\
_080F0B10: .4byte StringOfsTable\n\
_080F0B14: .4byte gStringData\n\
_080F0B18: .4byte gTextWindow+8\n\
_080F0B1C: .4byte Unicode_CursorUp\n\
_080F0B20: .4byte Unicode_CursorDown\n\
_080F0B24:\n\
	movs r5, #6\n\
	ldrsh r0, [r6, r5]\n\
	cmp r0, #0\n\
	beq _080F0B54\n\
	ldr r3, _080F0B94 @ =Unicode_CursorUp\n\
	movs r2, #0\n\
	ldr r0, _080F0B98 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0B40\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0B42\n\
_080F0B40:\n\
	movs r2, #1\n\
_080F0B42:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #7\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #2\n\
	adds r0, r3, #0\n\
	bl PrintJISString\n\
_080F0B54:\n\
	movs r1, #6\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #3\n\
	beq _080F0B84\n\
	ldr r3, _080F0B9C @ =Unicode_CursorDown\n\
	movs r2, #0\n\
	ldr r0, _080F0B98 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0B70\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0B72\n\
_080F0B70:\n\
	movs r2, #1\n\
_080F0B72:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #7\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #5\n\
	adds r0, r3, #0\n\
	bl PrintJISString\n\
_080F0B84:\n\
	ldrh r1, [r6, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r6, r2]\n\
	cmp r0, #0\n\
	beq _080F0BA0\n\
	subs r0, r1, #1\n\
	strh r0, [r6, #0xa]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0B94: .4byte Unicode_CursorUp\n\
_080F0B98: .4byte gTextWindow+8\n\
_080F0B9C: .4byte Unicode_CursorDown\n\
_080F0BA0:\n\
	ldr r0, _080F0BCC @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r4, #2\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F0BE0\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0x63\n\
	bne _080F0BD4\n\
	ldr r0, _080F0BD0 @ =gStageRun\n\
	movs r5, #0xaa\n\
	lsls r5, r5, #1\n\
	adds r0, r0, r5\n\
	str r4, [r0]\n\
	movs r0, #0x69\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0BCC: .4byte gJoypad\n\
_080F0BD0: .4byte gStageRun\n\
_080F0BD4:\n\
	cmp r0, #0x73\n\
	beq _080F0BDA\n\
	b _080F1050\n\
_080F0BDA:\n\
	movs r0, #0x7c\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
_080F0BE0:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F0BEA\n\
	b _RETURN\n\
_080F0BEA:\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0x45\n\
	beq _080F0BF4\n\
	cmp r0, #0x73\n\
	bne _080F0C52\n\
_080F0BF4:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	ldr r0, _080F0C38 @ =gSaveSlotMetadata\n\
	movs r2, #4\n\
	ldrsh r1, [r6, r2]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080F0C0A\n\
	b _080F0DC0\n\
_080F0C0A:\n\
	ldr r5, _080F0C3C @ =0x00006270\n\
	adds r0, r6, r5\n\
	bl StoreStoryData\n\
	ldr r1, _080F0C40 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r0, [r0]\n\
	ldr r2, _080F0C44 @ =0x00006460\n\
	adds r1, r6, r2\n\
	bl StoreZeroStatus\n\
	ldrb r0, [r6, #4]\n\
	ldr r1, _080F0C48 @ =gGameState+0x625C\n\
	movs r2, #0x94\n\
	lsls r2, r2, #2\n\
	bl sram_08003330\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0x45\n\
	bne _080F0C4C\n\
	movs r0, #0x48\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0C38: .4byte gSaveSlotMetadata\n\
_080F0C3C: .4byte 0x00006270\n\
_080F0C40: .4byte 0x000064AC\n\
_080F0C44: .4byte 0x00006460\n\
_080F0C48: .4byte gGameState+0x625C\n\
_080F0C4C:\n\
	movs r0, #0x76\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
_080F0C52:\n\
	ldr r0, _080F0C68 @ =gSaveSlotMetadata\n\
	movs r5, #4\n\
	ldrsh r1, [r6, r5]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080F0C6C\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0C68: .4byte gSaveSlotMetadata\n\
_080F0C6C:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F0DC0\n\
_080F0C74:\n\
	movs r0, #4\n\
	bl PrintOptionMessage1\n\
	movs r0, #1\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F0C84:\n\
	ldr r1, _080F0D04 @ =StringOfsTable\n\
	movs r2, #4\n\
	ldrsh r0, [r6, r2]\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F0D08 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F0D0C @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0CA8\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0CAA\n\
_080F0CA8:\n\
	movs r2, #1\n\
_080F0CAA:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F0CC6\n\
	cmp r0, #4\n\
	beq _080F0CC6\n\
	b _RETURN\n\
_080F0CC6:\n\
	adds r0, r6, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F0CD6\n\
	b _RETURN\n\
_080F0CD6:\n\
	lsls r0, r4, #0x10\n\
	cmp r0, #0\n\
	bgt _080F0CDE\n\
	b _080F0DD8\n\
_080F0CDE:\n\
	ldr r5, _080F0D10 @ =0x00006270\n\
	adds r0, r6, r5\n\
	bl StoreStoryData\n\
	ldr r1, _080F0D14 @ =0x000064AC\n\
	adds r0, r6, r1\n\
	ldr r0, [r0]\n\
	ldr r2, _080F0D18 @ =0x00006460\n\
	adds r1, r6, r2\n\
	bl StoreZeroStatus\n\
	ldrb r0, [r6, #4]\n\
	ldr r1, _080F0D1C @ =gGameState+0x625C\n\
	movs r2, #0x94\n\
	lsls r2, r2, #2\n\
	bl sram_08003330\n\
	b _080F0DC0\n\
	.align 2, 0\n\
_080F0D04: .4byte StringOfsTable\n\
_080F0D08: .4byte gStringData\n\
_080F0D0C: .4byte gTextWindow+8\n\
_080F0D10: .4byte 0x00006270\n\
_080F0D14: .4byte 0x000064AC\n\
_080F0D18: .4byte 0x00006460\n\
_080F0D1C: .4byte gGameState+0x625C\n\
_080F0D20:\n\
	ldr r1, _080F0D48 @ =gSramState\n\
	ldrb r0, [r1]\n\
	cmp r0, #2\n\
	bne _080F0D2A\n\
	b _RETURN\n\
_080F0D2A:\n\
	movs r5, #0x1c\n\
	ldrsh r0, [r1, r5]\n\
	cmp r0, #0\n\
	bne _080F0D34\n\
	b _RETURN\n\
_080F0D34:\n\
	movs r0, #9\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0x48\n\
	bne _080F0D42\n\
	b _080F1050\n\
_080F0D42:\n\
	movs r0, #0x77\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0D48: .4byte gSramState\n\
_080F0D4C:\n\
	movs r0, #6\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F0D5C:\n\
	ldr r1, _080F0DC8 @ =StringOfsTable\n\
	movs r2, #4\n\
	ldrsh r0, [r6, r2]\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F0DCC @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F0DD0 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0D80\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0D82\n\
_080F0D80:\n\
	movs r2, #1\n\
_080F0D82:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F0D9E\n\
	cmp r0, #4\n\
	beq _080F0D9E\n\
	b _RETURN\n\
_080F0D9E:\n\
	adds r0, r6, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F0DAE\n\
	b _RETURN\n\
_080F0DAE:\n\
	lsls r0, r4, #0x10\n\
	cmp r0, #0\n\
	ble _080F0DD8\n\
	ldrb r0, [r6, #4]\n\
	ldr r1, _080F0DD4 @ =gGameState+0x625C\n\
	movs r2, #0x94\n\
	lsls r2, r2, #2\n\
	bl sram_08003378\n\
_080F0DC0:\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0DC8: .4byte StringOfsTable\n\
_080F0DCC: .4byte gStringData\n\
_080F0DD0: .4byte gTextWindow+8\n\
_080F0DD4: .4byte gGameState+0x625C\n\
_080F0DD8:\n\
	ldrb r0, [r6, #3]\n\
	subs r0, #5\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
_080F0DE0:\n\
	ldr r1, _080F0F00 @ =StringOfsTable\n\
	movs r5, #4\n\
	ldrsh r0, [r6, r5]\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F0F04 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F0F08 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F0E04\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F0E06\n\
_080F0E04:\n\
	movs r2, #1\n\
_080F0E06:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldr r1, _080F0F0C @ =gSramState\n\
	ldrb r0, [r1]\n\
	cmp r0, #1\n\
	bne _080F0E20\n\
	b _RETURN\n\
_080F0E20:\n\
	movs r2, #0x1e\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #0\n\
	bne _080F0E2A\n\
	b _RETURN\n\
_080F0E2A:\n\
	movs r0, #0xa\n\
	bl PrintOptionMessage2\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F0E36:\n\
	ldr r0, _080F0F08 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F0E44\n\
	cmp r0, #4\n\
	beq _080F0E44\n\
	b _RETURN\n\
_080F0E44:\n\
	ldr r5, _080F0F10 @ =0x00006260\n\
	adds r4, r6, r5\n\
	ldrb r0, [r4]\n\
	ldr r2, _080F0F14 @ =0x00006410\n\
	adds r1, r6, r2\n\
	bl ResetMissionScore\n\
	ldr r5, _080F0F18 @ =0x000064AC\n\
	adds r0, r6, r5\n\
	ldr r0, [r0]\n\
	ldr r2, _080F0F1C @ =0x00006460\n\
	adds r1, r6, r2\n\
	bl LoadZeroStatus\n\
	ldrb r0, [r4]\n\
	ldr r5, _080F0F20 @ =0x00006270\n\
	adds r1, r6, r5\n\
	bl LoadStoryData\n\
	ldr r0, _080F0F24 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F0E7C:\n\
	ldr r7, _080F0F24 @ =gStageRun\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #1\n\
	adds r5, r7, r2\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _080F0E98\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl FadeOutBGM\n\
	str r4, [r5]\n\
_080F0E98:\n\
	ldr r2, _080F0F08 @ =gTextWindow+8\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r5, #0xaa\n\
	lsls r5, r5, #1\n\
	adds r0, r7, r5\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F0EB0\n\
	b _RETURN\n\
_080F0EB0:\n\
	ldr r0, _080F0F28 @ =gScore\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r0, #0\n\
	bne _080F0F34\n\
	ldr r4, _080F0F2C @ =gCurStory\n\
	ldrb r2, [r4, #4]\n\
	movs r1, #0xf7\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	strb r0, [r4, #4]\n\
	ldr r2, _080F0F20 @ =0x00006270\n\
	adds r3, r6, r2\n\
	ldrb r2, [r3]\n\
	ands r1, r2\n\
	strb r1, [r3]\n\
	movs r2, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F0EDE\n\
	ldr r5, _080F0F30 @ =0x0000625C\n\
	adds r0, r6, r5\n\
	strh r2, [r0, #2]\n\
_080F0EDE:\n\
	ldrb r1, [r4, #4]\n\
	movs r3, #2\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F0EF0\n\
	ldr r1, _080F0F30 @ =0x0000625C\n\
	adds r0, r6, r1\n\
	strh r3, [r0, #2]\n\
_080F0EF0:\n\
	ldr r5, _080F0F10 @ =0x00006260\n\
	adds r0, r6, r5\n\
	strh r2, [r0]\n\
	movs r0, #1\n\
	bl InitStageRun\n\
	b _080F0FD0\n\
	.align 2, 0\n\
_080F0F00: .4byte StringOfsTable\n\
_080F0F04: .4byte gStringData\n\
_080F0F08: .4byte gTextWindow+8\n\
_080F0F0C: .4byte gSramState\n\
_080F0F10: .4byte 0x00006260\n\
_080F0F14: .4byte 0x00006410\n\
_080F0F18: .4byte 0x000064AC\n\
_080F0F1C: .4byte 0x00006460\n\
_080F0F20: .4byte 0x00006270\n\
_080F0F24: .4byte gStageRun\n\
_080F0F28: .4byte gScore\n\
_080F0F2C: .4byte gCurStory\n\
_080F0F30: .4byte 0x0000625C\n\
_080F0F34:\n\
	ldr r3, _080F0F60 @ =gCurStory\n\
	ldrb r2, [r3, #4]\n\
	movs r0, #8\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F0F6C\n\
	movs r1, #0xf7\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	strb r0, [r3, #4]\n\
	ldr r0, _080F0F64 @ =0x00006270\n\
	adds r2, r6, r0\n\
	ldrb r0, [r2]\n\
	ands r1, r0\n\
	strb r1, [r2]\n\
	ldr r1, _080F0F68 @ =0x00006260\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	bl InitStageRun\n\
	b _080F0FD0\n\
	.align 2, 0\n\
_080F0F60: .4byte gCurStory\n\
_080F0F64: .4byte 0x00006270\n\
_080F0F68: .4byte 0x00006260\n\
_080F0F6C:\n\
	ldrb r1, [r3, #5]\n\
	movs r0, #0x18\n\
	ands r0, r1\n\
	cmp r0, #8\n\
	bne _080F0F88\n\
	ldr r2, _080F0F84 @ =0x00006260\n\
	adds r0, r6, r2\n\
	movs r1, #0x11\n\
	strh r1, [r0]\n\
	movs r0, #0x11\n\
	movs r1, #0xa\n\
	b _080F0FCC\n\
	.align 2, 0\n\
_080F0F84: .4byte 0x00006260\n\
_080F0F88:\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0x10\n\
	bne _080F0FA4\n\
	ldr r5, _080F0FA0 @ =0x00006260\n\
	adds r0, r6, r5\n\
	movs r1, #0x11\n\
	strh r1, [r0]\n\
	movs r0, #0x11\n\
	movs r1, #0xe\n\
	b _080F0FCC\n\
	.align 2, 0\n\
_080F0FA0: .4byte 0x00006260\n\
_080F0FA4:\n\
	ldrb r1, [r3, #6]\n\
	movs r0, #0x14\n\
	ands r0, r1\n\
	cmp r0, #4\n\
	bne _080F0FC0\n\
	ldr r1, _080F0FBC @ =0x00006260\n\
	adds r0, r6, r1\n\
	movs r1, #0x11\n\
	strh r1, [r0]\n\
	movs r0, #0x11\n\
	b _080F0FCC\n\
	.align 2, 0\n\
_080F0FBC: .4byte 0x00006260\n\
_080F0FC0:\n\
	ldr r2, _080F0FDC @ =0x00006260\n\
	adds r0, r6, r2\n\
	movs r1, #0x11\n\
	strh r1, [r0]\n\
	movs r0, #0x11\n\
	movs r1, #2\n\
_080F0FCC:\n\
	bl LoadStageRun\n\
_080F0FD0:\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
_080f0fd4: @ 0x080F0FD4\n\
	adds r0, r6, #0\n\
	bl SetGameMode\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F0FDC: .4byte 0x00006260\n\
_080F0FE0:\n\
	movs r0, #8\n\
	bl PrintOptionMessage1\n\
	movs r0, #1\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F0FF0:\n\
	ldr r1, _080F1058 @ =StringOfsTable\n\
	movs r5, #4\n\
	ldrsh r0, [r6, r5]\n\
	adds r0, #0x1f\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F105C @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F1060 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F1014\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F1016\n\
_080F1014:\n\
	movs r2, #1\n\
_080F1016:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F1030\n\
	cmp r0, #4\n\
	bne _RETURN\n\
_080F1030:\n\
	adds r0, r6, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r0, #0\n\
	beq _RETURN\n\
	lsls r0, r4, #0x10\n\
	cmp r0, #0\n\
	ble _080F1064\n\
	ldrb r0, [r6, #4]\n\
	bl DeleteSector\n\
	movs r0, #0xb\n\
	bl PrintOptionMessage2\n\
_080F1050:\n\
	movs r0, #0x40\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
	.align 2, 0\n\
_080F1058: .4byte StringOfsTable\n\
_080F105C: .4byte gStringData\n\
_080F1060: .4byte gTextWindow+8\n\
_080F1064:\n\
	movs r0, #0x52\n\
	strb r0, [r6, #3]\n\
	b _RETURN\n\
_080F106A:\n\
	ldr r6, _080F10B0 @ =gStageRun\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _080F1086\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl FadeOutBGM\n\
	str r4, [r5]\n\
_080F1086:\n\
	ldr r2, _080F10B4 @ =gTextWindow+8\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _RETURN\n\
	bl ExitProcess\n\
_RETURN:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F10B0: .4byte gStageRun\n\
_080F10B4: .4byte gTextWindow+8\n\
 .syntax divided\n");
}
