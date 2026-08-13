#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"

struct Projectile* FUN_0809d8a0(struct Coord* c, s32 r1, u8 r2, struct Enemy* r3);
struct Projectile* FUN_0809d904(struct Coord* c, s32 r1, u8 r2, struct Enemy* r3);

typedef struct {
  COLLISION_OBJECT_HDR;
  Coords32 unk_b4;  // 0xB4, オメガ本体からの距離?
  u8 unk_bc[8];     // 0xBC
} Omega1wHand;
static_assert(sizeof(Omega1wHand) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void OmegaWhiteHand_Init(Omega1wHand* p);
static void OmegaWhiteHand_Update(Omega1wHand* p);
static void OmegaWhiteHand_Die(struct Entity* p);

// clang-format off
const EnemyRoutine gOmegaWhiteHandRoutine = {
    [ENTITY_INIT] =      (void*)OmegaWhiteHand_Init,
    [ENTITY_UPDATE] =    (void*)OmegaWhiteHand_Update,
    [ENTITY_DIE] =       (void*)OmegaWhiteHand_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateOmega1wHand(Coords32* c, bool8 isLeftHand, struct Entity* omega) {
  struct Entity* p = (struct Entity*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1W_HAND);
    p->coord = *c;
    p->work[0] = isLeftHand;
    p->unk_28 = omega;
  }
  return p;
}

// --------------------------------------------

static void Omega1wHand_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void OmegaWhiteHand_Init(Omega1wHand* p) {
  EnableSpriteAnimation_Affine(p);
  p->angle = 0;
  SET_XFLIP(p, FALSE);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, Omega1wHand_OnCollision);
  (&p->d)->x = (&p->d)->y = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 1;
  if (p->work[0] == 0) {  // 右手
    p->spr.oam.priority = 3;
    (p->unk_b4).x = -PIXEL(19);
    (p->unk_b4).y = -PIXEL(58);
  } else {               // 左手
    p->renderPrio = 23;  // 重なったら、右手の方が見えるようにする
    (p->unk_b4).x = PIXEL(21);
    (p->unk_b4).y = -PIXEL(56);
    SET_YFLIP(p, FALSE);  // 左手は上下反転させない
  }
  p->flags2 |= WHITE_PAINTABLE;
  p->invincibleID = (p->unk_28)->uniqueID;  // オメガが白くなったら、手も白くするで

  OmegaWhiteHand_Update((Omega1wHand*)p);
}

// --------------------------------------------

void FUN_0806aa9c(struct Enemy* p);
void FUN_0806ae90(struct Enemy* p);
void FUN_0806af24(struct Enemy* p);
void FUN_0806b094(struct Enemy* p);
void FUN_0806b120(struct Enemy* p);
void FUN_0806b8cc(struct Enemy* p);

void FUN_0806aaa0(struct Enemy* p);
void FUN_0806ae94(struct Enemy* p);
void FUN_0806af40(struct Enemy* p);
void FUN_0806b098(struct Enemy* p);
void FUN_0806b124(struct Enemy* p);
void FUN_0806b8d0(struct Enemy* p);

void FUN_0806ac98(struct Enemy* p);
void FUN_0806aedc(struct Enemy* p);
void FUN_0806afdc(struct Enemy* p);
void FUN_0806b0dc(struct Enemy* p);
void FUN_0806b4cc(struct Enemy* p);
void FUN_0806bb8c(struct Enemy* p);

