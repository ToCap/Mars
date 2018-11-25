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

#ifndef IOLIB_H
#define IOLIB_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "IoLib_Cfg.h"
#include "IoLib_Types.h"					/**/


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup IoHwAb 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00379
 */
#define	IOLIB_MODULE_ID					MODULE_ID_IOHWAB

/*!
 * \ingroup IoHwAb 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00374
 */
#define IOLIB_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup IoHwAb 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00003, SRS_BSW_00318, SRS_BSW_00321
 */
#define IOLIB_SW_MAJOR_VERSION 					1
#define IOLIB_SW_MINOR_VERSION 					0
#define IOLIB_SW_PATCH_VERSION					0

#define IOLIB_AR_RELEASE_MAJOR_VERSION			4
#define IOLIB_AR_RELEASE_MINOR_VERSION			2
#define IOLIB_AR_RELEASE_REVISION_VERSION		1


/*! 
 * \ingroup IoLib
 * \defgroup IoLib_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (IOLIB_DEV_ERROR_DETECT == STD_ON)
#define	IOLIB_E_UNINIT						0x01
#define IOLIB_E_PARAM_DATA					0x12
#endif
/** @} */ // end of IOLIB_DevelopmentErrors

/*! 
 * \ingroup IoLib
 * \defgroup IoLib_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define IOLIB_GETSENSORMODE_ID				0x01
#define IOLIB_GETSENSORTYPE_ID				0x02
#define IOLIB_SETSENSORMODE_ID				0x03
#define IOLIB_SETSENSORTYPE_ID				0x04
#define IOLIB_DECLARESENSOR_ID				0x05
#define IOLIB_SETSENSORMONITORING_ID		0x06
#define IOLIB_DECLAREACTUATOR_ID			0x07

/** @} */ // end of IOLIB_Apis

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
#if (IOLIB_VERSION_INFO_API == STD_ON)
void IoLib_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif
Std_ReturnType IoLib_GetSensorMode(IoLib_PortSensorType Port, P2VAR(IoLib_SensorMode) Mode);
Std_ReturnType IoLib_GetSensorType(IoLib_PortSensorType Port, P2VAR(IoLib_SensorType) Type);
Std_ReturnType IoLib_SetSensorMode(IoLib_PortSensorType Port, IoLib_SensorMode Mode);
Std_ReturnType IoLib_SetSensorType(IoLib_PortSensorType Port, IoLib_SensorType Type);

Std_ReturnType IoLib_DeclareActuator(IoLib_PortActuatorType Port, string Name);
Std_ReturnType IoLib_DeclareSensor(IoLib_PortSensorType Port, string Name, IoLib_SensorType Type, IoLib_SensorMode Mode);

#endif /*IOLIB_H*/
