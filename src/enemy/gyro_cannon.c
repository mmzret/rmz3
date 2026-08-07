#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "overworld_terrain.h"
#include "vfx.h"
#include "score.h"
#include "zero.h"

void FUN_080b2b40(u8 kind, struct Coord* c, s32 v, u8 n);
struct Projectile* CreateLemon(struct Coord* c, s32 r1, u8 r2);
void CreateProjectile8(s32 x, s32 y);
void CreateGhost27(struct Coord* c, u8 r1, u8 r2);

typedef struct {
  COLLISION_OBJECT_HDR;
  struct {
    Entity* elfx;    // 0xB4
    s32 init_y;      // 0xB8
    bool8 is_right;  // 0xBC
    u8 unk_bd;       // 0xBD
    u8 unk_be;       // 0xBE
    u8 unk_bf;       // 0xBF
    u32 unk_c0;      // 0xC0
  } props;           // props (16bytes, offset: 0xB4..)
} GyroCannon;
static_assert(sizeof(GyroCannon) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void GyroCannon_Init(GyroCannon* p);
static void GyroCannon_Update(GyroCannon* p);
static void GyroCannon_Die(GyroCannon* p);

// clang-format off
const EnemyRoutine gGyroCannonRoutine = {
    [ENTITY_INIT] =      (void*)GyroCannon_Init,
    [ENTITY_UPDATE] =    (void*)GyroCannon_Update,
    [ENTITY_DIE] =       (void*)GyroCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const struct SlashedEnemy sSlashedEnemies[4];
static void (*const sUpdates2[3])(GyroCannon*);
static Entity* CreateGyroCannon(Entity* q, bool8 isPropeller, u8 r2) {
  Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_GYRO_CANNON);
    p->unk_28 = q;
    p->work[0] = isPropeller, p->work[1] = r2;
  }
  return p;
}

// --------------------------------------------

static void initGyroCannonMainBody(GyroCannon* p);
static void initGyroCannonPropeller(GyroCannon* p);

static void GyroCannon_Init(GyroCannon* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] != 0) {  // propeller
    initGyroCannonPropeller(p);
  } else {
    initGyroCannonMainBody(p);
  }
  GyroCannon_Update(p);
}

void gyrocannon_0806d32c(GyroCannon* p);
NAKED static void gyrocannon_0806d1b4(GyroCannon* p);

static void GyroCannon_Update(GyroCannon* p) {
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (p->work[0] != 0) {
    gyrocannon_0806d32c(p);  // propeller
  } else {
    gyrocannon_0806d1b4(p);
  }
}

void FUN_0806d524(GyroCannon* p);
void FUN_0806d470(GyroCannon* p);

static void GyroCannon_Die(GyroCannon* p) {
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (p->work[0] != 0) {
    FUN_0806d524(p);  // propeller
  } else {
    FUN_0806d470(p);
  }
}

// --------------------------------------------

static void GyroCannon_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

// 0x0806d0a8
static void initGyroCannonMainBody(GyroCannon* p) {
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 0));
  UpdateSpriteAnimation(p);
  if (FLAG(gSystemSavedata.flags, MOD_GYRO_CANNON) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 20);
  } else {
    _INIT_BODY(p, sCollisions, 16);
  }
  SET_BODY_INTERSECT_HANDLER(p, GyroCannon_OnCollision);
  p->unk_2c = CreateGyroCannon((void*)p, TRUE, 0);
  (&p->props)->unk_bd = 0;
  (&p->props)->init_y = p->coord.y;
  (&p->props)->unk_be = 0, (&p->props)->unk_bf = 0;
  p->d.y = 0;
  p->work[3] = 0;
  (&p->props)->elfx = NULL;
  p->mode[1] = 2;
}

static void initGyroCannonPropeller(GyroCannon* p) {
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 6));
  UpdateSpriteAnimation(p);
  INIT_BODY(p, &sCollisions[2], 6, NULL);
  p->flags &= ~X_FLIP;
  (p->spr).xflip = FALSE, (p->spr).oam.xflip = FALSE;
  (p->props).elfx = NULL;
}

