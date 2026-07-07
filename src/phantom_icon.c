#include "entity.h"
#include "renderer.h"

// ファントムのミニゲームで、残機を表す顔アイコンのスプライト
// 他のミニゲームのアイコンは、vfx/minigame_icon.c で実装されており、なぜファントムのアイコンだけ実装が別かは今の所は不明

typedef struct {
  RenderNode node;  // 0x00
  void* p;          // 0x08 (0x20319D0 or 0x20319D8 or 0x20319E0)
  struct {
    /*0x0C*/ u32 y : 8;
    /*0x0D*/ u32 affineMode : 2;  // 0x1, 0x2 = 0x3
    /*    */ u32 objMode : 2;     // 0x4, 0x8 = 0xC
    /*    */ u32 mosaic : 1;      // 0x10
    /*    */ u32 bpp : 1;         // 0x20
    /*    */ u32 shape : 2;       // 0x40, 0x80
    /*0x0E*/ u32 x : 9;
    /*    */ u32 matrixNum : 5;  // bits 3/4 are h-flip/v-flip if not in affine mode
    /*    */ u32 size : 2;
    /*0x10*/ u16 tileNum : 10;
    /*    */ u16 priority : 2;
    /*    */ u16 paletteNum : 4;
    u8 pad[2];    // 0x12
  } oam;          // 0x0C
  u8 unk_14[12];  // 0x14
} PhantomIconSprite;
static_assert(sizeof(PhantomIconSprite) == sizeof(RenderData));

static void RenderTask_PhantomIcon(PhantomIconSprite* s, struct DrawPivot* pivot);

/**
 * @brief Create phantom face icon for Minigame HP
 * @param s ChipIcon sprite (0: 0x2031970, 1: 0x2031990, 2: 0x20319B0)
 * @param p 0x20319D0
 * @param r2 0x0000001
 * @param tilenum Tile Number for Chip icon
 * @note Called on Phantom minigame only in Zero3
 */
void CreatePhantomIcon(PhantomIconSprite* s, void* p, u8 r2, u16 tilenum) {
  SetTaskCallback(&s->node, RenderTask_PhantomIcon);
  (s->oam).bpp = 0;
  (s->oam).paletteNum = 0;
  (s->oam).pad[0] = 0, (s->oam).pad[1] = 0;
  (s->oam).mosaic = 1;
  (s->oam).priority = 2;
  (s->oam).objMode = 0;
  s->p = p;
  (s->oam).shape = (r2 >> 2);
  (s->oam).size = r2 & 3;
  (s->oam).tileNum = tilenum;
  (s->oam).affineMode = 0;
  (s->oam).matrixNum = 0;
  (s->oam).x = 0, (s->oam).y = 0;
}

// Only used in Phantom minigame
// 0x08004d80
NAKED static void RenderTask_PhantomIcon(PhantomIconSprite* s, struct DrawPivot* pivot) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r3, r1, #0\n\
	ldr r0, _08004E08 @ =gOamManager\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r7, r0, r1\n\
	ldr r5, [r7]\n\
	cmp r5, r7\n\
	bhs _08004E00\n\
	ldr r2, [r4, #8]\n\
	ldr r0, [r2, #4]\n\
	ldr r1, [r3, #0xc]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	asrs r6, r0, #0x10\n\
	adds r0, r6, #0\n\
	adds r0, #0x40\n\
	cmp r0, #0xdf\n\
	bhi _08004E00\n\
	ldr r0, [r2]\n\
	ldr r1, [r3, #8]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	asrs r3, r0, #0x10\n\
	adds r1, r3, #0\n\
	adds r1, #0x80\n\
	ldr r0, _08004E0C @ =0x0000016F\n\
	cmp r1, r0\n\
	bhi _08004E00\n\
	ldr r2, [r4, #0xc]\n\
	str r2, [r5]\n\
	movs r1, #0xff\n\
	ands r1, r6\n\
	ldrb r0, [r4, #0xd]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #0xe\n\
	orrs r1, r0\n\
	ldr r0, _08004E10 @ =0x000001FF\n\
	ands r3, r0\n\
	lsls r0, r3, #0x10\n\
	orrs r1, r0\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x1c\n\
	orrs r1, r0\n\
	ldrb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x1d\n\
	orrs r1, r0\n\
	ldrb r0, [r4, #0xf]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #0x1e\n\
	orrs r1, r0\n\
	orrs r2, r1\n\
	str r2, [r5]\n\
	ldrh r1, [r4, #0x10]\n\
	strh r1, [r5, #4]\n\
	ldrh r0, [r4, #0x10]\n\
	lsls r0, r0, #0x16\n\
	lsrs r0, r0, #0x16\n\
	orrs r1, r0\n\
	strh r1, [r5, #4]\n\
	adds r0, r5, #0\n\
	adds r0, #8\n\
	str r0, [r7]\n\
_08004E00:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08004E08: .4byte gOamManager\n\
_08004E0C: .4byte 0x0000016F\n\
_08004E10: .4byte 0x000001FF\n\
 .syntax divided\n");
}
