#include "text.h"

#include "gfx.h"
#include "global.h"

#define FONT_BOLD 0x7800

static s32 printStringWithLen(u8 startX, u8 startY, char_t *s, u16 len);

void InitTextPrinter(u32 *bg0) {
  gTextPrinter.bg0 = (tile_id_t *)bg0;
  gTextPrinter.inserted = &gTerminateCharCode;
  gTextPrinter.startX = 0;
  gTextPrinter.endX = 30;
  gTextPrinter.startY = 0;
  gTextPrinter.endY = 22;
  text_080e9730();
}

void text_080e9730(void) {
  static const ALIGNED(4) u16 sDefaultBGPalette[SLOT_4BPP] = {
      0x0000, 0xFFFF, 0xB9CE, 0x8421, 0xC21F, 0xABFF, 0xC3EC, 0x9E80, 0xA110, 0xF3F3, 0xF68A, 0xD14A, 0xA8FC, 0x8537, 0x908D, 0xCEB5,
  };

  u8 val;
  CpuFastCopy(gFontBold, (void *)(CHAR_BASE(0) + VRAM + FONT_BOLD), 2048);
  val = 0;
  CpuFastCopy(sDefaultBGPalette, gPaletteManager.buf, 32);
  gTextPrinter.startX = val;
  gTextPrinter.endX = 30;
  gTextPrinter.startY = 0;
  gTextPrinter.endY = 22;
  ResetCharTiles();
}

WIP void ResetCharTiles(void) {
#if MODERN
  struct CharTile *tile;
  gTextPrinter.freelist = NULL;
  for (s32 i = 79; i >= 0; i--) {
    tile = &gTextPrinter.tilelist[i];
    tile->tileID = 894 - (79 - i) * 2;
    tile->next = gTextPrinter.freelist;
    gTextPrinter.freelist = tile;
  }
  gTextPrinter.used = gTextPrinter.cur = NULL;
  gTextPrinter.len = 0;
#else
  INCCODE("asm/wip/ResetCharTiles.inc");
#endif
}

void LoadKatakanaBold(void) {
  const void *src = &gFontBold[0x40];
  const u16 charBase = (*((u16 *)&gVideoRegBuffer.bgcnt[0]) & 0xc) << 12;
  CpuFastCopy(src, (void *)(VRAM + 0x7000 + charBase), 2048);
}

void FUN_080e981c(void) {
  gTextPrinter.unk_002 = 2;
  CpuFastCopy(&gFontPalette[0], &gPaletteManager.buf[32], ARRAY_COUNT(gFontPalette) * 2);
}

void FUN_080e9840(void) {
  gTextPrinter.unk_002 = 10;
  CpuFastCopy(&gFontPalette[0], &gPaletteManager.buf[160], ARRAY_COUNT(gFontPalette) * 2);
}

