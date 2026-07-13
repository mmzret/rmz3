#include "text.h"

#include "gfx.h"
#include "global.h"

#define CHAR_KANJI 0xF0

#define CHAR_VARIABLE 0xF9
#define CHAR_LF 0xFC

#define ASCII_a 97  // "a"
#define JIS_KANA 160

extern const u8 gFontTall[];
extern const u8 gFontJIS[][TILE_SIZE_4BPP];
extern const u8 gFontBig[];
extern const rgb555 gFontBigPal[16 * 6];

// タイルID
//  736.. gFontTall と gFontBig のための領域 (使う文字だけ重複なしで動的にロード)
//  896.. gFontJIS の カタカナ
//  960.. gFontJIS の ASCII(正確にはASCII文字の0x20..5F)
#define GLYPH_TILEID 736
#define JIS_KANA_TILEID 896  // 0x7000 / TILE_SIZE_4BPP, ◻︎。「」、・ヲァィゥェォ ...
#define ASCII_TILEID 960     // 0x7800 / TILE_SIZE_4BPP printable ASCII (32..96)

static s32 printStringWithLen(u8 start_x8, u8 start_y8, char_t* s, u16 len);

/**
 * @brief gFontTall と gFontJIS のパレット (赤文字含む)
 * @note ゲーム中、 BGP0 はこのパレット固定と思われる
 */
static const ALIGNED(4) rgb555 sBGP0[16] = {
    RGB_BLACK, RGBg_WHITE, RGBg(14, 14, 14), RGBg(1, 1, 1), RGBg(31, 16, 16), RGBg(31, 31, 10), RGBg(12, 31, 16), RGBg(0, 20, 7), RGBg(16, 8, 8), RGBg(19, 31, 28), RGBg(10, 20, 29), RGBg(10, 10, 20), RGBg(28, 7, 10), RGBg(23, 9, 1), RGBg(13, 4, 4), RGBg(21, 21, 19),
};  // 0x080FF15C

void InitTextPrinter(void* tilemap) {
  gTextPrinter.tilemap = tilemap;
  gTextPrinter.variable = &gTerminateCharCode;
  gTextPrinter.startX = 0;
  gTextPrinter.endX = 30;
  gTextPrinter.startY = 0;
  gTextPrinter.endY = 22;
  LoadAsciiBold();
}

// 0x080e9730
void LoadAsciiBold(void) {
  u8 val;
  CpuFastCopy(gFontJIS, (void*)(VRAM + CHAR_BASE(0) + (ASCII_TILEID * TILE_SIZE_4BPP)), 64 * TILE_SIZE_4BPP);
  val = 0;
  CpuFastCopy(sBGP0, gPaletteManager.buf, 32);
  gTextPrinter.startX = val;  // 0
  gTextPrinter.endX = 30;
  gTextPrinter.startY = 0;
  gTextPrinter.endY = 22;
  ResetCharTiles();
}

// 0x080e97a4
NON_MATCH void ResetCharTiles(void) {
#if MODERN
  s32 i;
  GlyphNode* c;
  gTextPrinter.freelist = NULL;
  for (i = 79; i >= 0; i--) {
    c = &gTextPrinter.glyphBuffer[i];
    c->tileID = (GLYPH_TILEID + (79 * 2)) - (79 - i) * 2;
    c->next = gTextPrinter.freelist;
    gTextPrinter.freelist = c;
  }
  gTextPrinter.cache = gTextPrinter.cur = NULL;
  gTextPrinter.len = 0;
#else
  INCCODE("asm/wip/ResetCharTiles.inc");
#endif
}

void LoadJISKana(void) {
  const void* src = &gFontJIS[64];
  void* dst = (void*)(VRAM + CHAR_BASE(0) + (JIS_KANA_TILEID * TILE_SIZE_4BPP));
  CpuFastCopy(src, dst, 64 * TILE_SIZE_4BPP);
}

/**
 * @brief gFontBigPal を BGP2 にロードする, タイトル画面、ゲームオーバー、ゲームクリア時に使用
 * @note 0x080e981c
 */
void FUN_080e981c(void) {
  gTextPrinter.fontBigPalID = 2;
  CpuFastCopy(gFontBigPal, &gPaletteManager.buf[16 * 2], sizeof(gFontBigPal));
}

/**
 * @brief gFontBigPal を BGP10 にロードする, ミニゲームのときのみ使用
 * @note 0x080e9840
 */
void FUN_080e9840(void) {
  gTextPrinter.fontBigPalID = 10;
  CpuFastCopy(gFontBigPal, &gPaletteManager.buf[16 * 10], sizeof(gFontBigPal));
}

/**
 * @brief 毎フレーム、gTextPrinter の文字列を全て描画する
 * @note 0x080e9864
 */
