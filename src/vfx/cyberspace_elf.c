#include "cyberelf.h"
#include "global.h"
#include "vfx.h"

/*
  ゼロがサイバー空間に入った時にゼロの周りを飛ぶエルフ
*/

static void CyberSpaceElf_Init(struct VFX* vfx);
void CyberSpaceElf_Update(struct VFX* vfx);
void CyberSpaceElf_Die(struct VFX* vfx);

// clang-format off
const VFXRoutine gCyberSpaceElfRoutine = {
    [ENTITY_INIT] =      CyberSpaceElf_Init,
    [ENTITY_UPDATE] =    CyberSpaceElf_Update,
    [ENTITY_DIE] =       CyberSpaceElf_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateCyberSpaceElf(struct Coord* c, u8 kind, u8 r2) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_CS_ELF);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord = *c;
    (p->s).work[0] = kind;
    (p->s).work[1] = r2;
  }
}

static void CyberSpaceElf_Init(struct VFX* p) {
  s32 y;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  InitNonAffineMotion(&p->s);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetMotion(&p->s, GetElfMotion((p->s).work[0]));
  SET_XFLIP(p, FALSE);
  y = (p->s).coord.y - PIXEL(18);
  (p->s).coord.y = y;
  (p->props).tmp.c.x = (p->s).coord.x;
  (p->props).tmp.c.y = y;
  (p->s).work[2] = 0;
  (p->s).work[3] = 0x80;
  CyberSpaceElf_Update(p);
}

INCASM("asm/vfx/cyberspace_elf.inc");
