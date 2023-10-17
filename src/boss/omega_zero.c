#include "boss.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "projectile.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"
#include "zero.h"

static const u8 gOmegaZeroMode[48];
static const u8 sInitModes[4];
static const struct Collision sCollisions[6];
static const struct Coord sExplosionCoords[2];

void CreateOzChargeSaberRock(s32 x, u8 r1);
void oz_080b3820(struct Coord *c, bool8 isRight);
void oz_080c3b44(struct Boss *p);
void oz_080c3b9c(struct Boss *p);
struct Projectile *CreateOmegaZeroSaber(struct Boss *p, u8 kind);

static const BossFunc gOmegaZeroMainRoutine1[24];
static const BossFunc gOmegaZeroMainRoutine2[24];

static void OmegaZero_Init(struct Boss *p);
static void OmegaZero_Update(struct Boss *p);
static void OmegaZero_Die(struct Boss *p);

// clang-format off
const BossRoutine gOmegaZeroRoutine = {
    [ENTITY_INIT] =      OmegaZero_Init,
    [ENTITY_UPDATE] =    OmegaZero_Update,
    [ENTITY_DIE] =       OmegaZero_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

NON_MATCH static void calcNextOmegaZeroAction(struct Boss *p) {
#if MODERN
  s32 d = abs((p->s).coord.x - (pZero2->s).coord.x);
  if (d < PIXEL(80)) {
    d = 0;  // 近距離ルーチン
  } else if (d < PIXEL(120)) {
    d = 1;  // 中距離ルーチン
  } else {
    d = 2;  // 遠距離ルーチン
  }
  d <<= 4;

  while (TRUE) {
    u32 rng;
    RNG_0202f388 = LCG(RNG_0202f388);
    rng = (RNG_0202f388 >> 16) & 0xF;

    if ((p->props.oz).prevMode == gOmegaZeroMode[d + rng]) {
      if ((p->props.oz).unk_c6 != 0) continue;
    }

    if ((p->body).hp < 33 || (gOmegaZeroMode[d + rng] != 20)) {
      if ((p->props.oz).prevMode == gOmegaZeroMode[d + rng]) {
        (p->props.oz).unk_c6++;
      } else {
        (p->props.oz).prevMode = gOmegaZeroMode[d + rng];
        (p->props.oz).unk_c6 = 0;
      }
      (p->s).mode[1] = (p->props.oz).prevMode;
      (p->s).mode[2] = 0;
      return;
    }
  }
#else
  INCCODE("asm/wip/calcNextOmegaZeroAction.inc");
#endif
}

static void oz_0805d6a8(struct Boss *p) {
  {
    s32 x = (p->props.oz).x - PIXEL(224);
    if ((p->s).coord.x < x) {
      (p->s).coord.x = x;
    }
  }

  {
    s32 x = (p->props.oz).x + PIXEL(224);
    if ((p->s).coord.x > x) {
      (p->s).coord.x = x;
    }
  }
}

// 0x0805d6d8
static void onCollision(struct Body *body, struct Coord *c1, struct Coord *c2) {
  struct Zero *z = (struct Zero *)body->enemy->parent;
  struct Boss *oz = (struct Boss *)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (oz->props.oz).isRight = (oz->s).coord.x < (z->s).coord.x;
  }
}

