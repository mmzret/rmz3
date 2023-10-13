#include "syssav.h"

#include "gba/gba.h"
#include "global.h"
#include "sram.h"

// 0x08338dc4
static const mod_t MsgBoxModIDs[8] = {76, 77, 79, 98, 112, 120, 137, 139};
static const mod_t TitleScreenModIDs[4] = {63, 114, 152, 154};
static const mod_t ElevatorModIDs[2] = {65, 107};
static const mod_t WeatherModIDs[2] = {133, 84};
static const mod_t CielComputerModIDs[4] = {88, 96, 113, 134};
static const mod_t LifeEnergyModIDs[2] = {78, 150};
static const mod_t ECrystalModIDs[2] = {85, 117};
static const mod_t DiskModIDs[2] = {105, 135};
static const mod_t ExtraLifeModIDs[2] = {72, 126};
static const mod_t BulletModIDs[2] = {71, 109};
static const mod_t AllResetModIDs[4] = {82, 95, 122, 125};

/**
 * @note 0x080082e4
 */
void LoadSystemData(void) {
  s8 health = -1;
  if (CheckSavedataCorrect(SLOT_SYSTEM, sizeof(gSystemSavedataManager))) {
    s8 tmp;
    sram_08003378(SLOT_SYSTEM, (u8*)&gSystemSavedataManager, sizeof(gSystemSavedataManager));
    do {
      UpdateSram();
      if (gSramState.unk_00 != 1) {
        tmp = gSramState.health;
      } else {
        tmp = 0;
      }
      health = tmp;
    } while (tmp == 0);
  }

  if (health < 0) {
    u32 fill = 0;
    struct SystemSavedataManager* s = &gSystemSavedataManager;
    CpuFastFill(fill, s, (sizeof(gSystemSavedataManager) / 32) * 32);
    CpuFill32(fill, &s->mmbn4, sizeof(gSystemSavedataManager) % 32);
    s->mmbn4 = 0x32DA;
    SaveSystemData();
  }
}

/**
 * @note 0x08008368
 */
void SaveSystemData(void) {
  sram_08003330(SLOT_SYSTEM, gSystemSavedataManager.flags, sizeof(gSystemSavedataManager));
  do {
    do {
      UpdateSram();
    } while (gSramState.unk_00 == 2);
  } while (gSramState.unk_1c == 0);
}

/**
 * @brief 020021b0 から (r0+62) bit をセットすることで改造カードの有効無効化を行う
 * @note 0x08008398
 */
NAKED void ToggleMods(mod_t id) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	lsls r0, r0, #0x18\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #0x16\n\
	adds r0, r0, r1\n\
	lsrs r6, r0, #0x18\n\
	movs r5, #0\n\
	ldr r7, _08008420 @ =gSystemSavedataManager\n\
	ldr r0, _08008424 @ =0x08338DE2\n\
	mov sl, r0\n\
	ldr r1, _08008428 @ =0x08338DC4\n\
	mov r8, r1\n\
	adds r4, r7, #0\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_080083C2:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	mov r1, r8\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _0800842C\n\
	lsrs r0, r1, #0x1b\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080083E4\n\
	b _080089BE\n\
_080083E4:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x44\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x44\n\
	mov ip, r1\n\
	ldr r4, _08008428 @ =0x08338DC4\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080083F8:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #7\n\
	ble _080083F8\n\
	b _08008438\n\
	.align 2, 0\n\
_08008420: .4byte gSystemSavedataManager\n\
_08008424: .4byte AllResetModIDs\n\
_08008428: .4byte MsgBoxModIDs\n\
_0800842C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	ble _080083C2\n\
_08008438:\n\
	movs r5, #0\n\
	ldr r4, _080084A4 @ =0x08338DCC\n\
	ldr r1, _080084A8 @ =gSystemSavedataManager\n\
	mov r8, r1\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_08008448:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _080084AC\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08008468\n\
	b _080089B4\n\
