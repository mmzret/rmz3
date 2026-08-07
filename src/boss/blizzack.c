#include "boss.h"
#include "collision.h"
#include "global.h"
#include "element.h"
#include "script.h"
#include "score.h"
#include "stagerun.h"
#include "zero.h"

void FUN_0805af14(struct Boss* p);
void CreateVFX57(struct Coord* c, u8 a1, u8 a2, s16 dx, s16 dy);
void FUN_080aabd4(struct Boss* p);
struct Entity* CreateEnemy42(struct Entity* e, u8 type, u8 param_3);
void FUN_080aac28(struct Entity* e);
void blizzack_080aaae0(struct Entity* e, u8 n);
Entity* CreateProjectile31(Entity* q, u8 kind1, u8 kind2);
void FUN_080b2b40(u8 kind, struct Coord* c, s32 v, u8 n);
struct Entity* CreateBossExplosion(struct Entity* boss, struct Coord* c);
struct Entity* CreateBossExplosion(struct Entity* boss, struct Coord* c);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[48];         // 0xB4
} Blizzack;
static_assert(sizeof(Blizzack) == sizeof(Boss));

NAKED void Blizzack_Init(Blizzack* p);
void Blizzack_Update(Blizzack* p);
void Blizzack_Die(Blizzack* p);

// clang-format off
const BossRoutine gBlizzackRoutine = {
    [ENTITY_INIT] =      (void*)Blizzack_Init,
    [ENTITY_UPDATE] =    (void*)Blizzack_Update,
    [ENTITY_DIE] =       (void*)Blizzack_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const struct Collision sCollisions[4];
static void (*const sDeads[3])(Blizzack*);
static const Coords32 sElementCoord;
static void (*const sUpdates[21])(Blizzack*);
void CreateBlizzack(Coords32* c) {
  Blizzack* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_BLIZZACK);
    p->coord = *c;
    p->work[0] = 0, p->work[1] = 0;
  }
}

// --------------------------------------------

