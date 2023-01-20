#include "sound.h"

extern SoundID SoundID1;
extern SoundID SoundID2;
extern u32 *u32_020021a4;

NAKED void initSound(void) {
  asm(".syntax unified\n\
    push {lr}\n\
    bl m4aSoundInit\n\
    ldr r1, _08004440 @ =0x020021A4\n\
	ldr r0, _08004444 @ =0x00000150\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [r1]\n\
	ldr r0, _08004448 @ =0x02000020\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, _0800444C @ =0x02000022\n\
	strh r1, [r0]\n\
	pop {r0}\n\
	bx r0\n\
    .align 2, 0\n\
_08004440: .4byte 0x020021A4\n\
_08004444: .4byte 0x00000150\n\
_08004448: .4byte 0x02000020\n\
_0800444C: .4byte 0x02000022\n\
    .syntax divided\n");
}

void stopAllMusics(void) {
  m4aMPlayAllStop();
  SoundID1 = 0;
  SoundID2 = 0;
  return;
}

NAKED void _usrHBlankCallback(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r6, _0800447C @ =0x02000020\n\
	ldrh r0, [r6]\n\
	adds r5, r0, #0\n\
	cmp r5, #0\n\
	beq _08004480\n\
	subs r0, #1\n\
	b _08004490\n\
	.align 2, 0\n\
_0800447C: .4byte 0x02000020\n\
_08004480:\n\
	ldr r4, _0800449C @ =0x02000022\n\
	ldrh r0, [r4]\n\
	cmp r0, #0\n\
	beq _08004492\n\
	bl m4aSongNumStart\n\
	strh r5, [r4]\n\
	movs r0, #8\n\
_08004490:\n\
	strh r0, [r6]\n\
_08004492:\n\
	bl m4aSoundMain\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800449C: .4byte 0x02000022\n\
    .syntax divided\n");
}

void FUN_080044a0(void) {
  m4aSoundVSync();
  return;
}

// メニュー画面を開いた時など、BGMの音量を落とす
NAKED void turnDownBGM(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r0, _080044D4 @ =0x0000000F\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080044CE\n\
	ldr r5, _080044D8 @ =0x0810F75C\n\
	adds r4, r0, #0\n\
_080044BC:\n\
	ldr r0, [r5]\n\
	ldr r1, _080044DC @ =0x0000FFFF\n\
	movs r2, #0x60\n\
	bl m4aMPlayVolumeControl\n\
	adds r5, #0xc\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _080044BC\n\
_080044CE:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080044D4: .4byte 0x0000000F\n\
_080044D8: .4byte 0x0810F75C\n\
_080044DC: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

// メニュー画面から戻った時に、BGMを通常音量に戻す
NAKED void turnUpBGM(void) {
  asm(".syntax unified\n\
  	push {r4, r5, lr}\n\
	ldr r0, _0800450C @ =0x0000000F\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08004504\n\
	ldr r5, _08004510 @ =0x0810F75C\n\
	adds r4, r0, #0\n\
_080044F0:\n\
	ldr r0, [r5]\n\
	ldr r1, _08004514 @ =0x0000FFFF\n\
	movs r2, #0x80\n\
	lsls r2, r2, #1\n\
	bl m4aMPlayVolumeControl\n\
	adds r5, #0xc\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bne _080044F0\n\
_08004504:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800450C: .4byte 0x0000000F\n\
_08004510: .4byte 0x0810F75C\n\
_08004514: .4byte 0x0000FFFF\n\
          .syntax divided\n");
}

void playBGM(SoundID32 n) {
  m4aSongNumStart((u16)n);
  return;
}

void fadeoutBGM(SoundID n) {
  bool32 playing;

  playing = _isSoundPlaying((u16)n);
  if (playing != 0) {
    m4aMPlayFadeOut(gMPlayTable[gSongTable[n & 0xffff].ms].info, 6);
  }
  return;
}

NAKED bool32 _isSoundPlaying(SoundID32 n) {
  asm(".syntax unified\n\
	push {lr}\n\
	lsls r0, r0, #0x10\n\
	ldr r3, _08004590 @ =0x0810F75C\n\
	ldr r1, _08004594 @ =0x0810F810\n\
	lsrs r0, r0, #0xd\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0, #4]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	ldr r2, [r1]\n\
	ldr r1, [r2]\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	bne _08004598\n\
	ldr r1, [r2, #4]\n\
	ldrh r0, [r2, #4]\n\
	cmp r0, #0\n\
	beq _08004598\n\
	cmp r1, #0\n\
	blt _08004598\n\
	movs r0, #1\n\
	b _0800459A\n\
	.align 2, 0\n\
_08004590: .4byte 0x0810F75C\n\
_08004594: .4byte 0x0810F810\n\
_08004598:\n\
	movs r0, #0\n\
_0800459A:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
          .syntax divided\n");
}

NAKED s16 playSound(SoundID id) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	ldr r1, _080045CC @ =0x0810F810\n\
	lsls r0, r4, #3\n\
	adds r0, r0, r1\n\
	movs r2, #0xa6\n\
	lsls r2, r2, #1\n\
	adds r1, r1, r2\n\
	ldrh r0, [r0, #4]\n\
	ldrh r1, [r1]\n\
	cmp r0, r1\n\
	bne _080045D4\n\
	ldr r1, _080045D0 @ =0x02000022\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080045C6\n\
	cmp r0, #0x29\n\
	bne _080045DE\n\
_080045C6:\n\
	strh r4, [r1]\n\
	b _080045DE\n\
	.align 2, 0\n\
_080045CC: .4byte 0x0810F810\n\
_080045D0: .4byte 0x02000022\n\
_080045D4:\n\
	cmp r4, #0\n\
	beq _080045E4\n\
	adds r0, r4, #0\n\
	bl m4aSongNumStart\n\
_080045DE:\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	b _080045E6\n\
_080045E4:\n\
	movs r0, #0\n\
_080045E6:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
          .syntax divided\n");
}

NAKED void stopSound(SoundID32 n) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	blt _08004606\n\
	lsrs r4, r0, #0x10\n\
	adds r0, r4, #0\n\
	bl _isSoundPlaying\n\
	cmp r0, #0\n\
	beq _08004606\n\
	adds r0, r4, #0\n\
	bl m4aSongNumStop\n\
_08004606:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
          .syntax divided\n");
}

NAKED void fadeoutSound(s32 r0, u16 r1) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	lsls r4, r1, #0x10\n\
	ldr r3, _0800463C @ =0x0810F75C\n\
	ldr r1, _08004640 @ =0x0810F810\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0xd\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0, #4]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	ldr r2, [r1]\n\
	ldr r1, [r2]\n\
	ldr r0, [r0]\n\
	cmp r1, r0\n\
	bne _08004636\n\
	lsrs r1, r4, #0x14\n\
	adds r0, r2, #0\n\
	bl m4aMPlayFadeOut\n\
_08004636:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800463C: .4byte 0x0810F75C\n\
_08004640: .4byte 0x0810F810\n\
          .syntax divided\n");
}

// まだ音が終わっていないか
bool32 isSoundPlaying(SoundID n) {
  if (_isSoundPlaying(n) == 0) {
    return 0;
  } else {
    return 1;
  }
}

void sound_0800465c(SoundID n) {
  bool32 b;

  b = _isSoundPlaying(n);
  if (b != 0) {
    m4aMPlayVolumeControl(gMPlayTable[gSongTable[n & 0xffff].ms].info, 0xffff, 0x100);
  }
  return;
}