_08008468:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x45\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x45\n\
	mov ip, r1\n\
	ldr r4, _080084A4 @ =0x08338DCC\n\
	movs r1, #1\n\
	mov r8, r1\n\
_0800847C:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #3\n\
	ble _0800847C\n\
	b _080084B8\n\
	.align 2, 0\n\
_080084A4: .4byte TitleScreenModIDs\n\
_080084A8: .4byte gSystemSavedataManager\n\
_080084AC:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _08008448\n\
_080084B8:\n\
	movs r5, #0\n\
	ldr r4, _08008524 @ =0x08338DD0\n\
	ldr r0, _08008528 @ =gSystemSavedataManager\n\
	mov r8, r0\n\
	movs r1, #7\n\
	mov sb, r1\n\
	adds r3, r6, #0\n\
	ands r3, r1\n\
_080084C8:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _0800852C\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080084E8\n\
	b _080089AA\n\
_080084E8:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x46\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x46\n\
	mov ip, r1\n\
	ldr r4, _08008524 @ =0x08338DD0\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080084FC:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _080084FC\n\
	b _08008538\n\
	.align 2, 0\n\
_08008524: .4byte ElevatorModIDs\n\
_08008528: .4byte gSystemSavedataManager\n\
_0800852C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _080084C8\n\
_08008538:\n\
	movs r5, #0\n\
	ldr r4, _080085A4 @ =0x08338DD2\n\
	ldr r1, _080085A8 @ =gSystemSavedataManager\n\
	mov r8, r1\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_08008548:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _080085AC\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08008568\n\
	b _080089A0\n\
_08008568:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x47\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x47\n\
	mov ip, r1\n\
	ldr r4, _080085A4 @ =0x08338DD2\n\
	movs r1, #1\n\
	mov r8, r1\n\
_0800857C:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0800857C\n\
	b _080085B8\n\
	.align 2, 0\n\
_080085A4: .4byte WeatherModIDs\n\
_080085A8: .4byte gSystemSavedataManager\n\
_080085AC:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _08008548\n\
_080085B8:\n\
	movs r5, #0\n\
	ldr r4, _08008624 @ =0x08338DD4\n\
	ldr r0, _08008628 @ =gSystemSavedataManager\n\
	mov r8, r0\n\
	movs r1, #7\n\
	mov sb, r1\n\
	adds r3, r6, #0\n\
	ands r3, r1\n\
_080085C8:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _0800862C\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080085E8\n\
	b _08008996\n\
_080085E8:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x48\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x48\n\
	mov ip, r1\n\
	ldr r4, _08008624 @ =0x08338DD4\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080085FC:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #3\n\
	ble _080085FC\n\
	b _08008638\n\
	.align 2, 0\n\
_08008624: .4byte CielComputerModIDs\n\
_08008628: .4byte gSystemSavedataManager\n\
_0800862C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _080085C8\n\
_08008638:\n\
	movs r5, #0\n\
	ldr r4, _080086A4 @ =0x08338DD8\n\
	ldr r1, _080086A8 @ =gSystemSavedataManager\n\
	mov r8, r1\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_08008648:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _080086AC\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08008668\n\
	b _0800898C\n\
_08008668:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x49\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x49\n\
	mov ip, r1\n\
	ldr r4, _080086A4 @ =0x08338DD8\n\
	movs r1, #1\n\
	mov r8, r1\n\
_0800867C:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0800867C\n\
	b _080086B8\n\
	.align 2, 0\n\
_080086A4: .4byte LifeEnergyModIDs\n\
_080086A8: .4byte gSystemSavedataManager\n\
_080086AC:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _08008648\n\
_080086B8:\n\
	movs r5, #0\n\
	ldr r4, _08008724 @ =0x08338DDA\n\
	ldr r0, _08008728 @ =gSystemSavedataManager\n\
	mov r8, r0\n\
	movs r1, #7\n\
	mov sb, r1\n\
	adds r3, r6, #0\n\
	ands r3, r1\n\
_080086C8:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _0800872C\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080086E8\n\
	b _08008982\n\
