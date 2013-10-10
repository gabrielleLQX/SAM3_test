//  ----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
//  ----------------------------------------------------------------------------
//  DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
//  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
//  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  ----------------------------------------------------------------------------
// File Name           : AT91SAM3SD8.h
// Object              : AT91SAM3SD8 definitions
// Generated           : AT91 SW Application Group  08/30/2005 (15:52:59)
// 
// CVS Reference       : /AT91SAM3SD8.pl/1.21/Tue Aug 30 11:55:03 2005//
// CVS Reference       : /SYS_SAM3S.pl/1.2/Tue Feb  1 17:01:52 2005//
// CVS Reference       : /MC_SAM3S.pl/1.3/Fri May 20 14:12:30 2005//
// CVS Reference       : /PMC_SAM3S_USB.pl/1.4/Tue Feb  8 13:58:22 2005//
// CVS Reference       : /RSTC_SAM3S.pl/1.2/Wed Jul 13 14:57:40 2005//
// CVS Reference       : /UDP_SAM3S.pl/1.1/Tue May 10 11:34:52 2005//
// CVS Reference       : /PWM_SAM3S.pl/1.1/Tue May 10 11:53:07 2005//
// CVS Reference       : /RTTC_6081A.pl/1.2/Tue Nov  9 14:43:58 2004//
// CVS Reference       : /PITC_6079A.pl/1.2/Tue Nov  9 14:43:56 2004//
// CVS Reference       : /WDTC_6080A.pl/1.3/Tue Nov  9 14:44:00 2004//
// CVS Reference       : /VREG_6085B.pl/1.1/Tue Feb  1 16:05:48 2005//
// CVS Reference       : /AIC_6075B.pl/1.3/Fri May 20 14:01:30 2005//
// CVS Reference       : /PIO_6057A.pl/1.2/Thu Feb  3 10:18:28 2005//
// CVS Reference       : /DBGU_6059D.pl/1.1/Mon Jan 31 13:15:32 2005//
// CVS Reference       : /US_6089C.pl/1.1/Mon Jul 12 18:23:26 2004//
// CVS Reference       : /SPI_6088D.pl/1.3/Fri May 20 14:08:59 2005//
// CVS Reference       : /SSC_6078A.pl/1.1/Tue Jul 13 07:45:40 2004//
// CVS Reference       : /TC_6082A.pl/1.7/Fri Mar 11 12:52:17 2005//
// CVS Reference       : /TWI_6061A.pl/1.1/Tue Jul 13 07:38:06 2004//
// CVS Reference       : /PDC_6074C.pl/1.2/Thu Feb  3 08:48:54 2005//
// CVS Reference       : /ADC_6051C.pl/1.1/Fri Oct 17 09:12:38 2003//
//  ----------------------------------------------------------------------------

#ifndef AT91SAM3SD8_H
#define AT91SAM3SD8_H

typedef volatile unsigned int AT91_REG;// Hardware register definition

typedef volatile char AT86_REG;// Hardware register definition
// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR System Peripherals
// *****************************************************************************
typedef struct _AT91S_SYS {
  //
  AT91_REG         SMC_SETUP0;
  AT91_REG         SMC_PULSE0;
  AT91_REG         SMC_CYCLE0;
  AT91_REG         SMC_MODE0;
  AT91_REG         SMC_SETUP1;
  AT91_REG         SMC_PULSE1;
  AT91_REG         SMC_CYCLE1;
  AT91_REG         SMC_MODE1;
  AT91_REG         SMC_SETUP2;
  AT91_REG         SMC_PULSE2;
  AT91_REG         SMC_CYCLE2;
  AT91_REG         SMC_MODE2;
  AT91_REG         SMC_SETUP3;
  AT91_REG         SMC_PULSE3;
  AT91_REG         SMC_CYCLE3;
  AT91_REG         SMC_MODE3;
  AT91_REG         SMC_SETUP4;
  AT91_REG         SMC_PULSE4;
  AT91_REG         SMC_CYCLE4;
  AT91_REG         SMC_MODE4;
  AT91_REG	   Reserved0[12]; 	//
  AT91_REG         SMC_OCMS;
  AT91_REG         SMC_KEY1;
  AT91_REG         SMC_KEY2;
  AT91_REG	   Reserved1[22]; 	//
  AT91_REG	   SMC_WPMR;
  AT91_REG         SMC_WPSR;
  AT91_REG	   Reserved2[69]; 	//

  AT91_REG         MATRIX_MCFG0;
  AT91_REG         MATRIX_MCFG1;
  AT91_REG         MATRIX_MCFG2;
  AT91_REG         MATRIX_MCFG3;
  AT91_REG	   Reserved3[12]; 	//
  AT91_REG	   MATRIX_SCFG0;
  AT91_REG	   MATRIX_SCFG1;
  AT91_REG	   MATRIX_SCFG2;
  AT91_REG	   MATRIX_SCFG3;
  AT91_REG	   MATRIX_SCFG4;
  AT91_REG	   Reserved4[11]; 	//
  AT91_REG	   MATRIX_PRAS0;
  AT91_REG	   Reserved5[1]; 	//
  AT91_REG	   MATRIX_PRAS1;
  AT91_REG	   Reserved6[1]; 	//
  AT91_REG	   MATRIX_PRAS2;
  AT91_REG	   Reserved7[1]; 	//
  AT91_REG	   MATRIX_PRAS3;
  AT91_REG	   Reserved8[1]; 	//
  AT91_REG	   MATRIX_PRAS4;
  AT91_REG	   Reserved9[28]; 	//
  AT91_REG	   CCFG_SYSIO;
  AT91_REG	   Reserved10[1]; 	//
  AT91_REG	   CCFG_SMCNFCS;
  AT91_REG	   Reserved11[49]; 	//
  AT91_REG	   MATRIX_WPMR;
  AT91_REG	   MATRIX_WPSR;
  AT91_REG	   Reserved12[5]; 	//

  AT91_REG         PMC_SCER; 	// System Clock Enable Register
  AT91_REG	   PMC_SCDR; 	// System Clock Disable Register
  AT91_REG	   PMC_SCSR; 	// System Clock Status Register
  AT91_REG	   Reserved13[1]; 	// 
  AT91_REG	   PMC_PCER; 	// Peripheral Clock Enable Register
  AT91_REG	   PMC_PCDR; 	// Peripheral Clock Disable Register
  AT91_REG	   PMC_PCSR; 	// Peripheral Clock Status Register
  AT91_REG	   Reserved14[1]; 	// 
  AT91_REG	   CKGR_MOR; 	// Main Oscillator Register
  AT91_REG	   CKGR_MCFR; 	// Main Clock  Frequency Register
  AT91_REG	   CKGR_PLLAR; 	// PLLA Register
  AT91_REG	   CKGR_PLLBR; 	// PLLB Register
  AT91_REG	   PMC_MCKR; 	// Master Clock Register
  AT91_REG	   Reserved15[1]; 	// 
  AT91_REG	   PMC_USB; 	// USB Clock Register
  AT91_REG	   Reserved16[1]; 	// 
  AT91_REG	   PMC_PCK[3]; 	// Programmable Clock Register
  AT91_REG	   Reserved17[5]; 	// 
  AT91_REG	   PMC_IER; 	// Interrupt Enable Register
  AT91_REG	   PMC_IDR; 	// Interrupt Disable Register
  AT91_REG	   PMC_SR; 	// Status Register
  AT91_REG	   PMC_IMR; 	// Interrupt Mask Register
  AT91_REG	   PMC_FSMR; 	// Fast Startup Mode Register
  AT91_REG	   PMC_FSPR; 	// Fast Startup Polarity Register
  AT91_REG	   PMC_FOCR; 	// Fast Startup Clear Register
  AT91_REG	   Reserved18[26]; 	// 
  AT91_REG	   PMC_WPMR;
  AT91_REG	   PMC_WPSR;
  AT91_REG	   Reserved19[5]; 	//
  AT91_REG	   PMC_PCER1;
  AT91_REG	   PMC_PCDR1;
  AT91_REG	   PMC_PCSR1;
  AT91_REG	   Reserved20[1];
  AT91_REG	   PMC_OCR;       // Oscillator Calibration Register
  AT91_REG	   Reserved21[59];

  AT91_REG	   UART0_CR; 	// Control Register
  AT91_REG	   UART0_MR; 	// Mode Register
  AT91_REG	   UART0_IER; 	// Interrupt Enable Register
  AT91_REG	   UART0_IDR; 	// Interrupt Disable Register
  AT91_REG	   UART0_IMR; 	// Interrupt Mask Register
  AT91_REG	   UART0_SR; 	// Status Register
  AT91_REG	   UART0_RHR; 	// Receive Holding Register
  AT91_REG	   UART0_THR; 	// Transmit Holding Register
  AT91_REG	   UART0_BRGR; 	// Baud Rate Generator Register
  AT91_REG	   Reserved22[55];
  AT91_REG	   UART0_PDC[5];
  AT91_REG	   Reserved23[7]; 

  AT91_REG         CHIPID_CIDR;
  AT91_REG         CHIPID_EXID;
  AT91_REG	   Reserved24[48];
 
  AT91_REG	   UART1_CR; 	// Control Register
  AT91_REG	   UART1_MR; 	// Mode Register
  AT91_REG	   UART1_IER; 	// Interrupt Enable Register
  AT91_REG	   UART1_IDR; 	// Interrupt Disable Register
  AT91_REG	   UART1_IMR; 	// Interrupt Mask Register
  AT91_REG	   UART1_SR; 	// Status Register
  AT91_REG	   UART1_RHR; 	// Receive Holding Register
  AT91_REG	   UART1_THR; 	// Transmit Holding Register
  AT91_REG	   UART1_BRGR; 	// Baud Rate Generator Register
  AT91_REG	   Reserved25[55];
  AT91_REG	   UART1_PDC[5];
  AT91_REG	   Reserved26[7]; 

  AT91_REG         EEFC_FMR; //EEFC Flash Mode Register
  AT91_REG         EEFC_FCR; //EEFC Flash Command Register
  AT91_REG         EEFC_FSR; //EEFC Flash Status Register
  AT91_REG         EEFC_FRR; //EEFC Flash Result Register
  AT91_REG         Reserved27[124];

  AT91_REG         Reserved28[128];

  AT91_REG	 PIOA_PER; 	// PIO Enable Register
  AT91_REG	 PIOA_PDR; 	// PIO Disable Register
  AT91_REG	 PIOA_PSR; 	// PIO Status Register
  AT91_REG	 Reserved29[1]; 	// 
  AT91_REG	 PIOA_OER; 	// Output Enable Register
  AT91_REG	 PIOA_ODR; 	// Output Disable Registerr
  AT91_REG	 PIOA_OSR; 	// Output Status Register
  AT91_REG	 Reserved30[1]; 	// 
  AT91_REG	 PIOA_IFER; 	// Input Filter Enable Register
  AT91_REG	 PIOA_IFDR; 	// Input Filter Disable Register
  AT91_REG	 PIOA_IFSR; 	// Input Filter Status Register
  AT91_REG	 Reserved31[1]; 	// 
  AT91_REG	 PIOA_SODR; 	// Set Output Data Register
  AT91_REG	 PIOA_CODR; 	// Clear Output Data Register
  AT91_REG	 PIOA_ODSR; 	// Output Data Status Register
  AT91_REG	 PIOA_PDSR; 	// Pin Data Status Register
  AT91_REG	 PIOA_IER; 	// Interrupt Enable Register
  AT91_REG	 PIOA_IDR; 	// Interrupt Disable Register
  AT91_REG	 PIOA_IMR; 	// Interrupt Mask Register
  AT91_REG	 PIOA_ISR; 	// Interrupt Status Register
  AT91_REG	 PIOA_MDER; 	// Multi-driver Enable Register
  AT91_REG	 PIOA_MDDR; 	// Multi-driver Disable Register
  AT91_REG	 PIOA_MDSR; 	// Multi-driver Status Register
  AT91_REG	 Reserved32[1]; 	// 
  AT91_REG	 PIOA_PPUDR; 	// Pull-up Disable Register
  AT91_REG	 PIOA_PPUER; 	// Pull-up Enable Register
  AT91_REG	 PIOA_PPUSR; 	// Pull-up Status Register
  AT91_REG	 Reserved33[1]; 	// 
  AT91_REG	 PIOA_ASR; 	// Select A Register
  AT91_REG	 PIOA_BSR; 	// Select B Register
  AT91_REG	 PIOA_ABSR; 	// AB Select Status Register
  AT91_REG	 Reserved34[9]; 	// 
  AT91_REG	 PIOA_OWER; 	// Output Write Enable Register
  AT91_REG	 PIOA_OWDR; 	// Output Write Disable Register
  AT91_REG	 PIOA_OWSR; 	// Output Write Status Register
  AT91_REG	 Reserved35[93]; 	// 
  AT91_REG	 PIOB_PER; 	// PIO Enable Register
  AT91_REG	 PIOB_PDR; 	// PIO Disable Register
  AT91_REG	 PIOB_PSR; 	// PIO Status Register
  AT91_REG	 Reserved36[1]; 	// 
  AT91_REG	 PIOB_OER; 	// Output Enable Register
  AT91_REG	 PIOB_ODR; 	// Output Disable Registerr
  AT91_REG	 PIOB_OSR; 	// Output Status Register
  AT91_REG	 Reserved37[1]; 	// 
  AT91_REG	 PIOB_IFER; 	// Input Filter Enable Register
  AT91_REG	 PIOB_IFDR; 	// Input Filter Disable Register
  AT91_REG	 PIOB_IFSR; 	// Input Filter Status Register
  AT91_REG	 Reserved38[1]; 	// 
  AT91_REG	 PIOB_SODR; 	// Set Output Data Register
  AT91_REG	 PIOB_CODR; 	// Clear Output Data Register
  AT91_REG	 PIOB_ODSR; 	// Output Data Status Register
  AT91_REG	 PIOB_PDSR; 	// Pin Data Status Register
  AT91_REG	 PIOB_IER; 	// Interrupt Enable Register
  AT91_REG	 PIOB_IDR; 	// Interrupt Disable Register
  AT91_REG	 PIOB_IMR; 	// Interrupt Mask Register
  AT91_REG	 PIOB_ISR; 	// Interrupt Status Register
  AT91_REG	 PIOB_MDER; 	// Multi-driver Enable Register
  AT91_REG	 PIOB_MDDR; 	// Multi-driver Disable Register
  AT91_REG	 PIOB_MDSR; 	// Multi-driver Status Register
  AT91_REG	 Reserved39[1]; 	// 
  AT91_REG	 PIOB_PPUDR; 	// Pull-up Disable Register
  AT91_REG	 PIOB_PPUER; 	// Pull-up Enable Register
  AT91_REG	 PIOB_PPUSR; 	// Pull-up Status Register
  AT91_REG	 Reserved40[1]; 	// 
  AT91_REG	 PIOB_ASR; 	// Select A Register
  AT91_REG	 PIOB_BSR; 	// Select B Register
  AT91_REG	 PIOB_ABSR; 	// AB Select Status Register
  AT91_REG	 Reserved41[9]; 	// 
  AT91_REG	 PIOB_OWER; 	// Output Write Enable Register
  AT91_REG	 PIOB_OWDR; 	// Output Write Disable Register
  AT91_REG	 PIOB_OWSR; 	// Output Write Status Register
  AT91_REG	 Reserved42[93]; 	// 
  AT91_REG	 PIOC_PER; 	// PIO Enable Register
  AT91_REG	 PIOC_PDR; 	// PIO Disable Register
  AT91_REG	 PIOC_PSR; 	// PIO Status Register
  AT91_REG	 Reserved43[1]; 	// 
  AT91_REG	 PIOC_OER; 	// Output Enable Register
  AT91_REG	 PIOC_ODR; 	// Output Disable Registerr
  AT91_REG	 PIOC_OSR; 	// Output Status Register
  AT91_REG	 Reserved44[1]; 	// 
  AT91_REG	 PIOC_IFER; 	// Input Filter Enable Register
  AT91_REG	 PIOC_IFDR; 	// Input Filter Disable Register
  AT91_REG	 PIOC_IFSR; 	// Input Filter Status Register
  AT91_REG	 Reserved45[1]; 	// 
  AT91_REG	 PIOC_SODR; 	// Set Output Data Register
  AT91_REG	 PIOC_CODR; 	// Clear Output Data Register
  AT91_REG	 PIOC_ODSR; 	// Output Data Status Register
  AT91_REG	 PIOC_PDSR; 	// Pin Data Status Register
  AT91_REG	 PIOC_IER; 	// Interrupt Enable Register
  AT91_REG	 PIOC_IDR; 	// Interrupt Disable Register
  AT91_REG	 PIOC_IMR; 	// Interrupt Mask Register
  AT91_REG	 PIOC_ISR; 	// Interrupt Status Register
  AT91_REG	 PIOC_MDER; 	// Multi-driver Enable Register
  AT91_REG	 PIOC_MDDR; 	// Multi-driver Disable Register
  AT91_REG	 PIOC_MDSR; 	// Multi-driver Status Register
  AT91_REG	 Reserved46[1]; 	// 
  AT91_REG	 PIOC_PPUDR; 	// Pull-up Disable Register
  AT91_REG	 PIOC_PPUER; 	// Pull-up Enable Register
  AT91_REG	 PIOC_PPUSR; 	// Pull-up Status Register
  AT91_REG	 Reserved47[1]; 	// 
  AT91_REG	 PIOC_ASR; 	// Select A Register
  AT91_REG	 PIOC_BSR; 	// Select B Register
  AT91_REG	 PIOC_ABSR; 	// AB Select Status Register
  AT91_REG	 Reserved48[9]; 	// 
  AT91_REG	 PIOC_OWER; 	// Output Write Enable Register
  AT91_REG	 PIOC_OWDR; 	// Output Write Disable Register
  AT91_REG	 PIOC_OWSR; 	// Output Write Status Register
  AT91_REG	 Reserved49[93]; 	// 

  AT91_REG	 RSTC_RCR; 	// Reset Control Register
  AT91_REG	 RSTC_RSR; 	// Reset Status Register
  AT91_REG	 RSTC_RMR; 	// Reset Mode Register
  AT91_REG	 Reserved50[1]; 	// 

  AT91_REG       SUPC_CR;
  AT91_REG       SUPC_SMMR;
  AT91_REG       SUPC_MR;
  AT91_REG       SUPC_WUMR;
  AT91_REG       SUPC_WUIR;
  AT91_REG       SUPC_SR;
  AT91_REG	 Reserved51[2]; 	//

  AT91_REG	 RTTC_RTMR; 	// Real-time Mode Register
  AT91_REG	 RTTC_RTAR; 	// Real-time Alarm Register
  AT91_REG	 RTTC_RTVR; 	// Real-time Value Register
  AT91_REG	 RTTC_RTSR; 	// Real-time Status Register

  AT91_REG	 WDTC_WDCR; 	// Watchdog Control Register
  AT91_REG	 WDTC_WDMR; 	// Watchdog Mode Register
  AT91_REG	 WDTC_WDSR; 	// Watchdog Status Register
  AT91_REG	 Reserved52[1]; 	// 

  AT91_REG       RTCC_CR;
  AT91_REG       RTCC_MR;
  AT91_REG       RTCC_TIMR;
  AT91_REG       RTCC_CALR;
  AT91_REG       RTCC_TIMALR;
  AT91_REG       RTCC_CALALR;
  AT91_REG       RTCC_SR;
  AT91_REG       RTCC_SCCR;
  AT91_REG       RTCC_IER;
  AT91_REG       RTCC_IDR;
  AT91_REG       RTCC_IMR;
  AT91_REG       RTCC_VER;
  AT91_REG	 Reserved53[52]; 	// 

  AT91_REG         SYS_GPBR[8];
  AT91_REG         Reserved54[84];

  AT91_REG         Reserved55[1024];

} AT91S_SYS, *AT91PS_SYS;


// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Static Memory Controller Interface
// *****************************************************************************
typedef struct _AT91S_SMC {
  AT91_REG         SMC_SETUP0;
  AT91_REG         SMC_PULSE0;
  AT91_REG         SMC_CYCLE0;
  AT91_REG         SMC_MODE0;
  AT91_REG         SMC_SETUP1;
  AT91_REG         SMC_PULSE1;
  AT91_REG         SMC_CYCLE1;
  AT91_REG         SMC_MODE1;
  AT91_REG         SMC_SETUP2;
  AT91_REG         SMC_PULSE2;
  AT91_REG         SMC_CYCLE2;
  AT91_REG         SMC_MODE2;
  AT91_REG         SMC_SETUP3;
  AT91_REG         SMC_PULSE3;
  AT91_REG         SMC_CYCLE3;
  AT91_REG         SMC_MODE3;
  AT91_REG         SMC_SETUP4;
  AT91_REG         SMC_PULSE4;
  AT91_REG         SMC_CYCLE4;
  AT91_REG         SMC_MODE4;
  AT91_REG	   Reserved0[12]; 	//
  AT91_REG         SMC_OCMS;
  AT91_REG         SMC_KEY1;
  AT91_REG         SMC_KEY2;
  AT91_REG	   Reserved1[22]; 	//
  AT91_REG	   SMC_WPMR;
  AT91_REG         SMC_WPSR;
  AT91_REG	   Reserved2[69]; 	//
} AT91S_SMC, *AT91PS_SMC;

// -------- SMC_RCR : (SMC Offset: 0x0) SMC Remap Control Register -------- 
#define AT91C_SMC_NWE_SETUP(nwe_setup)       ((unsigned int) (((nwe_setup << 7)& 0x20) + (nwe_setup & 0x1F)) <<  0) // (SMC) NWE Setup Length
// -------- SMC_ASR : (SMC Offset: 0x4) SMC Abort Status Register -------- 
#define AT91C_SMC_NCS_WR_SETUP(ncswr_setup)       ((unsigned int) (((ncswr_setup << 7)& 0x20) + (ncswr_setup & 0x1F)) <<  8) // (SMC) NCS Setup Length in WRITE Access
#define AT91C_SMC_NRD_SETUP(nrd_setup)       ((unsigned int) (((nrd_setup << 7)& 0x20) + (nrd_setup & 0x1F)) <<  16) // (SMC) NRD Setup Length
#define AT91C_SMC_NCS_RD_SETUP(ncsrd_setup)  ((unsigned int) (((ncsrd_steup << 7)& 0x20) + (ncsrd_setup & 0x1F)) << 24) // (SMC) NCS Setup Length in READ Access
#define AT91C_SMC_NWE_PULSE(nwe_pulse)       ((unsigned int) (((nwe_pulse << 8)& 0x40) + (nwe_pulse & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_NCS_WR_PULSE(ncswr_pulse)  ((unsigned int) (((ncswr_pulse << 8)& 0x40) + (ncswr_pulse & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_NRD_PULSE(nrd_pulse)       ((unsigned int) (((nrd_pulse << 8)& 0x40) + (nrd_pulse & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_NCS_RD_PULSE(ncsrd_pulse)  ((unsigned int) (((ncsrd_pulse << 8)& 0x40) + (ncsrd_pulse & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_NWE_CYCLE(nwe_cycle)       ((unsigned int) (((nwe_cycle << 8)& 0x40) + (nwe_cycle & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_NRD_CYCLE(nwe_cycle)       ((unsigned int) (((nrd_cycle << 8)& 0x40) + (nrd_cycle & 0x3F)) <<  0) // (SMC) 
#define AT91C_SMC_READ_MODE         ((unsigned int) 0x1 <<  0) // (SMC) 
#define AT91C_SMC_WRITE_MODE        ((unsigned int) 0x1 <<  1) // (SMC) 
#define AT91C_SMC_ABTTYP            ((unsigned int) 0x3 << 10) // (SMC)
#define AT91C_SMC_EXNW_MODE_DISABLE ((unsigned int) 0x0 << 4) // (SMC) 
#define AT91C_SMC_EXNW_MODE_FROZEN  ((unsigned int) 0x10 << 4) // (SMC)
#define AT91C_SMC_EXNW_MODE_READY   ((unsigned int) 0x11 << 4) // (SMC) 
#define AT91C_SMC_DBW8_BIT          ((unsigned int) 0x0 << 12) // (SMC) 
#define AT91C_SMC_DBW16_BIT         ((unsigned int) 0x1 << 12) // (SMC) 
#define AT91C_SMC_DBW32_BIT         ((unsigned int) 0x2 << 12) // (SMC)
#define AT91C_SMC_TDF_CYCLES(tdf_cycle)        ((unsigned int) (tdf_cycle) << 16) // (SMC)   
#define AT91C_SMC_TDF_MODE          ((unsigned int) 0x1 << 20) // (SMC)
#define AT91C_SMC_PMEN              ((unsigned int) 0x1 << 24) // (SMC)
#define AT91C_SMC_PS4_BYTE          ((unsigned int) 0x0 << 28) // (SMC)
#define AT91C_SMC_PS8_BYTE          ((unsigned int) 0x1 << 28) // (SMC)
#define AT91C_SMC_PS16_BYTE         ((unsigned int) 0x2 << 28) // (SMC)
#define AT91C_SMC_PS32_BYTE         ((unsigned int) 0x3 << 28) // (SMC)
#define AT91C_SMC_SMSE              ((unsigned int) 0x1 << 0) // (SMC) Static Memory Controller Scrambling Enable
#define AT91C_SMC_CSSE(num_cs)      ((unsigned int) 0x1 << (16 + num_cs)) // (SMC) Chip Select (x = 0 to 3) Scrambling Enable
#define AT91C_SMC_KEY(key)          ((unsigned int) key << 0) // (SMC)
#define AT91C_SMC_WPEN              ((unsigned int) 0x1 <<  0) // (SMC)
#define AT91C_SMC_WPKEY             ((unsigned int) 0x534D43 << 8) // (SMC) 
#define AT91C_SMC_WPVS              ((unsigned int) 0x1 << 0) // (SMC) 
#define AT91C_SMC_WPVSRC(wpvsrc)    ((unsigned int) wpvsrc << 8) // (SMC) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Bus Matrix
// *****************************************************************************
typedef struct _AT91S_MATRIX {
  AT91_REG         MATRIX_MCFG0;
  AT91_REG         MATRIX_MCFG1;
  AT91_REG         MATRIX_MCFG2;
  AT91_REG         MATRIX_MCFG3;
  AT91_REG	   Reserved0[12]; 	//
  AT91_REG	   MATRIX_SCFG0;
  AT91_REG	   MATRIX_SCFG1;
  AT91_REG	   MATRIX_SCFG2;
  AT91_REG	   MATRIX_SCFG3;
  AT91_REG	   MATRIX_SCFG4;
  AT91_REG	   Reserved1[11]; 	//
  AT91_REG	   MATRIX_PRAS0;
  AT91_REG	   Reserved2[1]; 	//
  AT91_REG	   MATRIX_PRAS1;
  AT91_REG	   Reserved3[1]; 	//
  AT91_REG	   MATRIX_PRAS2;
  AT91_REG	   Reserved4[1]; 	//
  AT91_REG	   MATRIX_PRAS3;
  AT91_REG	   Reserved5[1]; 	//
  AT91_REG	   MATRIX_PRAS4;
  AT91_REG	   Reserved6[28]; 	//
  AT91_REG	   CCFG_SYSIO;
  AT91_REG	   Reserved7[1]; 	//
  AT91_REG	   CCFG_SMCNFCS;
  AT91_REG	   Reserved8[49]; 	//
  AT91_REG	   MATRIX_WPMR;
  AT91_REG	   MATRIX_WPSR;
  AT91_REG	   Reserved9[5]; 	//
} AT91S_MATRIX, *AT91PS_MATRIX;

