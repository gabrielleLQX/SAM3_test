#include "AT91SAM3SD8.h"
//#include "at91sam3sd8.h"
#include "global.h"
#include "radio.h"
#include <stdio.h>

static volatile AT86RF_reg *radio_reg;

static uint8_t phr = 0;//phy header

static uint8_t psdu[128];

static uint8_t aes[19];

static uint16_t fcs = 0;//frame control sequence
static uint8_t csma_rctr = 0;
static uint8_t frame_rctr = 0;

static uint8_t seq_transmit = 0;

static uint8_t lqi = 255;//link quality indication
static uint8_t ed = 0;//energy detect
static uint8_t pre_seq[4];//preamble sequence


void radioReset()
{
  radio_reg->tx_status = 0x00;
  radio_reg->trx_state = 0x00;
  radio_reg->trx_ctrl_0 = 0x09;
  radio_reg->trx_ctrl_1   = 0x22;
  radio_reg->phy_tx_pwr   = 0x00;
  radio_reg->phy_rssi     = 0x60;
  radio_reg->phy_ed_level = 0xff;
  radio_reg->phy_cc_cca   = 0x2b;
  radio_reg->cca_thres    = 0xc7;
  radio_reg->rx_ctrl      = 0x37;
  radio_reg->sfd_value    = 0xa7;
  radio_reg->trx_ctrl_2   = 0x20;
  radio_reg->ant_div      = 0x00;
  radio_reg->irq_mask     = 0x00;
  radio_reg->irq_status   = 0x00;
  radio_reg->vreg_ctrl    = 0x00;
  radio_reg->batmon       = 0x02;
  radio_reg->xosc_ctrl    = 0xf0;
  radio_reg->cc_ctrl_0    = 0x00;
  radio_reg->cc_ctrl_1    = 0x00;
  radio_reg->rx_syn       = 0x00;
  radio_reg->trx_rpc      = 0xc1;
  radio_reg->xah_ctrl_1   = 0x00;  
  radio_reg->ftn_ctrl     = 0x58;
  radio_reg->xah_ctrl_2   = 0x00;
  radio_reg->pll_cf       = 0x57;
  radio_reg->pll_dcu      = 0x20;
  radio_reg->part_num     = 0x0b;
  radio_reg->version_num  = 0x01;
  radio_reg->main_id[0]   = 0x1f;
  radio_reg->main_id[1]   = 0x00;
  radio_reg->short_addr[0]= 0xff;
  radio_reg->short_addr[1]= 0xff;
  radio_reg->pan_id[0]    = 0xff;
  radio_reg->pan_id[1]    = 0xff;
  radio_reg->ieee_addr[0] = 0x00;
  radio_reg->ieee_addr[1] = 0x00;
  radio_reg->ieee_addr[2] = 0x00;
  radio_reg->ieee_addr[3] = 0x00;
  radio_reg->ieee_addr[4] = 0x00;
  radio_reg->ieee_addr[5] = 0x00;
  radio_reg->ieee_addr[6] = 0x00;
  radio_reg->ieee_addr[7] = 0x00;
  radio_reg->xah_ctrl_0   = 0x38;
  radio_reg->csma_seed[0] = 0xea;
  radio_reg->csma_seed[1] = 0x42;
  radio_reg->csma_be      = 0x53;
  radio_reg->tst_ctrl_digi= 0x00;
  radio_reg->phy_tx_time  = 0x00;
  radio_reg->tst_agc      = 0x00;
  radio_reg->tst_sdm      = 0x00;
}

void radioClearPSDU(uint8_t phr_indice)
{
  int i;
  i = phr_indice;
  while(i<128)
    psdu[i++] = 0;
}

void radioClearGV()
{
  phr = 0;//phy header
  lqi = 255;//link quality indication
  ed = 0;//energy detect

  int i;
  i = 0;
  while(i<19)
    aes[i++] = 0;

  i = 0;
  while(i<4)
    pre_seq[i++] = 0;//preamble sequence

  seq_transmit = 0;

  fcs = 0;//frame control sequence
  csma_rctr = 0;
  frame_rctr = 0;  
}

void radioInit()
{
  radio_reg = malloc(sizeof(AT86RF_reg));
  radioReset();
  radioClearPSDU(0);
  radioClearGV();
}

void radioDestroy()
{
  free((void *)radio_reg);
}

u08 radioReadReg(u08 cmd)
{
  switch(cmd & 0x3f){
  case 0x01: // 
    return radio_reg->tx_status;
  case 0x02: // 
    return radio_reg->trx_state;
  case 0x03: // 
    return radio_reg->trx_ctrl_0;
  case 0x04: //    	  
    return radio_reg->trx_ctrl_1;
  case 0x05: // 
    return radio_reg->phy_tx_pwr;
  case 0x06: // 
    return radio_reg->phy_rssi;
  case 0x07: // 
    return radio_reg->phy_ed_level;
  case 0x08: // 
    return radio_reg->phy_cc_cca;
  case 0x09: // 
    return radio_reg->cca_thres;
  case 0x0a: // 
    return radio_reg->rx_ctrl;
  case 0x0b: // 
    return radio_reg->sfd_value;
  case 0x0c: // 
    return radio_reg->trx_ctrl_2;
  case 0x0d: // 
    return radio_reg->ant_div;
  case 0x0e: // 
    return radio_reg->irq_mask;
  case 0x0f: // 
    return radio_reg->irq_status;
  case 0x10: // 
    return radio_reg->vreg_ctrl;
  case 0x11: // 
    return radio_reg->batmon;
  case 0x12: // 
    return radio_reg->xosc_ctrl;
  case 0x13: // 
    return radio_reg->cc_ctrl_0;
  case 0x14: // 
    return radio_reg->cc_ctrl_1;
  case 0x15: // 
    return radio_reg->rx_syn;
  case 0x16: // 
    return radio_reg->trx_rpc;
  case 0x17: // 
    return radio_reg->xah_ctrl_1;
  case 0x18: // 
    return radio_reg->ftn_ctrl;
  case 0x19: // 
    return radio_reg->xah_ctrl_2;
  case 0x1a: // 
    return radio_reg->pll_cf;
  case 0x1b: // 
    return radio_reg->pll_dcu;
  case 0x1c: // 
    return radio_reg->part_num;
  case 0x1d: // 
    return radio_reg->version_num;
  case 0x1e: // 
    return radio_reg->main_id[0];
  case 0x1f: // 
    return radio_reg->main_id[1];
  case 0x20: // 
    return radio_reg->short_addr[0];
  case 0x21: // 
    return radio_reg->short_addr[1];
  case 0x22: // 
    return radio_reg->pan_id[0];
  case 0x23: // 
    return radio_reg->pan_id[1];
  case 0x24: // 
    return radio_reg->ieee_addr[0];
  case 0x25: // 
    return radio_reg->ieee_addr[1];
  case 0x26: // 
    return radio_reg->ieee_addr[2];
  case 0x27: // 
    return radio_reg->ieee_addr[3];
  case 0x28: // 
    return radio_reg->ieee_addr[4];
  case 0x29: // 
    return radio_reg->ieee_addr[5];
  case 0x2a: // 
      return radio_reg->ieee_addr[6];
  case 0x2b: // 
    return radio_reg->ieee_addr[7];
  case 0x2c: // 
    return radio_reg->xah_ctrl_0;
  case 0x2d: // 
    return radio_reg->csma_seed[0];
  case 0x2e: // 
    return radio_reg->csma_seed[1];
  case 0x2f: // 
    return radio_reg->csma_be;
  case 0x36: // 
    return radio_reg->tst_ctrl_digi;
  case 0x3c: // 
    return radio_reg->tst_agc;
  case 0x3d: // 
    return radio_reg->tst_sdm;
  case 0x3b: // 
    return radio_reg->phy_tx_time;
  }
}

