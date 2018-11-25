/*
 ***************************************************************************************************
 * MARS - the open source AR platform for Mindstorm https://github.com/ToCap/Mars
 *
 * Copyright (C) 2020  GC-MS Software (ThomTheCat)
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 ***************************************************************************************************
*/

#ifndef TWI_NXC
#define TWI_NXC
/**
 * \defgroup Twi
*/

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "AT91SAM7.h"
#include "Aic.h"						/**/
#include "Det.h"
#include "Twi.h"						/**/

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
#define I2CClk								400000L//TODO : Trouver un meilleur nom
#define CLDIV								(((CLOCK_FREQUENCY/I2CClk)/2)-3)//TODO : Trouver un meilleur nom
#define TWCK (1 << 4)//TODO : Trouver un meilleur nom
#define TWD (1 << 3)//TODO : Trouver un meilleur nom

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/

/**
 * \ingroup Twi 
 * \enum Twi_StateType
 * \brief ???
 * \remarks
 */
typedef enum 
{
  TWI_PRV_UNINITIALISED = 0,
  TWI_PRV_FAILED,//TODO : verifier l'utilie
  TWI_PRV_IDLE,
  TWI_PRV_DONE,
  TWI_PRV_RX_BUSY,
  TWI_PRV_TX_BUSY,
  
} Twi_Prv_StatusType;


/*
 ***************************************************************************************************
 * Interrupts
 ***************************************************************************************************
*/
extern void twi_isr_entry(void);
extern uint32 interrupts_get_and_disable(void);
extern void interrupts_enable(void);


/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
*/
/** \var Twi_stMain
 *  \brief ???
 */
static Twi_Prv_StatusType Twi_stMain;



/** \var Twi_stInit
 *  \brief ???
 */
uint8 Twi_stInit = STD_INIT_STATE_UNINIT;

static uint32 Twi_Prv_ctPending;
static uint8* Twi_Prv_xBufPtr;

static uint32 Twi_Prv_stMask;

/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/


/**
 * \ingroup Twi
 * \brief Returns the status of the specified TWI Hardware microcontroller peripheral
 * \param	HWUnit	TWI Hardware microcontroller peripheral (unit) ID
 * \return	Twi_StatusType
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard but follows Spi
*/
Twi_StatusType Twi_GetHWUnitStatus(Twi_HWUnitType HWUnit)
{
  return (Twi_stMain > TWI_PRV_DONE ? TWI_BUSY : (Twi_stMain < TWI_PRV_IDLE ? TWI_UNINIT : TWI_IDLE));
}


