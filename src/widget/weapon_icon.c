#include "global.h"
#include "overworld.h"
#include "widget.h"

static void MenuWeapon_Init(struct Widget *w);
static void MenuWeapon_Update(struct Widget *w);
static void MenuWeapon_Die(struct Widget *w);

// clang-format off
const WidgetRoutine gMenuWeaponIconRoutine = {
    [ENTITY_INIT] =      MenuWeapon_Init,
    [ENTITY_UPDATE] =    MenuWeapon_Update,
    [ENTITY_DIE] =       MenuWeapon_Die,
    [ENTITY_DISAPPEAR] = DeleteWidget,
    [ENTITY_EXIT] =      (WidgetFunc)DeleteEntity,
};
// clang-format on

const motion_t sWeaponIconMotions[4] = {
    [WEAPON_BUSTER] = MOTION(SM014_CHIPICON, 0),
    [WEAPON_SABER] = MOTION(SM014_CHIPICON, 1),
    [WEAPON_ROD] = MOTION(SM014_CHIPICON, 2),
    [WEAPON_SHIELD] = MOTION(SM014_CHIPICON, 3),
};

// ------------------------------------------------------------------------------------------------------------------------------------

struct Widget *createMenuWeaponIcon(void *g, weapon_t weapon, bool8 isSubWeapon, bool8 r3) {
  struct Widget *w = (struct Widget *)AllocEntityFirst(gWidgetHeaderPtr);
  if (w != NULL) {
    (w->s).taskCol = 16;
    INIT_WIDGET_ROUTINE(w, 0);
    (w->s).tileNum = 0;
    (w->s).palID = 0;
    (w->s).unk_28 = (struct Entity *)g;
    (w->s).work[0] = weapon;
    (w->s).work[1] = isSubWeapon;
    (w->s).work[3] = r3;
  }
  return w;
}

static void MenuWeapon_Init(struct Widget *w) {
  s32 x, y;

  SET_WIDGET_ROUTINE(w, ENTITY_UPDATE);
  InitNonAffineMotion(&w->s);
  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, sWeaponIconMotions[(w->s).work[0]]);
  (w->s).spr.xflip = FALSE;
  (w->s).spr.oam.xflip = FALSE;
  (w->s).flags &= ~X_FLIP;

  (w->s).coord.x = 0x4400;
  if ((w->s).work[1] != 0) {
    (w->s).coord.y = 0x5000;  // sub
  } else {
    (w->s).coord.y = 0x3800;  // main
  }

  (w->s).work[2] = 0;
  if ((w->s).work[3] != 0) {
    (w->s).spr.oam.priority = 1;
    (w->s).mode[1] = 2;
  } else {
    (w->s).spr.oam.priority = 0;
  }

  x = (w->s).coord.x;
  y = (w->s).coord.y;
  (w->s).unk_coord.x = x;
  (w->s).unk_coord.y = y;
  MenuWeapon_Update(w);
}

