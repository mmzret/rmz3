#include "boss/copy_x.h"
#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "metatile.h"
#include "projectile.h"

// コピーXのチャージショット + レイジングエクスチャージ(ﾓｳﾕﾙｻﾝ!)
typedef struct {
  COLLISION_OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  Coords32 c_b4;  // 0xB4
  u8 unk_bc[8];   // 0xBC
} Projectile28;
static_assert(sizeof(Projectile28) == sizeof(Projectile));

// Entity.work[0]
enum {
  PJ28_0_UNK = 0,
  PJ28_1_UNK = 1,
  PJ28_2_RAGING_EX_CHARGE = 2,  // レイジングエクスチャージ(ﾓｳﾕﾙｻﾝ!)
  PJ28_3_UNUSED = 3,            // 使われてなさそう, 2のレイジングエクスチャージと似たような処理っぽい
};

void FUN_080a90a0(struct Entity* e, u8 param_2, u8 param_3);

static void Projectile28_Init(Projectile28* p);
static void Projectile28_Update(Projectile28* p);
static void Projectile28_Die(Projectile28* p);

// clang-format off
const ProjectileRoutine gProjectile28Routine = {
    [ENTITY_INIT] =      (void*)Projectile28_Init,
    [ENTITY_UPDATE] =    (void*)Projectile28_Update,
    [ENTITY_DIE] =       (void*)Projectile28_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteProjectile,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

// 0x080a9aa0
void CreateProjectile28(struct Entity* e, u8 kind, u8 unusedval) {
  struct Entity* p = AllocEntityLast(gProjectileHeaderPtr);
  if (p != NULL) {
    INIT_PROJECTILE_ROUTINE(p, 28);
    p->work[0] = kind, p->work[1] = unusedval;
    p->unk_28 = (void*)e;
    p->coord = e->coord;
  }
}

// --------------------------------------------

static void FUN_080a9b90(Projectile28* p);
static void FUN_080a9d88(Projectile28* p);
static void Projectile28_Init_RagingEXCharge(Projectile28* p);
void FUN_080aa08c(Projectile28* p);

static void Projectile28_Init(Projectile28* p) {
  static void (*const PTR_ARRAY_0836c20c[4])(Projectile28*) = {
      FUN_080a9b90,
      FUN_080a9d88,
      Projectile28_Init_RagingEXCharge,
      FUN_080aa08c,
  };  // 0x0836c20c
  (PTR_ARRAY_0836c20c[p->work[0]])(p);
}

static void FUN_080a9c88(Projectile28* p);
static void FUN_080a9dcc(Projectile28* p);
void FUN_080a9ef8(Projectile28* p);
void FUN_080aa120(Projectile28* p);

static void Projectile28_Update(Projectile28* p) {
  static void (*const PTR_ARRAY_0836c21c[4])(Projectile28*) = {
      FUN_080a9c88,
      FUN_080a9dcc,
      FUN_080a9ef8,
      FUN_080aa120,
  };  // 0x0836c21c
  (PTR_ARRAY_0836c21c[p->work[0]])(p);
}

static void Projectile28_Die(Projectile28* p) {
  if (p->work[0] >= PJ28_2_RAGING_EX_CHARGE) {
    gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN1_ON;
    gWindowRegBuffer.winin[2] |= 0xFE;
    gPaletteManager.buf[0] = RGB_BLACK;
  }
  EXIT_BODY(p);
  SET_PROJECTILE_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static const struct Collision sCollisions[];

static void FUN_080a9b90(Projectile28* p) {
  struct Entity* q = p->unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 0));
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if (p->flags & X_FLIP) {
    p->coord.x += PIXEL(31);
    p->d.x = PIXEL(1) / 2;
    p->work[2] = 0x7F;
  } else {
    p->coord.x -= PIXEL(31);
    p->d.x = -PIXEL(1) / 2;
    p->work[2] = 0x0;
  }
  p->coord.y -= PIXEL(24);
  p->d.y = 0;
  p->work[3] = 0;
  INIT_BODY(p, &sCollisions[0], 64, NULL);
  (p->c_b4).x = p->coord.x, (p->c_b4).y = p->coord.y;
  p->mode[2] = 1;
  Projectile28_Update((void*)p);
}

static void FUN_080a9c88(Projectile28* p) {
  UpdateSpriteAnimation(p);
  if (p->flags & X_FLIP) {
    (p->coord).x = (p->c_b4).x + COS(p->work[2]) * 11;
    (p->coord).y = (p->c_b4).y + SIN(p->work[2]) * 22;
    p->work[2] += 16;
    p->d.x += 8;
    if (p->d.x > PIXEL(2)) p->d.x = PIXEL(2);
  } else {
    (p->coord).x = (p->c_b4).x + COS(p->work[2]) * 11;
    (p->coord).y = (p->c_b4).y + SIN(p->work[2]) * 22;
    p->work[2] -= 16;
    p->d.x -= 8;
    if (p->d.x < -PIXEL(2)) p->d.x = -PIXEL(2);
  }
  if (((p->work[3]++) & 3) == 0) FUN_080a90a0((void*)p, 6, 0);
  (p->c_b4).x += p->d.x;
  if (FUN_080098a4((p->coord).x, (p->coord).y)) {
    SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
  }
}

static void FUN_080a9d88(Projectile28* p) {
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->flags) |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 1));
  p->mode[2] = 1;
  Projectile28_Update(p);
}

static void FUN_080a9dcc(Projectile28* p) {
  BossCopyX* q = (BossCopyX*)(p->unk_28);
  p->coord = q->coord;
  SET_XFLIP(p, (q->flags & X_FLIP) != 0);
  if (q->unk_c6) {
    if (p->mode[2] != 0) SetSpriteAnimation(p, MOTION(SM095_COPYX_CHARGE, 1));
    p->flags |= DISPLAY;
    p->mode[2] = 0;
  } else {
    p->flags &= ~DISPLAY;
    p->mode[2] = 1;
  }
  UpdateSpriteAnimation(p);
  if (q->mode[0] >= ENTITY_DIE) SET_PROJECTILE_ROUTINE(p, ENTITY_DIE);
}

void FUN_080a9fe4(void* t, struct DrawPivot* c);

// 0x080a9e74
static void Projectile28_Init_RagingEXCharge(Projectile28* p) {
  struct Entity* q = p->unk_28;
  SET_PROJECTILE_ROUTINE(p, ENTITY_UPDATE);
  SetTaskCallback((void*)&p->spr, FUN_080a9fe4);
  (p->spr).sprites = (void*)p;
  p->flags &= ~USE_COMMON_OAM_RENDERER;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  p->coord = q->coord;
  gWindowRegBuffer.dispcnt |= DISPCNT_WIN1_ON;
  gWindowRegBuffer.winin[1] = WININ_WIN0_CLR | WININ_WIN0_OBJ | WININ_WIN0_BG0;
  gWindowRegBuffer.winin[2] |= WINOUT_WIN01_BG3 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG1;
  (*(u16*)(&gPaletteManager.buf[0])) = RGB_WHITE;  // NOTE: gPaletteManager.buf[0] = RGB_WHITE; だとコンパイル結果が一致しなかった
  p->work[2] = p->work[3] = 0;
  Projectile28_Update(p);
}

INCASM("asm/projectile/copy_x_28.inc");

// --------------------------------------------

// 0x0836c22c
static const struct Collision sCollisions[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      nature : 0x04,
      hitzone : 1,
      hardness : METAL,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(127), PIXEL(64), -PIXEL(1)},
    },
};
