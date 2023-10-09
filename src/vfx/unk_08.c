#include "entity.h"
#include "global.h"
#include "vfx.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void Ghost8_Init(struct VFX* p);
void Ghost8_Update(struct VFX* p);
void Ghost8_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost8Routine = {
    [ENTITY_INIT] =      Ghost8_Init,
    [ENTITY_UPDATE] =    Ghost8_Update,
    [ENTITY_DIE] =       Ghost8_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateGhost8(struct Coord* c, u8 n, u8 x, u16 y) {
  struct VFX* p = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 1;
    INIT_VFX_ROUTINE(p, VFX_UNK_008);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).coord = *c;
    (p->s).work[1] = n;
    (p->props).unk8.unk_0 = x;
    (p->props).unk8.unk_4 = y;
  }
}

INCASM("asm/vfx/unk_08.inc");
