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

#ifndef DLT_H
#define DLT_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Std_Types.h"

#include "Det.h"
#include "Dem.h"

#include "Dlt_Cfg.h"


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Dlt 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00379
 */
#define	DLT_MODULE_ID					MODULE_ID_DLT

/*!
 * \ingroup Dlt 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00374
 */
#define DLT_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Dlt 
 *  This is the first group
 * \par Autosar standard
 * SRS_BSW_00003, SRS_BSW_00318, SRS_BSW_00321
 */
#define DLT_SW_MAJOR_VERSION 				1
#define DLT_SW_MINOR_VERSION 				0
#define DLT_SW_PATCH_VERSION				0

#define DLT_AR_RELEASE_MAJOR_VERSION		4
#define DLT_AR_RELEASE_MINOR_VERSION		2
#define DLT_AR_RELEASE_REVISION_VERSION		1


/*! 
 * \ingroup Dlt
 * \defgroup Dlt_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define DLT_INIT_ID							0x01
#define DLT_GETVERSIONINFO_ID				0x02
#define DLT_SENDLOGMESSAGE_ID				0x03
#define DLT_SENDTRACEMESSAGE_ID				0x04
#define DLT_DETFORWARDERRORTRACE_ID			0x07
#define DLT_DEMTRIGGERONEVENTSTATUS_ID		0x15
/** @} */ // end of Dlt_Apis


/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/

/*!
 * \ingroup Dlt 
 * \enum Dlt_MessageTypeType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00224
 */
TYPEDEF enum Dlt_MessageTypeType
{
	DLT_TYPE_LOG = 0x01,
	DLT_TYPE_APP_TRACE = 0x02,
	DLT_TYPE_NW_TRACE = 0x03,
	DLT_TYPE_CONTROL = 0x04,

} ;


/*!
 * \ingroup Dlt 
 * \struct Dlt_SessionIDType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00225
 * Limitation : Dlt_SessionIDType is typed as unsigned 8bit integer
 */
typedef uint8 Dlt_SessionIDType;


/*!
 * \ingroup Dlt 
 * \struct Dlt_ApplicationIDType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00226
 * Limitation : Dlt_ApplicationIDType is typed as unsigned 8bit integer
 */
typedef uint8 Dlt_ApplicationIDType;


/*!
 * \ingroup Dlt 
 * \struct Dlt_ContextIDType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00227
 * Limitation : Dlt_ContextIDType is typed as unsigned 8bit integer
 */
typedef uint8 Dlt_ContextIDType;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageIDType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00228
 * Limitation : Dlt_MessageIDType is typed as unsigned 8bit integer
 */
typedef uint8 Dlt_MessageIDType;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageArgumentCount
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00235
 */
typedef uint16 Dlt_MessageArgumentCount;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageOptionsType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00229
 */
TYPEDEF struct Dlt_MessageOptionsType
{
	uint8	message_type : 3;
	uint8	verbose_mode : 1;
	uint8	reserved : 4;

} ;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageLogLevelType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00230
 */
TYPEDEF enum Dlt_MessageLogLevelType
{
	DLT_LOG_OFF = 0x00, /*!<Turn off logging */
	DLT_LOG_FATAL = 0x01, /*!<Fatal system error */
	DLT_LOG_ERROR = 0x02, /*!<Errors occurring in a SW-C with impact to correct functionality */
	DLT_LOG_WARN = 0x03, /*!<Log messages where a incorrect behavior can not be ensured */
	DLT_LOG_INFO = 0x04, /*!<Log messages providing information for better understanding of the internal behavior of a software */
	DLT_LOG_DEBUG = 0x05, /*!<Log messages, which are usable only for debugging of a software */
	DLT_LOG_VERBOSE = 0x06, /*!<Log messages with the highest communicative level, here all possible states, information and everything else can be logged */
} ;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageTraceType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00231
 */
TYPEDEF enum Dlt_MessageTraceType
{
	DLT_TRACE_VARIABLE = 0x01, /*!<For tracing the value of a variable*/
	DLT_TRACE_FUNCTION_IN = 0x02, /*!<For tracing the calling of a function*/
	DLT_TRACE_FUNCTION_OUT = 0x03, /*!<For tracing the returning of a function*/
	DLT_TRACE_STATE = 0x04, /*!<For tracing a state of a state machine*/
	DLT_TRACE_VFB = 0x05, /*!<For tracing RTE Events*/
} ;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageLogInfoType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00236
 */
TYPEDEF struct Dlt_MessageLogInfoType
{
	Dlt_MessageArgumentCount	arg_count;
	Dlt_MessageLogLevelType		log_level;
	Dlt_MessageOptionsType		options;
	Dlt_ContextIDType			context_id;
	Dlt_ApplicationIDType		app_id;
} ;

/*!
 * \ingroup Dlt 
 * \struct Dlt_MessageTraceInfoType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dlt_00237
 */
TYPEDEF struct Dlt_MessageTraceInfoType
{
	Dlt_MessageTraceType		trace_info;
	Dlt_MessageOptionsType		options;
	Dlt_ContextIDType			context_id;
	Dlt_ApplicationIDType		app_id;
	
} Dlt_MessageTraceInfoType;

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/

#if (DLT_VERSION_INFO_API == STD_ON)
void Dlt_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif

void Dlt_DemTriggerOnEventStatus(Dem_EventIdType EventId, Dem_UdsStatusByteType EventStatusByteOld, Dem_UdsStatusByteType EventStatusByteNew);
void Dlt_DetForwardErrorTrace(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType session_id, const Dlt_MessageLogInfoType* log_info, const uint8* log_data, uint16 log_data_length);
Std_ReturnType Dlt_SendTraceMessage(Dlt_SessionIDType session_id, const Dlt_MessageTraceInfoType* trace_info, const uint8* trace_data, uint16 trace_data_length);

void Dlt_Init(void);

#endif /*DLT_H*/
