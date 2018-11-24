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

#ifndef AIC_H
#define AIC_H

/**
 * \defgroup Aic
 */
 

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/

#include "Std_Types.h"
#include "AT91SAM7.h"
#include "Aic_Cfg.h"




/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Aic 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Aic module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define	AIC_MODULE_ID						MODULE_ID_CPLX

/*!
 * \ingroup Aic 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Aic module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define AIC_VENDOR_ID						0x0


/*!
 * \ingroup Aic 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Aic module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define AIC_SW_MAJOR_VERSION 				1
#define AIC_SW_MINOR_VERSION 				0
#define AIC_SW_PATCH_VERSION				0

#define AIC_AR_RELEASE_MAJOR_VERSION		4
#define AIC_AR_RELEASE_MINOR_VERSION		2
#define AIC_AR_RELEASE_REVISION_VERSION		1


/*!
 * \ingroup Aic 
 * \defgroup Aic_PriorityLevelTypes
 *  This is the first group
 *  @{
 */
#define AIC_INT_LEVEL_LOWEST				1
#define AIC_INT_LEVEL_LOW					2
#define AIC_INT_LEVEL_NORMAL				4
#define AIC_INT_LEVEL_ABOVE_NORMAL			5
/** @} */ // end of Aic_PriorityLevelTypes


#define AIC_NUM_INTERRUPTLINE_MAX			32u

/*! 
 * \ingroup Aic
 * \defgroup Aic_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (AIC_DEV_ERROR_DETECT == STD_ON)
#define	AIC_E_PARAM_POINTER				0x11 /*!< API function called with a NULL pointer */
#define	AIC_E_PARAM_DATA				0x12 /*!< API function called with wrong parameter value */
#define AIC_E_UNINIT					0x20 /*!< API function called before the Aic driver has been full initialized or after the Aic driver has been shut down */
#endif
/** @} */ // end of PORT_DevelopmentErrors

/*! 
 * \ingroup Aic
 * \defgroup Aic_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define AIC_INIT_ID							0x00
#define AIC_DISABLEINTERRUPTLINE_ID			0x01
#define AIC_ENABLEINTERRUPTLINE_ID			0x02
#define AIC_RESETINTERRUPTLINE_ID			0x03
#define AIC_SETINTERRUPTLINE_ID				0x04


/** @} */ // end of Aic_Apis

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/

void Aic_Init(void);

void Aic_DisableInterruptLine(uint32 VectorId);
void Aic_EnableInterruptLine(uint32 VectorId);
void Aic_ResetInterruptLine(uint32 VectorId);
Std_ReturnType Aic_SetInterruptLine(uint32 VectorId, uint32 Mode, uint32 ISR);

#endif /*AIC_H*/
