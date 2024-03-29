#include "collision.h"

#include "global.h"
#include "story.h"

static void TrySweepBodies(void);
static void checkOverlap1(struct Hitbox *ah, struct Hitbox *dh);
static void checkOverlap2(struct Hitbox *ah, struct Hitbox *dh);
static void tryOverlapCallback1(struct Hitbox *ah, struct Hitbox *dh);
static void tryOverlapCallback2(struct Hitbox *ah, struct Hitbox *dh);

// atkにかけられる値(肉質,弱点属性)
static const s32 sDamageScale[9][4] = {
    {9, 9, 9, 9}, {4, 4, 4, 4}, {4, 3, 2, 6}, {4, 6, 3, 2}, {4, 2, 6, 3}, {2, 2, 2, 2}, {2, 1, 9, 3}, {2, 3, 1, 9}, {2, 9, 3, 1},
};

// 0x08007074
static void unused_Clear24Bytes(u32 *p) {
  p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = 0;
  return;
}

void ResetCollisionManager(void) {
  gCollisionManager.disabled = 0;
  gCollisionManager.sweep = 0;
  gCollisionManager.hitstop = 0;
  ClearAllHitboxes();
}

// 030038e4 から 36バイト を0クリア
void ClearAllHitboxes(void) {
  void *dest;
  gCollisionManager.length = 0;

  dest = &gCollisionManager.list[0][0];
  CpuFastFill(0, dest, 32);
  CpuFill32(0, &gCollisionManager.list[2][2], 4);
}

// 0x080070E0
void CheckCollision(void) {
  TrySweepBodies();
  if (gCollisionManager.hitstop != 0) {
    gCollisionManager.hitstop--;
    return;
  }

  gCollisionManager.talkTo = NULL;
  gCollisionManager.door = NULL;
  gCollisionManager.teleportal = NULL;
  checkOverlap1(gCollisionManager.list[DDP][FACTION_ALLY], gCollisionManager.list[DRP2][FACTION_ENEMY]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_ALLY], gCollisionManager.list[DRP2][FACTION_NEUTRAL]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_ENEMY], gCollisionManager.list[DRP2][FACTION_ALLY]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_ENEMY], gCollisionManager.list[DRP2][FACTION_NEUTRAL]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP2][FACTION_ENEMY]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP2][FACTION_ALLY]);
  checkOverlap1(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP2][FACTION_NEUTRAL]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_ALLY], gCollisionManager.list[DRP][FACTION_ENEMY]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_ALLY], gCollisionManager.list[DRP][FACTION_NEUTRAL]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_ENEMY], gCollisionManager.list[DRP][FACTION_ALLY]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_ENEMY], gCollisionManager.list[DRP][FACTION_NEUTRAL]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP][FACTION_ENEMY]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP][FACTION_ALLY]);
  checkOverlap2(gCollisionManager.list[DDP][FACTION_NEUTRAL], gCollisionManager.list[DRP][FACTION_NEUTRAL]);
}

void InitBody(struct Body *p, const struct Collision *collisions, struct Coord *coord, s16 hp) {
  p->status = 0;
  p->prevStatus = 0;
  p->invincibleTime = 0;
  p->coord = coord;
  p->hp = hp;
  p->fn = NULL;
  p->unk_28 = 0;
  p->parent = NULL;
  *(u32 *)&p->invincibleTime = 0;

  SetDDP(p, collisions);
}

void SetDDP(struct Body *p, const struct Collision *collisions) {
  p->collisions = collisions;
  p->hardness = 0;
  p->forceFlags = 0;
}

void InitWeaponBody(struct Body *o, const struct Collision *hitbox, s16 atk, s16 elementID, s16 nature, s16 comboLv) {
  u32 forceFlags;

  o->collisions = hitbox;
  o->atk = atk;
  o->element = (u8)elementID;
  o->nature = (u8)nature;
  o->comboLv = (u8)comboLv;
  o->hardness = 0;

  forceFlags = (atk >= 0);  // FORCE_DAMAGE
  if (elementID >= 0) forceFlags |= FORCE_ELEMENT;
  if (nature >= 0) forceFlags |= FORCE_NATURE;
  if (comboLv >= 0) forceFlags |= FORCE_COMBO_LEVEL;
  o->forceFlags = (u8)forceFlags;
}