static bool8 tryKillOmegaZero(struct Boss *p) {
  u32 *status = &(p->body).status;

  if (((*status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && ((gStageRun.missionStatus & MISSION_FAIL) == 0)) {
    struct VFX *shadow = (p->props.oz).vfx;
    if (shadow != NULL) {
      (shadow->s).work[1] = 1;
      (p->props.oz).vfx = NULL;
    }

    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if (*status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else {
      (p->s).mode[1] = 0;
    }
    OmegaZero_Die(p);
    return TRUE;
  }

  return FALSE;
}

NON_MATCH static void OmegaZero_Init(struct Boss *p) {
#if MODERN
  struct Body *body;
  SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitModes[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  ResetBossBody(p, sCollisions, 96);
  body = &p->body;
  body->fn = onCollision;
  (p->s).palID = 4;
  (p->s).tileNum = 512;
  if ((p->s).work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM128_UNK);
    LOAD_STATIC_GRAPHIC(SM237_ROCK);
    p->props.oz.x = (p->s).coord.x >> 8;
    p->props.oz.x = ((p->props.oz.x / 240) * PIXEL(240));
    p->props.oz.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
    p->props.oz.vfx = NULL;
    p->props.oz.prevMode |= 0xFF;
    p->props.oz.unk_c6 = 0;
    (p->s).coord.y = p->props.oz.y;
    LoadZeroPalette(NULL, 8);
    SetWeaponElement(2, 4);
  }
  OmegaZero_Update(p);
#else
  INCCODE("asm/wip/OmegaZero_Init.inc");
#endif
}

// --------------------------------------------

static void nop_0805d950(struct Boss *_);
static void tryMakeFlinch(struct Boss *p);
static void ozNeutral(struct Boss *p);
static void ozMode1(struct Boss *p);
static void ozDash(struct Boss *p);
static void ozDoubleJump1(struct Boss *p);
static void ozDoubleJump2(struct Boss *p);
static void ozTripleSlash1(struct Boss *p);
static void ozTripleSlash2(struct Boss *p);
static void ozTripleSlash3(struct Boss *p);
static void double_charge_wave_1(struct Boss *p);
static void double_charge_wave_2(struct Boss *p);
static void double_charge_wave_3(struct Boss *p);
static void ozRyuenjin1(struct Boss *p);
static void ozRyuenjin2(struct Boss *p);
static void ozRyuenjin3(struct Boss *p);
static void messenkou(struct Boss *p);
static void rekkoha(struct Boss *p);
static void charge_saber(struct Boss *p);
static void arc_blade_1(struct Boss *p);
static void arc_blade_2(struct Boss *p);
static void flinched(struct Boss *p);
static void ozRanbu1(struct Boss *p);
static void ozRanbu2(struct Boss *p);
static void ozRanbu3(struct Boss *p);
static void ozRanbu4(struct Boss *p);

static void OmegaZero_Update(struct Boss *p) {
  // clang-format off
  static const BossFunc sUpdates1[24] = {
      tryMakeFlinch,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      tryMakeFlinch,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      tryMakeFlinch,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
      tryMakeFlinch,
      nop_0805d950,
      nop_0805d950,
      nop_0805d950,
  };
  static const BossFunc sUpdates2[24] = {
      ozNeutral,
      ozMode1,
      ozDash,
      ozDoubleJump1,
      ozDoubleJump2,
      ozTripleSlash1,
      ozTripleSlash2,
      ozTripleSlash3,
      double_charge_wave_1,
      double_charge_wave_2,
      double_charge_wave_3,
      ozRyuenjin1,
      ozRyuenjin2,
      ozRyuenjin3,
      messenkou,
      rekkoha,
      charge_saber,
      arc_blade_1,
      arc_blade_2,
      flinched,
      ozRanbu1,
      ozRanbu2,
      ozRanbu3,
      ozRanbu4,
  };
  // clang-format on
  bool8 isDead = tryKillOmegaZero(p);
  if (!isDead) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

static void ozDeath0(struct Boss *p);
static void ozDeath1(struct Boss *p);

static void OmegaZero_Die(struct Boss *p) {
  static const BossFunc sDeads[2] = {
      ozDeath0,
      ozDeath1,
  };
  (sDeads[(p->s).mode[1]])(p);
  return;
}

static void nop_0805d950(struct Boss *_) {
  // nop
  return;
}

// 0x0805d954
static void tryMakeFlinch(struct Boss *p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    (p->s).mode[1] = 19;
    (p->s).mode[2] = 0;
  }
}

// 01 00 -- --
static void ozNeutral(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      if ((u32)((pZero2->s).coord.x - (p->s).coord.x) + PIXEL(208) > PIXEL(416)) {
        (p->s).work[2] = 8;
      } else {
        (p->s).work[2] = 24;
      }
      SetMotion(&p->s, MOTION(DM000_ZERO_NEUTRAL, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      bool8 xflip;
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).spr.xflip = (p->s).coord.x < (pZero2->s).coord.x;
      xflip = (p->s).spr.oam.xflip = (p->s).coord.x < (pZero2->s).coord.x;
      if (xflip) {
        (p->s).flags |= X_FLIP;
      } else {
        (p->s).flags &= ~X_FLIP;
      }
      (p->s).work[2]--;
      if (!((pZero2->body).status & BODY_STATUS_DEAD) && ((pZero2->body).hp != 0) && ((p->s).work[2] == 0)) {
        calcNextOmegaZeroAction(p);
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

// 01 01 xx --
NAKED static void ozMode1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #7\n\
	bhi _0805DB2A\n\
	lsls r0, r0, #2\n\
	ldr r1, _0805DA68 @ =_0805DA6C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0805DA68: .4byte _0805DA6C\n\
_0805DA6C: @ jump table\n\
	.4byte _0805DA8C @ case 0\n\
	.4byte _0805DAA2 @ case 1\n\
	.4byte _0805DAC0 @ case 2\n\
	.4byte _0805DAE4 @ case 3\n\
	.4byte _0805DAD0 @ case 4\n\
	.4byte _0805DAE4 @ case 5\n\
	.4byte _0805DB00 @ case 6\n\
	.4byte _0805DB0E @ case 7\n\
_0805DA8C:\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	ldr r1, _0805DABC @ =0x00003F02\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DAA2:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805DAB4\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DAB4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805DB2A\n\
	.align 2, 0\n\
_0805DABC: .4byte 0x00003F02\n\
_0805DAC0:\n\
	movs r0, #0xf3\n\
	bl PlaySound\n\
	ldr r1, _0805DACC @ =0x00003F03\n\
	b _0805DAD8\n\
	.align 2, 0\n\
_0805DACC: .4byte 0x00003F03\n\
_0805DAD0:\n\
	adds r0, r4, #0\n\
	bl oz_080c39a0\n\
	ldr r1, _0805DAFC @ =0x00003F04\n\
_0805DAD8:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DAE4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805DB2A\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805DB2A\n\
	.align 2, 0\n\
_0805DAFC: .4byte 0x00003F04\n\
_0805DB00:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DB0E:\n\
	ldr r0, _0805DB30 @ =gStageRun\n\
	ldrb r0, [r0, #0x12]\n\
	movs r2, #1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _0805DB24\n\
	strb r1, [r4, #0xd]\n\
	strb r2, [r4, #0xe]\n\
	movs r0, #0x1e\n\
	strb r0, [r4, #0x12]\n\
_0805DB24:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0805DB2A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805DB30: .4byte gStageRun\n\
 .syntax divided\n");
}

// 01 02 xx --
NAKED static void ozDash(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805DBAE\n\
	cmp r0, #1\n\
	bgt _0805DB48\n\
	cmp r0, #0\n\
	beq _0805DB52\n\
	b _0805DC40\n\
_0805DB48:\n\
	cmp r0, #2\n\
	beq _0805DC00\n\
	cmp r0, #3\n\
	beq _0805DC2A\n\
	b _0805DC40\n\
_0805DB52:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0805DBF8 @ =sCollisions+72\n\
	bl SetDDP\n\
	movs r0, #0xe9\n\
	bl PlaySound\n\
	ldr r0, _0805DBFC @ =0xFFFFFC80\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805DB76\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #2\n\
_0805DB76:\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #0\n\
	bl CreateParticle\n\
	adds r0, r4, #0\n\
	bl CreateAfterImages\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	str r0, [r1]\n\
	movs r0, #0x1c\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #3\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DBAE:\n\
	ldrb r0, [r4, #0x13]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805DBCE\n\
	movs r0, #3\n\
	strb r0, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	bl CreateParticle\n\
_0805DBCE:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805DBEE\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DBEE:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805DC40\n\
	.align 2, 0\n\
_0805DBF8: .4byte sCollisions+72\n\
_0805DBFC: .4byte 0xFFFFFC80\n\
_0805DC00:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0805DC48 @ =sCollisions+24\n\
	bl SetDDP\n\
	adds r3, r4, #0\n\
	adds r3, #0xbc\n\
	ldr r2, [r3]\n\
	cmp r2, #0\n\
	beq _0805DC1C\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x11]\n\
	str r1, [r3]\n\
_0805DC1C:\n\
	ldr r1, _0805DC4C @ =0x00000301\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DC2A:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805DC40\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0805DC40:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805DC48: .4byte sCollisions+24\n\
_0805DC4C: .4byte 0x00000301\n\
 .syntax divided\n");
}

// 01 03 xx --
NAKED static void ozDoubleJump1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805DC98\n\
	cmp r0, #1\n\
	bgt _0805DC64\n\
	cmp r0, #0\n\
	beq _0805DC6E\n\
	b _0805DD12\n\
_0805DC64:\n\
	cmp r0, #2\n\
	beq _0805DCD0\n\
	cmp r0, #3\n\
	beq _0805DCE4\n\
	b _0805DD12\n\
_0805DC6E:\n\
	ldr r0, _0805DCC8 @ =0xFFFFFE00\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805DC82\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
_0805DC82:\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805DCCC @ =0xFFFFFB00\n\
	str r0, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DC98:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	cmp r0, #0\n\
	ble _0805DCB6\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DCB6:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805DD12\n\
	.align 2, 0\n\
_0805DCC8: .4byte 0xFFFFFE00\n\
_0805DCCC: .4byte 0xFFFFFB00\n\
_0805DCD0:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805DD18 @ =0xFFFFFC00\n\
	str r0, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DCE4:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	cmp r0, #0\n\
	ble _0805DD04\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805DD04:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0805DD12:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805DD18: .4byte 0xFFFFFC00\n\
 .syntax divided\n");
}

// 01 04 xx --
static void ozDoubleJump2(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetMotion(&p->s, MOTION(DM004_ZERO_AIR, 0x01));
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      break;
    }
    default: {
      return;
    }
  }

  (p->s).coord.x += (p->s).d.x;
  oz_0805d6a8(p);

  (p->s).d.y += 0x40;
  if (PIXEL(7) < (p->s).d.y) {
    (p->s).d.y = PIXEL(7);
  }

  (p->s).coord.y += (p->s).d.y;
  if ((p->s).coord.y >= p->props.oz.y) {
    (p->s).coord.y = p->props.oz.y;
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
  UpdateMotionGraphic(&p->s);
}

// 01 05 xx --
static void ozTripleSlash1(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      PlaySound(SE_OMEGAZERO_VOICE_ea);
      CreateOmegaZeroSaber(p, 0);
      SetMotion(&p->s, MOTION(DM014_ZERO_SABER_TRIPLE1, 0x00));
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      break;
    }
    default: {
      return;
    }
  }

  UpdateMotionGraphic(&p->s);
  if ((p->s).motion.state == MOTION_END) {
    (p->s).mode[1] = 6;
    (p->s).mode[2] = 0;
  }
}

// 01 06 xx --
static void ozTripleSlash2(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      PlaySound(SE_OMEGAZERO_VOICE_eb);
      CreateOmegaZeroSaber(p, 1);
      SetMotion(&p->s, MOTION(DM015_ZERO_SABER_TRIPLE2, 0x00));
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      break;
    }
    default: {
      return;
    }
  }

  UpdateMotionGraphic(&p->s);
  if ((p->s).motion.state == MOTION_END) {
    (p->s).mode[1] = 7;
    (p->s).mode[2] = 0;
  }
}

// 01 07 xx --
static void ozTripleSlash3(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      PlaySound(SE_OMEGAZERO_VOICE_ec);
      CreateOmegaZeroSaber(p, 2);
      SetMotion(&p->s, MOTION(DM016_ZERO_SABER_TRIPLE3, 0x00));
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      break;
    }
    default: {
      return;
    }
  }

  UpdateMotionGraphic(&p->s);
  if ((p->s).motion.state == MOTION_END) {
    (p->s).mode[1] = 0;
    (p->s).mode[2] = 0;
  }
}

// 01 08 xx --
NAKED static void double_charge_wave_1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805DE9C\n\
	cmp r0, #1\n\
	bgt _0805DE7C\n\
	cmp r0, #0\n\
	beq _0805DE86\n\
	b _0805DEDC\n\
_0805DE7C:\n\
	cmp r0, #2\n\
	beq _0805DEB6\n\
	cmp r0, #3\n\
	beq _0805DEC4\n\
	b _0805DEDC\n\
_0805DE86:\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	bl oz_080c3b44\n\
	adds r0, r4, #0\n\
	bl oz_080c3b9c\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DE9C:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805DEAE\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DEAE:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805DEDC\n\
_0805DEB6:\n\
	ldr r1, _0805DEE4 @ =0x00000803\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DEC4:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805DEDC\n\
	movs r1, #0\n\
	movs r0, #9\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805DEDC:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805DEE4: .4byte 0x00000803\n\
 .syntax divided\n");
}