WIP void PrintAllStrings(void) {
#ifdef ALWAYS_FALSE
  s32 i;

  // cur にあるグリフ (前回の PrintAllStrings で使ったグリフ) を全て cache に移動する
  GlyphNode* node = gTextPrinter.cur;
  while (node != NULL) {
    GlyphNode* next = node->next;
    node->next = gTextPrinter.cache;
    gTextPrinter.cache = node;
    node = next;
  }
  gTextPrinter.cur = NULL;

  for (i = 0; i < gTextPrinter.len; i++) {
    printStringWithLen(gTextPrinter.x8[i], gTextPrinter.y8[i], gTextPrinter.strings[i], gTextPrinter.progress[i]);
  }
  gTextPrinter.len = 0;
#else
  INCCODE("asm/wip/PrintAllStrings.inc");
#endif
}

/**
 * @brief まだVRAMにロードされていないグリフ(= GlyphNode.tileID の bit15 が1)をVRAMにロードする
 * @note 0x080e98ec
 */
NON_MATCH void LoadGlyphTiles(void) {
#if MODERN
  GlyphNode* node = gTextPrinter.cur;
  while (node != NULL) {
    if (node->tileID & GLYPH_TILE_NOT_LOADED) {
      node->tileID &= ~GLYPH_TILE_NOT_LOADED;
      {
        const Glyph glyph = node->c;
        void* vram = (void*)(VRAM + CHAR_BASE(0));
        if (glyph < 0x200) {  // gFontTall (normal, BGP0)
          u32 offset = ((glyph & 0xFFF0) * (TILE_SIZE_4BPP * 2)) + ((glyph & 0xF) * TILE_SIZE_4BPP);
          CpuFastCopy(&gFontTall[offset], vram + (node->tileID * TILE_SIZE_4BPP), TILE_SIZE_4BPP);
          CpuFastCopy(&gFontTall[offset + (16 * TILE_SIZE_4BPP)], (vram + (node->tileID * TILE_SIZE_4BPP)) + TILE_SIZE_4BPP, TILE_SIZE_4BPP);
        } else if (glyph < 0x400) {  // gFontTall+Red (BGP0, パレットを変えずに4bppの色番号を変えることで赤くしている)
          u16 i;
          const u8* src = &gFontTall[((glyph & 0x1F0) * (TILE_SIZE_4BPP * 2)) + ((glyph & 0xF) * TILE_SIZE_4BPP)];
          u32* dst = vram + (node->tileID * TILE_SIZE_4BPP);
          for (i = 0; i < 8; i++) {
            *dst++ = (*((u32*)src)) << 2;
            src += 4;
          }
          src += 15 * TILE_SIZE_4BPP;
          for (i = 0; i < 8; i++) {
            *dst++ = (*((u32*)src)) << 2;
            src += 4;
          }
        } else {                           // gFontBig
          if ((glyph & (1 << 11)) == 0) {  // 左半分
            u32 offset = ((glyph & 0x1F0) * (TILE_SIZE_4BPP * 4)) + ((glyph & 0xF) * (TILE_SIZE_4BPP * 2));
            CpuFastCopy(&gFontBig[offset], vram + (node->tileID * TILE_SIZE_4BPP), TILE_SIZE_4BPP);
            CpuFastCopy(&gFontBig[offset + (32 * TILE_SIZE_4BPP)], (vram + (node->tileID * TILE_SIZE_4BPP)) + TILE_SIZE_4BPP, TILE_SIZE_4BPP);
          } else {  // 右半分
            u32 offset = ((glyph & 0x1F0) * (TILE_SIZE_4BPP * 4)) + ((glyph & 0xF) * (TILE_SIZE_4BPP * 2));
            CpuFastCopy(&gFontBig[offset + TILE_SIZE_4BPP], vram + (node->tileID * TILE_SIZE_4BPP), TILE_SIZE_4BPP);
            CpuFastCopy(&gFontBig[offset + (32 * TILE_SIZE_4BPP) + TILE_SIZE_4BPP], (vram + (node->tileID * TILE_SIZE_4BPP)) + TILE_SIZE_4BPP, TILE_SIZE_4BPP);
          }
        }
      }
    }
    node = node->next;
  }
#else
  INCCODE("asm/wip/LoadGlyphTiles.inc");
#endif
}

// Get string character count (not bytesize)
s16 getStringLength(char_t* s) {
  s16 len = 0;
  for (; *s < CHAR_NEXT; s++) {
    if (*s == CHAR_VARIABLE) len += getStringLength(gTextPrinter.variable);
    if (*s < CHAR_KANJI) len++;  // バイト数ではなく文字数を数える
  }
  return len;
}

static s16 Unused_GetLineCount(char_t* s) {
  s16 line = 1;
  for (; *s < CHAR_NEXT; s++) {
    if (*s == CHAR_LF) line++;
  }
  return line;
}

void PrintString(const char_t* s, u32 x8, u32 y8) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    gTextPrinter.strings[gTextPrinter.len] = (char_t*)s;
    gTextPrinter.x8[gTextPrinter.len] = x8;
    gTextPrinter.y8[gTextPrinter.len] = y8;
    gTextPrinter.progress[gTextPrinter.len] = -1;
    gTextPrinter.len++;
  }
}

void text_080e9b40(const char_t* s, u32 x8, u32 y8, u16 count) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    gTextPrinter.strings[gTextPrinter.len] = (char_t*)s;
    gTextPrinter.x8[gTextPrinter.len] = x8;
    gTextPrinter.y8[gTextPrinter.len] = y8;
    gTextPrinter.progress[gTextPrinter.len] = count;
    gTextPrinter.len++;
  }
}

