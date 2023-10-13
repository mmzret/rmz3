#include "intro.h"

#include "blink.h"
#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "mmbn4.h"
#include "motion.h"
#include "sprite.h"
#include "sram.h"
#include "syssav.h"
#include "system.h"
#include "text.h"

static const KEY_INPUT* const sDemoplayKeyInputs[4];
static const u8* const sDemoplayKeyFrames[4];
static const u8 sDemoplayStageIDs[4];
static const struct Coord Coord_ARRAY_08385fa4[9];
static const IntroLoopFunc sIntroMinigameScripts[4];
static const u8 u8_ARRAY_08385f9c[7];
static const s32 s32_ARRAY_08385fec[8];
static const s32 s32_ARRAY_ARRAY_0838600c[16];
static const struct Coord s32_ARRAY_ARRAY_0838604c[4];

static void IntroLoop_CapcomInti(struct Intro* p);
static void IntroLoop_ComeBackTitle(struct Intro* p);
static void IntroLoop_sram_080ebb74(struct Intro* p);
static void IntroLoop_sram_080ebcd4(struct Intro* p);
static void IntroLoop_TitleScreen(struct Intro* p);
static void IntroLoop_080ed8dc(struct Intro* p);
static void IntroLoop_Minigame(struct Intro* p);
static void initGameSavedata(struct Intro* p);
static void demoplay_080ebe84(struct Intro* p);
static u8 intro_080ecd28(struct Intro* p);
static void loadTitleScreen(struct Intro* _ UNUSED);
static void FUN_080ed07c(struct Intro* p);
static void intro_080ed108(struct Intro* p);
static void intro_080ed1d4(struct Intro* p);
static void intro_080ed2a0(struct Intro* p);
static void intro_080ed480(struct Intro* p, u8 step);
static void FUN_080ed57c(motion_t m, s32 x, s32 y, u16 r3, u8 r4);
static void FUN_080ed6c4(struct Intro* p);
static void intro_080ed770(struct Intro* p, u8 r1);

/*
  Process の1つ
  無限ループとして、 gIntroLoops を実行し続ける
  ただし、 gIntroLoops の実行後は GameLoop に処理を戻し、別のProcessを挟む
*/
void Process_Intro(struct Process* p) {
  // clang-format off
  static const IntroLoopFunc sIntroLoops[7] = {
      [0] = IntroLoop_CapcomInti,
      [1] = IntroLoop_ComeBackTitle,
      [2] = IntroLoop_sram_080ebb74,
      [3] = IntroLoop_sram_080ebcd4,
      [4] = IntroLoop_TitleScreen,
      [5] = IntroLoop_080ed8dc,
      [6] = IntroLoop_Minigame,
  };
  // clang-format on
  FUN_08002428(p);
  do {
    sIntroLoops[gIntro.mode[0]](&gIntro);
    SwitchProcess(TRUE);
  } while (TRUE);
}

