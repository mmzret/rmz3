#include "blink.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "vfx.h"
#include "zero.h"

static const struct Collision sCollision;

static void CopyXMini_Init(struct Zero* z);
static void CopyXMini_Update(struct Zero* z);
static void CopyXMini_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gCopyXMiniRoutine = {
  [ENTITY_INIT] =       CopyXMini_Init,
  [ENTITY_UPDATE] =     CopyXMini_Update,
  [ENTITY_DIE]  =       CopyXMini_Die,
  [ENTITY_DISAPPEAR] =  RemovePlayer,
  [ENTITY_EXIT] =       (ZeroFunc)DeleteEntity,
};
// clang-format on

struct Zero* CreatePlayerCopyX(struct MinigameState* p, struct Coord* c, u8 n) {
  struct Zero* z = AllocPlayer();
  if (z != NULL) {
    (z->s).taskCol = 16;
    INIT_PLAYER_ROUTINE(z, PLAYER_MINIGAME_COPY_X);
    (z->s).coord = *c;
    (z->s).work[0] = n;
    (z->s).unk_28 = (struct Entity*)p;
  }
  return z;
}

static void CopyXMini_Init(struct Zero* z) {
  struct Coord c;

  InitNonAffineMotion(&z->s);
  ResetDynamicMotion(&z->s);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;

  (z->s).spr.xflip = TRUE;
  (z->s).spr.oam.xflip = TRUE;
  (z->s).flags |= X_FLIP;
  INIT_BODY(z, &sCollision, 32, NULL);
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;

  c = (z->s).coord;
  (z->mg).copyx.unk_280[1] = (struct Entity*)CreateCopyXIcon(z, &c, 0);
  (z->mg).copyx.unk_280[0] = (struct Entity*)CreateCopyXIcon(z, &c, 1);
  (z->mg).copyx.unk_280[2] = (struct Entity*)CreateCopyXIcon(z, &c, 2);
  (z->mg).copyx.life = 3;
  CopyXMini_Update(z);
}

// --------------------------------------------

static bool32 Update1_0(struct Zero* z);
static bool32 Update1_1(struct Zero* z);
static bool32 Update1_2(struct Zero* z);
static bool32 Update1_3(struct Zero* z);

static void Update2_0(struct Zero* z);
static void Update2_1(struct Zero* z);
static void Update2_2(struct Zero* z);
static void Update2_3(struct Zero* z);

#define STATE ((struct MinigameState*)(z->s).unk_28)

// 0x080359a8
static void CopyXMini_Update(struct Zero* z) {
  static const ZeroFunc sUpdates1[4] = {
      (ZeroFunc)Update1_0,
      (ZeroFunc)Update1_1,
      (ZeroFunc)Update1_2,
      (ZeroFunc)Update1_3,
  };
  static const ZeroFunc sUpdates2[4] = {
      Update2_0,
      Update2_1,
      Update2_2,
      Update2_3,
  };

  if (STATE->unk_04 != 2) {
    (sUpdates1[(z->s).mode[1]])(z);
    (sUpdates2[(z->s).mode[1]])(z);
  }

  if ((z->mg).copyx.life != STATE->unk_0c) {
    (z->mg).copyx.life = STATE->unk_0c;
    if ((z->mg).copyx.life == 2) {
      PlaySound(SE_NOT_ALLOWED);
    } else if ((z->mg).copyx.life == 1) {
      PlaySound(SE_COPYX_RECOVER_VOICE);  // ﾓｳﾕﾙｻﾝ!
    } else if ((z->mg).copyx.life == 0) {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 19));
      UpdateMotionGraphic(&z->s);
      PlaySound(SE_COPYX_STUN);
    }
  } else if ((z->mg).copyx.life == 0) {
    UpdateMotionGraphic(&z->s);
  }
}

#undef STATE

// --------------------------------------------

static void CopyXMini_Die(struct Zero* z) {
  // nop
  return;
}

// --------------------------------------------

// 0x08035a40
static bool32 Update1_0(struct Zero* z) { return TRUE; }

// 0x08035a44
static void Update2_0(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 0));
      z->mg.copyx.element = 0;  // flame
      LoadBlink(93, 640);
      (z->s).work[2] = 60;
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      if ((z->s).work[2] == 0 || (--(z->s).work[2] == 0)) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
    }
  }
}

// ----------------------------------------------

// 0x08035a9c
static bool32 Update1_1(struct Zero* z) {
  struct MinigameState* s = (struct MinigameState*)(z->s).unk_28;
  if (s->unk_04 == 1) {
    if (gJoypad[0].pressed & (R_BUTTON | L_BUTTON)) {
      (z->s).mode[1] = 2;
      (z->s).mode[2] = 0;
      if (gJoypad[0].pressed & L_BUTTON) {
        (z->s).mode[3] = 0;
      } else {
        (z->s).mode[3] = 1;
      }
    }
    if (gJoypad[0].pressed & B_BUTTON) {
      (z->s).mode[1] = 3;
      (z->s).mode[2] = 0;
    }
  }
  return TRUE;
}

// 0x08035af0
static void Update2_1(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 0));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      break;
    }
  }
}

// ----------------------------------------------

