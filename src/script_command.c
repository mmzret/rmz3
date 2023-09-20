#include "blink.h"
#include "collision.h"
#include "element.h"
#include "entity.h"
#include "gfx.h"
#include "global.h"
#include "gpu_regs.h"
#include "hud.h"
#include "mission.h"
#include "overworld.h"
#include "result.h"
#include "sound.h"
#include "sprite.h"
#include "story.h"
#include "text.h"
#include "vfx.h"
#include "zero.h"

static bool32 Cmd_goto(struct VM* vm);
static bool32 Cmd_wait(struct VM* vm);
static bool32 Cmd_time(struct VM* vm);
static bool32 Cmd_nop(struct VM* _ UNUSED);
static bool32 Cmd_resetcamera(struct VM* vm);
static bool32 Cmd_modifycamera(struct VM* vm);
static bool32 Cmd_cmd06(struct VM* vm);
static bool32 Cmd_resume(struct VM* vm);
static bool32 Cmd_cmd08(struct VM* vm);
static bool32 Cmd_disablekeyinput(struct VM* vm);
static bool32 Cmd_loadgraphic(struct VM* vm);
static bool32 Cmd_spawn(struct VM* vm);
static bool32 Cmd_cmd0c(struct VM* vm);
static bool32 Cmd_cmd0d(struct VM* vm);
static bool32 Cmd_cmd0e(struct VM* vm);
static bool32 Cmd_cmd0f(struct VM* vm);
static bool32 Cmd_emergency(struct VM* vm);
static bool32 Cmd_quake(struct VM* vm);
static bool32 Cmd_emotion(struct VM* vm);
static bool32 Cmd_scroll(struct VM* vm);
static bool32 Cmd_screeneffect(struct VM* vm);
static bool32 Cmd_rune(struct VM* vm);
static bool32 Cmd_indicator(struct VM* vm);
static bool32 Cmd_message(struct VM* vm);
static bool32 Cmd_bgm(struct VM* vm);
static bool32 Cmd_se(struct VM* vm);
static bool32 Cmd_force(struct VM* vm);
static bool32 Cmd_cmd1b(struct VM* vm);
static bool32 Cmd_cmd1c(struct VM* vm);
static bool32 Cmd_sweep(struct VM* vm);
static bool32 Cmd_lockmenu(struct VM* vm);
static bool32 Cmd_eventflag(struct VM* vm);
static bool32 Cmd_cmd20(struct VM* vm);
static bool32 Cmd_drop(struct VM* vm);
static bool32 Cmd_missionresult(struct VM* vm);
static bool32 Cmd_goodluck(struct VM* vm);
static bool32 Cmd_killtimeelf(struct VM* vm);
static bool32 Cmd_cutscene(struct VM* vm);

