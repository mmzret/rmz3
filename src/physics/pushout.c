#include "gba/gba.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "task.h"

// GetGroundMetatileAttr と似た処理だが、空中判定を受けた際に、Hazardチェックもする(GetGroundMetatileAttrより厳しい)
WIP metatile_attr_t FUN_080098a4(s32 x, s32 y) {
#if MODERN
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  if ((mx < 0x771) && (my < 0x4F6)) {
    struct MetatileMap* tm = &gOverworld.tilemap;
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[(my * tm->width) + mx]];
    if ((gShapeCheckerUp[attr & 0xF])(x & 0xFFF, y & 0xFFF) == 0) {
      return GetHazardMetatileAttr(x, y);
    }
    return attr;
  }
  return 0x0A01;
#else
  INCCODE("asm/wip/FUN_080098a4.inc");
#endif
}

// 現在立っている地面部分(x, y)のmetatile_attr_tを取得 (空中にいる場合は0)
WIP metatile_attr_t GetGroundMetatileAttr(s32 x, s32 y) {
#if MODERN
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  struct MetatileMap* tm = &gOverworld.tilemap;
  metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[(my * tm->width) + mx]];
  if ((attr & 0x0F) == 0) {
    return 0;
  }
  if ((attr & 0x0F) == METATILE_GROUND) {
    return attr;  // ここで間違えて0を返すと、ゼロが床をすり抜けて落下死する
  }
  if ((gShapeCheckerUp[attr & 0xF])(x & 0xFFF, y & 0xFFF) == 0) {  // (坂道の)空中部分
    return 0;
  }
  return attr;
#else
  INCCODE("asm/wip/GetGroundMetatileAttr.inc");
#endif
}

s32 CalcPushout_Up(s32 x, s32 y);

WIP s32 PushoutToUp1(s32 x, s32 y) {
#if MODERN
  s32 newY;
  s32 i = 0;
  s32 Y = y;
  struct MetatileMap* tm = &gOverworld.tilemap;
  while (TRUE) {
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[METACOORD(Y) * tm->width + METACOORD(x)]];
    u32 shape = attr & 0xF;
    newY = Y;
    if ((shape == 0) || (attr == 0x800F)) {
      break;
    }
    if (shape == METATILE_GROUND) {
      newY = COORD(METACOORD(Y)) - 1;
    } else {
      s32 dy = (gShapeCheckerUp[shape])(x & 0xFFF, Y & 0xFFF);
      if (dy == 0) {
        break;
      }
      newY = Y + dy;
      if (((Y ^ newY) & PIXEL(16)) == 0) {  // yのmetacorrdが変化しない
        break;
      }
    }
    Y = newY;
    i++;

    if (i > 15) break;
  }

  if (i < 16) {
    return CalcPushout_Up(x, Y) - y;
  }
  return 1;
#else
  INCCODE("asm/wip/PushoutToUp1.inc");
#endif
}

// おそらく壁にめり込んだ際の上方向への押し出し処理(結構チェックしたからロジックは大丈夫...？)
NON_MATCH s32 PushoutToUp2(s32 x, s32 y) {
#if MODERN
  s32 newY;
  s32 i = 0;
  s32 Y = y;
  struct MetatileMap* tm = &gOverworld.tilemap;
  while (TRUE) {
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[METACOORD(Y) * tm->width + METACOORD(x)]];
    u32 shape = attr & 0xF;
    newY = Y;
    if ((shape == 0) || (attr == 0x800F)) {
      break;
    }
    if (shape == METATILE_GROUND) {
      newY = (Y & 0xFFFFF000) - 1;
    } else {
      s32 dy = (gShapeCheckerUp[shape])(x & 0xFFF, Y & 0xFFF);
      if (dy == 0) {
        break;
      }
      newY = Y + dy;
      if (((Y ^ newY) & PIXEL(16)) == 0) {  // yのmetacorrdが変化しない
        break;
      }
    }
    Y = newY;
    i++;

    if (i > 15) {
      return 1;
    }
  }
  return newY - y;
#else
  INCCODE("asm/wip/PushoutToUp2.inc");
#endif
}

s32 CalcPushout_Down(s32 x, s32 y);