NAKED void Blizzack_Init(Blizzack* p) {
  asm(".syntax unified\
\n	push {r4, r5, r6, r7, lr}\
\n	mov r7, sl\
\n	mov r6, sb\
\n	mov r5, r8\
\n	push {r5, r6, r7}\
\n	adds r7, r0, #0\
\n	ldr r1, _08059C94 @ =gBossFnTable\
\n	ldrb r0, [r7, #9]\
\n	lsls r0, r0, #2\
\n	adds r0, r0, r1\
\n	movs r1, #1\
\n	str r1, [r7, #0xc]\
\n	ldr r0, [r0]\
\n	ldr r0, [r0, #4]\
\n	str r0, [r7, #0x14]\
\n	movs r4, #0xfa\
\n	lsls r4, r4, #3\
\n	ldr r5, _08059C98 @ =gStaticMotionGraphics\
\n	adds r0, r4, r5\
\n	ldr r2, _08059C9C @ =wStaticGraphicTilenums\
\n	mov sb, r2\
\n	mov r1, sb\
\n	adds r1, #0xc8\
\n	ldrh r1, [r1]\
\n	ldrh r2, [r0, #6]\
\n	lsrs r2, r2, #6\
\n	subs r1, r1, r2\
\n	lsls r1, r1, #5\
\n	movs r6, #0x80\
\n	lsls r6, r6, #9\
\n	adds r1, r1, r6\
\n	bl LoadGraphic\
\n	ldr r0, _08059CA0 @ =gStaticMotionGraphics+12\
\n	mov r8, r0\
\n	add r4, r8\
\n	ldr r1, _08059CA4 @ =wStaticMotionPalIDs\
\n	mov sl, r1\
\n	mov r0, sl\
\n	adds r0, #0xc8\
\n	ldrh r1, [r0]\
\n	ldrb r0, [r4, #7]\
\n	subs r1, r1, r0\
\n	lsls r1, r1, #5\
\n	movs r2, #0x80\
\n	lsls r2, r2, #2\
\n	adds r1, r1, r2\
\n	adds r0, r4, #0\
\n	bl LoadPalette\
\n	movs r4, #0xf5\
\n	lsls r4, r4, #3\
\n	adds r0, r4, r5\
\n	mov r1, sb\
\n	adds r1, #0xc4\
\n	ldrh r1, [r1]\
\n	ldrh r2, [r0, #6]\
\n	lsrs r2, r2, #6\
\n	subs r1, r1, r2\
\n	lsls r1, r1, #5\
\n	adds r1, r1, r6\
\n	bl LoadGraphic\
\n	add r4, r8\
\n	mov r0, sl\
\n	adds r0, #0xc4\
\n	ldrh r1, [r0]\
\n	ldrb r0, [r4, #7]\
\n	subs r1, r1, r0\
\n	lsls r1, r1, #5\
\n	movs r0, #0x80\
\n	lsls r0, r0, #2\
\n	adds r1, r1, r0\
\n	adds r0, r4, #0\
\n	bl LoadPalette\
\n	ldr r4, _08059CA8 @ =0x000007BC\
\n	adds r5, r4, r5\
\n	mov r0, sb\
\n	adds r0, #0xc6\
\n	ldrh r1, [r0]\
\n	ldrh r0, [r5, #6]\
\n	lsrs r0, r0, #6\
\n	subs r1, r1, r0\
\n	lsls r1, r1, #5\
\n	adds r1, r1, r6\
\n	adds r0, r5, #0\
\n	bl LoadGraphic\
\n	add r4, r8\
\n	mov r0, sl\
\n	adds r0, #0xc6\
\n	ldrh r1, [r0]\
\n	ldrb r0, [r4, #7]\
\n	subs r1, r1, r0\
\n	lsls r1, r1, #5\
\n	movs r2, #0x80\
\n	lsls r2, r2, #2\
\n	adds r1, r1, r2\
\n	adds r0, r4, #0\
\n	bl LoadPalette\
\n	adds r0, r7, #0\
\n	bl InitNonAffineMotion\
\n	adds r0, r7, #0\
\n	bl ResetDynamicMotion\
\n	ldrb r1, [r7, #0xa]\
\n	movs r0, #1\
\n	movs r2, #0\
\n	mov r8, r2\
\n	orrs r0, r1\
\n	movs r1, #2\
\n	orrs r0, r1\
\n	strb r0, [r7, #0xa]\
\n	movs r1, #0xb4\
\n	lsls r1, r1, #8\
\n	adds r0, r7, #0\
\n	bl SetMotion\
\n	adds r0, r7, #0\
\n	adds r0, #0x4c\
\n	mov r1, r8\
\n	strb r1, [r0]\
\n	adds r2, r7, #0\
\n	adds r2, #0x4a\
\n	ldrb r1, [r2]\
\n	movs r0, #0x11\
\n	rsbs r0, r0, #0\
\n	ands r0, r1\
\n	strb r0, [r2]\
\n	ldrb r1, [r7, #0xa]\
\n	movs r0, #0xef\
\n	ands r0, r1\
\n	strb r0, [r7, #0xa]\
\n	adds r1, r7, #0\
\n	adds r1, #0xd0\
\n	movs r0, #0x40\
\n	strb r0, [r1]\
\n	ldr r1, _08059CAC @ =sCollisions\
\n	adds r0, r7, #0\
\n	movs r2, #0x40\
\n	bl ResetBossBody\
\n	adds r2, r7, #0\
\n	adds r2, #0x49\
\n	ldrb r1, [r2]\
\n	movs r0, #0xd\
\n	rsbs r0, r0, #0\
\n	ands r0, r1\
\n	movs r1, #8\
\n	orrs r0, r1\
\n	strb r0, [r2]\
\n	ldr r0, [r7, #0x54]\
\n	ldr r1, [r7, #0x58]\
\n	bl FUN_0800a134\
\n	adds r1, r0, #0\
\n	adds r4, r7, #0\
\n	adds r4, #0xb8\
\n	str r1, [r4]\
\n	ldr r0, [r7, #0x54]\
\n	bl FUN_0800a31c\
\n	adds r5, r7, #0\
\n	adds r5, #0xb4\
\n	str r0, [r5]\
\n	ldr r0, [r7, #0x54]\
\n	ldr r1, [r4]\
\n	bl FUN_0800a22c\
\n	adds r1, r7, #0\
\n	adds r1, #0xd8\
\n	str r0, [r1]\
\n	adds r3, r7, #0\
\n	adds r3, #0xdc\
\n	ldr r2, [r5]\
\n	subs r0, r0, r2\
\n	lsrs r1, r0, #0x1f\
\n	adds r0, r0, r1\
\n	asrs r0, r0, #1\
\n	adds r2, r2, r0\
\n	str r2, [r3]\
\n	ldr r0, [r7, #0x54]\
\n	ldr r1, [r7, #0x58]\
\n	bl FUN_08009f6c\
\n	adds r1, r7, #0\
\n	adds r1, #0xbc\
\n	str r0, [r1]\
\n	str r0, [r7, #0x58]\
\n	adds r1, #4\
\n	ldr r0, [r7, #0x54]\
\n	str r0, [r1]\
\n	adds r0, r7, #0\
\n	adds r0, #0xc5\
\n	mov r2, r8\
\n	strb r2, [r0]\
\n	adds r0, #1\
\n	strb r2, [r0]\
\n	adds r0, #1\
\n	strb r2, [r0]\
\n	adds r1, #8\
\n	ldr r0, _08059CB0 @ =0x0000FFFF\
\n	strh r0, [r1]\
\n	adds r0, r7, #0\
\n	movs r1, #0\
\n	movs r2, #0\
\n	bl CreateEnemy42\
\n	str r0, [r7, #0x2c]\
\n	movs r1, #1\
\n	strb r1, [r0, #0xe]\
\n	ldr r0, [r7, #0x2c]\
\n	adds r0, #0xbc\
\n	movs r2, #0\
\n	movs r1, #0xc8\
\n	lsls r1, r1, #7\
\n	strh r1, [r0]\
\n	adds r1, r7, #0\
\n	adds r1, #0xcc\
\n	movs r0, #3\
\n	strb r0, [r1]\
\n	adds r1, #1\
\n	strb r0, [r1]\
\n	adds r1, #1\
\n	strb r0, [r1]\
\n	adds r0, r7, #0\
\n	adds r0, #0xd4\
\n	mov r1, r8\
\n	str r1, [r0]\
\n	adds r0, #0xc\
\n	strb r2, [r0]\
\n	strb r2, [r7, #0xd]\
\n	movs r2, #1\
\n	strb r2, [r7, #0xe]\
\n	adds r0, r7, #0\
\n	bl Blizzack_Update\
\n	pop {r3, r4, r5}\
\n	mov r8, r3\
\n	mov sb, r4\
\n	mov sl, r5\
\n	pop {r4, r5, r6, r7}\
\n	pop {r0}\
\n	bx r0\
\n	.align 2, 0\
\n_08059C94: .4byte gBossFnTable\
\n_08059C98: .4byte gStaticMotionGraphics\
\n_08059C9C: .4byte wStaticGraphicTilenums\
\n_08059CA0: .4byte gStaticMotionGraphics+12\
\n_08059CA4: .4byte wStaticMotionPalIDs\
\n_08059CA8: .4byte 0x000007BC\
\n_08059CAC: .4byte sCollisions\
\n_08059CB0: .4byte 0x0000FFFF\
\n .syntax divided\
");
}

