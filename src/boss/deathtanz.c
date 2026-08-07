#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "script.h"
#include "zero.h"

struct Entity* CreateVFX39(struct Coord* c, u8 r1, u8 r2);
void FUN_080bdaf8(s32 x, s32 y);
void RemovePaletteAnimation(u16 n);
u32 StepPaletteAnimation(u16 blinkID);
void FUN_080a08e0(struct Entity* e, s32 x, s32 y, u8 a3);
void deathtanz_080a09a0(struct Entity* parent, s32 x, s32 y, u8 n);
void deathtanz_080a09f4(struct Entity* e, s32 x, s32 y, u8 a3, u8 a4);
s32 PushoutToUp1(s32 x, s32 y);
s32 PushoutToDown1(s32 x, s32 y);
void FUN_080bdb44(s32 x, s32 y);
struct Entity* CreateSmoke(u8 kind, struct Coord* c);
struct Entity* CreateBossExplosion(struct Entity* boss, struct Coord* c);
void FUN_080bdb44(s32 x, s32 y);

struct Deathtanz {
  COLLISION_OBJECT_HDR;  // 0x00
  // props (48bytes, offset: 0xB4..)
  Coords32 unk_b4;
  u8 unk_bc;
  u8 unk_bd;
  u8 unk_be;
  u8 unk_bf;
  u8 unk_c0;
  u8 unk_c1;
  bool8 shouldTurnRight;
  u8 unk_c3;
  u8 unk_c4;
  u8 unk_c5[3];
  Coords32 unk_c8;
  u8 unk_d0[20];
};
static_assert(sizeof(struct Deathtanz) == sizeof(struct Boss));

static const u8 sDeathtanzModes[32];
static const struct Collision sCollisions[];
static const u8 sInitModes[2];

static void Deathtanz_Init(struct Deathtanz* p);
static void Deathtanz_Update(struct Boss* p);
static void Deathtanz_Die(struct Boss* p);

// clang-format off
const BossRoutine gDeathtanzRoutine = {
    [ENTITY_INIT] =      (void*)Deathtanz_Init,
    [ENTITY_UPDATE] =    (void*)Deathtanz_Update,
    [ENTITY_DIE] =       (void*)Deathtanz_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


void FUN_080a0888(s32 x, s32 y, u8 a2, u8 a3);
struct Entity* FUN_080b2b40(u8 kind, struct Coord* c, s32 r2, u8 r3);
void StartPaletteAnimation(u16 blinkID, u16 ofs);
extern void __divsi3();
void deathtanz_080a0934(struct Entity* e, s32 x, s32 y, u8 a3, u8 a4);
static const Coords32 sExplosionCoords[2];
static const u8 sPostures[14];
static const u8 u8_ARRAY_08362ea6[16];
NAKED static void calcNextAction(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	mov ip, r0\n\
	movs r3, #0\n\
	adds r0, #0xb4\n\
	mov r2, ip\n\
	ldr r1, [r2, #0x54]\n\
	ldr r2, [r0]\n\
	cmp r1, r2\n\
	bge _08048D84\n\
	movs r3, #1\n\
_08048D84:\n\
	ldr r0, _08048DA4 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r0, r2\n\
	bge _08048D92\n\
	movs r0, #1\n\
	eors r3, r0\n\
_08048D92:\n\
	ldr r7, _08048DA8 @ =RNG_0202f388\n\
	mov r5, ip\n\
	adds r5, #0xc3\n\
	ldr r0, _08048DAC @ =sDeathtanzModes\n\
	mov r8, r0\n\
	lsls r6, r3, #4\n\
	mov r4, ip\n\
	adds r4, #0xc4\n\
	b _08048DBA\n\
	.align 2, 0\n\
_08048DA4: .4byte pZero2\n\
_08048DA8: .4byte RNG_0202f388\n\
_08048DAC: .4byte sDeathtanzModes\n\
_08048DB0:\n\
	ldr r0, _08048DF8 @ =gScore\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #4\n\
	bhi _08048DE6\n\
_08048DBA:\n\
	ldr r1, [r7]\n\
	ldr r0, _08048DFC @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08048E00 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r7]\n\
	lsrs r3, r0, #0x11\n\
	movs r0, #0xf\n\
	ands r3, r0\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r5]\n\
	ldrb r2, [r0]\n\
	cmp r1, r2\n\
	bne _08048DE2\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _08048DBA\n\
_08048DE2:\n\
	cmp r2, #0x11\n\
	beq _08048DB0\n\
_08048DE6:\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	bne _08048E04\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	b _08048E08\n\
	.align 2, 0\n\
_08048DF8: .4byte gScore\n\
_08048DFC: .4byte 0x000343FD\n\
_08048E00: .4byte 0x00269EC3\n\
_08048E04:\n\
	movs r0, #0\n\
	strb r1, [r5]\n\
_08048E08:\n\
	strb r0, [r4]\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r1, #0\n\
	mov r2, ip\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  struct Zero* z = (struct Zero*)body->enemy->parent;
  struct Deathtanz* p = (struct Deathtanz*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (p->unk_c8).x = (z->s).coord.x;
    (p->unk_c8).y = (z->s).coord.y;
    p->shouldTurnRight = (p->coord).x < (z->s).coord.x;
  }
}

static bool8 tryKillDeathtanz(struct Boss* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    PlaySound(SE_DEATHTANZ_DEATH);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    Deathtanz_Die(p);
    return TRUE;
  }

  return FALSE;
}

static void Deathtanz_Init(struct Deathtanz* p) {
  s32 y;

  // TODO: Kill them all
#if MODERN == 0
  register u32 r0 asm("r0");
  register u8 r1 asm("r1");
  register u8* r2 asm("r2");
#endif

  SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  ResetBossBody((void*)p, &sCollisions[0], 64);
  SET_BOSS_COLLISION_HANDLER(p, onCollision);

  if (p->work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM054_DEATHTANZ_ROCK);
    LOAD_STATIC_GRAPHIC(SM055_DEATHTANZ_PROJECTILE);

    p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y);
    p->unk_b4.x = p->coord.x >> 8;
    p->unk_b4.x = ((p->unk_b4.x / 240) * PIXEL(240)) + PIXEL(120);
    p->unk_b4.y = p->coord.y;
    p->unk_bd = 0;
    p->unk_c1 = 3;
#if MODERN
    p->unk_c3 = 0xFF;
#else
    r2 = &p->unk_c3;
    r0 = *r2;
    r1 = 0xFF;
    r0 |= r1;
    *r2 = r0;
#endif
    p->unk_c4 = 0;
  }
  Deathtanz_Update((void*)p);
}

// --------------------------------------------

static void nop_0804908c(void* _);
static void tryMakeFlinch(struct Boss* p);

void deathtanzMode0(struct Boss* p);
void deathtanzNeutral(struct Boss* p);
void deathtanzMode2(struct Boss* p);
void deathtanzMode3(struct Boss* p);
void deathtanzMode4(struct Boss* p);
void deathtanzPreAI(struct Deathtanz* p);
void deathtanzMode6(struct Boss* p);
void deathtanzMode7(struct Deathtanz* p);
void deathtanzMode8(struct Boss* p);
void deathtanzMode9(struct Boss* p);
void deathtanzMode10(struct Boss* p);
void deathtanzMode11(struct Boss* p);
void deathtanzMode12(struct Boss* p);
void deathtanzMode13(struct Boss* p);
void deathtanzMode14(struct Boss* p);
void deathtanzMode15(struct Boss* p);
void deathtanzMode16(struct Deathtanz* p);
void deathtanzEX1(struct Deathtanz* p);
void deathtanzEX2(struct Boss* p);
void deathtanzMode19(struct Boss* p);
void deathtanzKnockBackDamage(struct Boss* p);

