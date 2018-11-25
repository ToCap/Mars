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

#ifndef TCK_H
#define TCK_H

/**
 * \defgroup Tck
 */
 
/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Tck_Cfg.h"



/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Tck 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Tck module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define	TCK_MODULE_ID						MODULE_ID_CPLX

/*!
 * \ingroup Tck 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Tck module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define TCK_VENDOR_ID						0x0//TODO : A coder


/*!
 * \ingroup Tck 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Tck module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define TCK_SW_MAJOR_VERSION 				1
#define TCK_SW_MINOR_VERSION 				0
#define TCK_SW_PATCH_VERSION				0

#define TCK_AR_RELEASE_MAJOR_VERSION		4
#define TCK_AR_RELEASE_MINOR_VERSION		2
#define TCK_AR_RELEASE_REVISION_VERSION		1

/*! 
 * \ingroup Tck
 * \defgroup Tck_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (TCK_DEV_ERROR_DETECT == STD_ON)
#define	TCK_E_PARAM_POINTER				0x11 /*!< API function called with a NULL pointer */
#define	TCK_E_PARAM_DATA				0x12 /*!< API function called with wrong parameter value */
#define TCK_E_UNINIT					0x20 /*!< API function called before the Tck driver has been full initialized or after the Tck driver has been shut down */
#endif
/** @} */ // end of PORT_DevelopmentErrors

/*! 
 * \ingroup Tck
 * \defgroup Tck_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define TCK_INIT_ID							0x00


/** @} */ // end of Tck_Apis

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
void Tck_BusyWait1ms(uint32 WaitingTimeMin);
void Tck_BusyWait1ns(uint32 WaitingTimeMin);
uint32 Tck_GetCurrentTickCounter(void);

#endif /*TCK_H*/
