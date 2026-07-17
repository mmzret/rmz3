#include "cyberelf.h"
#include "global.h"
#include "vfx.h"

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
void CyberSpaceElf_Die(struct VFX* vfx);

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

void FUN_080bfd98(struct Coord* c, u8 r1, u8 r2);

INCASM("asm/vfx/cyberspace_elf_a.inc");

void CyberSpaceElf_Die(struct VFX* vfx) {
  FUN_080bfd98(&(vfx->s).coord, 1, (vfx->s).work[1]);
  SET_VFX_ROUTINE(vfx, ENTITY_EXIT);
}
