#include "system.h"

#include "blink.h"
#include "game.h"
#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "input.h"
#include "intro.h"
#include "sound.h"
#include "sram.h"
#include "syssav.h"
#include "text.h"

static void VBlankIntr(void);
static void HBlankIntrDummy(void);
static void VCountIntr(void);
static void runDMA0(void);
static void transferByHand(void);
void Timer3Intr(void);
void SerialCB(void);

static void InterruptSystemProcess(struct Process* p, bool32 b);
static void transferData(void);

// 0x080fec74
static const VoidFunc gIntrTableTemplate[14] = {
    VBlankIntr, HBlankIntrDummy, VCountIntr, HBlankIntrDummy, HBlankIntrDummy, HBlankIntrDummy, Timer3Intr, SerialCB, HBlankIntrDummy, HBlankIntrDummy, HBlankIntrDummy, HBlankIntrDummy, HBlankIntrDummy, HBlankIntrDummy,
};

WIP void Process_SoftReset(struct Process* _ UNUSED) {
#if MODERN
  gIntrManager.slowGameRatio = 1;
  ResetVideoRegister();
  MaskBg0(gGameState.bg0, SCREEN_BASE(0), 1408, 0x3C0);
  gJoypad[0].field6_0x14 = 24;
  gJoypad[0].field7_0x15 = 4;
  gJoypad[1].field6_0x14 = 24;
  gJoypad[1].field7_0x15 = 4;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0x00;
  PALETTE16(0) = RGB_BLACK;
  StopAllMusics();
  text_080e9730();
  LoadKatakanaBold();
  gVideoRegBuffer.dispcnt &= BG_MODE_0;
  gVideoRegBuffer.dispcnt &= ~DISPCNT_BG_ALL_ON;
  gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  *(u32*)gVideoRegBuffer.bgofs[0] = 0;
  if (gIntro.mode[0] == 0) {
    PALETTE16(0) = RGB_WHITE;
  }
  SwitchProcess(TRUE);
  exec(Process_Intro);
#else
  INCCODE("asm/wip/Process_SoftReset.inc");
#endif
}

WIP NORETURN void Process_System(struct Process* p) {
#if MODERN
  while (TRUE) {
    PrintAllStrings();
    ExecBlink();
    gSystemBuffer.idx = (gSystemBuffer.idx == 0);
    gSystemBuffer.ofs = 0;
    UpdateSram();
    do {
      do {
      } while (gIntrManager.frame2 < gIntrManager.slowGameRatio);
    } while (REG_VCOUNT != 161);
    gIntrManager.frame2 = 0;
    PollKeyInput();
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    FlashVideoRegister();
    FlashOAM();
    FlashBlendRegister();
    FlashWinRegister();
    FlashMOSAIC();
    transferData();
    FUN_080e98ec();
    flashPalette_08003b24();
    doGraphicTransferTasks();
    if (gSramState.unk_00 == 0) {
      if (gGameState.unk_00c != 0) {
        if (((gJoypad[0].input & (SELECT_BUTTON | START_BUTTON)) == (SELECT_BUTTON | START_BUTTON)) && (gJoypad[0].input & A_BUTTON) && (gJoypad[0].input & B_BUTTON)) {
          if ((gJoypad[0].pressed & (SELECT_BUTTON | START_BUTTON)) || (gJoypad[0].pressed & A_BUTTON) || (gJoypad[0].pressed & B_BUTTON)) {
            disableProcess(0);
            disableProcess(1);
            SetIntroMode(&gIntro, 1);
            ResetProcess(0, Process_SoftReset);
          }
        }
      }
    }
    InterruptSystemProcess(p, 1);
  }
#else
  INCCODE("asm/wip/Process_System.inc");
#endif
}

void usrHBlankCallback(void) {
  _usrHBlankCallback();
  return;
}

void usrVBlankCallback(void) {
  LinkVSync();
  FUN_080044a0();
}

// 0x0300_0000 ~ 0x0300_7e00 までを0クリア
void ClearMemory(void) {
  REG_WAITCNT = 0x45B7;
#if MODERN
  // TODO: ClearMemory
  // スタックに戻り先を入れているがIWRAMがゼロクリアされるので戻り先も0クリアされクラッシュする
#else
  DmaFill32(3, 0, (void*)IWRAM, 0x7E00);
#endif
  DmaFill32(3, 0, (void*)EWRAM, 0x40000);
  gSystemBuffer.idx = 0;
  gSystemBuffer.ofs = 0;
}

