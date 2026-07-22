#include "collision.h"
#include "global.h"
#include "palette_animation.h"
#include "solid.h"
#include "story.h"

static const struct Collision sCollision;
static const struct Rect sSize;
static const Coords32 sLightSwitch_ElfxOffsets;

static void Solid32_Init(struct Solid* p);
static void Solid32_Update(struct Solid* p);
static void Solid32_Die(void* _ UNUSED);
static void Solid32_Disappear(struct Solid* p);

// clang-format off
const SolidRoutine gLightSwitchRoutine = {
    [ENTITY_INIT] =      (void*)Solid32_Init,
    [ENTITY_UPDATE] =    (void*)Solid32_Update,
    [ENTITY_DIE] =       (void*)Solid32_Die,
    [ENTITY_DISAPPEAR] = (void*)Solid32_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Solid32_Init(struct Solid* p) {
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  EnableSpriteAnimation_Normal(p);
  SetSpriteAnimation(p, MOTION(SM223_LIGHT_SWITCH, 0));
  (p->s).flags2 |= ENTI_PHYSICS;
  (p->s).size = &sSize;
  (p->s).physicsAttr = SHAPE_BLOCK;
  (p->s).flags2 &= ~WHITE_PAINTABLE;
  (p->s).invincibleID = (p->s).uniqueID;
  (p->s).coord.y = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  if (gCurStory.s.unk_54 & (1 << (p->s).work[0])) {
    (p->s).mode[3] = 2;
  } else {
    (p->s).mode[3] = 0;
  }
  Solid32_Update(p);
}

NAKED static void Solid32_Update(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldrb r6, [r5, #0xf]\n\
	cmp r6, #1\n\
	beq _080DBF2C\n\
	cmp r6, #1\n\
	bgt _080DBED4\n\
	cmp r6, #0\n\
	beq _080DBEDE\n\
	b _080DBFDE\n\
_080DBED4:\n\
	cmp r6, #2\n\
	beq _080DBF74\n\
	cmp r6, #3\n\
	beq _080DBFBA\n\
	b _080DBFDE\n\
_080DBEDE:\n\
	movs r1, #0xdf\n\
	lsls r1, r1, #8\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080DBF68 @ =sCollision\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	movs r0, #0xbd\n\
	bl RemovePaletteAnimation\n\
	adds r0, r5, #0\n\
	bl _GetEntityPaletteID\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x13\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	movs r0, #0xbe\n\
	bl StartPaletteAnimation\n\
	ldrb r0, [r5, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xf]\n\
_080DBF2C:\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r4, #1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080DBFDE\n\
	movs r0, #0x3c\n\
	bl PlaySound\n\
	ldr r2, _080DBF6C @ =sLightSwitch_ElfxOffsets\n\
	movs r0, #0\n\
	adds r1, r5, #0\n\
	bl ApplyElementEffect\n\
	ldr r2, _080DBF70 @ =gCurStory\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	ldrb r1, [r5, #0x10]\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r5, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xf]\n\
	b _080DBFDE\n\
	.align 2, 0\n\
_080DBF68: .4byte sCollision\n\
_080DBF6C: .4byte sLightSwitch_ElfxOffsets\n\
_080DBF70: .4byte gCurStory\n\
_080DBF74:\n\
	ldr r1, _080DBFF0 @ =0x0000DF01\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r0, #0xbe\n\
	bl RemovePaletteAnimation\n\
	adds r0, r5, #0\n\
	bl _GetEntityPaletteID\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x13\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	orrs r1, r0\n\
	movs r0, #0xbd\n\
	bl StartPaletteAnimation\n\
	ldrb r0, [r5, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xf]\n\
_080DBFBA:\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldr r0, _080DBFF4 @ =gCurStory\n\
	adds r4, r0, #0\n\
	adds r4, #0x54\n\
	ldrb r2, [r4]\n\
	ldrb r3, [r5, #0x10]\n\
	adds r1, r2, #0\n\
	asrs r1, r3\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080DBFDE\n\
	lsls r0, r3\n\
	eors r2, r0\n\
	strb r2, [r4]\n\
	strb r1, [r5, #0xf]\n\
_080DBFDE:\n\
	movs r0, #0xbd\n\
	bl StepPaletteAnimation\n\
	movs r0, #0xbe\n\
	bl StepPaletteAnimation\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080DBFF0: .4byte 0x0000DF01\n\
_080DBFF4: .4byte gCurStory\n\
 .syntax divided\n");
}

static void Solid32_Die(void* _) {}

static void Solid32_Disappear(struct Solid* p) {
  RemovePaletteAnimation(189);
  RemovePaletteAnimation(190);
  DeleteSolid((void*)p);
}

static const struct Collision sCollision = {
  kind : DRP,
  faction : FACTION_ENEMY,
  LAYER(0xFFFFFFFF),
  hitzone : 0xFF,
  remaining : 0,
  priorityLayer : 0xFFFDEF7B,
  range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
};

static const struct Rect sSize = {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)};

static const Coords32 sLightSwitch_ElfxOffsets = {PIXEL(0), -PIXEL(16)};  // 0x083714bc
