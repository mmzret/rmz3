#ifndef GUARD_RMZ3_LINK_H
#define GUARD_RMZ3_LINK_H

#include "gba/gba.h"
#include "types.h"

#define LINKCMD_NONE 0xEFFF

#define LINK_SLAVE 0
#define LINK_MASTER 8

#define MAX_LINK_PLAYERS 4
#define CMD_LENGTH 8
#define QUEUE_CAPACITY 30

enum {
  LINK_STATE_START0,
  LINK_STATE_START1,
  LINK_STATE_HANDSHAKE,
  LINK_STATE_INIT_TIMER,
  LINK_STATE_CONN_ESTABLISHED,
};

enum {
  QUEUE_FULL_NONE,
  QUEUE_FULL_SEND,
  QUEUE_FULL_RECV,
};

enum {
  LAG_NONE,
  LAG_MASTER,
  LAG_SLAVE,
};

struct SendQueue {
  u16 data[CMD_LENGTH][QUEUE_CAPACITY];
  u8 pos;
  u8 count;
};

struct RecvQueue {
  u16 data[MAX_LINK_PLAYERS][CMD_LENGTH][QUEUE_CAPACITY];
  u8 pos;
  u8 count;
};

struct Link {
  u8 isMaster;  // 0: slave, 8: master
  u8 state;
  u8 localId;  // local multi-player ID
  u8 playerCount;
  u16 tempRecvBuffer[4];

  bool8 receivedNothing;
  u8 serialIntrCounter;
  bool8 ALIGNED(4) unk_10;
  u8 link_field_F;
  bool8 hardwareError;
  bool8 badChecksum;
  u8 queueFull;
  u8 lag;
  u16 checksum;
  u16 unk_18[MAX_LINK_PLAYERS];
  u16 unk_20[MAX_LINK_PLAYERS];
  u8 sendCmdIndex;
  u8 recvCmdIndex;
  u8 unk_2a[MAX_LINK_PLAYERS];
  struct SendQueue ALIGNED(4) sendQueue;
  struct RecvQueue ALIGNED(4) recvQueue;
};  // 2456 bytes? (080024cc のメモリコピーから推測)

extern u16 gLinkSavedIme;
extern u8 sNumVBlanksWithoutSerialIntr;
extern bool8 sSendBufferEmpty;
extern u8 sChecksumAvailable;
extern u16 sSendNonzeroCheck;
extern u16 sRecvNonzeroCheck;
extern u8 gLastSendQueueCount;
extern u8 gLastRecvQueueCount;
extern u8 u8_ARRAY_020014fc[4];
extern u8 u8_02001500;
extern struct Link gLink;

#endif  // GUARD_RMZ3_LINK_H
