#include "AT91SAM3SD8.h"
//#include "at91sam3sd8.h"
#include "global.h"
#include "spi.h"
#include "radio.h"
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
  pSPI->SPI_MR = (AT91C_SPI_LLB | AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PS_FIXED | ((0x0)<<16));
  //pSPI->SPI_MR = (AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PS_FIXED | ((0x0)<<16));
  pSPI->SPI_CSR[0] = (AT91C_SPI_CPOL | AT91C_SPI_NCPHA | AT91C_SPI_CSAAT | AT91C_SPI_BITS_8 | AT91C_SPI_SCBR | AT91C_SPI_SCBR | AT91C_SPI_DLYBCT);  
}

void spiTransferByte(u08 TxData, AT91_spi *spiIO, int i) 
{ 
  unsigned char RxData = 0;
  static unsigned char ShiftRegister = 0;
  //ENABLE 8 BIT TRANSFER
  pSPI->SPI_CSR[0] |= AT91C_SPI_BITS_8;

  if(i==7){
    //MASK UNUSED BITS
    TxData &= 0x000000FF;
    
    //WAIT UNTIL TRANSMIT REGISTER IS EMPTY
    while (!(pSPI ->SPI_SR & AT91C_SPI_TXEMPTY));
    
    // TRANSMIT DATA
    pSPI->SPI_TDR = TxData;
    ShiftRegister = pSPI->SPI_TDR;
  }
  if(i<8){
    spiIO->m_mosi = (((ShiftRegister >> i) & 1) == 1);
  }
  if(i==0){
    /*
    //READ THE RECEIVED DATA
    //WAIT UNTIL RECEIVE REGISTER IS FULL
    while ((pSPI -> SPI_SR & AT91C_SPI_RDRF) == 0);
    //READ RDR AND MASK UNUSED BITS
    RxData = (pSPI -> SPI_RDR & 0xFF); 
    printf("\rspi_receive = %x\r\n", RxData);
    */
    ShiftRegister = 0;
    //return RxData; 
  }
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

void spiStep(AT91_spi *spiIO){
  static int i = 15;
  static int k = 0;
  uint8_t reg_addr;//test
  uint8_t cmd_state[9];
  reg_addr = 0x02;//TRX_STATE
  cmd_state[0] = TRX_OFF;//TRX_CMD
  cmd_state[6] = RX_ON;//TRX_CMD
  cmd_state[7] = RX_AACK_ON;//TRX_CMD
  cmd_state[2] = TX_ARET_ON;//TRX_CMD
  cmd_state[3] = TX_START;//TRX_CMD
  cmd_state[8] = PLL_ON;//TRX_CMD
  cmd_state[5] = PREP_DEEP_SLEEP;//TRX_CMD
  cmd_state[4] = FORCE_TRX_OFF;//TRX_CMD
  cmd_state[1] = FORCE_PLL_ON;//TRX_CMD

  spiIO->m_spck = 1;
  if(i>=0){
    if(i>7)
      spiTransferByte(CMD_REGISTER_WRITE | reg_addr,spiIO,i-8);
    //test
    //spiTRXSPI(spiIO, CMD_REGISTER_WRITE | reg_addr, i-8);
    else if(i>=0)
      spiTransferByte(cmd_state[k],spiIO,i);	
    //test
    //spiTRXSPI(spiIO, cmd_state[k], i);
    i--;  
  }
  else{
    i=15;
    if(k==8)
      k=0;
    else
      k++;
  }
}
