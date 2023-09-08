#include "mmbn4.h"

#include "global.h"

static void sio_08001748(void);
static void* mmbn4_080016c8(void* r0);
void DisableSerial(void);

// clang-format off
const struct Unk_080006c8 UnkMmbn4Datas[5] = {
    {(void*)0x02000fb0, (void*)0x02000db0, (void*)0x02000dc0, 4},
    {(void*)0x02000fb0, (void*)0x02000db0, (void*)0x02000eb0, 0},
    {(void*)0x02000fb0, (void*)0x02000db0, (void*)0x02000dc0, 4},
    {(void*)0x02000fb0, (void*)0x02000db0, (void*)0x02000dc0, 0},
    {(void*)0x02000fb0, (void*)0x02000db0, (void*)0x02000dc0, 4},
};
// clang-format on

NAKED static void clearMemory16(void* dst, u32 bytesize) {
  asm(".syntax unified\n\
	push {r0, r1, r2, r3, lr}\n\
	ldr r2, _08000734 @ =0x01000000\n\
	lsrs r1, r1, #1\n\
	orrs r2, r1\n\
	adds r1, r0, #0\n\
	sub sp, #4\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	mov r0, sp\n\
	bl CpuSet\n\
	add sp, #4\n\
	pop {r0, r1, r2, r3, pc}\n\
	.align 2, 0\n\
_08000734: .4byte 0x01000000\n\
 .syntax divided\n");
}

NAKED static void mmbn4_08000738(u32 r0, u32 r1, u32 r2, u32 r3) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r7, _08000794 @ =0x02000D50\n\
	str r0, [r7, #0x20]\n\
	str r0, [r7, #0x24]\n\
	strb r2, [r7, #3]\n\
	strb r3, [r7, #2]\n\
	ldr r0, _08000770 @ =UnkMmbn4Datas\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	str r1, [r7, #0x34]\n\
	ldr r1, [r0, #4]\n\
	str r1, [r7, #0x38]\n\
	ldr r1, [r0, #8]\n\
	str r1, [r7, #0x3c]\n\
	ldrb r1, [r0, #0xc]\n\
	strb r1, [r7]\n\
	strb r1, [r7, #1]\n\
	movs r1, #0\n\
	strb r1, [r7, #5]\n\
	strb r1, [r7, #8]\n\
	strh r1, [r7, #0x18]\n\
	mvns r1, r1\n\
	strh r1, [r7, #0x10]\n\
	strh r1, [r7, #0x12]\n\
	strh r1, [r7, #0x14]\n\
	strh r1, [r7, #0x16]\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08000770: .4byte UnkMmbn4Datas\n\
 .syntax divided\n");
}

WIP static void sio_08000774(u32 r0, u16 r1, u16 r2) {
#if MODERN
  gUnk02000d50.unk_1c = r0;
  gUnk02000d50.unk_0a = r1;
  gUnk02000d50.unk_0e = r2;
#else
  INCCODE("asm/wip/sio_08000774.inc");
#endif
}

INCASM("asm/mmbn4.inc");

NAKED static void* mmbn4_080016c8(void* r0) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #2\n\
	adds r7, r0, #0\n\
	bl FUN_08000784\n\
	beq _080016D6\n\
	movs r0, #1\n\
_080016D6:\n\
	ldr r4, _08001728 @ =0x020014C0\n\
	strb r0, [r4]\n\
	movs r5, #0\n\
_080016DC:\n\
	ldr r1, _0800172C @ =0x08001730\n\
	ldr r6, [r1, #4]\n\
	tst r5, r5\n\
	bne _080016E6\n\
	ldr r6, [r1]\n\
_080016E6:\n\
	ldr r0, [r6]\n\
	ldr r1, _08001738 @ =0x4234574A\n\
	cmp r0, r1\n\
	bne _080016FC\n\
	ldrh r0, [r6, #4]\n\
	ldr r1, _0800173C @ =0x08001740\n\
	ldr r1, [r1, r7]\n\
	cmp r0, r1\n\
	bne _080016FC\n\
	bl sio_08001748\n\
_080016FC:\n\
	adds r5, #1\n\
	cmp r5, #2\n\
	blt _080016DC\n\
	ldr r1, _0800172C @ =0x08001730\n\
	ldr r6, [r1, #4]\n\
	ldrb r5, [r4]\n\
	tst r5, r5\n\
	beq _0800170E\n\
	ldr r6, [r1]\n\
_0800170E:\n\
	ldr r0, [r6]\n\
	ldr r1, _08001738 @ =0x4234574A\n\
	cmp r0, r1\n\
	bne _08001724\n\
	ldrh r0, [r6, #4]\n\
	ldr r1, _0800173C @ =0x08001740\n\
	ldr r1, [r1, r7]\n\
	cmp r0, r1\n\
	bne _08001724\n\
	adds r0, r6, #0\n\
	b _08001726\n\
_08001724:\n\
	movs r0, #0xff\n\
_08001726:\n\
	pop {r4, r5, r6, r7, pc}\n\
	.align 2, 0\n\
_08001728: .4byte 0x020014C0\n\
_0800172C: .4byte _08001730\n\
_08001730:\n\
	.byte 0xB0, 0x0D, 0x00, 0x02, 0xC0, 0x0D, 0x00, 0x02\n\
_08001738: .4byte 0x4234574A\n\
_0800173C: .4byte _08001740\n\
_08001740:\n\
	.byte 0x00, 0x40, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00\n\
 .syntax divided\n");
}

NAKED static void sio_08001748(void) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	ldrb r1, [r6, #0xc]\n\
	cmp r1, #5\n\
	bgt _08001756\n\
	ldrb r1, [r6, #0xe]\n\
	cmp r1, #5\n\
	ble _08001770\n\
_08001756:\n\
	ldr r4, _08001774 @ =0x02000D50\n\
	adds r0, r1, #0\n\
	cmp r1, r2\n\
	bge _08001760\n\
	adds r0, r2, #0\n\
_08001760:\n\
	adds r0, #8\n\
	ldr r1, [r4, #0x54]\n\
	cmp r0, r1\n\
	bge _0800176A\n\
	adds r0, r1, #0\n\
_0800176A:\n\
	str r0, [r4, #0x54]\n\
	movs r0, #0xc\n\
	strb r0, [r4]\n\
_08001770:\n\
	pop {r4, pc}\n\
	.align 2, 0\n\
_08001774: .4byte 0x02000D50\n\
 .syntax divided\n");
}

void sio_08001778(void) {
  DisableSerial();
  return;
}
