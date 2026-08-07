#include "global.h"
#include "element.h"
#include "vfx.h"
#include "trig.h"

// ボス死亡時の爆発, 爆発時には、火球や漏れ出る光、誘爆のエフェクトなどがあるが、すべてのエフェクトをここで担う
typedef struct {
  ENTITY_HDR;     // 0x00
  ENTITY_SPRITE;  // 0x28
  u8 unk_74[16];  // 0x74
} BossExplosion;
static_assert(sizeof(BossExplosion) == sizeof(struct VFX));

// Entity.work[0]
enum {
  BOSS_EXPLOSION_MODE_0 = 0,
  BOSS_EXPLOSION_MODE_1 = 1,
  BOSS_EXPLOSION_MODE_2 = 2,  // 誘爆エフェクト？
  BOSS_EXPLOSION_MODE_3 = 3,  // 火球
};

static void BossExplosion_Init(BossExplosion* p);
static void BossExplosion_Update(BossExplosion* p);
static void BossExplosion_Die(BossExplosion* p);

// clang-format off
const VFXRoutine gBossExplosionRoutine = {
    [ENTITY_INIT] =      (void*)BossExplosion_Init,
    [ENTITY_UPDATE] =    (void*)BossExplosion_Update,
    [ENTITY_DIE] =       (void*)BossExplosion_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Entity* CreateBossExplosion(Entity* boss, Coords32* c) {
  BossExplosion* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_BOSS_EXPLOSION);
    p->unk_28 = (void*)boss;
    p->d = *c;
    p->work[0] = 0, p->work[1] = 0;
  }
  return (Entity*)p;
}

static void FUN_080c7984(Entity* e, Coords32* c, u8 kind1, u8 kind2) {
  BossExplosion* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_BOSS_EXPLOSION);
    p->unk_28 = (void*)e;
    p->coord = *c;
    p->work[0] = kind1, p->work[1] = kind2;
  }
}

// --------------------------------------------

void FUN_080c7a28(BossExplosion* p);
void FUN_080c7a90(BossExplosion* p);
static void FUN_080c7bc4(BossExplosion* p);
static void initFireball(BossExplosion* p);

static void BossExplosion_Init(BossExplosion* p) {
  static void (*const sInitializers[4])(BossExplosion*) = {
      FUN_080c7a28,
      FUN_080c7a90,
      FUN_080c7bc4,
      initFireball,
  };  // 0x0836f940
  (sInitializers[p->work[0]])(p);
}

NAKED static void FUN_080c7cc0(BossExplosion* p);
static void FUN_080c7f78(BossExplosion* p);
static void FUN_080c7ff0(BossExplosion* p);
static void updateFireball(BossExplosion* p);

static void BossExplosion_Update(BossExplosion* p) {
  static void (*const sUpdates[4])(BossExplosion*) = {
      FUN_080c7cc0,
      FUN_080c7f78,
      FUN_080c7ff0,
      updateFireball,
  };  // 0x0836f950
  (sUpdates[p->work[0]])(p);
}

static void FUN_080c8084(BossExplosion* p);
static void FUN_080c810c(BossExplosion* p);
static void FUN_080c8124(BossExplosion* p);
static void deleteFireball(BossExplosion* p);

static void BossExplosion_Die(BossExplosion* p) {
  static void (*const sDeinitializers[4])(BossExplosion*) = {
      FUN_080c8084,
      FUN_080c810c,
      FUN_080c8124,
      deleteFireball,
  };  // 0x0836F960
  (sDeinitializers[p->work[0]])(p);
}

void FUN_080c7a28(BossExplosion* p) {
  register struct Entity* q asm("r3") = p->unk_28;
  register s32 m asm("r2");
  register s32 x asm("r0");
  s32 z;
  z = 0;
  m = 0x10;
  p->work[2] = m;
  p->work[3] = z;
  p->work[1] = z;
  gElFxManager.delay = 4;
  {
    register s32 cx asm("r0");
    register s32 cy asm("r1");
    cx = q->coord.x;
    cy = q->coord.y;
    p->coord.x = cx;
    p->coord.y = cy;
  }
  m &= q->flags;
  if (m) {
    x = p->coord.x;
    x -= p->d.x;
  } else {
    x = p->coord.x;
    x += p->d.x;
  }
  p->coord.x = x;
  p->coord.y += p->d.y;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  BossExplosion_Update((void*)p);
}

