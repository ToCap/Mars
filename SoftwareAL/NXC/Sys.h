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
#ifndef SYS_H
#define SYS_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Std_Types.h"						/*standard type definition*/

#include "Sys_Cfg.h"
#include "Sys_BasicCallout.h"

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/

/*!
 * \ingroup BatM 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define	SYS_MODULE_ID					MODULE_ID_CPLX

/*!
 * \ingroup BatM 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define SYS_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup BatM 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define SYS_SW_MAJOR_VERSION 					1
#define SYS_SW_MINOR_VERSION 					0
#define SYS_SW_PATCH_VERSION					0

#define SYS_AR_RELEASE_MAJOR_VERSION			4
#define SYS_AR_RELEASE_MINOR_VERSION			2
#define SYS_AR_RELEASE_REVISION_VERSION			1

/*! 
 * \ingroup BatM
 * \defgroup BatM_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#define SYS_E_PARAM_POINTER				0x10
#define SYS_E_INIT_FAILED					0x11
#define	SYS_E_PARAM						0x0A
#define SYS_E_NOT_INITIALIZED				0x0B

 /** @} */ // end of SYS_DevelopmentErrors

/*! 
 * \ingroup BatM
 * \defgroup BatM_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define SYS_INIT_ID						0x01
#define SYS_MAINFUNCTION_ID				0x02
 /** @} */ // end of SYS_Apis
/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/
/*!
 * \ingroup Dlt 
 * \struct Dlt_SessionIDType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00225
 * Limitation : Dlt_SessionIDType is typed as unsigned 8bit integer
 */
typedef mutex Sys_MutexType;

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
#if (SYS_VERSION_INFO_API == STD_ON)
void Sys_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif

#endif /*SYS_H*/