/**
 * \ingroup Twi
 * \brief Start an asynchronous read operation of data from specified TWI device
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard but follows Spi
*/
Std_ReturnType Twi_AsyncReceive(uint32 DeviceAddress, uint8* Buffer, uint16 LenByte)
{
	/* Declaration of local variables */
	Std_ReturnType 			stRetVal;
	
	/* Initialize variables with default value */
	stRetVal = E_OK;					/*operation sucessful*/
	

	/* Check Twi driver initialisation status */
	if (Twi_stInit == STD_INIT_STATE_INIT)
	{
		/* On Avr driver is fully initialized, Check if transmission is already on-going */
		if (Twi_stMain < TWI_PRV_RX_BUSY)
		{
			/* On no transmission is already on-going, Start receiving operation */
			Twi_stMain = TWI_PRV_RX_BUSY;
			/* HINTS : Critical section is not required since integer write operation is atomic */
		
			/* Initialize */
			Twi_Prv_xBufPtr = Buffer;
			Twi_Prv_ctPending = LenByte;
			
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
			/* */
			*AT91C_TWI_MMR = AT91C_TWI_IADRSZ_NO|AT91C_TWI_MREAD|((DeviceAddress & 0x7f) << 16);
			Twi_Prv_stMask = AT91C_TWI_RXRDY|AT91C_TWI_NACK;
			*AT91C_TWI_CR = AT91C_TWI_START;
			*AT91C_TWI_IER = AT91C_TWI_RXRDY;
#endif
		}
		else
		{
			/* On transmission is already on-going, Return error */
			stRetVal = E_NOT_OK;
		}
	}
	else
	{
		/* On initialisation is on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (TWI_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(TWI_MODULE_ID, 0, TWI_ASYNCRECEIVE_ID, TWI_E_UNINIT);
		#endif	
	}

	return stRetVal;
}



Std_ReturnType Twi_AsyncSend(uint32 DeviceAddress, const uint8* Buffer, uint16 LenByte)
{
	/* Declaration of local variables */
	Std_ReturnType 			stRetVal;
	
	/* Initialize variables with default value */
	stRetVal = E_OK;					/*operation sucessful*/
	

	/* Check Twi driver initialisation status */
	if (Twi_stInit == STD_INIT_STATE_INIT)
	{
		/* On Avr driver is fully initialized, Check if transmission is already on-going */
		if (Twi_stMain < TWI_PRV_RX_BUSY)
		{
			/* On no transmission is already on-going, Start receiving operation */
			Twi_stMain = TWI_PRV_TX_BUSY;
			/* HINTS : Critical section is not required since integer write operation is atomic */
				
			/* Initialize */
			Twi_Prv_xBufPtr = (uint8*)Buffer;
			Twi_Prv_ctPending = LenByte;
			
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
			*AT91C_TWI_MMR = AT91C_TWI_IADRSZ_NO|((DeviceAddress & 0x7f) << 16);
			*AT91C_TWI_THR = *Twi_Prv_xBufPtr++;
			Twi_Prv_ctPending--;
			//STATS(twi_stats.bytes_tx++)
			Twi_Prv_stMask = AT91C_TWI_TXRDY|AT91C_TWI_NACK;
			*AT91C_TWI_IER = AT91C_TWI_TXRDY;
#endif			
		}
		else
		{
			/* On transmission is already on-going, Return error */
			stRetVal = E_NOT_OK;
		}
	}
	else
	{
		/* On initialisation is on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (TWI_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(TWI_MODULE_ID, 0, TWI_ASYNCSEND_ID, TWI_E_UNINIT);
		#endif	
	}

	return stRetVal;
}

/**
 * \ingroup Twi
 * \brief Initialize or reinitializes the Twi module
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard but follows Spi
*/
Std_ReturnType Twi_ReInit(void)
{
	/* Declaration of local variables */
	uint32 stInterrupt;
	Std_ReturnType 			stRetVal;
	
	/* Initialize variables with default value */
	stRetVal = E_OK;					/*operation sucessful*/
	

	/* Disable all interrupts */
	stInterrupt = interrupts_get_and_disable();

	/* Configure hardware registers */	
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	*AT91C_TWI_IDR = ~0;		/* Disable all interrupt sources */
#endif
	
	/* Configure interrupt line for ISR of Twi */
	Aic_DisableInterruptLine(AT91C_ID_TWI);
	(void)Aic_SetInterruptLine(AT91C_ID_TWI, AIC_INT_LEVEL_ABOVE_NORMAL, (uint32)twi_isr_entry);
	Aic_EnableInterruptLine(AT91C_ID_TWI);

	/* Force hardware reset to finish re-initialisation */
	Twi_Reset();

	
	Twi_stMain = TWI_IDLE;

	/* Enable all interrupts */
	if (stInterrupt) {interrupts_enable();}

	return stRetVal;
}


/**
 * \ingroup Twi
 * \brief Initialize or reinitializes the Twi module
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard but follows Spi
*/
void Twi_Reset(void)
{
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	/* Declaration of local variables */
	uint32 clocks = 9;//TODO : utiliser une sysco

	*AT91C_TWI_IDR = ~0;

	*AT91C_PMC_PCER = (1 << AT91C_ID_PIOA) |	/* Need PIO too */
		(1 << AT91C_ID_TWI);	/* TWI clock domain */

	/* Set up pin as an IO pin for clocking till clean */
	*AT91C_PIOA_MDER = TWD | TWCK;
	*AT91C_PIOA_PER = TWD | TWCK;
	*AT91C_PIOA_ODR = TWD;
	*AT91C_PIOA_OER = TWCK;

	while (clocks > 0 && !(*AT91C_PIOA_PDSR & TWD))
	{
		*AT91C_PIOA_CODR = TWCK;
		Tck_BusyWait1ns(1500);
		*AT91C_PIOA_SODR = TWCK;
		Tck_BusyWait1ns(1500);
		clocks--;
	}

	*AT91C_PIOA_PDR = TWD | TWCK;
	*AT91C_PIOA_ASR = TWD | TWCK;

	*AT91C_TWI_CR = AT91C_TWI_SWRST|AT91C_TWI_MSDIS;/* Disable & reset */

	*AT91C_TWI_CWGR = ((CLDIV << 8)|CLDIV);       /* Set for 400kHz */
	*AT91C_TWI_CR = AT91C_TWI_MSEN;		/* Enable as master */
	*AT91C_TWI_IER = AT91C_TWI_NACK;
#endif

	Twi_Prv_stMask = 0u;
}

/*
 ***************************************************************************************************
 * Processes
 ***************************************************************************************************
*/
/**
 * \ingroup Twi
 * \brief Initialize or reinitializes the Twi driver
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Twi_Init(void)
{
	(void)Twi_ReInit();
	

    /* Update Twi initialisation status */
	Twi_stInit = STD_INIT_STATE_INIT;
}


void Twi_Proc_Isr(void)
{
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	/* Declaration of local variables */
	uint32 stCurr;
	
	/* Get current hardware status */
	stCurr = *AT91C_TWI_SR & Twi_Prv_stMask;
	
	/* Switch on current hardware status */
	if (stCurr & AT91C_TWI_RXRDY)
	{
		/* On receive transmission is on-going, Switch on number of pending bytes */
		if (Twi_Prv_ctPending > (uint16)1)
		{
			/* On transmission is on-going, Copy to local buffer */
			*Twi_Prv_xBufPtr++ = *AT91C_TWI_RHR;
			Twi_Prv_ctPending--;
		}
		else if (Twi_Prv_ctPending == (uint16)1)
		{
			/* On second last byte, Issue a stop on the next byte */
			*AT91C_TWI_CR = AT91C_TWI_STOP;
		}
		else if (Twi_Prv_ctPending == (uint16)0)
		{
			/* On transmission is over, */
			Twi_stMain = TWI_PRV_DONE;
			*AT91C_TWI_IDR = AT91C_TWI_RXRDY;
		}
		else
		{
			/* Do nothing */
		}
	}
	else if (stCurr & AT91C_TWI_TXRDY)
	{
		/* On send transmission is on-going, Switch on number of pending bytes */
		if (Twi_Prv_ctPending > (uint16)0)
		{
			/* On transmission is on-going, Copy from local buffer */
			*AT91C_TWI_THR = *Twi_Prv_xBufPtr++;
			Twi_Prv_ctPending--;
		}
		else
		{
			/* On transmission is over, Wait for acknowledge */
			*AT91C_TWI_IDR = AT91C_TWI_TXRDY;
			*AT91C_TWI_IER = AT91C_TWI_TXCOMP;
			Twi_Prv_stMask = AT91C_TWI_TXCOMP|AT91C_TWI_NACK;
		}
	}
	else if (stCurr & AT91C_TWI_TXCOMP)
	{
		/* On acknowledge, */
		Twi_stMain = TWI_PRV_DONE;
		*AT91C_TWI_IDR = AT91C_TWI_TXCOMP;
	}
	else if (stCurr & AT91C_TWI_NACK)
	{
		/* On N-acknowledge, Reset*/
		*AT91C_TWI_IDR = ~0;
		Twi_stMain = TWI_PRV_UNINITIALISED;
	}
	else
	{
		/* Do nothing */
	}
#endif	
}
#endif /*TWI_NXC*/