void* Malloc(u32 byteSize) {
  void* d = (void*)&gSystemBuffer.buf[gSystemBuffer.idx][gSystemBuffer.ofs];

  const u32 actual = (576 - gSystemBuffer.ofs);
  const u32 wordsize = (byteSize + 3) / 4;
  if (actual >= wordsize) {
    gSystemBuffer.ofs += wordsize;
    return d;
  }
  return NULL;
}

NAKED void FillMemory(u16 fillval, u16* dst, u32 bytesize) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r6, r1, #0\n\
	adds r5, r2, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r7, r1, #0\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r5, r0\n\
	cmp r5, #0\n\
	beq _08001BC6\n\
	ands r6, r0\n\
	movs r0, #2\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _08001B84\n\
	strh r1, [r6]\n\
	subs r5, #2\n\
	cmp r5, #0\n\
	beq _08001BC6\n\
	adds r6, #2\n\
_08001B84:\n\
	cmp r5, #0x20\n\
	bls _08001BB2\n\
	lsls r0, r1, #0x10\n\
	orrs r0, r1\n\
	str r0, [sp]\n\
	movs r4, #0x20\n\
	rsbs r4, r4, #0\n\
	ands r4, r5\n\
	lsrs r2, r4, #2\n\
	ldr r0, _08001BD0 @ =0x001FFFFF\n\
	ands r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	orrs r2, r0\n\
	mov r0, sp\n\
	adds r1, r6, #0\n\
	bl CpuFastSet\n\
	adds r6, r6, r4\n\
	movs r0, #0x1f\n\
	ands r5, r0\n\
	cmp r5, #0\n\
	beq _08001BC6\n\
_08001BB2:\n\
	add r0, sp, #4\n\
	strh r7, [r0]\n\
	lsls r2, r5, #0xa\n\
	lsrs r2, r2, #0xb\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	orrs r2, r1\n\
	adds r1, r6, #0\n\
	bl CpuSet\n\
_08001BC6:\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08001BD0: .4byte 0x001FFFFF\n\
 .syntax divided\n");
}

NAKED void Transfer30Bytes(void* src, void* dst, u32 bytesize) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	adds r6, r1, #0\n\
	adds r4, r2, #0\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	beq _08001C42\n\
	ands r5, r0\n\
	ands r6, r0\n\
	movs r1, #2\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08001BFC\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08001C0A\n\
_08001BFC:\n\
	lsls r2, r4, #0xa\n\
	lsrs r2, r2, #0xb\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl CpuSet\n\
	b _08001C42\n\
_08001C0A:\n\
	cmp r4, #0x1f\n\
	bls _08001C2A\n\
	movs r2, #0x20\n\
	rsbs r2, r2, #0\n\
	ands r2, r4\n\
	lsrs r2, r2, #2\n\
	ldr r0, _08001C48 @ =0x001FFFFF\n\
	ands r2, r0\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl CpuFastSet\n\
	movs r0, #0x1f\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08001C42\n\
_08001C2A:\n\
	movs r0, #0x20\n\
	rsbs r0, r0, #0\n\
	ands r0, r4\n\
	adds r5, r5, r0\n\
	adds r6, r6, r0\n\
	movs r2, #0x1f\n\
	ands r2, r4\n\
	lsrs r2, r2, #1\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl CpuSet\n\
_08001C42:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08001C48: .4byte 0x001FFFFF\n\
 .syntax divided\n");
}

NAKED void InitIntrHandlers(void) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	ldr r4, _08001D00 @ =IntrMain\n\
	ldr r0, _08001D04 @ =gIntrManager+56\n\
	mov ip, r0\n\
	ldr r3, _08001D08 @ =0x080FEC74\n\
	mov r2, ip\n\
	subs r2, #0x38\n\
	movs r1, #0xd\n\
