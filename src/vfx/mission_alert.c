#include "blink.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "task.h"
#include "vfx.h"

extern const struct Graphic gGraphic_GAMEOVER;
extern const struct Palette gPalette_GAMEOVER;
extern const struct Graphic gGraphic_MissionStart;
extern const struct Palette gPalette_MissionStart;

// work[0]
#define MISSION_START 0
#define MISSION_FAILED 1
#define MISSION_COMPLETED 2
#define WARNING 3
#define GAME_OVER 4

static const u8 u8_ARRAY_0836e810[3];

static void MissionAlert_Init(struct VFX* p);
static void MissionAlert_Update(struct VFX* p);
static void MissionAlert_Die(struct VFX* p);

// clang-format off
const VFXRoutine gMissionAlertRoutine = {
    [ENTITY_INIT] =      MissionAlert_Init,
    [ENTITY_MAIN] =      MissionAlert_Update,
    [ENTITY_DIE] =       MissionAlert_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

struct VFX* CreateMissionAlert(u8 kind) {
  struct VFX* g = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_MISSION_ALERT);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).work[0] = kind;
    (g->s).work[1] = 0;
  } else {
    return NULL;
  }
  return g;
}

// --------------------------------------------

static void initMissionXXX(struct VFX* p);
static void initWarning(struct VFX* p);
static void initGameOver(struct VFX* p);

