#include "hud.h"

#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "story.h"

extern const struct Graphic gGraphic_085473D4;
extern const struct Palette gPalette_085473D4;

extern const struct Graphic gGraphic_HPGauge;
extern const struct Palette gPalette_HPGauge;

static void drawZeroHPWeaponIcon(void* p);
static void FUN_080ea3c8(void* p);
static void drawLeftTime(struct HUD* p);

void ResetHUD(void* p) {
  gHUD.bg0 = p;
  gHUD.unk_02 = 0;
  gHUD.z = NULL;
  gHUD.unk_0c = NULL;
  gHUD.timeLeft = 0;
}

void DrawStatus(void) {
  gWindowRegBuffer.unk_0c[2] |= 1;
  if (gHUD.unk_02 == 0) {
    if (!FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
      LoadGraphic(&gGraphic_085473D4, (void*)CHAR_BASE(0));
      LoadPalette(&gPalette_085473D4, 0);
      LoadGraphic(&gGraphic_HPGauge, (void*)CHAR_BASE(0));
      LoadPalette(&gPalette_HPGauge, 0);
    } else {
      LoadGraphic(&gGraphic_TitleLogo, (void*)CHAR_BASE(0));
      LoadPalette(&gPalette_TitleLogo, 0);
    }
    gHUD.unk_02 = 1;
  }

  if (!FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    drawZeroHPWeaponIcon(&gHUD.bg0);
    FUN_080ea3c8(&gHUD.bg0);
  } else {
    gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
    if (gHUD.unk_02 < 32) {
      gHUD.unk_02++;
    }
    gVideoRegBuffer.bgofs[0][1] = 32 - gHUD.unk_02;
    loadBgMap_08004248((s32)gHUD.bg0, (s32*)&gBgMapOffsets[0], 18, 0, 0);
  }
}

void DrawLeftTime(void) {
  if (gHUD.timeLeft != 0) {
    gWindowRegBuffer.unk_0c[2] |= 1;
    drawLeftTime(&gHUD);
  }
}

