#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "hud.h"
#include "overworld.h"
#include "palette_animation.h"
#include "spawn.h"
#include "text.h"
#include "zero.h"

extern const Coords32 gMaxCoords;

static bool32 RunScript(struct VM* vm);
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
  vm->eventID = vm->unk_004 = 0;

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
  gPaletteManager.buf[0] = RGB_BLACK;
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_BLACK;
  StopAllMusics();
}

void FUN_08021b88(struct VM* _ UNUSED) {
  gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
  gPaletteManager.post_process = NULL;
  RemoveAllPaletteAnimations();
  gBlendRegBuffer.bldclt = 0;
  gWindowRegBuffer.dispcnt = 0;
  gWindowRegBuffer.winin[2] = 0xFF;
  wMOSAIC = 0;
  gPaletteManager.buf[0] = RGB_BLACK;
  gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
  StopAllMusics();
}

void SetScript(struct VM* vm, const GameCommand* script) {
  vm->pc = (GameCommand*)script;
  vm->start = (GameCommand*)script;
  gStageRun.vm.active |= VM_ACTIVE;
  wMOSAIC = 0;
  if (gTimeElfTimer != 0) {
    CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
    TurnUpBGM();
    gTimeElfTimer = 0;
  }
  StopSound(SE_TIME_ELF);
  StopSound(SE_TIME_ELF_HURRY);
}

