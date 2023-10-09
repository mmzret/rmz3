#include "blink.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "hud.h"
#include "overworld.h"
#include "sound.h"
#include "text.h"
#include "zero.h"

extern const s32 s32_ARRAY_080fece4[2];

static bool32 runFieldScript(struct VM *vm);
static void updateScreenEffectZ(struct VM *vm);
static void writeRune(struct VM *vm);
static void readInput(struct VM *vm);
static void filterEmergencyRed(struct VM *vm);
static void quakeScreen(struct VM *vm);
static void FUN_08021f2c(struct VM *vm);
static void tryDeleteIndicator(struct VM *vm);
static void tryForceZeroXCoord(struct VM *vm);
static void NoEntryZero(struct VM *vm);

void ClearVM(struct VM *vm, u32 stageID) {
  s32 i;

  vm->unk_000 = stageID;
  vm->unk_001 = 0;
  vm->unk_003 = vm->unk_004 = 0;

  for (i = 0; i < SCRIPT_ENTITY_COUNT; i++) {
    vm->entities[i].entity = NULL;
  }

  vm->time = 0;
  vm->wait = 0;
  vm->forcedKey = 0;
  vm->screenEffect = NO_SCREEN_EFFECT;
  vm->unk_14a = 0;
  vm->emergency = 0;
  vm->magnitude = 0;
  vm->rune.raw = 0;
  vm->indicator = NULL;
  vm->bgm = MUS_NONE;
  vm->zeroDeathTextIDs[0] = vm->zeroDeathTextIDs[1] = 0xFFFF;
  (vm->forceCoord).x = (vm->forceCoord).y = -1;

  gStageRun.vm.active = 0;
  PALETTE16(0) = RGB_BLACK;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x00;
  StopAllMusics();
}

void FUN_08021b88(struct VM *_ UNUSED) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.unk_408 = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.unk_0c[2] = 0xFF;
  wMOSAIC = 0;
  PALETTE16(0) = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
  StopAllMusics();
}

void SetScript(struct VM *vm, const struct Command *script) {
  vm->pc = (struct Command *)script;
  vm->start = (struct Command *)script;
  gStageRun.vm.active |= TRUE;
  wMOSAIC = 0;
  if (gTimeElfTimer != 0) {
    CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
    TurnUpBGM();
    gTimeElfTimer = 0;
  }
  stopSound(SE_TIME_ELF);
  stopSound(SE_TIME_ELF_HURRY);
}

/*
コマンド列を実行する
返り値:
  0: まだコマンドが残ってる
  1: 終端コマンド(0xFF)まで実行完了
*/
bool32 RunVM(struct VM *vm) {
  bool32 done = FALSE;
  if (gStageRun.vm.active & 1) {
    done = runFieldScript(vm);
  }
  vm->time++;

  readInput(vm);
  filterEmergencyRed(vm);
  quakeScreen(vm);
  FUN_08021f2c(vm);
  tryDeleteIndicator(vm);
  tryForceZeroXCoord(vm);
  NoEntryZero(vm);
  return done;
}

void FUN_08021ca0(struct VM *vm) {
  updateScreenEffectZ(vm);
  writeRune(vm);
}

void FUN_08021cb4(struct VM *vm, const struct Command *script, struct Entity *e) {
  struct ScriptEntity *se = &vm->entities[2];
  if (se->entity == NULL) {
    e->flags |= SCRIPTED;
    e->arr = (u8 *)se;
    vm->entities[2].entity = e;
    se->unk_08 = 2;
    se->unk_09 = 0;
    se->unk_0A[0] = se->unk_0A[1] = se->unk_0A[2] = 0;
    SetScript(vm, script);
  }
}

