#include "gfx.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "system.h"
#include "text.h"

// 0xF3 val
#define CHAR_WINDOW 0xF3
#define CHAR_ANSWER 0xF4
#define CHAR_F5 0xF5
#define CHAR_F6 0xF6
#define CHAR_TOP 0xFA
#define CHAR_BOTTOM 0xFB

#define MUGSHOT_TILEID 608
#define MSGBOX_TILEID 704

enum TextBank {
  TB_SYSTEM,      // 0
  TB_OPEN_DISK,   // 1
  TB_BANK2,       // 2
  TB_SPACECRAFT,  // 3
};

static const u16* const gTextOffsetTable[20];
extern const char_t gAsciiCaret[];

static void resetTextWindow(TextWindowText* t);
static void setupTextWindow(TextWindowText* t);
static void _UpdateTextWindow(TextWindowText* t);
static bool32 isMugshotChanged(TextWindowText* t);

void ClearTextWindow(void* bgmap) {
  gTextPrinter.startX = 0;
  gTextPrinter.endX = 30;
  gTextPrinter.startY = 0;
  gTextPrinter.endY = 22;
  gTextWindow.frame = 0;
  gTextWindow.buffer = bgmap;
  gTextWindow.text.state.u32 = 0;
  (&gTextWindow.text)->mode = 0;
}

// テキストウィンドウがなくても毎フレーム呼ばれる
void UpdateTextWindow(void) {
  gTextWindow.frame++;
  _UpdateTextWindow(&gTextWindow.text);
}

static void unused_080ea664(void) { gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON; }

static void unused_080ea678(TextID n) {
  TextWindowText* t;
  PrintTextWindow(n, TW_OPTION);
  t = &gTextWindow.text;
  t->flag |= 1;
}

void PrintNormalMessage(TextID n) {
  PrintTextWindow(n, TW_NORMAL);
  return;
}

static const char_t* const gTextTable[20];

// gTextTable[t>>8] + gTextOffsetTable[t>>8][t&0xFF]
static inline char_t* GetText(TextID t) {
  char_t** _table = (char_t**)gTextTable;
  char_t** table = &_table[t >> 8];
  const u16 ofs = (gTextOffsetTable[t >> 8])[t & 0xFF];
  return &((*table)[ofs]);
}

void PrintTextWindow(TextID t, u16 kind) {
  TextWindowText* w = &gTextWindow.text;

  char_t* s = GetText(t);
  if ((t & 0xFF00) == (TB_OPEN_DISK << 8)) {
    if (t == 0x100) {
      PlaySound(SE_GAIN_DISK);
    } else {
      PlaySound(SE_NOTIFICATION);
    }
  }
  w->start = s;
  w->textType = kind;
  resetTextWindow(w);
  setupTextWindow(w);
  if (w->mugshot != 0) {
    (w->state).u32 = TWK_MUGSHOT;
  } else {
    (w->state).u32 = TWK_INLINE;
  }
}

void PrintOptionMessage1(TextID t) {
  TextWindowText* w = &gTextWindow.text;
  w->start = GetText(t);
  w->textType = TW_OPTION;
  if ((w->state).u8[0] == TWK_MUGSHOT) {
    w->next = w->start;
    w->mode = TWM_TYPING;
    (w->state).u8[1] = 5;
  } else {
    resetTextWindow(w);
    setupTextWindow(w);
    if (w->mugshot != 0) {
      (w->state).u32 = TWK_MUGSHOT;
    } else {
      (w->state).u32 = TWK_INLINE;
    }
  }
  w->flag = 1;
}

void PrintOptionMessage2(TextID n) {
  PrintOptionMessage1(n);
  (&gTextWindow.text)->textType = 0;
}

void PrintResultInline(TextID t, bool16 ng) {
  TextWindowText* w = &gTextWindow.text;

  char_t* s = GetText(t);
  if (!ng) {
    PlaySound(SE_NOTIFICATION);
  } else {
    PlaySound(SE_NOT_ALLOWED);
  }
  w->start = (char_t*)s;
  w->textType = 0;
  resetTextWindow(w);
  setupTextWindow(w);
  (w->state).u32 = TWK_UNK3;
}

static void resetTextWindow(TextWindowText* t) {
  t->flag = 0;
  t->mode = TWM_TYPING;
  t->mugshot = 0;
  t->mugshotRight = 0;
  t->optionID = 0;
  t->unk_16 = 0;
  t->y8 = 1;
  t->current = t->start;
  t->next = NULL;
}

/**
 * @note 0x080ea830
 */
static void setupTextWindow(TextWindowText* t) {
  char_t* s = t->current;
  char_t unk_16 = 0xFF;
  char_t c2 = 0xFF;
  t->optional_next = NULL;
  while (*s < CHAR_NEXT) {
    if (*s == CHAR_WINDOW) {
      char_t c = *(++s);
      t->mugshot = c >> 1;
      t->mugshotRight = c & 1;
    } else if (*s == CHAR_F5) {
      s++;
      unk_16 = *s;
    } else if (*s == CHAR_F6) {
      s++;
      c2 = *s;
    } else if (*s == CHAR_TOP) {
      t->y8 = 1;
    } else if (*s == CHAR_BOTTOM) {
      t->y8 = 13;
    }
    s++;
  }

  if (unk_16 != 0xFF) {
    t->unk_16 = unk_16;  // 今の所 必ず 0x09 が来る
    for (s = t->start; *s < 0xFF; s++) {
      if (s[0] == CHAR_ANSWER && s[1] == unk_16) {
        t->next = s + 2;
        break;
      }
    }
    if (*s == 0xFF) t->next = NULL;
  } else {
    t->next = (*s <= CHAR_NEXT) ? ++s : NULL;
  }
  if (c2 != 0xFF) {
    t->optionID = (t->optionID >> 4) | (1 << 4);
    for (s = t->start; *s < 0xFF; s++) {
      if (s[0] == CHAR_ANSWER && s[1] == c2) {
        t->optional_next = s + 2;
        break;
      }
    }
  }
}

