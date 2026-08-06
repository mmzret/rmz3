#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"
#include "physics.h"
#include "vfx.h"
#include "story.h"
#include "score.h"
#include "zero.h"

s32 FUN_0800a40c(s32 x, s32 y);
void FUN_080b8f68(s32 x, s32 y, u8 n);
void createShrimporinIce(s32 x, s32 y, u8 n);
bool8 IsVoidSpace(s32 x, s32 y);
void FUN_080b8080(struct Enemy* p, struct Coord* c, const motion_t* m, s32 n, s32 a4);
void FUN_080b869c(struct Entity* e, struct Coord* c, struct Coord* dc, s32 y, motion_t* motions, u8 frame, u8 taskCol, u8 palID);
void shrimporinIceCrash(s32 x, s32 y, u8 frame);

struct ShrimporinObject {
  COLLISION_OBJECT_HDR;
  Entity* elfx;   // 0xB4, Element Effect
  u8 unk_b8[12];  // 0xB8
};
static_assert(sizeof(struct ShrimporinObject) == sizeof(struct Enemy));

static const EnemyFunc sUpdates1[8];
static const EnemyFunc sUpdates2[8];
static const struct Collision sCollisions[6];
static const Coords32 sElementCoord;
static const u8 sInitModes[4];
static const motion_t sMotions[4];

NAKED static void Shrimporin_Init(struct Enemy* p);
static void Shrimporin_Update(struct Enemy* p);
static void Shrimporin_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gShrimporinRoutine = {
    [ENTITY_INIT] =      (void*)Shrimporin_Init,
    [ENTITY_UPDATE] =    (void*)Shrimporin_Update,
    [ENTITY_DIE] =       (void*)Shrimporin_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, u16 r2, bool16 isDirRight);
void CreateShrimporin(s32 x, s32 y, u8 n, bool8 r3) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_SHRIMPORIN);
    (p->coord).x = x, (p->coord).y = y;
    p->work[2] = n;
    if (r3) {
      p->work[0] = 5;
    } else {
      p->work[0] = 2;
    }
  }
}

void nop_08069874(struct Body* body, Coords32* c1, Coords32* c2) {}

static bool8 tryKillShrimporin(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    if ((p->s).work[0] == 2) {
      (p->s).mode[1] = 3;
    } else if ((p->body).status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 2;
    } else {
      (p->s).mode[1] = 0;
    }
    Shrimporin_Die(p);
    return TRUE;
  }
  return FALSE;
}