// 文字列のうち、 rowStart行 から rowEnd行 までを描画
void PrintRows(char_t* s, u32 x8, u32 y8, u16 rowStart, u16 rowEnd) {
  if (gTextPrinter.len < MAX_STRING_COUNT) {
    u16 line = 0;
    for (; (line < rowStart) && (*s < CHAR_NEXT); s++) {
      if (*s == CHAR_LF) line++;
    }

    if (*s < CHAR_NEXT) {
      u16 len;
      gTextPrinter.strings[gTextPrinter.len] = s;
      gTextPrinter.x8[gTextPrinter.len] = x8;
      gTextPrinter.y8[gTextPrinter.len] = y8;

      len = 0;
      for (; (line < rowEnd) && (*s < CHAR_NEXT); s++) {
        if (*s == CHAR_VARIABLE) len += getStringLength(gTextPrinter.variable);
        if (*s < CHAR_KANJI) len++;
        if (*s == CHAR_LF) line++;
      }
      gTextPrinter.progress[gTextPrinter.len] = len;
      gTextPrinter.len++;
    }
  }
}

// 文字列を skipBytesize だけ読み飛ばす
char_t* SkipString(char_t* s, s32 skipBytesize) {
  for (; (*s < CHAR_NEXT) && (skipBytesize != 0); s++) {
    if (*s < CHAR_KANJI) {
      skipBytesize--;

    } else if (*s == CHAR_KANJI) {
      s++;
      skipBytesize--;

    } else if (*s < CHAR_VARIABLE) {
      s++;
    }
  }
  return s;
}

/**
 * @brief Print JIS string
 * @note 0x080e9cb4
 */
void PrintJISString(const char_t* s, u32 x8, u32 y8) {
  u16* dst = gTextPrinter.tilemap;
  if (y8 < 32) {
    dst = &dst[x8 + (y8 * 32)];
    while (*s != 0) {
      if (x8 > 31) return;

      if (*s < ASCII_a) {
        *dst++ = (ASCII_TILEID - 32) + *s++;  // 0..96: ASCII -> そのまま表示する (0..32 は来ないことを前提とする)
      } else if (*s < JIS_KANA) {
        *dst++ = ((ASCII_TILEID - 32) - 32) + *s++;  // 97..159: ASCII小文字 -> 大文字として表示する
      } else {
        *dst++ = (JIS_KANA_TILEID - 160) + *s++;  // 160..255: JISカナ -> そのまま表示する
      }
    }
  }
}

// 0x080e9d04
void PrintMinigameNumber(s32 score, u16 x8, u16 y8) {
  s16 i;
  char_t s[17];  // 符号 + 15桁 + 終端
  s32 val = score;
  if (score < 0) val = -score;
  s[16] = '\0';

  for (i = 15; i > 0; i--) {
    s[i] = '0' + (val % 10);
    if (val < 10) break;
    val /= 10;
  }
  if (score < 0) s[--i] = '-';  // sign
  PrintJISString(&s[i], x8 - 15 + i, y8);
};

NAKED void unused_080e9d94(s32 r0, u16 r1, u16 r2) { INCCODE("asm/unused/unused_080e9d94.inc"); };

// 0x080e9e00
NAKED static s32 printStringWithLen(u8 start_x8, u8 start_y8, char_t* s, u16 len) {
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
	bl AllocateGlyph\n\
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
	bl AllocateGlyph\n\
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

// 0x080e9fe0
static GlyphNode* AllocateGlyph(Glyph glyph) {
  GlyphNode* node;

  {
    // このフレームで使用が確定している文字の中に、同じ文字があればそれを返す
    node = gTextPrinter.cur;
    while (node != NULL) {
      if ((glyph & 0xFFF) == (node->c & 0xFFF)) return node;
      node = node->next;
    }
  }
  {
    // キャッシュ(前フレームで使用した文字)の中に、同じ文字があればそれを cur に移動して返す
    void* tail = &gTextPrinter.cache;
    node = gTextPrinter.cache;
    while (node != NULL) {
      if ((glyph & 0xFFF) == (node->c & 0xFFF)) {
        *((GlyphNode**)tail) = node->next;
        node->next = gTextPrinter.cur;
        gTextPrinter.cur = node;
        return node;
      }
      tail = node;
      node = node->next;
    }
  }

  // バッファに空きがないなら、キャッシュを解放して空きを作る
  if (gTextPrinter.freelist == NULL) {
    gTextPrinter.freelist = gTextPrinter.cache;
    if (gTextPrinter.cache == NULL) return NULL;  // キャッシュを解放しても空きがない場合は失敗
    gTextPrinter.cache = NULL;                    // キャッシュを解放
  }

  node = gTextPrinter.freelist;
  gTextPrinter.freelist = node->next;
  node->next = gTextPrinter.cur;
  gTextPrinter.cur = node;
  node->tileID |= GLYPH_TILE_NOT_LOADED;
  return node;
}