void Blizzack_Update(Blizzack* p) {
  if ((*(u32*)((u8*)p + 0x8c) & 0x200) != 0 || *(s16*)((u8*)p + 0xa4) == 0) {
    u16 ms = gStageRun.missionStatus & 8;
    if (ms == 0) {
      SET_BOSS_ROUTINE(p, 2);
      p->mode[1] = ms;
      Blizzack_Die(p);
      return;
    }
  }
  FUN_0805af14((struct Boss*)p);
  {
    u32* st = (u32*)((u8*)p + 0x8c);
    s32 one;
    s32 v = *st;
    one = 1;
    asm("" : "+r"(one));
    if ((v & one) != 0) {
      s32 f = 0;
      s32* el;
      if (p->coord.x < (pZero2->s).coord.x) {
        f = 1;
      }
      *((u8*)p + 0xc4) = f;
      el = (s32*)((u8*)p + 0xd4);
      if (*el == 0) {
        *el = (s32)ApplyElementEffect(0x1A, (struct CollisionObject*)p, &sElementCoord);
      }
      if (isKilled((struct Entity*)*el)) {
        *el = 0;
      }
      if ((*((u8*)p + 0x97) & 0xF0) == 0x20) {
        *((u8*)p + 0xe0) = 0x80;
      }
      if ((*st & 0x20000) != 0) {
        p->mode[1] = 0x13;
        p->mode[2] = one;
      }
    }
  }
  (sUpdates[p->mode[1]])(p);
}

void Blizzack_Die(Blizzack* p) {
  (sDeads[p->mode[1]])(p);
}

void blizzackMode0(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6400;
    *t = v;
    p->mode[2] = z;
    p->work[2] = z;
  }
  UpdateEntityAnim((struct Entity*)p);
  if (((struct Entity*)p->scriptEntity)->id & 1) {
    p->mode[1] = 1;
    p->mode[2] = 1;
  }
}

void blizzackMode1(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x01));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6401;
    *t = v;
    p->mode[2] = z;
    PlaySound(0x42);
  }
  UpdateEntityAnim((struct Entity*)p);
  if (*(u8*)((u8*)p + 0x73) == 3 && (gStageRun.vm.active & 1) == 0) {
    p->mode[1] = 2;
    p->mode[2] = 1;
  }
}

INCASM("asm/boss/blizzack_a.inc");

void blizzackPreAI(Blizzack* p) {
  struct Zero* z;
  u8 f;
  if (p->mode[2] != 0) {
    register u8 zz asm("r2");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x00));
    (p->unk_2c)->mode[2] = 1;
    {
      register u16* h asm("r0");
      register s32 hv asm("r1");
      h = (u16*)((u8*)p->unk_2c + 0xbc);
      zz = 0;
      asm("" : "+r"(zz));
      hv = 0x6400;
      *h = hv;
    }
    p->mode[2] = zz;
    p->work[2] = 0x20;
  }
  UpdateEntityAnim((struct Entity*)p);
  f = 0;
  z = pZero2;
  if ((z->s).coord.x > p->coord.x) {
    f = 1;
  }
  (p->spr).xflip = f;
  f = 0;
  if ((z->s).coord.x > p->coord.x) {
    f = 1;
  }
  {
    register u8* oa asm("ip");
    u32 sh4;
    s32 ov;
    s32 m11;
    oa = (u8*)p + 0x4a;
    sh4 = f << 4;
    ov = *oa;
    m11 = -0x11;
    m11 &= ov;
    m11 |= sh4;
    *oa = m11;
  }
  if (f != 0) {
    p->flags |= 0x10;
  } else {
    p->flags &= 0xEF;
  }
  if ((u8)--p->work[2] == 0xFF) {
    p->mode[1] = 2;
    p->mode[2] = 1;
  }
}

void blizzackNextMode(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x02));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6402;
    *t = v;
    p->mode[2] = z;
    PlaySound(0x42);
  }
  UpdateEntityAnim((struct Entity*)p);
  if (*(u8*)((u8*)p + 0x73) == 3) {
    p->mode[1] = *(u8*)((u8*)p + 0xf);
    p->mode[2] = 1;
  }
}