void CreateScriptEntity(u8 n, struct ScriptEntityTemplate *template) {
  struct ScriptEntity *se = &gStageRun.vm.entities[n];
  if (se->entity == NULL) {
    struct Entity *e;

    if ((template->kind == ENTITY_PLAYER) && (template->unk_02 != 0)) {
      e = (struct Entity *)AllocPlayer2();
      if (e != NULL) {
        e->taskCol = 16;
        INIT_PLAYER_ROUTINE(((struct Zero *)e), template->variant);
      }
    } else {
      e = CreateStageEntity(template->kind, template->variant);
    }

    se->entity = e;
    if (e != NULL) {
      e->flags |= SCRIPTED;
      e->arr = (u8 *)se;
      e->work[0] = template->unk_02;
      e->work[1] = template->unk_03;
      e->coord.x = (template->coord).x;
      e->coord.y = (template->coord).y;
      if (template->xflip) {
        e->flags |= X_FLIP;
      } else {
        e->flags &= ~X_FLIP;
      }
      if (template->yflip) {
        e->flags |= Y_FLIP;
      } else {
        e->flags &= ~Y_FLIP;
      }
      se->unk_08 = n;
      se->unk_09 = 0;
      se->unk_0A[0] = se->unk_0A[1] = se->unk_0A[2] = 0;
      if (n == 0) {
        pZero2 = (struct Zero *)e;
        gHUD.z = (struct Zero *)e;
        SaveZeroStatus((struct Zero *)e, &gGameState.save.status);
        LoadZeroPalette(e, ((&((struct Zero *)e)->unk_b4)->status).body);
      }
      if (n == 1) {
        CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
      }
    }
  }
}

void DeleteScriptEntity(u8 n) {
  struct ScriptEntity *s = &gStageRun.vm.entities[n];
  struct Entity *e = s->entity;
  if (e != NULL) {
    if ((gStageRun.id != 0) && (n == 0)) {
      gHUD.z = NULL;
      resetSateliteElfPosition(gGameState.z2);
      CopyZeroStatus(gGameState.z2, &gGameState.save.status);
    }
    if (n == 1) {
      gHUD.unk_0c = NULL;
    }
    DeleteStageEntity((struct CollidableEntity *)e);
    s->entity = NULL;
  }
}

/*
RunVM(08021e5c) で終端(0xFF)までループして実行される

返り値:
  0: ループ続行
  1: ループから抜ける 再び runFieldScript が実行されるとき、次のコマンドから再開
*/
static bool32 runFieldScript(struct VM *vm) {
  if (vm->wait != 0) {
    vm->wait--;
    return FALSE;
  }

  while (vm->pc->cmd != 0xFF) {
    const bool32 exit = (gScriptCommands[vm->pc->cmd])(vm);
    if (exit) {
      vm->pc++;
      return FALSE;
    }

    vm->pc++;
  }
  gStageRun.vm.active &= ~1;
  return TRUE;
}

// 0x08021ec4
static void readInput(struct VM *vm) {
  struct Zero *z = (struct Zero *)vm->entities[0].entity;
  if (vm->forcedKey == 0) {
    gStageRun.input = gJoypad[0].input & 0x7FFF;
    gStageRun.unk_06 = gJoypad[1].input & 0x7FFF;

  } else if (vm->forcedKey == 0xFFFF) {
    gStageRun.input = 0;
    gStageRun.unk_06 = 0;
    if (z != NULL) {
      ResetZeroInput(z);
    }

  } else {
    gStageRun.input = vm->forcedKey;
    gStageRun.unk_06 = vm->forcedKey;
  }
}