static void Deathtanz_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[21] = {
      (BossFunc)nop_0804908c,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)nop_0804908c,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)tryMakeFlinch,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
      (BossFunc)nop_0804908c,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[21] = {
      (BossFunc)deathtanzMode0,
      (BossFunc)deathtanzNeutral,
      (BossFunc)deathtanzMode2,
      (BossFunc)deathtanzMode3,
      (BossFunc)deathtanzMode4,
      (BossFunc)deathtanzPreAI,
      (BossFunc)deathtanzMode6,
      (BossFunc)deathtanzMode7,
      (BossFunc)deathtanzMode8,
      (BossFunc)deathtanzMode9,
      (BossFunc)deathtanzMode10,
      (BossFunc)deathtanzMode11,
      (BossFunc)deathtanzMode12,
      (BossFunc)deathtanzMode13,
      (BossFunc)deathtanzMode14,
      (BossFunc)deathtanzMode15,
      (BossFunc)deathtanzMode16,
      (BossFunc)deathtanzEX1,
      (BossFunc)deathtanzEX2,
      (BossFunc)deathtanzMode19,
      (BossFunc)deathtanzKnockBackDamage,
  };
  // clang-format on

  bool8 killed = tryKillDeathtanz(p);
  if (!killed) {
    (sUpdates1[p->mode[1]])(p);
    (sUpdates2[p->mode[1]])(p);
  }
}

// --------------------------------------------

void FUN_0804ac44(struct Boss* p);
void deathtanz_0804adb0(struct Boss* p);

static void Deathtanz_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      (BossFunc)FUN_0804ac44,
      (BossFunc)deathtanz_0804adb0,
  };
  (sDeads[p->mode[1]])(p);
}

// --------------------------------------------

static void nop_0804908c(void* p) {}

static void tryMakeFlinch(struct Boss* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      p->mode[1] = 20, p->mode[2] = 0;
    }
  }
}

void deathtanzMode0(struct Boss* p) {
  u32 pa;
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x01));
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((p->scriptEntity->flags & 1) == 0) {
        break;
      }
      goto inc2;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x02));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if ((*(u32*)((u8*)p + 0x70) & 0xFFFF00) == (0x83 << 9)) {
        PlaySound(0x5b);
      }
      goto st;
    case 4: {
      struct Coord c;
      register struct Entity* v asm("r3");
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x03));
      c.x = p->coord.x;
      c.y = p->coord.y - 0x2000;
      v = CreateVFX39(&c, 1, 0);
      p->unk_2c = v;
      if (v != NULL) {
        register s32 z asm("r2");
        register u8* q asm("r1");
        q = (u8*)v + 0x74;
        z = 0;
        *q = 0x10;
        q += 1;
        asm("" : "+r"(q));
        *q = 6;
        q += 1;
        asm("" : "+r"(q));
        *q = 0x18;
        *(s32*)((u8*)v + 0x78) = z;
      }
      {
        s32 z2 = 0;
        p->work[2] = 0x1e;
        p->d.x = z2;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      register s32 d asm("r5");
      struct Entity* v;
      {
        register s32 d0 asm("r1");
        s32 n;
        d0 = p->d.x;
        n = (0x80 << 7) - d0;
        if (n < 0) {
          n += 15;
        }
        n >>= 4;
        d = d0 + n;
        p->d.x = d;
      }
      v = p->unk_2c;
      if (v != NULL) {
        {
          s32 q8 = d;
          u32 mm;
          if (d < 0) {
            q8 = d + 7;
          }
          q8 >>= 3;
          {
            register u32 w asm("r1");
            w = p->work[2];
            mm = 1;
            mm &= w;
          }
          mm *= q8;
          asm volatile("add %0, %1, %0" : "+l"(mm) : "l"(d));
          *(s32*)((u8*)v + 0x78) = mm;
        }
      }
      {
        s32 t = p->work[2] - 1;
        p->work[2] = t;
        if ((t << 24) == 0) {
          p->mode[2]++;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 6: {
      u32 v2, sv, k, kc;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x04));
      v2 = GetEntityPaletteID((struct Entity*)p);
      sv = ((u32)(u8)v2) << 5;
      k = 0x80 << 2;
      asm volatile("add %0, %1, #0" : "=&l"(kc) : "l"(k));
      ((void (*)(u16, u32))StartPaletteAnimation)(0x29, sv | kc);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      struct Entity* v = p->unk_2c;
      if (v != NULL) {
        register s32 d asm("r5");
        d = p->d.x;
        {
          s32 q8 = d;
          u32 mm;
          if (d < 0) {
            q8 = d + 7;
          }
          q8 >>= 3;
          {
            register u32 w asm("r1");
            w = p->work[2];
            mm = 1;
            mm &= w;
          }
          mm *= q8;
          asm volatile("add %0, %1, %0" : "+l"(mm) : "l"(d));
          *(s32*)((u8*)v + 0x78) = mm;
        }
      }
      p->work[2]--;
      pa = 0x29;
      goto step;
    }
    case 8: {
      u32 v2, sv, k, kc;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x05));
      RemovePaletteAnimation(0x29);
      v2 = GetEntityPaletteID((struct Entity*)p);
      sv = ((u32)(u8)v2) << 5;
      k = 0x80 << 2;
      asm volatile("add %0, %1, #0" : "=&l"(kc) : "l"(k));
      ((void (*)(u16, u32))StartPaletteAnimation)(0x2a, sv | kc);
      PlaySound(0x45);
      FUN_080bdaf8(p->coord.x, p->coord.y);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 9: {
      register s32 d asm("r5");
      struct Entity* v;
      {
        register s32 d0 asm("r1");
        s32 n;
        d0 = p->d.x;
        n = -d0;
        if (n < 0) {
          n += 15;
        }
        n >>= 4;
        d = d0 + n;
        p->d.x = d;
      }
      v = p->unk_2c;
      if (v != NULL) {
        {
          s32 q8 = d;
          u32 mm;
          if (d < 0) {
            q8 = d + 7;
          }
          q8 >>= 3;
          {
            register u32 w asm("r1");
            w = p->work[2];
            mm = 1;
            mm &= w;
          }
          mm *= q8;
          asm volatile("add %0, %1, %0" : "+l"(mm) : "l"(d));
          *(s32*)((u8*)v + 0x78) = mm;
        }
      }
      p->work[2]--;
      pa = 0x2a;
    step:
      StepPaletteAnimation(pa);
      UpdateEntityAnim((struct Entity*)p);
    st:
      if (p->motion.state != 3) {
        break;
      }
    inc2:
      p->mode[2]++;
      break;
    }
    case 10: {
      register struct Entity* v asm("r3");
      v = p->unk_2c;
      if (v != NULL) {
        register u8* q77 asm("r1");
        q77 = (u8*)v + 0x77;
        *q77 = 1;
      }
      RemovePaletteAnimation(0x2a);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x06));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 11: {
      register s32 one asm("r2");
      register s32 f asm("r1");
      s32 g;
      UpdateEntityAnim((struct Entity*)p);
      g = gStageRun.vm.active;
      one = 1;
      f = one;
      f &= g;
      if (f != 0) {
        break;
      }
      p->mode[1] = one;
      p->mode[2] = f;
      break;
    }
  }
}

void deathtanzNeutral(struct Boss* p) {
  u8* fp;
  u8 fv;
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      {
        u8* fp0 = (u8*)p + 0xbd;
        fv = *fp0;
        asm volatile("add %0, %1, #0" : "=&l"(fp) : "l"(fp0));
      }
      if (fv != 0) {
        register s32 one asm("r2");
        s32 v;
        s32 v2;
        register u8* oa asm("ip");
        u8* t0;
        v = p->flags >> 4;
        one = 1;
        v ^= one;
        asm("" : "+r"(v));
        v &= one;
        (p->spr).xflip = v;
        v2 = p->flags >> 4;
        v2 ^= one;
        asm("" : "+r"(v2));
        v2 &= one;
        {
          u32 off = 0x4a;
          u32 sh4;
          s32 ov;
          s32 m11;
          register u8* fa asm("r2");
          asm("" : "+r"(off));
          off += (u32)p;
          t0 = (u8*)off;
          oa = t0;
          asm("" : "+r"(oa));
          sh4 = v2 << 4;
          ov = *t0;
          m11 = -0x11;
          asm("" : "+r"(m11));
          m11 &= ov;
          m11 |= sh4;
          fa = oa;
          asm("" : "+r"(fa));
          *fa = m11;
        }
        if (v2 != 0) {
          p->flags |= 0x10;
        } else {
          p->flags &= 0xEF;
        }
      }
      *fp = 0;
      p->work[2] = 8;
      SetMotion((struct Entity*)p, 0xA706);
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 raw;
      struct Zero* z;
      UpdateEntityAnim((struct Entity*)p);
      raw = p->work[2] - 1;
      p->work[2] = raw;
      if ((raw << 24) != 0) {
        break;
      }
      z = pZero2;
      if (*(u32*)((u8*)z + 0x8c) & 0x200) {
        break;
      }
      if (*(s16*)((u8*)z + 0xa4) == 0) {
        break;
      }
      calcNextAction(p);
      break;
    }
  }
}