#define AT91C_MATRIX_ULBT_INFINITE       ((unsigned int) 0x0 <<  0) // (MATRIX)
#define AT91C_MATRIX_ULBT_SINGLE         ((unsigned int) 0x1 <<  0) // (MATRIX)
#define AT91C_MATRIX_ULBT_4BEATBURST     ((unsigned int) 0x2 <<  0) // (MATRIX)
#define AT91C_MATRIX_ULBT_8BEATBURST     ((unsigned int) 0x3 <<  0) // (MATRIX)
#define AT91C_MATRIX_ULBT_16BEATBURST    ((unsigned int) 0x4 <<  0) // (MATRIX)
#define AT91C_MATRIX_SLOT_CYCLE(slotcycle) ((unsigned int) slotcycle <<  0)
#define AT91C_MATRIX_DEFMSTR_TYPE_NO     ((unsigned int) 0x0 <<  16) // (MATRIX)
#define AT91C_MATRIX_DEFMSTR_TYPE_LAST   ((unsigned int) 0x1 <<  16) // (MATRIX)
#define AT91C_MATRIX_DEFMSTR_TYPE_FIXED  ((unsigned int) 0x2 <<  16) // (MATRIX)
#define AT91C_MATRIX_FIXED_DEFMSTR(master)  ((unsigned int) master <<  18) // (MATRIX)
#define AT91C_MATRIX_ARBT_ROUNDROBIN     ((unsigned int) 0x0 <<  0) // (MATRIX)
#define AT91C_MATRIX_ARBT_FIXED          ((unsigned int) 0x1 <<  0) // (MATRIX)
#define AT91C_MATRIX_M0PR(pras)          ((unsigned int) pras <<  0) // (MATRIX)
#define AT91C_MATRIX_M1PR(pras)          ((unsigned int) pras <<  4) // (MATRIX)
#define AT91C_MATRIX_M2PR(pras)          ((unsigned int) pras <<  8) // (MATRIX)
#define AT91C_MATRIX_M3PR(pras)          ((unsigned int) pras << 12) // (MATRIX)
#define AT91C_MATRIX_M4PR(pras)          ((unsigned int) pras << 16) // (MATRIX)

#define AT91C_MATRIX_SYSIO4              ((unsigned int) 0x1 <<  4) // (MATRIX)
#define AT91C_MATRIX_SYSIO5              ((unsigned int) 0x1 <<  5) // (MATRIX)
#define AT91C_MATRIX_SYSIO6              ((unsigned int) 0x1 <<  6) // (MATRIX)
#define AT91C_MATRIX_SYSIO7              ((unsigned int) 0x1 <<  7) // (MATRIX)
#define AT91C_MATRIX_SYSIO10             ((unsigned int) 0x1 << 10) // (MATRIX)
#define AT91C_MATRIX_SYSIO11             ((unsigned int) 0x1 << 11) // (MATRIX)
#define AT91C_MATRIX_SYSIO12             ((unsigned int) 0x1 << 12) // (MATRIX)

#define AT91C_MATRIX_SMC_NFCS(num)       ((unsigned int) 0x1 << num) // (MATRIX)
#define AT91C_MATRIX_WPEN                ((unsigned int) 0x1 <<  0) // (MATRIX)
#define AT91C_MATRIX_WPKEY               ((unsigned int) 0x4D4154 << 8) // (MATRIX) 
#define AT91C_MATRIX_WPVS              ((unsigned int) 0x1 << 0) // (MATRIX) 
#define AT91C_MATRIX_WPVSRC            ((unsigned int) 0x4D4154 << 8) // (MATRIX) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Power Management Controler
// *****************************************************************************
typedef struct _AT91S_PMC {
	AT91_REG	 PMC_SCER; 	// System Clock Enable Register
	AT91_REG	 PMC_SCDR; 	// System Clock Disable Register
	AT91_REG	 PMC_SCSR; 	// System Clock Status Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PMC_PCER0; 	// Peripheral Clock Enable Register
	AT91_REG	 PMC_PCDR0; 	// Peripheral Clock Disable Register
	AT91_REG	 PMC_PCSR0; 	// Peripheral Clock Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 CKGR_MOR; 	// Main Oscillator Register
	AT91_REG	 CKGR_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 CKGR_PLLAR; 	// PLLA Register 
	AT91_REG	 CKGR_PLLBR; 	// PLLB Register
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved3[1]; 	// 
	AT91_REG	 PMC_USB; 	// USB Clock Register
	AT91_REG	 Reserved4[1]; 	// 
	AT91_REG	 PMC_PCKR[3]; 	// Programmable Clock Register
	AT91_REG	 Reserved5[5]; 	// 
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PMC_FSMR; 	// Fast Startup Mode Register
	AT91_REG	 PMC_FSPR; 	// Fast Startup Polarity Register
	AT91_REG	 PMC_FOCR; 	// Fault Output Clear Register
	AT91_REG	 Reserved6[26];	//
	AT91_REG	 PMC_WPMR; 	// Write Protect Mode Register
	AT91_REG	 PMC_WPSR; 	// Write Protect Status Register
	AT91_REG	 Reserved7[5];	//
	AT91_REG	 PMC_PCER1; 	// Peripheral Clock Enable Register
	AT91_REG	 PMC_PCDR1; 	// Peripheral Clock Disable Register
	AT91_REG	 PMC_PCSR1; 	// Peripheral Clock Status Register
	AT91_REG	 Reserved8[1]; 	// 
	AT91_REG	 PMC_OCR; 	// Oscillator Calibration Register       
} AT91S_PMC, *AT91PS_PMC;

// -------- PMC_SCER : (PMC Offset: 0x0) System Clock Enable Register -------- 
#define AT91C_PMC_PCK         ((unsigned int) 0x1 <<  0) // (PMC) Processor Clock
#define AT91C_PMC_UDP         ((unsigned int) 0x1 <<  7) // (PMC) USB Device Port Clock
#define AT91C_PMC_SCER_PCK0        ((unsigned int) 0x1 <<  8) // (PMC) Programmable Clock Output
#define AT91C_PMC_SCER_PCK1        ((unsigned int) 0x1 <<  9) // (PMC) Programmable Clock Output
#define AT91C_PMC_SCER_PCK2        ((unsigned int) 0x1 << 10) // (PMC) Programmable Clock Output
// -------- PMC_SCDR : (PMC Offset: 0x4) System Clock Disable Register -------- 
// -------- PMC_SCSR : (PMC Offset: 0x8) System Clock Status Register -------- 
// -------- CKGR_MCFR : (PMC Offset: 0x24) Main Clock Frequency Register -------- 
// -------- CKGR_PLLAR : (PMC Offset: 0x28) PLLA  Register -------- 
// -------- CKGR_PLLBR : (PMC Offset: 0x2c) PLLB  Register --------
// -------- CKGR_MOR : (CKGR Offset: 0x20) Main Oscillator Register -------- 
#define AT91C_CKGR_MOSCEN     ((unsigned int) 0x1 <<  0) // (CKGR) Main Oscillator Enable
#define AT91C_CKGR_OSCBYPASS  ((unsigned int) 0x1 <<  1) // (CKGR) Main Oscillator Bypass
#define AT91C_CKGR_OSCOUNT    ((unsigned int) 0xFF <<  8) // (CKGR) Main Oscillator Start-up Time
// -------- CKGR_MCFR : (CKGR Offset: 0x24) Main Clock Frequency Register -------- 
#define AT91C_CKGR_MAINF      ((unsigned int) 0xFFFF <<  0) // (CKGR) Main Clock Frequency
#define AT91C_CKGR_MAINRDY    ((unsigned int) 0x1 << 16) // (CKGR) Main Clock Ready
// -------- CKGR_PLLAR : (CKGR Offset: 0x28) PLLA Register -------- 
#define AT91C_CKGR_DIVA        ((unsigned int) 0xFF <<  0) // (CKGR) Divider Selected
#define 	AT91C_CKGR_DIVA_0                    ((unsigned int) 0x0) // (CKGR) Divider output is 0
#define 	AT91C_CKGR_DIVA_BYPASS               ((unsigned int) 0x1) // (CKGR) Divider is bypassed
#define AT91C_CKGR_PLLACOUNT   ((unsigned int) 0x3F <<  8) // (CKGR) PLLA Counter
#define AT91C_CKGR_OUTA        ((unsigned int) 0x3 << 14) // (CKGR) PLLA Output Frequency Range
#define 	AT91C_CKGR_OUTA_0                    ((unsigned int) 0x0 << 14) // (CKGR) Please refer to the PLLA datasheet
#define 	AT91C_CKGR_OUTA_1                    ((unsigned int) 0x1 << 14) // (CKGR) Please refer to the PLLA datasheet
#define 	AT91C_CKGR_OUTA_2                    ((unsigned int) 0x2 << 14) // (CKGR) Please refer to the PLLA datasheet
#define 	AT91C_CKGR_OUTA_3                    ((unsigned int) 0x3 << 14) // (CKGR) Please refer to the PLLA datasheet
#define AT91C_CKGR_MULA        ((unsigned int) 0x7FF << 16) // (CKGR) PLLA Multiplier
#define 	AT91C_CKGR_ONE                    ((unsigned int) 0x1 << 29) // (CKGR) Set to 1 when configuring

// -------- CKGR_PLLBR : (CKGR Offset: 0x2c) PLL B Register -------- 
#define AT91C_CKGR_DIVB        ((unsigned int) 0xFF <<  0) // (CKGR) Divider Selected
#define 	AT91C_CKGR_DIVB_0                    ((unsigned int) 0x0) // (CKGR) Divider output is 0
#define 	AT91C_CKGR_DIVB_BYPASS               ((unsigned int) 0x1) // (CKGR) Divider is bypassed
#define AT91C_CKGR_PLLBCOUNT   ((unsigned int) 0x3F <<  8) // (CKGR) PLLB Counter
#define AT91C_CKGR_OUTB        ((unsigned int) 0x3 << 14) // (CKGR) PLLB Output Frequency Range
#define 	AT91C_CKGR_OUTB_0                    ((unsigned int) 0x0 << 14) // (CKGR) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_1                    ((unsigned int) 0x1 << 14) // (CKGR) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_2                    ((unsigned int) 0x2 << 14) // (CKGR) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_3                    ((unsigned int) 0x3 << 14) // (CKGR) Please refer to the PLLB datasheet
#define AT91C_CKGR_MULB        ((unsigned int) 0x7FF << 16) // (CKGR) PLL Multiplier

// -------- PMC_MCKR : (PMC Offset: 0x30) Master Clock Register -------- 
#define AT91C_PMC_CSS         ((unsigned int) 0x3 <<  0) // (PMC) Programmable Clock Selection
#define 	AT91C_PMC_CSS_SLOW_CLK             ((unsigned int) 0x0) // (PMC) Slow Clock is selected
#define 	AT91C_PMC_CSS_MAIN_CLK             ((unsigned int) 0x1) // (PMC) Main Clock is selected
#define 	AT91C_PMC_CSS_PLLA_CLK              ((unsigned int) 0x2) // (PMC) Clock from PLLA is selected
#define 	AT91C_PMC_CSS_PLLB_CLK              ((unsigned int) 0x3) // (PMC) Clock from PLLB is selected

#define         AT91C_PMC_PRES_CLK3                 ((unsigned int) 0x7 <<  4) // (PMC) Selected clock divided by 3
#define 	AT91C_PMC_PRES                  ((unsigned int) 0x0 <<  4) // (PMC) Selected clock
#define 	AT91C_PMC_PRES_CLK_2                ((unsigned int) 0x1 <<  4) // (PMC) Selected clock divided by 2
#define 	AT91C_PMC_PRES_CLK_4                ((unsigned int) 0x2 <<  4) // (PMC) Selected clock divided by 4
#define 	AT91C_PMC_PRES_CLK_8                ((unsigned int) 0x3 <<  4) // (PMC) Selected clock divided by 8
#define 	AT91C_PMC_PRES_CLK_16               ((unsigned int) 0x4 <<  4) // (PMC) Selected clock divided by 16
#define 	AT91C_PMC_PRES_CLK_32               ((unsigned int) 0x5 <<  4) // (PMC) Selected clock divided by 32
#define 	AT91C_PMC_PRES_CLK_64               ((unsigned int) 0x6 <<  4) // (PMC) Selected clock divided by 64
// -------- PMC_PCKR : (PMC Offset: 0x40) Programmable Clock Register -------- 
// -------- PMC_IER : (PMC Offset: 0x60) PMC Interrupt Enable Register -------- 
#define AT91C_PMC_MOSCS       ((unsigned int) 0x1 <<  0) // (PMC) MOSC Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKA       ((unsigned int) 0x1 <<  1) // (PMC) PLLA Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKB       ((unsigned int) 0x1 <<  2) // (PMC) PLLB Status/Enable/Disable/Mask
#define AT91C_PMC_MCKRDY      ((unsigned int) 0x1 <<  3) // (PMC) MCK_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_PCK0RDY     ((unsigned int) 0x1 <<  8) // (PMC) PCK0_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_PCK1RDY     ((unsigned int) 0x1 <<  9) // (PMC) PCK1_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_PCK2RDY     ((unsigned int) 0x1 << 10) // (PMC) PCK2_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_MOSCSELS    ((unsigned int) 0x1 << 16) // (PMC) MOSCSELS_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_MOSCRCS     ((unsigned int) 0x1 << 17) // (PMC) MOSCRCS_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_CFDEV       ((unsigned int) 0x1 << 18) // (PMC) CFDEV_RDY Status/Enable/Disable/Mask
// -------- PMC_IDR : (PMC Offset: 0x64) PMC Interrupt Disable Register -------- 
// -------- PMC_SR : (PMC Offset: 0x68) PMC Status Register -------- 
// -------- PMC_IMR : (PMC Offset: 0x6c) PMC Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR UART
// *****************************************************************************
typedef struct _AT91S_UART {
  AT91_REG	   UART_CR; 	// Control Register
  AT91_REG	   UART_MR; 	// Mode Register
  AT91_REG	   UART_IER; 	// Interrupt Enable Register
  AT91_REG	   UART_IDR; 	// Interrupt Disable Register
  AT91_REG	   UART_IMR; 	// Interrupt Mask Register
  AT91_REG	   UART_SR; 	// Status Register
  AT91_REG	   UART_RHR; 	// Receive Holding Register
  AT91_REG	   UART_THR; 	// Transmit Holding Register
  AT91_REG	   UART_BRGR; 	// Baud Rate Generator Register
  AT91_REG	   Reserved1[55];
  AT91_REG	   UART_PDC[5];
  AT91_REG	   Reserved2[7]; 
} AT91S_UART, *AT91PS_UART;

#define AT91C_UART_RSTRX       ((unsigned int) 0x1 << 2) // (UART_CR)
#define AT91C_UART_RSTTX       ((unsigned int) 0x1 << 3) // (UART_CR)
#define AT91C_UART_RXEN        ((unsigned int) 0x1 << 4) // (UART_CR)
#define AT91C_UART_RXDIS       ((unsigned int) 0x1 << 5) // (UART_CR)
#define AT91C_UART_TXEN        ((unsigned int) 0x1 << 6) // (UART_CR)
#define AT91C_UART_TXDIS       ((unsigned int) 0x1 << 7) // (UART_CR)
#define AT91C_UART_RSTSTA      ((unsigned int) 0x1 << 8) // (UART_CR)

#define AT91C_UART_PAR_EVEN    ((unsigned int) 0x0 << 9) // (UART_MR)
#define AT91C_UART_PAR_ODD     ((unsigned int) 0x1 << 9) // (UART_MR)
#define AT91C_UART_PAR_SPACE   ((unsigned int) 0x2 << 9) // (UART_MR)
#define AT91C_UART_PAR_MARK    ((unsigned int) 0x3 << 9) // (UART_MR)
#define AT91C_UART_PAR_NO      ((unsigned int) 0x4 << 9) // (UART_MR)
#define AT91C_UART_CHMODE_NORMAL    ((unsigned int) 0x0 << 14) // (UART_MR)
#define AT91C_UART_CHMODE_AUTOMATIC ((unsigned int) 0x1 << 14) // (UART_MR)
#define AT91C_UART_CHMODE_LOCAL     ((unsigned int) 0x2 << 14) // (UART_MR)
#define AT91C_UART_CHMODE_REMOTE    ((unsigned int) 0x3 << 14) // (UART_MR)
//IER IDR IMR SR
#define AT91C_UART_RXRDY    ((unsigned int) 0x1 << 0) // 
#define AT91C_UART_TXRDY    ((unsigned int) 0x1 << 1) //
#define AT91C_UART_ENDRX    ((unsigned int) 0x1 << 3) //
#define AT91C_UART_ENDTX    ((unsigned int) 0x1 << 4) //
#define AT91C_UART_OVRE     ((unsigned int) 0x1 << 5) //
#define AT91C_UART_FRAME    ((unsigned int) 0x1 << 6) //
#define AT91C_UART_PARE     ((unsigned int) 0x1 << 7) //
#define AT91C_UART_TXEMPTY  ((unsigned int) 0x1 << 9) //
#define AT91C_UART_TXBUFE   ((unsigned int) 0x1 << 11) //
#define AT91C_UART_RXBUFF   ((unsigned int) 0x1 << 12) //

#define AT91C_UART_CD(cd)   ((unsigned int) cd << 0) // (UART_BRGR)

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Peripheral DMA Controller
// *****************************************************************************
typedef struct _AT91S_CHIPID {
  AT91_REG         CHIPID_CIDR;
  AT91_REG         CHIPID_EXID;
  AT91_REG	   Reserved23[48];
} AT91S_CHIPID, *AT91PS_CHIPID;

#define AT91C_CHIPID_EPROC_ARM946ES  ((unsigned int) 0x1 <<  5) // (CHIPID_CIDR)
#define AT91C_CHIPID_EPROC_ARM7TDMI  ((unsigned int) 0x2 <<  5) // (CHIPID_CIDR)
#define AT91C_CHIPID_EPROC_CM3       ((unsigned int) 0x3 <<  5) // (CHIPID_CIDR)
#define AT91C_CHIPID_EPROC_ARM920T   ((unsigned int) 0x4 <<  5) // (CHIPID_CIDR)
#define AT91C_CHIPID_EPROC_ARM926EJS ((unsigned int) 0x5 <<  5) // (CHIPID_CIDR) 
#define AT91C_CHIPID_EPROC_CA5       ((unsigned int) 0x6 <<  5) // (CHIPID_CIDR)

#define AT91C_CHIPID_NVPSIZ_NONE(n)     ((unsigned int) 0x0 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_8K(n)       ((unsigned int) 0x1 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_16K(n)      ((unsigned int) 0x2 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_32K(n)      ((unsigned int) 0x3 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_64K(n)     ((unsigned int) 0x5 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_128K(n)     ((unsigned int) 0x7 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_256K(n)     ((unsigned int) 0x9 << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_512K(n)     ((unsigned int) 0xA << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_1024K(n)    ((unsigned int) 0xC << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPSIZ_2048K(n)    ((unsigned int) 0xE << (8 + (n << 2))) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_48K   ((unsigned int) 0x0 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_1K    ((unsigned int) 0x1 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_2K    ((unsigned int) 0x2 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_6K    ((unsigned int) 0x3 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_112K  ((unsigned int) 0x4 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_4K    ((unsigned int) 0x5 << 16) // (CHIPID_CIDR) 
#define AT91C_CHIPID_SRAMSIZ_80K   ((unsigned int) 0x6 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_160K  ((unsigned int) 0x7 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_8K    ((unsigned int) 0x8 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_16K   ((unsigned int) 0x9 << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_32K   ((unsigned int) 0xA << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_64K   ((unsigned int) 0xB << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_128K  ((unsigned int) 0xC << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_256K  ((unsigned int) 0xD << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_96K   ((unsigned int) 0xE << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_SRAMSIZ_512K  ((unsigned int) 0xF << 16) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM9xx   ((unsigned int) 0x19 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM9XExx ((unsigned int) 0x29 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x34      ((unsigned int) 0x34 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_CAP7         ((unsigned int) 0x37 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_CAP9         ((unsigned int) 0x39 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_CAP11        ((unsigned int) 0x3B << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x40      ((unsigned int) 0x40 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x42      ((unsigned int) 0x42 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x55      ((unsigned int) 0x55 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7Axx  ((unsigned int) 0x60 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7AQxx ((unsigned int) 0x61 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x63      ((unsigned int) 0x63 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7Sxx  ((unsigned int) 0x70 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7XCxx ((unsigned int) 0x71 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7SExx ((unsigned int) 0x72 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7Lxx  ((unsigned int) 0x73 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7Xxx  ((unsigned int) 0x75 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91SAM7SLxx ((unsigned int) 0x76 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3UxC    ((unsigned int) 0x80 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3UxE    ((unsigned int) 0x81 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3AxC    ((unsigned int) 0x83 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3XxC    ((unsigned int) 0x84 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3XxE    ((unsigned int) 0x85 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3XxG    ((unsigned int) 0x86 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3SxA    ((unsigned int) 0x88 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3SxB    ((unsigned int) 0x89 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3SxC    ((unsigned int) 0x8A << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT91x92      ((unsigned int) 0x92 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3NxA    ((unsigned int) 0x93 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3NxB    ((unsigned int) 0x94 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3NxC    ((unsigned int) 0x95 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3DxA    ((unsigned int) 0x98 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3DxB    ((unsigned int) 0x99 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM3DxC    ((unsigned int) 0x9A << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_ATSAM5A      ((unsigned int) 0xA5 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_ARCH_AT75Cxx      ((unsigned int) 0xF0 << 20) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPTYP_ROM        ((unsigned int) 0x0 << 28) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPTYP_ROMLESS    ((unsigned int) 0x1 << 28) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPTYP_FLASH      ((unsigned int) 0x2 << 28) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPTYP_ROM_FLASH  ((unsigned int) 0x3 << 28) // (CHIPID_CIDR)
#define AT91C_CHIPID_NVPTYP_SRAM       ((unsigned int) 0x4 << 28) // (CHIPID_CIDR)
#define AT91C_CHIPID_EXT               ((unsigned int) 0x1 << 31) // (CHIPID_CIDR)

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR ENHANCED EMBEDDED FLASH CONTROLLER
// *****************************************************************************
typedef struct _AT91S_EEFC {
  AT91_REG         EEFC_FMR; //EEFC Flash Mode Register
  AT91_REG         EEFC_FCR; //EEFC Flash Command Register
  AT91_REG         EEFC_FSR; //EEFC Flash Status Register
  AT91_REG         EEFC_FRR; //EEFC Flash Result Register
  AT91_REG         Reserved26[124];
} AT91S_EEFC, *AT91PS_EEFC;

#define AT91C_EEFC_FRDY               ((unsigned int) 0x1 << 0) // (EEFC_FMR)Flash Mode Register
#define AT91C_EEFC_FAM                ((unsigned int) 0x1 << 24) // (EEFC_FMR)Flash Mode Register 
#define AT91C_EEFC_FCMD(fcr_fcmd)                ((unsigned int) fcr_fcmd << 0) // (EEFC_FCR)
#define AT91C_EEFC_FARG(fcr_farg)                ((unsigned int) fcr_farg << 8) // (EEFC_FCR)
#define AT91C_EEFC_FKEY                ((unsigned int) 0x5A << 24) // (EEFC_FCR)
#define AT91C_EEFC_FRDY                ((unsigned int) 0x1 << 0) // (EEFC_FSR)
#define AT91C_EEFC_FCMDE               ((unsigned int) 0x1 << 1) // (EEFC_FSR)
#define AT91C_EEFC_FLOCKE              ((unsigned int) 0x1 << 2) // (EEFC_FSR)

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Parallel Input Output Controler
// *****************************************************************************
typedef struct _AT91S_PIO {
	AT91_REG	 PIO_PER; 	// PIO Enable Register
	AT91_REG	 PIO_PDR; 	// PIO Disable Register
	AT91_REG	 PIO_PSR; 	// PIO Status Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PIO_OER; 	// Output Enable Register
	AT91_REG	 PIO_ODR; 	// Output Disable Registerr
	AT91_REG	 PIO_OSR; 	// Output Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 PIO_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIO_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIO_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 PIO_SODR; 	// Set Output Data Register
	AT91_REG	 PIO_CODR; 	// Clear Output Data Register
	AT91_REG	 PIO_ODSR; 	// Output Data Status Register
	AT91_REG	 PIO_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIO_IER; 	// Interrupt Enable Register
	AT91_REG	 PIO_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIO_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIO_ISR; 	// Interrupt Status Register
	AT91_REG	 PIO_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIO_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIO_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved3[1]; 	// 
	AT91_REG	 PIO_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIO_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIO_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved4[1]; 	// 
	AT91_REG	 PIO_ASR; 	// Select A Register
	AT91_REG	 PIO_BSR; 	// Select B Register
	AT91_REG	 PIO_ABSR; 	// AB Select Status Register
	AT91_REG	 Reserved5[9]; 	// 
	AT91_REG	 PIO_OWER; 	// Output Write Enable Register
	AT91_REG	 PIO_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIO_OWSR; 	// Output Write Status Register
} AT91S_PIO, *AT91PS_PIO;

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Reset Controller Interface
// *****************************************************************************
typedef struct _AT91S_RSTC {
	AT91_REG	 RSTC_RCR; 	// Reset Control Register
	AT91_REG	 RSTC_RSR; 	// Reset Status Register
	AT91_REG	 RSTC_RMR; 	// Reset Mode Register
} AT91S_RSTC, *AT91PS_RSTC;

// -------- RSTC_RCR : (RSTC Offset: 0x0) Reset Control Register -------- 
#define AT91C_RSTC_PROCRST    ((unsigned int) 0x1 <<  0) // (RSTC) Processor Reset
#define AT91C_RSTC_PERRST     ((unsigned int) 0x1 <<  2) // (RSTC) Peripheral Reset
#define AT91C_RSTC_EXTRST     ((unsigned int) 0x1 <<  3) // (RSTC) External Reset
#define AT91C_RSTC_KEY        ((unsigned int) 0xFF << 24) // (RSTC) Password
// -------- RSTC_RSR : (RSTC Offset: 0x4) Reset Status Register -------- 
#define AT91C_RSTC_URSTS      ((unsigned int) 0x1 <<  0) // (RSTC) User Reset Status
//#define AT91C_RSTC_BODSTS     ((unsigned int) 0x1 <<  1) // (RSTC) Brownout Detection Status
#define AT91C_RSTC_RSTTYP     ((unsigned int) 0x7 <<  8) // (RSTC) Reset Type
#define 	AT91C_RSTC_RSTTYP_POWERUP              ((unsigned int) 0x0 <<  8) // (RSTC) Power-up Reset. VDDCORE rising.
#define 	AT91C_RSTC_RSTTYP_WAKEUP               ((unsigned int) 0x1 <<  8) // (RSTC) WakeUp Reset. VDDCORE rising.
#define 	AT91C_RSTC_RSTTYP_WATCHDOG             ((unsigned int) 0x2 <<  8) // (RSTC) Watchdog Reset. Watchdog overflow occured.
#define 	AT91C_RSTC_RSTTYP_SOFTWARE             ((unsigned int) 0x3 <<  8) // (RSTC) Software Reset. Processor reset required by the software.
#define 	AT91C_RSTC_RSTTYP_USER                 ((unsigned int) 0x4 <<  8) // (RSTC) User Reset. NRST pin detected low.
  //#define 	AT91C_RSTC_RSTTYP_BROWNOUT             ((unsigned int) 0x5 <<  8) // (RSTC) Brownout Reset occured.
#define AT91C_RSTC_NRSTL      ((unsigned int) 0x1 << 16) // (RSTC) NRST pin level
#define AT91C_RSTC_SRCMP      ((unsigned int) 0x1 << 17) // (RSTC) Software Reset Command in Progress.
// -------- RSTC_RMR : (RSTC Offset: 0x8) Reset Mode Register -------- 
#define AT91C_RSTC_URSTEN     ((unsigned int) 0x1 <<  0) // (RSTC) User Reset Enable
#define AT91C_RSTC_URSTIEN    ((unsigned int) 0x1 <<  4) // (RSTC) User Reset Interrupt Enable
  //#define AT91C_RSTC_ERSTL      ((unsigned int) 0xF <<  8) // (RSTC) User Reset Length
  //#define AT91C_RSTC_BODIEN     ((unsigned int) 0x1 << 16) // (RSTC) Brownout Detection Interrupt Enable

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Supply Controller User Interface
// *****************************************************************************

