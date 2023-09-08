#include "link.h"

#include "global.h"
#include "mmbn4.h"

static void InitTimer(void);
static void StopTimer(void);
static void StartTransfer(void);

static void DoRecv(void);
static void DoSend(void);
static void SendRecvDone(void);
static bool8 DoHandshake(void);

#define SIO_MULTI_CNT ((struct SioMultiCnt *)REG_ADDR_SIOCNT)

void DisableSerial(void) {
  gLinkSavedIme = REG_IME;
  REG_IME = 0;
  REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
  REG_IME = gLinkSavedIme;

  REG_SIOCNT = SIO_MULTI_MODE;
  REG_TM3CNT_H = 0;
  REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
  CpuFill32(0, &gLink, sizeof(gLink));
  CpuFill16(0, u8_ARRAY_020014fc, 4);
  u8_ARRAY_020014fc[1] = 0;
}

NAKED static void EnableSerial(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	ldr r6, _08002560 @ =0x02000004\n\
	ldr r3, _08002564 @ =0x04000208\n\
	ldrh r2, [r3]\n\
	movs r4, #0\n\
	strh r4, [r3]\n\
	ldr r5, _08002568 @ =0x04000200\n\
	ldrh r1, [r5]\n\
	ldr r0, _0800256C @ =0x0000FF3F\n\
	ands r0, r1\n\
	strh r0, [r5]\n\
	strh r2, [r3]\n\
	ldr r0, _08002570 @ =0x04000134\n\
	strh r4, [r0]\n\
	ldr r2, _08002574 @ =0x04000128\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	adds r0, r1, #0\n\
	strh r0, [r2]\n\
	ldrh r0, [r2]\n\
	ldr r7, _08002578 @ =0x00004003\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldrh r2, [r3]\n\
	strh r2, [r6]\n\
	strh r4, [r3]\n\
	ldrh r0, [r5]\n\
	movs r1, #0x80\n\
	orrs r0, r1\n\
	strh r0, [r5]\n\
	strh r2, [r3]\n\
	ldr r0, _0800257C @ =0x0400012A\n\
	strh r4, [r0]\n\
	ldr r2, _08002580 @ =0x04000120\n\
	movs r0, #0\n\
	movs r1, #0\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r1, _08002584 @ =gLink\n\
	ldr r2, _08002588 @ =0x05000266\n\
	mov r0, sp\n\
	bl CpuSet\n\
	add r0, sp, #4\n\
	strh r5, [r0]\n\
	ldr r1, _0800258C @ =0x020014FC\n\
	ldr r2, _08002590 @ =0x01000002\n\
	bl CpuSet\n\
	ldr r0, _08002594 @ =0x02000006\n\
	strb r4, [r0]\n\
	ldr r0, _08002598 @ =0x02000007\n\
	strb r4, [r0]\n\
	ldr r0, _0800259C @ =0x02000008\n\
	strb r4, [r0]\n\
	ldr r0, _080025A0 @ =0x020014F0\n\
	strb r4, [r0]\n\
	ldr r0, _080025A4 @ =gLastRecvQueueCount\n\
	strb r4, [r0]\n\
	ldr r0, _080025A8 @ =0x02000009\n\
	strb r4, [r0]\n\
	ldr r0, _080025AC @ =0x0200000A\n\
	strh r5, [r0]\n\
	ldr r0, _080025B0 @ =0x0200000C\n\
	strh r5, [r0]\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08002560: .4byte 0x02000004\n\
_08002564: .4byte 0x04000208\n\
_08002568: .4byte 0x04000200\n\
_0800256C: .4byte 0x0000FF3F\n\
_08002570: .4byte 0x04000134\n\
_08002574: .4byte 0x04000128\n\
_08002578: .4byte 0x00004003\n\
_0800257C: .4byte 0x0400012A\n\
_08002580: .4byte 0x04000120\n\
_08002584: .4byte gLink\n\
_08002588: .4byte 0x05000266\n\
_0800258C: .4byte 0x020014FC\n\
_08002590: .4byte 0x01000002\n\
_08002594: .4byte 0x02000006\n\
_08002598: .4byte 0x02000007\n\
_0800259C: .4byte 0x02000008\n\
_080025A0: .4byte 0x020014F0\n\
_080025A4: .4byte gLastRecvQueueCount\n\
_080025A8: .4byte 0x02000009\n\
_080025AC: .4byte 0x0200000A\n\
_080025B0: .4byte 0x0200000C\n\
 .syntax divided\n");
}