NAKED static void MenuWeapon_Update(struct Widget *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	ldr r7, [r4, #0x28]\n\
	ldr r1, _080E6014 @ =0x000064AC\n\
	adds r0, r7, r1\n\
	ldr r3, [r0]\n\
	ldr r1, _080E6018 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0, #4]\n\
	cmp r0, #0\n\
	beq _080E6020\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E601C @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E6216\n\
	.align 2, 0\n\
_080E6014: .4byte 0x000064AC\n\
_080E6018: .4byte 0x00000DCC\n\
_080E601C: .4byte gWidgetFnTable\n\
_080E6020:\n\
	ldr r0, [r4, #0x64]\n\
	ldr r1, [r4, #0x68]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #5\n\
	bls _080E6030\n\
	b _080E61F2\n\
_080E6030:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080E603C @ =_080E6040\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080E603C: .4byte _080E6040\n\
_080E6040: @ jump table\n\
	.4byte _080E6058 @ case 0\n\
	.4byte _080E60C0 @ case 1\n\
	.4byte _080E60FA @ case 2\n\
	.4byte _080E6118 @ case 3\n\
	.4byte _080E612C @ case 4\n\
	.4byte _080E6174 @ case 5\n\
_080E6058:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	beq _080E6090\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0xd]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, r1\n\
	beq _080E607C\n\
	strb r1, [r4, #0x10]\n\
	ldr r0, _080E608C @ =sWeaponIconMotions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E607C:\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #2\n\
	beq _080E6084\n\
	b _080E61F2\n\
_080E6084:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	b _080E61F0\n\
	.align 2, 0\n\
_080E608C: .4byte sWeaponIconMotions\n\
_080E6090:\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0xc]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, r1\n\
	beq _080E60AE\n\
	strb r1, [r4, #0x10]\n\
	ldr r0, _080E60BC @ =sWeaponIconMotions\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r1, [r1]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E60AE:\n\
	ldrb r0, [r7, #3]\n\
	cmp r0, #1\n\
	beq _080E60B6\n\
	b _080E61F2\n\
_080E60B6:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	b _080E61F0\n\
	.align 2, 0\n\
_080E60BC: .4byte sWeaponIconMotions\n\
_080E60C0:\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #0x16]\n\
	movs r0, #0xc\n\
	ands r0, r1\n\
	movs r6, #2\n\
	cmp r0, #0\n\
	beq _080E60D2\n\
	movs r6, #4\n\
_080E60D2:\n\
	movs r5, #0\n\
	cmp r5, r6\n\
	bhs _080E60F4\n\
_080E60D8:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r5, r0\n\
	beq _080E60EA\n\
	ldrb r2, [r4, #0x11]\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	movs r3, #1\n\
	bl createMenuWeaponIcon\n\
_080E60EA:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, r6\n\
	blo _080E60D8\n\
_080E60F4:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E60FA:\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
	ldrb r2, [r4, #0x10]\n\
	lsls r2, r2, #9\n\
	ldr r1, [r4, #0x54]\n\
	adds r1, r1, r2\n\
	str r1, [r4, #0x54]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _080E61F2\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	b _080E61F0\n\
_080E6118:\n\
	ldr r1, _080E6128 @ =0x00000DCC\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0, #5]\n\
	cmp r0, #0\n\
	beq _080E61F2\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	b _080E61F0\n\
	.align 2, 0\n\
_080E6128: .4byte 0x00000DCC\n\
_080E612C:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	beq _080E6140\n\
	adds r1, r3, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r1, [r1, #0xd]\n\
	cmp r0, r1\n\
	beq _080E614C\n\
	b _080E615C\n\
_080E6140:\n\
	adds r1, r3, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r4, #0x10]\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r0, r1\n\
	bne _080E615C\n\
_080E614C:\n\
	adds r2, r4, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080E616E\n\
_080E615C:\n\
	adds r2, r4, #0\n\
	adds r2, #0x49\n\
	ldrb r0, [r2]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r0\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
_080E616E:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080E6174:\n\
	ldrb r2, [r4, #0x12]\n\
	subs r2, #1\n\
	strb r2, [r4, #0x12]\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #9\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	lsls r2, r2, #0x18\n\
	cmp r2, #0\n\
	bne _080E61F2\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	beq _080E61B4\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E61B0 @ =gWidgetFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E61F2\n\
	.align 2, 0\n\
_080E61B0: .4byte gWidgetFnTable\n\
_080E61B4:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	beq _080E61C2\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xd]\n\
	b _080E61C8\n\
_080E61C2:\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xc]\n\
_080E61C8:\n\
	strb r0, [r4, #0x10]\n\
	ldr r1, _080E621C @ =sWeaponIconMotions\n\
	ldrb r0, [r4, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r2, r4, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r0, _080E6220 @ =0x00000DCC\n\
	adds r1, r7, r0\n\
	movs r0, #0\n\
	strb r0, [r1, #5]\n\
_080E61F0:\n\
	strb r0, [r4, #0xd]\n\
_080E61F2:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	str r0, [r4, #0x64]\n\
	str r1, [r4, #0x68]\n\
	ldr r0, _080E6224 @ =gVideoRegBuffer+16\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bls _080E6216\n\
	ldr r0, [r4, #0x54]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
_080E6216:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E621C: .4byte sWeaponIconMotions\n\
_080E6220: .4byte 0x00000DCC\n\
_080E6224: .4byte gVideoRegBuffer+16\n\
 .syntax divided\n");
}

static void MenuWeapon_Die(struct Widget *w) {
  SET_WIDGET_ROUTINE(w, ENTITY_EXIT);
  return;
}
