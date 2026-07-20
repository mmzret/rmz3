#include "global.h"
#include "overworld.h"

/*
  ステージの傾斜などを表現するため
  x と y は 0xFFF　されているので PIXEL(0)..PIXEL(16) の間

  返り値が0なら空中, 0以外なら壁の中
*/

// clang-format off
const ShapeChecker gShapeCheckerUp[16] = {
    [SHAPE_EMPTY]   = FUN_0800a738,
    [SHAPE_BLOCK]   = FUN_0800a73c,
    [SHAPE_SLOPE2]  = FUN_0800a740,
    [SHAPE_SLOPE3]  = FUN_0800a760,
    [SHAPE_SLOPE4]  = FUN_0800a780,
    [SHAPE_SLOPE5]  = FUN_0800a7a0,
    [SHAPE_SLOPE6]  = FUN_0800a7c0,
    [SHAPE_SLOPE7]  = FUN_0800a7e0,
    [SHAPE_SLOPE8]  = FUN_0800a800,
    [SHAPE_SLOPE9]  = FUN_0800a814,
    [SHAPE_SLOPE10] = FUN_0800a834,
    [SHAPE_SLOPE11] = FUN_0800a848,
    [SHAPE_SLOPE12] = FUN_0800a868,
    [SHAPE_SLOPE13] = FUN_0800a888,
    [SHAPE_14]      = FUN_0800a73c,
    [SHAPE_15]      = FUN_0800a73c,
};
// clang-format on

// clang-format off
const ShapeChecker gShapeCheckerDown[16] = {
    [SHAPE_EMPTY]   = FUN_0800a738,
    [SHAPE_BLOCK]   = FUN_0800a73c,
    [SHAPE_SLOPE2]  = FUN_0800a8a8,
    [SHAPE_SLOPE3]  = FUN_0800a8bc,
    [SHAPE_SLOPE4]  = FUN_0800a8d4,
    [SHAPE_SLOPE5]  = FUN_0800a8e8,
    [SHAPE_SLOPE6]  = FUN_0800a900,
    [SHAPE_SLOPE7]  = FUN_0800a918,
    [SHAPE_SLOPE8]  = FUN_0800a930,
    [SHAPE_SLOPE9]  = FUN_0800a94c,
    [SHAPE_SLOPE10] = FUN_0800a968,
    [SHAPE_SLOPE11] = FUN_0800a984,
    [SHAPE_SLOPE12] = FUN_0800a9a0,
    [SHAPE_SLOPE13] = FUN_0800a9bc,
    [SHAPE_14]      = FUN_0800a738,
    [SHAPE_15]      = FUN_0800a73c,
};
// clang-format on

// clang-format off
const ShapeChecker gShapeCheckerLeft[16] = {
    [SHAPE_EMPTY]   = FUN_0800a738,
    [SHAPE_BLOCK]   = FUN_0800a73c,
    [SHAPE_SLOPE2]  = FUN_0800aa08,
    [SHAPE_SLOPE3]  = FUN_0800a9d8,
    [SHAPE_SLOPE4]  = FUN_0800aaec,
    [SHAPE_SLOPE5]  = FUN_0800aaac,
    [SHAPE_SLOPE6]  = FUN_0800aa6c,
    [SHAPE_SLOPE7]  = FUN_0800aa3c,
    [SHAPE_SLOPE8]  = FUN_0800ab48,
    [SHAPE_SLOPE9]  = FUN_0800ab20,
    [SHAPE_SLOPE10] = FUN_0800abf8,
    [SHAPE_SLOPE11] = FUN_0800abc4,
    [SHAPE_SLOPE12] = FUN_0800ab90,
    [SHAPE_SLOPE13] = FUN_0800ab68,
    [SHAPE_14]      = FUN_0800a738,
    [SHAPE_15]      = FUN_0800a73c,
};
// clang-format on

// clang-format off
const ShapeChecker gShapeCheckerRight[16] = {
    [SHAPE_EMPTY]   = FUN_0800a738,
    [SHAPE_BLOCK]   = FUN_0800a73c,
    [SHAPE_SLOPE2]  = FUN_0800ab20,
    [SHAPE_SLOPE3]  = FUN_0800ab48,
    [SHAPE_SLOPE4]  = FUN_0800ab68,
    [SHAPE_SLOPE5]  = FUN_0800ab90,
    [SHAPE_SLOPE6]  = FUN_0800abc4,
    [SHAPE_SLOPE7]  = FUN_0800abf8,
    [SHAPE_SLOPE8]  = FUN_0800a9d8,
    [SHAPE_SLOPE9]  = FUN_0800aa08,
    [SHAPE_SLOPE10] = FUN_0800aa3c,
    [SHAPE_SLOPE11] = FUN_0800aa6c,
    [SHAPE_SLOPE12] = FUN_0800aaac,
    [SHAPE_SLOPE13] = FUN_0800aaec,
    [SHAPE_14]      = FUN_0800a738,
    [SHAPE_15]      = FUN_0800a73c,
};
// clang-format on

s32 FUN_0800a738(s32 x, s32 y) { return 0; }

s32 FUN_0800a73c(s32 x, s32 y) { return ~y; }