void blizzackJump(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x03));
    (p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6403;
    *t = v;
    p->mode[2] = z;
    p->d.x = ((pZero2->s).coord.x - p->coord.x) / 52;
    p->d.y = -0x9C0;
  }
  UpdateEntityAnim((struct Entity*)p);
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  p->d.y += 0x60;
  if (p->d.y > 0x700) {
    p->d.y = 0x700;
  }
  if (FUN_08009f6c(p->coord.x, p->coord.y) < p->coord.y) {
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
    p->mode[1] = 6;
    p->mode[2] = 1;
  }
}

void blizzackStamp(Blizzack* p) {
  if (p->mode[2] != 0) {
    struct Entity* q;
    s32 z;
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x04));
    (p->unk_2c)->mode[2] = 1;
    q = p->unk_2c;
    {
      register u16* hp asm("r0");
      register s32 hv asm("r1");
      hp = (u16*)((u8*)q + 0xbc);
      asm("" : "+r"(hp));
      z = 0;
      asm("" : "+r"(z) : "r"(hp));
      hv = 0x6404;
      *hp = hv;
    }
    p->mode[2] = z;
    p->work[2] = z;
    PlaySound(0x91);
    AppendQuake(4, &p->coord);
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    register u8 w asm("r1");
    register s32 nx asm("r0");
    w = p->work[2];
    nx = w + 1;
    asm("" : "+r"(nx));
    p->work[2] = nx;
    if ((w & 7) == 0) {
      struct Coord* c = &p->coord;
      CreateVFX57(c, 0, 1, 0x118, -(p->work[2] << 2) - 0x40);
      CreateVFX57(c, 0, 1, -0x118, -(p->work[2] << 2) - 0x40);
    }
  }
  {
    u8 st = p->motion.state;
    if (st == 3) {
      p->mode[1] = st;
      p->mode[2] = 1;
    }
  }
}

void blizzackMode7(Blizzack* p) {
  if (p->mode[2] != 0) {
    register s32 one asm("r5");
    register s32 v asm("r3");
    register struct Zero* z asm("r2");
    struct Entity* q;
    s32 zz;
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x07));
    q = p->unk_2c;
    one = 1;
    q->mode[2] = one;
    {
      register u16* hp asm("r0");
      register s32 hv asm("r1");
      hp = (u16*)((u8*)(p->unk_2c) + 0xbc);
      asm("" : "+r"(hp));
      zz = 0;
      asm("" : "+r"(zz) : "r"(hp));
      hv = 0x6407;
      *hp = hv;
    }
    p->mode[2] = zz;
    v = 0;
    z = pZero2;
    if ((z->s).coord.x > p->coord.x) {
      v = 1;
    }
    p->spr.xflip = v;
    v = 0;
    if ((z->s).coord.x > p->coord.x) {
      v = 1;
    }
    {
      register u8* oa asm("ip");
      register s32 fv asm("r1");
      u8* oa0;
      u32 k;
      s32 sh4, ov, m11;
      k = 0x4a;
      asm("" : "+r"(k));
      oa0 = (u8*)(k + (u32)p);
      oa = oa0;
      asm volatile("add %0, %1, #0" : "=&l"(fv) : "l"(one));
      fv &= v;
      sh4 = fv << 4;
      ov = *oa0;
      m11 = -0x11;
      m11 &= ov;
      m11 |= sh4;
      *oa = m11;
      if (fv != 0) {
        p->flags |= X_FLIP;
      } else {
        p->flags &= ~X_FLIP;
      }
    }
    SetDDP(&p->body, &sCollisions[2]);
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->motion.state == 3) {
    p->mode[1] = 8;
    p->mode[2] = 1;
  }
}

void blizzackMode8(Blizzack* p) {
  if (p->mode[2] != 0) {
    p->mode[2] = 0;
    p->work[2] = 0xb4;
    FUN_080aabd4((struct Boss*)p);
  }
  UpdateEntityAnim((struct Entity*)p);
  if ((u8)--p->work[2] == 0xff) {
    p->mode[1] = 9;
    p->mode[2] = 1;
  }
}

void blizzackMode9(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x08));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6408;
    *t = v;
    p->mode[2] = z;
    p->work[2] = 8;
    SetDDP(&p->body, sCollisions);
  }
  UpdateEntityAnim((struct Entity*)p);
  if ((u8)--p->work[2] == 0xff) {
    p->mode[1] = 3;
    p->mode[2] = 1;
  }
}

void blizzackStartBlizzard(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x09));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6409;
    *t = v;
    p->mode[2] = z;
    SetDDP(&p->body, &sCollisions[2]);
  }
  UpdateEntityAnim((struct Entity*)p);
  if (*(u8*)((u8*)p + 0x73) == 3) {
    p->mode[1] = 0xb;
    p->mode[2] = 1;
  }
}

