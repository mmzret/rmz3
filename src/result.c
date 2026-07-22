#include "result.h"
#include "text_ids.h"

#include "game.h"
#include "global.h"
#include "palette_animation.h"
#include "score.h"
#include "sprite.h"
#include "stagerun.h"
#include "story.h"
#include "text_window.h"
#include "widget.h"
#include "zero.h"

#define STAGE_CHIP_NONE 0
#define STAGE_CHIP_HEAD 1
#define STAGE_CHIP_BODY 2
#define STAGE_CHIP_FOOT 3

extern const u8 u8_ARRAY_083863d0[24];
extern const u8 u8_ARRAY_083863e8[40];

static const u8 sStageChipTypes[STAGE_COUNT];
static const u8 sStageChipIDs[STAGE_COUNT];
static const TextID sUnlockEquipTextIDs[STAGE_COUNT];
static const u32 sStageRewardExSkills[STAGE_COUNT];
static const TextID sUnlockExSkillTextIDs[STAGE_COUNT];

static void printNumOnResultScreen(s32 n, u8 x8, u8 y8);
static void PrintResultRank(u8 rank);
static void PrintCodeName1(struct ResultState* p);
static void PrintCodeName2(struct ResultState* p);
static bool32 CountUpResultScore(s32 score, s16 step, u8 se_interval, u8 x8, u8 y8);

static void ResultScreen_InitWidget(void);
static void ResultScreen_UpdateAndRenderWidget(void);

bool8 IsAllElfUnlocked(Player* _);
bool8 IsElfBreeder(Player* _);
bool8 allSecretDiskFound(void);
void CalcMissionScore(void);
u8 CalcElfPenalty(Player* p);

void CreateDiskIcon(Coords32* c, u8 n, u8 r2);

// 0x08023f00
void ResultScreen_Init(struct ResultState* p) {
  u8 i;
  Coords32 c;

  ResultScreen_InitWidget();
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  gBlendRegBuffer.bldclt = 0;
  LOAD_STATIC_GRAPHIC(SM014_CHIPICON);
  LOAD_STATIC_GRAPHIC(SM127_DISABLED_DISK);
  c.y = PIXEL(114);
  for (i = 0; i < gStageDiskManager.stageDiskCount; i++) {
    c.x = i * PIXEL(16) + PIXEL(48);
    CreateDiskIcon(&c, gStageDiskManager.stageDiskIDs[i], 0);
  }
  p->mode[0] = p->mode[1] = p->mode[2] = p->mode[3] = 0;
  p->frame = p->unk_06 = p->unk_08 = p->unk_0a = 0;
  p->unk_0c = 0;
}

static bool32 printPlayerAllScore(struct ResultState* p);
static bool32 getStageRewardChip(struct ResultState* p);
static bool32 getStageRewardExSkill(struct ResultState* p);
static bool32 FUN_080248f0(struct ResultState* p);

/**
 * @brief リザルト画面のときに毎フレーム実行される
 * @return まだリザルト画面かどうか (TRUE: まだリザルト画面, FALSE: リザルト画面が終了)
 * @note 0x0802400c
 */
