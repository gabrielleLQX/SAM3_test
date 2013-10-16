/*
 * TITLE		: 	SPI DRIVER FOR AT91SAM7S256
 * AUTHOR		:	BALAJI VENKATACHALAM
 * DATE			:	2ND OCTOBER 2008
 * FILENAME		:	spi.c
 * DESCRIPTION	:	COMPRISES 3 FUNCTIONS.
 * 					1. void spiInit(void) 		- Initializes SPI peripheral
 * 					2. u08 spiTransferByte(u08)	- Transfer a Character
 * 					3. u16 spiTransferWord(u16)	- Transfer a Word
 * */

#include "AT91SAM3SD8.h"
//#include "at91sam3sd8.h"
#include "global.h"
#include "spi.h"
#include <stdio.h>

#ifndef SPI_SCKDIV
#define SPI_SCKDIV		2
#endif

AT91PS_SPI pSPI = AT91C_BASE_SPI;
//static volatile AT91_spi *spiIO;
//spiIO = malloc(sizeof(AT91_spi));

void spiInit()
{
  AT91C_BASE_PMC->PMC_PCER0 |= (1<<AT91C_ID_SPI);

  //PIO PINS SETUP FOR SPI BUS
  *AT91C_PIOA_ASR   = AT91C_PA12_MISO|AT91C_PA13_MOSI|AT91C_PA14_SPCK;	// assign pins to SPI interface
  *AT91C_PIOA_PDR   = AT91C_PA12_MISO|AT91C_PA13_MOSI|AT91C_PA14_SPCK;
  *AT91C_PIOA_PPUER = AT91C_PA12_MISO|AT91C_PA13_MOSI|AT91C_PA14_SPCK;	// set pullups
  
  //CHIP SELECT SETTINGS
  AT91C_BASE_PIOA->PIO_ASR = AT91C_PA11_NPCS0;
  AT91C_BASE_PIOA->PIO_PDR = AT91C_PA11_NPCS0;
  AT91C_BASE_PIOA->PIO_OER = AT91C_PA11_NPCS0;
  
  //
  pSPI->SPI_CR = (AT91C_SPI_SPIEN | AT91C_SPI_SWRST);	
  pSPI->SPI_CR = AT91C_SPI_SPIEN;
  //Local Loop, PS fixed
  //pSPI->SPI_MR = (AT91C_SPI_LLB | AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PS_FIXED | ((0x0)<<16));
  pSPI->SPI_MR = (AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PS_FIXED | ((0x0)<<16));
  pSPI->SPI_CSR[0] = (AT91C_SPI_CPOL | AT91C_SPI_NCPHA | AT91C_SPI_CSAAT | AT91C_SPI_BITS_8 | AT91C_SPI_SCBR | AT91C_SPI_SCBR | AT91C_SPI_DLYBCT);  
}

u08 spiTransferByte(u08 TxData) 
{ 
  unsigned char RxData = 0;
  //ENABLE 8 BIT TRANSFER
  pSPI->SPI_CSR[0] |= AT91C_SPI_BITS_8;

  //MASK UNUSED BITS
  TxData &= 0x000000FF;

  //WAIT UNTIL TRANSMIT REGISTER IS EMPTY
  while (!(pSPI ->SPI_SR & AT91C_SPI_TXEMPTY));

  // TRANSMIT DATA
  pSPI->SPI_TDR = TxData;
    
  //READ THE RECEIVED DATA
  //WAIT UNTIL RECEIVE REGISTER IS FULL
  while ((pSPI -> SPI_SR & AT91C_SPI_RDRF) == 0);

  //READ RDR AND MASK UNUSED BITS
  RxData = (pSPI -> SPI_RDR & 0xFF); 
  return RxData; 
}
u16 spiTransferWord(u16 TxData) 
{ 
  unsigned int RxData = 0;	
  //ENABLE 16 BIT TRANSFER
  pSPI->SPI_CSR[0] |= AT91C_SPI_BITS_16;

  //MASK UNUSED BITS
  TxData &= 0x0000FFFF;

  //WAIT UNTIL TRANSMIT REGISTER IS EMPTY
  while (!(pSPI ->SPI_SR & AT91C_SPI_TXEMPTY));

  // TRANSMIT DATA
  pSPI->SPI_TDR = TxData;
	
  //READ THE RECEIVED DATA
  //WAIT UNTIL RECEIVE REGISTER IS FULL
  while (!(pSPI -> SPI_SR & AT91C_SPI_RDRF));

  //READ RDR AND MASK UNUSED BITS
  RxData = (pSPI -> SPI_RDR & 0x0000FFFF); 
  return RxData; 
}

void spiIOInit(AT91_spi *spimaster_io)
{
  spimaster_io->m_spck = 0;
  spimaster_io->m_miso = 0;
  spimaster_io->m_mosi = 0;
  spimaster_io->m_npcs0_nss = 1;
  spimaster_io->m_npcs1 = 1;
  spimaster_io->m_npcs2 = 1;
  spimaster_io->m_npcs3 = 1;
}


void spiTRXSPI(AT91_spi *spiIO, u08 TxData, int i){

  if(spiIO->m_spck==1){
    spiIO->m_mosi = (((TxData >> i) & 1) == 1);
  }
}