// 0x08035b1c
static bool32 Update1_2(struct Zero* z) {
  if (((z->s).mode[2] >= 2) && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

// 0x08035b44
NAKED static void Update2_2(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0xe]\n\
	cmp r5, #1\n\
	bne _08035B50\n\
	b _08035C62\n\
_08035B50:\n\
	cmp r5, #1\n\
	bgt _08035B5A\n\
	cmp r5, #0\n\
	beq _08035B68\n\
	b _08035CD0\n\
_08035B5A:\n\
	cmp r5, #2\n\
	bne _08035B60\n\
	b _08035C8A\n\
_08035B60:\n\
	cmp r5, #3\n\
	bne _08035B66\n\
	b _08035CAC\n\
_08035B66:\n\
	b _08035CD0\n\
_08035B68:\n\
	ldr r1, _08035BA4 @ =0x0000B314\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r0, #0x45\n\
	bl PlaySound\n\
	movs r0, #0xa\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _08035BE6\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _08035BA8\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x5d\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5e\n\
	bl LoadBlink\n\
	b _08035BD8\n\
	.align 2, 0\n\
_08035BA4: .4byte 0x0000B314\n\
_08035BA8:\n\
	cmp r0, #2\n\
	bne _08035BC0\n\
	strb r5, [r1]\n\
	movs r0, #0x5f\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5d\n\
	bl LoadBlink\n\
	b _08035BD8\n\
_08035BC0:\n\
	cmp r0, #1\n\
	bne _08035BD8\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #0x5e\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5f\n\
	bl LoadBlink\n\
_08035BD8:\n\
	movs r1, #0xa1\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldr r0, [r0]\n\
	adds r0, #0x74\n\
	movs r1, #2\n\
	b _08035C44\n\
_08035BE6:\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _08035C08\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #0x5d\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5f\n\
	bl LoadBlink\n\
	b _08035C38\n\
_08035C08:\n\
	cmp r0, #2\n\
	bne _08035C22\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x5f\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5e\n\
	bl LoadBlink\n\
	b _08035C38\n\
_08035C22:\n\
	cmp r0, #1\n\
	bne _08035C38\n\
	strb r5, [r1]\n\
	movs r0, #0x5e\n\
	bl ClearBlink\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5d\n\
	bl LoadBlink\n\
_08035C38:\n\
	movs r1, #0xa1\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldr r0, [r0]\n\
	adds r0, #0x74\n\
	movs r1, #1\n\
_08035C44:\n\
	strb r1, [r0]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldr r0, [r0]\n\
	adds r0, #0x74\n\
	strb r1, [r0]\n\
	adds r2, #8\n\
	adds r0, r4, r2\n\
	ldr r0, [r0]\n\
	adds r0, #0x74\n\
	strb r1, [r0]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08035C62:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _08035CA0\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _08035CA4\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08035CD0\n\
	b _08035CA4\n\
_08035C8A:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08035CD0\n\
_08035CA0:\n\
	movs r0, #0xa\n\
	strb r0, [r4, #0x12]\n\
_08035CA4:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _08035CD0\n\
_08035CAC:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	bl FUN_0801779c\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _08035CC8\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08035CD0\n\
_08035CC8:\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_08035CD0:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// ----------------------------------------------

// 0x08035cd8
static bool32 Update1_3(struct Zero* z) {
  if ((z->s).mode[2] >= 5) {
    if (gJoypad[0].pressed & (R_BUTTON | L_BUTTON)) {
      (z->s).mode[1] = 2;
      (z->s).mode[2] = 0;
      if (gJoypad[0].pressed & L_BUTTON) {
        (z->s).mode[3] = 0;
      } else {
        (z->s).mode[3] = 1;
      }
    }
    if (gJoypad[0].pressed & B_BUTTON) {
      (z->s).mode[1] = 3;
      (z->s).mode[2] = 2;
    }
  }
  return TRUE;
}

void* FUN_080b18d4(struct Coord* c1, struct Coord* c2, u8 kind);

// 0x08035d2c
static void Update2_3(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 1));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&z->s);
      if ((z->s).motion.state == MOTION_END) {
        (z->s).mode[2]++;
      }
      break;
    }
    case 2: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 2));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateMotionGraphic(&z->s);
      if ((z->s).motion.state == MOTION_END) {
        (z->s).mode[2]++;
      }
      break;
    }
    case 4: {
      struct Coord coords;
      SetMotion(&z->s, MOTION(DM179_COPY_X, 3));
      if ((z->mg).copyx.element == 0) {
        PlaySound(SE_HANU_TAILFIRE_SE);
      } else if ((z->mg).copyx.element == 1) {
        PlaySound(SE_COPYX_ELECSHOT);
      } else if ((z->mg).copyx.element == 2) {
        PlaySound(SE_ICE_40);
      } else {
        PlaySound(SE_HANU_TAILFIRE_SE);
      }
      *(&coords) = *(&(z->s).coord);
      coords.x += PIXEL(22);
      coords.y -= PIXEL(22);
      FUN_080b18d4(&coords, &(z->s).coord, (z->mg).copyx.element);
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      UpdateMotionGraphic(&z->s);
      if ((z->s).motion.state == MOTION_END) {
        (z->s).mode[2]++;
      }
      break;
    }
    case 6: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 4));
      (z->s).mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      UpdateMotionGraphic(&z->s);
      if ((z->s).motion.state == MOTION_END) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
    }
    default: {
      break;
    }
  }
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ALLY,
  LAYER(0xFFFFFFFF),
  hitzone : 0x01,
  hardness : METAL,
  remaining : 0,
  layer : 0xFFFFFFFF,
  range : {PIXEL(0), PIXEL(0), PIXEL(22), PIXEL(22)},
};