NON_MATCH bool32 ResultScreen_Update(struct ResultState* p) {
#if MODERN
  switch (p->mode[0]) {
    case 0: {
      p->rank = (gScore.total)->rank;
      if (IsAllElfUnlocked(gGameState.z2)) {
        (gScore.total)->allElfCompleted = TRUE;
        if (IsElfBreeder(gGameState.z2)) (gScore.total)->allCyberElfBreeded = TRUE;
      }
      if (allSecretDiskFound()) (gScore.total)->allSecretDiskFound = TRUE;
      gScore.elfPenalty += CalcElfPenalty(gGameState.z2);
      CalcMissionScore();
      BGCNT16(1) = BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(2);  // 0x204
      RESET_BGOFS(1);
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= (DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
      LoadGraphic(&gGraphic_MiscMenu, BG_CHAR_OFFSET(1));
      LoadPalette(&gPalette_MiscMenu, 0);
      LoadGraphic(BG_GRAPHIC(BG_CODENAME), CHAR_BASE(1));
      LoadPalette(BG_PALETTE(BG_CODENAME), 0);
      CopyBgMap(SCREEN_ADDR(1), SELF_REL_PTR(&gBgMapOffsets[100]), 0, 0);
      PauseAllPaletteAnimations();
      StartPaletteAnimation(64, 0);
      gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN1_ON;
      if (gStageRun.vm.bgm != BGM_RESULT) {
        if (gStageRun.vm.bgm != MUS_NONE) {
          FadeOutBGM(gStageRun.vm.bgm & 0xFFFF);
          gStageRun.vm.bgm = MUS_NONE;
        }
        PlayBGM(BGM_RESULT);
        gStageRun.vm.bgm = BGM_RESULT;
      }
      gStageRun.vm.transition = TRANSITION_Z | TRANSITION_REVERSE;
      p->mode[0]++;
      FALLTHROUGH;
    }
    case 1: {
      StepPaletteAnimation(64);
      if (gStageRun.vm.transition == TRANSITION_NONE) {
        gPaletteManager.buf[0] = RGB_BLACK;
        p->mode[1] = 0;
        p->mode[0]++;
      }
      break;
    }
    case 2: {
      StepPaletteAnimation(64);
      if (printPlayerAllScore(p) != TRUE) {
        p->mode[1] = 0;
        p->mode[0]++;
      }
      break;
    }
    case 3: {
      StepPaletteAnimation(64);
      if (getStageRewardChip(p) != TRUE) {
        p->mode[1] = 0;
        p->mode[0]++;
      }
      break;
    }
    case 4: {
      StepPaletteAnimation(64);
      if (getStageRewardExSkill(p) != TRUE) {
        p->mode[1] = 0;
        p->mode[0]++;
      }
      break;
    }
    case 5: {
      StepPaletteAnimation(64);
      if (FUN_080248f0(p) != TRUE) {
        p->mode[1] = 0;
        p->mode[0]++;
      }
      break;
    }
    case 6: {
      StepPaletteAnimation(64);
      if (gStageRun.vm.bgm != MUS_NONE) {
        FadeOutBGM(gStageRun.vm.bgm & 0xFFFF);
        gStageRun.vm.bgm = MUS_NONE;
      }
      gStageRun.vm.transition = TRANSITION_Z | TRANSITION_BLACKOUT;
      p->mode[0]++;
      break;
    }
    case 7: {
      StepPaletteAnimation(64);
      if (gStageRun.vm.transition != TRANSITION_NONE) {
        break;
      }
      gVideoRegBuffer.dispcnt &= ~(DISPCNT_OBJ_ON | DISPCNT_BG1_ON);  // &= 0xEDFF
      RemovePaletteAnimation(64);
      ResumeAllPaletteAnimations();
      p->frame = 60;
      p->mode[0]++;
      FALLTHROUGH;
    }
    case 8: {
      if (p->frame == 0) {
        (gScore.total)->fusionCount = 0;
        StoreZeroStatus(gGameState.z2, &gGameState.save.status);
        ResultScreen_UpdateAndRenderWidget();
        return FALSE;
      }
      p->frame--;
      break;
    }
  }
  ResultScreen_UpdateAndRenderWidget();
  return TRUE;
#else
  INCCODE("asm/wip/ResultScreen_Update.inc");
#endif
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
	ldr r0, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x16]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #2\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r4, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x17]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #3\n\
	str r2, [sp]\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x18]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #4\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x19]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #5\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x1a]\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #6\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #0x1b]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #7\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldrb r0, [r0, #5]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r2, #4\n\
	ldrsh r1, [r5, r2]\n\
	movs r2, #9\n\
	str r2, [sp]\n\
	movs r2, #3\n\
	movs r3, #0x18\n\
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
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
	bl CountUpResultScore\n\
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
	ldr r0, _08024724 @ =gScore\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #1]\n\
	bl PrintResultRank\n\
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
_08024724: .4byte gScore\n\
_08024728:\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x3b\n\
	ble _08024774\n\
	ldr r0, _08024744 @ =gStageRun\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	beq _0802474C\n\
	ldr r0, _08024748 @ =gScore\n\
	ldr r1, [r0]\n\
	ldrb r0, [r1, #4]\n\
	strb r0, [r5, #0x18]\n\
	ldrb r0, [r1, #2]\n\
	b _08024756\n\
	.align 2, 0\n\
_08024744: .4byte gStageRun\n\
_08024748: .4byte gScore\n\
_0802474C:\n\
	ldr r0, _08024770 @ =gScore\n\
	ldr r1, [r0]\n\
	ldrb r0, [r1, #9]\n\
	strb r0, [r5, #0x18]\n\
	ldrb r0, [r1, #8]\n\
_08024756:\n\
	strb r0, [r5, #0x19]\n\
	adds r0, r5, #0\n\
	bl PrintCodeName1\n\
	adds r0, r5, #0\n\
	bl PrintCodeName2\n\
	movs r0, #0xc7\n\
	bl PlaySound\n\
	movs r0, #0\n\
	b _08024776\n\
	.align 2, 0\n\
_08024770: .4byte gScore\n\
_08024774:\n\
	movs r0, #1\n\
_08024776:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

#define PLAYER_STATE(z) (&((z)->unk_b4))

/**
 * @brief ステージ報酬のチップを獲得する
 * @return TRUE: get new chip, FALSE: already have chip or no chip
 * @note 0x08024780
 */
static bool32 getStageRewardChip(struct ResultState* p) {
  struct GameState* g = &gGameState;
  struct Zero* player = g->z2;

  if (p->mode[1] == 0) {
    if (sStageChipTypes[gStageRun.id] != STAGE_CHIP_NONE) {
      switch (sStageChipTypes[gStageRun.id]) {
        case STAGE_CHIP_HEAD: {
          u8 unlocked = (PLAYER_STATE(player)->status).unlockedHead;
          u32 chip_id = sStageChipIDs[gStageRun.id];
          if ((unlocked & (1 << chip_id)) >> chip_id) {
            return FALSE;
          }
          (PLAYER_STATE(player)->status).unlockedHead |= (1 << chip_id);
          break;
        }
        case STAGE_CHIP_BODY: {
          u8 unlocked = (PLAYER_STATE(player)->status).unlockedBody;
          u32 chip_id = sStageChipIDs[gStageRun.id];
          if ((unlocked & (1 << chip_id)) >> chip_id) {
            return FALSE;
          }
          (PLAYER_STATE(player)->status).unlockedBody |= (1 << chip_id);
          break;
        }
        case STAGE_CHIP_FOOT: {
          u8 unlocked = (PLAYER_STATE(player)->status).unlockedFoot;
          u32 chip_id = sStageChipIDs[gStageRun.id];
          if ((unlocked & (1 << chip_id)) >> chip_id) {
            return FALSE;
          }
          (PLAYER_STATE(player)->status).unlockedFoot |= (1 << chip_id);
          break;
        }
      }
      PrintResultInline(sUnlockEquipTextIDs[gStageRun.id], 0);
      p->mode[1]++;
    }
  }

  if (((&gTextWindow.text)->mode) != 0) {
    return TRUE;
  }
  return FALSE;
}

static bool32 getStageRewardExSkill(struct ResultState* p) {
  struct GameState* g = &gGameState;
  struct Zero* player = g->z2;

  if ((PLAYER_STATE(player)->status).menuZeroColor == MZC_HARD) return FALSE;

  if (p->mode[1] == 0) {
    u32 id = sStageRewardExSkills[gStageRun.id];
    if ((id != EXSKILL_ID_NONE) && (p->rank >= RANK_A)) {
      if (((PLAYER_STATE(player)->status).unlockedExSkill & (1 << id)) >> id) {
        return FALSE;
      }
      (PLAYER_STATE(player)->status).unlockedExSkill |= (1 << id);
      PrintResultInline(sUnlockExSkillTextIDs[gStageRun.id], 0);
      p->unk_0c = 1;
    }
    p->mode[1]++;
  }

  if (((&gTextWindow.text)->mode) != 0) {
    return TRUE;
  }
  return FALSE;
}

#undef PLAYER_STATE

// 0x080248f0
NAKED static bool32 FUN_080248f0(struct ResultState* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #1]\n\
	cmp r5, #0\n\
	bne _0802491A\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateSquareCursor\n\
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
	bl OpenSecretDisk\n\
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
NAKED static void printNumOnResultScreen(s32 n, u8 x8, u8 y8) {
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

// 0x08024b54
static void PrintResultRank(u8 rank) {
  u16* m = Malloc(2);
  if (m != NULL) {
    *m = (TILE_PAL(5) | 0x166) - rank;
    RequestBgMapTransfer(m, (void*)SCREEN_BASE(1) + 738, 2);
  }
}

// 0x08024b98
static void PrintCodeName1(struct ResultState* p) {
  s16 i;
  u16* m = Malloc(16);
  if (m != NULL) {
    if (p->codenamePrefix == 0) {  // no prefix
      for (i = 0; i < 8; i++) {
        m[i] = (TILE_PAL(15) | 0x300) + u8_ARRAY_083863e8[p->codenameSuffix * 2] + i;
      }
    } else {
      for (i = 0; i < 8; i++) {
        m[i] = (TILE_PAL(15) | 0x300) + u8_ARRAY_083863d0[p->codenamePrefix * 2] + i;
      }
      // 残りのコードネームは PrintCodeName2 で描画する
    }
    RequestBgMapTransfer(m, (void*)SCREEN_BASE(1) + 802, 16);
  }
}

// 0x08024c48
// 称号が AAのBB みたいに 2つに分かれている場合に、BBの方を描画する (別れていないならこの関数では何もしない)
NAKED static void PrintCodeName2(struct ResultState* p) {
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

// リザルトスコアをカウントアップさせる演出
NON_MATCH static bool32 CountUpResultScore(s32 score, s16 step, u8 se_interval, u8 x8, u8 y8) {
#if MODERN
  s32 turbo;
  if (score >> 4) {
    turbo = (score >> 4);  // スコアが大きい時はカウントアップを速くする
  } else {
    turbo = 1;
  }

  if (se_interval != 0) {
    s32 n = step / se_interval;
    if ((se_interval * n) == step) {
      PlaySound(SE_RESULT);
    }
    n *= turbo;
    if (abs(n) <= abs(score)) {
      printNumOnResultScreen(n, x8, y8);
      return TRUE;
    }
  }

  printNumOnResultScreen(score, x8, y8);
  return FALSE;
#else
  INCCODE("asm/wip/CountUpResultScore.inc");
#endif
}

/**
 * @brief Widgetのアロケータ + それを描画する Renderer の初期化
 * @note 0x08024db4
 */
static void ResultScreen_InitWidget(void) {
  Coords32* c = &gGameState.unk_0dc4;
  c->x = PIXEL(120), c->y = PIXEL(80);
  ResetPivot(&gGameState.unk_0db8, c, 0, 0);
  Renderer_Init(&gGameState.rendererUI);
  Renderer_SetPivot(&gGameState.rendererUI, &gGameState.unk_0db8);
  InitWidgetHeader(&gGameState.entityHeaders[ENTITY_WIDGET], gWidgets, 64);
}

/**
 * @brief Widgetを更新して描画する
 * @note 0x08024e0c
 */
static void ResultScreen_UpdateAndRenderWidget(void) {
  Coords32* c = &gGameState.unk_0dc4;
  c->x = PIXEL(BGOFS(1)->x & 0x1FF) + PIXEL(120);
  Renderer_Clear(&gGameState.rendererUI);
  UpdateEntities(gWidgetHeaderPtr);
  DrawEntity(gWidgetHeaderPtr, &gGameState.rendererUI);
  Renderer_Flush(&gGameState.rendererUI);
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
    0x0000, 0x0000, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_FLAMEBODY_CHIP, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_ICEBODY_CHIP, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_THUNDERBODY_CHIP, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_LIGHTBODY_CHIP, 0x0000, 0x0000, 0x0000, 0x0000, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_QUICKFOOT_CHIP, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_DOUBLE_JUMPFOOT, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SPIKEFOOT_CHIP, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SHADOW_DASHFOOT, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_ABSORBERBODY_CHIP, 0x0000, 0x0000, 0x0000,
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
    0x0000, 0x0000, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_2, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_3, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_4, TEXT_OPEN_SECRET_DISK_YOU_CAPTURED_THE_EX_SKILLOF_ALIAS6, 0x0000, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_7, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_8, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_9, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_10, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_11, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_12, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_13, TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_14, 0x0000, 0x0000, 0x0000,
};