void blizzackBlizzard(Blizzack* p) {
  if (p->mode[2] != 0) {
    p->mode[2] = 0;
    p->work[2] = 0xb4;
    FUN_080aac28((struct Entity*)p);
    CreateEnemy42((struct Entity*)p, 1, (p->flags >> 4) & 1);
    *(s16*)((u8*)p + 0xc8) = PlaySound(0x44);
  }
  UpdateEntityAnim((struct Entity*)p);
  if ((u8)--p->work[2] == 0xff) {
    p->mode[1] = 0xc;
    p->mode[2] = 1;
  }
}

void blizzackEndBlizzard(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x08));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6408;
    *t = v;
    p->mode[2] = z;
    p->work[2] = 8;
    StopSound(*(s16*)((u8*)p + 0xc8));
    SetDDP(&p->body, sCollisions);
  }
  UpdateEntityAnim((struct Entity*)p);
  if ((u8)--p->work[2] == 0xff) {
    p->mode[1] = 3;
    p->mode[2] = 1;
  }
}

NON_MATCH void blizzackBombJump(Blizzack* p) {
#if MODERN
  if (p->mode[2] != 0) {
    SetMotion((struct Entity*)p, 0xB403);
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    *(u16*)((u8*)p->unk_2c + 0xbc) = 0x6403;
    p->mode[2] = 0;
    {
      s32 tx = *(s32*)((u8*)p + 0xdc);
      s32 x = p->coord.x;
      s32 d2 = tx - x;
      if (d2 > 0x7800) {
        p->d.x = ((pZero2->s).coord.x - x) / 0x1A;
        p->work[3] = 2;
      } else {
        s32 zx = (pZero2->s).coord.x;
        s32 d3 = zx - x;
        if (d3 > 0x5000) {
          p->d.x = d3 / 0x34;
          p->work[3] = 0;
        } else if (d2 <= 0xA000 && (RANDOM(RNG_0202f388) & 1)) {
          p->d.x = d3 / 0x1A;
          p->work[3] = 2;
        } else {
          p->d.x = (x - zx) / 0x1A;
          p->work[3] = 1;
        }
      }
    }
    p->d.y = -0x9C0;
    p->work[2] = 0x10;
    {
      u32 xf = 0;
      if ((pZero2->s).coord.x > p->coord.x) {
        xf = 1;
      }
      (p->spr).xflip = xf;
      *((u8*)p + 0x4a) = (*((u8*)p + 0x4a) & ~0x11) | (xf << 4);
      if (xf != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
    }
  }
  UpdateEntityAnim((struct Entity*)p);
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  p->d.y += 0x60;
  if (p->d.y > 0x700) {
    p->d.y = 0x700;
  }
  {
    s32 t = p->work[2] - 1;
    p->work[2] = t;
    if ((u8)t == 0xFF) {
      p->mode[1] = 0xE;
      p->mode[2] = 1;
    }
  }
#else
  INCCODE("asm/boss/blizzack_bombjump.inc");
#endif
}

void blizzackBomb(Blizzack* p) {
  if (p->mode[2] != 0) {
    struct Entity* q;
    register u16* h asm("r0");
    register s32 z asm("r2");
    register s32 kv asm("r1");
    SetMotion((struct Entity*)p, 0xB40F);
    q = p->unk_2c;
    q->mode[2] = 1;
    h = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    kv = 0x640E;
    *h = kv;
    p->mode[2] = z;
    p->work[2] = z;
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    register s32 xf asm("r3");
    register struct Zero* z asm("r2");
    xf = 0;
    z = pZero2;
    if ((z->s).coord.x > p->coord.x) {
      xf = 1;
    }
    (p->spr).xflip = xf;
    xf = 0;
    if ((z->s).coord.x > p->coord.x) {
      xf = 1;
    }
    {
      register u8* oa asm("r5");
      s32 sh4, ov, m11;
      oa = (u8*)p + 0x4a;
      sh4 = xf << 4;
      ov = *oa;
      m11 = -0x11;
      m11 &= ov;
      m11 |= sh4;
      *oa = m11;
    }
    if (xf != 0) {
      p->flags |= 0x10;
    } else {
      register u8 h2 asm("r1");
      register u8 g asm("r0");
      h2 = p->flags;
      asm("" : "+r"(h2));
      g = 0xEF;
      g &= h2;
      p->flags = g;
    }
  }
  p->coord.x += p->d.x;
  {
    register s32 cy asm("r0");
    register s32 dy asm("r1");
    cy = p->coord.y;
    dy = p->d.y;
    cy += dy;
    p->coord.y = cy;
    dy += 0x60;
    p->d.y = dy;
    if (dy > 0x700) {
      p->d.y = 0x700;
    }
  }
  {
    s32 w = p->work[2] + 1;
    p->work[2] = w;
    if ((u8)w == 0xE) {
      register s32 a asm("r5");
      register struct Zero* zz asm("r3");
      s32 dx;
      register s32 ty asm("r2");
      if (p->work[3] == 1) {
        zz = pZero2;
        dx = (((zz->s).coord.x - p->coord.x) << 12) >> 16;
        ty = p->coord.y;
        ty += -0x2000;
      } else {
        zz = pZero2;
        dx = (((zz->s).coord.x - p->coord.x) << 12) >> 16;
        ty = p->coord.y;
        ty += 0x3000;
      }
      {
        s32 dy2 = (((zz->s).coord.y - ty) << 12) >> 16;
        a = (u8)((((u16)ArcTan2(dx, dy2)) + 0x4000) >> 8);
      }
      PlaySound(0x43);
      blizzack_080aaae0((struct Entity*)p, (u8)(a + 6));
      blizzack_080aaae0((struct Entity*)p, (u8)(a - 6));
    }
  }
  if (p->motion.state == 3) {
    p->mode[1] = 0xF;
    p->mode[2] = 1;
  }
}

void blizzackBombFall(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xb4, 0x03));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6403;
    *t = v;
    p->mode[2] = z;
  }
  UpdateEntityAnim((struct Entity*)p);
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;
  p->d.y += 0x60;
  if (p->d.y > 0x700) {
    p->d.y = 0x700;
  }
  if (FUN_08009f6c(p->coord.x, p->coord.y) < p->coord.y) {
    p->mode[1] = 0x10;
    p->mode[2] = 1;
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
  }
}

