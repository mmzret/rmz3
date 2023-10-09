#include "entity.h"
#include "gfx.h"
#include "vfx.h"
#include "global.h"

/*
work[0]:
  00: ???
  01: ミッション選択時のボス顔
  02: ???
  03: レジスタンスベース司令室の世界地図上の黄色い点
  04: ???
*/

#define BOSS_MUGSHOT 1
#define MISSION_LOCATION 3

static void Ghost71_Init(struct VFX* p);
static void Ghost71_Update(struct VFX* p);
static void Ghost71_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost71Routine = {
    [ENTITY_INIT] =      Ghost71_Init,
    [ENTITY_UPDATE] =    Ghost71_Update,
    [ENTITY_DIE] =       Ghost71_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

NAKED struct VFX* CreateStageBossMugshots(void* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	mov sl, r0\n\
	movs r5, #0xff\n\
	lsls r5, r5, #4\n\
	ldr r7, _080C5E50 @ =gStaticMotionGraphics\n\
	adds r0, r5, r7\n\
	ldr r1, _080C5E54 @ =wStaticGraphicTilenums\n\
	mov r8, r1\n\
	movs r4, #0xcc\n\
	lsls r4, r4, #1\n\
	adds r1, r1, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	mov sb, r2\n\
	add r1, sb\n\
	bl LoadGraphic\n\
	ldr r0, _080C5E58 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r1, _080C5E5C @ =wStaticMotionPalIDs\n\
	adds r4, r1, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r5, _080C5E60 @ =0x0000102C\n\
	adds r0, r5, r7\n\
	movs r4, #0xcf\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, sb\n\
	bl LoadGraphic\n\
	ldr r0, _080C5E58 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r1, _080C5E5C @ =wStaticMotionPalIDs\n\
	adds r4, r1, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r0, _080C5E64 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	beq _080C5E30\n\
	adds r1, r6, #0\n\
	adds r1, #0x25\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _080C5E68 @ =gVFXFnTable\n\
	movs r1, #0x47\n\
	strb r1, [r6, #9]\n\
	adds r1, #0xd5\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #0\n\
	strh r2, [r6, #0x20]\n\
	adds r1, r6, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	movs r0, #2\n\
	strb r0, [r6, #0x10]\n\
	mov r2, sl\n\
	str r2, [r6, #0x28]\n\
_080C5E30:\n\
	ldr r2, _080C5E6C @ =gCurStory\n\
	ldrb r1, [r2, #5]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C5E74\n\
	movs r0, #4\n\
	str r0, [sp]\n\
	movs r1, #0\n\
	mov sl, r1\n\
	ldr r5, _080C5E70 @ =0x00001004\n\
	adds r0, r7, r5\n\
	movs r4, #0xcd\n\
	lsls r4, r4, #1\n\
	b _080C5E9E\n\
	.align 2, 0\n\
_080C5E50: .4byte gStaticMotionGraphics\n\
_080C5E54: .4byte wStaticGraphicTilenums\n\
_080C5E58: .4byte gStaticMotionGraphics+12\n\
_080C5E5C: .4byte wStaticMotionPalIDs\n\
_080C5E60: .4byte 0x0000102C\n\
_080C5E64: .4byte gVFXHeaderPtr\n\
_080C5E68: .4byte gVFXFnTable\n\
_080C5E6C: .4byte gCurStory\n\
_080C5E70: .4byte 0x00001004\n\
_080C5E74:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C5E84\n\
	movs r0, #3\n\
	str r0, [sp]\n\
	movs r1, #4\n\
	b _080C5E94\n\
_080C5E84:\n\
	ldrb r1, [r2, #6]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C5EDC\n\
	movs r0, #1\n\
	str r0, [sp]\n\
	movs r1, #7\n\
_080C5E94:\n\
	mov sl, r1\n\
	ldr r5, _080C5ED0 @ =0x00001018\n\
	adds r0, r7, r5\n\
	movs r4, #0xce\n\
	lsls r4, r4, #1\n\
_080C5E9E:\n\
	mov r2, r8\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, sb\n\
	bl LoadGraphic\n\
	ldr r0, _080C5ED4 @ =gStaticMotionGraphics+12\n\
	adds r5, r0, r5\n\
	ldr r1, _080C5ED8 @ =wStaticMotionPalIDs\n\
	adds r4, r1, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	b _080C5F1E\n\
	.align 2, 0\n\
_080C5ED0: .4byte 0x00001018\n\
_080C5ED4: .4byte gStaticMotionGraphics+12\n\
_080C5ED8: .4byte wStaticMotionPalIDs\n\
_080C5EDC:\n\
	movs r0, #4\n\
	str r0, [sp]\n\
	movs r1, #8\n\
	mov sl, r1\n\
	movs r5, #0x82\n\
	lsls r5, r5, #5\n\
	adds r0, r7, r5\n\
	movs r4, #0xd0\n\
	lsls r4, r4, #1\n\
	mov r2, r8\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, sb\n\
	bl LoadGraphic\n\
	ldr r0, _080C5F88 @ =gStaticMotionGraphics+12\n\
	adds r5, r0, r5\n\
	ldr r1, _080C5F8C @ =wStaticMotionPalIDs\n\
	adds r4, r1, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
_080C5F1E:\n\
	mov r1, sl\n\
	lsls r0, r1, #0x10\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r2, [sp]\n\
	adds r0, r0, r2\n\
	cmp r4, r0\n\
	bge _080C5F74\n\
	movs r7, #0\n\
	movs r5, #1\n\
	ldr r1, _080C5F90 @ =gVFXFnTable+(71*4)\n\
	mov sb, r1\n\
	mov r8, r0\n\
_080C5F38:\n\
	ldr r0, _080C5F94 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _080C5F64\n\
	adds r0, #0x25\n\
	strb r5, [r0]\n\
	movs r0, #0x47\n\
	strb r0, [r1, #9]\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	ldr r0, [r0]\n\
	str r0, [r1, #0x14]\n\
	strh r7, [r1, #0x20]\n\
	adds r0, r1, #0\n\
	adds r0, #0x22\n\
	strb r7, [r0]\n\
	strb r5, [r1, #0x10]\n\
	strb r4, [r1, #0x11]\n\
	str r6, [r1, #0x28]\n\
_080C5F64:\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r0, r1\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r8\n\
	blt _080C5F38\n\
_080C5F74:\n\
	adds r0, r6, #0\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080C5F88: .4byte gStaticMotionGraphics+12\n\
_080C5F8C: .4byte wStaticMotionPalIDs\n\
_080C5F90: .4byte gVFXFnTable+(71*4)\n\
_080C5F94: .4byte gVFXHeaderPtr\n\
 .syntax divided\n");
}

void FUN_080c5f98(struct VFX* p) {
  SET_VFX_ROUTINE(p, ENTITY_DIE);
  return;
}

// --------------------------------------------

static void FUN_080c5ff8(struct VFX* p);
static void FUN_080c6778(struct VFX* p);

static void Ghost71_Init(struct VFX* p) {
  // clang-format off
  static const VFXFunc sInitializers[] = {
      FUN_080c5ff8,
      FUN_080c5ff8,
      FUN_080c5ff8,
      FUN_080c5ff8,
      FUN_080c6778,
  };
  // clang-format on
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c6018(struct VFX* p);
static void updateBossMugshot(struct VFX* p);
static void FUN_080c647c(struct VFX* p);
static void updateMissionPoint(struct VFX* p);
static void nop_080c687c(struct VFX* p);

void Ghost71_Update(struct VFX* p) {
  // clang-format off
  static const VFXFunc sUpdates[] = {
      FUN_080c6018,
      updateBossMugshot,
      FUN_080c647c,
      updateMissionPoint,
      nop_080c687c,
  };
  // clang-format on
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c6038(struct VFX* p);
static void FUN_080c65ac(struct VFX* p);

static void Ghost71_Die(struct VFX* p) {
  // clang-format off
  static const VFXFunc sDeinitializers[] = {
      FUN_080c6038,
      FUN_080c6038,
      FUN_080c65ac,
      FUN_080c6038,
      FUN_080c6038,
  };
  // clang-format on
  (sDeinitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void FUN_080c5ff8(struct VFX* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost71_Update(p);
}

static void FUN_080c6018(struct VFX* p) {
  SET_VFX_ROUTINE(p, ENTITY_DIE);
  Ghost71_Die(p);
}

static void FUN_080c6038(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void updateBossMugshot(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #5\n\
	bls _080C6064\n\
	b _080C63BC\n\
_080C6064:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080C6070 @ =_080C6074\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080C6070: .4byte _080C6074\n\
_080C6074: @ jump table\n\
	.4byte _080C608C @ case 0\n\
	.4byte _080C614E @ case 1\n\
	.4byte _080C62C0 @ case 2\n\
	.4byte _080C6304 @ case 3\n\
	.4byte _080C6328 @ case 4\n\
	.4byte _080C635E @ case 5\n\
_080C608C:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl InitScalerotMotion2\n\
	adds r3, r5, #0\n\
	adds r3, #0x45\n\
	ldrb r1, [r3]\n\
	movs r2, #0xd\n\
	rsbs r2, r2, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r1, r5, #0\n\
	adds r1, #0x49\n\
	ldrb r0, [r1]\n\
	ands r2, r0\n\
	strb r2, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x25\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _080C60E4 @ =gMission\n\
	ldr r2, [r0]\n\
	ldr r0, _080C60E8 @ =MissionBitfields_0836f81c\n\
	ldrb r3, [r5, #0x11]\n\
	adds r0, r3, r0\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r2, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C60EC\n\
	movs r1, #0xcf\n\
	lsls r1, r1, #8\n\
	str r1, [r5, #0x5c]\n\
	b _080C6118\n\
	.align 2, 0\n\
_080C60E4: .4byte gMission\n\
_080C60E8: .4byte MissionBitfields_0836f81c\n\
_080C60EC:\n\
	adds r0, r3, #0\n\
	cmp r0, #3\n\
	bhi _080C6100\n\
	adds r0, r5, #0\n\
	adds r0, #0x22\n\
	strb r3, [r0]\n\
	ldrb r1, [r5, #0x11]\n\
	movs r0, #0xcd\n\
	lsls r0, r0, #8\n\
	b _080C6110\n\
_080C6100:\n\
	cmp r0, #7\n\
	bhi _080C6124\n\
	subs r0, r3, #4\n\
	adds r1, r5, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldrb r1, [r5, #0x11]\n\
	ldr r0, _080C6120 @ =0x0000CDFC\n\
_080C6110:\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x5c]\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
_080C6118:\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	b _080C6140\n\
	.align 2, 0\n\
_080C6120: .4byte 0x0000CDFC\n\
_080C6124:\n\
	adds r0, r3, #0\n\
	subs r0, #8\n\
	adds r1, r5, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldrb r1, [r5, #0x11]\n\
	ldr r0, _080C6184 @ =0x0000CFF8\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x5c]\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
_080C6140:\n\
	movs r1, #0\n\
	movs r0, #0x1f\n\
	strb r0, [r5, #0x12]\n\
	strb r1, [r5, #0x13]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080C614E:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #3\n\
	bhi _080C6194\n\
	ldr r2, _080C6188 @ =sMissionLocation\n\
	adds r3, r0, #0\n\
	lsls r0, r3, #3\n\
	adds r0, r0, r2\n\
	ldrb r1, [r5, #0x12]\n\
	ldr r0, [r0]\n\
	muls r0, r1, r0\n\
	ldr r6, _080C618C @ =gStageRun+232\n\
	adds r7, r2, #0\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bge _080C6174\n\
	adds r0, #0x1f\n\
_080C6174:\n\
	asrs r0, r0, #5\n\
	ldr r1, _080C6190 @ =0xFFFF8800\n\
	adds r0, r0, r1\n\
	ldr r1, [r6, #0x38]\n\
	adds r2, r1, r0\n\
	lsls r0, r3, #4\n\
	subs r0, r0, r3\n\
	b _080C6248\n\
	.align 2, 0\n\
_080C6184: .4byte 0x0000CFF8\n\
_080C6188: .4byte sMissionLocation\n\
_080C618C: .4byte gStageRun+232\n\
_080C6190: .4byte 0xFFFF8800\n\
_080C6194:\n\
	cmp r0, #6\n\
	bhi _080C61D8\n\
	ldr r2, _080C61CC @ =sMissionLocation\n\
	ldrb r3, [r5, #0x11]\n\
	lsls r0, r3, #3\n\
	adds r0, r0, r2\n\
	ldrb r1, [r5, #0x12]\n\
	ldr r0, [r0]\n\
	muls r0, r1, r0\n\
	ldr r6, _080C61D0 @ =gStageRun+232\n\
	adds r7, r2, #0\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bge _080C61B2\n\
	adds r0, #0x1f\n\
_080C61B2:\n\
	asrs r0, r0, #5\n\
	ldr r1, _080C61D4 @ =0xFFFF8800\n\
	adds r0, r0, r1\n\
	ldr r1, [r6, #0x38]\n\
	adds r2, r1, r0\n\
	subs r1, r3, #4\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0xa\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #6\n\
	b _080C624E\n\
	.align 2, 0\n\
_080C61CC: .4byte sMissionLocation\n\
_080C61D0: .4byte gStageRun+232\n\
_080C61D4: .4byte 0xFFFF8800\n\
_080C61D8:\n\
	cmp r0, #7\n\
	bne _080C621C\n\
	ldr r2, _080C6210 @ =sMissionLocation\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r2\n\
	ldrb r1, [r5, #0x12]\n\
	ldr r0, [r0]\n\
	muls r0, r1, r0\n\
	ldr r6, _080C6214 @ =gStageRun+232\n\
	adds r7, r2, #0\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bge _080C61F6\n\
	adds r0, #0x1f\n\
_080C61F6:\n\
	asrs r0, r0, #5\n\
	ldr r1, _080C6218 @ =0xFFFF8800\n\
	adds r0, r0, r1\n\
	ldr r2, [r6, #0x38]\n\
	adds r2, r2, r0\n\
	movs r1, #0x20\n\
	subs r1, r1, r4\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #6\n\
	adds r2, r2, r0\n\
	str r2, [r5, #0x54]\n\
	b _080C6262\n\
	.align 2, 0\n\
_080C6210: .4byte sMissionLocation\n\
_080C6214: .4byte gStageRun+232\n\
_080C6218: .4byte 0xFFFF8800\n\
_080C621C:\n\
	ldr r2, _080C62B0 @ =sMissionLocation\n\
	ldrb r3, [r5, #0x11]\n\
	lsls r0, r3, #3\n\
	adds r0, r0, r2\n\
	ldrb r1, [r5, #0x12]\n\
	ldr r0, [r0]\n\
	muls r0, r1, r0\n\
	ldr r6, _080C62B4 @ =gStageRun+232\n\
	adds r7, r2, #0\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	bge _080C6236\n\
	adds r0, #0x1f\n\
_080C6236:\n\
	asrs r0, r0, #5\n\
	ldr r1, _080C62B8 @ =0xFFFF8800\n\
	adds r0, r0, r1\n\
	ldr r1, [r6, #0x38]\n\
	adds r2, r1, r0\n\
	adds r1, r3, #0\n\
	subs r1, #8\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
_080C6248:\n\
	lsls r0, r0, #0xa\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #5\n\
_080C624E:\n\
	adds r0, r0, r1\n\
	movs r1, #0x20\n\
	subs r1, r1, r4\n\
	muls r0, r1, r0\n\
	cmp r0, #0\n\
	bge _080C625C\n\
	adds r0, #0x1f\n\
_080C625C:\n\
	asrs r0, r0, #5\n\
	adds r0, r2, r0\n\
	str r0, [r5, #0x54]\n\
_080C6262:\n\
	ldrb r0, [r5, #0x11]\n\
	lsls r0, r0, #3\n\
	adds r1, r7, #4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	muls r0, r4, r0\n\
	cmp r0, #0\n\
	bge _080C6274\n\
	adds r0, #0x1f\n\
_080C6274:\n\
	asrs r0, r0, #5\n\
	ldr r1, _080C62BC @ =0xFFFFB000\n\
	adds r0, r0, r1\n\
	ldr r2, [r6, #0x3c]\n\
	adds r2, r2, r0\n\
	movs r1, #0x20\n\
	subs r1, r1, r4\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #6\n\
	adds r2, r2, r0\n\
	str r2, [r5, #0x58]\n\
	movs r2, #0x20\n\
	subs r0, r2, r4\n\
	lsls r0, r0, #3\n\
	adds r1, r5, #0\n\
	adds r1, #0x50\n\
	strh r0, [r1]\n\
	ldrb r0, [r5, #0x12]\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #3\n\
	adds r0, r5, #0\n\
	adds r0, #0x52\n\
	strh r2, [r0]\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #0\n\
	beq _080C6316\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	b _080C63BC\n\
	.align 2, 0\n\
_080C62B0: .4byte sMissionLocation\n\
_080C62B4: .4byte gStageRun+232\n\
_080C62B8: .4byte 0xFFFF8800\n\
_080C62BC: .4byte 0xFFFFB000\n\
_080C62C0:\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	adds r2, r5, #0\n\
	adds r2, #0x49\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, [r5, #0x5c]\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldr r0, _080C6320 @ =gMission\n\
	ldr r2, [r0]\n\
	ldr r1, _080C6324 @ =MissionBitfields_0836f81c\n\
	ldrb r0, [r5, #0x11]\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r2, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C62FE\n\
	adds r0, r5, #0\n\
	adds r0, #0x64\n\
	str r0, [r5, #0x40]\n\
_080C62FE:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080C6304:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, [r5, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _080C63BC\n\
	movs r0, #0\n\
	strb r0, [r5, #0x12]\n\
_080C6316:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
	b _080C63BC\n\
	.align 2, 0\n\
_080C6320: .4byte gMission\n\
_080C6324: .4byte MissionBitfields_0836f81c\n\
_080C6328:\n\
	adds r0, r5, #0\n\
	bl InitScalerotMotion2\n\
	adds r3, r5, #0\n\
	adds r3, #0x45\n\
	ldrb r1, [r3]\n\
	movs r2, #0xd\n\
	rsbs r2, r2, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r1, r5, #0\n\
	adds r1, #0x49\n\
	ldrb r0, [r1]\n\
	ands r2, r0\n\
	strb r2, [r1]\n\
	ldr r1, [r5, #0x5c]\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_080C635E:\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r5, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x12]\n\
	ldr r3, _080C63F0 @ =gSineTable\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #1\n\
	adds r2, r1, #0\n\
	subs r0, r2, r0\n\
	adds r1, r5, #0\n\
	adds r1, #0x52\n\
	strh r0, [r1]\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #8\n\
	bls _080C6398\n\
	subs r0, #8\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	ldrh r0, [r0]\n\
	subs r0, r2, r0\n\
	subs r1, #2\n\
	strh r0, [r1]\n\
_080C6398:\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #0x10\n\
	bne _080C63BC\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C63F4 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
_080C63BC:\n\
	ldr r0, _080C63F8 @ =gMission\n\
	ldr r2, [r0]\n\
	ldr r1, _080C63FC @ =MissionBitfields_0836f81c\n\
	ldrb r0, [r5, #0x11]\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	ldrb r0, [r0]\n\
	lsls r1, r0\n\
	ldr r0, [r2, #0x14]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C6474\n\
	ldrb r0, [r5, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x1a\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080C6400\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080C6406\n\
	.align 2, 0\n\
_080C63F0: .4byte gSineTable\n\
_080C63F4: .4byte gVFXFnTable\n\
_080C63F8: .4byte gMission\n\
_080C63FC: .4byte MissionBitfields_0836f81c\n\
_080C6400:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080C6406:\n\
	strb r0, [r5, #0xa]\n\
	movs r4, #1\n\
	adds r1, r2, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r0, [r5, #0x13]\n\
	lsrs r2, r0, #3\n\
	ands r2, r4\n\
	adds r4, r3, #0\n\
	cmp r2, #0\n\
	beq _080C6438\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	b _080C643E\n\
_080C6438:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_080C643E:\n\
	strb r0, [r5, #0xa]\n\
	movs r3, #1\n\
	adds r1, r2, #0\n\
	adds r2, r5, #0\n\
	adds r2, #0x4d\n\
	strb r1, [r2]\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r4]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	ldrb r2, [r5, #0x13]\n\
	lsls r2, r2, #0x18\n\
	lsrs r1, r2, #0x1a\n\
	ands r1, r3\n\
	lsls r1, r1, #8\n\
	ldr r0, [r5, #0x54]\n\
	subs r0, r0, r1\n\
	str r0, [r5, #0x64]\n\
	lsrs r2, r2, #0x1b\n\
	ands r2, r3\n\
	lsls r2, r2, #8\n\
	ldr r0, [r5, #0x58]\n\
	subs r0, r0, r2\n\
	str r0, [r5, #0x68]\n\
_080C6474:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void FUN_080c647c(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r1, [r4, #0x28]\n\
	movs r2, #0\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #3\n\
	bgt _080C6494\n\
	ldr r2, _080C6490 @ =gStageRun+232\n\
	adds r1, r0, #0\n\
	b _080C64CC\n\
	.align 2, 0\n\
_080C6490: .4byte gStageRun+232\n\
_080C6494:\n\
	cmp r0, #6\n\
	bgt _080C64B4\n\
	ldr r2, _080C64AC @ =gStageRun+232\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	subs r1, #4\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0xa\n\
	ldr r1, _080C64B0 @ =0xFFFFC400\n\
	b _080C64D4\n\
	.align 2, 0\n\
_080C64AC: .4byte gStageRun+232\n\
_080C64B0: .4byte 0xFFFFC400\n\
_080C64B4:\n\
	cmp r0, #7\n\
	bne _080C64C4\n\
	ldr r0, _080C64C0 @ =gStageRun+232\n\
	ldr r0, [r0, #0x38]\n\
	str r0, [r4, #0x54]\n\
	b _080C64DC\n\
	.align 2, 0\n\
_080C64C0: .4byte gStageRun+232\n\
_080C64C4:\n\
	ldr r2, _080C64EC @ =gStageRun+232\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	subs r1, #8\n\
_080C64CC:\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0xa\n\
	ldr r1, _080C64F0 @ =0xFFFFA600\n\
_080C64D4:\n\
	adds r0, r0, r1\n\
	ldr r1, [r2, #0x38]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
_080C64DC:\n\
	ldrb r5, [r4, #0xd]\n\
	cmp r5, #1\n\
	beq _080C6558\n\
	cmp r5, #1\n\
	bgt _080C64F4\n\
	cmp r5, #0\n\
	beq _080C64FA\n\
	b _080C65A6\n\
	.align 2, 0\n\
_080C64EC: .4byte gStageRun+232\n\
_080C64F0: .4byte 0xFFFFA600\n\
_080C64F4:\n\
	cmp r5, #2\n\
	beq _080C65A0\n\
	b _080C65A6\n\
_080C64FA:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	adds r3, r4, #0\n\
	adds r3, #0x45\n\
	ldrb r1, [r3]\n\
	movs r2, #0xd\n\
	rsbs r2, r2, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r1, r4, #0\n\
	adds r1, #0x49\n\
	ldrb r0, [r1]\n\
	ands r2, r0\n\
	strb r2, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	strb r5, [r0]\n\
	ldr r1, _080C6580 @ =0x0000CC01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, _080C6584 @ =gStageRun+232\n\
	ldr r0, [r0, #0x3c]\n\
	ldr r2, _080C6588 @ =0xFFFFD800\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x58]\n\
	ldr r0, _080C658C @ =gOverworld\n\
	ldr r1, _080C6590 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	strb r5, [r4, #0x13]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080C6558:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r3, _080C6594 @ =gBlendRegBuffer\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0x20\n\
	subs r0, r0, r2\n\
	asrs r0, r0, #1\n\
	movs r1, #0x1f\n\
	ands r0, r1\n\
	lsrs r2, r2, #1\n\
	lsls r2, r2, #8\n\
	orrs r0, r2\n\
	strh r0, [r3, #2]\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080C6598\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	b _080C65A6\n\
	.align 2, 0\n\
_080C6580: .4byte 0x0000CC01\n\
_080C6584: .4byte gStageRun+232\n\
_080C6588: .4byte 0xFFFFD800\n\
_080C658C: .4byte gOverworld\n\
_080C6590: .4byte 0x0002D025\n\
_080C6594: .4byte gBlendRegBuffer\n\
_080C6598:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080C65A6\n\
_080C65A0:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
_080C65A6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static void FUN_080c65ac(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	beq _080C65BC\n\
	cmp r0, #1\n\
	beq _080C65C6\n\
	b _080C6610\n\
_080C65BC:\n\
	movs r0, #0x10\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080C65C6:\n\
	ldr r3, _080C65E8 @ =gBlendRegBuffer\n\
	ldrb r5, [r4, #0x12]\n\
	movs r1, #0x1f\n\
	ands r1, r5\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0x10\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r3, #2]\n\
	lsls r0, r5, #0x18\n\
	cmp r0, #0\n\
	beq _080C65EC\n\
	subs r0, r5, #1\n\
	strb r0, [r4, #0x12]\n\
	b _080C6610\n\
	.align 2, 0\n\
_080C65E8: .4byte gBlendRegBuffer\n\
_080C65EC:\n\
	ldr r0, _080C6618 @ =gOverworld\n\
	ldr r1, _080C661C @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080C6620 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r4, #0x14]\n\
_080C6610:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C6618: .4byte gOverworld\n\
_080C661C: .4byte 0x0002D025\n\
_080C6620: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void updateMissionPoint(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r6, #0x10\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	ldrb r5, [r4, #0xd]\n\
	cmp r5, #0\n\
	beq _080C663A\n\
	cmp r5, #1\n\
	beq _080C66A2\n\
	b _080C676C\n\
_080C663A:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	bl InitScalerotMotion1\n\
	adds r2, r4, #0\n\
	adds r2, #0x45\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x1e\n\
	strb r0, [r1]\n\
	movs r1, #0xcc\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r3, _080C6714 @ =gStageRun+232\n\
	ldr r2, _080C6718 @ =sMissionLocation\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	ldr r0, _080C671C @ =0xFFFF8800\n\
	adds r1, r1, r0\n\
	ldr r0, [r3, #0x38]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	adds r2, #4\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	ldr r2, _080C6720 @ =0xFFFFB000\n\
	adds r1, r1, r2\n\
	ldr r0, [r3, #0x3c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	strb r5, [r4, #0x12]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
_080C66A2:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080C6724 @ =gOverworld\n\
	ldr r3, _080C6728 @ =0x0002D025\n\
	adds r0, r0, r3\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	bne _080C6734\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x41\n\
	bne _080C66CC\n\
	strb r2, [r4, #0x12]\n\
_080C66CC:\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r2, #0x20\n\
	bls _080C66E0\n\
	ldrb r1, [r4, #0x12]\n\
	subs r1, #0x20\n\
	asrs r1, r1, #1\n\
	movs r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
_080C66E0:\n\
	ldr r1, _080C672C @ =gBlendRegBuffer\n\
	movs r0, #0x1f\n\
	ands r6, r0\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	adds r0, r3, #0\n\
	orrs r6, r0\n\
	strh r6, [r1, #2]\n\
	ldr r1, _080C6730 @ =gSineTable\n\
	movs r0, #0x40\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	asrs r1, r1, #1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	b _080C673C\n\
	.align 2, 0\n\
_080C6714: .4byte gStageRun+232\n\
_080C6718: .4byte sMissionLocation\n\
_080C671C: .4byte 0xFFFF8800\n\
_080C6720: .4byte 0xFFFFB000\n\
_080C6724: .4byte gOverworld\n\
_080C6728: .4byte 0x0002D025\n\
_080C672C: .4byte gBlendRegBuffer\n\
_080C6730: .4byte gSineTable\n\
_080C6734:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
_080C673C:\n\
	adds r0, r4, #0\n\
	adds r0, #0x50\n\
	strh r7, [r0]\n\
	adds r0, #2\n\
	strh r7, [r0]\n\
	ldr r0, [r4, #0x28]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _080C676C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080C6774 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
_080C676C:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C6774: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void FUN_080c6778(struct VFX* g) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _080C67AC @ =gCurStory\n\
	ldrb r1, [r2, #5]\n\
	movs r3, #2\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C67B4\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C67B0 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	b _080C6862\n\
	.align 2, 0\n\
_080C67AC: .4byte gCurStory\n\
_080C67B0: .4byte gVFXFnTable\n\
_080C67B4:\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C67C2\n\
	movs r1, #4\n\
	movs r0, #0\n\
	b _080C67FC\n\
_080C67C2:\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C6864\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C67D8\n\
	movs r1, #3\n\
	movs r0, #4\n\
	b _080C67FC\n\
_080C67D8:\n\
	ldrb r1, [r2, #6]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C67E8\n\
	movs r1, #1\n\
	movs r0, #7\n\
	b _080C67FC\n\
_080C67E8:\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C6864\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C6864\n\
	movs r1, #4\n\
	movs r0, #8\n\
_080C67FC:\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r0, r0, r1\n\
	cmp r4, r0\n\
	bge _080C6852\n\
	movs r6, #0\n\
	ldr r1, _080C6870 @ =gVFXFnTable+(71*4)\n\
	mov r8, r1\n\
	adds r7, r0, #0\n\
_080C6810:\n\
	ldr r0, _080C6874 @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _080C6842\n\
	adds r2, r1, #0\n\
	adds r2, #0x25\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	movs r0, #0x47\n\
	strb r0, [r1, #9]\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	ldr r0, [r0]\n\
	str r0, [r1, #0x14]\n\
	strh r6, [r1, #0x20]\n\
	adds r0, r1, #0\n\
	adds r0, #0x22\n\
	strb r6, [r0]\n\
	movs r0, #3\n\
	strb r0, [r1, #0x10]\n\
	strb r4, [r1, #0x11]\n\
	str r5, [r1, #0x28]\n\
_080C6842:\n\
	lsls r0, r4, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r0, r1\n\
	lsrs r4, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r7\n\
	blt _080C6810\n\
_080C6852:\n\
	ldr r1, _080C6878 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
_080C6862:\n\
	str r0, [r5, #0x14]\n\
_080C6864:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C6870: .4byte gVFXFnTable+(71*4)\n\
_080C6874: .4byte gVFXHeaderPtr\n\
_080C6878: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void nop_080c687c(struct VFX* p) { return; }

// --------------------------------------------

// clang-format off
const struct Coord sMissionLocation[12] = {
  {0x5300, 0x2F00},
  {0x8400, 0x3800},
  {0x7D00, 0x2D00},
  {0x8800, 0x2400},
  {0x6500, 0x3A00},
  {0x9C00, 0x2E00},
  {0x7E00, 0x1B00},
  {0x9900, 0x2600},
  {0x5B00, 0x2100},
  {0x6B00, 0x1C00},
  {0x6D00, 0x3100},
  {0x9900, 0x2600},
};
// clang-format on

const u8 MissionBitfields_0836f81c[12] = {
    2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14,
};
