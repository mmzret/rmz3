#include "blink.h"

#include "gba/gba.h"
#include "gfx.h"
#include "global.h"
#include "motion.h"

/**
 * @brief wBlinks(0x02001fe0 から 0x02001ff0 まで)をゼロクリアする
 * @note 0x08003d84
 */
void ClearBlinkings(void) {
  u16* start = (u16*)&gBlinkManager;
  u16 fill = 0;
  u16* id = &start[BLINK_LENGTH - 1];
  do {
    *id = fill;
    id--;
  } while ((s32)id >= (s32)start);
}

/**
 * @brief CMD室の世界地図のような時間経過で色が変わるオブジェクトの色を変える処理(つまり点滅処理)を行う
 * @note 0x08003df4
 */
NAKED void ExecBlink(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	movs r7, #0\n\
	ldr r0, _08003E68 @ =gBlinkManager\n\
	mov r8, r0\n\
	mov r5, r8\n\
	adds r5, #0x20\n\
	adds r6, r5, #0\n\
_08003E06:\n\
	lsls r0, r7, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	beq _08003EAE\n\
	ldrh r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _08003EAE\n\
	ldr r2, [r5]\n\
	ldrb r0, [r2, #2]\n\
	ldrb r4, [r2, #1]\n\
	subs r0, r0, r4\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	ldrh r1, [r5, #0x12]\n\
	mov ip, r1\n\
	ldr r1, _08003E6C @ =0x000001FF\n\
	adds r0, r1, #0\n\
	mov r1, ip\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08003E78\n\
	ldrb r1, [r5, #0xc]\n\
	ldr r0, [r5, #8]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	movs r0, #0xd\n\
	ldrsb r0, [r5, r0]\n\
	ldr r1, [r1]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	muls r0, r3, r0\n\
	lsls r0, r0, #1\n\
	adds r0, #4\n\
	adds r0, r2, r0\n\
	lsls r1, r4, #1\n\
	ldrh r2, [r5, #0x12]\n\
	adds r1, r1, r2\n\
	ldr r2, _08003E70 @ =gPaletteManager\n\
	adds r1, r1, r2\n\
	ldr r2, _08003E74 @ =0x001FFFFF\n\
	ands r2, r3\n\
	bl CpuSet\n\
	b _08003EAE\n\
	.align 2, 0\n\
_08003E68: .4byte gBlinkManager\n\
_08003E6C: .4byte 0x000001FF\n\
_08003E70: .4byte gPaletteManager\n\
_08003E74: .4byte 0x001FFFFF\n\
_08003E78:\n\
	ldrb r1, [r6, #0xc]\n\
	ldr r0, [r6, #8]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	movs r0, #0xd\n\
	ldrsb r0, [r6, r0]\n\
	ldr r1, [r1]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	muls r0, r3, r0\n\
	lsls r0, r0, #1\n\
	adds r0, #4\n\
	adds r0, r2, r0\n\
	lsls r1, r4, #1\n\
	movs r2, #0x1f\n\
	ands r1, r2\n\
	ldrh r2, [r6, #0x12]\n\
	adds r1, r1, r2\n\
	ldr r2, _08003EC4 @ =gPaletteManager\n\
	adds r1, r1, r2\n\
	ldr r2, _08003EC8 @ =0x001FFFFF\n\
	ands r2, r3\n\
	bl CpuSet\n\
_08003EAE:\n\
	adds r5, #0x14\n\
	adds r6, #0x14\n\
	adds r7, #1\n\
	cmp r7, #0xf\n\
	ble _08003E06\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08003EC4: .4byte gPaletteManager\n\
_08003EC8: .4byte 0x001FFFFF\n\
	 .syntax divided\n");
}

/**
 * @brief Blinkingを一時停止させる？ メニュー画面に入る時とか
 * @note 0x08003ecc
 */
void PauseAllBlinks(void) {
  s32 i;
  for (i = 0; i < BLINK_LENGTH; i++) {
    if ((gBlinkManager.ids)[i] != 0) {
      (gBlinkManager.blinks)[i].paused = TRUE;
    }
  }
}

/**
 * @brief メニュー画面から出る時
 */
void ResumeAllBlinks(void) {
  s32 i;
  for (i = 0; i < BLINK_LENGTH; i++) {
    if ((gBlinkManager.ids)[i] != 0) {
      if ((gBlinkManager.blinks)[i].paused) {
        (gBlinkManager.blinks)[i].paused = FALSE;
      } else {
        (gBlinkManager.ids)[i] = 0;
      }
    }
  }
}

/**
 * @brief wBlinks で最初に0のエントリiを探して、wBlinks[i] と wFilms[i] に新たなBlinkをセットする
 * @param blinkID BlinkのID 0x085be764 のidx
 * @param ofs Paletteオフセット (詳細はTODO)
 * @note 0x08003f2c
 */
NAKED void LoadBlink(u16 blinkID, u16 ofs) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	movs r6, #0\n\
	ldr r3, _08003FF4 @ =gBlinkManager\n\
	adds r0, r4, #1\n\
	mov r8, r0\n\
	mov r2, r8\n\
	adds r1, r3, #0\n\
_08003F46:\n\
	ldrh r0, [r1]\n\
	cmp r0, r2\n\
	bne _08003F4E\n\
	b _08004050\n\
_08003F4E:\n\
	adds r1, #2\n\
	adds r6, #1\n\
	cmp r6, #0xf\n\
	ble _08003F46\n\
	movs r6, #0\n\
	ldrh r0, [r3]\n\
	cmp r0, #0\n\
	beq _08003F6E\n\
	adds r1, r3, #0\n\
_08003F60:\n\
	adds r1, #2\n\
	adds r6, #1\n\
	cmp r6, #0xf\n\
	bgt _08003F6E\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	bne _08003F60\n\
_08003F6E:\n\
	cmp r6, #0x10\n\
	beq _08004050\n\
	lsls r0, r6, #2\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #2\n\
	ldr r1, _08003FF8 @ =gBlinkManager+32\n\
	adds r5, r0, r1\n\
	lsls r1, r4, #2\n\
	ldr r0, _08003FFC @ =gBlinkMotionColorOffsets\n\
	adds r2, r1, r0\n\
	ldr r0, [r2]\n\
	adds r0, r0, r2\n\
	str r0, [r5]\n\
	ldr r0, _08004000 @ =gBlinkMotionCmdTable\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	str r1, [r5, #4]\n\
	movs r0, #0\n\
	strh r0, [r5, #0x10]\n\
	strh r7, [r5, #0x12]\n\
	adds r4, r5, #0\n\
	adds r4, #8\n\
	adds r0, r4, #0\n\
	bl ResetMotion\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl setMotionStep\n\
	ldr r2, [r5]\n\
	ldrb r0, [r2, #2]\n\
	ldrb r4, [r2, #1]\n\
	subs r0, r0, r4\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	ldrh r1, [r5, #0x12]\n\
	ldr r0, _08004004 @ =0x000001FF\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08004010\n\
	ldrb r1, [r5, #0xc]\n\
	ldr r0, [r5, #8]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	movs r0, #0xd\n\
	ldrsb r0, [r5, r0]\n\
	ldr r1, [r1]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	muls r0, r3, r0\n\
	lsls r0, r0, #1\n\
	adds r0, #4\n\
	adds r0, r2, r0\n\
	lsls r1, r4, #1\n\
	ldrh r5, [r5, #0x12]\n\
	adds r1, r1, r5\n\
	ldr r2, _08004008 @ =gPaletteManager\n\
	adds r1, r1, r2\n\
	ldr r2, _0800400C @ =0x001FFFFF\n\
	ands r2, r3\n\
	bl CpuSet\n\
	b _08004046\n\
	.align 2, 0\n\
_08003FF4: .4byte gBlinkManager\n\
_08003FF8: .4byte gBlinkManager+32\n\
_08003FFC: .4byte gBlinkMotionColorOffsets\n\
_08004000: .4byte gBlinkMotionCmdTable\n\
_08004004: .4byte 0x000001FF\n\
_08004008: .4byte gPaletteManager\n\
_0800400C: .4byte 0x001FFFFF\n\
_08004010:\n\
	ldrb r1, [r5, #0xc]\n\
	ldr r0, [r5, #8]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	movs r0, #0xd\n\
	ldrsb r0, [r5, r0]\n\
	ldr r1, [r1]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	muls r0, r3, r0\n\
	lsls r0, r0, #1\n\
	adds r0, #4\n\
	adds r0, r2, r0\n\
	lsls r1, r4, #1\n\
	movs r2, #0x1f\n\
	ands r1, r2\n\
	ldrh r5, [r5, #0x12]\n\
	adds r1, r1, r5\n\
	ldr r2, _0800405C @ =gPaletteManager\n\
	adds r1, r1, r2\n\
	ldr r2, _08004060 @ =0x001FFFFF\n\
	ands r2, r3\n\
	bl CpuSet\n\
_08004046:\n\
	ldr r1, _08004064 @ =gBlinkManager\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r1\n\
	mov r1, r8\n\
	strh r1, [r0]\n\
_08004050:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800405C: .4byte gPaletteManager\n\
_08004060: .4byte 0x001FFFFF\n\
_08004064: .4byte gBlinkManager\n\
	 .syntax divided\n");
}

/**
 * @note 0x08004068
 */
u32 UpdateBlinkMotionState(u16 blinkID) {
  struct Blink* b;
  s32 i;

  blinkID++;
  for (i = 0; i < BLINK_LENGTH; i++) {
    if ((gBlinkManager.ids)[i] == blinkID) {
      break;
    }
  }
  if (i == BLINK_LENGTH) {
    return MOTION_END;
  }
  b = &gBlinkManager.blinks[i];
  UpdateMotionState(&b->m);
  return b->m.state;
}

/**
 * @brief wBlinks の該当エントリ(wBlinks[i] = (n+1)) を0クリアする
 * @param n BlinkのID 0x085be764 のidx
 * @note 0x080040b4
 */
void ClearBlink(u16 blinkID) {
  s32 i;

  blinkID++;
  for (i = 0; i < BLINK_LENGTH; i++) {
    if ((gBlinkManager.ids)[i] == blinkID) {
      break;
    }
  }
  if (i != BLINK_LENGTH) {
    (gBlinkManager.ids)[i] = 0;
  }
}

// ------------------------------------------------------------------------------------------------------------------------------------

const u32 gBlinkMotionColorOffsets[BLINK_NUM] = {
    0x00000460, 0x00000484, 0x000004A8, 0x000004CC, 0x000004E0, 0x00000514, 0x00000600, 0x0000060C, 0x00000708, 0x000007C8, 0x000008C4, 0x000008D0, 0x00000A50, 0x00000B10, 0x00000BD0, 0x00000C70, 0x00000DB0, 0x00000E50, 0x00000EF0, 0x00000F90, 0x00001030, 0x00001170, 0x00001210, 0x000012B0, 0x00001350, 0x00001490, 0x000014D0, 0x000015B0, 0x00001630, 0x000016B0, 0x00001770, 0x000019F0, 0x00001AB0, 0x00001C68, 0x00002138, 0x00002144, 0x00002154, 0x00002164, 0x0000217C, 0x00002180, 0x0000218C, 0x00002228, 0x00002348, 0x00002408, 0x00002414, 0x00002474, 0x00002564, 0x00002588, 0x00002594, 0x00002634, 0x00002670, 0x000026A0, 0x000026D0, 0x000026D4, 0x00002704, 0x00002724, 0x00002730, 0x00002750, 0x000027D4, 0x000027E0, 0x00002804, 0x00002840, 0x000028C0, 0x000028F4, 0x00002934, 0x000029B4, 0x00002A34, 0x00002A44, 0x00002A54, 0x00002A88,
    0x00002B28, 0x00002BE8, 0x00002CA8, 0x00002D28, 0x00002DA8, 0x00002F48, 0x00002FC8, 0x00003168, 0x000032E8, 0x00003468, 0x000034E0, 0x00003518, 0x0000354C, 0x000035CC, 0x0000364C, 0x000036AC, 0x000037CC, 0x0000390C, 0x0000394C, 0x000039CC, 0x00003A4C, 0x00003ACC, 0x00003AEC, 0x00003B0C, 0x00003B2C, 0x00003B4C, 0x00003B6C, 0x00003DCC, 0x00003FCC, 0x0000404C, 0x0000416C, 0x00003B58, 0x00004208, 0x000042C8, 0x00004388, 0x00004390, 0x000043B4, 0x000043C8, 0x000044A8, 0x000044B4, 0x000044C0, 0x000044E0, 0x00004560, 0x00004710, 0x00004714, 0x00004730, 0x0000474C, 0x00004764, 0x00004770, 0x0000477C, 0x000047CC, 0x000048BC, 0x000048DC, 0x00004984, 0x00004B44, 0x00004D3C, 0x00004D50, 0x00004D5C, 0x00004E28, 0x00004EB4, 0x00004EEC, 0x00004F00, 0x00004F8C, 0x00004FA4, 0x00004FB4, 0x00004FD4, 0x00004FEC, 0x0000500C, 0x0000502C, 0x00005044,
    0x00005048, 0x00005054, 0x00005064, 0x00005148, 0x00005304, 0x00005484, 0x000054AC, 0x000054D4, 0x000054EC, 0x00005500, 0x00005514, 0x00005578, 0x0000557C, 0x00005584, 0x000055C0, 0x000055CC, 0x000055D8, 0x000055E4, 0x000055F0, 0x000055FC, 0x000056C4, 0x000056D8, 0x000056EC, 0x00005770, 0x0000577C, 0x0000578C, 0x00005794, 0x000057A4, 0x00005924, 0x000059E4, 0x00005AE4, 0x00005C24, 0x00005C48, 0x00005C6C, 0x00005C90, 0x00005CB4, 0x00005CD8, 0x00005CFC, 0x00005D04, 0x00005D10, 0x00005D34, 0x00005D58, 0x00005D7C, 0x00005DA0, 0x00005DC4, 0x0000017C, 0x00000178, 0x00005DE0, 0x00005E60, 0x00005EE0, 0x00005FA0, 0x00006120, 0x00006144, 0x00006148, 0x000061C8, 0x00006248, 0x00006338, 0x00006348, 0x000063A8, 0x000063BC, 0x000063C4, 0x000063E4, 0x000063F8, 0x000064A0, 0x00006520, 0x00006540, 0x000065CC, 0x00006658, 0x000066B4, 0x00006710,
    0x000067B0, 0x000067F8, 0x0000687C, 0x00006894, 0x000068B4, 0x000068D4, 0x000068E0, 0x00006908, 0x00006924, 0x00006944, 0x00006950, 0x000069D0, 0x00006A30, 0x00006A94, 0x00006AE4, 0x00006BE8, 0x00006C88, 0x00006CA8, 0x00006D08, 0x00006DC0, 0x00006DD0, 0x00006E0C, 0x00006E1C, 0x00006E2C, 0x00006E3C, 0x00006FA8, 0x00006FB8, 0x00006FC8, 0x00006FD8, 0x00007004, 0x00007030, 0x000072F0, 0x00007330, 0x00007530, 0x00007554, 0x00007574, 0x00007594, 0x000075B4, 0x000075D4, 0x00007614, 0x00007654, 0x000076D4, 0x000077B4, 0x00007894, 0x00007974, 0x00007A54, 0x00007B34, 0x00007C14, 0x00007CF4, 0x00007DD4, 0x00007DEC, 0x00007E04, 0x00007E1C, 0x00007EAC, 0x00007EC4, 0x00007F84, 0x000080B4, 0x000080D8, 0x000080E0, 0x000080E8, 0x00008198, 0x000081B8, 0x000081D8, 0x00008258, 0x00008294, 0x000082B4, 0x000082D4, 0x00008434, 0x00008454, 0x000085B4,
};

// ./tools/dumper/bin.ts baserom.gba 0x085b6130 0x085be764 data/blink_pal.bin
INCBIN("data/blink_pal.bin");

// clang-format off
extern const struct MotionCmd* const gBlinkCmd_000[];
extern const struct MotionCmd* const gBlinkCmd_001[];
extern const struct MotionCmd* const gBlinkCmd_002[];
extern const struct MotionCmd* const gBlinkCmd_003[];
extern const struct MotionCmd* const gBlinkCmd_Menu[];
extern const struct MotionCmd* const gBlinkCmd_005[];
extern const struct MotionCmd* const gBlinkCmd_006[];
extern const struct MotionCmd* const gBlinkCmd_007[];
extern const struct MotionCmd* const gBlinkCmd_008[];
extern const struct MotionCmd* const gBlinkCmd_009[];
extern const struct MotionCmd* const gBlinkCmd_010[];
extern const struct MotionCmd* const gBlinkCmd_011[];
extern const struct MotionCmd* const gBlinkCmd_012[];
extern const struct MotionCmd* const gBlinkCmd_013[];
extern const struct MotionCmd* const gBlinkCmd_014[];
extern const struct MotionCmd* const gBlinkCmd_015[];
extern const struct MotionCmd* const gBlinkCmd_016[];
extern const struct MotionCmd* const gBlinkCmd_017[];
extern const struct MotionCmd* const gBlinkCmd_018[];
extern const struct MotionCmd* const gBlinkCmd_019[];
extern const struct MotionCmd* const gBlinkCmd_020[];
extern const struct MotionCmd* const gBlinkCmd_021[];
extern const struct MotionCmd* const gBlinkCmd_022[];
extern const struct MotionCmd* const gBlinkCmd_023[];
extern const struct MotionCmd* const gBlinkCmd_024[];
extern const struct MotionCmd* const gBlinkCmd_025[];
extern const struct MotionCmd* const gBlinkCmd_026[];
extern const struct MotionCmd* const gBlinkCmd_027[];
extern const struct MotionCmd* const gBlinkCmd_028[];
extern const struct MotionCmd* const gBlinkCmd_029[];
extern const struct MotionCmd* const gBlinkCmd_030[];
extern const struct MotionCmd* const gBlinkCmd_031[];
extern const struct MotionCmd* const gBlinkCmd_032[];
extern const struct MotionCmd* const gBlinkCmd_033[];
extern const struct MotionCmd* const gBlinkCmd_034[];
extern const struct MotionCmd* const gBlinkCmd_035[];
extern const struct MotionCmd* const gBlinkCmd_036[];
extern const struct MotionCmd* const gBlinkCmd_037[];
extern const struct MotionCmd* const gBlinkCmd_038[];
extern const struct MotionCmd* const gBlinkCmd_039[];
extern const struct MotionCmd* const gBlinkCmd_040[];
extern const struct MotionCmd* const gBlinkCmd_041[];
extern const struct MotionCmd* const gBlinkCmd_042[];
extern const struct MotionCmd* const gBlinkCmd_043[];
extern const struct MotionCmd* const gBlinkCmd_044[];
extern const struct MotionCmd* const gBlinkCmd_045[];
extern const struct MotionCmd* const gBlinkCmd_046[];
extern const struct MotionCmd* const gBlinkCmd_047[];
extern const struct MotionCmd* const gBlinkCmd_048[];
extern const struct MotionCmd* const gBlinkCmd_049[];
extern const struct MotionCmd* const gBlinkCmd_050[];
extern const struct MotionCmd* const gBlinkCmd_051[];
extern const struct MotionCmd* const gBlinkCmd_052[];
extern const struct MotionCmd* const gBlinkCmd_053[];
extern const struct MotionCmd* const gBlinkCmd_054[];
extern const struct MotionCmd* const gBlinkCmd_055[];
extern const struct MotionCmd* const gBlinkCmd_056[];
extern const struct MotionCmd* const gBlinkCmd_057[];
extern const struct MotionCmd* const gBlinkCmd_058[];
extern const struct MotionCmd* const gBlinkCmd_059[];
extern const struct MotionCmd* const gBlinkCmd_060[];
extern const struct MotionCmd* const gBlinkCmd_061[];
extern const struct MotionCmd* const gBlinkCmd_062[];
extern const struct MotionCmd* const gBlinkCmd_063[];
extern const struct MotionCmd* const gBlinkCmd_064[];
extern const struct MotionCmd* const gBlinkCmd_065[];
extern const struct MotionCmd* const gBlinkCmd_066[];
extern const struct MotionCmd* const gBlinkCmd_067[];
extern const struct MotionCmd* const gBlinkCmd_068[];
extern const struct MotionCmd* const gBlinkCmd_069[];
extern const struct MotionCmd* const gBlinkCmd_070[];
extern const struct MotionCmd* const gBlinkCmd_071[];
extern const struct MotionCmd* const gBlinkCmd_072[];
extern const struct MotionCmd* const gBlinkCmd_073[];
extern const struct MotionCmd* const gBlinkCmd_074[];
extern const struct MotionCmd* const gBlinkCmd_075[];
extern const struct MotionCmd* const gBlinkCmd_076[];
extern const struct MotionCmd* const gBlinkCmd_077[];
extern const struct MotionCmd* const gBlinkCmd_078[];
extern const struct MotionCmd* const gBlinkCmd_079[];
extern const struct MotionCmd* const gBlinkCmd_080[];
extern const struct MotionCmd* const gBlinkCmd_081[];
extern const struct MotionCmd* const gBlinkCmd_082[];
extern const struct MotionCmd* const gBlinkCmd_083[];
extern const struct MotionCmd* const gBlinkCmd_084[];
extern const struct MotionCmd* const gBlinkCmd_085[];
extern const struct MotionCmd* const gBlinkCmd_086[];
extern const struct MotionCmd* const gBlinkCmd_087[];
extern const struct MotionCmd* const gBlinkCmd_088[];
extern const struct MotionCmd* const gBlinkCmd_089[];
extern const struct MotionCmd* const gBlinkCmd_090[];
extern const struct MotionCmd* const gBlinkCmd_091[];
extern const struct MotionCmd* const gBlinkCmd_092[];
extern const struct MotionCmd* const gBlinkCmd_093[];
extern const struct MotionCmd* const gBlinkCmd_094[];
extern const struct MotionCmd* const gBlinkCmd_095[];
extern const struct MotionCmd* const gBlinkCmd_096[];
extern const struct MotionCmd* const gBlinkCmd_097[];
extern const struct MotionCmd* const gBlinkCmd_098[];
extern const struct MotionCmd* const gBlinkCmd_099[];
extern const struct MotionCmd* const gBlinkCmd_100[];
extern const struct MotionCmd* const gBlinkCmd_102[];
extern const struct MotionCmd* const gBlinkCmd_103[];
extern const struct MotionCmd* const gBlinkCmd_104[];
extern const struct MotionCmd* const gBlinkCmd_105[];
extern const struct MotionCmd* const gBlinkCmd_106[];
extern const struct MotionCmd* const gBlinkCmd_107[];
extern const struct MotionCmd* const gBlinkCmd_108[];
extern const struct MotionCmd* const gBlinkCmd_109[];
extern const struct MotionCmd* const gBlinkCmd_110[];
extern const struct MotionCmd* const gBlinkCmd_111[];
extern const struct MotionCmd* const gBlinkCmd_112[];
extern const struct MotionCmd* const gBlinkCmd_113[];
extern const struct MotionCmd* const gBlinkCmd_114[];
extern const struct MotionCmd* const gBlinkCmd_115[];
extern const struct MotionCmd* const gBlinkCmd_116[];
extern const struct MotionCmd* const gBlinkCmd_117[];
extern const struct MotionCmd* const gBlinkCmd_118[];
extern const struct MotionCmd* const gBlinkCmd_119[];
extern const struct MotionCmd* const gBlinkCmd_120[];
extern const struct MotionCmd* const gBlinkCmd_121[];
extern const struct MotionCmd* const gBlinkCmd_122[];
extern const struct MotionCmd* const gBlinkCmd_123[];
extern const struct MotionCmd* const gBlinkCmd_124[];
extern const struct MotionCmd* const gBlinkCmd_125[];
extern const struct MotionCmd* const gBlinkCmd_126[];
extern const struct MotionCmd* const gBlinkCmd_127[];
extern const struct MotionCmd* const gBlinkCmd_128[];
extern const struct MotionCmd* const gBlinkCmd_129[];
extern const struct MotionCmd* const gBlinkCmd_130[];
extern const struct MotionCmd* const gBlinkCmd_131[];
extern const struct MotionCmd* const gBlinkCmd_132[];
extern const struct MotionCmd* const gBlinkCmd_133[];
extern const struct MotionCmd* const gBlinkCmd_134[];
extern const struct MotionCmd* const gBlinkCmd_135[];
extern const struct MotionCmd* const gBlinkCmd_136[];
extern const struct MotionCmd* const gBlinkCmd_137[];
extern const struct MotionCmd* const gBlinkCmd_138[];
extern const struct MotionCmd* const gBlinkCmd_139[];
extern const struct MotionCmd* const gBlinkCmd_140[];
extern const struct MotionCmd* const gBlinkCmd_141[];
extern const struct MotionCmd* const gBlinkCmd_142[];
extern const struct MotionCmd* const gBlinkCmd_143[];
extern const struct MotionCmd* const gBlinkCmd_144[];
extern const struct MotionCmd* const gBlinkCmd_145[];
extern const struct MotionCmd* const gBlinkCmd_146[];
extern const struct MotionCmd* const gBlinkCmd_147[];
extern const struct MotionCmd* const gBlinkCmd_148[];
extern const struct MotionCmd* const gBlinkCmd_149[];
extern const struct MotionCmd* const gBlinkCmd_150[];
extern const struct MotionCmd* const gBlinkCmd_151[];
extern const struct MotionCmd* const gBlinkCmd_152[];
extern const struct MotionCmd* const gBlinkCmd_153[];
extern const struct MotionCmd* const gBlinkCmd_154[];
extern const struct MotionCmd* const gBlinkCmd_155[];
extern const struct MotionCmd* const gBlinkCmd_156[];
extern const struct MotionCmd* const gBlinkCmd_157[];
extern const struct MotionCmd* const gBlinkCmd_158[];
extern const struct MotionCmd* const gBlinkCmd_159[];
extern const struct MotionCmd* const gBlinkCmd_160[];
extern const struct MotionCmd* const gBlinkCmd_161[];
extern const struct MotionCmd* const gBlinkCmd_162[];
extern const struct MotionCmd* const gBlinkCmd_163[];
extern const struct MotionCmd* const gBlinkCmd_164[];
extern const struct MotionCmd* const gBlinkCmd_165[];
extern const struct MotionCmd* const gBlinkCmd_166[];
extern const struct MotionCmd* const gBlinkCmd_167[];
extern const struct MotionCmd* const gBlinkCmd_168[];
extern const struct MotionCmd* const gBlinkCmd_169[];
extern const struct MotionCmd* const gBlinkCmd_170[];
extern const struct MotionCmd* const gBlinkCmd_171[];
extern const struct MotionCmd* const gBlinkCmd_172[];
extern const struct MotionCmd* const gBlinkCmd_173[];
extern const struct MotionCmd* const gBlinkCmd_174[];
extern const struct MotionCmd* const gBlinkCmd_175[];
extern const struct MotionCmd* const gBlinkCmd_176[];
extern const struct MotionCmd* const gBlinkCmd_177[];
extern const struct MotionCmd* const gBlinkCmd_178[];
extern const struct MotionCmd* const gBlinkCmd_179[];
extern const struct MotionCmd* const gBlinkCmd_180[];
extern const struct MotionCmd* const gBlinkCmd_181[];
extern const struct MotionCmd* const gBlinkCmd_182[];
extern const struct MotionCmd* const gBlinkCmd_183[];
extern const struct MotionCmd* const gBlinkCmd_184[];
extern const struct MotionCmd* const gBlinkCmd_187[];
extern const struct MotionCmd* const gBlinkCmd_188[];
extern const struct MotionCmd* const gBlinkCmd_189[];
extern const struct MotionCmd* const gBlinkCmd_190[];
extern const struct MotionCmd* const gBlinkCmd_191[];
extern const struct MotionCmd* const gBlinkCmd_192[];
extern const struct MotionCmd* const gBlinkCmd_193[];
extern const struct MotionCmd* const gBlinkCmd_194[];
extern const struct MotionCmd* const gBlinkCmd_195[];
extern const struct MotionCmd* const gBlinkCmd_196[];
extern const struct MotionCmd* const gBlinkCmd_197[];
extern const struct MotionCmd* const gBlinkCmd_198[];
extern const struct MotionCmd* const gBlinkCmd_199[];
extern const struct MotionCmd* const gBlinkCmd_200[];
extern const struct MotionCmd* const gBlinkCmd_201[];
extern const struct MotionCmd* const gBlinkCmd_202[];
extern const struct MotionCmd* const gBlinkCmd_203[];
extern const struct MotionCmd* const gBlinkCmd_204[];
extern const struct MotionCmd* const gBlinkCmd_205[];
extern const struct MotionCmd* const gBlinkCmd_206[];
extern const struct MotionCmd* const gBlinkCmd_207[];
extern const struct MotionCmd* const gBlinkCmd_208[];
extern const struct MotionCmd* const gBlinkCmd_209[];
extern const struct MotionCmd* const gBlinkCmd_210[];
extern const struct MotionCmd* const gBlinkCmd_211[];
extern const struct MotionCmd* const gBlinkCmd_212[];
extern const struct MotionCmd* const gBlinkCmd_213[];
extern const struct MotionCmd* const gBlinkCmd_214[];
extern const struct MotionCmd* const gBlinkCmd_215[];
extern const struct MotionCmd* const gBlinkCmd_216[];
extern const struct MotionCmd* const gBlinkCmd_217[];
extern const struct MotionCmd* const gBlinkCmd_218[];
extern const struct MotionCmd* const gBlinkCmd_219[];
extern const struct MotionCmd* const gBlinkCmd_220[];
extern const struct MotionCmd* const gBlinkCmd_221[];
extern const struct MotionCmd* const gBlinkCmd_222[];
extern const struct MotionCmd* const gBlinkCmd_223[];
extern const struct MotionCmd* const gBlinkCmd_224[];
extern const struct MotionCmd* const gBlinkCmd_225[];
extern const struct MotionCmd* const gBlinkCmd_226[];
extern const struct MotionCmd* const gBlinkCmd_227[];
extern const struct MotionCmd* const gBlinkCmd_228[];
extern const struct MotionCmd* const gBlinkCmd_229[];
extern const struct MotionCmd* const gBlinkCmd_230[];
extern const struct MotionCmd* const gBlinkCmd_231[];
extern const struct MotionCmd* const gBlinkCmd_232[];
extern const struct MotionCmd* const gBlinkCmd_233[];
extern const struct MotionCmd* const gBlinkCmd_234[];
extern const struct MotionCmd* const gBlinkCmd_235[];
extern const struct MotionCmd* const gBlinkCmd_236[];
extern const struct MotionCmd* const gBlinkCmd_237[];
extern const struct MotionCmd* const gBlinkCmd_238[];
extern const struct MotionCmd* const gBlinkCmd_239[];
extern const struct MotionCmd* const gBlinkCmd_240[];
extern const struct MotionCmd* const gBlinkCmd_241[];
extern const struct MotionCmd* const gBlinkCmd_242[];
extern const struct MotionCmd* const gBlinkCmd_243[];
extern const struct MotionCmd* const gBlinkCmd_244[];
extern const struct MotionCmd* const gBlinkCmd_245[];
extern const struct MotionCmd* const gBlinkCmd_246[];
extern const struct MotionCmd* const gBlinkCmd_247[];
extern const struct MotionCmd* const gBlinkCmd_248[];
extern const struct MotionCmd* const gBlinkCmd_249[];
extern const struct MotionCmd* const gBlinkCmd_250[];
extern const struct MotionCmd* const gBlinkCmd_251[];
extern const struct MotionCmd* const gBlinkCmd_252[];
extern const struct MotionCmd* const gBlinkCmd_253[];
extern const struct MotionCmd* const gBlinkCmd_254[];
extern const struct MotionCmd* const gBlinkCmd_255[];
extern const struct MotionCmd* const gBlinkCmd_256[];
extern const struct MotionCmd* const gBlinkCmd_257[];
extern const struct MotionCmd* const gBlinkCmd_258[];
extern const struct MotionCmd* const gBlinkCmd_259[];
extern const struct MotionCmd* const gBlinkCmd_260[];
extern const struct MotionCmd* const gBlinkCmd_261[];
extern const struct MotionCmd* const gBlinkCmd_262[];
extern const struct MotionCmd* const gBlinkCmd_263[];
extern const struct MotionCmd* const gBlinkCmd_264[];
extern const struct MotionCmd* const gBlinkCmd_265[];
extern const struct MotionCmd* const gBlinkCmd_266[];
extern const struct MotionCmd* const gBlinkCmd_267[];
extern const struct MotionCmd* const gBlinkCmd_268[];
extern const struct MotionCmd* const gBlinkCmd_269[];
extern const struct MotionCmd* const gBlinkCmd_270[];
extern const struct MotionCmd* const gBlinkCmd_271[];
extern const struct MotionCmd* const gBlinkCmd_272[];
extern const struct MotionCmd* const gBlinkCmd_273[];
extern const struct MotionCmd* const gBlinkCmd_274[];
extern const struct MotionCmd* const gBlinkCmd_275[];
extern const struct MotionCmd* const gBlinkCmd_276[];
extern const struct MotionCmd* const gBlinkCmd_277[];
extern const struct MotionCmd* const gBlinkCmd_278[];
extern const struct MotionCmd* const gBlinkCmd_279[];

const struct MotionCmd* const * const gBlinkMotionCmdTable[BLINK_NUM] = {
    [0] =  gBlinkCmd_000,
    [1] =  gBlinkCmd_001,
    [2] =  gBlinkCmd_002,
    [3] =  gBlinkCmd_003,
    [4] =  gBlinkCmd_Menu, // メニュー画面の点滅
    [5] =  gBlinkCmd_005,
    [6] =  gBlinkCmd_006,
    [7] =  gBlinkCmd_007,
    [8] =  gBlinkCmd_008,
    [9] =  gBlinkCmd_009,
    [10] =  gBlinkCmd_010,
    [11] =  gBlinkCmd_011,
    [12] =  gBlinkCmd_012,
    [13] =  gBlinkCmd_013,
    [14] =  gBlinkCmd_014,
    [15] =  gBlinkCmd_015,
    [16] =  gBlinkCmd_016,
    [17] =  gBlinkCmd_017,
    [18] =  gBlinkCmd_018,
    [19] =  gBlinkCmd_019,
    [20] =  gBlinkCmd_020,
    [21] =  gBlinkCmd_021,
    [22] =  gBlinkCmd_022,
    [23] =  gBlinkCmd_023,
    [24] =  gBlinkCmd_024,
    [25] =  gBlinkCmd_025,
    [26] =  gBlinkCmd_026,
    [27] =  gBlinkCmd_027,
    [28] =  gBlinkCmd_028,
    [29] =  gBlinkCmd_029,
    [30] =  gBlinkCmd_030,
    [31] =  gBlinkCmd_031,
    [32] =  gBlinkCmd_032,
    [33] =  gBlinkCmd_033,
    [34] =  gBlinkCmd_034,
    [35] =  gBlinkCmd_035,
    [36] =  gBlinkCmd_036,
    [37] =  gBlinkCmd_037,
    [38] =  gBlinkCmd_038,
    [39] =  gBlinkCmd_039,
    [40] =  gBlinkCmd_040,
    [41] =  gBlinkCmd_041,
    [42] =  gBlinkCmd_042,
    [43] =  gBlinkCmd_043,
    [44] =  gBlinkCmd_044,
    [45] =  gBlinkCmd_045,
    [46] =  gBlinkCmd_046,
    [47] =  gBlinkCmd_047,
    [48] =  gBlinkCmd_048,
    [49] =  gBlinkCmd_049,
    [50] =  gBlinkCmd_050,
    [51] =  gBlinkCmd_051,
    [52] =  gBlinkCmd_052,
    [53] =  gBlinkCmd_053,
    [54] =  gBlinkCmd_054,
    [55] =  gBlinkCmd_055,
    [56] =  gBlinkCmd_056,
    [57] =  gBlinkCmd_057,
    [58] =  gBlinkCmd_058,
    [59] =  gBlinkCmd_059,
    [60] =  gBlinkCmd_060,
    [61] =  gBlinkCmd_061,
    [62] =  gBlinkCmd_062,
    [63] =  gBlinkCmd_063,
    [64] =  gBlinkCmd_064,
    [65] =  gBlinkCmd_065,
    [66] =  gBlinkCmd_066,
    [67] =  gBlinkCmd_067,
    [68] =  gBlinkCmd_068,
    [69] =  gBlinkCmd_069,
    [70] =  gBlinkCmd_070,
    [71] =  gBlinkCmd_071,
    [72] =  gBlinkCmd_072,
    [73] =  gBlinkCmd_073,
    [74] =  gBlinkCmd_074,
    [75] =  gBlinkCmd_075,
    [76] =  gBlinkCmd_076,
    [77] =  gBlinkCmd_077,
    [78] =  gBlinkCmd_078,
    [79] =  gBlinkCmd_079,
    [80] =  gBlinkCmd_080,
    [81] =  gBlinkCmd_081,
    [82] =  gBlinkCmd_082,
    [83] =  gBlinkCmd_083,
    [84] =  gBlinkCmd_084,
    [85] =  gBlinkCmd_085,
    [86] =  gBlinkCmd_086,
    [87] =  gBlinkCmd_087,
    [88] =  gBlinkCmd_088,
    [89] =  gBlinkCmd_089,
    [90] =  gBlinkCmd_090,
    [91] =  gBlinkCmd_091,
    [92] =  gBlinkCmd_092,
    [93] =  gBlinkCmd_093,
    [94] =  gBlinkCmd_094,
    [95] =  gBlinkCmd_095,
    [96] =  gBlinkCmd_096,
    [97] =  gBlinkCmd_097,
    [98] =  gBlinkCmd_098,
    [99] =  gBlinkCmd_099,
    [100] =  gBlinkCmd_100,
    [101] =  gBlinkCmd_096,
    [102] =  gBlinkCmd_102,
    [103] =  gBlinkCmd_103,
    [104] =  gBlinkCmd_104,
    [105] =  gBlinkCmd_105,
    [106] =  gBlinkCmd_106,
    [107] =  gBlinkCmd_107,
    [108] =  gBlinkCmd_108,
    [109] =  gBlinkCmd_109,
    [110] =  gBlinkCmd_110,
    [111] =  gBlinkCmd_111,
    [112] =  gBlinkCmd_112,
    [113] =  gBlinkCmd_113,
    [114] =  gBlinkCmd_114,
    [115] =  gBlinkCmd_115,
    [116] =  gBlinkCmd_116,
    [117] =  gBlinkCmd_117,
    [118] =  gBlinkCmd_118,
    [119] =  gBlinkCmd_119,
    [120] =  gBlinkCmd_120,
    [121] =  gBlinkCmd_121,
    [122] =  gBlinkCmd_122,
    [123] =  gBlinkCmd_123,
    [124] =  gBlinkCmd_124,
    [125] =  gBlinkCmd_125,
    [126] =  gBlinkCmd_126,
    [127] =  gBlinkCmd_127,
    [128] =  gBlinkCmd_128,
    [129] =  gBlinkCmd_129,
    [130] =  gBlinkCmd_130,
    [131] =  gBlinkCmd_131,
    [132] =  gBlinkCmd_132,
    [133] =  gBlinkCmd_133,
    [134] =  gBlinkCmd_134,
    [135] =  gBlinkCmd_135,
    [136] =  gBlinkCmd_136,
    [137] =  gBlinkCmd_137,
    [138] =  gBlinkCmd_138,
    [139] =  gBlinkCmd_139,
    [140] =  gBlinkCmd_140,
    [141] =  gBlinkCmd_141,
    [142] =  gBlinkCmd_142,
    [143] =  gBlinkCmd_143,
    [144] =  gBlinkCmd_144,
    [145] =  gBlinkCmd_145,
    [146] =  gBlinkCmd_146,
    [147] =  gBlinkCmd_147,
    [148] =  gBlinkCmd_148,
    [149] =  gBlinkCmd_149,
    [150] =  gBlinkCmd_150,
    [151] =  gBlinkCmd_151,
    [152] =  gBlinkCmd_152,
    [153] =  gBlinkCmd_153,
    [154] =  gBlinkCmd_154,
    [155] =  gBlinkCmd_155,
    [156] =  gBlinkCmd_156,
    [157] =  gBlinkCmd_157,
    [158] =  gBlinkCmd_158,
    [159] =  gBlinkCmd_159,
    [160] =  gBlinkCmd_160,
    [161] =  gBlinkCmd_161,
    [162] =  gBlinkCmd_162,
    [163] =  gBlinkCmd_163,
    [164] =  gBlinkCmd_164,
    [165] =  gBlinkCmd_165,
    [166] =  gBlinkCmd_166,
    [167] =  gBlinkCmd_167,
    [168] =  gBlinkCmd_168,
    [169] =  gBlinkCmd_169,
    [170] =  gBlinkCmd_170,
    [171] =  gBlinkCmd_171,
    [172] =  gBlinkCmd_172,
    [173] =  gBlinkCmd_173,
    [174] =  gBlinkCmd_174,
    [175] =  gBlinkCmd_175,
    [176] =  gBlinkCmd_176,
    [177] =  gBlinkCmd_177,
    [178] =  gBlinkCmd_178,
    [179] =  gBlinkCmd_179,
    [180] =  gBlinkCmd_180,
    [181] =  gBlinkCmd_181,
    [182] =  gBlinkCmd_182,
    [183] =  gBlinkCmd_183,
    [184] =  gBlinkCmd_184,
    [185] =  gBlinkCmd_000,
    [186] =  gBlinkCmd_000,
    [187] =  gBlinkCmd_187,
    [188] =  gBlinkCmd_188,
    [189] =  gBlinkCmd_189,
    [190] =  gBlinkCmd_190,
    [191] =  gBlinkCmd_191,
    [192] =  gBlinkCmd_192,
    [193] =  gBlinkCmd_193,
    [194] =  gBlinkCmd_194,
    [195] =  gBlinkCmd_195,
    [196] =  gBlinkCmd_196,
    [197] =  gBlinkCmd_197,
    [198] =  gBlinkCmd_198,
    [199] =  gBlinkCmd_199,
    [200] =  gBlinkCmd_200,
    [201] =  gBlinkCmd_201,
    [202] =  gBlinkCmd_202,
    [203] =  gBlinkCmd_203,
    [204] =  gBlinkCmd_204,
    [205] =  gBlinkCmd_205,
    [206] =  gBlinkCmd_206,
    [207] =  gBlinkCmd_207,
    [208] =  gBlinkCmd_208,
    [209] =  gBlinkCmd_209,
    [210] =  gBlinkCmd_210,
    [211] =  gBlinkCmd_211,
    [212] =  gBlinkCmd_212,
    [213] =  gBlinkCmd_213,
    [214] =  gBlinkCmd_214,
    [215] =  gBlinkCmd_215,
    [216] =  gBlinkCmd_216,
    [217] =  gBlinkCmd_217,
    [218] =  gBlinkCmd_218,
    [219] =  gBlinkCmd_219,
    [220] =  gBlinkCmd_220,
    [221] =  gBlinkCmd_221,
    [222] =  gBlinkCmd_222,
    [223] =  gBlinkCmd_223,
    [224] =  gBlinkCmd_224,
    [225] =  gBlinkCmd_225,
    [226] =  gBlinkCmd_226,
    [227] =  gBlinkCmd_227,
    [228] =  gBlinkCmd_228,
    [229] =  gBlinkCmd_229,
    [230] =  gBlinkCmd_230,
    [231] =  gBlinkCmd_231,
    [232] =  gBlinkCmd_232,
    [233] =  gBlinkCmd_233,
    [234] =  gBlinkCmd_234,
    [235] =  gBlinkCmd_235,
    [236] =  gBlinkCmd_236,
    [237] =  gBlinkCmd_237,
    [238] =  gBlinkCmd_238,
    [239] =  gBlinkCmd_239,
    [240] =  gBlinkCmd_240,
    [241] =  gBlinkCmd_241,
    [242] =  gBlinkCmd_242,
    [243] =  gBlinkCmd_243,
    [244] =  gBlinkCmd_244,
    [245] =  gBlinkCmd_245,
    [246] =  gBlinkCmd_246,
    [247] =  gBlinkCmd_247,
    [248] =  gBlinkCmd_248,
    [249] =  gBlinkCmd_249,
    [250] =  gBlinkCmd_250,
    [251] =  gBlinkCmd_251,
    [252] =  gBlinkCmd_252,
    [253] =  gBlinkCmd_253,
    [254] =  gBlinkCmd_254,
    [255] =  gBlinkCmd_255,
    [256] =  gBlinkCmd_256,
    [257] =  gBlinkCmd_257,
    [258] =  gBlinkCmd_258,
    [259] =  gBlinkCmd_259,
    [260] =  gBlinkCmd_260,
    [261] =  gBlinkCmd_261,
    [262] =  gBlinkCmd_262,
    [263] =  gBlinkCmd_263,
    [264] =  gBlinkCmd_264,
    [265] =  gBlinkCmd_265,
    [266] =  gBlinkCmd_266,
    [267] =  gBlinkCmd_267,
    [268] =  gBlinkCmd_268,
    [269] =  gBlinkCmd_269,
    [270] =  gBlinkCmd_270,
    [271] =  gBlinkCmd_271,
    [272] =  gBlinkCmd_272,
    [273] =  gBlinkCmd_273,
    [274] =  gBlinkCmd_274,
    [275] =  gBlinkCmd_275,
    [276] =  gBlinkCmd_276,
    [277] =  gBlinkCmd_277,
    [278] =  gBlinkCmd_278,
    [279] =  gBlinkCmd_279,
};
// clang-format on

INCASM("asm/blink.inc");