void FUN_080c7a90(BossExplosion* p) {
  register u32 one4 asm("r4");
  register s32 z5 asm("r5");
  InitScalerotMotion1((struct Entity*)p);
  {
    register u8 f0 asm("r0");
    u8 fv0 = p->flags;
    f0 = fv0;
    one4 = 1;
    asm("" : "+r"(one4));
    z5 = 0;
    f0 |= one4;
    {
      register s32 c2 asm("r1");
      c2 = 2;
      f0 |= c2;
    }
    p->flags = f0;
  }
  asm volatile("" :: "r"(z5));
  SetMotion((struct Entity*)p, 0xEE00);
  UpdateEntityAnim((struct Entity*)p);
  {
    register u32 one9 asm("r9");
    u32 xf = RANDOM(RNG_0202f388) & one4;
    s32 v;
    if (xf != 0) {
      register s32 vf asm("r0");
      register u32 c10 asm("r1");
      vf = p->flags;
      c10 = 0x10;
      vf |= c10;
      v = vf;
    } else {
      register u8 lf2 asm("r1");
      register s32 vv2 asm("r0");
      lf2 = p->flags;
      vv2 = 0xEF;
      vv2 &= lf2;
      v = vv2;
    }
    p->flags = v;
    {
      register u32 t4 asm("r4");
      t4 = 1;
      one9 = t4;
    }
    {
      register u32 x1 asm("r1");
      x1 = one9;
      x1 &= xf;
      (p->spr).xflip = x1;
      {
        u8* a = (u8*)p + 0x4a;
        s32 sh = x1 << 4;
        u8 b = *a;
        s32 msk = -0x11;
        msk &= b;
        msk |= sh;
        *a = msk;
      }
    }
    {
      u8* pr = (u8*)p + 0x49;
      u8 b2 = *pr;
      s32 m2 = -0xD;
      m2 &= b2;
      *pr = m2;
    }
    {
      register u32* rp8 asm("r8");
      register u32 A3 asm("r5");
      register u32 C3 asm("r3");
      u32 sd;
      register u32 raw1 asm("r1");
      u32 raw2;
      u32 raw3;
      register u32 seed2 asm("r2");
      register u32 seed3 asm("r6");
      u32 r1a;
      u32 w1;
      u32 ang;
      rp8 = &RNG_0202f388;
      sd = *rp8;
      asm("" : "+r"(sd));
      A3 = 0x343FD;
      asm("" : "+r"(A3));
      raw1 = sd * A3;
      C3 = 0x269EC3;
      asm("" : "+r"(C3));
      raw1 += C3;
      raw1 <<= 1;
      seed2 = raw1 >> 1;
      r1a = (raw1 >> 0x11) & 0x7F;
      one4 += 0xFF;
      asm("" : "+r"(one4));
      {
        register u32 cc0 asm("r0");
        cc0 = one4;
        asm("" : "+r"(cc0));
        r1a += cc0;
      }
      w1 = p->work[1] << 6;
      raw2 = seed2 * A3;
      raw2 += C3;
      raw2 <<= 1;
      seed3 = raw2 >> 1;
      ang = (u8)(w1 + ((raw2 >> 0x11) & 0x3F));
      {
        u8* w = (u8*)p + 0x50;
        *(u16*)w = r1a;
        r1a >>= 1;
        w += 2;
        *(u16*)w = r1a;
        w -= 0x2E;
        *w = ang;
      }
      raw3 = seed3 * A3;
      raw3 += C3;
      raw3 <<= 1;
      {
        u32 s3v = raw3 >> 1;
        register u32* rl asm("r2");
        rl = rp8;
        *rl = s3v;
      }
      p->work[2] = (raw3 >> 0x11) % 0x14;
      p->work[3] = ang;
      *(s32*)((u8*)p + 0x64) = 0x80;
      *(s32*)((u8*)p + 0x68) = 0x10;
    }
    {
      u32 tbl, id;
      EntityFunc** routine_table;
      tbl = (u32)gVFXFnTable;
      id = (p->id) << 2;
      routine_table = (EntityFunc**)(tbl + id);
      {
        register u32 m4 asm("r4");
        m4 = one9;
        asm("" : "+r"(m4));
        *(u32*)(p->mode) = m4;
      }
      p->onUpdate = (void*)(*routine_table)[1];
    }
  }
  BossExplosion_Update((BossExplosion*)p);
}

static void FUN_080c7bc4(BossExplosion* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM000_BATTLE_EFFECT, 1));
  UpdateSpriteAnimation(p);
  (p->d).x = COS(p->work[1]), (p->d).y = SIN(p->work[1]);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  BossExplosion_Update(p);
}

static void initFireball(BossExplosion* p) {
  EnableSpriteAnimation_Affine(p);
  p->flags |= DISPLAY;
  SetSpriteTableDynamic(p);
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM199_BOSS_EXPLOSION, 0));
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, FALSE);
  (p->spr).oam.priority = 1;
  (p->spr).mag.y = (p->spr).mag.x = 0x10;
  p->angle = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  BossExplosion_Update(p);
}