typedef struct _AT91S_SUPC {
	AT91_REG	 SUPC_CR;
        AT91_REG	 SUPC_SMMR;     //supply monitor mode register
	AT91_REG	 SUPC_MR; 	// Voltage Regulator Mode Register
        AT91_REG	 SUPC_WUMR;     //wake up mode register
        AT91_REG	 SUPC_WUIR;     //wake up inputs register
        AT91_REG	 SUPC_SR;      
        AT91_REG	 Reserved[1];
} AT91S_SUPC, *AT91PS_SUPC;

// -------- SUPC_CR : (SUPC Offset: 0x0) Control Register -------- 
#define AT91C_SUPC_VROFF     ((unsigned int) 0x1 <<  2) // (SUPC) Voltage Regulator Off
#define AT91C_SUPC_XTALSEL   ((unsigned int) 0x1 <<  3) // (SUPC) crystal oscillator select
#define AT91C_SUPC_KEY       ((unsigned int) 0xA5 <<  24) // (SUPC) password

// -------- SUPC_SMMR : (SUPC Offset: 0x4) Controller Supply Monitor Mode Register -------- 
#define AT91C_SUPC_SMTH_1_9V      ((unsigned int) 0x0 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_0V      ((unsigned int) 0x1 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_1V      ((unsigned int) 0x2 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_2V      ((unsigned int) 0x3 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_3V      ((unsigned int) 0x4 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_4V      ((unsigned int) 0x5 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_5V      ((unsigned int) 0x6 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_6V      ((unsigned int) 0x7 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_7V      ((unsigned int) 0x8 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_8V      ((unsigned int) 0x9 <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_2_9V      ((unsigned int) 0xA <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_3_0V      ((unsigned int) 0xB <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_3_1V      ((unsigned int) 0xC <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_3_2V      ((unsigned int) 0xD <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_3_3V      ((unsigned int) 0xE <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMTH_3_4V      ((unsigned int) 0xF <<  0) // (SUPC) supply monitor threshold
#define AT91C_SUPC_SMSMPL_SMD     ((unsigned int) 0x0 <<  8) // (SUPC) supply monitor sampling period(disabled)
#define AT91C_SUPC_SMSMPL_CSM         ((unsigned int) 0x1 <<  8) // (SUPC) supply monitor sampling period(continuous supply monitor)
#define AT91C_SUPC_SMSMPL_32SLCK      ((unsigned int) 0x2 <<  8) // (SUPC) supply monitor sampling period
#define AT91C_SUPC_SMSMPL_256SLCK     ((unsigned int) 0x3 <<  8) // (SUPC) supply monitor sampling period
#define AT91C_SUPC_SMSMPL_2048SLCK    ((unsigned int) 0x4 <<  8) // (SUPC) supply monitor sampling period
#define AT91C_SUPC_SMRSTEN       ((unsigned int) 0x1 <<  12) // (SUPC) supply monitor reset enable
#define AT91C_SUPC_SMIEN         ((unsigned int) 0x1 <<  13) // (SUPC) supply monitor interrupt enable

// -------- SUPC_MR : (SUPC Offset: 0x8) Mode Register -------- 
#define AT91C_SUPC_BODRSTEN      ((unsigned int) 0x1 <<  12) // (SUPC) Brownout detector reset enable
#define AT91C_SUPC_BODDIS        ((unsigned int) 0x1 <<  13) // Brownout Detector Disable
#define AT91C_SUPC_ONREG         ((unsigned int) 0x1 <<  14) // (SUPC) Voltage Regulator enable
#define AT91C_SUPC_OSCBYPASS     ((unsigned int) 0x1 <<  20) // Oscillator Bypass
#define AT91C_SUPC_KEY           ((unsigned int) 0xA5 <<  24) // (SUPC) passwordKey

// -------- SUPC_WUMR : (SUPC Offset: 0x8) Wake up Mode Register -------- 
#define AT91C_SUPC_SMEN      ((unsigned int) 0x1 <<  1) // (SUPC) Supply Monitor Wake Up enable
#define AT91C_SUPC_RTTEN     ((unsigned int) 0x1 <<  2) // Real Time Timer Wake Up Enable
#define AT91C_SUPC_RTCEN     ((unsigned int) 0x1 <<  3) // (SUPC) Real Time Clock Wake Up Enable
#define AT91C_SUPC_WKUPDBC_IMMEDIATE     ((unsigned int) 0x0 <<  12) // Wake Up Inputs Debouncer Period
#define AT91C_SUPC_WKUPDBC_3_SLCK        ((unsigned int) 0x1 <<  12) // Wake Up Inputs Debouncer Period
#define AT91C_SUPC_WKUPDBC_32_SLCK       ((unsigned int) 0x2 <<  12) // Wake Up Inputs Debouncer Period
#define AT91C_SUPC_WKUPDBC_512_SLCK       ((unsigned int) 0x3 <<  12) // Wake Up Inputs Debouncer Period
#define AT91C_SUPC_WKUPDBC_4096_SLCK       ((unsigned int) 0x4 <<  12) // Wake Up Inputs Debouncer Period
#define AT91C_SUPC_WKUPDBC_32768_SLCK       ((unsigned int) 0x5 <<  12) // Wake Up Inputs Debouncer Period

// -------- SUPC_WUIR : (SUPC Offset: 0x8) Wake up Inputs Register -------- 
#define AT91C_SUPC_WKUPEN(num_wkupen)      ((unsigned int) 0x1 << num_wkupen) // (SUPC) Supply Monitor Wake Up Input enable
#define AT91C_SUPC_WKUPT(num_wkupt)      ((unsigned int) 0x1 << (16 + num_wkupt)) // (SUPC) Supply Monitor Wake Up Input status

// -------- SUPC_SR : (SUPC Offset: 0xc) Status Register -------- 
#define AT91C_SUPC_WKUPS      ((unsigned int) 0x1 <<  1) // (SUPC) Wake Up status
#define AT91C_SUPC_SMWS       ((unsigned int) 0x1 <<  2) // (SUPC) Supply Monitor Detection Wake Up Status
#define AT91C_SUPC_BODRSTS    ((unsigned int) 0x1 <<  3) // (SUPC) Brownout Detector Reset Status
#define AT91C_SUPC_SMRSTS     ((unsigned int) 0x1 <<  4) // (SUPC) Supply Monitor Reset Status
#define AT91C_SUPC_SMS        ((unsigned int) 0x1 <<  5) // (SUPC) Supply Monitor Status
#define AT91C_SUPC_SMOS       ((unsigned int) 0x1 <<  6) // (SUPC) Supply Monitor Output Status
#define AT91C_SUPC_OSCSEL      ((unsigned int) 0x1 <<  7) // (SUPC) 32-kHz Oscillator Selection Status
#define AT91C_SUPC_WKUPIS(num_wkupis)      ((unsigned int) 0x1 << (16 + num_wkupis)) // (SUPC) Supply Monitor Wake Up Input type

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Real Time Timer Controller Interface
// *****************************************************************************
typedef struct _AT91S_RTTC {
	AT91_REG	 RTTC_RTMR; 	// Real-time Mode Register
	AT91_REG	 RTTC_RTAR; 	// Real-time Alarm Register
	AT91_REG	 RTTC_RTVR; 	// Real-time Value Register
	AT91_REG	 RTTC_RTSR; 	// Real-time Status Register
} AT91S_RTTC, *AT91PS_RTTC;

// -------- RTTC_RTMR : (RTTC Offset: 0x0) Real-time Mode Register -------- 
#define AT91C_RTTC_RTPRES     ((unsigned int) 0xFFFF <<  0) // (RTTC) Real-time Timer Prescaler Value
#define AT91C_RTTC_ALMIEN     ((unsigned int) 0x1 << 16) // (RTTC) Alarm Interrupt Enable
#define AT91C_RTTC_RTTINCIEN  ((unsigned int) 0x1 << 17) // (RTTC) Real Time Timer Increment Interrupt Enable
#define AT91C_RTTC_RTTRST     ((unsigned int) 0x1 << 18) // (RTTC) Real Time Timer Restart
// -------- RTTC_RTAR : (RTTC Offset: 0x4) Real-time Alarm Register -------- 
#define AT91C_RTTC_ALMV       ((unsigned int) 0xffffffff <<  0) // (RTTC) Alarm Value
// -------- RTTC_RTVR : (RTTC Offset: 0x8) Current Real-time Value Register -------- 
#define AT91C_RTTC_CRTV       ((unsigned int) 0xffffffff <<  0) // (RTTC) Current Real-time Value
// -------- RTTC_RTSR : (RTTC Offset: 0xc) Real-time Status Register -------- 
#define AT91C_RTTC_ALMS       ((unsigned int) 0x1 <<  0) // (RTTC) Real-time Alarm Status
#define AT91C_RTTC_RTTINC     ((unsigned int) 0x1 <<  1) // (RTTC) Real-time Timer Increment

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Watchdog Timer Controller Interface
// *****************************************************************************
typedef struct _AT91S_WDTC {
	AT91_REG	 WDTC_WDCR; 	// Watchdog Control Register
	AT91_REG	 WDTC_WDMR; 	// Watchdog Mode Register
	AT91_REG	 WDTC_WDSR; 	// Watchdog Status Register
} AT91S_WDTC, *AT91PS_WDTC;

// -------- WDTC_WDCR : (WDTC Offset: 0x0) Periodic Interval Image Register -------- 
#define AT91C_WDTC_WDRSTT     ((unsigned int) 0x1 <<  0) // (WDTC) Watchdog Restart
#define AT91C_WDTC_KEY        ((unsigned int) 0xFF << 24) // (WDTC) Watchdog KEY Password
// -------- WDTC_WDMR : (WDTC Offset: 0x4) Watchdog Mode Register -------- 
#define AT91C_WDTC_WDV        ((unsigned int) 0xFFF <<  0) // (WDTC) Watchdog Timer Restart
#define AT91C_WDTC_WDFIEN     ((unsigned int) 0x1 << 12) // (WDTC) Watchdog Fault Interrupt Enable
#define AT91C_WDTC_WDRSTEN    ((unsigned int) 0x1 << 13) // (WDTC) Watchdog Reset Enable
#define AT91C_WDTC_WDRPROC    ((unsigned int) 0x1 << 14) // (WDTC) Watchdog Timer Restart
#define AT91C_WDTC_WDDIS      ((unsigned int) 0x1 << 15) // (WDTC) Watchdog Disable
#define AT91C_WDTC_WDD        ((unsigned int) 0xFFF << 16) // (WDTC) Watchdog Delta Value
#define AT91C_WDTC_WDDBGHLT   ((unsigned int) 0x1 << 28) // (WDTC) Watchdog Debug Halt
#define AT91C_WDTC_WDIDLEHLT  ((unsigned int) 0x1 << 29) // (WDTC) Watchdog Idle Halt
// -------- WDTC_WDSR : (WDTC Offset: 0x8) Watchdog Status Register -------- 
#define AT91C_WDTC_WDUNF      ((unsigned int) 0x1 <<  0) // (WDTC) Watchdog Underflow
#define AT91C_WDTC_WDERR      ((unsigned int) 0x1 <<  1) // (WDTC) Watchdog Error

typedef struct _AT91S_RTCC {
  AT91_REG RTCC_RCCR;
  AT91_REG RTCC_RCMR;
  AT91_REG RTCC_RCTIMR;
  AT91_REG RTCC_RCCALR;
  AT91_REG RTCC_RCTIMALR;
  AT91_REG RTCC_RCCALALR;
  AT91_REG RTCC_RCSR;
  AT91_REG RTCC_RCSCCR;
  AT91_REG RTCC_RCIER;
  AT91_REG RTCC_RCIDR;
  AT91_REG RTCC_RCIMR;
  AT91_REG RTCC_RCVER;
  AT91_REG Reserved[52];  
} AT_91S_RTCC, *AT91PS_RTCC;

// -------- RTCC_RCCR : (RTCC Offset: 0x0) Real-Time Clock Control Register -------- 
#define AT91C_RTCC_UPDTIM     ((unsigned int) 0x1 <<  0) // (RTCC) update reauest register(stop counting)
#define AT91C_RTCC_UPDCAL        ((unsigned int) 0x1 << 1) // (RTCC) Update Request Calendar Register
#define AT91C_RTCC_TIMEVSEL_0      ((unsigned int) 0x0 << 8) // (RTCC) Time Event Selection (minute change)
#define AT91C_RTCC_TIMEVSEL_1      ((unsigned int) 0x1 << 8) // (RTCC) Time Event Selection (hour change)
#define AT91C_RTCC_TIMEVSEL_2      ((unsigned int) 0x2 << 8) // (RTCC) Time Event Selection (every day at midnight)
#define AT91C_RTCC_TIMEVSEL_3      ((unsigned int) 0x3 << 8) // (RTCC) Time Event Selection (every day at noon)
#define AT91C_RTCC_CALEVSEL_0      ((unsigned int) 0x0 << 16) // (RTCC) Calendar Event Selection (week change)
#define AT91C_RTCC_CALEVSEL_1      ((unsigned int) 0x1 << 16) // (RTCC) Calendar Event Selection (month change)
#define AT91C_RTCC_CALEVSEL_2      ((unsigned int) 0x2 << 16) // (RTCC) Calendar Event Selection (year change)
#define AT91C_RTCC_CALEVSEL      ((unsigned int) 0x3 << 16) // (RTCC) Calendar Event Selection
// -------- RTCC_RCMR : (RTCC Offset: 0x4) Real-Time Clock Mode Register -------- 
#define AT91C_RTCC_HRMOD_0        ((unsigned int) 0x0 <<  0) // (RTCC) 24 hour mode
#define AT91C_RTCC_HRMOD_1        ((unsigned int) 0x1 <<  0) // (RTCC) 12 hour mode
// -------- RTCC_RCTIMR : (RTCC Offset: 0x8) Real-Time Clock Time Register -------- 
#define AT91C_RTCC_TIMSEC(num_sec)        (num_sec <<  0) // (RTCC) current second ([6-4]:tens,[3-0]:units)
#define AT91C_RTCC_TIMMIN(num_min)        (num_min <<  8) // (RTCC) current minute ([14-12]:tens,[11-8]:units)
#define AT91C_RTCC_TIMHOUR(num_hour)        (num_hour << 16) // (RTCC) current hour
#define AT91C_RTCC_TIMAMPM           ((unsigned int) 0x1 <<  22) // (RTCC) am=0 pm=1
// -------- RTCC_RCCALR : (RTCC Offset: 0xc) Real-Time Clock Calendar Register -------- 
#define AT91C_RTCC_CALCENT(num_cent)        (num_cent <<  0) // (RTCC) current century
#define AT91C_RTCC_CALYEAR(num_year)        (num_year <<  8) // (RTCC) current year
#define AT91C_RTCC_CALMONTH(num_month)      (num_month << 16) // (RTCC) current month
#define AT91C_RTCC_CALDAY(num_day)          (num_day << 21) // (RTCC) current day
#define AT91C_RTCC_CALDATE(num_date)        (num_date << 24) // (RTCC) current date
// -------- RTCC_RCTIMALR : (RTCC Offset: 0x10) Real-Time Clock Time Alarm Register -------- 
#define AT91C_RTCC_ALSEC(num_sec)        (num_sec <<  0) // (RTCC) current second ([6-4]:tens,[3-0]:units)
#define AT91C_RTCC_SECEN           ((unsigned int) 0x1 <<  7) // (RTCC) second enable
#define AT91C_RTCC_ALMIN(num_min)        (num_min <<  8) // (RTCC) current minute ([14-12]:tens,[11-8]:units)
#define AT91C_RTCC_MINEN           ((unsigned int) 0x1 <<  15) // (RTCC) minute enable
#define AT91C_RTCC_ALHOUR(num_hour)        (num_hour << 16) // (RTCC) current hour
#define AT91C_RTCC_HOUREN           ((unsigned int) 0x1 <<  23) // (RTCC) hour enable
#define AT91C_RTCC_TIMALAMPM           ((unsigned int) 0x1 <<  22) // (RTCC) am=0 pm=1
// -------- RTCC_RCCALALR : (RTCC Offset: 0x14) Real-Time Clock Calendar Alarm Register -------- 
#define AT91C_RTCC_ALMONTH(num_month)      (num_month << 16) // (RTCC) current month
#define AT91C_RTCC_ALDATE(num_date)        (num_date << 24) // (RTCC) current date
#define AT91C_RTCC_MTHEN           ((unsigned int) 0x1 <<  23) // (RTCC) month enable
#define AT91C_RTCC_DATEEN           ((unsigned int) 0x1 <<  31) // (RTCC) date enable
// -------- RTCC_RCSR : (RTCC Offset: 0x18) Real-Time Clock Status Register -------- 
#define AT91C_RTCC_ACKUPD           ((unsigned int) 0x1 <<  0) // (RTCC) acknowledge for update
#define AT91C_RTCC_ALARM            ((unsigned int) 0x1 <<  1) // (RTCC) ALARM FLAG
#define AT91C_RTCC_SSEC             ((unsigned int) 0x1 <<  2) // (RTCC) acknowledge for update
#define AT91C_RTCC_TIMEV            ((unsigned int) 0x1 <<  3) // (RTCC) Time Event
#define AT91C_RTCC_CALEV            ((unsigned int) 0x1 <<  4) // (RTCC) Calendar Event
// -------- RTCC_RCSCCR : (RTCC Offset: 0x1C) Real-Time Clock Status Clear Command Register -------- 
#define AT91C_RTCC_ACKCLR           ((unsigned int) 0x1 <<  0) // (RTCC) acknowledge for update
#define AT91C_RTCC_ALRCLR           ((unsigned int) 0x1 <<  1) // (RTCC) ALARM FLAG
#define AT91C_RTCC_SECCLR           ((unsigned int) 0x1 <<  2) // (RTCC) acknowledge for update
#define AT91C_RTCC_TIMCLR           ((unsigned int) 0x1 <<  3) // (RTCC) Time Event
#define AT91C_RTCC_CALCLR           ((unsigned int) 0x1 <<  4) // (RTCC) Calendar Event
// -------- RTCC_RCIER : (RTCC Offset: 0x20) Real-Time Clock Interrupt Enable Register Register -------- 
#define AT91C_RTCC_ACKEN           ((unsigned int) 0x1 <<  0) // (RTCC) acknowledge for update
#define AT91C_RTCC_ALREN           ((unsigned int) 0x1 <<  1) // (RTCC) ALARM FLAG
#define AT91C_RTCC_IER_SECEN           ((unsigned int) 0x1 <<  2) // (RTCC) acknowledge for update
#define AT91C_RTCC_TIMEN           ((unsigned int) 0x1 <<  3) // (RTCC) Time Event
#define AT91C_RTCC_CALEN           ((unsigned int) 0x1 <<  4) // (RTCC) Calendar Event
// -------- RTCC_RCIDR : (RTCC Offset: 0x24) Real-Time Clock Interrupt Disable Register -------- 
// -------- RTCC_RCIMR : (RTCC Offset: 0x28) Real-Time Clock Interrupt Mask Register -------- 
// -------- RTCC_RCVER : (RTCC Offset: 0x2c) Real-Time Clock Valid Entry Register -------- 
#define AT91C_RTCC_NVTIM           ((unsigned int) 0x1 <<  0) // (RTCC) TIMR has invalid data
#define AT91C_RTCC_NVCAL           ((unsigned int) 0x1 <<  1) // (RTCC) CALR has invalid data
#define AT91C_RTCC_NVTIMALR        ((unsigned int) 0x1 <<  2) // (RTCC) TIMALR has invalid data
#define AT91C_RTCC_NVCALALR        ((unsigned int) 0x1 <<  3) // (RTCC) CALALR has invalid data

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR General Purpose Backup Register
// *****************************************************************************
typedef struct _AT91S_GPBR {
	AT91_REG	 SYS_GPBR[8];
} AT91S_GPBR, *AT91PS_GPBR;

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Synchronous Serial Controller Interface
// *****************************************************************************
typedef struct _AT91S_SSC {
	AT91_REG	 SSC_CR; 	// Control Register
	AT91_REG	 SSC_CMR; 	// Clock Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 SSC_RCMR; 	// Receive Clock ModeRegister
	AT91_REG	 SSC_RFMR; 	// Receive Frame Mode Register
	AT91_REG	 SSC_TCMR; 	// Transmit Clock Mode Register
	AT91_REG	 SSC_TFMR; 	// Transmit Frame Mode Register
	AT91_REG	 SSC_RHR; 	// Receive Holding Register
	AT91_REG	 SSC_THR; 	// Transmit Holding Register
	AT91_REG	 Reserved1[2]; 	// 
	AT91_REG	 SSC_RSHR; 	// Receive Sync Holding Register
	AT91_REG	 SSC_TSHR; 	// Transmit Sync Holding Register
	AT91_REG	 Reserved2[2]; 	// 
	AT91_REG	 SSC_SR; 	// Status Register
	AT91_REG	 SSC_IER; 	// Interrupt Enable Register
	AT91_REG	 SSC_IDR; 	// Interrupt Disable Register
	AT91_REG	 SSC_IMR; 	// Interrupt Mask Register
	AT91_REG	 Reserved3[44]; 	// 
	AT91_REG	 SSC_RPR; 	// Receive Pointer Register
	AT91_REG	 SSC_RCR; 	// Receive Counter Register
	AT91_REG	 SSC_TPR; 	// Transmit Pointer Register
	AT91_REG	 SSC_TCR; 	// Transmit Counter Register
	AT91_REG	 SSC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 SSC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 SSC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 SSC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 SSC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 SSC_PTSR; 	// PDC Transfer Status Register
} AT91S_SSC, *AT91PS_SSC;

// -------- SSC_CR : (SSC Offset: 0x0) SSC Control Register -------- 
#define AT91C_SSC_RXEN        ((unsigned int) 0x1 <<  0) // (SSC) Receive Enable
#define AT91C_SSC_RXDIS       ((unsigned int) 0x1 <<  1) // (SSC) Receive Disable
#define AT91C_SSC_TXEN        ((unsigned int) 0x1 <<  8) // (SSC) Transmit Enable
#define AT91C_SSC_TXDIS       ((unsigned int) 0x1 <<  9) // (SSC) Transmit Disable
#define AT91C_SSC_SWRST       ((unsigned int) 0x1 << 15) // (SSC) Software Reset
// -------- SSC_RCMR : (SSC Offset: 0x10) SSC Receive Clock Mode Register -------- 
#define AT91C_SSC_CKS         ((unsigned int) 0x3 <<  0) // (SSC) Receive/Transmit Clock Selection
#define 	AT91C_SSC_CKS_DIV                  ((unsigned int) 0x0) // (SSC) Divided Clock
#define 	AT91C_SSC_CKS_TK                   ((unsigned int) 0x1) // (SSC) TK Clock signal
#define 	AT91C_SSC_CKS_RK                   ((unsigned int) 0x2) // (SSC) RK pin
#define AT91C_SSC_CKO         ((unsigned int) 0x7 <<  2) // (SSC) Receive/Transmit Clock Output Mode Selection
#define 	AT91C_SSC_CKO_NONE                 ((unsigned int) 0x0 <<  2) // (SSC) Receive/Transmit Clock Output Mode: None RK pin: Input-only
#define 	AT91C_SSC_CKO_CONTINOUS            ((unsigned int) 0x1 <<  2) // (SSC) Continuous Receive/Transmit Clock RK pin: Output
#define 	AT91C_SSC_CKO_DATA_TX              ((unsigned int) 0x2 <<  2) // (SSC) Receive/Transmit Clock only during data transfers RK pin: Output
#define AT91C_SSC_CKI         ((unsigned int) 0x1 <<  5) // (SSC) Receive/Transmit Clock Inversion
#define AT91C_SSC_START       ((unsigned int) 0xF <<  8) // (SSC) Receive/Transmit Start Selection
#define 	AT91C_SSC_START_CONTINOUS            ((unsigned int) 0x0 <<  8) // (SSC) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data.
#define 	AT91C_SSC_START_TX                   ((unsigned int) 0x1 <<  8) // (SSC) Transmit/Receive start
#define 	AT91C_SSC_START_LOW_RF               ((unsigned int) 0x2 <<  8) // (SSC) Detection of a low level on RF input
#define 	AT91C_SSC_START_HIGH_RF              ((unsigned int) 0x3 <<  8) // (SSC) Detection of a high level on RF input
#define 	AT91C_SSC_START_FALL_RF              ((unsigned int) 0x4 <<  8) // (SSC) Detection of a falling edge on RF input
#define 	AT91C_SSC_START_RISE_RF              ((unsigned int) 0x5 <<  8) // (SSC) Detection of a rising edge on RF input
#define 	AT91C_SSC_START_LEVEL_RF             ((unsigned int) 0x6 <<  8) // (SSC) Detection of any level change on RF input
#define 	AT91C_SSC_START_EDGE_RF              ((unsigned int) 0x7 <<  8) // (SSC) Detection of any edge on RF input
#define 	AT91C_SSC_START_0                    ((unsigned int) 0x8 <<  8) // (SSC) Compare 0
#define AT91C_SSC_STTDLY      ((unsigned int) 0xFF << 16) // (SSC) Receive/Transmit Start Delay
#define AT91C_SSC_PERIOD      ((unsigned int) 0xFF << 24) // (SSC) Receive/Transmit Period Divider Selection
// -------- SSC_RFMR : (SSC Offset: 0x14) SSC Receive Frame Mode Register -------- 
#define AT91C_SSC_DATLEN      ((unsigned int) 0x1F <<  0) // (SSC) Data Length
#define AT91C_SSC_LOOP        ((unsigned int) 0x1 <<  5) // (SSC) Loop Mode
#define AT91C_SSC_MSBF        ((unsigned int) 0x1 <<  7) // (SSC) Most Significant Bit First
#define AT91C_SSC_DATNB       ((unsigned int) 0xF <<  8) // (SSC) Data Number per Frame
#define AT91C_SSC_FSLEN       ((unsigned int) 0xF << 16) // (SSC) Receive/Transmit Frame Sync length
#define AT91C_SSC_FSOS        ((unsigned int) 0x7 << 20) // (SSC) Receive/Transmit Frame Sync Output Selection
#define 	AT91C_SSC_FSOS_NONE                 ((unsigned int) 0x0 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: None RK pin Input-only
#define 	AT91C_SSC_FSOS_NEGATIVE             ((unsigned int) 0x1 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Negative Pulse
#define 	AT91C_SSC_FSOS_POSITIVE             ((unsigned int) 0x2 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Positive Pulse
#define 	AT91C_SSC_FSOS_LOW                  ((unsigned int) 0x3 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver Low during data transfer
#define 	AT91C_SSC_FSOS_HIGH                 ((unsigned int) 0x4 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver High during data transfer
#define 	AT91C_SSC_FSOS_TOGGLE               ((unsigned int) 0x5 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Toggling at each start of data transfer
#define AT91C_SSC_FSEDGE      ((unsigned int) 0x1 << 24) // (SSC) Frame Sync Edge Detection
// -------- SSC_TCMR : (SSC Offset: 0x18) SSC Transmit Clock Mode Register -------- 
// -------- SSC_TFMR : (SSC Offset: 0x1c) SSC Transmit Frame Mode Register -------- 
#define AT91C_SSC_DATDEF      ((unsigned int) 0x1 <<  5) // (SSC) Data Default Value
#define AT91C_SSC_FSDEN       ((unsigned int) 0x1 << 23) // (SSC) Frame Sync Data Enable
// -------- SSC_SR : (SSC Offset: 0x40) SSC Status Register -------- 
#define AT91C_SSC_TXRDY       ((unsigned int) 0x1 <<  0) // (SSC) Transmit Ready
#define AT91C_SSC_TXEMPTY     ((unsigned int) 0x1 <<  1) // (SSC) Transmit Empty
#define AT91C_SSC_ENDTX       ((unsigned int) 0x1 <<  2) // (SSC) End Of Transmission
#define AT91C_SSC_TXBUFE      ((unsigned int) 0x1 <<  3) // (SSC) Transmit Buffer Empty
#define AT91C_SSC_RXRDY       ((unsigned int) 0x1 <<  4) // (SSC) Receive Ready
#define AT91C_SSC_OVRUN       ((unsigned int) 0x1 <<  5) // (SSC) Receive Overrun
#define AT91C_SSC_ENDRX       ((unsigned int) 0x1 <<  6) // (SSC) End of Reception
#define AT91C_SSC_RXBUFF      ((unsigned int) 0x1 <<  7) // (SSC) Receive Buffer Full
#define AT91C_SSC_TXSYN       ((unsigned int) 0x1 << 10) // (SSC) Transmit Sync
#define AT91C_SSC_RXSYN       ((unsigned int) 0x1 << 11) // (SSC) Receive Sync
#define AT91C_SSC_TXENA       ((unsigned int) 0x1 << 16) // (SSC) Transmit Enable
#define AT91C_SSC_RXENA       ((unsigned int) 0x1 << 17) // (SSC) Receive Enable
// -------- SSC_IER : (SSC Offset: 0x44) SSC Interrupt Enable Register -------- 
// -------- SSC_IDR : (SSC Offset: 0x48) SSC Interrupt Disable Register -------- 
// -------- SSC_IMR : (SSC Offset: 0x4c) SSC Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Peripheral DMA Controller
// *****************************************************************************
typedef struct _AT91S_PDC {
	AT91_REG	 PDC_RPR; 	// Receive Pointer Register
	AT91_REG	 PDC_RCR; 	// Receive Counter Register
	AT91_REG	 PDC_TPR; 	// Transmit Pointer Register
	AT91_REG	 PDC_TCR; 	// Transmit Counter Register
	AT91_REG	 PDC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PDC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PDC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PDC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PDC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PDC_PTSR; 	// PDC Transfer Status Register
} AT91S_PDC, *AT91PS_PDC;

