#include "collision.h"
#include "element.h"
#include "enemy.h"
#include "global.h"

extern const motion_t Action_ARRAY_080ff004[4];
#include "motion.h"
#include "projectile/unk_06.h"
#include "stagerun.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  s32 x_b4;              // 0xB4
  u8 unk_b8;             // 0xB8
  u8 unk_b9;             // 0xB9
  u8 unk_ba;             // 0xBA
  u8 unk_bb;             // 0xBB
  u8 unk_bc;             // 0xBC
  struct Entity* elfx;   // 0xC0, Element FX
} Lamplort;
static_assert(sizeof(Lamplort) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

NAKED static void Lamplort_Init(Lamplort* p);
static void Lamplort_Update(Lamplort* p);
void Lamplort_Die(Lamplort* p);
void Lamplort_Disappear(Lamplort* p);

// clang-format off
const EnemyRoutine gLamplortRoutine = {
    [ENTITY_INIT] =      (void*)Lamplort_Init,
    [ENTITY_UPDATE] =    (void*)Lamplort_Update,
    [ENTITY_DIE] =       (void*)Lamplort_Die,
    [ENTITY_DISAPPEAR] = (void*)Lamplort_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static struct Entity* CreateLamplort(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_LAMPLORT);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

// --------------------------------------------

NAKED static void Lamplort_OnCollision(struct Body* body, Coords32* c, Coords32* _ UNUSED);

NAKED static void Lamplort_Init(Lamplort* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #2\n\
	orrs r2, r0\n\
	orrs r2, r3\n\
	strb r2, [r6, #0xa]\n\
	ldr r0, _0806C290 @ =gSystemSavedata\n\
	ldrb r1, [r0, #0x15]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806C29C\n\
	ldr r0, _0806C294 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _0806C29C\n\
	movs r0, #4\n\
	orrs r2, r0\n\
	strb r2, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806C298 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0xc\n\
	b _0806C2B4\n\
	.align 2, 0\n\
_0806C290: .4byte gSystemSavedata\n\
_0806C294: .4byte gCurStory\n\
_0806C298: .4byte sCollisions\n\
_0806C29C:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #4\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0806C2E0 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
_0806C2B4:\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	ldr r0, _0806C2E4 @ =Lamplort_OnCollision\n\
	str r0, [r4, #0x24]\n\
	adds r1, r6, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r6, #0x54]\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	str r0, [r6, #0x60]\n\
	str r0, [r6, #0x5c]\n\
	ldrb r1, [r6, #0x10]\n\
	cmp r1, #0\n\
	bne _0806C2E8\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	strb r1, [r0]\n\
	adds r4, r0, #0\n\
	b _0806C2F2\n\
	.align 2, 0\n\
_0806C2E0: .4byte sCollisions\n\
_0806C2E4: .4byte Lamplort_OnCollision\n\
_0806C2E8:\n\
	adds r1, r6, #0\n\
	adds r1, #0xbc\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r4, r1, #0\n\
_0806C2F2:\n\
	ldrb r2, [r4]\n\
	cmp r2, #0\n\
	beq _0806C300\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _0806C306\n\
_0806C300:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0806C306:\n\
	strb r0, [r6, #0xa]\n\
	movs r7, #1\n\
	adds r1, r7, #0\n\
	ands r1, r2\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	movs r5, #0\n\
	strb r1, [r0]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	str r5, [r0]\n\
	strb r5, [r6, #0x12]\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	bl FUN_0800a05c\n\
	str r0, [r6, #0x58]\n\
	ldrb r2, [r4]\n\
	adds r0, r6, #0\n\
	mov r1, sp\n\
	movs r3, #0\n\
	bl CreateProjectile6\n\
	str r0, [r6, #0x2c]\n\
	adds r0, r6, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	beq _0806C362\n\
	movs r1, #0xc8\n\
	lsls r1, r1, #5\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateEntityAnim\n\
_0806C362:\n\
	adds r0, r6, #0\n\
	adds r0, #0xbb\n\
	strb r5, [r0]\n\
	ldr r1, _0806C38C @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	strb r7, [r6, #0xd]\n\
	strb r5, [r6, #0xe]\n\
	strb r5, [r6, #0xf]\n\
	adds r0, r6, #0\n\
	bl Lamplort_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806C38C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

bool8 FUN_0806c81c(struct Enemy* p);
bool8 FUN_0806c824(struct Enemy* p);
bool8 FUN_0806c8c8(struct Enemy* p);
bool8 FUN_0806c9c0(struct Enemy* p);
bool8 true_0806cac4(struct Enemy* p);
bool8 FUN_0806cb58(struct Enemy* p);
bool8 FUN_0806cc00(struct Enemy* p);
static bool32 true_0806cd48(void* _ UNUSED);
static bool32 FUN_0806cda4(void* _ UNUSED);
static bool32 FUN_0806cdac(void* _ UNUSED);

// clang-format off
// 0x08366540
static const EnemyFunc sUpdates1[10] = {
    (void*)FUN_0806c81c,
    (void*)FUN_0806c824,
    (void*)FUN_0806c8c8,
    (void*)FUN_0806c9c0,
    (void*)true_0806cac4,
    (void*)FUN_0806cb58,
    (void*)FUN_0806cc00,
    (void*)true_0806cd48,
    (void*)FUN_0806cda4,
    (void*)FUN_0806cdac,
};
// clang-format on

void FUN_0806c820(struct Enemy* p);
static void FUN_0806c828(Lamplort* p);
void FUN_0806c8cc(struct Enemy* p);
void FUN_0806c9c4(struct Enemy* p);
static void FUN_0806cac8(Lamplort* p);
static void FUN_0806cb5c(Lamplort* p);
void lamplort_0806cc04(struct Enemy* p);
static void FUN_0806cd4c(Lamplort* p);
static void FUN_0806cda8(void* _ UNUSED);
static void FUN_0806cdb0(Lamplort* p);

// clang-format off
// 0x08366568
static const EnemyFunc sUpdates2[10] = {
    (void*)FUN_0806c820,
    (void*)FUN_0806c828,
    (void*)FUN_0806c8cc,
    (void*)FUN_0806c9c4,
    (void*)FUN_0806cac8,
    (void*)FUN_0806cb5c,
    (void*)lamplort_0806cc04,
    (void*)FUN_0806cd4c,
    (void*)FUN_0806cda8,
    (void*)FUN_0806cdb0,
};
// clang-format on

static bool32 FUN_0806ce5c(void* _ UNUSED);

static bool32 FUN_0806ce5c(void* _);
static bool32 lamplort_0806ce08(Lamplort* p);

static void Lamplort_Update(Lamplort* p) {
  u8 m;
  if (!((p->body).status & BODY_STATUS_DEAD)) {
    if (FUN_0806ce5c(p)) {
      goto alive;
    }
  }
  SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  Lamplort_Die(p);
  return;

alive:
  if (IsFrozen(p)) {
    u32 v;
    ((LamplortFlame*)(p->unk_2c))->unk_b4 |= 2;
    v = (u32)p->elfx;
    if (v == 0) {
      p->mode[1] = 1, p->mode[2] = 0;
    }
  }
  (sUpdates1[p->mode[1]])((struct Enemy*)p);
  lamplort_0806ce08(p);
  m = p->mode[1];
  if (m == 7) goto dispatch2;
  if (m == 9) goto dispatch2;
  if (IsFrozen(p)) {
    p->unk_ba = p->mode[1];
    return;
  }
dispatch2:
  (sUpdates2[p->mode[1]])((struct Enemy*)p);
}

INCASM("asm/enemy/lamplort_a.inc");

void Lamplort_Disappear(Lamplort* p) { DeleteEnemy((struct Entity*)p); }

bool8 FUN_0806c81c(struct Enemy* p) { return TRUE; }

void FUN_0806c820(struct Enemy* p) {}

bool8 FUN_0806c824(struct Enemy* p) { return TRUE; }

static void FUN_0806c828(Lamplort* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 40;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      SetDDP(&p->body, &sCollisions[0]);
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 0));
      SET_XFLIP(p, p->unk_bc);
      p->mode[2]++;
      FALLTHROUGH;
    case 2:
      UpdateSpriteAnimation(p);
      if (p->work[2] == 0 || --p->work[2] == 0) {
        p->mode[1] = 2, p->mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_0806c8c8(struct Enemy* p) { return TRUE; }

void FUN_0806c8cc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      register s32 one asm("r6");
      u8 v;
      SetMotion(&p->s, MOTION(0x19, 4));
      SetDDP(&p->body, &sCollisions[0]);
      {
        u32* f = (u32*)((u8*)(p->s).unk_2c + 0xb4);
        u32 fv = *f;
        one = 1;
        *f = fv | one;
      }
      (p->s).work[2] = 0;
      PlaySound(0x11F);
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x4000) {
        (p->s).work[3] = 0;
      } else {
        (p->s).work[3] = one;
      }
      v = *((u8*)p + 0xbc);
      {
        register u8 nf asm("r0");
        if (v != 0) {
          register u8 fl asm("r1");
          fl = (p->s).flags;
          nf = 0x10;
          nf |= fl;
        } else {
          register u8 fl2 asm("r1");
          fl2 = (p->s).flags;
          asm("" : "+r"(fl2));
          nf = 0xEF;
          nf &= fl2;
        }
        (p->s).flags = nf;
      }
      {
        register s32 x asm("r1");
        u8* a;
        s32 sh;
        u8 ov;
        s32 m;
        x = 1;
        x &= v;
        ((p->s).spr).xflip = x;
        a = (u8*)p + 0x4a;
        sh = x << 4;
        ov = *a;
        m = -0x11;
        m &= ov;
        m |= sh;
        *a = m;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      u8 nv;
      u8 st;
      if ((p->s).work[3] == 0) {
        if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x4000) {
          goto skip;
        }
        nv = 1;
      } else {
        if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) <= 0x4000) {
          goto skip;
        }
        nv = 0;
      }
      (p->s).work[3] = nv;
    skip:
      UpdateEntityAnim(&p->s);
      st = *((u8*)p + 0x73);
      if (st == 3) {
        (p->s).mode[1] = st;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }
}

bool8 FUN_0806c9c0(struct Enemy* p) { return TRUE; }

void FUN_0806c9c4(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0x19, 0x06));
      SetDDP(&p->body, &sCollisions[0]);
      SET_XFLIP(p, *(u8*)((u8*)p + 0xbc));
      (p->s).work[2] = 0xFF;
      if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x4000) {
        (p->s).work[3] = 0;
      } else {
        (p->s).work[3] = 1;
      }
      (p->s).mode[2]++;
      /* fallthrough */
    case 1: {
      u8 w2 = (p->s).work[2];
      if ((w2 & 0xF) == 0) {
        PlaySound(0x11F);
      }
    }
      if ((p->s).work[3] == 0) {
        if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) <= 0x4000) {
          (p->s).work[3] = 1;
        }
      } else {
        if (Camera_GetDistance(&gStageRun.vm.camera, &(p->s).coord) > 0x4000) {
          (p->s).work[3] = 0;
        }
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] != 0) {
        if ((u8)--(p->s).work[2] != 0) {
          break;
        }
      }
      (p->s).mode[1] = 4, (p->s).mode[2] = 0;
      break;
  }
}

bool8 true_0806cac4(struct Enemy* p) { return TRUE; }

static void FUN_0806cac8(Lamplort* p) {
  switch (p->mode[2]) {
    case 0: {
      LamplortFlame* flame;
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 8));
      SetDDP(&p->body, &sCollisions[0]);
      flame = (LamplortFlame*)(p->unk_2c);
      flame->unk_b4 |= 2;
      SET_XFLIP(p, p->unk_bc);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_0806cb58(struct Enemy* p) { return TRUE; }

static void FUN_0806cb5c(Lamplort* p) {
  switch (p->mode[2]) {
    case 0: {
      LamplortFlame* flame;
      SetSpriteAnimation(p, MOTION(SM025_LAMPLORT, 1));
      SetDDP(&p->body, &sCollisions[0]);
      SET_XFLIP(p, p->unk_bc);
      flame = (LamplortFlame*)(p->unk_2c);
      flame->unk_b4 |= 2;
      p->work[2] = 8;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        if (p->work[2] == 0 || --p->work[2] == 0) {
          p->mode[1] = 6, p->mode[2] = 0;
        }
      }
      break;
  }
}

bool8 FUN_0806cc00(struct Enemy* p) { return TRUE; }

void lamplort_0806cc04(struct Enemy* p) {
  s32 m = (p->s).mode[2];
  switch (m) {
    case 0: {
      u8 fv;
      u32 x1;
      s32 z3;
      SetMotion(&p->s, 0x1902);
      SetDDP(&p->body, &sCollisions[5]);
      fv = *((u8*)p + 0xbc);
      if (fv != 0) {
        (p->s).flags |= 0x10;
      } else {
        (p->s).flags &= 0xEF;
      }
      x1 = 1 & fv;
      {
        bool8* xa = &((p->s).spr).xflip;
        z3 = 0;
        *xa = x1;
      }
      {
        register u8* t0 asm("r0");
        register u8* oa asm("ip");
        u32 off = 0x4a;
        asm("" : "+r"(off));
        off += (u32)p;
        t0 = (u8*)off;
        oa = t0;
        asm("" : "+r"(oa));
        x1 <<= 4;
        {
          s32 ov = *t0;
          s32 m11 = -0x11;
          u32 vv;
          register u8* fa asm("r1");
          asm("" : "+r"(m11));
          vv = (m11 & ov) | x1;
          fa = oa;
          asm("" : "+r"(fa));
          *fa = vv;
        }
      }
      (p->s).work[3] = z3;
      (p->s).work[2] = 8;
      (p->s).mode[2]++;
    }
      /* fallthrough */
    case 1: {
      u8 w2 = (p->s).work[2];
      if (w2 != 0) {
        s32 t = w2 - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          goto umg;
        }
      }
      {
        s32 raw = (p->s).work[3] + 1;
        u8 t3;
        (p->s).work[3] = raw;
        t3 = raw;
        if (t3 > 2) {
          (p->s).mode[2]++;
        } else {
          (p->s).work[2] = 8;
          if (t3 == 2) {
            SetMotion(&p->s, Action_ARRAY_080ff004[(p->s).work[3]]);
          }
          if ((p->s).work[3] == 1) {
            SetDDP(&p->body, &sCollisions[5]);
          } else {
            SetDDP(&p->body, &sCollisions[0]);
          }
        }
      }
      if ((p->s).work[3] == 1) {
        u8* bc = (u8*)p + 0xbc;
        register u32 nv asm("r1");
        register u32 one2 asm("r2");
        u8 rv;
        u32 x2;
        nv = *bc;
        one2 = 1;
        asm("" : "+r"(one2));
        nv ^= one2;
        *bc = nv;
        rv = *bc;
        if (rv != 0) {
          register s32 flA asm("r0");
          register s32 cA asm("r1");
          flA = (p->s).flags;
          cA = 0x10;
          asm("" : "+r"(cA));
          flA |= cA;
          (p->s).flags = flA;
        } else {
          (p->s).flags &= 0xEF;
        }
        x2 = 1 & rv;
        ((p->s).spr).xflip = x2;
        {
          register u8* oa3 asm("r3");
          s32 ov2;
          s32 m11b;
          oa3 = (u8*)&((p->s).spr).oam + 6;
          x2 <<= 4;
          ov2 = *oa3;
          m11b = -0x11;
          asm("" : "+r"(m11b));
          *oa3 = (m11b & ov2) | x2;
        }
      }
    umg:
      UpdateEntityAnim(&p->s);
      break;
    }
    case 2:
      (p->s).mode[1] = 1;
      (p->s).mode[2] = 0;
      break;
  }
}

static bool32 true_0806cd48(void* _ UNUSED) { return TRUE; }

static void FUN_0806cd4c(Lamplort* p) {
  if (p->mode[2] == 0) {
    LamplortFlame* flame;
    SetDDP(&p->body, &sCollisions[7]);
    flame = (LamplortFlame*)(p->unk_2c);
    flame->unk_b4 |= 2;
    p->mode[2]++;
  }
  if (IsDead(p->elfx)) {
    SetDDP(&p->body, &sCollisions[0]);
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

static bool32 FUN_0806cda4(void* _ UNUSED) { return TRUE; }

static void FUN_0806cda8(void* _ UNUSED) {}

static bool32 FUN_0806cdac(void* _ UNUSED) { return TRUE; }

static void FUN_0806cdb0(Lamplort* p) {
  if (p->mode[2] == 0) {
    LamplortFlame* flame;
    SetDDP(&p->body, &sCollisions[7]);
    flame = (LamplortFlame*)(p->unk_2c);
    flame->unk_b4 |= 2;
    p->d.y = 0;
    p->mode[2]++;
  }
  if (IsDead(p->elfx)) {
    SetDDP(&p->body, &sCollisions[0]);
    p->elfx = NULL;
    p->mode[1] = 1, p->mode[2] = 0;
  }
}

static const Coords32 sElementCoord;

static bool32 lamplort_0806ce08(Lamplort* p) {
  if ((p->elfx == NULL) && ((p->body).status & BODY_STATUS_WHITE)) {
    p->elfx = (void*)ApplyElementEffect(0, (Object*)p, &sElementCoord);
    if (p->elfx != NULL) {
      if ((p->body).elemented == ELEMENT_THUNDER) {
        p->mode[1] = 7, p->mode[2] = 0;
      } else if ((p->body).elemented == ELEMENT_ICE) {
        p->mode[1] = 9, p->mode[2] = 0;
      }
    }
  }
  return TRUE;
}

static bool32 FUN_0806ce5c(void* _ UNUSED) { return TRUE; }

/**
 * @note 0x0806ce60
 */
NAKED static void Lamplort_OnCollision(struct Body* body, Coords32* c, Coords32* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	adds r4, r1, #0\n\
	ldr r0, [r3, #0xc]\n\
	ldr r0, [r0, #4]\n\
	ldrb r0, [r0, #4]\n\
	cmp r0, #3\n\
	beq _0806CE78\n\
	cmp r0, #0xe\n\
	beq _0806CE78\n\
	cmp r0, #0xf\n\
	bne _0806CEA2\n\
_0806CE78:\n\
	ldr r2, [r3, #0x2c]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806CEA2\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, [r4]\n\
	cmp r1, r0\n\
	bge _0806CE9A\n\
	adds r1, r2, #0\n\
	adds r1, #0xbb\n\
	movs r0, #0xff\n\
	b _0806CEA0\n\
_0806CE9A:\n\
	adds r1, r2, #0\n\
	adds r1, #0xbb\n\
	movs r0, #0xfe\n\
_0806CEA0:\n\
	strb r0, [r1]\n\
_0806CEA2:\n\
	ldr r0, [r3, #4]\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _0806CF20\n\
	ldr r0, [r3, #0xc]\n\
	ldr r0, [r0, #4]\n\
	ldr r0, [r0, #4]\n\
	ldr r1, _0806CEEC @ =0x000200FF\n\
	ands r0, r1\n\
	subs r1, #0xfd\n\
	cmp r0, r1\n\
	bne _0806CF20\n\
	ldr r2, [r3, #0x2c]\n\
	ldrb r0, [r2, #0xd]\n\
	subs r0, #5\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bls _0806CF20\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0\n\
	bne _0806CEF4\n\
	ldr r0, _0806CEF0 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r2, #0x54]\n\
	cmp r1, r0\n\
	bge _0806CF08\n\
	movs r0, #5\n\
	strb r0, [r2, #0xd]\n\
	strb r3, [r2, #0xe]\n\
	b _0806CF08\n\
	.align 2, 0\n\
_0806CEEC: .4byte 0x000200FF\n\
_0806CEF0: .4byte pZero2\n\
_0806CEF4:\n\
	ldr r0, _0806CF28 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r2, #0x54]\n\
	cmp r1, r0\n\
	ble _0806CF08\n\
	movs r1, #0\n\
	movs r0, #5\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
_0806CF08:\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806CF20\n\
	adds r1, r2, #0\n\
	adds r1, #0xa4\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
_0806CF20:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806CF28: .4byte pZero2\n\
 .syntax divided\n");
}

// --------------------------------------------

// 0x08366590
static const struct Collision sCollisions[8] = {
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 4,
      range : {-PIXEL(9), -PIXEL(14), PIXEL(26), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 3,
      priorityLayer : 0xFFFFFFFF,
      range : {-PIXEL(8), -PIXEL(14), PIXEL(24), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 2,
      range : {PIXEL(10), -PIXEL(14), PIXEL(14), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(6), -PIXEL(14), PIXEL(31), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(14), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(11), PIXEL(20), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 3,
      remaining : 0,
      range : {PIXEL(2), -PIXEL(12), PIXEL(22), PIXEL(20)},
    },
};

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(10)};