NAKED static bool8 shrimporin_080698dc(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r1, [r4, #0xd]\n\
	cmp r1, #7\n\
	beq _0806998A\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #2\n\
	beq _0806998A\n\
	cmp r0, #5\n\
	beq _0806998A\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0806998A\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	beq _08069906\n\
	cmp r0, #1\n\
	beq _08069948\n\
	b _0806998A\n\
_08069906:\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	beq _0806998A\n\
	ldr r1, _08069940 @ =sUpdates1\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	ldr r1, _08069944 @ =sUpdates2\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_0806993C:\n\
	movs r0, #1\n\
	b _0806998C\n\
	.align 2, 0\n\
_08069940: .4byte sUpdates1\n\
_08069944: .4byte sUpdates2\n\
_08069948:\n\
	cmp r1, #2\n\
	bne _08069966\n\
	ldrb r0, [r4, #0x13]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08069960\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldrb r2, [r4, #0x11]\n\
	bl FUN_080b8f68\n\
_08069960:\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
_08069966:\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	beq _08069988\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	ldr r1, _08069984 @ =0x00020001\n\
	ands r0, r1\n\
	cmp r0, r1\n\
	bne _0806993C\n\
	movs r0, #0\n\
	strb r0, [r4, #0xf]\n\
	b _0806998C\n\
	.align 2, 0\n\
_08069984: .4byte 0x00020001\n\
_08069988:\n\
	strb r0, [r4, #0xf]\n\
_0806998A:\n\
	movs r0, #0\n\
_0806998C:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

void shrimporin_08069994(struct ShrimporinObject* p) {
  if (p->elfx == NULL && ((p->body).status & BODY_STATUS_WHITE)) {
    if (((p->body).status & BODY_STATUS_RECOILED)) {
      p->mode[1] = 7, p->mode[2] = 0;
    } else {
      p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoord);
      if (p->elfx != NULL) {
        p->mode[1] = 0, p->mode[2] = 0;
      }
    }
  }
}

static void FUN_080699e0(struct Enemy* p) {
  if (((p->body).status & (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) == (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) {
    (p->s).mode[1] = 7, (p->s).mode[2] = 0;
  }
}

// --------------------------------------------

NAKED static void Shrimporin_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r1, _08069A24 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #2\n\
	bls _08069A28\n\
	subs r0, #3\n\
	strb r0, [r6, #0x10]\n\
	strb r1, [r6, #0x11]\n\
	b _08069A2C\n\
	.align 2, 0\n\
_08069A24: .4byte gEnemyFnTable\n\
_08069A28:\n\
	movs r0, #0\n\
	strb r0, [r6, #0x11]\n\
_08069A2C:\n\
	ldr r1, _08069A84 @ =sInitModes\n\
	ldrb r0, [r6, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	movs r4, #0\n\
	movs r5, #0\n\
	strb r0, [r6, #0xd]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #2\n\
	beq _08069AB4\n\
	adds r1, r6, #0\n\
	adds r1, #0xb8\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r1]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_0800a05c\n\
	str r0, [r6, #0x58]\n\
	ldr r0, _08069A88 @ =gSystemSavedata\n\
	ldrb r1, [r0, #0x14]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08069A94\n\
	ldr r0, _08069A8C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08069A94\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08069A90 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _08069ACA\n\
	.align 2, 0\n\
_08069A84: .4byte sInitModes\n\
_08069A88: .4byte gSystemSavedata\n\
_08069A8C: .4byte gCurStory\n\
_08069A90: .4byte sCollisions\n\
_08069A94:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08069AB0 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
	b _08069ACA\n\
	.align 2, 0\n\
_08069AB0: .4byte sCollisions\n\
_08069AB4:\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08069B04 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
_08069ACA:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	adds r1, r6, #0\n\
	adds r1, #0xb4\n\
	movs r0, #0\n\
	str r0, [r1]\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r6, #0x11]\n\
	adds r1, r6, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldr r0, _08069B08 @ =nop_08069874\n\
	str r0, [r4, #0x24]\n\
	adds r0, r6, #0\n\
	bl Shrimporin_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08069B04: .4byte sCollisions\n\
_08069B08: .4byte nop_08069874\n\
 .syntax divided\n");
}

// --------------------------------------------

static void FUN_080699e0(struct Enemy* p);
static void nop_08069c20(struct Enemy* p);
static void shrimporin_08069c24(struct ShrimporinObject* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    (EnemyFunc)shrimporin_08069c24,
    (EnemyFunc)nop_08069c20,
    (EnemyFunc)nop_08069c20,
    (EnemyFunc)FUN_080699e0,
    (EnemyFunc)FUN_080699e0,
    (EnemyFunc)nop_08069c20,
    (EnemyFunc)FUN_080699e0,
    (EnemyFunc)nop_08069c20,
};
// clang-format on

NON_MATCH void shrimporin_08069c80(struct Enemy* p);
void shrimporin_08069d00(struct Enemy* p);
void shrimporinBurrowSnow(struct Enemy* p);
void popoutShrimporin(struct Enemy* p);
void shrimporinSpin(struct Enemy* p);
void shrimporinIce(struct Enemy* p);
void shrimporin_0806a230(struct Enemy* p);
void shrimporin_0806a544(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    shrimporin_08069c80,
    shrimporin_08069d00,
    shrimporinBurrowSnow,
    popoutShrimporin,
    shrimporinSpin,
    shrimporinIce,
    shrimporin_0806a230,
    shrimporin_0806a544,
};
// clang-format on

static void Shrimporin_Update(struct Enemy* p) {
  if ((p->s).work[0] == 2) {
    if (IS_METTAUR) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }
    if (tryKillShrimporin(p)) {
      return;
    }
  } else {
    if (tryKillShrimporin(p)) {
      return;
    }
    shrimporin_08069994((void*)p);
    if (shrimporin_080698dc(p)) {
      return;
    }
  }

  (sUpdates1[(p->s).mode[1]])((void*)p);
  (sUpdates2[(p->s).mode[1]])((void*)p);
}

// --------------------------------------------

void explodeShrimpolin(struct Enemy* p);
void slashShrimporin(struct Enemy* p);
void shrimporin_0806a544(struct Enemy* p);
void shrimporin_0806a4ec(struct Enemy* p);

static void Shrimporin_Die(struct Enemy* p) {
  static const EnemyFunc sDeads[4] = {
      (void*)explodeShrimpolin,
      (void*)slashShrimporin,
      (void*)shrimporin_0806a544,
      (void*)shrimporin_0806a4ec,
  };

  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void nop_08069c20(struct Enemy* p) { return; }

static void shrimporin_08069c24(struct ShrimporinObject* p) {
  struct Entity* elfx = p->elfx;
  if (elfx == NULL || IsDead(elfx)) {
    p->elfx = NULL;
    SetDDP(&p->body, &sCollisions[1]);
    if (!IsFrozen(p)) p->mode[1] = 6, p->mode[2] = 0;
  }

  if (((p->body).status & (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) == (BODY_STATUS_RECOILED | BODY_STATUS_WHITE)) {
    p->mode[1] = 7, p->mode[2] = 0;
  }
}

NON_MATCH void shrimporin_08069c80(struct Enemy* p) {
#if MODERN
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      SetDDP(&p->body, &sCollisions[2]);
      (p->s).mode[2]++;
      // fallthrough
    case 1: {
      s32 f = IsFrozen(&p->s);
      if (f == 0) {
        (p->s).d.y += 0x40;
        if ((p->s).d.y > 0x700) {
          (p->s).d.y = 0x700;
        }
        (p->s).coord.y += (p->s).d.y;
        {
          s32 r = PushoutToUp2((p->s).coord.x, (p->s).coord.y + PIXEL(8));
          if (r < 0) {
            (p->s).d.y = f;
            (p->s).coord.y += r;
          }
        }
      }
      (p->s).coord.x += FUN_0800a40c((p->s).coord.x, (p->s).coord.y + PIXEL(12));
      break;
    }
  }
#else
  INCCODE("asm/enemy/shrimporin_9c80.inc");
#endif
}

void shrimporin_08069d00(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register u8 fv asm("r0");
      register u8 t asm("r1");
      SetDDP(&p->body, sCollisions);
      t = (p->s).flags;
      fv = 0xFE;
      fv &= t;
      (p->s).flags = fv;
      asm volatile("" ::"r"(t));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 d = (pZero2->s).coord.x - (p->s).coord.x;
      u8 w = (p->s).work[0];
      if (w == 0) {
        if (d <= 0x77FF) {
          (p->s).mode[1] = 2;
          (p->s).mode[2] = w;
        }
      } else {
        if (d > 0x7800) {
          s32 z = 0;
          (p->s).mode[1] = 2;
          (p->s).mode[2] = z;
        }
      }
      break;
    }
  }
}

void shrimporinBurrowSnow(struct Enemy* p) {
  u8 m = (p->s).mode[2];
  switch (m) {
    case 0:
      (p->s).flags &= ~DISPLAY;
      SetDDP(&p->body, sCollisions);
      (p->s).d.x = m;
      (p->s).work[2] = m;
      (p->s).work[3] = m;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      register s32 hit asm("r2");
      register s32 g asm("r2");
      s32 zx, v, t, r, s5, cx;
      u16 at;
      t = (p->s).work[3];
      if ((t & 3) == 0) {
        FUN_080b8f68((p->s).coord.x, (p->s).coord.y, (p->s).work[1]);
      }
      (p->s).work[3]++;
      t = (p->s).work[2] + 1;
      (p->s).work[2] = t;
      if ((u8)t > 0x78) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = 0;
      }
      zx = (pZero2->s).coord.x;
      zx -= 0x4000;
      asm("" : "+l"(zx));
      if ((pZero2->s).flags & X_FLIP) {
        zx += 0x8000;
      }
      asm("" : "+l"(zx));
      zx += 0x2000;
      zx -= (((p->s).work[2] >> 4) & 1) << 14;
      (p->s).unk_coord.x = 0x500;
      v = (p->s).unk_coord.x;
      if (zx - (p->s).coord.x < 0) {
        v = -0x500;
      }
      (p->s).unk_coord.x = v;
      (p->s).d.x += ((v - (p->s).d.x) * 24) / 256;
      if ((p->s).d.x > 0x300) {
        (p->s).d.x = 0x300;
      } else if ((p->s).d.x < -0x300) {
        (p->s).d.x = -0x300;
      }
      (p->s).coord.x += (p->s).d.x;
      {
        s32 base = *(s32*)((u8*)p + 0xb8);
        s32 dd = (p->s).coord.x - base;
        if (dd > 0x16800) {
          (p->s).coord.x = base + 0x16800;
        } else if (dd < -0x16800) {
          (p->s).coord.x = base + -0x16800;
        }
      }
      r = 0;
      if ((p->s).d.x > 0) {
        cx = (p->s).coord.x;
        s5 = 0xC00;
        hit = PushoutToLeft2(cx + s5, (p->s).coord.y - 0x800);
        asm("" : "+r"(hit));
        if (hit >= 0) {
          goto nopush;
        }
      } else {
        cx = (p->s).coord.x;
        s5 = -0xC00;
        hit = PushoutToRight2(cx + s5, (p->s).coord.y - 0x800);
        asm("" : "+r"(hit));
        if (hit <= 0) {
          goto nopush;
        }
      }
      r = 1;
      (p->s).coord.x += hit;
    nopush:
      g = FUN_0800a05c((p->s).coord.x + s5, (p->s).coord.y);
      asm("" : "+r"(g));
      if ((u32)(g - (p->s).coord.y + 0xF00) > 0x1DFF) {
        r = 1;
        (p->s).coord.x -= (p->s).d.x;
      }
      asm volatile("" ::"r"(g));
      t = (p->s).work[2];
      (p->s).work[2] = r + t;
      SET_XFLIP(p, (u32)(p->s).d.x >> 31);
      at = FUN_080098a4((p->s).coord.x, (p->s).coord.y + 0x800);
      if (at == 0) {
        SetMotion(&p->s, MOTION(0x0D, 0x02));
        UpdateEntityAnim(&p->s);
        (p->s).mode[1] = 6;
        (p->s).mode[2] = at;
      } else {
        (p->s).coord.y = FUN_0800a05c((p->s).coord.x, (p->s).coord.y);
      }
      break;
    }
  }
}

void popoutShrimporin(struct Enemy* p) {
  s32 md = (p->s).mode[2];
  switch (md) {
    case 0:
      PlaySound(0x55);
      (p->s).flags |= DISPLAY;
      GotoMotion(&p->s, MOTION(0x0D, 0x01), 1, 1);
      UpdateEntityAnim(&p->s);
      (p->s).work[2] = 0x10;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      s32 t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      if ((t << 24) == 0) {
        (p->s).mode[2]++;
      }
      break;
    }
    case 2: {
      s32 on;
      SetDDP(&p->body, &sCollisions[1]);
      createShrimporinIce((p->s).coord.x, (p->s).coord.y, (p->s).work[1]);
      SetMotion(&p->s, MOTION(0x0D, 0x02));
      on = 0;
      if ((pZero2->s).coord.x - (p->s).coord.x > 0) {
        on = 1;
      }
      SET_XFLIP(p, on);
      {
        register s32 w18 asm("r1");
        w18 = 0x18;
        asm("" : "+r"(w18));
        (p->s).d.y = -0x5AA;
        (p->s).coord.y += -0x800;
        (p->s).work[2] = w18;
      }
      (p->s).mode[2]++;
      /* fallthrough */
    }
    case 3: {
      u8 t;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      t = --(p->s).work[2];
      if (t == 0) {
        (p->s).mode[1] = 4;
        (p->s).mode[2] = t;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void shrimporinSpin(struct Enemy* p) {
  u8 md = (p->s).mode[2];
  switch (md) {
    case 0:
      SetMotion(&p->s, MOTION(0x0D, 0x03));
      (p->s).work[2] = md;
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        (p->s).mode[1] = 6;
        (p->s).mode[2] = 0;
      }
      if ((s8)(p->s).motion.cmdIdx == 5 && (p->s).work[2] == 0) {
        s32 one = 1;
        s32 x2;
        (p->s).work[2] = one;
        x2 = (p->s).coord.x - 0x700;
        if ((p->s).flags & 0x10) {
          x2 = (p->s).coord.x + 0x700;
        }
        CreateShrimporin(x2, (p->s).coord.y + 0xF00, ((p->s).flags >> 4) & one, (p->s).work[1]);
      }
      break;
  }
}

void shrimporinIce(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      s32 dx;
      s32 dy;
      s32 d;
      SetDDP(&p->body, &sCollisions[3]);
      SetMotion(&p->s, MOTION(0x0D, 0x06));
      (p->s).d.x = (pZero2->s).coord.x - (p->s).coord.x;
      {
        u8 w2 = (p->s).work[2];
        if ((p->s).d.x > 0) {
          if (w2 != 1) {
            goto zero;
          }
          goto aim;
        }
        if (w2 == 0) {
          goto aim;
        }
      }
    zero:
      (p->s).d.x = 0;
      (p->s).d.y = 0x280;
      goto done;
    aim:
      {
        struct Zero* z = pZero2;
        s32 yy = (p->s).coord.y + 0x1800;
        dy = (z->s).coord.y - yy;
      }
      (p->s).d.y = dy;
      dx = (p->s).d.x;
      d = (dx >> 8) * (dx >> 8);
      d += (dy >> 8) * (dy >> 8);
      d = (u16)Sqrt(d) << 8;
      if (d != 0) {
        s32 ux = ((p->s).d.x << 8) / d;
        s32 uy;
        (p->s).d.x = ux;
        uy = ((p->s).d.y << 8) / d;
        (p->s).d.y = uy;
        (p->s).d.x = (ux * 5 << 7) / 256;
        (p->s).d.y = (uy * 5 << 7) / 256;
      } else {
        (p->s).d.x = 0x280;
        (p->s).d.y = d;
      }
    done:
      (p->s).work[2] = 0xFF;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 x = (p->s).coord.x + (p->s).d.x;
      s32 y;
      (p->s).coord.x = x;
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      (p->s).work[2]--;
      if ((u16)GetGroundMetatileAttr(x, y) != 0 || ((p->body).status & 4) != 0 ||
          (p->s).work[2] == 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = 3;
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

void shrimporin_0806a230(struct Enemy* p) {
  s32 r;
  u8 m2 = (p->s).mode[2];
  switch (m2) {
    case 0:
      (p->s).flags |= DISPLAY;
      (p->s).d.x = m2;
      (p->s).d.y = m2;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 dx;
      (p->s).coord.x += (p->s).d.x;
      dx = (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      if (dx != 0) {
        if (dx > 0) {
          r = PushoutToLeft2((p->s).coord.x + 0xC00, (p->s).coord.y - 0x800);
          if (r >= 0) {
            goto up;
          }
        } else {
          r = PushoutToRight2((p->s).coord.x - 0xC00, (p->s).coord.y - 0x800);
          if (r <= 0) {
            goto up;
          }
        }
        (p->s).coord.x += r;
      }
    up:
      r = PushoutToUp2((p->s).coord.x, (p->s).coord.y + 0x600);
      if ((u8)IsVoidSpace((p->s).coord.x, (p->s).coord.y) != 0) {
        u32 z;
        u8 t = (p->s).flags;
        u8 fv = 0xFE;
        fv &= t;
        asm volatile("" ::"r"(t));
        z = 0;
        fv &= 0xFD;
        (p->s).flags = fv;
        (p->body).status = z;
        (p->body).prevStatus = z;
        (p->body).invincibleTime = z;
        (p->s).flags &= ~COLLIDABLE;
        SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
        break;
      }
      if (r >= 0) {
        break;
      }
      if ((p->s).d.x != 0) {
        s32* q = (s32*)((u8*)p + 0xb8);
        s32 x = (p->s).coord.x;
        s32 b = *q;
        if (x > b) {
          if (x <= b + 0x16800) {
            goto place;
          }
          *q = x + -0x16800;
          goto place2;
        }
        if (x >= b - 0x16800) {
          goto place;
        }
        *q = x + 0x16800;
      place2:;
      }
    place:
      (p->s).coord.y += r;
      createShrimporinIce((p->s).coord.x, (p->s).coord.y, (p->s).work[1]);
      {
        u8 z2 = 0;
        (p->s).mode[1] = 2;
        (p->s).mode[2] = z2;
      }
      break;
    }
  }
}

void explodeShrimpolin(struct Enemy* p) {
  struct Coord c;
  struct Coord* co;
  {
    register u8 f asm("r0");
    register u8 t asm("r1");
    register u8 k2 asm("r1");
    u8* q = (u8*)p + 0x8c;
    s32 z;
    asm("" : "+r"(q));
    z = 0;
    *(s32*)q = z;
    asm("" : "+r"(q));
    q += 4;
    asm("" : "+r"(q));
    *(s32*)q = z;
    asm("" : "+r"(q));
    q += 4;
    asm("" : "+r"(q));
    *q = z;
    t = (p->s).flags;
    f = 0xFB;
    f &= t;
    asm volatile("" ::"r"(t));
    k2 = 0xFE;
    f &= k2;
    (p->s).flags = f;
  }
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y - 0x1000;
  CreateSmoke(1, &c);
  PlaySound(0x2a);
  FUN_080b8080(p, &c, sMotions, 3, (p->s).work[1]);
  co = &(p->s).coord;
  TryDropItem(2, co);
  if (gScore.enemyCount <= 0x270E) {
    gScore.enemyCount++;
  }
  TryDropZakoDisk((struct Entity*)p, co);
  SET_ENEMY_ROUTINE(p, 4);
}

void slashShrimporin(struct Enemy* p) {
  register s32 z asm("r6");
  z = (p->s).mode[2];
  switch (z) {
    case 0: {
      register s32 dir asm("r4");
      struct Coord c;
      dir = 0;
      if ((pZero2->s).coord.x - (p->s).coord.x > 0) {
        dir = 1;
      }
      SetMotion(&p->s, MOTION(0x0D, 0x04));
      {
        u8* a = (u8*)p + 0x8c;
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      (p->s).flags &= ~COLLIDABLE;
      c.x = (p->s).coord.x;
      c.y = (p->s).coord.y;
      ((struct Entity* (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x200, dir);
      {
        register s32 k asm("r1");
        k = 0x60;
        c.x = k - ((dir * 3) << 6);
        c.y = k;
      }
      FUN_080b869c(&p->s, &(p->s).coord, &c, 0x40, (motion_t*)&sMotions[3], 0x18, 1, (p->s).work[1]);
      (p->s).work[2] = 0x18;
      (p->s).d.y = z;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t;
      (p->s).d.y += 0x30;
      if ((p->s).d.y > 0x700) {
        (p->s).d.y = 0x700;
      }
      (p->s).coord.y += (p->s).d.y;
      UpdateEntityAnim(&p->s);
      t = (p->s).work[2] - 1;
      (p->s).work[2] = t;
      t <<= 24;
      if (t != 0) {
        if ((u16)GetGroundMetatileAttr((p->s).coord.x, (p->s).coord.y) == 0) {
          break;
        }
      }
      explodeShrimpolin(p);
      break;
    }
  }
}

void shrimporin_0806a4ec(struct Enemy* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  (p->s).flags &= ~COLLIDABLE;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  if ((p->s).work[1] == 0) {
    PlaySound(0x3F);
  } else {
    PlaySound(0x122);
  }
  shrimporinIceCrash((p->s).coord.x, (p->s).coord.y, (p->s).work[1]);
}

void shrimporin_0806a544(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 d asm("r6");
      GotoMotion(&p->s, 0x0D03, 6, 1);
      UpdateEntityAnim(&p->s);
      {
        register struct Zero* z asm("r2");
        register s32 dx asm("r1");
        register s32 dy asm("r0");
        register s32 t asm("r4");
        z = pZero2;
        {
          register s32 zx asm("r0");
          dx = (p->s).coord.x;
          zx = (z->s).coord.x;
          dx -= zx;
        }
        (p->s).d.x = dx;
        dy = (p->s).coord.y;
        {
          register s32 k asm("r3");
          k = 0xc0 << 5;
          dy += k;
        }
        dy -= (z->s).coord.y;
        (p->s).d.y = dy;
        dx >>= 8;
        d = dx * dx;
        dy >>= 8;
        t = dy * dy;
        {
          register s32 t2 asm("r0");
          t2 = t;
          d += t2;
        }
      }
      d = (u16)Sqrt(d) << 8;
      if (d != 0) {
        register s32 q asm("r4");
        q = ((p->s).d.x << 8) / d;
        (p->s).d.x = q;
        {
          register s32 q2 asm("r0");
          q2 = ((p->s).d.y << 8) / d;
          (p->s).d.x = q << 2;
          (p->s).d.y = q2 << 2;
        }
      } else {
        (p->s).d.x = 0x80 << 3;
        (p->s).d.y = d;
      }
      SetDDP(&p->body, &sCollisions[5]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx2 asm("r2");
      register s32 ny asm("r1");
      {
        register s32 nx asm("r0");
        nx = (p->s).coord.x;
        dx2 = (p->s).d.x;
        nx += dx2;
        (p->s).coord.x = nx;
      }
      {
        register s32 dy2 asm("r0");
        register s32 lim asm("r1");
        dy2 = (p->s).d.y + 0x40;
        (p->s).d.y = dy2;
        lim = 0xe0 << 3;
        if (dy2 > lim) {
          (p->s).d.y = lim;
        }
      }
      {
        register s32 dv asm("r0");
        ny = (p->s).coord.y;
        dv = (p->s).d.y;
        ny += dv;
        (p->s).coord.y = ny;
      }
      if (dx2 == 0) {
        goto chk;
      }
      if (dx2 <= 0) {
        goto neg;
      }
      {
        register s32 r asm("r2");
        register s32 xx2 asm("r0");
        register s32 k6 asm("r2");
        xx2 = (p->s).coord.x;
        k6 = 0xc0 << 4;
        xx2 += k6;
        {
          register s32 k7 asm("r3");
          k7 = 0xFFFFF800;
          ny += k7;
        }
        r = PushoutToLeft2(xx2, ny);
        if (r >= 0) {
          goto chk;
        }
        {
          register s32 nx3 asm("r0");
          nx3 = (p->s).coord.x;
          nx3 += r;
          asm volatile("str %0, [%1, #0x54]" :: "l"(nx3), "l"(p) : "memory");
        }
        goto boom;
      }
    neg:
      {
        register s32 r2 asm("r2");
        register s32 xx asm("r0");
        register s32 k4 asm("r4");
        xx = (p->s).coord.x;
        k4 = 0xFFFFF400;
        xx += k4;
        {
          register s32 k5 asm("r2");
          k5 = 0xFFFFF800;
          ny += k5;
        }
        r2 = PushoutToRight2(xx, ny);
        if (r2 <= 0) {
          goto chk;
        }
        (p->s).coord.x = (p->s).coord.x + r2;
        goto boom;
      }
    chk:
      if ((*(s32*)((u8*)p + 0x8c) & 4) == 0) {
        goto down;
      }
    boom:
      explodeShrimpolin(p);
      break;
    down: {
      register s32 r3 asm("r2");
      r3 = PushoutToUp2((p->s).coord.x, (p->s).coord.y);
      if (r3 >= 0) {
        break;
      }
      if ((p->s).d.x != 0) {
        register s32* q3 asm("r3");
        register s32 cx asm("r1");
        register s32 base asm("r0");
        register s32 k8 asm("r4");
        q3 = (s32*)((u8*)p + 0xb8);
        cx = (p->s).coord.x;
        base = *q3;
        if (cx > base) {
          k8 = 0xb4 << 9;
          base += k8;
          if (cx <= base) {
            goto skip;
          }
          k8 = 0xFFFE9800;
        } else {
          k8 = 0xFFFE9800;
          base += k8;
          if (cx >= base) {
            goto skip;
          }
          k8 = 0xb4 << 9;
        }
        {
          register s32 nv asm("r0");
          nv = cx + k8;
          *q3 = nv;
        }
      }
    skip:
      (p->s).coord.y = (p->s).coord.y + r3;
      createShrimporinIce((p->s).coord.x, (p->s).coord.y, (p->s).work[1]);
      explodeShrimpolin(p);
      break;
    }
    }
  }
}

// --------------------------------------------

static const struct Collision sCollisions[6] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x1800},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1800, 0x1800},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x04,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 2,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1800, 0x1800},
    },
};

static const Coords32 sElementCoord = {0, 0};

static const u8 sInitModes[4] = {1, 1, 5, 0};

static const motion_t sMotions[4] = {
    MOTION(SM013_SHRIMPOLIN, 0x07),
    MOTION(SM013_SHRIMPOLIN, 0x08),
    MOTION(SM013_SHRIMPOLIN, 0x08),
    MOTION(SM013_SHRIMPOLIN, 0x05),
};