NAKED static void FUN_080c7cc0(BossExplosion* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x28]\n\
	mov sb, r0\n\
	ldrb r6, [r7, #0xd]\n\
	cmp r6, #0\n\
	beq _080C7CDE\n\
	cmp r6, #1\n\
	beq _080C7DA0\n\
	b _080C7F52\n\
_080C7CDE:\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	ldrb r1, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	bhs _080C7D12\n\
	subs r0, r1, #1\n\
	strb r0, [r7, #0x12]\n\
	strb r6, [r7, #0x13]\n\
	mov r1, sb\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r4, #1\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	orrs r0, r4\n\
	str r0, [r1]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	strb r4, [r7, #0x11]\n\
	b _080C7D30\n\
_080C7D12:\n\
	mov r1, sb\n\
	adds r1, #0x8c\n\
	ldr r0, [r1]\n\
	movs r2, #2\n\
	rsbs r2, r2, #0\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r1]\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	mov r0, sb\n\
	bl UpdateEntityPaletteID\n\
	strb r6, [r7, #0x11]\n\
_080C7D30:\n\
	ldrb r0, [r7, #0x12]\n\
	cmp r0, #1\n\
	bls _080C7D38\n\
	b _080C7F52\n\
_080C7D38:\n\
	adds r1, r7, #0\n\
	adds r1, #0x80\n\
	movs r0, #0x80\n\
	strh r0, [r1]\n\
	movs r0, #0x30\n\
	bl PlaySound\n\
	ldr r4, _080C7D8C @ =0x00001298\n\
	ldr r1, _080C7D90 @ =gStaticMotionGraphics\n\
	adds r0, r4, r1\n\
	ldr r1, _080C7D94 @ =wStaticGraphicTilenums\n\
	movs r5, #0xee\n\
	lsls r5, r5, #1\n\
	adds r1, r1, r5\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _080C7D98 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r3\n\
	ldr r0, _080C7D9C @ =wStaticMotionPalIDs\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r7, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xd]\n\
	b _080C7F52\n\
	.align 2, 0\n\
_080C7D8C: .4byte 0x00001298\n\
_080C7D90: .4byte gStaticMotionGraphics\n\
_080C7D94: .4byte wStaticGraphicTilenums\n\
_080C7D98: .4byte gStaticMotionGraphics+12\n\
_080C7D9C: .4byte wStaticMotionPalIDs\n\
_080C7DA0:\n\
	ldrb r1, [r7, #0x12]\n\
	adds r0, r1, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #1\n\
	bls _080C7DCC\n\
	mov r5, sb\n\
	adds r5, #0x8c\n\
	ldr r0, [r5]\n\
	orrs r0, r6\n\
	str r0, [r5]\n\
	mov r4, sb\n\
	adds r4, #0x90\n\
	ldr r0, [r4]\n\
	orrs r0, r6\n\
	str r0, [r4]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	strb r6, [r7, #0x11]\n\
	b _080C7DEE\n\
_080C7DCC:\n\
	mov r5, sb\n\
	adds r5, #0x8c\n\
	ldr r0, [r5]\n\
	movs r1, #2\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	str r0, [r5]\n\
	mov r4, sb\n\
	adds r4, #0x90\n\
	ldr r0, [r4]\n\
	ands r0, r1\n\
	str r0, [r4]\n\
	mov r0, sb\n\
	bl UpdateEntityPaletteID\n\
	movs r0, #0\n\
	strb r0, [r7, #0x11]\n\
_080C7DEE:\n\
	str r5, [sp, #8]\n\
	str r4, [sp, #0xc]\n\
	movs r1, #0x80\n\
	adds r1, r1, r7\n\
	mov sl, r1\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x28\n\
	bne _080C7E12\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	mov r0, sb\n\
	mov r1, sp\n\
	movs r2, #3\n\
	movs r3, #0\n\
	bl FUN_080c7984\n\
_080C7E12:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7E6C\n\
	ldr r3, _080C7F64 @ =RNG_0202f388\n\
	mov r8, r3\n\
	ldr r0, [r3]\n\
	ldr r5, _080C7F68 @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r5, r1\n\
	ldr r3, _080C7F6C @ =0x00269EC3\n\
	adds r1, r1, r3\n\
	lsls r1, r1, #1\n\
	lsrs r6, r1, #1\n\
	lsrs r1, r1, #0x11\n\
	movs r4, #0x7f\n\
	ands r1, r4\n\
	movs r2, #0x40\n\
	subs r1, r2, r1\n\
	lsls r1, r1, #8\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	adds r0, r6, #0\n\
	muls r0, r5, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	mov r3, r8\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r4\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	ldr r0, [r7, #0x58]\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	movs r0, #1\n\
	mov r1, sp\n\
	bl CreateSmoke\n\
_080C7E6C:\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	bne _080C7ED8\n\
	ldr r2, _080C7F64 @ =RNG_0202f388\n\
	mov r8, r2\n\
	ldr r0, [r2]\n\
	ldr r3, _080C7F68 @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r3, r1\n\
	ldr r4, _080C7F6C @ =0x00269EC3\n\
	adds r1, r1, r4\n\
	lsls r1, r1, #1\n\
	lsrs r6, r1, #1\n\
	lsrs r1, r1, #0x11\n\
	movs r5, #0x1f\n\
	ands r1, r5\n\
	movs r2, #0x10\n\
	subs r1, r2, r1\n\
	lsls r1, r1, #8\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [sp]\n\
	adds r0, r6, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	ands r0, r5\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	ldr r0, [r7, #0x58]\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	muls r3, r1, r3\n\
	adds r3, r3, r4\n\
	lsls r3, r3, #1\n\
	lsrs r0, r3, #1\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	lsrs r3, r3, #0x11\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	adds r0, r7, #0\n\
	mov r1, sp\n\
	movs r2, #2\n\
	bl FUN_080c7984\n\
_080C7ED8:\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	movs r1, #0x12\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7EEE\n\
	movs r0, #0x35\n\
	bl PlaySound\n\
_080C7EEE:\n\
	mov r3, sl\n\
	ldrh r0, [r3]\n\
	movs r1, #6\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C7F18\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldrb r3, [r7, #0x12]\n\
	lsrs r3, r3, #1\n\
	movs r0, #3\n\
	ands r3, r0\n\
	adds r0, r7, #0\n\
	mov r1, sp\n\
	movs r2, #1\n\
	bl FUN_080c7984\n\
_080C7F18:\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	ldr r1, _080C7F70 @ =0xFFFF0000\n\
	cmp r0, r1\n\
	bne _080C7F52\n\
	ldr r2, [sp, #8]\n\
	ldr r0, [r2]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	ldr r3, [sp, #0xc]\n\
	ldr r0, [r3]\n\
	orrs r0, r1\n\
	str r0, [r3]\n\
	mov r0, sb\n\
	bl PaintEntityWhite\n\
	ldr r1, _080C7F74 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
_080C7F52:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C7F64: .4byte RNG_0202f388\n\
_080C7F68: .4byte 0x000343FD\n\
_080C7F6C: .4byte 0x00269EC3\n\
_080C7F70: .4byte 0xFFFF0000\n\
_080C7F74: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080c7f78(BossExplosion* p) {
  UpdateSpriteAnimation(p);
  (p->unk_coord).x += (0xFF - (p->unk_coord).x) * 80 / 256;
  (p->unk_coord).y += (0xFF - (p->unk_coord).y) * 12 / 256;
  (p->spr).mag.x = (p->unk_coord).x;
  (p->spr).mag.y = (p->unk_coord).y;
  p->work[3]++;
  p->angle = p->work[3];
  p->work[2]--;
  if (p->work[2] == 0xFF) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

static void FUN_080c7ff0(BossExplosion* p) {
  UpdateSpriteAnimation(p);
  (p->coord).x += (p->d).x;
  (p->coord).y += (p->d).y;
  if (IsSpriteAnimEnd(p)) SET_VFX_ROUTINE(p, ENTITY_DIE);
}

static void updateFireball(BossExplosion* p) {
  Entity* boss = p->unk_28;
  UpdateSpriteAnimation(p);
  if ((p->spr).mag.x <= 0x1FF) {
    (p->spr).mag.x += 4;
    (p->spr).mag.y += 4;
  }
  if (boss->mode[0] == ENTITY_EXIT) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    p->flags &= ~DISPLAY;
  }
}

// --------------------------------------------

static void FUN_080c8084(BossExplosion* p) {
  Boss* boss = (Boss*)p->unk_28;
  if (p->mode[2] == 0) {
    p->work[2] = 0;
    p->mode[2]++;
  }
  if ((p->work[2]++ & 3) > 1) {
    (boss->body).status |= BODY_STATUS_WHITE;
    (boss->body).prevStatus |= BODY_STATUS_WHITE;
    PaintEntityWhite((void*)boss);
    p->work[1] = 1;
  } else {
    (boss->body).status &= ~BODY_STATUS_WHITE;
    (boss->body).prevStatus &= ~BODY_STATUS_WHITE;
    UpdateEntityPaletteID((void*)boss);
    p->work[1] = 0;
  }
  if (boss->mode[0] == ENTITY_EXIT) {
    p->flags &= ~DISPLAY;
    SET_VFX_ROUTINE(p, ENTITY_EXIT);
  }
}

static void FUN_080c810c(BossExplosion* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void FUN_080c8124(BossExplosion* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

static void deleteFireball(BossExplosion* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }
