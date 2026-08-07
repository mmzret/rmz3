#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"
#include "zero.h"

bool8 FUN_08075a84(struct Enemy* p);
struct Entity* FUN_080b9228(struct Coord* c, s32 a2);

// Hammer in Repair Factory

struct Entity* CreateBallChain(Coords32* c, struct Entity* e, u8 n);

static const struct Collision sCollisions[5];

NAKED static void Enemy21_Init(struct Enemy* p);
static void Enemy21_Update(struct Enemy* p);
static void Enemy21_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHammerRoutine = {
    [ENTITY_INIT] =      (void*)Enemy21_Init,
    [ENTITY_UPDATE] =    (void*)Enemy21_Update,
    [ENTITY_DIE] =       (void*)Enemy21_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


bool8 FUN_0800daec(s32 x, s32 y);
struct Entity* unused_080752cc(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HAMMER);
    p->coord = *c;
    p->work[0] = n, p->work[1] = 0;
  }
  return p;
}

static struct Enemy* FUN_0807532c(struct Entity* e, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HAMMER);
    (p->s).unk_28 = e;
    (p->s).work[0] = n, (p->s).work[1] = 1;
  }
  return p;
}

// --------------------------------------------

NAKED static void Enemy21_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #1\n\
	bne _08075474\n\
	adds r0, r5, #0\n\
	bl InitScalerotMotion1\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08075460 @ =0x0836705C\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	ldr r0, _08075464 @ =FUN_08075a5c\n\
	str r0, [r4, #0x24]\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #1\n\
	bne _08075474\n\
	ldr r0, [r5, #0x28]\n\
	ldr r1, [r0, #0x58]\n\
	ldr r0, [r0, #0x54]\n\
	str r0, [r5, #0x54]\n\
	str r1, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb8\n\
	strb r6, [r0]\n\
	str r6, [r5, #0x60]\n\
	adds r0, #8\n\
	movs r4, #0\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #5\n\
	str r0, [r5, #0x5c]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb5\n\
	strb r4, [r0]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, _08075468 @ =0xFFFFF800\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_0800a134\n\
	adds r1, r0, #0\n\
	movs r0, #0x98\n\
	lsls r0, r0, #7\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	bl FUN_0800a134\n\
	str r0, [r5, #0x68]\n\
	adds r2, r5, #0\n\
	adds r2, #0xbc\n\
	ldr r1, [r5, #0x58]\n\
	subs r1, r1, r0\n\
	str r1, [r2]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _0807546C @ =0xFFFFF000\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	mov r0, sp\n\
	adds r1, r5, #0\n\
	movs r2, #0\n\
	bl CreateBallChain\n\
	ldrb r2, [r5, #0x11]\n\
	cmp r2, #1\n\
	bne _08075474\n\
	ldr r1, _08075470 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r2, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r2, [r5, #0xd]\n\
	strb r4, [r5, #0xe]\n\
	strb r4, [r5, #0xf]\n\
	b _08075498\n\
	.align 2, 0\n\
_08075460: .4byte sCollisions+24\n\
_08075464: .4byte FUN_08075a5c\n\
_08075468: .4byte 0xFFFFF800\n\
_0807546C: .4byte 0xFFFFF000\n\
_08075470: .4byte gEnemyFnTable\n\
_08075474:\n\
	ldrb r1, [r5, #0x10]\n\
	adds r0, r5, #0\n\
	bl FUN_0807532c\n\
	ldr r1, _080754A8 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r1, #0\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	strb r1, [r5, #0xe]\n\
	strb r1, [r5, #0xf]\n\
_08075498:\n\
	adds r0, r5, #0\n\
	bl Enemy21_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080754A8: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool8 FUN_080755e8(struct Enemy* p);
static bool8 FUN_08075628(struct Enemy* p);
bool8 FUN_080756e8(struct Enemy* p);
static bool8 FUN_080755f0(struct Enemy* p);

static void FUN_080755ec(struct Enemy* p);
void FUN_0807562c(struct Enemy* p);
void FUN_080756ec(struct Enemy* p);
static void FUN_080755f4(struct Enemy* p);
bool8 FUN_08075a30(struct Enemy* p);

static void Enemy21_Update(struct Enemy* p) {
  static const EnemyFunc sUpdates1[4] = {
      (EnemyFunc)FUN_080755e8,
      (EnemyFunc)FUN_08075628,
      (EnemyFunc)FUN_080756e8,
      (EnemyFunc)FUN_080755f0,
  };
  static const EnemyFunc sUpdates2[4] = {
      FUN_080755ec,
      FUN_0807562c,
      FUN_080756ec,
      FUN_080755f4,
  };

  if ((p->s).work[1] == 1) {
    if (((p->s).unk_28)->mode[0] == ENTITY_EXIT) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      return;
    }
    if ((p->body).status & BODY_STATUS_DEAD) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      Enemy21_Die(p);
      return;
    }
    FUN_08075a30(p);
  }
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Enemy21_Die(struct Enemy* p) {
  if ((p->s).work[1] == 1) {
    if (IS_METTAUR) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }

    switch ((p->s).mode[2]) {
      case 0: {
        (p->s).mode[2] = 1;
        EXIT_BODY(p);
        FALLTHROUGH;
      }
      case 1: {
        (p->s).mode[2]++;
        return;
      }

      case 2: {
        break;
      }

      default: {
        return;
      }
    }
  }

  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static bool8 FUN_080755e8(struct Enemy* p) { return TRUE; }

static void FUN_080755ec(struct Enemy* p) {
  // nop
  return;
}

static bool8 FUN_080755f0(struct Enemy* p) { return TRUE; }

static void FUN_080755f4(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).flags &= ~DISPLAY;
    EXIT_BODY(p);
    (p->s).mode[2]++;
  }
}

static bool8 FUN_08075628(struct Enemy* p) { return TRUE; }

void FUN_0807562c(struct Enemy* p0) {
  register struct Enemy* p asm("r4");
  p = p0;
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, 0x2900);
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 dx;
      u16* ang;
      s32 a;
      const s16* st;
      s32 sv;
      s32 t;
      s32 dxs;
      register s32 s1 asm("r5");
      register s32 c1 asm("r6");
      s32* r;
      dx = (p->s).d.x;
      dx += ((0x1A00 - dx) << 2) >> 8;
      (p->s).d.x = dx;
      ang = (u16*)((u8*)p + 0xc0);
      a = (s8)p->buffer[0] + *ang;
      *ang = a;
      st = gSineTable;
      sv = st[(u8)a];
      *(u16*)((u8*)p + 0xc2) = sv;
      dxs = (p->s).d.x >> 8;
      t = dxs;
      t = sv * t;
      t >>= 8;
      (p->s).d.y = t;
      s1 = st[(u8)t];
      c1 = st[(u8)(t + 0x40)];
      r = (s32*)((u8*)p + 0xbc);
      (p->s).coord.x = ((s1 * *r) >> 8) + (p->s).unk_coord.x;
      (p->s).coord.y = ((c1 * *r) >> 8) + (p->s).unk_coord.y;
      (p->s).angle = -t;
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

bool8 FUN_080756e8(struct Enemy* p) { return TRUE; }

void FUN_080756ec(struct Enemy* p0) {
  register struct Enemy* p asm("r4");
  register s32 nm asm("r0");
  p = p0;
  switch ((p->s).mode[2]) {
    case 0: {
      register const s16* tb asm("r0");
      register u16* ang asm("r3");
      register s8* st asm("r2");
      SetDDP(&p->body, &sCollisions[3]);
      if ((p->s).coord.x > (pZero2->s).coord.x) {
        tb = gSineTable;
        ang = (u16*)((u8*)p + 0xc0);
        st = (s8*)((u8*)p + 0xb4);
        {
          register s32 sv asm("r1");
          {
            register u32 a asm("r1");
            register u32 b asm("r5");
            a = *(u8*)st;
            b = *(u8*)ang;
            a += b;
            sv = tb[(u8)a];
          }
          {
            register s32 cur asm("r0");
            cur = *(s16*)((u8*)p + 0xc2);
            if (cur > sv) {
              register s32 v asm("r0");
              v = -*st;
              *st = v;
            }
          }
        }
        (p->s).d.x = 0x40;
        *ang = 0x40;
        *st = 2;
        nm = 1;
      } else {
        tb = gSineTable;
        ang = (u16*)((u8*)p + 0xc0);
        st = (s8*)((u8*)p + 0xb4);
        {
          register s32 sv asm("r1");
          {
            register u32 a asm("r1");
            register u32 b asm("r5");
            a = *(u8*)st;
            b = *(u8*)ang;
            a += b;
            sv = tb[(u8)a];
          }
          {
            register s32 cur asm("r0");
            cur = *(s16*)((u8*)p + 0xc2);
            if (cur > sv) {
              register s32 v asm("r0");
              v = -*st;
              *st = v;
            }
          }
        }
        {
          register s32 v asm("r0");
          v = 0x40;
          v = -v;
          (p->s).d.x = v;
        }
        *ang = 0xc0;
        *st = 2;
        nm = 5;
      }
      (p->s).mode[2] = nm;
      (p->s).work[2] = 0xf0;
      FALLTHROUGH;
    }
    case 1: {
      struct Coord sc1;
      {
        register s32 dy asm("r0");
        register s32 dx asm("r1");
        dy = (p->s).d.y;
        dx = (p->s).d.x;
        if (dy < dx) {
          dy += 3;
          (p->s).d.y = dy;
          if (dy < dx) {
            goto spin1;
          }
          {
            register s32 k asm("r2");
            register s32 ax asm("r0");
            ax = (p->s).coord.x;
            sc1.x = ax;
            dx = (p->s).coord.y;
            k = -0x800;
            dx += k;
          }
        } else {
          dy -= 3;
          (p->s).d.y = dy;
          if (dy > dx) {
            goto spin1;
          }
          {
            register s32 k asm("r3");
            register s32 ax asm("r0");
            ax = (p->s).coord.x;
            sc1.x = ax;
            dx = (p->s).coord.y;
            k = -0x800;
            dx += k;
          }
        }
        sc1.y = dx;
        asm("" : "+m"(sc1));
        {
          register s32 ax asm("r0");
          if (((u16)((s32 (*)(s32, s32))FUN_0800daec)(ax, dx)) == 1) {
            ((bool8 (*)(struct Enemy*, s32))FUN_08075a84)(p, 0);
            PlaySound(0x2d);
          }
        }
      }
      (p->s).d.x = 0x80 << 7;
      (p->s).mode[2]++;
    spin1:
      {
        register const s16* tb asm("r1");
        register s32 t2 asm("r2");
        register s32* r asm("r3");
        tb = gSineTable;
        t2 = (p->s).d.y;
        {
          register s32 sv asm("r5");
          sv = tb[(u8)t2];
          sc1.x = sv;
          sv = tb[(u8)(t2 + 0x40)];
          sc1.y = sv;
        }
        asm("" : "+m"(sc1));
        r = (s32*)((u8*)p + 0xbc);
        {
          register s32 v asm("r0");
          register s32 s1 asm("r5");
          v = *r;
          s1 = sc1.x;
          v = s1 * v;
          v >>= 8;
          v += (p->s).unk_coord.x;
          (p->s).coord.x = v;
          v = *r;
          {
            register s32 cc asm("r1");
            cc = sc1.y;
            v = cc * v;
          }
          v >>= 8;
          v += (p->s).unk_coord.y;
          (p->s).coord.y = v;
        }
        {
          register s32 a asm("r2");
          register u8* q asm("r0");
          a = -t2;
          q = (u8*)p + 0x24;
          *q = a;
        }
        UpdateEntityAnim(&p->s);
      }
      break;
    }
    case 2: {
      s32 sc2x;
      s32 sc2y;
      register s32 t asm("r2");
      register s32 rc asm("r1");
      {
        register s32* r asm("r3");
        register const s16* tb asm("r3");
        {
          register u16* ang asm("r1");
          register s32 a asm("r0");
          tb = gSineTable;
          ang = (u16*)((u8*)p + 0xc0);
          a = *(s8*)((u8*)p + 0xb4);
          {
            register u32 cur asm("r2");
            cur = *ang;
            a += cur;
          }
          *ang = a;
          t = tb[(u8)a];
          *(u16*)((u8*)p + 0xc2) = t;
        }
        {
          register s32 dx asm("r1");
          register s32 v asm("r0");
          dx = (p->s).d.x;
          v = 0xe0 << 6;
          v -= dx;
          v <<= 3;
          v >>= 8;
          dx += v;
          (p->s).d.x = dx;
          t = dx * t;
          t >>= 0x10;
          (p->s).d.y = t;
        }
        {
          register s32 sv asm("r1");
          sv = tb[(u8)t];
          *(volatile s32*)&sc2x = sv;
          sv = tb[(u8)(t + 0x40)];
          *(volatile s32*)&sc2y = sv;
        }
        r = (s32*)((u8*)p + 0xbc);
        {
          register s32 v asm("r0");
          register s32 s1 asm("r5");
          v = *r;
          s1 = sc2x;
          v = s1 * v;
          v >>= 8;
          v += (p->s).unk_coord.x;
          (p->s).coord.x = v;
          nm = *r;
        }
        rc = sc2y;
      }
      goto rotortail;
    }
    case 5:
      {
        register s32 dy asm("r0");
        register s32 dx asm("r1");
        dy = (p->s).d.y;
        dx = (p->s).d.x;
        if (dy < dx) {
          dy += 3;
          (p->s).d.y = dy;
          if (dy < dx) {
            goto spin5;
          }
          {
            register s32 k asm("r2");
            dy = (p->s).coord.x;
            dx = (p->s).coord.y;
            k = -0x800;
            asm("" : "+l"(k));
            dx += k;
          }
        } else {
          dy -= 3;
          (p->s).d.y = dy;
          if (dy > dx) {
            goto spin5;
          }
          {
            register s32 k asm("r3");
            dy = (p->s).coord.x;
            dx = (p->s).coord.y;
            k = -0x800;
            asm("" : "+l"(k));
            dx += k;
          }
        }
        if (((u16)((s32 (*)(s32, s32))FUN_0800daec)(dy, dx)) == 1) {
          ((bool8 (*)(struct Enemy*, s32))FUN_08075a84)(p, 0);
          PlaySound(0x2d);
        }
      }
      (p->s).d.x = 0x80 << 7;
      (p->s).mode[2]++;
    spin5:
      {
        register const s16* tb asm("r1");
        register s32 t2 asm("r2");
        register s32* r asm("r3");
        register s32 s1v asm("r5");
        register s32 c1v asm("r6");
        tb = gSineTable;
        t2 = (p->s).d.y;
        s1v = tb[(u8)t2];
        c1v = tb[(u8)(t2 + 0x40)];
        r = (s32*)((u8*)p + 0xbc);
        {
          register s32 v asm("r0");
          register s32 s1 asm("r5");
          v = *r;
          s1 = s1v;
          v = s1 * v;
          v >>= 8;
          v += (p->s).unk_coord.x;
          (p->s).coord.x = v;
          v = *r;
          {
            register s32 cc asm("r1");
            cc = c1v;
            v = cc * v;
          }
          v >>= 8;
          v += (p->s).unk_coord.y;
          (p->s).coord.y = v;
        }
        {
          register s32 a asm("r2");
          register u8* q asm("r0");
          a = -t2;
          q = (u8*)p + 0x24;
          *q = a;
        }
        UpdateEntityAnim(&p->s);
      }
      break;
    case 6: {
      s32 sc6x;
      s32 sc6y;
      register s32 t asm("r2");
      register s32 rc asm("r1");
      {
        register s32* r asm("r3");
        register const s16* tb asm("r3");
        {
          register u16* ang asm("r1");
          register s32 a asm("r0");
          tb = gSineTable;
          ang = (u16*)((u8*)p + 0xc0);
          a = *(s8*)((u8*)p + 0xb4);
          {
            register u32 cur asm("r2");
            cur = *ang;
            a += cur;
          }
          *ang = a;
          t = tb[(u8)a];
          *(u16*)((u8*)p + 0xc2) = t;
        }
        {
          register s32 dx asm("r1");
          register s32 v asm("r0");
          dx = (p->s).d.x;
          v = 0xe0 << 6;
          v -= dx;
          v <<= 3;
          v >>= 8;
          dx += v;
          (p->s).d.x = dx;
          t = dx * t;
          t >>= 0x10;
          (p->s).d.y = t;
        }
        {
          register s32 sv asm("r1");
          sv = tb[(u8)t];
          *(volatile s32*)&sc6x = sv;
          sv = tb[(u8)(t + 0x40)];
          *(volatile s32*)&sc6y = sv;
        }
        r = (s32*)((u8*)p + 0xbc);
        {
          register s32 v asm("r0");
          register s32 s1 asm("r5");
          v = *r;
          s1 = sc6x;
          v = s1 * v;
          v >>= 8;
          v += (p->s).unk_coord.x;
          (p->s).coord.x = v;
          nm = *r;
        }
        rc = sc6y;
      }
    rotortail:
      nm = rc * nm;
      nm >>= 8;
      nm += (p->s).unk_coord.y;
      (p->s).coord.y = nm;
      {
        register s32 a asm("r2");
        register u8* q asm("r0");
        a = -t;
        q = (u8*)p + 0x24;
        *q = a;
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] != 0) {
        register s32 v asm("r0");
        v = (p->s).work[2] - 1;
        (p->s).work[2] = v;
        if ((v << 24) != 0) {
          break;
        }
      }
      {
        register s32 one asm("r0");
        one = 1;
        (p->s).mode[1] = one;
        one = 0;
        (p->s).mode[2] = one;
      }
      break;
    }
  }
}

bool8 FUN_08075a30(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    if ((s8)p->buffer[1] == 1) {
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      p->buffer[1] = 0;
    }
  }
  return TRUE;
}

void FUN_08075a5c(struct Body* body) {
  const struct Collision* c = (body->enemy)->processing;
  if (c->special == 1) {
    if ((*(u32*)&c->atkType & 0x000200FF) == 0x00020002) {
      ((struct Enemy*)body->parent)->buffer[1] = 1;
    }
  }
}

bool8 FUN_08075a84(struct Enemy* p) {
  struct Coord c;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y - PIXEL(16);
  FUN_080b9228(&c, 0);
  return TRUE;
}

// --------------------------------------------

// 0x08367044
static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
};
