#include "blink.h"
#include "disk.h"
#include "game.h"
#include "global.h"
#include "text.h"

// "シークレットディスクのカイセキ"のシーン

typedef void (*DiskLoopFunc)(struct GameState*);

void ResetPivot(struct Pivot* p, struct Coord* c, u32 _, void* nullVal);

static const DiskLoopFunc sDiskLoops[5];

static void DiskLoop_Init(struct GameState* g);
static void DiskLoop_OpenScreen(struct GameState* g);
static void DiskLoop_Run(struct GameState* g);
static void DiskLoop_BlackOut(struct GameState* g);
static void DiskLoop_Exit(struct GameState* g);

static void sd_analysis_080f8408(struct GameState* g);

void MainLoop_Disk(struct GameState* g) {
  sDiskLoops[g->mode[1]](g);
  sd_analysis_080f8408(g);
  return;
}

static void sd_analysis_080f83ac(struct GameState* g);
static void setSecretDiskPalette(struct GameState* g);

NAKED static void DiskLoop_Init(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	movs r4, #0\n\
	movs r5, #0\n\
	strh r5, [r7, #4]\n\
	ldr r1, _080F7E2C @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	strb r4, [r0, #0xa]\n\
	strb r4, [r0, #0xb]\n\
	strb r4, [r0, #0xd]\n\
	strb r4, [r0, #0xe]\n\
	strb r4, [r0, #0xf]\n\
	strb r4, [r0, #0x10]\n\
	strb r4, [r0, #0x11]\n\
	strb r4, [r0, #0x12]\n\
	adds r0, r7, #0\n\
	bl sd_analysis_080f83ac\n\
	ldr r4, _080F7E30 @ =gVideoRegBuffer\n\
	ldrh r1, [r4]\n\
	ldr r0, _080F7E34 @ =0x0000FFF8\n\
	ands r0, r1\n\
	ldr r1, _080F7E38 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r2, #0x98\n\
	lsls r2, r2, #5\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r1, _080F7E3C @ =0x00004206\n\
	adds r0, r1, #0\n\
	strh r0, [r4, #6]\n\
	str r5, [r4, #0x10]\n\
	ldr r1, _080F7E40 @ =gBlendRegBuffer\n\
	ldr r0, _080F7E44 @ =0x00002010\n\
	strh r0, [r1]\n\
	ldr r0, _080F7E48 @ =gGraphic_Capcom+(22*20)\n\
	movs r5, #0xc\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, _080F7E4C @ =gGraphic_Capcom+(22*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r2, _080F7E50 @ =0x00000ED8\n\
	adds r0, r7, r2\n\
	ldr r2, _080F7E54 @ =gBgMapOffsets+(101*4)\n\
	ldr r1, [r2]\n\
	adds r1, r1, r2\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl CopyBgMap\n\
	ldr r0, _080F7E58 @ =gSystemSavedataManager\n\
	adds r0, #0x4b\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _080F7E64\n\
	ldr r0, _080F7E5C @ =gGraphic_Capcom+(36*20)\n\
	ldrh r2, [r4, #6]\n\
	adds r1, r5, #0\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080F7E60 @ =gGraphic_Capcom+(36*20)+12\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	b _080F7E7E\n\
	.align 2, 0\n\
_080F7E2C: .4byte 0x00000DCC\n\
_080F7E30: .4byte gVideoRegBuffer\n\
_080F7E34: .4byte 0x0000FFF8\n\
_080F7E38: .4byte 0x0000F0FF\n\
_080F7E3C: .4byte 0x00004206\n\
_080F7E40: .4byte gBlendRegBuffer\n\
_080F7E44: .4byte 0x00002010\n\
_080F7E48: .4byte gGraphic_Capcom+(22*20)\n\
_080F7E4C: .4byte gGraphic_Capcom+(22*20)+12\n\
_080F7E50: .4byte 0x00000ED8\n\
_080F7E54: .4byte gBgMapOffsets+(101*4)\n\
_080F7E58: .4byte gSystemSavedataManager\n\
_080F7E5C: .4byte gGraphic_Capcom+(36*20)\n\
_080F7E60: .4byte gGraphic_Capcom+(36*20)+12\n\
_080F7E64:\n\
	cmp r0, #2\n\
	bne _080F7E7E\n\
	ldr r0, _080F7F78 @ =gGraphic_Capcom+(36*20)+20\n\
	ldrh r2, [r4, #6]\n\
	adds r1, r5, #0\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080F7F7C @ =gGraphic_Capcom+(36*20)+32\n\
	movs r1, #0\n\
	bl LoadPalette\n\
_080F7E7E:\n\
	adds r0, r7, #0\n\
	bl setSecretDiskPalette\n\
	movs r4, #0x8c\n\
	lsls r4, r4, #1\n\
	ldr r0, _080F7F80 @ =gStaticMotionGraphics\n\
	mov r8, r0\n\
	adds r0, r4, r0\n\
	ldr r6, _080F7F84 @ =wStaticGraphicTilenums\n\
	ldrh r1, [r6, #0x1c]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _080F7F88 @ =gStaticMotionGraphics+12\n\
	mov sl, r0\n\
	add r4, sl\n\
	ldr r5, _080F7F8C @ =wStaticMotionPalIDs\n\
	ldrh r1, [r5, #0x1c]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sb, r2\n\
	add r1, sb\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _080F7F90 @ =0x0000067C\n\
	add r8, r4\n\
	adds r6, #0xa6\n\
	ldrh r1, [r6]\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	add r4, sl\n\
	adds r5, #0xa6\n\
	ldrh r1, [r5]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sb\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	adds r0, r7, #0\n\
	movs r1, #3\n\
	bl createMenuCursor\n\
	adds r0, r7, #0\n\
	movs r1, #4\n\
	bl createMenuCursor\n\
	adds r0, r7, #0\n\
	movs r1, #0\n\
	bl createSecretDiskModalBorder\n\
	adds r0, r7, #0\n\
	movs r1, #1\n\
	bl createSecretDiskModalBorder\n\
	adds r0, r7, #0\n\
	movs r1, #2\n\
	bl createSecretDiskModalBorder\n\
	adds r0, r7, #0\n\
	movs r1, #3\n\
	bl createSecretDiskModalBorder\n\
	movs r0, #0x40\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r2, #0\n\
	ldr r3, _080F7F94 @ =0x03002BE0\n\
	adds r4, r3, #0\n\
	subs r4, #0x20\n\
_080F7F34:\n\
	lsls r0, r2, #1\n\
	adds r1, r0, r3\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0xf\n\
	bls _080F7F34\n\
	ldr r1, _080F7F98 @ =0x00000ED8\n\
	adds r0, r7, r1\n\
	ldr r1, _080F7F9C @ =gVideoRegBuffer+6\n\
	ldrh r2, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl RequestBgMapTransfer\n\
	movs r0, #1\n\
	strb r0, [r7, #1]\n\
	adds r0, r7, #0\n\
	bl DiskLoop_OpenScreen\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F7F78: .4byte gGraphic_Capcom+(36*20)+20\n\
_080F7F7C: .4byte gGraphic_Capcom+(36*20)+32\n\
_080F7F80: .4byte gStaticMotionGraphics\n\
_080F7F84: .4byte wStaticGraphicTilenums\n\
_080F7F88: .4byte gStaticMotionGraphics+12\n\
_080F7F8C: .4byte wStaticMotionPalIDs\n\
_080F7F90: .4byte 0x0000067C\n\
_080F7F94: .4byte 0x03002BE0\n\
_080F7F98: .4byte 0x00000ED8\n\
_080F7F9C: .4byte gVideoRegBuffer+6\n\
 .syntax divided\n");
}

static void DiskLoop_OpenScreen(struct GameState* g) {
  g->frames++;
  if (g->frames >= 16) {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
    g->mode[1] = 2;
    DiskLoop_Run(g);
  } else {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  }
}

static void printThreeDigitNumber(u16 n, u8 x, u8 y);

NAKED static void DiskLoop_Run(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	mov sb, r0\n\
	ldr r4, _080F80A8 @ =0x00000DCC\n\
	add r4, sb\n\
	movs r0, #0\n\
	strb r0, [r4, #0xc]\n\
	ldr r1, _080F80AC @ =PTR_ARRAY_083864ac\n\
	mov r2, sb\n\
	ldrb r0, [r2, #2]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sb\n\
	bl _call_via_r1\n\
	ldr r0, _080F80B0 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F8046\n\
	movs r0, #3\n\
	mov r3, sb\n\
	strb r0, [r3, #1]\n\
_080F8046:\n\
	ldr r7, _080F80B4 @ =StringOfsTable\n\
	movs r1, #0xef\n\
	lsls r1, r1, #2\n\
	adds r0, r7, r1\n\
	ldrh r0, [r0]\n\
	ldr r2, _080F80B8 @ =gStringData\n\
	mov r8, r2\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #1\n\
	bl PrintString\n\
	ldrb r0, [r4, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0x16\n\
	movs r2, #1\n\
	bl printThreeDigitNumber\n\
	ldr r0, _080F80BC @ =gStageDiskManager\n\
	ldr r1, [r0]\n\
	ldrb r2, [r4, #0xa]\n\
	lsls r0, r2, #0x18\n\
	lsrs r3, r0, #0x18\n\
	lsrs r0, r0, #0x1a\n\
	adds r5, r1, r0\n\
	ldrb r1, [r5]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #3\n\
	ands r1, r2\n\
	asrs r0, r1\n\
	movs r2, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F808E\n\
	b _080F823C\n\
_080F808E:\n\
	ldrb r0, [r5]\n\
	adds r1, #4\n\
	asrs r0, r1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080F809C\n\
	b _080F8214\n\
_080F809C:\n\
	cmp r3, #5\n\
	bhi _080F80C0\n\
	movs r3, #0xaf\n\
	lsls r3, r3, #2\n\
	adds r0, r3, #0\n\
	b _080F80CA\n\
	.align 2, 0\n\
_080F80A8: .4byte 0x00000DCC\n\
_080F80AC: .4byte PTR_ARRAY_083864ac\n\
_080F80B0: .4byte gJoypad\n\
_080F80B4: .4byte StringOfsTable\n\
_080F80B8: .4byte gStringData\n\
_080F80BC: .4byte gStageDiskManager\n\
_080F80C0:\n\
	cmp r3, #0x13\n\
	bhi _080F80E0\n\
	movs r1, #0xaf\n\
	lsls r1, r1, #2\n\
	adds r0, r1, #0\n\
_080F80CA:\n\
	ldrb r4, [r4, #0xa]\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl PrintString\n\
	b _080F81F8\n\
_080F80E0:\n\
	cmp r3, #0x5d\n\
	bhi _080F8140\n\
	ldrb r0, [r4, #0xa]\n\
	adds r6, r0, #0\n\
	adds r6, #0x50\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #3\n\
	adds r0, r7, r2\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl PrintString\n\
	lsls r4, r6, #1\n\
	adds r4, r4, r7\n\
	ldrh r0, [r4]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #6\n\
	bl PrintString\n\
	ldr r3, _080F8138 @ =0x000005A2\n\
	adds r0, r7, r3\n\
	ldrh r5, [r0]\n\
	add r5, r8\n\
	ldrh r0, [r4]\n\
	add r0, r8\n\
	bl getStringLength\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r1, #0x11\n\
	adds r0, r5, #0\n\
	movs r2, #6\n\
	bl PrintString\n\
	ldr r1, _080F813C @ =0x000005A4\n\
	adds r0, r7, r1\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	b _080F81BC\n\
	.align 2, 0\n\
_080F8138: .4byte 0x000005A2\n\
_080F813C: .4byte 0x000005A4\n\
_080F8140:\n\
	cmp r3, #0x6d\n\
	bhi _080F81E0\n\
	ldr r2, _080F81C8 @ =0x000005A6\n\
	adds r0, r7, r2\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl PrintString\n\
	movs r6, #0\n\
	ldr r1, _080F81CC @ =DiskECrystalAmounts\n\
	ldrb r0, [r4, #0xa]\n\
	subs r0, #0x5e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0]\n\
	cmp r2, #0\n\
	beq _080F817C\n\
_080F8166:\n\
	adds r0, r2, #0\n\
	movs r1, #0xa\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r2, #0\n\
	bne _080F8166\n\
_080F817C:\n\
	ldr r1, _080F81CC @ =DiskECrystalAmounts\n\
	ldr r0, _080F81D0 @ =0x00000DCC\n\
	add r0, sb\n\
	ldrb r0, [r0, #0xa]\n\
	subs r0, #0x5e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0x11\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r2, #0\n\
	movs r2, #6\n\
	bl PrintNumber\n\
	ldr r4, _080F81D4 @ =StringOfsTable\n\
	movs r3, #0xb5\n\
	lsls r3, r3, #3\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	ldr r5, _080F81D8 @ =gStringData\n\
	adds r0, r0, r5\n\
	adds r1, r6, #0\n\
	adds r1, #0x12\n\
	movs r2, #6\n\
	bl PrintString\n\
	ldr r0, _080F81DC @ =0x000005AA\n\
	adds r4, r4, r0\n\
	ldrh r0, [r4]\n\
	adds r0, r0, r5\n\
_080F81BC:\n\
	movs r1, #0x11\n\
	movs r2, #8\n\
	bl PrintString\n\
	b _080F81F8\n\
	.align 2, 0\n\
_080F81C8: .4byte 0x000005A6\n\
_080F81CC: .4byte DiskECrystalAmounts\n\
_080F81D0: .4byte 0x00000DCC\n\
_080F81D4: .4byte StringOfsTable\n\
_080F81D8: .4byte gStringData\n\
_080F81DC: .4byte 0x000005AA\n\
_080F81E0:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x9a\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl PrintString\n\
_080F81F8:\n\
	ldr r0, _080F8208 @ =StringOfsTable\n\
	ldr r2, _080F820C @ =0x000003BA\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, _080F8210 @ =gStringData\n\
	adds r0, r0, r1\n\
	b _080F822E\n\
	.align 2, 0\n\
_080F8208: .4byte StringOfsTable\n\
_080F820C: .4byte 0x000003BA\n\
_080F8210: .4byte gStringData\n\
_080F8214:\n\
	ldr r3, _080F8238 @ =0x000003BE\n\
	adds r0, r7, r3\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #0x11\n\
	movs r2, #4\n\
	bl PrintString\n\
	movs r1, #0xee\n\
	lsls r1, r1, #2\n\
	adds r0, r7, r1\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
_080F822E:\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
	b _080F824C\n\
	.align 2, 0\n\
_080F8238: .4byte 0x000003BE\n\
_080F823C:\n\
	ldr r2, _080F82AC @ =0x000003BA\n\
	adds r0, r7, r2\n\
	ldrh r0, [r0]\n\
	add r0, r8\n\
	movs r1, #1\n\
	movs r2, #0x12\n\
	bl PrintString\n\
_080F824C:\n\
	ldr r5, _080F82B0 @ =0x00000DCC\n\
	add r5, sb\n\
	ldrb r0, [r5, #0xe]\n\
	cmp r0, #0\n\
	beq _080F82BC\n\
	ldr r2, _080F82B4 @ =gPaletteManager\n\
	ldrb r1, [r5, #0x12]\n\
	lsls r1, r1, #0xa\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #5\n\
	orrs r1, r0\n\
	ldrb r0, [r5, #0x10]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _080F82B8 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #6\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0x10\n\
	strb r0, [r2, #0xc]\n\
	ldrb r1, [r2, #0xe]\n\
	movs r0, #3\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xe]\n\
	ldrb r3, [r5, #0xe]\n\
	adds r1, r3, #0\n\
	adds r1, #0x40\n\
	movs r4, #0xff\n\
	ands r1, r4\n\
	movs r0, #0x40\n\
	subs r0, r0, r3\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r2, #4]\n\
	ldrb r3, [r5, #0xf]\n\
	adds r1, r3, #0\n\
	adds r1, #0x50\n\
	ands r1, r4\n\
	movs r0, #0x50\n\
	subs r0, r0, r3\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r2, #8]\n\
	b _080F82CE\n\
	.align 2, 0\n\
_080F82AC: .4byte 0x000003BA\n\
_080F82B0: .4byte 0x00000DCC\n\
_080F82B4: .4byte gPaletteManager\n\
_080F82B8: .4byte gWindowRegBuffer\n\
_080F82BC:\n\
	ldr r2, _080F82F0 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _080F82F4 @ =0x0000DFFF\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strh r0, [r2]\n\
	strb r1, [r5, #0x10]\n\
	strb r1, [r5, #0x11]\n\
	strb r1, [r5, #0x12]\n\
_080F82CE:\n\
	movs r0, #0x40\n\
	bl UpdateBlinkMotionState\n\
	ldr r0, _080F82F8 @ =0x00000DCC\n\
	add r0, sb\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0\n\
	beq _080F82E4\n\
	mov r0, sb\n\
	bl setSecretDiskPalette\n\
_080F82E4:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F82F0: .4byte gWindowRegBuffer\n\
_080F82F4: .4byte 0x0000DFFF\n\
_080F82F8: .4byte 0x00000DCC\n\
 .syntax divided\n");
}

static void DiskLoop_BlackOut(struct GameState* g) {
  g->frames--;
  if (g->frames == 0) {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x0;
    g->mode[1] = 4;
    DiskLoop_Exit(g);
  } else {
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = g->frames;
  }
}

static void DiskLoop_Exit(struct GameState* g) {
  u8* s;
  ClearBlink(64);
  gWindowRegBuffer.dispcnt &= 0xDFFF;
  PALETTE16(0) = 0;
  s = (u8*)&(g->sceneState).menu;
  s[13] = 1;
  SetGameMode(g, GAMEMODE(MAINGAME, OVERWORLD, 3, 5));
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void sd_analysis_080f83ac(struct GameState* g) {
  struct Coord* c = &g->unk_0dc4;
  c->x = PIXEL(120);
  c->y = PIXEL(80);
  ResetPivot(&g->unk_0db8, c, 0, 0);
  ResetTaskManager(&g->taskManager2);
  SetTaskPivot(&g->taskManager2, &g->unk_0db8);
  InitWidgetHeader(&g->entityHeaders[ENTITY_WIDGET], gWidgets, 64);
}

static void sd_analysis_080f8408(struct GameState* g) {
  struct Coord* c = &g->unk_0dc4;
  const u16* bg1ofs = gVideoRegBuffer.bgofs[1];
  c->x = PIXEL(bg1ofs[0] & 0x1FF) + PIXEL(120);
  ClearTaskBuffer(&g->taskManager2);
  UpdateEntities(gWidgetHeaderPtr);
  DrawEntity(gWidgetHeaderPtr, &g->taskManager2);
  RunAllTasks(&g->taskManager2);
}

NAKED static void setSecretDiskPalette(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov r8, r0\n\
	ldr r6, _080F84F8 @ =0x00000ED8\n\
	add r6, r8\n\
	movs r5, #0\n\
	ldr r0, _080F84FC @ =gStageDiskManager\n\
	mov sb, r0\n\
	ldr r1, _080F8500 @ =gVideoRegBuffer+6\n\
	mov sl, r1\n\
	ldr r2, _080F8504 @ =0x000031A2\n\
	adds r7, r2, #0\n\
_080F847A:\n\
	mov r3, sb\n\
	ldr r2, [r3]\n\
	ldr r0, _080F8508 @ =0x00000DCC\n\
	add r0, r8\n\
	ldrb r0, [r0, #0xb]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	adds r1, r1, r5\n\
	asrs r0, r1, #2\n\
	adds r3, r2, r0\n\
	ldrb r2, [r3]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	movs r2, #3\n\
	ands r2, r1\n\
	asrs r0, r2\n\
	movs r4, #1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080F856C\n\
	ldrb r0, [r3]\n\
	adds r1, r2, #4\n\
	asrs r0, r1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080F8514\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsls r4, r4, #6\n\
	lsrs r0, r0, #0x17\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	adds r2, r4, r6\n\
	adds r1, r2, #0\n\
	adds r1, #0xc6\n\
	ldr r3, _080F850C @ =0x000080ED\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x83\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	adds r3, #0x1f\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r2, _080F8510 @ =0x0000810E\n\
	b _080F855C\n\
	.align 2, 0\n\
_080F84F8: .4byte 0x00000ED8\n\
_080F84FC: .4byte gStageDiskManager\n\
_080F8500: .4byte gVideoRegBuffer+6\n\
_080F8504: .4byte 0x000031A2\n\
_080F8508: .4byte 0x00000DCC\n\
_080F850C: .4byte 0x000080ED\n\
_080F8510: .4byte 0x0000810E\n\
_080F8514:\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsls r4, r4, #6\n\
	lsrs r0, r0, #0x17\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	adds r2, r4, r6\n\
	adds r1, r2, #0\n\
	adds r1, #0xc6\n\
	ldr r3, _080F8564 @ =0x000080EB\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x83\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	adds r3, #0x1f\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r2, _080F8568 @ =0x0000810C\n\
_080F855C:\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	b _080F85A8\n\
	.align 2, 0\n\
_080F8564: .4byte 0x000080EB\n\
_080F8568: .4byte 0x0000810C\n\
_080F856C:\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsls r4, r4, #6\n\
	lsrs r0, r0, #0x17\n\
	adds r4, r4, r0\n\
	lsls r4, r4, #1\n\
	adds r1, r4, r6\n\
	adds r0, r1, #0\n\
	adds r0, #0xc6\n\
	strh r7, [r0]\n\
	adds r0, #2\n\
	strh r7, [r0]\n\
	movs r3, #0x83\n\
	lsls r3, r3, #1\n\
	adds r0, r1, r3\n\
	strh r7, [r0]\n\
	movs r2, #0x84\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	strh r7, [r0]\n\
_080F85A8:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0x1d\n\
	bhi _080F85B4\n\
	b _080F847A\n\
_080F85B4:\n\
	ldr r0, _080F85DC @ =0x00000ED8\n\
	add r0, r8\n\
	mov r3, sl\n\
	ldrh r2, [r3]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl RequestBgMapTransfer\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F85DC: .4byte 0x00000ED8\n\
 .syntax divided\n");
}

NAKED static void sd_analysis_080f85e0(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0\n\
	bne _080F8638\n\
	ldr r0, _080F8634 @ =0x00000DCC\n\
	adds r5, r6, r0\n\
	movs r0, #1\n\
	strb r0, [r5, #0xc]\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CreateMenuComp2\n\
	adds r4, r0, #0\n\
	str r4, [r5, #4]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #5\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x14\n\
	adds r0, #0x18\n\
	adds r4, #0x74\n\
	strh r0, [r4]\n\
	ldr r4, [r5, #4]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r5, #0xb]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #4\n\
	adds r0, #0x18\n\
	adds r4, #0x76\n\
	strh r0, [r4]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
	b _080F8754\n\
	.align 2, 0\n\
_080F8634: .4byte 0x00000DCC\n\
_080F8638:\n\
	ldr r0, _080F8654 @ =0x00000DCC\n\
	adds r3, r6, r0\n\
	ldrb r1, [r3, #0xa]\n\
	ldr r0, _080F8658 @ =gJoypad\n\
	ldrh r2, [r0, #6]\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F865C\n\
	cmp r1, #0\n\
	beq _080F868C\n\
	subs r0, r1, #1\n\
	b _080F868A\n\
	.align 2, 0\n\
_080F8654: .4byte 0x00000DCC\n\
_080F8658: .4byte gJoypad\n\
_080F865C:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F866C\n\
	cmp r1, #0xb2\n\
	bhi _080F868C\n\
	adds r0, r1, #1\n\
	b _080F868A\n\
_080F866C:\n\
	movs r0, #0x40\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F867C\n\
	cmp r1, #4\n\
	bls _080F868C\n\
	subs r0, r1, #5\n\
	b _080F868A\n\
_080F867C:\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080F868C\n\
	cmp r1, #0xae\n\
	bhi _080F868C\n\
	adds r0, r1, #5\n\
_080F868A:\n\
	strb r0, [r3, #0xa]\n\
_080F868C:\n\
	ldr r0, _080F86B4 @ =0x00000DCC\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4, #0xa]\n\
	cmp r1, r0\n\
	beq _080F869C\n\
	movs r0, #1\n\
	bl PlaySound\n\
_080F869C:\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xb]\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	bls _080F86B8\n\
	strb r2, [r4, #0xb]\n\
	b _080F86C4\n\
	.align 2, 0\n\
_080F86B4: .4byte 0x00000DCC\n\
_080F86B8:\n\
	ldrb r1, [r4, #0xb]\n\
	subs r0, #5\n\
	cmp r1, r0\n\
	bge _080F86C8\n\
	subs r0, r2, #5\n\
	strb r0, [r4, #0xb]\n\
_080F86C4:\n\
	movs r0, #1\n\
	strb r0, [r4, #0xc]\n\
_080F86C8:\n\
	ldr r0, _080F8734 @ =0x00000DCC\n\
	adds r5, r6, r0\n\
	ldr r4, [r5, #4]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #5\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x14\n\
	adds r0, #0x18\n\
	adds r4, #0x74\n\
	strh r0, [r4]\n\
	ldr r4, [r5, #4]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r5, #0xb]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #4\n\
	adds r0, #0x18\n\
	adds r4, #0x76\n\
	strh r0, [r4]\n\
	ldr r0, _080F8738 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r4, #1\n\
	movs r3, #1\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F8748\n\
	ldr r0, _080F873C @ =gStageDiskManager\n\
	ldr r0, [r0]\n\
	ldrb r2, [r5, #0xa]\n\
	lsrs r1, r2, #2\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r1\n\
	movs r1, #3\n\
	ands r1, r2\n\
	asrs r0, r1\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080F8740\n\
	ldr r0, [r5, #4]\n\
	adds r0, #0x78\n\
	strb r4, [r0]\n\
	strb r4, [r6, #2]\n\
	movs r0, #0\n\
	strb r0, [r6, #3]\n\
	b _080F8754\n\
	.align 2, 0\n\
_080F8734: .4byte 0x00000DCC\n\
_080F8738: .4byte gJoypad\n\
_080F873C: .4byte gStageDiskManager\n\
_080F8740:\n\
	movs r0, #4\n\
	bl PlaySound\n\
	b _080F8754\n\
_080F8748:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F8754\n\
	movs r0, #3\n\
	strb r0, [r6, #1]\n\
_080F8754:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void sd_analysis_080f875c(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	mov r8, r0\n\
	ldrb r0, [r0, #3]\n\
	cmp r0, #0\n\
	bne _080F880C\n\
	ldr r0, _080F8798 @ =gStageDiskManager\n\
	ldr r1, [r0]\n\
	ldr r0, _080F879C @ =0x00000DCC\n\
	add r0, r8\n\
	ldrb r2, [r0, #0xa]\n\
	lsrs r0, r2, #2\n\
	adds r1, r1, r0\n\
	ldrb r1, [r1]\n\
	movs r0, #3\n\
	ands r0, r2\n\
	adds r0, #4\n\
	asrs r1, r0\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080F87A0\n\
	movs r0, #2\n\
	bl PlaySound\n\
	b _080F87A6\n\
	.align 2, 0\n\
_080F8798: .4byte gStageDiskManager\n\
_080F879C: .4byte 0x00000DCC\n\
_080F87A0:\n\
	movs r0, #0xe\n\
	bl PlaySound\n\
_080F87A6:\n\
	ldr r4, _080F87CC @ =0x00000DCC\n\
	add r4, r8\n\
	ldrb r1, [r4, #0xa]\n\
	mov r0, r8\n\
	movs r2, #0\n\
	bl OpenSecretDisk\n\
	ldrb r0, [r4, #0xa]\n\
	cmp r0, #0x13\n\
	bls _080F87F4\n\
	cmp r0, #0x2e\n\
	bhi _080F87D0\n\
	movs r0, #0x13\n\
	strb r0, [r4, #0x10]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x11]\n\
	movs r0, #9\n\
	strb r0, [r4, #0x12]\n\
	b _080F87FC\n\
	.align 2, 0\n\
_080F87CC: .4byte 0x00000DCC\n\
_080F87D0:\n\
	cmp r0, #0x3b\n\
	bhi _080F87E2\n\
	movs r0, #2\n\
	strb r0, [r4, #0x10]\n\
	movs r0, #0x11\n\
	strb r0, [r4, #0x11]\n\
	movs r0, #7\n\
	strb r0, [r4, #0x12]\n\
	b _080F87FC\n\
_080F87E2:\n\
	cmp r0, #0x5d\n\
	bhi _080F87F4\n\
	movs r0, #8\n\
	strb r0, [r4, #0x10]\n\
	movs r0, #0xb\n\
	strb r0, [r4, #0x11]\n\
	movs r0, #0x16\n\
	strb r0, [r4, #0x12]\n\
	b _080F87FC\n\
_080F87F4:\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	strb r0, [r4, #0x11]\n\
	strb r0, [r4, #0x10]\n\
_080F87FC:\n\
	ldr r1, _080F88E0 @ =0x00000DCC\n\
	add r1, r8\n\
	movs r0, #1\n\
	strb r0, [r1, #0xc]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #3]\n\
	adds r0, #1\n\
	strb r0, [r1, #3]\n\
_080F880C:\n\
	movs r7, #2\n\
	ldr r2, _080F88E4 @ =0x03002BC0\n\
	mov sl, r2\n\
	movs r4, #0x1f\n\
	mov sb, r4\n\
	movs r5, #0x1f\n\
	mov ip, r5\n\
_080F881A:\n\
	lsls r0, r7, #1\n\
	mov r1, sl\n\
	adds r6, r0, r1\n\
	ldrh r1, [r6]\n\
	adds r4, r1, #0\n\
	ldr r2, _080F88E8 @ =0x03002BE0\n\
	adds r0, r0, r2\n\
	ldrh r2, [r0]\n\
	str r2, [sp, #0xc]\n\
	movs r0, #0x1f\n\
	adds r3, r1, #0\n\
	ands r3, r0\n\
	adds r0, r2, #0\n\
	mov r5, ip\n\
	ands r0, r5\n\
	lsrs r0, r0, #1\n\
	cmp r3, r0\n\
	bls _080F8844\n\
	subs r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_080F8844:\n\
	lsrs r1, r1, #5\n\
	mov r0, ip\n\
	ands r1, r0\n\
	lsrs r0, r2, #5\n\
	mov r2, sb\n\
	ands r0, r2\n\
	lsrs r0, r0, #1\n\
	cmp r1, r0\n\
	bls _080F885C\n\
	subs r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
_080F885C:\n\
	lsrs r2, r4, #0xa\n\
	mov r4, ip\n\
	ands r2, r4\n\
	ldr r5, [sp, #0xc]\n\
	lsrs r0, r5, #0xa\n\
	mov r4, sb\n\
	ands r0, r4\n\
	lsrs r0, r0, #1\n\
	cmp r2, r0\n\
	bls _080F8876\n\
	subs r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
_080F8876:\n\
	lsls r0, r2, #0xa\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	orrs r0, r3\n\
	strh r0, [r6]\n\
	adds r0, r7, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	cmp r7, #0xf\n\
	bls _080F881A\n\
	ldr r5, _080F88EC @ =u8_ARRAY_ARRAY_083864d8\n\
	ldr r4, _080F88E0 @ =0x00000DCC\n\
	add r4, r8\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	adds r1, r0, r5\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080F8950\n\
	ldrb r0, [r1, #5]\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x19\n\
	ldrb r3, [r4, #0xe]\n\
	cmp r3, r2\n\
	bhs _080F88F0\n\
	lsrs r1, r0, #0x1c\n\
	adds r1, r3, r1\n\
	strb r1, [r4, #0xe]\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0, #6]\n\
	lsrs r0, r0, #4\n\
	ldrb r2, [r4, #0xf]\n\
	adds r0, r0, r2\n\
	strb r0, [r4, #0xf]\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	adds r2, r0, r5\n\
	ldrb r0, [r2, #5]\n\
	lsrs r0, r0, #1\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	cmp r1, r0\n\
	bls _080F88D2\n\
	strb r0, [r4, #0xe]\n\
_080F88D2:\n\
	ldrb r0, [r2, #6]\n\
	lsrs r1, r0, #1\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, r1\n\
	bls _080F8950\n\
	strb r1, [r4, #0xf]\n\
	b _080F8950\n\
	.align 2, 0\n\
_080F88E0: .4byte 0x00000DCC\n\
_080F88E4: .4byte 0x03002BC0\n\
_080F88E8: .4byte 0x03002BE0\n\
_080F88EC: .4byte u8_ARRAY_ARRAY_083864d8\n\
_080F88F0:\n\
	strb r2, [r4, #0xe]\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	ldr r5, _080F897C @ =u8_ARRAY_ARRAY_083864d8\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0, #6]\n\
	lsrs r0, r0, #1\n\
	strb r0, [r4, #0xf]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #3]\n\
	ldrb r5, [r4, #0xa]\n\
	cmp r0, #1\n\
	bne _080F8950\n\
	lsls r0, r5, #3\n\
	ldr r2, _080F897C @ =u8_ARRAY_ARRAY_083864d8\n\
	adds r0, r0, r2\n\
	ldrb r2, [r0, #4]\n\
	ldrh r3, [r0]\n\
	movs r1, #2\n\
	ldrsb r1, [r0, r1]\n\
	movs r0, #0x40\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	str r0, [sp]\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	ldr r1, _080F897C @ =u8_ARRAY_ARRAY_083864d8\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	ldrsb r1, [r0, r1]\n\
	movs r0, #0x50\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #4]\n\
	ldrb r0, [r4, #0xa]\n\
	lsls r0, r0, #3\n\
	ldr r4, _080F897C @ =u8_ARRAY_ARRAY_083864d8\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0, #7]\n\
	str r0, [sp, #8]\n\
	mov r0, r8\n\
	adds r1, r5, #0\n\
	bl FUN_080e83d0\n\
	mov r5, r8\n\
	ldrb r0, [r5, #3]\n\
	adds r0, #1\n\
	strb r0, [r5, #3]\n\
_080F8950:\n\
	ldr r0, _080F8980 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F896A\n\
	movs r0, #3\n\
	bl PlaySound\n\
	mov r1, r8\n\
	ldrb r0, [r1, #2]\n\
	adds r0, #1\n\
	strb r0, [r1, #2]\n\
_080F896A:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F897C: .4byte u8_ARRAY_ARRAY_083864d8\n\
_080F8980: .4byte gJoypad\n\
 .syntax divided\n");
}

NAKED static void sd_analysis_080f8984(struct GameState* g) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	ldr r0, _080F89B8 @ =0x00000DCC\n\
	adds r2, r3, r0\n\
	ldrb r0, [r2, #0xe]\n\
	cmp r0, #0\n\
	beq _080F89F4\n\
	adds r4, r0, #0\n\
	ldr r1, _080F89BC @ =u8_ARRAY_ARRAY_083864d8\n\
	ldrb r0, [r2, #0xa]\n\
	lsls r0, r0, #3\n\
	adds r5, r0, r1\n\
	ldrb r0, [r5, #5]\n\
	lsrs r1, r0, #4\n\
	subs r0, r4, r1\n\
	cmp r0, #0\n\
	ble _080F89C6\n\
	strb r0, [r2, #0xe]\n\
	ldrb r3, [r2, #0xf]\n\
	ldrb r0, [r5, #6]\n\
	lsrs r1, r0, #4\n\
	subs r0, r3, r1\n\
	cmp r0, #0\n\
	ble _080F89C0\n\
	strb r0, [r2, #0xf]\n\
	b _080F8A18\n\
	.align 2, 0\n\
_080F89B8: .4byte 0x00000DCC\n\
_080F89BC: .4byte u8_ARRAY_ARRAY_083864d8\n\
_080F89C0:\n\
	movs r0, #0\n\
	strb r0, [r2, #0xf]\n\
	b _080F8A18\n\
_080F89C6:\n\
	movs r0, #0\n\
	strb r0, [r2, #0xe]\n\
	strb r0, [r2, #0xf]\n\
	strb r0, [r3, #2]\n\
	strb r0, [r3, #3]\n\
	movs r2, #2\n\
	ldr r3, _080F89F0 @ =0x03002BC0\n\
	adds r4, r3, #0\n\
	adds r4, #0x20\n\
_080F89D8:\n\
	lsls r0, r2, #1\n\
	adds r1, r0, r3\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0xf\n\
	bls _080F89D8\n\
	b _080F8A18\n\
	.align 2, 0\n\
_080F89F0: .4byte 0x03002BC0\n\
_080F89F4:\n\
	strb r0, [r2, #0xe]\n\
	strb r0, [r2, #0xf]\n\
	strb r0, [r3, #2]\n\
	strb r0, [r3, #3]\n\
	movs r2, #2\n\
	ldr r3, _080F8A20 @ =0x03002BC0\n\
	adds r4, r3, #0\n\
	adds r4, #0x20\n\
_080F8A04:\n\
	lsls r0, r2, #1\n\
	adds r1, r0, r3\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0xf\n\
	bls _080F8A04\n\
_080F8A18:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F8A20: .4byte 0x03002BC0\n\
 .syntax divided\n");
}

static void printThreeDigitNumber(u16 n, u8 x, u8 y) {
  u8 i;
  for (i = 0; i < 3; i++) {
    u32 digit = n % 10;
    PrintString(STRING(digit + 30), x - i, y);
    n /= 10;
  }
}

/**
 * @brief シークレットディスクを開ける処理
 * @param disk_no ディスク番号
 * @param is_result 1(リザルト画面) or 0(セルヴォの解析)
 * @note 0x080f8a84
 */
NAKED u16 OpenSecretDisk(struct GameState* g, u8 disk_no, bool8 is_result) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	lsls r1, r1, #0x18\n\
	lsrs r5, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	ldr r1, _080F8AD8 @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r4, [r0]\n\
	cmp r2, #0\n\
	beq _080F8AA4\n\
	subs r0, r5, #6\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xd\n\
	bls _080F8B6C\n\
	cmp r5, #0x6d\n\
	bhi _080F8B6C\n\
_080F8AA4:\n\
	ldr r0, _080F8ADC @ =gStageDiskManager\n\
	ldr r1, [r0]\n\
	lsrs r0, r5, #2\n\
	adds r6, r1, r0\n\
	ldrb r2, [r6]\n\
	movs r3, #3\n\
	ands r3, r5\n\
	adds r1, r3, #4\n\
	adds r0, r2, #0\n\
	asrs r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F8B6C\n\
	movs r0, #0x10\n\
	lsls r0, r3\n\
	orrs r2, r0\n\
	strb r2, [r6]\n\
	cmp r5, #5\n\
	bhi _080F8B48\n\
	lsls r0, r5, #2\n\
	ldr r1, _080F8AE0 @ =_080F8AE4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F8AD8: .4byte 0x000064AC\n\
_080F8ADC: .4byte gStageDiskManager\n\
_080F8AE0: .4byte _080F8AE4\n\
_080F8AE4: @ jump table\n\
	.4byte _080F8AFC @ case 0\n\
	.4byte _080F8B06 @ case 1\n\
	.4byte _080F8B10 @ case 2\n\
	.4byte _080F8B1E @ case 3\n\
	.4byte _080F8B28 @ case 4\n\
	.4byte _080F8B32 @ case 5\n\
_080F8AFC:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x17]\n\
	movs r0, #4\n\
	b _080F8B18\n\
_080F8B06:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x17]\n\
	movs r0, #2\n\
	b _080F8B18\n\
_080F8B10:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x17]\n\
	movs r0, #8\n\
_080F8B18:\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x17]\n\
	b _080F8B3E\n\
_080F8B1E:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x19]\n\
	movs r0, #0x40\n\
	b _080F8B3A\n\
_080F8B28:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x19]\n\
	movs r0, #2\n\
	b _080F8B3A\n\
_080F8B32:\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r1, [r2, #0x19]\n\
	movs r0, #0x80\n\
_080F8B3A:\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x19]\n\
_080F8B3E:\n\
	ldr r1, _080F8B44 @ =0x0000017B\n\
	b _080F8B84\n\
	.align 2, 0\n\
_080F8B44: .4byte 0x0000017B\n\
_080F8B48:\n\
	cmp r5, #0x13\n\
	bls _080F8B6C\n\
	cmp r5, #0x5d\n\
	bhi _080F8B68\n\
	ldr r0, _080F8B64 @ =gUnlockedElfPtr\n\
	ldr r1, [r0]\n\
	adds r1, r5, r1\n\
	subs r1, #0x14\n\
	ldrb r0, [r1]\n\
	movs r2, #1\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	b _080F8B82\n\
	.align 2, 0\n\
_080F8B64: .4byte gUnlockedElfPtr\n\
_080F8B68:\n\
	cmp r5, #0x6d\n\
	bls _080F8B70\n\
_080F8B6C:\n\
	movs r0, #0\n\
	b _080F8B86\n\
_080F8B70:\n\
	ldr r1, _080F8B8C @ =DiskECrystalAmounts\n\
	adds r0, r5, #0\n\
	subs r0, #0x5e\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl AddECrystal\n\
_080F8B82:\n\
	ldr r1, _080F8B90 @ =0x0000010D\n\
_080F8B84:\n\
	adds r0, r5, r1\n\
_080F8B86:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080F8B8C: .4byte DiskECrystalAmounts\n\
_080F8B90: .4byte 0x0000010D\n\
 .syntax divided\n");
}

/**
 * @param flagbits &SaveSlot.disk[0] (addr: 0x02036e78)
 * @note 0x080f8b94
 */
void clearSecretDiskData(u8* flagbits) {
  gStageDiskManager.disk = flagbits;
  CpuFastFill(0, flagbits, 32);
  CpuFill32(0, &flagbits[32], 16);
  clearStageDisk();
}

/**
 * @brief clearSecretDiskData のハードモード版
 * @note 0x080f8bd4, 処理は clearSecretDiskData と完全に同じ
 */
void clearSecretDiskDataHard(u8* flagbits) {
  gStageDiskManager.disk = flagbits;
  CpuFastFill(0, flagbits, 32);
  CpuFill32(0, &flagbits[32], 16);
  clearStageDisk();
}

/**
 * @brief clearSecretDiskData のアルティメットモード版
 * @note 0x080f8c14
 */
NAKED void unlockAllSecretDisk(u8* flagbits) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldr r6, _080F8C74 @ =gStageDiskManager\n\
	str r4, [r6]\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r2, _080F8C78 @ =0x01000008\n\
	mov r0, sp\n\
	adds r1, r4, #0\n\
	bl CpuFastSet\n\
	str r5, [sp, #4]\n\
	add r0, sp, #4\n\
	adds r4, #0x20\n\
	ldr r2, _080F8C7C @ =0x05000004\n\
	adds r1, r4, #0\n\
	bl CpuSet\n\
	movs r7, #3\n\
_080F8C3C:\n\
	ldr r2, [r6]\n\
	lsrs r4, r5, #2\n\
	adds r2, r2, r4\n\
	adds r3, r5, #0\n\
	ands r3, r7\n\
	movs r0, #1\n\
	lsls r0, r3\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldr r2, [r6]\n\
	adds r2, r2, r4\n\
	movs r0, #0x10\n\
	lsls r0, r3\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0xb3\n\
	bls _080F8C3C\n\
	bl clearStageDisk\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F8C74: .4byte gStageDiskManager\n\
_080F8C78: .4byte 0x01000008\n\
_080F8C7C: .4byte 0x05000004\n\
 .syntax divided\n");
}

void clearStageDisk(void) {
  u8 i;
  for (i = 0; i < 10; i++) {
    gStageDiskManager.stageDiskIDs[i] = 0xFF;
  }
  gStageDiskManager.stageDiskCount = 0;
}

void getDiskInStageRun(u8 disk_id) {
  u8* flagbits = gStageDiskManager.disk;
  UNLOCK_DISK(flagbits, disk_id);
  gStageDiskManager.stageDiskIDs[gStageDiskManager.stageDiskCount] = disk_id;
  gStageDiskManager.stageDiskCount++;
}

bool8 allSecretDiskFound(void) {
  u8 i;
  for (i = 0; i < DISK_COUNT; i++) {
    if ((IS_DISK_UNLOCKED(gStageDiskManager.disk, i) & 1) == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static void sd_analysis_080f85e0(struct GameState* g);
static void sd_analysis_080f875c(struct GameState* g);
static void sd_analysis_080f8984(struct GameState* g);

const DiskLoopFunc PTR_ARRAY_083864ac[3] = {
    sd_analysis_080f85e0,
    sd_analysis_080f875c,
    sd_analysis_080f8984,
};

const u16 DiskECrystalAmounts[16] = {
    80, 100, 200, 150, 40, 100, 100, 50, 80, 100, 100, 40, 500, 100, 100, 100,
};

const u8 u8_ARRAY_ARRAY_083864d8[DISK_COUNT][8] = {
    {0x1C, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x1E, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x1D, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x2B, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x26, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x2C, 0x0E, 0x0F, 0x0F, 0x00, 0x30, 0x30, 0x01}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00},
    {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x0A, 0xB0, 0x00, 0xF6, 0x00, 0x48, 0x48, 0x00}, {0x00, 0x91, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x95, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x95, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xBE, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xBE, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x00, 0x93, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x99, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x95, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x95, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x9B, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x9B, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0x9E, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA2, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA4, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA7, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA7, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x00, 0xA8, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA8, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xA9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xAA, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xAA, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xAD, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xAE, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB0, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB1, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB1, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB1, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB1, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x00, 0xB2, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB3, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB3, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB3, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB3, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB3, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB5, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB5, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB5, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB6, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB8, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB8, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB8, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},
    {0x00, 0xB9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x00, 0xB9, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00},
    {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x04, 0xAA, 0x00, 0xFA, 0x00, 0x24, 0x24, 0x00}, {0x00, 0xE1, 0x08, 0x04, 0x00, 0x78, 0x96, 0x00}, {0x06, 0xA7, 0xFD, 0xDF, 0x01, 0x58, 0x58, 0x00}, {0x1E, 0xA4, 0x05, 0xE9, 0x01, 0x50, 0x50, 0x00}, {0x00, 0xA2, 0x02, 0xEC, 0x01, 0x50, 0x50, 0x00}, {0x04, 0xA8, 0x02, 0xDB, 0x01, 0x58, 0x58, 0x00}, {0x00, 0x31, 0x00, 0x00, 0x00, 0x48, 0x48, 0x00}, {0x00, 0x31, 0x00, 0x00, 0x00, 0x48, 0x48, 0x00}, {0x01, 0xAF, 0x00, 0x00, 0x01, 0x38, 0x50, 0x00}, {0x10, 0xB5, 0x0F, 0xEE, 0x01, 0x52, 0x52, 0x00}, {0x01, 0xB4, 0x00, 0xDE, 0x01, 0x58, 0x58, 0x00}, {0x1E, 0xB3, 0x00, 0xEC, 0x01, 0x48, 0x48, 0x00}, {0x09, 0xAB, 0xFA, 0xD6, 0x01, 0x7E, 0x6C, 0x00}, {0x00, 0xB2, 0x00, 0xE3, 0x01, 0x52, 0x52, 0x00}, {0x02, 0xB0, 0x00, 0xE8, 0x01, 0x46, 0x4A, 0x00}, {0x00, 0xA5, 0x08, 0xE8, 0x01, 0x60, 0x50, 0x00}, {0x09, 0x13, 0xFE, 0xF1, 0x00, 0x40, 0x40, 0x00},
    {0x01, 0x14, 0xFF, 0xF1, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x27, 0x00, 0xEB, 0x00, 0x40, 0x40, 0x00}, {0x02, 0xD4, 0x00, 0xF3, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x6D, 0x0E, 0xDD, 0x00, 0x62, 0x5E, 0x00}, {0x02, 0x74, 0x00, 0xF0, 0x00, 0x40, 0x40, 0x00}, {0x0F, 0x17, 0x00, 0xFC, 0x00, 0x40, 0x40, 0x00}, {0x09, 0x07, 0x00, 0xF6, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x2F, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x08, 0x08, 0xFA, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x09, 0x38, 0x00, 0xFA, 0x00, 0x48, 0x48, 0x00}, {0x06, 0x68, 0xF9, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x07, 0x71, 0x00, 0xE6, 0x00, 0x66, 0x4A, 0x00}, {0x01, 0x66, 0xF2, 0x12, 0x00, 0x4E, 0x40, 0x00}, {0x03, 0x0D, 0x00, 0x06, 0x00, 0x40, 0x40, 0x00}, {0x06, 0x2E, 0x00, 0xF6, 0x00, 0x40, 0x40, 0x00}, {0x01, 0x75, 0x00, 0x11, 0x00, 0x40, 0x2E, 0x00}, {0x1D, 0x7E, 0x00, 0xF0, 0x00, 0x40, 0x40, 0x00}, {0x12, 0x8E, 0x01, 0xF6, 0x00, 0x40, 0x40, 0x00},
    {0x0C, 0x77, 0x01, 0xEE, 0x00, 0x40, 0x40, 0x00}, {0x0F, 0x19, 0x00, 0xF1, 0x00, 0x48, 0x48, 0x00}, {0x03, 0x1D, 0x03, 0xF8, 0x00, 0x40, 0x40, 0x00}, {0x01, 0xD5, 0x00, 0xEC, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x15, 0x00, 0xF9, 0x00, 0x40, 0x40, 0x00}, {0x0C, 0x28, 0x0B, 0xF0, 0x00, 0x40, 0x40, 0x00}, {0x03, 0x67, 0x02, 0x02, 0x00, 0x40, 0x40, 0x00}, {0x18, 0x43, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x01, 0x16, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x02, 0x2A, 0x00, 0xF7, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x6B, 0x00, 0xFA, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x06, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x03, 0x47, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x18, 0x03, 0x00, 0x00, 0x40, 0x40, 0x00}, {0x0B, 0x35, 0x01, 0xF6, 0x00, 0x40, 0x40, 0x00}, {0x00, 0x10, 0x00, 0xF2, 0x00, 0x40, 0x40, 0x00}, {0x00, 0xDB, 0x00, 0xF8, 0x00, 0x40, 0x40, 0x00},
    {0x03, 0xDC, 0x00, 0xF8, 0x00, 0x40, 0x40, 0x00}, {0x05, 0xC5, 0x00, 0xE0, 0x01, 0x46, 0x46, 0x00}, {0x0E, 0xC2, 0x00, 0xF2, 0x01, 0x38, 0x38, 0x00}, {0x03, 0xC2, 0x00, 0xEF, 0x00, 0x38, 0x38, 0x00}, {0x01, 0xC4, 0x00, 0xF3, 0x00, 0x38, 0x38, 0x00}, {0x01, 0xBB, 0x00, 0xF3, 0x00, 0x38, 0x38, 0x00}, {0x01, 0xC3, 0x00, 0xED, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xC0, 0x00, 0xEF, 0x00, 0x38, 0x38, 0x00}, {0x01, 0xC6, 0x00, 0xF5, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xBF, 0x00, 0xED, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xBE, 0x00, 0xEF, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xC1, 0x00, 0xEF, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xC5, 0x00, 0xF2, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xC7, 0x00, 0xF0, 0x00, 0x38, 0x38, 0x00}, {0x00, 0xBE, 0xFC, 0xD6, 0x01, 0x64, 0x64, 0x00}, {0x00, 0xA1, 0xE6, 0xD8, 0x01, 0x64, 0x64, 0x00}, {0x02, 0xBD, 0xF0, 0xF3, 0x01, 0x64, 0x64, 0x00}, {0x00, 0xBC, 0x00, 0xE0, 0x01, 0x64, 0x64, 0x00},
};

// clang-format off
static const DiskLoopFunc sDiskLoops[5] = {
    DiskLoop_Init, 
    DiskLoop_OpenScreen, 
    DiskLoop_Run, 
    DiskLoop_BlackOut, 
    DiskLoop_Exit,
};
// clang-format on
