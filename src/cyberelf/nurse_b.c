#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

void FUN_080bfce8(struct Coord* c, s32 r1);
struct Entity* FUN_080bfc94(struct Coord* c, u8 r1);
bool8 FUN_080e1578(struct Coord* c1, struct Coord* c2, struct Coord* c3, u8* param_4, s16 param_5);

struct CyberElfNurseB {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8[12];         // 0xB8
};
static_assert(sizeof(struct CyberElfNurseB) == sizeof(CyberElf));

struct Entity* CreateElf3(struct Entity* nurse_b, struct Entity* z);

void NurseB_Init(CyberElf* p);
void NurseB_Update(CyberElf* p);
void NurseB_Die(CyberElf* p);

// clang-format off
const ElfRoutine gNurseBRoutine = {
    [ENTITY_INIT] =      (void*)NurseB_Init,
    [ENTITY_UPDATE] =    (void*)NurseB_Update,
    [ENTITY_DIE] =       (void*)NurseB_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


const CyberElfFunc sNurseBUpdates[4];
struct Entity* CreateNurseBElf(struct Zero* z, u8 breed, u8 availability, u8 satelite_slot) {
  struct CyberElfNurseB* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 2);
    p->player = z;
    p->work[0] = breed, p->work[1] = availability, p->work[2] = satelite_slot;
    if (satelite_slot == 0) {
      p->work[3] = ((&z->unk_b4)->status).satelites[0];
    } else {
      p->work[3] = ((&z->unk_b4)->status).satelites[1];
    }
  }
  return (struct Entity*)p;
}

void NurseB_Init(CyberElf* p) {
  struct Zero* z = ((struct CyberElfNurseB*)p)->player;
  struct Rect rr = gZeroRanges[*((u8*)z + 0x147)];
  s32 z8;
  InitNonAffineMotion((struct Entity*)p);
  ResetDynamicMotion((struct Entity*)p);
  {
    register s32 c1 asm("r0");
    register s32 f1 asm("r1");
    f1 = p->flags;
    c1 = 1;
    asm("" : "+r"(c1));
    z8 = 0;
    c1 = c1 | f1;
    c1 |= 2;
    p->flags = c1;
  }
  SetMotion((struct Entity*)p, GetElfMotion(0));
  UpdateEntityAnim((struct Entity*)p);
  (p->spr).xflip = z8;
  {
    u8* oa = (u8*)&(p->spr).oam + 6;
    s32 ov = *oa;
    s32 m11 = -0x11;
    asm("" : "+r"(m11));
    *oa = m11 & ov;
    p->flags &= 0xEF;
  }
  p->coord.x = (z->s).coord.x + rr.x;
  p->coord.y = (z->s).coord.y + rr.y;
  {
    s32* b = (s32*)&((struct CyberElfNurseB*)p)->unk_b8[4];
    b[0] = z8;
    b[1] = z8;
  }
  if (p->work[2] != 0) {
    ((struct CyberElfNurseB*)p)->unk_b8[0] = z8;
  } else {
    ((struct CyberElfNurseB*)p)->unk_b8[0] = 8;
  }
  ((struct CyberElfNurseB*)p)->unk_b8[1] = 0x20;
  CreateElf3((struct Entity*)p, (struct Entity*)z);
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  NurseB_Update(p);
}

void NurseB_Update(CyberElf* p) {
  struct CyberElfNurseB* q = (struct CyberElfNurseB*)p;
  struct Zero* z = q->player;
  struct Rect rr = gZeroRanges[*((u8*)z + 0x147)];
  UpdateEntityAnim((struct Entity*)p);
  {
    u8 v = gPause;
    if (v == 0) {
      if (*((u8*)z + 0x232) != 0) {
        u8 f = ~DISPLAY & p->flags;
        f = f & ~FLIPABLE;
        p->flags = f;
        (p->body).status = v;
        (p->body).prevStatus = v;
        (p->body).invincibleTime = v;
        p->flags &= ~COLLIDABLE;
        SET_ELF_ROUTINE(p, ENTITY_DISAPPEAR);
      } else if (((z->body).status & 0x200) || ((z->body).hp == 0)) {
        SET_ELF_ROUTINE(p, ENTITY_DIE);
      } else {
        p->unk_coord.x = (z->s).coord.x + rr.x;
        p->unk_coord.y = (z->s).coord.y + rr.y;
        (sNurseBUpdates[p->mode[1]])(p);
        {
          u8* a8 = &q->unk_b8[0];
          s32* b;
          register s32 t asm("r3");
          s32 d, idx, s;
          t = *a8 + 1;
          d = t;
          asm("" : "+r"(d));
          d >>= 4;
          d <<= 4;
          t -= d;
          idx = t;
          *a8 = t;
          t <<= 4;
          s = gSineTable[(u8)(idx << 4)] << 4;
          b = (s32*)&q->unk_b8[4];
          p->coord.x = (b[0] + s) + p->unk_coord.x;
          p->coord.y = b[1] + p->unk_coord.y;
          {
            register s32 u asm("r0");
            s32 k;
            u = t + 0x40;
            u &= 0xFF;
            k = 0x10;
            if (u > 0x7F) {
              k = 0x11;
            }
            p->renderPrio = k;
          }
          {
            u8* a9 = &q->unk_b8[1];
            s32 raw = *a9 - 1;
            *a9 = raw;
            if ((u8)raw == 0xFF) {
              FUN_080bfc94(&p->coord, 2);
              *a9 = 0x20;
            }
          }
        }
      }
    }
  }
}

void NurseB_Die(CyberElf* p) {
  FUN_080bfce8(&p->coord, 0);
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080e284c(CyberElf* p) {
  struct Coord c;
  struct Zero* z = *(struct Zero**)&p->buffer[0];
  c.x = (z->s).coord.x;
  c.y = (z->s).coord.y;
  {
    bool8 hit;
    if (p->work[2] != 0) {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0x180);
    } else {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0xC0);
    }
    if (hit) {
      p->mode[1] = (p->mode[1] + 1) & 3;
    }
  }
}

void FUN_080e28a8(CyberElf* p) {
  struct Coord c;
  struct Zero* z = *(struct Zero**)&p->buffer[0];
  struct Rect r = gZeroRanges[z->posture];
  c.x = (z->s).coord.x;
  c.y = (z->s).coord.y + r.y;
  {
    bool8 hit;
    if (p->work[2] != 0) {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0x180);
    } else {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0xC0);
    }
    if (hit) {
      p->mode[1] = (p->mode[1] + 1) & 3;
    }
  }
}

void FUN_080e2920(CyberElf* p) {
  struct Coord c;
  struct Zero* z = *(struct Zero**)&p->buffer[0];
  struct Rect r = gZeroRanges[z->posture];
  c.x = (z->s).coord.x;
  c.y = (z->s).coord.y - r.h;
  {
    bool8 hit;
    if (p->work[2] != 0) {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0x180);
    } else {
      hit = FUN_080e1578((struct Coord*)&p->buffer[8], &p->unk_coord, &c, &p->buffer[6], 0xC0);
    }
    if (hit) {
      p->mode[1] = (p->mode[1] + 1) & 3;
    }
  }
}

// --------------------------------------------

void FUN_080e284c(CyberElf* p);
void FUN_080e28a8(CyberElf* p);
void FUN_080e2920(CyberElf* p);
void FUN_080e28a8(CyberElf* p);

const CyberElfFunc sNurseBUpdates[4] = {
    FUN_080e284c,
    FUN_080e28a8,
    FUN_080e2920,
    FUN_080e28a8,
};
