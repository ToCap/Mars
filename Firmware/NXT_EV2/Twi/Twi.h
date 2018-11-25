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

#ifndef TWI_H
#define TWI_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Twi_Cfg.h"					/*pre-compiler configuration*/
#include "Std_Types.h"



/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/
/*!
 * \ingroup Twi 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00379
 */
#define	TWI_MODULE_ID					MODULE_ID_CPLX

/*!
 * \ingroup Twi 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00374
 */
#define TWI_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Twi 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00003, SRS_BSW_00318, SRS_BSW_00321
 */
#define TWI_SW_MAJOR_VERSION 				1
#define TWI_SW_MINOR_VERSION 				0
#define TWI_SW_PATCH_VERSION				0

#define TWI_AR_RELEASE_MAJOR_VERSION		4
#define TWI_AR_RELEASE_MINOR_VERSION		2
#define TWI_AR_RELEASE_REVISION_VERSION		1


/**
 * \ingroup Twi 
 * \def Twi_HWUnitType
 * \brief ???
 * \remarks
 */
typedef uint8 Twi_HWUnitType;

/**
 * \ingroup Twi 
 * \def Twi_ChannelType
 * \brief ???
 * \remarks
 */
typedef uint8 Twi_ChannelType;

/**
 * \ingroup Twi 
 * \enum Twi_StatusType
 * \brief ???
 * \remarks
 */
typedef enum 
{
	TWI_UNINIT, /*!< The TWI Driver is not initialized or not usable */
	TWI_IDLE, /*!< The TWI Driver is not currently transmitting any Job */
	TWI_BUSY /*!< The TWI Driver is performing a Job */
} Twi_StatusType;


/*! 
 * \ingroup Twi
 * \defgroup Twi_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (TWI_DEV_ERROR_DETECT == STD_ON)
#define	TWI_E_PARAM_POINTER				0x11 /*!< API function called with a NULL pointer */
#define	TWI_E_PARAM_DATA				0x12 /*!< API function called with wrong parameter value */
#define TWI_E_UNINIT					0x20 /*!< API function called before the Twi module has been full initialized or after the CaS module has been shut down */
#endif
/** @} */ // end of CaS_DevelopmentErrors

/*! 
 * \ingroup Twi
 * \defgroup Twi_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define TWI_ASYNCRECEIVE_ID					0x01
#define TWI_ASYNCSEND_ID					0x02
#define TWI_GETHWUNITSTATUS_ID				0x03
#define TWI_RESET_ID						0x04
#define TWI_INIT_ID							0x05
#define TWI_PROC_ISR_ID						0x06
/** @} */ // end of Twi_Apis

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/

Twi_StatusType Twi_GetHWUnitStatus(Twi_HWUnitType HWUnit);
Std_ReturnType Twi_AsyncReceive(uint32 DeviceAddress, uint8* Buffer, uint16 LenByte);
Std_ReturnType Twi_AsyncSend(uint32 DeviceAddress, const uint8* Buffer, uint16 LenByte);
Std_ReturnType Twi_ReInit(void);
void Twi_Reset(void);

void Twi_Init(void);

#if (TWI_VERSION_INFO_API == STD_ON)
void Twi_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

#endif /*TWI_H*/
