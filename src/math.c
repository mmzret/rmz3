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

s32 CalcAngleBetweenCoords(Coords32* c1, Coords32* c2) { return CalcAngleBetweenPoints(c1->x, c1->y, c2->x, c2->y); }

// The u32 return is load-bearing: a u8 return adds a lsls/lsrs
// truncation pair the ROM does not have.
u32 FUN_080e964c(u32 a, s32 b, s32 c) {
  s32 diff = a - b;
  if ((u32)((diff + c) & 0xFF) <= (u32)(c << 1)) {
    b = a;
  } else {
    s32 masked = diff & 0xFF;
    s32 dir = -1;
    if (masked <= 0x7F) {
      dir = 1;
    }
    b += c * dir;
    b &= 0xFF;
  }
  return b;
}

NAKED static void unused_080e9680(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) { INCCODE("asm/unused/unused_080e9680.inc"); }

NAKED static void unused_080e9698(void* param_1, void* param_2, u32 param_3, u32 param_4) { INCCODE("asm/unused/unused_080e9698.inc"); }

static s32 unused_080e96c8(s32 a, s32 b) {
  register s32 c asm("r2") = 0x100 - a;
  b += c;
  c = ((b & 0xFF) + 0x80);
  c &= 0xFF;
  c -= 0x80;
  return c;
}
