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

  
int main() {
  printf("\rHello World!\r\n");
  
  // enable the clock of the PIO (mt:) and USART0
  AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, ( 1 << AT91C_ID_PIOA ) | ( 1 << AT91C_ID_US0 ) ) ;
  //Enable the Reset Pin
  AT91F_RSTSetMode( AT91C_BASE_RSTC , AT91C_RSTC_URSTEN );
  //Initialize the UART		
  uart0_init();
  printf("\rUART INIT\r\n");
  //Initialize SPI


  static AT86RF_io *radioIO;
  radioIO = malloc(sizeof(AT86RF_io));
  radioIO->s_sclk = 0;
  radioIO->s_miso = 0;
  radioIO->s_mosi = 0;
  radioIO->s_nsel = 1;
  
  static AT91_spi *spiIO;
  spiIO = malloc(sizeof(AT91_spi));
  spiIO->m_spck = 0;
  spiIO->m_miso = 0;
  spiIO->m_mosi = 0;
  spiIO->m_npcs0_nss = 0;
  spiIO->m_npcs1 = 1;
  spiIO->m_npcs2 = 1;
  spiIO->m_npcs3 = 1;


  spiInit();
  //spiIOInit(spiIO);
  
  //Say that SPI is initialized
  printf("\rSPI INIT\r\n");

  unsigned char *s = "abcdefgh";
  int j = 0;
  
  printf("\r\n------SPI Test-----\r\n");
  while(*(s+j)!='\0')
    {
      printf("%x ",spiTransferByte(*(s+(j++))));
    } 
  //spiCommand(cmd_ragister_read);
  printf("\r\n------End of SPI Test-----\r\n");

  //printf("\n------Radio Test-----\r\n");
  RTT_Init(pRTTC);
  
  RTT_SetPrescaler(pRTTC,0xf000);
  //printf("\rRTT_SetPrescaler\r\n");

  RTT_SetAlarm(pRTTC,2);
  //printf("\rRTT_SetAlarm\r\n");

  RTT_EnableIT(pRTTC,0x3 << 16);
  //printf("\rRTT_EnableIT\r\n");
  
  radioInit();
  
  int i;
  int finish;
  //at least 2*8bits for transmiting
  i = 15;
  do{
    radioIO->nrst == 1;

    
      while(RTT_GetStatus(pRTTC)==0){
	//radioIO->s_sclk = 0;
      }
      //radioIO->s_sclk = 1;
      spiIO->m_spck = 1;
      if(i>7)
	spiTRXSPI(spiIO, 0xAF, i-8);
      //else if(i>=0)	
      //spiTRXSPI(spiIO, 0xF0, i);
      radioIO->s_sclk = spiIO->m_spck;
      radioIO->s_mosi = spiIO->m_mosi;
      radioIO->s_nsel = spiIO->m_npcs0_nss;
      finish = radioTRXtest(radioIO, i);
      spiIO->m_miso = radioIO->s_miso;
      if(i>-1)
	i--;
     
    //RTT_GetTime(pRTTC);
  }while(finish==1);
  
  free(radioIO);
  free(spiIO);
  
  printf("\r------End of Radio Test-----\r\n");
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