#include "Board.h"
// #include "Cstartup_SAM3.h"
#include "serial.h"
#include "rprintf.h"
#include "global.h"
#include "spi.h"
#include "radio.h"
#include "rtt.h"
#include "pmc.h"

#define cmd_register_read  0x80
#define cmd_register_write 0xC0
#define cmd_frame_read     0x20
#define cmd_frame_write    0x60
#define cmd_SRAM_read      0x00
#define cmd_SRAM_write     0x40

AT91PS_RTTC pRTTC = AT91C_BASE_RTTC;
AT91PS_PMC pPMC = AT91C_BASE_PMC;

//AT86RFIOPS_RADIO ioRADIO = ((AT86RFIOPS_RADIO) 0x10000000);

//AT86RF_PS_RADIO pRADIO;

unsigned int DB = 1;
//SPI
boolean M_SPCK;
boolean M_MISO;
boolean M_MOSI;
boolean M_NPCS0_NSS;
boolean M_NPCS1;
boolean M_NPCS2;
boolean M_NPCS3;

//RADIO
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

int main() {
  int i = 10;
  //AT91_spi spiIO = ((AT91_spi) 0x41000100);
  //AT86RF_io radioIO = ((AT86RF_io) 0x41000200);
  printf("\rHello World!\r\n");
  
  // enable the clock of the PIO (mt:) and USART0
  AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, ( 1 << AT91C_ID_PIOA ) | ( 1 << AT91C_ID_US0 ) ) ;
  //Enable the Reset Pin
  AT91F_RSTSetMode( AT91C_BASE_RSTC , AT91C_RSTC_URSTEN );
  //Initialize the UART		
  uart0_init();
  printf("\rUART INIT\r\n");
  //Initialize SPI
  spiInit(DB);
  
  //Say that SPI is initialized
  printf("\rSPI INIT\r\n");

  unsigned char *s = "abcdefgh";
  int j = 0;
  
  printf("\r\n------SPI Test-----\r\n");
  while(*(s+j)!='\0')
    {
      printf("%c",spiTransferByte(*(s+(j++)),DB));
    } 
  //spiCommand(cmd_ragister_read);
  printf("\r\n------End of SPI Test-----\r\n");

  //printf("\n------RTT Test-----\r\n");
  RTT_Init(pRTTC);
  
  RTT_SetPrescaler(pRTTC,0xf000);
  //printf("\rRTT_SetPrescaler\r\n");

  RTT_SetAlarm(pRTTC,2);
  //printf("\rRTT_SetAlarm\r\n");

  RTT_EnableIT(pRTTC,0x3 << 16);
  //printf("\rRTT_EnableIT\r\n");
  
  int k;
  u08 cmd;
  u08 addr;
  u08 value;
  u08 phystatus;
  u08 cmd_buff;
  u08 data_buff;
  u08 phr;
  u08 phr_write;
  u08 phr_buff;
  u08 psdu;
  u08 psdu_buff;
  u08 sram_write;
  u08 addr_write;
  u08 addr_read;
  u08 sram_data;
  u08 addr_buff;

  u08 lqi;
  u08 ed;
  u08 rx_status;
  
  //spiIOInit(spiIO);
  //  radioIOInit(radioIO);

  printf("\r\n------Radio Test-----\r\n");
  S_SCLK = 0;
  S_MISO = 0;
  S_MOSI = 0;
  S_nSEL = 1;
  
  M_SPCK = 0;
  M_MISO = 0;
  M_MOSI = 0;
  M_NPCS0_NSS = 1;
  M_NPCS1 = 1;
  M_NPCS2 = 1;
  M_NPCS3 = 1;
  
  radioReset();

  
  M_NPCS1 = 0;
  S_nSEL =  M_NPCS1;
  cmd_buff = 0;
  phystatus = 0;  
  data_buff = 0;
  addr_buff = 0;
  sram_data = 0;
  phr = 0;
  i = 7;
  j = 7;
  k = 0;  

  addr = 0x06;//test
  value = 0x08;//test
  cmd = cmd_SRAM_write;//test
  sram_write = 0xA5;//test
  addr_read = 0x90;//test
  addr_write = 0x90;//test
  phr_write = 10;//test

  while(1){
    if( S_nSEL == 1)
      break;
    else {
      while(RTT_GetStatus(pRTTC)==0){
	M_SPCK = 0;
	S_SCLK = M_SPCK;
      }
      M_SPCK = 1;
      S_SCLK = M_SPCK;
      
      // S_SCLK = 0;
      if(i>=0){
	M_MOSI = cmd >> i;
	S_MOSI =  M_MOSI;
	// S_MOSI = cmd >> i;
	cmd_buff |= ( S_MOSI << i);
	phystatus = radioPhyStatus();
	S_MISO = phystatus >> i;
	M_MISO =  S_MISO;
	i--;
	if(i==0){
	  printf("\rcmd_buff = %x, j = %d\r\n",cmd_buff, j);
	  k = 0;
	  j = 7;
	  phr_buff = 0;
	}
      }
      else if(j>=0){
	if((cmd_buff & 0xC0) == 0x80){//register read
	   S_MISO = radioReadReg(cmd_buff) >> j;
	   M_MISO =  S_MISO;
	   data_buff |= ((M_MISO) << j);
	   if(j==0)
	     printf("\rcmd_buff = %x, data_buff = %x\r\n",cmd_buff,data_buff);
	}
	else if((cmd_buff & 0xC0) == 0xC0){//register write
	  M_MOSI = value >> j;
	  S_MOSI =  M_MOSI;
	  data_buff |= ((S_MOSI) << j);
	  if(j==0){
	    radioWrReg(cmd_buff,data_buff);
	    printf("\rcmd_buff = %x, data_buff = %x\r\n",cmd_buff,data_buff);
	  }
	}
	else if((cmd_buff & 0xE0) == 0x20){//Frame read
	  if(k==0){
	    S_MISO = radioReadPHR() >> j;
	    M_MISO = S_MISO;
	    phr |= ((M_MISO) << j);
	    if(j==0){//PHR received
	      printf("\rRead : PHR = %x\r\n",phr);
	      k = phr + 3;//num_PSDU + LQI + ED + RX_STATUS
	      j = 8;
	      psdu_buff = 0;
	    }
	  }
	  else if(k>3){//PSDU
	    S_MISO = radioReadPSDU(phr + 3 - k) >> j;
	    M_MISO = S_MISO;
	    psdu_buff |= (M_MISO << j);
	    if(j==0){
	      printf("\rRead : PSDU[%d] = %x\r\n", phr + 3 - k, psdu_buff);
	      psdu_buff = 0;
	      k--;
	      j = 8;
	    }
	  }
	  else if(k==3){//LQI
	    S_MISO = radioReadLQI() >> j;
	    M_MISO = S_MISO;
	    lqi |= (M_MISO << j);
	    if(j==0){
	      printf("\rRead : LQI = %x\r\n",lqi);
	      k--;
	      j = 8;
	    }
	  }
	  else if(k==2){//ED
	    S_MISO = radioReadED() >> j;
	    M_MISO = S_MISO;
	    ed |= (M_MISO << j);	    
	    if(j==0){
	      printf("\rRead : ED = %x\r\n",ed);
	      k--;
	      j = 8;
	    }
	  }
	  else if(k==1){//RX_STATUS
	    S_MISO = radioReadRxS() >> j;
	    M_MISO = S_MISO;
	    rx_status |= (M_MISO << j);	    
	    if(j==0){	      
	      printf("\rRead : RX_STATUS = %x\r\n",rx_status);
	      k = -1;
	    }
	  }
	}
	else if((cmd_buff & 0xE0) == 0x60){//Frame write
	  if(k==0){
	    M_MOSI = phr_write >> j;
	    S_MOSI = M_MOSI;
	    phr_buff |= ((S_MOSI) << j);
	    if(j==0){//PHR received
	      //printf("\r___write : PHR_write = %d\r\n",phr_write);
	      printf("\r___write : PHR_buff = %d\r\n",phr_buff);
	      radioWrPHR(phr_buff);
	      k = phr_buff;//num_PSDU
	      //setpsdu(psdu_write, phr_buff);
	      j = 8;
	      psdu_buff = 0;
	    }
	  }
	  else if(k>0){//PSDU
	    M_MOSI = k >> j;
	    S_MOSI = M_MOSI;
	    psdu_buff |= ((S_MOSI) << j);
	    if(j==0){//psdu received
	      printf("\r___write : k = %d\r\n",k);
	      printf("\r_____write : %d\r\n", psdu_buff);
	      radioWrPSDU(psdu_buff, phr_buff - k);
	      printf("\rWrite : PSDU_buff[%d] = %x\r\n", phr_buff - k, psdu_buff);
	      k--;
	      if(k==0){
		k = -1;
		j = 0;
	      }
	      else{
		j = 8;
		psdu_buff = 0;
	      }
	    }
	  }
	}
	else if((cmd_buff & 0xE0) == 0){//SRAM read
	  if(k==0){
	    S_MISO = addr_read >> j;
	    M_MISO = S_MISO;
	    addr_buff |= ((M_MISO) << j);
	    if(j==0){//ADDR received
	      printf("\rRead : ADDR = %x\r\n",addr_buff);
	      k = 1;
	      j = 8;
	      sram_data = 0;
	    }
	  }
	  else if(k>0){//
	    if(S_nSEL==0){
	      S_MISO = radioReadSRAM(addr_buff + k - 1) >> j;
	      M_MISO = S_MISO;
	      sram_data |= (M_MISO << j);
	      if(j==0){
		printf("\rRead : SRAM[%x] = %x\r\n", addr_buff + k - 1, sram_data);
		psdu_buff = 0;
		k++;
		j = 8;
		if((addr_buff + k - 1) > 0x94){
		  printf("out of SRAM\r\n");
		  j = 0;
		}
	      }
	    }
	    else{
	      addr_buff = 0;
	      j = 0;
	    }
	  }
	}
	else if((cmd_buff & 0xE0) == 0x40){//SRAM write
	  if(k==0){
	    M_MOSI = addr_write >> j;
	    S_MOSI = M_MOSI;
	    addr_buff |= ((S_MOSI) << j);
	    if(j==0){//ADDR received
	      printf("\r___write : addr_buff = %x\r\n",addr_buff);
	      k = 1;//
	      j = 8;
	      sram_data = 0;
	    }
	  }
	  else if(k>0){//
	    if(S_nSEL==0){
	      M_MOSI = sram_write >> j;
	      S_MOSI = M_MOSI;
	      sram_data |= ((S_MOSI) << j);
	      if(j==0){//psdu received
		//printf("\r___write : sram_write = %x\r\n",sram_write);
		//printf("\r___Write : SRAM[%x] = %x\r\n", addr_buff + k - 1, sram_data);
		radioWrSRAM(addr_buff + k - 1, sram_data);//addr data
		k++;
		j = 8;
		sram_data = 0;
		if((addr_buff + k - 1) > 0x94){
		  printf("out of SRAM\r\n");
		  j = 0;
		}
	      }
	    }
	    else{
	      addr_buff = 0;
	      sram_data = 0;
	      j = 0;
	    }
	  }
	}
	j--;
      }
      else{
	//printf("\rcmd = %x, data_buff = %x\r\n",cmd_buff,data_buff);
	M_NPCS1 = 1;
	S_nSEL =  M_NPCS1;
	cmd_buff = 0;
	data_buff = 0;
	phr = 0;
	phr_buff = 0;
	psdu_buff = 0;
	addr_buff = 0;
	sram_data = 0;
	lqi = 0;
	ed = 0;
	i = 7;
	j = 7;
	k = 0;
	M_SPCK = 0;
	S_SCLK =  M_SPCK;
	break;
      }
    }

    //RTT_GetTime(pRTTC);
  }
  printf("\r------End of Radio Test-----\r\n");
  /*
  RTT_SetPrescaler(pRTTC,0x80);
  printf("\rRTT_SetPrescaler\r\n");
  RTT_SetReload(pRTTC);
  i = 10;
  while(i--){
    while(RTT_GetStatus(pRTTC)==0);
    RTT_GetTime(pRTTC);
  }
  printf("\r------End of RTT Test-----\r\n");

  printf("\n------PMC Test-----\r\n");
  PMC_EnableAllPeripherals();
  printf("\r------End of PMC Test-----\r\n");
  */

  printf("\r\nPlease press any button to exit :\r\n");
  getchar();
  
  printf("\r\n------end of Hello ! ------\r\n");
  return 0;
}