// -------- PDC_PTCR : (PDC Offset: 0x120) PDC Transfer Control Register -------- 
#define AT91C_PDC_RXTEN       ((unsigned int) 0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      ((unsigned int) 0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       ((unsigned int) 0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      ((unsigned int) 0x1 <<  9) // (PDC) Transmitter Transfer Disable
// -------- PDC_PTSR : (PDC Offset: 0x124) PDC Transfer Status Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Serial Parallel Interface
// *****************************************************************************
typedef struct _AT91S_SPI {
	AT91_REG	 SPI_CR; 	// Control Register
	AT91_REG	 SPI_MR; 	// Mode Register
	AT91_REG	 SPI_RDR; 	// Receive Data Register
	AT91_REG	 SPI_TDR; 	// Transmit Data Register
	AT91_REG	 SPI_SR; 	// Status Register
	AT91_REG	 SPI_IER; 	// Interrupt Enable Register
	AT91_REG	 SPI_IDR; 	// Interrupt Disable Register
	AT91_REG	 SPI_IMR; 	// Interrupt Mask Register
	AT91_REG	 Reserved0[4]; 	// 
	AT91_REG	 SPI_CSR[4]; 	// Chip Select Register
  //for at91sam3sd8
	AT91_REG	 Reserved1[41]; 	// 
        AT91_REG         SPI_WPMR;      //Write Protection Control Register
        AT91_REG         SPI_WPSR;      //Write Protection Status Register
  AT91_REG tx_fifo_head;
  AT91_REG rx_fifo_head;
  AT91_REG tx_fifo_len;
  AT91_REG rx_fifo_len;
  unsigned short tx_fifo[8];
  unsigned short rx_fifo[8];
  
        AT91_REG         Reserved2[5]; //
	AT91_REG	 SPI_RPR; 	// Receive Pointer Register
	AT91_REG	 SPI_RCR; 	// Receive Counter Register
	AT91_REG	 SPI_TPR; 	// Transmit Pointer Register
	AT91_REG	 SPI_TCR; 	// Transmit Counter Register
	AT91_REG	 SPI_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 SPI_RNCR; 	// Receive Next Counter Register
	AT91_REG	 SPI_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 SPI_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 SPI_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 SPI_PTSR; 	// PDC Transfer Status Register

} AT91S_SPI, *AT91PS_SPI;

// -------- SPI_CR : (SPI Offset: 0x0) SPI Control Register -------- 
#define AT91C_SPI_SPIEN       ((unsigned int) 0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS      ((unsigned int) 0x1 <<  1) // (SPI) SPI Disable
#define AT91C_SPI_SWRST       ((unsigned int) 0x1 <<  7) // (SPI) SPI Software reset
#define AT91C_SPI_LASTXFER    ((unsigned int) 0x1 << 24) // (SPI) SPI Last Transfer
// -------- SPI_MR : (SPI Offset: 0x4) SPI Mode Register -------- 
#define AT91C_SPI_MSTR        ((unsigned int) 0x1 <<  0) // (SPI) Master/Slave Mode
#define AT91C_SPI_PS          ((unsigned int) 0x1 <<  1) // (SPI) Peripheral Select
#define 	AT91C_SPI_PS_FIXED                ((unsigned int) 0x0 <<  1) // (SPI) Fixed Peripheral Select
#define 	AT91C_SPI_PS_VARIABLE             ((unsigned int) 0x1 <<  1) // (SPI) Variable Peripheral Select
#define AT91C_SPI_PCSDEC      ((unsigned int) 0x1 <<  2) // (SPI) Chip Select Decode
#define AT91C_SPI_FDIV        ((unsigned int) 0x1 <<  3) // (SPI) Clock Selection
#define AT91C_SPI_MODFDIS     ((unsigned int) 0x1 <<  4) // (SPI) Mode Fault Detection
#define AT91C_SPI_LLB         ((unsigned int) 0x1 <<  7) // (SPI) Clock Selection
#define AT91C_SPI_PCS         ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_DLYBCS      ((unsigned int) 0xFF << 24) // (SPI) Delay Between Chip Selects
// -------- SPI_RDR : (SPI Offset: 0x8) Receive Data Register -------- 
#define AT91C_SPI_RD          ((unsigned int) 0xFFFF <<  0) // (SPI) Receive Data
#define AT91C_SPI_RPCS        ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_TDR : (SPI Offset: 0xc) Transmit Data Register -------- 
#define AT91C_SPI_TD          ((unsigned int) 0xFFFF <<  0) // (SPI) Transmit Data
#define AT91C_SPI_TPCS        ((unsigned int) 0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_SR : (SPI Offset: 0x10) Status Register -------- 
#define AT91C_SPI_RDRF        ((unsigned int) 0x1 <<  0) // (SPI) Receive Data Register Full
#define AT91C_SPI_TDRE        ((unsigned int) 0x1 <<  1) // (SPI) Transmit Data Register Empty
#define AT91C_SPI_MODF        ((unsigned int) 0x1 <<  2) // (SPI) Mode Fault Error
#define AT91C_SPI_OVRES       ((unsigned int) 0x1 <<  3) // (SPI) Overrun Error Status
#define AT91C_SPI_ENDRX       ((unsigned int) 0x1 <<  4) // (SPI) End of Receiver Transfer
#define AT91C_SPI_ENDTX       ((unsigned int) 0x1 <<  5) // (SPI) End of Transfer Transfer
#define AT91C_SPI_RXBUFF      ((unsigned int) 0x1 <<  6) // (SPI) RXBUFF
#define AT91C_SPI_TXBUFE      ((unsigned int) 0x1 <<  7) // (SPI) TXBUFE
#define AT91C_SPI_NSSR        ((unsigned int) 0x1 <<  8) // (SPI) NSSR
#define AT91C_SPI_TXEMPTY     ((unsigned int) 0x1 <<  9) // (SPI) TXEMPTY 
#define AT91C_SPI_SPIENS      ((unsigned int) 0x1 << 16) // (SPI) Enable Status
// -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register -------- 
// -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register -------- 
// -------- SPI_IMR : (SPI Offset: 0x1c) Interrupt Mask Register -------- 
// -------- SPI_CSR : (SPI Offset: 0x30) Chip Select Register -------- 
#define AT91C_SPI_CPOL        ((unsigned int) 0x1 <<  0) // (SPI) Clock Polarity
#define AT91C_SPI_NCPHA       ((unsigned int) 0x1 <<  1) // (SPI) Clock Phase
#define AT91C_SPI_CSAAT       ((unsigned int) 0x0 <<  3) // (SPI) Chip Select Active After Transfer
#define AT91C_SPI_BITS        ((unsigned int) 0xF <<  4) // (SPI) Bits Per Transfer
#define 	AT91C_SPI_BITS_8                    ((unsigned int) 0x0 <<  4) // (SPI) 8 Bits Per transfer
#define 	AT91C_SPI_BITS_9                    ((unsigned int) 0x1 <<  4) // (SPI) 9 Bits Per transfer
#define 	AT91C_SPI_BITS_10                   ((unsigned int) 0x2 <<  4) // (SPI) 10 Bits Per transfer
#define 	AT91C_SPI_BITS_11                   ((unsigned int) 0x3 <<  4) // (SPI) 11 Bits Per transfer
#define 	AT91C_SPI_BITS_12                   ((unsigned int) 0x4 <<  4) // (SPI) 12 Bits Per transfer
#define 	AT91C_SPI_BITS_13                   ((unsigned int) 0x5 <<  4) // (SPI) 13 Bits Per transfer
#define 	AT91C_SPI_BITS_14                   ((unsigned int) 0x6 <<  4) // (SPI) 14 Bits Per transfer
#define 	AT91C_SPI_BITS_15                   ((unsigned int) 0x7 <<  4) // (SPI) 15 Bits Per transfer
#define 	AT91C_SPI_BITS_16                   ((unsigned int) 0x8 <<  4) // (SPI) 16 Bits Per transfer
#define AT91C_SPI_SCBR        ((unsigned int) 0xFF <<  8) // (SPI) Serial Clock Baud Rate
#define AT91C_SPI_DLYBS       ((unsigned int) 0xFF << 16) // (SPI) Delay Before SPCK
#define AT91C_SPI_DLYBCT      ((unsigned int) 0xFF << 24) // (SPI) Delay Between Consecutive Transfers

typedef struct _AT86S_RADIO {
  AT86_REG Reserved0;
  AT86_REG TX_STATUS;
  AT86_REG TRX_STATE;
  AT86_REG TRX_CTRL_0;
  AT86_REG TRX_CTRL_1;
  AT86_REG PHY_TX_PWR;
  AT86_REG PHY_RSSI;
  AT86_REG PHY_ED_LEVEL;
  AT86_REG PHY_CC_CCA;
  AT86_REG CCA_THRES;
  AT86_REG RX_CTRL;
  AT86_REG SFD_VALUE;
  AT86_REG TRX_CTRL_2;
  AT86_REG ANT_DIV;  
  AT86_REG IRQ_MASK;
  AT86_REG IRQ_STATUS;
  AT86_REG VREG_CTRL;
  AT86_REG BATMON;
  AT86_REG XOSC_CTRL;
  AT86_REG CC_CTRL_0;
  AT86_REG CC_CTRL_1;
  AT86_REG RX_SYN;
  AT86_REG TRX_RPC;
  AT86_REG XAH_CTRL_1;
  AT86_REG FTN_CTRL;
  AT86_REG XAH_CTRL_2;
  AT86_REG PLL_CF;
  AT86_REG PLL_DCU;
  AT86_REG PART_NUM;  
  AT86_REG VERSION_NUM;
  AT86_REG MAIN_ID[2];
  AT86_REG SHORT_ADDR[2];
  AT86_REG PAN_ID[2];
  AT86_REG IEEE_ADDR[8];
  AT86_REG XAH_CTRL_0;
  AT86_REG CSMA_SEED[2];
  AT86_REG CSMA_BE;
  AT86_REG Reserved1[6];
  AT86_REG TST_CTRL_DIGI;
  AT86_REG Reserved2[4];
  AT86_REG PHY_TX_TIME;
  AT86_REG TST_AGC;
  AT86_REG TST_SDM;
  unsigned int radioIO;
} AT86S_RADIO, *AT86PS_RADIO;
/*
typedef struct _AT86S_RADIOIO {
  //uint32_t radioIO;
  
  boolean DIG3;
  boolean DIG4;
  boolean AVSS1;
  boolean RFP;
  boolean RFN;
  boolean AVSS2;
  boolean DVSS1;
  boolean nRST;
  boolean DIG1;
  boolean DIG2;
  boolean SLP_TR;
  boolean DVSS2;
  boolean DVDD1;
  boolean DVDD2;
  boolean DEVDD2;
  boolean DVSS3;
  boolean CLKM;
  boolean DVSS4;
  boolean SCLK;//in
  boolean MISO;//out
  boolean DVSS5;
  boolean MOSI;//in
  boolean nSEL;//in
  boolean IRQ;
  boolean XTAL2;
  boolean XTAL1;
  boolean AVSS3;
  boolean EVDD;
  boolean AVDD;
  boolean AVSS4[3]; 
  
} AT86RFIOS_RADIO, *AT86RFIOPS_RADIO;
*/

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Timer Counter Channel Interface
// *****************************************************************************
typedef struct _AT91S_TC {
	AT91_REG	 TC_CCR; 	// Channel Control Register
	AT91_REG	 TC_CMR; 	// Channel Mode Register (Capture Mode / Waveform Mode)
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 TC_CV; 	// Counter Value
	AT91_REG	 TC_RA; 	// Register A
	AT91_REG	 TC_RB; 	// Register B
	AT91_REG	 TC_RC; 	// Register C
	AT91_REG	 TC_SR; 	// Status Register
	AT91_REG	 TC_IER; 	// Interrupt Enable Register
	AT91_REG	 TC_IDR; 	// Interrupt Disable Register
	AT91_REG	 TC_IMR; 	// Interrupt Mask Register
} AT91S_TC, *AT91PS_TC;

// -------- TC_CCR : (TC Offset: 0x0) TC Channel Control Register -------- 
#define AT91C_TC_CLKEN        ((unsigned int) 0x1 <<  0) // (TC) Counter Clock Enable Command
#define AT91C_TC_CLKDIS       ((unsigned int) 0x1 <<  1) // (TC) Counter Clock Disable Command
#define AT91C_TC_SWTRG        ((unsigned int) 0x1 <<  2) // (TC) Software Trigger Command
// -------- TC_CMR : (TC Offset: 0x4) TC Channel Mode Register: Capture Mode / Waveform Mode -------- 
#define AT91C_TC_CLKS         ((unsigned int) 0x7 <<  0) // (TC) Clock Selection
#define 	AT91C_TC_CLKS_TIMER_DIV1_CLOCK     ((unsigned int) 0x0) // (TC) Clock selected: TIMER_DIV1_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV2_CLOCK     ((unsigned int) 0x1) // (TC) Clock selected: TIMER_DIV2_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV3_CLOCK     ((unsigned int) 0x2) // (TC) Clock selected: TIMER_DIV3_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV4_CLOCK     ((unsigned int) 0x3) // (TC) Clock selected: TIMER_DIV4_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV5_CLOCK     ((unsigned int) 0x4) // (TC) Clock selected: TIMER_DIV5_CLOCK
#define 	AT91C_TC_CLKS_XC0                  ((unsigned int) 0x5) // (TC) Clock selected: XC0
#define 	AT91C_TC_CLKS_XC1                  ((unsigned int) 0x6) // (TC) Clock selected: XC1
#define 	AT91C_TC_CLKS_XC2                  ((unsigned int) 0x7) // (TC) Clock selected: XC2
#define AT91C_TC_CLKI         ((unsigned int) 0x1 <<  3) // (TC) Clock Invert
#define AT91C_TC_BURST        ((unsigned int) 0x3 <<  4) // (TC) Burst Signal Selection
#define 	AT91C_TC_BURST_NONE                 ((unsigned int) 0x0 <<  4) // (TC) The clock is not gated by an external signal
#define 	AT91C_TC_BURST_XC0                  ((unsigned int) 0x1 <<  4) // (TC) XC0 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC1                  ((unsigned int) 0x2 <<  4) // (TC) XC1 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC2                  ((unsigned int) 0x3 <<  4) // (TC) XC2 is ANDed with the selected clock
#define AT91C_TC_CPCSTOP      ((unsigned int) 0x1 <<  6) // (TC) Counter Clock Stopped with RC Compare
#define AT91C_TC_LDBSTOP      ((unsigned int) 0x1 <<  6) // (TC) Counter Clock Stopped with RB Loading
#define AT91C_TC_CPCDIS       ((unsigned int) 0x1 <<  7) // (TC) Counter Clock Disable with RC Compare
#define AT91C_TC_LDBDIS       ((unsigned int) 0x1 <<  7) // (TC) Counter Clock Disabled with RB Loading
#define AT91C_TC_ETRGEDG      ((unsigned int) 0x3 <<  8) // (TC) External Trigger Edge Selection
#define 	AT91C_TC_ETRGEDG_NONE                 ((unsigned int) 0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_ETRGEDG_RISING               ((unsigned int) 0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_ETRGEDG_FALLING              ((unsigned int) 0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_ETRGEDG_BOTH                 ((unsigned int) 0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVTEDG      ((unsigned int) 0x3 <<  8) // (TC) External Event Edge Selection
#define 	AT91C_TC_EEVTEDG_NONE                 ((unsigned int) 0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_EEVTEDG_RISING               ((unsigned int) 0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_EEVTEDG_FALLING              ((unsigned int) 0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_EEVTEDG_BOTH                 ((unsigned int) 0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVT         ((unsigned int) 0x3 << 10) // (TC) External Event  Selection
#define 	AT91C_TC_EEVT_TIOB                 ((unsigned int) 0x0 << 10) // (TC) Signal selected as external event: TIOB TIOB direction: input
#define 	AT91C_TC_EEVT_XC0                  ((unsigned int) 0x1 << 10) // (TC) Signal selected as external event: XC0 TIOB direction: output
#define 	AT91C_TC_EEVT_XC1                  ((unsigned int) 0x2 << 10) // (TC) Signal selected as external event: XC1 TIOB direction: output
#define 	AT91C_TC_EEVT_XC2                  ((unsigned int) 0x3 << 10) // (TC) Signal selected as external event: XC2 TIOB direction: output
#define AT91C_TC_ABETRG       ((unsigned int) 0x1 << 10) // (TC) TIOA or TIOB External Trigger Selection
#define AT91C_TC_ENETRG       ((unsigned int) 0x1 << 12) // (TC) External Event Trigger enable
#define AT91C_TC_WAVESEL      ((unsigned int) 0x3 << 13) // (TC) Waveform  Selection
#define 	AT91C_TC_WAVESEL_UP                   ((unsigned int) 0x0 << 13) // (TC) UP mode without atomatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN               ((unsigned int) 0x1 << 13) // (TC) UPDOWN mode without automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UP_AUTO              ((unsigned int) 0x2 << 13) // (TC) UP mode with automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN_AUTO          ((unsigned int) 0x3 << 13) // (TC) UPDOWN mode with automatic trigger on RC Compare
#define AT91C_TC_CPCTRG       ((unsigned int) 0x1 << 14) // (TC) RC Compare Trigger Enable
#define AT91C_TC_WAVE         ((unsigned int) 0x1 << 15) // (TC) 
#define AT91C_TC_ACPA         ((unsigned int) 0x3 << 16) // (TC) RA Compare Effect on TIOA
#define 	AT91C_TC_ACPA_NONE                 ((unsigned int) 0x0 << 16) // (TC) Effect: none
#define 	AT91C_TC_ACPA_SET                  ((unsigned int) 0x1 << 16) // (TC) Effect: set
#define 	AT91C_TC_ACPA_CLEAR                ((unsigned int) 0x2 << 16) // (TC) Effect: clear
#define 	AT91C_TC_ACPA_TOGGLE               ((unsigned int) 0x3 << 16) // (TC) Effect: toggle
#define AT91C_TC_LDRA         ((unsigned int) 0x3 << 16) // (TC) RA Loading Selection
#define 	AT91C_TC_LDRA_NONE                 ((unsigned int) 0x0 << 16) // (TC) Edge: None
#define 	AT91C_TC_LDRA_RISING               ((unsigned int) 0x1 << 16) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRA_FALLING              ((unsigned int) 0x2 << 16) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRA_BOTH                 ((unsigned int) 0x3 << 16) // (TC) Edge: each edge of TIOA
#define AT91C_TC_ACPC         ((unsigned int) 0x3 << 18) // (TC) RC Compare Effect on TIOA
#define 	AT91C_TC_ACPC_NONE                 ((unsigned int) 0x0 << 18) // (TC) Effect: none
#define 	AT91C_TC_ACPC_SET                  ((unsigned int) 0x1 << 18) // (TC) Effect: set
#define 	AT91C_TC_ACPC_CLEAR                ((unsigned int) 0x2 << 18) // (TC) Effect: clear
#define 	AT91C_TC_ACPC_TOGGLE               ((unsigned int) 0x3 << 18) // (TC) Effect: toggle
#define AT91C_TC_LDRB         ((unsigned int) 0x3 << 18) // (TC) RB Loading Selection
#define 	AT91C_TC_LDRB_NONE                 ((unsigned int) 0x0 << 18) // (TC) Edge: None
#define 	AT91C_TC_LDRB_RISING               ((unsigned int) 0x1 << 18) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRB_FALLING              ((unsigned int) 0x2 << 18) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRB_BOTH                 ((unsigned int) 0x3 << 18) // (TC) Edge: each edge of TIOA
#define AT91C_TC_AEEVT        ((unsigned int) 0x3 << 20) // (TC) External Event Effect on TIOA
#define 	AT91C_TC_AEEVT_NONE                 ((unsigned int) 0x0 << 20) // (TC) Effect: none
#define 	AT91C_TC_AEEVT_SET                  ((unsigned int) 0x1 << 20) // (TC) Effect: set
#define 	AT91C_TC_AEEVT_CLEAR                ((unsigned int) 0x2 << 20) // (TC) Effect: clear
#define 	AT91C_TC_AEEVT_TOGGLE               ((unsigned int) 0x3 << 20) // (TC) Effect: toggle
#define AT91C_TC_ASWTRG       ((unsigned int) 0x3 << 22) // (TC) Software Trigger Effect on TIOA
#define 	AT91C_TC_ASWTRG_NONE                 ((unsigned int) 0x0 << 22) // (TC) Effect: none
#define 	AT91C_TC_ASWTRG_SET                  ((unsigned int) 0x1 << 22) // (TC) Effect: set
#define 	AT91C_TC_ASWTRG_CLEAR                ((unsigned int) 0x2 << 22) // (TC) Effect: clear
#define 	AT91C_TC_ASWTRG_TOGGLE               ((unsigned int) 0x3 << 22) // (TC) Effect: toggle
#define AT91C_TC_BCPB         ((unsigned int) 0x3 << 24) // (TC) RB Compare Effect on TIOB
#define 	AT91C_TC_BCPB_NONE                 ((unsigned int) 0x0 << 24) // (TC) Effect: none
#define 	AT91C_TC_BCPB_SET                  ((unsigned int) 0x1 << 24) // (TC) Effect: set
#define 	AT91C_TC_BCPB_CLEAR                ((unsigned int) 0x2 << 24) // (TC) Effect: clear
#define 	AT91C_TC_BCPB_TOGGLE               ((unsigned int) 0x3 << 24) // (TC) Effect: toggle
#define AT91C_TC_BCPC         ((unsigned int) 0x3 << 26) // (TC) RC Compare Effect on TIOB
#define 	AT91C_TC_BCPC_NONE                 ((unsigned int) 0x0 << 26) // (TC) Effect: none
#define 	AT91C_TC_BCPC_SET                  ((unsigned int) 0x1 << 26) // (TC) Effect: set
#define 	AT91C_TC_BCPC_CLEAR                ((unsigned int) 0x2 << 26) // (TC) Effect: clear
#define 	AT91C_TC_BCPC_TOGGLE               ((unsigned int) 0x3 << 26) // (TC) Effect: toggle
#define AT91C_TC_BEEVT        ((unsigned int) 0x3 << 28) // (TC) External Event Effect on TIOB
#define 	AT91C_TC_BEEVT_NONE                 ((unsigned int) 0x0 << 28) // (TC) Effect: none
#define 	AT91C_TC_BEEVT_SET                  ((unsigned int) 0x1 << 28) // (TC) Effect: set
#define 	AT91C_TC_BEEVT_CLEAR                ((unsigned int) 0x2 << 28) // (TC) Effect: clear
#define 	AT91C_TC_BEEVT_TOGGLE               ((unsigned int) 0x3 << 28) // (TC) Effect: toggle
#define AT91C_TC_BSWTRG       ((unsigned int) 0x3 << 30) // (TC) Software Trigger Effect on TIOB
#define 	AT91C_TC_BSWTRG_NONE                 ((unsigned int) 0x0 << 30) // (TC) Effect: none
#define 	AT91C_TC_BSWTRG_SET                  ((unsigned int) 0x1 << 30) // (TC) Effect: set
#define 	AT91C_TC_BSWTRG_CLEAR                ((unsigned int) 0x2 << 30) // (TC) Effect: clear
#define 	AT91C_TC_BSWTRG_TOGGLE               ((unsigned int) 0x3 << 30) // (TC) Effect: toggle
// -------- TC_SR : (TC Offset: 0x20) TC Channel Status Register -------- 
#define AT91C_TC_COVFS        ((unsigned int) 0x1 <<  0) // (TC) Counter Overflow
#define AT91C_TC_LOVRS        ((unsigned int) 0x1 <<  1) // (TC) Load Overrun
#define AT91C_TC_CPAS         ((unsigned int) 0x1 <<  2) // (TC) RA Compare
#define AT91C_TC_CPBS         ((unsigned int) 0x1 <<  3) // (TC) RB Compare
#define AT91C_TC_CPCS         ((unsigned int) 0x1 <<  4) // (TC) RC Compare
#define AT91C_TC_LDRAS        ((unsigned int) 0x1 <<  5) // (TC) RA Loading
#define AT91C_TC_LDRBS        ((unsigned int) 0x1 <<  6) // (TC) RB Loading
#define AT91C_TC_ETRGS        ((unsigned int) 0x1 <<  7) // (TC) External Trigger
#define AT91C_TC_CLKSTA       ((unsigned int) 0x1 << 16) // (TC) Clock Enabling
#define AT91C_TC_MTIOA        ((unsigned int) 0x1 << 17) // (TC) TIOA Mirror
#define AT91C_TC_MTIOB        ((unsigned int) 0x1 << 18) // (TC) TIOA Mirror
// -------- TC_IER : (TC Offset: 0x24) TC Channel Interrupt Enable Register -------- 
// -------- TC_IDR : (TC Offset: 0x28) TC Channel Interrupt Disable Register -------- 
// -------- TC_IMR : (TC Offset: 0x2c) TC Channel Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Two-wire Interface
// *****************************************************************************
typedef struct _AT91S_TWI {
	AT91_REG	 TWI_CR; 	// Control Register
	AT91_REG	 TWI_MMR; 	// Master Mode Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 TWI_IADR; 	// Internal Address Register
	AT91_REG	 TWI_CWGR; 	// Clock Waveform Generator Register
	AT91_REG	 Reserved1[3]; 	// 
	AT91_REG	 TWI_SR; 	// Status Register
	AT91_REG	 TWI_IER; 	// Interrupt Enable Register
	AT91_REG	 TWI_IDR; 	// Interrupt Disable Register
	AT91_REG	 TWI_IMR; 	// Interrupt Mask Register
	AT91_REG	 TWI_RHR; 	// Receive Holding Register
	AT91_REG	 TWI_THR; 	// Transmit Holding Register
} AT91S_TWI, *AT91PS_TWI;