// 01 09 xx --
NAKED static void double_charge_wave_2(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #7\n\
	bhi _0805DFAE\n\
	lsls r0, r0, #2\n\
	ldr r1, _0805DEFC @ =_0805DF00\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0805DEFC: .4byte _0805DF00\n\
_0805DF00: @ jump table\n\
	.4byte _0805DF20 @ case 0\n\
	.4byte _0805DF6C @ case 1\n\
	.4byte _0805DF2E @ case 2\n\
	.4byte _0805DF38 @ case 3\n\
	.4byte _0805DF52 @ case 4\n\
	.4byte _0805DF6C @ case 5\n\
	.4byte _0805DF88 @ case 6\n\
	.4byte _0805DF96 @ case 7\n\
_0805DF20:\n\
	movs r0, #0xed\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	bl CreateDoubleChargeWave1\n\
	b _0805DF5E\n\
_0805DF2E:\n\
	movs r0, #0xc\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DF38:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805DF4A\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DF4A:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805DFAE\n\
_0805DF52:\n\
	movs r0, #0xed\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	bl CreateDoubleChargeWave2\n\
_0805DF5E:\n\
	ldr r1, _0805DF84 @ =0x00000804\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DF6C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805DFAE\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805DFAE\n\
	.align 2, 0\n\
_0805DF84: .4byte 0x00000804\n\
_0805DF88:\n\
	ldr r1, _0805DFB4 @ =0x00000802\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DF96:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805DFAE\n\
	movs r1, #0\n\
	movs r0, #0xa\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805DFAE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805DFB4: .4byte 0x00000802\n\
 .syntax divided\n");
}

