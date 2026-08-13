#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"
#include "physics.h"
#include "physics.h"
#include "zero.h"

struct Projectile* FUN_080a374c(struct Entity* e, struct Coord* c, u8 a2);
struct Projectile* tretista_080a369c(struct Entity* e, struct Coord* c, u8 a2);
struct Projectile* tretista_080a36f4(struct Entity* e, struct Coord* c, u8 a2);

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4;             // 0xB4
  s8 unk_b5[2];          // 0xB5
  u8 unk_b7;             // 0xB7
  u8 unk_b8[8];          // 0xB8
  void* unk_c0;          // 0xC0
  u8 unk_c4[20];         // 0xC4
  u8 unk_d8;             // 0xD8
  u8 unk_d9[11];         // 0xD9
} Tretista;
static_assert(sizeof(Tretista) == sizeof(Boss));

static const struct Collision sCollisions[13];

static void Tretista_Init(Tretista* p);
static void Tretista_Update(Tretista* p);
static void Tretista_Die(Tretista* p);

// clang-format off
const BossRoutine gTretistaRoutine = {
    [ENTITY_INIT] =      (void*)Tretista_Init,
    [ENTITY_UPDATE] =    (void*)Tretista_Update,
    [ENTITY_DIE] =       (void*)Tretista_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Tretista* Unused_CreateTretista(Coords32* c, u8 n) {
  Tretista* p = (Tretista*)AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_TRETISTA);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

NAKED static void Tretista_Init(Tretista* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r6, #0\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r6, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _0804D710 @ =sCollisions\n\
	adds r0, r5, #0\n\
	movs r2, #0x60\n\
	bl ResetBossBody\n\
	ldr r1, _0804D714 @ =FUN_0804fdf8\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x40\n\
	strb r6, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0xc0\n\
	str r6, [r0]\n\
	subs r0, #9\n\
	strb r6, [r0]\n\
	adds r0, #0x21\n\
	movs r7, #1\n\
	strb r7, [r0]\n\
	subs r0, #0x14\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	adds r0, #4\n\
	str r6, [r0]\n\
	adds r0, #0xd\n\
	strb r6, [r0]\n\
	adds r0, #9\n\
	strb r6, [r0]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0xd4\n\
	str r1, [r0]\n\
	str r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	bl FUN_0800a134\n\
	adds r4, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r4, #0\n\
	bl FUN_0800a31c\n\
	adds r1, r5, #0\n\
	adds r1, #0xd0\n\
	str r0, [r1]\n\
	ldr r0, [r5, #0x54]\n\
	adds r1, r4, #0\n\
	bl FUN_0800a22c\n\
	adds r1, r5, #0\n\
	adds r1, #0xdc\n\
	str r0, [r1]\n\
	subs r1, #0x24\n\
	ldr r0, [r5, #0x54]\n\
	ldr r2, _0804D718 @ =0xFFFF9000\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _0804D720\n\
	ldr r1, _0804D71C @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r6, [r5, #0xd]\n\
	b _0804D734\n\
	.align 2, 0\n\
_0804D710: .4byte sCollisions\n\
_0804D714: .4byte FUN_0804fdf8\n\
_0804D718: .4byte 0xFFFF9000\n\
_0804D71C: .4byte gBossFnTable\n\
_0804D720:\n\
	ldr r1, _0804D750 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r7, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r5, #0xd]\n\
_0804D734:\n\
	strb r6, [r5, #0xe]\n\
	strb r6, [r5, #0xf]\n\
	movs r0, #0\n\
	strb r0, [r5, #0x11]\n\
	adds r1, r5, #0\n\
	adds r1, #0xe1\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	bl Tretista_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0804D750: .4byte gBossFnTable\n\
   .syntax divided\n");
}

static bool8 FUN_0804dc8c(Tretista* p);
bool8 FUN_0804df70(Tretista* p);
bool8 FUN_0804e01c(Tretista* p);
bool8 FUN_0804e08c(Tretista* p);
bool8 FUN_0804e3f0(Tretista* p);
bool8 FUN_0804e544(Tretista* p);
bool8 FUN_0804eb38(Tretista* p);
bool8 FUN_0804f2b4(Tretista* p);
bool8 FUN_0804f5c0(Tretista* p);
bool8 FUN_0804f7d8(Tretista* p);
bool8 FUN_0804fc6c(Tretista* p);
bool8 FUN_0804e8f4(Tretista* p);

void tretista_0804dc90(Tretista* p);
void tretista_0804df74(Tretista* p);
void tretista_0804e020(Tretista* p);
void tretistaNeutral(Tretista* p);
void tretista_0804e3f4(Tretista* p);
void tretista_0804e548(Tretista* p);
void tretistaPipeThrow(Tretista* p);
void tretistaHellBouncers(Tretista* p);
void tretistaBreathGas(Tretista* p);
void tretistaLaserCraw(Tretista* p);
void tretista_0804fc70(Tretista* p);
void FUN_0804e8f8(Tretista* p);

static void Tretista_Update(Tretista* p) {
  // clang-format off
  static bool8 (*const sUpdates1[12])(Tretista*) = {
      FUN_0804dc8c,
      FUN_0804df70,
      FUN_0804e01c,
      FUN_0804e08c,
      FUN_0804e3f0,
      FUN_0804e544,
      FUN_0804eb38,
      FUN_0804f2b4,
      FUN_0804f5c0,
      FUN_0804f7d8,
      FUN_0804fc6c,
      FUN_0804e8f4,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[12])(Tretista*) = {
      (void*)tretista_0804dc90,
      (void*)tretista_0804df74,
      (void*)tretista_0804e020,
      (void*)tretistaNeutral,
      (void*)tretista_0804e3f4,
      (void*)tretista_0804e548,
      (void*)tretistaPipeThrow,
      (void*)tretistaHellBouncers,
      (void*)tretistaBreathGas,
      (void*)tretistaLaserCraw,
      (void*)tretista_0804fc70,
      (void*)FUN_0804e8f8,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    PlaySound(SE_TRETISTA_DEATH);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[3] = 1;
    } else {
      p->mode[3] = 0;
    }
    Tretista_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

static void FUN_0804d804(Tretista* p);
static void tretista_0804d8e8(Tretista* p);

static void Tretista_Die(Tretista* p) {
  static void (*const sDeads[2])(Tretista*) = {
      FUN_0804d804,
      tretista_0804d8e8,
  };
  (sDeads[p->mode[1]])((void*)p);
}

static void FUN_0804d804(Tretista* p) {
  StepPaletteAnimation(73);
  StepPaletteAnimation(74);
  StepPaletteAnimation(75);
  StepPaletteAnimation(76);

  switch (p->mode[2]) {
    case 0: {
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & VM_ACTIVE)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      SetSpriteAnimation(p, MOTION(DM171_TRETISTA, 37));
      p->flags |= DISPLAY;
      (p->spr).yflip = FALSE, (p->spr).oam.yflip = FALSE;
      p->flags &= ~Y_FLIP;
      EXIT_BODY(p);
      (&p->d)->x = (&p->d)->y = 0;
      p->work[2] = 1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (p->work[2] > 0 && --(p->work[2]) == 0) p->mode[2]++;
      break;
    }
    case 2: {
      p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

NAKED static void tretista_0804d8e8(Tretista* p) { INCCODE("asm/wip/tretista_0804d8e8.inc"); }

static bool8 FUN_0804dc8c(Tretista* p) { return TRUE; }

INCASM("asm/boss/tretista_a.inc");

void tretista_0804e548(Tretista* p) {
  s32 zx;
  s32 w;
  u32 fl2;
  s32 r;
  s32 nx;
  s32 ny;
  u8 m3 = p->mode[3];
  if (m3 == 0 || m3 == 2) {
    switch (p->mode[2]) {
      case 0:
        SetSpriteAnimation(p, 0xAB0C);
        SetDDP(&p->body, &sCollisions[1]);
        zx = (pZero2->s).coord.x;
        if (p->mode[3] != 2) {
          if (!(p->flags & 0x10)) {
            s32 px = p->coord.x;
            asm("" : "+r"(px));
            if (zx > px) {
              goto Lt1;
            }
            goto skipturn;
          Lt1:
            asm volatile("");
            goto turn;
          }
          goto setchk;
        }
        w = 0;
        goto setw;
      case 1:
        goto lab1;
      case 2:
        UpdateEntityAnim((struct Entity*)p);
        if (p->motion.state == 3) {
          u8 v;
          (p->spr).xflip = (p->flags >> 4 ^ 1) & 1;
          v = (p->flags >> 4 ^ 1) & 1;
          (p->spr).oam.xflip = v;
          asm("" : "+r"(v));
          if (v != 0) {
            register u32 blk asm("r1");
            register u32 tv asm("r0");
            tv = p->flags;
            blk = 0x10;
            asm("" : "+r"(blk));
            tv |= blk;
            fl2 = tv;
          } else {
          clearA2:
            {
              register u32 av asm("r1");
              av = p->flags;
              asm("" : "+r"(av));
              fl2 = 0xEF;
              fl2 &= av;
            }
          }
        storeA2:
          p->flags = fl2;
          goto bump;
        }
        break;
      case 3:
      lab3:
        SetSpriteAnimation(p, 0xAB0C);
        SetDDP(&p->body, &sCollisions[1]);
        p->mode[2]++;
        FALLTHROUGH;
      case 4:
      lab4:
        UpdateEntityAnim((struct Entity*)p);
        if (p->motion.state != 3) {
          break;
        }
        goto bump;
      case 5:
        SetSpriteAnimation(p, 0xAB0D);
        p->work[3] = 0;
        p->mode[2]++;
        FALLTHROUGH;
      case 6: {
        s32 dy = p->d.y;
        dy += 0x20;
        p->d.y = dy;
        nx = p->coord.x + p->d.x;
        p->coord.x = nx;
        ny = p->coord.y + dy;
        p->coord.y = ny;
        if (!(p->d.x > 0)) {
          goto push_right;
        }
        r = PushoutToLeft1(nx + 0x2800, ny);
        goto push_tail;
      }
      case 7:
        SetDDP(&p->body, &sCollisions[1]);
        SetSpriteAnimation(p, 0xAB0F);
        p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x1000);
        PlaySound(0xDE);
        p->mode[2]++;
        FALLTHROUGH;
      case 8:
        UpdateEntityAnim((struct Entity*)p);
        if (p->motion.state == 3) {
          p->mode[1] = 3;
          p->mode[2] = 0;
        }
        break;
    }
  } else {
    switch (p->mode[2]) {
      case 0: {
        s32 k;
        SetSpriteAnimation(p, 0xAB0C);
        SetDDP(&p->body, &sCollisions[1]);
        zx = (pZero2->s).coord.x;
        if (zx > p->coord.x) {
          zx += -0x8700;
        } else {
          zx += 0x8700;
        }
        if (p->flags & 0x10) {
          goto setchk;
        }
        if (zx <= p->coord.x) {
          goto skipturn;
        }
        goto turn;
      setchk:
        if (zx < p->coord.x) {
        turn:
          SetSpriteAnimation(p, 0xAB0B);
          w = 1;
        setw:
          p->work[3] = w;
        }
      skipturn:
        p->work[2] = 0x38;
        asm volatile("" ::: "memory");
        p->d.x = (zx - p->coord.x) / 0x38;
        k = 0xC400;
        asm("" : "+r"(k));
        p->d.y = -(k / 0x38);
        p->work[2] = 0x37;
        p->mode[2]++;
        FALLTHROUGH;
      }
      case 1:
      lab1:
        if (p->work[3] == 1) {
          goto bump;
        }
        p->mode[2] = 4;
        break;
      case 2:
        UpdateEntityAnim((struct Entity*)p);
        if (p->motion.state == 3) {
          u8 v2;
          (p->spr).xflip = (p->flags >> 4 ^ 1) & 1;
          v2 = (p->flags >> 4 ^ 1) & 1;
          (p->spr).oam.xflip = v2;
          if (v2 != 0) {
            goto orB2;
          }
          goto clearA2;
        orB2:
          {
            register u32 blk2 asm("r1");
            register u32 tv2 asm("r0");
            tv2 = p->flags;
            blk2 = 0x10;
            asm("" : "+r"(blk2));
            tv2 |= blk2;
            fl2 = tv2;
          }
          goto storeA2;
        }
        break;
      case 3:
        goto lab3;
      case 4:
        goto lab4;
      case 5:
        SetSpriteAnimation(p, 0xAB0D);
        p->work[3] = 0;
        p->mode[2]++;
        FALLTHROUGH;
      case 6: {
        s32 dy2 = p->d.y;
        s32 t;
        dy2 += 0x20;
        p->d.y = dy2;
        nx = p->coord.x + p->d.x;
        p->coord.x = nx;
        ny = p->coord.y + dy2;
        p->coord.y = ny;
        if (p->d.x > 0) {
          r = PushoutToLeft1(nx + 0x2800, ny);
        } else {
        push_right:
          r = PushoutToRight1(nx + -0x2800, ny);
        }
      push_tail:
        if (r != 0) {
          p->coord.x += r;
        }
        if (p->d.y > 0 && p->work[3] == 0) {
          p->work[3] = 1;
          SetDDP(&p->body, &sCollisions[4]);
        }
        UpdateEntityAnim((struct Entity*)p);
        t = p->work[2];
        if (t != 0) {
          t--;
          p->work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      bump:
        p->mode[2]++;
        break;
      }
      case 7:
        SetDDP(&p->body, &sCollisions[1]);
        SetSpriteAnimation(p, 0xAB0F);
        p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x1000);
        PlaySound(0xDE);
        p->mode[2]++;
        FALLTHROUGH;
      case 8:
        UpdateEntityAnim((struct Entity*)p);
        if (p->motion.state == 3) {
          p->mode[2] = 0;
          p->mode[3] = 2;
        }
        break;
    }
  }
}

INCASM("asm/boss/tretista_b.inc");

void tretistaPipeThrow(Tretista* p0) {
  register Tretista* p asm("r4");
  u32 wv;
  u32 wz;
  p = p0;
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x11));
      SetDDP(&p->body, &sCollisions[1]);
      {
        u32 z = 0;
        p->work[2] = 0x34;
        p->d.x = z;
      }
      {
        s32 dd = 0x1A680;
        asm("" : "+r"(dd));
        p->d.y = -(dd / 0x34);
      }
      wv = 0x33;
    setw:
      p->work[2] = wv;
    bump01:
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
    case 21:
    case 31:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x0D));
      SetDDP(&p->body, (const struct Collision*)0x8363410);
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 vy = p->d.y + 0x50;
      p->d.y = vy;
      {
        s32 cx = p->coord.x;
        cx += p->d.x;
        p->coord.x = cx;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + vy;
      }
      if (vy > 0) {
        u32 w3 = p->work[3];
        if (w3 == 0) {
          u32 one = 1;
          p->work[3] = one;
          SetMotion((struct Entity*)p, MOTION(0xAB, 0x12));
          if ((RANDOM(RNG_0202f388) & one) != 0) {
            *(struct Projectile**)((u8*)p + 0xc4) =
                tretista_080a36f4((struct Entity*)p, &p->coord, (p->flags >> 4) & one);
            p->mode[3] = w3;
          } else {
            *(struct Projectile**)((u8*)p + 0xc4) =
                tretista_080a369c((struct Entity*)p, &p->coord, (p->flags >> 4) & one);
            p->mode[3] = one;
          }
        }
      }
      goto umgtail;
    }
    case 4: {
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x12));
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x1000);
      SetDDP(&p->body, &sCollisions[1]);
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
        *(u32*)((u8*)q + 0xc0) |= 1;
      }
      PlaySound(0xDE);
      p->work[2] = 0xA;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      if (p->mode[3] == 0) {
        p->mode[2] = 0xA;
        break;
      }
      p->mode[2] = 0x28;
      break;
    case 10: {
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
        *(u32*)((u8*)q + 0xc0) |= 8;
      }
      PlaySound(0xD5);
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x13));
      SetDDP(&p->body, &sCollisions[1]);
      {
        u32 z = 0;
        p->work[2] = 0x5A;
        p->work[3] = z;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 11:
      if ((*(struct Projectile**)((u8*)p + 0xc4))->mode[0] > 1) {
        p->work[3] = 1;
      }
      goto umgtail;
    case 12: {
      if ((*(struct Projectile**)((u8*)p + 0xc4))->mode[0] > 1) {
        p->work[3] = 1;
      }
      if (p->work[3] == 1) {
        wz = 0;
        goto endset;
      }
      {
        u32 m2v;
        if ((RANDOM(RNG_0202f388) & 1) != 0) {
          m2v = 0x14;
          asm("" : "+r"(m2v));
        } else {
          m2v = 0x1E;
          asm(" " : "+r"(m2v));
        }
        *(volatile u8*)&p->mode[2] = m2v;
      }
      p->mode[2] = 0x1E;
      break;
    }
    case 20: {
      register s32 x5 asm("r5");
      s32 lim;
      register s32 off asm("r2");
      register s32 cx asm("r3");
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x0C));
      SetDDP(&p->body, &sCollisions[1]);
      if ((p->flags & 0x10) == 0) {
        register s32 c0 asm("r0");
        register s32 r2v asm("r2");
        c0 = p->coord.x;
        x5 = c0 + -0x9800;
        r2v = c0 + -0xD800;
        lim = *(s32*)((u8*)p + 0xd0);
        asm("add %0, %1, #0" : "=r"(cx) : "r"(c0));
        if (r2v < lim) {
          off = 0x80 << 7;
          goto ovr20;
        }
      } else {
        register s32 c0 asm("r0");
        register s32 r2v asm("r2");
        register s32 kc asm("r1");
        c0 = p->coord.x;
        kc = 0x98 << 8;
        asm("" : "+r"(kc));
        x5 = c0 + kc;
        kc = 0xD8 << 8;
        asm("" : "+r"(kc));
        r2v = c0 + kc;
        lim = *(s32*)((u8*)p + 0xdc);
        asm("add %0, %1, #0 " : "=r"(cx) : "r"(c0));
        if (r2v > lim) {
          off = -0x4000;
        ovr20:
          x5 = lim + off;
        }
      }
      p->work[2] = 0x38;
      p->d.x = (x5 - cx) / 0x38;
      {
        s32 dd = 0xF5 << 9;
        asm("" : "+r"(dd));
        p->d.y = -(dd / 0x38);
      }
      wv = 0x37;
      goto setw;
    }
    case 22:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x0D));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 23: {
      s32 vy = p->d.y + 0x50;
      p->d.y = vy;
      {
        s32 cx = p->coord.x;
        cx += p->d.x;
        p->coord.x = cx;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + vy;
      }
      if (vy > 0) {
        if (p->work[3] == 0) {
          p->work[3] = 1;
          SetDDP(&p->body, (const struct Collision*)0x8363410);
        }
      }
      {
        s32 fl = FUN_08009f6c(p->coord.x, p->coord.y);
        {
          register s32 kd asm("r1");
          kd = -0x2D00;
          asm("" : "+r"(kd));
          fl += kd;
        }
        if (p->coord.y > fl) {
          if (p->d.y > 0) {
            struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
            *(u32*)((u8*)q + 0xc0) |= 0x10;
          }
        }
      }
      goto umgtail;
    }
    case 24:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x0F));
      PlaySound(0xDE);
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x1000);
      goto ddp34;
    case 30: {
      s32 tgt;
      s32 lim;
      s32 dxv;
      s32 cx;
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x14));
      SetDDP(&p->body, (const struct Collision*)0x83634A0);
      if ((p->flags & 0x10) == 0) {
        register s32 c0 asm("r0");
        register s32 r2v asm("r2");
        c0 = p->coord.x;
        r2v = c0 + -0xD800;
        lim = *(s32*)((u8*)p + 0xd0);
        asm("add %0, %1, #0" : "=r"(cx) : "r"(c0));
        if (r2v < lim) {
          tgt = lim + (0x80 << 7);
        } else {
          tgt = cx + -0x5800;
        }
        dxv = -0x300;
      } else {
        register s32 c0 asm("r0");
        register s32 r2v asm("r2");
        c0 = p->coord.x;
        r2v = c0 + (0xD8 << 8);
        lim = *(s32*)((u8*)p + 0xdc);
        asm("add %0, %1, #0 " : "=r"(cx) : "r"(c0));
        if (r2v > lim) {
          tgt = lim + -0x4000;
        } else {
          tgt = cx + (0xB0 << 7);
        }
        dxv = 0xC0 << 2;
      }
      p->d.x = dxv;
      {
        s32 t = tgt - cx;
        if (t <= 0) {
          t = cx - tgt;
        }
        p->d.y = t;
        p->unk_coord.y = t + -0x2000;
      }
      p->unk_coord.x = 0;
      goto bump01;
    }
    case 32:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x15));
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    case 33: {
      s32 v;
      {
        s32 cx = p->coord.x;
        v = p->d.x;
        p->coord.x = cx + v;
      }
      if (v < 0) {
        v = -v;
      }
      {
        s32 acc = p->unk_coord.x + v;
        p->unk_coord.x = acc;
        if (acc > p->unk_coord.y) {
          struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
          *(u32*)((u8*)q + 0xc0) |= 0x10;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->unk_coord.x > p->d.y) {
        p->mode[2]++;
      }
      break;
    }
    case 34:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x16));
    ddp34:
      SetDDP(&p->body, &sCollisions[1]);
      p->mode[2]++;
      FALLTHROUGH;
    case 25:
    case 35: {
      u32 st;
      UpdateEntityAnim((struct Entity*)p);
      st = p->motion.state;
      if (st != 3) {
        break;
      }
      p->mode[1] = st;
      p->mode[2] = 0;
      break;
    }
    case 40:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x17));
      SetDDP(&p->body, (const struct Collision*)0x8363458);
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
        *(u32*)((u8*)q + 0xc0) |= 2;
      }
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    case 41:
      UpdateEntityAnim((struct Entity*)p);
      if ((*(u32*)((u8*)p + 0x70) & 0x00FFFF00) == 0x81 << 9) {
        PlaySound(0xD8);
      }
      if (p->motion.state != 3) {
        break;
      }
      goto cdtail;
    case 42:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x18));
      SetDDP(&p->body, &sCollisions[1]);
      {
        u32 z = 0;
        p->work[2] = z;
        {
          register u8* t asm("r1");
          t = (u8*)p + 0xb7;
          *t = z;
        }
      }
      p->mode[2]++;
      FALLTHROUGH;
    case 43:
      if (p->work[2] == 0) {
        s32 ci = (s8)*((u8*)p + 0x71);
        if (ci == 1) {
          p->work[2] = ci;
          {
            struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
            *(u32*)((u8*)q + 0xc0) |= 4;
          }
          PlaySound(0xD5);
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        goto bump51;
      }
      goto b7chk;
    case 44:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x09));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0x3C;
      p->mode[2]++;
      FALLTHROUGH;
    case 45:
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w == 0) {
          goto clr45;
        }
        w--;
        p->work[2] = w;
        if ((w << 24) == 0) {
          goto clr45;
        }
      }
    b7chk:
      if (*((u8*)p + 0xb7) != 1) {
        break;
      }
      p->mode[2] = 0x32;
      break;
    case 50: {
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x24));
      p->work[2] = 0x28;
      if ((p->flags & 0x10) == 0) {
        p->d.x = p->coord.x + (0x80 << 5);
      } else {
        p->d.x = p->coord.x + -0x1000;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 51: {
      s32 nx;
      {
        s32 dv = p->d.x;
        s32 cx = p->coord.x;
        s32 t = ((dv - cx) << 4) >> 8;
        nx = cx + t;
        p->coord.x = nx;
      }
      {
        s32 r;
        if ((p->flags & 0x10) == 0) {
          r = PushoutToLeft1(nx + (0xB8 << 6), p->coord.y);
        } else {
          r = PushoutToRight1(nx + -0x2E00, p->coord.y);
        }
        if (r != 0) {
          p->coord.x += r;
        }
      }
    umgtail:
      UpdateEntityAnim((struct Entity*)p);
    cdtail:
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
    bump51:
      p->mode[2]++;
      break;
    }
    case 52:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x09));
      p->work[2] = 0x32;
      p->mode[2]++;
      FALLTHROUGH;
    case 53:
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
    clr45:
      {
        u8* t = (u8*)p + 0xb7;
        wz = 0;
        *t = wz;
      }
    endset:
      p->mode[1] = 3;
      p->mode[2] = wz;
      break;
  }
}