_080086E8:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x4a\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x4a\n\
	mov ip, r1\n\
	ldr r4, _08008724 @ =0x08338DDA\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080086FC:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _080086FC\n\
	b _08008738\n\
	.align 2, 0\n\
_08008724: .4byte ECrystalModIDs\n\
_08008728: .4byte gSystemSavedataManager\n\
_0800872C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _080086C8\n\
_08008738:\n\
	movs r5, #0\n\
	ldr r4, _080087A4 @ =0x08338DDC\n\
	ldr r1, _080087A8 @ =gSystemSavedataManager\n\
	mov r8, r1\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_08008748:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _080087AC\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08008768\n\
	b _08008978\n\
_08008768:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x4b\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x4b\n\
	mov ip, r1\n\
	ldr r4, _080087A4 @ =0x08338DDC\n\
	movs r1, #1\n\
	mov r8, r1\n\
_0800877C:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0800877C\n\
	b _080087B8\n\
	.align 2, 0\n\
_080087A4: .4byte DiskModIDs\n\
_080087A8: .4byte gSystemSavedataManager\n\
_080087AC:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _08008748\n\
_080087B8:\n\
	movs r5, #0\n\
	ldr r4, _08008824 @ =0x08338DDE\n\
	ldr r0, _08008828 @ =gSystemSavedataManager\n\
	mov r8, r0\n\
	movs r1, #7\n\
	mov sb, r1\n\
	adds r3, r6, #0\n\
	ands r3, r1\n\
_080087C8:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _0800882C\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080087E8\n\
	b _0800896E\n\
_080087E8:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x4c\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x4c\n\
	mov ip, r1\n\
	ldr r4, _08008824 @ =0x08338DDE\n\
	movs r0, #1\n\
	mov r8, r0\n\
_080087FC:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _080087FC\n\
	b _08008838\n\
	.align 2, 0\n\
_08008824: .4byte ExtraLifeModIDs\n\
_08008828: .4byte gSystemSavedataManager\n\
_0800882C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _080087C8\n\
_08008838:\n\
	movs r5, #0\n\
	ldr r4, _080088A4 @ =0x08338DE0\n\
	ldr r1, _080088A8 @ =gSystemSavedataManager\n\
	mov r8, r1\n\
	movs r0, #7\n\
	mov sb, r0\n\
	adds r3, r6, #0\n\
	ands r3, r0\n\
_08008848:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, #0x18\n\
	cmp r6, r0\n\
	bne _080088AC\n\
	lsrs r0, r1, #0x1b\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	asrs r0, r3\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08008868\n\
	b _08008964\n\
_08008868:\n\
	adds r0, r5, #1\n\
	adds r1, r7, #0\n\
	adds r1, #0x4d\n\
	strb r0, [r1]\n\
	movs r5, #0\n\
	subs r1, #0x4d\n\
	mov ip, r1\n\
	ldr r4, _080088A4 @ =0x08338DE0\n\
	movs r1, #1\n\
	mov r8, r1\n\
_0800887C:\n\
	lsls r2, r5, #0x10\n\
	asrs r2, r2, #0x10\n\
	adds r0, r2, r4\n\
	ldrb r1, [r0]\n\
	lsrs r3, r1, #3\n\
	add r3, ip\n\
	mov r0, sb\n\
	ands r0, r1\n\
	mov r1, r8\n\
	lsls r1, r0\n\
	ldrb r0, [r3]\n\
	bics r0, r1\n\
	strb r0, [r3]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	lsrs r5, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	cmp r2, #1\n\
	ble _0800887C\n\
	b _080088B8\n\
	.align 2, 0\n\
_080088A4: .4byte BulletModIDs\n\
_080088A8: .4byte gSystemSavedataManager\n\
_080088AC:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble _08008848\n\
_080088B8:\n\
	movs r5, #0\n\
	ldr r0, _08008930 @ =gSystemSavedataManager\n\
	mov ip, r0\n\
	movs r4, #0\n\
	movs r1, #0x44\n\
	add r1, ip\n\
	mov sb, r1\n\
