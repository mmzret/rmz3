#include "blink.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "hud.h"
#include "overworld.h"
#include "sound.h"
#include "text.h"
#include "zero.h"

extern const struct Coord gMaxCoords;

static bool32 runFieldScript(struct VM* vm);
static void PrintScriptString(struct VM* vm);
static void readInput(struct VM* vm);
static void StepEmergencyRed(struct VM* vm);
static void quakeScreen(struct VM* vm);
static void StepTransition(struct VM* vm);
static void tryDeleteIndicator(struct VM* vm);
static void tryForceZeroXCoord(struct VM* vm);
static void UpdatePlayerMovableArea(struct VM* vm);

void ClearVM(struct VM* vm, u32 stageID) {
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
  vm->transition = TRANSITION_NONE;
  vm->unk_14a = 0;
  vm->emergency = 0;
  vm->magnitude = 0;
  vm->string.raw = 0;
  vm->indicator = NULL;
  vm->bgm = MUS_NONE;
  vm->zeroDeathTextIDs[0] = vm->zeroDeathTextIDs[1] = 0xFFFF;
  (vm->forceCoord).x = (vm->forceCoord).y = -1;

  gStageRun.vm.active = 0;
  PALETTE16(0) = RGB_BLACK;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x00;
  StopAllMusics();
}

void FUN_08021b88(struct VM* _ UNUSED) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
  gPaletteManager.post_process = NULL;
  ClearBlinkings();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  wMOSAIC = 0;
  PALETTE16(0) = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
  StopAllMusics();
}