// --------------------------------------------

typedef void (*TextFunc)(TextWindowText*);

static void _UpdateTextWindow_0_Nop(TextWindowText* t);
static void _UpdateTextWindow_1_MugshotMessage(TextWindowText* t);
static void _UpdateTextWindow_2_InlineMessage(TextWindowText* t);
static void _UpdateTextWindow_3_Unk3(TextWindowText* t);

/**
 * @note テキストウィンドウがなくても毎フレーム呼ばれる
 * @note 0x080ea8e8
 */
static void _UpdateTextWindow(TextWindowText* t) {
  // clang-format off
  static const TextFunc routine[] = {
    [TWK_NONE]    = _UpdateTextWindow_0_Nop,
    [TWK_MUGSHOT] = _UpdateTextWindow_1_MugshotMessage,
    [TWK_INLINE]  = _UpdateTextWindow_2_InlineMessage,
    [TWK_UNK3]    = _UpdateTextWindow_3_Unk3,
  };  // 0x083767a8
  // clang-format on
  (routine[(t->state).u8[0]])(t);
}

static bool32 isMugshotChanged(TextWindowText* t) {
  char_t* s = t->next;
  bool32 result = FALSE;
  for (; *s < CHAR_NEXT; s++) {
    if (*s == CHAR_WINDOW) {
      s++;
      if (*s != ((t->mugshot << 1) | t->mugshotRight)) {
        result = TRUE;
      }
    }
  }
  return result;
}

static const u32 sVramOffsets[2];  // [mugshot, msgbox]
extern const ColorGraphic gDialogGraphics[];

extern const struct Graphic gGraphic_MsgBox0;

#if MODERN
#define DIALOG_GRAPHIC(base, n) ((void*)&gDialogGraphics[base + n])
#define DIALOG_PALETTE(base, n) ((void*)(&gDialogGraphics[base + n].pal))
#else
#define _gDialogGraphics 0x085a7ec4
#define _gDialogPalettes (0x085a7ec4 + 12)
#define DIALOG_GRAPHIC(base, n) ((void*)(_gDialogGraphics + ((base) * sizeof(ColorGraphic)) + ((n) * sizeof(ColorGraphic))))
#define DIALOG_PALETTE(base, n) ((void*)((_gDialogPalettes + ((base) * sizeof(ColorGraphic))) + ((n) * sizeof(ColorGraphic))))
#endif

/**
 * @brief Load msgbox and mugshot tile data into VRAM
 * @note 0x080ea930
 */
static void LoadWindowTileData(TextWindowText* t, u8 mugshot) {
  // msgbox
  if (gSystemSavedata.msgbox == 0) {
    RequestGraphicTransfer(&gGraphic_MsgBox0, (void*)CHAR_BASE(0) + sVramOffsets[1]);
  } else {
    // e-card: msgbox
    RequestGraphicTransfer(DIALOG_GRAPHIC(57, gSystemSavedata.msgbox), (void*)CHAR_BASE(0) + sVramOffsets[1]);
    LoadPalette(DIALOG_PALETTE(57, gSystemSavedata.msgbox), 0);
  }
  // mugshot
  if ((t->mugshot != NO_MUGSHOT) && (mugshot != 0)) {
    RequestGraphicTransfer(DIALOG_GRAPHIC(0, mugshot), (void*)CHAR_BASE(0) + sVramOffsets[0]);
    LoadPalette(DIALOG_PALETTE(0, mugshot), 32);
  }
}

static const u16 sTilemap_MugshotLeft[];
static const u16 sTilemap_MugshotRight[];

/**
 * @brief Draw mugshot tilemap
 * @note タイルデータは LoadWindowTileData でVRAMにロードする
 * @note 0x080ea9f0
 */
static void DrawMugshot(TextWindowText* t) {
  s16 i;
  u16* bgmap = gTextWindow.buffer;

  if (gTextWindow.text.state.u8[0] == TWK_MUGSHOT && (t->mugshot != NO_MUGSHOT)) {
    if (t->mugshotRight == 0) {
      bgmap += 1 + (t->y8 * 32);
      for (i = 0; i < 6; i++, bgmap += 32) {
        CopyMemory((void*)&sTilemap_MugshotLeft[6 * i], bgmap, 6 * sizeof(u16));
      }
    } else {
      bgmap += 23 + (t->y8 * 32);
      for (i = 0; i < 6; i++, bgmap += 32) {
        CopyMemory((void*)&sTilemap_MugshotRight[6 * i], bgmap, 6 * sizeof(u16));
      }
    }
  }
}

/**
 * @brief (多分)通常のテキストウィンドウ を描画する
 * @param roundness ウィンドウの角の丸み
 * @note 0x080eaa7c
 */