void deathtanzMode2(struct Boss* p) {
  register s32 st asm("r5");
  register s32 nm asm("r0");
  switch (p->mode[2]) {
    case 0: {
      register s32 f asm("r2");
      p->work[2] = 0;
      f = 0;
      if (p->coord.x > *(s32*)((u8*)p + 0xb4)) {
        f = 1;
      }
      if ((p->flags & 0x10) != 0) {
        if (f == 0) {
          goto nm2;
        }
        goto go;
      } else {
        if (f == 0) {
          goto go;
        }
      }
    nm2:
      nm = 2;
      goto setmode;
    go:
      SetDDP(&p->body, &sCollisions[4]);
      p->work[2] = 1;
      SetMotion((struct Entity*)p, 0xA707);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0x73) != 3) {
        break;
      }
      nm = p->mode[2] + 1;
      goto setmode;
    case 2: {
      if (p->work[2] != 0) {
        register s32 one asm("r2");
        {
          register s32 xf asm("r0");
          xf = (u32)p->flags >> 4;
          one = 1;
          xf ^= one;
          asm("" : "+r"(xf));
          xf &= one;
          *((u8*)p + 0x4c) = xf;
        }
        {
          register s32 x2 asm("r1");
          x2 = (u32)p->flags >> 4;
          x2 ^= one;
          asm("" : "+r"(x2));
          x2 &= one;
          {
            register u8* oa asm("ip");
            register s32 sh asm("r3");
            register s32 ov asm("r2");
            register s32 m11 asm("r0");
            oa = (u8*)p + 0x4a;
            sh = x2 << 4;
            ov = *oa;
            m11 = -0x11;
            m11 &= ov;
            m11 |= sh;
            *oa = m11;
          }
          if (x2 != 0) {
            register s32 g asm("r0");
            register s32 k asm("r1");
            g = p->flags;
            asm("" : "+r"(g));
            k = 0x10;
            g |= k;
            p->flags = g;
          } else {
            register u8 h asm("r1");
            register u8 g2 asm("r0");
            h = p->flags;
            asm("" : "+r"(h));
            g2 = 0xEF;
            g2 &= h;
            p->flags = g2;
          }
        }
      }
      {
        register const u8* tb asm("r3");
        register s32 v asm("r0");
        tb = u8_ARRAY_08362ea6;
        asm("" : "+r"(tb));
        v = RANDOM(RNG_0202f388) & 0xF;
        v += (s32)tb;
        v = *(const u8*)v;
        *((u8*)p + 0xbc) = v;
        asm("" : "+r"(v));
        if ((v << 24) == 0) {
          SetDDP(&p->body, &sCollisions[7]);
          SetMotion((struct Entity*)p, 0xA708);
        } else {
          SetDDP(&p->body, &sCollisions[9]);
          SetMotion((struct Entity*)p, 0xA709);
        }
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      st = *((u8*)p + 0x73);
      if (st != 3) {
        break;
      }
      PlaySound(0x5c);
      if (*((u8*)p + 0xbc) == 0) {
        if ((RANDOM(RNG_0202f388) & 1) != 0) {
          p->mode[1] = 6;
        } else {
          p->mode[1] = 9;
        }
      } else {
        p->mode[1] = st;
      }
      nm = 0;
    setmode:
      p->mode[2] = nm;
      break;
  }
}

void deathtanzMode3(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 tx asm("r6");
      register s32 sq asm("r4");
      register s32 w asm("r0");
      register s32* bp asm("r0");
      register s32 bx asm("r2");
      register s32 cx asm("r1");
      SetDDP(&p->body, &sCollisions[12]);
      w = *((u8*)p + 0xbc);
      w <<= 5;
      w += 0x10;
      tx = w << 8;
      asm volatile("add %0, %1, #0" : "=&l"(bp) : "l"(p));
      bp = (s32*)((u8*)bp + 0xb4);
      cx = p->coord.x;
      bx = *bp;
      if (cx < bx) {
        register s32 k asm("r1");
        register s32 t1 asm("r0");
        k = -0x7800;
        asm("" : "+r"(k));
        t1 = tx + k;
        tx = bx - t1;
      } else {
        register s32 k2 asm("r1");
        register s32 t2 asm("r0");
        k2 = -0x7800;
        asm("" : "+r"(k2));
        t2 = tx + k2;
        tx = bx + t2;
      }
      sq = 0xC3 * 8;
      {
        register s32 d asm("r1");
        register s32 num asm("r0");
        d = ((s32(*)(u32))Sqrt)(sq);
        asm("" : "+r"(d));
        num = tx - p->coord.x;
        d = (s32)(((u32)(d << 16)) >> 15);
        p->d.x = num / d;
      }
      {
        u32 t = (u16)Sqrt(sq);
        p->d.y = -(s32)((((t * 4 + t) * 4 + t)) * 4) / 2;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0A));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      p->coord.x += p->d.x;
      p->d.y += 0x2A;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      if (p->d.y > 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 2:
      SetDDP(&p->body, &sCollisions[15]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0B));
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 cy, by;
      UpdateEntityAnim((struct Entity*)p);
      p->coord.x += p->d.x;
      p->d.y += 0x2A;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      cy = p->coord.y + p->d.y;
      p->coord.y = cy;
      by = *(s32*)((u8*)p + 0xb8);
      if (cy > by) {
        p->coord.y = by;
        p->mode[2]++;
      }
      break;
    }
    case 4:
      SetDDP(&p->body, &sCollisions[9]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x09));
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        register s32 md asm("r0");
        if ((p->flags & 0x10) == 0) {
          register struct Zero* z1 asm("r0");
          register s32 zx asm("r0");
          register s32 cx1 asm("r1");
          register s32 lim1 asm("r1");
          register s32 d1 asm("r0");
          z1 = pZero2;
          asm("" : "+r"(z1));
          zx = (z1->s).coord.x;
          cx1 = p->coord.x;
          d1 = zx - cx1;
          lim1 = 0x45FF;
          asm("" : "+r"(lim1));
          if ((u32)d1 <= (u32)lim1) {
            goto four;
          }
          goto five;
        } else {
          register struct Zero* z2 asm("r1");
          register s32 cx2 asm("r0");
          register s32 zx2 asm("r1");
          register s32 lim2 asm("r1");
          register s32 d2 asm("r0");
          z2 = pZero2;
          asm("" : "+r"(z2));
          cx2 = p->coord.x;
          zx2 = (z2->s).coord.x;
          d2 = cx2 - zx2;
          lim2 = 0x45FF;
          asm("" : "+r"(lim2));
          if ((u32)d2 > (u32)lim2) {
            goto five;
          }
        }
      four:
        md = 4;
        goto setm;
      five:
        md = 5;
      setm:
        p->mode[1] = md;
        {
          register s32 z0 asm("r0");
          z0 = 0;
          p->mode[2] = z0;
        }
      }
      break;
  }
}