// -------- TWI_CR : (TWI Offset: 0x0) TWI Control Register -------- 
#define AT91C_TWI_START       ((unsigned int) 0x1 <<  0) // (TWI) Send a START Condition
#define AT91C_TWI_STOP        ((unsigned int) 0x1 <<  1) // (TWI) Send a STOP Condition
#define AT91C_TWI_MSEN        ((unsigned int) 0x1 <<  2) // (TWI) TWI Master Transfer Enabled
#define AT91C_TWI_MSDIS       ((unsigned int) 0x1 <<  3) // (TWI) TWI Master Transfer Disabled
#define AT91C_TWI_SWRST       ((unsigned int) 0x1 <<  7) // (TWI) Software Reset
// -------- TWI_MMR : (TWI Offset: 0x4) TWI Master Mode Register -------- 
#define AT91C_TWI_IADRSZ      ((unsigned int) 0x3 <<  8) // (TWI) Internal Device Address Size
#define 	AT91C_TWI_IADRSZ_NO                   ((unsigned int) 0x0 <<  8) // (TWI) No internal device address
#define 	AT91C_TWI_IADRSZ_1_BYTE               ((unsigned int) 0x1 <<  8) // (TWI) One-byte internal device address
#define 	AT91C_TWI_IADRSZ_2_BYTE               ((unsigned int) 0x2 <<  8) // (TWI) Two-byte internal device address
#define 	AT91C_TWI_IADRSZ_3_BYTE               ((unsigned int) 0x3 <<  8) // (TWI) Three-byte internal device address
#define AT91C_TWI_MREAD       ((unsigned int) 0x1 << 12) // (TWI) Master Read Direction
#define AT91C_TWI_DADR        ((unsigned int) 0x7F << 16) // (TWI) Device Address
// -------- TWI_CWGR : (TWI Offset: 0x10) TWI Clock Waveform Generator Register -------- 
#define AT91C_TWI_CLDIV       ((unsigned int) 0xFF <<  0) // (TWI) Clock Low Divider
#define AT91C_TWI_CHDIV       ((unsigned int) 0xFF <<  8) // (TWI) Clock High Divider
#define AT91C_TWI_CKDIV       ((unsigned int) 0x7 << 16) // (TWI) Clock Divider
// -------- TWI_SR : (TWI Offset: 0x20) TWI Status Register -------- 
#define AT91C_TWI_TXCOMP      ((unsigned int) 0x1 <<  0) // (TWI) Transmission Completed
#define AT91C_TWI_RXRDY       ((unsigned int) 0x1 <<  1) // (TWI) Receive holding register ReaDY
#define AT91C_TWI_TXRDY       ((unsigned int) 0x1 <<  2) // (TWI) Transmit holding register ReaDY
#define AT91C_TWI_OVRE        ((unsigned int) 0x1 <<  6) // (TWI) Overrun Error
#define AT91C_TWI_UNRE        ((unsigned int) 0x1 <<  7) // (TWI) Underrun Error
#define AT91C_TWI_NACK        ((unsigned int) 0x1 <<  8) // (TWI) Not Acknowledged
// -------- TWI_IER : (TWI Offset: 0x24) TWI Interrupt Enable Register -------- 
// -------- TWI_IDR : (TWI Offset: 0x28) TWI Interrupt Disable Register -------- 
// -------- TWI_IMR : (TWI Offset: 0x2c) TWI Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Usart
// *****************************************************************************
typedef struct _AT91S_USART {
	AT91_REG	 US_CR; 	// Control Register
	AT91_REG	 US_MR; 	// Mode Register
	AT91_REG	 US_IER; 	// Interrupt Enable Register
	AT91_REG	 US_IDR; 	// Interrupt Disable Register
	AT91_REG	 US_IMR; 	// Interrupt Mask Register
	AT91_REG	 US_CSR; 	// Channel Status Register
	AT91_REG	 US_RHR; 	// Receiver Holding Register
	AT91_REG	 US_THR; 	// Transmitter Holding Register
	AT91_REG	 US_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 US_RTOR; 	// Receiver Time-out Register
	AT91_REG	 US_TTGR; 	// Transmitter Time-guard Register
	AT91_REG	 Reserved0[5]; 	// 
	AT91_REG	 US_FIDI; 	// FI_DI_Ratio Register
	AT91_REG	 US_NER; 	// Nb Errors Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 US_IF; 	// IRDA_FILTER Register
	AT91_REG	 Reserved2[44]; 	// 
	AT91_REG	 US_RPR; 	// Receive Pointer Register
	AT91_REG	 US_RCR; 	// Receive Counter Register
	AT91_REG	 US_TPR; 	// Transmit Pointer Register
	AT91_REG	 US_TCR; 	// Transmit Counter Register
	AT91_REG	 US_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 US_RNCR; 	// Receive Next Counter Register
	AT91_REG	 US_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 US_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 US_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 US_PTSR; 	// PDC Transfer Status Register
} AT91S_USART, *AT91PS_USART;

// -------- US_CR : (USART Offset: 0x0) Debug Unit Control Register -------- 
#define AT91C_US_RSTRX        ((unsigned int) 0x1 <<  2) // (USART) Reset Receiver 
#define AT91C_US_RSTTX        ((unsigned int) 0x1 <<  3) // (USART) 
#define AT91C_US_RXEN         ((unsigned int) 0x1 <<  4) // (USART) 
#define AT91C_US_RXDIS        ((unsigned int) 0x1 <<  5) // (USART)
#define AT91C_US_TXEN         ((unsigned int) 0x1 <<  6) // (USART) 
#define AT91C_US_TXDIS        ((unsigned int) 0x1 <<  7) // (USART)
#define AT91C_US_RSTSTA       ((unsigned int) 0x1 <<  8) // (USART)
#define AT91C_US_STTBRK       ((unsigned int) 0x1 <<  9) // (USART) Start Break
#define AT91C_US_STPBRK       ((unsigned int) 0x1 << 10) // (USART) Stop Break
#define AT91C_US_STTTO        ((unsigned int) 0x1 << 11) // (USART) Start Time-out
#define AT91C_US_SENDA        ((unsigned int) 0x1 << 12) // (USART) Send Address
#define AT91C_US_RSTIT        ((unsigned int) 0x1 << 13) // (USART) Reset Iterations
#define AT91C_US_RSTNACK      ((unsigned int) 0x1 << 14) // (USART) Reset Non Acknowledge
#define AT91C_US_RETTO        ((unsigned int) 0x1 << 15) // (USART) Rearm Time-out
#define AT91C_US_DTREN        ((unsigned int) 0x1 << 16) // (USART) Data Terminal ready Enable
#define AT91C_US_DTRDIS       ((unsigned int) 0x1 << 17) // (USART) Data Terminal ready Disable
#define AT91C_US_RTSEN        ((unsigned int) 0x1 << 18) // (USART) Request to Send enable
#define AT91C_US_RTSDIS       ((unsigned int) 0x1 << 19) // (USART) Request to Send Disable
// -------- US_MR : (USART Offset: 0x4) Debug Unit Mode Register -------- 
#define AT91C_US_USMODE       ((unsigned int) 0xF <<  0) // (USART) Usart mode
#define 	AT91C_US_USMODE_NORMAL               ((unsigned int) 0x0) // (USART) Normal
#define 	AT91C_US_USMODE_RS485                ((unsigned int) 0x1) // (USART) RS485
#define 	AT91C_US_USMODE_HWHSH                ((unsigned int) 0x2) // (USART) Hardware Handshaking
#define 	AT91C_US_USMODE_MODEM                ((unsigned int) 0x3) // (USART) Modem
#define 	AT91C_US_USMODE_ISO7816_0            ((unsigned int) 0x4) // (USART) ISO7816 protocol: T = 0
#define 	AT91C_US_USMODE_ISO7816_1            ((unsigned int) 0x6) // (USART) ISO7816 protocol: T = 1
#define 	AT91C_US_USMODE_IRDA                 ((unsigned int) 0x8) // (USART) IrDA
#define 	AT91C_US_USMODE_SWHSH                ((unsigned int) 0xC) // (USART) Software Handshaking
#define AT91C_US_CLKS         ((unsigned int) 0x3 <<  4) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CLKS_CLOCK                ((unsigned int) 0x0 <<  4) // (USART) Clock
#define 	AT91C_US_CLKS_FDIV1                ((unsigned int) 0x1 <<  4) // (USART) fdiv1
#define 	AT91C_US_CLKS_SLOW                 ((unsigned int) 0x2 <<  4) // (USART) slow_clock (ARM)
#define 	AT91C_US_CLKS_EXT                  ((unsigned int) 0x3 <<  4) // (USART) External (SCK)
#define AT91C_US_CHRL         ((unsigned int) 0x3 <<  6) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CHRL_5_BITS               ((unsigned int) 0x0 <<  6) // (USART) Character Length: 5 bits
#define 	AT91C_US_CHRL_6_BITS               ((unsigned int) 0x1 <<  6) // (USART) Character Length: 6 bits
#define 	AT91C_US_CHRL_7_BITS               ((unsigned int) 0x2 <<  6) // (USART) Character Length: 7 bits
#define 	AT91C_US_CHRL_8_BITS               ((unsigned int) 0x3 <<  6) // (USART) Character Length: 8 bits
#define AT91C_US_SYNC         ((unsigned int) 0x1 <<  8) // (USART) Synchronous Mode Select
#define        AT91C_US_PAR_EVEN          ((unsigned int) 0x0 <<  9) // (USART)
#define        AT91C_US_PAR_ODD           ((unsigned int) 0x1 <<  9) // (USART)
#define        AT91C_US_PAR_SPACE         ((unsigned int) 0x2 <<  9) // (USART)
#define        AT91C_US_PAR_MARK          ((unsigned int) 0x3 <<  9) // (USART)
#define        AT91C_US_PAR_NONE          ((unsigned int) 0x4 <<  9) // (USART)
#define        AT91C_US_PAR_MULTIDROP     ((unsigned int) 0x6 <<  9) // (USART)
#define AT91C_US_NBSTOP       ((unsigned int) 0x3 << 12) // (USART) Number of Stop bits
#define 	AT91C_US_NBSTOP_1_BIT                ((unsigned int) 0x0 << 12) // (USART) 1 stop bit
#define 	AT91C_US_NBSTOP_15_BIT               ((unsigned int) 0x1 << 12) // (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits
#define 	AT91C_US_NBSTOP_2_BIT                ((unsigned int) 0x2 << 12) // (USART) 2 stop bits
#define AT91C_US_MSBF         ((unsigned int) 0x1 << 16) // (USART) Bit Order
#define AT91C_US_MODE9        ((unsigned int) 0x1 << 17) // (USART) 9-bit Character length
#define AT91C_US_CKLO         ((unsigned int) 0x1 << 18) // (USART) Clock Output Select
#define AT91C_US_OVER         ((unsigned int) 0x1 << 19) // (USART) Over Sampling Mode
#define AT91C_US_INACK        ((unsigned int) 0x1 << 20) // (USART) Inhibit Non Acknowledge
#define AT91C_US_DSNACK       ((unsigned int) 0x1 << 21) // (USART) Disable Successive NACK
#define AT91C_US_MAX_ITER     ((unsigned int) 0x1 << 24) // (USART) Number of Repetitions
#define AT91C_US_FILTER       ((unsigned int) 0x1 << 28) // (USART) Receive Line Filter
// -------- US_IER : (USART Offset: 0x8) Debug Unit Interrupt Enable Register -------- 
#define AT91C_US_RXBRK        ((unsigned int) 0x1 <<  2) // (USART) Break Received/End of Break
#define AT91C_US_TIMEOUT      ((unsigned int) 0x1 <<  8) // (USART) Receiver Time-out
#define AT91C_US_ITERATION    ((unsigned int) 0x1 << 10) // (USART) Max number of Repetitions Reached
#define AT91C_US_NACK         ((unsigned int) 0x1 << 13) // (USART) Non Acknowledge
#define AT91C_US_RIIC         ((unsigned int) 0x1 << 16) // (USART) Ring INdicator Input Change Flag
#define AT91C_US_DSRIC        ((unsigned int) 0x1 << 17) // (USART) Data Set Ready Input Change Flag
#define AT91C_US_DCDIC        ((unsigned int) 0x1 << 18) // (USART) Data Carrier Flag
#define AT91C_US_CTSIC        ((unsigned int) 0x1 << 19) // (USART) Clear To Send Input Change Flag
// -------- US_IDR : (USART Offset: 0xc) Debug Unit Interrupt Disable Register -------- 
// -------- US_IMR : (USART Offset: 0x10) Debug Unit Interrupt Mask Register -------- 
#define AT91C_US_RXRDY        ((unsigned int) 0x1 <<  0) // (USART)
#define AT91C_US_TXRDY        ((unsigned int) 0x1 <<  1) // (USART)
#define AT91C_US_OVRE         ((unsigned int) 0x1 <<  5) // (USART)
#define AT91C_US_FRAME        ((unsigned int) 0x1 <<  6) // (USART)
#define AT91C_US_PARE        ((unsigned int) 0x1 <<  7) // (USART)
// -------- US_CSR : (USART Offset: 0x14) Debug Unit Channel Status Register -------- 
#define AT91C_US_RI           ((unsigned int) 0x1 << 20) // (USART) Image of RI Input
#define AT91C_US_DSR          ((unsigned int) 0x1 << 21) // (USART) Image of DSR Input
#define AT91C_US_DCD          ((unsigned int) 0x1 << 22) // (USART) Image of DCD Input
#define AT91C_US_CTS          ((unsigned int) 0x1 << 23) // (USART) Image of CTS Input

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR USB Device Interface
// *****************************************************************************
typedef struct _AT91S_UDP {
	AT91_REG	 UDP_NUM; 	// Frame Number Register
	AT91_REG	 UDP_GLBSTATE; 	// Global State Register
	AT91_REG	 UDP_FADDR; 	// Function Address Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 UDP_IER; 	// Interrupt Enable Register
	AT91_REG	 UDP_IDR; 	// Interrupt Disable Register
	AT91_REG	 UDP_IMR; 	// Interrupt Mask Register
	AT91_REG	 UDP_ISR; 	// Interrupt Status Register
	AT91_REG	 UDP_ICR; 	// Interrupt Clear Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 UDP_RSTEP; 	// Reset Endpoint Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 UDP_CSR[4]; 	// Endpoint Control and Status Register
	AT91_REG	 Reserved3[4]; 	// 
	AT91_REG	 UDP_FDR[4]; 	// Endpoint FIFO Data Register
	AT91_REG	 Reserved4[5]; 	// 
	AT91_REG	 UDP_TXVC; 	// Transceiver Control Register
} AT91S_UDP, *AT91PS_UDP;

// -------- UDP_FRM_NUM : (UDP Offset: 0x0) USB Frame Number Register -------- 
#define AT91C_UDP_FRM_NUM     ((unsigned int) 0x7FF <<  0) // (UDP) Frame Number as Defined in the Packet Field Formats
#define AT91C_UDP_FRM_ERR     ((unsigned int) 0x1 << 16) // (UDP) Frame Error
#define AT91C_UDP_FRM_OK      ((unsigned int) 0x1 << 17) // (UDP) Frame OK
// -------- UDP_GLB_STATE : (UDP Offset: 0x4) USB Global State Register -------- 
#define AT91C_UDP_FADDEN      ((unsigned int) 0x1 <<  0) // (UDP) Function Address Enable
#define AT91C_UDP_CONFG       ((unsigned int) 0x1 <<  1) // (UDP) Configured
#define AT91C_UDP_ESR         ((unsigned int) 0x1 <<  2) // (UDP) Enable Send Resume
#define AT91C_UDP_RSMINPR     ((unsigned int) 0x1 <<  3) // (UDP) A Resume Has Been Sent to the Host
#define AT91C_UDP_RMWUPE      ((unsigned int) 0x1 <<  4) // (UDP) Remote Wake Up Enable
// -------- UDP_FADDR : (UDP Offset: 0x8) USB Function Address Register -------- 
#define AT91C_UDP_FADD        ((unsigned int) 0xFF <<  0) // (UDP) Function Address Value
#define AT91C_UDP_FEN         ((unsigned int) 0x1 <<  8) // (UDP) Function Enable
// -------- UDP_IER : (UDP Offset: 0x10) USB Interrupt Enable Register -------- 
#define AT91C_UDP_EPINT0      ((unsigned int) 0x1 <<  0) // (UDP) Endpoint 0 Interrupt
#define AT91C_UDP_EPINT1      ((unsigned int) 0x1 <<  1) // (UDP) Endpoint 0 Interrupt
#define AT91C_UDP_EPINT2      ((unsigned int) 0x1 <<  2) // (UDP) Endpoint 2 Interrupt
#define AT91C_UDP_EPINT3      ((unsigned int) 0x1 <<  3) // (UDP) Endpoint 3 Interrupt
#define AT91C_UDP_RXSUSP      ((unsigned int) 0x1 <<  8) // (UDP) USB Suspend Interrupt
#define AT91C_UDP_RXRSM       ((unsigned int) 0x1 <<  9) // (UDP) USB Resume Interrupt
#define AT91C_UDP_EXTRSM      ((unsigned int) 0x1 << 10) // (UDP) USB External Resume Interrupt
#define AT91C_UDP_SOFINT      ((unsigned int) 0x1 << 11) // (UDP) USB Start Of frame Interrupt
#define AT91C_UDP_WAKEUP      ((unsigned int) 0x1 << 13) // (UDP) USB Resume Interrupt
// -------- UDP_IDR : (UDP Offset: 0x14) USB Interrupt Disable Register -------- 
// -------- UDP_IMR : (UDP Offset: 0x18) USB Interrupt Mask Register -------- 
// -------- UDP_ISR : (UDP Offset: 0x1c) USB Interrupt Status Register -------- 
#define AT91C_UDP_ENDBUSRES   ((unsigned int) 0x1 << 12) // (UDP) USB End Of Bus Reset Interrupt
// -------- UDP_ICR : (UDP Offset: 0x20) USB Interrupt Clear Register -------- 
// -------- UDP_RST_EP : (UDP Offset: 0x28) USB Reset Endpoint Register -------- 
#define AT91C_UDP_EP0         ((unsigned int) 0x1 <<  0) // (UDP) Reset Endpoint 0
#define AT91C_UDP_EP1         ((unsigned int) 0x1 <<  1) // (UDP) Reset Endpoint 1
#define AT91C_UDP_EP2         ((unsigned int) 0x1 <<  2) // (UDP) Reset Endpoint 2
#define AT91C_UDP_EP3         ((unsigned int) 0x1 <<  3) // (UDP) Reset Endpoint 3
// -------- UDP_CSR : (UDP Offset: 0x30) USB Endpoint Control and Status Register -------- 
#define AT91C_UDP_TXCOMP      ((unsigned int) 0x1 <<  0) // (UDP) Generates an IN packet with data previously written in the DPR
#define AT91C_UDP_RX_DATA_BK0 ((unsigned int) 0x1 <<  1) // (UDP) Receive Data Bank 0
#define AT91C_UDP_RXSETUP     ((unsigned int) 0x1 <<  2) // (UDP) Sends STALL to the Host (Control endpoints)
#define AT91C_UDP_ISOERROR    ((unsigned int) 0x1 <<  3) // (UDP) Isochronous error (Isochronous endpoints)
#define AT91C_UDP_TXPKTRDY    ((unsigned int) 0x1 <<  4) // (UDP) Transmit Packet Ready
#define AT91C_UDP_FORCESTALL  ((unsigned int) 0x1 <<  5) // (UDP) Force Stall (used by Control, Bulk and Isochronous endpoints).
#define AT91C_UDP_RX_DATA_BK1 ((unsigned int) 0x1 <<  6) // (UDP) Receive Data Bank 1 (only used by endpoints with ping-pong attributes).
#define AT91C_UDP_DIR         ((unsigned int) 0x1 <<  7) // (UDP) Transfer Direction
#define AT91C_UDP_EPTYPE      ((unsigned int) 0x7 <<  8) // (UDP) Endpoint type
#define 	AT91C_UDP_EPTYPE_CTRL                 ((unsigned int) 0x0 <<  8) // (UDP) Control
#define 	AT91C_UDP_EPTYPE_ISO_OUT              ((unsigned int) 0x1 <<  8) // (UDP) Isochronous OUT
#define 	AT91C_UDP_EPTYPE_BULK_OUT             ((unsigned int) 0x2 <<  8) // (UDP) Bulk OUT
#define 	AT91C_UDP_EPTYPE_INT_OUT              ((unsigned int) 0x3 <<  8) // (UDP) Interrupt OUT
#define 	AT91C_UDP_EPTYPE_ISO_IN               ((unsigned int) 0x5 <<  8) // (UDP) Isochronous IN
#define 	AT91C_UDP_EPTYPE_BULK_IN              ((unsigned int) 0x6 <<  8) // (UDP) Bulk IN
#define 	AT91C_UDP_EPTYPE_INT_IN               ((unsigned int) 0x7 <<  8) // (UDP) Interrupt IN
#define AT91C_UDP_DTGLE       ((unsigned int) 0x1 << 11) // (UDP) Data Toggle
#define AT91C_UDP_EPEDS       ((unsigned int) 0x1 << 15) // (UDP) Endpoint Enable Disable
#define AT91C_UDP_RXBYTECNT   ((unsigned int) 0x7FF << 16) // (UDP) Number Of Bytes Available in the FIFO
// -------- UDP_TXVC : (UDP Offset: 0x74) Transceiver Control Register -------- 
#define AT91C_UDP_TXVDIS      ((unsigned int) 0x1 <<  8) // (UDP) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Analog to Digital Convertor
// *****************************************************************************
typedef struct _AT91S_ADC {
	AT91_REG	 ADC_CR; 	// ADC Control Register
	AT91_REG	 ADC_MR; 	// ADC Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 ADC_CHER; 	// ADC Channel Enable Register
	AT91_REG	 ADC_CHDR; 	// ADC Channel Disable Register
	AT91_REG	 ADC_CHSR; 	// ADC Channel Status Register
	AT91_REG	 ADC_SR; 	// ADC Status Register
	AT91_REG	 ADC_LCDR; 	// ADC Last Converted Data Register
	AT91_REG	 ADC_IER; 	// ADC Interrupt Enable Register
	AT91_REG	 ADC_IDR; 	// ADC Interrupt Disable Register
	AT91_REG	 ADC_IMR; 	// ADC Interrupt Mask Register
	AT91_REG	 ADC_CDR0; 	// ADC Channel Data Register 0
	AT91_REG	 ADC_CDR1; 	// ADC Channel Data Register 1
	AT91_REG	 ADC_CDR2; 	// ADC Channel Data Register 2
	AT91_REG	 ADC_CDR3; 	// ADC Channel Data Register 3
	AT91_REG	 ADC_CDR4; 	// ADC Channel Data Register 4
	AT91_REG	 ADC_CDR5; 	// ADC Channel Data Register 5
	AT91_REG	 ADC_CDR6; 	// ADC Channel Data Register 6
	AT91_REG	 ADC_CDR7; 	// ADC Channel Data Register 7
	AT91_REG	 Reserved1[44]; 	// 
	AT91_REG	 ADC_RPR; 	// Receive Pointer Register
	AT91_REG	 ADC_RCR; 	// Receive Counter Register
	AT91_REG	 ADC_TPR; 	// Transmit Pointer Register
	AT91_REG	 ADC_TCR; 	// Transmit Counter Register
	AT91_REG	 ADC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 ADC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 ADC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 ADC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 ADC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 ADC_PTSR; 	// PDC Transfer Status Register
} AT91S_ADC, *AT91PS_ADC;

// -------- ADC_CR : (ADC Offset: 0x0) ADC Control Register -------- 
#define AT91C_ADC_SWRST       ((unsigned int) 0x1 <<  0) // (ADC) Software Reset
#define AT91C_ADC_START       ((unsigned int) 0x1 <<  1) // (ADC) Start Conversion
// -------- ADC_MR : (ADC Offset: 0x4) ADC Mode Register -------- 
#define AT91C_ADC_TRGEN       ((unsigned int) 0x1 <<  0) // (ADC) Trigger Enable
#define 	AT91C_ADC_TRGEN_DIS                  ((unsigned int) 0x0) // (ADC) Hradware triggers are disabled. Starting a conversion is only possible by software
#define 	AT91C_ADC_TRGEN_EN                   ((unsigned int) 0x1) // (ADC) Hardware trigger selected by TRGSEL field is enabled.
#define AT91C_ADC_TRGSEL      ((unsigned int) 0x7 <<  1) // (ADC) Trigger Selection
#define 	AT91C_ADC_TRGSEL_TIOA0                ((unsigned int) 0x0 <<  1) // (ADC) Selected TRGSEL = TIAO0
#define 	AT91C_ADC_TRGSEL_TIOA1                ((unsigned int) 0x1 <<  1) // (ADC) Selected TRGSEL = TIAO1
#define 	AT91C_ADC_TRGSEL_TIOA2                ((unsigned int) 0x2 <<  1) // (ADC) Selected TRGSEL = TIAO2
#define 	AT91C_ADC_TRGSEL_TIOA3                ((unsigned int) 0x3 <<  1) // (ADC) Selected TRGSEL = TIAO3
#define 	AT91C_ADC_TRGSEL_TIOA4                ((unsigned int) 0x4 <<  1) // (ADC) Selected TRGSEL = TIAO4
#define 	AT91C_ADC_TRGSEL_TIOA5                ((unsigned int) 0x5 <<  1) // (ADC) Selected TRGSEL = TIAO5
#define 	AT91C_ADC_TRGSEL_EXT                  ((unsigned int) 0x6 <<  1) // (ADC) Selected TRGSEL = External Trigger
#define AT91C_ADC_LOWRES      ((unsigned int) 0x1 <<  4) // (ADC) Resolution.
#define 	AT91C_ADC_LOWRES_10_BIT               ((unsigned int) 0x0 <<  4) // (ADC) 10-bit resolution
#define 	AT91C_ADC_LOWRES_8_BIT                ((unsigned int) 0x1 <<  4) // (ADC) 8-bit resolution
#define AT91C_ADC_SLEEP       ((unsigned int) 0x1 <<  5) // (ADC) Sleep Mode
#define 	AT91C_ADC_SLEEP_NORMAL_MODE          ((unsigned int) 0x0 <<  5) // (ADC) Normal Mode
#define 	AT91C_ADC_SLEEP_MODE                 ((unsigned int) 0x1 <<  5) // (ADC) Sleep Mode
#define AT91C_ADC_PRESCAL     ((unsigned int) 0x3F <<  8) // (ADC) Prescaler rate selection
#define AT91C_ADC_STARTUP     ((unsigned int) 0x1F << 16) // (ADC) Startup Time
#define AT91C_ADC_SHTIM       ((unsigned int) 0xF << 24) // (ADC) Sample & Hold Time
// -------- 	ADC_CHER : (ADC Offset: 0x10) ADC Channel Enable Register -------- 
#define AT91C_ADC_CH0         ((unsigned int) 0x1 <<  0) // (ADC) Channel 0
#define AT91C_ADC_CH1         ((unsigned int) 0x1 <<  1) // (ADC) Channel 1
#define AT91C_ADC_CH2         ((unsigned int) 0x1 <<  2) // (ADC) Channel 2
#define AT91C_ADC_CH3         ((unsigned int) 0x1 <<  3) // (ADC) Channel 3
#define AT91C_ADC_CH4         ((unsigned int) 0x1 <<  4) // (ADC) Channel 4
#define AT91C_ADC_CH5         ((unsigned int) 0x1 <<  5) // (ADC) Channel 5
#define AT91C_ADC_CH6         ((unsigned int) 0x1 <<  6) // (ADC) Channel 6
#define AT91C_ADC_CH7         ((unsigned int) 0x1 <<  7) // (ADC) Channel 7
// -------- 	ADC_CHDR : (ADC Offset: 0x14) ADC Channel Disable Register -------- 
// -------- 	ADC_CHSR : (ADC Offset: 0x18) ADC Channel Status Register -------- 
// -------- ADC_SR : (ADC Offset: 0x1c) ADC Status Register -------- 
#define AT91C_ADC_EOC0        ((unsigned int) 0x1 <<  0) // (ADC) End of Conversion
#define AT91C_ADC_EOC1        ((unsigned int) 0x1 <<  1) // (ADC) End of Conversion
#define AT91C_ADC_EOC2        ((unsigned int) 0x1 <<  2) // (ADC) End of Conversion
#define AT91C_ADC_EOC3        ((unsigned int) 0x1 <<  3) // (ADC) End of Conversion
#define AT91C_ADC_EOC4        ((unsigned int) 0x1 <<  4) // (ADC) End of Conversion
#define AT91C_ADC_EOC5        ((unsigned int) 0x1 <<  5) // (ADC) End of Conversion
#define AT91C_ADC_EOC6        ((unsigned int) 0x1 <<  6) // (ADC) End of Conversion
#define AT91C_ADC_EOC7        ((unsigned int) 0x1 <<  7) // (ADC) End of Conversion
#define AT91C_ADC_OVRE0       ((unsigned int) 0x1 <<  8) // (ADC) Overrun Error
#define AT91C_ADC_OVRE1       ((unsigned int) 0x1 <<  9) // (ADC) Overrun Error
#define AT91C_ADC_OVRE2       ((unsigned int) 0x1 << 10) // (ADC) Overrun Error
#define AT91C_ADC_OVRE3       ((unsigned int) 0x1 << 11) // (ADC) Overrun Error
#define AT91C_ADC_OVRE4       ((unsigned int) 0x1 << 12) // (ADC) Overrun Error
#define AT91C_ADC_OVRE5       ((unsigned int) 0x1 << 13) // (ADC) Overrun Error
#define AT91C_ADC_OVRE6       ((unsigned int) 0x1 << 14) // (ADC) Overrun Error
#define AT91C_ADC_OVRE7       ((unsigned int) 0x1 << 15) // (ADC) Overrun Error
#define AT91C_ADC_DRDY        ((unsigned int) 0x1 << 16) // (ADC) Data Ready
#define AT91C_ADC_GOVRE       ((unsigned int) 0x1 << 17) // (ADC) General Overrun
#define AT91C_ADC_ENDRX       ((unsigned int) 0x1 << 18) // (ADC) End of Receiver Transfer
#define AT91C_ADC_RXBUFF      ((unsigned int) 0x1 << 19) // (ADC) RXBUFF Interrupt
// -------- ADC_LCDR : (ADC Offset: 0x20) ADC Last Converted Data Register -------- 
#define AT91C_ADC_LDATA       ((unsigned int) 0x3FF <<  0) // (ADC) Last Data Converted
// -------- ADC_IER : (ADC Offset: 0x24) ADC Interrupt Enable Register -------- 
// -------- ADC_IDR : (ADC Offset: 0x28) ADC Interrupt Disable Register -------- 
// -------- ADC_IMR : (ADC Offset: 0x2c) ADC Interrupt Mask Register -------- 
// -------- ADC_CDR0 : (ADC Offset: 0x30) ADC Channel Data Register 0 -------- 
#define AT91C_ADC_DATA        ((unsigned int) 0x3FF <<  0) // (ADC) Converted Data
// -------- ADC_CDR1 : (ADC Offset: 0x34) ADC Channel Data Register 1 -------- 
// -------- ADC_CDR2 : (ADC Offset: 0x38) ADC Channel Data Register 2 -------- 
// -------- ADC_CDR3 : (ADC Offset: 0x3c) ADC Channel Data Register 3 -------- 
// -------- ADC_CDR4 : (ADC Offset: 0x40) ADC Channel Data Register 4 -------- 
// -------- ADC_CDR5 : (ADC Offset: 0x44) ADC Channel Data Register 5 -------- 
// -------- ADC_CDR6 : (ADC Offset: 0x48) ADC Channel Data Register 6 -------- 
// -------- ADC_CDR7 : (ADC Offset: 0x4c) ADC Channel Data Register 7 -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Timer Counter Interface
// *****************************************************************************
typedef struct _AT91S_TCB {
	AT91S_TC	 TCB_TC0; 	// TC Channel 0
	AT91_REG	 Reserved0[4]; 	// 
	AT91S_TC	 TCB_TC1; 	// TC Channel 1
	AT91_REG	 Reserved1[4]; 	// 
	AT91S_TC	 TCB_TC2; 	// TC Channel 2
	AT91_REG	 Reserved2[4]; 	// 
	AT91_REG	 TCB_BCR; 	// TC Block Control Register
	AT91_REG	 TCB_BMR; 	// TC Block Mode Register
} AT91S_TCB, *AT91PS_TCB;

