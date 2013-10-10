/*
 * TITLE		: 	SPI DRIVER FOR AT91SAM7S256
 * AUTHOR		:	BALAJI VENKATACHALAM
 * DATE			:	2ND OCTOBER 2008
 * FILENAME		:	spi.h
 * DESCRIPTION	:	Comprises Function Prototypes for the following Functions
 * 					1. spiInit
 * 					2. spiTransferByte
 * 					3. spiTransferWord
 * */

#ifndef ARMLIB_SPI_H
#define ARMLIB_SPI_H


//SPI I/O
typedef struct _ATSPI
{
  boolean M_SPCK;
  boolean M_MISO;
  boolean M_MOSI;
  boolean M_NPCS0_NSS;
  boolean M_NPCS1;
  boolean M_NPCS2;
  boolean M_NPCS3;
}*AT91_spi;


void spiInit(unsigned int debug);
u08 spiTransferByte(u08 TxData, unsigned int debug);
u16 SpiTransferWord(u16 TxData,unsigned int debug);
#endif
//@}

