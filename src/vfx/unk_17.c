#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

// パンテオン(ガーディアン)が粉々になって飛び散るときのエフェクト(これもパーティクルと言えなくもない...？)

static void Ghost17_Init(struct VFX* p);
static void Ghost17_Update(struct VFX* p);
static void Ghost17_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost17Routine = {
    [ENTITY_INIT] =      Ghost17_Init,
    [ENTITY_UPDATE] =    Ghost17_Update,
    [ENTITY_DIE] =       Ghost17_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct Entity* CreateGhost17_1(struct Entity* e) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_017);
    p->work[0] = 0;
    p->unk_28 = e;
  }
  return p;
}

void CreateGhost17_2(struct Entity* e, Coords32* c) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_017);
      p->work[0] = 1, p->work[1] = i;
      p->unk_28 = e;
      p->coord.x = c->x, p->coord.y = c->y;
    }
  }
}

// --------------------------------------------

static void FUN_080b6970(struct VFX* p);
static void FUN_080b6a9c(struct VFX* p);

static void Ghost17_Init(struct VFX* p) {
  static VFXFunc const sInitializers[] = {
      FUN_080b6970,
      FUN_080b6a9c,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080b6a38(struct VFX* p);
static void FUN_080b6b8c(struct Entity* p);

static void Ghost17_Update(struct VFX* p) {
  static VFXFunc const sUpdates[] = {
      (void*)FUN_080b6a38,
      (void*)FUN_080b6b8c,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void Ghost17_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED static void FUN_080b6970(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x28]\n\
	adds r6, r0, #0\n\
	adds r6, #0x54\n\
	ldrb r0, [r0, #0xa]\n\
	lsrs r5, r0, #4\n\
	movs r0, #1\n\
	ands r5, r0\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r7, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B69B4 @ =0x00001405\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	adds r2, r5, #0\n\
	cmp r5, #0\n\
	beq _080B69B8\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B69BE\n\
	.align 2, 0\n\
_080B69B4: .4byte 0x00001405\n\
_080B69B8:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B69BE:\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r2, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	strb r5, [r4, #0x11]\n\
	cmp r5, #0\n\
	beq _080B69F0\n\
	movs r0, #0x40\n\
	str r0, [r4, #0x5c]\n\
	ldr r0, [r6]\n\
	ldr r1, _080B69EC @ =0xFFFFF800\n\
	b _080B69FC\n\
	.align 2, 0\n\
_080B69EC: .4byte 0xFFFFF800\n\
_080B69F0:\n\
	movs r0, #0x40\n\
	rsbs r0, r0, #0\n\
	str r0, [r4, #0x5c]\n\
	ldr r0, [r6]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
_080B69FC:\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r6, #4]\n\
	ldr r1, _080B6A30 @ =0xFFFFE800\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0\n\
	str r0, [r4, #0x60]\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B6A34 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Ghost17_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6A30: .4byte 0xFFFFE800\n\
_080B6A34: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080b6a38(struct VFX* p) {
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  (p->s).d.y += 0x10;
  UpdateSpriteAnimation(p);
  (p->s).work[2]--;
  if ((p->s).work[2] == 0xff) {
    CreateGhost17_2((p->s).unk_28, &(p->s).coord);
    CreateSmoke(2, &(p->s).coord);
    PlaySound(0x2a);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

static void FUN_080b6a9c(struct VFX* p) {
  static const motion_t sMotions[3] = {
      MOTION(SM020_PANTHEON_GUARDIAN, 8),
      MOTION(SM020_PANTHEON_GUARDIAN, 7),
      MOTION(SM020_PANTHEON_GUARDIAN, 9),
  };  // 0x0836e870
  register s32 dx asm("r1");

  bool8 xflip = (((struct Entity*)(p->s).unk_28)->flags & X_FLIP) != 0;
  register u32 idx asm("r5") = (p->s).work[1];

  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, sMotions[idx]);
  UpdateSpriteAnimation(p);
  SET_XFLIP(&p->s, xflip);

  if (xflip) idx = 2 - idx;
  dx = (idx - 1) * PIXEL(1);

  (p->s).d.x = dx + (RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(1);
  (p->s).d.y = -(RANDOM(RNG_0202f388) & 0x1FF) - PIXEL(2);

  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost17_Update((void*)p);
}

static void FUN_080b6b8c(struct Entity* p) {
  (p->coord).x += (p->d).x;
  (p->coord).y += (p->d).y;
  (p->d).y += PIXEL(1) / 4;
  UpdateSpriteAnimation(p);
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    CreateSmoke(3, &p->coord);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}
