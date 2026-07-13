#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"
#include "physics.h"
#include "vfx.h"
#include "zero.h"

static const struct Collision sCollision;

static void CopyXMini_Init(struct Zero* p);
static void CopyXMini_Update(struct Zero* p);
static void CopyXMini_Die(void* _ UNUSED);

// clang-format off
const ZeroRoutine gCopyXMiniRoutine = {
  [ENTITY_INIT] =       (void*)CopyXMini_Init,
  [ENTITY_UPDATE] =     (void*)CopyXMini_Update,
  [ENTITY_DIE]  =       (void*)CopyXMini_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreatePlayerCopyX(struct MinigameState* q, Coords32* c, u8 n) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_COPY_X);
    p->coord = *c;
    p->work[0] = n;
    p->unk_28 = (void*)q;
  }
  return p;
}

static void CopyXMini_Init(struct Zero* p) {
  Coords32 c;

  EnableSpriteAnimation_Normal(p);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;

  (p->s).spr.xflip = TRUE;
  (p->s).spr.oam.xflip = TRUE;
  (p->s).flags |= X_FLIP;
  INIT_BODY(p, &sCollision, 32, NULL);
  (p->s).coord.y = FUN_0800a05c((p->s).coord.x, (p->s).coord.y);
  SET_PLAYER_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0, (p->s).mode[2] = 0, (p->s).mode[3] = 0;

  c = (p->s).coord;
  (p->mg).copyx.unk_280[1] = (struct Entity*)CreateCopyXIcon(p, &c, 0);
  (p->mg).copyx.unk_280[0] = (struct Entity*)CreateCopyXIcon(p, &c, 1);
  (p->mg).copyx.unk_280[2] = (struct Entity*)CreateCopyXIcon(p, &c, 2);
  (p->mg).copyx.life = 3;
  CopyXMini_Update(p);
}

static bool32 Update1_0(void* _);
static bool32 Update1_1(struct Zero* p);
static bool32 Update1_2(struct Entity* p);
static bool32 Update1_3(struct Entity* p);

static void Update2_0(struct Zero* p);
static void Update2_1(struct Zero* p);
static void Update2_2(struct Zero* p);
static void Update2_3(struct Zero* p);

#define STATE ((struct MinigameState*)(p->s).unk_28)

// 0x080359a8
static void CopyXMini_Update(struct Zero* p) {
  static const ZeroFunc sUpdates1[4] = {
      (void*)Update1_0,
      (void*)Update1_1,
      (void*)Update1_2,
      (void*)Update1_3,
  };
  static const ZeroFunc sUpdates2[4] = {
      (void*)Update2_0,
      (void*)Update2_1,
      (void*)Update2_2,
      (void*)Update2_3,
  };

  if (STATE->unk_04 != 2) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }

  if ((p->mg).copyx.life != STATE->unk_0c) {
    (p->mg).copyx.life = STATE->unk_0c;
    if ((p->mg).copyx.life == 2) {
      PlaySound(SE_NOT_ALLOWED);
    } else if ((p->mg).copyx.life == 1) {
      PlaySound(SE_COPYX_RECOVER_VOICE);  // ﾓｳﾕﾙｻﾝ!
    } else if ((p->mg).copyx.life == 0) {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 19));
      UpdateSpriteAnimation(p);
      PlaySound(SE_COPYX_STUN);
    }
  } else if ((p->mg).copyx.life == 0) {
    UpdateSpriteAnimation(p);
  }
}

#undef STATE

static void CopyXMini_Die(void* _) {}

// --------------------------------------------

// 0x08035a40
static bool32 Update1_0(void* _) { return TRUE; }