/*
  毎フレーム、gTextPrinter の文字列を全て描画する
*/
NAKED void PrintAllStrings(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r1, _080E98E4 @ =gTextPrinter\n\
	movs r2, #0xb1\n\
	lsls r2, r2, #3\n\
	adds r0, r1, r2\n\
	ldr r2, [r0]\n\
	ldr r7, _080E98E8 @ =0x0000058C\n\
	adds r1, r1, r7\n\
	cmp r2, #0\n\
	beq _080E9888\n\
	ldr r3, [r1]\n\
_080E987A:\n\
	ldr r0, [r2]\n\
	str r3, [r2]\n\
	adds r3, r2, #0\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _080E987A\n\
	str r3, [r1]\n\
_080E9888:\n\
	ldr r3, _080E98E4 @ =gTextPrinter\n\
	movs r1, #0xb1\n\
	lsls r1, r1, #3\n\
	adds r0, r3, r1\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	movs r5, #0\n\
	movs r2, #4\n\
	ldrsh r0, [r3, r2]\n\
	cmp r5, r0\n\
	bge _080E98D6\n\
	adds r6, r3, #0\n\
_080E98A0:\n\
	movs r7, #0xc4\n\
	lsls r7, r7, #1\n\
	adds r0, r6, r7\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	movs r2, #0xf4\n\
	lsls r2, r2, #1\n\
	adds r1, r6, r2\n\
	adds r1, r5, r1\n\
	ldrb r1, [r1]\n\
	lsls r2, r5, #2\n\
	adds r3, r6, #0\n\
	adds r3, #8\n\
	adds r2, r2, r3\n\
	ldr r2, [r2]\n\
	lsls r3, r5, #1\n\
	adds r7, #0xc0\n\
	adds r4, r6, r7\n\
	adds r3, r3, r4\n\
	ldrh r3, [r3]\n\
	bl printStringWithLen\n\
	adds r5, #1\n\
	movs r1, #4\n\
	ldrsh r0, [r6, r1]\n\
	cmp r5, r0\n\
	blt _080E98A0\n\
_080E98D6:\n\
	ldr r1, _080E98E4 @ =gTextPrinter\n\
	movs r0, #0\n\
	strh r0, [r1, #4]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E98E4: .4byte gTextPrinter\n\
_080E98E8: .4byte 0x0000058C\n\
 .syntax divided\n");
}

NAKED void FUN_080e98ec(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r0, _080E996C @ =gTextPrinter\n\
	movs r1, #0xb1\n\
	lsls r1, r1, #3\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	cmp r6, #0\n\
	bne _080E9906\n\
	b _080E9A60\n\
_080E9906:\n\
	movs r2, #0xf\n\
	mov r8, r2\n\
	ldr r0, _080E9970 @ =gFont\n\
	mov sl, r0\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #1\n\
	mov sb, r1\n\
_080E9914:\n\
	ldrh r1, [r6, #6]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E9924\n\
	b _080E9A58\n\
_080E9924:\n\
	subs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	strh r0, [r6, #6]\n\
	ldrh r2, [r6, #4]\n\
	ldr r0, _080E9974 @ =gVideoRegBuffer+4\n\
	ldrh r1, [r0]\n\
	movs r0, #0xc\n\
	ands r0, r1\n\
	lsls r0, r0, #0xc\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	adds r7, r0, r1\n\
	ldr r0, _080E9978 @ =0x000001FF\n\
	cmp r2, r0\n\
	bhi _080E9984\n\
	ldr r1, _080E997C @ =0x0000FFF0\n\
	adds r0, r1, #0\n\
	adds r4, r2, #0\n\
	ands r4, r0\n\
	lsls r4, r4, #6\n\
	mov r0, r8\n\
	ands r2, r0\n\
	lsls r0, r2, #5\n\
	adds r4, r4, r0\n\
	mov r1, sl\n\
	adds r0, r4, r1\n\
	ldrh r1, [r6, #6]\n\
	lsls r1, r1, #5\n\
	adds r1, r7, r1\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	ldr r2, _080E9980 @ =0x080FF37C\n\
	b _080E9A04\n\
	.align 2, 0\n\
_080E996C: .4byte gTextPrinter\n\
_080E9970: .4byte gFont\n\
_080E9974: .4byte gVideoRegBuffer+4\n\
_080E9978: .4byte 0x000001FF\n\
_080E997C: .4byte 0x0000FFF0\n\
_080E9980: .4byte gFont+(32*16)\n\
_080E9984:\n\
	ldr r0, _080E99D0 @ =0x000003FF\n\
	cmp r2, r0\n\
	bhi _080E99D4\n\
	adds r0, r2, #0\n\
	mov r1, sb\n\
	ands r0, r1\n\
	lsls r0, r0, #6\n\
	mov r1, r8\n\
	ands r2, r1\n\
	lsls r1, r2, #5\n\
	adds r0, r0, r1\n\
	mov r2, sl\n\
	adds r1, r0, r2\n\
	ldrh r0, [r6, #6]\n\
	lsls r0, r0, #5\n\
	adds r3, r7, r0\n\
	movs r2, #0\n\
_080E99A6:\n\
	ldm r1!, {r0}\n\
	lsls r0, r0, #2\n\
	stm r3!, {r0}\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #7\n\
	bls _080E99A6\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #1\n\
	adds r1, r1, r0\n\
	movs r2, #0\n\
_080E99BE:\n\
	ldm r1!, {r0}\n\
	lsls r0, r0, #2\n\
	stm r3!, {r0}\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #7\n\
	bls _080E99BE\n\
	b _080E9A58\n\
	.align 2, 0\n\
_080E99D0: .4byte 0x000003FF\n\
_080E99D4:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	adds r1, r0, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E9A20\n\
	adds r4, r2, #0\n\
	mov r1, sb\n\
	ands r4, r1\n\
	lsls r4, r4, #7\n\
	mov r0, r8\n\
	ands r2, r0\n\
	lsls r0, r2, #6\n\
	adds r4, r4, r0\n\
	ldr r1, _080E9A18 @ =gFontBig\n\
	adds r0, r4, r1\n\
	ldrh r1, [r6, #6]\n\
	lsls r1, r1, #5\n\
	adds r1, r7, r1\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	ldr r2, _080E9A1C @ =0x08106E3C\n\
_080E9A04:\n\
	adds r4, r4, r2\n\
	ldrh r1, [r6, #6]\n\
	lsls r1, r1, #5\n\
	adds r1, #0x20\n\
	adds r1, r7, r1\n\
	adds r0, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	b _080E9A58\n\
	.align 2, 0\n\
_080E9A18: .4byte gFontBig\n\
_080E9A1C: .4byte gFontBig+1024\n\
_080E9A20:\n\
	adds r4, r2, #0\n\
	mov r0, sb\n\
	ands r4, r0\n\
	lsls r4, r4, #7\n\
	mov r1, r8\n\
	ands r2, r1\n\
	lsls r0, r2, #6\n\
	adds r4, r4, r0\n\
	ldr r5, _080E9A70 @ =0x08106A5C\n\
	adds r0, r4, r5\n\
	ldrh r1, [r6, #6]\n\
	lsls r1, r1, #5\n\
	adds r1, r7, r1\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r5, r5, r2\n\
	adds r4, r4, r5\n\
	ldrh r1, [r6, #6]\n\
	lsls r1, r1, #5\n\
	adds r1, #0x20\n\
	adds r1, r7, r1\n\
	adds r0, r4, #0\n\
	movs r2, #8\n\
	bl CpuFastSet\n\
_080E9A58:\n\
	ldr r6, [r6]\n\
	cmp r6, #0\n\
	beq _080E9A60\n\
	b _080E9914\n\
_080E9A60:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E9A70: .4byte gFontBig+32\n\
 .syntax divided\n");
}

s16 getStringLength(char_t *s) {
  s16 len = 0;
  for (; *s < CHAR_NEXT; s++) {
    if (*s == CHAR_INSERT) {  // Insert
      len += getStringLength(gTextPrinter.inserted);
    }
    if (*s < 0xF0) {
      len++;
    }
  }
  return len;
}

// Unused
static s16 GetLineCount(char_t *s) {
  s16 line = 1;
  for (; *s < CHAR_NEXT; s++) {
    if (*s == CHAR_LF) {
      line++;
    }
  }
  return line;
}

void PrintString(const char_t *s, u32 x, u32 y) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    gTextPrinter.strings[gTextPrinter.len] = (char_t *)s;
    gTextPrinter.x[gTextPrinter.len] = x;
    gTextPrinter.y[gTextPrinter.len] = y;
    gTextPrinter.progress[gTextPrinter.len] = -1;
    gTextPrinter.len++;
  }
}

void text_080e9b40(const char_t *s, u32 x, u32 y, u16 count) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    gTextPrinter.strings[gTextPrinter.len] = (char_t *)s;
    gTextPrinter.x[gTextPrinter.len] = x;
    gTextPrinter.y[gTextPrinter.len] = y;
    gTextPrinter.progress[gTextPrinter.len] = count;
    gTextPrinter.len++;
  }
}

// 文字列のうち、 rowStart行 から rowEnd行 までを描画
void PrintRows(char_t *s, u32 x, u32 y, u16 rowStart, u16 rowEnd) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    u16 line = 0;
    for (; (line < rowStart) && (*s < CHAR_NEXT); s++) {
      if (*s == CHAR_LF) {
        line++;
      }
    }

    if (*s < CHAR_NEXT) {
      u16 len;
      gTextPrinter.strings[gTextPrinter.len] = s;
      gTextPrinter.x[gTextPrinter.len] = x;
      gTextPrinter.y[gTextPrinter.len] = y;

      len = 0;
      for (; (line < rowEnd) && (*s < CHAR_NEXT); s++) {
        if (*s == CHAR_INSERT) {
          len += getStringLength(gTextPrinter.inserted);
        }
        if (*s < CHAR_KANJI) {
          len++;
        }
        if (*s == CHAR_LF) {
          line++;
        }
      }
      gTextPrinter.progress[gTextPrinter.len] = len;
      gTextPrinter.len++;
    }
  }
}

// 文字列を skipBytesize だけ読み飛ばす
char_t *SkipString(char_t *s, s32 skipBytesize) {
  for (; (*s < CHAR_NEXT) && (skipBytesize != 0); s++) {
    if (*s < CHAR_KANJI) {
      skipBytesize--;

    } else if (*s == CHAR_KANJI) {
      s++;
      skipBytesize--;

    } else if (*s < CHAR_INSERT) {
      s++;
    }
  }
  return s;
}

// x, y is 8x8 tile unit
WIP void PrintUnicodeString(u8 *s, u32 x, u32 y) {
#if MODERN
  if (y < 32) {
    tile_id_t *bg0 = &gTextPrinter.bg0[x + (y * 32)];
    for (; *s != 0; s++, bg0++) {
      if (x < 32) {
        if (*s < UNICODE_A) {
          *bg0 = 928 + *s;
        } else if (*s < UNICODE_NBSP) {
          *bg0 = 896 + *s;
        } else {
          *bg0 = 736 + *s;
        }
      }
    }
  }
#else
  INCCODE("asm/wip/PrintUnicodeString.inc");
#endif
}

NAKED void minigame_str_080e9d04(s32 r0, u16 r1, u16 r2) { INCCODE("asm/todo/minigame_str_080e9d04.inc"); };

#if MODERN == 0
NAKED void unused_080e9d94(s32 r0, u16 r1, u16 r2) { INCCODE("asm/unused/unused_080e9d94.inc"); };
#endif

NAKED static s32 printStringWithLen(u8 startX, u8 startY, char_t *s, u16 len) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r7, r2, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	mov r8, r3\n\
	str r6, [sp, #4]\n\
	ldr r2, _080E9E4C @ =gTextPrinter\n\
	lsls r0, r1, #5\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	ldr r1, [r2]\n\
	adds r5, r1, r0\n\
	str r5, [sp, #8]\n\
	movs r0, #0\n\
	str r0, [sp, #0xc]\n\
	ldrb r0, [r7]\n\
	cmp r0, #0xfc\n\
	bls _080E9E3A\n\
	b _080E9FC6\n\
_080E9E3A:\n\
	cmp r3, #0\n\
	bne _080E9E40\n\
	b _080E9FC6\n\
_080E9E40:\n\
	cmp r0, #0xef\n\
	bhi _080E9E50\n\
	ldrb r4, [r7]\n\
	ldr r1, [sp, #0xc]\n\
	orrs r4, r1\n\
	b _080E9EEC\n\
	.align 2, 0\n\
_080E9E4C: .4byte gTextPrinter\n\
_080E9E50:\n\
	cmp r0, #0xf0\n\
	bne _080E9E62\n\
	adds r7, #1\n\
	ldrb r0, [r7]\n\
	adds r4, r0, #0\n\
	adds r4, #0xf0\n\
	ldr r2, [sp, #0xc]\n\
	orrs r4, r2\n\
	b _080E9EEC\n\
_080E9E62:\n\
	cmp r0, #0xf1\n\
	bne _080E9E6C\n\
	movs r3, #0\n\
	str r3, [sp, #0xc]\n\
	b _080E9FB6\n\
_080E9E6C:\n\
	cmp r0, #0xf2\n\
	bne _080E9E78\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	str r0, [sp, #0xc]\n\
	b _080E9FB6\n\
_080E9E78:\n\
	cmp r0, #0xf7\n\
	bne _080E9E9C\n\
	adds r7, #1\n\
	ldr r0, _080E9E98 @ =gTextPrinter\n\
	ldrh r0, [r0, #6]\n\
	ldrb r1, [r7]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xc\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
	b _080E9FB6\n\
	.align 2, 0\n\
_080E9E98: .4byte gTextPrinter\n\
_080E9E9C:\n\
	cmp r0, #0xfc\n\
	bne _080E9EB4\n\
	ldr r5, [sp, #8]\n\
	adds r5, #0x80\n\
	str r5, [sp, #8]\n\
	ldr r0, [sp]\n\
	adds r0, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp]\n\
	ldr r6, [sp, #4]\n\
	b _080E9FB6\n\
_080E9EB4:\n\
	cmp r0, #0xf9\n\
	bne _080E9EE4\n\
	ldr r3, _080E9EE0 @ =0x020308A4\n\
	ldr r2, [r3]\n\
	adds r0, r6, #0\n\
	ldr r1, [sp]\n\
	mov r3, r8\n\
	bl printStringWithLen\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0\n\
	beq _080E9FC6\n\
	mov r1, r8\n\
	subs r0, r1, r2\n\
	lsls r1, r0, #1\n\
	adds r5, r5, r1\n\
	adds r0, r6, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	mov r8, r2\n\
	b _080E9FB6\n\
	.align 2, 0\n\
_080E9EE0: .4byte 0x020308A4\n\
_080E9EE4:\n\
	cmp r0, #0xf8\n\
	bhi _080E9FB6\n\
	adds r7, #1\n\
	b _080E9FB6\n\
_080E9EEC:\n\
	ldr r2, _080E9F30 @ =gTextPrinter\n\
	movs r3, #0xb3\n\
	lsls r3, r3, #3\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	subs r0, r6, r0\n\
	adds r3, #2\n\
	adds r1, r2, r3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bhs _080E9F1E\n\
	ldr r1, _080E9F34 @ =0x00000599\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	ldr r3, [sp]\n\
	subs r0, r3, r0\n\
	ldr r3, _080E9F38 @ =0x0000059B\n\
	adds r1, r2, r3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _080E9F40\n\
_080E9F1E:\n\
	adds r5, #2\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r0, _080E9F3C @ =0x000003FF\n\
	cmp r4, r0\n\
	bls _080E9FAC\n\
	b _080E9FA4\n\
	.align 2, 0\n\
_080E9F30: .4byte gTextPrinter\n\
_080E9F34: .4byte 0x00000599\n\
_080E9F38: .4byte 0x0000059B\n\
_080E9F3C: .4byte 0x000003FF\n\
_080E9F40:\n\
	adds r0, r4, #0\n\
	bl getFreeCharTile\n\
	cmp r0, #0\n\
	beq _080E9FC6\n\
	strh r4, [r0, #4]\n\
	adds r3, r5, #0\n\
	adds r3, #0x40\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	mov sl, r1\n\
	adds r1, r4, #0\n\
	mov r2, sl\n\
	ands r1, r2\n\
	ldrh r2, [r0, #6]\n\
	ldr r0, _080E9FD8 @ =0x00000FFF\n\
	mov sb, r0\n\
	ands r0, r2\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	adds r1, #1\n\
	strh r1, [r3]\n\
	adds r5, #2\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r1, _080E9FDC @ =0x000003FF\n\
	cmp r4, r1\n\
	bls _080E9FAC\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r2, #0\n\
	orrs r4, r0\n\
	adds r0, r4, #0\n\
	bl getFreeCharTile\n\
	cmp r0, #0\n\
	beq _080E9FC6\n\
	strh r4, [r0, #4]\n\
	adds r3, r5, #0\n\
	adds r3, #0x40\n\
	mov r1, sl\n\
	ands r1, r4\n\
	ldrh r2, [r0, #6]\n\
	mov r0, sb\n\
	ands r0, r2\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	adds r1, #1\n\
	strh r1, [r3]\n\
_080E9FA4:\n\
	adds r5, #2\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
_080E9FAC:\n\
	mov r0, r8\n\
	subs r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov r8, r0\n\
_080E9FB6:\n\
	adds r7, #1\n\
	ldrb r0, [r7]\n\
	cmp r0, #0xfc\n\
	bhi _080E9FC6\n\
	mov r3, r8\n\
	cmp r3, #0\n\
	beq _080E9FC6\n\
	b _080E9E40\n\
_080E9FC6:\n\
	mov r0, r8\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080E9FD8: .4byte 0x00000FFF\n\
_080E9FDC: .4byte 0x000003FF\n\
 .syntax divided\n");
}

NAKED static struct CharTile *getFreeCharTile(u16 styledChar) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	ldr r1, _080EA048 @ =gTextPrinter\n\
	movs r2, #0xb1\n\
	lsls r2, r2, #3\n\
	adds r0, r1, r2\n\
	ldr r2, [r0]\n\
	adds r7, r1, #0\n\
	cmp r2, #0\n\
	beq _080EA00C\n\
	ldr r4, _080EA04C @ =0x00000FFF\n\
	adds r3, r6, #0\n\
	ands r3, r4\n\
_080E9FFC:\n\
	ldrh r1, [r2, #4]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r3, r0\n\
	beq _080EA08C\n\
	ldr r2, [r2]\n\
	cmp r2, #0\n\
	bne _080E9FFC\n\
_080EA00C:\n\
	ldr r5, _080EA050 @ =0x0203089C\n\
	ldr r2, [r5]\n\
	cmp r2, #0\n\
	beq _080EA02C\n\
	ldr r4, _080EA04C @ =0x00000FFF\n\
	adds r3, r6, #0\n\
	ands r3, r4\n\
_080EA01A:\n\
	ldrh r1, [r2, #4]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r3, r0\n\
	beq _080EA054\n\
	adds r5, r2, #0\n\
	ldr r2, [r2]\n\
	cmp r2, #0\n\
	bne _080EA01A\n\
_080EA02C:\n\
	movs r0, #0xb2\n\
	lsls r0, r0, #3\n\
	adds r3, r7, r0\n\
	ldr r1, [r3]\n\
	cmp r1, #0\n\
	bne _080EA068\n\
	subs r0, #4\n\
	adds r2, r7, r0\n\
	ldr r0, [r2]\n\
	str r0, [r3]\n\
	cmp r0, #0\n\
	bne _080EA066\n\
	movs r0, #0\n\
	b _080EA08E\n\
	.align 2, 0\n\
_080EA048: .4byte gTextPrinter\n\
_080EA04C: .4byte 0x00000FFF\n\
_080EA050: .4byte 0x0203089C\n\
_080EA054:\n\
	ldr r0, [r2]\n\
	str r0, [r5]\n\
	movs r3, #0xb1\n\
	lsls r3, r3, #3\n\
	adds r1, r7, r3\n\
	ldr r0, [r1]\n\
	str r0, [r2]\n\
	str r2, [r1]\n\
	b _080EA08C\n\
_080EA066:\n\
	str r1, [r2]\n\
_080EA068:\n\
	movs r0, #0xb2\n\
	lsls r0, r0, #3\n\
	adds r1, r7, r0\n\
	ldr r2, [r1]\n\
	ldr r0, [r2]\n\
	str r0, [r1]\n\
	movs r3, #0xb1\n\
	lsls r3, r3, #3\n\
	adds r1, r7, r3\n\
	ldr r0, [r1]\n\
	str r0, [r2]\n\
	str r2, [r1]\n\
	ldrh r1, [r2, #6]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #8\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2, #6]\n\
_080EA08C:\n\
	adds r0, r2, #0\n\
_080EA08E:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}