NAKED void text_080eaa7c(TextWindowText* t, u16 roundness) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	mov sl, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r2, r1, #0x10\n\
	ldrb r0, [r0, #5]\n\
	str r0, [sp, #8]\n\
	ldr r0, _080EAAC8 @ =gTextWindow\n\
	ldr r7, [r0, #4]\n\
	mov r1, sl\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #1\n\
	beq _080EAAA0\n\
	b _080EABF0\n\
_080EAAA0:\n\
	ldr r1, _080EAACC @ =gSineTable\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0xa\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	mov r3, sl\n\
	ldrb r0, [r3, #6]\n\
	cmp r0, #0\n\
	bne _080EAAD0\n\
	movs r6, #1\n\
	str r6, [sp, #4]\n\
	ldr r1, [sp]\n\
	lsls r0, r1, #0x10\n\
	b _080EAAE2\n\
	.align 2, 0\n\
_080EAAC8: .4byte gTextWindow\n\
_080EAACC: .4byte gSineTable\n\
_080EAAD0:\n\
	movs r0, #0x1d\n\
	ldr r3, [sp]\n\
	lsls r2, r3, #0x10\n\
	asrs r1, r2, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	adds r0, r2, #0\n\
_080EAAE2:\n\
	ldr r2, _080EABC8 @ =gWindowRegBuffer\n\
	ldr r6, [sp, #4]\n\
	lsls r5, r6, #0x10\n\
	asrs r5, r5, #0x10\n\
	asrs r0, r0, #0x10\n\
	mov r8, r0\n\
	adds r1, r5, r0\n\
	lsls r1, r1, #3\n\
	adds r1, #3\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	lsls r0, r5, #0xb\n\
	ldr r3, _080EABCC @ =0xFFFFFD00\n\
	adds r0, r0, r3\n\
	orrs r1, r0\n\
	strh r1, [r2, #4]\n\
	ldr r0, _080EABD0 @ =0x000002C5\n\
	ldr r6, [sp, #8]\n\
	subs r4, r6, #1\n\
	lsls r4, r4, #5\n\
	adds r4, r5, r4\n\
	lsls r4, r4, #1\n\
	subs r4, #2\n\
	adds r4, r7, r4\n\
	mov r3, r8\n\
	adds r3, #2\n\
	lsls r3, r3, #1\n\
	adds r1, r4, #0\n\
	adds r2, r3, #0\n\
	str r3, [sp, #0xc]\n\
	bl FillMemory\n\
	ldr r0, _080EABD4 @ =0x000002C6\n\
	adds r6, #6\n\
	lsls r6, r6, #5\n\
	adds r5, r5, r6\n\
	lsls r5, r5, #1\n\
	subs r5, #2\n\
	adds r5, r7, r5\n\
	adds r1, r5, #0\n\
	ldr r3, [sp, #0xc]\n\
	adds r2, r3, #0\n\
	bl FillMemory\n\
	adds r7, r4, #0\n\
	ldr r6, _080EABD8 @ =0x000002C1\n\
	adds r0, r6, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r2, _080EABDC @ =0x000002C2\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	ldr r3, _080EABE0 @ =0x000002C7\n\
	adds r1, r3, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #1\n\
	adds r0, r7, r5\n\
	strh r1, [r0]\n\
	movs r3, #0xa0\n\
	lsls r3, r3, #1\n\
	adds r0, r7, r3\n\
	strh r1, [r0]\n\
	movs r4, #0xc0\n\
	lsls r4, r4, #1\n\
	adds r1, r7, r4\n\
	adds r6, #2\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #1\n\
	adds r1, r7, r2\n\
	adds r6, #1\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	mov r0, r8\n\
	lsls r0, r0, #1\n\
	mov r8, r0\n\
	movs r1, #2\n\
	add r8, r1\n\
	add r7, r8\n\
	ldr r6, _080EABE4 @ =0x000006C1\n\
	adds r0, r6, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	adds r6, #1\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	adds r6, #5\n\
	adds r1, r6, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	adds r5, r7, r5\n\
	strh r1, [r5]\n\
	adds r3, r7, r3\n\
	strh r1, [r3]\n\
	adds r4, r7, r4\n\
	ldr r1, _080EABE8 @ =0x000006C3\n\
	adds r0, r1, #0\n\
	strh r0, [r4]\n\
	adds r2, r7, r2\n\
	ldr r3, _080EABEC @ =0x000006C4\n\
	adds r0, r3, #0\n\
	strh r0, [r2]\n\
	b _080EAE8E\n\
	.align 2, 0\n\
_080EABC8: .4byte gWindowRegBuffer\n\
_080EABCC: .4byte 0xFFFFFD00\n\
_080EABD0: .4byte 0x000002C5\n\
_080EABD4: .4byte 0x000002C6\n\
_080EABD8: .4byte 0x000002C1\n\
_080EABDC: .4byte 0x000002C2\n\
_080EABE0: .4byte 0x000002C7\n\
_080EABE4: .4byte 0x000006C1\n\
_080EABE8: .4byte 0x000006C3\n\
_080EABEC: .4byte 0x000006C4\n\
_080EABF0:\n\
	ldr r1, _080EAC1C @ =gSineTable\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r6, #0\n\
	ldrsh r1, [r0, r6]\n\
	movs r0, #0xb0\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #8\n\
	adds r0, #0x37\n\
	lsls r0, r0, #0xd\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	mov r1, sl\n\
	ldrb r0, [r1, #6]\n\
	cmp r0, #0\n\
	bne _080EAC20\n\
	movs r2, #1\n\
	str r2, [sp, #4]\n\
	ldr r3, [sp]\n\
	lsls r0, r3, #0x10\n\
	b _080EAC32\n\
	.align 2, 0\n\
_080EAC1C: .4byte gSineTable\n\
_080EAC20:\n\
	movs r0, #0x1d\n\
	ldr r6, [sp]\n\
	lsls r2, r6, #0x10\n\
	asrs r1, r2, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	adds r0, r2, #0\n\
_080EAC32:\n\
	ldr r2, _080EAD70 @ =gWindowRegBuffer\n\
	ldr r1, [sp, #4]\n\
	lsls r5, r1, #0x10\n\
	asrs r5, r5, #0x10\n\
	asrs r0, r0, #0x10\n\
	mov sb, r0\n\
	adds r1, r5, r0\n\
	lsls r1, r1, #3\n\
	adds r1, #3\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	lsls r0, r5, #0xb\n\
	ldr r3, _080EAD74 @ =0xFFFFFD00\n\
	adds r0, r0, r3\n\
	orrs r1, r0\n\
	strh r1, [r2, #4]\n\
	ldr r0, _080EAD78 @ =0x000002C5\n\
	ldr r6, [sp, #8]\n\
	subs r4, r6, #1\n\
	lsls r4, r4, #5\n\
	adds r4, r5, r4\n\
	lsls r4, r4, #1\n\
	subs r4, #2\n\
	adds r4, r7, r4\n\
	mov r3, sb\n\
	adds r3, #2\n\
	lsls r3, r3, #1\n\
	adds r1, r4, #0\n\
	adds r2, r3, #0\n\
	str r3, [sp, #0xc]\n\
	bl FillMemory\n\
	ldr r0, _080EAD7C @ =0x000002C6\n\
	adds r6, #6\n\
	lsls r6, r6, #5\n\
	adds r5, r5, r6\n\
	lsls r5, r5, #1\n\
	subs r5, #2\n\
	adds r5, r7, r5\n\
	adds r1, r5, #0\n\
	ldr r3, [sp, #0xc]\n\
	adds r2, r3, #0\n\
	bl FillMemory\n\
	adds r7, r4, #0\n\
	mov r6, sl\n\
	ldrb r0, [r6, #6]\n\
	cmp r0, #0\n\
	beq _080EAC96\n\
	b _080EADA8\n\
_080EAC96:\n\
	movs r1, #0xb2\n\
	lsls r1, r1, #2\n\
	adds r0, r1, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r2, _080EAD80 @ =0x000002C9\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	movs r3, #0xb3\n\
	lsls r3, r3, #2\n\
	adds r1, r3, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	movs r6, #0x80\n\
	lsls r6, r6, #1\n\
	mov r8, r6\n\
	adds r0, r7, r6\n\
	strh r1, [r0]\n\
	movs r5, #0xa0\n\
	lsls r5, r5, #1\n\
	adds r0, r7, r5\n\
	strh r1, [r0]\n\
	adds r6, #0x80\n\
	adds r1, r7, r6\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r4, #0xe0\n\
	lsls r4, r4, #1\n\
	adds r1, r7, r4\n\
	subs r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080EAD84 @ =0x000002D2\n\
	adds r1, r7, #2\n\
	movs r2, #0xc\n\
	bl FillMemory\n\
	ldr r0, _080EAD88 @ =0x000002D3\n\
	movs r2, #0xe1\n\
	lsls r2, r2, #1\n\
	adds r1, r7, r2\n\
	movs r2, #0xc\n\
	bl FillMemory\n\
	ldr r3, _080EAD8C @ =0x000002CD\n\
	adds r0, r3, #0\n\
	strh r0, [r7, #0xe]\n\
	adds r1, r7, #0\n\
	adds r1, #0x4e\n\
	ldr r2, _080EAD90 @ =0x000002CE\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x40\n\
	adds r3, #4\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x40\n\
	strh r0, [r1]\n\
	movs r2, #0x87\n\
	lsls r2, r2, #1\n\
	adds r1, r7, r2\n\
	strh r0, [r1]\n\
	movs r3, #0xa7\n\
	lsls r3, r3, #1\n\
	adds r1, r7, r3\n\
	strh r0, [r1]\n\
	movs r0, #0xc7\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	ldr r2, _080EAD94 @ =0x000002CF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r3, #0x80\n\
	adds r1, r7, r3\n\
	adds r2, #1\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	mov r3, sb\n\
	lsls r0, r3, #1\n\
	adds r0, #2\n\
	adds r7, r7, r0\n\
	ldr r1, _080EAD98 @ =0x000006C1\n\
	adds r0, r1, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r2, _080EAD9C @ =0x000006C2\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	ldr r3, _080EADA0 @ =0x000006C7\n\
	adds r1, r3, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	add r8, r7\n\
	mov r0, r8\n\
	strh r1, [r0]\n\
	adds r5, r7, r5\n\
	strh r1, [r5]\n\
	adds r6, r7, r6\n\
	ldr r1, _080EADA4 @ =0x000006C3\n\
	b _080EAE7C\n\
	.align 2, 0\n\
_080EAD70: .4byte gWindowRegBuffer\n\
_080EAD74: .4byte 0xFFFFFD00\n\
_080EAD78: .4byte 0x000002C5\n\
_080EAD7C: .4byte 0x000002C6\n\
_080EAD80: .4byte 0x000002C9\n\
_080EAD84: .4byte 0x000002D2\n\
_080EAD88: .4byte 0x000002D3\n\
_080EAD8C: .4byte 0x000002CD\n\
_080EAD90: .4byte 0x000002CE\n\
_080EAD94: .4byte 0x000002CF\n\
_080EAD98: .4byte 0x000006C1\n\
_080EAD9C: .4byte 0x000006C2\n\
_080EADA0: .4byte 0x000006C7\n\
_080EADA4: .4byte 0x000006C3\n\
_080EADA8:\n\
	mov r3, sb\n\
	lsls r2, r3, #1\n\
	subs r2, #0xc\n\
	adds r7, r7, r2\n\
	ldr r6, _080EAEC8 @ =0x000006CD\n\
	adds r0, r6, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r3, _080EAECC @ =0x000006CE\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	adds r6, #4\n\
	adds r1, r6, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	mov r8, r0\n\
	adds r0, r7, r0\n\
	strh r1, [r0]\n\
	movs r5, #0xa0\n\
	lsls r5, r5, #1\n\
	adds r0, r7, r5\n\
	strh r1, [r0]\n\
	movs r6, #0xc0\n\
	lsls r6, r6, #1\n\
	adds r1, r7, r6\n\
	adds r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r4, #0xe0\n\
	lsls r4, r4, #1\n\
	adds r1, r7, r4\n\
	adds r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	subs r7, r7, r2\n\
	ldr r1, _080EAED0 @ =0x000002C1\n\
	adds r0, r1, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r3, _080EAED4 @ =0x000002C2\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	adds r3, #5\n\
	adds r1, r3, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	mov r3, r8\n\
	adds r0, r7, r3\n\
	strh r1, [r0]\n\
	adds r0, r7, r5\n\
	strh r1, [r0]\n\
	adds r1, r7, r6\n\
	ldr r3, _080EAED8 @ =0x000002C3\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, r7, r4\n\
	adds r3, #1\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r7, r7, r2\n\
	ldr r0, _080EAEDC @ =0x000006D2\n\
	adds r1, r7, #2\n\
	movs r2, #0xc\n\
	bl FillMemory\n\
	ldr r0, _080EAEE0 @ =0x000006D3\n\
	movs r2, #0xe1\n\
	lsls r2, r2, #1\n\
	adds r1, r7, r2\n\
	movs r2, #0xc\n\
	bl FillMemory\n\
	adds r7, #0xe\n\
	movs r3, #0xd9\n\
	lsls r3, r3, #3\n\
	adds r0, r3, #0\n\
	strh r0, [r7]\n\
	adds r1, r7, #0\n\
	adds r1, #0x40\n\
	ldr r2, _080EAEE4 @ =0x000006C9\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x80\n\
	adds r3, #4\n\
	adds r1, r3, #0\n\
	strh r1, [r0]\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	add r8, r7\n\
	mov r0, r8\n\
	strh r1, [r0]\n\
	adds r5, r7, r5\n\
	strh r1, [r5]\n\
	adds r6, r7, r6\n\
	ldr r1, _080EAEE8 @ =0x000006CA\n\
_080EAE7C:\n\
	adds r0, r1, #0\n\
	strh r0, [r6]\n\
	adds r4, r7, r4\n\
	adds r2, #2\n\
	adds r0, r2, #0\n\
	strh r0, [r4]\n\
	mov r0, sl\n\
	bl DrawMugshot\n\
_080EAE8E:\n\
	ldr r1, _080EAEEC @ =gTextPrinter\n\
	movs r3, #0xb3\n\
	lsls r3, r3, #3\n\
	adds r0, r1, r3\n\
	mov r6, sp\n\
	ldrb r6, [r6, #4]\n\
	strb r6, [r0]\n\
	ldr r2, _080EAEF0 @ =0x0000059A\n\
	adds r0, r1, r2\n\
	mov r3, sp\n\
	ldrb r3, [r3]\n\
	strb r3, [r0]\n\
	ldr r6, _080EAEF4 @ =0x00000599\n\
	adds r0, r1, r6\n\
	mov r2, sp\n\
	ldrb r2, [r2, #8]\n\
	strb r2, [r0]\n\
	ldr r3, _080EAEF8 @ =0x0000059B\n\
	adds r1, r1, r3\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080EAEC8: .4byte 0x000006CD\n\
_080EAECC: .4byte 0x000006CE\n\
_080EAED0: .4byte 0x000002C1\n\
_080EAED4: .4byte 0x000002C2\n\
_080EAED8: .4byte 0x000002C3\n\
_080EAEDC: .4byte 0x000006D2\n\
_080EAEE0: .4byte 0x000006D3\n\
_080EAEE4: .4byte 0x000006C9\n\
_080EAEE8: .4byte 0x000006CA\n\
_080EAEEC: .4byte gTextPrinter\n\
_080EAEF0: .4byte 0x0000059A\n\
_080EAEF4: .4byte 0x00000599\n\
_080EAEF8: .4byte 0x0000059B\n\
 .syntax divided\n");
}

// 0x080eaefc
// インラインメッセージウィンドウの描画 (テキスト自体は描画しない)
static void DrawInlineMessageWindow(TextWindowText* t, u32 len) {
  s32 sin = ((gSineTable[(u8)len] * 7) >> 3) + 7;
  u16* bgmap = gTextWindow.buffer;

  struct WramWindowRegister* w = &gWindowRegBuffer;
  s32 x8 = sin >> 3;                                      // ウィンドウの幅(8ドット単位)
  (w->winH).half[0] = 0x400 | (((x8 << 3) + 12) & 0xFF);  // x1 = 4, x2 = 4 + ((x8+1) * 8)

  // ウィンドウの内側
  if (x8 != 0) {
    FillMemory((MSGBOX_TILEID + 5), &bgmap[512 + 1], x8 << 1);
    FillMemory((MSGBOX_TILEID + 6), &bgmap[512 + (3 * 32) + 1], x8 << 1);
  }

  // ウィンドウの左端
  bgmap[512 + (0 * 32)] = (MSGBOX_TILEID + 1);
  bgmap[512 + (1 * 32)] = (MSGBOX_TILEID + 2);
  bgmap[512 + (2 * 32)] = (MSGBOX_TILEID + 3);
  bgmap[512 + (3 * 32)] = (MSGBOX_TILEID + 4);
  // ウィンドウの右端
  bgmap[512 + (0 * 32) + (1 + x8)] = TILE_XFLIP | (MSGBOX_TILEID + 1);
  bgmap[512 + (1 * 32) + (1 + x8)] = TILE_XFLIP | (MSGBOX_TILEID + 2);
  bgmap[512 + (2 * 32) + (1 + x8)] = TILE_XFLIP | (MSGBOX_TILEID + 3);
  bgmap[512 + (3 * 32) + (1 + x8)] = TILE_XFLIP | (MSGBOX_TILEID + 4);
}

/**
 * @brief 会話中でない時 (_UpdateTextWindow は会話してなくても毎フレーム呼ばれるため)
 * @note 0x080eafd8
 */
static void _UpdateTextWindow_0_Nop(TextWindowText* t) { t->mode = 0; }

static inline void shit1(TextWindowText* t) {
  const char* s = t->current;
  s32 no_left_mugshot = 0;
  if (t->mugshotRight || t->mugshot == NO_MUGSHOT) no_left_mugshot = 1;
  text_080e9b40(s, 8 - (no_left_mugshot * 7), t->y8, t->done);
}

static inline void shit2(TextWindowText* t, const char* s) {
  s32 no_left_mugshot = 0;
  if (t->mugshotRight || t->mugshot == NO_MUGSHOT) no_left_mugshot = 1;
  PrintString(s, 8 - (no_left_mugshot * 7), t->y8);
}

// 0x080eafe0
static void _UpdateTextWindow_1_MugshotMessage(TextWindowText* t) {
  switch ((t->state).u8[1]) {
    case 0: {
      LoadWindowTileData(t, t->mugshot);
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      RESET_BGOFS(0);
      gPaletteManager.buf[0] = RGB_BLACK;
      gWindowRegBuffer.dispcnt |= DISPCNT_WIN0_ON;
      gWindowRegBuffer.winin[0] = WININ_WIN0_BG0;
      gWindowRegBuffer.winin[2] |= 1;
      gWindowRegBuffer.winin[1] |= 1;
      t->len = 0;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 1: {
      t->mode = TWM_TYPING;
      gWindowRegBuffer.winV.half[0] = WIN_RANGE2(((t->y8 * 8) - 2), (((t->y8 + 6) * 8) + 2) & 0xFF);
      text_080eaa7c(t, (u16)t->len);
      t->len += 4;
      if (t->len < 64) break;
      if (!t->mugshotRight) {
        gWindowRegBuffer.winH.half[0] = WIN_RANGE(9, 232);
      } else {
        gWindowRegBuffer.winH.half[0] = WIN_RANGE(7, 231);
      }
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 2: {
      t->len = getStringLength(t->current);
      t->done = 1;
      t->frame = 4;
      (t->state).u8[2] = 0;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 3: {
      text_080eaa7c(t, 64);
      if (t->textType == TW_NORMAL || (t->flag & TEXT_FLAG_UNK0)) {
        if (gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) (t->state).u8[2] = 1;
      }
      if ((t->state).u8[2] != 0 || ((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) t->frame = 0;
      shit1(t);
      SkipString(t->current, t->done - 1);
      if (--t->frame == -1) {
        t->done++;
        if ((t->state).u8[2] != 0) t->done += 3;
        if (t->done < t->len) {
          t->frame = 3;
        } else {
          t->frame = 0;
          t->mode = TWM_WAITING;
          (t->state).u8[1]++;
        }
      }
      break;
    }
    case 4: {
      text_080eaa7c(t, 64);
      if (!((&gTextWindow.text)->flag & TEXT_FLAG_UNK3)) shit2(t, t->current);
      t->frame++;
      if (t->textType != TW_NORMAL) {
        if ((t->frame <= t->textType) && !(t->flag & TEXT_FLAG_TERMINATE)) break;
      } else {
        if (t->optional_next) {
          t->mode = TWM_WAITING | TWM_TYPING;
          if (gJoypad[0].field3_0x6 & (DPAD_UP | DPAD_DOWN)) {
            PlaySound(SE_CURSOR);
            if ((t->optionID & 0xF0) == 0x20) {
              t->optionID = (t->optionID & 0xF) | 0x10;
            } else {
              t->optionID = (t->optionID & 0xF) | 0x20;
            }
          }
          {
            // Draw cursor
            const char* s = STRING(STR_CURSOR);  // ▷
            s32 no_left_mugshot = 0;
            u32 x8, y8;
            if (t->mugshotRight || t->mugshot == NO_MUGSHOT) no_left_mugshot = 1;
            x8 = 8 - (no_left_mugshot * 7);
            y8 = t->y8 + 2;
            if ((t->optionID & 0xF0) == 0x20) y8 += 2;
            PrintString(s, x8, y8);  // ▷
          }
          if (t->flag & TEXT_FLAG_UNK2) {
            PlaySound(SE_NO);
          } else {
            if (gJoypad[0].pressed & A_BUTTON) {
              (t->state).u8[1]++;
              PlaySound(SE_YES);
            }
            break;
          }
        } else {
          if ((t->frame & 0x10) == 0) PrintJISString(gAsciiCaret, 28 - (t->mugshotRight * 7), t->y8 + 5);
          if (!(gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) && !((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) break;
        }
      }
      (t->state).u8[1]++;
      break;
    }
    case 5: {
      if (!(t->flag & TEXT_FLAG_TERMINATE)) {
        if (t->flag & TEXT_FLAG_UNK0) {
          if (t->optional_next && (t->flag & TEXT_FLAG_UNK2)) {
            t->next = NULL;
            t->optional_next = NULL;
          }
          if (!t->next) {
            text_080eaa7c(t, 64);
            if (!((&gTextWindow.text)->flag & TEXT_FLAG_UNK3)) shit2(t, t->current);
            t->mode = TEXT_MODE_OPTION;
            break;
          }
        }
        if (t->optional_next && ((t->optionID & 0xF0) == 0x20)) t->next = t->optional_next;
        if (t->next && !isMugshotChanged(t)) {
          text_080eaa7c(t, 64);
          t->current = t->next;
          setupTextWindow(t);
          t->mode = TWM_TYPING;
          (t->state).u8[1] = 2;
          break;
        }
      }
      t->mode = TEXT_MODE_OPTION | TWM_TYPING;
      t->len = 64;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 6: {
      t->len -= 4;
      if (!((&gTextWindow.text)->flag & TEXT_FLAG_UNK3)) shit2(t, t->current);
      text_080eaa7c(t, t->len);
      if (t->len != 0) break;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 7: {
      if (t->next && !(t->flag & TEXT_FLAG_TERMINATE)) {
        t->current = t->next;
        setupTextWindow(t);
        (t->state).u8[1] = 0;
      } else {
        (t->state).u8[1]++;
      }
      break;
    }
    case 8: {
      gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON;
      gWindowRegBuffer.winin[2] |= 1;
      gWindowRegBuffer.winin[1] |= 1;
      (t->state).u32 = 0;
      gTextPrinter.startX = 0;
      gTextPrinter.endX = 30;
      gTextPrinter.startY = 0;
      gTextPrinter.endY = 22;
      break;
    }
    default: {
      break;
    }
  }
}

// 0x080eb474
static void _UpdateTextWindow_2_InlineMessage(TextWindowText* t) {
  switch ((t->state).u8[1]) {
    case 0: {
      LoadWindowTileData(t, t->mugshot);
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      RESET_BGOFS(0);
      gPaletteManager.buf[0] = RGB_BLACK;
      gWindowRegBuffer.dispcnt |= DISPCNT_WIN0_ON;
      gWindowRegBuffer.winin[0] = WININ_WIN0_BG0;
      gWindowRegBuffer.winin[2] |= 1;
      gWindowRegBuffer.winin[1] |= 1;
      gWindowRegBuffer.winV.half[0] = WIN_RANGE(134, 154);
      t->len = 0;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 1: {
      DrawInlineMessageWindow(t, (u16)t->len);
      t->len += 4;
      if (t->len < 64) break;
      gWindowRegBuffer.winH.half[0] = WIN_RANGE(16, 224);
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 2: {
      t->mode = TWM_TYPING;
      t->len = getStringLength(t->current);
      t->done = 1;
      t->frame = 4;
      (t->state).u8[2] = 0;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 3: {
      DrawInlineMessageWindow(t, 64);
      if (t->textType == TW_NORMAL || (t->flag & TEXT_FLAG_UNK0)) {
        if (gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) (t->state).u8[2] = 1;
      }
      if ((t->state).u8[2] != 0 || ((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) t->frame = 0;
      text_080e9b40(t->current, 1, 17, t->done);
      SkipString(t->current, t->done - 1);
      if (--t->frame == -1) {
        t->done++;
        if ((t->state).u8[2] != 0) t->done += 3;
        if (t->done < t->len) {
          t->frame = 3;
        } else {
          t->frame = 0;
          t->mode = TWM_WAITING;
          (t->state).u8[1]++;
        }
      }
      break;
    }
    case 4: {
      DrawInlineMessageWindow(t, 64);
      PrintString(t->current, 1, 17);
      t->frame++;
      if (t->textType != TW_NORMAL) {
        if ((t->frame <= t->textType) && !(t->flag & TEXT_FLAG_TERMINATE)) break;
      } else {
        if ((t->frame & 0x10) == 0) PrintJISString(gAsciiCaret, 28, 18);
        if (!(gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) && !((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) break;
      }
      (t->state).u8[1]++;
      break;
    }
    case 5: {
      DrawInlineMessageWindow(t, 64);
      if (!(t->flag & TEXT_FLAG_TERMINATE)) {
        if (t->flag & TEXT_FLAG_UNK0) {
          if (!t->next) {
            PrintString(t->current, 1, 17);
            t->mode = TEXT_MODE_OPTION;
            break;
          }
        } else if (!t->next) {
          goto _NEXT;
        }
        t->current = t->next;
        setupTextWindow(t);
        t->mode = TWM_TYPING;
        (t->state).u8[1] = 2;
        break;
      }
    _NEXT:
      t->mode = TEXT_MODE_OPTION | TWM_TYPING;
      t->len = 64;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 6: {
      t->len -= 4;
      if (t->len == 0) {
        gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON;
        gWindowRegBuffer.winin[2] |= 1;
        gWindowRegBuffer.winin[1] |= 1;
        (t->state).u32 = 0;
      } else {
        DrawInlineMessageWindow(t, (u16)t->len);
      }
      break;
    }
    default: {
      break;
    }
  }
}

/**
 * @brief TWK_UNK3
 * @note 0x080eb6e8
 */
static void _UpdateTextWindow_3_Unk3(TextWindowText* t) {
  switch ((t->state).u8[1]) {
    case 0: {
      LoadWindowTileData(t, t->mugshot);
      gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
      RESET_BGOFS(0);
      gPaletteManager.buf[0] = RGB_BLACK;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 1: {
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 2: {
      t->mode = TWM_TYPING;
      t->len = getStringLength(t->current);
      t->done = 1;
      t->frame = 4;
      (t->state).u8[2] = 0;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 3: {
      if (t->textType == TW_NORMAL || (t->flag & TEXT_FLAG_UNK0)) {
        if (gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) (t->state).u8[2] = 1;
      }
      if ((t->state).u8[2] != 0 || ((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) t->frame = 0;
      text_080e9b40(t->current, 1, 18, t->done);
      SkipString(t->current, t->done - 1);
      if (--t->frame == -1) {
        t->done++;
        if ((t->state).u8[2] != 0) t->done += 3;
        if (t->done < t->len) {
          t->frame = 3;
        } else {
          t->frame = 0;
          t->mode = TWM_WAITING;
          (t->state).u8[1]++;
        }
      }
      break;
    }

    case 4: {
      PrintString(t->current, 1, 18);
      t->frame++;
      if (t->textType != TW_NORMAL) {
        if ((t->frame <= t->textType) && !(t->flag & TEXT_FLAG_TERMINATE)) break;
      } else {
        if ((t->frame & 0x10) == 0) PrintJISString(gAsciiCaret, 28, 19);
        if (!(gJoypad[0].pressed & (A_BUTTON | B_BUTTON)) && !((&gTextWindow.text)->flag & TEXT_FLAG_TERMINATE)) break;
      }
      (t->state).u8[1]++;
      break;
    }

    case 5: {
      if (!(t->flag & TEXT_FLAG_TERMINATE)) {
        if (t->flag & TEXT_FLAG_UNK0) {
          if (!t->next) {
            PrintString(t->current, 1, 18);
            t->mode = TEXT_MODE_OPTION;
            break;
          }
        } else if (!t->next) {
          goto _NEXT;
        }
        t->current = t->next;
        setupTextWindow(t);
        t->mode = TWM_TYPING;
        (t->state).u8[1] = 2;
        break;
      }
    _NEXT:
      t->mode = TEXT_MODE_OPTION | TWM_TYPING;
      (t->state).u8[1]++;
      FALLTHROUGH;
    }
    case 6: {
      (t->state).u32 = 0;
      break;
    }
    default: {
      break;
    }
  }
}

// --------------------------------------------

extern const u16 TextOfs_System[];
extern const u16 TextOffsets_OpenSecretDisk[];
extern const u16 TextOfs_CielChats[];
extern const u16 TextOfs_SpaceCraft[];
extern const u16 TextOfs_Volcano[];
extern const u16 TextOfs_OceanHighwayRuins[];
extern const u16 TextOfs_WeaponRepairFactory[];
extern const u16 TextOfs_OldLifeSpace[];
extern const u16 TextOfs_MissileFactory[];
extern const u16 TextOfs_TwilightDesert[];
extern const u16 TextOfs_AnatreForest[];
extern const u16 TextOfs_IceBase[];
extern const u16 TextOfs_AreaX2[];
extern const u16 TextOfs_EnergyFactory[];
extern const u16 TextOfs_SnowyPlains[];
extern const u16 TextOfs_SunkenLibrary[];
extern const u16 TextOfs_GiantElevator[];
extern const u16 TextOfs_SubArcadia[];
extern const u16 TextOfs_WeilLabo[];
extern const u16 TextOfs_Others[];

// clang-format off
// 0x083767b8
static const u16* const gTextOffsetTable[20] = {
  TextOfs_System,
  TextOffsets_OpenSecretDisk,
  TextOfs_CielChats,
  TextOfs_SpaceCraft,
  TextOfs_Volcano,
  TextOfs_OceanHighwayRuins,
  TextOfs_WeaponRepairFactory,
  TextOfs_OldLifeSpace,
  TextOfs_MissileFactory,
  TextOfs_TwilightDesert,
  TextOfs_AnatreForest,
  TextOfs_IceBase,
  TextOfs_AreaX2,
  TextOfs_EnergyFactory,
  TextOfs_SnowyPlains,
  TextOfs_SunkenLibrary,
  TextOfs_GiantElevator,
  TextOfs_SubArcadia,
  TextOfs_WeilLabo,
  TextOfs_Others,
};
// clang-format on

extern const char_t Text_System[];
extern const char_t Texts_OpenSecretDisk[];
extern const char_t Text_CielChats[];
extern const char_t Text_SpaceCraft[];
extern const char_t Text_Volcano[];
extern const char_t Text_OceanHighwayRuins[];
extern const char_t Text_WeaponRepairFactory[];
extern const char_t Text_OldLifeSpace[];
extern const char_t Text_MissileFactory[];
extern const char_t Text_TwilightDesert[];
extern const char_t Texts_AnatreForest[];
extern const char_t Texts_IceBase[];
extern const char_t Texts_AreaX2[];
extern const char_t Texts_EnergyFactory[];
extern const char_t Texts_SnowyPlains[];
extern const char_t Text_SunkenLibrary[];
extern const char_t Texts_GiantElevator[];
extern const char_t Text_SubArcadia[];
extern const char_t Text_WeilLabo[];
extern const char_t Text_Others[];

// clang-format off
// 0x08376808
static const char_t* const gTextTable[20] = {
  [TB_SYSTEM] =    Text_System,
  [TB_OPEN_DISK] = Texts_OpenSecretDisk,
  [TB_BANK2]     = Text_CielChats,
  [TB_SPACECRAFT] = Text_SpaceCraft,
    Text_Volcano,
    Text_OceanHighwayRuins,
    Text_WeaponRepairFactory,
    Text_OldLifeSpace,
    Text_MissileFactory,
    Text_TwilightDesert,
    Texts_AnatreForest,
    Texts_IceBase,
    Texts_AreaX2,
    Texts_EnergyFactory,
    Texts_SnowyPlains,
    Text_SunkenLibrary,
    Texts_GiantElevator,
    Text_SubArcadia,
    Text_WeilLabo,
    Text_Others,
};
// clang-format on

// 0x08376858
static const u32 sVramOffsets[2] = {
    MUGSHOT_TILEID * TILE_SIZE_4BPP,
    MSGBOX_TILEID* TILE_SIZE_4BPP,
};

// clang-format off
static const u16 sTilemap_MugshotLeft[6*8] = {
    (TILE_PAL(1) | MUGSHOT_TILEID), (TILE_PAL(1) | (MUGSHOT_TILEID+1)), (TILE_PAL(1) | (MUGSHOT_TILEID+2)), (TILE_PAL(1) | (MUGSHOT_TILEID+3)), (TILE_PAL(1) | (MUGSHOT_TILEID+4)), (TILE_PAL(1) | (MUGSHOT_TILEID+5)), // row0
    0x1266, 0x1267, 0x1268, 0x1269, 0x126A, 0x126B, // row1
    0x126C, 0x126D, 0x126E, 0x126F, 0x1270, 0x1271, // row2
    0x1272, 0x1273, 0x1274, 0x1275, 0x1276, 0x1277, // row3
    0x1278, 0x1279, 0x127A, 0x127B, 0x127C, 0x127D, // row4
    0x127E, 0x127F, 0x1280, 0x1281, 0x1282, 0x1283, // row5
    0x1284, 0x1285, 0x1286, 0x1287, 0x1288, 0x1289, // row6 (unused, Z1 の mugshot が 8x8 だったのでその名残?)
    0x128A, 0x128B, 0x128C, 0x128D, 0x128E, 0x128F, // row7 (unused)
}; // 0x08376860
// clang-format on

// sTilemap_MugshotLeft を xflip しただけ
// clang-format off
static const u16 sTilemap_MugshotRight[6*8] = {
    (TILE_PAL(1) | TILE_XFLIP | (MUGSHOT_TILEID+5)), (TILE_PAL(1) | TILE_XFLIP | (MUGSHOT_TILEID+4)), (TILE_PAL(1) | TILE_XFLIP | (MUGSHOT_TILEID+3)), (TILE_PAL(1) | TILE_XFLIP | (MUGSHOT_TILEID+2)), (TILE_PAL(1) | TILE_XFLIP | (MUGSHOT_TILEID+1)), (TILE_PAL(1) | TILE_XFLIP | MUGSHOT_TILEID), // row0
    0x166B, 0x166A, 0x1669, 0x1668, 0x1667, 0x1666, // row1
    0x1671, 0x1670, 0x166F, 0x166E, 0x166D, 0x166C, // row2
    0x1677, 0x1676, 0x1675, 0x1674, 0x1673, 0x1672, // row3 
    0x167D, 0x167C, 0x167B, 0x167A, 0x1679, 0x1678, // row4 
    0x1683, 0x1682, 0x1681, 0x1680, 0x167F, 0x167E, // row5 
    0x1689, 0x1688, 0x1687, 0x1686, 0x1685, 0x1684, // row6 (unused)
    0x168F, 0x168E, 0x168D, 0x168C, 0x168B, 0x168A, // row7 (unused)
};  // 0x083768c0
// clang-format on