void deathtanzMode4(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      motion_t m;
      SetDDP(&p->body, &sCollisions[1]);
      m = MOTION(0xA7, 0x32);
      goto setm;
    case 2:
      m = MOTION(0xA7, 0x33);
    setm:
      SetMotion((struct Entity*)p, m);
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 4: {
      s32 v, nv;
      PlaySound(0x5e);
      SetDDP(&p->body, &sCollisions[18]);
      v = Sqrt(0x1C0) << 6;
      nv = -v;
      p->d.x = v;
      if (p->flags & X_FLIP) {
        p->d.x = nv;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x34));
      p->mode[2]++;
    }
      /* fallthrough */
    case 5: {
      s32 cx = p->coord.x;
      s32 od = p->d.x;
      p->coord.x = cx + od;
      if (p->flags & X_FLIP) {
        s32 nd = od + 0x40;
        p->d.x = nd;
        if (nd > 0) {
          p->mode[2]++;
        }
      } else {
        s32 nd = od - 0x40;
        p->d.x = nd;
        if (nd < 0) {
          p->mode[2]++;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 6:
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x35));
      p->mode[2]++;
      /* fallthrough */
    case 7:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 5;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzPreAI(struct Deathtanz* p) {
  switch (p->mode[2]) {
    case 0: {
      u8* c;
      s32 f;
      struct Zero* z;
      s32 px;
      s32 zx;
      p->unk_bd = 0;
      f = 0;
      z = pZero2;
      px = p->coord.x;
      zx = (z->s).coord.x;
      c = &p->unk_bd;
      if (px > zx) {
        f = 1;
      }
      if (p->flags & X_FLIP) {
        if (f == 0) goto advance;
      } else {
        if (f != 0) goto advance;
      }
      SetDDP(&p->body, &sCollisions[4]);
      *c = 1;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x07));
      p->mode[2]++;
    }
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
      advance:
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzMode6(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32* bp asm("r3");
      register s32 v asm("r0");
      register s32 k asm("r1");
      register s32 tx asm("r6");
      register s32 sq asm("r4");
      SetDDP(&p->body, &sCollisions[15]);
      bp = (s32*)((u8*)p + 0xb4);
      if (p->coord.x < *bp) {
        register s32 one asm("r1");
        u8* oa;
        s32 ov;
        (p->spr).xflip = 1;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        one = 0x10;
        ov |= one;
        *oa = ov;
        p->flags = one | p->flags;
        v = *bp;
        k = 0xA8 * 128;
      } else {
        register s32 zero asm("r0");
        register s32 ov asm("r1");
        u8* xp;
        u8* oa;
        s32 m11;
        xp = (u8*)p + 0x4c;
        zero = 0;
        *xp = zero;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        m11 = zero - 0x11;
        m11 &= ov;
        *oa = m11;
        p->flags &= 0xEF;
        v = *bp;
        k = -0x5400;
      }
      tx = v + k;
      p->unk_coord.x = tx;
      sq = 0x666;
      p->work[2] = Sqrt(sq) + 0x10;
      p->d.x = (tx - p->coord.x) / p->work[2];
      {
        u32 t = (u16)Sqrt(sq);
        p->d.y = -(s32)(((t * 2 + t) << 3) + t);
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0A));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t;
      p->coord.x += p->d.x;
      p->d.y += 0x19;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t <= 0x14) {
        goto tramp;
      }
      break;
    tramp:
      asm volatile("");
      goto inc;
    }
    case 2:
      SetDDP(&p->body, &sCollisions[21]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x20));
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 t;
      p->coord.x += p->d.x;
      p->d.y += 0x19;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t != 0) {
        break;
      }
      goto inc;
    }
    case 4: {
      s32* bp = (s32*)((u8*)p + 0xb4);
      s32 cx = p->coord.x;
      s32 bx = *bp;
      s32 nx;
      if (cx < bx) {
        nx = bx + -0x5400;
      } else {
        nx = bx + 0xA8 * 128;
      }
      p->coord.x = nx;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    inc:
      p->mode[2]++;
      break;
    case 6: {
      register s32 one asm("r2");
      SetDDP(&p->body, &sCollisions[24]);
      {
        register s32 xf0 asm("r0");
        xf0 = p->flags >> 4;
        one = 1;
        xf0 ^= one;
        asm("" : "+r"(xf0));
        xf0 &= one;
        (p->spr).xflip = xf0;
      }
      {
        register s32 xf asm("r1");
        register u8* oa asm("r4");
        s32 sh4, ov, m11;
        xf = p->flags >> 4;
        xf ^= one;
        asm("" : "+r"(xf));
        xf &= one;
        oa = (u8*)p + 0x4a;
        sh4 = xf << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
        if (xf != 0) {
          p->flags |= 0x10;
        } else {
          register u8 h asm("r1");
          register u8 g asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g = 0xEF;
          g &= h;
          p->flags = g;
        }
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x21));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        s32 z0 = 0;
        p->mode[1] = 7;
        p->mode[2] = z0;
      }
      break;
  }
}

void deathtanzMode7(struct Deathtanz* p) {
  s32 md = p->mode[2];
  switch (md) {
    case 0:
      SetDDP(&p->body, &sCollisions[28]);
      p->unk_be = md;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x23));
      p->work[2] = md;
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx == 3 && p->work[2] == 0) {
        s32 cx;
        register s32 off asm("r0");
        p->work[2] = 1;
        p->unk_c1 &= ~1;
        PlaySound(0x5D);
        cx = p->coord.x;
        if (p->flags & 0x10) {
          off = 0x2400;
        } else {
          off = -0x2400;
        }
        FUN_080a08e0((struct Entity*)p, cx + off, p->coord.y - 0x3700, (p->flags >> 4) & 1);
        SetDDP(&p->body, &sCollisions[32]);
      }
      if (p->unk_be != 0) {
        p->mode[2]++;
      }
      break;
    case 2:
      p->unk_c1 |= 1;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x25));
      p->mode[2]++;
      /* fallthrough */
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 8;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzMode8(struct Boss* p) {
  register s32 m asm("r5");
  m = p->mode[2];
  switch (m) {
    case 0: {
      s32 v;
      SetDDP(&p->body, &sCollisions[15]);
      p->d.x = -0x3000;
      {
        register s32 q asm("r1");
        s32 sq = ((s32 (*)(s32))Sqrt)(0x666);
        asm volatile("add %0, %1, #0" : "=&l"(q) : "l"(sq));
        q <<= 16;
        q = (u32)q >> 16;
        asm volatile("" ::: "memory");
        v = ((s32 (*)(s32, s32))__divsi3)(p->d.x, q);
      }
      p->d.x = v;
      if (p->flags & X_FLIP) {
        p->d.x = -v;
      }
      p->d.y = m;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0B));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 ny;
      p->coord.x += p->d.x;
      p->d.y += 0x19;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      {
        s32 dv;
        ny = p->coord.y;
        dv = p->d.y;
        ny += dv;
        p->coord.y = ny;
      }
      if (ny > *(s32*)((u8*)p + 0xb8)) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      SetDDP(&p->body, &sCollisions[9]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x09));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 1;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzMode9(struct Boss* p) {
  register s32 z asm("r4");
  z = p->mode[2];
  switch (z) {
    case 0: {
      register s32 tx asm("r6");
      register s32 sq asm("r4");
      register s32* bp asm("r3");
      register s32 v asm("r0");
      register s32 k asm("r1");
      SetDDP(&p->body, &sCollisions[12]);
      *((u8*)p + 0xbf) = z;
      bp = (s32*)((u8*)p + 0xb4);
      if (p->coord.x < *bp) {
        register s32 one asm("r1");
        u8* oa;
        s32 ov;
        (p->spr).xflip = 1;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        one = 0x10;
        ov |= one;
        *oa = ov;
        p->flags |= one;
        v = *bp;
        k = 0xA8 * 128;
      } else {
        u8* oa;
        s32 m11, ov;
        (p->spr).xflip = z;
        oa = (u8*)p + 0x4a;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        *oa = m11;
        p->flags &= 0xEF;
        v = *bp;
        k = -0x5400;
      }
      tx = v + k;
      p->unk_coord.x = tx;
      sq = 0x851;
      p->work[2] = Sqrt(sq) + 0x10;
      p->d.x = (tx - p->coord.x) / p->work[2];
      {
        u32 t = (u16)Sqrt(sq);
        p->d.y = -(s32)(((t * 2 + t) << 3) + t);
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0A));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t;
      p->coord.x += p->d.x;
      p->d.y += 0x19;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t == 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      register s32 one asm("r2");
      s32 bx, cx, nx;
      SetDDP(&p->body, &sCollisions[35]);
      {
        register s32 xf0 asm("r0");
        xf0 = p->flags >> 4;
        one = 1;
        xf0 ^= one;
        asm("" : "+r"(xf0));
        xf0 &= one;
        (p->spr).xflip = xf0;
      }
      {
        register s32 xf asm("r1");
        register u8* oa asm("r4");
        s32 sh4, ov, m11;
        xf = p->flags >> 4;
        xf ^= one;
        asm("" : "+r"(xf));
        xf &= one;
        oa = (u8*)p + 0x4a;
        sh4 = xf << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
        if (xf != 0) {
          p->flags |= 0x10;
        } else {
          register u8 h asm("r1");
          register u8 g asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g = 0xEF;
          g &= h;
          p->flags = g;
        }
      }
      {
        s32* bp = (s32*)((u8*)p + 0xb4);
        cx = p->coord.x;
        bx = *bp;
        if (cx < bx) {
          nx = bx + -0x5400;
        } else {
          nx = bx + 0xA8 * 128;
        }
        p->coord.x = nx;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0C));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        s32 z0 = 0;
        p->mode[1] = 0xA;
        p->mode[2] = z0;
      }
      break;
  }
}