_08001C5C:\n\
	ldm r3!, {r0}\n\
	stm r2!, {r0}\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bge _08001C5C\n\
	ldr r0, _08001D0C @ =0x040000D4\n\
	str r4, [r0]\n\
	mov r1, ip\n\
	str r1, [r0, #4]\n\
	ldr r1, _08001D10 @ =0x84000048\n\
	str r1, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	ldr r0, _08001D14 @ =0x03007FFC\n\
	mov r4, ip\n\
	str r4, [r0]\n\
	movs r0, #0x90\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	str r1, [r0]\n\
	movs r0, #0x97\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	strb r1, [r0]\n\
	ldr r0, _08001D18 @ =0x04000208\n\
	movs r3, #1\n\
	strh r3, [r0]\n\
	ldr r2, _08001D1C @ =0x04000200\n\
	ldr r4, _08001D20 @ =0x00002005\n\
	adds r0, r4, #0\n\
	strh r0, [r2]\n\
	ldr r2, _08001D24 @ =0x04000004\n\
	movs r0, #0x28\n\
	strh r0, [r2]\n\
	ldr r2, _08001D28 @ =0x0000012D\n\
	add r2, ip\n\
	ldrb r0, [r2]\n\
	strb r3, [r2]\n\
	movs r0, #0x96\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	ldrb r2, [r0]\n\
	strb r1, [r0]\n\
	movs r0, #0x94\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	str r1, [r0]\n\
	ldr r0, _08001D2C @ =0x0000012F\n\
	add r0, ip\n\
	strb r1, [r0]\n\
	movs r2, #0x9c\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	movs r0, #0xa2\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	str r1, [r0]\n\
	str r1, [r2]\n\
	movs r2, #0xa8\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	movs r0, #0xb0\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	str r1, [r0]\n\
	str r1, [r2]\n\
	movs r2, #0xba\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	movs r0, #0xc2\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	str r1, [r0]\n\
	str r1, [r2]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08001D00: .4byte IntrMain\n\
_08001D04: .4byte gIntrManager+56\n\
_08001D08: .4byte gIntrTableTemplate\n\
_08001D0C: .4byte 0x040000D4\n\
_08001D10: .4byte 0x84000048\n\
_08001D14: .4byte 0x03007FFC\n\
_08001D18: .4byte 0x04000208\n\
_08001D1C: .4byte 0x04000200\n\
_08001D20: .4byte 0x00002005\n\
_08001D24: .4byte 0x04000004\n\
_08001D28: .4byte 0x0000012D\n\
_08001D2C: .4byte 0x0000012F\n\
 .syntax divided\n");
}

static void unused_08001d30(void) {
  REG_IME = 1;
  return;
}

// 毎フレーム、転送予約されたデータを転送する
NAKED static void transferData(void) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	ldr r4, _08001D6C @ =gIntrManager+384\n\
	subs r2, r4, #4\n\
	ldr r3, [r2]\n\
	cmp r3, #0\n\
	beq _08001D70\n\
	adds r1, r4, #0\n\
	subs r1, #0x18\n\
	adds r0, r4, #0\n\
	subs r0, #0xc\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	adds r0, r4, #0\n\
	subs r0, #8\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r2]\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	str r0, [r2]\n\
	b _08001D94\n\
	.align 2, 0\n\