NAKED static void gyrocannon_0806d1b4(GyroCannon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, _0806D204 @ =0xFFFFE800\n\
	adds r1, r1, r2\n\
	bl IsVoidSpace\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _0806D20C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0806D208 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D204: .4byte 0xFFFFE800\n\
_0806D208: .4byte gEnemyFnTable\n\
_0806D20C:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r1, r0, #0\n\
	cmp r1, #1\n\
	beq _0806D246\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	beq _0806D222\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0806D222\n\
	str r2, [r4, #0x2c]\n\
_0806D222:\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	beq _0806D246\n\
	adds r3, r4, #0\n\
	adds r3, #0x8c\n\
	ldr r0, [r3]\n\
	ldr r1, _0806D250 @ =0x00020001\n\
	ands r0, r1\n\
	cmp r0, r1\n\
	bne _0806D240\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0806D240:\n\
	ldrb r2, [r4, #0xd]\n\
	cmp r2, #1\n\
	bne _0806D254\n\
_0806D246:\n\
	adds r0, r4, #0\n\
	bl FUN_0806d684\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D250: .4byte 0x00020001\n\
_0806D254:\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806D280\n\
	ldr r1, _0806D27C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl GyroCannon_Die\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D27C: .4byte gEnemyFnTable\n\
_0806D280:\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	cmp r2, #8\n\
	beq _0806D2AC\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0806D2AC\n\
	ldr r6, [r5]\n\
	cmp r6, #0\n\
	bne _0806D2B2\n\
	ldr r2, _0806D2D0 @ =0x083666A0\n\
	movs r0, #0\n\
	adds r1, r4, #0\n\
	bl ApplyElementEffect\n\
	str r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
	movs r0, #8\n\
	strb r0, [r4, #0xd]\n\
	strb r6, [r4, #0xe]\n\
_0806D2AC:\n\
	ldr r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
_0806D2B2:\n\
	ldr r1, _0806D2D4 @ =0x0836666C\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D2D8 @ =0x083666C0\n\
	bl SetDDP\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D2D0: .4byte sElementCoord\n\
_0806D2D4: .4byte PTR_ARRAY_0836666c\n\
_0806D2D8: .4byte sCollisions+(24*1)\n\
_0806D2DC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D324 @ =sCollisions\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	bne _0806D31C\n\
	ldrb r0, [r5, #0xb]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	beq _0806D306\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0806D306:\n\
	ldr r0, _0806D328 @ =0x0836666C\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_0806D31C:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806D324: .4byte sCollisions\n\
_0806D328: .4byte PTR_ARRAY_0836666c\n\
 .syntax divided\n");
}

void gyrocannon_0806d32c(GyroCannon* p) {
  struct Entity* par = p->unk_28;
  if ((p->body).status & 0x200) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    GyroCannon_Die(p);
    return;
  }
  if (p->mode[1] == 0) {
    register u32 f asm("r0");
    s32 zv;
    if (par->mode[1] != 8) {
      SetDDP(&p->body, &sCollisions[2]);
      if (!IsFrozen(par)) {
        UpdateEntityAnim((struct Entity*)p);
      }
    } else {
      SetDDP(&p->body, &sCollisions[3]);
    }
    p->coord.x = par->coord.x;
    p->coord.y = par->coord.y;
    if (par->mode[0] > 1) {
      u8* pb = (u8*)par + 0xb4;
      s32 p9 = pb[9];
      if (p9 == 0) {
        register s32 flg asm("r1");
        register s32 cfe asm("r0");
        asm("" : "+r"(p9));
        flg = p->flags;
        cfe = 0xFE;
        asm("" : "+r"(cfe));
        f = cfe & flg;
        zv = p9;
        goto ta;
      }
      p->work[2] = 0x40;
      p->mode[1]++;
    }
    if (IsVoidSpace(par->coord.x, par->coord.y + -0x1800)) {
      register s32 flg2 asm("r1");
      register s32 cfe2 asm("r0");
      flg2 = p->flags;
      cfe2 = 0xFE;
      asm("" : "+r"(cfe2));
      f = cfe2 & flg2;
      zv = 0;
      asm("" : "+r"(zv));
    ta:
      asm("" : "+r"(f));
      f &= 0xFD;
      p->flags = f;
      (p->body).status = zv;
      (p->body).prevStatus = zv;
      (p->body).invincibleTime = zv;
      p->flags &= 0xFB;
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    }
  } else {
    s32 oy;
    UpdateEntityAnim((struct Entity*)p);
    oy = p->coord.y;
    p->coord.y = oy + -0x200;
    {
      s32 raw = p->work[2] - 1;
      p->work[2] = raw;
      if ((u8)raw == 0xFF) {
        goto die2;
      }
    }
    if (FUN_080098a4(p->coord.x, oy + -0xE00) != 0) {
    die2:
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      GyroCannon_Die(p);
    }
  }
}

void FUN_0806d470(GyroCannon* p) {
  if (p->mode[2] == 0) {
    u8* b0 = (u8*)p + 0xb4;
    u8 v = b0[0xa];
    u8* b;
    asm volatile("add %0, %1, #0" : "=&l"(b) : "l"(b0));
    if (v != 0) {
      p->mode[1] = 0;
    } else if (((p->body).status & 0x10000) != 0) {
      struct Coord c;
      c.x = p->coord.x;
      c.y = p->coord.y - 0x1400;
      FUN_080b2b40(0, &c, 0x200, b[8]);
      if (p->unk_2c != NULL) {
        p->mode[1] = 1;
      } else if ((u16)FUN_080098a4(p->coord.x, p->coord.y + 0xB00) != 0) {
        p->mode[1] = 2;
      } else {
        p->mode[1] = 0;
      }
    } else {
      p->mode[1] = 0;
    }
    EXIT_BODY(p);
    b[9] = 1;
    p->mode[2]++;
  }
  (sUpdates2[p->mode[1]])(p);
}

void FUN_0806d524(GyroCannon* p) {
  struct Coord c;
  c.x = p->coord.x;
  c.y = p->coord.y - 0x1200;
  CreateSmoke(2, &c);
  if (!((bool16 (*)(s32, s32))FUN_080098a4)(c.x, c.y)) {
    const struct SlashedEnemy* t0;
    register u8* b4 asm("r6");
    t0 = sSlashedEnemies;
    {
      register u8* b40 asm("r2");
      register s32 pal asm("r5");
      register s32 k asm("r3");
      register s32 kk asm("r0");
      register u8 fl asm("r1");
      b40 = (u8*)p + 0xb4;
      pal = b40[8];
      fl = p->flags;
      k = 0x10;
      kk = k;
      kk &= fl;
      asm volatile("add %0, %1, #0" : "=&l"(b4) : "l"(b40));
      if (kk != 0) {
        k |= pal;
      } else {
        k = pal;
      }
      ((struct VFX* (*)())CreateSlashedEnemy)(&c, t0, 0, k);
    }
    {
      register struct Coord* cp asm("r5");
      const struct SlashedEnemy* t1;
      register s32 pal2 asm("r2");
      register s32 k2 asm("r3");
      register s32 kk2 asm("r0");
      register u8 fl2 asm("r1");
      cp = &c;
      t1 = sSlashedEnemies;
      pal2 = b4[8];
      fl2 = p->flags;
      k2 = 0x10;
      kk2 = k2;
      kk2 &= fl2;
      if (kk2 != 0) {
        k2 |= pal2;
      } else {
        k2 = pal2;
      }
      ((struct VFX* (*)())CreateSlashedEnemy)(cp, t1, 0, k2);
    }
    {
      register struct Coord* cp2 asm("r5");
      const struct SlashedEnemy* t2;
      register s32 pal3 asm("r2");
      register s32 k3 asm("r3");
      register s32 kk3 asm("r0");
      register u8 fl3 asm("r1");
      cp2 = &c;
      t2 = &sSlashedEnemies[1];
      pal3 = b4[8];
      fl3 = p->flags;
      k3 = 0x10;
      kk3 = k3;
      kk3 &= fl3;
      if (kk3 != 0) {
        k3 |= pal3;
      } else {
        k3 = pal3;
      }
      ((struct VFX* (*)())CreateSlashedEnemy)(cp2, t2, 0, k3);
    }
    {
      register struct Coord* cp3 asm("r5");
      const struct SlashedEnemy* t3;
      register s32 pal4 asm("r2");
      register s32 k4 asm("r3");
      register s32 kk4 asm("r0");
      register u8 fl4 asm("r1");
      cp3 = &c;
      t3 = &sSlashedEnemies[1];
      pal4 = b4[8];
      fl4 = p->flags;
      k4 = 0x10;
      kk4 = k4;
      kk4 &= fl4;
      if (kk4 != 0) {
        k4 |= pal4;
      } else {
        k4 = pal4;
      }
      ((struct VFX* (*)())CreateSlashedEnemy)(cp3, t3, 0, k4);
    }
  }
  PlaySound(0x2A);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_0806d618(GyroCannon* p) {
  register GyroCannon* pp asm("r4");
  register s32 m asm("r5");
  s32 v;
  s32 y;
  pp = p;
  m = pp->mode[2];
  if (m == 0) {
    SetMotion((struct Entity*)p, MOTION(0x17, 0x00));
    pp->d.y = m;
    pp->mode[2]++;
  }
  v = pp->d.y + 0x40;
  pp->d.y = v;
  if (v > 0x700) {
    pp->d.y = 0x700;
  }
  y = pp->coord.y + pp->d.y;
  pp->coord.y = y;
  if ((u16)FUN_080098a4(pp->coord.x, y + 0xA00) != 0) {
    s32 z;
    pp->coord.y = FUN_08009f6c(pp->coord.x, pp->coord.y) - 0xA00;
    z = 0;
    pp->mode[1] = 7;
    pp->mode[2] = z;
    {
      register u8* pr asm("r1");
      register s32 one asm("r0");
      pr = (u8*)&pp->props;
      asm("" : "+r"(pr));
      one = 1;
      pr[11] = one;
    }
    asm volatile("" ::"r"(pp));
  }
}

void FUN_0806d684(GyroCannon* p) {
  if (p->mode[2] == 0) {
    register struct Zero** zp asm("r4");
    register s32 dist asm("r6");
    s32 dx, dy;
    SetMotion((struct Entity*)p, MOTION(0x17, 0x00));
    zp = &pZero2;
    {
      register struct Zero* z asm("r2");
      z = *zp;
      dx = p->coord.x - (z->s).coord.x;
      p->d.x = dx;
      dy = p->coord.y - (z->s).coord.y;
      dy += -0x1800;
      p->d.y = dy;
    }
    {
      register s32 a asm("r1");
      register s32 t1 asm("r6");
      register s32 b asm("r0");
      register s32 t2 asm("r1");
      a = dx >> 8;
      asm volatile("add %0, %1, #0" : "=&l"(t1) : "l"(a));
      t1 *= a;
      b = dy >> 8;
      asm volatile("add %0, %1, #0" : "=&l"(t2) : "l"(b));
      t2 *= b;
      asm volatile("add %0, %1, #0" : "=&l"(b) : "l"(t2));
      dist = t1 + b;
    }
    {
      register s32 sq asm("r0");
      sq = ((s32(*)(u32))Sqrt)(dist);
      sq <<= 16;
      dist = (s32)(((u32)sq) >> 16);
    }
    if (dist == 0) {
      goto zerodist;
    }
    {
      register s32 nx asm("r4");
      register s32 ny asm("r0");
      nx = p->d.x / dist;
      p->d.x = nx;
      ny = p->d.y / dist;
      {
        register s32 q asm("r1");
        q = (nx * 2 + nx) * 2;
        p->d.x = q;
        q = (ny * 2 + ny) * 2;
        p->d.y = q;
      }
    }
    goto haddir;
  zerodist : {
    register s32 v asm("r0");
    if (((*zp)->s.flags & 0x10) == 0) {
      goto negv;
    }
    v = 0xC0 * 8;
    goto stdx;
  negv:
    v = -0x600;
  stdx:
    p->d.x = v;
    p->d.y = 0;
  }
  haddir:;
    if (p->d.x <= 0) {
      goto flipon;
    }
    {
      register s32 zz asm("r2");
      u8* oa;
      s32 m11, ov;
      zz = 0;
      {
        register u8 h asm("r1");
        register u8 g asm("r0");
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xEF;
        g &= h;
        p->flags = g;
      }
      *((u8*)p + 0x4c) = zz;
      oa = (u8*)p + 0x4a;
      ov = *oa;
      m11 = -0x11;
      m11 &= ov;
      *oa = m11;
      goto flipdone;
    }
  flipon : {
      register s32 one asm("r2");
      register u8* oa2 asm("r3");
      s32 sh4, ov2, m112;
      one = 1;
      {
        register u8 fl asm("r1");
        register s32 fv asm("r0");
        fl = p->flags;
        fv = 0x10;
        fv |= fl;
        p->flags = fv;
      }
      *((u8*)p + 0x4c) = one;
      oa2 = (u8*)p + 0x4a;
      one = 0x10;
      ov2 = *oa2;
      m112 = -0x11;
      m112 &= ov2;
      m112 |= one;
      *oa2 = m112;
    }
  flipdone:
    {
      register u8* a2 asm("r1");
      register s32 v2 asm("r0");
      a2 = (u8*)p + 0xb4;
      v2 = 1;
      a2[0xa] = v2;
    }
    SetDDP(&p->body, &sCollisions[4]);
    p->mode[2]++;
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    register s32 cx asm("r0");
    register s32 dxv asm("r3");
    register s32 cy asm("r1");
    register s32 dyv asm("r2");
    cx = p->coord.x;
    dxv = p->d.x;
    cx += dxv;
    p->coord.x = cx;
    cy = p->coord.y;
    dyv = p->d.y;
    cy += dyv;
    p->coord.y = cy;
    dyv += 0x40;
    p->d.y = dyv;
    cx += dxv;
    if (((u16)FUN_080098a4(cx, cy) << 16) != 0) {
      goto die;
    }
  }
  {
    register s32 bx asm("r0");
    register s32 by asm("r1");
    register s32 k2 asm("r2");
    {
      register s32 t asm("r1");
      bx = p->coord.x;
      t = p->d.x;
      bx += t;
    }
    by = p->coord.y;
    k2 = -0x1800;
    by += k2;
    if (((u16)FUN_080098a4(bx, by) << 16) == 0) {
      return;
    }
  }
die:
  SET_ENEMY_ROUTINE(p, ENTITY_DIE);
  GyroCannon_Die(p);
}

void FUN_0806d7e0(GyroCannon* p) {
  s32 onR;
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, 0x1700);
    p->work[2] = 0x78;
    p->mode[2]++;
  }
  onR = 0;
  if (p->coord.x < (pZero2->s).coord.x) {
    onR = 1;
  }
  if (onR != 0) {
    p->flags |= 0x10;
  } else {
    p->flags &= 0xEF;
  }
  {
    register s32 xfc asm("r1");
    xfc = onR;
    asm("" : "+r"(xfc));
    (p->spr).xflip = xfc;
  {
    u8* oa = (u8*)p + 0x4a;
    s32 sh = xfc << 4;
    s32 ov = *oa;
    s32 m11 = -0x11;
    m11 &= ov;
    *oa = m11 | sh;
  }
  }
  {
    s32* bp = (s32*)((u8*)p + 0xb4);
    p->coord.y = bp[1] + (gSineTable[p->work[3]] << 5);
  }
  p->work[3]++;
  {
    s32 raw = p->work[2] - 1;
    p->work[2] = raw;
    if ((u8)raw == 0xFF) {
      register u8 nm asm("r0");
      u32 rv = RANDOM(RNG_0202f388) & 0xF;
      asm("" : "+r"(rv));
      if (rv <= 9) {
        nm = 3;
        asm("" : "+r"(nm));
        goto setm;
      }
      nm = 5;
      asm("" : "+r"(nm));
    setm:
      p->mode[1] = nm;
      {
        register u8 zz asm("r0");
        zz = 0;
        p->mode[2] = zz;
      }
    }
  }
}

void FUN_0806d8b0(GyroCannon* p) {
  struct Coord c;
  register struct Entity* q asm("r4");
  if (p->mode[2] == 0) {
    register s32 sp asm("r4");
    SetMotion((struct Entity*)p, MOTION(0x17, 0x03));
    c.y = p->coord.y + 0x800;
    if (p->flags & X_FLIP) {
      c.x = p->coord.x + 0x1000;
      sp = 0x180;
      CreateLemon(&c, sp, 0x90);
      c.y = p->coord.y - 0x500;
      CreateLemon(&c, sp, 0x70);
    } else {
      c.x = p->coord.x - 0x1000;
      sp = 0x180;
      CreateLemon(&c, sp, 0xEF);
      c.y = p->coord.y - 0x500;
      CreateLemon(&c, sp, 0x10);
    }
    PlaySound(0x2C);
    p->work[2] = 0x30;
    p->mode[2]++;
  }
  q = p->unk_2c;
  if (q == NULL) {
    if (((bool16 (*)(s32, s32))FUN_080098a4)(p->coord.x, p->coord.y + 0xA00)) {
      p->mode[1] = (u8)(u32)q;
      p->mode[2] = (u8)(u32)q;
      return;
    }
  }
  {
    s32 t = p->work[2] - 1;
    p->work[2] = t;
    t <<= 24;
    t = (u32)t >> 24;
    if (t == 0xFF) {
      register struct Entity* r asm("r1");
      r = p->unk_2c;
      if (r != NULL) {
        p->mode[1] = 4;
        p->mode[2] = 0;
        return;
      }
      p->mode[1] = 7;
      p->mode[2] = (u8)(u32)r;
    }
  }
}

void FUN_0806d998(GyroCannon* p) {
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, 0x1700);
    p->work[2] = 8;
    p->mode[2]++;
  }
  if ((u8)(--p->work[2]) == 0xff) {
    p->mode[1] = 2;
    p->mode[2] = 0;
  }
}

void FUN_0806d9d4(GyroCannon* p) {
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, 0x1704);
    p->work[2] = 8;
    p->mode[2]++;
  }
  if ((u8)(--p->work[2]) == 0xff) {
    CreateProjectile8(p->coord.x, p->coord.y + 0xc00);
    p->mode[1] = 6;
    p->mode[2] = 0;
  }
}