// おそらく壁にめり込んだ際の下方向への押し出し処理
WIP s32 PushoutToDown1(s32 x, s32 y) {
#if MODERN
  s32 newY;
  s32 i = 0;
  s32 Y = y;
  struct MetatileMap* tm = &gOverworld.tilemap;
  while (TRUE) {
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[METACOORD(Y) * tm->width + METACOORD(x)]];
    u32 shape = attr & 0xF;
    newY = Y;
    if ((shape == 0) || (attr & 0x8400)) {
      break;
    }
    if (shape == METATILE_GROUND) {
      newY = (Y + PIXEL(16)) & 0xFFFFF000;
    } else {
      s32 dy = (gShapeCheckerDown[shape])(x & 0xFFF, (~Y) & 0xFFF);
      if (dy == 0) {
        break;
      }
      newY = Y - dy;
      if (((Y ^ newY) & PIXEL(16)) == 0) {  // yのmetacorrdが変化しない
        break;
      }
    }
    Y = newY;
    i++;
    if (i > 15) {
      return -1;
    };
  }
  return CalcPushout_Down(x, Y) - y;
#else
  INCCODE("asm/wip/PushoutToDown1.inc");
#endif
}

// おそらく壁にめり込んだ際の下方向への押し出し処理
WIP s32 PushoutToDown2(s32 x, s32 y) {
#if MODERN
  s32 newY;
  s32 i = 0;
  s32 Y = y;
  struct MetatileMap* tm = &gOverworld.tilemap;
  while (TRUE) {
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[METACOORD(Y) * tm->width + METACOORD(x)]];
    u32 shape = attr & 0xF;
    newY = Y;
    if ((shape == 0) || (attr & 0x8400)) {
      break;
    }
    if (shape == METATILE_GROUND) {
      newY = (Y + PIXEL(16)) & 0xFFFFF000;
    } else {
      s32 dy = (gShapeCheckerDown[shape])(x & 0xFFF, (~Y) & 0xFFF);
      if (dy == 0) {
        break;
      }
      newY = Y - dy;
      if (((Y ^ newY) & COORD(1)) == 0) {  // yのmetacorrdが変化しない
        break;
      }
    }
    Y = newY;
    i++;

    if (i > 15) {
      return -1;
    };
  }
  return Y - y;
#else
  INCCODE("asm/wip/PushoutToDown2.inc");
#endif
}

s32 CalcPushout_Left(s32 x, s32 y);

WIP s32 PushoutToLeft1(s32 x, s32 y) {
#if MODERN
  s32 newX;
  s32 i = 0;
  s32 X = x;
  struct MetatileMap* tm = &gOverworld.tilemap;
  while (TRUE) {
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[METACOORD(y) * tm->width + METACOORD(X)]];
    u32 shape = attr & 0xF;
    newX = X;
    if ((shape == 0) || (attr & 0x8400)) {
      break;
    }
    if (shape == METATILE_GROUND) {
      newX = (X & 0xFFFFF000) - 1;
    } else {
      s32 dx = (gShapeCheckerLeft[shape])(y & 0xFFF, X & 0xFFF);
      if (dx == 0) {
        break;
      }
      newX = X + dx;
      if (((X ^ newX) & PIXEL(16)) == 0) {  // yのmetacorrdが変化しない
        break;
      }
    }
    X = newX;
    i++;

    if (i > 15) break;
  }

  if (i < 16) {
    return CalcPushout_Left(X, y) - x;
  }
  return 1;
#else
  INCCODE("asm/wip/PushoutToLeft1.inc");
#endif
}

