#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "zero.h"

struct CyberElf7 {
  COLLISION_OBJECT_HDR;  // 0x00
  struct Zero* player;   // 0xB4
  u8 unk_b8[12];         // 0xB8
};
static_assert(sizeof(struct CyberElf7) == sizeof(CyberElf));

void Elf7_Init(CyberElf* p);
void Elf7_Update(CyberElf* p);
NON_MATCH void Elf7_Die(CyberElf* p);

// clang-format off
const ElfRoutine gElf7Routine = {
    [ENTITY_INIT] =      (void*)Elf7_Init,
    [ENTITY_UPDATE] =    (void*)Elf7_Update,
    [ENTITY_DIE] =       (void*)Elf7_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};

const u8 u8_ARRAY_08371d94[3];
// clang-format on

struct Entity* CreateElf7(struct Zero* z, u8 breed, u8 availability, u8 _) {
  struct CyberElf7* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 7);
    p->player = z;
    p->work[0] = breed, p->work[1] = availability;
  }
  return (struct Entity*)p;
}

void Elf7_Init(CyberElf* p) {
  struct Zero* z = ((struct CyberElf7*)p)->player;
  register s32 one asm("r4");
  u8 post;
  {
    register u8* gp asm("r0");
    gp = (u8*)&gPause;
    asm volatile("" : "+r"(gp));
    one = 1;
    *gp = one;
  }
  InitNonAffineMotion((struct Entity*)p);
  ResetDynamicMotion((struct Entity*)p);
  one |= p->flags;
  one |= 2;
  p->flags = one;
  post = *(u8*)((u8*)z + 0x121);
  if (post <= 0x1A) {
    SetMotion((struct Entity*)p, GetElfMotion(0));
  } else if (post <= 0x27) {
    SetMotion((struct Entity*)p, GetElfMotion(1));
  } else {
    SetMotion((struct Entity*)p, GetElfMotion(2));
  }
  SET_PLAYER_XFLIP((struct Entity*)p, ((z->s).flags >> 4) & 1);
  {
    u8 tv = u8_ARRAY_08371d94[p->work[0]];
    register u8* pb asm("r1");
    register s32 zz asm("r2");
    pb = (u8*)p + 0xba;
    zz = 0;
    *pb = tv;
    asm("" : "+r"(pb));
    pb += 6;
    asm("" : "+r"(pb));
    *(u32*)pb = 0xC00;
    {
      register u8* pc asm("r0");
      pc = (u8*)p + 0xb8;
      *pc = zz;
      asm("" : "+r"(pc));
      pc += 3;
      asm("" : "+r"(pc));
      *pc = zz;
    }
    asm("" : "+r"(pb));
    pb -= 7;
    asm("" : "+r"(pb));
    *pb = 0x20;
  }
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  Elf7_Update(p);
}

INCASM("asm/cyberelf/unk_7_a.inc");

NON_MATCH void Elf7_Die(CyberElf* p) {
#if MODERN
  u8* z = *(u8**)((u8*)p + 0xb4);
  gPause = 0;
  switch (*(z + 0x121) - 5) {
    case 0: {
      register u8* b asm("r1");
      u16 h2;
      u8 zz;
      b = z + 0xb4;
      h2 = *(u16*)(b + 4) + 3;
      zz = 0;
      *(u16*)(b + 4) = h2;
      *(b + 0xa) = zz;
      goto txt;
    }
    case 1: {
      register u8* b asm("r1");
      u16 h2;
      u8 zz;
      b = z + 0xb4;
      h2 = *(u16*)(b + 4) + 3;
      zz = 0;
      *(u16*)(b + 4) = h2;
      *(b + 0xb) = zz;
    }
    txt:
      PrintTextWindow(0x103, 0x5A);
      break;
    case 2:
    case 3: {
      u8* b = z + 0xb4;
      *(u16*)(b + 4) += 5;
      PlaySound(6);
      {
        u8* q = (u8*)gScore.unk_00;
        if (*q <= 8) {
          *q += 1;
          q = (u8*)gScore.unk_00;
          if (*q <= 8) {
            *q += 1;
            asm volatile("");
          }
        }
      }
      if (p->work[1] != 0) {
        u8* q2 = (u8*)gScore.unk_00;
        if (*q2 <= 8) {
          *q2 += 1;
          q2 = (u8*)gScore.unk_00;
          if (*q2 <= 8) {
            *q2 += 1;
          }
        }
      }
      break;
    }
    case 22: {
      u8* b = z + 0xb4;
      *(u16*)(b + 4) += 5;
      break;
    }
    case 23:
    case 24:
    case 25:
    case 26:
    case 38:
    case 40: {
      u8* b = z + 0xb4;
      *(u16*)(b + 4) += 3;
      break;
    }
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 39:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
      break;
  }
  {
    u8* c = (u8*)gScore.unk_00 + 0x4c;
    if (*c <= 0x62) {
      *c += 1;
    }
  }
  {
    register u32 idv asm("r0");
    u8* base;
    u8* slot;
    idv = *(z + 0x121);
    base = (u8*)*gUnlockedElfPtr;
    slot = base + idv;
    *slot |= 2;
  }
  {
    u8* b5 = (u8*)p + 0x49;
    s32 m5 = -0xD;
    asm("" : "+r"(m5));
    *b5 = (*b5 & m5) | 8;
  }
  FUN_080bfce8(&p->coord, 0);
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
#else
  INCCODE("asm/cyberelf/unk_7_die.inc");
#endif
}