void FUN_0806da20(GyroCannon* p) {
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, 0x1705);
    p->work[2] = 8;
    p->mode[2]++;
  }
  if ((u8)(--p->work[2]) == 0xff) {
    p->mode[1] = 2;
    p->mode[2] = 0;
  }
}

void FUN_0806da5c(GyroCannon* p) {
  u8 z;
  if (p->mode[2] == 0) {
    SetMotion((struct Entity*)p, MOTION(0x17, 0x00));
    p->work[2] = 0x78;
    p->mode[2]++;
  }
  {
    register u8* q asm("r1");
    q = (u8*)p + 0xb4;
    asm("" : "+r"(q));
    z = 0;
    q[0xb] = 1;
  }
  if (FUN_080098a4(p->coord.x, p->coord.y + 0xB00) == 0) {
    p->mode[1] = z;
  } else {
    if ((u8)--p->work[2] != 0xFF) {
      return;
    }
    p->mode[1] = 3;
  }
  p->mode[2] = z;
}

void FUN_0806dab8(GyroCannon* p) {
  struct Entity** slot;
  u8 m = p->mode[2];
  if (m == 0) {
    SetMotion((struct Entity*)p, MOTION(0x17, 0x00));
    SetDDP(&p->body, &sCollisions[1]);
    p->d.y = m;
    p->mode[2]++;
  }
  p->d.y += 0x40;
  if (p->d.y > 0x700) {
    p->d.y = 0x700;
  }
  p->coord.y += p->d.y;
  if (FUN_080098a4(p->coord.x, p->coord.y + 0xA00)) {
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y) - 0xA00;
  }
  slot = (struct Entity**)((u8*)p + 0xb4);
  if (isKilled(*slot)) {
    u32 z = 0;
    *slot = (struct Entity*)z;
    SetDDP(&p->body, &sCollisions[0]);
    if (p->unk_2c != NULL) {
      p->mode[1] = 9;
      p->mode[2] = z;
    } else {
      p->mode[1] = 0;
      p->mode[2] = 1;
    }
  }
}

void FUN_0806db58(GyroCannon* p) {
  UpdateEntityAnim((struct Entity*)p);
  p->coord.y -= 0x200;
  {
    s32* base = (s32*)((u8*)p + 0xb4);
    if (p->coord.y < base[1]) {
      p->coord.y = base[1];
      p->mode[1] = 2;
      p->mode[2] = 0;
      p->work[3] = 0x7f;
    }
  }
}

void gyroCannon_0806db8c(GyroCannon* p) {
  register u32 a3 asm("r3");
  register struct Coord* c5 asm("r5");
  register u8* pr8 asm("r8");
  c5 = &p->coord;
  {
    register const struct SlashedEnemy* s6 asm("r6");
    register s32 pv asm("r2");
    s6 = &sSlashedEnemies[2];
    {
      register u8* pt asm("r0");
      pt = (u8*)p + 0xb4;
      pv = pt[8];
    }
    {
      register u8 fl asm("r1");
      register u32 t0 asm("r0");
      fl = p->flags;
      a3 = 0x10;
      t0 = a3;
      t0 &= fl;
      if (t0 != 0) {
        a3 |= pv;
      } else {
        a3 = pv;
      }
    }
    ((struct VFX* (*)())CreateSlashedEnemy)(c5, s6, 0, a3);
  }
  {
    struct Coord* c7;
    register const struct SlashedEnemy* sip asm("ip");
    register u8* pr2 asm("r2");
    register s32 pv6 asm("r6");
    c7 = &p->coord;
    asm("" : "+r"(c7));
    sip = &sSlashedEnemies[2];
    pr2 = (u8*)p + 0xb4;
    pv6 = pr2[8];
    {
      register u8 fl asm("r1");
      register u32 t0 asm("r0");
      fl = p->flags;
      a3 = 0x10;
      t0 = a3;
      t0 &= fl;
      c5 = c7;
      pr8 = pr2;
      if (t0 != 0) {
        a3 |= pv6;
      } else {
        a3 = pv6;
      }
    }
    ((struct VFX* (*)())CreateSlashedEnemy)(c7, sip, 0, a3);
  }
  {
    register struct Coord* c6 asm("r6");
    const struct SlashedEnemy* s7;
    u8 p2;
    c6 = c5;
    s7 = &sSlashedEnemies[3];
    {
      register u8* pl asm("r0");
      pl = pr8;
      p2 = pl[8];
    }
    {
      register u8 fl asm("r1");
      register u32 t0 asm("r0");
      fl = p->flags;
      a3 = 0x10;
      t0 = a3;
      t0 &= fl;
      if (t0 != 0) {
        a3 |= p2;
      } else {
        a3 = p2;
      }
    }
    ((struct VFX* (*)())CreateSlashedEnemy)(c6, s7, 0, a3);
  }
  {
    register struct Coord* c6 asm("r6");
    const struct SlashedEnemy* s7;
    u8 p2;
    c6 = c5;
    s7 = &sSlashedEnemies[3];
    {
      register u8* pl asm("r0");
      pl = pr8;
      p2 = pl[8];
    }
    {
      register u8 fl asm("r1");
      register u32 t0 asm("r0");
      fl = p->flags;
      a3 = 0x10;
      t0 = a3;
      t0 &= fl;
      if (t0 != 0) {
        a3 |= p2;
      } else {
        a3 = p2;
      }
    }
    ((struct VFX* (*)())CreateSlashedEnemy)(c6, s7, 0, a3);
  }
  CreateSmoke(1, c5);
  if (p->flags & 0x10) {
    CreateSmoke(2, c5);
    CreateSmoke(2, c5);
  } else {
    CreateSmoke(2, c5);
    CreateSmoke(2, c5);
  }
  {
    register s32 cf asm("r0");
    register s32 flv asm("r1");
    flv = p->flags;
    cf = 0xFE;
    asm("" : "+r"(cf));
    p->flags = cf & flv;
  }
  PlaySound(0x2A);
  {
    register struct Coord* c1 asm("r1");
    c1 = c5;
    TryDropItem(4, c1);
  }
  if (gScore.enemyCount <= 0x270E) {
    gScore.enemyCount++;
  }
  TryDropZakoDisk((struct Entity*)p, c5);
  SET_ENEMY_ROUTINE(p, 4);
}