static const KEY_INPUT sDemoplayKeyInputs_Volcano[144] = {
    0x0000, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC02, 0xFE12, 0xFE13, 0xFE12, 0xFF12, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFE12, 0xFE13, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFF12, 0xFE12, 0xFC02, 0xFC22, 0xFE22, 0xFC22, 0xFC02, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC02, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFE12, 0xFC12, 0xFC02, 0xFC00, 0xFC02, 0xFC12, 0xFC92, 0xFC82, 0xFCA2, 0xFC22, 0xFD22, 0xFC22, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFE10, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFC12,
    0xFC02, 0xFD02, 0xFC02, 0xFD02, 0xFC02, 0xFC03, 0xFC13, 0xFC93, 0xFC92, 0xFC90, 0xFC80, 0xFC82, 0xFCA2, 0xFC22, 0xFE23, 0xFE22, 0xFC22, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE93, 0xFE92, 0xFE90, 0xFE80, 0xFE82, 0xFE92, 0xFC92, 0xFE92, 0xFE12, 0xFE13, 0xFC12, 0xFC02, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

static const u8 sDemoplayFrames_Volcano[144] = {
    0, 36, 2, 2, 10, 20, 90, 3, 6, 4, 11, 9, 1, 8, 1, 3, 15, 13, 6, 195, 4, 21, 7, 19, 2, 1, 8, 1, 3, 11, 1, 12, 10, 26, 1, 24, 14, 12, 1, 2, 14, 16, 9, 4, 23, 7, 13, 24, 46, 4, 4, 28, 54, 2, 1, 2, 1, 9, 38, 8, 1, 18, 18, 1, 4, 2, 26, 4, 19, 5, 32, 31, 5, 5, 5, 6, 62, 8, 10, 1, 1, 3, 1, 17, 12, 10, 13, 10, 4, 14, 3, 9, 44, 3, 3, 2, 2, 1, 42, 8, 2, 1, 28, 21, 174, 23, 1, 6, 2, 3, 17, 12, 2, 11, 1, 4, 17, 15, 3, 8, 1, 2, 18, 14, 2, 10, 1, 3, 20, 11, 2, 12, 1, 2, 18, 12, 3, 5, 0, 0, 0, 0, 0, 0,
};

static const KEY_INPUT sDemoplayKeyInputs_Ocean[160] = {
    0x0000, 0xFC02, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC13, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFE12, 0xFC12, 0xFC02, 0xFC12, 0xFC02, 0xFC12, 0xFC02, 0xFE22, 0xFE23, 0xFE22, 0xFC22, 0xFC02, 0xFE12, 0xFE13, 0xFE12, 0xFE92, 0xFCA2, 0xFC22, 0xFC92, 0xFD12, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFE13, 0xFC13, 0xFC12, 0xFC02, 0xFC22, 0xFD22, 0xFD02, 0xFC02, 0xFC22, 0xFC02, 0xFC03, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC13, 0xFC12, 0xFD12, 0xFC12, 0xFC22, 0xFC20, 0xFC00, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFC02, 0xFC22, 0xFC62, 0xFC42, 0xFC12, 0xFD02, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFC12,
    0xFE12, 0xFC10, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFC22, 0xFC02, 0xFC03, 0xFD03, 0xFD13, 0xFC13, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC10, 0xFC00, 0xFC02, 0xFC22, 0xFC62, 0xFC02, 0xFC12, 0xFD12, 0xFD02, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFE10, 0xFE12, 0xFC12, 0xFC13, 0xFC12, 0xFC92, 0xFCA2, 0xFC22, 0xFC92, 0xFC12, 0xFD12, 0xFD02, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFE13, 0xFC13, 0xFC10, 0xFC12, 0xFC02, 0xFC22, 0xFE22, 0xFC22, 0xFC23, 0xFC22, 0xFC02, 0xFC12, 0xFE12, 0xFC12, 0xFE12, 0xFC13, 0xFC03, 0xFC12, 0xFC13, 0xFC12, 0xFC13, 0xFC12, 0xFE12, 0xFE13, 0xFE12, 0xFC12, 0xFC02, 0xFE02, 0xFE23, 0xFE63, 0x0000, 0x0000,
};

static const u8 sDemoplayFrames_Ocean[160] = {
    0, 31, 7, 21, 4, 3, 11, 19, 11, 11, 3, 20, 12, 2, 62, 43, 25, 15, 39, 1, 29, 5, 3, 10, 5, 19, 2, 1, 1, 2, 1, 10, 11, 3, 9, 5, 20, 21, 6, 16, 38, 1, 42, 10, 3, 7, 8, 13, 24, 4, 12, 38, 1, 2, 24, 1, 5, 14, 11, 10, 23, 10, 1, 4, 19, 5, 41, 61, 4, 3, 1, 1, 6, 10, 10, 5, 18, 5, 15, 7, 19, 5, 27, 3, 22, 7, 5, 8, 6, 11, 12, 1, 21, 9, 13, 4, 14, 3, 2, 16, 3, 2, 1, 3, 4, 6, 8, 7, 19, 6, 7, 2, 14, 15, 14, 12, 2, 1, 3, 2, 6, 4, 6, 14, 6, 21, 6, 18, 3, 2, 5, 10, 49, 23, 20, 1, 6, 6, 48, 1, 17, 6, 26, 4, 28, 8, 16, 18, 9, 23, 26, 18, 8, 4, 20, 1, 4, 1, 0, 0,
};

static const KEY_INPUT sDemoplayKeyInputs_RepairFactory[136] = {
    0x0000, 0xFD00, 0xFD10, 0xFF10, 0xFF11, 0xFF10, 0xFF11, 0xFF91, 0xFF81, 0xFF21, 0xFF20, 0xFD00, 0xFD02, 0xFD00, 0xFD02, 0xFD00, 0xFD20, 0xFF20, 0xFF61, 0xFF41, 0xFD40, 0xFD50, 0xFD40, 0xFD50, 0xFD10, 0xFF10, 0xFD10, 0xFF10, 0xFD10, 0xFF10, 0xFF11, 0xFF10, 0xFD10, 0xFC10, 0xFC00, 0xFD00, 0xFD10, 0xFF10, 0xFD10, 0xFF10, 0xFF11, 0xFD11, 0xFD10, 0xFD00, 0xFD01, 0xFD03, 0xFD02, 0xFD03, 0xFC03, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFC13, 0xFC12, 0xFC10, 0xFC12, 0xFC02, 0xFC03, 0xFC13, 0xFC12, 0xFC13, 0xFC12, 0xFC02, 0xFC22, 0xFC02, 0xFC12, 0xFC13,
    0xFC12, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFC12, 0xFC02, 0xFC00, 0xFC02, 0xFC12, 0xFC13, 0xFC12, 0xFC10, 0xFC12, 0xFE12, 0xFC12, 0xFC92, 0xFC82, 0xFC83, 0xFC03, 0xFC02, 0xFC22, 0xFC02, 0xFC12, 0xFC02, 0xFC22, 0xFC02, 0xFC12, 0xFC02, 0xFC12, 0xFC92, 0xFC82, 0xFC22, 0xFC00, 0xFC02, 0xFC22, 0xFC23, 0xFC22, 0xFC23, 0xFC22, 0xFC02, 0xFC12, 0xFC02, 0xFC22, 0xFC02, 0xFC12, 0xFE12, 0xFE13, 0xFC13, 0xFC12, 0xFC13, 0xFC12, 0xFC13, 0xFC12, 0xFC13, 0xFC12, 0xFC10, 0xFC00, 0xFC02, 0xFC12, 0xFE12, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

static const u8 sDemoplayFrames_RepairFactory[136] = {
    0, 14, 13, 20, 12, 6, 1, 2, 1, 12, 14, 6, 5, 4, 6, 19, 10, 3, 22, 1, 3, 22, 24, 3, 4, 25, 7, 32, 24, 2, 11, 9, 64, 1, 4, 11, 23, 27, 6, 17, 19, 2, 8, 15, 11, 7, 79, 8, 3, 33, 1, 7, 27, 2, 3, 5, 1, 33, 12, 10, 16, 24, 16, 7, 32, 2, 47, 13, 14, 8, 3, 6, 21, 13, 30, 5, 42, 1, 12, 1, 4, 25, 21, 1, 2, 2, 8, 2, 34, 53, 27, 49, 21, 47, 28, 40, 17, 19, 1, 1, 9, 3, 31, 1, 29, 11, 23, 7, 11, 20, 15, 8, 19, 3, 3, 26, 1, 32, 22, 6, 10, 5, 9, 1, 2, 3, 40, 16, 26, 0, 0, 0, 0, 0, 0, 0,
};

static const KEY_INPUT sDemoplayKeyInputs_OldLifeArea[144] = {
    0x0000, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFE11, 0xFC11, 0xFC10, 0xFC11, 0xFC10, 0xFC11, 0xFE11, 0xFE81, 0xFE21, 0xFC21, 0xFC20, 0xFC00, 0xFC02, 0xFC00, 0xFC20, 0xFE20, 0xFC20, 0xFE20, 0xFE21, 0xFE20, 0xFE21, 0xFE20, 0xFE21, 0xFE61, 0xFE11, 0xFE10, 0xFC10, 0xFC00, 0xFC02, 0xFC00, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFE11, 0xFC11, 0xFC10, 0xFC11, 0xFC10, 0xFC11, 0xFE91, 0xFE21, 0xFE20, 0xFC20, 0xFC00, 0xFC02, 0xFC22, 0xFC02, 0xFC00, 0xFC20, 0xFC21, 0xFC20, 0xFC21, 0xFC20, 0xFC21, 0xFC20, 0xFC81, 0xFC91, 0xFE11, 0xFE10, 0xFC10, 0xFC11, 0xFC10, 0xFC00, 0xFC01,
    0xFC11, 0xFD11, 0xFC11, 0xFC10, 0xFE10, 0xFC10, 0xFC00, 0xFC10, 0xFC11, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFE11, 0xFC11, 0xFC10, 0xFC00, 0xFD00, 0xFC00, 0xFC10, 0xFD00, 0xFC00, 0xFC10, 0xFC00, 0xFD00, 0xFC00, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFC10, 0xFC00, 0xFC01, 0xFD01, 0xFC00, 0xFC10, 0xFE10, 0xFC10, 0xFC00, 0xFC01, 0xFD01, 0xFC00, 0xFC10, 0xFE10, 0xFC10, 0xFE10, 0xFE11, 0xFE10, 0xFC10, 0xFC90, 0xFC80, 0xFC81, 0xFC01, 0xFC00, 0xFC20, 0xFE20, 0xFF20, 0xFD20, 0xFD00, 0xFC00, 0xFC01, 0xFC21, 0xFD21, 0xFD20, 0xFD00, 0xFC00, 0xFC20, 0x0000,
};

static const u8 sDemoplayFrames_OldLifeArea[144] = {
    0, 3, 26, 6, 29, 7, 24, 1, 14, 3, 15, 6, 4, 9, 1, 8, 4, 6, 2, 32, 6, 10, 18, 6, 4, 14, 3, 14, 6, 1, 2, 11, 4, 4, 6, 39, 4, 5, 12, 5, 7, 13, 2, 3, 14, 7, 1, 2, 13, 5, 7, 2, 45, 82, 18, 26, 56, 11, 4, 17, 28, 15, 4, 1, 1, 20, 2, 7, 21, 1, 94, 1, 13, 12, 1, 29, 10, 3, 53, 16, 22, 15, 27, 7, 23, 8, 14, 5, 8, 9, 1, 9, 24, 36, 15, 10, 21, 11, 18, 8, 5, 36, 28, 23, 5, 11, 2, 40, 1, 13, 17, 7, 21, 3, 1, 1, 14, 27, 2, 23, 7, 10, 22, 8, 16, 2, 3, 9, 3, 20, 28, 12, 4, 2, 4, 24, 19, 6, 2, 1, 10, 33, 14, 0,
};

// Demoplay Key inputs
static const KEY_INPUT* const sDemoplayKeyInputs[4] = {
    sDemoplayKeyInputs_Volcano,
    sDemoplayKeyInputs_Ocean,
    sDemoplayKeyInputs_RepairFactory,
    sDemoplayKeyInputs_OldLifeArea,
};

// Demoplay Key inputs
static const u8* const sDemoplayKeyFrames[4] = {
    sDemoplayFrames_Volcano,
    sDemoplayFrames_Ocean,
    sDemoplayFrames_RepairFactory,
    sDemoplayFrames_OldLifeArea,
};

static const u8 sDemoplayStageIDs[4] = {
    STAGE_VOLCANO,
    STAGE_OCEAN,
    STAGE_REPAIR_FACTORY,
    STAGE_OLD_RESIDENTIAL,
};

void SetIntroMode(struct Intro* intro, u32 mode) {
  *(u32*)(&intro->mode) = mode;
  *(u32*)(&intro->titleFrame) = 0;
}

NAKED static void IntroLoop_CapcomInti(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	ldr r0, _080EB90C @ =gJoypad\n\
	ldrh r0, [r0, #4]\n\
	cmp r0, #0\n\
	beq _080EB8FA\n\
	movs r0, #3\n\
	strh r0, [r5, #8]\n\
_080EB8FA:\n\
	ldrb r0, [r5, #5]\n\
	cmp r0, #6\n\
	bls _080EB902\n\
	b _080EBAE2\n\
_080EB902:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080EB910 @ =_080EB914\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080EB90C: .4byte gJoypad\n\
_080EB910: .4byte _080EB914\n\
_080EB914: @ jump table\n\
	.4byte _080EB930 @ case 0\n\
	.4byte _080EB984 @ case 1\n\
	.4byte _080EB9C6 @ case 2\n\
	.4byte _080EB9E6 @ case 3\n\
	.4byte _080EBA42 @ case 4\n\
	.4byte _080EBA80 @ case 5\n\
	.4byte _080EBA9E @ case 6\n\
_080EB930:\n\
	adds r0, r5, #0\n\
	bl initGameSavedata\n\
	ldr r2, _080EBAEC @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080EBAF0 @ =0x0000FFF8\n\
	ands r0, r1\n\
	movs r4, #0\n\
	ldr r1, _080EBAF4 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0xe4\n\
	lsls r3, r3, #6\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r6, _080EBAF8 @ =0x00000206\n\
	adds r0, r6, #0\n\
	strh r0, [r2, #0xa]\n\
	str r4, [r2, #0x18]\n\
	ldr r0, _080EBAFC @ =gPaletteManager\n\
	strh r4, [r0]\n\
	ldr r0, _080EBB00 @ =0x08547280\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, _080EBB04 @ =0x0854728C\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _080EBB08 @ =gBgMapOffsets\n\
	str r4, [sp]\n\
	movs r0, #0x38\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	strh r4, [r5, #8]\n\
	strh r4, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EB984:\n\
	ldrh r1, [r5, #0xa]\n\
	adds r1, #1\n\
	ldrh r0, [r5, #8]\n\
	adds r1, r1, r0\n\
	strh r1, [r5, #0xa]\n\
	ldr r3, _080EBAFC @ =gPaletteManager\n\
	movs r0, #0x40\n\
	subs r0, r0, r1\n\
	ldr r2, _080EBB0C @ =0x00000402\n\
	adds r4, r3, r2\n\
	strb r0, [r4]\n\
	movs r2, #0xff\n\
	ands r0, r2\n\
	ldr r6, _080EBB10 @ =0x00000401\n\
	adds r2, r3, r6\n\
	strb r0, [r2]\n\
	subs r6, #1\n\
	adds r3, r3, r6\n\
	strb r0, [r3]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, #0x1f\n\
	bgt _080EB9B4\n\
	b _080EBAE2\n\
_080EB9B4:\n\
	movs r0, #0x20\n\
	strb r0, [r4]\n\
	strb r0, [r2]\n\
	strb r0, [r3]\n\
	movs r0, #0x78\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EB9C6:\n\
	ldrh r0, [r5, #0xa]\n\
	subs r0, #1\n\
	strh r0, [r5, #0xa]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080EB9DC\n\
	movs r1, #8\n\
	ldrsh r0, [r5, r1]\n\
	cmp r0, #0\n\
	bne _080EB9DC\n\
	b _080EBAE2\n\
_080EB9DC:\n\
	movs r0, #0x20\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EB9E6:\n\
	ldrh r2, [r5, #0xa]\n\
	subs r2, #1\n\
	ldrh r0, [r5, #8]\n\
	subs r2, r2, r0\n\
	movs r4, #0\n\
	adds r1, r2, #0\n\
	strh r2, [r5, #0xa]\n\
	ldr r3, _080EBAFC @ =gPaletteManager\n\
	ldr r6, _080EBB0C @ =0x00000402\n\
	adds r0, r3, r6\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	subs r6, #1\n\
	adds r1, r3, r6\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r3, r3, r1\n\
	strb r0, [r3]\n\
	lsls r2, r2, #0x10\n\
	cmp r2, #0\n\
	bgt _080EBAE2\n\
	ldr r0, _080EBB14 @ =0x08547294\n\
	ldr r1, _080EBB18 @ =0x0200214A\n\
	ldrh r2, [r1]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080EBB1C @ =0x085472A0\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _080EBB08 @ =gBgMapOffsets\n\
	str r4, [sp]\n\
	movs r0, #0x38\n\
	movs r2, #1\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	strh r4, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EBA42:\n\
	ldrh r0, [r5, #0xa]\n\
	adds r0, #1\n\
	ldrh r2, [r5, #8]\n\
	adds r0, r0, r2\n\
	adds r3, r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldr r2, _080EBAFC @ =gPaletteManager\n\
	ldr r6, _080EBB0C @ =0x00000402\n\
	adds r4, r2, r6\n\
	strb r3, [r4]\n\
	movs r1, #0xff\n\
	ands r1, r3\n\
	subs r6, #1\n\
	adds r3, r2, r6\n\
	strb r1, [r3]\n\
	subs r6, #1\n\
	adds r2, r2, r6\n\
	strb r1, [r2]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x1f\n\
	ble _080EBAE2\n\
	movs r0, #0x20\n\
	strb r0, [r4]\n\
	strb r0, [r3]\n\
	strb r0, [r2]\n\
	movs r0, #0x78\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EBA80:\n\
	ldrh r0, [r5, #0xa]\n\
	subs r0, #1\n\
	strh r0, [r5, #0xa]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080EBA94\n\
	movs r1, #8\n\
	ldrsh r0, [r5, r1]\n\
	cmp r0, #0\n\
	beq _080EBAE2\n\
_080EBA94:\n\
	movs r0, #0x20\n\
	strh r0, [r5, #0xa]\n\
	ldrb r0, [r5, #5]\n\
	adds r0, #1\n\
	strb r0, [r5, #5]\n\
_080EBA9E:\n\
	ldrh r1, [r5, #0xa]\n\
	subs r1, #1\n\
	ldrh r0, [r5, #8]\n\
	subs r1, r1, r0\n\
	adds r3, r1, #0\n\
	strh r1, [r5, #0xa]\n\
	ldr r2, _080EBAFC @ =gPaletteManager\n\
	ldr r6, _080EBB0C @ =0x00000402\n\
	adds r4, r2, r6\n\
	strb r3, [r4]\n\
	movs r0, #0xff\n\
	ands r0, r3\n\
	subs r6, #1\n\
	adds r3, r2, r6\n\
	strb r0, [r3]\n\
	subs r6, #1\n\
	adds r2, r2, r6\n\
	strb r0, [r2]\n\
	lsls r1, r1, #0x10\n\
	cmp r1, #0\n\
	bgt _080EBAE2\n\
	movs r0, #0x20\n\
	strb r0, [r4]\n\
	strb r0, [r3]\n\
	strb r0, [r2]\n\
	ldr r2, _080EBAEC @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080EBB20 @ =0x0000C7FF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	adds r0, r5, #0\n\
	movs r1, #4\n\
	bl SetIntroMode\n\
_080EBAE2:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EBAEC: .4byte gVideoRegBuffer\n\
_080EBAF0: .4byte 0x0000FFF8\n\
_080EBAF4: .4byte 0x0000F0FF\n\
_080EBAF8: .4byte 0x00000206\n\
_080EBAFC: .4byte gPaletteManager\n\
_080EBB00: .4byte gGraphic_Capcom\n\
_080EBB04: .4byte gPalette_Capcom\n\
_080EBB08: .4byte gBgMapOffsets\n\
_080EBB0C: .4byte 0x00000402\n\
_080EBB10: .4byte 0x00000401\n\
_080EBB14: .4byte gGraphic_Inti\n\
_080EBB18: .4byte gVideoRegBuffer+10\n\
_080EBB1C: .4byte gPalette_Inti\n\
_080EBB20: .4byte 0x0000C7FF\n\
 .syntax divided\n");
}

// ソフトリセット時、セーブデータ選択画面でBボタンを押した時
static void IntroLoop_ComeBackTitle(struct Intro* p) {
  initGameSavedata(p);
  SetIntroMode(p, 4);
}

static void initGameSavedata(struct Intro* p) {
  s16 saveIdx;

  LoadSystemData();
  p->saveOK = FALSE;
  saveIdx = 0;
  do {
    bool32 ok = CheckSavedataCorrect(saveIdx, SAVE_SLOT_SIZE);
    if (ok) {
      p->saveOK = 1;
    }
    saveIdx++;
  } while (saveIdx < 5);
}

// 02 xx nn nn
NAKED static void IntroLoop_sram_080ebb74(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r5, [r6, #5]\n\
	cmp r5, #0\n\
	beq _080EBB84\n\
	cmp r5, #1\n\
	beq _080EBBFA\n\
	b _080EBCA8\n\
_080EBB84:\n\
	ldr r4, _080EBC10 @ =gPaletteManager\n\
	ldr r1, _080EBC14 @ =0x00000402\n\
	adds r0, r4, r1\n\
	movs r1, #0x20\n\
	strb r1, [r0]\n\
	ldr r2, _080EBC18 @ =0x00000401\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	movs r1, #0x81\n\
	lsls r1, r1, #3\n\
	adds r0, r4, r1\n\
	str r5, [r0]\n\
	bl ClearBlinkings\n\
	ldr r0, _080EBC1C @ =gBlendRegBuffer\n\
	strh r5, [r0]\n\
	ldr r1, _080EBC20 @ =gWindowRegBuffer\n\
	strh r5, [r1]\n\
	movs r0, #0xff\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, _080EBC24 @ =wMOSAIC\n\
	strh r5, [r0]\n\
	strh r5, [r4]\n\
	bl text_080e9730\n\
	ldr r2, _080EBC28 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080EBC2C @ =0x0000FFF8\n\
	ands r0, r1\n\
	ldr r1, _080EBC30 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	bl SwitchProcess\n\
	ldr r4, _080EBC34 @ =gGameState\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	ldr r0, _080EBC38 @ =0x00006260\n\
	adds r4, r4, r0\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	ldr r1, _080EBC3C @ =Process_Game\n\
	bl ResetProcess\n\
	ldrb r0, [r6, #5]\n\
	adds r0, #1\n\
	strb r0, [r6, #5]\n\
_080EBBFA:\n\
	ldr r2, _080EBC40 @ =gJoypad\n\
	ldrh r0, [r2, #4]\n\
	movs r1, #0xb\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080EBC44\n\
	movs r0, #1\n\
	bl disableProcess\n\
	b _080EBC4A\n\
	.align 2, 0\n\
_080EBC10: .4byte gPaletteManager\n\
_080EBC14: .4byte 0x00000402\n\
_080EBC18: .4byte 0x00000401\n\
_080EBC1C: .4byte gBlendRegBuffer\n\
_080EBC20: .4byte gWindowRegBuffer\n\
_080EBC24: .4byte wMOSAIC\n\
_080EBC28: .4byte gVideoRegBuffer\n\
_080EBC2C: .4byte 0x0000FFF8\n\
_080EBC30: .4byte 0x0000F0FF\n\
_080EBC34: .4byte gGameState\n\
_080EBC38: .4byte 0x00006260\n\
_080EBC3C: .4byte Process_Game\n\
_080EBC40: .4byte gJoypad\n\
_080EBC44:\n\
	strh r1, [r2]\n\
	strh r1, [r2, #4]\n\
	strh r1, [r2, #6]\n\
_080EBC4A:\n\
	ldr r0, _080EBCB0 @ =gProcessManager\n\
	movs r1, #0x99\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080EBCA8\n\
	ldr r5, _080EBCB4 @ =gPaletteManager\n\
	ldr r2, _080EBCB8 @ =0x00000402\n\
	adds r0, r5, r2\n\
	movs r4, #0\n\
	movs r1, #0x20\n\
	strb r1, [r0]\n\
	ldr r3, _080EBCBC @ =0x00000401\n\
	adds r0, r5, r3\n\
	strb r1, [r0]\n\
	subs r2, #2\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	adds r3, #7\n\
	adds r0, r5, r3\n\
	str r4, [r0]\n\
	bl ClearBlinkings\n\
	ldr r0, _080EBCC0 @ =gBlendRegBuffer\n\
	strh r4, [r0]\n\
	ldr r1, _080EBCC4 @ =gWindowRegBuffer\n\
	strh r4, [r1]\n\
	movs r0, #0xff\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, _080EBCC8 @ =wMOSAIC\n\
	strh r4, [r0]\n\
	strh r4, [r5]\n\
	bl text_080e9730\n\
	bl StopAllMusics\n\
	ldrh r0, [r6, #0x12]\n\
	adds r0, #1\n\
	strh r0, [r6, #0x12]\n\
	ldr r0, _080EBCCC @ =gIntro\n\
	movs r1, #1\n\
	bl SetIntroMode\n\
	ldr r0, _080EBCD0 @ =Process_SoftReset\n\
	bl exec\n\
_080EBCA8:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EBCB0: .4byte gProcessManager\n\
_080EBCB4: .4byte gPaletteManager\n\
_080EBCB8: .4byte 0x00000402\n\
_080EBCBC: .4byte 0x00000401\n\
_080EBCC0: .4byte gBlendRegBuffer\n\
_080EBCC4: .4byte gWindowRegBuffer\n\
_080EBCC8: .4byte wMOSAIC\n\
_080EBCCC: .4byte gIntro\n\
_080EBCD0: .4byte Process_SoftReset\n\
	 .syntax divided\n");
}

// 03 xx nn nn
NAKED static void IntroLoop_sram_080ebcd4(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r6, [r7, #5]\n\
	cmp r6, #0\n\
	beq _080EBCE4\n\
	cmp r6, #1\n\
	beq _080EBD90\n\
	b _080EBE5A\n\
_080EBCE4:\n\
	ldr r4, _080EBDB0 @ =gPaletteManager\n\
	ldr r1, _080EBDB4 @ =0x00000402\n\
	adds r0, r4, r1\n\
	movs r1, #0x20\n\
	strb r1, [r0]\n\
	ldr r2, _080EBDB8 @ =0x00000401\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	movs r1, #0x81\n\
	lsls r1, r1, #3\n\
	adds r0, r4, r1\n\
	str r6, [r0]\n\
	bl ClearBlinkings\n\
	ldr r0, _080EBDBC @ =gBlendRegBuffer\n\
	movs r5, #0\n\
	strh r6, [r0]\n\
	ldr r1, _080EBDC0 @ =gWindowRegBuffer\n\
	strh r6, [r1]\n\
	movs r0, #0xff\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, _080EBDC4 @ =wMOSAIC\n\
	strh r6, [r0]\n\
	strh r6, [r4]\n\
	bl text_080e9730\n\
	ldr r2, _080EBDC8 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080EBDCC @ =0x0000FFF8\n\
	ands r0, r1\n\
	ldr r1, _080EBDD0 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	bl SwitchProcess\n\
	ldr r4, _080EBDD4 @ =gGameState\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl SetGameMode\n\
	ldr r2, _080EBDD8 @ =0x08385E0C\n\
	ldrh r0, [r7, #0x12]\n\
	lsrs r0, r0, #1\n\
	movs r1, #3\n\
	ands r0, r1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	ldr r1, _080EBDDC @ =0x00006260\n\
	adds r4, r4, r1\n\
	strh r0, [r4]\n\
	ldr r1, _080EBDE0 @ =Process_Game\n\
	movs r0, #1\n\
	bl ResetProcess\n\
	movs r2, #0x92\n\
	lsls r2, r2, #2\n\
	adds r1, r7, r2\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
	ldr r3, _080EBDE4 @ =0x0000024A\n\
	adds r0, r7, r3\n\
	strb r5, [r0]\n\
	ldr r1, _080EBDE8 @ =0x0000024B\n\
	adds r0, r7, r1\n\
	strb r5, [r0]\n\
	adds r2, #4\n\
	adds r0, r7, r2\n\
	strh r6, [r0]\n\
	ldr r0, _080EBDEC @ =gJoypad\n\
	ldrh r1, [r0]\n\
	adds r3, #4\n\
	adds r0, r7, r3\n\
	strh r1, [r0]\n\
	ldrb r0, [r7, #5]\n\
	adds r0, #1\n\
	strb r0, [r7, #5]\n\
_080EBD90:\n\
	ldr r0, _080EBDF0 @ =0x0000024E\n\
	adds r3, r7, r0\n\
	ldr r0, _080EBDEC @ =gJoypad\n\
	ldrh r1, [r3]\n\
	ldrh r2, [r0]\n\
	eors r1, r2\n\
	ands r1, r2\n\
	movs r0, #0xb\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080EBDF4\n\
	movs r0, #1\n\
	bl disableProcess\n\
	b _080EBDFC\n\
	.align 2, 0\n\
_080EBDB0: .4byte gPaletteManager\n\
_080EBDB4: .4byte 0x00000402\n\
_080EBDB8: .4byte 0x00000401\n\
_080EBDBC: .4byte gBlendRegBuffer\n\
_080EBDC0: .4byte gWindowRegBuffer\n\
_080EBDC4: .4byte wMOSAIC\n\
_080EBDC8: .4byte gVideoRegBuffer\n\
_080EBDCC: .4byte 0x0000FFF8\n\
_080EBDD0: .4byte 0x0000F0FF\n\
_080EBDD4: .4byte gGameState\n\
_080EBDD8: .4byte sDemoplayStageIDs\n\
_080EBDDC: .4byte 0x00006260\n\
_080EBDE0: .4byte Process_Game\n\
_080EBDE4: .4byte 0x0000024A\n\
_080EBDE8: .4byte 0x0000024B\n\
_080EBDEC: .4byte gJoypad\n\
_080EBDF0: .4byte 0x0000024E\n\
_080EBDF4:\n\
	strh r2, [r3]\n\
	adds r0, r7, #0\n\
	bl demoplay_080ebe84\n\
_080EBDFC:\n\
	ldr r0, _080EBE60 @ =gProcessManager\n\
	movs r1, #0x99\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080EBE5A\n\
	ldr r5, _080EBE64 @ =gPaletteManager\n\
	ldr r2, _080EBE68 @ =0x00000402\n\
	adds r0, r5, r2\n\
	movs r4, #0\n\
	movs r1, #0x20\n\
	strb r1, [r0]\n\
	ldr r3, _080EBE6C @ =0x00000401\n\
	adds r0, r5, r3\n\
	strb r1, [r0]\n\
	subs r2, #2\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	adds r3, #7\n\
	adds r0, r5, r3\n\
	str r4, [r0]\n\
	bl ClearBlinkings\n\
	ldr r0, _080EBE70 @ =gBlendRegBuffer\n\
	strh r4, [r0]\n\
	ldr r1, _080EBE74 @ =gWindowRegBuffer\n\
	strh r4, [r1]\n\
	movs r0, #0xff\n\
	strb r0, [r1, #0xe]\n\
	ldr r0, _080EBE78 @ =wMOSAIC\n\
	strh r4, [r0]\n\
	strh r4, [r5]\n\
	bl text_080e9730\n\
	bl StopAllMusics\n\
	ldrh r0, [r7, #0x12]\n\
	adds r0, #1\n\
	strh r0, [r7, #0x12]\n\
	ldr r0, _080EBE7C @ =gIntro\n\
	movs r1, #1\n\
	bl SetIntroMode\n\
	ldr r0, _080EBE80 @ =Process_SoftReset\n\
	bl exec\n\
_080EBE5A:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EBE60: .4byte gProcessManager\n\
_080EBE64: .4byte gPaletteManager\n\
_080EBE68: .4byte 0x00000402\n\
_080EBE6C: .4byte 0x00000401\n\
_080EBE70: .4byte gBlendRegBuffer\n\
_080EBE74: .4byte gWindowRegBuffer\n\
_080EBE78: .4byte wMOSAIC\n\
_080EBE7C: .4byte gIntro\n\
_080EBE80: .4byte Process_SoftReset\n\
 .syntax divided\n");
}

// タイトル画面で放置したときのデモプレイの入力処理
NAKED static void demoplay_080ebe84(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r3, r0, #0\n\
	movs r0, #0x93\n\
	lsls r0, r0, #2\n\
	adds r7, r3, r0\n\
	ldrh r5, [r7]\n\
	ldr r1, _080EBEF8 @ =0x0000024A\n\
	adds r6, r3, r1\n\
	ldr r2, _080EBEFC @ =0x0000024B\n\
	adds r2, r2, r3\n\
	mov ip, r2\n\
	ldrb r0, [r6]\n\
	ldrb r1, [r2]\n\
	cmp r0, r1\n\
	bne _080EBED8\n\
	ldr r2, _080EBF00 @ =0x08385DEC\n\
	ldrh r1, [r3, #0x12]\n\
	lsrs r1, r1, #1\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	adds r2, r1, r2\n\
	movs r0, #0x92\n\
	lsls r0, r0, #2\n\
	adds r3, r3, r0\n\
	ldrh r4, [r3]\n\
	ldr r2, [r2]\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r2\n\
	ldrh r5, [r0]\n\
	ldr r0, _080EBF04 @ =0x08385DFC\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	movs r1, #0\n\
	mov r2, ip\n\
	strb r0, [r2]\n\
	strb r1, [r6]\n\
	ldrh r0, [r3]\n\
	adds r0, #1\n\
	strh r0, [r3]\n\
_080EBED8:\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	movs r3, #0\n\
	strb r0, [r6]\n\
	ldr r1, _080EBF08 @ =gJoypad\n\
	strh r5, [r1]\n\
	ldrh r2, [r7]\n\
	adds r0, r5, #0\n\
	bics r0, r2\n\
	strh r0, [r1, #4]\n\
	strh r3, [r1, #6]\n\
	strh r5, [r7]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EBEF8: .4byte 0x0000024A\n\
_080EBEFC: .4byte 0x0000024B\n\
_080EBF00: .4byte sDemoplayKeyInputs\n\
_080EBF04: .4byte sDemoplayKeyFrames\n\
_080EBF08: .4byte gJoypad\n\
 .syntax divided\n");
}

// --------------------------------------------

static void InitTitleAnimation(struct Intro* p);
static void updateTitleAnimation(struct Intro* p);
static void InitTitleScreen(struct Intro* p);
static void SelectOnTitle(struct Intro* p);
static void HandleTitleAction(struct Intro* p);

// 04 xx nn nn
static void IntroLoop_TitleScreen(struct Intro* p) {
  // clang-format off
  static const IntroLoopFunc seq[5] = {
      InitTitleAnimation,
      updateTitleAnimation,
      InitTitleScreen,
      SelectOnTitle,
      HandleTitleAction,
  };
  // clang-format on
  (seq[p->mode[1]])(p);
}

// 04 00 xx nn
static void InitTitleAnimation(struct Intro* p) {
  UnmaskBg0();
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0x0;
  PALETTE16(0) = RGB_BLACK;
  text_080e9730();
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  p->unk_236 = 0;
  *(u8*)&p->unk_250 = 0;
  *(u32*)&p->unk_24c = 0;
  p->mode[2] = 0;
  p->mode[1] = 1;
}

WIP static void updateTitleAnimation(struct Intro* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      playBGM(BGM_TITLE);
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gBlendRegBuffer.bldclt = 0x248;
      gBlendRegBuffer.bldalpha = 0x1000;
      gIntro.rng = 0;
      FUN_080ed07c(p);
      intro_080ed1d4(p);
      FUN_080ed6c4(p);
      p->unk_234 = 0;
      p->unk_235 = 0;
      p->titleFrame = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      intro_080ed108(p);
      if (p->titleFrame < 285) {
        if (p->titleFrame == 284) {
          gVideoRegBuffer.dispcnt &= 0xC7FF;
        } else if (p->titleFrame < 184) {
          if (p->titleFrame > 83) {
            intro_080ed770(p, 1);
          }
        } else {
          intro_080ed770(p, 0);
        }
      }

      if (p->titleFrame < 300) {
        if (p->titleFrame >= 240) {
          intro_080ed480(p, 3);

        } else {
          if (p->titleFrame >= 200) {
            intro_080ed480(p, 2);

          } else {
            if (p->titleFrame >= 140) {
              intro_080ed480(p, 1);

            } else {
              if (p->titleFrame >= 100) {
                intro_080ed480(p, 0);
              }
            }
          }
        }
      }
      if (p->titleFrame > 318) {
        intro_080ed2a0(p);
      }
      if (p->titleFrame > 414) {
        gVideoRegBuffer.dispcnt |= 0x3800;
        intro_080ed770(p, 2);
      }
      break;
    }
  }

  if (p->unk_235 != 0) {
    p->unk_235--;
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x40 - p->unk_235;
  } else if (p->unk_234 < 0x40) {
    p->unk_234++;
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = (p->unk_234 >> 1);
  }
  p->titleFrame++;

  if (p->titleFrame > 429) {
    PlaySound(SE_UNK_14d);
  } else {
    if ((p->unk_236 == 0) && (!(gJoypad[0].pressed & (A_BUTTON | B_BUTTON | START_BUTTON)))) {
      return;
    }
    PlaySound(SE_UNK_14d);
    fadeoutBGM(BGM_TITLE);
  }
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x40;
  p->mode[2] = 0;
  p->mode[1] = 2;
#else
  INCCODE("asm/wip/updateTitleAnimation.inc");
#endif
}

NAKED static void InitTitleScreen(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	str r0, [sp, #0xc]\n\
	ldr r0, _080EC324 @ =gGameState+16\n\
	ldr r6, _080EC328 @ =gVideoRegBuffer+4\n\
	ldrh r2, [r6]\n\
	movs r4, #0xf8\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #3\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #2\n\
	bl MaskBg0\n\
	subs r5, r6, #4\n\
	ldrh r1, [r5]\n\
	ldr r0, _080EC32C @ =0x0000FFF8\n\
	ands r0, r1\n\
	movs r1, #0\n\
	mov r8, r1\n\
	ldr r1, _080EC330 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r2, #0x9e\n\
	lsls r2, r2, #7\n\
	adds r1, r2, #0\n\
	movs r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	bl FUN_080e981c\n\
	movs r0, #6\n\
	strh r0, [r6]\n\
	mov r0, r8\n\
	str r0, [r5, #0xc]\n\
	ldr r2, _080EC334 @ =0x00000206\n\
	adds r1, r2, #0\n\
	strh r1, [r5, #6]\n\
	str r0, [r5, #0x10]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	lsls r1, r0, #3\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #0x13\n\
	adds r1, r1, r2\n\
	mov r2, r8\n\
	str r2, [sp, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x11\n\
	mov sb, r2\n\
	orrs r2, r0\n\
	mov sb, r2\n\
	add r0, sp, #4\n\
	bl CpuFastSet\n\
	ldr r0, _080EC338 @ =gBgMapOffsets\n\
	mov sl, r0\n\
	movs r0, #0xe\n\
	str r0, [sp]\n\
	movs r0, #0x12\n\
	mov r1, sl\n\
	movs r2, #5\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldr r1, _080EC33C @ =0x00000486\n\
	adds r0, r1, #0\n\
	strh r0, [r5, #8]\n\
	mov r2, r8\n\
	str r2, [r5, #0x14]\n\
	ldr r0, _080EC340 @ =0x085472A8\n\
	movs r6, #0x80\n\
	lsls r6, r6, #7\n\
	adds r1, r6, #0\n\
	bl LoadGraphic\n\
	ldr r0, _080EC344 @ =0x085472B4\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	mov r0, r8\n\
	str r0, [sp]\n\
	movs r0, #0x24\n\
	mov r1, sl\n\
	movs r2, #2\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldr r1, _080EC348 @ =0x00000646\n\
	adds r0, r1, #0\n\
	strh r0, [r5, #0xa]\n\
	ands r4, r0\n\
	lsls r4, r4, #3\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #0x13\n\
	adds r4, r4, r2\n\
	mov r0, r8\n\
	str r0, [sp, #8]\n\
	add r0, sp, #8\n\
	adds r1, r4, #0\n\
	mov r2, sb\n\
	bl CpuFastSet\n\
	ldr r0, [sp, #0xc]\n\
	bl loadTitleScreen\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #1\n\
	movs r0, #0xf0\n\
	bl LoadBlink\n\
	ldr r2, _080EC34C @ =gWindowRegBuffer\n\
	ldrh r0, [r2]\n\
	orrs r6, r0\n\
	strh r6, [r2]\n\
	movs r0, #0xff\n\
	strb r0, [r2, #0xd]\n\
	ldrb r1, [r2, #0xe]\n\
	movs r0, #6\n\
	orrs r0, r1\n\
	movs r1, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r2, #0xe]\n\
	movs r0, #0x50\n\
	strh r0, [r2, #6]\n\
	movs r0, #0xa0\n\
	strh r0, [r2, #0xa]\n\
	ldr r1, _080EC350 @ =gBlendRegBuffer\n\
	ldr r0, _080EC354 @ =0x00003E43\n\
	strh r0, [r1]\n\
	ldr r0, _080EC358 @ =0x00000808\n\
	strh r0, [r1, #2]\n\
	ldr r1, [sp, #0xc]\n\
	movs r2, #0x8d\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	strb r7, [r0]\n\
	adds r2, #1\n\
	adds r0, r1, r2\n\
	strb r7, [r0]\n\
	adds r2, #1\n\
	adds r0, r1, r2\n\
	strb r7, [r0]\n\
	adds r2, #0x1a\n\
	adds r0, r1, r2\n\
	strb r7, [r0]\n\
	strb r7, [r1, #6]\n\
	movs r0, #3\n\
	strb r0, [r1, #5]\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EC324: .4byte gGameState+16\n\
_080EC328: .4byte gVideoRegBuffer+4\n\
_080EC32C: .4byte 0x0000FFF8\n\
_080EC330: .4byte 0x0000F0FF\n\
_080EC334: .4byte 0x00000206\n\
_080EC338: .4byte gBgMapOffsets\n\
_080EC33C: .4byte 0x00000486\n\
_080EC340: .4byte gGraphic_085472a8\n\
_080EC344: .4byte gPalette_085472a8\n\
_080EC348: .4byte 0x00000646\n\
_080EC34C: .4byte gWindowRegBuffer\n\
_080EC350: .4byte gBlendRegBuffer\n\
_080EC354: .4byte 0x00003E43\n\
_080EC358: .4byte 0x00000808\n\
 .syntax divided\n");
}

NAKED static void SelectOnTitle(struct Intro* p) { INCCODE("asm/todo/SelectOnTitle.inc"); }

static void HandleTitleAction(struct Intro* p) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gVideoRegBuffer.dispcnt &= 0xB0FF;
  BGCNT16(0) = 0x4008;
  gWindowRegBuffer.dispcnt &= 0xBFFF;
  gWindowRegBuffer.unk_0c[2] |= 0xE;
  gBlendRegBuffer.bldclt = 0;
  ClearBlink(0xf0);
  sio_0800100c();
  sio_08001778();
  switch (p->cursor) {
    case 0: {
      SetGameMode(&gGameState, GAMEMODE(MAINGAME, NEW_GAME, 0, 0));
      SetIntroMode(p, 5);
      return;
    }
    case 1: {
      SetGameMode(&gGameState, GAMEMODE(MAINGAME, CONTINUE_GAME, 0, 0));
      SetIntroMode(p, 5);
      return;
    }
    case 2: {
      SetIntroMode(p, 6);
      return;
    }
    case 3: {
      if ((p->unk_12 & 1) == 0) {
        SetIntroMode(p, 2);
      } else {
        SetIntroMode(p, 3);
      }
      return;
    }
  }
}

NAKED static u8 intro_080ecd28(struct Intro* p) { INCCODE("asm/todo/intro_080ecd28.inc"); }

static void loadTitleScreen(struct Intro* _ UNUSED) {
  if (gSystemSavedataManager.title < 3) {
    *(u32*)gVideoRegBuffer.bgofs[3] = gSystemSavedataManager.title * 80;
    LoadGraphic(BG_GRAPHIC(BG_TITLE_ZERO), (void*)CHAR_BASE(3));
    LoadPalette(BG_PALETTE(BG_TITLE_ZERO), 0);
    LoadBgMap(56, gBgMapOffsets, BG_TITLE_ZERO, 0, 0);
  } else {
    *(u32*)gVideoRegBuffer.bgofs[3] = (gSystemSavedataManager.title - 3) * 80;
    LoadGraphic(BG_GRAPHIC(BG_TITLE_CIEL), (void*)CHAR_BASE(3));
    LoadPalette(BG_PALETTE(BG_TITLE_CIEL), 0);
    LoadBgMap(56, gBgMapOffsets, BG_TITLE_CIEL, 0, 0);
  }
}

static void FUN_080ed07c(struct Intro* p) {
  gVideoRegBuffer.dispcnt |= 0x1200;
  *(u16*)&gVideoRegBuffer.bgcnt[1] = 0x1807;
  *(u32*)gVideoRegBuffer.bgofs[1] = 0;
  LoadGraphic(BG_GRAPHIC(BG_OP_ANIM1), (void*)CHAR_BASE(1));
  LoadPalette(BG_PALETTE(BG_OP_ANIM1), 0);
  LoadGraphic(BG_GRAPHIC(BG_OP_ANIM2), (void*)CHAR_BASE(1));
  LoadPalette(BG_PALETTE(BG_OP_ANIM2), 0);
  LoadBgMap(18, gBgMapOffsets, BG_OP_ANIM1, 0, 0);
  p->unk_23c = 0;
}

NAKED static void intro_080ed108(struct Intro* p) { INCCODE("asm/todo/intro_080ed108.inc"); }

static void intro_080ed1d4(struct Intro* p) {
  InitMotionLocation();
  LOAD_STATIC_GRAPHIC(SM149_MEGAMAN_LOGO);
  LOAD_STATIC_GRAPHIC(SM150_Z_LOGO);
  p->unk_240 = 0;
  p->unk_243 = 10;
}

NAKED static void intro_080ed2a0(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov sl, r0\n\
	movs r6, #0\n\
	ldr r0, _080ED2DC @ =gSineTable\n\
	mov sb, r0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	mov r8, r1\n\
	ldr r5, _080ED2E0 @ =0x08385FA4\n\
_080ED2BC:\n\
	movs r0, #0x90\n\
	lsls r0, r0, #2\n\
	add r0, sl\n\
	movs r3, #0\n\
	ldrsh r2, [r0, r3]\n\
	lsls r1, r6, #1\n\
	adds r1, r1, r6\n\
	lsls r1, r1, #2\n\
	subs r4, r2, r1\n\
	adds r0, r2, #0\n\
	cmp r0, #0x65\n\
	ble _080ED2EC\n\
	ldr r0, _080ED2E4 @ =0x00001010\n\
	ldr r1, _080ED2E8 @ =gBlendRegBuffer\n\
	strh r0, [r1, #2]\n\
	b _080ED31A\n\
	.align 2, 0\n\
_080ED2DC: .4byte gSineTable\n\
_080ED2E0: .4byte Coord_ARRAY_08385fa4\n\
_080ED2E4: .4byte 0x00001010\n\
_080ED2E8: .4byte gBlendRegBuffer\n\
_080ED2EC:\n\
	adds r0, r2, #0\n\
	movs r1, #6\n\
	bl __modsi3\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x1a\n\
	lsrs r1, r1, #0x17\n\
	add r1, sb\n\
	ldrh r1, [r1]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x14\n\
	movs r0, #0x1f\n\
	adds r2, r1, #0\n\
	ands r2, r0\n\
	movs r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r2, r0\n\
	ldr r3, _080ED384 @ =gBlendRegBuffer\n\
	strh r2, [r3, #2]\n\
_080ED31A:\n\
	cmp r4, #0xc\n\
	bne _080ED324\n\
	ldr r0, _080ED388 @ =0x0000014F\n\
	bl PlaySound\n\
_080ED324:\n\
	cmp r4, #0xc\n\
	ble _080ED32A\n\
	movs r4, #0xc\n\
_080ED32A:\n\
	cmp r6, #7\n\
	bgt _080ED408\n\
	cmp r4, #5\n\
	bhi _080ED394\n\
	ldr r7, _080ED38C @ =0xFFFF9500\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	orrs r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	ldr r2, _080ED390 @ =s32_ARRAY_08385fec\n\
	lsls r1, r6, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #7\n\
	subs r3, r3, r1\n\
	lsls r2, r4, #2\n\
	adds r2, r2, r4\n\
	lsls r2, r2, #0x19\n\
	lsrs r2, r2, #0x17\n\
	add r2, sb\n\
	movs r7, #0\n\
	ldrsh r2, [r2, r7]\n\
	mov r7, r8\n\
	subs r2, r7, r2\n\
	muls r2, r3, r2\n\
	asrs r2, r2, #8\n\
	adds r1, r1, r2\n\
	ldr r2, [r5, #4]\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #6\n\
	adds r2, r2, r3\n\
	movs r3, #6\n\
	subs r3, r3, r4\n\
	movs r4, #0x2a\n\
	muls r3, r4, r3\n\
	add r3, r8\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	movs r4, #1\n\
	str r4, [sp]\n\
	bl FUN_080ed57c\n\
	b _080ED45A\n\
	.align 2, 0\n\
_080ED384: .4byte gBlendRegBuffer\n\
_080ED388: .4byte 0x0000014F\n\
_080ED38C: .4byte 0xFFFF9500\n\
_080ED390: .4byte s32_ARRAY_08385fec\n\
_080ED394:\n\
	cmp r4, #0xb\n\
	bhi _080ED3E0\n\
	ldr r7, _080ED3D8 @ =0xFFFF9500\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	orrs r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	subs r2, r4, #6\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #0x19\n\
	lsrs r1, r1, #0x17\n\
	add r1, sb\n\
	movs r2, #0\n\
	ldrsh r4, [r1, r2]\n\
	ldr r1, [r5]\n\
	muls r1, r4, r1\n\
	asrs r1, r1, #8\n\
	ldr r3, _080ED3DC @ =s32_ARRAY_08385fec\n\
	lsls r2, r6, #2\n\
	adds r2, r2, r3\n\
	mov r3, r8\n\
	subs r4, r3, r4\n\
	ldr r2, [r2]\n\
	muls r2, r4, r2\n\
	asrs r2, r2, #8\n\
	adds r1, r1, r2\n\
	lsls r3, r4, #1\n\
	adds r3, r3, r4\n\
	lsls r3, r3, #4\n\
	ldr r2, [r5, #4]\n\
	adds r2, r2, r3\n\
	b _080ED3F4\n\
	.align 2, 0\n\
_080ED3D8: .4byte 0xFFFF9500\n\
_080ED3DC: .4byte s32_ARRAY_08385fec\n\
_080ED3E0:\n\
	cmp r4, #0\n\
	blt _080ED45A\n\
	ldr r7, _080ED404 @ =0xFFFF9500\n\
	adds r1, r7, #0\n\
	adds r0, r6, #0\n\
	orrs r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	ldr r1, [r5]\n\
	ldr r2, [r5, #4]\n\
_080ED3F4:\n\
	movs r3, #0\n\
	str r3, [sp]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	bl FUN_080ed57c\n\
	b _080ED45A\n\
	.align 2, 0\n\
_080ED404: .4byte 0xFFFF9500\n\
_080ED408:\n\
	cmp r4, #0xb\n\
	bhi _080ED442\n\
	movs r7, #0x96\n\
	lsls r7, r7, #8\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, sb\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	subs r1, r3, r1\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #3\n\
	ldr r1, [r5]\n\
	adds r1, r1, r0\n\
	ldr r2, [r5, #4]\n\
	movs r0, #0\n\
	cmp r4, #5\n\
	bgt _080ED438\n\
	movs r0, #1\n\
_080ED438:\n\
	str r0, [sp]\n\
	adds r0, r7, #0\n\
	bl FUN_080ed57c\n\
	b _080ED45A\n\
_080ED442:\n\
	cmp r4, #0\n\
	blt _080ED45A\n\
	ldr r1, [r5]\n\
	ldr r2, [r5, #4]\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	movs r0, #0x96\n\
	lsls r0, r0, #8\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	bl FUN_080ed57c\n\
_080ED45A:\n\
	adds r5, #8\n\
	adds r6, #1\n\
	cmp r6, #8\n\
	bgt _080ED464\n\
	b _080ED2BC\n\
_080ED464:\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	add r1, sl\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void intro_080ed480(struct Intro* p, u8 step) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r4, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r2, r1, #0x18\n\
	ldr r0, _080ED55C @ =0x00000243\n\
	adds r3, r4, r0\n\
	ldrb r0, [r3]\n\
	cmp r0, r2\n\
	beq _080ED4A6\n\
	movs r1, #0\n\
	strb r2, [r3]\n\
	ldr r3, _080ED560 @ =0x00000242\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
_080ED4A6:\n\
	movs r0, #0\n\
	mov sb, r0\n\
	lsls r2, r2, #3\n\
	mov sl, r2\n\
	ldr r1, _080ED564 @ =gIntro\n\
	mov r8, r1\n\
	ldr r0, _080ED568 @ =0x0838604C\n\
	adds r0, #4\n\
	add r0, sl\n\
	str r0, [sp, #4]\n\
	ldr r7, _080ED56C @ =0x0838600C\n\
_080ED4BC:\n\
	ldr r3, _080ED570 @ =0xFFFF9500\n\
	adds r0, r3, #0\n\
	mov r5, sb\n\
	orrs r5, r0\n\
	lsls r5, r5, #0x10\n\
	lsrs r5, r5, #0x10\n\
	ldr r0, _080ED568 @ =0x0838604C\n\
	add r0, sl\n\
	ldr r2, [r7]\n\
	ldr r0, [r0]\n\
	adds r2, r2, r0\n\
	mov r1, r8\n\
	ldr r0, [r1, #0xc]\n\
	ldr r3, _080ED574 @ =0x41C64E6D\n\
	adds r4, r0, #0\n\
	muls r4, r3, r4\n\
	ldr r0, _080ED578 @ =0x00003039\n\
	adds r4, r4, r0\n\
	str r4, [r1, #0xc]\n\
	lsrs r0, r4, #0x10\n\
	movs r1, #3\n\
	str r2, [sp, #8]\n\
	bl __umodsi3\n\
	subs r0, #1\n\
	lsls r0, r0, #8\n\
	ldr r2, [sp, #8]\n\
	adds r2, r2, r0\n\
	ldr r6, [r7, #4]\n\
	ldr r1, [sp, #4]\n\
	ldr r0, [r1]\n\
	adds r6, r6, r0\n\
	ldr r3, _080ED574 @ =0x41C64E6D\n\
	muls r4, r3, r4\n\
	ldr r0, _080ED578 @ =0x00003039\n\
	adds r4, r4, r0\n\
	mov r1, r8\n\
	str r4, [r1, #0xc]\n\
	lsrs r0, r4, #0x10\n\
	movs r1, #3\n\
	str r2, [sp, #8]\n\
	bl __umodsi3\n\
	subs r0, #1\n\
	lsls r0, r0, #8\n\
	adds r6, r6, r0\n\
	ldr r0, _080ED574 @ =0x41C64E6D\n\
	adds r3, r4, #0\n\
	muls r3, r0, r3\n\
	ldr r1, _080ED578 @ =0x00003039\n\
	adds r3, r3, r1\n\
	mov r0, r8\n\
	str r3, [r0, #0xc]\n\
	lsrs r3, r3, #0x10\n\
	movs r0, #0x3f\n\
	ands r3, r0\n\
	adds r3, #0xd0\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	adds r0, r5, #0\n\
	ldr r2, [sp, #8]\n\
	adds r1, r2, #0\n\
	adds r2, r6, #0\n\
	bl FUN_080ed57c\n\
	adds r7, #8\n\
	movs r1, #1\n\
	add sb, r1\n\
	mov r3, sb\n\
	cmp r3, #6\n\
	ble _080ED4BC\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080ED55C: .4byte 0x00000243\n\
_080ED560: .4byte 0x00000242\n\
_080ED564: .4byte gIntro\n\
_080ED568: .4byte s32_ARRAY_ARRAY_0838604c\n\
_080ED56C: .4byte s32_ARRAY_ARRAY_0838600c\n\
_080ED570: .4byte 0xFFFF9500\n\
_080ED574: .4byte 0x41C64E6D\n\
_080ED578: .4byte 0x00003039\n\
 .syntax divided\n");
}

NAKED static void FUN_080ed57c(motion_t m, s32 x, s32 y, u16 r3, u8 r4) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0x40\n\
	ldr r4, [sp, #0x5c]\n\
	lsls r5, r0, #0x10\n\
	lsrs r7, r5, #0x10\n\
	lsls r3, r3, #0x10\n\
	lsrs r6, r3, #0x10\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	mov sb, r4\n\
	add r3, sp, #0x20\n\
	movs r0, #0\n\
	str r0, [r3, #8]\n\
	str r0, [r3, #0xc]\n\
	str r1, [sp, #0x38]\n\
	add r4, sp, #0x38\n\
	str r2, [r4, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	mov r8, r3\n\
	cmp r6, r0\n\
	bne _080ED5C8\n\
	lsrs r0, r5, #0x18\n\
	lsls r0, r0, #2\n\
	ldr r1, _080ED5C4 @ =gStaticMotionMetaspriteTable\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	adds r2, r4, #0\n\
	bl InitNonAffineSprite\n\
	b _080ED5F6\n\
	.align 2, 0\n\
_080ED5C4: .4byte gStaticMotionMetaspriteTable\n\
_080ED5C8:\n\
	cmp r6, r0\n\
	bls _080ED5E4\n\
	lsrs r0, r5, #0x18\n\
	lsls r0, r0, #2\n\
	ldr r1, _080ED5E0 @ =gStaticMotionMetaspriteTable\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	adds r2, r4, #0\n\
	bl InitScalerotSprite1\n\
	b _080ED5F6\n\
	.align 2, 0\n\
_080ED5E0: .4byte gStaticMotionMetaspriteTable\n\
_080ED5E4:\n\
	lsrs r0, r5, #0x18\n\
	lsls r0, r0, #2\n\
	ldr r1, _080ED688 @ =gStaticMotionMetaspriteTable\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	adds r2, r4, #0\n\
	bl InitScalerotSprite2\n\
_080ED5F6:\n\
	mov r4, sp\n\
	ldr r0, _080ED68C @ =wStaticGraphicTilenums\n\
	lsrs r2, r7, #8\n\
	lsls r2, r2, #1\n\
	adds r0, r2, r0\n\
	ldrh r0, [r0]\n\
	ldr r1, _080ED690 @ =0x000003FF\n\
	ands r1, r0\n\
	ldrh r3, [r4, #0x14]\n\
	ldr r0, _080ED694 @ =0xFFFFFC00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r4, #0x14]\n\
	mov r3, sp\n\
	ldr r0, _080ED698 @ =wStaticMotionPalIDs\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3, #0x15]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #0x15]\n\
	mov r0, sp\n\
	strb r7, [r0, #0x1a]\n\
	ldrb r2, [r3, #0x15]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	strb r0, [r3, #0x15]\n\
	movs r2, #3\n\
	mov r0, sb\n\
	ands r0, r2\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r3, #0x11]\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r3, #0x11]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	cmp r6, r4\n\
	beq _080ED6AE\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	cmp r6, r0\n\
	bls _080ED656\n\
	adds r6, r0, #0\n\
_080ED656:\n\
	mov r0, sp\n\
	strh r6, [r0, #0x1c]\n\
	strh r6, [r0, #0x1e]\n\
	mov r3, sp\n\
	movs r1, #0x1f\n\
	ands r1, r7\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r3, #0x13]\n\
	movs r0, #0x3f\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #0x13]\n\
	cmp r6, r4\n\
	bls _080ED69C\n\
	mov r0, sp\n\
	movs r1, #0\n\
	bl ScalerotSprite\n\
	mov r0, sp\n\
	mov r1, r8\n\
	bl TaskCB_SetMetaspriteTileNum1\n\
	b _080ED6B6\n\
	.align 2, 0\n\
_080ED688: .4byte gStaticMotionMetaspriteTable\n\
_080ED68C: .4byte wStaticGraphicTilenums\n\
_080ED690: .4byte 0x000003FF\n\
_080ED694: .4byte 0xFFFFFC00\n\
_080ED698: .4byte wStaticMotionPalIDs\n\
_080ED69C:\n\
	mov r0, sp\n\
	movs r1, #0\n\
	bl ScalerotSprite\n\
	mov r0, sp\n\
	mov r1, r8\n\
	bl TaskCB_SetMetaspriteTileNum2\n\
	b _080ED6B6\n\
_080ED6AE:\n\
	mov r0, sp\n\
	mov r1, r8\n\
	bl TaskCB_DrawNoAffineSprite\n\
_080ED6B6:\n\
	add sp, #0x40\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
   .syntax divided\n");
}

NAKED static void FUN_080ed6c4(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #0xc\n\
	adds r6, r0, #0\n\
	ldr r4, _080ED750 @ =gVideoRegBuffer\n\
	ldrh r1, [r4]\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #6\n\
	adds r0, r2, #0\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r3, _080ED754 @ =0x00005A42\n\
	adds r0, r3, #0\n\
	strh r0, [r4, #0xa]\n\
	str r5, [r4, #0x18]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	adds r1, r1, r0\n\
	str r5, [sp, #4]\n\
	ldr r2, _080ED758 @ =0x01000400\n\
	add r0, sp, #4\n\
	bl CpuFastSet\n\
	ldr r0, _080ED75C @ =0x085472BC\n\
	ldrh r2, [r4, #0xa]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080ED760 @ =0x085472C8\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _080ED764 @ =gBgMapOffsets\n\
	str r5, [sp]\n\
	movs r0, #0x38\n\
	movs r2, #3\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldr r2, _080ED768 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #7\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0xff\n\
	strb r0, [r2, #0xd]\n\
	ldrb r1, [r2, #0xe]\n\
	movs r0, #6\n\
	orrs r0, r1\n\
	movs r1, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r2, #0xe]\n\
	movs r0, #0xa0\n\
	strh r0, [r2, #0xa]\n\
	ldr r0, _080ED76C @ =0x00000246\n\
	adds r6, r6, r0\n\
	movs r0, #0xa\n\
	strb r0, [r6]\n\
	add sp, #0xc\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080ED750: .4byte gVideoRegBuffer\n\
_080ED754: .4byte 0x00005A42\n\
_080ED758: .4byte 0x01000400\n\
_080ED75C: .4byte gGraphic_Capcom+3*20\n\
_080ED760: .4byte gPalette_Capcom+3*20\n\
_080ED764: .4byte gBgMapOffsets\n\
_080ED768: .4byte gWindowRegBuffer\n\
_080ED76C: .4byte 0x00000246\n\
 .syntax divided\n");
}

NAKED static void intro_080ed770(struct Intro* p, u8 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	mov r8, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r6, r1, #0x18\n\
	movs r5, #0\n\
	ldr r1, _080ED7C4 @ =0x00000246\n\
	add r1, r8\n\
	ldrb r0, [r1]\n\
	cmp r0, r6\n\
	beq _080ED794\n\
	strb r6, [r1]\n\
	movs r0, #0x91\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	strh r5, [r0]\n\
_080ED794:\n\
	cmp r6, #1\n\
	bhi _080ED844\n\
	movs r0, #0x91\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	ldrh r7, [r0]\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	cmp r4, #0x1f\n\
	bgt _080ED7CC\n\
	ldr r0, _080ED7C8 @ =gSineTable\n\
	lsls r1, r7, #0x19\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r0\n\
	movs r3, #0\n\
	ldrsh r2, [r1, r3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	asrs r0, r0, #3\n\
	adds r5, r0, #0\n\
	subs r5, #0x50\n\
	ldrh r0, [r1]\n\
	b _080ED81E\n\
	.align 2, 0\n\
_080ED7C4: .4byte 0x00000246\n\
_080ED7C8: .4byte gSineTable\n\
_080ED7CC:\n\
	cmp r4, #0x2f\n\
	bgt _080ED7D6\n\
	movs r5, #0x10\n\
	movs r4, #0x10\n\
	b _080ED826\n\
_080ED7D6:\n\
	cmp r4, #0x67\n\
	bgt _080ED824\n\
	ldr r1, _080ED80C @ =gSineTable\n\
	mov sb, r1\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	subs r0, #0x30\n\
	lsls r0, r0, #3\n\
	movs r1, #7\n\
	bl __divsi3\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, sb\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	asrs r0, r0, #4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	subs r5, r1, r0\n\
	cmp r4, #0x47\n\
	bgt _080ED810\n\
	movs r4, #0x10\n\
	b _080ED826\n\
	.align 2, 0\n\
_080ED80C: .4byte gSineTable\n\
_080ED810:\n\
	lsls r0, r7, #0x19\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r0, r0, #0x17\n\
	add r0, sb\n\
	ldrh r0, [r0]\n\
_080ED81E:\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x14\n\
	b _080ED826\n\
_080ED824:\n\
	movs r4, #0\n\
_080ED826:\n\
	ldr r3, _080ED840 @ =gBlendRegBuffer\n\
	movs r0, #0x1f\n\
	adds r2, r4, #0\n\
	ands r2, r0\n\
	lsls r1, r4, #1\n\
	adds r1, r1, r4\n\
	asrs r1, r1, #2\n\
	movs r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r2, r0\n\
	strh r2, [r3, #2]\n\
	b _080ED86E\n\
	.align 2, 0\n\
_080ED840: .4byte gBlendRegBuffer\n\
_080ED844:\n\
	movs r1, #0x91\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #0xb\n\
	bgt _080ED86E\n\
	ldr r2, _080ED8D0 @ =gSineTable\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #4\n\
	adds r5, r0, #0\n\
	subs r5, #0x50\n\
_080ED86E:\n\
	cmp r6, #1\n\
	bne _080ED876\n\
	movs r0, #0xa0\n\
	subs r5, r0, r5\n\
_080ED876:\n\
	ldr r2, _080ED8D4 @ =gVideoRegBuffer+24\n\
	movs r1, #2\n\
	subs r1, r1, r6\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #4\n\
	subs r0, r0, r5\n\
	strh r0, [r2]\n\
	adds r2, r5, #0\n\
	adds r2, #0x50\n\
	cmp r5, #0\n\
	bge _080ED890\n\
	movs r5, #0\n\
_080ED890:\n\
	cmp r5, #0xf0\n\
	ble _080ED896\n\
	movs r5, #0xf0\n\
_080ED896:\n\
	cmp r2, #0\n\
	bge _080ED89C\n\
	movs r2, #0\n\
_080ED89C:\n\
	cmp r2, #0xf0\n\
	ble _080ED8A2\n\
	movs r2, #0xf0\n\
_080ED8A2:\n\
	ldr r1, _080ED8D8 @ =gWindowRegBuffer\n\
	movs r0, #0xff\n\
	ands r2, r0\n\
	lsls r0, r5, #8\n\
	orrs r2, r0\n\
	strh r2, [r1, #6]\n\
	movs r1, #0x91\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	ldrh r2, [r1]\n\
	movs r3, #0\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0x5f\n\
	bgt _080ED8C2\n\
	adds r0, r2, #1\n\
	strh r0, [r1]\n\
_080ED8C2:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080ED8D0: .4byte gSineTable\n\
_080ED8D4: .4byte gVideoRegBuffer+24\n\
_080ED8D8: .4byte gWindowRegBuffer\n\
   .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void IntroLoop_080ed8dc(struct Intro* p) {
  switch (p->mode[1]) {
    case 0: {
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
      gPaletteManager.unk_408 = NULL;
      ClearBlinkings();
      gBlendRegBuffer.bldclt = 0;
      gWindowRegBuffer.dispcnt = 0;
      gWindowRegBuffer.unk_0c[2] = 0xFF;
      wMOSAIC = 0;
      PALETTE16(0) = RGB_BLACK;
      text_080e9730();
      gVideoRegBuffer.dispcnt &= BG_MODE_0;
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      SwitchProcess(TRUE);
      ResetProcess(1, Process_Game);
      p->mode[1]++;
      FALLTHROUGH;
    }
    case 1: {
      if (gProcessManager.processes[1].status == PROCESS_DISABLED) {
        SetIntroMode(&gIntro, 1);
        exec(Process_SoftReset);
      }
      break;
    }
  }
}

// --------------------------------------------

static void IntroLoop_Minigame(struct Intro* p) {
  (sIntroMinigameScripts[p->mode[1]])(p);
  return;
}

// --------------------------------------------

static void FUN_080ed9c0(struct Intro* p) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0;
  PALETTE16(0) = RGB_BLACK;
  text_080e9730();
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  *((u8*)&p->unk_240) = 0;
  p->mode[2] = 0;
  p->mode[1] = 1;
}

NAKED static void minigameSelectScript(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	movs r0, #0\n\
	mov sb, r0\n\
	mov r8, r0\n\
	ldrb r0, [r5, #6]\n\
	cmp r0, #1\n\
	beq _080EDB72\n\
	cmp r0, #1\n\
	bgt _080EDA80\n\
	cmp r0, #0\n\
	beq _080EDA8E\n\
	b _080EDCC4\n\
_080EDA80:\n\
	cmp r0, #2\n\
	bne _080EDA86\n\
	b _080EDC54\n\
_080EDA86:\n\
	cmp r0, #3\n\
	bne _080EDA8C\n\
	b _080EDC98\n\
_080EDA8C:\n\
	b _080EDCC4\n\
_080EDA8E:\n\
	ldr r2, _080EDBEC @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080EDBF0 @ =0x0000FFF8\n\
	ands r0, r1\n\
	ldr r1, _080EDBF4 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r3, #0xe4\n\
	lsls r3, r3, #6\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _080EDBF8 @ =0x00000606\n\
	adds r0, r1, #0\n\
	strh r0, [r2, #0xa]\n\
	mov r3, r8\n\
	str r3, [r2, #0x18]\n\
	ldr r0, _080EDBFC @ =gGraphic_Capcom+(22*20)\n\
	ldrh r2, [r2, #8]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080EDC00 @ =gGraphic_Capcom+(22*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _080EDC04 @ =gBgMapOffsets\n\
	mov r0, r8\n\
	str r0, [sp]\n\
	movs r0, #0x38\n\
	movs r2, #6\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	movs r0, #0x40\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldr r1, _080EDC08 @ =gBlendRegBuffer\n\
	ldr r0, _080EDC0C @ =0x00003E41\n\
	strh r0, [r1]\n\
	movs r2, #0x10\n\
	mov sl, r2\n\
	mov r3, sl\n\
	strh r3, [r1, #2]\n\
	bl text_080e9730\n\
	bl FUN_080e9840\n\
	movs r1, #0\n\
	ldr r6, _080EDC10 @ =gSystemSavedataManager\n\
	ldrb r0, [r6, #0x1a]\n\
	ldr r7, _080EDC14 @ =gSineTable\n\
	movs r4, #0xff\n\
	ldrb r2, [r7, #0x14]\n\
	cmp r0, r2\n\
	bne _080EDB04\n\
	movs r1, #1\n\
_080EDB04:\n\
	adds r3, r1, #0\n\
	ldrb r2, [r6, #0x1b]\n\
	ldrh r1, [r7, #0x16]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080EDB14\n\
	adds r3, #1\n\
_080EDB14:\n\
	ldrb r2, [r6, #0x1c]\n\
	ldrh r1, [r7, #0x18]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080EDB22\n\
	adds r3, #1\n\
_080EDB22:\n\
	ldrb r2, [r6, #0x1d]\n\
	ldrh r1, [r7, #0x1a]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080EDB30\n\
	adds r3, #1\n\
_080EDB30:\n\
	ldrb r2, [r6, #0x1e]\n\
	ldrh r1, [r7, #0x1c]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080EDB3E\n\
	adds r3, #1\n\
_080EDB3E:\n\
	ldrb r2, [r6, #0x1f]\n\
	ldrh r1, [r7, #0x1e]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080EDB4C\n\
	adds r3, #1\n\
_080EDB4C:\n\
	adds r2, r3, #0\n\
	adds r0, r6, #0\n\
	adds r0, #0x20\n\
	ldrb r1, [r0]\n\
	ldrh r0, [r7, #0x20]\n\
	ands r4, r0\n\
	cmp r1, r4\n\
	bne _080EDB5E\n\
	adds r2, #1\n\
_080EDB5E:\n\
	ldr r3, _080EDC18 @ =0x00000241\n\
	adds r0, r5, r3\n\
	strb r2, [r0]\n\
	mov r0, sl\n\
	strh r0, [r5, #8]\n\
	mov r1, r8\n\
	strh r1, [r5, #0xa]\n\
	ldrb r0, [r5, #6]\n\
	adds r0, #1\n\
	strb r0, [r5, #6]\n\
_080EDB72:\n\
	movs r2, #0x90\n\
	lsls r2, r2, #2\n\
	adds r6, r5, r2\n\
	ldrb r2, [r6]\n\
	adds r4, r2, #0\n\
	ldr r7, _080EDC1C @ =gJoypad\n\
	ldrh r1, [r7, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDB8C\n\
	adds r0, r2, #1\n\
	strb r0, [r6]\n\
_080EDB8C:\n\
	ldrh r1, [r7, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDBA4\n\
	ldrb r0, [r6]\n\
	ldr r3, _080EDC18 @ =0x00000241\n\
	adds r1, r5, r3\n\
	adds r0, #0xff\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	strb r0, [r6]\n\
_080EDBA4:\n\
	ldr r0, _080EDC18 @ =0x00000241\n\
	adds r1, r5, r0\n\
	ldrb r0, [r6]\n\
	ldrb r1, [r1]\n\
	bl __umodsi3\n\
	strb r0, [r6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r4, r0\n\
	beq _080EDBC0\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080EDBC0:\n\
	ldrh r2, [r5, #8]\n\
	movs r1, #8\n\
	ldrsh r0, [r5, r1]\n\
	cmp r0, #0xf\n\
	bgt _080EDBDE\n\
	adds r2, #1\n\
	strh r2, [r5, #8]\n\
	ldr r3, _080EDC08 @ =gBlendRegBuffer\n\
	movs r1, #0x1f\n\
	ands r1, r2\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
_080EDBDE:\n\
	ldrh r1, [r5, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r5, r2]\n\
	cmp r0, #0x1f\n\
	bgt _080EDC20\n\
	adds r0, r1, #1\n\
	b _080EDC60\n\
	.align 2, 0\n\
_080EDBEC: .4byte gVideoRegBuffer\n\
_080EDBF0: .4byte 0x0000FFF8\n\
_080EDBF4: .4byte 0x0000F0FF\n\
_080EDBF8: .4byte 0x00000606\n\
_080EDBFC: .4byte gGraphic_Capcom+(22*20)\n\
_080EDC00: .4byte gGraphic_Capcom+(22*20)+12\n\
_080EDC04: .4byte gBgMapOffsets\n\
_080EDC08: .4byte gBlendRegBuffer\n\
_080EDC0C: .4byte 0x00003E41\n\
_080EDC10: .4byte gSystemSavedataManager\n\
_080EDC14: .4byte gSineTable\n\
_080EDC18: .4byte 0x00000241\n\
_080EDC1C: .4byte gJoypad\n\
_080EDC20:\n\
	ldrh r1, [r7, #4]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDC38\n\
	movs r0, #2\n\
	bl PlaySound\n\
	ldrb r0, [r5, #6]\n\
	adds r0, #2\n\
	strb r0, [r5, #6]\n\
	b _080EDCC4\n\
_080EDC38:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDCC4\n\
	movs r0, #3\n\
	bl PlaySound\n\
	movs r0, #0x40\n\
	bl ClearBlink\n\
	ldrb r0, [r5, #6]\n\
	adds r0, #1\n\
	strb r0, [r5, #6]\n\
	b _080EDCC4\n\
_080EDC54:\n\
	ldrh r1, [r5, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r0, [r5, r2]\n\
	cmp r0, #0\n\
	beq _080EDC88\n\
	subs r0, r1, #1\n\
_080EDC60:\n\
	adds r1, r0, #0\n\
	strh r0, [r5, #0xa]\n\
	ldr r2, _080EDC80 @ =gPaletteManager\n\
	ldr r3, _080EDC84 @ =0x00000402\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	subs r3, #1\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
	b _080EDCC4\n\
	.align 2, 0\n\
_080EDC80: .4byte gPaletteManager\n\
_080EDC84: .4byte 0x00000402\n\
_080EDC88:\n\
	movs r0, #0x40\n\
	bl ClearBlink\n\
	adds r0, r5, #0\n\
	movs r1, #4\n\
	bl SetIntroMode\n\
	b _080EDCC4\n\
_080EDC98:\n\
	ldrh r2, [r5, #8]\n\
	movs r3, #8\n\
	ldrsh r0, [r5, r3]\n\
	cmp r0, #0\n\
	beq _080EDCBC\n\
	subs r2, #1\n\
	strh r2, [r5, #8]\n\
	ldr r3, _080EDCB8 @ =gBlendRegBuffer\n\
	movs r1, #0x1f\n\
	ands r1, r2\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
	b _080EDCC4\n\
	.align 2, 0\n\
_080EDCB8: .4byte gBlendRegBuffer\n\
_080EDCBC:\n\
	mov r0, r8\n\
	strb r0, [r5, #6]\n\
	movs r0, #2\n\
	strb r0, [r5, #5]\n\
_080EDCC4:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	mov r1, sb\n\
	lsls r4, r1, #0x10\n\
	asrs r1, r4, #0x10\n\
	ldr r2, _080EDD38 @ =0x00000241\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	bge _080EDDA0\n\
	mov r3, r8\n\
	lsls r1, r3, #0x10\n\
	asrs r0, r1, #0x10\n\
	adds r7, r1, #0\n\
	cmp r0, #6\n\
	bgt _080EDDA0\n\
	ldr r0, _080EDD3C @ =0x020021C8\n\
	mov sl, r0\n\
_080EDCEA:\n\
	ldr r0, _080EDD40 @ =u8_ARRAY_0838607c\n\
	asrs r6, r1, #0x10\n\
	adds r0, r6, r0\n\
	ldrb r1, [r0]\n\
	adds r0, r1, #0\n\
	subs r0, #0xf0\n\
	add r0, sl\n\
	ldrb r2, [r0]\n\
	ldr r0, _080EDD44 @ =gSineTable\n\
	adds r1, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r0\n\
	ldrb r1, [r1]\n\
	cmp r2, r1\n\
	bne _080EDD7A\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	adds r3, r5, r1\n\
	ldrb r0, [r3]\n\
	asrs r2, r4, #0x10\n\
	cmp r0, r2\n\
	bne _080EDD20\n\
	adds r1, #2\n\
	adds r0, r5, r1\n\
	mov r1, r8\n\
	strb r1, [r0]\n\
_080EDD20:\n\
	ldr r4, _080EDD48 @ =StringOfsTable\n\
	ldr r0, _080EDD4C @ =u16_ARRAY_08386084\n\
	lsls r1, r6, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	ldrb r0, [r3]\n\
	cmp r0, r2\n\
	beq _080EDD50\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #1\n\
	b _080EDD52\n\
	.align 2, 0\n\
_080EDD38: .4byte 0x00000241\n\
_080EDD3C: .4byte gSystemSavedataManager+24\n\
_080EDD40: .4byte u8_ARRAY_0838607c\n\
_080EDD44: .4byte gSineTable\n\
_080EDD48: .4byte StringOfsTable\n\
_080EDD4C: .4byte u16_ARRAY_08386084\n\
_080EDD50:\n\
	lsls r0, r1, #1\n\
_080EDD52:\n\
	adds r0, r4, r0\n\
	ldrh r0, [r0]\n\
	ldr r1, _080EDDB0 @ =gStringData\n\
	adds r0, r0, r1\n\
	mov r2, sb\n\
	lsls r4, r2, #0x10\n\
	asrs r4, r4, #0x10\n\
	lsls r2, r4, #1\n\
	adds r2, #0xa\n\
	ldr r3, _080EDDB4 @ =0x00000241\n\
	adds r1, r5, r3\n\
	ldrb r1, [r1]\n\
	subs r2, r2, r1\n\
	movs r1, #8\n\
	bl PrintString\n\
	adds r4, #1\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	mov sb, r4\n\
_080EDD7A:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r7, r1\n\
	lsrs r0, r0, #0x10\n\
	mov r8, r0\n\
	mov r2, sb\n\
	lsls r4, r2, #0x10\n\
	asrs r1, r4, #0x10\n\
	ldr r3, _080EDDB4 @ =0x00000241\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	bge _080EDDA0\n\
	mov r0, r8\n\
	lsls r1, r0, #0x10\n\
	asrs r0, r1, #0x10\n\
	adds r7, r1, #0\n\
	cmp r0, #6\n\
	ble _080EDCEA\n\
_080EDDA0:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EDDB0: .4byte gStringData\n\
_080EDDB4: .4byte 0x00000241\n\
 .syntax divided\n");
}

NAKED static void FUN_080eddb8(struct Intro* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #6]\n\
	cmp r0, #1\n\
	beq _080EDDE2\n\
	cmp r0, #1\n\
	bgt _080EDDCC\n\
	cmp r0, #0\n\
	beq _080EDDD6\n\
	b _080EDEB2\n\
_080EDDCC:\n\
	cmp r0, #2\n\
	beq _080EDE3A\n\
	cmp r0, #3\n\
	beq _080EDE88\n\
	b _080EDEB2\n\
_080EDDD6:\n\
	strh r0, [r6, #8]\n\
	movs r0, #0x20\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #6]\n\
	adds r0, #1\n\
	strb r0, [r6, #6]\n\
_080EDDE2:\n\
	ldrh r2, [r6, #8]\n\
	movs r1, #8\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0xf\n\
	bgt _080EDE00\n\
	adds r2, #1\n\
	strh r2, [r6, #8]\n\
	ldr r3, _080EDE1C @ =gBlendRegBuffer\n\
	movs r1, #0x1f\n\
	ands r1, r2\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
_080EDE00:\n\
	ldr r0, _080EDE20 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDE24\n\
	movs r0, #2\n\
	bl PlaySound\n\
	ldrb r0, [r6, #6]\n\
	adds r0, #1\n\
	strb r0, [r6, #6]\n\
	b _080EDEB2\n\
	.align 2, 0\n\
_080EDE1C: .4byte gBlendRegBuffer\n\
_080EDE20: .4byte gJoypad\n\
_080EDE24:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080EDEB2\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldrb r0, [r6, #6]\n\
	adds r0, #2\n\
	strb r0, [r6, #6]\n\
	b _080EDEB2\n\
_080EDE3A:\n\
	ldrh r0, [r6, #0xa]\n\
	movs r2, #0xa\n\
	ldrsh r4, [r6, r2]\n\
	cmp r4, #0\n\
	beq _080EDE70\n\
	subs r0, #1\n\
	adds r1, r0, #0\n\
	strh r0, [r6, #0xa]\n\
	ldr r2, _080EDE68 @ =gPaletteManager\n\
	ldr r3, _080EDE6C @ =0x00000402\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	subs r3, #1\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
	b _080EDEB2\n\
	.align 2, 0\n\
_080EDE68: .4byte gPaletteManager\n\
_080EDE6C: .4byte 0x00000402\n\
_080EDE70:\n\
	movs r0, #0x40\n\
	bl ClearBlink\n\
	ldr r0, _080EDE84 @ =gBlendRegBuffer\n\
	movs r1, #0\n\
	strh r4, [r0]\n\
	strb r1, [r6, #6]\n\
	movs r0, #3\n\
	b _080EDEB0\n\
	.align 2, 0\n\
_080EDE84: .4byte gBlendRegBuffer\n\
_080EDE88:\n\
	ldrh r2, [r6, #8]\n\
	movs r3, #8\n\
	ldrsh r0, [r6, r3]\n\
	cmp r0, #0\n\
	beq _080EDEAC\n\
	subs r2, #1\n\
	strh r2, [r6, #8]\n\
	ldr r3, _080EDEA8 @ =gBlendRegBuffer\n\
	movs r1, #0x1f\n\
	ands r1, r2\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
	b _080EDEB2\n\
	.align 2, 0\n\
_080EDEA8: .4byte gBlendRegBuffer\n\
_080EDEAC:\n\
	movs r0, #1\n\
	strb r0, [r6, #6]\n\
_080EDEB0:\n\
	strb r0, [r6, #5]\n\
_080EDEB2:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	ldr r5, _080EDEF4 @ =StringOfsTable\n\
	movs r1, #0x88\n\
	lsls r1, r1, #4\n\
	adds r0, r5, r1\n\
	ldrh r0, [r0]\n\
	ldr r4, _080EDEF8 @ =gStringData\n\
	adds r0, r0, r4\n\
	movs r1, #0xd\n\
	movs r2, #2\n\
	bl PrintString\n\
	ldr r1, _080EDEFC @ =0x08386092\n\
	ldr r2, _080EDF00 @ =0x00000242\n\
	adds r0, r6, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r0, [r0]\n\
	adds r0, r0, r4\n\
	movs r1, #3\n\
	movs r2, #4\n\
	bl PrintString\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EDEF4: .4byte StringOfsTable\n\
_080EDEF8: .4byte gStringData\n\
_080EDEFC: .4byte u16_ARRAY_08386092\n\
_080EDF00: .4byte 0x00000242\n\
 .syntax divided\n");
}

static void FUN_080edf04(struct Intro* p) {
  switch (p->mode[2]) {
    case 0: {
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
      gPaletteManager.unk_408 = NULL;
      ClearBlinkings();
      gBlendRegBuffer.bldclt = 0;
      gWindowRegBuffer.dispcnt = 0;
      gWindowRegBuffer.unk_0c[2] = 0xFF;
      wMOSAIC = 0;
      PALETTE16(0) = RGB_BLACK;
      text_080e9730();
      gVideoRegBuffer.dispcnt &= BG_MODE_0;
      gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      SwitchProcess(TRUE);
      SetGameMode(&gGameState, (p->unk_242 << 8) + 3);
      ResetProcess(1, Process_Game);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (gProcessManager.processes[1].status == PROCESS_DISABLED) {
        p->mode[2] = 0;
        p->mode[1] = 1;
      }
      break;
    }
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

const TextID ALIGNED(4) ModCardTextIDs[120] = {
    0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F, 0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0086, 0x0087, 0x0086, 0x0080, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F, 0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0089, 0x008F, 0x0096, 0x0086, 0x0097, 0x0098, 0x0099, 0x009A, 0x008A, 0x009B, 0x009C, 0x009D, 0x007B, 0x009E, 0x0081, 0x0080, 0x009F, 0x0086, 0x008F, 0x0079, 0x00A0, 0x0080, 0x008C, 0x0080, 0x0080, 0x0086, 0x0090, 0x0089, 0x00A1, 0x00A2, 0x0089, 0x0082, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x008F, 0x009C, 0x00AA, 0x0086, 0x007A, 0x0086, 0x00AB, 0x00AC, 0x00AD, 0x00AD, 0x00AE, 0x00AF, 0x00AD, 0x00B0, 0x00AD, 0x00AD, 0x0087, 0x00B1, 0x0079, 0x00B2, 0x0079, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF, 0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE,
};

const u8 MaybeCharTable[122] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x21, 0x22, 0x23, 0x24, 0x2B, 0x2C, 0x30, 0x31, 0x34, 0x35, 0x36, 0x38, 0x39, 0x53, 0x0D, 0x20, 0x25, 0x26, 0x28, 0x29, 0x2D, 0x2E, 0x2F, 0x32, 0x33, 0x37, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x54, 0x56, 0x57, 0x58, 0x5A, 0x5B, 0x5C, 0x05, 0x06, 0x0C, 0x19, 0x27, 0x2A, 0x44, 0x45, 0x4A, 0x52, 0x55, 0x59, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x00,
};

const TextID ALIGNED(2) UnlockMinigameTextIDs[7] = {
    0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8,
};

static const u8 u8_ARRAY_08385f9c[7] = {
    0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8,
};

static const struct Coord Coord_ARRAY_08385fa4[9] = {
    {0x1900, 0x3000}, {0x2D00, 0x3000}, {0x4200, 0x3000}, {0x5800, 0x3000}, {0x6F00, 0x3000}, {0x8B00, 0x3200}, {0xA200, 0x3000}, {0xC600, 0x3000}, {0x9800, 0x3000},
};

static const s32 s32_ARRAY_08385fec[8] = {
    0xA000, 0xA000, 0xA000, 0xA000, 0xA000, 0x5000, 0x5000, 0x5000,
};

static const s32 s32_ARRAY_ARRAY_0838600c[16] = {
    0x00001900, 0x00003000, 0x00002D00, 0x00003000, 0x00004200, 0x00003000, 0x00005800, 0x00003000, 0x00006F00, 0x00003000, 0x00008B00, 0x00003200, 0x0000A200, 0x00003000, 0x0000C600, 0x00003000,
};

static const struct Coord s32_ARRAY_ARRAY_0838604c[4] = {
    {0x3400, -0x1E00},
    {-0xA00, 0x5C00},
    {-0xA00, -0x1E00},
    {0x3400, 0x5C00},
};

static const IntroLoopFunc sIntroMinigameScripts[4] = {
    FUN_080ed9c0,
    minigameSelectScript,
    FUN_080eddb8,
    FUN_080edf04,
};

const u8 ALIGNED(4) u8_ARRAY_0838607c[8] = {
    0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0x00,
};

const u16 ALIGNED(4) u16_ARRAY_08386084[7] = {
    0x020E, 0x0210, 0x0212, 0x0214, 0x0216, 0x0218, 0x021A,
};

const u16 ALIGNED(2) u16_ARRAY_08386092[7] = {
    0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
};
