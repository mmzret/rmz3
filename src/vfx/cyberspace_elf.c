#include "cyberelf.h"
#include "global.h"
#include "vfx.h"

/*
  ゼロがサイバー空間に入った時にゼロの周りを飛ぶエルフ
*/

static void CyberSpaceElf_Init(struct VFX *vfx);
void CyberSpaceElf_Update(struct VFX *vfx);
void CyberSpaceElf_Die(struct VFX *vfx);

// clang-format off
const VFXRoutine gCyberSpaceElfRoutine = {
    [ENTITY_INIT] =      CyberSpaceElf_Init,
    [ENTITY_MAIN] =      CyberSpaceElf_Update,
    [ENTITY_DIE] =       CyberSpaceElf_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateCyberSpaceElf(struct Coord *c, u8 kind, u8 r2) {
  struct VFX *p = (struct VFX *)AllocEntityFirst(gVFXHeaderPtr);
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

WIP static void CyberSpaceElf_Init(struct VFX *vfx) {
#if MODERN
  SET_VFX_ROUTINE(vfx, ENTITY_MAIN);
  InitNonAffineMotion(&vfx->s);
  ResetDynamicMotion(&vfx->s);
  (vfx->s).flags |= DISPLAY;
  (vfx->s).flags |= FLIPABLE;
  SetMotion(&vfx->s, GetElfMotion((vfx->s).work[0]));
  {
    const bool8 xflip = FALSE;
    (vfx->s).flags &= ~X_FLIP;
    (vfx->s).spr.xflip = xflip;
    (vfx->s).spr.oam.xflip = xflip;
  }
  (vfx->s).coord.y -= PIXEL(18);
  (vfx->props).afterImage.c = (vfx->s).coord;
  (vfx->s).work[2] = 0;
  (vfx->s).work[3] = 0x80;
  CyberSpaceElf_Update(vfx);
#else
  INCCODE("asm/wip/CyberSpaceElf_Init.inc");
#endif
}

INCASM("asm/vfx/cyberspace_elf.inc");