void blizzackBombStamp(Blizzack* p) {
  if (p->mode[2] != 0) {
    struct Entity* q;
    register u16* h asm("r0");
    register s32 z asm("r2");
    register s32 kv asm("r1");
    SetMotion((struct Entity*)p, 0xB404);
    q = p->unk_2c;
    q->mode[2] = 1;
    h = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    kv = 0x6404;
    *h = kv;
    p->mode[2] = z;
    p->work[2] = z;
    PlaySound(0x91);
    AppendQuake(4, &p->coord);
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    register u8 w asm("r1");
    register s32 nx asm("r0");
    w = p->work[2];
    nx = w + 1;
    asm("" : "+r"(nx));
    p->work[2] = nx;
    if ((w & 0xF) == 0) {
      struct Coord* c = &p->coord;
      CreateVFX57(c, 0, 1, 0x118, -(p->work[2] << 2) - 0x40);
      CreateVFX57(c, 0, 1, -0x118, -(p->work[2] << 2) - 0x40);
    }
  }
  if (p->work[2] != 0x30) {
    return;
  }
  if (*((u8*)p + 0xc5) != 0) {
    p->mode[1] = 4;
    p->mode[2] = 1;
    p->mode[3] = 5;
    return;
  }
  if (*((u8*)p + 0xc6) > 1) {
    register s32 half asm("r0");
    s16* lp;
    register s32 m asm("r0");
    half = *(s8*)((u8*)p + 0xd0);
    half += (s32)((u32)half >> 31);
    lp = (s16*)((u8*)p + 0xa4);
    half >>= 1;
    if (half > *lp) {
      if (gScore.total->rank > 4) {
        m = 0xA;
        goto setm;
      }
    }
    m = 7;
  setm:
    p->mode[1] = m;
    p->mode[2] = 1;
    return;
  }
  {
    register s32 seven asm("r4");
    register u32* rp asm("r2");
    register u32 ka asm("r3");
    register u32 sv asm("r1");
    u32 t;
    rp = &RNG_0202f388;
    {
      u32 v = *rp;
      ka = 0x343FD;
      t = ka * v;
    }
    t += 0x269EC3;
    t <<= 1;
    sv = t >> 1;
    *rp = sv;
    t >>= 0x11;
    seven = 7;
    t &= seven;
    if (t == 0) {
      p->mode[1] = 2;
      p->mode[2] = 1;
      return;
    }
    t = sv;
    t *= ka;
    t += 0x269EC3;
    t <<= 1;
    sv = t >> 1;
    *rp = sv;
    t >>= 0x11;
    {
      register s32 one asm("r1");
      one = 1;
      t &= one;
      if (t != 0) {
        p->mode[1] = seven;
        p->mode[2] = one;
        return;
      }
      p->mode[1] = 4;
      p->mode[2] = one;
      p->mode[3] = 0xD;
    }
  }
}

void blizzackMode17(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x05));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6405;
    *t = v;
    p->mode[2] = z;
    p->work[2] = 0x18;
  }
  UpdateEntityAnim((struct Entity*)p);
  if (p->work[2] == 0xC) {
    if (p->coord.y - 0x4000 > pZero2->s.coord.y) {
      CreateProjectile31((Entity*)p, 1, 4);
      CreateProjectile31((Entity*)p, 1, 5);
      CreateProjectile31((Entity*)p, 1, 6);
      CreateProjectile31((Entity*)p, 1, 7);
    } else {
      CreateProjectile31((Entity*)p, 1, 0);
      CreateProjectile31((Entity*)p, 1, 1);
      CreateProjectile31((Entity*)p, 1, 2);
      CreateProjectile31((Entity*)p, 1, 3);
    }
  }
  if (--p->work[2] == 0xFF) {
    p->mode[1] = 0x12;
    p->mode[2] = 1;
  }
}

void blizzackMode18(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x06));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x6406;
    *t = v;
    p->mode[2] = z;
    p->work[2] = 8;
  }
  UpdateEntityAnim((struct Entity*)p);
  if (--p->work[2] == 0xFF) {
    p->mode[1] = 3;
    p->mode[2] = 1;
  }
}

