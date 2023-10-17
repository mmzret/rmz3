#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "weapon.h"
#include "zero.h"

static const struct Collision sCollisions[3];
static const u8 sInitModes[4];

static void Fefnir_Init(struct Zero* z);
static void Fefnir_Update(struct Zero* z);
static void Fefnir_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gFefnirRoutine = {
  [ENTITY_INIT] =       Fefnir_Init,
  [ENTITY_UPDATE] =     Fefnir_Update,
  [ENTITY_DIE]  =       Fefnir_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

void CreatePlayerFefnir(struct MinigameState* p, s32 x, s32 y) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, 1);
    (z->s).work[0] = 0;
    (z->s).coord.x = x;
    (z->s).coord.y = y;
    (z->s).unk_28 = (struct Entity*)p;
  }
}

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

static void Fefnir_Init(struct Zero* z) {
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = sInitModes[(z->s).work[0]];

  (z->s).flags |= FLIPABLE;
  (z->s).flags |= DISPLAY;
  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  INIT_BODY(z, &sCollisions[0], 6, onCollision);
  (z->s).work[3] = 0;
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  Fefnir_Update(z);
}

// --------------------------------------------

static void FUN_08034744(struct Zero* z);
static void FUN_08034774(struct Zero* z);
static void nop_08034740(struct Zero* z);

static void FUN_080347a0(struct Zero* z);
static void fefnir_080347f0(struct Zero* z);
static void fefnir_080348bc(struct Zero* z);
static void fefnir_08034974(struct Zero* z);

static void Fefnir_Update(struct Zero* z) {
  static const ZeroFunc sUpdates1[4] = {
      FUN_08034744,
      FUN_08034774,
      nop_08034740,
      nop_08034740,
  };
  static const ZeroFunc sUpdates2[4] = {
      FUN_080347a0,
      fefnir_080347f0,
      fefnir_080348bc,
      fefnir_08034974,
  };

  struct MinigameState* p = (struct MinigameState*)(z->s).unk_28;
  if ((p->unk_00[47] != 0) && ((z->s).mode[1] != 3)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  (sUpdates1[(z->s).mode[1]])(z);
  (sUpdates2[(z->s).mode[1]])(z);
  if ((z->s).coord.x <= PIXEL(9852)) {
    (z->s).coord.x = PIXEL(9852);
    (z->s).d.x = 0;
  }
  if ((z->s).coord.x >= PIXEL(10068)) {
    (z->s).coord.x = PIXEL(10068);
    (z->s).d.x = 0;
  }
}

// --------------------------------------------

static void Fefnir_Die(struct Zero* z) {
  SET_PLAYER_ROUTINE(z, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static void nop_08034740(struct Zero* z) {
  // nop
  return;
}

static void FUN_08034744(struct Zero* z) {
  struct MinigameState* p = (struct MinigameState*)(z->s).unk_28;
  if ((*(u16*)&p->unk_00[24]) & 0x30) {
    (z->s).mode[1] = 1;
    (z->s).mode[2] = 0;
  }
  if ((*(u16*)&p->unk_00[26]) & 0x02) {
    (z->s).mode[1] = 2;
    (z->s).mode[2] = 0;
  }
}

static void FUN_08034774(struct Zero* z) {
  struct MinigameState* p = (struct MinigameState*)(z->s).unk_28;
  if (((*(u16*)&p->unk_00[24]) & 0x30) == 0) {
    (z->s).mode[1] = 0;
    (z->s).mode[2] = 0;
  }
  if ((*(u16*)&p->unk_00[26]) & 0x02) {
    (z->s).mode[1] = 2;
    (z->s).mode[2] = 0;
  }
}

static void FUN_080347a0(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      (z->s).spr.xflip = FALSE;
      (z->s).spr.oam.xflip = FALSE;
      (z->s).flags &= ~X_FLIP;
      GotoMotion(&z->s, MOTION(DM161_FEFNIR, 23), 9, 4);
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      break;
    }
  }
}

NAKED static void fefnir_080347f0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r6, [r4, #0x28]\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #0\n\
	beq _08034802\n\
	cmp r5, #1\n\
	beq _08034828\n\
	b _080348B6\n\
_08034802:\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrh r2, [r6, #0x18]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #0\n\
	bl CreateParticle\n\
	ldr r1, _0803487C @ =0x0000A10C\n\
	adds r0, r4, #0\n\
	movs r2, #4\n\
	movs r3, #4\n\
	bl GotoMotion\n\
	strb r5, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08034828:\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0x12]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803484C\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrh r2, [r6, #0x18]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	bl CreateParticle\n\
_0803484C:\n\
	ldrh r1, [r6, #0x18]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08034884\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, _08034880 @ =0xFFFFFD00\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	subs r0, #0x11\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	b _080348AE\n\
	.align 2, 0\n\
_0803487C: .4byte 0x0000A10C\n\
_08034880: .4byte 0xFFFFFD00\n\
_08034884:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080348B0\n\
	ldr r0, [r4, #0x54]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r0, [r2]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r4, #0xa]\n\
	orrs r0, r1\n\
_080348AE:\n\
	strb r0, [r4, #0xa]\n\
_080348B0:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080348B6:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void fefnir_080348bc(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      PlaySound(SE_FEFNIR_ATK);
      (z->s).spr.xflip = FALSE;
      (z->s).spr.oam.xflip = FALSE;
      (z->s).flags &= ~X_FLIP;
      if ((z->s).work[3] != 0) {
        SetMotion(&z->s, MOTION(DM161_FEFNIR, 25));
        CreateWeapon6((z->s).coord.x + PIXEL(9), (z->s).coord.y - PIXEL(76));
      } else {
        SetMotion(&z->s, MOTION(DM161_FEFNIR, 24));
        CreateWeapon6((z->s).coord.x - PIXEL(9), (z->s).coord.y - PIXEL(76));
      }
      (z->s).work[2] = (z->s).work[3] * 6 + 8;
      (z->s).work[3] ^= 1;
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      (z->s).work[2]--;
      if ((z->s).work[2] == 0) {
        (z->s).mode[1] = 0;
        (z->s).mode[2] = 0;
      }
      break;
    }
  }
}

static void fefnir_08034974(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      PlaySound(SE_FEFNIR_DAMAGE);
      SetMotion(&z->s, MOTION(DM161_FEFNIR, 27));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 2,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x2000, 0x2000},
    },
};

static const u8 sInitModes[4] = {0, 0, 0, 0};