void ResetSerial(void) {
  EnableSerial();
  DisableSerial();
}

NAKED u32 LinkMain1(u8 *shouldAdvanceLinkState, u16 *sendCmd, u16 (*recvCmds)[CMD_LENGTH]) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r1, #0\n\
	adds r6, r2, #0\n\
	ldr r0, _080025E0 @ =gLink\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #4\n\
	bhi _08002676\n\
	lsls r0, r0, #2\n\
	ldr r1, _080025E4 @ =_080025E8\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080025E0: .4byte gLink\n\
_080025E4: .4byte _080025E8\n\
_080025E8: @ jump table\n\
	.4byte _080025FC @ case 0\n\
	.4byte _0800260C @ case 1\n\
	.4byte _08002624 @ case 2\n\
	.4byte _08002660 @ case 3\n\
	.4byte _0800266A @ case 4\n\
_080025FC:\n\
	bl DisableSerial\n\
	ldr r1, _08002608 @ =gLink\n\
	movs r0, #1\n\
	strb r0, [r1, #1]\n\
	b _08002676\n\
	.align 2, 0\n\
_08002608: .4byte gLink\n\
_0800260C:\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	bne _08002676\n\
	bl EnableSerial\n\
	ldr r1, _08002620 @ =gLink\n\
	movs r0, #2\n\
	strb r0, [r1, #1]\n\
	b _08002676\n\
	.align 2, 0\n\
_08002620: .4byte gLink\n\
_08002624:\n\
	ldrb r1, [r4]\n\
	cmp r1, #1\n\
	beq _08002634\n\
	cmp r1, #2\n\
	beq _0800264C\n\
	bl CheckMasterOrSlave\n\
	b _08002676\n\
_08002634:\n\
	ldr r2, _08002648 @ =gLink\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	beq _08002676\n\
	ldrb r0, [r2, #3]\n\
	cmp r0, #1\n\
	bls _08002676\n\
	strb r1, [r2, #0x10]\n\
	b _08002676\n\
	.align 2, 0\n\
_08002648: .4byte gLink\n\
_0800264C:\n\
	ldr r0, _08002658 @ =gLink\n\
	movs r1, #0\n\
	strb r1, [r0, #1]\n\
	ldr r0, _0800265C @ =0x0400012A\n\
	strh r1, [r0]\n\
	b _08002676\n\
	.align 2, 0\n\
_08002658: .4byte gLink\n\
_0800265C: .4byte 0x0400012A\n\
_08002660:\n\
	bl InitTimer\n\
	ldr r1, _080026B8 @ =gLink\n\
	movs r0, #4\n\
	strb r0, [r1, #1]\n\
_0800266A:\n\
	adds r0, r5, #0\n\
	bl EnqueueSendCmd\n\
	adds r0, r6, #0\n\
	bl DequeueRecvCmds\n\
_08002676:\n\
	movs r0, #0\n\
	strb r0, [r4]\n\
	ldr r1, _080026B8 @ =gLink\n\
	ldrb r2, [r1, #2]\n\
	ldrb r0, [r1, #3]\n\
	lsls r0, r0, #2\n\
	orrs r2, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #8\n\
	bne _0800268E\n\
	movs r0, #0x20\n\
	orrs r2, r0\n\
_0800268E:\n\
	ldrb r0, [r1, #0xc]\n\
	lsls r3, r0, #8\n\
	ldrb r0, [r1, #0x11]\n\
	lsls r4, r0, #9\n\
	ldrb r0, [r1, #0x12]\n\
	lsls r5, r0, #0x10\n\
	ldrb r0, [r1, #0x13]\n\
	lsls r6, r0, #0x11\n\
	ldrb r0, [r1, #0x14]\n\
	lsls r7, r0, #0x12\n\
	ldrb r0, [r1, #0x15]\n\
	lsls r0, r0, #0x14\n\
	mov ip, r0\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #4\n\
	bne _080026BC\n\
	movs r0, #0x40\n\
	orrs r0, r3\n\
	orrs r0, r2\n\
	b _080026C0\n\
	.align 2, 0\n\
_080026B8: .4byte gLink\n\
_080026BC:\n\
	adds r0, r2, #0\n\
	orrs r0, r3\n\
_080026C0:\n\
	orrs r0, r4\n\
	orrs r0, r5\n\
	orrs r0, r6\n\
	orrs r0, r7\n\
	mov r2, ip\n\
	orrs r0, r2\n\
	adds r2, r0, #0\n\
	ldrb r0, [r1, #2]\n\
	cmp r0, #3\n\
	bls _080026DA\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xf\n\
	orrs r2, r0\n\
_080026DA:\n\
	adds r0, r2, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static void CheckMasterOrSlave(void) {
  u32 terminals;

  terminals = *(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SD | SIO_MULTI_SI);
  if (terminals == SIO_MULTI_SD && gLink.localId == 0)
    gLink.isMaster = LINK_MASTER;
  else
    gLink.isMaster = LINK_SLAVE;
}

static void InitTimer(void) {
  if (gLink.isMaster) {
    REG_TM3CNT_L = 0xFF7C;
    REG_TM3CNT_H = TIMER_64CLK | TIMER_INTR_ENABLE;
    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = gLinkSavedIme;
  }
}

static void EnqueueSendCmd(u16 *sendCmd) {
  u8 i;
  u8 offset;

  gLinkSavedIme = REG_IME;
  REG_IME = 0;
  if (gLink.sendQueue.count < QUEUE_CAPACITY) {
    offset = gLink.sendQueue.pos + gLink.sendQueue.count;
    if (offset >= QUEUE_CAPACITY) offset -= QUEUE_CAPACITY;

    for (i = 0; i < CMD_LENGTH; i++) {
      sSendNonzeroCheck |= *sendCmd;
      gLink.sendQueue.data[i][offset] = *sendCmd;
      *sendCmd = 0;
      sendCmd++;
    }
  } else {
    gLink.queueFull |= QUEUE_FULL_SEND;
  }
  if (sSendNonzeroCheck) {
    gLink.sendQueue.count++;
    sSendNonzeroCheck = 0;
  }
  REG_IME = gLinkSavedIme;
  gLastSendQueueCount = gLink.sendQueue.count;
}

WIP static void DequeueRecvCmds(u16 (*recvCmds)[CMD_LENGTH]) {
#if MODERN
  u8 i, j;

  gLinkSavedIme = REG_IME;
  REG_IME = 0;
  if (gLink.recvQueue.count == 0) {
    for (i = 0; i < gLink.playerCount; i++) {
      for (j = 0; j < CMD_LENGTH; j++) {
        recvCmds[i][j] = 0;
      }
    }
    gLink.receivedNothing = TRUE;
  } else {
    for (i = 0; i < gLink.playerCount; i++) {
      for (j = 0; j < CMD_LENGTH; j++) {
        recvCmds[i][j] = gLink.recvQueue.data[i][j][gLink.recvQueue.pos];
      }
    }
    gLink.recvQueue.count--;
    gLink.recvQueue.pos++;
    if (gLink.recvQueue.pos >= QUEUE_CAPACITY) {
      gLink.recvQueue.pos = 0;
    }
    gLink.receivedNothing = FALSE;
  }
  REG_IME = gLinkSavedIme;
#else
  INCCODE("asm/wip/DequeueRecvCmds.inc");
#endif
}

void LinkVSync(void) {
  if (gLink.isMaster) {
    switch (gLink.state) {
      case LINK_STATE_CONN_ESTABLISHED: {
        if (gLink.serialIntrCounter < 9) {
          if (gLink.hardwareError == FALSE) {
            gLink.lag = LAG_MASTER;
            return;
          }
        } else {
          if (gLink.lag != LAG_NONE) {
            return;
          }
          gLink.serialIntrCounter = 0;
        }

        FALLTHROUGH;
      }

      case LINK_STATE_HANDSHAKE: {
        StartTransfer();
        if ((u8_02001500 == 2) && (++sNumVBlanksWithoutSerialIntr > 6)) {
          gLink.lag = LAG_SLAVE;
          gLink.localId = 0;
          gLink.playerCount = 0;
          gLink.link_field_F = FALSE;
        }
        break;
      }
    }
    return;
  }

  if (gLink.state == LINK_STATE_CONN_ESTABLISHED || gLink.state == LINK_STATE_HANDSHAKE) {
    if (++sNumVBlanksWithoutSerialIntr > 6) {
      if (gLink.state == LINK_STATE_CONN_ESTABLISHED) {
        gLink.lag = LAG_SLAVE;
      }
      if (gLink.state == LINK_STATE_HANDSHAKE) {
        gLink.localId = 0;
        gLink.playerCount = 0;
        gLink.link_field_F = FALSE;
      }
    }
  }
}

void Timer3Intr(void) {
  StopTimer();
  StartTransfer();
}

void SerialCB(void) {
  u8 i;
  struct SioMultiCnt cnt = *SIO_MULTI_CNT;
  gLink.localId = cnt.id;

  switch (gLink.state) {
    case LINK_STATE_CONN_ESTABLISHED: {
      if (cnt.error) {
        gLink.hardwareError = TRUE;
      }
      DoRecv();
      DoSend();
      SendRecvDone();
      break;
    }
    case LINK_STATE_HANDSHAKE: {
      if (DoHandshake()) {
        if (gLink.isMaster) {
          gLink.state = LINK_STATE_INIT_TIMER;
          gLink.serialIntrCounter = 8;
        } else {
          gLink.state = LINK_STATE_CONN_ESTABLISHED;
        }
        break;
      }
      for (i = 0; i < MAX_LINK_PLAYERS; i++) {
        gLink.unk_2a[i] = 0xFF;
      }
      break;
    }
  }
  gLink.serialIntrCounter++;
  sNumVBlanksWithoutSerialIntr = 0;
  if (gLink.serialIntrCounter == 8) {
    gLastRecvQueueCount = gLink.recvQueue.count;
  }
}

static void StartTransfer(void) { REG_SIOCNT |= SIO_START; }

NAKED static bool8 DoHandshake(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	movs r0, #0\n\
	mov sl, r0\n\
	ldr r1, _08002B00 @ =0x0000FFFF\n\
	mov ip, r1\n\
	ldr r0, _08002B04 @ =0x02001500\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08002AEC\n\
	cmp r0, #2\n\
	beq _08002AEC\n\
	b _08002C5C\n\
_08002AEC:\n\
	ldr r0, _08002B08 @ =gLink\n\
	ldrb r1, [r0, #0x10]\n\
	cmp r1, #1\n\
	bne _08002B24\n\
	ldr r1, _08002B0C @ =0x0400012A\n\
	ldr r2, _08002B10 @ =0x00008FFF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	b _08002B2C\n\
	.align 2, 0\n\
_08002B00: .4byte 0x0000FFFF\n\
_08002B04: .4byte 0x02001500\n\
_08002B08: .4byte gLink\n\
_08002B0C: .4byte 0x0400012A\n\
_08002B10: .4byte 0x00008FFF\n\
_08002B14:\n\
	mov r0, sb\n\
	adds r0, #0x2a\n\
	adds r0, r4, r0\n\
	movs r1, #0xff\n\
	strb r1, [r0]\n\
	movs r7, #0\n\
	mov sl, r7\n\
	b _08002BF6\n\
_08002B24:\n\
	ldr r2, _08002BA0 @ =0x0400012A\n\
	ldr r1, _08002BA4 @ =0x020014F4\n\
	ldrh r0, [r1]\n\
	strh r0, [r2]\n\
_08002B2C:\n\
	movs r0, #0\n\
	ldr r1, _08002BA8 @ =gLink\n\
	strb r0, [r1, #0x10]\n\
	movs r4, #0\n\
	adds r2, r1, #0\n\
	adds r2, #4\n\
	adds r5, r1, #0\n\
	adds r5, #0x2a\n\
	movs r3, #0xff\n\
_08002B3E:\n\
	adds r0, r4, r5\n\
	ldrb r1, [r0]\n\
	orrs r1, r3\n\
	strb r1, [r0]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #3\n\
	bls _08002B3E\n\
	ldr r0, _08002BAC @ =0x04000120\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	movs r4, #0\n\
	movs r7, #4\n\
	rsbs r7, r7, #0\n\
	mov r8, r7\n\
	subs r0, r2, #4\n\
	mov sb, r0\n\
	adds r5, r2, #0\n\
	mov r6, sb\n\
	adds r6, #0x2a\n\
_08002B6C:\n\
	ldr r2, _08002BA4 @ =0x020014F4\n\
	ldrh r1, [r2]\n\
	mov r7, r8\n\
	ands r1, r7\n\
	lsls r2, r4, #1\n\
	adds r0, r2, r5\n\
	ldrh r3, [r0]\n\
	adds r0, r3, #0\n\
	ands r0, r7\n\
	cmp r1, r0\n\
	beq _08002B90\n\
	adds r0, r3, #0\n\
	ldr r1, _08002BB0 @ =0x00008FFF\n\
	cmp r0, r1\n\
	beq _08002B90\n\
	ldr r7, _08002BB4 @ =0x0000FFC6\n\
	cmp r0, r7\n\
	bne _08002BDA\n\
_08002B90:\n\
	adds r0, r2, r5\n\
	ldrh r0, [r0]\n\
	ldr r1, _08002BB4 @ =0x0000FFC6\n\
	cmp r0, r1\n\
	bne _08002BB8\n\
	adds r1, r4, r6\n\
	movs r0, #2\n\
	b _08002BBC\n\
	.align 2, 0\n\
_08002BA0: .4byte 0x0400012A\n\
_08002BA4: .4byte 0x020014F4\n\
_08002BA8: .4byte gLink\n\
_08002BAC: .4byte 0x04000120\n\
_08002BB0: .4byte 0x00008FFF\n\
_08002BB4: .4byte 0x0000FFC6\n\
_08002BB8:\n\
	adds r1, r4, r6\n\
	movs r0, #1\n\
_08002BBC:\n\
	strb r0, [r1]\n\
	mov r0, sl\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sl, r0\n\
	adds r0, r2, r5\n\
	ldrh r1, [r0]\n\
	cmp ip, r1\n\
	bls _08002BEC\n\
	cmp r1, #0\n\
	beq _08002BEC\n\
	adds r0, r1, #0\n\
	mov ip, r0\n\
	b _08002BEC\n\
_08002BDA:\n\
	ldr r2, _08002C18 @ =0x0000FFFF\n\
	cmp r0, r2\n\
	bne _08002B14\n\
	mov r7, sb\n\
	ldrb r7, [r7, #2]\n\
	cmp r4, r7\n\
	bne _08002BEC\n\
	movs r0, #0\n\
	mov sl, r0\n\
_08002BEC:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #3\n\
	bls _08002B6C\n\
_08002BF6:\n\
	mov r2, sl\n\
	ldr r1, _08002C1C @ =gLink\n\
	strb r2, [r1, #3]\n\
	mov r0, sl\n\
	cmp r0, #1\n\
	bls _08002C44\n\
	ldr r7, _08002C20 @ =0x02000008\n\
	ldrb r7, [r7]\n\
	cmp r0, r7\n\
	bne _08002C28\n\
	ldrh r1, [r1, #4]\n\
	ldr r0, _08002C24 @ =0x00008FFF\n\
	cmp r1, r0\n\
	bne _08002C28\n\
	movs r0, #1\n\
	b _08002C98\n\
	.align 2, 0\n\
_08002C18: .4byte 0x0000FFFF\n\
_08002C1C: .4byte gLink\n\
_08002C20: .4byte 0x02000008\n\
_08002C24: .4byte 0x00008FFF\n\
_08002C28:\n\
	ldr r1, _08002C40 @ =gLink\n\
	ldrb r0, [r1, #3]\n\
	cmp r0, #1\n\
	bls _08002C44\n\
	movs r0, #3\n\
	mov r2, ip\n\
	ands r2, r0\n\
	mov ip, r2\n\
	mov r0, ip\n\
	adds r0, #1\n\
	strb r0, [r1, #0x11]\n\
	b _08002C4A\n\
	.align 2, 0\n\
_08002C40: .4byte gLink\n\
_08002C44:\n\
	movs r0, #0\n\
	ldr r7, _08002C54 @ =gLink\n\
	strb r0, [r7, #0x11]\n\
_08002C4A:\n\
	ldr r1, _08002C54 @ =gLink\n\
	ldrb r0, [r1, #3]\n\
	ldr r2, _08002C58 @ =0x02000008\n\
	strb r0, [r2]\n\
	b _08002C96\n\
	.align 2, 0\n\
_08002C54: .4byte gLink\n\
_08002C58: .4byte 0x02000008\n\
_08002C5C:\n\
	ldr r0, _08002C70 @ =gLink\n\
	ldrb r1, [r0, #0x10]\n\
	cmp r1, #1\n\
	bne _08002C7C\n\
	ldr r1, _08002C74 @ =0x0400012A\n\
	ldr r7, _08002C78 @ =0x00008FFF\n\
	adds r0, r7, #0\n\
	strh r0, [r1]\n\
	b _08002C84\n\
	.align 2, 0\n\
_08002C70: .4byte gLink\n\
_08002C74: .4byte 0x0400012A\n\
_08002C78: .4byte 0x00008FFF\n\
_08002C7C:\n\
	ldr r0, _08002CA8 @ =0x0400012A\n\
	ldr r1, _08002CAC @ =0x020014F4\n\
	ldrh r1, [r1]\n\
	strh r1, [r0]\n\
_08002C84:\n\
	movs r0, #0\n\
	ldr r1, _08002CB0 @ =gLink\n\
	strb r0, [r1, #0x10]\n\
	ldr r0, _08002CB4 @ =0x04000120\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	ldr r2, _08002CB0 @ =gLink\n\
	str r0, [r2, #4]\n\
	str r1, [r2, #8]\n\
_08002C96:\n\
	movs r0, #0\n\
_08002C98:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08002CA8: .4byte 0x0400012A\n\
_08002CAC: .4byte 0x020014F4\n\
_08002CB0: .4byte gLink\n\
_08002CB4: .4byte 0x04000120\n\
 .syntax divided\n");
}

static void DoRecv(void) {
  u16 recv[4];
  u8 i;
  u8 index;

  *(u64 *)recv = REG_SIOMLT_RECV;

  for (i = 0; i < 4; i++) {
    FUN_08000eac(recv[i], i, gLink.recvCmdIndex);
  }

  if (gLink.sendCmdIndex == 0) {
    for (i = 0; i < gLink.playerCount; i++) {
      if (gLink.unk_2a[i] == 1) {
        if (gLink.checksum != recv[i] && sChecksumAvailable) gLink.badChecksum = TRUE;
      } else if (gLink.unk_2a[i] == 2) {
        if (recv[i] == 0xFFC6) gLink.unk_20[i] = 0;
      }
    }
    gLink.checksum = 0;
    sChecksumAvailable = TRUE;
  } else {
    index = gLink.recvQueue.pos + gLink.recvQueue.count;
    if (index >= QUEUE_CAPACITY) index -= QUEUE_CAPACITY;

    if (gLink.recvQueue.count < QUEUE_CAPACITY) {
      for (i = 0; i < gLink.playerCount; i++) {
        if (gLink.unk_2a[i] == 1) {
          gLink.checksum += recv[i];
          sRecvNonzeroCheck |= recv[i];
          gLink.recvQueue.data[i][gLink.recvCmdIndex][index] = recv[i];

        } else if (gLink.unk_2a[i] == 2) {
          if (gLink.sendCmdIndex == 4) {
            gLink.unk_18[i] = recv[i];

          } else if (gLink.sendCmdIndex == 3) {
            gLink.unk_20[i] += (1 + recv[i]);

          } else if (gLink.sendCmdIndex == 5) {
            gLink.unk_20[i] += recv[i];
          }
        }
      }
    } else {
      gLink.queueFull |= QUEUE_FULL_RECV;
    }
    gLink.recvCmdIndex++;
    if (gLink.recvCmdIndex == CMD_LENGTH && sRecvNonzeroCheck) {
      gLink.recvQueue.count++;
      sRecvNonzeroCheck = 0;
    }
  }
}

static void DoSend(void) {
  if (gLink.sendCmdIndex == CMD_LENGTH) {
    REG_SIOMLT_SEND = gLink.checksum;
    if (!sSendBufferEmpty) {
      gLink.sendQueue.count--;
      gLink.sendQueue.pos++;
      if (gLink.sendQueue.pos >= QUEUE_CAPACITY) {
        gLink.sendQueue.pos = 0;
      }
    } else {
      sSendBufferEmpty = FALSE;
    }
  } else {
    if (gLink.sendCmdIndex == 0 && gLink.sendQueue.count == 0) {
      sSendBufferEmpty = TRUE;
    }
    if (sSendBufferEmpty) {
      REG_SIOMLT_SEND = 0;
    } else {
      REG_SIOMLT_SEND = gLink.sendQueue.data[gLink.sendCmdIndex][gLink.sendQueue.pos];
    }
    gLink.sendCmdIndex++;
  }
}

static void StopTimer(void) {
  if (gLink.isMaster) {
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFF7C;
  }
}

static void SendRecvDone(void) {
  if (gLink.recvCmdIndex == CMD_LENGTH) {
    gLink.sendCmdIndex = 0;
    gLink.recvCmdIndex = 0;
  } else if (gLink.isMaster) {
    REG_TM3CNT_H |= TIMER_ENABLE;
  }
}

void ResetSendBuffer(void) {
  u8 i, j;
  gLink.sendQueue.count = 0;
  gLink.sendQueue.pos = 0;
  for (i = 0; i < CMD_LENGTH; i++) {
    for (j = 0; j < QUEUE_CAPACITY; j++) {
      gLink.sendQueue.data[i][j] = 0xEFFF;
    }
  }
}

void ResetRecvBuffer(void) {
  u8 i, j, k;
  gLink.recvQueue.count = 0;
  gLink.recvQueue.pos = 0;
  for (i = 0; i < MAX_LINK_PLAYERS; i++) {
    for (j = 0; j < CMD_LENGTH; j++) {
      for (k = 0; k < QUEUE_CAPACITY; k++) {
        gLink.recvQueue.data[i][j][k] = LINKCMD_NONE;
      }
    }
  }
}

u8 GetLinkState(void) { return gLink.state; }
u8 get0x02001539(void) { return gLink.recvCmdIndex; }

#if MODERN == 0
static void unused_Set0x02001500(u8 val) {
  u8_02001500 = val;
  return;
}
#endif

u8 FUN_0800309c(u8 idx) { return gLink.unk_2a[idx]; }

u8 GetLastSendQueueCount(void) { return gLastSendQueueCount; }
u8 GetLastRecvQueueCount(void) { return gLastRecvQueueCount; }

#if MODERN == 0
static bool8 unused_080030c8(void) {
  if ((gLastSendQueueCount < 6) && (gLastRecvQueueCount < 6)) {
    return FALSE;
  } else {
    return TRUE;
  }
}
#endif