NAKED static void FUN_08021f2c(struct VM *vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	movs r0, #0xa2\n\
	lsls r0, r0, #1\n\
	adds r5, r4, r0\n\
	ldr r3, [r5]\n\
	lsrs r1, r3, #0x10\n\
	cmp r3, #0\n\
	beq _0802202A\n\
	movs r0, #8\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08021FB0\n\
	ldr r1, _08021F9C @ =gPaletteManager\n\
	ldr r2, _08021FA0 @ =0x00000402\n\
	adds r2, r2, r1\n\
	mov r8, r2\n\
	movs r4, #0\n\
	movs r0, #0x20\n\
	strb r0, [r2]\n\
	ldr r6, _08021FA4 @ =0x00000401\n\
	adds r7, r1, r6\n\
	strb r0, [r7]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r6, r1, r2\n\
	strb r0, [r6]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0xa\n\
	adds r1, r3, r0\n\
	str r1, [r5]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xf\n\
	cmp r1, r0\n\
	bls _0802202A\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08021F8C\n\
	movs r0, #0xc7\n\
	bl PlaySound\n\
	mov r1, r8\n\
	strb r4, [r1]\n\
	strb r4, [r7]\n\
	strb r4, [r6]\n\
_08021F8C:\n\
	str r4, [r5]\n\
	ldr r2, _08021FA8 @ =gWindowRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _08021FAC @ =0x0000DFFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	b _0802202A\n\
	.align 2, 0\n\
_08021F9C: .4byte gPaletteManager\n\
_08021FA0: .4byte 0x00000402\n\
_08021FA4: .4byte 0x00000401\n\
_08021FA8: .4byte gWindowRegBuffer\n\
_08021FAC: .4byte 0x0000DFFF\n\
_08021FB0:\n\
	movs r0, #1\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	bne _08021FBC\n\
	movs r0, #0x40\n\
	subs r1, r0, r1\n\
_08021FBC:\n\
	movs r0, #4\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08021FF4\n\
	ldr r2, _08021FEC @ =gPaletteManager\n\
	lsrs r1, r1, #1\n\
	movs r0, #0x40\n\
	subs r0, r0, r1\n\
	ldr r6, _08021FF0 @ =0x00000402\n\
	adds r1, r2, r6\n\
	strb r0, [r1]\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	subs r6, #1\n\
	adds r1, r2, r6\n\
	strb r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r2, r2, r1\n\
	strb r0, [r2]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r3, r2\n\
	b _08022016\n\
	.align 2, 0\n\
_08021FEC: .4byte gPaletteManager\n\
_08021FF0: .4byte 0x00000402\n\
_08021FF4:\n\
	ldr r2, _08022034 @ =gPaletteManager\n\
	lsrs r1, r1, #1\n\
	ldr r6, _08022038 @ =0x00000402\n\
	adds r0, r2, r6\n\
	strb r1, [r0]\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	subs r6, #1\n\
	adds r0, r2, r6\n\
	strb r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	adds r2, r2, r0\n\
	strb r1, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xa\n\
	adds r0, r3, r1\n\
_08022016:\n\
	str r0, [r5]\n\
	movs r6, #0xa2\n\
	lsls r6, r6, #1\n\
	adds r2, r4, r6\n\
	ldr r1, [r2]\n\
	ldr r0, _0802203C @ =0x00400005\n\
	cmp r1, r0\n\
	bls _0802202A\n\
	movs r0, #0\n\
	str r0, [r2]\n\
_0802202A:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08022034: .4byte gPaletteManager\n\
_08022038: .4byte 0x00000402\n\
_0802203C: .4byte 0x00400005\n\
 .syntax divided\n");
}