static void OmegaWhiteHand_Update(Omega1wHand* p) {
  // clang-format off
  static const EnemyFunc sUpdates[6] = {
      (EnemyFunc)FUN_0806aa9c,
      (EnemyFunc)FUN_0806ae90,
      (EnemyFunc)FUN_0806af24,
      (EnemyFunc)FUN_0806b094,
      (EnemyFunc)FUN_0806b120,
      (EnemyFunc)FUN_0806b8cc,
  }; // 0x083663e0
  // clang-format on

  // clang-format off
  static const EnemyFunc sUpdateRights[6] = {
      (EnemyFunc)FUN_0806aaa0,
      (EnemyFunc)FUN_0806ae94,
      (EnemyFunc)FUN_0806af40,
      (EnemyFunc)FUN_0806b098,
      (EnemyFunc)FUN_0806b124,
      (EnemyFunc)FUN_0806b8d0,
  }; // 0x083663f8
  // clang-format on

  // clang-format off
  static const EnemyFunc sUpdateLefts[6] = {
      (EnemyFunc)FUN_0806ac98,
      (EnemyFunc)FUN_0806aedc,
      (EnemyFunc)FUN_0806afdc,
      (EnemyFunc)FUN_0806b0dc,
      (EnemyFunc)FUN_0806b4cc,
      (EnemyFunc)FUN_0806bb8c,
  }; // 0x08366410
  // clang-format on

  Omega1* omega = (Omega1*)p->unk_28;
  if (omega->mode[0] >= ENTITY_DISAPPEAR) {
    // 本体が消えるときは、手も消える
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((omega->unk_d4 & 2) && (p->mode[1] != 5)) {
    p->mode[1] = 5, p->mode[2] = 0;
  }
  (sUpdates[p->mode[1]])((void*)p);

  if (p->work[0] == 0) {  // 右手
    (sUpdateRights[p->mode[1]])((void*)p);
  } else {  // 左手
    (sUpdateLefts[p->mode[1]])((void*)p);
  }
}

// --------------------------------------------

void FUN_0806a8fc(struct Enemy* p);
void FUN_0806aa54(struct Enemy* p);

static void OmegaWhiteHand_Die(struct Entity* p) {
  static const EnemyFunc sDeinitializers[2] = {
      (EnemyFunc)FUN_0806a8fc,
      (EnemyFunc)FUN_0806aa54,
  };  // 0x08366428
  (sDeinitializers[(p->mode)[1]])((void*)p);
}

// --------------------------------------------

INCASM("asm/enemy/omega1w_hand_a.inc");

void FUN_0806b124(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  struct Coord c;
  p = p0;
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).d.y = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 d0;
      s32 lim;
      s32 ny;
      UpdateEntityAnim(&p->s);
      d0 = (p->s).d.y - 0x40;
      (p->s).d.y = d0;
      if (d0 < -0x300) {
        (p->s).d.y = -0x300;
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      lim = ((p->s).unk_28)->coord.y + -0x7A00;
      if (ny >= lim) {
        break;
      }
      (p->s).coord.y = lim;
      (p->s).work[2] = 0x14;
      goto bump;
    }
    case 2: {
      s32 t0 = (p->s).work[2];
      if (t0 == 0) {
        break;
      }
      t0--;
      (p->s).work[2] = t0;
      if ((t0 << 24) != 0) {
        break;
      }
      asm volatile("" ::"r"(p));
      goto bump;
    }
    case 3:
      SetDDP(&p->body, &sCollisions[1]);
      (p->s).mode[3] = 4;
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      u32 one;
      SetMotion(&p->s, MOTION(0x09, 0x02));
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        register u32 z3 asm("r4");
        z3 = 0;
        *x4c = one;
        {
          register u8* oa asm("r3");
          register s32 k asm("r2");
          oa = (u8*)p + 0x4a;
          k = 0x10;
          {
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k;
            *oa = m11;
          }
        }
        {
          u8* a = (u8*)p + 0x24;
          *a = z3;
          SetDDP((struct Body*)(a + 0x50), &sCollisions[5]);
          *(s32*)((u8*)p + 0xbc) = z3;
        }
      }
      (p->s).d.x = -0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      s32* b;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim0 = -0x7800;
        b = a0;
        asm("" : "+r"(b));
        if (d0 < lim0) {
          (p->s).d.x -= 0x40;
          if ((p->s).d.x < -0x80) {
            (p->s).d.x = -0x80;
          }
        }
      }
      *b += (p->s).d.x;
      (p->s).coord.x = *b + ((p->s).unk_28)->coord.x + -0x1300;
      UpdateEntityAnim(&p->s);
      if (*b < -0x8000) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 6;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw = (p->s).work[2];
        if (tw == 0) {
          break;
        }
        tw--;
        (p->s).work[2] = tw;
        if ((tw << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 6:
      SetMotion(&p->s, MOTION(0x09, 0x02));
      SetDDP(&p->body, &sCollisions[5]);
      *(s32*)((u8*)p + 0xbc) = -0x8000;
      (p->s).d.x = 0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      s32 kv;
      s32 hb;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim1 = -0x800;
        kv = (s32)a0;
        asm("" : "+r"(kv));
        if (d0 > lim1) {
          (p->s).d.x += 0x40;
          if ((p->s).d.x > 0x80) {
            (p->s).d.x = 0x80;
          }
        }
      }
      *(s32*)kv += (p->s).d.x;
      {
        s32 t0 = *(s32*)kv + ((p->s).unk_28)->coord.x;
        kv = -0x1300;
        (p->s).coord.x = t0 + kv;
      }
      hb = kv;
      UpdateEntityAnim(&p->s);
      if ((p->s).coord.x > ((p->s).unk_28)->coord.x + hb) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 4;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw2 = (p->s).work[2];
        if (tw2 == 0) {
          break;
        }
        tw2--;
        (p->s).work[2] = tw2;
        if ((tw2 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 10:
      (p->s).work[2] = 0x1E;
      if ((p->s).mode[3] & 1) {
        c.x = (p->s).coord.x + 0x600;
      } else {
        c.x = (p->s).coord.x + -0x600;
      }
      c.y = (p->s).coord.y + 0xE00;
      PlaySound(0x12D);
      FUN_0809d8a0(&c, 0xA0 << 1, 7, p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t1 = (p->s).work[2];
      if (t1 == 0) {
        break;
      }
      t1--;
      (p->s).work[2] = t1;
      if ((t1 << 24) != 0) {
        break;
      }
      goto bump;
    }
    case 12:
      (p->s).work[2] = 0x40;
      if ((p->s).mode[3] & 1) {
        (p->s).mode[2] = 7;
      } else {
        (p->s).mode[2] = 5;
      }
      break;
    case 20: {
      SetMotion(&p->s, MOTION(0x09, 0x00));
      {
        u8* a2 = (u8*)p + 0x24;
        register u32 z asm("r4");
        z = 0;
        *a2 = z;
        SetDDP((struct Body*)(a2 + 0x50), &sCollisions[1]);
        (p->s).coord.x = ((p->s).unk_28)->coord.x + -0x1300;
        (p->s).d.y = z;
      }
      (p->s).work[2] = 0x28;
      goto bump;
    }
    case 21: {
      s32 t2 = (p->s).work[2];
      u32 z2;
      if (t2 == 0) {
        break;
      }
      t2--;
      (p->s).work[2] = t2;
      z2 = (u8)t2;
      if (z2 != 0) {
        break;
      }
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa = (u8*)p + 0x4a;
        s32 ov = *oa;
        s32 m11 = -0x11;
        m11 &= ov;
        *oa = m11;
      }
      goto bump;
    }
    case 22: {
      s32 lim2;
      s32 ny2;
      UpdateEntityAnim(&p->s);
      (p->s).d.y += 0x80;
      if ((p->s).d.y > 0x300) {
        (p->s).d.y = 0x300;
      }
      ny2 = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny2;
      lim2 = ((p->s).unk_28)->coord.y + -0x3A00;
      if (ny2 <= lim2) {
        break;
      }
      (p->s).coord.y = lim2;
    bump:
      (p->s).mode[2]++;
      break;
    }
    case 23:
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 24:
      UpdateEntityAnim(&p->s);
      if (((p->s).unk_28)->mode[1] != 5) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_0806b4cc(struct Enemy* p0) {
  register struct Enemy* p asm("r5");
  struct Coord c;
  p = p0;
  switch ((p->s).mode[2]) {
    case 0: {
      u32 one;
      u32 z;
      SetMotion(&p->s, MOTION(0x09, 0x02));
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        *x4c = one;
      }
      {
        register u8* oa asm("ip");
        oa = (u8*)(0x4a + (u32)p);
        {
          register s32 k asm("r2");
          k = 0x10;
          {
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k;
            *oa = m11;
          }
        }
        (p->s).flags |= 0x20;
        {
          u8* x4d = (u8*)p + 0x4d;
          asm volatile("mov %0, #0" : "=r"(z));
          *x4d = one;
        }
        {
          register s32 k2 asm("r2");
          k2 = 0x20;
          {
            s32 ov2 = *oa;
            s32 m21 = -0x21;
            m21 &= ov2;
            m21 |= k2;
            *oa = m21;
          }
        }
      }
      SetDDP(&p->body, &sCollisions[5]);
      (p->s).work[3] = z;
      *((u8*)p + 0x24) = z;
      (p->s).d.y = z;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 ny;
      s32 lim;
      {
        u32 t = (p->s).work[3];
        if (t <= 0x3F) {
          (p->s).work[3] = t + 4;
        }
      }
      {
        u32 mv = ~(p->s).work[3];
        *((u8*)p + 0x24) = mv;
      }
      UpdateEntityAnim(&p->s);
      (p->s).d.y += 0x20;
      if ((p->s).d.y > 0x300) {
        (p->s).d.y = 0x300;
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      lim = ((p->s).unk_28)->coord.y + -0x200;
      if (ny <= lim) {
        break;
      }
      (p->s).coord.y = lim;
      (p->s).work[2] = 0x14;
      (p->s).mode[2]++;
      break;
    }
    case 2: {
      s32 t0 = (p->s).work[2];
      if (t0 == 0) {
        break;
      }
      t0--;
      (p->s).work[2] = t0;
      if ((t0 << 24) != 0) {
        break;
      }
      (p->s).mode[2]++;
      break;
    }
    case 3:
      (p->s).mode[3] = 4;
      (p->s).work[2] = 0x50;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 4: {
      u32 one;
      SetMotion(&p->s, MOTION(0x09, 0x02));
      one = 1;
      (p->s).flags |= 0x10;
      {
        u8* x4c = (u8*)p + 0x4c;
        u32 z3;
        asm volatile("mov %0, #0" : "=r"(z3));
        *x4c = one;
        {
          register u8* oa asm("r3");
          register s32 k asm("r2");
          oa = (u8*)p + 0x4a;
          k = 0x10;
          {
            s32 ov = *oa;
            s32 m11 = -0x11;
            m11 &= ov;
            m11 |= k;
            *oa = m11;
          }
        }
        SetDDP(&p->body, &sCollisions[5]);
        *(s32*)((u8*)p + 0xbc) = z3;
      }
      (p->s).d.y = -0x100;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      s32* b;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim0 = -0x2E80;
        b = a0;
        asm("" : "+r"(b));
        if (d0 < lim0) {
          (p->s).d.y += 0x40;
          if ((p->s).d.y > -0x40) {
            (p->s).d.y = -0x40;
          }
        }
      }
      *b += (p->s).d.y;
      (p->s).coord.y = *b + ((p->s).unk_28)->coord.y + -0x200;
      UpdateEntityAnim(&p->s);
      if (*b < -0x3000) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 6;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw = (p->s).work[2];
        if (tw == 0) {
          break;
        }
        tw--;
        (p->s).work[2] = tw;
        if ((tw << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 6:
      SetMotion(&p->s, MOTION(0x09, 0x02));
      SetDDP(&p->body, &sCollisions[5]);
      *(s32*)((u8*)p + 0xbc) = -0x3000;
      (p->s).d.y = 0x100;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 7: {
      s32 kv;
      s32 hb;
      {
        s32* a0 = (s32*)((u8*)p + 0xbc);
        s32 d0 = *a0;
        s32 lim1 = -0x180;
        kv = (s32)a0;
        asm("" : "+r"(kv));
        if (d0 > lim1) {
          (p->s).d.y -= 0x40;
          if ((p->s).d.y <= 0x3F) {
            (p->s).d.y = 0x40;
          }
        }
      }
      *(s32*)kv += (p->s).d.y;
      {
        s32 t0 = *(s32*)kv + ((p->s).unk_28)->coord.y;
        kv = -0x200;
        (p->s).coord.y = t0 + kv;
      }
      hb = kv;
      UpdateEntityAnim(&p->s);
      if ((p->s).coord.y > ((p->s).unk_28)->coord.y + hb) {
        if ((u8)--(p->s).mode[3] != 0) {
          (p->s).mode[2] = 4;
          break;
        }
        (p->s).mode[2] = 0x14;
        break;
      }
      {
        s32 tw2 = (p->s).work[2];
        if (tw2 == 0) {
          break;
        }
        tw2--;
        (p->s).work[2] = tw2;
        if ((tw2 << 24) != 0) {
          break;
        }
      }
      (p->s).mode[2] = 0xA;
      break;
    }
    case 10:
      (p->s).work[2] = 0x3C;
      c.x = (p->s).coord.x + -0x1200;
      c.y = (p->s).coord.y;
      PlaySound(0x12D);
      FUN_0809d904(&c, 0x80 << 2, 7, p);
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 11: {
      s32 t1 = (p->s).work[2];
      if (t1 == 0) {
        break;
      }
      t1--;
      (p->s).work[2] = t1;
      if ((t1 << 24) != 0) {
        break;
      }
      (p->s).mode[2]++;
      break;
    }
    case 12:
      (p->s).work[2] = 0x40;
      if ((p->s).mode[3] & 1) {
        (p->s).mode[2] = 7;
      } else {
        (p->s).mode[2] = 5;
      }
      break;
    case 20: {
      u32 z2;
      SetMotion(&p->s, MOTION(0x09, 0x01));
      z2 = 0;
      (p->s).flags &= 0xEF;
      *((u8*)p + 0x4c) = z2;
      {
        u8* oa2 = (u8*)p + 0x4a;
        {
          s32 ov3 = *oa2;
          s32 m11b = -0x11;
          m11b &= ov3;
          *oa2 = m11b;
        }
        (p->s).flags &= 0xDF;
        *((u8*)p + 0x4d) = z2;
        {
          s32 ov4 = *oa2;
          s32 m21b = -0x21;
          m21b &= ov4;
          *oa2 = m21b;
        }
      }
      {
        u8* a2 = (u8*)p + 0x24;
        *a2 = z2;
        SetDDP((struct Body*)(a2 + 0x50), &sCollisions[3]);
      }
      (p->s).coord.x = ((p->s).unk_28)->coord.x + (0xA8 << 5);
      (p->s).d.y = z2;
      (p->s).work[2] = 0x32;
      (p->s).mode[2]++;
      break;
    }
    case 21: {
      s32 t2 = (p->s).work[2];
      if (t2 == 0) {
        break;
      }
      t2--;
      (p->s).work[2] = t2;
      if ((t2 << 24) != 0) {
        break;
      }
      (p->s).mode[2]++;
      break;
    }
    case 22: {
      s32 ny2;
      s32 lim2;
      UpdateEntityAnim(&p->s);
      (p->s).d.y -= 4;
      if ((p->s).d.y < -0xA0) {
        (p->s).d.y = -0xA0;
      }
      ny2 = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny2;
      lim2 = ((p->s).unk_28)->coord.y + -0x3800;
      if (ny2 >= lim2) {
        break;
      }
      (p->s).coord.y = lim2;
      (p->s).mode[2]++;
      break;
    }
    case 23:
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 24:
      UpdateEntityAnim(&p->s);
      if (((p->s).unk_28)->mode[1] != 5) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/enemy/omega1w_hand_b.inc");

// 0x0806be0c
static void Omega1wHand_OnCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// 0x08366430
static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0400, 0x0200, 0x1E00, 0x2800},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0400, 0x0200, 0x2000, 0x2A00},
    },
};
