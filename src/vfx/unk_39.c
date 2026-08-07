#include "global.h"
#include "gpu_regs.h"
#include "gfx.h"
#include "vfx.h"

struct VFX39 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  u8 unk_74[4];
  u8 unk_78[4];
  u8 winin1;
  u8 winout;
  u32 pad_80;
};
static_assert(sizeof(struct VFX39) == sizeof(struct VFX));

static void VFX39_Init(struct VFX39* p);
static void VFX39_Update(struct VFX* vfx);
void VFX39_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gVFX39Routine = {
    [ENTITY_INIT] =       (VFXFunc)VFX39_Init,
    [ENTITY_UPDATE] =     (VFXFunc)VFX39_Update,
    [ENTITY_DIE] =        (VFXFunc)VFX39_Die,
    [ENTITY_DISAPPEAR] =  (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// 0x080bd3bc
struct Entity* CreateVFX39(Coords32* c, u8 r1, u8 r2) {
  struct VFX39* p = (struct VFX39*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_039);
    (p->s).coord = *c;
    (p->s).work[0] = r1;
    (p->s).work[1] = r2;
    p->winin1 = 0x31;
    p->winout = 0x0E;
  }
  return (void*)p;
}

// --------------------------------------------

void TaskCB_080bd610(struct Sprite* s, struct DrawPivot* c);

static void VFX39_Init(struct VFX39* p) {
  SetTaskCallback((void*)&(p->s).spr, TaskCB_080bd610);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~USE_COMMON_OAM_RENDERER;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  p->unk_74[3] = 0;
  (p->s).d.y = PIXEL(0);
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  VFX39_Update((void*)p);
}

// --------------------------------------------

void FUN_080bd48c(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);
void FUN_080bd578(struct VFX* vfx);

static void VFX39_Update(struct VFX* vfx) {
  static const VFXFunc sUpdates[4] = {
      FUN_080bd48c,
      FUN_080bd578,
      FUN_080bd578,
      FUN_080bd578,
  };
  (sUpdates[(vfx->s).work[0]])(vfx);
}

// --------------------------------------------

void FUN_080bd48c(struct VFX* p) {
  if ((p->s).mode[2] == 0) {
    register s32 z asm("r3");
    {
      register u16 d asm("r2");
      register s32 v asm("r0");
      d = gWindowRegBuffer.dispcnt;
      z = DISPCNT_WIN1_ON;
      asm volatile("add %0, %1, #0" : "=&l"(v) : "l"(z));
      z = 0;
      v |= d;
      gWindowRegBuffer.dispcnt = v;
    }
    gWindowRegBuffer.winin[1] = 0x31;
    gWindowRegBuffer.winin[2] |= 0xE;
    *(s32*)((u8*)p + 0x78) = 0x2000;
    *(u8*)((u8*)p + 0x74) = z;
    *(u8*)((u8*)p + 0x75) = z;
    *(u8*)((u8*)p + 0x76) = z;
    (p->s).mode[2]++;
  }
  if (gJoypad[0].input & 1) {
    register s32 amt asm("r3");
    register s32 v asm("r0");
    register u8* q asm("r2");
    q = (u8*)p;
    v = *(s32*)(q + 0x78);
    amt = 0x100;
    asm("" : "+r"(amt));
    v += amt;
    *(s32*)(q + 0x78) = v;
  } else if (gJoypad[0].input & 2) {
    register s32 amt2 asm("r3");
    register s32 v2 asm("r0");
    register u8* q2 asm("r2");
    q2 = (u8*)p;
    v2 = *(s32*)(q2 + 0x78);
    amt2 = -0x100;
    asm("" : "+r"(amt2));
    v2 += amt2;
    *(s32*)(q2 + 0x78) = v2;
  }
  if ((gJoypad[0].input & 0x300) == 0x300) {
    register u8* a asm("r1");
    a = (u8*)p;
    *(s32*)(a + 0x60) = 0;
  } else if (gJoypad[0].input & 0x100) {
    register u8* b asm("r2");
    s32 v;
    b = (u8*)p;
    v = *(s32*)(b + 0x60);
    v += 0x10;
    *(s32*)(b + 0x60) = v;
  } else if (gJoypad[0].input & 0x200) {
    register u8* c asm("r3");
    s32 v;
    c = (u8*)p;
    v = *(s32*)(c + 0x60);
    v -= 0x10;
    *(s32*)(c + 0x60) = v;
  }
  {
    s32 w = (p->s).work[3] + 1;
    (p->s).work[3] = w;
    if (w & 1) {
      *(u8*)((u8*)p + 0x74) = 0x1F;
      *(u8*)((u8*)p + 0x75) = 0x1F;
      *(u8*)((u8*)p + 0x76) = 0x1F;
    } else {
      *(u8*)((u8*)p + 0x74) = 0x18;
      *(u8*)((u8*)p + 0x75) = 0x1F;
      *(u8*)((u8*)p + 0x76) = 0x18;
    }
  }
}

void FUN_080bd578(struct VFX* p) {
  register u8 m asm("r4");
  m = (p->s).mode[2];
  if (m == 0) {
    gWindowRegBuffer.dispcnt |= DISPCNT_WIN1_ON;
    gWindowRegBuffer.winin[1] = *(u8*)((u8*)p + 0x7c);
    gWindowRegBuffer.winin[2] |= *(u8*)((u8*)p + 0x7d);
    (p->s).mode[2] = m + 1;
    asm volatile("" :: "r"(m));
  }
  if (*(u8*)((u8*)p + 0x77) != 0) {
    SET_VFX_ROUTINE(p, 2);
  }
}

void VFX39_Die(struct VFX* p) {
  (*(u16*)(&gPaletteManager.buf[0])) = 0;
  gWindowRegBuffer.dispcnt &= 0xBFFF;
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_39_a.inc");