void gyroCannon_0806dccc(GyroCannon* p) {
  if (p->mode[3] == 0) {
    SetMotion((struct Entity*)p, 0x1707);
    {
      struct Coord* ca;
      u32 xf;
      u32 one;
      ca = &p->coord;
      xf = p->flags >> 4;
      one = 1;
      xf &= one;
      CreateGhost27(ca, xf, one);
    }
    {
      struct Entity* e = p->unk_2c;
      s32 y = e->coord.y;
      s32 x = e->coord.x;
      p->coord.x = x;
      p->coord.y = y;
    }
    p->mode[3]++;
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    struct Entity* e = p->unk_2c;
    if (e != NULL) {
      if (e->mode[0] > 1) {
        p->unk_2c = NULL;
      } else {
        p->coord.y = e->coord.y + -0x200;
      }
      if (p->unk_2c != NULL) {
        return;
      }
    }
  }
  {
    struct Coord* c7;
    register const struct SlashedEnemy* sip asm("ip");
    register u8* pr2 asm("r2");
    register u8* pr8 asm("r8");
    u8 p5;
    register struct Coord* c6 asm("r6");
    register u32 a3 asm("r3");
    c7 = &p->coord;
    sip = &sSlashedEnemies[2];
    pr2 = (u8*)p + 0xb4;
    p5 = pr2[8];
    {
      register u8 fl asm("r1");
      register u32 t0 asm("r0");
      fl = p->flags;
      a3 = 0x10;
      t0 = a3;
      t0 &= fl;
      c6 = c7;
      pr8 = pr2;
      if (t0 != 0) {
        a3 |= p5;
      } else {
        a3 = p5;
      }
    }
    ((struct VFX* (*)())CreateSlashedEnemy)(c7, sip, 0, a3);
    {
      register struct Coord* c5 asm("r5");
      const struct SlashedEnemy* s7;
      u8 p2;
      c5 = c6;
      s7 = &sSlashedEnemies[3];
      {
        register u8* pl asm("r1");
        pl = pr8;
        p2 = pl[8];
      }
      {
        register u8 fl asm("r1");
        register u32 t0 asm("r0");
        fl = p->flags;
        a3 = 0x10;
        t0 = a3;
        t0 &= fl;
        if (t0 != 0) {
          a3 |= p2;
        } else {
          a3 = p2;
        }
      }
      ((struct VFX* (*)())CreateSlashedEnemy)(c5, s7, 0, a3);
    }
    CreateSmoke(1, c6);
    if (p->flags & 0x10) {
      CreateSmoke(2, c6);
    } else {
      CreateSmoke(2, c6);
    }
    {
      register struct Coord* c1 asm("r1");
      c1 = c6;
      TryDropItem(4, c1);
    }
    PlaySound(0x2A);
    if (gScore.enemyCount <= 0x270E) {
      gScore.enemyCount++;
    }
    TryDropZakoDisk((struct Entity*)p, c6);
    SET_ENEMY_ROUTINE(p, 4);
  }

}

