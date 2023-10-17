#include "blink.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "vfx.h"
#include "zero.h"

#define STATE ((struct MinigameState*)(z->s).unk_28)

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
  (z->mg).copyx.unk_27d = 3;
  CopyXMini_Update(z);
}

// --------------------------------------------

static bool8 nop_08035a40(struct Zero* z);
static bool8 FUN_08035a9c(struct Zero* z);
static bool8 FUN_08035b1c(struct Zero* z);
static bool8 FUN_08035cd8(struct Zero* z);

static void copyXMini_08035a44(struct Zero* z);
static void FUN_08035af0(struct Zero* z);
static void FUN_08035b44(struct Zero* z);
static void FUN_08035d2c(struct Zero* z);

static void CopyXMini_Update(struct Zero* z) {
  static const ZeroFunc sUpdates1[4] = {
      (ZeroFunc)nop_08035a40,
      (ZeroFunc)FUN_08035a9c,
      (ZeroFunc)FUN_08035b1c,
      (ZeroFunc)FUN_08035cd8,
  };
  static const ZeroFunc sUpdates2[4] = {
      copyXMini_08035a44,
      FUN_08035af0,
      FUN_08035b44,
      FUN_08035d2c,
  };

  if (STATE->unk_04 != 2) {
    (sUpdates1[(z->s).mode[1]])(z);
    (sUpdates2[(z->s).mode[1]])(z);
  }

  if (z->mg.copyx.unk_27d != STATE->unk_0c) {
    z->mg.copyx.unk_27d = STATE->unk_0c;
    if (z->mg.copyx.unk_27d == 2) {
      PlaySound(SE_NOT_ALLOWED);
    } else if (z->mg.copyx.unk_27d == 1) {
      PlaySound(SE_COPYX_RECOVER_VOICE);
    } else if (z->mg.copyx.unk_27d == 0) {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 19));
      UpdateMotionGraphic(&z->s);
      PlaySound(SE_COPYX_STUN);
    }
  } else if (z->mg.copyx.unk_27d == 0) {
    UpdateMotionGraphic(&z->s);
  }
}

// --------------------------------------------

static void CopyXMini_Die(struct Zero* z) {
  // nop
  return;
}

// --------------------------------------------

static bool8 nop_08035a40(struct Zero* z) {
  // nop
  return TRUE;
}

static void copyXMini_08035a44(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0: {
      SetMotion(&z->s, MOTION(DM179_COPY_X, 0));
      z->mg.copyx.unk_27c = 0;
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

static bool8 FUN_08035a9c(struct Zero* z) {
  if (STATE->unk_04 == 1) {
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

static void FUN_08035af0(struct Zero* z) {
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

static bool8 FUN_08035b1c(struct Zero* z) {
  if (((z->s).mode[2] >= 2) && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

NAKED static void FUN_08035b44(struct Zero* z) {
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

static bool8 FUN_08035cd8(struct Zero* z) {
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

NAKED static void FUN_08035d2c(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	sub sp, #8\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #7\n\
	bls _08035D3A\n\
	b _08035E3A\n\
_08035D3A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08035D44 @ =_08035D48\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08035D44: .4byte _08035D48\n\
_08035D48: @ jump table\n\
	.4byte _08035D68 @ case 0\n\
	.4byte _08035DF8 @ case 1\n\
	.4byte _08035D78 @ case 2\n\
	.4byte _08035DF8 @ case 3\n\
	.4byte _08035D88 @ case 4\n\
	.4byte _08035DF8 @ case 5\n\
	.4byte _08035E14 @ case 6\n\
	.4byte _08035E22 @ case 7\n\
_08035D68:\n\
	ldr r1, _08035D74 @ =0x0000B301\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _08035DF2\n\
	.align 2, 0\n\
_08035D74: .4byte 0x0000B301\n\
_08035D78:\n\
	ldr r1, _08035D84 @ =0x0000B302\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _08035DF2\n\
	.align 2, 0\n\
_08035D84: .4byte 0x0000B302\n\
_08035D88:\n\
	ldr r1, _08035DA4 @ =0x0000B303\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08035DA8\n\
	movs r0, #0x51\n\
	bl PlaySound\n\
	b _08035DC6\n\
	.align 2, 0\n\
_08035DA4: .4byte 0x0000B303\n\
_08035DA8:\n\
	cmp r0, #1\n\
	bne _08035DB4\n\
	movs r0, #0x49\n\
	bl PlaySound\n\
	b _08035DC6\n\
_08035DB4:\n\
	cmp r0, #2\n\
	bne _08035DC0\n\
	movs r0, #0x40\n\
	bl PlaySound\n\
	b _08035DC6\n\
_08035DC0:\n\
	movs r0, #0x51\n\
	bl PlaySound\n\
_08035DC6:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp]\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _08035E10 @ =0xFFFFEA00\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r2, #0x9f\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldrb r2, [r0]\n\
	mov r0, sp\n\
	bl FUN_080b18d4\n\
_08035DF2:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08035DF8:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08035E3A\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _08035E3A\n\
	.align 2, 0\n\
_08035E10: .4byte 0xFFFFEA00\n\
_08035E14:\n\
	ldr r1, _08035E44 @ =0x0000B304\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08035E22:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08035E3A\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_08035E3A:\n\
	add sp, #8\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08035E44: .4byte 0x0000B304\n\
 .syntax divided\n");
}

// --------------------------------------------

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ALLY,
  damage : 0,
  atkType : 0xFF,
  element : 0xFF,
  nature : 0xFF,
  comboLv : 0xFF,
  hitzone : 1,
  hardness : METAL,
  remaining : 0,
  layer : 0xFFFFFFFF,
  range : {0x0000, 0x0000, 0x1600, 0x1600},
};

#undef STATE
