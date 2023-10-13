#include "game.h"
#include "global.h"
#include "widget.h"

/*
  ヘッド、ボディ、フットのチップリスト
*/

#define ARMORS_HEAD 0
#define ARMORS_BODY 1
#define ARMORS_FOOT 2

static void ArmorIcons_Init(struct Widget *w);
static void ArmorIcons_Update(struct Widget *w);
static void ArmorIcons_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gArmorIconsRoutine = {
    [ENTITY_INIT] =      ArmorIcons_Init,
    [ENTITY_UPDATE] =    ArmorIcons_Update,
    [ENTITY_DIE] =       ArmorIcons_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *CreateArmorIcons(struct GameState *g, u8 r1, u8 r2) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 5);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = r1;
    (w->s).work[1] = r2;
  }
  return w;
}

struct Widget *CreateArmorIcons2(struct GameState *g, struct Widget *p, u8 r2, u8 r3) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 5);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    w->props.armorIcon.w = p;
    (w->s).work[0] = 1;
    (w->s).work[1] = r2;
    w->props.armorIcon.unk_78[0] = r3;
  }
  return w;
}

// --------------------------------------------

static void FUN_080e6ab8(struct Widget *w);
static void FUN_080e6bb8(struct Widget *w);

static void ArmorIcons_Init(struct Widget *w) {
  s32 x, y;

  if ((w->s).work[0] != 0) {
    FUN_080e6bb8(w);
  } else {
    FUN_080e6ab8(w);
  }

  x = (w->s).coord.x;
  y = (w->s).coord.y;
  (w->s).unk_coord.x = x;
  (w->s).unk_coord.y = y;
  ArmorIcons_Update(w);
}

static void FUN_080e6f6c(struct Widget *w);
static void FUN_080e6c94(struct Widget *w);

static void ArmorIcons_Update(struct Widget *w) {
  (w->s).coord = (w->s).unk_coord;
  if ((w->s).work[0] != 0) {
    FUN_080e6f6c(w);
  } else {
    FUN_080e6c94(w);
  }
  (w->s).unk_coord = (w->s).coord;
  if (BGOFS(1)->x > 0x100) {
    (w->s).coord.x += PIXEL(512);
  }
}

static void ArmorIcons_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}

// --------------------------------------------