void radioWrReg(u08 cmd, u08 value)
{
  switch(cmd & 0x3f){
  case 0x01: // 
    radio_reg->tx_status = value;
    break;
  case 0x02: // 
    radio_reg->trx_state = value;
    break;
  case 0x03: // 
    radio_reg->trx_ctrl_0 = value;
    break;
  case 0x04: //    	  
    radio_reg->trx_ctrl_1 = value;
    break;
  case 0x05: // 
    radio_reg->phy_tx_pwr = value;
    break;
  case 0x06: // 
    radio_reg->phy_rssi = value;
    break;
  case 0x07: // 
    radio_reg->phy_ed_level = value;
    break;
  case 0x08: // 
    radio_reg->phy_cc_cca = value;
    break;
  case 0x09: // 
    radio_reg->cca_thres = value;
    break;
  case 0x0a: // 
    radio_reg->rx_ctrl = value;
    break;
  case 0x0b: // 
    radio_reg->sfd_value = value;
    break;
  case 0x0c: // 
    radio_reg->trx_ctrl_2 = value;
    break;
  case 0x0d: // 
    radio_reg->ant_div = value;
    break;
  case 0x0e: // 
    radio_reg->irq_mask = value;
    break;
  case 0x0f: // 
    radio_reg->irq_status = value;
    break;
  case 0x10: // 
    radio_reg->vreg_ctrl = value;
    break;
  case 0x11: // 
    radio_reg->batmon = value;
    break;
  case 0x12: // 
    radio_reg->xosc_ctrl = value;
    break;
  case 0x13: // 
    radio_reg->cc_ctrl_0 = value;
    break;
  case 0x14: // 
    radio_reg->cc_ctrl_1 = value;
    break;
  case 0x15: // 
    radio_reg->rx_syn = value;
    break;
  case 0x16: // 
    radio_reg->trx_rpc = value;
    break;
  case 0x17: // 
    radio_reg->xah_ctrl_1 = value;
    break;
  case 0x18: // 
    radio_reg->ftn_ctrl = value;
    break;
  case 0x19: // 
    radio_reg->xah_ctrl_2 = value;
    break;
  case 0x1a: // 
    radio_reg->pll_cf = value;
    break;
  case 0x1b: // 
    radio_reg->pll_dcu = value;
    break;
  case 0x1c: // 
    radio_reg->part_num = value;
    break;
  case 0x1d: // 
    radio_reg->version_num = value;
    break;
  case 0x1e: // 
    radio_reg->main_id[0] = value;
    break;
  case 0x1f: // 
    radio_reg->main_id[1] = value;
    break;
  case 0x20: // 
    radio_reg->short_addr[0] = value;
    break;
  case 0x21: // 
    radio_reg->short_addr[1] = value;
    break;
  case 0x22: // 
    radio_reg->pan_id[0] = value;
    break;
  case 0x23: // 
    radio_reg->pan_id[1] = value;
    break;
  case 0x24: // 
    radio_reg->ieee_addr[0] = value;
    break;
  case 0x25: // 
    radio_reg->ieee_addr[1] = value;
    break;
  case 0x26: // 
    radio_reg->ieee_addr[2] = value;
    break;
  case 0x27: // 
    radio_reg->ieee_addr[3] = value;
    break;
  case 0x28: // 
    radio_reg->ieee_addr[4] = value;
    break;
  case 0x29: // 
    radio_reg->ieee_addr[5] = value;
    break;
  case 0x2a: // 
    radio_reg->ieee_addr[6] = value;
    break;
  case 0x2b: // 
    radio_reg->ieee_addr[7] = value;
    break;
  case 0x2c: // 
    radio_reg->xah_ctrl_0 = value;
    break;
  case 0x2d: // 
    radio_reg->csma_seed[0] = value;
    break;
  case 0x2e: // 
    radio_reg->csma_seed[1] = value;
    break;
  case 0x2f: // 
    radio_reg->csma_be = value;
    break;
  case 0x36: // 
    radio_reg->tst_ctrl_digi = value;
    break;
  case 0x3c: // 
    radio_reg->tst_agc = value;
    break;
  case 0x3d: // 
    radio_reg->tst_sdm = value;
    break;
  case 0x3b: // 
    radio_reg->phy_tx_time = value;
    break;        
  }
}

u08 radioReadPHR()
{
  //phr = 11;
  return phr;
}

uint16_t radioReadFCF(){
  return fcf;
}

u08 radioReadPSDU(u08 k)
{
  if(k < 2){
    *(psdu + k) = radioReadFCF() >> (k*8);
    if(k==1)
      printf("\rFCF = %x",radioReadFCF());
  }
  return *(psdu + k);
}

u08 radioPhyStatus()
{  
  switch((radio_reg->trx_ctrl_1 & 0x0c) >> 2){
  case 0:
    return 0;
  case 1:
    return radio_reg->tx_status;
  case 2:
    return radio_reg->phy_rssi;
  case 3:
    return radio_reg->irq_status;
  } 
}

u08 radioReadLQI()
{
  lqi = 255;
  return lqi;
}

u08 radioReadED()
{
  return radio_reg->phy_ed_level;
}

u08 radioReadRxS()
{
  return ((radio_reg->trx_state & TRAC_STATUS) >> 1) | (radio_reg->phy_rssi & 0x80);
}

void radioWrPHR(u08 phr_value){
  phr = phr_value;
  if(phr == 5)
    printf("\rMPDU Acknownledgement !\r\n");
  else if(phr > 8)
    printf("\rMPDU !\r\n");
}

void radioWrPSDU(u08 psdu_value, u08 k){
  *(psdu+k) = psdu_value;
  printf("\rWrite : PSDU[%d] = %x\r\n", k, *(psdu + k));
}

u08 radioReadSRAM(u08 addr){
  if(addr<0x80){
    //printf("Read : SRAM_PSDU[%x] = %x\r\n",addr, *(PSDU+addr));
    return *(psdu + addr);
  }
  else if(addr>0x81 && addr <0x95){
    //printf("Read : SRAM_AES[%x] = %x\r\n",addr, *(AES + addr - 128));
    return *(aes + addr -128);
  }
  else{
    printf("\rNot valid read_sram! \r\n");
    return 0;
  }
  //printf("Read : SRAM[%x] = %x\r\n",addr, *(radio_reg + addr));
  //return *(radio_reg + addr);radioReadPSDU(addr)
}

void radioWrSRAM(u08 addr, u08 data){
  if(addr<0x80){
    *(psdu + addr) = data;
    printf("Write : SRAM_PSDU[%x] = %x\r\n",addr, *(psdu + addr));
  }
  else if(addr>0x81 && addr <0x95){
    *(aes + addr - 128) = data;
    printf("Write : SRAM_AES[%x] = %x\r\n",addr, *(aes + addr - 128));
  }
  else{
    printf("\rSRAM[%x] is not PSDU nor AES ! \r\n", addr);
  }
}