void blizzackMode19(Blizzack* p) {
  if (p->mode[2] != 0) {
    s32 v;
    register u8 z asm("r2");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x0B));
    (p->unk_2c)->mode[2] = 1;
    {
      register u16* h asm("r0");
      register s32 hv asm("r1");
      h = (u16*)((u8*)p->unk_2c + 0xbc);
      z = 0;
      asm("" : "+r"(z));
      hv = 0x640B;
      *h = hv;
    }
    p->mode[2] = z;
    v = 0x100;
    p->d.x = v;
    p->d.y = -0x300;
    if (*(u8*)((u8*)p + 0xc4) != 0) {
      p->d.x = -v;
    }
    SetDDP(&p->body, &sCollisions[0]);
  }
  UpdateEntityAnim((struct Entity*)p);
  {
    s32 dy;
    p->coord.y += p->d.y;
    dy = p->d.y + 0x60;
    p->d.y = dy;
    if (dy > 0x700) {
      p->d.y = 0x700;
    }
  }
  if (FUN_08009f6c(p->coord.x, p->coord.y) < p->coord.y) {
    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
    if (*(s32*)((u8*)p + 0xd4) == 0) {
      p->mode[1] = 0x14;
      p->mode[2] = 1;
    }
  } else {
    p->coord.x += p->d.x;
  }
}

void blizzackMode20(Blizzack* p) {
  if (p->mode[2] != 0) {
    u16* t;
    register s32 z asm("r2");
    register s32 v asm("r1");
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x0E));
    ((struct Entity*)p->unk_2c)->mode[2] = 1;
    t = (u16*)((u8*)p->unk_2c + 0xbc);
    z = 0;
    v = 0x640D;
    *t = v;
    p->mode[2] = z;
    p->work[2] = 8;
  }
  UpdateEntityAnim((struct Entity*)p);
  if (--p->work[2] == 0xFF) {
    p->mode[1] = 2;
    p->mode[2] = 1;
  }
}

void blizzack_0805ac5c(Blizzack* p) {
  register s32 one asm("r5");
  s32 nm;
  register s32 z2 asm("r2");
  u8* fp;
  u32* st;
  struct Coord c;
  {
    struct StageRun* sr = &gStageRun;
    u16 ms = sr->missionStatus;
    s32 t;
    one = 1;
    asm volatile("add %0, %1, #0" : "=&l"(t) : "l"(one));
    t &= ms;
    if (t != 0) {
      u8 av = sr->vm.active;
      s32 t2;
      asm volatile("add %0, %1, #0" : "=&l"(t2) : "l"(one));
      t2 &= av;
      if (t2 == 0) {
        register s32 mk asm("r0");
        register s32 k10 asm("r1");
        mk = 0xFFFE;
        mk &= ms;
        k10 = 0x10;
        mk |= k10;
        sr->missionStatus = mk;
      }
    }
  }
  StopSound(*(s16*)((u8*)p + 0xc8));
  p->mode[2] = 0;
  p->work[2] = 0;
  {
    s32 onR = 0;
    if ((pZero2->s).coord.x > p->coord.x) {
      onR = 1;
    }
    fp = (u8*)p + 0xc4;
    *fp = onR;
  }
  SetMotion((struct Entity*)p, 0xB40B);
  UpdateEntityAnim((struct Entity*)p);
  {
    u32* st0 = (u32*)((u8*)p + 0x8c);
    u32 sv = *st0 & 0x10000;
    asm volatile("add %0, %1, #0" : "=&l"(st) : "l"(st0));
    if (sv != 0) {
    c.x = p->coord.x;
    c.y = p->coord.y - 0x1C00;
    FUN_080b2b40(0, &c, 0x200, *fp);
      nm = 2;
    } else {
      nm = 1;
    }
  }
  p->mode[1] = nm;
  z2 = 0;
  asm("" : "+r"(z2));
  p->mode[2] = 1;
  (p->unk_2c)->mode[3] = 1;
  *st = z2;
  *(u32*)((u8*)p + 0x90) = z2;
  *(u8*)((u8*)p + 0x94) = z2;
  p->flags &= 0xFB;
}

void blizzack_0805ad2c(Blizzack* p) {
  struct Coord c;
  if (p->mode[2] != 0) {
    u8 z;
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x0B));
    z = 0;
    p->d.y = z;
    p->work[2] = z;
    p->mode[2] = z;
    p->mode[3] = z;
  }
  UpdateEntityAnim((struct Entity*)p);
  switch (p->mode[3]) {
    case 0:
      if ((p->scriptEntity->flags & 0x80) == 0) {
        return;
      }
      c.x = 0x600;
      c.y = -0x1800;
      p->unk_2c = CreateBossExplosion((struct Entity*)p, &c);
      break;
    case 1:
      if ((p->unk_2c)->mode[0] <= 1) {
        return;
      }
      gStageRun.vm.active |= 2;
      p->work[2] = 0x20;
      break;
    case 2:
      if ((u8)--p->work[2] != 0xFF) {
        return;
      }
      {
        register u8 t asm("r0");
        register u8 fv asm("r1");
        t = p->flags;
        fv = 0xFE;
        fv &= t;
        p->flags = fv;
        asm volatile("" :: "r"(t));
      }
      break;
    default:
      return;
  }
  p->mode[3]++;
}