static void MissionAlert_Init(struct VFX* p) {
  // clang-format off
  static VFXFunc const sInitializers[] = {
      [MISSION_START] =     initMissionXXX,
      [MISSION_FAILED] =    initMissionXXX,
      [MISSION_COMPLETED] = initMissionXXX,
      [WARNING] =           initWarning,
      [GAME_OVER] =         initGameOver,
  };
  // clang-format on

  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

static void updateMissionXXX(struct VFX* p);
static void updateWarning(struct VFX* p);
static void updateGameOver(struct VFX* p);

static void MissionAlert_Update(struct VFX* p) {
  // clang-format off
  static VFXFunc const sUpdates[] = {
      [MISSION_START] =     updateMissionXXX,
      [MISSION_FAILED] =    updateMissionXXX,
      [MISSION_COMPLETED] = updateMissionXXX,
      [WARNING] =           updateWarning,
      [GAME_OVER] =         updateGameOver,
  };
  // clang-format on

  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

static void MissionAlert_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void TaskCB_Unk080b5890(struct Sprite* p, struct DrawPivot* _ UNUSED);

static void initMissionXXX(struct VFX* p) {
  SetTaskCallback((struct Task*)&(p->s).spr, TaskCB_Unk080b5890);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~OAM_PRIO;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).work[2] = 0;
  (p->s).d.y = 0;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  MissionAlert_Update(p);
}

static void updateMissionXXX(struct VFX* vfx) {
  switch ((vfx->s).mode[2]) {
    case 0: {
      (vfx->s).work[2]++;
      if ((vfx->s).work[2] == 39) {
        LoadBlink(u8_ARRAY_0836e810[(vfx->s).work[0]], 32);
        (vfx->s).work[2] = 38;
        (vfx->s).mode[2]++;
      }
      break;
    }

    case 1: {
      UpdateBlinkMotionState(u8_ARRAY_0836e810[(vfx->s).work[0]]);
      (vfx->s).work[2]--;
      if ((vfx->s).work[2] == 0xFF) {
        if ((vfx->s).work[0] != 0) {
          PlaySound(MUS_DUMMY);
        }
        (vfx->s).work[2] = 24;
        (vfx->s).mode[2]++;
      }
      break;
    }

    case 2: {
      UpdateBlinkMotionState(u8_ARRAY_0836e810[(vfx->s).work[0]]);
      (vfx->s).work[2]--;
      if ((vfx->s).work[2] == 0xFF) {
        (vfx->s).mode[2]++;
        (vfx->s).work[2] = 0;
      }
      break;
    }

    case 3: {
      UpdateBlinkMotionState(u8_ARRAY_0836e810[(vfx->s).work[0]]);
      (vfx->s).work[2]++;
      if ((vfx->s).work[2] == 33) {
        ClearBlink(u8_ARRAY_0836e810[(vfx->s).work[0]]);
        SET_VFX_ROUTINE(vfx, ENTITY_DIE);
        MissionAlert_Die(vfx);
      }
      break;
    }
  }
}

NAKED static void TaskCB_Unk080b5890(struct Sprite* p, struct DrawPivot* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0x24\n\
	ldr r0, [r0, #8]\n\
	mov r8, r0\n\
	ldr r4, _080B5918 @ =gGameState+16\n\
	ldr r1, _080B591C @ =u8_ARRAY_080ff0a8\n\
	mov r0, sp\n\
	movs r2, #0x1a\n\
	bl memcpy\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #1\n\
	bls _080B58B2\n\
	b _080B5AA0\n\
_080B58B2:\n\
	ldrb r0, [r1, #0xf]\n\
	cmp r0, #0\n\
	bne _080B5938\n\
	ldr r4, _080B5920 @ =gVideoRegBuffer\n\
	ldrh r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r2, _080B5924 @ =0x12001200\n\
	ldrh r0, [r4, #4]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r0\n\
	lsls r1, r1, #3\n\
	ldr r0, _080B5928 @ =0x06000800\n\
	adds r1, r1, r0\n\
	str r2, [sp, #0x1c]\n\
	add r0, sp, #0x1c\n\
	ldr r2, _080B592C @ =0x01000200\n\
	bl CpuFastSet\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xf]\n\
	ldrb r1, [r1, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r2, _080B5930 @ =gGraphic_MissionStart\n\
	adds r0, r0, r2\n\
	ldrh r2, [r4, #4]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	mov r0, r8\n\
	ldrb r1, [r0, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080B5934 @ =gPalette_MissionStart\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	b _080B594E\n\
	.align 2, 0\n\
_080B5918: .4byte gGameState+16\n\
_080B591C: .4byte u8_ARRAY_080ff0a8\n\
_080B5920: .4byte gVideoRegBuffer\n\
_080B5924: .4byte 0x12001200\n\
_080B5928: .4byte 0x06000800\n\
_080B592C: .4byte 0x01000200\n\
_080B5930: .4byte gGraphic_MissionStart\n\
_080B5934: .4byte gPalette_MissionStart\n\
_080B5938:\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x10]\n\
	lsls r0, r0, #8\n\
	ldr r1, _080B5964 @ =0x0836DCC0\n\
	adds r0, r0, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	movs r2, #0x40\n\
	bl CpuFastSet\n\
_080B594E:\n\
	mov r0, r8\n\
	ldrb r4, [r0, #0xe]\n\
	cmp r4, #1\n\
	bne _080B5958\n\
	b _080B5A98\n\
_080B5958:\n\
	cmp r4, #1\n\
	bgt _080B5968\n\
	cmp r4, #0\n\
	beq _080B5972\n\
	b _080B5A98\n\
	.align 2, 0\n\
_080B5964: .4byte 0x0836DCC0\n\
_080B5968:\n\
	cmp r4, #2\n\
	beq _080B59E2\n\
	cmp r4, #3\n\
	beq _080B5A20\n\
	b _080B5A98\n\
_080B5972:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #1\n\
	bl Malloc\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	bne _080B5982\n\
	b _080B5A98\n\
_080B5982:\n\
	str r4, [sp, #0x20]\n\
	add r0, sp, #0x20\n\
	ldr r2, _080B59A8 @ =0x01000050\n\
	adds r1, r7, #0\n\
	bl CpuFastSet\n\
	movs r5, #0\n\
	adds r3, r7, #0\n\
	adds r3, #0x80\n\
_080B5994:\n\
	mov r2, sp\n\
	adds r1, r2, r5\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x12]\n\
	ldrb r2, [r1]\n\
	cmp r0, r2\n\
	bhs _080B59AC\n\
	movs r4, #0xff\n\
	b _080B59D6\n\
	.align 2, 0\n\
_080B59A8: .4byte 0x01000050\n\
_080B59AC:\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x12]\n\
	ldrb r2, [r1]\n\
	subs r0, r0, r2\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #3\n\
	movs r0, #0xff\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r0, #0\n\
	bge _080B59C8\n\
	movs r4, #0\n\
_080B59C8:\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080B59D6\n\
	lsls r0, r4, #0x10\n\
	rsbs r0, r0, #0\n\
	lsrs r4, r0, #0x10\n\
_080B59D6:\n\
	strh r4, [r3]\n\
	adds r3, #2\n\
	adds r5, #1\n\
	cmp r5, #0x19\n\
	ble _080B5994\n\
	b _080B5A7A\n\
_080B59E2:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #1\n\
	bl Malloc\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	beq _080B5A98\n\
	movs r0, #0\n\
	str r0, [sp, #0x20]\n\
	add r0, sp, #0x20\n\
	ldr r2, _080B5A1C @ =0x01000050\n\
	adds r1, r7, #0\n\
	bl CpuFastSet\n\
	movs r5, #0\n\
	adds r4, r7, #0\n\
	adds r4, #0x80\n\
_080B5A04:\n\
	adds r0, r5, #0\n\
	movs r1, #3\n\
	bl __divsi3\n\
	subs r0, #4\n\
	strh r0, [r4]\n\
	adds r4, #2\n\
	adds r5, #1\n\
	cmp r5, #0x19\n\
	ble _080B5A04\n\
	b _080B5A7A\n\
	.align 2, 0\n\
_080B5A1C: .4byte 0x01000050\n\
_080B5A20:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #1\n\
	bl Malloc\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	beq _080B5A98\n\
	movs r0, #0\n\
	str r0, [sp, #0x20]\n\
	add r0, sp, #0x20\n\
	ldr r2, _080B5AAC @ =0x01000050\n\
	adds r1, r7, #0\n\
	bl CpuFastSet\n\
	movs r5, #0\n\
	adds r6, r7, #0\n\
	adds r6, #0x80\n\
_080B5A42:\n\
	mov r2, r8\n\
	ldrb r1, [r2, #0x12]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #2\n\
	cmp r4, #0xff\n\
	ble _080B5A52\n\
	movs r4, #0xff\n\
_080B5A52:\n\
	movs r0, #1\n\
	ands r0, r5\n\
	cmp r0, #0\n\
	bne _080B5A60\n\
	lsls r0, r4, #0x10\n\
	rsbs r0, r0, #0\n\
	lsrs r4, r0, #0x10\n\
_080B5A60:\n\
	adds r0, r5, #0\n\
	movs r1, #3\n\
	bl __divsi3\n\
	lsls r1, r4, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r1, r1, r0\n\
	subs r1, #4\n\
	strh r1, [r6]\n\
	adds r6, #2\n\
	adds r5, #1\n\
	cmp r5, #0x19\n\
	ble _080B5A42\n\
_080B5A7A:\n\
	ldr r2, _080B5AB0 @ =gIntrManager\n\
	movs r1, #0xc8\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	str r7, [r0]\n\
	movs r0, #0xca\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _080B5AB4 @ =0x04000010\n\
	str r0, [r1]\n\
	movs r0, #0xcc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _080B5AB8 @ =0xA2600001\n\
	str r0, [r1]\n\
_080B5A98:\n\
	ldr r1, _080B5ABC @ =gVideoRegBuffer+12\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	strh r0, [r1, #2]\n\
_080B5AA0:\n\
	add sp, #0x24\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B5AAC: .4byte 0x01000050\n\
_080B5AB0: .4byte gIntrManager\n\
_080B5AB4: .4byte 0x04000010\n\
_080B5AB8: .4byte 0xA2600001\n\
_080B5ABC: .4byte gVideoRegBuffer+12\n\
 .syntax divided\n");
}

// --------------------------------------------

static void TaskCB_Unk080b5b90(struct Sprite* p, struct DrawPivot* _ UNUSED);

static void initWarning(struct VFX* p) {
  SetTaskCallback((struct Task*)&(p->s).spr, TaskCB_Unk080b5b90);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~OAM_PRIO;
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).work[2] = 0;
  (p->s).d.y = 0;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[2] = 0;
  MissionAlert_Update(p);
}

NAKED static void updateWarning(struct VFX* p) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x12]\n\
	ldrb r0, [r2, #0xe]\n\
	cmp r0, #4\n\
	bhi _080B5B88\n\
	lsls r0, r0, #2\n\
	ldr r1, _080B5B28 @ =_080B5B2C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080B5B28: .4byte _080B5B2C\n\
_080B5B2C: @ jump table\n\
	.4byte _080B5B50 @ case 0\n\
	.4byte _080B5B40 @ case 1\n\
	.4byte _080B5B48 @ case 2\n\
	.4byte _080B5B50 @ case 3\n\
	.4byte _080B5B62 @ case 4\n\
_080B5B40:\n\
	ldrb r0, [r2, #0x12]\n\
	cmp r0, #0x19\n\
	bls _080B5B88\n\
	b _080B5B56\n\
_080B5B48:\n\
	ldrb r0, [r2, #0x12]\n\
	cmp r0, #0x3f\n\
	bls _080B5B88\n\
	b _080B5B56\n\
_080B5B50:\n\
	ldrb r0, [r2, #0x12]\n\
	cmp r0, #0x1b\n\
	bls _080B5B88\n\
_080B5B56:\n\
	ldrb r0, [r2, #0xe]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r2, #0xe]\n\
	strb r1, [r2, #0x12]\n\
	b _080B5B88\n\
_080B5B62:\n\
	ldrb r0, [r2, #0x12]\n\
	cmp r0, #0x19\n\
	bls _080B5B88\n\
	ldr r1, _080B5B8C @ =gVFXFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldrb r0, [r2, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xe]\n\
_080B5B88:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B5B8C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void TaskCB_Unk080b5b90(struct Sprite* p, struct DrawPivot* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x2c\n\
	ldr r7, [r0, #8]\n\
	ldrb r0, [r7, #0xc]\n\
	cmp r0, #1\n\
	bls _080B5BA6\n\
	b _080B607C\n\
_080B5BA6:\n\
	ldrb r0, [r7, #0xf]\n\
	cmp r0, #0\n\
	bne _080B5BEA\n\
	ldr r2, _080B5BFC @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrb r1, [r7, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r4, _080B5C00 @ =gGraphic_MissionStart\n\
	adds r0, r0, r4\n\
	ldrh r2, [r2, #4]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldrb r1, [r7, #0x10]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r6, _080B5C04 @ =gPalette_MissionStart\n\
	adds r0, r0, r6\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r7, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xf]\n\
_080B5BEA:\n\
	ldrb r0, [r7, #0xe]\n\
	cmp r0, #5\n\
	bls _080B5BF2\n\
	b _080B607C\n\
_080B5BF2:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080B5C08 @ =_080B5C0C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080B5BFC: .4byte gVideoRegBuffer\n\
_080B5C00: .4byte gGraphic_MissionStart\n\
_080B5C04: .4byte gPalette_MissionStart\n\
_080B5C08: .4byte _080B5C0C\n\
_080B5C0C: @ jump table\n\
	.4byte _080B5C24 @ case 0\n\
	.4byte _080B5CB8 @ case 1\n\
	.4byte _080B5DDC @ case 2\n\
	.4byte _080B5ED8 @ case 3\n\
	.4byte _080B5FE0 @ case 4\n\
	.4byte _080B607C @ case 5\n\
_080B5C24:\n\
	ldrb r0, [r7, #0x12]\n\
	ldr r1, _080B5CB0 @ =PTR_ARRAY_0836e42c\n\
	lsrs r0, r0, #2\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r1\n\
	ldr r1, [r1]\n\
	ldrb r7, [r1]\n\
	str r7, [sp]\n\
	ldrb r1, [r1, #1]\n\
	movs r2, #0\n\
	lsls r1, r1, #0x10\n\
	mov ip, r1\n\
	asrs r1, r1, #0x10\n\
	str r1, [sp, #0xc]\n\
	str r0, [sp, #4]\n\
_080B5C42:\n\
	movs r1, #0\n\
	mov sl, ip\n\
	lsls r5, r2, #0x10\n\
	ldr r2, [sp, #0xc]\n\
	cmp r1, r2\n\
	bge _080B5C9E\n\
	asrs r6, r5, #0x10\n\
	lsls r3, r6, #5\n\
	mov sb, r3\n\
	ldr r4, [sp]\n\
	mov r8, r4\n\
	ldr r0, _080B5CB0 @ =PTR_ARRAY_0836e42c\n\
	ldr r7, [sp, #4]\n\
	adds r0, r7, r0\n\
	ldr r0, [r0]\n\
	str r0, [sp, #0x24]\n\
_080B5C62:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	mov r0, sb\n\
	adds r3, r2, r0\n\
	add r3, r8\n\
	lsls r3, r3, #1\n\
	ldr r1, _080B5CB4 @ =gGameState+16\n\
	adds r3, r3, r1\n\
	movs r4, #0xe0\n\
	lsls r4, r4, #1\n\
	adds r3, r3, r4\n\
	mov r7, sl\n\
	asrs r4, r7, #0x10\n\
	adds r0, r6, #0\n\
	muls r0, r4, r0\n\
	adds r0, r2, r0\n\
	ldr r1, [sp, #0x24]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0, #2]\n\
	movs r7, #0x90\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r4\n\
	blt _080B5C62\n\
_080B5C9E:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	ble _080B5C42\n\
	b _080B607C\n\
	.align 2, 0\n\
_080B5CB0: .4byte PTR_ARRAY_0836e42c\n\
_080B5CB4: .4byte gGameState+16\n\
_080B5CB8:\n\
	ldr r0, _080B5DC8 @ =PTR_ARRAY_0836e42c\n\
	ldr r0, [r0, #0x18]\n\
	ldrb r2, [r0]\n\
	str r2, [sp]\n\
	ldrb r1, [r0, #1]\n\
	movs r2, #0\n\
	lsls r1, r1, #0x10\n\
	str r1, [sp, #0x10]\n\
	asrs r3, r1, #0x10\n\
	str r3, [sp, #0x14]\n\
_080B5CCC:\n\
	movs r1, #0\n\
	ldr r4, [sp, #0x10]\n\
	mov sl, r4\n\
	lsls r5, r2, #0x10\n\
	ldr r6, [sp, #0x14]\n\
	cmp r1, r6\n\
	bge _080B5D28\n\
	asrs r0, r5, #0x10\n\
	str r0, [sp, #0x28]\n\
	lsls r0, r0, #5\n\
	mov sb, r0\n\
	ldr r2, [sp]\n\
	mov r8, r2\n\
	ldr r0, _080B5DC8 @ =PTR_ARRAY_0836e42c\n\
	ldr r0, [r0, #0x18]\n\
	mov ip, r0\n\
_080B5CEC:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	mov r4, sb\n\
	adds r3, r2, r4\n\
	add r3, r8\n\
	lsls r3, r3, #1\n\
	ldr r6, _080B5DCC @ =gGameState+16\n\
	adds r3, r3, r6\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	adds r3, r3, r0\n\
	mov r1, sl\n\
	asrs r4, r1, #0x10\n\
	ldr r6, [sp, #0x28]\n\
	adds r0, r6, #0\n\
	muls r0, r4, r0\n\
	adds r0, r2, r0\n\
	add r0, ip\n\
	ldrb r0, [r0, #2]\n\
	movs r6, #0x90\n\
	lsls r6, r6, #5\n\
	adds r1, r6, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r4\n\
	blt _080B5CEC\n\
_080B5D28:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	ble _080B5CCC\n\
	movs r1, #0\n\
	ldr r6, _080B5DD0 @ =0x0836E460\n\
	movs r5, #0xd\n\
_080B5D3C:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r3, r2, #1\n\
	ldr r4, _080B5DCC @ =gGameState+16\n\
	adds r3, r3, r4\n\
	movs r0, #0xd1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	mov r8, r0\n\
	ldrb r0, [r7, #0x12]\n\
	muls r0, r5, r0\n\
	adds r0, r2, r0\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0]\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	movs r4, #0xe1\n\
	lsls r4, r4, #2\n\
	adds r4, r4, r3\n\
	mov r8, r4\n\
	ldrb r0, [r7, #0x12]\n\
	muls r0, r5, r0\n\
	adds r0, r2, r0\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0]\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	ldr r4, _080B5DD4 @ =0x0000035E\n\
	adds r4, r4, r3\n\
	mov r8, r4\n\
	ldrb r0, [r7, #0x12]\n\
	muls r0, r5, r0\n\
	adds r0, #0xc\n\
	subs r0, r0, r2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0]\n\
	movs r4, #0x90\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	ldr r4, _080B5DD8 @ =0x0000039E\n\
	adds r3, r3, r4\n\
	ldrb r0, [r7, #0x12]\n\
	muls r0, r5, r0\n\
	adds r0, #0xc\n\
	subs r0, r0, r2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0]\n\
	movs r4, #0xd0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #0xc\n\
	ble _080B5D3C\n\
	b _080B607C\n\
	.align 2, 0\n\
_080B5DC8: .4byte PTR_ARRAY_0836e42c\n\
_080B5DCC: .4byte gGameState+16\n\
_080B5DD0: .4byte 0x0836E460\n\
_080B5DD4: .4byte 0x0000035E\n\
_080B5DD8: .4byte 0x0000039E\n\
_080B5DDC:\n\
	ldr r0, _080B5EC4 @ =PTR_ARRAY_0836e42c\n\
	ldr r0, [r0, #0x18]\n\
	ldrb r6, [r0]\n\
	str r6, [sp]\n\
	ldrb r1, [r0, #1]\n\
	movs r2, #0\n\
	lsls r1, r1, #0x10\n\
	str r1, [sp, #0x18]\n\
	asrs r7, r1, #0x10\n\
	str r7, [sp, #0x1c]\n\
_080B5DF0:\n\
	movs r1, #0\n\
	ldr r0, [sp, #0x18]\n\
	mov sl, r0\n\
	lsls r5, r2, #0x10\n\
	ldr r2, [sp, #0x1c]\n\
	cmp r1, r2\n\
	bge _080B5E4C\n\
	asrs r6, r5, #0x10\n\
	lsls r3, r6, #5\n\
	mov sb, r3\n\
	ldr r4, [sp]\n\
	mov r8, r4\n\
	ldr r0, _080B5EC4 @ =PTR_ARRAY_0836e42c\n\
	ldr r0, [r0, #0x18]\n\
	str r0, [sp, #0x24]\n\
	movs r7, #0xe0\n\
	lsls r7, r7, #1\n\
	mov ip, r7\n\
_080B5E14:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	mov r0, sb\n\
	adds r3, r2, r0\n\
	add r3, r8\n\
	lsls r3, r3, #1\n\
	ldr r1, _080B5EC8 @ =gGameState+16\n\
	adds r3, r3, r1\n\
	add r3, ip\n\
	mov r7, sl\n\
	asrs r4, r7, #0x10\n\
	adds r0, r6, #0\n\
	muls r0, r4, r0\n\
	adds r0, r2, r0\n\
	ldr r1, [sp, #0x24]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0, #2]\n\
	movs r7, #0x90\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r4\n\
	blt _080B5E14\n\
_080B5E4C:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	ble _080B5DF0\n\
	movs r1, #0\n\
	ldr r6, _080B5ECC @ =0x0836E5A5\n\
_080B5E5E:\n\
	lsls r3, r1, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r4, r3, #1\n\
	ldr r2, _080B5EC8 @ =gGameState+16\n\
	adds r4, r4, r2\n\
	movs r7, #0xd1\n\
	lsls r7, r7, #2\n\
	adds r5, r4, r7\n\
	adds r2, r3, r6\n\
	ldrb r0, [r2]\n\
	movs r7, #0xb0\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #2\n\
	adds r5, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #5\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	ldr r7, _080B5ED0 @ =0x0000035E\n\
	adds r5, r4, r7\n\
	movs r2, #0xc\n\
	subs r2, r2, r3\n\
	adds r2, r2, r6\n\
	ldrb r0, [r2]\n\
	movs r7, #0x90\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	ldr r0, _080B5ED4 @ =0x0000039E\n\
	adds r4, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #5\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r1, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #0xc\n\
	ble _080B5E5E\n\
	b _080B607C\n\
	.align 2, 0\n\
_080B5EC4: .4byte PTR_ARRAY_0836e42c\n\
_080B5EC8: .4byte gGameState+16\n\
_080B5ECC: .4byte 0x0836E5A5\n\
_080B5ED0: .4byte 0x0000035E\n\
_080B5ED4: .4byte 0x0000039E\n\
_080B5ED8:\n\
	ldrb r0, [r7, #0x12]\n\
	ldr r1, _080B5FCC @ =PTR_ARRAY_0836e42c\n\
	lsrs r0, r0, #2\n\
	adds r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r1\n\
	ldr r1, [r1]\n\
	ldrb r3, [r1]\n\
	str r3, [sp]\n\
	ldrb r1, [r1, #1]\n\
	movs r2, #0\n\
	lsls r1, r1, #0x10\n\
	mov ip, r1\n\
	mov r4, ip\n\
	asrs r4, r4, #0x10\n\
	str r4, [sp, #0x20]\n\
	str r0, [sp, #8]\n\
_080B5EFA:\n\
	movs r1, #0\n\
	mov sl, ip\n\
	lsls r5, r2, #0x10\n\
	ldr r6, [sp, #0x20]\n\
	cmp r1, r6\n\
	bge _080B5F56\n\
	asrs r6, r5, #0x10\n\
	lsls r7, r6, #5\n\
	mov sb, r7\n\
	ldr r0, [sp]\n\
	mov r8, r0\n\
	ldr r0, _080B5FCC @ =PTR_ARRAY_0836e42c\n\
	ldr r2, [sp, #8]\n\
	adds r0, r2, r0\n\
	ldr r0, [r0]\n\
	str r0, [sp, #0x24]\n\
_080B5F1A:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	mov r4, sb\n\
	adds r3, r2, r4\n\
	add r3, r8\n\
	lsls r3, r3, #1\n\
	ldr r7, _080B5FD0 @ =gGameState+16\n\
	adds r3, r3, r7\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	adds r3, r3, r0\n\
	mov r1, sl\n\
	asrs r4, r1, #0x10\n\
	adds r0, r6, #0\n\
	muls r0, r4, r0\n\
	adds r0, r2, r0\n\
	ldr r7, [sp, #0x24]\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0, #2]\n\
	movs r7, #0x90\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, r4\n\
	blt _080B5F1A\n\
_080B5F56:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	ble _080B5EFA\n\
	movs r1, #0\n\
	ldr r6, _080B5FD4 @ =0x0836E5A5\n\
_080B5F68:\n\
	lsls r3, r1, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r4, r3, #1\n\
	ldr r2, _080B5FD0 @ =gGameState+16\n\
	adds r4, r4, r2\n\
	movs r7, #0xd1\n\
	lsls r7, r7, #2\n\
	adds r5, r4, r7\n\
	adds r2, r3, r6\n\
	ldrb r0, [r2]\n\
	movs r7, #0xb0\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #2\n\
	adds r5, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r2, #0xf0\n\
	lsls r2, r2, #5\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	ldr r7, _080B5FD8 @ =0x0000035E\n\
	adds r5, r4, r7\n\
	movs r2, #0xc\n\
	subs r2, r2, r3\n\
	adds r2, r2, r6\n\
	ldrb r0, [r2]\n\
	movs r7, #0x90\n\
	lsls r7, r7, #5\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	ldr r0, _080B5FDC @ =0x0000039E\n\
	adds r4, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #5\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r1, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #0xc\n\
	ble _080B5F68\n\
	b _080B607C\n\
	.align 2, 0\n\
_080B5FCC: .4byte PTR_ARRAY_0836e42c\n\
_080B5FD0: .4byte gGameState+16\n\
_080B5FD4: .4byte 0x0836E5A5\n\
_080B5FD8: .4byte 0x0000035E\n\
_080B5FDC: .4byte 0x0000039E\n\
_080B5FE0:\n\
	movs r1, #0\n\
	ldr r3, _080B608C @ =0x0836E460\n\
	mov r8, r3\n\
	movs r6, #0x19\n\
	movs r5, #0xd\n\
_080B5FEA:\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x10\n\
	lsls r3, r2, #1\n\
	ldr r4, _080B6090 @ =gGameState+16\n\
	adds r3, r3, r4\n\
	movs r0, #0xd1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	mov sb, r0\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, r6, r0\n\
	muls r0, r5, r0\n\
	adds r0, r2, r0\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, sb\n\
	strh r0, [r1]\n\
	movs r4, #0xe1\n\
	lsls r4, r4, #2\n\
	adds r4, r4, r3\n\
	mov sb, r4\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, r6, r0\n\
	muls r0, r5, r0\n\
	adds r0, r2, r0\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, sb\n\
	strh r0, [r1]\n\
	ldr r4, _080B6094 @ =0x0000035E\n\
	adds r4, r4, r3\n\
	mov sb, r4\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, r6, r0\n\
	muls r0, r5, r0\n\
	adds r0, #0xc\n\
	subs r0, r0, r2\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r4, #0x90\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	mov r1, sb\n\
	strh r0, [r1]\n\
	ldr r4, _080B6098 @ =0x0000039E\n\
	adds r3, r3, r4\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, r6, r0\n\
	muls r0, r5, r0\n\
	adds r0, #0xc\n\
	subs r0, r0, r2\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r4, #0xd0\n\
	lsls r4, r4, #5\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r1, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #0xc\n\
	ble _080B5FEA\n\
_080B607C:\n\
	add sp, #0x2c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B608C: .4byte 0x0836E460\n\
_080B6090: .4byte gGameState+16\n\
_080B6094: .4byte 0x0000035E\n\
_080B6098: .4byte 0x0000039E\n\
 .syntax divided\n");
}

// --------------------------------------------

static void updateGameOverTile(struct Sprite* p, struct DrawPivot* _ UNUSED);

static void initGameOver(struct VFX* p) {
  SetTaskCallback((struct Task*)&(p->s).spr, updateGameOverTile);
  (p->s).spr.sprites = (struct MetaspriteHeader*)p;
  (p->s).flags &= ~(1 << 3);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  (p->s).work[2] = 0;
  SET_VFX_ROUTINE(p, ENTITY_MAIN);
  (p->s).mode[2] = 0;
  MissionAlert_Update(p);
}

static void updateGameOver(struct VFX* p) {
  (p->s).work[2]++;

  if ((p->s).mode[1] == 0) {
    if (123 < (p->s).work[2]) {
      (p->s).mode[1]++;
      (p->s).work[2] = 0;
    }
  } else if ((p->s).mode[1] == 1) {
    if (20 < (p->s).work[2]) {
      (p->s).mode[1]++;
      (p->s).work[2] = 0;
    }
  } else if ((p->s).mode[1] == 2) {
    if (32 < (p->s).work[2]) {
      SET_VFX_ROUTINE(p, ENTITY_DIE);
      MissionAlert_Die(p);
    }
  }
}

NAKED static void updateGameOverTile(struct Sprite* p, struct DrawPivot* _ UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r4, [r0, #8]\n\
	ldr r0, _080B6204 @ =gGameState+16\n\
	mov r8, r0\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #1\n\
	bls _080B6160\n\
	b _080B62C8\n\
_080B6160:\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _080B6190\n\
	ldr r1, _080B6208 @ =gVideoRegBuffer\n\
	ldrh r2, [r1]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r0, r3, #0\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldr r0, _080B620C @ =gGraphic_GAMEOVER\n\
	ldrh r2, [r1, #4]\n\
	movs r1, #0xc\n\
	ands r1, r2\n\
	lsls r1, r1, #0xc\n\
	bl LoadGraphic\n\
	ldr r0, _080B6210 @ =gPalette_GAMEOVER\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
_080B6190:\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	bne _080B6218\n\
	ldrb r0, [r4, #0x12]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	ble _080B61A8\n\
	movs r0, #9\n\
_080B61A8:\n\
	ldr r1, _080B6214 @ =0x0836E7B8\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldrb r3, [r0]\n\
	ldrb r1, [r0, #1]\n\
	movs r2, #0\n\
	lsls r7, r1, #0x10\n\
	cmp r2, r1\n\
	blt _080B61BE\n\
	b _080B62C8\n\
_080B61BE:\n\
	adds r6, r3, #0\n\
	adds r4, r0, #0\n\
	movs r0, #0x90\n\
	lsls r0, r0, #5\n\
	adds r5, r0, #0\n\
_080B61C8:\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r6, r1\n\
	lsls r0, r0, #1\n\
	mov r2, r8\n\
	adds r3, r0, r2\n\
	movs r0, #0x90\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0, #2]\n\
	orrs r0, r5\n\
	strh r0, [r2]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	asrs r3, r7, #0x10\n\
	adds r0, r1, r3\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0, #2]\n\
	orrs r0, r5\n\
	strh r0, [r2]\n\
	adds r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r2, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, r3\n\
	blt _080B61C8\n\
	b _080B62C8\n\
	.align 2, 0\n\
_080B6204: .4byte gGameState+16\n\
_080B6208: .4byte gVideoRegBuffer\n\
_080B620C: .4byte gGraphic_GAMEOVER\n\
_080B6210: .4byte gPalette_GAMEOVER\n\
_080B6214: .4byte 0x0836E7B8\n\
_080B6218:\n\
	cmp r0, #1\n\
	bne _080B62C8\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r1, r0, #0x18\n\
	lsrs r0, r1, #0x18\n\
	cmp r0, #9\n\
	bhi _080B628C\n\
	lsrs r0, r1, #0x19\n\
	cmp r0, #5\n\
	ble _080B622E\n\
	movs r0, #5\n\
_080B622E:\n\
	ldr r1, _080B6288 @ =0x0836E7E0\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldrb r3, [r0]\n\
	ldrb r1, [r0, #1]\n\
	movs r2, #0\n\
	lsls r7, r1, #0x10\n\
	cmp r2, r1\n\
	bge _080B62C8\n\
	adds r6, r3, #0\n\
	adds r4, r0, #0\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	adds r5, r3, #0\n\
_080B624C:\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r6, r1\n\
	lsls r0, r0, #1\n\
	mov r2, r8\n\
	adds r3, r0, r2\n\
	movs r0, #0x90\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0, #2]\n\
	orrs r0, r5\n\
	strh r0, [r2]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	asrs r3, r7, #0x10\n\
	adds r0, r1, r3\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0, #2]\n\
	orrs r0, r5\n\
	strh r0, [r2]\n\
	adds r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r2, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, r3\n\
	blt _080B624C\n\
	b _080B62C8\n\
	.align 2, 0\n\
_080B6288: .4byte 0x0836E7E0\n\
_080B628C:\n\
	lsrs r0, r1, #0x19\n\
	cmp r0, #0xa\n\
	ble _080B6294\n\
	movs r0, #0xa\n\
_080B6294:\n\
	movs r2, #0\n\
	movs r5, #0x90\n\
	lsls r5, r5, #2\n\
	ldr r1, _080B62D4 @ =0x0836E7F4\n\
	subs r0, #4\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r3, [r0]\n\
	movs r0, #0x90\n\
	lsls r0, r0, #5\n\
	adds r4, r0, #0\n\
_080B62AA:\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r2, r1, #1\n\
	add r2, r8\n\
	adds r2, r2, r5\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	orrs r0, r4\n\
	strh r0, [r2]\n\
	adds r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r2, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, #0x1f\n\
	ble _080B62AA\n\
_080B62C8:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B62D4: .4byte 0x0836E7F4\n\
 .syntax divided\n");
}

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
const tile_id_t u16_ARRAY_ARRAY_0836dcc0[3][128] = {
  { 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208, 0x1209, 0x120A, 0x120B, 0x120C, 0x120D, 0x120E, 0x120F, 0x1210, 0x1211, 0x1212, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1213, 0x1214, 0x1215, 0x1216, 0x1217, 0x1218, 0x1213, 0x1213, 0x1219, 0x121A, 0x121B, 0x121C, 0x1215, 0x121D, 0x121E, 0x121F, 0x1213, 0x1220, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1221, 0x1222, 0x1223, 0x1224, 0x1225, 0x1226, 0x1227, 0x1228, 0x1229, 0x122A, 0x122B, 0x122C, 0x122D, 0x122E, 0x122F, 0x1230, 0x1231, 0x1232, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1233, 0x1234, 0x1234, 0x1234, 0x1234, 0x1234, 0x1234, 0x1234, 0x1234, 0x1234, 0x1235, 0x1234, 0x1236, 0x1236, 0x1234, 0x1234, 0x1237, 0x1238, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200 },
  { 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208, 0x1209, 0x120A, 0x120B, 0x120C, 0x120D, 0x120E, 0x120F, 0x1210, 0x1211, 0x1208, 0x1212, 0x1213, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1214, 0x1215, 0x1216, 0x1217, 0x1218, 0x1219, 0x1214, 0x1214, 0x121A, 0x121B, 0x121C, 0x121D, 0x121E, 0x121F, 0x1220, 0x1221, 0x1222, 0x1223, 0x121A, 0x1224, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1225, 0x1226, 0x1227, 0x1228, 0x1229, 0x122A, 0x122B, 0x122C, 0x122D, 0x122E, 0x122F, 0x1230, 0x1231, 0x1232, 0x1233, 0x1234, 0x1235, 0x1236, 0x1237, 0x1238, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1239, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123B, 0x123C, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123A, 0x123D, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200 },
  { 0x1200, 0x1200, 0x1200, 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208, 0x1209, 0x120A, 0x120B, 0x120C, 0x120D, 0x120E, 0x120F, 0x1210, 0x1211, 0x1212, 0x1213, 0x1214, 0x1215, 0x1216, 0x1217, 0x1218, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1219, 0x121A, 0x121B, 0x121C, 0x121D, 0x121E, 0x1219, 0x1219, 0x121F, 0x1220, 0x1221, 0x1222, 0x1223, 0x1224, 0x1225, 0x1226, 0x1224, 0x1227, 0x1228, 0x1219, 0x1219, 0x1229, 0x1220, 0x122A, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x122B, 0x122C, 0x122D, 0x122E, 0x122F, 0x1230, 0x1231, 0x1232, 0x1233, 0x1234, 0x1235, 0x1236, 0x1237, 0x1238, 0x1239, 0x123A, 0x123B, 0x123C, 0x123D, 0x123E, 0x123E, 0x123F, 0x1240, 0x1241, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200, 0x1242, 0x1243, 0x1243, 0x1243, 0x1243, 0x1243, 0x1243, 0x1243, 0x1243, 0x1243, 0x1244, 0x1243, 0x1243, 0x1243, 0x1243, 0x1245, 0x1246, 0x1243, 0x1243, 0x1247, 0x1247, 0x1243, 0x1248, 0x1249, 0x1200, 0x1200, 0x1200, 0x1200, 0x1200 },
};
// clang-format on

// --------------------------------------------

const u8 u8_ARRAY_0836dfc0[32] = {
    0x02, 0x05, 0x02, 0x03, 0x04, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x13, 0x02, 0x01, 0x01, 0x01, 0x13,
};

const u8 u8_ARRAY_0836dfe0[50] = {
    0x02, 0x08, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06,
};

const u8 u8_ARRAY_0836e012[74] = {
    0x02, 0x0C, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x14, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x13, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x13, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x13,
};

const u8 u8_ARRAY_0836e05c[98] = {
    0x02, 0x10, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e0be[110] = {
    0x02, 0x12, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B,
};

const u8 u8_ARRAY_0836e12c[134] = {
    0x02, 0x16, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01,
};

const u8 u8_ARRAY_0836e1b2[158] = {
    0x02, 0x1A, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x02, 0x03, 0x04, 0x01, 0x05, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e250[134] = {
    0x06, 0x16, 0x19, 0x01, 0x01, 0x06, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x19, 0x01, 0x0C, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x19, 0x01, 0x10, 0x06, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x01, 0x06, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x0C, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x10, 0x06, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e2d6[110] = {
    0x0A, 0x12, 0x07, 0x01, 0x01, 0x05, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x07, 0x01, 0x11, 0x12, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x0D, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x04, 0x01, 0x05, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e344[92] = {
    0x0D, 0x0F, 0x19, 0x01, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x19, 0x01, 0x0C, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x19, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x10, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x19, 0x01, 0x10, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e3a0[62] = {
    0x12, 0x0A, 0x0A, 0x0B, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x0A, 0x0B, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x0A, 0x0B, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e3de[50] = {
    0x14, 0x08, 0x07, 0x01, 0x0B, 0x02, 0x03, 0x01, 0x01, 0x09, 0x07, 0x0D, 0x0B, 0x02, 0x03, 0x01, 0x0E, 0x0F, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x04, 0x0B, 0x02, 0x03, 0x01, 0x08, 0x09, 0x07, 0x04, 0x01, 0x01, 0x03, 0x01, 0x01, 0x09,
};

const u8 u8_ARRAY_0836e410[28] = {
    0x18, 0x04, 0x16, 0x01, 0x01, 0x09, 0x16, 0x01, 0x0E, 0x0F, 0x16, 0x01, 0x08, 0x09, 0x16, 0x01, 0x08, 0x09, 0x16, 0x01, 0x08, 0x09, 0x16, 0x01, 0x01, 0x09, 0x00, 0x00,
};

const u8* const PTR_ARRAY_0836e42c[6] = {
    u8_ARRAY_0836dfc0, u8_ARRAY_0836dfe0, u8_ARRAY_0836e012, u8_ARRAY_0836e05c, u8_ARRAY_0836e0be, u8_ARRAY_0836e12c,
};

const u8* const PTR_ARRAY_0836e444[7] = {
    u8_ARRAY_0836e1b2, u8_ARRAY_0836e250, u8_ARRAY_0836e2d6, u8_ARRAY_0836e344, u8_ARRAY_0836e3a0, u8_ARRAY_0836e3de, u8_ARRAY_0836e410,
};

const u8 u8_ARRAY_0836e460[11] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 u8_ARRAY_0836e46b[314] = {
    0,  23, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  24, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  23, 24, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  24, 24, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  23, 24, 24, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  24, 24, 24, 0, 0, 0,  0,  0,  0,  0,  0,  0,  23, 24, 24, 24, 0, 0, 0,  0,  0,  0,  0,  0,  0,  24, 24, 24, 24, 0, 0,  0,  0,  0,  0,  0,  0,  23, 24, 24, 24, 24, 0, 0,  0,  0,  0,  0,  0,  0,  24, 24, 24, 24, 24, 0,  0,  0,  0,  0,  0,  0,  23, 24, 24, 24, 24, 24, 0,  0,  0,  0,  0,  0,  0,  24, 24, 24, 24, 24, 24, 0,  0,  0,  0,  0,  0,  23, 24, 24, 24, 24, 24,
    24, 0,  0, 0, 0, 0, 0, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 0, 0, 23, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 0, 0, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 0, 23, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0,  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
};

const u8 u8_ARRAY_0836e5a5[13] = {
    24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
};

const u8 u8_ARRAY_0836e5b2[518] = {
    9,   2,   1,   2,   4,   5,   9,   4,   1,  6,  7,   8,   4,   9,   10,  11,  9,   5,   1,   6,   7,  12, 13, 4,  9,  14, 15, 16, 9,  7,  1,   6,   7,   12,  17,  18,  19,  4,   9,   14,  15, 20, 21,  0,   9,   8,   1,   6,   7,   12,  17, 18, 22, 23, 4,  9,  14, 15, 20, 24, 25, 26, 9,  10, 1,   6,   7,   12,  17,  18,  22,  27,  28,  29,  4,   9,   14,  15,  20,  24,  25,  30,  31,  0,   9,   11,  1,   6,   7,   12,  17,  18,  22,  27,  28,  32,  33,  4,   9,   14,  15,  20,  24,  25,  30,  34,  35,  36,  9,   13,  1,   6,   7,   12,  17,  18,  22,  27,  28, 32, 37, 38, 39,  4,   9,   14,  15,  20,  24,  25,  30,  34,  35,  40,  41,  0,   9,   13,  42,  43,  44,  45,  46,  47,  48,  49,  50, 51, 52, 53, 39, 54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  0,   9, 13, 42,  43,  44, 45,  46,  47,  48,
    49,  50,  51,  52,  66,  67,  68,  69,  70, 71, 72,  73,  74,  75,  76,  77,  78,  79,  0,   9,   13, 80, 81, 82, 81, 81, 83, 84, 81, 81, 81,  81,  85,  86,  87,  88,  88,  88,  88,  89,  90, 91, 92,  88,  88,  93,  0,   8,   15,  94,  95, 95, 95, 95, 95, 96, 97, 95, 95, 95, 95, 95, 95, 98, 99,  100, 100, 100, 100, 100, 100, 101, 102, 103, 100, 100, 100, 100, 104, 6,   19,  105, 106, 106, 106, 106, 106, 106, 106, 107, 108, 106, 106, 106, 106, 106, 106, 106, 106, 109, 110, 110, 110, 110, 110, 110, 110, 110, 111, 110, 110, 110, 110, 110, 110, 110, 110, 112, 0,  0,  0,  0,  113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 114, 115, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 0,  0,  0,  0,  0,  113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 114, 0, 0,  0,   0,   0,  113, 113, 113, 113,
    113, 113, 113, 113, 113, 113, 113, 113, 0,  0,  113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 0,  0,  113, 113, 113, 113, 113, 113, 113, 113, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  116, 113, 113, 113, 113, 113, 113, 113, 0,   0,   113, 113, 113, 113, 113, 113, 114, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   116, 113, 113, 113, 113, 113, 0,   0,   113, 113, 113, 113, 0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   113, 113, 113, 113, 0,   0,   113, 113, 0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0,  113, 113, 0,  0,   0,   0,
};

// clang-format off
const u8* const PTR_ARRAY_0836e7b8[22] = {
    &u8_ARRAY_0836e5b2[0],
    &u8_ARRAY_0836e5b2[6],
    &u8_ARRAY_0836e5b2[16],
    &u8_ARRAY_0836e5b2[28],
    &u8_ARRAY_0836e5b2[44],
    &u8_ARRAY_0836e5b2[62],
    &u8_ARRAY_0836e5b2[84],
    &u8_ARRAY_0836e5b2[108],
    &u8_ARRAY_0836e5b2[136],
    &u8_ARRAY_0836e5b2[164],
    &u8_ARRAY_0836e5b2[136],
    &u8_ARRAY_0836e5b2[108],
    &u8_ARRAY_0836e5b2[192],
    &u8_ARRAY_0836e5b2[220],
    &u8_ARRAY_0836e5b2[252],
    &u8_ARRAY_0836e5b2[292],
    &u8_ARRAY_0836e5b2[324],
    &u8_ARRAY_0836e5b2[356],
    &u8_ARRAY_0836e5b2[388],
    &u8_ARRAY_0836e5b2[420],
    &u8_ARRAY_0836e5b2[452],
    &u8_ARRAY_0836e5b2[484],
};
// clang-format on

static const u8 u8_ARRAY_0836e810[3] = {205, 206, 205};
