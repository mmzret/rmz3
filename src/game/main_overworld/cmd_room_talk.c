#include "game.h"
#include "global.h"

static const u8 MissionBitfields_083861e8[MISSION_COUNT];
static const str_id_t StageNameIdxs[MISSION_COUNT];
static const TextID MissionSummaryTextIDs[MISSION_COUNT];
static const TextID MissionAskTextIDs[MISSION_COUNT];
static const u8 u8_ARRAY_0838623c[16];
static const TextID FreeRunStageTextIDs[FREE_STAGE_COUNT];
static const TextID FreeRunStageConfirmTextIDs[FREE_STAGE_COUNT];

NAKED void OverworldLoop_CmdRoomTalk(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x20\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #3]\n\
	cmp r0, #0x3f\n\
	bls _080F10CC\n\
	b _080F11DC\n\
_080F10CC:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F10D8 @ =_080F10DC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F10D8: .4byte _080F10DC\n\
_080F10DC: @ jump table\n\
	.4byte _080F11E6 @ case 0\n\
	.4byte _080F1204 @ case 1\n\
	.4byte _080F1252 @ case 2\n\
	.4byte _080F1268 @ case 3\n\
	.4byte _080F1286 @ case 4\n\
	.4byte _080F13A4 @ case 5\n\
	.4byte _080F149A @ case 6\n\
	.4byte _080F14CC @ case 7\n\
	.4byte _080F1644 @ case 8\n\
	.4byte _080F166C @ case 9\n\
	.4byte _080F179E @ case 10\n\
	.4byte _080F17BC @ case 11\n\
	.4byte _080F17E2 @ case 12\n\
	.4byte _080F183C @ case 13\n\
	.4byte _080F1854 @ case 14\n\
	.4byte _080F1A9E @ case 15\n\
	.4byte _080F1AB4 @ case 16\n\
	.4byte _080F1B06 @ case 17\n\
	.4byte _080F1B60 @ case 18\n\
	.4byte _080F1BE0 @ case 19\n\
	.4byte _080F1C18 @ case 20\n\
	.4byte _080F1C54 @ case 21\n\
	.4byte _080F1C78 @ case 22\n\
	.4byte _080F1CC0 @ case 23\n\
	.4byte _080F1D20 @ case 24\n\
	.4byte _080F1D40 @ case 25\n\
	.4byte _080F11DC @ case 26\n\
	.4byte _080F11DC @ case 27\n\
	.4byte _080F11DC @ case 28\n\
	.4byte _080F11DC @ case 29\n\
	.4byte _080F11DC @ case 30\n\
	.4byte _080F11DC @ case 31\n\
	.4byte _080F11DC @ case 32\n\
	.4byte _080F11DC @ case 33\n\
	.4byte _080F11DC @ case 34\n\
	.4byte _080F11DC @ case 35\n\
	.4byte _080F11DC @ case 36\n\
	.4byte _080F11DC @ case 37\n\
	.4byte _080F11DC @ case 38\n\
	.4byte _080F11DC @ case 39\n\
	.4byte _080F11DC @ case 40\n\
	.4byte _080F11DC @ case 41\n\
	.4byte _080F11DC @ case 42\n\
	.4byte _080F11DC @ case 43\n\
	.4byte _080F11DC @ case 44\n\
	.4byte _080F11DC @ case 45\n\
	.4byte _080F11DC @ case 46\n\
	.4byte _080F11DC @ case 47\n\
	.4byte _080F11DC @ case 48\n\
	.4byte _080F11DC @ case 49\n\
	.4byte _080F11DC @ case 50\n\
	.4byte _080F11DC @ case 51\n\
	.4byte _080F11DC @ case 52\n\
	.4byte _080F11DC @ case 53\n\
	.4byte _080F11DC @ case 54\n\
	.4byte _080F11DC @ case 55\n\
	.4byte _080F11DC @ case 56\n\
	.4byte _080F11DC @ case 57\n\
	.4byte _080F11DC @ case 58\n\
	.4byte _080F11DC @ case 59\n\
	.4byte _080F11DC @ case 60\n\
	.4byte _080F11DC @ case 61\n\
	.4byte _080F11DC @ case 62\n\
	.4byte _080F1268 @ case 63\n\
_080F11DC:\n\
	adds r0, r5, #0\n\
	bl OverworldLoop_ManageSaveData\n\
	bl _080F1D84\n\
_080F11E6:\n\
	ldr r0, _080F1238 @ =gCurStory\n\
	ldrb r1, [r0, #5]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F11F4\n\
	b _080F1396\n\
_080F11F4:\n\
	movs r0, #0\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F1204:\n\
	ldr r0, _080F123C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1214\n\
	cmp r0, #4\n\
	beq _080F1214\n\
	bl _080F1D84\n\
_080F1214:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F1226\n\
	bl _080F1D84\n\
_080F1226:\n\
	lsls r0, r2, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F1240\n\
	movs r0, #0xf\n\
	bl PrintOptionMessage1\n\
	bl _080F1D36\n\
	.align 2, 0\n\
_080F1238: .4byte gCurStory\n\
_080F123C: .4byte gTextWindow+8\n\
_080F1240:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F124A\n\
	b _080F1396\n\
_080F124A:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	b _080F1492\n\
_080F1252:\n\
	ldr r2, _080F1264 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F125C\n\
	b _080F17C4\n\
_080F125C:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	bl FUN_080f1cfe\n\
	.align 2, 0\n\
_080F1264: .4byte gTextWindow+8\n\
_080F1268:\n\
	ldr r0, _080F12B8 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1278\n\
	cmp r0, #4\n\
	beq _080F1278\n\
	bl _080F1D84\n\
_080F1278:\n\
	movs r0, #1\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
	movs r0, #4\n\
	strb r0, [r5, #3]\n\
_080F1286:\n\
	ldr r6, _080F12B8 @ =gTextWindow+8\n\
	ldrh r0, [r6, #2]\n\
	cmp r0, #0\n\
	beq _080F1296\n\
	cmp r0, #4\n\
	beq _080F1296\n\
	bl _080F1D84\n\
_080F1296:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F12A8\n\
	bl _080F1D84\n\
_080F12A8:\n\
	lsls r0, r2, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F12BC\n\
	movs r0, #0x40\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
	.align 2, 0\n\
_080F12B8: .4byte gTextWindow+8\n\
_080F12BC:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	beq _080F12C6\n\
	b _080F1492\n\
_080F12C6:\n\
	ldr r4, _080F12F4 @ =gCurStory\n\
	ldrb r2, [r4, #6]\n\
	movs r0, #0x30\n\
	ands r0, r2\n\
	cmp r0, #0x10\n\
	bne _080F1300\n\
	ldr r0, _080F12F8 @ =gStageRun+16\n\
	ldr r1, _080F12FC @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x4c]\n\
	bl SetScript\n\
	movs r0, #0x13\n\
	bl setStageCheckpoint\n\
	ldrh r1, [r6]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	movs r0, #0x19\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
	.align 2, 0\n\
_080F12F4: .4byte gCurStory\n\
_080F12F8: .4byte gStageRun+16\n\
_080F12FC: .4byte gStageScriptList\n\
_080F1300:\n\
	ldrb r1, [r4, #5]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1318\n\
	ldr r0, _080F1314 @ =0x00001305\n\
	bl PrintOptionMessage2\n\
	b _080F1396\n\
	.align 2, 0\n\
_080F1314: .4byte 0x00001305\n\
_080F1318:\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1340\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #0\n\
	bne _080F1334\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	bl PrintOptionMessage2\n\
	movs r0, #1\n\
	strb r0, [r4, #0xc]\n\
	b _080F1396\n\
_080F1334:\n\
	ldr r0, _080F133C @ =0x00000201\n\
	bl PrintOptionMessage2\n\
	b _080F1396\n\
	.align 2, 0\n\
_080F133C: .4byte 0x00000201\n\
_080F1340:\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F1368\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #1\n\
	bhi _080F135C\n\
	ldr r0, _080F1358 @ =0x00000202\n\
	bl PrintOptionMessage2\n\
	strb r6, [r4, #0xc]\n\
	b _080F1396\n\
	.align 2, 0\n\
_080F1358: .4byte 0x00000202\n\
_080F135C:\n\
	ldr r0, _080F1364 @ =0x00000203\n\
	bl PrintOptionMessage2\n\
	b _080F1396\n\
	.align 2, 0\n\
_080F1364: .4byte 0x00000203\n\
_080F1368:\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #2\n\
	bhi _080F137C\n\
	movs r0, #0x81\n\
	lsls r0, r0, #2\n\
	bl PrintOptionMessage2\n\
	movs r0, #3\n\
	strb r0, [r4, #0xc]\n\
	b _080F1396\n\
_080F137C:\n\
	cmp r0, #3\n\
	bhi _080F1390\n\
	ldr r0, _080F138C @ =0x00000205\n\
	bl PrintOptionMessage2\n\
	movs r0, #4\n\
	strb r0, [r4, #0xc]\n\
	b _080F1396\n\
	.align 2, 0\n\
_080F138C: .4byte 0x00000205\n\
_080F1390:\n\
	ldr r0, _080F13A0 @ =0x00000206\n\
	bl PrintOptionMessage2\n\
_080F1396:\n\
	movs r0, #3\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
	.align 2, 0\n\
_080F13A0: .4byte 0x00000206\n\
_080F13A4:\n\
	ldr r0, _080F13E4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F13B4\n\
	cmp r0, #4\n\
	beq _080F13B4\n\
	bl _080F1D84\n\
_080F13B4:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F13C6\n\
	bl _080F1D84\n\
_080F13C6:\n\
	lsls r0, r2, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	ble _080F1488\n\
	ldr r4, _080F13E8 @ =gCurStory\n\
	ldrb r1, [r4, #6]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F13EC\n\
	movs r0, #0x13\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
	.align 2, 0\n\
_080F13E4: .4byte gTextWindow+8\n\
_080F13E8: .4byte gCurStory\n\
_080F13EC:\n\
	movs r0, #0x14\n\
	ands r0, r1\n\
	cmp r0, #4\n\
	bne _080F13FC\n\
	ldr r0, _080F13F8 @ =0x00001344\n\
	b _080F1402\n\
	.align 2, 0\n\
_080F13F8: .4byte 0x00001344\n\
_080F13FC:\n\
	cmp r0, #0x14\n\
	bne _080F1414\n\
	ldr r0, _080F1410 @ =0x00001345\n\
_080F1402:\n\
	bl PrintOptionMessage2\n\
	movs r0, #0x18\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
	.align 2, 0\n\
_080F1410: .4byte 0x00001345\n\
_080F1414:\n\
	movs r0, #0x10\n\
	bl PrintOptionMessage2\n\
	ldrb r1, [r4, #5]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	rsbs r0, r0, #0\n\
	asrs r2, r0, #0x1f\n\
	movs r0, #4\n\
	ands r2, r0\n\
	ldrb r0, [r4, #6]\n\
	movs r3, #1\n\
	ands r3, r0\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1440\n\
	adds r0, r3, #3\n\
	adds r0, r2, r0\n\
	b _080F1444\n\
_080F1440:\n\
	adds r0, r2, #0\n\
	orrs r0, r3\n\
_080F1444:\n\
	strh r0, [r5, #6]\n\
	strh r0, [r5, #4]\n\
	ldr r1, _080F1470 @ =gCurStory\n\
	ldrb r3, [r1, #5]\n\
	movs r0, #8\n\
	ands r0, r3\n\
	movs r2, #3\n\
	cmp r0, #0\n\
	beq _080F1458\n\
	movs r2, #6\n\
_080F1458:\n\
	ldrb r0, [r1, #6]\n\
	movs r1, #1\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x80\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080F1474\n\
	adds r0, r1, #1\n\
	adds r0, r2, r0\n\
	b _080F1476\n\
	.align 2, 0\n\
_080F1470: .4byte gCurStory\n\
_080F1474:\n\
	adds r0, r2, r1\n\
_080F1476:\n\
	movs r1, #0\n\
	strh r0, [r5, #8]\n\
	ldr r2, _080F1484 @ =0x00000DCC\n\
	adds r0, r5, r2\n\
	str r1, [r0]\n\
	bl _080F1C6C\n\
	.align 2, 0\n\
_080F1484: .4byte 0x00000DCC\n\
_080F1488:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bne _080F1492\n\
	b _080F1B00\n\
_080F1492:\n\
	movs r0, #2\n\
	strb r0, [r5, #3]\n\
	bl _080F1D84\n\
_080F149A:\n\
	ldr r0, _080F1528 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F14AA\n\
	cmp r0, #4\n\
	beq _080F14AA\n\
	bl _080F1D84\n\
_080F14AA:\n\
	ldr r3, _080F152C @ =0x00000DCC\n\
	adds r4, r5, r3\n\
	ldr r0, [r4]\n\
	cmp r0, #0\n\
	bne _080F14BC\n\
	adds r0, r5, #4\n\
	bl CreateStageBossMugshots\n\
	str r0, [r4]\n\
_080F14BC:\n\
	movs r0, #0x13\n\
	bl PrintOptionMessage1\n\
	movs r0, #0x3c\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F14CC:\n\
	ldrh r1, [r5, #0xa]\n\
	movs r4, #0xa\n\
	ldrsh r0, [r5, r4]\n\
	cmp r0, #0\n\
	beq _080F14DA\n\
	subs r0, r1, #1\n\
	strh r0, [r5, #0xa]\n\
_080F14DA:\n\
	ldrh r3, [r5, #6]\n\
	movs r6, #6\n\
	ldrsh r0, [r5, r6]\n\
	movs r1, #8\n\
	ldrsh r2, [r5, r1]\n\
	cmp r0, r2\n\
	beq _080F153E\n\
	ldr r0, _080F1530 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F150A\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r2\n\
	ble _080F1504\n\
	strh r3, [r5, #4]\n\
_080F1504:\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F150A:\n\
	ldr r0, _080F1530 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F153E\n\
	ldrh r2, [r5, #4]\n\
	movs r3, #4\n\
	ldrsh r1, [r5, r3]\n\
	movs r4, #6\n\
	ldrsh r0, [r5, r4]\n\
	cmp r1, r0\n\
	bne _080F1534\n\
	ldrh r0, [r5, #8]\n\
	b _080F1536\n\
	.align 2, 0\n\
_080F1528: .4byte gTextWindow+8\n\
_080F152C: .4byte 0x00000DCC\n\
_080F1530: .4byte gJoypad\n\
_080F1534:\n\
	subs r0, r2, #1\n\
_080F1536:\n\
	strh r0, [r5, #4]\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F153E:\n\
	ldr r0, _080F1588 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F154E\n\
	cmp r0, #4\n\
	beq _080F154E\n\
	bl _080F1D84\n\
_080F154E:\n\
	ldr r0, _080F158C @ =gMission\n\
	ldr r2, [r0]\n\
	ldr r0, _080F1590 @ =MissionBitfields_083861e8\n\
	movs r6, #4\n\
	ldrsh r3, [r5, r6]\n\
	adds r0, r3, r0\n\
	movs r1, #1\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r2, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F15A0\n\
	ldr r2, _080F1594 @ =StringOfsTable\n\
	ldr r1, _080F1598 @ =StageNameIdxs\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F159C @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	movs r2, #0xd\n\
	bl PrintString\n\
	b _080F15B2\n\
	.align 2, 0\n\
_080F1588: .4byte gTextWindow+8\n\
_080F158C: .4byte gMission\n\
_080F1590: .4byte MissionBitfields_083861e8\n\
_080F1594: .4byte StringOfsTable\n\
_080F1598: .4byte StageNameIdxs\n\
_080F159C: .4byte gStringData\n\
_080F15A0:\n\
	ldr r0, _080F15F0 @ =StringOfsTable\n\
	adds r0, #0x96\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F15F4 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	movs r2, #0xd\n\
	bl PrintString\n\
_080F15B2:\n\
	movs r1, #0xa\n\
	ldrsh r0, [r5, r1]\n\
	cmp r0, #0\n\
	beq _080F15BE\n\
	bl _080F1D84\n\
_080F15BE:\n\
	ldr r0, _080F15F8 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1620\n\
	ldr r0, _080F15FC @ =gMission\n\
	ldr r2, [r0]\n\
	ldr r1, _080F1600 @ =MissionBitfields_083861e8\n\
	movs r4, #4\n\
	ldrsh r0, [r5, r4]\n\
	adds r0, r0, r1\n\
	adds r1, r3, #0\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r2, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1604\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F15F0: .4byte StringOfsTable\n\
_080F15F4: .4byte gStringData\n\
_080F15F8: .4byte gJoypad\n\
_080F15FC: .4byte gMission\n\
_080F1600: .4byte MissionBitfields_083861e8\n\
_080F1604:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	ldr r1, _080F161C @ =MissionSummaryTextIDs\n\
	movs r6, #4\n\
	ldrsh r0, [r5, r6]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	bl PrintOptionMessage2\n\
	b _080F1C6C\n\
	.align 2, 0\n\
_080F161C: .4byte MissionSummaryTextIDs\n\
_080F1620:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F162A\n\
	b _080F1D84\n\
_080F162A:\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldr r1, _080F1640 @ =0x00000DCC\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	bl FUN_080c5f98\n\
	movs r0, #0xb\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1640: .4byte 0x00000DCC\n\
_080F1644:\n\
	ldr r0, _080F16B4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1652\n\
	cmp r0, #4\n\
	beq _080F1652\n\
	b _080F1D84\n\
_080F1652:\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldr r1, _080F16B8 @ =MissionAskTextIDs\n\
	movs r2, #4\n\
	ldrsh r0, [r5, r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F166C:\n\
	ldr r4, _080F16B4 @ =gTextWindow+8\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F167A\n\
	cmp r0, #4\n\
	beq _080F167A\n\
	b _080F1D84\n\
_080F167A:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F168A\n\
	b _080F1D84\n\
_080F168A:\n\
	lsls r0, r2, #0x10\n\
	cmp r0, #0\n\
	ble _080F16C8\n\
	ldr r3, _080F16BC @ =0x00000DCC\n\
	adds r0, r5, r3\n\
	ldr r0, [r0]\n\
	bl FUN_080c5f98\n\
	ldr r0, _080F16C0 @ =gStageRun+16\n\
	ldr r1, _080F16C4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	ldrh r1, [r4]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0xc\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F16B4: .4byte gTextWindow+8\n\
_080F16B8: .4byte MissionAskTextIDs\n\
_080F16BC: .4byte 0x00000DCC\n\
_080F16C0: .4byte gStageRun+16\n\
_080F16C4: .4byte gStageScriptList\n\
_080F16C8:\n\
	movs r3, #1\n\
	ldr r2, _080F1704 @ =gCurStory\n\
	ldrb r1, [r2, #5]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F170C\n\
	ldr r0, _080F1708 @ =gMission\n\
	ldr r0, [r0]\n\
	ldr r2, [r0, #0x14]\n\
	lsrs r1, r2, #2\n\
	adds r4, r3, #0\n\
	bics r4, r1\n\
	adds r1, r4, #0\n\
	lsrs r0, r2, #3\n\
	adds r6, r3, #0\n\
	bics r6, r0\n\
	adds r0, r6, #0\n\
	adds r0, r0, r1\n\
	lsrs r1, r2, #4\n\
	bics r3, r1\n\
	adds r1, r3, #0\n\
	adds r1, r1, r0\n\
	movs r0, #0x20\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080F1780\n\
	adds r0, r1, #1\n\
	b _080F1784\n\
	.align 2, 0\n\
_080F1704: .4byte gCurStory\n\
_080F1708: .4byte gMission\n\
_080F170C:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1740\n\
	ldr r0, _080F1738 @ =gMission\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x14]\n\
	lsrs r0, r1, #7\n\
	lsrs r2, r1, #8\n\
	adds r4, r3, #0\n\
	bics r4, r2\n\
	adds r2, r4, #0\n\
	bics r3, r0\n\
	adds r2, r2, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080F173C\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	b _080F1782\n\
	.align 2, 0\n\
_080F1738: .4byte gMission\n\
_080F173C:\n\
	lsls r0, r2, #0x10\n\
	b _080F1782\n\
_080F1740:\n\
	ldrb r1, [r2, #6]\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1786\n\
	ldr r0, _080F177C @ =gMission\n\
	ldr r0, [r0]\n\
	ldr r2, [r0, #0x14]\n\
	lsrs r1, r2, #0xb\n\
	adds r6, r3, #0\n\
	bics r6, r1\n\
	adds r1, r6, #0\n\
	lsrs r0, r2, #0xc\n\
	adds r4, r3, #0\n\
	bics r4, r0\n\
	adds r0, r4, #0\n\
	adds r0, r0, r1\n\
	lsrs r1, r2, #0xd\n\
	bics r3, r1\n\
	adds r1, r3, #0\n\
	adds r1, r1, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080F1780\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x10\n\
	b _080F1782\n\
	.align 2, 0\n\
_080F177C: .4byte gMission\n\
_080F1780:\n\
	lsls r0, r1, #0x10\n\
_080F1782:\n\
	lsrs r0, r0, #0x10\n\
_080F1784:\n\
	adds r3, r0, #0\n\
_080F1786:\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bgt _080F1796\n\
	movs r0, #0x12\n\
	bl PrintOptionMessage2\n\
	b _080F1C6C\n\
_080F1796:\n\
	movs r0, #0x11\n\
	bl PrintOptionMessage2\n\
	b _080F1BD4\n\
_080F179E:\n\
	ldr r0, _080F17D0 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F17AC\n\
	cmp r0, #4\n\
	beq _080F17AC\n\
	b _080F1D84\n\
_080F17AC:\n\
	ldr r6, _080F17D4 @ =0x00000DCC\n\
	adds r0, r5, r6\n\
	ldr r0, [r0]\n\
	bl FUN_080c5f98\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F17BC:\n\
	ldr r2, _080F17D0 @ =gTextWindow+8\n\
	ldrh r4, [r2, #2]\n\
	cmp r4, #0\n\
	beq _080F17D8\n\
_080F17C4:\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F17D0: .4byte gTextWindow+8\n\
_080F17D4: .4byte 0x00000DCC\n\
_080F17D8:\n\
	movs r0, #0xf\n\
	bl PrintOptionMessage1\n\
	strh r4, [r5, #0xa]\n\
	b _080F1D36\n\
_080F17E2:\n\
	ldr r0, _080F1820 @ =gStageRun\n\
	ldrb r1, [r0, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F17F0\n\
	b _080F1D84\n\
_080F17F0:\n\
	ldr r1, _080F1824 @ =MissionBitfields_083861e8\n\
	movs r2, #4\n\
	ldrsh r0, [r5, r2]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	ldr r3, _080F1828 @ =0x00006260\n\
	adds r4, r5, r3\n\
	strh r0, [r4]\n\
	ldr r6, _080F182C @ =0x00006270\n\
	adds r0, r5, r6\n\
	bl saveCurStory\n\
	ldr r1, _080F1830 @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	ldr r2, _080F1834 @ =0x00006460\n\
	adds r1, r5, r2\n\
	bl CopyZeroStatus\n\
	ldrb r0, [r4]\n\
	ldr r3, _080F1838 @ =0x00006410\n\
	adds r1, r5, r3\n\
	b _080F1CF0\n\
	.align 2, 0\n\
_080F1820: .4byte gStageRun\n\
_080F1824: .4byte MissionBitfields_083861e8\n\
_080F1828: .4byte 0x00006260\n\
_080F182C: .4byte 0x00006270\n\
_080F1830: .4byte 0x000064AC\n\
_080F1834: .4byte 0x00006460\n\
_080F1838: .4byte 0x00006410\n\
_080F183C:\n\
	movs r0, #0x32\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	strh r0, [r5, #6]\n\
	strh r0, [r5, #8]\n\
	movs r0, #0xf\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F1854:\n\
	ldr r0, _080F1A3C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1862\n\
	cmp r0, #4\n\
	beq _080F1862\n\
	b _080F1D84\n\
_080F1862:\n\
	movs r4, #0\n\
	movs r2, #0\n\
	ldr r0, _080F1A40 @ =gMission\n\
	ldr r6, [r0]\n\
	ldr r7, _080F1A44 @ =u8_ARRAY_0838623c\n\
	movs r0, #1\n\
	mov ip, r0\n\
_080F1870:\n\
	lsls r0, r2, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r0, r3, r7\n\
	mov r1, ip\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r6, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1894\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #1\n\
	add r1, sp\n\
	strh r2, [r1]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
_080F1894:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	ble _080F1870\n\
	movs r1, #4\n\
	ldrsh r2, [r5, r1]\n\
	lsls r1, r4, #0x10\n\
	asrs r0, r1, #0x10\n\
	subs r0, #1\n\
	adds r7, r1, #0\n\
	cmp r2, r0\n\
	bge _080F18C8\n\
	ldr r0, _080F1A48 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F18C8\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
_080F18C8:\n\
	movs r2, #4\n\
	ldrsh r0, [r5, r2]\n\
	cmp r0, #0\n\
	ble _080F18E8\n\
	ldr r0, _080F1A48 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F18E8\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r5, #4]\n\
	subs r0, #1\n\
	strh r0, [r5, #4]\n\
_080F18E8:\n\
	ldrh r3, [r5, #4]\n\
	movs r4, #4\n\
	ldrsh r1, [r5, r4]\n\
	movs r6, #6\n\
	ldrsh r0, [r5, r6]\n\
	adds r2, r3, #0\n\
	cmp r1, r0\n\
	bge _080F18FA\n\
	strh r2, [r5, #6]\n\
_080F18FA:\n\
	movs r0, #4\n\
	ldrsh r1, [r5, r0]\n\
	movs r2, #6\n\
	ldrsh r0, [r5, r2]\n\
	adds r0, #1\n\
	cmp r1, r0\n\
	ble _080F190C\n\
	subs r0, r3, #1\n\
	strh r0, [r5, #6]\n\
_080F190C:\n\
	movs r2, #0\n\
	cmp r7, #0\n\
	ble _080F197E\n\
	ldr r3, _080F1A4C @ =StringOfsTable\n\
	mov sb, r3\n\
	ldr r4, _080F1A50 @ =FreeRunStageTextIDs\n\
	mov r8, r4\n\
_080F191A:\n\
	lsls r1, r2, #0x10\n\
	asrs r3, r1, #0x10\n\
	movs r6, #6\n\
	ldrsh r0, [r5, r6]\n\
	subs r0, r3, r0\n\
	lsls r0, r0, #0x19\n\
	lsrs r2, r0, #0x18\n\
	adds r6, r1, #0\n\
	cmp r2, #2\n\
	bhi _080F1972\n\
	lsls r0, r3, #1\n\
	add r0, sp\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F1A54 @ =gStringData\n\
	adds r4, r1, r0\n\
	movs r3, #0\n\
	ldr r1, _080F1A3C @ =gTextWindow+8\n\
	ldrb r0, [r1, #6]\n\
	cmp r0, #0\n\
	bne _080F1956\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #1\n\
	bne _080F1958\n\
_080F1956:\n\
	movs r3, #1\n\
_080F1958:\n\
	lsls r0, r3, #3\n\
	subs r0, r0, r3\n\
	movs r1, #0xa\n\
	subs r1, r1, r0\n\
	ldr r0, _080F1A3C @ =gTextWindow+8\n\
	lsls r2, r2, #0x18\n\
	asrs r2, r2, #0x18\n\
	adds r2, #2\n\
	ldrb r0, [r0, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r4, #0\n\
	bl PrintString\n\
_080F1972:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r6, r2\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, r7\n\
	blt _080F191A\n\
_080F197E:\n\
	ldr r0, _080F1A4C @ =StringOfsTable\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F1A54 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F1A3C @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F1998\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F199A\n\
_080F1998:\n\
	movs r2, #1\n\
_080F199A:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	movs r6, #4\n\
	ldrsh r2, [r5, r6]\n\
	movs r6, #6\n\
	ldrsh r0, [r5, r6]\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, #2\n\
	ldrb r0, [r4, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	strh r0, [r5, #8]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1A2A\n\
	movs r1, #6\n\
	ldrsh r0, [r5, r1]\n\
	cmp r0, #0\n\
	beq _080F19F6\n\
	ldr r3, _080F1A58 @ =Unicode_CursorUp\n\
	movs r1, #0\n\
	ldrb r0, [r4, #6]\n\
	cmp r0, #0\n\
	bne _080F19E0\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F19E2\n\
_080F19E0:\n\
	movs r1, #1\n\
_080F19E2:\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldr r0, _080F1A3C @ =gTextWindow+8\n\
	ldrb r2, [r0, #5]\n\
	adds r2, #2\n\
	adds r0, r3, #0\n\
	bl PrintUnicodeString\n\
_080F19F6:\n\
	movs r2, #6\n\
	ldrsh r1, [r5, r2]\n\
	asrs r0, r7, #0x10\n\
	subs r0, #2\n\
	cmp r1, r0\n\
	bge _080F1A2A\n\
	ldr r3, _080F1A5C @ =Unicode_CursorDown\n\
	movs r2, #0\n\
	ldr r0, _080F1A3C @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F1A16\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F1A18\n\
_080F1A16:\n\
	movs r2, #1\n\
_080F1A18:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #5\n\
	adds r0, r3, #0\n\
	bl PrintUnicodeString\n\
_080F1A2A:\n\
	ldrh r0, [r5, #0xa]\n\
	movs r3, #0xa\n\
	ldrsh r4, [r5, r3]\n\
	cmp r4, #0\n\
	beq _080F1A60\n\
	subs r0, #1\n\
	strh r0, [r5, #0xa]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1A3C: .4byte gTextWindow+8\n\
_080F1A40: .4byte gMission\n\
_080F1A44: .4byte u8_ARRAY_0838623c\n\
_080F1A48: .4byte gJoypad\n\
_080F1A4C: .4byte StringOfsTable\n\
_080F1A50: .4byte FreeRunStageTextIDs\n\
_080F1A54: .4byte gStringData\n\
_080F1A58: .4byte Unicode_CursorUp\n\
_080F1A5C: .4byte Unicode_CursorDown\n\
_080F1A60:\n\
	ldr r0, _080F1A7C @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1A80\n\
	movs r0, #3\n\
	bl PlaySound\n\
	movs r0, #0xf\n\
	bl PrintOptionMessage1\n\
	strh r4, [r5, #0xa]\n\
	b _080F1D36\n\
	.align 2, 0\n\
_080F1A7C: .4byte gJoypad\n\
_080F1A80:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1A8A\n\
	b _080F1D84\n\
_080F1A8A:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	movs r4, #4\n\
	ldrsh r0, [r5, r4]\n\
	lsls r0, r0, #1\n\
	add r0, sp\n\
	ldrh r0, [r0]\n\
	strh r0, [r5, #4]\n\
	b _080F1C6C\n\
_080F1A9E:\n\
	ldr r1, _080F1AF0 @ =FreeRunStageConfirmTextIDs\n\
	movs r6, #4\n\
	ldrsh r0, [r5, r6]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	bl PrintOptionMessage1\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F1AB4:\n\
	ldr r4, _080F1AF4 @ =gTextWindow+8\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F1AC2\n\
	cmp r0, #4\n\
	beq _080F1AC2\n\
	b _080F1D84\n\
_080F1AC2:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080F1AD2\n\
	b _080F1D84\n\
_080F1AD2:\n\
	lsls r0, r2, #0x10\n\
	cmp r0, #0\n\
	ble _080F1B00\n\
	ldr r0, _080F1AF8 @ =gStageRun+16\n\
	ldr r1, _080F1AFC @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	ldrh r1, [r4]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	b _080F1C6C\n\
	.align 2, 0\n\
_080F1AF0: .4byte FreeRunStageConfirmTextIDs\n\
_080F1AF4: .4byte gTextWindow+8\n\
_080F1AF8: .4byte gStageRun+16\n\
_080F1AFC: .4byte gStageScriptList\n\
_080F1B00:\n\
	movs r0, #0xd\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
_080F1B06:\n\
	ldr r0, _080F1B44 @ =gStageRun\n\
	ldrb r1, [r0, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1B14\n\
	b _080F1D84\n\
_080F1B14:\n\
	ldr r1, _080F1B48 @ =u8_ARRAY_0838623c\n\
	movs r2, #4\n\
	ldrsh r0, [r5, r2]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	ldr r3, _080F1B4C @ =0x00006260\n\
	adds r4, r5, r3\n\
	strh r0, [r4]\n\
	ldr r6, _080F1B50 @ =0x00006270\n\
	adds r0, r5, r6\n\
	bl saveCurStory\n\
	ldr r1, _080F1B54 @ =0x000064AC\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	ldr r2, _080F1B58 @ =0x00006460\n\
	adds r1, r5, r2\n\
	bl CopyZeroStatus\n\
	ldrb r0, [r4]\n\
	ldr r3, _080F1B5C @ =0x00006410\n\
	adds r1, r5, r3\n\
	b _080F1CF0\n\
	.align 2, 0\n\
_080F1B44: .4byte gStageRun\n\
_080F1B48: .4byte u8_ARRAY_0838623c\n\
_080F1B4C: .4byte 0x00006260\n\
_080F1B50: .4byte 0x00006270\n\
_080F1B54: .4byte 0x000064AC\n\
_080F1B58: .4byte 0x00006460\n\
_080F1B5C: .4byte 0x00006410\n\
_080F1B60:\n\
	movs r0, #0x10\n\
	bl PrintOptionMessage2\n\
	ldr r1, _080F1B90 @ =gCurStory\n\
	ldrb r2, [r1, #5]\n\
	movs r0, #8\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	rsbs r0, r0, #0\n\
	asrs r3, r0, #0x1f\n\
	movs r0, #4\n\
	ands r3, r0\n\
	ldrb r0, [r1, #6]\n\
	movs r1, #1\n\
	ands r1, r0\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F1B94\n\
	adds r0, r1, #3\n\
	adds r0, r3, r0\n\
	b _080F1B98\n\
	.align 2, 0\n\
_080F1B90: .4byte gCurStory\n\
_080F1B94:\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
_080F1B98:\n\
	strh r0, [r5, #6]\n\
	strh r0, [r5, #4]\n\
	ldr r1, _080F1BC4 @ =gCurStory\n\
	ldrb r3, [r1, #5]\n\
	movs r0, #8\n\
	ands r0, r3\n\
	movs r2, #3\n\
	cmp r0, #0\n\
	beq _080F1BAC\n\
	movs r2, #6\n\
_080F1BAC:\n\
	ldrb r0, [r1, #6]\n\
	movs r1, #1\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x80\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080F1BC8\n\
	adds r0, r1, #1\n\
	adds r1, r2, r0\n\
	b _080F1BCA\n\
	.align 2, 0\n\
_080F1BC4: .4byte gCurStory\n\
_080F1BC8:\n\
	adds r1, r2, r1\n\
_080F1BCA:\n\
	movs r0, #0\n\
	strh r1, [r5, #8]\n\
	ldr r4, _080F1BDC @ =0x00000DCC\n\
	adds r1, r5, r4\n\
	str r0, [r1]\n\
_080F1BD4:\n\
	movs r0, #6\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1BDC: .4byte 0x00000DCC\n\
_080F1BE0:\n\
	ldr r0, _080F1BF8 @ =gCurStory\n\
	ldrb r1, [r0, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F1BFC\n\
	movs r0, #0x2c\n\
	bl PrintOptionMessage2\n\
	movs r0, #0x15\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1BF8: .4byte gCurStory\n\
_080F1BFC:\n\
	ldr r0, _080F1C40 @ =gStageRun+16\n\
	ldr r1, _080F1C44 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x50]\n\
	bl SetScript\n\
	ldr r2, _080F1C48 @ =gTextWindow+8\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F1C18:\n\
	ldr r0, _080F1C4C @ =gStageRun\n\
	ldrb r0, [r0, #0x12]\n\
	movs r4, #1\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	beq _080F1C26\n\
	b _080F1D84\n\
_080F1C26:\n\
	ldr r2, _080F1C50 @ =gCurStory\n\
	ldrb r1, [r2, #6]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strb r0, [r2, #6]\n\
	movs r0, #0x2d\n\
	bl PrintOptionMessage1\n\
	strh r4, [r5, #0xa]\n\
	movs r0, #0x16\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1C40: .4byte gStageRun+16\n\
_080F1C44: .4byte gStageScriptList\n\
_080F1C48: .4byte gTextWindow+8\n\
_080F1C4C: .4byte gStageRun\n\
_080F1C50: .4byte gCurStory\n\
_080F1C54:\n\
	ldr r0, _080F1C74 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1C62\n\
	cmp r0, #4\n\
	beq _080F1C62\n\
	b _080F1D84\n\
_080F1C62:\n\
	movs r0, #0x2d\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
_080F1C6C:\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1C74: .4byte gTextWindow+8\n\
_080F1C78:\n\
	ldr r4, _080F1CB4 @ =gTextWindow+8\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _080F1C86\n\
	cmp r0, #4\n\
	beq _080F1C86\n\
	b _080F1D84\n\
_080F1C86:\n\
	adds r0, r5, #0\n\
	bl handleWrapTwoChoice\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080F1D84\n\
	lsls r0, r2, #0x10\n\
	cmp r0, #0\n\
	ble _080F1D2C\n\
	ldr r0, _080F1CB8 @ =gStageRun+16\n\
	ldr r1, _080F1CBC @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	ldrh r1, [r4]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x17\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1CB4: .4byte gTextWindow+8\n\
_080F1CB8: .4byte gStageRun+16\n\
_080F1CBC: .4byte gStageScriptList\n\
_080F1CC0:\n\
	ldr r0, _080F1D08 @ =gStageRun\n\
	ldrb r1, [r0, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1D84\n\
	ldr r6, _080F1D0C @ =0x00006260\n\
	adds r4, r5, r6\n\
	movs r0, #0x10\n\
	strh r0, [r4]\n\
	ldr r1, _080F1D10 @ =0x00006270\n\
	adds r0, r5, r1\n\
	bl saveCurStory\n\
	ldr r2, _080F1D14 @ =0x000064AC\n\
	adds r0, r5, r2\n\
	ldr r0, [r0]\n\
	ldr r3, _080F1D18 @ =0x00006460\n\
	adds r1, r5, r3\n\
	bl CopyZeroStatus\n\
	ldrb r0, [r4]\n\
	ldr r6, _080F1D1C @ =0x00006410\n\
	adds r1, r5, r6\n\
_080F1CF0:\n\
	bl InitMissionInfo\n\
	ldrb r0, [r4]\n\
	bl InitStageRun\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
FUN_080f1cfe:\n\
	adds r0, r5, #0\n\
	bl SetGameMode\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1D08: .4byte gStageRun\n\
_080F1D0C: .4byte 0x00006260\n\
_080F1D10: .4byte 0x00006270\n\
_080F1D14: .4byte 0x000064AC\n\
_080F1D18: .4byte 0x00006460\n\
_080F1D1C: .4byte 0x00006410\n\
_080F1D20:\n\
	ldr r0, _080F1D3C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F1D2C\n\
	cmp r0, #4\n\
	bne _080F1D84\n\
_080F1D2C:\n\
	movs r0, #0xf\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r5, #0xa]\n\
_080F1D36:\n\
	movs r0, #5\n\
	strb r0, [r5, #3]\n\
	b _080F1D84\n\
	.align 2, 0\n\
_080F1D3C: .4byte gTextWindow+8\n\
_080F1D40:\n\
	ldr r0, _080F1D94 @ =gStageRun\n\
	ldrb r1, [r0, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F1D84\n\
	ldr r0, _080F1D98 @ =0x00006260\n\
	adds r4, r5, r0\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldr r1, _080F1D9C @ =0x00006270\n\
	adds r0, r5, r1\n\
	bl saveCurStory\n\
	ldr r2, _080F1DA0 @ =0x000064AC\n\
	adds r0, r5, r2\n\
	ldr r0, [r0]\n\
	ldr r3, _080F1DA4 @ =0x00006460\n\
	adds r1, r5, r3\n\
	bl CopyZeroStatus\n\
	ldrb r0, [r4]\n\
	ldr r6, _080F1DA8 @ =0x00006410\n\
	adds r1, r5, r6\n\
	bl InitMissionInfo\n\
	ldrb r0, [r4]\n\
	bl InitStageRun\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	adds r0, r5, #0\n\
	bl SetGameMode\n\
_080F1D84:\n\
	add sp, #0x20\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F1D94: .4byte gStageRun\n\
_080F1D98: .4byte 0x00006260\n\
_080F1D9C: .4byte 0x00006270\n\
_080F1DA0: .4byte 0x000064AC\n\
_080F1DA4: .4byte 0x00006460\n\
_080F1DA8: .4byte 0x00006410\n\
 .syntax divided\n");
}

static const u8 MissionBitfields_083861e8[MISSION_COUNT] = {
    2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14,
};

// Idx of 08372210 (StringOfsTable)
static const str_id_t StageNameIdxs[MISSION_COUNT] = {
    63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
};

static const TextID MissionSummaryTextIDs[MISSION_COUNT] = {
    0x0014, 0x0016, 0x0018, 0x001A, 0x001C, 0x001E, 0x0020, 0x0022, 0x0024, 0x0026, 0x0028, 0x002A,
};

static const TextID MissionAskTextIDs[MISSION_COUNT] = {
    0x0015, 0x0017, 0x0019, 0x001B, 0x001D, 0x001F, 0x0021, 0x0023, 0x0025, 0x0027, 0x0029, 0x002B,
};

static const u8 u8_ARRAY_0838623c[16] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0,
};

static const TextID FreeRunStageTextIDs[FREE_STAGE_COUNT] = {
    0x002F, 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D,
};

static const TextID FreeRunStageConfirmTextIDs[FREE_STAGE_COUNT] = {
    0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F, 0x0040, 0x0041,
};
