#include "AT91SAM3SD8.h"
//#include "at91sam3sd8.h"
#include "global.h"
#include "radio.h"
#include <stdio.h>

AT86PS_RADIO pRADIO = ((AT86PS_RADIO) 0x41000000);
u08 PHR;
u08 LQI;
u08 ED;
u08 PSDU[128];
u08 AES[19];

void radioInit()
{
  pRADIO->radioIO = 0x80;// /RST=L
}
/*
void radioIOInit()
{
  radioIO->S_SCLK = 0;
  radioIO->S_MISO = 0;
  radioIO->S_MOSI = 0;
  radioIO->S_nSEL = 1;
}
*/
void radioReset()
{
  pRADIO->radioIO = 0x80;// /RST=L
  /*
  pRADIO->TX_STATUS = 0x00;
  pRADIO->TRX_STATE = 0x00;
  pRADIO->TRX_CTRL_0 = 0x09;
  pRADIO->TRX_CTRL_1   = 0x22;
  pRADIO->PHY_TX_PWR   = 0x00;
  pRADIO->PHY_RSSI     = 0x60;
  pRADIO->PHY_ED_LEVEL = 0xFF;
  pRADIO->PHY_CC_CCA   = 0x2B;
  pRADIO->CCA_THRES    = 0xC7;
  pRADIO->RX_CTRL      = 0x37;
  pRADIO->SFD_VALUE    = 0xA7;
  pRADIO->TRX_CTRL_2   = 0x20;
  pRADIO->ANT_DIV      = 0x00;
  pRADIO->IRQ_MASK     = 0x00;
  pRADIO->IRQ_STATUS   = 0x00;
  pRADIO->VREG_CTRL    = 0x00;
  pRADIO->BATMON       = 0x02;
  pRADIO->XOSC_CTRL    = 0xF0;
  pRADIO->CC_CTRL_0    = 0x00;
  pRADIO->CC_CTRL_1    = 0x00;
  pRADIO->RX_SYN       = 0x00;
  pRADIO->TRX_RPC      = 0xC1;
  pRADIO->XAH_CTRL_1   = 0x00;  
  pRADIO->FTN_CTRL     = 0x58;
  pRADIO->XAH_CTRL_2   = 0x00;
  pRADIO->PLL_CF       = 0x57;
  pRADIO->PLL_DCU      = 0x20;
  pRADIO->PART_NUM     = 0x0B;
  pRADIO->VERSION_NUM  = 0x01;
  pRADIO->MAIN_ID[0]   = 0x1F;
  pRADIO->MAIN_ID[1]   = 0x00;
  pRADIO->SHORT_ADDR[0]= 0xFF;
  pRADIO->SHORT_ADDR[1]= 0xFF;
  pRADIO->PAN_ID[0]    = 0xFF;
  pRADIO->PAN_ID[1]    = 0xFF;
  pRADIO->IEEE_ADDR[0] = 0x00;
  pRADIO->IEEE_ADDR[1] = 0x00;
  pRADIO->IEEE_ADDR[2] = 0x00;
  pRADIO->IEEE_ADDR[3] = 0x00;
  pRADIO->IEEE_ADDR[4] = 0x00;
  pRADIO->IEEE_ADDR[5] = 0x00;
  pRADIO->IEEE_ADDR[6] = 0x00;
  pRADIO->IEEE_ADDR[7] = 0x00;
  pRADIO->XAH_CTRL_0   = 0x38;
  pRADIO->CSMA_SEED[0] = 0xEA;
  pRADIO->CSMA_SEED[1] = 0x42;
  pRADIO->CSMA_BE      = 0x53;
  pRADIO->TST_CTRL_DIGI= 0x00;
  pRADIO->PHY_TX_TIME  = 0x00;
  pRADIO->TST_AGC      = 0x00;
  pRADIO->TST_SDM      = 0x00;
  */
}

u08 radioPhyStatus()
{  
  switch((pRADIO->TRX_CTRL_1 & 0x0C) >> 2){
  case 0:
    return 0;
  case 1:
    return pRADIO->TX_STATUS;
  case 2:
    return pRADIO->PHY_RSSI;
  case 3:
    return pRADIO->IRQ_STATUS;
  } 
}