NAKED static void FUN_080e6ab8(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r0, [r5, #0x28]\n\
	ldr r1, _080E6B0C @ =0x000064AC\n\
	adds r0, r0, r1\n\
	ldr r4, [r0]\n\
	ldr r1, _080E6B10 @ =gWidgetFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #0\n\
	bne _080E6B18\n\
	ldr r1, _080E6B14 @ =sHeadChipMotions\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xf]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
	b _080E6B64\n\
	.align 2, 0\n\
_080E6B0C: .4byte 0x000064AC\n\
_080E6B10: .4byte gWidgetFnTable\n\
_080E6B14: .4byte sHeadChipMotions\n\
_080E6B18:\n\
	cmp r0, #1\n\
	bne _080E6B48\n\
	ldr r1, _080E6B40 @ =sBodyChipMotions\n\
	adds r4, #0xb4\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r1, _080E6B44 @ =sBodyChipPalIDs\n\
	ldrb r0, [r4, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	adds r0, r5, #0\n\
	bl ForceEntityPalette\n\
	b _080E6B64\n\
	.align 2, 0\n\
_080E6B40: .4byte sBodyChipMotions\n\
_080E6B44: .4byte sBodyChipPalIDs\n\
_080E6B48:\n\
	ldr r1, _080E6BB0 @ =sFootChipMotions\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
_080E6B64:\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	subs r3, #1\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r0, #0x9c\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x54]\n\
	ldr r1, _080E6BB4 @ =sChipHeight\n\
	ldrb r0, [r5, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	adds r0, #0x79\n\
	strb r2, [r0]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E6BB0: .4byte sFootChipMotions\n\
_080E6BB4: .4byte sChipHeight\n\
 .syntax divided\n");
}

NAKED static void FUN_080e6bb8(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x74]\n\
	ldr r1, _080E6C04 @ =gWidgetFnTable\n\
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
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #0\n\
	bne _080E6C0C\n\
	ldr r0, _080E6C08 @ =sHeadChipMotions\n\
	ldrb r1, [r4, #0x11]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
	b _080E6C50\n\
	.align 2, 0\n\
_080E6C04: .4byte gWidgetFnTable\n\
_080E6C08: .4byte sHeadChipMotions\n\
_080E6C0C:\n\
	cmp r0, #1\n\
	bne _080E6C38\n\
	ldr r1, _080E6C30 @ =sBodyChipMotions\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r1, _080E6C34 @ =sBodyChipPalIDs\n\
	ldrb r0, [r4, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	adds r0, r4, #0\n\
	bl ForceEntityPalette\n\
	b _080E6C50\n\
	.align 2, 0\n\
_080E6C30: .4byte sBodyChipMotions\n\
_080E6C34: .4byte sBodyChipPalIDs\n\
_080E6C38:\n\
	ldr r0, _080E6C90 @ =sFootChipMotions\n\
	ldrb r1, [r4, #0x11]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
_080E6C50:\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	subs r3, #1\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	strb r2, [r4, #0x12]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E6C90: .4byte sFootChipMotions\n\
 .syntax divided\n");
}

NAKED static void FUN_080e6c94(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	ldr r0, [r6, #0x28]\n\
	mov r8, r0\n\
	ldr r0, _080E6CD8 @ =0x000064AC\n\
	add r0, r8\n\
	ldr r4, [r0]\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r2, _080E6CDC @ =0x00000DCC\n\
	add r2, r8\n\
	ldrb r0, [r2, #4]\n\
	cmp r0, #0\n\
	beq _080E6CE4\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r1, _080E6CE0 @ =gWidgetFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r6, #0x14]\n\
	b _080E6F62\n\
	.align 2, 0\n\
_080E6CD8: .4byte 0x000064AC\n\
_080E6CDC: .4byte 0x00000DCC\n\
_080E6CE0: .4byte gWidgetFnTable\n\
_080E6CE4:\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #1\n\
	bne _080E6CEC\n\
	b _080E6EAE\n\
_080E6CEC:\n\
	cmp r0, #1\n\
	bgt _080E6CF6\n\
	cmp r0, #0\n\
	beq _080E6D04\n\
	b _080E6F62\n\
_080E6CF6:\n\
	cmp r0, #2\n\
	bne _080E6CFC\n\
	b _080E6EC4\n\
_080E6CFC:\n\
	cmp r0, #3\n\
	bne _080E6D02\n\
	b _080E6F50\n\
_080E6D02:\n\
	b _080E6F62\n\
_080E6D04:\n\
	mov r0, r8\n\
	ldrb r1, [r0, #3]\n\
	ldrb r0, [r6, #0x11]\n\
	adds r0, #4\n\
	cmp r1, r0\n\
	beq _080E6D12\n\
	b _080E6F62\n\
_080E6D12:\n\
	str r6, [r2, #0x20]\n\
	ldrb r3, [r6, #0x11]\n\
	cmp r3, #0\n\
	bne _080E6D82\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r2, [r0, #0x17]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x19\n\
	adds r1, r1, r0\n\
	movs r0, #4\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1a\n\
	adds r1, r1, r0\n\
	movs r0, #8\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1b\n\
	adds r1, r1, r0\n\
	adds r4, r6, #0\n\
	adds r4, #0x79\n\
	strb r1, [r4]\n\
	mov r0, r8\n\
	movs r1, #0xff\n\
	bl CheckUnlockedHead\n\
	movs r5, #0\n\
	adds r7, r4, #0\n\
	ldrb r1, [r7]\n\
	cmp r5, r1\n\
	blo _080E6D5C\n\
	b _080E6E8A\n\
_080E6D5C:\n\
	lsls r4, r5, #0x18\n\
	lsrs r4, r4, #0x18\n\
	mov r0, r8\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedHead\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	adds r3, r4, #0\n\
	bl CreateArmorIcons2\n\
	adds r5, #1\n\
	ldrb r0, [r7]\n\
	cmp r5, r0\n\
	blo _080E6D5C\n\
	b _080E6E8A\n\
_080E6D82:\n\
	cmp r3, #1\n\
	bne _080E6DFE\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r2, [r0, #0x18]\n\
	ands r3, r2\n\
	movs r1, #2\n\
	ands r1, r2\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x19\n\
	adds r1, r3, r1\n\
	movs r0, #4\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1a\n\
	adds r1, r1, r0\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1c\n\
	adds r1, r1, r0\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1d\n\
	adds r1, r1, r0\n\
	movs r0, #8\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1b\n\
	adds r1, r1, r0\n\
	adds r4, r6, #0\n\
	adds r4, #0x79\n\
	strb r1, [r4]\n\
	mov r0, r8\n\
	movs r1, #0xff\n\
	bl CheckUnlockedBody\n\
	movs r5, #0\n\
	adds r7, r4, #0\n\
	ldrb r1, [r7]\n\
	cmp r5, r1\n\
	bhs _080E6E8A\n\
_080E6DD8:\n\
	lsls r4, r5, #0x18\n\
	lsrs r4, r4, #0x18\n\
	mov r0, r8\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedBody\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	adds r3, r4, #0\n\
	bl CreateArmorIcons2\n\
	adds r5, #1\n\
	ldrb r0, [r7]\n\
	cmp r5, r0\n\
	blo _080E6DD8\n\
	b _080E6E8A\n\
_080E6DFE:\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r2, [r0, #0x19]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x19\n\
	adds r1, r1, r0\n\
	movs r0, #4\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1a\n\
	adds r1, r1, r0\n\
	movs r0, #8\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1b\n\
	adds r1, r1, r0\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1c\n\
	adds r1, r1, r0\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1d\n\
	adds r1, r1, r0\n\
	movs r0, #0x40\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1e\n\
	adds r1, r1, r0\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x1f\n\
	adds r1, r1, r0\n\
	adds r4, r6, #0\n\
	adds r4, #0x79\n\
	strb r1, [r4]\n\
	mov r0, r8\n\
	movs r1, #0xff\n\
	bl CheckUnlockedFoot\n\
	movs r5, #0\n\
	adds r7, r4, #0\n\
	ldrb r1, [r7]\n\
	cmp r5, r1\n\
	bhs _080E6E8A\n\
_080E6E66:\n\
	lsls r4, r5, #0x18\n\
	lsrs r4, r4, #0x18\n\
	mov r0, r8\n\
	adds r1, r4, #0\n\
	bl CheckUnlockedFoot\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r0, r8\n\
	adds r1, r6, #0\n\
	adds r3, r4, #0\n\
	bl CreateArmorIcons2\n\
	adds r5, #1\n\
	ldrb r0, [r7]\n\
	cmp r5, r0\n\
	blo _080E6E66\n\
_080E6E8A:\n\
	ldr r0, _080E6E9C @ =u8_ARRAY_083720b5\n\
	ldrb r1, [r6, #0x10]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r7]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bls _080E6EA0\n\
	movs r0, #0xc\n\
	b _080E6EA2\n\
	.align 2, 0\n\
_080E6E9C: .4byte u8_ARRAY_083720b5\n\
_080E6EA0:\n\
	movs r0, #8\n\
_080E6EA2:\n\
	strb r0, [r6, #0x12]\n\
	movs r0, #0\n\
	strb r0, [r6, #0x13]\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	b _080E6F60\n\
_080E6EAE:\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r6, #0x12]\n\
	cmp r0, r1\n\
	blo _080E6F62\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	b _080E6F60\n\
_080E6EC4:\n\
	ldrb r0, [r2, #5]\n\
	cmp r0, #0\n\
	beq _080E6F62\n\
	ldrb r0, [r6, #0x11]\n\
	cmp r0, #0\n\
	bne _080E6EF4\n\
	ldr r1, _080E6EF0 @ =sHeadChipMotions\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xf]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
	b _080E6F40\n\
	.align 2, 0\n\
_080E6EF0: .4byte sHeadChipMotions\n\
_080E6EF4:\n\
	cmp r0, #1\n\
	bne _080E6F24\n\
	ldr r1, _080E6F1C @ =sBodyChipMotions\n\
	adds r4, #0xb4\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldr r1, _080E6F20 @ =sBodyChipPalIDs\n\
	ldrb r0, [r4, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	adds r0, r6, #0\n\
	bl ForceEntityPalette\n\
	b _080E6F40\n\
	.align 2, 0\n\
_080E6F1C: .4byte sBodyChipMotions\n\
_080E6F20: .4byte sBodyChipPalIDs\n\
_080E6F24:\n\
	ldr r1, _080E6F4C @ =sFootChipMotions\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0x11]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	movs r1, #5\n\
	bl ForceEntityPalette\n\
_080E6F40:\n\
	adds r0, r6, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r6, #0xd]\n\
	adds r0, #1\n\
	b _080E6F60\n\
	.align 2, 0\n\
_080E6F4C: .4byte sFootChipMotions\n\
_080E6F50:\n\
	ldrb r0, [r6, #0x13]\n\
	subs r0, #1\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080E6F62\n\
	strb r0, [r2, #5]\n\
_080E6F60:\n\
	strb r0, [r6, #0xd]\n\
_080E6F62:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void FUN_080e6f6c(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x28]\n\
	ldr r6, [r5, #0x74]\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #4\n\
	bls _080E6F84\n\
	b _080E70DA\n\
_080E6F84:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E6F90 @ =_080E6F94\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E6F90: .4byte _080E6F94\n\
_080E6F94: @ jump table\n\
	.4byte _080E6FA8 @ case 0\n\
	.4byte _080E6FF0 @ case 1\n\
	.4byte _080E700A @ case 2\n\
	.4byte _080E705C @ case 3\n\
	.4byte _080E7094 @ case 4\n\
_080E6FA8:\n\
	ldrb r4, [r5, #0x12]\n\
	adds r4, #1\n\
	strb r4, [r5, #0x12]\n\
	adds r7, r5, #0\n\
	adds r7, #0x78\n\
	ldr r0, _080E6FEC @ =u8_ARRAY_083720b8\n\
	mov r8, r0\n\
	ldrb r1, [r6, #0x11]\n\
	add r1, r8\n\
	ldrb r0, [r7]\n\
	ldrb r1, [r1]\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0xf\n\
	ldr r1, [r5, #0x54]\n\
	subs r1, r1, r0\n\
	str r1, [r5, #0x54]\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	cmp r4, #7\n\
	bhi _080E6FD6\n\
	b _080E70DA\n\
_080E6FD6:\n\
	ldrb r0, [r6, #0x11]\n\
	add r0, r8\n\
	ldrb r1, [r7]\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	bhs _080E7082\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #2\n\
	strb r0, [r5, #0xd]\n\
	b _080E70DA\n\
	.align 2, 0\n\
_080E6FEC: .4byte u8_ARRAY_083720b8\n\
_080E6FF0:\n\
	ldrb r1, [r5, #0x12]\n\
	adds r1, #1\n\
	strb r1, [r5, #0x12]\n\
	ldr r0, [r5, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r5, #0x58]\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	cmp r1, #0xb\n\
	bls _080E70DA\n\
	b _080E7082\n\
_080E700A:\n\
	ldr r1, _080E7040 @ =0x00000DCC\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0, #5]\n\
	cmp r0, #0\n\
	beq _080E70DA\n\
	ldrb r2, [r5, #0x1e]\n\
	lsls r2, r2, #8\n\
	adds r0, r5, #0\n\
	adds r0, #0x70\n\
	ldrb r0, [r0]\n\
	orrs r2, r0\n\
	ldrb r0, [r6, #0x1e]\n\
	lsls r0, r0, #8\n\
	adds r1, r6, #0\n\
	adds r1, #0x70\n\
	ldrb r1, [r1]\n\
	orrs r0, r1\n\
	cmp r2, r0\n\
	bne _080E7044\n\
	adds r2, r5, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080E7056\n\
	.align 2, 0\n\
_080E7040: .4byte 0x00000DCC\n\
_080E7044:\n\
	adds r2, r5, #0\n\
	adds r2, #0x49\n\
	ldrb r0, [r2]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r0\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
_080E7056:\n\
	ldrb r0, [r6, #0x13]\n\
	strb r0, [r5, #0x12]\n\
	b _080E7082\n\
_080E705C:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	adds r2, r5, #0\n\
	adds r2, #0x78\n\
	ldr r1, _080E708C @ =u8_ARRAY_083720b8\n\
	ldrb r0, [r6, #0x11]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r2]\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	blo _080E707C\n\
	ldr r0, [r5, #0x58]\n\
	ldr r2, _080E7090 @ =0xFFFFFC00\n\
	adds r0, r0, r2\n\
	str r0, [r5, #0x58]\n\
_080E707C:\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #8\n\
	bhi _080E70DA\n\
_080E7082:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
	b _080E70DA\n\
	.align 2, 0\n\
_080E708C: .4byte u8_ARRAY_083720b8\n\
_080E7090: .4byte 0xFFFFFC00\n\
_080E7094:\n\
	ldrb r4, [r5, #0x12]\n\
	subs r4, #1\n\
	strb r4, [r5, #0x12]\n\
	adds r2, r5, #0\n\
	adds r2, #0x78\n\
	ldr r0, _080E70E4 @ =u8_ARRAY_083720b8\n\
	ldrb r1, [r6, #0x11]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r2]\n\
	ldrb r1, [r1]\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0xf\n\
	ldr r1, [r5, #0x54]\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x54]\n\
	lsls r4, r4, #0x18\n\
	cmp r4, #0\n\
	bne _080E70DA\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080E70E8 @ =gWidgetFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
_080E70DA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E70E4: .4byte u8_ARRAY_083720b8\n\
_080E70E8: .4byte gWidgetFnTable\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

const motion_t sHeadChipMotions[4] = {
    MOTION(SM014_CHIPICON, 0x1B),
    MOTION(SM014_CHIPICON, 0x1E),
    MOTION(SM014_CHIPICON, 0x1C),
    MOTION(SM014_CHIPICON, 0x1D),
};

// --------------------------------------------

// clang-format off
const motion_t sBodyChipMotions[6] = {
    MOTION(SM014_CHIPICON, 0x1F),
    MOTION(SM014_CHIPICON, 0x24),
    MOTION(SM014_CHIPICON, 0x23),
    MOTION(SM014_CHIPICON, 0x07),
    MOTION(SM014_CHIPICON, 0x08),
    MOTION(SM014_CHIPICON, 0x09),
};
// clang-format on

const u8 sBodyChipPalIDs[6] = {5, 5, 5, 4, 4, 4};

// --------------------------------------------

// clang-format off
const motion_t sFootChipMotions[8] = {
    MOTION(SM014_CHIPICON, 0x25),
    MOTION(SM014_CHIPICON, 0x26),
    MOTION(SM014_CHIPICON, 0x27),
    MOTION(SM014_CHIPICON, 0x28),
    MOTION(SM014_CHIPICON, 0x29),
    MOTION(SM014_CHIPICON, 0x2A),
    MOTION(SM014_CHIPICON, 0x2B),
    MOTION(SM014_CHIPICON, 0x2C),
};
// clang-format on

// --------------------------------------------

const u8 sChipHeight[3] = {
    [ARMORS_HEAD] = 0x38,
    [ARMORS_BODY] = 0x50,
    [ARMORS_FOOT] = 0x68,
};

const u8 u8_ARRAY_083720b5[3] = {
    [ARMORS_HEAD] = 4,
    [ARMORS_BODY] = 3,
    [ARMORS_FOOT] = 4,
};

const u8 u8_ARRAY_083720b8[3] = {
    [ARMORS_HEAD] = 4,
    [ARMORS_BODY] = 3,
    [ARMORS_FOOT] = 4,
};
