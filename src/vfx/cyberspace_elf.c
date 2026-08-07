#include "cyberelf.h"
#include "global.h"
#include "vfx.h"

void FUN_080bfd98(struct Coord* c, u8 r1, u8 r2);

// VFX69 と同じ構造体?
// ゼロがサイバー空間に入った時にゼロの周りを飛ぶエルフ
struct CyberSpaceElf {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  Coords32 c74;  // 0x74
  u8 unk_7c[8];  // 0x7C
};
static_assert(sizeof(struct CyberSpaceElf) == sizeof(struct VFX));

static void CyberSpaceElf_Init(struct CyberSpaceElf* p);
void CyberSpaceElf_Update(struct VFX* p);
void CyberSpaceElf_Die(struct VFX* p);

// clang-format off
const VFXRoutine gCyberSpaceElfRoutine = {
    [ENTITY_INIT] =      (void*)CyberSpaceElf_Init,
    [ENTITY_UPDATE] =    (void*)CyberSpaceElf_Update,
    [ENTITY_DIE] =       (void*)CyberSpaceElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateCyberSpaceElf(Coords32* c, u8 kind, u8 r2) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_CS_ELF);
    p->coord = *c;
    p->work[0] = kind, p->work[1] = r2;
  }
}

static void CyberSpaceElf_Init(struct CyberSpaceElf* p) {
  s32 y;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, GetElfMotion((p->s).work[0]));
  SET_XFLIP(p, FALSE);
  y = (p->s).coord.y - PIXEL(18);
  (p->s).coord.y = y;
  (p->c74).x = (p->s).coord.x;
  (p->c74).y = y;
  (p->s).work[2] = 0;
  (p->s).work[3] = 0x80;
  CyberSpaceElf_Update((void*)p);
}

void CyberSpaceElf_Update(struct VFX* p) {
  register const s16* tb asm("r2");
  register s32 y asm("r1");
  register s32 x asm("r0");
  UpdateEntityAnim(&p->s);
  switch ((p->s).work[1]) {
    case 0: {
      register s32 sv asm("r1");
      tb = gSineTable;
      sv = tb[(p->s).work[2]];
      sv <<= 5;
      x = *(s32*)((u8*)p + 0x74);
      x += sv;
      (p->s).coord.x = x;
      {
        register s32 t asm("r0");
        t = tb[(u8)((p->s).work[2] + 0x40)];
        t <<= 2;
        y = *(s32*)((u8*)p + 0x78);
        y += t;
        t = 0x80 - (p->s).work[3];
        t <<= 9;
        y += t;
        asm volatile("");
      }
      goto sty;
    }
    case 1: {
      register s32 sv2 asm("r1");
      tb = gSineTable;
      sv2 = tb[(p->s).work[2]];
      sv2 <<= 5;
      x = *(s32*)((u8*)p + 0x74);
      x -= sv2;
      (p->s).coord.x = x;
      {
        register s32 t2 asm("r0");
        t2 = tb[(u8)((p->s).work[2] + 0x40)];
        t2 <<= 2;
        y = *(s32*)((u8*)p + 0x78);
        y += t2;
        t2 = 0x80 - (p->s).work[3];
        t2 <<= 9;
        y += t2;
      }
      goto sty;
    }
    case 2: {
      register s32 sv3 asm("r1");
      register s32 sq asm("r0");
      tb = gSineTable;
      {
        register s32 z3 asm("r3");
        const s16* bp = (const s16*)(((p->s).work[2] << 1) + (u32)tb);
        z3 = 0;
        sq = *(const s16*)((const u8*)bp + z3);
      }
      sv3 = sq * 2;
      sv3 += sq;
      sv3 <<= 3;
      x = *(s32*)((u8*)p + 0x74);
      x += sv3;
      goto common;
    }
    case 3: {
      register s32 sv4 asm("r1");
      register s32 sq2 asm("r0");
      tb = gSineTable;
      {
        const s16* bp = (const s16*)(((p->s).work[2] << 1) + (u32)tb);
        asm volatile("mov r3, #0\n\tldrsh %0, [%1, r3]" : "=l"(sq2) : "l"(bp) : "r3");
      }
      sv4 = sq2 * 2;
      sv4 += sq2;
      sv4 <<= 3;
      x = *(s32*)((u8*)p + 0x74);
      x -= sv4;
    common:
      (p->s).coord.x = x;
      {
        register s32 t3 asm("r0");
        {
          const s16* yp = (const s16*)((((u8)((p->s).work[2] + 0x40)) << 1) + (u32)tb);
          asm volatile("mov r1, #0\n\tldrsh %0, [%1, r1]" : "=l"(t3) : "l"(yp) : "r1");
        }
        t3 <<= 2;
        y = *(s32*)((u8*)p + 0x78);
        y -= t3;
        t3 = 0x80 - (p->s).work[3];
        t3 <<= 10;
        y -= t3;
      }
    sty:
      (p->s).coord.y = y;
      break;
    }
  }
  {
    register u32 w asm("r0");
    w = (u8)((p->s).work[2] - 0x41);
    if (w > 0x7E) {
      goto hi;
    }
    {
      register u8* tc asm("r1");
      register s32 v asm("r0");
      tc = (u8*)p + 0x25;
      v = 0x11;
      *tc = v;
    }
    w = (p->s).work[3] - 1;
    goto stw;
  hi : {
    register u8* tc2 asm("r1");
    register s32 v2 asm("r0");
    tc2 = (u8*)p + 0x25;
    v2 = 0xF;
    *tc2 = v2;
  }
    w = (p->s).work[3] + 1;
  stw:
    (p->s).work[3] = w;
  }
  (p->s).work[2] += 8;
  if ((u8)(p->s).work[2] == 0) {
    PlaySound(0x23);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    CyberSpaceElf_Die(p);
  }
}

void CyberSpaceElf_Die(struct VFX* vfx) {
  FUN_080bfd98(&(vfx->s).coord, 1, (vfx->s).work[1]);
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}
