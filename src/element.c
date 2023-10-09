#include "element.h"

#include "entity.h"
#include "gfx.h"
#include "global.h"

void FUN_080250b8(void) {
  wElement.unk_0 = 0;
  setWramElement(0);
  wElement.unk_2 = 0;
  LOAD_STATIC_GRAPHIC(SM028_ICE_EFFECT);
}

void FUN_0802511c(void) {
  u32 n;

  if (wElement.unk_2 != 0) {
    wElement.unk_2--;
    return;
  }
  if (wElement.unk_1 != wElement.unk_0) {
    wElement.unk_0 = wElement.unk_1;
    if (wElement.unk_1 != 0) {
      n = 25 + wElement.unk_0;
      REQUEST_STATIC_GRAPHIC(n);
    }
  }
}

void setWramElement(u8 elementID) {
  wElement.unk_1 = elementID;
  return;
}

void FUN_080251a8(void) {
  if (wElement.unk_0 != 0) {
    u32 n = 25 + wElement.unk_0;
    LOAD_STATIC_GRAPHIC(n);
  }
  if (wElement.unk_0 != 3) {
    LOAD_STATIC_GRAPHIC(SM028_ICE_EFFECT);
  }
}

// おそらく引数のEntityに属性攻撃のエフェクト(氷や電撃)をつける関数
NAKED struct VFX *ApplyElementEffect(u8 idx, struct Entity *p, const struct Coord *c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x24\n\
	adds r5, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	movs r0, #0\n\
	mov sl, r0\n\
	ldr r0, [r2]\n\
	str r0, [sp]\n\
	ldr r0, [r2, #4]\n\
	str r0, [sp, #4]\n\
	movs r1, #0\n\
	str r1, [sp, #0x20]\n\
	adds r0, r5, #0\n\
	adds r0, #0x97\n\
	ldrb r0, [r0]\n\
	movs r1, #0xf0\n\
	ands r1, r0\n\
	cmp r1, #0x10\n\
	bne _08025286\n\
	movs r2, #1\n\
	str r2, [sp, #0x20]\n\
	b _08025298\n\
_08025286:\n\
	cmp r1, #0x20\n\
	bne _08025290\n\
	movs r0, #2\n\
	str r0, [sp, #0x20]\n\
	b _08025298\n\
_08025290:\n\
	cmp r1, #0x30\n\
	bne _08025298\n\
	movs r1, #3\n\
	str r1, [sp, #0x20]\n\
_08025298:\n\
	ldr r0, _080252C4 @ =WeakElements\n\
	lsls r1, r3, #2\n\
	ldr r2, [sp, #0x20]\n\
	adds r1, r2, r1\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080252AA\n\
	b _080255FA\n\
_080252AA:\n\
	cmp r3, #6\n\
	bls _080252B0\n\
	b _080253D4\n\
_080252B0:\n\
	ldr r0, [sp, #0x20]\n\
	cmp r0, #1\n\
	bne _080252C8\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateThunderEffect\n\
	mov sl, r0\n\
	b _080255AE\n\
	.align 2, 0\n\
_080252C4: .4byte WeakElements\n\
_080252C8:\n\
	ldr r1, [sp, #0x20]\n\
	cmp r1, #2\n\
	bne _0802534C\n\
	ldr r0, [sp]\n\
	movs r4, #0xc0\n\
	lsls r4, r4, #3\n\
	adds r0, r0, r4\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	ldr r2, _08025340 @ =0xFFFFF400\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateFlameEffect\n\
	mov sl, r0\n\
	ldr r0, [sp]\n\
	ldr r1, _08025344 @ =0xFFFFF200\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	adds r0, r0, r4\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateFlameEffect\n\
	ldr r0, [sp]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateFlameEffect\n\
	ldr r0, [sp]\n\
	ldr r2, _08025348 @ =0xFFFFF600\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateFlameEffect\n\
	b _080255AE\n\
	.align 2, 0\n\
_08025340: .4byte 0xFFFFF400\n\
_08025344: .4byte 0xFFFFF200\n\
_08025348: .4byte 0xFFFFF600\n\
_0802534C:\n\
	ldr r2, [sp, #0x20]\n\
	cmp r2, #3\n\
	beq _08025354\n\
	b _080255AE\n\
_08025354:\n\
	ldr r0, [sp]\n\
	movs r4, #0xc0\n\
	lsls r4, r4, #3\n\
	adds r0, r0, r4\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _080253C8 @ =0xFFFFF400\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateIceEffect\n\
	mov sl, r0\n\
	ldr r0, [sp]\n\
	ldr r2, _080253CC @ =0xFFFFF200\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	adds r0, r0, r4\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateIceEffect\n\
	ldr r0, [sp]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateIceEffect\n\
	ldr r0, [sp]\n\
	ldr r1, _080253D0 @ =0xFFFFF600\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	adds r0, r5, #0\n\
	mov r1, sp\n\
	movs r2, #0x5a\n\
	bl CreateIceEffect\n\
	b _080255AE\n\
	.align 2, 0\n\
_080253C8: .4byte 0xFFFFF400\n\
_080253CC: .4byte 0xFFFFF200\n\
_080253D0: .4byte 0xFFFFF600\n\
_080253D4:\n\
	movs r7, #0x1e\n\
	ldr r0, [sp, #0x20]\n\
	cmp r0, #1\n\
	bne _08025426\n\
	add r4, sp, #8\n\
	ldr r6, _08025408 @ =Coord_ARRAY_0835e01c\n\
	movs r1, #6\n\
	mov r8, r1\n\
_080253E4:\n\
	ldr r0, [sp]\n\
	ldr r1, [r6]\n\
	adds r0, r0, r1\n\
	str r0, [sp, #8]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r6, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #4]\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	bne _0802540C\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateThunderEffect\n\
	mov sl, r0\n\
	b _08025416\n\
	.align 2, 0\n\
_08025408: .4byte Coord_ARRAY_0835e01c\n\
_0802540C:\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateThunderEffect\n\
_08025416:\n\
	adds r6, #8\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	add r8, r0\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bge _080253E4\n\
	b _080255AE\n\
_08025426:\n\
	ldr r2, [sp, #0x20]\n\
	cmp r2, #2\n\
	bne _080254F0\n\
	add r0, sp, #0x10\n\
	mov sb, r0\n\
	mov r4, sb\n\
	ldr r6, _08025470 @ =Coord_ARRAY_0835e054\n\
	movs r1, #3\n\
	mov r8, r1\n\
_08025438:\n\
	ldr r0, [sp]\n\
	ldr r1, [r6]\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r6, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #4]\n\
	ldr r0, [sp, #0x10]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [r4, #4]\n\
	ldr r1, _08025474 @ =0xFFFFF400\n\
	adds r0, r0, r1\n\
	str r0, [r4, #4]\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	bne _08025478\n\
	adds r0, r5, #0\n\
	mov r1, sb\n\
	adds r2, r7, #0\n\
	bl CreateFlameEffect\n\
	mov sl, r0\n\
	b _08025482\n\
	.align 2, 0\n\
_08025470: .4byte Coord_ARRAY_0835e054\n\
_08025474: .4byte 0xFFFFF400\n\
_08025478:\n\
	adds r0, r5, #0\n\
	mov r1, sb\n\
	adds r2, r7, #0\n\
	bl CreateFlameEffect\n\
_08025482:\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, _080254E8 @ =0xFFFFF200\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateFlameEffect\n\
	ldr r0, [sp, #0x10]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateFlameEffect\n\
	ldr r0, [sp, #0x10]\n\
	ldr r1, _080254EC @ =0xFFFFF600\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x10]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateFlameEffect\n\
	adds r6, #8\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	add r8, r0\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bge _08025438\n\
	b _080255AE\n\
	.align 2, 0\n\
_080254E8: .4byte 0xFFFFF200\n\
_080254EC: .4byte 0xFFFFF600\n\
_080254F0:\n\
	ldr r2, [sp, #0x20]\n\
	cmp r2, #3\n\
	bne _080255AE\n\
	add r0, sp, #0x18\n\
	mov sb, r0\n\
	mov r4, sb\n\
	ldr r6, _08025538 @ =Coord_ARRAY_0835e054\n\
	movs r1, #3\n\
	mov r8, r1\n\
_08025502:\n\
	ldr r0, [sp]\n\
	ldr r1, [r6]\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, [r6, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #4]\n\
	ldr r0, [sp, #0x18]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [r4, #4]\n\
	ldr r1, _0802553C @ =0xFFFFF400\n\
	adds r0, r0, r1\n\
	str r0, [r4, #4]\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	bne _08025540\n\
	adds r0, r5, #0\n\
	mov r1, sb\n\
	adds r2, r7, #0\n\
	bl CreateIceEffect\n\
	mov sl, r0\n\
	b _0802554A\n\
	.align 2, 0\n\
_08025538: .4byte Coord_ARRAY_0835e054\n\
_0802553C: .4byte 0xFFFFF400\n\
_08025540:\n\
	adds r0, r5, #0\n\
	mov r1, sb\n\
	adds r2, r7, #0\n\
	bl CreateIceEffect\n\
_0802554A:\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, _080255DC @ =0xFFFFF200\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateIceEffect\n\
	ldr r0, [sp, #0x18]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateIceEffect\n\
	ldr r0, [sp, #0x18]\n\
	ldr r1, _080255E0 @ =0xFFFFF600\n\
	adds r0, r0, r1\n\
	str r0, [sp, #0x18]\n\
	ldr r0, [r4, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	adds r2, r7, #0\n\
	bl CreateIceEffect\n\
	adds r6, #8\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	add r8, r0\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bge _08025502\n\
_080255AE:\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	beq _080255FA\n\
	ldr r0, [sp, #0x20]\n\
	cmp r0, #1\n\
	bne _080255CA\n\
	movs r0, #0x3c\n\
	bl PlaySound\n\
	adds r1, r5, #0\n\
	adds r1, #0x94\n\
	ldrb r0, [r1]\n\
	adds r0, #0x1e\n\
	strb r0, [r1]\n\
_080255CA:\n\
	ldr r1, [sp, #0x20]\n\
	cmp r1, #2\n\
	bne _080255E4\n\
	movs r0, #0x3d\n\
	bl PlaySound\n\
	movs r0, #0\n\
	b _080255FC\n\
	.align 2, 0\n\
_080255DC: .4byte 0xFFFFF200\n\
_080255E0: .4byte 0xFFFFF600\n\
_080255E4:\n\
	ldr r2, [sp, #0x20]\n\
	cmp r2, #3\n\
	bne _080255FA\n\
	movs r0, #0x40\n\
	bl PlaySound\n\
	adds r1, r5, #0\n\
	adds r1, #0x94\n\
	ldrb r0, [r1]\n\
	adds r0, #0x1e\n\
	strb r0, [r1]\n\
_080255FA:\n\
	mov r0, sl\n\
_080255FC:\n\
	add sp, #0x24\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

bool32 isKilled(struct Entity *p) {
  if (p != NULL) {
    return 1 < p->mode[0];
  }
  return TRUE;
}

const ALIGNED(4) u8 WeakElements[34][4] = {
    {0, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
};

const struct Coord Coord_ARRAY_0835e01c[7] = {
    {0x00000000, 0x00000000}, {-0x00001C00, 0x00000000}, {0x00001C00, 0x00000000}, {-0x00000E00, -0x00001C00}, {0x00000E00, -0x00001C00}, {-0x00000E00, 0x00001C00}, {0x00000E00, 0x00001C00},
};

const struct Coord Coord_ARRAY_0835e054[4] = {
    {-0x00000E00, -0x00000E00},
    {0x00000E00, -0x00000E00},
    {-0x00000E00, 0x00000E00},
    {0x00000E00, 0x00000E00},
};