INCASM("asm/boss/tretista_c.inc");

void tretistaLaserCraw(Tretista* p0) {
  register Tretista* p asm("r5");
  p = p0;
  switch (p->mode[2]) {
    case 0: {
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x11));
      SetDDP(&p->body, &sCollisions[1]);
      {
        u32 z = 0;
        p->work[2] = 0x34;
        p->d.x = z;
      }
      {
        s32 dd = 0x1A680;
        asm("" : "+r"(dd));
        p->d.y = -(dd / 0x34);
      }
      p->work[2] = 0x33;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      p->mode[2]++;
      break;
    case 2:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x0D));
      SetDDP(&p->body, (const struct Collision*)0x8363410);
      p->work[3] = 0;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 vy = p->d.y + 0x50;
      p->d.y = vy;
      {
        s32 cx = p->coord.x;
        cx += p->d.x;
        p->coord.x = cx;
      }
      {
        s32 cy = p->coord.y;
        p->coord.y = cy + vy;
      }
      if (vy > 0) {
        u32 w3 = p->work[3];
        if (w3 == 0) {
          u32 one = 1;
          p->work[3] = one;
          SetMotion((struct Entity*)p, MOTION(0xAB, 0x12));
          *(struct Projectile**)((u8*)p + 0xc4) =
              tretista_080a36f4((struct Entity*)p, &p->coord, (p->flags >> 4) & one);
          p->mode[3] = w3;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 4: {
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x12));
      p->coord.y = FUN_08009f6c(p->coord.x, p->coord.y + -0x1000);
      SetDDP(&p->body, &sCollisions[1]);
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
        *(u32*)((u8*)q + 0xc0) |= 1;
      }
      PlaySound(0xDE);
      p->work[2] = 0xA;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      if (p->mode[3] != 0) {
        break;
      }
      p->mode[2] = 0xA;
      break;
    case 10: {
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc4);
        *(u32*)((u8*)q + 0xc0) |= 8;
      }
      PlaySound(0xD5);
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x13));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0x5A;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 11:
      UpdateEntityAnim((struct Entity*)p);
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 12:
      p->mode[2] = 0x1E;
      break;
    case 30:
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x20));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0xA;
      p->mode[2]++;
      FALLTHROUGH;
    case 31:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state != 3) {
        break;
      }
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    case 32: {
      *(struct Projectile**)((u8*)p + 0xc0) =
          FUN_080a374c((struct Entity*)p, &p->coord, (p->flags >> 4) & 1);
      StartPaletteAnimation(0x49, 0x2E0);
      PlaySound(0xDB);
      {
        u32 z = 0;
        p->work[2] = z;
        p->work[3] = z;
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 33: {
      if (p->work[3] == 0) {
        if (p->work[2] > 0x14) {
          p->work[3] = 1;
          RemovePaletteAnimation(0x49);
          StartPaletteAnimation(0x4A, 0x2E0);
        }
      }
      if (p->work[3] == 1) {
        StepPaletteAnimation(0x4A);
      } else {
        StepPaletteAnimation(0x49);
      }
      {
        u32 w = p->work[2];
        if (w <= 0x1E) {
          w++;
          p->work[2] = w;
          if ((u8)w <= 0x1E) {
            break;
          }
        }
      }
      p->mode[2]++;
      break;
    }
    case 34: {
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc0);
        *(u32*)((u8*)q + 0xc0) |= 0x100;
      }
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x22));
      SetDDP(&p->body, &sCollisions[1]);
      if ((p->flags & 0x10) == 0) {
        p->d.x = -0x300;
      } else {
        p->d.x = 0xC0 << 2;
      }
      p->d.y = 0xF0 << 7;
      p->unk_coord.x = 0;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 35: {
      s32 v;
      {
        s32 cx = p->coord.x;
        v = p->d.x;
        p->coord.x = cx + v;
      }
      if (v < 0) {
        v = -v;
      }
      p->unk_coord.x += v;
      StepPaletteAnimation(0x4A);
      {
        s32 r;
        if (p->d.x > 0) {
          r = PushoutToLeft1(p->coord.x + (0xB8 << 6), p->coord.y);
        } else {
          r = PushoutToRight1(p->coord.x + -0x2E00, p->coord.y);
        }
        if (r != 0) {
          p->coord.x += r;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 half = p->d.y >> 1;
        if (p->unk_coord.x > half) {
          struct Projectile** h = (struct Projectile**)((u8*)p + 0xc4);
          struct Projectile* q = *h;
          if (q != NULL) {
            *(u32*)((u8*)q + 0xc0) |= 0x10;
            *h = NULL;
          }
        }
      }
      if (p->unk_coord.x > p->d.y) {
        RemovePaletteAnimation(0x4A);
        p->mode[2]++;
      }
      break;
    }
    case 36: {
      {
        struct Projectile* q = *(struct Projectile**)((u8*)p + 0xc0);
        *(u32*)((u8*)q + 0xc0) |= 0x200;
      }
      StartPaletteAnimation(0x4B, 0x2E0);
      SetMotion((struct Entity*)p, MOTION(0xAB, 0x23));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0x1E;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 37: {
      u32 st3;
      StepPaletteAnimation(0x4B);
      UpdateEntityAnim((struct Entity*)p);
      st3 = p->motion.state;
      if (st3 != 3) {
        break;
      }
      {
        u32 w = p->work[2];
        if (w != 0) {
          w--;
          p->work[2] = w;
          if ((w << 24) != 0) {
            break;
          }
        }
      }
      RemovePaletteAnimation(0x4B);
      p->mode[1] = st3;
      p->mode[2] = 0;
      break;
    }
  }
}

INCASM("asm/boss/tretista_d.inc");

// 0x083633b0
static const struct Collision sCollisions[13] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(36), PIXEL(38)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(4), -PIXEL(34), PIXEL(84), PIXEL(68)},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(26), -PIXEL(49), PIXEL(20), PIXEL(24)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(4), -PIXEL(18), PIXEL(84), PIXEL(37)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(56), PIXEL(72), PIXEL(103)},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(15), -PIXEL(96), PIXEL(22), PIXEL(23)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(41), PIXEL(72), PIXEL(83)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(37), PIXEL(80), PIXEL(77)},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {PIXEL(0), -PIXEL(50), PIXEL(20), PIXEL(26)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(12), PIXEL(80), PIXEL(25)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(12), -PIXEL(37), PIXEL(97), PIXEL(78)},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 1,
      range : {-PIXEL(26), -PIXEL(49), PIXEL(20), PIXEL(24)},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(12), -PIXEL(12), PIXEL(97), PIXEL(24)},
    },
};

static const Coords32 sTretista_ExplosionOffsets[2] = {
    {PIXEL(0), -PIXEL(48)},
    {PIXEL(0), -PIXEL(48)},
};  // 0x083634E8
