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

#ifndef AIC_NXC
#define AIC_NXC
/**
 * \defgroup Aic
*/

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Det.h"
#include "Dem.h"	
#include "Aic.h"						/**/
#include "Aic_Prv.h"					/**/



/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/



/*
 ***************************************************************************************************
 * Interrupts
 ***************************************************************************************************
*/
extern uint32 interrupts_get_and_disable(void);
extern void interrupts_enable(void);

/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
*/

#define Aic_Prv_xSysCtrl ((volatile struct _AT91S_SYSC *)0xFFFFF000)


/** \var Aic_stInit
 *  \brief ???
 */
uint8 Aic_stInit = STD_INIT_STATE_UNINIT;



/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/


/**
 * \ingroup Aic
 * \brief	Disable handling of an interrupt line in the AIC
 * \param	VectorId	Identification of a peripheral by assigned VectorId
 * 
*/
void Aic_DisableInterruptLine(uint32 VectorId)
{
	/* Declaration of local variables */
	uint32 stInterrupt;
	
	
	/* Check if specified VectorId is valid */
	if (VectorId < AIC_NUM_INTERRUPTLINE_MAX)
	{
		/* On specified vector is valid, Update register under critical section */
		stInterrupt = interrupts_get_and_disable();

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
		Aic_Prv_xSysCtrl->SYSC_AIC_IDCR = (1 << VectorId);
#endif

		/* Enable all interrupts */
		if (stInterrupt) {interrupts_enable();}
	}
	else
	{
		/* On specified vector is NOT valid, Return error */
		
		/* Trace error in Det if required */
		#if (AIC_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AIC_MODULE_ID, 0, AIC_DISABLEINTERRUPTLINE_ID, AIC_E_PARAM_DATA);
		#endif	
	}
}


/**
 * \ingroup Aic
 * \brief	Enable handling of an interrupt line in the AIC
 * \param	VectorId	Identification of a peripheral by assigned VectorId
 * 
*/
void Aic_EnableInterruptLine(uint32 VectorId)
{
	/* Declaration of local variables */
	uint32 stInterrupt;
	
	/* Check if specified VectorId is valid */
	if (VectorId < AIC_NUM_INTERRUPTLINE_MAX)
	{
		/* On specified vector is valid, Update register under critical section */
		stInterrupt = interrupts_get_and_disable();

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
		Aic_Prv_xSysCtrl->SYSC_AIC_IECR = (1 << VectorId);
#endif

		/* Enable all interrupts */
		if (stInterrupt) {interrupts_enable();}
	}
	else
	{
		/* On specified vector is NOT valid, Return error */
		
		/* Trace error in Det if required */
		#if (AIC_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AIC_MODULE_ID, 0, AIC_ENABLEINTERRUPTLINE_ID, AIC_E_PARAM_DATA);
		#endif	
	}
}


/**
 * \ingroup Aic
 * \brief	Reset an interrupt line in the AIC
 * \param	VectorId	Identification of a peripheral by assigned VectorId
 * 
*/
void Aic_ResetInterruptLine(uint32 VectorId)
{
	/* Declaration of local variables */
	uint32 stInterrupt;

	/* Check if specified VectorId is valid */
	if (VectorId < AIC_NUM_INTERRUPTLINE_MAX)
	{
		/* On specified vector is valid, Update register under critical section */
		stInterrupt = interrupts_get_and_disable();
#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
		Aic_Prv_xSysCtrl->SYSC_AIC_ICCR = (1 << VectorId);
#endif

		/* Enable all interrupts */
		if (stInterrupt) {interrupts_enable();}

	}
	else
	{
		/* On specified vector is NOT valid, Return error */
		
		/* Trace error in Det if required */
		#if (AIC_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AIC_MODULE_ID, 0, AIC_RESETINTERRUPTLINE_ID, AIC_E_PARAM_DATA);
		#endif	
	}
}