void radioTRXSPI(AT86RF_io *radioIO){
  int i;
  /************************************************************
   *cmd
   ************************************************************/
  //8bits/unit of transmission 
  i = 7;
  uint8_t cmd;
  while(i>=0){
    //receive the command from SPI master
    if(radioIO->s_sclk==1){
      cmd |= (radioIO->s_mosi << i);
      //transmit phy status to master
      radioIO->s_miso = (((radioPhyStatus() >> i) & 1) == 1);
      //wait until sclk=0
      while(radioIO->s_sclk==1);
    }
    i--;
  }

  /************************************************************
   *register, PHR or ADDR
   ************************************************************/
  int k;//number of data for transmission 
  k = 0;
  i = 7;
  uint8_t data, addr;
  while(i>=0){
    //transmit value of the register in [address]
    if(radioIO->s_sclk==1){
      if((cmd & 0xC0) == CMD_REGISTER_READ){//register read	
	radioIO->s_miso = (((radioReadReg(cmd) >> i) & 1) == 1); 
      }
      else if((cmd & 0xC0) == CMD_REGISTER_WRITE){//register write
	data |= ((radioIO->s_mosi) << i);
	if(i==0){
	  radioWrReg(cmd,data);
	  printf("\rcmd = %x, data = %x\r\n",cmd,data);
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_READ){//Frame read
	//phr = radioReadPHR();
	radioIO->s_miso = (((radioReadPHR() >> i) & 1) == 1);
	if(i==0){//PHR received
	  //printf("\rRead : PHR = %x\r\n",radioReadPHR());
	  k = radioReadPHR() + 3;//num_PSDU + LQI + ED + RX_STATUS
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_WRITE){//Frame write
	phr |= (radioIO->s_mosi << i);
	if(i==0){//PHR received
	  //printf("\r___write : PHR_write = %d\r\n",phr_write);
	  //printf("\r___write : PHR_buff = %d\r\n",phr_buff);
	  radioWrPHR(phr);
	  k = phr;//num_PSDU
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_READ){//SRAM read
	addr |= (radioIO->s_mosi << i);
	if(i==0){//ADDR received
	  printf("\rRead : ADDR = %x\r\n",addr);
	  k = 1;
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_WRITE){//SRAM write
	addr |= ((radioIO->s_mosi) << i);
	if(i==0){//ADDR received
	  printf("\r___write : addr = %x\r\n",addr);
	  k = 1;//
	}
      }
      else{
	printf("\rinvalid command ! \r\n");
	break;
      }
      //wait until sclk=0
      while(radioIO->s_sclk==1);
    }
    i--;
  }
  
  /************************************************************
   *SRAM_DATA or PSDU
   ************************************************************/
  //transmission of PSDU
  i = 7;
  uint8_t psdu_data;
  uint8_t rx_status;
  uint8_t sram_data;
  while(i>=0){
    if((cmd & 0xE0) == CMD_FRAME_READ){//Frame Read
      if(k>3){//PSDU
	radioIO->s_miso = ((radioReadPSDU(k - 3 - 1) >> i) == 1);
	//collect psdu just for printf
	psdu_data |= (radioIO->s_miso << i);
	if(i==0){
	  printf("\rRead : PSDU[%d] = %x\r\n", k - 3 -1, psdu_data);
	  psdu_data = 0;
	  k--;
	  i = 8;
	}
      }
      else if(k==3){//LQI
	radioIO->s_miso = (((radioReadLQI() >> i) & 1) == 1);
	//collect lqi just for printf
	lqi |= (radioIO->s_miso << i);
	if(i==0){
	  printf("\rRead : LQI = %x\r\n",lqi);
	  k--;
	  i = 8;
	}
      }
      else if(k==2){//ED
	radioIO->s_miso = (((radioReadED() >> i) & 1) == 1);
	//collect ed just for printf
	ed |= (radioIO->s_miso << i);
	if(i==0){
	  printf("\rRead : ED = %x\r\n",ed);
	  k--;
	  i = 8;
	}
      }
      else if(k==1){//RX_STATUS
	radioIO->s_miso = (((radioReadRxS() >> i) & 1) == 1);
	//collect rx_status just for printf
	rx_status |= (radioIO->s_miso << i);	    
	if(i==0){	      
	  printf("\rRead : RX_STATUS = %x\r\n",rx_status);
	  k = -1;
	}
      }
    }
    else if((cmd & 0xE0) == CMD_FRAME_WRITE){//Frame write
      if(k>0){//PSDU
	psdu_data |= ((radioIO->s_mosi) << i);
	if(i==0){//psdu received
	  printf("\r___write : No.%d",phr - k);
	  printf(" = %d\r\n", psdu_data);
	  radioWrPSDU(psdu_data, phr - k);
	  printf("\rWrite : PSDU_buff[%d] = %x\r\n", phr - k, psdu_data);
	  k--;
	  if(k==0){
	    k = -1;
	    i = 0;
	  }
	  else{
	    i = 8;
	    psdu_data = 0;
	  }
	}
      }
    }
    else if((cmd & 0xE0) == CMD_SRAM_READ){//SRAM read
      if(k>0){//
	if(radioIO->s_nsel==0){
	  if((((addr+k-1)>0x7F) && ((addr+k-1)<0x82))||((addr+k-1)>0x94)){
	    printf("\rNot PSDU nor AES ! \r\n");
	    k++;
	  }
	  else if((addr+k-1)>0x94){
	    printf("out of SRAM\r\n");
	    i = 0;
	  }
	  else{
	    radioIO->s_miso = ((radioReadSRAM(addr + k - 1) >> i) & 1 == 1);
	    //collect sram_data just for printf
	    sram_data |= (radioIO->s_miso << i);
	    if(i==0){
	      printf("\rRead : SRAM[%x] = %x\r\n", addr + k - 1, sram_data);
	      k++;
	      i = 8;
	    }
	  }
	}
	else{
	  addr = 0;
	  sram_data = 0;
	  i = 0;
	}
      }
    }
    else if((cmd & 0xE0) == CMD_SRAM_WRITE){//SRAM write
      if(k>0){//
	if(radioIO->s_nsel==0){
	  sram_data |= ((radioIO->s_mosi) << i);
	  if(i==0){//psdu received
	    //printf("\r___write : sram_write = %x\r\n",sram_write);
	    //printf("\r___Write : SRAM[%x] = %x\r\n", addr_buff + k - 1, sram_data);
	    radioWrSRAM(addr + k - 1, sram_data);//addr data
	    k++;
	    i = 8;
	    sram_data = 0;
	    if((addr + k - 1) > 0x94){
	      printf("out of SRAM\r\n");
	      i = 0;
	    }
	  }
	}
	else{
	  addr = 0;
	  sram_data = 0;
	  i = 0;
	}
      }
    }
    while(radioIO->s_sclk==1);
    i--;
  }
  //End of the transmission
  
}

boolean radioTRXtest(AT86RF_io *radioIO, int i){
  static int k;
  static int j;
  /************************************************************
   *cmd
   ************************************************************/
  //8bits/unit of transmission 
  static uint8_t cmd;
  static uint8_t data, addr;
  static uint8_t psdu_data;
  static uint8_t rx_status;
  static uint8_t sram_data;

  if(i>=8){
    //receive the command from SPI master
    if(radioIO->s_sclk==1){
      cmd |= (radioIO->s_mosi << (i-8));
      //transmit phy status to master
      radioIO->s_miso = (((radioPhyStatus() >> (i-8)) & 1) == 1);
      if(i==8)
	  printf("\rcmd = %x\r\n",cmd);	
      i--;
    }
  }

  /************************************************************
   *register, PHR or ADDR
   ************************************************************/
  else if(i>=0){
    //transmit value of the register in [address]
    if(radioIO->s_sclk==1){
      if((cmd & 0xC0) == CMD_REGISTER_READ){//register read	
	radioIO->s_miso = (((radioReadReg(cmd & 0x3F) >> i) & 1) == 1); 
	if(i==0){
	  k = 0;
	  printf("\rreg[0x%x] = %x\r\n",cmd & 0x3F,radioReadReg(cmd & 0x3F));
	  cmd = 0;
	  data = 0;
	  j = 0;
	  addr = 0;
	  sram_data = 0;
	  psdu_data = 0;
	  rx_status = 0;
	  return 0;
	}
      }
      else if((cmd & 0xC0) == CMD_REGISTER_WRITE){//register write
	data |= ((radioIO->s_mosi) << i);
	if(i==0){
	  k = 0;
	  radioWrReg(cmd,data);
	  printf("\rcmd = %x, data = %x\r\n",cmd,data);	
	  data = 0;
	  cmd = 0;
	  j = 0;
	  addr = 0;
	  sram_data = 0;
	  psdu_data = 0;
	  rx_status = 0;
	  return 0;
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_READ){//Frame read
	//phr = radioReadPHR();
	radioIO->s_miso = (((radioReadPHR() >> i) & 1) == 1);
	if(i==0){//PHR received
	  //printf("\rRead : PHR = %x\r\n",radioReadPHR());
	  k = radioReadPHR() + 3;//num_PSDU + LQI + ED + RX_STATUS
	  j = 7;
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_WRITE){//Frame write
	phr |= (radioIO->s_mosi << i);
	if(i==0){//PHR received
	  //printf("\r___write : PHR_write = %d\r\n",phr_write);
	  //printf("\r___write : PHR_buff = %d\r\n",phr_buff);
	  radioWrPHR(phr);
	  k = phr;//num_PSDU
	  j = 7;
	  //phr = 0;
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_READ){//SRAM read
	addr |= (radioIO->s_mosi << i);
	if(i==0){//ADDR received
	  printf("\rRead : ADDR = %x\r\n",addr);
	  k = 1;
	  j = 7;
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_WRITE){//SRAM write
	addr |= ((radioIO->s_mosi) << i);
	if(i==0){//ADDR received
	  printf("\r___write : addr = %x\r\n",addr);
	  k = 1;//
	  j = 7;
	}
      }
      else{
	printf("\rinvalid command ! \r\n");
      }
    }
    i--;
  }
  
  /************************************************************
   *SRAM_DATA or PSDU
   ************************************************************/
  //transmission of PSDU
  else if(k>0)
    {
      if((cmd & 0xE0) == CMD_FRAME_READ){//Frame Read
	if(k>3){//PSDU
	  radioIO->s_miso = ((radioReadPSDU(k - 3 - 1) >> j) == 1);
	  //collect psdu just for printf
	  psdu_data |= (radioIO->s_miso << i);
	  if(j==0){
	    printf("\rRead : PSDU[%d] = %x\r\n", k - 3 -1, psdu_data);
	    psdu_data = 0;
	    k--;
	    j = 8;
	  }
	}
	else if(k==3){//LQI
	  radioIO->s_miso = (((radioReadLQI() >> j) & 1) == 1);
	  //collect lqi just for printf
	  lqi |= (radioIO->s_miso << j);
	  if(j==0){
	    printf("\rRead : LQI = %x\r\n",lqi);
	    k--;
	    j = 8;
	  }
	}
	else if(k==2){//ED
	  radioIO->s_miso = (((radioReadED() >> j) & 1) == 1);
	  //collect ed just for printf
	  ed |= (radioIO->s_miso << i);
	  if(j==0){
	    printf("\rRead : ED = %x\r\n",ed);
	    k--;
	    j = 8;
	  }
	}
	else if(k==1){//RX_STATUS
	  radioIO->s_miso = (((radioReadRxS() >> j) & 1) == 1);
	  //collect rx_status just for printf
	  rx_status |= (radioIO->s_miso << j);	    
	  if(j==0){
	    printf("\rRead : RX_STATUS = %x\r\n",rx_status);
	    k = 0;
	    cmd = 0;
	    j = 0;
	    addr = 0;
	    sram_data = 0;
	    data = 0;
	    psdu_data = 0;
	    rx_status = 0;
	    return 0;
	  }
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_WRITE){//Frame write
	if(k>0){//PSDU
	  psdu_data |= ((radioIO->s_mosi) << j);
	  if(j==0){//psdu received
	    printf("\r___write : No.%d",phr - k);
	    printf(" = %d\r\n", psdu_data);
	    radioWrPSDU(psdu_data, phr - k);
	    printf("\rWrite : PSDU_buff[%d] = %x\r\n", phr - k, psdu_data);
	    k--;
	    j = 8;
	    psdu_data = 0;
	    if(k==0){
	      cmd = 0;
	      k = 0;
	      j = 0;
	      addr = 0;
	      sram_data = 0;
	      data = 0;
	      psdu_data = 0;
	      rx_status = 0;
	      return 0;
	    }
	    else
	      return 1;
	  }
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_READ){//SRAM read
	if(k>0){//
	  if(radioIO->s_nsel==0){
	    if((((addr+k-1)>0x7F) && ((addr+k-1)<0x82))||((addr+k-1)>0x94)){
	      printf("\rSRAM[%x] is not PSDU nor AES ! \r\n", addr+k-1);
	      k++;
	      j = 8;
	    }
	    else if((addr+k-1)>0x94){
	      printf("out of SRAM\r\n");
	      j = 0;
	    }
	    else{
	      radioIO->s_miso = ((radioReadSRAM(addr + k - 1) >> j) & 1 == 1);
	      //collect sram_data just for printf
	      sram_data |= (radioIO->s_miso << j);
	      if(j==0){
		printf("\rRead : SRAM[%x] = %x\r\n", addr + k - 1, sram_data);
		k++;
		j = 8;
		if((addr + k - 1) > 0x94){
		  printf("out of SRAM\r\n");
		  k = 0;
		  j = 0;
		  addr = 0;
		  sram_data = 0;
		  cmd = 0;
		  data = 0;
		  psdu_data = 0;
		  rx_status = 0;
		  return 0;
		}
	      }
	    }
	  }
	  else{
	    addr = 0;
	    sram_data = 0;
	    k = 0;
	    j = 0;
	    cmd = 0;
	    data = 0;
	    psdu_data = 0;
	    rx_status = 0;
	    return 0;
	  }
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_WRITE){//SRAM write
	if(k>0){//
	  if(radioIO->s_nsel==0){
	    sram_data |= ((radioIO->s_mosi) << j);
	    if(j==0){//psdu received
	      //printf("\r___write : sram_write = %x\r\n",sram_write);
	      //printf("\r___Write : SRAM[%x] = %x\r\n", addr_buff + k - 1, sram_data);
	      radioWrSRAM(addr + k - 1, sram_data);//addr data
	      k++;
	      j = 8;
	      sram_data = 0;
	      if((addr + k - 1) > 0x94){
		printf("out of SRAM\r\n");
		k = 0;
		j = 0;
		cmd = 0;
		data = 0;
		addr = 0;
		psdu_data = 0;
		rx_status = 0;
		sram_data = 0;
		return 0;
	      }
	    }
	  }
	  else{
	    addr = 0;
	    sram_data = 0;
	    k = 0;
	    j = 0;
	    cmd = 0;
	    data = 0;
	    psdu_data = 0;
	    rx_status = 0;
	    return 0;
	  }
	}
      }
      j--;
    }
  else if(k==0){
    j = 0;
    cmd = 0;
    data = 0;
    addr = 0;
    psdu_data = 0;
    rx_status = 0;
    sram_data = 0;
    return 0;
  }
  //radioIO->s_sclk==0;
  //while(radioIO->s_sclk==1);
  return 1;
}

void radio_update(uint8_t cmd)
{
  uint8_t status = radio_reg->tx_status & TRX_STATUS;

  if(cmd == TX_START){
    if(status == TX_ARET_ON){      
      printf("\r jump to state = BUSY_TX_ARET\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_TX_ARET;
    }
    else if(status == PLL_ON){
      printf("\r jump to state = BUSY_TX\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_TX;
    }
    else if(status != TX_START)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == FORCE_TRX_OFF){
    if(status!=SLEEP){
      printf("\r jump to state = TRX_OFF\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | TRX_OFF;
    }
    else if(status != TRX_OFF)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == FORCE_PLL_ON){
    if((status!=SLEEP)&&(status!=P_ON)&&(status!=STATE_TRANSITION_IN_PROGRESS)){
      printf("\r jump to state = PLL_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | PLL_ON;
    }
    else if(status != PLL_ON)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == RX_ON){
    if((status == TRX_OFF) || (status == PLL_ON) || (status == TX_ARET_ON) || (status == RX_AACK_ON)){
      printf("\r jump to state = RX_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != RX_ON)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == TRX_OFF){
    if((status == P_ON) || (status == PREP_DEEP_SLEEP) || (status == PLL_ON) || (status == RX_ON) || (status == RX_AACK_ON) || (status == TX_ARET_ON)){
      printf("\r jump to state = TRX_OFF\n\r");      
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != TRX_OFF)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == PLL_ON){
    if((status == TRX_OFF) || (status == RX_ON) || (status == TX_ARET_ON) || (status == RX_AACK_ON)){
      printf("\r jump to state = PLL_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != PLL_ON)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == PREP_DEEP_SLEEP){
    if(status == TRX_OFF){
      printf("\r jump to state = PREP_DEEP_SLEEP\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != PREP_DEEP_SLEEP)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == RX_AACK_ON){
    if((status == RX_ON)||(status == TX_ARET_ON)||(status == TRX_OFF)||(status == PLL_ON)){
      printf("\r jump to state = RX_AACK_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != RX_AACK_ON)
      printf("Invalid state demand ! \n\r");
  }
  else if(cmd == TX_ARET_ON){
    if((status == RX_ON)||(status == RX_AACK_ON)||(status == TRX_OFF)||(status == PLL_ON)){
      printf("\r jump to state = TX_ARET_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | cmd;
    }
    else if(status != TX_ARET_ON)
      printf("Invalid state demand ! \n\r");
  }

  //  else
  //  printf("Invalid state demand ! \n\r");  
}

/************************************************************************************
 *State : BUSY_RX_AACK
 ************************************************************************************/

boolean radioFrameFiltering()
{
  printf("--------Frame Filting-------\n\r");
  //The Frame Type subfield shall not contain a reserved frame type
  if((fcf & FRAME_TYPE) > 3){
    printf("Reserved frame type !\n\r");
    return 0;
  }
  //The Frame Version subfield shall not contain a reserved value
  else if(((fcf & FRAME_VERSION) >> 12) != radio_reg->version_num){
    return 0;
  }
  //If a destination PAN identifier is included in the frame, it shall match macPANId or
  //shall be the broadcast PAN identifier (0xFFFF)
  else if((fcf & D_ADDR_MODE) > ((uint8_t) 1<<10)){

    //If a short destination address is included in the frame, it shall match either
    //macShortAddress or the broadcast address (0xFFFF). Otherwise, if an extended
    //destination address is included in the frame, it shall match aExtendedAddress

    //D_ADDR
    if((fcf & D_ADDR_MODE) == ((uint8_t) 2<<10)){
      printf("D_ADDR is a short address ! \n\r");
      //if not a broadcast address
      if((psdu[5] != 0xff)||(psdu[6] != 0xff)){
	if(psdu[5] != radio_reg->short_addr[0])
	  return 0;
	else if((psdu[6] >> 8) != radio_reg->pan_id[1])
	  return 0;
      }
    }
    else if((fcf & D_ADDR_MODE) == ((uint8_t) 3<<10)){
      printf("D_ADDR is an extended address ! \n\r");
      int i;
      i = 0;
      /*
      while(i < 8){
	if(psdu[5 + (i++)] != 0xff)
	  break;
      }
      //not broadcast address
      if(i==8)
	i = 0;
      */
      while(i < 8){
	if(psdu[5 + i] == radio_reg->ieee_addr[i])
	  i++;
	else
	  break;
      }
      if(i!=8)
	return 0;
    }

    //D_PANID : if not a broadcast address
    if((psdu[3] != 0xff)||(psdu[4] != 0xff)){
      if((psdu[3] != radio_reg->pan_id[0])||(psdu[3] != 0xff))
	return 0;
      else if((psdu[4] != radio_reg->pan_id[1])||(psdu[4] != 0xff))
	return 0;
    }
  }
  //If only source addressing fields are included in a data or MAC command frame, the
  //frame shall be accepted only if the device is the PAN coordinator and the source
  //PAN identifier matches macPANId
  else if(((fcf & FRAME_TYPE) == FRAMETYPE_DATA)||((fcf & FRAME_TYPE) == FRAMETYPE_MAC)){
    if((fcf & S_ADDR_MODE) > ((uint8_t) 1<<14)){
      if((radio_reg->csma_seed[1] & AACK_I_AM_COORD)==0)
	return 0;
    }
  }
  //If the frame type indicates that the frame is a beacon frame, the source PAN
  //identifier shall match macPANId unless macPANId is equal to 0xFFFF, in which case
  //the beacon frame shall be accepted regardless of the source PAN identifier.
  else if((fcf & FRAME_TYPE) == FRAMETYPE_BEACON){
    if((radio_reg->pan_id[0] != 0xff) || (radio_reg->pan_id[1] != 0xff)){
      if((fcf & D_ADDR_MODE) == ((uint8_t) 0<<10)){
	if(psdu[3] != radio_reg->pan_id[0])//s_panid
	  return 0;
	else if(psdu[4] != radio_reg->pan_id[1])
	  return 0;
      }
      else if((fcf & D_ADDR_MODE) == ((uint8_t) 2<<10)){
	if(psdu[7] != radio_reg->pan_id[0])//s_panid
	  return 0;
	else if(psdu[8] != radio_reg->pan_id[1])
	  return 0;
      }
      else if((fcf & D_ADDR_MODE) == ((uint8_t) 3<<10)){
	if(psdu[13] != radio_reg->pan_id[0])//s_panid
	  return 0;
	else if(psdu[14] != radio_reg->pan_id[1])
	  return 0;
      }
    }
  }
  printf("--------Finish FrameFilting-------\n\r");
  return 1;
}

boolean radioFrameReceive(AT86RF_io *radioIO, u08 phr_indice){
  //printf("\r---------Frame Receiving-------\n\r");
  static int i;//counter
  static int j = 7;//indice of bit

  if(i<3)
    i = phr_indice;

  if((i==phr_indice)&&(j==7))
    radioClearPSDU(phr_indice);
  
  if(i<phr){    
    if(j>=0){
      psdu[i] |= (radioIO->rfn << j);
      j--;
    }
    else{
      j = 7;
      i++;
    }
    return 0;
  }
  else{
    printf("\r---------Finish Receiving-------\n\r");
    i = 0;
    j = 7;
    return 1;
  }
}

void radioWait(uint8_t time)
{
  while(time--);
}

void radioRisingEdge(AT86RF_io *radioIO)
{
  while(radioIO->slp_tr == 0);
}

boolean radioACKTransmit(AT86RF_io *radioIO)
{
  static int i = 0;//counter
  static int j = 7;//indice of bit
  static int k = 0;
  //pres_seq
  if(i<4){
    if(j>=0){
      radioIO->rfp = (((0 >> j) & 1) == 1);
      j--;
    }
    else{
      j = 7;
      i++;
    }
  }
  else{
    
    if(j>=0){
      //sfd
      if(k==0)
	radioIO->rfp = (((radio_reg->sfd_value >> j) & 1) == 1);
      //phr
      else if(k==1)
	radioIO->rfp = (((5 >> j) & 1) == 1);
      //seqence
      else if(k==4)
	radioIO->rfp = (((seq_receive >> j) & 1) == 1);
      //PSDU
      else if(k<7)
	radioIO->rfp = (((psdu[k] >> j) & 1) == 1);
      
      j--;
    }
    else{
      if(k>=6){
	k = 7;
	return 1;
      }
      else{
	k++;
	j = 7;
      }
    }
  }
  return 0;
}

uint8_t radioScanMHR(AT86RF_io *radioIO)
{
  //printf("--------Scanning MHR-------\n\r");
  static int i = 0;//counter
  static int j = 7;//indice of bit
  static uint8_t phr_indice = 3;

  if((i==0)||(j==7))
    radioClearGV(0);

  if(i<phr_indice){    
    if(j>=0){
      psdu[i] |= (radioIO->rfn << j);
      j--;
    }
    else{
      //FCF received
      if(i==1){

	//Destination address 16bits + PAN_ID
	if((fcf & D_ADDR_MODE) == ((uint8_t) 0x2<<10)){
	  phr_indice += 4;
	}
	//Destination address 64bits + PAN_ID
	else if((fcf & D_ADDR_MODE) == ((uint8_t) 0x3<<10)){
	  phr_indice += 10;
	}

	//Source address 16bits + PAN_ID
	if((fcf & S_ADDR_MODE) == ((uint8_t) 0x2<<14))
	  phr_indice += 4;
	//Source address 64bits + PAN_ID
	else if((fcf & S_ADDR_MODE) == ((uint8_t) 0x3<<14))
	  phr_indice += 10;	    
      }
      j = 7;
      i++;
    }
    if(i<=phr_indice)
      return 0;
  }
  else{
    switch(fcf & FRAME_TYPE){
    case 0:
      printf("Frame Type = Beacon !\n\r");
      break;
    case 1:
      printf("Frame Type = Data !\n\r");
      break;
    case 2:
      printf("Frame Type = ACK !\n\r");
      break;
    case 3:
      printf("Frame Type = MAC command !\n\r");
      break;
    default:
      printf("Reserved frame type ! \n\r");
    }
    printf("--------Finish Scanning-------\n\r");
    return phr_indice;
  }
}

//BUSY_RX_AACK
boolean radioTransaction(AT86RF_io *radioIO) 
{
  uint8_t phr_indice;

  radio_reg->irq_status |= RX_START;
  radioIO->irq = 1;
  
  phr_indice = radioScanMHR(radioIO);
  if(phr_indice>2){

    if(radioFrameFiltering()){
      radio_reg->irq_status |= AMI;
      radioIO->irq = 1;

      //radioClearPSDU(phr_indice);
      if(radioFrameReceive(radioIO,phr_indice)){

	//Frame Check Sequence valid
	if((radio_reg->phy_rssi & RX_CRC_VALID)!=0){

	  radio_reg->irq_status |= TRX_END;
	  radioIO->irq = 1;

	  if((radio_reg->tx_status & TRX_STATUS) == BUSY_RX_AACK){

	    //ACK requested
	    if(((fcf & ACKREQ >> 5)==1) && ((radio_reg->csma_seed[1] & AACK_DIS_ACK) == 0) && ((fcf & FRAME_VERSION)<=(radio_reg->csma_seed[1] >> 6))){

	      //Slotted operation = 0
	      if((radio_reg->xah_ctrl_0 & SLOTTED_OPERATION)==0){
		//AACK time = 0
		if((radio_reg->xah_ctrl_1 & AACK_ACK_TIME)==0)
		  radioWait(12);
		else
		  radioWait(2);
	      }	  
	      else{
		radioWait(2);
		radioRisingEdge(radioIO);
	      }
	      if(radioACKTransmit(radioIO)){
		printf("\rTransaction finished ! \r\n");
		return 1;
	      }
	    }
	  }
	  else if((radio_reg->tx_status & TRX_STATUS) == BUSY_RX){
	    printf("\rTransaction finished ! \r\n");
	    return 1;
	  }
	}  
      }
    }
    //if !radioFrameFilting
    //Promiscuous Mode
    else{  
      if(radioFrameReceive(radioIO, phr_indice)){
	if((radio_reg->xah_ctrl_1 & AACK_PROM_MODE)!=0){
	  radio_reg->irq_status |= TRX_END;
	  radioIO->irq = 1;
	  printf("\rTransaction finished ! \r\n");
	  return 1;
	}
	//Reserved Frames
	else{
	  if((fcf & FRAME_TYPE) > 3){
	    if((radio_reg->xah_ctrl_1 & AACK_UPLD_RES_FT)!=0)
	      if((radio_reg->phy_rssi & RX_CRC_VALID)!=0){
		radio_reg->irq_status |= TRX_END;
		radioIO->irq = 1;
		printf("\rTransaction finished ! \r\n");
		return 1;
	      }
	  }
	} 
      }
    }
  }
  return 0;
}

/************************************************************************************
 *State : BUSY_TX_ARET
 ************************************************************************************/

boolean radioFrameEnd() 
{
  if((radio_reg->tx_status & TRAC_STATUS) == INVALID)
    return 0;
  else{
    printf("\rFrame end ! \r\n");
    return 1;
  }
}


boolean radioSHRDetected(AT86RF_io *radioIO)
{  /*
  int i;
  while(i<4)
    pre_seq[i++] = 0;
  radio_reg->sfd_value = 0xA7;
  printf("\rSHR detected ! \r\n");
  return 1;
   */
  
  static int i = 0;//counter
  static int j = 7;//indice of bit
  static uint8_t sfd = 0;
  //clear pres_seq  
  
  //while(i<4){
  if(i<4){
    if(j>=0){
      //pre_seq[i] |= (radioIO->rfn << j);
      if(radioIO->rfn == 0)
	j--;
      else{
	printf("\rinvalid PRES_SEQUENCE ! Go back to wait for PRES_SEQUENCE \r\n");
	i = 0;
	j = 7;
	return 0;
      }
    }
    else{
      j = 7;
      i++;
      sfd = 0;
    }
  }
  else if(i==4){
    if(j>=0){
      sfd |= (radioIO->rfn << j);
      j--;
    }
    else{
      if(sfd != radio_reg->sfd_value){
	printf("\rinvalid SFD ! Go back to wait for PRES_SEQUENCE \r\n");
	i = 0;
	j = 7;
	sfd = 0;
	return 0;
	//goto WAITBEGIN;
      }
      else{	
	printf("\rvalid SFD ! \r\n");
	//return 0;
	i = 5;
	j = 7;
      }
    }
  }
  else if(i==5){
    if(j>=0){
      phr |= (radioIO->rfn << j);
      j--;
    }
    else{
      if((phr!=5)||(phr<9)){
	printf("\rreserved PHR ! \r\n");
	i = 0;
	j = 7;
	phr = 0;
	return 0;
	//goto WAITBEGIN;
      }
      else{	
	printf("\rvalid PHR ! \r\n");
	i = 6;
	j = 7;
	return 1;
      }
    }    
  }
  else if(i==6){
    i = 6;
    j = 7;
    return 1;    
  }
  return 0;
}

//BUSY_TX_ARET
boolean radioReceiveACK(AT86RF_io *radioIO)
{
  static int i = 0;//counter
  static int j = 7;//indice of bit
  static uint8_t sfd_ack = 0;
  static uint8_t phr_ack = 0;

  if(i<4){
    if(j>=0){
      if(radioIO->rfn == 0)
	j--;
      else{
	i = 0;
	j = 7;
      }
    }
    else{
      j = 7;
      i++;
    }
  }
  else if(i==4){
    if(j>=0){
      sfd_ack |= (radioIO->rfn << j);
      j--;
    }
    else{
      if(sfd_ack != radio_reg->sfd_value){
	printf("\rinvalid SFD ! Go back to wait for PRES_SEQUENCE \r\n");
	i = 0;
	j = 7;
      }
      else{
	sfd_ack = 0;
	i = 5;
	j = 7;
      }
    }
  }
  else if(i==5){
    if(j>=0){
      phr_ack |= (radioIO->rfn << j);
      j--;
    }
    else{
      i = 6;
      j = 7;
      if(phr_ack!=5){
	printf("\rNot ACK frame ! \r\n");
	i = 0;
	j = 7;
	phr_ack = 0;
      }
    }
  }
  else {
    //valid quantity of data
    if(phr_ack==5){
      if(i<(phr_ack+6)){    
	if(j>=0){
	  psdu[i-6] |= (radioIO->rfn << j);
	  j--;
	}
	else{
	  j = 7;
	  i++;
	}
      }
      else{
	i = 0;
	j = 7;
	sfd_ack = 0;
	phr_ack = 0;
	return 1;
      }
    }
  }
  return 0;
}

boolean radioACKValid()
{
  if((fcf & FRAME_TYPE)== FRAMETYPE_ACK){
    if(psdu[2] == seq_transmit){//seq_num valid
      return 1;
    }
  }
  return 0;
}

boolean radioCCA()
{
  //Random Backoff
  radio_reg->csma_seed[0] = 0xff;
  radio_reg->csma_seed[1] = radio_reg->csma_seed[1] & (~CSMA_SEED_1) | 0x7;;
  
  csma_rctr++;

  radio_reg->phy_cc_cca = radio_reg->phy_cc_cca & CCA_MODE | 0x2;//Carrier sense only
  //CCA requested in RX modes
  radio_reg->phy_cc_cca |= CCA_REQUEST;//a cca request
  if((radio_reg->tx_status & CCA_STATUS) != 0)//if idle
    {
      radio_reg->tx_status &= (~CCA_STATUS);//clear idle
      radio_reg->tx_status &= (~CCA_DONE);//clear done
      radioWait(8);
      radio_reg->tx_status |= CCA_STATUS;//idle
      radio_reg->tx_status |= CCA_DONE;//done
      return 1;
    }
  return 0;
}

boolean radioTransmitFrame(AT86RF_io *radioIO)
{
  static int i = 0;//counter
  static int j = 7;//indice of bit

  //valid quantity of data
  if((phr==5)||(phr>8)){

    //pres_seq
    if(i<4){
      if(j>=0){
	radioIO->rfp = (((0 >> j) & 1) == 1);
	j--;
      }
      else{
	j = 7;
	i++;
      }
    }
    //sfd
    else if(i==4){
      if(j>=0){
	radioIO->rfp = (((radio_reg->sfd_value >> j) & 1) == 1);
	j--;
      }
      else{
	j = 7;
	i = 5;
      }
    }
    //phr
    else if(i==5){
      if(j>=0){
	radioIO->rfp = (((phr >> j) & 1) == 1);
	j--;
      }
      else{
	j = 7;
	i = 6;
	seq_transmit = 0;
      }
    }    
    //psdu
    else {
      if(i<(phr+6)){    
	if(j>=0){
	  radioIO->rfp = (((psdu[i-6] >> j) & 1) == 1);
	  if(i==8)//sequence
	    seq_transmit |= (radioIO->rfp << j);
	  j--;
	}
	else{
	  j = 7;
	  i++;
	}
      }
      else{
	i = 0;
	j = 7;
	return 1;
      }
    }
  }
  else
    printf("\rFailed Transmission : PHR reserved ! \r\n");
  return 0;
}

boolean radioTxAret(AT86RF_io *radioIO)
{
  radio_reg->trx_state |= INVALID;
  static int i = 0;
 
  if(i==0){
    //no retry performed if max_csma_retries < 7
    if(((radio_reg->xah_ctrl_0 & MAX_CSMA_RETRIES) >> 1) < 7){
      csma_rctr = 0;
      if(!(radioCCA())){//cca failure
	if(csma_rctr > ((radio_reg->xah_ctrl_0 & MAX_CSMA_RETRIES) >> 1)){
	  radio_reg->trx_state = radio_reg->trx_state & (~TRAC_STATUS) | CHANNEL_ACCESS_FAILURE;
	  goto INTERRUPT;
	}
      }
      i = 1;
    }
  }

  if(radioTransmitFrame(radioIO)){
    frame_rctr++;
    if((fcf & ACKREQ)!=0){//ACK Requested
      if(radioReceiveACK(radioIO)){//ACK received before timeout
	if(radioACKValid()){
	  if((radio_reg->csma_seed[1] & AACK_SET_PD)!=0){
	    radio_reg->trx_state = radio_reg->trx_state & (~TRAC_STATUS) | SUCCESS_DATA_PENDING;
	    goto INTERRUPT;
	  }
	  else
	    radio_reg->trx_state = radio_reg->trx_state & (~TRAC_STATUS) | SUCCESS;
	  goto INTERRUPT;
	}
      }
      else{
	if(frame_rctr > ((radio_reg->xah_ctrl_0 & MAX_FRAME_RETRIES) >> 4)){
	  radio_reg->trx_state = radio_reg->trx_state & (~TRAC_STATUS) | NO_ACK;
	  goto INTERRUPT;	
	}
	else{
	  i = 0;
	  return 0;
	}
      }
    }
    else
      radio_reg->trx_state = radio_reg->trx_state & (~TRAC_STATUS) | SUCCESS;
  
  INTERRUPT:
    radio_reg->irq_status |= TRX_END;
    return 1;
  }
  return 0;
}

/*********************************************************************************
 *State Machine 
 ********************************************************************************/

int radioStateMachine(AT86RF_io *radioIO, int line_in)
{
  uint8_t cmd;
  //command of change
  cmd = radio_reg->trx_state & TRX_CMD;
  //actual state
  switch(radio_reg->tx_status & TRX_STATUS){
  case P_ON:
    printf("\r State = P_ON\n\r");
    radio_update(cmd);
    return line_in;
    break;
  case BUSY_RX:
    printf("\r State = BUSY_RX\n\r");
    if(radioTransaction(radioIO)){
    //if(radioFrameReceive()){
      //if detecting the receive end, jump to RX_ON
      printf("\r jump to state = RX_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | RX_ON;
      return 0;
    }
    return line_in;
    break;
  case BUSY_TX:
    printf("\r State = BUSY_TX\n\r");
    //if detecting the transmit end, jump to PLL_ON
    if(radioTransmitFrame(radioIO)){
      printf("\r jump to state = PLL_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | PLL_ON;
      return 0;
    }
    return line_in;
    break;
  case RX_ON:
    printf("\r State = RX_ON\n\r");
    radio_update(cmd);
    //if detecting SHR, jump in to BUSY_RX
    if((radio_reg->tx_status & TRX_STATUS) == RX_ON){
      if(radioSHRDetected(radioIO)){
	printf("\r jump to state = BUSY_RX\n\r");
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_RX;
      }
    }
    return line_in;
    break;
  case TRX_OFF:
    printf("\r State = TRX_OFF\r\n");
    radio_update(cmd);
    if((radio_reg->tx_status & TRX_STATUS) == TRX_OFF){
      if(radioIO->slp_tr==1){
	printf("\r jump to state = SLEEP\n\r");
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | SLEEP;
      }
    }
    return line_in;
    break;
  case PLL_ON:
    printf("\r State = PLL_ON\n\r");
    radio_update(cmd);
    if((radio_reg->tx_status & TRX_STATUS) == PLL_ON){
      //if detecting signal SLP_TR, jump in to BUSY_TX
      if(radioIO->slp_tr==1){
	printf("\r jump to state = BUSY_TX\n\r");
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_TX;
      }
    }
    return line_in;
    break;
  case SLEEP:
    printf("\r State = SLEEP\n\r");
    if(radioIO->slp_tr==0){
      printf("\r jump to state = TRX_OFF\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | TRX_OFF;
    }
    return line_in;
    break;
  case PREP_DEEP_SLEEP:
    printf("\r State = PREP_DEEP_SLEEP\n\r");    
    radio_update(cmd);
    if((radio_reg->tx_status & TRX_STATUS) == PREP_DEEP_SLEEP)
    if(radioIO->slp_tr==1){
      printf("\r jump to state = DEEP_SLEEP\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | SLEEP;
    }
    return line_in;
    break;
  case BUSY_RX_AACK:
    printf("\r State = BUSY_RX_AACK\n\r");
    if(radioTransaction(radioIO)){//Transaction finished
      printf("\r jump to state = RX_AACK_ON\n\r");      
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | RX_AACK_ON;
      return 0;
    }
    return line_in;
    break;
  case BUSY_TX_ARET:
    printf("\r State = BUSY_TX_ARET\n\r");
    if(radioTxAret(radioIO)){
      printf("\r jump to state = TX_ARET_ON\n\r");
      radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | TX_ARET_ON;
      return 0;
    }
    return line_in;
    break;
  case RX_AACK_ON:
    printf("\r State = RX_AACK_ON\n\r");
    //if SHR detected,jump to BUSY_RX_AACK;
    //else stay on RX_AACK_ON
    radio_update(cmd);
    if((radio_reg->tx_status & TRX_STATUS) == RX_AACK_ON){
      if(radioSHRDetected(radioIO)){
	printf("\r jump to state = BUSY_RX_AACK\n\r");
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_RX_AACK;
      }
    }
    return line_in;
    break;
  case TX_ARET_ON:
    printf("\r State = TX_ARET_ON\n\r");
    frame_rctr=0;//FIX_ME!
    radio_update(cmd);
    if((radio_reg->tx_status & TRX_STATUS) == TX_ARET_ON){
      if(radioIO->slp_tr==1){
	printf("\r jump to state = BUSY_TX_ARET\n\r");
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | BUSY_TX_ARET;
      }
    }
    return line_in;
    break;
  default:
    printf("Out of state ! \n");
    return line_in;
  }
  // }
  //}
}

int radioRun(AT86RF_io *radioIO, int line_in){
    return radioStateMachine(radioIO,line_in);
}

int radioStep(AT86RF_io *radioIO, int line_in){
  static boolean finish;
  static int i = 15;
  static int j = 0;

  if(radioIO->nrst==0){
    radioReset();
    printf("\r RADIO Reset ! \r\n");
    //VDD is presented, jump to P_ON
    if(radioIO->nrst==1){      
      if(radioIO->evdd==1)
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | P_ON;
      else
	radio_reg->tx_status = radio_reg->tx_status & (~TRX_STATUS) | TRX_OFF;	
    }
    return line_in;
  }  
  else{
    if(radioIO->s_sclk==1){
      //SPI slave
      if(finish == 0){
	//"finish" = 1 when cmd has been written into TRX_CMD
	finish = (radioTRXtest(radioIO, i)==0);
      }

      if(i>=0){
	i--;
      }
      else{
	//j = 0 : cmd:P_ON->TRX_OFF
	//j = 1 : cmd:TRX_OFF->PLL_ON/RX_ON
	//j > 1 & line_in = 1 : cmd:FrameRead(possible)
	//j = 2 & line_in = 2 : cmd:FrameWrite
	//j = 3 & line_in = 2 : cmd:TX_START/radioIO->slp_tr = 1
	if(finish==1)line_in = radioRun(radioIO,line_in);
	//Transfer FrameWrite
	if(line_in == 2){
	  if(j<2){
	    if(finish==1){
	      i = 15;
	      j++;
	      finish = 0;
	    }
	  }
	  else if(j==2){
	    if(finish==1){
	      i = 16;
	      j++;
	      finish = 0;
	    }
	  }
	}
	//Receive 
	else{
	  if(j==0){
	    if(finish==1){
	      i = 15;
	      j++;
	      finish = 0;
	    }
	  }
	}

      }
      return line_in;
    }
    else
      return line_in;
  }
}