/*
  int i;
  //8bits/unit of transmission 
  i = 7;
  uint8_t cmd;
  while(i>=0){
    //receive the command from SPI master
    if(spiIO->m_spck==1){
      cmd |= (spiIO->m_mosi << i);
      //transmit phy status to master
      spiIO->m_miso = (((spiPhyStatus() >> i) & 1) == 1);
      //wait until spck=0
      while(spiIO->m_spck==1);
    }
    i--;
  }

  int k;//number of data for transmission 
  k = 0;
  i = 7;
  uint8_t data, addr;
  while(i>=0){
    //transmit value of the register in [address]
    if(spiIO->m_spck==1){
      if((cmd & 0xC0) == CMD_REGISTER_READ){//register read	
	spiIO->m_miso = (((spiReadReg(cmd) >> i) & 1) == 1); 
      }
      else if((cmd & 0xC0) == CMD_REGISTER_WRITE){//register write
	data |= ((spiIO->m_mosi) << i);
	if(i==0){
	  spiWrReg(cmd,data);
	  printf("\rcmd = %x, data = %x\r\n",cmd,data);
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_READ){//Frame read
	//phr = spiReadPHR();
	spiIO->m_miso = (((spiReadPHR() >> i) & 1) == 1);
	if(i==0){//PHR received
	  //printf("\rRead : PHR = %x\r\n",spiReadPHR());
	  k = spiReadPHR() + 3;//num_PSDU + LQI + ED + RX_STATUS
	}
      }
      else if((cmd & 0xE0) == CMD_FRAME_WRITE){//Frame write
	phr |= (spiIO->m_mosi << i);
	if(i==0){//PHR received
	  //printf("\r___write : PHR_write = %d\r\n",phr_write);
	  //printf("\r___write : PHR_buff = %d\r\n",phr_buff);
	  spiWrPHR(phr);
	  k = phr;//num_PSDU
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_READ){//SRAM read
	addr |= (spiIO->m_mosi << i);
	if(i==0){//ADDR received
	  printf("\rRead : ADDR = %x\r\n",addr);
	  k = 1;
	}
      }
      else if((cmd & 0xE0) == CMD_SRAM_WRITE){//SRAM write
	addr |= ((spiIO->m_mosi) << i);
	if(i==0){//ADDR received
	  printf("\r___write : addr = %x\r\n",addr);
	  k = 1;//
	}
      }
      else{
	printf("\rinvalid command ! \r\n");
	break;
      }
      //wait until spck=0
      while(spiIO->m_spck==1);
    }
    i--;
  }
  //transmission of PSDU
  i = 7;
  uint8_t psdu_data;
  uint8_t rx_status;
  uint8_t sram_data;
  while(i>=0){
    if((cmd & 0xE0) == CMD_FRAME_READ){//Frame Read
      if(k>3){//PSDU
	spiIO->m_miso = ((spiReadPSDU(k - 3 - 1) >> i) == 1);
	//collect psdu just for printf
	psdu_data |= (spiIO->m_miso << i);
	if(i==0){
	  printf("\rRead : PSDU[%d] = %x\r\n", k - 3 -1, psdu_data);
	  psdu_data = 0;
	  k--;
	  i = 8;
	}
      }
      else if(k==3){//LQI
	spiIO->m_miso = (((spiReadLQI() >> i) & 1) == 1);
	//collect lqi just for printf
	lqi |= (spiIO->m_miso << i);
	if(i==0){
	  printf("\rRead : LQI = %x\r\n",lqi);
	  k--;
	  i = 8;
	}
      }
      else if(k==2){//ED
	spiIO->m_miso = (((spiReadED() >> i) & 1) == 1);
	//collect ed just for printf
	ed |= (spiIO->m_miso << i);
	if(i==0){
	  printf("\rRead : ED = %x\r\n",ed);
	  k--;
	  i = 8;
	}
      }
      else if(k==1){//RX_STATUS
	spiIO->m_miso = (((spiReadRxS() >> i) & 1) == 1);
	//collect rx_status just for printf
	rx_status |= (spiIO->m_miso << i);	    
	if(i==0){	      
	  printf("\rRead : RX_STATUS = %x\r\n",rx_status);
	  k = -1;
	}
      }
    }
    else if((cmd & 0xE0) == 0x60){//Frame write
      if(k>0){//PSDU
	psdu_data |= ((spiIO->m_mosi) << i);
	if(i==0){//psdu received
	  printf("\r___write : No.%d",phr - k);
	  printf(" = %d\r\n", psdu_data);
	  spiWrPSDU(psdu_data, phr - k);
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
    else if((cmd & 0xE0) == 0){//SRAM read
      if(k>0){//
	if(spiIO->m_nsel==0){
	  spiIO->m_miso = ((spiReadSRAM(addr + k - 1) >> i) & 1 == 1);
	  //collect sram_data just for printf
	  sram_data |= (spiIO->m_miso << i);
	  if(i==0){
	    printf("\rRead : SRAM[%x] = %x\r\n", addr + k - 1, sram_data);
	    k++;
	    i = 8;
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
    else if((cmd & 0xE0) == 0x40){//SRAM write
      if(k>0){//
	if(spiIO->m_nsel==0){
	  sram_data |= ((spiIO->m_mosi) << i);
	  if(i==0){//psdu received
	    //printf("\r___write : sram_write = %x\r\n",sram_write);
	    //printf("\r___Write : SRAM[%x] = %x\r\n", addr_buff + k - 1, sram_data);
	    spiWrSRAM(addr + k - 1, sram_data);//addr data
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
    while(spiyIO->m_spck==1);
    i--;
  }
  //End of the transmission
  
}
*/