void deathtanzMode10(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 bx asm("r3");
      register s32 v asm("r0");
      register s32 tx asm("r2");
      register s32 dx asm("r1");
      s32 dy, dist, nx, ny;
      PlaySound(0x5D);
      SetDDP(&p->body, &sCollisions[15]);
      bx = *(s32*)((u8*)p + 0xb4);
      v = bx + -0x1400;
      p->d.x = v;
      tx = v;
      if (p->flags & 0x10) {
        tx = bx + 0xA0 * 32;
      }
      dx = tx - p->coord.x;
      p->d.x = dx;
      dy = *(s32*)((u8*)p + 0xb8) - p->coord.y;
      p->d.y = dy;
      dx >>= 8;
      dist = dx * dx;
      dy >>= 8;
      dist += dy * dy;
      dist = Sqrt(dist) << 8;
      nx = (p->d.x << 8) / dist;
      p->d.x = nx;
      ny = (p->d.y << 8) / dist;
      p->d.x = nx << 3;
      p->d.y = ny << 3;
      {
        register s32 q asm("r0");
        asm volatile("add %0, %1, #0" : "=&l"(q) : "l"(dist));
        p->work[2] = q >> 11;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0B));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t;
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t <= 0x17) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->work[2] = 0;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x26));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if (p->work[2] == 0) {
        s32 cy, by;
        p->coord.x += p->d.x;
        cy = p->coord.y + p->d.y;
        p->coord.y = cy;
        by = *(s32*)((u8*)p + 0xb8);
        if (cy > by) {
          p->coord.y = by;
          p->work[2] = 1;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      SetDDP(&p->body, &sCollisions[sPostures[(s8)p->motion.cmdIdx]]);
      break;
    case 4:
      SetDDP(&p->body, &sCollisions[7]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x08));
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        register u8 f asm("r1");
        register s32 md asm("r0");
        f = *((u8*)p + 0xbf);
        if (f != 0) {
          f = 0;
          md = 5;
        } else {
          md = 0xB;
        }
        p->mode[1] = md;
        p->mode[2] = f;
      }
      break;
  }
}

void deathtanzMode11(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 bx asm("r3");
      register s32 v asm("r0");
      register s32 tx asm("r2");
      register s32 dx asm("r1");
      s32 dy, dist, nx, ny;
      SetDDP(&p->body, &sCollisions[12]);
      bx = *(s32*)((u8*)p + 0xb4);
      v = bx + -0x5400;
      p->d.x = v;
      tx = v;
      if (p->flags & 0x10) {
        tx = bx + 0x5400;
      }
      dx = tx - p->coord.x;
      p->d.x = dx;
      {
        s32 by = *(s32*)((u8*)p + 0xb8);
        s32 k = -0x6800;
        asm("" : "+r"(k));
        by += k;
        dy = by - p->coord.y;
      }
      p->d.y = dy;
      dx >>= 8;
      dist = dx * dx;
      dy >>= 8;
      dist += dy * dy;
      dist = Sqrt(dist) << 8;
      nx = (p->d.x << 8) / dist;
      p->d.x = nx;
      ny = (p->d.y << 8) / dist;
      p->d.x = nx << 3;
      p->d.y = ny << 3;
      {
        register s32 q asm("r0");
        asm volatile("add %0, %1, #0" : "=&l"(q) : "l"(dist));
        p->work[2] = q >> 11;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0A));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 t;
      p->coord.x += p->d.x;
      p->coord.y += p->d.y;
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t == 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2: {
      register s32 one asm("r2");
      s32 bx;
      SetDDP(&p->body, &sCollisions[35]);
      {
        register s32 xf0 asm("r0");
        xf0 = p->flags >> 4;
        one = 1;
        xf0 ^= one;
        asm("" : "+r"(xf0));
        xf0 &= one;
        (p->spr).xflip = xf0;
      }
      {
        register s32 xf asm("r1");
        register u8* oa asm("r4");
        s32 sh4, ov, m11;
        xf = p->flags >> 4;
        xf ^= one;
        asm("" : "+r"(xf));
        xf &= one;
        oa = (u8*)p + 0x4a;
        sh4 = xf << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
        if (xf != 0) {
          p->flags |= 0x10;
        } else {
          register u8 h asm("r1");
          register u8 g asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g = 0xEF;
          g &= h;
          p->flags = g;
        }
      }
      {
        s32* bp = (s32*)((u8*)p + 0xb4);
        s32 cx = p->coord.x;
        s32 nx;
        bx = *bp;
        if (cx < bx) {
          nx = bx + -0x5400;
        } else {
          register s32 k2 asm("r2");
          k2 = 0xA8 * 128;
          asm("" : "+r"(k2));
          nx = bx + k2;
        }
        p->coord.x = nx;
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0C));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        u8* q = (u8*)p + 0xbf;
        s32 z0 = 0;
        s32 one = 1;
        *q = one;
        p->mode[1] = 0xA;
        p->mode[2] = z0;
      }
      break;
  }
}

void deathtanzMode12(struct Boss* p) {
  register s32 z asm("r5");
  z = p->mode[2];
  switch (z) {
    case 0:
      if ((u32)((p->coord.x - *(s32*)((u8*)p + 0xb4)) + 0xC8 * 64) > 0xC8 * 128) {
        p->mode[1] = 2;
        p->mode[2] = z;
        UpdateEntityAnim((struct Entity*)p);
        break;
      }
      SetDDP(&p->body, &sCollisions[60]);
      *((u8*)p + 0xbe) = z;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0D));
      p->work[2] = z;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx == 6) {
        register s32 w asm("r5");
        w = p->work[2];
        if (w == 0) {
          register s32 one asm("r6");
          register s32 x asm("r1");
          register s32 cx asm("r2");
          register u32 fl asm("r3");
          s32 y;
          one = 1;
          p->work[2] = one;
          PlaySound(0x5D);
          cx = p->coord.x;
          x = cx - 0x3700;
          fl = p->flags;
          if (fl & 0x10) {
            x = cx + 0x3700;
          }
          y = p->coord.y - 0x3200;
          ((void (*)(struct Entity*, s32, s32, s32, s32))deathtanz_080a0934)((struct Entity*)p, x, y, (fl >> 4) & one, w);
          *((u8*)p + 0xc1) &= 0xFD;
        }
      }
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 2: {
      u32 rv = (RNG_0202f388 * 0x343FD + 0x269EC3) << 1;
      u32 b;
      asm("" : "+r"(rv));
      RNG_0202f388 = rv >> 1;
      b = (rv >> 0x11) & 1;
      p->work[2] = b * 18 + 0x3C;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0E));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      s32 t = p->work[2] - 1;
      p->work[2] = t;
      if ((u8)t == 0) {
        p->mode[1] = 0xD;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void deathtanzMode13(struct Boss* p) {
  register s32 m asm("r5");
  m = p->mode[2];
  switch (m) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x0F));
      p->work[2] = m;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx == 5 && p->work[2] == 0) {
        register s32 one asm("r5");
        register s32 x asm("r1");
        register s32 cx asm("r2");
        register u32 fl asm("r3");
        s32 y;
        one = 1;
        p->work[2] = one;
        PlaySound(0x5D);
        cx = p->coord.x;
        x = cx - 0x3700;
        fl = p->flags;
        if (fl & 0x10) {
          x = cx + 0x3700;
        }
        y = p->coord.y - 0x3200;
        ((void (*)(struct Entity*, s32, s32, s32, s32))deathtanz_080a0934)((struct Entity*)p, x, y, (fl >> 4) & one, one);
        *((u8*)p + 0xc1) &= 0xFE;
      }
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x10));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0xbe) != 0) {
        p->mode[1] = 0xE;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzMode14(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register u8* c1 asm("r3");
      register u8 fv asm("r1");
      register u8 g asm("r0");
      register s32 z asm("r2");
      c1 = (u8*)p + 0xc1;
      fv = *c1;
      g = 2;
      z = 0;
      g |= fv;
      *c1 = g;
      *((u8*)p + 0xbe) = z;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x11));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      goto inc;
    case 2:
      SetDDP(&p->body, &sCollisions[62]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x13));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (*((u8*)p + 0xbe) == 0) {
        break;
      }
    inc:
      p->mode[2]++;
      break;
    case 4: {
      register u8* c2 asm("r2");
      register u8 fv2 asm("r1");
      register u8 g2 asm("r0");
      c2 = (u8*)p + 0xc1;
      fv2 = *c2;
      g2 = 1;
      g2 |= fv2;
      *c2 = g2;
      SetDDP(&p->body, &sCollisions[60]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x15));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 5;
        p->mode[2] = 0;
      }
      break;
  }
}

