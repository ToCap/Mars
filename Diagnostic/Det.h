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

#ifndef DET_H
#define DET_H


/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
/* Include standard headers */
#include "Modules.h"
#include "Std_Types.h"

/* Include of configuration specific headers */
#include "Det_Cfg.h"


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Det 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00379
 */
#define	DET_MODULE_ID					MODULE_ID_DET

/*!
 * \ingroup Det 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00374
 */
#define DET_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Det 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00003, SRS_BSW_00318, SRS_BSW_00321
 */
#define DET_SW_MAJOR_VERSION 			1
#define DET_SW_MINOR_VERSION 			0
#define DET_SW_PATCH_VERSION			0

#define DET_AR_RELEASE_MAJOR_VERSION	4
#define DET_AR_RELEASE_MINOR_VERSION	2
#define DET_AR_RELEASE_REVISION_VERSION	1


/*! 
 * \ingroup Det
 * \defgroup Det_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (DET_DEV_ERROR_DETECT == STD_ON)
#define	DET_E_PARAM_POINTER				0x01 /*!< API called with a NULL  pointer */
#endif
/** @} */ // end of Det_DevelopmentErrors

/*! 
 * \ingroup Det
 * \defgroup Det_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define DET_GETVERSIONINFO_ID			0x03
/** @} */ // end of Det_Apis

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
#if (DET_VERSION_INFO_API == STD_ON)
void Det_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif

Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId);

void Det_Init();
void Det_Start();

#endif /*DET_H*/