void blizzack_0805add0(Blizzack* p) {
  struct Coord c;
  if (p->mode[2] != 0) {
    u8* q;
    register u32 one asm("r2");
    register u8 fl asm("r1");
    u32 z;
    SetMotion((struct Entity*)p, MOTION(0xB4, 0x0C));
    q = (u8*)p + 0xc4;
    {
      u8 qv = *q;
      u32 v;
      one = 1;
      asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(one));
      v &= qv;
      (p->spr).xflip = v;
    }
    {
      register u8* oa asm("ip");
      u8 qv = *q;
      u32 v;
      oa = (u8*)p + 0x4a;
      asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(one));
      v &= qv;
      {
        u32 sh4 = v << 4;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
    }
    one &= *q;
    if (one != 0) {
      p->flags |= 0x10;
    } else {
      p->flags &= 0xEF;
    }
    fl = p->flags;
    if ((0x10 & fl) != 0) {
      p->d.x = 0x20;
      p->unk_coord.x = -1;
    } else {
      p->d.x = -0x20;
      p->unk_coord.x = 1;
    }
    z = 0;
    p->work[2] = 0x20;
    p->mode[2] = z;
    p->mode[3] = z;
    CreateEnemy42((struct Entity*)p, 2, (((u32)fl << 24) >> 28) & 1);
    p->unk_2c = (struct Entity*)z;
    PlaySound(0x2F);
  }
  UpdateEntityAnim((struct Entity*)p);
  switch (p->mode[3]) {
    case 0:
      p->coord.x += p->d.x;
      p->d.x += p->unk_coord.x;
      if ((u8)--p->work[2] != 0xFF) {
        break;
      }
      goto next;
    case 1:
      if (((p->scriptEntity)->flags & 0x80) == 0) {
        break;
      }
      c.x = 0xE00;
      c.y = -0x1800;
      p->unk_2c = CreateBossExplosion((struct Entity*)p, &c);
      goto next;
    case 2:
      if ((p->unk_2c)->mode[0] <= 1) {
        break;
      }
      gStageRun.vm.active |= VM_FLAG1;
      p->work[2] = 0x20;
      goto next;
    case 3:
      if ((u8)--p->work[2] != 0xFF) {
        break;
      }
      {
        register u8 t asm("r0");
        register u8 fv asm("r1");
        t = p->flags;
        fv = (u8)~DISPLAY;
        fv &= t;
        p->flags = fv;
        asm volatile("" :: "r"(t));
      }
    next:
      p->mode[3]++;
      break;
  }
}

void FUN_0805af14(struct Boss* p) {
  if (p->coord.x < *(s32*)((u8*)p + 0xb4) + 0x2000 ||
      p->coord.x > *(s32*)((u8*)p + 0xd8) - 0x2000) {
    p->coord.x = *(s32*)((u8*)p + 0xc0);
  }
  *(s32*)((u8*)p + 0xc0) = p->coord.x;
}

void blizzackMode0(Blizzack* p);
void blizzackMode1(Blizzack* p);
void blizzackNeutral(Blizzack* p);
void blizzackPreAI(Blizzack* p);
void blizzackNextMode(Blizzack* p);
void blizzackJump(Blizzack* p);
void blizzackStamp(Blizzack* p);
void blizzackMode7(Blizzack* p);
void blizzackMode8(Blizzack* p);
void blizzackMode9(Blizzack* p);
void blizzackStartBlizzard(Blizzack* p);
void blizzackBlizzard(Blizzack* p);
void blizzackEndBlizzard(Blizzack* p);
NON_MATCH void blizzackBombJump(Blizzack* p);
void blizzackBomb(Blizzack* p);
void blizzackBombFall(Blizzack* p);
void blizzackBombStamp(Blizzack* p);
void blizzackMode17(Blizzack* p);
void blizzackMode18(Blizzack* p);
void blizzackMode19(Blizzack* p);
void blizzackMode20(Blizzack* p);

// clang-format off
// 0x08364b50
static void (*const sUpdates[21])(Blizzack*) = {
    blizzackMode0,
    blizzackMode1,
    blizzackNeutral,
    blizzackPreAI,
    blizzackNextMode,
    blizzackJump,
    blizzackStamp,
    blizzackMode7,
    blizzackMode8,
    blizzackMode9,
    blizzackStartBlizzard,
    blizzackBlizzard,
    blizzackEndBlizzard,
    blizzackBombJump,
    blizzackBomb,
    blizzackBombFall,
    blizzackBombStamp,
    blizzackMode17,
    blizzackMode18,
    blizzackMode19,
    blizzackMode20,
};
// clang-format on

// --------------------------------------------

void blizzack_0805ac5c(Blizzack* p);
void blizzack_0805ad2c(Blizzack* p);
void blizzack_0805add0(Blizzack* p);

static void (*const sDeads[3])(Blizzack*) = {
    blizzack_0805ac5c,
    blizzack_0805ad2c,
    blizzack_0805add0,
};

// --------------------------------------------

// 0x08364bb0
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 8,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(24), PIXEL(34), PIXEL(48)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 8,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      remaining : 0,
      range : {PIXEL(8), -PIXEL(24), PIXEL(50), PIXEL(48)},
    },
};

// 0x08364c10
static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(24)};