void deathtanzMode15(struct Boss* p) {
  u8 m = p->mode[2];
  switch (m) {
    case 0:
      PlaySound(0x5C);
      SetDDP(&p->body, &sCollisions[1]);
      *(u8*)((u8*)p + 0xbe) = m;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x16));
      p->mode[2]++;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) == 3) {
        u8 z = 0;
        p->mode[1] = 0x10;
        p->mode[2] = z;
      }
      break;
  }
}

void deathtanzMode16(struct Deathtanz* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 x;
      s32 y;
      u32 fl;
      u8 dir;
      SetDDP(&p->body, &sCollisions[65]);
      x = p->coord.x - 0x800;
      fl = p->flags;
      if (X_FLIP & fl) {
        x = p->coord.x + 0x800;
      }
      y = p->coord.y - 0x2600;
      dir = (fl >> 4) & 1;
      deathtanz_080a09a0((struct Entity*)p, x, y, dir);
      p->unk_c1 &= ~1;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x18));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->unk_be == 0) {
        break;
      }
      goto inc;
    case 2:
      p->unk_c1 |= 1;
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x1A));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
    inc:
      p->mode[2]++;
      break;
    case 4:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x1B));
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        u8 z = 0;
        p->mode[1] = 5;
        p->mode[2] = z;
      }
      break;
  }
}

void deathtanzEX1(struct Deathtanz* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 side asm("r4");
      s32 t;
      s32 px;
      s32 base;
      struct Zero* z0;
      p->unk_c0 = 3;
      p->work[2] = 0;
      t = 0;
      z0 = pZero2;
      px = p->coord.x;
      if (px < (z0->s).coord.x) {
        t = 1;
      }
      asm volatile("add %0, %1, #0" : "=&l"(side) : "l"(t));
      base = p->unk_b4.x;
      if ((u32)(px - base + 0x2800) > 0x5000) {
        s32 s2 = 0;
        if (px < base) {
          s2 = 1;
        }
        if (side != s2) {
          u8 one = 1;
          p->mode[1] = one;
          p->mode[2] = one;
          p->work[2] = one;
          UpdateEntityAnim((struct Entity*)p);
          return;
        }
      }
      if (p->flags & X_FLIP) {
        if (side != 0) {
          p->mode[2] = 2;
          break;
        }
      } else {
        if (side == 0) {
          p->mode[2] = 2;
          break;
        }
      }
      SetDDP(&p->body, &sCollisions[4]);
      p->work[2] = 1;
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x07));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) == 3) {
        p->mode[2]++;
      }
      break;
    case 2:
      SetDDP(&p->body, &sCollisions[68]);
      if (p->work[2] != 0) {
        u32 v;
        p->spr.xflip = ((p->flags >> 4) ^ 1) & 1;
        v = ((p->flags >> 4) ^ 1) & 1;
        {
          register s32 ov asm("r2");
          u8* oa = (u8*)p + 0x4a;
          s32 sh4 = v << 4;
          s32 m11;
          ov = *oa;
          m11 = -0x11;
          m11 &= ov;
          *oa = m11 | sh4;
        }
        if (v != 0) {
          p->flags |= X_FLIP;
        } else {
          p->flags &= ~X_FLIP;
        }
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x27));
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 4:
      PlaySound(0x5F);
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 5:
      deathtanz_080a09f4((struct Entity*)p, p->coord.x, p->coord.y - 0x4900, p->work[2],
                         (p->flags >> 4) & 1);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x29));
      p->mode[2]++;
      FALLTHROUGH;
    case 6:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) != 3) {
        break;
      }
      {
        s32 w = p->work[2] + 1;
        p->work[2] = w;
        if ((u8)w <= 2) {
          goto setmode5;
        }
      }
      p->mode[2]++;
      break;
    setmode5:
      p->mode[2] = 5;
      break;
    case 7:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x2A));
      p->work[2] = 0x5a;
      p->mode[2]++;
      FALLTHROUGH;
    case 8:
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 w = p->work[2] - 1;
        u8 wb;
        p->work[2] = w;
        wb = w;
        if (wb == 0) {
          p->mode[1] = 0x12;
          p->mode[2] = wb;
        }
      }
      break;
  }
}

void deathtanzEX2(struct Boss* p) {
  register s32 one asm("r4");
  register s32 ax asm("r0");
  register s32 ay asm("r1");
  register s32 k asm("r2");
  register s32 fl asm("r3");
  register s32 k2 asm("r2");
  register s32 fl2 asm("r3");
  switch (p->mode[2]) {
    case 0:
      SetDDP(&p->body, &sCollisions[1]);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x2B));
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx != 4) {
        goto stchk;
      }
      if (p->work[2] != 0) {
        goto stchk;
      }
      PlaySound(0x5D);
      {
        register u8* a asm("r1");
        register s32 v asm("r0");
        a = (u8*)p + 0xc0;
        v = 2;
        *a = v;
      }
      goto shot0;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x2D));
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx != 4) {
        goto stchk;
      }
      if (p->work[2] != 0) {
        goto stchk;
      }
      {
        u8* a3 = (u8*)p + 0xc0;
        one = 1;
        *a3 = one;
      }
      PlaySound(0x5D);
      ax = p->coord.x;
      ay = p->coord.y;
      fl = p->flags >> 4;
      fl &= one;
      k = 1;
      goto docall;
    }
    case 4:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x2F));
      p->work[2] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 5: {
      register s32 w asm("r1");
      UpdateEntityAnim((struct Entity*)p);
      if ((s8)p->motion.cmdIdx != 4) {
        goto stchk;
      }
      w = p->work[2];
      if (w != 0) {
        goto stchk;
      }
      *((u8*)p + 0xc0) = w;
      PlaySound(0x5D);
    shot0:
      ax = p->coord.x;
      ay = p->coord.y;
      fl2 = p->flags >> 4;
      k2 = 1;
      fl2 &= k2;
      k2 = 0;
    docall:
      ((void (*)(s32, s32, s32, s32))FUN_080a0888)(ax, ay, k2, fl2);
    stchk:
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    }
    case 6:
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x31));
      p->mode[2]++;
      FALLTHROUGH;
    case 7:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        s32 z0 = 0;
        p->mode[1] = 5;
        p->mode[2] = z0;
      }
      break;
  }
}