_080088C6:\n\
	lsls r0, r5, #0x10\n\
	asrs r2, r0, #0x10\n\
	mov r1, sl\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	bne _08008934\n\
	movs r5, #0x3f\n\
	ldr r0, _08008930 @ =gSystemSavedataManager\n\
	mov r8, r0\n\
	movs r6, #7\n\
	movs r7, #1\n\
_080088DE:\n\
	lsls r2, r5, #0x10\n\
	asrs r3, r2, #0x10\n\
	asrs r2, r2, #0x13\n\
	add r2, r8\n\
	adds r0, r3, #0\n\
	ands r0, r6\n\
	adds r1, r7, #0\n\
	lsls r1, r0\n\
	ldrb r0, [r2]\n\
	bics r0, r1\n\
	strb r0, [r2]\n\
	adds r3, #1\n\
	lsls r3, r3, #0x10\n\
	lsrs r5, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	cmp r3, #0xb6\n\
	ble _080088DE\n\
	mov r0, ip\n\
	adds r0, #0x4d\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	subs r0, #1\n\
	strb r4, [r0]\n\
	mov r1, sb\n\
	strb r4, [r1]\n\
	bl SaveSystemData\n\
	b _080089D4\n\
	.align 2, 0\n\
_08008930: .4byte gSystemSavedataManager\n\
_08008934:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _080088C6\n\
	lsrs r0, r6, #3\n\
	adds r1, r0, r7\n\
	ldrb r2, [r1]\n\
	movs r3, #7\n\
	ands r3, r6\n\
	adds r0, r2, #0\n\
	asrs r0, r3\n\
	movs r4, #1\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080089C8\n\
	adds r0, r4, #0\n\
	lsls r0, r3\n\
	bics r2, r0\n\
	strb r2, [r1]\n\
	bl SaveSystemData\n\
	b _080089D4\n\
_08008964:\n\
	adds r1, r7, #0\n\
	adds r1, #0x4d\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080088B8\n\
_0800896E:\n\
	adds r1, r7, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08008838\n\
_08008978:\n\
	adds r1, r7, #0\n\
	adds r1, #0x4b\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080087B8\n\
_08008982:\n\
	adds r1, r7, #0\n\
	adds r1, #0x4a\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08008738\n\
_0800898C:\n\
	adds r1, r7, #0\n\
	adds r1, #0x49\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080086B8\n\
_08008996:\n\
	adds r1, r7, #0\n\
	adds r1, #0x48\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08008638\n\
_080089A0:\n\
	adds r1, r7, #0\n\
	adds r1, #0x47\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080085B8\n\
_080089AA:\n\
	adds r1, r7, #0\n\
	adds r1, #0x46\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08008538\n\
_080089B4:\n\
	adds r1, r7, #0\n\
	adds r1, #0x45\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080084B8\n\
_080089BE:\n\
	adds r1, r7, #0\n\
	adds r1, #0x44\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08008438\n\
_080089C8:\n\
	adds r0, r4, #0\n\
	lsls r0, r3\n\
	orrs r2, r0\n\
	strb r2, [r1]\n\
	bl SaveSystemData\n\
_080089D4:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
     .syntax divided\n");
}

/**
 * @brief ミニゲームが1つでも遊べるなら1が返る
 * @note 0x080089e4
 */
bool8 IsAnyMinigameUnlocked(void) {
  bool8 ok = FALSE;
  if (gSystemSavedataManager.unlockedMinigames[0] == (gSineTable[10 + 0] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[1] == (gSineTable[10 + 1] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[2] == (gSineTable[10 + 2] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[3] == (gSineTable[10 + 3] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[4] == (gSineTable[10 + 4] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[5] == (gSineTable[10 + 5] & 0xFF)) {
    ok = TRUE;
  } else if (gSystemSavedataManager.unlockedMinigames[6] == (gSineTable[10 + 6] & 0xFF)) {
    ok = TRUE;
  }
  return ok;
}