// 01 0A xx --
NAKED static void double_charge_wave_3(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805DFE8\n\
	cmp r0, #1\n\
	bgt _0805DFCC\n\
	cmp r0, #0\n\
	beq _0805DFD6\n\
	b _0805E060\n\
_0805DFCC:\n\
	cmp r0, #2\n\
	beq _0805E002\n\
	cmp r0, #3\n\
	beq _0805E01C\n\
	b _0805E060\n\
_0805DFD6:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl SetMotion\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DFE8:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805DFFA\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805DFFA:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E060\n\
_0805E002:\n\
	movs r0, #0xee\n\
	bl PlaySound\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E01C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	cmp r1, #1\n\
	bne _0805E03E\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	bne _0805E03E\n\
	strb r1, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	movs r1, #3\n\
	bl CreateOmegaZeroSaber\n\
_0805E03E:\n\
	ldr r0, [r4, #0x70]\n\
	ldr r1, _0805E068 @ =0x00FFFF00\n\
	ands r0, r1\n\
	ldr r1, _0805E06C @ =0x00010300\n\
	cmp r0, r1\n\
	bne _0805E050\n\
	adds r0, r4, #0\n\
	bl CreateDoubleChargeWave3\n\
_0805E050:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E060\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0805E060:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E068: .4byte 0x00FFFF00\n\
_0805E06C: .4byte 0x00010300\n\
 .syntax divided\n");
}

// 01 0B xx --
NAKED static void ozRyuenjin1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805E0EC\n\
	cmp r0, #1\n\
	bgt _0805E084\n\
	cmp r0, #0\n\
	beq _0805E090\n\
	b _0805E1AE\n\
_0805E084:\n\
	cmp r0, #2\n\
	beq _0805E15C\n\
	cmp r0, #3\n\
	bne _0805E08E\n\
	b _0805E196\n\
_0805E08E:\n\
	b _0805E1AE\n\
_0805E090:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0805E14C @ =sCollisions+72\n\
	bl SetDDP\n\
	movs r0, #0xe9\n\
	bl PlaySound\n\
	ldr r0, _0805E150 @ =0xFFFFFC80\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805E0B4\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #2\n\
_0805E0B4:\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #0\n\
	bl CreateParticle\n\
	adds r0, r4, #0\n\
	bl CreateAfterImages\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	str r0, [r1]\n\
	movs r0, #0x1c\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #3\n\
	strb r0, [r4, #0x13]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E0EC:\n\
	ldrb r0, [r4, #0x13]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805E10C\n\
	movs r0, #3\n\
	strb r0, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	bl CreateParticle\n\
_0805E10C:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0805E13C\n\
	ldr r0, _0805E154 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	ldr r1, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	ldr r1, _0805E158 @ =0x00002FFF\n\
	cmp r0, r1\n\
	bhi _0805E142\n\
_0805E13C:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E142:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E1AE\n\
	.align 2, 0\n\
_0805E14C: .4byte sCollisions+72\n\
_0805E150: .4byte 0xFFFFFC80\n\
_0805E154: .4byte pZero2\n\
_0805E158: .4byte 0x00002FFF\n\
_0805E15C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0805E1B4 @ =sCollisions+24\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	movs r1, #4\n\
	bl CreateOmegaZeroSaber\n\
	movs r0, #0xef\n\
	bl PlaySound\n\
	adds r3, r4, #0\n\
	adds r3, #0xbc\n\
	ldr r2, [r3]\n\
	cmp r2, #0\n\
	beq _0805E186\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x11]\n\
	str r1, [r3]\n\
_0805E186:\n\
	movs r1, #0x90\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E196:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E1AE\n\
	movs r1, #0\n\
	movs r0, #0xc\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E1AE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E1B4: .4byte sCollisions+24\n\
 .syntax divided\n");
}

/*
  01 0C xx --
  Jump up
*/
NAKED static void ozRyuenjin2(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _0805E1C8\n\
	cmp r0, #1\n\
	beq _0805E1FE\n\
	b _0805E26A\n\
_0805E1C8:\n\
	adds r0, r4, #0\n\
	movs r1, #5\n\
	bl CreateOmegaZeroSaber\n\
	adds r1, r4, #0\n\
	adds r1, #0xc0\n\
	str r0, [r1]\n\
	ldr r0, _0805E270 @ =0xFFFFFF00\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805E1EA\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
_0805E1EA:\n\
	str r2, [r4, #0x5c]\n\
	ldr r0, _0805E274 @ =0xFFFFFA00\n\
	str r0, [r4, #0x60]\n\
	ldr r1, _0805E278 @ =0x00001201\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E1FE:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r1, [r4, #0x60]\n\
	adds r1, #0x40\n\
	str r1, [r4, #0x60]\n\
	ldr r0, [r4, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	cmp r1, #0\n\
	ble _0805E264\n\
	adds r0, r4, #0\n\
	adds r0, #0xc0\n\
	ldr r3, [r0]\n\
	cmp r3, #0\n\
	beq _0805E25C\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	adds r0, r3, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	ldr r1, _0805E27C @ =gProjectileFnTable\n\
	ldrb r0, [r3, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r3, #0x14]\n\
_0805E25C:\n\
	movs r1, #0\n\
	movs r0, #0xd\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E264:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0805E26A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E270: .4byte 0xFFFFFF00\n\
_0805E274: .4byte 0xFFFFFA00\n\
_0805E278: .4byte 0x00001201\n\
_0805E27C: .4byte gProjectileFnTable\n\
 .syntax divided\n");
}

/*
  01 0D xx --
  Fall down
*/
static void ozRyuenjin3(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      CreateOmegaZeroSaber(p, 6);
      SetMotion(&p->s, MOTION(DM018_ZERO_SABER_TENRETSUJIN, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).coord.x += (p->s).d.x;
      oz_0805d6a8(p);
      (p->s).d.y += PIXEL(1) / 4;
      if ((p->s).d.y > PIXEL(7)) {
        (p->s).d.y = PIXEL(7);
      }
      (p->s).coord.y += (p->s).d.y;
      if ((p->s).coord.y >= p->props.oz.y) {
        (p->s).coord.y = p->props.oz.y;
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

/*
  01 0E xx --
  滅閃光
*/
NAKED static void messenkou(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _0805E32A\n\
	cmp r5, #1\n\
	bgt _0805E304\n\
	cmp r5, #0\n\
	beq _0805E30E\n\
	b _0805E392\n\
_0805E304:\n\
	cmp r5, #2\n\
	beq _0805E36E\n\
	cmp r5, #3\n\
	beq _0805E37C\n\
	b _0805E392\n\
_0805E30E:\n\
	adds r0, r4, #0\n\
	bl FUN_080c39e8\n\
	movs r0, #0x1e\n\
	strb r0, [r4, #0x12]\n\
	strb r5, [r4, #0x13]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E32A:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805E33C\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E33C:\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	bne _0805E366\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _0805E366\n\
	movs r0, #0xf1\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	bl ozMessenkou2\n\
	adds r0, r4, #0\n\
	bl CreateMessenkou\n\
	movs r0, #1\n\
	strb r0, [r4, #0x13]\n\
_0805E366:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E392\n\
_0805E36E:\n\
	ldr r1, _0805E398 @ =0x00003F01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E37C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E392\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0805E392:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E398: .4byte 0x00003F01\n\
 .syntax divided\n");
}

/*
  01 0F xx --
  裂光覇
*/
NAKED static void rekkoha(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r4, [r5, #0xe]\n\
	cmp r4, #1\n\
	beq _0805E3D6\n\
	cmp r4, #1\n\
	bgt _0805E3B0\n\
	cmp r4, #0\n\
	beq _0805E3BA\n\
	b _0805E454\n\
_0805E3B0:\n\
	cmp r4, #2\n\
	beq _0805E430\n\
	cmp r4, #3\n\
	beq _0805E43E\n\
	b _0805E454\n\
_0805E3BA:\n\
	adds r0, r5, #0\n\
	bl oz_Rekkoha_080c3a5c\n\
	movs r0, #0x5a\n\
	strb r0, [r5, #0x12]\n\
	strb r4, [r5, #0x13]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #6\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_0805E3D6:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0805E3E8\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_0805E3E8:\n\
	ldrb r0, [r5, #0x13]\n\
	cmp r0, #0\n\
	bne _0805E422\n\
	adds r0, r5, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _0805E422\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0805E42C @ =0x083651A4\n\
	bl SetDDP\n\
	movs r0, #0xf0\n\
	bl PlaySound\n\
	movs r4, #0\n\
_0805E40E:\n\
	lsls r1, r4, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r5, #0\n\
	bl ozRekkoha_080ae300\n\
	adds r4, #1\n\
	cmp r4, #4\n\
	ble _0805E40E\n\
	movs r0, #1\n\
	strb r0, [r5, #0x13]\n\
_0805E422:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E454\n\
	.align 2, 0\n\
_0805E42C: .4byte 0x083651A4\n\
_0805E430:\n\
	ldr r1, _0805E45C @ =0x00003F01\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_0805E43E:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E454\n\
	movs r0, #0\n\
	strb r0, [r5, #0xd]\n\
	strb r0, [r5, #0xe]\n\
_0805E454:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E45C: .4byte 0x00003F01\n\
 .syntax divided\n");
}

// 01 10 xx --
static void charge_saber(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).work[2] = 24;
      oz_080c3b44(p);
      oz_080c3b9c(p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
    case 2: {
      (p->s).work[2] = 0;
      PlaySound(SE_OMEGAZERO_CHARGE_SABER);
      CreateOmegaZeroSaber(p, 7);
      SetMotion(&p->s, MOTION(DM020_ZERO_SABER_CHARGE, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateMotionGraphic(&p->s);
      if ((*(u32 *)&(p->s).motion.step & 0xffff00) == 0x10300) {
        s32 x = (p->s).coord.x - PIXEL(48);
        if ((p->s).flags & X_FLIP) {
          x = (p->s).coord.x + PIXEL(48);
        }
        CreateOzChargeSaberRock(x, 0);
        oz_080b3820(&(p->s).coord, (p->s).flags >> 4 & 1);
        AppendQuake(3, &(p->s).coord);
      }
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[1] = 0;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

// 01 11 xx --
NAKED static void arc_blade_1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805E584\n\
	cmp r0, #1\n\
	bgt _0805E550\n\
	cmp r0, #0\n\
	beq _0805E55A\n\
	b _0805E5FE\n\
_0805E550:\n\
	cmp r0, #2\n\
	beq _0805E5BC\n\
	cmp r0, #3\n\
	beq _0805E5D0\n\
	b _0805E5FE\n\
_0805E55A:\n\
	ldr r0, _0805E5B4 @ =0xFFFFFE00\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805E56E\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
_0805E56E:\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805E5B8 @ =0xFFFFFB00\n\
	str r0, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E584:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	cmp r0, #0\n\
	ble _0805E5A2\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E5A2:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E5FE\n\
	.align 2, 0\n\
_0805E5B4: .4byte 0xFFFFFE00\n\
_0805E5B8: .4byte 0xFFFFFB00\n\
_0805E5BC:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805E604 @ =0xFFFFFC00\n\
	str r0, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E5D0:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	cmp r0, #0\n\
	ble _0805E5F0\n\
	movs r1, #0\n\
	movs r0, #0x12\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E5F0:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0805E5FE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E604: .4byte 0xFFFFFC00\n\
 .syntax divided\n");
}

// 01 12 xx --
NAKED static void arc_blade_2(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _0805E648\n\
	cmp r5, #1\n\
	bgt _0805E61C\n\
	cmp r5, #0\n\
	beq _0805E626\n\
	b _0805E6C2\n\
_0805E61C:\n\
	cmp r5, #2\n\
	beq _0805E684\n\
	cmp r5, #3\n\
	beq _0805E69E\n\
	b _0805E6C2\n\
_0805E626:\n\
	movs r0, #0xee\n\
	bl PlaySound\n\
	strb r5, [r4, #0x12]\n\
	strb r5, [r4, #0x13]\n\
	adds r0, r4, #0\n\
	movs r1, #8\n\
	bl CreateOmegaZeroSaber\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E648:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	bne _0805E666\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #6\n\
	bhi _0805E666\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	bl createOzArcBlade\n\
	movs r0, #2\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
_0805E666:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E6C2\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805E6C2\n\
_0805E684:\n\
	movs r0, #0\n\
	str r0, [r4, #0x5c]\n\
	adds r0, r4, #0\n\
	movs r1, #9\n\
	bl CreateOmegaZeroSaber\n\
	ldr r1, _0805E6C8 @ =0x00001901\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E69E:\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	ldr r1, [r4, #0x58]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E6C2\n\
	movs r1, #0\n\
	movs r0, #4\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E6C2:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E6C8: .4byte 0x00001901\n\
 .syntax divided\n");
}

// 0x0805e6cc
NAKED static void flinched(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _0805E714\n\
	cmp r5, #1\n\
	bgt _0805E6E0\n\
	cmp r5, #0\n\
	beq _0805E6EA\n\
	b _0805E794\n\
_0805E6E0:\n\
	cmp r5, #2\n\
	beq _0805E754\n\
	cmp r5, #3\n\
	beq _0805E77A\n\
	b _0805E794\n\
_0805E6EA:\n\
	movs r0, #0xf2\n\
	bl PlaySound\n\
	movs r1, #0xc8\n\
	lsls r1, r1, #6\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	str r1, [r4, #0x5c]\n\
	adds r0, r4, #0\n\
	adds r0, #0xc4\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #9\n\
	subs r1, r1, r0\n\
	str r1, [r4, #0x5c]\n\
	str r5, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E714:\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _0805E724\n\
	str r1, [r4, #0x60]\n\
_0805E724:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r1, r4, #0\n\
	adds r1, #0xb8\n\
	ldr r1, [r1]\n\
	cmp r0, r1\n\
	ble _0805E73E\n\
	str r1, [r4, #0x58]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E73E:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	b _0805E794\n\
_0805E754:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E794\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805E794\n\
_0805E77A:\n\
	adds r0, r4, #0\n\
	movs r1, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	movs r0, #1\n\
	strb r0, [r4, #0xe]\n\
	movs r0, #0xa\n\
	strb r0, [r4, #0x12]\n\
_0805E794:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 01 14 xx --
NAKED static void ozRanbu1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	beq _0805E7AC\n\
	cmp r0, #1\n\
	beq _0805E7E2\n\
	b _0805E862\n\
_0805E7AC:\n\
	adds r0, r4, #0\n\
	bl CreateAfterImages\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	str r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805E868 @ =0xFFFFFB80\n\
	str r0, [r4, #0x5c]\n\
	adds r2, r0, #0\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805E7D6\n\
	movs r2, #0x90\n\
	lsls r2, r2, #3\n\
_0805E7D6:\n\
	str r2, [r4, #0x5c]\n\
	ldr r0, _0805E86C @ =0xFFFFFF00\n\
	str r0, [r4, #0x60]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E7E2:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	bl oz_0805d6a8\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x10\n\
	str r0, [r4, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _0805E800\n\
	str r1, [r4, #0x60]\n\
_0805E800:\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldr r2, [r0]\n\
	adds r5, r0, #0\n\
	cmp r1, r2\n\
	ble _0805E830\n\
	adds r3, r4, #0\n\
	adds r3, #0xbc\n\
	ldr r2, [r3]\n\
	cmp r2, #0\n\
	beq _0805E826\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x11]\n\
	str r1, [r3]\n\
_0805E826:\n\
	ldr r0, [r5]\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0805E830:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805E85C\n\
	adds r3, r4, #0\n\
	adds r3, #0xbc\n\
	ldr r2, [r3]\n\
	cmp r2, #0\n\
	beq _0805E850\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x11]\n\
	str r1, [r3]\n\
_0805E850:\n\
	ldr r0, [r5]\n\
	str r0, [r4, #0x58]\n\
	movs r1, #0\n\
	movs r0, #0x15\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E85C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_0805E862:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E868: .4byte 0xFFFFFB80\n\
_0805E86C: .4byte 0xFFFFFF00\n\
 .syntax divided\n");
}

// 01 15 xx --
NAKED static void ozRanbu2(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805E918\n\
	cmp r0, #1\n\
	bgt _0805E884\n\
	cmp r0, #0\n\
	beq _0805E88E\n\
	b _0805E978\n\
_0805E884:\n\
	cmp r0, #2\n\
	beq _0805E93C\n\
	cmp r0, #3\n\
	beq _0805E95A\n\
	b _0805E978\n\
_0805E88E:\n\
	movs r0, #0xea\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl CreateOmegaZeroSaber\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _0805E8EC @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	str r1, [r4, #0x64]\n\
	movs r2, #0\n\
	ldr r0, [r4, #0x54]\n\
	cmp r0, r1\n\
	bge _0805E8B8\n\
	movs r2, #1\n\
_0805E8B8:\n\
	adds r5, r2, #0\n\
	movs r3, #1\n\
	adds r1, r5, #0\n\
	ands r1, r3\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r4\n\
	mov ip, r0\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0805E8F0\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _0805E8F6\n\
	.align 2, 0\n\
_0805E8EC: .4byte pZero2\n\
_0805E8F0:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0805E8F6:\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, [r4, #0x64]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #5\n\
	adds r1, r1, r0\n\
	lsls r0, r5, #1\n\
	adds r0, r0, r5\n\
	lsls r0, r0, #0xc\n\
	subs r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	ldr r0, _0805E938 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x58]\n\
	str r0, [r4, #0x68]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E918:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E978\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805E978\n\
	.align 2, 0\n\
_0805E938: .4byte pZero2\n\
_0805E93C:\n\
	movs r0, #0xeb\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	movs r1, #0xb\n\
	bl CreateOmegaZeroSaber\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E95A:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805E978\n\
	movs r1, #0\n\
	movs r0, #0x16\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805E978:\n\
	ldr r0, _0805E98C @ =pZero2\n\
	ldr r1, [r0]\n\
	ldr r0, [r4, #0x64]\n\
	str r0, [r1, #0x54]\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r1, #0x58]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805E98C: .4byte pZero2\n\
 .syntax divided\n");
}

// 01 16 xx --
NAKED static void ozRanbu3(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	beq _0805E9C6\n\
	cmp r5, #1\n\
	bgt _0805E9A4\n\
	cmp r5, #0\n\
	beq _0805E9AE\n\
	b _0805EA3C\n\
_0805E9A4:\n\
	cmp r5, #2\n\
	beq _0805EA00\n\
	cmp r5, #3\n\
	beq _0805EA1E\n\
	b _0805EA3C\n\
_0805E9AE:\n\
	movs r0, #0xee\n\
	bl PlaySound\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	strb r5, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805E9C6:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	cmp r1, #1\n\
	bne _0805E9EE\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	bne _0805E9EE\n\
	strb r1, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	movs r1, #0xc\n\
	bl CreateOmegaZeroSaber\n\
_0805E9EE:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805EA3C\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805EA3C\n\
_0805EA00:\n\
	movs r0, #0xeb\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	movs r1, #0xd\n\
	bl CreateOmegaZeroSaber\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805EA1E:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805EA3C\n\
	movs r1, #0\n\
	movs r0, #0x17\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805EA3C:\n\
	ldr r0, _0805EA50 @ =pZero2\n\
	ldr r1, [r0]\n\
	ldr r0, [r4, #0x64]\n\
	str r0, [r1, #0x54]\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r1, #0x58]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805EA50: .4byte pZero2\n\
 .syntax divided\n");
}

// 01 17 xx --
NAKED static void ozRanbu4(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _0805EA90\n\
	cmp r0, #1\n\
	bgt _0805EA68\n\
	cmp r0, #0\n\
	beq _0805EA72\n\
	b _0805EB02\n\
_0805EA68:\n\
	cmp r0, #2\n\
	beq _0805EAAE\n\
	cmp r0, #3\n\
	beq _0805EAC8\n\
	b _0805EB02\n\
_0805EA72:\n\
	movs r0, #0xec\n\
	bl PlaySound\n\
	adds r0, r4, #0\n\
	movs r1, #0xe\n\
	bl CreateOmegaZeroSaber\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805EA90:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805EB02\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _0805EB02\n\
_0805EAAE:\n\
	movs r0, #0xee\n\
	bl PlaySound\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805EAC8:\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	cmp r1, #1\n\
	bne _0805EAF0\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	bne _0805EAF0\n\
	strb r1, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	movs r1, #0xf\n\
	bl CreateOmegaZeroSaber\n\
_0805EAF0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0805EB02\n\
	movs r1, #0\n\
	movs r0, #0xb\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0805EB02:\n\
	ldr r0, _0805EB14 @ =pZero2\n\
	ldr r1, [r0]\n\
	ldr r0, [r4, #0x64]\n\
	str r0, [r1, #0x54]\n\
	ldr r0, [r4, #0x68]\n\
	str r0, [r1, #0x58]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805EB14: .4byte pZero2\n\
 .syntax divided\n");
}

// 02 00 xx --
static void ozDeath0(struct Boss *p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= ~COLLIDABLE;
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & 1)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      (p->s).work[2] = 80;
      SetMotion(&p->s, MOTION(DM050_ZERO_STUN, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      (p->s).work[2]--;
      if ((p->s).scriptEntity->flags & (1 << 7)) {
        (p->s).mode[2]++;
      }
      break;
    }

    case 2: {
      (p->s).unk_2c = (struct Entity *)CreateBossExplosion(p, (struct Coord *)sExplosionCoords);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      if (((p->s).unk_2c)->mode[0] >= 2) {
        gStageRun.vm.active |= (1 << 1);
        (p->s).mode[2]++;
      }
      break;
    }

    case 4: {
      break;
    }
  }
}

// 02 01 xx --
NAKED static void ozDeath1(struct Boss *p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #4\n\
	bhi _0805ECB8\n\
	lsls r0, r0, #2\n\
	ldr r1, _0805EC04 @ =_0805EC08\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0805EC04: .4byte _0805EC08\n\
_0805EC08: @ jump table\n\
	.4byte _0805EC1C @ case 0\n\
	.4byte _0805EC68 @ case 1\n\
	.4byte _0805EC90 @ case 2\n\
	.4byte _0805ECA0 @ case 3\n\
	.4byte _0805ECB8 @ case 4\n\
_0805EC1C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r3, _0805EC84 @ =gStageRun\n\
	ldrh r2, [r3, #8]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0805EC56\n\
	ldrb r1, [r3, #0x12]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0805EC56\n\
	ldr r0, _0805EC88 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
_0805EC56:\n\
	movs r0, #0x50\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _0805EC8C @ =0x00003201\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805EC68:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0805ECB8\n\
	b _0805ECB2\n\
	.align 2, 0\n\
_0805EC84: .4byte gStageRun\n\
_0805EC88: .4byte 0x0000FFFE\n\
_0805EC8C: .4byte 0x00003201\n\
_0805EC90:\n\
	ldr r1, _0805ECC0 @ =0x083651F8\n\
	adds r0, r4, #0\n\
	bl CreateBossExplosion\n\
	str r0, [r4, #0x2c]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805ECA0:\n\
	ldr r0, [r4, #0x2c]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0805ECB8\n\
	ldr r2, _0805ECC4 @ =gStageRun\n\
	ldrb r1, [r2, #0x12]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x12]\n\
_0805ECB2:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_0805ECB8:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805ECC0: .4byte 0x083651F8\n\
_0805ECC4: .4byte gStageRun\n\
 .syntax divided\n");
}

static const struct Collision sCollisions[6] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      comboLv : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(10), PIXEL(26), PIXEL(22)},
    },

    // --------------------------------------------

    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(14), PIXEL(16), PIXEL(30)},
    },
};

static const u8 gOmegaZeroMode[48] = {
    5, 5, 5, 5, 5, 5, 11, 11, 15, 15, 15, 15, 16, 16, 16, 16, 8, 8, 8, 8, 11, 11, 20, 20, 14, 14, 14, 14, 17, 17, 17, 17, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 11, 11, 11, 11,
};

static const u8 sInitModes[4] = {1, 0, 0, 0};

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(28)},
    {PIXEL(0), -PIXEL(28)},
};