// -------- TCB_BCR : (TCB Offset: 0xc0) TC Block Control Register -------- 
#define AT91C_TCB_SYNC        ((unsigned int) 0x1 <<  0) // (TCB) Synchro Command
// -------- TCB_BMR : (TCB Offset: 0xc4) TC Block Mode Register -------- 
#define AT91C_TCB_TC0XC0S     ((unsigned int) 0x3 <<  0) // (TCB) External Clock Signal 0 Selection
#define 	AT91C_TCB_TC0XC0S_TCLK0                ((unsigned int) 0x0) // (TCB) TCLK0 connected to XC0
#define 	AT91C_TCB_TC0XC0S_NONE                 ((unsigned int) 0x1) // (TCB) None signal connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA1                ((unsigned int) 0x2) // (TCB) TIOA1 connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA2                ((unsigned int) 0x3) // (TCB) TIOA2 connected to XC0
#define AT91C_TCB_TC1XC1S     ((unsigned int) 0x3 <<  2) // (TCB) External Clock Signal 1 Selection
#define 	AT91C_TCB_TC1XC1S_TCLK1                ((unsigned int) 0x0 <<  2) // (TCB) TCLK1 connected to XC1
#define 	AT91C_TCB_TC1XC1S_NONE                 ((unsigned int) 0x1 <<  2) // (TCB) None signal connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA0                ((unsigned int) 0x2 <<  2) // (TCB) TIOA0 connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA2                ((unsigned int) 0x3 <<  2) // (TCB) TIOA2 connected to XC1
#define AT91C_TCB_TC2XC2S     ((unsigned int) 0x3 <<  4) // (TCB) External Clock Signal 2 Selection
#define 	AT91C_TCB_TC2XC2S_TCLK2                ((unsigned int) 0x0 <<  4) // (TCB) TCLK2 connected to XC2
#define 	AT91C_TCB_TC2XC2S_NONE                 ((unsigned int) 0x1 <<  4) // (TCB) None signal connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA0                ((unsigned int) 0x2 <<  4) // (TCB) TIOA0 connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA1                ((unsigned int) 0x3 <<  4) // (TCB) TIOA2 connected to XC2

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR PWMC Channel Interface
// *****************************************************************************
typedef struct _AT91S_PWMC_CH {
	AT91_REG	 PWMC_CMR; 	// Channel Mode Register
	AT91_REG	 PWMC_CDTYR; 	// Channel Duty Cycle Register
	AT91_REG	 PWMC_CPRDR; 	// Channel Period Register
	AT91_REG	 PWMC_CCNTR; 	// Channel Counter Register
	AT91_REG	 PWMC_CUPDR; 	// Channel Update Register
	AT91_REG	 PWMC_Reserved[3]; 	// Reserved
} AT91S_PWMC_CH, *AT91PS_PWMC_CH;

// -------- PWMC_CMR : (PWMC_CH Offset: 0x0) PWMC Channel Mode Register -------- 
#define AT91C_PWMC_CPRE       ((unsigned int) 0xF <<  0) // (PWMC_CH) Channel Pre-scaler : PWMC_CLKx
#define 	AT91C_PWMC_CPRE_MCK                  ((unsigned int) 0x0) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCKA                 ((unsigned int) 0xB) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCKB                 ((unsigned int) 0xC) // (PWMC_CH) 
#define AT91C_PWMC_CALG       ((unsigned int) 0x1 <<  8) // (PWMC_CH) Channel Alignment
#define AT91C_PWMC_CPOL       ((unsigned int) 0x1 <<  9) // (PWMC_CH) Channel Polarity
#define AT91C_PWMC_CPD        ((unsigned int) 0x1 << 10) // (PWMC_CH) Channel Update Period
// -------- PWMC_CDTYR : (PWMC_CH Offset: 0x4) PWMC Channel Duty Cycle Register -------- 
#define AT91C_PWMC_CDTY       ((unsigned int) 0x0 <<  0) // (PWMC_CH) Channel Duty Cycle
// -------- PWMC_CPRDR : (PWMC_CH Offset: 0x8) PWMC Channel Period Register -------- 
#define AT91C_PWMC_CPRD       ((unsigned int) 0x0 <<  0) // (PWMC_CH) Channel Period
// -------- PWMC_CCNTR : (PWMC_CH Offset: 0xc) PWMC Channel Counter Register -------- 
#define AT91C_PWMC_CCNT       ((unsigned int) 0x0 <<  0) // (PWMC_CH) Channel Counter
// -------- PWMC_CUPDR : (PWMC_CH Offset: 0x10) PWMC Channel Update Register -------- 
#define AT91C_PWMC_CUPD       ((unsigned int) 0x0 <<  0) // (PWMC_CH) Channel Update

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Pulse Width Modulation Controller Interface
// *****************************************************************************
typedef struct _AT91S_PWMC {
	AT91_REG	 PWMC_MR; 	// PWMC Mode Register
	AT91_REG	 PWMC_ENA; 	// PWMC Enable Register
	AT91_REG	 PWMC_DIS; 	// PWMC Disable Register
	AT91_REG	 PWMC_SR; 	// PWMC Status Register
	AT91_REG	 PWMC_IER; 	// PWMC Interrupt Enable Register
	AT91_REG	 PWMC_IDR; 	// PWMC Interrupt Disable Register
	AT91_REG	 PWMC_IMR; 	// PWMC Interrupt Mask Register
	AT91_REG	 PWMC_ISR; 	// PWMC Interrupt Status Register
	AT91_REG	 Reserved0[55]; 	// 
	AT91_REG	 PWMC_VR; 	// PWMC Version Register
	AT91_REG	 Reserved1[64]; 	// 
	AT91S_PWMC_CH	 PWMC_CH[4]; 	// PWMC Channel
} AT91S_PWMC, *AT91PS_PWMC;

// -------- PWMC_MR : (PWMC Offset: 0x0) PWMC Mode Register -------- 
#define AT91C_PWMC_DIVA       ((unsigned int) 0xFF <<  0) // (PWMC) CLKA divide factor.
#define AT91C_PWMC_PREA       ((unsigned int) 0xF <<  8) // (PWMC) Divider Input Clock Prescaler A
#define 	AT91C_PWMC_PREA_MCK                  ((unsigned int) 0x0 <<  8) // (PWMC) 
#define AT91C_PWMC_DIVB       ((unsigned int) 0xFF << 16) // (PWMC) CLKB divide factor.
#define AT91C_PWMC_PREB       ((unsigned int) 0xF << 24) // (PWMC) Divider Input Clock Prescaler B
#define 	AT91C_PWMC_PREB_MCK                  ((unsigned int) 0x0 << 24) // (PWMC) 
// -------- PWMC_ENA : (PWMC Offset: 0x4) PWMC Enable Register -------- 
#define AT91C_PWMC_CHID0      ((unsigned int) 0x1 <<  0) // (PWMC) Channel ID 0
#define AT91C_PWMC_CHID1      ((unsigned int) 0x1 <<  1) // (PWMC) Channel ID 1
#define AT91C_PWMC_CHID2      ((unsigned int) 0x1 <<  2) // (PWMC) Channel ID 2
#define AT91C_PWMC_CHID3      ((unsigned int) 0x1 <<  3) // (PWMC) Channel ID 3
// -------- PWMC_DIS : (PWMC Offset: 0x8) PWMC Disable Register -------- 
// -------- PWMC_SR : (PWMC Offset: 0xc) PWMC Status Register -------- 
// -------- PWMC_IER : (PWMC Offset: 0x10) PWMC Interrupt Enable Register -------- 
// -------- PWMC_IDR : (PWMC Offset: 0x14) PWMC Interrupt Disable Register -------- 
// -------- PWMC_IMR : (PWMC Offset: 0x18) PWMC Interrupt Mask Register -------- 
// -------- PWMC_ISR : (PWMC Offset: 0x1c) PWMC Interrupt Status Register -------- 

// *****************************************************************************
//               REGISTER ADDRESS DEFINITION FOR AT91SAM3SD8
// *****************************************************************************
// ========== Register definition for SYS peripheral ========== 
// ========== Register definition for EEFC peripheral ==========
#define AT91C_EEFC_FMR  ((AT91_REG *) 	0x400E0A00) // (EEFC) 
#define AT91C_EEFC_FCR  ((AT91_REG *) 	0x400E0A04) // (EEFC) 
#define AT91C_EEFC_FSR  ((AT91_REG *) 	0x400E0A08) // (EEFC) 
#define AT91C_EEFC_FRR  ((AT91_REG *) 	0x400E0A0C) // (EEFC) 
// ========== Register definition for PIOA peripheral ========== 
#define AT91C_PIOA_ODR  ((AT91_REG *) 	0x400E0E14) // (PIOA) Output Disable Registerr
#define AT91C_PIOA_SODR ((AT91_REG *) 	0x400E0E30) // (PIOA) Set Output Data Register
#define AT91C_PIOA_ISR  ((AT91_REG *) 	0x400E0E4C) // (PIOA) Interrupt Status Register
#define AT91C_PIOA_ABSR ((AT91_REG *) 	0x400E0E78) // (PIOA) AB Select Status Register
#define AT91C_PIOA_IER  ((AT91_REG *) 	0x400E0E40) // (PIOA) Interrupt Enable Register
#define AT91C_PIOA_PPUDR ((AT91_REG *) 	0x400E0E60) // (PIOA) Pull-up Disable Register
#define AT91C_PIOA_IMR  ((AT91_REG *) 	0x400E0E48) // (PIOA) Interrupt Mask Register
#define AT91C_PIOA_PER  ((AT91_REG *) 	0x400E0E00) // (PIOA) PIO Enable Register
#define AT91C_PIOA_IFDR ((AT91_REG *) 	0x400E0E24) // (PIOA) Input Filter Disable Register
#define AT91C_PIOA_OWDR ((AT91_REG *) 	0x400E0EA4) // (PIOA) Output Write Disable Register
#define AT91C_PIOA_MDSR ((AT91_REG *) 	0x400E0E58) // (PIOA) Multi-driver Status Register
#define AT91C_PIOA_IDR  ((AT91_REG *) 	0x400E0E44) // (PIOA) Interrupt Disable Register
#define AT91C_PIOA_ODSR ((AT91_REG *) 	0x400E0E38) // (PIOA) Output Data Status Register
#define AT91C_PIOA_PPUSR ((AT91_REG *) 	0x400E0E68) // (PIOA) Pull-up Status Register
#define AT91C_PIOA_OWSR ((AT91_REG *) 	0x400E0EA8) // (PIOA) Output Write Status Register
#define AT91C_PIOA_BSR  ((AT91_REG *) 	0x400E0E74) // (PIOA) Select B Register
#define AT91C_PIOA_OWER ((AT91_REG *) 	0x400E0EA0) // (PIOA) Output Write Enable Register
#define AT91C_PIOA_IFER ((AT91_REG *) 	0x400E0E20) // (PIOA) Input Filter Enable Register
#define AT91C_PIOA_PDSR ((AT91_REG *) 	0x400E0E3C) // (PIOA) Pin Data Status Register
#define AT91C_PIOA_PPUER ((AT91_REG *) 	0x400E0E64) // (PIOA) Pull-up Enable Register
#define AT91C_PIOA_OSR  ((AT91_REG *) 	0x400E0E18) // (PIOA) Output Status Register
#define AT91C_PIOA_ASR  ((AT91_REG *) 	0x400E0E70) // (PIOA) Select A Register
#define AT91C_PIOA_MDDR ((AT91_REG *) 	0x400E0E54) // (PIOA) Multi-driver Disable Register
#define AT91C_PIOA_CODR ((AT91_REG *) 	0x400E0E34) // (PIOA) Clear Output Data Register
#define AT91C_PIOA_MDER ((AT91_REG *) 	0x400E0E50) // (PIOA) Multi-driver Enable Register
#define AT91C_PIOA_PDR  ((AT91_REG *) 	0x400E0E04) // (PIOA) PIO Disable Register
#define AT91C_PIOA_IFSR ((AT91_REG *) 	0x400E0E28) // (PIOA) Input Filter Status Register
#define AT91C_PIOA_OER  ((AT91_REG *) 	0x400E0E10) // (PIOA) Output Enable Register
#define AT91C_PIOA_PSR  ((AT91_REG *) 	0x400E0E08) // (PIOA) PIO Status Register

// ========== Register definition for PIOB peripheral ========== 
#define AT91C_PIOB_ODR  ((AT91_REG *) 	0x400E1014) // (PIOB) Output Disable Registerr
#define AT91C_PIOB_SODR ((AT91_REG *) 	0x400E1030) // (PIOB) Set Output Data Register
#define AT91C_PIOB_ISR  ((AT91_REG *) 	0x400E104C) // (PIOB) Interrupt Status Register
#define AT91C_PIOB_ABSR ((AT91_REG *) 	0x400E1078) // (PIOB) AB Select Status Register
#define AT91C_PIOB_IER  ((AT91_REG *) 	0x400E1040) // (PIOB) Interrupt Enable Register
#define AT91C_PIOB_PPUDR ((AT91_REG *) 	0x400E1060) // (PIOB) Pull-up Disable Register
#define AT91C_PIOB_IMR  ((AT91_REG *) 	0x400E1048) // (PIOB) Interrupt Mask Register
#define AT91C_PIOB_PER  ((AT91_REG *) 	0x400E1000) // (PIOB) PIO Enable Register
#define AT91C_PIOB_IFDR ((AT91_REG *) 	0x400E1024) // (PIOB) Input Filter Disable Register
#define AT91C_PIOB_OWDR ((AT91_REG *) 	0x400E10A4) // (PIOB) Output Write Disable Register
#define AT91C_PIOB_MDSR ((AT91_REG *) 	0x400E1058) // (PIOB) Multi-driver Status Register
#define AT91C_PIOB_IDR  ((AT91_REG *) 	0x400E1044) // (PIOB) Interrupt Disable Register
#define AT91C_PIOB_ODSR ((AT91_REG *) 	0x400E1038) // (PIOB) Output Data Status Register
#define AT91C_PIOB_PPUSR ((AT91_REG *) 	0x400E1068) // (PIOB) Pull-up Status Register
#define AT91C_PIOB_OWSR ((AT91_REG *) 	0x400E10A8) // (PIOB) Output Write Status Register
#define AT91C_PIOB_BSR  ((AT91_REG *) 	0x400E1074) // (PIOB) Select B Register
#define AT91C_PIOB_OWER ((AT91_REG *) 	0x400E10A0) // (PIOB) Output Write Enable Register
#define AT91C_PIOB_IFER ((AT91_REG *) 	0x400E1020) // (PIOB) Input Filter Enable Register
#define AT91C_PIOB_PDSR ((AT91_REG *) 	0x400E103C) // (PIOB) Pin Data Status Register
#define AT91C_PIOB_PPUER ((AT91_REG *) 	0x400E1064) // (PIOB) Pull-up Enable Register
#define AT91C_PIOB_OSR  ((AT91_REG *) 	0x400E1018) // (PIOB) Output Status Register
#define AT91C_PIOB_ASR  ((AT91_REG *) 	0x400E1070) // (PIOB) Select A Register
#define AT91C_PIOB_MDDR ((AT91_REG *) 	0x400E1054) // (PIOB) Multi-driver Disable Register
#define AT91C_PIOB_CODR ((AT91_REG *) 	0x400E1034) // (PIOB) Clear Output Data Register
#define AT91C_PIOB_MDER ((AT91_REG *) 	0x400E1050) // (PIOB) Multi-driver Enable Register
#define AT91C_PIOB_PDR  ((AT91_REG *) 	0x400E1004) // (PIOB) PIO Disable Register
#define AT91C_PIOB_IFSR ((AT91_REG *) 	0x400E1028) // (PIOB) Input Filter Status Register
#define AT91C_PIOB_OER  ((AT91_REG *) 	0x400E1010) // (PIOB) Output Enable Register
#define AT91C_PIOB_PSR  ((AT91_REG *) 	0x400E1008) // (PIOB) PIO Status Register

// ========== Register definition for PIOC peripheral ========== 
#define AT91C_PIOC_ODR  ((AT91_REG *) 	0x400E1214) // (PIOC) Output Disable Registerr
#define AT91C_PIOC_SODR ((AT91_REG *) 	0x400E1230) // (PIOC) Set Output Data Register
#define AT91C_PIOC_ISR  ((AT91_REG *) 	0x400E124C) // (PIOC) Interrupt Status Register
#define AT91C_PIOC_ABSR ((AT91_REG *) 	0x400E1278) // (PIOC) AB Select Status Register
#define AT91C_PIOC_IER  ((AT91_REG *) 	0x400E1240) // (PIOC) Interrupt Enable Register
#define AT91C_PIOC_PPUDR ((AT91_REG *) 	0x400E1260) // (PIOC) Pull-up Disable Register
#define AT91C_PIOC_IMR  ((AT91_REG *) 	0x400E1248) // (PIOC) Interrupt Mask Register
#define AT91C_PIOC_PER  ((AT91_REG *) 	0x400E1200) // (PIOC) PIO Enable Register
#define AT91C_PIOC_IFDR ((AT91_REG *) 	0x400E1224) // (PIOC) Input Filter Disable Register
#define AT91C_PIOC_OWDR ((AT91_REG *) 	0x400E12A4) // (PIOC) Output Write Disable Register
#define AT91C_PIOC_MDSR ((AT91_REG *) 	0x400E1258) // (PIOC) Multi-driver Status Register
#define AT91C_PIOC_IDR  ((AT91_REG *) 	0x400E1244) // (PIOC) Interrupt Disable Register
#define AT91C_PIOC_ODSR ((AT91_REG *) 	0x400E1238) // (PIOC) Output Data Status Register
#define AT91C_PIOC_PPUSR ((AT91_REG *) 	0x400E1268) // (PIOC) Pull-up Status Register
#define AT91C_PIOC_OWSR ((AT91_REG *) 	0x400E12A8) // (PIOC) Output Write Status Register
#define AT91C_PIOC_BSR  ((AT91_REG *) 	0x400E1274) // (PIOC) Select B Register
#define AT91C_PIOC_OWER ((AT91_REG *) 	0x400E12A0) // (PIOC) Output Write Enable Register
#define AT91C_PIOC_IFER ((AT91_REG *) 	0x400E1220) // (PIOC) Input Filter Enable Register
#define AT91C_PIOC_PDSR ((AT91_REG *) 	0x400E123C) // (PIOC) Pin Data Status Register
#define AT91C_PIOC_PPUER ((AT91_REG *) 	0x400E1264) // (PIOC) Pull-up Enable Register
#define AT91C_PIOC_OSR  ((AT91_REG *) 	0x400E1218) // (PIOC) Output Status Register
#define AT91C_PIOC_ASR  ((AT91_REG *) 	0x400E1270) // (PIOC) Select A Register
#define AT91C_PIOC_MDDR ((AT91_REG *) 	0x400E1254) // (PIOC) Multi-driver Disable Register
#define AT91C_PIOC_CODR ((AT91_REG *) 	0x400E1234) // (PIOC) Clear Output Data Register
#define AT91C_PIOC_MDER ((AT91_REG *) 	0x400E1250) // (PIOC) Multi-driver Enable Register
#define AT91C_PIOC_PDR  ((AT91_REG *) 	0x400E1204) // (PIOC) PIO Disable Register
#define AT91C_PIOC_IFSR ((AT91_REG *) 	0x400E1228) // (PIOC) Input Filter Status Register
#define AT91C_PIOC_OER  ((AT91_REG *) 	0x400E1210) // (PIOC) Output Enable Register
#define AT91C_PIOC_PSR  ((AT91_REG *) 	0x400E1208) // (PIOC) PIO Status Register

