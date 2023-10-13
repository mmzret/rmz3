#include "result.h"

#include "global.h"
#include "reward.h"
#include "sprite.h"
#include "stagerun.h"

#define STAGE_CHIP_NONE 0
#define STAGE_CHIP_BODY 2
#define STAGE_CHIP_FOOT 3

extern const u8 u8_ARRAY_083863d0[24];
extern const u8 u8_ARRAY_083863e8[40];

static const u8 sStageChipTypes[STAGE_COUNT];
static const u8 sStageChipIDs[STAGE_COUNT];
static const TextID sUnlockEquipTextIDs[STAGE_COUNT];
static const u32 sStageRewardExSkills[STAGE_COUNT];
static const TextID sUnlockExSkillTextIDs[STAGE_COUNT];

static void printNumOnResultScreen(u32 n, u8 x, u8 y);
static void FUN_08024b54(u8 rank);
static void FUN_08024b98(struct ResultState* p);
static void FUN_08024c48(struct ResultState* p);
static bool32 printResultScore(u8 score, u16 r1, u8 r2, u8 x, u8 y);
static void FUN_08024db4(void);

void CreateDiskIcon(struct Coord* c, u8 n, u8 r2);
void FUN_08024db4(void);

void PrepareResultScreen(struct ResultState* p) {
  u8 i;
  struct Coord c;

  FUN_08024db4();
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  gBlendRegBuffer.bldclt = 0;
  LOAD_STATIC_GRAPHIC(SM014_CHIPICON);
  LOAD_STATIC_GRAPHIC(SM127_DISABLED_DISK);
  c.y = PIXEL(114);
  for (i = 0; i < gStageDiskManager.stageDiskCount; i++) {
    c.x = i * PIXEL(16) + PIXEL(48);
    CreateDiskIcon(&c, gStageDiskManager.stageDiskIDs[i], 0);
  }
  p->unk_00[0] = p->unk_00[1] = p->unk_00[2] = p->unk_00[3] = 0;
  p->frame = p->unk_06 = p->unk_08 = p->unk_0a = 0;
  p->unk_0c = 0;
}

static bool32 printPlayerAllScore(struct ResultState* p);
static bool32 getStageRewardChip(struct ResultState* p);
static bool32 getStageRewardExSkill(struct ResultState* p);
static bool32 FUN_080248f0(struct ResultState* p);
static void result_08024e0c(void);

NAKED bool32 result_0802400c(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6]\n\
	cmp r0, #8\n\
	bls _08024018\n\
	b _080242E4\n\
_08024018:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08024024 @ =_08024028\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08024024: .4byte _08024028\n\
_08024028: @ jump table\n\
	.4byte _0802404C @ case 0\n\
	.4byte _0802417C @ case 1\n\
	.4byte _080241D4 @ case 2\n\
	.4byte _080241EC @ case 3\n\
	.4byte _08024202 @ case 4\n\
	.4byte _08024218 @ case 5\n\
	.4byte _0802422E @ case 6\n\
	.4byte _08024268 @ case 7\n\
	.4byte _0802429A @ case 8\n\