NAKED s32 PushoutToLeft2(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	adds r6, r1, #0\n\
	adds r5, r4, #0\n\
	movs r7, #0\n\
	ldr r0, _08009D94 @ =gOverworld+440\n\
	mov sb, r0\n\
	movs r2, #0xc5\n\
	lsls r2, r2, #3\n\
	add r2, sb\n\
	mov r8, r2\n\
_08009D54:\n\
	mov r3, r8\n\
	ldrh r1, [r3]\n\
	asrs r0, r6, #0xc\n\
	muls r0, r1, r0\n\
	asrs r1, r4, #0xc\n\
	adds r0, r0, r1\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r2, #0xf\n\
	ands r2, r1\n\
	cmp r2, #0\n\
	beq _08009DC6\n\
	movs r3, #0x84\n\
	lsls r3, r3, #8\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08009DC6\n\
	cmp r2, #1\n\
	bne _08009D9C\n\
	ldr r0, _08009D98 @ =0xFFFFF000\n\
	ands r0, r4\n\
	subs r4, r0, #1\n\
	b _08009DD4\n\
	.align 2, 0\n\
_08009D94: .4byte gOverworld+440\n\
_08009D98: .4byte 0xFFFFF000\n\
_08009D9C:\n\
	ldr r1, _08009DCC @ =gShapeCheckerLeft\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldr r2, _08009DD0 @ =0x00000FFF\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	ldr r3, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	beq _08009DC6\n\
	adds r1, r4, #0\n\
	adds r4, r4, r0\n\
	eors r1, r4\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08009DD4\n\
_08009DC6:\n\
	subs r0, r4, r5\n\
	b _08009DDC\n\
	.align 2, 0\n\
_08009DCC: .4byte gShapeCheckerLeft\n\
_08009DD0: .4byte 0x00000FFF\n\
_08009DD4:\n\
	adds r7, #1\n\
	cmp r7, #0xf\n\
	ble _08009D54\n\
	movs r0, #1\n\
_08009DDC:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

s32 CalcPushout_Right(s32 x, s32 y);

NAKED s32 PushoutToRight1(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r4, r0, #0\n\
	adds r6, r1, #0\n\
	mov sb, r4\n\
	movs r5, #0\n\
	ldr r0, _08009E4C @ =gOverworld+440\n\
	mov r8, r0\n\
	movs r1, #0xc5\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	mov sl, r1\n\
	ldr r3, _08009E50 @ =0x00000FFF\n\
_08009E0A:\n\
	mov r2, sl\n\
	ldrh r1, [r2]\n\
	asrs r0, r6, #0xc\n\
	muls r0, r1, r0\n\
	asrs r1, r4, #0xc\n\
	adds r0, r0, r1\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrh r0, [r0]\n\
	mov r7, r8\n\
	ldr r1, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r2, #0xf\n\
	ands r2, r1\n\
	cmp r2, #0\n\
	beq _08009E8A\n\
	movs r7, #0x84\n\
	lsls r7, r7, #8\n\
	adds r0, r7, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08009E8A\n\
	cmp r2, #1\n\
	bne _08009E58\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	adds r4, r4, r0\n\
	ldr r0, _08009E54 @ =0xFFFFF000\n\
	ands r4, r0\n\
	b _08009E84\n\
	.align 2, 0\n\
_08009E4C: .4byte gOverworld+440\n\
_08009E50: .4byte 0x00000FFF\n\
_08009E54: .4byte 0xFFFFF000\n\
_08009E58:\n\
	ldr r1, _08009E9C @ =gShapeCheckerRight\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	adds r1, r3, #0\n\
	bics r1, r4\n\
	ldr r2, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r3\n\
	str r3, [sp]\n\
	bl _call_via_r2\n\
	ldr r3, [sp]\n\
	cmp r0, #0\n\
	beq _08009E8A\n\
	adds r1, r4, #0\n\
	subs r4, r4, r0\n\
	eors r1, r4\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08009E8A\n\
_08009E84:\n\
	adds r5, #1\n\
	cmp r5, #0xf\n\
	ble _08009E0A\n\
_08009E8A:\n\
	cmp r5, #0xf\n\
	bgt _08009EA0\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl CalcPushout_Right\n\
	mov r1, sb\n\
	subs r0, r0, r1\n\
	b _08009EA4\n\
	.align 2, 0\n\
_08009E9C: .4byte gShapeCheckerRight\n\
_08009EA0:\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
_08009EA4:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 PushoutToRight2(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	adds r6, r1, #0\n\
	adds r5, r4, #0\n\
	movs r7, #0\n\
	ldr r0, _08009F14 @ =gOverworld+440\n\
	mov sb, r0\n\
	movs r2, #0xc5\n\
	lsls r2, r2, #3\n\
	add r2, sb\n\
	mov r8, r2\n\
_08009ED0:\n\
	mov r3, r8\n\
	ldrh r1, [r3]\n\
	asrs r0, r6, #0xc\n\
	muls r0, r1, r0\n\
	asrs r1, r4, #0xc\n\
	adds r0, r0, r1\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r2, #0xf\n\
	ands r2, r1\n\
	cmp r2, #0\n\
	beq _08009F46\n\
	movs r3, #0x84\n\
	lsls r3, r3, #8\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08009F46\n\
	cmp r2, #1\n\
	bne _08009F1C\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	adds r4, r4, r0\n\
	ldr r0, _08009F18 @ =0xFFFFF000\n\
	ands r4, r0\n\
	b _08009F54\n\
	.align 2, 0\n\
_08009F14: .4byte gOverworld+440\n\
_08009F18: .4byte 0xFFFFF000\n\
_08009F1C:\n\
	ldr r1, _08009F4C @ =gShapeCheckerRight\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldr r2, _08009F50 @ =0x00000FFF\n\
	adds r1, r2, #0\n\
	bics r1, r4\n\
	ldr r3, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	beq _08009F46\n\
	adds r1, r4, #0\n\
	subs r4, r4, r0\n\
	eors r1, r4\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08009F54\n\
_08009F46:\n\
	subs r0, r4, r5\n\
	b _08009F5E\n\
	.align 2, 0\n\
_08009F4C: .4byte gShapeCheckerRight\n\
_08009F50: .4byte 0x00000FFF\n\
_08009F54:\n\
	adds r7, #1\n\
	cmp r7, #0xf\n\
	ble _08009ED0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
_08009F5E:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

s32 FUN_0800af30(s32 x, s32 y, s32 r2);

NAKED s32 FUN_08009f6c(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	mov sb, r1\n\
	mov r4, sb\n\
	asrs r0, r7, #0xc\n\
	mov r8, r0\n\
	asrs r1, r4, #0xc\n\
	ldr r0, _08009F90 @ =0x0000077F\n\
	cmp r8, r0\n\
	bls _08009F94\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _0800A04C\n\
	.align 2, 0\n\
_08009F90: .4byte 0x0000077F\n\
_08009F94:\n\
	movs r6, #0\n\
	ldr r0, _08009FF0 @ =0x000004FF\n\
	cmp r1, r0\n\
	bhi _0800A01E\n\
	ldr r2, _08009FF4 @ =gOverworld+440\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	mov sl, r2\n\
_08009FA6:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	muls r0, r1, r0\n\
	add r0, r8\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrh r0, [r0]\n\
	ldr r2, _08009FF4 @ =gOverworld+440\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r5, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r5\n\
	lsls r0, r0, #2\n\
	ldr r1, _08009FF8 @ =gShapeCheckerUp\n\
	adds r0, r0, r1\n\
	ldr r2, _08009FFC @ =0x00000FFF\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	ldr r3, [r0]\n\
	adds r0, r7, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	beq _08009FE4\n\
	ldr r0, _0800A000 @ =0x0000800F\n\
	cmp r5, r0\n\
	bne _0800A01E\n\
_08009FE4:\n\
	movs r0, #1\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _0800A004\n\
	adds r4, #1\n\
	b _0800A010\n\
	.align 2, 0\n\
_08009FF0: .4byte 0x000004FF\n\
_08009FF4: .4byte gOverworld+440\n\
_08009FF8: .4byte gShapeCheckerUp\n\
_08009FFC: .4byte 0x00000FFF\n\
_0800A000: .4byte 0x0000800F\n\
_0800A004:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r4, r2\n\
	asrs r0, r0, #0xc\n\
	lsls r0, r0, #0xc\n\
	subs r4, r0, #1\n\
_0800A010:\n\
	asrs r1, r4, #0xc\n\
	adds r6, #1\n\
	cmp r6, #0x7f\n\
	bgt _0800A022\n\
	ldr r0, _0800A028 @ =0x000004FF\n\
	cmp r1, r0\n\
	bls _08009FA6\n\
_0800A01E:\n\
	cmp r6, #0x7f\n\
	ble _0800A030\n\
_0800A022:\n\
	ldr r2, _0800A02C @ =0x7FFFFFFF\n\
	b _0800A040\n\
	.align 2, 0\n\
_0800A028: .4byte 0x000004FF\n\
_0800A02C: .4byte 0x7FFFFFFF\n\
_0800A030:\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl PushoutToUp1\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bgt _0800A04A\n\
	adds r2, r4, r1\n\
_0800A040:\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	bl FUN_0800af30\n\
	b _0800A04C\n\
_0800A04A:\n\
	movs r0, #0\n\
_0800A04C:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800a05c(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	adds r4, r1, #0\n\
	asrs r0, r7, #0xc\n\
	mov sl, r0\n\
	asrs r1, r4, #0xc\n\
	movs r6, #0\n\
	ldr r0, _0800A0D0 @ =0x000004FF\n\
	cmp r1, r0\n\
	bhi _0800A0FE\n\
	ldr r2, _0800A0D4 @ =gOverworld+440\n\
	mov sb, r2\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	add r0, sb\n\
	mov r8, r0\n\
_0800A084:\n\
	mov r2, r8\n\
	ldrh r0, [r2]\n\
	muls r0, r1, r0\n\
	add r0, sl\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r5, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r5\n\
	lsls r0, r0, #2\n\
	ldr r1, _0800A0D8 @ =gShapeCheckerUp\n\
	adds r0, r0, r1\n\
	ldr r2, _0800A0DC @ =0x00000FFF\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	ldr r3, [r0]\n\
	adds r0, r7, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	beq _0800A0C2\n\
	ldr r0, _0800A0E0 @ =0x0000800F\n\
	cmp r5, r0\n\
	bne _0800A0FE\n\
_0800A0C2:\n\
	movs r0, #1\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _0800A0E4\n\
	adds r4, #1\n\
	b _0800A0F0\n\
	.align 2, 0\n\
_0800A0D0: .4byte 0x000004FF\n\
_0800A0D4: .4byte gOverworld+440\n\
_0800A0D8: .4byte gShapeCheckerUp\n\
_0800A0DC: .4byte 0x00000FFF\n\
_0800A0E0: .4byte 0x0000800F\n\
_0800A0E4:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r4, r2\n\
	asrs r0, r0, #0xc\n\
	lsls r0, r0, #0xc\n\
	subs r4, r0, #1\n\
_0800A0F0:\n\
	asrs r1, r4, #0xc\n\
	adds r6, #1\n\
	cmp r6, #0x7f\n\
	bgt _0800A102\n\
	ldr r0, _0800A108 @ =0x000004FF\n\
	cmp r1, r0\n\
	bls _0800A084\n\
_0800A0FE:\n\
	cmp r6, #0x7f\n\
	ble _0800A110\n\
_0800A102:\n\
	ldr r0, _0800A10C @ =0x7FFFFFFF\n\
	b _0800A124\n\
	.align 2, 0\n\
_0800A108: .4byte 0x000004FF\n\
_0800A10C: .4byte 0x7FFFFFFF\n\
_0800A110:\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl PushoutToUp2\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bgt _0800A122\n\
	adds r0, r4, r1\n\
	b _0800A124\n\
_0800A122:\n\
	movs r0, #0\n\
_0800A124:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

s32 FUN_0800afd4(s32 x, s32 y1, s32 y2);

NAKED s32 FUN_0800a134(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	mov sb, r1\n\
	mov r5, sb\n\
	asrs r0, r7, #0xc\n\
	mov r8, r0\n\
	asrs r1, r5, #0xc\n\
	ldr r0, _0800A158 @ =0x0000077F\n\
	cmp r8, r0\n\
	bls _0800A15C\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _0800A218\n\
	.align 2, 0\n\
_0800A158: .4byte 0x0000077F\n\
_0800A15C:\n\
	movs r6, #0\n\
	ldr r0, _0800A1C4 @ =0x000004FF\n\
	cmp r1, r0\n\
	bhi _0800A1E6\n\
	ldr r2, _0800A1C8 @ =gOverworld+440\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	mov sl, r2\n\
	ldr r3, _0800A1CC @ =0x00000FFF\n\
_0800A170:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	muls r0, r1, r0\n\
	add r0, r8\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldrh r0, [r0]\n\
	ldr r2, _0800A1C8 @ =gOverworld+440\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	movs r0, #0xf\n\
	ands r0, r4\n\
	lsls r0, r0, #2\n\
	ldr r1, _0800A1D0 @ =gShapeCheckerDown\n\
	adds r0, r0, r1\n\
	adds r1, r3, #0\n\
	bics r1, r5\n\
	ldr r2, [r0]\n\
	adds r0, r7, #0\n\
	ands r0, r3\n\
	str r3, [sp]\n\
	bl _call_via_r2\n\
	ldr r3, [sp]\n\
	cmp r0, #0\n\
	beq _0800A1B6\n\
	movs r2, #0x84\n\
	lsls r2, r2, #8\n\
	adds r0, r2, #0\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	beq _0800A1E6\n\
_0800A1B6:\n\
	movs r0, #1\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _0800A1D4\n\
	subs r5, #1\n\
	b _0800A1D8\n\
	.align 2, 0\n\
_0800A1C4: .4byte 0x000004FF\n\
_0800A1C8: .4byte gOverworld+440\n\
_0800A1CC: .4byte 0x00000FFF\n\
_0800A1D0: .4byte gShapeCheckerDown\n\
_0800A1D4:\n\
	asrs r0, r5, #0xc\n\
	lsls r5, r0, #0xc\n\
_0800A1D8:\n\
	asrs r1, r5, #0xc\n\
	adds r6, #1\n\
	cmp r6, #0x7f\n\
	bgt _0800A1EA\n\
	ldr r0, _0800A1F8 @ =0x000004FF\n\
	cmp r1, r0\n\
	bls _0800A170\n\
_0800A1E6:\n\
	cmp r6, #0x7f\n\
	ble _0800A1FC\n\
_0800A1EA:\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	movs r2, #0\n\
	bl FUN_0800afd4\n\
	b _0800A218\n\
	.align 2, 0\n\
_0800A1F8: .4byte 0x000004FF\n\
_0800A1FC:\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	bl PushoutToDown1\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	blt _0800A216\n\
	adds r2, r5, r1\n\
	adds r0, r7, #0\n\
	mov r1, sb\n\
	bl FUN_0800afd4\n\
	b _0800A218\n\
_0800A216:\n\
	ldr r0, _0800A228 @ =0x7FFFFFFF\n\
_0800A218:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800A228: .4byte 0x7FFFFFFF\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800a22c(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r4, r0, #0\n\
	adds r6, r1, #0\n\
	mov r8, r4\n\
	asrs r1, r4, #0xc\n\
	asrs r7, r6, #0xc\n\
	ldr r0, _0800A24C @ =0x000004FF\n\
	cmp r7, r0\n\
	bls _0800A250\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _0800A30C\n\
	.align 2, 0\n\
_0800A24C: .4byte 0x000004FF\n\
_0800A250:\n\
	movs r5, #0\n\
	ldr r0, _0800A2B0 @ =0x0000077F\n\
	cmp r1, r0\n\
	bhi _0800A2DE\n\
	ldr r0, _0800A2B4 @ =gOverworld+440\n\
	mov sl, r0\n\
	movs r2, #0xc5\n\
	lsls r2, r2, #3\n\
	add r2, sl\n\
	mov sb, r2\n\
_0800A264:\n\
	mov r2, sb\n\
	ldrh r0, [r2]\n\
	muls r0, r7, r0\n\
	adds r0, r0, r1\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrh r0, [r0]\n\
	mov r2, sl\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0]\n\
	ldr r0, _0800A2B8 @ =0x0000800F\n\
	cmp r2, r0\n\
	beq _0800A2A2\n\
	ldr r1, _0800A2BC @ =gShapeCheckerLeft\n\
	movs r0, #0xf\n\
	ands r2, r0\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldr r2, _0800A2C0 @ =0x00000FFF\n\
	adds r1, r4, #0\n\
	ands r1, r2\n\
	ldr r3, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	bne _0800A2DE\n\
_0800A2A2:\n\
	movs r0, #1\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _0800A2C4\n\
	adds r4, #1\n\
	b _0800A2D0\n\
	.align 2, 0\n\
_0800A2B0: .4byte 0x0000077F\n\
_0800A2B4: .4byte gOverworld+440\n\
_0800A2B8: .4byte 0x0000800F\n\
_0800A2BC: .4byte gShapeCheckerLeft\n\
_0800A2C0: .4byte 0x00000FFF\n\
_0800A2C4:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r4, r1\n\
	asrs r0, r0, #0xc\n\
	lsls r0, r0, #0xc\n\
	subs r4, r0, #1\n\
_0800A2D0:\n\
	asrs r1, r4, #0xc\n\
	adds r5, #1\n\
	cmp r5, #0x7f\n\
	bgt _0800A2E2\n\
	ldr r0, _0800A2E8 @ =0x0000077F\n\
	cmp r1, r0\n\
	bls _0800A264\n\
_0800A2DE:\n\
	cmp r5, #0x7f\n\
	ble _0800A2F0\n\
_0800A2E2:\n\
	ldr r2, _0800A2EC @ =0x7FFFFFFF\n\
	b _0800A300\n\
	.align 2, 0\n\
_0800A2E8: .4byte 0x0000077F\n\
_0800A2EC: .4byte 0x7FFFFFFF\n\
_0800A2F0:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToLeft1\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bgt _0800A30A\n\
	adds r2, r4, r1\n\
_0800A300:\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	bl FUN_0800b08c\n\
	b _0800A30C\n\
_0800A30A:\n\
	movs r0, #0\n\
_0800A30C:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_0800a31c(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r4, r0, #0\n\
	adds r6, r1, #0\n\
	mov r8, r4\n\
	asrs r2, r4, #0xc\n\
	asrs r7, r6, #0xc\n\
	ldr r0, _0800A33C @ =0x000004FF\n\
	cmp r7, r0\n\
	bls _0800A340\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	b _0800A3F8\n\
	.align 2, 0\n\
_0800A33C: .4byte 0x000004FF\n\
_0800A340:\n\
	movs r5, #0\n\
	ldr r0, _0800A3A0 @ =0x0000077F\n\
	cmp r2, r0\n\
	bhi _0800A3C6\n\
	ldr r0, _0800A3A4 @ =gOverworld+440\n\
	mov sl, r0\n\
	movs r1, #0xc5\n\
	lsls r1, r1, #3\n\
	add r1, sl\n\
	mov sb, r1\n\
_0800A354:\n\
	mov r1, sb\n\
	ldrh r0, [r1]\n\
	muls r0, r7, r0\n\
	adds r0, r0, r2\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrh r0, [r0]\n\
	mov r2, sl\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0]\n\
	ldr r0, _0800A3A8 @ =0x0000800F\n\
	cmp r2, r0\n\
	beq _0800A392\n\
	ldr r1, _0800A3AC @ =gShapeCheckerRight\n\
	movs r0, #0xf\n\
	ands r2, r0\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r1\n\
	ldr r2, _0800A3B0 @ =0x00000FFF\n\
	adds r1, r2, #0\n\
	bics r1, r4\n\
	ldr r3, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	bl _call_via_r3\n\
	cmp r0, #0\n\
	bne _0800A3C6\n\
_0800A392:\n\
	movs r0, #1\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	beq _0800A3B4\n\
	subs r4, #1\n\
	b _0800A3B8\n\
	.align 2, 0\n\
_0800A3A0: .4byte 0x0000077F\n\
_0800A3A4: .4byte gOverworld+440\n\
_0800A3A8: .4byte 0x0000800F\n\
_0800A3AC: .4byte gShapeCheckerRight\n\
_0800A3B0: .4byte 0x00000FFF\n\
_0800A3B4:\n\
	asrs r0, r4, #0xc\n\
	lsls r4, r0, #0xc\n\
_0800A3B8:\n\
	asrs r2, r4, #0xc\n\
	adds r5, #1\n\
	cmp r5, #0x7f\n\
	bgt _0800A3CA\n\
	ldr r0, _0800A3D8 @ =0x0000077F\n\
	cmp r2, r0\n\
	bls _0800A354\n\
_0800A3C6:\n\
	cmp r5, #0x7f\n\
	ble _0800A3DC\n\
_0800A3CA:\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	movs r2, #0\n\
	bl FUN_0800b144\n\
	b _0800A3F8\n\
	.align 2, 0\n\
_0800A3D8: .4byte 0x0000077F\n\
_0800A3DC:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl PushoutToRight1\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	blt _0800A3F6\n\
	adds r2, r4, r2\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	bl FUN_0800b144\n\
	b _0800A3F8\n\
_0800A3F6:\n\
	ldr r0, _0800A408 @ =0x7FFFFFFF\n\
_0800A3F8:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800A408: .4byte 0x7FFFFFFF\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

NAKED s32 FUN_0800a40c(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	adds r6, r1, #0\n\
	asrs r3, r5, #0xc\n\
	asrs r2, r6, #0xc\n\
	movs r0, #0xee\n\
	lsls r0, r0, #3\n\
	cmp r3, r0\n\
	bhi _0800A4AA\n\
	ldr r0, _0800A470 @ =0x000004F5\n\
	cmp r2, r0\n\
	bhi _0800A4AA\n\
	ldr r7, _0800A474 @ =gOverworld+440\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r1, r7, r0\n\
	ldrh r0, [r1]\n\
	muls r0, r2, r0\n\
	adds r0, r0, r3\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, [r7]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	ldr r0, _0800A478 @ =gShapeCheckerUp\n\
	movs r2, #0xf\n\
	ands r2, r4\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r0\n\
	ldr r3, _0800A47C @ =0x00000FFF\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	adds r1, r6, #0\n\
	ands r1, r3\n\
	ldr r2, [r2]\n\
	bl _call_via_r2\n\
	cmp r0, #0\n\
	beq _0800A498\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _0800A484\n\
	ldr r1, _0800A480 @ =0x0002BE50\n\
	adds r0, r7, r1\n\
	b _0800A4B0\n\
	.align 2, 0\n\
_0800A470: .4byte 0x000004F5\n\
_0800A474: .4byte gOverworld+440\n\
_0800A478: .4byte gShapeCheckerUp\n\
_0800A47C: .4byte 0x00000FFF\n\
_0800A480: .4byte 0x0002BE50\n\
_0800A484:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	ands r4, r0\n\
	cmp r4, #0\n\
	beq _0800A498\n\
	ldr r1, _0800A494 @ =0x0002BE4C\n\
	adds r0, r7, r1\n\
	b _0800A4B0\n\
	.align 2, 0\n\
_0800A494: .4byte 0x0002BE4C\n\
_0800A498:\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl GetHazardMetatileAttr\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _0800A4AE\n\
_0800A4AA:\n\
	movs r0, #0\n\
	b _0800A4B2\n\
_0800A4AE:\n\
	ldr r0, _0800A4B8 @ =s32_ARRAY_02000028\n\
_0800A4B0:\n\
	ldr r0, [r0]\n\
_0800A4B2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800A4B8: .4byte s32_ARRAY_02000028\n\
 .syntax divided\n");
}

NON_MATCH s32 FUN_0800a4bc(s32 x, s32 y) {
#if MODERN
  const s32 mx = METACOORD(x);
  const s32 my = METACOORD(y);
  if ((mx < 0x771) && (my < 0x4F6)) {
    struct MetatileMap* tm = &gOverworld.tilemap;
    metatile_attr_t attr = gOverworld.terrain.attrs[tm->map[my * tm->width + mx]];
    if ((gShapeCheckerUp[attr & 0xF])(x & 0xFFF, y & 0xFFF) != 0) {
      if (attr & 0x2000) {
        return gOverworld.unk_2c004.y;
      }
      if (attr & 0x4000) {
        return gOverworld.unk_2c004.x;
      }
    }
  }
  return 0;
#else
  INCCODE("asm/wip/FUN_0800a4bc.inc");
#endif
}

static s32 unused_0800a550(s32 x, s32 y) { return isStageBlocking(-1, x, y); }

// Used only in Phantom's minigame
NAKED s32 isStageBlocking(s32 start, s32 x, s32 y) { INCCODE("asm/todo/isStageBlocking.inc"); }

NAKED void AppendHazard(u16 id, u16 attr, const struct Coord* c, const struct Rect* size) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov sb, r2\n\
	mov r8, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	ldr r2, _0800A6C4 @ =gOverworld\n\
	movs r0, #0xe9\n\
	lsls r0, r0, #1\n\
	adds r4, r2, r0\n\
	ldrb r3, [r4]\n\
	adds r0, r3, #1\n\
	mov ip, r2\n\
	cmp r0, #0x1f\n\
	ble _0800A61A\n\
	b _0800A728\n\
_0800A61A:\n\
	strb r0, [r4]\n\
	adds r6, r3, #0\n\
	lsls r2, r6, #1\n\
	mov sl, r2\n\
	adds r0, r2, r6\n\
	lsls r4, r0, #3\n\
	mov r3, ip\n\
	adds r0, r4, r3\n\
	movs r2, #0xea\n\
	lsls r2, r2, #1\n\
	adds r7, r0, r2\n\
	strh r5, [r7]\n\
	movs r3, #0xeb\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	strh r1, [r0]\n\
	movs r1, #0xee\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r4, r1\n\
	mov r0, r8\n\
	movs r3, #0\n\
	ldrsh r2, [r0, r3]\n\
	mov r3, sb\n\
	ldr r0, [r3]\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r4, r1\n\
	mov r0, r8\n\
	movs r3, #2\n\
	ldrsh r2, [r0, r3]\n\
	mov r3, sb\n\
	ldr r0, [r3, #4]\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	movs r3, #0\n\
	ldr r0, _0800A6C8 @ =0x000001D3\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	cmp r3, r0\n\
	bge _0800A6D4\n\
	mov r5, ip\n\
	mov sb, r4\n\
	ldrh r4, [r7]\n\
	mov r1, ip\n\
	ldr r7, _0800A6CC @ =0x000004D4\n\
	adds r2, r0, #0\n\
_0800A67E:\n\
	adds r0, r1, r7\n\
	ldrh r0, [r0]\n\
	cmp r0, r4\n\
	beq _0800A68E\n\
	adds r1, #0x18\n\
	adds r3, #1\n\
	cmp r3, r2\n\
	blt _0800A67E\n\
_0800A68E:\n\
	ldr r1, _0800A6C8 @ =0x000001D3\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r3, r0\n\
	bge _0800A6D4\n\
	movs r0, #0xf2\n\
	lsls r0, r0, #1\n\
	adds r2, r5, r0\n\
	add r2, sb\n\
	lsls r1, r3, #1\n\
	adds r1, r1, r3\n\
	lsls r1, r1, #3\n\
	ldr r3, _0800A6D0 @ =0x000004DC\n\
	adds r0, r5, r3\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	movs r0, #0xf4\n\
	lsls r0, r0, #1\n\
	adds r2, r5, r0\n\
	add r2, sb\n\
	adds r3, #4\n\
	adds r0, r5, r3\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	str r0, [r2]\n\
	b _0800A704\n\
	.align 2, 0\n\
_0800A6C4: .4byte gOverworld\n\
_0800A6C8: .4byte 0x000001D3\n\
_0800A6CC: .4byte 0x000004D4\n\
_0800A6D0: .4byte 0x000004DC\n\
_0800A6D4:\n\
	lsls r3, r6, #1\n\
	adds r1, r3, r6\n\
	lsls r1, r1, #3\n\
	movs r2, #0xf2\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	adds r2, r1, r2\n\
	movs r0, #0xee\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	movs r2, #0xf4\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	adds r2, r1, r2\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	str r0, [r2]\n\
	mov sl, r3\n\
_0800A704:\n\
	mov r1, sl\n\
	adds r0, r1, r6\n\
	lsls r0, r0, #3\n\
	mov r3, ip\n\
	adds r2, r0, r3\n\
	mov r1, r8\n\
	ldrh r0, [r1, #4]\n\
	lsrs r0, r0, #1\n\
	movs r3, #0xec\n\
	lsls r3, r3, #1\n\
	adds r1, r2, r3\n\
	strh r0, [r1]\n\
	mov r1, r8\n\
	ldrh r0, [r1, #6]\n\
	lsrs r0, r0, #1\n\
	adds r3, #2\n\
	adds r1, r2, r3\n\
	strh r0, [r1]\n\
_0800A728:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// TODO asm/hazard.o