void deathtanzKnockBackDamage(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 dx, dy, dist, nx, ny;
      PlaySound(0x60);
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x36));
      dx = p->coord.x - *(s32*)((u8*)p + 0xc8);
      p->d.x = dx;
      dy = p->coord.y - 0x3000;
      dy -= *(s32*)((u8*)p + 0xcc);
      p->d.y = dy;
      dist = (dx >> 8) * (dx >> 8);
      dist += (dy >> 8) * (dy >> 8);
      dist = Sqrt(dist) << 8;
      nx = (p->d.x << 8) / dist;
      p->d.x = nx;
      ny = (p->d.y << 8) / dist;
      p->d.y = ny;
      p->d.x = nx * 1152 / 256;
      p->d.y = ny * 1152 / 256;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 r asm("r6");
      s32 x, bx, ny;
      x = p->coord.x + p->d.x;
      p->coord.x = x;
      bx = *(s32*)((u8*)p + 0xb4);
      if (x > bx + 0x5000) {
        p->coord.x = bx + 0x5000;
      } else if (x < bx - 0x5000) {
        p->coord.x = bx - 0x5000;
      }
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      ny = p->coord.y + p->d.y;
      p->coord.y = ny;
      if (p->d.y > 0) {
        r = PushoutToUp1(p->coord.x, ny);
        if (r < 0) {
          p->coord.y += r;
          p->mode[1] = 5;
          p->mode[2] = 0;
        }
      } else {
        r = PushoutToDown1(p->coord.x, ny - 0x2000);
        if (r < 0) {
          p->coord.y += r;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void deathtanzMode19(struct Boss* p) {
  struct Entity* e = p->unk_28;
  register s32 m asm("r1");
  m = p->mode[2];
  switch (m) {
    case 0: {
      s32 k10;
      register s32 z6 asm("r6");
      {
        register u8 f2 asm("r0");
        f2 = p->flags2;
        k10 = 0x10;
        asm("" : "+r"(k10));
        z6 = 0;
        f2 |= k10;
        p->flags2 = f2;
      }
      p->invincibleID = e->uniqueID;
      {
        u8* a = (u8*)p + 0x8c;
        *(s32*)a = m;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = m;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = m;
      }
      p->flags &= ~4;
      {
        register s32 one asm("r2");
        register s32 xv asm("r1");
        u32 t0 = e->flags;
        t0 >>= 4;
        one = 1;
        t0 &= one;
        (p->spr).xflip = t0;
        xv = (u32)e->flags >> 4;
        xv &= one;
        {
          register u8* oa asm("ip");
          s32 sh4, ov, m11;
          oa = (u8*)p + 0x4a;
          sh4 = xv << 4;
          ov = *oa;
          m11 = -0x11;
          m11 &= ov;
          m11 |= sh4;
          *oa = m11;
        }
        if (xv != 0) {
          register u8 g asm("r0");
          g = p->flags;
          g |= k10;
          p->flags = g;
        } else {
          register u8 h asm("r1");
          register u8 g2 asm("r0");
          h = p->flags;
          asm("" : "+r"(h));
          g2 = 0xEF;
          g2 &= h;
          p->flags = g2;
        }
      }
      SetMotion((struct Entity*)p, 0xA739);
      p->mode[2]++;
      asm volatile("" : "+l"(z6));
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx asm("r1");
      {
        s32 cx = p->coord.x;
        dx = p->d.x;
        p->coord.x = cx + dx;
      }
      {
        register s32 k asm("r0");
        if (p->work[3] != 0) {
          k = 0xF6;
        } else {
          k = 0xFA;
        }
        p->d.x = dx * k / 256;
      }
      FUN_0801779c((struct Entity*)p);
      if (e->mode[0] == 4) {
        register u8 g asm("r0");
        register u8 h asm("r1");
        register s32 zr asm("r2");
        u8* a;
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xFE;
        g &= h;
        zr = 0;
        h = 0xFD;
        g &= h;
        p->flags = g;
        a = (u8*)p + 0x8c;
        *(s32*)a = zr;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = zr;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = zr;
        p->flags &= ~4;
        SET_BOSS_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void FUN_0804ac44(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 hit asm("r5");
      register u8* f asm("r6");
      struct Coord c;
      hit = 0;
      {
        register u8* t asm("r2");
        register s32 b1 asm("r0");
        t = (u8*)p + 0xc1;
        {
          register s32 tv asm("r1");
          tv = *t;
          b1 = 1;
          b1 &= tv;
        }
        f = t;
        if (b1 == 0) {
          goto skip1;
        }
      }
      {
        register s32 cx asm("r3");
        register s32 v0 asm("r0");
        register s32 v asm("r2");
        hit = 1;
        cx = p->coord.x;
        v0 = cx + 0xFFFFD600;
        c.x = v0;
        v = v0;
        if ((p->flags & 0x10) != 0) {
          register s32 k asm("r0");
          k = 0xb0 << 6;
          v = cx + k;
        }
        c.x = v;
        c.y = p->coord.y + 0xFFFFE700;
        CreateSmoke(1, &c);
        FUN_080bdb44(c.x, c.y);
      }
    skip1:
      if ((*f & 2) != 0) {
        hit = 1;
        c.x = p->coord.x;
        c.y = p->coord.y + 0xFFFFB400;
        CreateSmoke(1, &c);
        FUN_080bdb44(c.x, c.y);
      }
      if (hit != 0) {
        PlaySound(0x2A);
      }
      {
        u8* a = (u8*)p + 0x8c;
        s32 z = 0;
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      p->flags &= 0xFB;
      InitNonAffineMotion((struct Entity*)p);
      ResetDynamicMotion((struct Entity*)p);
      {
        register u16 ms asm("r2");
        ms = gStageRun.missionStatus;
        hit = 1;
        if ((hit & ms) != 0) {
          register s32 av asm("r1");
          register s32 t2 asm("r0");
          av = gStageRun.vm.active;
          t2 = hit;
          t2 &= av;
          if (t2 == 0) {
            gStageRun.missionStatus = (ms & 0xFFFE) | 0x10;
          }
        }
      }
      p->work[2] = 0x50;
      SetMotion((struct Entity*)p, 0xA737);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      p->work[2] = p->work[2] - 1;
      if ((p->scriptEntity->flags & 0x80) == 0) {
        break;
      }
      goto adv;
    case 2:
      p->unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)sExplosionCoords);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if (((struct Entity*)p->unk_2c)->mode[0] <= 1) {
        break;
      }
      gStageRun.vm.active |= 2;
    adv:
      p->mode[2]++;
      break;
    case 4:
      break;
  }
}

void deathtanz_0804adb0(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 dir asm("r6");
      register s32 snd asm("r6");
      u8* c1;
      struct Coord c;
      struct Entity* e;
      snd = 0;
      {
        register u8* a asm("r2");
        u8 f;
        a = (u8*)p + 0xc1;
        f = *a & 1;
        asm volatile("add %0, %1, #0" : "=&l"(c1) : "l"(a));
        if (f != 0) {
          s32 bx;
          s32 x0;
          s32 x;
          snd = 1;
          bx = p->coord.x;
          x0 = bx - 0x2A00;
          c.x = x0;
          asm volatile("add %0, %1, #0" : "=&l"(x) : "l"(x0));
          if ((p->flags & X_FLIP) != 0) {
            x = bx + (0xb0 << 6);
          }
          c.x = x;
          c.y = p->coord.y - 0x1900;
          CreateSmoke(1, &c);
          FUN_080bdb44(c.x, c.y);
        }
      }
      if ((*c1 & 2) != 0) {
        snd = 1;
        c.x = p->coord.x;
        c.y = p->coord.y - 0x4C00;
        CreateSmoke(1, &c);
        FUN_080bdb44(c.x, c.y);
      }
      if (snd != 0) {
        PlaySound(0x2a);
      }
      PlaySound(0x2f);
      dir = *((u8*)p + 0xc2);
      e = AllocEntityLast(gBossHeaderPtr);
      if (e != NULL) {
        register s32 z asm("r2");
        register s32 z0 asm("r0");
        {
          register u8* tc asm("r1");
          tc = (u8*)e + 0x25;
          z = 0;
          z0 = 0x18;
          *tc = z0;
        }
        {
          register const BossFunc** tb asm("r1");
          tb = (const BossFunc**)gBossFnTable;
          e->id = 7;
          e->onUpdate = (void*)tb[7][0];
        }
        z0 = 0;
        *(u16*)((u8*)e + 0x20) = z;
        *((u8*)e + 0x22) = z0;
        {
          register s32 h asm("r1");
          register s32 g asm("r0");
          h = e->flags2;
          asm("" : "+r"(h));
          g = 0x10;
          g |= h;
          e->flags2 = g;
        }
        *((u8*)e + 0x1d) = *((u8*)e + 0x1c);
        e->coord.x = p->coord.x;
        e->coord.y = p->coord.y;
        {
          register s32 v asm("r0");
          register s32 sh asm("r1");
          v = 0x80 << 1;
          sh = dir << 9;
          v -= sh;
          e->d.x = v;
        }
        e->unk_28 = (struct Entity*)p;
        {
          register s32 one asm("r1");
          register s32 fv asm("r0");
          one = 1;
          *((u8*)e + 0x10) = one;
          fv = (u32)p->flags >> 4;
          fv &= one;
          fv ^= dir;
          *((u8*)e + 0x13) = fv;
        }
      }
      SetMotion((struct Entity*)p, MOTION(0xA7, 0x38));
      {
        register u8* a asm("r0");
        register s32 z1 asm("r1");
        a = (u8*)p + 0x8c;
        z1 = 0;
        asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        asm volatile("str %0, [%1]" ::"l"(z1), "l"(a) : "memory");
        a += 4;
        asm("" : "+r"(a));
        *a = z1;
      }
      {
        register u8 h2 asm("r1");
        register u8 g2 asm("r0");
        h2 = p->flags;
        asm("" : "+r"(h2));
        g2 = 0xFB;
        g2 &= h2;
        p->flags = g2;
      }
      if ((gStageRun.missionStatus & 1) != 0) {
        if ((*((u8*)&gStageRun + 0x12) & 1) == 0) {
          gStageRun.missionStatus = (gStageRun.missionStatus & 0xFFFE) | 0x10;
        }
      }
      {
        register s32 v2 asm("r0");
        register s32 sh2 asm("r1");
        v2 = 0x80 << 1;
        sh2 = dir << 9;
        v2 -= sh2;
        p->d.x = v2;
      }
      {
        c.x = p->coord.x;
        c.y = p->coord.y - 0x2000;
        ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c, 0x80 << 2, dir);
      }
      p->work[2] = 0x32;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dv asm("r2");
      register s32 dir2 asm("r3");
      p->coord.x += p->d.x;
      dv = p->d.x;
      dir2 = *((u8*)p + 0xc2);
      {
        register s32 m asm("r0");
        if ((p->flags & 0x10) != 0) {
          if (dir2 != 1) {
            goto fast;
          }
          goto slow;
        } else {
          if (dir2 == 0) {
            goto slow;
          }
        fast:
          m = 0xfa;
          goto mul;
        }
      slow:
        m = 0xf6;
      mul:
        m = dv * m;
        if (m < 0) {
          m += 0xff;
        }
        p->d.x = m >> 8;
      }
      p->work[2]--;
      if ((p->scriptEntity->flags & 0x80) != 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)&sExplosionCoords[1]);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if (((struct Entity*)p->unk_2c)->mode[0] <= 1) {
        break;
      }
      {
        register struct StageRun* sr2 asm("r2");
        register s32 g3 asm("r0");
        register s32 h3 asm("r1");
        sr2 = &gStageRun;
        h3 = *((u8*)sr2 + 0x12);
        asm("" : "+r"(h3));
        g3 = 2;
        g3 |= h3;
        *((u8*)sr2 + 0x12) = g3;
      }
      p->mode[2]++;
      break;
    case 4:
      break;
  }
}

// --------------------------------------------

// 0x083627dc
static const struct Collision sCollisions[71] = {
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
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0100, -0x2B00, 0x2400, 0x1F00},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0600, -0x1500, 0x3400, 0x2400},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1300, 0x3B00},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2000, 0x1700, 0x3E00},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2A00, 0x4900, 0x1900},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x2000, 0x1700, 0x3E00},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0900, -0x1A00, 0x2F00, 0x3700},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0800, -0x1500, 0x2800, 0x2400},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0500, -0x3400, 0x2C00, 0x1A00},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x1300, 0x2F00, 0x2700},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0200, -0x1C00, 0x1C00, 0x3A00},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x3300, 0x1A00, 0x1400},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0200, -0x2A00, 0x1300, 0x5100},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0200, -0x2B00, 0x1300, 0x5100},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2A00, 0x1B00, 0x5100},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1200, -0x2E00, 0x1A00, 0x1400},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2A00, 0x1B00, 0x5100},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0300, -0x1C00, 0x2400, 0x3300},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x1F00, -0x1B00, 0x3400, 0x0F00},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1B00, 0x1500, 0x3500},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0600, -0x2B00, 0x1B00, 0x4400},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0A00, -0x4000, 0x2400, 0x1B00},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x2A00, 0x1400, 0x4C00},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x1C00, 0x2400, 0x1000},
    },
    [26] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [27] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [29] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0C00, -0x2C00, 0x2400, 0x1000},
    },
    [30] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [31] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [32] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0700, -0x2B00, 0x1B00, 0x4400},
    },
    [33] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {0x0900, -0x1500, 0x1200, 0x2900},
    },
    [34] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0600, -0x2F00, 0x1400, 0x3100},
    },
    [35] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0A00, -0x2600, 0x1000, 0x4800},
    },
    [36] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0500, -0x1B00, 0x2C00, 0x1000},
    },
    [37] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 1,
      range : {-0x0200, -0x3600, 0x1500, 0x1F00},
    },
    [38] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0A00, -0x1900, 0x1100, 0x2E00},
    },
    [39] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x3600, 0x2C00, 0x1000},
    },
    [41] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [42] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [43] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0700, -0x3000, 0x2C00, 0x1000},
    },
    [44] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [45] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x2C00, 0x1000, 0x5600},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x2100, -0x5300, 0x0B00, 0x3300},
    },
    [47] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0100, -0x2C00, 0x1100, 0x5600},
    },
    [48] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [49] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0300, -0x5A00, 0x3600, 0x3400},
    },
    [50] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [51] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [52] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x3300, -0x5A00, 0x3600, 0x3400},
    },
    [53] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [55] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x3300, -0x2600, 0x3600, 0x3400},
    },
    [56] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [57] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1C00, -0x1700, 0x0800, 0x3400},
    },
    [59] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0400, -0x2600, 0x1000, 0x5600},
    },
    [60] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0B00, -0x1F00, 0x2400, 0x4000},
    },
    [61] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0C00, -0x1C00, 0x1300, 0x3B00},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0500, -0x3100, 0x1E00, 0x1B00},
    },
    [63] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0300, -0x1200, 0x3A00, 0x2600},
    },
    [64] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0C00, -0x1C00, 0x1300, 0x3B00},
    },
    [65] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x0A00, 0x2E00, 0x1800},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2100, 0x0F00, 0x4500},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x0300, -0x1D00, 0x1300, 0x3B00},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x1000, 0x3200, 0x2300},
    },
    [69] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x2300, 0x1100, 0x4800},
    },
    [70] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x05,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x1A00, 0x1900, 0x3700},
    },
};

static const u8 sDeathtanzModes[32] = {
    2, 2, 2, 2, 2, 2, 2, 2, 12, 12, 12, 12, 17, 17, 17, 17, 2, 2, 2, 2, 2, 2, 12, 12, 15, 15, 15, 15, 17, 17, 17, 17,
};

static const u8 sInitModes[2] = {0, 19};

// 0x08362ea6
static const u8 u8_ARRAY_08362ea6[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3,
};

// 0x08362eb6
static const u8 sPostures[14] = {
    39, 39, 42, 42, 45, 45, 48, 51, 54, 57, 57, 57, 57, 0,
};

// 0x08362ec4
static const Coords32 sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(35)},
    {PIXEL(0), -PIXEL(35)},
};
