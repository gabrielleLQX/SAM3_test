#ifndef ARMLIB_SPI_H
#define ARMLIB_SPI_H


//SPI I/O
typedef struct _ATSPI
{
  boolean m_spck;
  boolean m_miso;
  boolean m_mosi;
  boolean m_npcs0_nss;
  boolean m_npcs1;
  boolean m_npcs2;
  boolean m_npcs3;
  boolean m_irq;
  uint8_t line_in;
  boolean finish;
}AT91_spi;


void spiInit();
void spiTransferByte(u08 TxData, AT91_spi *spiIO, int i);
u16 SpiTransferWord(u16 TxData);

void spiIOInit(AT91_spi *spiIO);
void spiTRXSPI(AT91_spi *spiIO, u08 TxData, int i);
void spiStep(AT91_spi *spiIO);
#endif
//@}