// ========== Register definition for PMC peripheral ========== 
#define AT91C_PMC_SCER  ((AT91_REG *) 	0x400E0400) // (PMC) System Clock Enable Register
#define AT91C_PMC_SCDR  ((AT91_REG *) 	0x400E0404) // (PMC) System Clock Disable Register
#define AT91C_PMC_SCSR  ((AT91_REG *) 	0x400E0408) // (PMC) System Clock Status Register
#define AT91C_PMC_PCER0  ((AT91_REG *) 	0x400E0410) // (PMC) Peripheral Clock Enable Register
#define AT91C_PMC_PCDR0  ((AT91_REG *) 	0x400E0414) // (PMC) Peripheral Clock Disable Register
#define AT91C_PMC_PCSR0  ((AT91_REG *) 	0x400E0418) // (PMC) Peripheral Clock Status Register
#define AT91C_CKGR_MOR  ((AT91_REG *) 	0x400E0420) // (CKGR) Main Oscillator Register
#define AT91C_CKGR_MCFR ((AT91_REG *) 	0x400E0424) // (CKGR) Main Clock  Frequency Register
#define AT91C_CKGR_PLLAR ((AT91_REG *) 	0x400E0428) // (CKGR) PLLA Register
#define AT91C_CKGR_PLLBR ((AT91_REG *) 	0x400E042C) // (CKGR) PLLB Register
#define AT91C_PMC_MCKR  ((AT91_REG *) 	0x400E0430) // (PMC) Master Clock Register
#define AT91C_PMC_USB   ((AT91_REG *) 	0x400E0438) // (PMC) USB Clock Register
#define AT91C_PMC_PCK0  ((AT91_REG *) 	0x400E0440) // (PMC) Programmable Clock Register
#define AT91C_PMC_PCK1  ((AT91_REG *) 	0x400E0444) // (PMC) Programmable Clock Register
#define AT91C_PMC_PCK2  ((AT91_REG *) 	0x400E0448) // (PMC) Programmable Clock Register
#define AT91C_PMC_IER   ((AT91_REG *) 	0x400E0460) // (PMC) Interrupt Enable Register
#define AT91C_PMC_IDR   ((AT91_REG *) 	0x400E0464) // (PMC) Interrupt Disable Register
#define AT91C_PMC_SR    ((AT91_REG *) 	0x400E0468) // (PMC) Status Register
#define AT91C_PMC_IMR   ((AT91_REG *) 	0x400E046C) // (PMC) Interrupt Mask Register
#define AT91C_PMC_FSMR  ((AT91_REG *) 	0x400E0470) // (PMC) Fast Startup Mode Register
#define AT91C_PMC_FSPR  ((AT91_REG *) 	0x400E0474) // (PMC) Fast Startup Polarity Register
#define AT91C_PMC_FOCR  ((AT91_REG *) 	0x400E0478) // (PMC) Fast Output Clear Register
#define AT91C_PMC_WPMR  ((AT91_REG *) 	0x400E04E4) // (PMC) Write Protect Mode Register
#define AT91C_PMC_WPSR  ((AT91_REG *) 	0x400E04E8) // (PMC) Write Protect Status Register
#define AT91C_PMC_PCER1  ((AT91_REG *) 	0x400E0500) // (PMC) Peripheral Clock Enable Register
#define AT91C_PMC_PCDR1  ((AT91_REG *) 	0x400E0504) // (PMC) Peripheral Clock Disable Register
#define AT91C_PMC_PCSR1  ((AT91_REG *) 	0x400E0508) // (PMC) Peripheral Clock Status Register
#define AT91C_PMC_OCR    ((AT91_REG *) 	0x400E0510) // (PMC) Peripheral Clock Status Register
// ========== Register definition for RSTC peripheral ========== 
#define AT91C_RSTC_RCR  ((AT91_REG *) 	0x400E1400) // (RSTC) Reset Control Register
#define AT91C_RSTC_RMR  ((AT91_REG *) 	0x400E1408) // (RSTC) Reset Mode Register
#define AT91C_RSTC_RSR  ((AT91_REG *) 	0x400E1404) // (RSTC) Reset Status Register
// ========== Register definition for RTTC peripheral ========== 
#define AT91C_RTTC_RTSR ((AT91_REG *) 	0x400E143C) // (RTTC) Real-time Status Register
#define AT91C_RTTC_RTMR ((AT91_REG *) 	0x400E1430) // (RTTC) Real-time Mode Register
#define AT91C_RTTC_RTVR ((AT91_REG *) 	0x400E1438) // (RTTC) Real-time Value Register
#define AT91C_RTTC_RTAR ((AT91_REG *) 	0x400E1434) // (RTTC) Real-time Alarm Register
// ========== Register definition for WDTC peripheral ========== 
#define AT91C_WDTC_WDCR ((AT91_REG *) 	0X400e1450) // (WDTC) Watchdog Control Register
#define AT91C_WDTC_WDSR ((AT91_REG *) 	0X400e1458) // (WDTC) Watchdog Status Register
#define AT91C_WDTC_WDMR ((AT91_REG *) 	0X400e1454) // (WDTC) Watchdog Mode Register
// ========== Register definition for SUPC peripheral ========== 
#define AT91C_SUPC_CR   ((AT91_REG *) 	0x400E1410) // (SUPC) 
#define AT91C_SUPC_SMMR ((AT91_REG *) 	0x400E1414) // (SUPC) 
#define AT91C_SUPC_MR   ((AT91_REG *) 	0x400E1418) // (SUPC) 
#define AT91C_SUPC_WUMR ((AT91_REG *) 	0x400E141C) // (SUPC) 
#define AT91C_SUPC_WUIR ((AT91_REG *) 	0x400E1420) // (SUPC) 
#define AT91C_SUPC_SR   ((AT91_REG *) 	0x400E1424) // (SUPC) 
// ========== Register definition for SMC peripheral ========== 
#define AT91C_SMC_SETUP0 ((AT91_REG *) 	0x400E0000) // (MC) MC Abort Status Register
#define AT91C_SMC_PULSE0 ((AT91_REG *) 	0x400E0004) // (MC) MC Remap Control Register
#define AT91C_SMC_CYCLE0 ((AT91_REG *) 	0x400E0008) // (MC) MC Flash Command Register
#define AT91C_SMC_MODE0  ((AT91_REG *) 	0x400E000C) // (MC) MC Abort Address Status Register
#define AT91C_SMC_SETUP1 ((AT91_REG *) 	0x400E0010) // (MC) MC Abort Status Register
#define AT91C_SMC_PULSE1 ((AT91_REG *) 	0x400E0014) // (MC) MC Remap Control Register
#define AT91C_SMC_CYCLE1 ((AT91_REG *) 	0x400E0018) // (MC) MC Flash Command Register
#define AT91C_SMC_MODE1  ((AT91_REG *) 	0x400E001C) // (MC) MC Abort Address Status Register
#define AT91C_SMC_SETUP2 ((AT91_REG *) 	0x400E0020) // (MC) MC Abort Status Register
#define AT91C_SMC_PULSE2 ((AT91_REG *) 	0x400E0024) // (MC) MC Remap Control Register
#define AT91C_SMC_CYCLE2 ((AT91_REG *) 	0x400E0028) // (MC) MC Flash Command Register
#define AT91C_SMC_MODE2  ((AT91_REG *) 	0x400E002C) // (MC) MC Abort Address Status Register
#define AT91C_SMC_SETUP3 ((AT91_REG *) 	0x400E0030) // (MC) MC Abort Status Register
#define AT91C_SMC_PULSE3 ((AT91_REG *) 	0x400E0034) // (MC) MC Remap Control Register
#define AT91C_SMC_CYCLE3 ((AT91_REG *) 	0x400E0038) // (MC) MC Flash Command Register
#define AT91C_SMC_MODE3  ((AT91_REG *) 	0x400E003C) // (MC) MC Abort Address Status Register
#define AT91C_SMC_SETUP4 ((AT91_REG *) 	0x400E0040) // (MC) MC Abort Status Register
#define AT91C_SMC_PULSE4 ((AT91_REG *) 	0x400E0044) // (MC) MC Remap Control Register
#define AT91C_SMC_CYCLE4 ((AT91_REG *) 	0x400E0048) // (MC) MC Flash Command Register
#define AT91C_SMC_MODE4  ((AT91_REG *) 	0x400E004C) // (MC) MC Abort Address Status Register
#define AT91C_SMC_OCMR   ((AT91_REG *) 	0x400E0080) // (MC) MC Flash Status Register
#define AT91C_SMC_KEY1   ((AT91_REG *) 	0x400E0084) // (MC) MC Flash Mode Register
#define AT91C_SMC_KEY2   ((AT91_REG *) 	0x400E0088) // (MC) MC Flash Mode Register
#define AT91C_SMC_WPMR   ((AT91_REG *) 	0x400E00E4) // (MC) MC Flash Mode Register
#define AT91C_SMC_WPSR   ((AT91_REG *) 	0x400E00E8) // (MC) MC Flash Mode Register
// ========== Register definition for PDC_SPI peripheral ========== 
#define AT91C_SPI_PTCR  ((AT91_REG *) 	0x40008120) // (PDC_SPI) PDC Transfer Control Register
#define AT91C_SPI_TPR   ((AT91_REG *) 	0x40008108) // (PDC_SPI) Transmit Pointer Register
#define AT91C_SPI_TCR   ((AT91_REG *) 	0x4000810C) // (PDC_SPI) Transmit Counter Register
#define AT91C_SPI_RCR   ((AT91_REG *) 	0x40008104) // (PDC_SPI) Receive Counter Register
#define AT91C_SPI_PTSR  ((AT91_REG *) 	0x40008124) // (PDC_SPI) PDC Transfer Status Register
#define AT91C_SPI_RNPR  ((AT91_REG *) 	0x40008110) // (PDC_SPI) Receive Next Pointer Register
#define AT91C_SPI_RPR   ((AT91_REG *) 	0x40008100) // (PDC_SPI) Receive Pointer Register
#define AT91C_SPI_TNCR  ((AT91_REG *) 	0x4000811C) // (PDC_SPI) Transmit Next Counter Register
#define AT91C_SPI_RNCR  ((AT91_REG *) 	0x40008114) // (PDC_SPI) Receive Next Counter Register
#define AT91C_SPI_TNPR  ((AT91_REG *) 	0x40008118) // (PDC_SPI) Transmit Next Pointer Register
// ========== Register definition for SPI peripheral ========== 
#define AT91C_SPI_IER   ((AT91_REG *) 	0x40008014) // (SPI) Interrupt Enable Register
#define AT91C_SPI_SR    ((AT91_REG *) 	0x40008010) // (SPI) Status Register
#define AT91C_SPI_IDR   ((AT91_REG *) 	0x40008018) // (SPI) Interrupt Disable Register
#define AT91C_SPI_CR    ((AT91_REG *) 	0x40008000) // (SPI) Control Register
#define AT91C_SPI_MR    ((AT91_REG *) 	0x40008004) // (SPI) Mode Register
#define AT91C_SPI_IMR   ((AT91_REG *) 	0x4000801C) // (SPI) Interrupt Mask Register
#define AT91C_SPI_TDR   ((AT91_REG *) 	0x4000800C) // (SPI) Transmit Data Register
#define AT91C_SPI_RDR   ((AT91_REG *) 	0x40008008) // (SPI) Receive Data Register
#define AT91C_SPI_CSR   ((AT91_REG *) 	0x40008030) // (SPI) Chip Select Register
// ========== Register definition for PDC_ADC peripheral ========== 
#define AT91C_ADC_PTSR  ((AT91_REG *) 	0x40038124) // (PDC_ADC) PDC Transfer Status Register
#define AT91C_ADC_PTCR  ((AT91_REG *) 	0x40038120) // (PDC_ADC) PDC Transfer Control Register
#define AT91C_ADC_TNPR  ((AT91_REG *) 	0x40038118) // (PDC_ADC) Transmit Next Pointer Register
#define AT91C_ADC_TNCR  ((AT91_REG *) 	0x4003811C) // (PDC_ADC) Transmit Next Counter Register
#define AT91C_ADC_RNPR  ((AT91_REG *) 	0x40038110) // (PDC_ADC) Receive Next Pointer Register
#define AT91C_ADC_RNCR  ((AT91_REG *) 	0x40038114) // (PDC_ADC) Receive Next Counter Register
#define AT91C_ADC_RPR   ((AT91_REG *) 	0x40038100) // (PDC_ADC) Receive Pointer Register
#define AT91C_ADC_TCR   ((AT91_REG *) 	0x4003810C) // (PDC_ADC) Transmit Counter Register
#define AT91C_ADC_TPR   ((AT91_REG *) 	0x40038108) // (PDC_ADC) Transmit Pointer Register
#define AT91C_ADC_RCR   ((AT91_REG *) 	0x40038104) // (PDC_ADC) Receive Counter Register
// ========== Register definition for ADC peripheral ========== 
#define AT91C_ADC_CDR2  ((AT91_REG *) 	0x40038038) // (ADC) ADC Channel Data Register 2
#define AT91C_ADC_CDR3  ((AT91_REG *) 	0x4003803C) // (ADC) ADC Channel Data Register 3
#define AT91C_ADC_CDR0  ((AT91_REG *) 	0x40038030) // (ADC) ADC Channel Data Register 0
#define AT91C_ADC_CDR5  ((AT91_REG *) 	0x40038044) // (ADC) ADC Channel Data Register 5
#define AT91C_ADC_CHDR  ((AT91_REG *) 	0x40038014) // (ADC) ADC Channel Disable Register
#define AT91C_ADC_SR    ((AT91_REG *) 	0x4003801C) // (ADC) ADC Status Register
#define AT91C_ADC_CDR4  ((AT91_REG *) 	0x40038040) // (ADC) ADC Channel Data Register 4
#define AT91C_ADC_CDR1  ((AT91_REG *) 	0x40038034) // (ADC) ADC Channel Data Register 1
#define AT91C_ADC_LCDR  ((AT91_REG *) 	0x40038020) // (ADC) ADC Last Converted Data Register
#define AT91C_ADC_IDR   ((AT91_REG *) 	0x40038028) // (ADC) ADC Interrupt Disable Register
#define AT91C_ADC_CR    ((AT91_REG *) 	0x40038000) // (ADC) ADC Control Register
#define AT91C_ADC_CDR7  ((AT91_REG *) 	0x4003804C) // (ADC) ADC Channel Data Register 7
#define AT91C_ADC_CDR6  ((AT91_REG *) 	0x40038048) // (ADC) ADC Channel Data Register 6
#define AT91C_ADC_IER   ((AT91_REG *) 	0x40038024) // (ADC) ADC Interrupt Enable Register
#define AT91C_ADC_CHER  ((AT91_REG *) 	0x40038010) // (ADC) ADC Channel Enable Register
#define AT91C_ADC_CHSR  ((AT91_REG *) 	0x40038018) // (ADC) ADC Channel Status Register
#define AT91C_ADC_MR    ((AT91_REG *) 	0x40038004) // (ADC) ADC Mode Register
#define AT91C_ADC_IMR   ((AT91_REG *) 	0x4003802C) // (ADC) ADC Interrupt Mask Register
// ========== Register definition for PDC_SSC peripheral ========== 
#define AT91C_SSC_TNCR  ((AT91_REG *) 	0x4000411C) // (PDC_SSC) Transmit Next Counter Register
#define AT91C_SSC_RPR   ((AT91_REG *) 	0x40004100) // (PDC_SSC) Receive Pointer Register
#define AT91C_SSC_RNCR  ((AT91_REG *) 	0x40004114) // (PDC_SSC) Receive Next Counter Register
#define AT91C_SSC_TPR   ((AT91_REG *) 	0x40004108) // (PDC_SSC) Transmit Pointer Register
#define AT91C_SSC_PTCR  ((AT91_REG *) 	0x40004120) // (PDC_SSC) PDC Transfer Control Register
#define AT91C_SSC_TCR   ((AT91_REG *) 	0x4000410C) // (PDC_SSC) Transmit Counter Register
#define AT91C_SSC_RCR   ((AT91_REG *) 	0x40004104) // (PDC_SSC) Receive Counter Register
#define AT91C_SSC_RNPR  ((AT91_REG *) 	0x40004110) // (PDC_SSC) Receive Next Pointer Register
#define AT91C_SSC_TNPR  ((AT91_REG *) 	0x40004118) // (PDC_SSC) Transmit Next Pointer Register
#define AT91C_SSC_PTSR  ((AT91_REG *) 	0x40004124) // (PDC_SSC) PDC Transfer Status Register
// ========== Register definition for SSC peripheral ========== 
#define AT91C_SSC_RHR   ((AT91_REG *) 	0x40004020) // (SSC) Receive Holding Register
#define AT91C_SSC_RSHR  ((AT91_REG *) 	0x40004030) // (SSC) Receive Sync Holding Register
#define AT91C_SSC_TFMR  ((AT91_REG *) 	0x4000401C) // (SSC) Transmit Frame Mode Register
#define AT91C_SSC_IDR   ((AT91_REG *) 	0x40004048) // (SSC) Interrupt Disable Register
#define AT91C_SSC_THR   ((AT91_REG *) 	0x40004024) // (SSC) Transmit Holding Register
#define AT91C_SSC_RCMR  ((AT91_REG *) 	0x40004010) // (SSC) Receive Clock ModeRegister
#define AT91C_SSC_IER   ((AT91_REG *) 	0x40004044) // (SSC) Interrupt Enable Register
#define AT91C_SSC_TSHR  ((AT91_REG *) 	0x40004034) // (SSC) Transmit Sync Holding Register
#define AT91C_SSC_SR    ((AT91_REG *) 	0x40004040) // (SSC) Status Register
#define AT91C_SSC_CMR   ((AT91_REG *) 	0x40004004) // (SSC) Clock Mode Register
#define AT91C_SSC_TCMR  ((AT91_REG *) 	0x40004018) // (SSC) Transmit Clock Mode Register
#define AT91C_SSC_CR    ((AT91_REG *) 	0x40004000) // (SSC) Control Register
#define AT91C_SSC_IMR   ((AT91_REG *) 	0x4000404C) // (SSC) Interrupt Mask Register
#define AT91C_SSC_RFMR  ((AT91_REG *) 	0x40004014) // (SSC) Receive Frame Mode Register
// ========== Register definition for PDC_US1 peripheral ========== 
#define AT91C_US1_RNCR  ((AT91_REG *) 	0x40028114) // (PDC_US1) Receive Next Counter Register
#define AT91C_US1_PTCR  ((AT91_REG *) 	0x40028120) // (PDC_US1) PDC Transfer Control Register
#define AT91C_US1_TCR   ((AT91_REG *) 	0x4002810C) // (PDC_US1) Transmit Counter Register
#define AT91C_US1_PTSR  ((AT91_REG *) 	0x40028124) // (PDC_US1) PDC Transfer Status Register
#define AT91C_US1_TNPR  ((AT91_REG *) 	0x40028118) // (PDC_US1) Transmit Next Pointer Register
#define AT91C_US1_RCR   ((AT91_REG *) 	0x40028104) // (PDC_US1) Receive Counter Register
#define AT91C_US1_RNPR  ((AT91_REG *) 	0x40028110) // (PDC_US1) Receive Next Pointer Register
#define AT91C_US1_RPR   ((AT91_REG *) 	0x40028100) // (PDC_US1) Receive Pointer Register
#define AT91C_US1_TNCR  ((AT91_REG *) 	0x4002811C) // (PDC_US1) Transmit Next Counter Register
#define AT91C_US1_TPR   ((AT91_REG *) 	0x40028108) // (PDC_US1) Transmit Pointer Register
// ========== Register definition for US1 peripheral ========== 
#define AT91C_US1_IF    ((AT91_REG *) 	0x4002804C) // (US1) IRDA_FILTER Register
#define AT91C_US1_NER   ((AT91_REG *) 	0x40028044) // (US1) Nb Errors Register
#define AT91C_US1_RTOR  ((AT91_REG *) 	0x40028024) // (US1) Receiver Time-out Register
#define AT91C_US1_CSR   ((AT91_REG *) 	0x40028014) // (US1) Channel Status Register
#define AT91C_US1_IDR   ((AT91_REG *) 	0x4002800C) // (US1) Interrupt Disable Register
#define AT91C_US1_IER   ((AT91_REG *) 	0x40028008) // (US1) Interrupt Enable Register
#define AT91C_US1_THR   ((AT91_REG *) 	0x4002801C) // (US1) Transmitter Holding Register
#define AT91C_US1_TTGR  ((AT91_REG *) 	0x40028028) // (US1) Transmitter Time-guard Register
#define AT91C_US1_RHR   ((AT91_REG *) 	0x40028018) // (US1) Receiver Holding Register
#define AT91C_US1_BRGR  ((AT91_REG *) 	0x40028020) // (US1) Baud Rate Generator Register
#define AT91C_US1_IMR   ((AT91_REG *) 	0x40028010) // (US1) Interrupt Mask Register
#define AT91C_US1_FIDI  ((AT91_REG *) 	0x40028040) // (US1) FI_DI_Ratio Register
#define AT91C_US1_CR    ((AT91_REG *) 	0x40028000) // (US1) Control Register
#define AT91C_US1_MR    ((AT91_REG *) 	0x40028004) // (US1) Mode Register
// ========== Register definition for PDC_US0 peripheral ========== 
#define AT91C_US0_TNPR  ((AT91_REG *) 	0x40024118) // (PDC_US0) Transmit Next Pointer Register
#define AT91C_US0_RNPR  ((AT91_REG *) 	0x40024110) // (PDC_US0) Receive Next Pointer Register
#define AT91C_US0_TCR   ((AT91_REG *) 	0x4002410C) // (PDC_US0) Transmit Counter Register
#define AT91C_US0_PTCR  ((AT91_REG *) 	0x40024120) // (PDC_US0) PDC Transfer Control Register
#define AT91C_US0_PTSR  ((AT91_REG *) 	0x40024124) // (PDC_US0) PDC Transfer Status Register
#define AT91C_US0_TNCR  ((AT91_REG *) 	0x4002411C) // (PDC_US0) Transmit Next Counter Register
#define AT91C_US0_TPR   ((AT91_REG *) 	0x40024108) // (PDC_US0) Transmit Pointer Register
#define AT91C_US0_RCR   ((AT91_REG *) 	0x40024104) // (PDC_US0) Receive Counter Register
#define AT91C_US0_RPR   ((AT91_REG *) 	0x40024100) // (PDC_US0) Receive Pointer Register
#define AT91C_US0_RNCR  ((AT91_REG *) 	0x40024114) // (PDC_US0) Receive Next Counter Register
// ========== Register definition for US0 peripheral ========== 
#define AT91C_US0_BRGR  ((AT91_REG *) 	0x40024020) // (US0) Baud Rate Generator Register
#define AT91C_US0_NER   ((AT91_REG *) 	0x40024044) // (US0) Nb Errors Register
#define AT91C_US0_CR    ((AT91_REG *) 	0x40024000) // (US0) Control Register
#define AT91C_US0_IMR   ((AT91_REG *) 	0x40024010) // (US0) Interrupt Mask Register
#define AT91C_US0_FIDI  ((AT91_REG *) 	0x40024040) // (US0) FI_DI_Ratio Register
#define AT91C_US0_TTGR  ((AT91_REG *) 	0x40024028) // (US0) Transmitter Time-guard Register
#define AT91C_US0_MR    ((AT91_REG *) 	0x40024004) // (US0) Mode Register
#define AT91C_US0_RTOR  ((AT91_REG *) 	0x40024024) // (US0) Receiver Time-out Register
#define AT91C_US0_CSR   ((AT91_REG *) 	0x40024014) // (US0) Channel Status Register
#define AT91C_US0_RHR   ((AT91_REG *) 	0x40024018) // (US0) Receiver Holding Register
#define AT91C_US0_IDR   ((AT91_REG *) 	0x4002400C) // (US0) Interrupt Disable Register
#define AT91C_US0_THR   ((AT91_REG *) 	0x4002401C) // (US0) Transmitter Holding Register
#define AT91C_US0_IF    ((AT91_REG *) 	0x4002404C) // (US0) IRDA_FILTER Register
#define AT91C_US0_IER   ((AT91_REG *) 	0x40024008) // (US0) Interrupt Enable Register
// ========== Register definition for TWI0 peripheral ========== 
#define AT91C_TWI0_IER   ((AT91_REG *) 	0x40018024) // (TWI0) Interrupt Enable Register
#define AT91C_TWI0_CR    ((AT91_REG *) 	0x40018000) // (TWI0) Control Register
#define AT91C_TWI0_SR    ((AT91_REG *) 	0x40018020) // (TWI0) Status Register
#define AT91C_TWI0_IMR   ((AT91_REG *) 	0x4001802C) // (TWI0) Interrupt Mask Register
#define AT91C_TWI0_THR   ((AT91_REG *) 	0x40018034) // (TWI0) Transmit Holding Register
#define AT91C_TWI0_IDR   ((AT91_REG *) 	0x40018028) // (TWI0) Interrupt Disable Register
#define AT91C_TWI0_IADR  ((AT91_REG *) 	0x4001800C) // (TWI0) Internal Address Register
#define AT91C_TWI0_MMR   ((AT91_REG *) 	0x40018004) // (TWI0) Master Mode Register
#define AT91C_TWI0_CWGR  ((AT91_REG *) 	0x40018010) // (TWI0) Clock Waveform Generator Register
#define AT91C_TWI0_RHR   ((AT91_REG *) 	0x40018030) // (TWI0) Receive Holding Register
// ========== Register definition for TWI1 peripheral ========== 
#define AT91C_TWI1_IER   ((AT91_REG *) 	0x4001C024) // (TWI1) Interrupt Enable Register
#define AT91C_TWI1_CR    ((AT91_REG *) 	0x4001C000) // (TWI1) Control Register
#define AT91C_TWI1_SR    ((AT91_REG *) 	0x4001C020) // (TWI1) Status Register
#define AT91C_TWI1_IMR   ((AT91_REG *) 	0x4001C02C) // (TWI1) Interrupt Mask Register
#define AT91C_TWI1_THR   ((AT91_REG *) 	0x4001C034) // (TWI1) Transmit Holding Register
#define AT91C_TWI1_IDR   ((AT91_REG *) 	0x4001C028) // (TWI1) Interrupt Disable Register
#define AT91C_TWI1_IADR  ((AT91_REG *) 	0x4001C00C) // (TWI1) Internal Address Register
#define AT91C_TWI1_MMR   ((AT91_REG *) 	0x4001C004) // (TWI1) Master Mode Register
#define AT91C_TWI1_CWGR  ((AT91_REG *) 	0x4001C010) // (TWI1) Clock Waveform Generator Register
#define AT91C_TWI1_RHR   ((AT91_REG *) 	0x4001C030) // (TWI1) Receive Holding Register
// ========== Register definition for TC0 peripheral ========== 
#define AT91C_TC0_SR    ((AT91_REG *) 	0x40010020) // (TC0) Status Register
#define AT91C_TC0_RC    ((AT91_REG *) 	0x4001001C) // (TC0) Register C
#define AT91C_TC0_RB    ((AT91_REG *) 	0x40010018) // (TC0) Register B
#define AT91C_TC0_CCR   ((AT91_REG *) 	0x40010000) // (TC0) Channel Control Register
#define AT91C_TC0_CMR   ((AT91_REG *) 	0x40010004) // (TC0) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC0_IER   ((AT91_REG *) 	0x40010024) // (TC0) Interrupt Enable Register
#define AT91C_TC0_RA    ((AT91_REG *) 	0x40010014) // (TC0) Register A
#define AT91C_TC0_IDR   ((AT91_REG *) 	0x40010028) // (TC0) Interrupt Disable Register
#define AT91C_TC0_CV    ((AT91_REG *) 	0x40010010) // (TC0) Counter Value
#define AT91C_TC0_IMR   ((AT91_REG *) 	0x4001002C) // (TC0) Interrupt Mask Register
// ========== Register definition for TC1 peripheral ========== 
#define AT91C_TC1_RB    ((AT91_REG *) 	0x40010058) // (TC1) Register B
#define AT91C_TC1_CCR   ((AT91_REG *) 	0x40010040) // (TC1) Channel Control Register
#define AT91C_TC1_IER   ((AT91_REG *) 	0x40010064) // (TC1) Interrupt Enable Register
#define AT91C_TC1_IDR   ((AT91_REG *) 	0x40010068) // (TC1) Interrupt Disable Register
#define AT91C_TC1_SR    ((AT91_REG *) 	0x40010060) // (TC1) Status Register
#define AT91C_TC1_CMR   ((AT91_REG *) 	0x40010044) // (TC1) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC1_RA    ((AT91_REG *) 	0x40010054) // (TC1) Register A
#define AT91C_TC1_RC    ((AT91_REG *) 	0x4001005C) // (TC1) Register C
#define AT91C_TC1_IMR   ((AT91_REG *) 	0x4001006C) // (TC1) Interrupt Mask Register
#define AT91C_TC1_CV    ((AT91_REG *) 	0x40010050) // (TC1) Counter Value
// ========== Register definition for TC2 peripheral ========== 
#define AT91C_TC2_CMR   ((AT91_REG *) 	0x40010084) // (TC2) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC2_CCR   ((AT91_REG *) 	0x40010080) // (TC2) Channel Control Register
#define AT91C_TC2_CV    ((AT91_REG *) 	0x40010090) // (TC2) Counter Value
#define AT91C_TC2_RA    ((AT91_REG *) 	0x40010094) // (TC2) Register A
#define AT91C_TC2_RB    ((AT91_REG *) 	0x40010098) // (TC2) Register B
#define AT91C_TC2_IDR   ((AT91_REG *) 	0x400100A8) // (TC2) Interrupt Disable Register
#define AT91C_TC2_IMR   ((AT91_REG *) 	0x400100AC) // (TC2) Interrupt Mask Register
#define AT91C_TC2_RC    ((AT91_REG *) 	0x4001009C) // (TC2) Register C
#define AT91C_TC2_IER   ((AT91_REG *) 	0x400100A4) // (TC2) Interrupt Enable Register
#define AT91C_TC2_SR    ((AT91_REG *) 	0x400100A0) // (TC2) Status Register
// ========== Register definition for TC3 peripheral ========== 
#define AT91C_TC3_SR    ((AT91_REG *) 	0x40014020) // (TC3) Status Register
#define AT91C_TC3_RC    ((AT91_REG *) 	0x4001401C) // (TC3) Register C
#define AT91C_TC3_RB    ((AT91_REG *) 	0x40014018) // (TC3) Register B
#define AT91C_TC3_CCR   ((AT91_REG *) 	0x40014000) // (TC3) Channel Control Register
#define AT91C_TC3_CMR   ((AT91_REG *) 	0x40014004) // (TC3) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC3_IER   ((AT91_REG *) 	0x40014024) // (TC3) Interrupt Enable Register
#define AT91C_TC3_RA    ((AT91_REG *) 	0x40014014) // (TC3) Register A
#define AT91C_TC3_IDR   ((AT91_REG *) 	0x40014028) // (TC3) Interrupt Disable Register
#define AT91C_TC3_CV    ((AT91_REG *) 	0x40014010) // (TC3) Counter Value
#define AT91C_TC3_IMR   ((AT91_REG *) 	0x4001402C) // (TC3) Interrupt Mask Register
// ========== Register definition for TC4 peripheral ========== 
#define AT91C_TC4_RB    ((AT91_REG *) 	0x40014058) // (TC4) Register B
#define AT91C_TC4_CCR   ((AT91_REG *) 	0x40014040) // (TC4) Channel Control Register
#define AT91C_TC4_IER   ((AT91_REG *) 	0x40014064) // (TC4) Interrupt Enable Register
#define AT91C_TC4_IDR   ((AT91_REG *) 	0x40014068) // (TC4) Interrupt Disable Register
#define AT91C_TC4_SR    ((AT91_REG *) 	0x40014060) // (TC4) Status Register
#define AT91C_TC4_CMR   ((AT91_REG *) 	0x40014044) // (TC4) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC4_RA    ((AT91_REG *) 	0x40014054) // (TC4) Register A
#define AT91C_TC4_RC    ((AT91_REG *) 	0x4001405C) // (TC4) Register C
#define AT91C_TC4_IMR   ((AT91_REG *) 	0x4001406C) // (TC4) Interrupt Mask Register
#define AT91C_TC4_CV    ((AT91_REG *) 	0x40014050) // (TC4) Counter Value
// ========== Register definition for TC5 peripheral ========== 
#define AT91C_TC5_CMR   ((AT91_REG *) 	0x40014084) // (TC5) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC5_CCR   ((AT91_REG *) 	0x40014080) // (TC5) Channel Control Register
#define AT91C_TC5_CV    ((AT91_REG *) 	0x40014090) // (TC5) Counter Value
#define AT91C_TC5_RA    ((AT91_REG *) 	0x40014094) // (TC5) Register A
#define AT91C_TC5_RB    ((AT91_REG *) 	0x40014098) // (TC5) Register B
#define AT91C_TC5_IDR   ((AT91_REG *) 	0x400140A8) // (TC5) Interrupt Disable Register
#define AT91C_TC5_IMR   ((AT91_REG *) 	0x400140AC) // (TC5) Interrupt Mask Register
#define AT91C_TC5_RC    ((AT91_REG *) 	0x4001409C) // (TC5) Register C
#define AT91C_TC5_IER   ((AT91_REG *) 	0x400140A4) // (TC5) Interrupt Enable Register
#define AT91C_TC5_SR    ((AT91_REG *) 	0x400140A0) // (TC5) Status Register
// ========== Register definition for PWMC_CH3 peripheral ========== 
#define AT91C_PWMC_CH3_CUPDR ((AT91_REG *) 	0x40020270) // (PWMC_CH3) Channel Update Register
#define AT91C_PWMC_CH3_Reserved ((AT91_REG *) 	0x40020274) // (PWMC_CH3) Reserved
#define AT91C_PWMC_CH3_CPRDR ((AT91_REG *) 	0x40020268) // (PWMC_CH3) Channel Period Register
#define AT91C_PWMC_CH3_CDTYR ((AT91_REG *) 	0x40020264) // (PWMC_CH3) Channel Duty Cycle Register
#define AT91C_PWMC_CH3_CCNTR ((AT91_REG *) 	0x4002026C) // (PWMC_CH3) Channel Counter Register
#define AT91C_PWMC_CH3_CMR ((AT91_REG *) 	0x40020260) // (PWMC_CH3) Channel Mode Register
// ========== Register definition for PWMC_CH2 peripheral ========== 
#define AT91C_PWMC_CH2_Reserved ((AT91_REG *) 	0x40020254) // (PWMC_CH2) Reserved
#define AT91C_PWMC_CH2_CMR ((AT91_REG *) 	0x40020240) // (PWMC_CH2) Channel Mode Register
#define AT91C_PWMC_CH2_CCNTR ((AT91_REG *) 	0x4002024C) // (PWMC_CH2) Channel Counter Register
#define AT91C_PWMC_CH2_CPRDR ((AT91_REG *) 	0x40020248) // (PWMC_CH2) Channel Period Register
#define AT91C_PWMC_CH2_CUPDR ((AT91_REG *) 	0x40020250) // (PWMC_CH2) Channel Update Register
#define AT91C_PWMC_CH2_CDTYR ((AT91_REG *) 	0x40020244) // (PWMC_CH2) Channel Duty Cycle Register
// ========== Register definition for PWMC_CH1 peripheral ========== 
#define AT91C_PWMC_CH1_Reserved ((AT91_REG *) 	0x40020234) // (PWMC_CH1) Reserved
#define AT91C_PWMC_CH1_CUPDR ((AT91_REG *) 	0x40020230) // (PWMC_CH1) Channel Update Register
#define AT91C_PWMC_CH1_CPRDR ((AT91_REG *) 	0x40020228) // (PWMC_CH1) Channel Period Register
#define AT91C_PWMC_CH1_CCNTR ((AT91_REG *) 	0x4002022C) // (PWMC_CH1) Channel Counter Register
#define AT91C_PWMC_CH1_CDTYR ((AT91_REG *) 	0x40020224) // (PWMC_CH1) Channel Duty Cycle Register
#define AT91C_PWMC_CH1_CMR ((AT91_REG *) 	0x40020220) // (PWMC_CH1) Channel Mode Register
// ========== Register definition for PWMC_CH0 peripheral ========== 
#define AT91C_PWMC_CH0_Reserved ((AT91_REG *) 	0x40020214) // (PWMC_CH0) Reserved
#define AT91C_PWMC_CH0_CPRDR ((AT91_REG *) 	0x40020208) // (PWMC_CH0) Channel Period Register
#define AT91C_PWMC_CH0_CDTYR ((AT91_REG *) 	0x40020204) // (PWMC_CH0) Channel Duty Cycle Register
#define AT91C_PWMC_CH0_CMR ((AT91_REG *) 	0x40020200) // (PWMC_CH0) Channel Mode Register
#define AT91C_PWMC_CH0_CUPDR ((AT91_REG *) 	0x40020210) // (PWMC_CH0) Channel Update Register
#define AT91C_PWMC_CH0_CCNTR ((AT91_REG *) 	0x4002020C) // (PWMC_CH0) Channel Counter Register
// ========== Register definition for PWMC peripheral ========== 
#define AT91C_PWMC_IDR  ((AT91_REG *) 	0x40020014) // (PWMC) PWMC Interrupt Disable Register
#define AT91C_PWMC_DIS  ((AT91_REG *) 	0x40020008) // (PWMC) PWMC Disable Register
#define AT91C_PWMC_IER  ((AT91_REG *) 	0x40020010) // (PWMC) PWMC Interrupt Enable Register
#define AT91C_PWMC_VR   ((AT91_REG *) 	0x400200FC) // (PWMC) PWMC Version Register
#define AT91C_PWMC_ISR  ((AT91_REG *) 	0x4002001C) // (PWMC) PWMC Interrupt Status Register
#define AT91C_PWMC_SR   ((AT91_REG *) 	0x4002000C) // (PWMC) PWMC Status Register
#define AT91C_PWMC_IMR  ((AT91_REG *) 	0x40020018) // (PWMC) PWMC Interrupt Mask Register
#define AT91C_PWMC_MR   ((AT91_REG *) 	0x40020000) // (PWMC) PWMC Mode Register
#define AT91C_PWMC_ENA  ((AT91_REG *) 	0x40020004) // (PWMC) PWMC Enable Register
// ========== Register definition for UDP peripheral ========== 
#define AT91C_UDP_IMR   ((AT91_REG *) 	0x40034018) // (UDP) Interrupt Mask Register
#define AT91C_UDP_FADDR ((AT91_REG *) 	0x40034008) // (UDP) Function Address Register
#define AT91C_UDP_NUM   ((AT91_REG *) 	0x40034000) // (UDP) Frame Number Register
#define AT91C_UDP_FDR   ((AT91_REG *) 	0x40034050) // (UDP) Endpoint FIFO Data Register
#define AT91C_UDP_ISR   ((AT91_REG *) 	0x4003401C) // (UDP) Interrupt Status Register
#define AT91C_UDP_CSR   ((AT91_REG *) 	0x40034030) // (UDP) Endpoint Control and Status Register
#define AT91C_UDP_IDR   ((AT91_REG *) 	0x40034014) // (UDP) Interrupt Disable Register
#define AT91C_UDP_ICR   ((AT91_REG *) 	0x40034020) // (UDP) Interrupt Clear Register
#define AT91C_UDP_RSTEP ((AT91_REG *) 	0x40034028) // (UDP) Reset Endpoint Register
#define AT91C_UDP_TXVC  ((AT91_REG *) 	0x40034074) // (UDP) Transceiver Control Register
#define AT91C_UDP_GLBSTATE ((AT91_REG *) 	0x40034004) // (UDP) Global State Register
#define AT91C_UDP_IER   ((AT91_REG *) 	0x40034010) // (UDP) Interrupt Enable Register

