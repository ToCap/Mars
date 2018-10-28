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

#ifndef DLT_PRV_H
#define DLT_PRV_H

/**
 * \defgroup Dlt
*/

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/
/*! \struct Dlt_StandardHeaderType
 *  \brief ???
 *
 * \par Autosar standard
 * 
 */
TYPEDEF struct Dlt_Prv_DemPayload
{
	uint32 EventId;
	uint32 DTCOfEvent;
	//TODO : Add defintion of EventExtendedDataRecord type
	//TODO : Add defintion of EventFreezeFrameData type

};

/*! \struct Dlt_StandardHeaderType
 *  \brief ???
 *
 * \par Autosar standard
 * 
 */
TYPEDEF struct Dlt_Prv_DetPayload
{
	uint16 xModuleId;
	uint8 xInstanceId;
	uint8 xApiId;
	uint8 xErrorId;

};

/*! \struct Dlt_StandardHeaderType
 *  \brief ???
 *
 * \par Autosar standard
 * 
 */
TYPEDEF struct Dlt_Prv_StandardHeaderType
{
	uint8	HTYP;
	uint8	MCNT;
	uint16	LEN;
	uint32	ECU;
	uint32	SEID;
	uint32	TMSP;

};



TYPEDEF struct Dlt_Prv_ExtendedHeaderType
{
	uint8	MSIN;
	uint8	NOAR;
	uint32	APIID;
	uint32	CTID;

} ;

TYPEDEF struct Dlt_Prv_ExtendedHeaderMessageInfoType
{
	uint8	VERB : 1;
	uint8	MSTP : 3;
	uint8	MTIN : 4;

} ;


TYPEDEF struct Dlt_Prv_StandardHeaderStatusType
{
	uint8	UEH : 1;
	uint8	MSBF : 1;
	uint8	WEID : 1;
	uint8	WSID : 1;
	uint8	WTMS : 1;
	uint8	VERS : 3;

} ;

#endif /*DLT_PRV_H*/
