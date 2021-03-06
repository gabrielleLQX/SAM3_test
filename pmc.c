/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

//#include "Board.h"

#include "AT91SAM3SD8.h"
//#include "at91sam3sd8.h"
#include "global.h"
#include "pmc.h"
#include <stdio.h>
/*----------------------------------------------------------------------------
 *        Local definitions
 *----------------------------------------------------------------------------*/

#define MASK_STATUS0 0xFFFFFFFC
#define MASK_STATUS1 0xFFFFFFFF

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

AT91PS_PMC PMC = AT91C_BASE_PMC;
/**
 * \brief Enables the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targetted.
 *
 * \note The ID must NOT be shifted (i.e. 1 << ID_xxx).
 *
 * \param id  Peripheral ID (ID_xxx).
 */
void PMC_EnablePeripheral(unsigned int id)
{
  if(id < 35){
    if (id < 32) {
      if ((PMC->PMC_PCSR0 & (1 << id)) == (1 << id)) {
	printf("\rPMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", id);
      }
      else {
	PMC->PMC_PCER0 = 1 << id;
      }
    }
    else {
      id -= 32;
      if ((PMC->PMC_PCSR1 & (1 << id)) == (1 << id)) {
	printf("\rPMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", id + 32);
      }
      else {
	PMC->PMC_PCER1 = 1 << id;
      }
    }
  }
  else
    printf("\rError : Wrong ID number ! \n");
}

/**
 * \brief Disables the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targetted.
 *
 * \note The ID must NOT be shifted (i.e. 1 << ID_xxx).
 *
 * \param id  Peripheral ID (ID_xxx).
 */
void PMC_DisablePeripheral(unsigned int id)
{
  if(id < 35){
    if (id < 32) {
      if ((PMC->PMC_PCSR0 & (1 << id)) != (1 << id)) {
	printf("\rPMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", id);
      }
      else {
	PMC->PMC_PCDR0 = 1 << id;
      }
    }
    else {
      id -= 32;
      if ((PMC->PMC_PCSR1 & (1 << id)) != (1 << id)) {
	printf("\rPMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", id + 32);
      }
      else {
	PMC->PMC_PCDR1 = 1 << id;
      }
    }
  }
  else
    printf("\rError : Wrong ID number ! \n");

}

/**
 * \brief Enable all the periph clock via PMC.
 */
void PMC_EnableAllPeripherals(void)
{
    PMC->PMC_PCER0 = MASK_STATUS0;
  printf("\rPMC->PMC_PCSR0(%x) = %x \n", &PMC->PMC_PCSR0, PMC->PMC_PCSR0);
    while( (PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0);
    PMC->PMC_PCER1 = MASK_STATUS1;
  printf("\rPMC->PMC_PCSR1(%x) = %x \n", &PMC->PMC_PCSR1, PMC->PMC_PCSR1);
    while( (PMC->PMC_PCSR1 & MASK_STATUS1) != MASK_STATUS1);
    printf("\rEnable all periph clocks\n\r");
}
/**
 * \brief Disable all the periph clock via PMC.
 */
void PMC_DisableAllPeripherals(void)
{
    PMC->PMC_PCDR0 = MASK_STATUS0;
    while((PMC->PMC_PCSR0 & MASK_STATUS0) != 0);
    PMC->PMC_PCDR1 = MASK_STATUS1;
    while((PMC->PMC_PCSR1 & MASK_STATUS1) != 0);
    printf("\rDisable all periph clocks\n\r");
}

/**
 * \brief Get Periph Status for the given peripheral ID.
 *
 * \param id  Peripheral ID (ID_xxx).
 */
unsigned int PMC_IsPeriphEnabled(unsigned int id)
{
  if(id < 35){
    if (id < 32) {
      return (PMC->PMC_PCSR0 & (1 << id));
    }
    else {
      return (PMC->PMC_PCSR1 & (1 << (id - 32)));
    }
  }
  else
    printf("\rError : Wrong ID number ! \n");
}
