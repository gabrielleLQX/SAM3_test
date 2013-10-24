#ifndef RADIO_H
#define RADIO_H
//#include "AT91SAM3SD8.h"

//Radio I/O 
typedef struct _ATRADIO
{
  boolean dig3;
  boolean dig4;
  boolean avss1;
  boolean rfp;
  boolean rfn;
  boolean avss2;
  boolean dvss1;
  boolean nrst;
  boolean dig1;
  boolean dig2;
  boolean slp_tr;
  boolean dvss2;
  boolean dvdd1;
  boolean dvdd2;
  boolean devdd2;
  boolean dvss3;
  boolean clkm;
  boolean dvss4;
  boolean s_sclk;//in
  boolean s_miso;//out
  boolean dvss5;
  boolean s_mosi;//in
  boolean s_nsel;//in
  boolean irq;
  boolean xtal2;
  boolean xtal1;
  boolean avss3;
  boolean evdd;
  boolean avdd;
  boolean avss4[3]; 
}AT86RF_io;

typedef struct _AT86RFREG{
  uint8_t tx_status;
  uint8_t trx_state;
  uint8_t trx_ctrl_0;
  uint8_t trx_ctrl_1;
  uint8_t phy_tx_pwr;
  uint8_t phy_rssi;
  uint8_t phy_ed_level;
  uint8_t phy_cc_cca;
  uint8_t cca_thres;
  uint8_t rx_ctrl;
  uint8_t sfd_value;
  uint8_t trx_ctrl_2;
  uint8_t ant_div;  
  uint8_t irq_mask;
  uint8_t irq_status;
  uint8_t vreg_ctrl;
  uint8_t batmon;
  uint8_t xosc_ctrl;
  uint8_t cc_ctrl_0;
  uint8_t cc_ctrl_1;
  uint8_t rx_syn;
  uint8_t trx_rpc;
  uint8_t xah_ctrl_1;
  uint8_t ftn_ctrl;
  uint8_t xah_ctrl_2;
  uint8_t pll_cf;
  uint8_t pll_dcu;
  uint8_t part_num;  
  uint8_t version_num;
  uint8_t main_id[2];
  uint8_t short_addr[2];
  uint8_t pan_id[2];
  uint8_t ieee_addr[8];
  uint8_t xah_ctrl_0;
  uint8_t csma_seed[2];
  uint8_t csma_be;
  uint8_t Reserved1[6];
  uint8_t tst_ctrl_digi;
  uint8_t Reserved2[4];
  uint8_t phy_tx_time;
  uint8_t tst_agc;
  uint8_t tst_sdm;
}AT86RF_reg;

u08 phr;//phy header
u08 lqi;//link quality indication
u08 ed;//energy detect
u08 psdu[128];

u08 aes[19];

uint8_t pre_seq[4];//preamble sequence
#define fcf (psdu[0]+(psdu[1]<<8))//frame control field
#define d_panid (psdu[3]+(psdu[4]<<8))//destination PAN_ID

uint16_t fcs;//frame control sequence
uint8_t csma_rctr;
uint8_t frame_rctr;
#define CMD_BITS  ((uint8_t) 0x7 << 5)


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
#define AACK_I_AM_COORD  ((uint8_t) 0x1 << 3)
#define CSMA_SEED_1      ((uint8_t) 0x7 << 0)

//static uint16_t FCF;
#define FRAME_TYPE    ((uint16_t) 0x7 << 0)
#define ACKREQ        ((uint16_t) 0x1 << 5)
#define FRAME_VERSION ((uint16_t) 0x3 << 12)
#define D_ADDR_MODE       ((uint16_t) 0x3 << 10)
#define S_ADDR_MODE       ((uint16_t) 0x3 << 14)

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

#define CMD_REGISTER_READ  0x80
#define CMD_REGISTER_WRITE 0xC0
#define CMD_FRAME_READ     0x20
#define CMD_FRAME_WRITE    0x60
#define CMD_SRAM_READ      0x00
#define CMD_SRAM_WRITE     0x40

void radioReset();
void radioInit();
void radioDestroy();
//SPI slave
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
void radioTRXSPI(AT86RF_io *radioIO);

boolean radioTRXtest(AT86RF_io *radioIO, int i);

//State Machine
void radioUpdate(u08 cmd);
boolean radioFrameFiltering();
void radioFrameReceive();
void radioWait(u08 time);
void radioRisingEdge(AT86RF_io *radioIO);
void radioACKTransmit();
void radioScanMHR();
boolean radioTransaction(AT86RF_io *radioIO);
boolean radioFrameEnd();
boolean radioSHRDetected();
boolean radioReceiveACK(AT86RF_io *radioIO);
boolean radioACKValid();
boolean radioCCA();
void radioTransmitFrame(AT86RF_io *radioIO);
boolean radioTxAret(AT86RF_io *radioIO);
void radioStateMachine(AT86RF_io *radioIO);

void radioRun(AT86RF_io *radioIO);
void radioStep(AT86RF_io *radioIO);
#endif

