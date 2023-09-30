#include "game.h"
#include "global.h"

static const TextID SearchReactionTexts[4];
static const disk_t SunkenSecretDisks[4];
static const str_id_t StrID_ARRAY_08386294[4];
static const TextID AfterSearchTextIDs[4];

NAKED void OverworldLoop_SunkenLibrarySearch(struct GameState *p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x20\n\
	adds r6, r0, #0\n\
	ldrb r0, [r6, #3]\n\
	cmp r0, #9\n\
	bls _080F2636\n\
	b _080F2BF8\n\
_080F2636:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080F2640 @ =_080F2644\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080F2640: .4byte _080F2644\n\
_080F2644: @ jump table\n\
	.4byte _080F266C @ case 0\n\
	.4byte _080F26FE @ case 1\n\
	.4byte _080F2724 @ case 2\n\
	.4byte _080F29AC @ case 3\n\
	.4byte _080F29E8 @ case 4\n\
	.4byte _080F2A18 @ case 5\n\
	.4byte _080F2A98 @ case 6\n\
	.4byte _080F2AF0 @ case 7\n\
	.4byte _080F2B20 @ case 8\n\
	.4byte _080F2BD8 @ case 9\n\
_080F266C:\n\
	ldr r2, _080F26B4 @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F2676\n\
	b _080F29F0\n\
_080F2676:\n\
	ldr r7, _080F26B8 @ =0x0000FFFF\n\
	movs r3, #0\n\
	ldr r0, _080F26BC @ =SearchReactionTexts\n\
	mov sl, r0\n\
	ldr r0, _080F26C0 @ =gStageDiskManager\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r1, _080F26C4 @ =SunkenSecretDisks\n\
	mov sb, r1\n\
_080F2688:\n\
	lsls r0, r7, #0x10\n\
	asrs r4, r0, #0x10\n\
	lsls r3, r3, #0x10\n\
	asrs r0, r3, #0x10\n\
	add r0, sb\n\
	ldrb r2, [r0]\n\
	lsrs r0, r2, #2\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	movs r0, #3\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	movs r0, #1\n\
	ands r1, r0\n\
	adds r5, r3, #0\n\
	cmp r1, #0\n\
	bne _080F26C8\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	b _080F26CA\n\
	.align 2, 0\n\
_080F26B4: .4byte gTextWindow+8\n\
_080F26B8: .4byte 0x0000FFFF\n\
_080F26BC: .4byte SearchReactionTexts\n\
_080F26C0: .4byte gStageDiskManager\n\
_080F26C4: .4byte SunkenSecretDisks\n\
_080F26C8:\n\
	lsls r0, r4, #0x10\n\
_080F26CA:\n\
	lsrs r0, r0, #0x10\n\
	adds r7, r0, #0\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r5, r2\n\
	lsrs r3, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _080F2688\n\
	lsls r0, r7, #0x10\n\
	asrs r0, r0, #0xf\n\
	add r0, sl\n\
	ldrh r0, [r0]\n\
	bl PrintOptionMessage2\n\
	movs r0, #0x97\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	movs r0, #0x98\n\
	movs r1, #0\n\
	bl LoadBlink\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F26FE:\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F270C\n\
	cmp r0, #4\n\
	beq _080F270C\n\
	b _080F2BF8\n\
_080F270C:\n\
	ldr r0, _080F291C @ =0x00000F07\n\
	bl PrintOptionMessage1\n\
	movs r0, #0\n\
	strh r0, [r6, #4]\n\
	strh r0, [r6, #6]\n\
	strh r0, [r6, #8]\n\
	movs r0, #0xf\n\
	strh r0, [r6, #0xa]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F2724:\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F2732\n\
	cmp r0, #4\n\
	beq _080F2732\n\
	b _080F2BF8\n\
_080F2732:\n\
	movs r7, #0\n\
	movs r3, #0\n\
	ldr r0, _080F2920 @ =gStageDiskManager\n\
	ldr r5, [r0]\n\
	ldr r0, _080F2924 @ =SunkenSecretDisks\n\
	mov r8, r0\n\
_080F273E:\n\
	lsls r0, r3, #0x10\n\
	asrs r4, r0, #0x10\n\
	mov r1, r8\n\
	adds r0, r4, r1\n\
	ldrb r2, [r0]\n\
	lsrs r0, r2, #2\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	movs r0, #3\n\
	ands r0, r2\n\
	asrs r1, r0\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080F2770\n\
	lsls r0, r7, #0x10\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r0, #1\n\
	add r1, sp\n\
	strh r3, [r1]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
_080F2770:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _080F273E\n\
	movs r5, #4\n\
	ldrsh r2, [r6, r5]\n\
	lsls r1, r7, #0x10\n\
	asrs r0, r1, #0x10\n\
	subs r0, #1\n\
	adds r7, r1, #0\n\
	cmp r2, r0\n\
	bge _080F27A4\n\
	ldr r0, _080F2928 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F27A4\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r6, #4]\n\
	adds r0, #1\n\
	strh r0, [r6, #4]\n\
_080F27A4:\n\
	movs r1, #4\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0\n\
	ble _080F27C4\n\
	ldr r0, _080F2928 @ =gJoypad\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F27C4\n\
	movs r0, #1\n\
	bl PlaySound\n\
	ldrh r0, [r6, #4]\n\
	subs r0, #1\n\
	strh r0, [r6, #4]\n\
_080F27C4:\n\
	ldrh r3, [r6, #4]\n\
	movs r2, #4\n\
	ldrsh r1, [r6, r2]\n\
	movs r5, #6\n\
	ldrsh r0, [r6, r5]\n\
	adds r2, r3, #0\n\
	cmp r1, r0\n\
	bge _080F27D6\n\
	strh r2, [r6, #6]\n\
_080F27D6:\n\
	movs r0, #4\n\
	ldrsh r1, [r6, r0]\n\
	movs r2, #6\n\
	ldrsh r0, [r6, r2]\n\
	adds r0, #1\n\
	cmp r1, r0\n\
	ble _080F27E8\n\
	subs r0, r3, #1\n\
	strh r0, [r6, #6]\n\
_080F27E8:\n\
	movs r3, #0\n\
	cmp r7, #0\n\
	ble _080F285A\n\
	ldr r5, _080F292C @ =StringOfsTable\n\
	mov sb, r5\n\
	ldr r0, _080F2930 @ =StrID_ARRAY_08386294\n\
	mov r8, r0\n\
_080F27F6:\n\
	lsls r1, r3, #0x10\n\
	asrs r3, r1, #0x10\n\
	movs r2, #6\n\
	ldrsh r0, [r6, r2]\n\
	subs r0, r3, r0\n\
	lsls r0, r0, #0x19\n\
	lsrs r2, r0, #0x18\n\
	adds r5, r1, #0\n\
	cmp r2, #2\n\
	bhi _080F284E\n\
	lsls r0, r3, #1\n\
	add r0, sp\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #1\n\
	add r0, r8\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #1\n\
	add r0, sb\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F2934 @ =gStringData\n\
	adds r4, r1, r0\n\
	movs r3, #0\n\
	ldr r1, _080F2918 @ =gTextWindow+8\n\
	ldrb r0, [r1, #6]\n\
	cmp r0, #0\n\
	bne _080F2832\n\
	ldrb r0, [r1, #4]\n\
	cmp r0, #1\n\
	bne _080F2834\n\
_080F2832:\n\
	movs r3, #1\n\
_080F2834:\n\
	lsls r0, r3, #3\n\
	subs r0, r0, r3\n\
	movs r1, #0xa\n\
	subs r1, r1, r0\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	lsls r2, r2, #0x18\n\
	asrs r2, r2, #0x18\n\
	adds r2, #2\n\
	ldrb r0, [r0, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r4, #0\n\
	bl PrintString\n\
_080F284E:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r5, r2\n\
	lsrs r3, r0, #0x10\n\
	cmp r0, r7\n\
	blt _080F27F6\n\
_080F285A:\n\
	ldr r0, _080F292C @ =StringOfsTable\n\
	ldrh r1, [r0]\n\
	ldr r0, _080F2934 @ =gStringData\n\
	adds r3, r1, r0\n\
	movs r2, #0\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F2874\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F2876\n\
_080F2874:\n\
	movs r2, #1\n\
_080F2876:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #8\n\
	subs r1, r1, r0\n\
	movs r5, #4\n\
	ldrsh r2, [r6, r5]\n\
	movs r5, #6\n\
	ldrsh r0, [r6, r5]\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #1\n\
	adds r2, #2\n\
	ldrb r0, [r4, #5]\n\
	adds r2, r2, r0\n\
	adds r0, r3, #0\n\
	bl PrintString\n\
	ldrh r0, [r6, #8]\n\
	adds r0, #1\n\
	strh r0, [r6, #8]\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F2906\n\
	movs r1, #6\n\
	ldrsh r0, [r6, r1]\n\
	cmp r0, #0\n\
	beq _080F28D2\n\
	ldr r3, _080F2938 @ =Unicode_CursorUp\n\
	movs r1, #0\n\
	ldrb r0, [r4, #6]\n\
	cmp r0, #0\n\
	bne _080F28BC\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F28BE\n\
_080F28BC:\n\
	movs r1, #1\n\
_080F28BE:\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	ldrb r2, [r0, #5]\n\
	adds r2, #2\n\
	adds r0, r3, #0\n\
	bl PrintUnicodeString\n\
_080F28D2:\n\
	movs r2, #6\n\
	ldrsh r1, [r6, r2]\n\
	asrs r0, r7, #0x10\n\
	subs r0, #2\n\
	cmp r1, r0\n\
	bge _080F2906\n\
	ldr r3, _080F293C @ =Unicode_CursorDown\n\
	movs r2, #0\n\
	ldr r0, _080F2918 @ =gTextWindow+8\n\
	ldrb r1, [r0, #6]\n\
	adds r4, r0, #0\n\
	cmp r1, #0\n\
	bne _080F28F2\n\
	ldrb r0, [r4, #4]\n\
	cmp r0, #1\n\
	bne _080F28F4\n\
_080F28F2:\n\
	movs r2, #1\n\
_080F28F4:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	movs r1, #0x1c\n\
	subs r1, r1, r0\n\
	ldrb r2, [r4, #5]\n\
	adds r2, #5\n\
	adds r0, r3, #0\n\
	bl PrintUnicodeString\n\
_080F2906:\n\
	ldrh r1, [r6, #0xa]\n\
	movs r5, #0xa\n\
	ldrsh r0, [r6, r5]\n\
	cmp r0, #0\n\
	beq _080F2940\n\
	subs r0, r1, #1\n\
	strh r0, [r6, #0xa]\n\
	b _080F2BF8\n\
	.align 2, 0\n\
_080F2918: .4byte gTextWindow+8\n\
_080F291C: .4byte 0x00000F07\n\
_080F2920: .4byte gStageDiskManager\n\
_080F2924: .4byte SunkenSecretDisks\n\
_080F2928: .4byte gJoypad\n\
_080F292C: .4byte StringOfsTable\n\
_080F2930: .4byte StrID_ARRAY_08386294\n\
_080F2934: .4byte gStringData\n\
_080F2938: .4byte Unicode_CursorUp\n\
_080F293C: .4byte Unicode_CursorDown\n\
_080F2940:\n\
	ldr r0, _080F2964 @ =gJoypad\n\
	ldrh r1, [r0, #4]\n\
	movs r4, #2\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080F296C\n\
	movs r0, #3\n\
	bl PlaySound\n\
	ldr r2, _080F2968 @ =gTextWindow+8\n\
	ldrh r1, [r2]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #3\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F2964: .4byte gJoypad\n\
_080F2968: .4byte gTextWindow+8\n\
_080F296C:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080F2976\n\
	b _080F2BF8\n\
_080F2976:\n\
	movs r0, #2\n\
	bl PlaySound\n\
	ldr r2, _080F29A4 @ =gTextWindow+8\n\
	ldrh r1, [r2]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _080F29A8 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	str r4, [r0]\n\
	movs r2, #4\n\
	ldrsh r0, [r6, r2]\n\
	lsls r0, r0, #1\n\
	add r0, sp\n\
	ldrh r0, [r0]\n\
	strh r0, [r6, #4]\n\
	movs r0, #5\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F29A4: .4byte gTextWindow+8\n\
_080F29A8: .4byte gStageRun\n\
_080F29AC:\n\
	ldr r0, _080F29FC @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	beq _080F29BA\n\
	cmp r0, #4\n\
	beq _080F29BA\n\
	b _080F2BF8\n\
_080F29BA:\n\
	movs r0, #0x97\n\
	bl ClearBlink\n\
	movs r0, #0x98\n\
	bl ClearBlink\n\
	ldr r4, _080F2A00 @ =0x087044BC\n\
	ldr r0, [r4]\n\
	ldr r5, _080F2A04 @ =0x08704520\n\
	adds r0, r0, r5\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl LoadGraphic\n\
	ldr r0, [r4]\n\
	ldr r1, _080F2A08 @ =0x0870452C\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	bl LoadPalette\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	strb r0, [r6, #3]\n\
_080F29E8:\n\
	ldr r2, _080F29FC @ =gTextWindow+8\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, #0\n\
	beq _080F2A0C\n\
_080F29F0:\n\
	ldrh r1, [r2]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	b _080F2BF8\n\
	.align 2, 0\n\
_080F29FC: .4byte gTextWindow+8\n\
_080F2A00: .4byte gStageTilesetOffsets+12\n\
_080F2A04: .4byte gSnowTilesetGraphics+36\n\
_080F2A08: .4byte gSnowTilesetGraphics+48\n\
_080F2A0C:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r0, r6, #0\n\
	bl SetGameMode\n\
	b _080F2BF8\n\
_080F2A18:\n\
	ldr r5, _080F2A88 @ =gStageRun\n\
	movs r2, #0xaa\n\
	lsls r2, r2, #1\n\
	adds r2, r2, r5\n\
	mov sb, r2\n\
	ldr r7, [r2]\n\
	cmp r7, #0\n\
	beq _080F2A2A\n\
	b _080F2BF8\n\
_080F2A2A:\n\
	ldr r1, _080F2A8C @ =gStageEntityManager\n\
	ldr r0, _080F2A90 @ =0x0000020E\n\
	adds r1, r1, r0\n\
	ldrh r2, [r1]\n\
	movs r0, #1\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	ldrb r0, [r6, #4]\n\
	bl getSunkenLibRoomCoord\n\
	mov r8, r0\n\
	adds r4, r5, #0\n\
	adds r4, #0xe8\n\
	adds r0, r4, #0\n\
	movs r1, #3\n\
	bl SetCameraMode\n\
	movs r0, #8\n\
	strb r0, [r4, #0x19]\n\
	strh r7, [r4, #0x22]\n\
	mov r1, r8\n\
	str r1, [r4, #0x48]\n\
	movs r2, #0x90\n\
	lsls r2, r2, #1\n\
	adds r1, r5, r2\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	str r0, [r1]\n\
	ldr r0, [r2, #4]\n\
	str r0, [r1, #4]\n\
	movs r1, #0x9a\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	str r7, [r0]\n\
	movs r2, #0x9e\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	str r7, [r0]\n\
	movs r0, #1\n\
	mov r5, sb\n\
	str r0, [r5]\n\
	ldr r1, _080F2A94 @ =0x00000ECC\n\
	adds r0, r6, r1\n\
	str r7, [r0]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F2A88: .4byte gStageRun\n\
_080F2A8C: .4byte gStageEntityManager\n\
_080F2A90: .4byte 0x0000020E\n\
_080F2A94: .4byte 0x00000ECC\n\
_080F2A98:\n\
	ldr r0, _080F2AE0 @ =gBlendRegBuffer\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	strh r1, [r0, #2]\n\
	ldr r2, _080F2AE4 @ =0x00000ECC\n\
	adds r4, r6, r2\n\
	ldr r0, [r4]\n\
	cmp r0, #0\n\
	bne _080F2AB8\n\
	ldrb r0, [r6, #4]\n\
	bl getSunkenLibRoomCoord\n\
	movs r1, #0x18\n\
	bl CreateScriptActor\n\
	str r0, [r4]\n\
_080F2AB8:\n\
	ldr r0, _080F2AE8 @ =gStageRun\n\
	movs r5, #0xaa\n\
	lsls r5, r5, #1\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _080F2AC8\n\
	b _080F2BF8\n\
_080F2AC8:\n\
	ldr r1, _080F2AEC @ =AfterSearchTextIDs\n\
	movs r2, #4\n\
	ldrsh r0, [r6, r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	bl PrintNormalMessage\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F2AE0: .4byte gBlendRegBuffer\n\
_080F2AE4: .4byte 0x00000ECC\n\
_080F2AE8: .4byte gStageRun\n\
_080F2AEC: .4byte AfterSearchTextIDs\n\
_080F2AF0:\n\
	ldr r1, _080F2B14 @ =gBlendRegBuffer\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	strh r0, [r1, #2]\n\
	ldr r0, _080F2B18 @ =gTextWindow+8\n\
	ldrh r0, [r0, #2]\n\
	cmp r0, #0\n\
	bne _080F2BF8\n\
	ldr r0, _080F2B1C @ =gStageRun\n\
	movs r5, #0xaa\n\
	lsls r5, r5, #1\n\
	adds r0, r0, r5\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F2B14: .4byte gBlendRegBuffer\n\
_080F2B18: .4byte gTextWindow+8\n\
_080F2B1C: .4byte gStageRun\n\
_080F2B20:\n\
	ldr r1, _080F2BC8 @ =gBlendRegBuffer\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	strh r0, [r1, #2]\n\
	ldr r7, _080F2BCC @ =gStageRun\n\
	movs r0, #0xaa\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	mov sl, r0\n\
	ldr r5, [r0]\n\
	cmp r5, #0\n\
	bne _080F2BF8\n\
	ldr r1, [r7, #0x20]\n\
	mov sb, r1\n\
	movs r2, #0x54\n\
	add r2, sb\n\
	mov r8, r2\n\
	ldr r1, _080F2BD0 @ =0x00000ECC\n\
	adds r0, r6, r1\n\
	ldr r2, [r0]\n\
	cmp r2, #0\n\
	beq _080F2B84\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	adds r0, r2, #0\n\
	adds r0, #0x8c\n\
	str r5, [r0]\n\
	adds r0, #4\n\
	str r5, [r0]\n\
	adds r1, r2, #0\n\
	adds r1, #0x94\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldrb r1, [r2, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r2, #0xa]\n\
	ldr r1, _080F2BD4 @ =gSolidFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #0x14]\n\
_080F2B84:\n\
	adds r4, r7, #0\n\
	adds r4, #0xe8\n\
	adds r0, r4, #0\n\
	movs r1, #6\n\
	bl SetCameraMode\n\
	movs r0, #8\n\
	strb r0, [r4, #0x19]\n\
	strh r5, [r4, #0x22]\n\
	mov r2, r8\n\
	str r2, [r4, #0x48]\n\
	movs r0, #0x90\n\
	lsls r0, r0, #1\n\
	adds r1, r7, r0\n\
	mov r2, sb\n\
	ldr r0, [r2, #0x54]\n\
	str r0, [r1]\n\
	mov r2, r8\n\
	ldr r0, [r2, #4]\n\
	str r0, [r1, #4]\n\
	movs r1, #0x9a\n\
	lsls r1, r1, #1\n\
	adds r0, r7, r1\n\
	str r5, [r0]\n\
	movs r2, #0x9e\n\
	lsls r2, r2, #1\n\
	adds r0, r7, r2\n\
	str r5, [r0]\n\
	movs r0, #1\n\
	mov r5, sl\n\
	str r0, [r5]\n\
	ldrb r0, [r6, #3]\n\
	adds r0, #1\n\
	b _080F2BF6\n\
	.align 2, 0\n\
_080F2BC8: .4byte gBlendRegBuffer\n\
_080F2BCC: .4byte gStageRun\n\
_080F2BD0: .4byte 0x00000ECC\n\
_080F2BD4: .4byte gSolidFnTable\n\
_080F2BD8:\n\
	ldr r0, _080F2C14 @ =gStageRun\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080F2BF8\n\
	ldr r1, _080F2C18 @ =gStageEntityManager\n\
	ldr r2, _080F2C1C @ =0x0000020E\n\
	adds r1, r1, r2\n\
	ldrh r2, [r1]\n\
	ldr r0, _080F2C20 @ =0x0000FFFE\n\
	ands r0, r2\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
_080F2BF6:\n\
	strb r0, [r6, #3]\n\
_080F2BF8:\n\
	movs r0, #0x97\n\
	bl UpdateBlinkMotionState\n\
	movs r0, #0x98\n\
	bl UpdateBlinkMotionState\n\
	add sp, #0x20\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080F2C14: .4byte gStageRun\n\
_080F2C18: .4byte gStageEntityManager\n\
_080F2C1C: .4byte 0x0000020E\n\
_080F2C20: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

/**
 * @brief 図書館で検索マシンで検索した時のゼロのリアクション
 * @note idx = まだ取得してないデータ数-1
 */
static const TextID SearchReactionTexts[4] = {0x0F06, 0x0F05, 0x0F04, 0x0F03};

static const disk_t SunkenSecretDisks[4] = {
    DISK_ID(DISK_FILE_D),
    DISK_ID(DISK_FILE_K),
    DISK_ID(DISK_FILE_J),
    DISK_ID(DISK_FILE_L),
};

static const str_id_t StrID_ARRAY_08386294[4] = {0x03DE, 0x03DF, 0x03E0, 0x03E1};

/*
  xxx ノ データガ アル
  エリアヲ サーチシマシタ
  サイド ジョウホウガ
  ヒツヨウナ トキハ
  コンソールヲ シラベテクダサイ
*/
static const TextID AfterSearchTextIDs[4] = {0x0F08, 0x0F09, 0x0F0A, 0x0F0B};