_0802404C:\n\
	ldr r4, _0802419C @ =gMission\n\
	ldr r0, [r4]\n\
	ldrb r0, [r0, #1]\n\
	str r0, [r6, #0x10]\n\
	ldr r0, _080241A0 @ =gGameState\n\
	ldr r1, _080241A4 @ =0x000064AC\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	bl IsAllElfUnlocked\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08024088\n\
	ldr r1, [r4]\n\
	movs r0, #1\n\
	strb r0, [r1, #6]\n\
	ldr r0, [r5]\n\
	bl IsElfBreeder\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08024088\n\
	ldr r2, [r4]\n\
	ldrb r1, [r2, #7]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2, #7]\n\
_08024088:\n\
	bl allSecretDiskFound\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080240A2\n\
	ldr r0, _0802419C @ =gMission\n\
	ldr r2, [r0]\n\
	ldrb r1, [r2, #7]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2, #7]\n\
_080240A2:\n\
	ldr r0, _080241A0 @ =gGameState\n\
	ldr r2, _080241A4 @ =0x000064AC\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	bl CalcElfPenalty\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r2, _0802419C @ =gMission\n\
	ldr r1, [r2, #0x10]\n\
	adds r1, r1, r0\n\
	movs r7, #1\n\
	rsbs r7, r7, #0\n\
	str r1, [r2, #0x10]\n\
	bl calcStageScore\n\
	ldr r5, _080241A8 @ =gVideoRegBuffer+6\n\
	movs r3, #0x81\n\
	lsls r3, r3, #2\n\
	adds r0, r3, #0\n\
	strh r0, [r5]\n\
	adds r1, r5, #0\n\
	adds r1, #0xa\n\
	movs r0, #0\n\
	str r0, [r1]\n\
	subs r2, r5, #6\n\
	ldrh r1, [r2]\n\
	ldr r0, _080241AC @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x98\n\
	lsls r3, r3, #5\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _080241B0 @ =gGraphic_Capcom+(22*20)\n\
	movs r4, #0xc\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, _080241B4 @ =gGraphic_Capcom+(22*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r0, _080241B8 @ =gGraphics_CodeName\n\
	ldrh r1, [r5]\n\
	ands r4, r1\n\
	lsls r4, r4, #0xc\n\
	adds r1, r4, #0\n\
	bl LoadGraphic\n\
	ldr r0, _080241BC @ =0x085475E8\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldrh r1, [r5]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #5\n\
	ands r0, r1\n\
	lsls r0, r0, #3\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	adds r0, r0, r1\n\
	ldr r2, _080241C0 @ =0x08522430\n\
	ldr r1, [r2]\n\
	adds r1, r1, r2\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl CopyBgMap\n\
	bl PauseAllBlinks\n\
	movs r0, #0x40\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r2, _080241C4 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080241C8 @ =0x0000BFFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _080241CC @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xbe\n\
	beq _0802416A\n\
	cmp r0, r7\n\
	beq _08024160\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r7, [r4]\n\
_08024160:\n\
	movs r0, #0xbe\n\
	bl playBGM\n\
	movs r0, #0xbe\n\
	str r0, [r4]\n\
_0802416A:\n\
	ldr r0, _080241CC @ =gStageRun\n\
	movs r2, #0xaa\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	movs r1, #9\n\
	str r1, [r0]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
_0802417C:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080241CC @ =gStageRun\n\
	movs r3, #0xaa\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	ldr r2, [r0]\n\
	cmp r2, #0\n\
	beq _08024192\n\
	b _080242E4\n\
_08024192:\n\
	ldr r0, _080241D0 @ =gPaletteManager\n\
	movs r1, #0\n\
	strh r2, [r0]\n\
	strb r1, [r6, #1]\n\
	b _0802425A\n\
	.align 2, 0\n\
_0802419C: .4byte gMission\n\
_080241A0: .4byte gGameState\n\
_080241A4: .4byte 0x000064AC\n\
_080241A8: .4byte gVideoRegBuffer+6\n\
_080241AC: .4byte 0x0000F0FF\n\
_080241B0: .4byte gGraphic_Capcom+(22*20)\n\
_080241B4: .4byte gGraphic_Capcom+(22*20)+12\n\
_080241B8: .4byte gGraphics_CodeName\n\
_080241BC: .4byte gGraphics_CodeName+12\n\
_080241C0: .4byte gBgMapOffsets+400\n\
_080241C4: .4byte gWindowRegBuffer\n\
_080241C8: .4byte 0x0000BFFF\n\
_080241CC: .4byte gStageRun\n\
_080241D0: .4byte gPaletteManager\n\
_080241D4:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	adds r0, r6, #0\n\
	bl printPlayerAllScore\n\
	cmp r0, #1\n\
	bne _080241E6\n\
	b _080242E4\n\
_080241E6:\n\
	movs r0, #0\n\
	strb r0, [r6, #1]\n\
	b _0802425A\n\
_080241EC:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	adds r0, r6, #0\n\
	bl getStageRewardChip\n\
	cmp r0, #1\n\
	beq _080242E4\n\
	movs r0, #0\n\
	strb r0, [r6, #1]\n\
	b _0802425A\n\
_08024202:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	adds r0, r6, #0\n\
	bl getStageRewardExSkill\n\
	cmp r0, #1\n\
	beq _080242E4\n\
	movs r0, #0\n\
	strb r0, [r6, #1]\n\
	b _0802425A\n\
_08024218:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	adds r0, r6, #0\n\
	bl FUN_080248f0\n\
	cmp r0, #1\n\
	beq _080242E4\n\
	movs r0, #0\n\
	strb r0, [r6, #1]\n\
	b _0802425A\n\
_0802422E:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	ldr r4, _08024264 @ =gStageRun\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #1\n\
	adds r7, r4, r0\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _08024250\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_08024250:\n\
	movs r2, #0xaa\n\
	lsls r2, r2, #1\n\
	adds r1, r4, r2\n\
	movs r0, #0xa\n\
	str r0, [r1]\n\
_0802425A:\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _080242E4\n\
	.align 2, 0\n\
_08024264: .4byte gStageRun\n\
_08024268:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080242C4 @ =gStageRun\n\
	movs r3, #0xaa\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080242E4\n\
	ldr r2, _080242C8 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080242CC @ =0x0000EDFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0x40\n\
	bl ClearBlink\n\
	bl ResumeAllBlinks\n\
	movs r0, #0x3c\n\
	strh r0, [r6, #4]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
_0802429A:\n\
	ldrh r0, [r6, #4]\n\
	movs r2, #4\n\
	ldrsh r1, [r6, r2]\n\
	cmp r1, #0\n\
	bne _080242E0\n\
	ldr r0, _080242D0 @ =gMission\n\
	ldr r0, [r0]\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	ldr r1, _080242D4 @ =gGameState\n\
	ldr r3, _080242D8 @ =0x000064AC\n\
	adds r0, r1, r3\n\
	ldr r0, [r0]\n\
	ldr r2, _080242DC @ =0x00006460\n\
	adds r1, r1, r2\n\
	bl CopyZeroStatus\n\
	bl result_08024e0c\n\
	movs r0, #0\n\
	b _080242EA\n\
	.align 2, 0\n\
_080242C4: .4byte gStageRun\n\
_080242C8: .4byte gVideoRegBuffer\n\
_080242CC: .4byte 0x0000EDFF\n\
_080242D0: .4byte gMission\n\
_080242D4: .4byte gGameState\n\
_080242D8: .4byte 0x000064AC\n\
_080242DC: .4byte 0x00006460\n\
_080242E0:\n\
	subs r0, #1\n\
	strh r0, [r6, #4]\n\
_080242E4:\n\
	bl result_08024e0c\n\
	movs r0, #1\n\
_080242EA:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool32 printPlayerAllScore(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	movs r6, #0\n\
	ldr r0, _0802431C @ =gJoypad\n\
	ldrh r1, [r0]\n\
	movs r0, #0xb\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802430A\n\
	movs r6, #1\n\
	ldr r0, _08024320 @ =0x00004E21\n\
	strh r0, [r5, #4]\n\
_0802430A:\n\
	ldrb r0, [r5, #1]\n\
	cmp r0, #0x17\n\
	bls _08024312\n\
	b _08024774\n\
_08024312:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08024324 @ =_08024328\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0802431C: .4byte gJoypad\n\
_08024320: .4byte 0x00004E21\n\
_08024324: .4byte _08024328\n\
_08024328: @ jump table\n\
	.4byte _08024388 @ case 0\n\
	.4byte _080243AE @ case 1\n\
	.4byte _080243C8 @ case 2\n\
	.4byte _080243F2 @ case 3\n\
	.4byte _0802444A @ case 4\n\
	.4byte _08024464 @ case 5\n\
	.4byte _0802448C @ case 6\n\
	.4byte _080244BC @ case 7\n\
	.4byte _080244D6 @ case 8\n\
	.4byte _08024500 @ case 9\n\
	.4byte _08024530 @ case 10\n\
	.4byte _0802454A @ case 11\n\
	.4byte _08024574 @ case 12\n\
	.4byte _080245A4 @ case 13\n\
	.4byte _080245BE @ case 14\n\
	.4byte _080245E8 @ case 15\n\
	.4byte _0802461C @ case 16\n\
	.4byte _08024636 @ case 17\n\
	.4byte _08024664 @ case 18\n\
	.4byte _0802467E @ case 19\n\
	.4byte _080246AA @ case 20\n\
	.4byte _080246C2 @ case 21\n\
	.4byte _080246F4 @ case 22\n\
	.4byte _0802471C @ case 23\n\
_08024388:\n\
	ldr r0, _08024724 @ =gMission\n\
	movs r1, #7\n\
	ldrsb r1, [r0, r1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	movs r1, #0x10\n\
	movs r2, #2\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _080243A4\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_080243A4:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080243AE:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _080243BE\n\
	b _08024774\n\
_080243BE:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080243C8:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x16]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #2\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _080243E8\n\
	b _08024774\n\
_080243E8:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080243F2:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _08024402\n\
	b _08024774\n\
_08024402:\n\
	ldr r4, _08024724 @ =gMission\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #4\n\
	bl __udivsi3\n\
	movs r1, #0xe\n\
	movs r2, #3\n\
	bl printNumOnResultScreen\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x3c\n\
	bl __udivsi3\n\
	movs r1, #0x3c\n\
	bl __umodsi3\n\
	movs r1, #0x11\n\
	movs r2, #3\n\
	bl printNumOnResultScreen\n\
	movs r0, #0\n\
	movs r1, #0x10\n\
	movs r2, #3\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _08024440\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_08024440:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802444A:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _0802445A\n\
	b _08024774\n\
_0802445A:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024464:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x17]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #3\n\
	str r2, [sp]\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _08024482\n\
	b _08024774\n\
_08024482:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802448C:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _0802449C\n\
	b _08024774\n\
_0802449C:\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrh r0, [r0, #0xc]\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _080244B2\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_080244B2:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080244BC:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _080244CC\n\
	b _08024774\n\
_080244CC:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080244D6:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x18]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #4\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _080244F6\n\
	b _08024774\n\
_080244F6:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024500:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _08024510\n\
	b _08024774\n\
_08024510:\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrh r0, [r0, #0xe]\n\
	movs r1, #0x11\n\
	movs r2, #5\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _08024526\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_08024526:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024530:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _08024540\n\
	b _08024774\n\
_08024540:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802454A:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x19]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #5\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _0802456A\n\
	b _08024774\n\
_0802456A:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024574:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _08024584\n\
	b _08024774\n\
_08024584:\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrh r0, [r0, #0x14]\n\
	movs r1, #0x11\n\
	movs r2, #6\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _0802459A\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_0802459A:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080245A4:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _080245B4\n\
	b _08024774\n\
_080245B4:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080245BE:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x1a]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #6\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _080245DE\n\
	b _08024774\n\
_080245DE:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080245E8:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _080245F8\n\
	b _08024774\n\
_080245F8:\n\
	ldr r0, _08024724 @ =gMission\n\
	ldr r0, [r0]\n\
	adds r0, #0x4c\n\
	ldrb r0, [r0]\n\
	movs r1, #0x11\n\
	movs r2, #7\n\
	bl printNumOnResultScreen\n\
	cmp r6, #0\n\
	bne _08024612\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_08024612:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802461C:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bgt _0802462C\n\
	b _08024774\n\
_0802462C:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024636:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #0x1b]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #7\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	bne _0802465A\n\
	b _08024774\n\
_0802465A:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_08024664:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	bgt _08024674\n\
	b _08024774\n\
_08024674:\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802467E:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldrb r0, [r0, #5]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #9\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	beq _08024774\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080246AA:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	ble _08024774\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080246C2:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	ldr r0, _08024724 @ =gMission\n\
	ldr r1, [r0]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r1, r2]\n\
	ldrb r1, [r1, #0x10]\n\
	bl __divsi3\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #0xa\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl printResultScore\n\
	cmp r0, #1\n\
	beq _08024774\n\
	movs r0, #0\n\
	strh r0, [r5, #4]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080246F4:\n\
	ldrh r0, [r5, #4]\n\
	adds r0, #1\n\
	strh r0, [r5, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x1d\n\
	ble _08024774\n\
	ldr r0, _08024724 @ =gMission\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #1]\n\
	bl FUN_08024b54\n\
	movs r0, #0x1d\n\
	bl PlaySound\n\
	movs r0, #0\n\
	strh r0, [r5, #6]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_0802471C:\n\
	ldrh r0, [r5, #6]\n\
	adds r0, #1\n\
	strh r0, [r5, #6]\n\
	b _08024728\n\
	.align 2, 0\n\
_08024724: .4byte gMission\n\
_08024728:\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x3b\n\
	ble _08024774\n\
	ldr r0, _08024744 @ =gStageRun\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	beq _0802474C\n\
	ldr r0, _08024748 @ =gMission\n\
	ldr r1, [r0]\n\
	ldrb r0, [r1, #4]\n\
	strb r0, [r5, #0x18]\n\
	ldrb r0, [r1, #2]\n\
	b _08024756\n\
	.align 2, 0\n\
_08024744: .4byte gStageRun\n\
_08024748: .4byte gMission\n\
_0802474C:\n\
	ldr r0, _08024770 @ =gMission\n\
	ldr r1, [r0]\n\
	ldrb r0, [r1, #9]\n\
	strb r0, [r5, #0x18]\n\
	ldrb r0, [r1, #8]\n\
_08024756:\n\
	strb r0, [r5, #0x19]\n\
	adds r0, r5, #0\n\
	bl FUN_08024b98\n\
	adds r0, r5, #0\n\
	bl FUN_08024c48\n\
	movs r0, #0xc7\n\
	bl PlaySound\n\
	movs r0, #0\n\
	b _08024776\n\
	.align 2, 0\n\
_08024770: .4byte gMission\n\
_08024774:\n\
	movs r0, #1\n\
_08024776:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool32 getStageRewardChip(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r0, _080247B4 @ =gGameState\n\
	ldr r1, _080247B8 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r3, [r0]\n\
	ldrb r0, [r6, #1]\n\
	cmp r0, #0\n\
	bne _08024844\n\
	ldr r0, _080247BC @ =sStageChipTypes\n\
	ldr r1, _080247C0 @ =gStageRun\n\
	ldrh r4, [r1]\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	adds r7, r1, #0\n\
	cmp r0, #0\n\
	beq _08024844\n\
	adds r2, r0, #0\n\
	cmp r2, #2\n\
	beq _080247EC\n\
	cmp r2, #2\n\
	bgt _080247C4\n\
	cmp r2, #1\n\
	beq _080247CA\n\
	b _0802482E\n\
	.align 2, 0\n\
_080247B4: .4byte gGameState\n\
_080247B8: .4byte 0x000064AC\n\
_080247BC: .4byte sStageChipTypes\n\
_080247C0: .4byte gStageRun\n\
_080247C4:\n\
	cmp r2, #3\n\
	beq _08024810\n\
	b _0802482E\n\
_080247CA:\n\
	adds r5, r3, #0\n\
	adds r5, #0xb4\n\
	ldrb r3, [r5, #0x17]\n\
	ldr r0, _080247E8 @ =sStageChipIDs\n\
	adds r0, r4, r0\n\
	ldrb r1, [r0]\n\
	lsls r2, r1\n\
	adds r0, r3, #0\n\
	ands r0, r2\n\
	asrs r0, r1\n\
	cmp r0, #0\n\
	bne _0802484C\n\
	orrs r3, r2\n\
	strb r3, [r5, #0x17]\n\
	b _0802482E\n\
	.align 2, 0\n\
_080247E8: .4byte sStageChipIDs\n\
_080247EC:\n\
	adds r5, r3, #0\n\
	adds r5, #0xb4\n\
	ldrb r2, [r5, #0x18]\n\
	ldr r0, _0802480C @ =sStageChipIDs\n\
	adds r0, r4, r0\n\
	ldrb r1, [r0]\n\
	movs r3, #1\n\
	lsls r3, r1\n\
	adds r0, r2, #0\n\
	ands r0, r3\n\
	asrs r0, r1\n\
	cmp r0, #0\n\
	bne _0802484C\n\
	orrs r2, r3\n\
	strb r2, [r5, #0x18]\n\
	b _0802482E\n\
	.align 2, 0\n\
_0802480C: .4byte sStageChipIDs\n\
_08024810:\n\
	adds r5, r3, #0\n\
	adds r5, #0xb4\n\
	ldrb r2, [r5, #0x19]\n\
	ldr r0, _08024850 @ =sStageChipIDs\n\
	adds r0, r4, r0\n\
	ldrb r1, [r0]\n\
	movs r3, #1\n\
	lsls r3, r1\n\
	adds r0, r2, #0\n\
	ands r0, r3\n\
	asrs r0, r1\n\
	cmp r0, #0\n\
	bne _0802484C\n\
	orrs r2, r3\n\
	strb r2, [r5, #0x19]\n\
_0802482E:\n\
	ldr r1, _08024854 @ =sUnlockEquipTextIDs\n\
	ldrh r0, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r1, #0\n\
	bl PrintResultInline\n\
	ldrb r0, [r6, #1]\n\
	adds r0, #1\n\
	strb r0, [r6, #1]\n\
_08024844:\n\
	ldr r0, _08024858 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _0802485C\n\
_0802484C:\n\
	movs r0, #0\n\
	b _0802485E\n\
	.align 2, 0\n\
_08024850: .4byte sStageChipIDs\n\
_08024854: .4byte sUnlockEquipTextIDs\n\
_08024858: .4byte gTextWindow+8\n\
_0802485C:\n\
	movs r0, #1\n\
_0802485E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool32 getStageRewardExSkill(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, _080248D0 @ =gGameState\n\
	ldr r1, _080248D4 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	adds r4, r0, #0\n\
	adds r4, #0xb4\n\
	ldrb r0, [r4, #0x1a]\n\
	cmp r0, #1\n\
	beq _080248CC\n\
	ldrb r0, [r5, #1]\n\
	cmp r0, #0\n\
	bne _080248C4\n\
	ldr r1, _080248D8 @ =sStageRewardExSkills\n\
	ldr r7, _080248DC @ =gStageRun\n\
	ldrh r0, [r7]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r3, [r0]\n\
	cmp r3, #0xff\n\
	beq _080248BE\n\
	ldr r0, [r5, #0x10]\n\
	cmp r0, #4\n\
	bls _080248BE\n\
	ldrh r2, [r4, #0x14]\n\
	movs r6, #1\n\
	adds r1, r6, #0\n\
	lsls r1, r3\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	asrs r0, r3\n\
	cmp r0, #0\n\
	bne _080248CC\n\
	orrs r2, r1\n\
	strh r2, [r4, #0x14]\n\
	ldr r0, _080248E0 @ =sUnlockExSkillTextIDs\n\
	ldrh r1, [r7]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	movs r1, #0\n\
	bl PrintResultInline\n\
	str r6, [r5, #0xc]\n\
_080248BE:\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
_080248C4:\n\
	ldr r0, _080248E4 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _080248E8\n\
_080248CC:\n\
	movs r0, #0\n\
	b _080248EA\n\
	.align 2, 0\n\
_080248D0: .4byte gGameState\n\
_080248D4: .4byte 0x000064AC\n\
_080248D8: .4byte sStageRewardExSkills\n\
_080248DC: .4byte gStageRun\n\
_080248E0: .4byte sUnlockExSkillTextIDs\n\
_080248E4: .4byte gTextWindow+8\n\
_080248E8:\n\
	movs r0, #1\n\
_080248EA:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool32 FUN_080248f0(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #1]\n\
	cmp r5, #0\n\
	bne _0802491A\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	str r0, [r4, #0x14]\n\
	adds r0, #0x74\n\
	movs r1, #0x18\n\
	strh r1, [r0]\n\
	ldr r0, [r4, #0x14]\n\
	adds r0, #0x76\n\
	movs r1, #0x72\n\
	strh r1, [r0]\n\
	strh r5, [r4, #6]\n\
	ldrb r0, [r4, #1]\n\
	adds r0, #1\n\
	strb r0, [r4, #1]\n\
_0802491A:\n\
	ldr r0, _0802494C @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _08024924\n\
	b _08024A64\n\
_08024924:\n\
	movs r5, #0\n\
	ldrh r2, [r4, #6]\n\
	strh r2, [r4, #4]\n\
	ldr r0, _08024950 @ =gStageDiskManager\n\
	ldrb r1, [r0, #0xe]\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	beq _0802497C\n\
	ldr r0, _08024954 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802495C\n\
	lsls r0, r2, #0x10\n\
	cmp r0, #0\n\
	beq _08024958\n\
	subs r0, r2, #1\n\
	b _0802495A\n\
	.align 2, 0\n\
_0802494C: .4byte gTextWindow+8\n\
_08024950: .4byte gStageDiskManager\n\
_08024954: .4byte gJoypad\n\
_08024958:\n\
	ldrb r0, [r3, #0xe]\n\
_0802495A:\n\
	strh r0, [r4, #6]\n\
_0802495C:\n\
	ldr r0, _080249DC @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0802497C\n\
	ldrh r0, [r4, #6]\n\
	adds r0, #1\n\
	strh r0, [r4, #6]\n\
	movs r1, #6\n\
	ldrsh r0, [r4, r1]\n\
	ldrb r3, [r3, #0xe]\n\
	cmp r0, r3\n\
	ble _0802497C\n\
	movs r0, #0\n\
	strh r0, [r4, #6]\n\
_0802497C:\n\
	movs r2, #4\n\
	ldrsh r1, [r4, r2]\n\
	movs r2, #6\n\
	ldrsh r0, [r4, r2]\n\
	cmp r1, r0\n\
	beq _0802498E\n\
	movs r0, #1\n\
	bl PlaySound\n\
_0802498E:\n\
	movs r1, #6\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0\n\
	beq _08024A0E\n\
	ldr r0, _080249DC @ =gJoypad\n\
	ldrh r2, [r0, #4]\n\
	movs r3, #1\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080249F4\n\
	ldr r1, _080249E0 @ =gStageDiskManager\n\
	movs r2, #6\n\
	ldrsh r0, [r4, r2]\n\
	adds r0, r1, r0\n\
	ldrb r2, [r0, #3]\n\
	ldr r0, [r1]\n\
	lsrs r1, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r2\n\
	adds r0, #4\n\
	asrs r1, r0\n\
	ands r1, r3\n\
	cmp r1, #0\n\
	bne _080249EC\n\
	ldr r0, _080249E4 @ =gGameState\n\
	adds r1, r2, #0\n\
	movs r2, #1\n\
	bl openSecretDisk\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	bne _080249FE\n\
	ldr r5, _080249E8 @ =0x00000101\n\
	b _080249FE\n\
	.align 2, 0\n\
_080249DC: .4byte gJoypad\n\
_080249E0: .4byte gStageDiskManager\n\
_080249E4: .4byte gGameState\n\
_080249E8: .4byte 0x00000101\n\
_080249EC:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080249FE\n\
_080249F4:\n\
	movs r0, #0xa\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080249FE\n\
	strh r1, [r4, #6]\n\
_080249FE:\n\
	ldr r1, [r4, #0x14]\n\
	movs r2, #6\n\
	ldrsh r0, [r4, r2]\n\
	lsls r0, r0, #4\n\
	adds r0, #0x20\n\
	adds r1, #0x74\n\
	strh r0, [r1]\n\
	b _08024A2C\n\
_08024A0E:\n\
	ldr r0, [r4, #0x14]\n\
	adds r0, #0x74\n\
	movs r1, #0x18\n\
	strh r1, [r0]\n\
	ldr r0, _08024A28 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0xb\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08024A2C\n\
	movs r0, #0\n\
	b _08024A66\n\
	.align 2, 0\n\
_08024A28: .4byte gJoypad\n\
_08024A2C:\n\
	cmp r5, #0\n\
	beq _08024A4E\n\
	ldr r0, _08024A40 @ =0x00000101\n\
	cmp r5, r0\n\
	bne _08024A44\n\
	adds r0, r5, #0\n\
	movs r1, #1\n\
	bl PrintResultInline\n\
	b _08024A64\n\
	.align 2, 0\n\
_08024A40: .4byte 0x00000101\n\
_08024A44:\n\
	adds r0, r5, #0\n\
	movs r1, #0\n\
	bl PrintResultInline\n\
	b _08024A64\n\
_08024A4E:\n\
	ldr r0, _08024A6C @ =StringOfsTable\n\
	movs r1, #0xee\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _08024A70 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
_08024A64:\n\
	movs r0, #1\n\
_08024A66:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08024A6C: .4byte StringOfsTable\n\
_08024A70: .4byte gStringData\n\
 .syntax divided\n");
}

/*
  リザルト画面用の数値描画関数
  数値nを(8*x px, 8*y px)に描画
*/
NAKED static void printNumOnResultScreen(u32 n, u8 x, u8 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	mov sb, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r2, [sp, #4]\n\
	mov r6, sb\n\
	cmp r6, #0\n\
	bge _08024A96\n\
	rsbs r6, r6, #0\n\
_08024A96:\n\
	movs r1, #1\n\
	movs r4, #0xa\n\
	cmp r6, #0xa\n\
	blo _08024AAE\n\
_08024A9E:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r4\n\
	lsls r4, r0, #1\n\
	cmp r6, r4\n\
	bhs _08024A9E\n\
_08024AAE:\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	bge _08024ABC\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	b _08024ABE\n\
_08024ABC:\n\
	adds r4, r1, #0\n\
_08024ABE:\n\
	lsls r5, r4, #1\n\
	adds r0, r5, #0\n\
	bl Malloc\n\
	mov r8, r0\n\
	cmp r0, #0\n\
	beq _08024B38\n\
	mov sl, r5\n\
	mov r1, sb\n\
	lsrs r7, r1, #0x1f\n\
	ldr r2, [sp]\n\
	subs r2, r2, r4\n\
	str r2, [sp, #0xc]\n\
	ldr r0, [sp, #4]\n\
	lsls r0, r0, #5\n\
	str r0, [sp, #8]\n\
	cmp r4, r7\n\
	bls _08024B0A\n\
	mov r0, sl\n\
	subs r0, #2\n\
	mov r1, r8\n\
	adds r5, r0, r1\n\
_08024AEA:\n\
	adds r0, r6, #0\n\
	movs r1, #0xa\n\
	bl __umodsi3\n\
	ldr r2, _08024B48 @ =0x00005167\n\
	adds r0, r0, r2\n\
	strh r0, [r5]\n\
	subs r5, #2\n\
	subs r4, #1\n\
	adds r0, r6, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	adds r6, r0, #0\n\
	cmp r4, r7\n\
	bhi _08024AEA\n\
_08024B0A:\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	bge _08024B18\n\
	ldr r1, _08024B4C @ =0x00005174\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
_08024B18:\n\
	ldr r1, _08024B50 @ =gVideoRegBuffer+6\n\
	ldrh r0, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	ldr r0, [sp, #8]\n\
	adds r0, #1\n\
	ldr r2, [sp, #0xc]\n\
	adds r0, r2, r0\n\
	lsls r0, r0, #1\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	mov r2, sl\n\
	bl RequestBgMapTransfer\n\
_08024B38:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08024B48: .4byte 0x00005167\n\
_08024B4C: .4byte 0x00005174\n\
_08024B50: .4byte gVideoRegBuffer+6\n\
 .syntax divided\n");
}

static void FUN_08024b54(u8 rank) {
  u16* m = Malloc(2);
  if (m != NULL) {
    *m = 0x5166 - rank;
    RequestBgMapTransfer(m, (void*)SCREEN_BASE_16(1) + 738, 2);
  }
}

static void FUN_08024b98(struct ResultState* p) {
  s16 i;
  u16* m = Malloc(16);
  if (m != NULL) {
    if (p->codenamePrefix == CODENAME_NO_PREFIX) {
      for (i = 0; i < 8; i++) {
        m[i] = 0xF300 + u8_ARRAY_083863e8[p->codenameSuffix * 2] + i;
      }
    } else {
      for (i = 0; i < 8; i++) {
        m[i] = 0xF300 + u8_ARRAY_083863d0[p->codenamePrefix * 2] + i;
      }
    }
    RequestBgMapTransfer(m, (void*)SCREEN_BASE_16(1) + 802, 16);
  }
}

NAKED static void FUN_08024c48(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #0x18]\n\
	cmp r0, #0\n\
	beq _08024CF2\n\
	ldr r0, _08024D00 @ =u8_ARRAY_083863e8\n\
	mov r8, r0\n\
	ldrb r0, [r6, #0x19]\n\
	lsls r0, r0, #1\n\
	mov r1, r8\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r5, [r0]\n\
	lsls r4, r5, #1\n\
	adds r0, r4, #0\n\
	bl Malloc\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	beq _08024CF2\n\
	movs r0, #0\n\
	mov sb, r4\n\
	ldr r1, _08024D04 @ =u8_ARRAY_083863d0\n\
	mov ip, r1\n\
	ldr r3, _08024D08 @ =gVideoRegBuffer+6\n\
	mov sl, r3\n\
	cmp r0, r5\n\
	bge _08024CAE\n\
	ldr r1, _08024D0C @ =0xFFFFF300\n\
	adds r4, r1, #0\n\
_08024C8C:\n\
	lsls r2, r0, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r3, r2, #1\n\
	adds r3, r3, r7\n\
	ldrb r1, [r6, #0x19]\n\
	lsls r1, r1, #1\n\
	add r1, r8\n\
	adds r0, r4, r0\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r0, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r5\n\
	blt _08024C8C\n\
_08024CAE:\n\
	ldrb r0, [r6, #0x18]\n\
	lsls r0, r0, #1\n\
	mov r1, ip\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	adds r1, r2, r5\n\
	cmp r1, #9\n\
	ble _08024CCC\n\
	subs r1, #9\n\
	lsls r0, r2, #0x18\n\
	asrs r0, r0, #0x18\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_08024CCC:\n\
	cmp r5, #8\n\
	bne _08024CD6\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_08024CD6:\n\
	mov r3, sl\n\
	ldrh r0, [r3]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	ldr r3, _08024D10 @ =0x000001B1\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #1\n\
	adds r1, r1, r0\n\
	adds r0, r7, #0\n\
	mov r2, sb\n\
	bl RequestBgMapTransfer\n\
_08024CF2:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08024D00: .4byte u8_ARRAY_083863e8\n\
_08024D04: .4byte u8_ARRAY_083863d0\n\
_08024D08: .4byte gVideoRegBuffer+6\n\
_08024D0C: .4byte 0xFFFFF300\n\
_08024D10: .4byte 0x000001B1\n\
 .syntax divided\n");
}

NAKED static bool32 printResultScore(u8 score, u16 r1, u8 r2, u8 x, u8 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	ldr r0, [sp, #0x28]\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	lsls r2, r2, #0x18\n\
	lsrs r5, r2, #0x18\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	mov sb, r3\n\
	mov r2, sb\n\
	str r2, [sp]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	str r0, [sp, #4]\n\
	asrs r0, r7, #4\n\
	movs r2, #1\n\
	mov sl, r2\n\
	cmp r0, #0\n\
	beq _08024D4A\n\
	mov sl, r0\n\
_08024D4A:\n\
	cmp r5, #0\n\
	bne _08024D56\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	mov r2, r8\n\
	b _08024D9C\n\
_08024D56:\n\
	lsls r4, r1, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl __divsi3\n\
	adds r6, r0, #0\n\
	adds r0, r6, #0\n\
	muls r0, r5, r0\n\
	cmp r0, r4\n\
	bne _08024D72\n\
	movs r0, #0x34\n\
	bl PlaySound\n\
_08024D72:\n\
	mov r0, sl\n\
	muls r0, r6, r0\n\
	adds r2, r0, #0\n\
	cmp r0, #0\n\
	bge _08024D7E\n\
	rsbs r2, r0, #0\n\
_08024D7E:\n\
	adds r1, r7, #0\n\
	cmp r7, #0\n\
	bge _08024D86\n\
	rsbs r1, r7, #0\n\
_08024D86:\n\
	cmp r2, r1\n\
	bgt _08024D96\n\
	mov r1, sb\n\
	mov r2, r8\n\
	bl printNumOnResultScreen\n\
	movs r0, #1\n\
	b _08024DA2\n\
_08024D96:\n\
	adds r0, r7, #0\n\
	ldr r1, [sp]\n\
	ldr r2, [sp, #4]\n\
_08024D9C:\n\
	bl printNumOnResultScreen\n\
	movs r0, #0\n\
_08024DA2:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static void FUN_08024db4(void) {
  struct Coord* c = &gGameState.unk_0dc4;
  c->x = PIXEL(120);
  c->y = PIXEL(80);
  ResetPivot(&gGameState.unk_0db8, c, 0, 0);
  ResetTaskManager(&gGameState.taskManager2);
  SetTaskPivot(&gGameState.taskManager2, &gGameState.unk_0db8);
  InitWidgetHeader(&gGameState.entityHeaders[ENTITY_WIDGET], gWidgets, 64);
}

static void result_08024e0c(void) {
  struct Coord* c = &gGameState.unk_0dc4;
  c->x = PIXEL(BGOFS(1)->x & 0x1FF) + PIXEL(120);
  ClearTaskBuffer(&gGameState.taskManager2);
  UpdateEntities(gWidgetHeaderPtr);
  DrawEntity(gWidgetHeaderPtr, &gGameState.taskManager2);
  RunAllTasks(&gGameState.taskManager2);
}

// clang-format off
static const u8 sStageChipTypes[STAGE_COUNT] = {
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_BODY,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_FOOT,
    STAGE_CHIP_BODY,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
    STAGE_CHIP_NONE,
}; // ステージクリアしたときの報酬としてもらえるチップ
// clang-format on

// sStageChipTypes[i] が BODY, sStageChipIDs[i] が4 ならBODYの4 つまり フレイムチップ
static const u8 sStageChipIDs[STAGE_COUNT] = {
    0, 0, 4, 5, 3, 1, 0, 0, 0, 0, 4, 2, 5, 3, 2, 0, 0, 0,
};

static const TextID sUnlockEquipTextIDs[STAGE_COUNT] = {
    0x0000, 0x0000, 0x0118, 0x0117, 0x0119, 0x0116, 0x0000, 0x0000, 0x0000, 0x0000, 0x011E, 0x011C, 0x011D, 0x011B, 0x011A, 0x0000, 0x0000, 0x0000,
};

// clang-format off
static const u32 sStageRewardExSkills[STAGE_COUNT] = {
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_BURST,
    EXSKILL_ID_THROW,
    EXSKILL_ID_SMASH,
    EXSKILL_ID_THOUSAND,
    EXSKILL_ID_NONE,
    EXSKILL_ID_SWEEP,
    EXSKILL_ID_SPLIT,
    EXSKILL_ID_BLIZZ,
    EXSKILL_ID_LASER,
    EXSKILL_ID_SOUL,
    EXSKILL_ID_ORBIT,
    EXSKILL_ID_VSHOT,
    EXSKILL_ID_GALE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
    EXSKILL_ID_NONE,
};
// clang-format on

static const TextID sUnlockExSkillTextIDs[STAGE_COUNT] = {
    0x0000, 0x0000, 0x010C, 0x010B, 0x010D, 0x010A, 0x0000, 0x0113, 0x010F, 0x010E, 0x0111, 0x0114, 0x0110, 0x0115, 0x0112, 0x0000, 0x0000, 0x0000,
};
