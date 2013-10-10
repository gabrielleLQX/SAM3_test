
#include "AT91SAM3SD8.h"
#include "global.h"
#include "rtt.h"
#include <stdio.h>

//AT91PS_RTTC pRTTC = AT91C_BASE_RTTC;
void RTT_Init(AT91PS_RTTC pRTTC)
{  
  pRTTC->RTTC_RTMR = 0x00008000;
  pRTTC->RTTC_RTAR = 0xffffffff;
  /*
    printf("after init MR(%x) = %x\n",&pRTTC->RTTC_RTMR,pRTTC->RTTC_RTMR);
    printf("after init AR(%x) = %x\n",&pRTTC->RTTC_RTAR,pRTTC->RTTC_RTAR);
    printf("after init VR(%x) = %x\n",&pRTTC->RTTC_RTVR,pRTTC->RTTC_RTVR);
    printf("after init SR(%x) = %x\n",&pRTTC->RTTC_RTSR,pRTTC->RTTC_RTSR);
  */
}
/**
 * \brief Changes the prescaler value of the given RTT and restarts it.
 *
 * \note This function disables RTT interrupt sources.
 *
 * \param rtt  Pointer to a Rtt instance.
 * \param prescaler  Prescaler value for the RTT.
 */
void RTT_SetReload(AT91PS_RTTC pRTTC)
{
  pRTTC->RTTC_RTMR |= AT91C_RTTC_RTTRST;
  //printf("MR = %x\n",pRTTC->RTTC_RTMR);
  pRTTC->RTTC_RTMR &= ~AT91C_RTTC_RTTRST;
  //pRTTC->RTTC_RTRTMR & (~AT91C_RTTC_RTRTTRST) | prescaler;
}

void RTT_SetPrescaler(AT91PS_RTTC pRTTC,uint16_t prescaler)
{
  pRTTC->RTTC_RTMR = pRTTC->RTTC_RTMR & 0x70000 | prescaler; //|  AT91C_RTTC_RTTRST);
  //printf("MR = %x\n",pRTTC->RTTC_RTMR);
  //pRTTC->RTTC_RTRTMR & (~AT91C_RTTC_RTRTTRST) | prescaler;
}

/**
 * \brief Returns the current value of the RTT timer value.
 *
 * \param rtt  Pointer to a Rtt instance.
 */
uint32_t RTT_GetTime(AT91PS_RTTC pRTTC)
{
  if(pRTTC->RTTC_RTVR == pRTTC->RTTC_RTAR)
    printf("VR equal to AR = %x\r\n",pRTTC->RTTC_RTVR);
  else
    printf("VR = %x, AR = %x\r\n",pRTTC->RTTC_RTVR,pRTTC->RTTC_RTAR);
  return pRTTC->RTTC_RTVR;
}

/**
 * \brief Enables the specified RTT interrupt sources.
 *
 * \param rtt  Pointer to a Rtt instance.
 * \param sources  Bitmask of interrupts to enable.
 */
void RTT_EnableIT(AT91PS_RTTC pRTTC,uint32_t sources)
{
    pRTTC->RTTC_RTMR |= sources & 0x30000;
    //printf("MR(%x) = %x\n",&pRTTC->RTTC_RTMR,pRTTC->RTTC_RTMR);
}

/**
 * \brief Returns the status register value of the given RTT.
 *
 * \param rtt  Pointer to an Rtt instance.
 */
uint32_t RTT_GetStatus(AT91PS_RTTC pRTTC)
{
  return pRTTC->RTTC_RTSR;
}
uint32_t RTT_GetMode(AT91PS_RTTC pRTTC)
{
  //printf("MR(%x) = %x\n",&pRTTC->RTTC_RTMR,pRTTC->RTTC_RTMR);
  return pRTTC->RTTC_RTMR;
}


/**
 * \brief Configures the RTT to generate an alarm at the given time.
 *
 * \param pRtt  Pointer to an Rtt instance.
 * \param time  Alarm time.
 */
void RTT_SetAlarm(AT91PS_RTTC pRTTC,uint32_t time)
{
  if(time > 0){
    pRTTC->RTTC_RTAR = time;
    //printf("AR(%x) renewed ! = %x\n",&pRTTC->RTTC_RTAR,pRTTC->RTTC_RTAR);
  }
  else
    printf("invalid value\n");
  
}