/**
 * \ingroup Aic
 * \brief	Register an interrupt service routine for a specified interrupt line
 * \remarks	 Note that while this function registers the routine in the AIC, it
 * does not enable or disable the interrupt line for that VectorId. Use
 * aic_mask_on and aic_mask_off to control actual activation of the interrupt line
 * \param	VectorId	Identification of a peripheral by assigned VectorId
 * \param	Mode		Priority of this interrupt in relation to others 
 * \param	ISR			Pointer to the interrupt service routine function 
 * \return	Std_ReturnType
 *				E_OK		
 *				E_NOT_OK	
 * 
*/
Std_ReturnType Aic_SetInterruptLine(uint32 VectorId, uint32 Mode, uint32 ISR)
{
	/* Declaration of local variables */
	uint32 stInterrupt;
	Std_ReturnType stRetVal;
	
	/* Initialize variables with default value */
	stRetVal = E_OK;					/*operation successful*/
	
	/* Check if specified VectorId is valid */
	if (VectorId < AIC_NUM_INTERRUPTLINE_MAX)
	{
		/* On specified vector is valid, Update register under critical section */
		stInterrupt = interrupts_get_and_disable();

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
		Aic_Prv_xSysCtrl->SYSC_AIC_SMR[VectorId] = Mode;
		Aic_Prv_xSysCtrl->SYSC_AIC_SVR[VectorId] = ISR;
#endif

		/* Enable all interrupts */
		if (stInterrupt) {interrupts_enable();}
	}
	else
	{
		/* On specified vector is NOT valid, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (AIC_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AIC_MODULE_ID, 0, AIC_SETINTERRUPTLINE_ID, AIC_E_PARAM_DATA);
		#endif	
	}
	
	return stRetVal;
}







/*
 ***************************************************************************************************
 * Processes
 ***************************************************************************************************
*/
/**
 * \ingroup Aic
 * \brief Initialize or reinitializes the Aic module
 *
 * commentaire supplementaire
 * \return	void
 * \remarks	The function leaves interrupts disabled in the ARM core when it returns, so that other board drivers may register interrupt handlers safely
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Aic_Init(void)
{

	/* Declaration of local variables */
	uint32 idxSource;

	/* Prevent the ARM core from being interrupted while we set up the
	* AIC.
	*/
	interrupts_get_and_disable();

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2)
	/* Set Aic into known state whatever previous state */
	Aic_Prv_xSysCtrl->SYSC_AIC_IDCR = 0xFFFFFFFF;
	Aic_Prv_xSysCtrl->SYSC_AIC_FFDR = 0xFFFFFFFF;
	Aic_Prv_xSysCtrl->SYSC_AIC_ICCR = 0xFFFFFFFF;
	Aic_Prv_xSysCtrl->SYSC_AIC_EOICR = 1;
	/* HINTS : When coming from a warm boot, the AIC may be in a weird state. 
				Therefore this is necessary to do some cleaning up to bring the AIC back into a known state:
					- All interrupt lines disabled
					- No interrupt lines handled by the FIQ handler
					- No pending interrupts
					- AIC idle, not handling an interrupt*/

	/* Enable debug protection. This is necessary for JTAG debugging, so
	* that the hardware debugger can read AIC registers without
	* triggering side-effects.
	*/
	Aic_Prv_xSysCtrl->SYSC_AIC_DCR = 1;

	/* Set default handlers for all interrupt lines */
	for (idxSource = 0; idxSource < 32; idxSource++)
	{
		Aic_Prv_xSysCtrl->SYSC_AIC_SMR[idxSource] = 0;
		Aic_Prv_xSysCtrl->SYSC_AIC_SVR[idxSource] = (uint32)default_isr;
	}
	
	Aic_Prv_xSysCtrl->SYSC_AIC_SVR[AT91C_PERIPHERAL_ID_FIQ] = (uint32)default_fiq;
	Aic_Prv_xSysCtrl->SYSC_AIC_SPU = (uint32)spurious_isr;
#endif
    /* Update initialisation status */
	Aic_stInit = STD_INIT_STATE_INIT;
}
#endif /*AIC_NXC*/
