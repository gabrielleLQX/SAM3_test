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
  spimaster_io->m_irq = 0;
}

void spiTRXSPI(AT91_spi *spiIO, u08 TxData, int i){

  if(spiIO->m_spck==1){
    spiIO->m_mosi = (((TxData >> i) & 1) == 1);
  }
}

void spiStep(AT91_spi *spiIO){
  static int i = 15;
  static int j = 0;
  static int k = 0;
  static int a = 7;
  static int b = -1;
  static int c = 0;
  static unsigned char yORn = 'n';
  
  static uint8_t reg_irq = 0x0f;
  static uint8_t irq_status = 0;//test
  static uint8_t reg_addr = 0x02;//test
  uint8_t cmd_state[9];
  static uint8_t cmd_mode = CMD_REGISTER_WRITE;
  static uint8_t phr_frame = 0;
  static uint8_t data_frame = 0;
  static int line_in;
  //reg_addr = 0x02;//TRX_STATE
  cmd_state[0] = TRX_OFF;//TRX_CMD
  cmd_state[1] = RX_ON;//TRX_CMD
  cmd_state[5] = RX_AACK_ON;//TRX_CMD
  cmd_state[4] = TX_ARET_ON;//TRX_CMD
  cmd_state[3] = TX_START;//TRX_CMD
  cmd_state[2] = PLL_ON;//TRX_CMD
  cmd_state[6] = PREP_DEEP_SLEEP;//TRX_CMD
  cmd_state[7] = FORCE_TRX_OFF;//TRX_CMD
  cmd_state[8] = FORCE_PLL_ON;//TRX_CMD

  spiIO->m_spck = 1;
  spiIO->finish = 0;

  //interruption demanded
  if(spiIO->m_irq==1){
    if(b==-1){
      b = 15;
      line_in = spiIO->line_in;
      spiIO->line_in = 0;
    }
  }
  else{
    if(b>=0){
      //inform model radio to read irq register
      /*
      if(b==15){
	line_in = spiIO->line_in;
	spiIO->line_in = 0;
      }
      */
      if(b>7)
	spiTransferByte(CMD_REGISTER_READ | reg_irq, spiIO, b-8);
      else if(b>=0){
	irq_status |= (spiIO->m_miso << b);
	if(b==0){
	  irq_status = irq_status << 2;
	  spiIO->line_in = line_in;
	}
      }
      b--;  
    }
    else{    
      if(yORn != 'y'){
	if(cmd_mode==CMD_REGISTER_WRITE){
	  if(i>=0){
	    if(i>7)
	      //spiTransferByte(CMD_REGISTER_WRITE | reg_addr,spiIO,i-8);
	      spiTransferByte(cmd_mode | reg_addr,spiIO,i-8);
	    else if(i>=0)
	      spiTransferByte(cmd_state[k],spiIO,i);
	  
	    i--;  
	  }
	  else{
	    //i = 15;
	    if(k==0){
	      k = spiIO->line_in;
	      i = 15;
	    }
	    //Receive
	    else if(k==1){
	      i = -1;
	    }
	    //Transfer
	    else if(k==2){
	      //FrameWrite
	      i = 15;
	      cmd_mode = CMD_FRAME_WRITE;
	      phr_frame = 0;
	    }
	    else if(k==3){
	      phr_frame = 0;
	    }
	  }
	}
	else if(cmd_mode==CMD_FRAME_WRITE){
	  if(i==15){
	    printf("\r Number of octets you want to transfer (0<n<127): ");
	    phr_frame += 100 * (getchar()-'0');
	    phr_frame += 10 * (getchar()-'0');
	    phr_frame += 1 * (getchar()-'0');
	    printf("%d\r\n", phr_frame);
	    //phr = phr_frame;
	  }
	  if(i>=0){
	    if(i>7)
	      spiTransferByte(CMD_FRAME_WRITE,spiIO,i-8);
	    else if(i>=0){
	      spiTransferByte(phr_frame,spiIO,i);
	      j = 0;
	      a = 7;
	    }
	    i--;  
	  }
	  else if(j<phr_frame){
	    if(a==7){
	      data_frame = 0;
	      printf("\r Data[%d] to transfer (0<x<255): ", j);
	      data_frame += 100 * (getchar()-'0');
	      data_frame += 10 * (getchar()-'0');
	      data_frame += 1 * (getchar()-'0');
	      printf("%d\r\n", data_frame);
	    }
	    if(a>=0){
	      spiTransferByte(data_frame,spiIO,a);
	      a--;
	    }
	    else{
	      j++;
	      a = 7;
	      if(j==phr_frame){
		cmd_mode = CMD_REGISTER_WRITE;
		data_frame = 0;
		a = 7;
		i = 15;
		k = 3;
	      }
	    }
	  }	
	}
	else if(cmd_mode==CMD_FRAME_READ){
	  if(i>=0){
	    if(i>7){
	      spiTransferByte(CMD_FRAME_READ,spiIO,i-8);
	      if(i==8)
		phr_frame = 0;
	    }
	    else if(i>=0){
	      phr_frame |= (spiIO->m_miso << i);
	      //spiTransferByte(phr,spiIO,i);
	      if(i==0){
		j = 0;
		a = 7;
		data_frame = 0;
	      }
	    }
	    i--;  
	  }
	  else if(j<phr_frame){
	    if(a==7){
	      data_frame = 0;
	      printf("\r Data[%d]: ", j);
	      printf("%d\r\n", data_frame);
	    }
	    if(a>=0){
	      data_frame |= (spiIO->m_miso << a);
	      //spiTransferByte(data_frame,spiIO,a);
	      if(a==0){
		//printf("%d\r\n", data_frame);
		a = 8;
		data_frame = 0;
		j++;
		if(j==phr_frame){
		  a = 0;
		  k = 3;
		}
	      }
	      a--;
	    }
	  }
	}
      }
      //Receive done:FrameRead
      else{
	if(i>=0){
	  //cmd : Frame Read
	  if(i>7)
	    spiTransferByte(CMD_FRAME_READ,spiIO,i-8);//Frame Read
	  //
	  else if(i>=0){
	    if((i==5)&&(c==0)){
	      c=1;
	      i=7;
	    }
	    if(c==1)phr_frame |= (spiIO->m_miso << i);
	    if(i==0){
	      printf("\r%d octets to read from Radio ! \r\n", phr_frame);
	      j = 0;
	      a = 7;
	      data_frame = 0;
	    }
	  }
	  i--;  
	}
	else if(j<(phr_frame+3)){
	  if(a>=0){
	    data_frame |= (spiIO->m_miso << a);
	    a--;
	  }
	  else{
	    printf("\r Data[%d] : %d\r\n", j,data_frame);
	    j++;
	    a = 7;
	    data_frame = 0;
	    if(j==(phr_frame+3)){
	      printf("Frame Read finished ! \n\r");
	      yORn = 'n';
	      spiIO->finish = 1;
	    }
	  }
	}      
      }
      //Receive
      if(line_in==1){
	if((irq_status & RX_START) != 0){
	  printf("\r Interruption : Rx Started ! \r\n");
	}
	if((irq_status & TRX_END) != 0){
	  printf("\r Frame can be read now! \r\n");
	  printf("\r Do you want to read the Frame read now (y or n)?");
	  printf("%c\r\n", yORn=getchar());
	  if(yORn=='y'){
	    spiIO->line_in = 0;
	    cmd_mode = CMD_FRAME_READ;
	    //phr_frame = 0;
	    i = 15;
	  }
	}
	if((irq_status & AMI) != 0){
	  printf("\r Address is valid ! \r\n");
	}
      }
      //Transfer
      else if(line_in==2){
	if((irq_status & TRX_END) != 0){
	  printf("\r Frame has been written ! \r\n");
	}
      }
      
      irq_status = 0;
      //spiIO->line_in = 1;    
      
    }
  }
}