// clang-format off
const CommandHandler gScriptCommands[38] = {
    Cmd_goto,
    Cmd_wait,
    Cmd_time,
    Cmd_nop,
    Cmd_resetcamera,
    Cmd_modifycamera,
    Cmd_cmd06,
    Cmd_resume,
    Cmd_cmd08,
    Cmd_disablekeyinput,
    Cmd_loadgraphic,
    Cmd_spawn,
    Cmd_cmd0c,
    Cmd_cmd0d,
    Cmd_cmd0e,
    Cmd_cmd0f,
    Cmd_emergency,
    Cmd_quake,
    Cmd_emotion,
    Cmd_scroll,
    Cmd_screeneffect,
    Cmd_rune,
    Cmd_indicator,
    Cmd_message,
    Cmd_bgm,
    Cmd_se,
    Cmd_force,
    Cmd_cmd1b,
    Cmd_cmd1c,
    Cmd_sweep,
    Cmd_lockmenu,
    Cmd_eventflag,
    Cmd_cmd20,
    Cmd_drop,
    Cmd_missionresult,
    Cmd_goodluck,
    Cmd_killtimeelf,
    Cmd_cutscene,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

static bool32 Cmd_goto(struct VM* vm) {
  if (vm->pc->status == 0) {
    vm->pc = (struct Command*)(vm->pc->work - sizeof(struct Command));
  }
  return FALSE;
}

static bool32 Cmd_wait(struct VM* vm) {
  struct Command* c = vm->pc;
  if (c->status == 0) {
    if (vm->unk_004 != 0) {
      vm->pc--;
      return TRUE;
    }
    return FALSE;
  }

  vm->wait = c->work;
  if (c->status == 2) {
    vm->wait -= vm->time;
  }

  if ((s32)vm->wait < 1) {
    vm->wait = 0;
    return FALSE;
  }

  vm->wait--;
  return TRUE;
}

static bool32 Cmd_time(struct VM* vm) {
  vm->time = vm->pc->work;
  return FALSE;
}

static bool32 Cmd_nop(struct VM* _ UNUSED) {
  // nop
  return FALSE;
}

// カメラの設定を一括で行う
static bool32 Cmd_resetcamera(struct VM* vm) {
  struct Entity* p;
  struct CameraTemplate* t = (struct CameraTemplate*)vm->pc->work;
  struct Camera* camera = &gStageRun.vm.camera;
  if (camera->mode == 0) {
    RestoreBackground();
  }
  LoadCameraTemplate(camera, t);
  if (t->mode != 1) {
    struct ScriptEntity* se = &vm->entities[t->unk_02];
    p = se->entity;
    if (p != NULL) {
      camera->zero = &p->coord;
      if (t->chaseMode & (1 << 3)) {
        (camera->target).x = (p->coord).x;
        (camera->target).y = (p->coord).y;
      }
    }
  }
  return FALSE;
}

/*
カメラの微調整

type:
  00:
  01:
  02:
  03: カメラのX座標セット
  04: カメラのY座標セット
*/
static bool32 Cmd_modifycamera(struct VM* vm) {
  struct Camera* camera = &gStageRun.vm.camera;
  switch (vm->pc->status) {
    case 0: {
      SetCameraMode(camera, vm->pc->work);
      break;
    }
    case 1: {
      camera->chaseMode = (u8)vm->pc->work;
      camera->unk_22 = 0;
      break;
    }
    case 2: {
      if (camera->mode != 1) {
        struct ScriptEntity* s = &(vm->entities[(vm->pc)->work]);
        struct Entity* z = s->entity;
        if (z != NULL) {
          camera->zero = &z->coord;
        }
      }
      break;
    }
    case 3: {
      camera->target.x = vm->pc->work;
      break;
    }
    case 4: {
      camera->target.y = vm->pc->work;
      break;
    }
    case 5: {
      camera->forceScrollSpeed.x = vm->pc->work;
      break;
    }
    case 6: {
      camera->forceScrollSpeed.y = vm->pc->work;
      break;
    }
    case 7: {
      camera->unk_left = vm->pc->work;
      break;
    }
    case 8: {
      camera->unk_right = vm->pc->work;
      break;
    }
    case 9: {
      camera->unk_top = vm->pc->work;
      break;
    }
    case 10: {
      camera->unk_bottom = vm->pc->work;
      break;
    }
    case 11: {
      camera->left = vm->pc->work;
      break;
    }
    case 12: {
      camera->right = vm->pc->work;
      break;
    }
    case 13: {
      camera->top = vm->pc->work;
      break;
    }
    case 14: {
      camera->bottom = vm->pc->work;
      break;
    }
    case 15: {
      camera->chaseMode |= (1 << 3);
      camera->unk_22 = 0;
      break;
    }
    case 16: {
      SetCameraMode(camera, 0);
      SaveDispRegister();
      gVideoRegBuffer.dispcnt &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
      break;
    }
    case 17: {
      SetCameraMode(camera, 6);
      RestoreBackground();
      break;
    }
  }
  return FALSE;
}

NAKED static bool32 Cmd_cmd06(struct VM* vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	adds r2, r0, #0\n\
	ldr r7, [r2, #0xc]\n\
	movs r1, #2\n\
	ldrsh r0, [r7, r1]\n\
	cmp r0, #6\n\
	bls _080225C6\n\
	b _08022800\n\
_080225C6:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080225D0 @ =_080225D4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080225D0: .4byte _080225D4\n\
_080225D4: @ jump table\n\
	.4byte _080225F0 @ case 0\n\
	.4byte _08022640 @ case 1\n\
	.4byte _08022660 @ case 2\n\
	.4byte _08022700 @ case 3\n\
	.4byte _08022778 @ case 4\n\
	.4byte _0802279A @ case 5\n\
	.4byte _080227A8 @ case 6\n\
_080225F0:\n\
	ldr r1, _08022634 @ =gVideoRegBuffer+6\n\
	movs r2, #0xa1\n\
	lsls r2, r2, #2\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r0, r1, #0\n\
	adds r0, #0xa\n\
	movs r4, #0\n\
	str r4, [r0]\n\
	subs r1, #6\n\
	ldrh r2, [r1]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	adds r0, r3, #0\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r5, _08022638 @ =0x08547280\n\
	adds r0, r0, r5\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _0802263C @ =0x0854728C\n\
	adds r0, r0, r1\n\
	b _08022746\n\
	.align 2, 0\n\
_08022634: .4byte gVideoRegBuffer+6\n\
_08022638: .4byte gGraphic_Capcom\n\
_0802263C: .4byte gPalette_Capcom\n\
_08022640:\n\
	ldr r2, _08022658 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _0802265C @ =0x0000EDFF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	bl ResumeAllBlinks\n\
	b _08022800\n\
	.align 2, 0\n\
_08022658: .4byte gVideoRegBuffer\n\
_0802265C: .4byte 0x0000EDFF\n\
_08022660:\n\
	ldr r4, _080226E4 @ =gVideoRegBuffer+6\n\
	ldr r5, _080226E8 @ =0x00008284\n\
	adds r0, r5, #0\n\
	strh r0, [r4]\n\
	movs r3, #0\n\
	strh r3, [r4, #0xa]\n\
	movs r0, #0xa0\n\
	strh r0, [r4, #0xc]\n\
	subs r2, r4, #6\n\
	ldrh r0, [r2]\n\
	movs r5, #0x90\n\
	lsls r5, r5, #5\n\
	adds r1, r5, #0\n\
	orrs r0, r1\n\
	movs r6, #0\n\
	orrs r0, r3\n\
	ldr r1, _080226EC @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _080226F0 @ =0x08547280\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r2, _080226F4 @ =0x0854728C\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r5, _080226F8 @ =gBgMapOffsets\n\
	ldrb r2, [r7, #1]\n\
	str r6, [sp]\n\
	movs r0, #0x12\n\
	adds r1, r5, #0\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldrh r1, [r4]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #5\n\
	ands r0, r1\n\
	lsls r0, r0, #3\n\
	ldr r3, _080226FC @ =0x06000800\n\
	adds r0, r0, r3\n\
	ldrb r2, [r7, #1]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r6, [sp]\n\
	adds r1, r5, #0\n\
	movs r3, #0\n\
	bl loadBgMap_08004248\n\
	bl PauseAllBlinks\n\
	b _08022800\n\
	.align 2, 0\n\
_080226E4: .4byte gVideoRegBuffer+6\n\
_080226E8: .4byte 0x00008284\n\
_080226EC: .4byte 0x0000FEFF\n\
_080226F0: .4byte gGraphic_Capcom\n\
_080226F4: .4byte gPalette_Capcom\n\
_080226F8: .4byte gBgMapOffsets\n\
_080226FC: .4byte 0x06000800\n\
_08022700:\n\
	ldr r2, _08022760 @ =gVideoRegBuffer+6\n\
	ldr r4, _08022764 @ =0x00008284\n\
	adds r0, r4, #0\n\
	strh r0, [r2]\n\
	movs r3, #0\n\
	strh r3, [r2, #0xa]\n\
	movs r0, #0x60\n\
	strh r0, [r2, #0xc]\n\
	subs r2, #6\n\
	ldrh r0, [r2]\n\
	movs r5, #0x90\n\
	lsls r5, r5, #5\n\
	adds r1, r5, #0\n\
	orrs r0, r1\n\
	movs r4, #0\n\
	orrs r0, r3\n\
	ldr r1, _08022768 @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _0802276C @ =0x08547280\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r2, _08022770 @ =0x0854728C\n\
	adds r0, r0, r2\n\
_08022746:\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _08022774 @ =gBgMapOffsets\n\
	ldrb r2, [r7, #1]\n\
	str r4, [sp]\n\
	movs r0, #0x12\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	bl PauseAllBlinks\n\
	b _08022800\n\
	.align 2, 0\n\
_08022760: .4byte gVideoRegBuffer+6\n\
_08022764: .4byte 0x00008284\n\
_08022768: .4byte 0x0000FEFF\n\
_0802276C: .4byte gGraphic_Capcom\n\
_08022770: .4byte gPalette_Capcom\n\
_08022774: .4byte gBgMapOffsets\n\
_08022778:\n\
	ldr r1, _08022790 @ =gVideoRegBuffer+18\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08022794\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	ldr r0, [r2, #0xc]\n\
	subs r0, #8\n\
	str r0, [r2, #0xc]\n\
	movs r0, #1\n\
	b _08022802\n\
	.align 2, 0\n\
_08022790: .4byte gVideoRegBuffer+18\n\
_08022794:\n\
	bl text_080e9730\n\
	b _08022800\n\
_0802279A:\n\
	ldr r1, _080227A4 @ =gPaletteManager\n\
	ldr r0, [r7, #4]\n\
	strh r0, [r1]\n\
	b _08022800\n\
	.align 2, 0\n\
_080227A4: .4byte gPaletteManager\n\
_080227A8:\n\
	ldr r1, _0802280C @ =gVideoRegBuffer+6\n\
	movs r3, #0x81\n\
	lsls r3, r3, #2\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r0, r1, #0\n\
	adds r0, #0xa\n\
	movs r4, #0\n\
	str r4, [r0]\n\
	subs r1, #6\n\
	ldrh r2, [r1]\n\
	movs r5, #0x90\n\
	lsls r5, r5, #5\n\
	adds r0, r5, #0\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, _08022810 @ =0x08547280\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldrb r1, [r7, #1]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r2, _08022814 @ =0x0854728C\n\
	adds r0, r0, r2\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _08022818 @ =gBgMapOffsets\n\
	ldrb r2, [r7, #1]\n\
	str r4, [sp]\n\
	movs r0, #0x12\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	bl PauseAllBlinks\n\
_08022800:\n\
	movs r0, #0\n\
_08022802:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0802280C: .4byte gVideoRegBuffer+6\n\
_08022810: .4byte gGraphic_Capcom\n\
_08022814: .4byte gPalette_Capcom\n\
_08022818: .4byte gBgMapOffsets\n\
 .syntax divided\n");
}

static bool32 Cmd_resume(struct VM* vm) {
  if (vm->pc->status == 0) {
    struct Zero* z = (struct Zero*)vm->entities[0].entity;
    struct Camera* camera = &gStageRun.vm.camera;
    if (camera->mode == 0) {
      RestoreBackground();
      SetCameraMode(camera, 6);
      camera->chaseMode = (1 << 3);
      camera->unk_22 = 0;
    }
    camera->zero = &(z->s).coord;
    camera->viewport.x = (z->s).coord.x;
    camera->viewport.y = (z->s).coord.y;
    camera->unk_left = 0;
    camera->unk_top = 0;
    gCollisionManager.disabled &= 0x7F;
    gCollisionManager.sweep = 0;
  } else {
    gCollisionManager.disabled &= 0x7F;
    gCollisionManager.sweep = 0;
  }

  return FALSE;
}

static bool32 Cmd_cmd08(struct VM* vm) {
  if (vm->pc->status != 0) {
    if ((gStageRun.vm.active & vm->pc->work) != 0) {
      return FALSE;
    }
  } else if ((gStageRun.vm.active & vm->pc->work) == 0) {
    return FALSE;
  }
  vm->pc--;
  return TRUE;
}

/*
status:
  0: プレイヤーのキー入力を無効に
  1: キー入力への干渉をやめる
  2: プレイヤーのキー入力を無効にし、valで指定したキー入力を強制する
*/
static bool32 Cmd_disablekeyinput(struct VM* vm) {
  switch ((vm->pc)->status) {
    case 0: {
      vm->forcedKey = INPUT_DISABLED;
      break;
    }
    case 1: {
      vm->forcedKey = 0;
      break;
    }
    case 2: {
      vm->forcedKey = ((vm->pc)->work) | INPUT_DISABLED;
      break;
    }
  }
  return FALSE;
}

static bool32 Cmd_loadgraphic(struct VM* vm) {
  u32 n = *((s16*)&vm->pc->work);
  LOAD_STATIC_GRAPHIC(n);
  return FALSE;
}

static bool32 Cmd_spawn(struct VM* vm) {
  struct Command* pc = vm->pc;
  u8 idx = pc->status;
  CreateScriptEntity(idx, (struct ScriptEntityTemplate*)pc->work);

  // create Zero
  if ((vm->pc->val2 == 0) && (idx == 0)) {
    struct Zero* z = (struct Zero*)vm->entities[0].entity;
    s32 y = FUN_08009f6c((z->s).coord.x, (z->s).coord.y);
    (z->s).coord.y = y;
  }
  return FALSE;
}

NAKED static bool32 Cmd_cmd0c(struct VM* vm) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r2, r0, #0\n\
	ldr r4, [r2, #0xc]\n\
	ldrb r0, [r4, #1]\n\
	lsls r0, r0, #4\n\
	adds r0, #0x10\n\
	adds r5, r2, r0\n\
	ldr r3, [r5]\n\
	cmp r3, #0\n\
	bne _080229C2\n\
	b _08022ABE\n\
_080229C2:\n\
	movs r1, #2\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #7\n\
	bhi _08022ABE\n\
	lsls r0, r0, #2\n\
	ldr r1, _080229D4 @ =_080229D8\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080229D4: .4byte _080229D8\n\
_080229D8: @ jump table\n\
	.4byte _080229F8 @ case 0\n\
	.4byte _08022A06 @ case 1\n\
	.4byte _08022A20 @ case 2\n\
	.4byte _08022A5C @ case 3\n\
	.4byte _08022A9E @ case 4\n\
	.4byte _08022AA8 @ case 5\n\
	.4byte _08022AB2 @ case 6\n\
	.4byte _08022ABA @ case 7\n\
_080229F8:\n\
	ldr r0, [r4, #4]\n\
	ldr r0, [r0]\n\
	str r0, [r3, #0x54]\n\
	ldr r0, [r4, #4]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r3, #0x58]\n\
	b _08022ABE\n\
_08022A06:\n\
	ldr r1, [r4, #4]\n\
	lsls r1, r1, #4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	cmp r1, #0\n\
	beq _08022ABE\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r3, #0x54]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r3, #0x58]\n\
	b _08022ABE\n\
_08022A20:\n\
	ldr r0, [r4, #4]\n\
	cmp r0, #0\n\
	beq _08022A2E\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _08022A34\n\
_08022A2E:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_08022A34:\n\
	strb r0, [r3, #0xa]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08022ABE\n\
	ldr r0, [r4, #4]\n\
	movs r2, #1\n\
	ands r0, r2\n\
	adds r1, r3, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	ldr r1, [r4, #4]\n\
	adds r3, #0x4a\n\
	ands r1, r2\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	b _08022A96\n\
_08022A5C:\n\
	ldr r0, [r4, #4]\n\
	cmp r0, #0\n\
	beq _08022A6A\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0x20\n\
	orrs r0, r1\n\
	b _08022A70\n\
_08022A6A:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xdf\n\
	ands r0, r1\n\
_08022A70:\n\
	strb r0, [r3, #0xa]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08022ABE\n\
	ldr r0, [r4, #4]\n\
	movs r2, #1\n\
	ands r0, r2\n\
	adds r1, r3, #0\n\
	adds r1, #0x4d\n\
	strb r0, [r1]\n\
	ldr r1, [r4, #4]\n\
	adds r3, #0x4a\n\
	ands r1, r2\n\
	lsls r1, r1, #5\n\
	ldrb r2, [r3]\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
_08022A96:\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	b _08022ABE\n\
_08022A9E:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	b _08022ABE\n\
_08022AA8:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r3, #0xa]\n\
	b _08022ABE\n\
_08022AB2:\n\
	ldrb r0, [r4, #1]\n\
	bl DeleteScriptEntity\n\
	b _08022ABE\n\
_08022ABA:\n\
	movs r0, #0\n\
	str r0, [r5]\n\
_08022ABE:\n\
	movs r0, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool32 Cmd_cmd0d(struct VM* vm) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	ldr r4, [r3, #0xc]\n\
	ldr r1, [r4, #4]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08022B20\n\
	movs r5, #1\n\
	ands r1, r5\n\
	cmp r1, #0\n\
	beq _08022B00\n\
	ldr r0, _08022AFC @ =gCurStory\n\
	ldrh r3, [r4, #2]\n\
	lsls r2, r3, #0x10\n\
	asrs r2, r2, #0x13\n\
	adds r0, #4\n\
	adds r2, r2, r0\n\
	movs r1, #7\n\
	ands r1, r3\n\
	adds r0, r5, #0\n\
	lsls r0, r1\n\
	ldrb r1, [r2]\n\
	orrs r0, r1\n\
	b _08022B18\n\
	.align 2, 0\n\
_08022AFC: .4byte gCurStory\n\
_08022B00:\n\
	ldr r0, _08022B1C @ =gCurStory\n\
	ldrh r1, [r4, #2]\n\
	lsls r2, r1, #0x10\n\
	asrs r2, r2, #0x13\n\
	adds r0, #4\n\
	adds r2, r2, r0\n\
	movs r0, #7\n\
	ands r0, r1\n\
	adds r1, r5, #0\n\
	lsls r1, r0\n\
	ldrb r0, [r2]\n\
	bics r0, r1\n\
_08022B18:\n\
	strb r0, [r2]\n\
	b _08022B48\n\
	.align 2, 0\n\
_08022B1C: .4byte gCurStory\n\
_08022B20:\n\
	ldrb r0, [r4, #1]\n\
	lsls r2, r0, #4\n\
	adds r0, r3, #0\n\
	adds r0, #0x10\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _08022B48\n\
	cmp r1, #0\n\
	beq _08022B3E\n\
	adds r2, r3, r2\n\
	ldrb r1, [r4, #2]\n\
	ldrb r0, [r2, #0x19]\n\
	orrs r0, r1\n\
	b _08022B46\n\
_08022B3E:\n\
	adds r2, r3, r2\n\
	ldrb r1, [r4, #2]\n\
	ldrb r0, [r2, #0x19]\n\
	bics r0, r1\n\
_08022B46:\n\
	strb r0, [r2, #0x19]\n\
_08022B48:\n\
	movs r0, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static bool32 Cmd_cmd0e(struct VM* vm) {
  struct Command* c = vm->pc;
  if (vm->entities[c->status].entity != NULL) {
    (vm->entities[c->status].unk_0A)[c->val2] = (u16)c->work;
  }
  return FALSE;
}

static bool32 Cmd_cmd0f(struct VM* vm) {
  const u8 n = vm->pc->status;
  if (vm->entities[n].entity != NULL) {
    struct Entity* p = vm->entities[vm->pc->val2].entity;
    if (p != NULL) {
      vm->entities[n].unk_04 = p;
    }
  }
  return FALSE;
}

static bool32 Cmd_emergency(struct VM* vm) {
  switch (vm->pc->status) {
    case 0: {
      vm->emergency = (u16)(vm->pc->work) | 0x8000;
      break;
    }
    case 1: {
      vm->emergency |= 0x4000;
      break;
    }
  }
  return FALSE;
}

static bool32 Cmd_quake(struct VM* vm) {
  struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      vm->magnitude = (u16)pc->work | 0x8000;
      break;
    }
    case 1: {
      vm->magnitude = 0;
      break;
    }
    case 2: {
      AppendQuake(*(u8*)&pc->work, &gStageRun.vm.camera.viewport);
      break;
    }
  }
  return FALSE;
}

// びっくりマークなどの吹き出し(Emotion Bubble)を出す
static bool32 Cmd_emotion(struct VM* vm) {
  struct Entity* e;
  struct Coord coord;
  struct Command12* c = (struct Command12*)vm->pc;
  u16 kind = c->kind;
  coord.x = ((s32)c->x) << 8;
  coord.y = ((s32)c->y) << 8;
  e = vm->entities[c->idx].entity;
  if (e != NULL) {
    CreateEmotionBubble(kind, &e->coord, &coord);
  }
  return FALSE;
}

// Scroll text like Prologue (プロローグなど、スクロールするテキスト字幕)
NAKED static bool32 Cmd_scroll(struct VM* vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0xc]\n\
	ldrb r3, [r0, #1]\n\
	cmp r3, #1\n\
	beq _08022CB4\n\
	cmp r3, #1\n\
	bgt _08022C94\n\
	cmp r3, #0\n\
	beq _08022C9A\n\
	b _08022DE0\n\
_08022C94:\n\
	cmp r3, #2\n\
	beq _08022D38\n\
	b _08022DE0\n\
_08022C9A:\n\
	ldr r0, _08022CB0 @ =gVideoRegBuffer\n\
	ldrh r2, [r0]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #1\n\
	adds r1, r5, #0\n\
	orrs r1, r2\n\
	strh r1, [r0]\n\
	strh r3, [r0, #0xc]\n\
	strh r3, [r0, #0xe]\n\
	strh r3, [r4, #6]\n\
	b _08022DE0\n\
	.align 2, 0\n\
_08022CB0: .4byte gVideoRegBuffer\n\
_08022CB4:\n\
	adds r0, r4, #0\n\
	adds r0, #0xd0\n\
	ldr r0, [r0]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08022CC8\n\
	ldrh r0, [r4, #6]\n\
	adds r0, #1\n\
	strh r0, [r4, #6]\n\
_08022CC8:\n\
	ldr r3, _08022D04 @ =0x0200214E\n\
	ldrh r0, [r4, #6]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	strh r1, [r3]\n\
	ldrh r1, [r4, #6]\n\
	ldr r2, [r4, #0xc]\n\
	ldr r0, [r2, #4]\n\
	cmp r1, r0\n\
	blo _08022CDE\n\
	b _08022DD0\n\
_08022CDE:\n\
	lsrs r5, r1, #4\n\
	adds r3, r5, #0\n\
	cmp r3, #9\n\
	bhi _08022D10\n\
	ldr r1, _08022D08 @ =StringOfsTable\n\
	movs r6, #2\n\
	ldrsh r0, [r2, r6]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _08022D0C @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r2, #0xa\n\
	subs r2, r2, r3\n\
	lsls r2, r2, #1\n\
	adds r1, r5, #1\n\
	str r1, [sp]\n\
	movs r1, #0\n\
	b _08022D84\n\
	.align 2, 0\n\
_08022D04: .4byte 0x0200214E\n\
_08022D08: .4byte StringOfsTable\n\
_08022D0C: .4byte gStringData\n\
_08022D10:\n\
	ldr r1, _08022D30 @ =StringOfsTable\n\
	movs r3, #2\n\
	ldrsh r0, [r2, r3]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _08022D34 @ =gStringData\n\
	adds r0, r0, r1\n\
	adds r3, r5, #0\n\
	subs r3, #0xa\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r1, r5, #1\n\
	str r1, [sp]\n\
	movs r1, #0\n\
	b _08022DB6\n\
	.align 2, 0\n\
_08022D30: .4byte StringOfsTable\n\
_08022D34: .4byte gStringData\n\
_08022D38:\n\
	adds r0, r4, #0\n\
	adds r0, #0xd0\n\
	ldr r0, [r0]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08022D4C\n\
	ldrh r0, [r4, #6]\n\
	adds r0, #1\n\
	strh r0, [r4, #6]\n\
_08022D4C:\n\
	ldr r3, _08022D8C @ =0x0200214E\n\
	ldrh r0, [r4, #6]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	strh r1, [r3]\n\
	ldrh r1, [r4, #6]\n\
	ldr r2, [r4, #0xc]\n\
	ldr r0, [r2, #4]\n\
	cmp r1, r0\n\
	bhs _08022DD0\n\
	lsrs r5, r1, #4\n\
	adds r3, r5, #0\n\
	cmp r3, #9\n\
	bhi _08022D98\n\
	ldr r1, _08022D90 @ =StringOfsTable\n\
	movs r6, #2\n\
	ldrsh r0, [r2, r6]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _08022D94 @ =gStringData\n\
	adds r0, r0, r1\n\
	movs r2, #0xa\n\
	subs r2, r2, r3\n\
	lsls r2, r2, #1\n\
	adds r1, r5, #1\n\
	str r1, [sp]\n\
	movs r1, #6\n\
_08022D84:\n\
	movs r3, #0\n\
	bl PrintRows\n\
	b _08022DBC\n\
	.align 2, 0\n\
_08022D8C: .4byte 0x0200214E\n\
_08022D90: .4byte StringOfsTable\n\
_08022D94: .4byte gStringData\n\
_08022D98:\n\
	ldr r1, _08022DC8 @ =StringOfsTable\n\
	movs r3, #2\n\
	ldrsh r0, [r2, r3]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, _08022DCC @ =gStringData\n\
	adds r0, r0, r1\n\
	adds r3, r5, #0\n\
	subs r3, #0xa\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	adds r1, r5, #1\n\
	str r1, [sp]\n\
	movs r1, #6\n\
_08022DB6:\n\
	movs r2, #0\n\
	bl PrintRows\n\
_08022DBC:\n\
	ldr r0, [r4, #0xc]\n\
	subs r0, #8\n\
	str r0, [r4, #0xc]\n\
	movs r0, #1\n\
	b _08022DE2\n\
	.align 2, 0\n\
_08022DC8: .4byte StringOfsTable\n\
_08022DCC: .4byte gStringData\n\
_08022DD0:\n\
	adds r2, r3, #0\n\
	subs r2, #0xe\n\
	ldrh r0, [r2]\n\
	ldr r1, _08022DEC @ =0x0000FEFF\n\
	ands r1, r0\n\
	movs r0, #0\n\
	strh r1, [r2]\n\
	strh r0, [r3]\n\
_08022DE0:\n\
	movs r0, #0\n\
_08022DE2:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08022DEC: .4byte 0x0000FEFF\n\
 .syntax divided\n");
}

/*
status:
  0:       ScreenEffect が NONE　になるまで待つ
  それ以外: ScreenEffect に status をセット
*/
static bool32 Cmd_screeneffect(struct VM* vm) {
  struct Command* c = vm->pc;
  if (c->status == 0) {
    if (vm->screenEffect != NO_SCREEN_EFFECT) {
      vm->pc = c - 1;
      return TRUE;
    }
  } else {
    vm->screenEffect = c->status;
    if (vm->screenEffect & (1 << 3)) {
      *(u16*)(&gPaletteManager.buf[0]) = 0;
    }
  }
  return FALSE;
}

static bool32 Cmd_rune(struct VM* vm) {
  struct Command* c = vm->pc;
  if (c->work == 0) {
    *(u32*)&vm->rune = 0;
    gVideoRegBuffer.dispcnt &= 0xFEFF;
  } else {
    *(u32*)&vm->rune = ((c->work & 0xFFFF) | ((u32)c->status << 16) | ((u32)c->val2 << 24));
    gVideoRegBuffer.dispcnt |= DISPCNT_BG0_ON;
  }
  return FALSE;
}

/*
残機数を示すコマンド
レジスタンスベースによるステージへの転送時、リトライ時などに実行される
*/
static bool32 Cmd_indicator(struct VM* vm) {
  struct VFX* indicator;
  struct Boss* boss = (struct Boss*)vm->entities[1].entity;
  struct Command* pc = vm->pc;

  if (pc->status == 0) {
    if (vm->indicator == NULL) {
      return FALSE;
    }
    goto _REDO;
  }
  if (gVFXHeaderPtr->remaining == 0) {
  _REDO:
    vm->pc = pc - 1;
    return TRUE;
  }

  // Remove old indicator
  indicator = vm->indicator;
  if (indicator != NULL) {
    (indicator->s).flags &= ~DISPLAY;
    (indicator->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(indicator, ENTITY_DISAPPEAR);
  }

  switch (vm->pc->status - 1) {
    case 0: {
      if (!IS_MISSION) {
        vm->indicator = CreateExlifeIndicator((gMission.unk_00)->extraLife);
        PlaySound(SE_CUTSCENE);
        break;
      }

      if (vm->pc->val2 == 2) {
        PlaySound(SE_MISSION_VOICE);
      } else {
        PlaySound(SE_CUTSCENE);
      }
      vm->indicator = CreateMissionAlert(0);
      if (vm->pc->val2 == 3) {
        break;
      }
      CreateExlifeIndicator((gMission.unk_00)->extraLife);
      break;
    }

    case 1:
    case 5: {
      if ((gMission.unk_00)->extraLife != 0) {
        if (IS_MISSION) {
          vm->indicator = CreateMissionAlert(1);
          break;
        }
        vm->indicator = NULL;
        break;
      }
      vm->indicator = CreateMissionAlert(4);
      break;
    }

    case 2: {
      vm->indicator = CreateMissionAlert(2);
      PlaySound(SE_CUTSCENE);
      break;
    }

    case 3: {
      PlaySound(SE_CAUTION);
      if (boss != NULL) {
        gHUD.unk_0c = (struct Entity*)boss;
      }
      vm->indicator = CreateMissionAlert(3);
      break;
    }
  }

  return FALSE;
}

/*
status:
  0: メッセージの描画 (val = TextID)
  1:
  2: Message.modeが特定の値になるまで待機
  3:
  4: ゼロがボス戦で死んだとき用のメッセージを描画(メッセージタイプ指定可能)
  5: ゼロがボス戦で死んだとき用のメッセージを描画
  6:
  7: メッセージを強制終了
*/
static bool32 Cmd_message(struct VM* vm) {
  switch (vm->pc->status) {
    case 0: {
      PrintTextWindow(*(TextID*)&(vm->pc->work), (u16)vm->pc->val2);
      break;
    }
    case 1: {
      if (gCurStory.s.f0 & STORY_DEMO) {
        PrintTextWindow(*(TextID*)&vm->pc->work, 0x50);
        break;
      }
      if (vm->pc->val2 == 0) {
        PrintNormalMessage(*(TextID*)&vm->pc->work);
      } else {
        PrintOptionMessage2(*(TextID*)&vm->pc->work);
      }
      break;
    }
    case 2: {
      if (vm->pc->val2 == 0) {
        if ((&gTextWindow.text)->mode != 0) {
          vm->pc--;
          return TRUE;
        }
      } else if (((&gTextWindow.text)->mode != 0) && ((&gTextWindow.text)->mode != TEXT_MODE_OPTION)) {
        vm->pc--;
        return TRUE;
      }
      break;
    }
    case 3: {
      vm->zeroDeathTextIDs[vm->pc->val2] = vm->pc->work;
      break;
    }
    case 4: {
      if (vm->zeroDeathTextIDs[vm->pc->val2] != 0xFFFF) {
        PrintTextWindow(vm->zeroDeathTextIDs[vm->pc->val2], *(u16*)&vm->pc->work);
        vm->zeroDeathTextIDs[vm->pc->val2] = 0xFFFF;
      }
      break;
    }
    case 5: {
      if (vm->zeroDeathTextIDs[vm->pc->val2] != 0xFFFF) {
        PrintNormalMessage(vm->zeroDeathTextIDs[vm->pc->val2]);
        vm->zeroDeathTextIDs[vm->pc->val2] = 0xFFFF;
      }
      break;
    }
    case 6: {
      vm->zeroDeathTextIDs[vm->pc->val2] = 0xFFFF;
      break;
    }
    case 7: {
      (&gTextWindow.text)->flag |= (1 << 1);
      break;
    }
  }
  return FALSE;
}

/*
status:
 0: 今のBGMを止めて新しいBGM(val)を流す
 1: BGMをなくす
 2: BGMが終わるまで待機(このコマンドを再度やり直す)
*/
static bool32 Cmd_bgm(struct VM* vm) {
  struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      if (vm->bgm != MUS_NONE) {
        fadeoutBGM(vm->bgm & 0xFFFF);
      }
      playBGM(*(u16*)&vm->pc->work);
      vm->bgm = vm->pc->work;
      break;
    }

    case 1: {
      if (vm->bgm != MUS_NONE) {
        fadeoutBGM(vm->bgm & 0xFFFF);
        vm->bgm = MUS_NONE;
      }
      break;
    }

    case 2: {
      if (vm->bgm != MUS_NONE) {
        if (_isSoundPlaying(vm->bgm)) {
          vm->pc--;
          return TRUE;
        }
      }
      break;
    }
  }
  return FALSE;
}

/*
status:
 0: コマンドで指定したSEを流す
 1: コマンドで指定したSEを止める
 2: コマンドで指定したSEをフェードアウトさせる(val4=SoundID)
*/
static bool32 Cmd_se(struct VM* vm) {
  struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      PlaySound(pc->work);
      break;
    }
    case 1: {
      stopSound(pc->work);
      break;
    }
    case 2: {
      fadeoutSound(pc->work, pc->val2);
      break;
    }
    default: {
      break;
    }
  }
  return FALSE;
}

/*
ゼロにアクションを強制させる
status:
 00: ゼロの座標を強制的に移動 & 固定
 01: ゼロの座標固定を解除
 02: ゼロを仁王立ちさせる
 03:
 04:
 05:
 06:
 07:
 08:
 09: ゼロを指定した座標まで歩いて移動させる
 10: テレポートしてきたモーションさせる
 11:
 12: セイバー以外の武器を禁止 オメガにトドメさすとき？
 13: エルフのポジションをリセット
*/
static bool32 Cmd_force(struct VM* vm) {
  struct Command* pc;
  struct Zero* z = (struct Zero*)vm->entities[0].entity;
  if ((vm->pc)->status == 12) {
    (&gGameState.save.status)->mainWeapon = WEAPON_SABER;
    (&gGameState.save.status)->subWeapon = WEAPON_SABER;
  }
  if (z != NULL) {
    switch ((vm->pc)->status) {
      case 0: {
        (vm->forceCoord).x = (z->s).coord.x;
        (vm->forceCoord).y = (z->s).coord.y;
        break;
      }
      case 1: {
        (vm->forceCoord).x = (vm->forceCoord).y = -1;
        break;
      }
      case 2: {
        (z->s).mode[1] = ZERO_TALK;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 0;
        break;
      }
      case 3: {
        gInChat = FALSE;
        break;
      }
      case 4: {
        (z->s).mode[1] = ZERO_TELEPORT;
        (z->s).mode[2] = 0;
        (z->s).mode[3] = 2;
        break;
      }
      case 5: {
        gInTransport = TRUE;
        (z->s).mode[1] = ZERO_TELEPORT;
        (z->s).mode[2] = 3;
        (z->s).mode[3] = 0;
        PlaySound(SE_TENSOU);
        break;
      }
      case 6: {
        (z->s).mode[1] = ZERO_TELEPORT;
        (z->s).mode[2] = 4;
        (z->s).mode[3] = 0;
        gInTransport = FALSE;
        PlaySound(SE_TENSOU);
        break;
      }
      case 7: {
        if ((z->s).mode[1] != ZERO_GROUND) {
          vm->pc--;
          return TRUE;
        }
        break;
      }
      case 8: {
        if ((*(u32*)((z->s).mode) & 0xFFFF00) != 0) {
          vm->pc--;
          return TRUE;
        }
        break;
      }
      case 9: {
        const s32 d = (z->s).coord.x - vm->pc->work;
        if (d < -PIXEL(2)) {
          vm->forcedKey = INPUT_DISABLED | DPAD_RIGHT;
          vm->pc--;
          return TRUE;
        } else if (d > PIXEL(2)) {
          vm->forcedKey = INPUT_DISABLED | DPAD_LEFT;
          vm->pc--;
          return TRUE;
        }
        (z->s).coord.x = vm->pc->work;
        vm->forcedKey = INPUT_DISABLED;
        break;
      }
      case 10: {
        (z->s).mode[1] = ZERO_CYBER;
        (z->s).mode[2] = 2;
        (z->s).mode[3] = 0;
        break;
      }
      case 11: {
        z->inCyberSpace = TRUE;
        break;
      }
      case 12: {
        ((&z->unk_b4)->status).mainWeapon = WEAPON_SABER;
        ((&z->unk_b4)->status).subWeapon = WEAPON_SABER;
        break;
      }
      case 13: {
        resetSateliteElfPosition(z);
        break;
      }
      case 14: {
        (z->s).mode[1] = ZERO_GROUND;
        (z->s).mode[2] = 3;  // Bike
        (z->s).mode[3] = 0;
        gInTransport = FALSE;
        break;
      }
    }
  }
  return FALSE;
}

static bool32 Cmd_cmd1b(struct VM* vm) {
  const struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      ExitStageLandscape();
      ResetLandscape(vm->pc->val2, &gOverworld.unk_1c8.viewport);
      break;
    }

    case 1: {
      gOverworld.unk_1c8.work[pc->val2] = (u8)pc->work;
      break;
    }
  }

  return FALSE;
}

static bool32 Cmd_cmd1c(struct VM* vm) {
  const struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      gStageEntityManager.unk_20e |= (1 << 0);
      break;
    }
    case 1: {
      gStageEntityManager.unk_20e &= ~(1 << 0);
      break;
    }
    case 2: {
      FUN_080186c8(pc->work, gStageEntityManager.dynamicEntityRange[1]);
      break;
    }
    case 3: {
      FUN_080186c8(gStageEntityManager.dynamicEntityRange[0], pc->work);
      break;
    }
  }
  return FALSE;
}

static bool32 Cmd_sweep(struct VM* vm) {
  switch (vm->pc->status) {
    case 0: {
      gCollisionManager.sweep |= (1 << 1);
      break;
    }

    case 1: {
      gCollisionManager.sweep = 0;
      break;
    }

    case 2: {
      gCollisionManager.disabled |= (1 << 7);
      break;
    }

    case 3: {
      gCollisionManager.disabled &= ~(1 << 7);
      break;
    }
  }

  return FALSE;
}

static bool32 Cmd_lockmenu(struct VM* vm) {
  switch (vm->pc->status) {
    case 0: {
      gStageRun.missionStatus |= DISABLE_MENU;
      break;
    }

    case 1: {
      gStageRun.missionStatus &= ~DISABLE_MENU;
      break;
    }
  }

  return FALSE;
}

static bool32 Cmd_eventflag(struct VM* vm) {
  struct Command* pc = vm->pc;
  switch (pc->status) {
    case 0: {
      vm->unk_003 = pc->val2;
      if (!IsDemoplay()) {
        s32 flags = gSystemSavedataManager.flags[vm->unk_003 >> 3];
        u8 idx = vm->unk_003 & 7;
        if ((flags >> idx) & 1) {
          gStageRun.missionStatus |= EVENT_SCENE;
        }
      }
      break;
    }
    case 1: {
      s32 flags = gSystemSavedataManager.flags[vm->unk_003 >> 3];
      u8 idx = vm->unk_003 & 7;
      if (((flags >> idx) & 1) == 0) {
        gSystemSavedataManager.flags[vm->unk_003 >> 3] |= (1 << idx);
        SaveSystemData();
      }
      gStageRun.missionStatus &= ~EVENT_SCENE;
      break;
    }
  }
  return FALSE;
}

static bool32 Cmd_cmd20(struct VM* vm) {
  LOAD_STATIC_GRAPHIC(0);
  LOAD_STATIC_GRAPHIC(3);
  LOAD_STATIC_GRAPHIC(209);
  FUN_080251a8();
  return FALSE;
}

static bool32 Cmd_drop(struct VM* vm) {
  const struct Command* pc = vm->pc;
  struct ScriptEntity* se = &vm->entities[pc->work];
  struct Entity* e = se->entity;
  if (pc->status == 0) {
    TryDropItem(pc->val2, (struct Coord*)pc->work);
  } else if (e != NULL) {
    TryDropItem(pc->val2, &e->coord);
  }
  return FALSE;
}

/*
status:
  0: リザルトの前処理
  1: リザルト処理(完了までには result_0802400c を何回も行っている)
*/
static bool32 Cmd_missionresult(struct VM* vm) {
  const struct Command* pc = vm->pc;
  if (pc->status == 0) {
    prepareResultScreen(&gGameState.sceneState.result);
  } else {
    bool32 redo = result_0802400c(&gGameState.sceneState.result);
    if (redo == 1) {
      vm->pc--;
      return TRUE;
    }
  }
  return FALSE;
}

// ゼロがミッションに出撃した後のシエルの独り言
static bool32 Cmd_goodluck(struct VM* vm) {
  if ((vm->pc)->status == 0) {
    if (CielGoodluckTextIDs[(gMission.unk_00)->lastStage] != 0) {
      PrintNormalMessage(CielGoodluckTextIDs[(gMission.unk_00)->lastStage]);
    }
  } else if ((gCurStory.s.f1 & STORY_F1_B3) == 0) {
    PrintNormalMessage(0x4a);
  } else if ((gCurStory.s.f1 & STORY_F1_B7) == 0) {
    PrintNormalMessage(0x4b);
  } else if ((gCurStory.s.f2 & NO_HARPUIA) == 0) {
    PrintNormalMessage(0x4c);
  } else if ((gCurStory.s.f2 & SUNKEN_ANALYZE) == 0) {
    PrintNormalMessage(0x4d);
  } else if ((gCurStory.s.f2 & WEIL_LABO) == 0) {
    PrintNormalMessage(0x4e);
  } else {
    PrintNormalMessage(0x4f);
  }
  return FALSE;
}

// ストパーラ系のエルフの効果を強制終了する
static bool32 Cmd_killtimeelf(struct VM* vm) {
  if (gTimeElfTimer != 0) {
    gCurStory.s.elfFlags &= ~TIME_ELF_ENABLED;
    TurnUpBGM();
    gTimeElfTimer = 0;
  }
  stopSound(SE_TIME_ELF);
  stopSound(SE_TIME_ELF_HURRY);
  return FALSE;
}

NAKED static void FUN_080237c4(u32 r0, s32 x, s32 y, u16 r3) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r3, r3, #0x10\n\
	lsrs r5, r3, #0x10\n\
	add r3, sp, #0x20\n\
	movs r0, #0\n\
	str r0, [r3, #8]\n\
	str r0, [r3, #0xc]\n\
	str r1, [sp, #0x38]\n\
	add r4, sp, #0x38\n\
	str r2, [r4, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	adds r7, r3, #0\n\
	cmp r5, r0\n\
	beq _08023800\n\
	lsls r0, r6, #2\n\
	ldr r1, _080237FC @ =gStaticMotionMetaspriteTable\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	adds r2, r4, #0\n\
	bl InitScalerotSprite1\n\
	b _08023810\n\
	.align 2, 0\n\
_080237FC: .4byte gStaticMotionMetaspriteTable\n\
_08023800:\n\
	lsls r0, r6, #2\n\
	ldr r1, _08023880 @ =gStaticMotionMetaspriteTable\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	adds r2, r4, #0\n\
	bl InitNonAffineSprite\n\
_08023810:\n\
	mov r4, sp\n\
	ldr r0, _08023884 @ =wStaticGraphicTilenums\n\
	lsls r3, r6, #1\n\
	adds r0, r3, r0\n\
	ldrh r0, [r0]\n\
	ldr r1, _08023888 @ =0x000003FF\n\
	ands r1, r0\n\
	ldrh r2, [r4, #0x14]\n\
	ldr r0, _0802388C @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r4, #0x14]\n\
	ldr r0, _08023890 @ =wStaticMotionPalIDs\n\
	adds r3, r3, r0\n\
	ldrb r1, [r3]\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r4, #0x15]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0x15]\n\
	mov r1, sp\n\
	movs r0, #0\n\
	strb r0, [r1, #0x1a]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r5, r0\n\
	beq _08023894\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	cmp r5, r0\n\
	bls _08023852\n\
	adds r5, r0, #0\n\
_08023852:\n\
	mov r0, sp\n\
	strh r5, [r0, #0x1c]\n\
	strh r5, [r0, #0x1e]\n\
	mov r3, sp\n\
	movs r1, #0x1f\n\
	ands r1, r6\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r3, #0x13]\n\
	movs r0, #0x3f\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #0x13]\n\
	mov r0, sp\n\
	movs r1, #0\n\
	bl ScalerotSprite\n\
	mov r0, sp\n\
	adds r1, r7, #0\n\
	bl TaskCB_SetMetaspriteTileNum1\n\
	b _0802389C\n\
	.align 2, 0\n\
_08023880: .4byte gStaticMotionMetaspriteTable\n\
_08023884: .4byte wStaticGraphicTilenums\n\
_08023888: .4byte 0x000003FF\n\
_0802388C: .4byte 0xFFFFFC00\n\
_08023890: .4byte wStaticMotionPalIDs\n\
_08023894:\n\
	mov r0, sp\n\
	adds r1, r7, #0\n\
	bl TaskCB_DrawNoAffineSprite\n\
_0802389C:\n\
	add sp, #0x40\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

NAKED static bool32 Cmd_cutscene(struct VM* vm) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0xc]\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #8\n\
	bls _080238BC\n\
	b _08023EE6\n\
_080238BC:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080238C8 @ =_080238CC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080238C8: .4byte _080238CC\n\
_080238CC: @ jump table\n\
	.4byte _080238F0 @ case 0\n\
	.4byte _08023A2C @ case 1\n\
	.4byte _08023D9E @ case 2\n\
	.4byte _08023B88 @ case 3\n\
	.4byte _08023C34 @ case 4\n\
	.4byte _08023D84 @ case 5\n\
	.4byte _08023DC8 @ case 6\n\
	.4byte _08023E30 @ case 7\n\
	.4byte _08023ED0 @ case 8\n\
_080238F0:\n\
	ldr r1, _080239FC @ =gVideoRegBuffer+6\n\
	ldr r2, _08023A00 @ =0x00000287\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #6\n\
	ldrh r2, [r1]\n\
	ldr r0, _08023A04 @ =0x0000F0FF\n\
	ands r0, r2\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	adds r2, r3, #0\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	movs r0, #0\n\
	strh r0, [r1, #0x10]\n\
	movs r0, #0x50\n\
	strh r0, [r1, #0x12]\n\
	ldr r0, _08023A08 @ =gGraphics_08547b54\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, _08023A0C @ =0x08547B60\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _08023A10 @ =gBgMapOffsets\n\
	movs r2, #0\n\
	str r2, [sp]\n\
	movs r0, #0x12\n\
	movs r2, #0x71\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldr r5, _08023A14 @ =0x00000A3C\n\
	ldr r3, _08023A18 @ =gStaticMotionGraphics\n\
	mov r8, r3\n\
	adds r0, r5, r3\n\
	ldr r1, _08023A1C @ =wStaticGraphicTilenums\n\
	mov sb, r1\n\
	movs r4, #0x83\n\
	lsls r4, r4, #1\n\
	adds r1, r1, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r3, _08023A20 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r3\n\
	ldr r6, _08023A24 @ =wStaticMotionPalIDs\n\
	adds r4, r6, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	mov sl, r0\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	movs r5, #0xa5\n\
	lsls r5, r5, #4\n\
	mov r1, r8\n\
	adds r0, r5, r1\n\
	movs r4, #0x84\n\
	lsls r4, r4, #1\n\
	mov r2, sb\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	bl LoadGraphic\n\
	ldr r0, _08023A20 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	adds r4, r6, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r4, _08023A28 @ =0x00000A64\n\
	add r8, r4\n\
	movs r5, #0x85\n\
	lsls r5, r5, #1\n\
	add sb, r5\n\
	mov r2, sb\n\
	ldrh r1, [r2]\n\
	mov r3, r8\n\
	ldrh r0, [r3, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	ldr r1, _08023A20 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r1\n\
	adds r6, r6, r5\n\
	ldrh r1, [r6]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	bl PauseAllBlinks\n\
	adds r0, r7, #0\n\
	adds r0, #0xd0\n\
	movs r2, #0\n\
	str r2, [r0]\n\
	b _08023EE6\n\
	.align 2, 0\n\
_080239FC: .4byte gVideoRegBuffer+6\n\
_08023A00: .4byte 0x00000287\n\
_08023A04: .4byte 0x0000F0FF\n\
_08023A08: .4byte gGraphic_Capcom+2260\n\
_08023A0C: .4byte gGraphic_Capcom+2272\n\
_08023A10: .4byte gBgMapOffsets\n\
_08023A14: .4byte 0x00000A3C\n\
_08023A18: .4byte gStaticMotionGraphics\n\
_08023A1C: .4byte wStaticGraphicTilenums\n\
_08023A20: .4byte gStaticMotionGraphics+12\n\
_08023A24: .4byte wStaticMotionPalIDs\n\
_08023A28: .4byte 0x00000A64\n\
_08023A2C:\n\
	adds r1, r7, #0\n\
	adds r1, #0xd0\n\
	ldr r2, [r1]\n\
	adds r0, r2, #0\n\
	subs r0, #0x3c\n\
	lsls r6, r0, #4\n\
	mov r8, r1\n\
	cmp r6, #0\n\
	bge _08023A40\n\
	movs r6, #0\n\
_08023A40:\n\
	cmp r2, #0xdc\n\
	ble _08023A6A\n\
	ldr r5, _08023A80 @ =gVideoRegBuffer+18\n\
	ldr r4, _08023A84 @ =gSineTable\n\
	adds r0, r2, #0\n\
	subs r0, #0xdc\n\
	lsls r0, r0, #7\n\
	movs r1, #0x78\n\
	bl __divsi3\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #5\n\
	adds r0, #0x28\n\
	strh r0, [r5]\n\
_08023A6A:\n\
	mov r0, r8\n\
	ldr r3, [r0]\n\
	cmp r3, #0x3c\n\
	ble _08023AB0\n\
	cmp r3, #0x63\n\
	bgt _08023A88\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #8\n\
	adds r1, r6, r2\n\
	b _08023A9C\n\
	.align 2, 0\n\
_08023A80: .4byte gVideoRegBuffer+18\n\
_08023A84: .4byte gSineTable\n\
_08023A88:\n\
	cmp r3, #0x9f\n\
	bgt _08023AC6\n\
	adds r1, r3, #0\n\
	subs r1, #0x64\n\
	lsls r0, r1, #3\n\
	muls r1, r0, r1\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #8\n\
	adds r0, r6, r2\n\
	adds r1, r1, r0\n\
_08023A9C:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #7\n\
	adds r2, r6, r0\n\
	adds r3, #0xc4\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	movs r0, #0x85\n\
	bl FUN_080237c4\n\
	b _08023AC6\n\
_08023AB0:\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #8\n\
	adds r1, r6, r2\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #7\n\
	adds r2, r6, r3\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	movs r0, #0x85\n\
	bl FUN_080237c4\n\
_08023AC6:\n\
	mov r0, r8\n\
	ldr r3, [r0]\n\
	cmp r3, #0xa0\n\
	ble _08023B08\n\
	cmp r3, #0xc7\n\
	bgt _08023ADA\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	subs r1, r1, r6\n\
	b _08023AF0\n\
_08023ADA:\n\
	ldr r0, _08023B04 @ =0x00000117\n\
	cmp r3, r0\n\
	bgt _08023B1E\n\
	adds r0, r3, #0\n\
	subs r0, #0xc8\n\
	lsls r1, r0, #3\n\
	muls r0, r1, r0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	subs r1, r1, r6\n\
	subs r1, r1, r0\n\
_08023AF0:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #7\n\
	adds r2, r6, r0\n\
	adds r3, #0x60\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	movs r0, #0x83\n\
	bl FUN_080237c4\n\
	b _08023B1E\n\
	.align 2, 0\n\
_08023B04: .4byte 0x00000117\n\
_08023B08:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	subs r1, r1, r6\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #7\n\
	adds r2, r6, r3\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	movs r0, #0x83\n\
	bl FUN_080237c4\n\
_08023B1E:\n\
	mov r0, r8\n\
	ldr r3, [r0]\n\
	cmp r3, #0xb4\n\
	ble _08023B60\n\
	cmp r3, #0xdb\n\
	bgt _08023B32\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #8\n\
	adds r1, r6, r2\n\
	b _08023B48\n\
_08023B32:\n\
	ldr r0, _08023B5C @ =0x00000117\n\
	cmp r3, r0\n\
	bgt _08023B76\n\
	adds r1, r3, #0\n\
	subs r1, #0xdc\n\
	lsls r0, r1, #3\n\
	muls r1, r0, r1\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #8\n\
	adds r0, r6, r2\n\
	adds r1, r1, r0\n\
_08023B48:\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #7\n\
	adds r2, r6, r0\n\
	adds r3, #0x4c\n\
	lsls r3, r3, #0x10\n\
	lsrs r3, r3, #0x10\n\
	movs r0, #0x84\n\
	bl FUN_080237c4\n\
	b _08023B76\n\
	.align 2, 0\n\
_08023B5C: .4byte 0x00000117\n\
_08023B60:\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #8\n\
	adds r1, r6, r2\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #7\n\
	adds r2, r6, r3\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	movs r0, #0x84\n\
	bl FUN_080237c4\n\
_08023B76:\n\
	mov r0, r8\n\
	ldr r1, [r0]\n\
	ldr r0, _08023B84 @ =0x00000153\n\
	cmp r1, r0\n\
	bgt _08023B82\n\
	b _08023E8E\n\
_08023B82:\n\
	b _08023EC2\n\
	.align 2, 0\n\
_08023B84: .4byte 0x00000153\n\
_08023B88:\n\
	bl ResetCharTiles\n\
	ldr r4, _08023C0C @ =gVideoRegBuffer\n\
	ldrh r1, [r4]\n\
	ldr r0, _08023C10 @ =0x0000F0FF\n\
	ands r0, r1\n\
	movs r2, #0xd8\n\
	lsls r2, r2, #6\n\
	adds r1, r2, #0\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	ldr r3, _08023C14 @ =0x00001E02\n\
	adds r0, r3, #0\n\
	strh r0, [r4, #8]\n\
	strh r5, [r4, #0x14]\n\
	strh r5, [r4, #0x16]\n\
	ldr r0, _08023C18 @ =0x08547C58\n\
	movs r1, #0\n\
	bl LoadGraphic\n\
	ldr r0, _08023C1C @ =0x08547C64\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r6, _08023C20 @ =gBgMapOffsets\n\
	str r5, [sp]\n\
	movs r0, #0x24\n\
	adds r1, r6, #0\n\
	movs r2, #0x7e\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	ldr r1, _08023C24 @ =0x00001D87\n\
	adds r0, r1, #0\n\
	strh r0, [r4, #6]\n\
	strh r5, [r4, #0x10]\n\
	movs r0, #0x60\n\
	strh r0, [r4, #0x12]\n\
	ldr r0, _08023C28 @ =0x08547C44\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, _08023C2C @ =0x08547C50\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	str r5, [sp]\n\
	movs r0, #0x12\n\
	adds r1, r6, #0\n\
	movs r2, #0x7d\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	bl PauseAllBlinks\n\
	ldr r0, _08023C30 @ =0x00000111\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	adds r0, r7, #0\n\
	adds r0, #0xd0\n\
	str r5, [r0]\n\
	b _08023EE6\n\
	.align 2, 0\n\
_08023C0C: .4byte gVideoRegBuffer\n\
_08023C10: .4byte 0x0000F0FF\n\
_08023C14: .4byte 0x00001E02\n\
_08023C18: .4byte gGraphic_Capcom+2520\n\
_08023C1C: .4byte gGraphic_Capcom+2532\n\
_08023C20: .4byte gBgMapOffsets\n\
_08023C24: .4byte 0x00001D87\n\
_08023C28: .4byte gGraphic_Capcom+2500\n\
_08023C2C: .4byte gGraphic_Capcom+2512\n\
_08023C30: .4byte 0x00000111\n\
_08023C34:\n\
	ldr r0, _08023C80 @ =0x00000111\n\
	bl GetBlinkMotionState\n\
	adds r0, r7, #0\n\
	adds r0, #0xd0\n\
	ldr r3, [r0]\n\
	adds r1, r3, #0\n\
	subs r1, #0x40\n\
	mov r8, r0\n\
	cmp r1, #0x80\n\
	bhi _08023C62\n\
	ldr r2, _08023C84 @ =gVideoRegBuffer+18\n\
	ldr r1, _08023C88 @ =gSineTable\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #4\n\
	adds r0, #0x30\n\
	strh r0, [r2]\n\
_08023C62:\n\
	mov r0, r8\n\
	ldr r3, [r0]\n\
	cmp r3, #0x3f\n\
	bgt _08023C90\n\
	ldr r2, _08023C8C @ =gVideoRegBuffer+22\n\
	ldr r1, _08023C88 @ =gSineTable\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #4\n\
	b _08023CCE\n\
	.align 2, 0\n\
_08023C80: .4byte 0x00000111\n\
_08023C84: .4byte gVideoRegBuffer+18\n\
_08023C88: .4byte gSineTable\n\
_08023C8C: .4byte gVideoRegBuffer+22\n\
_08023C90:\n\
	adds r0, r3, #0\n\
	subs r0, #0x40\n\
	cmp r0, #0x80\n\
	bhi _08023CB8\n\
	ldr r2, _08023CB0 @ =gVideoRegBuffer+22\n\
	ldr r1, _08023CB4 @ =gSineTable\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #6\n\
	adds r0, #0x2c\n\
	b _08023CCE\n\
	.align 2, 0\n\
_08023CB0: .4byte gVideoRegBuffer+22\n\
_08023CB4: .4byte gSineTable\n\
_08023CB8:\n\
	ldr r2, _08023D38 @ =gVideoRegBuffer+22\n\
	ldr r1, _08023D3C @ =gSineTable\n\
	adds r0, r3, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	asrs r0, r0, #6\n\
	adds r0, #8\n\
_08023CCE:\n\
	strh r0, [r2]\n\
	mov r4, r8\n\
	ldr r1, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _08023CFA\n\
	ldr r0, _08023D40 @ =0x00001222\n\
	bl PrintNormalMessage\n\
	ldr r1, _08023D44 @ =gVideoRegBuffer+6\n\
	ldr r2, _08023D48 @ =0x00001887\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08023D4C @ =gBgMapOffsets\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	movs r0, #0x12\n\
	movs r2, #0x7d\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
_08023CFA:\n\
	ldr r2, [r4]\n\
	ldr r3, _08023D50 @ =0xFFFFFEFF\n\
	adds r1, r2, r3\n\
	ldr r0, _08023D54 @ =0x000002E6\n\
	cmp r1, r0\n\
	bhi _08023D60\n\
	subs r0, #0x26\n\
	cmp r2, r0\n\
	bne _08023D12\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	str r0, [r4]\n\
_08023D12:\n\
	ldr r0, _08023D58 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _08023D1C\n\
	b _08023E8E\n\
_08023D1C:\n\
	ldr r0, _08023D5C @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	movs r1, #6\n\
	str r1, [r0]\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #2\n\
	adds r0, r0, r3\n\
	str r0, [r2]\n\
	b _08023E8E\n\
	.align 2, 0\n\
_08023D38: .4byte gVideoRegBuffer+22\n\
_08023D3C: .4byte gSineTable\n\
_08023D40: .4byte 0x00001222\n\
_08023D44: .4byte gVideoRegBuffer+6\n\
_08023D48: .4byte 0x00001887\n\
_08023D4C: .4byte gBgMapOffsets\n\
_08023D50: .4byte 0xFFFFFEFF\n\
_08023D54: .4byte 0x000002E6\n\
_08023D58: .4byte gTextWindow+8\n\
_08023D5C: .4byte gStageRun\n\
_08023D60:\n\
	ldr r0, _08023D7C @ =0x000003E7\n\
	cmp r2, r0\n\
	bgt _08023D68\n\
	b _08023E8E\n\
_08023D68:\n\
	ldr r0, _08023D80 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _08023D78\n\
	b _08023EE6\n\
_08023D78:\n\
	b _08023E8E\n\
	.align 2, 0\n\
_08023D7C: .4byte 0x000003E7\n\
_08023D80: .4byte gStageRun\n\
_08023D84:\n\
	ldr r0, _08023DB8 @ =gStageRun\n\
	movs r2, #0xaa\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _08023D94\n\
	b _08023E8E\n\
_08023D94:\n\
	ldr r0, _08023DBC @ =0x00000111\n\
	bl ClearBlink\n\
	bl text_080e9730\n\
_08023D9E:\n\
	ldr r2, _08023DC0 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _08023DC4 @ =0x0000EDFF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	bl ResumeAllBlinks\n\
	b _08023EE6\n\
	.align 2, 0\n\
_08023DB8: .4byte gStageRun\n\
_08023DBC: .4byte 0x00000111\n\
_08023DC0: .4byte gVideoRegBuffer\n\
_08023DC4: .4byte 0x0000EDFF\n\
_08023DC8:\n\
	bl UnmaskBg0\n\
	ldr r1, _08023E18 @ =gVideoRegBuffer+6\n\
	ldr r2, _08023E1C @ =0x00001F83\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #6\n\
	ldrh r2, [r1]\n\
	ldr r0, _08023E20 @ =0x0000F0FF\n\
	ands r0, r2\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	adds r2, r3, #0\n\
	movs r4, #0\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	strh r4, [r1, #0x10]\n\
	movs r0, #0x60\n\
	strh r0, [r1, #0x12]\n\
	ldr r0, _08023E24 @ =0x08547BF4\n\
	movs r1, #0\n\
	bl LoadGraphic\n\
	ldr r0, _08023E28 @ =0x08547C00\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldr r1, _08023E2C @ =gBgMapOffsets\n\
	str r4, [sp]\n\
	movs r0, #0x12\n\
	movs r2, #0x79\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
	bl PauseAllBlinks\n\
	adds r0, r7, #0\n\
	adds r0, #0xd0\n\
	str r4, [r0]\n\
	b _08023EE6\n\
	.align 2, 0\n\
_08023E18: .4byte gVideoRegBuffer+6\n\
_08023E1C: .4byte 0x00001F83\n\
_08023E20: .4byte 0x0000F0FF\n\
_08023E24: .4byte gGraphic_Capcom+2420\n\
_08023E28: .4byte gGraphic_Capcom+2432\n\
_08023E2C: .4byte gBgMapOffsets\n\
_08023E30:\n\
	adds r4, r7, #0\n\
	adds r4, #0xd0\n\
	ldr r3, [r4]\n\
	adds r0, r3, #0\n\
	subs r0, #0x40\n\
	cmp r0, #0x80\n\
	bhi _08023E5A\n\
	ldr r2, _08023E98 @ =gVideoRegBuffer+18\n\
	ldr r1, _08023E9C @ =gSineTable\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r1\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #4\n\
	strh r0, [r2]\n\
_08023E5A:\n\
	ldr r0, [r4]\n\
	cmp r0, #0xc0\n\
	bne _08023E88\n\
	ldr r2, _08023E98 @ =gVideoRegBuffer+18\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	subs r2, #0xc\n\
	ldrh r1, [r2]\n\
	ldr r0, _08023EA0 @ =0x0000E0FF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08023EA4 @ =gBgMapOffsets\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	movs r0, #0x12\n\
	movs r2, #0x79\n\
	movs r3, #0\n\
	bl LoadBgMap\n\
_08023E88:\n\
	ldr r0, [r4]\n\
	cmp r0, #0xc0\n\
	bgt _08023EA8\n\
_08023E8E:\n\
	ldr r0, [r7, #0xc]\n\
	subs r0, #8\n\
	str r0, [r7, #0xc]\n\
	movs r0, #1\n\
	b _08023EE8\n\
	.align 2, 0\n\
_08023E98: .4byte gVideoRegBuffer+18\n\
_08023E9C: .4byte gSineTable\n\
_08023EA0: .4byte 0x0000E0FF\n\
_08023EA4: .4byte gBgMapOffsets\n\
_08023EA8:\n\
	ldr r0, _08023EC8 @ =gGameState+16\n\
	ldr r1, _08023ECC @ =gVideoRegBuffer+4\n\
	ldrh r2, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #3\n\
	movs r3, #0xf0\n\
	lsls r3, r3, #2\n\
	bl MaskBg0\n\
_08023EC2:\n\
	bl text_080e9730\n\
	b _08023EE6\n\
	.align 2, 0\n\
_08023EC8: .4byte gGameState+16\n\
_08023ECC: .4byte gVideoRegBuffer+4\n\
_08023ED0:\n\
	ldr r2, _08023EF8 @ =gVideoRegBuffer\n\
	ldrh r1, [r2]\n\
	ldr r0, _08023EFC @ =0x0000EDFF\n\
	ands r0, r1\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	bl ResumeAllBlinks\n\
_08023EE6:\n\
	movs r0, #0\n\
_08023EE8:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08023EF8: .4byte gVideoRegBuffer\n\
_08023EFC: .4byte 0x0000EDFF\n\
 .syntax divided\n");
}