NAKED static void FUN_0806ddfc(GyroCannon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _0806DE2E\n\
	ldr r1, _0806DE64 @ =0x00001708\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r1, [r4, #0xa]\n\
	lsrs r1, r1, #4\n\
	movs r2, #1\n\
	ands r1, r2\n\
	movs r2, #0\n\
	bl CreateGhost27\n\
	movs r0, #0x30\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
_0806DE2E:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0806DEFA\n\
	adds r7, r4, #0\n\
	adds r7, #0x54\n\
	ldr r0, _0806DE68 @ =0x08366758\n\
	mov ip, r0\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r5, [r2, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	adds r6, r7, #0\n\
	mov r8, r2\n\
	cmp r0, #0\n\
	beq _0806DE6C\n\
	orrs r3, r5\n\
	b _0806DE6E\n\
	.align 2, 0\n\
_0806DE64: .4byte 0x00001708\n\
_0806DE68: .4byte sSlashedEnemies +(28*2)\n\
_0806DE6C:\n\
	adds r3, r5, #0\n\
_0806DE6E:\n\
	adds r0, r7, #0\n\
	mov r1, ip\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	adds r5, r6, #0\n\
	ldr r7, _0806DE90 @ =0x08366774\n\
	mov r0, r8\n\
	ldrb r2, [r0, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DE94\n\
	orrs r3, r2\n\
	b _0806DE96\n\
	.align 2, 0\n\
_0806DE90: .4byte sSlashedEnemies +(28*3)\n\
_0806DE94:\n\
	adds r3, r2, #0\n\
_0806DE96:\n\
	adds r0, r5, #0\n\
	adds r1, r7, #0\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	movs r0, #1\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DEBC\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	b _0806DEC4\n\
_0806DEBC:\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
_0806DEC4:\n\
	adds r1, r6, #0\n\
	movs r0, #4\n\
	bl TryDropItem\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _0806DF04 @ =gScore\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _0806DF08 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _0806DEE0\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_0806DEE0:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl TryDropZakoDisk\n\
	ldr r1, _0806DF0C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r4, #0x14]\n\
_0806DEFA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806DF04: .4byte gScore\n\
_0806DF08: .4byte 0x0000270E\n\
_0806DF0C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// 0x0806df10
static void GyroCannon_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    Entity* q = (Entity*)body->enemy->parent;
    GyroCannon* p = (GyroCannon*)body->parent;
    (&p->props)->is_right = (q->coord).x > (p->coord).x;
  }
}

void FUN_0806d618(GyroCannon* p);
void FUN_0806d684(GyroCannon* p);
void FUN_0806d7e0(GyroCannon* p);
void FUN_0806d8b0(GyroCannon* p);
void FUN_0806d998(GyroCannon* p);
void FUN_0806d9d4(GyroCannon* p);
void FUN_0806da20(GyroCannon* p);
void FUN_0806da5c(GyroCannon* p);
void FUN_0806dab8(GyroCannon* p);
void FUN_0806db58(GyroCannon* p);

// clang-format off
static void (*const PTR_ARRAY_0836666c[10])(GyroCannon*) = {
    FUN_0806d618,
    FUN_0806d684,
    FUN_0806d7e0,
    FUN_0806d8b0,
    FUN_0806d998,
    FUN_0806d9d4,
    FUN_0806da20,
    FUN_0806da5c,
    FUN_0806dab8,
    FUN_0806db58,
};
// clang-format on

void gyroCannon_0806db8c(GyroCannon* p);
void gyroCannon_0806dccc(GyroCannon* p);
NAKED static void FUN_0806ddfc(GyroCannon* p);

static void (*const sUpdates2[3])(GyroCannon*) = {
    gyroCannon_0806db8c,
    gyroCannon_0806dccc,
    FUN_0806ddfc,
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};

// 0x083666a8
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
};

// 0x08366720
static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : 0x170B,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170C,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170D,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170E,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
};
