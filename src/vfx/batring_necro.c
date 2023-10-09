#include "global.h"
#include "story.h"
#include "vfx.h"

static const s32 *const PTR_s32_ARRAY_0836e9c4[3];

static void BatringNecro_Init(struct VFX *vfx);
static void BatringNecro_Update(struct VFX *vfx);
static void Ghost21_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gBatringNecroRoutine = {
    [ENTITY_INIT] =      BatringNecro_Init,
    [ENTITY_UPDATE] =    BatringNecro_Update,
    [ENTITY_DIE] =       Ghost21_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX *FUN_080b7680(struct Coord *c, u8 param_2) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_BATRING_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = param_2;
    (vfx->s).work[1] = 0;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
  }
  return vfx;
}

struct VFX *FUN_080b76d4(struct Coord *c, u8 r1, u16 r2, s32 r3) {
  struct VFX *vfx = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, VFX_BATRING_NECRO);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = r1;
    (vfx->s).work[1] = 1;
    (vfx->s).coord.x = c->x;
    (vfx->s).coord.y = c->y;
    (vfx->props).vfx21.unk_0 = r2;
    (vfx->props).vfx21.unk_4 = r3;
  }
  return vfx;
}

// --------------------------------------------

NAKED static void BatringNecro_Init(struct VFX *vfx) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r4, #0xa]\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x12]\n\
	ldrb r1, [r4, #0x10]\n\
	cmp r1, #0\n\
	bne _080B777E\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0x60\n\
	b _080B77A2\n\
_080B777E:\n\
	movs r1, #1\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	movs r0, #0x60\n\
	rsbs r0, r0, #0\n\
_080B77A2:\n\
	str r0, [r4, #0x5c]\n\
	movs r3, #0\n\
	str r3, [r4, #0x60]\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080B77CC\n\
	movs r0, #0xff\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B77C8 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	strb r1, [r4, #0xd]\n\
	b _080B77FE\n\
	.align 2, 0\n\
_080B77C8: .4byte gVFXFnTable\n\
_080B77CC:\n\
	ldr r2, _080B7810 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080B7814 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B7818 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #7\n\
	ands r0, r1\n\
	adds r0, #0x7f\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B781C @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
_080B77FE:\n\
	strb r3, [r4, #0xe]\n\
	strb r3, [r4, #0xf]\n\
	adds r0, r4, #0\n\
	bl BatringNecro_Update\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B7810: .4byte RNG_0202f388\n\
_080B7814: .4byte 0x000343FD\n\
_080B7818: .4byte 0x00269EC3\n\
_080B781C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_080b788c(struct VFX *vfx);
void FUN_080b7890(struct VFX *vfx);
void FUN_080b7a04(struct VFX *vfx);

static void BatringNecro_Update(struct VFX *vfx) {
  static const VFXFunc sUpdates[3] = {
      nop_080b788c,
      FUN_080b7890,
      FUN_080b7a04,
  };
  if (IS_METTAUR) {
    SET_VFX_ROUTINE(vfx, ENTITY_DIE);
    Ghost21_Die(vfx);
    return;
  }
  (sUpdates[(vfx->s).mode[1]])(vfx);
}

// --------------------------------------------

static void Ghost21_Die(struct VFX *vfx) {
  (vfx->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080b788c(struct VFX *vfx) {
  // nop
  return;
}

INCASM("asm/vfx/unk_21.inc");

// --------------------------------------------

static const s32 s32_ARRAY_0836e964[8 * 3] = {
    0x00000120, -0x00000200, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, -0x000000B0, -0x00000160, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000200, 0x00000120, -0x00000160, 0x00000120, -0x00000200, -0x000000B0, -0x00000160,
};

static const s32 *const PTR_s32_ARRAY_0836e9c4[3] = {
    &s32_ARRAY_0836e964[0],
    &s32_ARRAY_0836e964[8],
    &s32_ARRAY_0836e964[16],
};
