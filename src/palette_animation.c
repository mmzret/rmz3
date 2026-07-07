#include "palette_animation.h"

#include "gba/gba.h"
#include "gfx.h"
#include "global.h"

// 元々 Blink という名前をつけており、まだBlinkという名前が残っている部分もあるが、将来的にはすべて PaletteAnimation に統一する予定

extern const s32 gPlttAnimDataOffsets[];
extern const AnimCmd* const* const gPlttAnimScriptTable[];

// パレットを時間経過で(指定した色に)変化させる処理 e.g. CMD室の世界地図のglowエフェクト

// 0x08003dd8
void RemoveAllPaletteAnimations(void) {
  s32 i;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    gPaletteAnimationManager.ids[i] = 0;
  }
}

static inline void TransferPalettes(PaletteAnimation* b) {
  PlttAnimData* pal = b->pal;
  s16 len = (pal->end - pal->start) + 1;  // 転送する色数 (len * 2 = 転送するバイト数)
  if ((b->offsetByte & 0x1FF) == 0) {
    s16 idx = (b->m).table[(b->m).id][(b->m).cmdIdx].param;  // 今回転送するパレットのインデックス
    u16* src = (u16*)(pal + 1) + (idx * len);
    s32 dst_byte_offset = b->offsetByte + (pal->start << 1);
    CpuCopy16(src, ((u8*)gPaletteManager.buf + dst_byte_offset), (len << 1));
  } else {
    s16 idx = (b->m).table[(b->m).id][(b->m).cmdIdx].param;  // 今回転送するパレットのインデックス
    u16* src = (u16*)(pal + 1) + (idx * len);
    s32 dst_byte_offset = b->offsetByte + ((pal->start << 1) & 0x1F);
    CpuCopy16(src, ((u8*)gPaletteManager.buf + dst_byte_offset), (len << 1));
  }
}

/**
 * @brief 現在有効な PaletteAnimation の今の色を gPaletteManager.buf に転送する
 * @note アニメーションのステートの更新はしない
 * @note 0x08003df4
 */
void TransferAnimatedPalettesToPaletteBuffer(void) {
  s32 i;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] != 0) {
      PaletteAnimation* b = &gPaletteAnimationManager.anims[i];
      if (!b->paused) TransferPalettes(b);
    }
  }
}

/**
 * @brief すべてのパレットアニメーションを一時停止する, メニュー画面に入るときなど
 * @note 0x08003ecc
 */
void PauseAllPaletteAnimations(void) {
  s32 i;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] != 0) {
      gPaletteAnimationManager.anims[i].paused = TRUE;
    }
  }
}

/**
 * @brief メニュー画面から出る時
 * @note 0x08003ef4
 */
void ResumeAllPaletteAnimations(void) {
  s32 i;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] != 0) {
      if (gPaletteAnimationManager.anims[i].paused) {
        gPaletteAnimationManager.anims[i].paused = FALSE;
      } else {
        gPaletteAnimationManager.ids[i] = 0;
      }
    }
  }
}

/**
 * @brief IDで指定したパレットアニメーションを開始する
 * @param id パレットアニメーションのID 0x085be764 のidx
 * @param dst_byte_ofs アニメーション転送先のバイトオフセット ( PlttAnimData の示すオフセットにさらに加算される, ほどんどの場合　0)
 * @note 0x08003f2c
 * @note gPlttAnimDataOffsets のレジスタ割り当てだけが、うまくいかない
 */
NON_MATCH void StartPaletteAnimation(u16 id, u16 dst_byte_ofs) {
#if MODERN
  s32 i;

  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] == (id + 1)) {
      return;
    }
  }
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] == 0) break;
  }
  if (i != MAX_PLTT_ANIM) {
    PaletteAnimation* b = &gPaletteAnimationManager.anims[i];
    b->pal = SELF_REL_PTR(&gPlttAnimDataOffsets[id]);  // ここのレジスタ割り当てだけが、うまくいかない！！！！
    b->cmds = (AnimCmd**)gPlttAnimScriptTable[id];
    b->paused = FALSE;
    b->offsetByte = dst_byte_ofs;
    ResetAnimState(&b->m, (const AnimCmd* const*)b->cmds);
    SetAnimSubID(&b->m, 0);
    TransferPalettes(b);
    gPaletteAnimationManager.ids[i] = (id + 1);  // 0 は 空きエントリを意味するので、blinkIDに1を加えている
  }
#else
  INCCODE("asm/wip/StartPaletteAnimation.inc");
#endif
}

/**
 * @brief idで指定したパレットアニメーションを1フレーム進める
 * @note 0x08004068
 */
u32 StepPaletteAnimation(u16 id) {
  PaletteAnimation* b;
  s32 i;

  id++;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] == id) break;
  }
  if (i == MAX_PLTT_ANIM) {
    return ANIM_END;
  }
  b = &gPaletteAnimationManager.anims[i];
  StepAnimState(&b->m);
  return b->m.state;
}

/**
 * @brief idで指定したパレットアニメーションを終了する
 * @note 0x080040b4
 */
void RemovePaletteAnimation(u16 id) {
  s32 i;

  id++;
  for (i = 0; i < MAX_PLTT_ANIM; i++) {
    if (gPaletteAnimationManager.ids[i] == id) break;
  }
  if (i != MAX_PLTT_ANIM) gPaletteAnimationManager.ids[i] = 0;
}