// 0x08035a44
static void Update2_0(struct Zero* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 0));
      (p->mg).copyx.element = 0;  // flame
      StartPaletteAnimation(93, 640);
      (p->s).work[2] = 60;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->s).work[2] == 0 || (--(p->s).work[2] == 0)) {
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

// ----------------------------------------------

// 0x08035a9c
static bool32 Update1_1(struct Zero* p) {
  struct MinigameState* s = (struct MinigameState*)(p->s).unk_28;
  if (s->unk_04 == 1) {
    if (gJoypad[0].pressed & (R_BUTTON | L_BUTTON)) {
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      if (gJoypad[0].pressed & L_BUTTON) {
        (p->s).mode[3] = 0;
      } else {
        (p->s).mode[3] = 1;
      }
    }
    if (gJoypad[0].pressed & B_BUTTON) {
      (p->s).mode[1] = 3, (p->s).mode[2] = 0;
    }
  }
  return TRUE;
}

// 0x08035af0
static void Update2_1(struct Zero* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// ----------------------------------------------

// 0x08035b1c
static bool32 Update1_2(struct Entity* p) {
  if ((p->mode[2] >= 2) && (gJoypad[0].pressed & B_BUTTON)) {
    p->mode[1] = 3, p->mode[2] = 0;
  }
  return TRUE;
}

// 0x08035b44
NAKED static void Update2_2(struct Zero* p) {
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
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5e\n\
	bl StartPaletteAnimation\n\
	b _08035BD8\n\
	.align 2, 0\n\
_08035BA4: .4byte 0x0000B314\n\
_08035BA8:\n\
	cmp r0, #2\n\
	bne _08035BC0\n\
	strb r5, [r1]\n\
	movs r0, #0x5f\n\
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5d\n\
	bl StartPaletteAnimation\n\
	b _08035BD8\n\
_08035BC0:\n\
	cmp r0, #1\n\
	bne _08035BD8\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #0x5e\n\
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5f\n\
	bl StartPaletteAnimation\n\
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
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5f\n\
	bl StartPaletteAnimation\n\
	b _08035C38\n\
_08035C08:\n\
	cmp r0, #2\n\
	bne _08035C22\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x5f\n\
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5e\n\
	bl StartPaletteAnimation\n\
	b _08035C38\n\
_08035C22:\n\
	cmp r0, #1\n\
	bne _08035C38\n\
	strb r5, [r1]\n\
	movs r0, #0x5e\n\
	bl RemovePaletteAnimation\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #2\n\
	movs r0, #0x5d\n\
	bl StartPaletteAnimation\n\
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
	bl UpdateEntityAnim\n\
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
	bl UpdateEntityAnim\n\
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
	bl UpdateEntityAnim\n\
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
static bool32 Update1_3(struct Entity* p) {
  if (p->mode[2] >= 5) {
    if (gJoypad[0].pressed & (R_BUTTON | L_BUTTON)) {
      p->mode[1] = 2;
      p->mode[2] = 0;
      if (gJoypad[0].pressed & L_BUTTON) {
        p->mode[3] = 0;
      } else {
        p->mode[3] = 1;
      }
    }
    if (gJoypad[0].pressed & B_BUTTON) {
      p->mode[1] = 3, p->mode[2] = 2;
    }
  }
  return TRUE;
}

struct Entity* FUN_080b18d4(Coords32* c1, Coords32* c2, u8 element);

// 0x08035d2c
static void Update2_3(struct Zero* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) (p->s).mode[2]++;
      break;
    }
    case 2: {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 2));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) (p->s).mode[2]++;
      break;
    }
    case 4: {
      Coords32 coords;
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 3));
      if ((p->mg).copyx.element == 0) {
        PlaySound(SE_HANU_TAILFIRE_SE);
      } else if ((p->mg).copyx.element == 1) {
        PlaySound(SE_COPYX_ELECSHOT);
      } else if ((p->mg).copyx.element == 2) {
        PlaySound(SE_ICE_40);
      } else {
        PlaySound(SE_HANU_TAILFIRE_SE);
      }
      *(&coords) = *(&(p->s).coord);
      coords.x += PIXEL(22);
      coords.y -= PIXEL(22);
      FUN_080b18d4(&coords, &(p->s).coord, (p->mg).copyx.element);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) (p->s).mode[2]++;
      break;
    }
    case 6: {
      SetSpriteAnimation(p, MOTION(DM179_COPY_X, 4));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
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