#if MODERN == 0
static void SetDDP_Unused(struct Body *o, const struct Collision *hitbox, u8 r2) {
  o->collisions = hitbox;
  o->hardness = r2;
  o->forceFlags = 0;
}
#endif

// 毎フレーム呼び出されて、gCollisionManager に body が持つ Collisionのリンクリストを1つずつ登録していく
WIP void ResisterNonAffineHitbox(struct Body *body) {
#if MODERN
  struct Collision *collisions = (struct Collision *)body->collisions;
  struct Coord *c = body->coord;
  if ((body->invincibleTime & 0x7F) != 0) {
    body->invincibleTime = (body->invincibleTime & 0x80) | ((body->invincibleTime & 0x7F) - 1);
  }
  if (collisions != NULL) {
    if ((collisions[0].damage == 0) && (collisions[0].hitzone == 0)) {
      body->prevStatus = body->status;
      body->status = 0;
    } else {
      u32 i;
      struct Hitbox *h;
      while (gCollisionManager.length < 64) {
        i = gCollisionManager.length;
        h = &gCollisionManager.buf[i];
        gCollisionManager.length = i + 1;

        h->body = body;
        h->collisions = collisions;
        h->c.x = c->x + (collisions[0].range).x;
        h->c.y = c->y + (collisions[0].range).y;
        h->w = (collisions[0].range).w;
        h->h = (collisions[0].range).h;
        h->next = gCollisionManager.list[collisions[0].kind][collisions[0].faction];
        gCollisionManager.list[collisions[0].kind][collisions[0].faction] = h;
        if (collisions[0].remaining == 0) {
          break;
        }
        collisions = &collisions[1];
      }
      body->prevStatus = body->status;
      body->status = 0;
    }
  }
#else
  INCCODE("asm/wip/ResisterBodyHitbox1.inc");
#endif
}

WIP void RegisterFlipableHitbox(struct Body *body, u8 flip) {
#if MODERN
  struct Collision *collisions = (struct Collision *)body->collisions;
  struct Coord *c = body->coord;
  if ((body->invincibleTime & 0x7F) != 0) {
    body->invincibleTime = (body->invincibleTime & 0x80) | ((body->invincibleTime & 0x7F) - 1);
  }

  if (collisions != NULL) {
    if ((collisions[0].damage != 0) || (collisions[0].hitzone != 0)) {
      for (; gCollisionManager.length < 64;) {
        s32 i = gCollisionManager.length++;
        struct Hitbox *h = &gCollisionManager.buf[i];
        h->body = body;
        h->collisions = collisions;
        if (flip & (X_FLIP >> 4)) {
          h->c.x = c->x - (collisions[0].range).x;
        } else {
          h->c.x = c->x + (collisions[0].range).x;
        }
        if (flip & (Y_FLIP >> 4)) {
          h->c.y = c->y - (collisions[0].range).y;
        } else {
          h->c.y = c->y + (collisions[0].range).y;
        }
        h->w = (collisions[0].range).w;
        h->h = (collisions[0].range).h;
        h->next = gCollisionManager.list[collisions[0].kind][collisions[0].faction];
        gCollisionManager.list[collisions[0].kind][collisions[0].faction] = h;
        if (collisions[0].remaining == 0) {
          break;
        }
        collisions = &collisions[1];
      }
    }
    body->prevStatus = body->status;
    body->status = 0;
  }
#else
  INCCODE("asm/wip/ResisterBodyHitbox2.inc");
#endif
}

