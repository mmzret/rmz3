#include "global.h"

/**
 * @brief X と Y が作る直角三角形のなす角度を求める
 * @param x Coord X
 * @param y Coord Y
 * @return angle(gSineTable's idx)
 * @note 0x080e95cc
 */
s32 CalcAngle(s32 x, s32 y) {
  u16 angle;
  s32 tmp;
  while (TRUE) {
    if (abs(x) < 0x8000) {
      if (abs(y) < 0x8000) {
        break;
      }
    }

    // Ceiling x
    tmp = x;
    if (tmp < 0) {
      tmp += 0xF;
    }
    x = (tmp >> 4);

    // Ceiling y
    tmp = y;
    if (tmp < 0) {
      tmp += 0xF;
    }
    y = (tmp >> 4);
  }

  angle = ArcTan2(x, y);
  return (((s32)(angle) + 0x80) >> 8) & 0xFF;
}

s32 CalcAngleBetweenPoints(s32 x1, s32 y1, s32 x2, s32 y2) { return CalcAngle(x2 - x1, y2 - y1); }

s32 CalcAngleBetweenCoords(struct Coord* c1, struct Coord* c2) { return CalcAngleBetweenPoints(c1->x, c1->y, c2->x, c2->y); }

NAKED u8 FUN_080e964c(u32 r0, s32 r1, s32 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	adds r3, r1, #0\n\
	adds r4, r2, #0\n\
	subs r2, r6, r3\n\
	adds r0, r2, r4\n\
	movs r5, #0xff\n\
	ands r0, r5\n\
	lsls r1, r4, #1\n\
	cmp r0, r1\n\
	bhi _080E9666\n\
	adds r3, r6, #0\n\
	b _080E9678\n\
_080E9666:\n\
	ands r2, r5\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r2, #0x7f\n\
	bgt _080E9672\n\
	movs r0, #1\n\
_080E9672:\n\
	muls r0, r4, r0\n\
	adds r3, r3, r0\n\
	ands r3, r5\n\
_080E9678:\n\
	adds r0, r3, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

#if MODERN == 0
NAKED static void unused_080e9680(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) { INCCODE("asm/unused/unused_080e9680.inc"); }
#endif

#if MODERN == 0
NAKED static void unused_080e9698(void* param_1, void* param_2, u32 param_3, u32 param_4) { INCCODE("asm/unused/unused_080e9698.inc"); }
#endif

#if MODERN == 0
static s32 unused_080e96c8(s32 a, s32 b) {
  register s32 c asm("r2") = 0x100 - a;
  b += c;
  c = ((b & 0xFF) + 0x80);
  c &= 0xFF;
  c -= 0x80;
  return c;
}
#endif