u08 radioReadReg(u08 cmd)
{
  switch(cmd & 0x3F){
  case 0x01: // 
    return pRADIO->TX_STATUS;
  case 0x02: // 
    return pRADIO->TRX_STATE;
  case 0x03: // 
    return pRADIO->TRX_CTRL_0;
  case 0x04: //    	  
    return pRADIO->TRX_CTRL_1;
  case 0x05: // 
    return pRADIO->PHY_TX_PWR;
  case 0x06: // 
    return pRADIO->PHY_RSSI;
  case 0x07: // 
    return pRADIO->PHY_ED_LEVEL;
  case 0x08: // 
    return pRADIO->PHY_CC_CCA;
  case 0x09: // 
    return pRADIO->CCA_THRES;
  case 0x0A: // 
    return pRADIO->RX_CTRL;
  case 0x0B: // 
    return pRADIO->SFD_VALUE;
  case 0x0C: // 
    return pRADIO->TRX_CTRL_2;
  case 0x0D: // 
    return pRADIO->ANT_DIV;
  case 0x0E: // 
    return pRADIO->IRQ_MASK;
  case 0x0F: // 
    return pRADIO->IRQ_STATUS;
  case 0x10: // 
    return pRADIO->VREG_CTRL;
  case 0x11: // 
    return pRADIO->BATMON;
  case 0x12: // 
    return pRADIO->XOSC_CTRL;
  case 0x13: // 
    return pRADIO->CC_CTRL_0;
  case 0x14: // 
    return pRADIO->CC_CTRL_1;
  case 0x15: // 
    return pRADIO->RX_SYN;
  case 0x16: // 
    return pRADIO->TRX_RPC;
  case 0x17: // 
    return pRADIO->XAH_CTRL_1;
  case 0x18: // 
    return pRADIO->FTN_CTRL;
  case 0x19: // 
    return pRADIO->XAH_CTRL_2;
  case 0x1A: // 
    return pRADIO->PLL_CF;
  case 0x1B: // 
    return pRADIO->PLL_DCU;
  case 0x1C: // 
    return pRADIO->PART_NUM;
  case 0x1D: // 
    return pRADIO->VERSION_NUM;
  case 0x1E: // 
    return pRADIO->MAIN_ID[0];
  case 0x1F: // 
    return pRADIO->MAIN_ID[1];
  case 0x20: // 
    return pRADIO->SHORT_ADDR[0];
  case 0x21: // 
    return pRADIO->SHORT_ADDR[1];
  case 0x22: // 
    return pRADIO->PAN_ID[0];
  case 0x23: // 
    return pRADIO->PAN_ID[1];
  case 0x24: // 
    return pRADIO->IEEE_ADDR[0];
  case 0x25: // 
    return pRADIO->IEEE_ADDR[1];
  case 0x26: // 
    return pRADIO->IEEE_ADDR[2];
  case 0x27: // 
    return pRADIO->IEEE_ADDR[3];
  case 0x28: // 
    return pRADIO->IEEE_ADDR[4];
  case 0x29: // 
    return pRADIO->IEEE_ADDR[5];
  case 0x2A: // 
      return pRADIO->IEEE_ADDR[6];
  case 0x2B: // 
    return pRADIO->IEEE_ADDR[7];
  case 0x2C: // 
    return pRADIO->XAH_CTRL_0;
  case 0x2D: // 
    return pRADIO->CSMA_SEED[0];
  case 0x2E: // 
    return pRADIO->CSMA_SEED[1];
  case 0x2F: // 
    return pRADIO->CSMA_BE;
  case 0x36: // 
    return pRADIO->TST_CTRL_DIGI;
  case 0x3C: // 
    return pRADIO->TST_AGC;
  case 0x3D: // 
    return pRADIO->TST_SDM;
  case 0x3B: // 
    return pRADIO->PHY_TX_TIME;
  }
}