_08001D6C: .4byte gIntrManager+384\n\
_08001D70:\n\
	ldr r0, [r4, #0x18]\n\
	cmp r0, #0\n\
	beq _08001D8E\n\
	adds r1, r4, #0\n\
	subs r1, #0x18\n\
	ldr r0, [r4, #0x10]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r4, #0x14]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r1]\n\
	str r3, [r4, #0x18]\n\
	b _08001D94\n\
_08001D8E:\n\
	adds r1, r4, #0\n\
	subs r1, #0x10\n\
	str r0, [r1]\n\
_08001D94:\n\
	bl runDMA0\n\
	ldr r0, [r4, #0x10]\n\
	str r0, [r4]\n\
	ldr r0, [r4, #0x14]\n\
	str r0, [r4, #4]\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #8]\n\
	movs r1, #0\n\
	str r1, [r4, #0x18]\n\
	adds r4, #0x24\n\
	ldr r0, [r4, #0x10]\n\
	str r0, [r4]\n\
	ldr r0, [r4, #0x14]\n\
	str r0, [r4, #4]\n\
	ldr r0, [r4, #0x18]\n\
	str r0, [r4, #8]\n\
	str r1, [r4, #0x18]\n\
	bl transferByHand\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void HBlankIntrDummy(void) { return; }

// 頻繁に呼び出される関数なので gIntrManager にコピーされる
static void VBlankIntr(void) {
  if ((gIntrManager.intrLock & INTR_FLAG_VBLANK) == 0) {
    gIntrManager.intrLock |= INTR_FLAG_VBLANK;
    INTR_CHECK = 1;
    gIntrManager.frame2++;
    if (gIntrManager.vblankCallback != NULL) {
      gIntrManager.vblankCallback();
    }
    runDMA0();
    transferByHand();
    gIntrManager.intrLock ^= INTR_FLAG_VBLANK;
  }
}

static void VCountIntr(void) {
  vu16 y = REG_VCOUNT;
  if ((gIntrManager.intrLock & INTR_FLAG_HBLANK) == 0) {
    gIntrManager.intrLock |= INTR_FLAG_HBLANK;
    if (y == 0) {
      gIntrManager.frame++;
    }
    if ((y == gIntrManager.lyc) && (gIntrManager.hblankCallback != NULL)) {
      gIntrManager.hblankCallback();
    }
    if (y < gIntrManager.lyc) {
      REG_DISPSTAT_H = gIntrManager.lyc;
    } else {
      REG_DISPSTAT_H = 0;
    }
    gIntrManager.intrLock ^= INTR_FLAG_HBLANK;
  }
}

NAKED static void runDMA0(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r2, _08001F10 @ =0x040000B8\n\
	movs r0, #0\n\
	str r0, [r2]\n\
	ldr r1, _08001F14 @ =gIntrManager\n\
	movs r3, #0xb8\n\
	lsls r3, r3, #1\n\
	adds r0, r1, r3\n\
	ldr r3, [r0]\n\
	cmp r3, #0\n\
	beq _08001F74\n\
	movs r4, #0xb4\n\
	lsls r4, r4, #1\n\
	adds r0, r1, r4\n\
	ldr r5, [r0]\n\
	adds r4, #4\n\
	adds r0, r1, r4\n\
	ldr r4, [r0]\n\
	ldr r0, _08001F18 @ =0x040000B0\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	str r4, [r0]\n\
	ldr r0, _08001F1C @ =0xCDFFFFFF\n\
	ands r0, r3\n\
	str r0, [r2]\n\
	ldr r0, [r2]\n\
	ldr r2, _08001F20 @ =0x0000FFFF\n\
	ands r2, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08001F24\n\
	lsls r2, r2, #2\n\
	b _08001F26\n\
	.align 2, 0\n\
_08001F10: .4byte 0x040000B8\n\
_08001F14: .4byte gIntrManager\n\
_08001F18: .4byte 0x040000B0\n\
_08001F1C: .4byte 0xCDFFFFFF\n\
_08001F20: .4byte 0x0000FFFF\n\
_08001F24:\n\
	lsls r2, r2, #1\n\
_08001F26:\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0xf\n\
	ands r1, r3\n\
	cmp r1, #0\n\
	bne _08001F32\n\
	adds r4, r4, r2\n\
_08001F32:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xe\n\
	cmp r1, r0\n\
	bne _08001F3C\n\
	subs r4, r4, r2\n\
_08001F3C:\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x11\n\
	ands r1, r3\n\
	cmp r1, #0\n\
	bne _08001F48\n\
	adds r5, r5, r2\n\
_08001F48:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x10\n\
	cmp r1, r0\n\
	bne _08001F52\n\
	subs r5, r5, r2\n\
_08001F52:\n\
	ldr r2, _08001F7C @ =0x040000B0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x18\n\
	cmp r0, #0\n\
	bge _08001F66\n\
_08001F5E:\n\
	ldr r0, [r2]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08001F5E\n\
_08001F66:\n\
	ldr r0, _08001F7C @ =0x040000B0\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	str r4, [r0]\n\
	adds r0, #4\n\
	str r3, [r0]\n\
	ldr r0, [r0]\n\
_08001F74:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08001F7C: .4byte 0x040000B0\n\
 .syntax divided\n");
}

// 転送予約されたデータを(DMAを使わずに)手動で転送する
NAKED static void transferByHand(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _08001FA0 @ =gIntrManager+384\n\
	ldr r1, [r4, #8]\n\
	cmp r1, #0\n\
	beq _08001FC0\n\
	ldr r0, [r4]\n\
	str r0, [r4, #0xc]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08001FA4\n\
	strh r5, [r4, #0x1c]\n\
	b _08001FA8\n\
	.align 2, 0\n\
_08001FA0: .4byte gIntrManager+384\n\
_08001FA4:\n\
	movs r0, #1\n\
	strh r0, [r4, #0x1c]\n\
_08001FA8:\n\
	movs r0, #1\n\
	strh r0, [r4, #0x1e]\n\
	ldr r0, [r4, #8]\n\
	strh r0, [r4, #0x20]\n\
	adds r0, r4, #0\n\
	bl _transferByHand\n\
	lsls r0, r5, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r0, r1\n\
	lsrs r5, r0, #0x10\n\
_08001FC0:\n\
	adds r4, #0x24\n\
	ldr r1, [r4, #8]\n\
	cmp r1, #0\n\
	beq _08001FF6\n\
	ldr r0, [r4]\n\
	str r0, [r4, #0xc]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08001FDA\n\
	movs r0, #0\n\
	b _08001FDC\n\
_08001FDA:\n\
	movs r0, #1\n\
_08001FDC:\n\
	strh r0, [r4, #0x1c]\n\
	movs r0, #1\n\
	strh r0, [r4, #0x1e]\n\
	ldr r0, [r4, #8]\n\
	strh r0, [r4, #0x20]\n\
	adds r0, r4, #0\n\
	bl _transferByHand\n\
	lsls r0, r5, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	lsrs r5, r0, #0x10\n\
_08001FF6:\n\
	lsls r0, r5, #0x10\n\
	asrs r3, r0, #0x10\n\
	cmp r3, #0\n\
	beq _08002022\n\
	ldr r2, _08002028 @ =0x04000004\n\
	ldrh r0, [r2]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrh r0, [r2]\n\
	ldr r2, _0800202C @ =gIntrManager\n\
	ldr r1, _08002030 @ =0x08338C90\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r2, #4]\n\
	ldr r2, _08002034 @ =0x04000200\n\
	ldrh r0, [r2]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrh r0, [r2]\n\
_08002022:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08002028: .4byte 0x04000004\n\
_0800202C: .4byte gIntrManager\n\
_08002030: .4byte HBlankIntrs\n\
_08002034: .4byte 0x04000200\n\
 .syntax divided\n");
}

// HBlankIntr2との違いは SlowTR の代わりに FastTR を転送することのみ
void HBlankIntr1(void) {
  vu16 y = REG_VCOUNT;
  if ((y <= DISPLAY_HEIGHT) && (_transferByHand(&gIntrManager.tr[0]), y == DISPLAY_HEIGHT)) {
    REG_DISPSTAT &= ~DISPSTAT_HBLANK_INTR;
    REG_DISPSTAT;

    gIntrManager.table[1] = HBlankIntrDummy;

    REG_IE &= ~INTR_FLAG_HBLANK;
    REG_IE;
  }
}

// HBlankIntr1 との違いは FastTR の代わりに SlowTR を転送することのみ
void HBlankIntr2(void) {
  vu16 y = REG_VCOUNT;
  if ((y <= DISPLAY_HEIGHT) && (_transferByHand(&gIntrManager.tr[1]), y == DISPLAY_HEIGHT)) {
    REG_DISPSTAT &= ~DISPSTAT_HBLANK_INTR;
    REG_DISPSTAT;

    gIntrManager.table[1] = HBlankIntrDummy;

    REG_IE &= ~INTR_FLAG_HBLANK;
    REG_IE;
  }
}

void FUN_08002110(void) {
  vu16 y = REG_VCOUNT;
  if (y <= DISPLAY_HEIGHT) {
    struct TransferReservation* t = &gIntrManager.tr[0];
    _transferByHand(t);
    t = &gIntrManager.tr[1];
    _transferByHand(t);

    if (y == DISPLAY_HEIGHT) {
      REG_DISPSTAT &= ~DISPSTAT_HBLANK_INTR;
      REG_DISPSTAT;
      gIntrManager.table[1] = HBlankIntrDummy;
      REG_IE &= ~INTR_FLAG_HBLANK;
      REG_IE;
    }
  }
}

void _transferByHand(struct TransferReservation* t) {
  u16 i;
  u16* src = t->src;
  u16* dst = t->dst;
  for (i = t->remaining; i > 0; i--) {
    *dst = *src;
    dst = dst + t->delta_dst;
    src = src + t->delta_src;
  }
  t->src = src;
}

void clear0x020014e0(void) {
  u32_020014e0 = 0;
  return;
}

void InitScheduler(bool32 ok) {
  s32 i;
  struct Process* proc = &gProcessManager.processes[0];
  gProcessManager.masterFrame = 0;
  gProcessManager.systemOK = ok;
  StackFramePointer = NULL;
  for (i = 0; i < 3; i++, proc = &proc[1]) {
    proc->status = PROCESS_DISABLED;
  }
}

/*
  Returnされることはない
  いわゆるスケジューラ的な役割
  Process を見ていって、実行可能なものがあったら、そっちに処理を渡す
  Process が自発的に Process を中断するとここに処理が戻る
*/
WIP void GameLoop(void) {
#if MODERN
  struct Process* proc;
  do {
    gProcessManager.procID = 0;
    proc = gProcessManager.processes;
    do {
      if ((proc->status & (PROCESS_DISABLED | PROCESS_DISABLED_08)) == 0) {
        if (proc->status & PROCESS_SLEEP) {
          if ((proc->sleep == 0 || (--proc->sleep == 0))) {
            proc->status = PROCESS_OK;
          }
        }
        if (proc->status == PROCESS_OK) {
          if (proc->doReset) {
            ResetProcess(gProcessManager.procID, proc->fn);
          }
          CallProcess(proc, proc->fn, proc->sp, &StackFramePointer);
        }
      }
      gProcessManager.procID++;
      proc++;
    } while (gProcessManager.procID < 3);

    gProcessManager.masterFrame++;
  } while (gProcessManager.systemOK);
#else
  INCCODE("asm/wip/GameLoop.inc");
#endif
}

#if MODERN == 0
// Processes 全てに対して、GameLoop でスケジューリングされないようにする
static void unused_DisableAllProcesses(void) {
  struct Process* proc = gProcessManager.processes;
  s32 i = 0;
  do {
    if (proc->status != PROCESS_DISABLED) {
      disableProcess(i);
    }
    i++;
    proc = &proc[1];
  } while (i < 3);
}
#endif

void ResetProcess(s32 i, void* fn) {
  struct Process* p = &gProcessManager.processes[i];
  p->fn = fn;
  p->sp = (u16*)(&gProcessManager.stack[gProcessStackPointerOffsets[i]]);
  p->sleep = 0;
  p->doReset = FALSE;
  p->status = PROCESS_OK;
}

/*
  Processの処理を中断して、スケジューリングに処理を戻す
  Processを終了するわけではない。次のスケジューリングのときにこの関数の lr 部分から再開
*/
void SwitchProcess(bool32 b) {
  struct Process* p = &gProcessManager.processes[gProcessManager.procID];
  if (b) {
    p->sleep = b;
    p->status = PROCESS_SLEEP;
    returnCallProcess((u32*)&p->fn, (u32*)&p->sp, StackFramePointer);
  }
}

// Process_System を中断し、別の Process を(可能なら)実行させる
static void InterruptSystemProcess(struct Process* p, bool32 b) {
  if (b) {
    p->sleep = b;
    p->status = PROCESS_SLEEP;
    returnCallProcess((u32*)&p->fn, (u32*)&p->sp, StackFramePointer);
  }
}

/*
  プロセスを終了する
  proc->doReset が true でないならスケジューリングされることは以後ない
*/
void ExitProcess(void) {
  struct Process* p = &gProcessManager.processes[gProcessManager.procID];
  p->status = PROCESS_DISABLED;
  returnCallProcess((u32*)&p->fn, (u32*)&p->sp, StackFramePointer);
}

// GameLoop で Process がスケジューリングされないようにする
void disableProcess(s32 i) {
  struct Process* p = &gProcessManager.processes[i];
  if (p->status != PROCESS_DISABLED) {
    p->status = PROCESS_DISABLED;
  }
}

/*
  現在のProcess の処理内容を fn に置き換える
  Unix の fork, exec の exec と処理が似ているため、execと命名
*/
void exec(void* fn) {
  struct Process* p = &gProcessManager.processes[gProcessManager.procID];
  p->doReset = TRUE;
  p->fn = fn;
  ReturnToGameLoop(StackFramePointer);
}

void FUN_080023e0(s32 i) {
  struct Process* p = &gProcessManager.processes[i];
  if (p->status != PROCESS_DISABLED) {
    p->status |= PROCESS_DISABLED_08;
  }
}

void FUN_08002400(s32 i) {
  struct Process* p = &gProcessManager.processes[i];
  if ((p->status != PROCESS_DISABLED) && (p->status & PROCESS_DISABLED_08)) {
    p->status &= ~PROCESS_DISABLED_08;
  }
}

// Process の ofs 12..15 (例: 03002a74..03002a77) を 0クリア
void FUN_08002428(struct Process* p) {
  s32 i;
  u16* unk_10 = (u16*)p->unk_10;
  for (i = 0; i < 4; i++) {
    p->unk_0c[i] = 0;
    unk_10[i] = 0;
  }
}