void FUN_080e3f24(CyberElf* p) {
  s32* val = (s32*)((u8*)p + 0xc0);
  *val += 0x30;
  if (*val > 0x27FF) {
    *val = 0x2800;
    *((u8*)p + 0xbc) = 1;
    p->mode[1]++;
  }
}

void FUN_080e3f54(CyberElf* p) {
  u32 w = ((struct CyberElf7*)p)->unk_b8[4] - 1;
  ((struct CyberElf7*)p)->unk_b8[4] = w;
  if (w == 0) {
    p->mode[1]++;
  }
}

void FUN_080e3f70(CyberElf* p) {
  register struct Zero* z asm("r5") = ((struct CyberElf7*)p)->player;
  const struct Rect* zr;
  const struct Rect* rp;
  s32 w0, w1;
  register s32 rx asm("r0");
  s32 dx, dy, ox, oy, f, k, v;
  zr = gZeroRanges;
  asm("" : "+r"(zr));
  {
    register s32 idx asm("r0");
    register const struct Rect* base asm("r1");
    register const struct Rect* res asm("r0");
    base = zr;
    asm volatile("" : "+r"(base));
    idx = *((u8*)z + 0x147) * 8;
    asm volatile("add %0, %1, %2" : "=l"(res) : "l"(idx), "l"(base));
    rp = res;
  }
  w0 = ((const s32*)rp)[0];
  w1 = ((const s32*)rp)[1];
  v = *(s32*)((u8*)p + 0xc0) - 0x60;
  *(s32*)((u8*)p + 0xc0) = v;
  if (v <= 0xC00) {
    *(s32*)((u8*)p + 0xc0) = 0xC00;
    SET_ELF_ROUTINE(p, 2);
  }
  if (((struct CyberElf7*)p)->unk_b8[2] == 0) {
    asm volatile("lsl %0, %1, #16\n\tasr %0, %0, #16" : "=l"(rx) : "l"(w0));
    dx = (z->s).coord.x + rx;
    dy = (z->s).coord.y + (w0 >> 16) - 0x200;
  } else if (((struct CyberElf7*)p)->unk_b8[2] == 1) {
    asm volatile("lsl %0, %1, #16\n\tasr %0, %0, #16" : "=l"(rx) : "l"(w0));
    dx = (z->s).coord.x + rx;
    dy = (z->s).coord.y;
  } else {
    asm volatile("lsl %0, %1, #16\n\tasr %0, %0, #16" : "=l"(rx) : "l"(w0));
    dx = (z->s).coord.x + rx;
    dy = (z->s).coord.y - (w1 >> 16);
  }
  ox = p->coord.x;
  dx -= ox;
  oy = p->coord.y;
  dy -= oy;
  f = *(s32*)((u8*)p + 0xc0);
  k = 0xA0 << 6;
  f = k - f;
  dx = dx * f / k;
  dy = dy * f / k;
  p->coord.x = ox + dx;
  p->coord.y = oy + dy;
}

void FUN_080e3f24(CyberElf* p);
void FUN_080e3f54(CyberElf* p);
void FUN_080e3f70(CyberElf* p);

static const CyberElfFunc sUpdates[3] = {
    FUN_080e3f24,
    FUN_080e3f54,
    FUN_080e3f70,
};  // 0x08371d88

// 0x08371d94
const u8 u8_ARRAY_08371d94[3] = {0, 1, 2};
