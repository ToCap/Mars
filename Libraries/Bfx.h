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

#ifndef BFX_H
#define BFX_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/

/* Include standard headers */
#include "Std_Types.h"						/*standard type definition*/


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Bfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define	BFX_MODULE_ID					MODULE_ID_BFX

/*!
 * \ingroup Bfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define BFX_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Bfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define BFX_SW_MAJOR_VERSION 				1
#define BFX_SW_MINOR_VERSION 				0
#define BFX_SW_PATCH_VERSION				0

#define BFX_AR_RELEASE_MAJOR_VERSION		4
#define BFX_AR_RELEASE_MINOR_VERSION		2
#define BFX_AR_RELEASE_REVISION_VERSION		1



/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/

void Bfx_ClrBit_u8u8(P2VAR(uint8) Data, uint8 BitPn);
void Bfx_ClrBit_u16u8(P2VAR(uint16) Data, uint8 BitPn);
void Bfx_ClrBit_u32u8(P2VAR(uint32) Data, uint8 BitPn);

boolean Bfx_GetBit_u8u8(uint8 Data, uint8 BitPn);
boolean Bfx_GetBit_u16u8(uint16 Data, uint8 BitPn);
boolean Bfx_GetBit_u32u8(uint32 Data, uint8 BitPn);

void Bfx_SetBit_u32u8(P2VAR(uint32) Data, uint8 BitPn);
void Bfx_SetBit_u16u8(P2VAR(uint16) Data, uint8 BitPn);
void Bfx_SetBit_u8u8(P2VAR(uint8) Data, uint8 BitPn);

void Bfx_PutBit_u8u8u8(P2VAR(uint8) Data, uint8 BitPn, boolean Status);
void Bfx_PutBit_u16u8u8(P2VAR(uint16) Data, uint8 BitPn, boolean Status);
void Bfx_PutBit_u32u8u8(P2VAR(uint32) Data, uint8 BitPn, boolean Status);

void Bfx_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);


#endif /*BFX_H*/

