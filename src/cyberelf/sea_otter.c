#include "cyberelf.h"
#include "global.h"

// 敵の動きを止めるサイバーエルフ

void SeaOtterElf_Init(CyberElf* p);
void SeaOtterElf_Update(CyberElf* p);
void SeaOtterElf_Die(CyberElf* p);

// clang-format off
const ElfRoutine gSeaOtterElfRoutine = {
    [ENTITY_INIT] =      (void*)SeaOtterElf_Init,
    [ENTITY_UPDATE] =    (void*)SeaOtterElf_Update,
    [ENTITY_DIE] =       (void*)SeaOtterElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void MenuExit_SeaOtterElf(CyberElf* e) {
  CyberElf* linked = *(CyberElf**)e->buffer;
  register u32 z asm("r2");
  register u8 fl asm("r0");
  register u8 fv asm("r1");
  z = e->work[2];
  if (z == 0) {
    if (e->work[3] == linked->buffer[0]) {
      return;
    }
    fv = e->flags;
    fl = ~DISPLAY & fv;
  } else {
    u8* b = linked->buffer;
    if (e->work[3] == b[1]) {
      return;
    }
    fv = e->flags;
    fl = ~DISPLAY & fv;
    z = 0;
  }
  fl &= ~FLIPABLE;
  e->flags = fl;
  (e->body).status = z;
  (e->body).prevStatus = z;
  (e->body).invincibleTime = z;
  e->flags &= ~COLLIDABLE;
  SET_ELF_ROUTINE(e, ENTITY_DISAPPEAR);
  if (e->unk_2c != NULL) {
    (e->unk_2c)->flags2 &= 0x7f;
  }
}

INCASM("asm/cyberelf/sea_otter.inc");

void FUN_080e4a3c(CyberElf* p);
void FUN_080e4a88(CyberElf* p);
void FUN_080e4ae8(CyberElf* p);
static void FUN_080e4b58(CyberElf* p);

// 0x08371dc0
static const CyberElfFunc sUpdates[4] = {
    FUN_080e4a3c,
    FUN_080e4a88,
    FUN_080e4ae8,
    FUN_080e4b58,
};

static void FUN_080e4b58(CyberElf* p) {
  if (p->mode[2] == 0) {
    p->mode[3] = 64;
    p->mode[2]++;
  }

  if ((p->d).x > 0x90) {
    p->mode[3]--;
    if (p->mode[3] != 0xFF) {
      return;
    }
  }

  p->mode[1] = 0, p->mode[2] = 0;
}
