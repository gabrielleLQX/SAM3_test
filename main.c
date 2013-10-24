#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "Board.h"
// #include "Cstartup_SAM3.h"
#include "serial.h"
#include "rprintf.h"
#include "global.h"
#include "spi.h"
#include "radio.h"
#include "rtt.h"
#include "pmc.h"


AT91PS_RTTC pRTTC = AT91C_BASE_RTTC;
AT91PS_PMC pPMC = AT91C_BASE_PMC;

void debug_wait(boolean gdb_s)
{
  while(1){
    if (gdb_s==1)
      break;
  }
} 

int main() {
  boolean gdb_s;
  //debug_wait(gdb_s);
  printf("\rHello World!\r\n");
  
  // enable the clock of the PIO (mt:) and USART0
  AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, ( 1 << AT91C_ID_PIOA ) | ( 1 << AT91C_ID_US0 ) ) ;
  //Enable the Reset Pin
  AT91F_RSTSetMode( AT91C_BASE_RSTC , AT91C_RSTC_URSTEN );
  //Initialize the UART		
  uart0_init();
  printf("\rUART INIT\r\n");

  //Initialize SPI
  spiInit();  
  //Say that SPI is initialized
  printf("\rSPI INIT\r\n");

  static AT91_spi *spiIO;
  //fprintf(stderr, "Valeur de spiIO = %p\n", spiIO);
  spiIO = malloc(sizeof(AT91_spi));
  spiIO->m_spck = 0;
  spiIO->m_miso = 0;
  spiIO->m_mosi = 0;
  spiIO->m_npcs0_nss = 0;
  spiIO->m_npcs1 = 1;
  spiIO->m_npcs2 = 1;
  spiIO->m_npcs3 = 1;

  radioInit();
  //Say that RADIO is initialized
  printf("\rRADIO INIT\r\n");

  static AT86RF_io *radioIO;
  //fprintf(stderr, "Valeur de radioIO = %p\n", radioIO);
  radioIO = malloc(sizeof(AT86RF_io));
  radioIO->nrst = 1;
  radioIO->s_sclk = 0;
  radioIO->s_miso = 0;
  radioIO->s_mosi = 0;
  radioIO->s_nsel = 1;
  /**********************************************************************
   *test of QEMU_SPI
   *********************************************************************/
  /*
  unsigned char *s = "abcdefgh";
  int j = 0;//counter of the string
  int i = 7;//indice of bit in each transferred data
  unsigned char shift_reg = 0;
  //while(gdb_s==0);
  printf("\r\n------SPI Test-----\r\n");
  spiIO->m_spck = 1;

  radioIO->s_nsel = spiIO->m_npcs0_nss;
  radioIO->s_sclk = spiIO->m_spck;

  while(*(s+j)!='\0')
    {
      while(i>=0){
	spiTransferByte(*(s+j),spiIO,i);
	radioIO->s_mosi = spiIO->m_mosi;
	//for confirm that data is correctly transferred.
	shift_reg |= (radioIO->s_mosi << i);
	if(i==0){
	  i = 7;
	  printf("\rreceive_reg = %c\r\n", shift_reg);
	  shift_reg = 0;
	  break;
	}
	i--;
      }
      j++;    
    }
  printf("\r\n------End of SPI Test-----\r\n");
  */

  printf("\r\n------SPI Test-----\r\n");

  while(1){

    spiStep(spiIO);
    //radioStep(radioIO);
    radioIO->s_sclk = spiIO->m_spck;
    radioIO->s_mosi = spiIO->m_mosi;
    radioIO->s_nsel = spiIO->m_npcs0_nss; 
    radioStep(radioIO);   
    spiIO->m_miso = radioIO->s_miso;
    
  }
  radioDestroy();

  free(radioIO);
  free(spiIO);
  
  printf("\r------End of Radio Test-----\r\n");


  /*********************************************************************
   *test of changing state by writing TRX_CMD in register TRX_STATE(0x02)
   ********************************************************************/
  /*
  int i;
  int j;
  int k;
  boolean finish;
  uint8_t reg_addr;//test
  uint8_t cmd_state[9];
  reg_addr = 0x02;//TRX_STATE
  cmd_state[0] = TRX_OFF;//TRX_CMD
  cmd_state[1] = RX_ON;//TRX_CMD
  cmd_state[2] = RX_AACK_ON;//TRX_CMD
  cmd_state[3] = TX_ARET_ON;//TRX_CMD
  cmd_state[4] = TX_START;//TRX_CMD
  cmd_state[5] = PLL_ON;//TRX_CMD
  cmd_state[6] = PREP_DEEP_SLEEP;//TRX_CMD
  cmd_state[7] = FORCE_TRX_OFF;//TRX_CMD
  cmd_state[8] = FORCE_PLL_ON;//TRX_CMD

  //at least 2*8bits for transmiting
  //8bits of cmd
  //8bits of addr/reg
  i = 15;
  j = 7;
  k = 0;
  while(1){
    spiIO->m_spck = 1;

    if(finish == 0)
      {
	if(i>7)
	  spiTransferByte(CMD_REGISTER_WRITE | reg_addr,spiIO,i-8);
	//test
	//spiTRXSPI(spiIO, CMD_REGISTER_WRITE | reg_addr, i-8);
	else if(i>=0)
	  spiTransferByte(cmd_state[k],spiIO,i);	
	//test
	//spiTRXSPI(spiIO, cmd_state[k], i);

	radioIO->s_sclk = spiIO->m_spck;
	radioIO->s_mosi = spiIO->m_mosi;
	radioIO->s_nsel = spiIO->m_npcs0_nss;

	//"finish" = 1 when cmd has been written into TRX_CMD
	finish = (radioTRXtest(radioIO, i)==0);

	spiIO->m_miso = radioIO->s_miso;

	if(i>=0){
	  i--;
	}
	else{
	  radioRun(radioIO);
	}
      }
    else{
      break;
    }
    
  }
  
  free(radioIO);
  free(spiIO);
  
  printf("\r------End of Radio Test-----\r\n");
  */
  /*********************************************************************
   *test of changing state by writing TRX_CMD in register TRX_STATE(0x02)
   ********************************************************************/
  /*
  int i;
  boolean finish;
  uint8_t reg_addr;//test
  uint8_t cmd_state;
  reg_addr = 0x02;//TRX_STATE
  cmd_state = TRX_OFF;//TRX_CMD

  //at least 2*8bits for transmiting
  //8bits of cmd
  //8bits of addr/reg
  i = 15;
  j = 7;
  while(1){
    radioIO->nrst == 1;
    
    while(RTT_GetStatus(pRTTC)==0){        
      spiIO->m_spck = 0;
      radioIO->s_sclk = spiIO->m_spck;
    }
    spiIO->m_spck = 1;

    if(finish == 0)
      {
        if(i>7)
         //test
         spiTRXSPI(spiIO, CMD_REGISTER_WRITE | reg_addr, i-8);
        else if(i>=0)        
         spiTRXSPI(spiIO, cmd_state, i);

        radioIO->s_sclk = spiIO->m_spck;
        radioIO->s_mosi = spiIO->m_mosi;
        radioIO->s_nsel = spiIO->m_npcs0_nss;
        //"finish" = 1 when cmd has been written into TRX_CMD
        finish = (radioTRXtest(radioIO, i)==0);
        spiIO->m_miso = radioIO->s_miso;
        if(i>=0){
         i--;
        }
        else{
         radioRun(radioIO);
         if(j==0)
         j=8;
         j--;
        }
      }
    else{
      radioRun(radioIO);
      //finish = 0;
      //i = 15;
      //j = 7;
    }
  }


  free(radioIO);
  free(spiIO);
  
  printf("\r------End of Radio Test-----\r\n");
*/

  /****************************************************
   *test of Real Time Timer
   ***************************************************/
  /*
  printf("\n------RTT Test-----\r\n");
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