NAKED void RegisterScalerotHitbox(struct Body *o, u32 r1, u32 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r6, [r7]\n\
	ldr r0, [r7, #8]\n\
	mov ip, r0\n\
	ldr r1, _080074D4 @ =gSineTable\n\
	movs r0, #0xff\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r5, #0\n\
	ldrsh r3, [r0, r5]\n\
	mov sl, r3\n\
	movs r0, #0x3f\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r8, r1\n\
	adds r3, r7, #0\n\
	adds r3, #0x20\n\
	ldrb r2, [r3]\n\
	movs r1, #0x7f\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _080074BA\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	subs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
_080074BA:\n\
	cmp r6, #0\n\
	beq _080075A8\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #0\n\
	bne _080074D8\n\
	ldrb r1, [r6, #8]\n\
	cmp r1, #0\n\
	bne _080074D8\n\
	ldr r0, [r7, #0x18]\n\
	str r0, [r7, #0x1c]\n\
	str r1, [r7, #0x18]\n\
	b _080075A8\n\
	.align 2, 0\n\
_080074D4: .4byte gSineTable\n\
_080074D8:\n\
	ldr r0, _08007540 @ =gCollisionManager\n\
	ldrb r1, [r0, #3]\n\
	cmp r1, #0x3f\n\
	bhi _080075A0\n\
	adds r3, r0, #0\n\
	mov sb, r3\n\
	movs r5, #1\n\
	ands r5, r4\n\
	str r5, [sp]\n\
	movs r0, #2\n\
	ands r0, r4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	str r0, [sp, #4]\n\
_080074F4:\n\
	mov r0, sb\n\
	ldrb r2, [r0, #3]\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #3\n\
	mov r1, sb\n\
	adds r1, #4\n\
	adds r4, r0, r1\n\
	adds r2, #1\n\
	mov r1, sb\n\
	strb r2, [r1, #3]\n\
	str r7, [r4, #8]\n\
	str r6, [r4, #4]\n\
	movs r2, #0x10\n\
	ldrsh r3, [r6, r2]\n\
	mov r1, r8\n\
	muls r1, r3, r1\n\
	asrs r1, r1, #8\n\
	movs r5, #0x12\n\
	ldrsh r2, [r6, r5]\n\
	mov r0, sl\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	adds r5, r1, r0\n\
	mov r1, r8\n\
	muls r1, r2, r1\n\
	asrs r1, r1, #8\n\
	mov r0, sl\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	subs r1, r1, r0\n\
	ldr r0, [sp]\n\
	cmp r0, #0\n\
	beq _08007544\n\
	mov r2, ip\n\
	ldr r0, [r2]\n\
	subs r0, r0, r5\n\
	b _0800754A\n\
	.align 2, 0\n\
_08007540: .4byte gCollisionManager\n\
_08007544:\n\
	mov r3, ip\n\
	ldr r0, [r3]\n\
	adds r0, r0, r5\n\
_0800754A:\n\
	str r0, [r4, #0xc]\n\
	ldr r5, [sp, #4]\n\
	cmp r5, #0\n\
	beq _0800755A\n\
	mov r2, ip\n\
	ldr r0, [r2, #4]\n\
	subs r0, r0, r1\n\
	b _08007560\n\
_0800755A:\n\
	mov r3, ip\n\
	ldr r0, [r3, #4]\n\
	adds r0, r0, r1\n\
_08007560:\n\
	str r0, [r4, #0x10]\n\
	ldrh r0, [r6, #0x14]\n\
	strh r0, [r4, #0x14]\n\
	ldrh r0, [r6, #0x16]\n\
	strh r0, [r4, #0x16]\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r5, [r6, #1]\n\
	adds r0, r0, r5\n\
	lsls r0, r0, #2\n\
	ldr r1, _080075B8 @ =0x030038E4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4]\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r2, [r6, #1]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	ldr r3, _080075B8 @ =0x030038E4\n\
	adds r0, r0, r3\n\
	str r4, [r0]\n\
	ldrb r0, [r6, #0xb]\n\
	cmp r0, #0\n\
	beq _080075A0\n\
	adds r6, #0x18\n\
	ldr r5, _080075BC @ =gCollisionManager\n\
	ldrb r0, [r5, #3]\n\
	cmp r0, #0x3f\n\
	bls _080074F4\n\
_080075A0:\n\
	ldr r0, [r7, #0x18]\n\
	str r0, [r7, #0x1c]\n\
	movs r0, #0\n\
	str r0, [r7, #0x18]\n\
_080075A8:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080075B8: .4byte 0x030038E4\n\
_080075BC: .4byte gCollisionManager\n\
      .syntax divided\n");
}

/*
  与えるダメージ量を計算する
    引数: r0 = 攻撃側, r1 = 食らう側
      例: (r0, r1) = (0x030058F8, 0x02037CD4)
    返り値: 実際のダメージ
*/
WIP u16 CalcDamage(struct Body *a, struct Body *d) {
#if MODERN
  const struct Collision *processing = d->processing;
  const u8 hardness = processing->hardness | d->hardness;

  if (!(gCollisionManager.disabled & 0x80) && (processing->hitzone != 0xFF) && !(hardness & NO_DAMAGE)) {
    const s32 X = sDamageScale[processing->hitzone][a->element];
    if (X != 9) {
      u16 damage = (X * a->atk) / 4;
      if (processing->special == HALFABLE) {
        if (FLAG(gCurStory.s.gameflags, PUTITE_ENABLED) && (a->atk == 254)) {
          damage = 8;
        }
        if (gSystemSavedataManager.mods[2] & (1 << 3)) {
          damage /= 2;
        }
      }
      if (hardness & HARDNESS_WEAK) {
        damage *= 2;
      }
      if (hardness & LITTLE_HARD) {
        damage = (damage << 1) / 3;
      }
      if (damage == 0) {
        damage = 1;
      }
      return damage;
    }
  }
  return 0;
#else
  INCCODE("asm/wip/CalcDamage.inc");
#endif
}

// ドアフラグはここで立ててる
WIP void hitbox_08007674(struct Body *a, struct Body *d) {
#if MODERN
  if (gCollisionManager.disabled & (1 << 7)) {
    return;
  }

  if ((a->collisionLayer & LAYER_MASK(&d->processing)) == 0) {
    return;
  }

  if ((a->processing)->special == CHATABLE) {
    a->status |= BODY_STATUS_CHAT;
    d->status |= BODY_STATUS_CHAT;
    gCollisionManager.talkTo = a;
  }
  if ((a->processing)->special == DOOR_3D) {
    a->status |= BODY_STATUS_DOOR;
    d->status |= BODY_STATUS_DOOR;
    gCollisionManager.door = a;
  }
  if ((a->processing)->special == CS_TELEPORTAL) {
    a->status |= BODY_STATUS_TELEPORTAL;
    d->status |= BODY_STATUS_TELEPORTAL;
    gCollisionManager.teleportal = a;
  }

  if (((gCollisionManager.disabled >> (d->processing)->faction)) & 1) {
    return;
  }

  // Binding
  if (((a->processing)->unk_0a & ((1 << 5) | (1 << 0))) && ((d->processing)->unk_0a & (1 << 2))) {
    if (!(a->status & BODY_STATUS_BINDING) && !(d->status & BODY_STATUS_BINDED)) {
      if (!(a->prevStatus & BODY_STATUS_BINDING) && !(d->prevStatus & BODY_STATUS_BINDED)) {
        a->bindPair = d;
        d->bindPair = a;
        a->unk_21 = d->unk_21 = ((a->processing)->unk_0a & 0xF0) >> 1;
        a->hitboxFlags |= BODY_STATUS_BINDING;
        d->hitboxFlags |= BODY_STATUS_BINDED;
        a->status |= a->hitboxFlags;
        d->status |= d->hitboxFlags;
      } else if ((a->bindPair == d) && (d->bindPair == a)) {
        if ((((a->processing)->unk_0a & (1 << 1)) && (a->unk_21 != 0)) || (a->unk_21 != 0 && d->unk_21 != 0)) {
          a->hitboxFlags |= BODY_STATUS_BINDING;
          d->hitboxFlags |= BODY_STATUS_BINDED;
          a->status |= a->hitboxFlags;
          d->status |= d->hitboxFlags;
        }
      }
    }
  }

  if (d->status & (BODY_STATUS_WHITE | BODY_STATUS_B3)) {
    return;
  }

  if (a->collisionLayer & (d->processing)->priorityLayer) {
    if ((a->processing)->special == HALFABLE) {
      if ((a->processing)->atkType != 0) {
        if (d->prevStatus & (BODY_STATUS_B3 | BODY_STATUS_B4)) {
          if (d->unk_23 == (a->processing)->atkType) {
            if (a->comboLv <= d->invincibleLv) {
              a->enemy = d;
              d->enemy = a;
              d->status |= BODY_STATUS_B4;
              return;
            }
          }
        }
      }
    }
    if ((d->processing)->hitzone != 0xFF) {
      a->enemy = d;
      a->hitboxFlags |= BODY_STATUS_B5;
      if ((d->processing)->hardness & METAL) {
        a->hitboxFlags |= BODY_STATUS_BLOCKED;
      }
    }
    if ((d->invincibleTime != 0) || (a->atk == 0xFF)) {
      a->status |= a->hitboxFlags;
      return;
    }
    d->enemy = a;
    d->hitboxFlags |= BODY_STATUS_B3;
    d->unk_23 = (a->processing)->atkType & 0xF;
    d->elemented = a->element & 0xF;
    d->invincibleLv = a->comboLv;

    if (a->nature & BODY_NATURE_B2) {
      d->hitboxFlags |= BODY_STATUS_BLOCKED;
    }
    if (a->nature & BODY_NATURE_B0) {
      d->hitboxFlags |= BODY_STATUS_B14;
    }
    if (a->nature & ELEMENT_ENCHANTABLE) {
      d->hitboxFlags |= BODY_STATUS_B15;
    }
    if (a->nature & BODY_NATURE_CUT) {
      d->hitboxFlags |= BODY_STATUS_SLASHED;
    }
    if (a->nature & BODY_NATURE_RECOIL) {
      d->hitboxFlags |= BODY_STATUS_RECOILED;
    }
    if (a->nature & BODY_NATURE_ILETHAS) {
      d->hitboxFlags |= BODY_STATUS_B22;
    }

    if ((d->processing)->hitzone != 0xFF) {
      if (((a->processing)->atkType == ATK_SABER) || ((a->processing)->atkType == ATK_ROD)) {
        gCollisionManager.hitstop = 4;
      }
    }
    a->status |= a->hitboxFlags;
    d->status |= d->hitboxFlags;
    return;
  }

  if ((a->processing)->special == HALFABLE) {
    if ((a->processing)->atkType != 0) {
      if (d->prevStatus & (BODY_STATUS_WHITE | BODY_STATUS_B1)) {
        if (d->unk_23 == (a->processing)->atkType) {
          if (a->comboLv <= d->invincibleLv) {
            a->enemy = d;
            d->enemy = a;
            d->status |= BODY_STATUS_B1;
            return;
          }
        }
      }
    }
  }
  if ((d->processing)->hitzone != 0xFF) {
    a->enemy = d;
    a->hitboxFlags |= BODY_STATUS_B2;
    if ((d->processing)->hardness & METAL) {
      a->hitboxFlags |= BODY_STATUS_BLOCKED;
      d->hitboxFlags |= BODY_STATUS_B13;
    }
  }

  if ((d->processing)->special == CS_BOSS) {
    if (d->invincibleTime != 0) {
      if ((a->comboLv <= d->invincibleLv) && ((a->processing)->atkType != 0)) {
        a->hitboxFlags = 0;
        return;
      }
    }
  }

  // 攻撃が通った
  if (d->invincibleTime == 0 || (a->comboLv > d->invincibleLv)) {
    if (a->atk != 0xFF) {
      d->enemy = a;
      d->hitboxFlags |= BODY_STATUS_WHITE;
      d->unk_23 = (a->processing)->atkType;
      d->elemented = a->element;
      d->invincibleLv = a->comboLv;

      if (a->nature & BODY_NATURE_B2) {
        a->hitboxFlags |= BODY_STATUS_B13;
        d->hitboxFlags |= BODY_STATUS_BLOCKED;
      }
      if (a->nature & BODY_NATURE_B0) {
        d->hitboxFlags |= BODY_STATUS_B14;
      }
      if (a->nature & ELEMENT_ENCHANTABLE) {
        d->hitboxFlags |= BODY_STATUS_B15;
      }
      if (a->nature & BODY_NATURE_CUT) {
        d->hitboxFlags |= BODY_STATUS_SLASHED;
      }
      if (a->nature & BODY_NATURE_RECOIL) {
        d->hitboxFlags |= BODY_STATUS_RECOILED;
      }
      if (a->nature & BODY_NATURE_ILETHAS) {
        a->hitboxFlags |= BODY_STATUS_B23;
        d->hitboxFlags |= BODY_STATUS_B22;
      }

      d->hp -= CalcDamage(a, d);
      if (d->hp <= 0) {
        d->hp = 0;
        d->hitboxFlags |= BODY_STATUS_DEAD;
      }
      if ((d->processing)->hitzone != 0xFF) {
        if (((a->processing)->atkType == ATK_SABER) || ((a->processing)->atkType == ATK_ROD)) {
          gCollisionManager.hitstop = 4;
        }
      }
      if (((d->processing)->special == HALFABLE) || ((d->processing)->special == CS_BOSS)) {
        d->invincibleTime = 90;
      }
      a->status |= a->hitboxFlags;
      d->status |= d->hitboxFlags;
      return;
    }
  }

  if (a->nature & BODY_NATURE_B2) {
    a->enemy = d;
    a->hitboxFlags |= BODY_STATUS_B13;
    d->status |= BODY_STATUS_BLOCKED;
  }
  if (a->nature & BODY_NATURE_ILETHAS) {
    a->enemy = d;
    d->status |= BODY_STATUS_B22;
    a->hitboxFlags |= BODY_STATUS_B23;
  }
  a->status |= a->hitboxFlags;
#else
  INCCODE("asm/wip/hitbox_08007674.inc");
#endif
}

static bool8 unused_08007b80(struct Body *a, struct Body *d) {
  const u8 hardness = (d->processing)->hardness | d->hardness;
  if (gCollisionManager.disabled & (1 << 7)) {
    return FALSE;
  }
  if (!(hardness & NO_DAMAGE)) {
    d->hp--;
    d->enemy = a;
    d->status |= BODY_STATUS_WHITE;
    d->unk_23 = (a->processing)->atkType;
    d->elemented = a->element;
    d->invincibleLv = a->comboLv;
    if (d->hp < 1) {
      d->hp = 0;
      d->status |= BODY_STATUS_DEAD;
    }
    switch ((d->processing)->special) {
      case 1: {
        d->invincibleTime = 90;
        break;
      }
      case 2: {
        d->invincibleTime = 90;
        break;
      }
    }
  }
  return TRUE;
}

u16 CalcPutitedSpikeDamage(struct Body *body, u8 damage) {
  const u8 hardness = (body->processing)->hardness | body->hardness;
  if (gCollisionManager.disabled & (1 << 7)) {
    return 0;
  }
  if (body->invincibleTime != 0) {
    return 0;
  }

  if (hardness & HARDNESS_WEAK) {
    damage *= 2;
  }
  if (hardness & LITTLE_HARD) {
    damage = (damage * 2) / 3;
  }
  if (damage == 0) {
    damage = 1;
  }

  if (!(hardness & NO_DAMAGE)) {
    body->hp -= damage;
    if (body->hp < 1) {
      body->hp = 0;
      body->hitboxFlags |= BODY_STATUS_DEAD;
    }

    switch (body->processing->special) {
      case 1: {
        body->invincibleTime = 90;
        break;
      }
      case 2: {
        body->invincibleTime = 90;
        break;
      }
    }
  }
  return damage;
}

/*
    毎フレーム呼び出される
      .sweepフラグが立っていたら、フラグの種類に応じて対象のBodyを全部殺す
 */
static void TrySweepBodies(void) {
  s32 faction;
  for (faction = 0; faction < 3; faction++) {
    if ((gCollisionManager.sweep >> faction) & 1) {
      struct Hitbox *hitbox = gCollisionManager.list[DRP][faction];
      for (; hitbox != NULL; hitbox = hitbox->next) {
        struct Body *body;
        (hitbox->body)->elemented = 0;

        if (hitbox->body->hp != 0) {
          hitbox->body->hp = 0;
          (hitbox->body)->status |= (BODY_STATUS_WHITE | BODY_STATUS_DEAD);
        } else {
          (hitbox->body)->status |= BODY_STATUS_DEAD;
        }
      }
    }
  }
}

/**
 * @brief DDP と DRP2 について、 Hitboxが重なっていたら 0x08007e28 を呼び出す
 * @param ah DDP's hitbox info
 * @param dh DRP2's hitbox info
 * @note 0x08007d38
 */
static void checkOverlap1(struct Hitbox *a, struct Hitbox *drp2) {
  u16 w, h;
  s32 x, y;
  u32 W, H;
  struct Hitbox *d;

  if ((a != NULL) && (drp2 != NULL)) {
    do {
      x = (a->c).x;
      y = (a->c).y;
      w = a->w;
      h = a->h;

      for (d = drp2; d != NULL; d = d->next) {
        if (a->body != d->body) {
          W = w + d->w;
          H = h + d->h;
          if ((x - (d->c).x) + (W >> 1) < W) {
            if ((y - (d->c).y) + (H >> 1) < H) {
              tryOverlapCallback1(a, d);
            }
          }
        }
      }

      a = a->next;
    } while (a != NULL);
  }
}

/**
 * @brief DDP　と DRP について、Hitboxが重なっていたら 0x08008078 を呼び出す
 * @details 呼び出す関数が 0x08008078 に変わった以外は、 0x08007d38 と全く同じ
 * @param ah DDP's hitbox info
 * @param dh DRP's hitbox info
 * @note 0x08007db0
 */
static void checkOverlap2(struct Hitbox *a, struct Hitbox *drp1) {
  u16 w, h;
  s32 x, y;
  u32 W, H;
  struct Hitbox *d;

  if ((a != NULL) && (drp1 != NULL)) {
    do {
      x = (a->c).x;
      y = (a->c).y;
      w = a->w;
      h = a->h;

      for (d = drp1; d != NULL; d = d->next) {
        if (a->body != d->body) {
          W = w + d->w;
          H = h + d->h;
          if ((x - (d->c).x) + (W >> 1) < W) {
            if ((y - (d->c).y) + (H >> 1) < H) {
              tryOverlapCallback2(a, d);
            }
          }
        }
      }

      a = a->next;
    } while (a != NULL);
  }
}

/**
 * @brief apとdpに衝突の結果生まれるフラグをセットして、ap->body->fn と dh->body->fn をそれぞれ呼び出す
 * @param ah DDP's hitbox info
 * @param dh DRP2's hitbox info
 */
WIP static void tryOverlapCallback1(struct Hitbox *ah, struct Hitbox *dh) {
#if MODERN
  struct Body *a = ah->body;
  struct Body *d = dh->body;

  if ((gCollisionManager.disabled & (1 << 7)) || (ah->collisions->special == DOOR_3D)) {
    return;
  }

  if (!(a->forceFlags & FORCE_NATURE)) {
    a->nature = ah->collisions->nature;
  }

  if (a->nature & BODY_NATURE_B7) {
    return;
  }

  a->hitboxFlags = 0;
  d->hitboxFlags = 0;
  a->processing = ah->collisions;
  d->processing = dh->collisions;

  if (!(a->forceFlags & FORCE_NATURE)) {
    a->nature = ah->collisions->nature;
  }

  if ((a->status & BODY_STATUS_B8) == 0) {
    a->unk_32[0] = -0x8000;
    a->unk_32[1] = 0x7FFF;
  }

  if (a->coord->x >= d->coord->x) {
    a->unk_32[0] = (s16)(((dh->c).x + dh->w) - a->coord->x) >> 8;
  } else {
    a->unk_32[1] = (s16)(((dh->c).x - dh->w) - a->coord->x) >> 8;
  }

  if ((a->processing->special == HALFABLE) && (a->processing->atkType != 0) && (d->prevStatus & (BODY_STATUS_B6 | BODY_STATUS_B7))) {
    d->enemy = a;
    d->status |= BODY_STATUS_B7;
  } else {
    if (d->processing->hardness & METAL) {
      d->hitboxFlags |= BODY_STATUS_B13;
    }
    d->enemy = a;
    d->hitboxFlags |= BODY_STATUS_B6;
    if ((a->processing->atkType == ATK_SABER) || (a->processing->atkType == ATK_ROD)) {
      gCollisionManager.hitstop = 4;
    }
    if (d->processing->hardness & METAL) {
      a->hitboxFlags |= BODY_STATUS_BLOCKED;
    }
  }

  a->enemy = d;
  a->hitboxFlags |= (BODY_STATUS_B5 | BODY_STATUS_B8);
  if (a->nature & BODY_NATURE_RECOIL) {
    d->hitboxFlags |= BODY_STATUS_B22;
  }
  a->status |= a->hitboxFlags;
  d->status |= d->hitboxFlags;

  if ((a->fn == NULL) && (d->fn == NULL) && (a->hitboxFlags == 0) && (d->hitboxFlags == 0)) {
    return;
  } else {
    u16 distance;
    struct Coord c1, c2;
    c1.x = (dh->w * ((ah->c).x - (dh->c).x)) / (ah->w + dh->w);
    c1.y = (dh->h * ((ah->c).y - (dh->c).y)) / (ah->h + dh->h);
    distance = Sqrt(POW2((ah->c).x - (dh->c).x) + POW2((ah->c).y - (dh->c).y));
    c2.x = (((ah->c).x - (dh->c).x) << 8) / distance;
    c2.y = (((ah->c).y - (dh->c).y) << 8) / distance;
    if ((a->fn != NULL) && (a->hitboxFlags)) {
      (a->fn)(a, &c1, &c2);
    }
    if ((d->fn != NULL) && (d->hitboxFlags)) {
      c2.x = -c2.x;
      c2.y = -c2.y;
      (d->fn)(d, &c1, &c2);
    }
  }
#else
  INCCODE("asm/wip/tryOverlapCallback1.inc");
#endif
}

/**
 * @brief apとdpに衝突の結果生まれるフラグをセットして、ap->body->fn と dh->body->fn をそれぞれ呼び出す
 * @param ah Attacker's hitbox info
 * @param dh Defender's hitbox info
 */
WIP static void tryOverlapCallback2(struct Hitbox *ah, struct Hitbox *dh) {
#if MODERN
  u8 atkType;
  struct Body *a = ah->body;
  struct Body *d = dh->body;
  if (a->status & BODY_STATUS_B8) {
    if (a->coord->x + PIXEL(a->unk_32[1]) < ((dh->c).x - dh->w)) {
      return;
    }
    if (((dh->c).x + dh->w) < a->coord->x + PIXEL(a->unk_32[0])) {
      return;
    }
  }
  a->hitboxFlags = 0, d->hitboxFlags = 0;

  a->processing = ah->collisions;
  d->processing = dh->collisions;

  if (!(a->forceFlags & FORCE_DAMAGE)) {
    a->atk = ah->collisions->damage;
  }
  if (!(a->forceFlags & FORCE_ELEMENT)) {
    a->element = ah->collisions->element;
  }
  if (!(a->forceFlags & FORCE_NATURE)) {
    a->nature = ah->collisions->nature;
  }
  if (!(a->forceFlags & FORCE_COMBO_LEVEL)) {
    a->comboLv = ah->collisions->comboLv;
  }
  if (!(a->forceFlags & FORCE_LAYER)) {
    a->collisionLayer = ah->collisions->layer;
    goto DONE;
  }

  atkType = (ah->collisions)->atkType;
  if (atkType < 4) {
    if (a->nature & BODY_NATURE_B0) {
      a->collisionLayer = (1 << 31);
    } else if (a->nature & ELEMENT_ENCHANTABLE) {
      a->collisionLayer = (1 << (atkType * 5 + a->element + 1));
    } else {
      a->collisionLayer = (1 << (atkType * 5 + a->element));
    }

  } else if (atkType == ATK_UNK4) {
    a->collisionLayer = (1 << 16);

  } else if (atkType < 8) {
    a->collisionLayer = 1 << (atkType - 3);

  } else if (atkType < 12) {
    if (a->element != 0) {
      a->collisionLayer = 1 << (a->element + 6);
    } else {
      a->collisionLayer = (1 << 6);
    }

  } else if (atkType == ATK_UNK12) {
    a->collisionLayer = (1 << 8);

  } else if (atkType == ATK_SOUL_LAUNCHER) {
    if (a->element == ELEMENT_FLAME) {
      a->collisionLayer = 0x400000;
    } else {
      a->collisionLayer = 0x200000;
    }

  } else if (atkType == 14) {
    if (a->element == ELEMENT_THUNDER) {
      a->collisionLayer = (1 << 17);
    } else {
      a->collisionLayer = (1 << 16);
    }

  } else {
    if (a->element == ELEMENT_ICE) {
      a->collisionLayer = 0x40000;
    } else {
      a->collisionLayer = (1 << 16);
    }
  }

DONE:
  hitbox_08007674(a, d);
  if ((a->fn == NULL) && (d->fn == NULL) && (a->hitboxFlags == 0) && (d->hitboxFlags == 0)) {
    return;
  } else {
    u16 distance;
    struct Coord c1, c2;
    c1.x = (dh->w * ((ah->c).x - (dh->c).x)) / (ah->w + dh->w);
    c1.y = (dh->h * ((ah->c).y - (dh->c).y)) / (ah->h + dh->h);
    distance = Sqrt(POW2((ah->c).x - (dh->c).x) + POW2((ah->c).y - (dh->c).y));
    c2.x = (((ah->c).x - (dh->c).x) << 8) / distance;
    c2.y = (((ah->c).y - (dh->c).y) << 8) / distance;
    if ((a->fn != NULL) && (a->hitboxFlags)) {
      (a->fn)(a, &c1, &c2);
    }
    if ((d->fn != NULL) && (d->hitboxFlags)) {
      c2.x = -c2.x;
      c2.y = -c2.y;
      (d->fn)(d, &c1, &c2);
    }
  }
#else
  INCCODE("asm/wip/tryOverlapCallback2.inc");
#endif
}