// Zマークを作りながらの暗転(or Zマークを作りながらの暗転からの復帰)
NAKED static void updateScreenEffectZ(struct VM *vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r1, #0xa2\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	movs r0, #8\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08022054\n\
	b _08022170\n\
_08022054:\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0802207C\n\
	ldr r1, _08022078 @ =gSineTable\n\
	lsrs r0, r2, #0x10\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	subs r0, r0, r1\n\
	asrs r4, r0, #2\n\
	b _0802208E\n\
	.align 2, 0\n\
_08022078: .4byte gSineTable\n\
_0802207C:\n\
	ldr r0, _080220B0 @ =gSineTable\n\
	lsrs r1, r2, #0x10\n\
	adds r1, #0x40\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	asrs r4, r0, #0x12\n\
_0802208E:\n\
	ldr r3, _080220B4 @ =gWindowRegBuffer\n\
	ldrh r1, [r3]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	adds r0, r2, #0\n\
	movs r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	strb r2, [r3, #0xc]\n\
	movs r0, #0xa0\n\
	strh r0, [r3, #8]\n\
	cmp r4, #0\n\
	bne _080220B8\n\
	movs r0, #0xf0\n\
	strh r0, [r3, #4]\n\
	b _08022170\n\
	.align 2, 0\n\
_080220B0: .4byte gSineTable\n\
_080220B4: .4byte gWindowRegBuffer\n\
_080220B8:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #1\n\
	bl Malloc\n\
	adds r5, r0, #0\n\
	cmp r5, #0\n\
	beq _08022170\n\
	ldr r2, _080220FC @ =gIntrManager\n\
	movs r1, #0xda\n\
	lsls r1, r1, #1\n\
	adds r0, r2, r1\n\
	str r5, [r0]\n\
	movs r0, #0xdc\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _08022100 @ =0x04000040\n\
	str r0, [r1]\n\
	movs r0, #0xde\n\
	lsls r0, r0, #1\n\
	adds r1, r2, r0\n\
	ldr r0, _08022104 @ =0xA2600001\n\
	str r0, [r1]\n\
	movs r3, #0\n\
	adds r6, r4, #0\n\
	adds r6, #0x32\n\
	movs r0, #0x50\n\
	subs r0, r0, r4\n\
	adds r2, r5, #0\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
_080220F4:\n\
	cmp r3, r6\n\
	bge _08022108\n\
	movs r0, #0\n\
	b _08022122\n\
	.align 2, 0\n\
_080220FC: .4byte gIntrManager\n\
_08022100: .4byte 0x04000040\n\
_08022104: .4byte 0xA2600001\n\
_08022108:\n\
	adds r0, r4, #0\n\
	adds r0, #0x6e\n\
	cmp r3, r0\n\
	bge _08022120\n\
	asrs r0, r1, #1\n\
	adds r0, #0x78\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf0\n\
	bls _08022122\n\
	movs r0, #0\n\
	b _08022122\n\
_08022120:\n\
	movs r0, #0xf0\n\
_08022122:\n\
	strh r0, [r2]\n\
	adds r2, #2\n\
	subs r1, #3\n\
	adds r3, #1\n\
	cmp r3, #0x9f\n\
	ble _080220F4\n\
	movs r3, #0\n\
	movs r0, #0x32\n\
	subs r7, r0, r4\n\
	movs r0, #0x6e\n\
	subs r6, r0, r4\n\
	adds r2, r5, #0\n\
_0802213A:\n\
	cmp r3, r7\n\
	bge _08022142\n\
	movs r0, #0xf0\n\
	b _08022166\n\
_08022142:\n\
	cmp r3, r6\n\
	bge _08022168\n\
	adds r1, r4, #0\n\
	adds r1, #0x50\n\
	subs r1, r1, r3\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	adds r0, #0x78\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf0\n\
	bls _0802215E\n\
	movs r0, #0xf0\n\
_0802215E:\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
_08022166:\n\
	strh r0, [r2]\n\
_08022168:\n\
	adds r2, #2\n\
	adds r3, #1\n\
	cmp r3, #0x9f\n\
	ble _0802213A\n\
_08022170:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void writeRune(struct VM *vm) {
  const s32 rune = vm->rune.raw;
  if (rune != 0) {
    u8 x = rune >> 16;
    u8 y = rune >> 24;
    PrintString(STRING(rune & 0xFFFF), x, y);
  }
}

static void tryDeleteIndicator(struct VM *vm) {
  struct VFX *z = vm->indicator;
  if ((z != NULL) && (ENTITY_UPDATE < (z->s).mode[0])) {
    vm->indicator = NULL;
  }
}

static void tryForceZeroXCoord(struct VM *vm) {
  s32 x;
  struct Entity *e = vm->entities[0].entity;
  if ((e != NULL) && (x = (vm->forceCoord).x, 0 < x)) {
    (e->coord).x = x;
  }
}

// gOverworld.disableArea の見えない壁に阻まれる処理
WIP static void NoEntryZero(struct VM *vm) {
#if MODERN
  s32 top = 0;
  s32 left = 0;
  s32 right = s32_ARRAY_080fece4[0];
  s32 bottom = s32_ARRAY_080fece4[1];

  struct Zero *z = (struct Zero *)vm->entities[0].entity;
  if (z != NULL) {
    struct Camera *camera = &gStageRun.vm.camera;
    if (camera->mode > 3) {
      left = camera->left;
      top = camera->top;
      right = camera->right;
      bottom = camera->bottom;
    }

    if (left < gOverworld.unk_1c8.disableArea[0]) {
      left = gOverworld.unk_1c8.disableArea[0];
    }
    if (top < gOverworld.unk_1c8.disableArea[1]) {
      top = gOverworld.unk_1c8.disableArea[1];
    }
    if (right > gOverworld.unk_1c8.disableArea[2]) {
      right = gOverworld.unk_1c8.disableArea[2];
    }
    if (bottom > gOverworld.unk_1c8.disableArea[3]) {
      bottom = gOverworld.unk_1c8.disableArea[3];
    }
    SetDisableArea(z, left, top, right, bottom);

    z = (struct Zero *)vm->entities[1].entity;
    if ((z != NULL) && ((z->s).kind == ENTITY_PLAYER)) {
      SetDisableArea(z, left, top, right, bottom);
    }
  }
#else
  INCCODE("asm/wip/NoEntryZero.inc");
#endif
}

NAKED static void filterEmergencyRed(struct VM *vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r1, #0xa6\n\
	lsls r1, r1, #1\n\
	adds r5, r0, r1\n\
	ldrh r3, [r5]\n\
	ldr r0, _08022314 @ =0x0000BFFF\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0802230C\n\
	ldr r1, _08022318 @ =gSineTable\n\
	lsls r0, r3, #0x1a\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x17\n\
	adds r0, r0, r2\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x15\n\
	movs r1, #8\n\
	subs r4, r1, r0\n\
	movs r2, #0xff\n\
	lsls r2, r2, #8\n\
	ands r2, r3\n\
	adds r0, r3, #1\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	orrs r2, r0\n\
	strh r2, [r5]\n\
	ldr r3, _0802231C @ =gPaletteManager\n\
	asrs r0, r4, #1\n\
	adds r0, #0x20\n\
	movs r6, #0x80\n\
	lsls r6, r6, #3\n\
	adds r1, r3, r6\n\
	strb r0, [r1]\n\
	movs r0, #0x20\n\
	subs r0, r0, r4\n\
	adds r6, #1\n\
	adds r1, r3, r6\n\
	strb r0, [r1]\n\
	ldr r1, _08022320 @ =0x00000402\n\
	adds r3, r3, r1\n\
	strb r0, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _0802230C\n\
	cmp r4, #0\n\
	bne _0802230C\n\
	strh r4, [r5]\n\
_0802230C:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08022314: .4byte 0x0000BFFF\n\
_08022318: .4byte gSineTable\n\
_0802231C: .4byte gPaletteManager\n\
_08022320: .4byte 0x00000402\n\
 .syntax divided\n");
}

static void quakeScreen(struct VM *vm) {
  struct Coord c;
  s32 rng;

  if (vm->magnitude != 0) {
    RNG_0202f388 = LCG(RNG_0202f388);
    rng = (RNG_0202f388 >> 16) & 0xF;
    if (rng <= (vm->magnitude & 0xFF)) {
      AppendQuake(rng, &gStageRun.vm.camera.viewport);
    }
    if ((&gStageRun.vm.camera)->mode == 0) {
      CalcQuake(&(&gStageRun.vm.camera)->target, &c);
      ((struct BgOfs *)gVideoRegBuffer.bgofs[1])->x = c.x >> 8;
      ((struct BgOfs *)gVideoRegBuffer.bgofs[1])->y = c.y >> 8;
    }
  }
}
