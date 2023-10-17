#include "collision.h"
#include "entity.h"
#include "global.h"
#include "solid.h"

// レジスタンスベースのモブキャラ

typedef TextID (*TalkFunc)(struct Solid*);

static const SolidFunc sUpdates[5];

static void MobNPC_Init(struct Solid* p);
static void MobNPC_Update(struct Solid* p);
static void MobNPC_Die(struct Solid* p);

// clang-format off
const SolidRoutine gMobNPCRoutine = {
    [ENTITY_INIT] =      MobNPC_Init,
    [ENTITY_UPDATE] =    MobNPC_Update,
    [ENTITY_DIE] =       MobNPC_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED static void MobNPC_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080D94A4\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080D94A0 @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080D9528\n\
	.align 2, 0\n\
_080D94A0: .4byte gSolidFnTable\n\
_080D94A4:\n\
	ldr r1, _080D94D8 @ =gSolidFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r2, #0\n\
	orrs r1, r0\n\
	movs r0, #2\n\
	orrs r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r4, #0xa]\n\
	ldrb r3, [r4, #0x11]\n\
	cmp r3, #0\n\
	beq _080D94DC\n\
	movs r0, #0x10\n\
	orrs r1, r0\n\
	b _080D94E0\n\
	.align 2, 0\n\
_080D94D8: .4byte gSolidFnTable\n\
_080D94DC:\n\
	movs r0, #0xef\n\
	ands r1, r0\n\
_080D94E0:\n\
	strb r1, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r3\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x1c\n\
	strb r0, [r1]\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_08009f6c\n\
	str r0, [r4, #0x58]\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r4, #0x54]\n\
	str r0, [r1]\n\
	ldr r1, _080D9530 @ =sMobNPCInitializers\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
_080D9528:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D9530: .4byte sMobNPCInitializers\n\
 .syntax divided\n");
}

static void mob_neutral_080d95a8(struct Solid* p);
static void FUN_080d95f8(struct Solid* p);
static void FUN_080d9734(struct Solid* p);
void mob_chat_080d97b4(struct Solid* p);
void FUN_080d98e8(struct Solid* p);

static void MobNPC_Update(struct Solid* p) {
  // clang-format off
  static const SolidFunc sUpdates[5] = {
      mob_neutral_080d95a8,
      FUN_080d95f8,
      FUN_080d9734,
      mob_chat_080d97b4,
      FUN_080d98e8,
  };
  // clang-format on

  if (((p->s).mode[1] < ENTITY_DISAPPEAR) && ((p->body).status & BODY_STATUS_CHAT) && gInChat && (gCollisionManager.talkTo == &p->body)) {
    (p->s).mode[1] = ENTITY_DISAPPEAR;
    (p->s).mode[2] = 0;
  }
  (sUpdates[(p->s).mode[1]])(p);
}

static void MobNPC_Die(struct Solid* p) { SET_SOLID_ROUTINE(p, ENTITY_DISAPPEAR); }

static void mob_neutral_080d95a8(struct Solid* p) {
  if ((p->s).mode[2] == 0) {
    SetMotion(&p->s, (p->props).mob.motion);
    (p->s).work[2] = 64;
    (p->s).mode[2]++;
  }
  UpdateMotionGraphic(&p->s);
  if (((p->props).mob.unk_08 != 0) && (--(p->s).work[2] == 0xff)) {
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

NAKED static void FUN_080d95f8(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0\n\
	bne _080D9656\n\
	adds r0, r4, #0\n\
	adds r0, #0xc0\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D9622\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	b _080D962C\n\
_080D9622:\n\
	adds r1, r4, #0\n\
	adds r1, #0xbc\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	rsbs r0, r0, #0\n\
_080D962C:\n\
	str r0, [r4, #0x5c]\n\
	movs r0, #0\n\
	ldrsh r2, [r1, r0]\n\
	asrs r2, r2, #2\n\
	ldr r3, _080D96A0 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _080D96A4 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080D96A8 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0x3f\n\
	ands r0, r1\n\
	adds r2, r2, r0\n\
	strb r2, [r4, #0x12]\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080D9656:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	beq _080D96AC\n\
	ldr r0, [r4, #0x54]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080D9694\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, [r1]\n\
	adds r1, r1, r0\n\
	ldr r2, [r4, #0x54]\n\
	cmp r2, r1\n\
	ble _080D96E0\n\
_080D9694:\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
	b _080D972C\n\
	.align 2, 0\n\
_080D96A0: .4byte RNG_0202f388\n\
_080D96A4: .4byte 0x000343FD\n\
_080D96A8: .4byte 0x00269EC3\n\
_080D96AC:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, _080D96DC @ =0xFFFFF600\n\
	adds r0, r0, r1\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080D96D4\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	adds r0, r4, #0\n\
	adds r0, #0xb8\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, [r1]\n\
	subs r1, r1, r0\n\
	ldr r2, [r4, #0x54]\n\
	cmp r2, r1\n\
	bge _080D96E0\n\
_080D96D4:\n\
	movs r0, #2\n\
	strb r0, [r4, #0xd]\n\
	strb r5, [r4, #0xe]\n\
	b _080D972C\n\
	.align 2, 0\n\
_080D96DC: .4byte 0xFFFFF600\n\
_080D96E0:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080D9726\n\
	ldr r2, _080D9710 @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _080D9714 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080D9718 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080D971C\n\
	movs r0, #0\n\
	b _080D971E\n\
	.align 2, 0\n\
_080D9710: .4byte RNG_0202f388\n\
_080D9714: .4byte 0x000343FD\n\
_080D9718: .4byte 0x00269EC3\n\
_080D971C:\n\
	movs r0, #2\n\
_080D971E:\n\
	strb r0, [r4, #0xd]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xe]\n\
	b _080D972C\n\
_080D9726:\n\
	ldr r0, [r4, #0x5c]\n\
	adds r0, r2, r0\n\
	str r0, [r4, #0x54]\n\
_080D972C:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void FUN_080d9734(struct Solid* p) {
  if ((p->s).mode[2] == 0) {
    SetMotion(&p->s, (p->props).mob.motion);
    (p->s).work[2] = 64;
    (p->s).mode[2]++;
  }

  UpdateMotionGraphic(&p->s);

  (p->s).work[2]--;
  if ((p->s).work[2] == 0xFF) {
    bool8 xflip = (((p->s).flags >> 4) & 1) == 0;  // Toggle
    if (xflip) {
      (p->s).flags |= X_FLIP;
    } else {
      (p->s).flags &= ~X_FLIP;
    }
    (p->s).spr.xflip = xflip & 1;
    (p->s).spr.oam.xflip = xflip;
    (p->s).d.x = -(p->s).d.x;
    (p->s).mode[1] = 1;
    (p->s).mode[2] = 0;
  }
}

INCASM("asm/solid/mob_npc.inc");

void andrew_080d9cd8(struct Solid* p);
void alouette_080d9eb8(struct Solid* p);
void FUN_080da01c(struct Solid* p);
void FUN_080da114(struct Solid* p);
void FUN_080da21c(struct Solid* p);
void FUN_080da320(struct Solid* p);
void FUN_080da41c(struct Solid* p);
void FUN_080da500(struct Solid* p);
void FUN_080da5e8(struct Solid* p);
void FUN_080da6f0(struct Solid* p);
void extraNPC_080da7d8(struct Solid* p);
void FUN_080dab40(struct Solid* p);
void FUN_080dac28(struct Solid* p);
void FUN_080dadfc(struct Solid* p);

// clang-format off
const SolidFunc sMobNPCInitializers[27] = {
    [MOB_ANDREW] =      andrew_080d9cd8,
    [MOB_ALOUETTE] =    alouette_080d9eb8,
    [MOB_HIBOU] =       FUN_080da01c,
    [MOB_MENART] =      FUN_080da114,
    [MOB_ROCINOLLE] =   FUN_080da21c,
    [MOB_HIRONDELLE] =  FUN_080da320,
    [MOB_PIC] =         FUN_080da41c,
    [MOB_07] =          FUN_080da500,
    [MOB_08] =          FUN_080da5e8,
    [MOB_09] =          FUN_080da6f0,
    [MOB_10] =          extraNPC_080da7d8,
    [MOB_11] =          extraNPC_080da7d8,
    [MOB_12] =          extraNPC_080da7d8,
    [MOB_13] =          extraNPC_080da7d8,
    [MOB_14] =          extraNPC_080da7d8,
    [MOB_15] =          extraNPC_080da7d8,
    [MOB_16] =          extraNPC_080da7d8,
    [MOB_17] =          extraNPC_080da7d8,
    [MOB_18] =          extraNPC_080da7d8,
    [MOB_19] =          extraNPC_080da7d8,
    [MOB_20] =          extraNPC_080da7d8,
    [MOB_21] =          FUN_080dab40,
    [MOB_22] =          FUN_080dac28,
    [MOB_23] =          FUN_080dac28,
    [MOB_24] =          FUN_080dac28,
    [MOB_25] =          FUN_080dac28,
    [MOB_26] =          FUN_080dadfc,
};
// clang-format on

// --------------------------------------------

TextID andrew_080d9d8c(struct Solid* p);
TextID alouette_080d9f88(struct Solid* p);
TextID hibou_080da098(struct Solid* p);
TextID menart_080da18c(struct Solid* p);
TextID rocinolle_080da294(struct Solid* p);
TextID hirondelle_080da398(struct Solid* p);
TextID pic_080da494(struct Solid* p);
TextID perroquiet_080da57c(struct Solid* p);
TextID doigt_080da660(struct Solid* p);
TextID autruche_080da768(struct Solid* p);
TextID faucon_080da93c(struct Solid* p);
TextID kiss_080dac04(struct Solid* p);
TextID colbor_080dad10(struct Solid* p);
TextID getCielComputerResearchTextID(struct Solid* p);

// clang-format off
const TalkFunc sMobNPCTalks[27] = {
    [MOB_ANDREW] =      andrew_080d9d8c,
    [MOB_ALOUETTE] =    alouette_080d9f88,
    [MOB_HIBOU] =       hibou_080da098,
    [MOB_MENART] =      menart_080da18c,
    [MOB_ROCINOLLE] =   rocinolle_080da294,
    [MOB_HIRONDELLE] =  hirondelle_080da398,
    [MOB_PIC] =         pic_080da494,
    [MOB_07] =          perroquiet_080da57c,
    [MOB_08] =          doigt_080da660,
    [MOB_09] =          autruche_080da768,
    [MOB_10] =          faucon_080da93c,
    [MOB_11] =          faucon_080da93c,
    [MOB_12] =          faucon_080da93c,
    [MOB_13] =          faucon_080da93c,
    [MOB_14] =          faucon_080da93c,
    [MOB_15] =          faucon_080da93c,
    [MOB_16] =          faucon_080da93c,
    [MOB_17] =          faucon_080da93c,
    [MOB_18] =          faucon_080da93c,
    [MOB_19] =          faucon_080da93c,
    [MOB_20] =          faucon_080da93c,
    [MOB_21] =          kiss_080dac04,
    [MOB_22] =          colbor_080dad10,
    [MOB_23] =          colbor_080dad10,
    [MOB_24] =          colbor_080dad10,
    [MOB_25] =          colbor_080dad10,
    [MOB_26] =          getCielComputerResearchTextID,
};
// clang-format on

// clang-format off
const motion_t sMobNPCMotions[27] = {
    MOTION(0xC4, 0x00),
    MOTION(0xBB, 0x00),
    MOTION(0xC3, 0x00),
    MOTION(0xC5, 0x00),
    MOTION(0xC0, 0x00),
    MOTION(0xBE, 0x00),
    MOTION(0xC7, 0x00),
    MOTION(0xC6, 0x00),
    MOTION(0xC1, 0x00),
    MOTION(0xBF, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBD, 0x00),
    MOTION(0xBC, 0x00),
    MOTION(0x82, 0x00),
    MOTION(0x82, 0x00),
    MOTION(0x82, 0x00),
    MOTION(0x82, 0x00),
    MOTION(0xC4, 0x00),
};
// clang-format on

const struct Collision sMobNPCCollisions[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CHATABLE,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(72), PIXEL(1)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CHATABLE,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {-PIXEL(16), PIXEL(0), PIXEL(32), PIXEL(1)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CHATABLE,
      damage : 255,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0x00,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(1)},
    },
};