// *****************************************************************************
//               PIO DEFINITIONS FOR AT91SAM3SD8
// *****************************************************************************
#define AT91C_PIO_PA0        ((unsigned int) 1 <<  0) // Pin Controlled by PA0
#define AT91C_PA0_PWM0     ((unsigned int) AT91C_PIO_PA0) //  PWM Channel 0
#define AT91C_PA0_TIOA0    ((unsigned int) AT91C_PIO_PA0) //  Timer Counter 0 Multipurpose Timer I/O Pin A
#define AT91C_PIO_PA1        ((unsigned int) 1 <<  1) // Pin Controlled by PA1
#define AT91C_PA1_PWM1     ((unsigned int) AT91C_PIO_PA1) //  PWM Channel 1
#define AT91C_PA1_TIOB0    ((unsigned int) AT91C_PIO_PA1) //  Timer Counter 0 Multipurpose Timer I/O Pin B
#define AT91C_PIO_PA10       ((unsigned int) 1 << 10) // Pin Controlled by PA10
#define AT91C_PA10_DTXD     ((unsigned int) AT91C_PIO_PA10) //  DBGU Debug Transmit Data
#define AT91C_PA10_NPCS2    ((unsigned int) AT91C_PIO_PA10) //  SPI Peripheral Chip Select 2
#define AT91C_PIO_PA11       ((unsigned int) 1 << 11) // Pin Controlled by PA11
#define AT91C_PA11_NPCS0    ((unsigned int) AT91C_PIO_PA11) //  SPI Peripheral Chip Select 0
#define AT91C_PA11_PWM0     ((unsigned int) AT91C_PIO_PA11) //  PWM Channel 0
#define AT91C_PIO_PA12       ((unsigned int) 1 << 12) // Pin Controlled by PA12
#define AT91C_PA12_MISO     ((unsigned int) AT91C_PIO_PA12) //  SPI Master In Slave
#define AT91C_PA12_PWM1     ((unsigned int) AT91C_PIO_PA12) //  PWM Channel 1
#define AT91C_PIO_PA13       ((unsigned int) 1 << 13) // Pin Controlled by PA13
#define AT91C_PA13_MOSI     ((unsigned int) AT91C_PIO_PA13) //  SPI Master Out Slave
#define AT91C_PA13_PWM2     ((unsigned int) AT91C_PIO_PA13) //  PWM Channel 2
#define AT91C_PIO_PA14       ((unsigned int) 1 << 14) // Pin Controlled by PA14
#define AT91C_PA14_SPCK     ((unsigned int) AT91C_PIO_PA14) //  SPI Serial Clock
#define AT91C_PA14_PWM3     ((unsigned int) AT91C_PIO_PA14) //  PWM Channel 3
#define AT91C_PIO_PA15       ((unsigned int) 1 << 15) // Pin Controlled by PA15
#define AT91C_PA15_TF       ((unsigned int) AT91C_PIO_PA15) //  SSC Transmit Frame Sync
#define AT91C_PA15_TIOA1    ((unsigned int) AT91C_PIO_PA15) //  Timer Counter 1 Multipurpose Timer I/O Pin A
#define AT91C_PIO_PA16       ((unsigned int) 1 << 16) // Pin Controlled by PA16
#define AT91C_PA16_TK       ((unsigned int) AT91C_PIO_PA16) //  SSC Transmit Clock
#define AT91C_PA16_TIOB1    ((unsigned int) AT91C_PIO_PA16) //  Timer Counter 1 Multipurpose Timer I/O Pin B
#define AT91C_PIO_PA17       ((unsigned int) 1 << 17) // Pin Controlled by PA17
#define AT91C_PA17_TD       ((unsigned int) AT91C_PIO_PA17) //  SSC Transmit data
#define AT91C_PA17_PCK1     ((unsigned int) AT91C_PIO_PA17) //  PMC Programmable Clock Output 1
#define AT91C_PIO_PA18       ((unsigned int) 1 << 18) // Pin Controlled by PA18
#define AT91C_PA18_RD       ((unsigned int) AT91C_PIO_PA18) //  SSC Receive Data
#define AT91C_PA18_PCK2     ((unsigned int) AT91C_PIO_PA18) //  PMC Programmable Clock Output 2
#define AT91C_PIO_PA19       ((unsigned int) 1 << 19) // Pin Controlled by PA19
#define AT91C_PA19_RK       ((unsigned int) AT91C_PIO_PA19) //  SSC Receive Clock
#define AT91C_PA19_FIQ      ((unsigned int) AT91C_PIO_PA19) //  AIC Fast Interrupt Input
#define AT91C_PIO_PA2        ((unsigned int) 1 <<  2) // Pin Controlled by PA2
#define AT91C_PA2_PWM2     ((unsigned int) AT91C_PIO_PA2) //  PWM Channel 2
#define AT91C_PA2_SCK0     ((unsigned int) AT91C_PIO_PA2) //  USART 0 Serial Clock
#define AT91C_PIO_PA20       ((unsigned int) 1 << 20) // Pin Controlled by PA20
#define AT91C_PA20_RF       ((unsigned int) AT91C_PIO_PA20) //  SSC Receive Frame Sync
#define AT91C_PA20_IRQ0     ((unsigned int) AT91C_PIO_PA20) //  External Interrupt 0
#define AT91C_PIO_PA21       ((unsigned int) 1 << 21) // Pin Controlled by PA21
#define AT91C_PA21_RXD1     ((unsigned int) AT91C_PIO_PA21) //  USART 1 Receive Data
#define AT91C_PA21_PCK1     ((unsigned int) AT91C_PIO_PA21) //  PMC Programmable Clock Output 1
#define AT91C_PIO_PA22       ((unsigned int) 1 << 22) // Pin Controlled by PA22
#define AT91C_PA22_TXD1     ((unsigned int) AT91C_PIO_PA22) //  USART 1 Transmit Data
#define AT91C_PA22_NPCS3    ((unsigned int) AT91C_PIO_PA22) //  SPI Peripheral Chip Select 3
#define AT91C_PIO_PA23       ((unsigned int) 1 << 23) // Pin Controlled by PA23
#define AT91C_PA23_SCK1     ((unsigned int) AT91C_PIO_PA23) //  USART 1 Serial Clock
#define AT91C_PA23_PWM0     ((unsigned int) AT91C_PIO_PA23) //  PWM Channel 0
#define AT91C_PIO_PA24       ((unsigned int) 1 << 24) // Pin Controlled by PA24
#define AT91C_PA24_RTS1     ((unsigned int) AT91C_PIO_PA24) //  USART 1 Ready To Send
#define AT91C_PA24_PWM1     ((unsigned int) AT91C_PIO_PA24) //  PWM Channel 1
#define AT91C_PIO_PA25       ((unsigned int) 1 << 25) // Pin Controlled by PA25
#define AT91C_PA25_CTS1     ((unsigned int) AT91C_PIO_PA25) //  USART 1 Clear To Send
#define AT91C_PA25_PWM2     ((unsigned int) AT91C_PIO_PA25) //  PWM Channel 2
#define AT91C_PIO_PA26       ((unsigned int) 1 << 26) // Pin Controlled by PA26
#define AT91C_PA26_DCD1     ((unsigned int) AT91C_PIO_PA26) //  USART 1 Data Carrier Detect
#define AT91C_PA26_TIOA2    ((unsigned int) AT91C_PIO_PA26) //  Timer Counter 2 Multipurpose Timer I/O Pin A
#define AT91C_PIO_PA27       ((unsigned int) 1 << 27) // Pin Controlled by PA27
#define AT91C_PA27_DTR1     ((unsigned int) AT91C_PIO_PA27) //  USART 1 Data Terminal ready
#define AT91C_PA27_TIOB2    ((unsigned int) AT91C_PIO_PA27) //  Timer Counter 2 Multipurpose Timer I/O Pin B
#define AT91C_PIO_PA28       ((unsigned int) 1 << 28) // Pin Controlled by PA28
#define AT91C_PA28_DSR1     ((unsigned int) AT91C_PIO_PA28) //  USART 1 Data Set ready
#define AT91C_PA28_TCLK1    ((unsigned int) AT91C_PIO_PA28) //  Timer Counter 1 external clock input
#define AT91C_PIO_PA29       ((unsigned int) 1 << 29) // Pin Controlled by PA29
#define AT91C_PA29_RI1      ((unsigned int) AT91C_PIO_PA29) //  USART 1 Ring Indicator
#define AT91C_PA29_TCLK2    ((unsigned int) AT91C_PIO_PA29) //  Timer Counter 2 external clock input
#define AT91C_PIO_PA3        ((unsigned int) 1 <<  3) // Pin Controlled by PA3
#define AT91C_PA3_TWD      ((unsigned int) AT91C_PIO_PA3) //  TWI Two-wire Serial Data
#define AT91C_PA3_NPCS3    ((unsigned int) AT91C_PIO_PA3) //  SPI Peripheral Chip Select 3
#define AT91C_PIO_PA30       ((unsigned int) 1 << 30) // Pin Controlled by PA30
#define AT91C_PA30_IRQ1     ((unsigned int) AT91C_PIO_PA30) //  External Interrupt 1
#define AT91C_PA30_NPCS2    ((unsigned int) AT91C_PIO_PA30) //  SPI Peripheral Chip Select 2
#define AT91C_PIO_PA31       ((unsigned int) 1 << 31) // Pin Controlled by PA31
#define AT91C_PA31_NPCS1    ((unsigned int) AT91C_PIO_PA31) //  SPI Peripheral Chip Select 1
#define AT91C_PA31_PCK2     ((unsigned int) AT91C_PIO_PA31) //  PMC Programmable Clock Output 2
#define AT91C_PIO_PA4        ((unsigned int) 1 <<  4) // Pin Controlled by PA4
#define AT91C_PA4_TWCK     ((unsigned int) AT91C_PIO_PA4) //  TWI Two-wire Serial Clock
#define AT91C_PA4_TCLK0    ((unsigned int) AT91C_PIO_PA4) //  Timer Counter 0 external clock input
#define AT91C_PIO_PA5        ((unsigned int) 1 <<  5) // Pin Controlled by PA5
#define AT91C_PA5_RXD0     ((unsigned int) AT91C_PIO_PA5) //  USART 0 Receive Data
#define AT91C_PA5_NPCS3    ((unsigned int) AT91C_PIO_PA5) //  SPI Peripheral Chip Select 3
#define AT91C_PIO_PA6        ((unsigned int) 1 <<  6) // Pin Controlled by PA6
#define AT91C_PA6_TXD0     ((unsigned int) AT91C_PIO_PA6) //  USART 0 Transmit Data
#define AT91C_PA6_PCK0     ((unsigned int) AT91C_PIO_PA6) //  PMC Programmable Clock Output 0
#define AT91C_PIO_PA7        ((unsigned int) 1 <<  7) // Pin Controlled by PA7
#define AT91C_PA7_RTS0     ((unsigned int) AT91C_PIO_PA7) //  USART 0 Ready To Send
#define AT91C_PA7_PWM3     ((unsigned int) AT91C_PIO_PA7) //  PWM Channel 3
#define AT91C_PIO_PA8        ((unsigned int) 1 <<  8) // Pin Controlled by PA8
#define AT91C_PA8_CTS0     ((unsigned int) AT91C_PIO_PA8) //  USART 0 Clear To Send
#define AT91C_PA8_ADTRG    ((unsigned int) AT91C_PIO_PA8) //  ADC External Trigger
#define AT91C_PIO_PA9        ((unsigned int) 1 <<  9) // Pin Controlled by PA9
#define AT91C_PA9_DRXD     ((unsigned int) AT91C_PIO_PA9) //  DBGU Debug Receive Data
#define AT91C_PA9_NPCS1    ((unsigned int) AT91C_PIO_PA9) //  SPI Peripheral Chip Select 1

// *****************************************************************************
//               PERIPHERAL ID DEFINITIONS FOR AT91SAM3SD8
// *****************************************************************************
#define AT91C_ID_SUPC   ((unsigned int) 0) // Supply Controller
#define AT91C_ID_RSTC   ((unsigned int)  1) // System Peripheral
#define AT91C_ID_RTC    ((unsigned int)  2) // Real Time Clock
#define AT91C_ID_RTT    ((unsigned int)  3) // Real Time Timer
#define AT91C_ID_WDT    ((unsigned int)  4) // Watchdog
#define AT91C_ID_PMC    ((unsigned int)  5) // PMC
#define AT91C_ID_EFC    ((unsigned int)  6) // EFC
#define AT91C_ID_7_Reserved ((unsigned int) 7) // Reserved
#define AT91C_ID_UART0  ((unsigned int) 8) // UART0
#define AT91C_ID_UART1  ((unsigned int) 9) // UART1
#define AT91C_ID_SMC    ((unsigned int) 10) // SMC
#define AT91C_ID_PIOA   ((unsigned int) 11) // Parallel IO Controller
#define AT91C_ID_PIOB   ((unsigned int) 12) // Parallel IO Controller
#define AT91C_ID_PIOC   ((unsigned int) 13) // Parallel IO Controller
#define AT91C_ID_US0 ((unsigned int) 14) // USART0
#define AT91C_ID_US1 ((unsigned int) 15) // USART1
#define AT91C_ID_16_Reserved ((unsigned int) 16) // Reserved
#define AT91C_ID_17_Reserved ((unsigned int) 17) // Reserved
#define AT91C_ID_HSMCI  ((unsigned int) 18) // HSMCI
#define AT91C_ID_TWI0   ((unsigned int) 19) // Two-Wire Interface
#define AT91C_ID_TWI1   ((unsigned int) 20) // Two-Wire Interface
#define AT91C_ID_SPI    ((unsigned int) 21) // Serial Peripheral Interface
#define AT91C_ID_SSC    ((unsigned int) 22) // Serial Synchronous Controller
#define AT91C_ID_TC0    ((unsigned int) 23) // Timer Counter 0
#define AT91C_ID_TC1    ((unsigned int) 24) // Timer Counter 1
#define AT91C_ID_TC2    ((unsigned int) 25) // Timer Counter 2
#define AT91C_ID_TC3    ((unsigned int) 26) // Timer Counter 3
#define AT91C_ID_TC4    ((unsigned int) 27) // Timer Counter 4
#define AT91C_ID_TC5    ((unsigned int) 28) // Timer Counter 5
#define AT91C_ID_ADC    ((unsigned int) 29) // Analog-to-Digital Converter
#define AT91C_ID_DACC   ((unsigned int) 30) // Reserved
#define AT91C_ID_PWMC   ((unsigned int) 31) // PWM Controller
#define AT91C_ID_CRCCU  ((unsigned int) 32) // Reserved
#define AT91C_ID_ACC    ((unsigned int) 33) // ACC
#define AT91C_ID_UDP    ((unsigned int) 34) // ACC
#define AT91C_ALL_INT   ((unsigned long) 0x2BFFDFFFE) // ALL VALID INTERRUPTS


// *****************************************************************************
//               BASE ADDRESS DEFINITIONS FOR AT91SAM3SD8
// *****************************************************************************
#define AT91C_BASE_SYS       ((AT91PS_SYS) 	0x400E0000) // (SYS) Base Address
#define AT91C_BASE_PIOA      ((AT91PS_PIO) 	0x400E0E00) // (PIOA) Base Address
#define AT91C_BASE_PIOB      ((AT91PS_PIO) 	0x400E1000) // (PIOA) Base Address
#define AT91C_BASE_PIOC      ((AT91PS_PIO) 	0x400E1200) // (PIOA) Base Address
//#define AT91C_BASE_CKGR      ((AT91PS_CKGR) 	0xFFFFFC20) // (CKGR) Base Address
#define AT91C_BASE_PMC       ((AT91PS_PMC) 	0x400E0400) // (PMC) Base Address
#define AT91C_BASE_RSTC      ((AT91PS_RSTC) 	0x400E1400) // (RSTC) Base Address
#define AT91C_BASE_RTTC      ((AT91PS_RTTC) 	0x400E1430) // (RTTC) Base Address
#define AT91C_BASE_PITC      ((AT91PS_PITC) 	0x400E1460) // (RTCC) Base Address
#define AT91C_BASE_WDTC      ((AT91PS_WDTC) 	0X400e1450) // (WDTC) Base Address
#define AT91C_BASE_SUPC      ((AT91PS_SUPC) 	0x400E1410) // (SUPC) Base Address
#define AT91C_BASE_SMC        ((AT91PS_SMC) 	0x400E0000) // (SMC) Base Address
#define AT91C_BASE_PDC_SPI   ((AT91PS_PDC) 	0x40008100) // (PDC_SPI) Base Address
#define AT91C_BASE_SPI       ((AT91PS_SPI) 	0x40008000) // (SPI) Base Address
#define AT91C_BASE_PDC_ADC   ((AT91PS_PDC) 	0x40038100) // (PDC_ADC) Base Address
#define AT91C_BASE_ADC       ((AT91PS_ADC) 	0x40038000) // (ADC) Base Address
#define AT91C_BASE_PDC_SSC   ((AT91PS_PDC) 	0x40004100) // (PDC_SSC) Base Address
#define AT91C_BASE_SSC       ((AT91PS_SSC) 	0x40004000) // (SSC) Base Address
#define AT91C_BASE_PDC_US1   ((AT91PS_PDC) 	0x40028100) // (PDC_US1) Base Address
#define AT91C_BASE_US1       ((AT91PS_USART) 	0x40028000) // (US1) Base Address
#define AT91C_BASE_PDC_US0   ((AT91PS_PDC) 	0x40024100) // (PDC_US0) Base Address
#define AT91C_BASE_US0       ((AT91PS_USART) 	0x40024000) // (US0) Base Address
#define AT91C_BASE_TWI       ((AT91PS_TWI) 	0x40018000) // (TWI) Base Address
#define AT91C_BASE_TC0       ((AT91PS_TC) 	0x40010000) // (TC0) Base Address
#define AT91C_BASE_TC1       ((AT91PS_TC) 	0x40010040) // (TC1) Base Address
#define AT91C_BASE_TC2       ((AT91PS_TC) 	0x40010080) // (TC2) Base Address
#define AT91C_BASE_TC3       ((AT91PS_TC) 	0x40014000) // (TC3) Base Address
#define AT91C_BASE_TC4       ((AT91PS_TC) 	0x40014040) // (TC4) Base Address
#define AT91C_BASE_TC5       ((AT91PS_TC) 	0x40014080) // (TC5) Base Address
#define AT91C_BASE_PWMC_CH3  ((AT91PS_PWMC_CH) 	0x40020260) // (PWMC_CH3) Base Address
#define AT91C_BASE_PWMC_CH2  ((AT91PS_PWMC_CH) 	0x40020240) // (PWMC_CH2) Base Address
#define AT91C_BASE_PWMC_CH1  ((AT91PS_PWMC_CH) 	0x40020220) // (PWMC_CH1) Base Address
#define AT91C_BASE_PWMC_CH0  ((AT91PS_PWMC_CH) 	0x40020200) // (PWMC_CH0) Base Address
#define AT91C_BASE_PWMC      ((AT91PS_PWMC) 	0x40020000) // (PWMC) Base Address
#define AT91C_BASE_UDP       ((AT91PS_UDP) 	0x40034000) // (UDP) Base Address

// *****************************************************************************
//               MEMORY MAPPING DEFINITIONS FOR AT91SAM3SD8
// *****************************************************************************
// ISRAM
#define AT91C_ISRAM	 ((char *) 	0x20000000) // Internal SRAM base address
#define AT91C_ISRAM_SIZE	 ((unsigned int) 0x00010000) // Internal SRAM size in byte (64 Kbytes)
// IFLASH
#define AT91C_IFLASH	 ((char *) 	0x00000000) // Internal FLASH base address
#define AT91C_IFLASH_SIZE	 ((unsigned int) 0x00080000) // Internal FLASH size in byte (512 Kbytes)
#define AT91C_IFLASH_PAGE_SIZE	 ((unsigned int) 256) // Internal FLASH Page Size: 256 bytes
#define AT91C_IFLASH_LOCK_REGION_SIZE	 ((unsigned int) 4096) // Internal FLASH Lock Region Size: 4 Kbytes
#define AT91C_IFLASH_NB_OF_PAGES	 ((unsigned int) 1024) // Internal FLASH Number of Pages: 1024 bytes
#define AT91C_IFLASH_NB_OF_LOCK_BITS	 ((unsigned int) 8) // Internal FLASH Number of Lock Bits: 8 bytes

#endif
