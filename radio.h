/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef RADIO_H
#define RADIO_H
//#include "AT91SAM3SD8.h"

//Radio I/O 
typedef struct _ATRADIO
{
  boolean DIG3;
  boolean DIG4;
  boolean AVSS1;
  boolean RFP;
  boolean RFN;
  boolean AVSS2;
  boolean DVSS1;
  boolean nRST;
  boolean DIG1;
  boolean DIG2;
  boolean SLP_TR;
  boolean DVSS2;
  boolean DVDD1;
  boolean DVDD2;
  boolean DEVDD2;
  boolean DVSS3;
  boolean CLKM;
  boolean DVSS4;
  boolean S_SCLK;//in
  boolean S_MISO;//out
  boolean DVSS5;
  boolean S_MOSI;//in
  boolean S_nSEL;//in
  boolean IRQ;
  boolean XTAL2;
  boolean XTAL1;
  boolean AVSS3;
  boolean EVDD;
  boolean AVDD;
  boolean AVSS4[3]; 
}*AT86RF_io;

#define TRX_STATUS                   ((uint8_t) 0x1f <<  0)
#define TRX_CMD                      ((uint8_t) 0x1f <<  0)

//0x01 TRX_STATUS->CCA_DONE
#define CCA_DONE   ((uint8_t) 0x1 << 7)
#define CCA_STATUS ((uint8_t) 0x1 << 6)

//0x01 TRX_STATUS->TRX_STATUS
//0x02 TRX_STATE->TRX_CMD
#define P_ON                         ((uint8_t) 0x0 <<  0)
#define BUSY_RX                      ((uint8_t) 0x01 <<  0)
#define TX_START                     ((uint8_t) 0x02 <<  0)
#define BUSY_TX                      ((uint8_t) 0x02 <<  0)
#define FORCE_TRX_OFF                ((uint8_t) 0x03 <<  0)
#define FORCE_PLL_ON                 ((uint8_t) 0x04 <<  0)
#define RX_ON                        ((uint8_t) 0x06 <<  0)
#define TRX_OFF                      ((uint8_t) 0x08 <<  0)
#define PLL_ON                       ((uint8_t) 0x09 <<  0)
#define SLEEP                        ((uint8_t) 0x0f <<  0)
#define PREP_DEEP_SLEEP              ((uint8_t) 0x10 <<  0)
#define BUSY_RX_AACK                 ((uint8_t) 0x11 <<  0)
#define BUSY_TX_ARET                 ((uint8_t) 0x12 <<  0)
#define RX_AACK_ON                   ((uint8_t) 0x16 <<  0)
#define TX_ARET_ON                   ((uint8_t) 0x19 <<  0)
#define STATE_TRANSITION_IN_PROGRESS ((uint8_t) 0x1f <<  0)

//0x02 TRX_STATE->TRAC_STATUS
#define TRAC_STATUS                  ((uint8_t) 0x7 <<  5)
#define SUCCESS                      ((uint8_t) 0x0 <<  5)
#define SUCCESS_DATA_PENDING         ((uint8_t) 0x1 <<  5)
#define SUCCESS_WAIT_FOR_ACK         ((uint8_t) 0x2 <<  5)
#define CHANNEL_ACCESS_FAILURE       ((uint8_t) 0x3 <<  5)
#define NO_ACK                       ((uint8_t) 0x5 <<  5)
#define INVALID                      ((uint8_t) 0x7 <<  5)

//0xPHY_RSSI
#define RX_CRC_VALID   ((uint8_t) 0x1 << 7)
//0x08 PHY_CC_CCA
#define CCA_REQUEST    ((uint8_t) 0x1 << 7)
#define CCA_MODE       ((uint8_t) 0x3 << 5)
#define CHANNEL        ((uint8_t) 0x1f << 5)

//0x0e IRQ_MASK
//0x0f IRQ_STATUS
#define BAT_LOW     ((uint8_t) 0x1 << 7)
#define TRX_UR      ((uint8_t) 0x1 << 6)
#define AMI         ((uint8_t) 0x1 << 5)
#define CCA_ED_DONE ((uint8_t) 0x1 << 4)
#define TRX_END     ((uint8_t) 0x1 << 3)
#define RX_START    ((uint8_t) 0x1 << 2)
#define PLL_UNLOCK  ((uint8_t) 0x1 << 1)
#define PLL_LOCK    ((uint8_t) 0x1 << 0)

//0x17 XAH_CTRL_1
#define AACK_PROM_MODE   ((uint8_t) 0x1 << 1)
#define AACK_ACK_TIME    ((uint8_t) 0x1 << 2)
#define AACK_UPLD_RES_FT ((uint8_t) 0x1 << 4)

//0x2C XAH_CTRL_0
#define MAX_FRAME_RETRIES ((uint8_t) 0xf << 4)
#define MAX_CSMA_RETRIES  ((uint8_t) 0x7 << 1)
#define SLOTTED_OPERATION ((uint8_t) 0x1 << 0)

//0x2E CSMA_SEED_1
#define AACK_SET_PD      ((uint8_t) 0x1 << 5)
#define AACK_DIS_ACK     ((uint8_t) 0x1 << 4)
#define CSMA_SEED_1      ((uint8_t) 0x7 << 0)

//static uint16_t FCF;
#define FrameType    ((uint16_t) 0x7 << 0)
#define ACKReq       ((uint16_t) 0x1 << 5)
#define FrameVersion ((uint16_t) 0x3 << 12)

static uint16_t FCF;
#define FRAMETYPE_BEACON       ((uint8_t) 0x0 << 0)
#define FRAMETYPE_DATA         ((uint8_t) 0x1 << 0)
#define FRAMETYPE_ACK          ((uint8_t) 0x2 << 0)
#define FRAMETYPE_MAC          ((uint8_t) 0x3 << 0)
#define SEC_EN                 ((uint8_t) 0x1 << 3)
#define FRAME_PENDING          ((uint8_t) 0x1 << 4)
#define ACK_REQ                ((uint8_t) 0x1 << 5)
#define PANID_COMP             ((uint8_t) 0x1 << 6)
#define DES_ADDR_MODE          ((uint8_t) 0x3 << 10)
#define SRC_ADDR_MODE          ((uint8_t) 0x3 << 14)



static uint8_t csma_rctr;
static uint8_t frame_rctr;

void radioInit();
//void radioIOInit();
void radioReset();
u08 radioPhyStatus();
u08 radioReadReg(u08 cmd);
void radioWrReg(u08 cmd, u08 value);
u08 radioReadPHR();
u08 radioReadPSDU(u08 k);
u08 radioReadLQI();
u08 radioReadED();
u08 radioReadRxS();
void radioWrPHR(u08 phr);
void radioWrPSDU(u08 psdu, u08 k);
u08 radioReadSRAM(u08 addr);
void radioWrSRAM(u08 addr, u08 data);
/*
void radioUpdate(u08 cmd);
boolean radioTransferBeacon();
boolean radioFrameFiltering();
void radioFrameReceive();
void radioWait(u08 time);
void radioRisingEdge();
void radioACKTransmit();
boolean radioTransaction();
boolean radioFrameEnd();
boolean radioSHRDetected();
boolean radioReceiveACK();
boolean radioACKValid();
boolean radioCCA(u08 *csma_rctr);
boolean radioTxAret();
void radioStateMachine();
*/
#endif

