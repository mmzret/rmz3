#include "collision.h"
#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "score.h"
#include "zero.h"

// NurseB (Elf2) に従属する何か

static void Elf3_Init(CyberElf* p);
void Elf3_Update(CyberElf* p);
void Elf3_Die(CyberElf* p);

// clang-format off
const ElfRoutine gElf3Routine = {
    [ENTITY_INIT] =      (void*)Elf3_Init,
    [ENTITY_UPDATE] =    (void*)Elf3_Update,
    [ENTITY_DIE] =       (void*)Elf3_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateElf3(struct Entity* nurse_b, struct Entity* z) {
  struct Entity* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 3);
    p->unk_28 = nurse_b;
    p->unk_2c = z;
    p->work[0] = 0, p->work[1] = nurse_b->work[1];
  }
  return p;
}

// --------------------------------------------

static const struct Collision sElf3Collisions[];
void FUN_080e2af0(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void Elf3_Init(CyberElf* p) {
  p->flags |= FLIPABLE;
  (p->spr).xflip = FALSE, (p->spr).oam.xflip = FALSE;
  p->flags &= ~X_FLIP;
  INIT_BODY(p, sElf3Collisions, 1, FUN_080e2af0);
  p->work[2] = 0;
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  Elf3_Update(p);
}

void Elf3_Update(CyberElf* p) {
  struct CollisionObject* t = (struct CollisionObject*)p->unk_2c;
  if (p->unk_28->mode[0] > 1 || t->body.hp == 0) {
    SET_ELF_ROUTINE(p, ENTITY_DIE);
    Elf3_Die(p);
  } else {
    s32 x = t->coord.x;
    s32 y = t->coord.y;
    p->coord.x = x;
    p->coord.y = y;
    if (!(t->body.status & 0x200) && t->body.hp != 0 && p->work[2] != 0) {
      gLifeRecoverAmount += p->work[2] << 2;
      p->work[2] = 0;
    }
  }
}

void Elf3_Die(CyberElf* p) {
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080e2af0(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  CyberElf* p = (CyberElf*)body->parent;
  struct Entity* atk = (struct Entity*)(body->enemy)->parent;
  struct Entity* q = p->unk_28;
  struct Enemy* z = (struct Enemy*)p->unk_2c;
  if (!((z->body).status & BODY_STATUS_DEAD) && (z->body).hp != 0 &&
      (body->hitboxFlags & 0x800000) && atk->kind == 4) {
    u8 idx;
    if (atk->id != 0) {
      return;
    }
    if (q->work[2] == 0) {
      u8* pr = (u8*)z + 0xb4;
      idx = pr[0];
    } else {
      u8* pr = (u8*)z + 0xb4;
      idx = pr[1];
    }
    if (gElfAvailability[idx] & 4) {
      p->work[2] += 2;
    } else {
      p->work[2] += 1;
    }
    AddMissionDamage(2);
  }
}

void FUN_080e2b78(CyberElf* p0) {
  register CyberElf* p asm("r3");
  register u8 w asm("r2");
  struct Entity* q;
  p = p0;
  q = *(struct Entity**)((u8*)p + 0xb4);
  w = p->work[2];
  {
    register u8 fl asm("r0");
    u32 z;
    register u8* r asm("r0");
  if (w == 0) {
    if (p->work[3] == *(u8*)((u8*)q + 0xb4)) {
      return;
    }
    {
      register u8 t asm("r1");
      t = p->flags;
      fl = 0xFE;
      fl &= t;
      asm volatile("" :: "r"(t));
    }
    z = w;
  } else {
    register u8* b asm("r1");
    b = (u8*)q + 0xb4;
    asm("" : "+r"(b));
    if (p->work[3] == b[1]) {
      return;
    }
    {
      register u8 t asm("r1");
      t = p->flags;
      fl = 0xFE;
      fl &= t;
      asm volatile("" :: "r"(t));
    }
    z = 0;
  }
  fl &= 0xFD;
  p->flags = fl;
  r = (u8*)p + 0x8c;
  *(u32*)r = z;
  asm volatile("add %0, #4" : "+r"(r));
  *(u32*)r = z;
  asm volatile("add %0, #4" : "+r"(r));
  *r = z;
  p->flags &= 0xFB;
  SET_ELF_ROUTINE(p, 3);
  }
}

// 0x08371cf0
static const struct Collision sElf3Collisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x40,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0100, -0x0E00, 0x3400, 0x3200},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {-0x0100, -0x0E00, 0x3400, 0x3200},
    },
};
