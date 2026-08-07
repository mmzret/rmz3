#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "solid.h"
#include "stagerun.h"

// Gray horizontal door

static const struct Collision sCollisions[2];

static void Solid22_Init(struct Solid* p);
static void Solid22_Update(struct Solid* p);
static void Solid22_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DGrayHRoutine = {
    [ENTITY_INIT] =      Solid22_Init,
    [ENTITY_UPDATE] =    Solid22_Update,
    [ENTITY_DIE] =       Solid22_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void Solid22_Init(struct Solid* p) {
  LOAD_STATIC_GRAPHIC(SM120_DOOR_2D_GRAY_H);
  (p->s).coord.x -= PIXEL(7);
  (p->s).coord.y += PIXEL(9);
  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0;
  (p->s).mode[2] = 0;
  Solid22_Update(p);
}

// --------------------------------------------

void FUN_080d7eb8(struct Solid* p);
void openStageDoor_080d7f0c(struct Solid* p);
void FUN_080d8088(struct Solid* p);
void FUN_080d820c(struct Solid* p);

static void Solid22_Update(struct Solid* p) {
  static SolidFunc const sUpdates[] = {
      FUN_080d7eb8,
      openStageDoor_080d7f0c,
      FUN_080d8088,
      FUN_080d820c,
  };
  (sUpdates[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid22_Die(struct Solid* p) {
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED void FUN_080d7e5c(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r3, [r0, #0x2c]\n\
	ldr r0, [r0, #0xc]\n\
	ldr r4, [r0, #0x2c]\n\
	movs r2, #8\n\
	ldrsb r2, [r4, r2]\n\
	cmp r2, #0\n\
	bne _080D7EAA\n\
	ldr r1, [r3, #0x58]\n\
	ldr r0, [r4, #0x58]\n\
	cmp r1, r0\n\
	ble _080D7E84\n\
	ldrb r1, [r3, #0x10]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080D7EAA\n\
	strb r5, [r3, #0xd]\n\
	b _080D7E92\n\
_080D7E84:\n\
	ldrb r1, [r3, #0x10]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D7EAA\n\
	movs r0, #2\n\
	strb r0, [r3, #0xd]\n\
_080D7E92:\n\
	strb r2, [r3, #0xe]\n\
	ldr r0, _080D7EB0 @ =0x00000119\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080D7EB4 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	str r4, [r0]\n\
_080D7EAA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D7EB0: .4byte 0x00000119\n\
_080D7EB4: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

void FUN_080d7eb8(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0x78, 0x00));
      INIT_BODY(p, sCollisions, 0, FUN_080d7e5c);
      (p->s).mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim(&p->s);
      break;
  }
}

void openStageDoor_080d7f0c(struct Solid* p) {
  register s32 w asm("r0");
  switch ((p->s).mode[2]) {
    case 0: {
      register s32* q asm("r1");
      {
        u8* a = (u8*)p + 0x8c;
        s32 z = 0;
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      (p->s).flags &= 0xFB;
      (p->s).flags2 &= 0xF7;
      SetMotion(&p->s, 0x7802);
      q = (s32*)((u8*)p + 0xbc);
      {
        register s32 k asm("r2");
        k = 0x80 << 6;
        *q = (p->s).coord.x + k;
      }
      {
        register struct Entity* e asm("r0");
        register s32 k2 asm("r3");
        register s32 yy asm("r0");
        e = *(struct Entity**)((u8*)p + 0xb4);
        yy = (e->coord).y;
        k2 = 0x80 << 7;
        asm volatile("add %0, %0, %1" : "+l"(yy) : "l"(k2));
        q[1] = yy;
      }
      {
        register u8* cm asm("r2");
        register s32 g asm("r0");
        register s32 h asm("r1");
        cm = (u8*)&gCollisionManager;
        h = cm[1];
        g = 2;
        g |= h;
        cm[1] = g;
      }
      w = 0x40;
      goto setw;
    }
    case 1:
      {
        register u8* cm2 asm("r1");
        cm2 = (u8*)&gCollisionManager;
        cm2[1] = 0;
      }
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 2:
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] == 0x1c) {
        PlaySound(0x9c);
      }
      w = (p->s).work[2] - 1;
      (p->s).work[2] = w;
      if ((w << 24) != 0) {
        break;
      }
      w = 0x40;
      goto setw;
    case 3: {
      register struct Entity* e2 asm("r1");
      register s32* q2 asm("r1");
      register s32 dd asm("r6");
      register s32 k3 asm("r3");
      register s32 zx asm("r2");
      register struct Entity* e3 asm("r5");
      UpdateEntityAnim(&p->s);
      {
        register struct Entity** slot asm("r2");
        slot = (struct Entity**)((u8*)p + 0xb4);
        e2 = *slot;
        {
          register s32 yv asm("r0");
          yv = (e2->coord).y;
          k3 = 0x80 << 1;
          yv += k3;
          (e2->coord).y = yv;
        }
        q2 = (s32*)((u8*)p + 0xbc);
        e3 = *slot;
      }
      {
        register s32 tx asm("r0");
        tx = *q2;
        zx = (e3->coord).x;
        dd = tx - zx;
        if (dd > k3) {
          tx = zx + k3;
        } else {
          register s32 lo asm("r0");
          lo = 0xFFFFFF00;
          if (dd >= lo) {
            goto chk;
          }
          tx = zx + lo;
        }
        (e3->coord).x = tx;
      }
    chk:
      {
        register s32 wv asm("r2");
        wv = (p->s).work[2];
        if (wv == 0x20) {
          {
            register u8* cam asm("r0");
            cam = (u8*)&gStageRun.vm.camera;
            asm("" : "+r"(cam));
            *(struct Entity**)(cam + 0x48) = e2;
          }
        }
        w = wv - 1;
        (p->s).work[2] = w;
      }
      if ((w << 24) != 0) {
        break;
      }
      PlaySound(0x9d);
      SetMotion(&p->s, 0x7803);
      w = 0x20;
    setw:
      (p->s).work[2] = w;
      (p->s).mode[2]++;
      break;
    }
    case 4: {
      UpdateEntityAnim(&p->s);
      w = (p->s).work[2] - 1;
      (p->s).work[2] = w;
      if ((w << 24) != 0) {
        break;
      }
      {
        register struct StageRun* sr asm("r1");
        register s32 z2 asm("r2");
        register struct Entity* e4 asm("r3");
        sr = &gStageRun;
        {
          register u16 ms asm("r2");
          register s32 mk asm("r0");
          ms = *(u16*)((u8*)sr + 0x14);
          mk = 0x0000FFFE;
          mk &= ms;
          z2 = 0;
          *(u16*)((u8*)sr + 0x14) = mk;
        }
        {
          register u8* sp2 asm("r1");
          sp2 = (u8*)sr;
          sp2 += 0xe8;
          e4 = *(struct Entity**)((u8*)p + 0xb4);
          *(struct Coord**)(sp2 + 0x48) = &e4->coord;
        }
        {
          register s32 off asm("r1");
          register u8* tp asm("r0");
          off = 0x119;
          tp = (u8*)e4 + off;
          *tp = z2;
        }
        (p->s).mode[1] = 3;
        (p->s).mode[2] = z2;
      }
      break;
    }
  }
}

void FUN_080d8088(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      {
        u8* w = (u8*)p + 0x8c;
        s32 z = 0;
        *(u32*)w = z;
        asm("" : "+r"(w));
        w += 4;
        *(u32*)w = z;
        asm("" : "+r"(w));
        w += 4;
        asm("" : "+r"(w));
        *w = z;
      }
      (p->s).flags &= 0xFB;
      (p->s).flags2 &= 0xF7;
      SetMotion(&p->s, 0x7802);
      {
        s32* tp = (s32*)((u8*)p + 0xbc);
        tp[0] = (p->s).coord.x + 0x2000;
        tp[1] = (*(struct Entity**)((u8*)p + 0xb4))->coord.y + -0x4000;
      }
      {
        u32 v = gCollisionManager.sweep;
        u32 t = 2;
        t |= v;
        gCollisionManager.sweep = t;
      }
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      break;
    }
    case 1:
      gCollisionManager.sweep = 0;
      (p->s).mode[2]++;
      // fallthrough
    case 2:
      UpdateEntityAnim(&p->s);
      if ((p->s).work[2] == 0x1C) {
        PlaySound(0x9C);
      }
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      break;
    case 3: {
      struct Entity** pb;
      register s32* tp asm("r1");
      register s32 k1 asm("r6");
      UpdateEntityAnim(&p->s);
      pb = (struct Entity**)((u8*)p + 0xb4);
      {
        struct Entity* z1 = *pb;
        s32 cy = z1->coord.y;
        k1 = -0x100;
        z1->coord.y = cy + k1;
        asm("" : "+r"(pb));
      }
      tp = (s32*)((u8*)p + 0xbc);
      {
        struct Entity* z2 = *pb;
        s32 tx = tp[0];
        s32 zx = z2->coord.x;
        s32 d = tx - zx;
        {
          s32 nx2;
          if (d > 0x100) {
            nx2 = zx + 0x100;
            goto st;
          }
          if (d < k1) {
            register s32 k2 asm("r5");
            k2 = -0x100;
            asm volatile("" : "+r"(k2));
            nx2 = zx + k2;
          st:
            z2->coord.x = nx2;
          }
        }
      }
      {
        u32 w2 = (p->s).work[2];
        if (w2 == 0x20) {
          u8* cam = (u8*)&gStageRun + 0xE8;
          *(s32**)(cam + 0x48) = tp;
        }
        {
          s32 t = w2 - 1;
          (p->s).work[2] = t;
          if ((t << 24) != 0) {
            break;
          }
        }
      }
      PlaySound(0x9D);
      SetMotion(&p->s, 0x7803);
      (p->s).work[2] = 0x20;
      (p->s).mode[2]++;
      break;
    }
    case 4: {
      s32 z2;
      UpdateEntityAnim(&p->s);
      {
        s32 t = (p->s).work[2] - 1;
        s32 t8;
        (p->s).work[2] = t;
        t8 = t << 24;
        if (t8 != 0) {
          break;
        }
        asm volatile("" : "+r"(t8));
      }
      {
        u8* g = (u8*)&gStageRun;
        struct Entity* z3;
        u32 v = *(u16*)(g + 0x14);
        u32 t = 0xFFFE;
        t &= v;
        z2 = 0;
        asm volatile("" : "+r"(z2));
        *(u16*)(g + 0x14) = t;
        {
          u8* cam = g + 0xE8;
          z3 = *(struct Entity**)((u8*)p + 0xb4);
          *(s32**)(cam + 0x48) = (s32*)&z3->coord;
        }
        *((u8*)z3 + 0x119) = z2;
      }
      (p->s).mode[1] = 3;
      (p->s).mode[2] = z2;
      break;
    }
  }
}

void FUN_080d820c(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      /* fallthrough */
    case 1:
      UpdateEntityAnim(&p->s);
      if ((p->s).motion.state == 3) {
        SetMotion(&p->s, MOTION(0x78, 0x00));
        (p->s).mode[2]++;
      }
      break;
    case 2:
      UpdateEntityAnim(&p->s);
      break;
  }
}

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      nature : BODY_NATURE_B7,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(32), PIXEL(1), PIXEL(36), PIXEL(36)},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 0xFF,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(0), PIXEL(0)},
    },
};
