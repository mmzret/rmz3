#include "collision.h"
#include "global.h"
#include "weapon.h"
#include "camera.h"
#include "vfx.h"
#include "stagerun.h"

// 0x083615e0
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      atkType : 7,
      element : ELEMENT_ICE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000010,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
};

// --------------------------------------------

void BlizzardArrow_Init(Weapon* p);
void BlizzardArrow_Update(Weapon* p);
void BlizzardArrow_Die(Weapon* p);

// clang-format off
const WeaponRoutine gBlizzardArrowRoutine = {
    [ENTITY_INIT] =      (void*)BlizzardArrow_Init,
    [ENTITY_UPDATE] =    (void*)BlizzardArrow_Update,
    [ENTITY_DIE] =       (void*)BlizzardArrow_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

// --------------------------------------------

void MenuExit_BlizzardArrow(Weapon* p) {
  Player* z = (Player*)p->unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_ICE) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (z->unk_136 & (1 << WEAPON_BUSTER)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

INCASM("asm/weapon/blizzard_arrow_a.inc");

void BlizzardArrow_Update(Weapon* p) {
  if (p->work[3] != 0) {
    goto die;
  }
  switch (p->mode[1]) {
    case 0:
      UpdateEntityAnim((struct Entity*)p);
      {
        s32 vy = p->d.y + p->unk_coord.y;
        p->d.y = vy;
        p->coord.y += vy;
      }
      if (p->motion.cmdIdx > 1) {
        p->d.x = 0;
        p->unk_coord.x = 0x80;
        goto inc;
      }
      break;
    case 1: {
      metatile_attr_t attr;
      UpdateEntityAnim((struct Entity*)p);
      if (p->flags & X_FLIP) {
        s32 dx = p->d.x;
        if (dx <= 0x6FF) {
          p->d.x = dx + p->unk_coord.x;
        }
      } else {
        s32 dx = p->d.x;
        if (dx > -0x700) {
          p->d.x = dx - p->unk_coord.x;
        }
      }
      p->coord.x += p->d.x;
      attr = FUN_080098a4(p->coord.x, p->coord.y);
      if (attr != 0) {
        if (attr & 0x8000) {
          attr = 0;
        }
        if (attr & 0xF) {
          goto inc;
        }
      }
      if (p->body.status & BODY_STATUS_BLOCKED) {
        CreateParticle(&p->coord, 6, (p->flags >> 4) & 1);
        PlaySound(0x2B);
      inc:
        p->mode[1]++;
        break;
      }
      if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > (0xA0 << 6)) {
      die:
        SET_WEAPON_ROUTINE(p, ENTITY_DIE);
        BlizzardArrow_Die((Weapon*)p);
      }
      break;
    }
    case 2: {
      if (RANDOM(RNG_0202f388) & 1) {
        SetSpriteAnimation(p, MOTION(0x52, 0x03));
      } else {
        SetSpriteAnimation(p, MOTION(0x52, 0x04));
      }
      p->body.status = 0;
      p->body.prevStatus = 0;
      p->body.invincibleTime = 0;
      p->flags &= ~COLLIDABLE;
      ((Coords32*)p->buffer)[0] = p->coord;
      ((Coords32*)p->buffer)[1] = p->coord;
      if (p->flags & X_FLIP) {
        p->d.x = -((s32)(RANDOM(RNG_0202f388) & 0x1FF) + 0x80);
        p->unk_coord.x = -((s32)(RANDOM(RNG_0202f388) & 0x1FF) + 0x80);
      } else {
        p->d.x = (RANDOM(RNG_0202f388) & 0x1FF) + 0x80;
        p->unk_coord.x = (RANDOM(RNG_0202f388) & 0x1FF) + 0x80;
      }
      p->d.y = -(s32)(((RANDOM(RNG_0202f388) & 0xF) + 8) << 6);
      p->unk_coord.y = -(s32)(((RANDOM(RNG_0202f388) & 0xF) + 8) << 6);
      SET_XFLIP(p, RANDOM(RNG_0202f388) & 1);
      SET_YFLIP(p, RANDOM(RNG_0202f388) & 1);
      p->work[2] = 0x40;
      p->mode[1]++;
    }
      /* fallthrough */
    case 3: {
      u32 t;
      struct Coord* q;
      UpdateEntityAnim((struct Entity*)p);
      q = (Coords32*)p->buffer;
      q[0].x += p->d.x;
      q[0].y += p->d.y;
      q[1].x += p->unk_coord.x;
      q[1].y += p->unk_coord.y;
      p->d.y += 0x40;
      p->unk_coord.y += 0x40;
      t = p->work[2] - 1;
      p->work[2] = t;
      if ((t << 24) != 0) {
        if (t & 1) {
          p->coord = q[0];
        } else {
          p->coord = ((Coords32*)p->buffer)[1];
        }
        break;
      }
      SET_WEAPON_ROUTINE(p, ENTITY_DIE);
      BlizzardArrow_Die((Weapon*)p);
      asm volatile("@d3");
      break;
    }
  }
}

INCASM("asm/weapon/blizzard_arrow_b.inc");

// --------------------------------------------

// 0x08361624
static const s32 sBlizzardArrowYOffsets[3] = {PIXEL(0), -PIXEL(4), PIXEL(4)};
