#include "global.h"
#include "overworld.h"

static const struct Coord sSunkenLibRoom[24];

/*
checkpoint (0202fe62):
  00: ステージ読み込み中
  01: ブリーフィング
  02: スタートポイント
  03: データルーム
  04: データルーム(リトライ時用？)
  05: ボス部屋ガーダールーム
  06: ボス戦

StageEventPhase (0202ffdc):
  00: チェックポイントに応じた初期化処理
  01: ブリーフィング中
  02: ミッション開始後~検索ルームまで
      データのある部屋を決める乱数シードは毎フレーム変わる
      乱数シードから部屋を決める処理は次のフェーズ(3)に移行する直前に1度だけ実行される
  03:
  04: 検索ルーム~

データ検索処理は、 080f2620 で行われる
*/
NAKED s16 SunkenLib_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldr r5, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r7, r6, r0\n\
	ldrb r0, [r7]\n\
	cmp r0, #0\n\
	beq _0801F268\n\
	b _0801F3B0\n\
_0801F268:\n\
	ldr r2, _0801F2C4 @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r1, #1\n\
	orrs r1, r0\n\
	strh r1, [r2, #8]\n\
	ldr r5, _0801F2C8 @ =gCurStory\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #0xfb\n\
	ands r1, r0\n\
	strb r1, [r5, #4]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801F304\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801F2D4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F2CC @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	ldr r4, _0801F2D0 @ =gStageDiskManager\n\
	ldr r3, [r4]\n\
	ldrb r1, [r3, #2]\n\
	movs r2, #0xfd\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	strb r0, [r3, #2]\n\
	ldr r3, [r4]\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	ldr r3, [r4]\n\
	ldrb r1, [r3, #3]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r3, #3]\n\
	ldr r1, [r4]\n\
	ldrb r0, [r1, #4]\n\
	ands r2, r0\n\
	strb r2, [r1, #4]\n\
	b _0801F2E2\n\
	.align 2, 0\n\
_0801F2C4: .4byte gStageRun\n\
_0801F2C8: .4byte gCurStory\n\
_0801F2CC: .4byte gStageScriptList\n\
_0801F2D0: .4byte gStageDiskManager\n\
_0801F2D4:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F300 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x60]\n\
	bl SetScript\n\
_0801F2E2:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r2, #0xbf\n\
	lsls r2, r2, #1\n\
	adds r1, r6, r2\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r3, #0xbe\n\
	lsls r3, r3, #1\n\
	adds r1, r6, r3\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F300: .4byte gStageScriptList\n\
_0801F304:\n\
	cmp r4, #1\n\
	bne _0801F31C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F318 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _0801F3B4\n\
	.align 2, 0\n\
_0801F318: .4byte gStageScriptList\n\
_0801F31C:\n\
	cmp r4, #2\n\
	bne _0801F330\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F32C @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #8]\n\
	b _0801F372\n\
	.align 2, 0\n\
_0801F32C: .4byte gStageScriptList\n\
_0801F330:\n\
	cmp r4, #3\n\
	bne _0801F344\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F340 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x10]\n\
	b _0801F372\n\
	.align 2, 0\n\
_0801F340: .4byte gStageScriptList\n\
_0801F344:\n\
	cmp r4, #4\n\
	bne _0801F358\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F354 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x14]\n\
	b _0801F372\n\
	.align 2, 0\n\
_0801F354: .4byte gStageScriptList\n\
_0801F358:\n\
	cmp r4, #5\n\
	bne _0801F380\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0801F37C @ =gStageScriptList\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #1\n\
	adds r1, r6, r3\n\
	ldr r1, [r1]\n\
	ldr r2, [r2, #0x34]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1, #0x1c]\n\
_0801F372:\n\
	bl SetScript\n\
	strb r4, [r7]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F37C: .4byte gStageScriptList\n\
_0801F380:\n\
	cmp r4, #6\n\
	beq _0801F386\n\
	b _0801F6BE\n\
_0801F386:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0801F3AC @ =gStageScriptList\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #1\n\
	adds r1, r6, r3\n\
	ldr r1, [r1]\n\
	ldr r2, [r2, #0x34]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1, #0x4c]\n\
	bl SetScript\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #4]\n\
	strb r4, [r7]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F3AC: .4byte gStageScriptList\n\
_0801F3B0:\n\
	cmp r0, #1\n\
	bne _0801F3C0\n\
_0801F3B4:\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	strb r0, [r7]\n\
	b _0801F6BE\n\
_0801F3C0:\n\
	cmp r0, #2\n\
	bne _0801F450\n\
	ldr r4, _0801F404 @ =gStageRun\n\
	movs r0, #0xc8\n\
	lsls r0, r0, #1\n\
	adds r2, r4, r0\n\
	ldr r1, [r2]\n\
	ldr r0, _0801F408 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0801F40C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r0, r0, #1\n\
	str r0, [r2]\n\
	ldr r1, [r5, #0x54]\n\
	movs r0, #0xa5\n\
	lsls r0, r0, #0xd\n\
	cmp r1, r0\n\
	bgt _0801F3E8\n\
	b _0801F6BE\n\
_0801F3E8:\n\
	ldr r0, _0801F410 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801F418\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F414 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	b _0801F42E\n\
	.align 2, 0\n\
_0801F404: .4byte gStageRun\n\
_0801F408: .4byte 0x000343FD\n\
_0801F40C: .4byte 0x00269EC3\n\
_0801F410: .4byte gCurStory\n\
_0801F414: .4byte gStageScriptList\n\
_0801F418:\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F448 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x64]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801F44C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801F42E:\n\
	adds r0, r6, #0\n\
	bl calcSunkenLibDiskRoom\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r2, #0xbe\n\
	lsls r2, r2, #1\n\
	adds r1, r6, r2\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F448: .4byte gStageScriptList\n\
_0801F44C: .4byte 0x0000FFFE\n\
_0801F450:\n\
	cmp r0, #3\n\
	bne _0801F460\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #4\n\
	strb r0, [r7]\n\
	b _0801F6BE\n\
_0801F460:\n\
	cmp r0, #4\n\
	beq _0801F466\n\
	b _0801F600\n\
_0801F466:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r3, _0801F494 @ =0xFFEB0000\n\
	adds r2, r0, r3\n\
	ldr r1, _0801F498 @ =0x00002FFF\n\
	adds r3, r0, #0\n\
	cmp r2, r1\n\
	bhi _0801F4AC\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0801F49C @ =0x0001DFFF\n\
	cmp r1, r0\n\
	bgt _0801F4AC\n\
	ldr r0, _0801F4A0 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _0801F4CE\n\
	ldr r0, _0801F4A4 @ =gGameState\n\
	ldrb r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _0801F4CE\n\
	ldr r0, _0801F4A8 @ =0x00000F02\n\
	bl PrintOptionMessage1\n\
	b _0801F4CE\n\
	.align 2, 0\n\
_0801F494: .4byte 0xFFEB0000\n\
_0801F498: .4byte 0x00002FFF\n\
_0801F49C: .4byte 0x0001DFFF\n\
_0801F4A0: .4byte gTextWindow+8\n\
_0801F4A4: .4byte gGameState\n\
_0801F4A8: .4byte 0x00000F02\n\
_0801F4AC:\n\
	ldr r0, _0801F570 @ =0xFFEB6000\n\
	adds r1, r3, r0\n\
	ldr r0, _0801F574 @ =0x0000EFFF\n\
	cmp r1, r0\n\
	bhi _0801F4CE\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0801F578 @ =0x0001DFFF\n\
	cmp r1, r0\n\
	bgt _0801F4CE\n\
	ldr r2, _0801F57C @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _0801F4CE\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
_0801F4CE:\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, _0801F580 @ =0x0003BFFF\n\
	cmp r1, r0\n\
	bgt _0801F4D8\n\
	b _0801F6BE\n\
_0801F4D8:\n\
	ldr r1, [r5, #0x54]\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #0xc\n\
	cmp r1, r0\n\
	ble _0801F4E4\n\
	b _0801F6BE\n\
_0801F4E4:\n\
	movs r5, #0\n\
	movs r1, #0xbf\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrh r7, [r0]\n\
	movs r4, #1\n\
	ldr r2, _0801F584 @ =gStageDiskManager\n\
	mov r8, r2\n\
	ldr r3, _0801F588 @ =0x0834CE78\n\
	mov ip, r3\n\
_0801F4F8:\n\
	lsls r0, r5, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r0, r7, #0\n\
	asrs r0, r3\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _0801F526\n\
	mov r0, r8\n\
	ldr r1, [r0]\n\
	mov r2, ip\n\
	adds r0, r3, r2\n\
	ldrb r2, [r0]\n\
	lsrs r0, r2, #2\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	movs r0, #3\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	ands r1, r4\n\
	cmp r1, #0\n\
	bne _0801F532\n\
_0801F526:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _0801F4F8\n\
_0801F532:\n\
	movs r3, #0xbf\n\
	lsls r3, r3, #1\n\
	adds r2, r6, r3\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xf\n\
	bne _0801F598\n\
	ldr r2, _0801F58C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	ldr r0, _0801F590 @ =gStageRun+16\n\
	ldr r2, _0801F594 @ =gStageScriptList\n\
	adds r3, #2\n\
	adds r1, r6, r3\n\
	ldr r1, [r1]\n\
	ldr r2, [r2, #0x34]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F570: .4byte 0xFFEB6000\n\
_0801F574: .4byte 0x0000EFFF\n\
_0801F578: .4byte 0x0001DFFF\n\
_0801F57C: .4byte gTextWindow+8\n\
_0801F580: .4byte 0x0003BFFF\n\
_0801F584: .4byte gStageDiskManager\n\
_0801F588: .4byte gSunkenDataFileIdxs\n\
_0801F58C: .4byte gCurStory\n\
_0801F590: .4byte gStageRun+16\n\
_0801F594: .4byte gStageScriptList\n\
_0801F598:\n\
	lsls r0, r5, #0x10\n\
	asrs r4, r0, #0x10\n\
	cmp r4, #3\n\
	ble _0801F5A2\n\
	b _0801F6BE\n\
_0801F5A2:\n\
	movs r0, #1\n\
	lsls r0, r4\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	str r4, [r0]\n\
	ldr r0, _0801F5EC @ =0x0834CE7C\n\
	lsls r4, r4, #1\n\
	adds r0, r4, r0\n\
	ldrh r0, [r0]\n\
	movs r1, #0x5a\n\
	bl PrintTextWindow\n\
	ldr r0, _0801F5F0 @ =0x0834CE84\n\
	adds r0, r4, r0\n\
	ldrh r1, [r0]\n\
	movs r2, #0xb6\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	strh r1, [r0]\n\
	ldr r0, _0801F5F4 @ =0x0834CE8C\n\
	adds r4, r4, r0\n\
	ldrh r0, [r4]\n\
	movs r3, #0xb7\n\
	lsls r3, r3, #1\n\
	adds r1, r6, r3\n\
	strh r0, [r1]\n\
	ldr r0, _0801F5F8 @ =gStageRun+16\n\
	ldr r1, _0801F5FC @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F5EC: .4byte gSunkenDataTextIDs\n\
_0801F5F0: .4byte u16_ARRAY_0834ce84\n\
_0801F5F4: .4byte u16_ARRAY_0834ce8c\n\
_0801F5F8: .4byte gStageRun+16\n\
_0801F5FC: .4byte gStageScriptList\n\
_0801F600:\n\
	cmp r0, #5\n\
	bne _0801F650\n\
	ldr r1, _0801F640 @ =s32_ARRAY_0834ce94\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #1\n\
	adds r0, r6, r2\n\
	ldr r0, [r0]\n\
	lsls r3, r0, #2\n\
	adds r1, r3, r1\n\
	ldr r2, [r5, #0x54]\n\
	ldr r0, [r1]\n\
	cmp r2, r0\n\
	blt _0801F650\n\
	ldr r0, _0801F644 @ =gStageRun+16\n\
	ldr r1, _0801F648 @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	adds r1, r3, r1\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	ldr r2, _0801F64C @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	strb r0, [r7]\n\
	b _0801F6BE\n\
	.align 2, 0\n\
_0801F640: .4byte s32_ARRAY_0834ce94\n\
_0801F644: .4byte gStageRun+16\n\
_0801F648: .4byte gStageScriptList\n\
_0801F64C: .4byte gCurStory\n\
_0801F650:\n\
	movs r3, #0xbe\n\
	lsls r3, r3, #1\n\
	adds r5, r6, r3\n\
	ldrb r0, [r5]\n\
	cmp r0, #6\n\
	beq _0801F6B4\n\
	cmp r0, #7\n\
	bne _0801F6BE\n\
	ldr r4, _0801F6A4 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801F6BE\n\
	ldr r1, _0801F6A8 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F6AC @ =gStageScriptList\n\
	ldr r1, [r1, #0x34]\n\
	ldr r1, [r1, #0x5c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801F6B0 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #8\n\
	b _0801F6BC\n\
	.align 2, 0\n\
_0801F6A4: .4byte gStageRun\n\
_0801F6A8: .4byte gCollisionManager\n\
_0801F6AC: .4byte gStageScriptList\n\
_0801F6B0: .4byte 0x0000FFEF\n\
_0801F6B4:\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #7\n\
_0801F6BC:\n\
	strb r0, [r5]\n\
_0801F6BE:\n\
	movs r0, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

s16 SunkenLib_FreeUpdate(struct StageRun* p) { return SunkenLib_MissionUpdate(p); }

NAKED struct Coord* getSunkenLibRoomCoord(u8 idx) {
  asm(".syntax unified\n\
	push {lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #7\n\
	bls _0801F6FC\n\
	ldr r0, _0801F6F4 @ =0x0202FFF4\n\
	adds r0, r1, r0\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #3\n\
	ldr r1, _0801F6F8 @ =sSunkenLibRoom\n\
	b _0801F706\n\
	.align 2, 0\n\
_0801F6F4: .4byte 0x0202FFF4\n\
_0801F6F8: .4byte sSunkenLibRoom\n\
_0801F6FC:\n\
	ldr r0, _0801F70C @ =0x0202FFF4\n\
	adds r0, r1, r0\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #3\n\
	ldr r1, _0801F710 @ =sSunkenLibRoom\n\
_0801F706:\n\
	adds r0, r0, r1\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801F70C: .4byte 0x0202FFF4\n\
_0801F710: .4byte sSunkenLibRoom\n\
 .syntax divided\n");
}

NAKED struct Coord* FUN_0801f714(struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	movs r4, #0\n\
	b _0801F71E\n\
_0801F71C:\n\
	adds r4, #1\n\
_0801F71E:\n\
	cmp r4, #0x17\n\
	bgt _0801F750\n\
	lsls r0, r4, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl getSunkenLibRoomCoord\n\
	adds r2, r0, #0\n\
	ldr r1, [r2]\n\
	ldr r0, [r5]\n\
	subs r1, r1, r0\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #5\n\
	adds r1, r1, r0\n\
	ldr r0, _0801F774 @ =0x00002FFF\n\
	cmp r1, r0\n\
	bhi _0801F71C\n\
	ldr r0, [r2, #4]\n\
	ldr r1, [r5, #4]\n\
	subs r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	ldr r1, _0801F778 @ =0x00001FFF\n\
	cmp r0, r1\n\
	bhi _0801F71C\n\
_0801F750:\n\
	cmp r4, #0x18\n\
	bne _0801F756\n\
	movs r4, #4\n\
_0801F756:\n\
	cmp r4, #3\n\
	ble _0801F784\n\
	subs r0, r4, #4\n\
	movs r1, #3\n\
	ands r0, r1\n\
	adds r4, r0, #4\n\
	ldr r1, _0801F77C @ =gMission\n\
	movs r0, #7\n\
	ldrsb r0, [r1, r0]\n\
	subs r0, #2\n\
	cmp r0, #0\n\
	ble _0801F780\n\
	ldrb r0, [r1, #7]\n\
	subs r0, #2\n\
	b _0801F782\n\
	.align 2, 0\n\
_0801F774: .4byte 0x00002FFF\n\
_0801F778: .4byte 0x00001FFF\n\
_0801F77C: .4byte gMission\n\
_0801F780:\n\
	movs r0, #0\n\
_0801F782:\n\
	strb r0, [r1, #7]\n\
_0801F784:\n\
	ldr r1, _0801F79C @ =gStageRun+392\n\
	ldr r0, [r5]\n\
	str r0, [r1]\n\
	ldr r0, [r5, #4]\n\
	str r0, [r1, #4]\n\
	lsls r0, r4, #3\n\
	ldr r1, _0801F7A0 @ =Coord_ARRAY_0834cea4\n\
	adds r0, r0, r1\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801F79C: .4byte gStageRun+392\n\
_0801F7A0: .4byte Coord_ARRAY_0834cea4\n\
 .syntax divided\n");
}

struct Coord* FUN_0801f7a4(struct Coord* _ UNUSED) { return (struct Coord*)&gStageRun.unk_188; }

NAKED void calcSunkenLibDiskRoom(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r0, _0801F82C @ =0x0202FFF4\n\
	movs r3, #0x17\n\
	adds r0, #0x17\n\
_0801F7B4:\n\
	strb r3, [r0]\n\
	subs r0, #1\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0801F7B4\n\
	ldr r5, _0801F830 @ =0x0202FFF0\n\
	adds r4, r5, #4\n\
	movs r3, #0x1f\n\
	ldr r7, _0801F834 @ =0x000343FD\n\
	ldr r6, _0801F838 @ =0x00269EC3\n\
_0801F7C8:\n\
	ldr r0, [r5]\n\
	muls r0, r7, r0\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #7\n\
	ands r0, r1\n\
	adds r0, r0, r4\n\
	ldrb r2, [r0]\n\
	ldrb r1, [r4]\n\
	strb r1, [r0]\n\
	strb r2, [r4]\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0801F7C8\n\
	ldr r6, _0801F83C @ =gStageRun\n\
	movs r0, #0xc8\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	movs r1, #0xce\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	movs r3, #0x1f\n\
	ldr r7, _0801F834 @ =0x000343FD\n\
_0801F7FC:\n\
	ldr r0, [r5]\n\
	muls r0, r7, r0\n\
	ldr r1, _0801F838 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	adds r0, r6, r0\n\
	movs r1, #0xce\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	ldrb r1, [r4]\n\
	strb r1, [r0]\n\
	strb r2, [r4]\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0801F7FC\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0801F82C: .4byte 0x0202FFF4\n\
_0801F830: .4byte 0x0202FFF0\n\
_0801F834: .4byte 0x000343FD\n\
_0801F838: .4byte 0x00269EC3\n\
_0801F83C: .4byte gStageRun\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
/*
  水没した図書館の部屋一覧の座標(SunkenLib data room coords)
    08 09 10 11 12 13
    14 00 01 02 03 15
    16 04 05 06 07 17
    18 19 20 21 22 23
*/
static const struct Coord sSunkenLibRoom[24] = {
  { 0x001A5000, 0x00031F00 }, { 0x001AA000, 0x00031F00 }, { 0x001AF000, 0x00031F00 }, { 0x001B4000, 0x00031F00 }, { 0x001A5000, 0x00035F00 }, { 0x001AA000, 0x00035F00 },
  { 0x001AF000, 0x00035F00 }, { 0x001B4000, 0x00035F00 }, { 0x001A0000, 0x0002DF00 }, { 0x001A5000, 0x0002DF00 }, { 0x001AA000, 0x0002DF00 }, { 0x001AF000, 0x0002DF00 },
  { 0x001B4000, 0x0002DF00 }, { 0x001B9000, 0x0002DF00 }, { 0x001A0000, 0x00031F00 }, { 0x001B9000, 0x00031F00 }, { 0x001A0000, 0x00035F00 }, { 0x001B9000, 0x00035F00 },
  { 0x001A0000, 0x00039F00 }, { 0x001A5000, 0x00039F00 }, { 0x001AA000, 0x00039F00 }, { 0x001AF000, 0x00039F00 }, { 0x001B4000, 0x00039F00 }, { 0x001B9000, 0x00039F00 },
};
// clang-format on

const disk_t gSunkenDataFileIdxs[4] = {
    DISK_ID(DISK_FILE_D),
    DISK_ID(DISK_FILE_K),
    DISK_ID(DISK_FILE_J),
    DISK_ID(DISK_FILE_L),
};

const TextID gSunkenDataTextIDs[4] = {
    0x0F11,
    0x0F12,
    0x0F13,
    0x0F14,
};

const TextID u16_ARRAY_0834ce84[4] = {
    0x0F15,
    0x0F17,
    0x0F19,
    0x0F1B,
};

const TextID u16_ARRAY_0834ce8c[4] = {
    0x0F16,
    0x0F18,
    0x0F1A,
    0x0F1C,
};

const s32 s32_ARRAY_0834ce94[4] = {
    0x1E000,
    0x78000,
    0x4B000,
    0xA5000,
};

// clang-format off
const struct Coord Coord_ARRAY_0834cea4[8] = {
    { 0x11000, 0x4E000},
    { 0x6B000, 0x4E000},
    { 0x3E000, 0x4E000},
    { 0x98000, 0x40000},
    { 0xC5000, 0x4E000},
    { 0xF2000, 0x40000},
    {0x11F000, 0x4E000},
    {0x14C000, 0x40000},
};
// clang-format on
