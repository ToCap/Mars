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

#ifndef TCK_NXC
#define TCK_NXC
/**
 * \defgroup Tck
*/

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "AT91SAM7.h"

/* Includes of "Platform" headers */
#include "Aic.h"						/**/

/* Include of common headers */
#include "Det.h"
#include "Dem.h"	

/* Includes of specific headers */
#include "Tck.h"						/**/
#include "Tck_MemMap.h"					/**/
#include "SchM_Tck.h"					/**/


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
#define TCK_LOW_PRIORITY_IRQ				10//TODO : a definir ailleurs ?

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/


/*
 ***************************************************************************************************
 * Interrupts
 ***************************************************************************************************
*/
extern void systick_isr_entry(void);
extern void systick_low_priority_entry(void);
extern uint32 interrupts_get_and_disable(void);
extern void interrupts_enable(void);

/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
*/

/** \var Mcu_Prv_ctrSysTick
 *  \brief ???
 *  \par : Measurement visibility : No
 */
static volatile uint32 Tck_Prv_ctrSysTick;

/** \var Tck_stInit
 *  \brief ???
 */
uint8 Tck_stInit = STD_INIT_STATE_UNINIT;



/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/

void Tck_BusyWait1ms(uint32 WaitingTimeMin)
{
	/* Declaration of local variables */
	volatile uint32 ctrEndTimer = Tck_Prv_ctrSysTick + WaitingTimeMin;

	while (Tck_Prv_ctrSysTick < ctrEndTimer)
	{
		/* Do nothing */
	}
}


void Tck_BusyWait1ns(uint32 WaitingTimeMin)
{
	volatile uint32 x = (WaitingTimeMin >> 7) + 1;

	while (x)
	{
		x--;
	}
}


/**
 * \ingroup Tck
 * Return
 *
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * None
*/
uint32 Tck_GetCurrentTickCounter(void)
{
	return Tck_Prv_ctrSysTick;
	/* HINTS : System tick counter is stored as a single 32bits integer 
				therefore read/write operations are atomic and critical section is useless */
}


void Tck_Resume()
{
	Aic_EnableInterruptLine(TCK_LOW_PRIORITY_IRQ);
}


void Tck_Suspend()
{
	Aic_DisableInterruptLine(TCK_LOW_PRIORITY_IRQ);
}

/*
 ***************************************************************************************************
 * Processes
 ***************************************************************************************************
*/
/**
 * \ingroup Tck
 * \brief Initialize or reinitializes the Tck module
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Tck_Init(void)
{
	/* Declaration of local variables */
	uint32 stInterrupt;
	
	/* Disable all interrupts */
	stInterrupt = interrupts_get_and_disable();

	/* Configure interrupt line for low priority ISR of Tck */
	Aic_DisableInterruptLine(TCK_LOW_PRIORITY_IRQ);
	(void)Aic_SetInterruptLine(TCK_LOW_PRIORITY_IRQ, (1 << 5) /* positive internal edge */ |
		AIC_INT_LEVEL_LOW, (uint32)systick_low_priority_entry);
	Aic_EnableInterruptLine(TCK_LOW_PRIORITY_IRQ);

	/* Configure interrupt line for standard priority ISR of Tck */
	Aic_DisableInterruptLine(AT91C_PERIPHERAL_ID_SYSIRQ);
	(void)Aic_SetInterruptLine(AT91C_PERIPHERAL_ID_SYSIRQ, (1 << 5) /* positive internal edge */ |
		AIC_INT_LEVEL_NORMAL, (uint32) systick_isr_entry);
	Aic_EnableInterruptLine(AT91C_PERIPHERAL_ID_SYSIRQ);
	
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	/* Activate all ISR of Tck hardware module */
	*AT91C_PITC_PIMR = ((CLOCK_FREQUENCY / 16 / PIT_FREQ) - 1) | 0x03000000;
#endif

	/* Enable all interrupts */
	if (stInterrupt) {interrupts_enable();}
		
    /* Update Tck initialisation status */
	Tck_stInit = STD_INIT_STATE_INIT;
}


/**
 * \ingroup Tck
 *
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Deviations : not specified in AR standard 
*/
void Tck_Proc_Isr(void)
{
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	/* Declaration of local variables */
	uint32 stToto;
	
	/* Read status to confirm interrupt */
	stToto = *AT91C_PITC_PIVR;

	/* Update with number of ticks since last time */
	Tck_Prv_ctrSysTick += ((stToto & AT91C_SYSC_PICNT) >> 20);
	
	/* Trigger low priority task */
	*AT91C_AIC_ISCR = (1 << TCK_LOW_PRIORITY_IRQ);
#endif
}

#endif /*TCK_NXC*/
