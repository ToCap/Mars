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

#ifndef DEM_H
#define DEM_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Dem_Types.h"
#include "Dem_Cfg.h"						/*module self-configuration*/




/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/

/*!
 * \ingroup Dem 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00379
 */
#define	DEM_MODULE_ID					MODULE_ID_DEM

/*!
 * \ingroup Dem 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00374
 */
#define DEM_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Dem 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00003, SRS_BSW_00318, SRS_BSW_00321
 */
#define DEM_SW_MAJOR_VERSION 			1
#define DEM_SW_MINOR_VERSION 			0
#define DEM_SW_PATCH_VERSION			0

#define DEM_AR_RELEASE_MAJOR_VERSION	4
#define DEM_AR_RELEASE_MINOR_VERSION	2
#define DEM_AR_RELEASE_REVISION_VERSION	1


/*! 
 * \ingroup Dem
 * \defgroup Dem_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#define	DEM_E_WRONG_CONFIGURATION		0x10 /*!< API function called with a parameter value, which is not allowed by active configuration */
#define	DEM_E_PARAM_POINTER				0x11 /*!< API function called with a NULL pointer */
#define	DEM_E_PARAM_DATA				0x12 /*!< API function called with wrong parameter value */
#define	DEM_E_PARAM_LENGTH				0x13 /*!< API function called with wrong length parameter value */
#define	DEM_E_INIT_FAILED				0x14 /*!< Dem initialisation failed */
#define	DEM_E_UNINIT					0x20 /*!< API function called before the Dem module has been full initialized or after the Dem module has been shut down */
#define	DEM_E_NODATAAVAILABLE			0x30 /*!<  */
#define	DEM_E_WRONG_RECORDNUMBER		0x31 /*!<  */
#define	DEM_E_WRONG_DIDNUMBER			0x32 /*!<  */
#define	DEM_E_WRONG_CONDITION			0x40 /*!<  */
#endif
/** @} */ // end of Dem_DevelopmentErrors

/*! 
 * \ingroup Dem
 * \defgroup Dem_ExtendedReturnTypes
 *  This is the first group
 * \sa Std_ReturnType
 * \par Autosar standard
 * SWS_Std_00006 (SRS_BSW_00357)
 *  @{
 */
#define DEM_E_NO_DTC_AVAILABLE			0x02
#define DEM_E_NO_FDC_AVAILABLE			0x03
#define DEM_E_NODATAAVAILABLE			0x30
#define DEM_E_WRONG_RECORDNUMBER		0x31
#define DEM_E_WRONG_DIDNUMBER			0x32
/** @} */ // end of Std_ReturnTypes

/*! 
 * \ingroup Dem
 * \defgroup Dem_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define DEM_GETVERSIONINFO_ID				0x00
#define DEM_PREINIT_ID						0x01
#define DEM_INIT_ID							0x02 
#define DEM_SHUTDOWN_ID						0x03
#define DEM_SETEVENTSTATUS_ID				0x04 /*!< Service ID of Dem_SetEventStatus */
#define DEM_RESETEVENTSTATUS_ID				0x05
//#define Dem_PRESTOREFREEZEFRAME_ID		0x06
//#define Dem_CLEARPRESTOREDFREEZEFRAME_ID	0x07
#define DEM_SETOPERATIONCYCLESTATE_ID		0x08
#define DEM_RESETEVENTDEBOUNCESTATUS_ID		0x09 /*!< Service ID of Dem_ResetEventDebounceStatus */
#define	DEM_GETEVENTSTATUS_ID				0x0A /*!< Service ID of Dem_GetEventStatus */
#define DEM_GETEVENTFAILED_ID				0x0B
#define DEM_GETEVENTTESTED_ID				0x0C
#define DEM_GETDTCOFEVENT_ID				0x0D
#define DEM_REPORTERRORSTATUS_ID			0x0F
#define DEM_GETINDICATORSTATUS_ID			0x29
#define	DEM_GETCOMPONENTFAILED_ID			0x2A
#define DEM_GETEVENTFREEZEFRAMEDATA_ID		0x31
#define	DEM_GETEVENTMEMORYOVERFLOW_ID		0x32
#define DEM_GETNUMBEROFEVENTMEMORYENTRIES_ID 0x35
#define DEM_SETEVENTAVAILABLE_ID			0x37 /*!< Service ID of Dem_SetEventAvailable */
#define DEM_SETENABLECONDITION_ID			0x39
#define DEM_GETFAULTDETECTIONCOUNTER_ID		0x3e
#define DEM_SETEVENTDISABLED_ID				0x51
#define DEM_MAINFUNCTION_ID					0x55
#define DEM_GETEVENTFREEZEFRAMEDATAEX_ID	0x6E
#define DEM_SETWIRSTATUS_ID					0x7A
#define DEM_GETOPERATIONCYCLESTATE_ID		0x9E
#define DEM_GETDEBOUNCINGOFEVENT_ID			0x9F
#define DEM_SETINDICATORSTATUS_ID			0xA1
#define DEM_SETDTR_ID						0xA2
/** @} */ // end of Dem_Apis


/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
#if (DEM_VERSION_INFO_API == STD_ON)
void Dem_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif
void Dem_PreInit(void);
void Dem_Init(void);
void Dem_MainFunction(void);
void Dem_Shutdown(void);

boolean Dem_GetInitialisationStatus();
Std_ReturnType Dem_DeclareEvent(string name, uint8 component, uint8 stDebAlgorithm)

void Dem_ReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
Std_ReturnType Dem_ResetEventDebounceStatus(Dem_EventIdType EventId, Dem_DebounceResetStatusType DebounceResetStatus);
Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId);
Std_ReturnType Dem_PrestoreFreezeFrame(Dem_EventIdType EventId);
Std_ReturnType Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId);
Std_ReturnType Dem_GetComponentFailed(Dem_ComponentIdType ComponentId, P2VAR(boolean) ComponentFailed);
Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType) EventStatusByte);
Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean) EventFailed);
Std_ReturnType Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean) EventTested);
Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType) DebouncingState);
Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(char) FaultDetectionCounter);
Std_ReturnType Dem_GetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType) IndicatorStatus);
Std_ReturnType Dem_SetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType) IndicatorStatus);

#endif /*DEM_H*/
