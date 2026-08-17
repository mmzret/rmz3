#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"

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

void FUN_0806aaa0(struct Enemy* p) {
  struct Entity* q;
  s32 z, nx, ny;
  s32* pb;
  u32 w2, one, num;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      if ((*(s32*)((u8*)(p->s).unk_28 + 0xd4) & 1) == 0) {
        break;
      }
      goto bump;
    case 2:
      (p->s).flags |= DISPLAY;
      z = 0;
      {
        register struct Entity* q1 asm("r1");
        q1 = (p->s).unk_28;
        (p->s).coord.y = (q1->coord).y - 0x1800;
        (p->s).coord.x = (q1->coord).x;
        (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + (q1->coord).x;
      }
      SetMotion(&p->s, MOTION(0x09, 0x00));
      {
        u8* d = (u8*)p + 0x5c;
        *(s32*)(d + 4) = z;
      }
      (p->s).d.x = z;
      (p->s).unk_coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y - 0x400);
      (p->s).coord.y = (p->s).unk_coord.y - 0x1800;
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).d.x = 0x2000;
      if ((p->s).mode[3] == 1) {
        (p->s).work[2] = 0x80;
        (p->s).work[3] = z;
        (p->s).flags &= 0xEF;
        (p->s).spr.xflip = z;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        (p->s).mode[2] += 2;
      } else {
        (p->s).work[2] = 0x3C;
        (p->s).work[3] = RANDOM(RNG_0202f388) % 20;
        (p->s).flags &= 0xEF;
        (p->s).spr.xflip = z;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        (p->s).work[3] = z;
        (p->s).mode[2]++;
      }
      /* fallthrough */
    case 3:
      UpdateEntityAnim(&p->s);
      (p->s).work[3]++;
      num = (p->s).work[3];
      w2 = (p->s).work[2];
      if ((u8)((u32)num % w2) == 0) {
        (p->s).work[2] = w2 - 10;
        (p->s).coord.x += ((s32)(RANDOM(RNG_0202f388) % 6) - 3) << 8;
      }
      if ((p->s).work[2] == 0) {
        (p->s).work[2] = 0x80;
        (p->s).work[3] = 0;
        goto bump;
      }
      break;
    case 4:
      {
      register u32 v2 asm("r3");
      v2 = (p->s).work[2];
      asm("" : "+l"(v2));
      one = 1;
      asm("" : "+l"(one));
      if (v2 & one) {
        register s32* pb2 asm("r0");
        pb2 = (s32*)((u8*)p + 0xb4);
        q = (p->s).unk_28;
        nx = *pb2 + (q->coord).x + ((v2 >> 3) << 8);
      } else {
        register s32* pb2 asm("r0");
        pb2 = (s32*)((u8*)p + 0xb4);
        q = (p->s).unk_28;
        nx = *pb2 + (q->coord).x - (((v2 << 24) >> 27) << 8);
      }
      (p->s).coord.x = nx;
      ny = *(s32*)((u8*)p + 0xb8) + (q->coord).y;
      (p->s).coord.y += ((ny - (p->s).coord.y) << 3) >> 8;
      asm volatile("" ::"l"(v2));
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] != 0) {
        if ((u8)--(p->s).work[2] != 0) {
          break;
        }
      }
    bump:
      (p->s).mode[2]++;
      break;
    case 5: {
      s32 z2;
      (p->s).flags |= DISPLAY;
      z2 = 0;
      (p->s).mode[1] = 2;
      (p->s).mode[2] = z2;
      break;
    }
  }
}

void FUN_0806ac98(struct Enemy* p) {
  struct Entity* q;
  s32 z, nx, ny;
  s32* pb;
  u32 w2, one, num;

  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      if ((*(s32*)((u8*)(p->s).unk_28 + 0xd4) & 1) == 0) {
        break;
      }
      goto bump;
    case 2:
      (p->s).flags |= DISPLAY;
      z = 0;
      {
        register struct Entity* q1 asm("r1");
        q1 = (p->s).unk_28;
        (p->s).coord.y = (q1->coord).y - 0x1800;
        (p->s).coord.x = (q1->coord).x;
        (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + (q1->coord).x;
      }
      SetMotion(&p->s, MOTION(0x09, 0x01));
      {
        u8* d = (u8*)p + 0x5c;
        *(s32*)(d + 4) = z;
      }
      (p->s).d.x = z;
      (p->s).unk_coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y - 0x1000);
      (p->s).coord.y = (p->s).unk_coord.y - 0x1800;
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).d.x = 0x2000;
      if ((p->s).mode[3] == 1) {
        (p->s).work[2] = 0x80;
        (p->s).work[3] = z;
        (p->s).flags &= 0xEF;
        (p->s).spr.xflip = z;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        (p->s).mode[2] += 2;
      } else {
        (p->s).work[2] = 0x3C;
        (p->s).work[3] = RANDOM(RNG_0202f388) % 20;
        (p->s).flags &= 0xEF;
        (p->s).spr.xflip = z;
        {
          u8* oa = (u8*)p + 0x4a;
          s32 ov = *oa;
          s32 m11 = -0x11;
          m11 &= ov;
          *oa = m11;
        }
        (p->s).mode[2]++;
      }
      /* fallthrough */
    case 3:
      UpdateEntityAnim(&p->s);
      (p->s).work[3]++;
      num = (p->s).work[3];
      w2 = (p->s).work[2];
      if ((u8)((u32)num % w2) == 0) {
        (p->s).work[2] = w2 - 10;
        (p->s).coord.x += ((s32)(RANDOM(RNG_0202f388) & 7) - 4) << 8;
      }
      if ((p->s).work[2] == 0) {
        (p->s).work[2] = 0x80;
        (p->s).work[3] = 0;
        goto bump;
      }
      break;
    case 4:
      {
      register u32 v2 asm("r3");
      v2 = (p->s).work[2];
      asm("" : "+l"(v2));
      one = 1;
      asm("" : "+l"(one));
      if (v2 & one) {
        register s32* pb2 asm("r0");
        pb2 = (s32*)((u8*)p + 0xb4);
        q = (p->s).unk_28;
        nx = *pb2 + (q->coord).x + ((v2 >> 3) << 8);
      } else {
        register s32* pb2 asm("r0");
        pb2 = (s32*)((u8*)p + 0xb4);
        q = (p->s).unk_28;
        nx = *pb2 + (q->coord).x - (((v2 << 24) >> 27) << 8);
      }
      (p->s).coord.x = nx;
      ny = *(s32*)((u8*)p + 0xb8) + (q->coord).y;
      (p->s).coord.y += ((ny - (p->s).coord.y) << 3) >> 8;
      asm volatile("" ::"l"(v2));
      }
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] != 0) {
        if ((u8)--(p->s).work[2] != 0) {
          break;
        }
      }
    bump:
      (p->s).mode[2]++;
      break;
    case 5: {
      s32 z2;
      (p->s).flags |= DISPLAY;
      z2 = 0;
      (p->s).mode[1] = 2;
      (p->s).mode[2] = z2;
      break;
    }
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