NAKED static void drawZeroHPWeaponIcon(void* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4]\n\
	ldr r3, [r4, #8]\n\
	cmp r3, #0\n\
	bne _080EA1EE\n\
	b _080EA3B2\n\
_080EA1EE:\n\
	ldr r2, _080EA274 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r6, #0x80\n\
	lsls r6, r6, #1\n\
	adds r0, r6, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0xa4\n\
	ldrh r7, [r0]\n\
	adds r0, r3, #0\n\
	bl getMaxHP1x\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov ip, r0\n\
	ldr r0, [r4, #8]\n\
	adds r0, #0xb4\n\
	ldrb r3, [r0, #0xc]\n\
	ldrb r4, [r0, #0xd]\n\
	ldrb r1, [r0, #0xe]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	lsls r2, r0, #0x10\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #3\n\
	movs r0, #2\n\
	ands r1, r0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r1, r0, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #4\n\
	adds r6, r2, r0\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldr r0, _080EA278 @ =0x120C120B\n\
	str r0, [r1]\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	ldr r0, _080EA27C @ =0x122C122B\n\
	str r0, [r1]\n\
	adds r1, r3, #0\n\
	cmp r1, r4\n\
	bne _080EA288\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #2\n\
	adds r2, r5, r3\n\
	lsls r1, r4, #0x10\n\
	adds r1, r1, r4\n\
	lsls r1, r1, #1\n\
	ldr r3, _080EA280 @ =0x120E120D\n\
	adds r0, r6, r3\n\
	adds r0, r1, r0\n\
	str r0, [r2]\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #2\n\
	adds r2, r5, r0\n\
	ldr r3, _080EA284 @ =0x122E122D\n\
	adds r0, r6, r3\n\
	adds r1, r1, r0\n\
	str r1, [r2]\n\
	b _080EA2CC\n\
	.align 2, 0\n\
_080EA274: .4byte gVideoRegBuffer\n\
_080EA278: .4byte 0x120C120B\n\
_080EA27C: .4byte 0x122C122B\n\
_080EA280: .4byte 0x120E120D\n\
_080EA284: .4byte 0x122E122D\n\
_080EA288:\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #2\n\
	adds r3, r5, r0\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	ldr r1, _080EA308 @ =0x120E120D\n\
	adds r2, r6, r1\n\
	adds r1, r0, r2\n\
	str r1, [r3]\n\
	movs r3, #0xd0\n\
	lsls r3, r3, #2\n\
	adds r3, r3, r5\n\
	mov r8, r3\n\
	ldr r3, _080EA30C @ =0x124E124D\n\
	adds r1, r6, r3\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #2\n\
	adds r1, r5, r3\n\
	lsls r0, r4, #0x10\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	adds r2, r0, r2\n\
	str r2, [r1]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #2\n\
	adds r2, r5, r1\n\
	ldr r3, _080EA310 @ =0x122E122D\n\
	adds r1, r6, r3\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
_080EA2CC:\n\
	movs r6, #0x90\n\
	lsls r6, r6, #2\n\
	adds r5, r5, r6\n\
	lsls r0, r7, #0x10\n\
	asrs r0, r0, #0x10\n\
	mov r4, ip\n\
	cmp r0, r4\n\
	bgt _080EA336\n\
	movs r2, #0\n\
	ldr r1, _080EA314 @ =gMission\n\
	mov r8, r1\n\
	cmp r2, r4\n\
	bge _080EA38C\n\
	adds r3, r0, #0\n\
	ldr r7, _080EA318 @ =0x12A112A0\n\
	movs r1, #3\n\
	ands r1, r3\n\
	ldr r6, _080EA31C @ =0x12211220\n\
	mov ip, r6\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	subs r6, r7, r0\n\
	adds r1, r4, #0\n\
_080EA2FC:\n\
	adds r0, r2, #4\n\
	cmp r0, r3\n\
	bgt _080EA320\n\
	mov r2, ip\n\
	str r2, [r5]\n\
	b _080EA32A\n\
	.align 2, 0\n\
_080EA308: .4byte 0x120E120D\n\
_080EA30C: .4byte 0x124E124D\n\
_080EA310: .4byte 0x122E122D\n\
_080EA314: .4byte gMission\n\
_080EA318: .4byte 0x12A112A0\n\
_080EA31C: .4byte 0x12211220\n\
_080EA320:\n\
	cmp r2, r3\n\
	ble _080EA328\n\
	str r7, [r5]\n\
	b _080EA32A\n\
_080EA328:\n\
	str r6, [r5]\n\
_080EA32A:\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	subs r5, #0x40\n\
	cmp r2, r1\n\
	blt _080EA2FC\n\
	b _080EA38C\n\
_080EA336:\n\
	subs r0, r0, r4\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	movs r2, #0\n\
	ldr r3, _080EA36C @ =gMission\n\
	mov r8, r3\n\
	cmp r2, r4\n\
	bge _080EA38C\n\
	lsls r0, r7, #0x10\n\
	asrs r3, r0, #0x10\n\
	ldr r7, _080EA370 @ =0x12A312A2\n\
	movs r1, #3\n\
	ands r1, r3\n\
	ldr r6, _080EA374 @ =0x12231222\n\
	mov ip, r6\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	subs r6, r7, r0\n\
	adds r1, r4, #0\n\
_080EA35E:\n\
	adds r0, r2, #4\n\
	cmp r0, r3\n\
	bgt _080EA378\n\
	mov r2, ip\n\
	str r2, [r5]\n\
	b _080EA382\n\
	.align 2, 0\n\
_080EA36C: .4byte gMission\n\
_080EA370: .4byte 0x12A312A2\n\
_080EA374: .4byte 0x12231222\n\
_080EA378:\n\
	cmp r2, r3\n\
	ble _080EA380\n\
	str r7, [r5]\n\
	b _080EA382\n\
_080EA380:\n\
	str r6, [r5]\n\
_080EA382:\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	subs r5, #0x40\n\
	cmp r2, r1\n\
	blt _080EA35E\n\
_080EA38C:\n\
	ldr r0, _080EA3BC @ =0x12011200\n\
	str r0, [r5]\n\
	ldr r3, _080EA3C0 @ =0x0000122A\n\
	adds r0, r3, #0\n\
	strh r0, [r5, #4]\n\
	adds r2, r5, #0\n\
	adds r2, #0x44\n\
	mov r6, r8\n\
	ldr r1, [r6]\n\
	subs r3, #0x26\n\
	adds r0, r3, #0\n\
	ldrb r1, [r1, #1]\n\
	adds r0, r0, r1\n\
	strh r0, [r2]\n\
	adds r1, r5, #0\n\
	adds r1, #0x84\n\
	ldr r6, _080EA3C4 @ =0x0000124A\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
_080EA3B2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EA3BC: .4byte 0x12011200\n\
_080EA3C0: .4byte 0x0000122A\n\
_080EA3C4: .4byte 0x0000124A\n\
 .syntax divided\n");
}

NAKED static void FUN_080ea3c8(void* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r3, [r0]\n\
	ldr r4, [r0, #0xc]\n\
	cmp r4, #0\n\
	bne _080EA3D4\n\
	b _080EA4E4\n\
_080EA3D4:\n\
	ldr r2, _080EA42C @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #1\n\
	adds r0, r5, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	ldrh r4, [r0]\n\
	movs r0, #0xae\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldr r0, _080EA430 @ =0x124C124B\n\
	str r0, [r1]\n\
	movs r5, #0xbe\n\
	lsls r5, r5, #2\n\
	adds r1, r3, r5\n\
	ldr r0, _080EA434 @ =0x126C126B\n\
	str r0, [r1]\n\
	movs r0, #0x9e\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x20\n\
	bgt _080EA456\n\
	movs r3, #0\n\
	adds r4, r0, #0\n\
	ldr r5, _080EA438 @ =0x12A512A4\n\
	movs r1, #3\n\
	ands r1, r4\n\
	ldr r7, _080EA43C @ =0x12251224\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	subs r1, r5, r0\n\
	movs r6, #0x20\n\
_080EA420:\n\
	adds r0, r3, #4\n\
	cmp r0, r4\n\
	bgt _080EA440\n\
	str r7, [r2]\n\
	b _080EA44A\n\
	.align 2, 0\n\
_080EA42C: .4byte gVideoRegBuffer\n\
_080EA430: .4byte 0x124C124B\n\
_080EA434: .4byte 0x126C126B\n\
_080EA438: .4byte 0x12A512A4\n\
_080EA43C: .4byte 0x12251224\n\
_080EA440:\n\
	cmp r3, r4\n\
	ble _080EA448\n\
	str r5, [r2]\n\
	b _080EA44A\n\
_080EA448:\n\
	str r1, [r2]\n\
_080EA44A:\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	subs r2, #0x40\n\
	cmp r3, r6\n\
	blt _080EA420\n\
	b _080EA4E0\n\
_080EA456:\n\
	cmp r0, #0x40\n\
	bgt _080EA49E\n\
	subs r0, #0x20\n\
	movs r3, #0\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x10\n\
	ldr r5, _080EA480 @ =0x12A712A6\n\
	movs r1, #3\n\
	ands r1, r4\n\
	ldr r7, _080EA484 @ =0x12271226\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	subs r1, r5, r0\n\
	movs r6, #0x20\n\
_080EA474:\n\
	adds r0, r3, #4\n\
	cmp r0, r4\n\
	bgt _080EA488\n\
	str r7, [r2]\n\
	b _080EA492\n\
	.align 2, 0\n\
_080EA480: .4byte 0x12A712A6\n\
_080EA484: .4byte 0x12271226\n\
_080EA488:\n\
	cmp r3, r4\n\
	ble _080EA490\n\
	str r5, [r2]\n\
	b _080EA492\n\
_080EA490:\n\
	str r1, [r2]\n\
_080EA492:\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	subs r2, #0x40\n\
	cmp r3, r6\n\
	blt _080EA474\n\
	b _080EA4E0\n\
_080EA49E:\n\
	subs r0, #0x40\n\
	movs r3, #0\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x10\n\
	ldr r5, _080EA4C4 @ =0x12A912A8\n\
	movs r1, #3\n\
	ands r1, r4\n\
	ldr r7, _080EA4C8 @ =0x12291228\n\
	lsls r0, r1, #0x10\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #5\n\
	subs r1, r5, r0\n\
	movs r6, #0x20\n\
_080EA4B8:\n\
	adds r0, r3, #4\n\
	cmp r0, r4\n\
	bgt _080EA4CC\n\
	str r7, [r2]\n\
	b _080EA4D6\n\
	.align 2, 0\n\
_080EA4C4: .4byte 0x12A912A8\n\
_080EA4C8: .4byte 0x12291228\n\
_080EA4CC:\n\
	cmp r3, r4\n\
	ble _080EA4D4\n\
	str r5, [r2]\n\
	b _080EA4D6\n\
_080EA4D4:\n\
	str r1, [r2]\n\
_080EA4D6:\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	subs r2, #0x40\n\
	cmp r3, r6\n\
	blt _080EA4B8\n\
_080EA4E0:\n\
	ldr r0, _080EA4EC @ =0x12031202\n\
	str r0, [r2]\n\
_080EA4E4:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EA4EC: .4byte 0x12031202\n\
 .syntax divided\n");
}

NAKED static void drawLeftTime(struct HUD* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	ldr r7, [r0]\n\
	ldr r3, _080EA5EC @ =gVideoRegBuffer\n\
	ldrh r2, [r3]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r1, r4, #0\n\
	orrs r1, r2\n\
	strh r1, [r3]\n\
	ldr r0, [r0, #0x10]\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	movs r1, #0x96\n\
	lsls r1, r1, #2\n\
	bl __divsi3\n\
	adds r2, r7, #0\n\
	adds r2, #0x68\n\
	lsls r0, r0, #1\n\
	movs r1, #0x9c\n\
	lsls r1, r1, #5\n\
	adds r6, r1, #0\n\
	adds r1, r0, r6\n\
	strh r1, [r2]\n\
	adds r2, #2\n\
	ldr r4, _080EA5F0 @ =0x00001381\n\
	adds r5, r4, #0\n\
	adds r1, r0, r5\n\
	strh r1, [r2]\n\
	adds r2, #0x3e\n\
	ldr r1, _080EA5F4 @ =0x00001395\n\
	adds r4, r1, #0\n\
	adds r1, r0, r4\n\
	strh r1, [r2]\n\
	adds r1, r7, #0\n\
	adds r1, #0xaa\n\
	ldr r2, _080EA5F8 @ =0x00001396\n\
	mov sb, r2\n\
	add r0, sb\n\
	strh r0, [r1]\n\
	mov r0, r8\n\
	movs r1, #0x3c\n\
	bl __divsi3\n\
	movs r1, #0xa\n\
	bl __modsi3\n\
	adds r2, r7, #0\n\
	adds r2, #0x6c\n\
	lsls r0, r0, #1\n\
	adds r1, r0, r6\n\
	strh r1, [r2]\n\
	adds r2, #2\n\
	adds r1, r0, r5\n\
	strh r1, [r2]\n\
	adds r2, #0x3e\n\
	adds r1, r0, r4\n\
	strh r1, [r2]\n\
	adds r1, r7, #0\n\
	adds r1, #0xae\n\
	add r0, sb\n\
	strh r0, [r1]\n\
	subs r1, #0x3e\n\
	ldr r2, _080EA5FC @ =0x00001394\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x40\n\
	adds r2, #0x15\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	mov r0, r8\n\
	movs r1, #0x3c\n\
	bl __modsi3\n\
	mov r8, r0\n\
	movs r1, #6\n\
	bl __divsi3\n\
	adds r2, r7, #0\n\
	adds r2, #0x72\n\
	lsls r0, r0, #1\n\
	adds r1, r0, r6\n\
	strh r1, [r2]\n\
	adds r2, #2\n\
	adds r1, r0, r5\n\
	strh r1, [r2]\n\
	adds r2, #0x3e\n\
	adds r1, r0, r4\n\
	strh r1, [r2]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	add r0, sb\n\
	strh r0, [r1]\n\
	movs r0, #0x64\n\
	mov r1, r8\n\
	muls r1, r0, r1\n\
	adds r0, r1, #0\n\
	movs r1, #0x3c\n\
	bl __divsi3\n\
	movs r1, #0xa\n\
	bl __modsi3\n\
	adds r1, r7, #0\n\
	adds r1, #0x76\n\
	lsls r0, r0, #1\n\
	adds r6, r0, r6\n\
	strh r6, [r1]\n\
	adds r1, #2\n\
	adds r5, r0, r5\n\
	strh r5, [r1]\n\
	adds r1, #0x3e\n\
	adds r4, r0, r4\n\
	strh r4, [r1]\n\
	adds r1, #2\n\
	add r0, sb\n\
	strh r0, [r1]\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EA5EC: .4byte gVideoRegBuffer\n\
_080EA5F0: .4byte 0x00001381\n\
_080EA5F4: .4byte 0x00001395\n\
_080EA5F8: .4byte 0x00001396\n\
_080EA5FC: .4byte 0x00001394\n\
 .syntax divided\n");
}