/*
コマンド列を実行する
返り値:
  0: まだコマンドが残ってる
  1: 終端コマンド(0xFF)まで実行完了
*/
bool32 RunVM(struct VM* vm) {
  bool32 done = FALSE;
  if (gStageRun.vm.active & VM_ACTIVE) {
    done = RunScript(vm);
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

// シールドブーメラン を受け取る会話の時にのみ呼ばれる
void FUN_08021cb4(struct VM* vm, const GameCommand* script, struct Entity* e) {
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

struct ScriptEntityTemplate {
  u8 kind;
  u8 variant;
  u8 work[2];
  Coords32 coord;
  s8 xflip;
  s8 yflip;
};

// spawn　コマンド
void CreateScriptEntity(u8 n, struct ScriptEntityTemplate* template) {
  struct ScriptEntity* se = &gStageRun.vm.entities[n];
  if (se->entity == NULL) {
    struct Entity* e;

    if ((template->kind == ENTITY_PLAYER) && (template->work[0] != PLAYER_ZERO)) {
      e = AllocPlayer2();
      if (e != NULL) {
        e->renderPrio = 16;
        INIT_PLAYER_ROUTINE(e, template->variant);
      }
    } else {
      e = CreateStageEntity(template->kind, template->variant);
    }

    se->entity = e;
    if (e != NULL) {
      e->flags |= SCRIPTED;
      e->scriptEntity = se;
      e->work[0] = template->work[0], e->work[1] = template->work[1];
      e->coord.x = (template->coord).x, e->coord.y = (template->coord).y;
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
        LoadZeroStatus((struct Zero*)e, &gGameState.save.status);
        LoadZeroPalette(e, ((&((struct Zero*)e)->unk_b4)->status).body);
      }
      if (n == 1) CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
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
      StoreZeroStatus(gGameState.z2, &gGameState.save.status);
    }
    if (n == 1) gHUD.unk_0c = NULL;
    DeleteStageEntity(e);
    s->entity = NULL;
  }
}

/**
 * @brief スクリプト(asm/scripts のコマンド列) を実行する
 * @return TRUE: 終端コマンド(end)まで実行を終えた, FALSE: wait コマンドなどで一時停止(halt)している
 * @note 0x08021e5c
 */
static bool32 RunScript(struct VM* vm) {
  if (vm->wait != 0) {
    vm->wait--;
    return FALSE;
  }

  while (((vm->pc)->c).op != 0xFF) {
    const bool32 halted = (gScriptCommands[((vm->pc)->c).op])(vm);
    if (halted) {  // wait コマンドや wait_transition_end コマンドなどでコマンドの実行が一時停止した (pcのデクリメント処理はそれぞれのコマンドハンドラが行う)
      vm->pc++;
      return FALSE;
    }
    vm->pc++;
  }
  gStageRun.vm.active &= ~VM_ACTIVE;
  return TRUE;  // 終端コマンドまで実行完了
}

// 0x08021ec4
static void readInput(struct VM* vm) {
  Player* p = (Player*)vm->entities[0].entity;
  if (vm->forcedKey == 0) {
    gStageRun.input = gJoypad[0].input & 0x7FFF;
    gStageRun.unk_06 = gJoypad[1].input & 0x7FFF;
  } else if (vm->forcedKey == 0xFFFF) {
    gStageRun.input = 0;
    gStageRun.unk_06 = 0;
    if (p != NULL) ResetZeroInput(p);
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
      gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_NONE;
      vm->transition += (0x3 << 16);                   // counter += 3
      if (vm->transition > (64 << 16)) {               // counter > 64
        if (!(vm->transition & TRANSITION_REVERSE)) {  // 画面が見える状態からZで真っ黒になったとき
          PlaySound(SE_UNK_c7);
          gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_BLACK;
        }
        vm->transition = TRANSITION_NONE;
        gWindowRegBuffer.dispcnt &= ~DISPCNT_WIN0_ON;
      }
    } else {
      if (!(mode & TRANSITION_REVERSE)) {
        counter = 64 - counter;
      }
      if (mode & TRANSITION_WHITEOUT) {
        gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_WHITE - (counter >> 1);
        vm->transition += (0x1 << 16);  // counter++
      } else {
        gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = (counter >> 1);
        vm->transition += (0x2 << 16);  // counter += 2
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
  Entity* p = vm->indicator;
  if ((p != NULL) && (ENTITY_UPDATE < p->mode[0])) {
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
  Coords32 c1 = {x : 0, y : 0};
  Coords32 c2 = {x : gMaxCoords.x, y : gMaxCoords.y};

  if (player != NULL) {
    struct Camera* cam = &gStageRun.vm.camera;
    if (cam->mode >= CM4) {
      c1.x = cam->left, c1.y = cam->top;
      c2.x = cam->right, c2.y = cam->bottom;
    }
    if (c1.x < gOverworld.range.left) c1.x = gOverworld.range.left;
    if (c1.y < gOverworld.range.top) c1.y = gOverworld.range.top;
    if (c2.x > gOverworld.range.right) c2.x = gOverworld.range.right;
    if (c2.y > gOverworld.range.bottom) c2.y = gOverworld.range.bottom;
    SetDisableArea(player, c1.x, c1.y, c2.x, c2.y);

    player = (struct Zero*)vm->entities[1].entity;
    if ((player != NULL) && ((player->s).kind == ENTITY_PLAYER)) {
      SetDisableArea(player, c1.x, c1.y, c2.x, c2.y);
    }
  }
}

/**
 * @brief update Emergency effect (blend red)
 * @note 0x080222a4
 */
static void StepEmergencyRed(struct VM* vm) {
  if ((vm->emergency & ((u16)~EMERGENCY_END)) != 0) {  // = (vm->emergency & EMERGENCY_ENABLED) != 0
    s32 red = 8 - (COS(vm->emergency << 2) >> 5);
    vm->emergency = (vm->emergency & 0xFF00) | ((vm->emergency + 1) & 0xFF);
    gPaletteManager.filter[0] = 0x20 + (red >> 1);                       // R
    gPaletteManager.filter[2] = gPaletteManager.filter[1] = 0x20 - red;  // G, B

    if ((vm->emergency & EMERGENCY_END) && (red == 0)) {
      vm->emergency = 0;
    }
  }
}

static void quakeScreen(struct VM* vm) {
  if (vm->magnitude != 0) {
    s32 rng = RANDOM(RNG_0202f388) & 0xF;
    if (rng <= (vm->magnitude & 0xFF)) {
      AppendQuake(rng, &gStageRun.vm.camera.viewport);
    }
    // カメラが無効なときは自分で反映させる
    if ((&gStageRun.vm.camera)->mode == CM0_DISABLED) {
      Coords32 c;
      CalcQuake(&(&gStageRun.vm.camera)->target, &c);
      BGOFS(1)->x = c.x >> 8, BGOFS(1)->y = c.y >> 8;
    }
  }
}