s32 FUN_0800a740(s32 x, s32 y) {
  y += (x >> 1) - PIXEL(16);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a760(s32 x, s32 y) {
  y += (x >> 1) - PIXEL(8);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a780(s32 x, s32 y) {
  y += (x >> 2) - PIXEL(16);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a7a0(s32 x, s32 y) {
  y += (x >> 2) - PIXEL(12);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a7c0(s32 x, s32 y) {
  y += (x >> 2) - PIXEL(8);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a7e0(s32 x, s32 y) {
  y += (x >> 2) - PIXEL(4);
  if (y > 0) {
    return -y;
  }
  return 0;
}

// y > x/2
s32 FUN_0800a800(s32 x, s32 y) {
  y -= (x >> 1);
  if (y > 0) {
    return -y;
  }
  return 0;
}

// y > x/2 + 8
s32 FUN_0800a814(s32 x, s32 y) {
  y -= (x >> 1) + PIXEL(8);
  if (y > 0) {
    return -y;
  }
  return 0;
}

// y > x/4
s32 FUN_0800a834(s32 x, s32 y) {
  y -= (x >> 2);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a848(s32 x, s32 y) {
  y -= (x >> 2) + PIXEL(4);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a868(s32 x, s32 y) {
  y -= (x >> 2) + PIXEL(8);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a888(s32 x, s32 y) {
  y -= (x >> 2) + PIXEL(12);
  if (y > 0) {
    return -y;
  }
  return 0;
}

s32 FUN_0800a8a8(s32 x, s32 y) {
  if (y < (x >> 1)) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a8bc(s32 x, s32 y) {
  if (y < ((x >> 1) + PIXEL(8))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a8d4(s32 x, s32 y) {
  if (y < (x >> 2)) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a8e8(s32 x, s32 y) {
  if (y < ((x >> 2) + PIXEL(4))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a900(s32 x, s32 y) {
  if (y < ((x >> 2) + PIXEL(8))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a918(s32 x, s32 y) {
  if (y < ((x >> 2) + PIXEL(12))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a930(s32 x, s32 y) {
  if (y < (PIXEL(16) - (x >> 1))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a94c(s32 x, s32 y) {
  if (y < (PIXEL(16) - (x >> 1))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a968(s32 x, s32 y) {
  if (y < (PIXEL(16) - (x >> 2))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a984(s32 x, s32 y) {
  if (y < (PIXEL(12) - (x >> 2))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a9a0(s32 x, s32 y) {
  if (y < (PIXEL(8) - (x >> 2))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a9bc(s32 x, s32 y) {
  if (y < (PIXEL(4) - (x >> 2))) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800a9d8(s32 x, s32 y) {
  s32 val;
  if (x >= PIXEL(8)) {
    return ~y;
  }
  y -= PIXEL(16);
  val = y + (x << 1);
  if (val > 0) {
    return -val;
  }
  return 0;
}

s32 FUN_0800aa08(s32 x, s32 y) {
  s32 val;
  if (x >= PIXEL(8)) {
    y -= PIXEL(16);
    val = y + ((x - PIXEL(8)) << 1);
    if (val <= 0) {
      return 0;
    }
  } else {
    return 0;
  }
  return -val;
}

s32 FUN_0800aa3c(s32 x, s32 y) {
  s32 Y;
  if (x >= PIXEL(4)) {
    return ~y;
  }
  y -= PIXEL(16);
  Y = y + (x << 2);
  if (Y > 0) {
    return -Y;
  }
  return 0;
}

s32 FUN_0800aa6c(s32 x, s32 y) {
  s32 Y;
  if (x < PIXEL(4)) {
    return 0;
  }
  if (x >= PIXEL(8)) {
    return ~y;
  }

  y -= PIXEL(16);
  Y = y + ((x - PIXEL(4)) << 2);
  if (Y > 0) {
    return -Y;
  }
  return 0;
}

s32 FUN_0800aaac(s32 x, s32 y) {
  s32 Y;
  if (x < PIXEL(8)) return 0;
  if (x >= PIXEL(12)) return ~y;

  y -= PIXEL(16);
  Y = y + ((x - PIXEL(8)) << 2);
  if (Y > 0) return -Y;
  return 0;
}

s32 FUN_0800aaec(s32 x, s32 y) {
  s32 Y;
  if (x < PIXEL(12)) return 0;

  y -= PIXEL(16);
  Y = y + ((x - PIXEL(12)) << 2);
  if (Y > 0) return -Y;
  return 0;
}

s32 FUN_0800ab20(s32 x, s32 y) {
  if (x > 0x7FF && y < (x - 0x800) * 2) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800ab48(s32 x, s32 y) {
  if (x > 0x7FF) {
    return ~y;
  }
  if (y >= x * 2) {
    return 0;
  }
  return ~y;
}

s32 FUN_0800ab68(s32 x, s32 y) {
  if (x > 0xBFF && y < (x - 0xC00) * 4) {
    return ~y;
  }
  return 0;
}

s32 FUN_0800ab90(s32 x, s32 y) {
  if (x <= 0x7FF) {
    return 0;
  }
  if (x > 0xBFF) {
    return ~y;
  }
  if (y >= (x - 0x800) * 4) {
    return 0;
  }
  return ~y;
}

s32 FUN_0800abc4(s32 x, s32 y) {
  if (x <= 0x3FF) {
    return 0;
  }
  if (x > 0x7FF) {
    return ~y;
  }
  if (y >= (x - 0x400) * 4) {
    return 0;
  }
  return ~y;
}

s32 FUN_0800abf8(s32 x, s32 y) {
  if (x > 0x3FF) {
    return ~y;
  }
  if (y >= x * 4) {
    return 0;
  }
  return ~y;
}
