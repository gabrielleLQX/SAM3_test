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

void spiInit(unsigned int DB)
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

    //SPI CONTROL REGISTER
    //=========================================================================================
    //| -------- | -------- | -------- | -------- | -------- | -------- | -------- | LASTXFER |
    //=========================================================================================
    
    //=========================================================================================
    //| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |
    //========================================================================================= 
    
    //=========================================================================================
    //| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |
    //=========================================================================================
    
    //=========================================================================================
    //|  SWRST   | -------- | -------- | -------- | -------- | -------- |  SPIDIS  |   SPEN   |
    //=========================================================================================
    
      pSPI->SPI_CR = (AT91C_SPI_SPIEN | AT91C_SPI_SWRST);	
      pSPI->SPI_CR = AT91C_SPI_SPIEN;
      pSPI->SPI_WPMR = DB << 1;
      // if(pSPI->SPI_CR & 0x1)
      //	printf("Enable SPI !\nSPI_CR(%x) = %x \n",&pSPI->SPI_CR,pSPI->SPI_CR);
    
    //SPI MODE REGISTER
    //=========================================================================================
    //|                                         DLYBCS                                        |
    //=========================================================================================
    
    //=========================================================================================
    //| -------- | -------- | -------- | -------- |                    PCS                    |
    //========================================================================================= 
    
    //=========================================================================================
    //| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |
    //=========================================================================================
    
    //=========================================================================================
    //|   LLB    | -------- | -------- |  MODFDIS | -------- |  PCSDEC  |    PS    |   MSTR   |
    //=========================================================================================
    /*
      pSPI->SPI_MR |= 0x1;
      pSPI->SPI_MR |= 0x2;
    */
    pSPI->SPI_MR = (AT91C_SPI_LLB | AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PS_FIXED | ((0x0)<<16));
    //printf("finish config,SPI_MR(%x) = %x \n",&pSPI->SPI_MR,*(&pSPI->SPI_MR));
    //SPI CHIP SELECT REGISTER 0 
    //=========================================================================================
    //|                                         DLYBCT                                        |
    //=========================================================================================
    
    //=========================================================================================
    //|                                          DLYBS                                        |
    //========================================================================================= 
    
    //=========================================================================================
    //|                                          SCBR                                         |
    //=========================================================================================
    
    //=========================================================================================
    //|                 BITS                      |   CSAAT  | -------- |   NCPHA  |   CPOL   |
    //=========================================================================================
    
    pSPI->SPI_CSR[0] = (AT91C_SPI_CPOL | AT91C_SPI_NCPHA | AT91C_SPI_CSAAT | AT91C_SPI_BITS_8 | AT91C_SPI_SCBR | AT91C_SPI_SCBR | AT91C_SPI_DLYBCT);
    //printf("SPI_CSR[0](%x) = %x (%x)\n",&pSPI->SPI_CSR[0],*(&pSPI->SPI_CSR[0]),(AT91C_SPI_CPOL | AT91C_SPI_NCPHA | AT91C_SPI_CSAAT | AT91C_SPI_BITS_8 | AT91C_SPI_SCBR | AT91C_SPI_SCBR | AT91C_SPI_DLYBCT));
    
}

u08 spiTransferByte(u08 TxData, unsigned int DB) 
{ 
	unsigned char RxData = 0;
	//ENABLE 8 BIT TRANSFER
	pSPI->SPI_CSR[0] |= AT91C_SPI_BITS_8;
	//printf("before,SPI_CSR[0](%x) = %x \n",&pSPI->SPI_CSR[0],*(&pSPI->SPI_CSR[0]));
	//MASK UNUSED BITS
	TxData &= 0x000000FF;
	//printf("before transmit,TxData = %x \n",TxData);

	//printf("before transmit,SR = %x\n",pSPI->SPI_SR);
	//WAIT UNTIL TRANSMIT REGISTER IS EMPTY
	while (!(pSPI ->SPI_SR & AT91C_SPI_TXEMPTY));

	// TRANSMIT DATA
	pSPI->SPI_WPMR = 0;
	pSPI->SPI_TDR = TxData;
	pSPI->SPI_WPMR = DB << 1;
	//printf("after transmit,SR = %x\n",pSPI->SPI_SR);
	
	//READ THE RECEIVED DATA
	//WAIT UNTIL RECEIVE REGISTER IS FULL
	pSPI->SPI_WPMR = 0;
	while ((pSPI -> SPI_SR & AT91C_SPI_RDRF) == 0);

	pSPI->SPI_WPMR = DB << 1;
	//READ RDR AND MASK UNUSED BITS
	pSPI->SPI_WPMR = 0;	  
	RxData = (pSPI -> SPI_RDR & 0xFF); 
	pSPI->SPI_WPMR = DB << 1;	  
	//printf("after receive,SR = %x\n",pSPI->SPI_SR);	
	//printf("after receive,RxData = %x\n",RxData);
	return RxData; 
}
u16 spiTransferWord(u16 TxData, unsigned int DB) 
{ 
	unsigned int RxData = 0;	
	//ENABLE 16 BIT TRANSFER
	pSPI->SPI_CSR[0] |= AT91C_SPI_BITS_16;
	//printf("before,SPI_CSR[0](%x) = %x \n",&pSPI->SPI_CSR[0],*(&pSPI->SPI_CSR[0]));
	//MASK UNUSED BITS
	TxData &= 0x0000FFFF;
	//printf("before transmit,TxData = %x \n",TxData);

	//printf("before transmit,SR = %x\n",pSPI->SPI_SR);
	//WAIT UNTIL TRANSMIT REGISTER IS EMPTY
	while (!(pSPI ->SPI_SR & AT91C_SPI_TXEMPTY));

	//pSPI->SPI_WPMR = 0;
	// TRANSMIT DATA
	pSPI->SPI_TDR = TxData;	
	//pSPI->SPI_WPMR = DB << 1;
	//printf("after transmit,TDR = %x\n",pSPI->SPI_TDR);
	//printf("after transmit,SR = %x\n",pSPI->SPI_SR);
	
	//READ THE RECEIVED DATA
	//WAIT UNTIL RECEIVE REGISTER IS FULL
	//printf("before receive,SR = %x\n",pSPI->SPI_SR);
	//pSPI->SPI_WPMR = 0;
	while (!(pSPI -> SPI_SR & AT91C_SPI_RDRF));
	
	//pSPI->SPI_WPMR = DB << 1;
	//READ RDR AND MASK UNUSED BITS	 
	
	//pSPI->SPI_WPMR = 0;
	RxData = (pSPI -> SPI_RDR & 0x0000FFFF); 
	//pSPI->SPI_WPMR = DB << 1;	  
	return RxData; 
}
/*
void spiIOInit()
{
  spiIO->M_SPCK = 0;
  spiIO->M_MISO = 0;
  spiIO->M_MOSI = 0;
  spiIO->M_NPCS0_NSS = 1;
  spiIO->M_NPCS1 = 1;
  spiIO->M_NPCS2 = 1;
  spiIO->M_NPCS3 = 1;
}
*/
