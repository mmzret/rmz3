#include "global.h"

/*
  ステージの傾斜などを表現するため
  x と y は 0xFFF　されているので PIXEL(0)..PIXEL(16) の間
*/

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
  if (x < PIXEL(8)) {
    return 0;
  }
  if (x >= PIXEL(12)) {
    return ~y;
  }

  y -= PIXEL(16);
  Y = y + ((x - PIXEL(8)) << 2);
  if (Y > 0) {
    return -Y;
  }
  return 0;
}

NAKED s32 FUN_0800aaec(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800AB0C @ =0x00000BFF\n\
	cmp r2, r0\n\
	ble _0800AB06\n\
	ldr r0, _0800AB10 @ =0xFFFFF000\n\
	adds r1, r1, r0\n\
	ldr r3, _0800AB14 @ =0xFFFFF400\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #2\n\
	adds r0, r1, r0\n\
	cmp r0, #0\n\
	bgt _0800AB18\n\
_0800AB06:\n\
	movs r0, #0\n\
	b _0800AB1A\n\
	.align 2, 0\n\
_0800AB0C: .4byte 0x00000BFF\n\
_0800AB10: .4byte 0xFFFFF000\n\
_0800AB14: .4byte 0xFFFFF400\n\
_0800AB18:\n\
	rsbs r0, r0, #0\n\
_0800AB1A:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800ab20(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800AB38 @ =0x000007FF\n\
	cmp r2, r0\n\
	ble _0800AB40\n\
	ldr r3, _0800AB3C @ =0xFFFFF800\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bge _0800AB40\n\
	mvns r0, r1\n\
	b _0800AB42\n\
	.align 2, 0\n\
_0800AB38: .4byte 0x000007FF\n\
_0800AB3C: .4byte 0xFFFFF800\n\
_0800AB40:\n\
	movs r0, #0\n\
_0800AB42:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800ab48(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800AB5C @ =0x000007FF\n\
	cmp r2, r0\n\
	bgt _0800AB58\n\
	lsls r0, r2, #1\n\
	cmp r1, r0\n\
	bge _0800AB60\n\
_0800AB58:\n\
	mvns r0, r1\n\
	b _0800AB62\n\
	.align 2, 0\n\
_0800AB5C: .4byte 0x000007FF\n\
_0800AB60:\n\
	movs r0, #0\n\
_0800AB62:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800ab68(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800AB80 @ =0x00000BFF\n\
	cmp r2, r0\n\
	ble _0800AB88\n\
	ldr r3, _0800AB84 @ =0xFFFFF400\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #2\n\
	cmp r1, r0\n\
	bge _0800AB88\n\
	mvns r0, r1\n\
	b _0800AB8A\n\
	.align 2, 0\n\
_0800AB80: .4byte 0x00000BFF\n\
_0800AB84: .4byte 0xFFFFF400\n\
_0800AB88:\n\
	movs r0, #0\n\
_0800AB8A:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800ab90(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800ABB0 @ =0x000007FF\n\
	cmp r2, r0\n\
	ble _0800ABBC\n\
	ldr r0, _0800ABB4 @ =0x00000BFF\n\
	cmp r2, r0\n\
	bgt _0800ABAA\n\
	ldr r3, _0800ABB8 @ =0xFFFFF800\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #2\n\
	cmp r1, r0\n\
	bge _0800ABBC\n\
_0800ABAA:\n\
	mvns r0, r1\n\
	b _0800ABBE\n\
	.align 2, 0\n\
_0800ABB0: .4byte 0x000007FF\n\
_0800ABB4: .4byte 0x00000BFF\n\
_0800ABB8: .4byte 0xFFFFF800\n\
_0800ABBC:\n\
	movs r0, #0\n\
_0800ABBE:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800abc4(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800ABE4 @ =0x000003FF\n\
	cmp r2, r0\n\
	ble _0800ABF0\n\
	ldr r0, _0800ABE8 @ =0x000007FF\n\
	cmp r2, r0\n\
	bgt _0800ABDE\n\
	ldr r3, _0800ABEC @ =0xFFFFFC00\n\
	adds r0, r2, r3\n\
	lsls r0, r0, #2\n\
	cmp r1, r0\n\
	bge _0800ABF0\n\
_0800ABDE:\n\
	mvns r0, r1\n\
	b _0800ABF2\n\
	.align 2, 0\n\
_0800ABE4: .4byte 0x000003FF\n\
_0800ABE8: .4byte 0x000007FF\n\
_0800ABEC: .4byte 0xFFFFFC00\n\
_0800ABF0:\n\
	movs r0, #0\n\
_0800ABF2:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800abf8(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _0800AC0C @ =0x000003FF\n\
	cmp r2, r0\n\
	bgt _0800AC08\n\
	lsls r0, r2, #2\n\
	cmp r1, r0\n\
	bge _0800AC10\n\
_0800AC08:\n\
	mvns r0, r1\n\
	b _0800AC12\n\
	.align 2, 0\n\
_0800AC0C: .4byte 0x000003FF\n\
_0800AC10:\n\
	movs r0, #0\n\
_0800AC12:\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}