void radioWrReg(u08 cmd, u08 value)
{
  switch(cmd & 0x3F){
  case 0x01: // 
    pRADIO->TX_STATUS = value;
    break;
  case 0x02: // 
    pRADIO->TRX_STATE = value;
    break;
  case 0x03: // 
    pRADIO->TRX_CTRL_0 = value;
    break;
  case 0x04: //    	  
    pRADIO->TRX_CTRL_1 = value;
    break;
  case 0x05: // 
    pRADIO->PHY_TX_PWR = value;
    break;
  case 0x06: // 
    pRADIO->PHY_RSSI = value;
    break;
  case 0x07: // 
    pRADIO->PHY_ED_LEVEL = value;
    break;
  case 0x08: // 
    pRADIO->PHY_CC_CCA = value;
    break;
  case 0x09: // 
    pRADIO->CCA_THRES = value;
    break;
  case 0x0A: // 
    pRADIO->RX_CTRL = value;
    break;
  case 0x0B: // 
    pRADIO->SFD_VALUE = value;
    break;
  case 0x0C: // 
    pRADIO->TRX_CTRL_2 = value;
    break;
  case 0x0D: // 
    pRADIO->ANT_DIV = value;
    break;
  case 0x0E: // 
    pRADIO->IRQ_MASK = value;
    break;
  case 0x0F: // 
    pRADIO->IRQ_STATUS = value;
    break;
  case 0x10: // 
    pRADIO->VREG_CTRL = value;
    break;
  case 0x11: // 
    pRADIO->BATMON = value;
    break;
  case 0x12: // 
    pRADIO->XOSC_CTRL = value;
    break;
  case 0x13: // 
    pRADIO->CC_CTRL_0 = value;
    break;
  case 0x14: // 
    pRADIO->CC_CTRL_1 = value;
    break;
  case 0x15: // 
    pRADIO->RX_SYN = value;
    break;
  case 0x16: // 
    pRADIO->TRX_RPC = value;
    break;
  case 0x17: // 
    pRADIO->XAH_CTRL_1 = value;
    break;
  case 0x18: // 
    pRADIO->FTN_CTRL = value;
    break;
  case 0x19: // 
    pRADIO->XAH_CTRL_2 = value;
    break;
  case 0x1A: // 
    pRADIO->PLL_CF = value;
    break;
  case 0x1B: // 
    pRADIO->PLL_DCU = value;
    break;
  case 0x1C: // 
    pRADIO->PART_NUM = value;
    break;
  case 0x1D: // 
    pRADIO->VERSION_NUM = value;
    break;
  case 0x1E: // 
    pRADIO->MAIN_ID[0] = value;
    break;
  case 0x1F: // 
    pRADIO->MAIN_ID[1] = value;
    break;
  case 0x20: // 
    pRADIO->SHORT_ADDR[0] = value;
    break;
  case 0x21: // 
    pRADIO->SHORT_ADDR[1] = value;
    break;
  case 0x22: // 
    pRADIO->PAN_ID[0] = value;
      break;
    case 0x23: // 
      pRADIO->PAN_ID[1] = value;
      break;
    case 0x24: // 
      pRADIO->IEEE_ADDR[0] = value;
      break;
    case 0x25: // 
      pRADIO->IEEE_ADDR[1] = value;
      break;
    case 0x26: // 
      pRADIO->IEEE_ADDR[2] = value;
      break;
    case 0x27: // 
      pRADIO->IEEE_ADDR[3] = value;
      break;
    case 0x28: // 
      pRADIO->IEEE_ADDR[4] = value;
      break;
    case 0x29: // 
      pRADIO->IEEE_ADDR[5] = value;
      break;
    case 0x2A: // 
      pRADIO->IEEE_ADDR[6] = value;
      break;
    case 0x2B: // 
      pRADIO->IEEE_ADDR[7] = value;
      break;
    case 0x2C: // 
      pRADIO->XAH_CTRL_0 = value;
      break;
    case 0x2D: // 
      pRADIO->CSMA_SEED[0] = value;
      break;
    case 0x2E: // 
      pRADIO->CSMA_SEED[1] = value;
      break;
    case 0x2F: // 
      pRADIO->CSMA_BE = value;
      break;
    case 0x36: // 
      pRADIO->TST_CTRL_DIGI = value;
      break;
    case 0x3C: // 
      pRADIO->TST_AGC = value;
      break;
    case 0x3D: // 
      pRADIO->TST_SDM = value;
      break;
    case 0x3B: // 
      pRADIO->PHY_TX_TIME = value;
      break;        
    }
}

u08 radioReadPHR()
{
  PHR = 11;
  return PHR;
}

uint16_t radioReadFCF(){
  return FCF;
}

u08 radioReadPSDU(u08 k)
{
  if(k < 2){
    *(PSDU + k) = radioReadFCF() >> (k*8);
    if(k==1)
      printf("\rFCF = %x",radioReadFCF());
  }
  return *(PSDU + k);
}

u08 radioReadLQI()
{
  LQI = 255;
  return LQI;
}

u08 radioReadED()
{
  return ED;
}

u08 radioReadRxS()
{
  return ((pRADIO->TRX_STATE & TRAC_STATUS) >> 1) | (pRADIO->PHY_RSSI & 0x80);
}

void radioWrPHR(u08 phr){
  PHR = phr;
  if(phr == 5)
    printf("\rMPDU Acknownledgement !\r\n");
  else if(phr > 8)
    printf("\rMPDU !\r\n");
}

void radioWrPSDU(u08 psdu, u08 k){
  *(PSDU+k) = psdu;
  printf("\rWrite : PSDU[%d] = %x\r\n", k, *(PSDU + k));
}

u08 radioReadSRAM(u08 addr){
  if(addr<0x80){
    //printf("Read : SRAM_PSDU[%x] = %x\r\n",addr, *(PSDU+addr));
    return *(PSDU + addr);
  }
  else if(addr>0x81 && addr <0x95){
    //printf("Read : SRAM_AES[%x] = %x\r\n",addr, *(AES + addr - 128));
    return *(AES + addr -128);
  }
  else{
    printf("\rNot valid read_sram! \r\n");
    return 0;
  }
  //printf("Read : SRAM[%x] = %x\r\n",addr, *(pRADIO + addr));
  //return *(pRADIO + addr);radioReadPSDU(addr)
}

void radioWrSRAM(u08 addr, u08 data){
  if(addr<0x80){
    *(PSDU + addr) = data;
    printf("Write : SRAM_PSDU[%x] = %x\r\n",addr, *(PSDU + addr));
  }
  else if(addr>0x81 && addr <0x95){
    *(AES + addr - 128) = data;
    printf("Write : SRAM_AES[%x] = %x\r\n",addr, *(AES + addr - 128));
  }
  else{
    printf("\rNot valid write_sram! \r\n");
  }
}
