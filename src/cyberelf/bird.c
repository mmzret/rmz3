#include "cyberelf.h"
#include "global.h"

static const ElfFunc sUpdates[2];

void BirdElf_Init(CyberElf* p);
void BirdElf_Update(CyberElf* p);
void BirdElf_Die(CyberElf* p);

// clang-format off
const ElfRoutine gBirdElfRoutine = {
    [ENTITY_INIT] =      (void*)BirdElf_Init,
    [ENTITY_UPDATE] =    (void*)BirdElf_Update,
    [ENTITY_DIE] =       (void*)BirdElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void FUN_080e58bc(CyberElf* p) {
  CyberElf* e = *(CyberElf**)p->buffer;
  register u32 z asm("r2");
  register u8 fl asm("r0");
  register u8 fv asm("r1");
  z = p->work[2];
  if (z == 0) {
    if (p->work[3] == e->buffer[0]) {
      return;
    }
    fv = p->flags;
    fl = ~DISPLAY & fv;
  } else {
    u8* b = e->buffer;
    if (p->work[3] == b[1]) {
      return;
    }
    fv = p->flags;
    fl = ~DISPLAY & fv;
    z = 0;
  }
  fl &= ~FLIPABLE;
  p->flags = fl;
  (p->body).status = z;
  (p->body).prevStatus = z;
  (p->body).invincibleTime = z;
  p->flags &= ~COLLIDABLE;
  SET_ELF_ROUTINE(p, ENTITY_DISAPPEAR);
}

void FUN_080e5b74(CyberElf* p);
void FUN_080e5d68(CyberElf* p);

static const ElfFunc sUpdates[2] = {
    (void*)FUN_080e5b74,
    (void*)FUN_080e5d68,
};

INCASM("asm/cyberelf/bird.inc");