void SetScript(struct VM* vm, const struct Command* script) {
  vm->pc = (struct Command*)script;
  vm->start = (struct Command*)script;
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
bool32 RunVM(struct VM* vm) {
  bool32 done = FALSE;
  if (gStageRun.vm.active & 1) {
    done = runFieldScript(vm);
  }
  vm->time++;

  readInput(vm);
  StepEmergencyRed(vm);
  quakeScreen(vm);
  StepTransition(vm);
  tryDeleteIndicator(vm);
  tryForceZeroXCoord(vm);
  UpdatePlayerMovableArea(vm);
  return done;
}

static void _RenderWipeZ(struct VM* vm);

void RenderWipeZ(struct VM* vm) {
  _RenderWipeZ(vm);
  PrintScriptString(vm);
}

void FUN_08021cb4(struct VM* vm, const struct Command* script, struct Entity* e) {
  struct ScriptEntity* se = &vm->entities[2];
  if (se->entity == NULL) {
    e->flags |= SCRIPTED;
    e->scriptEntity = se;
    vm->entities[2].entity = e;
    se->unk_08 = 2;
    se->flags = 0;
    se->unk_0A[0] = se->unk_0A[1] = se->unk_0A[2] = 0;
    SetScript(vm, script);
  }
}

void CreateScriptEntity(u8 n, struct ScriptEntityTemplate* template) {
  struct ScriptEntity* se = &gStageRun.vm.entities[n];
  if (se->entity == NULL) {
    struct Entity* e;

    if ((template->kind == ENTITY_PLAYER) && (template->work[0] != PLAYER_ZERO)) {
      e = (struct Entity*)AllocPlayer2();
      if (e != NULL) {
        e->taskCol = 16;
        INIT_PLAYER_ROUTINE(((struct Zero*)e), template->variant);
      }
    } else {
      e = CreateStageEntity(template->kind, template->variant);
    }

    se->entity = e;
    if (e != NULL) {
      e->flags |= SCRIPTED;
      e->scriptEntity = se;
      e->work[0] = template->work[0];
      e->work[1] = template->work[1];
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
      se->flags = 0;
      se->unk_0A[0] = se->unk_0A[1] = se->unk_0A[2] = 0;
      if (n == 0) {
        pZero2 = (struct Zero*)e;
        gHUD.z = (struct Zero*)e;
        SaveZeroStatus((struct Zero*)e, &gGameState.save.status);
        LoadZeroPalette(e, ((&((struct Zero*)e)->unk_b4)->status).body);
      }
      if (n == 1) {
        CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
      }
    }
  }
}

void DeleteScriptEntity(u8 n) {
  struct ScriptEntity* s = &gStageRun.vm.entities[n];
  struct Entity* e = s->entity;
  if (e != NULL) {
    if ((gStageRun.id != 0) && (n == 0)) {
      gHUD.z = NULL;
      resetSateliteElfPosition(gGameState.z2);
      CopyZeroStatus(gGameState.z2, &gGameState.save.status);
    }
    if (n == 1) {
      gHUD.unk_0c = NULL;
    }
    DeleteStageEntity((struct CollidableEntity*)e);
    s->entity = NULL;
  }
}

/*
RunVM(08021e5c) で終端(0xFF)までループして実行される

返り値:
  0: ループ続行
  1: ループから抜ける 再び runFieldScript が実行されるとき、次のコマンドから再開
*/
static bool32 runFieldScript(struct VM* vm) {
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
static void readInput(struct VM* vm) {
  struct Zero* z = (struct Zero*)vm->entities[0].entity;
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

static void StepTransition(struct VM* vm) {
  u32 mode = vm->transition;
  u32 counter = mode >> 16;
  if (mode != TRANSITION_NONE) {
    if (mode & TRANSITION_Z) {
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x20;
      vm->transition += (0x3 << 16);
      if (vm->transition > (64 << 16)) {
        if (!(vm->transition & TRANSITION_REVERSE)) {
          PlaySound(SE_UNK_c7);
          gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x0;
        }
        vm->transition = TRANSITION_NONE;
        gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON;
      }
    } else {
      if (!(mode & TRANSITION_REVERSE)) {
        counter = 64 - counter;
      }
      if (mode & TRANSITION_WHITEOUT) {
        gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0x40 - (counter >> 1);
        vm->transition += (0x1 << 16);
      } else {
        gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = (counter >> 1);
        vm->transition += (0x2 << 16);
      }
      if (vm->transition > ((64 << 16) | 5)) {
        vm->transition = TRANSITION_NONE;
      }
    }
  }
}

// Zマークを作りながらの暗転(or Zマークを作りながらの暗転からの復帰)
NAKED static void _RenderWipeZ(struct VM* vm) {
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

// print_string (Cmd_printstring) でリクエストされた文字列があれば描画する (コマンド側で文字列の描画の終了がリクエストされるまで毎フレーム描画される)
static void PrintScriptString(struct VM* vm) {
  const s32 s = vm->string.raw;
  if (s != 0) {
    u8 x = s >> 16;
    u8 y = s >> 24;
    PrintString(STRING(s & 0xFFFF), x, y);
  }
}

static void tryDeleteIndicator(struct VM* vm) {
  struct VFX* z = vm->indicator;
  if ((z != NULL) && (ENTITY_UPDATE < (z->s).mode[0])) {
    vm->indicator = NULL;
  }
}

static void tryForceZeroXCoord(struct VM* vm) {
  s32 x;
  struct Entity* e = vm->entities[0].entity;
  if ((e != NULL) && (x = (vm->forceCoord).x, 0 < x)) {
    (e->coord).x = x;
  }
}

// gOverworld.range の見えない壁に阻まれる処理
static void UpdatePlayerMovableArea(struct VM* vm) {
  struct Zero* player = (struct Zero*)vm->entities[0].entity;
  struct Coord c1 = {x : 0, y : 0};
  struct Coord c2 = {x : gMaxCoords.x, y : gMaxCoords.y};

  if (player != NULL) {
    struct Camera* camera = &gStageRun.vm.camera;
    if (camera->mode > 3) {
      c1.x = camera->left;
      c1.y = camera->top;
      c2.x = camera->right;
      c2.y = camera->bottom;
    }

    if (c1.x < gOverworld.range.left) {
      c1.x = gOverworld.range.left;
    }
    if (c1.y < gOverworld.range.top) {
      c1.y = gOverworld.range.top;
    }
    if (c2.x > gOverworld.range.right) {
      c2.x = gOverworld.range.right;
    }
    if (c2.y > gOverworld.range.bottom) {
      c2.y = gOverworld.range.bottom;
    }
    SetDisableArea(player, c1.x, c1.y, c2.x, c2.y);

    player = (struct Zero*)vm->entities[1].entity;
    if ((player != NULL) && ((player->s).kind == ENTITY_PLAYER)) {
      SetDisableArea(player, c1.x, c1.y, c2.x, c2.y);
    }
  }
}

// update Emergency effect (blend red)
static void StepEmergencyRed(struct VM* vm) {
  if ((vm->emergency & ((u16)~EMERGENCY_TEMPORARY)) != 0) {
    s32 n = 8 - (COS(vm->emergency << 2) >> 5);
    vm->emergency = (vm->emergency & 0xFF00) | ((vm->emergency + 1) & 0xFF);
    gPaletteManager.filter[0] = 0x20 + (n >> 1);
    gPaletteManager.filter[2] = gPaletteManager.filter[1] = 0x20 - n;

    if ((vm->emergency & EMERGENCY_TEMPORARY) && (n == 0)) {
      vm->emergency = 0;
    }
  }
}

static void quakeScreen(struct VM* vm) {
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
      BGOFS(1)->x = c.x >> 8;
      BGOFS(1)->y = c.y >> 8;
    }
  }
}
